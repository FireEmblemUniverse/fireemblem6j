.SUFFIXES:
.SECONDARY:

# ==================
# = PROJECT CONFIG =
# ==================

BUILD_NAME := fe6

SRC_DIR = src
ASM_DIR = asm
BUILD_DIR = build

CLEAN_FILES :=
CLEAN_DIRS  :=

all: compare

# ====================
# = TOOL DEFINITIONS =
# ====================

ifeq ($(OS),Windows_NT)
  EXE := .exe
else
  EXE :=
  UNAME_S := $(shell uname -s)
endif

PYTHON := python3
TOOLCHAIN ?= $(DEVKITARM)
AGBCC_HOME ?= tools/agbcc

ifneq (,$(TOOLCHAIN))
  export PATH := $(TOOLCHAIN)/bin:$(PATH)
endif

PREFIX := arm-none-eabi-

ifeq ($(UNAME_S),Darwin)
  ifneq (,$(TOOLCHAIN))
    PREFIX := $(TOOLCHAIN)/bin/$(PREFIX)
  endif
  SHASUM ?= shasum
endif

export OBJCOPY := $(PREFIX)objcopy
export AS := $(PREFIX)as
export CPP := $(PREFIX)cpp
export LD := $(PREFIX)ld
export STRIP := $(PREFIX)strip

CC1     := $(AGBCC_HOME)/bin/old_agbcc$(EXE)
CC1_NEW := $(AGBCC_HOME)/bin/agbcc$(EXE)

SHASUM ?= sha1sum

# ================
# = BUILD CONFIG =
# ================

INC_DIRS := include asm/include $(AGBCC_HOME)/include .
INC_FLAG := $(foreach dir, $(INC_DIRS), -I $(dir))

CPPFLAGS := $(INC_FLAG) -nostdinc -undef
CFLAGS := -g -mthumb-interwork -Wimplicit -Wparentheses -Werror -fhex-asm -ffix-debug-line
CFLAG_OPT := -O2
ASFLAGS := -mcpu=arm7tdmi $(INC_FLAG)

LDS := $(BUILD_NAME).lds
C_SRCS := $(shell find $(SRC_DIR) -name "*.c")
ASM_SRCS := $(shell find $(SRC_DIR) -name "*.s") $(shell find $(ASM_DIR) -name "*.s")
DATA_SRCS := $(shell find data/ -name "*.s")

C_GENERATED :=

# =========
# = Texts =
# =========
TEXT_DIR := texts
TEXT_TOOLS := tools/texttools

TEXT_DECODER := $(PYTHON)  $(TEXT_TOOLS)/textdecoder.py
TEXT_DPARSER := $(PYTHON) $(TEXT_TOOLS)/textdeparser.py
TEXT_PROCESS := $(PYTHON) $(TEXT_TOOLS)/textprocess.py
TEXT_ENCODE := tools/textencode/textencode

TEXT_MAIN := $(TEXT_DIR)/texts.txt
TEXT_DEFS := $(TEXT_DIR)/textdefs.txt
TEXT_SRC  := $(TEXT_MAIN) $(shell find $(TEXT_DIR) -type f -name "*.txt")

TEXT_HEADER := include/constants/msg.h
MSG_LIST    := src/msg_data.c

# this should just be used for testing
$(TEXT_MAIN):
	@echo "[GEN]	$@"
	@$(TEXT_DECODER) > $@

$(MSG_LIST) $(TEXT_HEADER): $(TEXT_SRC) $(TEXT_DEFS)
	@echo "[GEN]	$@"
	@$(TEXT_PROCESS) $(TEXT_MAIN) $(TEXT_DEFS) $(MSG_LIST) $(TEXT_HEADER) cp932

C_GENERATED += $(MSG_LIST)
CLEAN_FILES += $(MSG_LIST) # $(TEXT_HEADER)

# ============
# = Spritans =
# ============

PNG_FILES := $(shell find ./data -type f -name '*.png')
TSA_FILES := $(shell find ./data -type f -name '*.tsa')
GBAGFX := tools/gbagfx/gbagfx$(EXE)

%.1bpp: %.png
	@echo "[GEN]	$@"
	@ $(GBAGFX) $< $@

%.4bpp: %.png
	@echo "[GEN]	$@"
	@ $(GBAGFX) $< $@

%.8bpp: %.png
	@echo "[GEN]	$@"
	@ $(GBAGFX) $< $@

%.gbapal: %.pal
	@echo "[GEN]	$@"
	@ $(GBAGFX) $< $@

%.gbapal: %.png
	@echo "[GEN]	$@"
	@$(GBAGFX) $< $@

%.lz: %
	@echo "[LZ ]	$@"
	@$(GBAGFX) $< $@

%.rl: %
	@echo "[LZ ]	$@"
	@$(GBAGFX) $< $@

CLEAN_FILES += $(PNG_FILES:%.png=%.4bpp) $(PNG_FILES:%.png=%.4bpp.lz) $(PNG_FILES:%.png=%.4bpp.lz.o)
CLEAN_FILES += $(PNG_FILES:%.png=%.gbapal) $(PNG_FILES:%.png=%.gbapal.lz)
CLEAN_FILES += $(TSA_FILES:%.tsa=%.tsa.lz)

# ==============
# = Banim data =
# ==============

ALL_BANIM_SCRS := $(shell find ./data/banims/ -type f -name "*.s")
ALL_BANIM_PALS := $(shell find ./data/banims/ -type f -name "*.agbpal")

BANIM_TOOLS := tools/banimtools
LZSS_COMPRESS  := $(PYTHON) $(BANIM_TOOLS)/lzss_compress.py
PNG_TO_GBA4BPP := $(PYTHON) $(BANIM_TOOLS)/png_to_4bpp.py
PNG_TO_GBA4BPP := $(PYTHON) $(BANIM_TOOLS)/png_to_4bpp.py
FK_COMPRESSOR  := $(PYTHON) $(BANIM_TOOLS)/compressor.py
STRIPER        := $(BANIM_TOOLS)/strip.sh

BANIM_OBJECT := src/banimdata.o

$(BUILD_DIR)/$(BANIM_OBJECT): linker_script_banim.txt $(shell ./tools/banimtools/banim_compressing_linker.py -t linker_script_banim.txt -m)
	@./tools/banimtools/banim_compressing_linker.py -o $@ -t linker_script_banim.txt -b 0x086A1000 -l $(LD) --objcopy $(OBJCOPY) -c ./tools/banimtools/compressor.py

BANIM_LINK_SCR := ./linker_script_banim.txt

%.stripped: %
	@echo "[STP]	$@"
	@$(STRIPER) $< $@

%.oamr.elf: %.o
	@echo "[LD ]	$@"
	@$(LD) -T $(BANIM_TOOLS)/link_oamr.ld -o $@ $<

%.oaml.elf: %.o
	@echo "[LD ]	$@"
	@$(LD) -T $(BANIM_TOOLS)/link_oaml.ld -o $@ $<

%.mode.elf: %.o
	@echo "[LD ]	$@"
	@$(LD) -T $(BANIM_TOOLS)/link_mode.ld -o $@ $<

%.oamr.bin: %.oamr.elf
	@echo "[OPY]	$@"
	@$(OBJCOPY) --only-section=.data.oamr -O binary $< $@

%.oaml.bin: %.oaml.elf
	@echo "[OPY]	$@"
	@$(OBJCOPY) --only-section=.data.oaml -O binary $< $@

%.mode.bin: %.mode.elf
	@echo "[OPY]	$@"
	@$(OBJCOPY) --only-section=.data.modes -O binary $< $@

BANIM_GENERATED :=
BANIM_GENERATED += $(ALL_BANIM_SCRS:%.s=%.o) $(ALL_BANIM_SCRS:%.s=%.o.bin) $(ALL_BANIM_SCRS:%.s=%.o.bin.lz) $(ALL_BANIM_SCRS:%.s=%.o.bin.lz.o)
BANIM_GENERATED += $(ALL_BANIM_SCRS:%.s=%.oamr.elf) $(ALL_BANIM_SCRS:%.s=%.oamr.bin) $(ALL_BANIM_SCRS:%.s=%.oamr.bin.lz) $(ALL_BANIM_SCRS:%.s=%.oamr.bin.lz.o)
BANIM_GENERATED += $(ALL_BANIM_SCRS:%.s=%.script.bin) $(ALL_BANIM_SCRS:%.s=%.script.bin.lz) $(ALL_BANIM_SCRS:%.s=%.script.bin.lz.o)
BANIM_GENERATED += $(ALL_BANIM_SCRS:%.s=%.oaml.elf) $(ALL_BANIM_SCRS:%.s=%.oaml.bin) $(ALL_BANIM_SCRS:%.s=%.oaml.bin.lz) $(ALL_BANIM_SCRS:%.s=%.oaml.bin.lz.o)
BANIM_GENERATED += $(ALL_BANIM_SCRS:%.s=%.mode.elf) $(ALL_BANIM_SCRS:%.s=%.mode.bin) $(ALL_BANIM_SCRS:%.s=%.mode.bin.o)
BANIM_GENERATED += $(ALL_BANIM_PALS:%=%.lz) $(ALL_BANIM_PALS:%=%.lz.o)
BANIM_GENERATED += $(ALL_BANIM_PALS:%=%.lz.stripped) $(ALL_BANIM_PALS:%=%.lz.stripped.o)

# CLEAN_FILES += $(BANIM_GENERATED)

banim: $(BUILD_DIR)/$(BANIM_OBJECT)

clean_banim:
	rm -rf $(BUILD_DIR)/$(BANIM_OBJECT) $(BANIM_GENERATED)

# ===========
# = Targets =
# ===========

ROM := $(BUILD_NAME).gba
ELF := $(ROM:%.gba=%.elf)
MAP := $(ROM:%.gba=%.map)

ifeq (,$(findstring $(C_GENERATED),$(C_SRCS)))
C_SRCS += $(C_GENERATED)
endif

C_OBJS := $(C_SRCS:%.c=$(BUILD_DIR)/%.o)
ASM_OBJS := $(ASM_SRCS:%.s=$(BUILD_DIR)/%.o)
DATA_OBJS := $(DATA_SRCS:%.s=$(BUILD_DIR)/%.o)

ALL_OBJS := $(C_OBJS) $(ASM_OBJS) $(DATA_OBJS) $(BUILD_DIR)/$(BANIM_OBJECT)
ALL_DEPS := $(ALL_OBJS:%.o=%.d)

SUBDIRS := $(sort $(dir $(ALL_OBJS)))
$(shell mkdir -p $(SUBDIRS))

# ===========
# = RECIPES =
# ===========

compare: $(ROM)
	$(SHASUM) -c fe6.sha1

.PHONY: compare

%.gba: %.elf
	@echo "[OPY]	$@"
	$(OBJCOPY) --strip-debug -O binary $< $@

$(ELF): $(ALL_OBJS) $(LDS)
	@echo "[LD ]	$@"
	@cd $(BUILD_DIR) && $(LD) -T ../$(LDS) -Map ../$(MAP) -R $(BANIM_OBJECT).sym.o -L../tools/agbcc/lib $(ALL_OBJS:$(BUILD_DIR)/%=%) -lc -lgcc -o ../$@

CLEAN_FILES += $(ROM) $(ELF) $(MAP)

# ============
# = Wizardry =
# ============
ASM_DEP := $(PYTHON)  tools/asmtools/asmdep.py

$(BUILD_DIR)/%.d: %.c
	@$(CPP) $(CPPFLAGS) $< -o $@ -MM -MG -MT $@ -MT $(BUILD_DIR)/$*.o

$(BUILD_DIR)/%.d: %.s
	@echo "$(BUILD_DIR)/$*.o: \\" > $@
	@$(ASM_DEP) $(INC_FLAG) $< >> $@

$(BUILD_DIR)/%.o: %.c $(BUILD_DIR)/%.d
	@echo "[CC ]	$<"
	@$(CPP) $(CPPFLAGS) $< | iconv -f UTF-8 -t CP932 | $(CC1) $(CFLAGS) $(CFLAG_OPT) -o $(BUILD_DIR)/$*.s
	@echo ".text\n\t.align\t2, 0\n" >> $(BUILD_DIR)/$*.s
	@$(AS) $(ASFLAGS) $(BUILD_DIR)/$*.s -o $@
	@$(STRIP) -N .gcc2_compiled. $@

$(BUILD_DIR)/%.d: $(BUILD_DIR)/%.o
	@touch $@

$(BUILD_DIR)/%.o: %.s
	@echo "[AS ]	$<"
	@$(AS) $(ASFLAGS) $< -o $@ --MD $(BUILD_DIR)/$*.d

%.o: %.s
	@echo "[AS ]	$<"
	@mkdir -p $(dir $(BUILD_DIR)/$*.d)
	@$(AS) $(ASFLAGS) $< -o $@ --MD $(BUILD_DIR)/$*.d

ifneq (clean,$(MAKECMDGOALS))
  -include $(ALL_DEPS)
  .PRECIOUS: $(BUILD_DIR)/%.d
endif

CLEAN_DIRS += $(BUILD_DIR)

# ==============
# = Make clean =
# ==============
CLEAN_DIRS += $(shell find . -type d -name "__pycache__")

clean:
	@rm -f $(CLEAN_FILES)
	@rm -f $(BANIM_GENERATED)
	@rm -rf $(CLEAN_DIRS)
	@echo "all cleaned..."

.PHONY: clean

# ======================
# = CFLAGS overrides =
# ======================

%/main.o:           CFLAGS += -mtpcs-frame

%/irq.o:            CFLAG_OPT := -O0
%/random.o:         CFLAG_OPT := -O0
%/hardware.o:       CFLAG_OPT := -O0
%/move.o:           CFLAG_OPT := -O0
%/oam.o:            CFLAG_OPT := -O0
%/sound.o:          CFLAG_OPT := -O0
%/ramfunc.o:        CFLAG_OPT := -O0
%/proc.o:           CFLAG_OPT := -O0
%/icon.o:           CFLAG_OPT := -O0
%/debugtext.o:      CFLAG_OPT := -O0
%/text.o:           CFLAG_OPT := -O0
%/banim_sprite.o:   CFLAG_OPT := -O0
%/sprite.o:         CFLAG_OPT := -O0
%/face.o:           CFLAG_OPT := -O0
%/talk.o:           CFLAG_OPT := -O0
%/event.o:          CFLAG_OPT := -O0
%/spriteanim.o:     CFLAG_OPT := -O0
%/gamecontroller.o: CFLAG_OPT := -O0
%/msg.o:            CFLAG_OPT := -O0

%/mu.o:             CFLAG_OPT := -O0
%/manim.o:          CFLAG_OPT := -O0
%/scanline.o:          CFLAG_OPT := -O0

%/gbasram.o:        CFLAG_OPT := -O1
%/shop.o:           CFLAG_OPT := -O0
%/arena_ui.o:       CFLAG_OPT := -O0
%/suspend_ui.o:     CFLAG_OPT := -O0
%/banim_ekrsetup.o: CFLAG_OPT := -O1
