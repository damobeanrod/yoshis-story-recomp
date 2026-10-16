#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8076072C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076072C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80760730: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80760734: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80760738: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8076073C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80760740: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80760744: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80760748: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8076074C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80760750: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80760754: jr          $ra
    // 0x80760758: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80760758: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80665754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80665754: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80665758: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8066575C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80665760: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x80665764: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80665768: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066576C: beq         $v0, $zero, L_8066577C
    if (ctx->r2 == 0) {
        // 0x80665770: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8066577C;
    }
    // 0x80665770: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80665774: b           L_80665790
    // 0x80665778: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_80665790;
    // 0x80665778: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8066577C:
    // 0x8066577C: jal         0x8066622C
    // 0x80665780: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8066622C(rdram, ctx);
        goto after_0;
    // 0x80665780: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80665784: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80665788: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8066578C: sb          $t7, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = ctx->r15;
L_80665790:
    // 0x80665790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80665794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80665798: jr          $ra
    // 0x8066579C: nop

    return;
    // 0x8066579C: nop

;}
RECOMP_FUNC void func_804C0C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0C2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C0C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C0C34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C0C38: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804C0C3C: jalr        $t9
    // 0x804C0C40: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804C0C40: nop

    after_0:
    // 0x804C0C44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C0C48: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x804C0C4C: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x804C0C50: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x804C0C54: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x804C0C58: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x804C0C5C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x804C0C60: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x804C0C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C0C68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C0C6C: jr          $ra
    // 0x804C0C70: nop

    return;
    // 0x804C0C70: nop

;}
RECOMP_FUNC void strchr_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ADD4: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8008ADD8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8008ADDC: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8008ADE0: beql        $t6, $v1, L_8008AE0C
    if (ctx->r14 == ctx->r3) {
        // 0x8008ADE4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8008AE0C;
    }
    goto skip_0;
    // 0x8008ADE4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
L_8008ADE8:
    // 0x8008ADE8: bnel        $v1, $zero, L_8008ADFC
    if (ctx->r3 != 0) {
        // 0x8008ADEC: lbu         $v1, 0x1($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X1);
            goto L_8008ADFC;
    }
    goto skip_1;
    // 0x8008ADEC: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x8008ADF0: jr          $ra
    // 0x8008ADF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8008ADF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008ADF8: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
L_8008ADFC:
    // 0x8008ADFC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008AE00: bne         $v0, $v1, L_8008ADE8
    if (ctx->r2 != ctx->r3) {
        // 0x8008AE04: nop
    
            goto L_8008ADE8;
    }
    // 0x8008AE04: nop

    // 0x8008AE08: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8008AE0C:
    // 0x8008AE0C: jr          $ra
    // 0x8008AE10: nop

    return;
    // 0x8008AE10: nop

;}
RECOMP_FUNC void func_805C99CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C99CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805C99D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C99D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C99D8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C99DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C99E0: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x805C99E4: bnel        $t6, $zero, L_805C9A48
    if (ctx->r14 != 0) {
        // 0x805C99E8: lw          $v0, 0x40($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X40);
            goto L_805C9A48;
    }
    goto skip_0;
    // 0x805C99E8: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
    skip_0:
    // 0x805C99EC: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x805C99F0: bnel        $t7, $zero, L_805C9A48
    if (ctx->r15 != 0) {
        // 0x805C99F4: lw          $v0, 0x40($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X40);
            goto L_805C9A48;
    }
    goto skip_1;
    // 0x805C99F4: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
    skip_1:
    // 0x805C99F8: jal         0x805C7BAC
    // 0x805C99FC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_805C7BAC(rdram, ctx);
        goto after_0;
    // 0x805C99FC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x805C9A00: beq         $v0, $zero, L_805C9A44
    if (ctx->r2 == 0) {
        // 0x805C9A04: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_805C9A44;
    }
    // 0x805C9A04: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805C9A08: addiu       $t8, $zero, 0x2710
    ctx->r24 = ADD32(0, 0X2710);
    // 0x805C9A0C: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x805C9A10: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x805C9A14: sw          $t8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r24;
    // 0x805C9A18: sw          $t9, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r25;
    // 0x805C9A1C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x805C9A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9A24: jal         0x805C74C8
    // 0x805C9A28: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_805C74C8(rdram, ctx);
        goto after_1;
    // 0x805C9A28: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_1:
    // 0x805C9A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9A30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C9A34: jal         0x805C9D10
    // 0x805C9A38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805C9D10(rdram, ctx);
        goto after_2;
    // 0x805C9A38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x805C9A3C: b           L_805C9A88
    // 0x805C9A40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C9A88;
    // 0x805C9A40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C9A44:
    // 0x805C9A44: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
L_805C9A48:
    // 0x805C9A48: beq         $v0, $zero, L_805C9A58
    if (ctx->r2 == 0) {
        // 0x805C9A4C: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_805C9A58;
    }
    // 0x805C9A4C: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x805C9A50: sw          $t0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r8;
    // 0x805C9A54: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_805C9A58:
    // 0x805C9A58: bne         $v0, $zero, L_805C9A7C
    if (ctx->r2 != 0) {
        // 0x805C9A5C: nop
    
            goto L_805C9A7C;
    }
    // 0x805C9A5C: nop

    // 0x805C9A60: lw          $t1, 0x2C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X2C);
    // 0x805C9A64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805C9A68: bne         $t1, $at, L_805C9A74
    if (ctx->r9 != ctx->r1) {
        // 0x805C9A6C: nop
    
            goto L_805C9A74;
    }
    // 0x805C9A6C: nop

    // 0x805C9A70: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
L_805C9A74:
    // 0x805C9A74: jal         0x805C7ABC
    // 0x805C9A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7ABC(rdram, ctx);
        goto after_3;
    // 0x805C9A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_805C9A7C:
    // 0x805C9A7C: jal         0x805C6CA4
    // 0x805C9A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C6CA4(rdram, ctx);
        goto after_4;
    // 0x805C9A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805C9A84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C9A88:
    // 0x805C9A88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C9A8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805C9A90: jr          $ra
    // 0x805C9A94: nop

    return;
    // 0x805C9A94: nop

;}
RECOMP_FUNC void func_8005A994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A998: beq         $a0, $zero, L_8005A9AC
    if (ctx->r4 == 0) {
        // 0x8005A99C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8005A9AC;
    }
    // 0x8005A99C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A9A0: sw          $a2, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->r6;
    // 0x8005A9A4: jal         0x8005A938
    // 0x8005A9A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8005A938(rdram, ctx);
        goto after_0;
    // 0x8005A9A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_8005A9AC:
    // 0x8005A9AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A9B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A9B4: jr          $ra
    // 0x8005A9B8: nop

    return;
    // 0x8005A9B8: nop

;}
RECOMP_FUNC void func_804249F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804249F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804249F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804249FC: jal         0x804249A0
    // 0x80424A00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804249A0(rdram, ctx);
        goto after_0;
    // 0x80424A00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80424A04: jal         0x80423038
    // 0x80424A08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80423038(rdram, ctx);
        goto after_1;
    // 0x80424A08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80424A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80424A10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80424A14: jr          $ra
    // 0x80424A18: nop

    return;
    // 0x80424A18: nop

;}
RECOMP_FUNC void func_8042F134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042F138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042F13C: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8042F140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8042F144: beq         $t6, $zero, L_8042F180
    if (ctx->r14 == 0) {
        // 0x8042F148: nop
    
            goto L_8042F180;
    }
    // 0x8042F148: nop

    // 0x8042F14C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042F150: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x8042F154: jalr        $t9
    // 0x8042F158: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8042F158: nop

    after_0:
    // 0x8042F15C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042F160: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x8042F164: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x8042F168: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8042F16C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8042F170: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8042F174: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8042F178: b           L_8042F180
    // 0x8042F17C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_8042F180;
    // 0x8042F17C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_8042F180:
    // 0x8042F180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042F184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042F188: jr          $ra
    // 0x8042F18C: nop

    return;
    // 0x8042F18C: nop

;}
RECOMP_FUNC void func_806805BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806805BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806805C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806805C4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806805C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806805CC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x806805D0: jal         0x80062684
    // 0x806805D4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x806805D4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x806805D8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x806805DC: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x806805E0: lw          $t7, 0x7F78($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7F78);
    // 0x806805E4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x806805E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806805EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806805F0: div         $zero, $t7, $t9
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r25)));
    // 0x806805F4: bne         $t9, $zero, L_80680600
    if (ctx->r25 != 0) {
        // 0x806805F8: nop
    
            goto L_80680600;
    }
    // 0x806805F8: nop

    // 0x806805FC: break       7
    do_break(2154300924);
L_80680600:
    // 0x80680600: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80680604: bne         $t9, $at, L_80680618
    if (ctx->r25 != ctx->r1) {
        // 0x80680608: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80680618;
    }
    // 0x80680608: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8068060C: bne         $t7, $at, L_80680618
    if (ctx->r15 != ctx->r1) {
        // 0x80680610: nop
    
            goto L_80680618;
    }
    // 0x80680610: nop

    // 0x80680614: break       6
    do_break(2154300948);
L_80680618:
    // 0x80680618: mfhi        $t0
    ctx->r8 = hi;
    // 0x8068061C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80680620: bne         $t0, $zero, L_80680638
    if (ctx->r8 != 0) {
        // 0x80680624: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80680638;
    }
    // 0x80680624: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80680628: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8068062C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80680630: jal         0x80680D04
    // 0x80680634: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    func_80680D04(rdram, ctx);
        goto after_1;
    // 0x80680634: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    after_1:
L_80680638:
    // 0x80680638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8068063C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80680640: jr          $ra
    // 0x80680644: nop

    return;
    // 0x80680644: nop

;}
RECOMP_FUNC void func_80421578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421578: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042157C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80421580: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80421584: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80421588: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042158C: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x80421590: jal         0x80421AB4
    // 0x80421594: lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X18);
    func_80421AB4(rdram, ctx);
        goto after_0;
    // 0x80421594: lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X18);
    after_0:
    // 0x80421598: jal         0x80421120
    // 0x8042159C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80421120(rdram, ctx);
        goto after_1;
    // 0x8042159C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804215A0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x804215A4: jal         0x80048F84
    // 0x804215A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x804215A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x804215AC: jal         0x80421478
    // 0x804215B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80421478(rdram, ctx);
        goto after_3;
    // 0x804215B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804215B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804215B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804215BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804215C0: jr          $ra
    // 0x804215C4: nop

    return;
    // 0x804215C4: nop

;}
RECOMP_FUNC void func_800598F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800598F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800598F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800598F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800598FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80059900: jal         0x80081C64
    // 0x80059904: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x80059904: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x80059908: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8005990C: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80059910: lw          $v1, 0x3F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3F4);
    // 0x80059914: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80059918: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005991C: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80059920: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80059924: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059928: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8005992C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80059930: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80059934: lw          $t0, 0x478($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X478);
    // 0x80059938: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8005993C: lwc1        $f4, 0xBA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XBA8);
    // 0x80059940: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80059944: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80059948: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8005994C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80059950: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059954: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80059958: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8005995C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80059960: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80059964: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80059968: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005996C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80059970: lwc1        $f8, 0x30($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X30);
    // 0x80059974: add.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80059978: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8005997C: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80059980: c.le.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl <= ctx->f16.fl;
    // 0x80059984: nop

    // 0x80059988: bc1f        L_80059994
    if (!c1cs) {
        // 0x8005998C: nop
    
            goto L_80059994;
    }
    // 0x8005998C: nop

    // 0x80059990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059994:
    // 0x80059994: beql        $v0, $zero, L_80059A34
    if (ctx->r2 == 0) {
        // 0x80059998: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80059A34;
    }
    goto skip_0;
    // 0x80059998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005999C: jal         0x80081C64
    // 0x800599A0: lwc1        $f12, 0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X8);
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x800599A0: lwc1        $f12, 0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X8);
    after_1:
    // 0x800599A4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800599A8: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x800599AC: lw          $v1, 0x3F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3F4);
    // 0x800599B0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800599B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800599B8: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800599BC: lwc1        $f18, 0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800599C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800599C4: div.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800599C8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800599CC: lw          $t1, 0x478($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X478);
    // 0x800599D0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800599D4: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800599D8: lwc1        $f18, 0xBAC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XBAC);
    // 0x800599DC: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x800599E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800599E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800599E8: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800599EC: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800599F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800599F4: mul.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800599F8: lwc1        $f16, 0x30($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X30);
    // 0x800599FC: mul.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80059A00: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80059A04: add.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80059A08: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80059A0C: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80059A10: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80059A14: add.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80059A18: add.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80059A1C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80059A20: nop

    // 0x80059A24: bc1f        L_80059A30
    if (!c1cs) {
        // 0x80059A28: nop
    
            goto L_80059A30;
    }
    // 0x80059A28: nop

    // 0x80059A2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059A30:
    // 0x80059A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80059A34:
    // 0x80059A34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80059A38: jr          $ra
    // 0x80059A3C: nop

    return;
    // 0x80059A3C: nop

;}
RECOMP_FUNC void func_805DA520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA520: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805DA524: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805DA528: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DA52C: jal         0x8004700C
    // 0x805DA530: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805DA530: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805DA534: beq         $v0, $zero, L_805DA5FC
    if (ctx->r2 == 0) {
        // 0x805DA538: lw          $a1, 0x1F4($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X1F4);
            goto L_805DA5FC;
    }
    // 0x805DA538: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    // 0x805DA53C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DA540: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x805DA544: jal         0x805DA464
    // 0x805DA548: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_805DA464(rdram, ctx);
        goto after_1;
    // 0x805DA548: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x805DA54C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x805DA550: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805DA554: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x805DA558: bnel        $t6, $zero, L_805DA600
    if (ctx->r14 != 0) {
        // 0x805DA55C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DA600;
    }
    goto skip_0;
    // 0x805DA55C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805DA560: lbu         $t7, 0x18($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X18);
    // 0x805DA564: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805DA568: bnel        $t7, $at, L_805DA600
    if (ctx->r15 != ctx->r1) {
        // 0x805DA56C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DA600;
    }
    goto skip_1;
    // 0x805DA56C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805DA570: lbu         $t8, 0x30($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X30);
    // 0x805DA574: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x805DA578: bnel        $t8, $at, L_805DA600
    if (ctx->r24 != ctx->r1) {
        // 0x805DA57C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DA600;
    }
    goto skip_2;
    // 0x805DA57C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805DA580: lwc1        $f4, 0x84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
    // 0x805DA584: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805DA588: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x805DA58C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805DA590: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805DA594: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805DA598: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x805DA59C: nop

    // 0x805DA5A0: bc1fl       L_805DA600
    if (!c1cs) {
        // 0x805DA5A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DA600;
    }
    goto skip_3;
    // 0x805DA5A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x805DA5A8: lw          $t9, 0x174($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X174);
    // 0x805DA5AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DA5B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DA5B4: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x805DA5B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805DA5BC: andi        $t1, $t0, 0xF00
    ctx->r9 = ctx->r8 & 0XF00;
    // 0x805DA5C0: beql        $t1, $zero, L_805DA600
    if (ctx->r9 == 0) {
        // 0x805DA5C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DA600;
    }
    goto skip_4;
    // 0x805DA5C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x805DA5C8: jal         0x805DAA20
    // 0x805DA5CC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805DAA20(rdram, ctx);
        goto after_2;
    // 0x805DA5CC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x805DA5D0: jal         0x800677F8
    // 0x805DA5D4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800677F8(rdram, ctx);
        goto after_3;
    // 0x805DA5D4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_3:
    // 0x805DA5D8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x805DA5DC: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x805DA5E0: lw          $t2, 0xF70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XF70);
    // 0x805DA5E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805DA5E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DA5EC: sw          $v1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r3;
    // 0x805DA5F0: lw          $t3, 0xF70($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XF70);
    // 0x805DA5F4: jal         0x805DA32C
    // 0x805DA5F8: sw          $v1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r3;
    func_805DA32C(rdram, ctx);
        goto after_4;
    // 0x805DA5F8: sw          $v1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r3;
    after_4:
L_805DA5FC:
    // 0x805DA5FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805DA600:
    // 0x805DA600: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DA604: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805DA608: jr          $ra
    // 0x805DA60C: nop

    return;
    // 0x805DA60C: nop

;}
RECOMP_FUNC void func_8005A2C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A2C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005A2C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005A2C8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8005A2CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005A2D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005A2D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005A2D8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8005A2DC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8005A2E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005A2E4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8005A2E8: beq         $s1, $zero, L_8005A34C
    if (ctx->r17 == 0) {
        // 0x8005A2EC: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8005A34C;
    }
    // 0x8005A2EC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8005A2F0: lui         $s4, 0x800F
    ctx->r20 = S32(0X800F << 16);
    // 0x8005A2F4: addiu       $s4, $s4, 0x7EA0
    ctx->r20 = ADD32(ctx->r20, 0X7EA0);
    // 0x8005A2F8: addiu       $s3, $zero, 0x4001
    ctx->r19 = ADD32(0, 0X4001);
    // 0x8005A2FC: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_8005A300:
    // 0x8005A300: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8005A304: beql        $s2, $t6, L_8005A340
    if (ctx->r18 == ctx->r14) {
        // 0x8005A308: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_8005A340;
    }
    goto skip_0;
    // 0x8005A308: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    skip_0:
    // 0x8005A30C: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x8005A310: bnel        $s3, $t7, L_8005A32C
    if (ctx->r19 != ctx->r15) {
        // 0x8005A314: lw          $t8, 0x59C($s4)
        ctx->r24 = MEM_W(ctx->r20, 0X59C);
            goto L_8005A32C;
    }
    goto skip_1;
    // 0x8005A314: lw          $t8, 0x59C($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X59C);
    skip_1:
    // 0x8005A318: jal         0x8005A070
    // 0x8005A31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005A070(rdram, ctx);
        goto after_0;
    // 0x8005A31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8005A320: b           L_8005A340
    // 0x8005A324: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_8005A340;
    // 0x8005A324: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8005A328: lw          $t8, 0x59C($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X59C);
L_8005A32C:
    // 0x8005A32C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005A330: lw          $t9, 0x110($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X110);
    // 0x8005A334: jalr        $t9
    // 0x8005A338: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8005A338: nop

    after_1:
    // 0x8005A33C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8005A340:
    // 0x8005A340: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8005A344: bne         $s1, $zero, L_8005A300
    if (ctx->r17 != 0) {
        // 0x8005A348: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8005A300;
    }
    // 0x8005A348: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8005A34C:
    // 0x8005A34C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005A350: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005A354: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A358: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005A35C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005A360: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8005A364: jr          $ra
    // 0x8005A368: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005A368: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_804D9088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D9088: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804D908C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804D9090: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804D9094: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804D9098: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804D909C: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    // 0x804D90A0: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x804D90A4: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x804D90A8: bne         $at, $zero, L_804D90DC
    if (ctx->r1 != 0) {
        // 0x804D90AC: sw          $v0, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r2;
            goto L_804D90DC;
    }
    // 0x804D90AC: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x804D90B0: jal         0x804D8FC4
    // 0x804D90B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804D8FC4(rdram, ctx);
        goto after_0;
    // 0x804D90B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x804D90B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804D90BC: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x804D90C0: sw          $t9, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r25;
    // 0x804D90C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804D90C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804D90CC: jal         0x804D9108
    // 0x804D90D0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_804D9108(rdram, ctx);
        goto after_1;
    // 0x804D90D0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x804D90D4: b           L_804D90F8
    // 0x804D90D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804D90F8;
    // 0x804D90D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804D90DC:
    // 0x804D90DC: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x804D90E0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x804D90E4: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x804D90E8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x804D90EC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x804D90F0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x804D90F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804D90F8:
    // 0x804D90F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804D90FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804D9100: jr          $ra
    // 0x804D9104: nop

    return;
    // 0x804D9104: nop

;}
RECOMP_FUNC void func_8046DCA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046DCA0: lui         $v0, 0x8047
    ctx->r2 = S32(RELOC_HI16(146, 0X1E2C) << 16);
    // 0x8046DCA4: jr          $ra
    // 0x8046DCA8: addiu       $v0, $v0, -0x534
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(146, 0X1E2C));
    return;
    // 0x8046DCA8: addiu       $v0, $v0, -0x534
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(146, 0X1E2C));
;}
RECOMP_FUNC void func_80057F24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057F24: lh          $v1, 0x6($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X6);
    // 0x80057F28: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80057F2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80057F30: beq         $v1, $zero, L_80057F6C
    if (ctx->r3 == 0) {
        // 0x80057F34: nop
    
            goto L_80057F6C;
    }
    // 0x80057F34: nop

L_80057F38:
    // 0x80057F38: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80057F3C: beq         $a1, $zero, L_80057F64
    if (ctx->r5 == 0) {
        // 0x80057F40: nop
    
            goto L_80057F64;
    }
    // 0x80057F40: nop

    // 0x80057F44: bne         $a2, $a1, L_80057F5C
    if (ctx->r6 != ctx->r5) {
        // 0x80057F48: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_80057F5C;
    }
    // 0x80057F48: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80057F4C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80057F50: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80057F54: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80057F58: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
L_80057F5C:
    // 0x80057F5C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80057F60: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80057F64:
    // 0x80057F64: bne         $v1, $zero, L_80057F38
    if (ctx->r3 != 0) {
        // 0x80057F68: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80057F38;
    }
    // 0x80057F68: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80057F6C:
    // 0x80057F6C: jr          $ra
    // 0x80057F70: nop

    return;
    // 0x80057F70: nop

;}
RECOMP_FUNC void func_80427994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80427998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042799C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804279A0: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x804279A4: jal         0x80067BBC
    // 0x804279A8: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x804279A8: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x804279AC: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    // 0x804279B0: jal         0x80067818
    // 0x804279B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x804279B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x804279B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804279BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804279C0: jr          $ra
    // 0x804279C4: nop

    return;
    // 0x804279C4: nop

;}
RECOMP_FUNC void func_806FA8F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FA8F8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x806FA8FC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x806FA900: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x806FA904: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x806FA908: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x806FA90C: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x806FA910: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x806FA914: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x806FA918: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x806FA91C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x806FA920: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x806FA924: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x806FA928: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x806FA92C: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x806FA930: lw          $s3, 0x1F4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FA934: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(700, 0X2600) << 16);
    // 0x806FA938: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806FA93C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x806FA940: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x806FA944: lwc1        $f30, -0x3DD0($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(700, 0X2600));
    // 0x806FA948: addiu       $a1, $zero, 0x14D0
    ctx->r5 = ADD32(0, 0X14D0);
    // 0x806FA94C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806FA950: addiu       $s0, $s3, 0xA0
    ctx->r16 = ADD32(ctx->r19, 0XA0);
    // 0x806FA954: jal         0x80065728
    // 0x806FA958: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x806FA958: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x806FA95C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x806FA960: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x806FA964: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806FA968: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806FA96C: lui         $v0, 0x8070
    ctx->r2 = S32(RELOC_HI16(700, 0X27C0) << 16);
    // 0x806FA970: addiu       $v0, $v0, -0x3C10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X27C0));
    // 0x806FA974: sw          $zero, 0x14BC($s3)
    MEM_W(0X14BC, ctx->r19) = 0;
    // 0x806FA978: sw          $zero, 0x14C4($s3)
    MEM_W(0X14C4, ctx->r19) = 0;
    // 0x806FA97C: swc1        $f4, 0x14AC($s3)
    MEM_W(0X14AC, ctx->r19) = ctx->f4.u32l;
    // 0x806FA980: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x806FA984: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x806FA988: lui         $t0, 0x8070
    ctx->r8 = S32(RELOC_HI16(700, 0X2754) << 16);
    // 0x806FA98C: sll         $t9, $s1, 3
    ctx->r25 = S32(ctx->r17 << 3);
    // 0x806FA990: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x806FA994: sw          $t8, 0x14CC($s3)
    MEM_W(0X14CC, ctx->r19) = ctx->r24;
    // 0x806FA998: lw          $t0, -0x3C7C($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(700, 0X2754));
    // 0x806FA99C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806FA9A0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x806FA9A4: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x806FA9A8: swc1        $f20, 0x14A4($s3)
    MEM_W(0X14A4, ctx->r19) = ctx->f20.u32l;
    // 0x806FA9AC: sw          $t0, 0x14C8($s3)
    MEM_W(0X14C8, ctx->r19) = ctx->r8;
    // 0x806FA9B0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x806FA9B4: lwc1        $f22, 0x3C($s4)
    ctx->f22.u32l = MEM_W(ctx->r20, 0X3C);
    // 0x806FA9B8: lwc1        $f24, 0x40($s4)
    ctx->f24.u32l = MEM_W(ctx->r20, 0X40);
    // 0x806FA9BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x806FA9C0: addiu       $s2, $zero, 0x280
    ctx->r18 = ADD32(0, 0X280);
L_806FA9C4:
    // 0x806FA9C4: swc1        $f22, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f22.u32l;
    // 0x806FA9C8: swc1        $f24, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f24.u32l;
    // 0x806FA9CC: jal         0x80066E88
    // 0x806FA9D0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x806FA9D0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x806FA9D4: mul.s       $f6, $f0, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x806FA9D8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x806FA9DC: jal         0x80066DE4
    // 0x806FA9E0: sub.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f6.fl;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x806FA9E0: sub.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f6.fl;
    after_2:
    // 0x806FA9E4: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x806FA9E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x806FA9EC: sub.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x806FA9F0: bc1f        L_806FA9FC
    if (!c1cs) {
        // 0x806FA9F4: nop
    
            goto L_806FA9FC;
    }
    // 0x806FA9F4: nop

    // 0x806FA9F8: add.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
L_806FA9FC:
    // 0x806FA9FC: bne         $s1, $s2, L_806FA9C4
    if (ctx->r17 != ctx->r18) {
        // 0x806FAA00: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_806FA9C4;
    }
    // 0x806FAA00: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x806FAA04: lw          $a2, 0x3C($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X3C);
    // 0x806FAA08: lw          $a3, 0x40($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X40);
    // 0x806FAA0C: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    // 0x806FAA10: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x806FAA14: jal         0x806FA738
    // 0x806FAA18: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_806FA738(rdram, ctx);
        goto after_3;
    // 0x806FAA18: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x806FAA1C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x806FAA20: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x806FAA24: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x806FAA28: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x806FAA2C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x806FAA30: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x806FAA34: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x806FAA38: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x806FAA3C: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x806FAA40: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x806FAA44: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x806FAA48: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x806FAA4C: jr          $ra
    // 0x806FAA50: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x806FAA50: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_807BA9E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BA9E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BA9EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BA9F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x807BA9F4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x807BA9F8: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x807BA9FC: jal         0x80067BBC
    // 0x807BAA00: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x807BAA00: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x807BAA04: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x807BAA08: jal         0x80067818
    // 0x807BAA0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x807BAA0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x807BAA10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BAA14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BAA18: jr          $ra
    // 0x807BAA1C: nop

    return;
    // 0x807BAA1C: nop

;}
RECOMP_FUNC void func_806B195C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B195C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x806B1960: beql        $at, $zero, L_806B1974
    if (ctx->r1 == 0) {
        // 0x806B1964: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_806B1974;
    }
    goto skip_0;
    // 0x806B1964: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x806B1968: jr          $ra
    // 0x806B196C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    return;
    // 0x806B196C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x806B1970: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_806B1974:
    // 0x806B1974: beq         $at, $zero, L_806B19B0
    if (ctx->r1 == 0) {
        // 0x806B1978: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_806B19B0;
    }
    // 0x806B1978: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x806B197C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x806B1980: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B1984: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806B1988: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x806B198C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806B1990: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x806B1994: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x806B1998: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x806B199C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806B19A0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x806B19A4: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x806B19A8: jr          $ra
    // 0x806B19AC: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    return;
    // 0x806B19AC: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
L_806B19B0:
    // 0x806B19B0: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x806B19B4: beq         $at, $zero, L_806B19CC
    if (ctx->r1 == 0) {
        // 0x806B19B8: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_806B19CC;
    }
    // 0x806B19B8: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x806B19BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B19C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806B19C4: jr          $ra
    // 0x806B19C8: nop

    return;
    // 0x806B19C8: nop

L_806B19CC:
    // 0x806B19CC: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x806B19D0: beq         $at, $zero, L_806B1A10
    if (ctx->r1 == 0) {
        // 0x806B19D4: lwc1        $f0, 0x18($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
            goto L_806B1A10;
    }
    // 0x806B19D4: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x806B19D8: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x806B19DC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x806B19E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B19E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806B19E8: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x806B19EC: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806B19F0: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x806B19F4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x806B19F8: sub.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x806B19FC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806B1A00: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806B1A04: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x806B1A08: jr          $ra
    // 0x806B1A0C: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    return;
    // 0x806B1A0C: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
L_806B1A10:
    // 0x806B1A10: jr          $ra
    // 0x806B1A14: nop

    return;
    // 0x806B1A14: nop

;}
RECOMP_FUNC void func_80536A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536A98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80536A9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80536AA0: jal         0x805367A4
    // 0x80536AA4: nop

    func_805367A4(rdram, ctx);
        goto after_0;
    // 0x80536AA4: nop

    after_0:
    // 0x80536AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80536AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80536AB0: jr          $ra
    // 0x80536AB4: nop

    return;
    // 0x80536AB4: nop

    // 0x80536AB8: nop

    // 0x80536ABC: nop

;}
RECOMP_FUNC void func_8057F810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F810: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057F814: lwc1        $f4, 0x4C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x8057F818: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8057F81C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8057F820: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8057F824: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8057F828: swc1        $f8, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f8.u32l;
    // 0x8057F82C: lwc1        $f0, 0x4C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x8057F830: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8057F834: nop

    // 0x8057F838: bc1fl       L_8057F850
    if (!c1cs) {
        // 0x8057F83C: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8057F850;
    }
    goto skip_0;
    // 0x8057F83C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_0:
    // 0x8057F840: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8057F844: b           L_8057F86C
    // 0x8057F848: swc1        $f10, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f10.u32l;
        goto L_8057F86C;
    // 0x8057F848: swc1        $f10, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f10.u32l;
    // 0x8057F84C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8057F850:
    // 0x8057F850: nop

    // 0x8057F854: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8057F858: nop

    // 0x8057F85C: bc1fl       L_8057F870
    if (!c1cs) {
        // 0x8057F860: lwc1        $f4, 0x50($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
            goto L_8057F870;
    }
    goto skip_1;
    // 0x8057F860: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    skip_1:
    // 0x8057F864: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8057F868: swc1        $f18, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f18.u32l;
L_8057F86C:
    // 0x8057F86C: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
L_8057F870:
    // 0x8057F870: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8057F874: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8057F878: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x8057F87C: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8057F880: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8057F884: nop

    // 0x8057F888: bc1fl       L_8057F8A0
    if (!c1cs) {
        // 0x8057F88C: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8057F8A0;
    }
    goto skip_2;
    // 0x8057F88C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_2:
    // 0x8057F890: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8057F894: jr          $ra
    // 0x8057F898: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x8057F898: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x8057F89C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8057F8A0:
    // 0x8057F8A0: nop

    // 0x8057F8A4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8057F8A8: nop

    // 0x8057F8AC: bc1f        L_8057F8BC
    if (!c1cs) {
        // 0x8057F8B0: nop
    
            goto L_8057F8BC;
    }
    // 0x8057F8B0: nop

    // 0x8057F8B4: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8057F8B8: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
L_8057F8BC:
    // 0x8057F8BC: jr          $ra
    // 0x8057F8C0: nop

    return;
    // 0x8057F8C0: nop

;}
RECOMP_FUNC void func_80466B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80466B28: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80466B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80466B30: lw          $t2, 0x1F4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X1F4);
    // 0x80466B34: lh          $t6, 0x1A($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X1A);
    // 0x80466B38: lh          $t7, 0x18($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X18);
    // 0x80466B3C: lw          $t9, 0x1F9C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X1F9C);
    // 0x80466B40: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80466B44: mflo        $t8
    ctx->r24 = lo;
    // 0x80466B48: nop

    // 0x80466B4C: nop

    // 0x80466B50: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80466B54: mflo        $t6
    ctx->r14 = lo;
    // 0x80466B58: addu        $v0, $t6, $t2
    ctx->r2 = ADD32(ctx->r14, ctx->r10);
    // 0x80466B5C: addiu       $t7, $v0, 0x1C
    ctx->r15 = ADD32(ctx->r2, 0X1C);
    // 0x80466B60: addiu       $t8, $v0, 0xFDC
    ctx->r24 = ADD32(ctx->r2, 0XFDC);
    // 0x80466B64: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x80466B68: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    // 0x80466B6C: lw          $t3, 0x2CF8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2CF8);
    // 0x80466B70: negu        $t3, $t3
    ctx->r11 = SUB32(0, ctx->r11);
    // 0x80466B74: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80466B78: addiu       $t3, $t3, 0x100
    ctx->r11 = ADD32(ctx->r11, 0X100);
    // 0x80466B7C: slti        $at, $t3, 0x100
    ctx->r1 = SIGNED(ctx->r11) < 0X100 ? 1 : 0;
    // 0x80466B80: bne         $at, $zero, L_80466B8C
    if (ctx->r1 != 0) {
        // 0x80466B84: nop
    
            goto L_80466B8C;
    }
    // 0x80466B84: nop

    // 0x80466B88: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_80466B8C:
    // 0x80466B8C: bgezl       $t3, L_80466B9C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80466B90: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80466B9C;
    }
    goto skip_0;
    // 0x80466B90: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80466B94: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80466B98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80466B9C:
    // 0x80466B9C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80466BA0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80466BA4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80466BA8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80466BAC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80466BB0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80466BB4: lw          $t8, 0x10($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X10);
    // 0x80466BB8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80466BBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80466BC0: lw          $t9, 0x168($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X168);
    // 0x80466BC4: lw          $a3, 0x88($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X88);
    // 0x80466BC8: sw          $t3, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r11;
    // 0x80466BCC: sw          $t2, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r10;
    // 0x80466BD0: jal         0x8007711C
    // 0x80466BD4: sw          $a0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r4;
    func_8007711C(rdram, ctx);
        goto after_0;
    // 0x80466BD4: sw          $a0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r4;
    after_0:
    // 0x80466BD8: lw          $a0, 0xF0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF0);
    // 0x80466BDC: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x80466BE0: lw          $t3, 0xDC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XDC);
    // 0x80466BE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466BE8: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80466BEC: ori         $t7, $t7, 0x207F
    ctx->r15 = ctx->r15 | 0X207F;
    // 0x80466BF0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80466BF4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80466BF8: addiu       $t1, $t2, 0x2D00
    ctx->r9 = ADD32(ctx->r10, 0X2D00);
    // 0x80466BFC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80466C00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80466C04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466C08: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x80466C0C: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x80466C10: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80466C14: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80466C18: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80466C1C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80466C20: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x80466C24: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x80466C28: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80466C2C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80466C30: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x80466C34: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80466C38: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x80466C3C: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80466C40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466C44: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80466C48: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80466C4C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80466C50: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80466C54: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80466C58: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80466C5C: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80466C60: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80466C64: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80466C68: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80466C6C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80466C70: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x80466C74: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80466C78: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80466C7C: lh          $t6, 0x1A($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X1A);
    // 0x80466C80: lh          $a3, 0x18($t2)
    ctx->r7 = MEM_H(ctx->r10, 0X18);
    // 0x80466C84: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80466C88: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80466C8C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80466C90: multu       $t8, $a3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80466C94: mflo        $v1
    ctx->r3 = lo;
    // 0x80466C98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80466C9C: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80466CA0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80466CA4: slti        $at, $v1, 0x7FF
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF ? 1 : 0;
    // 0x80466CA8: beql        $at, $zero, L_80466CBC
    if (ctx->r1 == 0) {
        // 0x80466CAC: addiu       $t1, $zero, 0x7FF
        ctx->r9 = ADD32(0, 0X7FF);
            goto L_80466CBC;
    }
    goto skip_1;
    // 0x80466CAC: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    skip_1:
    // 0x80466CB0: b           L_80466CBC
    // 0x80466CB4: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
        goto L_80466CBC;
    // 0x80466CB4: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80466CB8: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
L_80466CBC:
    // 0x80466CBC: bgez        $a3, L_80466CCC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80466CC0: sra         $v0, $a3, 3
        ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
            goto L_80466CCC;
    }
    // 0x80466CC0: sra         $v0, $a3, 3
    ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
    // 0x80466CC4: addiu       $at, $a3, 0x7
    ctx->r1 = ADD32(ctx->r7, 0X7);
    // 0x80466CC8: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_80466CCC:
    // 0x80466CCC: bgtzl       $v0, L_80466CE0
    if (SIGNED(ctx->r2) > 0) {
        // 0x80466CD0: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80466CE0;
    }
    goto skip_2;
    // 0x80466CD0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    skip_2:
    // 0x80466CD4: b           L_80466CE0
    // 0x80466CD8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80466CE0;
    // 0x80466CD8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80466CDC: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_80466CE0:
    // 0x80466CE0: bgtz        $v0, L_80466CF0
    if (SIGNED(ctx->r2) > 0) {
        // 0x80466CE4: addiu       $t9, $t0, 0x7FF
        ctx->r25 = ADD32(ctx->r8, 0X7FF);
            goto L_80466CF0;
    }
    // 0x80466CE4: addiu       $t9, $t0, 0x7FF
    ctx->r25 = ADD32(ctx->r8, 0X7FF);
    // 0x80466CE8: b           L_80466CF4
    // 0x80466CEC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80466CF4;
    // 0x80466CEC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80466CF0:
    // 0x80466CF0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80466CF4:
    // 0x80466CF4: div         $zero, $t9, $v1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r3)));
    // 0x80466CF8: bne         $v1, $zero, L_80466D04
    if (ctx->r3 != 0) {
        // 0x80466CFC: nop
    
            goto L_80466D04;
    }
    // 0x80466CFC: nop

    // 0x80466D00: break       7
    do_break(2152099072);
L_80466D04:
    // 0x80466D04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80466D08: bne         $v1, $at, L_80466D1C
    if (ctx->r3 != ctx->r1) {
        // 0x80466D0C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80466D1C;
    }
    // 0x80466D0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80466D10: bne         $t9, $at, L_80466D1C
    if (ctx->r25 != ctx->r1) {
        // 0x80466D14: nop
    
            goto L_80466D1C;
    }
    // 0x80466D14: nop

    // 0x80466D18: break       6
    do_break(2152099096);
L_80466D1C:
    // 0x80466D1C: mflo        $t6
    ctx->r14 = lo;
    // 0x80466D20: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80466D24: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80466D28: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x80466D2C: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80466D30: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80466D34: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80466D38: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80466D3C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466D40: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80466D44: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80466D48: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80466D4C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80466D50: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80466D54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80466D58: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466D5C: lui         $ra, 0xBF00
    ctx->r31 = S32(0XBF00 << 16);
    // 0x80466D60: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x80466D64: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80466D68: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80466D6C: lh          $t7, 0x18($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X18);
    // 0x80466D70: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80466D74: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x80466D78: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80466D7C: andi        $t6, $t8, 0x1FF
    ctx->r14 = ctx->r24 & 0X1FF;
    // 0x80466D80: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x80466D84: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80466D88: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80466D8C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466D90: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80466D94: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80466D98: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80466D9C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80466DA0: lh          $t7, 0x1A($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X1A);
    // 0x80466DA4: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80466DA8: lh          $t7, 0x18($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X18);
    // 0x80466DAC: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80466DB0: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80466DB4: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80466DB8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80466DBC: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80466DC0: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80466DC4: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80466DC8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80466DCC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466DD0: addiu       $t6, $zero, 0x204
    ctx->r14 = ADD32(0, 0X204);
    // 0x80466DD4: addiu       $t8, $zero, 0x406
    ctx->r24 = ADD32(0, 0X406);
    // 0x80466DD8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80466DDC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80466DE0: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80466DE4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80466DE8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466DEC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80466DF0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80466DF4: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80466DF8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80466DFC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466E00: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x80466E04: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80466E08: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80466E0C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80466E10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80466E14: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466E18: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80466E1C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80466E20: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80466E24: lh          $t8, 0x1A($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X1A);
    // 0x80466E28: lh          $t9, 0x18($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X18);
    // 0x80466E2C: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80466E30: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x80466E34: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80466E38: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x80466E3C: mflo        $t8
    ctx->r24 = lo;
    // 0x80466E40: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80466E44: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80466E48: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466E4C: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80466E50: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x80466E54: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80466E58: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80466E5C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80466E60: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80466E64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80466E68: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466E6C: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x80466E70: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80466E74: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80466E78: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80466E7C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80466E80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80466E84: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466E88: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80466E8C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80466E90: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80466E94: lh          $t7, 0x1A($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X1A);
    // 0x80466E98: lh          $a3, 0x18($t2)
    ctx->r7 = MEM_H(ctx->r10, 0X18);
    // 0x80466E9C: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x80466EA0: sra         $t6, $t7, 1
    ctx->r14 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80466EA4: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80466EA8: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80466EAC: mflo        $v1
    ctx->r3 = lo;
    // 0x80466EB0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80466EB4: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80466EB8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80466EBC: slti        $at, $v1, 0x7FF
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF ? 1 : 0;
    // 0x80466EC0: beq         $at, $zero, L_80466ED0
    if (ctx->r1 == 0) {
        // 0x80466EC4: nop
    
            goto L_80466ED0;
    }
    // 0x80466EC4: nop

    // 0x80466EC8: b           L_80466ED0
    // 0x80466ECC: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
        goto L_80466ED0;
    // 0x80466ECC: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
L_80466ED0:
    // 0x80466ED0: bgez        $a3, L_80466EE0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80466ED4: sra         $v0, $a3, 3
        ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
            goto L_80466EE0;
    }
    // 0x80466ED4: sra         $v0, $a3, 3
    ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
    // 0x80466ED8: addiu       $at, $a3, 0x7
    ctx->r1 = ADD32(ctx->r7, 0X7);
    // 0x80466EDC: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_80466EE0:
    // 0x80466EE0: bgtz        $v0, L_80466EF0
    if (SIGNED(ctx->r2) > 0) {
        // 0x80466EE4: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80466EF0;
    }
    // 0x80466EE4: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80466EE8: b           L_80466EF0
    // 0x80466EEC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80466EF0;
    // 0x80466EEC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80466EF0:
    // 0x80466EF0: bgtz        $v0, L_80466F00
    if (SIGNED(ctx->r2) > 0) {
        // 0x80466EF4: addiu       $t8, $t0, 0x7FF
        ctx->r24 = ADD32(ctx->r8, 0X7FF);
            goto L_80466F00;
    }
    // 0x80466EF4: addiu       $t8, $t0, 0x7FF
    ctx->r24 = ADD32(ctx->r8, 0X7FF);
    // 0x80466EF8: b           L_80466F04
    // 0x80466EFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80466F04;
    // 0x80466EFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80466F00:
    // 0x80466F00: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80466F04:
    // 0x80466F04: div         $zero, $t8, $v1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r3)));
    // 0x80466F08: bne         $v1, $zero, L_80466F14
    if (ctx->r3 != 0) {
        // 0x80466F0C: nop
    
            goto L_80466F14;
    }
    // 0x80466F0C: nop

    // 0x80466F10: break       7
    do_break(2152099600);
L_80466F14:
    // 0x80466F14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80466F18: bne         $v1, $at, L_80466F2C
    if (ctx->r3 != ctx->r1) {
        // 0x80466F1C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80466F2C;
    }
    // 0x80466F1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80466F20: bne         $t8, $at, L_80466F2C
    if (ctx->r24 != ctx->r1) {
        // 0x80466F24: nop
    
            goto L_80466F2C;
    }
    // 0x80466F24: nop

    // 0x80466F28: break       6
    do_break(2152099624);
L_80466F2C:
    // 0x80466F2C: mflo        $t7
    ctx->r15 = lo;
    // 0x80466F30: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80466F34: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80466F38: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x80466F3C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80466F40: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80466F44: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80466F48: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80466F4C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466F50: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80466F54: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80466F58: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80466F5C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80466F60: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80466F64: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80466F68: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466F6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80466F70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80466F74: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80466F78: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80466F7C: lh          $t6, 0x18($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X18);
    // 0x80466F80: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80466F84: addiu       $t8, $t6, 0x7
    ctx->r24 = ADD32(ctx->r14, 0X7);
    // 0x80466F88: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80466F8C: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x80466F90: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x80466F94: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80466F98: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80466F9C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466FA0: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x80466FA4: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80466FA8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80466FAC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80466FB0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80466FB4: lh          $t6, 0x1A($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X1A);
    // 0x80466FB8: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80466FBC: lh          $t6, 0x18($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X18);
    // 0x80466FC0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80466FC4: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80466FC8: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x80466FCC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80466FD0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80466FD4: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80466FD8: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80466FDC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80466FE0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466FE4: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x80466FE8: ori         $t7, $t7, 0xA0C
    ctx->r15 = ctx->r15 | 0XA0C;
    // 0x80466FEC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80466FF0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80466FF4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80466FF8: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80466FFC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80467000: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80467004: ori         $t9, $t9, 0xC0E
    ctx->r25 = ctx->r25 | 0XC0E;
    // 0x80467008: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8046700C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80467010: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80467014: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80467018: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8046701C: or          $t8, $t3, $zero
    ctx->r24 = ctx->r11 | 0;
    // 0x80467020: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80467024: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80467028: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8046702C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80467030: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80467034: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80467038: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8046703C: lw          $t7, 0xC($t2)
    ctx->r15 = MEM_W(ctx->r10, 0XC);
    // 0x80467040: lw          $t8, 0x168($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X168);
    // 0x80467044: lw          $a3, 0x88($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X88);
    // 0x80467048: sw          $t2, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r10;
    // 0x8046704C: jal         0x8007711C
    // 0x80467050: sw          $a0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r4;
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x80467050: sw          $a0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r4;
    after_1:
    // 0x80467054: lw          $a0, 0xF0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF0);
    // 0x80467058: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x8046705C: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x80467060: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80467064: ori         $t6, $t6, 0x207F
    ctx->r14 = ctx->r14 | 0X207F;
    // 0x80467068: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x8046706C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80467070: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80467074: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80467078: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8046707C: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x80467080: lui         $ra, 0xBF00
    ctx->r31 = S32(0XBF00 << 16);
    // 0x80467084: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80467088: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8046708C: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x80467090: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80467094: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80467098: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8046709C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x804670A0: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x804670A4: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x804670A8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804670AC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x804670B0: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x804670B4: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x804670B8: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x804670BC: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x804670C0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804670C4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x804670C8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x804670CC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x804670D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x804670D4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x804670D8: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x804670DC: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x804670E0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x804670E4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x804670E8: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x804670EC: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x804670F0: addiu       $t8, $t3, 0x8
    ctx->r24 = ADD32(ctx->r11, 0X8);
    // 0x804670F4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x804670F8: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x804670FC: lh          $t6, 0x1A($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X1A);
    // 0x80467100: lh          $a3, 0x18($t2)
    ctx->r7 = MEM_H(ctx->r10, 0X18);
    // 0x80467104: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80467108: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8046710C: multu       $t8, $a3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467110: mflo        $v1
    ctx->r3 = lo;
    // 0x80467114: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80467118: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8046711C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80467120: slti        $at, $v1, 0x7FF
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF ? 1 : 0;
    // 0x80467124: beq         $at, $zero, L_80467134
    if (ctx->r1 == 0) {
        // 0x80467128: nop
    
            goto L_80467134;
    }
    // 0x80467128: nop

    // 0x8046712C: b           L_80467134
    // 0x80467130: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
        goto L_80467134;
    // 0x80467130: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
L_80467134:
    // 0x80467134: bgez        $a3, L_80467144
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80467138: sra         $v0, $a3, 3
        ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
            goto L_80467144;
    }
    // 0x80467138: sra         $v0, $a3, 3
    ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
    // 0x8046713C: addiu       $at, $a3, 0x7
    ctx->r1 = ADD32(ctx->r7, 0X7);
    // 0x80467140: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_80467144:
    // 0x80467144: bgtz        $v0, L_80467154
    if (SIGNED(ctx->r2) > 0) {
        // 0x80467148: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80467154;
    }
    // 0x80467148: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8046714C: b           L_80467154
    // 0x80467150: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80467154;
    // 0x80467150: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80467154:
    // 0x80467154: bgtz        $v0, L_80467164
    if (SIGNED(ctx->r2) > 0) {
        // 0x80467158: addiu       $t9, $t0, 0x7FF
        ctx->r25 = ADD32(ctx->r8, 0X7FF);
            goto L_80467164;
    }
    // 0x80467158: addiu       $t9, $t0, 0x7FF
    ctx->r25 = ADD32(ctx->r8, 0X7FF);
    // 0x8046715C: b           L_80467168
    // 0x80467160: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80467168;
    // 0x80467160: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80467164:
    // 0x80467164: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80467168:
    // 0x80467168: div         $zero, $t9, $v1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r3)));
    // 0x8046716C: bne         $v1, $zero, L_80467178
    if (ctx->r3 != 0) {
        // 0x80467170: nop
    
            goto L_80467178;
    }
    // 0x80467170: nop

    // 0x80467174: break       7
    do_break(2152100212);
L_80467178:
    // 0x80467178: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8046717C: bne         $v1, $at, L_80467190
    if (ctx->r3 != ctx->r1) {
        // 0x80467180: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80467190;
    }
    // 0x80467180: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80467184: bne         $t9, $at, L_80467190
    if (ctx->r25 != ctx->r1) {
        // 0x80467188: nop
    
            goto L_80467190;
    }
    // 0x80467188: nop

    // 0x8046718C: break       6
    do_break(2152100236);
L_80467190:
    // 0x80467190: mflo        $t6
    ctx->r14 = lo;
    // 0x80467194: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80467198: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8046719C: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x804671A0: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x804671A4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x804671A8: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x804671AC: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x804671B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804671B4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x804671B8: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x804671BC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x804671C0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804671C4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x804671C8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804671CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804671D0: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x804671D4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x804671D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804671DC: lh          $t7, 0x18($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X18);
    // 0x804671E0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804671E4: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x804671E8: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x804671EC: andi        $t6, $t8, 0x1FF
    ctx->r14 = ctx->r24 & 0X1FF;
    // 0x804671F0: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x804671F4: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x804671F8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x804671FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80467200: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80467204: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80467208: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8046720C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80467210: lh          $t7, 0x1A($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X1A);
    // 0x80467214: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80467218: lh          $t7, 0x18($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X18);
    // 0x8046721C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80467220: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80467224: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80467228: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8046722C: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80467230: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80467234: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80467238: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8046723C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80467240: addiu       $t6, $zero, 0x204
    ctx->r14 = ADD32(0, 0X204);
    // 0x80467244: addiu       $t8, $zero, 0x406
    ctx->r24 = ADD32(0, 0X406);
    // 0x80467248: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8046724C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80467250: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80467254: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80467258: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8046725C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80467260: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80467264: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80467268: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8046726C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80467270: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x80467274: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80467278: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8046727C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80467280: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80467284: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80467288: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8046728C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80467290: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80467294: lh          $t8, 0x1A($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X1A);
    // 0x80467298: lh          $t9, 0x18($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X18);
    // 0x8046729C: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x804672A0: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x804672A4: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804672A8: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x804672AC: mflo        $t8
    ctx->r24 = lo;
    // 0x804672B0: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x804672B4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x804672B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804672BC: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x804672C0: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x804672C4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x804672C8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804672CC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x804672D0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x804672D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804672D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804672DC: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x804672E0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x804672E4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804672E8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x804672EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804672F0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x804672F4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804672F8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x804672FC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80467300: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80467304: lh          $t7, 0x1A($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X1A);
    // 0x80467308: lh          $a3, 0x18($t2)
    ctx->r7 = MEM_H(ctx->r10, 0X18);
    // 0x8046730C: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80467310: sra         $t6, $t7, 1
    ctx->r14 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80467314: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80467318: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046731C: mflo        $v1
    ctx->r3 = lo;
    // 0x80467320: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80467324: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80467328: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8046732C: slti        $at, $v1, 0x7FF
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF ? 1 : 0;
    // 0x80467330: beq         $at, $zero, L_80467340
    if (ctx->r1 == 0) {
        // 0x80467334: nop
    
            goto L_80467340;
    }
    // 0x80467334: nop

    // 0x80467338: b           L_80467340
    // 0x8046733C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
        goto L_80467340;
    // 0x8046733C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
L_80467340:
    // 0x80467340: bgez        $a3, L_80467350
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80467344: sra         $v0, $a3, 3
        ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
            goto L_80467350;
    }
    // 0x80467344: sra         $v0, $a3, 3
    ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
    // 0x80467348: addiu       $at, $a3, 0x7
    ctx->r1 = ADD32(ctx->r7, 0X7);
    // 0x8046734C: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_80467350:
    // 0x80467350: bgtz        $v0, L_80467360
    if (SIGNED(ctx->r2) > 0) {
        // 0x80467354: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80467360;
    }
    // 0x80467354: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80467358: b           L_80467360
    // 0x8046735C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80467360;
    // 0x8046735C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80467360:
    // 0x80467360: bgtz        $v0, L_80467370
    if (SIGNED(ctx->r2) > 0) {
        // 0x80467364: addiu       $t8, $t0, 0x7FF
        ctx->r24 = ADD32(ctx->r8, 0X7FF);
            goto L_80467370;
    }
    // 0x80467364: addiu       $t8, $t0, 0x7FF
    ctx->r24 = ADD32(ctx->r8, 0X7FF);
    // 0x80467368: b           L_80467374
    // 0x8046736C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80467374;
    // 0x8046736C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80467370:
    // 0x80467370: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80467374:
    // 0x80467374: div         $zero, $t8, $v1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r3)));
    // 0x80467378: bne         $v1, $zero, L_80467384
    if (ctx->r3 != 0) {
        // 0x8046737C: nop
    
            goto L_80467384;
    }
    // 0x8046737C: nop

    // 0x80467380: break       7
    do_break(2152100736);
L_80467384:
    // 0x80467384: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80467388: bne         $v1, $at, L_8046739C
    if (ctx->r3 != ctx->r1) {
        // 0x8046738C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8046739C;
    }
    // 0x8046738C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80467390: bne         $t8, $at, L_8046739C
    if (ctx->r24 != ctx->r1) {
        // 0x80467394: nop
    
            goto L_8046739C;
    }
    // 0x80467394: nop

    // 0x80467398: break       6
    do_break(2152100760);
L_8046739C:
    // 0x8046739C: mflo        $t7
    ctx->r15 = lo;
    // 0x804673A0: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x804673A4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x804673A8: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x804673AC: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x804673B0: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x804673B4: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x804673B8: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x804673BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804673C0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804673C4: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x804673C8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x804673CC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x804673D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804673D4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x804673D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804673DC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x804673E0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x804673E4: lh          $t6, 0x18($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X18);
    // 0x804673E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804673EC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x804673F0: addiu       $t8, $t6, 0x7
    ctx->r24 = ADD32(ctx->r14, 0X7);
    // 0x804673F4: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x804673F8: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x804673FC: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x80467400: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80467404: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80467408: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8046740C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x80467410: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80467414: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80467418: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8046741C: lh          $t6, 0x1A($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X1A);
    // 0x80467420: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80467424: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80467428: lh          $t6, 0x18($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X18);
    // 0x8046742C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80467430: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80467434: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x80467438: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8046743C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80467440: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80467444: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80467448: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8046744C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80467450: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x80467454: ori         $t7, $t7, 0xA0C
    ctx->r15 = ctx->r15 | 0XA0C;
    // 0x80467458: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8046745C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80467460: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80467464: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80467468: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8046746C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80467470: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80467474: ori         $t9, $t9, 0xC0E
    ctx->r25 = ctx->r25 | 0XC0E;
    // 0x80467478: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8046747C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80467480: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80467484: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80467488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046748C: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    // 0x80467490: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80467494: jr          $ra
    // 0x80467498: nop

    return;
    // 0x80467498: nop

;}
RECOMP_FUNC void func_80462A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462A58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80462A5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80462A60: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80462A64: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80462A68: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80462A6C: beql        $v0, $zero, L_80462AB0
    if (ctx->r2 == 0) {
        // 0x80462A70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80462AB0;
    }
    goto skip_0;
    // 0x80462A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80462A74: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80462A78: jal         0x80062684
    // 0x80462A7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x80462A7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80462A80: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80462A84: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x80462A88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80462A8C: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80462A90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80462A94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80462A98: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80462A9C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80462AA0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x80462AA4: jal         0x80463260
    // 0x80462AA8: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    func_80463260(rdram, ctx);
        goto after_1;
    // 0x80462AA8: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    after_1:
    // 0x80462AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80462AB0:
    // 0x80462AB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80462AB4: jr          $ra
    // 0x80462AB8: nop

    return;
    // 0x80462AB8: nop

;}
RECOMP_FUNC void func_8079EC04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079EC04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079EC08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079EC0C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8079EC10: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079EC14: jal         0x8079EB20
    // 0x8079EC18: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8079EB20(rdram, ctx);
        goto after_0;
    // 0x8079EC18: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8079EC1C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8079EC20: jal         0x8079E914
    // 0x8079EC24: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8079E914(rdram, ctx);
        goto after_1;
    // 0x8079EC24: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8079EC28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079EC2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079EC30: jr          $ra
    // 0x8079EC34: nop

    return;
    // 0x8079EC34: nop

;}
RECOMP_FUNC void func_8001DC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DC5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001DC60: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x8001DC64: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x8001DC68: lbu         $v1, 0xB14($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB14);
    // 0x8001DC6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001DC70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DC74: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8001DC78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001DC7C: beq         $a2, $v1, L_8001DCBC
    if (ctx->r6 == ctx->r3) {
        // 0x8001DC80: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_8001DCBC;
    }
    // 0x8001DC80: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8001DC84: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8001DC88: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001DC8C: sb          $a2, 0xB14($t0)
    MEM_B(0XB14, ctx->r8) = ctx->r6;
    // 0x8001DC90: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001DC94: lwc1        $f4, -0x6720($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6720);
    // 0x8001DC98: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001DC9C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001DCA0: swc1        $f4, 0xEC($a1)
    MEM_W(0XEC, ctx->r5) = ctx->f4.u32l;
    // 0x8001DCA4: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8001DCA8: lwc1        $f6, -0x6718($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6718);
    // 0x8001DCAC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001DCB0: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x8001DCB4: b           L_8001DCDC
    // 0x8001DCB8: lbu         $v1, 0xB14($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB14);
        goto L_8001DCDC;
    // 0x8001DCB8: lbu         $v1, 0xB14($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB14);
L_8001DCBC:
    // 0x8001DCBC: beq         $a3, $zero, L_8001DCDC
    if (ctx->r7 == 0) {
        // 0x8001DCC0: sll         $t7, $a2, 2
        ctx->r15 = S32(ctx->r6 << 2);
            goto L_8001DCDC;
    }
    // 0x8001DCC0: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8001DCC4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001DCC8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8001DCCC: lwc1        $f16, -0x6720($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6720);
    // 0x8001DCD0: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8001DCD4: swc1        $f16, 0xEC($a1)
    MEM_W(0XEC, ctx->r5) = ctx->f16.u32l;
    // 0x8001DCD8: lbu         $v1, -0x764C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X764C);
L_8001DCDC:
    // 0x8001DCDC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8001DCE0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001DCE4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8001DCE8: lwc1        $f0, -0x68D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X68D8);
    // 0x8001DCEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001DCF0: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    // 0x8001DCF4: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x8001DCF8: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x8001DCFC: swc1        $f0, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f0.u32l;
    // 0x8001DD00: swc1        $f0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f0.u32l;
    // 0x8001DD04: swc1        $f0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f0.u32l;
    // 0x8001DD08: jal         0x8001D8A0
    // 0x8001DD0C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8001D8A0(rdram, ctx);
        goto after_0;
    // 0x8001DD0C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001DD10: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8001DD14: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    // 0x8001DD18: jal         0x80065490
    // 0x8001DD1C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x8001DD1C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x8001DD20: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8001DD24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001DD28: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8001DD2C: lw          $t2, 0x34($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34);
    // 0x8001DD30: lwc1        $f0, 0x10($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X10);
    // 0x8001DD34: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x8001DD38: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8001DD3C: jal         0x8001D8C0
    // 0x8001DD40: swc1        $f0, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f0.u32l;
    func_8001D8C0(rdram, ctx);
        goto after_2;
    // 0x8001DD40: swc1        $f0, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f0.u32l;
    after_2:
    // 0x8001DD44: jal         0x8001DBEC
    // 0x8001DD48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001DBEC(rdram, ctx);
        goto after_3;
    // 0x8001DD48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8001DD4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DD50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DD54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001DD58: jr          $ra
    // 0x8001DD5C: nop

    return;
    // 0x8001DD5C: nop

;}
RECOMP_FUNC void func_8079F7D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079F7D8: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8079F7DC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8079F7E0: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8079F7E4: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8079F7E8: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8079F7EC: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8079F7F0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8079F7F4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8079F7F8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8079F7FC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8079F800: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8079F804: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8079F808: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8079F80C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8079F810: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8079F814: lui         $t9, 0x807A
    ctx->r25 = S32(RELOC_HI16(838, 0X1618) << 16);
    // 0x8079F818: addiu       $t9, $t9, 0xC78
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(838, 0X1618));
    // 0x8079F81C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8079F820: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8079F824: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8079F828: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8079F82C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8079F830: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079F834: addiu       $t6, $sp, 0x9C
    ctx->r14 = ADD32(ctx->r29, 0X9C);
    // 0x8079F838: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8079F83C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8079F840: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8079F844: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8079F848: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x8079F84C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8079F850: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x8079F854: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8079F858: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x8079F85C: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8079F860: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x8079F864: lwc1        $f22, 0x6C($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8079F868: lwc1        $f24, 0x70($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8079F86C: lw          $s2, 0x14($v1)
    ctx->r18 = MEM_W(ctx->r3, 0X14);
    // 0x8079F870: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x8079F874: jal         0x80049018
    // 0x8079F878: sw          $v1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r3;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x8079F878: sw          $v1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r3;
    after_0:
    // 0x8079F87C: beq         $v0, $zero, L_8079F89C
    if (ctx->r2 == 0) {
        // 0x8079F880: lw          $v1, 0xB4($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XB4);
            goto L_8079F89C;
    }
    // 0x8079F880: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x8079F884: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8079F888: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8079F88C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8079F890: sw          $t3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r11;
    // 0x8079F894: b           L_8079F8B0
    // 0x8079F898: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
        goto L_8079F8B0;
    // 0x8079F898: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
L_8079F89C:
    // 0x8079F89C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8079F8A0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8079F8A4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8079F8A8: sw          $t4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r12;
    // 0x8079F8AC: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
L_8079F8B0:
    // 0x8079F8B0: lui         $s6, 0x807A
    ctx->r22 = S32(RELOC_HI16(838, 0XE6C) << 16);
    // 0x8079F8B4: addiu       $s6, $s6, 0x4CC
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(838, 0XE6C));
    // 0x8079F8B8: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8079F8BC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8079F8C0: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x8079F8C4: addiu       $s7, $sp, 0x88
    ctx->r23 = ADD32(ctx->r29, 0X88);
    // 0x8079F8C8: addiu       $s5, $sp, 0x6C
    ctx->r21 = ADD32(ctx->r29, 0X6C);
    // 0x8079F8CC: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_8079F8D0:
    // 0x8079F8D0: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8079F8D4: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x8079F8D8: lw          $s0, 0xC($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC);
    // 0x8079F8DC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8079F8E0: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x8079F8E4: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x8079F8E8: sll         $t0, $t6, 1
    ctx->r8 = S32(ctx->r14 << 1);
    // 0x8079F8EC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8079F8F0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8079F8F4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8079F8F8: addu        $t2, $s6, $t1
    ctx->r10 = ADD32(ctx->r22, ctx->r9);
    // 0x8079F8FC: addu        $t3, $t2, $s3
    ctx->r11 = ADD32(ctx->r10, ctx->r19);
    // 0x8079F900: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8079F904: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x8079F908: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8079F90C: sw          $t4, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r12;
    // 0x8079F910: lw          $t7, 0x8($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X8);
    // 0x8079F914: sw          $t7, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r15;
    // 0x8079F918: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8079F91C: sw          $t4, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r12;
    // 0x8079F920: lw          $t7, 0x10($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X10);
    // 0x8079F924: beq         $s0, $zero, L_8079FA38
    if (ctx->r16 == 0) {
        // 0x8079F928: sw          $t7, 0x10($s5)
        MEM_W(0X10, ctx->r21) = ctx->r15;
            goto L_8079FA38;
    }
    // 0x8079F928: sw          $t7, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->r15;
    // 0x8079F92C: lh          $t5, 0x6C($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6C);
    // 0x8079F930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079F934: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8079F938: nop

    // 0x8079F93C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8079F940: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8079F944: nop

    // 0x8079F948: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8079F94C: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x8079F950: lh          $t8, 0x6E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6E);
    // 0x8079F954: addiu       $t9, $t8, 0x12
    ctx->r25 = ADD32(ctx->r24, 0X12);
    // 0x8079F958: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8079F95C: nop

    // 0x8079F960: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8079F964: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x8079F968: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x8079F96C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8079F970: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8079F974: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    // 0x8079F978: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8079F97C: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8079F980: swc1        $f16, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f16.u32l;
    // 0x8079F984: lh          $t6, 0x78($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X78);
    // 0x8079F988: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8079F98C: nop

    // 0x8079F990: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8079F994: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8079F998: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x8079F99C: lh          $t0, 0x7C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X7C);
    // 0x8079F9A0: sh          $t0, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r8;
    // 0x8079F9A4: lbu         $t1, 0x7A($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X7A);
    // 0x8079F9A8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8079F9AC: addu        $t3, $s7, $t2
    ctx->r11 = ADD32(ctx->r23, ctx->r10);
    // 0x8079F9B0: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x8079F9B4: jal         0x8079F6A4
    // 0x8079F9B8: sw          $v1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r3;
    func_8079F6A4(rdram, ctx);
        goto after_1;
    // 0x8079F9B8: sw          $v1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r3;
    after_1:
    // 0x8079F9BC: lh          $v0, 0x144($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X144);
    // 0x8079F9C0: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x8079F9C4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8079F9C8: bne         $at, $zero, L_8079FA24
    if (ctx->r1 != 0) {
        // 0x8079F9CC: nop
    
            goto L_8079FA24;
    }
    // 0x8079F9CC: nop

    // 0x8079F9D0: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8079F9D4: sb          $s4, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r20;
    // 0x8079F9D8: swc1        $f8, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f8.u32l;
    // 0x8079F9DC: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8079F9E0: swc1        $f10, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f10.u32l;
    // 0x8079F9E4: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8079F9E8: swc1        $f16, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f16.u32l;
    // 0x8079F9EC: lwc1        $f18, 0x6C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8079F9F0: swc1        $f18, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->f18.u32l;
    // 0x8079F9F4: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8079F9F8: swc1        $f4, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->f4.u32l;
    // 0x8079F9FC: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8079FA00: swc1        $f6, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f6.u32l;
    // 0x8079FA04: lh          $t4, 0x144($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X144);
    // 0x8079FA08: addiu       $t7, $t4, 0x10
    ctx->r15 = ADD32(ctx->r12, 0X10);
    // 0x8079FA0C: sh          $t7, 0x144($s2)
    MEM_H(0X144, ctx->r18) = ctx->r15;
    // 0x8079FA10: lw          $t5, 0x12C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X12C);
    // 0x8079FA14: sw          $t5, 0x12C($s2)
    MEM_W(0X12C, ctx->r18) = ctx->r13;
    // 0x8079FA18: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x8079FA1C: b           L_8079FA38
    // 0x8079FA20: sw          $t8, 0x138($s2)
    MEM_W(0X138, ctx->r18) = ctx->r24;
        goto L_8079FA38;
    // 0x8079FA20: sw          $t8, 0x138($s2)
    MEM_W(0X138, ctx->r18) = ctx->r24;
L_8079FA24:
    // 0x8079FA24: bnel        $fp, $v0, L_8079FA38
    if (ctx->r30 != ctx->r2) {
        // 0x8079FA28: sb          $zero, 0x165($s0)
        MEM_B(0X165, ctx->r16) = 0;
            goto L_8079FA38;
    }
    goto skip_0;
    // 0x8079FA28: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    skip_0:
    // 0x8079FA2C: b           L_8079FA38
    // 0x8079FA30: sb          $s4, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r20;
        goto L_8079FA38;
    // 0x8079FA30: sb          $s4, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r20;
    // 0x8079FA34: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
L_8079FA38:
    // 0x8079FA38: addiu       $s3, $s3, 0x14
    ctx->r19 = ADD32(ctx->r19, 0X14);
    // 0x8079FA3C: slti        $at, $s3, 0x28
    ctx->r1 = SIGNED(ctx->r19) < 0X28 ? 1 : 0;
    // 0x8079FA40: bne         $at, $zero, L_8079F8D0
    if (ctx->r1 != 0) {
        // 0x8079FA44: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8079F8D0;
    }
    // 0x8079FA44: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8079FA48: lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB8);
    // 0x8079FA4C: andi        $t9, $zero, 0xFF
    ctx->r25 = 0 & 0XFF;
    // 0x8079FA50: bne         $t9, $zero, L_8079FA8C
    if (ctx->r25 != 0) {
        // 0x8079FA54: sb          $zero, 0x10($v0)
        MEM_B(0X10, ctx->r2) = 0;
            goto L_8079FA8C;
    }
    // 0x8079FA54: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // 0x8079FA58: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8079FA5C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x8079FA60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8079FA64:
    // 0x8079FA64: lw          $s0, 0xC($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC);
    // 0x8079FA68: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8079FA6C: beq         $s0, $zero, L_8079FA78
    if (ctx->r16 == 0) {
        // 0x8079FA70: nop
    
            goto L_8079FA78;
    }
    // 0x8079FA70: nop

    // 0x8079FA74: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
L_8079FA78:
    // 0x8079FA78: bne         $v0, $v1, L_8079FA64
    if (ctx->r2 != ctx->r3) {
        // 0x8079FA7C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8079FA64;
    }
    // 0x8079FA7C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8079FA80: beql        $s2, $zero, L_8079FA90
    if (ctx->r18 == 0) {
        // 0x8079FA84: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8079FA90;
    }
    goto skip_1;
    // 0x8079FA84: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x8079FA88: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
L_8079FA8C:
    // 0x8079FA8C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8079FA90:
    // 0x8079FA90: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8079FA94: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8079FA98: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8079FA9C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8079FAA0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8079FAA4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8079FAA8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8079FAAC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8079FAB0: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8079FAB4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8079FAB8: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8079FABC: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8079FAC0: jr          $ra
    // 0x8079FAC4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8079FAC4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_8075FC4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075FC4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8075FC50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8075FC54: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x8075FC58: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8075FC5C: beq         $v1, $zero, L_8075FC70
    if (ctx->r3 == 0) {
        // 0x8075FC60: nop
    
            goto L_8075FC70;
    }
    // 0x8075FC60: nop

    // 0x8075FC64: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    // 0x8075FC68: lw          $t6, 0x21C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X21C);
    // 0x8075FC6C: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
L_8075FC70:
    // 0x8075FC70: jal         0x8075FB90
    // 0x8075FC74: nop

    func_8075FB90(rdram, ctx);
        goto after_0;
    // 0x8075FC74: nop

    after_0:
    // 0x8075FC78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8075FC7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8075FC80: jr          $ra
    // 0x8075FC84: nop

    return;
    // 0x8075FC84: nop

;}
RECOMP_FUNC void func_80676068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80676068: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8067606C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80676070: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80676074: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x80676078: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8067607C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80676080: beq         $v1, $zero, L_80676110
    if (ctx->r3 == 0) {
        // 0x80676084: nop
    
            goto L_80676110;
    }
    // 0x80676084: nop

    // 0x80676088: lw          $a1, 0x1F4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X1F4);
    // 0x8067608C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80676090: jal         0x80675C30
    // 0x80676094: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80675C30(rdram, ctx);
        goto after_0;
    // 0x80676094: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80676098: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8067609C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806760A0: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x806760A4: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    // 0x806760A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806760AC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x806760B0: blez        $v1, L_806760FC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x806760B4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_806760FC;
    }
    // 0x806760B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806760B8: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x806760BC: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x806760C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806760C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806760C8: lwc1        $f0, 0x3F8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X3F8);
    // 0x806760CC: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X25DC) << 16);
    // 0x806760D0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806760D4: nop

    // 0x806760D8: bc1f        L_806760EC
    if (!c1cs) {
        // 0x806760DC: nop
    
            goto L_806760EC;
    }
    // 0x806760DC: nop

    // 0x806760E0: lwc1        $f6, 0x7C9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X25DC));
    // 0x806760E4: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x806760E8: swc1        $f8, 0x3F8($a1)
    MEM_W(0X3F8, ctx->r5) = ctx->f8.u32l;
L_806760EC:
    // 0x806760EC: jal         0x80675C30
    // 0x806760F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675C30(rdram, ctx);
        goto after_1;
    // 0x806760F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806760F4: b           L_80676110
    // 0x806760F8: nop

        goto L_80676110;
    // 0x806760F8: nop

L_806760FC:
    // 0x806760FC: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x80676100: jal         0x80677A88
    // 0x80676104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80677A88(rdram, ctx);
        goto after_2;
    // 0x80676104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80676108: jal         0x80675B9C
    // 0x8067610C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675B9C(rdram, ctx);
        goto after_3;
    // 0x8067610C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80676110:
    // 0x80676110: jal         0x80675CD0
    // 0x80676114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675CD0(rdram, ctx);
        goto after_4;
    // 0x80676114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80676118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067611C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80676120: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80676124: jr          $ra
    // 0x80676128: nop

    return;
    // 0x80676128: nop

;}
RECOMP_FUNC void func_807AA094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AA094: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x807AA098: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AA09C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807AA0A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807AA0A4: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x807AA0A8: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x807AA0AC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x807AA0B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x807AA0B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807AA0B8: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x807AA0BC: jal         0x8004921C
    // 0x807AA0C0: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x807AA0C0: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    after_0:
    // 0x807AA0C4: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x807AA0C8: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x807AA0CC: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x807AA0D0: jal         0x8004921C
    // 0x807AA0D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x807AA0D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x807AA0D8: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x807AA0DC: sh          $v0, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r2;
    // 0x807AA0E0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x807AA0E4: lw          $t8, 0x168($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X168);
    // 0x807AA0E8: lw          $v1, -0x260C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X260C);
    // 0x807AA0EC: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x807AA0F0: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x807AA0F4: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x807AA0F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807AA0FC: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x807AA100: lw          $t3, 0x16C($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X16C);
    // 0x807AA104: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x807AA108: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x807AA10C: lw          $s0, 0xC($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XC);
    // 0x807AA110: addiu       $s0, $s0, -0x220
    ctx->r16 = ADD32(ctx->r16, -0X220);
    // 0x807AA114: sw          $s0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r16;
    // 0x807AA118: sw          $s0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r16;
    // 0x807AA11C: lw          $t5, 0x1F4($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X1F4);
    // 0x807AA120: jal         0x80077338
    // 0x807AA124: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x807AA124: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    after_2:
    // 0x807AA128: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x807AA12C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807AA130: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807AA134: jal         0x8007711C
    // 0x807AA138: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x807AA138: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    after_3:
    // 0x807AA13C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AA140: jal         0x807A9E88
    // 0x807AA144: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    func_807A9E88(rdram, ctx);
        goto after_4;
    // 0x807AA144: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_4:
    // 0x807AA148: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x807AA14C: lh          $t2, 0x70($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X70);
    // 0x807AA150: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x807AA154: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x807AA158: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x807AA15C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x807AA160: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x807AA164: multu       $s1, $t2
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807AA168: lui         $t5, 0xF550
    ctx->r13 = S32(0XF550 << 16);
    // 0x807AA16C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x807AA170: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x807AA174: lui         $t6, 0x701
    ctx->r14 = S32(0X701 << 16);
    // 0x807AA178: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x807AA17C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x807AA180: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    // 0x807AA184: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x807AA188: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x807AA18C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x807AA190: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x807AA194: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x807AA198: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x807AA19C: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x807AA1A0: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x807AA1A4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x807AA1A8: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x807AA1AC: mflo        $a1
    ctx->r5 = lo;
    // 0x807AA1B0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x807AA1B4: sra         $a1, $a1, 1
    ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
    // 0x807AA1B8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x807AA1BC: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x807AA1C0: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    // 0x807AA1C4: slti        $at, $a1, 0x7FF
    ctx->r1 = SIGNED(ctx->r5) < 0X7FF ? 1 : 0;
    // 0x807AA1C8: lui         $t5, 0xF300
    ctx->r13 = S32(0XF300 << 16);
    // 0x807AA1CC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x807AA1D0: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x807AA1D4: beq         $at, $zero, L_807AA1E4
    if (ctx->r1 == 0) {
        // 0x807AA1D8: or          $t1, $t3, $zero
        ctx->r9 = ctx->r11 | 0;
            goto L_807AA1E4;
    }
    // 0x807AA1D8: or          $t1, $t3, $zero
    ctx->r9 = ctx->r11 | 0;
    // 0x807AA1DC: b           L_807AA1E8
    // 0x807AA1E0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
        goto L_807AA1E8;
    // 0x807AA1E0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_807AA1E4:
    // 0x807AA1E4: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
L_807AA1E8:
    // 0x807AA1E8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x807AA1EC: bgez        $a3, L_807AA1FC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x807AA1F0: sra         $v0, $a3, 3
        ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
            goto L_807AA1FC;
    }
    // 0x807AA1F0: sra         $v0, $a3, 3
    ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
    // 0x807AA1F4: addiu       $at, $a3, 0x7
    ctx->r1 = ADD32(ctx->r7, 0X7);
    // 0x807AA1F8: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_807AA1FC:
    // 0x807AA1FC: bgtz        $v0, L_807AA20C
    if (SIGNED(ctx->r2) > 0) {
        // 0x807AA200: andi        $t3, $a2, 0xFFF
        ctx->r11 = ctx->r6 & 0XFFF;
            goto L_807AA20C;
    }
    // 0x807AA200: andi        $t3, $a2, 0xFFF
    ctx->r11 = ctx->r6 & 0XFFF;
    // 0x807AA204: b           L_807AA210
    // 0x807AA208: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_807AA210;
    // 0x807AA208: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_807AA20C:
    // 0x807AA20C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_807AA210:
    // 0x807AA210: bgtz        $v0, L_807AA220
    if (SIGNED(ctx->r2) > 0) {
        // 0x807AA214: addiu       $t6, $t0, 0x7FF
        ctx->r14 = ADD32(ctx->r8, 0X7FF);
            goto L_807AA220;
    }
    // 0x807AA214: addiu       $t6, $t0, 0x7FF
    ctx->r14 = ADD32(ctx->r8, 0X7FF);
    // 0x807AA218: b           L_807AA224
    // 0x807AA21C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_807AA224;
    // 0x807AA21C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_807AA220:
    // 0x807AA220: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_807AA224:
    // 0x807AA224: div         $zero, $t6, $s0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r16)));
    // 0x807AA228: bne         $s0, $zero, L_807AA234
    if (ctx->r16 != 0) {
        // 0x807AA22C: nop
    
            goto L_807AA234;
    }
    // 0x807AA22C: nop

    // 0x807AA230: break       7
    do_break(2155520560);
L_807AA234:
    // 0x807AA234: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x807AA238: bne         $s0, $at, L_807AA24C
    if (ctx->r16 != ctx->r1) {
        // 0x807AA23C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_807AA24C;
    }
    // 0x807AA23C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x807AA240: bne         $t6, $at, L_807AA24C
    if (ctx->r14 != ctx->r1) {
        // 0x807AA244: nop
    
            goto L_807AA24C;
    }
    // 0x807AA244: nop

    // 0x807AA248: break       6
    do_break(2155520584);
L_807AA24C:
    // 0x807AA24C: mflo        $t7
    ctx->r15 = lo;
    // 0x807AA250: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x807AA254: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x807AA258: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x807AA25C: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x807AA260: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x807AA264: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x807AA268: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x807AA26C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x807AA270: addiu       $t4, $a3, 0x7
    ctx->r12 = ADD32(ctx->r7, 0X7);
    // 0x807AA274: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x807AA278: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x807AA27C: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x807AA280: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x807AA284: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x807AA288: sra         $t5, $t4, 3
    ctx->r13 = S32(SIGNED(ctx->r12) >> 3);
    // 0x807AA28C: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x807AA290: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x807AA294: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x807AA298: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x807AA29C: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x807AA2A0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x807AA2A4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x807AA2A8: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x807AA2AC: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x807AA2B0: ori         $t3, $t3, 0x8000
    ctx->r11 = ctx->r11 | 0X8000;
    // 0x807AA2B4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x807AA2B8: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x807AA2BC: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x807AA2C0: addiu       $t6, $s1, -0x1
    ctx->r14 = ADD32(ctx->r17, -0X1);
    // 0x807AA2C4: addiu       $t4, $t9, 0x8
    ctx->r12 = ADD32(ctx->r25, 0X8);
    // 0x807AA2C8: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    // 0x807AA2CC: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x807AA2D0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x807AA2D4: addiu       $t9, $t2, -0x1
    ctx->r25 = ADD32(ctx->r10, -0X1);
    // 0x807AA2D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807AA2DC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x807AA2E0: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x807AA2E4: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x807AA2E8: sll         $t3, $t8, 12
    ctx->r11 = S32(ctx->r24 << 12);
    // 0x807AA2EC: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x807AA2F0: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x807AA2F4: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x807AA2F8: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x807AA2FC: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x807AA300: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x807AA304: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x807AA308: ori         $t9, $t9, 0x81FF
    ctx->r25 = ctx->r25 | 0X81FF;
    // 0x807AA30C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x807AA310: sw          $a3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r7;
    // 0x807AA314: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x807AA318: lui         $t5, 0x807B
    ctx->r13 = S32(RELOC_HI16(853, 0X1A90) << 16);
    // 0x807AA31C: lui         $a2, 0x600
    ctx->r6 = S32(0X600 << 16);
    // 0x807AA320: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x807AA324: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x807AA328: addiu       $t5, $t5, -0x4930
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(853, 0X1A90));
    // 0x807AA32C: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x807AA330: sw          $a2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r6;
    // 0x807AA334: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x807AA338: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x807AA33C: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x807AA340: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x807AA344: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x807AA348: ori         $t8, $t8, 0x103F
    ctx->r24 = ctx->r24 | 0X103F;
    // 0x807AA34C: addiu       $t9, $a3, 0x1E0
    ctx->r25 = ADD32(ctx->r7, 0X1E0);
    // 0x807AA350: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x807AA354: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x807AA358: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x807AA35C: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x807AA360: lui         $t5, 0x807B
    ctx->r13 = S32(RELOC_HI16(853, 0X1B88) << 16);
    // 0x807AA364: addiu       $t5, $t5, -0x4838
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(853, 0X1B88));
    // 0x807AA368: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x807AA36C: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x807AA370: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x807AA374: sw          $a2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r6;
    // 0x807AA378: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x807AA37C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x807AA380: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x807AA384: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x807AA388: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x807AA38C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807AA390: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807AA394: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807AA398: jr          $ra
    // 0x807AA39C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x807AA39C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_8066A4B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A4B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066A4B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A4BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8066A4C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8066A4C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8066A4C8: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8066A4CC: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8066A4D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8066A4D4: bnel        $v0, $at, L_8066A500
    if (ctx->r2 != ctx->r1) {
        // 0x8066A4D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066A500;
    }
    goto skip_0;
    // 0x8066A4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066A4DC: jal         0x8066A46C
    // 0x8066A4E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_8066A46C(rdram, ctx);
        goto after_0;
    // 0x8066A4E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x8066A4E4: beq         $v0, $zero, L_8066A4FC
    if (ctx->r2 == 0) {
        // 0x8066A4E8: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8066A4FC;
    }
    // 0x8066A4E8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8066A4EC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8066A4F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8066A4F4: jal         0x8002F6E4
    // 0x8066A4F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x8066A4F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_8066A4FC:
    // 0x8066A4FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A500:
    // 0x8066A500: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066A504: jr          $ra
    // 0x8066A508: nop

    return;
    // 0x8066A508: nop

;}
RECOMP_FUNC void func_807AE394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE394: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AE398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AE39C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807AE3A0: jal         0x807AC734
    // 0x807AE3A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807AC734(rdram, ctx);
        goto after_0;
    // 0x807AE3A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807AE3A8: beq         $v0, $zero, L_807AE3C0
    if (ctx->r2 == 0) {
        // 0x807AE3AC: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_807AE3C0;
    }
    // 0x807AE3AC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x807AE3B0: jal         0x807AE0E0
    // 0x807AE3B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807AE0E0(rdram, ctx);
        goto after_1;
    // 0x807AE3B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807AE3B8: b           L_807AE490
    // 0x807AE3BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807AE490;
    // 0x807AE3BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807AE3C0:
    // 0x807AE3C0: lui         $a2, 0x807B
    ctx->r6 = S32(RELOC_HI16(859, 0X14E0) << 16);
    // 0x807AE3C4: addiu       $a2, $a2, -0x24C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(859, 0X14E0));
    // 0x807AE3C8: lw          $a0, -0x7CE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE8);
    // 0x807AE3CC: jal         0x8005A994
    // 0x807AE3D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8005A994(rdram, ctx);
        goto after_2;
    // 0x807AE3D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x807AE3D4: jal         0x807ADD60
    // 0x807AE3D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807ADD60(rdram, ctx);
        goto after_3;
    // 0x807AE3D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807AE3DC: beql        $v0, $zero, L_807AE3FC
    if (ctx->r2 == 0) {
        // 0x807AE3E0: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_807AE3FC;
    }
    goto skip_0;
    // 0x807AE3E0: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_0:
    // 0x807AE3E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AE3E8: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE3EC: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x807AE3F0: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE3F4: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    // 0x807AE3F8: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_807AE3FC:
    // 0x807AE3FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AE400: blez        $v0, L_807AE410
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807AE404: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_807AE410;
    }
    // 0x807AE404: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x807AE408: b           L_807AE48C
    // 0x807AE40C: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
        goto L_807AE48C;
    // 0x807AE40C: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
L_807AE410:
    // 0x807AE410: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AE418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807AE41C: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x807AE420: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE424: jal         0x807AD0FC
    // 0x807AE428: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
    func_807AD0FC(rdram, ctx);
        goto after_4;
    // 0x807AE428: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
    after_4:
    // 0x807AE42C: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AE434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AE438: jal         0x807AD0FC
    // 0x807AE43C: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    func_807AD0FC(rdram, ctx);
        goto after_5;
    // 0x807AE43C: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    after_5:
    // 0x807AE440: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AE448: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AE44C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x807AE450: jal         0x807AEA24
    // 0x807AE454: sw          $v0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r2;
    func_807AEA24(rdram, ctx);
        goto after_6;
    // 0x807AE454: sw          $v0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r2;
    after_6:
    // 0x807AE458: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x807AE45C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE460: sb          $t3, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r11;
    // 0x807AE464: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE468: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x807AE46C: sb          $t4, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r12;
    // 0x807AE470: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE474: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x807AE478: sb          $t5, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r13;
    // 0x807AE47C: jal         0x800677F8
    // 0x807AE480: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    func_800677F8(rdram, ctx);
        goto after_7;
    // 0x807AE480: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_7:
    // 0x807AE484: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x807AE488: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_807AE48C:
    // 0x807AE48C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807AE490:
    // 0x807AE490: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807AE494: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AE498: jr          $ra
    // 0x807AE49C: nop

    return;
    // 0x807AE49C: nop

;}
RECOMP_FUNC void func_800480E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800480E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800480EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800480F0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x800480F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800480F8: addiu       $a2, $a2, -0x7FA0
    ctx->r6 = ADD32(ctx->r6, -0X7FA0);
    // 0x800480FC: jal         0x80047F34
    // 0x80048100: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    func_80047F34(rdram, ctx);
        goto after_0;
    // 0x80048100: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    after_0:
    // 0x80048104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004810C: jr          $ra
    // 0x80048110: nop

    return;
    // 0x80048110: nop

;}
RECOMP_FUNC void func_8057C3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C3B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057C3B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057C3B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057C3BC: jal         0x8057BB68
    // 0x8057C3C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8057BB68(rdram, ctx);
        goto after_0;
    // 0x8057C3C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8057C3C4: jal         0x8057C1AC
    // 0x8057C3C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057C1AC(rdram, ctx);
        goto after_1;
    // 0x8057C3C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8057C3CC: beq         $v0, $zero, L_8057C404
    if (ctx->r2 == 0) {
        // 0x8057C3D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8057C404;
    }
    // 0x8057C3D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057C3D4: jal         0x8057C6B0
    // 0x8057C3D8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8057C6B0(rdram, ctx);
        goto after_2;
    // 0x8057C3D8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_2:
    // 0x8057C3DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8057C3E0: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x8057C3E4: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8057C3E8: jal         0x80065490
    // 0x8057C3EC: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x8057C3EC: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    after_3:
    // 0x8057C3F0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8057C3F4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8057C3F8: lw          $t7, 0xEE0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XEE0);
    // 0x8057C3FC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8057C400: sw          $t8, 0xEE0($v0)
    MEM_W(0XEE0, ctx->r2) = ctx->r24;
L_8057C404:
    // 0x8057C404: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8057C408: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057C40C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057C410: jr          $ra
    // 0x8057C414: nop

    return;
    // 0x8057C414: nop

;}
RECOMP_FUNC void func_806D3F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D3F68: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806D3F6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D3F70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806D3F74: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806D3F78: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806D3F7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D3F80: jal         0x806D3DC0
    // 0x806D3F84: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    func_806D3DC0(rdram, ctx);
        goto after_0;
    // 0x806D3F84: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    after_0:
    // 0x806D3F88: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x806D3F8C: lui         $t7, 0x806D
    ctx->r15 = S32(RELOC_HI16(616, 0X3620) << 16);
    // 0x806D3F90: addiu       $t7, $t7, 0x65D0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(616, 0X3620));
    // 0x806D3F94: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806D3F98: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806D3F9C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806D3FA0: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806D3FA4: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806D3FA8: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    // 0x806D3FAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806D3FB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806D3FB4: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x806D3FB8: jal         0x80048378
    // 0x806D3FBC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x806D3FBC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x806D3FC0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806D3FC4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x806D3FC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806D3FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D3FD0: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x806D3FD4: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x806D3FD8: lw          $s1, 0x1F4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1F4);
    // 0x806D3FDC: jal         0x80045A34
    // 0x806D3FE0: sw          $zero, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = 0;
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x806D3FE0: sw          $zero, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = 0;
    after_2:
    // 0x806D3FE4: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806D3FE8: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x806D3FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D3FF0: jal         0x806D3E1C
    // 0x806D3FF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_806D3E1C(rdram, ctx);
        goto after_3;
    // 0x806D3FF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x806D3FF8: bne         $v0, $zero, L_806D402C
    if (ctx->r2 != 0) {
        // 0x806D3FFC: nop
    
            goto L_806D402C;
    }
    // 0x806D3FFC: nop

    // 0x806D4000: jal         0x80048060
    // 0x806D4004: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80048060(rdram, ctx);
        goto after_4;
    // 0x806D4004: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x806D4008: jal         0x800440E4
    // 0x806D400C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800440E4(rdram, ctx);
        goto after_5;
    // 0x806D400C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x806D4010: jal         0x8005FE48
    // 0x806D4014: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8005FE48(rdram, ctx);
        goto after_6;
    // 0x806D4014: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x806D4018: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x806D401C: sb          $t1, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r9;
    // 0x806D4020: sb          $zero, 0x165($s1)
    MEM_B(0X165, ctx->r17) = 0;
    // 0x806D4024: jal         0x800447C8
    // 0x806D4028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_7;
    // 0x806D4028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_806D402C:
    // 0x806D402C: jal         0x806D3DA0
    // 0x806D4030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D3DA0(rdram, ctx);
        goto after_8;
    // 0x806D4030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x806D4034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D4038: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806D403C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806D4040: jr          $ra
    // 0x806D4044: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x806D4044: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800077AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800077AC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800077B0: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x800077B4: lw          $t6, 0x1E9C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1E9C);
    // 0x800077B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800077BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800077C0: sltiu       $at, $t6, 0x11
    ctx->r1 = ctx->r14 < 0X11 ? 1 : 0;
    // 0x800077C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800077C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800077CC: bne         $at, $zero, L_800077DC
    if (ctx->r1 != 0) {
        // 0x800077D0: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800077DC;
    }
    // 0x800077D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800077D4: b           L_80007870
    // 0x800077D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80007870;
    // 0x800077D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800077DC:
    // 0x800077DC: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800077E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800077E4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800077E8: beq         $v1, $at, L_80007800
    if (ctx->r3 == ctx->r1) {
        // 0x800077EC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80007800;
    }
    // 0x800077EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800077F0: beq         $v1, $at, L_80007808
    if (ctx->r3 == ctx->r1) {
        // 0x800077F4: nop
    
            goto L_80007808;
    }
    // 0x800077F4: nop

    // 0x800077F8: b           L_80007870
    // 0x800077FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80007870;
    // 0x800077FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80007800:
    // 0x80007800: b           L_80007818
    // 0x80007804: lw          $a0, 0x138C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X138C);
        goto L_80007818;
    // 0x80007804: lw          $a0, 0x138C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X138C);
L_80007808:
    // 0x80007808: b           L_80007818
    // 0x8000780C: lw          $a0, 0x1390($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1390);
        goto L_80007818;
    // 0x8000780C: lw          $a0, 0x1390($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1390);
    // 0x80007810: b           L_80007870
    // 0x80007814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80007870;
    // 0x80007814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80007818:
    // 0x80007818: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8000781C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80007820: andi        $t7, $v0, 0xF
    ctx->r15 = ctx->r2 & 0XF;
    // 0x80007824: beql        $t7, $zero, L_80007838
    if (ctx->r15 == 0) {
        // 0x80007828: sb          $t8, 0x2($s0)
        MEM_B(0X2, ctx->r16) = ctx->r24;
            goto L_80007838;
    }
    goto skip_0;
    // 0x80007828: sb          $t8, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r24;
    skip_0:
    // 0x8000782C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80007830: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x80007834: sb          $t8, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r24;
L_80007838:
    // 0x80007838: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8000783C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80007840: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80007844: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80007848: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8000784C: sw          $a3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r7;
    // 0x80007850: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80007854: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // 0x80007858: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
    // 0x8000785C: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80007860: lw          $t9, 0x7E70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7E70);
    // 0x80007864: jalr        $t9
    // 0x80007868: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80007868: nop

    after_0:
    // 0x8000786C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80007870:
    // 0x80007870: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80007874: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80007878: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000787C: jr          $ra
    // 0x80007880: nop

    return;
    // 0x80007880: nop

    // 0x80007884: jr          $ra
    // 0x80007888: nop

    return;
    // 0x80007888: nop

    // 0x8000788C: jr          $ra
    // 0x80007890: nop

    return;
    // 0x80007890: nop

;}
RECOMP_FUNC void func_80445790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445798: jal         0x80046E88
    // 0x8044579C: addiu       $a0, $zero, 0x40EF
    ctx->r4 = ADD32(0, 0X40EF);
    func_80046E88(rdram, ctx);
        goto after_0;
    // 0x8044579C: addiu       $a0, $zero, 0x40EF
    ctx->r4 = ADD32(0, 0X40EF);
    after_0:
    // 0x804457A0: beq         $v0, $zero, L_804457B0
    if (ctx->r2 == 0) {
        // 0x804457A4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_804457B0;
    }
    // 0x804457A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804457A8: jal         0x800447C8
    // 0x804457AC: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x804457AC: nop

    after_1:
L_804457B0:
    // 0x804457B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804457B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804457B8: jr          $ra
    // 0x804457BC: nop

    return;
    // 0x804457BC: nop

;}
RECOMP_FUNC void func_805A146C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A146C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805A1470: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A1474: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A1478: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805A147C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A1480: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A1484: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x805A1488: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x805A148C: bnel        $t6, $zero, L_805A15B0
    if (ctx->r14 != 0) {
        // 0x805A1490: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A15B0;
    }
    goto skip_0;
    // 0x805A1490: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805A1494: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x805A1498: beql        $t7, $zero, L_805A15B0
    if (ctx->r15 == 0) {
        // 0x805A149C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A15B0;
    }
    goto skip_1;
    // 0x805A149C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805A14A0: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
    // 0x805A14A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805A14A8: bnel        $t8, $at, L_805A15B0
    if (ctx->r24 != ctx->r1) {
        // 0x805A14AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A15B0;
    }
    goto skip_2;
    // 0x805A14AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805A14B0: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x805A14B4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805A14B8: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x805A14BC: beq         $t9, $zero, L_805A1504
    if (ctx->r25 == 0) {
        // 0x805A14C0: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_805A1504;
    }
    // 0x805A14C0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x805A14C4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805A14C8: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x805A14CC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x805A14D0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x805A14D4: jal         0x8004D1F0
    // 0x805A14D8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x805A14D8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x805A14DC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805A14E0: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x805A14E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A14E8: jal         0x8004D698
    // 0x805A14EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x805A14EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x805A14F0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805A14F4: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x805A14F8: ori         $t1, $t0, 0xF
    ctx->r9 = ctx->r8 | 0XF;
    // 0x805A14FC: b           L_805A153C
    // 0x805A1500: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
        goto L_805A153C;
    // 0x805A1500: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
L_805A1504:
    // 0x805A1504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A1508: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x805A150C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x805A1510: jal         0x8004D1F0
    // 0x805A1514: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x805A1514: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x805A1518: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805A151C: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x805A1520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A1524: jal         0x8004D698
    // 0x805A1528: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8004D698(rdram, ctx);
        goto after_3;
    // 0x805A1528: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x805A152C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805A1530: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x805A1534: ori         $t3, $t2, 0xF0
    ctx->r11 = ctx->r10 | 0XF0;
    // 0x805A1538: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
L_805A153C:
    // 0x805A153C: lw          $t4, 0x138($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X138);
    // 0x805A1540: lwc1        $f4, 0xA8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x805A1544: lwc1        $f6, 0xAC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x805A1548: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x805A154C: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x805A1550: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805A1554: sw          $t6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r14;
    // 0x805A1558: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x805A155C: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x805A1560: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x805A1564: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805A1568: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805A156C: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805A1570: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805A1574: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x805A1578: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x805A157C: swc1        $f2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f2.u32l;
    // 0x805A1580: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x805A1584: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x805A1588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A158C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A1590: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x805A1594: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805A1598: swc1        $f18, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f18.u32l;
    // 0x805A159C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x805A15A0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805A15A4: jal         0x805A2B28
    // 0x805A15A8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805A2B28(rdram, ctx);
        goto after_4;
    // 0x805A15A8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
    // 0x805A15AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A15B0:
    // 0x805A15B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A15B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805A15B8: jr          $ra
    // 0x805A15BC: nop

    return;
    // 0x805A15BC: nop

;}
RECOMP_FUNC void func_80716AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716AB8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716ABC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716AC0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716AC4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716AC8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716ACC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716AD0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716AD4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716AD8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716ADC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716AE0: jr          $ra
    // 0x80716AE4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716AE4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80027504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027504: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80027508: lw          $v1, -0x72D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X72D8);
    // 0x8002750C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80027510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027514: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80027518: bgtzl       $v0, L_80027528
    if (SIGNED(ctx->r2) > 0) {
        // 0x8002751C: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80027528;
    }
    goto skip_0;
    // 0x8002751C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    skip_0:
    // 0x80027520: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80027524: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80027528:
    // 0x80027528: jal         0x800274BC
    // 0x8002752C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800274BC(rdram, ctx);
        goto after_0;
    // 0x8002752C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80027530: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80027534: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x80027538: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002753C: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80027540: bne         $at, $zero, L_80027558
    if (ctx->r1 != 0) {
        // 0x80027544: addiu       $t7, $t7, 0x7488
        ctx->r15 = ADD32(ctx->r15, 0X7488);
            goto L_80027558;
    }
    // 0x80027544: addiu       $t7, $t7, 0x7488
    ctx->r15 = ADD32(ctx->r15, 0X7488);
    // 0x80027548: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x8002754C: addiu       $t6, $t6, 0x7454
    ctx->r14 = ADD32(ctx->r14, 0X7454);
    // 0x80027550: b           L_8002755C
    // 0x80027554: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
        goto L_8002755C;
    // 0x80027554: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
L_80027558:
    // 0x80027558: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
L_8002755C:
    // 0x8002755C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027560: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80027564: jr          $ra
    // 0x80027568: nop

    return;
    // 0x80027568: nop

;}
RECOMP_FUNC void func_80027134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80027138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002713C: jal         0x80024748
    // 0x80027140: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024748(rdram, ctx);
        goto after_0;
    // 0x80027140: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80027144: beql        $v0, $zero, L_80027158
    if (ctx->r2 == 0) {
        // 0x80027148: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80027158;
    }
    goto skip_0;
    // 0x80027148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002714C: jal         0x800270C8
    // 0x80027150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800270C8(rdram, ctx);
        goto after_1;
    // 0x80027150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80027154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80027158:
    // 0x80027158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002715C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80027160: jr          $ra
    // 0x80027164: nop

    return;
    // 0x80027164: nop

;}
RECOMP_FUNC void func_804D6470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D6470: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D6474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D6478: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804D647C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804D6480: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804D6484: lui         $t8, 0x804D
    ctx->r24 = S32(RELOC_HI16(252, 0X568) << 16);
    // 0x804D6488: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804D648C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804D6490: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804D6494: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804D6498: lw          $t8, 0x6868($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(252, 0X568));
    // 0x804D649C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804D64A0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804D64A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804D64A8: jal         0x80048490
    // 0x804D64AC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804D64AC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804D64B0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804D64B4: jal         0x80048378
    // 0x804D64B8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804D64B8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804D64BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D64C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D64C4: jr          $ra
    // 0x804D64C8: nop

    return;
    // 0x804D64C8: nop

;}
RECOMP_FUNC void func_8040E984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040E984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040E988: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8040E98C: bne         $a1, $at, L_8040E9A8
    if (ctx->r5 != ctx->r1) {
        // 0x8040E990: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8040E9A8;
    }
    // 0x8040E990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040E994: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8040E998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8040E99C: beql        $v0, $t6, L_8040E9AC
    if (ctx->r2 == ctx->r14) {
        // 0x8040E9A0: addiu       $v0, $a0, 0x14C
        ctx->r2 = ADD32(ctx->r4, 0X14C);
            goto L_8040E9AC;
    }
    goto skip_0;
    // 0x8040E9A0: addiu       $v0, $a0, 0x14C
    ctx->r2 = ADD32(ctx->r4, 0X14C);
    skip_0:
    // 0x8040E9A4: sw          $v0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r2;
L_8040E9A8:
    // 0x8040E9A8: addiu       $v0, $a0, 0x14C
    ctx->r2 = ADD32(ctx->r4, 0X14C);
L_8040E9AC:
    // 0x8040E9AC: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8040E9B0: bnel        $t7, $zero, L_8040E9FC
    if (ctx->r15 != 0) {
        // 0x8040E9B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040E9FC;
    }
    goto skip_1;
    // 0x8040E9B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8040E9B8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8040E9BC: bnel        $t8, $zero, L_8040E9FC
    if (ctx->r24 != 0) {
        // 0x8040E9C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040E9FC;
    }
    goto skip_2;
    // 0x8040E9C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8040E9C4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040E9C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8040E9CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040E9D0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8040E9D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8040E9D8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8040E9DC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8040E9E0: lw          $t1, 0x1F4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040E9E4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8040E9E8: bnel        $t2, $at, L_8040E9FC
    if (ctx->r10 != ctx->r1) {
        // 0x8040E9EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040E9FC;
    }
    goto skip_3;
    // 0x8040E9EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8040E9F0: jal         0x8040F0B8
    // 0x8040E9F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8040F0B8(rdram, ctx);
        goto after_0;
    // 0x8040E9F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8040E9F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040E9FC:
    // 0x8040E9FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040EA00: jr          $ra
    // 0x8040EA04: nop

    return;
    // 0x8040EA04: nop

;}
RECOMP_FUNC void func_806B1524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B1528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B152C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806B1530: jal         0x80045A34
    // 0x806B1534: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806B1534: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x806B1538: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806B153C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x806B1540: bne         $v0, $zero, L_806B1558
    if (ctx->r2 != 0) {
        // 0x806B1544: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_806B1558;
    }
    // 0x806B1544: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x806B1548: jal         0x800445A4
    // 0x806B154C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806B154C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x806B1550: b           L_806B1568
    // 0x806B1554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806B1568;
    // 0x806B1554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806B1558:
    // 0x806B1558: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x806B155C: jal         0x80065728
    // 0x806B1560: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x806B1560: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x806B1564: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806B1568:
    // 0x806B1568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B156C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B1570: jr          $ra
    // 0x806B1574: nop

    return;
    // 0x806B1574: nop

;}
RECOMP_FUNC void func_8005F3F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F3F4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8005F3F8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8005F3FC: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x8005F400: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x8005F404: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x8005F408: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x8005F40C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8005F410: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8005F414: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8005F418: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8005F41C: lbu         $t6, 0x55($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X55);
    // 0x8005F420: addiu       $s7, $a1, 0x54
    ctx->r23 = ADD32(ctx->r5, 0X54);
    // 0x8005F424: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8005F428: beq         $t6, $zero, L_8005F4E4
    if (ctx->r14 == 0) {
        // 0x8005F42C: or          $s6, $s7, $zero
        ctx->r22 = ctx->r23 | 0;
            goto L_8005F4E4;
    }
    // 0x8005F42C: or          $s6, $s7, $zero
    ctx->r22 = ctx->r23 | 0;
    // 0x8005F430: lbu         $t7, 0x1($s7)
    ctx->r15 = MEM_BU(ctx->r23, 0X1);
    // 0x8005F434: lw          $s2, 0x0($a1)
    ctx->r18 = MEM_W(ctx->r5, 0X0);
    // 0x8005F438: lw          $s4, 0x198($a1)
    ctx->r20 = MEM_W(ctx->r5, 0X198);
    // 0x8005F43C: addiu       $s0, $s7, 0x4
    ctx->r16 = ADD32(ctx->r23, 0X4);
    // 0x8005F440: blez        $t7, L_8005F4E0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005F444: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8005F4E0;
    }
    // 0x8005F444: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005F448: addiu       $s3, $a1, 0x30
    ctx->r19 = ADD32(ctx->r5, 0X30);
    // 0x8005F44C: lh          $v0, 0x8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8);
L_8005F450:
    // 0x8005F450: bnel        $v0, $zero, L_8005F498
    if (ctx->r2 != 0) {
        // 0x8005F454: lw          $a3, 0xC($s0)
        ctx->r7 = MEM_W(ctx->r16, 0XC);
            goto L_8005F498;
    }
    goto skip_0;
    // 0x8005F454: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x8005F458: lh          $t8, 0xA($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XA);
    // 0x8005F45C: bnel        $t8, $zero, L_8005F498
    if (ctx->r24 != 0) {
        // 0x8005F460: lw          $a3, 0xC($s0)
        ctx->r7 = MEM_W(ctx->r16, 0XC);
            goto L_8005F498;
    }
    goto skip_1;
    // 0x8005F460: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    skip_1:
    // 0x8005F464: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8005F468: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8005F46C: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
    // 0x8005F470: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005F474: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8005F478: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8005F47C: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x8005F480: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8005F484: jal         0x8005F25C
    // 0x8005F488: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_8005F25C(rdram, ctx);
        goto after_0;
    // 0x8005F488: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
    // 0x8005F48C: b           L_8005F4CC
    // 0x8005F490: lbu         $t4, 0x1($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X1);
        goto L_8005F4CC;
    // 0x8005F490: lbu         $t4, 0x1($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X1);
    // 0x8005F494: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
L_8005F498:
    // 0x8005F498: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8005F49C: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
    // 0x8005F4A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005F4A4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8005F4A8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8005F4AC: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x8005F4B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005F4B4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8005F4B8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8005F4BC: lh          $t3, 0xA($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XA);
    // 0x8005F4C0: jal         0x8005F2CC
    // 0x8005F4C4: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    func_8005F2CC(rdram, ctx);
        goto after_1;
    // 0x8005F4C4: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    after_1:
    // 0x8005F4C8: lbu         $t4, 0x1($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X1);
L_8005F4CC:
    // 0x8005F4CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005F4D0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8005F4D4: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8005F4D8: bnel        $at, $zero, L_8005F450
    if (ctx->r1 != 0) {
        // 0x8005F4DC: lh          $v0, 0x8($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X8);
            goto L_8005F450;
    }
    goto skip_2;
    // 0x8005F4DC: lh          $v0, 0x8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8);
    skip_2:
L_8005F4E0:
    // 0x8005F4E0: sb          $zero, 0x1($s7)
    MEM_B(0X1, ctx->r23) = 0;
L_8005F4E4:
    // 0x8005F4E4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F4E8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F4EC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8005F4F0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8005F4F4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8005F4F8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x8005F4FC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x8005F500: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x8005F504: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x8005F508: jr          $ra
    // 0x8005F50C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8005F50C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8045310C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045310C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80453110: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80453114: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80453118: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045311C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80453120: lw          $v1, 0xA5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XA5C);
    // 0x80453124: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80453128: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8045312C: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80453130: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80453134: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80453138: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8045313C: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80453140: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80453144: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80453148: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8045314C: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80453150: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80453154: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80453158: addiu       $t8, $t7, 0xAE0
    ctx->r24 = ADD32(ctx->r15, 0XAE0);
    // 0x8045315C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80453160: jal         0x8044FD5C
    // 0x80453164: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_8044FD5C(rdram, ctx);
        goto after_0;
    // 0x80453164: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x80453168: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8045316C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80453170: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80453174: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80453178: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8045317C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80453180: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80453184: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80453188: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8045318C: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x80453190: addu        $a1, $v0, $t0
    ctx->r5 = ADD32(ctx->r2, ctx->r8);
    // 0x80453194: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    // 0x80453198: jal         0x8044ED68
    // 0x8045319C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8044ED68(rdram, ctx);
        goto after_1;
    // 0x8045319C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x804531A0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x804531A4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x804531A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804531AC: jal         0x8044F178
    // 0x804531B0: sw          $t1, 0xA5C($v0)
    MEM_W(0XA5C, ctx->r2) = ctx->r9;
    func_8044F178(rdram, ctx);
        goto after_2;
    // 0x804531B0: sw          $t1, 0xA5C($v0)
    MEM_W(0XA5C, ctx->r2) = ctx->r9;
    after_2:
    // 0x804531B4: jal         0x8044F384
    // 0x804531B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044F384(rdram, ctx);
        goto after_3;
    // 0x804531B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804531BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804531C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804531C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804531C8: jr          $ra
    // 0x804531CC: nop

    return;
    // 0x804531CC: nop

;}
RECOMP_FUNC void func_806D6D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D6D78: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806D6D7C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806D6D80: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x806D6D84: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x806D6D88: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806D6D8C: jal         0x8004700C
    // 0x806D6D90: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806D6D90: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x806D6D94: beq         $v0, $zero, L_806D6F14
    if (ctx->r2 == 0) {
        // 0x806D6D98: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_806D6F14;
    }
    // 0x806D6D98: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x806D6D9C: jal         0x806D6BC0
    // 0x806D6DA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806D6BC0(rdram, ctx);
        goto after_1;
    // 0x806D6DA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x806D6DA4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x806D6DA8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x806D6DAC: beq         $v0, $zero, L_806D6DBC
    if (ctx->r2 == 0) {
        // 0x806D6DB0: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806D6DBC;
    }
    // 0x806D6DB0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806D6DB4: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    // 0x806D6DB8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_806D6DBC:
    // 0x806D6DBC: bnel        $v0, $zero, L_806D6DFC
    if (ctx->r2 != 0) {
        // 0x806D6DC0: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_806D6DFC;
    }
    goto skip_0;
    // 0x806D6DC0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_0:
    // 0x806D6DC4: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x806D6DC8: lui         $t0, 0x806E
    ctx->r8 = S32(RELOC_HI16(622, 0X18E4) << 16);
    // 0x806D6DCC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x806D6DD0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806D6DD4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x806D6DD8: lw          $t0, -0x7B6C($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(622, 0X18E4));
    // 0x806D6DDC: sh          $t0, 0x144($s1)
    MEM_H(0X144, ctx->r17) = ctx->r8;
    // 0x806D6DE0: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x806D6DE4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x806D6DE8: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x806D6DEC: bne         $at, $zero, L_806D6DF8
    if (ctx->r1 != 0) {
        // 0x806D6DF0: sw          $t2, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r10;
            goto L_806D6DF8;
    }
    // 0x806D6DF0: sw          $t2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r10;
    // 0x806D6DF4: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
L_806D6DF8:
    // 0x806D6DF8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_806D6DFC:
    // 0x806D6DFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806D6E00: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x806D6E04: lwc1        $f2, 0x3C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x806D6E08: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x806D6E0C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x806D6E10: nop

    // 0x806D6E14: bc1tl       L_806D6E34
    if (c1cs) {
        // 0x806D6E18: lw          $t4, 0x10($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X10);
            goto L_806D6E34;
    }
    goto skip_1;
    // 0x806D6E18: lw          $t4, 0x10($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10);
    skip_1:
    // 0x806D6E1C: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x806D6E20: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x806D6E24: nop

    // 0x806D6E28: bc1fl       L_806D6E64
    if (!c1cs) {
        // 0x806D6E2C: sw          $zero, 0x10($s0)
        MEM_W(0X10, ctx->r16) = 0;
            goto L_806D6E64;
    }
    goto skip_2;
    // 0x806D6E2C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    skip_2:
    // 0x806D6E30: lw          $t4, 0x10($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10);
L_806D6E34:
    // 0x806D6E34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D6E38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D6E3C: bne         $t4, $zero, L_806D6E68
    if (ctx->r12 != 0) {
        // 0x806D6E40: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_806D6E68;
    }
    // 0x806D6E40: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806D6E44: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x806D6E48: jal         0x806D7A20
    // 0x806D6E4C: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    func_806D7A20(rdram, ctx);
        goto after_2;
    // 0x806D6E4C: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    after_2:
    // 0x806D6E50: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x806D6E54: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806D6E58: b           L_806D6E68
    // 0x806D6E5C: lwc1        $f2, 0x3C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X3C);
        goto L_806D6E68;
    // 0x806D6E5C: lwc1        $f2, 0x3C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x806D6E60: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
L_806D6E64:
    // 0x806D6E64: lwc1        $f2, 0x3C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X3C);
L_806D6E68:
    // 0x806D6E68: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x806D6E6C: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x806D6E70: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x806D6E74: lwc1        $f8, 0x84($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X84);
    // 0x806D6E78: sub.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x806D6E7C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806D6E80: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x806D6E84: nop

    // 0x806D6E88: bc1fl       L_806D6F0C
    if (!c1cs) {
        // 0x806D6E8C: addiu       $a0, $s1, 0xC4
        ctx->r4 = ADD32(ctx->r17, 0XC4);
            goto L_806D6F0C;
    }
    goto skip_3;
    // 0x806D6E8C: addiu       $a0, $s1, 0xC4
    ctx->r4 = ADD32(ctx->r17, 0XC4);
    skip_3:
    // 0x806D6E90: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806D6E94: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    // 0x806D6E98: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x806D6E9C: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x806D6EA0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x806D6EA4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x806D6EA8: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x806D6EAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D6EB0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x806D6EB4: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x806D6EB8: lui         $a2, 0xC000
    ctx->r6 = S32(0XC000 << 16);
    // 0x806D6EBC: lui         $a3, 0xC140
    ctx->r7 = S32(0XC140 << 16);
    // 0x806D6EC0: jalr        $t9
    // 0x806D6EC4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x806D6EC4: nop

    after_3:
    // 0x806D6EC8: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x806D6ECC: jal         0x80067BBC
    // 0x806D6ED0: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x806D6ED0: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_4:
    // 0x806D6ED4: addiu       $a0, $zero, 0x59
    ctx->r4 = ADD32(0, 0X59);
    // 0x806D6ED8: jal         0x80067818
    // 0x806D6EDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x806D6EDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x806D6EE0: jal         0x806D6D60
    // 0x806D6EE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806D6D60(rdram, ctx);
        goto after_6;
    // 0x806D6EE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x806D6EE8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806D6EEC: sw          $t0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r8;
    // 0x806D6EF0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x806D6EF4: sw          $t1, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->r9;
    // 0x806D6EF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D6EFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D6F00: jal         0x806D7A20
    // 0x806D6F04: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_806D7A20(rdram, ctx);
        goto after_7;
    // 0x806D6F04: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x806D6F08: addiu       $a0, $s1, 0xC4
    ctx->r4 = ADD32(ctx->r17, 0XC4);
L_806D6F0C:
    // 0x806D6F0C: jal         0x80048F84
    // 0x806D6F10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_8;
    // 0x806D6F10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
L_806D6F14:
    // 0x806D6F14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806D6F18: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x806D6F1C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x806D6F20: jr          $ra
    // 0x806D6F24: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x806D6F24: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_805A1A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1A28: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805A1A2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805A1A30: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x805A1A34: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x805A1A38: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x805A1A3C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x805A1A40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A1A44: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x805A1A48: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805A1A4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805A1A50: jal         0x80062AEC
    // 0x805A1A54: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x805A1A54: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    after_0:
    // 0x805A1A58: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x805A1A5C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x805A1A60: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x805A1A64: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x805A1A68: lwc1        $f12, 0x84($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805A1A6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805A1A70: lw          $t8, 0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X34);
    // 0x805A1A74: lw          $t9, 0x40($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X40);
    // 0x805A1A78: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x805A1A7C: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x805A1A80: addiu       $t0, $t9, 0xC
    ctx->r8 = ADD32(ctx->r25, 0XC);
    // 0x805A1A84: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x805A1A88: jal         0x800534C0
    // 0x805A1A8C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    func_800534C0(rdram, ctx);
        goto after_1;
    // 0x805A1A8C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x805A1A90: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x805A1A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A1A98: jal         0x80049D74
    // 0x805A1A9C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80049D74(rdram, ctx);
        goto after_2;
    // 0x805A1A9C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x805A1AA0: lw          $t1, 0x174($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X174);
    // 0x805A1AA4: addiu       $a1, $sp, 0x36
    ctx->r5 = ADD32(ctx->r29, 0X36);
    // 0x805A1AA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805A1AAC: lbu         $v0, 0x10($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X10);
    // 0x805A1AB0: bne         $v0, $zero, L_805A1AC8
    if (ctx->r2 != 0) {
        // 0x805A1AB4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_805A1AC8;
    }
    // 0x805A1AB4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x805A1AB8: lbu         $t2, 0x0($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X0);
    // 0x805A1ABC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x805A1AC0: andi        $t3, $t2, 0xF8
    ctx->r11 = ctx->r10 & 0XF8;
    // 0x805A1AC4: bne         $a0, $t3, L_805A1B10
    if (ctx->r4 != ctx->r11) {
        // 0x805A1AC8: addiu       $a0, $zero, 0x28
        ctx->r4 = ADD32(0, 0X28);
            goto L_805A1B10;
    }
L_805A1AC8:
    // 0x805A1AC8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x805A1ACC: bne         $v0, $at, L_805A1AEC
    if (ctx->r2 != ctx->r1) {
        // 0x805A1AD0: addiu       $a1, $sp, 0x36
        ctx->r5 = ADD32(ctx->r29, 0X36);
            goto L_805A1AEC;
    }
    // 0x805A1AD0: addiu       $a1, $sp, 0x36
    ctx->r5 = ADD32(ctx->r29, 0X36);
    // 0x805A1AD4: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x805A1AD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805A1ADC: andi        $t5, $t4, 0xF8
    ctx->r13 = ctx->r12 & 0XF8;
    // 0x805A1AE0: xor         $t6, $a0, $t5
    ctx->r14 = ctx->r4 ^ ctx->r13;
    // 0x805A1AE4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x805A1AE8: beq         $t6, $at, L_805A1B10
    if (ctx->r14 == ctx->r1) {
        // 0x805A1AEC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_805A1B10;
    }
L_805A1AEC:
    // 0x805A1AEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805A1AF0: bnel        $v1, $at, L_805A1B80
    if (ctx->r3 != ctx->r1) {
        // 0x805A1AF4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_805A1B80;
    }
    goto skip_0;
    // 0x805A1AF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x805A1AF8: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x805A1AFC: andi        $t8, $t7, 0xF8
    ctx->r24 = ctx->r15 & 0XF8;
    // 0x805A1B00: xor         $t9, $a0, $t8
    ctx->r25 = ctx->r4 ^ ctx->r24;
    // 0x805A1B04: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x805A1B08: bnel        $t9, $zero, L_805A1B80
    if (ctx->r25 != 0) {
        // 0x805A1B0C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_805A1B80;
    }
    goto skip_1;
    // 0x805A1B0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
L_805A1B10:
    // 0x805A1B10: lhu         $t0, 0xC($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0XC);
    // 0x805A1B14: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x805A1B18: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x805A1B1C: bne         $t0, $at, L_805A1B7C
    if (ctx->r8 != ctx->r1) {
        // 0x805A1B20: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_805A1B7C;
    }
    // 0x805A1B20: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805A1B24: bne         $t1, $at, L_805A1B6C
    if (ctx->r9 != ctx->r1) {
        // 0x805A1B28: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_805A1B6C;
    }
    // 0x805A1B28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A1B2C: lbu         $t2, 0x18($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X18);
    // 0x805A1B30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805A1B34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A1B38: bne         $t2, $at, L_805A1B50
    if (ctx->r10 != ctx->r1) {
        // 0x805A1B3C: nop
    
            goto L_805A1B50;
    }
    // 0x805A1B3C: nop

    // 0x805A1B40: lbu         $t3, 0x30($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X30);
    // 0x805A1B44: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x805A1B48: beql        $t3, $at, L_805A1B5C
    if (ctx->r11 == ctx->r1) {
        // 0x805A1B4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805A1B5C;
    }
    goto skip_2;
    // 0x805A1B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
L_805A1B50:
    // 0x805A1B50: jal         0x8002FABC
    // 0x805A1B54: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    func_8002FABC(rdram, ctx);
        goto after_3;
    // 0x805A1B54: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    after_3:
    // 0x805A1B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_805A1B5C:
    // 0x805A1B5C: jal         0x8003DD70
    // 0x805A1B60: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8003DD70(rdram, ctx);
        goto after_4;
    // 0x805A1B60: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x805A1B64: b           L_805A1B80
    // 0x805A1B68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_805A1B80;
    // 0x805A1B68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805A1B6C:
    // 0x805A1B6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805A1B70: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x805A1B74: jal         0x8002F6E4
    // 0x805A1B78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_5;
    // 0x805A1B78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
L_805A1B7C:
    // 0x805A1B7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805A1B80:
    // 0x805A1B80: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x805A1B84: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x805A1B88: jr          $ra
    // 0x805A1B8C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x805A1B8C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8069ACE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069ACE0: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8069ACE4: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8069ACE8: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x8069ACEC: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8069ACF0: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8069ACF4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8069ACF8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8069ACFC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8069AD00: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8069AD04: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8069AD08: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8069AD0C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8069AD10: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8069AD14: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8069AD18: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8069AD1C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8069AD20: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8069AD24: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x8069AD28: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8069AD2C: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x8069AD30: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8069AD34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8069AD38: jal         0x8004921C
    // 0x8069AD3C: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8069AD3C: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    after_0:
    // 0x8069AD40: sw          $v0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r2;
    // 0x8069AD44: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8069AD48: jal         0x8004921C
    // 0x8069AD4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x8069AD4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8069AD50: sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
    // 0x8069AD54: lw          $v1, 0x168($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X168);
    // 0x8069AD58: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(565, 0X1120) << 16);
    // 0x8069AD5C: addiu       $s1, $sp, 0xDC
    ctx->r17 = ADD32(ctx->r29, 0XDC);
    // 0x8069AD60: lw          $t8, 0x80($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X80);
    // 0x8069AD64: addiu       $t7, $t7, -0x4210
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(565, 0X1120));
    // 0x8069AD68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8069AD6C: sw          $t8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r24;
    // 0x8069AD70: lw          $s4, 0x1F4($fp)
    ctx->r20 = MEM_W(ctx->r30, 0X1F4);
    // 0x8069AD74: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8069AD78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8069AD7C: lw          $t9, 0x8($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X8);
    // 0x8069AD80: lw          $s0, 0x88($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X88);
    // 0x8069AD84: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8069AD88: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x8069AD8C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8069AD90: jal         0x80077338
    // 0x8069AD94: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x8069AD94: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x8069AD98: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x8069AD9C: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8069ADA0: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x8069ADA4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8069ADA8: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x8069ADAC: ori         $t7, $t7, 0xACB0
    ctx->r15 = ctx->r15 | 0XACB0;
    // 0x8069ADB0: ori         $t6, $t6, 0x18
    ctx->r14 = ctx->r14 | 0X18;
    // 0x8069ADB4: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8069ADB8: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8069ADBC: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x8069ADC0: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x8069ADC4: lui         $a1, 0x55
    ctx->r5 = S32(0X55 << 16);
    // 0x8069ADC8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8069ADCC: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x8069ADD0: ori         $a1, $a1, 0x3048
    ctx->r5 = ctx->r5 | 0X3048;
    // 0x8069ADD4: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x8069ADD8: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8069ADDC: sw          $a1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r5;
    // 0x8069ADE0: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x8069ADE4: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x8069ADE8: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x8069ADEC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8069ADF0: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x8069ADF4: sw          $a1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r5;
    // 0x8069ADF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8069ADFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8069AE00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8069AE04: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8069AE08: jal         0x8007711C
    // 0x8069AE0C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x8069AE0C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    after_3:
    // 0x8069AE10: lui         $at, 0xC188
    ctx->r1 = S32(0XC188 << 16);
    // 0x8069AE14: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8069AE18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8069AE1C: lui         $s3, 0x806A
    ctx->r19 = S32(RELOC_HI16(565, 0X1054) << 16);
    // 0x8069AE20: lui         $s5, 0x806A
    ctx->r21 = S32(RELOC_HI16(565, 0X18FC) << 16);
    // 0x8069AE24: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8069AE28: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8069AE2C: addiu       $s5, $s5, -0x3A34
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(565, 0X18FC));
    // 0x8069AE30: addiu       $s3, $s3, -0x42DC
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(565, 0X1054));
    // 0x8069AE34: addiu       $s1, $s2, 0x18
    ctx->r17 = ADD32(ctx->r18, 0X18);
    // 0x8069AE38: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8069AE3C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8069AE40: addiu       $s6, $zero, 0x309
    ctx->r22 = ADD32(0, 0X309);
L_8069AE44:
    // 0x8069AE44: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8069AE48: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8069AE4C: lw          $t6, 0x14($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X14);
    // 0x8069AE50: lwc1        $f16, 0x4($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8069AE54: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8069AE58: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8069AE5C: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8069AE60: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8069AE64: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8069AE68: lw          $t9, 0xC($s4)
    ctx->r25 = MEM_W(ctx->r20, 0XC);
    // 0x8069AE6C: lw          $t8, 0x10($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X10);
    // 0x8069AE70: mul.s       $f22, $f10, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8069AE74: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8069AE78: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x8069AE7C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8069AE80: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8069AE84: mul.s       $f24, $f6, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8069AE88: bne         $s6, $t8, L_8069AEAC
    if (ctx->r22 != ctx->r24) {
        // 0x8069AE8C: nop
    
            goto L_8069AEAC;
    }
    // 0x8069AE8C: nop

    // 0x8069AE90: jal         0x80066DE4
    // 0x8069AE94: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x8069AE94: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_4:
    // 0x8069AE98: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8069AE9C: jal         0x80066E88
    // 0x8069AEA0: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x8069AEA0: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_5:
    // 0x8069AEA4: b           L_8069AEC0
    // 0x8069AEA8: nop

        goto L_8069AEC0;
    // 0x8069AEA8: nop

L_8069AEAC:
    // 0x8069AEAC: jal         0x80066DE4
    // 0x8069AEB0: lwc1        $f12, 0x10($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X10);
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x8069AEB0: lwc1        $f12, 0x10($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X10);
    after_6:
    // 0x8069AEB4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8069AEB8: jal         0x80066E88
    // 0x8069AEBC: lwc1        $f12, 0x10($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X10);
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x8069AEBC: lwc1        $f12, 0x10($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X10);
    after_7:
L_8069AEC0:
    // 0x8069AEC0: mul.s       $f10, $f22, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8069AEC4: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8069AEC8: mul.s       $f8, $f24, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8069AECC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8069AED0: nop

    // 0x8069AED4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8069AED8: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8069AEDC: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8069AEE0: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8069AEE4: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8069AEE8: nop

    // 0x8069AEEC: sh          $t7, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r15;
    // 0x8069AEF0: lw          $t8, 0x10($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X10);
    // 0x8069AEF4: bne         $s6, $t8, L_8069AF28
    if (ctx->r22 != ctx->r24) {
        // 0x8069AEF8: nop
    
            goto L_8069AF28;
    }
    // 0x8069AEF8: nop

    // 0x8069AEFC: mul.s       $f8, $f22, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x8069AF00: lwc1        $f4, 0x40($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X40);
    // 0x8069AF04: mul.s       $f18, $f24, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8069AF08: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8069AF0C: add.s       $f16, $f6, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x8069AF10: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8069AF14: add.s       $f8, $f10, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x8069AF18: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8069AF1C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8069AF20: b           L_8069AF5C
    // 0x8069AF24: sh          $t6, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r14;
        goto L_8069AF5C;
    // 0x8069AF24: sh          $t6, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r14;
L_8069AF28:
    // 0x8069AF28: mul.s       $f6, $f22, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x8069AF2C: lw          $t7, 0x4($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X4);
    // 0x8069AF30: mul.s       $f16, $f24, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8069AF34: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8069AF38: nop

    // 0x8069AF3C: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8069AF40: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8069AF44: add.s       $f10, $f4, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f28.fl;
    // 0x8069AF48: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8069AF4C: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8069AF50: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8069AF54: nop

    // 0x8069AF58: sh          $t9, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r25;
L_8069AF5C:
    // 0x8069AF5C: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8069AF60: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8069AF64: lw          $t6, 0x14($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X14);
    // 0x8069AF68: lwc1        $f6, 0x4($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8069AF6C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8069AF70: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8069AF74: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8069AF78: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8069AF7C: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8069AF80: lw          $t9, 0xC($s4)
    ctx->r25 = MEM_W(ctx->r20, 0XC);
    // 0x8069AF84: lw          $t8, 0x10($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X10);
    // 0x8069AF88: mul.s       $f22, $f18, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8069AF8C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8069AF90: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x8069AF94: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8069AF98: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8069AF9C: mul.s       $f24, $f8, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8069AFA0: bne         $s6, $t8, L_8069AFC4
    if (ctx->r22 != ctx->r24) {
        // 0x8069AFA4: nop
    
            goto L_8069AFC4;
    }
    // 0x8069AFA4: nop

    // 0x8069AFA8: jal         0x80066DE4
    // 0x8069AFAC: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_80066DE4(rdram, ctx);
        goto after_8;
    // 0x8069AFAC: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_8:
    // 0x8069AFB0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8069AFB4: jal         0x80066E88
    // 0x8069AFB8: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_80066E88(rdram, ctx);
        goto after_9;
    // 0x8069AFB8: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_9:
    // 0x8069AFBC: b           L_8069AFD8
    // 0x8069AFC0: nop

        goto L_8069AFD8;
    // 0x8069AFC0: nop

L_8069AFC4:
    // 0x8069AFC4: jal         0x80066DE4
    // 0x8069AFC8: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    func_80066DE4(rdram, ctx);
        goto after_10;
    // 0x8069AFC8: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    after_10:
    // 0x8069AFCC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8069AFD0: jal         0x80066E88
    // 0x8069AFD4: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    func_80066E88(rdram, ctx);
        goto after_11;
    // 0x8069AFD4: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    after_11:
L_8069AFD8:
    // 0x8069AFD8: mul.s       $f18, $f22, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8069AFDC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8069AFE0: addiu       $s7, $s7, 0x10
    ctx->r23 = ADD32(ctx->r23, 0X10);
    // 0x8069AFE4: mul.s       $f10, $f24, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8069AFE8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8069AFEC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x8069AFF0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8069AFF4: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8069AFF8: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8069AFFC: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8069B000: trunc.w.s   $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8069B004: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8069B008: nop

    // 0x8069B00C: sh          $t7, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r15;
    // 0x8069B010: lw          $t8, 0x10($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X10);
    // 0x8069B014: bne         $s6, $t8, L_8069B044
    if (ctx->r22 != ctx->r24) {
        // 0x8069B018: nop
    
            goto L_8069B044;
    }
    // 0x8069B018: nop

    // 0x8069B01C: mul.s       $f10, $f22, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x8069B020: lwc1        $f6, 0x40($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X40);
    // 0x8069B024: mul.s       $f16, $f24, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8069B028: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8069B02C: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8069B030: add.s       $f18, $f4, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f30.fl;
    // 0x8069B034: trunc.w.s   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8069B038: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8069B03C: b           L_8069B074
    // 0x8069B040: sh          $t6, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r14;
        goto L_8069B074;
    // 0x8069B040: sh          $t6, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r14;
L_8069B044:
    // 0x8069B044: mul.s       $f16, $f22, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x8069B048: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x8069B04C: mul.s       $f8, $f24, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8069B050: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8069B054: nop

    // 0x8069B058: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8069B05C: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8069B060: sub.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8069B064: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8069B068: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8069B06C: nop

    // 0x8069B070: sh          $t9, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r25;
L_8069B074:
    // 0x8069B074: bne         $s7, $at, L_8069AE44
    if (ctx->r23 != ctx->r1) {
        // 0x8069B078: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_8069AE44;
    }
    // 0x8069B078: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8069B07C: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x8069B080: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x8069B084: ori         $t8, $t8, 0x207F
    ctx->r24 = ctx->r24 | 0X207F;
    // 0x8069B088: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8069B08C: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x8069B090: addiu       $t9, $s4, 0x18
    ctx->r25 = ADD32(ctx->r20, 0X18);
    // 0x8069B094: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8069B098: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8069B09C: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x8069B0A0: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x8069B0A4: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x8069B0A8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8069B0AC: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x8069B0B0: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8069B0B4: lw          $t9, 0x8($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X8);
    // 0x8069B0B8: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8069B0BC: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(565, 0X1840) << 16);
    // 0x8069B0C0: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8069B0C4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8069B0C8: lw          $t7, -0x3AF0($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(565, 0X1840));
    // 0x8069B0CC: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x8069B0D0: addiu       $a3, $zero, 0x7FF
    ctx->r7 = ADD32(0, 0X7FF);
    // 0x8069B0D4: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x8069B0D8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8069B0DC: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8069B0E0: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8069B0E4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8069B0E8: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x8069B0EC: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8069B0F0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8069B0F4: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x8069B0F8: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x8069B0FC: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8069B100: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x8069B104: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8069B108: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8069B10C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8069B110: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x8069B114: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8069B118: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8069B11C: lw          $t5, 0xD4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD4);
    // 0x8069B120: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x8069B124: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x8069B128: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8069B12C: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8069B130: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8069B134: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x8069B138: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8069B13C: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8069B140: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
    // 0x8069B144: mflo        $v0
    ctx->r2 = lo;
    // 0x8069B148: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8069B14C: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8069B150: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8069B154: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x8069B158: beq         $at, $zero, L_8069B168
    if (ctx->r1 == 0) {
        // 0x8069B15C: nop
    
            goto L_8069B168;
    }
    // 0x8069B15C: nop

    // 0x8069B160: b           L_8069B168
    // 0x8069B164: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_8069B168;
    // 0x8069B164: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8069B168:
    // 0x8069B168: bgez        $t0, L_8069B178
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8069B16C: sra         $v0, $t0, 3
        ctx->r2 = S32(SIGNED(ctx->r8) >> 3);
            goto L_8069B178;
    }
    // 0x8069B16C: sra         $v0, $t0, 3
    ctx->r2 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8069B170: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x8069B174: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8069B178:
    // 0x8069B178: bgtz        $v0, L_8069B188
    if (SIGNED(ctx->r2) > 0) {
        // 0x8069B17C: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8069B188;
    }
    // 0x8069B17C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8069B180: b           L_8069B188
    // 0x8069B184: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8069B188;
    // 0x8069B184: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8069B188:
    // 0x8069B188: bgtz        $v0, L_8069B198
    if (SIGNED(ctx->r2) > 0) {
        // 0x8069B18C: addiu       $t8, $t1, 0x7FF
        ctx->r24 = ADD32(ctx->r9, 0X7FF);
            goto L_8069B198;
    }
    // 0x8069B18C: addiu       $t8, $t1, 0x7FF
    ctx->r24 = ADD32(ctx->r9, 0X7FF);
    // 0x8069B190: b           L_8069B19C
    // 0x8069B194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8069B19C;
    // 0x8069B194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8069B198:
    // 0x8069B198: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8069B19C:
    // 0x8069B19C: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x8069B1A0: mflo        $t9
    ctx->r25 = lo;
    // 0x8069B1A4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8069B1A8: bne         $a1, $zero, L_8069B1B4
    if (ctx->r5 != 0) {
        // 0x8069B1AC: nop
    
            goto L_8069B1B4;
    }
    // 0x8069B1AC: nop

    // 0x8069B1B0: break       7
    do_break(2154410416);
L_8069B1B4:
    // 0x8069B1B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8069B1B8: bne         $a1, $at, L_8069B1CC
    if (ctx->r5 != ctx->r1) {
        // 0x8069B1BC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8069B1CC;
    }
    // 0x8069B1BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8069B1C0: bne         $t8, $at, L_8069B1CC
    if (ctx->r24 != ctx->r1) {
        // 0x8069B1C4: nop
    
            goto L_8069B1CC;
    }
    // 0x8069B1C4: nop

    // 0x8069B1C8: break       6
    do_break(2154410440);
L_8069B1CC:
    // 0x8069B1CC: andi        $t8, $a3, 0xFFF
    ctx->r24 = ctx->r7 & 0XFFF;
    // 0x8069B1D0: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8069B1D4: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x8069B1D8: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8069B1DC: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8069B1E0: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x8069B1E4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8069B1E8: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8069B1EC: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x8069B1F0: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x8069B1F4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8069B1F8: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8069B1FC: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x8069B200: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8069B204: addiu       $t7, $t0, 0x7
    ctx->r15 = ADD32(ctx->r8, 0X7);
    // 0x8069B208: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8069B20C: sra         $t9, $t7, 3
    ctx->r25 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8069B210: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8069B214: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x8069B218: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x8069B21C: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8069B220: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8069B224: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8069B228: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8069B22C: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x8069B230: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8069B234: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x8069B238: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8069B23C: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x8069B240: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8069B244: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8069B248: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8069B24C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8069B250: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8069B254: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8069B258: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8069B25C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8069B260: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8069B264: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8069B268: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x8069B26C: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(565, 0X10F8) << 16);
    // 0x8069B270: addiu       $t7, $t7, -0x4238
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(565, 0X10F8));
    // 0x8069B274: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8069B278: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x8069B27C: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8069B280: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8069B284: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8069B288: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8069B28C: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x8069B290: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x8069B294: sw          $t9, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r25;
    // 0x8069B298: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8069B29C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8069B2A0: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x8069B2A4: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8069B2A8: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8069B2AC: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8069B2B0: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8069B2B4: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8069B2B8: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8069B2BC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8069B2C0: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8069B2C4: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8069B2C8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8069B2CC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8069B2D0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8069B2D4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8069B2D8: jr          $ra
    // 0x8069B2DC: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8069B2DC: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void Fault_WaitInput(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007080C: lui         $t6, 0xFFFA
    ctx->r14 = S32(0XFFFA << 16);
    // 0x80070810: or          $t7, $sp, $zero
    ctx->r15 = ctx->r29 | 0;
    // 0x80070814: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070818: ori         $t6, $t6, 0x5A5A
    ctx->r14 = ctx->r14 | 0X5A5A;
L_8007081C:
    // 0x8007081C: addiu       $t7, $t7, -0x8
    ctx->r15 = ADD32(ctx->r15, -0X8);
    // 0x80070820: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80070824: bne         $t7, $sp, L_8007081C
    if (ctx->r15 != ctx->r29) {
        // 0x80070828: sw          $t6, 0x4($t7)
        MEM_W(0X4, ctx->r15) = ctx->r14;
            goto L_8007081C;
    }
    // 0x80070828: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8007082C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070830: jal         0x80070790
    // 0x80070834: nop

    Fault_WaitInputImpl(rdram, ctx);
        goto after_0;
    // 0x80070834: nop

    after_0:
    // 0x80070838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007083C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070840: jr          $ra
    // 0x80070844: nop

    return;
    // 0x80070844: nop

;}
RECOMP_FUNC void func_80065F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065F30: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80065F34: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80065F38: lwc1        $f4, 0xED4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XED4);
    // 0x80065F3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065F44: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80065F48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065F4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80065F50: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80065F54: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80065F58: jal         0x8007FF58
    // 0x80065F5C: nop

    func_8007FF58(rdram, ctx);
        goto after_0;
    // 0x80065F5C: nop

    after_0:
    // 0x80065F60: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80065F64: lwc1        $f10, 0xED8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XED8);
    // 0x80065F68: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80065F6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80065F70: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80065F74: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80065F78: jal         0x8007FF0C
    // 0x80065F7C: nop

    func_8007FF0C(rdram, ctx);
        goto after_1;
    // 0x80065F7C: nop

    after_1:
    // 0x80065F80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80065F84: lwc1        $f4, 0xEDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XEDC);
    // 0x80065F88: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80065F8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80065F90: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80065F94: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80065F98: jal         0x8007FEC8
    // 0x80065F9C: nop

    func_8007FEC8(rdram, ctx);
        goto after_2;
    // 0x80065F9C: nop

    after_2:
    // 0x80065FA0: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80065FA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80065FA8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80065FAC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80065FB0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80065FB4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80065FB8: jal         0x8007FFF0
    // 0x80065FBC: nop

    func_8007FFF0(rdram, ctx);
        goto after_3;
    // 0x80065FBC: nop

    after_3:
    // 0x80065FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065FC8: jr          $ra
    // 0x80065FCC: nop

    return;
    // 0x80065FCC: nop

;}
RECOMP_FUNC void func_80072278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072278: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007227C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80072280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80072284: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072288: jal         0x80082A6C
    // 0x8007228C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_0;
    // 0x8007228C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80072290: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072294: addiu       $a1, $a1, -0x5968
    ctx->r5 = ADD32(ctx->r5, -0X5968);
    // 0x80072298: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8007229C: jal         0x80089D70
    // 0x800722A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800722A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x800722A4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800722A8: addiu       $a1, $a1, -0x5948
    ctx->r5 = ADD32(ctx->r5, -0X5948);
    // 0x800722AC: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800722B0: jal         0x80089D70
    // 0x800722B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800722B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x800722B8: jal         0x80090710
    // 0x800722BC: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_3;
    // 0x800722BC: nop

    after_3:
    // 0x800722C0: jal         0x8008B920
    // 0x800722C4: nop

    osGetTime_recomp(rdram, ctx);
        goto after_4;
    // 0x800722C4: nop

    after_4:
    // 0x800722C8: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x800722CC: sw          $v1, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r3;
    // 0x800722D0: lw          $t6, 0x48($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X48);
    // 0x800722D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800722D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800722DC: beq         $t6, $at, L_800722F8
    if (ctx->r14 == ctx->r1) {
        // 0x800722E0: lui         $t9, 0x8011
        ctx->r25 = S32(0X8011 << 16);
            goto L_800722F8;
    }
    // 0x800722E0: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800722E4: sw          $v0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r2;
    // 0x800722E8: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800722EC: sw          $v1, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r3;
    // 0x800722F0: addiu       $t7, $t7, -0x4D94
    ctx->r15 = ADD32(ctx->r15, -0X4D94);
    // 0x800722F4: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
L_800722F8:
    // 0x800722F8: sw          $t8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r24;
    // 0x800722FC: addiu       $t9, $t9, -0x4D98
    ctx->r25 = ADD32(ctx->r25, -0X4D98);
    // 0x80072300: sw          $s0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r16;
    // 0x80072304: jal         0x80082BD4
    // 0x80072308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_5;
    // 0x80072308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8007230C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072310: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80072314: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80072318: jr          $ra
    // 0x8007231C: nop

    return;
    // 0x8007231C: nop

;}
RECOMP_FUNC void func_8044B51C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B51C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044B520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B524: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8044B528: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8044B52C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044B530: jal         0x8044A558
    // 0x8044B534: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_8044A558(rdram, ctx);
        goto after_0;
    // 0x8044B534: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_0:
    // 0x8044B538: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B53C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8044B540: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044B544: bne         $v0, $zero, L_8044B55C
    if (ctx->r2 != 0) {
        // 0x8044B548: nop
    
            goto L_8044B55C;
    }
    // 0x8044B548: nop

    // 0x8044B54C: jal         0x80446BDC
    // 0x8044B550: nop

    func_80446BDC(rdram, ctx);
        goto after_1;
    // 0x8044B550: nop

    after_1:
    // 0x8044B554: b           L_8044B580
    // 0x8044B558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044B580;
    // 0x8044B558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B55C:
    // 0x8044B55C: bne         $v0, $at, L_8044B574
    if (ctx->r2 != ctx->r1) {
        // 0x8044B560: nop
    
            goto L_8044B574;
    }
    // 0x8044B560: nop

    // 0x8044B564: jal         0x80446C0C
    // 0x8044B568: nop

    func_80446C0C(rdram, ctx);
        goto after_2;
    // 0x8044B568: nop

    after_2:
    // 0x8044B56C: b           L_8044B580
    // 0x8044B570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044B580;
    // 0x8044B570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B574:
    // 0x8044B574: jal         0x80446C40
    // 0x8044B578: nop

    func_80446C40(rdram, ctx);
        goto after_3;
    // 0x8044B578: nop

    after_3:
    // 0x8044B57C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B580:
    // 0x8044B580: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044B584: jr          $ra
    // 0x8044B588: nop

    return;
    // 0x8044B588: nop

;}
RECOMP_FUNC void func_80069FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069FE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80069FE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069FEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80069FF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80069FF4: bne         $a0, $zero, L_8006A004
    if (ctx->r4 != 0) {
        // 0x80069FF8: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8006A004;
    }
    // 0x80069FF8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80069FFC: b           L_8006A074
    // 0x8006A000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A074;
    // 0x8006A000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A004:
    // 0x8006A004: jal         0x80064DD0
    // 0x8006A008: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x8006A008: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x8006A00C: bne         $v0, $zero, L_8006A02C
    if (ctx->r2 != 0) {
        // 0x8006A010: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8006A02C;
    }
    // 0x8006A010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006A014: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A018: addiu       $a0, $a0, 0xF30
    ctx->r4 = ADD32(ctx->r4, 0XF30);
    // 0x8006A01C: jal         0x80071380
    // 0x8006A020: addiu       $a1, $zero, 0xCB
    ctx->r5 = ADD32(0, 0XCB);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8006A020: addiu       $a1, $zero, 0xCB
    ctx->r5 = ADD32(0, 0XCB);
    after_1:
    // 0x8006A024: b           L_8006A074
    // 0x8006A028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A074;
    // 0x8006A028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A02C:
    // 0x8006A02C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8006A030: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8006A034: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8006A038: bne         $t7, $zero, L_8006A064
    if (ctx->r15 != 0) {
        // 0x8006A03C: lui         $a3, 0x8006
        ctx->r7 = S32(0X8006 << 16);
            goto L_8006A064;
    }
    // 0x8006A03C: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x8006A040: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8006A044: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x8006A048: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x8006A04C: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x8006A050: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8006A054: jal         0x800675D0
    // 0x8006A058: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800675D0(rdram, ctx);
        goto after_2;
    // 0x8006A058: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8006A05C: b           L_8006A074
    // 0x8006A060: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_8006A074;
    // 0x8006A060: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8006A064:
    // 0x8006A064: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x8006A068: jal         0x800675D0
    // 0x8006A06C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800675D0(rdram, ctx);
        goto after_3;
    // 0x8006A06C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_3:
    // 0x8006A070: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8006A074:
    // 0x8006A074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A078: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006A07C: jr          $ra
    // 0x8006A080: nop

    return;
    // 0x8006A080: nop

;}
RECOMP_FUNC void func_8071593C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8071593C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80715940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80715944: jal         0x80715864
    // 0x80715948: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80715864(rdram, ctx);
        goto after_0;
    // 0x80715948: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8071594C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80715950: lui         $t6, 0x8071
    ctx->r14 = S32(RELOC_HI16(730, 0X15F0) << 16);
    // 0x80715954: addiu       $t6, $t6, 0x5E10
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(730, 0X15F0));
    // 0x80715958: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8071595C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80715960: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80715964: sw          $t6, 0x5F8($v0)
    MEM_W(0X5F8, ctx->r2) = ctx->r14;
    // 0x80715968: sh          $t7, 0x5FC($v0)
    MEM_H(0X5FC, ctx->r2) = ctx->r15;
    // 0x8071596C: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x80715970: addiu       $at, $zero, 0x4623
    ctx->r1 = ADD32(0, 0X4623);
    // 0x80715974: beq         $v1, $at, L_8071598C
    if (ctx->r3 == ctx->r1) {
        // 0x80715978: addiu       $at, $zero, 0x4624
        ctx->r1 = ADD32(0, 0X4624);
            goto L_8071598C;
    }
    // 0x80715978: addiu       $at, $zero, 0x4624
    ctx->r1 = ADD32(0, 0X4624);
    // 0x8071597C: beq         $v1, $at, L_80715994
    if (ctx->r3 == ctx->r1) {
        // 0x80715980: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_80715994;
    }
    // 0x80715980: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80715984: b           L_8071599C
    // 0x80715988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8071599C;
    // 0x80715988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8071598C:
    // 0x8071598C: b           L_80715998
    // 0x80715990: sw          $zero, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = 0;
        goto L_80715998;
    // 0x80715990: sw          $zero, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = 0;
L_80715994:
    // 0x80715994: sw          $t8, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = ctx->r24;
L_80715998:
    // 0x80715998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8071599C:
    // 0x8071599C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807159A0: jr          $ra
    // 0x807159A4: nop

    return;
    // 0x807159A4: nop

;}
RECOMP_FUNC void func_807925B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807925B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807925B4: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x807925B8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x807925BC: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x807925C0: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x807925C4: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x807925C8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x807925CC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807925D0: lw          $t0, -0x7290($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7290);
    // 0x807925D4: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x807925D8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x807925DC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x807925E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807925E4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_807925E8:
    // 0x807925E8: andi        $a1, $a3, 0x1
    ctx->r5 = ctx->r7 & 0X1;
    // 0x807925EC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x807925F0: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x807925F4: lw          $t8, 0x38($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X38);
    // 0x807925F8: addu        $t9, $t0, $a1
    ctx->r25 = ADD32(ctx->r8, ctx->r5);
    // 0x807925FC: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80792600: beq         $t8, $zero, L_8079268C
    if (ctx->r24 == 0) {
        // 0x80792604: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_8079268C;
    }
    // 0x80792604: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80792608: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x8079260C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80792610: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80792614: beq         $t6, $zero, L_80792630
    if (ctx->r14 == 0) {
        // 0x80792618: lw          $t2, 0x12C($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X12C);
            goto L_80792630;
    }
    // 0x80792618: lw          $t2, 0x12C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X12C);
    // 0x8079261C: bnel        $t2, $zero, L_80792644
    if (ctx->r10 != 0) {
        // 0x80792620: subu        $t7, $t7, $a1
        ctx->r15 = SUB32(ctx->r15, ctx->r5);
            goto L_80792644;
    }
    goto skip_0;
    // 0x80792620: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    skip_0:
    // 0x80792624: or          $t1, $s2, $zero
    ctx->r9 = ctx->r18 | 0;
    // 0x80792628: b           L_80792640
    // 0x8079262C: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
        goto L_80792640;
    // 0x8079262C: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
L_80792630:
    // 0x80792630: bnel        $s3, $t2, L_80792644
    if (ctx->r19 != ctx->r10) {
        // 0x80792634: subu        $t7, $t7, $a1
        ctx->r15 = SUB32(ctx->r15, ctx->r5);
            goto L_80792644;
    }
    goto skip_1;
    // 0x80792634: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    skip_1:
    // 0x80792638: or          $t1, $s2, $zero
    ctx->r9 = ctx->r18 | 0;
    // 0x8079263C: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
L_80792640:
    // 0x80792640: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
L_80792644:
    // 0x80792644: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80792648: addu        $t5, $t0, $t7
    ctx->r13 = ADD32(ctx->r8, ctx->r15);
    // 0x8079264C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_80792650:
    // 0x80792650: addu        $t8, $t5, $t4
    ctx->r24 = ADD32(ctx->r13, ctx->r12);
    // 0x80792654: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80792658: addu        $t3, $t9, $a2
    ctx->r11 = ADD32(ctx->r25, ctx->r6);
    // 0x8079265C: slti        $at, $t3, 0x15
    ctx->r1 = SIGNED(ctx->r11) < 0X15 ? 1 : 0;
    // 0x80792660: bne         $at, $zero, L_80792680
    if (ctx->r1 != 0) {
        // 0x80792664: slti        $at, $t3, 0x46
        ctx->r1 = SIGNED(ctx->r11) < 0X46 ? 1 : 0;
            goto L_80792680;
    }
    // 0x80792664: slti        $at, $t3, 0x46
    ctx->r1 = SIGNED(ctx->r11) < 0X46 ? 1 : 0;
    // 0x80792668: beql        $at, $zero, L_80792684
    if (ctx->r1 == 0) {
        // 0x8079266C: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_80792684;
    }
    goto skip_2;
    // 0x8079266C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_2:
    // 0x80792670: sw          $a1, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r5;
    // 0x80792674: sw          $t2, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r10;
    // 0x80792678: b           L_8079269C
    // 0x8079267C: ori         $v0, $t1, 0x1
    ctx->r2 = ctx->r9 | 0X1;
        goto L_8079269C;
    // 0x8079267C: ori         $v0, $t1, 0x1
    ctx->r2 = ctx->r9 | 0X1;
L_80792680:
    // 0x80792680: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80792684:
    // 0x80792684: bne         $t2, $s1, L_80792650
    if (ctx->r10 != ctx->r17) {
        // 0x80792688: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_80792650;
    }
    // 0x80792688: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
L_8079268C:
    // 0x8079268C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80792690: bne         $v0, $s2, L_807925E8
    if (ctx->r2 != ctx->r18) {
        // 0x80792694: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_807925E8;
    }
    // 0x80792694: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80792698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8079269C:
    // 0x8079269C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x807926A0: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x807926A4: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x807926A8: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x807926AC: jr          $ra
    // 0x807926B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x807926B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8040F830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040F830: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8040F834: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8040F838: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8040F83C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8040F840: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040F844: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040F848: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8040F84C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040F850: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8040F854: slti        $at, $t6, 0xC8
    ctx->r1 = SIGNED(ctx->r14) < 0XC8 ? 1 : 0;
    // 0x8040F858: beq         $at, $zero, L_8040FA1C
    if (ctx->r1 == 0) {
        // 0x8040F85C: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_8040FA1C;
    }
    // 0x8040F85C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8040F860: jal         0x80410EEC
    // 0x8040F864: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80410EEC(rdram, ctx);
        goto after_0;
    // 0x8040F864: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8040F868: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    // 0x8040F86C: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x8040F870: beq         $at, $zero, L_8040FA1C
    if (ctx->r1 == 0) {
        // 0x8040F874: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8040FA1C;
    }
    // 0x8040F874: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8040F878: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(26, 0X2440) << 16);
    // 0x8040F87C: addu        $at, $at, $t7
    gpr jr_addend_8040F884 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8040F880: lw          $t7, 0x1AC0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(26, 0X2440));
    // 0x8040F884: jr          $t7
    // 0x8040F888: nop

    switch (jr_addend_8040F884 >> 2) {
        case 0: goto L_8040F88C; break;
        case 1: goto L_8040F928; break;
        case 2: goto L_8040F98C; break;
        case 3: goto L_8040F9D8; break;
        case 4: goto L_8040F88C; break;
        default: switch_error(__func__, 0x8040F884, 0x80411AC0);
    }
    // 0x8040F888: nop

L_8040F88C:
    // 0x8040F88C: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8040F890: lbu         $t8, 0x7EA3($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7EA3);
    // 0x8040F894: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8040F898: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8040F89C: beql        $t8, $at, L_8040F8B0
    if (ctx->r24 == ctx->r1) {
        // 0x8040F8A0: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_8040F8B0;
    }
    goto skip_0;
    // 0x8040F8A0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    skip_0:
    // 0x8040F8A4: jal         0x80410F28
    // 0x8040F8A8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    func_80410F28(rdram, ctx);
        goto after_1;
    // 0x8040F8A8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_1:
    // 0x8040F8AC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
L_8040F8B0:
    // 0x8040F8B0: addu        $v0, $s1, $at
    ctx->r2 = ADD32(ctx->r17, ctx->r1);
    // 0x8040F8B4: lw          $t9, 0x39D0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X39D0);
    // 0x8040F8B8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8040F8BC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8040F8C0: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8040F8C4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8040F8C8: sll         $t0, $t0, 9
    ctx->r8 = S32(ctx->r8 << 9);
    // 0x8040F8CC: addu        $a1, $s1, $t0
    ctx->r5 = ADD32(ctx->r17, ctx->r8);
    // 0x8040F8D0: jal         0x8040FF04
    // 0x8040F8D4: addiu       $a1, $a1, 0x5C0
    ctx->r5 = ADD32(ctx->r5, 0X5C0);
    func_8040FF04(rdram, ctx);
        goto after_2;
    // 0x8040F8D4: addiu       $a1, $a1, 0x5C0
    ctx->r5 = ADD32(ctx->r5, 0X5C0);
    after_2:
    // 0x8040F8D8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8040F8DC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8040F8E0: lw          $t1, 0x39D0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X39D0);
    // 0x8040F8E4: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8040F8E8: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8040F8EC: sll         $t2, $t2, 9
    ctx->r10 = S32(ctx->r10 << 9);
    // 0x8040F8F0: addu        $a1, $s1, $t2
    ctx->r5 = ADD32(ctx->r17, ctx->r10);
    // 0x8040F8F4: jal         0x8040FF04
    // 0x8040F8F8: addiu       $a1, $a1, 0x5FC0
    ctx->r5 = ADD32(ctx->r5, 0X5FC0);
    func_8040FF04(rdram, ctx);
        goto after_3;
    // 0x8040F8F8: addiu       $a1, $a1, 0x5FC0
    ctx->r5 = ADD32(ctx->r5, 0X5FC0);
    after_3:
    // 0x8040F8FC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8040F900: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8040F904: lw          $t3, 0x39D0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X39D0);
    // 0x8040F908: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8040F90C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8040F910: sll         $t4, $t4, 9
    ctx->r12 = S32(ctx->r12 << 9);
    // 0x8040F914: addu        $a1, $s1, $t4
    ctx->r5 = ADD32(ctx->r17, ctx->r12);
    // 0x8040F918: jal         0x80411968
    // 0x8040F91C: addiu       $a1, $a1, 0x5FC0
    ctx->r5 = ADD32(ctx->r5, 0X5FC0);
    func_80411968(rdram, ctx);
        goto after_4;
    // 0x8040F91C: addiu       $a1, $a1, 0x5FC0
    ctx->r5 = ADD32(ctx->r5, 0X5FC0);
    after_4:
    // 0x8040F920: b           L_8040FA1C
    // 0x8040F924: nop

        goto L_8040FA1C;
    // 0x8040F924: nop

L_8040F928:
    // 0x8040F928: lw          $t5, 0x1E0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1E0);
    // 0x8040F92C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8040F930: addu        $v0, $s1, $at
    ctx->r2 = ADD32(ctx->r17, ctx->r1);
    // 0x8040F934: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8040F938: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
    // 0x8040F93C: lw          $t7, 0x39D0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X39D0);
    // 0x8040F940: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8040F944: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8040F948: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8040F94C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8040F950: sll         $t8, $t8, 9
    ctx->r24 = S32(ctx->r24 << 9);
    // 0x8040F954: addu        $a1, $s1, $t8
    ctx->r5 = ADD32(ctx->r17, ctx->r24);
    // 0x8040F958: jal         0x8040FF04
    // 0x8040F95C: addiu       $a1, $a1, 0x5C0
    ctx->r5 = ADD32(ctx->r5, 0X5C0);
    func_8040FF04(rdram, ctx);
        goto after_5;
    // 0x8040F95C: addiu       $a1, $a1, 0x5C0
    ctx->r5 = ADD32(ctx->r5, 0X5C0);
    after_5:
    // 0x8040F960: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8040F964: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8040F968: lw          $t9, 0x39D0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X39D0);
    // 0x8040F96C: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8040F970: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8040F974: sll         $t0, $t0, 9
    ctx->r8 = S32(ctx->r8 << 9);
    // 0x8040F978: addu        $a1, $s1, $t0
    ctx->r5 = ADD32(ctx->r17, ctx->r8);
    // 0x8040F97C: jal         0x80411968
    // 0x8040F980: addiu       $a1, $a1, 0x5FC0
    ctx->r5 = ADD32(ctx->r5, 0X5FC0);
    func_80411968(rdram, ctx);
        goto after_6;
    // 0x8040F980: addiu       $a1, $a1, 0x5FC0
    ctx->r5 = ADD32(ctx->r5, 0X5FC0);
    after_6:
    // 0x8040F984: b           L_8040FA1C
    // 0x8040F988: nop

        goto L_8040FA1C;
    // 0x8040F988: nop

L_8040F98C:
    // 0x8040F98C: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x8040F990: lbu         $t1, 0x7EA3($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7EA3);
    // 0x8040F994: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8040F998: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8040F99C: beql        $t1, $at, L_8040F9B0
    if (ctx->r9 == ctx->r1) {
        // 0x8040F9A0: addiu       $t2, $s1, 0x7FFF
        ctx->r10 = ADD32(ctx->r17, 0X7FFF);
            goto L_8040F9B0;
    }
    goto skip_1;
    // 0x8040F9A0: addiu       $t2, $s1, 0x7FFF
    ctx->r10 = ADD32(ctx->r17, 0X7FFF);
    skip_1:
    // 0x8040F9A4: jal         0x80411328
    // 0x8040F9A8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    func_80411328(rdram, ctx);
        goto after_7;
    // 0x8040F9A8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_7:
    // 0x8040F9AC: addiu       $t2, $s1, 0x7FFF
    ctx->r10 = ADD32(ctx->r17, 0X7FFF);
L_8040F9B0:
    // 0x8040F9B0: lw          $t2, 0x39D1($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X39D1);
    // 0x8040F9B4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8040F9B8: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8040F9BC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8040F9C0: sll         $t3, $t3, 9
    ctx->r11 = S32(ctx->r11 << 9);
    // 0x8040F9C4: addu        $a1, $s1, $t3
    ctx->r5 = ADD32(ctx->r17, ctx->r11);
    // 0x8040F9C8: jal         0x8040FF04
    // 0x8040F9CC: addiu       $a1, $a1, 0x5C0
    ctx->r5 = ADD32(ctx->r5, 0X5C0);
    func_8040FF04(rdram, ctx);
        goto after_8;
    // 0x8040F9CC: addiu       $a1, $a1, 0x5C0
    ctx->r5 = ADD32(ctx->r5, 0X5C0);
    after_8:
    // 0x8040F9D0: b           L_8040FA1C
    // 0x8040F9D4: nop

        goto L_8040FA1C;
    // 0x8040F9D4: nop

L_8040F9D8:
    // 0x8040F9D8: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x8040F9DC: lbu         $t4, 0x7EA3($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7EA3);
    // 0x8040F9E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8040F9E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8040F9E8: beql        $t4, $at, L_8040F9FC
    if (ctx->r12 == ctx->r1) {
        // 0x8040F9EC: addiu       $t5, $s1, 0x7FFF
        ctx->r13 = ADD32(ctx->r17, 0X7FFF);
            goto L_8040F9FC;
    }
    goto skip_2;
    // 0x8040F9EC: addiu       $t5, $s1, 0x7FFF
    ctx->r13 = ADD32(ctx->r17, 0X7FFF);
    skip_2:
    // 0x8040F9F0: jal         0x80411588
    // 0x8040F9F4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    func_80411588(rdram, ctx);
        goto after_9;
    // 0x8040F9F4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_9:
    // 0x8040F9F8: addiu       $t5, $s1, 0x7FFF
    ctx->r13 = ADD32(ctx->r17, 0X7FFF);
L_8040F9FC:
    // 0x8040F9FC: lw          $t5, 0x39D1($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X39D1);
    // 0x8040FA00: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8040FA04: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8040FA08: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8040FA0C: sll         $t6, $t6, 9
    ctx->r14 = S32(ctx->r14 << 9);
    // 0x8040FA10: addu        $a1, $s1, $t6
    ctx->r5 = ADD32(ctx->r17, ctx->r14);
    // 0x8040FA14: jal         0x80410010
    // 0x8040FA18: addiu       $a1, $a1, 0x5C0
    ctx->r5 = ADD32(ctx->r5, 0X5C0);
    func_80410010(rdram, ctx);
        goto after_10;
    // 0x8040FA18: addiu       $a1, $a1, 0x5C0
    ctx->r5 = ADD32(ctx->r5, 0X5C0);
    after_10:
L_8040FA1C:
    // 0x8040FA1C: jal         0x80062C70
    // 0x8040FA20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80062C70(rdram, ctx);
        goto after_11;
    // 0x8040FA20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8040FA24: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8040FA28: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8040FA2C: lwc1        $f10, 0x70($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8040FA30: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8040FA34: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8040FA38: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x8040FA3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8040FA40: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8040FA44: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8040FA48: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    // 0x8040FA4C: bne         $v0, $at, L_8040FA5C
    if (ctx->r2 != ctx->r1) {
        // 0x8040FA50: swc1        $f18, 0x70($s0)
        MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
            goto L_8040FA5C;
    }
    // 0x8040FA50: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
    // 0x8040FA54: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8040FA58: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_8040FA5C:
    // 0x8040FA5C: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x8040FA60: bnel        $v0, $at, L_8040FA74
    if (ctx->r2 != ctx->r1) {
        // 0x8040FA64: addiu       $at, $zero, 0x78
        ctx->r1 = ADD32(0, 0X78);
            goto L_8040FA74;
    }
    goto skip_3;
    // 0x8040FA64: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    skip_3:
    // 0x8040FA68: sb          $t7, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r15;
    // 0x8040FA6C: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x8040FA70: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
L_8040FA74:
    // 0x8040FA74: bne         $v0, $at, L_8040FA9C
    if (ctx->r2 != ctx->r1) {
        // 0x8040FA78: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_8040FA9C;
    }
    // 0x8040FA78: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8040FA7C: sb          $zero, -0x7D78($at)
    MEM_B(-0X7D78, ctx->r1) = 0;
    // 0x8040FA80: jal         0x800717BC
    // 0x8040FA84: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    func_800717BC(rdram, ctx);
        goto after_12;
    // 0x8040FA84: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    after_12:
    // 0x8040FA88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040FA8C: jal         0x800461F4
    // 0x8040FA90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800461F4(rdram, ctx);
        goto after_13;
    // 0x8040FA90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x8040FA94: jal         0x80044658
    // 0x8040FA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044658(rdram, ctx);
        goto after_14;
    // 0x8040FA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_8040FA9C:
    // 0x8040FA9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8040FAA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040FAA4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8040FAA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8040FAAC: jr          $ra
    // 0x8040FAB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8040FAB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_806EA8B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EA8B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EA8B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EA8BC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806EA8C0: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x806EA8C4: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(670, 0XECC) << 16);
    // 0x806EA8C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806EA8CC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806EA8D0: lw          $t8, -0x4964($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(670, 0XECC));
    // 0x806EA8D4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806EA8D8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x806EA8DC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x806EA8E0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x806EA8E4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x806EA8E8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x806EA8EC: beql        $v1, $zero, L_806EA920
    if (ctx->r3 == 0) {
        // 0x806EA8F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806EA920;
    }
    goto skip_0;
    // 0x806EA8F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806EA8F4: jalr        $v1
    // 0x806EA8F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x806EA8F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806EA8FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EA900: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x806EA904: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x806EA908: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x806EA90C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x806EA910: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x806EA914: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x806EA918: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x806EA91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806EA920:
    // 0x806EA920: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EA924: jr          $ra
    // 0x806EA928: nop

    return;
    // 0x806EA928: nop

;}
RECOMP_FUNC void func_80031BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031BC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031BCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031BD0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80031BD4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80031BD8: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031BDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80031BE0: jal         0x80042148
    // 0x80031BE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80042148(rdram, ctx);
        goto after_0;
    // 0x80031BE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80031BE8: beq         $v0, $zero, L_80031C28
    if (ctx->r2 == 0) {
        // 0x80031BEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80031C28;
    }
    // 0x80031BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80031BF0: jal         0x800310A0
    // 0x80031BF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800310A0(rdram, ctx);
        goto after_1;
    // 0x80031BF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80031BF8: jal         0x80021A44
    // 0x80031BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80021A44(rdram, ctx);
        goto after_2;
    // 0x80031BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80031C00: lw          $t6, 0x78($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X78);
    // 0x80031C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80031C08: beq         $t6, $zero, L_80031C20
    if (ctx->r14 == 0) {
        // 0x80031C0C: nop
    
            goto L_80031C20;
    }
    // 0x80031C0C: nop

    // 0x80031C10: jal         0x8002BCE8
    // 0x80031C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002BCE8(rdram, ctx);
        goto after_3;
    // 0x80031C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80031C18: b           L_80031C2C
    // 0x80031C1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80031C2C;
    // 0x80031C1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80031C20:
    // 0x80031C20: jal         0x800310D0
    // 0x80031C24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800310D0(rdram, ctx);
        goto after_4;
    // 0x80031C24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
L_80031C28:
    // 0x80031C28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80031C2C:
    // 0x80031C2C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80031C30: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80031C34: jr          $ra
    // 0x80031C38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80031C38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8004A0BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A0BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004A0C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004A0C4: jal         0x80064D1C
    // 0x8004A0C8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x8004A0C8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_0:
    // 0x8004A0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004A0D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004A0D4: jr          $ra
    // 0x8004A0D8: nop

    return;
    // 0x8004A0D8: nop

;}
RECOMP_FUNC void func_8064BC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BC34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064BC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064BC3C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064BC40: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8064BC44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064BC48: blez        $v0, L_8064BC5C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8064BC4C: addiu       $a2, $zero, 0x8
        ctx->r6 = ADD32(0, 0X8);
            goto L_8064BC5C;
    }
    // 0x8064BC4C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8064BC50: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064BC54: b           L_8064BC6C
    // 0x8064BC58: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064BC6C;
    // 0x8064BC58: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064BC5C:
    // 0x8064BC5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064BC60: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064BC64: jal         0x8064BF74
    // 0x8064BC68: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    func_8064BF74(rdram, ctx);
        goto after_0;
    // 0x8064BC68: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    after_0:
L_8064BC6C:
    // 0x8064BC6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064BC70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064BC74: jr          $ra
    // 0x8064BC78: nop

    return;
    // 0x8064BC78: nop

;}
RECOMP_FUNC void func_8003B694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B69C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B6A0: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8003B6A4: addiu       $t6, $zero, 0x69
    ctx->r14 = ADD32(0, 0X69);
    // 0x8003B6A8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003B6AC: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8003B6B0: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8003B6B4: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x8003B6B8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8003B6BC: lw          $t9, -0x1348($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1348);
    // 0x8003B6C0: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8003B6C4: lwc1        $f6, 0x7C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8003B6C8: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x8003B6CC: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8003B6D0: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x8003B6D4: jal         0x80039EAC
    // 0x8003B6D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80039EAC(rdram, ctx);
        goto after_0;
    // 0x8003B6D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003B6DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B6E0: jal         0x8003A060
    // 0x8003B6E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003A060(rdram, ctx);
        goto after_1;
    // 0x8003B6E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8003B6E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B6EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B6F0: jr          $ra
    // 0x8003B6F4: nop

    return;
    // 0x8003B6F4: nop

;}
RECOMP_FUNC void func_8058490C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058490C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584910: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584914: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584918: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058491C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584920: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584924: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584928: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058492C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584930: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584934: jr          $ra
    // 0x80584938: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584938: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8040DDCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040DDCC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040DDD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8040DDD4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8040DDD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040DDDC: jal         0x8040DCF0
    // 0x8040DDE0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    func_8040DCF0(rdram, ctx);
        goto after_0;
    // 0x8040DDE0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x8040DDE4: bne         $v0, $zero, L_8040DDFC
    if (ctx->r2 != 0) {
        // 0x8040DDE8: addiu       $t6, $zero, 0x5
        ctx->r14 = ADD32(0, 0X5);
            goto L_8040DDFC;
    }
    // 0x8040DDE8: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8040DDEC: jal         0x800445A4
    // 0x8040DDF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8040DDF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8040DDF4: b           L_8040DE9C
    // 0x8040DDF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8040DE9C;
    // 0x8040DDF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8040DDFC:
    // 0x8040DDFC: lw          $s1, 0x1F4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040DE00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040DE04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040DE08: sw          $zero, 0x28($s1)
    MEM_W(0X28, ctx->r17) = 0;
    // 0x8040DE0C: sw          $t6, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r14;
    // 0x8040DE10: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x8040DE14: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8040DE18: jal         0x8040E254
    // 0x8040DE1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8040E254(rdram, ctx);
        goto after_2;
    // 0x8040DE1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8040DE20: jal         0x80058958
    // 0x8040DE24: nop

    func_80058958(rdram, ctx);
        goto after_3;
    // 0x8040DE24: nop

    after_3:
    // 0x8040DE28: beq         $v0, $zero, L_8040DE98
    if (ctx->r2 == 0) {
        // 0x8040DE2C: lui         $t7, 0x8010
        ctx->r15 = S32(0X8010 << 16);
            goto L_8040DE98;
    }
    // 0x8040DE2C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8040DE30: lw          $t7, -0x7BC4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7BC4);
    // 0x8040DE34: lw          $t8, 0x10C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10C);
    // 0x8040DE38: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8040DE3C: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x8040DE40: beql        $t0, $zero, L_8040DE9C
    if (ctx->r8 == 0) {
        // 0x8040DE44: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8040DE9C;
    }
    goto skip_0;
    // 0x8040DE44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8040DE48: jal         0x80056564
    // 0x8040DE4C: nop

    func_80056564(rdram, ctx);
        goto after_4;
    // 0x8040DE4C: nop

    after_4:
    // 0x8040DE50: beq         $v0, $zero, L_8040DE98
    if (ctx->r2 == 0) {
        // 0x8040DE54: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_8040DE98;
    }
    // 0x8040DE54: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8040DE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040DE5C: jal         0x800457A0
    // 0x8040DE60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_5;
    // 0x8040DE60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8040DE64: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8040DE68: addiu       $t1, $zero, 0x1F
    ctx->r9 = ADD32(0, 0X1F);
    // 0x8040DE6C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8040DE70: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8040DE74: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8040DE78: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8040DE7C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8040DE80: jal         0x80056584
    // 0x8040DE84: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_80056584(rdram, ctx);
        goto after_6;
    // 0x8040DE84: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_6:
    // 0x8040DE88: lw          $t4, 0x16C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X16C);
    // 0x8040DE8C: lui         $t3, 0x8005
    ctx->r11 = S32(0X8005 << 16);
    // 0x8040DE90: addiu       $t3, $t3, 0x784C
    ctx->r11 = ADD32(ctx->r11, 0X784C);
    // 0x8040DE94: sw          $t3, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r11;
L_8040DE98:
    // 0x8040DE98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8040DE9C:
    // 0x8040DE9C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8040DEA0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8040DEA4: jr          $ra
    // 0x8040DEA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8040DEA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80032DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032DEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032DF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032DF4: jal         0x80021958
    // 0x80032DF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80032DF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80032DFC: bne         $v0, $zero, L_80032E0C
    if (ctx->r2 != 0) {
        // 0x80032E00: nop
    
            goto L_80032E0C;
    }
    // 0x80032E00: nop

    // 0x80032E04: b           L_80032E28
    // 0x80032E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80032E28;
    // 0x80032E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80032E0C:
    // 0x80032E0C: jal         0x80032948
    // 0x80032E10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80032948(rdram, ctx);
        goto after_1;
    // 0x80032E10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80032E14: bnel        $v0, $zero, L_80032E28
    if (ctx->r2 != 0) {
        // 0x80032E18: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80032E28;
    }
    goto skip_0;
    // 0x80032E18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80032E1C: b           L_80032E28
    // 0x80032E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80032E28;
    // 0x80032E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80032E24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80032E28:
    // 0x80032E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032E2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032E30: jr          $ra
    // 0x80032E34: nop

    return;
    // 0x80032E34: nop

;}
RECOMP_FUNC void func_8003EC84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EC84: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003EC88: beq         $a0, $zero, L_8003ECC4
    if (ctx->r4 == 0) {
        // 0x8003EC8C: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_8003ECC4;
    }
    // 0x8003EC8C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8003EC90: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x8003EC94: beq         $at, $zero, L_8003ECC4
    if (ctx->r1 == 0) {
        // 0x8003EC98: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_8003ECC4;
    }
    // 0x8003EC98: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8003EC9C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8003ECA0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8003ECA4: lwc1        $f4, -0x1080($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1080);
    // 0x8003ECA8: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8003ECAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003ECB0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8003ECB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003ECB8: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x8003ECBC: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
    // 0x8003ECC0: swc1        $f8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f8.u32l;
L_8003ECC4:
    // 0x8003ECC4: jr          $ra
    // 0x8003ECC8: nop

    return;
    // 0x8003ECC8: nop

;}
RECOMP_FUNC void func_80071760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071760: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80071764: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071768: addiu       $a0, $a0, -0x5E30
    ctx->r4 = ADD32(ctx->r4, -0X5E30);
    // 0x8007176C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071770: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80071774: jal         0x800824B0
    // 0x80071778: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80071778: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007177C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80071780: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80071784: jal         0x80086880
    // 0x80071788: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    osGetThreadId_recomp(rdram, ctx);
        goto after_1;
    // 0x80071788: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_1:
    // 0x8007178C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80071790: bne         $v0, $at, L_800717A8
    if (ctx->r2 != ctx->r1) {
        // 0x80071794: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800717A8;
    }
    // 0x80071794: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80071798: addiu       $v0, $v0, -0x7B80
    ctx->r2 = ADD32(ctx->r2, -0X7B80);
    // 0x8007179C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800717A0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800717A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800717A8:
    // 0x800717A8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800717AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800717B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800717B4: jr          $ra
    // 0x800717B8: nop

    return;
    // 0x800717B8: nop

;}
RECOMP_FUNC void func_804A1398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1398: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X3170) << 16);
    // 0x804A139C: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804A13A0: lwc1        $f4, 0x35B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X3170));
    // 0x804A13A4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x804A13A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804A13AC: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804A13B0: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X3174) << 16);
    // 0x804A13B4: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x804A13B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804A13BC: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    // 0x804A13C0: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x804A13C4: lwc1        $f10, 0x35B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X3174));
    // 0x804A13C8: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X3178) << 16);
    // 0x804A13CC: lwc1        $f18, 0x35B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X3178));
    // 0x804A13D0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804A13D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804A13D8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x804A13DC: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x804A13E0: jr          $ra
    // 0x804A13E4: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    return;
    // 0x804A13E4: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80057AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057AC0: lh          $a2, 0x8($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X8);
    // 0x80057AC4: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80057AC8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80057ACC: blezl       $a2, L_80057B0C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80057AD0: addiu       $v0, $zero, 0x96
        ctx->r2 = ADD32(0, 0X96);
            goto L_80057B0C;
    }
    goto skip_0;
    // 0x80057AD0: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
    skip_0:
L_80057AD4:
    // 0x80057AD4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80057AD8: beql        $a0, $zero, L_80057AF4
    if (ctx->r4 == 0) {
        // 0x80057ADC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80057AF4;
    }
    goto skip_1;
    // 0x80057ADC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x80057AE0: bnel        $a1, $a0, L_80057AF4
    if (ctx->r5 != ctx->r4) {
        // 0x80057AE4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80057AF4;
    }
    goto skip_2;
    // 0x80057AE4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x80057AE8: jr          $ra
    // 0x80057AEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80057AEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80057AF0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80057AF4:
    // 0x80057AF4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80057AF8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80057AFC: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80057B00: bne         $at, $zero, L_80057AD4
    if (ctx->r1 != 0) {
        // 0x80057B04: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80057AD4;
    }
    // 0x80057B04: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80057B08: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
L_80057B0C:
    // 0x80057B0C: jr          $ra
    // 0x80057B10: nop

    return;
    // 0x80057B10: nop

;}
RECOMP_FUNC void func_80020B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020B78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020B80: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80020B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80020B88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80020B8C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80020B90: jal         0x80049C70
    // 0x80020B94: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80049C70(rdram, ctx);
        goto after_0;
    // 0x80020B94: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80020B98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80020B9C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80020BA0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80020BA4: jal         0x80049C70
    // 0x80020BA8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80049C70(rdram, ctx);
        goto after_1;
    // 0x80020BA8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80020BAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80020BB0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80020BB4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80020BB8: jal         0x80049C70
    // 0x80020BBC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80049C70(rdram, ctx);
        goto after_2;
    // 0x80020BBC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80020BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020BC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020BC8: jr          $ra
    // 0x80020BCC: nop

    return;
    // 0x80020BCC: nop

;}
RECOMP_FUNC void func_80053CF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053CF8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80053CFC: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x80053D00: lui         $a3, 0xE700
    ctx->r7 = S32(0XE700 << 16);
    // 0x80053D04: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80053D08: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80053D0C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80053D10: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80053D14: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80053D18: lui         $t9, 0x1F
    ctx->r25 = S32(0X1F << 16);
    // 0x80053D1C: ori         $t9, $t9, 0x3205
    ctx->r25 = ctx->r25 | 0X3205;
    // 0x80053D20: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80053D24: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80053D28: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x80053D2C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80053D30: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80053D34: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80053D38: lui         $t6, 0x18
    ctx->r14 = S32(0X18 << 16);
    // 0x80053D3C: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x80053D40: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80053D44: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80053D48: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80053D4C: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80053D50: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80053D54: ori         $t5, $t5, 0x18
    ctx->r13 = ctx->r13 | 0X18;
    // 0x80053D58: ori         $t6, $t6, 0x2CB0
    ctx->r14 = ctx->r14 | 0X2CB0;
    // 0x80053D5C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80053D60: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x80053D64: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80053D68: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80053D6C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80053D70: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80053D74: lui         $t2, 0xC18
    ctx->r10 = S32(0XC18 << 16);
    // 0x80053D78: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80053D7C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80053D80: ori         $t2, $t2, 0x4241
    ctx->r10 = ctx->r10 | 0X4241;
    // 0x80053D84: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x80053D88: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80053D8C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80053D90: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80053D94: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x80053D98: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x80053D9C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80053DA0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80053DA4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80053DA8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80053DAC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80053DB0: addiu       $t7, $zero, -0xFF
    ctx->r15 = ADD32(0, -0XFF);
    // 0x80053DB4: lui         $t6, 0xF900
    ctx->r14 = S32(0XF900 << 16);
    // 0x80053DB8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80053DBC: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x80053DC0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80053DC4: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80053DC8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80053DCC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80053DD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053DD4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80053DD8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80053DDC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80053DE0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80053DE4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80053DE8: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x80053DEC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80053DF0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80053DF4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80053DF8: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80053DFC: lbu         $t4, 0x3($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X3);
    // 0x80053E00: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
    // 0x80053E04: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80053E08: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80053E0C: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x80053E10: sll         $t5, $t3, 16
    ctx->r13 = S32(ctx->r11 << 16);
    // 0x80053E14: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80053E18: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x80053E1C: or          $t3, $t6, $t9
    ctx->r11 = ctx->r14 | ctx->r25;
    // 0x80053E20: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80053E24: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80053E28: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80053E2C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80053E30: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80053E34: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80053E38: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x80053E3C: lbu         $t7, 0x7($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X7);
    // 0x80053E40: lbu         $t4, 0x5($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X5);
    // 0x80053E44: sll         $t3, $t9, 24
    ctx->r11 = S32(ctx->r25 << 24);
    // 0x80053E48: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x80053E4C: lbu         $t3, 0x6($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X6);
    // 0x80053E50: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x80053E54: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80053E58: sll         $t5, $t3, 8
    ctx->r13 = S32(ctx->r11 << 8);
    // 0x80053E5C: or          $t4, $t9, $t5
    ctx->r12 = ctx->r25 | ctx->r13;
    // 0x80053E60: beq         $a1, $zero, L_80053E78
    if (ctx->r5 == 0) {
        // 0x80053E64: sw          $t4, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r12;
            goto L_80053E78;
    }
    // 0x80053E64: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80053E68: beq         $a1, $at, L_80053E9C
    if (ctx->r5 == ctx->r1) {
        // 0x80053E6C: lui         $t9, 0xFC32
        ctx->r25 = S32(0XFC32 << 16);
            goto L_80053E9C;
    }
    // 0x80053E6C: lui         $t9, 0xFC32
    ctx->r25 = S32(0XFC32 << 16);
    // 0x80053E70: b           L_80053EC0
    // 0x80053E74: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
        goto L_80053EC0;
    // 0x80053E74: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80053E78:
    // 0x80053E78: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80053E7C: lui         $t6, 0xFC11
    ctx->r14 = S32(0XFC11 << 16);
    // 0x80053E80: ori         $t6, $t6, 0xA7FF
    ctx->r14 = ctx->r14 | 0XA7FF;
    // 0x80053E84: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80053E88: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80053E8C: addiu       $t7, $zero, -0x1C8
    ctx->r15 = ADD32(0, -0X1C8);
    // 0x80053E90: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80053E94: b           L_80053EBC
    // 0x80053E98: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_80053EBC;
    // 0x80053E98: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80053E9C:
    // 0x80053E9C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80053EA0: lui         $t5, 0x1FFC
    ctx->r13 = S32(0X1FFC << 16);
    // 0x80053EA4: ori         $t5, $t5, 0xF438
    ctx->r13 = ctx->r13 | 0XF438;
    // 0x80053EA8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80053EAC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80053EB0: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80053EB4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80053EB8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_80053EBC:
    // 0x80053EBC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80053EC0:
    // 0x80053EC0: lui         $t8, 0xBB00
    ctx->r24 = S32(0XBB00 << 16);
    // 0x80053EC4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80053EC8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80053ECC: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x80053ED0: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x80053ED4: ori         $t8, $t8, 0x1
    ctx->r24 = ctx->r24 | 0X1;
    // 0x80053ED8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80053EDC: jr          $ra
    // 0x80053EE0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    return;
    // 0x80053EE0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8001C4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C4E0: lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // 0x8001C4E4: addiu       $v0, $v0, -0x3B10
    ctx->r2 = ADD32(ctx->r2, -0X3B10);
    // 0x8001C4E8: jr          $ra
    // 0x8001C4EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8001C4EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80433430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433430: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80433434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80433438: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8043343C: jal         0x80047090
    // 0x80433440: addiu       $a0, $zero, 0x40C1
    ctx->r4 = ADD32(0, 0X40C1);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80433440: addiu       $a0, $zero, 0x40C1
    ctx->r4 = ADD32(0, 0X40C1);
    after_0:
    // 0x80433444: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80433448: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x8043344C: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x80433450: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80433454: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80433458: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8043345C: jal         0x8004613C
    // 0x80433460: lui         $a0, 0x40C1
    ctx->r4 = S32(0X40C1 << 16);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80433460: lui         $a0, 0x40C1
    ctx->r4 = S32(0X40C1 << 16);
    after_1:
    // 0x80433464: bne         $v0, $zero, L_80433474
    if (ctx->r2 != 0) {
        // 0x80433468: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80433474;
    }
    // 0x80433468: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8043346C: b           L_804334A0
    // 0x80433470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804334A0;
    // 0x80433470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80433474:
    // 0x80433474: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x80433478: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x8043347C: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80433480: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x80433484: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80433488: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x8043348C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80433490: jal         0x80047F9C
    // 0x80433494: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80433494: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80433498: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8043349C: sb          $zero, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = 0;
L_804334A0:
    // 0x804334A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804334A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804334A8: jr          $ra
    // 0x804334AC: nop

    return;
    // 0x804334AC: nop

;}
RECOMP_FUNC void func_804E9E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E9E7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804E9E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E9E84: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x804E9E88: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804E9E8C: lw          $a0, 0x16C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C);
    // 0x804E9E90: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x804E9E94: jal         0x804E9CC0
    // 0x804E9E98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_804E9CC0(rdram, ctx);
        goto after_0;
    // 0x804E9E98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x804E9E9C: lui         $a1, 0x804F
    ctx->r5 = S32(RELOC_HI16(264, 0X1B0) << 16);
    // 0x804E9EA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804E9EA4: jal         0x804E9C50
    // 0x804E9EA8: addiu       $a1, $a1, -0x64E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(264, 0X1B0));
    func_804E9C50(rdram, ctx);
        goto after_1;
    // 0x804E9EA8: addiu       $a1, $a1, -0x64E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(264, 0X1B0));
    after_1:
    // 0x804E9EAC: beq         $v0, $zero, L_804E9EC0
    if (ctx->r2 == 0) {
        // 0x804E9EB0: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_804E9EC0;
    }
    // 0x804E9EB0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x804E9EB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804E9EB8: nop

    // 0x804E9EBC: swc1        $f4, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f4.u32l;
L_804E9EC0:
    // 0x804E9EC0: lui         $at, 0x804F
    ctx->r1 = S32(RELOC_HI16(264, 0X820) << 16);
    // 0x804E9EC4: lwc1        $f8, -0x5E70($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(264, 0X820));
    // 0x804E9EC8: lwc1        $f6, 0x28($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X28);
    // 0x804E9ECC: lui         $at, 0x804F
    ctx->r1 = S32(RELOC_HI16(264, 0X824) << 16);
    // 0x804E9ED0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x804E9ED4: swc1        $f10, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f10.u32l;
    // 0x804E9ED8: lwc1        $f18, 0x28($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X28);
    // 0x804E9EDC: lwc1        $f16, -0x5E6C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(264, 0X824));
    // 0x804E9EE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804E9EE4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x804E9EE8: nop

    // 0x804E9EEC: bc1fl       L_804E9F04
    if (!c1cs) {
        // 0x804E9EF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804E9F04;
    }
    goto skip_0;
    // 0x804E9EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804E9EF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804E9EF8: nop

    // 0x804E9EFC: swc1        $f4, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f4.u32l;
    // 0x804E9F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804E9F04:
    // 0x804E9F04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804E9F08: jr          $ra
    // 0x804E9F0C: nop

    return;
    // 0x804E9F0C: nop

;}
RECOMP_FUNC void func_80677640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80677640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80677644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80677648: jal         0x806775C4
    // 0x8067764C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806775C4(rdram, ctx);
        goto after_0;
    // 0x8067764C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80677650: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80677654: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80677658: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8067765C: jal         0x80677A88
    // 0x80677660: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80677A88(rdram, ctx);
        goto after_1;
    // 0x80677660: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80677664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80677668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067766C: jr          $ra
    // 0x80677670: nop

    return;
    // 0x80677670: nop

;}
RECOMP_FUNC void func_80533DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533DD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80533DDC: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x80533DE0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80533DE4: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x80533DE8: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x80533DEC: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80533DF0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80533DF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80533DF8: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x80533DFC: addiu       $a3, $v0, 0x20
    ctx->r7 = ADD32(ctx->r2, 0X20);
    // 0x80533E00: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80533E04: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
    // 0x80533E08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80533E0C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80533E10:
    // 0x80533E10: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80533E14: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80533E18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80533E1C: beq         $t1, $zero, L_80533F90
    if (ctx->r9 == 0) {
        // 0x80533E20: lw          $t2, 0x0($a2)
        ctx->r10 = MEM_W(ctx->r6, 0X0);
            goto L_80533F90;
    }
    // 0x80533E20: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80533E24: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x80533E28: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x80533E2C: beq         $at, $zero, L_80533F80
    if (ctx->r1 == 0) {
        // 0x80533E30: or          $t3, $t4, $zero
        ctx->r11 = ctx->r12 | 0;
            goto L_80533F80;
    }
    // 0x80533E30: or          $t3, $t4, $zero
    ctx->r11 = ctx->r12 | 0;
    // 0x80533E34: subu        $s2, $s3, $t4
    ctx->r18 = SUB32(ctx->r19, ctx->r12);
    // 0x80533E38: andi        $s2, $s2, 0x3
    ctx->r18 = ctx->r18 & 0X3;
    // 0x80533E3C: beq         $s2, $zero, L_80533E98
    if (ctx->r18 == 0) {
        // 0x80533E40: addu        $s0, $s2, $t4
        ctx->r16 = ADD32(ctx->r18, ctx->r12);
            goto L_80533E98;
    }
    // 0x80533E40: addu        $s0, $s2, $t4
    ctx->r16 = ADD32(ctx->r18, ctx->r12);
    // 0x80533E44: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80533E48: addu        $s1, $a3, $t5
    ctx->r17 = ADD32(ctx->r7, ctx->r13);
L_80533E4C:
    // 0x80533E4C: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x80533E50: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80533E54: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80533E58: beq         $s2, $zero, L_80533E8C
    if (ctx->r18 == 0) {
        // 0x80533E5C: nop
    
            goto L_80533E8C;
    }
    // 0x80533E5C: nop

    // 0x80533E60: bne         $t1, $s2, L_80533E7C
    if (ctx->r9 != ctx->r18) {
        // 0x80533E64: addu        $t4, $v0, $t5
        ctx->r12 = ADD32(ctx->r2, ctx->r13);
            goto L_80533E7C;
    }
    // 0x80533E64: addu        $t4, $v0, $t5
    ctx->r12 = ADD32(ctx->r2, ctx->r13);
    // 0x80533E68: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80533E6C: bne         $t2, $t6, L_80533E8C
    if (ctx->r10 != ctx->r14) {
        // 0x80533E70: nop
    
            goto L_80533E8C;
    }
    // 0x80533E70: nop

    // 0x80533E74: b           L_80533E8C
    // 0x80533E78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_80533E8C;
    // 0x80533E78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80533E7C:
    // 0x80533E7C: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x80533E80: bne         $t2, $t7, L_80533E8C
    if (ctx->r10 != ctx->r15) {
        // 0x80533E84: nop
    
            goto L_80533E8C;
    }
    // 0x80533E84: nop

    // 0x80533E88: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80533E8C:
    // 0x80533E8C: bne         $s0, $t3, L_80533E4C
    if (ctx->r16 != ctx->r11) {
        // 0x80533E90: addiu       $t5, $t5, 0x4
        ctx->r13 = ADD32(ctx->r13, 0X4);
            goto L_80533E4C;
    }
    // 0x80533E90: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x80533E94: beq         $t3, $s3, L_80533F80
    if (ctx->r11 == ctx->r19) {
        // 0x80533E98: sll         $t5, $t3, 2
        ctx->r13 = S32(ctx->r11 << 2);
            goto L_80533F80;
    }
L_80533E98:
    // 0x80533E98: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80533E9C: addu        $s1, $a3, $t5
    ctx->r17 = ADD32(ctx->r7, ctx->r13);
L_80533EA0:
    // 0x80533EA0: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x80533EA4: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80533EA8: addu        $t7, $v0, $t5
    ctx->r15 = ADD32(ctx->r2, ctx->r13);
    // 0x80533EAC: beql        $s2, $zero, L_80533EE4
    if (ctx->r18 == 0) {
        // 0x80533EB0: lw          $t4, 0x4($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X4);
            goto L_80533EE4;
    }
    goto skip_0;
    // 0x80533EB0: lw          $t4, 0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4);
    skip_0:
    // 0x80533EB4: bne         $t1, $s2, L_80533ED0
    if (ctx->r9 != ctx->r18) {
        // 0x80533EB8: addu        $t4, $v0, $t5
        ctx->r12 = ADD32(ctx->r2, ctx->r13);
            goto L_80533ED0;
    }
    // 0x80533EB8: addu        $t4, $v0, $t5
    ctx->r12 = ADD32(ctx->r2, ctx->r13);
    // 0x80533EBC: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80533EC0: bnel        $t2, $t8, L_80533EE4
    if (ctx->r10 != ctx->r24) {
        // 0x80533EC4: lw          $t4, 0x4($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X4);
            goto L_80533EE4;
    }
    goto skip_1;
    // 0x80533EC4: lw          $t4, 0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4);
    skip_1:
    // 0x80533EC8: b           L_80533EE0
    // 0x80533ECC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_80533EE0;
    // 0x80533ECC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80533ED0:
    // 0x80533ED0: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x80533ED4: bnel        $t2, $t9, L_80533EE4
    if (ctx->r10 != ctx->r25) {
        // 0x80533ED8: lw          $t4, 0x4($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X4);
            goto L_80533EE4;
    }
    goto skip_2;
    // 0x80533ED8: lw          $t4, 0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4);
    skip_2:
    // 0x80533EDC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80533EE0:
    // 0x80533EE0: lw          $t4, 0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4);
L_80533EE4:
    // 0x80533EE4: addu        $t8, $v0, $t5
    ctx->r24 = ADD32(ctx->r2, ctx->r13);
    // 0x80533EE8: beql        $t4, $zero, L_80533F18
    if (ctx->r12 == 0) {
        // 0x80533EEC: lw          $t4, 0x8($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X8);
            goto L_80533F18;
    }
    goto skip_3;
    // 0x80533EEC: lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X8);
    skip_3:
    // 0x80533EF0: bne         $t1, $t4, L_80533F08
    if (ctx->r9 != ctx->r12) {
        // 0x80533EF4: lw          $t3, 0x4($t6)
        ctx->r11 = MEM_W(ctx->r14, 0X4);
            goto L_80533F08;
    }
    // 0x80533EF4: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x80533EF8: bnel        $t2, $t3, L_80533F18
    if (ctx->r10 != ctx->r11) {
        // 0x80533EFC: lw          $t4, 0x8($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X8);
            goto L_80533F18;
    }
    goto skip_4;
    // 0x80533EFC: lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X8);
    skip_4:
    // 0x80533F00: b           L_80533F14
    // 0x80533F04: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_80533F14;
    // 0x80533F04: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80533F08:
    // 0x80533F08: bnel        $t2, $t3, L_80533F18
    if (ctx->r10 != ctx->r11) {
        // 0x80533F0C: lw          $t4, 0x8($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X8);
            goto L_80533F18;
    }
    goto skip_5;
    // 0x80533F0C: lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X8);
    skip_5:
    // 0x80533F10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80533F14:
    // 0x80533F14: lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X8);
L_80533F18:
    // 0x80533F18: addiu       $t5, $t5, 0x10
    ctx->r13 = ADD32(ctx->r13, 0X10);
    // 0x80533F1C: beql        $t4, $zero, L_80533F4C
    if (ctx->r12 == 0) {
        // 0x80533F20: lw          $t4, 0xC($s1)
        ctx->r12 = MEM_W(ctx->r17, 0XC);
            goto L_80533F4C;
    }
    goto skip_6;
    // 0x80533F20: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    skip_6:
    // 0x80533F24: bne         $t1, $t4, L_80533F3C
    if (ctx->r9 != ctx->r12) {
        // 0x80533F28: lw          $t3, 0x8($t7)
        ctx->r11 = MEM_W(ctx->r15, 0X8);
            goto L_80533F3C;
    }
    // 0x80533F28: lw          $t3, 0x8($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X8);
    // 0x80533F2C: bnel        $t2, $t3, L_80533F4C
    if (ctx->r10 != ctx->r11) {
        // 0x80533F30: lw          $t4, 0xC($s1)
        ctx->r12 = MEM_W(ctx->r17, 0XC);
            goto L_80533F4C;
    }
    goto skip_7;
    // 0x80533F30: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    skip_7:
    // 0x80533F34: b           L_80533F48
    // 0x80533F38: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_80533F48;
    // 0x80533F38: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80533F3C:
    // 0x80533F3C: bnel        $t2, $t3, L_80533F4C
    if (ctx->r10 != ctx->r11) {
        // 0x80533F40: lw          $t4, 0xC($s1)
        ctx->r12 = MEM_W(ctx->r17, 0XC);
            goto L_80533F4C;
    }
    goto skip_8;
    // 0x80533F40: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    skip_8:
    // 0x80533F44: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80533F48:
    // 0x80533F48: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
L_80533F4C:
    // 0x80533F4C: beq         $t4, $zero, L_80533F78
    if (ctx->r12 == 0) {
        // 0x80533F50: nop
    
            goto L_80533F78;
    }
    // 0x80533F50: nop

    // 0x80533F54: bne         $t1, $t4, L_80533F6C
    if (ctx->r9 != ctx->r12) {
        // 0x80533F58: lw          $t3, 0xC($t8)
        ctx->r11 = MEM_W(ctx->r24, 0XC);
            goto L_80533F6C;
    }
    // 0x80533F58: lw          $t3, 0xC($t8)
    ctx->r11 = MEM_W(ctx->r24, 0XC);
    // 0x80533F5C: bne         $t2, $t3, L_80533F78
    if (ctx->r10 != ctx->r11) {
        // 0x80533F60: nop
    
            goto L_80533F78;
    }
    // 0x80533F60: nop

    // 0x80533F64: b           L_80533F78
    // 0x80533F68: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_80533F78;
    // 0x80533F68: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80533F6C:
    // 0x80533F6C: bne         $t2, $t3, L_80533F78
    if (ctx->r10 != ctx->r11) {
        // 0x80533F70: nop
    
            goto L_80533F78;
    }
    // 0x80533F70: nop

    // 0x80533F74: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80533F78:
    // 0x80533F78: bne         $t5, $s4, L_80533EA0
    if (ctx->r13 != ctx->r20) {
        // 0x80533F7C: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80533EA0;
    }
    // 0x80533F7C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_80533F80:
    // 0x80533F80: slt         $at, $t0, $a0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80533F84: beql        $at, $zero, L_80533F94
    if (ctx->r1 == 0) {
        // 0x80533F88: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80533F94;
    }
    goto skip_9;
    // 0x80533F88: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_9:
    // 0x80533F8C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_80533F90:
    // 0x80533F90: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80533F94:
    // 0x80533F94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80533F98: bne         $v1, $at, L_80533E10
    if (ctx->r3 != ctx->r1) {
        // 0x80533F9C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80533E10;
    }
    // 0x80533F9C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80533FA0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80533FA4: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x80533FA8: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80533FAC: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x80533FB0: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x80533FB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80533FB8: jr          $ra
    // 0x80533FBC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x80533FBC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void func_805557C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805557C0: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x805557C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805557C8: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x805557CC: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x805557D0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x805557D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805557D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805557DC: jal         0x8004921C
    // 0x805557E0: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x805557E0: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    after_0:
    // 0x805557E4: sh          $v0, 0xDA($sp)
    MEM_H(0XDA, ctx->r29) = ctx->r2;
    // 0x805557E8: lw          $a0, 0xE4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE4);
    // 0x805557EC: jal         0x8004921C
    // 0x805557F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x805557F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x805557F4: lh          $t3, 0xDA($sp)
    ctx->r11 = MEM_H(ctx->r29, 0XDA);
    // 0x805557F8: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x805557FC: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x80555800: andi        $t8, $t3, 0xFF
    ctx->r24 = ctx->r11 & 0XFF;
    // 0x80555804: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80555808: sh          $v0, 0xD8($sp)
    MEM_H(0XD8, ctx->r29) = ctx->r2;
    // 0x8055580C: lbu         $t7, 0x145($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X145);
    // 0x80555810: lw          $t9, 0x168($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X168);
    // 0x80555814: lw          $a0, 0x16C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X16C);
    // 0x80555818: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8055581C: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x80555820: addiu       $t0, $a0, 0xD
    ctx->r8 = ADD32(ctx->r4, 0XD);
    // 0x80555824: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    // 0x80555828: mflo        $t6
    ctx->r14 = lo;
    // 0x8055582C: nop

    // 0x80555830: nop

    // 0x80555834: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80555838: lw          $t6, 0x80($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X80);
    // 0x8055583C: mflo        $t8
    ctx->r24 = lo;
    // 0x80555840: addu        $t2, $t6, $t8
    ctx->r10 = ADD32(ctx->r14, ctx->r24);
    // 0x80555844: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x80555848: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8055584C: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x80555850: mflo        $v1
    ctx->r3 = lo;
    // 0x80555854: addu        $a1, $t2, $v1
    ctx->r5 = ADD32(ctx->r10, ctx->r3);
    // 0x80555858: addu        $t7, $a1, $v1
    ctx->r15 = ADD32(ctx->r5, ctx->r3);
    // 0x8055585C: sw          $a1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r5;
    // 0x80555860: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x80555864: lw          $t9, 0x1F4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X1F4);
    // 0x80555868: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x8055586C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80555870: sw          $t9, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r25;
    // 0x80555874: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80555878: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x8055587C: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x80555880: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x80555884: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x80555888: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8055588C: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x80555890: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x80555894: ori         $t7, $t7, 0xAC80
    ctx->r15 = ctx->r15 | 0XAC80;
    // 0x80555898: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8055589C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x805558A0: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x805558A4: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x805558A8: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x805558AC: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x805558B0: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x805558B4: ori         $a1, $a1, 0x5248
    ctx->r5 = ctx->r5 | 0X5248;
    // 0x805558B8: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x805558BC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x805558C0: sw          $a1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r5;
    // 0x805558C4: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x805558C8: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x805558CC: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x805558D0: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x805558D4: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x805558D8: sw          $a1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r5;
    // 0x805558DC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805558E0: sw          $t2, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r10;
    // 0x805558E4: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x805558E8: jal         0x8007711C
    // 0x805558EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8007711C(rdram, ctx);
        goto after_2;
    // 0x805558EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x805558F0: lw          $v0, 0xDC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XDC);
    // 0x805558F4: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x805558F8: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x805558FC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80555900: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80555904: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80555908: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8055590C: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x80555910: lbu         $t8, 0x3($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X3);
    // 0x80555914: addiu       $a3, $t1, 0x84
    ctx->r7 = ADD32(ctx->r9, 0X84);
    // 0x80555918: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x8055591C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80555920: lbu         $t8, 0x1($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X1);
    // 0x80555924: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80555928: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8055592C: lbu         $t7, 0x2($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X2);
    // 0x80555930: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x80555934: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80555938: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8055593C: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x80555940: lui         $t8, 0xFF2F
    ctx->r24 = S32(0XFF2F << 16);
    // 0x80555944: lui         $t6, 0xFC11
    ctx->r14 = S32(0XFC11 << 16);
    // 0x80555948: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8055594C: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x80555950: ori         $t6, $t6, 0x9623
    ctx->r14 = ctx->r14 | 0X9623;
    // 0x80555954: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x80555958: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8055595C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80555960: lh          $a2, 0xD8($sp)
    ctx->r6 = MEM_H(ctx->r29, 0XD8);
    // 0x80555964: lh          $a1, 0xDA($sp)
    ctx->r5 = MEM_H(ctx->r29, 0XDA);
    // 0x80555968: jal         0x805552EC
    // 0x8055596C: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    func_805552EC(rdram, ctx);
        goto after_3;
    // 0x8055596C: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    after_3:
    // 0x80555970: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x80555974: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x80555978: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8055597C: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80555980: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x80555984: ori         $t6, $t6, 0x81FF
    ctx->r14 = ctx->r14 | 0X81FF;
    // 0x80555988: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8055598C: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x80555990: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80555994: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x80555998: addiu       $t7, $t8, 0x348
    ctx->r15 = ADD32(ctx->r24, 0X348);
    // 0x8055599C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x805559A0: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x805559A4: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x805559A8: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x805559AC: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x805559B0: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x805559B4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x805559B8: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x805559BC: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x805559C0: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x805559C4: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x805559C8: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x805559CC: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x805559D0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805559D4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x805559D8: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x805559DC: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x805559E0: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x805559E4: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x805559E8: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x805559EC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805559F0: lw          $t4, 0xDC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XDC);
    // 0x805559F4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x805559F8: lh          $v1, 0xDA($sp)
    ctx->r3 = MEM_H(ctx->r29, 0XDA);
    // 0x805559FC: addiu       $t7, $t4, 0x8
    ctx->r15 = ADD32(ctx->r12, 0X8);
    // 0x80555A00: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80555A04: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80555A08: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80555A0C: lh          $t6, 0xD8($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XD8);
    // 0x80555A10: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x80555A14: addiu       $t5, $t3, 0x7
    ctx->r13 = ADD32(ctx->r11, 0X7);
    // 0x80555A18: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80555A1C: sra         $t5, $t5, 3
    ctx->r13 = S32(SIGNED(ctx->r13) >> 3);
    // 0x80555A20: andi        $t5, $t5, 0x1FF
    ctx->r13 = ctx->r13 & 0X1FF;
    // 0x80555A24: mflo        $t2
    ctx->r10 = lo;
    // 0x80555A28: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80555A2C: sra         $t2, $t2, 1
    ctx->r10 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80555A30: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80555A34: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x80555A38: beq         $at, $zero, L_80555A48
    if (ctx->r1 == 0) {
        // 0x80555A3C: nop
    
            goto L_80555A48;
    }
    // 0x80555A3C: nop

    // 0x80555A40: b           L_80555A48
    // 0x80555A44: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_80555A48;
    // 0x80555A44: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_80555A48:
    // 0x80555A48: bgez        $t3, L_80555A58
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80555A4C: sra         $a2, $t3, 3
        ctx->r6 = S32(SIGNED(ctx->r11) >> 3);
            goto L_80555A58;
    }
    // 0x80555A4C: sra         $a2, $t3, 3
    ctx->r6 = S32(SIGNED(ctx->r11) >> 3);
    // 0x80555A50: addiu       $at, $t3, 0x7
    ctx->r1 = ADD32(ctx->r11, 0X7);
    // 0x80555A54: sra         $a2, $at, 3
    ctx->r6 = S32(SIGNED(ctx->r1) >> 3);
L_80555A58:
    // 0x80555A58: bgtz        $a2, L_80555A68
    if (SIGNED(ctx->r6) > 0) {
        // 0x80555A5C: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_80555A68;
    }
    // 0x80555A5C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80555A60: b           L_80555A68
    // 0x80555A64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80555A68;
    // 0x80555A64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80555A68:
    // 0x80555A68: bgtz        $a2, L_80555A78
    if (SIGNED(ctx->r6) > 0) {
        // 0x80555A6C: addiu       $t8, $a3, 0x7FF
        ctx->r24 = ADD32(ctx->r7, 0X7FF);
            goto L_80555A78;
    }
    // 0x80555A6C: addiu       $t8, $a3, 0x7FF
    ctx->r24 = ADD32(ctx->r7, 0X7FF);
    // 0x80555A70: b           L_80555A7C
    // 0x80555A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80555A7C;
    // 0x80555A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80555A78:
    // 0x80555A78: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80555A7C:
    // 0x80555A7C: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x80555A80: bne         $v0, $zero, L_80555A8C
    if (ctx->r2 != 0) {
        // 0x80555A84: nop
    
            goto L_80555A8C;
    }
    // 0x80555A84: nop

    // 0x80555A88: break       7
    do_break(2153077384);
L_80555A8C:
    // 0x80555A8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80555A90: bne         $v0, $at, L_80555AA4
    if (ctx->r2 != ctx->r1) {
        // 0x80555A94: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80555AA4;
    }
    // 0x80555A94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80555A98: bne         $t8, $at, L_80555AA4
    if (ctx->r24 != ctx->r1) {
        // 0x80555A9C: nop
    
            goto L_80555AA4;
    }
    // 0x80555A9C: nop

    // 0x80555AA0: break       6
    do_break(2153077408);
L_80555AA4:
    // 0x80555AA4: mflo        $t7
    ctx->r15 = lo;
    // 0x80555AA8: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80555AAC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80555AB0: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x80555AB4: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80555AB8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80555ABC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80555AC0: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x80555AC4: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x80555AC8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80555ACC: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80555AD0: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80555AD4: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x80555AD8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80555ADC: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80555AE0: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x80555AE4: sll         $t5, $t5, 9
    ctx->r13 = S32(ctx->r13 << 9);
    // 0x80555AE8: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
    // 0x80555AEC: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x80555AF0: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x80555AF4: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80555AF8: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x80555AFC: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x80555B00: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80555B04: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x80555B08: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80555B0C: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80555B10: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80555B14: lh          $t8, 0xDA($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XDA);
    // 0x80555B18: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80555B1C: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x80555B20: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80555B24: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80555B28: lh          $t6, 0xD8($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XD8);
    // 0x80555B2C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80555B30: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80555B34: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80555B38: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80555B3C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80555B40: or          $ra, $t8, $t6
    ctx->r31 = ctx->r24 | ctx->r14;
    // 0x80555B44: sw          $ra, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r31;
    // 0x80555B48: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x80555B4C: lui         $t6, 0x8055
    ctx->r14 = S32(RELOC_HI16(357, 0X1900) << 16);
    // 0x80555B50: addiu       $t6, $t6, 0x67F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(357, 0X1900));
    // 0x80555B54: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80555B58: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x80555B5C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80555B60: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80555B64: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80555B68: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
    // 0x80555B6C: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x80555B70: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x80555B74: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x80555B78: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80555B7C: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x80555B80: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80555B84: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80555B88: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80555B8C: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x80555B90: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80555B94: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x80555B98: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80555B9C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80555BA0: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80555BA4: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x80555BA8: sw          $t4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r12;
    // 0x80555BAC: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80555BB0: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x80555BB4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80555BB8: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80555BBC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80555BC0: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80555BC4: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80555BC8: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80555BCC: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x80555BD0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80555BD4: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x80555BD8: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80555BDC: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x80555BE0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80555BE4: beq         $at, $zero, L_80555BF4
    if (ctx->r1 == 0) {
        // 0x80555BE8: or          $t3, $t8, $zero
        ctx->r11 = ctx->r24 | 0;
            goto L_80555BF4;
    }
    // 0x80555BE8: or          $t3, $t8, $zero
    ctx->r11 = ctx->r24 | 0;
    // 0x80555BEC: b           L_80555BF4
    // 0x80555BF0: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_80555BF4;
    // 0x80555BF0: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_80555BF4:
    // 0x80555BF4: bgtz        $a2, L_80555C04
    if (SIGNED(ctx->r6) > 0) {
        // 0x80555BF8: nop
    
            goto L_80555C04;
    }
    // 0x80555BF8: nop

    // 0x80555BFC: b           L_80555C04
    // 0x80555C00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80555C04;
    // 0x80555C00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80555C04:
    // 0x80555C04: bgtz        $a2, L_80555C14
    if (SIGNED(ctx->r6) > 0) {
        // 0x80555C08: addiu       $t9, $a3, 0x7FF
        ctx->r25 = ADD32(ctx->r7, 0X7FF);
            goto L_80555C14;
    }
    // 0x80555C08: addiu       $t9, $a3, 0x7FF
    ctx->r25 = ADD32(ctx->r7, 0X7FF);
    // 0x80555C0C: b           L_80555C14
    // 0x80555C10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80555C14;
    // 0x80555C10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80555C14:
    // 0x80555C14: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x80555C18: mflo        $t8
    ctx->r24 = lo;
    // 0x80555C1C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80555C20: bne         $v0, $zero, L_80555C2C
    if (ctx->r2 != 0) {
        // 0x80555C24: nop
    
            goto L_80555C2C;
    }
    // 0x80555C24: nop

    // 0x80555C28: break       7
    do_break(2153077800);
L_80555C2C:
    // 0x80555C2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80555C30: bne         $v0, $at, L_80555C44
    if (ctx->r2 != ctx->r1) {
        // 0x80555C34: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80555C44;
    }
    // 0x80555C34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80555C38: bne         $t9, $at, L_80555C44
    if (ctx->r25 != ctx->r1) {
        // 0x80555C3C: nop
    
            goto L_80555C44;
    }
    // 0x80555C3C: nop

    // 0x80555C40: break       6
    do_break(2153077824);
L_80555C44:
    // 0x80555C44: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x80555C48: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80555C4C: or          $t7, $t6, $t4
    ctx->r15 = ctx->r14 | ctx->r12;
    // 0x80555C50: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80555C54: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80555C58: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x80555C5C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80555C60: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x80555C64: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80555C68: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80555C6C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80555C70: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80555C74: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x80555C78: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x80555C7C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80555C80: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80555C84: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x80555C88: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80555C8C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80555C90: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x80555C94: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80555C98: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80555C9C: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x80555CA0: sw          $ra, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r31;
    // 0x80555CA4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80555CA8: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x80555CAC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80555CB0: lui         $t6, 0x8055
    ctx->r14 = S32(RELOC_HI16(357, 0X1918) << 16);
    // 0x80555CB4: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80555CB8: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80555CBC: addiu       $t6, $t6, 0x6808
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(357, 0X1918));
    // 0x80555CC0: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80555CC4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80555CC8: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80555CCC: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x80555CD0: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x80555CD4: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x80555CD8: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80555CDC: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80555CE0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80555CE4: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x80555CE8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80555CEC: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x80555CF0: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80555CF4: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x80555CF8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80555CFC: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80555D00: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80555D04: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x80555D08: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80555D0C: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x80555D10: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x80555D14: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80555D18: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80555D1C: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x80555D20: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80555D24: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80555D28: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x80555D2C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80555D30: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80555D34: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80555D38: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x80555D3C: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x80555D40: beq         $at, $zero, L_80555D50
    if (ctx->r1 == 0) {
        // 0x80555D44: or          $t3, $t8, $zero
        ctx->r11 = ctx->r24 | 0;
            goto L_80555D50;
    }
    // 0x80555D44: or          $t3, $t8, $zero
    ctx->r11 = ctx->r24 | 0;
    // 0x80555D48: b           L_80555D50
    // 0x80555D4C: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_80555D50;
    // 0x80555D4C: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_80555D50:
    // 0x80555D50: bgtz        $a2, L_80555D60
    if (SIGNED(ctx->r6) > 0) {
        // 0x80555D54: nop
    
            goto L_80555D60;
    }
    // 0x80555D54: nop

    // 0x80555D58: b           L_80555D60
    // 0x80555D5C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80555D60;
    // 0x80555D5C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80555D60:
    // 0x80555D60: bgtz        $a2, L_80555D70
    if (SIGNED(ctx->r6) > 0) {
        // 0x80555D64: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_80555D70;
    }
    // 0x80555D64: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x80555D68: b           L_80555D70
    // 0x80555D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80555D70;
    // 0x80555D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80555D70:
    // 0x80555D70: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x80555D74: mflo        $t8
    ctx->r24 = lo;
    // 0x80555D78: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80555D7C: bne         $v0, $zero, L_80555D88
    if (ctx->r2 != 0) {
        // 0x80555D80: nop
    
            goto L_80555D88;
    }
    // 0x80555D80: nop

    // 0x80555D84: break       7
    do_break(2153078148);
L_80555D88:
    // 0x80555D88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80555D8C: bne         $v0, $at, L_80555DA0
    if (ctx->r2 != ctx->r1) {
        // 0x80555D90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80555DA0;
    }
    // 0x80555D90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80555D94: bne         $t7, $at, L_80555DA0
    if (ctx->r15 != ctx->r1) {
        // 0x80555D98: nop
    
            goto L_80555DA0;
    }
    // 0x80555D98: nop

    // 0x80555D9C: break       6
    do_break(2153078172);
L_80555DA0:
    // 0x80555DA0: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x80555DA4: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80555DA8: or          $t9, $t6, $t4
    ctx->r25 = ctx->r14 | ctx->r12;
    // 0x80555DAC: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80555DB0: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80555DB4: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x80555DB8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80555DBC: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80555DC0: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x80555DC4: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80555DC8: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80555DCC: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x80555DD0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80555DD4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80555DD8: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80555DDC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80555DE0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80555DE4: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x80555DE8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80555DEC: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80555DF0: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x80555DF4: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x80555DF8: sw          $ra, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r31;
    // 0x80555DFC: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x80555E00: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x80555E04: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80555E08: lui         $t6, 0x8055
    ctx->r14 = S32(RELOC_HI16(357, 0X1980) << 16);
    // 0x80555E0C: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80555E10: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x80555E14: addiu       $t6, $t6, 0x6870
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(357, 0X1980));
    // 0x80555E18: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80555E1C: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80555E20: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80555E24: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80555E28: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x80555E2C: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x80555E30: sw          $t7, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r15;
    // 0x80555E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80555E38: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x80555E3C: jr          $ra
    // 0x80555E40: nop

    return;
    // 0x80555E40: nop

;}
RECOMP_FUNC void func_800103EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800103EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800103F0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800103F4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800103F8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800103FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010400: addiu       $v0, $v0, -0x64A0
    ctx->r2 = ADD32(ctx->r2, -0X64A0);
    // 0x80010404: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80010408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001040C:
    // 0x8001040C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80010410: sw          $v0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r2;
    // 0x80010414: sw          $v0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r2;
    // 0x80010418: sw          $v0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r2;
    // 0x8001041C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80010420: bne         $a1, $a0, L_8001040C
    if (ctx->r5 != ctx->r4) {
        // 0x80010424: sw          $v0, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->r2;
            goto L_8001040C;
    }
    // 0x80010424: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
    // 0x80010428: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x8001042C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80010430: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80010434: andi        $t8, $t6, 0xFF7F
    ctx->r24 = ctx->r14 & 0XFF7F;
    // 0x80010438: andi        $t0, $t8, 0xDF
    ctx->r8 = ctx->r24 & 0XDF;
    // 0x8001043C: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x80010440: andi        $t2, $t0, 0xF7
    ctx->r10 = ctx->r8 & 0XF7;
    // 0x80010444: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    // 0x80010448: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x8001044C: andi        $t3, $t2, 0xEF
    ctx->r11 = ctx->r10 & 0XEF;
    // 0x80010450: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x80010454: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80010458: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001045C:
    // 0x8001045C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80010460: sb          $v0, 0x155($v1)
    MEM_B(0X155, ctx->r3) = ctx->r2;
    // 0x80010464: sb          $v0, 0x156($v1)
    MEM_B(0X156, ctx->r3) = ctx->r2;
    // 0x80010468: sb          $v0, 0x157($v1)
    MEM_B(0X157, ctx->r3) = ctx->r2;
    // 0x8001046C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80010470: bne         $a0, $a1, L_8001045C
    if (ctx->r4 != ctx->r5) {
        // 0x80010474: sb          $v0, 0x150($v1)
        MEM_B(0X150, ctx->r3) = ctx->r2;
            goto L_8001045C;
    }
    // 0x80010474: sb          $v0, 0x150($v1)
    MEM_B(0X150, ctx->r3) = ctx->r2;
    // 0x80010478: addiu       $t4, $zero, 0x60
    ctx->r12 = ADD32(0, 0X60);
    // 0x8001047C: sb          $t4, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r12;
    // 0x80010480: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80010484: jal         0x8000BDA0
    // 0x80010488: addiu       $a0, $a2, 0x98
    ctx->r4 = ADD32(ctx->r6, 0X98);
    func_8000BDA0(rdram, ctx);
        goto after_0;
    // 0x80010488: addiu       $a0, $a2, 0x98
    ctx->r4 = ADD32(ctx->r6, 0X98);
    after_0:
    // 0x8001048C: jal         0x80010230
    // 0x80010490: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80010230(rdram, ctx);
        goto after_1;
    // 0x80010490: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80010494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001049C: jr          $ra
    // 0x800104A0: nop

    return;
    // 0x800104A0: nop

;}
RECOMP_FUNC void func_806CB720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CB720: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x806CB724: addiu       $at, $zero, 0x45A1
    ctx->r1 = ADD32(0, 0X45A1);
    // 0x806CB728: beq         $v0, $at, L_806CB750
    if (ctx->r2 == ctx->r1) {
        // 0x806CB72C: addiu       $at, $zero, 0x45A2
        ctx->r1 = ADD32(0, 0X45A2);
            goto L_806CB750;
    }
    // 0x806CB72C: addiu       $at, $zero, 0x45A2
    ctx->r1 = ADD32(0, 0X45A2);
    // 0x806CB730: beq         $v0, $at, L_806CB75C
    if (ctx->r2 == ctx->r1) {
        // 0x806CB734: addiu       $at, $zero, 0x45A3
        ctx->r1 = ADD32(0, 0X45A3);
            goto L_806CB75C;
    }
    // 0x806CB734: addiu       $at, $zero, 0x45A3
    ctx->r1 = ADD32(0, 0X45A3);
    // 0x806CB738: beq         $v0, $at, L_806CB774
    if (ctx->r2 == ctx->r1) {
        // 0x806CB73C: addiu       $at, $zero, 0x45A4
        ctx->r1 = ADD32(0, 0X45A4);
            goto L_806CB774;
    }
    // 0x806CB73C: addiu       $at, $zero, 0x45A4
    ctx->r1 = ADD32(0, 0X45A4);
    // 0x806CB740: beq         $v0, $at, L_806CB768
    if (ctx->r2 == ctx->r1) {
        // 0x806CB744: nop
    
            goto L_806CB768;
    }
    // 0x806CB744: nop

    // 0x806CB748: b           L_806CB780
    // 0x806CB74C: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(604, 0X3444) << 16);
        goto L_806CB780;
    // 0x806CB74C: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(604, 0X3444) << 16);
L_806CB750:
    // 0x806CB750: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(604, 0X3444) << 16);
    // 0x806CB754: jr          $ra
    // 0x806CB758: addiu       $v0, $v0, -0x149C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(604, 0X3444));
    return;
    // 0x806CB758: addiu       $v0, $v0, -0x149C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(604, 0X3444));
L_806CB75C:
    // 0x806CB75C: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(604, 0X3560) << 16);
    // 0x806CB760: jr          $ra
    // 0x806CB764: addiu       $v0, $v0, -0x1380
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(604, 0X3560));
    return;
    // 0x806CB764: addiu       $v0, $v0, -0x1380
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(604, 0X3560));
L_806CB768:
    // 0x806CB768: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(604, 0X3598) << 16);
    // 0x806CB76C: jr          $ra
    // 0x806CB770: addiu       $v0, $v0, -0x1348
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(604, 0X3598));
    return;
    // 0x806CB770: addiu       $v0, $v0, -0x1348
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(604, 0X3598));
L_806CB774:
    // 0x806CB774: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(604, 0X35E4) << 16);
    // 0x806CB778: jr          $ra
    // 0x806CB77C: addiu       $v0, $v0, -0x12FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(604, 0X35E4));
    return;
    // 0x806CB77C: addiu       $v0, $v0, -0x12FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(604, 0X35E4));
L_806CB780:
    // 0x806CB780: addiu       $v0, $v0, -0x149C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(604, 0X3444));
    // 0x806CB784: jr          $ra
    // 0x806CB788: nop

    return;
    // 0x806CB788: nop

;}
RECOMP_FUNC void func_807A1F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A1F38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A1F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A1F40: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x807A1F44: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807A1F48: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(844, 0X174) << 16);
    // 0x807A1F4C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x807A1F50: addiu       $t7, $t7, 0x2044
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(844, 0X174));
    // 0x807A1F54: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x807A1F58: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807A1F5C: sw          $t9, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r25;
    // 0x807A1F60: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807A1F64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807A1F68: jal         0x807A1F90
    // 0x807A1F6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_807A1F90(rdram, ctx);
        goto after_0;
    // 0x807A1F6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x807A1F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A1F74: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807A1F78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807A1F7C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x807A1F80: jr          $ra
    // 0x807A1F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x807A1F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002FC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FC7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FC80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FC84: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FC88: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FC8C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002FC90: jal         0x8002F678
    // 0x8002FC94: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FC94: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FC98: beq         $v0, $zero, L_8002FCAC
    if (ctx->r2 == 0) {
        // 0x8002FC9C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FCAC;
    }
    // 0x8002FC9C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FCA0: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FCA4: addiu       $t6, $t6, -0x173C
    ctx->r14 = ADD32(ctx->r14, -0X173C);
    // 0x8002FCA8: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FCAC:
    // 0x8002FCAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FCB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FCB4: jr          $ra
    // 0x8002FCB8: nop

    return;
    // 0x8002FCB8: nop

;}
RECOMP_FUNC void func_80026E44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026E44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80026E48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026E4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80026E50: jal         0x80024840
    // 0x80026E54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80024840(rdram, ctx);
        goto after_0;
    // 0x80026E54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80026E58: beq         $v0, $zero, L_80026E90
    if (ctx->r2 == 0) {
        // 0x80026E5C: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80026E90;
    }
    // 0x80026E5C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80026E60: jal         0x8001D770
    // 0x80026E64: nop

    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x80026E64: nop

    after_1:
    // 0x80026E68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80026E6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80026E70: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80026E74: jal         0x80067CE4
    // 0x80026E78: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_80067CE4(rdram, ctx);
        goto after_2;
    // 0x80026E78: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80026E7C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80026E80: jal         0x80067818
    // 0x80026E84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80026E84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80026E88: b           L_80026ED8
    // 0x80026E8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80026ED8;
    // 0x80026E8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80026E90:
    // 0x80026E90: lw          $t6, 0x154($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X154);
    // 0x80026E94: bnel        $t6, $zero, L_80026ED8
    if (ctx->r14 != 0) {
        // 0x80026E98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80026ED8;
    }
    goto skip_0;
    // 0x80026E98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80026E9C: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x80026EA0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80026EA4: bnel        $t7, $at, L_80026ED8
    if (ctx->r15 != ctx->r1) {
        // 0x80026EA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80026ED8;
    }
    goto skip_1;
    // 0x80026EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80026EAC: jal         0x8001D770
    // 0x80026EB0: nop

    func_8001D770(rdram, ctx);
        goto after_4;
    // 0x80026EB0: nop

    after_4:
    // 0x80026EB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80026EB8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80026EBC: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80026EC0: jal         0x80067CE4
    // 0x80026EC4: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_80067CE4(rdram, ctx);
        goto after_5;
    // 0x80026EC4: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x80026EC8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80026ECC: jal         0x80067818
    // 0x80026ED0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x80026ED0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80026ED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80026ED8:
    // 0x80026ED8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80026EDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80026EE0: jr          $ra
    // 0x80026EE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80026EE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805742A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805742A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805742A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805742AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805742B0: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805742B4: lui         $t6, 0x8057
    ctx->r14 = S32(RELOC_HI16(381, 0XE54) << 16);
    // 0x805742B8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805742BC: addiu       $t6, $t6, 0x4CE4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(381, 0XE54));
    // 0x805742C0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805742C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805742C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805742CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805742D0: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805742D4: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805742D8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x805742DC: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x805742E0: addiu       $at, $zero, 0x45BC
    ctx->r1 = ADD32(0, 0X45BC);
    // 0x805742E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805742E8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805742EC: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x805742F0: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x805742F4: swc1        $f2, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f2.u32l;
    // 0x805742F8: swc1        $f2, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f2.u32l;
    // 0x805742FC: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x80574300: swc1        $f0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f0.u32l;
    // 0x80574304: beq         $v0, $at, L_80574338
    if (ctx->r2 == ctx->r1) {
        // 0x80574308: swc1        $f0, 0xF8($a0)
        MEM_W(0XF8, ctx->r4) = ctx->f0.u32l;
            goto L_80574338;
    }
    // 0x80574308: swc1        $f0, 0xF8($a0)
    MEM_W(0XF8, ctx->r4) = ctx->f0.u32l;
    // 0x8057430C: addiu       $at, $zero, 0x45BF
    ctx->r1 = ADD32(0, 0X45BF);
    // 0x80574310: beq         $v0, $at, L_8057434C
    if (ctx->r2 == ctx->r1) {
        // 0x80574314: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8057434C;
    }
    // 0x80574314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80574318: addiu       $at, $zero, 0x45F3
    ctx->r1 = ADD32(0, 0X45F3);
    // 0x8057431C: beq         $v0, $at, L_8057435C
    if (ctx->r2 == ctx->r1) {
        // 0x80574320: addiu       $a1, $s0, 0xC4
        ctx->r5 = ADD32(ctx->r16, 0XC4);
            goto L_8057435C;
    }
    // 0x80574320: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x80574324: addiu       $at, $zero, 0x468C
    ctx->r1 = ADD32(0, 0X468C);
    // 0x80574328: beq         $v0, $at, L_8057434C
    if (ctx->r2 == ctx->r1) {
        // 0x8057432C: addiu       $a1, $s0, 0xC4
        ctx->r5 = ADD32(ctx->r16, 0XC4);
            goto L_8057434C;
    }
    // 0x8057432C: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x80574330: b           L_80574388
    // 0x80574334: nop

        goto L_80574388;
    // 0x80574334: nop

L_80574338:
    // 0x80574338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057433C: jal         0x80574154
    // 0x80574340: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    func_80574154(rdram, ctx);
        goto after_0;
    // 0x80574340: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    after_0:
    // 0x80574344: b           L_80574394
    // 0x80574348: sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
        goto L_80574394;
    // 0x80574348: sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
L_8057434C:
    // 0x8057434C: jal         0x80574178
    // 0x80574350: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    func_80574178(rdram, ctx);
        goto after_1;
    // 0x80574350: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    after_1:
    // 0x80574354: b           L_80574394
    // 0x80574358: sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
        goto L_80574394;
    // 0x80574358: sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
L_8057435C:
    // 0x8057435C: jal         0x80574280
    // 0x80574360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80574280(rdram, ctx);
        goto after_2;
    // 0x80574360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80574364: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    // 0x80574368: sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
    // 0x8057436C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80574370: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80574374: sh          $t0, 0x4C($t2)
    MEM_H(0X4C, ctx->r10) = ctx->r8;
    // 0x80574378: jal         0x8004A73C
    // 0x8057437C: lw          $a0, 0x174($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X174);
    func_8004A73C(rdram, ctx);
        goto after_3;
    // 0x8057437C: lw          $a0, 0x174($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X174);
    after_3:
    // 0x80574380: b           L_80574394
    // 0x80574384: nop

        goto L_80574394;
    // 0x80574384: nop

L_80574388:
    // 0x80574388: jal         0x805741B8
    // 0x8057438C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805741B8(rdram, ctx);
        goto after_4;
    // 0x8057438C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80574390: sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
L_80574394:
    // 0x80574394: lui         $t3, 0x8057
    ctx->r11 = S32(RELOC_HI16(381, 0X1D0) << 16);
    // 0x80574398: addiu       $t3, $t3, 0x4060
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(381, 0X1D0));
    // 0x8057439C: sw          $t3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r11;
    // 0x805743A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805743A4: jal         0x80574A64
    // 0x805743A8: lbu         $a1, 0x18($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X18);
    func_80574A64(rdram, ctx);
        goto after_5;
    // 0x805743A8: lbu         $a1, 0x18($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X18);
    after_5:
    // 0x805743AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805743B0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x805743B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805743B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805743BC: sb          $t4, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r12;
    // 0x805743C0: jr          $ra
    // 0x805743C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805743C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_804A48E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A48E8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x804A48EC: lw          $t6, -0x71E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X71E0);
    // 0x804A48F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A48F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A48F8: bne         $t6, $zero, L_804A490C
    if (ctx->r14 != 0) {
        // 0x804A48FC: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_804A490C;
    }
    // 0x804A48FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A4900: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804A4904: jal         0x804A491C
    // 0x804A4908: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_804A491C(rdram, ctx);
        goto after_0;
    // 0x804A4908: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
L_804A490C:
    // 0x804A490C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A4910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A4914: jr          $ra
    // 0x804A4918: nop

    return;
    // 0x804A4918: nop

;}
RECOMP_FUNC void pad_push_only(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FB1C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8007FB20: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8007FB24: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8007FB28: xor         $v0, $t6, $a1
    ctx->r2 = ctx->r14 ^ ctx->r5;
    // 0x8007FB2C: jr          $ra
    // 0x8007FB30: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x8007FB30: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80071D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071D40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071D48: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071D4C: addiu       $a0, $a0, -0x2750
    ctx->r4 = ADD32(ctx->r4, -0X2750);
    // 0x80071D50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071D54: jal         0x80082210
    // 0x80071D58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80071D58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80071D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071D60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071D64: jr          $ra
    // 0x80071D68: nop

    return;
    // 0x80071D68: nop

;}
RECOMP_FUNC void func_8059F608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059F608: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8059F60C: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(408, 0X1C0C) << 16);
    // 0x8059F610: addiu       $t9, $t9, 0xF6C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(408, 0X1C0C));
    // 0x8059F614: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8059F618: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8059F61C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8059F620: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8059F624: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8059F628: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8059F62C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8059F630: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x8059F634: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8059F638: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8059F63C: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8059F640: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8059F644: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x8059F648: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8059F64C: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x8059F650: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8059F654: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x8059F658: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8059F65C: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x8059F660: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x8059F664: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8059F668: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8059F66C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8059F670: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8059F674: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8059F678: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8059F67C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8059F680: sltu        $at, $t4, $t9
    ctx->r1 = ctx->r12 < ctx->r25 ? 1 : 0;
    // 0x8059F684: bnel        $at, $zero, L_8059F6BC
    if (ctx->r1 != 0) {
        // 0x8059F688: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8059F6BC;
    }
    goto skip_0;
    // 0x8059F688: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8059F68C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8059F690: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8059F694: lbu         $t1, 0x8($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X8);
    // 0x8059F698: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8059F69C: sltu        $at, $t6, $t1
    ctx->r1 = ctx->r14 < ctx->r9 ? 1 : 0;
    // 0x8059F6A0: bne         $at, $zero, L_8059F6B0
    if (ctx->r1 != 0) {
        // 0x8059F6A4: nop
    
            goto L_8059F6B0;
    }
    // 0x8059F6A4: nop

    // 0x8059F6A8: b           L_8059F6BC
    // 0x8059F6AC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_8059F6BC;
    // 0x8059F6AC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8059F6B0:
    // 0x8059F6B0: b           L_8059F6BC
    // 0x8059F6B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8059F6BC;
    // 0x8059F6B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8059F6B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8059F6BC:
    // 0x8059F6BC: jr          $ra
    // 0x8059F6C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8059F6C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80019DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019DB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80019DBC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80019DC0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80019DC4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80019DC8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80019DCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80019DD0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80019DD4: sll         $a3, $a2, 16
    ctx->r7 = S32(ctx->r6 << 16);
    // 0x80019DD8: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80019DDC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80019DE0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80019DE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019DE8: jal         0x80019E00
    // 0x80019DEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80019E00(rdram, ctx);
        goto after_0;
    // 0x80019DEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80019DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80019DF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80019DF8: jr          $ra
    // 0x80019DFC: nop

    return;
    // 0x80019DFC: nop

;}
RECOMP_FUNC void func_8043D194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D194: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8043D198: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1B60) << 16);
    // 0x8043D19C: lwc1        $f4, -0x1460($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1B60));
    // 0x8043D1A0: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1A10) << 16);
    // 0x8043D1A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043D1A8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8043D1AC: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
    // 0x8043D1B0: lwc1        $f6, -0x15B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1A10));
    // 0x8043D1B4: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1B64) << 16);
    // 0x8043D1B8: swc1        $f6, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f6.u32l;
    // 0x8043D1BC: lwc1        $f8, -0x145C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1B64));
    // 0x8043D1C0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8043D1C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8043D1C8: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    // 0x8043D1CC: jr          $ra
    // 0x8043D1D0: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x8043D1D0: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_8042F484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042F488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042F48C: jal         0x8042E298
    // 0x8042F490: nop

    func_8042E298(rdram, ctx);
        goto after_0;
    // 0x8042F490: nop

    after_0:
    // 0x8042F494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042F498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042F49C: jr          $ra
    // 0x8042F4A0: nop

    return;
    // 0x8042F4A0: nop

;}
RECOMP_FUNC void func_80568700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568700: jr          $ra
    // 0x80568704: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80568704: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80067C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067C30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067C34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067C38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067C3C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80067C40: jal         0x80067BBC
    // 0x80067C44: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80067C44: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80067C48: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80067C4C: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80067C50: addiu       $v0, $v1, -0x6A50
    ctx->r2 = ADD32(ctx->r3, -0X6A50);
    // 0x80067C54: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x80067C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067C5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067C60: jr          $ra
    // 0x80067C64: nop

    return;
    // 0x80067C64: nop

;}
RECOMP_FUNC void func_804C3310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3310: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804C3314: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C3318: swc1        $f0, 0x6C8($v0)
    MEM_W(0X6C8, ctx->r2) = ctx->f0.u32l;
    // 0x804C331C: swc1        $f0, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f0.u32l;
    // 0x804C3320: swc1        $f0, 0x6D0($v0)
    MEM_W(0X6D0, ctx->r2) = ctx->f0.u32l;
    // 0x804C3324: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x804C3328: jr          $ra
    // 0x804C332C: swc1        $f4, 0x6D4($v0)
    MEM_W(0X6D4, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x804C332C: swc1        $f4, 0x6D4($v0)
    MEM_W(0X6D4, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_806B1C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1C6C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x806B1C70: beq         $at, $zero, L_806B1C84
    if (ctx->r1 == 0) {
        // 0x806B1C74: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_806B1C84;
    }
    // 0x806B1C74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B1C78: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806B1C7C: jr          $ra
    // 0x806B1C80: nop

    return;
    // 0x806B1C80: nop

L_806B1C84:
    // 0x806B1C84: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x806B1C88: beq         $at, $zero, L_806B1CC4
    if (ctx->r1 == 0) {
        // 0x806B1C8C: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_806B1CC4;
    }
    // 0x806B1C8C: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x806B1C90: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x806B1C94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B1C98: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806B1C9C: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x806B1CA0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806B1CA4: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x806B1CA8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x806B1CAC: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x806B1CB0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806B1CB4: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x806B1CB8: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x806B1CBC: jr          $ra
    // 0x806B1CC0: add.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f12.fl;
    return;
    // 0x806B1CC0: add.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f12.fl;
L_806B1CC4:
    // 0x806B1CC4: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x806B1CC8: beq         $at, $zero, L_806B1CD8
    if (ctx->r1 == 0) {
        // 0x806B1CCC: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_806B1CD8;
    }
    // 0x806B1CCC: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x806B1CD0: jr          $ra
    // 0x806B1CD4: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    return;
    // 0x806B1CD4: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
L_806B1CD8:
    // 0x806B1CD8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x806B1CDC: beq         $at, $zero, L_806B1D18
    if (ctx->r1 == 0) {
        // 0x806B1CE0: subu        $t8, $a0, $a3
        ctx->r24 = SUB32(ctx->r4, ctx->r7);
            goto L_806B1D18;
    }
    // 0x806B1CE0: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x806B1CE4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x806B1CE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B1CEC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806B1CF0: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x806B1CF4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806B1CF8: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x806B1CFC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x806B1D00: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x806B1D04: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806B1D08: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x806B1D0C: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x806B1D10: jr          $ra
    // 0x806B1D14: sub.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f8.fl;
    return;
    // 0x806B1D14: sub.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f8.fl;
L_806B1D18:
    // 0x806B1D18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B1D1C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806B1D20: nop

    // 0x806B1D24: jr          $ra
    // 0x806B1D28: nop

    return;
    // 0x806B1D28: nop

;}
RECOMP_FUNC void _bcopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C1F0: beq         $a2, $zero, L_8008C25C
    if (ctx->r6 == 0) {
        // 0x8008C1F4: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8008C25C;
    }
    // 0x8008C1F4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8008C1F8: beq         $a0, $a1, L_8008C25C
    if (ctx->r4 == ctx->r5) {
        // 0x8008C1FC: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8008C25C;
    }
    // 0x8008C1FC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8008C200: bnel        $at, $zero, L_8008C224
    if (ctx->r1 != 0) {
        // 0x8008C204: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_8008C224;
    }
    goto skip_0;
    // 0x8008C204: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x8008C208: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x8008C20C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008C210: beql        $at, $zero, L_8008C224
    if (ctx->r1 == 0) {
        // 0x8008C214: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_8008C224;
    }
    goto skip_1;
    // 0x8008C214: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x8008C218: b           L_8008C388
    // 0x8008C21C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_8008C388;
    // 0x8008C21C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x8008C220: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_8008C224:
    // 0x8008C224: bne         $at, $zero, L_8008C23C
    if (ctx->r1 != 0) {
        // 0x8008C228: nop
    
            goto L_8008C23C;
    }
    // 0x8008C228: nop

    // 0x8008C22C: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x8008C230: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x8008C234: beq         $v0, $v1, L_8008C264
    if (ctx->r2 == ctx->r3) {
        // 0x8008C238: nop
    
            goto L_8008C264;
    }
    // 0x8008C238: nop

L_8008C23C:
    // 0x8008C23C: beq         $a2, $zero, L_8008C25C
    if (ctx->r6 == 0) {
        // 0x8008C240: nop
    
            goto L_8008C25C;
    }
    // 0x8008C240: nop

    // 0x8008C244: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_8008C248:
    // 0x8008C248: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8008C24C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008C250: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008C254: bne         $a0, $v1, L_8008C248
    if (ctx->r4 != ctx->r3) {
        // 0x8008C258: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_8008C248;
    }
    // 0x8008C258: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_8008C25C:
    // 0x8008C25C: jr          $ra
    // 0x8008C260: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x8008C260: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8008C264:
    // 0x8008C264: beq         $v0, $zero, L_8008C2C8
    if (ctx->r2 == 0) {
        // 0x8008C268: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008C2C8;
    }
    // 0x8008C268: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C26C: beq         $v0, $at, L_8008C2AC
    if (ctx->r2 == ctx->r1) {
        // 0x8008C270: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008C2AC;
    }
    // 0x8008C270: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008C274: beql        $v0, $at, L_8008C298
    if (ctx->r2 == ctx->r1) {
        // 0x8008C278: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_8008C298;
    }
    goto skip_2;
    // 0x8008C278: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x8008C27C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8008C280: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008C284: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008C288: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8008C28C: b           L_8008C2C8
    // 0x8008C290: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_8008C2C8;
    // 0x8008C290: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x8008C294: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_8008C298:
    // 0x8008C298: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8008C29C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8008C2A0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x8008C2A4: b           L_8008C2C8
    // 0x8008C2A8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_8008C2C8;
    // 0x8008C2A8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_8008C2AC:
    // 0x8008C2AC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8008C2B0: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x8008C2B4: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x8008C2B8: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x8008C2BC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x8008C2C0: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x8008C2C4: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_8008C2C8:
    // 0x8008C2C8: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x8008C2CC: bnel        $at, $zero, L_8008C328
    if (ctx->r1 != 0) {
        // 0x8008C2D0: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_8008C328;
    }
    goto skip_3;
    // 0x8008C2D0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x8008C2D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008C2D8: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8008C2DC: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8008C2E0: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x8008C2E4: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x8008C2E8: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8008C2EC: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x8008C2F0: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x8008C2F4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8008C2F8: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x8008C2FC: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x8008C300: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x8008C304: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x8008C308: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x8008C30C: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x8008C310: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x8008C314: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x8008C318: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x8008C31C: b           L_8008C2C8
    // 0x8008C320: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_8008C2C8;
    // 0x8008C320: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_8008C324:
    // 0x8008C324: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_8008C328:
    // 0x8008C328: bnel        $at, $zero, L_8008C364
    if (ctx->r1 != 0) {
        // 0x8008C32C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_8008C364;
    }
    goto skip_4;
    // 0x8008C32C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x8008C330: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008C334: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8008C338: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8008C33C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x8008C340: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8008C344: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8008C348: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x8008C34C: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x8008C350: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x8008C354: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x8008C358: b           L_8008C324
    // 0x8008C35C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_8008C324;
    // 0x8008C35C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_8008C360:
    // 0x8008C360: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_8008C364:
    // 0x8008C364: bne         $at, $zero, L_8008C23C
    if (ctx->r1 != 0) {
        // 0x8008C368: nop
    
            goto L_8008C23C;
    }
    // 0x8008C368: nop

    // 0x8008C36C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008C370: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8008C374: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8008C378: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8008C37C: b           L_8008C360
    // 0x8008C380: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_8008C360;
    // 0x8008C380: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x8008C384: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_8008C388:
    // 0x8008C388: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8008C38C: bne         $at, $zero, L_8008C3A4
    if (ctx->r1 != 0) {
        // 0x8008C390: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_8008C3A4;
    }
    // 0x8008C390: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x8008C394: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x8008C398: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x8008C39C: beq         $v0, $v1, L_8008C3D4
    if (ctx->r2 == ctx->r3) {
        // 0x8008C3A0: nop
    
            goto L_8008C3D4;
    }
    // 0x8008C3A0: nop

L_8008C3A4:
    // 0x8008C3A4: beq         $a2, $zero, L_8008C25C
    if (ctx->r6 == 0) {
        // 0x8008C3A8: nop
    
            goto L_8008C25C;
    }
    // 0x8008C3A8: nop

    // 0x8008C3AC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8008C3B0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8008C3B4: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_8008C3B8:
    // 0x8008C3B8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8008C3BC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8008C3C0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8008C3C4: bne         $a0, $v1, L_8008C3B8
    if (ctx->r4 != ctx->r3) {
        // 0x8008C3C8: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_8008C3B8;
    }
    // 0x8008C3C8: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x8008C3CC: jr          $ra
    // 0x8008C3D0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x8008C3D0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8008C3D4:
    // 0x8008C3D4: beq         $v0, $zero, L_8008C438
    if (ctx->r2 == 0) {
        // 0x8008C3D8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8008C438;
    }
    // 0x8008C3D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008C3DC: beq         $v0, $at, L_8008C41C
    if (ctx->r2 == ctx->r1) {
        // 0x8008C3E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008C41C;
    }
    // 0x8008C3E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008C3E4: beql        $v0, $at, L_8008C408
    if (ctx->r2 == ctx->r1) {
        // 0x8008C3E8: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_8008C408;
    }
    goto skip_5;
    // 0x8008C3E8: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x8008C3EC: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x8008C3F0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8008C3F4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8008C3F8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8008C3FC: b           L_8008C438
    // 0x8008C400: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_8008C438;
    // 0x8008C400: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8008C404: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_8008C408:
    // 0x8008C408: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x8008C40C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x8008C410: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x8008C414: b           L_8008C438
    // 0x8008C418: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_8008C438;
    // 0x8008C418: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_8008C41C:
    // 0x8008C41C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x8008C420: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x8008C424: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x8008C428: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x8008C42C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x8008C430: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x8008C434: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_8008C438:
    // 0x8008C438: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x8008C43C: bnel        $at, $zero, L_8008C498
    if (ctx->r1 != 0) {
        // 0x8008C440: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_8008C498;
    }
    goto skip_6;
    // 0x8008C440: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x8008C444: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8008C448: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x8008C44C: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x8008C450: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x8008C454: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x8008C458: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x8008C45C: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x8008C460: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x8008C464: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x8008C468: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x8008C46C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x8008C470: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x8008C474: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x8008C478: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x8008C47C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x8008C480: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x8008C484: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x8008C488: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x8008C48C: b           L_8008C438
    // 0x8008C490: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_8008C438;
    // 0x8008C490: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_8008C494:
    // 0x8008C494: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_8008C498:
    // 0x8008C498: bnel        $at, $zero, L_8008C4D4
    if (ctx->r1 != 0) {
        // 0x8008C49C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_8008C4D4;
    }
    goto skip_7;
    // 0x8008C49C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x8008C4A0: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8008C4A4: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x8008C4A8: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x8008C4AC: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x8008C4B0: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x8008C4B4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x8008C4B8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x8008C4BC: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x8008C4C0: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x8008C4C4: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x8008C4C8: b           L_8008C494
    // 0x8008C4CC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_8008C494;
    // 0x8008C4CC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_8008C4D0:
    // 0x8008C4D0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_8008C4D4:
    // 0x8008C4D4: bne         $at, $zero, L_8008C3A4
    if (ctx->r1 != 0) {
        // 0x8008C4D8: nop
    
            goto L_8008C3A4;
    }
    // 0x8008C4D8: nop

    // 0x8008C4DC: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8008C4E0: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8008C4E4: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8008C4E8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8008C4EC: b           L_8008C4D0
    // 0x8008C4F0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_8008C4D0;
    // 0x8008C4F0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void func_8051B368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051B368: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051B36C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8051B370: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8051B374: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8051B378: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8051B37C: lui         $a0, 0x8052
    ctx->r4 = S32(RELOC_HI16(297, 0X4C0) << 16);
    // 0x8051B380: lui         $a1, 0x40C6
    ctx->r5 = S32(0X40C6 << 16);
    // 0x8051B384: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8051B388: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x8051B38C: addiu       $a0, $a0, -0x4810
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(297, 0X4C0));
    // 0x8051B390: jal         0x80046804
    // 0x8051B394: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x8051B394: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8051B398: bne         $v0, $zero, L_8051B3A8
    if (ctx->r2 != 0) {
        // 0x8051B39C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8051B3A8;
    }
    // 0x8051B39C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8051B3A0: b           L_8051B3AC
    // 0x8051B3A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8051B3AC;
    // 0x8051B3A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8051B3A8:
    // 0x8051B3A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8051B3AC:
    // 0x8051B3AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8051B3B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051B3B4: jr          $ra
    // 0x8051B3B8: nop

    return;
    // 0x8051B3B8: nop

;}
RECOMP_FUNC void func_807B49A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B49A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807B49A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x807B49A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x807B49AC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x807B49B0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x807B49B4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807B49B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x807B49BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807B49C0: blez        $a2, L_807B49F0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x807B49C4: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_807B49F0;
    }
    // 0x807B49C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B49C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B49CC: sll         $s2, $a2, 3
    ctx->r18 = S32(ctx->r6 << 3);
    // 0x807B49D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_807B49D4:
    // 0x807B49D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B49D8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B49DC: jal         0x8005C27C
    // 0x807B49E0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x807B49E0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_0:
    // 0x807B49E4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B49E8: bnel        $s0, $s2, L_807B49D4
    if (ctx->r16 != ctx->r18) {
        // 0x807B49EC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_807B49D4;
    }
    goto skip_0;
    // 0x807B49EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
L_807B49F0:
    // 0x807B49F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x807B49F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B49F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x807B49FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x807B4A00: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x807B4A04: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x807B4A08: jr          $ra
    // 0x807B4A0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x807B4A0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80518F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80518F14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80518F18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80518F1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80518F20: jal         0x8004700C
    // 0x80518F24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80518F24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80518F28: beql        $v0, $zero, L_80518FE0
    if (ctx->r2 == 0) {
        // 0x80518F2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80518FE0;
    }
    goto skip_0;
    // 0x80518F2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80518F30: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x80518F34: lw          $a2, 0x1F4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1F4);
    // 0x80518F38: lhu         $a1, 0x208($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X208);
    // 0x80518F3C: lhu         $t8, 0x12BC($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X12BC);
    // 0x80518F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80518F44: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80518F48: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80518F4C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80518F50: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x80518F54: lhu         $t7, 0x1200($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1200);
    // 0x80518F58: lbu         $t9, 0x1202($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1202);
    // 0x80518F5C: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x80518F60: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80518F64: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80518F68: beq         $at, $zero, L_80518F80
    if (ctx->r1 == 0) {
        // 0x80518F6C: andi        $a3, $a3, 0xFFFF
        ctx->r7 = ctx->r7 & 0XFFFF;
            goto L_80518F80;
    }
    // 0x80518F6C: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x80518F70: jal         0x80518D68
    // 0x80518F74: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    func_80518D68(rdram, ctx);
        goto after_1;
    // 0x80518F74: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    after_1:
    // 0x80518F78: b           L_80518FE0
    // 0x80518F7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80518FE0;
    // 0x80518F7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80518F80:
    // 0x80518F80: sll         $t0, $a3, 4
    ctx->r8 = S32(ctx->r7 << 4);
    // 0x80518F84: addu        $t1, $a2, $t0
    ctx->r9 = ADD32(ctx->r6, ctx->r8);
    // 0x80518F88: lbu         $t2, 0x209($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X209);
    // 0x80518F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80518F90: srl         $t3, $t2, 4
    ctx->r11 = S32(U32(ctx->r10) >> 4);
    // 0x80518F94: bnel        $t3, $zero, L_80518FB0
    if (ctx->r11 != 0) {
        // 0x80518F98: lbu         $t4, 0x1FA($a2)
        ctx->r12 = MEM_BU(ctx->r6, 0X1FA);
            goto L_80518FB0;
    }
    goto skip_1;
    // 0x80518F98: lbu         $t4, 0x1FA($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1FA);
    skip_1:
    // 0x80518F9C: jal         0x80518EDC
    // 0x80518FA0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80518EDC(rdram, ctx);
        goto after_2;
    // 0x80518FA0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x80518FA4: b           L_80518FE0
    // 0x80518FA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80518FE0;
    // 0x80518FA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80518FAC: lbu         $t4, 0x1FA($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1FA);
L_80518FB0:
    // 0x80518FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80518FB4: bne         $t4, $zero, L_80518FD4
    if (ctx->r12 != 0) {
        // 0x80518FB8: nop
    
            goto L_80518FD4;
    }
    // 0x80518FB8: nop

    // 0x80518FBC: lbu         $t5, 0x1F9($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X1F9);
    // 0x80518FC0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80518FC4: bne         $t5, $zero, L_80518FD4
    if (ctx->r13 != 0) {
        // 0x80518FC8: nop
    
            goto L_80518FD4;
    }
    // 0x80518FC8: nop

    // 0x80518FCC: b           L_80518FDC
    // 0x80518FD0: sw          $t6, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r14;
        goto L_80518FDC;
    // 0x80518FD0: sw          $t6, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r14;
L_80518FD4:
    // 0x80518FD4: jal         0x80518DD8
    // 0x80518FD8: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    func_80518DD8(rdram, ctx);
        goto after_3;
    // 0x80518FD8: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    after_3:
L_80518FDC:
    // 0x80518FDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80518FE0:
    // 0x80518FE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80518FE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80518FE8: jr          $ra
    // 0x80518FEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80518FEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8005A824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A824: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8005A828: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005A82C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8005A830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A834:
    // 0x8005A834: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8005A838: lwc1        $f8, 0x18($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8005A83C: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8005A840: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8005A844: swc1        $f6, 0x54($a1)
    MEM_W(0X54, ctx->r5) = ctx->f6.u32l;
    // 0x8005A848: swc1        $f8, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f8.u32l;
    // 0x8005A84C: swc1        $f10, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f10.u32l;
    // 0x8005A850: swc1        $f4, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->f4.u32l;
    // 0x8005A854: lwc1        $f16, 0x30($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8005A858: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005A85C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005A860: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8005A864: bne         $v0, $a0, L_8005A834
    if (ctx->r2 != ctx->r4) {
        // 0x8005A868: swc1        $f16, 0x74($v1)
        MEM_W(0X74, ctx->r3) = ctx->f16.u32l;
            goto L_8005A834;
    }
    // 0x8005A868: swc1        $f16, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f16.u32l;
    // 0x8005A86C: jr          $ra
    // 0x8005A870: nop

    return;
    // 0x8005A870: nop

;}
RECOMP_FUNC void func_806F9C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F9C94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F9C98: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x806F9C9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F9CA0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x806F9CA4: jal         0x80067878
    // 0x806F9CA8: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x806F9CA8: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    after_0:
    // 0x806F9CAC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x806F9CB0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x806F9CB4: sh          $t7, 0x1F0($t8)
    MEM_H(0X1F0, ctx->r24) = ctx->r15;
    // 0x806F9CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F9CBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F9CC0: jr          $ra
    // 0x806F9CC4: nop

    return;
    // 0x806F9CC4: nop

;}
