#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void lroundf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800820FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80082100: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80082104: nop

    // 0x80082108: add.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8008210C: floor.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = S32(floorf(ctx->f0.fl));
    // 0x80082110: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x80082114: jr          $ra
    // 0x80082118: nop

    return;
    // 0x80082118: nop

;}
RECOMP_FUNC void func_80564140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80564140: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80564144: lh          $v1, 0x500($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X500);
    // 0x80564148: slti        $at, $v1, 0x9B
    ctx->r1 = SIGNED(ctx->r3) < 0X9B ? 1 : 0;
    // 0x8056414C: beq         $at, $zero, L_8056415C
    if (ctx->r1 == 0) {
        // 0x80564150: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_8056415C;
    }
    // 0x80564150: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80564154: sh          $t6, 0x500($v0)
    MEM_H(0X500, ctx->r2) = ctx->r14;
    // 0x80564158: lh          $v1, 0x500($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X500);
L_8056415C:
    // 0x8056415C: slti        $at, $v1, 0x9B
    ctx->r1 = SIGNED(ctx->r3) < 0X9B ? 1 : 0;
    // 0x80564160: bne         $at, $zero, L_80564174
    if (ctx->r1 != 0) {
        // 0x80564164: nop
    
            goto L_80564174;
    }
    // 0x80564164: nop

    // 0x80564168: lh          $t7, 0x502($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X502);
    // 0x8056416C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80564170: sh          $t8, 0x502($v0)
    MEM_H(0X502, ctx->r2) = ctx->r24;
L_80564174:
    // 0x80564174: jr          $ra
    // 0x80564178: nop

    return;
    // 0x80564178: nop

;}
RECOMP_FUNC void func_8043BA58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043BA58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8043BA5C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8043BA60: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8043BA64: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8043BA68: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8043BA6C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8043BA70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8043BA74: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8043BA78: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8043BA7C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8043BA80: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8043BA84: lw          $s5, 0x34($t6)
    ctx->r21 = MEM_W(ctx->r14, 0X34);
    // 0x8043BA88: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x8043BA8C: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x8043BA90: addiu       $s0, $s5, 0x4
    ctx->r16 = ADD32(ctx->r21, 0X4);
    // 0x8043BA94: blezl       $t7, L_8043BB40
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8043BA98: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8043BB40;
    }
    goto skip_0;
    // 0x8043BA98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_8043BA9C:
    // 0x8043BA9C: jal         0x80047090
    // 0x8043BAA0: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8043BAA0: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    after_0:
    // 0x8043BAA4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8043BAA8: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8043BAAC: lwc1        $f4, 0x3C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x8043BAB0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8043BAB4: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8043BAB8: lwc1        $f16, 0x40($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X40);
    // 0x8043BABC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8043BAC0: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x8043BAC4: andi        $s4, $v0, 0xFFFF
    ctx->r20 = ctx->r2 & 0XFFFF;
    // 0x8043BAC8: lw          $a3, 0x44($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X44);
    // 0x8043BACC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8043BAD0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8043BAD4: ori         $a0, $a0, 0x800
    ctx->r4 = ctx->r4 | 0X800;
    // 0x8043BAD8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8043BADC: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8043BAE0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8043BAE4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8043BAE8: jal         0x8004613C
    // 0x8043BAEC: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8043BAEC: nop

    after_1:
    // 0x8043BAF0: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x8043BAF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8043BAF8: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8043BAFC: nop

    // 0x8043BB00: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8043BB04: beq         $v0, $zero, L_8043BB24
    if (ctx->r2 == 0) {
        // 0x8043BB08: swc1        $f10, 0x50($v0)
        MEM_W(0X50, ctx->r2) = ctx->f10.u32l;
            goto L_8043BB24;
    }
    // 0x8043BB08: swc1        $f10, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f10.u32l;
    // 0x8043BB0C: lhu         $t3, 0xE($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XE);
    // 0x8043BB10: andi        $t2, $s4, 0x3FF
    ctx->r10 = ctx->r20 & 0X3FF;
    // 0x8043BB14: andi        $t4, $t3, 0xFC00
    ctx->r12 = ctx->r11 & 0XFC00;
    // 0x8043BB18: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8043BB1C: jal         0x80044194
    // 0x8043BB20: sh          $t5, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r13;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x8043BB20: sh          $t5, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r13;
    after_2:
L_8043BB24:
    // 0x8043BB24: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x8043BB28: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8043BB2C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8043BB30: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8043BB34: bne         $at, $zero, L_8043BA9C
    if (ctx->r1 != 0) {
        // 0x8043BB38: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_8043BA9C;
    }
    // 0x8043BB38: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8043BB3C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8043BB40:
    // 0x8043BB40: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8043BB44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8043BB48: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8043BB4C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8043BB50: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8043BB54: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8043BB58: jr          $ra
    // 0x8043BB5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8043BB5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8044BB30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BB30: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8044BB34: jr          $ra
    // 0x8044BB38: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8044BB38: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_80681A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80681A20: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x80681A24: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x80681A28: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80681A2C: lw          $t7, 0x180($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X180);
    // 0x80681A30: lui         $at, 0x4328
    ctx->r1 = S32(0X4328 << 16);
    // 0x80681A34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80681A38: lw          $t8, 0x1F4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1F4);
    // 0x80681A3C: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80681A40: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80681A44: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80681A48: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80681A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80681A50: lw          $v1, 0x1F4($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X1F4);
    // 0x80681A54: add.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80681A58: lwc1        $f4, 0x88($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X88);
    // 0x80681A5C: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80681A60: add.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80681A64: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80681A68: nop

    // 0x80681A6C: bc1f        L_80681A78
    if (!c1cs) {
        // 0x80681A70: nop
    
            goto L_80681A78;
    }
    // 0x80681A70: nop

    // 0x80681A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80681A78:
    // 0x80681A78: jr          $ra
    // 0x80681A7C: nop

    return;
    // 0x80681A7C: nop

;}
RECOMP_FUNC void func_800675D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800675D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800675D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800675D8: jalr        $a3
    // 0x800675DC: nop

    LOOKUP_FUNC(ctx->r7)(rdram, ctx);
        goto after_0;
    // 0x800675DC: nop

    after_0:
    // 0x800675E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800675E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800675E8: jr          $ra
    // 0x800675EC: nop

    return;
    // 0x800675EC: nop

;}
RECOMP_FUNC void func_8057BD1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057BD1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057BD20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8057BD24: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8057BD28: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8057BD2C: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(387, 0XF38) << 16);
    // 0x8057BD30: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8057BD34: lw          $v0, -0x35B8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(387, 0XF38));
    // 0x8057BD38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057BD3C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8057BD40: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8057BD44: beql        $v1, $zero, L_8057BD78
    if (ctx->r3 == 0) {
        // 0x8057BD48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057BD78;
    }
    goto skip_0;
    // 0x8057BD48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8057BD4C: jalr        $v1
    // 0x8057BD50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8057BD50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8057BD54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8057BD58: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x8057BD5C: lw          $t9, 0x14C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14C);
    // 0x8057BD60: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8057BD64: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8057BD68: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8057BD6C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8057BD70: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x8057BD74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057BD78:
    // 0x8057BD78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057BD7C: jr          $ra
    // 0x8057BD80: nop

    return;
    // 0x8057BD80: nop

;}
RECOMP_FUNC void func_8043FBA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043FBA8: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8043FBAC: lwc1        $f6, 0xE0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x8043FBB0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8043FBB4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8043FBB8: nop

    // 0x8043FBBC: bc1t        L_8043FBD4
    if (c1cs) {
        // 0x8043FBC0: nop
    
            goto L_8043FBD4;
    }
    // 0x8043FBC0: nop

    // 0x8043FBC4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8043FBC8: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8043FBCC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8043FBD0: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
L_8043FBD4:
    // 0x8043FBD4: jr          $ra
    // 0x8043FBD8: nop

    return;
    // 0x8043FBD8: nop

;}
RECOMP_FUNC void func_8069F1C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069F1C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8069F1CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8069F1D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8069F1D4: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x8069F1D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8069F1DC: lbu         $t6, 0x10($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X10);
    // 0x8069F1E0: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x8069F1E4: slti        $at, $t6, 0xE0
    ctx->r1 = SIGNED(ctx->r14) < 0XE0 ? 1 : 0;
    // 0x8069F1E8: beql        $at, $zero, L_8069F2A4
    if (ctx->r1 == 0) {
        // 0x8069F1EC: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_8069F2A4;
    }
    goto skip_0;
    // 0x8069F1EC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x8069F1F0: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069F1F4: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8069F1F8: jal         0x800653D8
    // 0x8069F1FC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8069F1FC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8069F200: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x8069F204: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8069F208: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5A0) << 16);
    // 0x8069F20C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8069F210: lwc1        $f6, -0xAF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5A0));
    // 0x8069F214: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8069F218: jal         0x80066DE4
    // 0x8069F21C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8069F21C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8069F220: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8069F224: jal         0x80066E88
    // 0x8069F228: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8069F228: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8069F22C: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8069F230: lwc1        $f8, 0xDC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x8069F234: lwc1        $f18, 0xE0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x8069F238: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8069F23C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8069F240: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8069F244: swc1        $f16, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f16.u32l;
    // 0x8069F248: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8069F24C: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8069F250: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8069F254: jal         0x80065954
    // 0x8069F258: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x8069F258: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x8069F25C: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5D8) << 16);
    // 0x8069F260: lwc1        $f16, -0xAB8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5D8));
    // 0x8069F264: lwc1        $f10, 0xE8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8069F268: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8069F26C: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8069F270: swc1        $f18, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f18.u32l;
    // 0x8069F274: jal         0x80065954
    // 0x8069F278: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_80065954(rdram, ctx);
        goto after_4;
    // 0x8069F278: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x8069F27C: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5DC) << 16);
    // 0x8069F280: lwc1        $f8, -0xAB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5DC));
    // 0x8069F284: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8069F288: lui         $t0, 0x806A
    ctx->r8 = S32(RELOC_HI16(580, 0X218) << 16);
    // 0x8069F28C: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8069F290: addiu       $t0, $t0, -0xE78
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(580, 0X218));
    // 0x8069F294: sw          $t0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r8;
    // 0x8069F298: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8069F29C: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
    // 0x8069F2A0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_8069F2A4:
    // 0x8069F2A4: jal         0x80048F84
    // 0x8069F2A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_5;
    // 0x8069F2A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8069F2AC: jal         0x8069EFC0
    // 0x8069F2B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8069EFC0(rdram, ctx);
        goto after_6;
    // 0x8069F2B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8069F2B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8069F2B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8069F2BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8069F2C0: jr          $ra
    // 0x8069F2C4: nop

    return;
    // 0x8069F2C4: nop

;}
RECOMP_FUNC void func_805A1D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1D44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A1D48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A1D4C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A1D50: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A1D54: jal         0x800692D4
    // 0x805A1D58: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_800692D4(rdram, ctx);
        goto after_0;
    // 0x805A1D58: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x805A1D5C: beq         $v0, $zero, L_805A1DA4
    if (ctx->r2 == 0) {
        // 0x805A1D60: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_805A1DA4;
    }
    // 0x805A1D60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A1D64: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x805A1D68: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x805A1D6C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x805A1D70: beq         $v1, $at, L_805A1DA4
    if (ctx->r3 == ctx->r1) {
        // 0x805A1D74: addiu       $v0, $a0, 0xC4
        ctx->r2 = ADD32(ctx->r4, 0XC4);
            goto L_805A1DA4;
    }
    // 0x805A1D74: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x805A1D78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A1D7C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x805A1D80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A1D84: sb          $v1, 0x30($t7)
    MEM_B(0X30, ctx->r15) = ctx->r3;
    // 0x805A1D88: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x805A1D8C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x805A1D90: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x805A1D94: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x805A1D98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A1D9C: jal         0x805A2B28
    // 0x805A1DA0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_805A2B28(rdram, ctx);
        goto after_1;
    // 0x805A1DA0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_1:
L_805A1DA4:
    // 0x805A1DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A1DA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A1DAC: jr          $ra
    // 0x805A1DB0: nop

    return;
    // 0x805A1DB0: nop

;}
RECOMP_FUNC void func_8002E488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E488: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002E48C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E490: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002E494: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002E498: jal         0x8002DBA8
    // 0x8002E49C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8002DBA8(rdram, ctx);
        goto after_0;
    // 0x8002E49C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002E4A0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8002E4A4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8002E4A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002E4AC: lbu         $t6, 0x1A8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1A8);
    // 0x8002E4B0: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8002E4B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002E4B8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8002E4BC: lwc1        $f4, -0x1810($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1810);
    // 0x8002E4C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002E4C4: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x8002E4C8: lwc1        $f6, -0x54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X54);
    // 0x8002E4CC: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
    // 0x8002E4D0: sb          $zero, 0x21($v0)
    MEM_B(0X21, ctx->r2) = 0;
    // 0x8002E4D4: sw          $zero, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = 0;
    // 0x8002E4D8: sw          $zero, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = 0;
    // 0x8002E4DC: sw          $t8, 0x1A4($v0)
    MEM_W(0X1A4, ctx->r2) = ctx->r24;
    // 0x8002E4E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E4E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002E4E8: jr          $ra
    // 0x8002E4EC: nop

    return;
    // 0x8002E4EC: nop

;}
RECOMP_FUNC void func_80531174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531174: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80531178: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8053117C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80531180: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80531184: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80531188: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8053118C: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x80531190: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80531194: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80531198: lw          $t8, 0x168($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X168);
    // 0x8053119C: lh          $t0, 0x144($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X144);
    // 0x805311A0: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x805311A4: lw          $t9, 0x88($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X88);
    // 0x805311A8: sll         $t1, $t0, 9
    ctx->r9 = S32(ctx->r8 << 9);
    // 0x805311AC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x805311B0: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x805311B4: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x805311B8: lw          $t3, 0x1F4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X1F4);
    // 0x805311BC: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x805311C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805311C4: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x805311C8: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x805311CC: jal         0x80530FA4
    // 0x805311D0: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    func_80530FA4(rdram, ctx);
        goto after_0;
    // 0x805311D0: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    after_0:
    // 0x805311D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805311D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805311DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805311E0: jal         0x8007711C
    // 0x805311E4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x805311E4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x805311E8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x805311EC: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x805311F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805311F4: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x805311F8: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x805311FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80531200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80531204: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80531208: jal         0x80531090
    // 0x8053120C: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    func_80531090(rdram, ctx);
        goto after_2;
    // 0x8053120C: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    after_2:
    // 0x80531210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80531214: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80531218: jal         0x80530F54
    // 0x8053121C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80530F54(rdram, ctx);
        goto after_3;
    // 0x8053121C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80531220: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80531224: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x80531228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8053122C: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x80531230: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80531234: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80531238: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8053123C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80531240: jal         0x80531090
    // 0x80531244: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    func_80531090(rdram, ctx);
        goto after_4;
    // 0x80531244: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    after_4:
    // 0x80531248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8053124C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80531250: jal         0x80530F54
    // 0x80531254: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80530F54(rdram, ctx);
        goto after_5;
    // 0x80531254: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80531258: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8053125C: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80531260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80531264: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x80531268: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8053126C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80531270: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80531274: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80531278: jal         0x80531090
    // 0x8053127C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    func_80531090(rdram, ctx);
        goto after_6;
    // 0x8053127C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    after_6:
    // 0x80531280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80531284: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80531288: jal         0x80530F54
    // 0x8053128C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80530F54(rdram, ctx);
        goto after_7;
    // 0x8053128C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_7:
    // 0x80531290: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80531294: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80531298: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x8053129C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805312A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805312A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805312A8: jr          $ra
    // 0x805312AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x805312AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80059DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059DEC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80059DF0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80059DF4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059DF8: lwc1        $f0, 0xBD8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XBD8);
    // 0x80059DFC: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80059E00: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80059E04: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80059E08: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80059E0C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80059E10: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80059E14: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80059E18: bc1t        L_80059E60
    if (c1cs) {
        // 0x80059E1C: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_80059E60;
    }
    // 0x80059E1C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80059E20: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059E24: lwc1        $f2, 0xBDC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0XBDC);
    // 0x80059E28: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80059E2C: nop

    // 0x80059E30: bc1tl       L_80059E64
    if (c1cs) {
        // 0x80059E34: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80059E64;
    }
    goto skip_0;
    // 0x80059E34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    skip_0:
    // 0x80059E38: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80059E3C: nop

    // 0x80059E40: bc1tl       L_80059E64
    if (c1cs) {
        // 0x80059E44: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80059E64;
    }
    goto skip_1;
    // 0x80059E44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    skip_1:
    // 0x80059E48: c.lt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl < ctx->f2.fl;
    // 0x80059E4C: nop

    // 0x80059E50: bc1tl       L_80059E64
    if (c1cs) {
        // 0x80059E54: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80059E64;
    }
    goto skip_2;
    // 0x80059E54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    skip_2:
    // 0x80059E58: b           L_80059E9C
    // 0x80059E5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80059E9C;
    // 0x80059E5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059E60:
    // 0x80059E60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
L_80059E64:
    // 0x80059E64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80059E68: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_80059E6C:
    // 0x80059E6C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80059E70: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80059E74: add.s       $f12, $f4, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80059E78: jal         0x8006B284
    // 0x80059E7C: add.s       $f14, $f6, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f22.fl;
    func_8006B284(rdram, ctx);
        goto after_0;
    // 0x80059E7C: add.s       $f14, $f6, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f22.fl;
    after_0:
    // 0x80059E80: bne         $v0, $zero, L_80059E90
    if (ctx->r2 != 0) {
        // 0x80059E84: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80059E90;
    }
    // 0x80059E84: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80059E88: b           L_80059E9C
    // 0x80059E8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80059E9C;
    // 0x80059E8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059E90:
    // 0x80059E90: bne         $s1, $s2, L_80059E6C
    if (ctx->r17 != ctx->r18) {
        // 0x80059E94: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80059E6C;
    }
    // 0x80059E94: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80059E98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059E9C:
    // 0x80059E9C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80059EA0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80059EA4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80059EA8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80059EAC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80059EB0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80059EB4: jr          $ra
    // 0x80059EB8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80059EB8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8043BA50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043BA50: jr          $ra
    // 0x8043BA54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8043BA54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_807429D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807429D4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807429D8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x807429DC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x807429E0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x807429E4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x807429E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x807429EC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x807429F0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x807429F4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x807429F8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x807429FC: jr          $ra
    // 0x80742A00: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742A00: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80047090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047090: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80047094: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80047098: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004709C: andi        $s1, $a0, 0xFFFF
    ctx->r17 = ctx->r4 & 0XFFFF;
    // 0x800470A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800470A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800470A8: addiu       $s0, $zero, 0x200
    ctx->r16 = ADD32(0, 0X200);
    // 0x800470AC: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
L_800470B0:
    // 0x800470B0: jal         0x80046FBC
    // 0x800470B4: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    func_80046FBC(rdram, ctx);
        goto after_0;
    // 0x800470B4: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    after_0:
    // 0x800470B8: bnel        $v0, $zero, L_800470CC
    if (ctx->r2 != 0) {
        // 0x800470BC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800470CC;
    }
    goto skip_0;
    // 0x800470BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800470C0: b           L_800470E0
    // 0x800470C4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800470E0;
    // 0x800470C4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800470C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800470CC:
    // 0x800470CC: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x800470D0: slti        $at, $s0, 0x3FF
    ctx->r1 = SIGNED(ctx->r16) < 0X3FF ? 1 : 0;
    // 0x800470D4: bnel        $at, $zero, L_800470B0
    if (ctx->r1 != 0) {
        // 0x800470D8: andi        $a0, $s1, 0xFFFF
        ctx->r4 = ctx->r17 & 0XFFFF;
            goto L_800470B0;
    }
    goto skip_1;
    // 0x800470D8: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    skip_1:
    // 0x800470DC: addiu       $v0, $zero, 0x3FF
    ctx->r2 = ADD32(0, 0X3FF);
L_800470E0:
    // 0x800470E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800470E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800470E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800470EC: jr          $ra
    // 0x800470F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800470F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_805365F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805365F4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805365F8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805365FC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536600: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536604: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536608: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053660C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536610: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536614: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536618: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053661C: jr          $ra
    // 0x80536620: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536620: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804A0548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A0548: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804A054C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804A0550: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804A0554: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804A0558: lui         $t6, 0x804A
    ctx->r14 = S32(RELOC_HI16(173, 0X2530) << 16);
    // 0x804A055C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804A0560: addiu       $t6, $t6, 0x2970
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(173, 0X2530));
    // 0x804A0564: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804A0568: jal         0x804A1398
    // 0x804A056C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    func_804A1398(rdram, ctx);
        goto after_0;
    // 0x804A056C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    after_0:
    // 0x804A0570: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x804A0574: sw          $zero, 0x60($v0)
    MEM_W(0X60, ctx->r2) = 0;
    // 0x804A0578: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x804A057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A0580: jal         0x80045A34
    // 0x804A0584: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x804A0584: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_1:
    // 0x804A0588: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804A058C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x804A0590: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x804A0594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A0598: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A059C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804A05A0: jal         0x804A27A0
    // 0x804A05A4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    func_804A27A0(rdram, ctx);
        goto after_2;
    // 0x804A05A4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    after_2:
    // 0x804A05A8: jal         0x804A04F0
    // 0x804A05AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804A04F0(rdram, ctx);
        goto after_3;
    // 0x804A05AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804A05B0: jal         0x804A1D18
    // 0x804A05B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804A1D18(rdram, ctx);
        goto after_4;
    // 0x804A05B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804A05B8: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x804A05BC: lw          $v1, -0x71E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X71E0);
    // 0x804A05C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804A05C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804A05C8: beq         $v1, $zero, L_804A05FC
    if (ctx->r3 == 0) {
        // 0x804A05CC: sb          $t9, -0x7EB0($at)
        MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
            goto L_804A05FC;
    }
    // 0x804A05CC: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x804A05D0: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x804A05D4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x804A05D8: addiu       $v0, $v0, -0x41F0
    ctx->r2 = ADD32(ctx->r2, -0X41F0);
    // 0x804A05DC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x804A05E0: bnel        $v1, $v0, L_804A0600
    if (ctx->r3 != ctx->r2) {
        // 0x804A05E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804A0600;
    }
    goto skip_0;
    // 0x804A05E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804A05E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A05EC: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x804A05F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804A05F4: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x804A05F8: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
L_804A05FC:
    // 0x804A05FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804A0600:
    // 0x804A0600: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804A0604: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804A0608: jr          $ra
    // 0x804A060C: nop

    return;
    // 0x804A060C: nop

;}
RECOMP_FUNC void func_800553F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800553F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800553F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800553FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80055400: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80055404: jal         0x80047090
    // 0x80055408: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80055408: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x8005540C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80055410: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x80055414: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x80055418: lw          $a3, 0x8C($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8C);
    // 0x8005541C: lw          $a2, 0x88($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X88);
    // 0x80055420: lw          $a1, 0x84($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X84);
    // 0x80055424: jal         0x8004613C
    // 0x80055428: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80055428: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    after_1:
    // 0x8005542C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80055430: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x80055434: lhu         $t7, 0x1E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1E);
    // 0x80055438: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005543C: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x80055440: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80055444: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80055448: jal         0x80044194
    // 0x8005544C: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x8005544C: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    after_2:
    // 0x80055450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80055454: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80055458: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005545C: jr          $ra
    // 0x80055460: nop

    return;
    // 0x80055460: nop

;}
RECOMP_FUNC void func_807C6958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C6958: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807C695C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C6960: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807C6964: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x807C6968: jal         0x80047090
    // 0x807C696C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807C696C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x807C6970: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x807C6974: beq         $v0, $at, L_807C69BC
    if (ctx->r2 == ctx->r1) {
        // 0x807C6978: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_807C69BC;
    }
    // 0x807C6978: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x807C697C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807C6980: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x807C6984: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x807C6988: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x807C698C: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x807C6990: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x807C6994: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x807C6998: jal         0x8004613C
    // 0x807C699C: or          $a0, $t8, $v1
    ctx->r4 = ctx->r24 | ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807C699C: or          $a0, $t8, $v1
    ctx->r4 = ctx->r24 | ctx->r3;
    after_1:
    // 0x807C69A0: beq         $v0, $zero, L_807C69BC
    if (ctx->r2 == 0) {
        // 0x807C69A4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_807C69BC;
    }
    // 0x807C69A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807C69A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807C69AC: jal         0x80047F9C
    // 0x807C69B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807C69B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x807C69B4: b           L_807C69C0
    // 0x807C69B8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_807C69C0;
    // 0x807C69B8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_807C69BC:
    // 0x807C69BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807C69C0:
    // 0x807C69C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C69C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807C69C8: jr          $ra
    // 0x807C69CC: nop

    return;
    // 0x807C69CC: nop

;}
RECOMP_FUNC void func_800371FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800371FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037204: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80037208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003720C: lw          $t6, 0x78($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X78);
    // 0x80037210: beq         $t6, $zero, L_80037234
    if (ctx->r14 == 0) {
        // 0x80037214: nop
    
            goto L_80037234;
    }
    // 0x80037214: nop

    // 0x80037218: jal         0x80035ED8
    // 0x8003721C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80035ED8(rdram, ctx);
        goto after_0;
    // 0x8003721C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80037220: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80037224: jal         0x8002F15C
    // 0x80037228: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    func_8002F15C(rdram, ctx);
        goto after_1;
    // 0x80037228: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_1:
    // 0x8003722C: b           L_80037234
    // 0x80037230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037234;
    // 0x80037230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037234:
    // 0x80037234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003723C: jr          $ra
    // 0x80037240: nop

    return;
    // 0x80037240: nop

;}
RECOMP_FUNC void func_80021F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021F08: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80021F0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80021F10: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80021F14: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80021F18: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80021F1C: lwc1        $f14, 0x10($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80021F20: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80021F24: nop

    // 0x80021F28: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80021F2C: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80021F30: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x80021F34: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80021F38: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80021F3C: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80021F40: nop

    // 0x80021F44: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80021F48: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80021F4C: jr          $ra
    // 0x80021F50: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80021F50: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80454FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80454FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80454FB8: lui         $a1, 0x8045
    ctx->r5 = S32(RELOC_HI16(98, 0X13910) << 16);
    // 0x80454FBC: jal         0x804547C0
    // 0x80454FC0: lw          $a1, 0x7CF0($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13910));
    func_804547C0(rdram, ctx);
        goto after_0;
    // 0x80454FC0: lw          $a1, 0x7CF0($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13910));
    after_0:
    // 0x80454FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80454FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80454FCC: jr          $ra
    // 0x80454FD0: nop

    return;
    // 0x80454FD0: nop

;}
RECOMP_FUNC void func_8006C67C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C67C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006C680: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006C684: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x8006C688: lw          $s0, -0x7D6C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D6C);
    // 0x8006C68C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006C690: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8006C694: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C698: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8006C69C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006C6A0: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x8006C6A4: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006C6A8: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8006C6AC: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8006C6B0: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x8006C6B4: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8006C6B8: swc1        $f18, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f18.u32l;
    // 0x8006C6BC: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8006C6C0: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x8006C6C4: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8006C6C8: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x8006C6CC: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006C6D0: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8006C6D4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C6D8: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8006C6DC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8006C6E0: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8006C6E4: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8006C6E8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006C6EC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006C6F0: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8006C6F4: sub.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8006C6F8: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8006C6FC: jal         0x80067114
    // 0x8006C700: sqrt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = sqrtf(ctx->f0.fl);
    func_80067114(rdram, ctx);
        goto after_0;
    // 0x8006C700: sqrt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = sqrtf(ctx->f0.fl);
    after_0:
    // 0x8006C704: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8006C708: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8006C70C: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8006C710: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8006C714: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006C718: nop

    // 0x8006C71C: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8006C720: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006C724: jal         0x80067114
    // 0x8006C728: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    func_80067114(rdram, ctx);
        goto after_1;
    // 0x8006C728: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_1:
    // 0x8006C72C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8006C730: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x8006C734: jal         0x80066DE4
    // 0x8006C738: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8006C738: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8006C73C: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8006C740: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8006C744: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8006C748: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8006C74C: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x8006C750: nop

    // 0x8006C754: bc1fl       L_8006C76C
    if (!c1cs) {
        // 0x8006C758: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006C76C;
    }
    goto skip_0;
    // 0x8006C758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8006C75C: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8006C760: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8006C764: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x8006C768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006C76C:
    // 0x8006C76C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006C770: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006C774: jr          $ra
    // 0x8006C778: nop

    return;
    // 0x8006C778: nop

;}
RECOMP_FUNC void func_800279E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800279E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800279EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800279F0: jal         0x80024668
    // 0x800279F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024668(rdram, ctx);
        goto after_0;
    // 0x800279F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800279F8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800279FC: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80027A00: addiu       $t6, $t6, 0x7968
    ctx->r14 = ADD32(ctx->r14, 0X7968);
    // 0x80027A04: lw          $t7, 0x1F4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1F4);
    // 0x80027A08: sw          $t6, 0x160($a3)
    MEM_W(0X160, ctx->r7) = ctx->r14;
    // 0x80027A0C: lw          $t9, 0x15C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X15C);
    // 0x80027A10: lw          $t8, 0x48($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X48);
    // 0x80027A14: jal         0x8001D770
    // 0x80027A18: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x80027A18: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    after_1:
    // 0x80027A1C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80027A20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80027A24: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80027A28: jal         0x80067BF8
    // 0x80027A2C: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_2;
    // 0x80027A2C: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x80027A30: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80027A34: jal         0x80067818
    // 0x80027A38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80027A38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80027A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027A40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80027A44: jr          $ra
    // 0x80027A48: nop

    return;
    // 0x80027A48: nop

;}
RECOMP_FUNC void func_804448AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804448AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804448B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x804448B4: jr          $ra
    // 0x804448B8: sb          $t6, 0x7EA4($at)
    MEM_B(0X7EA4, ctx->r1) = ctx->r14;
    return;
    // 0x804448B8: sb          $t6, 0x7EA4($at)
    MEM_B(0X7EA4, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8079EA14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079EA14: andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // 0x8079EA18: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8079EA1C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x8079EA20: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8079EA24: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8079EA28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8079EA2C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8079EA30: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
L_8079EA34:
    // 0x8079EA34: bnel        $at, $zero, L_8079EA84
    if (ctx->r1 != 0) {
        // 0x8079EA38: slti        $at, $a3, 0x4
        ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
            goto L_8079EA84;
    }
    goto skip_0;
    // 0x8079EA38: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    skip_0:
    // 0x8079EA3C: div         $zero, $v0, $t0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r8)));
    // 0x8079EA40: sll         $t6, $a3, 1
    ctx->r14 = S32(ctx->r7 << 1);
    // 0x8079EA44: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8079EA48: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8079EA4C: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x8079EA50: bne         $t0, $zero, L_8079EA5C
    if (ctx->r8 != 0) {
        // 0x8079EA54: nop
    
            goto L_8079EA5C;
    }
    // 0x8079EA54: nop

    // 0x8079EA58: break       7
    do_break(2155473496);
L_8079EA5C:
    // 0x8079EA5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8079EA60: bne         $t0, $at, L_8079EA74
    if (ctx->r8 != ctx->r1) {
        // 0x8079EA64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8079EA74;
    }
    // 0x8079EA64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8079EA68: bne         $v0, $at, L_8079EA74
    if (ctx->r2 != ctx->r1) {
        // 0x8079EA6C: nop
    
            goto L_8079EA74;
    }
    // 0x8079EA6C: nop

    // 0x8079EA70: break       6
    do_break(2155473520);
L_8079EA74:
    // 0x8079EA74: mflo        $v0
    ctx->r2 = lo;
    // 0x8079EA78: bnel        $a3, $a1, L_8079EA34
    if (ctx->r7 != ctx->r5) {
        // 0x8079EA7C: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8079EA34;
    }
    goto skip_1;
    // 0x8079EA7C: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    skip_1:
    // 0x8079EA80: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
L_8079EA84:
    // 0x8079EA84: bne         $at, $zero, L_8079EA94
    if (ctx->r1 != 0) {
        // 0x8079EA88: sll         $t9, $a3, 1
        ctx->r25 = S32(ctx->r7 << 1);
            goto L_8079EA94;
    }
    // 0x8079EA88: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x8079EA8C: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8079EA90: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
L_8079EA94:
    // 0x8079EA94: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x8079EA98: beq         $at, $zero, L_8079EB18
    if (ctx->r1 == 0) {
        // 0x8079EA9C: addu        $a1, $a0, $t9
        ctx->r5 = ADD32(ctx->r4, ctx->r25);
            goto L_8079EB18;
    }
    // 0x8079EA9C: addu        $a1, $a0, $t9
    ctx->r5 = ADD32(ctx->r4, ctx->r25);
L_8079EAA0:
    // 0x8079EAA0: div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // 0x8079EAA4: bne         $v0, $zero, L_8079EAB0
    if (ctx->r2 != 0) {
        // 0x8079EAA8: nop
    
            goto L_8079EAB0;
    }
    // 0x8079EAA8: nop

    // 0x8079EAAC: break       7
    do_break(2155473580);
L_8079EAB0:
    // 0x8079EAB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8079EAB4: bne         $v0, $at, L_8079EAC8
    if (ctx->r2 != ctx->r1) {
        // 0x8079EAB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8079EAC8;
    }
    // 0x8079EAB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8079EABC: bne         $v1, $at, L_8079EAC8
    if (ctx->r3 != ctx->r1) {
        // 0x8079EAC0: nop
    
            goto L_8079EAC8;
    }
    // 0x8079EAC0: nop

    // 0x8079EAC4: break       6
    do_break(2155473604);
L_8079EAC8:
    // 0x8079EAC8: mflo        $t1
    ctx->r9 = lo;
    // 0x8079EACC: mfhi        $v1
    ctx->r3 = hi;
    // 0x8079EAD0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8079EAD4: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x8079EAD8: div         $zero, $v0, $t0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r8)));
    // 0x8079EADC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8079EAE0: sh          $t2, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r10;
    // 0x8079EAE4: bne         $t0, $zero, L_8079EAF0
    if (ctx->r8 != 0) {
        // 0x8079EAE8: nop
    
            goto L_8079EAF0;
    }
    // 0x8079EAE8: nop

    // 0x8079EAEC: break       7
    do_break(2155473644);
L_8079EAF0:
    // 0x8079EAF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8079EAF4: bne         $t0, $at, L_8079EB08
    if (ctx->r8 != ctx->r1) {
        // 0x8079EAF8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8079EB08;
    }
    // 0x8079EAF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8079EAFC: bne         $v0, $at, L_8079EB08
    if (ctx->r2 != ctx->r1) {
        // 0x8079EB00: nop
    
            goto L_8079EB08;
    }
    // 0x8079EB00: nop

    // 0x8079EB04: break       6
    do_break(2155473668);
L_8079EB08:
    // 0x8079EB08: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x8079EB0C: mflo        $v0
    ctx->r2 = lo;
    // 0x8079EB10: bne         $at, $zero, L_8079EAA0
    if (ctx->r1 != 0) {
        // 0x8079EB14: nop
    
            goto L_8079EAA0;
    }
    // 0x8079EB14: nop

L_8079EB18:
    // 0x8079EB18: jr          $ra
    // 0x8079EB1C: nop

    return;
    // 0x8079EB1C: nop

;}
RECOMP_FUNC void func_806AB244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AB244: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AB248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AB24C: jal         0x806AB0A0
    // 0x806AB250: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806AB0A0(rdram, ctx);
        goto after_0;
    // 0x806AB250: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806AB254: beq         $v0, $zero, L_806AB27C
    if (ctx->r2 == 0) {
        // 0x806AB258: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806AB27C;
    }
    // 0x806AB258: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806AB25C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AB260: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806AB264: jal         0x806AB72C
    // 0x806AB268: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806AB72C(rdram, ctx);
        goto after_1;
    // 0x806AB268: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x806AB26C: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(592, 0X2FF8) << 16);
    // 0x806AB270: lwc1        $f4, -0x2428($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(592, 0X2FF8));
    // 0x806AB274: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x806AB278: swc1        $f4, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->f4.u32l;
L_806AB27C:
    // 0x806AB27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AB280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AB284: jr          $ra
    // 0x806AB288: nop

    return;
    // 0x806AB288: nop

;}
RECOMP_FUNC void func_8067F5D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067F5D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067F5DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067F5E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067F5E4: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8067F5E8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8067F5EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8067F5F0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8067F5F4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8067F5F8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8067F5FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8067F600: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8067F604: jal         0x80065954
    // 0x8067F608: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8067F608: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    after_0:
    // 0x8067F60C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8067F610: lh          $t7, 0x1F0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1F0);
    // 0x8067F614: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8067F618: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8067F61C: bnel        $t7, $at, L_8067F648
    if (ctx->r15 != ctx->r1) {
        // 0x8067F620: lw          $a1, 0x34($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X34);
            goto L_8067F648;
    }
    goto skip_0;
    // 0x8067F620: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x8067F624: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8067F628: jal         0x80067D5C
    // 0x8067F62C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_1;
    // 0x8067F62C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8067F630: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    // 0x8067F634: jal         0x80067F78
    // 0x8067F638: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_2;
    // 0x8067F638: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8067F63C: b           L_8067F660
    // 0x8067F640: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_8067F660;
    // 0x8067F640: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8067F644: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
L_8067F648:
    // 0x8067F648: jal         0x80067D5C
    // 0x8067F64C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_3;
    // 0x8067F64C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8067F650: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    // 0x8067F654: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8067F658: jal         0x800678F0
    // 0x8067F65C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x8067F65C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
L_8067F660:
    // 0x8067F660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067F664: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067F668: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067F66C: jr          $ra
    // 0x8067F670: nop

    return;
    // 0x8067F670: nop

;}
RECOMP_FUNC void func_8001AF28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AF28: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001AF2C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001AF30: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8001AF34: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8001AF38: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001AF3C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8001AF40: beq         $a2, $zero, L_8001AF5C
    if (ctx->r6 == 0) {
        // 0x8001AF44: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_8001AF5C;
    }
    // 0x8001AF44: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001AF48: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001AF4C: sllv        $t8, $t6, $a1
    ctx->r24 = S32(ctx->r14 << (ctx->r5 & 31));
    // 0x8001AF50: or          $v0, $a0, $t8
    ctx->r2 = ctx->r4 | ctx->r24;
    // 0x8001AF54: jr          $ra
    // 0x8001AF58: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x8001AF58: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_8001AF5C:
    // 0x8001AF5C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001AF60: sllv        $t1, $t9, $a1
    ctx->r9 = S32(ctx->r25 << (ctx->r5 & 31));
    // 0x8001AF64: nor         $t2, $t1, $zero
    ctx->r10 = ~(ctx->r9 | 0);
    // 0x8001AF68: and         $v0, $a0, $t2
    ctx->r2 = ctx->r4 & ctx->r10;
    // 0x8001AF6C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8001AF70: jr          $ra
    // 0x8001AF74: nop

    return;
    // 0x8001AF74: nop

    // 0x8001AF78: nop

    // 0x8001AF7C: nop

;}
RECOMP_FUNC void func_80735DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735DE4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80735DE8: lui         $a1, 0x8074
    ctx->r5 = S32(RELOC_HI16(736, 0X3840) << 16);
    // 0x80735DEC: addiu       $a1, $a1, -0x6D60
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(736, 0X3840));
    // 0x80735DF0: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80735DF4: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80735DF8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80735DFC: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x80735E00: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x80735E04: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x80735E08: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80735E0C: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x80735E10: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80735E14: bne         $at, $zero, L_80735E34
    if (ctx->r1 != 0) {
        // 0x80735E18: slti        $at, $t2, 0x19
        ctx->r1 = SIGNED(ctx->r10) < 0X19 ? 1 : 0;
            goto L_80735E34;
    }
    // 0x80735E18: slti        $at, $t2, 0x19
    ctx->r1 = SIGNED(ctx->r10) < 0X19 ? 1 : 0;
    // 0x80735E1C: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80735E20: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x80735E24: bne         $at, $zero, L_80735E34
    if (ctx->r1 != 0) {
        // 0x80735E28: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_80735E34;
    }
    // 0x80735E28: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x80735E2C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80735E30: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80735E34:
    // 0x80735E34: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x80735E38: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x80735E3C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80735E40: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(736, 0X3150) << 16);
    // 0x80735E44: addiu       $t7, $t7, -0x7450
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(736, 0X3150));
    // 0x80735E48: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x80735E4C: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80735E50: jr          $ra
    // 0x80735E54: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    return;
    // 0x80735E54: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_80704F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80704F08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80704F0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80704F10: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80704F14: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80704F18: jal         0x8004700C
    // 0x80704F1C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80704F1C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80704F20: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80704F24: beq         $v0, $zero, L_80705260
    if (ctx->r2 == 0) {
        // 0x80704F28: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_80705260;
    }
    // 0x80704F28: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80704F2C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80704F30: nop

    // 0x80704F34: swc1        $f12, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f12.u32l;
    // 0x80704F38: lw          $a0, 0x38($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X38);
    // 0x80704F3C: beq         $a0, $zero, L_80704F48
    if (ctx->r4 == 0) {
        // 0x80704F40: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_80704F48;
    }
    // 0x80704F40: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80704F44: sw          $t6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r14;
L_80704F48:
    // 0x80704F48: lw          $a0, 0x40($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X40);
    // 0x80704F4C: beq         $a0, $zero, L_80704F58
    if (ctx->r4 == 0) {
        // 0x80704F50: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_80704F58;
    }
    // 0x80704F50: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x80704F54: sw          $t7, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r15;
L_80704F58:
    // 0x80704F58: lhu         $t8, 0xC($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0XC);
    // 0x80704F5C: addiu       $at, $zero, 0x4607
    ctx->r1 = ADD32(0, 0X4607);
    // 0x80704F60: bnel        $t8, $at, L_8070500C
    if (ctx->r24 != ctx->r1) {
        // 0x80704F64: lw          $t5, 0x38($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X38);
            goto L_8070500C;
    }
    goto skip_0;
    // 0x80704F64: lw          $t5, 0x38($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X38);
    skip_0:
    // 0x80704F68: lw          $a0, 0x38($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X38);
    // 0x80704F6C: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x80704F70: beql        $at, $zero, L_8070500C
    if (ctx->r1 == 0) {
        // 0x80704F74: lw          $t5, 0x38($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X38);
            goto L_8070500C;
    }
    goto skip_1;
    // 0x80704F74: lw          $t5, 0x38($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X38);
    skip_1:
    // 0x80704F78: beq         $a0, $zero, L_80705008
    if (ctx->r4 == 0) {
        // 0x80704F7C: lui         $at, 0x4380
        ctx->r1 = S32(0X4380 << 16);
            goto L_80705008;
    }
    // 0x80704F7C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80704F80: sw          $zero, 0x138($a3)
    MEM_W(0X138, ctx->r7) = 0;
    // 0x80704F84: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80704F88: lwc1        $f4, 0x84($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X84);
    // 0x80704F8C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80704F90: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80704F94: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80704F98: nop

    // 0x80704F9C: bc1fl       L_80704FAC
    if (!c1cs) {
        // 0x80704FA0: lwc1        $f2, 0x4($v1)
        ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
            goto L_80704FAC;
    }
    goto skip_2;
    // 0x80704FA0: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    skip_2:
    // 0x80704FA4: sw          $t9, 0x138($a3)
    MEM_W(0X138, ctx->r7) = ctx->r25;
    // 0x80704FA8: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
L_80704FAC:
    // 0x80704FAC: lwc1        $f0, 0x3C($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80704FB0: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80704FB4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80704FB8: nop

    // 0x80704FBC: bc1fl       L_80704FE4
    if (!c1cs) {
        // 0x80704FC0: add.s       $f10, $f2, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
            goto L_80704FE4;
    }
    goto skip_3;
    // 0x80704FC0: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
    skip_3:
    // 0x80704FC4: lw          $t1, 0x138($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X138);
    // 0x80704FC8: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80704FCC: bnel        $t1, $zero, L_80704FE4
    if (ctx->r9 != 0) {
        // 0x80704FD0: add.s       $f10, $f2, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
            goto L_80704FE4;
    }
    goto skip_4;
    // 0x80704FD0: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
    skip_4:
    // 0x80704FD4: sw          $t2, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r10;
    // 0x80704FD8: lwc1        $f0, 0x3C($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80704FDC: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80704FE0: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
L_80704FE4:
    // 0x80704FE4: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80704FE8: nop

    // 0x80704FEC: bc1fl       L_8070500C
    if (!c1cs) {
        // 0x80704FF0: lw          $t5, 0x38($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X38);
            goto L_8070500C;
    }
    goto skip_5;
    // 0x80704FF0: lw          $t5, 0x38($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X38);
    skip_5:
    // 0x80704FF4: lw          $t3, 0x138($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X138);
    // 0x80704FF8: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80704FFC: beql        $t3, $zero, L_8070500C
    if (ctx->r11 == 0) {
        // 0x80705000: lw          $t5, 0x38($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X38);
            goto L_8070500C;
    }
    goto skip_6;
    // 0x80705000: lw          $t5, 0x38($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X38);
    skip_6:
    // 0x80705004: sw          $t4, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r12;
L_80705008:
    // 0x80705008: lw          $t5, 0x38($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X38);
L_8070500C:
    // 0x8070500C: bnel        $t5, $zero, L_80705230
    if (ctx->r13 != 0) {
        // 0x80705010: addiu       $a2, $a3, 0xC4
        ctx->r6 = ADD32(ctx->r7, 0XC4);
            goto L_80705230;
    }
    goto skip_7;
    // 0x80705010: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
    skip_7:
    // 0x80705014: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x80705018: beq         $v0, $zero, L_80705028
    if (ctx->r2 == 0) {
        // 0x8070501C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80705028;
    }
    // 0x8070501C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80705020: sw          $t6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r14;
    // 0x80705024: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80705028:
    // 0x80705028: bnel        $v0, $zero, L_80705230
    if (ctx->r2 != 0) {
        // 0x8070502C: addiu       $a2, $a3, 0xC4
        ctx->r6 = ADD32(ctx->r7, 0XC4);
            goto L_80705230;
    }
    goto skip_8;
    // 0x8070502C: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
    skip_8:
    // 0x80705030: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    // 0x80705034: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(709, 0X3628) << 16);
    // 0x80705038: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8070503C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80705040: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80705044: lw          $t8, 0x6A98($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(709, 0X3628));
    // 0x80705048: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x8070504C: sw          $t0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r8;
    // 0x80705050: beq         $at, $zero, L_80705068
    if (ctx->r1 == 0) {
        // 0x80705054: sw          $t8, 0x28($v1)
        MEM_W(0X28, ctx->r3) = ctx->r24;
            goto L_80705068;
    }
    // 0x80705054: sw          $t8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r24;
    // 0x80705058: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8070505C: sw          $t9, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r25;
    // 0x80705060: b           L_80705098
    // 0x80705064: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80705098;
    // 0x80705064: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80705068:
    // 0x80705068: lw          $t1, 0x10($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X10);
    // 0x8070506C: beql        $t1, $zero, L_8070509C
    if (ctx->r9 == 0) {
        // 0x80705070: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_8070509C;
    }
    goto skip_9;
    // 0x80705070: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    skip_9:
    // 0x80705074: lw          $t2, 0x40($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X40);
    // 0x80705078: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
    // 0x8070507C: bnel        $t2, $zero, L_8070509C
    if (ctx->r10 != 0) {
        // 0x80705080: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_8070509C;
    }
    goto skip_10;
    // 0x80705080: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    skip_10:
    // 0x80705084: swc1        $f12, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f12.u32l;
    // 0x80705088: swc1        $f12, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f12.u32l;
    // 0x8070508C: lw          $t3, 0x24($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X24);
    // 0x80705090: addiu       $v0, $t3, 0x1
    ctx->r2 = ADD32(ctx->r11, 0X1);
    // 0x80705094: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
L_80705098:
    // 0x80705098: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
L_8070509C:
    // 0x8070509C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807050A0: lwc1        $f16, 0x50($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X50);
    // 0x807050A4: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x807050A8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x807050AC: nop

    // 0x807050B0: bc1fl       L_80705120
    if (!c1cs) {
        // 0x807050B4: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80705120;
    }
    goto skip_11;
    // 0x807050B4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_11:
    // 0x807050B8: bne         $at, $zero, L_8070511C
    if (ctx->r1 != 0) {
        // 0x807050BC: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_8070511C;
    }
    // 0x807050BC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x807050C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807050C4: lwc1        $f4, 0xC8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x807050C8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x807050CC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x807050D0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807050D4: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x807050D8: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x807050DC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x807050E0: nop

    // 0x807050E4: bc1fl       L_807050F8
    if (!c1cs) {
        // 0x807050E8: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_807050F8;
    }
    goto skip_12;
    // 0x807050E8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_12:
    // 0x807050EC: swc1        $f12, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f12.u32l;
    // 0x807050F0: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x807050F4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_807050F8:
    // 0x807050F8: nop

    // 0x807050FC: bc1fl       L_80705110
    if (!c1cs) {
        // 0x80705100: lwc1        $f10, 0x50($a3)
        ctx->f10.u32l = MEM_W(ctx->r7, 0X50);
            goto L_80705110;
    }
    goto skip_13;
    // 0x80705100: lwc1        $f10, 0x50($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X50);
    skip_13:
    // 0x80705104: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    // 0x80705108: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8070510C: lwc1        $f10, 0x50($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X50);
L_80705110:
    // 0x80705110: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80705114: swc1        $f16, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f16.u32l;
    // 0x80705118: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
L_8070511C:
    // 0x8070511C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_80705120:
    // 0x80705120: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80705124: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80705128: bnel        $v0, $at, L_807051B0
    if (ctx->r2 != ctx->r1) {
        // 0x8070512C: slti        $at, $v0, 0x16
        ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
            goto L_807051B0;
    }
    goto skip_14;
    // 0x8070512C: slti        $at, $v0, 0x16
    ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
    skip_14:
    // 0x80705130: lw          $t5, 0x44($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X44);
    // 0x80705134: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
    // 0x80705138: bnel        $t5, $zero, L_807051B0
    if (ctx->r13 != 0) {
        // 0x8070513C: slti        $at, $v0, 0x16
        ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
            goto L_807051B0;
    }
    goto skip_15;
    // 0x8070513C: slti        $at, $v0, 0x16
    ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
    skip_15:
    // 0x80705140: lw          $t6, 0x138($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X138);
    // 0x80705144: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X3728) << 16);
    // 0x80705148: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8070514C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80705150: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80705154: lwc1        $f18, 0x6B98($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X3728));
    // 0x80705158: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8070515C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80705160: swc1        $f12, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f12.u32l;
    // 0x80705164: swc1        $f2, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f2.u32l;
    // 0x80705168: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x8070516C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80705170: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x80705174: sw          $t0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r8;
    // 0x80705178: sw          $t8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r24;
    // 0x8070517C: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x80705180: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x80705184: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80705188: jal         0x80067BBC
    // 0x8070518C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8070518C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80705190: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x80705194: jal         0x80067818
    // 0x80705198: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80705198: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8070519C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x807051A0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x807051A4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x807051A8: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    // 0x807051AC: slti        $at, $v0, 0x16
    ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
L_807051B0:
    // 0x807051B0: bne         $at, $zero, L_8070522C
    if (ctx->r1 != 0) {
        // 0x807051B4: addiu       $t2, $zero, 0xA
        ctx->r10 = ADD32(0, 0XA);
            goto L_8070522C;
    }
    // 0x807051B4: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x807051B8: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
    // 0x807051BC: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x807051C0: sw          $zero, 0x40($v1)
    MEM_W(0X40, ctx->r3) = 0;
    // 0x807051C4: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x807051C8: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
    // 0x807051CC: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x807051D0: sw          $t2, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r10;
    // 0x807051D4: lhu         $t3, 0xC($a3)
    ctx->r11 = MEM_HU(ctx->r7, 0XC);
    // 0x807051D8: addiu       $at, $zero, 0x4607
    ctx->r1 = ADD32(0, 0X4607);
    // 0x807051DC: swc1        $f12, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f12.u32l;
    // 0x807051E0: bne         $t3, $at, L_807051EC
    if (ctx->r11 != ctx->r1) {
        // 0x807051E4: addiu       $t4, $zero, 0x64
        ctx->r12 = ADD32(0, 0X64);
            goto L_807051EC;
    }
    // 0x807051E4: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x807051E8: sw          $t4, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r12;
L_807051EC:
    // 0x807051EC: lw          $t5, 0x18($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X18);
    // 0x807051F0: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x807051F4: bnel        $at, $zero, L_80705230
    if (ctx->r1 != 0) {
        // 0x807051F8: addiu       $a2, $a3, 0xC4
        ctx->r6 = ADD32(ctx->r7, 0XC4);
            goto L_80705230;
    }
    goto skip_16;
    // 0x807051F8: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
    skip_16:
    // 0x807051FC: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x80705200: lhu         $v0, 0xC($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0XC);
    // 0x80705204: addiu       $at, $zero, 0x4605
    ctx->r1 = ADD32(0, 0X4605);
    // 0x80705208: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8070520C: beq         $v0, $at, L_8070521C
    if (ctx->r2 == ctx->r1) {
        // 0x80705210: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8070521C;
    }
    // 0x80705210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80705214: addiu       $at, $zero, 0x461E
    ctx->r1 = ADD32(0, 0X461E);
    // 0x80705218: bne         $v0, $at, L_8070522C
    if (ctx->r2 != ctx->r1) {
        // 0x8070521C: addiu       $a2, $zero, 0x9
        ctx->r6 = ADD32(0, 0X9);
            goto L_8070522C;
    }
L_8070521C:
    // 0x8070521C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80705220: jal         0x80705A5C
    // 0x80705224: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80705A5C(rdram, ctx);
        goto after_3;
    // 0x80705224: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_3:
    // 0x80705228: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_8070522C:
    // 0x8070522C: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
L_80705230:
    // 0x80705230: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80705234: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80705238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8070523C: jal         0x80048F84
    // 0x80705240: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x80705240: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_4:
    // 0x80705244: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80705248: jal         0x80048F84
    // 0x8070524C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_5;
    // 0x8070524C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80705250: jal         0x8070384C
    // 0x80705254: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8070384C(rdram, ctx);
        goto after_6;
    // 0x80705254: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x80705258: jal         0x80703F10
    // 0x8070525C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80703F10(rdram, ctx);
        goto after_7;
    // 0x8070525C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_7:
L_80705260:
    // 0x80705260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80705264: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80705268: jr          $ra
    // 0x8070526C: nop

    return;
    // 0x8070526C: nop

;}
RECOMP_FUNC void func_806D3DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D3DA0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806D3DA4: lui         $t6, 0x806D
    ctx->r14 = S32(RELOC_HI16(616, 0XB84) << 16);
    // 0x806D3DA8: addiu       $t6, $t6, 0x3B34
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(616, 0XB84));
    // 0x806D3DAC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806D3DB0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806D3DB4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    // 0x806D3DB8: jr          $ra
    // 0x806D3DBC: sb          $t9, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r25;
    return;
    // 0x806D3DBC: sb          $t9, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_80067E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067E68: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80067E6C: addiu       $v0, $v1, -0x6A50
    ctx->r2 = ADD32(ctx->r3, -0X6A50);
    // 0x80067E70: jr          $ra
    // 0x80067E74: sw          $a0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r4;
    return;
    // 0x80067E74: sw          $a0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_8067BCCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067BCCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067BCD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067BCD4: lbu         $v0, 0x158($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X158);
    // 0x8067BCD8: lui         $t7, 0x8068
    ctx->r15 = S32(RELOC_HI16(541, 0X3C18) << 16);
    // 0x8067BCDC: bgtz        $v0, L_8067BD20
    if (SIGNED(ctx->r2) > 0) {
        // 0x8067BCE0: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8067BD20;
    }
    // 0x8067BCE0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8067BCE4: lw          $v0, 0x154($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X154);
    // 0x8067BCE8: bnel        $v0, $zero, L_8067BCF8
    if (ctx->r2 != 0) {
        // 0x8067BCEC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8067BCF8;
    }
    goto skip_0;
    // 0x8067BCEC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_0:
    // 0x8067BCF0: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // 0x8067BCF4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8067BCF8:
    // 0x8067BCF8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8067BCFC: sw          $v0, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r2;
    // 0x8067BD00: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8067BD04: lw          $t7, -0x2738($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(541, 0X3C18));
    // 0x8067BD08: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(541, 0X3C78) << 16);
    // 0x8067BD0C: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8067BD10: sw          $t7, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r15;
    // 0x8067BD14: lbu         $t8, -0x26D8($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(541, 0X3C78));
    // 0x8067BD18: b           L_8067BD24
    // 0x8067BD1C: sb          $t8, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r24;
        goto L_8067BD24;
    // 0x8067BD1C: sb          $t8, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r24;
L_8067BD20:
    // 0x8067BD20: sb          $t9, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r25;
L_8067BD24:
    // 0x8067BD24: jal         0x8067C1D4
    // 0x8067BD28: nop

    func_8067C1D4(rdram, ctx);
        goto after_0;
    // 0x8067BD28: nop

    after_0:
    // 0x8067BD2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067BD30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067BD34: jr          $ra
    // 0x8067BD38: nop

    return;
    // 0x8067BD38: nop

;}
RECOMP_FUNC void func_80446D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446D40: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446D44: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80446D48: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80446D4C: lw          $v1, 0x30($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X30);
    // 0x80446D50: addiu       $v0, $a1, 0x3C0
    ctx->r2 = ADD32(ctx->r5, 0X3C0);
    // 0x80446D54: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80446D58: beq         $at, $zero, L_80446D68
    if (ctx->r1 == 0) {
        // 0x80446D5C: nop
    
            goto L_80446D68;
    }
    // 0x80446D5C: nop

    // 0x80446D60: jr          $ra
    // 0x80446D64: addiu       $v0, $zero, 0x780
    ctx->r2 = ADD32(0, 0X780);
    return;
    // 0x80446D64: addiu       $v0, $zero, 0x780
    ctx->r2 = ADD32(0, 0X780);
L_80446D68:
    // 0x80446D68: jr          $ra
    // 0x80446D6C: nop

    return;
    // 0x80446D6C: nop

;}
RECOMP_FUNC void func_804473F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804473F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804473FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80447400: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80447404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80447408: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8044740C: bne         $a2, $zero, L_8044743C
    if (ctx->r6 != 0) {
        // 0x80447410: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_8044743C;
    }
    // 0x80447410: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80447414: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80447418: lw          $v1, 0xF4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XF4);
    // 0x8044741C: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80447420: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80447424: bne         $at, $zero, L_8044747C
    if (ctx->r1 != 0) {
        // 0x80447428: sw          $t7, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r15;
            goto L_8044747C;
    }
    // 0x80447428: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8044742C: jal         0x80446038
    // 0x80447430: nop

    func_80446038(rdram, ctx);
        goto after_0;
    // 0x80447430: nop

    after_0:
    // 0x80447434: b           L_80447480
    // 0x80447438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80447480;
    // 0x80447438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044743C:
    // 0x8044743C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80447440: bnel        $a2, $at, L_8044746C
    if (ctx->r6 != ctx->r1) {
        // 0x80447444: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8044746C;
    }
    goto skip_0;
    // 0x80447444: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80447448: jal         0x80445FD4
    // 0x8044744C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80445FD4(rdram, ctx);
        goto after_1;
    // 0x8044744C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80447450: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80447454: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447458: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8044745C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447460: b           L_8044747C
    // 0x80447464: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_8044747C;
    // 0x80447464: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    // 0x80447468: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8044746C:
    // 0x8044746C: bnel        $a2, $at, L_80447480
    if (ctx->r6 != ctx->r1) {
        // 0x80447470: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80447480;
    }
    goto skip_1;
    // 0x80447470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80447474: jal         0x80446038
    // 0x80447478: nop

    func_80446038(rdram, ctx);
        goto after_2;
    // 0x80447478: nop

    after_2:
L_8044747C:
    // 0x8044747C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80447480:
    // 0x80447480: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447484: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80447488: jr          $ra
    // 0x8044748C: nop

    return;
    // 0x8044748C: nop

;}
RECOMP_FUNC void func_8051EEA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051EEA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051EEA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051EEA8: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8051EEAC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8051EEB0: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x8051EEB4: bne         $at, $zero, L_8051EEC4
    if (ctx->r1 != 0) {
        // 0x8051EEB8: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_8051EEC4;
    }
    // 0x8051EEB8: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8051EEBC: jal         0x8051EF30
    // 0x8051EEC0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8051EF30(rdram, ctx);
        goto after_0;
    // 0x8051EEC0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
L_8051EEC4:
    // 0x8051EEC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051EEC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051EECC: jr          $ra
    // 0x8051EED0: nop

    return;
    // 0x8051EED0: nop

;}
RECOMP_FUNC void func_80029B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029B00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80029B04: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80029B08: jr          $ra
    // 0x80029B0C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x80029B0C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void func_80033DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033DD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033DDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033DE0: jal         0x80021B44
    // 0x80033DE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021B44(rdram, ctx);
        goto after_0;
    // 0x80033DE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80033DE8: bne         $v0, $zero, L_80033E00
    if (ctx->r2 != 0) {
        // 0x80033DEC: nop
    
            goto L_80033E00;
    }
    // 0x80033DEC: nop

    // 0x80033DF0: jal         0x80033DA4
    // 0x80033DF4: nop

    func_80033DA4(rdram, ctx);
        goto after_1;
    // 0x80033DF4: nop

    after_1:
    // 0x80033DF8: b           L_80033E44
    // 0x80033DFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033E44;
    // 0x80033DFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80033E00:
    // 0x80033E00: jal         0x80033494
    // 0x80033E04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80033494(rdram, ctx);
        goto after_2;
    // 0x80033E04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80033E08: bne         $v0, $zero, L_80033E20
    if (ctx->r2 != 0) {
        // 0x80033E0C: nop
    
            goto L_80033E20;
    }
    // 0x80033E0C: nop

    // 0x80033E10: jal         0x80033DA4
    // 0x80033E14: nop

    func_80033DA4(rdram, ctx);
        goto after_3;
    // 0x80033E14: nop

    after_3:
    // 0x80033E18: b           L_80033E44
    // 0x80033E1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033E44;
    // 0x80033E1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80033E20:
    // 0x80033E20: jal         0x80033160
    // 0x80033E24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80033160(rdram, ctx);
        goto after_4;
    // 0x80033E24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80033E28: beql        $v0, $zero, L_80033E44
    if (ctx->r2 == 0) {
        // 0x80033E2C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80033E44;
    }
    goto skip_0;
    // 0x80033E2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80033E30: jal         0x80033DA4
    // 0x80033E34: nop

    func_80033DA4(rdram, ctx);
        goto after_5;
    // 0x80033E34: nop

    after_5:
    // 0x80033E38: b           L_80033E44
    // 0x80033E3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033E44;
    // 0x80033E3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80033E40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80033E44:
    // 0x80033E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033E48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033E4C: jr          $ra
    // 0x80033E50: nop

    return;
    // 0x80033E50: nop

;}
RECOMP_FUNC void func_80435470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80435470: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80435474: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80435478: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8043547C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80435480: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80435484: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80435488: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8043548C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80435490: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80435494: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80435498: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8043549C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804354A0: addiu       $s2, $zero, 0x168
    ctx->r18 = ADD32(0, 0X168);
    // 0x804354A4: lw          $s1, 0x134C($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X134C);
    // 0x804354A8: sll         $t6, $s1, 3
    ctx->r14 = S32(ctx->r17 << 3);
    // 0x804354AC: addu        $s0, $v1, $t6
    ctx->r16 = ADD32(ctx->r3, ctx->r14);
    // 0x804354B0: slti        $at, $s1, 0x3C
    ctx->r1 = SIGNED(ctx->r17) < 0X3C ? 1 : 0;
    // 0x804354B4: beq         $at, $zero, L_804355AC
    if (ctx->r1 == 0) {
        // 0x804354B8: addiu       $s0, $s0, 0x106C
        ctx->r16 = ADD32(ctx->r16, 0X106C);
            goto L_804355AC;
    }
    // 0x804354B8: addiu       $s0, $s0, 0x106C
    ctx->r16 = ADD32(ctx->r16, 0X106C);
    // 0x804354BC: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(71, 0X2AE4) << 16);
    // 0x804354C0: lwc1        $f30, 0x6594($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(71, 0X2AE4));
    // 0x804354C4: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(71, 0X2AE8) << 16);
    // 0x804354C8: lwc1        $f26, 0x6598($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(71, 0X2AE8));
    // 0x804354CC: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(71, 0X2AEC) << 16);
    // 0x804354D0: lwc1        $f24, 0x659C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(71, 0X2AEC));
L_804354D4:
    // 0x804354D4: jal         0x800653D8
    // 0x804354D8: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x804354D8: nop

    after_0:
    // 0x804354DC: div         $zero, $v0, $s2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r18)));
    // 0x804354E0: mfhi        $t7
    ctx->r15 = hi;
    // 0x804354E4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x804354E8: lwc1        $f20, 0x0($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X0);
    // 0x804354EC: lwc1        $f22, 0x4($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X4);
    // 0x804354F0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804354F4: bne         $s2, $zero, L_80435500
    if (ctx->r18 != 0) {
        // 0x804354F8: nop
    
            goto L_80435500;
    }
    // 0x804354F8: nop

    // 0x804354FC: break       7
    do_break(2151896316);
L_80435500:
    // 0x80435500: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80435504: bne         $s2, $at, L_80435518
    if (ctx->r18 != ctx->r1) {
        // 0x80435508: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80435518;
    }
    // 0x80435508: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8043550C: bne         $v0, $at, L_80435518
    if (ctx->r2 != ctx->r1) {
        // 0x80435510: nop
    
            goto L_80435518;
    }
    // 0x80435510: nop

    // 0x80435514: break       6
    do_break(2151896340);
L_80435518:
    // 0x80435518: mov.s       $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
    // 0x8043551C: jal         0x80066E88
    // 0x80435520: addiu       $s0, $s0, 0x0
    ctx->r16 = ADD32(ctx->r16, 0X0);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80435520: addiu       $s0, $s0, 0x0
    ctx->r16 = ADD32(ctx->r16, 0X0);
    after_1:
    // 0x80435524: mul.s       $f6, $f30, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x80435528: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x8043552C: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x80435530: nop

    // 0x80435534: bc1fl       L_80435548
    if (!c1cs) {
        // 0x80435538: c.lt.s      $f20, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
            goto L_80435548;
    }
    goto skip_0;
    // 0x80435538: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    skip_0:
    // 0x8043553C: b           L_80435558
    // 0x80435540: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
        goto L_80435558;
    // 0x80435540: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    // 0x80435544: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
L_80435548:
    // 0x80435548: nop

    // 0x8043554C: bc1f        L_80435558
    if (!c1cs) {
        // 0x80435550: nop
    
            goto L_80435558;
    }
    // 0x80435550: nop

    // 0x80435554: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
L_80435558:
    // 0x80435558: jal         0x80066DE4
    // 0x8043555C: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8043555C: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    after_2:
    // 0x80435560: mul.s       $f8, $f30, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x80435564: addiu       $s1, $s1, 0x32
    ctx->r17 = ADD32(ctx->r17, 0X32);
    // 0x80435568: slti        $at, $s1, 0x3C
    ctx->r1 = SIGNED(ctx->r17) < 0X3C ? 1 : 0;
    // 0x8043556C: add.s       $f22, $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x80435570: c.lt.s      $f24, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f24.fl < ctx->f22.fl;
    // 0x80435574: nop

    // 0x80435578: bc1fl       L_8043558C
    if (!c1cs) {
        // 0x8043557C: c.lt.s      $f22, $f26
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
            goto L_8043558C;
    }
    goto skip_1;
    // 0x8043557C: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
    skip_1:
    // 0x80435580: b           L_8043559C
    // 0x80435584: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
        goto L_8043559C;
    // 0x80435584: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x80435588: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
L_8043558C:
    // 0x8043558C: nop

    // 0x80435590: bc1fl       L_804355A0
    if (!c1cs) {
        // 0x80435594: swc1        $f20, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
            goto L_804355A0;
    }
    goto skip_2;
    // 0x80435594: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    skip_2:
    // 0x80435598: mov.s       $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    ctx->f22.fl = ctx->f26.fl;
L_8043559C:
    // 0x8043559C: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
L_804355A0:
    // 0x804355A0: swc1        $f22, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f22.u32l;
    // 0x804355A4: bne         $at, $zero, L_804354D4
    if (ctx->r1 != 0) {
        // 0x804355A8: addiu       $s0, $s0, 0x190
        ctx->r16 = ADD32(ctx->r16, 0X190);
            goto L_804354D4;
    }
    // 0x804355A8: addiu       $s0, $s0, 0x190
    ctx->r16 = ADD32(ctx->r16, 0X190);
L_804355AC:
    // 0x804355AC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x804355B0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x804355B4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x804355B8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x804355BC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x804355C0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x804355C4: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x804355C8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x804355CC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x804355D0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x804355D4: jr          $ra
    // 0x804355D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x804355D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_804B6C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6C7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804B6C80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B6C84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B6C88: jal         0x804B6BF8
    // 0x804B6C8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804B6BF8(rdram, ctx);
        goto after_0;
    // 0x804B6C8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804B6C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B6C94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6C98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804B6C9C: jal         0x804B6FF0
    // 0x804B6CA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804B6FF0(rdram, ctx);
        goto after_1;
    // 0x804B6CA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x804B6CA4: lw          $t6, 0x1E4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E4);
    // 0x804B6CA8: bnel        $t6, $zero, L_804B6CBC
    if (ctx->r14 != 0) {
        // 0x804B6CAC: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_804B6CBC;
    }
    goto skip_0;
    // 0x804B6CAC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x804B6CB0: jal         0x8005FD1C
    // 0x804B6CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FD1C(rdram, ctx);
        goto after_2;
    // 0x804B6CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804B6CB8: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_804B6CBC:
    // 0x804B6CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B6CC0: lhu         $t7, 0xC($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XC);
    // 0x804B6CC4: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x804B6CC8: jal         0x80057978
    // 0x804B6CCC: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
    func_80057978(rdram, ctx);
        goto after_3;
    // 0x804B6CCC: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
    after_3:
    // 0x804B6CD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804B6CD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B6CD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804B6CDC: jr          $ra
    // 0x804B6CE0: nop

    return;
    // 0x804B6CE0: nop

;}
RECOMP_FUNC void func_8067291C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067291C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80672920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80672924: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80672928: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067292C: jal         0x80672750
    // 0x80672930: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80672750(rdram, ctx);
        goto after_0;
    // 0x80672930: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80672934: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80672938: jal         0x806728F4
    // 0x8067293C: lw          $a0, 0x1F4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X1F4);
    func_806728F4(rdram, ctx);
        goto after_1;
    // 0x8067293C: lw          $a0, 0x1F4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X1F4);
    after_1:
    // 0x80672940: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80672944: lw          $t6, 0x1E0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1E0);
    // 0x80672948: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8067294C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80672950: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x80672954: bne         $at, $zero, L_80672964
    if (ctx->r1 != 0) {
        // 0x80672958: sw          $t7, 0x1E0($a2)
        MEM_W(0X1E0, ctx->r6) = ctx->r15;
            goto L_80672964;
    }
    // 0x80672958: sw          $t7, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r15;
    // 0x8067295C: jal         0x80672C80
    // 0x80672960: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80672C80(rdram, ctx);
        goto after_2;
    // 0x80672960: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
L_80672964:
    // 0x80672964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80672968: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067296C: jr          $ra
    // 0x80672970: nop

    return;
    // 0x80672970: nop

;}
RECOMP_FUNC void func_806D90A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D90A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D90A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D90AC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D90B0: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x806D90B4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x806D90B8: bne         $t6, $zero, L_806D90E8
    if (ctx->r14 != 0) {
        // 0x806D90BC: nop
    
            goto L_806D90E8;
    }
    // 0x806D90BC: nop

    // 0x806D90C0: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x806D90C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x806D90C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806D90CC: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x806D90D0: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x806D90D4: jalr        $t9
    // 0x806D90D8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806D90D8: nop

    after_0:
    // 0x806D90DC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806D90E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D90E4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_806D90E8:
    // 0x806D90E8: jal         0x806D8EF8
    // 0x806D90EC: nop

    func_806D8EF8(rdram, ctx);
        goto after_1;
    // 0x806D90EC: nop

    after_1:
    // 0x806D90F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D90F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D90F8: jr          $ra
    // 0x806D90FC: nop

    return;
    // 0x806D90FC: nop

;}
RECOMP_FUNC void func_806D94F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D94F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D94F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D94FC: jal         0x806D9478
    // 0x806D9500: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806D9478(rdram, ctx);
        goto after_0;
    // 0x806D9500: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D9504: beq         $v0, $zero, L_806D9580
    if (ctx->r2 == 0) {
        // 0x806D9508: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806D9580;
    }
    // 0x806D9508: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D950C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806D9510: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806D9514: lui         $t7, 0x806E
    ctx->r15 = S32(RELOC_HI16(628, 0X730) << 16);
    // 0x806D9518: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806D951C: addiu       $t7, $t7, -0x6A10
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(628, 0X730));
    // 0x806D9520: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806D9524: lui         $t9, 0x806E
    ctx->r25 = S32(RELOC_HI16(628, 0X60C) << 16);
    // 0x806D9528: lui         $t2, 0x806E
    ctx->r10 = S32(RELOC_HI16(628, 0X27C) << 16);
    // 0x806D952C: addiu       $t9, $t9, -0x6B34
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(628, 0X60C));
    // 0x806D9530: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x806D9534: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x806D9538: addiu       $t2, $t2, -0x6EC4
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(628, 0X27C));
    // 0x806D953C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806D9540: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x806D9544: sh          $t0, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r8;
    // 0x806D9548: sb          $t1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r9;
    // 0x806D954C: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806D9550: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x806D9554: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x806D9558: jal         0x806D944C
    // 0x806D955C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806D944C(rdram, ctx);
        goto after_1;
    // 0x806D955C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x806D9560: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D9564: lui         $t3, 0x806E
    ctx->r11 = S32(RELOC_HI16(628, 0X4F0) << 16);
    // 0x806D9568: addiu       $t3, $t3, -0x6C50
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(628, 0X4F0));
    // 0x806D956C: jal         0x806D9064
    // 0x806D9570: sw          $t3, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r11;
    func_806D9064(rdram, ctx);
        goto after_2;
    // 0x806D9570: sw          $t3, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r11;
    after_2:
    // 0x806D9574: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x806D9578: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806D957C: sb          $t4, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r12;
L_806D9580:
    // 0x806D9580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D9584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D9588: jr          $ra
    // 0x806D958C: nop

    return;
    // 0x806D958C: nop

;}
RECOMP_FUNC void func_806B1EC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1EC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B1EC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806B1ECC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806B1ED0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806B1ED4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806B1ED8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806B1EDC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806B1EE0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B1EE4: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x806B1EE8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806B1EEC: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x806B1EF0: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x806B1EF4: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x806B1EF8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x806B1EFC: jal         0x806B195C
    // 0x806B1F00: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_806B195C(rdram, ctx);
        goto after_0;
    // 0x806B1F00: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x806B1F04: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806B1F08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B1F0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B1F10: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B1F14: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x806B1F18: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x806B1F1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806B1F20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B1F24: jr          $ra
    // 0x806B1F28: nop

    return;
    // 0x806B1F28: nop

;}
RECOMP_FUNC void func_807AE928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE928: jr          $ra
    // 0x807AE92C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807AE92C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805AA920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA920: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x805AA924: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x805AA928: addiu       $at, $zero, 0x407D
    ctx->r1 = ADD32(0, 0X407D);
    // 0x805AA92C: beq         $a0, $at, L_805AA944
    if (ctx->r4 == ctx->r1) {
        // 0x805AA930: addiu       $at, $zero, 0x407E
        ctx->r1 = ADD32(0, 0X407E);
            goto L_805AA944;
    }
    // 0x805AA930: addiu       $at, $zero, 0x407E
    ctx->r1 = ADD32(0, 0X407E);
    // 0x805AA934: beq         $a0, $at, L_805AA944
    if (ctx->r4 == ctx->r1) {
        // 0x805AA938: addiu       $at, $zero, 0x407F
        ctx->r1 = ADD32(0, 0X407F);
            goto L_805AA944;
    }
    // 0x805AA938: addiu       $at, $zero, 0x407F
    ctx->r1 = ADD32(0, 0X407F);
    // 0x805AA93C: bne         $a0, $at, L_805AA94C
    if (ctx->r4 != ctx->r1) {
        // 0x805AA940: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805AA94C;
    }
    // 0x805AA940: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805AA944:
    // 0x805AA944: jr          $ra
    // 0x805AA948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x805AA948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805AA94C:
    // 0x805AA94C: jr          $ra
    // 0x805AA950: nop

    return;
    // 0x805AA950: nop

;}
RECOMP_FUNC void func_806DFCF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DFCF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806DFCFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806DFD00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806DFD04: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806DFD08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806DFD0C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x806DFD10: jal         0x80062748
    // 0x806DFD14: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80062748(rdram, ctx);
        goto after_0;
    // 0x806DFD14: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x806DFD18: jal         0x806DF754
    // 0x806DFD1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DF754(rdram, ctx);
        goto after_1;
    // 0x806DFD1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806DFD20: jal         0x806DFBD4
    // 0x806DFD24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DFBD4(rdram, ctx);
        goto after_2;
    // 0x806DFD24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806DFD28: jal         0x806DF504
    // 0x806DFD2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DF504(rdram, ctx);
        goto after_3;
    // 0x806DFD2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806DFD30: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806DFD34: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806DFD38: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x806DFD3C: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x806DFD40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806DFD44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806DFD48: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806DFD4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806DFD50: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806DFD54: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x806DFD58: nop

    // 0x806DFD5C: bc1fl       L_806DFD70
    if (!c1cs) {
        // 0x806DFD60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806DFD70;
    }
    goto skip_0;
    // 0x806DFD60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806DFD64: jal         0x806E0398
    // 0x806DFD68: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806E0398(rdram, ctx);
        goto after_4;
    // 0x806DFD68: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806DFD6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806DFD70:
    // 0x806DFD70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806DFD74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806DFD78: jr          $ra
    // 0x806DFD7C: nop

    return;
    // 0x806DFD7C: nop

;}
RECOMP_FUNC void func_8000DAE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DAE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000DAEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000DAF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000DAF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000DAF8: jal         0x8000D9D0
    // 0x8000DAFC: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    func_8000D9D0(rdram, ctx);
        goto after_0;
    // 0x8000DAFC: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_0:
    // 0x8000DB00: jal         0x8000BE94
    // 0x8000DB04: addiu       $a0, $s0, 0x98
    ctx->r4 = ADD32(ctx->r16, 0X98);
    func_8000BE94(rdram, ctx);
        goto after_1;
    // 0x8000DB04: addiu       $a0, $s0, 0x98
    ctx->r4 = ADD32(ctx->r16, 0X98);
    after_1:
    // 0x8000DB08: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x8000DB0C: lbu         $a0, 0x4($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X4);
    // 0x8000DB10: ori         $t9, $t7, 0x40
    ctx->r25 = ctx->r15 | 0X40;
    // 0x8000DB14: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x8000DB18: andi        $t0, $t9, 0x7F
    ctx->r8 = ctx->r25 & 0X7F;
    // 0x8000DB1C: jal         0x800066E4
    // 0x8000DB20: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
    func_800066E4(rdram, ctx);
        goto after_2;
    // 0x8000DB20: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
    after_2:
    // 0x8000DB24: beq         $v0, $zero, L_8000DB34
    if (ctx->r2 == 0) {
        // 0x8000DB28: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8000DB34;
    }
    // 0x8000DB28: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8000DB2C: jal         0x8000678C
    // 0x8000DB30: lbu         $a0, 0x4($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X4);
    func_8000678C(rdram, ctx);
        goto after_3;
    // 0x8000DB30: lbu         $a0, 0x4($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X4);
    after_3:
L_8000DB34:
    // 0x8000DB34: jal         0x800066A8
    // 0x8000DB38: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    func_800066A8(rdram, ctx);
        goto after_4;
    // 0x8000DB38: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    after_4:
    // 0x8000DB3C: beq         $v0, $zero, L_8000DB4C
    if (ctx->r2 == 0) {
        // 0x8000DB40: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_8000DB4C;
    }
    // 0x8000DB40: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8000DB44: jal         0x8000675C
    // 0x8000DB48: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    func_8000675C(rdram, ctx);
        goto after_5;
    // 0x8000DB48: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    after_5:
L_8000DB4C:
    // 0x8000DB4C: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8000DB50: addiu       $v1, $v1, 0x4D10
    ctx->r3 = ADD32(ctx->r3, 0X4D10);
    // 0x8000DB54: lh          $t1, 0x213A($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X213A);
    // 0x8000DB58: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x8000DB5C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000DB60: bnel        $v0, $t1, L_8000DB74
    if (ctx->r2 != ctx->r9) {
        // 0x8000DB64: lh          $t3, 0x2146($v1)
        ctx->r11 = MEM_H(ctx->r3, 0X2146);
            goto L_8000DB74;
    }
    goto skip_0;
    // 0x8000DB64: lh          $t3, 0x2146($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2146);
    skip_0:
    // 0x8000DB68: b           L_8000DB80
    // 0x8000DB6C: sw          $t2, 0x211C($v1)
    MEM_W(0X211C, ctx->r3) = ctx->r10;
        goto L_8000DB80;
    // 0x8000DB6C: sw          $t2, 0x211C($v1)
    MEM_W(0X211C, ctx->r3) = ctx->r10;
    // 0x8000DB70: lh          $t3, 0x2146($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2146);
L_8000DB74:
    // 0x8000DB74: bnel        $v0, $t3, L_8000DB84
    if (ctx->r2 != ctx->r11) {
        // 0x8000DB78: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000DB84;
    }
    goto skip_1;
    // 0x8000DB78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8000DB7C: sw          $zero, 0x211C($v1)
    MEM_W(0X211C, ctx->r3) = 0;
L_8000DB80:
    // 0x8000DB80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000DB84:
    // 0x8000DB84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000DB88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000DB8C: jr          $ra
    // 0x8000DB90: nop

    return;
    // 0x8000DB90: nop

;}
RECOMP_FUNC void func_8042A2EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042A2EC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042A2F0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8042A2F4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8042A2F8: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8042A2FC: lh          $a1, 0x1C($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X1C);
    // 0x8042A300: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8042A304: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8042A308: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8042A30C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8042A310: lw          $v1, 0x10($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X10);
    // 0x8042A314: beq         $t9, $zero, L_8042A3B8
    if (ctx->r25 == 0) {
        // 0x8042A318: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_8042A3B8;
    }
    // 0x8042A318: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8042A31C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8042A320: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
L_8042A324:
    // 0x8042A324: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8042A328: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8042A32C: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8042A330: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8042A334: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8042A338: mflo        $t3
    ctx->r11 = lo;
    // 0x8042A33C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8042A340: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8042A344: sh          $t5, -0x10($a2)
    MEM_H(-0X10, ctx->r6) = ctx->r13;
    // 0x8042A348: lw          $t7, -0x8($a3)
    ctx->r15 = MEM_W(ctx->r7, -0X8);
    // 0x8042A34C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8042A350: multu       $t7, $a0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8042A354: mflo        $t8
    ctx->r24 = lo;
    // 0x8042A358: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8042A35C: lh          $t2, 0x2($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X2);
    // 0x8042A360: sh          $t2, -0xE($a2)
    MEM_H(-0XE, ctx->r6) = ctx->r10;
    // 0x8042A364: lw          $t3, -0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, -0X8);
    // 0x8042A368: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8042A36C: multu       $t3, $a0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8042A370: mflo        $t4
    ctx->r12 = lo;
    // 0x8042A374: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x8042A378: lh          $t7, 0x4($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X4);
    // 0x8042A37C: sh          $zero, -0xA($a2)
    MEM_H(-0XA, ctx->r6) = 0;
    // 0x8042A380: sh          $t7, -0xC($a2)
    MEM_H(-0XC, ctx->r6) = ctx->r15;
    // 0x8042A384: lh          $t6, -0x4($a3)
    ctx->r14 = MEM_H(ctx->r7, -0X4);
    // 0x8042A388: sh          $t6, -0x8($a2)
    MEM_H(-0X8, ctx->r6) = ctx->r14;
    // 0x8042A38C: lh          $t8, -0x2($a3)
    ctx->r24 = MEM_H(ctx->r7, -0X2);
    // 0x8042A390: sb          $zero, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = 0;
    // 0x8042A394: sb          $a1, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r5;
    // 0x8042A398: sb          $zero, -0x3($a2)
    MEM_B(-0X3, ctx->r6) = 0;
    // 0x8042A39C: sb          $zero, -0x4($a2)
    MEM_B(-0X4, ctx->r6) = 0;
    // 0x8042A3A0: sh          $t8, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r24;
    // 0x8042A3A4: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8042A3A8: sltu        $at, $t0, $t9
    ctx->r1 = ctx->r8 < ctx->r25 ? 1 : 0;
    // 0x8042A3AC: bnel        $at, $zero, L_8042A324
    if (ctx->r1 != 0) {
        // 0x8042A3B0: lw          $t2, 0x0($a3)
        ctx->r10 = MEM_W(ctx->r7, 0X0);
            goto L_8042A324;
    }
    goto skip_0;
    // 0x8042A3B0: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x8042A3B4: lh          $a1, 0x1C($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X1C);
L_8042A3B8:
    // 0x8042A3B8: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
    // 0x8042A3BC: sh          $t2, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r10;
    // 0x8042A3C0: lh          $t3, 0x1C($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X1C);
    // 0x8042A3C4: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x8042A3C8: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x8042A3CC: bne         $at, $zero, L_8042A3D8
    if (ctx->r1 != 0) {
        // 0x8042A3D0: nop
    
            goto L_8042A3D8;
    }
    // 0x8042A3D0: nop

    // 0x8042A3D4: sh          $zero, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = 0;
L_8042A3D8:
    // 0x8042A3D8: jr          $ra
    // 0x8042A3DC: nop

    return;
    // 0x8042A3DC: nop

;}
RECOMP_FUNC void func_805319F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805319F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805319FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80531A00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80531A04: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80531A08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80531A0C: jal         0x80530E78
    // 0x80531A10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80530E78(rdram, ctx);
        goto after_0;
    // 0x80531A10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80531A14: lw          $v0, 0x264($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X264);
    // 0x80531A18: beql        $v0, $zero, L_80531A74
    if (ctx->r2 == 0) {
        // 0x80531A1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80531A74;
    }
    goto skip_0;
    // 0x80531A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80531A20: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x80531A24: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80531A28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80531A2C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80531A30: lwc1        $f4, 0x268($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X268);
    // 0x80531A34: lui         $a3, 0xBE4C
    ctx->r7 = S32(0XBE4C << 16);
    // 0x80531A38: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x80531A3C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80531A40: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80531A44: lwc1        $f10, 0x10($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80531A48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80531A4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80531A50: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80531A54: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80531A58: jal         0x80531924
    // 0x80531A5C: nop

    func_80531924(rdram, ctx);
        goto after_1;
    // 0x80531A5C: nop

    after_1:
    // 0x80531A60: beq         $v0, $zero, L_80531A70
    if (ctx->r2 == 0) {
        // 0x80531A64: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80531A70;
    }
    // 0x80531A64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80531A68: jal         0x80531FB8
    // 0x80531A6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80531FB8(rdram, ctx);
        goto after_2;
    // 0x80531A6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
L_80531A70:
    // 0x80531A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80531A74:
    // 0x80531A74: jal         0x8005D87C
    // 0x80531A78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8005D87C(rdram, ctx);
        goto after_3;
    // 0x80531A78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80531A7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80531A80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80531A84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80531A88: jr          $ra
    // 0x80531A8C: nop

    return;
    // 0x80531A8C: nop

;}
RECOMP_FUNC void func_8076D318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D318: jr          $ra
    // 0x8076D31C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8076D31C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806652E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806652E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806652EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806652F0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x806652F4: lui         $t6, 0x8066
    ctx->r14 = S32(RELOC_HI16(504, 0X2B44) << 16);
    // 0x806652F8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x806652FC: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80665300: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80665304: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80665308: lw          $t0, 0x84($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X84);
    // 0x8066530C: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x80665310: lw          $t6, 0x7814($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(504, 0X2B44));
    // 0x80665314: sw          $t7, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r15;
    // 0x80665318: sw          $t8, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r24;
    // 0x8066531C: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
    // 0x80665320: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x80665324: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2C6C) << 16);
    // 0x80665328: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8066532C: beq         $t9, $zero, L_8066534C
    if (ctx->r25 == 0) {
        // 0x80665330: sll         $v0, $t0, 2
        ctx->r2 = S32(ctx->r8 << 2);
            goto L_8066534C;
    }
    // 0x80665330: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80665334: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80665338: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2C6C) << 16);
    // 0x8066533C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80665340: lwc1        $f4, 0x793C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2C6C));
    // 0x80665344: b           L_8066535C
    // 0x80665348: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
        goto L_8066535C;
    // 0x80665348: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
L_8066534C:
    // 0x8066534C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80665350: lwc1        $f6, 0x793C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2C6C));
    // 0x80665354: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80665358: swc1        $f8, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f8.u32l;
L_8066535C:
    // 0x8066535C: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2BD0) << 16);
    // 0x80665360: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80665364: lwc1        $f10, 0x78A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2BD0));
    // 0x80665368: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2C04) << 16);
    // 0x8066536C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80665370: swc1        $f10, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f10.u32l;
    // 0x80665374: lwc1        $f16, 0x78D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2C04));
    // 0x80665378: subu        $a0, $t1, $t0
    ctx->r4 = SUB32(ctx->r9, ctx->r8);
    // 0x8066537C: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80665380: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x80665384: jal         0x80067D5C
    // 0x80665388: swc1        $f16, 0xEC($a3)
    MEM_W(0XEC, ctx->r7) = ctx->f16.u32l;
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x80665388: swc1        $f16, 0xEC($a3)
    MEM_W(0XEC, ctx->r7) = ctx->f16.u32l;
    after_0:
    // 0x8066538C: addiu       $a0, $zero, 0x209
    ctx->r4 = ADD32(0, 0X209);
    // 0x80665390: jal         0x80067818
    // 0x80665394: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80665394: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80665398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066539C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806653A0: jr          $ra
    // 0x806653A4: nop

    return;
    // 0x806653A4: nop

;}
RECOMP_FUNC void func_8067BC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067BC30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067BC34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067BC38: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067BC3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8067BC40: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8067BC44: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x8067BC48: lwc1        $f12, 0x2C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8067BC4C: bnel        $t6, $at, L_8067BC5C
    if (ctx->r14 != ctx->r1) {
        // 0x8067BC50: add.s       $f0, $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
            goto L_8067BC5C;
    }
    goto skip_0;
    // 0x8067BC50: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    skip_0:
    // 0x8067BC54: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8067BC58: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
L_8067BC5C:
    // 0x8067BC5C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8067BC60: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8067BC64: swc1        $f12, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f12.u32l;
    // 0x8067BC68: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8067BC6C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8067BC70: nop

    // 0x8067BC74: bc1fl       L_8067BC94
    if (!c1cs) {
        // 0x8067BC78: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_8067BC94;
    }
    goto skip_1;
    // 0x8067BC78: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_1:
    // 0x8067BC7C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_8067BC80:
    // 0x8067BC80: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8067BC84: nop

    // 0x8067BC88: bc1tl       L_8067BC80
    if (c1cs) {
        // 0x8067BC8C: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8067BC80;
    }
    goto skip_2;
    // 0x8067BC8C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x8067BC90: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_8067BC94:
    // 0x8067BC94: nop

    // 0x8067BC98: bc1f        L_8067BCB4
    if (!c1cs) {
        // 0x8067BC9C: nop
    
            goto L_8067BCB4;
    }
    // 0x8067BC9C: nop

    // 0x8067BCA0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_8067BCA4:
    // 0x8067BCA4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8067BCA8: nop

    // 0x8067BCAC: bc1tl       L_8067BCA4
    if (c1cs) {
        // 0x8067BCB0: add.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_8067BCA4;
    }
    goto skip_3;
    // 0x8067BCB0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    skip_3:
L_8067BCB4:
    // 0x8067BCB4: jal         0x80679F80
    // 0x8067BCB8: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    func_80679F80(rdram, ctx);
        goto after_0;
    // 0x8067BCB8: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    after_0:
    // 0x8067BCBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067BCC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067BCC4: jr          $ra
    // 0x8067BCC8: nop

    return;
    // 0x8067BCC8: nop

;}
RECOMP_FUNC void func_8051EE20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051EE20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051EE24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051EE28: jal         0x8051EC54
    // 0x8051EE2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8051EC54(rdram, ctx);
        goto after_0;
    // 0x8051EE2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8051EE30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8051EE34: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8051EE38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8051EE3C: jal         0x80048F84
    // 0x8051EE40: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8051EE40: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_1:
    // 0x8051EE44: beq         $v0, $zero, L_8051EE90
    if (ctx->r2 == 0) {
        // 0x8051EE48: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_8051EE90;
    }
    // 0x8051EE48: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8051EE4C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8051EE50: sw          $t6, -0x76C0($at)
    MEM_W(-0X76C0, ctx->r1) = ctx->r14;
    // 0x8051EE54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8051EE58: jal         0x8051EF30
    // 0x8051EE5C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8051EF30(rdram, ctx);
        goto after_2;
    // 0x8051EE5C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x8051EE60: addiu       $a0, $zero, 0x213
    ctx->r4 = ADD32(0, 0X213);
    // 0x8051EE64: jal         0x80067818
    // 0x8051EE68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8051EE68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8051EE6C: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x8051EE70: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8051EE74: sb          $t7, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r15;
    // 0x8051EE78: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8051EE7C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8051EE80: sb          $t8, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r24;
    // 0x8051EE84: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8051EE88: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8051EE8C: sb          $t9, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r25;
L_8051EE90:
    // 0x8051EE90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051EE94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051EE98: jr          $ra
    // 0x8051EE9C: nop

    return;
    // 0x8051EE9C: nop

;}
RECOMP_FUNC void func_806D070C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D070C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806D0710: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D0714: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806D0718: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D071C: jal         0x80047090
    // 0x806D0720: addiu       $a0, $zero, 0x45A6
    ctx->r4 = ADD32(0, 0X45A6);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806D0720: addiu       $a0, $zero, 0x45A6
    ctx->r4 = ADD32(0, 0X45A6);
    after_0:
    // 0x806D0724: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x806D0728: bne         $v0, $at, L_806D0738
    if (ctx->r2 != ctx->r1) {
        // 0x806D072C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_806D0738;
    }
    // 0x806D072C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x806D0730: b           L_806D07E4
    // 0x806D0734: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806D07E4;
    // 0x806D0734: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D0738:
    // 0x806D0738: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806D073C: lui         $at, 0x45A6
    ctx->r1 = S32(0X45A6 << 16);
    // 0x806D0740: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x806D0744: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x806D0748: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x806D074C: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x806D0750: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x806D0754: jal         0x8004613C
    // 0x806D0758: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806D0758: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    after_1:
    // 0x806D075C: lhu         $v1, 0x22($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X22);
    // 0x806D0760: bne         $v0, $zero, L_806D0770
    if (ctx->r2 != 0) {
        // 0x806D0764: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806D0770;
    }
    // 0x806D0764: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806D0768: b           L_806D07E4
    // 0x806D076C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806D07E4;
    // 0x806D076C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D0770:
    // 0x806D0770: lhu         $t8, 0xE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XE);
    // 0x806D0774: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x806D0778: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x806D077C: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x806D0780: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x806D0784: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    // 0x806D0788: jal         0x80047F9C
    // 0x806D078C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806D078C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x806D0790: jal         0x806D0E40
    // 0x806D0794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D0E40(rdram, ctx);
        goto after_3;
    // 0x806D0794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806D0798: bne         $v0, $zero, L_806D07A8
    if (ctx->r2 != 0) {
        // 0x806D079C: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_806D07A8;
    }
    // 0x806D079C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x806D07A0: b           L_806D07E4
    // 0x806D07A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806D07E4;
    // 0x806D07A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D07A8:
    // 0x806D07A8: lui         $at, 0xC3A2
    ctx->r1 = S32(0XC3A2 << 16);
    // 0x806D07AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806D07B0: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x806D07B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D07B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x806D07BC: sb          $t1, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r9;
    // 0x806D07C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D07C4: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x806D07C8: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x806D07CC: jal         0x8005FDC4
    // 0x806D07D0: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x806D07D0: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x806D07D4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x806D07D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806D07DC: lw          $t3, 0x1F4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1F4);
    // 0x806D07E0: sw          $s0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r16;
L_806D07E4:
    // 0x806D07E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D07E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D07EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806D07F0: jr          $ra
    // 0x806D07F4: nop

    return;
    // 0x806D07F4: nop

;}
RECOMP_FUNC void func_80035ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035ED8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80035EDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80035EE0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80035EE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80035EE8: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80035EEC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80035EF0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80035EF4: jal         0x800356E8
    // 0x80035EF8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800356E8(rdram, ctx);
        goto after_0;
    // 0x80035EF8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80035EFC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80035F00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80035F04: addiu       $a0, $sp, 0x5F
    ctx->r4 = ADD32(ctx->r29, 0X5F);
    // 0x80035F08: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80035F0C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80035F10: jal         0x800359EC
    // 0x80035F14: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    func_800359EC(rdram, ctx);
        goto after_1;
    // 0x80035F14: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80035F18: bne         $v0, $zero, L_80035FD8
    if (ctx->r2 != 0) {
        // 0x80035F1C: addiu       $a0, $sp, 0x5F
        ctx->r4 = ADD32(ctx->r29, 0X5F);
            goto L_80035FD8;
    }
    // 0x80035F1C: addiu       $a0, $sp, 0x5F
    ctx->r4 = ADD32(ctx->r29, 0X5F);
    // 0x80035F20: addiu       $t7, $zero, 0x39
    ctx->r15 = ADD32(0, 0X39);
    // 0x80035F24: addiu       $t8, $zero, 0x47
    ctx->r24 = ADD32(0, 0X47);
    // 0x80035F28: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80035F2C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80035F30: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80035F34: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80035F38: jal         0x80035A70
    // 0x80035F3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80035A70(rdram, ctx);
        goto after_2;
    // 0x80035F3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80035F40: bnel        $v0, $zero, L_80035FDC
    if (ctx->r2 != 0) {
        // 0x80035F44: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80035FDC;
    }
    goto skip_0;
    // 0x80035F44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80035F48: jal         0x800653D8
    // 0x80035F4C: nop

    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x80035F4C: nop

    after_3:
    // 0x80035F50: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80035F54: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80035F58: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80035F5C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80035F60: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80035F64: lw          $t3, -0x152C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X152C);
    // 0x80035F68: and         $t0, $v0, $t9
    ctx->r8 = ctx->r2 & ctx->r25;
    // 0x80035F6C: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80035F70: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x80035F74: lbu         $v1, 0x0($t4)
    ctx->r3 = MEM_BU(ctx->r12, 0X0);
    // 0x80035F78: bne         $v1, $at, L_80035FB8
    if (ctx->r3 != ctx->r1) {
        // 0x80035F7C: sb          $v1, 0x5F($sp)
        MEM_B(0X5F, ctx->r29) = ctx->r3;
            goto L_80035FB8;
    }
    // 0x80035F7C: sb          $v1, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r3;
    // 0x80035F80: lw          $v0, 0x140($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X140);
    // 0x80035F84: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x80035F88: bnel        $v0, $zero, L_80035FAC
    if (ctx->r2 != 0) {
        // 0x80035F8C: sb          $t8, 0x5F($sp)
        MEM_B(0X5F, ctx->r29) = ctx->r24;
            goto L_80035FAC;
    }
    goto skip_1;
    // 0x80035F8C: sb          $t8, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r24;
    skip_1:
    // 0x80035F90: jal         0x800653D8
    // 0x80035F94: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x80035F94: nop

    after_4:
    // 0x80035F98: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x80035F9C: addiu       $t7, $t6, 0x6
    ctx->r15 = ADD32(ctx->r14, 0X6);
    // 0x80035FA0: b           L_80035FD8
    // 0x80035FA4: sw          $t7, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->r15;
        goto L_80035FD8;
    // 0x80035FA4: sw          $t7, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->r15;
    // 0x80035FA8: sb          $t8, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r24;
L_80035FAC:
    // 0x80035FAC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80035FB0: b           L_80035FD8
    // 0x80035FB4: sw          $v0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->r2;
        goto L_80035FD8;
    // 0x80035FB4: sw          $v0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->r2;
L_80035FB8:
    // 0x80035FB8: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x80035FBC: beq         $v1, $at, L_80035FD0
    if (ctx->r3 == ctx->r1) {
        // 0x80035FC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80035FD0;
    }
    // 0x80035FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80035FC4: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80035FC8: bnel        $v1, $at, L_80035FDC
    if (ctx->r3 != ctx->r1) {
        // 0x80035FCC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80035FDC;
    }
    goto skip_2;
    // 0x80035FCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
L_80035FD0:
    // 0x80035FD0: jal         0x80035834
    // 0x80035FD4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80035834(rdram, ctx);
        goto after_5;
    // 0x80035FD4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
L_80035FD8:
    // 0x80035FD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80035FDC:
    // 0x80035FDC: lbu         $v0, 0x5F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X5F);
    // 0x80035FE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80035FE4: jr          $ra
    // 0x80035FE8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80035FE8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80080DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080DF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80080DF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80080DFC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80080E00: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80080E04: jal         0x80082730
    // 0x80080E08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    fsin(rdram, ctx);
        goto after_0;
    // 0x80080E08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80080E0C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80080E10: jal         0x8008D250
    // 0x80080E14: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    fcos(rdram, ctx);
        goto after_1;
    // 0x80080E14: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80080E18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80080E1C: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80080E20: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80080E24: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80080E28: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80080E2C: nop

    // 0x80080E30: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80080E34: nop

    // 0x80080E38: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80080E3C: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80080E40: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80080E44: lwc1        $f12, 0x18($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80080E48: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80080E4C: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80080E50: nop

    // 0x80080E54: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80080E58: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80080E5C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80080E60: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80080E64: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80080E68: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80080E6C: lwc1        $f12, 0x28($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80080E70: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80080E74: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80080E78: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x80080E7C: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80080E80: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x80080E84: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80080E88: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80080E8C: lwc1        $f2, 0x34($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80080E90: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80080E94: lwc1        $f12, 0x38($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80080E98: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80080E9C: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80080EA0: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x80080EA4: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80080EA8: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x80080EAC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80080EB0: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80080EB4: nop

    // 0x80080EB8: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80080EBC: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
    // 0x80080EC0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80080EC4: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
    // 0x80080EC8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80080ECC: swc1        $f18, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
    // 0x80080ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80080ED4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80080ED8: jr          $ra
    // 0x80080EDC: nop

    return;
    // 0x80080EDC: nop

;}
RECOMP_FUNC void func_80787EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80787EA4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80787EA8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80787EAC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80787EB0: lw          $v1, 0x43E4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X43E4);
    // 0x80787EB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80787EB8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80787EBC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80787EC0: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x80787EC4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80787EC8: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x80787ECC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80787ED0: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80787ED4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80787ED8: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80787EDC: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80787EE0: sllv        $a1, $t6, $v1
    ctx->r5 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x80787EE4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80787EE8: addu        $t1, $v0, $t7
    ctx->r9 = ADD32(ctx->r2, ctx->r15);
    // 0x80787EEC: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80787EF0: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_80787EF4:
    // 0x80787EF4: lwc1        $f4, 0x4990($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X4990);
    // 0x80787EF8: lwc1        $f6, 0x43E8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X43E8);
    // 0x80787EFC: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80787F00: slti        $at, $t0, 0x16A
    ctx->r1 = SIGNED(ctx->r8) < 0X16A ? 1 : 0;
    // 0x80787F04: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80787F08: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80787F0C: addiu       $t1, $t1, 0x20
    ctx->r9 = ADD32(ctx->r9, 0X20);
    // 0x80787F10: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x80787F14: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80787F18: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80787F1C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80787F20: nop

    // 0x80787F24: sh          $t9, -0x20($t1)
    MEM_H(-0X20, ctx->r9) = ctx->r25;
    // 0x80787F28: lwc1        $f4, 0x43E4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X43E4);
    // 0x80787F2C: lwc1        $f18, 0x498C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X498C);
    // 0x80787F30: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80787F34: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80787F38: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80787F3C: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80787F40: bne         $at, $zero, L_80787EF4
    if (ctx->r1 != 0) {
        // 0x80787F44: sh          $t5, -0x10($t1)
        MEM_H(-0X10, ctx->r9) = ctx->r13;
            goto L_80787EF4;
    }
    // 0x80787F44: sh          $t5, -0x10($t1)
    MEM_H(-0X10, ctx->r9) = ctx->r13;
    // 0x80787F48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80787F4C: lbu         $t6, 0x520C($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X520C);
    // 0x80787F50: addiu       $a2, $v1, 0x520D
    ctx->r6 = ADD32(ctx->r3, 0X520D);
    // 0x80787F54: addiu       $v0, $zero, 0xB5
    ctx->r2 = ADD32(0, 0XB5);
    // 0x80787F58: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80787F5C: sb          $t7, 0x520C($v1)
    MEM_B(0X520C, ctx->r3) = ctx->r15;
    // 0x80787F60: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80787F64: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80787F68:
    // 0x80787F68: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x80787F6C: lbu         $t4, 0x1($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1);
    // 0x80787F70: lbu         $t6, 0x2($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X2);
    // 0x80787F74: or          $t9, $t8, $a0
    ctx->r25 = ctx->r24 | ctx->r4;
    // 0x80787F78: lbu         $t8, 0x3($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X3);
    // 0x80787F7C: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x80787F80: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80787F84: or          $t5, $t4, $a0
    ctx->r13 = ctx->r12 | ctx->r4;
    // 0x80787F88: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x80787F8C: or          $t9, $t8, $a0
    ctx->r25 = ctx->r24 | ctx->r4;
    // 0x80787F90: sb          $t9, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r25;
    // 0x80787F94: sb          $t7, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r15;
    // 0x80787F98: sb          $t5, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r13;
    // 0x80787F9C: bne         $t0, $v0, L_80787F68
    if (ctx->r8 != ctx->r2) {
        // 0x80787FA0: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80787F68;
    }
    // 0x80787FA0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80787FA4: jr          $ra
    // 0x80787FA8: nop

    return;
    // 0x80787FA8: nop

;}
RECOMP_FUNC void func_8005F960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F968: jal         0x8004700C
    // 0x8005F96C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8005F96C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005F970: beq         $v0, $zero, L_8005F99C
    if (ctx->r2 == 0) {
        // 0x8005F974: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005F99C;
    }
    // 0x8005F974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F978: lw          $v1, 0x174($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X174);
    // 0x8005F97C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8005F980: beql        $v1, $zero, L_8005F9A0
    if (ctx->r3 == 0) {
        // 0x8005F984: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005F9A0;
    }
    goto skip_0;
    // 0x8005F984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8005F988: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8005F98C: bnel        $t6, $t7, L_8005F9A0
    if (ctx->r14 != ctx->r15) {
        // 0x8005F990: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005F9A0;
    }
    goto skip_1;
    // 0x8005F990: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8005F994: b           L_8005F9A0
    // 0x8005F998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005F9A0;
    // 0x8005F998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005F99C:
    // 0x8005F99C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005F9A0:
    // 0x8005F9A0: jr          $ra
    // 0x8005F9A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005F9A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805C6CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C6CA4: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x805C6CA8: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x805C6CAC: lw          $t6, 0xA68($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XA68);
    // 0x805C6CB0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x805C6CB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805C6CB8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x805C6CBC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x805C6CC0: lw          $v1, 0xD8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XD8);
    // 0x805C6CC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C6CC8: lw          $t8, 0x70($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X70);
    // 0x805C6CCC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C6CD0: andi        $t9, $v1, 0x7
    ctx->r25 = ctx->r3 & 0X7;
    // 0x805C6CD4: beql        $t8, $zero, L_805C6E20
    if (ctx->r24 == 0) {
        // 0x805C6CD8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_805C6E20;
    }
    goto skip_0;
    // 0x805C6CD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x805C6CDC: bnel        $t9, $zero, L_805C6E20
    if (ctx->r25 != 0) {
        // 0x805C6CE0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_805C6E20;
    }
    goto skip_1;
    // 0x805C6CE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x805C6CE4: lw          $t0, 0x5C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X5C);
    // 0x805C6CE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805C6CEC: beq         $t0, $at, L_805C6E1C
    if (ctx->r8 == ctx->r1) {
        // 0x805C6CF0: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_805C6E1C;
    }
    // 0x805C6CF0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805C6CF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805C6CF8: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x805C6CFC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805C6D00: nop

    // 0x805C6D04: bc1fl       L_805C6E20
    if (!c1cs) {
        // 0x805C6D08: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_805C6E20;
    }
    goto skip_2;
    // 0x805C6D08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x805C6D0C: lw          $t1, 0x138($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X138);
    // 0x805C6D10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805C6D14: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805C6D18: bne         $t1, $zero, L_805C6D28
    if (ctx->r9 != 0) {
        // 0x805C6D1C: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_805C6D28;
    }
    // 0x805C6D1C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805C6D20: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805C6D24: nop

L_805C6D28:
    // 0x805C6D28: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x805C6D2C: jal         0x80066E88
    // 0x805C6D30: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x805C6D30: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x805C6D34: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x805C6D38: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x805C6D3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805C6D40: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x805C6D44: lwc1        $f18, 0x84($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805C6D48: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805C6D4C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x805C6D50: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x805C6D54: jal         0x80066DE4
    // 0x805C6D58: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x805C6D58: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    after_1:
    // 0x805C6D5C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x805C6D60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C6D64: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x805C6D68: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x805C6D6C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x805C6D70: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x805C6D74: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x805C6D78: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x805C6D7C: jal         0x805C6BC4
    // 0x805C6D80: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    func_805C6BC4(rdram, ctx);
        goto after_2;
    // 0x805C6D80: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x805C6D84: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x805C6D88: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x805C6D8C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x805C6D90: jal         0x805C6BC4
    // 0x805C6D94: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_805C6BC4(rdram, ctx);
        goto after_3;
    // 0x805C6D94: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x805C6D98: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805C6D9C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x805C6DA0: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(447, 0X3BE0) << 16);
    // 0x805C6DA4: lwc1        $f14, -0x5F30($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(447, 0X3BE0));
    // 0x805C6DA8: jal         0x805C6BC4
    // 0x805C6DAC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_805C6BC4(rdram, ctx);
        goto after_4;
    // 0x805C6DAC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x805C6DB0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x805C6DB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x805C6DB8: jal         0x805C6C20
    // 0x805C6DBC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_805C6C20(rdram, ctx);
        goto after_5;
    // 0x805C6DBC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_5:
    // 0x805C6DC0: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x805C6DC4: lui         $t3, 0x805D
    ctx->r11 = S32(RELOC_HI16(447, 0X3B08) << 16);
    // 0x805C6DC8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x805C6DCC: lw          $t3, -0x6008($t3)
    ctx->r11 = MEM_W(ctx->r11, (int16_t)RELOC_LO16(447, 0X3B08));
    // 0x805C6DD0: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x805C6DD4: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x805C6DD8: lw          $t4, -0x76F8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X76F8);
    // 0x805C6DDC: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x805C6DE0: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x805C6DE4: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(447, 0X3BE4) << 16);
    // 0x805C6DE8: lwc1        $f18, -0x5F2C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(447, 0X3BE4));
    // 0x805C6DEC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805C6DF0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x805C6DF4: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x805C6DF8: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x805C6DFC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x805C6E00: lw          $t9, 0x70($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X70);
    // 0x805C6E04: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x805C6E08: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x805C6E0C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x805C6E10: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x805C6E14: jalr        $t9
    // 0x805C6E18: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x805C6E18: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    after_6:
L_805C6E1C:
    // 0x805C6E1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805C6E20:
    // 0x805C6E20: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805C6E24: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x805C6E28: jr          $ra
    // 0x805C6E2C: nop

    return;
    // 0x805C6E2C: nop

;}
RECOMP_FUNC void func_8043F5E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F5E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043F5E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043F5EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043F5F0: jal         0x8004700C
    // 0x8043F5F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8043F5F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8043F5F8: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8043F5FC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x8043F600: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8043F604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043F608: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043F60C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8043F610: jal         0x80442188
    // 0x8043F614: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80442188(rdram, ctx);
        goto after_1;
    // 0x8043F614: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x8043F618: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4E94) << 16);
    // 0x8043F61C: lwc1        $f0, 0x3D94($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4E94));
    // 0x8043F620: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8043F624: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8043F628: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8043F62C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8043F630: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8043F634: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4E98) << 16);
    // 0x8043F638: swc1        $f0, 0x1C24($v1)
    MEM_W(0X1C24, ctx->r3) = ctx->f0.u32l;
    // 0x8043F63C: swc1        $f0, 0x1C28($v1)
    MEM_W(0X1C28, ctx->r3) = ctx->f0.u32l;
    // 0x8043F640: lwc1        $f4, 0x3D98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4E98));
    // 0x8043F644: sw          $zero, 0x2628($v1)
    MEM_W(0X2628, ctx->r3) = 0;
    // 0x8043F648: swc1        $f2, 0x1C88($v1)
    MEM_W(0X1C88, ctx->r3) = ctx->f2.u32l;
    // 0x8043F64C: swc1        $f2, 0x1C8C($v1)
    MEM_W(0X1C8C, ctx->r3) = ctx->f2.u32l;
    // 0x8043F650: beq         $t0, $zero, L_8043F67C
    if (ctx->r8 == 0) {
        // 0x8043F654: swc1        $f4, 0x1C74($v1)
        MEM_W(0X1C74, ctx->r3) = ctx->f4.u32l;
            goto L_8043F67C;
    }
    // 0x8043F654: swc1        $f4, 0x1C74($v1)
    MEM_W(0X1C74, ctx->r3) = ctx->f4.u32l;
    // 0x8043F658: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8043F65C: lwc1        $f8, 0x3C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x8043F660: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8043F664: swc1        $f10, 0x1C80($v1)
    MEM_W(0X1C80, ctx->r3) = ctx->f10.u32l;
    // 0x8043F668: lwc1        $f18, 0x40($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X40);
    // 0x8043F66C: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8043F670: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8043F674: b           L_8043F68C
    // 0x8043F678: swc1        $f4, 0x1C84($v1)
    MEM_W(0X1C84, ctx->r3) = ctx->f4.u32l;
        goto L_8043F68C;
    // 0x8043F678: swc1        $f4, 0x1C84($v1)
    MEM_W(0X1C84, ctx->r3) = ctx->f4.u32l;
L_8043F67C:
    // 0x8043F67C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8043F680: nop

    // 0x8043F684: swc1        $f0, 0x1C80($v1)
    MEM_W(0X1C80, ctx->r3) = ctx->f0.u32l;
    // 0x8043F688: swc1        $f0, 0x1C84($v1)
    MEM_W(0X1C84, ctx->r3) = ctx->f0.u32l;
L_8043F68C:
    // 0x8043F68C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8043F690: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8043F694: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8043F698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043F69C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8043F6A0: jal         0x8043F310
    // 0x8043F6A4: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    func_8043F310(rdram, ctx);
        goto after_2;
    // 0x8043F6A4: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x8043F6A8: jal         0x8043F42C
    // 0x8043F6AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F42C(rdram, ctx);
        goto after_3;
    // 0x8043F6AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8043F6B0: jal         0x8043F1A0
    // 0x8043F6B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F1A0(rdram, ctx);
        goto after_4;
    // 0x8043F6B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8043F6B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043F6BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043F6C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043F6C4: jr          $ra
    // 0x8043F6C8: nop

    return;
    // 0x8043F6C8: nop

;}
RECOMP_FUNC void func_80665518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80665518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066551C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80665520: lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14);
    // 0x80665524: bnel        $t6, $zero, L_8066556C
    if (ctx->r14 != 0) {
        // 0x80665528: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066556C;
    }
    goto skip_0;
    // 0x80665528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066552C: lw          $t7, 0x10($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X10);
    // 0x80665530: lui         $t0, 0x8066
    ctx->r8 = S32(RELOC_HI16(504, 0X2B90) << 16);
    // 0x80665534: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80665538: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8066553C: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x80665540: beq         $at, $zero, L_80665560
    if (ctx->r1 == 0) {
        // 0x80665544: sw          $t8, 0x10($a1)
        MEM_W(0X10, ctx->r5) = ctx->r24;
            goto L_80665560;
    }
    // 0x80665544: sw          $t8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r24;
    // 0x80665548: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8066554C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80665550: lw          $t0, 0x7860($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(504, 0X2B90));
    // 0x80665554: sw          $t1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r9;
    // 0x80665558: b           L_80665568
    // 0x8066555C: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
        goto L_80665568;
    // 0x8066555C: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
L_80665560:
    // 0x80665560: jal         0x80665264
    // 0x80665564: nop

    func_80665264(rdram, ctx);
        goto after_0;
    // 0x80665564: nop

    after_0:
L_80665568:
    // 0x80665568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066556C:
    // 0x8066556C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80665570: jr          $ra
    // 0x80665574: nop

    return;
    // 0x80665574: nop

;}
RECOMP_FUNC void func_8043F150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F150: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043F154: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8043F158: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8043F15C: lw          $t6, 0x1C70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C70);
    // 0x8043F160: addiu       $v1, $v0, 0x1C30
    ctx->r3 = ADD32(ctx->r2, 0X1C30);
    // 0x8043F164: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8043F168: bgez        $t7, L_8043F198
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8043F16C: sw          $t7, 0x1C70($v0)
        MEM_W(0X1C70, ctx->r2) = ctx->r15;
            goto L_8043F198;
    }
    // 0x8043F16C: sw          $t7, 0x1C70($v0)
    MEM_W(0X1C70, ctx->r2) = ctx->r15;
    // 0x8043F170: sw          $t9, 0x1C70($v0)
    MEM_W(0X1C70, ctx->r2) = ctx->r25;
    // 0x8043F174: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_8043F178:
    // 0x8043F178: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8043F17C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8043F180: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8043F184: bgez        $t1, L_8043F190
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8043F188: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_8043F190;
    }
    // 0x8043F188: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8043F18C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8043F190:
    // 0x8043F190: bgez        $a0, L_8043F178
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8043F194: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8043F178;
    }
    // 0x8043F194: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8043F198:
    // 0x8043F198: jr          $ra
    // 0x8043F19C: nop

    return;
    // 0x8043F19C: nop

;}
RECOMP_FUNC void func_80068AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068AB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068AB4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80068AB8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80068ABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068AC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80068AC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80068AC8: sb          $t6, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r14;
    // 0x80068ACC: jal         0x8006863C
    // 0x80068AD0: lw          $a0, 0x3F0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X3F0);
    func_8006863C(rdram, ctx);
        goto after_0;
    // 0x80068AD0: lw          $a0, 0x3F0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X3F0);
    after_0:
    // 0x80068AD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80068AD8: lw          $t9, 0xD0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XD0);
    // 0x80068ADC: jalr        $t9
    // 0x80068AE0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80068AE0: nop

    after_1:
    // 0x80068AE4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80068AE8: jal         0x800688CC
    // 0x80068AEC: sb          $zero, -0x7D76($at)
    MEM_B(-0X7D76, ctx->r1) = 0;
    func_800688CC(rdram, ctx);
        goto after_2;
    // 0x80068AEC: sb          $zero, -0x7D76($at)
    MEM_B(-0X7D76, ctx->r1) = 0;
    after_2:
    // 0x80068AF0: jal         0x8006899C
    // 0x80068AF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8006899C(rdram, ctx);
        goto after_3;
    // 0x80068AF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80068AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80068B04: jr          $ra
    // 0x80068B08: nop

    return;
    // 0x80068B08: nop

;}
RECOMP_FUNC void func_8040EC6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EC6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040EC70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040EC74: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040EC78: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8040EC7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8040EC80: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8040EC84: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8040EC88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040EC8C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8040EC90: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8040EC94: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8040EC98: nop

    // 0x8040EC9C: bc1fl       L_8040ECB0
    if (!c1cs) {
        // 0x8040ECA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040ECB0;
    }
    goto skip_0;
    // 0x8040ECA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8040ECA4: jal         0x8040F0B8
    // 0x8040ECA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8040F0B8(rdram, ctx);
        goto after_0;
    // 0x8040ECA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8040ECAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040ECB0:
    // 0x8040ECB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040ECB4: jr          $ra
    // 0x8040ECB8: nop

    return;
    // 0x8040ECB8: nop

;}
RECOMP_FUNC void func_80050894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050894: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80050898: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005089C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x800508A0: beq         $t7, $zero, L_800508C0
    if (ctx->r15 == 0) {
        // 0x800508A4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800508C0;
    }
    // 0x800508A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800508A8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800508AC: addiu       $a0, $a0, 0x9E0
    ctx->r4 = ADD32(ctx->r4, 0X9E0);
    // 0x800508B0: jal         0x80071380
    // 0x800508B4: addiu       $a1, $zero, 0xF7
    ctx->r5 = ADD32(0, 0XF7);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x800508B4: addiu       $a1, $zero, 0xF7
    ctx->r5 = ADD32(0, 0XF7);
    after_0:
    // 0x800508B8: b           L_80050918
    // 0x800508BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80050918;
    // 0x800508BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800508C0:
    // 0x800508C0: jal         0x800506B4
    // 0x800508C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800506B4(rdram, ctx);
        goto after_1;
    // 0x800508C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800508C8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800508CC: jal         0x8005074C
    // 0x800508D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8005074C(rdram, ctx);
        goto after_2;
    // 0x800508D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800508D4: beq         $v0, $zero, L_80050914
    if (ctx->r2 == 0) {
        // 0x800508D8: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80050914;
    }
    // 0x800508D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800508DC: addiu       $a0, $a0, -0x5A48
    ctx->r4 = ADD32(ctx->r4, -0X5A48);
    // 0x800508E0: jal         0x80057AC0
    // 0x800508E4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_80057AC0(rdram, ctx);
        goto after_3;
    // 0x800508E4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800508E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800508EC: addiu       $a0, $a0, -0x5A48
    ctx->r4 = ADD32(ctx->r4, -0X5A48);
    // 0x800508F0: jal         0x80057BAC
    // 0x800508F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80057BAC(rdram, ctx);
        goto after_4;
    // 0x800508F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x800508F8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800508FC: lh          $t8, -0x5A42($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X5A42);
    // 0x80050900: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80050904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80050908: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8005090C: b           L_80050918
    // 0x80050910: sh          $t9, -0x5A42($at)
    MEM_H(-0X5A42, ctx->r1) = ctx->r25;
        goto L_80050918;
    // 0x80050910: sh          $t9, -0x5A42($at)
    MEM_H(-0X5A42, ctx->r1) = ctx->r25;
L_80050914:
    // 0x80050914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050918:
    // 0x80050918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005091C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80050920: jr          $ra
    // 0x80050924: nop

    return;
    // 0x80050924: nop

;}
RECOMP_FUNC void bootproc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006743C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067440: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80067444: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80067448: addiu       $t7, $t7, 0xDE4
    ctx->r15 = ADD32(ctx->r15, 0XDE4);
    // 0x8006744C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80067450: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80067454: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80067458: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8006745C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80067460: addiu       $a2, $a2, -0x2FE8
    ctx->r6 = ADD32(ctx->r6, -0X2FE8);
    // 0x80067464: addiu       $a1, $a1, -0x4FE8
    ctx->r5 = ADD32(ctx->r5, -0X4FE8);
    // 0x80067468: addiu       $a0, $a0, -0x2FE8
    ctx->r4 = ADD32(ctx->r4, -0X2FE8);
    // 0x8006746C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80067470: jal         0x80081910
    // 0x80067474: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_0;
    // 0x80067474: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80067478: jal         0x80086060
    // 0x8006747C: nop

    osInitialize_recomp(rdram, ctx);
        goto after_1;
    // 0x8006747C: nop

    after_1:
    // 0x80067480: jal         0x80067400
    // 0x80067484: nop

    bootclear(rdram, ctx);
        goto after_2;
    // 0x80067484: nop

    after_2:
    // 0x80067488: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x8006748C: addiu       $t9, $t9, 0xDEC
    ctx->r25 = ADD32(ctx->r25, 0XDEC);
    // 0x80067490: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80067494: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80067498: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8006749C: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x800674A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800674A4: addiu       $a2, $a2, -0x2C18
    ctx->r6 = ADD32(ctx->r6, -0X2C18);
    // 0x800674A8: addiu       $a1, $a1, -0x2E18
    ctx->r5 = ADD32(ctx->r5, -0X2E18);
    // 0x800674AC: addiu       $a0, $a0, -0x2C18
    ctx->r4 = ADD32(ctx->r4, -0X2C18);
    // 0x800674B0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800674B4: jal         0x80081910
    // 0x800674B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_3;
    // 0x800674B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x800674BC: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x800674C0: addiu       $t0, $t0, -0x2C18
    ctx->r8 = ADD32(ctx->r8, -0X2C18);
    // 0x800674C4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800674C8: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x800674CC: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800674D0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800674D4: addiu       $a2, $a2, 0x7284
    ctx->r6 = ADD32(ctx->r6, 0X7284);
    // 0x800674D8: addiu       $a0, $a0, -0x2FC8
    ctx->r4 = ADD32(ctx->r4, -0X2FC8);
    // 0x800674DC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800674E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800674E4: jal         0x80085B10
    // 0x800674E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_4;
    // 0x800674E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x800674EC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800674F0: jal         0x80090CC0
    // 0x800674F4: addiu       $a0, $a0, -0x2FC8
    ctx->r4 = ADD32(ctx->r4, -0X2FC8);
    osStartThread_recomp(rdram, ctx);
        goto after_5;
    // 0x800674F4: addiu       $a0, $a0, -0x2FC8
    ctx->r4 = ADD32(ctx->r4, -0X2FC8);
    after_5:
    // 0x800674F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800674FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80067500: jr          $ra
    // 0x80067504: nop

    return;
    // 0x80067504: nop

;}
RECOMP_FUNC void func_8045F8A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045F8A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045F8A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045F8AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8045F8B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8045F8B4: jal         0x80047090
    // 0x8045F8B8: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8045F8B8: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x8045F8BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8045F8C0: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x8045F8C4: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x8045F8C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8045F8CC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8045F8D0: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x8045F8D4: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8045F8D8: jal         0x8004613C
    // 0x8045F8DC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8045F8DC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    after_1:
    // 0x8045F8E0: lhu         $t7, 0x1E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1E);
    // 0x8045F8E4: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x8045F8E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8045F8EC: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8045F8F0: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x8045F8F4: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8045F8F8: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    // 0x8045F8FC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8045F900: jal         0x80047F9C
    // 0x8045F904: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8045F904: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8045F908: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8045F90C: sb          $zero, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = 0;
    // 0x8045F910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045F914: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8045F918: jr          $ra
    // 0x8045F91C: nop

    return;
    // 0x8045F91C: nop

;}
RECOMP_FUNC void func_805D3438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D3438: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805D343C: jr          $ra
    // 0x805D3440: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    return;
    // 0x805D3440: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_804200B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804200B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804200B4: lui         $t6, 0x8042
    ctx->r14 = S32(RELOC_HI16(29, 0X34A4) << 16);
    // 0x804200B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804200BC: addiu       $t6, $t6, 0xB04
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(29, 0X34A4));
    // 0x804200C0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x804200C4: addiu       $v0, $sp, 0x1C
    ctx->r2 = ADD32(ctx->r29, 0X1C);
    // 0x804200C8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x804200CC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x804200D0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x804200D4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x804200D8: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x804200DC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x804200E0: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x804200E4: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x804200E8: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x804200EC: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x804200F0: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x804200F4: lw          $t9, 0x14C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14C);
    // 0x804200F8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804200FC: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80420100: jal         0x80062684
    // 0x80420104: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x80420104: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    after_0:
    // 0x80420108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042010C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80420110: jr          $ra
    // 0x80420114: nop

    return;
    // 0x80420114: nop

;}
RECOMP_FUNC void func_8043CCF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043CCF0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8043CCF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043CCF8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8043CCFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8043CD00: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x8043CD04: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8043CD08: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8043CD0C: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(89, 0X12F0) << 16);
    // 0x8043CD10: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8043CD14: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x8043CD18: addiu       $t8, $t8, -0x30D0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(89, 0X12F0));
    // 0x8043CD1C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8043CD20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043CD24: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8043CD28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043CD2C: jal         0x8043CEDC
    // 0x8043CD30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8043CEDC(rdram, ctx);
        goto after_0;
    // 0x8043CD30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8043CD34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8043CD38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8043CD3C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8043CD40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8043CD44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8043CD48: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x8043CD4C: lw          $t2, 0x16C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X16C);
    // 0x8043CD50: lui         $t1, 0x8044
    ctx->r9 = S32(RELOC_HI16(89, 0X6D0) << 16);
    // 0x8043CD54: addiu       $t1, $t1, -0x3CF0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(89, 0X6D0));
    // 0x8043CD58: sw          $t1, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r9;
    // 0x8043CD5C: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x8043CD60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043CD64: addiu       $a1, $zero, 0x340
    ctx->r5 = ADD32(0, 0X340);
    // 0x8043CD68: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x8043CD6C: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x8043CD70: jal         0x80045A34
    // 0x8043CD74: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x8043CD74: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x8043CD78: lw          $t4, 0x168($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X168);
    // 0x8043CD7C: lui         $t3, 0x8044
    ctx->r11 = S32(RELOC_HI16(89, 0X1064) << 16);
    // 0x8043CD80: addiu       $t3, $t3, -0x335C
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(89, 0X1064));
    // 0x8043CD84: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8043CD88: sw          $t3, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r11;
    // 0x8043CD8C: lw          $t5, 0x34($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X34);
    // 0x8043CD90: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(89, 0X1354) << 16);
    // 0x8043CD94: lwc1        $f4, -0x306C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(89, 0X1354));
    // 0x8043CD98: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x8043CD9C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8043CDA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8043CDA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8043CDA8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8043CDAC: swc1        $f4, 0x324($v0)
    MEM_W(0X324, ctx->r2) = ctx->f4.u32l;
L_8043CDB0:
    // 0x8043CDB0: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x8043CDB4: slti        $at, $a1, 0x63
    ctx->r1 = SIGNED(ctx->r5) < 0X63 ? 1 : 0;
    // 0x8043CDB8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x8043CDBC: sw          $v1, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r3;
    // 0x8043CDC0: sw          $v1, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->r3;
    // 0x8043CDC4: bne         $at, $zero, L_8043CDB0
    if (ctx->r1 != 0) {
        // 0x8043CDC8: sw          $v1, -0xC($a0)
        MEM_W(-0XC, ctx->r4) = ctx->r3;
            goto L_8043CDB0;
    }
    // 0x8043CDC8: sw          $v1, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->r3;
    // 0x8043CDCC: sw          $v1, 0x194($v0)
    MEM_W(0X194, ctx->r2) = ctx->r3;
    // 0x8043CDD0: sw          $v1, 0x190($v0)
    MEM_W(0X190, ctx->r2) = ctx->r3;
    // 0x8043CDD4: sw          $v1, 0x18C($v0)
    MEM_W(0X18C, ctx->r2) = ctx->r3;
    // 0x8043CDD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8043CDDC: addiu       $a0, $v0, 0x198
    ctx->r4 = ADD32(ctx->r2, 0X198);
    // 0x8043CDE0: addiu       $a2, $zero, 0x63
    ctx->r6 = ADD32(0, 0X63);
L_8043CDE4:
    // 0x8043CDE4: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x8043CDE8: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    // 0x8043CDEC: sw          $v1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r3;
    // 0x8043CDF0: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x8043CDF4: sw          $v1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r3;
    // 0x8043CDF8: sw          $v1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r3;
    // 0x8043CDFC: sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
    // 0x8043CE00: sw          $v1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r3;
    // 0x8043CE04: sw          $v1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r3;
    // 0x8043CE08: sw          $v1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r3;
    // 0x8043CE0C: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x8043CE10: sw          $v1, -0x28($a0)
    MEM_W(-0X28, ctx->r4) = ctx->r3;
    // 0x8043CE14: sw          $v1, -0x2C($a0)
    MEM_W(-0X2C, ctx->r4) = ctx->r3;
    // 0x8043CE18: bne         $a1, $a2, L_8043CDE4
    if (ctx->r5 != ctx->r6) {
        // 0x8043CE1C: sw          $v1, -0x30($a0)
        MEM_W(-0X30, ctx->r4) = ctx->r3;
            goto L_8043CDE4;
    }
    // 0x8043CE1C: sw          $v1, -0x30($a0)
    MEM_W(-0X30, ctx->r4) = ctx->r3;
    // 0x8043CE20: sw          $zero, 0x318($s1)
    MEM_W(0X318, ctx->r17) = 0;
    // 0x8043CE24: sw          $zero, 0x320($s1)
    MEM_W(0X320, ctx->r17) = 0;
    // 0x8043CE28: sw          $zero, 0x31C($s1)
    MEM_W(0X31C, ctx->r17) = 0;
    // 0x8043CE2C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8043CE30: jal         0x80047AB8
    // 0x8043CE34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x8043CE34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8043CE38: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8043CE3C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8043CE40: swc1        $f6, 0x328($s1)
    MEM_W(0X328, ctx->r17) = ctx->f6.u32l;
    // 0x8043CE44: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8043CE48: swc1        $f8, 0x32C($s1)
    MEM_W(0X32C, ctx->r17) = ctx->f8.u32l;
    // 0x8043CE4C: lw          $t6, 0x938($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X938);
    // 0x8043CE50: lw          $t8, 0x93C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X93C);
    // 0x8043CE54: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043CE58: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8043CE5C: mflo        $a0
    ctx->r4 = lo;
    // 0x8043CE60: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x8043CE64: jal         0x80064D1C
    // 0x8043CE68: nop

    func_80064D1C(rdram, ctx);
        goto after_3;
    // 0x8043CE68: nop

    after_3:
    // 0x8043CE6C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8043CE70: sw          $v0, 0x330($s1)
    MEM_W(0X330, ctx->r17) = ctx->r2;
    // 0x8043CE74: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8043CE78: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x8043CE7C: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x8043CE80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8043CE84: jal         0x800675D0
    // 0x8043CE88: lw          $a1, 0x940($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X940);
    func_800675D0(rdram, ctx);
        goto after_4;
    // 0x8043CE88: lw          $a1, 0x940($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X940);
    after_4:
    // 0x8043CE8C: sh          $zero, 0x334($s1)
    MEM_H(0X334, ctx->r17) = 0;
    // 0x8043CE90: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8043CE94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8043CE98: lw          $v0, 0x94C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X94C);
    // 0x8043CE9C: beql        $v0, $zero, L_8043CEB8
    if (ctx->r2 == 0) {
        // 0x8043CEA0: sw          $zero, 0x338($s1)
        MEM_W(0X338, ctx->r17) = 0;
            goto L_8043CEB8;
    }
    goto skip_0;
    // 0x8043CEA0: sw          $zero, 0x338($s1)
    MEM_W(0X338, ctx->r17) = 0;
    skip_0:
    // 0x8043CEA4: beq         $v0, $at, L_8043CEC0
    if (ctx->r2 == ctx->r1) {
        // 0x8043CEA8: nop
    
            goto L_8043CEC0;
    }
    // 0x8043CEA8: nop

    // 0x8043CEAC: b           L_8043CECC
    // 0x8043CEB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8043CECC;
    // 0x8043CEB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043CEB4: sw          $zero, 0x338($s1)
    MEM_W(0X338, ctx->r17) = 0;
L_8043CEB8:
    // 0x8043CEB8: b           L_8043CEC8
    // 0x8043CEBC: sw          $zero, 0x33C($s1)
    MEM_W(0X33C, ctx->r17) = 0;
        goto L_8043CEC8;
    // 0x8043CEBC: sw          $zero, 0x33C($s1)
    MEM_W(0X33C, ctx->r17) = 0;
L_8043CEC0:
    // 0x8043CEC0: jal         0x80052C98
    // 0x8043CEC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052C98(rdram, ctx);
        goto after_5;
    // 0x8043CEC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8043CEC8:
    // 0x8043CEC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043CECC:
    // 0x8043CECC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8043CED0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8043CED4: jr          $ra
    // 0x8043CED8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8043CED8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800272D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800272D0: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x800272D4: addiu       $t6, $t6, 0x7260
    ctx->r14 = ADD32(ctx->r14, 0X7260);
    // 0x800272D8: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x800272DC: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x800272E0: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    // 0x800272E4: jr          $ra
    // 0x800272E8: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
    return;
    // 0x800272E8: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80475900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475900: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475904: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475908: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047590C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475910: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475914: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475918: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047591C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475920: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475924: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475928: jr          $ra
    // 0x8047592C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047592C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806EDC98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EDC98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806EDC9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EDCA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EDCA4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EDCA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EDCAC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806EDCB0: jal         0x800577D8
    // 0x806EDCB4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806EDCB4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x806EDCB8: jal         0x806ED57C
    // 0x806EDCBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED57C(rdram, ctx);
        goto after_1;
    // 0x806EDCBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EDCC0: jal         0x806ED5F0
    // 0x806EDCC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED5F0(rdram, ctx);
        goto after_2;
    // 0x806EDCC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EDCC8: jal         0x806ED6C4
    // 0x806EDCCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED6C4(rdram, ctx);
        goto after_3;
    // 0x806EDCCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EDCD0: bne         $v0, $zero, L_806EDCF0
    if (ctx->r2 != 0) {
        // 0x806EDCD4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EDCF0;
    }
    // 0x806EDCD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDCD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EDCDC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806EDCE0: jal         0x806EE584
    // 0x806EDCE4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_4;
    // 0x806EDCE4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806EDCE8: b           L_806EDD64
    // 0x806EDCEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EDD64;
    // 0x806EDCEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EDCF0:
    // 0x806EDCF0: jal         0x806ED714
    // 0x806EDCF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED714(rdram, ctx);
        goto after_5;
    // 0x806EDCF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EDCF8: beq         $v0, $zero, L_806EDD18
    if (ctx->r2 == 0) {
        // 0x806EDCFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EDD18;
    }
    // 0x806EDCFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDD00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EDD04: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806EDD08: jal         0x806EE584
    // 0x806EDD0C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_6;
    // 0x806EDD0C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x806EDD10: b           L_806EDD64
    // 0x806EDD14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EDD64;
    // 0x806EDD14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EDD18:
    // 0x806EDD18: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x806EDD1C: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806EDD20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDD24: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x806EDD28: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x806EDD2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EDD30: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806EDD34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806EDD38: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x806EDD3C: nop

    // 0x806EDD40: bc1f        L_806EDD58
    if (!c1cs) {
        // 0x806EDD44: nop
    
            goto L_806EDD58;
    }
    // 0x806EDD44: nop

    // 0x806EDD48: jal         0x806EE584
    // 0x806EDD4C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_7;
    // 0x806EDD4C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x806EDD50: b           L_806EDD64
    // 0x806EDD54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EDD64;
    // 0x806EDD54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EDD58:
    // 0x806EDD58: jal         0x806ED844
    // 0x806EDD5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED844(rdram, ctx);
        goto after_8;
    // 0x806EDD5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x806EDD60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EDD64:
    // 0x806EDD64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EDD68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806EDD6C: jr          $ra
    // 0x806EDD70: nop

    return;
    // 0x806EDD70: nop

;}
RECOMP_FUNC void func_800728CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800728CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800728D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800728D4: jal         0x80072858
    // 0x800728D8: sw          $a1, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r5;
    func_80072858(rdram, ctx);
        goto after_0;
    // 0x800728D8: sw          $a1, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r5;
    after_0:
    // 0x800728DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800728E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800728E4: jr          $ra
    // 0x800728E8: nop

    return;
    // 0x800728E8: nop

;}
RECOMP_FUNC void func_80081344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081344: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80081348: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8008134C: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80081350: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80081354: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80081358: lwc1        $f12, 0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8008135C: lwc1        $f18, 0x20($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X20);
    // 0x80081360: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80081364: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80081368: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8008136C: lwc1        $f6, 0x30($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X30);
    // 0x80081370: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80081374: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80081378: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x8008137C: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80081380: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80081384: lwc1        $f10, 0x24($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80081388: mul.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8008138C: nop

    // 0x80081390: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80081394: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80081398: mul.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8008139C: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800813A0: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800813A4: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800813A8: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800813AC: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800813B0: lwc1        $f18, 0x18($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800813B4: lwc1        $f6, 0x28($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800813B8: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800813BC: nop

    // 0x800813C0: mul.s       $f16, $f2, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800813C4: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800813C8: mul.s       $f10, $f12, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800813CC: lwc1        $f8, 0x38($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800813D0: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800813D4: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800813D8: jr          $ra
    // 0x800813DC: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x800813DC: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_80400118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80400118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040011C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80400120: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x80400124: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x80400128: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x8040012C: addiu       $at, $zero, 0x4692
    ctx->r1 = ADD32(0, 0X4692);
    // 0x80400130: beq         $v1, $at, L_80400174
    if (ctx->r3 == ctx->r1) {
        // 0x80400134: lw          $a1, 0xF54($a2)
        ctx->r5 = MEM_W(ctx->r6, 0XF54);
            goto L_80400174;
    }
    // 0x80400134: lw          $a1, 0xF54($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XF54);
    // 0x80400138: addiu       $at, $zero, 0x4693
    ctx->r1 = ADD32(0, 0X4693);
    // 0x8040013C: beq         $v1, $at, L_804001A0
    if (ctx->r3 == ctx->r1) {
        // 0x80400140: addiu       $at, $zero, 0x46AA
        ctx->r1 = ADD32(0, 0X46AA);
            goto L_804001A0;
    }
    // 0x80400140: addiu       $at, $zero, 0x46AA
    ctx->r1 = ADD32(0, 0X46AA);
    // 0x80400144: beq         $v1, $at, L_80400154
    if (ctx->r3 == ctx->r1) {
        // 0x80400148: addiu       $at, $zero, 0x46AE
        ctx->r1 = ADD32(0, 0X46AE);
            goto L_80400154;
    }
    // 0x80400148: addiu       $at, $zero, 0x46AE
    ctx->r1 = ADD32(0, 0X46AE);
    // 0x8040014C: bne         $v1, $at, L_804001CC
    if (ctx->r3 != ctx->r1) {
        // 0x80400150: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804001CC;
    }
    // 0x80400150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80400154:
    // 0x80400154: jal         0x80058A14
    // 0x80400158: nop

    func_80058A14(rdram, ctx);
        goto after_0;
    // 0x80400158: nop

    after_0:
    // 0x8040015C: bne         $v0, $zero, L_8040016C
    if (ctx->r2 != 0) {
        // 0x80400160: nop
    
            goto L_8040016C;
    }
    // 0x80400160: nop

    // 0x80400164: b           L_804001CC
    // 0x80400168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804001CC;
    // 0x80400168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8040016C:
    // 0x8040016C: b           L_804001CC
    // 0x80400170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804001CC;
    // 0x80400170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80400174:
    // 0x80400174: lw          $t6, 0xCE8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XCE8);
    // 0x80400178: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8040017C: andi        $t7, $a1, 0x1440
    ctx->r15 = ctx->r5 & 0X1440;
    // 0x80400180: beq         $t6, $at, L_80400190
    if (ctx->r14 == ctx->r1) {
        // 0x80400184: nop
    
            goto L_80400190;
    }
    // 0x80400184: nop

    // 0x80400188: beq         $t7, $zero, L_80400198
    if (ctx->r15 == 0) {
        // 0x8040018C: nop
    
            goto L_80400198;
    }
    // 0x8040018C: nop

L_80400190:
    // 0x80400190: b           L_804001CC
    // 0x80400194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804001CC;
    // 0x80400194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80400198:
    // 0x80400198: b           L_804001CC
    // 0x8040019C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804001CC;
    // 0x8040019C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804001A0:
    // 0x804001A0: lw          $t8, 0xCE8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XCE8);
    // 0x804001A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804001A8: andi        $t9, $a1, 0x2880
    ctx->r25 = ctx->r5 & 0X2880;
    // 0x804001AC: beq         $t8, $at, L_804001BC
    if (ctx->r24 == ctx->r1) {
        // 0x804001B0: nop
    
            goto L_804001BC;
    }
    // 0x804001B0: nop

    // 0x804001B4: beq         $t9, $zero, L_804001C4
    if (ctx->r25 == 0) {
        // 0x804001B8: nop
    
            goto L_804001C4;
    }
    // 0x804001B8: nop

L_804001BC:
    // 0x804001BC: b           L_804001CC
    // 0x804001C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804001CC;
    // 0x804001C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804001C4:
    // 0x804001C4: b           L_804001CC
    // 0x804001C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804001CC;
    // 0x804001C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804001CC:
    // 0x804001CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804001D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804001D4: jr          $ra
    // 0x804001D8: nop

    return;
    // 0x804001D8: nop

;}
RECOMP_FUNC void func_80789CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80789CD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80789CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80789CE0: jal         0x8004700C
    // 0x80789CE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80789CE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80789CE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80789CEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80789CF0: lwc1        $f12, 0x84($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80789CF4: lwc1        $f14, 0x88($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80789CF8: lw          $a2, 0x8C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8C);
    // 0x80789CFC: jal         0x8003B8F0
    // 0x80789D00: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8003B8F0(rdram, ctx);
        goto after_1;
    // 0x80789D00: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80789D04: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80789D08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80789D0C: bne         $v0, $zero, L_80789D1C
    if (ctx->r2 != 0) {
        // 0x80789D10: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80789D1C;
    }
    // 0x80789D10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80789D14: b           L_80789D90
    // 0x80789D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80789D90;
    // 0x80789D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80789D1C:
    // 0x80789D1C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80789D20: jal         0x80047F9C
    // 0x80789D24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80789D24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80789D28: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80789D2C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80789D30: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80789D34: beq         $v1, $zero, L_80789D68
    if (ctx->r3 == 0) {
        // 0x80789D38: sb          $t6, 0x17C($a1)
        MEM_B(0X17C, ctx->r5) = ctx->r14;
            goto L_80789D68;
    }
    // 0x80789D38: sb          $t6, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r14;
    // 0x80789D3C: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(790, 0X500) << 16);
    // 0x80789D40: lwc1        $f0, -0x5E50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(790, 0X500));
    // 0x80789D44: lwc1        $f4, 0x6C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x80789D48: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80789D4C: swc1        $f6, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f6.u32l;
    // 0x80789D50: lwc1        $f8, 0x70($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X70);
    // 0x80789D54: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80789D58: swc1        $f10, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f10.u32l;
    // 0x80789D5C: lwc1        $f16, 0x74($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X74);
    // 0x80789D60: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80789D64: swc1        $f18, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->f18.u32l;
L_80789D68:
    // 0x80789D68: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80789D6C: lwc1        $f4, 0x6C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x80789D70: lwc1        $f6, 0x70($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X70);
    // 0x80789D74: lwc1        $f8, 0x74($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X74);
    // 0x80789D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80789D7C: swc1        $f4, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->f4.u32l;
    // 0x80789D80: swc1        $f0, 0xC4($a1)
    MEM_W(0XC4, ctx->r5) = ctx->f0.u32l;
    // 0x80789D84: swc1        $f0, 0xC8($a1)
    MEM_W(0XC8, ctx->r5) = ctx->f0.u32l;
    // 0x80789D88: swc1        $f6, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = ctx->f6.u32l;
    // 0x80789D8C: swc1        $f8, 0x80($a1)
    MEM_W(0X80, ctx->r5) = ctx->f8.u32l;
L_80789D90:
    // 0x80789D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80789D94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80789D98: jr          $ra
    // 0x80789D9C: nop

    return;
    // 0x80789D9C: nop

;}
RECOMP_FUNC void func_80742740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742740: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80742744: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80742748: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x8074274C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80742750: addu        $t0, $v0, $at
    ctx->r8 = ADD32(ctx->r2, ctx->r1);
    // 0x80742754: lw          $v1, 0x6E6C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X6E6C);
    // 0x80742758: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8074275C: lw          $t1, 0x6E60($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X6E60);
    // 0x80742760: bne         $v1, $at, L_80742770
    if (ctx->r3 != ctx->r1) {
        // 0x80742764: nop
    
            goto L_80742770;
    }
    // 0x80742764: nop

    // 0x80742768: beq         $t1, $zero, L_80742780
    if (ctx->r9 == 0) {
        // 0x8074276C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80742780;
    }
    // 0x8074276C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80742770:
    // 0x80742770: jal         0x807424D8
    // 0x80742774: nop

    func_807424D8(rdram, ctx);
        goto after_0;
    // 0x80742774: nop

    after_0:
    // 0x80742778: b           L_807427E0
    // 0x8074277C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807427E0;
    // 0x8074277C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80742780:
    // 0x80742780: lwc1        $f12, 0x6BE4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X6BE4);
    // 0x80742784: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80742788: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8074278C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80742790: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80742794: jal         0x807423AC
    // 0x80742798: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_807423AC(rdram, ctx);
        goto after_1;
    // 0x80742798: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8074279C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x807427A0: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807427A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807427A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807427AC: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x807427B0: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x807427B4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x807427B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x807427BC: jal         0x80742308
    // 0x807427C0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    func_80742308(rdram, ctx);
        goto after_2;
    // 0x807427C0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    after_2:
    // 0x807427C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x807427C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807427CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807427D0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x807427D4: swc1        $f0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f0.u32l;
    // 0x807427D8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x807427DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807427E0:
    // 0x807427E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807427E4: jr          $ra
    // 0x807427E8: nop

    return;
    // 0x807427E8: nop

;}
RECOMP_FUNC void func_804C3E0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3E0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C3E10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C3E14: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804C3E18: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804C3E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C3E20: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804C3E24: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804C3E28: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804C3E2C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804C3E30: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804C3E34: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(206, 0X1440) << 16);
    // 0x804C3E38: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804C3E3C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804C3E40: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804C3E44: lw          $t2, 0x3EC0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(206, 0X1440));
    // 0x804C3E48: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804C3E4C: jal         0x804C3B00
    // 0x804C3E50: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_804C3B00(rdram, ctx);
        goto after_0;
    // 0x804C3E50: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x804C3E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C3E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C3E5C: jr          $ra
    // 0x804C3E60: nop

    return;
    // 0x804C3E60: nop

    // 0x804C3E64: nop

    // 0x804C3E68: nop

    // 0x804C3E6C: nop

;}
RECOMP_FUNC void func_8003A994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A994: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003A998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A99C: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x8003A9A0: lbu         $v0, 0x10($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X10);
    // 0x8003A9A4: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x8003A9A8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8003A9AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003A9B0: jal         0x8003A620
    // 0x8003A9B4: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    func_8003A620(rdram, ctx);
        goto after_0;
    // 0x8003A9B4: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003A9B8: lh          $v0, 0x1A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1A);
    // 0x8003A9BC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8003A9C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003A9C4: bnel        $v0, $zero, L_8003A9E8
    if (ctx->r2 != 0) {
        // 0x8003A9C8: addiu       $v0, $v0, -0x10
        ctx->r2 = ADD32(ctx->r2, -0X10);
            goto L_8003A9E8;
    }
    goto skip_0;
    // 0x8003A9C8: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    skip_0:
    // 0x8003A9CC: jal         0x800447C8
    // 0x8003A9D0: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8003A9D0: nop

    after_1:
    // 0x8003A9D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003A9D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003A9DC: b           L_8003AA00
    // 0x8003A9E0: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
        goto L_8003AA00;
    // 0x8003A9E0: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x8003A9E4: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
L_8003A9E8:
    // 0x8003A9E8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003A9EC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003A9F0: bgtzl       $v0, L_8003AA00
    if (SIGNED(ctx->r2) > 0) {
        // 0x8003A9F4: sb          $v0, 0x3($v1)
        MEM_B(0X3, ctx->r3) = ctx->r2;
            goto L_8003AA00;
    }
    goto skip_1;
    // 0x8003A9F4: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    skip_1:
    // 0x8003A9F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003A9FC: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
L_8003AA00:
    // 0x8003AA00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AA04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003AA08: jr          $ra
    // 0x8003AA0C: nop

    return;
    // 0x8003AA0C: nop

;}
RECOMP_FUNC void func_8066A00C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A00C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066A010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A014: jal         0x8004700C
    // 0x8066A018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8066A018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066A01C: beq         $v0, $zero, L_8066A064
    if (ctx->r2 == 0) {
        // 0x8066A020: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8066A064;
    }
    // 0x8066A020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066A024: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8066A028: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8066A02C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8066A030: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8066A034: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8066A038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066A03C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8066A040: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8066A044: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8066A048: nop

    // 0x8066A04C: bc1fl       L_8066A068
    if (!c1cs) {
        // 0x8066A050: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066A068;
    }
    goto skip_0;
    // 0x8066A050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066A054: jal         0x8066A790
    // 0x8066A058: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_8066A790(rdram, ctx);
        goto after_1;
    // 0x8066A058: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_1:
    // 0x8066A05C: jal         0x80669DD4
    // 0x8066A060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80669DD4(rdram, ctx);
        goto after_2;
    // 0x8066A060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8066A064:
    // 0x8066A064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A068:
    // 0x8066A068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066A06C: jr          $ra
    // 0x8066A070: nop

    return;
    // 0x8066A070: nop

;}
RECOMP_FUNC void func_8057DBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057DBC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057DBC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057DBC8: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x8057DBCC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8057DBD0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8057DBD4: beq         $a1, $at, L_8057DBF0
    if (ctx->r5 == ctx->r1) {
        // 0x8057DBD8: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_8057DBF0;
    }
    // 0x8057DBD8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8057DBDC: jal         0x80067878
    // 0x8057DBE0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8057DBE0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8057DBE4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8057DBE8: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8057DBEC: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_8057DBF0:
    // 0x8057DBF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057DBF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057DBF8: jr          $ra
    // 0x8057DBFC: nop

    return;
    // 0x8057DBFC: nop

;}
RECOMP_FUNC void func_807BBF44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BBF44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807BBF48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BBF4C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x807BBF50: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // 0x807BBF54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807BBF58: jal         0x80065728
    // 0x807BBF5C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x807BBF5C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x807BBF60: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x807BBF64: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x807BBF68: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807BBF6C: sw          $t6, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r14;
    // 0x807BBF70: sb          $t7, 0x58($a0)
    MEM_B(0X58, ctx->r4) = ctx->r15;
    // 0x807BBF74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BBF78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807BBF7C: jr          $ra
    // 0x807BBF80: nop

    return;
    // 0x807BBF80: nop

;}
RECOMP_FUNC void func_80038318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003831C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038320: jal         0x80021958
    // 0x80038324: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80038324: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038328: bne         $v0, $zero, L_80038338
    if (ctx->r2 != 0) {
        // 0x8003832C: nop
    
            goto L_80038338;
    }
    // 0x8003832C: nop

    // 0x80038330: b           L_8003836C
    // 0x80038334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003836C;
    // 0x80038334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038338:
    // 0x80038338: jal         0x800415FC
    // 0x8003833C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x8003833C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80038340: beq         $v0, $zero, L_80038350
    if (ctx->r2 == 0) {
        // 0x80038344: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80038350;
    }
    // 0x80038344: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038348: b           L_8003836C
    // 0x8003834C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003836C;
    // 0x8003834C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038350:
    // 0x80038350: jal         0x8003776C
    // 0x80038354: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8003776C(rdram, ctx);
        goto after_2;
    // 0x80038354: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_2:
    // 0x80038358: bnel        $v0, $zero, L_8003836C
    if (ctx->r2 != 0) {
        // 0x8003835C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003836C;
    }
    goto skip_0;
    // 0x8003835C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80038360: b           L_8003836C
    // 0x80038364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003836C;
    // 0x80038364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80038368: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003836C:
    // 0x8003836C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038374: jr          $ra
    // 0x80038378: nop

    return;
    // 0x80038378: nop

;}
RECOMP_FUNC void func_8064CAC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064CAC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064CAC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064CACC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064CAD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8064CAD4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8064CAD8: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8064CADC: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8064CAE0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8064CAE4: bne         $v0, $at, L_8064CB0C
    if (ctx->r2 != ctx->r1) {
        // 0x8064CAE8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8064CB0C;
    }
    // 0x8064CAE8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064CAEC: jal         0x8064A1C8
    // 0x8064CAF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8064A1C8(rdram, ctx);
        goto after_0;
    // 0x8064CAF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8064CAF4: beq         $v0, $zero, L_8064CB0C
    if (ctx->r2 == 0) {
        // 0x8064CAF8: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8064CB0C;
    }
    // 0x8064CAF8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8064CAFC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8064CB00: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8064CB04: jal         0x8002F6E4
    // 0x8064CB08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x8064CB08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_8064CB0C:
    // 0x8064CB0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064CB10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064CB14: jr          $ra
    // 0x8064CB18: nop

    return;
    // 0x8064CB18: nop

;}
RECOMP_FUNC void func_8005F9F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F9F4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8005F9F8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8005F9FC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8005FA00: lw          $v0, -0x776C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X776C);
    // 0x8005FA04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005FA08: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
L_8005FA0C:
    // 0x8005FA0C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8005FA10: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8005FA14: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8005FA18: bne         $a1, $t7, L_8005FA34
    if (ctx->r5 != ctx->r15) {
        // 0x8005FA1C: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8005FA34;
    }
    // 0x8005FA1C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8005FA20: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8005FA24: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x8005FA28: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8005FA2C: jr          $ra
    // 0x8005FA30: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    return;
    // 0x8005FA30: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
L_8005FA34:
    // 0x8005FA34: slti        $at, $a2, 0x96
    ctx->r1 = SIGNED(ctx->r6) < 0X96 ? 1 : 0;
    // 0x8005FA38: bne         $at, $zero, L_8005FA0C
    if (ctx->r1 != 0) {
        // 0x8005FA3C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8005FA0C;
    }
    // 0x8005FA3C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005FA40: jr          $ra
    // 0x8005FA44: nop

    return;
    // 0x8005FA44: nop

;}
RECOMP_FUNC void func_805A905C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A905C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805A9060: sll         $a3, $a1, 2
    ctx->r7 = S32(ctx->r5 << 2);
    // 0x805A9064: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(429, 0X1420) << 16);
    // 0x805A9068: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A906C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A9070: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x805A9074: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A9078: lwc1        $f4, -0x5EE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(429, 0X1420));
    // 0x805A907C: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(429, 0X1430) << 16);
    // 0x805A9080: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x805A9084: swc1        $f4, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->f4.u32l;
    // 0x805A9088: lwc1        $f6, -0x5ED0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(429, 0X1430));
    // 0x805A908C: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x805A9090: addiu       $t7, $zero, 0x3F
    ctx->r15 = ADD32(0, 0X3F);
    // 0x805A9094: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A9098: sw          $t6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r14;
    // 0x805A909C: sw          $t7, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r15;
    // 0x805A90A0: swc1        $f6, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f6.u32l;
    // 0x805A90A4: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x805A90A8: lui         $v1, 0x805B
    ctx->r3 = S32(RELOC_HI16(429, 0X13C8) << 16);
    // 0x805A90AC: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A90B0: addiu       $v1, $v1, -0x5F38
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(429, 0X13C8));
    // 0x805A90B4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x805A90B8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805A90BC: jal         0x805A922C
    // 0x805A90C0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_805A922C(rdram, ctx);
        goto after_0;
    // 0x805A90C0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x805A90C4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805A90C8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805A90CC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x805A90D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x805A90D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_805A90D8:
    // 0x805A90D8: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x805A90DC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x805A90E0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x805A90E4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x805A90E8: bne         $a0, $a1, L_805A90D8
    if (ctx->r4 != ctx->r5) {
        // 0x805A90EC: sh          $t8, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r24;
            goto L_805A90D8;
    }
    // 0x805A90EC: sh          $t8, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r24;
    // 0x805A90F0: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805A90F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A90F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A90FC: swc1        $f8, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f8.u32l;
    // 0x805A9100: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805A9104: sw          $zero, 0x50($a2)
    MEM_W(0X50, ctx->r6) = 0;
    // 0x805A9108: sw          $zero, 0x44($a2)
    MEM_W(0X44, ctx->r6) = 0;
    // 0x805A910C: swc1        $f0, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f0.u32l;
    // 0x805A9110: swc1        $f0, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->f0.u32l;
    // 0x805A9114: swc1        $f10, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f10.u32l;
    // 0x805A9118: jal         0x805A9210
    // 0x805A911C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_805A9210(rdram, ctx);
        goto after_1;
    // 0x805A911C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_1:
    // 0x805A9120: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x805A9124: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x805A9128: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x805A912C: lwc1        $f0, 0x3C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x805A9130: lwc1        $f2, 0x40($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X40);
    // 0x805A9134: sub.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x805A9138: add.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x805A913C: swc1        $f16, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->f16.u32l;
    // 0x805A9140: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x805A9144: swc1        $f18, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f18.u32l;
    // 0x805A9148: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x805A914C: swc1        $f4, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f4.u32l;
    // 0x805A9150: swc1        $f6, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f6.u32l;
    // 0x805A9154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A9158: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A915C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805A9160: jr          $ra
    // 0x805A9164: nop

    return;
    // 0x805A9164: nop

;}
RECOMP_FUNC void func_8043EF00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043EF00: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8043EF04: addiu       $at, $zero, 0x4091
    ctx->r1 = ADD32(0, 0X4091);
    // 0x8043EF08: beq         $v0, $at, L_8043EF20
    if (ctx->r2 == ctx->r1) {
        // 0x8043EF0C: addiu       $at, $zero, 0x40C2
        ctx->r1 = ADD32(0, 0X40C2);
            goto L_8043EF20;
    }
    // 0x8043EF0C: addiu       $at, $zero, 0x40C2
    ctx->r1 = ADD32(0, 0X40C2);
    // 0x8043EF10: beq         $v0, $at, L_8043EF2C
    if (ctx->r2 == ctx->r1) {
        // 0x8043EF14: nop
    
            goto L_8043EF2C;
    }
    // 0x8043EF14: nop

    // 0x8043EF18: b           L_8043EF38
    // 0x8043EF1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8043EF38;
    // 0x8043EF1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043EF20:
    // 0x8043EF20: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(95, 0X3008) << 16);
    // 0x8043EF24: jr          $ra
    // 0x8043EF28: addiu       $v0, $v0, 0x1F08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(95, 0X3008));
    return;
    // 0x8043EF28: addiu       $v0, $v0, 0x1F08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(95, 0X3008));
L_8043EF2C:
    // 0x8043EF2C: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(95, 0X3874) << 16);
    // 0x8043EF30: jr          $ra
    // 0x8043EF34: addiu       $v0, $v0, 0x2774
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(95, 0X3874));
    return;
    // 0x8043EF34: addiu       $v0, $v0, 0x2774
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(95, 0X3874));
L_8043EF38:
    // 0x8043EF38: jr          $ra
    // 0x8043EF3C: nop

    return;
    // 0x8043EF3C: nop

;}
RECOMP_FUNC void func_8064E368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E368: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064E36C: lui         $at, 0x8065
    ctx->r1 = S32(RELOC_HI16(498, 0XBEC) << 16);
    // 0x8064E370: lwc1        $f4, -0x1744($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(498, 0XBEC));
    // 0x8064E374: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064E378: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064E37C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8064E380: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x8064E384: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8064E388: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8064E38C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064E390: jal         0x8005FCA8
    // 0x8064E394: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x8064E394: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    after_0:
    // 0x8064E398: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8064E39C: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x8064E3A0: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x8064E3A4: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x8064E3A8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8064E3AC: sw          $t0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r8;
    // 0x8064E3B0: sw          $t1, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r9;
    // 0x8064E3B4: jal         0x80066DE4
    // 0x8064E3B8: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8064E3B8: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    after_1:
    // 0x8064E3BC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8064E3C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8064E3C4: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8064E3C8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8064E3CC: jal         0x80066E88
    // 0x8064E3D0: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8064E3D0: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x8064E3D4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8064E3D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8064E3DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8064E3E0: lui         $at, 0x8065
    ctx->r1 = S32(RELOC_HI16(498, 0XBF0) << 16);
    // 0x8064E3E4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8064E3E8: swc1        $f18, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f18.u32l;
    // 0x8064E3EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064E3F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064E3F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8064E3F8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8064E3FC: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
    // 0x8064E400: lwc1        $f4, -0x1740($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(498, 0XBF0));
    // 0x8064E404: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8064E408: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8064E40C: lui         $at, 0x8065
    ctx->r1 = S32(RELOC_HI16(498, 0XBF4) << 16);
    // 0x8064E410: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
    // 0x8064E414: swc1        $f6, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f6.u32l;
    // 0x8064E418: lwc1        $f8, -0x173C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(498, 0XBF4));
    // 0x8064E41C: jal         0x8064E7C0
    // 0x8064E420: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    func_8064E7C0(rdram, ctx);
        goto after_3;
    // 0x8064E420: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x8064E424: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8064E428: jal         0x80067BBC
    // 0x8064E42C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x8064E42C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x8064E430: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    // 0x8064E434: jal         0x80067818
    // 0x8064E438: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x8064E438: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8064E43C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8064E440: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064E444: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064E448: jr          $ra
    // 0x8064E44C: nop

    return;
    // 0x8064E44C: nop

;}
RECOMP_FUNC void func_8002D898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D898: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002D89C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D8A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D8A4: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8002D8A8: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002D8AC: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8002D8B0: addiu       $t7, $t7, 0x3EA4
    ctx->r15 = ADD32(ctx->r15, 0X3EA4);
    // 0x8002D8B4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8002D8B8: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8002D8BC: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8002D8C0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8002D8C4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002D8C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002D8CC: sh          $a1, 0x10($t8)
    MEM_H(0X10, ctx->r24) = ctx->r5;
    // 0x8002D8D0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8002D8D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002D8D8: sh          $a1, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r5;
    // 0x8002D8DC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8002D8E0: sh          $a1, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r5;
    // 0x8002D8E4: jal         0x8005FDC4
    // 0x8002D8E8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8005FDC4(rdram, ctx);
        goto after_0;
    // 0x8002D8E8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8002D8EC: jal         0x8002AFA0
    // 0x8002D8F0: nop

    func_8002AFA0(rdram, ctx);
        goto after_1;
    // 0x8002D8F0: nop

    after_1:
    // 0x8002D8F4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8002D8F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002D8FC: lui         $t1, 0x8003
    ctx->r9 = S32(0X8003 << 16);
    // 0x8002D900: lui         $t2, 0x8003
    ctx->r10 = S32(0X8003 << 16);
    // 0x8002D904: addiu       $t1, $t1, 0x3984
    ctx->r9 = ADD32(ctx->r9, 0X3984);
    // 0x8002D908: addiu       $t2, $t2, 0x3A00
    ctx->r10 = ADD32(ctx->r10, 0X3A00);
    // 0x8002D90C: addiu       $t3, $zero, 0x168
    ctx->r11 = ADD32(0, 0X168);
    // 0x8002D910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002D914: sw          $t1, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = ctx->r9;
    // 0x8002D918: sw          $t2, 0xB8($v1)
    MEM_W(0XB8, ctx->r3) = ctx->r10;
    // 0x8002D91C: sw          $zero, 0x190($v1)
    MEM_W(0X190, ctx->r3) = 0;
    // 0x8002D920: sw          $t3, 0x19C($v1)
    MEM_W(0X19C, ctx->r3) = ctx->r11;
    // 0x8002D924: swc1        $f0, 0x188($v1)
    MEM_W(0X188, ctx->r3) = ctx->f0.u32l;
    // 0x8002D928: jal         0x800230DC
    // 0x8002D92C: swc1        $f0, 0x18C($v1)
    MEM_W(0X18C, ctx->r3) = ctx->f0.u32l;
    func_800230DC(rdram, ctx);
        goto after_2;
    // 0x8002D92C: swc1        $f0, 0x18C($v1)
    MEM_W(0X18C, ctx->r3) = ctx->f0.u32l;
    after_2:
    // 0x8002D930: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8002D934: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002D938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002D93C: jal         0x8001DC38
    // 0x8002D940: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    func_8001DC38(rdram, ctx);
        goto after_3;
    // 0x8002D940: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x8002D944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D948: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002D94C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002D950: jr          $ra
    // 0x8002D954: nop

    return;
    // 0x8002D954: nop

;}
RECOMP_FUNC void func_806AABE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AABE0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x806AABE4: addiu       $at, $zero, 0x459C
    ctx->r1 = ADD32(0, 0X459C);
    // 0x806AABE8: lui         $v0, 0x806B
    ctx->r2 = S32(RELOC_HI16(592, 0XAE0) << 16);
    // 0x806AABEC: bne         $t6, $at, L_806AAC00
    if (ctx->r14 != ctx->r1) {
        // 0x806AABF0: addiu       $v0, $v0, -0x4940
        ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(592, 0XAE0));
            goto L_806AAC00;
    }
    // 0x806AABF0: addiu       $v0, $v0, -0x4940
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(592, 0XAE0));
    // 0x806AABF4: lui         $v0, 0x806B
    ctx->r2 = S32(RELOC_HI16(592, 0XAE0) << 16);
    // 0x806AABF8: jr          $ra
    // 0x806AABFC: addiu       $v0, $v0, -0x4940
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(592, 0XAE0));
    return;
    // 0x806AABFC: addiu       $v0, $v0, -0x4940
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(592, 0XAE0));
L_806AAC00:
    // 0x806AAC00: jr          $ra
    // 0x806AAC04: nop

    return;
    // 0x806AAC04: nop

;}
RECOMP_FUNC void func_80446C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446C40: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446C44: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
    // 0x80446C48: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446C4C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80446C50: sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
    // 0x80446C54: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446C58: sw          $t6, 0x6CC8($at)
    MEM_W(0X6CC8, ctx->r1) = ctx->r14;
    // 0x80446C5C: addiu       $t7, $zero, 0x744
    ctx->r15 = ADD32(0, 0X744);
    // 0x80446C60: addiu       $t8, $zero, 0xAC8
    ctx->r24 = ADD32(0, 0XAC8);
    // 0x80446C64: sw          $v1, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r3;
    // 0x80446C68: sw          $t7, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->r15;
    // 0x80446C6C: jr          $ra
    // 0x80446C70: sw          $t8, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r24;
    return;
    // 0x80446C70: sw          $t8, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_804B69BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B69BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804B69C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B69C4: jal         0x804B66F8
    // 0x804B69C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_804B66F8(rdram, ctx);
        goto after_0;
    // 0x804B69C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x804B69CC: bne         $v0, $zero, L_804B6A3C
    if (ctx->r2 != 0) {
        // 0x804B69D0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_804B6A3C;
    }
    // 0x804B69D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804B69D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804B69D8: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x804B69DC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x804B69E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804B69E4: jal         0x804B6524
    // 0x804B69E8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_804B6524(rdram, ctx);
        goto after_1;
    // 0x804B69E8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x804B69EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804B69F0: bne         $v0, $at, L_804B6A30
    if (ctx->r2 != ctx->r1) {
        // 0x804B69F4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_804B6A30;
    }
    // 0x804B69F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804B69F8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804B69FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x804B6A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6A04: lw          $t7, 0x68($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X68);
    // 0x804B6A08: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x804B6A0C: bne         $t7, $zero, L_804B6A28
    if (ctx->r15 != 0) {
        // 0x804B6A10: nop
    
            goto L_804B6A28;
    }
    // 0x804B6A10: nop

    // 0x804B6A14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6A18: jal         0x804B6FF0
    // 0x804B6A1C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_804B6FF0(rdram, ctx);
        goto after_2;
    // 0x804B6A1C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_2:
    // 0x804B6A20: b           L_804B6A34
    // 0x804B6A24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_804B6A34;
    // 0x804B6A24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_804B6A28:
    // 0x804B6A28: jal         0x804B6FF0
    // 0x804B6A2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804B6FF0(rdram, ctx);
        goto after_3;
    // 0x804B6A2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
L_804B6A30:
    // 0x804B6A30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_804B6A34:
    // 0x804B6A34: jal         0x804B6580
    // 0x804B6A38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804B6580(rdram, ctx);
        goto after_4;
    // 0x804B6A38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_804B6A3C:
    // 0x804B6A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B6A40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804B6A44: jr          $ra
    // 0x804B6A48: nop

    return;
    // 0x804B6A48: nop

;}
RECOMP_FUNC void func_8064C348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C34C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C350: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064C354: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8064C358: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8064C35C: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8064C360: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8064C364: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8064C368: bne         $v0, $at, L_8064C390
    if (ctx->r2 != ctx->r1) {
        // 0x8064C36C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8064C390;
    }
    // 0x8064C36C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064C370: jal         0x8064A1C8
    // 0x8064C374: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8064A1C8(rdram, ctx);
        goto after_0;
    // 0x8064C374: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8064C378: beq         $v0, $zero, L_8064C390
    if (ctx->r2 == 0) {
        // 0x8064C37C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8064C390;
    }
    // 0x8064C37C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8064C380: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8064C384: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8064C388: jal         0x8002F6E4
    // 0x8064C38C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x8064C38C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_8064C390:
    // 0x8064C390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064C394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C398: jr          $ra
    // 0x8064C39C: nop

    return;
    // 0x8064C39C: nop

;}
RECOMP_FUNC void func_8057F520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F520: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057F524: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057F528: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057F52C: lw          $t6, 0x5C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X5C);
    // 0x8057F530: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8057F534: jal         0x8057EFA0
    // 0x8057F538: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_8057EFA0(rdram, ctx);
        goto after_0;
    // 0x8057F538: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x8057F53C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8057F540: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8057F544: bltz        $v0, L_8057F564
    if (SIGNED(ctx->r2) < 0) {
        // 0x8057F548: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8057F564;
    }
    // 0x8057F548: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8057F54C: addiu       $v0, $a1, 0x1C
    ctx->r2 = ADD32(ctx->r5, 0X1C);
L_8057F550:
    // 0x8057F550: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8057F554: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8057F558: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8057F55C: beq         $at, $zero, L_8057F550
    if (ctx->r1 == 0) {
        // 0x8057F560: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_8057F550;
    }
    // 0x8057F560: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
L_8057F564:
    // 0x8057F564: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8057F568: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8057F56C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8057F570: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x8057F574: sw          $t7, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r15;
    // 0x8057F578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057F57C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057F580: jr          $ra
    // 0x8057F584: nop

    return;
    // 0x8057F584: nop

;}
RECOMP_FUNC void func_805803C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805803C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805803C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805803CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805803D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805803D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x805803D8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x805803DC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x805803E0: jal         0x80047090
    // 0x805803E4: addiu       $a0, $zero, 0x4504
    ctx->r4 = ADD32(0, 0X4504);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805803E4: addiu       $a0, $zero, 0x4504
    ctx->r4 = ADD32(0, 0X4504);
    after_0:
    // 0x805803E8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x805803EC: beq         $v0, $at, L_80580424
    if (ctx->r2 == ctx->r1) {
        // 0x805803F0: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80580424;
    }
    // 0x805803F0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x805803F4: lui         $at, 0x4504
    ctx->r1 = S32(0X4504 << 16);
    // 0x805803F8: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x805803FC: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80580400: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80580404: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80580408: jal         0x8004613C
    // 0x8058040C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8058040C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80580410: beq         $v0, $zero, L_80580424
    if (ctx->r2 == 0) {
        // 0x80580414: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80580424;
    }
    // 0x80580414: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80580418: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8058041C: jal         0x80047F9C
    // 0x80580420: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80580420: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_80580424:
    // 0x80580424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80580428: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8058042C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80580430: jr          $ra
    // 0x80580434: nop

    return;
    // 0x80580434: nop

;}
RECOMP_FUNC void func_80048968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004896C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048970: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80048974: addiu       $a1, $zero, 0xBBE
    ctx->r5 = ADD32(0, 0XBBE);
    // 0x80048978: bne         $v0, $zero, L_80048994
    if (ctx->r2 != 0) {
        // 0x8004897C: nop
    
            goto L_80048994;
    }
    // 0x8004897C: nop

    // 0x80048980: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80048984: jal         0x80071380
    // 0x80048988: addiu       $a0, $a0, 0x820
    ctx->r4 = ADD32(ctx->r4, 0X820);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80048988: addiu       $a0, $a0, 0x820
    ctx->r4 = ADD32(ctx->r4, 0X820);
    after_0:
    // 0x8004898C: b           L_800489B0
    // 0x80048990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800489B0;
    // 0x80048990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048994:
    // 0x80048994: jalr        $v0
    // 0x80048998: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80048998: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8004899C: jal         0x80047C38
    // 0x800489A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80047C38(rdram, ctx);
        goto after_2;
    // 0x800489A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800489A4: jal         0x800474B0
    // 0x800489A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800474B0(rdram, ctx);
        goto after_3;
    // 0x800489A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800489AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800489B0:
    // 0x800489B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800489B4: jr          $ra
    // 0x800489B8: nop

    return;
    // 0x800489B8: nop

;}
