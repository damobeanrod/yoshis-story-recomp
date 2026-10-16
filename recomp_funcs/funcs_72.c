#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8064E4D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E4D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8064E4DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064E4E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064E4E4: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8064E4E8: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8064E4EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064E4F0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8064E4F4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8064E4F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8064E4FC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8064E500: jal         0x80048F84
    // 0x8064E504: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8064E504: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x8064E508: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8064E50C: jal         0x80048F84
    // 0x8064E510: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8064E510: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8064E514: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8064E518: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8064E51C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064E520: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8064E524: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8064E528: nop

    // 0x8064E52C: bc1fl       L_8064E568
    if (!c1cs) {
        // 0x8064E530: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8064E568;
    }
    goto skip_0;
    // 0x8064E530: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x8064E534: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8064E538: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8064E53C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8064E540: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8064E544: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8064E548: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8064E54C: nop

    // 0x8064E550: bc1fl       L_8064E588
    if (!c1cs) {
        // 0x8064E554: swc1        $f0, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
            goto L_8064E588;
    }
    goto skip_1;
    // 0x8064E554: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    skip_1:
    // 0x8064E558: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8064E55C: b           L_8064E588
    // 0x8064E560: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
        goto L_8064E588;
    // 0x8064E560: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8064E564: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8064E568:
    // 0x8064E568: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8064E56C: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8064E570: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8064E574: nop

    // 0x8064E578: bc1fl       L_8064E588
    if (!c1cs) {
        // 0x8064E57C: swc1        $f0, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
            goto L_8064E588;
    }
    goto skip_2;
    // 0x8064E57C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    skip_2:
    // 0x8064E580: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8064E584: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
L_8064E588:
    // 0x8064E588: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8064E58C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8064E590: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8064E594: lbu         $t0, 0x2C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2C);
    // 0x8064E598: beql        $t0, $zero, L_8064E5D8
    if (ctx->r8 == 0) {
        // 0x8064E59C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8064E5D8;
    }
    goto skip_3;
    // 0x8064E59C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8064E5A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8064E5A4: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x8064E5A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064E5AC: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x8064E5B0: nop

    // 0x8064E5B4: bc1fl       L_8064E5D8
    if (!c1cs) {
        // 0x8064E5B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8064E5D8;
    }
    goto skip_4;
    // 0x8064E5B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8064E5BC: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x8064E5C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064E5C4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8064E5C8: sw          $t1, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r9;
    // 0x8064E5CC: jal         0x8064E7C0
    // 0x8064E5D0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8064E7C0(rdram, ctx);
        goto after_2;
    // 0x8064E5D0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x8064E5D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064E5D8:
    // 0x8064E5D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064E5DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8064E5E0: jr          $ra
    // 0x8064E5E4: nop

    return;
    // 0x8064E5E4: nop

;}
RECOMP_FUNC void func_80716860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716860: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80716864: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80716868: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8071686C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80716870: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80716874: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80716878: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8071687C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80716880: addiu       $t6, $zero, 0x960
    ctx->r14 = ADD32(0, 0X960);
    // 0x80716884: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80716888: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8071688C: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x80716890: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // 0x80716894: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80716898: jal         0x8071637C
    // 0x8071689C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8071637C(rdram, ctx);
        goto after_0;
    // 0x8071689C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x807168A0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x807168A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807168A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x807168AC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x807168B0: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x807168B4: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x807168B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807168BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807168C0: jr          $ra
    // 0x807168C4: nop

    return;
    // 0x807168C4: nop

;}
RECOMP_FUNC void func_806ED034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806ED038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806ED03C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806ED040: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806ED044: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x806ED048: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x806ED04C: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x806ED050: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806ED054: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806ED058: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806ED05C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x806ED060: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806ED064: nop

    // 0x806ED068: bc1fl       L_806ED07C
    if (!c1cs) {
        // 0x806ED06C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806ED07C;
    }
    goto skip_0;
    // 0x806ED06C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806ED070: jal         0x8002F6E4
    // 0x806ED074: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x806ED074: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x806ED078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806ED07C:
    // 0x806ED07C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806ED080: jr          $ra
    // 0x806ED084: nop

    return;
    // 0x806ED084: nop

;}
RECOMP_FUNC void func_8040B6B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B6B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040B6B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040B6B8: jal         0x8040AE28
    // 0x8040B6BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040AE28(rdram, ctx);
        goto after_0;
    // 0x8040B6BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040B6C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040B6C4: lui         $t9, 0x8041
    ctx->r25 = S32(RELOC_HI16(14, 0X1338) << 16);
    // 0x8040B6C8: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x8040B6CC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8040B6D0: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8040B6D4: lw          $t9, -0x4168($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(14, 0X1338));
    // 0x8040B6D8: jalr        $t9
    // 0x8040B6DC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8040B6DC: nop

    after_1:
    // 0x8040B6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040B6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040B6E8: jr          $ra
    // 0x8040B6EC: nop

    return;
    // 0x8040B6EC: nop

;}
RECOMP_FUNC void func_805D8370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D8370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D8374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D8378: jal         0x8004700C
    // 0x805D837C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805D837C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D8380: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805D8384: beq         $v0, $zero, L_805D83D8
    if (ctx->r2 == 0) {
        // 0x805D8388: lw          $a1, 0x174($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X174);
            goto L_805D83D8;
    }
    // 0x805D8388: lw          $a1, 0x174($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X174);
    // 0x805D838C: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x805D8390: lbu         $t7, 0x10($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X10);
    // 0x805D8394: lbu         $v1, 0x10($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X10);
    // 0x805D8398: beq         $t7, $v1, L_805D83D8
    if (ctx->r15 == ctx->r3) {
        // 0x805D839C: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_805D83D8;
    }
    // 0x805D839C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x805D83A0: beq         $v1, $zero, L_805D83D8
    if (ctx->r3 == 0) {
        // 0x805D83A4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_805D83D8;
    }
    // 0x805D83A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805D83A8: bne         $v1, $at, L_805D83C0
    if (ctx->r3 != ctx->r1) {
        // 0x805D83AC: sb          $v1, 0x10($a1)
        MEM_B(0X10, ctx->r5) = ctx->r3;
            goto L_805D83C0;
    }
    // 0x805D83AC: sb          $v1, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r3;
    // 0x805D83B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805D83B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805D83B8: b           L_805D83D8
    // 0x805D83BC: swc1        $f4, 0xE0($a2)
    MEM_W(0XE0, ctx->r6) = ctx->f4.u32l;
        goto L_805D83D8;
    // 0x805D83BC: swc1        $f4, 0xE0($a2)
    MEM_W(0XE0, ctx->r6) = ctx->f4.u32l;
L_805D83C0:
    // 0x805D83C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805D83C4: bne         $a0, $at, L_805D83D8
    if (ctx->r4 != ctx->r1) {
        // 0x805D83C8: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_805D83D8;
    }
    // 0x805D83C8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805D83CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805D83D0: nop

    // 0x805D83D4: swc1        $f6, 0xE0($a2)
    MEM_W(0XE0, ctx->r6) = ctx->f6.u32l;
L_805D83D8:
    // 0x805D83D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D83DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D83E0: jr          $ra
    // 0x805D83E4: nop

    return;
    // 0x805D83E4: nop

;}
RECOMP_FUNC void func_807AE8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE8BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AE8C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AE8C4: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807AE8C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AE8CC: blez        $v0, L_807AE8DC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807AE8D0: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807AE8DC;
    }
    // 0x807AE8D0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807AE8D4: b           L_807AE8E4
    // 0x807AE8D8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_807AE8E4;
    // 0x807AE8D8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_807AE8DC:
    // 0x807AE8DC: jal         0x807AEA24
    // 0x807AE8E0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_807AEA24(rdram, ctx);
        goto after_0;
    // 0x807AE8E0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_0:
L_807AE8E4:
    // 0x807AE8E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AE8E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AE8EC: jr          $ra
    // 0x807AE8F0: nop

    return;
    // 0x807AE8F0: nop

;}
RECOMP_FUNC void func_80798BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798BFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80798C00: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80798C04: beq         $at, $zero, L_80798C14
    if (ctx->r1 == 0) {
        // 0x80798C08: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80798C14;
    }
    // 0x80798C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80798C0C: b           L_80798C70
    // 0x80798C10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80798C70;
    // 0x80798C10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80798C14:
    // 0x80798C14: bnel        $a0, $a1, L_80798C28
    if (ctx->r4 != ctx->r5) {
        // 0x80798C18: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80798C28;
    }
    goto skip_0;
    // 0x80798C18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x80798C1C: b           L_80798C70
    // 0x80798C20: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80798C70;
    // 0x80798C20: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80798C24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80798C28:
    // 0x80798C28: jal         0x800653D8
    // 0x80798C2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80798C2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80798C30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80798C34: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80798C38: subu        $t6, $a1, $a0
    ctx->r14 = SUB32(ctx->r5, ctx->r4);
    // 0x80798C3C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80798C40: div         $zero, $v0, $t7
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r15)));
    // 0x80798C44: mfhi        $t8
    ctx->r24 = hi;
    // 0x80798C48: bne         $t7, $zero, L_80798C54
    if (ctx->r15 != 0) {
        // 0x80798C4C: nop
    
            goto L_80798C54;
    }
    // 0x80798C4C: nop

    // 0x80798C50: break       7
    do_break(2155449424);
L_80798C54:
    // 0x80798C54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80798C58: bne         $t7, $at, L_80798C6C
    if (ctx->r15 != ctx->r1) {
        // 0x80798C5C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80798C6C;
    }
    // 0x80798C5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80798C60: bne         $v0, $at, L_80798C6C
    if (ctx->r2 != ctx->r1) {
        // 0x80798C64: nop
    
            goto L_80798C6C;
    }
    // 0x80798C64: nop

    // 0x80798C68: break       6
    do_break(2155449448);
L_80798C6C:
    // 0x80798C6C: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
L_80798C70:
    // 0x80798C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80798C74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80798C78: jr          $ra
    // 0x80798C7C: nop

    return;
    // 0x80798C7C: nop

;}
RECOMP_FUNC void func_8006DE24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DE24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006DE28: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8006DE2C: lw          $v0, -0x7BC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7BC4);
    // 0x8006DE30: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006DE34: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8006DE38: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8006DE3C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006DE40: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006DE44: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006DE48: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006DE4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006DE50: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006DE54: lbu         $t8, 0x5D($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5D);
    // 0x8006DE58: lbu         $t7, 0x5C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5C);
    // 0x8006DE5C: lw          $t6, 0x60($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X60);
    // 0x8006DE60: lui         $s4, 0x800B
    ctx->r20 = S32(0X800B << 16);
    // 0x8006DE64: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006DE68: addiu       $s4, $s4, 0x1104
    ctx->r20 = ADD32(ctx->r20, 0X1104);
    // 0x8006DE6C: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x8006DE70: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8006DE74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8006DE78: lw          $s2, 0x0($t6)
    ctx->r18 = MEM_W(ctx->r14, 0X0);
    // 0x8006DE7C: mflo        $s6
    ctx->r22 = lo;
    // 0x8006DE80: blezl       $s6, L_8006DEF0
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8006DE84: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8006DEF0;
    }
    goto skip_0;
    // 0x8006DE84: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
L_8006DE88:
    // 0x8006DE88: lh          $v1, 0x0($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X0);
    // 0x8006DE8C: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x8006DE90: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006DE94: blezl       $v1, L_8006DEE4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8006DE98: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8006DEE4;
    }
    goto skip_1;
    // 0x8006DE98: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_1:
L_8006DE9C:
    // 0x8006DE9C: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x8006DEA0: beql        $s3, $a0, L_8006DED4
    if (ctx->r19 == ctx->r4) {
        // 0x8006DEA4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8006DED4;
    }
    goto skip_2;
    // 0x8006DEA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x8006DEA8: jal         0x80051194
    // 0x8006DEAC: nop

    func_80051194(rdram, ctx);
        goto after_0;
    // 0x8006DEAC: nop

    after_0:
    // 0x8006DEB0: beq         $v0, $zero, L_8006DEC4
    if (ctx->r2 == 0) {
        // 0x8006DEB4: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8006DEC4;
    }
    // 0x8006DEB4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8006DEB8: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x8006DEBC: b           L_8006DED0
    // 0x8006DEC0: lh          $v1, 0x0($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X0);
        goto L_8006DED0;
    // 0x8006DEC0: lh          $v1, 0x0($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X0);
L_8006DEC4:
    // 0x8006DEC4: jal         0x80071380
    // 0x8006DEC8: addiu       $a1, $zero, 0x2B5
    ctx->r5 = ADD32(0, 0X2B5);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8006DEC8: addiu       $a1, $zero, 0x2B5
    ctx->r5 = ADD32(0, 0X2B5);
    after_1:
    // 0x8006DECC: lh          $v1, 0x0($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X0);
L_8006DED0:
    // 0x8006DED0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8006DED4:
    // 0x8006DED4: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006DED8: bne         $at, $zero, L_8006DE9C
    if (ctx->r1 != 0) {
        // 0x8006DEDC: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_8006DE9C;
    }
    // 0x8006DEDC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8006DEE0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_8006DEE4:
    // 0x8006DEE4: bne         $s5, $s6, L_8006DE88
    if (ctx->r21 != ctx->r22) {
        // 0x8006DEE8: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_8006DE88;
    }
    // 0x8006DEE8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8006DEEC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8006DEF0:
    // 0x8006DEF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006DEF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DEF8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006DEFC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006DF00: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006DF04: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8006DF08: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8006DF0C: jr          $ra
    // 0x8006DF10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006DF10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80798FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798FCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80798FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80798FD4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80798FD8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80798FDC: jal         0x80047090
    // 0x80798FE0: addiu       $a0, $zero, 0x46AF
    ctx->r4 = ADD32(0, 0X46AF);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80798FE0: addiu       $a0, $zero, 0x46AF
    ctx->r4 = ADD32(0, 0X46AF);
    after_0:
    // 0x80798FE4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80798FE8: lui         $at, 0x46AF
    ctx->r1 = S32(0X46AF << 16);
    // 0x80798FEC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80798FF0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x80798FF4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80798FF8: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x80798FFC: jal         0x8004613C
    // 0x80799000: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80799000: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    after_1:
    // 0x80799004: beq         $v0, $zero, L_80799028
    if (ctx->r2 == 0) {
        // 0x80799008: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80799028;
    }
    // 0x80799008: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8079900C: jal         0x80044194
    // 0x80799010: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x80799010: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80799014: jal         0x80798DB0
    // 0x80799018: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80798DB0(rdram, ctx);
        goto after_3;
    // 0x80799018: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8079901C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80799020: jal         0x80798E38
    // 0x80799024: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80798E38(rdram, ctx);
        goto after_4;
    // 0x80799024: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
L_80799028:
    // 0x80799028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079902C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80799030: jr          $ra
    // 0x80799034: nop

    return;
    // 0x80799034: nop

;}
RECOMP_FUNC void func_8058121C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058121C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80581220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581224: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80581228: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8058122C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80581230: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80581234: jal         0x80580CE8
    // 0x80581238: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80580CE8(rdram, ctx);
        goto after_0;
    // 0x80581238: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8058123C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80581240: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x80581244: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x80581248: sb          $v0, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r2;
    // 0x8058124C: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x80581250: beql        $v1, $zero, L_80581290
    if (ctx->r3 == 0) {
        // 0x80581254: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80581290;
    }
    goto skip_0;
    // 0x80581254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80581258: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    // 0x8058125C: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80581260: beq         $v0, $zero, L_8058128C
    if (ctx->r2 == 0) {
        // 0x80581264: addu        $t7, $t7, $v0
        ctx->r15 = ADD32(ctx->r15, ctx->r2);
            goto L_8058128C;
    }
    // 0x80581264: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80581268: lw          $t7, 0x6F08($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6F08);
    // 0x8058126C: bne         $t7, $zero, L_80581284
    if (ctx->r15 != 0) {
        // 0x80581270: nop
    
            goto L_80581284;
    }
    // 0x80581270: nop

    // 0x80581274: jal         0x8058106C
    // 0x80581278: nop

    func_8058106C(rdram, ctx);
        goto after_1;
    // 0x80581278: nop

    after_1:
    // 0x8058127C: b           L_80581290
    // 0x80581280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80581290;
    // 0x80581280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80581284:
    // 0x80581284: jal         0x8058111C
    // 0x80581288: nop

    func_8058111C(rdram, ctx);
        goto after_2;
    // 0x80581288: nop

    after_2:
L_8058128C:
    // 0x8058128C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80581290:
    // 0x80581290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581294: jr          $ra
    // 0x80581298: nop

    return;
    // 0x80581298: nop

;}
RECOMP_FUNC void func_80424AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424AC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80424AC4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80424AC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80424ACC: jal         0x804249A0
    // 0x80424AD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804249A0(rdram, ctx);
        goto after_0;
    // 0x80424AD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80424AD4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424AD8: lui         $a1, 0x8042
    ctx->r5 = S32(RELOC_HI16(35, 0X3380) << 16);
    // 0x80424ADC: lui         $a2, 0x8042
    ctx->r6 = S32(RELOC_HI16(35, 0X333C) << 16);
    // 0x80424AE0: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80424AE4: lw          $a3, 0xE4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XE4);
    // 0x80424AE8: addiu       $a2, $a2, 0x5D3C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(35, 0X333C));
    // 0x80424AEC: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80424AF0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80424AF4: addiu       $a1, $a1, 0x5D80
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(35, 0X3380));
    // 0x80424AF8: jal         0x80424824
    // 0x80424AFC: addiu       $a0, $v0, 0xA0
    ctx->r4 = ADD32(ctx->r2, 0XA0);
    func_80424824(rdram, ctx);
        goto after_1;
    // 0x80424AFC: addiu       $a0, $v0, 0xA0
    ctx->r4 = ADD32(ctx->r2, 0XA0);
    after_1:
    // 0x80424B00: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424B04: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(35, 0X36D8) << 16);
    // 0x80424B08: lwc1        $f6, 0x60D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(35, 0X36D8));
    // 0x80424B0C: lwc1        $f4, 0xE4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XE4);
    // 0x80424B10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80424B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80424B18: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80424B1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80424B20: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80424B24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80424B28: swc1        $f8, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->f8.u32l;
    // 0x80424B2C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424B30: lwc1        $f10, 0xE4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XE4);
    // 0x80424B34: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80424B38: nop

    // 0x80424B3C: bc1fl       L_80424B50
    if (!c1cs) {
        // 0x80424B40: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80424B50;
    }
    goto skip_0;
    // 0x80424B40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80424B44: jal         0x80424E54
    // 0x80424B48: swc1        $f0, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->f0.u32l;
    func_80424E54(rdram, ctx);
        goto after_2;
    // 0x80424B48: swc1        $f0, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->f0.u32l;
    after_2:
    // 0x80424B4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80424B50:
    // 0x80424B50: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80424B54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80424B58: jr          $ra
    // 0x80424B5C: nop

    return;
    // 0x80424B5C: nop

;}
RECOMP_FUNC void func_80565A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80565A74: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80565A78: lui         $t6, 0x8056
    ctx->r14 = S32(RELOC_HI16(369, 0X1CB8) << 16);
    // 0x80565A7C: addiu       $t6, $t6, 0x5518
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(369, 0X1CB8));
    // 0x80565A80: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80565A84: jr          $ra
    // 0x80565A88: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80565A88: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8044AC0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044AC0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044AC10: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X134A4) << 16);
    // 0x8044AC14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044AC18: addiu       $t6, $t6, 0x7884
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X134A4));
    // 0x8044AC1C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044AC20: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044AC24: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044AC28: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044AC2C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044AC30: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044AC34: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044AC38: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044AC3C: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044AC40: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044AC44: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044AC48: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044AC4C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044AC50: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044AC54: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044AC58: jal         0x80050A50
    // 0x8044AC5C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044AC5C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044AC60: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044AC64: jalr        $v0
    // 0x8044AC68: sw          $v0, 0x6A7C($v1)
    MEM_W(0X6A7C, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044AC68: sw          $v0, 0x6A7C($v1)
    MEM_W(0X6A7C, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044AC6C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044AC70: sw          $v0, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->r2;
    // 0x8044AC74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044AC78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044AC7C: jr          $ra
    // 0x8044AC80: nop

    return;
    // 0x8044AC80: nop

;}
RECOMP_FUNC void func_8000DD40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DD40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000DD44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000DD48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000DD4C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000DD50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000DD54: srl         $t6, $v0, 31
    ctx->r14 = S32(U32(ctx->r2) >> 31);
    // 0x8000DD58: beql        $t6, $zero, L_8000DE34
    if (ctx->r14 == 0) {
        // 0x8000DD5C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000DE34;
    }
    goto skip_0;
    // 0x8000DD5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8000DD60: lh          $v1, 0x8($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X8);
    // 0x8000DD64: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8000DD68: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8000DD6C: bne         $at, $zero, L_8000DDA8
    if (ctx->r1 != 0) {
        // 0x8000DD70: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8000DDA8;
    }
    // 0x8000DD70: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8000DD74: bltz        $t9, L_8000DE30
    if (SIGNED(ctx->r25) < 0) {
        // 0x8000DD78: sh          $t7, 0x8($a0)
        MEM_H(0X8, ctx->r4) = ctx->r15;
            goto L_8000DE30;
    }
    // 0x8000DD78: sh          $t7, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r15;
    // 0x8000DD7C: lh          $t0, 0xA($a0)
    ctx->r8 = MEM_H(ctx->r4, 0XA);
    // 0x8000DD80: lh          $t1, 0x8($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X8);
    // 0x8000DD84: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000DD88: bnel        $at, $zero, L_8000DE34
    if (ctx->r1 != 0) {
        // 0x8000DD8C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000DE34;
    }
    goto skip_1;
    // 0x8000DD8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8000DD90: jal         0x8000BBF4
    // 0x8000DD94: nop

    func_8000BBF4(rdram, ctx);
        goto after_0;
    // 0x8000DD94: nop

    after_0:
    // 0x8000DD98: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x8000DD9C: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x8000DDA0: b           L_8000DE30
    // 0x8000DDA4: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
        goto L_8000DE30;
    // 0x8000DDA4: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
L_8000DDA8:
    // 0x8000DDA8: jal         0x8000DE44
    // 0x8000DDAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000DE44(rdram, ctx);
        goto after_1;
    // 0x8000DDAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000DDB0: jal         0x8000E02C
    // 0x8000DDB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000E02C(rdram, ctx);
        goto after_2;
    // 0x8000DDB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8000DDB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000DDBC: beq         $v0, $at, L_8000DE30
    if (ctx->r2 == ctx->r1) {
        // 0x8000DDC0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000DE30;
    }
    // 0x8000DDC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000DDC4: jal         0x8000E804
    // 0x8000DDC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000E804(rdram, ctx);
        goto after_3;
    // 0x8000DDC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8000DDCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000DDD0: beq         $v0, $at, L_8000DDE4
    if (ctx->r2 == ctx->r1) {
        // 0x8000DDD4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000DDE4;
    }
    // 0x8000DDD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000DDD8: jal         0x8000E398
    // 0x8000DDDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000E398(rdram, ctx);
        goto after_4;
    // 0x8000DDDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8000DDE0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8000DDE4:
    // 0x8000DDE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000DDE8: beql        $v0, $at, L_8000DDFC
    if (ctx->r2 == ctx->r1) {
        // 0x8000DDEC: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8000DDFC;
    }
    goto skip_2;
    // 0x8000DDEC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8000DDF0: jal         0x8000DED0
    // 0x8000DDF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000DED0(rdram, ctx);
        goto after_5;
    // 0x8000DDF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8000DDF8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8000DDFC:
    // 0x8000DDFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000DE00: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8000DE04: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x8000DE08: bnel        $t6, $at, L_8000DE34
    if (ctx->r14 != ctx->r1) {
        // 0x8000DE0C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000DE34;
    }
    goto skip_3;
    // 0x8000DE0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8000DE10: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8000DE14: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x8000DE18: bne         $t7, $zero, L_8000DE28
    if (ctx->r15 != 0) {
        // 0x8000DE1C: nop
    
            goto L_8000DE28;
    }
    // 0x8000DE1C: nop

    // 0x8000DE20: bgezl       $t9, L_8000DE34
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000DE24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000DE34;
    }
    goto skip_4;
    // 0x8000DE24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
L_8000DE28:
    // 0x8000DE28: jal         0x8000BBF4
    // 0x8000DE2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000BBF4(rdram, ctx);
        goto after_6;
    // 0x8000DE2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_8000DE30:
    // 0x8000DE30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000DE34:
    // 0x8000DE34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000DE38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000DE3C: jr          $ra
    // 0x8000DE40: nop

    return;
    // 0x8000DE40: nop

;}
RECOMP_FUNC void func_8064A0D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A0D0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8064A0D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8064A0D8: addiu       $t7, $t6, -0x453E
    ctx->r15 = ADD32(ctx->r14, -0X453E);
    // 0x8064A0DC: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8064A0E0: beq         $at, $zero, L_8064A150
    if (ctx->r1 == 0) {
        // 0x8064A0E4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8064A150;
    }
    // 0x8064A0E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8064A0E8: lui         $at, 0x8065
    ctx->r1 = S32(RELOC_HI16(495, 0X3630) << 16);
    // 0x8064A0EC: addu        $at, $at, $t7
    gpr jr_addend_8064A0F4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8064A0F0: lw          $t7, -0x2900($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(495, 0X3630));
    // 0x8064A0F4: jr          $t7
    // 0x8064A0F8: nop

    switch (jr_addend_8064A0F4 >> 2) {
        case 0: goto L_8064A0FC; break;
        case 1: goto L_8064A108; break;
        case 2: goto L_8064A114; break;
        case 3: goto L_8064A120; break;
        case 4: goto L_8064A12C; break;
        case 5: goto L_8064A138; break;
        case 6: goto L_8064A144; break;
        default: switch_error(__func__, 0x8064A0F4, 0x8064D700);
    }
    // 0x8064A0F8: nop

L_8064A0FC:
    // 0x8064A0FC: lui         $v0, 0x8065
    ctx->r2 = S32(RELOC_HI16(495, 0X7D4) << 16);
    // 0x8064A100: jr          $ra
    // 0x8064A104: addiu       $v0, $v0, -0x575C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(495, 0X7D4));
    return;
    // 0x8064A104: addiu       $v0, $v0, -0x575C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(495, 0X7D4));
L_8064A108:
    // 0x8064A108: lui         $v0, 0x8065
    ctx->r2 = S32(RELOC_HI16(495, 0XD00) << 16);
    // 0x8064A10C: jr          $ra
    // 0x8064A110: addiu       $v0, $v0, -0x5230
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(495, 0XD00));
    return;
    // 0x8064A110: addiu       $v0, $v0, -0x5230
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(495, 0XD00));
L_8064A114:
    // 0x8064A114: lui         $v0, 0x8065
    ctx->r2 = S32(RELOC_HI16(495, 0X122C) << 16);
    // 0x8064A118: jr          $ra
    // 0x8064A11C: addiu       $v0, $v0, -0x4D04
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(495, 0X122C));
    return;
    // 0x8064A11C: addiu       $v0, $v0, -0x4D04
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(495, 0X122C));
L_8064A120:
    // 0x8064A120: lui         $v0, 0x8065
    ctx->r2 = S32(RELOC_HI16(495, 0X1764) << 16);
    // 0x8064A124: jr          $ra
    // 0x8064A128: addiu       $v0, $v0, -0x47CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(495, 0X1764));
    return;
    // 0x8064A128: addiu       $v0, $v0, -0x47CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(495, 0X1764));
L_8064A12C:
    // 0x8064A12C: lui         $v0, 0x8065
    ctx->r2 = S32(RELOC_HI16(495, 0X1DC8) << 16);
    // 0x8064A130: jr          $ra
    // 0x8064A134: addiu       $v0, $v0, -0x4168
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(495, 0X1DC8));
    return;
    // 0x8064A134: addiu       $v0, $v0, -0x4168
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(495, 0X1DC8));
L_8064A138:
    // 0x8064A138: lui         $v0, 0x8065
    ctx->r2 = S32(RELOC_HI16(495, 0X242C) << 16);
    // 0x8064A13C: jr          $ra
    // 0x8064A140: addiu       $v0, $v0, -0x3B04
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(495, 0X242C));
    return;
    // 0x8064A140: addiu       $v0, $v0, -0x3B04
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(495, 0X242C));
L_8064A144:
    // 0x8064A144: lui         $v0, 0x8065
    ctx->r2 = S32(RELOC_HI16(495, 0X2BA8) << 16);
    // 0x8064A148: jr          $ra
    // 0x8064A14C: addiu       $v0, $v0, -0x3388
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(495, 0X2BA8));
    return;
    // 0x8064A14C: addiu       $v0, $v0, -0x3388
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(495, 0X2BA8));
L_8064A150:
    // 0x8064A150: jr          $ra
    // 0x8064A154: nop

    return;
    // 0x8064A154: nop

;}
RECOMP_FUNC void func_8078F584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F584: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8078F588: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8078F58C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8078F590: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8078F594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078F598: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8078F59C: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x8078F5A0: bne         $a1, $zero, L_8078F5B0
    if (ctx->r5 != 0) {
        // 0x8078F5A4: lwc1        $f2, 0x1FC($t7)
        ctx->f2.u32l = MEM_W(ctx->r15, 0X1FC);
            goto L_8078F5B0;
    }
    // 0x8078F5A4: lwc1        $f2, 0x1FC($t7)
    ctx->f2.u32l = MEM_W(ctx->r15, 0X1FC);
    // 0x8078F5A8: b           L_8078F5BC
    // 0x8078F5AC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
        goto L_8078F5BC;
    // 0x8078F5AC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_8078F5B0:
    // 0x8078F5B0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8078F5B4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8078F5B8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
L_8078F5BC:
    // 0x8078F5BC: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x8078F5C0: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x8078F5C4: lwc1        $f0, 0x1FC($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X1FC);
    // 0x8078F5C8: jal         0x80065954
    // 0x8078F5CC: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8078F5CC: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    after_0:
    // 0x8078F5D0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8078F5D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8078F5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8078F5DC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8078F5E0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8078F5E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8078F5E8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8078F5EC: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8078F5F0: nop

    // 0x8078F5F4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8078F5F8: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8078F5FC: nop

    // 0x8078F600: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8078F604: beql        $v0, $zero, L_8078F654
    if (ctx->r2 == 0) {
        // 0x8078F608: mfc1        $v0, $f8
        ctx->r2 = (int32_t)ctx->f8.u32l;
            goto L_8078F654;
    }
    goto skip_0;
    // 0x8078F608: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x8078F60C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8078F610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8078F614: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8078F618: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8078F61C: nop

    // 0x8078F620: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8078F624: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8078F628: nop

    // 0x8078F62C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8078F630: bne         $v0, $zero, L_8078F648
    if (ctx->r2 != 0) {
        // 0x8078F634: nop
    
            goto L_8078F648;
    }
    // 0x8078F634: nop

    // 0x8078F638: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8078F63C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8078F640: b           L_8078F660
    // 0x8078F644: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_8078F660;
    // 0x8078F644: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_8078F648:
    // 0x8078F648: b           L_8078F660
    // 0x8078F64C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8078F660;
    // 0x8078F64C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8078F650: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
L_8078F654:
    // 0x8078F654: nop

    // 0x8078F658: bltz        $v0, L_8078F648
    if (SIGNED(ctx->r2) < 0) {
        // 0x8078F65C: nop
    
            goto L_8078F648;
    }
    // 0x8078F65C: nop

L_8078F660:
    // 0x8078F660: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8078F664: sltiu       $at, $v0, 0x50
    ctx->r1 = ctx->r2 < 0X50 ? 1 : 0;
    // 0x8078F668: beq         $at, $zero, L_8078F674
    if (ctx->r1 == 0) {
        // 0x8078F66C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8078F674;
    }
    // 0x8078F66C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8078F670: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
L_8078F674:
    // 0x8078F674: jal         0x8078F524
    // 0x8078F678: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8078F524(rdram, ctx);
        goto after_1;
    // 0x8078F678: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8078F67C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8078F680: sltiu       $at, $a1, 0x4
    ctx->r1 = ctx->r5 < 0X4 ? 1 : 0;
    // 0x8078F684: bnel        $at, $zero, L_8078F698
    if (ctx->r1 != 0) {
        // 0x8078F688: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078F698;
    }
    goto skip_1;
    // 0x8078F688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8078F68C: jal         0x8078F304
    // 0x8078F690: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8078F304(rdram, ctx);
        goto after_2;
    // 0x8078F690: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8078F694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078F698:
    // 0x8078F698: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8078F69C: jr          $ra
    // 0x8078F6A0: nop

    return;
    // 0x8078F6A0: nop

;}
RECOMP_FUNC void func_806EC5D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC5D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EC5D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EC5DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806EC5E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806EC5E4: jal         0x8004700C
    // 0x806EC5E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806EC5E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x806EC5EC: bnel        $v0, $zero, L_806EC600
    if (ctx->r2 != 0) {
        // 0x806EC5F0: lwc1        $f6, 0x88($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
            goto L_806EC600;
    }
    goto skip_0;
    // 0x806EC5F0: lwc1        $f6, 0x88($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
    skip_0:
    // 0x806EC5F4: b           L_806EC6F0
    // 0x806EC5F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806EC6F0;
    // 0x806EC5F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806EC5FC: lwc1        $f6, 0x88($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
L_806EC600:
    // 0x806EC600: lwc1        $f8, 0x88($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X88);
    // 0x806EC604: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x806EC608: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806EC60C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806EC610: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x806EC614: nop

    // 0x806EC618: bc1fl       L_806EC6F0
    if (!c1cs) {
        // 0x806EC61C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806EC6F0;
    }
    goto skip_1;
    // 0x806EC61C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x806EC620: lwc1        $f16, 0x84($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X84);
    // 0x806EC624: lwc1        $f18, 0x84($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806EC628: lui         $at, 0x423C
    ctx->r1 = S32(0X423C << 16);
    // 0x806EC62C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806EC630: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x806EC634: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806EC638: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x806EC63C: nop

    // 0x806EC640: bc1fl       L_806EC6F0
    if (!c1cs) {
        // 0x806EC644: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806EC6F0;
    }
    goto skip_2;
    // 0x806EC644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x806EC648: lh          $a0, 0x184($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X184);
    // 0x806EC64C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806EC650: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x806EC654: blez        $a0, L_806EC6EC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x806EC658: addiu       $a1, $zero, 0x45E3
        ctx->r5 = ADD32(0, 0X45E3);
            goto L_806EC6EC;
    }
    // 0x806EC658: addiu       $a1, $zero, 0x45E3
    ctx->r5 = ADD32(0, 0X45E3);
L_806EC65C:
    // 0x806EC65C: lw          $s0, 0x188($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X188);
    // 0x806EC660: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x806EC664: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x806EC668: beq         $s0, $zero, L_806EC6E4
    if (ctx->r16 == 0) {
        // 0x806EC66C: nop
    
            goto L_806EC6E4;
    }
    // 0x806EC66C: nop

    // 0x806EC670: lhu         $t6, 0xC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XC);
    // 0x806EC674: bne         $a1, $t6, L_806EC6E4
    if (ctx->r5 != ctx->r14) {
        // 0x806EC678: nop
    
            goto L_806EC6E4;
    }
    // 0x806EC678: nop

    // 0x806EC67C: lwc1        $f8, 0x84($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806EC680: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x806EC684: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x806EC688: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806EC68C: sb          $t7, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r15;
    // 0x806EC690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EC694: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EC698: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806EC69C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x806EC6A0: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x806EC6A4: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x806EC6A8: jal         0x806F0348
    // 0x806EC6AC: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    func_806F0348(rdram, ctx);
        goto after_1;
    // 0x806EC6AC: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x806EC6B0: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CCC) << 16);
    // 0x806EC6B4: lwc1        $f16, 0xC1C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CCC));
    // 0x806EC6B8: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x806EC6BC: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x806EC6C0: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
    // 0x806EC6C4: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    // 0x806EC6C8: jal         0x80067BBC
    // 0x806EC6CC: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x806EC6CC: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    after_2:
    // 0x806EC6D0: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x806EC6D4: jal         0x80067818
    // 0x806EC6D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x806EC6D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x806EC6DC: b           L_806EC6F0
    // 0x806EC6E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806EC6F0;
    // 0x806EC6E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806EC6E4:
    // 0x806EC6E4: bne         $at, $zero, L_806EC65C
    if (ctx->r1 != 0) {
        // 0x806EC6E8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_806EC65C;
    }
    // 0x806EC6E8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_806EC6EC:
    // 0x806EC6EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806EC6F0:
    // 0x806EC6F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806EC6F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806EC6F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806EC6FC: jr          $ra
    // 0x806EC700: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806EC700: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80566184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566184: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80566188: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8056618C: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80566190: lui         $t8, 0x8056
    ctx->r24 = S32(RELOC_HI16(372, 0X3A8) << 16);
    // 0x80566194: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80566198: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8056619C: addiu       $t8, $t8, 0x6408
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(372, 0X3A8));
    // 0x805661A0: ori         $t7, $t7, 0x30BF
    ctx->r15 = ctx->r15 | 0X30BF;
    // 0x805661A4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x805661A8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x805661AC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x805661B0: lui         $t0, 0xBF00
    ctx->r8 = S32(0XBF00 << 16);
    // 0x805661B4: addiu       $t1, $zero, 0x204
    ctx->r9 = ADD32(0, 0X204);
    // 0x805661B8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x805661BC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x805661C0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x805661C4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x805661C8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x805661CC: lui         $t3, 0x2
    ctx->r11 = S32(0X2 << 16);
    // 0x805661D0: ori         $t3, $t3, 0xA04
    ctx->r11 = ctx->r11 | 0XA04;
    // 0x805661D4: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x805661D8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x805661DC: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x805661E0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x805661E4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x805661E8: lui         $t5, 0x4
    ctx->r13 = S32(0X4 << 16);
    // 0x805661EC: ori         $t5, $t5, 0x60C
    ctx->r13 = ctx->r13 | 0X60C;
    // 0x805661F0: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x805661F4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x805661F8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x805661FC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80566200: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80566204: lui         $t7, 0x6
    ctx->r15 = S32(0X6 << 16);
    // 0x80566208: ori         $t7, $t7, 0xE0C
    ctx->r15 = ctx->r15 | 0XE0C;
    // 0x8056620C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80566210: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80566214: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80566218: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8056621C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80566220: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80566224: ori         $t9, $t9, 0xA10
    ctx->r25 = ctx->r25 | 0XA10;
    // 0x80566228: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8056622C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80566230: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80566234: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80566238: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8056623C: lui         $t2, 0xA
    ctx->r10 = S32(0XA << 16);
    // 0x80566240: ori         $t2, $t2, 0x1210
    ctx->r10 = ctx->r10 | 0X1210;
    // 0x80566244: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80566248: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8056624C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80566250: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80566254: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80566258: lui         $t4, 0xC
    ctx->r12 = S32(0XC << 16);
    // 0x8056625C: ori         $t4, $t4, 0x1214
    ctx->r12 = ctx->r12 | 0X1214;
    // 0x80566260: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80566264: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80566268: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8056626C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80566270: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80566274: lui         $t6, 0x12
    ctx->r14 = S32(0X12 << 16);
    // 0x80566278: ori         $t6, $t6, 0x1614
    ctx->r14 = ctx->r14 | 0X1614;
    // 0x8056627C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80566280: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80566284: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80566288: jr          $ra
    // 0x8056628C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    return;
    // 0x8056628C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
;}
RECOMP_FUNC void func_8057C728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C728: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8057C72C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057C730: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8057C734: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8057C738: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8057C73C: jal         0x8057C6EC
    // 0x8057C740: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_8057C6EC(rdram, ctx);
        goto after_0;
    // 0x8057C740: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x8057C744: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8057C748: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8057C74C: bne         $v0, $zero, L_8057C75C
    if (ctx->r2 != 0) {
        // 0x8057C750: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8057C75C;
    }
    // 0x8057C750: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8057C754: b           L_8057C8C0
    // 0x8057C758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8057C8C0;
    // 0x8057C758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8057C75C:
    // 0x8057C75C: lui         $t6, 0x8058
    ctx->r14 = S32(RELOC_HI16(387, 0XFC8) << 16);
    // 0x8057C760: sw          $a0, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r4;
    // 0x8057C764: addiu       $t6, $t6, -0x3528
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(387, 0XFC8));
    // 0x8057C768: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8057C76C: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x8057C770: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8057C774: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8057C778: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8057C77C: lui         $t7, 0x8058
    ctx->r15 = S32(RELOC_HI16(387, 0XFD8) << 16);
    // 0x8057C780: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8057C784: addiu       $t7, $t7, -0x3518
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(387, 0XFD8));
    // 0x8057C788: addu        $a2, $v1, $t7
    ctx->r6 = ADD32(ctx->r3, ctx->r15);
    // 0x8057C78C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8057C790: swc1        $f16, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f16.u32l;
    // 0x8057C794: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8057C798: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8057C79C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8057C7A0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8057C7A4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8057C7A8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8057C7AC: jal         0x80081C64
    // 0x8057C7B0: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x8057C7B0: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_1:
    // 0x8057C7B4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8057C7B8: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x8057C7BC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8057C7C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8057C7C4: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8057C7C8: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8057C7CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8057C7D0: div.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8057C7D4: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8057C7D8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8057C7DC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8057C7E0: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8057C7E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8057C7E8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8057C7EC: lui         $t8, 0x8058
    ctx->r24 = S32(RELOC_HI16(387, 0XFE8) << 16);
    // 0x8057C7F0: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x8057C7F4: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8057C7F8: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8057C7FC: mul.s       $f12, $f18, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8057C800: add.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x8057C804: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8057C808: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8057C80C: swc1        $f16, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f16.u32l;
    // 0x8057C810: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8057C814: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8057C818: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8057C81C: swc1        $f6, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f6.u32l;
    // 0x8057C820: lw          $t8, -0x3508($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(387, 0XFE8));
    // 0x8057C824: sw          $t8, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r24;
    // 0x8057C828: jal         0x80047F9C
    // 0x8057C82C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8057C82C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x8057C830: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8057C834: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8057C838: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8057C83C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8057C840: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8057C844: sb          $t9, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r25;
    // 0x8057C848: swc1        $f0, 0xC8($a1)
    MEM_W(0XC8, ctx->r5) = ctx->f0.u32l;
    // 0x8057C84C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8057C850: lwc1        $f10, 0x40($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X40);
    // 0x8057C854: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8057C858: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(387, 0X1014) << 16);
    // 0x8057C85C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8057C860: lwc1        $f6, -0x34DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(387, 0X1014));
    // 0x8057C864: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8057C868: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(387, 0XFF8) << 16);
    // 0x8057C86C: div.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8057C870: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8057C874: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8057C878: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8057C87C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8057C880: nop

    // 0x8057C884: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8057C888: swc1        $f10, 0xC4($a1)
    MEM_W(0XC4, ctx->r5) = ctx->f10.u32l;
    // 0x8057C88C: lw          $v0, -0x34F8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(387, 0XFF8));
    // 0x8057C890: sw          $v0, 0x12C($a1)
    MEM_W(0X12C, ctx->r5) = ctx->r2;
    // 0x8057C894: sw          $v0, 0x134($a1)
    MEM_W(0X134, ctx->r5) = ctx->r2;
    // 0x8057C898: sw          $v0, 0x138($a1)
    MEM_W(0X138, ctx->r5) = ctx->r2;
    // 0x8057C89C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8057C8A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8057C8A4: lhu         $t2, 0xC($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0XC);
    // 0x8057C8A8: bne         $t2, $at, L_8057C8B8
    if (ctx->r10 != ctx->r1) {
        // 0x8057C8AC: nop
    
            goto L_8057C8B8;
    }
    // 0x8057C8AC: nop

    // 0x8057C8B0: b           L_8057C8BC
    // 0x8057C8B4: sw          $zero, 0x1E4($a1)
    MEM_W(0X1E4, ctx->r5) = 0;
        goto L_8057C8BC;
    // 0x8057C8B4: sw          $zero, 0x1E4($a1)
    MEM_W(0X1E4, ctx->r5) = 0;
L_8057C8B8:
    // 0x8057C8B8: sw          $t3, 0x1E4($a1)
    MEM_W(0X1E4, ctx->r5) = ctx->r11;
L_8057C8BC:
    // 0x8057C8BC: sw          $zero, 0x24($a1)
    MEM_W(0X24, ctx->r5) = 0;
L_8057C8C0:
    // 0x8057C8C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057C8C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8057C8C8: jr          $ra
    // 0x8057C8CC: nop

    return;
    // 0x8057C8CC: nop

;}
RECOMP_FUNC void func_8079BA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079BA60: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8079BA64: lw          $t6, -0x7290($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7290);
    // 0x8079BA68: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8079BA6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079BA70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079BA74: lbu         $t7, 0x41($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X41);
    // 0x8079BA78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8079BA7C: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x8079BA80: beql        $t7, $zero, L_8079BAD8
    if (ctx->r15 == 0) {
        // 0x8079BA84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8079BAD8;
    }
    goto skip_0;
    // 0x8079BA84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8079BA88: lwc1        $f2, 0x78($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8079BA8C: add.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8079BA90: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8079BA94: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8079BA98: jal         0x8005FE48
    // 0x8079BA9C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x8079BA9C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8079BAA0: jal         0x800447C8
    // 0x8079BAA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8079BAA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8079BAA8: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8079BAAC: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x8079BAB0: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x8079BAB4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8079BAB8: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8079BABC: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8079BAC0: lw          $t9, 0x18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X18);
    // 0x8079BAC4: jalr        $t9
    // 0x8079BAC8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8079BAC8: nop

    after_2:
    // 0x8079BACC: b           L_8079BC28
    // 0x8079BAD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8079BC28;
    // 0x8079BAD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8079BAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8079BAD8:
    // 0x8079BAD8: jal         0x80049D74
    // 0x8079BADC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_80049D74(rdram, ctx);
        goto after_3;
    // 0x8079BADC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_3:
    // 0x8079BAE0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8079BAE4: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x8079BAE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079BAEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8079BAF0: jal         0x8004D150
    // 0x8079BAF4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D150(rdram, ctx);
        goto after_4;
    // 0x8079BAF4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_4:
    // 0x8079BAF8: lw          $t0, 0x1E0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1E0);
    // 0x8079BAFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8079BB00: bne         $t0, $at, L_8079BB30
    if (ctx->r8 != ctx->r1) {
        // 0x8079BB04: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8079BB30;
    }
    // 0x8079BB04: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8079BB08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8079BB0C: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8079BB10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079BB14: addiu       $a1, $zero, 0xB7
    ctx->r5 = ADD32(0, 0XB7);
    // 0x8079BB18: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8079BB1C: nop

    // 0x8079BB20: bc1fl       L_8079BB34
    if (!c1cs) {
        // 0x8079BB24: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_8079BB34;
    }
    goto skip_1;
    // 0x8079BB24: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x8079BB28: jal         0x8079B95C
    // 0x8079BB2C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    func_8079B95C(rdram, ctx);
        goto after_5;
    // 0x8079BB2C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    after_5:
L_8079BB30:
    // 0x8079BB30: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
L_8079BB34:
    // 0x8079BB34: addiu       $t1, $s0, 0xC4
    ctx->r9 = ADD32(ctx->r16, 0XC4);
    // 0x8079BB38: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8079BB3C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8079BB40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079BB44: lw          $t4, 0x40($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X40);
    // 0x8079BB48: lbu         $t5, 0x14($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X14);
    // 0x8079BB4C: beql        $t5, $zero, L_8079BC1C
    if (ctx->r13 == 0) {
        // 0x8079BB50: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8079BC1C;
    }
    goto skip_2;
    // 0x8079BB50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_2:
    // 0x8079BB54: jal         0x8079B95C
    // 0x8079BB58: addiu       $a1, $zero, 0x28B
    ctx->r5 = ADD32(0, 0X28B);
    func_8079B95C(rdram, ctx);
        goto after_6;
    // 0x8079BB58: addiu       $a1, $zero, 0x28B
    ctx->r5 = ADD32(0, 0X28B);
    after_6:
    // 0x8079BB5C: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8079BB60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8079BB64: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8079BB68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079BB6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079BB70: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8079BB74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8079BB78: jal         0x8079C140
    // 0x8079BB7C: swc1        $f8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f8.u32l;
    func_8079C140(rdram, ctx);
        goto after_7;
    // 0x8079BB7C: swc1        $f8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f8.u32l;
    after_7:
    // 0x8079BB80: jal         0x800653D8
    // 0x8079BB84: nop

    func_800653D8(rdram, ctx);
        goto after_8;
    // 0x8079BB84: nop

    after_8:
    // 0x8079BB88: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8079BB8C: beq         $t7, $zero, L_8079BBA8
    if (ctx->r15 == 0) {
        // 0x8079BB90: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_8079BBA8;
    }
    // 0x8079BB90: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8079BB94: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8079BB98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8079BB9C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8079BBA0: b           L_8079BBB4
    // 0x8079BBA4: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
        goto L_8079BBB4;
    // 0x8079BBA4: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
L_8079BBA8:
    // 0x8079BBA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8079BBAC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8079BBB0: swc1        $f16, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f16.u32l;
L_8079BBB4:
    // 0x8079BBB4: jal         0x8079B994
    // 0x8079BBB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8079B994(rdram, ctx);
        goto after_9;
    // 0x8079BBB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8079BBBC: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(829, 0XB10) << 16);
    // 0x8079BBC0: lwc1        $f18, -0x3D80($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(829, 0XB10));
    // 0x8079BBC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079BBC8: jal         0x8005FE48
    // 0x8079BBCC: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    func_8005FE48(rdram, ctx);
        goto after_10;
    // 0x8079BBCC: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    after_10:
    // 0x8079BBD0: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x8079BBD4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079BBD8: sb          $t0, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r8;
    // 0x8079BBDC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079BBE0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8079BBE4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8079BBE8: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x8079BBEC: sb          $t1, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r9;
    // 0x8079BBF0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079BBF4: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x8079BBF8: sb          $t2, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r10;
    // 0x8079BBFC: lbu         $t3, 0xF0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0XF0);
    // 0x8079BC00: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8079BC04: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x8079BC08: addiu       $t7, $t4, 0x20
    ctx->r15 = ADD32(ctx->r12, 0X20);
    // 0x8079BC0C: sb          $t7, 0xF0($v0)
    MEM_B(0XF0, ctx->r2) = ctx->r15;
    // 0x8079BC10: lw          $t8, -0x7CE8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7CE8);
    // 0x8079BC14: sb          $zero, 0xF2($t8)
    MEM_B(0XF2, ctx->r24) = 0;
    // 0x8079BC18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8079BC1C:
    // 0x8079BC1C: jal         0x8079B840
    // 0x8079BC20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8079B840(rdram, ctx);
        goto after_11;
    // 0x8079BC20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x8079BC24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079BC28:
    // 0x8079BC28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079BC2C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8079BC30: jr          $ra
    // 0x8079BC34: nop

    return;
    // 0x8079BC34: nop

;}
RECOMP_FUNC void func_80452BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452BA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452BA8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80452BAC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452BB0: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80452BB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80452BB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80452BBC: lwc1        $f4, 0x6CE0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6CE0);
    // 0x80452BC0: lui         $at, 0x43C3
    ctx->r1 = S32(0X43C3 << 16);
    // 0x80452BC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80452BC8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80452BCC: swc1        $f8, 0x6CE0($v0)
    MEM_W(0X6CE0, ctx->r2) = ctx->f8.u32l;
    // 0x80452BD0: lwc1        $f10, 0x6CE0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6CE0);
    // 0x80452BD4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80452BD8: nop

    // 0x80452BDC: bc1f        L_80452BF4
    if (!c1cs) {
        // 0x80452BE0: nop
    
            goto L_80452BF4;
    }
    // 0x80452BE0: nop

    // 0x80452BE4: jal         0x8045111C
    // 0x80452BE8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8045111C(rdram, ctx);
        goto after_0;
    // 0x80452BE8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x80452BEC: b           L_80452C00
    // 0x80452BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80452C00;
    // 0x80452BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452BF4:
    // 0x80452BF4: jal         0x80452690
    // 0x80452BF8: nop

    func_80452690(rdram, ctx);
        goto after_1;
    // 0x80452BF8: nop

    after_1:
    // 0x80452BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452C00:
    // 0x80452C00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452C04: jr          $ra
    // 0x80452C08: nop

    return;
    // 0x80452C08: nop

;}
RECOMP_FUNC void func_807AA78C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AA78C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AA790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AA794: jal         0x8004700C
    // 0x807AA798: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807AA798: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807AA79C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x807AA7A0: beq         $v0, $zero, L_807AA858
    if (ctx->r2 == 0) {
        // 0x807AA7A4: lw          $a0, 0x0($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X0);
            goto L_807AA858;
    }
    // 0x807AA7A4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x807AA7A8: lwc1        $f18, 0x84($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X84);
    // 0x807AA7AC: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807AA7B0: lwc1        $f10, 0x88($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X88);
    // 0x807AA7B4: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x807AA7B8: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x807AA7BC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x807AA7C0: jal         0x80067114
    // 0x807AA7C4: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    func_80067114(rdram, ctx);
        goto after_1;
    // 0x807AA7C4: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    after_1:
    // 0x807AA7C8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x807AA7CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807AA7D0: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x807AA7D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AA7D8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x807AA7DC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x807AA7E0: sub.s       $f14, $f2, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x807AA7E4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x807AA7E8: bc1f        L_807AA7FC
    if (!c1cs) {
        // 0x807AA7EC: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_807AA7FC;
    }
    // 0x807AA7EC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x807AA7F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807AA7F4: nop

    // 0x807AA7F8: add.s       $f12, $f14, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f18.fl;
L_807AA7FC:
    // 0x807AA7FC: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x807AA800: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x807AA804: bc1f        L_807AA82C
    if (!c1cs) {
        // 0x807AA808: nop
    
            goto L_807AA82C;
    }
    // 0x807AA808: nop

    // 0x807AA80C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807AA810: nop

    // 0x807AA814: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x807AA818: nop

    // 0x807AA81C: bc1f        L_807AA82C
    if (!c1cs) {
        // 0x807AA820: nop
    
            goto L_807AA82C;
    }
    // 0x807AA820: nop

    // 0x807AA824: b           L_807AA858
    // 0x807AA828: swc1        $f12, 0xD4($a3)
    MEM_W(0XD4, ctx->r7) = ctx->f12.u32l;
        goto L_807AA858;
    // 0x807AA828: swc1        $f12, 0xD4($a3)
    MEM_W(0XD4, ctx->r7) = ctx->f12.u32l;
L_807AA82C:
    // 0x807AA82C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C04) << 16);
    // 0x807AA830: lwc1        $f6, -0x47BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C04));
    // 0x807AA834: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x807AA838: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x807AA83C: nop

    // 0x807AA840: bc1fl       L_807AA858
    if (!c1cs) {
        // 0x807AA844: swc1        $f0, 0xD4($a3)
        MEM_W(0XD4, ctx->r7) = ctx->f0.u32l;
            goto L_807AA858;
    }
    goto skip_0;
    // 0x807AA844: swc1        $f0, 0xD4($a3)
    MEM_W(0XD4, ctx->r7) = ctx->f0.u32l;
    skip_0:
    // 0x807AA848: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807AA84C: b           L_807AA858
    // 0x807AA850: swc1        $f8, 0xD4($a3)
    MEM_W(0XD4, ctx->r7) = ctx->f8.u32l;
        goto L_807AA858;
    // 0x807AA850: swc1        $f8, 0xD4($a3)
    MEM_W(0XD4, ctx->r7) = ctx->f8.u32l;
    // 0x807AA854: swc1        $f0, 0xD4($a3)
    MEM_W(0XD4, ctx->r7) = ctx->f0.u32l;
L_807AA858:
    // 0x807AA858: addiu       $a0, $a3, 0xD0
    ctx->r4 = ADD32(ctx->r7, 0XD0);
    // 0x807AA85C: lw          $a1, 0xD4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XD4);
    // 0x807AA860: jal         0x80067170
    // 0x807AA864: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_80067170(rdram, ctx);
        goto after_2;
    // 0x807AA864: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x807AA868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AA86C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AA870: jr          $ra
    // 0x807AA874: nop

    return;
    // 0x807AA874: nop

;}
RECOMP_FUNC void func_8040BA40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040BA40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040BA44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8040BA48: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8040BA4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8040BA50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040BA54: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8040BA58: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8040BA5C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8040BA60: lbu         $t7, 0x1F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1F);
    // 0x8040BA64: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8040BA68: lui         $t1, 0x8041
    ctx->r9 = S32(RELOC_HI16(14, 0X1358) << 16);
    // 0x8040BA6C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8040BA70: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8040BA74: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8040BA78: lw          $t1, -0x4148($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(14, 0X1358));
    // 0x8040BA7C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8040BA80: jal         0x8040B590
    // 0x8040BA84: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_8040B590(rdram, ctx);
        goto after_0;
    // 0x8040BA84: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x8040BA88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040BA8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040BA90: jr          $ra
    // 0x8040BA94: nop

    return;
    // 0x8040BA94: nop

;}
RECOMP_FUNC void func_80553540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80553540: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80553544: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80553548: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8055354C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80553550: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80553554: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80553558: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8055355C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80553560: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    // 0x80553564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80553568: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8055356C: jal         0x8004D150
    // 0x80553570: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_8004D150(rdram, ctx);
        goto after_0;
    // 0x80553570: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x80553574: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80553578: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8055357C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80553580: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80553584: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80553588: lbu         $t9, 0x14($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X14);
    // 0x8055358C: beq         $t9, $zero, L_805535F0
    if (ctx->r25 == 0) {
        // 0x80553590: nop
    
            goto L_805535F0;
    }
    // 0x80553590: nop

    // 0x80553594: jal         0x8004D618
    // 0x80553598: addiu       $a2, $a2, -0x2BEC
    ctx->r6 = ADD32(ctx->r6, -0X2BEC);
    func_8004D618(rdram, ctx);
        goto after_1;
    // 0x80553598: addiu       $a2, $a2, -0x2BEC
    ctx->r6 = ADD32(ctx->r6, -0X2BEC);
    after_1:
    // 0x8055359C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x805535A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805535A4: lw          $t1, 0x40($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X40);
    // 0x805535A8: jal         0x8004A97C
    // 0x805535AC: lhu         $a0, 0x0($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X0);
    func_8004A97C(rdram, ctx);
        goto after_2;
    // 0x805535AC: lhu         $a0, 0x0($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X0);
    after_2:
    // 0x805535B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805535B4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x805535B8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x805535BC: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x805535C0: nop

    // 0x805535C4: bc1fl       L_805535D8
    if (!c1cs) {
        // 0x805535C8: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_805535D8;
    }
    goto skip_0;
    // 0x805535C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x805535CC: b           L_805535E4
    // 0x805535D0: swc1        $f0, 0xD60($t2)
    MEM_W(0XD60, ctx->r10) = ctx->f0.u32l;
        goto L_805535E4;
    // 0x805535D0: swc1        $f0, 0xD60($t2)
    MEM_W(0XD60, ctx->r10) = ctx->f0.u32l;
    // 0x805535D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_805535D8:
    // 0x805535D8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x805535DC: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x805535E0: swc1        $f8, 0xD60($t3)
    MEM_W(0XD60, ctx->r11) = ctx->f8.u32l;
L_805535E4:
    // 0x805535E4: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x805535E8: ori         $t5, $t4, 0xF000
    ctx->r13 = ctx->r12 | 0XF000;
    // 0x805535EC: sw          $t5, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r13;
L_805535F0:
    // 0x805535F0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805535F4: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x805535F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805535FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80553600: jal         0x8004D150
    // 0x80553604: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x80553604: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_3:
    // 0x80553608: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8055360C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80553610: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80553614: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x80553618: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8055361C: lbu         $t8, 0x5C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X5C);
    // 0x80553620: beql        $t8, $zero, L_80553658
    if (ctx->r24 == 0) {
        // 0x80553624: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80553658;
    }
    goto skip_1;
    // 0x80553624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80553628: jal         0x8004D618
    // 0x8055362C: addiu       $a2, $a2, -0x2A94
    ctx->r6 = ADD32(ctx->r6, -0X2A94);
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x8055362C: addiu       $a2, $a2, -0x2A94
    ctx->r6 = ADD32(ctx->r6, -0X2A94);
    after_4:
    // 0x80553630: jal         0x805538DC
    // 0x80553634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805538DC(rdram, ctx);
        goto after_5;
    // 0x80553634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80553638: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8055363C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80553640: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80553644: swc1        $f10, 0xD60($t9)
    MEM_W(0XD60, ctx->r25) = ctx->f10.u32l;
    // 0x80553648: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8055364C: ori         $t1, $t0, 0xF
    ctx->r9 = ctx->r8 | 0XF;
    // 0x80553650: sw          $t1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r9;
    // 0x80553654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80553658:
    // 0x80553658: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8055365C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80553660: jr          $ra
    // 0x80553664: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80553664: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80029CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029CFC: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80029D00: lbu         $v0, 0x12E8($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X12E8);
    // 0x80029D04: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x80029D08: bnel        $at, $zero, L_80029D18
    if (ctx->r1 != 0) {
        // 0x80029D0C: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80029D18;
    }
    goto skip_0;
    // 0x80029D0C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    skip_0:
    // 0x80029D10: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80029D14: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
L_80029D18:
    // 0x80029D18: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80029D1C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80029D20: lwc1        $f0, -0x214C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X214C);
    // 0x80029D24: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80029D28: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80029D2C: nop

    // 0x80029D30: bc1fl       L_80029D60
    if (!c1cs) {
        // 0x80029D34: lw          $t1, 0x4($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X4);
            goto L_80029D60;
    }
    goto skip_1;
    // 0x80029D34: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x80029D38: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80029D3C: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80029D40: lhu         $t9, 0x64($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X64);
    // 0x80029D44: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80029D48: bne         $t0, $zero, L_80029D7C
    if (ctx->r8 != 0) {
        // 0x80029D4C: nop
    
            goto L_80029D7C;
    }
    // 0x80029D4C: nop

    // 0x80029D50: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80029D54: jr          $ra
    // 0x80029D58: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80029D58: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x80029D5C: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
L_80029D60:
    // 0x80029D60: lhu         $t2, 0x64($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X64);
    // 0x80029D64: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80029D68: bne         $t3, $zero, L_80029D7C
    if (ctx->r11 != 0) {
        // 0x80029D6C: nop
    
            goto L_80029D7C;
    }
    // 0x80029D6C: nop

    // 0x80029D70: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80029D74: nop

    // 0x80029D78: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
L_80029D7C:
    // 0x80029D7C: jr          $ra
    // 0x80029D80: nop

    return;
    // 0x80029D80: nop

;}
RECOMP_FUNC void func_8069F40C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069F40C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8069F410: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8069F414: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8069F418: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8069F41C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8069F420: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8069F424: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8069F428: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5EC) << 16);
    // 0x8069F42C: lwc1        $f6, -0xAA4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5EC));
    // 0x8069F430: lwc1        $f4, 0x8C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8C);
    // 0x8069F434: lw          $a3, 0x88($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X88);
    // 0x8069F438: lw          $a2, 0x84($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X84);
    // 0x8069F43C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8069F440: lui         $a1, 0x40E9
    ctx->r5 = S32(0X40E9 << 16);
    // 0x8069F444: lui         $a0, 0x806A
    ctx->r4 = S32(RELOC_HI16(580, 0X6E0) << 16);
    // 0x8069F448: addiu       $a0, $a0, -0x9B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(580, 0X6E0));
    // 0x8069F44C: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x8069F450: jal         0x80046804
    // 0x8069F454: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x8069F454: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8069F458: bne         $v0, $zero, L_8069F468
    if (ctx->r2 != 0) {
        // 0x8069F45C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8069F468;
    }
    // 0x8069F45C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8069F460: b           L_8069F4DC
    // 0x8069F464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8069F4DC;
    // 0x8069F464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8069F468:
    // 0x8069F468: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x8069F46C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069F470: bnel        $t6, $zero, L_8069F49C
    if (ctx->r14 != 0) {
        // 0x8069F474: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8069F49C;
    }
    goto skip_0;
    // 0x8069F474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8069F478: jal         0x80045A34
    // 0x8069F47C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x8069F47C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_1:
    // 0x8069F480: bne         $v0, $zero, L_8069F498
    if (ctx->r2 != 0) {
        // 0x8069F484: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_8069F498;
    }
    // 0x8069F484: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8069F488: jal         0x800445A4
    // 0x8069F48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x8069F48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8069F490: b           L_8069F4DC
    // 0x8069F494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8069F4DC;
    // 0x8069F494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8069F498:
    // 0x8069F498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8069F49C:
    // 0x8069F49C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8069F4A0: jal         0x8069F3EC
    // 0x8069F4A4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_8069F3EC(rdram, ctx);
        goto after_3;
    // 0x8069F4A4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8069F4A8: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5F0) << 16);
    // 0x8069F4AC: lwc1        $f16, -0xAA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5F0));
    // 0x8069F4B0: lwc1        $f10, 0x6C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8069F4B4: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5F4) << 16);
    // 0x8069F4B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069F4BC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8069F4C0: swc1        $f18, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f18.u32l;
    // 0x8069F4C4: lwc1        $f6, -0xA9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5F4));
    // 0x8069F4C8: lwc1        $f4, 0x70($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8069F4CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8069F4D0: jal         0x80044194
    // 0x8069F4D4: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    func_80044194(rdram, ctx);
        goto after_4;
    // 0x8069F4D4: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x8069F4D8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8069F4DC:
    // 0x8069F4DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8069F4E0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8069F4E4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8069F4E8: jr          $ra
    // 0x8069F4EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8069F4EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80002FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002FF0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80002FF4: addiu       $a1, $a1, 0x4D10
    ctx->r5 = ADD32(ctx->r5, 0X4D10);
    // 0x80002FF8: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80002FFC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80003000: lwc1        $f4, 0x1D9C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x80003004: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80003008: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000300C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80003010: lw          $t6, 0x2A28($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2A28);
    // 0x80003014: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80003018: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8000301C: addiu       $v1, $zero, 0x200
    ctx->r3 = ADD32(0, 0X200);
    // 0x80003020: addiu       $a0, $zero, 0xFB
    ctx->r4 = ADD32(0, 0XFB);
    // 0x80003024: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80003028: swc1        $f10, 0x3FC($t6)
    MEM_W(0X3FC, ctx->r14) = ctx->f10.u32l;
    // 0x8000302C: lwc1        $f16, 0x1D9C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x80003030: lwc1        $f4, -0x4420($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4420);
    // 0x80003034: lw          $t7, 0x2A28($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X2A28);
    // 0x80003038: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8000303C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80003040: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80003044: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80003048: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000304C: swc1        $f6, 0x3F8($t7)
    MEM_W(0X3F8, ctx->r15) = ctx->f6.u32l;
    // 0x80003050: lwc1        $f8, 0x1D9C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x80003054: lw          $t8, 0x2A28($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X2A28);
    // 0x80003058: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x8000305C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80003060: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80003064: swc1        $f18, 0x3F4($t8)
    MEM_W(0X3F4, ctx->r24) = ctx->f18.u32l;
    // 0x80003068: lwc1        $f4, 0x1D9C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x8000306C: lwc1        $f8, -0x441C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X441C);
    // 0x80003070: lw          $t9, 0x2A28($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X2A28);
    // 0x80003074: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80003078: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8000307C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80003080: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80003084: swc1        $f10, 0x3F0($t9)
    MEM_W(0X3F0, ctx->r25) = ctx->f10.u32l;
    // 0x80003088: lwc1        $f16, 0x1D9C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x8000308C: lw          $t0, 0x2A28($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X2A28);
    // 0x80003090: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80003094: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80003098: swc1        $f6, 0x3EC($t0)
    MEM_W(0X3EC, ctx->r8) = ctx->f6.u32l;
L_8000309C:
    // 0x8000309C: lwc1        $f8, 0x1D9C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x800030A0: subu        $t1, $a0, $v0
    ctx->r9 = SUB32(ctx->r4, ctx->r2);
    // 0x800030A4: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800030A8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800030AC: lw          $t2, 0x2A28($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X2A28);
    // 0x800030B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800030B4: slti        $at, $v0, 0xFB
    ctx->r1 = SIGNED(ctx->r2) < 0XFB ? 1 : 0;
    // 0x800030B8: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x800030BC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800030C0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800030C4: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800030C8: bne         $at, $zero, L_8000309C
    if (ctx->r1 != 0) {
        // 0x800030CC: swc1        $f4, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
            goto L_8000309C;
    }
    // 0x800030CC: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x800030D0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800030D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800030D8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800030DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800030E0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800030E4: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
    // 0x800030E8: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
L_800030EC:
    // 0x800030EC: subu        $t4, $a0, $v0
    ctx->r12 = SUB32(ctx->r4, ctx->r2);
    // 0x800030F0: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800030F4: lwc1        $f6, 0x1D9C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x800030F8: lw          $t5, 0x2A28($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X2A28);
    // 0x800030FC: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80003100: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80003104: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80003108: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x8000310C: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x80003110: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80003114: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80003118: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x8000311C: div.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80003120: bne         $at, $zero, L_800030EC
    if (ctx->r1 != 0) {
        // 0x80003124: swc1        $f6, 0x0($t6)
        MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
            goto L_800030EC;
    }
    // 0x80003124: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80003128: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8000312C: lwc1        $f16, 0x1D9C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x80003130: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x80003134: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80003138: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8000313C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80003140: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80003144: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80003148: lw          $t8, 0x2A28($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X2A28);
    // 0x8000314C: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
    // 0x80003150: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80003154: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80003158: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8000315C: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x80003160: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80003164: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80003168: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8000316C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80003170: div.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80003174: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80003178: swc1        $f16, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f16.u32l;
    // 0x8000317C: lwc1        $f18, 0x1D9C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x80003180: lw          $t0, 0x2A28($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X2A28);
    // 0x80003184: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80003188: nop

    // 0x8000318C: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80003190: add.s       $f16, $f2, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80003194: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80003198: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000319C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800031A0: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    // 0x800031A4: lwc1        $f4, 0x1D9C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x800031A8: lw          $t2, 0x2A28($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X2A28);
    // 0x800031AC: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800031B0: nop

    // 0x800031B4: mul.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800031B8: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x800031BC: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800031C0: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    // 0x800031C4: subu        $a0, $a2, $v0
    ctx->r4 = SUB32(ctx->r6, ctx->r2);
    // 0x800031C8: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800031CC: lwc1        $f6, 0x1D9C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x800031D0: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x800031D4: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800031D8: mul.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800031DC: add.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800031E0: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800031E4: beql        $v0, $a3, L_800032B0
    if (ctx->r2 == ctx->r7) {
        // 0x800031E8: div.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
            goto L_800032B0;
    }
    goto skip_0;
    // 0x800031E8: div.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    skip_0:
    // 0x800031EC: div.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
L_800031F0:
    // 0x800031F0: lw          $t3, 0x2A28($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X2A28);
    // 0x800031F4: addiu       $t5, $a0, -0x1
    ctx->r13 = ADD32(ctx->r4, -0X1);
    // 0x800031F8: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800031FC: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x80003200: addiu       $t8, $a0, -0x2
    ctx->r24 = ADD32(ctx->r4, -0X2);
    // 0x80003204: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80003208: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8000320C: addiu       $t1, $a0, -0x3
    ctx->r9 = ADD32(ctx->r4, -0X3);
    // 0x80003210: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80003214: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80003218: subu        $a0, $a2, $v0
    ctx->r4 = SUB32(ctx->r6, ctx->r2);
    // 0x8000321C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80003220: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80003224: swc1        $f14, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f14.u32l;
    // 0x80003228: lwc1        $f14, 0x1D9C($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x8000322C: lw          $t6, 0x2A28($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2A28);
    // 0x80003230: mul.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80003234: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80003238: add.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8000323C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80003240: div.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80003244: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80003248: add.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8000324C: swc1        $f10, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f10.u32l;
    // 0x80003250: lwc1        $f10, 0x1D9C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x80003254: lw          $t9, 0x2A28($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X2A28);
    // 0x80003258: mul.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8000325C: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80003260: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80003264: div.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80003268: mul.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8000326C: add.s       $f6, $f2, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80003270: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x80003274: lwc1        $f8, 0x1D9C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x80003278: lw          $t2, 0x2A28($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X2A28);
    // 0x8000327C: mul.s       $f8, $f0, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80003280: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80003284: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80003288: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000328C: div.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80003290: mul.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80003294: add.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80003298: swc1        $f6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f6.u32l;
    // 0x8000329C: lwc1        $f6, 0x1D9C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x800032A0: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800032A4: bnel        $v0, $a3, L_800031F0
    if (ctx->r2 != ctx->r7) {
        // 0x800032A8: div.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
            goto L_800031F0;
    }
    goto skip_1;
    // 0x800032A8: div.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    skip_1:
    // 0x800032AC: div.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
L_800032B0:
    // 0x800032B0: addiu       $t5, $a0, -0x1
    ctx->r13 = ADD32(ctx->r4, -0X1);
    // 0x800032B4: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800032B8: lw          $t3, 0x2A28($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X2A28);
    // 0x800032BC: addiu       $t8, $a0, -0x2
    ctx->r24 = ADD32(ctx->r4, -0X2);
    // 0x800032C0: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800032C4: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x800032C8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800032CC: addiu       $t1, $a0, -0x3
    ctx->r9 = ADD32(ctx->r4, -0X3);
    // 0x800032D0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800032D4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800032D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800032DC: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800032E0: swc1        $f14, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f14.u32l;
    // 0x800032E4: lwc1        $f14, 0x1D9C($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x800032E8: lw          $t6, 0x2A28($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2A28);
    // 0x800032EC: mul.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800032F0: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800032F4: add.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x800032F8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800032FC: div.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80003300: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80003304: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80003308: add.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8000330C: swc1        $f10, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f10.u32l;
    // 0x80003310: lwc1        $f10, 0x1D9C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x80003314: lw          $t9, 0x2A28($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X2A28);
    // 0x80003318: mul.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8000331C: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80003320: mul.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80003324: div.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80003328: add.s       $f6, $f2, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8000332C: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x80003330: lwc1        $f8, 0x1D9C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1D9C);
    // 0x80003334: lw          $t2, 0x2A28($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X2A28);
    // 0x80003338: mul.s       $f8, $f0, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8000333C: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80003340: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80003344: div.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80003348: swc1        $f6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f6.u32l;
    // 0x8000334C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80003350: lw          $t4, 0x2A28($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X2A28);
    // 0x80003354: jr          $ra
    // 0x80003358: swc1        $f6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f6.u32l;
    return;
    // 0x80003358: swc1        $f6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80799554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799554: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80799558: jr          $ra
    // 0x8079955C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    return;
    // 0x8079955C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void func_804A0214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A0214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A0218: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804A021C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804A0220: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804A0224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A0228: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804A022C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804A0230: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804A0234: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804A0238: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804A023C: lui         $t2, 0x804A
    ctx->r10 = S32(RELOC_HI16(170, 0X2E8) << 16);
    // 0x804A0240: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804A0244: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804A0248: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804A024C: lw          $t2, 0x348($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(170, 0X2E8));
    // 0x804A0250: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804A0254: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804A0258: jal         0x804A0278
    // 0x804A025C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A0278(rdram, ctx);
        goto after_0;
    // 0x804A025C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A0260: jal         0x804A02C4
    // 0x804A0264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804A02C4(rdram, ctx);
        goto after_1;
    // 0x804A0264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804A0268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A026C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A0270: jr          $ra
    // 0x804A0274: nop

    return;
    // 0x804A0274: nop

;}
RECOMP_FUNC void func_8043E814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E814: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043E818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E81C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8043E820: jal         0x80045A34
    // 0x8043E824: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8043E824: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x8043E828: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8043E82C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8043E830: bne         $v0, $zero, L_8043E840
    if (ctx->r2 != 0) {
        // 0x8043E834: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_8043E840;
    }
    // 0x8043E834: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x8043E838: b           L_8043E860
    // 0x8043E83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8043E860;
    // 0x8043E83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043E840:
    // 0x8043E840: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x8043E844: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8043E848: jal         0x80065728
    // 0x8043E84C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x8043E84C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8043E850: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8043E854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8043E858: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x8043E85C: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
L_8043E860:
    // 0x8043E860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043E864: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043E868: jr          $ra
    // 0x8043E86C: nop

    return;
    // 0x8043E86C: nop

;}
RECOMP_FUNC void func_807A9B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A9B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A9B54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A9B58: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x807A9B5C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807A9B60: lui         $t7, 0x807B
    ctx->r15 = S32(RELOC_HI16(850, 0XB0) << 16);
    // 0x807A9B64: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x807A9B68: addiu       $t7, $t7, -0x6410
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(850, 0XB0));
    // 0x807A9B6C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x807A9B70: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807A9B74: sw          $t9, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r25;
    // 0x807A9B78: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807A9B7C: jal         0x807A9BC0
    // 0x807A9B80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807A9BC0(rdram, ctx);
        goto after_0;
    // 0x807A9B80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x807A9B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A9B88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807A9B8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807A9B90: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x807A9B94: jr          $ra
    // 0x807A9B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x807A9B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001CBDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CBDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001CBE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CBE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001CBE8: jal         0x80045A34
    // 0x8001CBEC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8001CBEC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x8001CBF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001CBF4: bne         $v0, $zero, L_8001CC0C
    if (ctx->r2 != 0) {
        // 0x8001CBF8: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8001CC0C;
    }
    // 0x8001CBF8: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8001CBFC: jal         0x800445A4
    // 0x8001CC00: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8001CC00: nop

    after_1:
    // 0x8001CC04: b           L_8001CC10
    // 0x8001CC08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CC10;
    // 0x8001CC08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001CC0C:
    // 0x8001CC0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001CC10:
    // 0x8001CC10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CC14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001CC18: jr          $ra
    // 0x8001CC1C: nop

    return;
    // 0x8001CC1C: nop

;}
RECOMP_FUNC void func_806717F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806717F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806717F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806717F8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x806717FC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80671800: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80671804: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80671808: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067180C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80671810: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80671814: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80671818: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x8067181C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80671820: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80671824: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80671828: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x8067182C: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x80671830: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80671834: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80671838: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x8067183C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80671840: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x80671844: jal         0x8005C27C
    // 0x80671848: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x80671848: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x8067184C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80671850: bne         $at, $zero, L_80671868
    if (ctx->r1 != 0) {
        // 0x80671854: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_80671868;
    }
    // 0x80671854: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80671858: lw          $t1, 0x1F4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X1F4);
    // 0x8067185C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80671860: b           L_80671938
    // 0x80671864: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
        goto L_80671938;
    // 0x80671864: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_80671868:
    // 0x80671868: addiu       $t0, $s0, 0x1
    ctx->r8 = ADD32(ctx->r16, 0X1);
    // 0x8067186C: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80671870: beq         $at, $zero, L_806718E0
    if (ctx->r1 == 0) {
        // 0x80671874: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_806718E0;
    }
    // 0x80671874: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80671878: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8067187C: subu        $a3, $a2, $a0
    ctx->r7 = SUB32(ctx->r6, ctx->r4);
    // 0x80671880: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x80671884: beq         $a3, $zero, L_806718AC
    if (ctx->r7 == 0) {
        // 0x80671888: addu        $a1, $a3, $a0
        ctx->r5 = ADD32(ctx->r7, ctx->r4);
            goto L_806718AC;
    }
    // 0x80671888: addu        $a1, $a3, $a0
    ctx->r5 = ADD32(ctx->r7, ctx->r4);
    // 0x8067188C: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80671890: addu        $v0, $s1, $t2
    ctx->r2 = ADD32(ctx->r17, ctx->r10);
L_80671894:
    // 0x80671894: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80671898: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8067189C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x806718A0: bne         $a1, $a0, L_80671894
    if (ctx->r5 != ctx->r4) {
        // 0x806718A4: addu        $v1, $v1, $t3
        ctx->r3 = ADD32(ctx->r3, ctx->r11);
            goto L_80671894;
    }
    // 0x806718A4: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x806718A8: beq         $a0, $a2, L_806718E0
    if (ctx->r4 == ctx->r6) {
        // 0x806718AC: sll         $t4, $a0, 2
        ctx->r12 = S32(ctx->r4 << 2);
            goto L_806718E0;
    }
L_806718AC:
    // 0x806718AC: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x806718B0: addu        $v0, $s1, $t4
    ctx->r2 = ADD32(ctx->r17, ctx->r12);
L_806718B4:
    // 0x806718B4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x806718B8: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x806718BC: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x806718C0: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
    // 0x806718C4: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x806718C8: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x806718CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x806718D0: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x806718D4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x806718D8: bne         $a0, $a2, L_806718B4
    if (ctx->r4 != ctx->r6) {
        // 0x806718DC: addu        $v1, $v1, $t8
        ctx->r3 = ADD32(ctx->r3, ctx->r24);
            goto L_806718B4;
    }
    // 0x806718DC: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
L_806718E0:
    // 0x806718E0: beq         $v1, $zero, L_806718F8
    if (ctx->r3 == 0) {
        // 0x806718E4: slti        $at, $t0, 0x4
        ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
            goto L_806718F8;
    }
    // 0x806718E4: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x806718E8: lw          $t9, 0x1F4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X1F4);
    // 0x806718EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806718F0: b           L_80671938
    // 0x806718F4: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
        goto L_80671938;
    // 0x806718F4: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_806718F8:
    // 0x806718F8: beq         $at, $zero, L_8067192C
    if (ctx->r1 == 0) {
        // 0x806718FC: negu        $s0, $t0
        ctx->r16 = SUB32(0, ctx->r8);
            goto L_8067192C;
    }
    // 0x806718FC: negu        $s0, $t0
    ctx->r16 = SUB32(0, ctx->r8);
    // 0x80671900: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x80671904: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80671908: addiu       $s1, $zero, -0x8
    ctx->r17 = ADD32(0, -0X8);
    // 0x8067190C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80671910:
    // 0x80671910: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80671914: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80671918: jal         0x8005C27C
    // 0x8067191C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x8067191C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_1:
    // 0x80671920: addiu       $s0, $s0, -0x8
    ctx->r16 = ADD32(ctx->r16, -0X8);
    // 0x80671924: bnel        $s1, $s0, L_80671910
    if (ctx->r17 != ctx->r16) {
        // 0x80671928: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80671910;
    }
    goto skip_0;
    // 0x80671928: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_8067192C:
    // 0x8067192C: lw          $t1, 0x1F4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X1F4);
    // 0x80671930: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80671934: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_80671938:
    // 0x80671938: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8067193C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80671940: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80671944: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80671948: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8067194C: jr          $ra
    // 0x80671950: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80671950: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_806E3BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E3BD4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806E3BD8: lw          $t6, -0x7294($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7294);
    // 0x806E3BDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806E3BE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E3BE4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806E3BE8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E3BEC: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x806E3BF0: beq         $t7, $zero, L_806E3CB0
    if (ctx->r15 == 0) {
        // 0x806E3BF4: addiu       $a2, $zero, 0x172
        ctx->r6 = ADD32(0, 0X172);
            goto L_806E3CB0;
    }
    // 0x806E3BF4: addiu       $a2, $zero, 0x172
    ctx->r6 = ADD32(0, 0X172);
    // 0x806E3BF8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x806E3BFC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x806E3C00: jal         0x80047534
    // 0x806E3C04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80047534(rdram, ctx);
        goto after_0;
    // 0x806E3C04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x806E3C08: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x806E3C0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x806E3C10: bne         $v0, $zero, L_806E3C34
    if (ctx->r2 != 0) {
        // 0x806E3C14: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_806E3C34;
    }
    // 0x806E3C14: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806E3C18: addiu       $a2, $zero, -0x32
    ctx->r6 = ADD32(0, -0X32);
    // 0x806E3C1C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x806E3C20: jal         0x800474D8
    // 0x806E3C24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800474D8(rdram, ctx);
        goto after_1;
    // 0x806E3C24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x806E3C28: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x806E3C2C: beq         $v0, $zero, L_806E3C80
    if (ctx->r2 == 0) {
        // 0x806E3C30: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_806E3C80;
    }
    // 0x806E3C30: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_806E3C34:
    // 0x806E3C34: lw          $t8, 0x58($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X58);
    // 0x806E3C38: bnel        $t8, $zero, L_806E3CB4
    if (ctx->r24 != 0) {
        // 0x806E3C3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E3CB4;
    }
    goto skip_0;
    // 0x806E3C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E3C40: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806E3C44: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806E3C48: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806E3C4C: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x806E3C50: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x806E3C54: swc1        $f6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f6.u32l;
    // 0x806E3C58: lwc1        $f8, 0x18($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X18);
    // 0x806E3C5C: swc1        $f8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f8.u32l;
    // 0x806E3C60: lwc1        $f10, 0x1C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x806E3C64: swc1        $f10, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f10.u32l;
    // 0x806E3C68: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x806E3C6C: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x806E3C70: swc1        $f0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f0.u32l;
    // 0x806E3C74: swc1        $f0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f0.u32l;
    // 0x806E3C78: b           L_806E3CB0
    // 0x806E3C7C: sw          $t9, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r25;
        goto L_806E3CB0;
    // 0x806E3C7C: sw          $t9, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r25;
L_806E3C80:
    // 0x806E3C80: lw          $t0, 0x58($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X58);
    // 0x806E3C84: beql        $t0, $zero, L_806E3CB4
    if (ctx->r8 == 0) {
        // 0x806E3C88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E3CB4;
    }
    goto skip_1;
    // 0x806E3C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806E3C8C: lwc1        $f16, 0x1C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x806E3C90: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x806E3C94: lwc1        $f18, 0x20($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X20);
    // 0x806E3C98: swc1        $f18, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f18.u32l;
    // 0x806E3C9C: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
    // 0x806E3CA0: swc1        $f4, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f4.u32l;
    // 0x806E3CA4: lwc1        $f6, 0x28($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X28);
    // 0x806E3CA8: swc1        $f6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f6.u32l;
    // 0x806E3CAC: sw          $zero, 0x58($v1)
    MEM_W(0X58, ctx->r3) = 0;
L_806E3CB0:
    // 0x806E3CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E3CB4:
    // 0x806E3CB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806E3CB8: jr          $ra
    // 0x806E3CBC: nop

    return;
    // 0x806E3CBC: nop

;}
RECOMP_FUNC void func_804C1834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1834: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x804C1838: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C183C: lui         $a2, 0x804C
    ctx->r6 = S32(RELOC_HI16(203, 0XE00) << 16);
    // 0x804C1840: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804C1844: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x804C1848: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x804C184C: addiu       $a2, $a2, 0x2570
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(203, 0XE00));
    // 0x804C1850: addiu       $v0, $a0, 0x14C
    ctx->r2 = ADD32(ctx->r4, 0X14C);
    // 0x804C1854: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x804C1858: addu        $t1, $a2, $t0
    ctx->r9 = ADD32(ctx->r6, ctx->r8);
    // 0x804C185C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x804C1860: sltu        $at, $t7, $t2
    ctx->r1 = ctx->r15 < ctx->r10 ? 1 : 0;
    // 0x804C1864: bnel        $at, $zero, L_804C18A8
    if (ctx->r1 != 0) {
        // 0x804C1868: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804C18A8;
    }
    goto skip_0;
    // 0x804C1868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x804C186C: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x804C1870: lh          $t3, 0x4($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X4);
    // 0x804C1874: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x804C1878: sh          $t4, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r12;
    // 0x804C187C: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x804C1880: slti        $at, $a1, 0xE
    ctx->r1 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
    // 0x804C1884: bne         $at, $zero, L_804C1898
    if (ctx->r1 != 0) {
        // 0x804C1888: sll         $t5, $a1, 3
        ctx->r13 = S32(ctx->r5 << 3);
            goto L_804C1898;
    }
    // 0x804C1888: sll         $t5, $a1, 3
    ctx->r13 = S32(ctx->r5 << 3);
    // 0x804C188C: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x804C1890: jr          $ra
    // 0x804C1894: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x804C1894: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_804C1898:
    // 0x804C1898: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x804C189C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x804C18A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804C18A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C18A8:
    // 0x804C18A8: jr          $ra
    // 0x804C18AC: nop

    return;
    // 0x804C18AC: nop

;}
RECOMP_FUNC void func_804358AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804358AC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x804358B0: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x804358B4: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x804358B8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804358BC: lui         $at, 0x4368
    ctx->r1 = S32(0X4368 << 16);
    // 0x804358C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804358C4: lw          $v1, 0xE80($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XE80);
    // 0x804358C8: lui         $at, 0x439C
    ctx->r1 = S32(0X439C << 16);
    // 0x804358CC: lui         $s1, 0x1000
    ctx->r17 = S32(0X1000 << 16);
    // 0x804358D0: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x804358D4: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x804358D8: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x804358DC: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x804358E0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x804358E4: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x804358E8: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x804358EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x804358F0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x804358F4: ori         $s1, $s1, 0x400
    ctx->r17 = ctx->r17 | 0X400;
    // 0x804358F8: lui         $s0, 0xB300
    ctx->r16 = S32(0XB300 << 16);
    // 0x804358FC: addiu       $a3, $zero, 0x3B
    ctx->r7 = ADD32(0, 0X3B);
    // 0x80435900: lui         $t5, 0xB400
    ctx->r13 = S32(0XB400 << 16);
    // 0x80435904: lui         $t4, 0xE400
    ctx->r12 = S32(0XE400 << 16);
    // 0x80435908: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    // 0x8043590C: addiu       $a2, $v0, 0xE8C
    ctx->r6 = ADD32(ctx->r2, 0XE8C);
    // 0x80435910: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
L_80435914:
    // 0x80435914: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80435918: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8043591C: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x80435920: nop

    // 0x80435924: bc1fl       L_80435AE8
    if (!c1cs) {
        // 0x80435928: addiu       $a3, $a3, -0x1
        ctx->r7 = ADD32(ctx->r7, -0X1);
            goto L_80435AE8;
    }
    goto skip_0;
    // 0x80435928: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    skip_0:
    // 0x8043592C: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x80435930: nop

    // 0x80435934: bc1fl       L_80435AE8
    if (!c1cs) {
        // 0x80435938: addiu       $a3, $a3, -0x1
        ctx->r7 = ADD32(ctx->r7, -0X1);
            goto L_80435AE8;
    }
    goto skip_1;
    // 0x80435938: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    skip_1:
    // 0x8043593C: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80435940: nop

    // 0x80435944: bc1fl       L_80435AE8
    if (!c1cs) {
        // 0x80435948: addiu       $a3, $a3, -0x1
        ctx->r7 = ADD32(ctx->r7, -0X1);
            goto L_80435AE8;
    }
    goto skip_2;
    // 0x80435948: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    skip_2:
    // 0x8043594C: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x80435950: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80435954: bc1fl       L_80435AE8
    if (!c1cs) {
        // 0x80435958: addiu       $a3, $a3, -0x1
        ctx->r7 = ADD32(ctx->r7, -0X1);
            goto L_80435AE8;
    }
    goto skip_3;
    // 0x80435958: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    skip_3:
    // 0x8043595C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80435960: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80435964: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x80435968: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8043596C: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80435970: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x80435974: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80435978: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8043597C: nop

    // 0x80435980: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80435984: beql        $a0, $zero, L_804359D4
    if (ctx->r4 == 0) {
        // 0x80435988: mfc1        $a0, $f4
        ctx->r4 = (int32_t)ctx->f4.u32l;
            goto L_804359D4;
    }
    goto skip_4;
    // 0x80435988: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    skip_4:
    // 0x8043598C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80435990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80435994: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80435998: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8043599C: nop

    // 0x804359A0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x804359A4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x804359A8: nop

    // 0x804359AC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x804359B0: bne         $a0, $zero, L_804359C8
    if (ctx->r4 != 0) {
        // 0x804359B4: nop
    
            goto L_804359C8;
    }
    // 0x804359B4: nop

    // 0x804359B8: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x804359BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804359C0: b           L_804359E0
    // 0x804359C4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_804359E0;
    // 0x804359C4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_804359C8:
    // 0x804359C8: b           L_804359E0
    // 0x804359CC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_804359E0;
    // 0x804359CC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x804359D0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
L_804359D4:
    // 0x804359D4: nop

    // 0x804359D8: bltz        $a0, L_804359C8
    if (SIGNED(ctx->r4) < 0) {
        // 0x804359DC: nop
    
            goto L_804359C8;
    }
    // 0x804359DC: nop

L_804359E0:
    // 0x804359E0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x804359E4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804359E8: addiu       $t9, $a0, 0x7
    ctx->r25 = ADD32(ctx->r4, 0X7);
    // 0x804359EC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x804359F0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x804359F4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x804359F8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x804359FC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80435A00: cvt.w.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80435A04: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80435A08: nop

    // 0x80435A0C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80435A10: beql        $t0, $zero, L_80435A60
    if (ctx->r8 == 0) {
        // 0x80435A14: mfc1        $t0, $f6
        ctx->r8 = (int32_t)ctx->f6.u32l;
            goto L_80435A60;
    }
    goto skip_5;
    // 0x80435A14: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    skip_5:
    // 0x80435A18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80435A1C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80435A20: sub.s       $f6, $f2, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80435A24: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80435A28: nop

    // 0x80435A2C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80435A30: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80435A34: nop

    // 0x80435A38: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80435A3C: bne         $t0, $zero, L_80435A54
    if (ctx->r8 != 0) {
        // 0x80435A40: nop
    
            goto L_80435A54;
    }
    // 0x80435A40: nop

    // 0x80435A44: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80435A48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80435A4C: b           L_80435A6C
    // 0x80435A50: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80435A6C;
    // 0x80435A50: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80435A54:
    // 0x80435A54: b           L_80435A6C
    // 0x80435A58: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80435A6C;
    // 0x80435A58: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80435A5C: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
L_80435A60:
    // 0x80435A60: nop

    // 0x80435A64: bltz        $t0, L_80435A54
    if (SIGNED(ctx->r8) < 0) {
        // 0x80435A68: nop
    
            goto L_80435A54;
    }
    // 0x80435A68: nop

L_80435A6C:
    // 0x80435A6C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80435A70: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80435A74: addiu       $t6, $t0, 0x7
    ctx->r14 = ADD32(ctx->r8, 0X7);
    // 0x80435A78: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80435A7C: or          $t9, $t8, $t4
    ctx->r25 = ctx->r24 | ctx->r12;
    // 0x80435A80: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80435A84: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80435A88: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80435A8C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80435A90: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80435A94: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80435A98: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80435A9C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80435AA0: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80435AA4: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80435AA8: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80435AAC: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x80435AB0: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x80435AB4: lw          $t7, 0x125C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X125C);
    // 0x80435AB8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80435ABC: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x80435AC0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80435AC4: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x80435AC8: lw          $t7, 0x124C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X124C);
    // 0x80435ACC: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80435AD0: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x80435AD4: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80435AD8: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x80435ADC: sw          $s1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r17;
    // 0x80435AE0: sw          $s0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r16;
    // 0x80435AE4: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
L_80435AE8:
    // 0x80435AE8: bgezl       $a3, L_80435914
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80435AEC: lwc1        $f0, 0x0($a2)
        ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
            goto L_80435914;
    }
    goto skip_6;
    // 0x80435AEC: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    skip_6:
    // 0x80435AF0: lui         $t8, 0xB800
    ctx->r24 = S32(0XB800 << 16);
    // 0x80435AF4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80435AF8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80435AFC: sw          $v1, 0xE80($v0)
    MEM_W(0XE80, ctx->r2) = ctx->r3;
    // 0x80435B00: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80435B04: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80435B08: jr          $ra
    // 0x80435B0C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80435B0C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8006CCB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CCB4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006CCB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CCBC: lwc1        $f6, 0x84($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X84);
    // 0x8006CCC0: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
    // 0x8006CCC4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8006CCC8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8006CCCC: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8006CCD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006CCD4: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8006CCD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006CCDC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8006CCE0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8006CCE4: bc1fl       L_8006CCF4
    if (!c1cs) {
        // 0x8006CCE8: lwc1        $f8, 0x88($a1)
        ctx->f8.u32l = MEM_W(ctx->r5, 0X88);
            goto L_8006CCF4;
    }
    goto skip_0;
    // 0x8006CCE8: lwc1        $f8, 0x88($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X88);
    skip_0:
    // 0x8006CCEC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8006CCF0: lwc1        $f8, 0x88($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X88);
L_8006CCF4:
    // 0x8006CCF4: lwc1        $f10, 0x88($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X88);
    // 0x8006CCF8: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8006CCFC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8006CD00: nop

    // 0x8006CD04: bc1fl       L_8006CD14
    if (!c1cs) {
        // 0x8006CD08: add.s       $f0, $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
            goto L_8006CD14;
    }
    goto skip_1;
    // 0x8006CD08: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
    skip_1:
    // 0x8006CD0C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8006CD10: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
L_8006CD14:
    // 0x8006CD14: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8006CD18: nop

    // 0x8006CD1C: bc1f        L_8006CD28
    if (!c1cs) {
        // 0x8006CD20: nop
    
            goto L_8006CD28;
    }
    // 0x8006CD20: nop

    // 0x8006CD24: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8006CD28:
    // 0x8006CD28: lwc1        $f6, 0x7760($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7760);
    // 0x8006CD2C: lwc1        $f12, 0x6C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8006CD30: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8006CD34: sub.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8006CD38: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8006CD3C: nop

    // 0x8006CD40: bc1fl       L_8006CD50
    if (!c1cs) {
        // 0x8006CD44: lwc1        $f0, 0x70($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
            goto L_8006CD50;
    }
    goto skip_2;
    // 0x8006CD44: lwc1        $f0, 0x70($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
    skip_2:
    // 0x8006CD48: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x8006CD4C: lwc1        $f0, 0x70($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
L_8006CD50:
    // 0x8006CD50: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8006CD54: nop

    // 0x8006CD58: bc1fl       L_8006CD68
    if (!c1cs) {
        // 0x8006CD5C: lwc1        $f10, 0x10($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
            goto L_8006CD68;
    }
    goto skip_3;
    // 0x8006CD5C: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    skip_3:
    // 0x8006CD60: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8006CD64: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
L_8006CD68:
    // 0x8006CD68: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8006CD6C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8006CD70: sub.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x8006CD74: jal         0x80065954
    // 0x8006CD78: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8006CD78: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8006CD7C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8006CD80: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8006CD84: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8006CD88: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8006CD8C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006CD90: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8006CD94: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8006CD98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006CD9C: bc1f        L_8006CDAC
    if (!c1cs) {
        // 0x8006CDA0: nop
    
            goto L_8006CDAC;
    }
    // 0x8006CDA0: nop

    // 0x8006CDA4: b           L_8006CDE4
    // 0x8006CDA8: swc1        $f14, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f14.u32l;
        goto L_8006CDE4;
    // 0x8006CDA8: swc1        $f14, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f14.u32l;
L_8006CDAC:
    // 0x8006CDAC: lwc1        $f18, 0x1088($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1088);
    // 0x8006CDB0: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8006CDB4: mul.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8006CDB8: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8006CDBC: nop

    // 0x8006CDC0: bc1fl       L_8006CDD8
    if (!c1cs) {
        // 0x8006CDC4: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_8006CDD8;
    }
    goto skip_4;
    // 0x8006CDC4: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_4:
    // 0x8006CDC8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8006CDCC: b           L_8006CDDC
    // 0x8006CDD0: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
        goto L_8006CDDC;
    // 0x8006CDD0: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006CDD4: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_8006CDD8:
    // 0x8006CDD8: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
L_8006CDDC:
    // 0x8006CDDC: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8006CDE0: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
L_8006CDE4:
    // 0x8006CDE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CDE8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006CDEC: jr          $ra
    // 0x8006CDF0: nop

    return;
    // 0x8006CDF0: nop

;}
RECOMP_FUNC void func_8005AC94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AC94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005AC98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005AC9C: jal         0x80051D64
    // 0x8005ACA0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80051D64(rdram, ctx);
        goto after_0;
    // 0x8005ACA0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8005ACA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005ACA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005ACAC: jr          $ra
    // 0x8005ACB0: nop

    return;
    // 0x8005ACB0: nop

;}
RECOMP_FUNC void func_80454E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454E00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80454E04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80454E08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80454E0C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80454E10: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80454E14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80454E18: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80454E1C: lw          $t6, 0x6A28($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A28);
    // 0x80454E20: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x80454E24: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x80454E28: bne         $t6, $at, L_80454E54
    if (ctx->r14 != ctx->r1) {
        // 0x80454E2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80454E54;
    }
    // 0x80454E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80454E30: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x80454E34: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80454E38: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80454E3C: jal         0x8044EDC4
    // 0x80454E40: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8044EDC4(rdram, ctx);
        goto after_0;
    // 0x80454E40: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80454E44: jal         0x80446D70
    // 0x80454E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80446D70(rdram, ctx);
        goto after_1;
    // 0x80454E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80454E4C: b           L_80454E64
    // 0x80454E50: nop

        goto L_80454E64;
    // 0x80454E50: nop

L_80454E54:
    // 0x80454E54: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454E58: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80454E5C: jal         0x80453704
    // 0x80454E60: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    func_80453704(rdram, ctx);
        goto after_2;
    // 0x80454E60: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    after_2:
L_80454E64:
    // 0x80454E64: jal         0x80454664
    // 0x80454E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80454664(rdram, ctx);
        goto after_3;
    // 0x80454E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80454E6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80454E70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80454E74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80454E78: jr          $ra
    // 0x80454E7C: nop

    return;
    // 0x80454E7C: nop

;}
RECOMP_FUNC void func_80424824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424824: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80424828: lw          $a3, 0x10($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X10);
    // 0x8042482C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80424830: beq         $a3, $zero, L_80424998
    if (ctx->r7 == 0) {
        // 0x80424834: andi        $t0, $a3, 0x3
        ctx->r8 = ctx->r7 & 0X3;
            goto L_80424998;
    }
    // 0x80424834: andi        $t0, $a3, 0x3
    ctx->r8 = ctx->r7 & 0X3;
    // 0x80424838: beq         $t0, $zero, L_804248A8
    if (ctx->r8 == 0) {
        // 0x8042483C: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_804248A8;
    }
    // 0x8042483C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80424840: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80424844: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80424848: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8042484C: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x80424850: mul.s       $f16, $f14, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80424854: beql        $v1, $v0, L_80424890
    if (ctx->r3 == ctx->r2) {
        // 0x80424858: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_80424890;
    }
    goto skip_0;
    // 0x80424858: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_0:
    // 0x8042485C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_80424860:
    // 0x80424860: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80424864: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80424868: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8042486C: swc1        $f14, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80424870: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80424874: lwc1        $f14, 0x4($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80424878: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8042487C: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x80424880: mul.s       $f16, $f14, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80424884: bnel        $v1, $v0, L_80424860
    if (ctx->r3 != ctx->r2) {
        // 0x80424888: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_80424860;
    }
    goto skip_1;
    // 0x80424888: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
    // 0x8042488C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_80424890:
    // 0x80424890: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80424894: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80424898: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8042489C: swc1        $f14, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f14.u32l;
    // 0x804248A0: beq         $v0, $a3, L_80424998
    if (ctx->r2 == ctx->r7) {
        // 0x804248A4: nop
    
            goto L_80424998;
    }
    // 0x804248A4: nop

L_804248A8:
    // 0x804248A8: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x804248AC: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x804248B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804248B4: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x804248B8: mul.s       $f16, $f14, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x804248BC: beql        $v0, $a3, L_80424940
    if (ctx->r2 == ctx->r7) {
        // 0x804248C0: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_80424940;
    }
    goto skip_2;
    // 0x804248C0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_2:
    // 0x804248C4: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_804248C8:
    // 0x804248C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804248CC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x804248D0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x804248D4: swc1        $f14, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->f14.u32l;
    // 0x804248D8: lwc1        $f14, -0xC($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0XC);
    // 0x804248DC: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x804248E0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x804248E4: sub.s       $f10, $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x804248E8: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x804248EC: add.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x804248F0: swc1        $f14, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f14.u32l;
    // 0x804248F4: lwc1        $f14, -0x8($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X8);
    // 0x804248F8: lwc1        $f10, -0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0X8);
    // 0x804248FC: sub.s       $f10, $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x80424900: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80424904: add.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80424908: swc1        $f14, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f14.u32l;
    // 0x8042490C: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x80424910: lwc1        $f10, -0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0X4);
    // 0x80424914: sub.s       $f10, $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x80424918: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8042491C: add.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80424920: swc1        $f14, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80424924: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80424928: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8042492C: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x80424930: mul.s       $f16, $f14, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80424934: bnel        $v0, $a3, L_804248C8
    if (ctx->r2 != ctx->r7) {
        // 0x80424938: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_804248C8;
    }
    goto skip_3;
    // 0x80424938: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_3:
    // 0x8042493C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_80424940:
    // 0x80424940: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80424944: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80424948: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8042494C: swc1        $f14, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->f14.u32l;
    // 0x80424950: lwc1        $f10, -0xC($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0XC);
    // 0x80424954: lwc1        $f14, -0xC($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0XC);
    // 0x80424958: sub.s       $f10, $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8042495C: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80424960: add.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80424964: swc1        $f14, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f14.u32l;
    // 0x80424968: lwc1        $f10, -0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0X8);
    // 0x8042496C: lwc1        $f14, -0x8($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X8);
    // 0x80424970: sub.s       $f10, $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x80424974: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80424978: add.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x8042497C: swc1        $f14, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f14.u32l;
    // 0x80424980: lwc1        $f10, -0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0X4);
    // 0x80424984: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x80424988: sub.s       $f10, $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8042498C: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80424990: add.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80424994: swc1        $f14, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f14.u32l;
L_80424998:
    // 0x80424998: jr          $ra
    // 0x8042499C: nop

    return;
    // 0x8042499C: nop

;}
RECOMP_FUNC void func_8064BD3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BD3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064BD40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064BD44: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8064BD48: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8064BD4C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8064BD50: lui         $t8, 0x8065
    ctx->r24 = S32(RELOC_HI16(495, 0X321C) << 16);
    // 0x8064BD54: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8064BD58: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8064BD5C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8064BD60: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8064BD64: lw          $t8, -0x2D14($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(495, 0X321C));
    // 0x8064BD68: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8064BD6C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8064BD70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064BD74: jal         0x80048490
    // 0x8064BD78: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8064BD78: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8064BD7C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8064BD80: jal         0x80048378
    // 0x8064BD84: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8064BD84: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8064BD88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064BD8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064BD90: jr          $ra
    // 0x8064BD94: nop

    return;
    // 0x8064BD94: nop

;}
RECOMP_FUNC void func_80030FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030FE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030FEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030FF0: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80030FF4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80030FF8: beq         $v0, $zero, L_8003101C
    if (ctx->r2 == 0) {
        // 0x80030FFC: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8003101C;
    }
    // 0x80030FFC: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80031000: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80031004: bne         $at, $zero, L_8003101C
    if (ctx->r1 != 0) {
        // 0x80031008: sw          $t6, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r14;
            goto L_8003101C;
    }
    // 0x80031008: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8003100C: jal         0x80030BA8
    // 0x80031010: nop

    func_80030BA8(rdram, ctx);
        goto after_0;
    // 0x80031010: nop

    after_0:
    // 0x80031014: b           L_80031050
    // 0x80031018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80031050;
    // 0x80031018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003101C:
    // 0x8003101C: lh          $t8, 0x13E($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X13E);
    // 0x80031020: lw          $t9, 0x38($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X38);
    // 0x80031024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80031028: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8003102C: bgezl       $t0, L_80031050
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80031030: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80031050;
    }
    goto skip_0;
    // 0x80031030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80031034: jal         0x80062DD4
    // 0x80031038: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80062DD4(rdram, ctx);
        goto after_1;
    // 0x80031038: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8003103C: beq         $v0, $zero, L_8003104C
    if (ctx->r2 == 0) {
        // 0x80031040: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8003104C;
    }
    // 0x80031040: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80031044: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80031048: sw          $t1, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r9;
L_8003104C:
    // 0x8003104C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80031050:
    // 0x80031050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031058: jr          $ra
    // 0x8003105C: nop

    return;
    // 0x8003105C: nop

;}
RECOMP_FUNC void func_804478C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804478C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804478CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804478D0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x804478D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804478D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804478DC: bne         $a2, $zero, L_80447914
    if (ctx->r6 != 0) {
        // 0x804478E0: lw          $t0, 0x1F4($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X1F4);
            goto L_80447914;
    }
    // 0x804478E0: lw          $t0, 0x1F4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1F4);
    // 0x804478E4: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x804478E8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x804478EC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804478F0: blez        $v1, L_80447900
    if (SIGNED(ctx->r3) <= 0) {
        // 0x804478F4: subu        $t6, $v1, $a3
        ctx->r14 = SUB32(ctx->r3, ctx->r7);
            goto L_80447900;
    }
    // 0x804478F4: subu        $t6, $v1, $a3
    ctx->r14 = SUB32(ctx->r3, ctx->r7);
    // 0x804478F8: b           L_80447960
    // 0x804478FC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_80447960;
    // 0x804478FC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80447900:
    // 0x80447900: jal         0x80446164
    // 0x80447904: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_80446164(rdram, ctx);
        goto after_0;
    // 0x80447904: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80447908: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044790C: b           L_80447960
    // 0x80447910: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
        goto L_80447960;
    // 0x80447910: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_80447914:
    // 0x80447914: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80447918: bne         $a2, $at, L_80447944
    if (ctx->r6 != ctx->r1) {
        // 0x8044791C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80447944;
    }
    // 0x8044791C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80447920: jal         0x8044610C
    // 0x80447924: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_8044610C(rdram, ctx);
        goto after_1;
    // 0x80447924: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80447928: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044792C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447930: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80447934: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80447938: sw          $t7, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r15;
    // 0x8044793C: b           L_80447960
    // 0x80447940: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
        goto L_80447960;
    // 0x80447940: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_80447944:
    // 0x80447944: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80447948: bne         $a2, $at, L_80447960
    if (ctx->r6 != ctx->r1) {
        // 0x8044794C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80447960;
    }
    // 0x8044794C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80447950: jal         0x80446164
    // 0x80447954: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_80446164(rdram, ctx);
        goto after_2;
    // 0x80447954: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_2:
    // 0x80447958: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044795C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_80447960:
    // 0x80447960: jal         0x804475C0
    // 0x80447964: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    func_804475C0(rdram, ctx);
        goto after_3;
    // 0x80447964: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    after_3:
    // 0x80447968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044796C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80447974: jr          $ra
    // 0x80447978: nop

    return;
    // 0x80447978: nop

;}
RECOMP_FUNC void func_8042D5C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042D5C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042D5C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042D5C8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8042D5CC: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8042D5D0: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(50, 0X2FD4) << 16);
    // 0x8042D5D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8042D5D8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042D5DC: lw          $t8, -0x278C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(50, 0X2FD4));
    // 0x8042D5E0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042D5E4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8042D5E8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8042D5EC: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8042D5F0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8042D5F4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8042D5F8: beql        $v1, $zero, L_8042D62C
    if (ctx->r3 == 0) {
        // 0x8042D5FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042D62C;
    }
    goto skip_0;
    // 0x8042D5FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042D600: jalr        $v1
    // 0x8042D604: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8042D604: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042D608: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042D60C: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8042D610: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8042D614: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8042D618: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8042D61C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8042D620: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8042D624: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8042D628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042D62C:
    // 0x8042D62C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042D630: jr          $ra
    // 0x8042D634: nop

    return;
    // 0x8042D634: nop

    // 0x8042D638: nop

    // 0x8042D63C: nop

;}
RECOMP_FUNC void func_805D10D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D10D4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x805D10D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D10DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805D10E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805D10E4: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x805D10E8: lw          $t7, 0x15C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X15C);
    // 0x805D10EC: lw          $v0, 0x14C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14C);
    // 0x805D10F0: lw          $v1, 0x16C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X16C);
    // 0x805D10F4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x805D10F8: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x805D10FC: lw          $s0, 0x8($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X8);
    // 0x805D1100: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x805D1104: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x805D1108: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x805D110C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805D1110: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x805D1114: sw          $v1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r3;
    // 0x805D1118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805D111C: jal         0x8004921C
    // 0x805D1120: sb          $t1, 0x83($sp)
    MEM_B(0X83, ctx->r29) = ctx->r9;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x805D1120: sb          $t1, 0x83($sp)
    MEM_B(0X83, ctx->r29) = ctx->r9;
    after_0:
    // 0x805D1124: sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
    // 0x805D1128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805D112C: jal         0x8004921C
    // 0x805D1130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x805D1130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x805D1134: lh          $t2, 0x32($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X32);
    // 0x805D1138: lw          $t6, 0x168($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X168);
    // 0x805D113C: lbu         $t4, 0x83($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X83);
    // 0x805D1140: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805D1144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D1148: lw          $v1, 0x88($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X88);
    // 0x805D114C: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x805D1150: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D1154: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x805D1158: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x805D115C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x805D1160: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x805D1164: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x805D1168: mflo        $t3
    ctx->r11 = lo;
    // 0x805D116C: ori         $t9, $t9, 0x18
    ctx->r25 = ctx->r25 | 0X18;
    // 0x805D1170: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D1174: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805D1178: addiu       $t0, $zero, 0x2C80
    ctx->r8 = ADD32(0, 0X2C80);
    // 0x805D117C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x805D1180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D1184: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x805D1188: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D118C: lui         $a3, 0xF0A
    ctx->r7 = S32(0XF0A << 16);
    // 0x805D1190: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x805D1194: ori         $t1, $t1, 0x3
    ctx->r9 = ctx->r9 | 0X3;
    // 0x805D1198: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x805D119C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805D11A0: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    // 0x805D11A4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x805D11A8: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x805D11AC: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x805D11B0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D11B4: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x805D11B8: sw          $a3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r7;
    // 0x805D11BC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x805D11C0: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x805D11C4: mflo        $t5
    ctx->r13 = lo;
    // 0x805D11C8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x805D11CC: addu        $a2, $t5, $t7
    ctx->r6 = ADD32(ctx->r13, ctx->r15);
    // 0x805D11D0: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x805D11D4: lbu         $t1, 0x1($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X1);
    // 0x805D11D8: lbu         $t6, 0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3);
    // 0x805D11DC: lbu         $t5, 0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2);
    // 0x805D11E0: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x805D11E4: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x805D11E8: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x805D11EC: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x805D11F0: sll         $t7, $t5, 8
    ctx->r15 = S32(ctx->r13 << 8);
    // 0x805D11F4: or          $t6, $t3, $t7
    ctx->r14 = ctx->r11 | ctx->r15;
    // 0x805D11F8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D11FC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x805D1200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D1204: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x805D1208: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x805D120C: lbu         $t2, 0x4($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X4);
    // 0x805D1210: lbu         $t7, 0x5($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X5);
    // 0x805D1214: lbu         $t1, 0x7($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X7);
    // 0x805D1218: lbu         $t9, 0x6($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X6);
    // 0x805D121C: sll         $t4, $t2, 24
    ctx->r12 = S32(ctx->r10 << 24);
    // 0x805D1220: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x805D1224: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x805D1228: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x805D122C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D1230: sll         $t2, $t9, 8
    ctx->r10 = S32(ctx->r25 << 8);
    // 0x805D1234: or          $t1, $t8, $t2
    ctx->r9 = ctx->r24 | ctx->r10;
    // 0x805D1238: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805D123C: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x805D1240: lui         $t4, 0xFC30
    ctx->r12 = S32(0XFC30 << 16);
    // 0x805D1244: lui         $t3, 0x5566
    ctx->r11 = S32(0X5566 << 16);
    // 0x805D1248: ori         $t3, $t3, 0xDB6D
    ctx->r11 = ctx->r11 | 0XDB6D;
    // 0x805D124C: ori         $t4, $t4, 0xB261
    ctx->r12 = ctx->r12 | 0XB261;
    // 0x805D1250: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D1254: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x805D1258: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x805D125C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x805D1260: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D1264: lui         $t7, 0xBB00
    ctx->r15 = S32(0XBB00 << 16);
    // 0x805D1268: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x805D126C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x805D1270: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805D1274: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x805D1278: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805D127C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D1280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D1284: lui         $t6, 0xFD90
    ctx->r14 = S32(0XFD90 << 16);
    // 0x805D1288: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x805D128C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D1290: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x805D1294: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805D1298: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x805D129C: lui         $t0, 0xF590
    ctx->r8 = S32(0XF590 << 16);
    // 0x805D12A0: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x805D12A4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x805D12A8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D12AC: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x805D12B0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x805D12B4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x805D12B8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x805D12BC: lui         $t2, 0xF300
    ctx->r10 = S32(0XF300 << 16);
    // 0x805D12C0: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x805D12C4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x805D12C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805D12CC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D12D0: jal         0x8004921C
    // 0x805D12D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8004921C(rdram, ctx);
        goto after_2;
    // 0x805D12D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x805D12D8: sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
    // 0x805D12DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805D12E0: jal         0x8004921C
    // 0x805D12E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_3;
    // 0x805D12E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x805D12E8: lh          $t1, 0x32($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X32);
    // 0x805D12EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805D12F0: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805D12F4: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x805D12F8: mflo        $t4
    ctx->r12 = lo;
    // 0x805D12FC: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x805D1300: sra         $t7, $t3, 1
    ctx->r15 = S32(SIGNED(ctx->r11) >> 1);
    // 0x805D1304: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x805D1308: slti        $at, $t5, 0x7FF
    ctx->r1 = SIGNED(ctx->r13) < 0X7FF ? 1 : 0;
    // 0x805D130C: beql        $at, $zero, L_805D1350
    if (ctx->r1 == 0) {
        // 0x805D1310: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_805D1350;
    }
    goto skip_0;
    // 0x805D1310: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    skip_0:
    // 0x805D1314: jal         0x8004921C
    // 0x805D1318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_4;
    // 0x805D1318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x805D131C: sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // 0x805D1320: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805D1324: jal         0x8004921C
    // 0x805D1328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_5;
    // 0x805D1328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x805D132C: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x805D1330: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805D1334: mflo        $t0
    ctx->r8 = lo;
    // 0x805D1338: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x805D133C: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x805D1340: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x805D1344: b           L_805D1350
    // 0x805D1348: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
        goto L_805D1350;
    // 0x805D1348: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x805D134C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_805D1350:
    // 0x805D1350: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805D1354: jal         0x8004921C
    // 0x805D1358: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_6;
    // 0x805D1358: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x805D135C: bgez        $v0, L_805D136C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805D1360: sra         $t4, $v0, 3
        ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805D136C;
    }
    // 0x805D1360: sra         $t4, $v0, 3
    ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805D1364: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805D1368: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_805D136C:
    // 0x805D136C: bgtz        $t4, L_805D137C
    if (SIGNED(ctx->r12) > 0) {
        // 0x805D1370: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_805D137C;
    }
    // 0x805D1370: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805D1374: b           L_805D1394
    // 0x805D1378: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_805D1394;
    // 0x805D1378: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_805D137C:
    // 0x805D137C: jal         0x8004921C
    // 0x805D1380: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_7;
    // 0x805D1380: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x805D1384: bgez        $v0, L_805D1394
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805D1388: sra         $a3, $v0, 3
        ctx->r7 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805D1394;
    }
    // 0x805D1388: sra         $a3, $v0, 3
    ctx->r7 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805D138C: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805D1390: sra         $a3, $at, 3
    ctx->r7 = S32(SIGNED(ctx->r1) >> 3);
L_805D1394:
    // 0x805D1394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805D1398: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805D139C: jal         0x8004921C
    // 0x805D13A0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_8;
    // 0x805D13A0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_8:
    // 0x805D13A4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x805D13A8: bgez        $v0, L_805D13B8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805D13AC: sra         $t3, $v0, 3
        ctx->r11 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805D13B8;
    }
    // 0x805D13AC: sra         $t3, $v0, 3
    ctx->r11 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805D13B0: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805D13B4: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_805D13B8:
    // 0x805D13B8: bgtzl       $t3, L_805D13CC
    if (SIGNED(ctx->r11) > 0) {
        // 0x805D13BC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_805D13CC;
    }
    goto skip_1;
    // 0x805D13BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x805D13C0: b           L_805D13EC
    // 0x805D13C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D13EC;
    // 0x805D13C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D13C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_805D13CC:
    // 0x805D13CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805D13D0: jal         0x8004921C
    // 0x805D13D4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_9;
    // 0x805D13D4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_9:
    // 0x805D13D8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x805D13DC: bgez        $v0, L_805D13EC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805D13E0: sra         $v1, $v0, 3
        ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805D13EC;
    }
    // 0x805D13E0: sra         $v1, $v0, 3
    ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805D13E4: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805D13E8: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_805D13EC:
    // 0x805D13EC: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x805D13F0: div         $zero, $t7, $v1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r3)));
    // 0x805D13F4: bne         $v1, $zero, L_805D1400
    if (ctx->r3 != 0) {
        // 0x805D13F8: nop
    
            goto L_805D1400;
    }
    // 0x805D13F8: nop

    // 0x805D13FC: break       7
    do_break(2153583612);
L_805D1400:
    // 0x805D1400: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805D1404: bne         $v1, $at, L_805D1418
    if (ctx->r3 != ctx->r1) {
        // 0x805D1408: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805D1418;
    }
    // 0x805D1408: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805D140C: bne         $t7, $at, L_805D1418
    if (ctx->r15 != ctx->r1) {
        // 0x805D1410: nop
    
            goto L_805D1418;
    }
    // 0x805D1410: nop

    // 0x805D1414: break       6
    do_break(2153583636);
L_805D1418:
    // 0x805D1418: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x805D141C: mflo        $t5
    ctx->r13 = lo;
    // 0x805D1420: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x805D1424: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x805D1428: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x805D142C: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x805D1430: sll         $t2, $t8, 12
    ctx->r10 = S32(ctx->r24 << 12);
    // 0x805D1434: or          $t0, $t6, $at
    ctx->r8 = ctx->r14 | ctx->r1;
    // 0x805D1438: or          $t1, $t0, $t2
    ctx->r9 = ctx->r8 | ctx->r10;
    // 0x805D143C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x805D1440: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x805D1444: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D1448: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x805D144C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x805D1450: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x805D1454: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805D1458: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x805D145C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D1460: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805D1464: jal         0x8004921C
    // 0x805D1468: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_10;
    // 0x805D1468: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x805D146C: addiu       $t7, $v0, 0x7
    ctx->r15 = ADD32(ctx->r2, 0X7);
    // 0x805D1470: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x805D1474: sra         $t5, $t7, 3
    ctx->r13 = S32(SIGNED(ctx->r15) >> 3);
    // 0x805D1478: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x805D147C: sll         $t9, $t6, 9
    ctx->r25 = S32(ctx->r14 << 9);
    // 0x805D1480: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x805D1484: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x805D1488: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805D148C: lui         $t0, 0xF200
    ctx->r8 = S32(0XF200 << 16);
    // 0x805D1490: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x805D1494: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x805D1498: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x805D149C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x805D14A0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D14A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805D14A8: jal         0x8004921C
    // 0x805D14AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_11;
    // 0x805D14AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x805D14B0: sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
    // 0x805D14B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805D14B8: jal         0x8004921C
    // 0x805D14BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_12;
    // 0x805D14BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x805D14C0: lh          $t3, 0x32($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X32);
    // 0x805D14C4: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x805D14C8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x805D14CC: addiu       $t7, $t3, -0x1
    ctx->r15 = ADD32(ctx->r11, -0X1);
    // 0x805D14D0: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x805D14D4: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x805D14D8: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x805D14DC: andi        $t4, $t1, 0xFFF
    ctx->r12 = ctx->r9 & 0XFFF;
    // 0x805D14E0: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x805D14E4: or          $t8, $t4, $t9
    ctx->r24 = ctx->r12 | ctx->r25;
    // 0x805D14E8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805D14EC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D14F0: lui         $t2, 0xE450
    ctx->r10 = S32(0XE450 << 16);
    // 0x805D14F4: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x805D14F8: ori         $t2, $t2, 0x3C0
    ctx->r10 = ctx->r10 | 0X3C0;
    // 0x805D14FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D1500: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x805D1504: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x805D1508: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D150C: lui         $t1, 0xB400
    ctx->r9 = S32(0XB400 << 16);
    // 0x805D1510: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x805D1514: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805D1518: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x805D151C: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x805D1520: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x805D1524: lui         $t3, 0xB300
    ctx->r11 = S32(0XB300 << 16);
    // 0x805D1528: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x805D152C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x805D1530: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x805D1534: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805D1538: sw          $s0, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r16;
    // 0x805D153C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805D1540: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805D1544: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805D1548: jr          $ra
    // 0x805D154C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x805D154C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80535E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535E24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80535E28: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80535E2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80535E30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80535E34: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80535E38: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80535E3C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80535E40: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80535E44: addiu       $t6, $zero, 0x1D4C
    ctx->r14 = ADD32(0, 0X1D4C);
    // 0x80535E48: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80535E4C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80535E50: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80535E54: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // 0x80535E58: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80535E5C: jal         0x8053589C
    // 0x80535E60: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8053589C(rdram, ctx);
        goto after_0;
    // 0x80535E60: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80535E64: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80535E68: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80535E6C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80535E70: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x80535E74: addiu       $t8, $zero, 0x1D4C
    ctx->r24 = ADD32(0, 0X1D4C);
    // 0x80535E78: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80535E7C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80535E80: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // 0x80535E84: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80535E88: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80535E8C: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80535E90: jal         0x8053589C
    // 0x80535E94: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_8053589C(rdram, ctx);
        goto after_1;
    // 0x80535E94: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80535E98: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80535E9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80535EA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80535EA4: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80535EA8: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80535EAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80535EB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80535EB4: jr          $ra
    // 0x80535EB8: nop

    return;
    // 0x80535EB8: nop

;}
RECOMP_FUNC void func_805DAE20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DAE20: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x805DAE24: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x805DAE28: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805DAE2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805DAE30: nop

    // 0x805DAE34: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x805DAE38: nop

    // 0x805DAE3C: bc1fl       L_805DAE6C
    if (!c1cs) {
        // 0x805DAE40: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_805DAE6C;
    }
    goto skip_0;
    // 0x805DAE40: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x805DAE44: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805DAE48: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805DAE4C: nop

    // 0x805DAE50: bc1f        L_805DAE88
    if (!c1cs) {
        // 0x805DAE54: nop
    
            goto L_805DAE88;
    }
    // 0x805DAE54: nop

    // 0x805DAE58: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x805DAE5C: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x805DAE60: jr          $ra
    // 0x805DAE64: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x805DAE64: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x805DAE68: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_805DAE6C:
    // 0x805DAE6C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x805DAE70: nop

    // 0x805DAE74: bc1f        L_805DAE88
    if (!c1cs) {
        // 0x805DAE78: nop
    
            goto L_805DAE88;
    }
    // 0x805DAE78: nop

    // 0x805DAE7C: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x805DAE80: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x805DAE84: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_805DAE88:
    // 0x805DAE88: jr          $ra
    // 0x805DAE8C: nop

    return;
    // 0x805DAE8C: nop

;}
RECOMP_FUNC void func_8043DA34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DA34: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x8043DA38: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x8043DA3C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8043DA40: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x8043DA44: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8043DA48: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8043DA4C: sltu        $at, $a2, $t7
    ctx->r1 = ctx->r6 < ctx->r15 ? 1 : 0;
    // 0x8043DA50: beq         $at, $zero, L_8043DA94
    if (ctx->r1 == 0) {
        // 0x8043DA54: sltu        $at, $t7, $a2
        ctx->r1 = ctx->r15 < ctx->r6 ? 1 : 0;
            goto L_8043DA94;
    }
    // 0x8043DA54: sltu        $at, $t7, $a2
    ctx->r1 = ctx->r15 < ctx->r6 ? 1 : 0;
    // 0x8043DA58: bne         $at, $zero, L_8043DA78
    if (ctx->r1 != 0) {
        // 0x8043DA5C: subu        $t8, $v1, $a2
        ctx->r24 = SUB32(ctx->r3, ctx->r6);
            goto L_8043DA78;
    }
    // 0x8043DA5C: subu        $t8, $v1, $a2
    ctx->r24 = SUB32(ctx->r3, ctx->r6);
L_8043DA60:
    // 0x8043DA60: sw          $t8, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r24;
    // 0x8043DA64: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8043DA68: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8043DA6C: sltu        $at, $t8, $a2
    ctx->r1 = ctx->r24 < ctx->r6 ? 1 : 0;
    // 0x8043DA70: beql        $at, $zero, L_8043DA60
    if (ctx->r1 == 0) {
        // 0x8043DA74: subu        $t8, $v1, $a2
        ctx->r24 = SUB32(ctx->r3, ctx->r6);
            goto L_8043DA60;
    }
    goto skip_0;
    // 0x8043DA74: subu        $t8, $v1, $a2
    ctx->r24 = SUB32(ctx->r3, ctx->r6);
    skip_0:
L_8043DA78:
    // 0x8043DA78: lh          $v0, 0x144($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X144);
    // 0x8043DA7C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8043DA80: beq         $v0, $at, L_8043DA90
    if (ctx->r2 == ctx->r1) {
        // 0x8043DA84: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_8043DA90;
    }
    // 0x8043DA84: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8043DA88: jr          $ra
    // 0x8043DA8C: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    return;
    // 0x8043DA8C: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
L_8043DA90:
    // 0x8043DA90: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
L_8043DA94:
    // 0x8043DA94: jr          $ra
    // 0x8043DA98: nop

    return;
    // 0x8043DA98: nop

;}
RECOMP_FUNC void func_80675CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675CD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80675CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80675CD8: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x80675CDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80675CE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80675CE4: lhu         $t7, 0x4($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X4);
    // 0x80675CE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80675CEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80675CF0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80675CF4: beq         $t8, $zero, L_80675D38
    if (ctx->r24 == 0) {
        // 0x80675CF8: nop
    
            goto L_80675D38;
    }
    // 0x80675CF8: nop

    // 0x80675CFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80675D00: jal         0x80677A88
    // 0x80675D04: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_80677A88(rdram, ctx);
        goto after_0;
    // 0x80675D04: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80675D08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80675D0C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80675D10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80675D14: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80675D18: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x80675D1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80675D20: lhu         $t9, 0x4($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4);
    // 0x80675D24: andi        $t1, $t9, 0xFFFE
    ctx->r9 = ctx->r25 & 0XFFFE;
    // 0x80675D28: sh          $t1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r9;
    // 0x80675D2C: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x80675D30: b           L_80675D38
    // 0x80675D34: sh          $t2, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r10;
        goto L_80675D38;
    // 0x80675D34: sh          $t2, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r10;
L_80675D38:
    // 0x80675D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80675D3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80675D40: jr          $ra
    // 0x80675D44: nop

    return;
    // 0x80675D44: nop

;}
RECOMP_FUNC void func_804CEC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CEC28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CEC2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CEC30: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804CEC34: lui         $t6, 0x804D
    ctx->r14 = S32(RELOC_HI16(240, 0X1A4C) << 16);
    // 0x804CEC38: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x804CEC3C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804CEC40: addiu       $t6, $t6, -0x304
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(240, 0X1A4C));
    // 0x804CEC44: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804CEC48: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804CEC4C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x804CEC50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CEC54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804CEC58: jal         0x804CEC7C
    // 0x804CEC5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804CEC7C(rdram, ctx);
        goto after_0;
    // 0x804CEC5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804CEC60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CEC64: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804CEC68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804CEC6C: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x804CEC70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CEC74: jr          $ra
    // 0x804CEC78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x804CEC78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void lfloorf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081FF8: floor.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = S32(floorf(ctx->f12.fl));
    // 0x80081FFC: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80082000: jr          $ra
    // 0x80082004: nop

    return;
    // 0x80082004: nop

;}
RECOMP_FUNC void func_8044F424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044F424: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8044F428: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8044F42C: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044F430: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F434: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8044F438: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    // 0x8044F43C: lw          $t6, 0x6A2C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X6A2C);
    // 0x8044F440: lw          $v1, 0x6A20($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X6A20);
    // 0x8044F444: lw          $a3, 0x6A24($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X6A24);
    // 0x8044F448: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8044F44C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8044F450: bne         $t6, $at, L_8044F464
    if (ctx->r14 != ctx->r1) {
        // 0x8044F454: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_8044F464;
    }
    // 0x8044F454: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8044F458: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8044F45C: b           L_8044F46C
    // 0x8044F460: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
        goto L_8044F46C;
    // 0x8044F460: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_8044F464:
    // 0x8044F464: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8044F468: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8044F46C:
    // 0x8044F46C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8044F470: lui         $t8, 0x8045
    ctx->r24 = S32(RELOC_HI16(98, 0X1370C) << 16);
    // 0x8044F474: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8044F478: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8044F47C: addiu       $t8, $t8, 0x7AEC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(98, 0X1370C));
    // 0x8044F480: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8044F484: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8044F488: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8044F48C: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x8044F490: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8044F494: addiu       $t0, $sp, 0x4C
    ctx->r8 = ADD32(ctx->r29, 0X4C);
    // 0x8044F498: addiu       $t2, $sp, 0x34
    ctx->r10 = ADD32(ctx->r29, 0X34);
    // 0x8044F49C: addiu       $v1, $sp, 0x4C
    ctx->r3 = ADD32(ctx->r29, 0X4C);
L_8044F4A0:
    // 0x8044F4A0: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x8044F4A4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8044F4A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8044F4AC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8044F4B0: bgez        $t4, L_8044F4C4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8044F4B4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8044F4C4;
    }
    // 0x8044F4B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8044F4B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8044F4BC: nop

    // 0x8044F4C0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8044F4C4:
    // 0x8044F4C4: lbu         $t5, 0x0($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X0);
    // 0x8044F4C8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8044F4CC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8044F4D0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8044F4D4: swc1        $f6, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f6.u32l;
    // 0x8044F4D8: bgez        $t5, L_8044F4F0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8044F4DC: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8044F4F0;
    }
    // 0x8044F4DC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8044F4E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8044F4E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8044F4E8: nop

    // 0x8044F4EC: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8044F4F0:
    // 0x8044F4F0: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8044F4F4: sltu        $at, $t2, $v1
    ctx->r1 = ctx->r10 < ctx->r3 ? 1 : 0;
    // 0x8044F4F8: bne         $at, $zero, L_8044F4A0
    if (ctx->r1 != 0) {
        // 0x8044F4FC: swc1        $f18, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->f18.u32l;
            goto L_8044F4A0;
    }
    // 0x8044F4FC: swc1        $f18, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->f18.u32l;
    // 0x8044F500: bgtz        $a3, L_8044F518
    if (SIGNED(ctx->r7) > 0) {
        // 0x8044F504: sll         $t5, $a3, 1
        ctx->r13 = S32(ctx->r7 << 1);
            goto L_8044F518;
    }
    // 0x8044F504: sll         $t5, $a3, 1
    ctx->r13 = S32(ctx->r7 << 1);
    // 0x8044F508: lw          $t6, 0x6A3C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X6A3C);
    // 0x8044F50C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8044F510: b           L_8044F548
    // 0x8044F514: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
        goto L_8044F548;
    // 0x8044F514: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
L_8044F518:
    // 0x8044F518: slti        $at, $a3, 0xD
    ctx->r1 = SIGNED(ctx->r7) < 0XD ? 1 : 0;
    // 0x8044F51C: beq         $at, $zero, L_8044F538
    if (ctx->r1 == 0) {
        // 0x8044F520: sll         $t7, $a3, 2
        ctx->r15 = S32(ctx->r7 << 2);
            goto L_8044F538;
    }
    // 0x8044F520: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8044F524: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x8044F528: lw          $t8, -0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X4);
    // 0x8044F52C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8044F530: b           L_8044F548
    // 0x8044F534: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
        goto L_8044F548;
    // 0x8044F534: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
L_8044F538:
    // 0x8044F538: lw          $t4, 0x6A38($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X6A38);
    // 0x8044F53C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8044F540: nop

    // 0x8044F544: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
L_8044F548:
    // 0x8044F548: lui         $v0, 0x8045
    ctx->r2 = S32(RELOC_HI16(98, 0X13760) << 16);
    // 0x8044F54C: addiu       $v0, $v0, 0x7B40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(98, 0X13760));
    // 0x8044F550: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8044F554: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8044F558: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8044F55C: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8044F560: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8044F564: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8044F568: bne         $a1, $a3, L_8044F974
    if (ctx->r5 != ctx->r7) {
        // 0x8044F56C: cvt.s.w     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8044F974;
    }
    // 0x8044F56C: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8044F570: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8044F574: addu        $t8, $v0, $t9
    ctx->r24 = ADD32(ctx->r2, ctx->r25);
    // 0x8044F578: lh          $t4, 0x0($t8)
    ctx->r12 = MEM_H(ctx->r24, 0X0);
    // 0x8044F57C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8044F580: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8044F584: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8044F588: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044F58C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8044F590: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8044F594: addiu       $t4, $sp, 0x34
    ctx->r12 = ADD32(ctx->r29, 0X34);
    // 0x8044F598: addiu       $t8, $sp, 0x4C
    ctx->r24 = ADD32(ctx->r29, 0X4C);
    // 0x8044F59C: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8044F5A0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8044F5A4: nop

    // 0x8044F5A8: bc1fl       L_8044F5BC
    if (!c1cs) {
        // 0x8044F5AC: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_8044F5BC;
    }
    goto skip_0;
    // 0x8044F5AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x8044F5B0: b           L_8044F5C0
    // 0x8044F5B4: div.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
        goto L_8044F5C0;
    // 0x8044F5B4: div.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8044F5B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_8044F5BC:
    // 0x8044F5BC: nop

L_8044F5C0:
    // 0x8044F5C0: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8044F5C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8044F5C8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8044F5CC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8044F5D0: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8044F5D4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8044F5D8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8044F5DC: nop

    // 0x8044F5E0: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8044F5E4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8044F5E8: nop

    // 0x8044F5EC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8044F5F0: beql        $t6, $zero, L_8044F640
    if (ctx->r14 == 0) {
        // 0x8044F5F4: mfc1        $t6, $f8
        ctx->r14 = (int32_t)ctx->f8.u32l;
            goto L_8044F640;
    }
    goto skip_1;
    // 0x8044F5F4: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x8044F5F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8044F5FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8044F600: sub.s       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8044F604: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8044F608: nop

    // 0x8044F60C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8044F610: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8044F614: nop

    // 0x8044F618: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8044F61C: bne         $t6, $zero, L_8044F634
    if (ctx->r14 != 0) {
        // 0x8044F620: nop
    
            goto L_8044F634;
    }
    // 0x8044F620: nop

    // 0x8044F624: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8044F628: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044F62C: b           L_8044F64C
    // 0x8044F630: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8044F64C;
    // 0x8044F630: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8044F634:
    // 0x8044F634: b           L_8044F64C
    // 0x8044F638: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8044F64C;
    // 0x8044F638: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8044F63C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
L_8044F640:
    // 0x8044F640: nop

    // 0x8044F644: bltz        $t6, L_8044F634
    if (SIGNED(ctx->r14) < 0) {
        // 0x8044F648: nop
    
            goto L_8044F634;
    }
    // 0x8044F648: nop

L_8044F64C:
    // 0x8044F64C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8044F650: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8044F654: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8044F658: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8044F65C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8044F660: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8044F664: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8044F668: mul.s       $f18, $f6, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8044F66C: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8044F670: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8044F674: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8044F678: nop

    // 0x8044F67C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8044F680: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8044F684: nop

    // 0x8044F688: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8044F68C: beql        $t9, $zero, L_8044F6DC
    if (ctx->r25 == 0) {
        // 0x8044F690: mfc1        $t9, $f10
        ctx->r25 = (int32_t)ctx->f10.u32l;
            goto L_8044F6DC;
    }
    goto skip_2;
    // 0x8044F690: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    skip_2:
    // 0x8044F694: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8044F698: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8044F69C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8044F6A0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8044F6A4: nop

    // 0x8044F6A8: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8044F6AC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8044F6B0: nop

    // 0x8044F6B4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8044F6B8: bne         $t9, $zero, L_8044F6D0
    if (ctx->r25 != 0) {
        // 0x8044F6BC: nop
    
            goto L_8044F6D0;
    }
    // 0x8044F6BC: nop

    // 0x8044F6C0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8044F6C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044F6C8: b           L_8044F6E8
    // 0x8044F6CC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8044F6E8;
    // 0x8044F6CC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8044F6D0:
    // 0x8044F6D0: b           L_8044F6E8
    // 0x8044F6D4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8044F6E8;
    // 0x8044F6D4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8044F6D8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
L_8044F6DC:
    // 0x8044F6DC: nop

    // 0x8044F6E0: bltz        $t9, L_8044F6D0
    if (SIGNED(ctx->r25) < 0) {
        // 0x8044F6E4: nop
    
            goto L_8044F6D0;
    }
    // 0x8044F6E4: nop

L_8044F6E8:
    // 0x8044F6E8: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x8044F6EC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8044F6F0: addu        $t0, $v0, $t8
    ctx->r8 = ADD32(ctx->r2, ctx->r24);
    // 0x8044F6F4: addu        $t2, $v0, $t4
    ctx->r10 = ADD32(ctx->r2, ctx->r12);
    // 0x8044F6F8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8044F6FC: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8044F700: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8044F704: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8044F708: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8044F70C: sub.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8044F710: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8044F714: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8044F718: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8044F71C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8044F720: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8044F724: nop

    // 0x8044F728: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8044F72C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8044F730: nop

    // 0x8044F734: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8044F738: beql        $t6, $zero, L_8044F788
    if (ctx->r14 == 0) {
        // 0x8044F73C: mfc1        $t6, $f10
        ctx->r14 = (int32_t)ctx->f10.u32l;
            goto L_8044F788;
    }
    goto skip_3;
    // 0x8044F73C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    skip_3:
    // 0x8044F740: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8044F744: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8044F748: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8044F74C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8044F750: nop

    // 0x8044F754: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8044F758: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8044F75C: nop

    // 0x8044F760: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8044F764: bne         $t6, $zero, L_8044F77C
    if (ctx->r14 != 0) {
        // 0x8044F768: nop
    
            goto L_8044F77C;
    }
    // 0x8044F768: nop

    // 0x8044F76C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8044F770: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044F774: b           L_8044F794
    // 0x8044F778: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8044F794;
    // 0x8044F778: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8044F77C:
    // 0x8044F77C: b           L_8044F794
    // 0x8044F780: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8044F794;
    // 0x8044F780: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8044F784: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
L_8044F788:
    // 0x8044F788: nop

    // 0x8044F78C: bltz        $t6, L_8044F77C
    if (SIGNED(ctx->r14) < 0) {
        // 0x8044F790: nop
    
            goto L_8044F77C;
    }
    // 0x8044F790: nop

L_8044F794:
    // 0x8044F794: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x8044F798: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8044F79C: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8044F7A0: lwc1        $f2, 0x4($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8044F7A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8044F7A8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8044F7AC: sub.s       $f18, $f6, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8044F7B0: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8044F7B4: add.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8044F7B8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8044F7BC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8044F7C0: nop

    // 0x8044F7C4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8044F7C8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8044F7CC: nop

    // 0x8044F7D0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8044F7D4: beql        $t9, $zero, L_8044F824
    if (ctx->r25 == 0) {
        // 0x8044F7D8: mfc1        $t9, $f10
        ctx->r25 = (int32_t)ctx->f10.u32l;
            goto L_8044F824;
    }
    goto skip_4;
    // 0x8044F7D8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x8044F7DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8044F7E0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8044F7E4: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8044F7E8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8044F7EC: nop

    // 0x8044F7F0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8044F7F4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8044F7F8: nop

    // 0x8044F7FC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8044F800: bne         $t9, $zero, L_8044F818
    if (ctx->r25 != 0) {
        // 0x8044F804: nop
    
            goto L_8044F818;
    }
    // 0x8044F804: nop

    // 0x8044F808: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8044F80C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044F810: b           L_8044F830
    // 0x8044F814: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8044F830;
    // 0x8044F814: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8044F818:
    // 0x8044F818: b           L_8044F830
    // 0x8044F81C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8044F830;
    // 0x8044F81C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8044F820: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
L_8044F824:
    // 0x8044F824: nop

    // 0x8044F828: bltz        $t9, L_8044F818
    if (SIGNED(ctx->r25) < 0) {
        // 0x8044F82C: nop
    
            goto L_8044F818;
    }
    // 0x8044F82C: nop

L_8044F830:
    // 0x8044F830: sb          $t9, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r25;
    // 0x8044F834: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8044F838: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8044F83C: lwc1        $f14, 0x8($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8044F840: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8044F844: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8044F848: sub.s       $f18, $f6, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x8044F84C: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8044F850: add.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x8044F854: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8044F858: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8044F85C: nop

    // 0x8044F860: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8044F864: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8044F868: nop

    // 0x8044F86C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8044F870: beql        $t4, $zero, L_8044F8C0
    if (ctx->r12 == 0) {
        // 0x8044F874: mfc1        $t4, $f10
        ctx->r12 = (int32_t)ctx->f10.u32l;
            goto L_8044F8C0;
    }
    goto skip_5;
    // 0x8044F874: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    skip_5:
    // 0x8044F878: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8044F87C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8044F880: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8044F884: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8044F888: nop

    // 0x8044F88C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8044F890: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8044F894: nop

    // 0x8044F898: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8044F89C: bne         $t4, $zero, L_8044F8B4
    if (ctx->r12 != 0) {
        // 0x8044F8A0: nop
    
            goto L_8044F8B4;
    }
    // 0x8044F8A0: nop

    // 0x8044F8A4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8044F8A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044F8AC: b           L_8044F8CC
    // 0x8044F8B0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8044F8CC;
    // 0x8044F8B0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8044F8B4:
    // 0x8044F8B4: b           L_8044F8CC
    // 0x8044F8B8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8044F8CC;
    // 0x8044F8B8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8044F8BC: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
L_8044F8C0:
    // 0x8044F8C0: nop

    // 0x8044F8C4: bltz        $t4, L_8044F8B4
    if (SIGNED(ctx->r12) < 0) {
        // 0x8044F8C8: nop
    
            goto L_8044F8B4;
    }
    // 0x8044F8C8: nop

L_8044F8CC:
    // 0x8044F8CC: sb          $t4, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r12;
    // 0x8044F8D0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8044F8D4: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8044F8D8: lwc1        $f16, 0xC($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8044F8DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8044F8E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8044F8E4: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8044F8E8: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8044F8EC: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8044F8F0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8044F8F4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8044F8F8: nop

    // 0x8044F8FC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8044F900: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8044F904: nop

    // 0x8044F908: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8044F90C: beql        $t6, $zero, L_8044F95C
    if (ctx->r14 == 0) {
        // 0x8044F910: mfc1        $t6, $f10
        ctx->r14 = (int32_t)ctx->f10.u32l;
            goto L_8044F95C;
    }
    goto skip_6;
    // 0x8044F910: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    skip_6:
    // 0x8044F914: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8044F918: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8044F91C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8044F920: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8044F924: nop

    // 0x8044F928: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8044F92C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8044F930: nop

    // 0x8044F934: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8044F938: bne         $t6, $zero, L_8044F950
    if (ctx->r14 != 0) {
        // 0x8044F93C: nop
    
            goto L_8044F950;
    }
    // 0x8044F93C: nop

    // 0x8044F940: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8044F944: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044F948: b           L_8044F968
    // 0x8044F94C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8044F968;
    // 0x8044F94C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8044F950:
    // 0x8044F950: b           L_8044F968
    // 0x8044F954: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8044F968;
    // 0x8044F954: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8044F958: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
L_8044F95C:
    // 0x8044F95C: nop

    // 0x8044F960: bltz        $t6, L_8044F950
    if (SIGNED(ctx->r14) < 0) {
        // 0x8044F964: nop
    
            goto L_8044F950;
    }
    // 0x8044F964: nop

L_8044F968:
    // 0x8044F968: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8044F96C: b           L_8044FD50
    // 0x8044F970: sb          $t6, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r14;
        goto L_8044FD50;
    // 0x8044F970: sb          $t6, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r14;
L_8044F974:
    // 0x8044F974: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8044F978: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044F97C: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8044F980: addiu       $t5, $sp, 0x34
    ctx->r13 = ADD32(ctx->r29, 0X34);
    // 0x8044F984: bc1f        L_8044F994
    if (!c1cs) {
        // 0x8044F988: addiu       $t6, $sp, 0x4C
        ctx->r14 = ADD32(ctx->r29, 0X4C);
            goto L_8044F994;
    }
    // 0x8044F988: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x8044F98C: b           L_8044F99C
    // 0x8044F990: div.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
        goto L_8044F99C;
    // 0x8044F990: div.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
L_8044F994:
    // 0x8044F994: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8044F998: nop

L_8044F99C:
    // 0x8044F99C: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8044F9A0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8044F9A4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8044F9A8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8044F9AC: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8044F9B0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8044F9B4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8044F9B8: nop

    // 0x8044F9BC: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8044F9C0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8044F9C4: nop

    // 0x8044F9C8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8044F9CC: beql        $t9, $zero, L_8044FA1C
    if (ctx->r25 == 0) {
        // 0x8044F9D0: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_8044FA1C;
    }
    goto skip_7;
    // 0x8044F9D0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_7:
    // 0x8044F9D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8044F9D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8044F9DC: sub.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8044F9E0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8044F9E4: nop

    // 0x8044F9E8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8044F9EC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8044F9F0: nop

    // 0x8044F9F4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8044F9F8: bne         $t9, $zero, L_8044FA10
    if (ctx->r25 != 0) {
        // 0x8044F9FC: nop
    
            goto L_8044FA10;
    }
    // 0x8044F9FC: nop

    // 0x8044FA00: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8044FA04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044FA08: b           L_8044FA28
    // 0x8044FA0C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8044FA28;
    // 0x8044FA0C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8044FA10:
    // 0x8044FA10: b           L_8044FA28
    // 0x8044FA14: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8044FA28;
    // 0x8044FA14: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8044FA18: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_8044FA1C:
    // 0x8044FA1C: nop

    // 0x8044FA20: bltz        $t9, L_8044FA10
    if (SIGNED(ctx->r25) < 0) {
        // 0x8044FA24: nop
    
            goto L_8044FA10;
    }
    // 0x8044FA24: nop

L_8044FA28:
    // 0x8044FA28: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8044FA2C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8044FA30: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8044FA34: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8044FA38: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8044FA3C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8044FA40: sub.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8044FA44: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8044FA48: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8044FA4C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8044FA50: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8044FA54: nop

    // 0x8044FA58: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8044FA5C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8044FA60: nop

    // 0x8044FA64: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8044FA68: beql        $t4, $zero, L_8044FAB8
    if (ctx->r12 == 0) {
        // 0x8044FA6C: mfc1        $t4, $f4
        ctx->r12 = (int32_t)ctx->f4.u32l;
            goto L_8044FAB8;
    }
    goto skip_8;
    // 0x8044FA6C: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    skip_8:
    // 0x8044FA70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8044FA74: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8044FA78: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8044FA7C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8044FA80: nop

    // 0x8044FA84: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8044FA88: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8044FA8C: nop

    // 0x8044FA90: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8044FA94: bne         $t4, $zero, L_8044FAAC
    if (ctx->r12 != 0) {
        // 0x8044FA98: nop
    
            goto L_8044FAAC;
    }
    // 0x8044FA98: nop

    // 0x8044FA9C: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8044FAA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044FAA4: b           L_8044FAC4
    // 0x8044FAA8: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8044FAC4;
    // 0x8044FAA8: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8044FAAC:
    // 0x8044FAAC: b           L_8044FAC4
    // 0x8044FAB0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8044FAC4;
    // 0x8044FAB0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8044FAB4: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
L_8044FAB8:
    // 0x8044FAB8: nop

    // 0x8044FABC: bltz        $t4, L_8044FAAC
    if (SIGNED(ctx->r12) < 0) {
        // 0x8044FAC0: nop
    
            goto L_8044FAAC;
    }
    // 0x8044FAC0: nop

L_8044FAC4:
    // 0x8044FAC4: sb          $t4, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r12;
    // 0x8044FAC8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8044FACC: addu        $t2, $v0, $t5
    ctx->r10 = ADD32(ctx->r2, ctx->r13);
    // 0x8044FAD0: addu        $t0, $v0, $t6
    ctx->r8 = ADD32(ctx->r2, ctx->r14);
    // 0x8044FAD4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8044FAD8: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8044FADC: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8044FAE0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8044FAE4: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8044FAE8: sub.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8044FAEC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8044FAF0: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8044FAF4: add.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8044FAF8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8044FAFC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8044FB00: nop

    // 0x8044FB04: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8044FB08: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8044FB0C: nop

    // 0x8044FB10: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8044FB14: beql        $t9, $zero, L_8044FB64
    if (ctx->r25 == 0) {
        // 0x8044FB18: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_8044FB64;
    }
    goto skip_9;
    // 0x8044FB18: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_9:
    // 0x8044FB1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8044FB20: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8044FB24: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8044FB28: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8044FB2C: nop

    // 0x8044FB30: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8044FB34: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8044FB38: nop

    // 0x8044FB3C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8044FB40: bne         $t9, $zero, L_8044FB58
    if (ctx->r25 != 0) {
        // 0x8044FB44: nop
    
            goto L_8044FB58;
    }
    // 0x8044FB44: nop

    // 0x8044FB48: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8044FB4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044FB50: b           L_8044FB70
    // 0x8044FB54: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8044FB70;
    // 0x8044FB54: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8044FB58:
    // 0x8044FB58: b           L_8044FB70
    // 0x8044FB5C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8044FB70;
    // 0x8044FB5C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8044FB60: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_8044FB64:
    // 0x8044FB64: nop

    // 0x8044FB68: bltz        $t9, L_8044FB58
    if (SIGNED(ctx->r25) < 0) {
        // 0x8044FB6C: nop
    
            goto L_8044FB58;
    }
    // 0x8044FB6C: nop

L_8044FB70:
    // 0x8044FB70: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x8044FB74: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8044FB78: lwc1        $f18, 0x4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8044FB7C: lwc1        $f2, 0x4($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8044FB80: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8044FB84: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8044FB88: sub.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x8044FB8C: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8044FB90: add.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8044FB94: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8044FB98: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8044FB9C: nop

    // 0x8044FBA0: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8044FBA4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8044FBA8: nop

    // 0x8044FBAC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8044FBB0: beql        $t4, $zero, L_8044FC00
    if (ctx->r12 == 0) {
        // 0x8044FBB4: mfc1        $t4, $f4
        ctx->r12 = (int32_t)ctx->f4.u32l;
            goto L_8044FC00;
    }
    goto skip_10;
    // 0x8044FBB4: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    skip_10:
    // 0x8044FBB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8044FBBC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8044FBC0: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8044FBC4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8044FBC8: nop

    // 0x8044FBCC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8044FBD0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8044FBD4: nop

    // 0x8044FBD8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8044FBDC: bne         $t4, $zero, L_8044FBF4
    if (ctx->r12 != 0) {
        // 0x8044FBE0: nop
    
            goto L_8044FBF4;
    }
    // 0x8044FBE0: nop

    // 0x8044FBE4: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8044FBE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044FBEC: b           L_8044FC0C
    // 0x8044FBF0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8044FC0C;
    // 0x8044FBF0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8044FBF4:
    // 0x8044FBF4: b           L_8044FC0C
    // 0x8044FBF8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8044FC0C;
    // 0x8044FBF8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8044FBFC: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
L_8044FC00:
    // 0x8044FC00: nop

    // 0x8044FC04: bltz        $t4, L_8044FBF4
    if (SIGNED(ctx->r12) < 0) {
        // 0x8044FC08: nop
    
            goto L_8044FBF4;
    }
    // 0x8044FC08: nop

L_8044FC0C:
    // 0x8044FC0C: sb          $t4, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r12;
    // 0x8044FC10: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8044FC14: lwc1        $f18, 0x8($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8044FC18: lwc1        $f14, 0x8($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8044FC1C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8044FC20: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8044FC24: sub.s       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x8044FC28: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8044FC2C: add.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x8044FC30: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8044FC34: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8044FC38: nop

    // 0x8044FC3C: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8044FC40: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8044FC44: nop

    // 0x8044FC48: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8044FC4C: beql        $t6, $zero, L_8044FC9C
    if (ctx->r14 == 0) {
        // 0x8044FC50: mfc1        $t6, $f4
        ctx->r14 = (int32_t)ctx->f4.u32l;
            goto L_8044FC9C;
    }
    goto skip_11;
    // 0x8044FC50: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    skip_11:
    // 0x8044FC54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8044FC58: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8044FC5C: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8044FC60: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8044FC64: nop

    // 0x8044FC68: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8044FC6C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8044FC70: nop

    // 0x8044FC74: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8044FC78: bne         $t6, $zero, L_8044FC90
    if (ctx->r14 != 0) {
        // 0x8044FC7C: nop
    
            goto L_8044FC90;
    }
    // 0x8044FC7C: nop

    // 0x8044FC80: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8044FC84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044FC88: b           L_8044FCA8
    // 0x8044FC8C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8044FCA8;
    // 0x8044FC8C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8044FC90:
    // 0x8044FC90: b           L_8044FCA8
    // 0x8044FC94: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8044FCA8;
    // 0x8044FC94: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8044FC98: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
L_8044FC9C:
    // 0x8044FC9C: nop

    // 0x8044FCA0: bltz        $t6, L_8044FC90
    if (SIGNED(ctx->r14) < 0) {
        // 0x8044FCA4: nop
    
            goto L_8044FC90;
    }
    // 0x8044FCA4: nop

L_8044FCA8:
    // 0x8044FCA8: sb          $t6, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r14;
    // 0x8044FCAC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8044FCB0: lwc1        $f18, 0xC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8044FCB4: lwc1        $f16, 0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8044FCB8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8044FCBC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8044FCC0: sub.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8044FCC4: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8044FCC8: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8044FCCC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8044FCD0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8044FCD4: nop

    // 0x8044FCD8: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8044FCDC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8044FCE0: nop

    // 0x8044FCE4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8044FCE8: beql        $t9, $zero, L_8044FD38
    if (ctx->r25 == 0) {
        // 0x8044FCEC: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_8044FD38;
    }
    goto skip_12;
    // 0x8044FCEC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_12:
    // 0x8044FCF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8044FCF4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8044FCF8: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8044FCFC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8044FD00: nop

    // 0x8044FD04: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8044FD08: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8044FD0C: nop

    // 0x8044FD10: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8044FD14: bne         $t9, $zero, L_8044FD2C
    if (ctx->r25 != 0) {
        // 0x8044FD18: nop
    
            goto L_8044FD2C;
    }
    // 0x8044FD18: nop

    // 0x8044FD1C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8044FD20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044FD24: b           L_8044FD44
    // 0x8044FD28: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8044FD44;
    // 0x8044FD28: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8044FD2C:
    // 0x8044FD2C: b           L_8044FD44
    // 0x8044FD30: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8044FD44;
    // 0x8044FD30: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8044FD34: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_8044FD38:
    // 0x8044FD38: nop

    // 0x8044FD3C: bltz        $t9, L_8044FD2C
    if (SIGNED(ctx->r25) < 0) {
        // 0x8044FD40: nop
    
            goto L_8044FD2C;
    }
    // 0x8044FD40: nop

L_8044FD44:
    // 0x8044FD44: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8044FD48: sb          $t9, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r25;
    // 0x8044FD4C: nop

L_8044FD50:
    // 0x8044FD50: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8044FD54: jr          $ra
    // 0x8044FD58: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8044FD58: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_8004457C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004457C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044584: jal         0x8005FE48
    // 0x80044588: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x80044588: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004458C: jal         0x800444D0
    // 0x80044590: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800444D0(rdram, ctx);
        goto after_1;
    // 0x80044590: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80044594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004459C: jr          $ra
    // 0x800445A0: nop

    return;
    // 0x800445A0: nop

;}
RECOMP_FUNC void func_807154D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807154D8: jr          $ra
    // 0x807154DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807154DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80428698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80428698: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042869C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804286A0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x804286A4: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x804286A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804286AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804286B0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804286B4: nop

    // 0x804286B8: bc1f        L_804286E4
    if (!c1cs) {
        // 0x804286BC: nop
    
            goto L_804286E4;
    }
    // 0x804286BC: nop

    // 0x804286C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804286C4: nop

    // 0x804286C8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804286CC: nop

    // 0x804286D0: bc1f        L_804286E4
    if (!c1cs) {
        // 0x804286D4: nop
    
            goto L_804286E4;
    }
    // 0x804286D4: nop

    // 0x804286D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x804286DC: b           L_804286F4
    // 0x804286E0: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
        goto L_804286F4;
    // 0x804286E0: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
L_804286E4:
    // 0x804286E4: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1ED0) << 16);
    // 0x804286E8: lwc1        $f10, -0x67F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1ED0));
    // 0x804286EC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x804286F0: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
L_804286F4:
    // 0x804286F4: jal         0x80427AC0
    // 0x804286F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80427AC0(rdram, ctx);
        goto after_0;
    // 0x804286F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804286FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80428700: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1ED4) << 16);
    // 0x80428704: lwc1        $f18, -0x67EC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1ED4));
    // 0x80428708: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8042870C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80428710: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1ED8) << 16);
    // 0x80428714: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80428718: nop

    // 0x8042871C: bc1fl       L_80428738
    if (!c1cs) {
        // 0x80428720: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80428738;
    }
    goto skip_0;
    // 0x80428720: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x80428724: lwc1        $f4, -0x67E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1ED8));
    // 0x80428728: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8042872C: b           L_80428740
    // 0x80428730: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
        goto L_80428740;
    // 0x80428730: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80428734: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80428738:
    // 0x80428738: nop

    // 0x8042873C: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
L_80428740:
    // 0x80428740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80428744: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80428748: jr          $ra
    // 0x8042874C: nop

    return;
    // 0x8042874C: nop

;}
RECOMP_FUNC void func_8043535C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043535C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80435360: lw          $t6, 0x134C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X134C);
    // 0x80435364: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80435368: slti        $at, $t7, 0x32
    ctx->r1 = SIGNED(ctx->r15) < 0X32 ? 1 : 0;
    // 0x8043536C: bne         $at, $zero, L_80435378
    if (ctx->r1 != 0) {
        // 0x80435370: sw          $t7, 0x134C($v0)
        MEM_W(0X134C, ctx->r2) = ctx->r15;
            goto L_80435378;
    }
    // 0x80435370: sw          $t7, 0x134C($v0)
    MEM_W(0X134C, ctx->r2) = ctx->r15;
    // 0x80435374: sw          $zero, 0x134C($v0)
    MEM_W(0X134C, ctx->r2) = 0;
L_80435378:
    // 0x80435378: jr          $ra
    // 0x8043537C: nop

    return;
    // 0x8043537C: nop

;}
RECOMP_FUNC void func_804CEC20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CEC20: jr          $ra
    // 0x804CEC24: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804CEC24: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805197F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805197F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805197F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805197F8: jal         0x80519668
    // 0x805197FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80519668(rdram, ctx);
        goto after_0;
    // 0x805197FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80519800: jal         0x800447C8
    // 0x80519804: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x80519804: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80519808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051980C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80519810: jr          $ra
    // 0x80519814: nop

    return;
    // 0x80519814: nop

;}
RECOMP_FUNC void func_80448960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448960: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80448964: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80448968: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8044896C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80448970: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x80448974: addiu       $t0, $zero, 0x1B6C
    ctx->r8 = ADD32(0, 0X1B6C);
    // 0x80448978: subu        $t1, $t0, $a3
    ctx->r9 = SUB32(ctx->r8, ctx->r7);
    // 0x8044897C: lw          $t7, 0x18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18);
    // 0x80448980: subu        $t8, $t7, $a3
    ctx->r24 = SUB32(ctx->r15, ctx->r7);
    // 0x80448984: slti        $at, $t8, 0x3C0
    ctx->r1 = SIGNED(ctx->r24) < 0X3C0 ? 1 : 0;
    // 0x80448988: beq         $at, $zero, L_80448994
    if (ctx->r1 == 0) {
        // 0x8044898C: sw          $t8, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r24;
            goto L_80448994;
    }
    // 0x8044898C: sw          $t8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r24;
    // 0x80448990: sw          $t1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r9;
L_80448994:
    // 0x80448994: jr          $ra
    // 0x80448998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80448998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_804C5CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C5CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C5CC0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804C5CC4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804C5CC8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804C5CCC: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(215, 0X4BC) << 16);
    // 0x804C5CD0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C5CD4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804C5CD8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804C5CDC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804C5CE0: lw          $t8, 0x5ECC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(215, 0X4BC));
    // 0x804C5CE4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804C5CE8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804C5CEC: jal         0x80048490
    // 0x804C5CF0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804C5CF0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804C5CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C5CF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C5CFC: jr          $ra
    // 0x804C5D00: nop

    return;
    // 0x804C5D00: nop

;}
RECOMP_FUNC void func_804CE2B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE2B0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x804CE2B4: addiu       $at, $zero, 0x4123
    ctx->r1 = ADD32(0, 0X4123);
    // 0x804CE2B8: beq         $v0, $at, L_804CE2E0
    if (ctx->r2 == ctx->r1) {
        // 0x804CE2BC: addiu       $at, $zero, 0x4124
        ctx->r1 = ADD32(0, 0X4124);
            goto L_804CE2E0;
    }
    // 0x804CE2BC: addiu       $at, $zero, 0x4124
    ctx->r1 = ADD32(0, 0X4124);
    // 0x804CE2C0: beq         $v0, $at, L_804CE2F8
    if (ctx->r2 == ctx->r1) {
        // 0x804CE2C4: addiu       $at, $zero, 0x4125
        ctx->r1 = ADD32(0, 0X4125);
            goto L_804CE2F8;
    }
    // 0x804CE2C4: addiu       $at, $zero, 0x4125
    ctx->r1 = ADD32(0, 0X4125);
    // 0x804CE2C8: beq         $v0, $at, L_804CE304
    if (ctx->r2 == ctx->r1) {
        // 0x804CE2CC: addiu       $at, $zero, 0x4126
        ctx->r1 = ADD32(0, 0X4126);
            goto L_804CE304;
    }
    // 0x804CE2CC: addiu       $at, $zero, 0x4126
    ctx->r1 = ADD32(0, 0X4126);
    // 0x804CE2D0: beq         $v0, $at, L_804CE2EC
    if (ctx->r2 == ctx->r1) {
        // 0x804CE2D4: nop
    
            goto L_804CE2EC;
    }
    // 0x804CE2D4: nop

    // 0x804CE2D8: b           L_804CE310
    // 0x804CE2DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CE310;
    // 0x804CE2DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CE2E0:
    // 0x804CE2E0: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(240, 0X678) << 16);
    // 0x804CE2E4: jr          $ra
    // 0x804CE2E8: addiu       $v0, $v0, -0x16D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(240, 0X678));
    return;
    // 0x804CE2E8: addiu       $v0, $v0, -0x16D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(240, 0X678));
L_804CE2EC:
    // 0x804CE2EC: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(240, 0X978) << 16);
    // 0x804CE2F0: jr          $ra
    // 0x804CE2F4: addiu       $v0, $v0, -0x13D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(240, 0X978));
    return;
    // 0x804CE2F4: addiu       $v0, $v0, -0x13D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(240, 0X978));
L_804CE2F8:
    // 0x804CE2F8: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(240, 0X1000) << 16);
    // 0x804CE2FC: jr          $ra
    // 0x804CE300: addiu       $v0, $v0, -0xD50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(240, 0X1000));
    return;
    // 0x804CE300: addiu       $v0, $v0, -0xD50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(240, 0X1000));
L_804CE304:
    // 0x804CE304: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(240, 0X184C) << 16);
    // 0x804CE308: jr          $ra
    // 0x804CE30C: addiu       $v0, $v0, -0x504
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(240, 0X184C));
    return;
    // 0x804CE30C: addiu       $v0, $v0, -0x504
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(240, 0X184C));
L_804CE310:
    // 0x804CE310: jr          $ra
    // 0x804CE314: nop

    return;
    // 0x804CE314: nop

;}
RECOMP_FUNC void func_8051ED2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051ED2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051ED30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051ED34: lw          $t6, 0x198($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X198);
    // 0x8051ED38: lw          $v1, 0x16C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X16C);
    // 0x8051ED3C: lbu         $v0, 0x10($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X10);
    // 0x8051ED40: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8051ED44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8051ED48: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8051ED4C: jal         0x8051EC54
    // 0x8051ED50: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8051EC54(rdram, ctx);
        goto after_0;
    // 0x8051ED50: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x8051ED54: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8051ED58: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8051ED5C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8051ED60: addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // 0x8051ED64: bgtzl       $v0, L_8051ED7C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8051ED68: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_8051ED7C;
    }
    goto skip_0;
    // 0x8051ED68: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8051ED6C: jal         0x8051EF30
    // 0x8051ED70: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_8051EF30(rdram, ctx);
        goto after_1;
    // 0x8051ED70: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
    // 0x8051ED74: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8051ED78: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_8051ED7C:
    // 0x8051ED7C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8051ED80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8051ED84: sb          $v0, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r2;
    // 0x8051ED88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051ED8C: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x8051ED90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051ED94: jr          $ra
    // 0x8051ED98: nop

    return;
    // 0x8051ED98: nop

;}
RECOMP_FUNC void func_8044A894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A894: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8044A898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A89C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044A8A0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A8A4: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044A8A8: lw          $a1, 0x6A54($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X6A54);
    // 0x8044A8AC: beq         $a1, $zero, L_8044A8C4
    if (ctx->r5 == 0) {
        // 0x8044A8B0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044A8C4;
    }
    // 0x8044A8B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044A8B4: jal         0x80050A2C
    // 0x8044A8B8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80050A2C(rdram, ctx);
        goto after_0;
    // 0x8044A8B8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044A8BC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A8C0: sw          $zero, 0x6A54($v1)
    MEM_W(0X6A54, ctx->r3) = 0;
L_8044A8C4:
    // 0x8044A8C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044A8C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8044A8CC: jr          $ra
    // 0x8044A8D0: nop

    return;
    // 0x8044A8D0: nop

;}
RECOMP_FUNC void func_806F6F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F6F64: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F6F68: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806F6F6C: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(691, 0X938) << 16);
    // 0x806F6F70: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806F6F74: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806F6F78: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806F6F7C: nop

    // 0x806F6F80: bc1fl       L_806F6FC0
    if (!c1cs) {
        // 0x806F6F84: lwc1        $f0, 0x4($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
            goto L_806F6FC0;
    }
    goto skip_0;
    // 0x806F6F84: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x806F6F88: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806F6F8C: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(691, 0X930) << 16);
    // 0x806F6F90: lwc1        $f8, 0x76C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(691, 0X930));
    // 0x806F6F94: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806F6F98: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(691, 0X934) << 16);
    // 0x806F6F9C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x806F6FA0: nop

    // 0x806F6FA4: bc1f        L_806F6FE4
    if (!c1cs) {
        // 0x806F6FA8: nop
    
            goto L_806F6FE4;
    }
    // 0x806F6FA8: nop

    // 0x806F6FAC: lwc1        $f10, 0x76C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(691, 0X934));
    // 0x806F6FB0: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x806F6FB4: jr          $ra
    // 0x806F6FB8: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x806F6FB8: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x806F6FBC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
L_806F6FC0:
    // 0x806F6FC0: lwc1        $f18, 0x76C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(691, 0X938));
    // 0x806F6FC4: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(691, 0X93C) << 16);
    // 0x806F6FC8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x806F6FCC: nop

    // 0x806F6FD0: bc1f        L_806F6FE4
    if (!c1cs) {
        // 0x806F6FD4: nop
    
            goto L_806F6FE4;
    }
    // 0x806F6FD4: nop

    // 0x806F6FD8: lwc1        $f4, 0x76CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(691, 0X93C));
    // 0x806F6FDC: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x806F6FE0: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
L_806F6FE4:
    // 0x806F6FE4: jr          $ra
    // 0x806F6FE8: nop

    return;
    // 0x806F6FE8: nop

;}
RECOMP_FUNC void func_804CF4E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF4E4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CF4E8: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B40) << 16);
    // 0x804CF4EC: lwc1        $f4, -0x210($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B40));
    // 0x804CF4F0: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804CF4F4: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x804CF4F8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x804CF4FC: nop

    // 0x804CF500: bc1fl       L_804CF518
    if (!c1cs) {
        // 0x804CF504: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_804CF518;
    }
    goto skip_0;
    // 0x804CF504: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x804CF508: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804CF50C: jr          $ra
    // 0x804CF510: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x804CF510: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x804CF514: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_804CF518:
    // 0x804CF518: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B4C) << 16);
    // 0x804CF51C: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x804CF520: nop

    // 0x804CF524: bc1f        L_804CF560
    if (!c1cs) {
        // 0x804CF528: nop
    
            goto L_804CF560;
    }
    // 0x804CF528: nop

    // 0x804CF52C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B44) << 16);
    // 0x804CF530: lwc1        $f0, -0x20C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B44));
    // 0x804CF534: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B48) << 16);
    // 0x804CF538: lwc1        $f10, -0x208($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B48));
    // 0x804CF53C: sub.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x804CF540: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x804CF544: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804CF548: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x804CF54C: nop

    // 0x804CF550: bc1f        L_804CF58C
    if (!c1cs) {
        // 0x804CF554: nop
    
            goto L_804CF58C;
    }
    // 0x804CF554: nop

    // 0x804CF558: jr          $ra
    // 0x804CF55C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x804CF55C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_804CF560:
    // 0x804CF560: lwc1        $f0, -0x204($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B4C));
    // 0x804CF564: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B50) << 16);
    // 0x804CF568: lwc1        $f4, -0x200($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B50));
    // 0x804CF56C: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x804CF570: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x804CF574: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804CF578: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x804CF57C: nop

    // 0x804CF580: bc1f        L_804CF58C
    if (!c1cs) {
        // 0x804CF584: nop
    
            goto L_804CF58C;
    }
    // 0x804CF584: nop

    // 0x804CF588: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_804CF58C:
    // 0x804CF58C: jr          $ra
    // 0x804CF590: nop

    return;
    // 0x804CF590: nop

;}
RECOMP_FUNC void func_804BD698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD698: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(191, 0X1E3C) << 16);
    // 0x804BD69C: addiu       $t6, $t6, -0x2894
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(191, 0X1E3C));
    // 0x804BD6A0: sh          $zero, 0x30($a0)
    MEM_H(0X30, ctx->r4) = 0;
    // 0x804BD6A4: jr          $ra
    // 0x804BD6A8: sw          $t6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r14;
    return;
    // 0x804BD6A8: sw          $t6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8067F674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067F674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067F678: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8067F67C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8067F680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067F684: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    // 0x8067F688: jal         0x80067878
    // 0x8067F68C: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8067F68C: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    after_0:
    // 0x8067F690: jal         0x80045BD8
    // 0x8067F694: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8067F694: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8067F698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067F69C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067F6A0: jr          $ra
    // 0x8067F6A4: nop

    return;
    // 0x8067F6A4: nop

;}
RECOMP_FUNC void func_80037244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037244: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003724C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80037250: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80037254: lw          $t6, 0x78($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X78);
    // 0x80037258: beq         $t6, $zero, L_80037270
    if (ctx->r14 == 0) {
        // 0x8003725C: nop
    
            goto L_80037270;
    }
    // 0x8003725C: nop

    // 0x80037260: jal         0x80035C80
    // 0x80037264: nop

    func_80035C80(rdram, ctx);
        goto after_0;
    // 0x80037264: nop

    after_0:
    // 0x80037268: b           L_80037270
    // 0x8003726C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037270;
    // 0x8003726C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037270:
    // 0x80037270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80037278: jr          $ra
    // 0x8003727C: nop

    return;
    // 0x8003727C: nop

;}
RECOMP_FUNC void func_804A1604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1604: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804A1608: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804A160C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804A1610: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804A1614: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x804A1618: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804A161C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x804A1620: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x804A1624: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804A1628: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x804A162C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804A1630: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x804A1634: jal         0x800653D8
    // 0x804A1638: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x804A1638: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x804A163C: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x804A1640: bne         $t8, $zero, L_804A1650
    if (ctx->r24 != 0) {
        // 0x804A1644: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_804A1650;
    }
    // 0x804A1644: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x804A1648: b           L_804A17F0
    // 0x804A164C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_804A17F0;
    // 0x804A164C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_804A1650:
    // 0x804A1650: jal         0x800653D8
    // 0x804A1654: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x804A1654: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x804A1658: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x804A165C: beq         $t9, $zero, L_804A1744
    if (ctx->r25 == 0) {
        // 0x804A1660: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_804A1744;
    }
    // 0x804A1660: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x804A1664: lw          $v0, 0x138($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X138);
    // 0x804A1668: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X301C) << 16);
    // 0x804A166C: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x804A1670: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x804A1674: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804A1678: lwc1        $f8, 0x345C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X301C));
    // 0x804A167C: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X303C) << 16);
    // 0x804A1680: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804A1684: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804A1688: lwc1        $f18, 0x347C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X303C));
    // 0x804A168C: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x804A1690: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X3180) << 16);
    // 0x804A1694: lwc1        $f8, 0x35C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X3180));
    // 0x804A1698: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x804A169C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804A16A0: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804A16A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A16A8: add.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x804A16AC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804A16B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x804A16B4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x804A16B8: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x804A16BC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x804A16C0: jal         0x804A1320
    // 0x804A16C4: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    func_804A1320(rdram, ctx);
        goto after_2;
    // 0x804A16C4: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x804A16C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x804A16CC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804A16D0: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x804A16D4: nop

    // 0x804A16D8: bc1f        L_804A16F0
    if (!c1cs) {
        // 0x804A16DC: nop
    
            goto L_804A16F0;
    }
    // 0x804A16DC: nop

    // 0x804A16E0: jal         0x804A1590
    // 0x804A16E4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    func_804A1590(rdram, ctx);
        goto after_3;
    // 0x804A16E4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x804A16E8: beq         $v0, $zero, L_804A1730
    if (ctx->r2 == 0) {
        // 0x804A16EC: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_804A1730;
    }
    // 0x804A16EC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_804A16F0:
    // 0x804A16F0: jal         0x800653D8
    // 0x804A16F4: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x804A16F4: nop

    after_4:
    // 0x804A16F8: andi        $t0, $v0, 0x3
    ctx->r8 = ctx->r2 & 0X3;
    // 0x804A16FC: beq         $t0, $zero, L_804A171C
    if (ctx->r8 == 0) {
        // 0x804A1700: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_804A171C;
    }
    // 0x804A1700: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x804A1704: beq         $t1, $zero, L_804A1714
    if (ctx->r9 == 0) {
        // 0x804A1708: nop
    
            goto L_804A1714;
    }
    // 0x804A1708: nop

    // 0x804A170C: b           L_804A1734
    // 0x804A1710: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_804A1734;
    // 0x804A1710: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_804A1714:
    // 0x804A1714: b           L_804A1734
    // 0x804A1718: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
        goto L_804A1734;
    // 0x804A1718: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
L_804A171C:
    // 0x804A171C: jal         0x800653D8
    // 0x804A1720: nop

    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x804A1720: nop

    after_5:
    // 0x804A1724: andi        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 & 0X1;
    // 0x804A1728: b           L_804A1734
    // 0x804A172C: addiu       $v1, $v1, 0x9
    ctx->r3 = ADD32(ctx->r3, 0X9);
        goto L_804A1734;
    // 0x804A172C: addiu       $v1, $v1, 0x9
    ctx->r3 = ADD32(ctx->r3, 0X9);
L_804A1730:
    // 0x804A1730: addiu       $v1, $v1, 0xB
    ctx->r3 = ADD32(ctx->r3, 0XB);
L_804A1734:
    // 0x804A1734: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x804A1738: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x804A173C: b           L_804A17F0
    // 0x804A1740: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
        goto L_804A17F0;
    // 0x804A1740: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_804A1744:
    // 0x804A1744: jal         0x800653D8
    // 0x804A1748: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_6;
    // 0x804A1748: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_6:
    // 0x804A174C: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x804A1750: beq         $t4, $zero, L_804A1778
    if (ctx->r12 == 0) {
        // 0x804A1754: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_804A1778;
    }
    // 0x804A1754: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x804A1758: jal         0x800653D8
    // 0x804A175C: nop

    func_800653D8(rdram, ctx);
        goto after_7;
    // 0x804A175C: nop

    after_7:
    // 0x804A1760: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
    // 0x804A1764: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x804A1768: addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
    // 0x804A176C: xor         $t7, $t5, $t6
    ctx->r15 = ctx->r13 ^ ctx->r14;
    // 0x804A1770: b           L_804A17F0
    // 0x804A1774: sw          $t7, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r15;
        goto L_804A17F0;
    // 0x804A1774: sw          $t7, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r15;
L_804A1778:
    // 0x804A1778: jal         0x800653D8
    // 0x804A177C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_8;
    // 0x804A177C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_8:
    // 0x804A1780: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x804A1784: beq         $t8, $zero, L_804A1794
    if (ctx->r24 == 0) {
        // 0x804A1788: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_804A1794;
    }
    // 0x804A1788: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x804A178C: b           L_804A17F0
    // 0x804A1790: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_804A17F0;
    // 0x804A1790: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_804A1794:
    // 0x804A1794: jal         0x800653D8
    // 0x804A1798: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_9;
    // 0x804A1798: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_9:
    // 0x804A179C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x804A17A0: beq         $t9, $zero, L_804A17F0
    if (ctx->r25 == 0) {
        // 0x804A17A4: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_804A17F0;
    }
    // 0x804A17A4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x804A17A8: jal         0x800653D8
    // 0x804A17AC: nop

    func_800653D8(rdram, ctx);
        goto after_10;
    // 0x804A17AC: nop

    after_10:
    // 0x804A17B0: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x804A17B4: beq         $t0, $zero, L_804A17E0
    if (ctx->r8 == 0) {
        // 0x804A17B8: nop
    
            goto L_804A17E0;
    }
    // 0x804A17B8: nop

    // 0x804A17BC: jal         0x800653D8
    // 0x804A17C0: nop

    func_800653D8(rdram, ctx);
        goto after_11;
    // 0x804A17C0: nop

    after_11:
    // 0x804A17C4: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x804A17C8: beq         $t1, $zero, L_804A17D8
    if (ctx->r9 == 0) {
        // 0x804A17CC: nop
    
            goto L_804A17D8;
    }
    // 0x804A17CC: nop

    // 0x804A17D0: b           L_804A17F0
    // 0x804A17D4: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_804A17F0;
    // 0x804A17D4: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_804A17D8:
    // 0x804A17D8: b           L_804A17F0
    // 0x804A17DC: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
        goto L_804A17F0;
    // 0x804A17DC: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
L_804A17E0:
    // 0x804A17E0: jal         0x800653D8
    // 0x804A17E4: nop

    func_800653D8(rdram, ctx);
        goto after_12;
    // 0x804A17E4: nop

    after_12:
    // 0x804A17E8: andi        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 & 0X1;
    // 0x804A17EC: addiu       $v1, $v1, 0x9
    ctx->r3 = ADD32(ctx->r3, 0X9);
L_804A17F0:
    // 0x804A17F0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x804A17F4: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x804A17F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A17FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A1800: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    // 0x804A1804: jal         0x804A27A0
    // 0x804A1808: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    func_804A27A0(rdram, ctx);
        goto after_13;
    // 0x804A1808: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    after_13:
    // 0x804A180C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804A1810: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804A1814: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804A1818: jr          $ra
    // 0x804A181C: nop

    return;
    // 0x804A181C: nop

;}
RECOMP_FUNC void func_804BD098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BD09C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD0A0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804BD0A4: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(191, 0X18C0) << 16);
    // 0x804BD0A8: addiu       $t6, $t6, -0x2E10
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(191, 0X18C0));
    // 0x804BD0AC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804BD0B0: jal         0x8005FDC4
    // 0x804BD0B4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    func_8005FDC4(rdram, ctx);
        goto after_0;
    // 0x804BD0B4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    after_0:
    // 0x804BD0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BD0BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BD0C0: jr          $ra
    // 0x804BD0C4: nop

    return;
    // 0x804BD0C4: nop

;}
RECOMP_FUNC void func_80052674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052674: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80052678: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005267C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80052680: jal         0x8007C61C
    // 0x80052684: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    func_8007C61C(rdram, ctx);
        goto after_0;
    // 0x80052684: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80052688: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005268C: addiu       $a0, $a0, -0x4D70
    ctx->r4 = ADD32(ctx->r4, -0X4D70);
    // 0x80052690: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80052694: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80052698: jal         0x8008DCB0
    // 0x8005269C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    osPfsFileState_recomp(rdram, ctx);
        goto after_1;
    // 0x8005269C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x800526A0: beq         $v0, $zero, L_800526B8
    if (ctx->r2 == 0) {
        // 0x800526A4: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_800526B8;
    }
    // 0x800526A4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800526A8: jal         0x8007C640
    // 0x800526AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8007C640(rdram, ctx);
        goto after_2;
    // 0x800526AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x800526B0: b           L_80052788
    // 0x800526B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80052788;
    // 0x800526B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800526B8:
    // 0x800526B8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800526BC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800526C0: addiu       $v1, $sp, 0x30
    ctx->r3 = ADD32(ctx->r29, 0X30);
    // 0x800526C4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800526C8: sra         $a1, $a1, 8
    ctx->r5 = S32(SIGNED(ctx->r5) >> 8);
L_800526CC:
    // 0x800526CC: lbu         $t6, 0xE($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XE);
    // 0x800526D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800526D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800526D8: sb          $t6, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r14;
    // 0x800526DC: lbu         $t7, 0xB($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XB);
    // 0x800526E0: sb          $t7, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r15;
    // 0x800526E4: lbu         $t8, 0xC($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XC);
    // 0x800526E8: sb          $t8, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r24;
    // 0x800526EC: lbu         $t9, 0xD($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XD);
    // 0x800526F0: bne         $v1, $a0, L_800526CC
    if (ctx->r3 != ctx->r4) {
        // 0x800526F4: sb          $t9, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r25;
            goto L_800526CC;
    }
    // 0x800526F4: sb          $t9, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r25;
    // 0x800526F8: lbu         $t0, 0x3A($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3A);
    // 0x800526FC: lbu         $t1, 0x3B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3B);
    // 0x80052700: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x80052704: bnel        $t0, $zero, L_80052738
    if (ctx->r8 != 0) {
        // 0x80052708: lbu         $t4, 0x0($v0)
        ctx->r12 = MEM_BU(ctx->r2, 0X0);
            goto L_80052738;
    }
    goto skip_0;
    // 0x80052708: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    skip_0:
    // 0x8005270C: bne         $t1, $zero, L_80052734
    if (ctx->r9 != 0) {
        // 0x80052710: lbu         $t2, 0x3C($sp)
        ctx->r10 = MEM_BU(ctx->r29, 0X3C);
            goto L_80052734;
    }
    // 0x80052710: lbu         $t2, 0x3C($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3C);
    // 0x80052714: bne         $t2, $zero, L_80052734
    if (ctx->r10 != 0) {
        // 0x80052718: lbu         $t3, 0x3D($sp)
        ctx->r11 = MEM_BU(ctx->r29, 0X3D);
            goto L_80052734;
    }
    // 0x80052718: lbu         $t3, 0x3D($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3D);
    // 0x8005271C: bne         $t3, $zero, L_80052734
    if (ctx->r11 != 0) {
        // 0x80052720: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80052734;
    }
    // 0x80052720: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80052724: jal         0x8007C640
    // 0x80052728: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8007C640(rdram, ctx);
        goto after_3;
    // 0x80052728: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_3:
    // 0x8005272C: b           L_80052788
    // 0x80052730: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_80052788;
    // 0x80052730: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80052734:
    // 0x80052734: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
L_80052738:
    // 0x80052738: bnel        $t4, $zero, L_80052754
    if (ctx->r12 != 0) {
        // 0x8005273C: sb          $t6, 0x1($v0)
        MEM_B(0X1, ctx->r2) = ctx->r14;
            goto L_80052754;
    }
    goto skip_1;
    // 0x8005273C: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    skip_1:
    // 0x80052740: lbu         $t5, -0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X1);
L_80052744:
    // 0x80052744: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80052748: beql        $t5, $zero, L_80052744
    if (ctx->r13 == 0) {
        // 0x8005274C: lbu         $t5, -0x1($v0)
        ctx->r13 = MEM_BU(ctx->r2, -0X1);
            goto L_80052744;
    }
    goto skip_2;
    // 0x8005274C: lbu         $t5, -0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X1);
    skip_2:
    // 0x80052750: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
L_80052754:
    // 0x80052754: lbu         $t7, 0x3A($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3A);
    // 0x80052758: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x8005275C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80052760: sb          $t7, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r15;
    // 0x80052764: lbu         $t8, 0x3B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3B);
    // 0x80052768: sb          $t8, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r24;
    // 0x8005276C: lbu         $t9, 0x3C($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3C);
    // 0x80052770: sb          $t9, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r25;
    // 0x80052774: lbu         $t0, 0x3D($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3D);
    // 0x80052778: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x8005277C: jal         0x8007C640
    // 0x80052780: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8007C640(rdram, ctx);
        goto after_4;
    // 0x80052780: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x80052784: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80052788:
    // 0x80052788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005278C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80052790: jr          $ra
    // 0x80052794: nop

    return;
    // 0x80052794: nop

;}
RECOMP_FUNC void func_8001BDB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BDB4: beq         $a0, $zero, L_8001BE20
    if (ctx->r4 == 0) {
        // 0x8001BDB8: nop
    
            goto L_8001BE20;
    }
    // 0x8001BDB8: nop

    // 0x8001BDBC: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8001BDC0: beq         $v0, $zero, L_8001BE20
    if (ctx->r2 == 0) {
        // 0x8001BDC4: nop
    
            goto L_8001BE20;
    }
    // 0x8001BDC4: nop

    // 0x8001BDC8: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x8001BDCC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001BDD0: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8001BDD4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8001BDD8: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001BDDC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001BDE0: c.eq.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl == ctx->f6.fl;
    // 0x8001BDE4: nop

    // 0x8001BDE8: bc1fl       L_8001BDFC
    if (!c1cs) {
        // 0x8001BDEC: sub.s       $f8, $f0, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8001BDFC;
    }
    goto skip_0;
    // 0x8001BDEC: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x8001BDF0: b           L_8001BE14
    // 0x8001BDF4: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
        goto L_8001BE14;
    // 0x8001BDF4: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x8001BDF8: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
L_8001BDFC:
    // 0x8001BDFC: div.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8001BE00: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8001BE04: swc1        $f16, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f16.u32l;
    // 0x8001BE08: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x8001BE0C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8001BE10: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
L_8001BE14:
    // 0x8001BE14: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8001BE18: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x8001BE1C: swc1        $f18, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f18.u32l;
L_8001BE20:
    // 0x8001BE20: jr          $ra
    // 0x8001BE24: nop

    return;
    // 0x8001BE24: nop

    // 0x8001BE28: nop

    // 0x8001BE2C: nop

;}
RECOMP_FUNC void func_80053A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053A20: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80053A24: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80053A28: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x80053A2C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80053A30: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80053A34: multu       $a3, $s0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80053A38: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80053A3C: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80053A40: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80053A44: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80053A48: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80053A4C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80053A50: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80053A54: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80053A58: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x80053A5C: mflo        $s2
    ctx->r18 = lo;
    // 0x80053A60: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80053A64: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80053A68: bgez        $s2, L_80053A74
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80053A6C: addu        $at, $s2, $zero
        ctx->r1 = ADD32(ctx->r18, 0);
            goto L_80053A74;
    }
    // 0x80053A6C: addu        $at, $s2, $zero
    ctx->r1 = ADD32(ctx->r18, 0);
    // 0x80053A70: addiu       $at, $s2, 0x1
    ctx->r1 = ADD32(ctx->r18, 0X1);
L_80053A74:
    // 0x80053A74: sra         $s2, $at, 1
    ctx->r18 = S32(SIGNED(ctx->r1) >> 1);
    // 0x80053A78: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80053A7C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80053A80: blez        $s0, L_80053C1C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80053A84: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80053C1C;
    }
    // 0x80053A84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80053A88: negu        $t6, $s4
    ctx->r14 = SUB32(0, ctx->r20);
    // 0x80053A8C: multu       $t6, $s6
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80053A90: addiu       $s5, $zero, 0x6
    ctx->r21 = ADD32(0, 0X6);
    // 0x80053A94: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x80053A98: mflo        $t7
    ctx->r15 = lo;
    // 0x80053A9C: bgez        $t7, L_80053AAC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80053AA0: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_80053AAC;
    }
    // 0x80053AA0: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80053AA4: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x80053AA8: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80053AAC:
    // 0x80053AAC: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80053AB0:
    // 0x80053AB0: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80053AB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80053AB8: blez        $s6, L_80053C0C
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80053ABC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80053C0C;
    }
    // 0x80053ABC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80053AC0: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80053AC4: addu        $s0, $ra, $fp
    ctx->r16 = ADD32(ctx->r31, ctx->r30);
    // 0x80053AC8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80053ACC: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x80053AD0: sll         $s0, $s0, 6
    ctx->r16 = S32(ctx->r16 << 6);
    // 0x80053AD4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80053AD8: sll         $t4, $ra, 6
    ctx->r12 = S32(ctx->r31 << 6);
    // 0x80053ADC: subu        $t5, $s2, $fp
    ctx->r13 = SUB32(ctx->r18, ctx->r30);
    // 0x80053AE0: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
L_80053AE4:
    // 0x80053AE4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80053AE8: sll         $t0, $a2, 6
    ctx->r8 = S32(ctx->r6 << 6);
    // 0x80053AEC: addu        $t1, $a2, $s4
    ctx->r9 = ADD32(ctx->r6, ctx->r20);
    // 0x80053AF0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80053AF4: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x80053AF8: addu        $v0, $t7, $s7
    ctx->r2 = ADD32(ctx->r15, ctx->r23);
    // 0x80053AFC: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x80053B00: sh          $s2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r18;
    // 0x80053B04: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80053B08: sh          $s5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r21;
    // 0x80053B0C: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
    // 0x80053B10: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x80053B14: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80053B18: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80053B1C: sll         $t2, $t2, 6
    ctx->r10 = S32(ctx->r10 << 6);
    // 0x80053B20: sb          $t8, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r24;
    // 0x80053B24: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x80053B28: addu        $a1, $t3, $s4
    ctx->r5 = ADD32(ctx->r11, ctx->r20);
    // 0x80053B2C: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x80053B30: sb          $t9, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r25;
    // 0x80053B34: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x80053B38: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80053B3C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80053B40: sb          $t6, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r14;
    // 0x80053B44: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
    // 0x80053B48: sh          $t4, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r12;
    // 0x80053B4C: sh          $t2, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r10;
    // 0x80053B50: sh          $zero, 0x16($v0)
    MEM_H(0X16, ctx->r2) = 0;
    // 0x80053B54: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
    // 0x80053B58: sh          $s2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r18;
    // 0x80053B5C: sh          $a1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r5;
    // 0x80053B60: sb          $t7, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r15;
    // 0x80053B64: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80053B68: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80053B6C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80053B70: sb          $t8, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r24;
    // 0x80053B74: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x80053B78: sb          $t9, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r25;
    // 0x80053B7C: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x80053B80: sb          $t6, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r14;
    // 0x80053B84: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
    // 0x80053B88: sb          $t7, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r15;
    // 0x80053B8C: sh          $s0, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r16;
    // 0x80053B90: sh          $t0, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r8;
    // 0x80053B94: sh          $zero, 0x26($v0)
    MEM_H(0X26, ctx->r2) = 0;
    // 0x80053B98: sh          $zero, 0x24($v0)
    MEM_H(0X24, ctx->r2) = 0;
    // 0x80053B9C: sh          $t5, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r13;
    // 0x80053BA0: sh          $t3, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r11;
    // 0x80053BA4: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80053BA8: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x80053BAC: sb          $t8, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = ctx->r24;
    // 0x80053BB0: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x80053BB4: sb          $t9, 0x2D($v0)
    MEM_B(0X2D, ctx->r2) = ctx->r25;
    // 0x80053BB8: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x80053BBC: sb          $t6, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r14;
    // 0x80053BC0: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
    // 0x80053BC4: sh          $s0, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r16;
    // 0x80053BC8: sh          $t2, 0x38($v0)
    MEM_H(0X38, ctx->r2) = ctx->r10;
    // 0x80053BCC: sh          $zero, 0x36($v0)
    MEM_H(0X36, ctx->r2) = 0;
    // 0x80053BD0: sh          $zero, 0x34($v0)
    MEM_H(0X34, ctx->r2) = 0;
    // 0x80053BD4: sh          $t5, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r13;
    // 0x80053BD8: sh          $a1, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r5;
    // 0x80053BDC: sb          $t7, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r15;
    // 0x80053BE0: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80053BE4: sb          $t8, 0x3C($v0)
    MEM_B(0X3C, ctx->r2) = ctx->r24;
    // 0x80053BE8: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x80053BEC: sb          $t9, 0x3D($v0)
    MEM_B(0X3D, ctx->r2) = ctx->r25;
    // 0x80053BF0: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x80053BF4: sb          $t6, 0x3E($v0)
    MEM_B(0X3E, ctx->r2) = ctx->r14;
    // 0x80053BF8: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
    // 0x80053BFC: bne         $s1, $s6, L_80053AE4
    if (ctx->r17 != ctx->r22) {
        // 0x80053C00: sb          $t7, 0x3F($v0)
        MEM_B(0X3F, ctx->r2) = ctx->r15;
            goto L_80053AE4;
    }
    // 0x80053C00: sb          $t7, 0x3F($v0)
    MEM_B(0X3F, ctx->r2) = ctx->r15;
    // 0x80053C04: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x80053C08: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_80053C0C:
    // 0x80053C0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80053C10: subu        $s2, $s2, $fp
    ctx->r18 = SUB32(ctx->r18, ctx->r30);
    // 0x80053C14: bne         $v0, $s0, L_80053AB0
    if (ctx->r2 != ctx->r16) {
        // 0x80053C18: addu        $ra, $ra, $fp
        ctx->r31 = ADD32(ctx->r31, ctx->r30);
            goto L_80053AB0;
    }
    // 0x80053C18: addu        $ra, $ra, $fp
    ctx->r31 = ADD32(ctx->r31, ctx->r30);
L_80053C1C:
    // 0x80053C1C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80053C20: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80053C24: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80053C28: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80053C2C: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80053C30: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80053C34: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80053C38: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80053C3C: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x80053C40: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80053C44: jr          $ra
    // 0x80053C48: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80053C48: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80051D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051D20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80051D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051D28: jal         0x80064DD0
    // 0x80051D2C: addiu       $a0, $zero, 0x414
    ctx->r4 = ADD32(0, 0X414);
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x80051D2C: addiu       $a0, $zero, 0x414
    ctx->r4 = ADD32(0, 0X414);
    after_0:
    // 0x80051D30: bne         $v0, $zero, L_80051D40
    if (ctx->r2 != 0) {
        // 0x80051D34: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80051D40;
    }
    // 0x80051D34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80051D38: b           L_80051D54
    // 0x80051D3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80051D54;
    // 0x80051D3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80051D40:
    // 0x80051D40: addiu       $a1, $zero, 0x414
    ctx->r5 = ADD32(0, 0X414);
    // 0x80051D44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80051D48: jal         0x80065728
    // 0x80051D4C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x80051D4C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80051D50: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80051D54:
    // 0x80051D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051D58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80051D5C: jr          $ra
    // 0x80051D60: nop

    return;
    // 0x80051D60: nop

;}
RECOMP_FUNC void Math_FAbs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081CA4: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80081CA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80081CAC: nop

    // 0x80081CB0: c.lt.d      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.d < ctx->f4.d;
    // 0x80081CB4: nop

    // 0x80081CB8: bc1fl       L_80081CD0
    if (!c1cs) {
        // 0x80081CBC: mov.d       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
            goto L_80081CD0;
    }
    goto skip_0;
    // 0x80081CBC: mov.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
    skip_0:
    // 0x80081CC0: neg.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = -ctx->f12.d;
    // 0x80081CC4: jr          $ra
    // 0x80081CC8: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    return;
    // 0x80081CC8: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    // 0x80081CCC: mov.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
L_80081CD0:
    // 0x80081CD0: jr          $ra
    // 0x80081CD4: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    return;
    // 0x80081CD4: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
;}
RECOMP_FUNC void func_807ADF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ADF40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807ADF44: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807ADF48: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x807ADF4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807ADF50: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x807ADF54: lw          $a0, -0x7CE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE8);
    // 0x807ADF58: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x807ADF5C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x807ADF60: jal         0x807ADF10
    // 0x807ADF64: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_807ADF10(rdram, ctx);
        goto after_0;
    // 0x807ADF64: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x807ADF68: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x807ADF6C: lui         $t9, 0x807B
    ctx->r25 = S32(RELOC_HI16(859, 0X24C0) << 16);
    // 0x807ADF70: addiu       $t9, $t9, -0x14E0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(859, 0X24C0));
    // 0x807ADF74: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x807ADF78: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807ADF7C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807ADF80: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x807ADF84: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x807ADF88: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x807ADF8C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x807ADF90: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x807ADF94: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26E4) << 16);
    // 0x807ADF98: lwc1        $f16, -0x12BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26E4));
    // 0x807ADF9C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x807ADFA0: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x807ADFA4: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x807ADFA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807ADFAC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x807ADFB0: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x807ADFB4: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x807ADFB8: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x807ADFBC: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x807ADFC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807ADFC4: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x807ADFC8: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x807ADFCC: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x807ADFD0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x807ADFD4: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x807ADFD8: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x807ADFDC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x807ADFE0: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x807ADFE4: mul.s       $f4, $f6, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x807ADFE8: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x807ADFEC: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x807ADFF0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x807ADFF4: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807ADFF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807ADFFC: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x807AE000: nop

    // 0x807AE004: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x807AE008: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x807AE00C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x807AE010: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x807AE014: div.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x807AE018: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x807AE01C: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x807AE020: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807AE024: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x807AE028: nop

    // 0x807AE02C: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x807AE030: jal         0x8006CA74
    // 0x807AE034: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    func_8006CA74(rdram, ctx);
        goto after_1;
    // 0x807AE034: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    after_1:
    // 0x807AE038: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x807AE03C: lui         $a2, 0x807B
    ctx->r6 = S32(RELOC_HI16(859, 0X17D8) << 16);
    // 0x807AE040: addiu       $a2, $a2, -0x21C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(859, 0X17D8));
    // 0x807AE044: lw          $a0, -0x7CE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE8);
    // 0x807AE048: jal         0x8005A994
    // 0x807AE04C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8005A994(rdram, ctx);
        goto after_2;
    // 0x807AE04C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x807AE050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AE054: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807AE058: jr          $ra
    // 0x807AE05C: nop

    return;
    // 0x807AE05C: nop

;}
RECOMP_FUNC void func_804457C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804457C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804457C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804457C8: jal         0x80444408
    // 0x804457CC: addiu       $a1, $zero, 0x40F0
    ctx->r5 = ADD32(0, 0X40F0);
    func_80444408(rdram, ctx);
        goto after_0;
    // 0x804457CC: addiu       $a1, $zero, 0x40F0
    ctx->r5 = ADD32(0, 0X40F0);
    after_0:
    // 0x804457D0: beq         $v0, $zero, L_804457FC
    if (ctx->r2 == 0) {
        // 0x804457D4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_804457FC;
    }
    // 0x804457D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804457D8: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x804457DC: jal         0x80444408
    // 0x804457E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80444408(rdram, ctx);
        goto after_1;
    // 0x804457E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x804457E4: beq         $v0, $zero, L_804457F4
    if (ctx->r2 == 0) {
        // 0x804457E8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_804457F4;
    }
    // 0x804457E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804457EC: jal         0x8005C9A8
    // 0x804457F0: nop

    func_8005C9A8(rdram, ctx);
        goto after_2;
    // 0x804457F0: nop

    after_2:
L_804457F4:
    // 0x804457F4: jal         0x800447C8
    // 0x804457F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x804457F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
L_804457FC:
    // 0x804457FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445800: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80445804: jr          $ra
    // 0x80445808: nop

    return;
    // 0x80445808: nop

;}
RECOMP_FUNC void func_8000BE94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BE94: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000BE98: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000BE9C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000BEA0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000BEA4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000BEA8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000BEAC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000BEB0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000BEB4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000BEB8: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8000BEBC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8000BEC0: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8000BEC4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000BEC8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8000BECC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000BED0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000BED4: addiu       $v0, $v0, -0x6384
    ctx->r2 = ADD32(ctx->r2, -0X6384);
    // 0x8000BED8: addiu       $v1, $v1, -0x6394
    ctx->r3 = ADD32(ctx->r3, -0X6394);
    // 0x8000BEDC: addiu       $a1, $a1, -0x63A4
    ctx->r5 = ADD32(ctx->r5, -0X63A4);
    // 0x8000BEE0: addiu       $a2, $a2, -0x63B4
    ctx->r6 = ADD32(ctx->r6, -0X63B4);
    // 0x8000BEE4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8000BEE8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8000BEEC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000BEF0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8000BEF4: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x8000BEF8: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x8000BEFC: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
L_8000BF00:
    // 0x8000BF00: beql        $s3, $zero, L_8000BF2C
    if (ctx->r19 == 0) {
        // 0x8000BF04: or          $s1, $s4, $zero
        ctx->r17 = ctx->r20 | 0;
            goto L_8000BF2C;
    }
    goto skip_0;
    // 0x8000BF04: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    skip_0:
    // 0x8000BF08: beql        $s3, $s5, L_8000BF3C
    if (ctx->r19 == ctx->r21) {
        // 0x8000BF0C: addiu       $s1, $s4, 0x10
        ctx->r17 = ADD32(ctx->r20, 0X10);
            goto L_8000BF3C;
    }
    goto skip_1;
    // 0x8000BF0C: addiu       $s1, $s4, 0x10
    ctx->r17 = ADD32(ctx->r20, 0X10);
    skip_1:
    // 0x8000BF10: beql        $s3, $s6, L_8000BF4C
    if (ctx->r19 == ctx->r22) {
        // 0x8000BF14: addiu       $s1, $s4, 0x20
        ctx->r17 = ADD32(ctx->r20, 0X20);
            goto L_8000BF4C;
    }
    goto skip_2;
    // 0x8000BF14: addiu       $s1, $s4, 0x20
    ctx->r17 = ADD32(ctx->r20, 0X20);
    skip_2:
    // 0x8000BF18: beql        $s3, $s7, L_8000BF5C
    if (ctx->r19 == ctx->r23) {
        // 0x8000BF1C: addiu       $s1, $s4, 0x30
        ctx->r17 = ADD32(ctx->r20, 0X30);
            goto L_8000BF5C;
    }
    goto skip_3;
    // 0x8000BF1C: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
    skip_3:
    // 0x8000BF20: b           L_8000BF64
    // 0x8000BF24: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
        goto L_8000BF64;
    // 0x8000BF24: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8000BF28: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
L_8000BF2C:
    // 0x8000BF2C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8000BF30: b           L_8000BF64
    // 0x8000BF34: lw          $s0, 0x4($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X4);
        goto L_8000BF64;
    // 0x8000BF34: lw          $s0, 0x4($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X4);
    // 0x8000BF38: addiu       $s1, $s4, 0x10
    ctx->r17 = ADD32(ctx->r20, 0X10);
L_8000BF3C:
    // 0x8000BF3C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000BF40: b           L_8000BF64
    // 0x8000BF44: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
        goto L_8000BF64;
    // 0x8000BF44: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8000BF48: addiu       $s1, $s4, 0x20
    ctx->r17 = ADD32(ctx->r20, 0X20);
L_8000BF4C:
    // 0x8000BF4C: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x8000BF50: b           L_8000BF64
    // 0x8000BF54: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
        goto L_8000BF64;
    // 0x8000BF54: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8000BF58: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
L_8000BF5C:
    // 0x8000BF5C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8000BF60: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
L_8000BF64:
    // 0x8000BF64: beql        $s0, $s1, L_8000BFB4
    if (ctx->r16 == ctx->r17) {
        // 0x8000BF68: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8000BFB4;
    }
    goto skip_4;
    // 0x8000BF68: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_4:
L_8000BF6C:
    // 0x8000BF6C: beql        $s0, $zero, L_8000BFB4
    if (ctx->r16 == 0) {
        // 0x8000BF70: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8000BFB4;
    }
    goto skip_5;
    // 0x8000BF70: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_5:
    // 0x8000BF74: jal         0x8000C170
    // 0x8000BF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000C170(rdram, ctx);
        goto after_0;
    // 0x8000BF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000BF7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000BF80: jal         0x8000DB94
    // 0x8000BF84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000DB94(rdram, ctx);
        goto after_1;
    // 0x8000BF84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8000BF88: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8000BF8C: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8000BF90: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8000BF94: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8000BF98: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000BF9C: addiu       $v0, $v0, -0x6384
    ctx->r2 = ADD32(ctx->r2, -0X6384);
    // 0x8000BFA0: addiu       $v1, $v1, -0x6394
    ctx->r3 = ADD32(ctx->r3, -0X6394);
    // 0x8000BFA4: addiu       $a1, $a1, -0x63A4
    ctx->r5 = ADD32(ctx->r5, -0X63A4);
    // 0x8000BFA8: bne         $s0, $s1, L_8000BF6C
    if (ctx->r16 != ctx->r17) {
        // 0x8000BFAC: addiu       $a2, $a2, -0x63B4
        ctx->r6 = ADD32(ctx->r6, -0X63B4);
            goto L_8000BF6C;
    }
    // 0x8000BFAC: addiu       $a2, $a2, -0x63B4
    ctx->r6 = ADD32(ctx->r6, -0X63B4);
    // 0x8000BFB0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8000BFB4:
    // 0x8000BFB4: bne         $s3, $fp, L_8000BF00
    if (ctx->r19 != ctx->r30) {
        // 0x8000BFB8: nop
    
            goto L_8000BF00;
    }
    // 0x8000BFB8: nop

    // 0x8000BFBC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000BFC0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8000BFC4: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8000BFC8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BFCC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000BFD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000BFD4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000BFD8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000BFDC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BFE0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000BFE4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8000BFE8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000BFEC: jr          $ra
    // 0x8000BFF0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000BFF0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_806FC9BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FC9BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806FC9C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FC9C4: lw          $a1, 0x134($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X134);
    // 0x806FC9C8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FC9CC: lui         $t0, 0x8070
    ctx->r8 = S32(RELOC_HI16(703, 0XA60) << 16);
    // 0x806FC9D0: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x806FC9D4: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x806FC9D8: lw          $t9, 0x14C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14C);
    // 0x806FC9DC: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x806FC9E0: lw          $t0, -0x2C90($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(703, 0XA60));
    // 0x806FC9E4: lui         $a3, 0x8070
    ctx->r7 = S32(RELOC_HI16(703, 0XA68) << 16);
    // 0x806FC9E8: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x806FC9EC: lw          $a3, -0x2C88($a3)
    ctx->r7 = MEM_W(ctx->r7, (int16_t)RELOC_LO16(703, 0XA68));
    // 0x806FC9F0: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806FC9F4: lwc1        $f14, 0x8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X8);
    // 0x806FC9F8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806FC9FC: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x806FCA00: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x806FCA04: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x806FCA08: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x806FCA0C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806FCA10: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x806FCA14: sltu        $at, $t7, $t3
    ctx->r1 = ctx->r15 < ctx->r11 ? 1 : 0;
    // 0x806FCA18: bne         $at, $zero, L_806FCA88
    if (ctx->r1 != 0) {
        // 0x806FCA1C: lwc1        $f2, 0x7C($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X7C);
            goto L_806FCA88;
    }
    // 0x806FCA1C: lwc1        $f2, 0x7C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x806FCA20: addiu       $v0, $a0, 0x14C
    ctx->r2 = ADD32(ctx->r4, 0X14C);
    // 0x806FCA24: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x806FCA28: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x806FCA2C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x806FCA30: sltu        $at, $t5, $a3
    ctx->r1 = ctx->r13 < ctx->r7 ? 1 : 0;
    // 0x806FCA34: bne         $at, $zero, L_806FCA88
    if (ctx->r1 != 0) {
        // 0x806FCA38: sw          $t5, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r13;
            goto L_806FCA88;
    }
    // 0x806FCA38: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x806FCA3C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x806FCA40: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x806FCA44: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x806FCA48: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x806FCA4C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x806FCA50: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x806FCA54: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x806FCA58: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x806FCA5C: jal         0x80067BBC
    // 0x806FCA60: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806FCA60: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x806FCA64: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    // 0x806FCA68: jal         0x80067818
    // 0x806FCA6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x806FCA6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806FCA70: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x806FCA74: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x806FCA78: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x806FCA7C: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806FCA80: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x806FCA84: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
L_806FCA88:
    // 0x806FCA88: addiu       $v0, $a2, 0x14C
    ctx->r2 = ADD32(ctx->r6, 0X14C);
    // 0x806FCA8C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x806FCA90: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(703, 0X718) << 16);
    // 0x806FCA94: addiu       $t8, $t8, -0x2FD8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(703, 0X718));
    // 0x806FCA98: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x806FCA9C: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x806FCAA0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x806FCAA4: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x806FCAA8: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x806FCAAC: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x806FCAB0: addu        $v1, $t2, $t8
    ctx->r3 = ADD32(ctx->r10, ctx->r24);
    // 0x806FCAB4: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x806FCAB8: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x806FCABC: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x806FCAC0: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x806FCAC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806FCAC8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806FCACC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806FCAD0: nop

    // 0x806FCAD4: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x806FCAD8: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x806FCADC: swc1        $f12, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f12.u32l;
    // 0x806FCAE0: add.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f18.fl;
    // 0x806FCAE4: swc1        $f14, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f14.u32l;
    // 0x806FCAE8: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x806FCAEC: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x806FCAF0: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x806FCAF4: nop

    // 0x806FCAF8: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x806FCAFC: swc1        $f0, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f0.u32l;
    // 0x806FCB00: swc1        $f2, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f2.u32l;
    // 0x806FCB04: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x806FCB08: swc1        $f8, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f8.u32l;
    // 0x806FCB0C: lh          $t5, 0x14($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X14);
    // 0x806FCB10: sh          $t5, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r13;
    // 0x806FCB14: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x806FCB18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806FCB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FCB20: bne         $t6, $zero, L_806FCB30
    if (ctx->r14 != 0) {
        // 0x806FCB24: nop
    
            goto L_806FCB30;
    }
    // 0x806FCB24: nop

    // 0x806FCB28: b           L_806FCB30
    // 0x806FCB2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806FCB30;
    // 0x806FCB2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806FCB30:
    // 0x806FCB30: jr          $ra
    // 0x806FCB34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x806FCB34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80453104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453104: jr          $ra
    // 0x80453108: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80453108: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800285B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800285B8: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x800285BC: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x800285C0: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x800285C4: beql        $t7, $zero, L_800285FC
    if (ctx->r15 == 0) {
        // 0x800285C8: lwc1        $f16, 0x84($a1)
        ctx->f16.u32l = MEM_W(ctx->r5, 0X84);
            goto L_800285FC;
    }
    goto skip_0;
    // 0x800285C8: lwc1        $f16, 0x84($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X84);
    skip_0:
    // 0x800285CC: lw          $t8, 0x28($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X28);
    // 0x800285D0: andi        $t9, $t8, 0x700
    ctx->r25 = ctx->r24 & 0X700;
    // 0x800285D4: bnel        $t9, $zero, L_800285FC
    if (ctx->r25 != 0) {
        // 0x800285D8: lwc1        $f16, 0x84($a1)
        ctx->f16.u32l = MEM_W(ctx->r5, 0X84);
            goto L_800285FC;
    }
    goto skip_1;
    // 0x800285D8: lwc1        $f16, 0x84($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X84);
    skip_1:
    // 0x800285DC: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
    // 0x800285E0: lwc1        $f6, 0xDC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XDC);
    // 0x800285E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800285E8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800285EC: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800285F0: jr          $ra
    // 0x800285F4: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800285F4: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800285F8: lwc1        $f16, 0x84($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X84);
L_800285FC:
    // 0x800285FC: lwc1        $f18, 0xDC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XDC);
    // 0x80028600: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80028604: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80028608: lwc1        $f8, 0xE0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XE0);
    // 0x8002860C: lwc1        $f6, 0x88($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X88);
    // 0x80028610: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80028614: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x80028618: jr          $ra
    // 0x8002861C: nop

    return;
    // 0x8002861C: nop

;}
RECOMP_FUNC void func_80471C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471C2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80471C30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80471C34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80471C38: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80471C3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80471C40: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80471C44: lw          $t6, 0x1F4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1F4);
    // 0x80471C48: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80471C4C: jal         0x80471BCC
    // 0x80471C50: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80471BCC(rdram, ctx);
        goto after_0;
    // 0x80471C50: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80471C54: jal         0x80471C10
    // 0x80471C58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80471C10(rdram, ctx);
        goto after_1;
    // 0x80471C58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80471C5C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80471C60: beql        $a1, $zero, L_80471CB0
    if (ctx->r5 == 0) {
        // 0x80471C64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80471CB0;
    }
    goto skip_0;
    // 0x80471C64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80471C68: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x80471C6C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80471C70: beql        $t7, $zero, L_80471CB0
    if (ctx->r15 == 0) {
        // 0x80471C74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80471CB0;
    }
    goto skip_1;
    // 0x80471C74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80471C78: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x80471C7C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80471C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80471C84: beq         $t9, $zero, L_80471CAC
    if (ctx->r25 == 0) {
        // 0x80471C88: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80471CAC;
    }
    // 0x80471C88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80471C8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80471C90: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(158, 0X1AE8) << 16);
    // 0x80471C94: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80471C98: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
    // 0x80471C9C: lwc1        $f6, 0x2FA8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(158, 0X1AE8));
    // 0x80471CA0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x80471CA4: jal         0x80471D38
    // 0x80471CA8: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    func_80471D38(rdram, ctx);
        goto after_2;
    // 0x80471CA8: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    after_2:
L_80471CAC:
    // 0x80471CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80471CB0:
    // 0x80471CB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80471CB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80471CB8: jr          $ra
    // 0x80471CBC: nop

    return;
    // 0x80471CBC: nop

;}
RECOMP_FUNC void func_8066B400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B400: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8066B404: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8066B408: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8066B40C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066B410: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8066B414: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8066B418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B41C: jal         0x8066AD18
    // 0x8066B420: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8066AD18(rdram, ctx);
        goto after_0;
    // 0x8066B420: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8066B424: jal         0x8066B050
    // 0x8066B428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066B050(rdram, ctx);
        goto after_1;
    // 0x8066B428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8066B42C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8066B430: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8066B434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8066B438: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8066B43C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B440: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8066B444: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8066B448: nop

    // 0x8066B44C: bc1fl       L_8066B460
    if (!c1cs) {
        // 0x8066B450: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8066B460;
    }
    goto skip_0;
    // 0x8066B450: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8066B454: jal         0x8066B970
    // 0x8066B458: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8066B970(rdram, ctx);
        goto after_2;
    // 0x8066B458: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8066B45C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066B460:
    // 0x8066B460: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8066B464: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8066B468: jr          $ra
    // 0x8066B46C: nop

    return;
    // 0x8066B46C: nop

;}
RECOMP_FUNC void func_80442398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80442398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044239C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804423A0: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804423A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804423A8: beq         $t6, $zero, L_804423E4
    if (ctx->r14 == 0) {
        // 0x804423AC: nop
    
            goto L_804423E4;
    }
    // 0x804423AC: nop

    // 0x804423B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804423B4: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804423B8: jalr        $t9
    // 0x804423BC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804423BC: nop

    after_0:
    // 0x804423C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804423C4: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804423C8: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804423CC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804423D0: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804423D4: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804423D8: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804423DC: b           L_804423E4
    // 0x804423E0: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_804423E4;
    // 0x804423E0: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_804423E4:
    // 0x804423E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804423E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804423EC: jr          $ra
    // 0x804423F0: nop

    return;
    // 0x804423F0: nop

;}
RECOMP_FUNC void func_8073F6D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F6D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073F6DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073F6E0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8073F6E4: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8073F6E8: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8073F6EC: lui         $t8, 0x8074
    ctx->r24 = S32(RELOC_HI16(748, 0X23FC) << 16);
    // 0x8073F6F0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8073F6F4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8073F6F8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8073F6FC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8073F700: lw          $t8, 0xBEC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(748, 0X23FC));
    // 0x8073F704: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8073F708: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8073F70C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8073F710: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8073F714: jal         0x80048490
    // 0x8073F718: addu        $a1, $t8, $v0
    ctx->r5 = ADD32(ctx->r24, ctx->r2);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8073F718: addu        $a1, $t8, $v0
    ctx->r5 = ADD32(ctx->r24, ctx->r2);
    after_0:
    // 0x8073F71C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8073F720: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8073F724: bnel        $v0, $zero, L_8073F744
    if (ctx->r2 != 0) {
        // 0x8073F728: lw          $t3, 0x174($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X174);
            goto L_8073F744;
    }
    goto skip_0;
    // 0x8073F728: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
    skip_0:
    // 0x8073F72C: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x8073F730: addiu       $t9, $zero, -0x5
    ctx->r25 = ADD32(0, -0X5);
    // 0x8073F734: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8073F738: b           L_8073F750
    // 0x8073F73C: sh          $t9, 0x50($t1)
    MEM_H(0X50, ctx->r9) = ctx->r25;
        goto L_8073F750;
    // 0x8073F73C: sh          $t9, 0x50($t1)
    MEM_H(0X50, ctx->r9) = ctx->r25;
    // 0x8073F740: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
L_8073F744:
    // 0x8073F744: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8073F748: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8073F74C: sh          $t2, 0x50($t4)
    MEM_H(0X50, ctx->r12) = ctx->r10;
L_8073F750:
    // 0x8073F750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073F754: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073F758: jr          $ra
    // 0x8073F75C: nop

    return;
    // 0x8073F75C: nop

;}
RECOMP_FUNC void func_8067A8F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067A8F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067A8FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067A900: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067A904: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8067A908: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067A90C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8067A910: lwc1        $f12, 0x3C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8067A914: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8067A918: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8067A91C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8067A920: jal         0x80082050
    // 0x8067A924: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    truncf_recomp(rdram, ctx);
        goto after_0;
    // 0x8067A924: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8067A928: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8067A92C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8067A930: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067A934: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8067A938: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8067A93C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8067A940: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8067A944: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8067A948: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8067A94C: lwc1        $f2, 0x3C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8067A950: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8067A954: nop

    // 0x8067A958: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8067A95C: beql        $t7, $zero, L_8067A9AC
    if (ctx->r15 == 0) {
        // 0x8067A960: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_8067A9AC;
    }
    goto skip_0;
    // 0x8067A960: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x8067A964: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8067A968: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067A96C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8067A970: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8067A974: nop

    // 0x8067A978: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8067A97C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8067A980: nop

    // 0x8067A984: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8067A988: bne         $t7, $zero, L_8067A9A0
    if (ctx->r15 != 0) {
        // 0x8067A98C: nop
    
            goto L_8067A9A0;
    }
    // 0x8067A98C: nop

    // 0x8067A990: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8067A994: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067A998: b           L_8067A9B8
    // 0x8067A99C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8067A9B8;
    // 0x8067A99C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8067A9A0:
    // 0x8067A9A0: b           L_8067A9B8
    // 0x8067A9A4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8067A9B8;
    // 0x8067A9A4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8067A9A8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_8067A9AC:
    // 0x8067A9AC: nop

    // 0x8067A9B0: bltz        $t7, L_8067A9A0
    if (SIGNED(ctx->r15) < 0) {
        // 0x8067A9B4: nop
    
            goto L_8067A9A0;
    }
    // 0x8067A9B4: nop

L_8067A9B8:
    // 0x8067A9B8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8067A9BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8067A9C0: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8067A9C4: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8067A9C8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8067A9CC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8067A9D0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8067A9D4: cvt.w.s     $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = CVT_W_S(ctx->f2.fl);
    // 0x8067A9D8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8067A9DC: nop

    // 0x8067A9E0: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8067A9E4: beql        $t0, $zero, L_8067AA34
    if (ctx->r8 == 0) {
        // 0x8067A9E8: mfc1        $t0, $f16
        ctx->r8 = (int32_t)ctx->f16.u32l;
            goto L_8067AA34;
    }
    goto skip_1;
    // 0x8067A9E8: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x8067A9EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8067A9F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8067A9F4: sub.s       $f16, $f2, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8067A9F8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8067A9FC: nop

    // 0x8067AA00: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8067AA04: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8067AA08: nop

    // 0x8067AA0C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8067AA10: bne         $t0, $zero, L_8067AA28
    if (ctx->r8 != 0) {
        // 0x8067AA14: nop
    
            goto L_8067AA28;
    }
    // 0x8067AA14: nop

    // 0x8067AA18: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8067AA1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067AA20: b           L_8067AA40
    // 0x8067AA24: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8067AA40;
    // 0x8067AA24: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_8067AA28:
    // 0x8067AA28: b           L_8067AA40
    // 0x8067AA2C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8067AA40;
    // 0x8067AA2C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8067AA30: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
L_8067AA34:
    // 0x8067AA34: nop

    // 0x8067AA38: bltz        $t0, L_8067AA28
    if (SIGNED(ctx->r8) < 0) {
        // 0x8067AA3C: nop
    
            goto L_8067AA28;
    }
    // 0x8067AA3C: nop

L_8067AA40:
    // 0x8067AA40: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x8067AA44: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8067AA48: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8067AA4C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8067AA50: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8067AA54: bgez        $t2, L_8067AA68
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8067AA58: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8067AA68;
    }
    // 0x8067AA58: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8067AA5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067AA60: nop

    // 0x8067AA64: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8067AA68:
    // 0x8067AA68: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8067AA6C: add.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8067AA70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8067AA74: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8067AA78: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8067AA7C: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x8067AA80: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8067AA84: bc1f        L_8067AA98
    if (!c1cs) {
        // 0x8067AA88: swc1        $f10, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
            goto L_8067AA98;
    }
    // 0x8067AA88: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x8067AA8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8067AA90: nop

    // 0x8067AA94: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
L_8067AA98:
    // 0x8067AA98: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x8067AA9C: lui         $at, 0xC307
    ctx->r1 = S32(0XC307 << 16);
    // 0x8067AAA0: bc1fl       L_8067AABC
    if (!c1cs) {
        // 0x8067AAA4: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_8067AABC;
    }
    goto skip_2;
    // 0x8067AAA4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_2:
    // 0x8067AAA8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8067AAAC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8067AAB0: b           L_8067AAC4
    // 0x8067AAB4: swc1        $f14, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f14.u32l;
        goto L_8067AAC4;
    // 0x8067AAB4: swc1        $f14, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f14.u32l;
    // 0x8067AAB8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_8067AABC:
    // 0x8067AABC: nop

    // 0x8067AAC0: swc1        $f14, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f14.u32l;
L_8067AAC4:
    // 0x8067AAC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067AAC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067AACC: jr          $ra
    // 0x8067AAD0: nop

    return;
    // 0x8067AAD0: nop

;}
RECOMP_FUNC void func_806F01BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F01BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806F01C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806F01C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806F01C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F01CC: jal         0x80045A34
    // 0x806F01D0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806F01D0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x806F01D4: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(676, 0X424C) << 16);
    // 0x806F01D8: addiu       $t6, $t6, 0x19C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(676, 0X424C));
    // 0x806F01DC: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806F01E0: bne         $v0, $zero, L_806F01F0
    if (ctx->r2 != 0) {
        // 0x806F01E4: sw          $t6, 0x1F8($s0)
        MEM_W(0X1F8, ctx->r16) = ctx->r14;
            goto L_806F01F0;
    }
    // 0x806F01E4: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
    // 0x806F01E8: b           L_806F028C
    // 0x806F01EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F028C;
    // 0x806F01EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F01F0:
    // 0x806F01F0: jal         0x806F0178
    // 0x806F01F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F0178(rdram, ctx);
        goto after_1;
    // 0x806F01F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806F01F8: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x806F01FC: jal         0x80058958
    // 0x806F0200: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_80058958(rdram, ctx);
        goto after_2;
    // 0x806F0200: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_2:
    // 0x806F0204: beq         $v0, $zero, L_806F0288
    if (ctx->r2 == 0) {
        // 0x806F0208: lui         $t8, 0x8010
        ctx->r24 = S32(0X8010 << 16);
            goto L_806F0288;
    }
    // 0x806F0208: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x806F020C: lw          $t8, -0x7BC4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7BC4);
    // 0x806F0210: lw          $t9, 0x10C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10C);
    // 0x806F0214: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x806F0218: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x806F021C: beql        $t1, $zero, L_806F028C
    if (ctx->r9 == 0) {
        // 0x806F0220: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_806F028C;
    }
    goto skip_0;
    // 0x806F0220: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x806F0224: jal         0x80056564
    // 0x806F0228: nop

    func_80056564(rdram, ctx);
        goto after_3;
    // 0x806F0228: nop

    after_3:
    // 0x806F022C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x806F0230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F0234: beq         $v0, $zero, L_806F0280
    if (ctx->r2 == 0) {
        // 0x806F0238: sw          $v0, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r2;
            goto L_806F0280;
    }
    // 0x806F0238: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x806F023C: jal         0x800457A0
    // 0x806F0240: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_4;
    // 0x806F0240: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x806F0244: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x806F0248: addiu       $t4, $zero, 0x29
    ctx->r12 = ADD32(0, 0X29);
    // 0x806F024C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x806F0250: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x806F0254: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x806F0258: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x806F025C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806F0260: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806F0264: jal         0x80056584
    // 0x806F0268: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80056584(rdram, ctx);
        goto after_5;
    // 0x806F0268: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_5:
    // 0x806F026C: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x806F0270: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806F0274: addiu       $t6, $t6, 0x784C
    ctx->r14 = ADD32(ctx->r14, 0X784C);
    // 0x806F0278: b           L_806F0288
    // 0x806F027C: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
        goto L_806F0288;
    // 0x806F027C: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
L_806F0280:
    // 0x806F0280: b           L_806F028C
    // 0x806F0284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F028C;
    // 0x806F0284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F0288:
    // 0x806F0288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806F028C:
    // 0x806F028C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806F0290: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806F0294: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806F0298: jr          $ra
    // 0x806F029C: nop

    return;
    // 0x806F029C: nop

;}
RECOMP_FUNC void func_8069A0B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069A0B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069A0BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069A0C0: jal         0x80699C60
    // 0x8069A0C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80699C60(rdram, ctx);
        goto after_0;
    // 0x8069A0C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069A0C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069A0CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8069A0D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069A0D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8069A0D8: jal         0x8069A0F0
    // 0x8069A0DC: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    func_8069A0F0(rdram, ctx);
        goto after_1;
    // 0x8069A0DC: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    after_1:
    // 0x8069A0E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069A0E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069A0E8: jr          $ra
    // 0x8069A0EC: nop

    return;
    // 0x8069A0EC: nop

;}
RECOMP_FUNC void func_805D33D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D33D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D33DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D33E0: jal         0x805D32D4
    // 0x805D33E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805D32D4(rdram, ctx);
        goto after_0;
    // 0x805D33E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D33E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D33EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D33F0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x805D33F4: jal         0x805D3B18
    // 0x805D33F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_805D3B18(rdram, ctx);
        goto after_1;
    // 0x805D33F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x805D33FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D3400: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805D3404: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(471, 0X197C) << 16);
    // 0x805D3408: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x805D340C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x805D3410: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805D3414: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x805D3418: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x805D341C: addiu       $t7, $t7, 0x33AC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(471, 0X197C));
    // 0x805D3420: sh          $t6, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r14;
    // 0x805D3424: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x805D3428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D342C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D3430: jr          $ra
    // 0x805D3434: nop

    return;
    // 0x805D3434: nop

;}
RECOMP_FUNC void func_8005ABB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005ABB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005ABB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005ABB8: jal         0x80064DD0
    // 0x8005ABBC: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x8005ABBC: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    after_0:
    // 0x8005ABC0: bne         $v0, $zero, L_8005ABE0
    if (ctx->r2 != 0) {
        // 0x8005ABC4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005ABE0;
    }
    // 0x8005ABC4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005ABC8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005ABCC: addiu       $a0, $a0, 0xC10
    ctx->r4 = ADD32(ctx->r4, 0XC10);
    // 0x8005ABD0: jal         0x80071380
    // 0x8005ABD4: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8005ABD4: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    after_1:
    // 0x8005ABD8: b           L_8005ABE4
    // 0x8005ABDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005ABE4;
    // 0x8005ABDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005ABE0:
    // 0x8005ABE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8005ABE4:
    // 0x8005ABE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005ABE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005ABEC: jr          $ra
    // 0x8005ABF0: nop

    return;
    // 0x8005ABF0: nop

;}
RECOMP_FUNC void func_80461C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461C60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80461C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80461C68: jal         0x80062748
    // 0x80461C6C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062748(rdram, ctx);
        goto after_0;
    // 0x80461C6C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x80461C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80461C74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80461C78: jr          $ra
    // 0x80461C7C: nop

    return;
    // 0x80461C7C: nop

;}
RECOMP_FUNC void func_8001C158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C158: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001C15C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001C160: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001C164: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x8001C168: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8001C16C: lw          $t7, -0x77F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X77F0);
    // 0x8001C170: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8001C174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001C178: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8001C17C: lw          $v0, 0x4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X4);
    // 0x8001C180: lw          $t9, 0x16C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X16C);
    // 0x8001C184: bne         $v0, $zero, L_8001C19C
    if (ctx->r2 != 0) {
        // 0x8001C188: lw          $v1, 0x1B8($t9)
        ctx->r3 = MEM_W(ctx->r25, 0X1B8);
            goto L_8001C19C;
    }
    // 0x8001C188: lw          $v1, 0x1B8($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X1B8);
    // 0x8001C18C: jal         0x8006E558
    // 0x8001C190: nop

    func_8006E558(rdram, ctx);
        goto after_0;
    // 0x8001C190: nop

    after_0:
    // 0x8001C194: b           L_8001C224
    // 0x8001C198: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8001C224;
    // 0x8001C198: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001C19C:
    // 0x8001C19C: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8001C1A0: lw          $a1, 0x20($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X20);
    // 0x8001C1A4: lw          $a2, 0x24($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X24);
    // 0x8001C1A8: lw          $a3, 0x8C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8C);
    // 0x8001C1AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001C1B0: lwc1        $f6, 0x38($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8001C1B4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8001C1B8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C1BC: jal         0x80050048
    // 0x8001C1C0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80050048(rdram, ctx);
        goto after_1;
    // 0x8001C1C0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8001C1C4: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001C1C8: addiu       $a1, $a1, -0x3F00
    ctx->r5 = ADD32(ctx->r5, -0X3F00);
    // 0x8001C1CC: jal         0x8006E138
    // 0x8001C1D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006E138(rdram, ctx);
        goto after_2;
    // 0x8001C1D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8001C1D4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C1D8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8001C1DC: lbu         $t0, 0x24($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X24);
    // 0x8001C1E0: andi        $t1, $t0, 0xFF0F
    ctx->r9 = ctx->r8 & 0XFF0F;
    // 0x8001C1E4: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x8001C1E8: sb          $t2, 0x24($v1)
    MEM_B(0X24, ctx->r3) = ctx->r10;
    // 0x8001C1EC: lwc1        $f8, 0x6C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x8001C1F0: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    // 0x8001C1F4: lwc1        $f10, 0x70($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X70);
    // 0x8001C1F8: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    // 0x8001C1FC: lwc1        $f16, 0x9C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X9C);
    // 0x8001C200: swc1        $f16, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f16.u32l;
    // 0x8001C204: lwc1        $f18, 0xA0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XA0);
    // 0x8001C208: swc1        $f18, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f18.u32l;
    // 0x8001C20C: lwc1        $f4, 0x8C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x8001C210: swc1        $f4, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f4.u32l;
    // 0x8001C214: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8001C218: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8001C21C: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x8001C220: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001C224:
    // 0x8001C224: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001C228: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001C22C: jr          $ra
    // 0x8001C230: nop

    return;
    // 0x8001C230: nop

;}
RECOMP_FUNC void func_8002D198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D19C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D1A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002D1A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002D1A8: jal         0x800422CC
    // 0x8002D1AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800422CC(rdram, ctx);
        goto after_0;
    // 0x8002D1AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8002D1B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002D1B4: jal         0x8002D164
    // 0x8002D1B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8002D164(rdram, ctx);
        goto after_1;
    // 0x8002D1B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002D1BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D1C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D1C4: jr          $ra
    // 0x8002D1C8: nop

    return;
    // 0x8002D1C8: nop

;}
RECOMP_FUNC void func_800516D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800516D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800516D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800516D8: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800516DC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800516E0: sb          $t6, 0x3E($a0)
    MEM_B(0X3E, ctx->r4) = ctx->r14;
    // 0x800516E4: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x800516E8: bnel        $t7, $zero, L_80051700
    if (ctx->r15 != 0) {
        // 0x800516EC: addiu       $a0, $a1, 0x4
        ctx->r4 = ADD32(ctx->r5, 0X4);
            goto L_80051700;
    }
    goto skip_0;
    // 0x800516EC: addiu       $a0, $a1, 0x4
    ctx->r4 = ADD32(ctx->r5, 0X4);
    skip_0:
    // 0x800516F0: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
    // 0x800516F4: b           L_80051724
    // 0x800516F8: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
        goto L_80051724;
    // 0x800516F8: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x800516FC: addiu       $a0, $a1, 0x4
    ctx->r4 = ADD32(ctx->r5, 0X4);
L_80051700:
    // 0x80051700: jal         0x80050A50
    // 0x80051704: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x80051704: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80051708: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8005170C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80051710: sw          $v0, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r2;
    // 0x80051714: jal         0x80051640
    // 0x80051718: lhu         $a1, 0x3C($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X3C);
    func_80051640(rdram, ctx);
        goto after_1;
    // 0x80051718: lhu         $a1, 0x3C($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X3C);
    after_1:
    // 0x8005171C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80051720: lw          $v0, 0x40($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X40);
L_80051724:
    // 0x80051724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005172C: jr          $ra
    // 0x80051730: nop

    return;
    // 0x80051730: nop

;}
RECOMP_FUNC void func_807606CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807606CC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807606D0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x807606D4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x807606D8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x807606DC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x807606E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x807606E4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x807606E8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x807606EC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x807606F0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x807606F4: jr          $ra
    // 0x807606F8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x807606F8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_800273F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800273F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800273F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800273FC: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x80027400: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80027404: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80027408: beq         $t6, $at, L_80027430
    if (ctx->r14 == ctx->r1) {
        // 0x8002740C: addiu       $a2, $zero, 0x79
        ctx->r6 = ADD32(0, 0X79);
            goto L_80027430;
    }
    // 0x8002740C: addiu       $a2, $zero, 0x79
    ctx->r6 = ADD32(0, 0X79);
    // 0x80027410: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80027414: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80027418: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    // 0x8002741C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80027420: jal         0x80024680
    // 0x80027424: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_80024680(rdram, ctx);
        goto after_0;
    // 0x80027424: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_0:
    // 0x80027428: b           L_80027448
    // 0x8002742C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80027448;
    // 0x8002742C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80027430:
    // 0x80027430: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80027434: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80027438: addiu       $a0, $a1, 0x14C
    ctx->r4 = ADD32(ctx->r5, 0X14C);
    // 0x8002743C: jal         0x80024680
    // 0x80027440: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_80024680(rdram, ctx);
        goto after_1;
    // 0x80027440: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_1:
    // 0x80027444: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80027448:
    // 0x80027448: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002744C: jr          $ra
    // 0x80027450: nop

    return;
    // 0x80027450: nop

;}
RECOMP_FUNC void func_8005C594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C594: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005C598: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005C59C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8005C5A0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005C5A4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8005C5A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005C5AC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8005C5B0: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x8005C5B4: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
    // 0x8005C5B8: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x8005C5BC: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x8005C5C0: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8005C5C4: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x8005C5C8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8005C5CC: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x8005C5D0: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8005C5D4: lh          $t3, 0x13C($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X13C);
    // 0x8005C5D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005C5DC: bgez        $t3, L_8005C5EC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8005C5E0: sra         $t4, $t3, 1
        ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
            goto L_8005C5EC;
    }
    // 0x8005C5E0: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8005C5E4: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x8005C5E8: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8005C5EC:
    // 0x8005C5EC: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x8005C5F0: lh          $t5, 0x13E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X13E);
    // 0x8005C5F4: jal         0x8005C4CC
    // 0x8005C5F8: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    func_8005C4CC(rdram, ctx);
        goto after_0;
    // 0x8005C5F8: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    after_0:
    // 0x8005C5FC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8005C600: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8005C604: lhu         $t6, 0x10($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X10);
    // 0x8005C608: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8005C60C: bnel        $t6, $zero, L_8005C64C
    if (ctx->r14 != 0) {
        // 0x8005C610: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8005C64C;
    }
    goto skip_0;
    // 0x8005C610: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x8005C614: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x8005C618: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8005C61C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005C620: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8005C624: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x8005C628: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8005C62C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005C630: bnel        $t4, $at, L_8005C64C
    if (ctx->r12 != ctx->r1) {
        // 0x8005C634: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8005C64C;
    }
    goto skip_1;
    // 0x8005C634: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    skip_1:
    // 0x8005C638: jal         0x8005D110
    // 0x8005C63C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8005D110(rdram, ctx);
        goto after_1;
    // 0x8005C63C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8005C640: b           L_8005C840
    // 0x8005C644: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C840;
    // 0x8005C644: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005C648: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_8005C64C:
    // 0x8005C64C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8005C650: jal         0x8005C420
    // 0x8005C654: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8005C420(rdram, ctx);
        goto after_2;
    // 0x8005C654: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_2:
    // 0x8005C658: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8005C65C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8005C660: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8005C664: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8005C668: beql        $t5, $zero, L_8005C690
    if (ctx->r13 == 0) {
        // 0x8005C66C: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_8005C690;
    }
    goto skip_2;
    // 0x8005C66C: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_2:
    // 0x8005C670: jal         0x8005C420
    // 0x8005C674: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_8005C420(rdram, ctx);
        goto after_3;
    // 0x8005C674: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8005C678: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8005C67C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8005C680: jal         0x8005C420
    // 0x8005C684: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_8005C420(rdram, ctx);
        goto after_4;
    // 0x8005C684: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x8005C688: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8005C68C: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_8005C690:
    // 0x8005C690: slti        $v1, $v0, 0x2
    ctx->r3 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8005C694: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8005C698: beq         $v1, $zero, L_8005C83C
    if (ctx->r3 == 0) {
        // 0x8005C69C: sw          $t6, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r14;
            goto L_8005C83C;
    }
    // 0x8005C69C: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
    // 0x8005C6A0: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8005C6A4: sll         $t0, $s1, 1
    ctx->r8 = S32(ctx->r17 << 1);
    // 0x8005C6A8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005C6AC: addu        $v1, $t2, $t0
    ctx->r3 = ADD32(ctx->r10, ctx->r8);
    // 0x8005C6B0: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x8005C6B4: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8005C6B8: beql        $t8, $at, L_8005C798
    if (ctx->r24 == ctx->r1) {
        // 0x8005C6BC: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_8005C798;
    }
    goto skip_3;
    // 0x8005C6BC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_3:
    // 0x8005C6C0: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x8005C6C4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8005C6C8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8005C6CC: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8005C6D0: beql        $t9, $zero, L_8005C744
    if (ctx->r25 == 0) {
        // 0x8005C6D4: lw          $t3, 0x3C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X3C);
            goto L_8005C744;
    }
    goto skip_4;
    // 0x8005C6D4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    skip_4:
    // 0x8005C6D8: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005C6DC: lw          $a1, 0x18($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X18);
    // 0x8005C6E0: lh          $a3, 0x13C($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X13C);
    // 0x8005C6E4: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8005C6E8: addu        $a2, $t0, $t2
    ctx->r6 = ADD32(ctx->r8, ctx->r10);
    // 0x8005C6EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005C6F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005C6F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005C6F8: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8005C6FC: mflo        $v1
    ctx->r3 = lo;
    // 0x8005C700: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8005C704: jal         0x8005C060
    // 0x8005C708: addu        $a0, $v1, $t5
    ctx->r4 = ADD32(ctx->r3, ctx->r13);
    func_8005C060(rdram, ctx);
        goto after_5;
    // 0x8005C708: addu        $a0, $v1, $t5
    ctx->r4 = ADD32(ctx->r3, ctx->r13);
    after_5:
    // 0x8005C70C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8005C710: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8005C714: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8005C718: lh          $a3, 0x13C($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X13C);
    // 0x8005C71C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8005C720: lw          $a1, 0x18($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X18);
    // 0x8005C724: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8005C728: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8005C72C: jal         0x8005C060
    // 0x8005C730: addu        $a0, $v1, $t8
    ctx->r4 = ADD32(ctx->r3, ctx->r24);
    func_8005C060(rdram, ctx);
        goto after_6;
    // 0x8005C730: addu        $a0, $v1, $t8
    ctx->r4 = ADD32(ctx->r3, ctx->r24);
    after_6:
    // 0x8005C734: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005C738: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8005C73C: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8005C740: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
L_8005C744:
    // 0x8005C744: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8005C748: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8005C74C: lw          $a1, 0x18($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X18);
    // 0x8005C750: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005C754: lh          $a3, 0x13C($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X13C);
    // 0x8005C758: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005C75C: addu        $a2, $t0, $t2
    ctx->r6 = ADD32(ctx->r8, ctx->r10);
    // 0x8005C760: mflo        $t5
    ctx->r13 = lo;
    // 0x8005C764: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x8005C768: jal         0x8005C060
    // 0x8005C76C: nop

    func_8005C060(rdram, ctx);
        goto after_7;
    // 0x8005C76C: nop

    after_7:
    // 0x8005C770: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x8005C774: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x8005C778: addiu       $t8, $s1, 0x1
    ctx->r24 = ADD32(ctx->r17, 0X1);
    // 0x8005C77C: sw          $t8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r24;
    // 0x8005C780: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x8005C784: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8005C788: lw          $s1, 0xC($t9)
    ctx->r17 = MEM_W(ctx->r25, 0XC);
    // 0x8005C78C: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x8005C790: addu        $v1, $t2, $t4
    ctx->r3 = ADD32(ctx->r10, ctx->r12);
    // 0x8005C794: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8005C798:
    // 0x8005C798: lhu         $t5, 0x10($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X10);
    // 0x8005C79C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8005C7A0: sh          $t6, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r14;
    // 0x8005C7A4: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x8005C7A8: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x8005C7AC: slti        $at, $a0, 0x2000
    ctx->r1 = SIGNED(ctx->r4) < 0X2000 ? 1 : 0;
    // 0x8005C7B0: bne         $at, $zero, L_8005C7F0
    if (ctx->r1 != 0) {
        // 0x8005C7B4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005C7F0;
    }
    // 0x8005C7B4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005C7B8: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005C7BC: beq         $at, $zero, L_8005C7E8
    if (ctx->r1 == 0) {
        // 0x8005C7C0: addiu       $t8, $a0, -0x2000
        ctx->r24 = ADD32(ctx->r4, -0X2000);
            goto L_8005C7E8;
    }
    // 0x8005C7C0: addiu       $t8, $a0, -0x2000
    ctx->r24 = ADD32(ctx->r4, -0X2000);
    // 0x8005C7C4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005C7C8: sh          $t8, -0x7F80($at)
    MEM_H(-0X7F80, ctx->r1) = ctx->r24;
    // 0x8005C7CC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8005C7D0: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x8005C7D4: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8005C7D8: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x8005C7DC: lw          $t4, 0x1F4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F4);
    // 0x8005C7E0: b           L_8005C7F0
    // 0x8005C7E4: lw          $s1, 0xC($t4)
    ctx->r17 = MEM_W(ctx->r12, 0XC);
        goto L_8005C7F0;
    // 0x8005C7E4: lw          $s1, 0xC($t4)
    ctx->r17 = MEM_W(ctx->r12, 0XC);
L_8005C7E8:
    // 0x8005C7E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005C7EC: sh          $zero, -0x7F80($at)
    MEM_H(-0X7F80, ctx->r1) = 0;
L_8005C7F0:
    // 0x8005C7F0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8005C7F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005C7F8: lhu         $t3, 0x10($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X10);
    // 0x8005C7FC: bnel        $t3, $zero, L_8005C840
    if (ctx->r11 != 0) {
        // 0x8005C800: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005C840;
    }
    goto skip_5;
    // 0x8005C800: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x8005C804: lhu         $t5, -0x7F80($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X7F80);
    // 0x8005C808: sll         $t6, $s1, 1
    ctx->r14 = S32(ctx->r17 << 1);
    // 0x8005C80C: addu        $t8, $t2, $t6
    ctx->r24 = ADD32(ctx->r10, ctx->r14);
    // 0x8005C810: sh          $t5, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r13;
    // 0x8005C814: sh          $zero, -0x7F80($at)
    MEM_H(-0X7F80, ctx->r1) = 0;
    // 0x8005C818: lhu         $t7, 0x0($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X0);
    // 0x8005C81C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005C820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005C824: bne         $t7, $at, L_8005C834
    if (ctx->r15 != ctx->r1) {
        // 0x8005C828: nop
    
            goto L_8005C834;
    }
    // 0x8005C828: nop

    // 0x8005C82C: b           L_8005C83C
    // 0x8005C830: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
        goto L_8005C83C;
    // 0x8005C830: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_8005C834:
    // 0x8005C834: jal         0x8005D110
    // 0x8005C838: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8005D110(rdram, ctx);
        goto after_8;
    // 0x8005C838: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
L_8005C83C:
    // 0x8005C83C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005C840:
    // 0x8005C840: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C844: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8005C848: jr          $ra
    // 0x8005C84C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8005C84C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80455274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80455278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045527C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80455280: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80455284: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13DD0) << 16);
    // 0x80455288: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8045528C: lw          $v1, 0x6CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CE8);
    // 0x80455290: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80455294: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80455298: lw          $t9, -0x7E50($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13DD0));
    // 0x8045529C: jalr        $t9
    // 0x804552A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804552A0: nop

    after_0:
    // 0x804552A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804552A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804552AC: jr          $ra
    // 0x804552B0: nop

    return;
    // 0x804552B0: nop

;}
RECOMP_FUNC void func_8002B03C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B03C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002B040: beq         $a1, $at, L_8002B080
    if (ctx->r5 == ctx->r1) {
        // 0x8002B044: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_8002B080;
    }
    // 0x8002B044: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8002B048: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002B04C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8002B050: lw          $v1, 0x1304($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1304);
    // 0x8002B054: lw          $t6, 0x130C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X130C);
    // 0x8002B058: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8002B05C: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x8002B060: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8002B064: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8002B068: sw          $t7, 0x130C($v0)
    MEM_W(0X130C, ctx->r2) = ctx->r15;
    // 0x8002B06C: addu        $a2, $v0, $t8
    ctx->r6 = ADD32(ctx->r2, ctx->r24);
    // 0x8002B070: mfhi        $t0
    ctx->r8 = hi;
    // 0x8002B074: sb          $a1, 0x1310($a2)
    MEM_B(0X1310, ctx->r6) = ctx->r5;
    // 0x8002B078: sw          $a3, 0x1314($a2)
    MEM_W(0X1314, ctx->r6) = ctx->r7;
    // 0x8002B07C: sw          $t0, 0x1304($v0)
    MEM_W(0X1304, ctx->r2) = ctx->r8;
L_8002B080:
    // 0x8002B080: jr          $ra
    // 0x8002B084: nop

    return;
    // 0x8002B084: nop

;}
RECOMP_FUNC void func_80760290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80760290: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80760294: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80760298: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8076029C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x807602A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807602A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807602A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x807602AC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x807602B0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x807602B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x807602B8: addiu       $t6, $zero, 0x528
    ctx->r14 = ADD32(0, 0X528);
    // 0x807602BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x807602C0: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x807602C4: addiu       $a3, $zero, 0x4EC
    ctx->r7 = ADD32(0, 0X4EC);
    // 0x807602C8: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x807602CC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x807602D0: jal         0x8076009C
    // 0x807602D4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_8076009C(rdram, ctx);
        goto after_0;
    // 0x807602D4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x807602D8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x807602DC: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x807602E0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x807602E4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x807602E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807602EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807602F0: jr          $ra
    // 0x807602F4: nop

    return;
    // 0x807602F4: nop

;}
