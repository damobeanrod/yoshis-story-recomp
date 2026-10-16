#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8005770C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005770C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80057710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057714: jal         0x800575B4
    // 0x80057718: addiu       $a1, $zero, 0x405E
    ctx->r5 = ADD32(0, 0X405E);
    func_800575B4(rdram, ctx);
        goto after_0;
    // 0x80057718: addiu       $a1, $zero, 0x405E
    ctx->r5 = ADD32(0, 0X405E);
    after_0:
    // 0x8005771C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80057724: jr          $ra
    // 0x80057728: nop

    return;
    // 0x80057728: nop

;}
RECOMP_FUNC void func_805A50B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A50B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A50B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A50B8: jal         0x805A4AF8
    // 0x805A50BC: nop

    func_805A4AF8(rdram, ctx);
        goto after_0;
    // 0x805A50BC: nop

    after_0:
    // 0x805A50C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A50C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A50C8: jr          $ra
    // 0x805A50CC: nop

    return;
    // 0x805A50CC: nop

;}
RECOMP_FUNC void func_8075F0F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075F0F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8075F0FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8075F100: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8075F104: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8075F108: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8075F10C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8075F110: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8075F114: jal         0x8004700C
    // 0x8075F118: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8075F118: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8075F11C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8075F120: beq         $v0, $zero, L_8075F188
    if (ctx->r2 == 0) {
        // 0x8075F124: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_8075F188;
    }
    // 0x8075F124: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8075F128: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x8075F12C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8075F130: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x8075F134: bnel        $t8, $at, L_8075F18C
    if (ctx->r24 != ctx->r1) {
        // 0x8075F138: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8075F18C;
    }
    goto skip_0;
    // 0x8075F138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8075F13C: lbu         $t9, 0xF4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF4);
    // 0x8075F140: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8075F144: beq         $t9, $zero, L_8075F180
    if (ctx->r25 == 0) {
        // 0x8075F148: nop
    
            goto L_8075F180;
    }
    // 0x8075F148: nop

    // 0x8075F14C: lwc1        $f4, 0x88($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8075F150: lwc1        $f6, 0x88($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X88);
    // 0x8075F154: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8075F158: lwc1        $f8, 0x40($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X40);
    // 0x8075F15C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8075F160: lwc1        $f10, 0x208($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X208);
    // 0x8075F164: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8075F168: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8075F16C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8075F170: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8075F174: nop

    // 0x8075F178: bc1fl       L_8075F18C
    if (!c1cs) {
        // 0x8075F17C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8075F18C;
    }
    goto skip_1;
    // 0x8075F17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_8075F180:
    // 0x8075F180: jal         0x8002F6E4
    // 0x8075F184: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x8075F184: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_8075F188:
    // 0x8075F188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8075F18C:
    // 0x8075F18C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8075F190: jr          $ra
    // 0x8075F194: nop

    return;
    // 0x8075F194: nop

;}
RECOMP_FUNC void func_80562B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80562B74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80562B78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80562B7C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80562B80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80562B84: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80562B88: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    // 0x80562B8C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80562B90: addiu       $a1, $a2, 0x13C
    ctx->r5 = ADD32(ctx->r6, 0X13C);
    // 0x80562B94: bc1f        L_80562BAC
    if (!c1cs) {
        // 0x80562B98: nop
    
            goto L_80562BAC;
    }
    // 0x80562B98: nop

    // 0x80562B9C: jal         0x80059398
    // 0x80562BA0: addiu       $a1, $a2, 0x13C
    ctx->r5 = ADD32(ctx->r6, 0X13C);
    func_80059398(rdram, ctx);
        goto after_0;
    // 0x80562BA0: addiu       $a1, $a2, 0x13C
    ctx->r5 = ADD32(ctx->r6, 0X13C);
    after_0:
    // 0x80562BA4: b           L_80562BB8
    // 0x80562BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80562BB8;
    // 0x80562BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80562BAC:
    // 0x80562BAC: jal         0x800594F8
    // 0x80562BB0: addiu       $a0, $a2, 0x84
    ctx->r4 = ADD32(ctx->r6, 0X84);
    func_800594F8(rdram, ctx);
        goto after_1;
    // 0x80562BB0: addiu       $a0, $a2, 0x84
    ctx->r4 = ADD32(ctx->r6, 0X84);
    after_1:
    // 0x80562BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80562BB8:
    // 0x80562BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80562BBC: jr          $ra
    // 0x80562BC0: nop

    return;
    // 0x80562BC0: nop

;}
RECOMP_FUNC void func_805AB27C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB27C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805AB280: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805AB284: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805AB288: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AB28C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805AB290: jal         0x805AAF60
    // 0x805AB294: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_805AAF60(rdram, ctx);
        goto after_0;
    // 0x805AB294: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x805AB298: jal         0x805AB0A0
    // 0x805AB29C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805AB0A0(rdram, ctx);
        goto after_1;
    // 0x805AB29C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805AB2A0: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x805AB2A4: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x805AB2A8: jal         0x80065ABC
    // 0x805AB2AC: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_2;
    // 0x805AB2AC: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_2:
    // 0x805AB2B0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x805AB2B4: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x805AB2B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AB2BC: lw          $t7, 0x264($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X264);
    // 0x805AB2C0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805AB2C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805AB2C8: beq         $t7, $zero, L_805AB2EC
    if (ctx->r15 == 0) {
        // 0x805AB2CC: nop
    
            goto L_805AB2EC;
    }
    // 0x805AB2CC: nop

    // 0x805AB2D0: jal         0x805AB914
    // 0x805AB2D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805AB914(rdram, ctx);
        goto after_3;
    // 0x805AB2D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805AB2D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AB2DC: jal         0x805AB24C
    // 0x805AB2E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_805AB24C(rdram, ctx);
        goto after_4;
    // 0x805AB2E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x805AB2E4: b           L_805AB2F8
    // 0x805AB2E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805AB2F8;
    // 0x805AB2E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805AB2EC:
    // 0x805AB2EC: jal         0x8005D87C
    // 0x805AB2F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8005D87C(rdram, ctx);
        goto after_5;
    // 0x805AB2F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x805AB2F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805AB2F8:
    // 0x805AB2F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805AB2FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805AB300: jr          $ra
    // 0x805AB304: nop

    return;
    // 0x805AB304: nop

;}
RECOMP_FUNC void func_80792174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80792174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80792178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079217C: jal         0x80790714
    // 0x80792180: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80790714(rdram, ctx);
        goto after_0;
    // 0x80792180: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80792184: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80792188: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8079218C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80792190: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x80792194: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80792198: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8079219C: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x807921A0: bne         $at, $zero, L_807921B0
    if (ctx->r1 != 0) {
        // 0x807921A4: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_807921B0;
    }
    // 0x807921A4: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x807921A8: sb          $t9, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r25;
    // 0x807921AC: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
L_807921B0:
    // 0x807921B0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x807921B4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x807921B8: lw          $t0, 0xEE0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XEE0);
    // 0x807921BC: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x807921C0: bne         $at, $zero, L_80792210
    if (ctx->r1 != 0) {
        // 0x807921C4: lui         $at, 0x8079
        ctx->r1 = S32(RELOC_HI16(817, 0X7AE4) << 16);
            goto L_80792210;
    }
    // 0x807921C4: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AE4) << 16);
    // 0x807921C8: lwc1        $f4, 0x7E34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AE4));
    // 0x807921CC: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x807921D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807921D4: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AE8) << 16);
    // 0x807921D8: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x807921DC: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    // 0x807921E0: lwc1        $f8, 0x7E38($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AE8));
    // 0x807921E4: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
    // 0x807921E8: jal         0x8005FE48
    // 0x807921EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x807921EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x807921F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807921F4: lui         $t3, 0x8079
    ctx->r11 = S32(RELOC_HI16(817, 0X1D4C) << 16);
    // 0x807921F8: addiu       $t3, $t3, 0x209C
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(817, 0X1D4C));
    // 0x807921FC: lw          $t1, 0x174($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X174);
    // 0x80792200: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80792204: sw          $zero, 0x44($t2)
    MEM_W(0X44, ctx->r10) = 0;
    // 0x80792208: sw          $t3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r11;
    // 0x8079220C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
L_80792210:
    // 0x80792210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80792214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80792218: jr          $ra
    // 0x8079221C: nop

    return;
    // 0x8079221C: nop

;}
RECOMP_FUNC void func_8046A8E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046A8E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8046A8EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046A8F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046A8F4: jal         0x8004700C
    // 0x8046A8F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8046A8F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8046A8FC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8046A900: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046A904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046A908: jal         0x8046B08C
    // 0x8046A90C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_8046B08C(rdram, ctx);
        goto after_1;
    // 0x8046A90C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_1:
    // 0x8046A910: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8046A914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046A918: beql        $t7, $zero, L_8046AA18
    if (ctx->r15 == 0) {
        // 0x8046A91C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8046AA18;
    }
    goto skip_0;
    // 0x8046A91C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8046A920: jal         0x80062684
    // 0x8046A924: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062684(rdram, ctx);
        goto after_2;
    // 0x8046A924: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_2:
    // 0x8046A928: jal         0x8046A744
    // 0x8046A92C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046A744(rdram, ctx);
        goto after_3;
    // 0x8046A92C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8046A930: jal         0x8046A80C
    // 0x8046A934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046A80C(rdram, ctx);
        goto after_4;
    // 0x8046A934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8046A938: jal         0x80469FF4
    // 0x8046A93C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80469FF4(rdram, ctx);
        goto after_5;
    // 0x8046A93C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8046A940: jal         0x80469834
    // 0x8046A944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80469834(rdram, ctx);
        goto after_6;
    // 0x8046A944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8046A948: jal         0x8046A0DC
    // 0x8046A94C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046A0DC(rdram, ctx);
        goto after_7;
    // 0x8046A94C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8046A950: jal         0x80469834
    // 0x8046A954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80469834(rdram, ctx);
        goto after_8;
    // 0x8046A954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8046A958: jal         0x8046A4A4
    // 0x8046A95C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046A4A4(rdram, ctx);
        goto after_9;
    // 0x8046A95C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8046A960: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8046A964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046A968: jal         0x8046A424
    // 0x8046A96C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8046A424(rdram, ctx);
        goto after_10;
    // 0x8046A96C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x8046A970: beq         $v0, $zero, L_8046A9F8
    if (ctx->r2 == 0) {
        // 0x8046A974: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_8046A9F8;
    }
    // 0x8046A974: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8046A978: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8046A97C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8046A980: jal         0x80469D08
    // 0x8046A984: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_80469D08(rdram, ctx);
        goto after_11;
    // 0x8046A984: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_11:
    // 0x8046A988: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8046A98C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8046A990: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8046A994: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8046A998: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8046A99C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8046A9A0: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8046A9A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046A9A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046A9AC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8046A9B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8046A9B4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8046A9B8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8046A9BC: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x8046A9C0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8046A9C4: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8046A9C8: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8046A9CC: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8046A9D0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8046A9D4: lw          $t9, 0x180($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X180);
    // 0x8046A9D8: beql        $s0, $t9, L_8046AA18
    if (ctx->r16 == ctx->r25) {
        // 0x8046A9DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8046AA18;
    }
    goto skip_1;
    // 0x8046A9DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8046A9E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8046A9E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8046A9E8: jal         0x8046B2D8
    // 0x8046A9EC: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    func_8046B2D8(rdram, ctx);
        goto after_12;
    // 0x8046A9EC: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    after_12:
    // 0x8046A9F0: b           L_8046AA18
    // 0x8046A9F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8046AA18;
    // 0x8046A9F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046A9F8:
    // 0x8046A9F8: jal         0x8046A29C
    // 0x8046A9FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046A29C(rdram, ctx);
        goto after_13;
    // 0x8046A9FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8046AA00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046AA04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046AA08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8046AA0C: jal         0x8046B2D8
    // 0x8046AA10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8046B2D8(rdram, ctx);
        goto after_14;
    // 0x8046AA10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x8046AA14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046AA18:
    // 0x8046AA18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046AA1C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8046AA20: jr          $ra
    // 0x8046AA24: nop

    return;
    // 0x8046AA24: nop

;}
RECOMP_FUNC void func_8055824C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8055824C: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80558250: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80558254: lw          $t6, 0x138($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X138);
    // 0x80558258: beql        $t6, $zero, L_80558268
    if (ctx->r14 == 0) {
        // 0x8055825C: lw          $t7, 0x0($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X0);
            goto L_80558268;
    }
    goto skip_0;
    // 0x8055825C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80558260: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80558264: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
L_80558268:
    // 0x80558268: lwc1        $f4, 0x6C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x8055826C: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80558270: mflo        $t8
    ctx->r24 = lo;
    // 0x80558274: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80558278: nop

    // 0x8055827C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80558280: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80558284: lwc1        $f8, 0x78($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80558288: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x8055828C: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80558290: lwc1        $f16, 0x70($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X70);
    // 0x80558294: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x80558298: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8055829C: nop

    // 0x805582A0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x805582A4: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x805582A8: lwc1        $f16, 0x7C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x805582AC: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x805582B0: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x805582B4: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805582B8: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x805582BC: swc1        $f18, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f18.u32l;
    // 0x805582C0: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x805582C4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x805582C8: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x805582CC: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    // 0x805582D0: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x805582D4: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x805582D8: jr          $ra
    // 0x805582DC: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x805582DC: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_805D7FBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7FBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D7FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D7FC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805D7FC8: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D7FCC: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x805D7FD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805D7FD4: jal         0x80065728
    // 0x805D7FD8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x805D7FD8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D7FDC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x805D7FE0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x805D7FE4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x805D7FE8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805D7FEC: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x805D7FF0: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x805D7FF4: sb          $t8, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r24;
    // 0x805D7FF8: sh          $t9, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r25;
    // 0x805D7FFC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x805D8000: lwc1        $f4, 0x40($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X40);
    // 0x805D8004: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x805D8008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D800C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805D8010: jr          $ra
    // 0x805D8014: nop

    return;
    // 0x805D8014: nop

;}
RECOMP_FUNC void func_8001B618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B618: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x8001B61C: lw          $t6, 0x7A00($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7A00);
    // 0x8001B620: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001B624: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001B628: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x8001B62C: bne         $t7, $zero, L_8001B63C
    if (ctx->r15 != 0) {
        // 0x8001B630: sra         $a0, $a0, 16
        ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
            goto L_8001B63C;
    }
    // 0x8001B630: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001B634: jr          $ra
    // 0x8001B638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001B638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B63C:
    // 0x8001B63C: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8001B640: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x8001B644: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8001B648: lw          $t9, 0x7A34($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7A34);
    // 0x8001B64C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B650: lw          $t0, 0x50($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X50);
    // 0x8001B654: bne         $t0, $zero, L_8001B664
    if (ctx->r8 != 0) {
        // 0x8001B658: nop
    
            goto L_8001B664;
    }
    // 0x8001B658: nop

    // 0x8001B65C: jr          $ra
    // 0x8001B660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001B660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B664:
    // 0x8001B664: jr          $ra
    // 0x8001B668: nop

    return;
    // 0x8001B668: nop

;}
RECOMP_FUNC void func_80420520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80420520: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80420524: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80420528: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042052C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80420530: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80420534: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80420538: lui         $t7, 0x8042
    ctx->r15 = S32(RELOC_HI16(29, 0X346C) << 16);
    // 0x8042053C: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x80420540: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80420544: addiu       $t7, $t7, 0xACC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(29, 0X346C));
    // 0x80420548: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8042054C: addiu       $t9, $zero, 0x4B0
    ctx->r25 = ADD32(0, 0X4B0);
    // 0x80420550: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80420554: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80420558: sw          $t9, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = ctx->r25;
    // 0x8042055C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x80420560: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80420564: jal         0x804205D8
    // 0x80420568: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804205D8(rdram, ctx);
        goto after_0;
    // 0x80420568: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8042056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80420570: jal         0x80045A34
    // 0x80420574: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80420574: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_1:
    // 0x80420578: bne         $v0, $zero, L_804205AC
    if (ctx->r2 != 0) {
        // 0x8042057C: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_804205AC;
    }
    // 0x8042057C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80420580: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    // 0x80420584: beq         $a0, $zero, L_8042059C
    if (ctx->r4 == 0) {
        // 0x80420588: nop
    
            goto L_8042059C;
    }
    // 0x80420588: nop

    // 0x8042058C: jal         0x800445A4
    // 0x80420590: nop

    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80420590: nop

    after_2:
    // 0x80420594: b           L_804205C8
    // 0x80420598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804205C8;
    // 0x80420598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042059C:
    // 0x8042059C: jal         0x800445A4
    // 0x804205A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x804205A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804205A4: b           L_804205C8
    // 0x804205A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804205C8;
    // 0x804205A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804205AC:
    // 0x804205AC: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x804205B0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x804205B4: jal         0x80065728
    // 0x804205B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_4;
    // 0x804205B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x804205BC: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x804205C0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x804205C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804205C8:
    // 0x804205C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804205CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804205D0: jr          $ra
    // 0x804205D4: nop

    return;
    // 0x804205D4: nop

;}
RECOMP_FUNC void func_8051A6A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051A6A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8051A6AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8051A6B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8051A6B4: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8051A6B8: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(294, 0X910) << 16);
    // 0x8051A6BC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8051A6C0: addiu       $t6, $t6, -0x51D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(294, 0X910));
    // 0x8051A6C4: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8051A6C8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8051A6CC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8051A6D0: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8051A6D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8051A6D8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8051A6DC: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x8051A6E0: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x8051A6E4: jal         0x80045A34
    // 0x8051A6E8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8051A6E8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x8051A6EC: lui         $t0, 0x8052
    ctx->r8 = S32(RELOC_HI16(294, 0X2E0) << 16);
    // 0x8051A6F0: addiu       $t0, $t0, -0x5800
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(294, 0X2E0));
    // 0x8051A6F4: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8051A6F8: sw          $t0, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r8;
    // 0x8051A6FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8051A700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8051A704: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8051A708: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8051A70C: jal         0x8051ADC0
    // 0x8051A710: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8051ADC0(rdram, ctx);
        goto after_1;
    // 0x8051A710: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8051A714: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8051A718: jal         0x80048378
    // 0x8051A71C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_80048378(rdram, ctx);
        goto after_2;
    // 0x8051A71C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8051A720: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8051A724: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8051A728: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8051A72C: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8051A730: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8051A734: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8051A738: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8051A73C: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x8051A740: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x8051A744: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x8051A748: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x8051A74C: jal         0x80058958
    // 0x8051A750: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    func_80058958(rdram, ctx);
        goto after_3;
    // 0x8051A750: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_3:
    // 0x8051A754: beq         $v0, $zero, L_8051A7D0
    if (ctx->r2 == 0) {
        // 0x8051A758: lui         $t3, 0x8010
        ctx->r11 = S32(0X8010 << 16);
            goto L_8051A7D0;
    }
    // 0x8051A758: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x8051A75C: lw          $t3, -0x7BC4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7BC4);
    // 0x8051A760: lw          $t4, 0x10C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10C);
    // 0x8051A764: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8051A768: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x8051A76C: beql        $t6, $zero, L_8051A7D4
    if (ctx->r14 == 0) {
        // 0x8051A770: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_8051A7D4;
    }
    goto skip_0;
    // 0x8051A770: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x8051A774: jal         0x80056564
    // 0x8051A778: nop

    func_80056564(rdram, ctx);
        goto after_4;
    // 0x8051A778: nop

    after_4:
    // 0x8051A77C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8051A780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8051A784: beq         $v0, $zero, L_8051A7D8
    if (ctx->r2 == 0) {
        // 0x8051A788: sw          $v0, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->r2;
            goto L_8051A7D8;
    }
    // 0x8051A788: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x8051A78C: jal         0x800457A0
    // 0x8051A790: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_5;
    // 0x8051A790: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8051A794: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8051A798: addiu       $t9, $zero, 0x29
    ctx->r25 = ADD32(0, 0X29);
    // 0x8051A79C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8051A7A0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8051A7A4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8051A7A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8051A7AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8051A7B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8051A7B4: jal         0x80056584
    // 0x8051A7B8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80056584(rdram, ctx);
        goto after_6;
    // 0x8051A7B8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_6:
    // 0x8051A7BC: lw          $t2, 0x16C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X16C);
    // 0x8051A7C0: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x8051A7C4: addiu       $t1, $t1, 0x784C
    ctx->r9 = ADD32(ctx->r9, 0X784C);
    // 0x8051A7C8: b           L_8051A7D8
    // 0x8051A7CC: sw          $t1, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r9;
        goto L_8051A7D8;
    // 0x8051A7CC: sw          $t1, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r9;
L_8051A7D0:
    // 0x8051A7D0: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
L_8051A7D4:
    // 0x8051A7D4: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_8051A7D8:
    // 0x8051A7D8: lui         $t4, 0x8052
    ctx->r12 = S32(RELOC_HI16(294, 0X160) << 16);
    // 0x8051A7DC: addiu       $t4, $t4, -0x5980
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(294, 0X160));
    // 0x8051A7E0: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8051A7E4: sw          $t4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r12;
    // 0x8051A7E8: sh          $t5, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r13;
    // 0x8051A7EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8051A7F0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8051A7F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8051A7F8: jr          $ra
    // 0x8051A7FC: nop

    return;
    // 0x8051A7FC: nop

;}
RECOMP_FUNC void func_80407C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80407C70: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80407C74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80407C78: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80407C7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80407C80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80407C84: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x80407C88: lui         $t6, 0x8041
    ctx->r14 = S32(RELOC_HI16(11, 0X2CD0) << 16);
    // 0x80407C8C: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x80407C90: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80407C94: lui         $t7, 0x8041
    ctx->r15 = S32(RELOC_HI16(11, 0X2510) << 16);
    // 0x80407C98: addiu       $t6, $t6, -0x5960
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(11, 0X2CD0));
    // 0x80407C9C: addiu       $t7, $t7, -0x6120
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(11, 0X2510));
    // 0x80407CA0: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x80407CA4: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x80407CA8: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80407CAC: jr          $ra
    // 0x80407CB0: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x80407CB0: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_8043A6F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043A6F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043A6F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043A6FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043A700: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043A704: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11A0) << 16);
    // 0x8043A708: lwc1        $f4, -0x4800($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11A0));
    // 0x8043A70C: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8043A710: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043A714: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11A4) << 16);
    // 0x8043A718: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8043A71C: nop

    // 0x8043A720: bc1fl       L_8043A73C
    if (!c1cs) {
        // 0x8043A724: lui         $at, 0x42FE
        ctx->r1 = S32(0X42FE << 16);
            goto L_8043A73C;
    }
    goto skip_0;
    // 0x8043A724: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    skip_0:
    // 0x8043A728: lwc1        $f6, -0x47FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11A4));
    // 0x8043A72C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8043A730: nop

    // 0x8043A734: bc1t        L_8043A7B8
    if (c1cs) {
        // 0x8043A738: lui         $at, 0x42FE
        ctx->r1 = S32(0X42FE << 16);
            goto L_8043A7B8;
    }
    // 0x8043A738: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
L_8043A73C:
    // 0x8043A73C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8043A740: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8043A744: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8043A748: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8043A74C: nop

    // 0x8043A750: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8043A754: jal         0x80065954
    // 0x8043A758: nop

    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8043A758: nop

    after_0:
    // 0x8043A75C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8043A760: lh          $t8, 0x1F0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1F0);
    // 0x8043A764: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8043A768: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8043A76C: bnel        $t8, $at, L_8043A798
    if (ctx->r24 != ctx->r1) {
        // 0x8043A770: lw          $a1, 0x34($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X34);
            goto L_8043A798;
    }
    goto skip_1;
    // 0x8043A770: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    skip_1:
    // 0x8043A774: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8043A778: jal         0x80067D5C
    // 0x8043A77C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_1;
    // 0x8043A77C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8043A780: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8043A784: jal         0x80067F78
    // 0x8043A788: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_2;
    // 0x8043A788: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8043A78C: b           L_8043A7C0
    // 0x8043A790: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_8043A7C0;
    // 0x8043A790: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8043A794: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
L_8043A798:
    // 0x8043A798: jal         0x80067D5C
    // 0x8043A79C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_3;
    // 0x8043A79C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8043A7A0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8043A7A4: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8043A7A8: jal         0x800678F0
    // 0x8043A7AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x8043A7AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x8043A7B0: b           L_8043A7C4
    // 0x8043A7B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8043A7C4;
    // 0x8043A7B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043A7B8:
    // 0x8043A7B8: jal         0x8043A6B4
    // 0x8043A7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043A6B4(rdram, ctx);
        goto after_5;
    // 0x8043A7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8043A7C0:
    // 0x8043A7C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043A7C4:
    // 0x8043A7C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043A7C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043A7CC: jr          $ra
    // 0x8043A7D0: nop

    return;
    // 0x8043A7D0: nop

;}
RECOMP_FUNC void func_8069BC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069BC34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069BC38: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8069BC3C: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x8069BC40: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8069BC44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069BC48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8069BC4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8069BC50: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8069BC54: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8069BC58: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8069BC5C: lui         $t1, 0x806A
    ctx->r9 = S32(RELOC_HI16(565, 0X1910) << 16);
    // 0x8069BC60: sb          $a3, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r7;
    // 0x8069BC64: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8069BC68: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8069BC6C: lw          $t1, -0x3A20($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(565, 0X1910));
    // 0x8069BC70: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    // 0x8069BC74: jal         0x8069B8C8
    // 0x8069BC78: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_8069B8C8(rdram, ctx);
        goto after_0;
    // 0x8069BC78: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x8069BC7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069BC80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069BC84: jr          $ra
    // 0x8069BC88: nop

    return;
    // 0x8069BC88: nop

    // 0x8069BC8C: nop

;}
RECOMP_FUNC void func_807AF000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF000: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(862, 0X10) << 16);
    // 0x807AF004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x807AF008: jr          $ra
    // 0x807AF00C: addiu       $v0, $v0, -0xFF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(862, 0X10));
    return;
    // 0x807AF00C: addiu       $v0, $v0, -0xFF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(862, 0X10));
;}
RECOMP_FUNC void func_806FDB50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FDB50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806FDB54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FDB58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806FDB5C: jal         0x80057754
    // 0x806FDB60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80057754(rdram, ctx);
        goto after_0;
    // 0x806FDB60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806FDB64: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806FDB68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806FDB6C: jal         0x806FD60C
    // 0x806FDB70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806FD60C(rdram, ctx);
        goto after_1;
    // 0x806FDB70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x806FDB74: jal         0x806FD7F8
    // 0x806FDB78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FD7F8(rdram, ctx);
        goto after_2;
    // 0x806FDB78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806FDB7C: jal         0x806FD854
    // 0x806FDB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FD854(rdram, ctx);
        goto after_3;
    // 0x806FDB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806FDB84: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x806FDB88: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x806FDB8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FDB90: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806FDB94: bne         $t7, $at, L_806FDBB4
    if (ctx->r15 != ctx->r1) {
        // 0x806FDB98: sw          $t7, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r15;
            goto L_806FDBB4;
    }
    // 0x806FDB98: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x806FDB9C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806FDBA0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x806FDBA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FDBA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806FDBAC: jal         0x806FE468
    // 0x806FDBB0: lw          $a3, 0x68($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X68);
    func_806FE468(rdram, ctx);
        goto after_4;
    // 0x806FDBB0: lw          $a3, 0x68($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X68);
    after_4:
L_806FDBB4:
    // 0x806FDBB4: jal         0x806FDAE8
    // 0x806FDBB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FDAE8(rdram, ctx);
        goto after_5;
    // 0x806FDBB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806FDBBC: jal         0x806FDA5C
    // 0x806FDBC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FDA5C(rdram, ctx);
        goto after_6;
    // 0x806FDBC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x806FDBC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806FDBC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806FDBCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806FDBD0: jr          $ra
    // 0x806FDBD4: nop

    return;
    // 0x806FDBD4: nop

;}
RECOMP_FUNC void func_8079E914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079E914: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8079E918: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8079E91C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8079E920: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8079E924: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8079E928: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8079E92C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8079E930: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8079E934: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8079E938: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8079E93C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8079E940: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8079E944: addiu       $s2, $sp, 0x5C
    ctx->r18 = ADD32(ctx->r29, 0X5C);
    // 0x8079E948: addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
    // 0x8079E94C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8079E950: addiu       $s5, $sp, 0x50
    ctx->r21 = ADD32(ctx->r29, 0X50);
    // 0x8079E954: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
L_8079E958:
    // 0x8079E958: lw          $t6, 0x100($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X100);
    // 0x8079E95C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8079E960: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8079E964: beq         $t6, $zero, L_8079E9DC
    if (ctx->r14 == 0) {
        // 0x8079E968: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_8079E9DC;
    }
    // 0x8079E968: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8079E96C: jal         0x800696D4
    // 0x8079E970: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800696D4(rdram, ctx);
        goto after_0;
    // 0x8079E970: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_0:
    // 0x8079E974: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
    // 0x8079E978: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
L_8079E97C:
    // 0x8079E97C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8079E980: sltu        $at, $v0, $s2
    ctx->r1 = ctx->r2 < ctx->r18 ? 1 : 0;
    // 0x8079E984: beq         $t7, $zero, L_8079E990
    if (ctx->r15 == 0) {
        // 0x8079E988: nop
    
            goto L_8079E990;
    }
    // 0x8079E988: nop

    // 0x8079E98C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8079E990:
    // 0x8079E990: bnel        $at, $zero, L_8079E97C
    if (ctx->r1 != 0) {
        // 0x8079E994: lhu         $t7, 0x0($v0)
        ctx->r15 = MEM_HU(ctx->r2, 0X0);
            goto L_8079E97C;
    }
    goto skip_0;
    // 0x8079E994: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    skip_0:
    // 0x8079E998: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    // 0x8079E99C: sh          $t8, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r24;
    // 0x8079E9A0: lw          $a0, 0x100($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X100);
    // 0x8079E9A4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8079E9A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8079E9AC: jal         0x8005C174
    // 0x8079E9B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C174(rdram, ctx);
        goto after_1;
    // 0x8079E9B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8079E9B4: bne         $s0, $zero, L_8079E9DC
    if (ctx->r16 != 0) {
        // 0x8079E9B8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8079E9DC;
    }
    // 0x8079E9B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8079E9BC: lw          $a0, 0x100($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X100);
L_8079E9C0:
    // 0x8079E9C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8079E9C4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8079E9C8: jal         0x8005C27C
    // 0x8079E9CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x8079E9CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8079E9D0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8079E9D4: bnel        $s0, $s3, L_8079E9C0
    if (ctx->r16 != ctx->r19) {
        // 0x8079E9D8: lw          $a0, 0x100($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X100);
            goto L_8079E9C0;
    }
    goto skip_1;
    // 0x8079E9D8: lw          $a0, 0x100($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X100);
    skip_1:
L_8079E9DC:
    // 0x8079E9DC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8079E9E0: bne         $s4, $s7, L_8079E958
    if (ctx->r20 != ctx->r23) {
        // 0x8079E9E4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8079E958;
    }
    // 0x8079E9E4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8079E9E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8079E9EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8079E9F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8079E9F4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8079E9F8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8079E9FC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8079EA00: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8079EA04: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8079EA08: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8079EA0C: jr          $ra
    // 0x8079EA10: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8079EA10: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80673560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80673564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80673568: jal         0x8005FD1C
    // 0x8067356C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FD1C(rdram, ctx);
        goto after_0;
    // 0x8067356C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80673570: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80673574: lw          $t7, 0x174($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X174);
    // 0x80673578: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8067357C: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
    // 0x80673580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80673584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80673588: jr          $ra
    // 0x8067358C: nop

    return;
    // 0x8067358C: nop

;}
RECOMP_FUNC void func_8006A0F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A0F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006A0FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006A100: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006A104: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A108: jal         0x80050C8C
    // 0x8006A10C: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    func_80050C8C(rdram, ctx);
        goto after_0;
    // 0x8006A10C: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    after_0:
    // 0x8006A110: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8006A114: jal         0x80069D40
    // 0x8006A118: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80069D40(rdram, ctx);
        goto after_1;
    // 0x8006A118: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_1:
    // 0x8006A11C: bne         $v0, $zero, L_8006A12C
    if (ctx->r2 != 0) {
        // 0x8006A120: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8006A12C;
    }
    // 0x8006A120: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8006A124: b           L_8006A184
    // 0x8006A128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A184;
    // 0x8006A128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A12C:
    // 0x8006A12C: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x8006A130: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x8006A134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006A138: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006A13C: jal         0x800675D0
    // 0x8006A140: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_800675D0(rdram, ctx);
        goto after_2;
    // 0x8006A140: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_2:
    // 0x8006A144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006A148: jal         0x80069E98
    // 0x8006A14C: lhu         $a1, 0x2A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2A);
    func_80069E98(rdram, ctx);
        goto after_3;
    // 0x8006A14C: lhu         $a1, 0x2A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2A);
    after_3:
    // 0x8006A150: lhu         $t7, 0x18($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X18);
    // 0x8006A154: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006A158: sra         $t8, $t7, 14
    ctx->r24 = S32(SIGNED(ctx->r15) >> 14);
    // 0x8006A15C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8006A160: bne         $t9, $at, L_8006A178
    if (ctx->r25 != ctx->r1) {
        // 0x8006A164: nop
    
            goto L_8006A178;
    }
    // 0x8006A164: nop

    // 0x8006A168: jal         0x80069FBC
    // 0x8006A16C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80069FBC(rdram, ctx);
        goto after_4;
    // 0x8006A16C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8006A170: b           L_8006A184
    // 0x8006A174: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8006A184;
    // 0x8006A174: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8006A178:
    // 0x8006A178: jal         0x8006A084
    // 0x8006A17C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006A084(rdram, ctx);
        goto after_5;
    // 0x8006A17C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8006A180: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8006A184:
    // 0x8006A184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A188: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A18C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006A190: jr          $ra
    // 0x8006A194: nop

    return;
    // 0x8006A194: nop

;}
RECOMP_FUNC void func_806FCF6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FCF6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FCF70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FCF74: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x806FCF78: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(703, 0XA70) << 16);
    // 0x806FCF7C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806FCF80: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806FCF84: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806FCF88: lw          $t8, -0x2C80($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(703, 0XA70));
    // 0x806FCF8C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806FCF90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806FCF94: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(703, 0XA9C) << 16);
    // 0x806FCF98: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x806FCF9C: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x806FCFA0: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x806FCFA4: sw          $t8, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r24;
    // 0x806FCFA8: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x806FCFAC: lwc1        $f6, -0x2C54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(703, 0XA9C));
    // 0x806FCFB0: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x806FCFB4: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x806FCFB8: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x806FCFBC: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x806FCFC0: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x806FCFC4: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x806FCFC8: jal         0x80048378
    // 0x806FCFCC: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x806FCFCC: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    after_0:
    // 0x806FCFD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FCFD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FCFD8: jr          $ra
    // 0x806FCFDC: nop

    return;
    // 0x806FCFDC: nop

;}
RECOMP_FUNC void func_8000C19C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C19C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8000C1A0: bne         $v0, $a0, L_8000C1B0
    if (ctx->r2 != ctx->r4) {
        // 0x8000C1A4: nop
    
            goto L_8000C1B0;
    }
    // 0x8000C1A4: nop

    // 0x8000C1A8: jr          $ra
    // 0x8000C1AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000C1AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C1B0:
    // 0x8000C1B0: beq         $v0, $a0, L_8000C1E4
    if (ctx->r2 == ctx->r4) {
        // 0x8000C1B4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8000C1E4;
    }
    // 0x8000C1B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000C1B8: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
L_8000C1BC:
    // 0x8000C1BC: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8000C1C0: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x8000C1C4: lbu         $t9, 0x30($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X30);
    // 0x8000C1C8: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000C1CC: bnel        $at, $zero, L_8000C1DC
    if (ctx->r1 != 0) {
        // 0x8000C1D0: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_8000C1DC;
    }
    goto skip_0;
    // 0x8000C1D0: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x8000C1D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000C1D8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_8000C1DC:
    // 0x8000C1DC: bnel        $v0, $a0, L_8000C1BC
    if (ctx->r2 != ctx->r4) {
        // 0x8000C1E0: lw          $t6, 0x8($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X8);
            goto L_8000C1BC;
    }
    goto skip_1;
    // 0x8000C1E0: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    skip_1:
L_8000C1E4:
    // 0x8000C1E4: bnel        $v1, $zero, L_8000C1F8
    if (ctx->r3 != 0) {
        // 0x8000C1E8: lw          $a0, 0x8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X8);
            goto L_8000C1F8;
    }
    goto skip_2;
    // 0x8000C1E8: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    skip_2:
    // 0x8000C1EC: jr          $ra
    // 0x8000C1F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000C1F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000C1F4: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
L_8000C1F8:
    // 0x8000C1F8: lbu         $t0, 0x30($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X30);
    // 0x8000C1FC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000C200: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000C204: bne         $at, $zero, L_8000C214
    if (ctx->r1 != 0) {
        // 0x8000C208: nop
    
            goto L_8000C214;
    }
    // 0x8000C208: nop

    // 0x8000C20C: jr          $ra
    // 0x8000C210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000C210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C214:
    // 0x8000C214: jr          $ra
    // 0x8000C218: nop

    return;
    // 0x8000C218: nop

;}
RECOMP_FUNC void func_8042DC20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042DC20: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(53, 0X10) << 16);
    // 0x8042DC24: addiu       $v0, $v0, -0x23D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(53, 0X10));
    // 0x8042DC28: jr          $ra
    // 0x8042DC2C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8042DC2C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804F3330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F3330: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x804F3334: addiu       $at, $zero, 0x4050
    ctx->r1 = ADD32(0, 0X4050);
    // 0x804F3338: beq         $v0, $at, L_804F3344
    if (ctx->r2 == ctx->r1) {
        // 0x804F333C: addiu       $at, $zero, 0x4051
        ctx->r1 = ADD32(0, 0X4051);
            goto L_804F3344;
    }
    // 0x804F333C: addiu       $at, $zero, 0x4051
    ctx->r1 = ADD32(0, 0X4051);
    // 0x804F3340: bne         $v0, $at, L_804F3350
    if (ctx->r2 != ctx->r1) {
        // 0x804F3344: lui         $v0, 0x804F
        ctx->r2 = S32(RELOC_HI16(270, 0X9F0) << 16);
            goto L_804F3350;
    }
L_804F3344:
    // 0x804F3344: lui         $v0, 0x804F
    ctx->r2 = S32(RELOC_HI16(270, 0X9F0) << 16);
    // 0x804F3348: jr          $ra
    // 0x804F334C: addiu       $v0, $v0, 0x3D20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(270, 0X9F0));
    return;
    // 0x804F334C: addiu       $v0, $v0, 0x3D20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(270, 0X9F0));
L_804F3350:
    // 0x804F3350: lui         $v0, 0x804F
    ctx->r2 = S32(RELOC_HI16(270, 0X7BC) << 16);
    // 0x804F3354: addiu       $v0, $v0, 0x3AEC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(270, 0X7BC));
    // 0x804F3358: jr          $ra
    // 0x804F335C: nop

    return;
    // 0x804F335C: nop

;}
RECOMP_FUNC void func_806EF170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF170: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EF174: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EF178: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EF17C: jal         0x806EC16C
    // 0x806EF180: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806EC16C(rdram, ctx);
        goto after_0;
    // 0x806EF180: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EF184: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EF188: jal         0x800577D8
    // 0x806EF18C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_1;
    // 0x806EF18C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x806EF190: jal         0x806EE5E4
    // 0x806EF194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE5E4(rdram, ctx);
        goto after_2;
    // 0x806EF194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EF198: jal         0x806EE664
    // 0x806EF19C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE664(rdram, ctx);
        goto after_3;
    // 0x806EF19C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EF1A0: jal         0x806EE720
    // 0x806EF1A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE720(rdram, ctx);
        goto after_4;
    // 0x806EF1A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EF1A8: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x806EF1AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EF1B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EF1B4: blez        $v0, L_806EF1C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806EF1B8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_806EF1C8;
    }
    // 0x806EF1B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806EF1BC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x806EF1C0: b           L_806EF1D0
    // 0x806EF1C4: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
        goto L_806EF1D0;
    // 0x806EF1C4: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
L_806EF1C8:
    // 0x806EF1C8: jal         0x806EF4A0
    // 0x806EF1CC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EF4A0(rdram, ctx);
        goto after_5;
    // 0x806EF1CC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
L_806EF1D0:
    // 0x806EF1D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806EF1D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EF1D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EF1DC: jr          $ra
    // 0x806EF1E0: nop

    return;
    // 0x806EF1E0: nop

;}
RECOMP_FUNC void func_80677AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80677AEC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80677AF0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80677AF4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80677AF8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80677AFC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80677B00: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80677B04: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80677B08: lui         $t1, 0x8067
    ctx->r9 = S32(RELOC_HI16(535, 0X258C) << 16);
    // 0x80677B0C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80677B10: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80677B14: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80677B18: lw          $t1, 0x7C4C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(535, 0X258C));
    // 0x80677B1C: jr          $ra
    // 0x80677B20: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80677B20: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x80677B24: nop

    // 0x80677B28: nop

    // 0x80677B2C: nop

;}
RECOMP_FUNC void func_80024814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024814: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x80024818: lui         $t9, 0x8002
    ctx->r25 = S32(0X8002 << 16);
    // 0x8002481C: addiu       $t9, $t9, 0x4778
    ctx->r25 = ADD32(ctx->r25, 0X4778);
    // 0x80024820: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80024824: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80024828: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8002482C: sw          $t7, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r15;
    // 0x80024830: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80024834: sw          $t9, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r25;
    // 0x80024838: jr          $ra
    // 0x8002483C: sb          $t8, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r24;
    return;
    // 0x8002483C: sb          $t8, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80790CB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790CB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80790CB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80790CBC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80790CC0: jal         0x807903C4
    // 0x80790CC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807903C4(rdram, ctx);
        goto after_0;
    // 0x80790CC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80790CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80790CCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80790CD0: jr          $ra
    // 0x80790CD4: nop

    return;
    // 0x80790CD4: nop

;}
RECOMP_FUNC void func_80455450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455450: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80455454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80455458: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045545C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455460: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80455464: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80455468: lwc1        $f12, 0x6C84($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X6C84);
    // 0x8045546C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80455470: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80455474: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80455478: nop

    // 0x8045547C: bc1f        L_804554CC
    if (!c1cs) {
        // 0x80455480: nop
    
            goto L_804554CC;
    }
    // 0x80455480: nop

    // 0x80455484: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80455488: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8045548C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80455490: jal         0x80450490
    // 0x80455494: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80450490(rdram, ctx);
        goto after_0;
    // 0x80455494: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80455498: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8045549C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804554A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804554A4: lwc1        $f6, 0x6C84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X6C84);
    // 0x804554A8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804554AC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804554B0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x804554B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804554B8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804554BC: jal         0x80455274
    // 0x804554C0: swc1        $f10, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f10.u32l;
    func_80455274(rdram, ctx);
        goto after_1;
    // 0x804554C0: swc1        $f10, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f10.u32l;
    after_1:
    // 0x804554C4: b           L_804554D8
    // 0x804554C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804554D8;
    // 0x804554C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804554CC:
    // 0x804554CC: jal         0x80457164
    // 0x804554D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80457164(rdram, ctx);
        goto after_2;
    // 0x804554D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x804554D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804554D8:
    // 0x804554D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804554DC: jr          $ra
    // 0x804554E0: nop

    return;
    // 0x804554E0: nop

;}
RECOMP_FUNC void func_804CEA84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CEA84: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x804CEA88: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x804CEA8C: lwc1        $f12, 0x0($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X0);
    // 0x804CEA90: mul.s       $f14, $f0, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x804CEA94: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1AF8) << 16);
    // 0x804CEA98: lwc1        $f8, -0x258($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1AF8));
    // 0x804CEA9C: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x804CEAA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804CEAA4: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1AFC) << 16);
    // 0x804CEAA8: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x804CEAAC: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804CEAB0: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x804CEAB4: nop

    // 0x804CEAB8: bc1tl       L_804CEAF0
    if (c1cs) {
        // 0x804CEABC: div.s       $f0, $f14, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
            goto L_804CEAF0;
    }
    goto skip_0;
    // 0x804CEABC: div.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    skip_0:
    // 0x804CEAC0: lwc1        $f10, -0x254($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1AFC));
    // 0x804CEAC4: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x804CEAC8: nop

    // 0x804CEACC: bc1tl       L_804CEAF0
    if (c1cs) {
        // 0x804CEAD0: div.s       $f0, $f14, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
            goto L_804CEAF0;
    }
    goto skip_1;
    // 0x804CEAD0: div.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    skip_1:
    // 0x804CEAD4: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804CEAD8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x804CEADC: swc1        $f6, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f6.u32l;
    // 0x804CEAE0: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804CEAE4: b           L_804CEBB8
    // 0x804CEAE8: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
        goto L_804CEBB8;
    // 0x804CEAE8: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
    // 0x804CEAEC: div.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
L_804CEAF0:
    // 0x804CEAF0: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B00) << 16);
    // 0x804CEAF4: lwc1        $f10, -0x250($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B00));
    // 0x804CEAF8: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804CEAFC: addiu       $v0, $a1, 0xC4
    ctx->r2 = ADD32(ctx->r5, 0XC4);
    // 0x804CEB00: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B04) << 16);
    // 0x804CEB04: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x804CEB08: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x804CEB0C: nop

    // 0x804CEB10: mul.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x804CEB14: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804CEB18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804CEB1C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x804CEB20: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x804CEB24: swc1        $f10, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f10.u32l;
    // 0x804CEB28: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804CEB2C: swc1        $f4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f4.u32l;
    // 0x804CEB30: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x804CEB34: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x804CEB38: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804CEB3C: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x804CEB40: nop

    // 0x804CEB44: bc1f        L_804CEB58
    if (!c1cs) {
        // 0x804CEB48: nop
    
            goto L_804CEB58;
    }
    // 0x804CEB48: nop

    // 0x804CEB4C: lwc1        $f8, -0x24C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B04));
    // 0x804CEB50: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x804CEB54: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_804CEB58:
    // 0x804CEB58: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x804CEB5C: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804CEB60: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804CEB64: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x804CEB68: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x804CEB6C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x804CEB70: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x804CEB74: swc1        $f10, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f10.u32l;
    // 0x804CEB78: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804CEB7C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x804CEB80: nop

    // 0x804CEB84: bc1f        L_804CEBB8
    if (!c1cs) {
        // 0x804CEB88: nop
    
            goto L_804CEBB8;
    }
    // 0x804CEB88: nop

    // 0x804CEB8C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x804CEB90: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x804CEB94: nop

    // 0x804CEB98: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x804CEB9C: nop

    // 0x804CEBA0: bc1f        L_804CEBB8
    if (!c1cs) {
        // 0x804CEBA4: nop
    
            goto L_804CEBB8;
    }
    // 0x804CEBA4: nop

    // 0x804CEBA8: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x804CEBAC: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x804CEBB0: ori         $t7, $t6, 0x3000
    ctx->r15 = ctx->r14 | 0X3000;
    // 0x804CEBB4: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
L_804CEBB8:
    // 0x804CEBB8: jr          $ra
    // 0x804CEBBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x804CEBBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806E7A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7A60: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x806E7A64: lw          $v0, -0x77F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X77F0);
    // 0x806E7A68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E7A6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E7A70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806E7A74: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    // 0x806E7A78: jal         0x806E793C
    // 0x806E7A7C: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    func_806E793C(rdram, ctx);
        goto after_0;
    // 0x806E7A7C: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    after_0:
    // 0x806E7A80: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x806E7A84: bne         $v0, $zero, L_806E7AA8
    if (ctx->r2 != 0) {
        // 0x806E7A88: addiu       $v1, $v1, 0x7EA0
        ctx->r3 = ADD32(ctx->r3, 0X7EA0);
            goto L_806E7AA8;
    }
    // 0x806E7A88: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x806E7A8C: lw          $a0, 0x9B0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X9B0);
    // 0x806E7A90: jal         0x806E793C
    // 0x806E7A94: lh          $a1, 0x9A6($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X9A6);
    func_806E793C(rdram, ctx);
        goto after_1;
    // 0x806E7A94: lh          $a1, 0x9A6($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X9A6);
    after_1:
    // 0x806E7A98: bnel        $v0, $zero, L_806E7AAC
    if (ctx->r2 != 0) {
        // 0x806E7A9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E7AAC;
    }
    goto skip_0;
    // 0x806E7A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E7AA0: jal         0x806E77D4
    // 0x806E7AA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806E77D4(rdram, ctx);
        goto after_2;
    // 0x806E7AA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_806E7AA8:
    // 0x806E7AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E7AAC:
    // 0x806E7AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E7AB0: jr          $ra
    // 0x806E7AB4: nop

    return;
    // 0x806E7AB4: nop

;}
RECOMP_FUNC void func_8057EF14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057EF14: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8057EF18: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x8057EF1C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8057EF20: addiu       $v1, $a0, 0x188
    ctx->r3 = ADD32(ctx->r4, 0X188);
    // 0x8057EF24: addiu       $a2, $sp, 0x4
    ctx->r6 = ADD32(ctx->r29, 0X4);
    // 0x8057EF28: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_8057EF2C:
    // 0x8057EF2C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8057EF30: beql        $a0, $zero, L_8057EF58
    if (ctx->r4 == 0) {
        // 0x8057EF34: lw          $a0, 0x4($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X4);
            goto L_8057EF58;
    }
    goto skip_0;
    // 0x8057EF34: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x8057EF38: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8057EF3C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8057EF40: lhu         $t8, 0x4($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X4);
    // 0x8057EF44: bnel        $a1, $t8, L_8057EF58
    if (ctx->r5 != ctx->r24) {
        // 0x8057EF48: lw          $a0, 0x4($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X4);
            goto L_8057EF58;
    }
    goto skip_1;
    // 0x8057EF48: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x8057EF4C: b           L_8057EF90
    // 0x8057EF50: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
        goto L_8057EF90;
    // 0x8057EF50: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8057EF54: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
L_8057EF58:
    // 0x8057EF58: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8057EF5C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8057EF60: beq         $a0, $zero, L_8057EF84
    if (ctx->r4 == 0) {
        // 0x8057EF64: nop
    
            goto L_8057EF84;
    }
    // 0x8057EF64: nop

    // 0x8057EF68: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x8057EF6C: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x8057EF70: lhu         $t1, 0x4($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X4);
    // 0x8057EF74: bne         $a1, $t1, L_8057EF84
    if (ctx->r5 != ctx->r9) {
        // 0x8057EF78: nop
    
            goto L_8057EF84;
    }
    // 0x8057EF78: nop

    // 0x8057EF7C: b           L_8057EF90
    // 0x8057EF80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
        goto L_8057EF90;
    // 0x8057EF80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_8057EF84:
    // 0x8057EF84: bne         $v0, $zero, L_8057EF2C
    if (ctx->r2 != 0) {
        // 0x8057EF88: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8057EF2C;
    }
    // 0x8057EF88: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8057EF8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8057EF90:
    // 0x8057EF90: jr          $ra
    // 0x8057EF94: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8057EF94: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80011AAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011AAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80011AB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80011AB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80011AB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80011ABC: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x80011AC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011AC4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80011AC8: addiu       $a3, $zero, 0x3F
    ctx->r7 = ADD32(0, 0X3F);
    // 0x80011ACC: jal         0x8001B7B0
    // 0x80011AD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8001B7B0(rdram, ctx);
        goto after_0;
    // 0x80011AD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80011AD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80011AD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80011ADC: jr          $ra
    // 0x80011AE0: nop

    return;
    // 0x80011AE0: nop

;}
RECOMP_FUNC void func_80032D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032D1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80032D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032D24: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80032D28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80032D2C: jal         0x800415D0
    // 0x80032D30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800415D0(rdram, ctx);
        goto after_0;
    // 0x80032D30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80032D34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80032D38: beq         $v0, $zero, L_80032D48
    if (ctx->r2 == 0) {
        // 0x80032D3C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80032D48;
    }
    // 0x80032D3C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80032D40: b           L_80032D68
    // 0x80032D44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80032D68;
    // 0x80032D44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80032D48:
    // 0x80032D48: lw          $t6, 0x7C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X7C);
    // 0x80032D4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80032D50: beq         $t6, $zero, L_80032D68
    if (ctx->r14 == 0) {
        // 0x80032D54: nop
    
            goto L_80032D68;
    }
    // 0x80032D54: nop

    // 0x80032D58: jal         0x80032CA0
    // 0x80032D5C: nop

    func_80032CA0(rdram, ctx);
        goto after_1;
    // 0x80032D5C: nop

    after_1:
    // 0x80032D60: b           L_80032D68
    // 0x80032D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80032D68;
    // 0x80032D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80032D68:
    // 0x80032D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032D6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80032D70: jr          $ra
    // 0x80032D74: nop

    return;
    // 0x80032D74: nop

;}
RECOMP_FUNC void func_80553FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80553FF0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80553FF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80553FF8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80553FFC: lwc1        $f12, 0xD5C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XD5C);
    // 0x80554000: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80554004: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80554008: jal         0x80066DE4
    // 0x8055400C: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8055400C: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80554010: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80554014: jal         0x80066E88
    // 0x80554018: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80554018: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x8055401C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80554020: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80554024: lui         $v0, 0x8055
    ctx->r2 = S32(RELOC_HI16(354, 0X4020) << 16);
    // 0x80554028: lwc1        $f4, 0xDF0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XDF0);
    // 0x8055402C: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80554030: addiu       $v0, $v0, 0x4B40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(354, 0X4020));
    // 0x80554034: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80554038: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8055403C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80554040: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80554044: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80554048: lwc1        $f8, 0xDF4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XDF4);
    // 0x8055404C: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80554050: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80554054: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80554058: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8055405C: mul.s       $f16, $f2, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80554060: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80554064: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80554068: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8055406C: mul.s       $f18, $f14, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80554070: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80554074: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80554078: nop

    // 0x8055407C: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80554080: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80554084: mul.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80554088: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8055408C: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80554090: swc1        $f4, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f4.u32l;
    // 0x80554094: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80554098: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8055409C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805540A0: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x805540A4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805540A8: swc1        $f8, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f8.u32l;
    // 0x805540AC: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x805540B0: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x805540B4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x805540B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805540BC: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x805540C0: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x805540C4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x805540C8: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x805540CC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x805540D0: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x805540D4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x805540D8: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x805540DC: nop

    // 0x805540E0: mul.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x805540E4: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x805540E8: mul.s       $f8, $f16, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x805540EC: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x805540F0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x805540F4: swc1        $f6, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f6.u32l;
    // 0x805540F8: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x805540FC: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80554100: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80554104: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x80554108: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8055410C: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80554110: sub.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80554114: swc1        $f4, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f4.u32l;
    // 0x80554118: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8055411C: swc1        $f12, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->f12.u32l;
    // 0x80554120: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x80554124: swc1        $f12, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->f12.u32l;
    // 0x80554128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8055412C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80554130: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80554134: jr          $ra
    // 0x80554138: nop

    return;
    // 0x80554138: nop

;}
RECOMP_FUNC void func_8066DDBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066DDBC: jr          $ra
    // 0x8066DDC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8066DDC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806D4048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D4048: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D404C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D4050: jal         0x806D3F68
    // 0x806D4054: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_806D3F68(rdram, ctx);
        goto after_0;
    // 0x806D4054: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D4058: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D405C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806D4060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D4064: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D4068: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806D406C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x806D4070: sh          $zero, 0x26($v0)
    MEM_H(0X26, ctx->r2) = 0;
    // 0x806D4074: jal         0x806D414C
    // 0x806D4078: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_806D414C(rdram, ctx);
        goto after_1;
    // 0x806D4078: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x806D407C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D4080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806D4084: jal         0x806D30C4
    // 0x806D4088: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_806D30C4(rdram, ctx);
        goto after_2;
    // 0x806D4088: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_2:
    // 0x806D408C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D4090: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D4094: jr          $ra
    // 0x806D4098: nop

    return;
    // 0x806D4098: nop

;}
RECOMP_FUNC void func_8007340C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007340C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073414: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80073418: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007341C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80073420: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80073424: jal         0x80084820
    // 0x80073428: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _blkclr(rdram, ctx);
        goto after_0;
    // 0x80073428: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007342C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80073430: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80073434: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80073438: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007343C: sb          $t7, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r15;
    // 0x80073440: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80073444: sb          $t8, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r24;
    // 0x80073448: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8007344C: sh          $t9, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r25;
    // 0x80073450: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80073454: sh          $t0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r8;
    // 0x80073458: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8007345C: sh          $t1, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r9;
    // 0x80073460: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80073464: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x80073468: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x8007346C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80073470: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x80073474: jal         0x800732C8
    // 0x80073478: sh          $t2, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r10;
    func_800732C8(rdram, ctx);
        goto after_1;
    // 0x80073478: sh          $t2, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r10;
    after_1:
    // 0x8007347C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073484: jr          $ra
    // 0x80073488: nop

    return;
    // 0x80073488: nop

;}
RECOMP_FUNC void func_805AE534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE534: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE538: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE53C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE540: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE544: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE548: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE54C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE550: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE554: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE558: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE55C: jr          $ra
    // 0x805AE560: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE560: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8064B2E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B2E4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8064B2E8: lui         $t6, 0x8065
    ctx->r14 = S32(RELOC_HI16(495, 0X1094) << 16);
    // 0x8064B2EC: addiu       $t6, $t6, -0x4E9C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(495, 0X1094));
    // 0x8064B2F0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8064B2F4: jr          $ra
    // 0x8064B2F8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8064B2F8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8043D618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D618: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8043D61C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8043D620: lw          $v0, 0xD8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XD8);
    // 0x8043D624: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8043D628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043D62C: andi        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 & 0X7;
    // 0x8043D630: bne         $t6, $zero, L_8043D6F8
    if (ctx->r14 != 0) {
        // 0x8043D634: sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
            goto L_8043D6F8;
    }
    // 0x8043D634: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8043D638: lw          $t7, 0xEA8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XEA8);
    // 0x8043D63C: beql        $t7, $zero, L_8043D6FC
    if (ctx->r15 == 0) {
        // 0x8043D640: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043D6FC;
    }
    goto skip_0;
    // 0x8043D640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8043D644: jal         0x800653D8
    // 0x8043D648: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8043D648: nop

    after_0:
    // 0x8043D64C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8043D650: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8043D654: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8043D658: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1A28) << 16);
    // 0x8043D65C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8043D660: lwc1        $f4, -0x1598($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1A28));
    // 0x8043D664: lwc1        $f6, 0x50($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X50);
    // 0x8043D668: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8043D66C: jal         0x80066DE4
    // 0x8043D670: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8043D670: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8043D674: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8043D678: jal         0x80066E88
    // 0x8043D67C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8043D67C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8043D680: lui         $at, 0xC128
    ctx->r1 = S32(0XC128 << 16);
    // 0x8043D684: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8043D688: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8043D68C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8043D690: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8043D694: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8043D698: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8043D69C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1A08) << 16);
    // 0x8043D6A0: lw          $t1, 0x138($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X138);
    // 0x8043D6A4: mul.s       $f16, $f12, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8043D6A8: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8043D6AC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8043D6B0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8043D6B4: lwc1        $f4, -0x15B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1A08));
    // 0x8043D6B8: lui         $at, 0xC140
    ctx->r1 = S32(0XC140 << 16);
    // 0x8043D6BC: lw          $t9, -0x72B8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72B8);
    // 0x8043D6C0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8043D6C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8043D6C8: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1B8C) << 16);
    // 0x8043D6CC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8043D6D0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8043D6D4: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8043D6D8: lwc1        $f18, -0x1434($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1B8C));
    // 0x8043D6DC: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8043D6E0: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8043D6E4: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8043D6E8: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8043D6EC: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8043D6F0: jalr        $t9
    // 0x8043D6F4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8043D6F4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_3:
L_8043D6F8:
    // 0x8043D6F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043D6FC:
    // 0x8043D6FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8043D700: jr          $ra
    // 0x8043D704: nop

    return;
    // 0x8043D704: nop

;}
RECOMP_FUNC void func_804526D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804526D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804526DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804526E0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x804526E4: jal         0x804525A8
    // 0x804526E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_804525A8(rdram, ctx);
        goto after_0;
    // 0x804526E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x804526EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804526F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804526F4: jr          $ra
    // 0x804526F8: nop

    return;
    // 0x804526F8: nop

;}
RECOMP_FUNC void func_8051F4F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051F4F4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8051F4F8: lw          $t6, -0x7BC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7BC4);
    // 0x8051F4FC: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(303, 0X914) << 16);
    // 0x8051F500: addiu       $t8, $t8, -0x66C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(303, 0X914));
    // 0x8051F504: lw          $v0, 0x10C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X10C);
    // 0x8051F508: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x8051F50C: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x8051F510: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x8051F514: beq         $v0, $zero, L_8051F53C
    if (ctx->r2 == 0) {
        // 0x8051F518: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8051F53C;
    }
    // 0x8051F518: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8051F51C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8051F520: beq         $v0, $at, L_8051F57C
    if (ctx->r2 == ctx->r1) {
        // 0x8051F524: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8051F57C;
    }
    // 0x8051F524: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8051F528: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8051F52C: beq         $v0, $at, L_8051F5CC
    if (ctx->r2 == ctx->r1) {
        // 0x8051F530: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8051F5CC;
    }
    // 0x8051F530: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8051F534: b           L_8051F5CC
    // 0x8051F538: nop

        goto L_8051F5CC;
    // 0x8051F538: nop

L_8051F53C:
    // 0x8051F53C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8051F540: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_8051F544:
    // 0x8051F544: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x8051F548: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8051F54C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8051F550: sb          $t9, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r25;
    // 0x8051F554: lbu         $t0, 0x1($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X1);
    // 0x8051F558: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8051F55C: sb          $t0, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r8;
    // 0x8051F560: lbu         $t1, -0x2($a2)
    ctx->r9 = MEM_BU(ctx->r6, -0X2);
    // 0x8051F564: sb          $t1, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r9;
    // 0x8051F568: lbu         $t2, -0x1($a2)
    ctx->r10 = MEM_BU(ctx->r6, -0X1);
    // 0x8051F56C: bne         $v0, $a0, L_8051F544
    if (ctx->r2 != ctx->r4) {
        // 0x8051F570: sb          $t2, 0xC($v1)
        MEM_B(0XC, ctx->r3) = ctx->r10;
            goto L_8051F544;
    }
    // 0x8051F570: sb          $t2, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r10;
    // 0x8051F574: jr          $ra
    // 0x8051F578: nop

    return;
    // 0x8051F578: nop

L_8051F57C:
    // 0x8051F57C: lui         $t4, 0x8052
    ctx->r12 = S32(RELOC_HI16(303, 0X92C) << 16);
    // 0x8051F580: addiu       $t4, $t4, -0x654
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(303, 0X92C));
    // 0x8051F584: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x8051F588: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x8051F58C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8051F590: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_8051F594:
    // 0x8051F594: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x8051F598: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8051F59C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8051F5A0: sb          $t5, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r13;
    // 0x8051F5A4: lbu         $t6, 0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1);
    // 0x8051F5A8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8051F5AC: sb          $t6, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r14;
    // 0x8051F5B0: lbu         $t7, -0x2($a2)
    ctx->r15 = MEM_BU(ctx->r6, -0X2);
    // 0x8051F5B4: sb          $t7, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r15;
    // 0x8051F5B8: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x8051F5BC: bne         $v0, $a0, L_8051F594
    if (ctx->r2 != ctx->r4) {
        // 0x8051F5C0: sb          $t8, 0xC($v1)
        MEM_B(0XC, ctx->r3) = ctx->r24;
            goto L_8051F594;
    }
    // 0x8051F5C0: sb          $t8, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r24;
    // 0x8051F5C4: jr          $ra
    // 0x8051F5C8: nop

    return;
    // 0x8051F5C8: nop

L_8051F5CC:
    // 0x8051F5CC: lui         $t0, 0x8052
    ctx->r8 = S32(RELOC_HI16(303, 0X944) << 16);
    // 0x8051F5D0: addiu       $t0, $t0, -0x63C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(303, 0X944));
    // 0x8051F5D4: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x8051F5D8: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x8051F5DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8051F5E0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_8051F5E4:
    // 0x8051F5E4: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
    // 0x8051F5E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8051F5EC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8051F5F0: sb          $t1, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r9;
    // 0x8051F5F4: lbu         $t2, 0x1($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X1);
    // 0x8051F5F8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8051F5FC: sb          $t2, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r10;
    // 0x8051F600: lbu         $t3, -0x2($a2)
    ctx->r11 = MEM_BU(ctx->r6, -0X2);
    // 0x8051F604: sb          $t3, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r11;
    // 0x8051F608: lbu         $t4, -0x1($a2)
    ctx->r12 = MEM_BU(ctx->r6, -0X1);
    // 0x8051F60C: bne         $v0, $a0, L_8051F5E4
    if (ctx->r2 != ctx->r4) {
        // 0x8051F610: sb          $t4, 0xC($v1)
        MEM_B(0XC, ctx->r3) = ctx->r12;
            goto L_8051F5E4;
    }
    // 0x8051F610: sb          $t4, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r12;
    // 0x8051F614: jr          $ra
    // 0x8051F618: nop

    return;
    // 0x8051F618: nop

;}
RECOMP_FUNC void func_8064DEFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064DEFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064DF00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064DF04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064DF08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064DF0C: jal         0x8064DF90
    // 0x8064DF10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8064DF90(rdram, ctx);
        goto after_0;
    // 0x8064DF10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8064DF14: beq         $v0, $zero, L_8064DF74
    if (ctx->r2 == 0) {
        // 0x8064DF18: lwc1        $f4, 0x24($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8064DF74;
    }
    // 0x8064DF18: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8064DF1C: jal         0x800653D8
    // 0x8064DF20: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x8064DF20: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x8064DF24: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8064DF28: sw          $t6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r14;
    // 0x8064DF2C: jal         0x8064DFC8
    // 0x8064DF30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064DFC8(rdram, ctx);
        goto after_2;
    // 0x8064DF30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8064DF34: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8064DF38: lui         $t7, 0x8065
    ctx->r15 = S32(RELOC_HI16(498, 0XB40) << 16);
    // 0x8064DF3C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8064DF40: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8064DF44: addiu       $t7, $t7, -0x17F0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(498, 0XB40));
    // 0x8064DF48: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8064DF4C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8064DF50: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8064DF54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064DF58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064DF5C: jal         0x8064E7C0
    // 0x8064DF60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8064E7C0(rdram, ctx);
        goto after_3;
    // 0x8064DF60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8064DF64: jal         0x8064DEBC
    // 0x8064DF68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064DEBC(rdram, ctx);
        goto after_4;
    // 0x8064DF68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8064DF6C: b           L_8064DF80
    // 0x8064DF70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8064DF80;
    // 0x8064DF70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064DF74:
    // 0x8064DF74: jal         0x800445A4
    // 0x8064DF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x8064DF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8064DF7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064DF80:
    // 0x8064DF80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064DF84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064DF88: jr          $ra
    // 0x8064DF8C: nop

    return;
    // 0x8064DF8C: nop

;}
RECOMP_FUNC void func_80793830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80793830: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80793834: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80793838: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079383C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80793840: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80793844: jal         0x80793618
    // 0x80793848: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    func_80793618(rdram, ctx);
        goto after_0;
    // 0x80793848: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    after_0:
    // 0x8079384C: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80793850: lui         $t7, 0x8079
    ctx->r15 = S32(RELOC_HI16(817, 0X79E4) << 16);
    // 0x80793854: addiu       $t7, $t7, 0x7D34
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(817, 0X79E4));
    // 0x80793858: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8079385C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80793860: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80793864: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x80793868: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8079386C: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    // 0x80793870: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80793874: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80793878: jal         0x80048378
    // 0x8079387C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8079387C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    after_1:
    // 0x80793880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80793884: jal         0x80045A34
    // 0x80793888: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x80793888: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_2:
    // 0x8079388C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80793890: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80793894: jal         0x80793698
    // 0x80793898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80793698(rdram, ctx);
        goto after_3;
    // 0x80793898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8079389C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807938A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807938A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807938A8: jr          $ra
    // 0x807938AC: nop

    return;
    // 0x807938AC: nop

;}
RECOMP_FUNC void func_80033A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033A00: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80033A04: lh          $t6, -0x767C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X767C);
    // 0x80033A08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80033A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033A10: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80033A14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80033A18: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80033A1C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80033A20: jal         0x800338A8
    // 0x80033A24: nop

    func_800338A8(rdram, ctx);
        goto after_0;
    // 0x80033A24: nop

    after_0:
    // 0x80033A28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80033A2C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80033A30: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x80033A34: jal         0x80033760
    // 0x80033A38: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_80033760(rdram, ctx);
        goto after_1;
    // 0x80033A38: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_1:
    // 0x80033A3C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80033A40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80033A44: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80033A48: addiu       $t9, $zero, 0x68
    ctx->r25 = ADD32(0, 0X68);
    // 0x80033A4C: swc1        $f6, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f6.u32l;
    // 0x80033A50: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80033A54: sb          $t9, 0x18($t0)
    MEM_B(0X18, ctx->r8) = ctx->r25;
    // 0x80033A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033A5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80033A60: jr          $ra
    // 0x80033A64: nop

    return;
    // 0x80033A64: nop

;}
RECOMP_FUNC void func_8074146C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8074146C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80741470: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80741474: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80741478: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8074147C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80741480: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80741484: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x80741488: beql        $t6, $zero, L_8074154C
    if (ctx->r14 == 0) {
        // 0x8074148C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8074154C;
    }
    goto skip_0;
    // 0x8074148C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80741490: lw          $t7, 0x4C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4C);
    // 0x80741494: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80741498: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8074149C: bnel        $t7, $zero, L_8074154C
    if (ctx->r15 != 0) {
        // 0x807414A0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8074154C;
    }
    goto skip_1;
    // 0x807414A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x807414A4: lw          $t8, 0xF54($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XF54);
    // 0x807414A8: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x807414AC: beql        $t9, $zero, L_8074154C
    if (ctx->r25 == 0) {
        // 0x807414B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8074154C;
    }
    goto skip_2;
    // 0x807414B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x807414B4: lw          $t0, 0x1E0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1E0);
    // 0x807414B8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x807414BC: slti        $at, $t1, 0xB4
    ctx->r1 = SIGNED(ctx->r9) < 0XB4 ? 1 : 0;
    // 0x807414C0: bne         $at, $zero, L_80741548
    if (ctx->r1 != 0) {
        // 0x807414C4: sw          $t1, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r9;
            goto L_80741548;
    }
    // 0x807414C4: sw          $t1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r9;
    // 0x807414C8: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x807414CC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x807414D0: addiu       $a0, $zero, 0x4024
    ctx->r4 = ADD32(0, 0X4024);
    // 0x807414D4: lhu         $v0, 0xC($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0XC);
    // 0x807414D8: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    // 0x807414DC: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x807414E0: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
    // 0x807414E4: beq         $t4, $at, L_807414F4
    if (ctx->r12 == ctx->r1) {
        // 0x807414E8: andi        $t5, $v0, 0x1000
        ctx->r13 = ctx->r2 & 0X1000;
            goto L_807414F4;
    }
    // 0x807414E8: andi        $t5, $v0, 0x1000
    ctx->r13 = ctx->r2 & 0X1000;
    // 0x807414EC: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x807414F0: bne         $t5, $at, L_80741548
    if (ctx->r13 != ctx->r1) {
        // 0x807414F4: lui         $at, 0x8074
        ctx->r1 = S32(RELOC_HI16(751, 0X11EC) << 16);
            goto L_80741548;
    }
L_807414F4:
    // 0x807414F4: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X11EC) << 16);
    // 0x807414F8: lwc1        $f4, 0x204C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(751, 0X11EC));
    // 0x807414FC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80741500: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80741504: jal         0x8005CEBC
    // 0x80741508: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_0;
    // 0x80741508: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8074150C: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x80741510: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80741514: jal         0x80047F9C
    // 0x80741518: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x80741518: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8074151C: lw          $t7, 0x3C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X3C);
    // 0x80741520: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80741524: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80741528: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8074152C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80741530: jal         0x80741E44
    // 0x80741534: sb          $t6, 0x31($t7)
    MEM_B(0X31, ctx->r15) = ctx->r14;
    func_80741E44(rdram, ctx);
        goto after_2;
    // 0x80741534: sb          $t6, 0x31($t7)
    MEM_B(0X31, ctx->r15) = ctx->r14;
    after_2:
    // 0x80741538: lw          $t9, 0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X3C);
    // 0x8074153C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80741540: sw          $t8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r24;
    // 0x80741544: sb          $zero, 0x165($t9)
    MEM_B(0X165, ctx->r25) = 0;
L_80741548:
    // 0x80741548: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8074154C:
    // 0x8074154C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80741550: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80741554: jr          $ra
    // 0x80741558: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80741558: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805746D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805746D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805746D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805746D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805746DC: jal         0x80574650
    // 0x805746E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80574650(rdram, ctx);
        goto after_0;
    // 0x805746E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805746E4: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x805746E8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x805746EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805746F0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805746F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805746F8: jal         0x8005FCA8
    // 0x805746FC: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    func_8005FCA8(rdram, ctx);
        goto after_1;
    // 0x805746FC: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    after_1:
    // 0x80574700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80574704: jal         0x80574A64
    // 0x80574708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80574A64(rdram, ctx);
        goto after_2;
    // 0x80574708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8057470C: lh          $t9, 0xC0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XC0);
    // 0x80574710: lh          $t2, 0xC2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XC2);
    // 0x80574714: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(381, 0XEF0) << 16);
    // 0x80574718: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8057471C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80574720: lwc1        $f8, 0x4D80($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(381, 0XEF0));
    // 0x80574724: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80574728: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8057472C: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80574730: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80574734: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80574738: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8057473C: addiu       $at, $zero, 0x4035
    ctx->r1 = ADD32(0, 0X4035);
    // 0x80574740: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80574744: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80574748: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8057474C: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80574750: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80574754: sh          $t1, 0xC0($s0)
    MEM_H(0XC0, ctx->r16) = ctx->r9;
    // 0x80574758: beq         $v0, $at, L_8057476C
    if (ctx->r2 == ctx->r1) {
        // 0x8057475C: sh          $t4, 0xC2($s0)
        MEM_H(0XC2, ctx->r16) = ctx->r12;
            goto L_8057476C;
    }
    // 0x8057475C: sh          $t4, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r12;
    // 0x80574760: addiu       $at, $zero, 0x468C
    ctx->r1 = ADD32(0, 0X468C);
    // 0x80574764: bne         $v0, $at, L_80574788
    if (ctx->r2 != ctx->r1) {
        // 0x80574768: nop
    
            goto L_80574788;
    }
    // 0x80574768: nop

L_8057476C:
    // 0x8057476C: jal         0x80067E68
    // 0x80574770: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x80574770: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x80574774: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80574778: jal         0x80067818
    // 0x8057477C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8057477C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80574780: b           L_805747A0
    // 0x80574784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805747A0;
    // 0x80574784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80574788:
    // 0x80574788: jal         0x80067E68
    // 0x8057478C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067E68(rdram, ctx);
        goto after_5;
    // 0x8057478C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80574790: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80574794: jal         0x80067818
    // 0x80574798: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x80574798: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8057479C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805747A0:
    // 0x805747A0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x805747A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805747A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805747AC: sb          $t5, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r13;
    // 0x805747B0: jr          $ra
    // 0x805747B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805747B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8002C600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C600: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002C604: nop

    // 0x8002C608: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x8002C60C: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x8002C610: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8002C614: jr          $ra
    // 0x8002C618: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8002C618: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8001FBE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FBE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001FBEC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001FBF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001FBF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001FBF8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8001FBFC: lbu         $t7, 0x111($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X111);
    // 0x8001FC00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001FC04: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8001FC08: bnel        $t7, $zero, L_8001FD30
    if (ctx->r15 != 0) {
        // 0x8001FC0C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001FD30;
    }
    goto skip_0;
    // 0x8001FC0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8001FC10: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
    // 0x8001FC14: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8001FC18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001FC1C: beql        $t8, $at, L_8001FCF0
    if (ctx->r24 == ctx->r1) {
        // 0x8001FC20: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8001FCF0;
    }
    goto skip_1;
    // 0x8001FC20: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_1:
    // 0x8001FC24: lw          $t9, 0x2C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X2C);
    // 0x8001FC28: andi        $t0, $t9, 0x700
    ctx->r8 = ctx->r25 & 0X700;
    // 0x8001FC2C: bnel        $t0, $zero, L_8001FC70
    if (ctx->r8 != 0) {
        // 0x8001FC30: lw          $t1, 0x174($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X174);
            goto L_8001FC70;
    }
    goto skip_2;
    // 0x8001FC30: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    skip_2:
    // 0x8001FC34: jal         0x8002F1D4
    // 0x8001FC38: nop

    func_8002F1D4(rdram, ctx);
        goto after_0;
    // 0x8001FC38: nop

    after_0:
    // 0x8001FC3C: jal         0x8001D770
    // 0x8001FC40: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x8001FC40: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_1:
    // 0x8001FC44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001FC48: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8001FC4C: jal         0x80067BF8
    // 0x8001FC50: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_2;
    // 0x8001FC50: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x8001FC54: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8001FC58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FC5C: jal         0x80067838
    // 0x8001FC60: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x8001FC60: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x8001FC64: b           L_8001FD30
    // 0x8001FC68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001FD30;
    // 0x8001FC68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001FC6C: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
L_8001FC70:
    // 0x8001FC70: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001FC74: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8001FC78: lw          $t3, 0x40($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X40);
    // 0x8001FC7C: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8001FC80: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x8001FC84: beq         $t5, $zero, L_8001FD2C
    if (ctx->r13 == 0) {
        // 0x8001FC88: sh          $t4, 0x22($sp)
        MEM_H(0X22, ctx->r29) = ctx->r12;
            goto L_8001FD2C;
    }
    // 0x8001FC88: sh          $t4, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r12;
    // 0x8001FC8C: beq         $t5, $at, L_8001FD2C
    if (ctx->r13 == ctx->r1) {
        // 0x8001FC90: lbu         $v0, 0x22($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X22);
            goto L_8001FD2C;
    }
    // 0x8001FC90: lbu         $v0, 0x22($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X22);
    // 0x8001FC94: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8001FC98: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8001FC9C: beq         $v0, $at, L_8001FD2C
    if (ctx->r2 == ctx->r1) {
        // 0x8001FCA0: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8001FD2C;
    }
    // 0x8001FCA0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001FCA4: beq         $v0, $at, L_8001FD2C
    if (ctx->r2 == ctx->r1) {
        // 0x8001FCA8: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_8001FD2C;
    }
    // 0x8001FCA8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8001FCAC: bnel        $v0, $at, L_8001FD30
    if (ctx->r2 != ctx->r1) {
        // 0x8001FCB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001FD30;
    }
    goto skip_3;
    // 0x8001FCB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8001FCB4: jal         0x8002F1D4
    // 0x8001FCB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002F1D4(rdram, ctx);
        goto after_4;
    // 0x8001FCB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8001FCBC: jal         0x8001D770
    // 0x8001FCC0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_8001D770(rdram, ctx);
        goto after_5;
    // 0x8001FCC0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_5:
    // 0x8001FCC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001FCC8: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8001FCCC: jal         0x80067BF8
    // 0x8001FCD0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_6;
    // 0x8001FCD0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x8001FCD4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8001FCD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FCDC: jal         0x80067838
    // 0x8001FCE0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_7;
    // 0x8001FCE0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_7:
    // 0x8001FCE4: b           L_8001FD30
    // 0x8001FCE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001FD30;
    // 0x8001FCE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001FCEC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8001FCF0:
    // 0x8001FCF0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x8001FCF4: jal         0x80036900
    // 0x8001FCF8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80036900(rdram, ctx);
        goto after_8;
    // 0x8001FCF8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_8:
    // 0x8001FCFC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8001FD00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001FD04: jal         0x8001D770
    // 0x8001FD08: sb          $t6, 0x111($a3)
    MEM_B(0X111, ctx->r7) = ctx->r14;
    func_8001D770(rdram, ctx);
        goto after_9;
    // 0x8001FD08: sb          $t6, 0x111($a3)
    MEM_B(0X111, ctx->r7) = ctx->r14;
    after_9:
    // 0x8001FD0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001FD10: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8001FD14: jal         0x80067BF8
    // 0x8001FD18: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_10;
    // 0x8001FD18: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_10:
    // 0x8001FD1C: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8001FD20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FD24: jal         0x80067838
    // 0x8001FD28: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_11;
    // 0x8001FD28: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_11:
L_8001FD2C:
    // 0x8001FD2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001FD30:
    // 0x8001FD30: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8001FD34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001FD38: jr          $ra
    // 0x8001FD3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001FD3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800678F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800678F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800678F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800678F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800678FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067900: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067904: jal         0x800677CC
    // 0x80067908: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    func_800677CC(rdram, ctx);
        goto after_0;
    // 0x80067908: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    after_0:
    // 0x8006790C: beq         $v0, $zero, L_80067920
    if (ctx->r2 == 0) {
        // 0x80067910: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80067920;
    }
    // 0x80067910: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80067914: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x80067918: jal         0x8001759C
    // 0x8006791C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_8001759C(rdram, ctx);
        goto after_1;
    // 0x8006791C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
L_80067920:
    // 0x80067920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067928: jr          $ra
    // 0x8006792C: nop

    return;
    // 0x8006792C: nop

;}
RECOMP_FUNC void func_807A1144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A1144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A1148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A114C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A1150: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x807A1154: jal         0x807A106C
    // 0x807A1158: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    func_807A106C(rdram, ctx);
        goto after_0;
    // 0x807A1158: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_0:
    // 0x807A115C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A1160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A1164: jr          $ra
    // 0x807A1168: nop

    return;
    // 0x807A1168: nop

;}
RECOMP_FUNC void func_8079A7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079A7F8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8079A7FC: lw          $v0, -0x72E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E8);
    // 0x8079A800: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8079A804: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079A808: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8079A80C: beq         $v0, $zero, L_8079A844
    if (ctx->r2 == 0) {
        // 0x8079A810: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8079A844;
    }
    // 0x8079A810: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079A814: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079A818: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    // 0x8079A81C: jalr        $v0
    // 0x8079A820: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8079A820: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8079A824: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8079A828: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8079A82C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x8079A830: jal         0x80067D5C
    // 0x8079A834: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    func_80067D5C(rdram, ctx);
        goto after_1;
    // 0x8079A834: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    after_1:
    // 0x8079A838: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x8079A83C: jal         0x80067818
    // 0x8079A840: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8079A840: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_8079A844:
    // 0x8079A844: jal         0x800447C8
    // 0x8079A848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x8079A848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8079A84C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8079A850: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079A854: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8079A858: jr          $ra
    // 0x8079A85C: nop

    return;
    // 0x8079A85C: nop

;}
RECOMP_FUNC void func_806FE404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FE404: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806FE408: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FE40C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806FE410: jal         0x806FE318
    // 0x806FE414: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806FE318(rdram, ctx);
        goto after_0;
    // 0x806FE414: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806FE418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FE41C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FE420: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x806FE424: jal         0x806FE468
    // 0x806FE428: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806FE468(rdram, ctx);
        goto after_1;
    // 0x806FE428: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x806FE42C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x806FE430: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x806FE434: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x806FE438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FE43C: jal         0x80058B98
    // 0x806FE440: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    func_80058B98(rdram, ctx);
        goto after_2;
    // 0x806FE440: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    after_2:
    // 0x806FE444: bnel        $v0, $zero, L_806FE458
    if (ctx->r2 != 0) {
        // 0x806FE448: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806FE458;
    }
    goto skip_0;
    // 0x806FE448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806FE44C: jal         0x800447C8
    // 0x806FE450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x806FE450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806FE454: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806FE458:
    // 0x806FE458: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806FE45C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806FE460: jr          $ra
    // 0x806FE464: nop

    return;
    // 0x806FE464: nop

;}
RECOMP_FUNC void func_8043C984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043C984: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8043C988: lw          $v1, -0x7CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
    // 0x8043C98C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8043C990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043C994: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8043C998: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8043C99C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043C9A0: lw          $a1, 0x34($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X34);
    // 0x8043C9A4: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8043C9A8: lwc1        $f6, 0x34($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8043C9AC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8043C9B0: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043C9B4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8043C9B8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8043C9BC: jal         0x80066DE4
    // 0x8043C9C0: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8043C9C0: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_0:
    // 0x8043C9C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8043C9C8: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043C9CC: jal         0x80066E88
    // 0x8043C9D0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8043C9D0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8043C9D4: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8043C9D8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8043C9DC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8043C9E0: lwc1        $f10, 0x328($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X328);
    // 0x8043C9E4: lwc1        $f6, 0x32C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X32C);
    // 0x8043C9E8: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8043C9EC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8043C9F0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8043C9F4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8043C9F8: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8043C9FC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8043CA00: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8043CA04: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(89, 0X1348) << 16);
    // 0x8043CA08: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8043CA0C: lwc1        $f10, 0x944($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X944);
    // 0x8043CA10: sub.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8043CA14: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8043CA18: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8043CA1C: lwc1        $f16, 0x328($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X328);
    // 0x8043CA20: lwc1        $f18, 0x32C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X32C);
    // 0x8043CA24: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8043CA28: sub.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8043CA2C: mul.s       $f6, $f2, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8043CA30: lwc1        $f4, 0x948($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X948);
    // 0x8043CA34: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8043CA38: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8043CA3C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8043CA40: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8043CA44: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8043CA48: bc1f        L_8043CA7C
    if (!c1cs) {
        // 0x8043CA4C: swc1        $f18, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
            goto L_8043CA7C;
    }
    // 0x8043CA4C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8043CA50: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(89, 0X1344) << 16);
    // 0x8043CA54: lwc1        $f16, -0x307C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(89, 0X1344));
    // 0x8043CA58: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x8043CA5C: addiu       $t9, $zero, -0x6
    ctx->r25 = ADD32(0, -0X6);
    // 0x8043CA60: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8043CA64: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8043CA68: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8043CA6C: nop

    // 0x8043CA70: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x8043CA74: b           L_8043CA9C
    // 0x8043CA78: sw          $t0, 0x31C($v0)
    MEM_W(0X31C, ctx->r2) = ctx->r8;
        goto L_8043CA9C;
    // 0x8043CA78: sw          $t0, 0x31C($v0)
    MEM_W(0X31C, ctx->r2) = ctx->r8;
L_8043CA7C:
    // 0x8043CA7C: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8043CA80: lwc1        $f8, -0x3078($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(89, 0X1348));
    // 0x8043CA84: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8043CA88: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8043CA8C: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x8043CA90: nop

    // 0x8043CA94: addiu       $t3, $t2, -0x5
    ctx->r11 = ADD32(ctx->r10, -0X5);
    // 0x8043CA98: sw          $t3, 0x31C($v0)
    MEM_W(0X31C, ctx->r2) = ctx->r11;
L_8043CA9C:
    // 0x8043CA9C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8043CAA0: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8043CAA4: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(89, 0X1350) << 16);
    // 0x8043CAA8: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8043CAAC: nop

    // 0x8043CAB0: bc1f        L_8043CAE4
    if (!c1cs) {
        // 0x8043CAB4: nop
    
            goto L_8043CAE4;
    }
    // 0x8043CAB4: nop

    // 0x8043CAB8: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(89, 0X134C) << 16);
    // 0x8043CABC: lwc1        $f18, -0x3074($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(89, 0X134C));
    // 0x8043CAC0: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x8043CAC4: addiu       $t6, $zero, -0x5
    ctx->r14 = ADD32(0, -0X5);
    // 0x8043CAC8: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8043CACC: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8043CAD0: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8043CAD4: nop

    // 0x8043CAD8: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x8043CADC: b           L_8043CB00
    // 0x8043CAE0: sw          $t7, 0x320($v0)
    MEM_W(0X320, ctx->r2) = ctx->r15;
        goto L_8043CB00;
    // 0x8043CAE0: sw          $t7, 0x320($v0)
    MEM_W(0X320, ctx->r2) = ctx->r15;
L_8043CAE4:
    // 0x8043CAE4: lwc1        $f4, -0x3070($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(89, 0X1350));
    // 0x8043CAE8: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8043CAEC: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8043CAF0: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8043CAF4: nop

    // 0x8043CAF8: addiu       $t0, $t8, -0x4
    ctx->r8 = ADD32(ctx->r24, -0X4);
    // 0x8043CAFC: sw          $t0, 0x320($v0)
    MEM_W(0X320, ctx->r2) = ctx->r8;
L_8043CB00:
    // 0x8043CB00: lw          $t1, 0x31C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X31C);
    // 0x8043CB04: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8043CB08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8043CB0C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8043CB10: lwc1        $f10, 0x944($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X944);
    // 0x8043CB14: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8043CB18: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8043CB1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8043CB20: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8043CB24: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8043CB28: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8043CB2C: lw          $t2, 0x320($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X320);
    // 0x8043CB30: lwc1        $f10, 0x948($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X948);
    // 0x8043CB34: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8043CB38: nop

    // 0x8043CB3C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8043CB40: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8043CB44: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8043CB48: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8043CB4C: nop

    // 0x8043CB50: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8043CB54: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8043CB58: lwc1        $f10, 0x328($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X328);
    // 0x8043CB5C: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8043CB60: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8043CB64: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x8043CB68: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8043CB6C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8043CB70: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x8043CB74: lwc1        $f8, 0x32C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X32C);
    // 0x8043CB78: mul.s       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8043CB7C: nop

    // 0x8043CB80: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8043CB84: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8043CB88: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8043CB8C: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x8043CB90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043CB94: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8043CB98: jr          $ra
    // 0x8043CB9C: nop

    return;
    // 0x8043CB9C: nop

;}
RECOMP_FUNC void func_8073ED1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073ED1C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8073ED20: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x8073ED24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8073ED28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073ED2C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8073ED30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8073ED34: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8073ED38: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x8073ED3C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8073ED40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8073ED44: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8073ED48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8073ED4C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8073ED50: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8073ED54: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8073ED58: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8073ED5C: lwc1        $f4, 0x8C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8073ED60: jal         0x8073FD9C
    // 0x8073ED64: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_8073FD9C(rdram, ctx);
        goto after_0;
    // 0x8073ED64: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8073ED68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073ED6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8073ED70: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8073ED74: jr          $ra
    // 0x8073ED78: nop

    return;
    // 0x8073ED78: nop

;}
RECOMP_FUNC void func_804C5AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5AEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C5AF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C5AF4: jal         0x804C5A20
    // 0x804C5AF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C5A20(rdram, ctx);
        goto after_0;
    // 0x804C5AF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C5AFC: beql        $v0, $zero, L_804C5B10
    if (ctx->r2 == 0) {
        // 0x804C5B00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C5B10;
    }
    goto skip_0;
    // 0x804C5B00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C5B04: jal         0x804C5A80
    // 0x804C5B08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804C5A80(rdram, ctx);
        goto after_1;
    // 0x804C5B08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804C5B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C5B10:
    // 0x804C5B10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C5B14: jr          $ra
    // 0x804C5B18: nop

    return;
    // 0x804C5B18: nop

;}
RECOMP_FUNC void func_8079F660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079F660: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8079F664: addiu       $at, $zero, 0x4041
    ctx->r1 = ADD32(0, 0X4041);
    // 0x8079F668: beq         $v0, $at, L_8079F680
    if (ctx->r2 == ctx->r1) {
        // 0x8079F66C: addiu       $at, $zero, 0x4042
        ctx->r1 = ADD32(0, 0X4042);
            goto L_8079F680;
    }
    // 0x8079F66C: addiu       $at, $zero, 0x4042
    ctx->r1 = ADD32(0, 0X4042);
    // 0x8079F670: beq         $v0, $at, L_8079F68C
    if (ctx->r2 == ctx->r1) {
        // 0x8079F674: nop
    
            goto L_8079F68C;
    }
    // 0x8079F674: nop

    // 0x8079F678: b           L_8079F698
    // 0x8079F67C: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(838, 0XD00) << 16);
        goto L_8079F698;
    // 0x8079F67C: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(838, 0XD00) << 16);
L_8079F680:
    // 0x8079F680: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(838, 0XD00) << 16);
    // 0x8079F684: jr          $ra
    // 0x8079F688: addiu       $v0, $v0, 0x360
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(838, 0XD00));
    return;
    // 0x8079F688: addiu       $v0, $v0, 0x360
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(838, 0XD00));
L_8079F68C:
    // 0x8079F68C: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(838, 0XA4C) << 16);
    // 0x8079F690: jr          $ra
    // 0x8079F694: addiu       $v0, $v0, 0xAC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(838, 0XA4C));
    return;
    // 0x8079F694: addiu       $v0, $v0, 0xAC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(838, 0XA4C));
L_8079F698:
    // 0x8079F698: addiu       $v0, $v0, 0x360
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(838, 0XD00));
    // 0x8079F69C: jr          $ra
    // 0x8079F6A0: nop

    return;
    // 0x8079F6A0: nop

;}
RECOMP_FUNC void func_805A0768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A0768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A076C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A0770: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A0774: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805A0778: jal         0x8059F3CC
    // 0x805A077C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    func_8059F3CC(rdram, ctx);
        goto after_0;
    // 0x805A077C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_0:
    // 0x805A0780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A0784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A0788: jr          $ra
    // 0x805A078C: nop

    return;
    // 0x805A078C: nop

;}
RECOMP_FUNC void func_806EE5E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE5E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EE5E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EE5EC: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x806EE5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806EE5F4: beq         $t6, $zero, L_806EE630
    if (ctx->r14 == 0) {
        // 0x806EE5F8: nop
    
            goto L_806EE630;
    }
    // 0x806EE5F8: nop

    // 0x806EE5FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806EE600: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x806EE604: jalr        $t9
    // 0x806EE608: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806EE608: nop

    after_0:
    // 0x806EE60C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EE610: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x806EE614: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x806EE618: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x806EE61C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x806EE620: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x806EE624: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x806EE628: b           L_806EE630
    // 0x806EE62C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_806EE630;
    // 0x806EE62C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_806EE630:
    // 0x806EE630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EE634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EE638: jr          $ra
    // 0x806EE63C: nop

    return;
    // 0x806EE63C: nop

;}
RECOMP_FUNC void func_8079A344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079A344: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079A348: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079A34C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079A350: jal         0x80799B68
    // 0x8079A354: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80799B68(rdram, ctx);
        goto after_0;
    // 0x8079A354: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8079A358: jal         0x80799BE0
    // 0x8079A35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80799BE0(rdram, ctx);
        goto after_1;
    // 0x8079A35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8079A360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079A364: jal         0x80062684
    // 0x8079A368: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80062684(rdram, ctx);
        goto after_2;
    // 0x8079A368: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x8079A36C: jal         0x8079A15C
    // 0x8079A370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8079A15C(rdram, ctx);
        goto after_3;
    // 0x8079A370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8079A374: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X26A4) << 16);
    // 0x8079A378: lwc1        $f6, -0x4E3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X26A4));
    // 0x8079A37C: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8079A380: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X26A8) << 16);
    // 0x8079A384: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8079A388: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8079A38C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079A390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079A394: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8079A398: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    // 0x8079A39C: lwc1        $f18, -0x4E38($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X26A8));
    // 0x8079A3A0: lwc1        $f10, 0x70($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8079A3A4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8079A3A8: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8079A3AC: nop

    // 0x8079A3B0: bc1fl       L_8079A3CC
    if (!c1cs) {
        // 0x8079A3B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8079A3CC;
    }
    goto skip_0;
    // 0x8079A3B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8079A3B8: jal         0x8079AEDC
    // 0x8079A3BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8079AEDC(rdram, ctx);
        goto after_4;
    // 0x8079A3BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8079A3C0: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8079A3C4: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
    // 0x8079A3C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079A3CC:
    // 0x8079A3CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079A3D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079A3D4: jr          $ra
    // 0x8079A3D8: nop

    return;
    // 0x8079A3D8: nop

;}
RECOMP_FUNC void func_80799944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799944: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80799948: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8079994C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80799950: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80799954: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80799958: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8079995C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80799960: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(826, 0X252C) << 16);
    // 0x80799964: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80799968: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8079996C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80799970: lw          $t1, -0x4FB4($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(826, 0X252C));
    // 0x80799974: jr          $ra
    // 0x80799978: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80799978: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8001B23C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B23C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B240: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001B244: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B248: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8001B24C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001B250: sw          $t6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r14;
    // 0x8001B254: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8001B258: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001B25C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001B260: jal         0x80019E98
    // 0x8001B264: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80019E98(rdram, ctx);
        goto after_0;
    // 0x8001B264: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8001B268: lh          $a3, 0x2($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X2);
    // 0x8001B26C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001B270: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8001B274: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8001B278: bgez        $a3, L_8001B28C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8001B27C: andi        $a3, $a3, 0x7F
        ctx->r7 = ctx->r7 & 0X7F;
            goto L_8001B28C;
    }
    // 0x8001B27C: andi        $a3, $a3, 0x7F
    ctx->r7 = ctx->r7 & 0X7F;
    // 0x8001B280: beq         $a3, $zero, L_8001B28C
    if (ctx->r7 == 0) {
        // 0x8001B284: nop
    
            goto L_8001B28C;
    }
    // 0x8001B284: nop

    // 0x8001B288: addiu       $a3, $a3, -0x80
    ctx->r7 = ADD32(ctx->r7, -0X80);
L_8001B28C:
    // 0x8001B28C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8001B290: jal         0x80019E98
    // 0x8001B294: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    func_80019E98(rdram, ctx);
        goto after_1;
    // 0x8001B294: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    after_1:
    // 0x8001B298: lh          $a3, 0x2($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X2);
    // 0x8001B29C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001B2A0: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8001B2A4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8001B2A8: bgez        $a3, L_8001B2B4
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8001B2AC: addu        $at, $a3, $zero
        ctx->r1 = ADD32(ctx->r7, 0);
            goto L_8001B2B4;
    }
    // 0x8001B2AC: addu        $at, $a3, $zero
    ctx->r1 = ADD32(ctx->r7, 0);
    // 0x8001B2B0: addiu       $at, $a3, 0x7F
    ctx->r1 = ADD32(ctx->r7, 0X7F);
L_8001B2B4:
    // 0x8001B2B4: sra         $a3, $at, 7
    ctx->r7 = S32(SIGNED(ctx->r1) >> 7);
    // 0x8001B2B8: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8001B2BC: jal         0x80019E98
    // 0x8001B2C0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    func_80019E98(rdram, ctx);
        goto after_2;
    // 0x8001B2C0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    after_2:
    // 0x8001B2C4: jal         0x8001B36C
    // 0x8001B2C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001B36C(rdram, ctx);
        goto after_3;
    // 0x8001B2C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8001B2CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B2D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001B2D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B2D8: jr          $ra
    // 0x8001B2DC: nop

    return;
    // 0x8001B2DC: nop

;}
RECOMP_FUNC void func_80069B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069B34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80069B38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80069B3C: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x80069B40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80069B44: addiu       $s0, $s0, -0x6808
    ctx->r16 = ADD32(ctx->r16, -0X6808);
    // 0x80069B48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80069B4C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80069B50: addiu       $a0, $a0, -0x6A30
    ctx->r4 = ADD32(ctx->r4, -0X6A30);
    // 0x80069B54: jal         0x8007D540
    // 0x80069B58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    eepmgr_SendRead(rdram, ctx);
        goto after_0;
    // 0x80069B58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80069B5C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80069B60: jal         0x8007D508
    // 0x80069B64: addiu       $a0, $a0, -0x6A30
    ctx->r4 = ADD32(ctx->r4, -0X6A30);
    func_8007D508(rdram, ctx);
        goto after_1;
    // 0x80069B64: addiu       $a0, $a0, -0x6A30
    ctx->r4 = ADD32(ctx->r4, -0X6A30);
    after_1:
    // 0x80069B68: beq         $v0, $zero, L_80069B78
    if (ctx->r2 == 0) {
        // 0x80069B6C: nop
    
            goto L_80069B78;
    }
    // 0x80069B6C: nop

    // 0x80069B70: b           L_80069BFC
    // 0x80069B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80069BFC;
    // 0x80069B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80069B78:
    // 0x80069B78: jal         0x800699BC
    // 0x80069B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800699BC(rdram, ctx);
        goto after_2;
    // 0x80069B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80069B80: lhu         $t6, 0x3FA($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X3FA);
    // 0x80069B84: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80069B88: bne         $t6, $v0, L_80069BB8
    if (ctx->r14 != ctx->r2) {
        // 0x80069B8C: nop
    
            goto L_80069BB8;
    }
    // 0x80069B8C: nop

    // 0x80069B90: lw          $t7, 0x3FC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X3FC);
    // 0x80069B94: lui         $at, 0x8131
    ctx->r1 = S32(0X8131 << 16);
    // 0x80069B98: ori         $at, $at, 0x7531
    ctx->r1 = ctx->r1 | 0X7531;
    // 0x80069B9C: bne         $t7, $at, L_80069BB8
    if (ctx->r15 != ctx->r1) {
        // 0x80069BA0: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80069BB8;
    }
    // 0x80069BA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80069BA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80069BA8: jal         0x80065528
    // 0x80069BAC: addiu       $a2, $zero, 0x3FA
    ctx->r6 = ADD32(0, 0X3FA);
    func_80065528(rdram, ctx);
        goto after_3;
    // 0x80069BAC: addiu       $a2, $zero, 0x3FA
    ctx->r6 = ADD32(0, 0X3FA);
    after_3:
    // 0x80069BB0: b           L_80069BFC
    // 0x80069BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80069BFC;
    // 0x80069BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80069BB8:
    // 0x80069BB8: jal         0x800699BC
    // 0x80069BBC: addiu       $a0, $a0, -0x6408
    ctx->r4 = ADD32(ctx->r4, -0X6408);
    func_800699BC(rdram, ctx);
        goto after_4;
    // 0x80069BBC: addiu       $a0, $a0, -0x6408
    ctx->r4 = ADD32(ctx->r4, -0X6408);
    after_4:
    // 0x80069BC0: lhu         $t8, 0x7FA($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X7FA);
    // 0x80069BC4: bnel        $t8, $v0, L_80069BFC
    if (ctx->r24 != ctx->r2) {
        // 0x80069BC8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80069BFC;
    }
    goto skip_0;
    // 0x80069BC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80069BCC: lw          $t9, 0x7FC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7FC);
    // 0x80069BD0: lui         $at, 0x8131
    ctx->r1 = S32(0X8131 << 16);
    // 0x80069BD4: ori         $at, $at, 0x7531
    ctx->r1 = ctx->r1 | 0X7531;
    // 0x80069BD8: bne         $t9, $at, L_80069BF8
    if (ctx->r25 != ctx->r1) {
        // 0x80069BDC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80069BF8;
    }
    // 0x80069BDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80069BE0: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80069BE4: addiu       $a1, $a1, -0x6408
    ctx->r5 = ADD32(ctx->r5, -0X6408);
    // 0x80069BE8: jal         0x80065528
    // 0x80069BEC: addiu       $a2, $zero, 0x3FA
    ctx->r6 = ADD32(0, 0X3FA);
    func_80065528(rdram, ctx);
        goto after_5;
    // 0x80069BEC: addiu       $a2, $zero, 0x3FA
    ctx->r6 = ADD32(0, 0X3FA);
    after_5:
    // 0x80069BF0: b           L_80069BFC
    // 0x80069BF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80069BFC;
    // 0x80069BF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80069BF8:
    // 0x80069BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80069BFC:
    // 0x80069BFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80069C00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80069C04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80069C08: jr          $ra
    // 0x80069C0C: nop

    return;
    // 0x80069C0C: nop

;}
RECOMP_FUNC void func_8044BAE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BAE8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8044BAEC: jr          $ra
    // 0x8044BAF0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8044BAF0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_8000DD00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DD00: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000DD04: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000DD08: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8000DD0C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000DD10: andi        $t7, $v1, 0x80
    ctx->r15 = ctx->r3 & 0X80;
    // 0x8000DD14: beq         $t7, $zero, L_8000DD38
    if (ctx->r15 == 0) {
        // 0x8000DD18: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_8000DD38;
    }
    // 0x8000DD18: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8000DD1C: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x8000DD20: sll         $v1, $a1, 8
    ctx->r3 = S32(ctx->r5 << 8);
    // 0x8000DD24: andi        $v1, $v1, 0x7F00
    ctx->r3 = ctx->r3 & 0X7F00;
    // 0x8000DD28: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8000DD2C: or          $v1, $t8, $v1
    ctx->r3 = ctx->r24 | ctx->r3;
    // 0x8000DD30: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8000DD34: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
L_8000DD38:
    // 0x8000DD38: jr          $ra
    // 0x8000DD3C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000DD3C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_805154A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805154A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805154A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805154A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805154AC: lui         $a0, 0x8051
    ctx->r4 = S32(RELOC_HI16(276, 0X1130) << 16);
    // 0x805154B0: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(276, 0X1150) << 16);
    // 0x805154B4: addiu       $a1, $a1, 0x65F0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(276, 0X1150));
    // 0x805154B8: addiu       $a0, $a0, 0x65D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(276, 0X1130));
    // 0x805154BC: jal         0x8004667C
    // 0x805154C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x805154C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x805154C4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x805154C8: lui         $a2, 0x8051
    ctx->r6 = S32(RELOC_HI16(276, 0X958) << 16);
    // 0x805154CC: addiu       $a2, $a2, 0x5DF8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(276, 0X958));
    // 0x805154D0: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x805154D4: jal         0x80057B28
    // 0x805154D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x805154D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x805154DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805154E0: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0X113C) << 16);
    // 0x805154E4: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(276, 0X27C) << 16);
    // 0x805154E8: sw          $zero, 0x65DC($at)
    MEM_W((int16_t)RELOC_LO16(276, 0X113C), ctx->r1) = 0;
    // 0x805154EC: addiu       $v0, $v0, 0x571C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(276, 0X27C));
    // 0x805154F0: jr          $ra
    // 0x805154F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805154F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8043FB94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043FB94: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8043FB98: lwc1        $f6, 0xEC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8043FB9C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8043FBA0: jr          $ra
    // 0x8043FBA4: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8043FBA4: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_805A4068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A4068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A406C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A4070: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A4074: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805A4078: jal         0x80047090
    // 0x805A407C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805A407C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x805A4080: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x805A4084: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x805A4088: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x805A408C: lw          $a3, 0x8C($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8C);
    // 0x805A4090: lw          $a2, 0x88($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X88);
    // 0x805A4094: lw          $a1, 0x84($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X84);
    // 0x805A4098: jal         0x8004613C
    // 0x805A409C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x805A409C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    after_1:
    // 0x805A40A0: lhu         $t7, 0x1E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1E);
    // 0x805A40A4: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x805A40A8: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x805A40AC: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x805A40B0: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x805A40B4: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    // 0x805A40B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A40BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A40C0: jr          $ra
    // 0x805A40C4: nop

    return;
    // 0x805A40C4: nop

;}
RECOMP_FUNC void func_8004DFC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DFC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004DFCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004DFD0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004DFD4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004DFD8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8004DFDC: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8004DFE0: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8004DFE4: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8004DFE8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004DFEC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004DFF0: addu        $v1, $t8, $t0
    ctx->r3 = ADD32(ctx->r24, ctx->r8);
    // 0x8004DFF4: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8004DFF8: beql        $v0, $zero, L_8004E0A8
    if (ctx->r2 == 0) {
        // 0x8004DFFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E0A8;
    }
    goto skip_0;
    // 0x8004DFFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004E000: beql        $v0, $at, L_8004E0A8
    if (ctx->r2 == ctx->r1) {
        // 0x8004E004: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E0A8;
    }
    goto skip_1;
    // 0x8004E004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004E008: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8004E00C: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004E010: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8004E014: beq         $v0, $at, L_8004E0A4
    if (ctx->r2 == ctx->r1) {
        // 0x8004E018: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004E0A4;
    }
    // 0x8004E018: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004E01C: beq         $v0, $at, L_8004E0A4
    if (ctx->r2 == ctx->r1) {
        // 0x8004E020: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8004E0A4;
    }
    // 0x8004E020: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004E024: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8004E028: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8004E02C: jal         0x8004D06C
    // 0x8004E030: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D06C(rdram, ctx);
        goto after_0;
    // 0x8004E030: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004E034: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8004E038: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8004E03C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8004E040: lbu         $t1, 0x14($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X14);
    // 0x8004E044: beql        $t1, $zero, L_8004E0A8
    if (ctx->r9 == 0) {
        // 0x8004E048: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E0A8;
    }
    goto skip_2;
    // 0x8004E048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8004E04C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8004E050: lhu         $v0, 0x4C($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X4C);
    // 0x8004E054: andi        $t3, $v0, 0x100
    ctx->r11 = ctx->r2 & 0X100;
    // 0x8004E058: bne         $t3, $zero, L_8004E074
    if (ctx->r11 != 0) {
        // 0x8004E05C: nop
    
            goto L_8004E074;
    }
    // 0x8004E05C: nop

    // 0x8004E060: lbu         $t4, 0x18($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X18);
    // 0x8004E064: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x8004E068: andi        $t5, $v0, 0x200
    ctx->r13 = ctx->r2 & 0X200;
    // 0x8004E06C: bne         $t4, $at, L_8004E084
    if (ctx->r12 != ctx->r1) {
        // 0x8004E070: nop
    
            goto L_8004E084;
    }
    // 0x8004E070: nop

L_8004E074:
    // 0x8004E074: jal         0x8004DA60
    // 0x8004E078: nop

    func_8004DA60(rdram, ctx);
        goto after_1;
    // 0x8004E078: nop

    after_1:
    // 0x8004E07C: b           L_8004E098
    // 0x8004E080: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
        goto L_8004E098;
    // 0x8004E080: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_8004E084:
    // 0x8004E084: beql        $t5, $zero, L_8004E09C
    if (ctx->r13 == 0) {
        // 0x8004E088: lw          $t6, 0x8($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X8);
            goto L_8004E09C;
    }
    goto skip_3;
    // 0x8004E088: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    skip_3:
    // 0x8004E08C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004E090: nop

    // 0x8004E094: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
L_8004E098:
    // 0x8004E098: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
L_8004E09C:
    // 0x8004E09C: ori         $t7, $t6, 0xF
    ctx->r15 = ctx->r14 | 0XF;
    // 0x8004E0A0: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
L_8004E0A4:
    // 0x8004E0A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004E0A8:
    // 0x8004E0A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004E0AC: jr          $ra
    // 0x8004E0B0: nop

    return;
    // 0x8004E0B0: nop

;}
RECOMP_FUNC void func_8043029C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043029C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804302A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804302A4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804302A8: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BF4) << 16);
    // 0x804302AC: lwc1        $f0, 0x1CD4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BF4));
    // 0x804302B0: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BF8) << 16);
    // 0x804302B4: lwc1        $f6, 0x1CD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BF8));
    // 0x804302B8: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x804302BC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804302C0: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x804302C4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804302C8: lwc1        $f12, 0x1C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x804302CC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x804302D0: nop

    // 0x804302D4: bc1f        L_804302E8
    if (!c1cs) {
        // 0x804302D8: nop
    
            goto L_804302E8;
    }
    // 0x804302D8: nop

    // 0x804302DC: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x804302E0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804302E4: lwc1        $f12, 0x1C($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X1C);
L_804302E8:
    // 0x804302E8: jal         0x80082730
    // 0x804302EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    fsin(rdram, ctx);
        goto after_0;
    // 0x804302EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x804302F0: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BFC) << 16);
    // 0x804302F4: lwc1        $f10, 0x1CDC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BFC));
    // 0x804302F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804302FC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80430300: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80430304: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80430308: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043030C: lwc1        $f12, 0x1C($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x80430310: jal         0x8008D250
    // 0x80430314: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    fcos(rdram, ctx);
        goto after_1;
    // 0x80430314: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80430318: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3C00) << 16);
    // 0x8043031C: lwc1        $f18, 0x1CE0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3C00));
    // 0x80430320: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80430324: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80430328: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8043032C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3C04) << 16);
    // 0x80430330: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80430334: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430338: lwc1        $f8, 0x1CE4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3C04));
    // 0x8043033C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80430340: lwc1        $f6, 0x1C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80430344: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80430348: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3C08) << 16);
    // 0x8043034C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80430350: lwc1        $f4, 0x1CE8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3C08));
    // 0x80430354: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3C0C) << 16);
    // 0x80430358: lwc1        $f8, 0x1CEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3C0C));
    // 0x8043035C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80430360: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80430364: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80430368: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x8043036C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80430370: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80430374: jr          $ra
    // 0x80430378: nop

    return;
    // 0x80430378: nop

;}
RECOMP_FUNC void func_80582804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582804: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80582808: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8058280C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80582810: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80582814: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80582818: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8058281C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80582820: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80582824: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80582828: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8058282C: jal         0x8005C27C
    // 0x80582830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x80582830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80582834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582838: lhu         $a1, 0x0($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X0);
    // 0x8058283C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80582840: jal         0x8005C27C
    // 0x80582844: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x80582844: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
    // 0x80582848: addiu       $a2, $s2, 0x8
    ctx->r6 = ADD32(ctx->r18, 0X8);
    // 0x8058284C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80582850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80582858: jal         0x8005C27C
    // 0x8058285C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x8058285C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_2:
    // 0x80582860: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80582864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582868: lhu         $a1, 0x2($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X2);
    // 0x8058286C: jal         0x8005C27C
    // 0x80582870: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_3;
    // 0x80582870: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_3:
    // 0x80582874: addiu       $a2, $s2, 0x10
    ctx->r6 = ADD32(ctx->r18, 0X10);
    // 0x80582878: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8058287C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80582884: jal         0x8005C27C
    // 0x80582888: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_4;
    // 0x80582888: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_4:
    // 0x8058288C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80582890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582894: lhu         $a1, 0x4($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X4);
    // 0x80582898: jal         0x8005C27C
    // 0x8058289C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_5;
    // 0x8058289C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_5:
    // 0x805828A0: addiu       $a2, $s2, 0x18
    ctx->r6 = ADD32(ctx->r18, 0X18);
    // 0x805828A4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x805828A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805828AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805828B0: jal         0x8005C27C
    // 0x805828B4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_6;
    // 0x805828B4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_6:
    // 0x805828B8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x805828BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805828C0: lhu         $a1, 0x6($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X6);
    // 0x805828C4: jal         0x8005C27C
    // 0x805828C8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_7;
    // 0x805828C8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_7:
    // 0x805828CC: addiu       $a2, $s2, 0x20
    ctx->r6 = ADD32(ctx->r18, 0X20);
    // 0x805828D0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x805828D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805828D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805828DC: jal         0x8005C27C
    // 0x805828E0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_8;
    // 0x805828E0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_8:
    // 0x805828E4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x805828E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805828EC: lhu         $a1, 0x8($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X8);
    // 0x805828F0: jal         0x8005C27C
    // 0x805828F4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_9;
    // 0x805828F4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_9:
    // 0x805828F8: addiu       $a2, $s2, 0x28
    ctx->r6 = ADD32(ctx->r18, 0X28);
    // 0x805828FC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80582900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80582908: jal         0x8005C27C
    // 0x8058290C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_10;
    // 0x8058290C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_10:
    // 0x80582910: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80582914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582918: lhu         $a1, 0xA($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0XA);
    // 0x8058291C: jal         0x8005C27C
    // 0x80582920: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_11;
    // 0x80582920: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_11:
    // 0x80582924: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80582928: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8058292C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80582930: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80582934: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80582938: jr          $ra
    // 0x8058293C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8058293C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80437814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437814: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80437818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043781C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80437820: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80437824: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80437828: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8043782C: jal         0x80065490
    // 0x80437830: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x80437830: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80437834: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80437838: lw          $t7, 0x174($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X174);
    // 0x8043783C: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x80437840: lh          $t9, 0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XC);
    // 0x80437844: lh          $t0, 0x6($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X6);
    // 0x80437848: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x8043784C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80437850: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80437854: lwc1        $f0, 0x4($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80437858: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8043785C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80437860: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80437864: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80437868: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8043786C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80437870: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80437874: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80437878: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8043787C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80437880: bc1f        L_804378BC
    if (!c1cs) {
        // 0x80437884: nop
    
            goto L_804378BC;
    }
    // 0x80437884: nop

    // 0x80437888: jal         0x804373F0
    // 0x8043788C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_804373F0(rdram, ctx);
        goto after_1;
    // 0x8043788C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80437890: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80437894: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437898: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8043789C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x804378A0: nop

    // 0x804378A4: bc1fl       L_804378F8
    if (!c1cs) {
        // 0x804378A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804378F8;
    }
    goto skip_0;
    // 0x804378A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804378AC: jal         0x804374E8
    // 0x804378B0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_804374E8(rdram, ctx);
        goto after_2;
    // 0x804378B0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x804378B4: b           L_804378F8
    // 0x804378B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804378F8;
    // 0x804378B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804378BC:
    // 0x804378BC: jal         0x804373F0
    // 0x804378C0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_804373F0(rdram, ctx);
        goto after_3;
    // 0x804378C0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x804378C4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x804378C8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x804378CC: jal         0x804374A8
    // 0x804378D0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_804374A8(rdram, ctx);
        goto after_4;
    // 0x804378D0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x804378D4: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804378D8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x804378DC: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x804378E0: nop

    // 0x804378E4: bc1fl       L_804378F8
    if (!c1cs) {
        // 0x804378E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804378F8;
    }
    goto skip_1;
    // 0x804378E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804378EC: jal         0x8043752C
    // 0x804378F0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_8043752C(rdram, ctx);
        goto after_5;
    // 0x804378F0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_5:
    // 0x804378F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804378F8:
    // 0x804378F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x804378FC: jr          $ra
    // 0x80437900: nop

    return;
    // 0x80437900: nop

;}
RECOMP_FUNC void func_8004E708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E708: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004E70C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004E710: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004E714: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8004E718: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004E71C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004E720: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8004E724: jal         0x80047AB8
    // 0x8004E728: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8004E728: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8004E72C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8004E730: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8004E734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E738: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004E73C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004E740: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x8004E744: jal         0x8004DAA0
    // 0x8004E748: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
    func_8004DAA0(rdram, ctx);
        goto after_1;
    // 0x8004E748: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
    after_1:
    // 0x8004E74C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E750: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004E754: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004E758: jal         0x8004DC08
    // 0x8004E75C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    func_8004DC08(rdram, ctx);
        goto after_2;
    // 0x8004E75C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x8004E760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E764: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004E768: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8004E76C: jal         0x8004DE6C
    // 0x8004E770: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    func_8004DE6C(rdram, ctx);
        goto after_3;
    // 0x8004E770: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x8004E774: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E778: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004E77C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8004E780: jal         0x8004DFC8
    // 0x8004E784: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    func_8004DFC8(rdram, ctx);
        goto after_4;
    // 0x8004E784: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x8004E788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004E78C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004E790: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8004E794: jr          $ra
    // 0x8004E798: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8004E798: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8045329C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045329C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804532A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804532A4: jal         0x804531D0
    // 0x804532A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804531D0(rdram, ctx);
        goto after_0;
    // 0x804532A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804532AC: beql        $v0, $zero, L_804532C0
    if (ctx->r2 == 0) {
        // 0x804532B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804532C0;
    }
    goto skip_0;
    // 0x804532B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804532B4: jal         0x8045287C
    // 0x804532B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8045287C(rdram, ctx);
        goto after_1;
    // 0x804532B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804532BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804532C0:
    // 0x804532C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804532C4: jr          $ra
    // 0x804532C8: nop

    return;
    // 0x804532C8: nop

;}
RECOMP_FUNC void func_8002674C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002674C: lbu         $t6, 0x158($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X158);
    // 0x80026750: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x80026754: addiu       $t7, $t7, 0x68BC
    ctx->r15 = ADD32(ctx->r15, 0X68BC);
    // 0x80026758: bne         $t6, $zero, L_80026770
    if (ctx->r14 != 0) {
        // 0x8002675C: lui         $v0, 0x8010
        ctx->r2 = S32(0X8010 << 16);
            goto L_80026770;
    }
    // 0x8002675C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80026760: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80026764: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
    // 0x80026768: jr          $ra
    // 0x8002676C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002676C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80026770:
    // 0x80026770: lh          $v0, -0x7680($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X7680);
    // 0x80026774: bgtz        $v0, L_80026784
    if (SIGNED(ctx->r2) > 0) {
        // 0x80026778: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_80026784;
    }
    // 0x80026778: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8002677C: b           L_80026790
    // 0x80026780: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
        goto L_80026790;
    // 0x80026780: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_80026784:
    // 0x80026784: beql        $at, $zero, L_80026794
    if (ctx->r1 == 0) {
        // 0x80026788: lw          $t8, 0x154($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X154);
            goto L_80026794;
    }
    goto skip_0;
    // 0x80026788: lw          $t8, 0x154($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X154);
    skip_0:
    // 0x8002678C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80026790:
    // 0x80026790: lw          $t8, 0x154($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X154);
L_80026794:
    // 0x80026794: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x80026798: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8002679C: sw          $t9, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r25;
    // 0x800267A0: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800267A4: sltu        $at, $t1, $t9
    ctx->r1 = ctx->r9 < ctx->r25 ? 1 : 0;
    // 0x800267A8: beq         $at, $zero, L_80026804
    if (ctx->r1 == 0) {
        // 0x800267AC: nop
    
            goto L_80026804;
    }
    // 0x800267AC: nop

    // 0x800267B0: lw          $t5, 0x14C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X14C);
    // 0x800267B4: lbu         $t3, 0x158($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X158);
    // 0x800267B8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800267BC: sltiu       $at, $t6, 0xF
    ctx->r1 = ctx->r14 < 0XF ? 1 : 0;
    // 0x800267C0: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800267C4: sb          $t4, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r12;
    // 0x800267C8: bne         $at, $zero, L_800267D4
    if (ctx->r1 != 0) {
        // 0x800267CC: sw          $t6, 0x14C($a0)
        MEM_W(0X14C, ctx->r4) = ctx->r14;
            goto L_800267D4;
    }
    // 0x800267CC: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    // 0x800267D0: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
L_800267D4:
    // 0x800267D4: lw          $v1, 0x15C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X15C);
    // 0x800267D8: lw          $v0, 0x154($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X154);
    // 0x800267DC: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x800267E0: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800267E4: beq         $at, $zero, L_80026804
    if (ctx->r1 == 0) {
        // 0x800267E8: subu        $t8, $v0, $a1
        ctx->r24 = SUB32(ctx->r2, ctx->r5);
            goto L_80026804;
    }
    // 0x800267E8: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
L_800267EC:
    // 0x800267EC: sw          $t8, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r24;
    // 0x800267F0: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x800267F4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800267F8: sltu        $at, $a1, $t8
    ctx->r1 = ctx->r5 < ctx->r24 ? 1 : 0;
    // 0x800267FC: bnel        $at, $zero, L_800267EC
    if (ctx->r1 != 0) {
        // 0x80026800: subu        $t8, $v0, $a1
        ctx->r24 = SUB32(ctx->r2, ctx->r5);
            goto L_800267EC;
    }
    goto skip_1;
    // 0x80026800: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    skip_1:
L_80026804:
    // 0x80026804: jr          $ra
    // 0x80026808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80026808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8078F9E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F9E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078F9EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078F9F0: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8078F9F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8078F9F8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8078F9FC: andi        $t8, $t7, 0xF00
    ctx->r24 = ctx->r15 & 0XF00;
    // 0x8078FA00: beql        $t8, $zero, L_8078FA18
    if (ctx->r24 == 0) {
        // 0x8078FA04: lwc1        $f12, 0xC8($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
            goto L_8078FA18;
    }
    goto skip_0;
    // 0x8078FA04: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    skip_0:
    // 0x8078FA08: jal         0x8078FD04
    // 0x8078FA0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8078FD04(rdram, ctx);
        goto after_0;
    // 0x8078FA0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8078FA10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8078FA14: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
L_8078FA18:
    // 0x8078FA18: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8078FA1C: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8078FA20: jal         0x80065ABC
    // 0x8078FA24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x8078FA24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8078FA28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8078FA2C: jal         0x8078F86C
    // 0x8078FA30: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    func_8078F86C(rdram, ctx);
        goto after_2;
    // 0x8078FA30: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    after_2:
    // 0x8078FA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078FA38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078FA3C: jr          $ra
    // 0x8078FA40: nop

    return;
    // 0x8078FA40: nop

;}
RECOMP_FUNC void func_800487A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800487A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800487A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800487AC: lbu         $t7, 0x158($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X158);
    // 0x800487B0: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x800487B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800487B8: bne         $t7, $at, L_800487F4
    if (ctx->r15 != ctx->r1) {
        // 0x800487BC: sw          $t6, 0x150($a0)
        MEM_W(0X150, ctx->r4) = ctx->r14;
            goto L_800487F4;
    }
    // 0x800487BC: sw          $t6, 0x150($a0)
    MEM_W(0X150, ctx->r4) = ctx->r14;
    // 0x800487C0: jal         0x80048690
    // 0x800487C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048690(rdram, ctx);
        goto after_0;
    // 0x800487C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800487C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800487CC: bne         $v0, $at, L_80048838
    if (ctx->r2 != ctx->r1) {
        // 0x800487D0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80048838;
    }
    // 0x800487D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800487D4: addiu       $v1, $a0, 0x14C
    ctx->r3 = ADD32(ctx->r4, 0X14C);
    // 0x800487D8: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800487DC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800487E0: sb          $t8, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r24;
    // 0x800487E4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800487E8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800487EC: b           L_8004883C
    // 0x800487F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8004883C;
    // 0x800487F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800487F4:
    // 0x800487F4: addiu       $v1, $a0, 0x14C
    ctx->r3 = ADD32(ctx->r4, 0X14C);
    // 0x800487F8: lbu         $t1, 0xC($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XC);
    // 0x800487FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80048800: bnel        $t1, $at, L_8004883C
    if (ctx->r9 != ctx->r1) {
        // 0x80048804: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004883C;
    }
    goto skip_0;
    // 0x80048804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80048808: jal         0x80048720
    // 0x8004880C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80048720(rdram, ctx);
        goto after_1;
    // 0x8004880C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x80048810: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80048814: bne         $v0, $at, L_80048838
    if (ctx->r2 != ctx->r1) {
        // 0x80048818: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80048838;
    }
    // 0x80048818: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8004881C: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x80048820: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80048824: sb          $t2, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r10;
    // 0x80048828: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8004882C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80048830: b           L_8004883C
    // 0x80048834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8004883C;
    // 0x80048834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80048838:
    // 0x80048838: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004883C:
    // 0x8004883C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80048844: jr          $ra
    // 0x80048848: nop

    return;
    // 0x80048848: nop

;}
RECOMP_FUNC void func_80453BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453BDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453BE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453BE4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80453BE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80453BEC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453BF0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80453BF4: swc1        $f4, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f4.u32l;
    // 0x80453BF8: jal         0x804449C0
    // 0x80453BFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804449C0(rdram, ctx);
        goto after_0;
    // 0x80453BFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80453C00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80453C04: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80453C08: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80453C0C: jal         0x80450490
    // 0x80453C10: nop

    func_80450490(rdram, ctx);
        goto after_1;
    // 0x80453C10: nop

    after_1:
    // 0x80453C14: jal         0x80445760
    // 0x80453C18: nop

    func_80445760(rdram, ctx);
        goto after_2;
    // 0x80453C18: nop

    after_2:
    // 0x80453C1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80453C20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80453C24: jal         0x80457164
    // 0x80453C28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80457164(rdram, ctx);
        goto after_3;
    // 0x80453C28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80453C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453C30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453C34: jr          $ra
    // 0x80453C38: nop

    return;
    // 0x80453C38: nop

;}
RECOMP_FUNC void func_8067E3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E3E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067E3EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067E3F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8067E3F4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8067E3F8: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8067E3FC: jal         0x80067BBC
    // 0x8067E400: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8067E400: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x8067E404: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8067E408: jal         0x80067818
    // 0x8067E40C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8067E40C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8067E410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067E414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067E418: jr          $ra
    // 0x8067E41C: nop

    return;
    // 0x8067E41C: nop

;}
RECOMP_FUNC void func_805552EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805552EC: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x805552F0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x805552F4: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x805552F8: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x805552FC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80555300: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80555304: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80555308: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8055530C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80555310: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80555314: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80555318: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8055531C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80555320: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80555324: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80555328: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8055532C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80555330: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x80555334: sw          $a2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r6;
    // 0x80555338: lw          $v1, 0x548($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X548);
    // 0x8055533C: sll         $s0, $a1, 16
    ctx->r16 = S32(ctx->r5 << 16);
    // 0x80555340: addiu       $s1, $a0, 0x2D0
    ctx->r17 = ADD32(ctx->r4, 0X2D0);
    // 0x80555344: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80555348: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8055534C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80555350: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80555354: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x80555358: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8055535C: addiu       $s6, $a0, 0x368
    ctx->r22 = ADD32(ctx->r4, 0X368);
    // 0x80555360: addiu       $s5, $a0, 0x378
    ctx->r21 = ADD32(ctx->r4, 0X378);
    // 0x80555364: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x80555368: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x8055536C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80555370:
    // 0x80555370: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80555374: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x80555378: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x8055537C: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x80555380: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80555384: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80555388: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // 0x8055538C: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x80555390: lwc1        $f8, -0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X40);
    // 0x80555394: bne         $at, $zero, L_805553A4
    if (ctx->r1 != 0) {
        // 0x80555398: swc1        $f8, 0x8($s1)
        MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
            goto L_805553A4;
    }
    // 0x80555398: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    // 0x8055539C: addiu       $v1, $v1, -0x3C
    ctx->r3 = ADD32(ctx->r3, -0X3C);
    // 0x805553A0: addiu       $v0, $v0, -0x2D0
    ctx->r2 = ADD32(ctx->r2, -0X2D0);
L_805553A4:
    // 0x805553A4: slti        $at, $s3, 0xA
    ctx->r1 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x805553A8: bne         $at, $zero, L_80555370
    if (ctx->r1 != 0) {
        // 0x805553AC: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80555370;
    }
    // 0x805553AC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x805553B0: lwc1        $f2, 0x2D0($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X2D0);
    // 0x805553B4: lwc1        $f4, 0x2DC($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X2DC);
    // 0x805553B8: lwc1        $f16, 0x2D4($fp)
    ctx->f16.u32l = MEM_W(ctx->r30, 0X2D4);
    // 0x805553BC: lwc1        $f6, 0x2E0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X2E0);
    // 0x805553C0: sub.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x805553C4: lwc1        $f10, 0x0($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X0);
    // 0x805553C8: lwc1        $f18, 0x4($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X4);
    // 0x805553CC: sub.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x805553D0: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x805553D4: sub.s       $f26, $f2, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x805553D8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x805553DC: sub.s       $f28, $f16, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x805553E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x805553E4: nop

    // 0x805553E8: c.eq.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl == ctx->f18.fl;
    // 0x805553EC: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x805553F0: bc1f        L_8055541C
    if (!c1cs) {
        // 0x805553F4: sqrt.s      $f24, $f0
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = sqrtf(ctx->f0.fl);
            goto L_8055541C;
    }
    // 0x805553F4: sqrt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = sqrtf(ctx->f0.fl);
    // 0x805553F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805553FC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80555400: c.eq.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl == ctx->f4.fl;
    // 0x80555404: nop

    // 0x80555408: bc1f        L_8055541C
    if (!c1cs) {
        // 0x8055540C: nop
    
            goto L_8055541C;
    }
    // 0x8055540C: nop

    // 0x80555410: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80555414: b           L_80555428
    // 0x80555418: nop

        goto L_80555428;
    // 0x80555418: nop

L_8055541C:
    // 0x8055541C: jal         0x80067114
    // 0x80555420: nop

    func_80067114(rdram, ctx);
        goto after_0;
    // 0x80555420: nop

    after_0:
    // 0x80555424: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
L_80555428:
    // 0x80555428: jal         0x80066DE4
    // 0x8055542C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8055542C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x80555430: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80555434: jal         0x80066E88
    // 0x80555438: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80555438: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x8055543C: lh          $t8, 0xF2($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XF2);
    // 0x80555440: mul.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80555444: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
    // 0x80555448: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8055544C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80555450: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x80555454: addiu       $t0, $s0, -0x1
    ctx->r8 = ADD32(ctx->r16, -0X1);
    // 0x80555458: cvt.s.w     $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8055545C: addiu       $s4, $fp, 0x2E8
    ctx->r20 = ADD32(ctx->r30, 0X2E8);
    // 0x80555460: addiu       $s2, $v1, 0x388
    ctx->r18 = ADD32(ctx->r3, 0X388);
    // 0x80555464: addiu       $s0, $v0, 0x398
    ctx->r16 = ADD32(ctx->r2, 0X398);
    // 0x80555468: addiu       $fp, $zero, 0x8
    ctx->r30 = ADD32(0, 0X8);
    // 0x8055546C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80555470: mul.s       $f14, $f30, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x80555474: nop

    // 0x80555478: mul.s       $f16, $f30, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x8055547C: nop

    // 0x80555480: mul.s       $f12, $f24, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f24.fl, ctx->f22.fl);
    // 0x80555484: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80555488: add.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f26.fl;
    // 0x8055548C: add.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80555490: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80555494: sub.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f28.fl;
    // 0x80555498: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x8055549C: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x805554A0: sh          $t1, 0x348($v1)
    MEM_H(0X348, ctx->r3) = ctx->r9;
    // 0x805554A4: sll         $t1, $t0, 22
    ctx->r9 = S32(ctx->r8 << 22);
    // 0x805554A8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x805554AC: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x805554B0: sub.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x805554B4: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x805554B8: add.s       $f18, $f10, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x805554BC: sh          $t3, 0x34A($v1)
    MEM_H(0X34A, ctx->r3) = ctx->r11;
    // 0x805554C0: sh          $zero, 0x360($v0)
    MEM_H(0X360, ctx->r2) = 0;
    // 0x805554C4: sub.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f28.fl;
    // 0x805554C8: lh          $t8, 0x360($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X360);
    // 0x805554CC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x805554D0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x805554D4: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x805554D8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x805554DC: sh          $t5, 0x358($v0)
    MEM_H(0X358, ctx->r2) = ctx->r13;
    // 0x805554E0: sh          $t7, 0x35A($v0)
    MEM_H(0X35A, ctx->r2) = ctx->r15;
    // 0x805554E4: sh          $zero, 0x352($v1)
    MEM_H(0X352, ctx->r3) = 0;
    // 0x805554E8: sh          $t8, 0x350($v1)
    MEM_H(0X350, ctx->r3) = ctx->r24;
    // 0x805554EC: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x805554F0: sh          $t2, 0x362($v0)
    MEM_H(0X362, ctx->r2) = ctx->r10;
    // 0x805554F4: lh          $t3, 0xF2($sp)
    ctx->r11 = MEM_H(ctx->r29, 0XF2);
    // 0x805554F8: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x805554FC: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80555500: sll         $t7, $t4, 6
    ctx->r15 = S32(ctx->r12 << 6);
    // 0x80555504: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80555508: sh          $t8, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = ctx->r24;
    // 0x8055550C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80555510:
    // 0x80555510: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80555514: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80555518: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8055551C: lwc1        $f8, 0x4($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X4);
    // 0x80555520: sub.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80555524: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80555528: lwc1        $f4, 0x4($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X4);
    // 0x8055552C: sub.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80555530: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80555534: sub.s       $f26, $f2, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80555538: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8055553C: sub.s       $f28, $f16, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80555540: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80555544: nop

    // 0x80555548: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x8055554C: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80555550: bc1f        L_8055557C
    if (!c1cs) {
        // 0x80555554: sqrt.s      $f24, $f0
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = sqrtf(ctx->f0.fl);
            goto L_8055557C;
    }
    // 0x80555554: sqrt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = sqrtf(ctx->f0.fl);
    // 0x80555558: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8055555C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80555560: c.eq.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl == ctx->f6.fl;
    // 0x80555564: nop

    // 0x80555568: bc1f        L_8055557C
    if (!c1cs) {
        // 0x8055556C: nop
    
            goto L_8055557C;
    }
    // 0x8055556C: nop

    // 0x80555570: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80555574: b           L_80555588
    // 0x80555578: nop

        goto L_80555588;
    // 0x80555578: nop

L_8055557C:
    // 0x8055557C: jal         0x80067114
    // 0x80555580: nop

    func_80067114(rdram, ctx);
        goto after_3;
    // 0x80555580: nop

    after_3:
    // 0x80555584: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
L_80555588:
    // 0x80555588: jal         0x80066DE4
    // 0x8055558C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x8055558C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_4:
    // 0x80555590: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80555594: jal         0x80066E88
    // 0x80555598: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x80555598: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_5:
    // 0x8055559C: mul.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x805555A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x805555A4: addiu       $s2, $s2, 0x40
    ctx->r18 = ADD32(ctx->r18, 0X40);
    // 0x805555A8: mul.s       $f14, $f30, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x805555AC: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x805555B0: addiu       $s6, $s6, 0x40
    ctx->r22 = ADD32(ctx->r22, 0X40);
    // 0x805555B4: mul.s       $f16, $f30, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x805555B8: addiu       $s5, $s5, 0x40
    ctx->r21 = ADD32(ctx->r21, 0X40);
    // 0x805555BC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x805555C0: mul.s       $f12, $f24, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f24.fl, ctx->f22.fl);
    // 0x805555C4: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x805555C8: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x805555CC: add.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f26.fl;
    // 0x805555D0: add.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x805555D4: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x805555D8: sub.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f28.fl;
    // 0x805555DC: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x805555E0: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x805555E4: sh          $v0, -0x40($s2)
    MEM_H(-0X40, ctx->r18) = ctx->r2;
    // 0x805555E8: sh          $v0, -0x40($s6)
    MEM_H(-0X40, ctx->r22) = ctx->r2;
    // 0x805555EC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x805555F0: sub.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x805555F4: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x805555F8: add.s       $f18, $f10, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x805555FC: sh          $v1, -0x3E($s2)
    MEM_H(-0X3E, ctx->r18) = ctx->r3;
    // 0x80555600: sh          $v1, -0x3E($s6)
    MEM_H(-0X3E, ctx->r22) = ctx->r3;
    // 0x80555604: sub.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f28.fl;
    // 0x80555608: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8055560C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80555610: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80555614: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80555618: sh          $a0, -0x40($s0)
    MEM_H(-0X40, ctx->r16) = ctx->r4;
    // 0x8055561C: sh          $a0, -0x40($s5)
    MEM_H(-0X40, ctx->r21) = ctx->r4;
    // 0x80555620: sh          $a1, -0x3E($s0)
    MEM_H(-0X3E, ctx->r16) = ctx->r5;
    // 0x80555624: sh          $a1, -0x3E($s5)
    MEM_H(-0X3E, ctx->r21) = ctx->r5;
    // 0x80555628: sh          $zero, -0x38($s0)
    MEM_H(-0X38, ctx->r16) = 0;
    // 0x8055562C: lh          $t3, -0x38($s0)
    ctx->r11 = MEM_H(ctx->r16, -0X38);
    // 0x80555630: sh          $t3, -0x38($s2)
    MEM_H(-0X38, ctx->r18) = ctx->r11;
    // 0x80555634: lh          $t4, 0xAA($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XAA);
    // 0x80555638: sh          $t4, -0x38($s5)
    MEM_H(-0X38, ctx->r21) = ctx->r12;
    // 0x8055563C: lh          $t5, -0x38($s5)
    ctx->r13 = MEM_H(ctx->r21, -0X38);
    // 0x80555640: sh          $t5, -0x38($s6)
    MEM_H(-0X38, ctx->r22) = ctx->r13;
    // 0x80555644: sh          $zero, -0x36($s2)
    MEM_H(-0X36, ctx->r18) = 0;
    // 0x80555648: lh          $t6, -0x36($s2)
    ctx->r14 = MEM_H(ctx->r18, -0X36);
    // 0x8055564C: sh          $t6, -0x36($s6)
    MEM_H(-0X36, ctx->r22) = ctx->r14;
    // 0x80555650: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80555654: sh          $t7, -0x36($s0)
    MEM_H(-0X36, ctx->r16) = ctx->r15;
    // 0x80555658: lh          $t8, -0x36($s0)
    ctx->r24 = MEM_H(ctx->r16, -0X36);
    // 0x8055565C: bne         $s3, $fp, L_80555510
    if (ctx->r19 != ctx->r30) {
        // 0x80555660: sh          $t8, -0x36($s5)
        MEM_H(-0X36, ctx->r21) = ctx->r24;
            goto L_80555510;
    }
    // 0x80555660: sh          $t8, -0x36($s5)
    MEM_H(-0X36, ctx->r21) = ctx->r24;
    // 0x80555664: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80555668: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8055566C: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80555670: lwc1        $f8, 0x4($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X4);
    // 0x80555674: sub.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80555678: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8055567C: lwc1        $f4, 0x4($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X4);
    // 0x80555680: sub.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80555684: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80555688: sub.s       $f26, $f2, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x8055568C: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80555690: sub.s       $f28, $f16, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80555694: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80555698: nop

    // 0x8055569C: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x805556A0: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x805556A4: bc1f        L_805556D0
    if (!c1cs) {
        // 0x805556A8: sqrt.s      $f24, $f0
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = sqrtf(ctx->f0.fl);
            goto L_805556D0;
    }
    // 0x805556A8: sqrt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = sqrtf(ctx->f0.fl);
    // 0x805556AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x805556B0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x805556B4: c.eq.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl == ctx->f6.fl;
    // 0x805556B8: nop

    // 0x805556BC: bc1f        L_805556D0
    if (!c1cs) {
        // 0x805556C0: nop
    
            goto L_805556D0;
    }
    // 0x805556C0: nop

    // 0x805556C4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x805556C8: b           L_805556DC
    // 0x805556CC: nop

        goto L_805556DC;
    // 0x805556CC: nop

L_805556D0:
    // 0x805556D0: jal         0x80067114
    // 0x805556D4: nop

    func_80067114(rdram, ctx);
        goto after_6;
    // 0x805556D4: nop

    after_6:
    // 0x805556D8: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
L_805556DC:
    // 0x805556DC: jal         0x80066DE4
    // 0x805556E0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_7;
    // 0x805556E0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_7:
    // 0x805556E4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x805556E8: jal         0x80066E88
    // 0x805556EC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_8;
    // 0x805556EC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_8:
    // 0x805556F0: mul.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x805556F4: nop

    // 0x805556F8: mul.s       $f14, $f30, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x805556FC: nop

    // 0x80555700: mul.s       $f16, $f30, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x80555704: nop

    // 0x80555708: mul.s       $f12, $f24, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f24.fl, ctx->f22.fl);
    // 0x8055570C: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80555710: add.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f26.fl;
    // 0x80555714: add.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80555718: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8055571C: sub.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f28.fl;
    // 0x80555720: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80555724: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80555728: sh          $t0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r8;
    // 0x8055572C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80555730: sub.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80555734: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80555738: add.s       $f18, $f10, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x8055573C: sh          $t2, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r10;
    // 0x80555740: sub.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f28.fl;
    // 0x80555744: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80555748: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8055574C: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80555750: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80555754: sh          $t4, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r12;
    // 0x80555758: sh          $t6, 0x2($s5)
    MEM_H(0X2, ctx->r21) = ctx->r14;
    // 0x8055575C: lh          $t7, 0xAA($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XAA);
    // 0x80555760: sh          $t7, 0x8($s5)
    MEM_H(0X8, ctx->r21) = ctx->r15;
    // 0x80555764: lh          $t8, 0x8($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X8);
    // 0x80555768: sh          $zero, 0xA($s6)
    MEM_H(0XA, ctx->r22) = 0;
    // 0x8055576C: sh          $t8, 0x8($s6)
    MEM_H(0X8, ctx->r22) = ctx->r24;
    // 0x80555770: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80555774: sh          $t9, 0xA($s5)
    MEM_H(0XA, ctx->r21) = ctx->r25;
    // 0x80555778: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8055577C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80555780: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80555784: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80555788: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8055578C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80555790: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80555794: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80555798: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8055579C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x805557A0: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x805557A4: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x805557A8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x805557AC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x805557B0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x805557B4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x805557B8: jr          $ra
    // 0x805557BC: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x805557BC: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void func_800403E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800403E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800403E8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800403EC: lw          $t7, -0x76BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76BC);
    // 0x800403F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800403F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800403F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800403FC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80040400: beq         $t7, $zero, L_80040418
    if (ctx->r15 == 0) {
        // 0x80040404: lbu         $v0, 0x12C8($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X12C8);
            goto L_80040418;
    }
    // 0x80040404: lbu         $v0, 0x12C8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X12C8);
    // 0x80040408: jal         0x8004031C
    // 0x8004040C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004031C(rdram, ctx);
        goto after_0;
    // 0x8004040C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80040410: b           L_800404B8
    // 0x80040414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800404B8;
    // 0x80040414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80040418:
    // 0x80040418: beq         $v0, $zero, L_800404B0
    if (ctx->r2 == 0) {
        // 0x8004041C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800404B0;
    }
    // 0x8004041C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80040420: lhu         $t2, 0x12BE($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X12BE);
    // 0x80040424: blez        $v0, L_800404B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80040428: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_800404B0;
    }
    // 0x80040428: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8004042C: addiu       $t0, $zero, 0x4144
    ctx->r8 = ADD32(0, 0X4144);
    // 0x80040430: addiu       $a1, $zero, 0x406C
    ctx->r5 = ADD32(0, 0X406C);
    // 0x80040434: addiu       $a0, $zero, 0x4004
    ctx->r4 = ADD32(0, 0X4004);
    // 0x80040438: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x8004043C: addu        $t9, $a3, $t2
    ctx->r25 = ADD32(ctx->r7, ctx->r10);
L_80040440:
    // 0x80040440: andi        $t3, $t9, 0x7
    ctx->r11 = ctx->r25 & 0X7;
    // 0x80040444: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040448: mflo        $t4
    ctx->r12 = lo;
    // 0x8004044C: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x80040450: lw          $a2, 0x11FC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X11FC);
    // 0x80040454: lhu         $v0, 0xC($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XC);
    // 0x80040458: beql        $v0, $a0, L_8004047C
    if (ctx->r2 == ctx->r4) {
        // 0x8004045C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8004047C;
    }
    goto skip_0;
    // 0x8004045C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80040460: beql        $v0, $a1, L_80040490
    if (ctx->r2 == ctx->r5) {
        // 0x80040464: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80040490;
    }
    goto skip_1;
    // 0x80040464: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x80040468: beql        $v0, $t0, L_80040490
    if (ctx->r2 == ctx->r8) {
        // 0x8004046C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80040490;
    }
    goto skip_2;
    // 0x8004046C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_2:
    // 0x80040470: b           L_800404A0
    // 0x80040474: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
        goto L_800404A0;
    // 0x80040474: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80040478: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8004047C:
    // 0x8004047C: jal         0x800401D8
    // 0x80040480: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800401D8(rdram, ctx);
        goto after_1;
    // 0x80040480: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80040484: b           L_800404B8
    // 0x80040488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800404B8;
    // 0x80040488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004048C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80040490:
    // 0x80040490: jal         0x8004029C
    // 0x80040494: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004029C(rdram, ctx);
        goto after_2;
    // 0x80040494: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80040498: b           L_800404B8
    // 0x8004049C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800404B8;
    // 0x8004049C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800404A0:
    // 0x800404A0: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x800404A4: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800404A8: bnel        $at, $zero, L_80040440
    if (ctx->r1 != 0) {
        // 0x800404AC: addu        $t9, $a3, $t2
        ctx->r25 = ADD32(ctx->r7, ctx->r10);
            goto L_80040440;
    }
    goto skip_3;
    // 0x800404AC: addu        $t9, $a3, $t2
    ctx->r25 = ADD32(ctx->r7, ctx->r10);
    skip_3:
L_800404B0:
    // 0x800404B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800404B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800404B8:
    // 0x800404B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800404BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800404C0: jr          $ra
    // 0x800404C4: nop

    return;
    // 0x800404C4: nop

;}
RECOMP_FUNC void func_80790434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790434: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80790438: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8079043C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x80790440: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x80790444: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80790448: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x8079044C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80790450: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80790454: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80790458: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8079045C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80790460: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80790464: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80790468: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8079046C: lui         $t9, 0x8079
    ctx->r25 = S32(RELOC_HI16(817, 0X766C) << 16);
    // 0x80790470: addiu       $t9, $t9, 0x79BC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(817, 0X766C));
    // 0x80790474: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80790478: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8079047C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80790480: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80790484: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80790488: lw          $s7, 0x1F4($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079048C: addiu       $t6, $sp, 0x8C
    ctx->r14 = ADD32(ctx->r29, 0X8C);
    // 0x80790490: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x80790494: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80790498: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8079049C: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x807904A0: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x807904A4: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x807904A8: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x807904AC: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x807904B0: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x807904B4: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x807904B8: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x807904BC: lwc1        $f22, 0x6C($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807904C0: jal         0x80049018
    // 0x807904C4: lwc1        $f24, 0x70($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X70);
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x807904C4: lwc1        $f24, 0x70($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X70);
    after_0:
    // 0x807904C8: beq         $v0, $zero, L_807904E8
    if (ctx->r2 == 0) {
        // 0x807904CC: or          $s1, $s7, $zero
        ctx->r17 = ctx->r23 | 0;
            goto L_807904E8;
    }
    // 0x807904CC: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x807904D0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x807904D4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x807904D8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x807904DC: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x807904E0: b           L_807904FC
    // 0x807904E4: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
        goto L_807904FC;
    // 0x807904E4: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_807904E8:
    // 0x807904E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807904EC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x807904F0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x807904F4: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x807904F8: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
L_807904FC:
    // 0x807904FC: lui         $s3, 0x8079
    ctx->r19 = S32(RELOC_HI16(817, 0X3928) << 16);
    // 0x80790500: addiu       $s3, $s3, 0x3C78
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(817, 0X3928));
    // 0x80790504: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80790508: addiu       $s6, $zero, 0x78
    ctx->r22 = ADD32(0, 0X78);
    // 0x8079050C: addiu       $s5, $sp, 0x78
    ctx->r21 = ADD32(ctx->r29, 0X78);
    // 0x80790510: addiu       $s4, $zero, 0x6
    ctx->r20 = ADD32(0, 0X6);
    // 0x80790514: addiu       $s2, $sp, 0x5C
    ctx->r18 = ADD32(ctx->r29, 0X5C);
L_80790518:
    // 0x80790518: lw          $t7, 0x4($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X4);
    // 0x8079051C: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x80790520: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80790524: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80790528: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x8079052C: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x80790530: multu       $t6, $s4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80790534: mflo        $t0
    ctx->r8 = lo;
    // 0x80790538: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8079053C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80790540: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80790544: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x80790548: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8079054C: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x80790550: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80790554: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80790558: sw          $t4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r12;
    // 0x8079055C: lw          $t7, 0x8($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X8);
    // 0x80790560: sw          $t7, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r15;
    // 0x80790564: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80790568: sw          $t4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r12;
    // 0x8079056C: lw          $t7, 0x10($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X10);
    // 0x80790570: beq         $a0, $zero, L_807905FC
    if (ctx->r4 == 0) {
        // 0x80790574: sw          $t7, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->r15;
            goto L_807905FC;
    }
    // 0x80790574: sw          $t7, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r15;
    // 0x80790578: lh          $t5, 0x5C($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X5C);
    // 0x8079057C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80790580: nop

    // 0x80790584: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80790588: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8079058C: nop

    // 0x80790590: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80790594: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x80790598: lh          $t8, 0x5E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X5E);
    // 0x8079059C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x807905A0: nop

    // 0x807905A4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807905A8: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x807905AC: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x807905B0: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x807905B4: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x807905B8: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    // 0x807905BC: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x807905C0: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x807905C4: swc1        $f16, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
    // 0x807905C8: lh          $t9, 0x68($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X68);
    // 0x807905CC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x807905D0: nop

    // 0x807905D4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807905D8: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x807905DC: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
    // 0x807905E0: lh          $t6, 0x6C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6C);
    // 0x807905E4: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x807905E8: lbu         $t0, 0x6A($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X6A);
    // 0x807905EC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x807905F0: addu        $t2, $s5, $t1
    ctx->r10 = ADD32(ctx->r21, ctx->r9);
    // 0x807905F4: jal         0x80790378
    // 0x807905F8: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    func_80790378(rdram, ctx);
        goto after_1;
    // 0x807905F8: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    after_1:
L_807905FC:
    // 0x807905FC: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80790600: bne         $s0, $s6, L_80790518
    if (ctx->r16 != ctx->r22) {
        // 0x80790604: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80790518;
    }
    // 0x80790604: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80790608: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8079060C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80790610: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80790614: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80790618: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8079061C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80790620: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80790624: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80790628: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x8079062C: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80790630: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80790634: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80790638: jr          $ra
    // 0x8079063C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8079063C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_80067FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067FF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067FF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067FFC: jal         0x80067390
    // 0x80068000: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Idle_InitVideo(rdram, ctx);
        goto after_0;
    // 0x80068000: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80068004: jal         0x800867A0
    // 0x80068008: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_1;
    // 0x80068008: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8006800C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80068010: sb          $zero, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = 0;
    // 0x80068014: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80068018: sb          $zero, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = 0;
    // 0x8006801C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80068020: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80068024: jal         0x800678D0
    // 0x80068028: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
    func_800678D0(rdram, ctx);
        goto after_2;
    // 0x80068028: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
    after_2:
    // 0x8006802C: jal         0x800679B0
    // 0x80068030: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800679B0(rdram, ctx);
        goto after_3;
    // 0x80068030: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80068034: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80068038: addiu       $t7, $t7, -0x7B20
    ctx->r15 = ADD32(ctx->r15, -0X7B20);
    // 0x8006803C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80068040: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80068044: bnel        $t8, $at, L_80068060
    if (ctx->r24 != ctx->r1) {
        // 0x80068048: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80068060;
    }
    goto skip_0;
    // 0x80068048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8006804C: jal         0x80071D6C
    // 0x80068050: nop

    func_80071D6C(rdram, ctx);
        goto after_4;
    // 0x80068050: nop

    after_4:
    // 0x80068054: jal         0x80071D6C
    // 0x80068058: nop

    func_80071D6C(rdram, ctx);
        goto after_5;
    // 0x80068058: nop

    after_5:
    // 0x8006805C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80068060:
    // 0x80068060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068064: jr          $ra
    // 0x80068068: nop

    return;
    // 0x80068068: nop

;}
RECOMP_FUNC void func_8041069C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041069C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804106A0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x804106A4: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x804106A8: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x804106AC: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x804106B0: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x804106B4: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x804106B8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x804106BC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x804106C0: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x804106C4: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x804106C8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x804106CC: addu        $a3, $a1, $at
    ctx->r7 = ADD32(ctx->r5, ctx->r1);
    // 0x804106D0: lw          $t6, 0x39CC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39CC);
    // 0x804106D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804106D8: ori         $at, $zero, 0xB9C0
    ctx->r1 = 0 | 0XB9C0;
    // 0x804106DC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x804106E0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x804106E4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x804106E8: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x804106EC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x804106F0: addu        $t6, $a1, $at
    ctx->r14 = ADD32(ctx->r5, ctx->r1);
    // 0x804106F4: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x804106F8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x804106FC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80410700: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410704: sll         $t7, $t7, 9
    ctx->r15 = S32(ctx->r15 << 9);
    // 0x80410708: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x8041070C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80410710: lui         $ra, 0x708
    ctx->r31 = S32(0X708 << 16);
    // 0x80410714: lui         $t0, 0xF510
    ctx->r8 = S32(0XF510 << 16);
    // 0x80410718: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8041071C: ori         $t0, $t0, 0x3F4
    ctx->r8 = ctx->r8 | 0X3F4;
    // 0x80410720: ori         $ra, $ra, 0x200
    ctx->r31 = ctx->r31 | 0X200;
    // 0x80410724: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x80410728: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8041072C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410730: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80410734: lui         $t7, 0xF400
    ctx->r15 = S32(0XF400 << 16);
    // 0x80410738: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8041073C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80410740: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80410744: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80410748: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8041074C: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x80410750: ori         $t8, $t8, 0x4004
    ctx->r24 = ctx->r24 | 0X4004;
    // 0x80410754: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80410758: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8041075C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80410760: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80410764: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410768: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8041076C: lui         $t8, 0x108
    ctx->r24 = S32(0X108 << 16);
    // 0x80410770: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80410774: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80410778: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8041077C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80410780: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410784: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80410788: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8041078C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80410790: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80410794: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80410798: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8041079C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804107A0: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x804107A4: ori         $t7, $t7, 0x4004
    ctx->r15 = ctx->r15 | 0X4004;
    // 0x804107A8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x804107AC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804107B0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x804107B4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x804107B8: addiu       $s2, $v1, 0x5C0
    ctx->r18 = ADD32(ctx->r3, 0X5C0);
    // 0x804107BC: addiu       $s3, $v1, 0x5FC0
    ctx->r19 = ADD32(ctx->r3, 0X5FC0);
    // 0x804107C0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x804107C4: lw          $v1, 0x39E4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X39E4);
    // 0x804107C8: lui         $s6, 0xBB00
    ctx->r22 = S32(0XBB00 << 16);
    // 0x804107CC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x804107D0: beq         $v1, $zero, L_80410AC4
    if (ctx->r3 == 0) {
        // 0x804107D4: ori         $s6, $s6, 0x101
        ctx->r22 = ctx->r22 | 0X101;
            goto L_80410AC4;
    }
    // 0x804107D4: ori         $s6, $s6, 0x101
    ctx->r22 = ctx->r22 | 0X101;
    // 0x804107D8: lui         $s5, 0xBB00
    ctx->r21 = S32(0XBB00 << 16);
    // 0x804107DC: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x804107E0: ori         $t5, $t5, 0x8000
    ctx->r13 = ctx->r13 | 0X8000;
    // 0x804107E4: ori         $s5, $s5, 0x1
    ctx->r21 = ctx->r21 | 0X1;
    // 0x804107E8: lw          $v0, 0x39E8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X39E8);
    // 0x804107EC: lui         $s4, 0xF510
    ctx->r20 = S32(0XF510 << 16);
    // 0x804107F0: lui         $s1, 0xBF00
    ctx->r17 = S32(0XBF00 << 16);
L_804107F4:
    // 0x804107F4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x804107F8: beq         $v0, $zero, L_80410AA8
    if (ctx->r2 == 0) {
        // 0x804107FC: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_80410AA8;
    }
    // 0x804107FC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80410800: sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9 << 2);
    // 0x80410804: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80410808: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8041080C: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80410810: or          $s7, $v0, $at
    ctx->r23 = ctx->r2 | ctx->r1;
    // 0x80410814: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80410818: or          $fp, $v0, $at
    ctx->r30 = ctx->r2 | ctx->r1;
L_8041081C:
    // 0x8041081C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410820: lui         $at, 0xFD10
    ctx->r1 = S32(0XFD10 << 16);
    // 0x80410824: sll         $a2, $t0, 2
    ctx->r6 = S32(ctx->r8 << 2);
    // 0x80410828: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8041082C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80410830: lw          $t9, 0x39D4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X39D4);
    // 0x80410834: andi        $a2, $a2, 0xFFF
    ctx->r6 = ctx->r6 & 0XFFF;
    // 0x80410838: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8041083C: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x80410840: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80410844: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80410848: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8041084C: lw          $t9, 0x39C8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X39C8);
    // 0x80410850: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80410854: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80410858: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8041085C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80410860: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80410864: lw          $t7, 0x39DC($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X39DC);
    // 0x80410868: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x8041086C: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x80410870: subu        $t9, $t8, $t1
    ctx->r25 = SUB32(ctx->r24, ctx->r9);
    // 0x80410874: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80410878: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x8041087C: srl         $t8, $t7, 3
    ctx->r24 = S32(U32(ctx->r15) >> 3);
    // 0x80410880: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80410884: sll         $t6, $t9, 9
    ctx->r14 = S32(ctx->r25 << 9);
    // 0x80410888: or          $t7, $t6, $s4
    ctx->r15 = ctx->r14 | ctx->r20;
    // 0x8041088C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80410890: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410894: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80410898: or          $t7, $s7, $a2
    ctx->r15 = ctx->r23 | ctx->r6;
    // 0x8041089C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x804108A0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x804108A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804108A8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x804108AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804108B0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x804108B4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804108B8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804108BC: lw          $t8, 0x39E0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X39E0);
    // 0x804108C0: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x804108C4: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x804108C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804108CC: lw          $t6, 0x39DC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39DC);
    // 0x804108D0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x804108D4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x804108D8: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x804108DC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x804108E0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x804108E4: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x804108E8: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x804108EC: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x804108F0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x804108F4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804108F8: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804108FC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80410900: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80410904: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80410908: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8041090C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410910: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80410914: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80410918: lw          $t6, 0x39DC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39DC);
    // 0x8041091C: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x80410920: subu        $t9, $t7, $t1
    ctx->r25 = SUB32(ctx->r15, ctx->r9);
    // 0x80410924: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x80410928: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x8041092C: srl         $t7, $t6, 3
    ctx->r15 = S32(U32(ctx->r14) >> 3);
    // 0x80410930: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x80410934: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x80410938: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x8041093C: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80410940: or          $t6, $t8, $s4
    ctx->r14 = ctx->r24 | ctx->r20;
    // 0x80410944: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80410948: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8041094C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410950: or          $t8, $fp, $a2
    ctx->r24 = ctx->r30 | ctx->r6;
    // 0x80410954: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80410958: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8041095C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80410960: lw          $t6, 0x39E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39E0);
    // 0x80410964: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x80410968: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x8041096C: lw          $t7, 0x39DC($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X39DC);
    // 0x80410970: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80410974: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80410978: addu        $t9, $t1, $t7
    ctx->r25 = ADD32(ctx->r9, ctx->r15);
    // 0x8041097C: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x80410980: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80410984: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80410988: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8041098C: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80410990: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80410994: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410998: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x8041099C: ori         $t6, $t6, 0x103F
    ctx->r14 = ctx->r14 | 0X103F;
    // 0x804109A0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x804109A4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804109A8: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x804109AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x804109B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804109B4: lui         $t7, 0x408
    ctx->r15 = S32(0X408 << 16);
    // 0x804109B8: ori         $t7, $t7, 0x103F
    ctx->r15 = ctx->r15 | 0X103F;
    // 0x804109BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x804109C0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x804109C4: sw          $s3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r19;
    // 0x804109C8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804109CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804109D0: addiu       $t8, $zero, 0x402
    ctx->r24 = ADD32(0, 0X402);
    // 0x804109D4: addiu       $s3, $s3, 0x40
    ctx->r19 = ADD32(ctx->r19, 0X40);
    // 0x804109D8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x804109DC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804109E0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x804109E4: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x804109E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804109EC: addiu       $s2, $s2, 0x40
    ctx->r18 = ADD32(ctx->r18, 0X40);
    // 0x804109F0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x804109F4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804109F8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x804109FC: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80410A00: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410A04: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x80410A08: ori         $t6, $t6, 0xA0C
    ctx->r14 = ctx->r14 | 0XA0C;
    // 0x80410A0C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80410A10: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80410A14: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80410A18: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80410A1C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410A20: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80410A24: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80410A28: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80410A2C: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80410A30: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410A34: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x80410A38: ori         $t9, $t9, 0x406
    ctx->r25 = ctx->r25 | 0X406;
    // 0x80410A3C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80410A40: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80410A44: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80410A48: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80410A4C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410A50: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80410A54: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80410A58: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80410A5C: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80410A60: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410A64: lui         $t7, 0xA
    ctx->r15 = S32(0XA << 16);
    // 0x80410A68: ori         $t7, $t7, 0xE0C
    ctx->r15 = ctx->r15 | 0XE0C;
    // 0x80410A6C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80410A70: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80410A74: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80410A78: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80410A7C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410A80: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80410A84: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80410A88: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80410A8C: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80410A90: lw          $v0, 0x39E8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X39E8);
    // 0x80410A94: lw          $t9, 0x39E0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X39E0);
    // 0x80410A98: sltu        $at, $t4, $v0
    ctx->r1 = ctx->r12 < ctx->r2 ? 1 : 0;
    // 0x80410A9C: bne         $at, $zero, L_8041081C
    if (ctx->r1 != 0) {
        // 0x80410AA0: addu        $t0, $t0, $t9
        ctx->r8 = ADD32(ctx->r8, ctx->r25);
            goto L_8041081C;
    }
    // 0x80410AA0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80410AA4: lw          $v1, 0x39E4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X39E4);
L_80410AA8:
    // 0x80410AA8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80410AAC: lw          $t6, 0x39DC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39DC);
    // 0x80410AB0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80410AB4: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80410AB8: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80410ABC: bne         $at, $zero, L_804107F4
    if (ctx->r1 != 0) {
        // 0x80410AC0: addu        $t1, $t1, $t6
        ctx->r9 = ADD32(ctx->r9, ctx->r14);
            goto L_804107F4;
    }
    // 0x80410AC0: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
L_80410AC4:
    // 0x80410AC4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80410AC8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80410ACC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80410AD0: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80410AD4: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80410AD8: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80410ADC: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80410AE0: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80410AE4: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x80410AE8: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80410AEC: jr          $ra
    // 0x80410AF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80410AF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8042F1E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F1E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042F1EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042F1F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042F1F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8042F1F8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8042F1FC: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8042F200: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042F204: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8042F208: beq         $v0, $at, L_8042F224
    if (ctx->r2 == ctx->r1) {
        // 0x8042F20C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8042F224;
    }
    // 0x8042F20C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8042F210: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8042F214: beq         $v0, $at, L_8042F280
    if (ctx->r2 == ctx->r1) {
        // 0x8042F218: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_8042F280;
    }
    // 0x8042F218: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8042F21C: b           L_8042F2B0
    // 0x8042F220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8042F2B0;
    // 0x8042F220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042F224:
    // 0x8042F224: jal         0x80062AEC
    // 0x8042F228: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x8042F228: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x8042F22C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8042F230: beq         $v0, $at, L_8042F250
    if (ctx->r2 == ctx->r1) {
        // 0x8042F234: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8042F250;
    }
    // 0x8042F234: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8042F238: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8042F23C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8042F240: jal         0x8002F6E4
    // 0x8042F244: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x8042F244: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8042F248: b           L_8042F2B0
    // 0x8042F24C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8042F2B0;
    // 0x8042F24C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042F250:
    // 0x8042F250: jal         0x8002FABC
    // 0x8042F254: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    func_8002FABC(rdram, ctx);
        goto after_2;
    // 0x8042F254: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    after_2:
    // 0x8042F258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042F25C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042F260: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8042F264: jal         0x8042F574
    // 0x8042F268: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8042F574(rdram, ctx);
        goto after_3;
    // 0x8042F268: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_3:
    // 0x8042F26C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042F270: jal         0x8042E220
    // 0x8042F274: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8042E220(rdram, ctx);
        goto after_4;
    // 0x8042F274: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x8042F278: b           L_8042F2B0
    // 0x8042F27C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8042F2B0;
    // 0x8042F27C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042F280:
    // 0x8042F280: lbu         $t8, 0x18($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X18);
    // 0x8042F284: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8042F288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042F28C: bne         $t8, $at, L_8042F2AC
    if (ctx->r24 != ctx->r1) {
        // 0x8042F290: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8042F2AC;
    }
    // 0x8042F290: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042F294: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8042F298: jal         0x8042F574
    // 0x8042F29C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8042F574(rdram, ctx);
        goto after_5;
    // 0x8042F29C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
    // 0x8042F2A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042F2A4: jal         0x8042E220
    // 0x8042F2A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8042E220(rdram, ctx);
        goto after_6;
    // 0x8042F2A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
L_8042F2AC:
    // 0x8042F2AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042F2B0:
    // 0x8042F2B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042F2B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042F2B8: jr          $ra
    // 0x8042F2BC: nop

    return;
    // 0x8042F2BC: nop

;}
RECOMP_FUNC void func_80078E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078E68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80078E6C: jr          $ra
    // 0x80078E70: nop

    return;
    // 0x80078E70: nop

;}
RECOMP_FUNC void func_8044817C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044817C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80448180: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80448184: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80448188: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8044818C: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80448190: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80448194: lui         $t0, 0x8045
    ctx->r8 = S32(RELOC_HI16(98, 0X13344) << 16);
    // 0x80448198: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8044819C: lw          $v1, 0x6CAC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CAC);
    // 0x804481A0: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x804481A4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x804481A8: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x804481AC: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x804481B0: lw          $t0, 0x7724($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(98, 0X13344));
    // 0x804481B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804481B8: beql        $t0, $zero, L_804481CC
    if (ctx->r8 == 0) {
        // 0x804481BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804481CC;
    }
    goto skip_0;
    // 0x804481BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804481C0: jalr        $t0
    // 0x804481C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
        goto after_0;
    // 0x804481C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x804481C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804481CC:
    // 0x804481CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804481D0: jr          $ra
    // 0x804481D4: nop

    return;
    // 0x804481D4: nop

;}
RECOMP_FUNC void func_804A13E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A13E8: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x804A13EC: lui         $v0, 0x804A
    ctx->r2 = S32(RELOC_HI16(173, 0X2FFC) << 16);
    // 0x804A13F0: addiu       $v1, $v1, -0x41F1
    ctx->r3 = ADD32(ctx->r3, -0X41F1);
    // 0x804A13F4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x804A13F8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x804A13FC: jr          $ra
    // 0x804A1400: lw          $v0, 0x343C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(173, 0X2FFC));
    return;
    // 0x804A1400: lw          $v0, 0x343C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(173, 0X2FFC));
;}
RECOMP_FUNC void func_807A6070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6070: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807A6074: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807A6078: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807A607C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807A6080: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807A6084: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807A6088: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807A608C: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(847, 0X14A8) << 16);
    // 0x807A6090: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807A6094: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807A6098: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807A609C: lw          $t1, 0x71A8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(847, 0X14A8));
    // 0x807A60A0: jr          $ra
    // 0x807A60A4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807A60A4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80791650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80791650: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80791654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80791658: jal         0x80790CB4
    // 0x8079165C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80790CB4(rdram, ctx);
        goto after_0;
    // 0x8079165C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80791660: jal         0x80790714
    // 0x80791664: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x80791664: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80791668: beq         $v0, $zero, L_80791680
    if (ctx->r2 == 0) {
        // 0x8079166C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80791680;
    }
    // 0x8079166C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80791670: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791674: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80791678: jal         0x8079393C
    // 0x8079167C: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x8079167C: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_2:
L_80791680:
    // 0x80791680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80791684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80791688: jr          $ra
    // 0x8079168C: nop

    return;
    // 0x8079168C: nop

;}
RECOMP_FUNC void func_80047EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047EB0: lh          $t6, 0x184($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X184);
    // 0x80047EB4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80047EB8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80047EBC: bne         $t6, $zero, L_80047ECC
    if (ctx->r14 != 0) {
        // 0x80047EC0: addiu       $v0, $zero, 0x50
        ctx->r2 = ADD32(0, 0X50);
            goto L_80047ECC;
    }
    // 0x80047EC0: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x80047EC4: jr          $ra
    // 0x80047EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80047EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80047ECC:
    // 0x80047ECC: lw          $t7, 0x188($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X188);
    // 0x80047ED0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80047ED4: bnel        $a1, $t7, L_80047EE8
    if (ctx->r5 != ctx->r15) {
        // 0x80047ED8: lw          $t8, 0x18C($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X18C);
            goto L_80047EE8;
    }
    goto skip_0;
    // 0x80047ED8: lw          $t8, 0x18C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X18C);
    skip_0:
    // 0x80047EDC: jr          $ra
    // 0x80047EE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80047EE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80047EE4: lw          $t8, 0x18C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X18C);
L_80047EE8:
    // 0x80047EE8: bnel        $a1, $t8, L_80047EFC
    if (ctx->r5 != ctx->r24) {
        // 0x80047EEC: lw          $t9, 0x190($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X190);
            goto L_80047EFC;
    }
    goto skip_1;
    // 0x80047EEC: lw          $t9, 0x190($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X190);
    skip_1:
    // 0x80047EF0: jr          $ra
    // 0x80047EF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80047EF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80047EF8: lw          $t9, 0x190($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X190);
L_80047EFC:
    // 0x80047EFC: bnel        $a1, $t9, L_80047F10
    if (ctx->r5 != ctx->r25) {
        // 0x80047F00: lw          $t0, 0x194($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X194);
            goto L_80047F10;
    }
    goto skip_2;
    // 0x80047F00: lw          $t0, 0x194($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X194);
    skip_2:
    // 0x80047F04: jr          $ra
    // 0x80047F08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80047F08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80047F0C: lw          $t0, 0x194($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X194);
L_80047F10:
    // 0x80047F10: bne         $a1, $t0, L_80047F20
    if (ctx->r5 != ctx->r8) {
        // 0x80047F14: nop
    
            goto L_80047F20;
    }
    // 0x80047F14: nop

    // 0x80047F18: jr          $ra
    // 0x80047F1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80047F1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80047F20:
    // 0x80047F20: bne         $v1, $v0, L_80047ECC
    if (ctx->r3 != ctx->r2) {
        // 0x80047F24: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_80047ECC;
    }
    // 0x80047F24: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80047F28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80047F2C: jr          $ra
    // 0x80047F30: nop

    return;
    // 0x80047F30: nop

;}
RECOMP_FUNC void func_80421424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421424: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80421428: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x8042142C: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x80421430: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80421434: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80421438: sll         $t7, $a2, 3
    ctx->r15 = S32(ctx->r6 << 3);
    // 0x8042143C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80421440: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80421444: addu        $a3, $t8, $a2
    ctx->r7 = ADD32(ctx->r24, ctx->r6);
    // 0x80421448: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8042144C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80421450: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x80421454: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x80421458: sw          $t9, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r25;
    // 0x8042145C: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80421460: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80421464: divu        $zero, $t1, $at
    lo = S32(U32(ctx->r9) / U32(ctx->r1)); hi = S32(U32(ctx->r9) % U32(ctx->r1));
    // 0x80421468: mfhi        $t2
    ctx->r10 = hi;
    // 0x8042146C: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x80421470: jr          $ra
    // 0x80421474: nop

    return;
    // 0x80421474: nop

;}
RECOMP_FUNC void func_80703F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80703F10: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80703F14: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(709, 0X33B8) << 16);
    // 0x80703F18: addiu       $t7, $t7, 0x6828
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(709, 0X33B8));
    // 0x80703F1C: lw          $v1, 0x28($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X28);
    // 0x80703F20: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80703F24: bnel        $at, $zero, L_80703F34
    if (ctx->r1 != 0) {
        // 0x80703F28: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_80703F34;
    }
    goto skip_0;
    // 0x80703F28: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    skip_0:
    // 0x80703F2C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80703F30: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
L_80703F34:
    // 0x80703F34: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80703F38: subu        $v1, $v1, $at
    ctx->r3 = SUB32(ctx->r3, ctx->r1);
    // 0x80703F3C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80703F40: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80703F44: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80703F48: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80703F4C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80703F50: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80703F54: sh          $t8, 0x48($v0)
    MEM_H(0X48, ctx->r2) = ctx->r24;
    // 0x80703F58: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80703F5C: addu        $a2, $a1, $t1
    ctx->r6 = ADD32(ctx->r5, ctx->r9);
    // 0x80703F60: sll         $t0, $a0, 1
    ctx->r8 = S32(ctx->r4 << 1);
    // 0x80703F64: sh          $t9, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r25;
    // 0x80703F68: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80703F6C: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x80703F70: sh          $t2, 0x48($v1)
    MEM_H(0X48, ctx->r3) = ctx->r10;
    // 0x80703F74: lw          $t3, 0x4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X4);
    // 0x80703F78: sh          $t3, 0x4A($v1)
    MEM_H(0X4A, ctx->r3) = ctx->r11;
    // 0x80703F7C: lw          $t4, 0x8($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X8);
    // 0x80703F80: sh          $t4, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r12;
    // 0x80703F84: lw          $t5, 0xC($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XC);
    // 0x80703F88: jr          $ra
    // 0x80703F8C: sh          $t5, 0x4E($v1)
    MEM_H(0X4E, ctx->r3) = ctx->r13;
    return;
    // 0x80703F8C: sh          $t5, 0x4E($v1)
    MEM_H(0X4E, ctx->r3) = ctx->r13;
;}
RECOMP_FUNC void func_8000A84C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A84C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000A850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A854: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000A858: lw          $a0, -0x6368($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6368);
    // 0x8000A85C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8000A860: jal         0x800824B0
    // 0x8000A864: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000A864: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8000A868: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000A86C: bne         $v0, $at, L_8000A87C
    if (ctx->r2 != ctx->r1) {
        // 0x8000A870: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000A87C;
    }
    // 0x8000A870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A874: b           L_8000A89C
    // 0x8000A878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000A89C;
    // 0x8000A878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000A87C:
    // 0x8000A87C: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x8000A880: lbu         $t7, 0x7733($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7733);
    // 0x8000A884: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8000A888: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A88C: beq         $t6, $t7, L_8000A89C
    if (ctx->r14 == ctx->r15) {
        // 0x8000A890: nop
    
            goto L_8000A89C;
    }
    // 0x8000A890: nop

    // 0x8000A894: b           L_8000A89C
    // 0x8000A898: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000A89C;
    // 0x8000A898: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000A89C:
    // 0x8000A89C: jr          $ra
    // 0x8000A8A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000A8A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806F6F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F6F08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F6F0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F6F10: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x806F6F14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806F6F18: beq         $t6, $zero, L_806F6F54
    if (ctx->r14 == 0) {
        // 0x806F6F1C: nop
    
            goto L_806F6F54;
    }
    // 0x806F6F1C: nop

    // 0x806F6F20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F6F24: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x806F6F28: jalr        $t9
    // 0x806F6F2C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806F6F2C: nop

    after_0:
    // 0x806F6F30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F6F34: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x806F6F38: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x806F6F3C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x806F6F40: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x806F6F44: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x806F6F48: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x806F6F4C: b           L_806F6F54
    // 0x806F6F50: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_806F6F54;
    // 0x806F6F50: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_806F6F54:
    // 0x806F6F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F6F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F6F5C: jr          $ra
    // 0x806F6F60: nop

    return;
    // 0x806F6F60: nop

;}
RECOMP_FUNC void func_804327B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804327B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804327B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804327B8: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804327BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804327C0: beq         $t6, $zero, L_804327FC
    if (ctx->r14 == 0) {
        // 0x804327C4: nop
    
            goto L_804327FC;
    }
    // 0x804327C4: nop

    // 0x804327C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804327CC: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804327D0: jalr        $t9
    // 0x804327D4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804327D4: nop

    after_0:
    // 0x804327D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804327DC: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804327E0: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804327E4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804327E8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804327EC: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804327F0: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804327F4: b           L_804327FC
    // 0x804327F8: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_804327FC;
    // 0x804327F8: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_804327FC:
    // 0x804327FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80432800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80432804: jr          $ra
    // 0x80432808: nop

    return;
    // 0x80432808: nop

;}
RECOMP_FUNC void func_8006E154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E154: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006E158: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8006E15C: lw          $v0, -0x7BC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7BC4);
    // 0x8006E160: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006E164: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006E168: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006E16C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8006E170: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8006E174: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8006E178: lw          $a3, 0x8C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8C);
    // 0x8006E17C: lw          $a0, 0x16C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C);
    // 0x8006E180: lw          $a2, 0x120($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X120);
    // 0x8006E184: lw          $a1, 0x11C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X11C);
    // 0x8006E188: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x8006E18C: jal         0x80050048
    // 0x8006E190: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    func_80050048(rdram, ctx);
        goto after_0;
    // 0x8006E190: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8006E194: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006E198: jal         0x8006E138
    // 0x8006E19C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8006E138(rdram, ctx);
        goto after_1;
    // 0x8006E19C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8006E1A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E1A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006E1A8: jr          $ra
    // 0x8006E1AC: nop

    return;
    // 0x8006E1AC: nop

;}
RECOMP_FUNC void func_806ADEE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ADEE0: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x806ADEE4: lui         $t9, 0x806B
    ctx->r25 = S32(RELOC_HI16(595, 0X1DEC) << 16);
    // 0x806ADEE8: addiu       $t9, $t9, -0x4D4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(595, 0X1DEC));
    // 0x806ADEEC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806ADEF0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x806ADEF4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806ADEF8: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x806ADEFC: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x806ADF00: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x806ADF04: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806ADF08: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
    // 0x806ADF0C: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x806ADF10: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x806ADF14: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806ADF18: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x806ADF1C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x806ADF20: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x806ADF24: sw          $t7, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r15;
    // 0x806ADF28: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x806ADF2C: sw          $t5, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r13;
    // 0x806ADF30: lw          $t7, 0x10($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X10);
    // 0x806ADF34: sw          $t7, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r15;
    // 0x806ADF38: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x806ADF3C: sw          $t5, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r13;
    // 0x806ADF40: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806ADF44: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x806ADF48: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x806ADF4C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x806ADF50: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x806ADF54: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x806ADF58: lw          $v1, 0x28($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X28);
    // 0x806ADF5C: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x806ADF60: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x806ADF64: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x806ADF68: lui         $t6, 0x806B
    ctx->r14 = S32(RELOC_HI16(595, 0X1BAC) << 16);
    // 0x806ADF6C: addiu       $t6, $t6, -0x714
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(595, 0X1BAC));
    // 0x806ADF70: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806ADF74: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806ADF78: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x806ADF7C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x806ADF80: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x806ADF84: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x806ADF88: lw          $t4, 0x4($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X4);
    // 0x806ADF8C: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
    // 0x806ADF90: lw          $t5, 0x8($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X8);
    // 0x806ADF94: sw          $t5, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r13;
    // 0x806ADF98: lw          $t4, 0xC($t9)
    ctx->r12 = MEM_W(ctx->r25, 0XC);
    // 0x806ADF9C: sw          $t4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r12;
    // 0x806ADFA0: lw          $t5, 0x10($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X10);
    // 0x806ADFA4: beq         $v1, $zero, L_806AE024
    if (ctx->r3 == 0) {
        // 0x806ADFA8: sw          $t5, 0x10($a2)
        MEM_W(0X10, ctx->r6) = ctx->r13;
            goto L_806AE024;
    }
    // 0x806ADFA8: sw          $t5, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r13;
    // 0x806ADFAC: lh          $t7, 0x24($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X24);
    // 0x806ADFB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806ADFB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806ADFB8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x806ADFBC: nop

    // 0x806ADFC0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806ADFC4: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x806ADFC8: nop

    // 0x806ADFCC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x806ADFD0: swc1        $f10, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f10.u32l;
    // 0x806ADFD4: lh          $t8, 0x26($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X26);
    // 0x806ADFD8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x806ADFDC: nop

    // 0x806ADFE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806ADFE4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x806ADFE8: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x806ADFEC: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x806ADFF0: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806ADFF4: swc1        $f4, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f4.u32l;
    // 0x806ADFF8: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x806ADFFC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x806AE000: swc1        $f8, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f8.u32l;
    // 0x806AE004: lh          $t6, 0x30($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X30);
    // 0x806AE008: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x806AE00C: nop

    // 0x806AE010: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806AE014: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x806AE018: swc1        $f6, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f6.u32l;
    // 0x806AE01C: lh          $t9, 0x34($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X34);
    // 0x806AE020: sh          $t9, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r25;
L_806AE024:
    // 0x806AE024: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x806AE028: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x806AE02C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806AE030: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806AE034: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x806AE038: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x806AE03C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x806AE040: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x806AE044: bgez        $t8, L_806AE058
    if (SIGNED(ctx->r24) >= 0) {
        // 0x806AE048: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_806AE058;
    }
    // 0x806AE048: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806AE04C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806AE050: nop

    // 0x806AE054: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_806AE058:
    // 0x806AE058: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x806AE05C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x806AE060: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x806AE064: bgez        $t6, L_806AE078
    if (SIGNED(ctx->r14) >= 0) {
        // 0x806AE068: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_806AE078;
    }
    // 0x806AE068: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806AE06C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806AE070: nop

    // 0x806AE074: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_806AE078:
    // 0x806AE078: div.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806AE07C: lui         $at, 0x4214
    ctx->r1 = S32(0X4214 << 16);
    // 0x806AE080: lui         $a3, 0x806B
    ctx->r7 = S32(RELOC_HI16(595, 0X1990) << 16);
    // 0x806AE084: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806AE088: addiu       $a3, $a3, -0x930
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(595, 0X1990));
    // 0x806AE08C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x806AE090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806AE094: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x806AE098: addiu       $t2, $sp, 0x40
    ctx->r10 = ADD32(ctx->r29, 0X40);
    // 0x806AE09C: addiu       $t1, $sp, 0x10
    ctx->r9 = ADD32(ctx->r29, 0X10);
    // 0x806AE0A0: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x806AE0A4: sub.s       $f12, $f16, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f6.fl;
L_806AE0A8:
    // 0x806AE0A8: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x806AE0AC: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x806AE0B0: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x806AE0B4: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x806AE0B8: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x806AE0BC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x806AE0C0: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806AE0C4: mflo        $t6
    ctx->r14 = lo;
    // 0x806AE0C8: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x806AE0CC: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x806AE0D0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x806AE0D4: addu        $t9, $a3, $t4
    ctx->r25 = ADD32(ctx->r7, ctx->r12);
    // 0x806AE0D8: addu        $t5, $t9, $a1
    ctx->r13 = ADD32(ctx->r25, ctx->r5);
    // 0x806AE0DC: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x806AE0E0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x806AE0E4: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x806AE0E8: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x806AE0EC: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x806AE0F0: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x806AE0F4: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x806AE0F8: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
    // 0x806AE0FC: lw          $t8, 0x10($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X10);
    // 0x806AE100: sw          $t8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r24;
    // 0x806AE104: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x806AE108: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x806AE10C: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x806AE110: addu        $t5, $t6, $t9
    ctx->r13 = ADD32(ctx->r14, ctx->r25);
    // 0x806AE114: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x806AE118: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806AE11C: mflo        $t8
    ctx->r24 = lo;
    // 0x806AE120: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x806AE124: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x806AE128: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x806AE12C: addu        $t6, $a3, $t4
    ctx->r14 = ADD32(ctx->r7, ctx->r12);
    // 0x806AE130: addu        $t9, $t6, $a1
    ctx->r25 = ADD32(ctx->r14, ctx->r5);
    // 0x806AE134: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x806AE138: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // 0x806AE13C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x806AE140: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x806AE144: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x806AE148: lw          $t7, 0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X8);
    // 0x806AE14C: sw          $t7, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r15;
    // 0x806AE150: lw          $t5, 0xC($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC);
    // 0x806AE154: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x806AE158: lw          $t7, 0x10($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X10);
    // 0x806AE15C: beq         $v1, $zero, L_806AE260
    if (ctx->r3 == 0) {
        // 0x806AE160: sw          $t7, 0x10($t1)
        MEM_W(0X10, ctx->r9) = ctx->r15;
            goto L_806AE260;
    }
    // 0x806AE160: sw          $t7, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r15;
    // 0x806AE164: lh          $t8, 0x10($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X10);
    // 0x806AE168: lh          $t4, 0x24($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X24);
    // 0x806AE16C: sub.s       $f14, $f16, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x806AE170: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x806AE174: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x806AE178: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806AE17C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806AE180: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x806AE184: nop

    // 0x806AE188: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x806AE18C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x806AE190: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x806AE194: nop

    // 0x806AE198: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806AE19C: swc1        $f10, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f10.u32l;
    // 0x806AE1A0: lh          $t6, 0x12($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X12);
    // 0x806AE1A4: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x806AE1A8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x806AE1AC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x806AE1B0: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806AE1B4: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806AE1B8: mul.s       $f4, $f6, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x806AE1BC: nop

    // 0x806AE1C0: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x806AE1C4: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x806AE1C8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x806AE1CC: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x806AE1D0: swc1        $f6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f6.u32l;
    // 0x806AE1D4: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x806AE1D8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x806AE1DC: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x806AE1E0: nop

    // 0x806AE1E4: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x806AE1E8: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x806AE1EC: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806AE1F0: swc1        $f8, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f8.u32l;
    // 0x806AE1F4: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x806AE1F8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x806AE1FC: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x806AE200: nop

    // 0x806AE204: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x806AE208: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x806AE20C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x806AE210: swc1        $f4, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f4.u32l;
    // 0x806AE214: lh          $t5, 0x30($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X30);
    // 0x806AE218: lh          $t7, 0x1C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1C);
    // 0x806AE21C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x806AE220: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x806AE224: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806AE228: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806AE22C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x806AE230: nop

    // 0x806AE234: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x806AE238: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x806AE23C: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x806AE240: swc1        $f6, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f6.u32l;
    // 0x806AE244: lh          $t8, 0x34($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X34);
    // 0x806AE248: sh          $t8, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r24;
    // 0x806AE24C: lbu         $t4, 0x32($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X32);
    // 0x806AE250: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x806AE254: addu        $t9, $t2, $t6
    ctx->r25 = ADD32(ctx->r10, ctx->r14);
    // 0x806AE258: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x806AE25C: sw          $t5, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r13;
L_806AE260:
    // 0x806AE260: bne         $a1, $t3, L_806AE0A8
    if (ctx->r5 != ctx->r11) {
        // 0x806AE264: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_806AE0A8;
    }
    // 0x806AE264: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x806AE268: jr          $ra
    // 0x806AE26C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x806AE26C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800415FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800415FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80041600: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80041604: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80041608: jal         0x800309B8
    // 0x8004160C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800309B8(rdram, ctx);
        goto after_0;
    // 0x8004160C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80041610: beq         $v0, $zero, L_80041620
    if (ctx->r2 == 0) {
        // 0x80041614: nop
    
            goto L_80041620;
    }
    // 0x80041614: nop

    // 0x80041618: b           L_80041684
    // 0x8004161C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041684;
    // 0x8004161C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80041620:
    // 0x80041620: jal         0x800415D0
    // 0x80041624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800415D0(rdram, ctx);
        goto after_1;
    // 0x80041624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80041628: beq         $v0, $zero, L_80041638
    if (ctx->r2 == 0) {
        // 0x8004162C: nop
    
            goto L_80041638;
    }
    // 0x8004162C: nop

    // 0x80041630: b           L_80041684
    // 0x80041634: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041684;
    // 0x80041634: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80041638:
    // 0x80041638: jal         0x80033FB0
    // 0x8004163C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80033FB0(rdram, ctx);
        goto after_2;
    // 0x8004163C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80041640: beq         $v0, $zero, L_80041650
    if (ctx->r2 == 0) {
        // 0x80041644: nop
    
            goto L_80041650;
    }
    // 0x80041644: nop

    // 0x80041648: b           L_80041684
    // 0x8004164C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041684;
    // 0x8004164C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80041650:
    // 0x80041650: jal         0x8003200C
    // 0x80041654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003200C(rdram, ctx);
        goto after_3;
    // 0x80041654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80041658: beq         $v0, $zero, L_80041668
    if (ctx->r2 == 0) {
        // 0x8004165C: nop
    
            goto L_80041668;
    }
    // 0x8004165C: nop

    // 0x80041660: b           L_80041684
    // 0x80041664: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041684;
    // 0x80041664: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80041668:
    // 0x80041668: jal         0x8003BEC8
    // 0x8004166C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003BEC8(rdram, ctx);
        goto after_4;
    // 0x8004166C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80041670: beql        $v0, $zero, L_80041684
    if (ctx->r2 == 0) {
        // 0x80041674: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80041684;
    }
    goto skip_0;
    // 0x80041674: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80041678: b           L_80041684
    // 0x8004167C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041684;
    // 0x8004167C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80041680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80041684:
    // 0x80041684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80041688: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004168C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80041690: jr          $ra
    // 0x80041694: nop

    return;
    // 0x80041694: nop

;}
