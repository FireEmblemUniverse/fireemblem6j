OUTPUT_ARCH(arm)

MEMORY
{
    rom   : ORIGIN = 0x08000000, LENGTH = 32M
    iwram : ORIGIN = 0x03000000, LENGTH = 32K
    ewram : ORIGIN = 0x02000000, LENGTH = 256K
}

__text_start            =       ORIGIN(rom);
__ewram_start           =       ORIGIN(ewram);
__iwram_start           =       ORIGIN(iwram);
__iwram_top             =       ORIGIN(iwram) + LENGTH(iwram);;
__sp_irq                =       __iwram_top - 0x060;
__sp_usr                =       __sp_irq - 0x1A0;
__irq_flags             =       0x03007ff8;

gNumMusicPlayers = 9;
gMaxLines = 0;

SECTIONS
{
    __ewram_overlay_beg = 0x02000000;
    __ewram_overlay_end = __ewram_overlay_beg;

    /* I wonder if there's not two distinct overlays here */
    /* or one with one instance split in two? */

    . = __ewram_overlay_beg;
    ewram_overlay_0 (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4); src/minimap.o(ewram_overlay_0);
        . = ALIGN(0x1000); src/map.o(ewram_overlay_0);
        . = ALIGN(4); src/bmfx.o(ewram_overlay_0);
        . = ALIGN(4); src/mapmenu.o(ewram_overlay_0);
        . = ALIGN(4); src/trademenu.o(ewram_overlay_0);
        . = ALIGN(4); src/bmio.o(ewram_overlay_0);
        . = . + 0x100;
        . = ALIGN(4); src/battlepreview.o(ewram_overlay_0);
        . = ALIGN(4); src/statscreen.o(ewram_overlay_0);
        . = ALIGN(4); src/statusscreen.o(ewram_overlay_0);
        . = ALIGN(4); src/mu.o(ewram_overlay_0);
        . = ALIGN(4); src/unitlistscreen.o(ewram_overlay_0);
        . = ALIGN(4); src/prepmenu.o(ewram_overlay_0);
        . = ALIGN(4); src/prep_sallycir.o(ewram_overlay_0);
        . = ALIGN(4); src/secretscreen.o(ewram_overlay_0);
        . = ALIGN(4); src/augury.o(ewram_overlay_0);
    }
    __ewram_overlay_end = MAX(., __ewram_overlay_end);

    . = __ewram_overlay_beg;
    ewram_overlay_savemenu (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4); src/savemenu.o(ewram_overlay_savemenu);
        . = ALIGN(4); src/savemenu_2.o(ewram_overlay_savemenu);
        . = ALIGN(4); src/soundroom.o(ewram_overlay_savemenu);
    }
    __ewram_overlay_end = MAX(., __ewram_overlay_end);

    . = __ewram_overlay_beg;
    ewram_overlay_sio (NOLOAD) : ALIGN(4)
    {
        . = 0x000000; gUnk_Sio_02000000 = .;
        . = 0x001000; gFont_Unk_Sio_02001000 = .;
        . = 0x001018; gText_Unk_Sio_02001018 = .;
        /* gap? */
        . = 0x0012A0; gUnk_Sio_020012A0 = .;
        /* gap? */
        . = 0x001520; gUnk_Sio_02001520 = .;
        . = 0x001524; gUnk_Sio_02001524 = .;
        . = 0x001528; gUnk_Sio_02001528 = .;
        . = 0x00152C; gSioImgBuf = .;
    }
    __ewram_overlay_end = MAX(., __ewram_overlay_end);

    . = __ewram_overlay_beg;
    ewram_overlay_opanim (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4); src/opanim.o(ewram_overlay_opanim);
    }
    __ewram_overlay_end = MAX(., __ewram_overlay_end);

    . = __ewram_overlay_beg;
    ewram_overlay_opinfo (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4); src/opinfo.o(ewram_overlay_opinfo);
        . = ALIGN(4); src/opinfo_classdemo.o(ewram_overlay_opinfo);
    }
    __ewram_overlay_end = MAX(., __ewram_overlay_end);

    . = __ewram_overlay_beg;
    ewram_overlay_banim (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4); src/banim_ekrbattle.o(ewram_overlay_banim);
        . = ALIGN(4); src/banim_ekrgauge.o(ewram_overlay_banim);
        . = ALIGN(4); src/banim_ekrdispup.o(ewram_overlay_banim);
        . = ALIGN(32); src/banim_ekrmain.o(ewram_overlay_banim);
        . = ALIGN(4); src/banim_ekrarena.o(ewram_overlay_banim);
        . = ALIGN(4); Banim_unused_0201E148 = .; . = . + 4;
        . = ALIGN(4); src/banim_efxmagic.o(ewram_overlay_banim);
        . = ALIGN(4); src/banim_dragon.o(ewram_overlay_banim);
        . = ALIGN(4); src/banim_dragonfx_idunn.o(ewram_overlay_banim);
        . = ALIGN(4); src/banim_efxsound.o(ewram_overlay_banim);
        . = ALIGN(4); src/banim_ekrclasschg.o(ewram_overlay_banim);
        . = ALIGN(4); src/banim_ekrlvup.o(ewram_overlay_banim);
        . = ALIGN(4); src/banim_ekrtriangle.o(ewram_overlay_banim);
        . = ALIGN(4); src/banim_ekrpopup.o(ewram_overlay_banim);
    }
    __ewram_overlay_end = MAX(., __ewram_overlay_end);

    . = __ewram_overlay_end;
    ewram_data (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4); src/hardware.o(ewram_data);
        . = ALIGN(4); src/move.o(ewram_data);
        . = ALIGN(4); src/sound.o(ewram_data);
        . = ALIGN(4); src/proc.o(ewram_data);
        . = ALIGN(4); src/icon.o(ewram_data);
        . = ALIGN(4); src/debugtext.o(ewram_data);
        . = ALIGN(4); src/text.o(ewram_data);
        . = ALIGN(4); src/banim_sprite.o(ewram_data);
        . = ALIGN(4); src/sprite.o(ewram_data);
        . = ALIGN(4); src/face.o(ewram_data);
        . = ALIGN(4); src/msg.o(ewram_data);
        . = ALIGN(4); src/util.o(ewram_data);
        . = ALIGN(4); src/bm.o(ewram_data);
        . = ALIGN(4); src/unit.o(ewram_data);
        . = ALIGN(4); src/map.o(ewram_data);
        . = ALIGN(4); src/mapwork.o(ewram_data);
        . = ALIGN(4); src/targetlist.o(ewram_data);
        . = ALIGN(4); src/unitsprite.o(ewram_data);
        . = ALIGN(4); src/battle.o(ewram_data);
        . = ALIGN(4); src/trap.o(ewram_data);
        . = ALIGN(4); src/supply.o(ewram_data);
        . = ALIGN(4); src/unitrearrange.o(ewram_data);
        . = ALIGN(4); src/arena.o(ewram_data);
        . = ALIGN(4); src/action.o(ewram_data);
        . = ALIGN(4); src/movepath.o(ewram_data);
        . = ALIGN(4); src/unitpanel.o(ewram_data);
        . = ALIGN(4); src/ai_phase.o(ewram_data);
        . = ALIGN(4); src/ai_decide.o(ewram_data);
        . = ALIGN(4); src/ai_080326C4.o(ewram_data);

        /* SIO */
        . = 0x0203B218 - __ewram_overlay_end; gSioOutgoing = .;
        . = 0x0203B618 - __ewram_overlay_end; gSioIncoming = .;
        . = 0x0203C618 - __ewram_overlay_end; gLinkArenaSt = .;
        . = 0x0203C67C - __ewram_overlay_end; gSioText_0203C67C = .;
        . = 0x0203C6A4 - __ewram_overlay_end; gSioText_0203C6A4 = .;
        . = 0x0203C704 - __ewram_overlay_end; gSioSaveConfig = .;
        . = 0x0203C708 - __ewram_overlay_end; gSioText_0203C708 = .;
        . = 0x0203C758 - __ewram_overlay_end; gSioFont_0203C758 = .;
        . = 0x0203C770 - __ewram_overlay_end; gLinkArenaTeamList = .;
        . = 0x0203C83C - __ewram_overlay_end; gSioResultRankings = .;
        . = 0x0203C900 - __ewram_overlay_end; gSioTexts = .;
        . = 0x0203C920 - __ewram_overlay_end; gKeyInputSequenceBuffer = .;
        . = 0x0203C940 - __ewram_overlay_end; gKeyInputSequenceTimer = .;
        . = 0x0203C980 - __ewram_overlay_end; gSioXmapOption = .;
        . = 0x0203C984 - __ewram_overlay_end; gSioBmSt = .;
        . = 0x0203C993 - __ewram_overlay_end; Sio_Unk_0203C993 = .;
        . = 0x0203C9D0 - __ewram_overlay_end; Unk_Sio_0203C9D0 = .;

        . = 0x0203C9D4 - __ewram_overlay_end;
        . = ALIGN(4); src/ui.o(ewram_data);
        . = ALIGN(4); src/mapselect.o(ewram_data);
        . = ALIGN(4); src/banim_ekrbattle.o(ewram_data);
        . = ALIGN(4); src/banim_ekrgauge.o(ewram_data);
        . = ALIGN(4); src/banim_setup.o(ewram_data);
        . = ALIGN(4); src/banim_ekrarena.o(ewram_data);
        . = ALIGN(4); src/banim_efxopmagic.o(ewram_data);
        . = ALIGN(4); src/banim_dragon.o(ewram_data);
        . = ALIGN(4); src/manim.o(ewram_data);
        . = ALIGN(4); gUnk_0203D354 = .; . = . + 4;
        . = ALIGN(4); gUnk_0203D358 = .; . = . + 4;
        . = ALIGN(1); gUnk_0203D35C = .; . = . + 1;
        . = ALIGN(1); gUnk_0203D35D = .; . = . + 1;
        . = ALIGN(4); gUnk_0203D360 = .; . = . + 1;
        . = ALIGN(1); gUnk_0203D361 = .; . = . + 1;
        . = ALIGN(1); gUnk_0203D362 = .; . = . + 1;
        . = ALIGN(2); gUnk_0203D364 = .; . = . + 2;
        . = ALIGN(4); gUnk_0203D368 = .; . = . + 4;
        . = ALIGN(4); gDemoMonologueId = .; . = . + 4;
        . = ALIGN(4); Texts_DemoMonologue = .; . = . + 0x30;
        . = ALIGN(4); Text_EndingTimeFlowMonologue = .; . = . + 0x38;
        . = ALIGN(1); gUnk_0203D3D8 = .; . = . + 1;
        . = ALIGN(1); gEndingId = .; . = . + 1; . = . + 2;
        . = ALIGN(4); src/statscreen.o(ewram_data);
        . = ALIGN(4); src/helpbox.o(ewram_data);
        . = ALIGN(4); src/chapter_title.o(ewram_data);
        . = ALIGN(4); src/helpbox_2.o(ewram_data);
        . = ALIGN(4); src/secretscreen.o(ewram_data);
        . = ALIGN(4); src/save_core.o(ewram_data);
        . = ALIGN(4); src/save_stats.o(ewram_data);
        . = ALIGN(4); src/save_game.o(ewram_data);
        . = ALIGN(4); src/save_multiarena.o(ewram_data);
        . = ALIGN(4); src/save_xmap.o(ewram_data);
        . = ALIGN(4); src/xmap.o(ewram_data);

        . = 0x0203DC70 - __ewram_overlay_end;
        . = ALIGN(4); src/ending_pinfo.o(ewram_data);

        . = 0x0203DCB8 - __ewram_overlay_end;
        . = ALIGN(4); src/shop.o(ewram_data);

        . = 0x02040000 - __ewram_overlay_end; /* end */
    }

    . = 0x03000000;
    IWRAM (NOLOAD) : ALIGN(4)
    {
        /* .bss */
        . = ALIGN(4); src/random.o(.bss);
        . = ALIGN(4); src/hardware.o(.bss);
        . = ALIGN(4); src/oam.o(.bss);
        . = ALIGN(4); src/talk.o(.bss);
        . = ALIGN(4); src/event.o(.bss);
        . = ALIGN(4); src/spriteanim.o(.bss);
        . = ALIGN(4); src/util.o(.bss);
        . = ALIGN(4); src/map.o(.bss);
        . = ALIGN(4); src/ai_script.o(.bss);
        . = ALIGN(4); src/ai_battle.o(.bss);

        . = 0x0013B8; sSioCnt = .;
        . = 0x0013BC; sSioId = .;
        . = 0x0013C0; gUnk_030013C0 = .;
        . = 0x0013C4; gUnk_030013C4 = .;
        . = 0x0013C8; gUnk_030013C8 = .;
        . = 0x0013CA; gUnk_030013CA = .;
        . = 0x0013D0; sReadCursor = .;
        . = 0x0013D8; sRecvCursor = .;
        . = 0x0013E0; gCurrentKeyInSeqIndex = .;
        . = 0x0013E4; gTargetKeyInSeqIndex = .;
        . = 0x0013E8; gUnk_030013E8 = .;
        . = 0x0013F0; gUnk_030013F0 = .;
        . = 0x001404; gUnk_03001404 = .;
        . = 0x001408; gUnk_03001408 = .;
        . = 0x00140C; gUnk_0300140C = .;
        . = 0x001410; gUnk_03001410 = .;
        . = 0x001418; gUnk_03001418 = .;
        . = 0x001428; gUnk_03001428 = .;
        . = 0x001438; gUnk_03001438 = .; . = . + 8;

        . = ALIGN(4); src/mu.o(.bss);
        . = ALIGN(4); src/shop.o(.bss);
        . = ALIGN(4); data/sounds/music_player_table.o(.bss);
        . = ALIGN(4); src/gbasram.o(.bss);
        . = ALIGN(4); *libgcc.a:dp-bit.o(.bss);
        . = ALIGN(4); *libgcc.a:fp-bit.o(.bss);
        . = ALIGN(4); src/iwram-data.o(iwram_data);

        /* stack: 0x03006648 ~ 0x03007E60 */

        . = 0x008000; /* end */
    }

    . = 0x08000000;
    ROM : ALIGN(4)
    {
        asm/crt0.o(.text);
        src/armfunc.o(.text);
        asm/arm.o(.text);

        src/main.o(.text);
        src/irq.o(.text);
        src/random.o(.text);
        src/hardware.o(.text);
        src/move.o(.text);
        src/oam.o(.text);
        src/sound.o(.text);
        src/ramfunc.o(.text);
        src/proc.o(.text);
        src/icon.o(.text);
        src/debugtext.o(.text);
        src/text.o(.text);
        src/banim_sprite.o(.text);
        src/sprite.o(.text);
        src/face.o(.text);
        src/talk.o(.text);
        src/event.o(.text);
        src/spriteanim.o(.text);
        src/gamecontroller.o(.text);
        src/msg.o(.text);
        src/util.o(.text);
        src/bm.o(.text);
        src/item.o(.text);
        src/unit.o(.text);
        src/map.o(.text);
        src/mapwork.o(.text);
        src/debugmenu.o(.text);
        src/playerphase.o(.text);
        src/bmfx.o(.text);
        src/mapmenu.o(.text);
        src/faction.o(.text);
        src/gold.o(.text);
        src/targetlist.o(.text);
        src/unitsprite.o(.text);
        src/support.o(.text);
        src/itemuse.o(.text);
        src/battle.o(.text);
        src/trademenu.o(.text);
        src/trap.o(.text);
        src/itemaction.o(.text);
        src/bmio.o(.text);
        src/chapter.o(.text);
        src/supply.o(.text);
        src/unitrearrange.o(.text);
        src/arena.o(.text);
        src/action.o(.text);
        src/movepath.o(.text);
        src/prepphase.o(.text);
        src/code_0802B814.o(.text);
        src/chapterinfo.o(.text);
        src/unitpanel.o(.text);
        src/subtitlehelp.o(.text);
        src/masseffect.o(.text);
        src/battlepreview.o(.text);
        src/ai_phase.o(.text);
        src/ai_order.o(.text);
        src/ai_decide.o(.text);
        src/ai_perform.o(.text);
        src/ai_utility.o(.text);
        src/ai_script.o(.text);
        src/ai_battle.o(.text);
        src/ai_080326C4.o(.text);
        asm/code-sio.o(.text);
        src/ui.o(.text);
        src/menu.o(.text);
        src/mapselect.o(.text);
        src/banim_ekrbattle.o(.text);
        src/banim_ekrlvupfan.o(.text);
        src/banim_ekrgauge.o(.text);
        src/banim_ekrdispup.o(.text);
        src/banim_ekrmisc.o(.text);
        src/banim_efxhpbar.o(.text);
        src/banim_efxdeath.o(.text);
        src/banim_efxfarattack.o(.text);
        src/banim_efxquake.o(.text);
        src/banim_efxflashing.o(.text);
        src/banim_ekrutils.o(.text);
        src/banim_ekrbattleintro.o(.text);
        src/banim_ekrbattleintrofx.o(.text);
        src/banim_setup.o(.text);
        src/banim_ekrcmd.o(.text);
        src/banim_main.o(.text);
        src/banim_ekrmain.o(.text);
        src/banim_ekrsetup.o(.text);
        src/banim_info.o(.text);
        src/banim_ekrmainmini.o(.text);
        src/banim_ekrterrainfx.o(.text);
        src/banim_ekrarena.o(.text);
        src/banim_efxmagic.o(.text);
        src/banim_efxhit.o(.text);
        src/banim_efxmisc.o(.text);
        src/banim_efxopmagic.o(.text);
        src/banim_dragon.o(.text);
        src/banim_dragonfx_manakete.o(.text);
        src/banim_dragonfx_fae.o(.text);
        src/banim_dragonfx_idunn.o(.text);
        src/banim_efxutils.o(.text);
        src/banim_efxsound.o(.text);
        src/banim_ekrclasschg.o(.text);
        src/banim_ekrlvup.o(.text);
        src/banim_ekrlvupfx.o(.text);
        src/banim_ekrtriangle.o(.text);
        src/banim_bg.o(.text);
        src/banim_ekrpopup.o(.text);
        src/spellassoc.o(.text);
        src/mu.o(.text);
        src/manim.o(.text);
        src/scanline.o(.text);
        src/eventinfo.o(.text);
        src/eventfunctions.o(.text);
        src/ending_monologue.o(.text);
        src/statscreen.o(.text);
        src/helpbox.o(.text);
        src/chapter_title.o(.text);
        src/helpbox_2.o(.text);
        src/mapui.o(.text);
        src/sioerror.o(.text);
        src/statusscreen.o(.text);
        src/unitlistscreen.o(.text);
        src/prepmenu.o(.text);
        src/prepscreen_disp.o(.text);
        src/prepmenuitem.o(.text);
        src/prepscreenfx.o(.text);
        src/prepscreenfx2.o(.text);
        src/prep_subitemscreen1.o(.text);
        src/prep_subitemscreen_viewall.o(.text);
        asm/prep_subitemscreen_viewall.o(.text);
        src/prep_subitemscreen3.o(.text);
        asm/prep_subitemscreen3.o(.text);
        src/prep_subitemscreen.o(.text);
        src/prep_subscreen_discard.o(.text);
        src/prep_menuscrollbar1.o(.text);
        asm/prep_menuscrollbar.o(.text);
        src/prep_menuscrollbar.o(.text);
        src/prep_080823A0.o(.text);
        asm/prep_bgscroll.o(.text);
        src/prep_bgscroll.o(.text);
        src/prep_sallycir.o(.text);
        src/prep_utils.o(.text);
        src/secretscreen_08082E74.o(.text);
        asm/secretscreen.o(.text);
        src/secretscreen.o(.text);
        src/save_core.o(.text);
        src/save_stats.o(.text);
        src/save_game.o(.text);
        src/save_multiarena.o(.text);
        src/save_xmap.o(.text);
        src/minimap.o(.text);
        src/savemenu.o(.text);
        src/savemenu_2.o(.text);
        src/xmap.o(.text);
        asm/xmap.o(.text); /* actually soundroom */
        src/soundroom.o(.text);
        asm/soundroom.o(.text);
        src/config.o(.text);
        src/augury.o(.text);
        src/playrank.o(.text);
        src/ending_credit.o(.text);
        asm/playrank_0808F33C.o(.text);
        src/ending_credit2.o(.text);
        src/ending_fin.o(.text);
        src/ending_cg.o(.text);
        src/ending_handler.o(.text);
        src/ending_pinfo.o(.text);
        src/worldmap.o(.text);
        src/worldmapfx.o(.text);
        src/monologue.o(.text);
        src/opinfo.o(.text);
        asm/opinfo.o(.text);
        src/opinfo_classdemo.o(.text);
        asm/opinfo_classdemo.o(.text);
        src/opinfo_classdemo2.o(.text);
        src/shop.o(.text);
        src/arena_ui.o(.text);
        src/suspend_ui.o(.text);
        src/opanim.o(.text);
        asm/opanim.o(.text);
        src/opanim6.o(.text);
        asm/opanim5.o(.text);
        src/titlescreen.o(.text);

        src/m4a_1.o(.text);
        src/m4a.o(.text);
        asm/gbasyscall.o(.text);
        src/gbasram.o(.text);
        *libgcc.a:_ashldi3.o(.text);
        *libgcc.a:_call_via_rX.o(.text);
        *libgcc.a:_divsi3.o(.text);
        *libgcc.a:_dvmd_tls.o(.text);
        *libgcc.a:_modsi3.o(.text);
        *libgcc.a:_udivsi3.o(.text);
        *libgcc.a:_umodsi3.o(.text);
        *libgcc.a:dp-bit.o(.text);
        *libgcc.a:fp-bit.o(.text);
        *libgcc.a:_lshrdi3.o(.text);
        *libgcc.a:_muldi3.o(.text);
        *libgcc.a:_negdi2.o(.text);
        *libc.a:memcpy.o(.text);
        *libc.a:memset.o(.text);
        *libc.a:strcpy.o(.text);

        asm/code_linker_stubs.o(.text);

        /* .rodata */
        . = ALIGN(4); src/msg_data.o(.rodata);
        . = ALIGN(4); src/main.o(.rodata);
        . = ALIGN(4); src/irq.o(.rodata);
        . = ALIGN(4); src/random.o(.rodata);
        . = ALIGN(4); src/hardware.o(.rodata);
        . = ALIGN(4); data/rodata_trig.o(.rodata);
        . = ALIGN(4); src/move.o(.rodata);
        . = ALIGN(4); src/oam.o(.rodata);
        . = ALIGN(4); src/sound.o(.rodata);
        . = ALIGN(4); src/ramfunc.o(.rodata);
        . = ALIGN(4); data/rodata_icon.o(.rodata);
        . = ALIGN(4); src/proc.o(.rodata);
        . = ALIGN(4); src/icon.o(.rodata);
        . = ALIGN(4); src/debugtext.o(.rodata);
        . = ALIGN(4); src/text.o(.rodata);
        . = ALIGN(4); src/banim_sprite.o(.rodata);
        . = ALIGN(4); src/sprite.o(.rodata);
        . = ALIGN(4); src/face.o(.rodata);
        . = ALIGN(4); src/talk.o(.rodata);
        . = ALIGN(4); src/event.o(.rodata);
        . = ALIGN(4); src/spriteanim.o(.rodata);
        . = ALIGN(4); src/gamecontroller.o(.rodata);
        . = ALIGN(4); src/msg.o(.rodata);
        . = ALIGN(4); src/util.o(.rodata);
        . = ALIGN(4); src/bmio_img.o(.rodata);
        . = ALIGN(4); src/item.o(.rodata);
        . = ALIGN(4); src/unit.o(.rodata);
        . = ALIGN(4); src/debugmenu.o(.rodata);
        . = ALIGN(4); src/bmfx.o(.rodata);
        . = ALIGN(4); src/unitsprite.o(.rodata);
        . = ALIGN(4); src/support.o(.rodata);
        . = ALIGN(4); src/battle.o(.rodata);
        . = ALIGN(4); src/trademenu.o(.rodata);
        . = ALIGN(4); src/menuinfo.o(.rodata);
        . = ALIGN(4); src/bmio.o(.rodata);
        . = ALIGN(4); src/chapter.o(.rodata);
        . = ALIGN(4); src/arena.o(.rodata);
        . = ALIGN(4); src/unitpanel.o(.rodata);
        . = ALIGN(4); src/battlepreview.o(.rodata);
        . = ALIGN(4); data/rodata_105DD0.o(.rodata);
        . = ALIGN(4); data/sio_rodata.o(.rodata);
        . = ALIGN(4); src/ai_order.o(.rodata);
        . = ALIGN(4); src/ai_perform.o(.rodata);
        . = ALIGN(4); src/ai_utility.o(.rodata);
        . = ALIGN(4); src/ai_script.o(.rodata);
        . = ALIGN(4); src/ai_data.o(.rodata);
        . = ALIGN(4); src/ai_battle.o(.rodata);
        . = ALIGN(4); src/ai_080326C4.o(.rodata);
        . = ALIGN(4); src/code_sio.o(.rodata);
        . = ALIGN(4); data/sio_data.o(.rodata);
        . = ALIGN(4); src/ui.o(.rodata);
        . = ALIGN(4); src/ui_img.o(.rodata);
        . = ALIGN(4); src/banim_efxquake_data.o(.rodata);
        . = ALIGN(4); src/banim_efxflashing.o(.rodata);
        . = ALIGN(4); src/banim_ekrbattleintro.o(.rodata);
        . = ALIGN(4); src/banim_ekrbattleintrofx.o(.rodata);
        . = ALIGN(4); src/banim_ekrcmd.o(.rodata);
        . = ALIGN(4); data/rodata_banim_08112122.o(.rodata);
        . = ALIGN(4); src/banim_ekrterrainfx.o(.rodata);
        . = ALIGN(4); src/banim_ekrarena.o(.rodata);
        . = ALIGN(4); data/rodata_banim_08112380.o(.rodata);
        . = ALIGN(4); src/banim_efxmagic.o(.rodata);
        . = ALIGN(4); src/banim_efxhit.o(.rodata);
        . = ALIGN(4); src/banim_efxmisc.o(.rodata);
        . = ALIGN(4); src/banim_efxopmagic.o(.rodata);
        . = ALIGN(4); data/rodata_banim_0811AE34.o(.rodata);
        . = ALIGN(4); src/banim_efxutils.o(.rodata);
        . = ALIGN(4); src/banim_ekrclasschg.o(.rodata);
        . = ALIGN(4); src/banim_ekrlvup.o(.rodata);
        . = ALIGN(4); src/banim_ekrtriangle.o(.rodata);
        . = ALIGN(4); src/banim_ekrtriangle_img.o(.rodata);
        . = ALIGN(4); src/banim_bg_img.o(.rodata);
        . = ALIGN(4); data/rodata_chapterinfo1.o(.rodata);
        . = ALIGN(4); src/unitsprite_img.o(.rodata);
        . = ALIGN(4); data/tilesetanim.o(.rodata);
        . = ALIGN(4); src/gamedata.o(.rodata);
        . = ALIGN(4); src/gamedatainfo.o(.rodata);
        . = ALIGN(4); src/ending_credit_info.o(.rodata);
        . = ALIGN(4); src/chapterinfo_data.o(.rodata);
        . = ALIGN(4); src/mu_info_data.o(.rodata);
        . = ALIGN(4); src/manim_img1.o(.rodata);
        . = ALIGN(4); src/worldmap_img.o(.rodata);
        . = ALIGN(4); src/arena_img.o(.rodata);
        . = ALIGN(4); src/manim_img2.o(.rodata);
        . = ALIGN(4); src/backgrounds_img.o(.rodata);
        . = ALIGN(4); src/mu.o(.rodata);
        . = ALIGN(4); src/manim.o(.rodata);
        . = ALIGN(4); src/scanline.o(.rodata);
        . = ALIGN(4); src/statscreen_img.o(.rodata);
        . = ALIGN(4); data/rodata_307544.o(.rodata);
        . = ALIGN(4); src/statscreen.o(.rodata);
        . = ALIGN(4); src/helpbox.o(.rodata);
        . = ALIGN(4); src/chapter_title.o(.rodata);
        . = ALIGN(4); src/helpbox_2.o(.rodata);
        . = ALIGN(4); src/statusscreen.o(.rodata);
        . = ALIGN(4); src/prep_img.o(.rodata);
        . = ALIGN(4); src/unitlistscreen.o(.rodata);
        . = ALIGN(4); src/prepmenu.o(.rodata);
        . = ALIGN(4); src/prepscreen_disp.o(.rodata);
        . = ALIGN(4); src/prepmenuitem.o(.rodata);
        . = ALIGN(4); src/prepscreenfx.o(.rodata);
        . = ALIGN(4); src/prep_subitemscreen.o(.rodata);
        . = ALIGN(4); src/prep_subscreen_discard.o(.rodata);
        . = ALIGN(4); src/save_core.o(.rodata);
        . = ALIGN(4); src/save_multiarena.o(.rodata);
        . = ALIGN(4); data/rodata_3273E4.o(.rodata);
        . = ALIGN(4); src/minimap.o(.rodata);
        . = ALIGN(4); data/rodata_3278AC.o(.rodata);
        . = ALIGN(4); src/ending_cg_img.o(.rodata);
        . = ALIGN(4); src/savemenu.o(.rodata);
        . = ALIGN(4); src/savemenu_2.o(.rodata);
        . = ALIGN(4); src/xmap.o(.rodata);
        . = ALIGN(4); data/xmap_rodata.o(.rodata); /* actually soundroom */
        . = ALIGN(4); data/rodata.o(.rodata);
        . = ALIGN(4); src/ending_pinfo.o(.rodata);
        . = ALIGN(4); src/monologue_img.o(.rodata);
        . = ALIGN(4); src/ending_monologue_img.o(.rodata);
        . = ALIGN(4); src/trig_high_accuracy.o(.rodata);
        . = ALIGN(4); src/worldmapfx.o(.rodata);
        . = ALIGN(4); src/opinfo_img.o(.rodata);
        . = ALIGN(4); src/opinfo_classdemo.o(.rodata);
        . = ALIGN(4); src/shop.o(.rodata);
        . = ALIGN(4); src/arena_ui.o(.rodata);
        . = ALIGN(4); src/suspend_ui.o(.rodata);
        . = ALIGN(4); src/titlescreen_img.o(.rodata);
        . = ALIGN(4); data/opanim_img.o(.rodata);

        . = ALIGN(4); src/m4a.o(.rodata);
        . = ALIGN(4); data/sounds/voicegroups.o(.rodata);
        . = ALIGN(4); data/sounds/keysplit_tables.o(.rodata);
        . = ALIGN(4); data/sounds/programmable_waves.o(.rodata);
        . = ALIGN(4); data/sounds/music_player_table.o(.rodata);
        . = ALIGN(4); data/sounds/song_table.o(.rodata);
        . = ALIGN(4); data/sounds/direct_sounds.o(.rodata);
        . = ALIGN(4); data/sounds/songs.o(.rodata);

        /* .data */
        . = ALIGN(4); src/gbasram.o(.rodata);
        . = ALIGN(4); src/hardware.o(.data);
        . = ALIGN(4); src/sound.o(.data);
        . = ALIGN(4); src/proc.o(.data);
        . = ALIGN(4); src/debugtext_img.o(.data);
        . = ALIGN(4); src/text.o(.data);
        . = ALIGN(4); src/textglyph_system.o(.data);
        . = ALIGN(4); src/textglyph_special.o(.data);
        . = ALIGN(4); src/textglyph_talk.o(.data);
        . = ALIGN(4); src/sprite.o(.data);
        . = ALIGN(4); src/face.o(.data);
        . = ALIGN(4); src/talk.o(.data);
        . = ALIGN(4); src/event.o(.data);
        . = ALIGN(4); src/spriteanim.o(.data);
        . = ALIGN(4); src/gamecontroller.o(.data);
        . = ALIGN(4); src/util.o(.data);
        . = ALIGN(4); src/bm.o(.data);
        . = ALIGN(4); src/unit.o(.data);
        . = ALIGN(4); src/map.o(.data);
        . = ALIGN(4); src/debugmenu.o(.data);
        . = ALIGN(4); src/playerphase.o(.data);
        . = ALIGN(4); src/bmfx.o(.data);
        . = ALIGN(4); src/mapmenu.o(.data);
        . = ALIGN(4); src/unitsprite.o(.data);
        . = ALIGN(4); src/support.o(.data);
        . = ALIGN(4); src/itemuse.o(.data);
        . = ALIGN(4); src/battle.o(.data);
        . = ALIGN(4); src/trademenu.o(.data);
        . = ALIGN(4); src/trap.o(.data);
        . = ALIGN(4); src/itemaction.o(.data);
        . = ALIGN(4); src/menuinfo.o(.data);
        . = ALIGN(4); src/bmio.o(.data);
        . = ALIGN(4); src/chapter.o(.data);
        . = ALIGN(4); src/arena.o(.data);
        . = ALIGN(4); src/action.o(.data);
        . = ALIGN(4); src/movepath.o(.data);
        . = ALIGN(4); src/prepphase.o(.data);
        . = ALIGN(4); src/unitpanel.o(.data);
        . = ALIGN(4); src/subtitlehelp.o(.data);
        . = ALIGN(4); src/masseffect.o(.data);
        . = ALIGN(4); src/battlepreview.o(.data);
        . = ALIGN(4); src/ai_phase.o(.data);
        . = ALIGN(4); src/ai_order.o(.data);
        . = ALIGN(4); src/ai_decide.o(.data);
        . = ALIGN(4); src/ai_perform.o(.data);
        . = ALIGN(4); src/ai_utility.o(.data);
        . = ALIGN(4); src/ai_data.o(.data);
        . = ALIGN(4); src/ai_battle.o(.data);
        . = ALIGN(4); src/ai_080326C4.o(.data);
        . = ALIGN(4); data/sio_data.o(.data);
        . = ALIGN(4); src/ui.o(.data);
        . = ALIGN(4); src/menu.o(.data);
        . = ALIGN(4); src/mapselect.o(.data);
        . = ALIGN(4); src/banim_ekrbattle.o(.data);
        . = ALIGN(4); src/banim_ekrlvupfan.o(.data);
        . = ALIGN(4); src/banim_ekrgauge.o(.data);
        . = ALIGN(4); src/banim_ekrgauge_data.o(.data);
        . = ALIGN(4); src/banim_ekrdispup.o(.data);
        . = ALIGN(4); src/banim_efxhpbar.o(.data);
        . = ALIGN(4); src/banim_efxdeath.o(.data);
        . = ALIGN(4); src/banim_efxfarattack.o(.data);
        . = ALIGN(4); src/banim_efxquake.o(.data);
        . = ALIGN(4); src/banim_efxflashing.o(.data);
        . = ALIGN(4); src/banim_ekrbattleintro.o(.data);
        . = ALIGN(4); src/banim_ekrbattleintrofx.o(.data);
        . = ALIGN(4); src/banim_ekrmain.o(.data);
        . = ALIGN(4); src/banim_ekrmainmini.o(.data);
        . = ALIGN(4); src/banim_ekrarena.o(.data);
        . = ALIGN(4); src/banim_ekrlvupfx_data.o(.data);
        . = ALIGN(4); src/banim_ekrterrainfx_data.o(.data);
        . = ALIGN(4); src/banim_efxhit_data.o(.data);
        . = ALIGN(4); src/banim_ekrbattleintrofx_data.o(.data);
        . = ALIGN(4); data/banim_efxmagic_.o(.data);
        . = ALIGN(4); src/banim_efxmagic.o(.data);
        . = ALIGN(4); src/banim_efxhit.o(.data);
        . = ALIGN(4); src/banim_efxmisc.o(.data);
        . = ALIGN(4); src/banim_efxopmagic.o(.data);
        . = ALIGN(4); src/banim_scripts.o(.data);
        . = ALIGN(4); src/banim_dragon.o(.data);
        . = ALIGN(4); src/banim_dragonfx_manakete.o(.data);
        . = ALIGN(4); src/banim_dragonfx_fae.o(.data);
        . = ALIGN(4); src/banim_dragonfx_idunn.o(.data);
        . = ALIGN(4); src/banim_dragonfx.o(.data);
        . = ALIGN(4); src/banim_efxutils.o(.data);
        . = ALIGN(4); src/banim_efxsound.o(.data);
        . = ALIGN(4); src/banim_ekrclasschg.o(.data);
        . = ALIGN(4); src/banim_ekrlvup.o(.data);
        . = ALIGN(4); src/banim_ekrlvupfx.o(.data);
        . = ALIGN(4); src/banim_ekrtriangle.o(.data);
        . = ALIGN(4); src/banim_ekrtriangle_data.o(.data);
        . = ALIGN(4); src/banim_bg.o(.data);
        . = ALIGN(4); src/banim_ekrpopup_data.o(.data);
        . = ALIGN(4); src/banim_ekrpopup.o(.data);
        . = ALIGN(4); src/gamedata.o(.data);
        . = ALIGN(4); src/face_img.o(.rodata);
        . = ALIGN(4); src/face_info.o(.data);
        . = ALIGN(4); src/gamedatainfo.o(.data);
        . = ALIGN(4); src/unitsprite_data.o(.data);
        . = ALIGN(4); src/spellassoc_data.o(.data);
        . = ALIGN(4); src/support_bonus.o(.data);
        . = ALIGN(4), src/ending_credit_info.o(.data);
        . = ALIGN(4), src/chapterinfo_data.o(.data);
        . = ALIGN(4), src/chapterinfo_assets.o(.data);
        . = ALIGN(4); src/mu.o(.data);
        . = ALIGN(4); src/mu_info.o(.data);
        . = ALIGN(4); src/manim.o(.data);
        . = ALIGN(4); src/scanline.o(.data);
        . = ALIGN(4); src/eventinfo.o(.data);
        . = ALIGN(4); src/eventinfo_data.o(.data);

        . = ALIGN(4); src/chapterinfo/event_info/ch0.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch1.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch2.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch3.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch4.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch5.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch6.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch7.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch8.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch9.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch10a.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch11a.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch12.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch13.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch14.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch15.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch16.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch17a.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch18a.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch19a.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch20a.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch21.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch22.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch23.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch24.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/final.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch10b.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch11b.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch17b.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch18b.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch19b.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch20b.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch8x.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch12x.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch14x.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch16x.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch20ax.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch20bx.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/ch21x.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/trail1.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/trail2.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/trail3.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/trail4.o(.data);
        . = ALIGN(4); src/chapterinfo/event_info/trail5.o(.data);

        . = ALIGN(4); src/chapterinfo/chapter_shops.o(.data);

        . = ALIGN(4); src/chapterinfo/event_scripts/common.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/tutorial.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter1.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter2.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter3.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter4.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter5.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter6.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter7.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter8.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter9.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter10_a.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter11_a.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter12.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter13.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter14.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter15.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter16.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter17a.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter18a.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter19a.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter20a.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter21.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter22.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter23.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter24.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/final.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter10_b.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter11_b.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter17_s.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter18_s.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter19_s.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter20_s.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter8x.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter12x.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter14x.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter16x.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter20ax.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter20x_s.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/chapter21x.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/trial_a.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/trial_b.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/trial_c.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/trial_d.o(.data);
        . = ALIGN(4); src/chapterinfo/event_scripts/trial_e.o(.data);

        . = ALIGN(4); src/eventfunctions.o(.data);
        . = ALIGN(4); src/ending_monologue.o(.data);
        . = ALIGN(4); src/statscreen.o(.data);
        . = ALIGN(4); src/helpbox.o(.data);
        . = ALIGN(4); src/chapter_title.o(.data);
        . = ALIGN(4); src/helpbox_2.o(.data);
        . = ALIGN(4); src/mapui.o(.data);
        . = ALIGN(4); src/statusscreen.o(.data);
        . = ALIGN(4); src/unitlistscreen.o(.data);
        . = ALIGN(4); src/prepmenu.o(.data);
        . = ALIGN(4); src/prepscreen_disp.o(.data);
        . = ALIGN(4); src/prepmenuitem.o(.data);
        . = ALIGN(4); src/prepscreenfx.o(.data);
        . = ALIGN(4); src/prep_subitemscreen.o(.data);
        . = ALIGN(4); src/prep_subscreen_discard.o(.data);
        . = ALIGN(4); src/prep_menuscrollbar.o(.data);
        . = ALIGN(4); src/prep_bgscroll.o(.data);
        . = ALIGN(4); src/prep_sallycir.o(.data);
        . = ALIGN(4); src/prep_utils.o(.data);
        . = ALIGN(4); asm/secretscreen.o(.data);
        . = ALIGN(4); src/chapterunits.o(.data);
        . = ALIGN(4); src/chapterinfo/map_changes.o(.rodata);
        . = ALIGN(4); src/save_core.o(.data);
        . = ALIGN(4); src/save_xmap.o(.data);
        . = ALIGN(4); src/minimap.o(.data);
        . = ALIGN(4); src/savemenu.o(.data);
        . = ALIGN(4); src/savemenu_2.o(.data);
        . = ALIGN(4); data/savemenufx.o(.data);
        . = ALIGN(4); src/xmap.o(.data);
        . = ALIGN(4); src/soundroom.o(.data);
        . = ALIGN(4); asm/soundroom.o(.data);
        . = ALIGN(4); src/config.o(.data);
        . = ALIGN(4); src/augury.o(.data);
        . = ALIGN(4); src/playrank.o(.data);
        . = ALIGN(4); src/ending_credit.o(.data);
        . = ALIGN(4); data/ending.o(.data);
        . = ALIGN(4); src/ending_credit2.o(.data);
        . = ALIGN(4); src/ending_fin.o(.data);
        . = ALIGN(4); src/ending_cg.o(.data);
        . = ALIGN(4); src/ending_handler.o(.data);
        . = ALIGN(4); src/ending_pinfo.o(.data);
        . = ALIGN(4); src/ending_pinfo_data.o(.data);
        . = ALIGN(4); data/data_68C1DC.o(.data);
        . = ALIGN(4); src/worldmap.o(.data);
        . = ALIGN(4); src/worldmapfx.o(.data);
        . = ALIGN(4); src/worldmap_eventscr.o(.data);
        . = ALIGN(4); src/monologue.o(.data);
        . = ALIGN(4); src/opinfo.o(.data);
        . = ALIGN(4); data/opinfo.o(.data);
        . = ALIGN(4); src/opinfo_classdemo.o(.data);
        . = ALIGN(4); src/shop.o(.data);
        . = ALIGN(4); src/arena_ui.o(.data);
        . = ALIGN(4); src/suspend_ui.o(.data);
        . = ALIGN(4); src/opanim.o(.data);
        . = ALIGN(4); data/opanim.o(.data);
        . = ALIGN(4); src/opanim6.o(.data);
        . = ALIGN(4); data/opanim6.o(.data);
        . = ALIGN(4); src/titlescreen.o(.data);

        . = ALIGN(4); data/_maybayunused_692308.o(.data);
        . = ALIGN(4); src/banimdata_table.o(.data);
        . = ALIGN(4); src/banimdata.o(.data);
        . = ALIGN(4); data/_maybayunused_7E989C.o(.data);
        . = ALIGN(4); src/banimdata_terraininfo.o(.rodata);
        . = ALIGN(4); src/banimdata_terraininfo_data.o(.data);
        . = ALIGN(4); src/banimdata_charpal.o(.rodata);
        . = ALIGN(4); src/banimdata_charpal_data.o(.data);
        . = ALIGN(4); FILL(0xFF);

        . = 0x800000; /* end */
    } = 0

    /* DWARF 2 sections */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    .debug_info     0 : { *(.debug_info) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }

    /* Discard everything not specifically mentioned above. */
    /DISCARD/ :
    {
        *(*);
    }
}
