    .syntax unified
    .cpu cortex-m4
    .thumb

    .section .vectors, "a", %progbits
vector_table:
    .word _estack
    .word Reset_Handler
    .word Default_Handler /* NMI */
    .word Default_Handler /* HardFault */
    .word Default_Handler /* MemManage */
    .word Default_Handler /* BusFault */
    .word Default_Handler /* UseageFault */
    .word 0               /* reserved */
    .word 0               /* reserved */
    .word 0               /* reserved */
    .word 0               /* reserved */
    .word Default_Handler /* SVCall */
    .word Default_Handler /* DebugMonitor */
    .word 0               /* reserved */
    .word Default_Handler /* PendSV */
    .word Default_Handler /* SysTick */
    .rept 91
    .word Default_Handler
    .endr

    .section .text.Reset_Handler
    .type Reset_Handler, %function
    .weak Reset_Handler
    .global Reset_Handler
Reset_Handler:
    /* copy data from flash to sram */
    ldr r0, =_sdata
    ldr r1, =_edata
    ldr r2, =_sidata
    b Data_Copy_Check
Data_Copy_Loop:
    ldr r3, [r2], #4
    str r3, [r0], #4
Data_Copy_Check:
    cmp r0, r1
    blo Data_Copy_Loop
    ldr r0, =_sbss
    ldr r1, =_ebss
    mov r2, #0
    b Bss_Zero_Check
Bss_Zero_Loop:
    str r2, [r0], #4
Bss_Zero_Check:
    cmp r0, r1
    blo Bss_Zero_Loop
    bl main
Loop:
    b Loop
    .size Reset_Handler, . - Reset_Handler

    .section .text.Default_Handler
    .type Default_Handler, %function
    .weak Default_Handler
    .global Default_Handler
Default_Handler:
    b Default_Handler
    .size Default_Handler, . - Default_Handler

