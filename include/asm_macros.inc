    .macro function name
    .align 2, 0
    .global \name
    .type \name , function
    .endm

    .macro endfunction name
    .size \name , . - \name
    .endm

    .macro thumb_function name
    function \name
    .thumb
    .thumb_func
    .endm
