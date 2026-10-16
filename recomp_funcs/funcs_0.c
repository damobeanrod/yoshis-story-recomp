#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_806FBDC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FBDC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806FBDC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FBDC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806FBDCC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FBDD0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x806FBDD4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806FBDD8: lwc1        $f0, 0x14A4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14A4);
    // 0x806FBDDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806FBDE0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x806FBDE4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806FBDE8: nop

    // 0x806FBDEC: bc1fl       L_806FBE24
    if (!c1cs) {
        // 0x806FBDF0: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_806FBE24;
    }
    goto skip_0;
    // 0x806FBDF0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x806FBDF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806FBDF8: nop

    // 0x806FBDFC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x806FBE00: swc1        $f6, 0x14A4($s0)
    MEM_W(0X14A4, ctx->r16) = ctx->f6.u32l;
    // 0x806FBE04: lwc1        $f8, 0x14A4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14A4);
    // 0x806FBE08: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x806FBE0C: nop

    // 0x806FBE10: bc1f        L_806FBE58
    if (!c1cs) {
        // 0x806FBE14: nop
    
            goto L_806FBE58;
    }
    // 0x806FBE14: nop

    // 0x806FBE18: b           L_806FBE58
    // 0x806FBE1C: swc1        $f2, 0x14A4($s0)
    MEM_W(0X14A4, ctx->r16) = ctx->f2.u32l;
        goto L_806FBE58;
    // 0x806FBE1C: swc1        $f2, 0x14A4($s0)
    MEM_W(0X14A4, ctx->r16) = ctx->f2.u32l;
    // 0x806FBE20: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_806FBE24:
    // 0x806FBE24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806FBE28: bc1f        L_806FBE58
    if (!c1cs) {
        // 0x806FBE2C: nop
    
            goto L_806FBE58;
    }
    // 0x806FBE2C: nop

    // 0x806FBE30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806FBE34: nop

    // 0x806FBE38: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x806FBE3C: swc1        $f16, 0x14A4($s0)
    MEM_W(0X14A4, ctx->r16) = ctx->f16.u32l;
    // 0x806FBE40: lwc1        $f18, 0x14A4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14A4);
    // 0x806FBE44: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x806FBE48: nop

    // 0x806FBE4C: bc1f        L_806FBE58
    if (!c1cs) {
        // 0x806FBE50: nop
    
            goto L_806FBE58;
    }
    // 0x806FBE50: nop

    // 0x806FBE54: swc1        $f2, 0x14A4($s0)
    MEM_W(0X14A4, ctx->r16) = ctx->f2.u32l;
L_806FBE58:
    // 0x806FBE58: jal         0x806FBCDC
    // 0x806FBE5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_806FBCDC(rdram, ctx);
        goto after_0;
    // 0x806FBE5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806FBE60: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x806FBE64: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806FBE68: beq         $v0, $zero, L_806FBEFC
    if (ctx->r2 == 0) {
        // 0x806FBE6C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_806FBEFC;
    }
    // 0x806FBE6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806FBE70: lwc1        $f4, 0x14A4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14A4);
    // 0x806FBE74: lui         $v1, 0x8070
    ctx->r3 = S32(RELOC_HI16(700, 0X28F8) << 16);
    // 0x806FBE78: addiu       $v1, $v1, -0x3AD8
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(700, 0X28F8));
    // 0x806FBE7C: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x806FBE80: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(700, 0X2608) << 16);
    // 0x806FBE84: bc1f        L_806FBEFC
    if (!c1cs) {
        // 0x806FBE88: nop
    
            goto L_806FBEFC;
    }
    // 0x806FBE88: nop

    // 0x806FBE8C: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x806FBE90: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x806FBE94: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x806FBE98: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806FBE9C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x806FBEA0: lwc1        $f0, -0x3DC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(700, 0X2608));
    // 0x806FBEA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806FBEA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806FBEAC: sw          $zero, 0x14BC($s0)
    MEM_W(0X14BC, ctx->r16) = 0;
    // 0x806FBEB0: sw          $t8, 0x14C0($s0)
    MEM_W(0X14C0, ctx->r16) = ctx->r24;
    // 0x806FBEB4: sw          $t9, 0x14C4($s0)
    MEM_W(0X14C4, ctx->r16) = ctx->r25;
    // 0x806FBEB8: swc1        $f0, 0x14B8($s0)
    MEM_W(0X14B8, ctx->r16) = ctx->f0.u32l;
    // 0x806FBEBC: swc1        $f0, 0x14B4($s0)
    MEM_W(0X14B4, ctx->r16) = ctx->f0.u32l;
    // 0x806FBEC0: swc1        $f6, 0x14AC($s0)
    MEM_W(0X14AC, ctx->r16) = ctx->f6.u32l;
    // 0x806FBEC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x806FBEC8: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x806FBECC: lui         $t2, 0x8070
    ctx->r10 = S32(RELOC_HI16(700, 0X2754) << 16);
    // 0x806FBED0: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x806FBED4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806FBED8: sw          $t0, 0x14CC($s0)
    MEM_W(0X14CC, ctx->r16) = ctx->r8;
    // 0x806FBEDC: lw          $t2, -0x3C7C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(700, 0X2754));
    // 0x806FBEE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FBEE4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806FBEE8: sw          $t2, 0x14C8($s0)
    MEM_W(0X14C8, ctx->r16) = ctx->r10;
    // 0x806FBEEC: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x806FBEF0: jal         0x806FC1EC
    // 0x806FBEF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_806FC1EC(rdram, ctx);
        goto after_1;
    // 0x806FBEF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x806FBEF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_806FBEFC:
    // 0x806FBEFC: jal         0x806FBA08
    // 0x806FBF00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_806FBA08(rdram, ctx);
        goto after_2;
    // 0x806FBF00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x806FBF04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806FBF08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806FBF0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806FBF10: jr          $ra
    // 0x806FBF14: nop

    return;
    // 0x806FBF14: nop

;}
RECOMP_FUNC void func_8043DD2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DD2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043DD30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8043DD34: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8043DD38: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8043DD3C: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(92, 0X1AE8) << 16);
    // 0x8043DD40: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8043DD44: lw          $v0, -0x14D8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(92, 0X1AE8));
    // 0x8043DD48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043DD4C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8043DD50: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8043DD54: jalr        $t9
    // 0x8043DD58: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8043DD58: nop

    after_0:
    // 0x8043DD5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043DD60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043DD64: jr          $ra
    // 0x8043DD68: nop

    return;
    // 0x8043DD68: nop

;}
RECOMP_FUNC void func_8005BB78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BB78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005BB7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005BB80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005BB84: jal         0x8005BA30
    // 0x8005BB88: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_8005BA30(rdram, ctx);
        goto after_0;
    // 0x8005BB88: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8005BB8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BB90: bne         $v0, $at, L_8005BBA0
    if (ctx->r2 != ctx->r1) {
        // 0x8005BB94: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005BBA0;
    }
    // 0x8005BB94: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005BB98: b           L_8005BBB8
    // 0x8005BB9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005BBB8;
    // 0x8005BB9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005BBA0:
    // 0x8005BBA0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8005BBA4: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8005BBA8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8005BBAC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005BBB0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8005BBB4: lw          $v0, -0x4BAC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BAC);
L_8005BBB8:
    // 0x8005BBB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005BBBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005BBC0: jr          $ra
    // 0x8005BBC4: nop

    return;
    // 0x8005BBC4: nop

;}
RECOMP_FUNC void func_8043B5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B5F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043B5F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043B5FC: jal         0x8043AC18
    // 0x8043B600: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8043AC18(rdram, ctx);
        goto after_0;
    // 0x8043B600: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043B604: jal         0x8043B590
    // 0x8043B608: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8043B590(rdram, ctx);
        goto after_1;
    // 0x8043B608: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8043B60C: jal         0x8043B4B0
    // 0x8043B610: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8043B4B0(rdram, ctx);
        goto after_2;
    // 0x8043B610: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8043B614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043B618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043B61C: jr          $ra
    // 0x8043B620: nop

    return;
    // 0x8043B620: nop

;}
RECOMP_FUNC void func_80583CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80583CC0: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(402, 0X1200) << 16);
    // 0x80583CC4: jr          $ra
    // 0x80583CC8: addiu       $v0, $v0, 0x4EC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(402, 0X1200));
    return;
    // 0x80583CC8: addiu       $v0, $v0, 0x4EC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(402, 0X1200));
;}
RECOMP_FUNC void func_800745E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800745E0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800745E4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800745E8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800745EC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800745F0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800745F4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800745F8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800745FC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80074600: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80074604: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074608: jal         0x800744B0
    // 0x8007460C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800744B0(rdram, ctx);
        goto after_0;
    // 0x8007460C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80074610: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80074614: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80074618: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007461C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80074620: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80074624: addiu       $s5, $zero, 0x68
    ctx->r21 = ADD32(0, 0X68);
    // 0x80074628: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8007462C:
    // 0x8007462C: lbu         $t6, 0x2AA($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2AA);
    // 0x80074630: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80074634: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x80074638: beql        $t6, $zero, L_800746FC
    if (ctx->r14 == 0) {
        // 0x8007463C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800746FC;
    }
    goto skip_0;
    // 0x8007463C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80074640: lbu         $t9, 0x2($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2);
    // 0x80074644: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80074648: beql        $t0, $zero, L_800746EC
    if (ctx->r8 == 0) {
        // 0x8007464C: lbu         $v0, 0x2AE($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X2AE);
            goto L_800746EC;
    }
    goto skip_1;
    // 0x8007464C: lbu         $v0, 0x2AE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2AE);
    skip_1:
    // 0x80074650: lbu         $t1, 0x2AE($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2AE);
    // 0x80074654: bnel        $s3, $t1, L_800746FC
    if (ctx->r19 != ctx->r9) {
        // 0x80074658: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800746FC;
    }
    goto skip_2;
    // 0x80074658: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x8007465C: lbu         $t2, 0x2B2($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2B2);
    // 0x80074660: beql        $t2, $zero, L_800746A8
    if (ctx->r10 == 0) {
        // 0x80074664: lbu         $t5, 0x2B6($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X2B6);
            goto L_800746A8;
    }
    goto skip_3;
    // 0x80074664: lbu         $t5, 0x2B6($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X2B6);
    skip_3:
    // 0x80074668: lbu         $t3, 0x2B6($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2B6);
    // 0x8007466C: beql        $s3, $t3, L_800746FC
    if (ctx->r19 == ctx->r11) {
        // 0x80074670: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800746FC;
    }
    goto skip_4;
    // 0x80074670: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x80074674: multu       $s1, $s5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80074678: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8007467C: mflo        $t4
    ctx->r12 = lo;
    // 0x80074680: addu        $a0, $s2, $t4
    ctx->r4 = ADD32(ctx->r18, ctx->r12);
    // 0x80074684: jal         0x80087550
    // 0x80074688: addiu       $a0, $a0, 0x2BC
    ctx->r4 = ADD32(ctx->r4, 0X2BC);
    osMotorStart_recomp(rdram, ctx);
        goto after_1;
    // 0x80074688: addiu       $a0, $a0, 0x2BC
    ctx->r4 = ADD32(ctx->r4, 0X2BC);
    after_1:
    // 0x8007468C: beq         $v0, $zero, L_8007469C
    if (ctx->r2 == 0) {
        // 0x80074690: nop
    
            goto L_8007469C;
    }
    // 0x80074690: nop

    // 0x80074694: b           L_800746F8
    // 0x80074698: sb          $zero, 0x2AE($s0)
    MEM_B(0X2AE, ctx->r16) = 0;
        goto L_800746F8;
    // 0x80074698: sb          $zero, 0x2AE($s0)
    MEM_B(0X2AE, ctx->r16) = 0;
L_8007469C:
    // 0x8007469C: b           L_800746F8
    // 0x800746A0: sb          $s6, 0x2B6($s0)
    MEM_B(0X2B6, ctx->r16) = ctx->r22;
        goto L_800746F8;
    // 0x800746A0: sb          $s6, 0x2B6($s0)
    MEM_B(0X2B6, ctx->r16) = ctx->r22;
    // 0x800746A4: lbu         $t5, 0x2B6($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X2B6);
L_800746A8:
    // 0x800746A8: beql        $t5, $zero, L_800746FC
    if (ctx->r13 == 0) {
        // 0x800746AC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800746FC;
    }
    goto skip_5;
    // 0x800746AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x800746B0: multu       $s1, $s5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800746B4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800746B8: mflo        $t6
    ctx->r14 = lo;
    // 0x800746BC: addu        $a0, $s2, $t6
    ctx->r4 = ADD32(ctx->r18, ctx->r14);
    // 0x800746C0: jal         0x800873B0
    // 0x800746C4: addiu       $a0, $a0, 0x2BC
    ctx->r4 = ADD32(ctx->r4, 0X2BC);
    osMotorStop_recomp(rdram, ctx);
        goto after_2;
    // 0x800746C4: addiu       $a0, $a0, 0x2BC
    ctx->r4 = ADD32(ctx->r4, 0X2BC);
    after_2:
    // 0x800746C8: beql        $v0, $zero, L_800746DC
    if (ctx->r2 == 0) {
        // 0x800746CC: lbu         $t7, 0x2B6($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X2B6);
            goto L_800746DC;
    }
    goto skip_6;
    // 0x800746CC: lbu         $t7, 0x2B6($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2B6);
    skip_6:
    // 0x800746D0: b           L_800746F8
    // 0x800746D4: sb          $zero, 0x2AE($s0)
    MEM_B(0X2AE, ctx->r16) = 0;
        goto L_800746F8;
    // 0x800746D4: sb          $zero, 0x2AE($s0)
    MEM_B(0X2AE, ctx->r16) = 0;
    // 0x800746D8: lbu         $t7, 0x2B6($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2B6);
L_800746DC:
    // 0x800746DC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800746E0: b           L_800746F8
    // 0x800746E4: sb          $t8, 0x2B6($s0)
    MEM_B(0X2B6, ctx->r16) = ctx->r24;
        goto L_800746F8;
    // 0x800746E4: sb          $t8, 0x2B6($s0)
    MEM_B(0X2B6, ctx->r16) = ctx->r24;
    // 0x800746E8: lbu         $v0, 0x2AE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2AE);
L_800746EC:
    // 0x800746EC: beql        $v0, $zero, L_800746FC
    if (ctx->r2 == 0) {
        // 0x800746F0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800746FC;
    }
    goto skip_7;
    // 0x800746F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x800746F4: sb          $zero, 0x2AE($s0)
    MEM_B(0X2AE, ctx->r16) = 0;
L_800746F8:
    // 0x800746F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800746FC:
    // 0x800746FC: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80074700: bne         $at, $zero, L_8007462C
    if (ctx->r1 != 0) {
        // 0x80074704: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8007462C;
    }
    // 0x80074704: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074708: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8007470C: lw          $v1, -0x26B0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X26B0);
    // 0x80074710: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x80074714: bne         $t9, $zero, L_800747C4
    if (ctx->r25 != 0) {
        // 0x80074718: nop
    
            goto L_800747C4;
    }
    // 0x80074718: nop

    // 0x8007471C: bne         $s4, $zero, L_800747C4
    if (ctx->r20 != 0) {
        // 0x80074720: sra         $v0, $v1, 4
        ctx->r2 = S32(SIGNED(ctx->r3) >> 4);
            goto L_800747C4;
    }
    // 0x80074720: sra         $v0, $v1, 4
    ctx->r2 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80074724: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80074728: addu        $t0, $s2, $v0
    ctx->r8 = ADD32(ctx->r18, ctx->r2);
    // 0x8007472C: lbu         $t1, 0x2AA($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2AA);
    // 0x80074730: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80074734: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80074738: beq         $t1, $zero, L_800747C4
    if (ctx->r9 == 0) {
        // 0x8007473C: addu        $t3, $s2, $t2
        ctx->r11 = ADD32(ctx->r18, ctx->r10);
            goto L_800747C4;
    }
    // 0x8007473C: addu        $t3, $s2, $t2
    ctx->r11 = ADD32(ctx->r18, ctx->r10);
    // 0x80074740: lbu         $t4, 0x2($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X2);
    // 0x80074744: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80074748: beq         $t5, $zero, L_800747C4
    if (ctx->r13 == 0) {
        // 0x8007474C: nop
    
            goto L_800747C4;
    }
    // 0x8007474C: nop

    // 0x80074750: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80074754: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80074758: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8007475C: mflo        $t6
    ctx->r14 = lo;
    // 0x80074760: addu        $a1, $s2, $t6
    ctx->r5 = ADD32(ctx->r18, ctx->r14);
    // 0x80074764: jal         0x8008786C
    // 0x80074768: addiu       $a1, $a1, 0x2BC
    ctx->r5 = ADD32(ctx->r5, 0X2BC);
    osMotorInit_recomp(rdram, ctx);
        goto after_3;
    // 0x80074768: addiu       $a1, $a1, 0x2BC
    ctx->r5 = ADD32(ctx->r5, 0X2BC);
    after_3:
    // 0x8007476C: bne         $v0, $zero, L_80074794
    if (ctx->r2 != 0) {
        // 0x80074770: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80074794;
    }
    // 0x80074770: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80074774: addu        $s0, $s2, $s1
    ctx->r16 = ADD32(ctx->r18, ctx->r17);
    // 0x80074778: lbu         $t7, 0x2AE($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2AE);
    // 0x8007477C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80074780: beq         $s3, $t7, L_8007478C
    if (ctx->r19 == ctx->r15) {
        // 0x80074784: nop
    
            goto L_8007478C;
    }
    // 0x80074784: nop

    // 0x80074788: sb          $t8, 0x2AE($s0)
    MEM_B(0X2AE, ctx->r16) = ctx->r24;
L_8007478C:
    // 0x8007478C: b           L_800747C4
    // 0x80074790: sb          $s6, 0x2B6($s0)
    MEM_B(0X2B6, ctx->r16) = ctx->r22;
        goto L_800747C4;
    // 0x80074790: sb          $s6, 0x2B6($s0)
    MEM_B(0X2B6, ctx->r16) = ctx->r22;
L_80074794:
    // 0x80074794: bne         $v0, $at, L_800747A8
    if (ctx->r2 != ctx->r1) {
        // 0x80074798: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_800747A8;
    }
    // 0x80074798: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8007479C: addu        $t0, $s2, $s1
    ctx->r8 = ADD32(ctx->r18, ctx->r17);
    // 0x800747A0: b           L_800747C4
    // 0x800747A4: sb          $t9, 0x2AE($t0)
    MEM_B(0X2AE, ctx->r8) = ctx->r25;
        goto L_800747C4;
    // 0x800747A4: sb          $t9, 0x2AE($t0)
    MEM_B(0X2AE, ctx->r8) = ctx->r25;
L_800747A8:
    // 0x800747A8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800747AC: bne         $v0, $at, L_800747C4
    if (ctx->r2 != ctx->r1) {
        // 0x800747B0: lui         $t1, 0x800B
        ctx->r9 = S32(0X800B << 16);
            goto L_800747C4;
    }
    // 0x800747B0: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800747B4: lw          $t1, -0x7B2C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7B2C);
    // 0x800747B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800747BC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800747C0: sw          $t2, -0x7B2C($at)
    MEM_W(-0X7B2C, ctx->r1) = ctx->r10;
L_800747C4:
    // 0x800747C4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800747C8: lw          $v1, -0x26B0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X26B0);
    // 0x800747CC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800747D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800747D4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800747D8: sw          $v1, -0x26B0($at)
    MEM_W(-0X26B0, ctx->r1) = ctx->r3;
    // 0x800747DC: jal         0x8007451C
    // 0x800747E0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_8007451C(rdram, ctx);
        goto after_4;
    // 0x800747E0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x800747E4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800747E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800747EC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800747F0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800747F4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800747F8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800747FC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80074800: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80074804: jr          $ra
    // 0x80074808: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80074808: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8005BA40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BA40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005BA44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005BA48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005BA4C: jal         0x8005BA30
    // 0x8005BA50: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_8005BA30(rdram, ctx);
        goto after_0;
    // 0x8005BA50: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8005BA54: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8005BA58: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8005BA5C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8005BA60: addiu       $t7, $t7, -0x4BB0
    ctx->r15 = ADD32(ctx->r15, -0X4BB0);
    // 0x8005BA64: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8005BA68: jal         0x8005B96C
    // 0x8005BA6C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    func_8005B96C(rdram, ctx);
        goto after_1;
    // 0x8005BA6C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x8005BA70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005BA74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005BA78: jr          $ra
    // 0x8005BA7C: nop

    return;
    // 0x8005BA7C: nop

;}
RECOMP_FUNC void func_805DAD00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DAD00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DAD04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DAD08: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x805DAD0C: slti        $at, $v0, 0x407A
    ctx->r1 = SIGNED(ctx->r2) < 0X407A ? 1 : 0;
    // 0x805DAD10: bne         $at, $zero, L_805DAD60
    if (ctx->r1 != 0) {
        // 0x805DAD14: slti        $at, $v0, 0x4196
        ctx->r1 = SIGNED(ctx->r2) < 0X4196 ? 1 : 0;
            goto L_805DAD60;
    }
    // 0x805DAD14: slti        $at, $v0, 0x4196
    ctx->r1 = SIGNED(ctx->r2) < 0X4196 ? 1 : 0;
    // 0x805DAD18: bne         $at, $zero, L_805DAD40
    if (ctx->r1 != 0) {
        // 0x805DAD1C: addiu       $t6, $v0, -0x4532
        ctx->r14 = ADD32(ctx->r2, -0X4532);
            goto L_805DAD40;
    }
    // 0x805DAD1C: addiu       $t6, $v0, -0x4532
    ctx->r14 = ADD32(ctx->r2, -0X4532);
    // 0x805DAD20: sltiu       $at, $t6, 0x15
    ctx->r1 = ctx->r14 < 0X15 ? 1 : 0;
    // 0x805DAD24: beq         $at, $zero, L_805DADBC
    if (ctx->r1 == 0) {
        // 0x805DAD28: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_805DADBC;
    }
    // 0x805DAD28: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x805DAD2C: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X27B0) << 16);
    // 0x805DAD30: addu        $at, $at, $t6
    gpr jr_addend_805DAD38 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x805DAD34: lw          $t6, -0x2B50($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(480, 0X27B0));
    // 0x805DAD38: jr          $t6
    // 0x805DAD3C: nop

    switch (jr_addend_805DAD38 >> 2) {
        case 0: goto L_805DAD78; break;
        case 1: goto L_805DAD78; break;
        case 2: goto L_805DAD78; break;
        case 3: goto L_805DAD78; break;
        case 4: goto L_805DADBC; break;
        case 5: goto L_805DADBC; break;
        case 6: goto L_805DADBC; break;
        case 7: goto L_805DADBC; break;
        case 8: goto L_805DADBC; break;
        case 9: goto L_805DADBC; break;
        case 10: goto L_805DADBC; break;
        case 11: goto L_805DAD78; break;
        case 12: goto L_805DADBC; break;
        case 13: goto L_805DADBC; break;
        case 14: goto L_805DADBC; break;
        case 15: goto L_805DADBC; break;
        case 16: goto L_805DADBC; break;
        case 17: goto L_805DADBC; break;
        case 18: goto L_805DADBC; break;
        case 19: goto L_805DAD78; break;
        case 20: goto L_805DAD78; break;
        default: switch_error(__func__, 0x805DAD38, 0x805DD4B0);
    }
    // 0x805DAD3C: nop

L_805DAD40:
    // 0x805DAD40: addiu       $at, $zero, 0x4194
    ctx->r1 = ADD32(0, 0X4194);
    // 0x805DAD44: beq         $v0, $at, L_805DAD84
    if (ctx->r2 == ctx->r1) {
        // 0x805DAD48: lui         $t7, 0x805E
        ctx->r15 = S32(RELOC_HI16(480, 0X25A0) << 16);
            goto L_805DAD84;
    }
    // 0x805DAD48: lui         $t7, 0x805E
    ctx->r15 = S32(RELOC_HI16(480, 0X25A0) << 16);
    // 0x805DAD4C: addiu       $at, $zero, 0x4195
    ctx->r1 = ADD32(0, 0X4195);
    // 0x805DAD50: beq         $v0, $at, L_805DAD84
    if (ctx->r2 == ctx->r1) {
        // 0x805DAD54: nop
    
            goto L_805DAD84;
    }
    // 0x805DAD54: nop

    // 0x805DAD58: b           L_805DADBC
    // 0x805DAD5C: nop

        goto L_805DADBC;
    // 0x805DAD5C: nop

L_805DAD60:
    // 0x805DAD60: addiu       $at, $zero, 0x4047
    ctx->r1 = ADD32(0, 0X4047);
    // 0x805DAD64: beq         $v0, $at, L_805DAD78
    if (ctx->r2 == ctx->r1) {
        // 0x805DAD68: addiu       $at, $zero, 0x4048
        ctx->r1 = ADD32(0, 0X4048);
            goto L_805DAD78;
    }
    // 0x805DAD68: addiu       $at, $zero, 0x4048
    ctx->r1 = ADD32(0, 0X4048);
    // 0x805DAD6C: beq         $v0, $at, L_805DAD78
    if (ctx->r2 == ctx->r1) {
        // 0x805DAD70: addiu       $at, $zero, 0x4079
        ctx->r1 = ADD32(0, 0X4079);
            goto L_805DAD78;
    }
    // 0x805DAD70: addiu       $at, $zero, 0x4079
    ctx->r1 = ADD32(0, 0X4079);
    // 0x805DAD74: bne         $v0, $at, L_805DADBC
    if (ctx->r2 != ctx->r1) {
        // 0x805DAD78: lui         $v0, 0x805E
        ctx->r2 = S32(RELOC_HI16(480, 0X227C) << 16);
            goto L_805DADBC;
    }
L_805DAD78:
    // 0x805DAD78: lui         $v0, 0x805E
    ctx->r2 = S32(RELOC_HI16(480, 0X227C) << 16);
    // 0x805DAD7C: b           L_805DADC4
    // 0x805DAD80: addiu       $v0, $v0, -0x3084
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(480, 0X227C));
        goto L_805DADC4;
    // 0x805DAD80: addiu       $v0, $v0, -0x3084
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(480, 0X227C));
L_805DAD84:
    // 0x805DAD84: lw          $t7, -0x2D60($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(480, 0X25A0));
    // 0x805DAD88: lui         $a0, 0x805E
    ctx->r4 = S32(RELOC_HI16(480, 0X2D80) << 16);
    // 0x805DAD8C: addiu       $a0, $a0, -0x2580
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(480, 0X2D80));
    // 0x805DAD90: bne         $t7, $zero, L_805DADB0
    if (ctx->r15 != 0) {
        // 0x805DAD94: lui         $a1, 0x805E
        ctx->r5 = S32(RELOC_HI16(480, 0X2D90) << 16);
            goto L_805DADB0;
    }
    // 0x805DAD94: lui         $a1, 0x805E
    ctx->r5 = S32(RELOC_HI16(480, 0X2D90) << 16);
    // 0x805DAD98: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(480, 0X2D90));
    // 0x805DAD9C: jal         0x8004667C
    // 0x805DADA0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x805DADA0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x805DADA4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805DADA8: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X25A0) << 16);
    // 0x805DADAC: sw          $t8, -0x2D60($at)
    MEM_W((int16_t)RELOC_LO16(480, 0X25A0), ctx->r1) = ctx->r24;
L_805DADB0:
    // 0x805DADB0: lui         $v0, 0x805E
    ctx->r2 = S32(RELOC_HI16(480, 0X2124) << 16);
    // 0x805DADB4: b           L_805DADC4
    // 0x805DADB8: addiu       $v0, $v0, -0x31DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(480, 0X2124));
        goto L_805DADC4;
    // 0x805DADB8: addiu       $v0, $v0, -0x31DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(480, 0X2124));
L_805DADBC:
    // 0x805DADBC: lui         $v0, 0x805E
    ctx->r2 = S32(RELOC_HI16(480, 0X227C) << 16);
    // 0x805DADC0: addiu       $v0, $v0, -0x3084
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(480, 0X227C));
L_805DADC4:
    // 0x805DADC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DADC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DADCC: jr          $ra
    // 0x805DADD0: nop

    return;
    // 0x805DADD0: nop

;}
RECOMP_FUNC void func_8045030C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045030C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80450310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80450314: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80450318: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8045031C: jal         0x80444408
    // 0x80450320: addiu       $a1, $zero, 0x40F6
    ctx->r5 = ADD32(0, 0X40F6);
    func_80444408(rdram, ctx);
        goto after_0;
    // 0x80450320: addiu       $a1, $zero, 0x40F6
    ctx->r5 = ADD32(0, 0X40F6);
    after_0:
    // 0x80450324: bne         $v0, $zero, L_8045033C
    if (ctx->r2 != 0) {
        // 0x80450328: lbu         $t6, 0x1F($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X1F);
            goto L_8045033C;
    }
    // 0x80450328: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8045032C: jal         0x80445148
    // 0x80450330: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80445148(rdram, ctx);
        goto after_1;
    // 0x80450330: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80450334: b           L_80450344
    // 0x80450338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80450344;
    // 0x80450338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045033C:
    // 0x8045033C: sb          $t6, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r14;
    // 0x80450340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80450344:
    // 0x80450344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80450348: jr          $ra
    // 0x8045034C: nop

    return;
    // 0x8045034C: nop

;}
RECOMP_FUNC void func_806F600C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F600C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806F6010: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(685, 0XC48) << 16);
    // 0x806F6014: addiu       $t6, $t6, 0x5FA8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(685, 0XC48));
    // 0x806F6018: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806F601C: jr          $ra
    // 0x806F6020: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806F6020: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8064F048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F048: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F04C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F050: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F054: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F058: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F05C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F060: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F064: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F068: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F06C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F070: jr          $ra
    // 0x8064F074: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F074: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80438AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438AC0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80438AC4: addiu       $at, $zero, 0x4099
    ctx->r1 = ADD32(0, 0X4099);
    // 0x80438AC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80438ACC: bne         $t6, $at, L_80438AE0
    if (ctx->r14 != ctx->r1) {
        // 0x80438AD0: nop
    
            goto L_80438AE0;
    }
    // 0x80438AD0: nop

    // 0x80438AD4: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(80, 0X1718) << 16);
    // 0x80438AD8: jr          $ra
    // 0x80438ADC: addiu       $v0, $v0, -0x5E28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(80, 0X1718));
    return;
    // 0x80438ADC: addiu       $v0, $v0, -0x5E28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(80, 0X1718));
L_80438AE0:
    // 0x80438AE0: jr          $ra
    // 0x80438AE4: nop

    return;
    // 0x80438AE4: nop

;}
RECOMP_FUNC void func_80438520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438520: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80438524: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(77, 0X484) << 16);
    // 0x80438528: addiu       $t6, $t6, 0x6D24
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(77, 0X484));
    // 0x8043852C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80438530: jr          $ra
    // 0x80438534: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x80438534: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80454664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454664: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80454668: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045466C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80454670: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80454674: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80454678: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8045467C: lw          $v0, 0xA5C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA5C);
    // 0x80454680: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80454684: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80454688: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8045468C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80454690: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80454694: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80454698: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8045469C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x804546A0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x804546A4: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x804546A8: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x804546AC: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x804546B0: addiu       $t8, $t7, 0xAE0
    ctx->r24 = ADD32(ctx->r15, 0XAE0);
    // 0x804546B4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x804546B8: jal         0x8044E684
    // 0x804546BC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_8044E684(rdram, ctx);
        goto after_0;
    // 0x804546BC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x804546C0: jal         0x8044FD5C
    // 0x804546C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044FD5C(rdram, ctx);
        goto after_1;
    // 0x804546C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804546C8: jal         0x8044FFC0
    // 0x804546CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044FFC0(rdram, ctx);
        goto after_2;
    // 0x804546CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804546D0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x804546D4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x804546D8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x804546DC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804546E0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804546E4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804546E8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x804546EC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804546F0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x804546F4: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x804546F8: addu        $a1, $s1, $t0
    ctx->r5 = ADD32(ctx->r17, ctx->r8);
    // 0x804546FC: jal         0x8044ED68
    // 0x80454700: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_3;
    // 0x80454700: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_3:
    // 0x80454704: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80454708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045470C: jal         0x8044F178
    // 0x80454710: sw          $t1, 0xA5C($s1)
    MEM_W(0XA5C, ctx->r17) = ctx->r9;
    func_8044F178(rdram, ctx);
        goto after_4;
    // 0x80454710: sw          $t1, 0xA5C($s1)
    MEM_W(0XA5C, ctx->r17) = ctx->r9;
    after_4:
    // 0x80454714: jal         0x8044F384
    // 0x80454718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044F384(rdram, ctx);
        goto after_5;
    // 0x80454718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8045471C: jal         0x80450200
    // 0x80454720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80450200(rdram, ctx);
        goto after_6;
    // 0x80454720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80454724: jal         0x8045043C
    // 0x80454728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8045043C(rdram, ctx);
        goto after_7;
    // 0x80454728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8045472C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80454730: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80454734: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80454738: jr          $ra
    // 0x8045473C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8045473C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8002FBBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FBBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FBC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FBC4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FBC8: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FBCC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002FBD0: jal         0x8002F678
    // 0x8002FBD4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FBD4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FBD8: beq         $v0, $zero, L_8002FBEC
    if (ctx->r2 == 0) {
        // 0x8002FBDC: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FBEC;
    }
    // 0x8002FBDC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FBE0: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FBE4: addiu       $t6, $t6, -0x2C04
    ctx->r14 = ADD32(ctx->r14, -0X2C04);
    // 0x8002FBE8: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FBEC:
    // 0x8002FBEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FBF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FBF4: jr          $ra
    // 0x8002FBF8: nop

    return;
    // 0x8002FBF8: nop

;}
RECOMP_FUNC void func_8003E6C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E6C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003E6C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003E6CC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8003E6D0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8003E6D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003E6D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003E6DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003E6E0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8003E6E4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8003E6E8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8003E6EC: lhu         $v1, 0x12BE($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X12BE);
    // 0x8003E6F0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8003E6F4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8003E6F8: addu        $s0, $v1, $a1
    ctx->r16 = ADD32(ctx->r3, ctx->r5);
    // 0x8003E6FC: andi        $s0, $s0, 0x7
    ctx->r16 = ctx->r16 & 0X7;
    // 0x8003E700: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x8003E704: beq         $a1, $zero, L_8003E778
    if (ctx->r5 == 0) {
        // 0x8003E708: or          $t0, $a1, $zero
        ctx->r8 = ctx->r5 | 0;
            goto L_8003E778;
    }
    // 0x8003E708: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x8003E70C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8003E710: subu        $s4, $t6, $a1
    ctx->r20 = SUB32(ctx->r14, ctx->r5);
    // 0x8003E714: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x8003E718: beq         $s4, $zero, L_8003E768
    if (ctx->r20 == 0) {
        // 0x8003E71C: sh          $s0, 0x30($sp)
        MEM_H(0X30, ctx->r29) = ctx->r16;
            goto L_8003E768;
    }
    // 0x8003E71C: sh          $s0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r16;
    // 0x8003E720: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
    // 0x8003E724: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
L_8003E728:
    // 0x8003E728: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003E72C: andi        $s0, $s0, 0x7
    ctx->r16 = ctx->r16 & 0X7;
    // 0x8003E730: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x8003E734: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003E738: mflo        $t7
    ctx->r15 = lo;
    // 0x8003E73C: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x8003E740: lw          $a0, 0x11FC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X11FC);
    // 0x8003E744: multu       $a1, $s2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003E748: mflo        $t9
    ctx->r25 = lo;
    // 0x8003E74C: addu        $t1, $s3, $t9
    ctx->r9 = ADD32(ctx->r19, ctx->r25);
    // 0x8003E750: jal         0x8003E4C8
    // 0x8003E754: sw          $a0, 0x11FC($t1)
    MEM_W(0X11FC, ctx->r9) = ctx->r4;
    func_8003E4C8(rdram, ctx);
        goto after_0;
    // 0x8003E754: sw          $a0, 0x11FC($t1)
    MEM_W(0X11FC, ctx->r9) = ctx->r4;
    after_0:
    // 0x8003E758: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8003E75C: bnel        $s1, $zero, L_8003E728
    if (ctx->r17 != 0) {
        // 0x8003E760: andi        $a1, $s0, 0xFFFF
        ctx->r5 = ctx->r16 & 0XFFFF;
            goto L_8003E728;
    }
    goto skip_0;
    // 0x8003E760: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    skip_0:
    // 0x8003E764: lhu         $v1, 0x12BE($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X12BE);
L_8003E768:
    // 0x8003E768: addiu       $a1, $v1, 0x5
    ctx->r5 = ADD32(ctx->r3, 0X5);
    // 0x8003E76C: andi        $a1, $a1, 0x7
    ctx->r5 = ctx->r5 & 0X7;
    // 0x8003E770: b           L_8003E79C
    // 0x8003E774: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
        goto L_8003E79C;
    // 0x8003E774: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
L_8003E778:
    // 0x8003E778: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8003E77C: andi        $v0, $t2, 0x7
    ctx->r2 = ctx->r10 & 0X7;
    // 0x8003E780: addiu       $a1, $v0, 0x5
    ctx->r5 = ADD32(ctx->r2, 0X5);
    // 0x8003E784: sh          $v0, 0x12BE($s3)
    MEM_H(0X12BE, ctx->r19) = ctx->r2;
    // 0x8003E788: andi        $a1, $a1, 0x7
    ctx->r5 = ctx->r5 & 0X7;
    // 0x8003E78C: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8003E790: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8003E794: subu        $s4, $t4, $t0
    ctx->r20 = SUB32(ctx->r12, ctx->r8);
    // 0x8003E798: sh          $v0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r2;
L_8003E79C:
    // 0x8003E79C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8003E7A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003E7A4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8003E7A8: jalr        $t9
    // 0x8003E7AC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8003E7AC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x8003E7B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003E7B4: lhu         $a1, 0x30($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X30);
    // 0x8003E7B8: jal         0x8003E590
    // 0x8003E7BC: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    func_8003E590(rdram, ctx);
        goto after_2;
    // 0x8003E7BC: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    after_2:
    // 0x8003E7C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003E7C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003E7C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E7CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003E7D0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8003E7D4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8003E7D8: jr          $ra
    // 0x8003E7DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8003E7DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80672178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80672178: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067217C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80672180: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x80672184: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80672188: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8067218C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80672190: jal         0x80671D4C
    // 0x80672194: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80671D4C(rdram, ctx);
        goto after_0;
    // 0x80672194: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80672198: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8067219C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x806721A0: lw          $t6, 0x1E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1E0);
    // 0x806721A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x806721A8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806721AC: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x806721B0: bne         $at, $zero, L_806721D0
    if (ctx->r1 != 0) {
        // 0x806721B4: sw          $t7, 0x1E0($a3)
        MEM_W(0X1E0, ctx->r7) = ctx->r15;
            goto L_806721D0;
    }
    // 0x806721B4: sw          $t7, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r15;
    // 0x806721B8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x806721BC: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x806721C0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x806721C4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x806721C8: jal         0x80672C80
    // 0x806721CC: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    func_80672C80(rdram, ctx);
        goto after_1;
    // 0x806721CC: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    after_1:
L_806721D0:
    // 0x806721D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806721D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806721D8: jr          $ra
    // 0x806721DC: nop

    return;
    // 0x806721DC: nop

;}
RECOMP_FUNC void func_80558484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558484: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80558488: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8055848C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80558490: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80558494: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80558498: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8055849C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805584A0: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x805584A4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x805584A8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x805584AC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x805584B0: jal         0x8004613C
    // 0x805584B4: lui         $a0, 0x40A4
    ctx->r4 = S32(0X40A4 << 16);
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x805584B4: lui         $a0, 0x40A4
    ctx->r4 = S32(0X40A4 << 16);
    after_0:
    // 0x805584B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x805584BC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x805584C0: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x805584C4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x805584C8: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x805584CC: jal         0x8004613C
    // 0x805584D0: lui         $a0, 0x40A5
    ctx->r4 = S32(0X40A5 << 16);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x805584D0: lui         $a0, 0x40A5
    ctx->r4 = S32(0X40A5 << 16);
    after_1:
    // 0x805584D4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x805584D8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x805584DC: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x805584E0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x805584E4: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x805584E8: jal         0x8004613C
    // 0x805584EC: lui         $a0, 0x40A6
    ctx->r4 = S32(0X40A6 << 16);
    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x805584EC: lui         $a0, 0x40A6
    ctx->r4 = S32(0X40A6 << 16);
    after_2:
    // 0x805584F0: lui         $a0, 0x40A6
    ctx->r4 = S32(0X40A6 << 16);
    // 0x805584F4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x805584F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x805584FC: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x80558500: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80558504: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80558508: jal         0x8004613C
    // 0x8055850C: ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    func_8004613C(rdram, ctx);
        goto after_3;
    // 0x8055850C: ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    after_3:
    // 0x80558510: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80558514: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80558518: lui         $a3, 0xBB03
    ctx->r7 = S32(0XBB03 << 16);
    // 0x8055851C: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x80558520: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80558524: jal         0x8004613C
    // 0x80558528: lui         $a0, 0x40A7
    ctx->r4 = S32(0X40A7 << 16);
    func_8004613C(rdram, ctx);
        goto after_4;
    // 0x80558528: lui         $a0, 0x40A7
    ctx->r4 = S32(0X40A7 << 16);
    after_4:
    // 0x8055852C: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80558530: jal         0x80047090
    // 0x80558534: addiu       $a0, $zero, 0x40A4
    ctx->r4 = ADD32(0, 0X40A4);
    func_80047090(rdram, ctx);
        goto after_5;
    // 0x80558534: addiu       $a0, $zero, 0x40A4
    ctx->r4 = ADD32(0, 0X40A4);
    after_5:
    // 0x80558538: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8055853C: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x80558540: addiu       $a0, $zero, 0x40A5
    ctx->r4 = ADD32(0, 0X40A5);
    // 0x80558544: lhu         $t8, 0xE($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XE);
    // 0x80558548: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x8055854C: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80558550: jal         0x80047090
    // 0x80558554: sh          $t0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r8;
    func_80047090(rdram, ctx);
        goto after_6;
    // 0x80558554: sh          $t0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r8;
    after_6:
    // 0x80558558: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8055855C: andi        $t2, $v0, 0x3FF
    ctx->r10 = ctx->r2 & 0X3FF;
    // 0x80558560: addiu       $a0, $zero, 0x40A6
    ctx->r4 = ADD32(0, 0X40A6);
    // 0x80558564: lhu         $t3, 0xE($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0XE);
    // 0x80558568: andi        $t4, $t3, 0xFC00
    ctx->r12 = ctx->r11 & 0XFC00;
    // 0x8055856C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80558570: jal         0x80047090
    // 0x80558574: sh          $t5, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r13;
    func_80047090(rdram, ctx);
        goto after_7;
    // 0x80558574: sh          $t5, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r13;
    after_7:
    // 0x80558578: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x8055857C: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x80558580: addiu       $a0, $zero, 0x40A6
    ctx->r4 = ADD32(0, 0X40A6);
    // 0x80558584: lhu         $t7, 0xE($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0XE);
    // 0x80558588: andi        $t9, $t7, 0xFC00
    ctx->r25 = ctx->r15 & 0XFC00;
    // 0x8055858C: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80558590: jal         0x80047090
    // 0x80558594: sh          $t0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r8;
    func_80047090(rdram, ctx);
        goto after_8;
    // 0x80558594: sh          $t0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r8;
    after_8:
    // 0x80558598: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8055859C: andi        $t3, $v0, 0x3FF
    ctx->r11 = ctx->r2 & 0X3FF;
    // 0x805585A0: addiu       $a0, $zero, 0x40A7
    ctx->r4 = ADD32(0, 0X40A7);
    // 0x805585A4: lhu         $t2, 0xE($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0XE);
    // 0x805585A8: andi        $t4, $t2, 0xFC00
    ctx->r12 = ctx->r10 & 0XFC00;
    // 0x805585AC: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x805585B0: jal         0x80047090
    // 0x805585B4: sh          $t5, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r13;
    func_80047090(rdram, ctx);
        goto after_9;
    // 0x805585B4: sh          $t5, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r13;
    after_9:
    // 0x805585B8: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x805585BC: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x805585C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805585C4: lhu         $t8, 0xE($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XE);
    // 0x805585C8: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x805585CC: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x805585D0: sh          $t0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r8;
    // 0x805585D4: jal         0x80047F9C
    // 0x805585D8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_10;
    // 0x805585D8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x805585DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805585E0: jal         0x80047F9C
    // 0x805585E4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    func_80047F9C(rdram, ctx);
        goto after_11;
    // 0x805585E4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_11:
    // 0x805585E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805585EC: jal         0x80047F9C
    // 0x805585F0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    func_80047F9C(rdram, ctx);
        goto after_12;
    // 0x805585F0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_12:
    // 0x805585F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805585F8: jal         0x80047F9C
    // 0x805585FC: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    func_80047F9C(rdram, ctx);
        goto after_13;
    // 0x805585FC: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    after_13:
    // 0x80558600: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80558604: jal         0x80047F9C
    // 0x80558608: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    func_80047F9C(rdram, ctx);
        goto after_14;
    // 0x80558608: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    after_14:
    // 0x8055860C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80558610: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80558614: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80558618: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8055861C: jr          $ra
    // 0x80558620: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80558620: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8078AD80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078AD80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8078AD84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078AD88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078AD8C: lh          $t6, 0x184($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X184);
    // 0x8078AD90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8078AD94: bnel        $t6, $zero, L_8078AE24
    if (ctx->r14 != 0) {
        // 0x8078AD98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078AE24;
    }
    goto skip_0;
    // 0x8078AD98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8078AD9C: jal         0x80047090
    // 0x8078ADA0: addiu       $a0, $zero, 0x4410
    ctx->r4 = ADD32(0, 0X4410);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8078ADA0: addiu       $a0, $zero, 0x4410
    ctx->r4 = ADD32(0, 0X4410);
    after_0:
    // 0x8078ADA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8078ADA8: lui         $at, 0x4410
    ctx->r1 = S32(0X4410 << 16);
    // 0x8078ADAC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8078ADB0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8078ADB4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8078ADB8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8078ADBC: jal         0x8004613C
    // 0x8078ADC0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8078ADC0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x8078ADC4: beq         $v0, $zero, L_8078AE20
    if (ctx->r2 == 0) {
        // 0x8078ADC8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8078AE20;
    }
    // 0x8078ADC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8078ADCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078ADD0: jal         0x80047F9C
    // 0x8078ADD4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8078ADD4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x8078ADD8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8078ADDC: lw          $t7, 0x134($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X134);
    // 0x8078ADE0: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(793, 0XDD0) << 16);
    // 0x8078ADE4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8078ADE8: sw          $t7, 0x138($a1)
    MEM_W(0X138, ctx->r5) = ctx->r15;
    // 0x8078ADEC: lh          $t8, 0x144($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X144);
    // 0x8078ADF0: sw          $t8, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r24;
    // 0x8078ADF4: lw          $t9, 0x134($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X134);
    // 0x8078ADF8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8078ADFC: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8078AE00: lwc1        $f4, -0x4FF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(793, 0XDD0));
    // 0x8078AE04: swc1        $f6, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f6.u32l;
    // 0x8078AE08: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(793, 0XE00) << 16);
    // 0x8078AE0C: swc1        $f4, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f4.u32l;
    // 0x8078AE10: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8078AE14: lwc1        $f8, -0x4FC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(793, 0XE00));
    // 0x8078AE18: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8078AE1C: swc1        $f16, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f16.u32l;
L_8078AE20:
    // 0x8078AE20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078AE24:
    // 0x8078AE24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078AE28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8078AE2C: jr          $ra
    // 0x8078AE30: nop

    return;
    // 0x8078AE30: nop

    // 0x8078AE34: nop

    // 0x8078AE38: nop

    // 0x8078AE3C: nop

;}
RECOMP_FUNC void func_80033EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033EA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80033EA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80033EAC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80033EB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80033EB4: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80033EB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80033EBC: jal         0x800421B4
    // 0x80033EC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800421B4(rdram, ctx);
        goto after_0;
    // 0x80033EC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80033EC4: beq         $v0, $zero, L_80033F9C
    if (ctx->r2 == 0) {
        // 0x80033EC8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80033F9C;
    }
    // 0x80033EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033ECC: jal         0x800411E8
    // 0x80033ED0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800411E8(rdram, ctx);
        goto after_1;
    // 0x80033ED0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80033ED4: jal         0x800433D0
    // 0x80033ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800433D0(rdram, ctx);
        goto after_2;
    // 0x80033ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80033EDC: jal         0x80041D3C
    // 0x80033EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80041D3C(rdram, ctx);
        goto after_3;
    // 0x80033EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80033EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033EE8: jal         0x80032E64
    // 0x80033EEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80032E64(rdram, ctx);
        goto after_4;
    // 0x80033EEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80033EF0: jal         0x80066DE4
    // 0x80033EF4: lwc1        $f12, 0x188($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X188);
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x80033EF4: lwc1        $f12, 0x188($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X188);
    after_5:
    // 0x80033EF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033EFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80033F00: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80033F04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80033F08: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80033F0C: addiu       $a1, $a1, -0x6EB8
    ctx->r5 = ADD32(ctx->r5, -0X6EB8);
    // 0x80033F10: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80033F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033F18: sub.s       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80033F1C: div.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80033F20: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80033F24: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80033F28: jal         0x800491B8
    // 0x80033F2C: nop

    func_800491B8(rdram, ctx);
        goto after_6;
    // 0x80033F2C: nop

    after_6:
    // 0x80033F30: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x80033F34: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80033F38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80033F3C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80033F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033F44: lw          $t8, 0x70($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X70);
    // 0x80033F48: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80033F4C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80033F50: jal         0x800331A4
    // 0x80033F54: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    func_800331A4(rdram, ctx);
        goto after_7;
    // 0x80033F54: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    after_7:
    // 0x80033F58: jal         0x80041450
    // 0x80033F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80041450(rdram, ctx);
        goto after_8;
    // 0x80033F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80033F60: lw          $t9, 0xAC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XAC);
    // 0x80033F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033F68: jalr        $t9
    // 0x80033F6C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x80033F6C: nop

    after_9:
    // 0x80033F70: beql        $v0, $zero, L_80033FA0
    if (ctx->r2 == 0) {
        // 0x80033F74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80033FA0;
    }
    goto skip_0;
    // 0x80033F74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80033F78: lw          $t9, 0xB8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XB8);
    // 0x80033F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033F80: jalr        $t9
    // 0x80033F84: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_10;
    // 0x80033F84: nop

    after_10:
    // 0x80033F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033F8C: jal         0x80041214
    // 0x80033F90: lw          $a1, 0x58($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X58);
    func_80041214(rdram, ctx);
        goto after_11;
    // 0x80033F90: lw          $a1, 0x58($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X58);
    after_11:
    // 0x80033F94: jal         0x80023EA0
    // 0x80033F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80023EA0(rdram, ctx);
        goto after_12;
    // 0x80033F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_80033F9C:
    // 0x80033F9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80033FA0:
    // 0x80033FA0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80033FA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80033FA8: jr          $ra
    // 0x80033FAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80033FAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005C9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C9A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C9AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C9B0: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x8005C9B4: beq         $t6, $zero, L_8005C9C8
    if (ctx->r14 == 0) {
        // 0x8005C9B8: nop
    
            goto L_8005C9C8;
    }
    // 0x8005C9B8: nop

    // 0x8005C9BC: jal         0x80045414
    // 0x8005C9C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045414(rdram, ctx);
        goto after_0;
    // 0x8005C9C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005C9C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8005C9C8:
    // 0x8005C9C8: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8005C9CC: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x8005C9D0: addiu       $t8, $t8, 0x5BD8
    ctx->r24 = ADD32(ctx->r24, 0X5BD8);
    // 0x8005C9D4: sb          $t7, 0x164($a0)
    MEM_B(0X164, ctx->r4) = ctx->r15;
    // 0x8005C9D8: sw          $t8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r24;
    // 0x8005C9DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C9E0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005C9E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C9E8: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x8005C9EC: jr          $ra
    // 0x8005C9F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005C9F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80740F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80740F4C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80740F50: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80740F54: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80740F58: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80740F5C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80740F60: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80740F64: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80740F68: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80740F6C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80740F70: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80740F74: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80740F78: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80740F7C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80740F80: lw          $fp, 0x1F4($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X1F4);
    // 0x80740F84: lui         $a0, 0x463A
    ctx->r4 = S32(0X463A << 16);
    // 0x80740F88: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x80740F8C: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80740F90: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x80740F94: lui         $a1, 0x4288
    ctx->r5 = S32(0X4288 << 16);
    // 0x80740F98: jal         0x8004613C
    // 0x80740F9C: lui         $a2, 0xC2BA
    ctx->r6 = S32(0XC2BA << 16);
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x80740F9C: lui         $a2, 0xC2BA
    ctx->r6 = S32(0XC2BA << 16);
    after_0:
    // 0x80740FA0: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x80740FA4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80740FA8: jal         0x80047F9C
    // 0x80740FAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x80740FAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80740FB0: lui         $a0, 0x463F
    ctx->r4 = S32(0X463F << 16);
    // 0x80740FB4: lui         $a3, 0xBB03
    ctx->r7 = S32(0XBB03 << 16);
    // 0x80740FB8: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80740FBC: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x80740FC0: lui         $a1, 0xC2F0
    ctx->r5 = S32(0XC2F0 << 16);
    // 0x80740FC4: jal         0x8004613C
    // 0x80740FC8: lui         $a2, 0xC2A0
    ctx->r6 = S32(0XC2A0 << 16);
    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x80740FC8: lui         $a2, 0xC2A0
    ctx->r6 = S32(0XC2A0 << 16);
    after_2:
    // 0x80740FCC: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X11D0) << 16);
    // 0x80740FD0: lwc1        $f0, 0x2030($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(751, 0X11D0));
    // 0x80740FD4: sw          $v0, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r2;
    // 0x80740FD8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80740FDC: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x80740FE0: lw          $t6, 0x4($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X4);
    // 0x80740FE4: swc1        $f0, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f0.u32l;
    // 0x80740FE8: jal         0x80047F9C
    // 0x80740FEC: lw          $a1, 0x4($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X4);
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x80740FEC: lw          $a1, 0x4($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X4);
    after_3:
    // 0x80740FF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80740FF4: lui         $s0, 0x463F
    ctx->r16 = S32(0X463F << 16);
    // 0x80740FF8: addiu       $s4, $zero, 0x201
    ctx->r20 = ADD32(0, 0X201);
    // 0x80740FFC: lui         $a3, 0xBB44
    ctx->r7 = S32(0XBB44 << 16);
    // 0x80741000: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80741004: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80741008: ori         $a3, $a3, 0x9BA6
    ctx->r7 = ctx->r7 | 0X9BA6;
    // 0x8074100C: jal         0x8004613C
    // 0x80741010: or          $a0, $s4, $s0
    ctx->r4 = ctx->r20 | ctx->r16;
    func_8004613C(rdram, ctx);
        goto after_4;
    // 0x80741010: or          $a0, $s4, $s0
    ctx->r4 = ctx->r20 | ctx->r16;
    after_4:
    // 0x80741014: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X11D4) << 16);
    // 0x80741018: lwc1        $f0, 0x2034($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(751, 0X11D4));
    // 0x8074101C: sw          $v0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r2;
    // 0x80741020: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80741024: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x80741028: lw          $t7, 0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X8);
    // 0x8074102C: swc1        $f0, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->f0.u32l;
    // 0x80741030: jal         0x80047F9C
    // 0x80741034: lw          $a1, 0x8($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X8);
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x80741034: lw          $a1, 0x8($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X8);
    after_5:
    // 0x80741038: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8074103C: andi        $s4, $s4, 0xFFFF
    ctx->r20 = ctx->r20 & 0XFFFF;
    // 0x80741040: lui         $a3, 0xBB83
    ctx->r7 = S32(0XBB83 << 16);
    // 0x80741044: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80741048: or          $a0, $s4, $s0
    ctx->r4 = ctx->r20 | ctx->r16;
    // 0x8074104C: lui         $a1, 0xC270
    ctx->r5 = S32(0XC270 << 16);
    // 0x80741050: jal         0x8004613C
    // 0x80741054: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_8004613C(rdram, ctx);
        goto after_6;
    // 0x80741054: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_6:
    // 0x80741058: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8074105C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80741060: sw          $v0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r2;
    // 0x80741064: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80741068: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x8074106C: lw          $t8, 0xC($fp)
    ctx->r24 = MEM_W(ctx->r30, 0XC);
    // 0x80741070: swc1        $f0, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f0.u32l;
    // 0x80741074: jal         0x80047F9C
    // 0x80741078: lw          $a1, 0xC($fp)
    ctx->r5 = MEM_W(ctx->r30, 0XC);
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x80741078: lw          $a1, 0xC($fp)
    ctx->r5 = MEM_W(ctx->r30, 0XC);
    after_7:
    // 0x8074107C: lui         $s2, 0x8074
    ctx->r18 = S32(RELOC_HI16(751, 0X10CC) << 16);
    // 0x80741080: lui         $s3, 0x8074
    ctx->r19 = S32(RELOC_HI16(751, 0X10F4) << 16);
    // 0x80741084: lui         $s1, 0x8074
    ctx->r17 = S32(RELOC_HI16(751, 0X111C) << 16);
    // 0x80741088: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X11D8) << 16);
    // 0x8074108C: lui         $s6, 0x8074
    ctx->r22 = S32(RELOC_HI16(751, 0X1144) << 16);
    // 0x80741090: addiu       $s4, $zero, 0x200
    ctx->r20 = ADD32(0, 0X200);
    // 0x80741094: addiu       $s6, $s6, 0x1FA4
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(751, 0X1144));
    // 0x80741098: lwc1        $f20, 0x2038($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(751, 0X11D8));
    // 0x8074109C: addiu       $s1, $s1, 0x1F7C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(751, 0X111C));
    // 0x807410A0: addiu       $s3, $s3, 0x1F54
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(751, 0X10F4));
    // 0x807410A4: addiu       $s2, $s2, 0x1F2C
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(751, 0X10CC));
    // 0x807410A8: or          $s0, $fp, $zero
    ctx->r16 = ctx->r30 | 0;
    // 0x807410AC: lui         $s5, 0x463D
    ctx->r21 = S32(0X463D << 16);
L_807410B0:
    // 0x807410B0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x807410B4: or          $a0, $s4, $s5
    ctx->r4 = ctx->r20 | ctx->r21;
    // 0x807410B8: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x807410BC: jal         0x8004613C
    // 0x807410C0: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    func_8004613C(rdram, ctx);
        goto after_8;
    // 0x807410C0: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    after_8:
    // 0x807410C4: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x807410C8: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x807410CC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x807410D0: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    // 0x807410D4: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x807410D8: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x807410DC: swc1        $f6, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f6.u32l;
    // 0x807410E0: jal         0x80047F9C
    // 0x807410E4: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    func_80047F9C(rdram, ctx);
        goto after_9;
    // 0x807410E4: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    after_9:
    // 0x807410E8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807410EC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x807410F0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x807410F4: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x807410F8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x807410FC: bne         $s1, $s6, L_807410B0
    if (ctx->r17 != ctx->r22) {
        // 0x80741100: andi        $s4, $s4, 0xFFFF
        ctx->r20 = ctx->r20 & 0XFFFF;
            goto L_807410B0;
    }
    // 0x80741100: andi        $s4, $s4, 0xFFFF
    ctx->r20 = ctx->r20 & 0XFFFF;
    // 0x80741104: sw          $zero, 0x40($fp)
    MEM_W(0X40, ctx->r30) = 0;
    // 0x80741108: sw          $zero, 0x44($fp)
    MEM_W(0X44, ctx->r30) = 0;
    // 0x8074110C: sw          $zero, 0x48($fp)
    MEM_W(0X48, ctx->r30) = 0;
    // 0x80741110: sw          $zero, 0x4C($fp)
    MEM_W(0X4C, ctx->r30) = 0;
    // 0x80741114: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80741118: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8074111C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80741120: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80741124: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80741128: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8074112C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80741130: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80741134: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80741138: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8074113C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80741140: jr          $ra
    // 0x80741144: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80741144: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8003112C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003112C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031134: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031138: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003113C: jal         0x800310A0
    // 0x80031140: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x80031140: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80031144: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80031148: jal         0x80030BDC
    // 0x8003114C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80030BDC(rdram, ctx);
        goto after_1;
    // 0x8003114C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80031150: beq         $v0, $zero, L_80031160
    if (ctx->r2 == 0) {
        // 0x80031154: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80031160;
    }
    // 0x80031154: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80031158: jal         0x800310D0
    // 0x8003115C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800310D0(rdram, ctx);
        goto after_2;
    // 0x8003115C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_80031160:
    // 0x80031160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031164: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80031168: jr          $ra
    // 0x8003116C: nop

    return;
    // 0x8003116C: nop

;}
RECOMP_FUNC void func_80038684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003868C: jal         0x80022280
    // 0x80038690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80022280(rdram, ctx);
        goto after_0;
    // 0x80038690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038694: jal         0x80023D08
    // 0x80038698: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80023D08(rdram, ctx);
        goto after_1;
    // 0x80038698: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8003869C: jal         0x80023EA0
    // 0x800386A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80023EA0(rdram, ctx);
        goto after_2;
    // 0x800386A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800386A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800386A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800386AC: jr          $ra
    // 0x800386B0: nop

    return;
    // 0x800386B0: nop

;}
RECOMP_FUNC void func_806F9EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9EA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F9EA8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x806F9EAC: lbu         $t7, -0x7204($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X7204);
    // 0x806F9EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F9EB4: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x806F9EB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806F9EBC: bne         $t7, $at, L_806F9ED4
    if (ctx->r15 != ctx->r1) {
        // 0x806F9EC0: lw          $v0, 0x88($t6)
        ctx->r2 = MEM_W(ctx->r14, 0X88);
            goto L_806F9ED4;
    }
    // 0x806F9EC0: lw          $v0, 0x88($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X88);
    // 0x806F9EC4: addiu       $a1, $v0, 0x200
    ctx->r5 = ADD32(ctx->r2, 0X200);
    // 0x806F9EC8: jal         0x8004590C
    // 0x806F9ECC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x806F9ECC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F9ED0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_806F9ED4:
    // 0x806F9ED4: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x806F9ED8: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(700, 0X2A88) << 16);
    // 0x806F9EDC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806F9EE0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806F9EE4: addiu       $t8, $t8, -0x3948
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(700, 0X2A88));
    // 0x806F9EE8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x806F9EEC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806F9EF0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806F9EF4: sw          $t0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r8;
    // 0x806F9EF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F9EFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F9F00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806F9F04: jal         0x806FA608
    // 0x806F9F08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806FA608(rdram, ctx);
        goto after_1;
    // 0x806F9F08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x806F9F0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F9F10: lui         $t1, 0x8070
    ctx->r9 = S32(RELOC_HI16(700, 0X300) << 16);
    // 0x806F9F14: addiu       $t1, $t1, -0x60D0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(700, 0X300));
    // 0x806F9F18: lw          $t2, 0x16C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X16C);
    // 0x806F9F1C: sw          $t1, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r9;
    // 0x806F9F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F9F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F9F28: jr          $ra
    // 0x806F9F2C: nop

    return;
    // 0x806F9F2C: nop

;}
RECOMP_FUNC void func_804EF95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF95C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EF960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF964: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804EF968: jal         0x80057640
    // 0x804EF96C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80057640(rdram, ctx);
        goto after_0;
    // 0x804EF96C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x804EF970: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804EF974: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x804EF978: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x804EF97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EF980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EF984: jr          $ra
    // 0x804EF988: nop

    return;
    // 0x804EF988: nop

;}
RECOMP_FUNC void func_804C8E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C8E98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C8E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C8EA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C8EA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C8EA8: jal         0x804C91F8
    // 0x804C8EAC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_804C91F8(rdram, ctx);
        goto after_0;
    // 0x804C8EAC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x804C8EB0: jal         0x8005FE48
    // 0x804C8EB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x804C8EB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804C8EB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C8EBC: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(225, 0X93C) << 16);
    // 0x804C8EC0: lwc1        $f0, -0x6D84($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(225, 0X93C));
    // 0x804C8EC4: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x804C8EC8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x804C8ECC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804C8ED0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x804C8ED4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804C8ED8: sb          $zero, 0x75($t7)
    MEM_B(0X75, ctx->r15) = 0;
    // 0x804C8EDC: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x804C8EE0: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x804C8EE4: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x804C8EE8: swc1        $f6, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f6.u32l;
    // 0x804C8EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C8EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C8EF4: jr          $ra
    // 0x804C8EF8: nop

    return;
    // 0x804C8EF8: nop

;}
RECOMP_FUNC void func_80522A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80522A8C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80522A90: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(321, 0X524) << 16);
    // 0x80522A94: addiu       $t6, $t6, 0x27D4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(321, 0X524));
    // 0x80522A98: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80522A9C: jr          $ra
    // 0x80522AA0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80522AA0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_804716D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804716D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804716D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804716DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804716E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804716E4: jal         0x80051194
    // 0x804716E8: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x804716E8: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x804716EC: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x804716F0: jal         0x80471D7C
    // 0x804716F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80471D7C(rdram, ctx);
        goto after_1;
    // 0x804716F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804716F8: beq         $v0, $zero, L_804717FC
    if (ctx->r2 == 0) {
        // 0x804716FC: nop
    
            goto L_804717FC;
    }
    // 0x804716FC: nop

    // 0x80471700: jal         0x80471DB4
    // 0x80471704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80471DB4(rdram, ctx);
        goto after_2;
    // 0x80471704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80471708: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8047170C: sh          $t6, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r14;
    // 0x80471710: lh          $t7, 0x1F0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1F0);
    // 0x80471714: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x80471718: lui         $t9, 0x8047
    ctx->r25 = S32(RELOC_HI16(158, 0X19F8) << 16);
    // 0x8047171C: addiu       $t9, $t9, 0x2EB8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(158, 0X19F8));
    // 0x80471720: sh          $t7, 0x30($t8)
    MEM_H(0X30, ctx->r24) = ctx->r15;
    // 0x80471724: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x80471728: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8047172C: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x80471730: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80471734: lw          $t1, 0x180($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X180);
    // 0x80471738: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8047173C: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x80471740: beq         $t1, $zero, L_80471750
    if (ctx->r9 == 0) {
        // 0x80471744: addiu       $t2, $t2, -0x7C48
        ctx->r10 = ADD32(ctx->r10, -0X7C48);
            goto L_80471750;
    }
    // 0x80471744: addiu       $t2, $t2, -0x7C48
    ctx->r10 = ADD32(ctx->r10, -0X7C48);
    // 0x80471748: b           L_8047176C
    // 0x8047174C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
        goto L_8047176C;
    // 0x8047174C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
L_80471750:
    // 0x80471750: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80471754: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80471758: sw          $t2, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r10;
    // 0x8047175C: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(158, 0X1AE0) << 16);
    // 0x80471760: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
    // 0x80471764: lwc1        $f6, 0x2FA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(158, 0X1AE0));
    // 0x80471768: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
L_8047176C:
    // 0x8047176C: lw          $t3, 0x180($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X180);
    // 0x80471770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80471774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80471778: beq         $t3, $zero, L_8047179C
    if (ctx->r11 == 0) {
        // 0x8047177C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8047179C;
    }
    // 0x8047177C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80471780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80471784: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80471788: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8047178C: jal         0x80472C94
    // 0x80471790: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80472C94(rdram, ctx);
        goto after_3;
    // 0x80471790: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x80471794: b           L_804717A4
    // 0x80471798: nop

        goto L_804717A4;
    // 0x80471798: nop

L_8047179C:
    // 0x8047179C: jal         0x80472C94
    // 0x804717A0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80472C94(rdram, ctx);
        goto after_4;
    // 0x804717A0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
L_804717A4:
    // 0x804717A4: lui         $t4, 0x8047
    ctx->r12 = S32(RELOC_HI16(158, 0X1E4) << 16);
    // 0x804717A8: lw          $t6, 0x16C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X16C);
    // 0x804717AC: addiu       $t4, $t4, 0x16A4
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(158, 0X1E4));
    // 0x804717B0: lui         $t5, 0x8047
    ctx->r13 = S32(RELOC_HI16(158, 0XAF8) << 16);
    // 0x804717B4: sw          $t4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r12;
    // 0x804717B8: addiu       $t5, $t5, 0x1FB8
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(158, 0XAF8));
    // 0x804717BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804717C0: jal         0x80472CD8
    // 0x804717C4: sw          $t5, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r13;
    func_80472CD8(rdram, ctx);
        goto after_5;
    // 0x804717C4: sw          $t5, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r13;
    after_5:
    // 0x804717C8: bnel        $v0, $zero, L_80471808
    if (ctx->r2 != 0) {
        // 0x804717CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80471808;
    }
    goto skip_0;
    // 0x804717CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804717D0: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    // 0x804717D4: beq         $a0, $zero, L_804717EC
    if (ctx->r4 == 0) {
        // 0x804717D8: nop
    
            goto L_804717EC;
    }
    // 0x804717D8: nop

    // 0x804717DC: jal         0x800445A4
    // 0x804717E0: nop

    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x804717E0: nop

    after_6:
    // 0x804717E4: b           L_80471808
    // 0x804717E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80471808;
    // 0x804717E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804717EC:
    // 0x804717EC: jal         0x800445A4
    // 0x804717F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_7;
    // 0x804717F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x804717F4: b           L_80471808
    // 0x804717F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80471808;
    // 0x804717F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804717FC:
    // 0x804717FC: jal         0x800445A4
    // 0x80471800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x80471800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80471804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80471808:
    // 0x80471808: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8047180C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80471810: jr          $ra
    // 0x80471814: nop

    return;
    // 0x80471814: nop

;}
RECOMP_FUNC void func_80567D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80567D04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80567D08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80567D0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80567D10: jal         0x8004700C
    // 0x80567D14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80567D14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80567D18: beql        $v0, $zero, L_80567DC4
    if (ctx->r2 == 0) {
        // 0x80567D1C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80567DC4;
    }
    goto skip_0;
    // 0x80567D1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80567D20: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x80567D24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80567D28: bnel        $t6, $at, L_80567DC4
    if (ctx->r14 != ctx->r1) {
        // 0x80567D2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80567DC4;
    }
    goto skip_1;
    // 0x80567D2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80567D30: lbu         $t7, 0x30($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X30);
    // 0x80567D34: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80567D38: bnel        $t7, $at, L_80567DC4
    if (ctx->r15 != ctx->r1) {
        // 0x80567D3C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80567DC4;
    }
    goto skip_2;
    // 0x80567D3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80567D40: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80567D44: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80567D48: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2194) << 16);
    // 0x80567D4C: lwc1        $f8, -0x68BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2194));
    // 0x80567D50: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80567D54: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80567D58: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80567D5C: nop

    // 0x80567D60: bc1fl       L_80567DC4
    if (!c1cs) {
        // 0x80567D64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80567DC4;
    }
    goto skip_3;
    // 0x80567D64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80567D68: lw          $t8, 0x174($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X174);
    // 0x80567D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80567D70: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80567D74: andi        $t0, $t9, 0xF00
    ctx->r8 = ctx->r25 & 0XF00;
    // 0x80567D78: beql        $t0, $zero, L_80567DC4
    if (ctx->r8 == 0) {
        // 0x80567D7C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80567DC4;
    }
    goto skip_4;
    // 0x80567D7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80567D80: jal         0x8005FDC4
    // 0x80567D84: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    func_8005FDC4(rdram, ctx);
        goto after_1;
    // 0x80567D84: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    after_1:
    // 0x80567D88: jal         0x80567AC4
    // 0x80567D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80567AC4(rdram, ctx);
        goto after_2;
    // 0x80567D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80567D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80567D94: jal         0x80569310
    // 0x80567D98: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80569310(rdram, ctx);
        goto after_3;
    // 0x80567D98: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80567D9C: lbu         $t1, 0xE($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XE);
    // 0x80567DA0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80567DA4: andi        $t2, $t1, 0xFF03
    ctx->r10 = ctx->r9 & 0XFF03;
    // 0x80567DA8: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80567DAC: jal         0x80067E68
    // 0x80567DB0: sb          $t3, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r11;
    func_80067E68(rdram, ctx);
        goto after_4;
    // 0x80567DB0: sb          $t3, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r11;
    after_4:
    // 0x80567DB4: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80567DB8: jal         0x80067818
    // 0x80567DBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x80567DBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80567DC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80567DC4:
    // 0x80567DC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80567DC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80567DCC: jr          $ra
    // 0x80567DD0: nop

    return;
    // 0x80567DD0: nop

;}
RECOMP_FUNC void func_80421758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042175C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80421760: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80421764: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80421768: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042176C: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(32, 0X15FC) << 16);
    // 0x80421770: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80421774: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80421778: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042177C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80421780: lw          $t8, 0x26BC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(32, 0X15FC));
    // 0x80421784: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80421788: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042178C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80421790: jal         0x80048490
    // 0x80421794: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80421794: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80421798: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8042179C: jal         0x80048378
    // 0x804217A0: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804217A0: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804217A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804217A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804217AC: jr          $ra
    // 0x804217B0: nop

    return;
    // 0x804217B0: nop

;}
RECOMP_FUNC void func_8000AC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AC34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000AC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AC3C: lui         $a0, 0xFA00
    ctx->r4 = S32(0XFA00 << 16);
    // 0x8000AC40: jal         0x8000A364
    // 0x8000AC44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000A364(rdram, ctx);
        goto after_0;
    // 0x8000AC44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8000AC48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000AC4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000AC50: jr          $ra
    // 0x8000AC54: nop

    return;
    // 0x8000AC54: nop

;}
RECOMP_FUNC void func_8044A5CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A5CC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044A5D0: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X13444) << 16);
    // 0x8044A5D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A5D8: addiu       $t6, $t6, 0x7824
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X13444));
    // 0x8044A5DC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044A5E0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044A5E4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044A5E8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044A5EC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044A5F0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A5F4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044A5F8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044A5FC: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044A600: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044A604: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044A608: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044A60C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044A610: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044A614: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044A618: jal         0x80050A50
    // 0x8044A61C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044A61C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044A620: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044A624: jalr        $v0
    // 0x8044A628: sw          $v0, 0x6A4C($v1)
    MEM_W(0X6A4C, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044A628: sw          $v0, 0x6A4C($v1)
    MEM_W(0X6A4C, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044A62C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A630: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8044A634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044A638: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044A63C: jr          $ra
    // 0x8044A640: nop

    return;
    // 0x8044A640: nop

;}
RECOMP_FUNC void func_80715164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80715164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80715168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8071516C: jal         0x8004700C
    // 0x80715170: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80715170: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80715174: beq         $v0, $zero, L_807151B8
    if (ctx->r2 == 0) {
        // 0x80715178: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807151B8;
    }
    // 0x80715178: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8071517C: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80715180: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80715184: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80715188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8071518C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80715190: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80715194: bc1f        L_807151B0
    if (!c1cs) {
        // 0x80715198: nop
    
            goto L_807151B0;
    }
    // 0x80715198: nop

    // 0x8071519C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807151A0: jal         0x80715C24
    // 0x807151A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80715C24(rdram, ctx);
        goto after_1;
    // 0x807151A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x807151A8: b           L_807151BC
    // 0x807151AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807151BC;
    // 0x807151AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807151B0:
    // 0x807151B0: jal         0x80715C24
    // 0x807151B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80715C24(rdram, ctx);
        goto after_2;
    // 0x807151B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
L_807151B8:
    // 0x807151B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807151BC:
    // 0x807151BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807151C0: jr          $ra
    // 0x807151C4: nop

    return;
    // 0x807151C4: nop

;}
RECOMP_FUNC void func_80432A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432A60: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80432A64: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(62, 0X26C) << 16);
    // 0x80432A68: addiu       $t6, $t6, 0x2A0C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(62, 0X26C));
    // 0x80432A6C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80432A70: jr          $ra
    // 0x80432A74: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80432A74: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80010688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010688: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001068C: addiu       $v0, $v0, -0x6DA0
    ctx->r2 = ADD32(ctx->r2, -0X6DA0);
    // 0x80010690: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80010694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80010698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001069C: beq         $t6, $zero, L_800106BC
    if (ctx->r14 == 0) {
        // 0x800106A0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800106BC;
    }
    // 0x800106A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800106A4: jal         0x8001B960
    // 0x800106A8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_8001B960(rdram, ctx);
        goto after_0;
    // 0x800106A8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_0:
    // 0x800106AC: jal         0x80011AAC
    // 0x800106B0: nop

    func_80011AAC(rdram, ctx);
        goto after_1;
    // 0x800106B0: nop

    after_1:
    // 0x800106B4: jal         0x80011540
    // 0x800106B8: nop

    func_80011540(rdram, ctx);
        goto after_2;
    // 0x800106B8: nop

    after_2:
L_800106BC:
    // 0x800106BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800106C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800106C4: jr          $ra
    // 0x800106C8: nop

    return;
    // 0x800106C8: nop

;}
RECOMP_FUNC void func_8002AAF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AAF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002AAF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002AAF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002AAFC: lbu         $v0, 0x18($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X18);
    // 0x8002AB00: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8002AB04: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8002AB08: bne         $at, $zero, L_8002AB30
    if (ctx->r1 != 0) {
        // 0x8002AB0C: slti        $at, $v0, 0x8
        ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
            goto L_8002AB30;
    }
    // 0x8002AB0C: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8002AB10: bne         $at, $zero, L_8002AB20
    if (ctx->r1 != 0) {
        // 0x8002AB14: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8002AB20;
    }
    // 0x8002AB14: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8002AB18: bne         $at, $zero, L_8002AB30
    if (ctx->r1 != 0) {
        // 0x8002AB1C: nop
    
            goto L_8002AB30;
    }
    // 0x8002AB1C: nop

L_8002AB20:
    // 0x8002AB20: lbu         $t6, 0x30($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X30);
    // 0x8002AB24: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8002AB28: beql        $t6, $at, L_8002ABC0
    if (ctx->r14 == ctx->r1) {
        // 0x8002AB2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002ABC0;
    }
    goto skip_0;
    // 0x8002AB2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8002AB30:
    // 0x8002AB30: jal         0x8002A630
    // 0x8002AB34: nop

    func_8002A630(rdram, ctx);
        goto after_0;
    // 0x8002AB34: nop

    after_0:
    // 0x8002AB38: beql        $v0, $zero, L_8002ABC0
    if (ctx->r2 == 0) {
        // 0x8002AB3C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002ABC0;
    }
    goto skip_1;
    // 0x8002AB3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8002AB40: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x8002AB44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002AB48: lbu         $t8, 0x12($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X12);
    // 0x8002AB4C: beql        $t8, $zero, L_8002AB98
    if (ctx->r24 == 0) {
        // 0x8002AB50: lh          $a2, 0xC2($s0)
        ctx->r6 = MEM_H(ctx->r16, 0XC2);
            goto L_8002AB98;
    }
    goto skip_2;
    // 0x8002AB50: lh          $a2, 0xC2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XC2);
    skip_2:
    // 0x8002AB54: lh          $v0, 0x13E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X13E);
    // 0x8002AB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002AB5C: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x8002AB60: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8002AB64: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002AB68: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002AB6C: jal         0x800475EC
    // 0x8002AB70: addiu       $a2, $v0, 0xF0
    ctx->r6 = ADD32(ctx->r2, 0XF0);
    func_800475EC(rdram, ctx);
        goto after_1;
    // 0x8002AB70: addiu       $a2, $v0, 0xF0
    ctx->r6 = ADD32(ctx->r2, 0XF0);
    after_1:
    // 0x8002AB74: beql        $v0, $zero, L_8002ABC0
    if (ctx->r2 == 0) {
        // 0x8002AB78: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002ABC0;
    }
    goto skip_3;
    // 0x8002AB78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8002AB7C: jal         0x800677F8
    // 0x8002AB80: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800677F8(rdram, ctx);
        goto after_2;
    // 0x8002AB80: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8002AB84: jal         0x8002FC7C
    // 0x8002AB88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002FC7C(rdram, ctx);
        goto after_3;
    // 0x8002AB88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8002AB8C: b           L_8002ABC0
    // 0x8002AB90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8002ABC0;
    // 0x8002AB90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002AB94: lh          $a2, 0xC2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XC2);
L_8002AB98:
    // 0x8002AB98: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x8002AB9C: jal         0x800475EC
    // 0x8002ABA0: addiu       $a2, $a2, 0xF0
    ctx->r6 = ADD32(ctx->r6, 0XF0);
    func_800475EC(rdram, ctx);
        goto after_4;
    // 0x8002ABA0: addiu       $a2, $a2, 0xF0
    ctx->r6 = ADD32(ctx->r6, 0XF0);
    after_4:
    // 0x8002ABA4: beql        $v0, $zero, L_8002ABC0
    if (ctx->r2 == 0) {
        // 0x8002ABA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002ABC0;
    }
    goto skip_4;
    // 0x8002ABA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8002ABAC: jal         0x800677F8
    // 0x8002ABB0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800677F8(rdram, ctx);
        goto after_5;
    // 0x8002ABB0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x8002ABB4: jal         0x8002FC7C
    // 0x8002ABB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002FC7C(rdram, ctx);
        goto after_6;
    // 0x8002ABB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8002ABBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002ABC0:
    // 0x8002ABC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002ABC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002ABC8: jr          $ra
    // 0x8002ABCC: nop

    return;
    // 0x8002ABCC: nop

;}
RECOMP_FUNC void func_8059FFE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059FFE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8059FFE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8059FFE8: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8059FFEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8059FFF0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8059FFF4: lw          $a1, 0xC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC);
    // 0x8059FFF8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8059FFFC: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    // 0x805A0000: bnel        $a1, $zero, L_805A0094
    if (ctx->r5 != 0) {
        // 0x805A0004: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_805A0094;
    }
    goto skip_0;
    // 0x805A0004: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x805A0008: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x805A000C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x805A0010: slti        $at, $t7, 0x78
    ctx->r1 = SIGNED(ctx->r15) < 0X78 ? 1 : 0;
    // 0x805A0014: bne         $at, $zero, L_805A0198
    if (ctx->r1 != 0) {
        // 0x805A0018: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_805A0198;
    }
    // 0x805A0018: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x805A001C: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x805A0020: blez        $v0, L_805A0088
    if (SIGNED(ctx->r2) <= 0) {
        // 0x805A0024: slti        $at, $v0, 0x140
        ctx->r1 = SIGNED(ctx->r2) < 0X140 ? 1 : 0;
            goto L_805A0088;
    }
    // 0x805A0024: slti        $at, $v0, 0x140
    ctx->r1 = SIGNED(ctx->r2) < 0X140 ? 1 : 0;
    // 0x805A0028: beq         $at, $zero, L_805A0088
    if (ctx->r1 == 0) {
        // 0x805A002C: nop
    
            goto L_805A0088;
    }
    // 0x805A002C: nop

    // 0x805A0030: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x805A0034: blez        $v0, L_805A0088
    if (SIGNED(ctx->r2) <= 0) {
        // 0x805A0038: slti        $at, $v0, 0xF0
        ctx->r1 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
            goto L_805A0088;
    }
    // 0x805A0038: slti        $at, $v0, 0xF0
    ctx->r1 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // 0x805A003C: beq         $at, $zero, L_805A0088
    if (ctx->r1 == 0) {
        // 0x805A0040: addiu       $a1, $zero, 0x4059
        ctx->r5 = ADD32(0, 0X4059);
            goto L_805A0088;
    }
    // 0x805A0040: addiu       $a1, $zero, 0x4059
    ctx->r5 = ADD32(0, 0X4059);
    // 0x805A0044: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A0048: jal         0x8059FF74
    // 0x805A004C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_8059FF74(rdram, ctx);
        goto after_0;
    // 0x805A004C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
    // 0x805A0050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A0054: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x805A0058: beq         $v0, $zero, L_805A0088
    if (ctx->r2 == 0) {
        // 0x805A005C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_805A0088;
    }
    // 0x805A005C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x805A0060: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A0064: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x805A0068: jal         0x80047F9C
    // 0x805A006C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x805A006C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_1:
    // 0x805A0070: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x805A0074: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x805A0078: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A007C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805A0080: sb          $t9, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r25;
    // 0x805A0084: sw          $a1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r5;
L_805A0088:
    // 0x805A0088: b           L_805A0198
    // 0x805A008C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
        goto L_805A0198;
    // 0x805A008C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805A0090: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_805A0094:
    // 0x805A0094: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_805A0098:
    // 0x805A0098: lw          $t1, 0x188($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X188);
    // 0x805A009C: bnel        $a1, $t1, L_805A00D8
    if (ctx->r5 != ctx->r9) {
        // 0x805A00A0: lw          $t3, 0x18C($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X18C);
            goto L_805A00D8;
    }
    goto skip_1;
    // 0x805A00A0: lw          $t3, 0x18C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X18C);
    skip_1:
    // 0x805A00A4: lw          $t2, 0x38($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X38);
    // 0x805A00A8: slti        $at, $t2, 0x1E0
    ctx->r1 = SIGNED(ctx->r10) < 0X1E0 ? 1 : 0;
    // 0x805A00AC: bnel        $at, $zero, L_805A019C
    if (ctx->r1 != 0) {
        // 0x805A00B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A019C;
    }
    goto skip_2;
    // 0x805A00B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x805A00B4: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x805A00B8: lwc1        $f4, 0x88($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X88);
    // 0x805A00BC: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x805A00C0: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x805A00C4: nop

    // 0x805A00C8: bc1tl       L_805A019C
    if (c1cs) {
        // 0x805A00CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A019C;
    }
    goto skip_3;
    // 0x805A00CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x805A00D0: sw          $v1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r3;
    // 0x805A00D4: lw          $t3, 0x18C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X18C);
L_805A00D8:
    // 0x805A00D8: bnel        $a1, $t3, L_805A0114
    if (ctx->r5 != ctx->r11) {
        // 0x805A00DC: lw          $t5, 0x190($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X190);
            goto L_805A0114;
    }
    goto skip_4;
    // 0x805A00DC: lw          $t5, 0x190($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X190);
    skip_4:
    // 0x805A00E0: lw          $t4, 0x38($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X38);
    // 0x805A00E4: slti        $at, $t4, 0x1E0
    ctx->r1 = SIGNED(ctx->r12) < 0X1E0 ? 1 : 0;
    // 0x805A00E8: bnel        $at, $zero, L_805A019C
    if (ctx->r1 != 0) {
        // 0x805A00EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A019C;
    }
    goto skip_5;
    // 0x805A00EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x805A00F0: lwc1        $f16, 0x88($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X88);
    // 0x805A00F4: lwc1        $f10, 0x88($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X88);
    // 0x805A00F8: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x805A00FC: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x805A0100: nop

    // 0x805A0104: bc1tl       L_805A019C
    if (c1cs) {
        // 0x805A0108: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A019C;
    }
    goto skip_6;
    // 0x805A0108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x805A010C: sw          $v1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r3;
    // 0x805A0110: lw          $t5, 0x190($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X190);
L_805A0114:
    // 0x805A0114: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x805A0118: bnel        $a1, $t5, L_805A0154
    if (ctx->r5 != ctx->r13) {
        // 0x805A011C: lw          $t7, 0x194($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X194);
            goto L_805A0154;
    }
    goto skip_7;
    // 0x805A011C: lw          $t7, 0x194($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X194);
    skip_7:
    // 0x805A0120: lw          $t6, 0x38($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X38);
    // 0x805A0124: slti        $at, $t6, 0x1E0
    ctx->r1 = SIGNED(ctx->r14) < 0X1E0 ? 1 : 0;
    // 0x805A0128: bnel        $at, $zero, L_805A019C
    if (ctx->r1 != 0) {
        // 0x805A012C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A019C;
    }
    goto skip_8;
    // 0x805A012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x805A0130: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x805A0134: lwc1        $f6, 0x88($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X88);
    // 0x805A0138: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x805A013C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x805A0140: nop

    // 0x805A0144: bc1tl       L_805A019C
    if (c1cs) {
        // 0x805A0148: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A019C;
    }
    goto skip_9;
    // 0x805A0148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x805A014C: sw          $v1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r3;
    // 0x805A0150: lw          $t7, 0x194($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X194);
L_805A0154:
    // 0x805A0154: bne         $a1, $t7, L_805A018C
    if (ctx->r5 != ctx->r15) {
        // 0x805A0158: nop
    
            goto L_805A018C;
    }
    // 0x805A0158: nop

    // 0x805A015C: lw          $t8, 0x38($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X38);
    // 0x805A0160: slti        $at, $t8, 0x1E0
    ctx->r1 = SIGNED(ctx->r24) < 0X1E0 ? 1 : 0;
    // 0x805A0164: bnel        $at, $zero, L_805A019C
    if (ctx->r1 != 0) {
        // 0x805A0168: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A019C;
    }
    goto skip_10;
    // 0x805A0168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x805A016C: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x805A0170: lwc1        $f16, 0x88($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X88);
    // 0x805A0174: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x805A0178: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x805A017C: nop

    // 0x805A0180: bc1tl       L_805A019C
    if (c1cs) {
        // 0x805A0184: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A019C;
    }
    goto skip_11;
    // 0x805A0184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x805A0188: sw          $v1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r3;
L_805A018C:
    // 0x805A018C: bne         $a2, $a3, L_805A0098
    if (ctx->r6 != ctx->r7) {
        // 0x805A0190: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_805A0098;
    }
    // 0x805A0190: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x805A0194: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
L_805A0198:
    // 0x805A0198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A019C:
    // 0x805A019C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A01A0: jr          $ra
    // 0x805A01A4: nop

    return;
    // 0x805A01A4: nop

;}
RECOMP_FUNC void func_8078B894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078B894: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078B898: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078B89C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078B8A0: jal         0x8078B920
    // 0x8078B8A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8078B920(rdram, ctx);
        goto after_0;
    // 0x8078B8A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8078B8A8: beq         $v0, $zero, L_8078B908
    if (ctx->r2 == 0) {
        // 0x8078B8AC: lui         $t6, 0x8079
        ctx->r14 = S32(RELOC_HI16(796, 0X1B04) << 16);
            goto L_8078B908;
    }
    // 0x8078B8AC: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(796, 0X1B04) << 16);
    // 0x8078B8B0: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x8078B8B4: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8078B8B8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8078B8BC: addiu       $t6, $t6, -0x336C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(796, 0X1B04));
    // 0x8078B8C0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8078B8C4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8078B8C8: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8078B8CC: jal         0x8078B958
    // 0x8078B8D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8078B958(rdram, ctx);
        goto after_1;
    // 0x8078B8D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8078B8D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078B8D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078B8DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8078B8E0: jal         0x8078C7A4
    // 0x8078B8E4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8078C7A4(rdram, ctx);
        goto after_2;
    // 0x8078B8E4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x8078B8E8: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x8078B8EC: lui         $t8, 0x8079
    ctx->r24 = S32(RELOC_HI16(796, 0XD50) << 16);
    // 0x8078B8F0: addiu       $t8, $t8, -0x4120
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(796, 0XD50));
    // 0x8078B8F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078B8F8: jal         0x8078B87C
    // 0x8078B8FC: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    func_8078B87C(rdram, ctx);
        goto after_3;
    // 0x8078B8FC: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    after_3:
    // 0x8078B900: b           L_8078B90C
    // 0x8078B904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8078B90C;
    // 0x8078B904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8078B908:
    // 0x8078B908: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8078B90C:
    // 0x8078B90C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078B910: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078B914: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078B918: jr          $ra
    // 0x8078B91C: nop

    return;
    // 0x8078B91C: nop

;}
RECOMP_FUNC void func_8044AE2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044AE2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044AE30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044AE34: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8044AE38: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8044AE3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044AE40: jal         0x8044A558
    // 0x8044AE44: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8044A558(rdram, ctx);
        goto after_0;
    // 0x8044AE44: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x8044AE48: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044AE4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8044AE50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044AE54: bne         $v0, $zero, L_8044AE6C
    if (ctx->r2 != 0) {
        // 0x8044AE58: nop
    
            goto L_8044AE6C;
    }
    // 0x8044AE58: nop

    // 0x8044AE5C: jal         0x80446440
    // 0x8044AE60: nop

    func_80446440(rdram, ctx);
        goto after_1;
    // 0x8044AE60: nop

    after_1:
    // 0x8044AE64: b           L_8044AE90
    // 0x8044AE68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044AE90;
    // 0x8044AE68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044AE6C:
    // 0x8044AE6C: bne         $v0, $at, L_8044AE84
    if (ctx->r2 != ctx->r1) {
        // 0x8044AE70: nop
    
            goto L_8044AE84;
    }
    // 0x8044AE70: nop

    // 0x8044AE74: jal         0x80446478
    // 0x8044AE78: nop

    func_80446478(rdram, ctx);
        goto after_2;
    // 0x8044AE78: nop

    after_2:
    // 0x8044AE7C: b           L_8044AE90
    // 0x8044AE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044AE90;
    // 0x8044AE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044AE84:
    // 0x8044AE84: jal         0x804464B4
    // 0x8044AE88: nop

    func_804464B4(rdram, ctx);
        goto after_3;
    // 0x8044AE88: nop

    after_3:
    // 0x8044AE8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044AE90:
    // 0x8044AE90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044AE94: jr          $ra
    // 0x8044AE98: nop

    return;
    // 0x8044AE98: nop

;}
RECOMP_FUNC void func_8006A1E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A1E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006A1E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006A1EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006A1F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006A1F4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8006A1F8: addiu       $s1, $a0, 0xC
    ctx->r17 = ADD32(ctx->r4, 0XC);
    // 0x8006A1FC: lw          $s0, 0x28($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X28);
    // 0x8006A200: bnel        $s0, $zero, L_8006A214
    if (ctx->r16 != 0) {
        // 0x8006A204: lw          $t7, 0x0($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X0);
            goto L_8006A214;
    }
    goto skip_0;
    // 0x8006A204: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x8006A208: b           L_8006A270
    // 0x8006A20C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006A270;
    // 0x8006A20C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006A210: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
L_8006A214:
    // 0x8006A214: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006A218: bnel        $t7, $zero, L_8006A248
    if (ctx->r15 != 0) {
        // 0x8006A21C: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_8006A248;
    }
    goto skip_1;
    // 0x8006A21C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x8006A220: jal         0x8006A198
    // 0x8006A224: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_8006A198(rdram, ctx);
        goto after_0;
    // 0x8006A224: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x8006A228: bne         $v0, $zero, L_8006A244
    if (ctx->r2 != 0) {
        // 0x8006A22C: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_8006A244;
    }
    // 0x8006A22C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A230: addiu       $a0, $a0, 0xF50
    ctx->r4 = ADD32(ctx->r4, 0XF50);
    // 0x8006A234: jal         0x80071380
    // 0x8006A238: addiu       $a1, $zero, 0x17D
    ctx->r5 = ADD32(0, 0X17D);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8006A238: addiu       $a1, $zero, 0x17D
    ctx->r5 = ADD32(0, 0X17D);
    after_1:
    // 0x8006A23C: b           L_8006A270
    // 0x8006A240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A270;
    // 0x8006A240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A244:
    // 0x8006A244: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_8006A248:
    // 0x8006A248: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8006A24C: jal         0x80050994
    // 0x8006A250: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_80050994(rdram, ctx);
        goto after_2;
    // 0x8006A250: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x8006A254: bnel        $v0, $zero, L_8006A270
    if (ctx->r2 != 0) {
        // 0x8006A258: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006A270;
    }
    goto skip_2;
    // 0x8006A258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x8006A25C: jal         0x80064E84
    // 0x8006A260: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_80064E84(rdram, ctx);
        goto after_3;
    // 0x8006A260: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x8006A264: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8006A268: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8006A26C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A270:
    // 0x8006A270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A274: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006A278: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006A27C: jr          $ra
    // 0x8006A280: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006A280: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80025E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025E64: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x80025E68: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x80025E6C: lui         $t0, 0x8002
    ctx->r8 = S32(0X8002 << 16);
    // 0x80025E70: bne         $v0, $at, L_80025E94
    if (ctx->r2 != ctx->r1) {
        // 0x80025E74: addiu       $t0, $t0, 0x5E1C
        ctx->r8 = ADD32(ctx->r8, 0X5E1C);
            goto L_80025E94;
    }
    // 0x80025E74: addiu       $t0, $t0, 0x5E1C
    ctx->r8 = ADD32(ctx->r8, 0X5E1C);
    // 0x80025E78: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80025E7C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80025E80: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x80025E84: bnel        $t7, $v0, L_80025E98
    if (ctx->r15 != ctx->r2) {
        // 0x80025E88: addiu       $t9, $zero, 0x9
        ctx->r25 = ADD32(0, 0X9);
            goto L_80025E98;
    }
    goto skip_0;
    // 0x80025E88: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    skip_0:
    // 0x80025E8C: b           L_80025E9C
    // 0x80025E90: sw          $t8, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r24;
        goto L_80025E9C;
    // 0x80025E90: sw          $t8, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r24;
L_80025E94:
    // 0x80025E94: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
L_80025E98:
    // 0x80025E98: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
L_80025E9C:
    // 0x80025E9C: jr          $ra
    // 0x80025EA0: sw          $t0, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r8;
    return;
    // 0x80025EA0: sw          $t0, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void func_804518A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804518A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804518A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804518A8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140D8) << 16);
    // 0x804518AC: lwc1        $f4, -0x7B48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140D8));
    // 0x804518B0: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x804518B4: lui         $at, 0x4443
    ctx->r1 = S32(0X4443 << 16);
    // 0x804518B8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804518BC: nop

    // 0x804518C0: bc1fl       L_804518F0
    if (!c1cs) {
        // 0x804518C4: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_804518F0;
    }
    goto skip_0;
    // 0x804518C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x804518C8: jal         0x804516BC
    // 0x804518CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804516BC(rdram, ctx);
        goto after_0;
    // 0x804518CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804518D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804518D4: jal         0x80450B18
    // 0x804518D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80450B18(rdram, ctx);
        goto after_1;
    // 0x804518D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x804518DC: jal         0x80445A34
    // 0x804518E0: nop

    func_80445A34(rdram, ctx);
        goto after_2;
    // 0x804518E0: nop

    after_2:
    // 0x804518E4: b           L_804519F4
    // 0x804518E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804519F4;
    // 0x804518E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804518EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_804518F0:
    // 0x804518F0: lui         $at, 0x43FF
    ctx->r1 = S32(0X43FF << 16);
    // 0x804518F4: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x804518F8: nop

    // 0x804518FC: bc1fl       L_8045192C
    if (!c1cs) {
        // 0x80451900: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8045192C;
    }
    goto skip_1;
    // 0x80451900: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x80451904: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80451908: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8045190C: beql        $t6, $zero, L_804519F4
    if (ctx->r14 == 0) {
        // 0x80451910: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804519F4;
    }
    goto skip_2;
    // 0x80451910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80451914: jal         0x80450B18
    // 0x80451918: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_3;
    // 0x80451918: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x8045191C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451920: b           L_804519F0
    // 0x80451924: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_804519F0;
    // 0x80451924: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80451928: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8045192C:
    // 0x8045192C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80451930: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80451934: nop

    // 0x80451938: bc1fl       L_80451970
    if (!c1cs) {
        // 0x8045193C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80451970;
    }
    goto skip_3;
    // 0x8045193C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_3:
    // 0x80451940: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80451944: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80451948: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8045194C: beql        $t7, $at, L_804519F4
    if (ctx->r15 == ctx->r1) {
        // 0x80451950: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804519F4;
    }
    goto skip_4;
    // 0x80451950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80451954: jal         0x80450B18
    // 0x80451958: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_4;
    // 0x80451958: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x8045195C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451960: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80451964: b           L_804519F0
    // 0x80451968: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
        goto L_804519F0;
    // 0x80451968: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8045196C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80451970:
    // 0x80451970: nop

    // 0x80451974: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80451978: nop

    // 0x8045197C: bc1fl       L_804519B4
    if (!c1cs) {
        // 0x80451980: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_804519B4;
    }
    goto skip_5;
    // 0x80451980: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_5:
    // 0x80451984: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80451988: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8045198C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80451990: beql        $t9, $at, L_804519F4
    if (ctx->r25 == ctx->r1) {
        // 0x80451994: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804519F4;
    }
    goto skip_6;
    // 0x80451994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x80451998: jal         0x80450B18
    // 0x8045199C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_5;
    // 0x8045199C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_5:
    // 0x804519A0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804519A4: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x804519A8: b           L_804519F0
    // 0x804519AC: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
        goto L_804519F0;
    // 0x804519AC: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x804519B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_804519B4:
    // 0x804519B4: nop

    // 0x804519B8: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x804519BC: nop

    // 0x804519C0: bc1fl       L_804519F4
    if (!c1cs) {
        // 0x804519C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804519F4;
    }
    goto skip_7;
    // 0x804519C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x804519C8: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x804519CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804519D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804519D4: beql        $t1, $at, L_804519F4
    if (ctx->r9 == ctx->r1) {
        // 0x804519D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804519F4;
    }
    goto skip_8;
    // 0x804519D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x804519DC: jal         0x80450B18
    // 0x804519E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_6;
    // 0x804519E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_6:
    // 0x804519E4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804519E8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x804519EC: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
L_804519F0:
    // 0x804519F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804519F4:
    // 0x804519F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804519F8: jr          $ra
    // 0x804519FC: nop

    return;
    // 0x804519FC: nop

;}
RECOMP_FUNC void func_80561FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80561FCC: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80561FD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80561FD4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80561FD8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80561FDC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80561FE0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80561FE4: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x80561FE8: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80561FEC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80561FF0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80561FF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80561FF8: jal         0x8004921C
    // 0x80561FFC: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80561FFC: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    after_0:
    // 0x80562000: sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // 0x80562004: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562008: jal         0x8004921C
    // 0x8056200C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x8056200C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80562010: lbu         $t9, 0x3B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3B);
    // 0x80562014: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x80562018: lbu         $t7, 0x145($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X145);
    // 0x8056201C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80562020: lw          $v1, 0x168($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X168);
    // 0x80562024: addiu       $s2, $sp, 0xBC
    ctx->r18 = ADD32(ctx->r29, 0XBC);
    // 0x80562028: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8056202C: lw          $t9, 0x80($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X80);
    // 0x80562030: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80562034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80562038: mflo        $t6
    ctx->r14 = lo;
    // 0x8056203C: nop

    // 0x80562040: nop

    // 0x80562044: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80562048: mflo        $t8
    ctx->r24 = lo;
    // 0x8056204C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80562050: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
    // 0x80562054: lw          $s1, 0x1F4($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X1F4);
    // 0x80562058: jal         0x80077338
    // 0x8056205C: lw          $s0, 0x88($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X88);
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x8056205C: lw          $s0, 0x88($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X88);
    after_2:
    // 0x80562060: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80562064: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80562068: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8056206C: jal         0x8007711C
    // 0x80562070: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x80562070: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x80562074: jal         0x80561B44
    // 0x80562078: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80561B44(rdram, ctx);
        goto after_4;
    // 0x80562078: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x8056207C: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x80562080: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80562084: ori         $t9, $t9, 0x513F
    ctx->r25 = ctx->r25 | 0X513F;
    // 0x80562088: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8056208C: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80562090: addiu       $t6, $s1, 0x738
    ctx->r14 = ADD32(ctx->r17, 0X738);
    // 0x80562094: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80562098: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8056209C: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x805620A0: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x805620A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805620A8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x805620AC: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x805620B0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x805620B4: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x805620B8: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x805620BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805620C0: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x805620C4: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x805620C8: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x805620CC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x805620D0: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x805620D4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x805620D8: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x805620DC: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x805620E0: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x805620E4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x805620E8: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x805620EC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x805620F0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x805620F4: lw          $s2, 0xBC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XBC);
    // 0x805620F8: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x805620FC: addiu       $t7, $s2, 0x8
    ctx->r15 = ADD32(ctx->r18, 0X8);
    // 0x80562100: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x80562104: jal         0x8004921C
    // 0x80562108: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    func_8004921C(rdram, ctx);
        goto after_5;
    // 0x80562108: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    after_5:
    // 0x8056210C: sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // 0x80562110: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562114: jal         0x8004921C
    // 0x80562118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_6;
    // 0x80562118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8056211C: lh          $t9, 0x3A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3A);
    // 0x80562120: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80562124: mflo        $t6
    ctx->r14 = lo;
    // 0x80562128: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8056212C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80562130: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80562134: slti        $at, $t9, 0x7FF
    ctx->r1 = SIGNED(ctx->r25) < 0X7FF ? 1 : 0;
    // 0x80562138: beq         $at, $zero, L_80562178
    if (ctx->r1 == 0) {
        // 0x8056213C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80562178;
    }
    // 0x8056213C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562140: jal         0x8004921C
    // 0x80562144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_7;
    // 0x80562144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80562148: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8056214C: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80562150: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562154: jal         0x8004921C
    // 0x80562158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_8;
    // 0x80562158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8056215C: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80562160: mflo        $t6
    ctx->r14 = lo;
    // 0x80562164: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80562168: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8056216C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80562170: b           L_80562180
    // 0x80562174: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
        goto L_80562180;
    // 0x80562174: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_80562178:
    // 0x80562178: addiu       $t6, $zero, 0x7FF
    ctx->r14 = ADD32(0, 0X7FF);
    // 0x8056217C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_80562180:
    // 0x80562180: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562184: jal         0x8004921C
    // 0x80562188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_9;
    // 0x80562188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8056218C: bgez        $v0, L_8056219C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80562190: sra         $t7, $v0, 3
        ctx->r15 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8056219C;
    }
    // 0x80562190: sra         $t7, $v0, 3
    ctx->r15 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80562194: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80562198: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_8056219C:
    // 0x8056219C: bgtzl       $t7, L_805621B0
    if (SIGNED(ctx->r15) > 0) {
        // 0x805621A0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_805621B0;
    }
    goto skip_0;
    // 0x805621A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x805621A4: b           L_805621C8
    // 0x805621A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_805621C8;
    // 0x805621A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805621AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_805621B0:
    // 0x805621B0: jal         0x8004921C
    // 0x805621B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_10;
    // 0x805621B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x805621B8: bgez        $v0, L_805621C8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805621BC: sra         $a2, $v0, 3
        ctx->r6 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805621C8;
    }
    // 0x805621BC: sra         $a2, $v0, 3
    ctx->r6 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805621C0: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805621C4: sra         $a2, $at, 3
    ctx->r6 = S32(SIGNED(ctx->r1) >> 3);
L_805621C8:
    // 0x805621C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805621CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805621D0: jal         0x8004921C
    // 0x805621D4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8004921C(rdram, ctx);
        goto after_11;
    // 0x805621D4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_11:
    // 0x805621D8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x805621DC: bgez        $v0, L_805621EC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805621E0: sra         $t8, $v0, 3
        ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805621EC;
    }
    // 0x805621E0: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805621E4: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805621E8: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_805621EC:
    // 0x805621EC: bgtzl       $t8, L_80562200
    if (SIGNED(ctx->r24) > 0) {
        // 0x805621F0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80562200;
    }
    goto skip_1;
    // 0x805621F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_1:
    // 0x805621F4: b           L_80562220
    // 0x805621F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80562220;
    // 0x805621F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805621FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80562200:
    // 0x80562200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80562204: jal         0x8004921C
    // 0x80562208: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8004921C(rdram, ctx);
        goto after_12;
    // 0x80562208: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_12:
    // 0x8056220C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80562210: bgez        $v0, L_80562220
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80562214: sra         $v1, $v0, 3
        ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80562220;
    }
    // 0x80562214: sra         $v1, $v0, 3
    ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80562218: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x8056221C: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_80562220:
    // 0x80562220: addiu       $t9, $a2, 0x7FF
    ctx->r25 = ADD32(ctx->r6, 0X7FF);
    // 0x80562224: div         $zero, $t9, $v1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r3)));
    // 0x80562228: bne         $v1, $zero, L_80562234
    if (ctx->r3 != 0) {
        // 0x8056222C: nop
    
            goto L_80562234;
    }
    // 0x8056222C: nop

    // 0x80562230: break       7
    do_break(2153128496);
L_80562234:
    // 0x80562234: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80562238: bne         $v1, $at, L_8056224C
    if (ctx->r3 != ctx->r1) {
        // 0x8056223C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8056224C;
    }
    // 0x8056223C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80562240: bne         $t9, $at, L_8056224C
    if (ctx->r25 != ctx->r1) {
        // 0x80562244: nop
    
            goto L_8056224C;
    }
    // 0x80562244: nop

    // 0x80562248: break       6
    do_break(2153128520);
L_8056224C:
    // 0x8056224C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80562250: mflo        $t6
    ctx->r14 = lo;
    // 0x80562254: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80562258: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8056225C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80562260: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80562264: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80562268: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8056226C: sw          $t9, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r25;
    // 0x80562270: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x80562274: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80562278: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8056227C: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x80562280: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80562284: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80562288: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x8056228C: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x80562290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80562294: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80562298: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x8056229C: jal         0x8004921C
    // 0x805622A0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    func_8004921C(rdram, ctx);
        goto after_13;
    // 0x805622A0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    after_13:
    // 0x805622A4: addiu       $t8, $v0, 0x7
    ctx->r24 = ADD32(ctx->r2, 0X7);
    // 0x805622A8: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x805622AC: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x805622B0: sll         $t6, $t9, 9
    ctx->r14 = S32(ctx->r25 << 9);
    // 0x805622B4: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x805622B8: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x805622BC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x805622C0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x805622C4: lw          $s1, 0xBC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XBC);
    // 0x805622C8: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x805622CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805622D0: addiu       $t9, $s1, 0x8
    ctx->r25 = ADD32(ctx->r17, 0X8);
    // 0x805622D4: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x805622D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805622DC: jal         0x8004921C
    // 0x805622E0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    func_8004921C(rdram, ctx);
        goto after_14;
    // 0x805622E0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    after_14:
    // 0x805622E4: sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // 0x805622E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805622EC: jal         0x8004921C
    // 0x805622F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_15;
    // 0x805622F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x805622F4: lh          $t6, 0x3A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3A);
    // 0x805622F8: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x805622FC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80562300: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80562304: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x80562308: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8056230C: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80562310: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80562314: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    // 0x80562318: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8056231C: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x80562320: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x80562324: lui         $s2, 0xBF00
    ctx->r18 = S32(0XBF00 << 16);
    // 0x80562328: addiu       $t8, $zero, 0x204
    ctx->r24 = ADD32(0, 0X204);
    // 0x8056232C: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80562330: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x80562334: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80562338: sw          $s2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r18;
    // 0x8056233C: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x80562340: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x80562344: ori         $t9, $t9, 0x604
    ctx->r25 = ctx->r25 | 0X604;
    // 0x80562348: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x8056234C: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x80562350: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80562354: sw          $s2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r18;
    // 0x80562358: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x8056235C: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x80562360: addiu       $a3, $a3, 0x400
    ctx->r7 = ADD32(ctx->r7, 0X400);
    // 0x80562364: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x80562368: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x8056236C: sw          $a3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r7;
    // 0x80562370: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80562374: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x80562378: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8056237C: ori         $t6, $t6, 0x50
    ctx->r14 = ctx->r14 | 0X50;
    // 0x80562380: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x80562384: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80562388: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x8056238C: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x80562390: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80562394: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x80562398: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8056239C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805623A0: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x805623A4: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x805623A8: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x805623AC: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x805623B0: lw          $s1, 0xBC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XBC);
    // 0x805623B4: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x805623B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805623BC: addiu       $t9, $s1, 0x8
    ctx->r25 = ADD32(ctx->r17, 0X8);
    // 0x805623C0: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x805623C4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x805623C8: jal         0x8004921C
    // 0x805623CC: sw          $a3, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_16;
    // 0x805623CC: sw          $a3, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r7;
    after_16:
    // 0x805623D0: sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // 0x805623D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805623D8: jal         0x8004921C
    // 0x805623DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_17;
    // 0x805623DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x805623E0: lh          $t7, 0x3A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3A);
    // 0x805623E4: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805623E8: mflo        $t6
    ctx->r14 = lo;
    // 0x805623EC: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x805623F0: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x805623F4: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x805623F8: slti        $at, $t7, 0x7FF
    ctx->r1 = SIGNED(ctx->r15) < 0X7FF ? 1 : 0;
    // 0x805623FC: beq         $at, $zero, L_8056243C
    if (ctx->r1 == 0) {
        // 0x80562400: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8056243C;
    }
    // 0x80562400: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562404: jal         0x8004921C
    // 0x80562408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_18;
    // 0x80562408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x8056240C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80562410: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80562414: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562418: jal         0x8004921C
    // 0x8056241C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_19;
    // 0x8056241C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80562420: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80562424: mflo        $t6
    ctx->r14 = lo;
    // 0x80562428: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8056242C: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80562430: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x80562434: b           L_80562444
    // 0x80562438: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_80562444;
    // 0x80562438: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_8056243C:
    // 0x8056243C: addiu       $t6, $zero, 0x7FF
    ctx->r14 = ADD32(0, 0X7FF);
    // 0x80562440: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_80562444:
    // 0x80562444: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562448: jal         0x8004921C
    // 0x8056244C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_20;
    // 0x8056244C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80562450: bgez        $v0, L_80562460
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80562454: sra         $t9, $v0, 3
        ctx->r25 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80562460;
    }
    // 0x80562454: sra         $t9, $v0, 3
    ctx->r25 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80562458: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x8056245C: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_80562460:
    // 0x80562460: bgtzl       $t9, L_80562474
    if (SIGNED(ctx->r25) > 0) {
        // 0x80562464: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80562474;
    }
    goto skip_2;
    // 0x80562464: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_2:
    // 0x80562468: b           L_8056248C
    // 0x8056246C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8056248C;
    // 0x8056246C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80562470: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80562474:
    // 0x80562474: jal         0x8004921C
    // 0x80562478: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_21;
    // 0x80562478: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x8056247C: bgez        $v0, L_8056248C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80562480: sra         $a2, $v0, 3
        ctx->r6 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8056248C;
    }
    // 0x80562480: sra         $a2, $v0, 3
    ctx->r6 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80562484: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80562488: sra         $a2, $at, 3
    ctx->r6 = S32(SIGNED(ctx->r1) >> 3);
L_8056248C:
    // 0x8056248C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80562494: jal         0x8004921C
    // 0x80562498: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8004921C(rdram, ctx);
        goto after_22;
    // 0x80562498: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_22:
    // 0x8056249C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x805624A0: bgez        $v0, L_805624B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805624A4: sra         $t8, $v0, 3
        ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805624B0;
    }
    // 0x805624A4: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805624A8: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805624AC: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_805624B0:
    // 0x805624B0: bgtzl       $t8, L_805624C4
    if (SIGNED(ctx->r24) > 0) {
        // 0x805624B4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_805624C4;
    }
    goto skip_3;
    // 0x805624B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_3:
    // 0x805624B8: b           L_805624E4
    // 0x805624BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805624E4;
    // 0x805624BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805624C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_805624C4:
    // 0x805624C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805624C8: jal         0x8004921C
    // 0x805624CC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8004921C(rdram, ctx);
        goto after_23;
    // 0x805624CC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_23:
    // 0x805624D0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x805624D4: bgez        $v0, L_805624E4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805624D8: sra         $v1, $v0, 3
        ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805624E4;
    }
    // 0x805624D8: sra         $v1, $v0, 3
    ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805624DC: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805624E0: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_805624E4:
    // 0x805624E4: addiu       $t7, $a2, 0x7FF
    ctx->r15 = ADD32(ctx->r6, 0X7FF);
    // 0x805624E8: div         $zero, $t7, $v1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r3)));
    // 0x805624EC: bne         $v1, $zero, L_805624F8
    if (ctx->r3 != 0) {
        // 0x805624F0: nop
    
            goto L_805624F8;
    }
    // 0x805624F0: nop

    // 0x805624F4: break       7
    do_break(2153129204);
L_805624F8:
    // 0x805624F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805624FC: bne         $v1, $at, L_80562510
    if (ctx->r3 != ctx->r1) {
        // 0x80562500: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80562510;
    }
    // 0x80562500: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80562504: bne         $t7, $at, L_80562510
    if (ctx->r15 != ctx->r1) {
        // 0x80562508: nop
    
            goto L_80562510;
    }
    // 0x80562508: nop

    // 0x8056250C: break       6
    do_break(2153129228);
L_80562510:
    // 0x80562510: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80562514: mflo        $t6
    ctx->r14 = lo;
    // 0x80562518: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8056251C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80562520: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80562524: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80562528: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8056252C: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x80562530: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x80562534: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x80562538: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8056253C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562540: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x80562544: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80562548: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8056254C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80562550: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x80562554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80562558: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x8056255C: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x80562560: jal         0x8004921C
    // 0x80562564: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    func_8004921C(rdram, ctx);
        goto after_24;
    // 0x80562564: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    after_24:
    // 0x80562568: addiu       $t8, $v0, 0x7
    ctx->r24 = ADD32(ctx->r2, 0X7);
    // 0x8056256C: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80562570: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x80562574: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x80562578: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8056257C: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80562580: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x80562584: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80562588: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8056258C: lw          $s1, 0xBC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XBC);
    // 0x80562590: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80562594: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562598: addiu       $t6, $s1, 0x8
    ctx->r14 = ADD32(ctx->r17, 0X8);
    // 0x8056259C: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x805625A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805625A4: jal         0x8004921C
    // 0x805625A8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    func_8004921C(rdram, ctx);
        goto after_25;
    // 0x805625A8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    after_25:
    // 0x805625AC: sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // 0x805625B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805625B4: jal         0x8004921C
    // 0x805625B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_26;
    // 0x805625B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x805625BC: lh          $t8, 0x3A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3A);
    // 0x805625C0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x805625C4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x805625C8: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x805625CC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x805625D0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x805625D4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x805625D8: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x805625DC: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x805625E0: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x805625E4: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x805625E8: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x805625EC: ori         $t9, $t9, 0x608
    ctx->r25 = ctx->r25 | 0X608;
    // 0x805625F0: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x805625F4: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x805625F8: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x805625FC: sw          $s2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r18;
    // 0x80562600: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x80562604: lui         $t6, 0x6
    ctx->r14 = S32(0X6 << 16);
    // 0x80562608: ori         $t6, $t6, 0xA08
    ctx->r14 = ctx->r14 | 0XA08;
    // 0x8056260C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80562610: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80562614: sw          $s2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r18;
    // 0x80562618: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8056261C: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x80562620: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x80562624: ori         $t8, $t8, 0xA0C
    ctx->r24 = ctx->r24 | 0XA0C;
    // 0x80562628: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8056262C: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x80562630: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80562634: sw          $s2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r18;
    // 0x80562638: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x8056263C: lui         $t7, 0xA
    ctx->r15 = S32(0XA << 16);
    // 0x80562640: ori         $t7, $t7, 0xE0C
    ctx->r15 = ctx->r15 | 0XE0C;
    // 0x80562644: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80562648: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x8056264C: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x80562650: sw          $s2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r18;
    // 0x80562654: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x80562658: lui         $t9, 0xC
    ctx->r25 = S32(0XC << 16);
    // 0x8056265C: ori         $t9, $t9, 0xE10
    ctx->r25 = ctx->r25 | 0XE10;
    // 0x80562660: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80562664: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x80562668: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8056266C: sw          $s2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r18;
    // 0x80562670: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x80562674: lui         $t6, 0xE
    ctx->r14 = S32(0XE << 16);
    // 0x80562678: ori         $t6, $t6, 0x1210
    ctx->r14 = ctx->r14 | 0X1210;
    // 0x8056267C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80562680: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80562684: sw          $s2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r18;
    // 0x80562688: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8056268C: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x80562690: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80562694: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80562698: addiu       $ra, $t5, 0x2
    ctx->r31 = ADD32(ctx->r13, 0X2);
    // 0x8056269C: andi        $ra, $ra, 0xFF
    ctx->r31 = ctx->r31 & 0XFF;
    // 0x805626A0: andi        $t8, $t5, 0xFF
    ctx->r24 = ctx->r13 & 0XFF;
    // 0x805626A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805626A8: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x805626AC: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x805626B0: sll         $t9, $ra, 8
    ctx->r25 = S32(ctx->r31 << 8);
    // 0x805626B4: addiu       $s0, $t5, 0x4
    ctx->r16 = ADD32(ctx->r13, 0X4);
    // 0x805626B8: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x805626BC: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x805626C0: or          $t8, $t7, $s0
    ctx->r24 = ctx->r15 | ctx->r16;
    // 0x805626C4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x805626C8: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x805626CC: lw          $v1, 0xBC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XBC);
    // 0x805626D0: addiu       $t8, $t5, 0x6
    ctx->r24 = ADD32(ctx->r13, 0X6);
    // 0x805626D4: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x805626D8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x805626DC: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x805626E0: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x805626E4: sll         $t7, $ra, 16
    ctx->r15 = S32(ctx->r31 << 16);
    // 0x805626E8: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x805626EC: or          $t6, $t8, $s0
    ctx->r14 = ctx->r24 | ctx->r16;
    // 0x805626F0: addiu       $a0, $s1, 0x1
    ctx->r4 = ADD32(ctx->r17, 0X1);
    // 0x805626F4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x805626F8: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x805626FC: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x80562700: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80562704: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80562708: addiu       $a3, $a0, 0x2
    ctx->r7 = ADD32(ctx->r4, 0X2);
    // 0x8056270C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80562710: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x80562714: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80562718: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x8056271C: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80562720: sll         $t7, $a3, 8
    ctx->r15 = S32(ctx->r7 << 8);
    // 0x80562724: addiu       $t0, $a0, 0x4
    ctx->r8 = ADD32(ctx->r4, 0X4);
    // 0x80562728: andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // 0x8056272C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80562730: or          $t8, $t9, $t0
    ctx->r24 = ctx->r25 | ctx->r8;
    // 0x80562734: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80562738: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8056273C: lw          $v1, 0xBC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XBC);
    // 0x80562740: addiu       $t8, $a0, 0x6
    ctx->r24 = ADD32(ctx->r4, 0X6);
    // 0x80562744: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80562748: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8056274C: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x80562750: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80562754: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x80562758: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8056275C: or          $t6, $t8, $t0
    ctx->r14 = ctx->r24 | ctx->r8;
    // 0x80562760: addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    // 0x80562764: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80562768: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x8056276C: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x80562770: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x80562774: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x80562778: addiu       $t1, $a1, 0x2
    ctx->r9 = ADD32(ctx->r5, 0X2);
    // 0x8056277C: andi        $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 & 0XFF;
    // 0x80562780: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80562784: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80562788: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x8056278C: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80562790: sll         $t9, $t1, 8
    ctx->r25 = S32(ctx->r9 << 8);
    // 0x80562794: addiu       $t2, $a1, 0x4
    ctx->r10 = ADD32(ctx->r5, 0X4);
    // 0x80562798: andi        $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 & 0XFF;
    // 0x8056279C: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x805627A0: or          $t8, $t7, $t2
    ctx->r24 = ctx->r15 | ctx->r10;
    // 0x805627A4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x805627A8: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x805627AC: lw          $v1, 0xBC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XBC);
    // 0x805627B0: addiu       $t8, $a1, 0x6
    ctx->r24 = ADD32(ctx->r5, 0X6);
    // 0x805627B4: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x805627B8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x805627BC: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x805627C0: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x805627C4: sll         $t7, $t1, 16
    ctx->r15 = S32(ctx->r9 << 16);
    // 0x805627C8: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x805627CC: or          $t6, $t8, $t2
    ctx->r14 = ctx->r24 | ctx->r10;
    // 0x805627D0: addiu       $a2, $s1, 0x3
    ctx->r6 = ADD32(ctx->r17, 0X3);
    // 0x805627D4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x805627D8: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x805627DC: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x805627E0: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x805627E4: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x805627E8: addiu       $t3, $a2, 0x2
    ctx->r11 = ADD32(ctx->r6, 0X2);
    // 0x805627EC: andi        $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 & 0XFF;
    // 0x805627F0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805627F4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805627F8: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x805627FC: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80562800: sll         $t7, $t3, 8
    ctx->r15 = S32(ctx->r11 << 8);
    // 0x80562804: addiu       $t4, $a2, 0x4
    ctx->r12 = ADD32(ctx->r6, 0X4);
    // 0x80562808: andi        $t4, $t4, 0xFF
    ctx->r12 = ctx->r12 & 0XFF;
    // 0x8056280C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80562810: or          $t8, $t9, $t4
    ctx->r24 = ctx->r25 | ctx->r12;
    // 0x80562814: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80562818: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8056281C: lw          $v1, 0xBC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XBC);
    // 0x80562820: addiu       $t8, $a2, 0x6
    ctx->r24 = ADD32(ctx->r6, 0X6);
    // 0x80562824: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80562828: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8056282C: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x80562830: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80562834: sll         $t9, $t3, 16
    ctx->r25 = S32(ctx->r11 << 16);
    // 0x80562838: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8056283C: or          $t6, $t8, $t4
    ctx->r14 = ctx->r24 | ctx->r12;
    // 0x80562840: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80562844: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x80562848: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x8056284C: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x80562850: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80562854: addiu       $t7, $t9, 0x400
    ctx->r15 = ADD32(ctx->r25, 0X400);
    // 0x80562858: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8056285C: sw          $t7, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r15;
    // 0x80562860: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x80562864: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x80562868: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8056286C: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x80562870: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x80562874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80562878: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8056287C: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x80562880: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80562884: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562888: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8056288C: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x80562890: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80562894: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x80562898: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x8056289C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x805628A0: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x805628A4: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x805628A8: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x805628AC: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x805628B0: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x805628B4: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x805628B8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x805628BC: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x805628C0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805628C4: jal         0x8004921C
    // 0x805628C8: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_27;
    // 0x805628C8: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    after_27:
    // 0x805628CC: sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // 0x805628D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805628D4: jal         0x8004921C
    // 0x805628D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_28;
    // 0x805628D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x805628DC: lh          $t9, 0x3A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3A);
    // 0x805628E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805628E4: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805628E8: mflo        $t7
    ctx->r15 = lo;
    // 0x805628EC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x805628F0: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x805628F4: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x805628F8: slti        $at, $t9, 0x7FF
    ctx->r1 = SIGNED(ctx->r25) < 0X7FF ? 1 : 0;
    // 0x805628FC: beq         $at, $zero, L_8056293C
    if (ctx->r1 == 0) {
        // 0x80562900: addiu       $t7, $zero, 0x7FF
        ctx->r15 = ADD32(0, 0X7FF);
            goto L_8056293C;
    }
    // 0x80562900: addiu       $t7, $zero, 0x7FF
    ctx->r15 = ADD32(0, 0X7FF);
    // 0x80562904: jal         0x8004921C
    // 0x80562908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_29;
    // 0x80562908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x8056290C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80562910: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80562914: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562918: jal         0x8004921C
    // 0x8056291C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_30;
    // 0x8056291C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80562920: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80562924: mflo        $t7
    ctx->r15 = lo;
    // 0x80562928: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8056292C: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80562930: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x80562934: b           L_80562940
    // 0x80562938: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
        goto L_80562940;
    // 0x80562938: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8056293C:
    // 0x8056293C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80562940:
    // 0x80562940: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562944: jal         0x8004921C
    // 0x80562948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_31;
    // 0x80562948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x8056294C: bgez        $v0, L_8056295C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80562950: sra         $t8, $v0, 3
        ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8056295C;
    }
    // 0x80562950: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80562954: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80562958: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_8056295C:
    // 0x8056295C: bgtz        $t8, L_8056296C
    if (SIGNED(ctx->r24) > 0) {
        // 0x80562960: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8056296C;
    }
    // 0x80562960: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562964: b           L_80562984
    // 0x80562968: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80562984;
    // 0x80562968: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8056296C:
    // 0x8056296C: jal         0x8004921C
    // 0x80562970: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_32;
    // 0x80562970: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x80562974: bgez        $v0, L_80562984
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80562978: sra         $a2, $v0, 3
        ctx->r6 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80562984;
    }
    // 0x80562978: sra         $a2, $v0, 3
    ctx->r6 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8056297C: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80562980: sra         $a2, $at, 3
    ctx->r6 = S32(SIGNED(ctx->r1) >> 3);
L_80562984:
    // 0x80562984: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562988: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8056298C: jal         0x8004921C
    // 0x80562990: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8004921C(rdram, ctx);
        goto after_33;
    // 0x80562990: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_33:
    // 0x80562994: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80562998: bgez        $v0, L_805629A8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8056299C: sra         $t6, $v0, 3
        ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805629A8;
    }
    // 0x8056299C: sra         $t6, $v0, 3
    ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805629A0: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805629A4: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_805629A8:
    // 0x805629A8: bgtzl       $t6, L_805629BC
    if (SIGNED(ctx->r14) > 0) {
        // 0x805629AC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_805629BC;
    }
    goto skip_4;
    // 0x805629AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_4:
    // 0x805629B0: b           L_805629DC
    // 0x805629B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805629DC;
    // 0x805629B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805629B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_805629BC:
    // 0x805629BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805629C0: jal         0x8004921C
    // 0x805629C4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8004921C(rdram, ctx);
        goto after_34;
    // 0x805629C4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_34:
    // 0x805629C8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x805629CC: bgez        $v0, L_805629DC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805629D0: sra         $v1, $v0, 3
        ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805629DC;
    }
    // 0x805629D0: sra         $v1, $v0, 3
    ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805629D4: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805629D8: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_805629DC:
    // 0x805629DC: addiu       $t9, $a2, 0x7FF
    ctx->r25 = ADD32(ctx->r6, 0X7FF);
    // 0x805629E0: div         $zero, $t9, $v1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r3)));
    // 0x805629E4: bne         $v1, $zero, L_805629F0
    if (ctx->r3 != 0) {
        // 0x805629E8: nop
    
            goto L_805629F0;
    }
    // 0x805629E8: nop

    // 0x805629EC: break       7
    do_break(2153130476);
L_805629F0:
    // 0x805629F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805629F4: bne         $v1, $at, L_80562A08
    if (ctx->r3 != ctx->r1) {
        // 0x805629F8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80562A08;
    }
    // 0x805629F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805629FC: bne         $t9, $at, L_80562A08
    if (ctx->r25 != ctx->r1) {
        // 0x80562A00: nop
    
            goto L_80562A08;
    }
    // 0x80562A00: nop

    // 0x80562A04: break       6
    do_break(2153130500);
L_80562A08:
    // 0x80562A08: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80562A0C: mflo        $t7
    ctx->r15 = lo;
    // 0x80562A10: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80562A14: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80562A18: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80562A1C: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80562A20: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80562A24: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80562A28: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80562A2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562A30: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80562A34: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x80562A38: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80562A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80562A40: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x80562A44: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80562A48: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80562A4C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80562A50: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x80562A54: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x80562A58: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x80562A5C: jal         0x8004921C
    // 0x80562A60: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    func_8004921C(rdram, ctx);
        goto after_35;
    // 0x80562A60: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    after_35:
    // 0x80562A64: addiu       $t8, $v0, 0x7
    ctx->r24 = ADD32(ctx->r2, 0X7);
    // 0x80562A68: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80562A6C: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x80562A70: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x80562A74: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80562A78: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80562A7C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80562A80: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80562A84: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x80562A88: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80562A8C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562A90: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80562A94: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x80562A98: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x80562A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80562AA0: jal         0x8004921C
    // 0x80562AA4: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    func_8004921C(rdram, ctx);
        goto after_36;
    // 0x80562AA4: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    after_36:
    // 0x80562AA8: sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // 0x80562AAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80562AB0: jal         0x8004921C
    // 0x80562AB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_37;
    // 0x80562AB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_37:
    // 0x80562AB8: lh          $t6, 0x3A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3A);
    // 0x80562ABC: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80562AC0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80562AC4: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80562AC8: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x80562ACC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80562AD0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80562AD4: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80562AD8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80562ADC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80562AE0: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80562AE4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80562AE8: lw          $v1, 0xBC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XBC);
    // 0x80562AEC: addiu       $ra, $t5, 0x2
    ctx->r31 = ADD32(ctx->r13, 0X2);
    // 0x80562AF0: andi        $ra, $ra, 0xFF
    ctx->r31 = ctx->r31 & 0XFF;
    // 0x80562AF4: andi        $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 & 0XFF;
    // 0x80562AF8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80562AFC: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80562B00: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80562B04: sll         $t7, $ra, 8
    ctx->r15 = S32(ctx->r31 << 8);
    // 0x80562B08: addiu       $s0, $t5, 0x4
    ctx->r16 = ADD32(ctx->r13, 0X4);
    // 0x80562B0C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80562B10: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80562B14: or          $t9, $t8, $s0
    ctx->r25 = ctx->r24 | ctx->r16;
    // 0x80562B18: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80562B1C: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x80562B20: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x80562B24: addiu       $t9, $t5, 0x6
    ctx->r25 = ADD32(ctx->r13, 0X6);
    // 0x80562B28: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80562B2C: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x80562B30: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x80562B34: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80562B38: sll         $t8, $ra, 16
    ctx->r24 = S32(ctx->r31 << 16);
    // 0x80562B3C: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80562B40: or          $t6, $t9, $s0
    ctx->r14 = ctx->r25 | ctx->r16;
    // 0x80562B44: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80562B48: sw          $s2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r18;
    // 0x80562B4C: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x80562B50: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x80562B54: sw          $t8, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r24;
    // 0x80562B58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80562B5C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80562B60: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80562B64: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80562B68: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80562B6C: jr          $ra
    // 0x80562B70: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80562B70: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_8002C95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C95C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8002C960: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002C964: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8002C968: lbu         $t6, -0x18AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X18AC);
    // 0x8002C96C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002C970: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002C974: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002C978: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8002C97C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8002C980: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8002C984: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x8002C988: lw          $t7, -0x189C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X189C);
    // 0x8002C98C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002C990: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002C994: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8002C998: jal         0x8002C8E8
    // 0x8002C99C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_8002C8E8(rdram, ctx);
        goto after_0;
    // 0x8002C99C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002C9A0: addiu       $a0, $s1, 0x12F0
    ctx->r4 = ADD32(ctx->r17, 0X12F0);
    // 0x8002C9A4: addiu       $a1, $zero, 0x114
    ctx->r5 = ADD32(0, 0X114);
    // 0x8002C9A8: jal         0x800657CC
    // 0x8002C9AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x8002C9AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8002C9B0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8002C9B4: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8002C9B8: addiu       $t9, $t9, -0x1864
    ctx->r25 = ADD32(ctx->r25, -0X1864);
    // 0x8002C9BC: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8002C9C0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8002C9C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8002C9C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002C9CC: jalr        $t9
    // 0x8002C9D0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8002C9D0: nop

    after_2:
    // 0x8002C9D4: sb          $zero, 0x22($s1)
    MEM_B(0X22, ctx->r17) = 0;
    // 0x8002C9D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002C9DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002C9E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002C9E4: jal         0x8001DC5C
    // 0x8002C9E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8001DC5C(rdram, ctx);
        goto after_3;
    // 0x8002C9E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8002C9EC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8002C9F0: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8002C9F4: addiu       $t0, $t0, -0x183C
    ctx->r8 = ADD32(ctx->r8, -0X183C);
    // 0x8002C9F8: beq         $v0, $t0, L_8002CA0C
    if (ctx->r2 == ctx->r8) {
        // 0x8002C9FC: lui         $t1, 0x800A
        ctx->r9 = S32(0X800A << 16);
            goto L_8002CA0C;
    }
    // 0x8002C9FC: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8002CA00: addiu       $t1, $t1, -0x1830
    ctx->r9 = ADD32(ctx->r9, -0X1830);
    // 0x8002CA04: bne         $v0, $t1, L_8002CA24
    if (ctx->r2 != ctx->r9) {
        // 0x8002CA08: nop
    
            goto L_8002CA24;
    }
    // 0x8002CA08: nop

L_8002CA0C:
    // 0x8002CA0C: jal         0x8002BE60
    // 0x8002CA10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002BE60(rdram, ctx);
        goto after_4;
    // 0x8002CA10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8002CA14: jal         0x8002AE54
    // 0x8002CA18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002AE54(rdram, ctx);
        goto after_5;
    // 0x8002CA18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8002CA1C: b           L_8002CA38
    // 0x8002CA20: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
        goto L_8002CA38;
    // 0x8002CA20: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
L_8002CA24:
    // 0x8002CA24: jal         0x8002BE88
    // 0x8002CA28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002BE88(rdram, ctx);
        goto after_6;
    // 0x8002CA28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8002CA2C: jal         0x8002AEE4
    // 0x8002CA30: nop

    func_8002AEE4(rdram, ctx);
        goto after_7;
    // 0x8002CA30: nop

    after_7:
    // 0x8002CA34: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
L_8002CA38:
    // 0x8002CA38: sb          $zero, 0x111($s1)
    MEM_B(0X111, ctx->r17) = 0;
    // 0x8002CA3C: sw          $t2, 0x11C($s1)
    MEM_W(0X11C, ctx->r17) = ctx->r10;
    // 0x8002CA40: sw          $zero, 0x78($s1)
    MEM_W(0X78, ctx->r17) = 0;
    // 0x8002CA44: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x8002CA48: sb          $zero, 0x10($t3)
    MEM_B(0X10, ctx->r11) = 0;
    // 0x8002CA4C: sw          $zero, 0x178($s1)
    MEM_W(0X178, ctx->r17) = 0;
    // 0x8002CA50: sw          $zero, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = 0;
    // 0x8002CA54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CA58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002CA5C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002CA60: jr          $ra
    // 0x8002CA64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002CA64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80452A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452A14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452A18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452A1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80452A20: jal         0x80450220
    // 0x80452A24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80450220(rdram, ctx);
        goto after_0;
    // 0x80452A24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80452A28: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80452A2C: lui         $a1, 0x8045
    ctx->r5 = S32(RELOC_HI16(98, 0X13904) << 16);
    // 0x80452A30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80452A34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80452A38: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x80452A3C: jal         0x8045111C
    // 0x80452A40: lw          $a1, 0x7CE4($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13904));
    func_8045111C(rdram, ctx);
        goto after_1;
    // 0x80452A40: lw          $a1, 0x7CE4($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13904));
    after_1:
    // 0x80452A44: jal         0x8044F178
    // 0x80452A48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8044F178(rdram, ctx);
        goto after_2;
    // 0x80452A48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80452A4C: jal         0x8044F384
    // 0x80452A50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8044F384(rdram, ctx);
        goto after_3;
    // 0x80452A50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80452A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80452A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452A5C: jr          $ra
    // 0x80452A60: nop

    return;
    // 0x80452A60: nop

;}
RECOMP_FUNC void func_806B20CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B20CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B20D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806B20D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806B20D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806B20DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806B20E0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806B20E4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806B20E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B20EC: addiu       $t6, $zero, 0x1D10
    ctx->r14 = ADD32(0, 0X1D10);
    // 0x806B20F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806B20F4: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x806B20F8: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x806B20FC: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x806B2100: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x806B2104: jal         0x806B195C
    // 0x806B2108: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_806B195C(rdram, ctx);
        goto after_0;
    // 0x806B2108: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x806B210C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806B2110: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B2114: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806B2118: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B211C: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x806B2120: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x806B2124: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806B2128: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B212C: jr          $ra
    // 0x806B2130: nop

    return;
    // 0x806B2130: nop

;}
RECOMP_FUNC void func_807A6880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6880: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807A6884: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A6888: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807A688C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807A6890: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x807A6894: jal         0x80047090
    // 0x807A6898: addiu       $a0, $zero, 0x471A
    ctx->r4 = ADD32(0, 0X471A);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807A6898: addiu       $a0, $zero, 0x471A
    ctx->r4 = ADD32(0, 0X471A);
    after_0:
    // 0x807A689C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x807A68A0: bne         $v0, $at, L_807A68B0
    if (ctx->r2 != ctx->r1) {
        // 0x807A68A4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_807A68B0;
    }
    // 0x807A68A4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x807A68A8: b           L_807A6920
    // 0x807A68AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807A6920;
    // 0x807A68AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807A68B0:
    // 0x807A68B0: lui         $at, 0x471A
    ctx->r1 = S32(0X471A << 16);
    // 0x807A68B4: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807A68B8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x807A68BC: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x807A68C0: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x807A68C4: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    // 0x807A68C8: jal         0x8004613C
    // 0x807A68CC: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807A68CC: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x807A68D0: lhu         $v1, 0x22($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X22);
    // 0x807A68D4: bne         $v0, $zero, L_807A68E4
    if (ctx->r2 != 0) {
        // 0x807A68D8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_807A68E4;
    }
    // 0x807A68D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x807A68DC: b           L_807A6920
    // 0x807A68E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807A6920;
    // 0x807A68E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807A68E4:
    // 0x807A68E4: lhu         $t8, 0xE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XE);
    // 0x807A68E8: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x807A68EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807A68F0: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x807A68F4: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x807A68F8: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    // 0x807A68FC: jal         0x80047F9C
    // 0x807A6900: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807A6900: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x807A6904: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807A6908: sb          $t1, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r9;
    // 0x807A690C: jal         0x807A6710
    // 0x807A6910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A6710(rdram, ctx);
        goto after_3;
    // 0x807A6910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807A6914: jal         0x807A67B8
    // 0x807A6918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A67B8(rdram, ctx);
        goto after_4;
    // 0x807A6918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807A691C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_807A6920:
    // 0x807A6920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807A6924: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807A6928: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807A692C: jr          $ra
    // 0x807A6930: nop

    return;
    // 0x807A6930: nop

;}
RECOMP_FUNC void func_805259FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805259FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80525A00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80525A04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80525A08: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80525A0C: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(324, 0X2AC) << 16);
    // 0x80525A10: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80525A14: addiu       $t7, $t7, 0x57BC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(324, 0X2AC));
    // 0x80525A18: addiu       $at, $zero, 0x41E7
    ctx->r1 = ADD32(0, 0X41E7);
    // 0x80525A1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80525A20: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80525A24: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x80525A28: beq         $v0, $at, L_80525A78
    if (ctx->r2 == ctx->r1) {
        // 0x80525A2C: sw          $t7, 0x20($a0)
        MEM_W(0X20, ctx->r4) = ctx->r15;
            goto L_80525A78;
    }
    // 0x80525A2C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x80525A30: addiu       $at, $zero, 0x41E8
    ctx->r1 = ADD32(0, 0X41E8);
    // 0x80525A34: beq         $v0, $at, L_80525A5C
    if (ctx->r2 == ctx->r1) {
        // 0x80525A38: addiu       $t8, $zero, 0x4736
        ctx->r24 = ADD32(0, 0X4736);
            goto L_80525A5C;
    }
    // 0x80525A38: addiu       $t8, $zero, 0x4736
    ctx->r24 = ADD32(0, 0X4736);
    // 0x80525A3C: addiu       $at, $zero, 0x41E9
    ctx->r1 = ADD32(0, 0X41E9);
    // 0x80525A40: beq         $v0, $at, L_80525A8C
    if (ctx->r2 == ctx->r1) {
        // 0x80525A44: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_80525A8C;
    }
    // 0x80525A44: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80525A48: addiu       $at, $zero, 0x41EA
    ctx->r1 = ADD32(0, 0X41EA);
    // 0x80525A4C: beq         $v0, $at, L_80525A68
    if (ctx->r2 == ctx->r1) {
        // 0x80525A50: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80525A68;
    }
    // 0x80525A50: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80525A54: b           L_80525A9C
    // 0x80525A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80525A9C;
    // 0x80525A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80525A5C:
    // 0x80525A5C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80525A60: b           L_80525A98
    // 0x80525A64: sh          $t8, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r24;
        goto L_80525A98;
    // 0x80525A64: sh          $t8, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r24;
L_80525A68:
    // 0x80525A68: addiu       $t0, $zero, 0x4738
    ctx->r8 = ADD32(0, 0X4738);
    // 0x80525A6C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80525A70: b           L_80525A98
    // 0x80525A74: sh          $t0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r8;
        goto L_80525A98;
    // 0x80525A74: sh          $t0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r8;
L_80525A78:
    // 0x80525A78: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80525A7C: addiu       $t2, $zero, 0x4735
    ctx->r10 = ADD32(0, 0X4735);
    // 0x80525A80: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80525A84: b           L_80525A98
    // 0x80525A88: sh          $t2, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r10;
        goto L_80525A98;
    // 0x80525A88: sh          $t2, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r10;
L_80525A8C:
    // 0x80525A8C: addiu       $t4, $zero, 0x4737
    ctx->r12 = ADD32(0, 0X4737);
    // 0x80525A90: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80525A94: sh          $t4, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r12;
L_80525A98:
    // 0x80525A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80525A9C:
    // 0x80525A9C: jal         0x8052598C
    // 0x80525AA0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8052598C(rdram, ctx);
        goto after_0;
    // 0x80525AA0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x80525AA4: beq         $v0, $zero, L_80525B38
    if (ctx->r2 == 0) {
        // 0x80525AA8: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_80525B38;
    }
    // 0x80525AA8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80525AAC: beq         $t5, $zero, L_80525AC8
    if (ctx->r13 == 0) {
        // 0x80525AB0: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_80525AC8;
    }
    // 0x80525AB0: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80525AB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80525AB8: beq         $t5, $at, L_80525AE4
    if (ctx->r13 == ctx->r1) {
        // 0x80525ABC: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_80525AE4;
    }
    // 0x80525ABC: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80525AC0: b           L_80525AF8
    // 0x80525AC4: nop

        goto L_80525AF8;
    // 0x80525AC4: nop

L_80525AC8:
    // 0x80525AC8: lw          $t9, -0x72EC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72EC);
    // 0x80525ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80525AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80525AD4: jalr        $t9
    // 0x80525AD8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80525AD8: nop

    after_1:
    // 0x80525ADC: b           L_80525AF8
    // 0x80525AE0: nop

        goto L_80525AF8;
    // 0x80525AE0: nop

L_80525AE4:
    // 0x80525AE4: lw          $t9, -0x72EC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72EC);
    // 0x80525AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80525AEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80525AF0: jalr        $t9
    // 0x80525AF4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80525AF4: nop

    after_2:
L_80525AF8:
    // 0x80525AF8: jal         0x805259E4
    // 0x80525AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805259E4(rdram, ctx);
        goto after_3;
    // 0x80525AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80525B00: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80525B04: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x80525B08: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(324, 0X8EC) << 16);
    // 0x80525B0C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80525B10: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80525B14: lh          $t8, 0x5DFC($t8)
    ctx->r24 = MEM_H(ctx->r24, (int16_t)RELOC_LO16(324, 0X8EC));
    // 0x80525B18: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80525B1C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80525B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80525B24: sh          $t8, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r24;
    // 0x80525B28: lw          $t9, -0x71E4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X71E4);
    // 0x80525B2C: lhu         $a1, 0x22($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X22);
    // 0x80525B30: jalr        $t9
    // 0x80525B34: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80525B34: nop

    after_4:
L_80525B38:
    // 0x80525B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80525B3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80525B40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80525B44: jr          $ra
    // 0x80525B48: nop

    return;
    // 0x80525B48: nop

;}
RECOMP_FUNC void func_8004C318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C318: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004C31C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004C320: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004C324: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8004C328: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8004C32C: lh          $v0, 0x6($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X6);
    // 0x8004C330: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8004C334: lh          $t0, 0x10($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X10);
    // 0x8004C338: blez        $v0, L_8004C378
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004C33C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8004C378;
    }
    // 0x8004C33C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004C340: lhu         $a0, 0x2($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X2);
    // 0x8004C344: addu        $t6, $t0, $v1
    ctx->r14 = ADD32(ctx->r8, ctx->r3);
L_8004C348:
    // 0x8004C348: sllv        $t7, $a0, $t6
    ctx->r15 = S32(ctx->r4 << (ctx->r14 & 31));
    // 0x8004C34C: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8004C350: bnel        $t8, $zero, L_8004C364
    if (ctx->r24 != 0) {
        // 0x8004C354: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8004C364;
    }
    goto skip_0;
    // 0x8004C354: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8004C358: b           L_8004C4BC
    // 0x8004C35C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8004C4BC;
    // 0x8004C35C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004C360: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8004C364:
    // 0x8004C364: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004C368: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004C36C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004C370: bnel        $at, $zero, L_8004C348
    if (ctx->r1 != 0) {
        // 0x8004C374: addu        $t6, $t0, $v1
        ctx->r14 = ADD32(ctx->r8, ctx->r3);
            goto L_8004C348;
    }
    goto skip_1;
    // 0x8004C374: addu        $t6, $t0, $v1
    ctx->r14 = ADD32(ctx->r8, ctx->r3);
    skip_1:
L_8004C378:
    // 0x8004C378: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8004C37C: slti        $at, $t9, 0x11
    ctx->r1 = SIGNED(ctx->r25) < 0X11 ? 1 : 0;
    // 0x8004C380: bnel        $at, $zero, L_8004C394
    if (ctx->r1 != 0) {
        // 0x8004C384: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_8004C394;
    }
    goto skip_2;
    // 0x8004C384: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    skip_2:
    // 0x8004C388: b           L_8004C4BC
    // 0x8004C38C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8004C4BC;
    // 0x8004C38C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004C390: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
L_8004C394:
    // 0x8004C394: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004C398: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004C39C: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x8004C3A0: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004C3A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004C3A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004C3AC: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8004C3B0: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004C3B4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004C3B8: sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    // 0x8004C3BC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8004C3C0: jal         0x800534C0
    // 0x8004C3C4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800534C0(rdram, ctx);
        goto after_0;
    // 0x8004C3C4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x8004C3C8: lh          $v1, 0x2E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2E);
    // 0x8004C3CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8004C3D0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8004C3D4: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8004C3D8: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x8004C3DC: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8004C3E0: andi        $t5, $v0, 0x7FF
    ctx->r13 = ctx->r2 & 0X7FF;
    // 0x8004C3E4: andi        $t3, $t2, 0xF8
    ctx->r11 = ctx->r10 & 0XF8;
    // 0x8004C3E8: bnel        $t3, $at, L_8004C3F8
    if (ctx->r11 != ctx->r1) {
        // 0x8004C3EC: lhu         $v0, 0x0($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X0);
            goto L_8004C3F8;
    }
    goto skip_3;
    // 0x8004C3EC: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    skip_3:
    // 0x8004C3F0: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x8004C3F4: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
L_8004C3F8:
    // 0x8004C3F8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004C3FC: beql        $v0, $zero, L_8004C4BC
    if (ctx->r2 == 0) {
        // 0x8004C400: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004C4BC;
    }
    goto skip_4;
    // 0x8004C400: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_4:
    // 0x8004C404: beql        $v0, $at, L_8004C4BC
    if (ctx->r2 == ctx->r1) {
        // 0x8004C408: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004C4BC;
    }
    goto skip_5;
    // 0x8004C408: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_5:
    // 0x8004C40C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004C410: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004C414: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8004C418: beq         $v0, $at, L_8004C4B8
    if (ctx->r2 == ctx->r1) {
        // 0x8004C41C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004C4B8;
    }
    // 0x8004C41C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004C420: beq         $v0, $at, L_8004C4B8
    if (ctx->r2 == ctx->r1) {
        // 0x8004C424: addiu       $t6, $zero, 0x10
        ctx->r14 = ADD32(0, 0X10);
            goto L_8004C4B8;
    }
    // 0x8004C424: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8004C428: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x8004C42C: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x8004C430: lh          $t4, 0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4);
    // 0x8004C434: srl         $t7, $v0, 6
    ctx->r15 = S32(U32(ctx->r2) >> 6);
    // 0x8004C438: andi        $t9, $v0, 0x3F
    ctx->r25 = ctx->r2 & 0X3F;
    // 0x8004C43C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8004C440: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8004C444: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8004C448: sh          $zero, 0x10($s0)
    MEM_H(0X10, ctx->r16) = 0;
    // 0x8004C44C: sh          $t6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r14;
    // 0x8004C450: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8004C454: lw          $t3, 0xA24($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XA24);
    // 0x8004C458: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8004C45C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8004C460: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x8004C464: andi        $t8, $t9, 0x8000
    ctx->r24 = ctx->r25 & 0X8000;
    // 0x8004C468: beq         $t8, $zero, L_8004C4B8
    if (ctx->r24 == 0) {
        // 0x8004C46C: sh          $t9, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r25;
            goto L_8004C4B8;
    }
    // 0x8004C46C: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x8004C470: lw          $t2, 0x174($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X174);
    // 0x8004C474: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x8004C478: lhu         $t1, 0x0($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X0);
    // 0x8004C47C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8004C480: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x8004C484: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8004C488: lw          $t3, 0x40($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X40);
    // 0x8004C48C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8004C490: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8004C494: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
    // 0x8004C498: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8004C49C: sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    // 0x8004C4A0: jal         0x8004C318
    // 0x8004C4A4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_8004C318(rdram, ctx);
        goto after_1;
    // 0x8004C4A4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_1:
    // 0x8004C4A8: lh          $v1, 0x2E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2E);
    // 0x8004C4AC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004C4B0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004C4B4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8004C4B8:
    // 0x8004C4B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8004C4BC:
    // 0x8004C4BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004C4C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004C4C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004C4C8: jr          $ra
    // 0x8004C4CC: nop

    return;
    // 0x8004C4CC: nop

;}
RECOMP_FUNC void func_80008AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008AFC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80008B00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80008B04: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80008B08: sltu        $at, $v0, $at
    ctx->r1 = ctx->r2 < ctx->r1 ? 1 : 0;
    // 0x80008B0C: beq         $at, $zero, L_80008C34
    if (ctx->r1 == 0) {
        // 0x80008B10: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_80008C34;
    }
    // 0x80008B10: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80008B14: addu        $v1, $v0, $a1
    ctx->r3 = ADD32(ctx->r2, ctx->r5);
    // 0x80008B18: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80008B1C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80008B20: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80008B24: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80008B28: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80008B2C: beq         $t7, $zero, L_80008C34
    if (ctx->r15 == 0) {
        // 0x80008B30: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_80008C34;
    }
    // 0x80008B30: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80008B34: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80008B38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80008B3C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80008B40: beq         $a0, $t9, L_80008C34
    if (ctx->r4 == ctx->r25) {
        // 0x80008B44: nop
    
            goto L_80008C34;
    }
    // 0x80008B44: nop

    // 0x80008B48: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x80008B4C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80008B50: lw          $t1, 0xC($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XC);
    // 0x80008B54: addu        $v1, $t0, $a1
    ctx->r3 = ADD32(ctx->r8, ctx->r5);
    // 0x80008B58: sw          $v1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r3;
    // 0x80008B5C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80008B60: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x80008B64: addu        $v1, $t1, $a1
    ctx->r3 = ADD32(ctx->r9, ctx->r5);
    // 0x80008B68: beq         $v0, $zero, L_80008B90
    if (ctx->r2 == 0) {
        // 0x80008B6C: sw          $v1, 0xC($a2)
        MEM_W(0XC, ctx->r6) = ctx->r3;
            goto L_80008B90;
    }
    // 0x80008B6C: sw          $v1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r3;
    // 0x80008B70: beq         $v0, $a0, L_80008BC0
    if (ctx->r2 == ctx->r4) {
        // 0x80008B74: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80008BC0;
    }
    // 0x80008B74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80008B78: beq         $v0, $at, L_80008BEC
    if (ctx->r2 == ctx->r1) {
        // 0x80008B7C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80008BEC;
    }
    // 0x80008B7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80008B80: beql        $v0, $at, L_80008BF0
    if (ctx->r2 == ctx->r1) {
        // 0x80008B84: lbu         $t1, 0x0($a2)
        ctx->r9 = MEM_BU(ctx->r6, 0X0);
            goto L_80008BF0;
    }
    goto skip_0;
    // 0x80008B84: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
    skip_0:
    // 0x80008B88: b           L_80008BF0
    // 0x80008B8C: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
        goto L_80008BF0;
    // 0x80008B8C: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
L_80008B90:
    // 0x80008B90: lw          $t2, 0x4($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X4);
    // 0x80008B94: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x80008B98: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x80008B9C: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x80008BA0: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x80008BA4: lw          $t5, 0x10($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X10);
    // 0x80008BA8: andi        $t9, $t8, 0xFFF3
    ctx->r25 = ctx->r24 & 0XFFF3;
    // 0x80008BAC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80008BB0: andi        $t7, $t6, 0xC
    ctx->r15 = ctx->r14 & 0XC;
    // 0x80008BB4: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80008BB8: b           L_80008BEC
    // 0x80008BBC: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
        goto L_80008BEC;
    // 0x80008BBC: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
L_80008BC0:
    // 0x80008BC0: lw          $t1, 0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4);
    // 0x80008BC4: lw          $t2, 0xC($a3)
    ctx->r10 = MEM_W(ctx->r7, 0XC);
    // 0x80008BC8: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x80008BCC: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80008BD0: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x80008BD4: lw          $t4, 0x14($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X14);
    // 0x80008BD8: andi        $t7, $t8, 0xFFF3
    ctx->r15 = ctx->r24 & 0XFFF3;
    // 0x80008BDC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80008BE0: andi        $t6, $t5, 0xC
    ctx->r14 = ctx->r13 & 0XC;
    // 0x80008BE4: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80008BE8: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
L_80008BEC:
    // 0x80008BEC: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
L_80008BF0:
    // 0x80008BF0: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80008BF4: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x80008BF8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80008BFC: sll         $t4, $v0, 6
    ctx->r12 = S32(ctx->r2 << 6);
    // 0x80008C00: bgez        $t4, L_80008C34
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80008C04: sll         $t5, $v0, 4
        ctx->r13 = S32(ctx->r2 << 4);
            goto L_80008C34;
    }
    // 0x80008C04: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x80008C08: srl         $t8, $t5, 30
    ctx->r24 = S32(U32(ctx->r13) >> 30);
    // 0x80008C0C: beq         $t8, $zero, L_80008C34
    if (ctx->r24 == 0) {
        // 0x80008C10: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_80008C34;
    }
    // 0x80008C10: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80008C14: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x80008C18: lw          $t6, 0xD80($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD80);
    // 0x80008C1C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80008C20: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x80008C24: sw          $a2, 0x180($t9)
    MEM_W(0X180, ctx->r25) = ctx->r6;
    // 0x80008C28: lw          $t0, 0xD80($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XD80);
    // 0x80008C2C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80008C30: sw          $t1, 0xD80($v0)
    MEM_W(0XD80, ctx->r2) = ctx->r9;
L_80008C34:
    // 0x80008C34: jr          $ra
    // 0x80008C38: nop

    return;
    // 0x80008C38: nop

;}
RECOMP_FUNC void func_8005780C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005780C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80057810: beq         $a0, $zero, L_8005783C
    if (ctx->r4 == 0) {
        // 0x80057814: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8005783C;
    }
    // 0x80057814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057818: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8005781C: beql        $a0, $zero, L_80057840
    if (ctx->r4 == 0) {
        // 0x80057820: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80057840;
    }
    goto skip_0;
    // 0x80057820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80057824: jal         0x800574D0
    // 0x80057828: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800574D0(rdram, ctx);
        goto after_0;
    // 0x80057828: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005782C: jal         0x800574F4
    // 0x80057830: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800574F4(rdram, ctx);
        goto after_1;
    // 0x80057830: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80057834: jal         0x80057560
    // 0x80057838: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80057560(rdram, ctx);
        goto after_2;
    // 0x80057838: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_8005783C:
    // 0x8005783C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80057840:
    // 0x80057840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80057844: jr          $ra
    // 0x80057848: nop

    return;
    // 0x80057848: nop

;}
RECOMP_FUNC void func_804555F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804555F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804555F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804555FC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80455600: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455604: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80455608: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8045560C: lwc1        $f12, 0x6C84($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X6C84);
    // 0x80455610: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80455614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80455618: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x8045561C: nop

    // 0x80455620: bc1f        L_80455670
    if (!c1cs) {
        // 0x80455624: nop
    
            goto L_80455670;
    }
    // 0x80455624: nop

    // 0x80455628: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8045562C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80455630: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80455634: jal         0x80450490
    // 0x80455638: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80450490(rdram, ctx);
        goto after_0;
    // 0x80455638: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045563C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80455640: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80455644: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80455648: lwc1        $f6, 0x6C84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X6C84);
    // 0x8045564C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80455650: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455654: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80455658: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8045565C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455660: jal         0x80455544
    // 0x80455664: swc1        $f10, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f10.u32l;
    func_80455544(rdram, ctx);
        goto after_1;
    // 0x80455664: swc1        $f10, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f10.u32l;
    after_1:
    // 0x80455668: b           L_8045567C
    // 0x8045566C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8045567C;
    // 0x8045566C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80455670:
    // 0x80455670: jal         0x80457164
    // 0x80455674: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_80457164(rdram, ctx);
        goto after_2;
    // 0x80455674: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_2:
    // 0x80455678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045567C:
    // 0x8045567C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80455680: jr          $ra
    // 0x80455684: nop

    return;
    // 0x80455684: nop

;}
RECOMP_FUNC void func_807BB4C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BB4C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BB4C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BB4C8: jal         0x80056904
    // 0x807BB4CC: nop

    func_80056904(rdram, ctx);
        goto after_0;
    // 0x807BB4CC: nop

    after_0:
    // 0x807BB4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BB4D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BB4D8: jr          $ra
    // 0x807BB4DC: nop

    return;
    // 0x807BB4DC: nop

;}
RECOMP_FUNC void func_80022A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022A58: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x80022A5C: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80022A60: slti        $at, $a0, 0xF
    ctx->r1 = SIGNED(ctx->r4) < 0XF ? 1 : 0;
    // 0x80022A64: bnel        $at, $zero, L_80022A90
    if (ctx->r1 != 0) {
        // 0x80022A68: slti        $at, $a0, -0xE
        ctx->r1 = SIGNED(ctx->r4) < -0XE ? 1 : 0;
            goto L_80022A90;
    }
    goto skip_0;
    // 0x80022A68: slti        $at, $a0, -0xE
    ctx->r1 = SIGNED(ctx->r4) < -0XE ? 1 : 0;
    skip_0:
    // 0x80022A6C: addiu       $a0, $a0, -0xE
    ctx->r4 = ADD32(ctx->r4, -0XE);
    // 0x80022A70: slti        $at, $a0, 0x37
    ctx->r1 = SIGNED(ctx->r4) < 0X37 ? 1 : 0;
    // 0x80022A74: bnel        $at, $zero, L_80022A84
    if (ctx->r1 != 0) {
        // 0x80022A78: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80022A84;
    }
    goto skip_1;
    // 0x80022A78: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    skip_1:
    // 0x80022A7C: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x80022A80: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80022A84:
    // 0x80022A84: jr          $ra
    // 0x80022A88: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x80022A88: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022A8C: slti        $at, $a0, -0xE
    ctx->r1 = SIGNED(ctx->r4) < -0XE ? 1 : 0;
L_80022A90:
    // 0x80022A90: beq         $at, $zero, L_80022AB8
    if (ctx->r1 == 0) {
        // 0x80022A94: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80022AB8;
    }
    // 0x80022A94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80022A98: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    // 0x80022A9C: slti        $at, $a0, -0x36
    ctx->r1 = SIGNED(ctx->r4) < -0X36 ? 1 : 0;
    // 0x80022AA0: beql        $at, $zero, L_80022AB0
    if (ctx->r1 == 0) {
        // 0x80022AA4: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80022AB0;
    }
    goto skip_2;
    // 0x80022AA4: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    skip_2:
    // 0x80022AA8: addiu       $a0, $zero, -0x36
    ctx->r4 = ADD32(0, -0X36);
    // 0x80022AAC: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80022AB0:
    // 0x80022AB0: jr          $ra
    // 0x80022AB4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x80022AB4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80022AB8:
    // 0x80022AB8: jr          $ra
    // 0x80022ABC: nop

    return;
    // 0x80022ABC: nop

;}
RECOMP_FUNC void func_8049F1AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049F1AC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8049F1B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8049F1B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8049F1B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8049F1BC: lw          $s1, 0x16C($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X16C);
    // 0x8049F1C0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8049F1C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8049F1C8: addiu       $s1, $s1, 0xD
    ctx->r17 = ADD32(ctx->r17, 0XD);
    // 0x8049F1CC: jal         0x8049EF18
    // 0x8049F1D0: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    func_8049EF18(rdram, ctx);
        goto after_0;
    // 0x8049F1D0: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    after_0:
    // 0x8049F1D4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8049F1D8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8049F1DC: bnel        $t8, $zero, L_8049F238
    if (ctx->r24 != 0) {
        // 0x8049F1E0: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_8049F238;
    }
    goto skip_0;
    // 0x8049F1E0: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_0:
    // 0x8049F1E4: lwc1        $f2, 0x6C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8049F1E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8049F1EC: sb          $t9, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r25;
    // 0x8049F1F0: add.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8049F1F4: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8049F1F8: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x8049F1FC: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x8049F200: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8049F204: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8049F208: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8049F20C: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x8049F210: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8049F214: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8049F218: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x8049F21C: jalr        $t9
    // 0x8049F220: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8049F220: nop

    after_1:
    // 0x8049F224: jal         0x800447C8
    // 0x8049F228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x8049F228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8049F22C: b           L_8049F3A8
    // 0x8049F230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8049F3A8;
    // 0x8049F230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8049F234: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_8049F238:
    // 0x8049F238: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X14D0) << 16);
    // 0x8049F23C: bne         $v0, $zero, L_8049F270
    if (ctx->r2 != 0) {
        // 0x8049F240: nop
    
            goto L_8049F270;
    }
    // 0x8049F240: nop

    // 0x8049F244: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8049F248: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8049F24C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8049F250: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
    // 0x8049F254: swc1        $f6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f6.u32l;
    // 0x8049F258: swc1        $f8, 0x50($at)
    MEM_W((int16_t)RELOC_LO16(167, 0X14D0), ctx->r1) = ctx->f8.u32l;
    // 0x8049F25C: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X12C4) << 16);
    // 0x8049F260: lwc1        $f2, -0x1BC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(167, 0X12C4));
    // 0x8049F264: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X14D4) << 16);
    // 0x8049F268: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x8049F26C: swc1        $f2, 0x54($at)
    MEM_W((int16_t)RELOC_LO16(167, 0X14D4), ctx->r1) = ctx->f2.u32l;
L_8049F270:
    // 0x8049F270: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X14D0) << 16);
    // 0x8049F274: lwc1        $f10, 0x50($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(167, 0X14D0));
    // 0x8049F278: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8049F27C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8049F280: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8049F284: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8049F288: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8049F28C: andi        $t2, $v0, 0x7
    ctx->r10 = ctx->r2 & 0X7;
    // 0x8049F290: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8049F294: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8049F298: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8049F29C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8049F2A0: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x8049F2A4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8049F2A8: subu        $a0, $t4, $t3
    ctx->r4 = SUB32(ctx->r12, ctx->r11);
    // 0x8049F2AC: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    // 0x8049F2B0: jal         0x8006593C
    // 0x8049F2B4: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    func_8006593C(rdram, ctx);
        goto after_3;
    // 0x8049F2B4: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x8049F2B8: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X14D0) << 16);
    // 0x8049F2BC: lwc1        $f0, 0x50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(167, 0X14D0));
    // 0x8049F2C0: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X14D4) << 16);
    // 0x8049F2C4: lwc1        $f2, 0x54($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(167, 0X14D4));
    // 0x8049F2C8: addiu       $v1, $v0, 0xF
    ctx->r3 = ADD32(ctx->r2, 0XF);
    // 0x8049F2CC: sb          $v1, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r3;
    // 0x8049F2D0: sb          $v1, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r3;
    // 0x8049F2D4: lw          $t5, 0x1E0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1E0);
    // 0x8049F2D8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8049F2DC: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X12C8) << 16);
    // 0x8049F2E0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8049F2E4: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
    // 0x8049F2E8: lwc1        $f10, -0x1B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(167, 0X12C8));
    // 0x8049F2EC: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X12CC) << 16);
    // 0x8049F2F0: lwc1        $f4, -0x1B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(167, 0X12CC));
    // 0x8049F2F4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8049F2F8: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X14D0) << 16);
    // 0x8049F2FC: swc1        $f0, 0x50($at)
    MEM_W((int16_t)RELOC_LO16(167, 0X14D0), ctx->r1) = ctx->f0.u32l;
    // 0x8049F300: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X14D4) << 16);
    // 0x8049F304: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8049F308: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8049F30C: swc1        $f2, 0x54($at)
    MEM_W((int16_t)RELOC_LO16(167, 0X14D4), ctx->r1) = ctx->f2.u32l;
    // 0x8049F310: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
    // 0x8049F314: slti        $at, $t7, 0x79
    ctx->r1 = SIGNED(ctx->r15) < 0X79 ? 1 : 0;
    // 0x8049F318: bnel        $at, $zero, L_8049F3A8
    if (ctx->r1 != 0) {
        // 0x8049F31C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8049F3A8;
    }
    goto skip_1;
    // 0x8049F31C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8049F320: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x8049F324: addiu       $at, $zero, 0x4054
    ctx->r1 = ADD32(0, 0X4054);
    // 0x8049F328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F32C: beq         $v0, $at, L_8049F364
    if (ctx->r2 == ctx->r1) {
        // 0x8049F330: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8049F364;
    }
    // 0x8049F330: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F334: addiu       $at, $zero, 0x4056
    ctx->r1 = ADD32(0, 0X4056);
    // 0x8049F338: beq         $v0, $at, L_8049F378
    if (ctx->r2 == ctx->r1) {
        // 0x8049F33C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8049F378;
    }
    // 0x8049F33C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F340: addiu       $at, $zero, 0x4057
    ctx->r1 = ADD32(0, 0X4057);
    // 0x8049F344: bne         $v0, $at, L_8049F388
    if (ctx->r2 != ctx->r1) {
        // 0x8049F348: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8049F388;
    }
    // 0x8049F348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F34C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F350: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8049F354: jal         0x8049FBAC
    // 0x8049F358: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8049FBAC(rdram, ctx);
        goto after_4;
    // 0x8049F358: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x8049F35C: b           L_8049F38C
    // 0x8049F360: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
        goto L_8049F38C;
    // 0x8049F360: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_8049F364:
    // 0x8049F364: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8049F368: jal         0x8049FBAC
    // 0x8049F36C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8049FBAC(rdram, ctx);
        goto after_5;
    // 0x8049F36C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
    // 0x8049F370: b           L_8049F38C
    // 0x8049F374: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
        goto L_8049F38C;
    // 0x8049F374: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_8049F378:
    // 0x8049F378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F37C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8049F380: jal         0x8049FBAC
    // 0x8049F384: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8049FBAC(rdram, ctx);
        goto after_6;
    // 0x8049F384: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
L_8049F388:
    // 0x8049F388: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_8049F38C:
    // 0x8049F38C: sb          $t0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r8;
    // 0x8049F390: sb          $t0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r8;
    // 0x8049F394: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8049F398: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8049F39C: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x8049F3A0: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    // 0x8049F3A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8049F3A8:
    // 0x8049F3A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8049F3AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8049F3B0: jr          $ra
    // 0x8049F3B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8049F3B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8004D414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D414: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004D418: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8004D41C: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x8004D420: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004D424: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004D428: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004D42C: addu        $a2, $t7, $v1
    ctx->r6 = ADD32(ctx->r15, ctx->r3);
    // 0x8004D430: lbu         $t8, 0x14($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X14);
    // 0x8004D434: beq         $t8, $zero, L_8004D468
    if (ctx->r24 == 0) {
        // 0x8004D438: nop
    
            goto L_8004D468;
    }
    // 0x8004D438: nop

    // 0x8004D43C: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x8004D440: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x8004D444: bne         $t0, $zero, L_8004D468
    if (ctx->r8 != 0) {
        // 0x8004D448: nop
    
            goto L_8004D468;
    }
    // 0x8004D448: nop

    // 0x8004D44C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004D450: nop

    // 0x8004D454: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
    // 0x8004D458: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8004D45C: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8004D460: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8004D464: sb          $zero, 0x14($t3)
    MEM_B(0X14, ctx->r11) = 0;
L_8004D468:
    // 0x8004D468: jr          $ra
    // 0x8004D46C: nop

    return;
    // 0x8004D46C: nop

;}
RECOMP_FUNC void func_8000B214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B21C: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x8000B220: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000B224: addiu       $a2, $a3, 0x36
    ctx->r6 = ADD32(ctx->r7, 0X36);
    // 0x8000B228: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x8000B22C: bnel        $t6, $zero, L_8000B258
    if (ctx->r14 != 0) {
        // 0x8000B230: lw          $a1, 0x1C($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X1C);
            goto L_8000B258;
    }
    goto skip_0;
    // 0x8000B230: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    skip_0:
    // 0x8000B234: lw          $t7, 0x50($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X50);
    // 0x8000B238: addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    // 0x8000B23C: addiu       $a2, $a3, 0x36
    ctx->r6 = ADD32(ctx->r7, 0X36);
    // 0x8000B240: lw          $a1, 0x88($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X88);
    // 0x8000B244: jal         0x8000CFD0
    // 0x8000B248: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8000CFD0(rdram, ctx);
        goto after_0;
    // 0x8000B248: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000B24C: b           L_8000B268
    // 0x8000B250: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
        goto L_8000B268;
    // 0x8000B250: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8000B254: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
L_8000B258:
    // 0x8000B258: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8000B25C: jal         0x8000CFD0
    // 0x8000B260: addiu       $a0, $a3, 0x60
    ctx->r4 = ADD32(ctx->r7, 0X60);
    func_8000CFD0(rdram, ctx);
        goto after_1;
    // 0x8000B260: addiu       $a0, $a3, 0x60
    ctx->r4 = ADD32(ctx->r7, 0X60);
    after_1:
    // 0x8000B264: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8000B268:
    // 0x8000B268: lbu         $t8, 0x60($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X60);
    // 0x8000B26C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8000B270: sb          $zero, 0x34($a3)
    MEM_B(0X34, ctx->r7) = 0;
    // 0x8000B274: andi        $t9, $t8, 0xFFF0
    ctx->r25 = ctx->r24 & 0XFFF0;
    // 0x8000B278: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8000B27C: sb          $t0, 0x60($a3)
    MEM_B(0X60, ctx->r7) = ctx->r8;
    // 0x8000B280: addiu       $t1, $t1, 0x6C24
    ctx->r9 = ADD32(ctx->r9, 0X6C24);
    // 0x8000B284: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8000B288: sw          $t3, 0xB0($a3)
    MEM_W(0XB0, ctx->r7) = ctx->r11;
    // 0x8000B28C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8000B290: sw          $t2, 0xB4($a3)
    MEM_W(0XB4, ctx->r7) = ctx->r10;
    // 0x8000B294: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8000B298: sw          $t3, 0xB8($a3)
    MEM_W(0XB8, ctx->r7) = ctx->r11;
    // 0x8000B29C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8000B2A0: sw          $t2, 0xBC($a3)
    MEM_W(0XBC, ctx->r7) = ctx->r10;
    // 0x8000B2A4: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x8000B2A8: sw          $t3, 0xC0($a3)
    MEM_W(0XC0, ctx->r7) = ctx->r11;
    // 0x8000B2AC: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8000B2B0: sw          $t2, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->r10;
    // 0x8000B2B4: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x8000B2B8: sw          $t3, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->r11;
    // 0x8000B2BC: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x8000B2C0: sw          $t2, 0xCC($a3)
    MEM_W(0XCC, ctx->r7) = ctx->r10;
    // 0x8000B2C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B2C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000B2CC: jr          $ra
    // 0x8000B2D0: nop

    return;
    // 0x8000B2D0: nop

;}
RECOMP_FUNC void func_806B29AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B29AC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B29B0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B29B4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B29B8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B29BC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B29C0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B29C4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B29C8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B29CC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B29D0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B29D4: jr          $ra
    // 0x806B29D8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B29D8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8073677C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073677C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80736780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736784: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80736788: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8073678C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x80736790: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80736794: jal         0x80736708
    // 0x80736798: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    func_80736708(rdram, ctx);
        goto after_0;
    // 0x80736798: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    after_0:
    // 0x8073679C: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x807367A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807367A4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x807367A8: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x807367AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807367B0: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B40) << 16);
    // 0x807367B4: lwc1        $f12, -0x6A60($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B40));
    // 0x807367B8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B44) << 16);
    // 0x807367BC: addiu       $v0, $a2, 0xC4
    ctx->r2 = ADD32(ctx->r6, 0XC4);
    // 0x807367C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x807367C4: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x807367C8: lwc1        $f2, -0x6A5C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B44));
    // 0x807367CC: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x807367D0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x807367D4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
L_807367D8:
    // 0x807367D8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807367DC: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x807367E0: lwc1        $f10, 0x1C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x807367E4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x807367E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807367EC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x807367F0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x807367F4: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x807367F8: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x807367FC: lwc1        $f0, -0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80736800: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80736804: nop

    // 0x80736808: bc1f        L_80736830
    if (!c1cs) {
        // 0x8073680C: nop
    
            goto L_80736830;
    }
    // 0x8073680C: nop

    // 0x80736810: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80736814: nop

    // 0x80736818: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8073681C: sub.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80736820: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80736824: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80736828: b           L_80736850
    // 0x8073682C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_80736850;
    // 0x8073682C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_80736830:
    // 0x80736830: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80736834: nop

    // 0x80736838: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8073683C: nop

    // 0x80736840: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80736844: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80736848: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8073684C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_80736850:
    // 0x80736850: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80736854: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80736858: nop

    // 0x8073685C: bc1fl       L_80736870
    if (!c1cs) {
        // 0x80736860: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_80736870;
    }
    goto skip_0;
    // 0x80736860: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_0:
    // 0x80736864: b           L_80736880
    // 0x80736868: swc1        $f14, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
        goto L_80736880;
    // 0x80736868: swc1        $f14, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
    // 0x8073686C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_80736870:
    // 0x80736870: nop

    // 0x80736874: bc1f        L_80736880
    if (!c1cs) {
        // 0x80736878: nop
    
            goto L_80736880;
    }
    // 0x80736878: nop

    // 0x8073687C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_80736880:
    // 0x80736880: bne         $a0, $a2, L_807367D8
    if (ctx->r4 != ctx->r6) {
        // 0x80736884: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_807367D8;
    }
    // 0x80736884: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80736888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073688C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80736890: jr          $ra
    // 0x80736894: nop

    return;
    // 0x80736894: nop

;}
RECOMP_FUNC void func_80051640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051640: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80051644: addiu       $a2, $a2, -0x57C4
    ctx->r6 = ADD32(ctx->r6, -0X57C4);
    // 0x80051648: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8005164C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80051650: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80051654: slti        $at, $v0, 0xA5
    ctx->r1 = SIGNED(ctx->r2) < 0XA5 ? 1 : 0;
    // 0x80051658: beq         $at, $zero, L_8005167C
    if (ctx->r1 == 0) {
        // 0x8005165C: sll         $t6, $v0, 4
        ctx->r14 = S32(ctx->r2 << 4);
            goto L_8005167C;
    }
    // 0x8005165C: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80051660: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80051664: addiu       $t7, $t7, -0x57C0
    ctx->r15 = ADD32(ctx->r15, -0X57C0);
    // 0x80051668: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8005166C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80051670: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80051674: sh          $a1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r5;
    // 0x80051678: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_8005167C:
    // 0x8005167C: jr          $ra
    // 0x80051680: nop

    return;
    // 0x80051680: nop

;}
RECOMP_FUNC void func_8007BA6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BA6C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8007BA70: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8007BA74: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8007BA78: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8007BA7C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8007BA80: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8007BA84: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8007BA88: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8007BA8C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8007BA90: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8007BA94: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8007BA98: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007BA9C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8007BAA0: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8007BAA4: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x8007BAA8: lwc1        $f20, 0x0($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8007BAAC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007BAB0: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x8007BAB4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8007BAB8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007BABC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BAC0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BAC4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8007BAC8: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x8007BACC: lui         $t9, 0xFFFC
    ctx->r25 = S32(0XFFFC << 16);
    // 0x8007BAD0: ori         $t9, $t9, 0xFC7E
    ctx->r25 = ctx->r25 | 0XFC7E;
    // 0x8007BAD4: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x8007BAD8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007BADC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007BAE0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BAE4: lui         $a1, 0xF0A
    ctx->r5 = S32(0XF0A << 16);
    // 0x8007BAE8: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x8007BAEC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8007BAF0: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8007BAF4: ori         $t6, $t6, 0x18
    ctx->r14 = ctx->r14 | 0X18;
    // 0x8007BAF8: addiu       $t7, $zero, 0xC00
    ctx->r15 = ADD32(0, 0XC00);
    // 0x8007BAFC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007BB00: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007BB04: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BB08: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8007BB0C: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8007BB10: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x8007BB14: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007BB18: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8007BB1C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BB20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007BB24: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x8007BB28: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x8007BB2C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007BB30: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x8007BB34: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BB38: lw          $t6, 0x2C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X2C);
    // 0x8007BB3C: lw          $t7, 0x24($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X24);
    // 0x8007BB40: addiu       $at, $zero, -0x40
    ctx->r1 = ADD32(0, -0X40);
    // 0x8007BB44: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x8007BB48: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x8007BB4C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007BB50: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8007BB54: addiu       $v0, $v0, 0x3F
    ctx->r2 = ADD32(ctx->r2, 0X3F);
    // 0x8007BB58: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x8007BB5C: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8007BB60: div         $zero, $t9, $t8
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r24)));
    // 0x8007BB64: mflo        $s7
    ctx->r23 = lo;
    // 0x8007BB68: lui         $fp, 0x1000
    ctx->r30 = S32(0X1000 << 16);
    // 0x8007BB6C: bne         $t8, $zero, L_8007BB78
    if (ctx->r24 != 0) {
        // 0x8007BB70: nop
    
            goto L_8007BB78;
    }
    // 0x8007BB70: nop

    // 0x8007BB74: break       7
    do_break(2147990388);
L_8007BB78:
    // 0x8007BB78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007BB7C: bne         $t8, $at, L_8007BB90
    if (ctx->r24 != ctx->r1) {
        // 0x8007BB80: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007BB90;
    }
    // 0x8007BB80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007BB84: bne         $t9, $at, L_8007BB90
    if (ctx->r25 != ctx->r1) {
        // 0x8007BB88: nop
    
            goto L_8007BB90;
    }
    // 0x8007BB88: nop

    // 0x8007BB8C: break       6
    do_break(2147990412);
L_8007BB90:
    // 0x8007BB90: lw          $s1, 0x28($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X28);
    // 0x8007BB94: lw          $t6, 0x30($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X30);
    // 0x8007BB98: ori         $fp, $fp, 0x400
    ctx->r30 = ctx->r30 | 0X400;
    // 0x8007BB9C: lui         $s6, 0xB300
    ctx->r22 = S32(0XB300 << 16);
    // 0x8007BBA0: subu        $v1, $t6, $s1
    ctx->r3 = SUB32(ctx->r14, ctx->r17);
    // 0x8007BBA4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007BBA8: blez        $v1, L_8007BE1C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007BBAC: lui         $s5, 0xB400
        ctx->r21 = S32(0XB400 << 16);
            goto L_8007BE1C;
    }
    // 0x8007BBAC: lui         $s5, 0xB400
    ctx->r21 = S32(0XB400 << 16);
    // 0x8007BBB0: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x8007BBB4: lui         $s4, 0xE400
    ctx->r20 = S32(0XE400 << 16);
L_8007BBB8:
    // 0x8007BBB8: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8007BBBC: addu        $t5, $s1, $s7
    ctx->r13 = ADD32(ctx->r17, ctx->r23);
    // 0x8007BBC0: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x8007BBC4: slt         $at, $t7, $s7
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x8007BBC8: lw          $a1, 0x24($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X24);
    // 0x8007BBCC: lw          $a2, 0x2C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X2C);
    // 0x8007BBD0: addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
    // 0x8007BBD4: andi        $t0, $t0, 0xFFF
    ctx->r8 = ctx->r8 & 0XFFF;
    // 0x8007BBD8: beq         $at, $zero, L_8007BBE4
    if (ctx->r1 == 0) {
        // 0x8007BBDC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8007BBE4;
    }
    // 0x8007BBDC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8007BBE0: or          $s7, $t7, $zero
    ctx->r23 = ctx->r15 | 0;
L_8007BBE4:
    // 0x8007BBE4: lui         $t2, 0x10
    ctx->r10 = S32(0X10 << 16);
    // 0x8007BBE8: lw          $t9, 0x14($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X14);
    // 0x8007BBEC: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x8007BBF0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8007BBF4: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x8007BBF8: sll         $t6, $t8, 21
    ctx->r14 = S32(ctx->r24 << 21);
    // 0x8007BBFC: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
    // 0x8007BC00: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007BC04: or          $t9, $t7, $t2
    ctx->r25 = ctx->r15 | ctx->r10;
    // 0x8007BC08: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x8007BC0C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8007BC10: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8007BC14: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007BC18: lw          $t6, 0x10($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X10);
    // 0x8007BC1C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BC20: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8007BC24: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007BC28: lw          $t9, 0x14($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X14);
    // 0x8007BC2C: subu        $a3, $a2, $a1
    ctx->r7 = SUB32(ctx->r6, ctx->r5);
    // 0x8007BC30: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x8007BC34: andi        $t7, $t9, 0x7
    ctx->r15 = ctx->r25 & 0X7;
    // 0x8007BC38: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x8007BC3C: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    // 0x8007BC40: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x8007BC44: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8007BC48: sra         $a3, $a3, 3
    ctx->r7 = S32(SIGNED(ctx->r7) >> 3);
    // 0x8007BC4C: andi        $a3, $a3, 0x1FF
    ctx->r7 = ctx->r7 & 0X1FF;
    // 0x8007BC50: sll         $a3, $a3, 9
    ctx->r7 = S32(ctx->r7 << 9);
    // 0x8007BC54: or          $t9, $t6, $t2
    ctx->r25 = ctx->r14 | ctx->r10;
    // 0x8007BC58: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x8007BC5C: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8007BC60: or          $t7, $t9, $a3
    ctx->r15 = ctx->r25 | ctx->r7;
    // 0x8007BC64: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007BC68: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007BC6C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BC70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007BC74: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007BC78: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BC7C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007BC80: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BC84: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8007BC88: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8007BC8C: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8007BC90: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8007BC94: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8007BC98: andi        $t2, $t2, 0xFFF
    ctx->r10 = ctx->r10 & 0XFFF;
    // 0x8007BC9C: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007BCA0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007BCA4: sll         $t2, $t2, 12
    ctx->r10 = S32(ctx->r10 << 12);
    // 0x8007BCA8: or          $t1, $s0, $zero
    ctx->r9 = ctx->r16 | 0;
    // 0x8007BCAC: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8007BCB0: andi        $t3, $t3, 0xFFF
    ctx->r11 = ctx->r11 & 0XFFF;
    // 0x8007BCB4: or          $t8, $t2, $at
    ctx->r24 = ctx->r10 | ctx->r1;
    // 0x8007BCB8: or          $t6, $t8, $t3
    ctx->r14 = ctx->r24 | ctx->r11;
    // 0x8007BCBC: or          $t7, $t9, $t0
    ctx->r15 = ctx->r25 | ctx->r8;
    // 0x8007BCC0: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8007BCC4: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007BCC8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BCCC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8007BCD0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8007BCD4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007BCD8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007BCDC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BCE0: lw          $t7, 0x14($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X14);
    // 0x8007BCE4: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x8007BCE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007BCEC: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x8007BCF0: sll         $t6, $t8, 21
    ctx->r14 = S32(ctx->r24 << 21);
    // 0x8007BCF4: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8007BCF8: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x8007BCFC: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8007BD00: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x8007BD04: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8007BD08: or          $t8, $t7, $a3
    ctx->r24 = ctx->r15 | ctx->r7;
    // 0x8007BD0C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BD10: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007BD14: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BD18: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    // 0x8007BD1C: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8007BD20: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007BD24: or          $t7, $t9, $t0
    ctx->r15 = ctx->r25 | ctx->r8;
    // 0x8007BD28: or          $t8, $t2, $t3
    ctx->r24 = ctx->r10 | ctx->r11;
    // 0x8007BD2C: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x8007BD30: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8007BD34: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BD38: blezl       $s7, L_8007BE10
    if (SIGNED(ctx->r23) <= 0) {
        // 0x8007BD3C: lw          $v0, 0x4C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X4C);
            goto L_8007BE10;
    }
    goto skip_0;
    // 0x8007BD3C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    skip_0:
L_8007BD40:
    // 0x8007BD40: jal         0x80082730
    // 0x8007BD44: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    fsin(rdram, ctx);
        goto after_0;
    // 0x8007BD44: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8007BD48: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8007BD4C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8007BD50: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x8007BD54: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007BD58: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8007BD5C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8007BD60: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8007BD64: nop

    // 0x8007BD68: beql        $v1, $zero, L_8007BE00
    if (ctx->r3 == 0) {
        // 0x8007BD6C: lwc1        $f10, 0x4($s2)
        ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
            goto L_8007BE00;
    }
    goto skip_1;
    // 0x8007BD6C: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    skip_1:
    // 0x8007BD70: lw          $a1, 0x24($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X24);
    // 0x8007BD74: lw          $a2, 0x2C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X2C);
    // 0x8007BD78: andi        $t0, $t0, 0xFFF
    ctx->r8 = ctx->r8 & 0XFFF;
    // 0x8007BD7C: addu        $a3, $a1, $v1
    ctx->r7 = ADD32(ctx->r5, ctx->r3);
    // 0x8007BD80: sll         $a3, $a3, 5
    ctx->r7 = S32(ctx->r7 << 5);
    // 0x8007BD84: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
    // 0x8007BD88: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007BD8C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8007BD90: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8007BD94: addiu       $t7, $s1, 0x1
    ctx->r15 = ADD32(ctx->r17, 0X1);
    // 0x8007BD98: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007BD9C: or          $t9, $t6, $s4
    ctx->r25 = ctx->r14 | ctx->r20;
    // 0x8007BDA0: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007BDA4: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8007BDA8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8007BDAC: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8007BDB0: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8007BDB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007BDB8: or          $t7, $t6, $t0
    ctx->r15 = ctx->r14 | ctx->r8;
    // 0x8007BDBC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007BDC0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BDC4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8007BDC8: sll         $t6, $s1, 5
    ctx->r14 = S32(ctx->r17 << 5);
    // 0x8007BDCC: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8007BDD0: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x8007BDD4: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8007BDD8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007BDDC: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8007BDE0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BDE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007BDE8: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x8007BDEC: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x8007BDF0: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007BDF4: sw          $s6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r22;
    // 0x8007BDF8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BDFC: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
L_8007BE00:
    // 0x8007BE00: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007BE04: bne         $s3, $s7, L_8007BD40
    if (ctx->r19 != ctx->r23) {
        // 0x8007BE08: add.s       $f20, $f20, $f10
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f10.fl;
            goto L_8007BD40;
    }
    // 0x8007BE08: add.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f10.fl;
    // 0x8007BE0C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8007BE10:
    // 0x8007BE10: subu        $v0, $v0, $s7
    ctx->r2 = SUB32(ctx->r2, ctx->r23);
    // 0x8007BE14: bgtz        $v0, L_8007BBB8
    if (SIGNED(ctx->r2) > 0) {
        // 0x8007BE18: sw          $v0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r2;
            goto L_8007BBB8;
    }
    // 0x8007BE18: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
L_8007BE1C:
    // 0x8007BE1C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8007BE20: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8007BE24: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007BE28: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BE2C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BE30: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x8007BE34: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x8007BE38: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8007BE3C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8007BE40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007BE44: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8007BE48: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8007BE4C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8007BE50: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8007BE54: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8007BE58: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8007BE5C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8007BE60: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8007BE64: jr          $ra
    // 0x8007BE68: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8007BE68: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8007BE6C: nop

;}
RECOMP_FUNC void func_8005DAA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DAA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005DAA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005DAAC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8005DAB0: lw          $t6, 0x16C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X16C);
    // 0x8005DAB4: lbu         $a0, 0x164($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X164);
    // 0x8005DAB8: lw          $a1, 0x2C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X2C);
    // 0x8005DABC: jal         0x8005DA78
    // 0x8005DAC0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8005DA78(rdram, ctx);
        goto after_0;
    // 0x8005DAC0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8005DAC4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8005DAC8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8005DACC: lw          $t8, 0x16C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X16C);
    // 0x8005DAD0: sw          $t7, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r15;
    // 0x8005DAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005DAD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005DADC: jr          $ra
    // 0x8005DAE0: nop

    return;
    // 0x8005DAE0: nop

;}
RECOMP_FUNC void func_806E5FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E5FB0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806E5FB4: sdc1        $f24, 0x10($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X10, ctx->r29);
    // 0x806E5FB8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x806E5FBC: sdc1        $f22, 0x8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X8, ctx->r29);
    // 0x806E5FC0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x806E5FC4: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x806E5FC8: sdc1        $f30, 0x28($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X28, ctx->r29);
    // 0x806E5FCC: sdc1        $f28, 0x20($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X20, ctx->r29);
    // 0x806E5FD0: sdc1        $f26, 0x18($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X18, ctx->r29);
    // 0x806E5FD4: sdc1        $f20, 0x0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X0, ctx->r29);
    // 0x806E5FD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806E5FDC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E5FE0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x806E5FE4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x806E5FE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806E5FEC: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
    // 0x806E5FF0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806E5FF4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806E5FF8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806E5FFC: lui         $s0, 0x806E
    ctx->r16 = S32(RELOC_HI16(655, 0X1060) << 16);
    // 0x806E6000: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806E6004: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x806E6008: addiu       $s0, $s0, 0x6D20
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(655, 0X1060));
    // 0x806E600C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x806E6010: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x806E6014: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x806E6018: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x806E601C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x806E6020: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x806E6024: addiu       $t0, $v0, 0x4
    ctx->r8 = ADD32(ctx->r2, 0X4);
    // 0x806E6028: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x806E602C: addiu       $a2, $a1, 0xC4
    ctx->r6 = ADD32(ctx->r5, 0XC4);
L_806E6030:
    // 0x806E6030: lw          $a1, -0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, -0X4);
    // 0x806E6034: lwc1        $f26, 0x84($a1)
    ctx->f26.u32l = MEM_W(ctx->r5, 0X84);
    // 0x806E6038: beq         $a3, $t1, L_806E6050
    if (ctx->r7 == ctx->r9) {
        // 0x806E603C: lwc1        $f16, 0x88($a1)
        ctx->f16.u32l = MEM_W(ctx->r5, 0X88);
            goto L_806E6050;
    }
    // 0x806E603C: lwc1        $f16, 0x88($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X88);
    // 0x806E6040: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x806E6044: lwc1        $f28, 0x84($a1)
    ctx->f28.u32l = MEM_W(ctx->r5, 0X84);
    // 0x806E6048: b           L_806E6074
    // 0x806E604C: lwc1        $f12, 0x88($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X88);
        goto L_806E6074;
    // 0x806E604C: lwc1        $f12, 0x88($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X88);
L_806E6050:
    // 0x806E6050: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
    // 0x806E6054: lw          $t6, 0x138($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X138);
    // 0x806E6058: lwc1        $f6, 0x84($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X84);
    // 0x806E605C: lwc1        $f8, 0x88($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X88);
    // 0x806E6060: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806E6064: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x806E6068: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x806E606C: add.s       $f12, $f8, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x806E6070: add.s       $f28, $f4, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f4.fl + ctx->f6.fl;
L_806E6074:
    // 0x806E6074: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x806E6078: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x806E607C: lwc1        $f30, 0x84($a1)
    ctx->f30.u32l = MEM_W(ctx->r5, 0X84);
    // 0x806E6080: sub.s       $f0, $f30, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f30.fl - ctx->f28.fl;
    // 0x806E6084: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806E6088: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806E608C: nop

    // 0x806E6090: bc1fl       L_806E60F0
    if (!c1cs) {
        // 0x806E6094: lw          $a1, 0x28($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X28);
            goto L_806E60F0;
    }
    goto skip_0;
    // 0x806E6094: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
    skip_0:
    // 0x806E6098: c.lt.s      $f30, $f28
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f30.fl < ctx->f28.fl;
    // 0x806E609C: nop

    // 0x806E60A0: bc1fl       L_806E60D0
    if (!c1cs) {
        // 0x806E60A4: sub.s       $f8, $f26, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f26.fl - ctx->f14.fl;
            goto L_806E60D0;
    }
    goto skip_1;
    // 0x806E60A4: sub.s       $f8, $f26, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f26.fl - ctx->f14.fl;
    skip_1:
    // 0x806E60A8: add.s       $f10, $f26, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f26.fl + ctx->f14.fl;
    // 0x806E60AC: c.lt.s      $f30, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f30.fl < ctx->f10.fl;
    // 0x806E60B0: nop

    // 0x806E60B4: bc1fl       L_806E60F0
    if (!c1cs) {
        // 0x806E60B8: lw          $a1, 0x28($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X28);
            goto L_806E60F0;
    }
    goto skip_2;
    // 0x806E60B8: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
    skip_2:
    // 0x806E60BC: lwc1        $f4, 0x3C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x806E60C0: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x806E60C4: b           L_806E60EC
    // 0x806E60C8: swc1        $f6, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f6.u32l;
        goto L_806E60EC;
    // 0x806E60C8: swc1        $f6, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f6.u32l;
    // 0x806E60CC: sub.s       $f8, $f26, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f26.fl - ctx->f14.fl;
L_806E60D0:
    // 0x806E60D0: c.lt.s      $f8, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f8.fl < ctx->f30.fl;
    // 0x806E60D4: nop

    // 0x806E60D8: bc1fl       L_806E60F0
    if (!c1cs) {
        // 0x806E60DC: lw          $a1, 0x28($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X28);
            goto L_806E60F0;
    }
    goto skip_3;
    // 0x806E60DC: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
    skip_3:
    // 0x806E60E0: lwc1        $f10, 0x3C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x806E60E4: sub.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x806E60E8: swc1        $f4, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f4.u32l;
L_806E60EC:
    // 0x806E60EC: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
L_806E60F0:
    // 0x806E60F0: lwc1        $f28, 0x3C($a0)
    ctx->f28.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806E60F4: lwc1        $f26, 0x84($a1)
    ctx->f26.u32l = MEM_W(ctx->r5, 0X84);
    // 0x806E60F8: sub.s       $f0, $f26, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f28.fl;
    // 0x806E60FC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806E6100: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x806E6104: nop

    // 0x806E6108: bc1fl       L_806E6190
    if (!c1cs) {
        // 0x806E610C: lw          $a1, 0x0($t0)
        ctx->r5 = MEM_W(ctx->r8, 0X0);
            goto L_806E6190;
    }
    goto skip_4;
    // 0x806E610C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    skip_4:
    // 0x806E6110: lw          $t9, 0x40($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X40);
    // 0x806E6114: bnel        $t9, $zero, L_806E6190
    if (ctx->r25 != 0) {
        // 0x806E6118: lw          $a1, 0x0($t0)
        ctx->r5 = MEM_W(ctx->r8, 0X0);
            goto L_806E6190;
    }
    goto skip_5;
    // 0x806E6118: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    skip_5:
    // 0x806E611C: lw          $t6, 0x38($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X38);
    // 0x806E6120: bnel        $t2, $t6, L_806E6190
    if (ctx->r10 != ctx->r14) {
        // 0x806E6124: lw          $a1, 0x0($t0)
        ctx->r5 = MEM_W(ctx->r8, 0X0);
            goto L_806E6190;
    }
    goto skip_6;
    // 0x806E6124: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    skip_6:
    // 0x806E6128: c.lt.s      $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl < ctx->f26.fl;
    // 0x806E612C: nop

    // 0x806E6130: bc1fl       L_806E6150
    if (!c1cs) {
        // 0x806E6134: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_806E6150;
    }
    goto skip_7;
    // 0x806E6134: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_7:
    // 0x806E6138: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x806E613C: lwc1        $f6, 0x3C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x806E6140: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x806E6144: b           L_806E615C
    // 0x806E6148: swc1        $f8, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f8.u32l;
        goto L_806E615C;
    // 0x806E6148: swc1        $f8, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f8.u32l;
    // 0x806E614C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_806E6150:
    // 0x806E6150: lwc1        $f10, 0x3C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X3C);
    // 0x806E6154: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x806E6158: swc1        $f4, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f4.u32l;
L_806E615C:
    // 0x806E615C: lw          $t9, 0x38($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X38);
    // 0x806E6160: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x806E6164: slti        $at, $t6, 0x33
    ctx->r1 = SIGNED(ctx->r14) < 0X33 ? 1 : 0;
    // 0x806E6168: bne         $at, $zero, L_806E618C
    if (ctx->r1 != 0) {
        // 0x806E616C: sw          $t6, 0x38($v0)
        MEM_W(0X38, ctx->r2) = ctx->r14;
            goto L_806E618C;
    }
    // 0x806E616C: sw          $t6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r14;
    // 0x806E6170: swc1        $f20, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f20.u32l;
    // 0x806E6174: swc1        $f20, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f20.u32l;
    // 0x806E6178: sw          $zero, 0x38($v0)
    MEM_W(0X38, ctx->r2) = 0;
    // 0x806E617C: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x806E6180: sw          $t3, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r11;
    // 0x806E6184: sw          $t4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r12;
    // 0x806E6188: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
L_806E618C:
    // 0x806E618C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
L_806E6190:
    // 0x806E6190: lwc1        $f26, 0x88($a1)
    ctx->f26.u32l = MEM_W(ctx->r5, 0X88);
    // 0x806E6194: sub.s       $f0, $f26, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f12.fl;
    // 0x806E6198: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806E619C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806E61A0: nop

    // 0x806E61A4: bc1f        L_806E6228
    if (!c1cs) {
        // 0x806E61A8: nop
    
            goto L_806E6228;
    }
    // 0x806E61A8: nop

    // 0x806E61AC: c.lt.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl < ctx->f12.fl;
    // 0x806E61B0: nop

    // 0x806E61B4: bc1fl       L_806E620C
    if (!c1cs) {
        // 0x806E61B8: sub.s       $f8, $f16, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f14.fl;
            goto L_806E620C;
    }
    goto skip_8;
    // 0x806E61B8: sub.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f14.fl;
    skip_8:
    // 0x806E61BC: add.s       $f0, $f16, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x806E61C0: c.lt.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl < ctx->f0.fl;
    // 0x806E61C4: nop

    // 0x806E61C8: bc1fl       L_806E61E8
    if (!c1cs) {
        // 0x806E61CC: add.s       $f10, $f26, $f22
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f26.fl + ctx->f22.fl;
            goto L_806E61E8;
    }
    goto skip_9;
    // 0x806E61CC: add.s       $f10, $f26, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f26.fl + ctx->f22.fl;
    skip_9:
    // 0x806E61D0: lwc1        $f6, 0x40($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X40);
    // 0x806E61D4: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x806E61D8: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
    // 0x806E61DC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x806E61E0: lwc1        $f26, 0x88($a1)
    ctx->f26.u32l = MEM_W(ctx->r5, 0X88);
    // 0x806E61E4: add.s       $f10, $f26, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f26.fl + ctx->f22.fl;
L_806E61E8:
    // 0x806E61E8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x806E61EC: nop

    // 0x806E61F0: bc1f        L_806E6228
    if (!c1cs) {
        // 0x806E61F4: nop
    
            goto L_806E6228;
    }
    // 0x806E61F4: nop

    // 0x806E61F8: lwc1        $f4, 0x40($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X40);
    // 0x806E61FC: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x806E6200: b           L_806E6228
    // 0x806E6204: swc1        $f6, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f6.u32l;
        goto L_806E6228;
    // 0x806E6204: swc1        $f6, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f6.u32l;
    // 0x806E6208: sub.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f14.fl;
L_806E620C:
    // 0x806E620C: c.lt.s      $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f8.fl < ctx->f26.fl;
    // 0x806E6210: nop

    // 0x806E6214: bc1f        L_806E6228
    if (!c1cs) {
        // 0x806E6218: nop
    
            goto L_806E6228;
    }
    // 0x806E6218: nop

    // 0x806E621C: lwc1        $f10, 0x40($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X40);
    // 0x806E6220: sub.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x806E6224: swc1        $f4, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f4.u32l;
L_806E6228:
    // 0x806E6228: bne         $a3, $t5, L_806E6030
    if (ctx->r7 != ctx->r13) {
        // 0x806E622C: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_806E6030;
    }
    // 0x806E622C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x806E6230: ldc1        $f20, 0x0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X0);
    // 0x806E6234: ldc1        $f22, 0x8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X8);
    // 0x806E6238: ldc1        $f24, 0x10($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X10);
    // 0x806E623C: ldc1        $f26, 0x18($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X18);
    // 0x806E6240: ldc1        $f28, 0x20($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X20);
    // 0x806E6244: ldc1        $f30, 0x28($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X28);
    // 0x806E6248: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x806E624C: jr          $ra
    // 0x806E6250: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x806E6250: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_805D2D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2D20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805D2D24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D2D28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D2D2C: jal         0x8004700C
    // 0x805D2D30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805D2D30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805D2D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D2D38: jal         0x80062D14
    // 0x805D2D3C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80062D14(rdram, ctx);
        goto after_1;
    // 0x805D2D3C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x805D2D40: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x805D2D44: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x805D2D48: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x805D2D4C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x805D2D50: bne         $t7, $at, L_805D2E48
    if (ctx->r15 != ctx->r1) {
        // 0x805D2D54: sw          $t7, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r15;
            goto L_805D2E48;
    }
    // 0x805D2D54: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x805D2D58: beq         $v1, $zero, L_805D2D80
    if (ctx->r3 == 0) {
        // 0x805D2D5C: sw          $zero, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = 0;
            goto L_805D2D80;
    }
    // 0x805D2D5C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x805D2D60: lw          $t9, 0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X34);
    // 0x805D2D64: slti        $at, $t9, 0xA0
    ctx->r1 = SIGNED(ctx->r25) < 0XA0 ? 1 : 0;
    // 0x805D2D68: beq         $at, $zero, L_805D2D78
    if (ctx->r1 == 0) {
        // 0x805D2D6C: nop
    
            goto L_805D2D78;
    }
    // 0x805D2D6C: nop

    // 0x805D2D70: b           L_805D2D8C
    // 0x805D2D74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_805D2D8C;
    // 0x805D2D74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_805D2D78:
    // 0x805D2D78: b           L_805D2D8C
    // 0x805D2D7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_805D2D8C;
    // 0x805D2D7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_805D2D80:
    // 0x805D2D80: jal         0x800653D8
    // 0x805D2D84: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x805D2D84: nop

    after_2:
    // 0x805D2D88: andi        $a1, $v0, 0x1
    ctx->r5 = ctx->r2 & 0X1;
L_805D2D8C:
    // 0x805D2D8C: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x805D2D90: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x805D2D94: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805D2D98: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x805D2D9C: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x805D2DA0: lw          $t9, 0x94($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X94);
    // 0x805D2DA4: jalr        $t9
    // 0x805D2DA8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x805D2DA8: nop

    after_3:
    // 0x805D2DAC: beq         $v0, $zero, L_805D2E48
    if (ctx->r2 == 0) {
        // 0x805D2DB0: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_805D2E48;
    }
    // 0x805D2DB0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x805D2DB4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x805D2DB8: jal         0x800653D8
    // 0x805D2DBC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x805D2DBC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_4:
    // 0x805D2DC0: andi        $t2, $v0, 0xF
    ctx->r10 = ctx->r2 & 0XF;
    // 0x805D2DC4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x805D2DC8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x805D2DCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805D2DD0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805D2DD4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x805D2DD8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805D2DDC: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805D2DE0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x805D2DE4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x805D2DE8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805D2DEC: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x805D2DF0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x805D2DF4: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x805D2DF8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805D2DFC: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x805D2E00: beq         $a1, $zero, L_805D2E2C
    if (ctx->r5 == 0) {
        // 0x805D2E04: swc1        $f0, 0x40($v1)
        MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
            goto L_805D2E2C;
    }
    // 0x805D2E04: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x805D2E08: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x805D2E0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805D2E10: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805D2E14: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x805D2E18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805D2E1C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805D2E20: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x805D2E24: b           L_805D2E48
    // 0x805D2E28: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
        goto L_805D2E48;
    // 0x805D2E28: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
L_805D2E2C:
    // 0x805D2E2C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805D2E30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805D2E34: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x805D2E38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805D2E3C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x805D2E40: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805D2E44: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
L_805D2E48:
    // 0x805D2E48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805D2E4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D2E50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805D2E54: jr          $ra
    // 0x805D2E58: nop

    return;
    // 0x805D2E58: nop

;}
RECOMP_FUNC void func_800505F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800505F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800505F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800505F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800505FC: addiu       $a0, $a0, -0x6150
    ctx->r4 = ADD32(ctx->r4, -0X6150);
    // 0x80050600: addiu       $a1, $zero, 0x708
    ctx->r5 = ADD32(0, 0X708);
    // 0x80050604: jal         0x80065728
    // 0x80050608: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80050608: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8005060C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80050610: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80050614: addiu       $a1, $a1, -0x5A30
    ctx->r5 = ADD32(ctx->r5, -0X5A30);
    // 0x80050618: addiu       $a0, $a0, -0x5A48
    ctx->r4 = ADD32(ctx->r4, -0X5A48);
    // 0x8005061C: jal         0x80058110
    // 0x80050620: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    func_80058110(rdram, ctx);
        goto after_1;
    // 0x80050620: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_1:
    // 0x80050624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005062C: jr          $ra
    // 0x80050630: nop

    return;
    // 0x80050630: nop

;}
RECOMP_FUNC void func_80050970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050978: jal         0x800506B4
    // 0x8005097C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800506B4(rdram, ctx);
        goto after_0;
    // 0x8005097C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80050980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050984: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80050988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005098C: jr          $ra
    // 0x80050990: nop

    return;
    // 0x80050990: nop

;}
RECOMP_FUNC void func_80430D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430D3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80430D40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80430D44: jal         0x80430BE8
    // 0x80430D48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80430BE8(rdram, ctx);
        goto after_0;
    // 0x80430D48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80430D4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80430D50: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80430D54: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430D58: lh          $v1, 0x1C($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X1C);
    // 0x80430D5C: bne         $v1, $zero, L_80430D88
    if (ctx->r3 != 0) {
        // 0x80430D60: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_80430D88;
    }
    // 0x80430D60: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80430D64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80430D68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80430D6C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80430D70: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x80430D74: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430D78: jal         0x804311BC
    // 0x80430D7C: lw          $a3, 0x20($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X20);
    func_804311BC(rdram, ctx);
        goto after_1;
    // 0x80430D7C: lw          $a3, 0x20($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X20);
    after_1:
    // 0x80430D80: b           L_80430D90
    // 0x80430D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80430D90;
    // 0x80430D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80430D88:
    // 0x80430D88: sh          $t7, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r15;
    // 0x80430D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80430D90:
    // 0x80430D90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80430D94: jr          $ra
    // 0x80430D98: nop

    return;
    // 0x80430D98: nop

;}
RECOMP_FUNC void func_80475BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475BBC: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80475BC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80475BC4: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80475BC8: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x80475BCC: lw          $v1, 0x14($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X14);
    // 0x80475BD0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80475BD4: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80475BD8: lw          $t7, 0x6D10($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D10);
    // 0x80475BDC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80475BE0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80475BE4: beq         $a3, $t7, L_80475BF0
    if (ctx->r7 == ctx->r15) {
        // 0x80475BE8: lw          $t6, 0x0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X0);
            goto L_80475BF0;
    }
    // 0x80475BE8: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x80475BEC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80475BF0:
    // 0x80475BF0: lhu         $t8, 0x13B4($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X13B4);
    // 0x80475BF4: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x80475BF8: beq         $t9, $zero, L_80475C04
    if (ctx->r25 == 0) {
        // 0x80475BFC: lui         $t8, 0x600
        ctx->r24 = S32(0X600 << 16);
            goto L_80475C04;
    }
    // 0x80475BFC: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80475C00: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
L_80475C04:
    // 0x80475C04: lw          $t1, 0xFB8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XFB8);
    // 0x80475C08: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80475C0C: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x80475C10: bnel        $t3, $zero, L_80475C20
    if (ctx->r11 != 0) {
        // 0x80475C14: sll         $t4, $t0, 2
        ctx->r12 = S32(ctx->r8 << 2);
            goto L_80475C20;
    }
    goto skip_0;
    // 0x80475C14: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    skip_0:
    // 0x80475C18: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80475C1C: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
L_80475C20:
    // 0x80475C20: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80475C24: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x80475C28: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x80475C2C: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80475C30: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80475C34: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80475C38: addu        $t1, $v1, $t9
    ctx->r9 = ADD32(ctx->r3, ctx->r25);
    // 0x80475C3C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80475C40: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80475C44: jr          $ra
    // 0x80475C48: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    return;
    // 0x80475C48: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
;}
RECOMP_FUNC void func_8073A194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073A194: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073A198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073A19C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8073A1A0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8073A1A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8073A1A8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8073A1AC: jal         0x80739A40
    // 0x8073A1B0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_80739A40(rdram, ctx);
        goto after_0;
    // 0x8073A1B0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8073A1B4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8073A1B8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8073A1BC: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8073A1C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073A1C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073A1C8: jr          $ra
    // 0x8073A1CC: nop

    return;
    // 0x8073A1CC: nop

;}
RECOMP_FUNC void func_8004F79C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F79C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8004F7A0: lbu         $t7, 0x3C($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3C);
    // 0x8004F7A4: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8004F7A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8004F7AC: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8004F7B0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8004F7B4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8004F7B8: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8004F7BC: jr          $ra
    // 0x8004F7C0: lbu         $v0, 0x1024($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1024);
    return;
    // 0x8004F7C0: lbu         $v0, 0x1024($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1024);
;}
RECOMP_FUNC void func_80046F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046F80: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x80046F84: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x80046F88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80046F8C: bne         $t6, $t7, L_80046FB4
    if (ctx->r14 != ctx->r15) {
        // 0x80046F90: nop
    
            goto L_80046FB4;
    }
    // 0x80046F90: nop

    // 0x80046F94: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x80046F98: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80046F9C: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x80046FA0: andi        $t1, $t0, 0x3FF
    ctx->r9 = ctx->r8 & 0X3FF;
    // 0x80046FA4: bne         $t9, $t1, L_80046FB4
    if (ctx->r25 != ctx->r9) {
        // 0x80046FA8: nop
    
            goto L_80046FB4;
    }
    // 0x80046FA8: nop

    // 0x80046FAC: jr          $ra
    // 0x80046FB0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80046FB0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80046FB4:
    // 0x80046FB4: jr          $ra
    // 0x80046FB8: nop

    return;
    // 0x80046FB8: nop

;}
RECOMP_FUNC void func_8040A470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040A470: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040A474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040A478: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040A47C: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x8040A480: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8040A484: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8040A488: jal         0x800592AC
    // 0x8040A48C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_800592AC(rdram, ctx);
        goto after_0;
    // 0x8040A48C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
    // 0x8040A490: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8040A494: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8040A498: bne         $v0, $zero, L_8040A4C0
    if (ctx->r2 != 0) {
        // 0x8040A49C: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_8040A4C0;
    }
    // 0x8040A49C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8040A4A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8040A4A4: sw          $zero, 0x28($t0)
    MEM_W(0X28, ctx->r8) = 0;
    // 0x8040A4A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040A4AC: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x8040A4B0: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x8040A4B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8040A4B8: jal         0x8040818C
    // 0x8040A4BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8040818C(rdram, ctx);
        goto after_1;
    // 0x8040A4BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_8040A4C0:
    // 0x8040A4C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040A4C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8040A4C8: jr          $ra
    // 0x8040A4CC: nop

    return;
    // 0x8040A4CC: nop

;}
RECOMP_FUNC void func_8003B9D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B9D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B9DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B9E0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8003B9E4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x8003B9E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B9EC: jal         0x80067E78
    // 0x8003B9F0: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    func_80067E78(rdram, ctx);
        goto after_0;
    // 0x8003B9F0: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    after_0:
    // 0x8003B9F4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8003B9F8: jal         0x80067818
    // 0x8003B9FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8003B9FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8003BA00: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8003BA04: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003BA08: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003BA0C: jal         0x8003B8F0
    // 0x8003BA10: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8003B8F0(rdram, ctx);
        goto after_2;
    // 0x8003BA10: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8003BA14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BA18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003BA1C: jr          $ra
    // 0x8003BA20: nop

    return;
    // 0x8003BA20: nop

;}
RECOMP_FUNC void func_80409928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409928: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8040992C: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80409930: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80409934: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80409938: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8040993C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80409940: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
L_80409944:
    // 0x80409944: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80409948: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8040994C: bne         $t6, $zero, L_804099B4
    if (ctx->r14 != 0) {
        // 0x80409950: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_804099B4;
    }
    // 0x80409950: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80409954: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80409958: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8040995C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80409960: lui         $t9, 0x8041
    ctx->r25 = S32(RELOC_HI16(11, 0X1E88) << 16);
    // 0x80409964: lui         $t0, 0x8041
    ctx->r8 = S32(RELOC_HI16(11, 0X110C) << 16);
    // 0x80409968: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8040996C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80409970: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80409974: addiu       $t9, $t9, -0x67A8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(11, 0X1E88));
    // 0x80409978: addiu       $t0, $t0, -0x7524
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(11, 0X110C));
    // 0x8040997C: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80409980: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x80409984: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80409988: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x8040998C: sw          $t7, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r15;
    // 0x80409990: sw          $v1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r3;
    // 0x80409994: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80409998: sw          $v1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r3;
    // 0x8040999C: sw          $t9, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r25;
    // 0x804099A0: sw          $t0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r8;
    // 0x804099A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804099A8: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x804099AC: b           L_80409B10
    // 0x804099B0: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
        goto L_80409B10;
    // 0x804099B0: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_804099B4:
    // 0x804099B4: lw          $t1, 0x58($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X58);
    // 0x804099B8: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x804099BC: bne         $t1, $zero, L_80409A24
    if (ctx->r9 != 0) {
        // 0x804099C0: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80409A24;
    }
    // 0x804099C0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x804099C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804099C8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x804099CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804099D0: lui         $t4, 0x8041
    ctx->r12 = S32(RELOC_HI16(11, 0X1E88) << 16);
    // 0x804099D4: lui         $t5, 0x8041
    ctx->r13 = S32(RELOC_HI16(11, 0X110C) << 16);
    // 0x804099D8: addiu       $t5, $t5, -0x7524
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(11, 0X110C));
    // 0x804099DC: addiu       $t4, $t4, -0x67A8
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(11, 0X1E88));
    // 0x804099E0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x804099E4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x804099E8: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x804099EC: sw          $t3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r11;
    // 0x804099F0: sw          $t2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r10;
    // 0x804099F4: sw          $v1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r3;
    // 0x804099F8: sw          $v1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r3;
    // 0x804099FC: sw          $t4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r12;
    // 0x80409A00: sw          $t5, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r13;
    // 0x80409A04: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80409A08: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x80409A0C: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80409A10: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80409A14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80409A18: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80409A1C: b           L_80409B10
    // 0x80409A20: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
        goto L_80409B10;
    // 0x80409A20: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
L_80409A24:
    // 0x80409A24: lw          $t6, 0x58($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X58);
    // 0x80409A28: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80409A2C: bne         $t6, $zero, L_80409A94
    if (ctx->r14 != 0) {
        // 0x80409A30: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80409A94;
    }
    // 0x80409A30: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80409A34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80409A38: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80409A3C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80409A40: lui         $t9, 0x8041
    ctx->r25 = S32(RELOC_HI16(11, 0X1E88) << 16);
    // 0x80409A44: lui         $t0, 0x8041
    ctx->r8 = S32(RELOC_HI16(11, 0X110C) << 16);
    // 0x80409A48: addiu       $t0, $t0, -0x7524
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(11, 0X110C));
    // 0x80409A4C: addiu       $t9, $t9, -0x67A8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(11, 0X1E88));
    // 0x80409A50: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80409A54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80409A58: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80409A5C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80409A60: sw          $t7, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r15;
    // 0x80409A64: sw          $v1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r3;
    // 0x80409A68: sw          $v1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r3;
    // 0x80409A6C: sw          $t9, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r25;
    // 0x80409A70: sw          $t0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r8;
    // 0x80409A74: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80409A78: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x80409A7C: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80409A80: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80409A84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80409A88: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x80409A8C: b           L_80409B10
    // 0x80409A90: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
        goto L_80409B10;
    // 0x80409A90: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
L_80409A94:
    // 0x80409A94: lw          $t1, 0x58($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X58);
    // 0x80409A98: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80409A9C: bne         $t1, $zero, L_80409B04
    if (ctx->r9 != 0) {
        // 0x80409AA0: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80409B04;
    }
    // 0x80409AA0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80409AA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80409AA8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80409AAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80409AB0: lui         $t4, 0x8041
    ctx->r12 = S32(RELOC_HI16(11, 0X1E88) << 16);
    // 0x80409AB4: lui         $t5, 0x8041
    ctx->r13 = S32(RELOC_HI16(11, 0X110C) << 16);
    // 0x80409AB8: addiu       $t5, $t5, -0x7524
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(11, 0X110C));
    // 0x80409ABC: addiu       $t4, $t4, -0x67A8
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(11, 0X1E88));
    // 0x80409AC0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80409AC4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80409AC8: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x80409ACC: sw          $t3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r11;
    // 0x80409AD0: sw          $t2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r10;
    // 0x80409AD4: sw          $v1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r3;
    // 0x80409AD8: sw          $v1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r3;
    // 0x80409ADC: sw          $t4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r12;
    // 0x80409AE0: sw          $t5, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r13;
    // 0x80409AE4: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80409AE8: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x80409AEC: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80409AF0: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80409AF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80409AF8: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80409AFC: b           L_80409B10
    // 0x80409B00: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
        goto L_80409B10;
    // 0x80409B00: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_80409B04:
    // 0x80409B04: bne         $v0, $v1, L_80409944
    if (ctx->r2 != ctx->r3) {
        // 0x80409B08: addiu       $a0, $a0, 0x30
        ctx->r4 = ADD32(ctx->r4, 0X30);
            goto L_80409944;
    }
    // 0x80409B08: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80409B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80409B10:
    // 0x80409B10: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x80409B14: jr          $ra
    // 0x80409B18: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80409B18: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800036F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800036F0: addiu       $v0, $a1, 0xF
    ctx->r2 = ADD32(ctx->r5, 0XF);
    // 0x800036F4: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800036F8: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x800036FC: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x80003700: subu        $t7, $a2, $t6
    ctx->r15 = SUB32(ctx->r6, ctx->r14);
    // 0x80003704: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80003708: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8000370C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x80003710: jr          $ra
    // 0x80003714: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    return;
    // 0x80003714: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
;}
RECOMP_FUNC void func_8079AC9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079AC9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079ACA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079ACA4: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8079ACA8: slti        $at, $v0, 0x471D
    ctx->r1 = SIGNED(ctx->r2) < 0X471D ? 1 : 0;
    // 0x8079ACAC: bne         $at, $zero, L_8079ACCC
    if (ctx->r1 != 0) {
        // 0x8079ACB0: addiu       $at, $zero, 0x471D
        ctx->r1 = ADD32(0, 0X471D);
            goto L_8079ACCC;
    }
    // 0x8079ACB0: addiu       $at, $zero, 0x471D
    ctx->r1 = ADD32(0, 0X471D);
    // 0x8079ACB4: beq         $v0, $at, L_8079AD28
    if (ctx->r2 == ctx->r1) {
        // 0x8079ACB8: addiu       $at, $zero, 0x471E
        ctx->r1 = ADD32(0, 0X471E);
            goto L_8079AD28;
    }
    // 0x8079ACB8: addiu       $at, $zero, 0x471E
    ctx->r1 = ADD32(0, 0X471E);
    // 0x8079ACBC: beql        $v0, $at, L_8079AD2C
    if (ctx->r2 == ctx->r1) {
        // 0x8079ACC0: lbu         $t7, 0xE($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0XE);
            goto L_8079AD2C;
    }
    goto skip_0;
    // 0x8079ACC0: lbu         $t7, 0xE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XE);
    skip_0:
    // 0x8079ACC4: b           L_8079AD78
    // 0x8079ACC8: lbu         $t6, 0xE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XE);
        goto L_8079AD78;
    // 0x8079ACC8: lbu         $t6, 0xE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XE);
L_8079ACCC:
    // 0x8079ACCC: slti        $at, $v0, 0x46E2
    ctx->r1 = SIGNED(ctx->r2) < 0X46E2 ? 1 : 0;
    // 0x8079ACD0: bne         $at, $zero, L_8079ACE8
    if (ctx->r1 != 0) {
        // 0x8079ACD4: addiu       $at, $zero, 0x471C
        ctx->r1 = ADD32(0, 0X471C);
            goto L_8079ACE8;
    }
    // 0x8079ACD4: addiu       $at, $zero, 0x471C
    ctx->r1 = ADD32(0, 0X471C);
    // 0x8079ACD8: beql        $v0, $at, L_8079AD2C
    if (ctx->r2 == ctx->r1) {
        // 0x8079ACDC: lbu         $t7, 0xE($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0XE);
            goto L_8079AD2C;
    }
    goto skip_1;
    // 0x8079ACDC: lbu         $t7, 0xE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XE);
    skip_1:
    // 0x8079ACE0: b           L_8079AD78
    // 0x8079ACE4: lbu         $t6, 0xE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XE);
        goto L_8079AD78;
    // 0x8079ACE4: lbu         $t6, 0xE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XE);
L_8079ACE8:
    // 0x8079ACE8: slti        $at, $v0, 0x46B9
    ctx->r1 = SIGNED(ctx->r2) < 0X46B9 ? 1 : 0;
    // 0x8079ACEC: bne         $at, $zero, L_8079AD08
    if (ctx->r1 != 0) {
        // 0x8079ACF0: addiu       $t6, $v0, -0x46B4
        ctx->r14 = ADD32(ctx->r2, -0X46B4);
            goto L_8079AD08;
    }
    // 0x8079ACF0: addiu       $t6, $v0, -0x46B4
    ctx->r14 = ADD32(ctx->r2, -0X46B4);
    // 0x8079ACF4: addiu       $at, $zero, 0x46E1
    ctx->r1 = ADD32(0, 0X46E1);
    // 0x8079ACF8: beql        $v0, $at, L_8079AD2C
    if (ctx->r2 == ctx->r1) {
        // 0x8079ACFC: lbu         $t7, 0xE($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0XE);
            goto L_8079AD2C;
    }
    goto skip_2;
    // 0x8079ACFC: lbu         $t7, 0xE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XE);
    skip_2:
    // 0x8079AD00: b           L_8079AD78
    // 0x8079AD04: lbu         $t6, 0xE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XE);
        goto L_8079AD78;
    // 0x8079AD04: lbu         $t6, 0xE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XE);
L_8079AD08:
    // 0x8079AD08: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x8079AD0C: beq         $at, $zero, L_8079AD74
    if (ctx->r1 == 0) {
        // 0x8079AD10: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8079AD74;
    }
    // 0x8079AD10: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8079AD14: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X2748) << 16);
    // 0x8079AD18: addu        $at, $at, $t6
    gpr jr_addend_8079AD20 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8079AD1C: lw          $t6, -0x4D98($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(826, 0X2748));
    // 0x8079AD20: jr          $t6
    // 0x8079AD24: nop

    switch (jr_addend_8079AD20 >> 2) {
        case 0: goto L_8079AD28; break;
        case 1: goto L_8079AD28; break;
        case 2: goto L_8079AD28; break;
        case 3: goto L_8079AD28; break;
        case 4: goto L_8079AD3C; break;
        default: switch_error(__func__, 0x8079AD20, 0x8079B268);
    }
    // 0x8079AD24: nop

L_8079AD28:
    // 0x8079AD28: lbu         $t7, 0xE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XE);
L_8079AD2C:
    // 0x8079AD2C: andi        $t8, $t7, 0xFF03
    ctx->r24 = ctx->r15 & 0XFF03;
    // 0x8079AD30: ori         $t9, $t8, 0x18
    ctx->r25 = ctx->r24 | 0X18;
    // 0x8079AD34: b           L_8079AD84
    // 0x8079AD38: sb          $t9, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r25;
        goto L_8079AD84;
    // 0x8079AD38: sb          $t9, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r25;
L_8079AD3C:
    // 0x8079AD3C: jal         0x80058A14
    // 0x8079AD40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80058A14(rdram, ctx);
        goto after_0;
    // 0x8079AD40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8079AD44: beq         $v0, $zero, L_8079AD60
    if (ctx->r2 == 0) {
        // 0x8079AD48: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8079AD60;
    }
    // 0x8079AD48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8079AD4C: lbu         $t0, 0xE($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XE);
    // 0x8079AD50: andi        $t1, $t0, 0xFF03
    ctx->r9 = ctx->r8 & 0XFF03;
    // 0x8079AD54: ori         $t2, $t1, 0x18
    ctx->r10 = ctx->r9 | 0X18;
    // 0x8079AD58: b           L_8079AD84
    // 0x8079AD5C: sb          $t2, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r10;
        goto L_8079AD84;
    // 0x8079AD5C: sb          $t2, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r10;
L_8079AD60:
    // 0x8079AD60: lbu         $t3, 0xE($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XE);
    // 0x8079AD64: andi        $t4, $t3, 0xFF03
    ctx->r12 = ctx->r11 & 0XFF03;
    // 0x8079AD68: ori         $t5, $t4, 0x44
    ctx->r13 = ctx->r12 | 0X44;
    // 0x8079AD6C: b           L_8079AD84
    // 0x8079AD70: sb          $t5, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r13;
        goto L_8079AD84;
    // 0x8079AD70: sb          $t5, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r13;
L_8079AD74:
    // 0x8079AD74: lbu         $t6, 0xE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XE);
L_8079AD78:
    // 0x8079AD78: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x8079AD7C: ori         $t8, $t7, 0x44
    ctx->r24 = ctx->r15 | 0X44;
    // 0x8079AD80: sb          $t8, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r24;
L_8079AD84:
    // 0x8079AD84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079AD88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079AD8C: jr          $ra
    // 0x8079AD90: nop

    return;
    // 0x8079AD90: nop

;}
RECOMP_FUNC void func_8078F6A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F6A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078F6A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078F6AC: lbu         $t6, 0xF5($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XF5);
    // 0x8078F6B0: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // 0x8078F6B4: beql        $t6, $zero, L_8078F6D8
    if (ctx->r14 == 0) {
        // 0x8078F6B8: sh          $zero, 0x144($a0)
        MEM_H(0X144, ctx->r4) = 0;
            goto L_8078F6D8;
    }
    goto skip_0;
    // 0x8078F6B8: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    skip_0:
    // 0x8078F6BC: jal         0x8078F524
    // 0x8078F6C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8078F524(rdram, ctx);
        goto after_0;
    // 0x8078F6C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8078F6C4: jal         0x8078F304
    // 0x8078F6C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8078F304(rdram, ctx);
        goto after_1;
    // 0x8078F6C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8078F6CC: b           L_8078F6DC
    // 0x8078F6D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078F6DC;
    // 0x8078F6D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078F6D4: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
L_8078F6D8:
    // 0x8078F6D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078F6DC:
    // 0x8078F6DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078F6E0: jr          $ra
    // 0x8078F6E4: nop

    return;
    // 0x8078F6E4: nop

;}
RECOMP_FUNC void func_8058481C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058481C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584820: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584824: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584828: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058482C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584830: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584834: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584838: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058483C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584840: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584844: jr          $ra
    // 0x80584848: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584848: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8002EFF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EFF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002EFFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002F000: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002F004: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F008: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x8002F00C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002F010: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8002F014: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8002F018: addiu       $t8, $t8, -0x3F24
    ctx->r24 = ADD32(ctx->r24, -0X3F24);
    // 0x8002F01C: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
    // 0x8002F020: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8002F024: lbu         $t9, 0x155($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X155);
    // 0x8002F028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002F02C: sw          $zero, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = 0;
    // 0x8002F030: beq         $t9, $zero, L_8002F054
    if (ctx->r25 == 0) {
        // 0x8002F034: addiu       $a1, $v0, 0x80
        ctx->r5 = ADD32(ctx->r2, 0X80);
            goto L_8002F054;
    }
    // 0x8002F034: addiu       $a1, $v0, 0x80
    ctx->r5 = ADD32(ctx->r2, 0X80);
    // 0x8002F038: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8002F03C: addiu       $a2, $a2, -0x30CC
    ctx->r6 = ADD32(ctx->r6, -0X30CC);
    // 0x8002F040: addiu       $a1, $v0, 0x80
    ctx->r5 = ADD32(ctx->r2, 0X80);
    // 0x8002F044: jal         0x800280F4
    // 0x8002F048: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800280F4(rdram, ctx);
        goto after_0;
    // 0x8002F048: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002F04C: b           L_8002F06C
    // 0x8002F050: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_8002F06C;
    // 0x8002F050: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_8002F054:
    // 0x8002F054: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8002F058: addiu       $a2, $a2, -0x30CC
    ctx->r6 = ADD32(ctx->r6, -0X30CC);
    // 0x8002F05C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002F060: jal         0x800280F4
    // 0x8002F064: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800280F4(rdram, ctx);
        goto after_1;
    // 0x8002F064: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8002F068: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_8002F06C:
    // 0x8002F06C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002F070: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x8002F074: sb          $zero, 0x21($v0)
    MEM_B(0X21, ctx->r2) = 0;
    // 0x8002F078: lw          $v1, 0xF10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XF10);
    // 0x8002F07C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8002F080: beq         $v1, $at, L_8002F090
    if (ctx->r3 == ctx->r1) {
        // 0x8002F084: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8002F090;
    }
    // 0x8002F084: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8002F088: bne         $v1, $at, L_8002F0C8
    if (ctx->r3 != ctx->r1) {
        // 0x8002F08C: nop
    
            goto L_8002F0C8;
    }
    // 0x8002F08C: nop

L_8002F090:
    // 0x8002F090: lw          $t0, 0xAA4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XAA4);
    // 0x8002F094: beq         $t0, $zero, L_8002F0C8
    if (ctx->r8 == 0) {
        // 0x8002F098: nop
    
            goto L_8002F0C8;
    }
    // 0x8002F098: nop

    // 0x8002F09C: jal         0x8001D770
    // 0x8002F0A0: nop

    func_8001D770(rdram, ctx);
        goto after_2;
    // 0x8002F0A0: nop

    after_2:
    // 0x8002F0A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002F0A8: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002F0AC: jal         0x80067BF8
    // 0x8002F0B0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_3;
    // 0x8002F0B0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8002F0B4: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x8002F0B8: jal         0x80067818
    // 0x8002F0BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8002F0BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8002F0C0: b           L_8002F0F0
    // 0x8002F0C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8002F0F0;
    // 0x8002F0C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002F0C8:
    // 0x8002F0C8: jal         0x8001D770
    // 0x8002F0CC: nop

    func_8001D770(rdram, ctx);
        goto after_5;
    // 0x8002F0CC: nop

    after_5:
    // 0x8002F0D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002F0D4: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002F0D8: jal         0x80067BF8
    // 0x8002F0DC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_6;
    // 0x8002F0DC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x8002F0E0: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x8002F0E4: jal         0x80067818
    // 0x8002F0E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8002F0E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8002F0EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002F0F0:
    // 0x8002F0F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002F0F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002F0F8: jr          $ra
    // 0x8002F0FC: nop

    return;
    // 0x8002F0FC: nop

    // 0x8002F100: jr          $ra
    // 0x8002F104: nop

    return;
    // 0x8002F104: nop

;}
RECOMP_FUNC void ViMode_Destroy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EABC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007EAC0: jr          $ra
    // 0x8007EAC4: nop

    return;
    // 0x8007EAC4: nop

;}
RECOMP_FUNC void func_80456F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80456F18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80456F1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80456F20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80456F24: jal         0x80456D98
    // 0x80456F28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80456D98(rdram, ctx);
        goto after_0;
    // 0x80456F28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80456F2C: jal         0x80455948
    // 0x80456F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80455948(rdram, ctx);
        goto after_1;
    // 0x80456F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80456F34: jal         0x80455770
    // 0x80456F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80455770(rdram, ctx);
        goto after_2;
    // 0x80456F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80456F3C: jal         0x80455CC0
    // 0x80456F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80455CC0(rdram, ctx);
        goto after_3;
    // 0x80456F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80456F44: jal         0x8044E684
    // 0x80456F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044E684(rdram, ctx);
        goto after_4;
    // 0x80456F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80456F4C: jal         0x8044FD5C
    // 0x80456F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044FD5C(rdram, ctx);
        goto after_5;
    // 0x80456F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80456F54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80456F58: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80456F5C: jal         0x80450490
    // 0x80456F60: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_80450490(rdram, ctx);
        goto after_6;
    // 0x80456F60: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_6:
    // 0x80456F64: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80456F68: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80456F6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80456F70: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80456F74: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80456F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456F7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80456F80: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80456F84: jal         0x80457164
    // 0x80456F88: swc1        $f4, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f4.u32l;
    func_80457164(rdram, ctx);
        goto after_7;
    // 0x80456F88: swc1        $f4, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f4.u32l;
    after_7:
    // 0x80456F8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80456F90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80456F94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80456F98: jr          $ra
    // 0x80456F9C: nop

    return;
    // 0x80456F9C: nop

;}
RECOMP_FUNC void func_80460590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460590: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80460594: addiu       $at, $zero, 0x410E
    ctx->r1 = ADD32(0, 0X410E);
    // 0x80460598: beq         $v0, $at, L_804605D8
    if (ctx->r2 == ctx->r1) {
        // 0x8046059C: addiu       $at, $zero, 0x410F
        ctx->r1 = ADD32(0, 0X410F);
            goto L_804605D8;
    }
    // 0x8046059C: addiu       $at, $zero, 0x410F
    ctx->r1 = ADD32(0, 0X410F);
    // 0x804605A0: beq         $v0, $at, L_804605E4
    if (ctx->r2 == ctx->r1) {
        // 0x804605A4: addiu       $at, $zero, 0x4110
        ctx->r1 = ADD32(0, 0X4110);
            goto L_804605E4;
    }
    // 0x804605A4: addiu       $at, $zero, 0x4110
    ctx->r1 = ADD32(0, 0X4110);
    // 0x804605A8: beq         $v0, $at, L_804605F0
    if (ctx->r2 == ctx->r1) {
        // 0x804605AC: addiu       $at, $zero, 0x4500
        ctx->r1 = ADD32(0, 0X4500);
            goto L_804605F0;
    }
    // 0x804605AC: addiu       $at, $zero, 0x4500
    ctx->r1 = ADD32(0, 0X4500);
    // 0x804605B0: beq         $v0, $at, L_804605FC
    if (ctx->r2 == ctx->r1) {
        // 0x804605B4: addiu       $at, $zero, 0x4501
        ctx->r1 = ADD32(0, 0X4501);
            goto L_804605FC;
    }
    // 0x804605B4: addiu       $at, $zero, 0x4501
    ctx->r1 = ADD32(0, 0X4501);
    // 0x804605B8: beq         $v0, $at, L_80460608
    if (ctx->r2 == ctx->r1) {
        // 0x804605BC: addiu       $at, $zero, 0x4502
        ctx->r1 = ADD32(0, 0X4502);
            goto L_80460608;
    }
    // 0x804605BC: addiu       $at, $zero, 0x4502
    ctx->r1 = ADD32(0, 0X4502);
    // 0x804605C0: beq         $v0, $at, L_80460620
    if (ctx->r2 == ctx->r1) {
        // 0x804605C4: addiu       $at, $zero, 0x4503
        ctx->r1 = ADD32(0, 0X4503);
            goto L_80460620;
    }
    // 0x804605C4: addiu       $at, $zero, 0x4503
    ctx->r1 = ADD32(0, 0X4503);
    // 0x804605C8: beq         $v0, $at, L_80460614
    if (ctx->r2 == ctx->r1) {
        // 0x804605CC: nop
    
            goto L_80460614;
    }
    // 0x804605CC: nop

    // 0x804605D0: b           L_8046062C
    // 0x804605D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8046062C;
    // 0x804605D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804605D8:
    // 0x804605D8: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(122, 0X7AC) << 16);
    // 0x804605DC: jr          $ra
    // 0x804605E0: addiu       $v0, $v0, 0xD3C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(122, 0X7AC));
    return;
    // 0x804605E0: addiu       $v0, $v0, 0xD3C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(122, 0X7AC));
L_804605E4:
    // 0x804605E4: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(122, 0X145C) << 16);
    // 0x804605E8: jr          $ra
    // 0x804605EC: addiu       $v0, $v0, 0x19EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(122, 0X145C));
    return;
    // 0x804605EC: addiu       $v0, $v0, 0x19EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(122, 0X145C));
L_804605F0:
    // 0x804605F0: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(122, 0X1DE4) << 16);
    // 0x804605F4: jr          $ra
    // 0x804605F8: addiu       $v0, $v0, 0x2374
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(122, 0X1DE4));
    return;
    // 0x804605F8: addiu       $v0, $v0, 0x2374
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(122, 0X1DE4));
L_804605FC:
    // 0x804605FC: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(122, 0X205C) << 16);
    // 0x80460600: jr          $ra
    // 0x80460604: addiu       $v0, $v0, 0x25EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(122, 0X205C));
    return;
    // 0x80460604: addiu       $v0, $v0, 0x25EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(122, 0X205C));
L_80460608:
    // 0x80460608: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(122, 0X22C0) << 16);
    // 0x8046060C: jr          $ra
    // 0x80460610: addiu       $v0, $v0, 0x2850
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(122, 0X22C0));
    return;
    // 0x80460610: addiu       $v0, $v0, 0x2850
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(122, 0X22C0));
L_80460614:
    // 0x80460614: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(122, 0X2C08) << 16);
    // 0x80460618: jr          $ra
    // 0x8046061C: addiu       $v0, $v0, 0x3198
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(122, 0X2C08));
    return;
    // 0x8046061C: addiu       $v0, $v0, 0x3198
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(122, 0X2C08));
L_80460620:
    // 0x80460620: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(122, 0X34EC) << 16);
    // 0x80460624: jr          $ra
    // 0x80460628: addiu       $v0, $v0, 0x3A7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(122, 0X34EC));
    return;
    // 0x80460628: addiu       $v0, $v0, 0x3A7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(122, 0X34EC));
L_8046062C:
    // 0x8046062C: jr          $ra
    // 0x80460630: nop

    return;
    // 0x80460630: nop

;}
RECOMP_FUNC void func_8052FE8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052FE8C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8052FE90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8052FE94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8052FE98: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8052FE9C: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(333, 0X2380) << 16);
    // 0x8052FEA0: addiu       $t6, $t6, 0x140
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(333, 0X2380));
    // 0x8052FEA4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8052FEA8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8052FEAC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8052FEB0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8052FEB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8052FEB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8052FEBC: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x8052FEC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8052FEC4: jal         0x805300EC
    // 0x8052FEC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805300EC(rdram, ctx);
        goto after_0;
    // 0x8052FEC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8052FECC: lw          $t4, 0x16C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X16C);
    // 0x8052FED0: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(333, 0X324) << 16);
    // 0x8052FED4: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8052FED8: addiu       $t9, $t9, -0x1F1C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(333, 0X324));
    // 0x8052FEDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052FEE0: jal         0x8052FB1C
    // 0x8052FEE4: sw          $t9, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r25;
    func_8052FB1C(rdram, ctx);
        goto after_1;
    // 0x8052FEE4: sw          $t9, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r25;
    after_1:
    // 0x8052FEE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052FEEC: jal         0x80045A34
    // 0x8052FEF0: addiu       $a1, $zero, 0x11A0
    ctx->r5 = ADD32(0, 0X11A0);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x8052FEF0: addiu       $a1, $zero, 0x11A0
    ctx->r5 = ADD32(0, 0X11A0);
    after_2:
    // 0x8052FEF4: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8052FEF8: sh          $zero, 0x119E($v0)
    MEM_H(0X119E, ctx->r2) = 0;
    // 0x8052FEFC: lhu         $v1, 0xC($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XC);
    // 0x8052FF00: addiu       $at, $zero, 0x419F
    ctx->r1 = ADD32(0, 0X419F);
    // 0x8052FF04: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8052FF08: beq         $v1, $at, L_8052FF24
    if (ctx->r3 == ctx->r1) {
        // 0x8052FF0C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8052FF24;
    }
    // 0x8052FF0C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8052FF10: addiu       $at, $zero, 0x41A1
    ctx->r1 = ADD32(0, 0X41A1);
    // 0x8052FF14: beql        $v1, $at, L_8052FF94
    if (ctx->r3 == ctx->r1) {
        // 0x8052FF18: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8052FF94;
    }
    goto skip_0;
    // 0x8052FF18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x8052FF1C: b           L_8052FFF8
    // 0x8052FF20: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
        goto L_8052FFF8;
    // 0x8052FF20: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_8052FF24:
    // 0x8052FF24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052FF28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052FF2C: lui         $at, 0x3C00
    ctx->r1 = S32(0X3C00 << 16);
    // 0x8052FF30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8052FF34: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2480) << 16);
    // 0x8052FF38: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x8052FF3C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8052FF40: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8052FF44: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8052FF48: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8052FF4C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8052FF50: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8052FF54: swc1        $f8, 0xF68($v0)
    MEM_W(0XF68, ctx->r2) = ctx->f8.u32l;
    // 0x8052FF58: lwc1        $f10, 0x240($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2480));
    // 0x8052FF5C: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2484) << 16);
    // 0x8052FF60: swc1        $f10, 0x1158($v0)
    MEM_W(0X1158, ctx->r2) = ctx->f10.u32l;
    // 0x8052FF64: lwc1        $f16, 0x244($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2484));
    // 0x8052FF68: swc1        $f16, 0x115C($v0)
    MEM_W(0X115C, ctx->r2) = ctx->f16.u32l;
    // 0x8052FF6C: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8052FF70: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8052FF74: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8052FF78: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8052FF7C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8052FF80: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8052FF84: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8052FF88: b           L_8052FFF8
    // 0x8052FF8C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
        goto L_8052FFF8;
    // 0x8052FF8C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8052FF90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8052FF94:
    // 0x8052FF94: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8052FF98: lui         $at, 0x3C00
    ctx->r1 = S32(0X3C00 << 16);
    // 0x8052FF9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052FFA0: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2488) << 16);
    // 0x8052FFA4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8052FFA8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8052FFAC: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x8052FFB0: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8052FFB4: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x8052FFB8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8052FFBC: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8052FFC0: swc1        $f6, 0xF68($v0)
    MEM_W(0XF68, ctx->r2) = ctx->f6.u32l;
    // 0x8052FFC4: lwc1        $f8, 0x248($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2488));
    // 0x8052FFC8: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X248C) << 16);
    // 0x8052FFCC: swc1        $f8, 0x1158($v0)
    MEM_W(0X1158, ctx->r2) = ctx->f8.u32l;
    // 0x8052FFD0: lwc1        $f10, 0x24C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X248C));
    // 0x8052FFD4: swc1        $f10, 0x115C($v0)
    MEM_W(0X115C, ctx->r2) = ctx->f10.u32l;
    // 0x8052FFD8: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8052FFDC: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x8052FFE0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8052FFE4: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8052FFE8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8052FFEC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8052FFF0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8052FFF4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8052FFF8:
    // 0x8052FFF8: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x8052FFFC: addiu       $t4, $zero, 0x29
    ctx->r12 = ADD32(0, 0X29);
    // 0x80530000: sw          $t9, 0x1160($v0)
    MEM_W(0X1160, ctx->r2) = ctx->r25;
    // 0x80530004: sw          $t4, 0x1164($v0)
    MEM_W(0X1164, ctx->r2) = ctx->r12;
    // 0x80530008: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8053000C: addiu       $t2, $zero, 0xF60
    ctx->r10 = ADD32(0, 0XF60);
L_80530010:
    // 0x80530010: lw          $t5, 0x1164($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1164);
    // 0x80530014: addiu       $t0, $t0, 0x520
    ctx->r8 = ADD32(ctx->r8, 0X520);
    // 0x80530018: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8053001C: blez        $t5, L_805300C8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80530020: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_805300C8;
    }
    // 0x80530020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80530024: sll         $a2, $t3, 2
    ctx->r6 = S32(ctx->r11 << 2);
    // 0x80530028: subu        $a2, $a2, $t3
    ctx->r6 = SUB32(ctx->r6, ctx->r11);
    // 0x8053002C: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x80530030: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x80530034: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x80530038: addiu       $a0, $zero, -0x1F40
    ctx->r4 = ADD32(0, -0X1F40);
    // 0x8053003C: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
L_80530040:
    // 0x80530040: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x80530044: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x80530048: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x8053004C: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x80530050: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x80530054: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80530058: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8053005C: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80530060: sb          $t6, -0x14($v1)
    MEM_B(-0X14, ctx->r3) = ctx->r14;
    // 0x80530064: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80530068: sb          $t7, -0x13($v1)
    MEM_B(-0X13, ctx->r3) = ctx->r15;
    // 0x8053006C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80530070: sb          $t8, -0x12($v1)
    MEM_B(-0X12, ctx->r3) = ctx->r24;
    // 0x80530074: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80530078: sh          $zero, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = 0;
    // 0x8053007C: sh          $zero, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = 0;
    // 0x80530080: sh          $zero, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = 0;
    // 0x80530084: sh          $zero, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = 0;
    // 0x80530088: sh          $a2, -0xE($v1)
    MEM_H(-0XE, ctx->r3) = ctx->r6;
    // 0x8053008C: sh          $a0, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = ctx->r4;
    // 0x80530090: sb          $t9, -0x11($v1)
    MEM_B(-0X11, ctx->r3) = ctx->r25;
    // 0x80530094: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80530098: addiu       $a0, $a0, 0x190
    ctx->r4 = ADD32(ctx->r4, 0X190);
    // 0x8053009C: sb          $t4, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r12;
    // 0x805300A0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x805300A4: sb          $t5, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r13;
    // 0x805300A8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x805300AC: sb          $t6, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r14;
    // 0x805300B0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x805300B4: sb          $t7, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r15;
    // 0x805300B8: lw          $t8, 0x1164($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X1164);
    // 0x805300BC: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x805300C0: bnel        $at, $zero, L_80530040
    if (ctx->r1 != 0) {
        // 0x805300C4: sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
            goto L_80530040;
    }
    goto skip_1;
    // 0x805300C4: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    skip_1:
L_805300C8:
    // 0x805300C8: bne         $t0, $t2, L_80530010
    if (ctx->r8 != ctx->r10) {
        // 0x805300CC: addiu       $t1, $t1, 0x520
        ctx->r9 = ADD32(ctx->r9, 0X520);
            goto L_80530010;
    }
    // 0x805300CC: addiu       $t1, $t1, 0x520
    ctx->r9 = ADD32(ctx->r9, 0X520);
    // 0x805300D0: jal         0x8052FAAC
    // 0x805300D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8052FAAC(rdram, ctx);
        goto after_3;
    // 0x805300D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805300D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805300DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805300E0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x805300E4: jr          $ra
    // 0x805300E8: nop

    return;
    // 0x805300E8: nop

;}
RECOMP_FUNC void func_8040EEF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EEF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040EEF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040EEF8: jal         0x8040EDB0
    // 0x8040EEFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040EDB0(rdram, ctx);
        goto after_0;
    // 0x8040EEFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040EF00: beq         $v0, $zero, L_8040EF20
    if (ctx->r2 == 0) {
        // 0x8040EF04: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8040EF20;
    }
    // 0x8040EF04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040EF08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040EF0C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8040EF10: jal         0x8040F0B8
    // 0x8040EF14: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_8040F0B8(rdram, ctx);
        goto after_1;
    // 0x8040EF14: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_1:
    // 0x8040EF18: b           L_8040EF34
    // 0x8040EF1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040EF34;
    // 0x8040EF1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040EF20:
    // 0x8040EF20: jal         0x8040EC00
    // 0x8040EF24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040EC00(rdram, ctx);
        goto after_2;
    // 0x8040EF24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8040EF28: jal         0x8040EC6C
    // 0x8040EF2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8040EC6C(rdram, ctx);
        goto after_3;
    // 0x8040EF2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8040EF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040EF34:
    // 0x8040EF34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040EF38: jr          $ra
    // 0x8040EF3C: nop

    return;
    // 0x8040EF3C: nop

;}
RECOMP_FUNC void func_806EDD74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EDD74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EDD78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EDD7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EDD80: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EDD84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EDD88: jal         0x800577D8
    // 0x806EDD8C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806EDD8C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x806EDD90: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806EDD94: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x806EDD98: jal         0x80065ABC
    // 0x806EDD9C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x806EDD9C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_1:
    // 0x806EDDA0: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806EDDA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDDA8: jal         0x80049D74
    // 0x806EDDAC: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_2;
    // 0x806EDDAC: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_2:
    // 0x806EDDB0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806EDDB4: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x806EDDB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDDBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806EDDC0: jal         0x8004D150
    // 0x806EDDC4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x806EDDC4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x806EDDC8: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x806EDDCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDDD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806EDDD4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806EDDD8: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x806EDDDC: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x806EDDE0: lbu         $t0, 0x14($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X14);
    // 0x806EDDE4: beql        $t0, $zero, L_806EDE7C
    if (ctx->r8 == 0) {
        // 0x806EDDE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EDE7C;
    }
    goto skip_0;
    // 0x806EDDE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806EDDEC: jal         0x8004D618
    // 0x806EDDF0: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x806EDDF0: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    after_4:
    // 0x806EDDF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDDF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EDDFC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806EDE00: jal         0x806EE584
    // 0x806EDE04: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_5;
    // 0x806EDE04: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
    // 0x806EDE08: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x806EDE0C: jal         0x806EBFB8
    // 0x806EDE10: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    func_806EBFB8(rdram, ctx);
        goto after_6;
    // 0x806EDE10: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    after_6:
    // 0x806EDE14: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x806EDE18: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x806EDE1C: sw          $v0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r2;
    // 0x806EDE20: lw          $v1, 0x478($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X478);
    // 0x806EDE24: addiu       $t5, $zero, 0x46
    ctx->r13 = ADD32(0, 0X46);
    // 0x806EDE28: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806EDE2C: lbu         $t1, 0xF0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XF0);
    // 0x806EDE30: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x806EDE34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806EDE38: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x806EDE3C: addiu       $t3, $t2, 0x20
    ctx->r11 = ADD32(ctx->r10, 0X20);
    // 0x806EDE40: sb          $t3, 0xF0($v1)
    MEM_B(0XF0, ctx->r3) = ctx->r11;
    // 0x806EDE44: lw          $t4, 0x478($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X478);
    // 0x806EDE48: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x806EDE4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDE50: sb          $zero, 0xF2($t4)
    MEM_B(0XF2, ctx->r12) = 0;
    // 0x806EDE54: sb          $t5, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r13;
    // 0x806EDE58: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806EDE5C: sb          $t6, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r14;
    // 0x806EDE60: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806EDE64: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
    // 0x806EDE68: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x806EDE6C: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806EDE70: jal         0x806EC098
    // 0x806EDE74: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    func_806EC098(rdram, ctx);
        goto after_7;
    // 0x806EDE74: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    after_7:
    // 0x806EDE78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EDE7C:
    // 0x806EDE7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EDE80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EDE84: jr          $ra
    // 0x806EDE88: nop

    return;
    // 0x806EDE88: nop

;}
RECOMP_FUNC void func_8078DA34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078DA34: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8078DA38: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8078DA3C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8078DA40: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8078DA44: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8078DA48: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8078DA4C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8078DA50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8078DA54: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8078DA58: lui         $t1, 0x8079
    ctx->r9 = S32(RELOC_HI16(802, 0XBC0) << 16);
    // 0x8078DA5C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8078DA60: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8078DA64: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8078DA68: lw          $t1, -0x2330($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(802, 0XBC0));
    // 0x8078DA6C: jr          $ra
    // 0x8078DA70: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8078DA70: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8078DA74: nop

    // 0x8078DA78: nop

    // 0x8078DA7C: nop

;}
RECOMP_FUNC void func_8002CEEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CEEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002CEF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CEF4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002CEF8: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002CEFC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002CF00: addiu       $t7, $t7, 0x1DE8
    ctx->r15 = ADD32(ctx->r15, 0X1DE8);
    // 0x8002CF04: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002CF08: addiu       $a1, $a1, -0x2898
    ctx->r5 = ADD32(ctx->r5, -0X2898);
    // 0x8002CF0C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8002CF10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002CF14: jal         0x80028118
    // 0x8002CF18: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002CF18: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002CF1C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8002CF20: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8002CF24: sw          $t8, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r24;
    // 0x8002CF28: jal         0x8002BB90
    // 0x8002CF2C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8002BB90(rdram, ctx);
        goto after_1;
    // 0x8002CF2C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002CF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CF34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002CF38: jr          $ra
    // 0x8002CF3C: nop

    return;
    // 0x8002CF3C: nop

;}
RECOMP_FUNC void func_806B1E3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1E3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B1E40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806B1E44: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806B1E48: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806B1E4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B1E50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806B1E54: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806B1E58: lui         $a2, 0x806B
    ctx->r6 = S32(RELOC_HI16(601, 0X1448) << 16);
    // 0x806B1E5C: lui         $a1, 0x806B
    ctx->r5 = S32(RELOC_HI16(601, 0X1468) << 16);
    // 0x806B1E60: addiu       $a1, $a1, 0x2DB8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(601, 0X1468));
    // 0x806B1E64: addiu       $a2, $a2, 0x2D98
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(601, 0X1448));
    // 0x806B1E68: jal         0x806B1A18
    // 0x806B1E6C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_806B1A18(rdram, ctx);
        goto after_0;
    // 0x806B1E6C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_0:
    // 0x806B1E70: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x806B1E74: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806B1E78: addiu       $t7, $zero, 0x1EF0
    ctx->r15 = ADD32(0, 0X1EF0);
    // 0x806B1E7C: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x806B1E80: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x806B1E84: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x806B1E88: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x806B1E8C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x806B1E90: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x806B1E94: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x806B1E98: jal         0x806B195C
    // 0x806B1E9C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_806B195C(rdram, ctx);
        goto after_1;
    // 0x806B1E9C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x806B1EA0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806B1EA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B1EA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B1EAC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B1EB0: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x806B1EB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806B1EB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B1EBC: jr          $ra
    // 0x806B1EC0: nop

    return;
    // 0x806B1EC0: nop

;}
RECOMP_FUNC void func_80678F24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80678F24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80678F28: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80678F2C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80678F30: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80678F34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80678F38: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80678F3C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80678F40: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80678F44: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x80678F48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80678F4C: sw          $zero, 0x304($a1)
    MEM_W(0X304, ctx->r5) = 0;
    // 0x80678F50: sw          $zero, 0x300($a1)
    MEM_W(0X300, ctx->r5) = 0;
    // 0x80678F54: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80678F58:
    // 0x80678F58: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80678F5C: swc1        $f0, 0x30C($v0)
    MEM_W(0X30C, ctx->r2) = ctx->f0.u32l;
    // 0x80678F60: swc1        $f0, 0x310($v0)
    MEM_W(0X310, ctx->r2) = ctx->f0.u32l;
    // 0x80678F64: swc1        $f0, 0x314($v0)
    MEM_W(0X314, ctx->r2) = ctx->f0.u32l;
    // 0x80678F68: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80678F6C: bne         $v1, $a0, L_80678F58
    if (ctx->r3 != ctx->r4) {
        // 0x80678F70: swc1        $f0, 0x2F8($v0)
        MEM_W(0X2F8, ctx->r2) = ctx->f0.u32l;
            goto L_80678F58;
    }
    // 0x80678F70: swc1        $f0, 0x2F8($v0)
    MEM_W(0X2F8, ctx->r2) = ctx->f0.u32l;
    // 0x80678F74: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80678F78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80678F7C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80678F80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80678F84: lui         $at, 0xC200
    ctx->r1 = S32(0XC200 << 16);
    // 0x80678F88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80678F8C: sh          $zero, 0x408($a1)
    MEM_H(0X408, ctx->r5) = 0;
    // 0x80678F90: swc1        $f0, 0x40C($a1)
    MEM_W(0X40C, ctx->r5) = ctx->f0.u32l;
    // 0x80678F94: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80678F98: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80678F9C: swc1        $f4, 0x410($a1)
    MEM_W(0X410, ctx->r5) = ctx->f4.u32l;
    // 0x80678FA0: swc1        $f6, 0x414($a1)
    MEM_W(0X414, ctx->r5) = ctx->f6.u32l;
    // 0x80678FA4: swc1        $f8, 0x418($a1)
    MEM_W(0X418, ctx->r5) = ctx->f8.u32l;
    // 0x80678FA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80678FAC:
    // 0x80678FAC: jal         0x80678868
    // 0x80678FB0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80678868(rdram, ctx);
        goto after_0;
    // 0x80678FB0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80678FB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80678FB8: bnel        $s0, $s1, L_80678FAC
    if (ctx->r16 != ctx->r17) {
        // 0x80678FBC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80678FAC;
    }
    goto skip_0;
    // 0x80678FBC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x80678FC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80678FC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80678FC8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80678FCC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80678FD0: jr          $ra
    // 0x80678FD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80678FD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805DA1FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA1FC: jr          $ra
    // 0x805DA200: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    return;
    // 0x805DA200: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
;}
RECOMP_FUNC void func_806D88D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D88D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806D88D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D88D8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x806D88DC: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806D88E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806D88E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806D88E8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x806D88EC: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806D88F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806D88F4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806D88F8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x806D88FC: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x806D8900: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x806D8904: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x806D8908: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x806D890C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x806D8910: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x806D8914: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x806D8918: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x806D891C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x806D8920: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x806D8924: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x806D8928: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x806D892C: jalr        $t9
    // 0x806D8930: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806D8930: nop

    after_0:
    // 0x806D8934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D8938: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x806D893C: jr          $ra
    // 0x806D8940: nop

    return;
    // 0x806D8940: nop

;}
RECOMP_FUNC void func_80035450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035458: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003545C: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x80035460: lw          $t6, 0x38($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X38);
    // 0x80035464: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x80035468: slti        $at, $v0, -0x78
    ctx->r1 = SIGNED(ctx->r2) < -0X78 ? 1 : 0;
    // 0x8003546C: bne         $at, $zero, L_80035530
    if (ctx->r1 != 0) {
        // 0x80035470: slti        $at, $v0, 0x30
        ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
            goto L_80035530;
    }
    // 0x80035470: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x80035474: beql        $at, $zero, L_80035534
    if (ctx->r1 == 0) {
        // 0x80035478: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035534;
    }
    goto skip_0;
    // 0x80035478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8003547C: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80035480: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80035484: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80035488: nop

    // 0x8003548C: bc1fl       L_80035534
    if (!c1cs) {
        // 0x80035490: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035534;
    }
    goto skip_1;
    // 0x80035490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80035494: lhu         $v0, 0xE($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XE);
    // 0x80035498: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003549C: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x800354A0: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x800354A4: beq         $v0, $at, L_800354C4
    if (ctx->r2 == ctx->r1) {
        // 0x800354A8: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800354C4;
    }
    // 0x800354A8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800354AC: beql        $v0, $at, L_800354C8
    if (ctx->r2 == ctx->r1) {
        // 0x800354B0: lbu         $t8, 0x18($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X18);
            goto L_800354C8;
    }
    goto skip_2;
    // 0x800354B0: lbu         $t8, 0x18($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X18);
    skip_2:
    // 0x800354B4: beq         $v0, $zero, L_800354C4
    if (ctx->r2 == 0) {
        // 0x800354B8: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800354C4;
    }
    // 0x800354B8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800354BC: bnel        $v0, $at, L_80035534
    if (ctx->r2 != ctx->r1) {
        // 0x800354C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035534;
    }
    goto skip_3;
    // 0x800354C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_800354C4:
    // 0x800354C4: lbu         $t8, 0x18($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X18);
L_800354C8:
    // 0x800354C8: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x800354CC: beql        $t8, $at, L_80035534
    if (ctx->r24 == ctx->r1) {
        // 0x800354D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035534;
    }
    goto skip_4;
    // 0x800354D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x800354D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800354D8: lwc1        $f8, 0xC4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x800354DC: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800354E0: nop

    // 0x800354E4: bc1tl       L_80035534
    if (c1cs) {
        // 0x800354E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035534;
    }
    goto skip_5;
    // 0x800354E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x800354EC: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    // 0x800354F0: jal         0x80065954
    // 0x800354F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x800354F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800354F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800354FC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80035500: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80035504: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80035508: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8003550C: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80035510: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80035514: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x80035518: nop

    // 0x8003551C: bc1fl       L_80035530
    if (!c1cs) {
        // 0x80035520: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_80035530;
    }
    goto skip_6;
    // 0x80035520: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    skip_6:
    // 0x80035524: b           L_80035530
    // 0x80035528: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_80035530;
    // 0x80035528: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8003552C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
L_80035530:
    // 0x80035530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035534:
    // 0x80035534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035538: jr          $ra
    // 0x8003553C: nop

    return;
    // 0x8003553C: nop

;}
RECOMP_FUNC void func_80446CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80446CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80446CD8: bltz        $a0, L_80446D30
    if (SIGNED(ctx->r4) < 0) {
        // 0x80446CDC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80446D30;
    }
    // 0x80446CDC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80446CE0: slti        $at, $a0, 0xC
    ctx->r1 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // 0x80446CE4: beql        $at, $zero, L_80446D34
    if (ctx->r1 == 0) {
        // 0x80446CE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80446D34;
    }
    goto skip_0;
    // 0x80446CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80446CEC: bne         $a1, $zero, L_80446D18
    if (ctx->r5 != 0) {
        // 0x80446CF0: sll         $t7, $a3, 2
        ctx->r15 = S32(ctx->r7 << 2);
            goto L_80446D18;
    }
    // 0x80446CF0: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80446CF4: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80446CF8: lui         $t9, 0x8045
    ctx->r25 = S32(RELOC_HI16(98, 0X13294) << 16);
    // 0x80446CFC: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80446D00: lw          $t9, 0x7674($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13294));
    // 0x80446D04: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80446D08: jalr        $t9
    // 0x80446D0C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80446D0C: nop

    after_0:
    // 0x80446D10: b           L_80446D34
    // 0x80446D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80446D34;
    // 0x80446D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80446D18:
    // 0x80446D18: lui         $t9, 0x8045
    ctx->r25 = S32(RELOC_HI16(98, 0X132C4) << 16);
    // 0x80446D1C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80446D20: lw          $t9, 0x76A4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X132C4));
    // 0x80446D24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80446D28: jalr        $t9
    // 0x80446D2C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80446D2C: nop

    after_1:
L_80446D30:
    // 0x80446D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80446D34:
    // 0x80446D34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80446D38: jr          $ra
    // 0x80446D3C: nop

    return;
    // 0x80446D3C: nop

;}
RECOMP_FUNC void func_80439D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80439D00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80439D04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80439D08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80439D0C: jal         0x80439090
    // 0x80439D10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80439090(rdram, ctx);
        goto after_0;
    // 0x80439D10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80439D14: jal         0x804393DC
    // 0x80439D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804393DC(rdram, ctx);
        goto after_1;
    // 0x80439D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80439D1C: jal         0x80439BAC
    // 0x80439D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80439BAC(rdram, ctx);
        goto after_2;
    // 0x80439D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80439D24: jal         0x80438BBC
    // 0x80439D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80438BBC(rdram, ctx);
        goto after_3;
    // 0x80439D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80439D2C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80439D30: lw          $t6, -0x76BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76BC);
    // 0x80439D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80439D38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80439D3C: beq         $t6, $zero, L_80439D4C
    if (ctx->r14 == 0) {
        // 0x80439D40: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_80439D4C;
    }
    // 0x80439D40: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80439D44: jal         0x8043A27C
    // 0x80439D48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8043A27C(rdram, ctx);
        goto after_4;
    // 0x80439D48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
L_80439D4C:
    // 0x80439D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80439D50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80439D54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80439D58: jr          $ra
    // 0x80439D5C: nop

    return;
    // 0x80439D5C: nop

;}
RECOMP_FUNC void func_8004029C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004029C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800402A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800402A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800402A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800402AC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800402B0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800402B4: jal         0x8003E558
    // 0x800402B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8003E558(rdram, ctx);
        goto after_0;
    // 0x800402B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800402BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800402C0: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    // 0x800402C4: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x800402C8: sb          $v0, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r2;
    // 0x800402CC: jalr        $t9
    // 0x800402D0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800402D0: nop

    after_1:
    // 0x800402D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800402D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800402DC: nop

    // 0x800402E0: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x800402E4: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x800402E8: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x800402EC: jal         0x800401B4
    // 0x800402F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800401B4(rdram, ctx);
        goto after_2;
    // 0x800402F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800402F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800402F8: jal         0x8003E7E0
    // 0x800402FC: lhu         $a1, 0x26($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X26);
    func_8003E7E0(rdram, ctx);
        goto after_3;
    // 0x800402FC: lhu         $a1, 0x26($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X26);
    after_3:
    // 0x80040300: jal         0x80038E18
    // 0x80040304: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80038E18(rdram, ctx);
        goto after_4;
    // 0x80040304: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80040308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004030C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80040314: jr          $ra
    // 0x80040318: nop

    return;
    // 0x80040318: nop

;}
RECOMP_FUNC void func_8064E258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E258: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8064E25C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064E260: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064E264: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064E268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064E26C: jal         0x80059278
    // 0x8064E270: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80059278(rdram, ctx);
        goto after_0;
    // 0x8064E270: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8064E274: beq         $v0, $zero, L_8064E2A0
    if (ctx->r2 == 0) {
        // 0x8064E278: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_8064E2A0;
    }
    // 0x8064E278: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8064E27C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8064E280: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x8064E284: lbu         $t7, 0xF0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XF0);
    // 0x8064E288: beql        $t7, $zero, L_8064E2A4
    if (ctx->r15 == 0) {
        // 0x8064E28C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8064E2A4;
    }
    goto skip_0;
    // 0x8064E28C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8064E290: jal         0x8064E368
    // 0x8064E294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064E368(rdram, ctx);
        goto after_1;
    // 0x8064E294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8064E298: b           L_8064E358
    // 0x8064E29C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8064E358;
    // 0x8064E29C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064E2A0:
    // 0x8064E2A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8064E2A4:
    // 0x8064E2A4: jal         0x8064E1E8
    // 0x8064E2A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8064E1E8(rdram, ctx);
        goto after_2;
    // 0x8064E2A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x8064E2AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8064E2B0: lui         $at, 0x8065
    ctx->r1 = S32(RELOC_HI16(498, 0XBE4) << 16);
    // 0x8064E2B4: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8064E2B8: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8064E2BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8064E2C0: nop

    // 0x8064E2C4: bc1fl       L_8064E2F8
    if (!c1cs) {
        // 0x8064E2C8: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8064E2F8;
    }
    goto skip_1;
    // 0x8064E2C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_1:
    // 0x8064E2CC: lwc1        $f4, -0x174C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(498, 0XBE4));
    // 0x8064E2D0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8064E2D4: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8064E2D8: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8064E2DC: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8064E2E0: nop

    // 0x8064E2E4: bc1fl       L_8064E32C
    if (!c1cs) {
        // 0x8064E2E8: lw          $t8, 0x18($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X18);
            goto L_8064E32C;
    }
    goto skip_2;
    // 0x8064E2E8: lw          $t8, 0x18($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X18);
    skip_2:
    // 0x8064E2EC: b           L_8064E328
    // 0x8064E2F0: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
        goto L_8064E328;
    // 0x8064E2F0: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
    // 0x8064E2F4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8064E2F8:
    // 0x8064E2F8: lui         $at, 0x8065
    ctx->r1 = S32(RELOC_HI16(498, 0XBE8) << 16);
    // 0x8064E2FC: bc1fl       L_8064E32C
    if (!c1cs) {
        // 0x8064E300: lw          $t8, 0x18($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X18);
            goto L_8064E32C;
    }
    goto skip_3;
    // 0x8064E300: lw          $t8, 0x18($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X18);
    skip_3:
    // 0x8064E304: lwc1        $f10, -0x1748($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(498, 0XBE8));
    // 0x8064E308: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8064E30C: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x8064E310: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8064E314: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x8064E318: nop

    // 0x8064E31C: bc1fl       L_8064E32C
    if (!c1cs) {
        // 0x8064E320: lw          $t8, 0x18($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X18);
            goto L_8064E32C;
    }
    goto skip_4;
    // 0x8064E320: lw          $t8, 0x18($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X18);
    skip_4:
    // 0x8064E324: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
L_8064E328:
    // 0x8064E328: lw          $t8, 0x18($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X18);
L_8064E32C:
    // 0x8064E32C: lui         $at, 0x8065
    ctx->r1 = S32(RELOC_HI16(498, 0XB60) << 16);
    // 0x8064E330: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8064E334: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8064E338: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8064E33C: lw          $t9, -0x17D0($at)
    ctx->r25 = MEM_W(ctx->r1, (int16_t)RELOC_LO16(498, 0XB60));
    // 0x8064E340: jalr        $t9
    // 0x8064E344: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8064E344: nop

    after_3:
    // 0x8064E348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064E34C: jal         0x8064E194
    // 0x8064E350: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8064E194(rdram, ctx);
        goto after_4;
    // 0x8064E350: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x8064E354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064E358:
    // 0x8064E358: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064E35C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8064E360: jr          $ra
    // 0x8064E364: nop

    return;
    // 0x8064E364: nop

;}
RECOMP_FUNC void func_80051418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051418: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005141C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80051420: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80051424: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80051428: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005142C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80051430: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80051434: jal         0x80051348
    // 0x80051438: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_80051348(rdram, ctx);
        goto after_0;
    // 0x80051438: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x8005143C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80051440: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80051444: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x80051448: lw          $t7, 0x5C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X5C);
    // 0x8005144C: lw          $s3, 0x0($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X0);
    // 0x80051450: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
    // 0x80051454: lw          $s1, 0x4($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X4);
    // 0x80051458: blezl       $v0, L_8005148C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005145C: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_8005148C;
    }
    goto skip_0;
    // 0x8005145C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_80051460:
    // 0x80051460: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80051464: beql        $s2, $a0, L_8005147C
    if (ctx->r18 == ctx->r4) {
        // 0x80051468: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8005147C;
    }
    goto skip_1;
    // 0x80051468: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8005146C: jal         0x80051368
    // 0x80051470: nop

    func_80051368(rdram, ctx);
        goto after_1;
    // 0x80051470: nop

    after_1:
    // 0x80051474: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
    // 0x80051478: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8005147C:
    // 0x8005147C: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80051480: bne         $at, $zero, L_80051460
    if (ctx->r1 != 0) {
        // 0x80051484: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80051460;
    }
    // 0x80051484: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80051488: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_8005148C:
    // 0x8005148C: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x80051490: lhu         $t9, 0x60($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X60);
    // 0x80051494: addiu       $s0, $t8, 0x60
    ctx->r16 = ADD32(ctx->r24, 0X60);
    // 0x80051498: beql        $s2, $t9, L_800514C0
    if (ctx->r18 == ctx->r25) {
        // 0x8005149C: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_800514C0;
    }
    goto skip_2;
    // 0x8005149C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    skip_2:
    // 0x800514A0: lhu         $s1, 0x0($s0)
    ctx->r17 = MEM_HU(ctx->r16, 0X0);
    // 0x800514A4: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
L_800514A8:
    // 0x800514A8: jal         0x80051368
    // 0x800514AC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    func_80051368(rdram, ctx);
        goto after_2;
    // 0x800514AC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_2:
    // 0x800514B0: lhu         $s1, 0x0($s0)
    ctx->r17 = MEM_HU(ctx->r16, 0X0);
    // 0x800514B4: bnel        $s2, $s1, L_800514A8
    if (ctx->r18 != ctx->r17) {
        // 0x800514B8: andi        $a0, $s1, 0xFFFF
        ctx->r4 = ctx->r17 & 0XFFFF;
            goto L_800514A8;
    }
    goto skip_3;
    // 0x800514B8: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    skip_3:
    // 0x800514BC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_800514C0:
    // 0x800514C0: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800514C4: addiu       $a2, $a2, 0x3E10
    ctx->r6 = ADD32(ctx->r6, 0X3E10);
    // 0x800514C8: beq         $v0, $zero, L_800514E0
    if (ctx->r2 == 0) {
        // 0x800514CC: lui         $a3, 0x8005
        ctx->r7 = S32(0X8005 << 16);
            goto L_800514E0;
    }
    // 0x800514CC: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x800514D0: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x800514D4: lh          $a1, 0xA($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XA);
    // 0x800514D8: jal         0x80057F74
    // 0x800514DC: addiu       $a3, $a3, 0x13F8
    ctx->r7 = ADD32(ctx->r7, 0X13F8);
    func_80057F74(rdram, ctx);
        goto after_3;
    // 0x800514DC: addiu       $a3, $a3, 0x13F8
    ctx->r7 = ADD32(ctx->r7, 0X13F8);
    after_3:
L_800514E0:
    // 0x800514E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800514E4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800514E8: lw          $v0, -0x57D0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57D0);
    // 0x800514EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800514F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800514F4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800514F8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800514FC: jr          $ra
    // 0x80051500: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80051500: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806D6A78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D6A78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D6A7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D6A80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806D6A84: jal         0x80045A34
    // 0x806D6A88: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806D6A88: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x806D6A8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D6A90: lui         $t6, 0x806D
    ctx->r14 = S32(RELOC_HI16(619, 0X2E0) << 16);
    // 0x806D6A94: bne         $v0, $zero, L_806D6AAC
    if (ctx->r2 != 0) {
        // 0x806D6A98: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_806D6AAC;
    }
    // 0x806D6A98: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806D6A9C: jal         0x800445A4
    // 0x806D6AA0: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806D6AA0: nop

    after_1:
    // 0x806D6AA4: b           L_806D6AEC
    // 0x806D6AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806D6AEC;
    // 0x806D6AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D6AAC:
    // 0x806D6AAC: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806D6AB0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806D6AB4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806D6AB8: addiu       $t6, $t6, 0x6B30
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(619, 0X2E0));
    // 0x806D6ABC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806D6AC0: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806D6AC4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D6AC8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x806D6ACC: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806D6AD0: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x806D6AD4: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x806D6AD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D6ADC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806D6AE0: jal         0x806D6AF8
    // 0x806D6AE4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    func_806D6AF8(rdram, ctx);
        goto after_2;
    // 0x806D6AE4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_2:
    // 0x806D6AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D6AEC:
    // 0x806D6AEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D6AF0: jr          $ra
    // 0x806D6AF4: nop

    return;
    // 0x806D6AF4: nop

;}
RECOMP_FUNC void func_80469780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80469780: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80469784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80469788: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8046978C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80469790: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80469794: lui         $t8, 0x8047
    ctx->r24 = S32(RELOC_HI16(138, 0X280C) << 16);
    // 0x80469798: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8046979C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804697A0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804697A4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804697A8: lw          $t8, -0x40B4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(138, 0X280C));
    // 0x804697AC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804697B0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804697B4: jal         0x80048490
    // 0x804697B8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804697B8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804697BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804697C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804697C4: jr          $ra
    // 0x804697C8: nop

    return;
    // 0x804697C8: nop

;}
