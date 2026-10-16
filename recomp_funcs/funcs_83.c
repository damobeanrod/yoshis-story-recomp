#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80736B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736B28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80736B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736B30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80736B34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80736B38: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80736B3C: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x80736B40: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80736B44: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80736B48: bne         $v0, $at, L_80736B60
    if (ctx->r2 != ctx->r1) {
        // 0x80736B4C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80736B60;
    }
    // 0x80736B4C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80736B50: jal         0x8002F6E4
    // 0x80736B54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x80736B54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80736B58: jal         0x8073605C
    // 0x80736B5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8073605C(rdram, ctx);
        goto after_1;
    // 0x80736B5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80736B60:
    // 0x80736B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80736B64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80736B68: jr          $ra
    // 0x80736B6C: nop

    return;
    // 0x80736B6C: nop

;}
RECOMP_FUNC void tmemLoad_A(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80082FC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082FCC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80082FD0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80082FD4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80082FD8: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x80082FDC: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80082FE0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80082FE4: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x80082FE8: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80082FEC: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80082FF0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80082FF4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80082FF8: lw          $t3, -0xEFC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XEFC);
    // 0x80082FFC: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x80083000: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80083004: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x80083008: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x8008300C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80083010: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80083014: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80083018: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8008301C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80083020: jal         0x80082F38
    // 0x80083024: lh          $a3, 0x2A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2A);
    tmemLoad_B(rdram, ctx);
        goto after_0;
    // 0x80083024: lh          $a3, 0x2A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2A);
    after_0:
    // 0x80083028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008302C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80083030: jr          $ra
    // 0x80083034: nop

    return;
    // 0x80083034: nop

;}
RECOMP_FUNC void func_8005C4CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C4CC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8005C4D0: lw          $v1, 0x168($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X168);
    // 0x8005C4D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C4D8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005C4DC: addiu       $v1, $v1, 0x48
    ctx->r3 = ADD32(ctx->r3, 0X48);
    // 0x8005C4E0: beq         $t6, $zero, L_8005C58C
    if (ctx->r14 == 0) {
        // 0x8005C4E4: nop
    
            goto L_8005C58C;
    }
    // 0x8005C4E4: nop

    // 0x8005C4E8: lw          $t7, 0x34($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X34);
    // 0x8005C4EC: lw          $t9, 0x38($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X38);
    // 0x8005C4F0: lw          $t1, 0x1C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1C);
    // 0x8005C4F4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8005C4F8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005C4FC: sw          $t8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r24;
    // 0x8005C500: sw          $t0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r8;
    // 0x8005C504: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8005C508: lw          $t2, 0x20($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X20);
    // 0x8005C50C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x8005C510: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x8005C514: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x8005C518: lw          $t4, 0x34($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X34);
    // 0x8005C51C: slti        $at, $t4, 0x9
    ctx->r1 = SIGNED(ctx->r12) < 0X9 ? 1 : 0;
    // 0x8005C520: bnel        $at, $zero, L_8005C548
    if (ctx->r1 != 0) {
        // 0x8005C524: lw          $t8, 0x38($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X38);
            goto L_8005C548;
    }
    goto skip_0;
    // 0x8005C524: lw          $t8, 0x38($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X38);
    skip_0:
    // 0x8005C528: lw          $t5, 0x30($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X30);
    // 0x8005C52C: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x8005C530: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8005C534: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8005C538: bne         $at, $zero, L_8005C544
    if (ctx->r1 != 0) {
        // 0x8005C53C: sw          $t6, 0x30($v0)
        MEM_W(0X30, ctx->r2) = ctx->r14;
            goto L_8005C544;
    }
    // 0x8005C53C: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
    // 0x8005C540: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
L_8005C544:
    // 0x8005C544: lw          $t8, 0x38($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X38);
L_8005C548:
    // 0x8005C548: slti        $at, $t8, 0x37
    ctx->r1 = SIGNED(ctx->r24) < 0X37 ? 1 : 0;
    // 0x8005C54C: bnel        $at, $zero, L_8005C564
    if (ctx->r1 != 0) {
        // 0x8005C550: lw          $t9, 0x30($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X30);
            goto L_8005C564;
    }
    goto skip_1;
    // 0x8005C550: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    skip_1:
    // 0x8005C554: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x8005C558: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x8005C55C: sw          $zero, 0x38($v0)
    MEM_W(0X38, ctx->r2) = 0;
    // 0x8005C560: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
L_8005C564:
    // 0x8005C564: addiu       $a0, $sp, 0x4
    ctx->r4 = ADD32(ctx->r29, 0X4);
    // 0x8005C568: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8005C56C: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8005C570: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8005C574: sw          $t2, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r10;
    // 0x8005C578: lw          $t3, 0x30($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X30);
    // 0x8005C57C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005C580: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x8005C584: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8005C588: sw          $t6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r14;
L_8005C58C:
    // 0x8005C58C: jr          $ra
    // 0x8005C590: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005C590: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80048CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048CC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80048CCC: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80048CD0: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x80048CD4: addiu       $a3, $a3, -0x735C
    ctx->r7 = ADD32(ctx->r7, -0X735C);
    // 0x80048CD8: addiu       $a2, $a2, 0x3E10
    ctx->r6 = ADD32(ctx->r6, 0X3E10);
    // 0x80048CDC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80048CE0: jal         0x80057F74
    // 0x80048CE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80057F74(rdram, ctx);
        goto after_0;
    // 0x80048CE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80048CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048CEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048CF0: jr          $ra
    // 0x80048CF4: nop

    return;
    // 0x80048CF4: nop

;}
RECOMP_FUNC void func_80056538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005653C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056540: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80056544: jal         0x80064D1C
    // 0x80056548: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x80056548: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    after_0:
    // 0x8005654C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80056550: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x80056554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056558: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005655C: jr          $ra
    // 0x80056560: nop

    return;
    // 0x80056560: nop

;}
RECOMP_FUNC void func_807BABD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BABD4: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x807BABD8: lbu         $v1, 0x10($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X10);
    // 0x807BABDC: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x807BABE0: slti        $at, $v1, 0x3D
    ctx->r1 = SIGNED(ctx->r3) < 0X3D ? 1 : 0;
    // 0x807BABE4: bne         $at, $zero, L_807BAC04
    if (ctx->r1 != 0) {
        // 0x807BABE8: addiu       $t6, $v1, -0xA
        ctx->r14 = ADD32(ctx->r3, -0XA);
            goto L_807BAC04;
    }
    // 0x807BABE8: addiu       $t6, $v1, -0xA
    ctx->r14 = ADD32(ctx->r3, -0XA);
    // 0x807BABEC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x807BABF0: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x807BABF4: beq         $at, $zero, L_807BAC04
    if (ctx->r1 == 0) {
        // 0x807BABF8: sb          $t6, 0x3($v0)
        MEM_B(0X3, ctx->r2) = ctx->r14;
            goto L_807BAC04;
    }
    // 0x807BABF8: sb          $t6, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r14;
    // 0x807BABFC: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x807BAC00: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
L_807BAC04:
    // 0x807BAC04: jr          $ra
    // 0x807BAC08: nop

    return;
    // 0x807BAC08: nop

;}
RECOMP_FUNC void func_80558FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558FE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80558FEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80558FF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80558FF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80558FF8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80558FFC: jal         0x80048F84
    // 0x80559000: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80559000: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80559004: jal         0x805580E8
    // 0x80559008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805580E8(rdram, ctx);
        goto after_1;
    // 0x80559008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8055900C: jal         0x805582E0
    // 0x80559010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805582E0(rdram, ctx);
        goto after_2;
    // 0x80559010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80559014: beql        $v0, $zero, L_80559044
    if (ctx->r2 == 0) {
        // 0x80559018: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80559044;
    }
    goto skip_0;
    // 0x80559018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8055901C: jal         0x80558830
    // 0x80559020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80558830(rdram, ctx);
        goto after_3;
    // 0x80559020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80559024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80559028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8055902C: jal         0x80559928
    // 0x80559030: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_80559928(rdram, ctx);
        goto after_4;
    // 0x80559030: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_4:
    // 0x80559034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80559038: jal         0x80557B60
    // 0x8055903C: addiu       $a1, $zero, 0x28A
    ctx->r5 = ADD32(0, 0X28A);
    func_80557B60(rdram, ctx);
        goto after_5;
    // 0x8055903C: addiu       $a1, $zero, 0x28A
    ctx->r5 = ADD32(0, 0X28A);
    after_5:
    // 0x80559040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80559044:
    // 0x80559044: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80559048: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8055904C: jr          $ra
    // 0x80559050: nop

    return;
    // 0x80559050: nop

;}
RECOMP_FUNC void func_8003C064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003C068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003C06C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003C070: lw          $t6, 0x7C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7C);
    // 0x8003C074: beql        $t6, $zero, L_8003C088
    if (ctx->r14 == 0) {
        // 0x8003C078: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003C088;
    }
    goto skip_0;
    // 0x8003C078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8003C07C: jal         0x8003C044
    // 0x8003C080: nop

    func_8003C044(rdram, ctx);
        goto after_0;
    // 0x8003C080: nop

    after_0:
    // 0x8003C084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003C088:
    // 0x8003C088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003C08C: jr          $ra
    // 0x8003C090: nop

    return;
    // 0x8003C090: nop

;}
RECOMP_FUNC void func_805841A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805841A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805841A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805841AC: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(402, 0X1A384) << 16);
    // 0x805841B0: lwc1        $f4, -0x1FBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(402, 0X1A384));
    // 0x805841B4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x805841B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x805841BC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x805841C0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x805841C4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x805841C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805841CC: addiu       $t6, $zero, 0x1E78
    ctx->r14 = ADD32(0, 0X1E78);
    // 0x805841D0: addiu       $t7, $zero, 0x1EF0
    ctx->r15 = ADD32(0, 0X1EF0);
    // 0x805841D4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x805841D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x805841DC: addiu       $a2, $zero, 0x1E0
    ctx->r6 = ADD32(0, 0X1E0);
    // 0x805841E0: addiu       $a3, $zero, 0x1D88
    ctx->r7 = ADD32(0, 0X1D88);
    // 0x805841E4: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x805841E8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x805841EC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x805841F0: jal         0x80583D88
    // 0x805841F4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_80583D88(rdram, ctx);
        goto after_0;
    // 0x805841F4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x805841F8: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x805841FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80584200: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80584204: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80584208: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8058420C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80584210: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80584214: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80584218: jr          $ra
    // 0x8058421C: nop

    return;
    // 0x8058421C: nop

;}
RECOMP_FUNC void func_8000A3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A3E8: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8000A3EC: addiu       $v1, $v1, 0x4D10
    ctx->r3 = ADD32(ctx->r3, 0X4D10);
    // 0x8000A3F0: lbu         $v0, 0x4F7C($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4F7C);
    // 0x8000A3F4: lbu         $a3, 0x4F7D($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X4F7D);
    // 0x8000A3F8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8000A3FC: lw          $t6, -0x77FC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77FC);
    // 0x8000A400: subu        $a0, $v0, $a3
    ctx->r4 = SUB32(ctx->r2, ctx->r7);
    // 0x8000A404: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x8000A408: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8000A40C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A410: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000A414: beq         $at, $zero, L_8000A424
    if (ctx->r1 == 0) {
        // 0x8000A418: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000A424;
    }
    // 0x8000A418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A41C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8000A420: sw          $a0, -0x77FC($at)
    MEM_W(-0X77FC, ctx->r1) = ctx->r4;
L_8000A424:
    // 0x8000A424: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x8000A428: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8000A42C: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8000A430: or          $a1, $t8, $t9
    ctx->r5 = ctx->r24 | ctx->r25;
    // 0x8000A434: lw          $a0, 0x4F90($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4F90);
    // 0x8000A438: jal         0x80082210
    // 0x8000A43C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000A43C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8000A440: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8000A444: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000A448: beq         $v0, $at, L_8000A458
    if (ctx->r2 == ctx->r1) {
        // 0x8000A44C: addiu       $v1, $v1, 0x4D10
        ctx->r3 = ADD32(ctx->r3, 0X4D10);
            goto L_8000A458;
    }
    // 0x8000A44C: addiu       $v1, $v1, 0x4D10
    ctx->r3 = ADD32(ctx->r3, 0X4D10);
    // 0x8000A450: lbu         $t0, 0x4F7C($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X4F7C);
    // 0x8000A454: sb          $t0, 0x4F7D($v1)
    MEM_B(0X4F7D, ctx->r3) = ctx->r8;
L_8000A458:
    // 0x8000A458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A45C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A460: jr          $ra
    // 0x8000A464: nop

    return;
    // 0x8000A464: nop

;}
RECOMP_FUNC void func_8078EC68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078EC68: lh          $a1, 0x184($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X184);
    // 0x8078EC6C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078EC70: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8078EC74: blez        $a1, L_8078ECB0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8078EC78: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8078ECB0;
    }
    // 0x8078EC78: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_8078EC7C:
    // 0x8078EC7C: lw          $a0, 0x188($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X188);
    // 0x8078EC80: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8078EC84: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8078EC88: beq         $a0, $zero, L_8078ECA8
    if (ctx->r4 == 0) {
        // 0x8078EC8C: nop
    
            goto L_8078ECA8;
    }
    // 0x8078EC8C: nop

    // 0x8078EC90: lhu         $t6, 0x8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8);
    // 0x8078EC94: lhu         $t7, 0xC($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XC);
    // 0x8078EC98: bne         $t6, $t7, L_8078ECA8
    if (ctx->r14 != ctx->r15) {
        // 0x8078EC9C: nop
    
            goto L_8078ECA8;
    }
    // 0x8078EC9C: nop

    // 0x8078ECA0: jr          $ra
    // 0x8078ECA4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8078ECA4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8078ECA8:
    // 0x8078ECA8: bne         $at, $zero, L_8078EC7C
    if (ctx->r1 != 0) {
        // 0x8078ECAC: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8078EC7C;
    }
    // 0x8078ECAC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8078ECB0:
    // 0x8078ECB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8078ECB4: jr          $ra
    // 0x8078ECB8: nop

    return;
    // 0x8078ECB8: nop

;}
RECOMP_FUNC void func_8004A780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A780: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004A784: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004A788: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004A78C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004A790: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8004A794: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8004A798: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8004A79C: jal         0x8004A0BC
    // 0x8004A7A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8004A0BC(rdram, ctx);
        goto after_0;
    // 0x8004A7A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8004A7A4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8004A7A8: bne         $v0, $zero, L_8004A7B8
    if (ctx->r2 != 0) {
        // 0x8004A7AC: sw          $v0, 0x30($t6)
        MEM_W(0X30, ctx->r14) = ctx->r2;
            goto L_8004A7B8;
    }
    // 0x8004A7AC: sw          $v0, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r2;
    // 0x8004A7B0: b           L_8004A910
    // 0x8004A7B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004A910;
    // 0x8004A7B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004A7B8:
    // 0x8004A7B8: jal         0x8004A0BC
    // 0x8004A7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004A0BC(rdram, ctx);
        goto after_1;
    // 0x8004A7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8004A7C0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8004A7C4: bne         $v0, $zero, L_8004A7D4
    if (ctx->r2 != 0) {
        // 0x8004A7C8: sw          $v0, 0x34($t7)
        MEM_W(0X34, ctx->r15) = ctx->r2;
            goto L_8004A7D4;
    }
    // 0x8004A7C8: sw          $v0, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r2;
    // 0x8004A7CC: b           L_8004A910
    // 0x8004A7D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004A910;
    // 0x8004A7D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004A7D4:
    // 0x8004A7D4: jal         0x8004A0BC
    // 0x8004A7D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004A0BC(rdram, ctx);
        goto after_2;
    // 0x8004A7D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8004A7DC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8004A7E0: bne         $v0, $zero, L_8004A7F0
    if (ctx->r2 != 0) {
        // 0x8004A7E4: sw          $v0, 0x38($t8)
        MEM_W(0X38, ctx->r24) = ctx->r2;
            goto L_8004A7F0;
    }
    // 0x8004A7E4: sw          $v0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->r2;
    // 0x8004A7E8: b           L_8004A910
    // 0x8004A7EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004A910;
    // 0x8004A7EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004A7F0:
    // 0x8004A7F0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8004A7F4: jal         0x8005BDF8
    // 0x8004A7F8: lhu         $a0, 0xC($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0XC);
    func_8005BDF8(rdram, ctx);
        goto after_3;
    // 0x8004A7F8: lhu         $a0, 0xC($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0XC);
    after_3:
    // 0x8004A7FC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8004A800: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8004A804: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004A808: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8004A80C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8004A810: jal         0x8004A124
    // 0x8004A814: sw          $v0, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r2;
    func_8004A124(rdram, ctx);
        goto after_4;
    // 0x8004A814: sw          $v0, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r2;
    after_4:
    // 0x8004A818: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8004A81C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004A820: jal         0x8004A064
    // 0x8004A824: sw          $s0, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r16;
    func_8004A064(rdram, ctx);
        goto after_5;
    // 0x8004A824: sw          $s0, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r16;
    after_5:
    // 0x8004A828: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8004A82C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004A830: bne         $v0, $zero, L_8004A840
    if (ctx->r2 != 0) {
        // 0x8004A834: sw          $v0, 0x40($t2)
        MEM_W(0X40, ctx->r10) = ctx->r2;
            goto L_8004A840;
    }
    // 0x8004A834: sw          $v0, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->r2;
    // 0x8004A838: b           L_8004A910
    // 0x8004A83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004A910;
    // 0x8004A83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004A840:
    // 0x8004A840: sll         $a1, $s0, 2
    ctx->r5 = S32(ctx->r16 << 2);
    // 0x8004A844: subu        $a1, $a1, $s0
    ctx->r5 = SUB32(ctx->r5, ctx->r16);
    // 0x8004A848: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x8004A84C: jal         0x800657CC
    // 0x8004A850: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_6;
    // 0x8004A850: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8004A854: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8004A858: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8004A85C: subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // 0x8004A860: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8004A864: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8004A868: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8004A86C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8004A870: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8004A874: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x8004A878: sh          $t6, 0x4C($t7)
    MEM_H(0X4C, ctx->r15) = ctx->r14;
    // 0x8004A87C: lbu         $t8, 0x18($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X18);
    // 0x8004A880: bne         $t8, $at, L_8004A904
    if (ctx->r24 != ctx->r1) {
        // 0x8004A884: nop
    
            goto L_8004A904;
    }
    // 0x8004A884: nop

    // 0x8004A888: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8004A88C: lhu         $v1, 0x1C($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X1C);
    // 0x8004A890: andi        $t9, $v1, 0x200
    ctx->r25 = ctx->r3 & 0X200;
    // 0x8004A894: beq         $t9, $zero, L_8004A8B4
    if (ctx->r25 == 0) {
        // 0x8004A898: andi        $t0, $v1, 0x100
        ctx->r8 = ctx->r3 & 0X100;
            goto L_8004A8B4;
    }
    // 0x8004A898: andi        $t0, $v1, 0x100
    ctx->r8 = ctx->r3 & 0X100;
    // 0x8004A89C: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x8004A8A0: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    // 0x8004A8A4: jalr        $t9
    // 0x8004A8A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8004A8A8: nop

    after_7:
    // 0x8004A8AC: b           L_8004A8E4
    // 0x8004A8B0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_8004A8E4;
    // 0x8004A8B0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8004A8B4:
    // 0x8004A8B4: beql        $t0, $zero, L_8004A8C8
    if (ctx->r8 == 0) {
        // 0x8004A8B8: lhu         $t1, 0x4C($v0)
        ctx->r9 = MEM_HU(ctx->r2, 0X4C);
            goto L_8004A8C8;
    }
    goto skip_0;
    // 0x8004A8B8: lhu         $t1, 0x4C($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X4C);
    skip_0:
    // 0x8004A8BC: b           L_8004A8E0
    // 0x8004A8C0: sw          $zero, 0x44($v0)
    MEM_W(0X44, ctx->r2) = 0;
        goto L_8004A8E0;
    // 0x8004A8C0: sw          $zero, 0x44($v0)
    MEM_W(0X44, ctx->r2) = 0;
    // 0x8004A8C4: lhu         $t1, 0x4C($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X4C);
L_8004A8C8:
    // 0x8004A8C8: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8004A8CC: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x8004A8D0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8004A8D4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8004A8D8: lw          $t4, 0x5C4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5C4);
    // 0x8004A8DC: sw          $t4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r12;
L_8004A8E0:
    // 0x8004A8E0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8004A8E4:
    // 0x8004A8E4: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8004A8E8: lhu         $t5, 0x4C($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X4C);
    // 0x8004A8EC: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x8004A8F0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004A8F4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8004A8F8: lw          $t8, 0x5C4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5C4);
    // 0x8004A8FC: b           L_8004A90C
    // 0x8004A900: sw          $t8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r24;
        goto L_8004A90C;
    // 0x8004A900: sw          $t8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r24;
L_8004A904:
    // 0x8004A904: jal         0x8004A73C
    // 0x8004A908: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8004A73C(rdram, ctx);
        goto after_8;
    // 0x8004A908: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
L_8004A90C:
    // 0x8004A90C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004A910:
    // 0x8004A910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A914: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004A918: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8004A91C: jr          $ra
    // 0x8004A920: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8004A920: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80425034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80425034: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80425038: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8042503C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80425040: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80425044: jal         0x80424F94
    // 0x80425048: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80424F94(rdram, ctx);
        goto after_0;
    // 0x80425048: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042504C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80425050: lw          $a1, 0xF4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XF4);
    // 0x80425054: lw          $a2, 0xF8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XF8);
    // 0x80425058: lw          $a3, 0xE4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE4);
    // 0x8042505C: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80425060: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80425064: jal         0x80424824
    // 0x80425068: addiu       $a0, $s0, 0xA0
    ctx->r4 = ADD32(ctx->r16, 0XA0);
    func_80424824(rdram, ctx);
        goto after_1;
    // 0x80425068: addiu       $a0, $s0, 0xA0
    ctx->r4 = ADD32(ctx->r16, 0XA0);
    after_1:
    // 0x8042506C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80425070: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80425074: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(35, 0X36E4) << 16);
    // 0x80425078: lwc1        $f6, 0x60E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(35, 0X36E4));
    // 0x8042507C: lwc1        $f4, 0xE4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x80425080: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80425084: swc1        $f8, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f8.u32l;
    // 0x80425088: lwc1        $f10, 0xE4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8042508C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80425090: nop

    // 0x80425094: bc1fl       L_804250CC
    if (!c1cs) {
        // 0x80425098: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_804250CC;
    }
    goto skip_0;
    // 0x80425098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8042509C: jal         0x800653D8
    // 0x804250A0: swc1        $f0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f0.u32l;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x804250A0: swc1        $f0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x804250A4: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x804250A8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x804250AC: mfhi        $t8
    ctx->r24 = hi;
    // 0x804250B0: sw          $t8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->r24;
    // 0x804250B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804250B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804250BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804250C0: jal         0x80425408
    // 0x804250C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80425408(rdram, ctx);
        goto after_3;
    // 0x804250C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x804250C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804250CC:
    // 0x804250CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804250D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804250D4: jr          $ra
    // 0x804250D8: nop

    return;
    // 0x804250D8: nop

;}
RECOMP_FUNC void func_800091B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800091B8: blez        $a1, L_800091E4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800091BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800091E4;
    }
    // 0x800091BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800091C0: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800091C4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_800091C8:
    // 0x800091C8: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800091CC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800091D0: beq         $v1, $t7, L_800091E4
    if (ctx->r3 == ctx->r15) {
        // 0x800091D4: nop
    
            goto L_800091E4;
    }
    // 0x800091D4: nop

    // 0x800091D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800091DC: bne         $v0, $a1, L_800091C8
    if (ctx->r2 != ctx->r5) {
        // 0x800091E0: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800091C8;
    }
    // 0x800091E0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_800091E4:
    // 0x800091E4: bne         $v0, $a1, L_800091F8
    if (ctx->r2 != ctx->r5) {
        // 0x800091E8: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_800091F8;
    }
    // 0x800091E8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800091EC: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x800091F0: sw          $a0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r4;
    // 0x800091F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800091F8:
    // 0x800091F8: jr          $ra
    // 0x800091FC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800091FC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_805C7C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C7C04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805C7C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805C7C0C: jal         0x805C6E30
    // 0x805C7C10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805C6E30(rdram, ctx);
        goto after_0;
    // 0x805C7C10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805C7C14: jal         0x805C7844
    // 0x805C7C18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805C7844(rdram, ctx);
        goto after_1;
    // 0x805C7C18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805C7C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805C7C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805C7C24: jr          $ra
    // 0x805C7C28: nop

    return;
    // 0x805C7C28: nop

;}
RECOMP_FUNC void func_800227C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800227C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800227C8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800227CC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800227D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800227D4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800227D8: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x800227DC: jal         0x80047AB8
    // 0x800227E0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x800227E0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800227E4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800227E8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800227EC: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800227F0: lbu         $t7, 0x1A8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1A8);
    // 0x800227F4: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x800227F8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800227FC: beq         $t7, $zero, L_80022848
    if (ctx->r15 == 0) {
        // 0x80022800: lwc1        $f18, 0x2C($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_80022848;
    }
    // 0x80022800: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80022804: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80022808: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002280C: lwc1        $f4, 0x6C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x80022810: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022814: lwc1        $f18, -0x388($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X388);
    // 0x80022818: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002281C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80022820: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80022824: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80022828: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002282C: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80022830: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    // 0x80022834: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80022838: jal         0x8002269C
    // 0x8002283C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    func_8002269C(rdram, ctx);
        goto after_1;
    // 0x8002283C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x80022840: b           L_80022880
    // 0x80022844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80022880;
    // 0x80022844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80022848:
    // 0x80022848: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002284C: lwc1        $f6, 0x6C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x80022850: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022854: lwc1        $f4, -0x384($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X384);
    // 0x80022858: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8002285C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80022860: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80022864: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80022868: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8002286C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80022870: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80022874: jal         0x8002269C
    // 0x80022878: sub.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f10.fl;
    func_8002269C(rdram, ctx);
        goto after_2;
    // 0x80022878: sub.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f10.fl;
    after_2:
    // 0x8002287C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80022880:
    // 0x80022880: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80022884: jr          $ra
    // 0x80022888: nop

    return;
    // 0x80022888: nop

;}
RECOMP_FUNC void func_804666F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804666F0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804666F4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(129, 0X2D0) << 16);
    // 0x804666F8: lwc1        $f2, 0x68D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(129, 0X2D0));
    // 0x804666FC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80466700: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80466704: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80466708: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8046670C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80466710: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80466714: nop

    // 0x80466718: bc1fl       L_8046672C
    if (!c1cs) {
        // 0x8046671C: lw          $t6, 0x34($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X34);
            goto L_8046672C;
    }
    goto skip_0;
    // 0x8046671C: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    skip_0:
    // 0x80466720: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80466724: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80466728: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
L_8046672C:
    // 0x8046672C: addiu       $t7, $t6, -0xA0
    ctx->r15 = ADD32(ctx->r14, -0XA0);
    // 0x80466730: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x80466734: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x80466738: addiu       $t9, $t8, 0xA0
    ctx->r25 = ADD32(ctx->r24, 0XA0);
    // 0x8046673C: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x80466740: lw          $t0, 0x38($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X38);
    // 0x80466744: addiu       $t1, $t0, -0x78
    ctx->r9 = ADD32(ctx->r8, -0X78);
    // 0x80466748: sw          $t1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r9;
    // 0x8046674C: lw          $t2, 0x38($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X38);
    // 0x80466750: addiu       $t3, $t2, 0x78
    ctx->r11 = ADD32(ctx->r10, 0X78);
    // 0x80466754: bgez        $t7, L_80466764
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80466758: sw          $t3, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->r11;
            goto L_80466764;
    }
    // 0x80466758: sw          $t3, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r11;
    // 0x8046675C: b           L_8046677C
    // 0x80466760: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
        goto L_8046677C;
    // 0x80466760: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
L_80466764:
    // 0x80466764: lw          $t5, 0x18($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X18);
    // 0x80466768: addiu       $t6, $zero, 0x13F
    ctx->r14 = ADD32(0, 0X13F);
    // 0x8046676C: slti        $at, $t5, 0x140
    ctx->r1 = SIGNED(ctx->r13) < 0X140 ? 1 : 0;
    // 0x80466770: bnel        $at, $zero, L_80466780
    if (ctx->r1 != 0) {
        // 0x80466774: lw          $v1, 0x14($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X14);
            goto L_80466780;
    }
    goto skip_1;
    // 0x80466774: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    skip_1:
    // 0x80466778: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
L_8046677C:
    // 0x8046677C: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
L_80466780:
    // 0x80466780: bgezl       $v1, L_804667A4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80466784: lw          $t0, 0x1C($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X1C);
            goto L_804667A4;
    }
    goto skip_2;
    // 0x80466784: lw          $t0, 0x1C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1C);
    skip_2:
    // 0x80466788: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x8046678C: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x80466790: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80466794: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80466798: jr          $ra
    // 0x8046679C: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    return;
    // 0x8046679C: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x804667A0: lw          $t0, 0x1C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1C);
L_804667A4:
    // 0x804667A4: slti        $at, $t0, 0xF0
    ctx->r1 = SIGNED(ctx->r8) < 0XF0 ? 1 : 0;
    // 0x804667A8: bne         $at, $zero, L_804667C8
    if (ctx->r1 != 0) {
        // 0x804667AC: nop
    
            goto L_804667C8;
    }
    // 0x804667AC: nop

    // 0x804667B0: lw          $t1, 0x18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X18);
    // 0x804667B4: addiu       $t4, $zero, 0xEF
    ctx->r12 = ADD32(0, 0XEF);
    // 0x804667B8: sw          $t4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r12;
    // 0x804667BC: subu        $t2, $v1, $t1
    ctx->r10 = SUB32(ctx->r3, ctx->r9);
    // 0x804667C0: addiu       $t3, $t2, 0xEF
    ctx->r11 = ADD32(ctx->r10, 0XEF);
    // 0x804667C4: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
L_804667C8:
    // 0x804667C8: jr          $ra
    // 0x804667CC: nop

    return;
    // 0x804667CC: nop

;}
RECOMP_FUNC void func_800720E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800720E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800720EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800720F0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800720F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800720F8: sw          $t6, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r14;
    // 0x800720FC: jal         0x8008B920
    // 0x80072100: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x80072100: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80072104: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80072108: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8007210C: addiu       $t7, $t7, -0x4D94
    ctx->r15 = ADD32(ctx->r15, -0X4D94);
    // 0x80072110: sw          $v0, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->r2;
    // 0x80072114: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072118: sw          $v1, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->r3;
    // 0x8007211C: addiu       $a0, $a0, -0x5908
    ctx->r4 = ADD32(ctx->r4, -0X5908);
    // 0x80072120: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80072124: jal         0x80082210
    // 0x80072128: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80072128: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    after_1:
    // 0x8007212C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072130: addiu       $a0, $a0, -0x2770
    ctx->r4 = ADD32(ctx->r4, -0X2770);
    // 0x80072134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80072138: jal         0x80082210
    // 0x8007213C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8007213C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80072140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072148: jr          $ra
    // 0x8007214C: nop

    return;
    // 0x8007214C: nop

;}
RECOMP_FUNC void func_8057C5D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C5D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057C5D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057C5D8: jal         0x8057BC48
    // 0x8057C5DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8057BC48(rdram, ctx);
        goto after_0;
    // 0x8057C5DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8057C5E0: jal         0x80045BD8
    // 0x8057C5E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8057C5E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8057C5E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057C5EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057C5F0: jr          $ra
    // 0x8057C5F4: nop

    return;
    // 0x8057C5F4: nop

;}
RECOMP_FUNC void func_804D2B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D2B60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D2B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D2B68: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804D2B6C: lui         $t6, 0x804D
    ctx->r14 = S32(RELOC_HI16(249, 0X490) << 16);
    // 0x804D2B70: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804D2B74: addiu       $t6, $t6, 0x2FA0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(249, 0X490));
    // 0x804D2B78: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804D2B7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804D2B80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804D2B84: jal         0x804D2E60
    // 0x804D2B88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_804D2E60(rdram, ctx);
        goto after_0;
    // 0x804D2B88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x804D2B8C: jal         0x804D2BC4
    // 0x804D2B90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804D2BC4(rdram, ctx);
        goto after_1;
    // 0x804D2B90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804D2B94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804D2B98: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x804D2B9C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x804D2BA0: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x804D2BA4: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x804D2BA8: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x804D2BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D2BB0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804D2BB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804D2BB8: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x804D2BBC: jr          $ra
    // 0x804D2BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804D2BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800424A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800424A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800424A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800424AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800424B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800424B4: lw          $v1, 0xF0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XF0);
    // 0x800424B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800424BC: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800424C0: beq         $v1, $zero, L_800424D0
    if (ctx->r3 == 0) {
        // 0x800424C4: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_800424D0;
    }
    // 0x800424C4: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x800424C8: b           L_80042544
    // 0x800424CC: sw          $t7, 0xF0($a1)
    MEM_W(0XF0, ctx->r5) = ctx->r15;
        goto L_80042544;
    // 0x800424CC: sw          $t7, 0xF0($a1)
    MEM_W(0XF0, ctx->r5) = ctx->r15;
L_800424D0:
    // 0x800424D0: lbu         $t8, -0x764C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X764C);
    // 0x800424D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800424D8: bnel        $v0, $t8, L_80042548
    if (ctx->r2 != ctx->r24) {
        // 0x800424DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80042548;
    }
    goto skip_0;
    // 0x800424DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800424E0: lbu         $t9, 0x18($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18);
    // 0x800424E4: bnel        $v0, $t9, L_80042548
    if (ctx->r2 != ctx->r25) {
        // 0x800424E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80042548;
    }
    goto skip_1;
    // 0x800424E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800424EC: lbu         $t0, 0x30($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X30);
    // 0x800424F0: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x800424F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800424F8: beq         $t0, $at, L_80042544
    if (ctx->r8 == ctx->r1) {
        // 0x800424FC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80042544;
    }
    // 0x800424FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80042500: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    // 0x80042504: jal         0x8001DC5C
    // 0x80042508: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8001DC5C(rdram, ctx);
        goto after_0;
    // 0x80042508: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8004250C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80042510: jal         0x8003262C
    // 0x80042514: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8003262C(rdram, ctx);
        goto after_1;
    // 0x80042514: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80042518: jal         0x8001D770
    // 0x8004251C: nop

    func_8001D770(rdram, ctx);
        goto after_2;
    // 0x8004251C: nop

    after_2:
    // 0x80042520: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80042524: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80042528: jal         0x80067BF8
    // 0x8004252C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_3;
    // 0x8004252C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x80042530: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    // 0x80042534: jal         0x80067818
    // 0x80042538: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x80042538: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8004253C: jal         0x80067A50
    // 0x80042540: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067A50(rdram, ctx);
        goto after_5;
    // 0x80042540: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
L_80042544:
    // 0x80042544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80042548:
    // 0x80042548: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004254C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80042550: jr          $ra
    // 0x80042554: nop

    return;
    // 0x80042554: nop

;}
RECOMP_FUNC void func_80058C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058C10: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80058C14: lw          $t6, -0x6DA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DA8);
    // 0x80058C18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80058C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058C20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80058C24: addiu       $t7, $t6, 0x120
    ctx->r15 = ADD32(ctx->r14, 0X120);
    // 0x80058C28: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80058C2C: jal         0x80058B44
    // 0x80058C30: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_80058B44(rdram, ctx);
        goto after_0;
    // 0x80058C30: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x80058C34: beq         $v0, $zero, L_80058C68
    if (ctx->r2 == 0) {
        // 0x80058C38: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80058C68;
    }
    // 0x80058C38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80058C3C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80058C40: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_80058C44:
    // 0x80058C44: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80058C48: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80058C4C: bne         $v0, $t8, L_80058C60
    if (ctx->r2 != ctx->r24) {
        // 0x80058C50: nop
    
            goto L_80058C60;
    }
    // 0x80058C50: nop

    // 0x80058C54: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80058C58: b           L_80058C6C
    // 0x80058C5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80058C6C;
    // 0x80058C5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80058C60:
    // 0x80058C60: bne         $a0, $a1, L_80058C44
    if (ctx->r4 != ctx->r5) {
        // 0x80058C64: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80058C44;
    }
    // 0x80058C64: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80058C68:
    // 0x80058C68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80058C6C:
    // 0x80058C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058C70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80058C74: jr          $ra
    // 0x80058C78: nop

    return;
    // 0x80058C78: nop

;}
RECOMP_FUNC void func_8069B588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069B588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069B58C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069B590: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069B594: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x8069B598: beq         $v1, $zero, L_8069B5A4
    if (ctx->r3 == 0) {
        // 0x8069B59C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8069B5A4;
    }
    // 0x8069B59C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8069B5A0: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
L_8069B5A4:
    // 0x8069B5A4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8069B5A8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8069B5AC: beq         $v1, $at, L_8069B5BC
    if (ctx->r3 == ctx->r1) {
        // 0x8069B5B0: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_8069B5BC;
    }
    // 0x8069B5B0: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8069B5B4: bnel        $v1, $at, L_8069B5D8
    if (ctx->r3 != ctx->r1) {
        // 0x8069B5B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8069B5D8;
    }
    goto skip_0;
    // 0x8069B5B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8069B5BC:
    // 0x8069B5BC: lw          $t7, 0x14($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14);
    // 0x8069B5C0: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8069B5C4: bnel        $t7, $zero, L_8069B5D8
    if (ctx->r15 != 0) {
        // 0x8069B5C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8069B5D8;
    }
    goto skip_1;
    // 0x8069B5C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8069B5CC: jal         0x8069B3F4
    // 0x8069B5D0: sw          $t8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r24;
    func_8069B3F4(rdram, ctx);
        goto after_0;
    // 0x8069B5D0: sw          $t8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r24;
    after_0:
    // 0x8069B5D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8069B5D8:
    // 0x8069B5D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069B5DC: jr          $ra
    // 0x8069B5E0: nop

    return;
    // 0x8069B5E0: nop

;}
RECOMP_FUNC void func_80531E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531E38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80531E3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80531E40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80531E44: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80531E48: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x80531E4C: lui         $t1, 0x8053
    ctx->r9 = S32(RELOC_HI16(342, 0X1840) << 16);
    // 0x80531E50: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80531E54: slti        $at, $v1, 0x4302
    ctx->r1 = SIGNED(ctx->r3) < 0X4302 ? 1 : 0;
    // 0x80531E58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80531E5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80531E60: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80531E64: nop

    // 0x80531E68: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x80531E6C: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x80531E70: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80531E74: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80531E78: lh          $t1, 0x2630($t1)
    ctx->r9 = MEM_H(ctx->r9, (int16_t)RELOC_LO16(342, 0X1840));
    // 0x80531E7C: bne         $at, $zero, L_80531E98
    if (ctx->r1 != 0) {
        // 0x80531E80: sh          $t1, 0x144($a0)
        MEM_H(0X144, ctx->r4) = ctx->r9;
            goto L_80531E98;
    }
    // 0x80531E80: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x80531E84: slti        $at, $v1, 0x4340
    ctx->r1 = SIGNED(ctx->r3) < 0X4340 ? 1 : 0;
    // 0x80531E88: beql        $at, $zero, L_80531E9C
    if (ctx->r1 == 0) {
        // 0x80531E8C: slti        $at, $v0, 0x4340
        ctx->r1 = SIGNED(ctx->r2) < 0X4340 ? 1 : 0;
            goto L_80531E9C;
    }
    goto skip_0;
    // 0x80531E8C: slti        $at, $v0, 0x4340
    ctx->r1 = SIGNED(ctx->r2) < 0X4340 ? 1 : 0;
    skip_0:
    // 0x80531E90: b           L_80531EE8
    // 0x80531E94: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
        goto L_80531EE8;
    // 0x80531E94: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
L_80531E98:
    // 0x80531E98: slti        $at, $v0, 0x4340
    ctx->r1 = SIGNED(ctx->r2) < 0X4340 ? 1 : 0;
L_80531E9C:
    // 0x80531E9C: bne         $at, $zero, L_80531EB4
    if (ctx->r1 != 0) {
        // 0x80531EA0: slti        $at, $v0, 0x436A
        ctx->r1 = SIGNED(ctx->r2) < 0X436A ? 1 : 0;
            goto L_80531EB4;
    }
    // 0x80531EA0: slti        $at, $v0, 0x436A
    ctx->r1 = SIGNED(ctx->r2) < 0X436A ? 1 : 0;
    // 0x80531EA4: beq         $at, $zero, L_80531EB4
    if (ctx->r1 == 0) {
        // 0x80531EA8: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80531EB4;
    }
    // 0x80531EA8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80531EAC: b           L_80531EE8
    // 0x80531EB0: sw          $t2, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->r10;
        goto L_80531EE8;
    // 0x80531EB0: sw          $t2, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->r10;
L_80531EB4:
    // 0x80531EB4: slti        $at, $v0, 0x436A
    ctx->r1 = SIGNED(ctx->r2) < 0X436A ? 1 : 0;
    // 0x80531EB8: bne         $at, $zero, L_80531ED0
    if (ctx->r1 != 0) {
        // 0x80531EBC: slti        $at, $v0, 0x437F
        ctx->r1 = SIGNED(ctx->r2) < 0X437F ? 1 : 0;
            goto L_80531ED0;
    }
    // 0x80531EBC: slti        $at, $v0, 0x437F
    ctx->r1 = SIGNED(ctx->r2) < 0X437F ? 1 : 0;
    // 0x80531EC0: beq         $at, $zero, L_80531ED0
    if (ctx->r1 == 0) {
        // 0x80531EC4: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_80531ED0;
    }
    // 0x80531EC4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80531EC8: b           L_80531EE8
    // 0x80531ECC: sw          $t3, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->r11;
        goto L_80531EE8;
    // 0x80531ECC: sw          $t3, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->r11;
L_80531ED0:
    // 0x80531ED0: slti        $at, $v0, 0x437F
    ctx->r1 = SIGNED(ctx->r2) < 0X437F ? 1 : 0;
    // 0x80531ED4: bne         $at, $zero, L_80531EE8
    if (ctx->r1 != 0) {
        // 0x80531ED8: slti        $at, $v0, 0x4395
        ctx->r1 = SIGNED(ctx->r2) < 0X4395 ? 1 : 0;
            goto L_80531EE8;
    }
    // 0x80531ED8: slti        $at, $v0, 0x4395
    ctx->r1 = SIGNED(ctx->r2) < 0X4395 ? 1 : 0;
    // 0x80531EDC: beq         $at, $zero, L_80531EE8
    if (ctx->r1 == 0) {
        // 0x80531EE0: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_80531EE8;
    }
    // 0x80531EE0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80531EE4: sw          $t4, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->r12;
L_80531EE8:
    // 0x80531EE8: jal         0x80531D68
    // 0x80531EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80531D68(rdram, ctx);
        goto after_0;
    // 0x80531EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80531EF0: beq         $v0, $zero, L_80531FA4
    if (ctx->r2 == 0) {
        // 0x80531EF4: lui         $t5, 0x8053
        ctx->r13 = S32(RELOC_HI16(342, 0X1830) << 16);
            goto L_80531FA4;
    }
    // 0x80531EF4: lui         $t5, 0x8053
    ctx->r13 = S32(RELOC_HI16(342, 0X1830) << 16);
    // 0x80531EF8: lw          $t6, 0x16C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X16C);
    // 0x80531EFC: addiu       $t5, $t5, 0x2620
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(342, 0X1830));
    // 0x80531F00: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(342, 0X1848) << 16);
    // 0x80531F04: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80531F08: lw          $t7, 0x134($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X134);
    // 0x80531F0C: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x80531F10: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80531F14: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80531F18: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80531F1C: lh          $t9, 0x2638($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(342, 0X1848));
    // 0x80531F20: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80531F24: lui         $t3, 0x8053
    ctx->r11 = S32(RELOC_HI16(342, 0X384) << 16);
    // 0x80531F28: addiu       $t3, $t3, 0x1174
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(342, 0X384));
    // 0x80531F2C: sh          $t9, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r25;
    // 0x80531F30: lw          $t4, 0x16C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X16C);
    // 0x80531F34: sw          $t2, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r10;
    // 0x80531F38: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80531F3C: sw          $t3, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r11;
    // 0x80531F40: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80531F44: sb          $t5, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r13;
    // 0x80531F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80531F4C: jal         0x80531FB8
    // 0x80531F50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80531FB8(rdram, ctx);
        goto after_1;
    // 0x80531F50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80531F54: jal         0x80531E20
    // 0x80531F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80531E20(rdram, ctx);
        goto after_2;
    // 0x80531F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80531F5C: jal         0x80531740
    // 0x80531F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80531740(rdram, ctx);
        goto after_3;
    // 0x80531F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80531F64: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80531F68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80531F6C: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80531F70: lw          $t6, 0x134($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X134);
    // 0x80531F74: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1850) << 16);
    // 0x80531F78: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80531F7C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80531F80: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80531F84: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80531F88: swc1        $f16, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f16.u32l;
    // 0x80531F8C: lwc1        $f18, 0x2640($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1850));
    // 0x80531F90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80531F94: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80531F98: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80531F9C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x80531FA0: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
L_80531FA4:
    // 0x80531FA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80531FA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80531FAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80531FB0: jr          $ra
    // 0x80531FB4: nop

    return;
    // 0x80531FB4: nop

;}
RECOMP_FUNC void func_806AB648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AB648: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806AB64C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AB650: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AB654: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806AB658: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806AB65C: jal         0x806AB418
    // 0x806AB660: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    func_806AB418(rdram, ctx);
        goto after_0;
    // 0x806AB660: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    after_0:
    // 0x806AB664: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x806AB668: lui         $t7, 0x806B
    ctx->r15 = S32(RELOC_HI16(592, 0X2FB8) << 16);
    // 0x806AB66C: addiu       $t7, $t7, -0x2468
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(592, 0X2FB8));
    // 0x806AB670: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806AB674: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806AB678: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806AB67C: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806AB680: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806AB684: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    // 0x806AB688: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806AB68C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806AB690: jal         0x80048378
    // 0x806AB694: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x806AB694: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    after_1:
    // 0x806AB698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AB69C: jal         0x80045A34
    // 0x806AB6A0: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x806AB6A0: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_2:
    // 0x806AB6A4: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806AB6A8: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x806AB6AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806AB6B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AB6B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806AB6B8: jr          $ra
    // 0x806AB6BC: nop

    return;
    // 0x806AB6BC: nop

;}
RECOMP_FUNC void func_80045250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045250: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80045254: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80045258: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004525C: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x80045260: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x80045264: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80045268: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8004526C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80045270: addiu       $s3, $s3, 0x7EB0
    ctx->r19 = ADD32(ctx->r19, 0X7EB0);
    // 0x80045274: addiu       $s0, $s0, 0x7EA0
    ctx->r16 = ADD32(ctx->r16, 0X7EA0);
L_80045278:
    // 0x80045278: lw          $s1, 0x9F4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9F4);
    // 0x8004527C: lh          $s2, 0x8($s1)
    ctx->r18 = MEM_H(ctx->r17, 0X8);
    // 0x80045280: jal         0x80058098
    // 0x80045284: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80058098(rdram, ctx);
        goto after_0;
    // 0x80045284: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80045288: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8004528C: bne         $s0, $s3, L_80045278
    if (ctx->r16 != ctx->r19) {
        // 0x80045290: sh          $s2, 0x8($s1)
        MEM_H(0X8, ctx->r17) = ctx->r18;
            goto L_80045278;
    }
    // 0x80045290: sh          $s2, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r18;
    // 0x80045294: jal         0x80052CD0
    // 0x80045298: nop

    func_80052CD0(rdram, ctx);
        goto after_1;
    // 0x80045298: nop

    after_1:
    // 0x8004529C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800452A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800452A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800452A8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800452AC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800452B0: jr          $ra
    // 0x800452B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800452B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800452B8: nop

    // 0x800452BC: nop

;}
RECOMP_FUNC void func_806F66A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F66A0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x806F66A4: addiu       $at, $zero, 0x45EB
    ctx->r1 = ADD32(0, 0X45EB);
    // 0x806F66A8: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(688, 0X4DC) << 16);
    // 0x806F66AC: bne         $t6, $at, L_806F66C0
    if (ctx->r14 != ctx->r1) {
        // 0x806F66B0: addiu       $v0, $v0, 0x6B7C
        ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(688, 0X4DC));
            goto L_806F66C0;
    }
    // 0x806F66B0: addiu       $v0, $v0, 0x6B7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(688, 0X4DC));
    // 0x806F66B4: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(688, 0X4DC) << 16);
    // 0x806F66B8: jr          $ra
    // 0x806F66BC: addiu       $v0, $v0, 0x6B7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(688, 0X4DC));
    return;
    // 0x806F66BC: addiu       $v0, $v0, 0x6B7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(688, 0X4DC));
L_806F66C0:
    // 0x806F66C0: jr          $ra
    // 0x806F66C4: nop

    return;
    // 0x806F66C4: nop

;}
RECOMP_FUNC void func_80565670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80565670: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80565674: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80565678: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8056567C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80565680: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80565684: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80565688: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8056568C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80565690: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80565694: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80565698: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8056569C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x805656A0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x805656A4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x805656A8: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x805656AC: lw          $s6, 0x1F4($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X1F4);
    // 0x805656B0: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x805656B4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x805656B8: lwc1        $f4, 0x504($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X504);
    // 0x805656BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805656C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805656C4: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x805656C8: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x805656CC: addiu       $v1, $s6, 0x174
    ctx->r3 = ADD32(ctx->r22, 0X174);
    // 0x805656D0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // 0x805656D4: addiu       $s5, $zero, 0x3E
    ctx->r21 = ADD32(0, 0X3E);
    // 0x805656D8: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x805656DC: or          $s7, $s6, $zero
    ctx->r23 = ctx->r22 | 0;
    // 0x805656E0: mul.s       $f22, $f6, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805656E4: nop

    // 0x805656E8: mul.s       $f24, $f10, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x805656EC: nop

L_805656F0:
    // 0x805656F0: lw          $s0, 0x5C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X5C);
    // 0x805656F4: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x805656F8: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    // 0x805656FC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80565700: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80565704: or          $s4, $s6, $zero
    ctx->r20 = ctx->r22 | 0;
L_80565708:
    // 0x80565708: trunc.w.s   $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    ctx->f18.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8056570C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80565710: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80565714: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80565718: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8056571C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80565720: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80565724: sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // 0x80565728: sh          $v0, -0x4($s1)
    MEM_H(-0X4, ctx->r17) = ctx->r2;
    // 0x8056572C: sh          $zero, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = 0;
    // 0x80565730: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x80565734: jal         0x805640E0
    // 0x80565738: sh          $t7, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r15;
    func_805640E0(rdram, ctx);
        goto after_0;
    // 0x80565738: sh          $t7, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r15;
    after_0:
    // 0x8056573C: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x80565740: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80565744: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80565748: bne         $s3, $s5, L_80565708
    if (ctx->r19 != ctx->r21) {
        // 0x8056574C: swc1        $f0, 0x3E4($s4)
        MEM_W(0X3E4, ctx->r20) = ctx->f0.u32l;
            goto L_80565708;
    }
    // 0x8056574C: swc1        $f0, 0x3E4($s4)
    MEM_W(0X3E4, ctx->r20) = ctx->f0.u32l;
    // 0x80565750: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80565754: addiu       $fp, $fp, 0x7C
    ctx->r30 = ADD32(ctx->r30, 0X7C);
    // 0x80565758: addiu       $at, $zero, 0x174
    ctx->r1 = ADD32(0, 0X174);
    // 0x8056575C: addiu       $t9, $t8, 0x7C
    ctx->r25 = ADD32(ctx->r24, 0X7C);
    // 0x80565760: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x80565764: bne         $fp, $at, L_805656F0
    if (ctx->r30 != ctx->r1) {
        // 0x80565768: addiu       $s7, $s7, 0x7C
        ctx->r23 = ADD32(ctx->r23, 0X7C);
            goto L_805656F0;
    }
    // 0x80565768: addiu       $s7, $s7, 0x7C
    ctx->r23 = ADD32(ctx->r23, 0X7C);
    // 0x8056576C: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80565770: swc1        $f4, 0x508($s6)
    MEM_W(0X508, ctx->r22) = ctx->f4.u32l;
    // 0x80565774: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80565778: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8056577C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80565780: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80565784: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80565788: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8056578C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80565790: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80565794: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80565798: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8056579C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x805657A0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x805657A4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x805657A8: jr          $ra
    // 0x805657AC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x805657AC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_8079FAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079FAC8: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8079FACC: lui         $t9, 0x807A
    ctx->r25 = S32(RELOC_HI16(838, 0X1618) << 16);
    // 0x8079FAD0: addiu       $t9, $t9, 0xC78
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(838, 0X1618));
    // 0x8079FAD4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8079FAD8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8079FADC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8079FAE0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8079FAE4: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8079FAE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079FAEC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079FAF0: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x8079FAF4: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8079FAF8: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8079FAFC: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8079FB00: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8079FB04: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x8079FB08: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8079FB0C: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x8079FB10: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8079FB14: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x8079FB18: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8079FB1C: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x8079FB20: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x8079FB24: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8079FB28: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8079FB2C: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x8079FB30: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8079FB34: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8079FB38: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8079FB3C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8079FB40: sltu        $at, $t4, $t9
    ctx->r1 = ctx->r12 < ctx->r25 ? 1 : 0;
    // 0x8079FB44: bnel        $at, $zero, L_8079FB7C
    if (ctx->r1 != 0) {
        // 0x8079FB48: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8079FB7C;
    }
    goto skip_0;
    // 0x8079FB48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8079FB4C: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8079FB50: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8079FB54: lbu         $t1, 0x8($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X8);
    // 0x8079FB58: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8079FB5C: sltu        $at, $t6, $t1
    ctx->r1 = ctx->r14 < ctx->r9 ? 1 : 0;
    // 0x8079FB60: bne         $at, $zero, L_8079FB70
    if (ctx->r1 != 0) {
        // 0x8079FB64: nop
    
            goto L_8079FB70;
    }
    // 0x8079FB64: nop

    // 0x8079FB68: b           L_8079FB7C
    // 0x8079FB6C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
        goto L_8079FB7C;
    // 0x8079FB6C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_8079FB70:
    // 0x8079FB70: b           L_8079FB7C
    // 0x8079FB74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8079FB7C;
    // 0x8079FB74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8079FB78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8079FB7C:
    // 0x8079FB7C: jr          $ra
    // 0x8079FB80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8079FB80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8057E888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057E888: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057E88C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057E890: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8057E894: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8057E898: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8057E89C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8057E8A0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8057E8A4: nop

    // 0x8057E8A8: bc1fl       L_8057E928
    if (!c1cs) {
        // 0x8057E8AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057E928;
    }
    goto skip_0;
    // 0x8057E8AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8057E8B0: lwc1        $f6, 0x2C4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X2C4);
    // 0x8057E8B4: lwc1        $f8, 0x20C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20C);
    // 0x8057E8B8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8057E8BC: nop

    // 0x8057E8C0: bc1fl       L_8057E928
    if (!c1cs) {
        // 0x8057E8C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057E928;
    }
    goto skip_1;
    // 0x8057E8C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8057E8C8: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x8057E8CC: swc1        $f0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f0.u32l;
    // 0x8057E8D0: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8057E8D4: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x8057E8D8: lwc1        $f10, 0x2C0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C0);
    // 0x8057E8DC: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x8057E8E0: lwc1        $f16, 0x2C4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C4);
    // 0x8057E8E4: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
    // 0x8057E8E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8057E8EC: addiu       $a1, $a3, 0x3C
    ctx->r5 = ADD32(ctx->r7, 0X3C);
    // 0x8057E8F0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8057E8F4: jal         0x8057DD6C
    // 0x8057E8F8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_8057DD6C(rdram, ctx);
        goto after_0;
    // 0x8057E8F8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8057E8FC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8057E900: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8057E904: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8057E908: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8057E90C: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x8057E910: sw          $zero, 0x2B4($a2)
    MEM_W(0X2B4, ctx->r6) = 0;
    // 0x8057E914: sw          $t6, 0x2CC($a2)
    MEM_W(0X2CC, ctx->r6) = ctx->r14;
    // 0x8057E918: swc1        $f18, 0x2D0($a2)
    MEM_W(0X2D0, ctx->r6) = ctx->f18.u32l;
    // 0x8057E91C: sw          $zero, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = 0;
    // 0x8057E920: sw          $zero, 0x2C8($a2)
    MEM_W(0X2C8, ctx->r6) = 0;
    // 0x8057E924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057E928:
    // 0x8057E928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057E92C: jr          $ra
    // 0x8057E930: nop

    return;
    // 0x8057E930: nop

;}
RECOMP_FUNC void func_804736C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804736C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804736C4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x804736C8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x804736CC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x804736D0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x804736D4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x804736D8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x804736DC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x804736E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x804736E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x804736E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804736EC: lw          $s4, 0x174($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X174);
    // 0x804736F0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x804736F4: addiu       $s1, $a0, 0xC4
    ctx->r17 = ADD32(ctx->r4, 0XC4);
    // 0x804736F8: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x804736FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80473700: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80473704: jal         0x80048F84
    // 0x80473708: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80473708: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    after_0:
    // 0x8047370C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80473710: jal         0x80048F84
    // 0x80473714: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80473714: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80473718: lw          $t7, 0x1F4($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X1F4);
    // 0x8047371C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80473720: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80473724: jal         0x80049D74
    // 0x80473728: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    func_80049D74(rdram, ctx);
        goto after_2;
    // 0x80473728: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    after_2:
    // 0x8047372C: beq         $s0, $zero, L_804737DC
    if (ctx->r16 == 0) {
        // 0x80473730: sll         $s1, $s0, 2
        ctx->r17 = S32(ctx->r16 << 2);
            goto L_804737DC;
    }
    // 0x80473730: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x80473734: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80473738: lui         $fp, 0x8047
    ctx->r30 = S32(RELOC_HI16(161, 0XCE8) << 16);
    // 0x8047373C: addiu       $fp, $fp, 0x3E78
    ctx->r30 = ADD32(ctx->r30, (int16_t)RELOC_LO16(161, 0XCE8));
    // 0x80473740: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x80473744: addiu       $s7, $zero, 0x40
    ctx->r23 = ADD32(0, 0X40);
    // 0x80473748: addiu       $s6, $zero, 0x38
    ctx->r22 = ADD32(0, 0X38);
    // 0x8047374C: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x80473750: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x80473754: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
L_80473758:
    // 0x80473758: addiu       $s1, $s1, -0x18
    ctx->r17 = ADD32(ctx->r17, -0X18);
    // 0x8047375C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80473760: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x80473764: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x80473768: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8047376C: beq         $v1, $zero, L_804737BC
    if (ctx->r3 == 0) {
        // 0x80473770: nop
    
            goto L_804737BC;
    }
    // 0x80473770: nop

    // 0x80473774: beq         $s5, $v1, L_804737BC
    if (ctx->r21 == ctx->r3) {
        // 0x80473778: nop
    
            goto L_804737BC;
    }
    // 0x80473778: nop

    // 0x8047377C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80473780: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x80473784: beq         $s6, $v1, L_804737BC
    if (ctx->r22 == ctx->r3) {
        // 0x80473788: nop
    
            goto L_804737BC;
    }
    // 0x80473788: nop

    // 0x8047378C: beq         $s7, $v1, L_804737BC
    if (ctx->r23 == ctx->r3) {
        // 0x80473790: nop
    
            goto L_804737BC;
    }
    // 0x80473790: nop

    // 0x80473794: beq         $s0, $s2, L_804737D4
    if (ctx->r16 == ctx->r18) {
        // 0x80473798: sll         $t0, $s0, 2
        ctx->r8 = S32(ctx->r16 << 2);
            goto L_804737D4;
    }
    // 0x80473798: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x8047379C: addu        $t1, $fp, $t0
    ctx->r9 = ADD32(ctx->r30, ctx->r8);
    // 0x804737A0: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x804737A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x804737A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804737AC: jalr        $t9
    // 0x804737B0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x804737B0: nop

    after_3:
    // 0x804737B4: b           L_804737D4
    // 0x804737B8: nop

        goto L_804737D4;
    // 0x804737B8: nop

L_804737BC:
    // 0x804737BC: bne         $s0, $s2, L_804737D4
    if (ctx->r16 != ctx->r18) {
        // 0x804737C0: nop
    
            goto L_804737D4;
    }
    // 0x804737C0: nop

    // 0x804737C4: lw          $v0, 0x1F4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1F4);
    // 0x804737C8: lhu         $t2, 0x0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X0);
    // 0x804737CC: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x804737D0: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
L_804737D4:
    // 0x804737D4: bnel        $s0, $zero, L_80473758
    if (ctx->r16 != 0) {
        // 0x804737D8: lw          $t8, 0x0($s4)
        ctx->r24 = MEM_W(ctx->r20, 0X0);
            goto L_80473758;
    }
    goto skip_0;
    // 0x804737D8: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    skip_0:
L_804737DC:
    // 0x804737DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x804737E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804737E4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x804737E8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x804737EC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x804737F0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x804737F4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x804737F8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x804737FC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80473800: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80473804: jr          $ra
    // 0x80473808: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80473808: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_804EFB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EFB58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EFB5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EFB60: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804EFB64: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x804EFB68: bne         $v1, $zero, L_804EFB84
    if (ctx->r3 != 0) {
        // 0x804EFB6C: nop
    
            goto L_804EFB84;
    }
    // 0x804EFB6C: nop

    // 0x804EFB70: jal         0x80045A34
    // 0x804EFB74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804EFB74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804EFB78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804EFB7C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x804EFB80: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
L_804EFB84:
    // 0x804EFB84: bne         $v1, $zero, L_804EFB94
    if (ctx->r3 != 0) {
        // 0x804EFB88: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_804EFB94;
    }
    // 0x804EFB88: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x804EFB8C: b           L_804EFBA4
    // 0x804EFB90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804EFBA4;
    // 0x804EFB90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804EFB94:
    // 0x804EFB94: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x804EFB98: jal         0x800657CC
    // 0x804EFB9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x804EFB9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x804EFBA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804EFBA4:
    // 0x804EFBA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EFBA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EFBAC: jr          $ra
    // 0x804EFBB0: nop

    return;
    // 0x804EFBB0: nop

;}
RECOMP_FUNC void func_80423AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423AA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80423AA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80423AA8: jal         0x80423A0C
    // 0x80423AAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80423A0C(rdram, ctx);
        goto after_0;
    // 0x80423AAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80423AB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80423AB4: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80423AB8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80423ABC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80423AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80423AC4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80423AC8: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80423ACC: lwc1        $f6, 0xEC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x80423AD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80423AD4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80423AD8: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x80423ADC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80423AE0: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80423AE4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80423AE8: nop

    // 0x80423AEC: bc1fl       L_80423B00
    if (!c1cs) {
        // 0x80423AF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80423B00;
    }
    goto skip_0;
    // 0x80423AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80423AF4: jal         0x80423DB8
    // 0x80423AF8: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    func_80423DB8(rdram, ctx);
        goto after_1;
    // 0x80423AF8: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    after_1:
    // 0x80423AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80423B00:
    // 0x80423B00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80423B04: jr          $ra
    // 0x80423B08: nop

    return;
    // 0x80423B08: nop

;}
RECOMP_FUNC void func_807AD960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AD960: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AD964: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x807AD968: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x807AD96C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807AD970: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x807AD974: jr          $ra
    // 0x807AD978: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x807AD978: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_807B67D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B67D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B67DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B67E0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B67E4: lwc1        $f12, 0x44($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X44);
    // 0x807B67E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807B67EC: jal         0x80081C64
    // 0x807B67F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x807B67F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x807B67F4: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x807B67F8: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x807B67FC: lw          $v1, 0x3F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X3F4);
    // 0x807B6800: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x807B6804: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807B6808: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x807B680C: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x807B6810: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807B6814: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807B6818: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807B681C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807B6820: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807B6824: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x807B6828: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807B682C: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x807B6830: div.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f18.fl);
    // 0x807B6834: div.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x807B6838: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    // 0x807B683C: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x807B6840: lw          $a1, 0xCE8($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XCE8);
    // 0x807B6844: bne         $a1, $zero, L_807B6BA8
    if (ctx->r5 != 0) {
        // 0x807B6848: nop
    
            goto L_807B6BA8;
    }
    // 0x807B6848: nop

    // 0x807B684C: lw          $t6, 0xFB8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XFB8);
    // 0x807B6850: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2EF0) << 16);
    // 0x807B6854: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x807B6858: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x807B685C: bne         $t8, $zero, L_807B68C8
    if (ctx->r24 != 0) {
        // 0x807B6860: nop
    
            goto L_807B68C8;
    }
    // 0x807B6860: nop

    // 0x807B6864: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2EE8) << 16);
    // 0x807B6868: lwc1        $f2, 0x76E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2EE8));
    // 0x807B686C: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x807B6870: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807B6874: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6878: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x807B687C: lui         $at, 0xC264
    ctx->r1 = S32(0XC264 << 16);
    // 0x807B6880: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x807B6884: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807B6888: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2EEC) << 16);
    // 0x807B688C: swc1        $f16, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f16.u32l;
    // 0x807B6890: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6894: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x807B6898: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x807B689C: swc1        $f4, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f4.u32l;
    // 0x807B68A0: lwc1        $f10, 0x76EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2EEC));
    // 0x807B68A4: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B68A8: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x807B68AC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x807B68B0: swc1        $f16, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f16.u32l;
    // 0x807B68B4: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B68B8: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x807B68BC: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x807B68C0: b           L_807B691C
    // 0x807B68C4: swc1        $f8, 0x70($t2)
    MEM_W(0X70, ctx->r10) = ctx->f8.u32l;
        goto L_807B691C;
    // 0x807B68C4: swc1        $f8, 0x70($t2)
    MEM_W(0X70, ctx->r10) = ctx->f8.u32l;
L_807B68C8:
    // 0x807B68C8: lwc1        $f2, 0x76F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2EF0));
    // 0x807B68CC: lui         $at, 0x4208
    ctx->r1 = S32(0X4208 << 16);
    // 0x807B68D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807B68D4: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B68D8: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x807B68DC: lui         $at, 0xC264
    ctx->r1 = S32(0XC264 << 16);
    // 0x807B68E0: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807B68E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807B68E8: swc1        $f10, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f10.u32l;
    // 0x807B68EC: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B68F0: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x807B68F4: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x807B68F8: swc1        $f8, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f8.u32l;
    // 0x807B68FC: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6900: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x807B6904: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x807B6908: swc1        $f6, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f6.u32l;
    // 0x807B690C: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6910: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x807B6914: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x807B6918: swc1        $f16, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f16.u32l;
L_807B691C:
    // 0x807B691C: lw          $t7, 0xFB8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XFB8);
    // 0x807B6920: lui         $at, 0xC130
    ctx->r1 = S32(0XC130 << 16);
    // 0x807B6924: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x807B6928: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x807B692C: bnel        $t9, $zero, L_807B6994
    if (ctx->r25 != 0) {
        // 0x807B6930: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_807B6994;
    }
    goto skip_0;
    // 0x807B6930: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_0:
    // 0x807B6934: lui         $at, 0xC130
    ctx->r1 = S32(0XC130 << 16);
    // 0x807B6938: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807B693C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x807B6940: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807B6944: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6948: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x807B694C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2EF4) << 16);
    // 0x807B6950: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x807B6954: swc1        $f4, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f4.u32l;
    // 0x807B6958: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B695C: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x807B6960: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x807B6964: swc1        $f10, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f10.u32l;
    // 0x807B6968: lwc1        $f18, 0x76F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2EF4));
    // 0x807B696C: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6970: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x807B6974: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x807B6978: swc1        $f8, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->f8.u32l;
    // 0x807B697C: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6980: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x807B6984: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x807B6988: b           L_807B69DC
    // 0x807B698C: swc1        $f6, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f6.u32l;
        goto L_807B69DC;
    // 0x807B698C: swc1        $f6, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f6.u32l;
    // 0x807B6990: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_807B6994:
    // 0x807B6994: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x807B6998: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807B699C: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B69A0: lw          $t4, 0x10($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X10);
    // 0x807B69A4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807B69A8: swc1        $f18, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->f18.u32l;
    // 0x807B69AC: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B69B0: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x807B69B4: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x807B69B8: swc1        $f4, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f4.u32l;
    // 0x807B69BC: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B69C0: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x807B69C4: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807B69C8: swc1        $f10, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f10.u32l;
    // 0x807B69CC: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B69D0: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x807B69D4: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x807B69D8: swc1        $f18, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->f18.u32l;
L_807B69DC:
    // 0x807B69DC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2EF8) << 16);
    // 0x807B69E0: lwc1        $f0, 0x76F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2EF8));
    // 0x807B69E4: lui         $at, 0x42C4
    ctx->r1 = S32(0X42C4 << 16);
    // 0x807B69E8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807B69EC: lui         $at, 0xC140
    ctx->r1 = S32(0XC140 << 16);
    // 0x807B69F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807B69F4: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B69F8: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x807B69FC: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
    // 0x807B6A00: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x807B6A04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807B6A08: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x807B6A0C: swc1        $f6, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f6.u32l;
    // 0x807B6A10: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6A14: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x807B6A18: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807B6A1C: swc1        $f18, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f18.u32l;
    // 0x807B6A20: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6A24: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    // 0x807B6A28: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x807B6A2C: swc1        $f4, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->f4.u32l;
    // 0x807B6A30: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6A34: lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14);
    // 0x807B6A38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807B6A3C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x807B6A40: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2EFC) << 16);
    // 0x807B6A44: swc1        $f10, 0x70($t1)
    MEM_W(0X70, ctx->r9) = ctx->f10.u32l;
    // 0x807B6A48: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6A4C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x807B6A50: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x807B6A54: swc1        $f18, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->f18.u32l;
    // 0x807B6A58: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6A5C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x807B6A60: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x807B6A64: swc1        $f6, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f6.u32l;
    // 0x807B6A68: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6A6C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x807B6A70: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x807B6A74: swc1        $f16, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->f16.u32l;
    // 0x807B6A78: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6A7C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x807B6A80: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x807B6A84: swc1        $f8, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->f8.u32l;
    // 0x807B6A88: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6A8C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x807B6A90: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x807B6A94: swc1        $f6, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f6.u32l;
    // 0x807B6A98: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6A9C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x807B6AA0: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x807B6AA4: swc1        $f16, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f16.u32l;
    // 0x807B6AA8: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6AAC: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x807B6AB0: lwc1        $f2, 0x76FC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2EFC));
    // 0x807B6AB4: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x807B6AB8: lui         $at, 0x4298
    ctx->r1 = S32(0X4298 << 16);
    // 0x807B6ABC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807B6AC0: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x807B6AC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807B6AC8: lui         $at, 0x4288
    ctx->r1 = S32(0X4288 << 16);
    // 0x807B6ACC: swc1        $f8, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->f8.u32l;
    // 0x807B6AD0: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6AD4: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x807B6AD8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x807B6ADC: swc1        $f6, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f6.u32l;
    // 0x807B6AE0: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6AE4: lw          $t0, 0x1C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1C);
    // 0x807B6AE8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807B6AEC: swc1        $f18, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f18.u32l;
    // 0x807B6AF0: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6AF4: lw          $t1, 0x1C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1C);
    // 0x807B6AF8: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x807B6AFC: swc1        $f4, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f4.u32l;
    // 0x807B6B00: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6B04: lw          $t2, 0x1C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1C);
    // 0x807B6B08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807B6B0C: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807B6B10: swc1        $f10, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->f10.u32l;
    // 0x807B6B14: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6B18: lw          $t3, 0x1C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1C);
    // 0x807B6B1C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x807B6B20: swc1        $f18, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f18.u32l;
    // 0x807B6B24: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6B28: lw          $t4, 0x20($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X20);
    // 0x807B6B2C: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x807B6B30: swc1        $f6, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->f6.u32l;
    // 0x807B6B34: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6B38: lw          $t5, 0x20($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X20);
    // 0x807B6B3C: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x807B6B40: swc1        $f16, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f16.u32l;
    // 0x807B6B44: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6B48: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x807B6B4C: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x807B6B50: swc1        $f8, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f8.u32l;
    // 0x807B6B54: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6B58: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x807B6B5C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x807B6B60: swc1        $f6, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->f6.u32l;
    // 0x807B6B64: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6B68: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x807B6B6C: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x807B6B70: swc1        $f16, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f16.u32l;
    // 0x807B6B74: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6B78: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x807B6B7C: mul.s       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x807B6B80: swc1        $f8, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f8.u32l;
    // 0x807B6B84: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6B88: lw          $t0, 0x24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X24);
    // 0x807B6B8C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x807B6B90: swc1        $f6, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->f6.u32l;
    // 0x807B6B94: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6B98: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x807B6B9C: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x807B6BA0: b           L_807B6E10
    // 0x807B6BA4: swc1        $f16, 0x70($t1)
    MEM_W(0X70, ctx->r9) = ctx->f16.u32l;
        goto L_807B6E10;
    // 0x807B6BA4: swc1        $f16, 0x70($t1)
    MEM_W(0X70, ctx->r9) = ctx->f16.u32l;
L_807B6BA8:
    // 0x807B6BA8: bnel        $a1, $at, L_807B6E14
    if (ctx->r5 != ctx->r1) {
        // 0x807B6BAC: lui         $at, 0x40F0
        ctx->r1 = S32(0X40F0 << 16);
            goto L_807B6E14;
    }
    goto skip_1;
    // 0x807B6BAC: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    skip_1:
    // 0x807B6BB0: lw          $t2, 0xFB8($a2)
    ctx->r10 = MEM_W(ctx->r6, 0XFB8);
    // 0x807B6BB4: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2F08) << 16);
    // 0x807B6BB8: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x807B6BBC: srl         $t4, $t3, 30
    ctx->r12 = S32(U32(ctx->r11) >> 30);
    // 0x807B6BC0: bne         $t4, $zero, L_807B6C2C
    if (ctx->r12 != 0) {
        // 0x807B6BC4: nop
    
            goto L_807B6C2C;
    }
    // 0x807B6BC4: nop

    // 0x807B6BC8: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2F00) << 16);
    // 0x807B6BCC: lwc1        $f2, 0x7700($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2F00));
    // 0x807B6BD0: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x807B6BD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807B6BD8: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6BDC: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x807B6BE0: lui         $at, 0xC260
    ctx->r1 = S32(0XC260 << 16);
    // 0x807B6BE4: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x807B6BE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807B6BEC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2F04) << 16);
    // 0x807B6BF0: swc1        $f4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f4.u32l;
    // 0x807B6BF4: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6BF8: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x807B6BFC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x807B6C00: swc1        $f16, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f16.u32l;
    // 0x807B6C04: lwc1        $f8, 0x7704($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2F04));
    // 0x807B6C08: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6C0C: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x807B6C10: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x807B6C14: swc1        $f4, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f4.u32l;
    // 0x807B6C18: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6C1C: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x807B6C20: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807B6C24: b           L_807B6C80
    // 0x807B6C28: swc1        $f10, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f10.u32l;
        goto L_807B6C80;
    // 0x807B6C28: swc1        $f10, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f10.u32l;
L_807B6C2C:
    // 0x807B6C2C: lwc1        $f2, 0x7708($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2F08));
    // 0x807B6C30: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x807B6C34: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807B6C38: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6C3C: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x807B6C40: lui         $at, 0xC260
    ctx->r1 = S32(0XC260 << 16);
    // 0x807B6C44: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x807B6C48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807B6C4C: swc1        $f8, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f8.u32l;
    // 0x807B6C50: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6C54: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x807B6C58: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807B6C5C: swc1        $f10, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f10.u32l;
    // 0x807B6C60: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6C64: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x807B6C68: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x807B6C6C: swc1        $f18, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f18.u32l;
    // 0x807B6C70: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6C74: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x807B6C78: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x807B6C7C: swc1        $f4, 0x70($t2)
    MEM_W(0X70, ctx->r10) = ctx->f4.u32l;
L_807B6C80:
    // 0x807B6C80: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2F0C) << 16);
    // 0x807B6C84: lwc1        $f0, 0x770C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2F0C));
    // 0x807B6C88: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x807B6C8C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807B6C90: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x807B6C94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807B6C98: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6C9C: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x807B6CA0: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x807B6CA4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x807B6CA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807B6CAC: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x807B6CB0: swc1        $f16, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f16.u32l;
    // 0x807B6CB4: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6CB8: lw          $t4, 0x10($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X10);
    // 0x807B6CBC: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x807B6CC0: swc1        $f4, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f4.u32l;
    // 0x807B6CC4: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6CC8: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x807B6CCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807B6CD0: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807B6CD4: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x807B6CD8: swc1        $f10, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f10.u32l;
    // 0x807B6CDC: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6CE0: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x807B6CE4: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x807B6CE8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807B6CEC: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x807B6CF0: swc1        $f18, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f18.u32l;
    // 0x807B6CF4: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6CF8: lw          $t7, 0x14($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14);
    // 0x807B6CFC: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x807B6D00: swc1        $f6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f6.u32l;
    // 0x807B6D04: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6D08: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x807B6D0C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807B6D10: swc1        $f18, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f18.u32l;
    // 0x807B6D14: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6D18: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x807B6D1C: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x807B6D20: swc1        $f4, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->f4.u32l;
    // 0x807B6D24: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6D28: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    // 0x807B6D2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807B6D30: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x807B6D34: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x807B6D38: swc1        $f10, 0x70($t0)
    MEM_W(0X70, ctx->r8) = ctx->f10.u32l;
    // 0x807B6D3C: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6D40: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x807B6D44: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x807B6D48: swc1        $f18, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f18.u32l;
    // 0x807B6D4C: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6D50: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x807B6D54: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x807B6D58: swc1        $f6, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f6.u32l;
    // 0x807B6D5C: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6D60: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x807B6D64: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x807B6D68: swc1        $f16, 0x6C($t3)
    MEM_W(0X6C, ctx->r11) = ctx->f16.u32l;
    // 0x807B6D6C: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6D70: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x807B6D74: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807B6D78: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x807B6D7C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x807B6D80: swc1        $f8, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->f8.u32l;
    // 0x807B6D84: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6D88: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x807B6D8C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x807B6D90: swc1        $f6, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f6.u32l;
    // 0x807B6D94: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6D98: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x807B6D9C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807B6DA0: swc1        $f18, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f18.u32l;
    // 0x807B6DA4: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6DA8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x807B6DAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807B6DB0: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x807B6DB4: lui         $at, 0x4292
    ctx->r1 = S32(0X4292 << 16);
    // 0x807B6DB8: swc1        $f4, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f4.u32l;
    // 0x807B6DBC: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6DC0: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x807B6DC4: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x807B6DC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807B6DCC: swc1        $f10, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f10.u32l;
    // 0x807B6DD0: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6DD4: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    // 0x807B6DD8: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x807B6DDC: swc1        $f8, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f8.u32l;
    // 0x807B6DE0: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6DE4: lw          $t0, 0x18($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X18);
    // 0x807B6DE8: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807B6DEC: swc1        $f10, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f10.u32l;
    // 0x807B6DF0: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6DF4: lw          $t1, 0x18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X18);
    // 0x807B6DF8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x807B6DFC: swc1        $f18, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f18.u32l;
    // 0x807B6E00: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6E04: lw          $t2, 0x18($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X18);
    // 0x807B6E08: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x807B6E0C: swc1        $f4, 0x70($t2)
    MEM_W(0X70, ctx->r10) = ctx->f4.u32l;
L_807B6E10:
    // 0x807B6E10: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
L_807B6E14:
    // 0x807B6E14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807B6E18: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807B6E1C: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x807B6E20: lui         $at, 0x40B0
    ctx->r1 = S32(0X40B0 << 16);
    // 0x807B6E24: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x807B6E28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807B6E2C: swc1        $f16, 0x6C($t3)
    MEM_W(0X6C, ctx->r11) = ctx->f16.u32l;
    // 0x807B6E30: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807B6E34: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x807B6E38: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x807B6E3C: swc1        $f4, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->f4.u32l;
    // 0x807B6E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B6E44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B6E48: jr          $ra
    // 0x807B6E4C: nop

    return;
    // 0x807B6E4C: nop

;}
RECOMP_FUNC void func_80698EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80698EF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80698EF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80698EFC: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x80698F00: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80698F04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80698F08: jal         0x80065728
    // 0x80698F0C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80698F0C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80698F10: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80698F14: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80698F18: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80698F1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80698F20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80698F24: jr          $ra
    // 0x80698F28: nop

    return;
    // 0x80698F28: nop

;}
RECOMP_FUNC void func_80716B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716B78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80716B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80716B80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80716B84: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80716B88: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80716B8C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80716B90: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80716B94: lw          $v1, 0x6E2C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E2C);
    // 0x80716B98: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80716B9C: beql        $v1, $zero, L_80716BB8
    if (ctx->r3 == 0) {
        // 0x80716BA0: lw          $v1, 0x0($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X0);
            goto L_80716BB8;
    }
    goto skip_0;
    // 0x80716BA0: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    skip_0:
    // 0x80716BA4: jal         0x80716A88
    // 0x80716BA8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    func_80716A88(rdram, ctx);
        goto after_0;
    // 0x80716BA8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_0:
    // 0x80716BAC: b           L_80716BDC
    // 0x80716BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80716BDC;
    // 0x80716BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80716BB4: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
L_80716BB8:
    // 0x80716BB8: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80716BBC: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80716BC0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80716BC4: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80716BC8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80716BCC: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80716BD0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80716BD4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80716BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80716BDC:
    // 0x80716BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80716BE0: jr          $ra
    // 0x80716BE4: nop

    return;
    // 0x80716BE4: nop

;}
RECOMP_FUNC void func_80436B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80436B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80436B44: jal         0x8004700C
    // 0x80436B48: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80436B48: nop

    after_0:
    // 0x80436B4C: beq         $v0, $zero, L_80436B70
    if (ctx->r2 == 0) {
        // 0x80436B50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80436B70;
    }
    // 0x80436B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80436B54: lw          $v1, 0x174($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X174);
    // 0x80436B58: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80436B5C: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x80436B60: beql        $t7, $zero, L_80436B74
    if (ctx->r15 == 0) {
        // 0x80436B64: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80436B74;
    }
    goto skip_0;
    // 0x80436B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80436B68: b           L_80436B74
    // 0x80436B6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80436B74;
    // 0x80436B6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80436B70:
    // 0x80436B70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80436B74:
    // 0x80436B74: jr          $ra
    // 0x80436B78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80436B78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80535D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535D88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80535D8C: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(351, 0X1A950) << 16);
    // 0x80535D90: lwc1        $f0, 0x1E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(351, 0X1A950));
    // 0x80535D94: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80535D98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80535D9C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80535DA0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80535DA4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80535DA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80535DAC: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x80535DB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80535DB4: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80535DB8: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80535DBC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80535DC0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80535DC4: jal         0x8053589C
    // 0x80535DC8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8053589C(rdram, ctx);
        goto after_0;
    // 0x80535DC8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80535DCC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80535DD0: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(351, 0X1A954) << 16);
    // 0x80535DD4: lwc1        $f2, 0x1E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(351, 0X1A954));
    // 0x80535DD8: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x80535DDC: addiu       $t8, $zero, 0x1EF0
    ctx->r24 = ADD32(0, 0X1EF0);
    // 0x80535DE0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80535DE4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80535DE8: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80535DEC: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80535DF0: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80535DF4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80535DF8: jal         0x8053589C
    // 0x80535DFC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_8053589C(rdram, ctx);
        goto after_1;
    // 0x80535DFC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80535E00: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80535E04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80535E08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80535E0C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80535E10: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80535E14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80535E18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80535E1C: jr          $ra
    // 0x80535E20: nop

    return;
    // 0x80535E20: nop

;}
RECOMP_FUNC void func_8042B410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042B410: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8042B414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042B418: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042B41C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8042B420: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8042B424: lw          $t7, 0x2C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X2C);
    // 0x8042B428: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8042B42C: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x8042B430: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x8042B434: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x8042B438: lh          $t8, 0x13C($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X13C);
    // 0x8042B43C: lh          $t7, 0x13E($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X13E);
    // 0x8042B440: lh          $t6, 0x144($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X144);
    // 0x8042B444: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8042B448: lw          $t8, 0x168($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X168);
    // 0x8042B44C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x8042B450: mflo        $t9
    ctx->r25 = lo;
    // 0x8042B454: nop

    // 0x8042B458: nop

    // 0x8042B45C: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8042B460: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x8042B464: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    // 0x8042B468: mflo        $t7
    ctx->r15 = lo;
    // 0x8042B46C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8042B470: jal         0x8042A8B0
    // 0x8042B474: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    func_8042A8B0(rdram, ctx);
        goto after_0;
    // 0x8042B474: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    after_0:
    // 0x8042B478: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8042B47C: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8042B480: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8042B484: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8042B488: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x8042B48C: lui         $t4, 0xFD90
    ctx->r12 = S32(0XFD90 << 16);
    // 0x8042B490: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x8042B494: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8042B498: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8042B49C: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x8042B4A0: lui         $t5, 0xF590
    ctx->r13 = S32(0XF590 << 16);
    // 0x8042B4A4: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8042B4A8: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x8042B4AC: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8042B4B0: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x8042B4B4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8042B4B8: lui         $ra, 0xE600
    ctx->r31 = S32(0XE600 << 16);
    // 0x8042B4BC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8042B4C0: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x8042B4C4: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x8042B4C8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8042B4CC: sw          $ra, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r31;
    // 0x8042B4D0: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8042B4D4: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8042B4D8: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x8042B4DC: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8042B4E0: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x8042B4E4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8042B4E8: lw          $t8, 0x40($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X40);
    // 0x8042B4EC: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
    // 0x8042B4F0: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8042B4F4: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8042B4F8: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8042B4FC: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8042B500: mflo        $a3
    ctx->r7 = lo;
    // 0x8042B504: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8042B508: sra         $a3, $a3, 1
    ctx->r7 = S32(SIGNED(ctx->r7) >> 1);
    // 0x8042B50C: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8042B510: slti        $at, $a3, 0x7FF
    ctx->r1 = SIGNED(ctx->r7) < 0X7FF ? 1 : 0;
    // 0x8042B514: beq         $at, $zero, L_8042B524
    if (ctx->r1 == 0) {
        // 0x8042B518: nop
    
            goto L_8042B524;
    }
    // 0x8042B518: nop

    // 0x8042B51C: b           L_8042B524
    // 0x8042B520: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
        goto L_8042B524;
    // 0x8042B520: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
L_8042B524:
    // 0x8042B524: bgez        $a1, L_8042B534
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8042B528: sra         $v0, $a1, 3
        ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
            goto L_8042B534;
    }
    // 0x8042B528: sra         $v0, $a1, 3
    ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8042B52C: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x8042B530: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8042B534:
    // 0x8042B534: bgtz        $v0, L_8042B544
    if (SIGNED(ctx->r2) > 0) {
        // 0x8042B538: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8042B544;
    }
    // 0x8042B538: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8042B53C: b           L_8042B544
    // 0x8042B540: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8042B544;
    // 0x8042B540: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8042B544:
    // 0x8042B544: bgtz        $v0, L_8042B554
    if (SIGNED(ctx->r2) > 0) {
        // 0x8042B548: addiu       $t6, $a3, 0x7FF
        ctx->r14 = ADD32(ctx->r7, 0X7FF);
            goto L_8042B554;
    }
    // 0x8042B548: addiu       $t6, $a3, 0x7FF
    ctx->r14 = ADD32(ctx->r7, 0X7FF);
    // 0x8042B54C: b           L_8042B558
    // 0x8042B550: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8042B558;
    // 0x8042B550: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8042B554:
    // 0x8042B554: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8042B558:
    // 0x8042B558: div         $zero, $t6, $a1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r5)));
    // 0x8042B55C: mflo        $t8
    ctx->r24 = lo;
    // 0x8042B560: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8042B564: bne         $a1, $zero, L_8042B570
    if (ctx->r5 != 0) {
        // 0x8042B568: nop
    
            goto L_8042B570;
    }
    // 0x8042B568: nop

    // 0x8042B56C: break       7
    do_break(2151855468);
L_8042B570:
    // 0x8042B570: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8042B574: bne         $a1, $at, L_8042B588
    if (ctx->r5 != ctx->r1) {
        // 0x8042B578: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8042B588;
    }
    // 0x8042B578: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8042B57C: bne         $t6, $at, L_8042B588
    if (ctx->r14 != ctx->r1) {
        // 0x8042B580: nop
    
            goto L_8042B588;
    }
    // 0x8042B580: nop

    // 0x8042B584: break       6
    do_break(2151855492);
L_8042B588:
    // 0x8042B588: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x8042B58C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8042B590: or          $t9, $t7, $t3
    ctx->r25 = ctx->r15 | ctx->r11;
    // 0x8042B594: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8042B598: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8042B59C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8042B5A0: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8042B5A4: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8042B5A8: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8042B5AC: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x8042B5B0: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8042B5B4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8042B5B8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8042B5BC: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x8042B5C0: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x8042B5C4: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x8042B5C8: lw          $t9, 0x38($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X38);
    // 0x8042B5CC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8042B5D0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8042B5D4: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x8042B5D8: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8042B5DC: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8042B5E0: sll         $t9, $t6, 9
    ctx->r25 = S32(ctx->r14 << 9);
    // 0x8042B5E4: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8042B5E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8042B5EC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8042B5F0: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8042B5F4: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x8042B5F8: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x8042B5FC: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8042B600: lw          $t8, 0x40($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X40);
    // 0x8042B604: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8042B608: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8042B60C: lw          $t8, 0x38($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X38);
    // 0x8042B610: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8042B614: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8042B618: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x8042B61C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8042B620: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8042B624: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8042B628: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8042B62C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8042B630: lw          $t8, 0x2C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X2C);
    // 0x8042B634: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8042B638: addu        $t7, $a2, $t9
    ctx->r15 = ADD32(ctx->r6, ctx->r25);
    // 0x8042B63C: lw          $t6, 0x14($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X14);
    // 0x8042B640: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x8042B644: lw          $t8, 0x40($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X40);
    // 0x8042B648: lw          $t7, 0x38($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X38);
    // 0x8042B64C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8042B650: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8042B654: multu       $t9, $t7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8042B658: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8042B65C: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x8042B660: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x8042B664: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8042B668: mflo        $t6
    ctx->r14 = lo;
    // 0x8042B66C: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8042B670: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x8042B674: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8042B678: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x8042B67C: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x8042B680: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8042B684: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x8042B688: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8042B68C: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8042B690: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8042B694: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x8042B698: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8042B69C: sw          $ra, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r31;
    // 0x8042B6A0: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8042B6A4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8042B6A8: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8042B6AC: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x8042B6B0: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x8042B6B4: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8042B6B8: lw          $t9, 0x40($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X40);
    // 0x8042B6BC: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
    // 0x8042B6C0: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8042B6C4: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8042B6C8: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x8042B6CC: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8042B6D0: mflo        $a3
    ctx->r7 = lo;
    // 0x8042B6D4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8042B6D8: sra         $a3, $a3, 1
    ctx->r7 = S32(SIGNED(ctx->r7) >> 1);
    // 0x8042B6DC: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8042B6E0: slti        $at, $a3, 0x7FF
    ctx->r1 = SIGNED(ctx->r7) < 0X7FF ? 1 : 0;
    // 0x8042B6E4: beq         $at, $zero, L_8042B6F4
    if (ctx->r1 == 0) {
        // 0x8042B6E8: nop
    
            goto L_8042B6F4;
    }
    // 0x8042B6E8: nop

    // 0x8042B6EC: b           L_8042B6F4
    // 0x8042B6F0: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
        goto L_8042B6F4;
    // 0x8042B6F0: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
L_8042B6F4:
    // 0x8042B6F4: bgez        $a1, L_8042B704
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8042B6F8: sra         $v0, $a1, 3
        ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
            goto L_8042B704;
    }
    // 0x8042B6F8: sra         $v0, $a1, 3
    ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8042B6FC: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x8042B700: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8042B704:
    // 0x8042B704: bgtz        $v0, L_8042B714
    if (SIGNED(ctx->r2) > 0) {
        // 0x8042B708: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8042B714;
    }
    // 0x8042B708: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8042B70C: b           L_8042B714
    // 0x8042B710: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8042B714;
    // 0x8042B710: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8042B714:
    // 0x8042B714: bgtz        $v0, L_8042B724
    if (SIGNED(ctx->r2) > 0) {
        // 0x8042B718: addiu       $t8, $a3, 0x7FF
        ctx->r24 = ADD32(ctx->r7, 0X7FF);
            goto L_8042B724;
    }
    // 0x8042B718: addiu       $t8, $a3, 0x7FF
    ctx->r24 = ADD32(ctx->r7, 0X7FF);
    // 0x8042B71C: b           L_8042B728
    // 0x8042B720: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8042B728;
    // 0x8042B720: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8042B724:
    // 0x8042B724: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8042B728:
    // 0x8042B728: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x8042B72C: mflo        $t9
    ctx->r25 = lo;
    // 0x8042B730: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8042B734: bne         $a1, $zero, L_8042B740
    if (ctx->r5 != 0) {
        // 0x8042B738: nop
    
            goto L_8042B740;
    }
    // 0x8042B738: nop

    // 0x8042B73C: break       7
    do_break(2151855932);
L_8042B740:
    // 0x8042B740: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8042B744: bne         $a1, $at, L_8042B758
    if (ctx->r5 != ctx->r1) {
        // 0x8042B748: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8042B758;
    }
    // 0x8042B748: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8042B74C: bne         $t8, $at, L_8042B758
    if (ctx->r24 != ctx->r1) {
        // 0x8042B750: nop
    
            goto L_8042B758;
    }
    // 0x8042B750: nop

    // 0x8042B754: break       6
    do_break(2151855956);
L_8042B758:
    // 0x8042B758: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x8042B75C: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8042B760: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x8042B764: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8042B768: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8042B76C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8042B770: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8042B774: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8042B778: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8042B77C: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x8042B780: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8042B784: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8042B788: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8042B78C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8042B790: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8042B794: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x8042B798: lw          $t6, 0x38($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X38);
    // 0x8042B79C: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8042B7A0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8042B7A4: addiu       $t9, $t6, 0x7
    ctx->r25 = ADD32(ctx->r14, 0X7);
    // 0x8042B7A8: sra         $t7, $t9, 3
    ctx->r15 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8042B7AC: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x8042B7B0: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x8042B7B4: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8042B7B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8042B7BC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8042B7C0: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8042B7C4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8042B7C8: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x8042B7CC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8042B7D0: lw          $t9, 0x40($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X40);
    // 0x8042B7D4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8042B7D8: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8042B7DC: lw          $t9, 0x38($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X38);
    // 0x8042B7E0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8042B7E4: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8042B7E8: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x8042B7EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8042B7F0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8042B7F4: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8042B7F8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8042B7FC: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8042B800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042B804: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8042B808: jr          $ra
    // 0x8042B80C: nop

    return;
    // 0x8042B80C: nop

;}
RECOMP_FUNC void func_80048EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048EDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048EE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048EE4: jal         0x80048320
    // 0x80048EE8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048320(rdram, ctx);
        goto after_0;
    // 0x80048EE8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x80048EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048EF4: jr          $ra
    // 0x80048EF8: nop

    return;
    // 0x80048EF8: nop

;}
RECOMP_FUNC void func_80567010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80567010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80567014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80567018: jal         0x80566E48
    // 0x8056701C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80566E48(rdram, ctx);
        goto after_0;
    // 0x8056701C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80567020: jal         0x80566F88
    // 0x80567024: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80566F88(rdram, ctx);
        goto after_1;
    // 0x80567024: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80567028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8056702C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80567030: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80567034: jal         0x805670F4
    // 0x80567038: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    func_805670F4(rdram, ctx);
        goto after_2;
    // 0x80567038: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    after_2:
    // 0x8056703C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80567040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80567044: jr          $ra
    // 0x80567048: nop

    return;
    // 0x80567048: nop

;}
RECOMP_FUNC void func_8002F52C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F52C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002F530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F534: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002F53C: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x8002F540: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002F544: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8002F548: jal         0x8002B9E4
    // 0x8002F54C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8002B9E4(rdram, ctx);
        goto after_0;
    // 0x8002F54C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002F550: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F554: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002F558: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002F55C: jal         0x8002F4B0
    // 0x8002F560: sw          $t7, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->r15;
    func_8002F4B0(rdram, ctx);
        goto after_1;
    // 0x8002F560: sw          $t7, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->r15;
    after_1:
    // 0x8002F564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F568: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002F56C: jr          $ra
    // 0x8002F570: nop

    return;
    // 0x8002F570: nop

;}
RECOMP_FUNC void func_80716F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716F48: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716F4C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716F50: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716F54: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716F58: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716F5C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716F60: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716F64: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716F68: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716F6C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716F70: jr          $ra
    // 0x80716F74: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716F74: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8066A50C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A50C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066A510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A514: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8066A518: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8066A51C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8066A520: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(511, 0XCD8) << 16);
    // 0x8066A524: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8066A528: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8066A52C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8066A530: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8066A534: lw          $t8, -0x55A8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(511, 0XCD8));
    // 0x8066A538: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8066A53C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8066A540: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8066A544: jal         0x80048490
    // 0x8066A548: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8066A548: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8066A54C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8066A550: jal         0x80048378
    // 0x8066A554: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8066A554: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8066A558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066A55C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066A560: jr          $ra
    // 0x8066A564: nop

    return;
    // 0x8066A564: nop

;}
RECOMP_FUNC void func_80077F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077F30: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80077F34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80077F38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80077F3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80077F40: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80077F44: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80077F48: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80077F4C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80077F50: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80077F54: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80077F58: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x80077F5C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80077F60: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x80077F64: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80077F68: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80077F6C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80077F70: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80077F74: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80077F78: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80077F7C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80077F80: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x80077F84: lw          $t4, 0x1C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C);
    // 0x80077F88: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x80077F8C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80077F90: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80077F94: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80077F98: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80077F9C: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x80077FA0: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80077FA4: lhu         $a1, 0xA($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0XA);
    // 0x80077FA8: lbu         $a2, 0x18($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X18);
    // 0x80077FAC: jal         0x80077338
    // 0x80077FB0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x80077FB0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80077FB4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80077FB8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80077FBC: lbu         $a1, 0x4($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X4);
    // 0x80077FC0: lbu         $a2, 0x5($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X5);
    // 0x80077FC4: jal         0x8007711C
    // 0x80077FC8: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x80077FC8: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    after_1:
    // 0x80077FCC: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80077FD0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80077FD4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80077FD8: beq         $t9, $zero, L_80077FF4
    if (ctx->r25 == 0) {
        // 0x80077FDC: addiu       $t2, $t1, 0x8
        ctx->r10 = ADD32(ctx->r9, 0X8);
            goto L_80077FF4;
    }
    // 0x80077FDC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80077FE0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80077FE4: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80077FE8: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x80077FEC: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x80077FF0: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
L_80077FF4:
    // 0x80077FF4: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x80077FF8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80077FFC: lui         $t7, 0x102
    ctx->r15 = S32(0X102 << 16);
    // 0x80078000: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x80078004: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80078008: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8007800C: sw          $v1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r3;
    // 0x80078010: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80078014: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80078018: lbu         $a2, 0x9($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X9);
    // 0x8007801C: jal         0x8007812C
    // 0x80078020: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_8007812C(rdram, ctx);
        goto after_2;
    // 0x80078020: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_2:
    // 0x80078024: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80078028: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8007802C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80078030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80078034: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80078038: jr          $ra
    // 0x8007803C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007803C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80564ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80564ECC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80564ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80564ED4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80564ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80564EDC: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80564EE0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80564EE4: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2594) << 16);
    // 0x80564EE8: c.eq.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl == ctx->f14.fl;
    // 0x80564EEC: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80564EF0: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80564EF4: bc1t        L_80564F78
    if (c1cs) {
        // 0x80564EF8: swc1        $f6, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
            goto L_80564F78;
    }
    // 0x80564EF8: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80564EFC: lwc1        $f12, 0x5DF4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2594));
    // 0x80564F00: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80564F04: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80564F08: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80564F0C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80564F10: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80564F14: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80564F18: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80564F1C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80564F20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80564F24: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80564F28: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80564F2C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80564F30: nop

    // 0x80564F34: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80564F38: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80564F3C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80564F40: nop

    // 0x80564F44: bc1f        L_80564F78
    if (!c1cs) {
        // 0x80564F48: nop
    
            goto L_80564F78;
    }
    // 0x80564F48: nop

    // 0x80564F4C: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x80564F50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80564F54: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x80564F58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80564F5C: jalr        $t9
    // 0x80564F60: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80564F60: nop

    after_0:
    // 0x80564F64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80564F68: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80564F6C: nop

    // 0x80564F70: swc1        $f14, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f14.u32l;
    // 0x80564F74: swc1        $f14, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f14.u32l;
L_80564F78:
    // 0x80564F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80564F7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80564F80: jr          $ra
    // 0x80564F84: nop

    return;
    // 0x80564F84: nop

;}
RECOMP_FUNC void func_80533878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8053387C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80533880: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80533884: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80533888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8053388C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80533890: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80533894: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80533898: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8053389C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x805338A0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805338A4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x805338A8: lui         $t2, 0x8053
    ctx->r10 = S32(RELOC_HI16(345, 0X18D0) << 16);
    // 0x805338AC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805338B0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x805338B4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x805338B8: lw          $t2, 0x43A0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(345, 0X18D0));
    // 0x805338BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805338C0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x805338C4: jal         0x80532C24
    // 0x805338C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80532C24(rdram, ctx);
        goto after_0;
    // 0x805338C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805338CC: jal         0x80532C84
    // 0x805338D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80532C84(rdram, ctx);
        goto after_1;
    // 0x805338D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805338D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805338D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805338DC: jr          $ra
    // 0x805338E0: nop

    return;
    // 0x805338E0: nop

;}
RECOMP_FUNC void func_8079364C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079364C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80793650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80793654: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80793658: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(817, 0X79E4) << 16);
    // 0x8079365C: addiu       $t6, $t6, 0x7D34
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(817, 0X79E4));
    // 0x80793660: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80793664: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80793668: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8079366C: sw          $zero, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = 0;
    // 0x80793670: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80793674: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x80793678: jal         0x8079393C
    // 0x8079367C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8079393C(rdram, ctx);
        goto after_0;
    // 0x8079367C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80793680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80793684: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80793688: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8079368C: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x80793690: jr          $ra
    // 0x80793694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80793694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806F1F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1F14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F1F18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806F1F1C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806F1F20: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806F1F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F1F28: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806F1F2C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806F1F30: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x806F1F34: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806F1F38: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806F1F3C: lui         $t2, 0x806F
    ctx->r10 = S32(RELOC_HI16(679, 0X1A34) << 16);
    // 0x806F1F40: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806F1F44: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806F1F48: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806F1F4C: lw          $t2, 0x2FB4($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(679, 0X1A34));
    // 0x806F1F50: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806F1F54: jal         0x806F1D24
    // 0x806F1F58: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_806F1D24(rdram, ctx);
        goto after_0;
    // 0x806F1F58: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x806F1F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F1F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F1F64: jr          $ra
    // 0x806F1F68: nop

    return;
    // 0x806F1F68: nop

;}
RECOMP_FUNC void func_80010A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010A30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80010A34: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80010A38: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80010A3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80010A40: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80010A44: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x80010A48: addiu       $a0, $zero, 0xD7
    ctx->r4 = ADD32(0, 0XD7);
L_80010A4C:
    // 0x80010A4C: jal         0x80011D1C
    // 0x80010A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_0;
    // 0x80010A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80010A54: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80010A58: bnel        $s0, $s1, L_80010A4C
    if (ctx->r16 != ctx->r17) {
        // 0x80010A5C: addiu       $a0, $zero, 0xD7
        ctx->r4 = ADD32(0, 0XD7);
            goto L_80010A4C;
    }
    goto skip_0;
    // 0x80010A5C: addiu       $a0, $zero, 0xD7
    ctx->r4 = ADD32(0, 0XD7);
    skip_0:
    // 0x80010A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80010A64: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80010A68: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80010A6C: jr          $ra
    // 0x80010A70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80010A70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8064B978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B97C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B980: jal         0x8004700C
    // 0x8064B984: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8064B984: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064B988: beq         $v0, $zero, L_8064B9E8
    if (ctx->r2 == 0) {
        // 0x8064B98C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8064B9E8;
    }
    // 0x8064B98C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064B990: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064B994: blez        $v1, L_8064B9A4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8064B998: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8064B9A4;
    }
    // 0x8064B998: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8064B99C: b           L_8064B9E8
    // 0x8064B9A0: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064B9E8;
    // 0x8064B9A0: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064B9A4:
    // 0x8064B9A4: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8064B9A8: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064B9AC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8064B9B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8064B9B4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8064B9B8: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x8064B9BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064B9C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8064B9C4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8064B9C8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8064B9CC: nop

    // 0x8064B9D0: bc1fl       L_8064B9EC
    if (!c1cs) {
        // 0x8064B9D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064B9EC;
    }
    goto skip_0;
    // 0x8064B9D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064B9D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8064B9DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8064B9E0: jal         0x8064BF74
    // 0x8064B9E4: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    func_8064BF74(rdram, ctx);
        goto after_1;
    // 0x8064B9E4: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    after_1:
L_8064B9E8:
    // 0x8064B9E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064B9EC:
    // 0x8064B9EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B9F0: jr          $ra
    // 0x8064B9F4: nop

    return;
    // 0x8064B9F4: nop

;}
RECOMP_FUNC void func_806F1FC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1FC8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806F1FCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F1FD0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x806F1FD4: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806F1FD8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806F1FDC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806F1FE0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x806F1FE4: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806F1FE8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(679, 0X1BE0) << 16);
    // 0x806F1FEC: lwc1        $f10, 0x3160($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(679, 0X1BE0));
    // 0x806F1FF0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x806F1FF4: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x806F1FF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F1FFC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806F2000: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806F2004: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x806F2008: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x806F200C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x806F2010: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x806F2014: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x806F2018: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x806F201C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x806F2020: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x806F2024: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x806F2028: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x806F202C: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x806F2030: jalr        $t9
    // 0x806F2034: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806F2034: nop

    after_0:
    // 0x806F2038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F203C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x806F2040: jr          $ra
    // 0x806F2044: nop

    return;
    // 0x806F2044: nop

;}
RECOMP_FUNC void func_806E0294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E0294: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806E0298: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(643, 0XD98) << 16);
    // 0x806E029C: addiu       $t6, $t6, 0x1C8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(643, 0XD98));
    // 0x806E02A0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806E02A4: jr          $ra
    // 0x806E02A8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806E02A8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80553D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80553D2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80553D30: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80553D34: lw          $v0, -0x77F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X77F0);
    // 0x80553D38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80553D3C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80553D40: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80553D44: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80553D48: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80553D4C: lh          $s0, 0x6($v0)
    ctx->r16 = MEM_H(ctx->r2, 0X6);
    // 0x80553D50: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80553D54: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80553D58: beq         $s0, $zero, L_80553D90
    if (ctx->r16 == 0) {
        // 0x80553D5C: lw          $s1, 0x10($v0)
        ctx->r17 = MEM_W(ctx->r2, 0X10);
            goto L_80553D90;
    }
    // 0x80553D5C: lw          $s1, 0x10($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X10);
L_80553D60:
    // 0x80553D60: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80553D64: beq         $a1, $zero, L_80553D88
    if (ctx->r5 == 0) {
        // 0x80553D68: nop
    
            goto L_80553D88;
    }
    // 0x80553D68: nop

    // 0x80553D6C: beql        $s3, $a1, L_80553D80
    if (ctx->r19 == ctx->r5) {
        // 0x80553D70: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80553D80;
    }
    goto skip_0;
    // 0x80553D70: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_0:
    // 0x80553D74: jal         0x80553B08
    // 0x80553D78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80553B08(rdram, ctx);
        goto after_0;
    // 0x80553D78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80553D7C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80553D80:
    // 0x80553D80: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80553D84: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_80553D88:
    // 0x80553D88: bne         $s0, $zero, L_80553D60
    if (ctx->r16 != 0) {
        // 0x80553D8C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80553D60;
    }
    // 0x80553D8C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80553D90:
    // 0x80553D90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80553D94: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80553D98: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80553D9C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80553DA0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80553DA4: jr          $ra
    // 0x80553DA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80553DA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805DA8D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA8D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DA8D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DA8DC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805DA8E0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x805DA8E4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805DA8E8: lui         $t8, 0x805E
    ctx->r24 = S32(RELOC_HI16(477, 0XB54) << 16);
    // 0x805DA8EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805DA8F0: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x805DA8F4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805DA8F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805DA8FC: lw          $t8, -0x546C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(477, 0XB54));
    // 0x805DA900: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805DA904: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805DA908: jal         0x80048490
    // 0x805DA90C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x805DA90C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x805DA910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DA914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DA918: jr          $ra
    // 0x805DA91C: nop

    return;
    // 0x805DA91C: nop

;}
RECOMP_FUNC void func_8052C9FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052C9FC: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8052CA00: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8052CA04: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x8052CA08: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x8052CA0C: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x8052CA10: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x8052CA14: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8052CA18: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8052CA1C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8052CA20: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8052CA24: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8052CA28: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8052CA2C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8052CA30: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8052CA34: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8052CA38: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8052CA3C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052CA40: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8052CA44: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x8052CA48: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8052CA4C: lwc1        $f24, 0x3C($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8052CA50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8052CA54: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8052CA58: addiu       $s1, $v0, 0xC8
    ctx->r17 = ADD32(ctx->r2, 0XC8);
    // 0x8052CA5C: addiu       $s0, $v0, 0xD8
    ctx->r16 = ADD32(ctx->r2, 0XD8);
    // 0x8052CA60: jal         0x8004921C
    // 0x8052CA64: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8052CA64: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8052CA68: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8052CA6C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8052CA70: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8052CA74: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8052CA78: lwc1        $f0, 0x6C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8052CA7C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8052CA80: sll         $s5, $v1, 6
    ctx->r21 = S32(ctx->r3 << 6);
    // 0x8052CA84: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8052CA88: addiu       $s7, $zero, 0x19
    ctx->r23 = ADD32(0, 0X19);
    // 0x8052CA8C: addiu       $s6, $zero, 0xFF
    ctx->r22 = ADD32(0, 0XFF);
L_8052CA90:
    // 0x8052CA90: lwc1        $f22, 0x4($s2)
    ctx->f22.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8052CA94: lwc1        $f20, 0x0($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8052CA98: sub.s       $f14, $f0, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8052CA9C: sub.s       $f12, $f24, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f24.fl - ctx->f20.fl;
    // 0x8052CAA0: jal         0x80067114
    // 0x8052CAA4: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    func_80067114(rdram, ctx);
        goto after_1;
    // 0x8052CAA4: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_1:
    // 0x8052CAA8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x8052CAAC: jal         0x80066E88
    // 0x8052CAB0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8052CAB0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x8052CAB4: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8052CAB8: jal         0x80066DE4
    // 0x8052CABC: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8052CABC: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    after_3:
    // 0x8052CAC0: mul.s       $f14, $f30, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f30.fl, ctx->f24.fl);
    // 0x8052CAC4: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8052CAC8: sll         $v0, $s3, 6
    ctx->r2 = S32(ctx->r19 << 6);
    // 0x8052CACC: mul.s       $f2, $f26, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x8052CAD0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8052CAD4: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x8052CAD8: mul.s       $f16, $f30, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x8052CADC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8052CAE0: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x8052CAE4: mul.s       $f12, $f26, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x8052CAE8: mov.s       $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    ctx->f24.fl = ctx->f20.fl;
    // 0x8052CAEC: add.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8052CAF0: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x8052CAF4: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8052CAF8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8052CAFC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8052CB00: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x8052CB04: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8052CB08: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x8052CB0C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8052CB10: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8052CB14: nop

    // 0x8052CB18: sh          $t7, -0x20($s1)
    MEM_H(-0X20, ctx->r17) = ctx->r15;
    // 0x8052CB1C: lwc1        $f4, -0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, -0X4);
    // 0x8052CB20: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8052CB24: sub.s       $f18, $f14, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8052CB28: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8052CB2C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8052CB30: add.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8052CB34: sh          $t9, -0x1E($s1)
    MEM_H(-0X1E, ctx->r17) = ctx->r25;
    // 0x8052CB38: lwc1        $f10, -0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, -0X8);
    // 0x8052CB3C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8052CB40: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8052CB44: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8052CB48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8052CB4C: sh          $t1, -0x20($s0)
    MEM_H(-0X20, ctx->r16) = ctx->r9;
    // 0x8052CB50: lwc1        $f10, -0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, -0X4);
    // 0x8052CB54: sh          $v0, -0x18($s0)
    MEM_H(-0X18, ctx->r16) = ctx->r2;
    // 0x8052CB58: add.s       $f26, $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f6.fl;
    // 0x8052CB5C: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8052CB60: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8052CB64: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8052CB68: nop

    // 0x8052CB6C: sh          $t3, -0x1E($s0)
    MEM_H(-0X1E, ctx->r16) = ctx->r11;
    // 0x8052CB70: sh          $v0, -0x18($s1)
    MEM_H(-0X18, ctx->r17) = ctx->r2;
    // 0x8052CB74: sh          $zero, -0x16($s1)
    MEM_H(-0X16, ctx->r17) = 0;
    // 0x8052CB78: sh          $zero, -0x1C($s0)
    MEM_H(-0X1C, ctx->r16) = 0;
    // 0x8052CB7C: lh          $t4, -0x1C($s0)
    ctx->r12 = MEM_H(ctx->r16, -0X1C);
    // 0x8052CB80: sh          $s5, -0x16($s0)
    MEM_H(-0X16, ctx->r16) = ctx->r21;
    // 0x8052CB84: sh          $t4, -0x1C($s1)
    MEM_H(-0X1C, ctx->r17) = ctx->r12;
    // 0x8052CB88: sh          $zero, -0x1A($s0)
    MEM_H(-0X1A, ctx->r16) = 0;
    // 0x8052CB8C: sh          $zero, -0x1A($s1)
    MEM_H(-0X1A, ctx->r17) = 0;
    // 0x8052CB90: sb          $s6, -0x14($s0)
    MEM_B(-0X14, ctx->r16) = ctx->r22;
    // 0x8052CB94: sb          $s6, -0x13($s0)
    MEM_B(-0X13, ctx->r16) = ctx->r22;
    // 0x8052CB98: sb          $s6, -0x12($s0)
    MEM_B(-0X12, ctx->r16) = ctx->r22;
    // 0x8052CB9C: sb          $s6, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r22;
    // 0x8052CBA0: sb          $s6, -0x14($s1)
    MEM_B(-0X14, ctx->r17) = ctx->r22;
    // 0x8052CBA4: sb          $s6, -0x13($s1)
    MEM_B(-0X13, ctx->r17) = ctx->r22;
    // 0x8052CBA8: sb          $s6, -0x12($s1)
    MEM_B(-0X12, ctx->r17) = ctx->r22;
    // 0x8052CBAC: bne         $s4, $s7, L_8052CA90
    if (ctx->r20 != ctx->r23) {
        // 0x8052CBB0: sb          $s6, -0x11($s1)
        MEM_B(-0X11, ctx->r17) = ctx->r22;
            goto L_8052CA90;
    }
    // 0x8052CBB0: sb          $s6, -0x11($s1)
    MEM_B(-0X11, ctx->r17) = ctx->r22;
    // 0x8052CBB4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8052CBB8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8052CBBC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8052CBC0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8052CBC4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8052CBC8: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8052CBCC: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8052CBD0: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8052CBD4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8052CBD8: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8052CBDC: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8052CBE0: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x8052CBE4: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x8052CBE8: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x8052CBEC: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x8052CBF0: jr          $ra
    // 0x8052CBF4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8052CBF4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_8069D1E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D1E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069D1EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D1F0: jal         0x8069D170
    // 0x8069D1F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8069D170(rdram, ctx);
        goto after_0;
    // 0x8069D1F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069D1F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069D1FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8069D200: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8069D204: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069D208: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(571, 0X6C8) << 16);
    // 0x8069D20C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8069D210: addiu       $t6, $t6, -0x2C48
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(571, 0X6C8));
    // 0x8069D214: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(571, 0X770) << 16);
    // 0x8069D218: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8069D21C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8069D220: lwc1        $f6, -0x2BA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(571, 0X770));
    // 0x8069D224: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(571, 0X36C) << 16);
    // 0x8069D228: addiu       $t7, $t7, -0x2FA4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(571, 0X36C));
    // 0x8069D22C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8069D230: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8069D234: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8069D238: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8069D23C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8069D240: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8069D244: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x8069D248: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x8069D24C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069D250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069D254: jr          $ra
    // 0x8069D258: nop

    return;
    // 0x8069D258: nop

;}
RECOMP_FUNC void func_8002AF3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AF3C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8002AF40: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8002AF44: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002AF48: sb          $v1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r3;
    // 0x8002AF4C: jr          $ra
    // 0x8002AF50: sb          $v1, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r3;
    return;
    // 0x8002AF50: sb          $v1, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_8040F690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040F690: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040F694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040F698: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8040F69C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8040F6A0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8040F6A4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8040F6A8: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x8040F6AC: jal         0x8041011C
    // 0x8040F6B0: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    func_8041011C(rdram, ctx);
        goto after_0;
    // 0x8040F6B0: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_0:
    // 0x8040F6B4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8040F6B8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8040F6BC: jal         0x8041069C
    // 0x8040F6C0: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    func_8041069C(rdram, ctx);
        goto after_1;
    // 0x8040F6C0: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x8040F6C4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8040F6C8: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x8040F6CC: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8040F6D0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8040F6D4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8040F6D8: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8040F6DC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8040F6E0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8040F6E4: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
    // 0x8040F6E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040F6EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8040F6F0: jr          $ra
    // 0x8040F6F4: nop

    return;
    // 0x8040F6F4: nop

;}
RECOMP_FUNC void func_806AA2BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA2BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806AA2C0: jr          $ra
    // 0x806AA2C4: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    return;
    // 0x806AA2C4: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8076060C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076060C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80760610: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80760614: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80760618: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8076061C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80760620: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80760624: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80760628: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8076062C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80760630: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80760634: jr          $ra
    // 0x80760638: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80760638: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_800683A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800683A4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800683A8: addiu       $a1, $a1, 0x6EB0
    ctx->r5 = ADD32(ctx->r5, 0X6EB0);
    // 0x800683AC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800683B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800683B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800683B8: bne         $t6, $zero, L_80068408
    if (ctx->r14 != 0) {
        // 0x800683BC: lui         $a0, 0x2
        ctx->r4 = S32(0X2 << 16);
            goto L_80068408;
    }
    // 0x800683BC: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x800683C0: jal         0x80064D1C
    // 0x800683C4: ori         $a0, $a0, 0x5840
    ctx->r4 = ctx->r4 | 0X5840;
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x800683C4: ori         $a0, $a0, 0x5840
    ctx->r4 = ctx->r4 | 0X5840;
    after_0:
    // 0x800683C8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800683CC: addiu       $a1, $a1, 0x6EB0
    ctx->r5 = ADD32(ctx->r5, 0X6EB0);
    // 0x800683D0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800683D4: bne         $v0, $zero, L_800683F4
    if (ctx->r2 != 0) {
        // 0x800683D8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800683F4;
    }
    // 0x800683D8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800683DC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800683E0: addiu       $a0, $a0, 0xE0C
    ctx->r4 = ADD32(ctx->r4, 0XE0C);
    // 0x800683E4: jal         0x80071380
    // 0x800683E8: addiu       $a1, $zero, 0x178
    ctx->r5 = ADD32(0, 0X178);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x800683E8: addiu       $a1, $zero, 0x178
    ctx->r5 = ADD32(0, 0X178);
    after_1:
    // 0x800683EC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800683F0: lw          $v1, 0x6EB0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6EB0);
L_800683F4:
    // 0x800683F4: addiu       $t7, $v1, 0x3F
    ctx->r15 = ADD32(ctx->r3, 0X3F);
    // 0x800683F8: srl         $t8, $t7, 6
    ctx->r24 = S32(U32(ctx->r15) >> 6);
    // 0x800683FC: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x80068400: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80068404: sw          $t9, 0x7FF8($at)
    MEM_W(0X7FF8, ctx->r1) = ctx->r25;
L_80068408:
    // 0x80068408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006840C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068410: jr          $ra
    // 0x80068414: nop

    return;
    // 0x80068414: nop

;}
RECOMP_FUNC void func_80005D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D78: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80005D7C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80005D80: lui         $s5, 0x800B
    ctx->r21 = S32(0X800B << 16);
    // 0x80005D84: addiu       $s5, $s5, 0x4D10
    ctx->r21 = ADD32(ctx->r21, 0X4D10);
    // 0x80005D88: lw          $t6, 0x1D68($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X1D68);
    // 0x80005D8C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80005D90: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80005D94: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80005D98: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80005D9C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80005DA0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80005DA4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80005DA8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80005DAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005DB0: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80005DB4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80005DB8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80005DBC: blez        $t7, L_80005F50
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80005DC0: sw          $t7, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r15;
            goto L_80005F50;
    }
    // 0x80005DC0: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x80005DC4: addiu       $fp, $zero, 0x7F
    ctx->r30 = ADD32(0, 0X7F);
    // 0x80005DC8: lw          $t9, 0x1D78($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X1D78);
L_80005DCC:
    // 0x80005DCC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80005DD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80005DD4: addu        $v0, $t9, $s6
    ctx->r2 = ADD32(ctx->r25, ctx->r22);
    // 0x80005DD8: lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2);
    // 0x80005DDC: lbu         $a3, 0x3($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X3);
    // 0x80005DE0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80005DE4: bne         $v1, $at, L_80005DF8
    if (ctx->r3 != ctx->r1) {
        // 0x80005DE8: or          $a2, $s7, $zero
        ctx->r6 = ctx->r23 | 0;
            goto L_80005DF8;
    }
    // 0x80005DE8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80005DEC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80005DF0: beql        $a3, $at, L_80005F40
    if (ctx->r7 == ctx->r1) {
        // 0x80005DF4: lw          $t7, 0x5C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5C);
            goto L_80005F40;
    }
    goto skip_0;
    // 0x80005DF4: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    skip_0:
L_80005DF8:
    // 0x80005DF8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80005DFC: jal         0x80004160
    // 0x80005E00: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    func_80004160(rdram, ctx);
        goto after_0;
    // 0x80005E00: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_0:
    // 0x80005E04: beql        $v0, $zero, L_80005F40
    if (ctx->r2 == 0) {
        // 0x80005E08: lw          $t7, 0x5C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5C);
            goto L_80005F40;
    }
    goto skip_1;
    // 0x80005E08: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    skip_1:
    // 0x80005E0C: jal         0x800066A8
    // 0x80005E10: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800066A8(rdram, ctx);
        goto after_1;
    // 0x80005E10: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x80005E14: beql        $v0, $zero, L_80005F40
    if (ctx->r2 == 0) {
        // 0x80005E18: lw          $t7, 0x5C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5C);
            goto L_80005F40;
    }
    goto skip_2;
    // 0x80005E18: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    skip_2:
    // 0x80005E1C: lw          $t0, 0x2688($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X2688);
    // 0x80005E20: lui         $s4, 0x800B
    ctx->r20 = S32(0X800B << 16);
    // 0x80005E24: addiu       $s4, $s4, 0x4D10
    ctx->r20 = ADD32(ctx->r20, 0X4D10);
    // 0x80005E28: blez        $t0, L_80005F3C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80005E2C: sw          $zero, 0x60($sp)
        MEM_W(0X60, ctx->r29) = 0;
            goto L_80005F3C;
    }
    // 0x80005E2C: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
L_80005E30:
    // 0x80005E30: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80005E34: lb          $t2, 0x240A($s4)
    ctx->r10 = MEM_B(ctx->r20, 0X240A);
    // 0x80005E38: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80005E3C: beql        $t1, $t2, L_80005E5C
    if (ctx->r9 == ctx->r10) {
        // 0x80005E40: lw          $t4, 0x1D78($s5)
        ctx->r12 = MEM_W(ctx->r21, 0X1D78);
            goto L_80005E5C;
    }
    goto skip_3;
    // 0x80005E40: lw          $t4, 0x1D78($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X1D78);
    skip_3:
    // 0x80005E44: lb          $v0, 0x240A($s4)
    ctx->r2 = MEM_B(ctx->r20, 0X240A);
    // 0x80005E48: beql        $t3, $v0, L_80005E5C
    if (ctx->r11 == ctx->r2) {
        // 0x80005E4C: lw          $t4, 0x1D78($s5)
        ctx->r12 = MEM_W(ctx->r21, 0X1D78);
            goto L_80005E5C;
    }
    goto skip_4;
    // 0x80005E4C: lw          $t4, 0x1D78($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X1D78);
    skip_4:
    // 0x80005E50: bnel        $v0, $zero, L_80005F40
    if (ctx->r2 != 0) {
        // 0x80005E54: lw          $t7, 0x5C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5C);
            goto L_80005F40;
    }
    goto skip_5;
    // 0x80005E54: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    skip_5:
    // 0x80005E58: lw          $t4, 0x1D78($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X1D78);
L_80005E5C:
    // 0x80005E5C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80005E60: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80005E64: addu        $v0, $t4, $s6
    ctx->r2 = ADD32(ctx->r12, ctx->r22);
    // 0x80005E68: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80005E6C: blez        $t5, L_80005EE0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80005E70: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80005EE0;
    }
    // 0x80005E70: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80005E74:
    // 0x80005E74: jal         0x8000B808
    // 0x80005E78: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8000B808(rdram, ctx);
        goto after_2;
    // 0x80005E78: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80005E7C: beq         $v0, $zero, L_80005EC4
    if (ctx->r2 == 0) {
        // 0x80005E80: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80005EC4;
    }
    // 0x80005E80: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80005E84: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80005E88: addiu       $s1, $s4, 0x2408
    ctx->r17 = ADD32(ctx->r20, 0X2408);
    // 0x80005E8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80005E90: beql        $t6, $zero, L_80005EA4
    if (ctx->r14 == 0) {
        // 0x80005E94: lbu         $t7, 0x2($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X2);
            goto L_80005EA4;
    }
    goto skip_6;
    // 0x80005E94: lbu         $t7, 0x2($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2);
    skip_6:
    // 0x80005E98: jal         0x80005CAC
    // 0x80005E9C: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    func_80005CAC(rdram, ctx);
        goto after_3;
    // 0x80005E9C: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    after_3:
    // 0x80005EA0: lbu         $t7, 0x2($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2);
L_80005EA4:
    // 0x80005EA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80005EA8: beql        $fp, $t7, L_80005EBC
    if (ctx->r30 == ctx->r15) {
        // 0x80005EAC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80005EBC;
    }
    goto skip_7;
    // 0x80005EAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_7:
    // 0x80005EB0: jal         0x80005CAC
    // 0x80005EB4: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    func_80005CAC(rdram, ctx);
        goto after_4;
    // 0x80005EB4: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    after_4:
    // 0x80005EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80005EBC:
    // 0x80005EBC: jal         0x80005CAC
    // 0x80005EC0: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    func_80005CAC(rdram, ctx);
        goto after_5;
    // 0x80005EC0: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    after_5:
L_80005EC4:
    // 0x80005EC4: lw          $t8, 0x1D78($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X1D78);
    // 0x80005EC8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80005ECC: addu        $v0, $t8, $s6
    ctx->r2 = ADD32(ctx->r24, ctx->r22);
    // 0x80005ED0: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80005ED4: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80005ED8: bnel        $at, $zero, L_80005E74
    if (ctx->r1 != 0) {
        // 0x80005EDC: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80005E74;
    }
    goto skip_8;
    // 0x80005EDC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_8:
L_80005EE0:
    // 0x80005EE0: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x80005EE4: blez        $t0, L_80005F20
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80005EE8: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80005F20;
    }
    // 0x80005EE8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80005EEC:
    // 0x80005EEC: jal         0x8000B8DC
    // 0x80005EF0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_8000B8DC(rdram, ctx);
        goto after_6;
    // 0x80005EF0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
    // 0x80005EF4: beq         $v0, $zero, L_80005F04
    if (ctx->r2 == 0) {
        // 0x80005EF8: addiu       $a0, $s4, 0x2408
        ctx->r4 = ADD32(ctx->r20, 0X2408);
            goto L_80005F04;
    }
    // 0x80005EF8: addiu       $a0, $s4, 0x2408
    ctx->r4 = ADD32(ctx->r20, 0X2408);
    // 0x80005EFC: jal         0x80005CAC
    // 0x80005F00: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    func_80005CAC(rdram, ctx);
        goto after_7;
    // 0x80005F00: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    after_7:
L_80005F04:
    // 0x80005F04: lw          $t1, 0x1D78($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X1D78);
    // 0x80005F08: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80005F0C: addu        $t2, $t1, $s6
    ctx->r10 = ADD32(ctx->r9, ctx->r22);
    // 0x80005F10: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x80005F14: slt         $at, $s3, $t3
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80005F18: bnel        $at, $zero, L_80005EEC
    if (ctx->r1 != 0) {
        // 0x80005F1C: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80005EEC;
    }
    goto skip_9;
    // 0x80005F1C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_9:
L_80005F20:
    // 0x80005F20: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80005F24: lw          $t6, 0x2688($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X2688);
    // 0x80005F28: addiu       $s4, $s4, 0x14
    ctx->r20 = ADD32(ctx->r20, 0X14);
    // 0x80005F2C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80005F30: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80005F34: bne         $at, $zero, L_80005E30
    if (ctx->r1 != 0) {
        // 0x80005F38: sw          $t5, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r13;
            goto L_80005E30;
    }
    // 0x80005F38: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
L_80005F3C:
    // 0x80005F3C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
L_80005F40:
    // 0x80005F40: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80005F44: addiu       $s6, $s6, 0xC
    ctx->r22 = ADD32(ctx->r22, 0XC);
    // 0x80005F48: bnel        $s7, $t7, L_80005DCC
    if (ctx->r23 != ctx->r15) {
        // 0x80005F4C: lw          $t9, 0x1D78($s5)
        ctx->r25 = MEM_W(ctx->r21, 0X1D78);
            goto L_80005DCC;
    }
    goto skip_10;
    // 0x80005F4C: lw          $t9, 0x1D78($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X1D78);
    skip_10:
L_80005F50:
    // 0x80005F50: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80005F54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80005F58: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80005F5C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80005F60: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80005F64: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80005F68: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80005F6C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80005F70: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80005F74: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80005F78: jr          $ra
    // 0x80005F7C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80005F7C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80680930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80680934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80680938: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8068093C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80680940: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80680944: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(550, 0X2188) << 16);
    // 0x80680948: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8068094C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80680950: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80680954: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80680958: lw          $t8, 0x2598($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(550, 0X2188));
    // 0x8068095C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80680960: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80680964: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80680968: jal         0x80048490
    // 0x8068096C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8068096C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80680970: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80680974: jal         0x80048378
    // 0x80680978: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80680978: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8068097C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80680980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80680984: jr          $ra
    // 0x80680988: nop

    return;
    // 0x80680988: nop

;}
RECOMP_FUNC void func_8044A76C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A76C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8044A770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A774: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044A778: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A77C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044A780: lw          $a1, 0x6A50($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X6A50);
    // 0x8044A784: beq         $a1, $zero, L_8044A79C
    if (ctx->r5 == 0) {
        // 0x8044A788: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044A79C;
    }
    // 0x8044A788: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044A78C: jal         0x80050A2C
    // 0x8044A790: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80050A2C(rdram, ctx);
        goto after_0;
    // 0x8044A790: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044A794: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A798: sw          $zero, 0x6A50($v1)
    MEM_W(0X6A50, ctx->r3) = 0;
L_8044A79C:
    // 0x8044A79C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044A7A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8044A7A4: jr          $ra
    // 0x8044A7A8: nop

    return;
    // 0x8044A7A8: nop

;}
RECOMP_FUNC void func_804CF450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF450: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CF454: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804CF458: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804CF45C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804CF460: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804CF464: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804CF468: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x804CF46C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804CF470: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804CF474: nop

    // 0x804CF478: bc1fl       L_804CF4A8
    if (!c1cs) {
        // 0x804CF47C: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_804CF4A8;
    }
    goto skip_0;
    // 0x804CF47C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x804CF480: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804CF484: nop

    // 0x804CF488: add.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f12.fl;
L_804CF48C:
    // 0x804CF48C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x804CF490: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804CF494: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804CF498: nop

    // 0x804CF49C: bc1tl       L_804CF48C
    if (c1cs) {
        // 0x804CF4A0: add.s       $f10, $f0, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f12.fl;
            goto L_804CF48C;
    }
    goto skip_1;
    // 0x804CF4A0: add.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f12.fl;
    skip_1:
    // 0x804CF4A4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_804CF4A8:
    // 0x804CF4A8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804CF4AC: nop

    // 0x804CF4B0: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804CF4B4: nop

    // 0x804CF4B8: bc1f        L_804CF4DC
    if (!c1cs) {
        // 0x804CF4BC: nop
    
            goto L_804CF4DC;
    }
    // 0x804CF4BC: nop

    // 0x804CF4C0: sub.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
L_804CF4C4:
    // 0x804CF4C4: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x804CF4C8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804CF4CC: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804CF4D0: nop

    // 0x804CF4D4: bc1tl       L_804CF4C4
    if (c1cs) {
        // 0x804CF4D8: sub.s       $f16, $f0, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_804CF4C4;
    }
    goto skip_2;
    // 0x804CF4D8: sub.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
    skip_2:
L_804CF4DC:
    // 0x804CF4DC: jr          $ra
    // 0x804CF4E0: nop

    return;
    // 0x804CF4E0: nop

;}
RECOMP_FUNC void func_806A97E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A97E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806A97EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A97F0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806A97F4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806A97F8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806A97FC: lui         $t8, 0x806B
    ctx->r24 = S32(RELOC_HI16(589, 0X10E0) << 16);
    // 0x806A9800: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806A9804: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806A9808: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806A980C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806A9810: lw          $t8, -0x5760($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(589, 0X10E0));
    // 0x806A9814: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806A9818: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806A981C: jal         0x80048490
    // 0x806A9820: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806A9820: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806A9824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806A9828: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806A982C: jr          $ra
    // 0x806A9830: nop

    return;
    // 0x806A9830: nop

;}
RECOMP_FUNC void func_80046AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046AC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80046AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046AC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80046ACC: jal         0x80046978
    // 0x80046AD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80046978(rdram, ctx);
        goto after_0;
    // 0x80046AD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80046AD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80046AD8: sb          $zero, 0x170($a0)
    MEM_B(0X170, ctx->r4) = 0;
    // 0x80046ADC: sw          $zero, 0x174($a0)
    MEM_W(0X174, ctx->r4) = 0;
    // 0x80046AE0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80046AE4: jal         0x80046A38
    // 0x80046AE8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    func_80046A38(rdram, ctx);
        goto after_1;
    // 0x80046AE8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    after_1:
    // 0x80046AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046AF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046AF4: jr          $ra
    // 0x80046AF8: nop

    return;
    // 0x80046AF8: nop

;}
RECOMP_FUNC void func_806EEFC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EEFC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EEFC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EEFCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EEFD0: jal         0x806EC16C
    // 0x806EEFD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806EC16C(rdram, ctx);
        goto after_0;
    // 0x806EEFD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EEFD8: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EEFDC: jal         0x800577D8
    // 0x806EEFE0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_1;
    // 0x806EEFE0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x806EEFE4: jal         0x806EE5E4
    // 0x806EEFE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE5E4(rdram, ctx);
        goto after_2;
    // 0x806EEFE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EEFEC: jal         0x806EE664
    // 0x806EEFF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE664(rdram, ctx);
        goto after_3;
    // 0x806EEFF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EEFF4: jal         0x806EE720
    // 0x806EEFF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE720(rdram, ctx);
        goto after_4;
    // 0x806EEFF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EEFFC: jal         0x806EED30
    // 0x806EF000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EED30(rdram, ctx);
        goto after_5;
    // 0x806EF000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EF004: beq         $v0, $zero, L_806EF01C
    if (ctx->r2 == 0) {
        // 0x806EF008: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EF01C;
    }
    // 0x806EF008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EF00C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EF010: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806EF014: jal         0x806EF4A0
    // 0x806EF018: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EF4A0(rdram, ctx);
        goto after_6;
    // 0x806EF018: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
L_806EF01C:
    // 0x806EF01C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806EF020: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EF024: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EF028: jr          $ra
    // 0x806EF02C: nop

    return;
    // 0x806EF02C: nop

;}
RECOMP_FUNC void func_8043FBDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043FBDC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8043FBE0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8043FBE4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8043FBE8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8043FBEC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8043FBF0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8043FBF4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8043FBF8: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8043FBFC: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8043FC00: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8043FC04: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8043FC08: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8043FC0C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8043FC10: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043FC14: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8043FC18: addiu       $s4, $zero, 0x168
    ctx->r20 = ADD32(0, 0X168);
    // 0x8043FC1C: lw          $s1, 0x1C90($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X1C90);
    // 0x8043FC20: lwc1        $f0, 0x1C2C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X1C2C);
    // 0x8043FC24: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8043FC28: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x8043FC2C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8043FC30: addu        $s0, $s2, $t6
    ctx->r16 = ADD32(ctx->r18, ctx->r14);
    // 0x8043FC34: slti        $at, $s1, 0x96
    ctx->r1 = SIGNED(ctx->r17) < 0X96 ? 1 : 0;
    // 0x8043FC38: beq         $at, $zero, L_8043FD84
    if (ctx->r1 == 0) {
        // 0x8043FC3C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8043FD84;
    }
    // 0x8043FC3C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8043FC40: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EB4) << 16);
    // 0x8043FC44: lwc1        $f30, 0x3DB4($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EB4));
    // 0x8043FC48: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
L_8043FC4C:
    // 0x8043FC4C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8043FC50: lwc1        $f6, 0x3C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X3C);
    // 0x8043FC54: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8043FC58: lwc1        $f24, 0x1C24($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0X1C24);
    // 0x8043FC5C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8043FC60: lwc1        $f26, 0x1C28($s2)
    ctx->f26.u32l = MEM_W(ctx->r18, 0X1C28);
    // 0x8043FC64: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8043FC68: lwc1        $f20, 0x8($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8043FC6C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8043FC70: lwc1        $f22, 0xC($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8043FC74: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8043FC78: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x8043FC7C: lwc1        $f4, 0x40($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X40);
    // 0x8043FC80: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8043FC84: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8043FC88: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8043FC8C: jal         0x800653D8
    // 0x8043FC90: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8043FC90: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    after_0:
    // 0x8043FC94: div         $zero, $v0, $s4
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r20)));
    // 0x8043FC98: mfhi        $t7
    ctx->r15 = hi;
    // 0x8043FC9C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8043FCA0: bne         $s4, $zero, L_8043FCAC
    if (ctx->r20 != 0) {
        // 0x8043FCA4: nop
    
            goto L_8043FCAC;
    }
    // 0x8043FCA4: nop

    // 0x8043FCA8: break       7
    do_break(2151939240);
L_8043FCAC:
    // 0x8043FCAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8043FCB0: bne         $s4, $at, L_8043FCC4
    if (ctx->r20 != ctx->r1) {
        // 0x8043FCB4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8043FCC4;
    }
    // 0x8043FCB4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8043FCB8: bne         $v0, $at, L_8043FCC4
    if (ctx->r2 != ctx->r1) {
        // 0x8043FCBC: nop
    
            goto L_8043FCC4;
    }
    // 0x8043FCBC: nop

    // 0x8043FCC0: break       6
    do_break(2151939264);
L_8043FCC4:
    // 0x8043FCC4: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8043FCC8: jal         0x80066E88
    // 0x8043FCCC: mov.s       $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8043FCCC: mov.s       $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
    after_1:
    // 0x8043FCD0: mul.s       $f4, $f0, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8043FCD4: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8043FCD8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x8043FCDC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8043FCE0: jal         0x80066DE4
    // 0x8043FCE4: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8043FCE4: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x8043FCE8: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8043FCEC: mul.s       $f10, $f0, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8043FCF0: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8043FCF4: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x8043FCF8: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x8043FCFC: slti        $at, $s1, 0x96
    ctx->r1 = SIGNED(ctx->r17) < 0X96 ? 1 : 0;
    // 0x8043FD00: neg.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = -ctx->f24.fl;
    // 0x8043FD04: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8043FD08: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8043FD0C: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    // 0x8043FD10: bc1fl       L_8043FD3C
    if (!c1cs) {
        // 0x8043FD14: swc1        $f2, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
            goto L_8043FD3C;
    }
    goto skip_0;
    // 0x8043FD14: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    skip_0:
    // 0x8043FD18: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x8043FD1C: nop

    // 0x8043FD20: bc1f        L_8043FD30
    if (!c1cs) {
        // 0x8043FD24: nop
    
            goto L_8043FD30;
    }
    // 0x8043FD24: nop

    // 0x8043FD28: b           L_8043FD3C
    // 0x8043FD2C: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
        goto L_8043FD3C;
    // 0x8043FD2C: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
L_8043FD30:
    // 0x8043FD30: b           L_8043FD3C
    // 0x8043FD34: swc1        $f24, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f24.u32l;
        goto L_8043FD3C;
    // 0x8043FD34: swc1        $f24, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f24.u32l;
    // 0x8043FD38: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
L_8043FD3C:
    // 0x8043FD3C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8043FD40: neg.s       $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = -ctx->f26.fl;
    // 0x8043FD44: add.s       $f22, $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f4.fl;
    // 0x8043FD48: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8043FD4C: nop

    // 0x8043FD50: bc1fl       L_8043FD7C
    if (!c1cs) {
        // 0x8043FD54: swc1        $f0, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
            goto L_8043FD7C;
    }
    goto skip_1;
    // 0x8043FD54: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    skip_1:
    // 0x8043FD58: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
    // 0x8043FD5C: nop

    // 0x8043FD60: bc1f        L_8043FD70
    if (!c1cs) {
        // 0x8043FD64: nop
    
            goto L_8043FD70;
    }
    // 0x8043FD64: nop

    // 0x8043FD68: b           L_8043FD7C
    // 0x8043FD6C: swc1        $f22, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f22.u32l;
        goto L_8043FD7C;
    // 0x8043FD6C: swc1        $f22, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f22.u32l;
L_8043FD70:
    // 0x8043FD70: b           L_8043FD7C
    // 0x8043FD74: swc1        $f26, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f26.u32l;
        goto L_8043FD7C;
    // 0x8043FD74: swc1        $f26, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f26.u32l;
    // 0x8043FD78: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
L_8043FD7C:
    // 0x8043FD7C: bne         $at, $zero, L_8043FC4C
    if (ctx->r1 != 0) {
        // 0x8043FD80: addiu       $s0, $s0, 0x150
        ctx->r16 = ADD32(ctx->r16, 0X150);
            goto L_8043FC4C;
    }
    // 0x8043FD80: addiu       $s0, $s0, 0x150
    ctx->r16 = ADD32(ctx->r16, 0X150);
L_8043FD84:
    // 0x8043FD84: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x8043FD88: addiu       $s1, $zero, 0x95
    ctx->r17 = ADD32(0, 0X95);
L_8043FD8C:
    // 0x8043FD8C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8043FD90: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8043FD94: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8043FD98: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8043FD9C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8043FDA0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8043FDA4: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x8043FDA8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8043FDAC: swc1        $f10, -0x30($s0)
    MEM_W(-0X30, ctx->r16) = ctx->f10.u32l;
    // 0x8043FDB0: bgez        $s1, L_8043FD8C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8043FDB4: swc1        $f4, -0x2C($s0)
        MEM_W(-0X2C, ctx->r16) = ctx->f4.u32l;
            goto L_8043FD8C;
    }
    // 0x8043FDB4: swc1        $f4, -0x2C($s0)
    MEM_W(-0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x8043FDB8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8043FDBC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8043FDC0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8043FDC4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8043FDC8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8043FDCC: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8043FDD0: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8043FDD4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8043FDD8: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8043FDDC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8043FDE0: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8043FDE4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8043FDE8: jr          $ra
    // 0x8043FDEC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8043FDEC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80536234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536234: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536238: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053623C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536240: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536244: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536248: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053624C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536250: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536254: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536258: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053625C: jr          $ra
    // 0x80536260: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536260: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8044996C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044996C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80449970: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80449974: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80449978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044997C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80449980: bne         $a2, $zero, L_804499B0
    if (ctx->r6 != 0) {
        // 0x80449984: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_804499B0;
    }
    // 0x80449984: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80449988: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x8044998C: lw          $v1, 0x114($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X114);
    // 0x80449990: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80449994: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80449998: bne         $at, $zero, L_804499F0
    if (ctx->r1 != 0) {
        // 0x8044999C: sw          $t7, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->r15;
            goto L_804499F0;
    }
    // 0x8044999C: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x804499A0: jal         0x80446A5C
    // 0x804499A4: nop

    func_80446A5C(rdram, ctx);
        goto after_0;
    // 0x804499A4: nop

    after_0:
    // 0x804499A8: b           L_804499F4
    // 0x804499AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804499F4;
    // 0x804499AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804499B0:
    // 0x804499B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804499B4: bnel        $a2, $at, L_804499E0
    if (ctx->r6 != ctx->r1) {
        // 0x804499B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_804499E0;
    }
    goto skip_0;
    // 0x804499B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x804499BC: jal         0x804469FC
    // 0x804499C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804469FC(rdram, ctx);
        goto after_1;
    // 0x804499C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x804499C4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804499C8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804499CC: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x804499D0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804499D4: b           L_804499F0
    // 0x804499D8: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_804499F0;
    // 0x804499D8: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    // 0x804499DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_804499E0:
    // 0x804499E0: bnel        $a2, $at, L_804499F4
    if (ctx->r6 != ctx->r1) {
        // 0x804499E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804499F4;
    }
    goto skip_1;
    // 0x804499E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804499E8: jal         0x80446A5C
    // 0x804499EC: nop

    func_80446A5C(rdram, ctx);
        goto after_2;
    // 0x804499EC: nop

    after_2:
L_804499F0:
    // 0x804499F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804499F4:
    // 0x804499F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804499F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804499FC: jr          $ra
    // 0x80449A00: nop

    return;
    // 0x80449A00: nop

;}
RECOMP_FUNC void func_80039924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003992C: jal         0x80039030
    // 0x80039930: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80039030(rdram, ctx);
        goto after_0;
    // 0x80039930: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80039934: jal         0x80038FEC
    // 0x80039938: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80038FEC(rdram, ctx);
        goto after_1;
    // 0x80039938: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8003993C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039940: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039944: jr          $ra
    // 0x80039948: nop

    return;
    // 0x80039948: nop

;}
RECOMP_FUNC void func_806AB3C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AB3C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AB3CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AB3D0: jal         0x806AB0A0
    // 0x806AB3D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806AB0A0(rdram, ctx);
        goto after_0;
    // 0x806AB3D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806AB3D8: beq         $v0, $zero, L_806AB400
    if (ctx->r2 == 0) {
        // 0x806AB3DC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806AB400;
    }
    // 0x806AB3DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806AB3E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AB3E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806AB3E8: jal         0x806AB72C
    // 0x806AB3EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806AB72C(rdram, ctx);
        goto after_1;
    // 0x806AB3EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x806AB3F0: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(592, 0X2FFC) << 16);
    // 0x806AB3F4: lwc1        $f4, -0x2424($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(592, 0X2FFC));
    // 0x806AB3F8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x806AB3FC: swc1        $f4, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->f4.u32l;
L_806AB400:
    // 0x806AB400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AB404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AB408: jr          $ra
    // 0x806AB40C: nop

    return;
    // 0x806AB40C: nop

;}
RECOMP_FUNC void func_80057A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057A28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80057A2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80057A30: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80057A34: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80057A38: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80057A3C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80057A40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80057A44: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x80057A48: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80057A4C: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80057A50: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80057A54: lw          $s0, 0x10($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X10);
    // 0x80057A58: blez        $t6, L_80057A9C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80057A5C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80057A9C;
    }
    // 0x80057A5C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80057A60: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80057A64:
    // 0x80057A64: beql        $a0, $zero, L_80057A88
    if (ctx->r4 == 0) {
        // 0x80057A68: lh          $t7, 0x8($s2)
        ctx->r15 = MEM_H(ctx->r18, 0X8);
            goto L_80057A88;
    }
    goto skip_0;
    // 0x80057A68: lh          $t7, 0x8($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X8);
    skip_0:
    // 0x80057A6C: jalr        $s4
    // 0x80057A70: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x80057A70: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x80057A74: beql        $v0, $zero, L_80057A88
    if (ctx->r2 == 0) {
        // 0x80057A78: lh          $t7, 0x8($s2)
        ctx->r15 = MEM_H(ctx->r18, 0X8);
            goto L_80057A88;
    }
    goto skip_1;
    // 0x80057A78: lh          $t7, 0x8($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X8);
    skip_1:
    // 0x80057A7C: b           L_80057AA0
    // 0x80057A80: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80057AA0;
    // 0x80057A80: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80057A84: lh          $t7, 0x8($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X8);
L_80057A88:
    // 0x80057A88: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80057A8C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80057A90: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80057A94: bnel        $at, $zero, L_80057A64
    if (ctx->r1 != 0) {
        // 0x80057A98: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80057A64;
    }
    goto skip_2;
    // 0x80057A98: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_2:
L_80057A9C:
    // 0x80057A9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057AA0:
    // 0x80057AA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80057AA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80057AA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80057AAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80057AB0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80057AB4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80057AB8: jr          $ra
    // 0x80057ABC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80057ABC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005EBC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EBC8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005EBCC: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8005EBD0: jr          $ra
    // 0x8005EBD4: sb          $t6, 0x38($t7)
    MEM_B(0X38, ctx->r15) = ctx->r14;
    return;
    // 0x8005EBD4: sb          $t6, 0x38($t7)
    MEM_B(0X38, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_8005E278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E278: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005E27C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005E280: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005E284: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005E288: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005E28C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005E290: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005E294: addiu       $s2, $zero, 0x4B
    ctx->r18 = ADD32(0, 0X4B);
L_8005E298:
    // 0x8005E298: jal         0x8005D8C0
    // 0x8005E29C: nop

    func_8005D8C0(rdram, ctx);
        goto after_0;
    // 0x8005E29C: nop

    after_0:
    // 0x8005E2A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005E2A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005E2A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E2AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005E2B0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8005E2B4: jal         0x80078D7C
    // 0x8005E2B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80078D7C(rdram, ctx);
        goto after_1;
    // 0x8005E2B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8005E2BC: jal         0x8007FCF0
    // 0x8005E2C0: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    func_8007FCF0(rdram, ctx);
        goto after_2;
    // 0x8005E2C0: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    after_2:
    // 0x8005E2C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005E2C8: bne         $s1, $s2, L_8005E298
    if (ctx->r17 != ctx->r18) {
        // 0x8005E2CC: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_8005E298;
    }
    // 0x8005E2CC: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x8005E2D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E2D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005E2D8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005E2DC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005E2E0: jr          $ra
    // 0x8005E2E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005E2E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800692D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800692D4: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800692D8: lw          $t7, -0x7CE8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CE8);
    // 0x800692DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800692E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800692E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800692E8: lbu         $t8, 0xF8($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XF8);
    // 0x800692EC: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x800692F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800692F4: beq         $t8, $zero, L_800694A4
    if (ctx->r24 == 0) {
        // 0x800692F8: lw          $a2, 0x88($t6)
        ctx->r6 = MEM_W(ctx->r14, 0X88);
            goto L_800694A4;
    }
    // 0x800692F8: lw          $a2, 0x88($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X88);
    // 0x800692FC: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x80069300: bltz        $v0, L_80069324
    if (SIGNED(ctx->r2) < 0) {
        // 0x80069304: slti        $at, $v0, 0x141
        ctx->r1 = SIGNED(ctx->r2) < 0X141 ? 1 : 0;
            goto L_80069324;
    }
    // 0x80069304: slti        $at, $v0, 0x141
    ctx->r1 = SIGNED(ctx->r2) < 0X141 ? 1 : 0;
    // 0x80069308: beq         $at, $zero, L_80069324
    if (ctx->r1 == 0) {
        // 0x8006930C: nop
    
            goto L_80069324;
    }
    // 0x8006930C: nop

    // 0x80069310: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x80069314: bltz        $v0, L_80069324
    if (SIGNED(ctx->r2) < 0) {
        // 0x80069318: slti        $at, $v0, 0xF1
        ctx->r1 = SIGNED(ctx->r2) < 0XF1 ? 1 : 0;
            goto L_80069324;
    }
    // 0x80069318: slti        $at, $v0, 0xF1
    ctx->r1 = SIGNED(ctx->r2) < 0XF1 ? 1 : 0;
    // 0x8006931C: bnel        $at, $zero, L_80069330
    if (ctx->r1 != 0) {
        // 0x80069320: lw          $v0, 0x1EC($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1EC);
            goto L_80069330;
    }
    goto skip_0;
    // 0x80069320: lw          $v0, 0x1EC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1EC);
    skip_0:
L_80069324:
    // 0x80069324: b           L_800694A8
    // 0x80069328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800694A8;
    // 0x80069328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006932C: lw          $v0, 0x1EC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1EC);
L_80069330:
    // 0x80069330: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80069334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80069338: beq         $v0, $zero, L_800693B4
    if (ctx->r2 == 0) {
        // 0x8006933C: nop
    
            goto L_800693B4;
    }
    // 0x8006933C: nop

    // 0x80069340: beq         $v0, $at, L_80069454
    if (ctx->r2 == ctx->r1) {
        // 0x80069344: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80069454;
    }
    // 0x80069344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80069348: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006934C: beq         $v0, $at, L_80069368
    if (ctx->r2 == ctx->r1) {
        // 0x80069350: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80069368;
    }
    // 0x80069350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80069354: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80069358: beq         $v0, $at, L_80069404
    if (ctx->r2 == ctx->r1) {
        // 0x8006935C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80069404;
    }
    // 0x8006935C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80069360: b           L_800694A8
    // 0x80069364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800694A8;
    // 0x80069364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80069368:
    // 0x80069368: jal         0x8004590C
    // 0x8006936C: addiu       $a1, $a2, 0x400
    ctx->r5 = ADD32(ctx->r6, 0X400);
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x8006936C: addiu       $a1, $a2, 0x400
    ctx->r5 = ADD32(ctx->r6, 0X400);
    after_0:
    // 0x80069370: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x80069374: addiu       $t9, $zero, 0x4222
    ctx->r25 = ADD32(0, 0X4222);
    // 0x80069378: addiu       $t2, $zero, 0x2244
    ctx->r10 = ADD32(0, 0X2244);
    // 0x8006937C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80069380: sh          $t9, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r25;
    // 0x80069384: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x80069388: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8006938C: sh          $t2, 0x1A($t4)
    MEM_H(0X1A, ctx->r12) = ctx->r10;
    // 0x80069390: sw          $zero, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = 0;
    // 0x80069394: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80069398: jal         0x80067BBC
    // 0x8006939C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8006939C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x800693A0: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    // 0x800693A4: jal         0x80067818
    // 0x800693A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x800693A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x800693AC: b           L_800694A8
    // 0x800693B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800694A8;
    // 0x800693B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800693B4:
    // 0x800693B4: jal         0x8004590C
    // 0x800693B8: addiu       $a1, $a2, 0x600
    ctx->r5 = ADD32(ctx->r6, 0X600);
    func_8004590C(rdram, ctx);
        goto after_3;
    // 0x800693B8: addiu       $a1, $a2, 0x600
    ctx->r5 = ADD32(ctx->r6, 0X600);
    after_3:
    // 0x800693BC: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x800693C0: addiu       $t5, $zero, 0x2224
    ctx->r13 = ADD32(0, 0X2224);
    // 0x800693C4: addiu       $t8, $zero, 0x4244
    ctx->r24 = ADD32(0, 0X4244);
    // 0x800693C8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800693CC: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x800693D0: sh          $t5, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r13;
    // 0x800693D4: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x800693D8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800693DC: sh          $t8, 0x1A($t9)
    MEM_H(0X1A, ctx->r25) = ctx->r24;
    // 0x800693E0: sw          $t1, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r9;
    // 0x800693E4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x800693E8: jal         0x80067BBC
    // 0x800693EC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x800693EC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_4:
    // 0x800693F0: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    // 0x800693F4: jal         0x80067818
    // 0x800693F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x800693F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x800693FC: b           L_800694A8
    // 0x80069400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800694A8;
    // 0x80069400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80069404:
    // 0x80069404: jal         0x8004590C
    // 0x80069408: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8004590C(rdram, ctx);
        goto after_6;
    // 0x80069408: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_6:
    // 0x8006940C: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x80069410: addiu       $t3, $zero, 0x2422
    ctx->r11 = ADD32(0, 0X2422);
    // 0x80069414: addiu       $t6, $zero, 0x2444
    ctx->r14 = ADD32(0, 0X2444);
    // 0x80069418: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8006941C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80069420: sh          $t3, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r11;
    // 0x80069424: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    // 0x80069428: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8006942C: sh          $t6, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r14;
    // 0x80069430: sw          $t0, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r8;
    // 0x80069434: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80069438: jal         0x80067BBC
    // 0x8006943C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_7;
    // 0x8006943C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_7:
    // 0x80069440: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    // 0x80069444: jal         0x80067818
    // 0x80069448: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_8;
    // 0x80069448: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x8006944C: b           L_800694A8
    // 0x80069450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800694A8;
    // 0x80069450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80069454:
    // 0x80069454: jal         0x8004590C
    // 0x80069458: addiu       $a1, $a2, 0x200
    ctx->r5 = ADD32(ctx->r6, 0X200);
    func_8004590C(rdram, ctx);
        goto after_9;
    // 0x80069458: addiu       $a1, $a2, 0x200
    ctx->r5 = ADD32(ctx->r6, 0X200);
    after_9:
    // 0x8006945C: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x80069460: addiu       $t8, $zero, 0x2242
    ctx->r24 = ADD32(0, 0X2242);
    // 0x80069464: addiu       $t2, $zero, 0x2244
    ctx->r10 = ADD32(0, 0X2244);
    // 0x80069468: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8006946C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80069470: sh          $t8, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r24;
    // 0x80069474: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x80069478: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8006947C: sh          $t2, 0x1A($t4)
    MEM_H(0X1A, ctx->r12) = ctx->r10;
    // 0x80069480: sw          $t5, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r13;
    // 0x80069484: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80069488: jal         0x80067BBC
    // 0x8006948C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_10;
    // 0x8006948C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_10:
    // 0x80069490: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    // 0x80069494: jal         0x80067818
    // 0x80069498: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_11;
    // 0x80069498: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x8006949C: b           L_800694A8
    // 0x800694A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800694A8;
    // 0x800694A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800694A4:
    // 0x800694A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800694A8:
    // 0x800694A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800694AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800694B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800694B4: jr          $ra
    // 0x800694B8: nop

    return;
    // 0x800694B8: nop

;}
RECOMP_FUNC void func_8078E918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078E918: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8078E91C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8078E920: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8078E924: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8078E928: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8078E92C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8078E930: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8078E934: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8078E938: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8078E93C: lui         $t1, 0x8079
    ctx->r9 = S32(RELOC_HI16(808, 0XA58) << 16);
    // 0x8078E940: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8078E944: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8078E948: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8078E94C: lw          $t1, -0x1688($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(808, 0XA58));
    // 0x8078E950: jr          $ra
    // 0x8078E954: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8078E954: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8078E958: nop

    // 0x8078E95C: nop

;}
RECOMP_FUNC void func_80536684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536684: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536688: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053668C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536690: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536694: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536698: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053669C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805366A0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805366A4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805366A8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805366AC: jr          $ra
    // 0x805366B0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805366B0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80568974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568974: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80568978: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8056897C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80568980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80568984: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x80568988: jal         0x80568710
    // 0x8056898C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x8056898C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80568990: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80568994: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80568998: jal         0x8005FE48
    // 0x8056899C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x8056899C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    after_1:
    // 0x805689A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805689A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805689A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805689AC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805689B0: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805689B4: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x805689B8: swc1        $f2, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f2.u32l;
    // 0x805689BC: swc1        $f2, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f2.u32l;
    // 0x805689C0: swc1        $f2, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f2.u32l;
    // 0x805689C4: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x805689C8: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x805689CC: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x805689D0: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x805689D4: jal         0x80569310
    // 0x805689D8: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    func_80569310(rdram, ctx);
        goto after_2;
    // 0x805689D8: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    after_2:
    // 0x805689DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805689E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805689E4: jr          $ra
    // 0x805689E8: nop

    return;
    // 0x805689E8: nop

;}
RECOMP_FUNC void func_804528E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804528E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804528EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804528F0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x804528F4: jal         0x804527B0
    // 0x804528F8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_804527B0(rdram, ctx);
        goto after_0;
    // 0x804528F8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_0:
    // 0x804528FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80452900: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452904: jr          $ra
    // 0x80452908: nop

    return;
    // 0x80452908: nop

;}
RECOMP_FUNC void func_80525784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80525784: lw          $t6, 0x174($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X174);
    // 0x80525788: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8052578C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80525790: lbu         $v1, 0x10($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X10);
    // 0x80525794: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80525798: beql        $v1, $a2, L_805257B4
    if (ctx->r3 == ctx->r6) {
        // 0x8052579C: sw          $a2, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r6;
            goto L_805257B4;
    }
    goto skip_0;
    // 0x8052579C: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    skip_0:
    // 0x805257A0: bne         $v1, $at, L_805257B4
    if (ctx->r3 != ctx->r1) {
        // 0x805257A4: nop
    
            goto L_805257B4;
    }
    // 0x805257A4: nop

    // 0x805257A8: jr          $ra
    // 0x805257AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    return;
    // 0x805257AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805257B0: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
L_805257B4:
    // 0x805257B4: jr          $ra
    // 0x805257B8: nop

    return;
    // 0x805257B8: nop

;}
RECOMP_FUNC void func_800316F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800316F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800316F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800316F8: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x800316FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80031700: jal         0x800310A0
    // 0x80031704: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x80031704: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80031708: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003170C: jal         0x80030EE8
    // 0x80031710: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80030EE8(rdram, ctx);
        goto after_1;
    // 0x80031710: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80031714: beq         $v0, $zero, L_80031724
    if (ctx->r2 == 0) {
        // 0x80031718: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80031724;
    }
    // 0x80031718: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003171C: jal         0x800310D0
    // 0x80031720: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800310D0(rdram, ctx);
        goto after_2;
    // 0x80031720: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_80031724:
    // 0x80031724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031728: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003172C: jr          $ra
    // 0x80031730: nop

    return;
    // 0x80031730: nop

;}
RECOMP_FUNC void func_804A1BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1BE8: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x804A1BEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804A1BF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804A1BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A1BF8: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x804A1BFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A1C00: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804A1C04: lwc1        $f2, 0x3C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804A1C08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804A1C0C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804A1C10: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x804A1C14: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x804A1C18: nop

    // 0x804A1C1C: bc1fl       L_804A1C30
    if (!c1cs) {
        // 0x804A1C20: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_804A1C30;
    }
    goto skip_0;
    // 0x804A1C20: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_0:
    // 0x804A1C24: b           L_804A1C70
    // 0x804A1C28: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
        goto L_804A1C70;
    // 0x804A1C28: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x804A1C2C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_804A1C30:
    // 0x804A1C30: lw          $a2, 0x40($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X40);
    // 0x804A1C34: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x804A1C38: jal         0x804A1320
    // 0x804A1C3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_804A1320(rdram, ctx);
        goto after_0;
    // 0x804A1C3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A1C40: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x804A1C44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804A1C48: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804A1C4C: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x804A1C50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804A1C54: bc1tl       L_804A1C70
    if (c1cs) {
        // 0x804A1C58: swc1        $f2, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
            goto L_804A1C70;
    }
    goto skip_1;
    // 0x804A1C58: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
    skip_1:
    // 0x804A1C5C: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x804A1C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804A1C64: b           L_804A1C70
    // 0x804A1C68: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
        goto L_804A1C70;
    // 0x804A1C68: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
    // 0x804A1C6C: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
L_804A1C70:
    // 0x804A1C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A1C74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804A1C78: jr          $ra
    // 0x804A1C7C: nop

    return;
    // 0x804A1C7C: nop

;}
RECOMP_FUNC void func_806E38C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E38C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E38CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E38D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806E38D4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E38D8: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x806E38DC: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x806E38E0: beql        $t6, $zero, L_806E3984
    if (ctx->r14 == 0) {
        // 0x806E38E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E3984;
    }
    goto skip_0;
    // 0x806E38E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E38E8: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x806E38EC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x806E38F0: beql        $t7, $at, L_806E3984
    if (ctx->r15 == ctx->r1) {
        // 0x806E38F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E3984;
    }
    goto skip_1;
    // 0x806E38F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806E38F8: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x806E38FC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806E3900: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x806E3904: beq         $t8, $zero, L_806E394C
    if (ctx->r24 == 0) {
        // 0x806E3908: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_806E394C;
    }
    // 0x806E3908: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x806E390C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806E3910: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x806E3914: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x806E3918: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x806E391C: jal         0x8004D1F0
    // 0x806E3920: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x806E3920: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806E3924: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806E3928: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806E392C: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x806E3930: jal         0x8004D698
    // 0x806E3934: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x806E3934: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x806E3938: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806E393C: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x806E3940: ori         $t0, $t9, 0xF0
    ctx->r8 = ctx->r25 | 0XF0;
    // 0x806E3944: b           L_806E3980
    // 0x806E3948: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
        goto L_806E3980;
    // 0x806E3948: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
L_806E394C:
    // 0x806E394C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806E3950: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x806E3954: jal         0x8004D1F0
    // 0x806E3958: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x806E3958: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x806E395C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806E3960: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806E3964: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x806E3968: jal         0x8004D698
    // 0x806E396C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_3;
    // 0x806E396C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x806E3970: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806E3974: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x806E3978: ori         $t2, $t1, 0xF
    ctx->r10 = ctx->r9 | 0XF;
    // 0x806E397C: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
L_806E3980:
    // 0x806E3980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E3984:
    // 0x806E3984: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E3988: jr          $ra
    // 0x806E398C: nop

    return;
    // 0x806E398C: nop

;}
RECOMP_FUNC void func_8001D398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D398: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8001D39C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8001D3A0: lw          $t6, 0xF10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XF10);
    // 0x8001D3A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D3A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D3AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001D3B0: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8001D3B4: lw          $v0, 0xF14($t8)
    ctx->r2 = MEM_W(ctx->r24, 0XF14);
    // 0x8001D3B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001D3BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001D3C0: jal         0x8001D0FC
    // 0x8001D3C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8001D0FC(rdram, ctx);
        goto after_0;
    // 0x8001D3C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8001D3C8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8001D3CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D3D0: sltiu       $at, $v0, 0x9
    ctx->r1 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x8001D3D4: bnel        $at, $zero, L_8001D418
    if (ctx->r1 != 0) {
        // 0x8001D3D8: sltiu       $at, $v0, 0x8
        ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
            goto L_8001D418;
    }
    goto skip_0;
    // 0x8001D3D8: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    skip_0:
    // 0x8001D3DC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8001D3E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8001D3E4: jal         0x8001D698
    // 0x8001D3E8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8001D698(rdram, ctx);
        goto after_1;
    // 0x8001D3E8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001D3EC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8001D3F0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001D3F4: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
    // 0x8001D3F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001D3FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D400: sb          $zero, 0x30($v0)
    MEM_B(0X30, ctx->r2) = 0;
    // 0x8001D404: jal         0x8001CE24
    // 0x8001D408: sb          $t0, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r8;
    func_8001CE24(rdram, ctx);
        goto after_2;
    // 0x8001D408: sb          $t0, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r8;
    after_2:
    // 0x8001D40C: b           L_8001D438
    // 0x8001D410: nop

        goto L_8001D438;
    // 0x8001D410: nop

    // 0x8001D414: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
L_8001D418:
    // 0x8001D418: beq         $at, $zero, L_8001D430
    if (ctx->r1 == 0) {
        // 0x8001D41C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001D430;
    }
    // 0x8001D41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D420: jal         0x8001D698
    // 0x8001D424: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8001D698(rdram, ctx);
        goto after_3;
    // 0x8001D424: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8001D428: b           L_8001D438
    // 0x8001D42C: nop

        goto L_8001D438;
    // 0x8001D42C: nop

L_8001D430:
    // 0x8001D430: jal         0x8001CE8C
    // 0x8001D434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001CE8C(rdram, ctx);
        goto after_4;
    // 0x8001D434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8001D438:
    // 0x8001D438: jal         0x8001D148
    // 0x8001D43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001D148(rdram, ctx);
        goto after_5;
    // 0x8001D43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8001D440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D444: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001D448: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D44C: jr          $ra
    // 0x8001D450: nop

    return;
    // 0x8001D450: nop

;}
RECOMP_FUNC void func_80714DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80714DD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80714DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80714DDC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80714DE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80714DE4: lh          $t6, 0x5E2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X5E2);
    // 0x80714DE8: lw          $v1, 0x5A0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5A0);
    // 0x80714DEC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80714DF0: sh          $t7, 0x5E2($v0)
    MEM_H(0X5E2, ctx->r2) = ctx->r15;
    // 0x80714DF4: lh          $a1, 0x5E2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X5E2);
    // 0x80714DF8: slti        $at, $a1, 0x3D
    ctx->r1 = SIGNED(ctx->r5) < 0X3D ? 1 : 0;
    // 0x80714DFC: bne         $at, $zero, L_80714E08
    if (ctx->r1 != 0) {
        // 0x80714E00: addiu       $t8, $a1, -0x3C
        ctx->r24 = ADD32(ctx->r5, -0X3C);
            goto L_80714E08;
    }
    // 0x80714E00: addiu       $t8, $a1, -0x3C
    ctx->r24 = ADD32(ctx->r5, -0X3C);
    // 0x80714E04: sh          $t8, 0x5E2($v0)
    MEM_H(0X5E2, ctx->r2) = ctx->r24;
L_80714E08:
    // 0x80714E08: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x80714E0C: lh          $t9, 0x5E2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X5E2);
    // 0x80714E10: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80714E14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80714E18: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80714E1C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80714E20: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80714E24: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80714E28: jal         0x80066DE4
    // 0x80714E2C: nop

    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x80714E2C: nop

    after_0:
    // 0x80714E30: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80714E34: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80714E38: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x80714E3C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80714E40: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80714E44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80714E48: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80714E4C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80714E50: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x80714E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80714E58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80714E5C: jr          $ra
    // 0x80714E60: nop

    return;
    // 0x80714E60: nop

;}
RECOMP_FUNC void func_804C1770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1770: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x804C1774: addiu       $at, $zero, 0x411F
    ctx->r1 = ADD32(0, 0X411F);
    // 0x804C1778: beq         $v0, $at, L_804C1790
    if (ctx->r2 == ctx->r1) {
        // 0x804C177C: addiu       $at, $zero, 0x4120
        ctx->r1 = ADD32(0, 0X4120);
            goto L_804C1790;
    }
    // 0x804C177C: addiu       $at, $zero, 0x4120
    ctx->r1 = ADD32(0, 0X4120);
    // 0x804C1780: beq         $v0, $at, L_804C179C
    if (ctx->r2 == ctx->r1) {
        // 0x804C1784: nop
    
            goto L_804C179C;
    }
    // 0x804C1784: nop

    // 0x804C1788: b           L_804C17A8
    // 0x804C178C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C17A8;
    // 0x804C178C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C1790:
    // 0x804C1790: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(203, 0X714) << 16);
    // 0x804C1794: jr          $ra
    // 0x804C1798: addiu       $v0, $v0, 0x1E84
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(203, 0X714));
    return;
    // 0x804C1798: addiu       $v0, $v0, 0x1E84
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(203, 0X714));
L_804C179C:
    // 0x804C179C: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(203, 0XCFC) << 16);
    // 0x804C17A0: jr          $ra
    // 0x804C17A4: addiu       $v0, $v0, 0x246C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(203, 0XCFC));
    return;
    // 0x804C17A4: addiu       $v0, $v0, 0x246C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(203, 0XCFC));
L_804C17A8:
    // 0x804C17A8: jr          $ra
    // 0x804C17AC: nop

    return;
    // 0x804C17AC: nop

;}
RECOMP_FUNC void func_807AFB50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AFB50: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(871, 0X10) << 16);
    // 0x807AFB54: addiu       $v0, $v0, -0x4A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(871, 0X10));
    // 0x807AFB58: jr          $ra
    // 0x807AFB5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807AFB5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8044A28C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A28C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044A290: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8044A294: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8044A298: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A29C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044A2A0: bne         $a2, $zero, L_8044A2F4
    if (ctx->r6 != 0) {
        // 0x8044A2A4: lw          $v0, 0x1F4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X1F4);
            goto L_8044A2F4;
    }
    // 0x8044A2A4: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044A2A8: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x8044A2AC: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x8044A2B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044A2B4: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x8044A2B8: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8044A2BC: bne         $at, $zero, L_8044A2E4
    if (ctx->r1 != 0) {
        // 0x8044A2C0: sw          $t7, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->r15;
            goto L_8044A2E4;
    }
    // 0x8044A2C0: sw          $t7, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r15;
    // 0x8044A2C4: jal         0x80446C40
    // 0x8044A2C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446C40(rdram, ctx);
        goto after_0;
    // 0x8044A2C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8044A2CC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A2D0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A2D4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8044A2D8: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x8044A2DC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044A2E0: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_8044A2E4:
    // 0x8044A2E4: jal         0x8044A060
    // 0x8044A2E8: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    func_8044A060(rdram, ctx);
        goto after_1;
    // 0x8044A2E8: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    after_1:
    // 0x8044A2EC: b           L_8044A338
    // 0x8044A2F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044A338;
    // 0x8044A2F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A2F4:
    // 0x8044A2F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044A2F8: bne         $a2, $at, L_8044A320
    if (ctx->r6 != ctx->r1) {
        // 0x8044A2FC: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044A320;
    }
    // 0x8044A2FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044A300: jal         0x80446C40
    // 0x8044A304: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446C40(rdram, ctx);
        goto after_2;
    // 0x8044A304: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8044A308: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A30C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A310: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x8044A314: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044A318: b           L_8044A334
    // 0x8044A31C: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_8044A334;
    // 0x8044A31C: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
L_8044A320:
    // 0x8044A320: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8044A324: bnel        $a2, $at, L_8044A338
    if (ctx->r6 != ctx->r1) {
        // 0x8044A328: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044A338;
    }
    goto skip_0;
    // 0x8044A328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044A32C: jal         0x80446C74
    // 0x8044A330: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80446C74(rdram, ctx);
        goto after_3;
    // 0x8044A330: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
L_8044A334:
    // 0x8044A334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A338:
    // 0x8044A338: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044A33C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8044A340: jr          $ra
    // 0x8044A344: nop

    return;
    // 0x8044A344: nop

;}
RECOMP_FUNC void gfxprint_prout(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F9D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007F9D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007F9DC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8007F9E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007F9E4: jal         0x8007F920
    // 0x8007F9E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    gfxprint_write(rdram, ctx);
        goto after_0;
    // 0x8007F9E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007F9EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007F9F0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8007F9F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007F9F8: jr          $ra
    // 0x8007F9FC: nop

    return;
    // 0x8007F9FC: nop

;}
RECOMP_FUNC void func_8069F2C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069F2C8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8069F2CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8069F2D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8069F2D4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069F2D8: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x8069F2DC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8069F2E0: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8069F2E4: sb          $a1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r5;
    // 0x8069F2E8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8069F2EC: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(580, 0X580) << 16);
    // 0x8069F2F0: sw          $a1, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r5;
    // 0x8069F2F4: addiu       $t6, $t6, -0xB10
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(580, 0X580));
    // 0x8069F2F8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8069F2FC: lui         $t9, 0x806A
    ctx->r25 = S32(RELOC_HI16(580, 0X258) << 16);
    // 0x8069F300: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8069F304: addiu       $t9, $t9, -0xE38
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(580, 0X258));
    // 0x8069F308: sb          $t8, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r24;
    // 0x8069F30C: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8069F310: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x8069F314: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8069F318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8069F31C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x8069F320: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x8069F324: jal         0x80066DE4
    // 0x8069F328: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8069F328: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8069F32C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8069F330: jal         0x80066E88
    // 0x8069F334: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8069F334: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8069F338: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8069F33C: jal         0x80065954
    // 0x8069F340: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8069F340: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8069F344: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8069F348: jal         0x80065954
    // 0x8069F34C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x8069F34C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8069F350: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8069F354: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8069F358: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8069F35C: lwc1        $f2, 0x0($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8069F360: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5E0) << 16);
    // 0x8069F364: lwc1        $f12, -0xAB0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5E0));
    // 0x8069F368: mul.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8069F36C: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x8069F370: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5E4) << 16);
    // 0x8069F374: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8069F378: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x8069F37C: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x8069F380: addiu       $t2, $t2, -0x7C48
    ctx->r10 = ADD32(ctx->r10, -0X7C48);
    // 0x8069F384: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x8069F388: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8069F38C: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    // 0x8069F390: lwc1        $f10, -0xAAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5E4));
    // 0x8069F394: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5E8) << 16);
    // 0x8069F398: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8069F39C: swc1        $f18, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f18.u32l;
    // 0x8069F3A0: lwc1        $f4, -0xAA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5E8));
    // 0x8069F3A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8069F3A8: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8069F3AC: swc1        $f6, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f6.u32l;
    // 0x8069F3B0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8069F3B4: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8069F3B8: nop

    // 0x8069F3BC: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8069F3C0: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
    // 0x8069F3C4: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    // 0x8069F3C8: lwc1        $f4, 0x4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8069F3CC: sw          $t2, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r10;
    // 0x8069F3D0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8069F3D4: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x8069F3D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8069F3DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8069F3E0: sb          $t3, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r11;
    // 0x8069F3E4: jr          $ra
    // 0x8069F3E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8069F3E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_806EDE8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EDE8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EDE90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EDE94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EDE98: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EDE9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EDEA0: jal         0x800577D8
    // 0x806EDEA4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806EDEA4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x806EDEA8: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x806EDEAC: blez        $v0, L_806EDEBC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806EDEB0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_806EDEBC;
    }
    // 0x806EDEB0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x806EDEB4: b           L_806EDED8
    // 0x806EDEB8: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
        goto L_806EDED8;
    // 0x806EDEB8: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
L_806EDEBC:
    // 0x806EDEBC: jal         0x806ED45C
    // 0x806EDEC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED45C(rdram, ctx);
        goto after_1;
    // 0x806EDEC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EDEC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDEC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EDECC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x806EDED0: jal         0x806EE584
    // 0x806EDED4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_2;
    // 0x806EDED4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_2:
L_806EDED8:
    // 0x806EDED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806EDEDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EDEE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EDEE4: jr          $ra
    // 0x806EDEE8: nop

    return;
    // 0x806EDEE8: nop

;}
RECOMP_FUNC void func_8078ACF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078ACF0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8078ACF4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8078ACF8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8078ACFC: lui         $t7, 0x8079
    ctx->r15 = S32(RELOC_HI16(793, 0XDC4) << 16);
    // 0x8078AD00: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x8078AD04: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8078AD08: lw          $t7, -0x4FFC($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(793, 0XDC4));
    // 0x8078AD0C: jr          $ra
    // 0x8078AD10: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x8078AD10: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_8043DF3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DF3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043DF40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043DF44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043DF48: jal         0x8043DCF4
    // 0x8043DF4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8043DCF4(rdram, ctx);
        goto after_0;
    // 0x8043DF4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8043DF50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8043DF54: bne         $v0, $at, L_8043DF64
    if (ctx->r2 != ctx->r1) {
        // 0x8043DF58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8043DF64;
    }
    // 0x8043DF58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043DF5C: jal         0x8043E0F8
    // 0x8043DF60: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8043E0F8(rdram, ctx);
        goto after_1;
    // 0x8043DF60: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
L_8043DF64:
    // 0x8043DF64: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8043DF68: jal         0x80048F84
    // 0x8043DF6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8043DF6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8043DF70: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8043DF74: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8043DF78: jal         0x80065ABC
    // 0x8043DF7C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_3;
    // 0x8043DF7C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_3:
    // 0x8043DF80: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8043DF84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043DF88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043DF8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043DF90: jr          $ra
    // 0x8043DF94: nop

    return;
    // 0x8043DF94: nop

;}
RECOMP_FUNC void func_80473904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80473904: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80473908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8047390C: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80473910: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80473914: beql        $t6, $zero, L_80473970
    if (ctx->r14 == 0) {
        // 0x80473918: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80473970;
    }
    goto skip_0;
    // 0x80473918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8047391C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80473920: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80473924: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80473928: jalr        $t9
    // 0x8047392C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8047392C: nop

    after_0:
    // 0x80473930: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80473934: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80473938: bne         $v0, $at, L_80473944
    if (ctx->r2 != ctx->r1) {
        // 0x8047393C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80473944;
    }
    // 0x8047393C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80473940: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80473944:
    // 0x80473944: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80473948: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x8047394C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80473950: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80473954: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80473958: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8047395C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x80473960: jal         0x8047380C
    // 0x80473964: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8047380C(rdram, ctx);
        goto after_1;
    // 0x80473964: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80473968: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8047396C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80473970:
    // 0x80473970: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80473974: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80473978: jr          $ra
    // 0x8047397C: nop

    return;
    // 0x8047397C: nop

;}
RECOMP_FUNC void func_804463F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804463F8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804463FC: addiu       $t6, $zero, 0x1B6C
    ctx->r14 = ADD32(0, 0X1B6C);
    // 0x80446400: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446404: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80446408: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    // 0x8044640C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446410: sw          $t7, 0x6CAC($at)
    MEM_W(0X6CAC, ctx->r1) = ctx->r15;
    // 0x80446414: jr          $ra
    // 0x80446418: sw          $zero, 0x220($v0)
    MEM_W(0X220, ctx->r2) = 0;
    return;
    // 0x80446418: sw          $zero, 0x220($v0)
    MEM_W(0X220, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80526290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526290: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80526294: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80526298: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8052629C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805262A0: jal         0x80045A34
    // 0x805262A4: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805262A4: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    after_0:
    // 0x805262A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x805262AC: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(327, 0X354) << 16);
    // 0x805262B0: bne         $v0, $zero, L_805262C0
    if (ctx->r2 != 0) {
        // 0x805262B4: sw          $v0, 0x1F4($a2)
        MEM_W(0X1F4, ctx->r6) = ctx->r2;
            goto L_805262C0;
    }
    // 0x805262B4: sw          $v0, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = ctx->r2;
    // 0x805262B8: b           L_80526338
    // 0x805262BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80526338;
    // 0x805262BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805262C0:
    // 0x805262C0: lw          $s0, 0x1F4($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X1F4);
    // 0x805262C4: addiu       $t6, $t6, 0x6254
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(327, 0X354));
    // 0x805262C8: sw          $t6, 0x1F8($a2)
    MEM_W(0X1F8, ctx->r6) = ctx->r14;
    // 0x805262CC: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x805262D0: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    // 0x805262D4: jal         0x80064D1C
    // 0x805262D8: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x805262D8: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    after_1:
    // 0x805262DC: bne         $v0, $zero, L_805262EC
    if (ctx->r2 != 0) {
        // 0x805262E0: sw          $v0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r2;
            goto L_805262EC;
    }
    // 0x805262E0: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x805262E4: b           L_80526338
    // 0x805262E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80526338;
    // 0x805262E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805262EC:
    // 0x805262EC: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x805262F0: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x805262F4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x805262F8: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x805262FC: jal         0x80064D1C
    // 0x80526300: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    func_80064D1C(rdram, ctx);
        goto after_2;
    // 0x80526300: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_2:
    // 0x80526304: bne         $v0, $zero, L_80526314
    if (ctx->r2 != 0) {
        // 0x80526308: sw          $v0, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r2;
            goto L_80526314;
    }
    // 0x80526308: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x8052630C: b           L_80526338
    // 0x80526310: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80526338;
    // 0x80526310: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80526314:
    // 0x80526314: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80526318: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x8052631C: jal         0x80064D1C
    // 0x80526320: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80064D1C(rdram, ctx);
        goto after_3;
    // 0x80526320: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_3:
    // 0x80526324: bne         $v0, $zero, L_80526334
    if (ctx->r2 != 0) {
        // 0x80526328: sw          $v0, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r2;
            goto L_80526334;
    }
    // 0x80526328: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8052632C: b           L_80526338
    // 0x80526330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80526338;
    // 0x80526330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80526334:
    // 0x80526334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80526338:
    // 0x80526338: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8052633C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80526340: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80526344: jr          $ra
    // 0x80526348: nop

    return;
    // 0x80526348: nop

;}
