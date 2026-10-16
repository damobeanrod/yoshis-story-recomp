#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8077DE28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077DE28: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x8077DE2C: lbu         $v1, 0x10($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X10);
    // 0x8077DE30: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x8077DE34: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8077DE38: bgez        $v1, L_8077DE44
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8077DE3C: nop
    
            goto L_8077DE44;
    }
    // 0x8077DE3C: nop

    // 0x8077DE40: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8077DE44:
    // 0x8077DE44: jr          $ra
    // 0x8077DE48: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
    return;
    // 0x8077DE48: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_80037FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037FB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037FBC: jal         0x80021958
    // 0x80037FC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80037FC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80037FC4: bne         $v0, $zero, L_80037FD4
    if (ctx->r2 != 0) {
        // 0x80037FC8: nop
    
            goto L_80037FD4;
    }
    // 0x80037FC8: nop

    // 0x80037FCC: b           L_80038008
    // 0x80037FD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038008;
    // 0x80037FD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037FD4:
    // 0x80037FD4: jal         0x800415FC
    // 0x80037FD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x80037FD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80037FDC: beq         $v0, $zero, L_80037FEC
    if (ctx->r2 == 0) {
        // 0x80037FE0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80037FEC;
    }
    // 0x80037FE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80037FE4: b           L_80038008
    // 0x80037FE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038008;
    // 0x80037FE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037FEC:
    // 0x80037FEC: jal         0x800376A4
    // 0x80037FF0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800376A4(rdram, ctx);
        goto after_2;
    // 0x80037FF0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80037FF4: bnel        $v0, $zero, L_80038008
    if (ctx->r2 != 0) {
        // 0x80037FF8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80038008;
    }
    goto skip_0;
    // 0x80037FF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80037FFC: b           L_80038008
    // 0x80038000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038008;
    // 0x80038000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80038004: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80038008:
    // 0x80038008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003800C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038010: jr          $ra
    // 0x80038014: nop

    return;
    // 0x80038014: nop

;}
RECOMP_FUNC void gfxprint_putc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F79C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007F7A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007F7A4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8007F7A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007F7AC: slti        $at, $a1, 0x20
    ctx->r1 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x8007F7B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007F7B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007F7B8: bne         $at, $zero, L_8007F7DC
    if (ctx->r1 != 0) {
        // 0x8007F7BC: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8007F7DC;
    }
    // 0x8007F7BC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8007F7C0: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x8007F7C4: beql        $at, $zero, L_8007F7E0
    if (ctx->r1 == 0) {
        // 0x8007F7C8: slti        $at, $v0, 0xA0
        ctx->r1 = SIGNED(ctx->r2) < 0XA0 ? 1 : 0;
            goto L_8007F7E0;
    }
    goto skip_0;
    // 0x8007F7C8: slti        $at, $v0, 0xA0
    ctx->r1 = SIGNED(ctx->r2) < 0XA0 ? 1 : 0;
    skip_0:
    // 0x8007F7CC: jal         0x8007F4A0
    // 0x8007F7D0: nop

    gfxprint_putc1(rdram, ctx);
        goto after_0;
    // 0x8007F7D0: nop

    after_0:
    // 0x8007F7D4: b           L_8007F910
    // 0x8007F7D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007F910;
    // 0x8007F7D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007F7DC:
    // 0x8007F7DC: slti        $at, $v0, 0xA0
    ctx->r1 = SIGNED(ctx->r2) < 0XA0 ? 1 : 0;
L_8007F7E0:
    // 0x8007F7E0: bne         $at, $zero, L_8007F828
    if (ctx->r1 != 0) {
        // 0x8007F7E4: slti        $at, $v0, 0xE0
        ctx->r1 = SIGNED(ctx->r2) < 0XE0 ? 1 : 0;
            goto L_8007F828;
    }
    // 0x8007F7E4: slti        $at, $v0, 0xE0
    ctx->r1 = SIGNED(ctx->r2) < 0XE0 ? 1 : 0;
    // 0x8007F7E8: beql        $at, $zero, L_8007F82C
    if (ctx->r1 == 0) {
        // 0x8007F7EC: slti        $at, $v0, 0xB
        ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
            goto L_8007F82C;
    }
    goto skip_1;
    // 0x8007F7EC: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    skip_1:
    // 0x8007F7F0: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x8007F7F4: slti        $at, $v0, 0xC0
    ctx->r1 = SIGNED(ctx->r2) < 0XC0 ? 1 : 0;
    // 0x8007F7F8: beq         $t6, $zero, L_8007F818
    if (ctx->r14 == 0) {
        // 0x8007F7FC: nop
    
            goto L_8007F818;
    }
    // 0x8007F7FC: nop

    // 0x8007F800: beq         $at, $zero, L_8007F814
    if (ctx->r1 == 0) {
        // 0x8007F804: addiu       $a1, $v0, 0x20
        ctx->r5 = ADD32(ctx->r2, 0X20);
            goto L_8007F814;
    }
    // 0x8007F804: addiu       $a1, $v0, 0x20
    ctx->r5 = ADD32(ctx->r2, 0X20);
    // 0x8007F808: addiu       $a1, $v0, -0x20
    ctx->r5 = ADD32(ctx->r2, -0X20);
    // 0x8007F80C: b           L_8007F818
    // 0x8007F810: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
        goto L_8007F818;
    // 0x8007F810: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_8007F814:
    // 0x8007F814: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_8007F818:
    // 0x8007F818: jal         0x8007F4A0
    // 0x8007F81C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gfxprint_putc1(rdram, ctx);
        goto after_1;
    // 0x8007F81C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8007F820: b           L_8007F910
    // 0x8007F824: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007F910;
    // 0x8007F824: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007F828:
    // 0x8007F828: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
L_8007F82C:
    // 0x8007F82C: bne         $at, $zero, L_8007F870
    if (ctx->r1 != 0) {
        // 0x8007F830: slti        $at, $v0, 0xE
        ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
            goto L_8007F870;
    }
    // 0x8007F830: slti        $at, $v0, 0xE
    ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
    // 0x8007F834: bne         $at, $zero, L_8007F85C
    if (ctx->r1 != 0) {
        // 0x8007F838: addiu       $t7, $v0, -0x8A
        ctx->r15 = ADD32(ctx->r2, -0X8A);
            goto L_8007F85C;
    }
    // 0x8007F838: addiu       $t7, $v0, -0x8A
    ctx->r15 = ADD32(ctx->r2, -0X8A);
    // 0x8007F83C: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x8007F840: beq         $at, $zero, L_8007F90C
    if (ctx->r1 == 0) {
        // 0x8007F844: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8007F90C;
    }
    // 0x8007F844: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007F848: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8007F84C: addu        $at, $at, $t7
    gpr jr_addend_8007F854 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007F850: lw          $t7, 0x2F50($at)
    ctx->r15 = ADD32(ctx->r1, 0X2F50);
    // 0x8007F854: jr          $t7
    // 0x8007F858: nop

    switch (jr_addend_8007F854 >> 2) {
        case 0: goto L_8007F900; break;
        case 1: goto L_8007F8F0; break;
        case 2: goto L_8007F8E8; break;
        case 3: goto L_8007F8DC; break;
        case 4: goto L_8007F90C; break;
        default: switch_error(__func__, 0x8007F854, 0x800B2F50);
    }
    // 0x8007F858: nop

L_8007F85C:
    // 0x8007F85C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8007F860: beql        $v0, $at, L_8007F898
    if (ctx->r2 == ctx->r1) {
        // 0x8007F864: lw          $t0, 0x28($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X28);
            goto L_8007F898;
    }
    goto skip_2;
    // 0x8007F864: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
    skip_2:
    // 0x8007F868: b           L_8007F910
    // 0x8007F86C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007F910;
    // 0x8007F86C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007F870:
    // 0x8007F870: beq         $v0, $zero, L_8007F90C
    if (ctx->r2 == 0) {
        // 0x8007F874: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8007F90C;
    }
    // 0x8007F874: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8007F878: beq         $v0, $at, L_8007F8A0
    if (ctx->r2 == ctx->r1) {
        // 0x8007F87C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8007F8A0;
    }
    // 0x8007F87C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007F880: bnel        $v0, $at, L_8007F910
    if (ctx->r2 != ctx->r1) {
        // 0x8007F884: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007F910;
    }
    goto skip_3;
    // 0x8007F884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8007F888: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x8007F88C: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x8007F890: sw          $t9, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r25;
    // 0x8007F894: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
L_8007F898:
    // 0x8007F898: b           L_8007F90C
    // 0x8007F89C: sw          $t0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r8;
        goto L_8007F90C;
    // 0x8007F89C: sw          $t0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r8;
L_8007F8A0:
    // 0x8007F8A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8007F8A4:
    // 0x8007F8A4: jal         0x8007F4A0
    // 0x8007F8A8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    gfxprint_putc1(rdram, ctx);
        goto after_2;
    // 0x8007F8A8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_2:
    // 0x8007F8AC: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x8007F8B0: lw          $t2, 0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X28);
    // 0x8007F8B4: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8007F8B8: bgez        $t3, L_8007F8CC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8007F8BC: andi        $t4, $t3, 0xFF
        ctx->r12 = ctx->r11 & 0XFF;
            goto L_8007F8CC;
    }
    // 0x8007F8BC: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8007F8C0: beq         $t4, $zero, L_8007F8CC
    if (ctx->r12 == 0) {
        // 0x8007F8C4: nop
    
            goto L_8007F8CC;
    }
    // 0x8007F8C4: nop

    // 0x8007F8C8: addiu       $t4, $t4, -0x100
    ctx->r12 = ADD32(ctx->r12, -0X100);
L_8007F8CC:
    // 0x8007F8CC: bnel        $t4, $zero, L_8007F8A4
    if (ctx->r12 != 0) {
        // 0x8007F8D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8007F8A4;
    }
    goto skip_4;
    // 0x8007F8D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x8007F8D4: b           L_8007F910
    // 0x8007F8D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007F910;
    // 0x8007F8D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007F8DC:
    // 0x8007F8DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007F8E0: b           L_8007F90C
    // 0x8007F8E4: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
        goto L_8007F90C;
    // 0x8007F8E4: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
L_8007F8E8:
    // 0x8007F8E8: b           L_8007F90C
    // 0x8007F8EC: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
        goto L_8007F90C;
    // 0x8007F8EC: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
L_8007F8F0:
    // 0x8007F8F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007F8F4: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x8007F8F8: b           L_8007F90C
    // 0x8007F8FC: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
        goto L_8007F90C;
    // 0x8007F8FC: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
L_8007F900:
    // 0x8007F900: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007F904: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8007F908: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
L_8007F90C:
    // 0x8007F90C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007F910:
    // 0x8007F910: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007F914: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007F918: jr          $ra
    // 0x8007F91C: nop

    return;
    // 0x8007F91C: nop

;}
RECOMP_FUNC void func_80035694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035694: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80035698: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003569C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800356A0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800356A4: lw          $v0, -0x77F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X77F0);
    // 0x800356A8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800356AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800356B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800356B4: lwc1        $f4, 0x84($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X84);
    // 0x800356B8: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x800356BC: addiu       $t8, $t8, 0x5450
    ctx->r24 = ADD32(ctx->r24, 0X5450);
    // 0x800356C0: lh          $a2, 0x6($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X6);
    // 0x800356C4: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x800356C8: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x800356CC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800356D0: jal         0x80035540
    // 0x800356D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80035540(rdram, ctx);
        goto after_0;
    // 0x800356D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800356D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800356DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800356E0: jr          $ra
    // 0x800356E4: nop

    return;
    // 0x800356E4: nop

;}
RECOMP_FUNC void func_80036298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003629C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800362A0: jal         0x80021958
    // 0x800362A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x800362A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800362A8: bne         $v0, $zero, L_800362B8
    if (ctx->r2 != 0) {
        // 0x800362AC: nop
    
            goto L_800362B8;
    }
    // 0x800362AC: nop

    // 0x800362B0: b           L_800362EC
    // 0x800362B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800362EC;
    // 0x800362B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800362B8:
    // 0x800362B8: jal         0x800415FC
    // 0x800362BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x800362BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800362C0: beq         $v0, $zero, L_800362D0
    if (ctx->r2 == 0) {
        // 0x800362C4: nop
    
            goto L_800362D0;
    }
    // 0x800362C4: nop

    // 0x800362C8: b           L_800362EC
    // 0x800362CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800362EC;
    // 0x800362CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800362D0:
    // 0x800362D0: jal         0x80035E28
    // 0x800362D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80035E28(rdram, ctx);
        goto after_2;
    // 0x800362D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800362D8: bnel        $v0, $zero, L_800362EC
    if (ctx->r2 != 0) {
        // 0x800362DC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800362EC;
    }
    goto skip_0;
    // 0x800362DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800362E0: b           L_800362EC
    // 0x800362E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800362EC;
    // 0x800362E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800362E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800362EC:
    // 0x800362EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800362F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800362F4: jr          $ra
    // 0x800362F8: nop

    return;
    // 0x800362F8: nop

;}
RECOMP_FUNC void func_80799EBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799EBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80799EC0: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80799EC4: lw          $t9, -0x729C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X729C);
    // 0x80799EC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799ECC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80799ED0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80799ED4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80799ED8: jalr        $t9
    // 0x80799EDC: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80799EDC: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_0:
    // 0x80799EE0: beq         $v0, $zero, L_80799F10
    if (ctx->r2 == 0) {
        // 0x80799EE4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80799F10;
    }
    // 0x80799EE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80799EE8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80799EEC: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x80799EF0: lw          $a1, 0x1D8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X1D8);
    // 0x80799EF4: jal         0x80048BE8
    // 0x80799EF8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_1;
    // 0x80799EF8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_1:
    // 0x80799EFC: jal         0x80067E68
    // 0x80799F00: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_80067E68(rdram, ctx);
        goto after_2;
    // 0x80799F00: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_2:
    // 0x80799F04: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80799F08: jal         0x80067818
    // 0x80799F0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80799F0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_80799F10:
    // 0x80799F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80799F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80799F18: jr          $ra
    // 0x80799F1C: nop

    return;
    // 0x80799F1C: nop

;}
RECOMP_FUNC void func_8006CAE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CAE0: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8006CAE4: lw          $v1, -0x7D6C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D6C);
    // 0x8006CAE8: beq         $a0, $zero, L_8006CAFC
    if (ctx->r4 == 0) {
        // 0x8006CAEC: lhu         $v0, 0x64($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X64);
            goto L_8006CAFC;
    }
    // 0x8006CAEC: lhu         $v0, 0x64($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X64);
    // 0x8006CAF0: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // 0x8006CAF4: b           L_8006CB04
    // 0x8006CAF8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
        goto L_8006CB04;
    // 0x8006CAF8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_8006CAFC:
    // 0x8006CAFC: andi        $v0, $v0, 0xFFFB
    ctx->r2 = ctx->r2 & 0XFFFB;
    // 0x8006CB00: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_8006CB04:
    // 0x8006CB04: jr          $ra
    // 0x8006CB08: sh          $v0, 0x64($v1)
    MEM_H(0X64, ctx->r3) = ctx->r2;
    return;
    // 0x8006CB08: sh          $v0, 0x64($v1)
    MEM_H(0X64, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80020EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020EB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020EB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020EBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80020EC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80020EC4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80020EC8: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80020ECC: addiu       $v0, $a2, 0xC
    ctx->r2 = ADD32(ctx->r6, 0XC);
    // 0x80020ED0: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
L_80020ED4:
    // 0x80020ED4: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80020ED8: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80020EDC: lbu         $t7, 0x14($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X14);
    // 0x80020EE0: bnel        $t7, $zero, L_80020EF4
    if (ctx->r15 != 0) {
        // 0x80020EE4: addu        $t8, $a3, $v1
        ctx->r24 = ADD32(ctx->r7, ctx->r3);
            goto L_80020EF4;
    }
    goto skip_0;
    // 0x80020EE4: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
    skip_0:
    // 0x80020EE8: bnel        $v1, $zero, L_80020ED4
    if (ctx->r3 != 0) {
        // 0x80020EEC: lw          $t6, -0x4($v0)
        ctx->r14 = MEM_W(ctx->r2, -0X4);
            goto L_80020ED4;
    }
    goto skip_1;
    // 0x80020EEC: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    skip_1:
    // 0x80020EF0: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
L_80020EF4:
    // 0x80020EF4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80020EF8: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x80020EFC: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x80020F00: jal         0x8004D698
    // 0x80020F04: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8004D698(rdram, ctx);
        goto after_0;
    // 0x80020F04: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x80020F08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80020F0C: jal         0x80020E4C
    // 0x80020F10: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80020E4C(rdram, ctx);
        goto after_1;
    // 0x80020F10: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80020F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020F18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020F1C: jr          $ra
    // 0x80020F20: nop

    return;
    // 0x80020F20: nop

;}
RECOMP_FUNC void func_807A6450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6450: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A6454: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x807A6458: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807A645C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1584) << 16);
    // 0x807A6460: lwc1        $f6, 0x7284($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1584));
    // 0x807A6464: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807A6468: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807A646C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x807A6470: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807A6474: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x807A6478: nop

    // 0x807A647C: bc1fl       L_807A648C
    if (!c1cs) {
        // 0x807A6480: lhu         $t6, 0xC($a0)
        ctx->r14 = MEM_HU(ctx->r4, 0XC);
            goto L_807A648C;
    }
    goto skip_0;
    // 0x807A6480: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    skip_0:
    // 0x807A6484: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x807A6488: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
L_807A648C:
    // 0x807A648C: addiu       $at, $zero, 0x46E6
    ctx->r1 = ADD32(0, 0X46E6);
    // 0x807A6490: bne         $t6, $at, L_807A64B4
    if (ctx->r14 != ctx->r1) {
        // 0x807A6494: lui         $at, 0x807A
        ctx->r1 = S32(RELOC_HI16(847, 0X1588) << 16);
            goto L_807A64B4;
    }
    // 0x807A6494: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1588) << 16);
    // 0x807A6498: lwc1        $f18, 0x7288($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1588));
    // 0x807A649C: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x807A64A0: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x807A64A4: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x807A64A8: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x807A64AC: b           L_807A64D0
    // 0x807A64B0: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
        goto L_807A64D0;
    // 0x807A64B0: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
L_807A64B4:
    // 0x807A64B4: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X158C) << 16);
    // 0x807A64B8: lwc1        $f10, 0x728C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X158C));
    // 0x807A64BC: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x807A64C0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x807A64C4: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x807A64C8: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x807A64CC: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
L_807A64D0:
    // 0x807A64D0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x807A64D4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807A64D8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x807A64DC: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x807A64E0: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x807A64E4: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x807A64E8: jr          $ra
    // 0x807A64EC: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x807A64EC: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_804EF5A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF5A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EF5A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804EF5A8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804EF5AC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804EF5B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF5B4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804EF5B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804EF5BC: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x804EF5C0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804EF5C4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804EF5C8: lui         $t2, 0x804F
    ctx->r10 = S32(RELOC_HI16(267, 0X1060) << 16);
    // 0x804EF5CC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804EF5D0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804EF5D4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804EF5D8: lw          $t2, -0x210($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(267, 0X1060));
    // 0x804EF5DC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804EF5E0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804EF5E4: jal         0x804EEE08
    // 0x804EF5E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804EEE08(rdram, ctx);
        goto after_0;
    // 0x804EF5E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804EF5EC: jal         0x804EEE64
    // 0x804EF5F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804EEE64(rdram, ctx);
        goto after_1;
    // 0x804EF5F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804EF5F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EF5F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EF5FC: jr          $ra
    // 0x804EF600: nop

    return;
    // 0x804EF600: nop

;}
RECOMP_FUNC void func_8004F5A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F5A4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8004F5A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004F5AC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8004F5B0: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8004F5B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004F5B8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004F5BC: nop

    // 0x8004F5C0: bc1fl       L_8004F5D4
    if (!c1cs) {
        // 0x8004F5C4: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8004F5D4;
    }
    goto skip_0;
    // 0x8004F5C4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x8004F5C8: jr          $ra
    // 0x8004F5CC: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x8004F5CC: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x8004F5D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8004F5D4:
    // 0x8004F5D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004F5D8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004F5DC: nop

    // 0x8004F5E0: bc1f        L_8004F5F4
    if (!c1cs) {
        // 0x8004F5E4: nop
    
            goto L_8004F5F4;
    }
    // 0x8004F5E4: nop

    // 0x8004F5E8: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x8004F5EC: jr          $ra
    // 0x8004F5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8004F5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004F5F4:
    // 0x8004F5F4: jr          $ra
    // 0x8004F5F8: nop

    return;
    // 0x8004F5F8: nop

;}
RECOMP_FUNC void func_80435B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80435B50: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80435B54: lw          $v1, 0x7F78($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7F78);
    // 0x80435B58: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80435B5C: andi        $a2, $v1, 0x7
    ctx->r6 = ctx->r3 & 0X7;
    // 0x80435B60: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80435B64: bne         $at, $zero, L_80435B94
    if (ctx->r1 != 0) {
        // 0x80435B68: sll         $t0, $a2, 2
        ctx->r8 = S32(ctx->r6 << 2);
            goto L_80435B94;
    }
    // 0x80435B68: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x80435B6C: addiu       $a1, $a2, -0x4
    ctx->r5 = ADD32(ctx->r6, -0X4);
    // 0x80435B70: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80435B74: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80435B78: lw          $t7, 0x124C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X124C);
    // 0x80435B7C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80435B80: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80435B84: bne         $at, $zero, L_80435BB0
    if (ctx->r1 != 0) {
        // 0x80435B88: sw          $t8, 0x124C($v1)
        MEM_W(0X124C, ctx->r3) = ctx->r24;
            goto L_80435BB0;
    }
    // 0x80435B88: sw          $t8, 0x124C($v1)
    MEM_W(0X124C, ctx->r3) = ctx->r24;
    // 0x80435B8C: jr          $ra
    // 0x80435B90: sw          $zero, 0x124C($v1)
    MEM_W(0X124C, ctx->r3) = 0;
    return;
    // 0x80435B90: sw          $zero, 0x124C($v1)
    MEM_W(0X124C, ctx->r3) = 0;
L_80435B94:
    // 0x80435B94: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x80435B98: lw          $t1, 0x124C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X124C);
    // 0x80435B9C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80435BA0: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x80435BA4: bne         $at, $zero, L_80435BB0
    if (ctx->r1 != 0) {
        // 0x80435BA8: sw          $t2, 0x124C($v1)
        MEM_W(0X124C, ctx->r3) = ctx->r10;
            goto L_80435BB0;
    }
    // 0x80435BA8: sw          $t2, 0x124C($v1)
    MEM_W(0X124C, ctx->r3) = ctx->r10;
    // 0x80435BAC: sw          $zero, 0x124C($v1)
    MEM_W(0X124C, ctx->r3) = 0;
L_80435BB0:
    // 0x80435BB0: jr          $ra
    // 0x80435BB4: nop

    return;
    // 0x80435BB4: nop

;}
RECOMP_FUNC void func_80672574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80672574: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80672578: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067257C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80672580: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80672584: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80672588: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8067258C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80672590: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80672594: addiu       $a1, $s0, 0x90
    ctx->r5 = ADD32(ctx->r16, 0X90);
    // 0x80672598: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8067259C: lw          $t7, 0x1E0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E0);
    // 0x806725A0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x806725A4: blez        $t8, L_806725D8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x806725A8: sw          $t8, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r24;
            goto L_806725D8;
    }
    // 0x806725A8: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x806725AC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806725B0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x806725B4: jal         0x806717F0
    // 0x806725B8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_806717F0(rdram, ctx);
        goto after_0;
    // 0x806725B8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_0:
    // 0x806725BC: beq         $v0, $zero, L_806725C8
    if (ctx->r2 == 0) {
        // 0x806725C0: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_806725C8;
    }
    // 0x806725C0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x806725C4: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
L_806725C8:
    // 0x806725C8: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x806725CC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x806725D0: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x806725D4: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_806725D8:
    // 0x806725D8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x806725DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806725E0: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x806725E4: beql        $at, $zero, L_80672624
    if (ctx->r1 == 0) {
        // 0x806725E8: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_80672624;
    }
    goto skip_0;
    // 0x806725E8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x806725EC: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x806725F0: lw          $t5, 0x1E0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1E0);
    // 0x806725F4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x806725F8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x806725FC: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80672600: lw          $t7, 0x1E0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E0);
    // 0x80672604: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x80672608: bne         $at, $zero, L_80672618
    if (ctx->r1 != 0) {
        // 0x8067260C: nop
    
            goto L_80672618;
    }
    // 0x8067260C: nop

    // 0x80672610: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80672614: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
L_80672618:
    // 0x80672618: jal         0x80671BE4
    // 0x8067261C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80671BE4(rdram, ctx);
        goto after_1;
    // 0x8067261C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80672620: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80672624:
    // 0x80672624: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80672628: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x8067262C: bnel        $at, $zero, L_80672740
    if (ctx->r1 != 0) {
        // 0x80672630: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80672740;
    }
    goto skip_1;
    // 0x80672630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80672634: jal         0x80067878
    // 0x80672638: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_2;
    // 0x80672638: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8067263C: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    // 0x80672640: jal         0x80067818
    // 0x80672644: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80672644: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80672648: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8067264C: lw          $t9, -0x7478($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7478);
    // 0x80672650: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80672654: bnel        $t9, $zero, L_806726BC
    if (ctx->r25 != 0) {
        // 0x80672658: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_806726BC;
    }
    goto skip_2;
    // 0x80672658: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_2:
    // 0x8067265C: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
    // 0x80672660: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80672664: jal         0x80672C80
    // 0x80672668: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
    func_80672C80(rdram, ctx);
        goto after_4;
    // 0x80672668: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
    after_4:
    // 0x8067266C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80672670: beql        $v0, $zero, L_80672688
    if (ctx->r2 == 0) {
        // 0x80672674: lw          $t2, 0x1C($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1C);
            goto L_80672688;
    }
    goto skip_3;
    // 0x80672674: lw          $t2, 0x1C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C);
    skip_3:
    // 0x80672678: lw          $t1, 0x1F4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1F4);
    // 0x8067267C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80672680: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x80672684: lw          $t2, 0x1C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C);
L_80672688:
    // 0x80672688: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8067268C: lw          $t3, 0x1F4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1F4);
    // 0x80672690: sw          $v1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r3;
    // 0x80672694: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x80672698: lw          $t5, 0x1F4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1F4);
    // 0x8067269C: sw          $v1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r3;
    // 0x806726A0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x806726A4: beql        $v0, $zero, L_80672740
    if (ctx->r2 == 0) {
        // 0x806726A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80672740;
    }
    goto skip_4;
    // 0x806726A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x806726AC: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x806726B0: b           L_8067273C
    // 0x806726B4: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
        goto L_8067273C;
    // 0x806726B4: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x806726B8: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
L_806726BC:
    // 0x806726BC: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x806726C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x806726C4: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x806726C8: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x806726CC: beq         $at, $zero, L_806726EC
    if (ctx->r1 == 0) {
        // 0x806726D0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_806726EC;
    }
    // 0x806726D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806726D4: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x806726D8: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // 0x806726DC: jal         0x80672C80
    // 0x806726E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80672C80(rdram, ctx);
        goto after_5;
    // 0x806726E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x806726E4: b           L_80672740
    // 0x806726E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80672740;
    // 0x806726E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806726EC:
    // 0x806726EC: jal         0x80672C80
    // 0x806726F0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80672C80(rdram, ctx);
        goto after_6;
    // 0x806726F0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_6:
    // 0x806726F4: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x806726F8: beql        $v0, $zero, L_80672710
    if (ctx->r2 == 0) {
        // 0x806726FC: lw          $t9, 0x1C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X1C);
            goto L_80672710;
    }
    goto skip_5;
    // 0x806726FC: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    skip_5:
    // 0x80672700: lw          $t8, 0x1F4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1F4);
    // 0x80672704: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80672708: sw          $v1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r3;
    // 0x8067270C: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
L_80672710:
    // 0x80672710: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80672714: lw          $t0, 0x1F4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1F4);
    // 0x80672718: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8067271C: lw          $t1, 0x20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X20);
    // 0x80672720: lw          $t2, 0x1F4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1F4);
    // 0x80672724: sw          $v1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r3;
    // 0x80672728: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8067272C: beql        $v0, $zero, L_80672740
    if (ctx->r2 == 0) {
        // 0x80672730: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80672740;
    }
    goto skip_6;
    // 0x80672730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80672734: lw          $t3, 0x1F4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1F4);
    // 0x80672738: sw          $v1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r3;
L_8067273C:
    // 0x8067273C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80672740:
    // 0x80672740: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80672744: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80672748: jr          $ra
    // 0x8067274C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8067274C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_804CC140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC140: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804CC144: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CC148: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804CC14C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CC150: lui         $a0, 0x804B
    ctx->r4 = S32(0X804B << 16);
    // 0x804CC154: lui         $a3, 0x7F7F
    ctx->r7 = S32(0X7F7F << 16);
    // 0x804CC158: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x804CC15C: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x804CC160: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x804CC164: jal         0x8004613C
    // 0x804CC168: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x804CC168: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    after_0:
    // 0x804CC16C: beq         $v0, $zero, L_804CC17C
    if (ctx->r2 == 0) {
        // 0x804CC170: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_804CC17C;
    }
    // 0x804CC170: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804CC174: jal         0x80044194
    // 0x804CC178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80044194(rdram, ctx);
        goto after_1;
    // 0x804CC178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
L_804CC17C:
    // 0x804CC17C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CC180: jal         0x80045A34
    // 0x804CC184: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x804CC184: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x804CC188: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804CC18C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x804CC190: jal         0x804CC3DC
    // 0x804CC194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CC3DC(rdram, ctx);
        goto after_3;
    // 0x804CC194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804CC198: lui         $t6, 0x804D
    ctx->r14 = S32(RELOC_HI16(234, 0X210) << 16);
    // 0x804CC19C: addiu       $t6, $t6, -0x3CC0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(234, 0X210));
    // 0x804CC1A0: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
    // 0x804CC1A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804CC1A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CC1AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804CC1B0: jr          $ra
    // 0x804CC1B4: nop

    return;
    // 0x804CC1B4: nop

;}
RECOMP_FUNC void func_80536080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536080: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80536084: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80536088: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8053608C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80536090: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80536094: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80536098: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8053609C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805360A0: addiu       $t6, $zero, 0x1C20
    ctx->r14 = ADD32(0, 0X1C20);
    // 0x805360A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x805360A8: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x805360AC: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x805360B0: addiu       $a1, $zero, 0x2D0
    ctx->r5 = ADD32(0, 0X2D0);
    // 0x805360B4: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x805360B8: jal         0x8053589C
    // 0x805360BC: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_8053589C(rdram, ctx);
        goto after_0;
    // 0x805360BC: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x805360C0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x805360C4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805360C8: addiu       $t8, $zero, 0x1C20
    ctx->r24 = ADD32(0, 0X1C20);
    // 0x805360CC: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x805360D0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x805360D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x805360D8: addiu       $a1, $zero, 0x2D0
    ctx->r5 = ADD32(0, 0X2D0);
    // 0x805360DC: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x805360E0: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x805360E4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x805360E8: jal         0x8053589C
    // 0x805360EC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_8053589C(rdram, ctx);
        goto after_1;
    // 0x805360EC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x805360F0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805360F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805360F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805360FC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80536100: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80536104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80536108: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8053610C: jr          $ra
    // 0x80536110: nop

    return;
    // 0x80536110: nop

;}
RECOMP_FUNC void func_8045B080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045B084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045B088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045B08C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8045B090: jal         0x8045B594
    // 0x8045B094: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8045B594(rdram, ctx);
        goto after_0;
    // 0x8045B094: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8045B098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045B09C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045B0A0: jr          $ra
    // 0x8045B0A4: nop

    return;
    // 0x8045B0A4: nop

;}
RECOMP_FUNC void func_807B4D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B4D88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B4D8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B4D90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807B4D94: jal         0x807B4A10
    // 0x807B4D98: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_807B4A10(rdram, ctx);
        goto after_0;
    // 0x807B4D98: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x807B4D9C: lui         $a1, 0x807B
    ctx->r5 = S32(RELOC_HI16(880, 0X2CB8) << 16);
    // 0x807B4DA0: addiu       $a1, $a1, 0x74B8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(880, 0X2CB8));
    // 0x807B4DA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807B4DA8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x807B4DAC: jal         0x807B4900
    // 0x807B4DB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807B4900(rdram, ctx);
        goto after_1;
    // 0x807B4DB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x807B4DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B4DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B4DBC: jr          $ra
    // 0x807B4DC0: nop

    return;
    // 0x807B4DC0: nop

;}
RECOMP_FUNC void func_8007861C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007861C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80078620: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80078624: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80078628: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8007862C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80078630: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80078634: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80078638: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8007863C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80078640: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80078644: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80078648: beq         $t8, $zero, L_80078670
    if (ctx->r24 == 0) {
        // 0x8007864C: sw          $t7, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r15;
            goto L_80078670;
    }
    // 0x8007864C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80078650: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80078654: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80078658: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x8007865C: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80078660: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80078664: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80078668: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x8007866C: sw          $t2, -0x7A20($at)
    MEM_W(-0X7A20, ctx->r1) = ctx->r10;
L_80078670:
    // 0x80078670: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80078674: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80078678: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8007867C: lhu         $v0, 0x4($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X4);
    // 0x80078680: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x80078684: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80078688: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007868C: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80078690: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80078694: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80078698: sll         $a3, $v0, 24
    ctx->r7 = S32(ctx->r2 << 24);
    // 0x8007869C: srl         $a3, $a3, 24
    ctx->r7 = S32(U32(ctx->r7) >> 24);
    // 0x800786A0: srl         $a2, $a2, 24
    ctx->r6 = S32(U32(ctx->r6) >> 24);
    // 0x800786A4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800786A8: addu        $a0, $t4, $t6
    ctx->r4 = ADD32(ctx->r12, ctx->r14);
    // 0x800786AC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800786B0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800786B4: jal         0x800784AC
    // 0x800786B8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    func_800784AC(rdram, ctx);
        goto after_0;
    // 0x800786B8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800786BC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800786C0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800786C4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800786C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800786CC: jr          $ra
    // 0x800786D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800786D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80023E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023E18: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
    // 0x80023E1C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80023E20: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80023E24: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80023E28: bc1fl       L_80023E5C
    if (!c1cs) {
        // 0x80023E2C: sub.s       $f0, $f12, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f10.fl;
            goto L_80023E5C;
    }
    goto skip_0;
    // 0x80023E2C: sub.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f10.fl;
    skip_0:
    // 0x80023E30: sub.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x80023E34: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80023E38: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80023E3C: nop

    // 0x80023E40: bc1f        L_80023E50
    if (!c1cs) {
        // 0x80023E44: nop
    
            goto L_80023E50;
    }
    // 0x80023E44: nop

    // 0x80023E48: jr          $ra
    // 0x80023E4C: add.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f6.fl;
    return;
    // 0x80023E4C: add.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f6.fl;
L_80023E50:
    // 0x80023E50: jr          $ra
    // 0x80023E54: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    return;
    // 0x80023E54: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x80023E58: sub.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f10.fl;
L_80023E5C:
    // 0x80023E5C: jr          $ra
    // 0x80023E60: nop

    return;
    // 0x80023E60: nop

;}
RECOMP_FUNC void func_8042DEF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042DEF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042DEF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042DEFC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8042DF00: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8042DF04: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8042DF08: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8042DF0C: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8042DF10: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8042DF14: bnel        $t9, $zero, L_8042DF28
    if (ctx->r25 != 0) {
        // 0x8042DF18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042DF28;
    }
    goto skip_0;
    // 0x8042DF18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042DF1C: jal         0x80064E84
    // 0x8042DF20: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8042DF20: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x8042DF24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042DF28:
    // 0x8042DF28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042DF2C: jr          $ra
    // 0x8042DF30: nop

    return;
    // 0x8042DF30: nop

;}
RECOMP_FUNC void func_80471FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471FB8: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80471FBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80471FC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80471FC4: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80471FC8: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80471FCC: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80471FD0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80471FD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80471FD8: jal         0x8004921C
    // 0x80471FDC: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80471FDC: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80471FE0: sh          $v0, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r2;
    // 0x80471FE4: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x80471FE8: jal         0x8004921C
    // 0x80471FEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80471FEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80471FF0: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x80471FF4: sra         $v1, $v0, 1
    ctx->r3 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80471FF8: sh          $v1, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r3;
    // 0x80471FFC: lw          $t8, 0x16C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X16C);
    // 0x80472000: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80472004: lw          $a3, -0x260C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X260C);
    // 0x80472008: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8047200C: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x80472010: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80472014: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x80472018: lw          $t6, 0x1F4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X1F4);
    // 0x8047201C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80472020: sw          $t6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r14;
    // 0x80472024: lw          $s0, 0xC($a3)
    ctx->r16 = MEM_W(ctx->r7, 0XC);
    // 0x80472028: addiu       $s0, $s0, -0x80
    ctx->r16 = ADD32(ctx->r16, -0X80);
    // 0x8047202C: sw          $s0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r16;
    // 0x80472030: lw          $t7, 0x168($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X168);
    // 0x80472034: lw          $t8, 0x80($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X80);
    // 0x80472038: jal         0x80077338
    // 0x8047203C: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x8047203C: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
    after_2:
    // 0x80472040: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x80472044: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80472048: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8047204C: jal         0x8007711C
    // 0x80472050: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x80472050: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    after_3:
    // 0x80472054: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80472058: jal         0x80471E20
    // 0x8047205C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80471E20(rdram, ctx);
        goto after_4;
    // 0x8047205C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80472060: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80472064: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80472068: ori         $t7, $t7, 0x207F
    ctx->r15 = ctx->r15 | 0X207F;
    // 0x8047206C: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80472070: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x80472074: sw          $s0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r16;
    // 0x80472078: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8047207C: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80472080: lui         $t6, 0xFD70
    ctx->r14 = S32(0XFD70 << 16);
    // 0x80472084: lui         $ra, 0x700
    ctx->r31 = S32(0X700 << 16);
    // 0x80472088: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8047208C: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x80472090: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80472094: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x80472098: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8047209C: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x804720A0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x804720A4: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x804720A8: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x804720AC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x804720B0: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x804720B4: sw          $ra, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r31;
    // 0x804720B8: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x804720BC: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x804720C0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x804720C4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x804720C8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x804720CC: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x804720D0: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x804720D4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x804720D8: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x804720DC: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
    // 0x804720E0: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x804720E4: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x804720E8: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x804720EC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x804720F0: lh          $t9, 0x98($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X98);
    // 0x804720F4: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x804720F8: addiu       $t4, $t2, 0x7
    ctx->r12 = ADD32(ctx->r10, 0X7);
    // 0x804720FC: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80472100: sra         $t4, $t4, 3
    ctx->r12 = S32(SIGNED(ctx->r12) >> 3);
    // 0x80472104: andi        $t4, $t4, 0x1FF
    ctx->r12 = ctx->r12 & 0X1FF;
    // 0x80472108: mflo        $t0
    ctx->r8 = lo;
    // 0x8047210C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80472110: sra         $t0, $t0, 1
    ctx->r8 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80472114: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80472118: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8047211C: beq         $at, $zero, L_8047212C
    if (ctx->r1 == 0) {
        // 0x80472120: nop
    
            goto L_8047212C;
    }
    // 0x80472120: nop

    // 0x80472124: b           L_8047212C
    // 0x80472128: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
        goto L_8047212C;
    // 0x80472128: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_8047212C:
    // 0x8047212C: bgez        $t2, L_8047213C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80472130: sra         $a1, $t2, 3
        ctx->r5 = S32(SIGNED(ctx->r10) >> 3);
            goto L_8047213C;
    }
    // 0x80472130: sra         $a1, $t2, 3
    ctx->r5 = S32(SIGNED(ctx->r10) >> 3);
    // 0x80472134: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
    // 0x80472138: sra         $a1, $at, 3
    ctx->r5 = S32(SIGNED(ctx->r1) >> 3);
L_8047213C:
    // 0x8047213C: bgtz        $a1, L_8047214C
    if (SIGNED(ctx->r5) > 0) {
        // 0x80472140: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8047214C;
    }
    // 0x80472140: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80472144: b           L_8047214C
    // 0x80472148: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8047214C;
    // 0x80472148: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8047214C:
    // 0x8047214C: bgtz        $a1, L_8047215C
    if (SIGNED(ctx->r5) > 0) {
        // 0x80472150: addiu       $t6, $a2, 0x7FF
        ctx->r14 = ADD32(ctx->r6, 0X7FF);
            goto L_8047215C;
    }
    // 0x80472150: addiu       $t6, $a2, 0x7FF
    ctx->r14 = ADD32(ctx->r6, 0X7FF);
    // 0x80472154: b           L_80472160
    // 0x80472158: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80472160;
    // 0x80472158: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8047215C:
    // 0x8047215C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
L_80472160:
    // 0x80472160: div         $zero, $t6, $s0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r16)));
    // 0x80472164: mflo        $t7
    ctx->r15 = lo;
    // 0x80472168: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8047216C: bne         $s0, $zero, L_80472178
    if (ctx->r16 != 0) {
        // 0x80472170: nop
    
            goto L_80472178;
    }
    // 0x80472170: nop

    // 0x80472174: break       7
    do_break(2152145268);
L_80472178:
    // 0x80472178: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8047217C: bne         $s0, $at, L_80472190
    if (ctx->r16 != ctx->r1) {
        // 0x80472180: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80472190;
    }
    // 0x80472180: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80472184: bne         $t6, $at, L_80472190
    if (ctx->r14 != ctx->r1) {
        // 0x80472188: nop
    
            goto L_80472190;
    }
    // 0x80472188: nop

    // 0x8047218C: break       6
    do_break(2152145292);
L_80472190:
    // 0x80472190: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x80472194: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80472198: or          $t9, $t8, $ra
    ctx->r25 = ctx->r24 | ctx->r31;
    // 0x8047219C: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x804721A0: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x804721A4: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x804721A8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x804721AC: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x804721B0: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x804721B4: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x804721B8: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x804721BC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x804721C0: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x804721C4: sll         $t4, $t4, 9
    ctx->r12 = S32(ctx->r12 << 9);
    // 0x804721C8: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
    // 0x804721CC: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x804721D0: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x804721D4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x804721D8: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x804721DC: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x804721E0: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x804721E4: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x804721E8: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x804721EC: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x804721F0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x804721F4: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x804721F8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x804721FC: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x80472200: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x80472204: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80472208: lh          $t9, 0x98($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X98);
    // 0x8047220C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80472210: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80472214: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x80472218: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8047221C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80472220: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x80472224: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x80472228: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8047222C: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(158, 0X1970) << 16);
    // 0x80472230: addiu       $t6, $t6, 0x2E30
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(158, 0X1970));
    // 0x80472234: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80472238: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x8047223C: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80472240: sw          $t3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r11;
    // 0x80472244: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80472248: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8047224C: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x80472250: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80472254: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x80472258: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8047225C: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x80472260: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80472264: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x80472268: addiu       $t9, $t6, 0x800
    ctx->r25 = ADD32(ctx->r14, 0X800);
    // 0x8047226C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80472270: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80472274: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x80472278: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8047227C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80472280: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x80472284: sw          $ra, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r31;
    // 0x80472288: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8047228C: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80472290: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80472294: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80472298: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8047229C: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x804722A0: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x804722A4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x804722A8: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x804722AC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x804722B0: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x804722B4: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x804722B8: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x804722BC: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x804722C0: beq         $at, $zero, L_804722D0
    if (ctx->r1 == 0) {
        // 0x804722C4: or          $t2, $t6, $zero
        ctx->r10 = ctx->r14 | 0;
            goto L_804722D0;
    }
    // 0x804722C4: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x804722C8: b           L_804722D0
    // 0x804722CC: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
        goto L_804722D0;
    // 0x804722CC: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_804722D0:
    // 0x804722D0: bgtz        $a1, L_804722E0
    if (SIGNED(ctx->r5) > 0) {
        // 0x804722D4: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_804722E0;
    }
    // 0x804722D4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x804722D8: b           L_804722E0
    // 0x804722DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_804722E0;
    // 0x804722DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_804722E0:
    // 0x804722E0: bgtz        $a1, L_804722F0
    if (SIGNED(ctx->r5) > 0) {
        // 0x804722E4: addiu       $t8, $a2, 0x7FF
        ctx->r24 = ADD32(ctx->r6, 0X7FF);
            goto L_804722F0;
    }
    // 0x804722E4: addiu       $t8, $a2, 0x7FF
    ctx->r24 = ADD32(ctx->r6, 0X7FF);
    // 0x804722E8: b           L_804722F0
    // 0x804722EC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_804722F0;
    // 0x804722EC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_804722F0:
    // 0x804722F0: div         $zero, $t8, $s0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r16)));
    // 0x804722F4: mflo        $t6
    ctx->r14 = lo;
    // 0x804722F8: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x804722FC: bne         $s0, $zero, L_80472308
    if (ctx->r16 != 0) {
        // 0x80472300: nop
    
            goto L_80472308;
    }
    // 0x80472300: nop

    // 0x80472304: break       7
    do_break(2152145668);
L_80472308:
    // 0x80472308: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8047230C: bne         $s0, $at, L_80472320
    if (ctx->r16 != ctx->r1) {
        // 0x80472310: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80472320;
    }
    // 0x80472310: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80472314: bne         $t8, $at, L_80472320
    if (ctx->r24 != ctx->r1) {
        // 0x80472318: nop
    
            goto L_80472320;
    }
    // 0x80472318: nop

    // 0x8047231C: break       6
    do_break(2152145692);
L_80472320:
    // 0x80472320: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x80472324: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80472328: or          $t7, $t9, $ra
    ctx->r15 = ctx->r25 | ctx->r31;
    // 0x8047232C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80472330: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80472334: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80472338: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8047233C: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x80472340: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x80472344: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80472348: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8047234C: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80472350: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80472354: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x80472358: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x8047235C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80472360: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x80472364: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80472368: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8047236C: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80472370: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x80472374: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x80472378: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8047237C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80472380: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80472384: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80472388: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(158, 0X1988) << 16);
    // 0x8047238C: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x80472390: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x80472394: addiu       $t6, $t6, 0x2E48
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(158, 0X1988));
    // 0x80472398: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8047239C: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x804723A0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x804723A4: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x804723A8: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x804723AC: sw          $t9, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r25;
    // 0x804723B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804723B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804723B8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x804723BC: jr          $ra
    // 0x804723C0: nop

    return;
    // 0x804723C0: nop

;}
RECOMP_FUNC void func_8051F740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051F740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051F744: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051F748: jal         0x80064E84
    // 0x8051F74C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8051F74C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8051F750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051F754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051F758: jr          $ra
    // 0x8051F75C: nop

    return;
    // 0x8051F75C: nop

;}
RECOMP_FUNC void func_805808E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805808E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805808E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805808EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805808F0: jal         0x80045A34
    // 0x805808F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805808F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x805808F8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x805808FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80580900: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80580904: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80580908: jal         0x800657CC
    // 0x8058090C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x8058090C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    after_1:
    // 0x80580910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80580914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80580918: jr          $ra
    // 0x8058091C: nop

    return;
    // 0x8058091C: nop

;}
RECOMP_FUNC void func_805CFF70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CFF70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CFF74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805CFF78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CFF7C: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(462, 0X3F0) << 16);
    // 0x805CFF80: lui         $a1, 0x805D
    ctx->r5 = S32(RELOC_HI16(462, 0X400) << 16);
    // 0x805CFF84: addiu       $a1, $a1, 0x370
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(462, 0X400));
    // 0x805CFF88: addiu       $a0, $a0, 0x360
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(462, 0X3F0));
    // 0x805CFF8C: jal         0x8004667C
    // 0x805CFF90: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x805CFF90: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_0:
    // 0x805CFF94: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x805CFF98: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x805CFF9C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x805CFFA0: lui         $a2, 0x805D
    ctx->r6 = S32(RELOC_HI16(462, 0X1E4) << 16);
    // 0x805CFFA4: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x805CFFA8: lw          $t7, 0x4C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4C);
    // 0x805CFFAC: bnel        $t7, $zero, L_805CFFC0
    if (ctx->r15 != 0) {
        // 0x805CFFB0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805CFFC0;
    }
    goto skip_0;
    // 0x805CFFB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805CFFB4: jal         0x80057B28
    // 0x805CFFB8: addiu       $a2, $a2, 0x154
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(462, 0X1E4));
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x805CFFB8: addiu       $a2, $a2, 0x154
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(462, 0X1E4));
    after_1:
    // 0x805CFFBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805CFFC0:
    // 0x805CFFC0: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(462, 0X11C) << 16);
    // 0x805CFFC4: addiu       $v0, $v0, 0x8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(462, 0X11C));
    // 0x805CFFC8: jr          $ra
    // 0x805CFFCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805CFFCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805AC884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC884: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805AC888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AC88C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AC890: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805AC894: jal         0x800692D4
    // 0x805AC898: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_800692D4(rdram, ctx);
        goto after_0;
    // 0x805AC898: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x805AC89C: beq         $v0, $zero, L_805AC8E0
    if (ctx->r2 == 0) {
        // 0x805AC8A0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_805AC8E0;
    }
    // 0x805AC8A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805AC8A4: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x805AC8A8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x805AC8AC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x805AC8B0: beq         $v1, $at, L_805AC8E0
    if (ctx->r3 == ctx->r1) {
        // 0x805AC8B4: addiu       $v0, $a0, 0xC4
        ctx->r2 = ADD32(ctx->r4, 0XC4);
            goto L_805AC8E0;
    }
    // 0x805AC8B4: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x805AC8B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805AC8BC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x805AC8C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805AC8C4: sb          $v1, 0x20($t7)
    MEM_B(0X20, ctx->r15) = ctx->r3;
    // 0x805AC8C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AC8CC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x805AC8D0: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x805AC8D4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x805AC8D8: jal         0x805AD274
    // 0x805AC8DC: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    func_805AD274(rdram, ctx);
        goto after_1;
    // 0x805AC8DC: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    after_1:
L_805AC8E0:
    // 0x805AC8E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AC8E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805AC8E8: jr          $ra
    // 0x805AC8EC: nop

    return;
    // 0x805AC8EC: nop

;}
RECOMP_FUNC void func_80051E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051E84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80051E88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051E8C: jal         0x80051D20
    // 0x80051E90: nop

    func_80051D20(rdram, ctx);
        goto after_0;
    // 0x80051E90: nop

    after_0:
    // 0x80051E94: addiu       $t6, $zero, 0x7FFF
    ctx->r14 = ADD32(0, 0X7FFF);
    // 0x80051E98: sh          $t6, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r14;
    // 0x80051E9C: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x80051EA0: ori         $a0, $a0, 0xEC00
    ctx->r4 = ctx->r4 | 0XEC00;
    // 0x80051EA4: jal         0x80064DD0
    // 0x80051EA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80064DD0(rdram, ctx);
        goto after_1;
    // 0x80051EA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80051EAC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80051EB0: sw          $v0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r2;
    // 0x80051EB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051EB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80051EBC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80051EC0: jr          $ra
    // 0x80051EC4: nop

    return;
    // 0x80051EC4: nop

;}
RECOMP_FUNC void func_806F98AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F98AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F98B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F98B4: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x806F98B8: jal         0x806F9894
    // 0x806F98BC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_806F9894(rdram, ctx);
        goto after_0;
    // 0x806F98BC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x806F98C0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806F98C4: addiu       $t6, $zero, 0x112
    ctx->r14 = ADD32(0, 0X112);
    // 0x806F98C8: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x806F98CC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x806F98D0: addiu       $t8, $t8, -0x6030
    ctx->r24 = ADD32(ctx->r24, -0X6030);
    // 0x806F98D4: sh          $t6, 0x4C($t7)
    MEM_H(0X4C, ctx->r15) = ctx->r14;
    // 0x806F98D8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x806F98DC: sw          $t8, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->r24;
    // 0x806F98E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F98E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F98E8: jr          $ra
    // 0x806F98EC: nop

    return;
    // 0x806F98EC: nop

;}
RECOMP_FUNC void func_804A3BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A3BA0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x804A3BA4: lw          $a0, 0x7EA8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EA8);
    // 0x804A3BA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x804A3BAC: lb          $v0, 0x3($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3);
    // 0x804A3BB0: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x804A3BB4: bne         $at, $zero, L_804A3BC4
    if (ctx->r1 != 0) {
        // 0x804A3BB8: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_804A3BC4;
    }
    // 0x804A3BB8: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x804A3BBC: bnel        $at, $zero, L_804A3BD8
    if (ctx->r1 != 0) {
        // 0x804A3BC0: lb          $v0, 0x2($a0)
        ctx->r2 = MEM_B(ctx->r4, 0X2);
            goto L_804A3BD8;
    }
    goto skip_0;
    // 0x804A3BC0: lb          $v0, 0x2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X2);
    skip_0:
L_804A3BC4:
    // 0x804A3BC4: blez        $v0, L_804A3BD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x804A3BC8: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_804A3BD4;
    }
    // 0x804A3BC8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x804A3BCC: b           L_804A3BD4
    // 0x804A3BD0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_804A3BD4;
    // 0x804A3BD0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_804A3BD4:
    // 0x804A3BD4: lb          $v0, 0x2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X2);
L_804A3BD8:
    // 0x804A3BD8: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x804A3BDC: bne         $at, $zero, L_804A3BEC
    if (ctx->r1 != 0) {
        // 0x804A3BE0: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_804A3BEC;
    }
    // 0x804A3BE0: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x804A3BE4: bne         $at, $zero, L_804A3C00
    if (ctx->r1 != 0) {
        // 0x804A3BE8: nop
    
            goto L_804A3C00;
    }
    // 0x804A3BE8: nop

L_804A3BEC:
    // 0x804A3BEC: bgezl       $v0, L_804A3C00
    if (SIGNED(ctx->r2) >= 0) {
        // 0x804A3BF0: ori         $v1, $v1, 0x8
        ctx->r3 = ctx->r3 | 0X8;
            goto L_804A3C00;
    }
    goto skip_1;
    // 0x804A3BF0: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
    skip_1:
    // 0x804A3BF4: jr          $ra
    // 0x804A3BF8: ori         $v0, $v1, 0x4
    ctx->r2 = ctx->r3 | 0X4;
    return;
    // 0x804A3BF8: ori         $v0, $v1, 0x4
    ctx->r2 = ctx->r3 | 0X4;
    // 0x804A3BFC: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
L_804A3C00:
    // 0x804A3C00: jr          $ra
    // 0x804A3C04: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x804A3C04: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8049EC3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049EC3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8049EC40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8049EC44: jal         0x8004700C
    // 0x8049EC48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8049EC48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8049EC4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8049EC50: beq         $v0, $zero, L_8049ECDC
    if (ctx->r2 == 0) {
        // 0x8049EC54: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_8049ECDC;
    }
    // 0x8049EC54: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8049EC58: lhu         $t7, 0x8($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X8);
    // 0x8049EC5C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8049EC60: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8049EC64: beql        $t8, $zero, L_8049EC88
    if (ctx->r24 == 0) {
        // 0x8049EC68: lwc1        $f16, 0x10($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
            goto L_8049EC88;
    }
    goto skip_0;
    // 0x8049EC68: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    skip_0:
    // 0x8049EC6C: lwc1        $f4, 0x88($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8049EC70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8049EC74: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8049EC78: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8049EC7C: b           L_8049EC90
    // 0x8049EC80: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
        goto L_8049EC90;
    // 0x8049EC80: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8049EC84: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
L_8049EC88:
    // 0x8049EC88: lwc1        $f18, 0x88($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8049EC8C: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
L_8049EC90:
    // 0x8049EC90: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X12B0) << 16);
    // 0x8049EC94: lwc1        $f12, -0x1D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(167, 0X12B0));
    // 0x8049EC98: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X12B4) << 16);
    // 0x8049EC9C: lwc1        $f4, -0x1CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(167, 0X12B4));
    // 0x8049ECA0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8049ECA4: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X12B8) << 16);
    // 0x8049ECA8: mul.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8049ECAC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8049ECB0: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x8049ECB4: bc1f        L_8049ECC0
    if (!c1cs) {
        // 0x8049ECB8: nop
    
            goto L_8049ECC0;
    }
    // 0x8049ECB8: nop

    // 0x8049ECBC: swc1        $f12, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f12.u32l;
L_8049ECC0:
    // 0x8049ECC0: lwc1        $f0, -0x1C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(167, 0X12B8));
    // 0x8049ECC4: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8049ECC8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8049ECCC: nop

    // 0x8049ECD0: bc1fl       L_8049ECE0
    if (!c1cs) {
        // 0x8049ECD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8049ECE0;
    }
    goto skip_1;
    // 0x8049ECD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8049ECD8: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
L_8049ECDC:
    // 0x8049ECDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8049ECE0:
    // 0x8049ECE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8049ECE4: jr          $ra
    // 0x8049ECE8: nop

    return;
    // 0x8049ECE8: nop

;}
RECOMP_FUNC void func_80075710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075710: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80075714: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80075718: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8007571C: lui         $t0, 0x800B
    ctx->r8 = S32(0X800B << 16);
    // 0x80075720: addiu       $t0, $t0, -0x7AD4
    ctx->r8 = ADD32(ctx->r8, -0X7AD4);
    // 0x80075724: addiu       $s0, $s0, -0x260C
    ctx->r16 = ADD32(ctx->r16, -0X260C);
    // 0x80075728: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007572C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80075730: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80075734: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80075738: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007573C: ori         $at, $at, 0x9B78
    ctx->r1 = ctx->r1 | 0X9B78;
    // 0x80075740: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80075744: multu       $t7, $at
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80075748: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8007574C: addiu       $t1, $t1, 0x40C0
    ctx->r9 = ADD32(ctx->r9, 0X40C0);
    // 0x80075750: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80075754: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x80075758: addiu       $s1, $s1, -0x53C0
    ctx->r17 = ADD32(ctx->r17, -0X53C0);
    // 0x8007575C: mflo        $t9
    ctx->r25 = lo;
    // 0x80075760: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x80075764: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80075768: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8007576C: beql        $t3, $zero, L_800757D8
    if (ctx->r11 == 0) {
        // 0x80075770: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_800757D8;
    }
    goto skip_0;
    // 0x80075770: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_0:
    // 0x80075774: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_80075778:
    // 0x80075778: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8007577C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80075780: jal         0x80082C88
    // 0x80075784: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_0;
    // 0x80075784: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_0:
    // 0x80075788: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8007578C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80075790: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80075794: jal         0x80082D88
    // 0x80075798: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80075798: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_1:
    // 0x8007579C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800757A0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800757A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800757A8: jal         0x80082C88
    // 0x800757AC: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ull_div_recomp(rdram, ctx);
        goto after_2;
    // 0x800757AC: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_2:
    // 0x800757B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800757B4: jal         0x800821A0
    // 0x800757B8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    csleep(rdram, ctx);
        goto after_3;
    // 0x800757B8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_3:
    // 0x800757BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800757C0: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800757C4: bnel        $t4, $zero, L_80075778
    if (ctx->r12 != 0) {
        // 0x800757C8: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_80075778;
    }
    goto skip_1;
    // 0x800757C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x800757CC: lui         $t0, 0x800B
    ctx->r8 = S32(0X800B << 16);
    // 0x800757D0: addiu       $t0, $t0, -0x7AD4
    ctx->r8 = ADD32(ctx->r8, -0X7AD4);
    // 0x800757D4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_800757D8:
    // 0x800757D8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800757DC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800757E0: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800757E4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800757E8: ori         $at, $at, 0x9998
    ctx->r1 = ctx->r1 | 0X9998;
    // 0x800757EC: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800757F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800757F4: addiu       $t8, $v0, 0x1E0
    ctx->r24 = ADD32(ctx->r2, 0X1E0);
    // 0x800757F8: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x800757FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80075800: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80075804: addu        $t1, $t9, $at
    ctx->r9 = ADD32(ctx->r25, ctx->r1);
    // 0x80075808: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x8007580C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80075810: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80075814: lw          $v1, 0x8($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X8);
    // 0x80075818: sw          $v1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r3;
    // 0x8007581C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80075820: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80075824: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80075828: jr          $ra
    // 0x8007582C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8007582C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8004A028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004A02C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004A030: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004A034: beql        $v0, $zero, L_8004A058
    if (ctx->r2 == 0) {
        // 0x8004A038: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004A058;
    }
    goto skip_0;
    // 0x8004A038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004A03C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004A040: lw          $v1, 0x44($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X44);
    // 0x8004A044: beql        $v1, $zero, L_8004A058
    if (ctx->r3 == 0) {
        // 0x8004A048: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004A058;
    }
    goto skip_1;
    // 0x8004A048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004A04C: jalr        $v1
    // 0x8004A050: nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8004A050: nop

    after_0:
    // 0x8004A054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004A058:
    // 0x8004A058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004A05C: jr          $ra
    // 0x8004A060: nop

    return;
    // 0x8004A060: nop

;}
RECOMP_FUNC void func_8042ED30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042ED30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042ED34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042ED38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042ED3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8042ED40: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8042ED44: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8042ED48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042ED4C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8042ED50: beq         $v0, $at, L_8042ED6C
    if (ctx->r2 == ctx->r1) {
        // 0x8042ED54: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8042ED6C;
    }
    // 0x8042ED54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8042ED58: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8042ED5C: beq         $v0, $at, L_8042EDC8
    if (ctx->r2 == ctx->r1) {
        // 0x8042ED60: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_8042EDC8;
    }
    // 0x8042ED60: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8042ED64: b           L_8042EDF8
    // 0x8042ED68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8042EDF8;
    // 0x8042ED68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042ED6C:
    // 0x8042ED6C: jal         0x80062AEC
    // 0x8042ED70: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x8042ED70: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x8042ED74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8042ED78: beq         $v0, $at, L_8042ED98
    if (ctx->r2 == ctx->r1) {
        // 0x8042ED7C: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8042ED98;
    }
    // 0x8042ED7C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8042ED80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8042ED84: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8042ED88: jal         0x8002F6E4
    // 0x8042ED8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x8042ED8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8042ED90: b           L_8042EDF8
    // 0x8042ED94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8042EDF8;
    // 0x8042ED94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042ED98:
    // 0x8042ED98: jal         0x8002FABC
    // 0x8042ED9C: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    func_8002FABC(rdram, ctx);
        goto after_2;
    // 0x8042ED9C: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    after_2:
    // 0x8042EDA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042EDA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042EDA8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8042EDAC: jal         0x8042EFF4
    // 0x8042EDB0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8042EFF4(rdram, ctx);
        goto after_3;
    // 0x8042EDB0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_3:
    // 0x8042EDB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042EDB8: jal         0x8042E220
    // 0x8042EDBC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8042E220(rdram, ctx);
        goto after_4;
    // 0x8042EDBC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x8042EDC0: b           L_8042EDF8
    // 0x8042EDC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8042EDF8;
    // 0x8042EDC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042EDC8:
    // 0x8042EDC8: lbu         $t8, 0x18($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X18);
    // 0x8042EDCC: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8042EDD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042EDD4: bne         $t8, $at, L_8042EDF4
    if (ctx->r24 != ctx->r1) {
        // 0x8042EDD8: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8042EDF4;
    }
    // 0x8042EDD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042EDDC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8042EDE0: jal         0x8042EFF4
    // 0x8042EDE4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8042EFF4(rdram, ctx);
        goto after_5;
    // 0x8042EDE4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
    // 0x8042EDE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042EDEC: jal         0x8042E220
    // 0x8042EDF0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8042E220(rdram, ctx);
        goto after_6;
    // 0x8042EDF0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
L_8042EDF4:
    // 0x8042EDF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042EDF8:
    // 0x8042EDF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042EDFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042EE00: jr          $ra
    // 0x8042EE04: nop

    return;
    // 0x8042EE04: nop

;}
RECOMP_FUNC void func_8004ED70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004ED70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004ED74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004ED78: jal         0x80064DD0
    // 0x8004ED7C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x8004ED7C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_0:
    // 0x8004ED80: bne         $v0, $zero, L_8004EDA0
    if (ctx->r2 != 0) {
        // 0x8004ED84: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8004EDA0;
    }
    // 0x8004ED84: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8004ED88: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004ED8C: addiu       $a0, $a0, 0x900
    ctx->r4 = ADD32(ctx->r4, 0X900);
    // 0x8004ED90: jal         0x80071380
    // 0x8004ED94: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8004ED94: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_1:
    // 0x8004ED98: b           L_8004EDA4
    // 0x8004ED9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004EDA4;
    // 0x8004ED9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004EDA0:
    // 0x8004EDA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8004EDA4:
    // 0x8004EDA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004EDA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004EDAC: jr          $ra
    // 0x8004EDB0: nop

    return;
    // 0x8004EDB0: nop

;}
RECOMP_FUNC void func_8044D5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044D5F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8044D5F8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8044D5FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044D600: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8044D604: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8044D608: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x8044D60C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8044D610: sll         $t0, $a3, 2
    ctx->r8 = S32(ctx->r7 << 2);
    // 0x8044D614: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8044D618: lw          $v0, 0x6980($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6980);
    // 0x8044D61C: addu        $t7, $v0, $t0
    ctx->r15 = ADD32(ctx->r2, ctx->r8);
    // 0x8044D620: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8044D624: addu        $t7, $v1, $t0
    ctx->r15 = ADD32(ctx->r3, ctx->r8);
    // 0x8044D628: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8044D62C: beq         $t9, $zero, L_8044D670
    if (ctx->r25 == 0) {
        // 0x8044D630: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_8044D670;
    }
    // 0x8044D630: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8044D634: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8044D638: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8044D63C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8044D640: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x8044D644: addu        $a1, $t4, $a1
    ctx->r5 = ADD32(ctx->r12, ctx->r5);
    // 0x8044D648: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8044D64C: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8044D650: jal         0x8044D1F4
    // 0x8044D654: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8044D1F4(rdram, ctx);
        goto after_0;
    // 0x8044D654: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x8044D658: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8044D65C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8044D660: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8044D664: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x8044D668: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8044D66C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8044D670:
    // 0x8044D670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8044D674: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8044D678: jr          $ra
    // 0x8044D67C: nop

    return;
    // 0x8044D67C: nop

;}
RECOMP_FUNC void func_80065728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065728: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006572C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065730: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065734: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80065738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006573C: jal         0x800656BC
    // 0x80065740: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800656BC(rdram, ctx);
        goto after_0;
    // 0x80065740: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80065744: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80065748: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8006574C: bne         $v0, $zero, L_8006576C
    if (ctx->r2 != 0) {
        // 0x80065750: lh          $t0, 0x2A($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X2A);
            goto L_8006576C;
    }
    // 0x80065750: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x80065754: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80065758: addiu       $a0, $a0, 0xDC4
    ctx->r4 = ADD32(ctx->r4, 0XDC4);
    // 0x8006575C: jal         0x80071380
    // 0x80065760: addiu       $a1, $zero, 0x247
    ctx->r5 = ADD32(0, 0X247);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80065760: addiu       $a1, $zero, 0x247
    ctx->r5 = ADD32(0, 0X247);
    after_1:
    // 0x80065764: b           L_800657C0
    // 0x80065768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800657C0;
    // 0x80065768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006576C:
    // 0x8006576C: srl         $a3, $a3, 1
    ctx->r7 = S32(U32(ctx->r7) >> 1);
    // 0x80065770: beq         $a3, $zero, L_800657BC
    if (ctx->r7 == 0) {
        // 0x80065774: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800657BC;
    }
    // 0x80065774: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065778: andi        $a2, $a3, 0x3
    ctx->r6 = ctx->r7 & 0X3;
    // 0x8006577C: beq         $a2, $zero, L_8006579C
    if (ctx->r6 == 0) {
        // 0x80065780: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8006579C;
    }
    // 0x80065780: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80065784: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80065788:
    // 0x80065788: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006578C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80065790: bne         $a1, $a0, L_80065788
    if (ctx->r5 != ctx->r4) {
        // 0x80065794: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80065788;
    }
    // 0x80065794: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80065798: beq         $a0, $a3, L_800657BC
    if (ctx->r4 == ctx->r7) {
        // 0x8006579C: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_800657BC;
    }
L_8006579C:
    // 0x8006579C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800657A0:
    // 0x800657A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800657A4: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x800657A8: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x800657AC: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    // 0x800657B0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800657B4: bne         $a0, $a3, L_800657A0
    if (ctx->r4 != ctx->r7) {
        // 0x800657B8: sh          $v0, -0x8($v1)
        MEM_H(-0X8, ctx->r3) = ctx->r2;
            goto L_800657A0;
    }
    // 0x800657B8: sh          $v0, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r2;
L_800657BC:
    // 0x800657BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800657C0:
    // 0x800657C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800657C4: jr          $ra
    // 0x800657C8: nop

    return;
    // 0x800657C8: nop

;}
RECOMP_FUNC void func_80670344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80670344: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80670348: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067034C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80670350: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80670354: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80670358: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8067035C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80670360: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80670364: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80670368: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8067036C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80670370: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80670374: jal         0x80065954
    // 0x80670378: nop

    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80670378: nop

    after_0:
    // 0x8067037C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80670380: lh          $t7, 0x1F0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1F0);
    // 0x80670384: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80670388: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8067038C: bnel        $t7, $at, L_806703B8
    if (ctx->r15 != ctx->r1) {
        // 0x80670390: lw          $a1, 0x34($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X34);
            goto L_806703B8;
    }
    goto skip_0;
    // 0x80670390: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x80670394: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80670398: jal         0x80067D5C
    // 0x8067039C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_1;
    // 0x8067039C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x806703A0: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x806703A4: jal         0x80067F78
    // 0x806703A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_2;
    // 0x806703A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x806703AC: b           L_806703D0
    // 0x806703B0: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_806703D0;
    // 0x806703B0: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x806703B4: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
L_806703B8:
    // 0x806703B8: jal         0x80067D5C
    // 0x806703BC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_3;
    // 0x806703BC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x806703C0: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x806703C4: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x806703C8: jal         0x800678F0
    // 0x806703CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x806703CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
L_806703D0:
    // 0x806703D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806703D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806703D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806703DC: jr          $ra
    // 0x806703E0: nop

    return;
    // 0x806703E0: nop

;}
RECOMP_FUNC void func_80421DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421DA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80421DA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80421DA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80421DAC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80421DB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80421DB4: jal         0x80421C00
    // 0x80421DB8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80421C00(rdram, ctx);
        goto after_0;
    // 0x80421DB8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80421DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80421DC0: jal         0x80421C70
    // 0x80421DC4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80421C70(rdram, ctx);
        goto after_1;
    // 0x80421DC4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80421DC8: bnel        $v0, $zero, L_80421E80
    if (ctx->r2 != 0) {
        // 0x80421DCC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80421E80;
    }
    goto skip_0;
    // 0x80421DCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80421DD0: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x80421DD4: jal         0x80421A34
    // 0x80421DD8: addiu       $a0, $a0, 0x884
    ctx->r4 = ADD32(ctx->r4, 0X884);
    func_80421A34(rdram, ctx);
        goto after_2;
    // 0x80421DD8: addiu       $a0, $a0, 0x884
    ctx->r4 = ADD32(ctx->r4, 0X884);
    after_2:
    // 0x80421DDC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80421DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80421DE4: addiu       $a1, $v0, 0x888
    ctx->r5 = ADD32(ctx->r2, 0X888);
    // 0x80421DE8: jal         0x80421AB4
    // 0x80421DEC: lw          $a2, 0x890($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X890);
    func_80421AB4(rdram, ctx);
        goto after_3;
    // 0x80421DEC: lw          $a2, 0x890($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X890);
    after_3:
    // 0x80421DF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80421DF4: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80421DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80421DFC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80421E00: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80421E04: nop

    // 0x80421E08: bc1fl       L_80421E34
    if (!c1cs) {
        // 0x80421E0C: lw          $t0, 0x138($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X138);
            goto L_80421E34;
    }
    goto skip_1;
    // 0x80421E0C: lw          $t0, 0x138($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X138);
    skip_1:
    // 0x80421E10: lw          $t7, 0x138($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X138);
    // 0x80421E14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80421E18: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80421E1C: xori        $a3, $t7, 0x1
    ctx->r7 = ctx->r15 ^ 0X1;
    // 0x80421E20: jal         0x80422558
    // 0x80421E24: sw          $a3, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r7;
    func_80422558(rdram, ctx);
        goto after_4;
    // 0x80421E24: sw          $a3, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r7;
    after_4:
    // 0x80421E28: b           L_80421E74
    // 0x80421E2C: nop

        goto L_80421E74;
    // 0x80421E2C: nop

    // 0x80421E30: lw          $t0, 0x138($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X138);
L_80421E34:
    // 0x80421E34: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(32, 0X1500) << 16);
    // 0x80421E38: lwc1        $f8, 0x88C($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X88C);
    // 0x80421E3C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80421E40: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80421E44: lwc1        $f10, 0x25C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(32, 0X1500));
    // 0x80421E48: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80421E4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80421E50: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80421E54: swc1        $f16, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f16.u32l;
    // 0x80421E58: jal         0x80048F84
    // 0x80421E5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_5;
    // 0x80421E5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_5:
    // 0x80421E60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80421E64: jal         0x80048F84
    // 0x80421E68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_6;
    // 0x80421E68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80421E6C: jal         0x804216FC
    // 0x80421E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804216FC(rdram, ctx);
        goto after_7;
    // 0x80421E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80421E74:
    // 0x80421E74: jal         0x80421A4C
    // 0x80421E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80421A4C(rdram, ctx);
        goto after_8;
    // 0x80421E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80421E7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80421E80:
    // 0x80421E80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80421E84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80421E88: jr          $ra
    // 0x80421E8C: nop

    return;
    // 0x80421E8C: nop

;}
RECOMP_FUNC void func_800389F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800389F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800389F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800389FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80038A00: jal         0x80045A34
    // 0x80038A04: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80038A04: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x80038A08: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80038A0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80038A10: bne         $v0, $zero, L_80038A28
    if (ctx->r2 != 0) {
        // 0x80038A14: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_80038A28;
    }
    // 0x80038A14: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x80038A18: jal         0x800445A4
    // 0x80038A1C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80038A1C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80038A20: b           L_80038A5C
    // 0x80038A24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038A5C;
    // 0x80038A24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038A28:
    // 0x80038A28: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80038A2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80038A30: jal         0x80065728
    // 0x80038A34: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x80038A34: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x80038A38: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80038A3C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80038A40: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80038A44: lw          $t8, 0x16C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X16C);
    // 0x80038A48: addiu       $t7, $t7, -0x1418
    ctx->r15 = ADD32(ctx->r15, -0X1418);
    // 0x80038A4C: sw          $t6, 0x124($a3)
    MEM_W(0X124, ctx->r7) = ctx->r14;
    // 0x80038A50: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80038A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80038A58: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_80038A5C:
    // 0x80038A5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038A60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038A64: jr          $ra
    // 0x80038A68: nop

    return;
    // 0x80038A68: nop

;}
RECOMP_FUNC void func_8078B190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078B190: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8078B194: addiu       $at, $zero, 0x4674
    ctx->r1 = ADD32(0, 0X4674);
    // 0x8078B198: beq         $v0, $at, L_8078B1B0
    if (ctx->r2 == ctx->r1) {
        // 0x8078B19C: addiu       $at, $zero, 0x4675
        ctx->r1 = ADD32(0, 0X4675);
            goto L_8078B1B0;
    }
    // 0x8078B19C: addiu       $at, $zero, 0x4675
    ctx->r1 = ADD32(0, 0X4675);
    // 0x8078B1A0: bne         $v0, $at, L_8078B1BC
    if (ctx->r2 != ctx->r1) {
        // 0x8078B1A4: lui         $v0, 0x8079
        ctx->r2 = S32(RELOC_HI16(796, 0X704) << 16);
            goto L_8078B1BC;
    }
    // 0x8078B1A4: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(796, 0X704) << 16);
    // 0x8078B1A8: jr          $ra
    // 0x8078B1AC: addiu       $v0, $v0, -0x476C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(796, 0X704));
    return;
    // 0x8078B1AC: addiu       $v0, $v0, -0x476C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(796, 0X704));
L_8078B1B0:
    // 0x8078B1B0: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(796, 0X258) << 16);
    // 0x8078B1B4: jr          $ra
    // 0x8078B1B8: addiu       $v0, $v0, -0x4C18
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(796, 0X258));
    return;
    // 0x8078B1B8: addiu       $v0, $v0, -0x4C18
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(796, 0X258));
L_8078B1BC:
    // 0x8078B1BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8078B1C0: jr          $ra
    // 0x8078B1C4: nop

    return;
    // 0x8078B1C4: nop

;}
RECOMP_FUNC void func_8003892C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003892C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038934: jal         0x80021958
    // 0x80038938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80038938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003893C: bne         $v0, $zero, L_8003894C
    if (ctx->r2 != 0) {
        // 0x80038940: nop
    
            goto L_8003894C;
    }
    // 0x80038940: nop

    // 0x80038944: b           L_80038980
    // 0x80038948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038980;
    // 0x80038948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003894C:
    // 0x8003894C: jal         0x80033FB0
    // 0x80038950: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80033FB0(rdram, ctx);
        goto after_1;
    // 0x80038950: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80038954: beq         $v0, $zero, L_80038964
    if (ctx->r2 == 0) {
        // 0x80038958: nop
    
            goto L_80038964;
    }
    // 0x80038958: nop

    // 0x8003895C: b           L_80038980
    // 0x80038960: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038980;
    // 0x80038960: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038964:
    // 0x80038964: jal         0x800388BC
    // 0x80038968: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800388BC(rdram, ctx);
        goto after_2;
    // 0x80038968: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8003896C: bnel        $v0, $zero, L_80038980
    if (ctx->r2 != 0) {
        // 0x80038970: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80038980;
    }
    goto skip_0;
    // 0x80038970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80038974: b           L_80038980
    // 0x80038978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038980;
    // 0x80038978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003897C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80038980:
    // 0x80038980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038984: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038988: jr          $ra
    // 0x8003898C: nop

    return;
    // 0x8003898C: nop

;}
RECOMP_FUNC void func_807C3448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3448: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x807C344C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x807C3450: lui         $a1, 0x807C
    ctx->r5 = S32(RELOC_HI16(907, 0X13B8) << 16);
    // 0x807C3454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C3458: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x807C345C: lw          $a2, -0x720C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X720C);
    // 0x807C3460: addiu       $a1, $a1, 0x4718
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(907, 0X13B8));
    // 0x807C3464: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x807C3468: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807C346C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_807C3470:
    // 0x807C3470: and         $t6, $a2, $v1
    ctx->r14 = ctx->r6 & ctx->r3;
    // 0x807C3474: bne         $t6, $zero, L_807C3494
    if (ctx->r14 != 0) {
        // 0x807C3478: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_807C3494;
    }
    // 0x807C3478: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x807C347C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x807C3480: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x807C3484: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x807C3488: addu        $t1, $a3, $t0
    ctx->r9 = ADD32(ctx->r7, ctx->r8);
    // 0x807C348C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x807C3490: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_807C3494:
    // 0x807C3494: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x807C3498: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x807C349C: bne         $at, $zero, L_807C3470
    if (ctx->r1 != 0) {
        // 0x807C34A0: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_807C3470;
    }
    // 0x807C34A0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x807C34A4: bne         $a0, $zero, L_807C34F0
    if (ctx->r4 != 0) {
        // 0x807C34A8: andi        $t2, $a2, 0x1000
        ctx->r10 = ctx->r6 & 0X1000;
            goto L_807C34F0;
    }
    // 0x807C34A8: andi        $t2, $a2, 0x1000
    ctx->r10 = ctx->r6 & 0X1000;
    // 0x807C34AC: beq         $t2, $zero, L_807C34D0
    if (ctx->r10 == 0) {
        // 0x807C34B0: andi        $t7, $a2, 0x2000
        ctx->r15 = ctx->r6 & 0X2000;
            goto L_807C34D0;
    }
    // 0x807C34B0: andi        $t7, $a2, 0x2000
    ctx->r15 = ctx->r6 & 0X2000;
    // 0x807C34B4: andi        $t3, $a2, 0x40
    ctx->r11 = ctx->r6 & 0X40;
    // 0x807C34B8: bne         $t3, $zero, L_807C34D0
    if (ctx->r11 != 0) {
        // 0x807C34BC: addiu       $t4, $zero, 0x6
        ctx->r12 = ADD32(0, 0X6);
            goto L_807C34D0;
    }
    // 0x807C34BC: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x807C34C0: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x807C34C4: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x807C34C8: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x807C34CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_807C34D0:
    // 0x807C34D0: beq         $t7, $zero, L_807C34F0
    if (ctx->r15 == 0) {
        // 0x807C34D4: andi        $t8, $a2, 0x80
        ctx->r24 = ctx->r6 & 0X80;
            goto L_807C34F0;
    }
    // 0x807C34D4: andi        $t8, $a2, 0x80
    ctx->r24 = ctx->r6 & 0X80;
    // 0x807C34D8: bne         $t8, $zero, L_807C34F0
    if (ctx->r24 != 0) {
        // 0x807C34DC: addiu       $t0, $zero, 0x7
        ctx->r8 = ADD32(0, 0X7);
            goto L_807C34F0;
    }
    // 0x807C34DC: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x807C34E0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x807C34E4: addu        $t1, $a3, $t9
    ctx->r9 = ADD32(ctx->r7, ctx->r25);
    // 0x807C34E8: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x807C34EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_807C34F0:
    // 0x807C34F0: bne         $a0, $zero, L_807C3500
    if (ctx->r4 != 0) {
        // 0x807C34F4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_807C3500;
    }
    // 0x807C34F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807C34F8: b           L_807C3558
    // 0x807C34FC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_807C3558;
    // 0x807C34FC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_807C3500:
    // 0x807C3500: bne         $a0, $at, L_807C3510
    if (ctx->r4 != ctx->r1) {
        // 0x807C3504: nop
    
            goto L_807C3510;
    }
    // 0x807C3504: nop

    // 0x807C3508: b           L_807C3558
    // 0x807C350C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_807C3558;
    // 0x807C350C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_807C3510:
    // 0x807C3510: jal         0x800653D8
    // 0x807C3514: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x807C3514: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x807C3518: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x807C351C: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x807C3520: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x807C3524: mfhi        $t2
    ctx->r10 = hi;
    // 0x807C3528: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x807C352C: addu        $t5, $a3, $t3
    ctx->r13 = ADD32(ctx->r7, ctx->r11);
    // 0x807C3530: bne         $a0, $zero, L_807C353C
    if (ctx->r4 != 0) {
        // 0x807C3534: nop
    
            goto L_807C353C;
    }
    // 0x807C3534: nop

    // 0x807C3538: break       7
    do_break(2155623736);
L_807C353C:
    // 0x807C353C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x807C3540: bne         $a0, $at, L_807C3554
    if (ctx->r4 != ctx->r1) {
        // 0x807C3544: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_807C3554;
    }
    // 0x807C3544: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x807C3548: bne         $v0, $at, L_807C3554
    if (ctx->r2 != ctx->r1) {
        // 0x807C354C: nop
    
            goto L_807C3554;
    }
    // 0x807C354C: nop

    // 0x807C3550: break       6
    do_break(2155623760);
L_807C3554:
    // 0x807C3554: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
L_807C3558:
    // 0x807C3558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C355C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x807C3560: jr          $ra
    // 0x807C3564: nop

    return;
    // 0x807C3564: nop

;}
RECOMP_FUNC void func_804EF328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF328: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804EF32C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804EF330: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804EF334: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804EF338: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804EF33C: jal         0x804EEEDC
    // 0x804EF340: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_804EEEDC(rdram, ctx);
        goto after_0;
    // 0x804EF340: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x804EF344: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x804EF348: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804EF34C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804EF350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804EF354: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x804EF358: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804EF35C: bc1f        L_804EF3D4
    if (!c1cs) {
        // 0x804EF360: nop
    
            goto L_804EF3D4;
    }
    // 0x804EF360: nop

    // 0x804EF364: jal         0x804EF078
    // 0x804EF368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804EF078(rdram, ctx);
        goto after_1;
    // 0x804EF368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804EF36C: jal         0x804EEF38
    // 0x804EF370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804EEF38(rdram, ctx);
        goto after_2;
    // 0x804EF370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804EF374: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x804EF378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804EF37C: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    // 0x804EF380: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x804EF384: beq         $at, $zero, L_804EF3A8
    if (ctx->r1 == 0) {
        // 0x804EF388: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_804EF3A8;
    }
    // 0x804EF388: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x804EF38C: lui         $a3, 0xBBA3
    ctx->r7 = S32(0XBBA3 << 16);
    // 0x804EF390: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x804EF394: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x804EF398: jal         0x804EF0EC
    // 0x804EF39C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_804EF0EC(rdram, ctx);
        goto after_3;
    // 0x804EF39C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_3:
    // 0x804EF3A0: b           L_804EF3F0
    // 0x804EF3A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804EF3F0;
    // 0x804EF3A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804EF3A8:
    // 0x804EF3A8: lui         $at, 0x804F
    ctx->r1 = S32(RELOC_HI16(267, 0X1190) << 16);
    // 0x804EF3AC: lwc1        $f10, -0xE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(267, 0X1190));
    // 0x804EF3B0: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x804EF3B4: lwc1        $f12, 0x3C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804EF3B8: lwc1        $f14, 0x40($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804EF3BC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804EF3C0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x804EF3C4: jal         0x804EFBB4
    // 0x804EF3C8: nop

    func_804EFBB4(rdram, ctx);
        goto after_4;
    // 0x804EF3C8: nop

    after_4:
    // 0x804EF3CC: b           L_804EF3EC
    // 0x804EF3D0: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_804EF3EC;
    // 0x804EF3D0: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_804EF3D4:
    // 0x804EF3D4: jal         0x804EF5A0
    // 0x804EF3D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804EF5A0(rdram, ctx);
        goto after_5;
    // 0x804EF3D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x804EF3DC: jal         0x804EF050
    // 0x804EF3E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804EF050(rdram, ctx);
        goto after_6;
    // 0x804EF3E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804EF3E4: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x804EF3E8: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
L_804EF3EC:
    // 0x804EF3EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804EF3F0:
    // 0x804EF3F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804EF3F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804EF3F8: jr          $ra
    // 0x804EF3FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x804EF3FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8045326C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045326C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453274: jal         0x804531D0
    // 0x80453278: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804531D0(rdram, ctx);
        goto after_0;
    // 0x80453278: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045327C: beql        $v0, $zero, L_80453290
    if (ctx->r2 == 0) {
        // 0x80453280: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80453290;
    }
    goto skip_0;
    // 0x80453280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80453284: jal         0x80452858
    // 0x80453288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80452858(rdram, ctx);
        goto after_1;
    // 0x80453288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8045328C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80453290:
    // 0x80453290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453294: jr          $ra
    // 0x80453298: nop

    return;
    // 0x80453298: nop

;}
RECOMP_FUNC void func_804081EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804081EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804081F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804081F4: jal         0x80408254
    // 0x804081F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80408254(rdram, ctx);
        goto after_0;
    // 0x804081F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804081FC: beq         $v0, $zero, L_8040823C
    if (ctx->r2 == 0) {
        // 0x80408200: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8040823C;
    }
    // 0x80408200: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80408204: jal         0x8040828C
    // 0x80408208: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040828C(rdram, ctx);
        goto after_1;
    // 0x80408208: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8040820C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80408210: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80408214: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80408218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040821C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80408220: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80408224: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x80408228: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8040822C: jal         0x804085E4
    // 0x80408230: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    func_804085E4(rdram, ctx);
        goto after_2;
    // 0x80408230: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    after_2:
    // 0x80408234: b           L_80408248
    // 0x80408238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80408248;
    // 0x80408238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040823C:
    // 0x8040823C: jal         0x800445A4
    // 0x80408240: nop

    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x80408240: nop

    after_3:
    // 0x80408244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80408248:
    // 0x80408248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040824C: jr          $ra
    // 0x80408250: nop

    return;
    // 0x80408250: nop

;}
RECOMP_FUNC void func_8007288C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007288C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80072890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072894: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80072898: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007289C: addiu       $a0, $a0, -0x59C0
    ctx->r4 = ADD32(ctx->r4, -0X59C0);
    // 0x800728A0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800728A4: jal         0x800824B0
    // 0x800728A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800728A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800728AC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800728B0: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800728B4: sw          $t7, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r15;
    // 0x800728B8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800728BC: sw          $t8, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r24;
    // 0x800728C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800728C4: jr          $ra
    // 0x800728C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800728C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_804A4EC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4EC4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804A4EC8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804A4ECC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804A4ED0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804A4ED4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804A4ED8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804A4EDC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A4EE0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804A4EE4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804A4EE8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804A4EEC: jr          $ra
    // 0x804A4EF0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804A4EF0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804C1A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C1A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C1A78: jal         0x804C192C
    // 0x804C1A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C192C(rdram, ctx);
        goto after_0;
    // 0x804C1A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C1A80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C1A84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C1A88: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804C1A8C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x804C1A90: bne         $v0, $zero, L_804C1AA8
    if (ctx->r2 != 0) {
        // 0x804C1A94: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_804C1AA8;
    }
    // 0x804C1A94: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x804C1A98: jal         0x804C1F2C
    // 0x804C1A9C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_804C1F2C(rdram, ctx);
        goto after_1;
    // 0x804C1A9C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x804C1AA0: b           L_804C1AB0
    // 0x804C1AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804C1AB0;
    // 0x804C1AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C1AA8:
    // 0x804C1AA8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x804C1AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C1AB0:
    // 0x804C1AB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C1AB4: jr          $ra
    // 0x804C1AB8: nop

    return;
    // 0x804C1AB8: nop

;}
RECOMP_FUNC void func_80705A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80705A5C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80705A60: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80705A64: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80705A68: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80705A6C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80705A70: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80705A74: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80705A78: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80705A7C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80705A80: lui         $t1, 0x8070
    ctx->r9 = S32(RELOC_HI16(709, 0X37C0) << 16);
    // 0x80705A84: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80705A88: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80705A8C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80705A90: lw          $t1, 0x6C30($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(709, 0X37C0));
    // 0x80705A94: jr          $ra
    // 0x80705A98: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80705A98: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x80705A9C: nop

;}
RECOMP_FUNC void func_800721F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800721F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800721FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80072200: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80072204: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072208: jal         0x8008B920
    // 0x8007220C: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x8007220C: nop

    after_0:
    // 0x80072210: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80072214: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80072218: jal         0x80082A6C
    // 0x8007221C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_1;
    // 0x8007221C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80072220: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072224: addiu       $a1, $a1, -0x5968
    ctx->r5 = ADD32(ctx->r5, -0X5968);
    // 0x80072228: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8007222C: jal         0x80089D70
    // 0x80072230: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80072230: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x80072234: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80072238: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8007223C: sw          $t6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r14;
    // 0x80072240: jal         0x80090710
    // 0x80072244: sw          $t7, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r15;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_3;
    // 0x80072244: sw          $t7, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r15;
    after_3:
    // 0x80072248: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007224C: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80072250: sw          $t8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r24;
    // 0x80072254: addiu       $t9, $t9, -0x4D98
    ctx->r25 = ADD32(ctx->r25, -0X4D98);
    // 0x80072258: sw          $s0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r16;
    // 0x8007225C: jal         0x80082BD4
    // 0x80072260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_4;
    // 0x80072260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80072264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072268: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007226C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80072270: jr          $ra
    // 0x80072274: nop

    return;
    // 0x80072274: nop

;}
RECOMP_FUNC void func_8040B524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B524: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040B528: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040B52C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040B530: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040B534: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8040B538: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8040B53C: jal         0x80048F84
    // 0x8040B540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8040B540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8040B544: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8040B548: jal         0x80048F84
    // 0x8040B54C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8040B54C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8040B550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040B554: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8040B558: jal         0x80047534
    // 0x8040B55C: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    func_80047534(rdram, ctx);
        goto after_2;
    // 0x8040B55C: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    after_2:
    // 0x8040B560: beq         $v0, $zero, L_8040B57C
    if (ctx->r2 == 0) {
        // 0x8040B564: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8040B57C;
    }
    // 0x8040B564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040B568: jal         0x8040B478
    // 0x8040B56C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8040B478(rdram, ctx);
        goto after_3;
    // 0x8040B56C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8040B570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040B574: jal         0x8040B590
    // 0x8040B578: lw          $a1, 0x138($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X138);
    func_8040B590(rdram, ctx);
        goto after_4;
    // 0x8040B578: lw          $a1, 0x138($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X138);
    after_4:
L_8040B57C:
    // 0x8040B57C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8040B580: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040B584: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8040B588: jr          $ra
    // 0x8040B58C: nop

    return;
    // 0x8040B58C: nop

;}
RECOMP_FUNC void func_806FDFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FDFA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FDFA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FDFA8: jal         0x80062D14
    // 0x806FDFAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80062D14(rdram, ctx);
        goto after_0;
    // 0x806FDFAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806FDFB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806FDFB4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FDFB8: lhu         $a1, 0x10($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X10);
    // 0x806FDFBC: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x806FDFC0: beql        $t7, $zero, L_806FE010
    if (ctx->r15 == 0) {
        // 0x806FDFC4: andi        $t4, $a1, 0x2
        ctx->r12 = ctx->r5 & 0X2;
            goto L_806FE010;
    }
    goto skip_0;
    // 0x806FDFC4: andi        $t4, $a1, 0x2
    ctx->r12 = ctx->r5 & 0X2;
    skip_0:
    // 0x806FDFC8: lw          $v1, 0x1E4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E4);
    // 0x806FDFCC: andi        $t9, $a1, 0xFFFE
    ctx->r25 = ctx->r5 & 0XFFFE;
    // 0x806FDFD0: blez        $v1, L_806FDFE8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x806FDFD4: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_806FDFE8;
    }
    // 0x806FDFD4: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x806FDFD8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FDFDC: sw          $t8, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = ctx->r24;
    // 0x806FDFE0: b           L_806FE00C
    // 0x806FDFE4: lhu         $a1, 0x10($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X10);
        goto L_806FE00C;
    // 0x806FDFE4: lhu         $a1, 0x10($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X10);
L_806FDFE8:
    // 0x806FDFE8: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    // 0x806FDFEC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FDFF0: addiu       $t2, $zero, 0x168
    ctx->r10 = ADD32(0, 0X168);
    // 0x806FDFF4: lhu         $t0, 0x10($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X10);
    // 0x806FDFF8: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x806FDFFC: sh          $t1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r9;
    // 0x806FE000: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FE004: sw          $t2, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = ctx->r10;
    // 0x806FE008: lhu         $a1, 0x10($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X10);
L_806FE00C:
    // 0x806FE00C: andi        $t4, $a1, 0x2
    ctx->r12 = ctx->r5 & 0X2;
L_806FE010:
    // 0x806FE010: beql        $t4, $zero, L_806FE038
    if (ctx->r12 == 0) {
        // 0x806FE014: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806FE038;
    }
    goto skip_1;
    // 0x806FE014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806FE018: lw          $v1, 0x1E4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E4);
    // 0x806FE01C: andi        $t6, $a1, 0xFFFD
    ctx->r14 = ctx->r5 & 0XFFFD;
    // 0x806FE020: blez        $v1, L_806FE030
    if (SIGNED(ctx->r3) <= 0) {
        // 0x806FE024: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_806FE030;
    }
    // 0x806FE024: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x806FE028: b           L_806FE034
    // 0x806FE02C: sw          $t5, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = ctx->r13;
        goto L_806FE034;
    // 0x806FE02C: sw          $t5, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = ctx->r13;
L_806FE030:
    // 0x806FE030: sh          $t6, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r14;
L_806FE034:
    // 0x806FE034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806FE038:
    // 0x806FE038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FE03C: jr          $ra
    // 0x806FE040: nop

    return;
    // 0x806FE040: nop

;}
RECOMP_FUNC void func_8045B37C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B37C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045B380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045B384: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8045B388: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8045B38C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8045B390: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8045B394: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8045B398: addiu       $at, $zero, 0x4112
    ctx->r1 = ADD32(0, 0X4112);
    // 0x8045B39C: bnel        $v0, $at, L_8045B3EC
    if (ctx->r2 != ctx->r1) {
        // 0x8045B3A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045B3EC;
    }
    goto skip_0;
    // 0x8045B3A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8045B3A4: jal         0x80052CB8
    // 0x8045B3A8: nop

    func_80052CB8(rdram, ctx);
        goto after_0;
    // 0x8045B3A8: nop

    after_0:
    // 0x8045B3AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8045B3B0: jal         0x80052CB8
    // 0x8045B3B4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80052CB8(rdram, ctx);
        goto after_1;
    // 0x8045B3B4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8045B3B8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8045B3BC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8045B3C0: beql        $v1, $a0, L_8045B3EC
    if (ctx->r3 == ctx->r4) {
        // 0x8045B3C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045B3EC;
    }
    goto skip_1;
    // 0x8045B3C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8045B3C8: beq         $v0, $a0, L_8045B3E8
    if (ctx->r2 == ctx->r4) {
        // 0x8045B3CC: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8045B3E8;
    }
    // 0x8045B3CC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8045B3D0: beq         $at, $zero, L_8045B3E8
    if (ctx->r1 == 0) {
        // 0x8045B3D4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8045B3E8;
    }
    // 0x8045B3D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8045B3D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8045B3DC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8045B3E0: jal         0x8045B0A8
    // 0x8045B3E4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_8045B0A8(rdram, ctx);
        goto after_2;
    // 0x8045B3E4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_2:
L_8045B3E8:
    // 0x8045B3E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045B3EC:
    // 0x8045B3EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8045B3F0: jr          $ra
    // 0x8045B3F4: nop

    return;
    // 0x8045B3F4: nop

;}
RECOMP_FUNC void func_804CE700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE700: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804CE704: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CE708: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CE70C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CE710: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804CE714: jal         0x804CE318
    // 0x804CE718: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_804CE318(rdram, ctx);
        goto after_0;
    // 0x804CE718: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x804CE71C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804CE720: bne         $v0, $at, L_804CE77C
    if (ctx->r2 != ctx->r1) {
        // 0x804CE724: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_804CE77C;
    }
    // 0x804CE724: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x804CE728: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x804CE72C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x804CE730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CE734: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CE738: bne         $a3, $t8, L_804CE774
    if (ctx->r7 != ctx->r24) {
        // 0x804CE73C: nop
    
            goto L_804CE774;
    }
    // 0x804CE73C: nop

    // 0x804CE740: bne         $a3, $zero, L_804CE75C
    if (ctx->r7 != 0) {
        // 0x804CE744: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804CE75C;
    }
    // 0x804CE744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CE748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CE74C: jal         0x804CE798
    // 0x804CE750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804CE798(rdram, ctx);
        goto after_1;
    // 0x804CE750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804CE754: b           L_804CE764
    // 0x804CE758: nop

        goto L_804CE764;
    // 0x804CE758: nop

L_804CE75C:
    // 0x804CE75C: jal         0x804CE798
    // 0x804CE760: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_804CE798(rdram, ctx);
        goto after_2;
    // 0x804CE760: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_804CE764:
    // 0x804CE764: jal         0x804CE834
    // 0x804CE768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CE834(rdram, ctx);
        goto after_3;
    // 0x804CE768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804CE76C: b           L_804CE77C
    // 0x804CE770: nop

        goto L_804CE77C;
    // 0x804CE770: nop

L_804CE774:
    // 0x804CE774: jal         0x804CE99C
    // 0x804CE778: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804CE99C(rdram, ctx);
        goto after_4;
    // 0x804CE778: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
L_804CE77C:
    // 0x804CE77C: jal         0x804CE418
    // 0x804CE780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CE418(rdram, ctx);
        goto after_5;
    // 0x804CE780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804CE784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804CE788: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CE78C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804CE790: jr          $ra
    // 0x804CE794: nop

    return;
    // 0x804CE794: nop

;}
RECOMP_FUNC void func_8000B338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B338: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8000B33C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000B340: lui         $s4, 0x800B
    ctx->r20 = S32(0X800B << 16);
    // 0x8000B344: addiu       $s4, $s4, 0x4D10
    ctx->r20 = ADD32(ctx->r20, 0X4D10);
    // 0x8000B348: lw          $v0, 0x1DAC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X1DAC);
    // 0x8000B34C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8000B350: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000B354: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8000B358: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000B35C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000B360: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000B364: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000B368: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000B36C: blez        $v0, L_8000B7A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000B370: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_8000B7A0;
    }
    // 0x8000B370: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8000B374: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8000B378: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8000B37C: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_8000B380:
    // 0x8000B380: lw          $t7, 0x4F28($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X4F28);
    // 0x8000B384: lw          $t0, 0x14($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X14);
    // 0x8000B388: lw          $t6, 0x2A2C($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X2A2C);
    // 0x8000B38C: addu        $t8, $t7, $s6
    ctx->r24 = ADD32(ctx->r15, ctx->r22);
    // 0x8000B390: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8000B394: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8000B398: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    // 0x8000B39C: addu        $s1, $s7, $t6
    ctx->r17 = ADD32(ctx->r23, ctx->r14);
    // 0x8000B3A0: lw          $t2, 0x44($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X44);
    // 0x8000B3A4: addiu       $s0, $s1, 0x30
    ctx->r16 = ADD32(ctx->r17, 0X30);
    // 0x8000B3A8: beql        $s3, $t2, L_8000B4B8
    if (ctx->r19 == ctx->r10) {
        // 0x8000B3AC: lbu         $t9, 0x4($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X4);
            goto L_8000B4B8;
    }
    goto skip_0;
    // 0x8000B3AC: lbu         $t9, 0x4($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X4);
    skip_0:
    // 0x8000B3B0: addiu       $s0, $s1, 0x30
    ctx->r16 = ADD32(ctx->r17, 0X30);
    // 0x8000B3B4: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x8000B3B8: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x8000B3BC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000B3C0: sltu        $at, $a0, $at
    ctx->r1 = ctx->r4 < ctx->r1 ? 1 : 0;
    // 0x8000B3C4: bnel        $at, $zero, L_8000B794
    if (ctx->r1 != 0) {
        // 0x8000B3C8: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_8000B794;
    }
    goto skip_1;
    // 0x8000B3C8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_1:
    // 0x8000B3CC: lw          $t3, 0x2C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X2C);
    // 0x8000B3D0: beql        $s1, $t3, L_8000B410
    if (ctx->r17 == ctx->r11) {
        // 0x8000B3D4: lw          $t9, 0x0($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X0);
            goto L_8000B410;
    }
    goto skip_2;
    // 0x8000B3D4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    skip_2:
    // 0x8000B3D8: lbu         $t4, 0x4($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X4);
    // 0x8000B3DC: bnel        $t4, $zero, L_8000B410
    if (ctx->r12 != 0) {
        // 0x8000B3E0: lw          $t9, 0x0($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X0);
            goto L_8000B410;
    }
    goto skip_3;
    // 0x8000B3E0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    skip_3:
    // 0x8000B3E4: lbu         $t6, 0x30($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X30);
    // 0x8000B3E8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000B3EC: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x8000B3F0: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8000B3F4: sb          $t7, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r15;
    // 0x8000B3F8: lwc1        $f4, 0x1D98($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X1D98);
    // 0x8000B3FC: sb          $s5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r21;
    // 0x8000B400: sb          $t8, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r24;
    // 0x8000B404: b           L_8000B4D0
    // 0x8000B408: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
        goto L_8000B4D0;
    // 0x8000B408: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8000B40C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
L_8000B410:
    // 0x8000B410: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x8000B414: bnel        $t0, $zero, L_8000B438
    if (ctx->r8 != 0) {
        // 0x8000B418: lw          $a1, 0x50($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X50);
            goto L_8000B438;
    }
    goto skip_4;
    // 0x8000B418: lw          $a1, 0x50($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X50);
    skip_4:
    // 0x8000B41C: lbu         $t1, 0x4($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X4);
    // 0x8000B420: bnel        $t1, $zero, L_8000B438
    if (ctx->r9 != 0) {
        // 0x8000B424: lw          $a1, 0x50($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X50);
            goto L_8000B438;
    }
    goto skip_5;
    // 0x8000B424: lw          $a1, 0x50($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X50);
    skip_5:
    // 0x8000B428: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x8000B42C: bgtz        $t2, L_8000B484
    if (SIGNED(ctx->r10) > 0) {
        // 0x8000B430: nop
    
            goto L_8000B484;
    }
    // 0x8000B430: nop

    // 0x8000B434: lw          $a1, 0x50($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X50);
L_8000B438:
    // 0x8000B438: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x8000B43C: bnel        $v0, $zero, L_8000B460
    if (ctx->r2 != 0) {
        // 0x8000B440: lw          $t3, 0x0($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X0);
            goto L_8000B460;
    }
    goto skip_6;
    // 0x8000B440: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    skip_6:
    // 0x8000B444: jal         0x8000D86C
    // 0x8000B448: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8000D86C(rdram, ctx);
        goto after_0;
    // 0x8000B448: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8000B44C: sb          $s5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r21;
    // 0x8000B450: sb          $s5, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r21;
    // 0x8000B454: b           L_8000B790
    // 0x8000B458: lw          $v0, 0x1DAC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X1DAC);
        goto L_8000B790;
    // 0x8000B458: lw          $v0, 0x1DAC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X1DAC);
    // 0x8000B45C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
L_8000B460:
    // 0x8000B460: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8000B464: bgez        $t5, L_8000B47C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8000B468: nop
    
            goto L_8000B47C;
    }
    // 0x8000B468: nop

    // 0x8000B46C: lbu         $t6, 0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3);
    // 0x8000B470: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x8000B474: bne         $t7, $zero, L_8000B484
    if (ctx->r15 != 0) {
        // 0x8000B478: nop
    
            goto L_8000B484;
    }
    // 0x8000B478: nop

L_8000B47C:
    // 0x8000B47C: b           L_8000B4D0
    // 0x8000B480: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
        goto L_8000B4D0;
    // 0x8000B480: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
L_8000B484:
    // 0x8000B484: jal         0x8000BC14
    // 0x8000B488: nop

    func_8000BC14(rdram, ctx);
        goto after_1;
    // 0x8000B488: nop

    after_1:
    // 0x8000B48C: jal         0x8000C170
    // 0x8000B490: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000C170(rdram, ctx);
        goto after_2;
    // 0x8000B490: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8000B494: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x8000B498: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000B49C: jal         0x8000C130
    // 0x8000B4A0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_8000C130(rdram, ctx);
        goto after_3;
    // 0x8000B4A0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_3:
    // 0x8000B4A4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000B4A8: sb          $s5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r21;
    // 0x8000B4AC: b           L_8000B4CC
    // 0x8000B4B0: sb          $t8, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r24;
        goto L_8000B4CC;
    // 0x8000B4B0: sb          $t8, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r24;
    // 0x8000B4B4: lbu         $t9, 0x4($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X4);
L_8000B4B8:
    // 0x8000B4B8: bnel        $t9, $zero, L_8000B4D0
    if (ctx->r25 != 0) {
        // 0x8000B4BC: lbu         $v0, 0x0($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X0);
            goto L_8000B4D0;
    }
    goto skip_7;
    // 0x8000B4BC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    skip_7:
    // 0x8000B4C0: lbu         $t0, 0x0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X0);
    // 0x8000B4C4: bgtzl       $t0, L_8000B794
    if (SIGNED(ctx->r8) > 0) {
        // 0x8000B4C8: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_8000B794;
    }
    goto skip_8;
    // 0x8000B4C8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_8:
L_8000B4CC:
    // 0x8000B4CC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
L_8000B4D0:
    // 0x8000B4D0: beql        $v0, $zero, L_8000B790
    if (ctx->r2 == 0) {
        // 0x8000B4D4: lw          $v0, 0x1DAC($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X1DAC);
            goto L_8000B790;
    }
    goto skip_9;
    // 0x8000B4D4: lw          $v0, 0x1DAC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X1DAC);
    skip_9:
    // 0x8000B4D8: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x8000B4DC: addiu       $s2, $s1, 0xB0
    ctx->r18 = ADD32(ctx->r17, 0XB0);
    // 0x8000B4E0: bgtzl       $v0, L_8000B4FC
    if (SIGNED(ctx->r2) > 0) {
        // 0x8000B4E4: lbu         $t4, 0x30($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X30);
            goto L_8000B4FC;
    }
    goto skip_10;
    // 0x8000B4E4: lbu         $t4, 0x30($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X30);
    skip_10:
    // 0x8000B4E8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8000B4EC: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8000B4F0: bgezl       $t3, L_8000B5E0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8000B4F4: lbu         $t4, 0x30($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X30);
            goto L_8000B5E0;
    }
    goto skip_11;
    // 0x8000B4F4: lbu         $t4, 0x30($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X30);
    skip_11:
    // 0x8000B4F8: lbu         $t4, 0x30($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X30);
L_8000B4FC:
    // 0x8000B4FC: addiu       $s2, $s1, 0xB0
    ctx->r18 = ADD32(ctx->r17, 0XB0);
    // 0x8000B500: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x8000B504: beql        $t5, $zero, L_8000B520
    if (ctx->r13 == 0) {
        // 0x8000B508: lw          $t9, 0x18($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X18);
            goto L_8000B520;
    }
    goto skip_12;
    // 0x8000B508: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    skip_12:
    // 0x8000B50C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8000B510: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8000B514: bgez        $t8, L_8000B628
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8000B518: nop
    
            goto L_8000B628;
    }
    // 0x8000B518: nop

    // 0x8000B51C: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
L_8000B520:
    // 0x8000B520: beql        $s3, $t9, L_8000B5A4
    if (ctx->r19 == ctx->r25) {
        // 0x8000B524: lw          $a0, 0x14($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X14);
            goto L_8000B5A4;
    }
    goto skip_13;
    // 0x8000B524: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    skip_13:
    // 0x8000B528: jal         0x8000B2D4
    // 0x8000B52C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000B2D4(rdram, ctx);
        goto after_4;
    // 0x8000B52C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8000B530: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x8000B534: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000B538: lw          $t0, 0x50($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X50);
    // 0x8000B53C: beq         $t0, $zero, L_8000B57C
    if (ctx->r8 == 0) {
        // 0x8000B540: nop
    
            goto L_8000B57C;
    }
    // 0x8000B540: nop

    // 0x8000B544: jal         0x8000C21C
    // 0x8000B548: addiu       $s2, $s1, 0xB0
    ctx->r18 = ADD32(ctx->r17, 0XB0);
    func_8000C21C(rdram, ctx);
        goto after_5;
    // 0x8000B548: addiu       $s2, $s1, 0xB0
    ctx->r18 = ADD32(ctx->r17, 0XB0);
    after_5:
    // 0x8000B54C: jal         0x8000CEEC
    // 0x8000B550: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000CEEC(rdram, ctx);
        goto after_6;
    // 0x8000B550: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8000B554: jal         0x8000CFA4
    // 0x8000B558: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000CFA4(rdram, ctx);
        goto after_7;
    // 0x8000B558: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8000B55C: jal         0x8000C170
    // 0x8000B560: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000C170(rdram, ctx);
        goto after_8;
    // 0x8000B560: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8000B564: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x8000B568: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000B56C: jal         0x8000DB94
    // 0x8000B570: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_8000DB94(rdram, ctx);
        goto after_9;
    // 0x8000B570: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_9:
    // 0x8000B574: b           L_8000B628
    // 0x8000B578: sw          $s3, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r19;
        goto L_8000B628;
    // 0x8000B578: sw          $s3, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r19;
L_8000B57C:
    // 0x8000B57C: jal         0x8000B2D4
    // 0x8000B580: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000B2D4(rdram, ctx);
        goto after_10;
    // 0x8000B580: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8000B584: jal         0x8000C170
    // 0x8000B588: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000C170(rdram, ctx);
        goto after_11;
    // 0x8000B588: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8000B58C: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x8000B590: jal         0x8000DB94
    // 0x8000B594: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8000DB94(rdram, ctx);
        goto after_12;
    // 0x8000B594: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_12:
    // 0x8000B598: b           L_8000B78C
    // 0x8000B59C: sw          $s3, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r19;
        goto L_8000B78C;
    // 0x8000B59C: sw          $s3, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r19;
    // 0x8000B5A0: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
L_8000B5A4:
    // 0x8000B5A4: beq         $s3, $a0, L_8000B5B8
    if (ctx->r19 == ctx->r4) {
        // 0x8000B5A8: nop
    
            goto L_8000B5B8;
    }
    // 0x8000B5A8: nop

    // 0x8000B5AC: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
    // 0x8000B5B0: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x8000B5B4: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
L_8000B5B8:
    // 0x8000B5B8: jal         0x8000B2D4
    // 0x8000B5BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000B2D4(rdram, ctx);
        goto after_13;
    // 0x8000B5BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x8000B5C0: jal         0x8000C170
    // 0x8000B5C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000C170(rdram, ctx);
        goto after_14;
    // 0x8000B5C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x8000B5C8: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x8000B5CC: jal         0x8000DB94
    // 0x8000B5D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8000DB94(rdram, ctx);
        goto after_15;
    // 0x8000B5D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
    // 0x8000B5D4: b           L_8000B790
    // 0x8000B5D8: lw          $v0, 0x1DAC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X1DAC);
        goto L_8000B790;
    // 0x8000B5D8: lw          $v0, 0x1DAC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X1DAC);
    // 0x8000B5DC: lbu         $t4, 0x30($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X30);
L_8000B5E0:
    // 0x8000B5E0: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x8000B5E4: bne         $t5, $zero, L_8000B628
    if (ctx->r13 != 0) {
        // 0x8000B5E8: nop
    
            goto L_8000B628;
    }
    // 0x8000B5E8: nop

    // 0x8000B5EC: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x8000B5F0: beq         $s3, $a0, L_8000B604
    if (ctx->r19 == ctx->r4) {
        // 0x8000B5F4: nop
    
            goto L_8000B604;
    }
    // 0x8000B5F4: nop

    // 0x8000B5F8: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8000B5FC: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x8000B600: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
L_8000B604:
    // 0x8000B604: jal         0x8000B2D4
    // 0x8000B608: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000B2D4(rdram, ctx);
        goto after_16;
    // 0x8000B608: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x8000B60C: jal         0x8000C170
    // 0x8000B610: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000C170(rdram, ctx);
        goto after_17;
    // 0x8000B610: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x8000B614: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x8000B618: jal         0x8000DB94
    // 0x8000B61C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8000DB94(rdram, ctx);
        goto after_18;
    // 0x8000B61C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_18:
    // 0x8000B620: b           L_8000B790
    // 0x8000B624: lw          $v0, 0x1DAC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X1DAC);
        goto L_8000B790;
    // 0x8000B624: lw          $v0, 0x1DAC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X1DAC);
L_8000B628:
    // 0x8000B628: jal         0x8000CFF0
    // 0x8000B62C: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    func_8000CFF0(rdram, ctx);
        goto after_19;
    // 0x8000B62C: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_19:
    // 0x8000B630: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8000B634: jal         0x8000CE90
    // 0x8000B638: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000CE90(rdram, ctx);
        goto after_20;
    // 0x8000B638: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x8000B63C: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x8000B640: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000B644: beq         $v0, $at, L_8000B650
    if (ctx->r2 == ctx->r1) {
        // 0x8000B648: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000B650;
    }
    // 0x8000B648: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B64C: bne         $v0, $at, L_8000B6A4
    if (ctx->r2 != ctx->r1) {
        // 0x8000B650: addiu       $v0, $s0, 0x1C
        ctx->r2 = ADD32(ctx->r16, 0X1C);
            goto L_8000B6A4;
    }
L_8000B650:
    // 0x8000B650: addiu       $v0, $s0, 0x1C
    ctx->r2 = ADD32(ctx->r16, 0X1C);
    // 0x8000B654: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000B658: addiu       $t1, $sp, 0x63
    ctx->r9 = ADD32(ctx->r29, 0X63);
    // 0x8000B65C: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x8000B660: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000B664: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x8000B668: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x8000B66C: sb          $t9, 0x62($sp)
    MEM_B(0X62, ctx->r29) = ctx->r25;
    // 0x8000B670: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8000B674: sb          $t0, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r8;
    // 0x8000B678: lbu         $t3, 0x3($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X3);
    // 0x8000B67C: sb          $t3, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r11;
    // 0x8000B680: lbu         $t4, 0x1($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X1);
    // 0x8000B684: sb          $t4, 0x61($sp)
    MEM_B(0X61, ctx->r29) = ctx->r12;
    // 0x8000B688: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x8000B68C: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
    // 0x8000B690: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8000B694: sll         $a3, $a3, 11
    ctx->r7 = S32(ctx->r7 << 11);
    // 0x8000B698: srl         $a3, $a3, 30
    ctx->r7 = S32(U32(ctx->r7) >> 30);
    // 0x8000B69C: b           L_8000B728
    // 0x8000B6A0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
        goto L_8000B728;
    // 0x8000B6A0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
L_8000B6A4:
    // 0x8000B6A4: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x8000B6A8: addiu       $t7, $sp, 0x63
    ctx->r15 = ADD32(ctx->r29, 0X63);
    // 0x8000B6AC: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8000B6B0: lw          $v1, 0x50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X50);
    // 0x8000B6B4: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x8000B6B8: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8000B6BC: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x8000B6C0: lbu         $t6, 0x6($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X6);
    // 0x8000B6C4: sb          $t6, 0x62($sp)
    MEM_B(0X62, ctx->r29) = ctx->r14;
    // 0x8000B6C8: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8000B6CC: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x8000B6D0: lbu         $t0, 0x4($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X4);
    // 0x8000B6D4: sb          $t0, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r8;
    // 0x8000B6D8: lbu         $t1, 0xC($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XC);
    // 0x8000B6DC: sb          $t1, 0x61($sp)
    MEM_B(0X61, ctx->r29) = ctx->r9;
    // 0x8000B6E0: lw          $t2, 0xD4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XD4);
    // 0x8000B6E4: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x8000B6E8: lw          $t3, 0x4C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4C);
    // 0x8000B6EC: lbu         $a3, 0x9($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X9);
    // 0x8000B6F0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8000B6F4: andi        $a3, $a3, 0x7
    ctx->r7 = ctx->r7 & 0X7;
    // 0x8000B6F8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8000B6FC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8000B700: bgezl       $t6, L_8000B72C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8000B704: lwc1        $f6, 0xC($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
            goto L_8000B72C;
    }
    goto skip_14;
    // 0x8000B704: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    skip_14:
    // 0x8000B708: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
    // 0x8000B70C: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8000B710: beql        $t8, $zero, L_8000B72C
    if (ctx->r24 == 0) {
        // 0x8000B714: lwc1        $f6, 0xC($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
            goto L_8000B72C;
    }
    goto skip_15;
    // 0x8000B714: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    skip_15:
    // 0x8000B718: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000B71C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000B720: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x8000B724: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
L_8000B728:
    // 0x8000B728: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
L_8000B72C:
    // 0x8000B72C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000B730: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000B734: lwc1        $f4, 0x1D94($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X1D94);
    // 0x8000B738: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000B73C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000B740: sb          $a3, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r7;
    // 0x8000B744: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000B748: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x8000B74C: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    // 0x8000B750: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8000B754: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8000B758: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000B75C: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x8000B760: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000B764: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x8000B768: jal         0x8000ADA0
    // 0x8000B76C: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    func_8000ADA0(rdram, ctx);
        goto after_21;
    // 0x8000B76C: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    after_21:
    // 0x8000B770: lbu         $t9, 0x5F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X5F);
    // 0x8000B774: lbu         $t2, 0x1($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X1);
    // 0x8000B778: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8000B77C: andi        $t1, $t0, 0x18
    ctx->r9 = ctx->r8 & 0X18;
    // 0x8000B780: andi        $t3, $t2, 0xFFE7
    ctx->r11 = ctx->r10 & 0XFFE7;
    // 0x8000B784: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x8000B788: sb          $t4, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r12;
L_8000B78C:
    // 0x8000B78C: lw          $v0, 0x1DAC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X1DAC);
L_8000B790:
    // 0x8000B790: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_8000B794:
    // 0x8000B794: slt         $at, $s6, $v0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000B798: bne         $at, $zero, L_8000B380
    if (ctx->r1 != 0) {
        // 0x8000B79C: addiu       $s7, $s7, 0xD0
        ctx->r23 = ADD32(ctx->r23, 0XD0);
            goto L_8000B380;
    }
    // 0x8000B79C: addiu       $s7, $s7, 0xD0
    ctx->r23 = ADD32(ctx->r23, 0XD0);
L_8000B7A0:
    // 0x8000B7A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000B7A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000B7A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000B7AC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B7B0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000B7B4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000B7B8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000B7BC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B7C0: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8000B7C4: jr          $ra
    // 0x8000B7C8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8000B7C8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_8049F130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049F130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8049F134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8049F138: jal         0x8004700C
    // 0x8049F13C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8049F13C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8049F140: bne         $v0, $zero, L_8049F160
    if (ctx->r2 != 0) {
        // 0x8049F144: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8049F160;
    }
    // 0x8049F144: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8049F148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F14C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8049F150: jal         0x8049FBAC
    // 0x8049F154: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8049FBAC(rdram, ctx);
        goto after_1;
    // 0x8049F154: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8049F158: b           L_8049F1A0
    // 0x8049F15C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8049F1A0;
    // 0x8049F15C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8049F160:
    // 0x8049F160: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8049F164: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8049F168: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8049F16C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F170: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8049F174: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8049F178: bc1f        L_8049F194
    if (!c1cs) {
        // 0x8049F17C: nop
    
            goto L_8049F194;
    }
    // 0x8049F17C: nop

    // 0x8049F180: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F184: jal         0x8049FBAC
    // 0x8049F188: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8049FBAC(rdram, ctx);
        goto after_2;
    // 0x8049F188: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x8049F18C: b           L_8049F1A0
    // 0x8049F190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8049F1A0;
    // 0x8049F190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8049F194:
    // 0x8049F194: jal         0x8049FBAC
    // 0x8049F198: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8049FBAC(rdram, ctx);
        goto after_3;
    // 0x8049F198: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8049F19C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8049F1A0:
    // 0x8049F1A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8049F1A4: jr          $ra
    // 0x8049F1A8: nop

    return;
    // 0x8049F1A8: nop

;}
RECOMP_FUNC void func_8003F224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F224: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003F228: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003F22C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003F230: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8003F234: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8003F238: jal         0x8003EBD4
    // 0x8003F23C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_8003EBD4(rdram, ctx);
        goto after_0;
    // 0x8003F23C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x8003F240: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8003F244: jal         0x80065490
    // 0x8003F248: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x8003F248: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x8003F24C: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x8003F250: jal         0x80065490
    // 0x8003F254: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x8003F254: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x8003F258: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8003F25C: jal         0x80065490
    // 0x8003F260: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x8003F260: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x8003F264: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8003F268: addiu       $t6, $t6, -0x1A14
    ctx->r14 = ADD32(ctx->r14, -0X1A14);
    // 0x8003F26C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003F270: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003F274: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    // 0x8003F278: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8003F27C: jal         0x8003E6C4
    // 0x8003F280: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8003E6C4(rdram, ctx);
        goto after_4;
    // 0x8003F280: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8003F284: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8003F288: addiu       $a2, $a2, -0x5A14
    ctx->r6 = ADD32(ctx->r6, -0X5A14);
    // 0x8003F28C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F290: jal         0x8003F14C
    // 0x8003F294: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8003F14C(rdram, ctx);
        goto after_5;
    // 0x8003F294: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x8003F298: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003F29C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003F2A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003F2A4: jr          $ra
    // 0x8003F2A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8003F2A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80532C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80532C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80532C8C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80532C90: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80532C94: lui         $t8, 0x8053
    ctx->r24 = S32(RELOC_HI16(345, 0X18A8) << 16);
    // 0x80532C98: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80532C9C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80532CA0: lw          $t8, 0x4378($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(345, 0X18A8));
    // 0x80532CA4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80532CA8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80532CAC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80532CB0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80532CB4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80532CB8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80532CBC: beql        $v1, $zero, L_80532CF0
    if (ctx->r3 == 0) {
        // 0x80532CC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80532CF0;
    }
    goto skip_0;
    // 0x80532CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80532CC4: jalr        $v1
    // 0x80532CC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80532CC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80532CCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80532CD0: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80532CD4: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80532CD8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80532CDC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80532CE0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80532CE4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80532CE8: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80532CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80532CF0:
    // 0x80532CF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80532CF4: jr          $ra
    // 0x80532CF8: nop

    return;
    // 0x80532CF8: nop

;}
RECOMP_FUNC void func_80011540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011540: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80011544: lbu         $t6, -0x6DA0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6DA0);
    // 0x80011548: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001154C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011550: beq         $t6, $zero, L_80011588
    if (ctx->r14 == 0) {
        // 0x80011554: lui         $t7, 0x800A
        ctx->r15 = S32(0X800A << 16);
            goto L_80011588;
    }
    // 0x80011554: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80011558: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8001155C: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80011560: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80011564: jal         0x8001ADC4
    // 0x80011568: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001ADC4(rdram, ctx);
        goto after_0;
    // 0x80011568: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8001156C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80011570: lw          $a0, -0x6D6C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D6C);
    // 0x80011574: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80011578: jal         0x8001ADC4
    // 0x8001157C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001ADC4(rdram, ctx);
        goto after_1;
    // 0x8001157C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80011580: b           L_800115F4
    // 0x80011584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800115F4;
    // 0x80011584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011588:
    // 0x80011588: lbu         $t7, -0x6D7C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X6D7C);
    // 0x8001158C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80011590: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80011594: beq         $t7, $zero, L_800115D4
    if (ctx->r15 == 0) {
        // 0x80011598: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800115D4;
    }
    // 0x80011598: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001159C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800115A0: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x800115A4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x800115A8: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x800115AC: jal         0x8001ADC4
    // 0x800115B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001ADC4(rdram, ctx);
        goto after_2;
    // 0x800115B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800115B4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800115B8: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x800115BC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x800115C0: lw          $a0, -0x6D6C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D6C);
    // 0x800115C4: jal         0x8001ADC4
    // 0x800115C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001ADC4(rdram, ctx);
        goto after_3;
    // 0x800115C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x800115CC: b           L_800115F4
    // 0x800115D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800115F4;
    // 0x800115D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800115D4:
    // 0x800115D4: jal         0x8001ADC4
    // 0x800115D8: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    func_8001ADC4(rdram, ctx);
        goto after_4;
    // 0x800115D8: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    after_4:
    // 0x800115DC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800115E0: lw          $a0, -0x6D6C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D6C);
    // 0x800115E4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800115E8: jal         0x8001ADC4
    // 0x800115EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001ADC4(rdram, ctx);
        goto after_5;
    // 0x800115EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x800115F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800115F4:
    // 0x800115F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800115F8: jr          $ra
    // 0x800115FC: nop

    return;
    // 0x800115FC: nop

;}
RECOMP_FUNC void func_8066B470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B470: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8066B474: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8066B478: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8066B47C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066B480: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8066B484: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8066B488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8066B48C: jal         0x8066AD18
    // 0x8066B490: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8066AD18(rdram, ctx);
        goto after_0;
    // 0x8066B490: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8066B494: jal         0x8066B050
    // 0x8066B498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066B050(rdram, ctx);
        goto after_1;
    // 0x8066B498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8066B49C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8066B4A0: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8066B4A4: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8066B4A8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8066B4AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8066B4B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B4B4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8066B4B8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8066B4BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8066B4C0: bc1f        L_8066B4D0
    if (!c1cs) {
        // 0x8066B4C4: nop
    
            goto L_8066B4D0;
    }
    // 0x8066B4C4: nop

    // 0x8066B4C8: jal         0x8066B970
    // 0x8066B4CC: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    func_8066B970(rdram, ctx);
        goto after_2;
    // 0x8066B4CC: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    after_2:
L_8066B4D0:
    // 0x8066B4D0: jal         0x8066B1C4
    // 0x8066B4D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066B1C4(rdram, ctx);
        goto after_3;
    // 0x8066B4D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8066B4D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8066B4DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8066B4E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8066B4E4: jr          $ra
    // 0x8066B4E8: nop

    return;
    // 0x8066B4E8: nop

;}
RECOMP_FUNC void func_804CE808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE808: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x804CE80C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x804CE810: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x804CE814: addiu       $t7, $t7, -0x785C
    ctx->r15 = ADD32(ctx->r15, -0X785C);
    // 0x804CE818: sw          $v1, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r3;
    // 0x804CE81C: sb          $v1, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r3;
    // 0x804CE820: sw          $t6, 0x150($a0)
    MEM_W(0X150, ctx->r4) = ctx->r14;
    // 0x804CE824: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
    // 0x804CE828: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x804CE82C: jr          $ra
    // 0x804CE830: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x804CE830: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8007B550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B550: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007B554: jr          $ra
    // 0x8007B558: nop

    return;
    // 0x8007B558: nop

;}
RECOMP_FUNC void func_80441D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441D38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80441D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80441D40: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80441D44: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80441D48: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80441D4C: addiu       $t6, $v0, 0x1C98
    ctx->r14 = ADD32(ctx->r2, 0X1C98);
    // 0x80441D50: addiu       $t7, $v0, 0x2160
    ctx->r15 = ADD32(ctx->r2, 0X2160);
    // 0x80441D54: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80441D58: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80441D5C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80441D60: jal         0x80441C44
    // 0x80441D64: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80441C44(rdram, ctx);
        goto after_0;
    // 0x80441D64: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80441D68: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80441D6C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80441D70: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80441D74: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80441D78: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x80441D7C: lui         $t9, 0x8044
    ctx->r25 = S32(RELOC_HI16(95, 0X2CE8) << 16);
    // 0x80441D80: addiu       $t9, $t9, 0x1BE8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(95, 0X2CE8));
    // 0x80441D84: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x80441D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80441D8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80441D90: jr          $ra
    // 0x80441D94: nop

    return;
    // 0x80441D94: nop

;}
RECOMP_FUNC void func_805AE654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE654: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AE658: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805AE65C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805AE660: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805AE664: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805AE668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AE66C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x805AE670: lui         $a2, 0x805C
    ctx->r6 = S32(RELOC_HI16(444, 0X17864) << 16);
    // 0x805AE674: lui         $a1, 0x805C
    ctx->r5 = S32(RELOC_HI16(444, 0X1787C) << 16);
    // 0x805AE678: addiu       $a1, $a1, 0x4F7C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(444, 0X1787C));
    // 0x805AE67C: addiu       $a2, $a2, 0x4F64
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(444, 0X17864));
    // 0x805AE680: jal         0x805AD7C8
    // 0x805AE684: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_805AD7C8(rdram, ctx);
        goto after_0;
    // 0x805AE684: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x805AE688: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x805AE68C: lui         $a1, 0x805C
    ctx->r5 = S32(RELOC_HI16(444, 0X1779C) << 16);
    // 0x805AE690: lui         $a2, 0x805C
    ctx->r6 = S32(RELOC_HI16(444, 0X176D4) << 16);
    // 0x805AE694: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x805AE698: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x805AE69C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805AE6A0: addiu       $a2, $a2, 0x4DD4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(444, 0X176D4));
    // 0x805AE6A4: addiu       $a1, $a1, 0x4E9C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(444, 0X1779C));
    // 0x805AE6A8: jal         0x805AD7C8
    // 0x805AE6AC: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    func_805AD7C8(rdram, ctx);
        goto after_1;
    // 0x805AE6AC: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_1:
    // 0x805AE6B0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x805AE6B4: swc1        $f0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f0.u32l;
    // 0x805AE6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AE6BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AE6C0: jr          $ra
    // 0x805AE6C4: nop

    return;
    // 0x805AE6C4: nop

;}
RECOMP_FUNC void func_8078DE94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078DE94: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8078DE98: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8078DE9C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8078DEA0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8078DEA4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8078DEA8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8078DEAC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8078DEB0: lui         $t1, 0x8079
    ctx->r9 = S32(RELOC_HI16(805, 0X128) << 16);
    // 0x8078DEB4: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8078DEB8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8078DEBC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8078DEC0: lw          $t1, -0x2128($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(805, 0X128));
    // 0x8078DEC4: jr          $ra
    // 0x8078DEC8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8078DEC8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8078DECC: nop

;}
RECOMP_FUNC void func_8002C51C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C51C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002C520: lwc1        $f0, -0x6C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C);
    // 0x8002C524: swc1        $f0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f0.u32l;
    // 0x8002C528: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x8002C52C: jr          $ra
    // 0x8002C530: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8002C530: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_800233B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800233B4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800233B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800233BC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x800233C0: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x800233C4: lwc1        $f4, 0xEC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XEC);
    // 0x800233C8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x800233CC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800233D0: lbu         $t9, 0x22($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X22);
    // 0x800233D4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x800233D8: lwc1        $f6, 0x28($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X28);
    // 0x800233DC: sb          $t9, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r25;
    // 0x800233E0: lwc1        $f12, 0x120($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X120);
    // 0x800233E4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800233E8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800233EC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800233F0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800233F4: nop

    // 0x800233F8: addiu       $v1, $v1, -0x8
    ctx->r3 = ADD32(ctx->r3, -0X8);
    // 0x800233FC: jal         0x80066E88
    // 0x80023400: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80023400: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x80023404: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80023408: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8002340C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023410: lwc1        $f10, 0xC4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80023414: lwc1        $f4, 0x100($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X100);
    // 0x80023418: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x8002341C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80023420: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80023424: lwc1        $f10, 0x10C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x80023428: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8002342C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80023430: lwc1        $f6, 0xE4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XE4);
    // 0x80023434: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80023438: lwc1        $f10, -0x2F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2F8);
    // 0x8002343C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80023440: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80023444: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80023448: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002344C: lwc1        $f2, -0x6280($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6280);
    // 0x80023450: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023454: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80023458: nop

    // 0x8002345C: mul.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80023460: c.le.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl <= ctx->f18.fl;
    // 0x80023464: nop

    // 0x80023468: bc1f        L_80023478
    if (!c1cs) {
        // 0x8002346C: nop
    
            goto L_80023478;
    }
    // 0x8002346C: nop

    // 0x80023470: b           L_80023490
    // 0x80023474: mov.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.fl = ctx->f2.fl;
        goto L_80023490;
    // 0x80023474: mov.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.fl = ctx->f2.fl;
L_80023478:
    // 0x80023478: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x8002347C: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x80023480: nop

    // 0x80023484: bc1f        L_80023490
    if (!c1cs) {
        // 0x80023488: nop
    
            goto L_80023490;
    }
    // 0x80023488: nop

    // 0x8002348C: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
L_80023490:
    // 0x80023490: lwc1        $f8, -0x2F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2F4);
    // 0x80023494: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023498: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x8002349C: nop

    // 0x800234A0: bc1tl       L_800234C0
    if (c1cs) {
        // 0x800234A4: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_800234C0;
    }
    goto skip_0;
    // 0x800234A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x800234A8: lwc1        $f10, -0x2F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2F0);
    // 0x800234AC: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x800234B0: nop

    // 0x800234B4: bc1fl       L_80023588
    if (!c1cs) {
        // 0x800234B8: lw          $v0, 0x34($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X34);
            goto L_80023588;
    }
    goto skip_1;
    // 0x800234B8: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    skip_1:
    // 0x800234BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_800234C0:
    // 0x800234C0: nop

    // 0x800234C4: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x800234C8: nop

    // 0x800234CC: bc1fl       L_80023530
    if (!c1cs) {
        // 0x800234D0: lw          $t6, 0x34($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X34);
            goto L_80023530;
    }
    goto skip_2;
    // 0x800234D0: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    skip_2:
    // 0x800234D4: lw          $t2, 0x34($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X34);
    // 0x800234D8: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x800234DC: slti        $at, $t3, 0x130
    ctx->r1 = SIGNED(ctx->r11) < 0X130 ? 1 : 0;
    // 0x800234E0: beql        $at, $zero, L_80023510
    if (ctx->r1 == 0) {
        // 0x800234E4: sw          $a0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r4;
            goto L_80023510;
    }
    goto skip_3;
    // 0x800234E4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    skip_3:
    // 0x800234E8: lw          $t4, 0x24($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X24);
    // 0x800234EC: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x800234F0: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800234F4: bnel        $t5, $zero, L_800235C4
    if (ctx->r13 != 0) {
        // 0x800234F8: lw          $t2, 0x24($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X24);
            goto L_800235C4;
    }
    goto skip_4;
    // 0x800234F8: lw          $t2, 0x24($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X24);
    skip_4:
    // 0x800234FC: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80023500: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80023504: b           L_800235C0
    // 0x80023508: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
        goto L_800235C0;
    // 0x80023508: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8002350C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
L_80023510:
    // 0x80023510: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80023514: jal         0x80023310
    // 0x80023518: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_80023310(rdram, ctx);
        goto after_1;
    // 0x80023518: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8002351C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80023520: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80023524: b           L_800235C0
    // 0x80023528: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
        goto L_800235C0;
    // 0x80023528: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8002352C: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
L_80023530:
    // 0x80023530: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x80023534: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x80023538: bnel        $at, $zero, L_80023568
    if (ctx->r1 != 0) {
        // 0x8002353C: sw          $a0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r4;
            goto L_80023568;
    }
    goto skip_5;
    // 0x8002353C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    skip_5:
    // 0x80023540: lw          $t8, 0x24($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X24);
    // 0x80023544: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x80023548: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8002354C: bnel        $t9, $zero, L_800235C4
    if (ctx->r25 != 0) {
        // 0x80023550: lw          $t2, 0x24($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X24);
            goto L_800235C4;
    }
    goto skip_6;
    // 0x80023550: lw          $t2, 0x24($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X24);
    skip_6:
    // 0x80023554: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80023558: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8002355C: b           L_800235C0
    // 0x80023560: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
        goto L_800235C0;
    // 0x80023560: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x80023564: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
L_80023568:
    // 0x80023568: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8002356C: jal         0x80023310
    // 0x80023570: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_80023310(rdram, ctx);
        goto after_2;
    // 0x80023570: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80023574: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80023578: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8002357C: b           L_800235C0
    // 0x80023580: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
        goto L_800235C0;
    // 0x80023580: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80023584: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
L_80023588:
    // 0x80023588: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x8002358C: slti        $at, $t0, 0x130
    ctx->r1 = SIGNED(ctx->r8) < 0X130 ? 1 : 0;
    // 0x80023590: beq         $at, $zero, L_800235A4
    if (ctx->r1 == 0) {
        // 0x80023594: subu        $t1, $v0, $v1
        ctx->r9 = SUB32(ctx->r2, ctx->r3);
            goto L_800235A4;
    }
    // 0x80023594: subu        $t1, $v0, $v1
    ctx->r9 = SUB32(ctx->r2, ctx->r3);
    // 0x80023598: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x8002359C: beql        $at, $zero, L_800235C4
    if (ctx->r1 == 0) {
        // 0x800235A0: lw          $t2, 0x24($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X24);
            goto L_800235C4;
    }
    goto skip_7;
    // 0x800235A0: lw          $t2, 0x24($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X24);
    skip_7:
L_800235A4:
    // 0x800235A4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800235A8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800235AC: jal         0x80023310
    // 0x800235B0: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_80023310(rdram, ctx);
        goto after_3;
    // 0x800235B0: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x800235B4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800235B8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800235BC: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
L_800235C0:
    // 0x800235C0: lw          $t2, 0x24($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X24);
L_800235C4:
    // 0x800235C4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800235C8: andi        $t3, $t2, 0x700
    ctx->r11 = ctx->r10 & 0X700;
    // 0x800235CC: beql        $t3, $zero, L_800235F0
    if (ctx->r11 == 0) {
        // 0x800235D0: lwc1        $f4, 0xC8($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
            goto L_800235F0;
    }
    goto skip_8;
    // 0x800235D0: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    skip_8:
    // 0x800235D4: lwc1        $f6, 0x110($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X110);
    // 0x800235D8: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800235DC: nop

    // 0x800235E0: bc1fl       L_800235F0
    if (!c1cs) {
        // 0x800235E4: lwc1        $f4, 0xC8($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
            goto L_800235F0;
    }
    goto skip_9;
    // 0x800235E4: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    skip_9:
    // 0x800235E8: swc1        $f2, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f2.u32l;
    // 0x800235EC: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
L_800235F0:
    // 0x800235F0: lwc1        $f8, 0x104($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X104);
    // 0x800235F4: lwc1        $f6, 0x110($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X110);
    // 0x800235F8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800235FC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80023600: lwc1        $f8, 0xE8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XE8);
    // 0x80023604: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80023608: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002360C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80023610: lwc1        $f6, -0x2EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2EC);
    // 0x80023614: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80023618: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8002361C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80023620: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80023624: nop

    // 0x80023628: mul.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8002362C: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x80023630: nop

    // 0x80023634: bc1f        L_80023644
    if (!c1cs) {
        // 0x80023638: nop
    
            goto L_80023644;
    }
    // 0x80023638: nop

    // 0x8002363C: b           L_80023660
    // 0x80023640: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_80023660;
    // 0x80023640: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80023644:
    // 0x80023644: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80023648: nop

    // 0x8002364C: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x80023650: nop

    // 0x80023654: bc1fl       L_80023664
    if (!c1cs) {
        // 0x80023658: lw          $t4, 0x174($a0)
        ctx->r12 = MEM_W(ctx->r4, 0X174);
            goto L_80023664;
    }
    goto skip_10;
    // 0x80023658: lw          $t4, 0x174($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X174);
    skip_10:
    // 0x8002365C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80023660:
    // 0x80023660: lw          $t4, 0x174($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X174);
L_80023664:
    // 0x80023664: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80023668: andi        $t6, $t5, 0xF00
    ctx->r14 = ctx->r13 & 0XF00;
    // 0x8002366C: beq         $t6, $zero, L_80023760
    if (ctx->r14 == 0) {
        // 0x80023670: nop
    
            goto L_80023760;
    }
    // 0x80023670: nop

    // 0x80023674: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80023678: nop

    // 0x8002367C: bc1f        L_80023760
    if (!c1cs) {
        // 0x80023680: nop
    
            goto L_80023760;
    }
    // 0x80023680: nop

    // 0x80023684: lwc1        $f12, 0x120($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X120);
    // 0x80023688: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8002368C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80023690: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80023694: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80023698: jal         0x80066E88
    // 0x8002369C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x8002369C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x800236A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800236A4: lwc1        $f10, -0x2E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E8);
    // 0x800236A8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800236AC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800236B0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800236B4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800236B8: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800236BC: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800236C0: bc1t        L_800236E4
    if (c1cs) {
        // 0x800236C4: mov.s       $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
            goto L_800236E4;
    }
    // 0x800236C4: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x800236C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800236CC: lwc1        $f6, -0x2E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E4);
    // 0x800236D0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800236D4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800236D8: nop

    // 0x800236DC: bc1fl       L_80023728
    if (!c1cs) {
        // 0x800236E0: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80023728;
    }
    goto skip_11;
    // 0x800236E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_11:
L_800236E4:
    // 0x800236E4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800236E8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800236EC: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x800236F0: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x800236F4: jal         0x80066DE4
    // 0x800236F8: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x800236F8: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x800236FC: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80023700: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80023704: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80023708: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8002370C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80023710: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80023714: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80023718: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002371C: b           L_80023730
    // 0x80023720: div.s       $f2, $f8, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
        goto L_80023730;
    // 0x80023720: div.s       $f2, $f8, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80023724: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80023728:
    // 0x80023728: nop

    // 0x8002372C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80023730:
    // 0x80023730: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80023734: nop

    // 0x80023738: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8002373C: nop

    // 0x80023740: bc1f        L_80023760
    if (!c1cs) {
        // 0x80023744: nop
    
            goto L_80023760;
    }
    // 0x80023744: nop

    // 0x80023748: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002374C: nop

    // 0x80023750: bc1fl       L_80023760
    if (!c1cs) {
        // 0x80023754: add.s       $f14, $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
            goto L_80023760;
    }
    goto skip_12;
    // 0x80023754: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
    skip_12:
    // 0x80023758: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8002375C: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
L_80023760:
    // 0x80023760: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x80023764: lbu         $t7, 0x7EA5($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7EA5);
    // 0x80023768: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002376C: beql        $t7, $zero, L_800237A8
    if (ctx->r15 == 0) {
        // 0x80023770: lwc1        $f10, 0x40($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
            goto L_800237A8;
    }
    goto skip_13;
    // 0x80023770: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    skip_13:
    // 0x80023774: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x80023778: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8002377C: beql        $t9, $zero, L_800237A8
    if (ctx->r25 == 0) {
        // 0x80023780: lwc1        $f10, 0x40($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
            goto L_800237A8;
    }
    goto skip_14;
    // 0x80023780: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    skip_14:
    // 0x80023784: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80023788: nop

    // 0x8002378C: bc1fl       L_800237B4
    if (!c1cs) {
        // 0x80023790: lwc1        $f8, 0xCC($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0XCC);
            goto L_800237B4;
    }
    goto skip_15;
    // 0x80023790: lwc1        $f8, 0xCC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XCC);
    skip_15:
    // 0x80023794: lw          $t0, 0x24($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X24);
    // 0x80023798: andi        $t1, $t0, 0x3000
    ctx->r9 = ctx->r8 & 0X3000;
    // 0x8002379C: bnel        $t1, $zero, L_800237B4
    if (ctx->r9 != 0) {
        // 0x800237A0: lwc1        $f8, 0xCC($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0XCC);
            goto L_800237B4;
    }
    goto skip_16;
    // 0x800237A0: lwc1        $f8, 0xCC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XCC);
    skip_16:
    // 0x800237A4: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
L_800237A8:
    // 0x800237A8: add.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x800237AC: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x800237B0: lwc1        $f8, 0xCC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XCC);
L_800237B4:
    // 0x800237B4: lwc1        $f4, 0x108($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X108);
    // 0x800237B8: lwc1        $f6, 0x114($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X114);
    // 0x800237BC: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800237C0: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800237C4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800237C8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800237CC: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    // 0x800237D0: lbu         $t2, 0xF4($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XF4);
    // 0x800237D4: beq         $t2, $zero, L_80023804
    if (ctx->r10 == 0) {
        // 0x800237D8: nop
    
            goto L_80023804;
    }
    // 0x800237D8: nop

    // 0x800237DC: lwc1        $f0, 0xC8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x800237E0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800237E4: nop

    // 0x800237E8: bc1fl       L_80023804
    if (!c1cs) {
        // 0x800237EC: swc1        $f2, 0x12E4($a1)
        MEM_W(0X12E4, ctx->r5) = ctx->f2.u32l;
            goto L_80023804;
    }
    goto skip_17;
    // 0x800237EC: swc1        $f2, 0x12E4($a1)
    MEM_W(0X12E4, ctx->r5) = ctx->f2.u32l;
    skip_17:
    // 0x800237F0: lwc1        $f6, 0x12E4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X12E4);
    // 0x800237F4: add.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800237F8: b           L_80023804
    // 0x800237FC: swc1        $f4, 0x12E4($a1)
    MEM_W(0X12E4, ctx->r5) = ctx->f4.u32l;
        goto L_80023804;
    // 0x800237FC: swc1        $f4, 0x12E4($a1)
    MEM_W(0X12E4, ctx->r5) = ctx->f4.u32l;
    // 0x80023800: swc1        $f2, 0x12E4($a1)
    MEM_W(0X12E4, ctx->r5) = ctx->f2.u32l;
L_80023804:
    // 0x80023804: jal         0x800232E0
    // 0x80023808: nop

    func_800232E0(rdram, ctx);
        goto after_6;
    // 0x80023808: nop

    after_6:
    // 0x8002380C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023810: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80023814: jr          $ra
    // 0x80023818: nop

    return;
    // 0x80023818: nop

;}
RECOMP_FUNC void func_8003FDC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FDC4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8003FDC8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003FDCC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003FDD0: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8003FDD4: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8003FDD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003FDDC: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x8003FDE0: lbu         $t7, 0x12C8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X12C8);
    // 0x8003FDE4: sb          $t7, 0x63($sp)
    MEM_B(0X63, ctx->r29) = ctx->r15;
    // 0x8003FDE8: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x8003FDEC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8003FDF0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8003FDF4: jal         0x80065490
    // 0x8003FDF8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x8003FDF8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    after_0:
    // 0x8003FDFC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8003FE00: jal         0x80065490
    // 0x8003FE04: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x8003FE04: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    after_1:
    // 0x8003FE08: lbu         $a2, 0x63($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X63);
    // 0x8003FE0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003FE10: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8003FE14: slti        $at, $a2, 0x6
    ctx->r1 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
    // 0x8003FE18: bne         $at, $zero, L_8003FE4C
    if (ctx->r1 != 0) {
        // 0x8003FE1C: addiu       $a3, $sp, 0x54
        ctx->r7 = ADD32(ctx->r29, 0X54);
            goto L_8003FE4C;
    }
    // 0x8003FE1C: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x8003FE20: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8003FE24: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x8003FE28: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003FE2C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8003FE30: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003FE34: jal         0x8003F894
    // 0x8003FE38: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_8003F894(rdram, ctx);
        goto after_2;
    // 0x8003FE38: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_2:
    // 0x8003FE3C: bnel        $v0, $zero, L_8003FE98
    if (ctx->r2 != 0) {
        // 0x8003FE40: lw          $v0, 0x180($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X180);
            goto L_8003FE98;
    }
    goto skip_0;
    // 0x8003FE40: lw          $v0, 0x180($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X180);
    skip_0:
    // 0x8003FE44: b           L_8003FFC8
    // 0x8003FE48: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003FFC8;
    // 0x8003FE48: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003FE4C:
    // 0x8003FE4C: jal         0x8003E520
    // 0x8003FE50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003E520(rdram, ctx);
        goto after_3;
    // 0x8003FE50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8003FE54: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8003FE58: sb          $v0, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r2;
    // 0x8003FE5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003FE60: jalr        $t9
    // 0x8003FE64: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8003FE64: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    after_4:
    // 0x8003FE68: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8003FE6C: addiu       $a3, $a3, -0x1A14
    ctx->r7 = ADD32(ctx->r7, -0X1A14);
    // 0x8003FE70: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8003FE74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003FE78: jal         0x8003E658
    // 0x8003FE7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8003E658(rdram, ctx);
        goto after_5;
    // 0x8003FE7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8003FE80: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8003FE84: addiu       $a2, $a2, -0x7C48
    ctx->r6 = ADD32(ctx->r6, -0X7C48);
    // 0x8003FE88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003FE8C: jal         0x8003F14C
    // 0x8003FE90: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_8003F14C(rdram, ctx);
        goto after_6;
    // 0x8003FE90: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_6:
    // 0x8003FE94: lw          $v0, 0x180($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X180);
L_8003FE98:
    // 0x8003FE98: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8003FE9C: beq         $v0, $zero, L_8003FF1C
    if (ctx->r2 == 0) {
        // 0x8003FEA0: nop
    
            goto L_8003FF1C;
    }
    // 0x8003FEA0: nop

    // 0x8003FEA4: lhu         $t2, 0xC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XC);
    // 0x8003FEA8: addiu       $a0, $zero, 0x406C
    ctx->r4 = ADD32(0, 0X406C);
    // 0x8003FEAC: bne         $a0, $t2, L_8003FF00
    if (ctx->r4 != ctx->r10) {
        // 0x8003FEB0: nop
    
            goto L_8003FF00;
    }
    // 0x8003FEB0: nop

    // 0x8003FEB4: lhu         $t3, 0xC($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XC);
    // 0x8003FEB8: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8003FEBC: bne         $a0, $t3, L_8003FECC
    if (ctx->r4 != ctx->r11) {
        // 0x8003FEC0: lw          $a1, 0x0($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X0);
            goto L_8003FECC;
    }
    // 0x8003FEC0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8003FEC4: lw          $t4, 0x1F4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1F4);
    // 0x8003FEC8: sw          $a1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r5;
L_8003FECC:
    // 0x8003FECC: beq         $a1, $zero, L_8003FEFC
    if (ctx->r5 == 0) {
        // 0x8003FED0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8003FEFC;
    }
    // 0x8003FED0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8003FED4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8003FED8: jal         0x80048060
    // 0x8003FEDC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_80048060(rdram, ctx);
        goto after_7;
    // 0x8003FEDC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_7:
    // 0x8003FEE0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8003FEE4: jal         0x80047F9C
    // 0x8003FEE8: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    func_80047F9C(rdram, ctx);
        goto after_8;
    // 0x8003FEE8: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    after_8:
    // 0x8003FEEC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8003FEF0: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8003FEF4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003FEF8: sb          $t5, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r13;
L_8003FEFC:
    // 0x8003FEFC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8003FF00:
    // 0x8003FF00: jal         0x80048060
    // 0x8003FF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048060(rdram, ctx);
        goto after_9;
    // 0x8003FF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8003FF08: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8003FF0C: jal         0x80047F9C
    // 0x8003FF10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_10;
    // 0x8003FF10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x8003FF14: b           L_8003FF28
    // 0x8003FF18: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
        goto L_8003FF28;
    // 0x8003FF18: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
L_8003FF1C:
    // 0x8003FF1C: jal         0x80048114
    // 0x8003FF20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80048114(rdram, ctx);
        goto after_11;
    // 0x8003FF20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x8003FF24: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
L_8003FF28:
    // 0x8003FF28: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003FF2C: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x8003FF30: lbu         $t8, 0x12C8($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X12C8);
    // 0x8003FF34: lhu         $t7, 0x12BE($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X12BE);
    // 0x8003FF38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003FF3C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8003FF40: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8003FF44: andi        $a1, $a1, 0x7
    ctx->r5 = ctx->r5 & 0X7;
    // 0x8003FF48: jal         0x8003E4C8
    // 0x8003FF4C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    func_8003E4C8(rdram, ctx);
        goto after_12;
    // 0x8003FF4C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_12:
    // 0x8003FF50: jal         0x8005FE48
    // 0x8003FF54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_13;
    // 0x8003FF54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8003FF58: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8003FF5C: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x8003FF60: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003FF64: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8003FF68: addiu       $t4, $t4, -0x7630
    ctx->r12 = ADD32(ctx->r12, -0X7630);
    // 0x8003FF6C: sh          $zero, 0x10($t0)
    MEM_H(0X10, ctx->r8) = 0;
    // 0x8003FF70: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8003FF74: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x8003FF78: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8003FF7C: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    // 0x8003FF80: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8003FF84: sw          $zero, 0x44($t2)
    MEM_W(0X44, ctx->r10) = 0;
    // 0x8003FF88: lbu         $t5, 0xE($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XE);
    // 0x8003FF8C: sb          $t3, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r11;
    // 0x8003FF90: sw          $t4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r12;
    // 0x8003FF94: andi        $t6, $t5, 0xFF03
    ctx->r14 = ctx->r13 & 0XFF03;
    // 0x8003FF98: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x8003FF9C: jal         0x8001D770
    // 0x8003FFA0: sb          $t7, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r15;
    func_8001D770(rdram, ctx);
        goto after_14;
    // 0x8003FFA0: sb          $t7, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r15;
    after_14:
    // 0x8003FFA4: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8003FFA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003FFAC: lw          $a1, 0x34($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X34);
    // 0x8003FFB0: jal         0x80067BF8
    // 0x8003FFB4: lw          $a2, 0x38($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_15;
    // 0x8003FFB4: lw          $a2, 0x38($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X38);
    after_15:
    // 0x8003FFB8: addiu       $a0, $zero, 0x21F
    ctx->r4 = ADD32(0, 0X21F);
    // 0x8003FFBC: jal         0x80067818
    // 0x8003FFC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_16;
    // 0x8003FFC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_16:
    // 0x8003FFC4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003FFC8:
    // 0x8003FFC8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003FFCC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8003FFD0: jr          $ra
    // 0x8003FFD4: nop

    return;
    // 0x8003FFD4: nop

;}
RECOMP_FUNC void func_80057754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057754: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80057758: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8005775C: lw          $t6, -0x6DA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DA8);
    // 0x80057760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057764: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x80057768: lbu         $t7, 0x5D($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5D);
    // 0x8005776C: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x80057770: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80057774: jal         0x80058958
    // 0x80057778: sb          $t7, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r15;
    func_80058958(rdram, ctx);
        goto after_0;
    // 0x80057778: sb          $t7, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r15;
    after_0:
    // 0x8005777C: beq         $v0, $zero, L_800577C8
    if (ctx->r2 == 0) {
        // 0x80057780: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_800577C8;
    }
    // 0x80057780: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80057784: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80057788: lw          $t8, -0x7BC4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7BC4);
    // 0x8005778C: lw          $t9, 0x10C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10C);
    // 0x80057790: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80057794: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x80057798: beql        $t1, $zero, L_800577CC
    if (ctx->r9 == 0) {
        // 0x8005779C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800577CC;
    }
    goto skip_0;
    // 0x8005779C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800577A0: lbu         $t2, 0x4($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X4);
    // 0x800577A4: lbu         $t3, 0x5($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X5);
    // 0x800577A8: lbu         $t4, 0x6($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X6);
    // 0x800577AC: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x800577B0: sb          $t3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r11;
    // 0x800577B4: sb          $t4, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r12;
    // 0x800577B8: lbu         $v0, 0x1B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1B);
    // 0x800577BC: sb          $v0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r2;
    // 0x800577C0: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // 0x800577C4: sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
L_800577C8:
    // 0x800577C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800577CC:
    // 0x800577CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800577D0: jr          $ra
    // 0x800577D4: nop

    return;
    // 0x800577D4: nop

;}
RECOMP_FUNC void func_80680DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680DC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80680DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80680DC8: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80680DCC: lui         $at, 0x4328
    ctx->r1 = S32(0X4328 << 16);
    // 0x80680DD0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80680DD4: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x80680DD8: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80680DDC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80680DE0: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80680DE4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80680DE8: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80680DEC: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80680DF0: jal         0x80680D5C
    // 0x80680DF4: swc1        $f16, 0x88($v1)
    MEM_W(0X88, ctx->r3) = ctx->f16.u32l;
    func_80680D5C(rdram, ctx);
        goto after_0;
    // 0x80680DF4: swc1        $f16, 0x88($v1)
    MEM_W(0X88, ctx->r3) = ctx->f16.u32l;
    after_0:
    // 0x80680DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80680DFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80680E00: jr          $ra
    // 0x80680E04: nop

    return;
    // 0x80680E04: nop

;}
RECOMP_FUNC void func_806F23D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F23D4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F23D8: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806F23DC: jr          $ra
    // 0x806F23E0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x806F23E0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80076EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076EDC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80076EE0: lui         $t4, 0xF500
    ctx->r12 = S32(0XF500 << 16);
    // 0x80076EE4: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x80076EE8: andi        $t6, $a1, 0x7
    ctx->r14 = ctx->r5 & 0X7;
    // 0x80076EEC: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x80076EF0: andi        $t9, $a2, 0x3
    ctx->r25 = ctx->r6 & 0X3;
    // 0x80076EF4: sll         $t6, $t9, 19
    ctx->r14 = S32(ctx->r25 << 19);
    // 0x80076EF8: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x80076EFC: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80076F00: sllv        $t9, $a3, $a2
    ctx->r25 = S32(ctx->r7 << (ctx->r6 & 31));
    // 0x80076F04: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80076F08: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80076F0C: addiu       $t9, $t6, 0x7
    ctx->r25 = ADD32(ctx->r14, 0X7);
    // 0x80076F10: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80076F14: andi        $t6, $t8, 0x1FF
    ctx->r14 = ctx->r24 & 0X1FF;
    // 0x80076F18: sll         $t9, $t6, 9
    ctx->r25 = S32(ctx->r14 << 9);
    // 0x80076F1C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80076F20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80076F24: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80076F28: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x80076F2C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076F30: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80076F34: andi        $t0, $t0, 0xF
    ctx->r8 = ctx->r8 & 0XF;
    // 0x80076F38: sll         $t0, $t0, 20
    ctx->r8 = S32(ctx->r8 << 20);
    // 0x80076F3C: or          $t6, $t0, $t5
    ctx->r14 = ctx->r8 | ctx->r13;
    // 0x80076F40: ori         $t7, $t6, 0x200
    ctx->r15 = ctx->r14 | 0X200;
    // 0x80076F44: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80076F48: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80076F4C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80076F50: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x80076F54: addiu       $t2, $a3, -0x1
    ctx->r10 = ADD32(ctx->r7, -0X1);
    // 0x80076F58: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80076F5C: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x80076F60: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80076F64: andi        $t2, $t2, 0xFFF
    ctx->r10 = ctx->r10 & 0XFFF;
    // 0x80076F68: sll         $t2, $t2, 12
    ctx->r10 = S32(ctx->r10 << 12);
    // 0x80076F6C: andi        $t3, $t3, 0xFFF
    ctx->r11 = ctx->r11 & 0XFFF;
    // 0x80076F70: or          $t8, $t2, $t3
    ctx->r24 = ctx->r10 | ctx->r11;
    // 0x80076F74: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x80076F78: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80076F7C: lui         $t1, 0x100
    ctx->r9 = S32(0X100 << 16);
    // 0x80076F80: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076F84: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80076F88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80076F8C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076F90: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80076F94: sll         $t9, $t7, 21
    ctx->r25 = S32(ctx->r15 << 21);
    // 0x80076F98: andi        $t6, $v1, 0x3
    ctx->r14 = ctx->r3 & 0X3;
    // 0x80076F9C: sll         $t7, $t6, 19
    ctx->r15 = S32(ctx->r14 << 19);
    // 0x80076FA0: or          $t8, $t9, $t4
    ctx->r24 = ctx->r25 | ctx->r12;
    // 0x80076FA4: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80076FA8: sllv        $t6, $a3, $v1
    ctx->r14 = S32(ctx->r7 << (ctx->r3 & 31));
    // 0x80076FAC: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80076FB0: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80076FB4: addiu       $t6, $t7, 0x7
    ctx->r14 = ADD32(ctx->r15, 0X7);
    // 0x80076FB8: sra         $t8, $t6, 3
    ctx->r24 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80076FBC: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x80076FC0: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x80076FC4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80076FC8: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80076FCC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80076FD0: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x80076FD4: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80076FD8: or          $t7, $t0, $t1
    ctx->r15 = ctx->r8 | ctx->r9;
    // 0x80076FDC: or          $t8, $t7, $t5
    ctx->r24 = ctx->r15 | ctx->r13;
    // 0x80076FE0: ori         $t9, $t8, 0x200
    ctx->r25 = ctx->r24 | 0X200;
    // 0x80076FE4: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80076FE8: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80076FEC: or          $t7, $t2, $t1
    ctx->r15 = ctx->r10 | ctx->r9;
    // 0x80076FF0: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x80076FF4: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80076FF8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80076FFC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x80077000: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077004: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80077008: jr          $ra
    // 0x8007700C: nop

    return;
    // 0x8007700C: nop

;}
RECOMP_FUNC void func_806CCE78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CCE78: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CCE7C: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x806CCE80: lh          $a1, 0x872($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X872);
    // 0x806CCE84: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x806CCE88: blez        $a1, L_806CCEF4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x806CCE8C: andi        $t6, $a1, 0x4
        ctx->r14 = ctx->r5 & 0X4;
            goto L_806CCEF4;
    }
    // 0x806CCE8C: andi        $t6, $a1, 0x4
    ctx->r14 = ctx->r5 & 0X4;
    // 0x806CCE90: beq         $t6, $zero, L_806CCEBC
    if (ctx->r14 == 0) {
        // 0x806CCE94: addiu       $t1, $zero, 0xF8
        ctx->r9 = ADD32(0, 0XF8);
            goto L_806CCEBC;
    }
    // 0x806CCE94: addiu       $t1, $zero, 0xF8
    ctx->r9 = ADD32(0, 0XF8);
    // 0x806CCE98: addiu       $t8, $zero, 0xF8
    ctx->r24 = ADD32(0, 0XF8);
    // 0x806CCE9C: addiu       $t0, $zero, 0x7C
    ctx->r8 = ADD32(0, 0X7C);
    // 0x806CCEA0: sb          $t8, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r24;
    // 0x806CCEA4: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x806CCEA8: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x806CCEAC: sb          $t0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r8;
    // 0x806CCEB0: sb          $t0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r8;
    // 0x806CCEB4: b           L_806CCEE4
    // 0x806CCEB8: sb          $zero, 0x6($v1)
    MEM_B(0X6, ctx->r3) = 0;
        goto L_806CCEE4;
    // 0x806CCEB8: sb          $zero, 0x6($v1)
    MEM_B(0X6, ctx->r3) = 0;
L_806CCEBC:
    // 0x806CCEBC: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x806CCEC0: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x806CCEC4: addiu       $t4, $zero, 0x7C
    ctx->r12 = ADD32(0, 0X7C);
    // 0x806CCEC8: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x806CCECC: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x806CCED0: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    // 0x806CCED4: sb          $t3, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r11;
    // 0x806CCED8: sb          $t4, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r12;
    // 0x806CCEDC: sb          $zero, 0x5($v1)
    MEM_B(0X5, ctx->r3) = 0;
    // 0x806CCEE0: sb          $t5, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r13;
L_806CCEE4:
    // 0x806CCEE4: lh          $t6, 0x872($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X872);
    // 0x806CCEE8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x806CCEEC: jr          $ra
    // 0x806CCEF0: sh          $t7, 0x872($v0)
    MEM_H(0X872, ctx->r2) = ctx->r15;
    return;
    // 0x806CCEF0: sh          $t7, 0x872($v0)
    MEM_H(0X872, ctx->r2) = ctx->r15;
L_806CCEF4:
    // 0x806CCEF4: sh          $zero, 0x872($v0)
    MEM_H(0X872, ctx->r2) = 0;
    // 0x806CCEF8: jr          $ra
    // 0x806CCEFC: nop

    return;
    // 0x806CCEFC: nop

;}
RECOMP_FUNC void floor_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081FEC: floor.w.d   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = S32(floor(ctx->f12.d));
    // 0x80081FF0: jr          $ra
    // 0x80081FF4: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
    return;
    // 0x80081FF4: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
;}
RECOMP_FUNC void func_80048F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048F84: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80048F88: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x80048F8C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80048F90: lwc1        $f2, 0x18($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80048F94: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80048F98: nop

    // 0x80048F9C: bc1fl       L_80048FD4
    if (!c1cs) {
        // 0x80048FA0: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80048FD4;
    }
    goto skip_0;
    // 0x80048FA0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x80048FA4: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80048FA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80048FAC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80048FB0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80048FB4: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80048FB8: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x80048FBC: nop

    // 0x80048FC0: bc1fl       L_80049010
    if (!c1cs) {
        // 0x80048FC4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80049010;
    }
    goto skip_1;
    // 0x80048FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80048FC8: jr          $ra
    // 0x80048FCC: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    return;
    // 0x80048FCC: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x80048FD0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80048FD4:
    // 0x80048FD4: nop

    // 0x80048FD8: bc1fl       L_80049010
    if (!c1cs) {
        // 0x80048FDC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80049010;
    }
    goto skip_2;
    // 0x80048FDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80048FE0: lwc1        $f10, 0x24($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80048FE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80048FE8: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80048FEC: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x80048FF0: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80048FF4: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x80048FF8: nop

    // 0x80048FFC: bc1fl       L_80049010
    if (!c1cs) {
        // 0x80049000: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80049010;
    }
    goto skip_3;
    // 0x80049000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x80049004: jr          $ra
    // 0x80049008: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    return;
    // 0x80049008: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x8004900C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80049010:
    // 0x80049010: jr          $ra
    // 0x80049014: nop

    return;
    // 0x80049014: nop

;}
RECOMP_FUNC void func_804BD718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BD71C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD720: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X419C) << 16);
    // 0x804BD724: lwc1        $f4, -0x534($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X419C));
    // 0x804BD728: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x804BD72C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41A0) << 16);
    // 0x804BD730: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804BD734: nop

    // 0x804BD738: bc1tl       L_804BD760
    if (c1cs) {
        // 0x804BD73C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BD760;
    }
    goto skip_0;
    // 0x804BD73C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BD740: lwc1        $f6, -0x530($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41A0));
    // 0x804BD744: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804BD748: nop

    // 0x804BD74C: bc1tl       L_804BD760
    if (c1cs) {
        // 0x804BD750: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BD760;
    }
    goto skip_1;
    // 0x804BD750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804BD754: jal         0x804BD6D8
    // 0x804BD758: nop

    func_804BD6D8(rdram, ctx);
        goto after_0;
    // 0x804BD758: nop

    after_0:
    // 0x804BD75C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BD760:
    // 0x804BD760: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BD764: jr          $ra
    // 0x804BD768: nop

    return;
    // 0x804BD768: nop

;}
RECOMP_FUNC void func_8040C758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040C75C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040C760: jal         0x8005780C
    // 0x8040C764: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    func_8005780C(rdram, ctx);
        goto after_0;
    // 0x8040C764: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8040C768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040C76C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040C770: jr          $ra
    // 0x8040C774: nop

    return;
    // 0x8040C774: nop

;}
RECOMP_FUNC void func_806D0E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0E28: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806D0E2C: lui         $t6, 0x806D
    ctx->r14 = S32(RELOC_HI16(607, 0X136C) << 16);
    // 0x806D0E30: addiu       $t6, $t6, 0xB0C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(607, 0X136C));
    // 0x806D0E34: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806D0E38: jr          $ra
    // 0x806D0E3C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806D0E3C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_807924DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807924DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807924E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807924E4: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807924E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807924EC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x807924F0: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x807924F4: bnel        $at, $zero, L_80792534
    if (ctx->r1 != 0) {
        // 0x807924F8: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_80792534;
    }
    goto skip_0;
    // 0x807924F8: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x807924FC: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80792500: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x80792504: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80792508: jal         0x8079393C
    // 0x8079250C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8079393C(rdram, ctx);
        goto after_0;
    // 0x8079250C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80792510: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80792514: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80792518: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8079251C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80792520: jal         0x807923A0
    // 0x80792524: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    func_807923A0(rdram, ctx);
        goto after_1;
    // 0x80792524: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    after_1:
    // 0x80792528: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8079252C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80792530: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
L_80792534:
    // 0x80792534: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x80792538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079253C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80792540: jr          $ra
    // 0x80792544: nop

    return;
    // 0x80792544: nop

;}
RECOMP_FUNC void func_80037F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037F30: jal         0x800238A8
    // 0x80037F34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800238A8(rdram, ctx);
        goto after_0;
    // 0x80037F34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80037F38: jal         0x80023EA0
    // 0x80037F3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80023EA0(rdram, ctx);
        goto after_1;
    // 0x80037F3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80037F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80037F48: jr          $ra
    // 0x80037F4C: nop

    return;
    // 0x80037F4C: nop

;}
RECOMP_FUNC void gfxprint_vprintf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FA8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007FA90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FA94: jal         0x80082140
    // 0x8007FA98: nop

    vaprintf(rdram, ctx);
        goto after_0;
    // 0x8007FA98: nop

    after_0:
    // 0x8007FA9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FAA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007FAA4: jr          $ra
    // 0x8007FAA8: nop

    return;
    // 0x8007FAA8: nop

;}
RECOMP_FUNC void func_8040B4B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B4B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040B4BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040B4C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040B4C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040B4C8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8040B4CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8040B4D0: jal         0x80048F84
    // 0x8040B4D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8040B4D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8040B4D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8040B4DC: jal         0x80048F84
    // 0x8040B4E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8040B4E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8040B4E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040B4E8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8040B4EC: jal         0x800474D8
    // 0x8040B4F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800474D8(rdram, ctx);
        goto after_2;
    // 0x8040B4F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8040B4F4: beq         $v0, $zero, L_8040B510
    if (ctx->r2 == 0) {
        // 0x8040B4F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8040B510;
    }
    // 0x8040B4F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040B4FC: jal         0x8040B478
    // 0x8040B500: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8040B478(rdram, ctx);
        goto after_3;
    // 0x8040B500: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8040B504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040B508: jal         0x8040B590
    // 0x8040B50C: lw          $a1, 0x138($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X138);
    func_8040B590(rdram, ctx);
        goto after_4;
    // 0x8040B50C: lw          $a1, 0x138($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X138);
    after_4:
L_8040B510:
    // 0x8040B510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8040B514: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040B518: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8040B51C: jr          $ra
    // 0x8040B520: nop

    return;
    // 0x8040B520: nop

;}
RECOMP_FUNC void func_806EE640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE640: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EE644: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    // 0x806EE648: lh          $t6, 0x12($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X12);
    // 0x806EE64C: sh          $t6, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r14;
    // 0x806EE650: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x806EE654: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    // 0x806EE658: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806EE65C: jr          $ra
    // 0x806EE660: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x806EE660: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_804F3A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F3A30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804F3A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F3A38: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x804F3A3C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x804F3A40: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F3A44: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x804F3A48: jal         0x8005780C
    // 0x804F3A4C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8005780C(rdram, ctx);
        goto after_0;
    // 0x804F3A4C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x804F3A50: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804F3A54: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x804F3A58: beql        $v1, $zero, L_804F3AB4
    if (ctx->r3 == 0) {
        // 0x804F3A5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804F3AB4;
    }
    goto skip_0;
    // 0x804F3A5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804F3A60: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x804F3A64: addiu       $at, $zero, 0x404C
    ctx->r1 = ADD32(0, 0X404C);
    // 0x804F3A68: beq         $v0, $at, L_804F3A80
    if (ctx->r2 == ctx->r1) {
        // 0x804F3A6C: addiu       $at, $zero, 0x404E
        ctx->r1 = ADD32(0, 0X404E);
            goto L_804F3A80;
    }
    // 0x804F3A6C: addiu       $at, $zero, 0x404E
    ctx->r1 = ADD32(0, 0X404E);
    // 0x804F3A70: beql        $v0, $at, L_804F3A9C
    if (ctx->r2 == ctx->r1) {
        // 0x804F3A74: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_804F3A9C;
    }
    goto skip_1;
    // 0x804F3A74: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    skip_1:
    // 0x804F3A78: b           L_804F3AB4
    // 0x804F3A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804F3AB4;
    // 0x804F3A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804F3A80:
    // 0x804F3A80: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x804F3A84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804F3A88: lwc1        $f4, 0x50($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X50);
    // 0x804F3A8C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804F3A90: b           L_804F3AB0
    // 0x804F3A94: swc1        $f8, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f8.u32l;
        goto L_804F3AB0;
    // 0x804F3A94: swc1        $f8, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f8.u32l;
    // 0x804F3A98: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_804F3A9C:
    // 0x804F3A9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804F3AA0: lwc1        $f10, 0x50($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X50);
    // 0x804F3AA4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804F3AA8: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x804F3AAC: swc1        $f4, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f4.u32l;
L_804F3AB0:
    // 0x804F3AB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804F3AB4:
    // 0x804F3AB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804F3AB8: jr          $ra
    // 0x804F3ABC: nop

    return;
    // 0x804F3ABC: nop

;}
RECOMP_FUNC void func_8000D81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D81C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000D820: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8000D824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000D828: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8000D82C: lw          $a2, 0x50($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X50);
    // 0x8000D830: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000D834: addiu       $a0, $a0, -0x63C4
    ctx->r4 = ADD32(ctx->r4, -0X63C4);
    // 0x8000D838: beq         $a2, $zero, L_8000D85C
    if (ctx->r6 == 0) {
        // 0x8000D83C: addiu       $a1, $a2, 0x70
        ctx->r5 = ADD32(ctx->r6, 0X70);
            goto L_8000D85C;
    }
    // 0x8000D83C: addiu       $a1, $a2, 0x70
    ctx->r5 = ADD32(ctx->r6, 0X70);
    // 0x8000D840: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8000D844: jal         0x8000DB94
    // 0x8000D848: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_8000DB94(rdram, ctx);
        goto after_0;
    // 0x8000D848: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000D84C: jal         0x8000D7E0
    // 0x8000D850: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8000D7E0(rdram, ctx);
        goto after_1;
    // 0x8000D850: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8000D854: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8000D858: sw          $zero, 0x50($v0)
    MEM_W(0X50, ctx->r2) = 0;
L_8000D85C:
    // 0x8000D85C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000D860: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000D864: jr          $ra
    // 0x8000D868: nop

    return;
    // 0x8000D868: nop

;}
RECOMP_FUNC void func_8073EED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EED0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8073EED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073EED8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073EEDC: addiu       $a0, $zero, 0x4648
    ctx->r4 = ADD32(0, 0X4648);
    // 0x8073EEE0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8073EEE4: jal         0x80047090
    // 0x8073EEE8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8073EEE8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x8073EEEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8073EEF0: lui         $at, 0x4648
    ctx->r1 = S32(0X4648 << 16);
    // 0x8073EEF4: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8073EEF8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8073EEFC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8073EF00: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8073EF04: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x8073EF08: jal         0x8004613C
    // 0x8073EF0C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8073EF0C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x8073EF10: bne         $v0, $zero, L_8073EF20
    if (ctx->r2 != 0) {
        // 0x8073EF14: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8073EF20;
    }
    // 0x8073EF14: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8073EF18: b           L_8073EF50
    // 0x8073EF1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8073EF50;
    // 0x8073EF1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073EF20:
    // 0x8073EF20: lhu         $t9, 0x1E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X1E);
    // 0x8073EF24: lhu         $t1, 0xE($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0XE);
    // 0x8073EF28: andi        $t0, $t9, 0x3FF
    ctx->r8 = ctx->r25 & 0X3FF;
    // 0x8073EF2C: andi        $t2, $t1, 0xFC00
    ctx->r10 = ctx->r9 & 0XFC00;
    // 0x8073EF30: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x8073EF34: sh          $t3, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r11;
    // 0x8073EF38: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8073EF3C: jal         0x80047F9C
    // 0x8073EF40: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8073EF40: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8073EF44: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8073EF48: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8073EF4C: sb          $t4, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r12;
L_8073EF50:
    // 0x8073EF50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073EF54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8073EF58: jr          $ra
    // 0x8073EF5C: nop

    return;
    // 0x8073EF5C: nop

;}
RECOMP_FUNC void func_80472738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80472738: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8047273C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80472740: jal         0x8004700C
    // 0x80472744: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80472744: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80472748: beq         $v0, $zero, L_80472798
    if (ctx->r2 == 0) {
        // 0x8047274C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80472798;
    }
    // 0x8047274C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80472750: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80472754: lw          $t8, 0x180($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X180);
    // 0x80472758: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x8047275C: bnel        $t7, $t8, L_8047279C
    if (ctx->r15 != ctx->r24) {
        // 0x80472760: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8047279C;
    }
    goto skip_0;
    // 0x80472760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80472764: lw          $t9, 0x138($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X138);
    // 0x80472768: beql        $t9, $zero, L_80472788
    if (ctx->r25 == 0) {
        // 0x8047276C: lw          $t1, 0x174($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X174);
            goto L_80472788;
    }
    goto skip_1;
    // 0x8047276C: lw          $t1, 0x174($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X174);
    skip_1:
    // 0x80472770: lw          $t0, 0x174($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X174);
    // 0x80472774: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x80472778: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x8047277C: b           L_8047279C
    // 0x80472780: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
        goto L_8047279C;
    // 0x80472780: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x80472784: lw          $t1, 0x174($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X174);
L_80472788:
    // 0x80472788: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x8047278C: lw          $v0, 0x8($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X8);
    // 0x80472790: b           L_8047279C
    // 0x80472794: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
        goto L_8047279C;
    // 0x80472794: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
L_80472798:
    // 0x80472798: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8047279C:
    // 0x8047279C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804727A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804727A4: jr          $ra
    // 0x804727A8: nop

    return;
    // 0x804727A8: nop

;}
RECOMP_FUNC void func_80052600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052600: addiu       $sp, $sp, -0x430
    ctx->r29 = ADD32(ctx->r29, -0X430);
    // 0x80052604: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80052608: jal         0x80052530
    // 0x8005260C: nop

    func_80052530(rdram, ctx);
        goto after_0;
    // 0x8005260C: nop

    after_0:
    // 0x80052610: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80052614: addiu       $t6, $t6, 0xAD0
    ctx->r14 = ADD32(ctx->r14, 0XAD0);
    // 0x80052618: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005261C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80052620: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x80052624: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x80052628: addiu       $t7, $sp, 0x42C
    ctx->r15 = ADD32(ctx->r29, 0X42C);
    // 0x8005262C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80052630: addiu       $a3, $a3, 0xAC0
    ctx->r7 = ADD32(ctx->r7, 0XAC0);
    // 0x80052634: lw          $a2, 0x5CC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5CC4);
    // 0x80052638: lhu         $a1, 0x5CC0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X5CC0);
    // 0x8005263C: addiu       $a0, $a0, -0x4D70
    ctx->r4 = ADD32(ctx->r4, -0X4D70);
    // 0x80052640: jal         0x800892E0
    // 0x80052644: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    osPfsFindFile_recomp(rdram, ctx);
        goto after_1;
    // 0x80052644: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x80052648: or          $a0, $sp, $zero
    ctx->r4 = ctx->r29 | 0;
    // 0x8005264C: addiu       $a0, $a0, 0x27
    ctx->r4 = ADD32(ctx->r4, 0X27);
    // 0x80052650: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x80052654: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80052658: lw          $a1, 0x42C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X42C);
    // 0x8005265C: jal         0x80052300
    // 0x80052660: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80052300(rdram, ctx);
        goto after_2;
    // 0x80052660: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80052664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80052668: addiu       $sp, $sp, 0x430
    ctx->r29 = ADD32(ctx->r29, 0X430);
    // 0x8005266C: jr          $ra
    // 0x80052670: nop

    return;
    // 0x80052670: nop

;}
RECOMP_FUNC void func_80048DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048DE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048DEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048DF0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80048DF4: jal         0x80048D74
    // 0x80048DF8: addiu       $a1, $a1, 0x47C8
    ctx->r5 = ADD32(ctx->r5, 0X47C8);
    func_80048D74(rdram, ctx);
        goto after_0;
    // 0x80048DF8: addiu       $a1, $a1, 0x47C8
    ctx->r5 = ADD32(ctx->r5, 0X47C8);
    after_0:
    // 0x80048DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048E00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048E04: jr          $ra
    // 0x80048E08: nop

    return;
    // 0x80048E08: nop

;}
RECOMP_FUNC void func_806E9290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E9290: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x806E9294: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x806E9298: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x806E929C: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x806E92A0: andi        $t7, $t6, 0x3000
    ctx->r15 = ctx->r14 & 0X3000;
    // 0x806E92A4: bne         $t7, $zero, L_806E92BC
    if (ctx->r15 != 0) {
        // 0x806E92A8: nop
    
            goto L_806E92BC;
    }
    // 0x806E92A8: nop

    // 0x806E92AC: lw          $t8, 0x28($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X28);
    // 0x806E92B0: andi        $t9, $t8, 0x3000
    ctx->r25 = ctx->r24 & 0X3000;
    // 0x806E92B4: beql        $t9, $zero, L_806E92C8
    if (ctx->r25 == 0) {
        // 0x806E92B8: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_806E92C8;
    }
    goto skip_0;
    // 0x806E92B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
L_806E92BC:
    // 0x806E92BC: jr          $ra
    // 0x806E92C0: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
    return;
    // 0x806E92C0: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
    // 0x806E92C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_806E92C8:
    // 0x806E92C8: lwc1        $f4, 0x40($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X40);
    // 0x806E92CC: addiu       $v1, $a1, 0xC4
    ctx->r3 = ADD32(ctx->r5, 0XC4);
    // 0x806E92D0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x806E92D4: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x806E92D8: bc1f        L_806E9348
    if (!c1cs) {
        // 0x806E92DC: swc1        $f6, 0x40($a1)
        MEM_W(0X40, ctx->r5) = ctx->f6.u32l;
            goto L_806E9348;
    }
    // 0x806E92DC: swc1        $f6, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f6.u32l;
    // 0x806E92E0: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806E92E4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x806E92E8: nop

    // 0x806E92EC: bc1f        L_806E9348
    if (!c1cs) {
        // 0x806E92F0: nop
    
            goto L_806E9348;
    }
    // 0x806E92F0: nop

    // 0x806E92F4: lw          $t1, 0x34($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X34);
    // 0x806E92F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806E92FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806E9300: ori         $t2, $t1, 0x700
    ctx->r10 = ctx->r9 | 0X700;
    // 0x806E9304: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
    // 0x806E9308: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806E930C: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16E8) << 16);
    // 0x806E9310: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806E9314: nop

    // 0x806E9318: bc1f        L_806E9348
    if (!c1cs) {
        // 0x806E931C: nop
    
            goto L_806E9348;
    }
    // 0x806E931C: nop

    // 0x806E9320: lwc1        $f10, -0x6668($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16E8));
    // 0x806E9324: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x806E9328: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x806E932C: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x806E9330: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806E9334: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x806E9338: nop

    // 0x806E933C: bc1f        L_806E9348
    if (!c1cs) {
        // 0x806E9340: nop
    
            goto L_806E9348;
    }
    // 0x806E9340: nop

    // 0x806E9344: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_806E9348:
    // 0x806E9348: jr          $ra
    // 0x806E934C: nop

    return;
    // 0x806E934C: nop

;}
RECOMP_FUNC void func_80519358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051935C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80519360: jal         0x8004700C
    // 0x80519364: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80519364: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80519368: beq         $v0, $zero, L_805193A4
    if (ctx->r2 == 0) {
        // 0x8051936C: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_805193A4;
    }
    // 0x8051936C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80519370: lwc1        $f4, 0x84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
    // 0x80519374: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80519378: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8051937C: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(291, 0X2450) << 16);
    // 0x80519380: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80519384: nop

    // 0x80519388: bc1fl       L_80519398
    if (!c1cs) {
        // 0x8051938C: sll         $t7, $t6, 2
        ctx->r15 = S32(ctx->r14 << 2);
            goto L_80519398;
    }
    goto skip_0;
    // 0x8051938C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    skip_0:
    // 0x80519390: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80519394: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
L_80519398:
    // 0x80519398: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8051939C: lw          $t8, -0x5F40($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(291, 0X2450));
    // 0x805193A0: sw          $t8, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r24;
L_805193A4:
    // 0x805193A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805193A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805193AC: jr          $ra
    // 0x805193B0: nop

    return;
    // 0x805193B0: nop

;}
RECOMP_FUNC void func_800490A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800490A8: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800490AC: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800490B0: bgez        $t6, L_800490C0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800490B4: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_800490C0;
    }
    // 0x800490B4: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800490B8: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x800490BC: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800490C0:
    // 0x800490C0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800490C4: nop

    // 0x800490C8: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800490CC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800490D0: jr          $ra
    // 0x800490D4: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
    return;
    // 0x800490D4: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
;}
RECOMP_FUNC void func_8000AA78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AA78: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000AA7C: jr          $ra
    // 0x8000AA80: sw          $zero, 0x6BC8($at)
    MEM_W(0X6BC8, ctx->r1) = 0;
    return;
    // 0x8000AA80: sw          $zero, 0x6BC8($at)
    MEM_W(0X6BC8, ctx->r1) = 0;
;}
RECOMP_FUNC void func_8006899C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006899C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800689A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800689A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800689A8: jal         0x80068340
    // 0x800689AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80068340(rdram, ctx);
        goto after_0;
    // 0x800689AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800689B0: jal         0x8006C848
    // 0x800689B4: lw          $a0, 0x3F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3F4);
    func_8006C848(rdram, ctx);
        goto after_1;
    // 0x800689B4: lw          $a0, 0x3F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3F4);
    after_1:
    // 0x800689B8: jal         0x8005A484
    // 0x800689BC: lw          $a0, 0x478($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X478);
    func_8005A484(rdram, ctx);
        goto after_2;
    // 0x800689BC: lw          $a0, 0x478($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X478);
    after_2:
    // 0x800689C0: jal         0x80044B80
    // 0x800689C4: addiu       $a0, $s0, 0x958
    ctx->r4 = ADD32(ctx->r16, 0X958);
    func_80044B80(rdram, ctx);
        goto after_3;
    // 0x800689C4: addiu       $a0, $s0, 0x958
    ctx->r4 = ADD32(ctx->r16, 0X958);
    after_3:
    // 0x800689C8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800689CC: jal         0x8005F7D8
    // 0x800689D0: addiu       $a0, $s0, 0x9C8
    ctx->r4 = ADD32(ctx->r16, 0X9C8);
    func_8005F7D8(rdram, ctx);
        goto after_4;
    // 0x800689D0: addiu       $a0, $s0, 0x9C8
    ctx->r4 = ADD32(ctx->r16, 0X9C8);
    after_4:
    // 0x800689D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800689D8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800689DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800689E0: jr          $ra
    // 0x800689E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800689E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806DB6C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DB6C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806DB6C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DB6C8: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806DB6CC: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(634, 0X680) << 16);
    // 0x806DB6D0: lwc1        $f10, -0x44C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(634, 0X680));
    // 0x806DB6D4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x806DB6D8: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806DB6DC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806DB6E0: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x806DB6E4: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x806DB6E8: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x806DB6EC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806DB6F0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x806DB6F4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806DB6F8: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x806DB6FC: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806DB700: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x806DB704: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806DB708: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x806DB70C: lwc1        $f6, 0x74($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X74);
    // 0x806DB710: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x806DB714: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x806DB718: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x806DB71C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x806DB720: lw          $t9, 0x84($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X84);
    // 0x806DB724: jalr        $t9
    // 0x806DB728: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806DB728: nop

    after_0:
    // 0x806DB72C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x806DB730: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x806DB734: jal         0x80067BBC
    // 0x806DB738: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x806DB738: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_1:
    // 0x806DB73C: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x806DB740: jal         0x80067818
    // 0x806DB744: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x806DB744: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x806DB748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DB74C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x806DB750: jr          $ra
    // 0x806DB754: nop

    return;
    // 0x806DB754: nop

;}
RECOMP_FUNC void func_80432B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432B64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80432B68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80432B6C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80432B70: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80432B74: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80432B78: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(62, 0X550) << 16);
    // 0x80432B7C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80432B80: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80432B84: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80432B88: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80432B8C: lw          $t8, 0x2CF0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(62, 0X550));
    // 0x80432B90: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80432B94: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80432B98: jal         0x80048490
    // 0x80432B9C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80432B9C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80432BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80432BA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80432BA8: jr          $ra
    // 0x80432BAC: nop

    return;
    // 0x80432BAC: nop

;}
RECOMP_FUNC void func_806A99EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A99EC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806A99F0: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806A99F4: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(589, 0X11E0) << 16);
    // 0x806A99F8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806A99FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806A9A00: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
    // 0x806A9A04: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806A9A08: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806A9A0C: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x806A9A10: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x806A9A14: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806A9A18: lwc1        $f6, -0x5660($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(589, 0X11E0));
    // 0x806A9A1C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x806A9A20: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806A9A24: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x806A9A28: jr          $ra
    // 0x806A9A2C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x806A9A2C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_8006509C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006509C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800650A0: addiu       $v0, $v0, 0x65C0
    ctx->r2 = ADD32(ctx->r2, 0X65C0);
    // 0x800650A4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800650A8: jr          $ra
    // 0x800650AC: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    return;
    // 0x800650AC: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_80580C08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580C08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580C10: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80580C14: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80580C18: lui         $t7, 0x8058
    ctx->r15 = S32(RELOC_HI16(399, 0X45E8) << 16);
    // 0x80580C1C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80580C20: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80580C24: addiu       $t7, $t7, 0x33F8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(399, 0X45E8));
    // 0x80580C28: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80580C2C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80580C30: jal         0x80580B68
    // 0x80580C34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80580B68(rdram, ctx);
        goto after_0;
    // 0x80580C34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80580C38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80580C3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80580C40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80580C44: jal         0x80580BA4
    // 0x80580C48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80580BA4(rdram, ctx);
        goto after_1;
    // 0x80580C48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80580C4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80580C50: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80580C54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80580C58: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80580C5C: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80580C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80580C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80580C68: jr          $ra
    // 0x80580C6C: nop

    return;
    // 0x80580C6C: nop

;}
RECOMP_FUNC void func_80799478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079947C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799480: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80799484: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80799488: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8079948C: slti        $at, $v0, 0x471D
    ctx->r1 = SIGNED(ctx->r2) < 0X471D ? 1 : 0;
    // 0x80799490: bne         $at, $zero, L_807994B0
    if (ctx->r1 != 0) {
        // 0x80799494: addiu       $at, $zero, 0x471D
        ctx->r1 = ADD32(0, 0X471D);
            goto L_807994B0;
    }
    // 0x80799494: addiu       $at, $zero, 0x471D
    ctx->r1 = ADD32(0, 0X471D);
    // 0x80799498: beq         $v0, $at, L_8079950C
    if (ctx->r2 == ctx->r1) {
        // 0x8079949C: addiu       $at, $zero, 0x471E
        ctx->r1 = ADD32(0, 0X471E);
            goto L_8079950C;
    }
    // 0x8079949C: addiu       $at, $zero, 0x471E
    ctx->r1 = ADD32(0, 0X471E);
    // 0x807994A0: beql        $v0, $at, L_80799510
    if (ctx->r2 == ctx->r1) {
        // 0x807994A4: lhu         $v0, 0xC($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0XC);
            goto L_80799510;
    }
    goto skip_0;
    // 0x807994A4: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    skip_0:
    // 0x807994A8: b           L_80799548
    // 0x807994AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80799548;
    // 0x807994AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807994B0:
    // 0x807994B0: slti        $at, $v0, 0x46E2
    ctx->r1 = SIGNED(ctx->r2) < 0X46E2 ? 1 : 0;
    // 0x807994B4: bne         $at, $zero, L_807994CC
    if (ctx->r1 != 0) {
        // 0x807994B8: addiu       $at, $zero, 0x471C
        ctx->r1 = ADD32(0, 0X471C);
            goto L_807994CC;
    }
    // 0x807994B8: addiu       $at, $zero, 0x471C
    ctx->r1 = ADD32(0, 0X471C);
    // 0x807994BC: beql        $v0, $at, L_80799510
    if (ctx->r2 == ctx->r1) {
        // 0x807994C0: lhu         $v0, 0xC($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0XC);
            goto L_80799510;
    }
    goto skip_1;
    // 0x807994C0: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    skip_1:
    // 0x807994C4: b           L_80799548
    // 0x807994C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80799548;
    // 0x807994C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807994CC:
    // 0x807994CC: slti        $at, $v0, 0x46B9
    ctx->r1 = SIGNED(ctx->r2) < 0X46B9 ? 1 : 0;
    // 0x807994D0: bne         $at, $zero, L_807994EC
    if (ctx->r1 != 0) {
        // 0x807994D4: addiu       $t6, $v0, -0x469B
        ctx->r14 = ADD32(ctx->r2, -0X469B);
            goto L_807994EC;
    }
    // 0x807994D4: addiu       $t6, $v0, -0x469B
    ctx->r14 = ADD32(ctx->r2, -0X469B);
    // 0x807994D8: addiu       $at, $zero, 0x46E1
    ctx->r1 = ADD32(0, 0X46E1);
    // 0x807994DC: beql        $v0, $at, L_80799510
    if (ctx->r2 == ctx->r1) {
        // 0x807994E0: lhu         $v0, 0xC($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0XC);
            goto L_80799510;
    }
    goto skip_2;
    // 0x807994E0: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    skip_2:
    // 0x807994E4: b           L_80799548
    // 0x807994E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80799548;
    // 0x807994E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807994EC:
    // 0x807994EC: sltiu       $at, $t6, 0x1E
    ctx->r1 = ctx->r14 < 0X1E ? 1 : 0;
    // 0x807994F0: beq         $at, $zero, L_80799544
    if (ctx->r1 == 0) {
        // 0x807994F4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80799544;
    }
    // 0x807994F4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x807994F8: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X25FC) << 16);
    // 0x807994FC: addu        $at, $at, $t6
    gpr jr_addend_80799504 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80799500: lw          $t6, -0x4EE4($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(826, 0X25FC));
    // 0x80799504: jr          $t6
    // 0x80799508: nop

    switch (jr_addend_80799504 >> 2) {
        case 0: goto L_8079950C; break;
        case 1: goto L_80799544; break;
        case 2: goto L_80799544; break;
        case 3: goto L_80799544; break;
        case 4: goto L_80799544; break;
        case 5: goto L_80799544; break;
        case 6: goto L_80799544; break;
        case 7: goto L_80799544; break;
        case 8: goto L_80799544; break;
        case 9: goto L_80799544; break;
        case 10: goto L_80799544; break;
        case 11: goto L_80799544; break;
        case 12: goto L_80799544; break;
        case 13: goto L_80799544; break;
        case 14: goto L_80799544; break;
        case 15: goto L_80799544; break;
        case 16: goto L_80799544; break;
        case 17: goto L_80799544; break;
        case 18: goto L_80799544; break;
        case 19: goto L_80799544; break;
        case 20: goto L_80799544; break;
        case 21: goto L_80799544; break;
        case 22: goto L_80799544; break;
        case 23: goto L_80799544; break;
        case 24: goto L_80799544; break;
        case 25: goto L_8079950C; break;
        case 26: goto L_8079950C; break;
        case 27: goto L_8079950C; break;
        case 28: goto L_8079950C; break;
        case 29: goto L_8079950C; break;
        default: switch_error(__func__, 0x80799504, 0x8079B11C);
    }
    // 0x80799508: nop

L_8079950C:
    // 0x8079950C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
L_80799510:
    // 0x80799510: addiu       $at, $zero, 0x46B2
    ctx->r1 = ADD32(0, 0X46B2);
    // 0x80799514: beq         $v0, $at, L_8079952C
    if (ctx->r2 == ctx->r1) {
        // 0x80799518: addiu       $at, $zero, 0x46B3
        ctx->r1 = ADD32(0, 0X46B3);
            goto L_8079952C;
    }
    // 0x80799518: addiu       $at, $zero, 0x46B3
    ctx->r1 = ADD32(0, 0X46B3);
    // 0x8079951C: beq         $v0, $at, L_8079953C
    if (ctx->r2 == ctx->r1) {
        // 0x80799520: nop
    
            goto L_8079953C;
    }
    // 0x80799520: nop

    // 0x80799524: b           L_80799548
    // 0x80799528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80799548;
    // 0x80799528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079952C:
    // 0x8079952C: jal         0x80799364
    // 0x80799530: nop

    func_80799364(rdram, ctx);
        goto after_0;
    // 0x80799530: nop

    after_0:
    // 0x80799534: b           L_80799548
    // 0x80799538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80799548;
    // 0x80799538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079953C:
    // 0x8079953C: jal         0x80799430
    // 0x80799540: nop

    func_80799430(rdram, ctx);
        goto after_1;
    // 0x80799540: nop

    after_1:
L_80799544:
    // 0x80799544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80799548:
    // 0x80799548: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079954C: jr          $ra
    // 0x80799550: nop

    return;
    // 0x80799550: nop

;}
RECOMP_FUNC void func_80011484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001148C: jal         0x800109DC
    // 0x80011490: nop

    func_800109DC(rdram, ctx);
        goto after_0;
    // 0x80011490: nop

    after_0:
    // 0x80011494: beq         $v0, $zero, L_800114D8
    if (ctx->r2 == 0) {
        // 0x80011498: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800114D8;
    }
    // 0x80011498: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001149C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800114A0: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x800114A4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800114A8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800114AC: beq         $v0, $zero, L_800114CC
    if (ctx->r2 == 0) {
        // 0x800114B0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800114CC;
    }
    // 0x800114B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800114B4: lbu         $t6, -0x6D9C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6D9C);
    // 0x800114B8: bne         $t6, $zero, L_800114CC
    if (ctx->r14 != 0) {
        // 0x800114BC: nop
    
            goto L_800114CC;
    }
    // 0x800114BC: nop

    // 0x800114C0: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800114C4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800114C8: sh          $t7, -0x5AE0($at)
    MEM_H(-0X5AE0, ctx->r1) = ctx->r15;
L_800114CC:
    // 0x800114CC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800114D0: jal         0x80011600
    // 0x800114D4: sb          $t8, -0x6D9C($at)
    MEM_B(-0X6D9C, ctx->r1) = ctx->r24;
    func_80011600(rdram, ctx);
        goto after_1;
    // 0x800114D4: sb          $t8, -0x6D9C($at)
    MEM_B(-0X6D9C, ctx->r1) = ctx->r24;
    after_1:
L_800114D8:
    // 0x800114D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800114DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800114E0: jr          $ra
    // 0x800114E4: nop

    return;
    // 0x800114E4: nop

;}
