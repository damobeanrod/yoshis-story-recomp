#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8046549C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046549C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804654A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804654A4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804654A8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804654AC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804654B0: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(125, 0X1DA8) << 16);
    // 0x804654B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804654B8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804654BC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804654C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804654C4: lw          $t8, 0x6378($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(125, 0X1DA8));
    // 0x804654C8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804654CC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804654D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804654D4: jal         0x80048490
    // 0x804654D8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804654D8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804654DC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804654E0: jal         0x80048378
    // 0x804654E4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804654E4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804654E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804654EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804654F0: jr          $ra
    // 0x804654F4: nop

    return;
    // 0x804654F4: nop

;}
RECOMP_FUNC void func_8006D72C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D72C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D734: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006D738: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8006D73C: jal         0x8006D6F8
    // 0x8006D740: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8006D6F8(rdram, ctx);
        goto after_0;
    // 0x8006D740: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006D744: beq         $v0, $zero, L_8006D764
    if (ctx->r2 == 0) {
        // 0x8006D748: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8006D764;
    }
    // 0x8006D748: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D74C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006D750: bne         $t6, $at, L_8006D760
    if (ctx->r14 != ctx->r1) {
        // 0x8006D754: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8006D760;
    }
    // 0x8006D754: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006D758: b           L_8006D764
    // 0x8006D75C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
        goto L_8006D764;
    // 0x8006D75C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_8006D760:
    // 0x8006D760: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_8006D764:
    // 0x8006D764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D76C: jr          $ra
    // 0x8006D770: nop

    return;
    // 0x8006D770: nop

;}
RECOMP_FUNC void func_8073ECE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073ECE0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8073ECE4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8073ECE8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8073ECEC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8073ECF0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8073ECF4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8073ECF8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8073ECFC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8073ED00: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(748, 0X2394) << 16);
    // 0x8073ED04: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8073ED08: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8073ED0C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8073ED10: lw          $t1, 0xB84($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(748, 0X2394));
    // 0x8073ED14: jr          $ra
    // 0x8073ED18: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8073ED18: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804CEF28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CEF28: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x804CEF2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CEF30: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x804CEF34: lw          $t9, 0x180($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X180);
    // 0x804CEF38: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804CEF3C: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x804CEF40: lwc1        $f16, 0xC4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x804CEF44: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CEF48: lh          $t8, 0x56($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X56);
    // 0x804CEF4C: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x804CEF50: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804CEF54: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x804CEF58: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x804CEF5C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804CEF60: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x804CEF64: bne         $a0, $t9, L_804CF094
    if (ctx->r4 != ctx->r25) {
        // 0x804CEF68: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_804CF094;
    }
    // 0x804CEF68: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x804CEF6C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x804CEF70: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x804CEF74: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x804CEF78: jal         0x80047AB8
    // 0x804CEF7C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x804CEF7C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x804CEF80: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x804CEF84: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804CEF88: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x804CEF8C: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x804CEF90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804CEF94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804CEF98: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x804CEF9C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x804CEFA0: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x804CEFA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804CEFA8: div.s       $f2, $f12, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f18.fl);
    // 0x804CEFAC: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x804CEFB0: nop

    // 0x804CEFB4: bc1fl       L_804CEFC8
    if (!c1cs) {
        // 0x804CEFB8: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_804CEFC8;
    }
    goto skip_0;
    // 0x804CEFB8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_0:
    // 0x804CEFBC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804CEFC0: nop

    // 0x804CEFC4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_804CEFC8:
    // 0x804CEFC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804CEFCC: nop

    // 0x804CEFD0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804CEFD4: nop

    // 0x804CEFD8: bc1f        L_804CEFE4
    if (!c1cs) {
        // 0x804CEFDC: nop
    
            goto L_804CEFE4;
    }
    // 0x804CEFDC: nop

    // 0x804CEFE0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_804CEFE4:
    // 0x804CEFE4: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x804CEFE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804CEFEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804CEFF0: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B2C) << 16);
    // 0x804CEFF4: lwc1        $f4, -0x224($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B2C));
    // 0x804CEFF8: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804CEFFC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x804CF000: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804CF004: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x804CF008: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804CF00C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x804CF010: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B38) << 16);
    // 0x804CF014: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x804CF018: div.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804CF01C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x804CF020: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x804CF024: nop

    // 0x804CF028: mul.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x804CF02C: nop

    // 0x804CF030: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x804CF034: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x804CF038: nop

    // 0x804CF03C: bc1f        L_804CF070
    if (!c1cs) {
        // 0x804CF040: nop
    
            goto L_804CF070;
    }
    // 0x804CF040: nop

    // 0x804CF044: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B30) << 16);
    // 0x804CF048: lwc1        $f8, -0x220($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B30));
    // 0x804CF04C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B34) << 16);
    // 0x804CF050: lwc1        $f10, -0x21C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B34));
    // 0x804CF054: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x804CF058: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x804CF05C: add.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x804CF060: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x804CF064: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x804CF068: b           L_804CF094
    // 0x804CF06C: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
        goto L_804CF094;
    // 0x804CF06C: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
L_804CF070:
    // 0x804CF070: lwc1        $f4, -0x218($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B38));
    // 0x804CF074: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B3C) << 16);
    // 0x804CF078: lwc1        $f8, -0x214($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B3C));
    // 0x804CF07C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x804CF080: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x804CF084: add.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x804CF088: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x804CF08C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x804CF090: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
L_804CF094:
    // 0x804CF094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CF098: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x804CF09C: jr          $ra
    // 0x804CF0A0: nop

    return;
    // 0x804CF0A0: nop

;}
RECOMP_FUNC void func_806AEE78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AEE78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AEE7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AEE80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806AEE84: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AEE88: lw          $t9, 0x10($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X10);
    // 0x806AEE8C: jalr        $t9
    // 0x806AEE90: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806AEE90: nop

    after_0:
    // 0x806AEE94: jal         0x806AE458
    // 0x806AEE98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806AE458(rdram, ctx);
        goto after_1;
    // 0x806AEE98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806AEE9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806AEEA0: jal         0x806ADDC0
    // 0x806AEEA4: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    func_806ADDC0(rdram, ctx);
        goto after_2;
    // 0x806AEEA4: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    after_2:
    // 0x806AEEA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AEEAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AEEB0: jr          $ra
    // 0x806AEEB4: nop

    return;
    // 0x806AEEB4: nop

;}
RECOMP_FUNC void func_80421250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421250: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80421254: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80421258: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042125C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80421260: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80421264: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80421268: lw          $t7, 0x174($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X174);
    // 0x8042126C: lbu         $t1, 0x18($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X18);
    // 0x80421270: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80421274: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x80421278: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042127C: lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XC);
    // 0x80421280: lh          $t9, 0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XC);
    // 0x80421284: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x80421288: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042128C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80421290: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80421294: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80421298: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8042129C: mul.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x804212A0: bne         $t1, $at, L_804212B8
    if (ctx->r9 != ctx->r1) {
        // 0x804212A4: addiu       $at, $zero, 0x4002
        ctx->r1 = ADD32(0, 0X4002);
            goto L_804212B8;
    }
    // 0x804212A4: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x804212A8: bne         $v1, $at, L_8042135C
    if (ctx->r3 != ctx->r1) {
        // 0x804212AC: nop
    
            goto L_8042135C;
    }
    // 0x804212AC: nop

    // 0x804212B0: b           L_8042135C
    // 0x804212B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8042135C;
    // 0x804212B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_804212B8:
    // 0x804212B8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804212BC: bne         $v1, $at, L_8042135C
    if (ctx->r3 != ctx->r1) {
        // 0x804212C0: lw          $t2, 0x68($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X68);
            goto L_8042135C;
    }
    // 0x804212C0: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x804212C4: lwc1        $f10, 0x4($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X4);
    // 0x804212C8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x804212CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804212D0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x804212D4: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x804212D8: bc1f        L_80421350
    if (!c1cs) {
        // 0x804212DC: nop
    
            goto L_80421350;
    }
    // 0x804212DC: nop

    // 0x804212E0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x804212E4: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    // 0x804212E8: jal         0x8002FABC
    // 0x804212EC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8002FABC(rdram, ctx);
        goto after_0;
    // 0x804212EC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x804212F0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x804212F4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x804212F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804212FC: sw          $t3, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r11;
    // 0x80421300: jal         0x8042182C
    // 0x80421304: addiu       $a1, $a3, 0x20
    ctx->r5 = ADD32(ctx->r7, 0X20);
    func_8042182C(rdram, ctx);
        goto after_1;
    // 0x80421304: addiu       $a1, $a3, 0x20
    ctx->r5 = ADD32(ctx->r7, 0X20);
    after_1:
    // 0x80421308: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8042130C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80421310: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80421314: jal         0x80067D5C
    // 0x80421318: lw          $a0, 0x24($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X24);
    func_80067D5C(rdram, ctx);
        goto after_2;
    // 0x80421318: lw          $a0, 0x24($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X24);
    after_2:
    // 0x8042131C: addiu       $a0, $zero, 0x269
    ctx->r4 = ADD32(0, 0X269);
    // 0x80421320: jal         0x80067818
    // 0x80421324: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80421324: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80421328: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x8042132C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80421330: sb          $t4, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r12;
    // 0x80421334: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80421338: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8042133C: sb          $t5, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r13;
    // 0x80421340: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80421344: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x80421348: b           L_80421358
    // 0x8042134C: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
        goto L_80421358;
    // 0x8042134C: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
L_80421350:
    // 0x80421350: jal         0x8002F6E4
    // 0x80421354: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_4;
    // 0x80421354: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
L_80421358:
    // 0x80421358: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8042135C:
    // 0x8042135C: beql        $t0, $zero, L_80421414
    if (ctx->r8 == 0) {
        // 0x80421360: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80421414;
    }
    goto skip_0;
    // 0x80421360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80421364: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x80421368: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8042136C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80421370: lw          $v0, 0xC($t8)
    ctx->r2 = MEM_W(ctx->r24, 0XC);
    // 0x80421374: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80421378: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8042137C: bnel        $t9, $zero, L_80421414
    if (ctx->r25 != 0) {
        // 0x80421380: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80421414;
    }
    goto skip_1;
    // 0x80421380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80421384: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80421388: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8042138C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80421390: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80421394: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80421398: lwc1        $f16, 0x8C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8042139C: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(32, 0X1760) << 16);
    // 0x804213A0: lwc1        $f18, 0x2820($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(32, 0X1760));
    // 0x804213A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804213A8: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x804213AC: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x804213B0: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x804213B4: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x804213B8: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x804213BC: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x804213C0: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x804213C4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x804213C8: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x804213CC: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x804213D0: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x804213D4: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x804213D8: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x804213DC: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x804213E0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x804213E4: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x804213E8: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x804213EC: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x804213F0: lwc1        $f18, 0x88($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X88);
    // 0x804213F4: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x804213F8: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x804213FC: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80421400: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x80421404: lw          $t9, 0x10($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X10);
    // 0x80421408: jalr        $t9
    // 0x8042140C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x8042140C: nop

    after_5:
    // 0x80421410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80421414:
    // 0x80421414: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80421418: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8042141C: jr          $ra
    // 0x80421420: nop

    return;
    // 0x80421420: nop

;}
RECOMP_FUNC void func_8000BD38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BD38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BD3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000BD40: lbu         $a2, 0x2($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X2);
    // 0x8000BD44: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8000BD48: bnel        $a2, $at, L_8000BD5C
    if (ctx->r6 != ctx->r1) {
        // 0x8000BD4C: lbu         $v1, 0x32($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X32);
            goto L_8000BD5C;
    }
    goto skip_0;
    // 0x8000BD4C: lbu         $v1, 0x32($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X32);
    skip_0:
    // 0x8000BD50: lw          $t6, 0x50($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X50);
    // 0x8000BD54: lh          $a2, 0x24($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X24);
    // 0x8000BD58: lbu         $v1, 0x32($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X32);
L_8000BD5C:
    // 0x8000BD5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000BD60: jal         0x8000BC34
    // 0x8000BD64: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8000BC34(rdram, ctx);
        goto after_0;
    // 0x8000BD64: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8000BD68: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BD6C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8000BD70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000BD74: beq         $v0, $v1, L_8000BD80
    if (ctx->r2 == ctx->r3) {
        // 0x8000BD78: addu        $t8, $t7, $v1
        ctx->r24 = ADD32(ctx->r15, ctx->r3);
            goto L_8000BD80;
    }
    // 0x8000BD78: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8000BD7C: sb          $t8, 0xB6($a0)
    MEM_B(0XB6, ctx->r4) = ctx->r24;
L_8000BD80:
    // 0x8000BD80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000BD84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000BD88: jr          $ra
    // 0x8000BD8C: nop

    return;
    // 0x8000BD8C: nop

;}
RECOMP_FUNC void func_8006E1B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E1B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006E1B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E1B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006E1BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006E1C0: jal         0x80081C64
    // 0x8006E1C4: lwc1        $f12, 0x8C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8C);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x8006E1C4: lwc1        $f12, 0x8C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8C);
    after_0:
    // 0x8006E1C8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8006E1CC: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x8006E1D0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8006E1D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006E1D8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8006E1DC: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8006E1E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006E1E4: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8006E1E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006E1EC: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8006E1F0: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8006E1F4: div.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8006E1F8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8006E1FC: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8006E200: jal         0x8006E154
    // 0x8006E204: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_8006E154(rdram, ctx);
        goto after_1;
    // 0x8006E204: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8006E208: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8006E20C: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8006E210: lw          $v0, 0x16C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X16C);
    // 0x8006E214: lbu         $t7, 0x24($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X24);
    // 0x8006E218: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x8006E21C: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x8006E220: sb          $t9, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r25;
    // 0x8006E224: lw          $v0, 0x16C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X16C);
    // 0x8006E228: lbu         $t0, 0x24($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X24);
    // 0x8006E22C: andi        $t1, $t0, 0xFFF0
    ctx->r9 = ctx->r8 & 0XFFF0;
    // 0x8006E230: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8006E234: sb          $t2, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r10;
    // 0x8006E238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E23C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006E240: jr          $ra
    // 0x8006E244: nop

    return;
    // 0x8006E244: nop

;}
RECOMP_FUNC void func_807ABF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ABF80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807ABF84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807ABF88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807ABF8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x807ABF90: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x807ABF94: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x807ABF98: jal         0x807ABA78
    // 0x807ABF9C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_807ABA78(rdram, ctx);
        goto after_0;
    // 0x807ABF9C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x807ABFA0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x807ABFA4: jal         0x807ABB78
    // 0x807ABFA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_807ABB78(rdram, ctx);
        goto after_1;
    // 0x807ABFA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x807ABFAC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x807ABFB0: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x807ABFB4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x807ABFB8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x807ABFBC: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x807ABFC0: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x807ABFC4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x807ABFC8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x807ABFCC: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x807ABFD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807ABFD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807ABFD8: jr          $ra
    // 0x807ABFDC: nop

    return;
    // 0x807ABFDC: nop

;}
RECOMP_FUNC void func_804BC948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BC948: lwc1        $f2, 0x364($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X364);
    // 0x804BC94C: lwc1        $f4, 0x36C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X36C);
    // 0x804BC950: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X417C) << 16);
    // 0x804BC954: lwc1        $f12, -0x554($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X417C));
    // 0x804BC958: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x804BC95C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4180) << 16);
    // 0x804BC960: lwc1        $f14, -0x550($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4180));
    // 0x804BC964: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4184) << 16);
    // 0x804BC968: mul.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x804BC96C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x804BC970: nop

    // 0x804BC974: bc1tl       L_804BC994
    if (c1cs) {
        // 0x804BC978: add.s       $f10, $f2, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
            goto L_804BC994;
    }
    goto skip_0;
    // 0x804BC978: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    skip_0:
    // 0x804BC97C: lwc1        $f8, -0x54C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4184));
    // 0x804BC980: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x804BC984: nop

    // 0x804BC988: bc1fl       L_804BC99C
    if (!c1cs) {
        // 0x804BC98C: lwc1        $f2, 0x360($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X360);
            goto L_804BC99C;
    }
    goto skip_1;
    // 0x804BC98C: lwc1        $f2, 0x360($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X360);
    skip_1:
    // 0x804BC990: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
L_804BC994:
    // 0x804BC994: swc1        $f10, 0x364($a0)
    MEM_W(0X364, ctx->r4) = ctx->f10.u32l;
    // 0x804BC998: lwc1        $f2, 0x360($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X360);
L_804BC99C:
    // 0x804BC99C: lwc1        $f16, 0x368($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X368);
    // 0x804BC9A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804BC9A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804BC9A8: sub.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x804BC9AC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804BC9B0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x804BC9B4: nop

    // 0x804BC9B8: bc1f        L_804BC9E4
    if (!c1cs) {
        // 0x804BC9BC: nop
    
            goto L_804BC9E4;
    }
    // 0x804BC9BC: nop

    // 0x804BC9C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BC9C4: nop

    // 0x804BC9C8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804BC9CC: nop

    // 0x804BC9D0: bc1f        L_804BC9E4
    if (!c1cs) {
        // 0x804BC9D4: nop
    
            goto L_804BC9E4;
    }
    // 0x804BC9D4: nop

    // 0x804BC9D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804BC9DC: b           L_804BC9F0
    // 0x804BC9E0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
        goto L_804BC9F0;
    // 0x804BC9E0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_804BC9E4:
    // 0x804BC9E4: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x804BC9E8: nop

    // 0x804BC9EC: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_804BC9F0:
    // 0x804BC9F0: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4188) << 16);
    // 0x804BC9F4: bc1tl       L_804BCA14
    if (c1cs) {
        // 0x804BC9F8: add.s       $f8, $f2, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f0.fl;
            goto L_804BCA14;
    }
    goto skip_2;
    // 0x804BC9F8: add.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f0.fl;
    skip_2:
    // 0x804BC9FC: lwc1        $f6, -0x548($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4188));
    // 0x804BCA00: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804BCA04: nop

    // 0x804BCA08: bc1f        L_804BCA18
    if (!c1cs) {
        // 0x804BCA0C: nop
    
            goto L_804BCA18;
    }
    // 0x804BCA0C: nop

    // 0x804BCA10: add.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f0.fl;
L_804BCA14:
    // 0x804BCA14: swc1        $f8, 0x360($a0)
    MEM_W(0X360, ctx->r4) = ctx->f8.u32l;
L_804BCA18:
    // 0x804BCA18: jr          $ra
    // 0x804BCA1C: nop

    return;
    // 0x804BCA1C: nop

;}
RECOMP_FUNC void func_807B9178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9178: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B917C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B9180: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B9184: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B9188: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B918C: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x807B9190: lui         $s2, 0x807C
    ctx->r18 = S32(RELOC_HI16(886, 0X1D0C) << 16);
    // 0x807B9194: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B9198: addiu       $s2, $s2, -0x6084
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(886, 0X1D0C));
    // 0x807B919C: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x807B91A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B91A4: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
L_807B91A8:
    // 0x807B91A8: sh          $zero, 0xFC0($s1)
    MEM_H(0XFC0, ctx->r17) = 0;
    // 0x807B91AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B91B0: jal         0x80069610
    // 0x807B91B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80069610(rdram, ctx);
        goto after_0;
    // 0x807B91B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x807B91B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x807B91BC: bne         $s0, $s3, L_807B91A8
    if (ctx->r16 != ctx->r19) {
        // 0x807B91C0: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_807B91A8;
    }
    // 0x807B91C0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x807B91C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B91C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B91CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B91D0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B91D4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B91D8: jr          $ra
    // 0x807B91DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807B91DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806820FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806820FC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80682100: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80682104: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80682108: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8068210C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682110: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80682114: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80682118: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8068211C: lui         $t1, 0x8068
    ctx->r9 = S32(RELOC_HI16(550, 0X2228) << 16);
    // 0x80682120: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80682124: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80682128: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8068212C: lw          $t1, 0x2638($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(550, 0X2228));
    // 0x80682130: jr          $ra
    // 0x80682134: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80682134: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x80682138: nop

    // 0x8068213C: nop

;}
RECOMP_FUNC void func_806F9F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9F30: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x806F9F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F9F38: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x806F9F3C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x806F9F40: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x806F9F44: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806F9F48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806F9F4C: sw          $a3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r7;
    // 0x806F9F50: jal         0x8004921C
    // 0x806F9F54: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x806F9F54: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    after_0:
    // 0x806F9F58: lw          $a0, 0xE4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE4);
    // 0x806F9F5C: sh          $v0, 0xDA($sp)
    MEM_H(0XDA, ctx->r29) = ctx->r2;
    // 0x806F9F60: jal         0x8004921C
    // 0x806F9F64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x806F9F64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x806F9F68: lw          $a3, 0xE4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE4);
    // 0x806F9F6C: sh          $v0, 0xD8($sp)
    MEM_H(0XD8, ctx->r29) = ctx->r2;
    // 0x806F9F70: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    // 0x806F9F74: lw          $t8, 0x180($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X180);
    // 0x806F9F78: lw          $t6, 0x168($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X168);
    // 0x806F9F7C: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x806F9F80: lw          $t9, 0x1F4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1F4);
    // 0x806F9F84: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(700, 0X2A78) << 16);
    // 0x806F9F88: lw          $t0, 0x80($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X80);
    // 0x806F9F8C: lw          $v1, 0x14C8($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X14C8);
    // 0x806F9F90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F9F94: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x806F9F98: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806F9F9C: lw          $t8, -0x3958($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(700, 0X2A78));
    // 0x806F9FA0: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x806F9FA4: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x806F9FA8: lw          $t6, 0x16C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X16C);
    // 0x806F9FAC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x806F9FB0: sw          $t0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r8;
    // 0x806F9FB4: jal         0x80077338
    // 0x806F9FB8: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x806F9FB8: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    after_2:
    // 0x806F9FBC: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    // 0x806F9FC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806F9FC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806F9FC8: jal         0x8007711C
    // 0x806F9FCC: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x806F9FCC: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    after_3:
    // 0x806F9FD0: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x806F9FD4: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x806F9FD8: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(700, 0X2918) << 16);
    // 0x806F9FDC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806F9FE0: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x806F9FE4: addiu       $t7, $t7, -0x3AB8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(700, 0X2918));
    // 0x806F9FE8: ori         $t6, $t6, 0x40FF
    ctx->r14 = ctx->r14 | 0X40FF;
    // 0x806F9FEC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x806F9FF0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x806F9FF4: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x806F9FF8: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x806F9FFC: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x806FA000: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806FA004: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x806FA008: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x806FA00C: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x806FA010: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x806FA014: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x806FA018: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA01C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806FA020: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x806FA024: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x806FA028: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x806FA02C: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA030: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x806FA034: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x806FA038: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806FA03C: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x806FA040: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x806FA044: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x806FA048: lw          $t4, 0xDC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA04C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x806FA050: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x806FA054: addiu       $t7, $t4, 0x8
    ctx->r15 = ADD32(ctx->r12, 0X8);
    // 0x806FA058: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x806FA05C: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x806FA060: lh          $t9, 0xD8($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XD8);
    // 0x806FA064: lh          $v1, 0xDA($sp)
    ctx->r3 = MEM_H(ctx->r29, 0XDA);
    // 0x806FA068: multu       $v1, $t9
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806FA06C: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x806FA070: addiu       $ra, $t3, 0x7
    ctx->r31 = ADD32(ctx->r11, 0X7);
    // 0x806FA074: sra         $ra, $ra, 3
    ctx->r31 = S32(SIGNED(ctx->r31) >> 3);
    // 0x806FA078: andi        $ra, $ra, 0x1FF
    ctx->r31 = ctx->r31 & 0X1FF;
    // 0x806FA07C: mflo        $t2
    ctx->r10 = lo;
    // 0x806FA080: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x806FA084: sra         $t2, $t2, 1
    ctx->r10 = S32(SIGNED(ctx->r10) >> 1);
    // 0x806FA088: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x806FA08C: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x806FA090: beql        $at, $zero, L_806FA0A4
    if (ctx->r1 == 0) {
        // 0x806FA094: addiu       $t1, $zero, 0x7FF
        ctx->r9 = ADD32(0, 0X7FF);
            goto L_806FA0A4;
    }
    goto skip_0;
    // 0x806FA094: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    skip_0:
    // 0x806FA098: b           L_806FA0A4
    // 0x806FA09C: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_806FA0A4;
    // 0x806FA09C: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
    // 0x806FA0A0: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
L_806FA0A4:
    // 0x806FA0A4: bgez        $t3, L_806FA0B4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x806FA0A8: sra         $a3, $t3, 3
        ctx->r7 = S32(SIGNED(ctx->r11) >> 3);
            goto L_806FA0B4;
    }
    // 0x806FA0A8: sra         $a3, $t3, 3
    ctx->r7 = S32(SIGNED(ctx->r11) >> 3);
    // 0x806FA0AC: addiu       $at, $t3, 0x7
    ctx->r1 = ADD32(ctx->r11, 0X7);
    // 0x806FA0B0: sra         $a3, $at, 3
    ctx->r7 = S32(SIGNED(ctx->r1) >> 3);
L_806FA0B4:
    // 0x806FA0B4: bgtzl       $a3, L_806FA0C8
    if (SIGNED(ctx->r7) > 0) {
        // 0x806FA0B8: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_806FA0C8;
    }
    goto skip_1;
    // 0x806FA0B8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    skip_1:
    // 0x806FA0BC: b           L_806FA0C8
    // 0x806FA0C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_806FA0C8;
    // 0x806FA0C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806FA0C4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
L_806FA0C8:
    // 0x806FA0C8: bgtz        $a3, L_806FA0D8
    if (SIGNED(ctx->r7) > 0) {
        // 0x806FA0CC: addiu       $t6, $a2, 0x7FF
        ctx->r14 = ADD32(ctx->r6, 0X7FF);
            goto L_806FA0D8;
    }
    // 0x806FA0CC: addiu       $t6, $a2, 0x7FF
    ctx->r14 = ADD32(ctx->r6, 0X7FF);
    // 0x806FA0D0: b           L_806FA0DC
    // 0x806FA0D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806FA0DC;
    // 0x806FA0D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806FA0D8:
    // 0x806FA0D8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_806FA0DC:
    // 0x806FA0DC: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x806FA0E0: mflo        $t7
    ctx->r15 = lo;
    // 0x806FA0E4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x806FA0E8: bne         $v0, $zero, L_806FA0F4
    if (ctx->r2 != 0) {
        // 0x806FA0EC: nop
    
            goto L_806FA0F4;
    }
    // 0x806FA0EC: nop

    // 0x806FA0F0: break       7
    do_break(2154799344);
L_806FA0F4:
    // 0x806FA0F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806FA0F8: bne         $v0, $at, L_806FA10C
    if (ctx->r2 != ctx->r1) {
        // 0x806FA0FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806FA10C;
    }
    // 0x806FA0FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806FA100: bne         $t6, $at, L_806FA10C
    if (ctx->r14 != ctx->r1) {
        // 0x806FA104: nop
    
            goto L_806FA10C;
    }
    // 0x806FA104: nop

    // 0x806FA108: break       6
    do_break(2154799368);
L_806FA10C:
    // 0x806FA10C: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x806FA110: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x806FA114: or          $t9, $t8, $t5
    ctx->r25 = ctx->r24 | ctx->r13;
    // 0x806FA118: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x806FA11C: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x806FA120: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA124: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x806FA128: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x806FA12C: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x806FA130: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x806FA134: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x806FA138: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x806FA13C: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA140: sll         $ra, $ra, 9
    ctx->r31 = S32(ctx->r31 << 9);
    // 0x806FA144: or          $ra, $ra, $at
    ctx->r31 = ctx->r31 | ctx->r1;
    // 0x806FA148: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x806FA14C: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x806FA150: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x806FA154: sw          $ra, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r31;
    // 0x806FA158: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA15C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x806FA160: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x806FA164: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x806FA168: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x806FA16C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x806FA170: lh          $t6, 0xDA($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XDA);
    // 0x806FA174: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x806FA178: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x806FA17C: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x806FA180: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x806FA184: lh          $t9, 0xD8($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XD8);
    // 0x806FA188: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x806FA18C: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x806FA190: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x806FA194: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806FA198: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x806FA19C: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x806FA1A0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x806FA1A4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x806FA1A8: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA1AC: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(700, 0X2A18) << 16);
    // 0x806FA1B0: addiu       $t9, $t9, -0x39B8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(700, 0X2A18));
    // 0x806FA1B4: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x806FA1B8: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x806FA1BC: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x806FA1C0: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x806FA1C4: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA1C8: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x806FA1CC: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x806FA1D0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806FA1D4: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x806FA1D8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806FA1DC: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x806FA1E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x806FA1E4: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x806FA1E8: addiu       $t7, $t9, 0x1800
    ctx->r15 = ADD32(ctx->r25, 0X1800);
    // 0x806FA1EC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x806FA1F0: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA1F4: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x806FA1F8: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x806FA1FC: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x806FA200: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x806FA204: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x806FA208: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA20C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x806FA210: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x806FA214: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806FA218: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x806FA21C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x806FA220: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806FA224: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA228: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x806FA22C: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x806FA230: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x806FA234: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x806FA238: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x806FA23C: beq         $at, $zero, L_806FA24C
    if (ctx->r1 == 0) {
        // 0x806FA240: or          $t3, $t9, $zero
        ctx->r11 = ctx->r25 | 0;
            goto L_806FA24C;
    }
    // 0x806FA240: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x806FA244: b           L_806FA24C
    // 0x806FA248: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_806FA24C;
    // 0x806FA248: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_806FA24C:
    // 0x806FA24C: bgtz        $a3, L_806FA25C
    if (SIGNED(ctx->r7) > 0) {
        // 0x806FA250: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_806FA25C;
    }
    // 0x806FA250: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x806FA254: b           L_806FA25C
    // 0x806FA258: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_806FA25C;
    // 0x806FA258: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_806FA25C:
    // 0x806FA25C: bgtz        $a3, L_806FA26C
    if (SIGNED(ctx->r7) > 0) {
        // 0x806FA260: addiu       $t6, $a2, 0x7FF
        ctx->r14 = ADD32(ctx->r6, 0X7FF);
            goto L_806FA26C;
    }
    // 0x806FA260: addiu       $t6, $a2, 0x7FF
    ctx->r14 = ADD32(ctx->r6, 0X7FF);
    // 0x806FA264: b           L_806FA270
    // 0x806FA268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806FA270;
    // 0x806FA268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806FA26C:
    // 0x806FA26C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_806FA270:
    // 0x806FA270: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x806FA274: mflo        $t9
    ctx->r25 = lo;
    // 0x806FA278: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x806FA27C: bne         $v0, $zero, L_806FA288
    if (ctx->r2 != 0) {
        // 0x806FA280: nop
    
            goto L_806FA288;
    }
    // 0x806FA280: nop

    // 0x806FA284: break       7
    do_break(2154799748);
L_806FA288:
    // 0x806FA288: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806FA28C: bne         $v0, $at, L_806FA2A0
    if (ctx->r2 != ctx->r1) {
        // 0x806FA290: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806FA2A0;
    }
    // 0x806FA290: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806FA294: bne         $t6, $at, L_806FA2A0
    if (ctx->r14 != ctx->r1) {
        // 0x806FA298: nop
    
            goto L_806FA2A0;
    }
    // 0x806FA298: nop

    // 0x806FA29C: break       6
    do_break(2154799772);
L_806FA2A0:
    // 0x806FA2A0: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x806FA2A4: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x806FA2A8: or          $t8, $t7, $t5
    ctx->r24 = ctx->r15 | ctx->r13;
    // 0x806FA2AC: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x806FA2B0: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x806FA2B4: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA2B8: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x806FA2BC: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x806FA2C0: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x806FA2C4: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x806FA2C8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x806FA2CC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x806FA2D0: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA2D4: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x806FA2D8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x806FA2DC: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x806FA2E0: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x806FA2E4: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x806FA2E8: sw          $ra, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r31;
    // 0x806FA2EC: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA2F0: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x806FA2F4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806FA2F8: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x806FA2FC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806FA300: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x806FA304: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x806FA308: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(700, 0X2A30) << 16);
    // 0x806FA30C: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x806FA310: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA314: addiu       $t7, $t7, -0x39A0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(700, 0X2A30));
    // 0x806FA318: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806FA31C: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x806FA320: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x806FA324: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x806FA328: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA32C: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x806FA330: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x806FA334: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x806FA338: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x806FA33C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x806FA340: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x806FA344: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x806FA348: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x806FA34C: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x806FA350: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA354: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x806FA358: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x806FA35C: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x806FA360: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x806FA364: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x806FA368: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA36C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x806FA370: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x806FA374: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x806FA378: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x806FA37C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x806FA380: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x806FA384: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA388: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x806FA38C: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x806FA390: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x806FA394: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x806FA398: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x806FA39C: beq         $at, $zero, L_806FA3AC
    if (ctx->r1 == 0) {
        // 0x806FA3A0: or          $t3, $t9, $zero
        ctx->r11 = ctx->r25 | 0;
            goto L_806FA3AC;
    }
    // 0x806FA3A0: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x806FA3A4: b           L_806FA3AC
    // 0x806FA3A8: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_806FA3AC;
    // 0x806FA3A8: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_806FA3AC:
    // 0x806FA3AC: bgtz        $a3, L_806FA3BC
    if (SIGNED(ctx->r7) > 0) {
        // 0x806FA3B0: nop
    
            goto L_806FA3BC;
    }
    // 0x806FA3B0: nop

    // 0x806FA3B4: b           L_806FA3BC
    // 0x806FA3B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_806FA3BC;
    // 0x806FA3B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_806FA3BC:
    // 0x806FA3BC: bgtz        $a3, L_806FA3CC
    if (SIGNED(ctx->r7) > 0) {
        // 0x806FA3C0: addiu       $t8, $a2, 0x7FF
        ctx->r24 = ADD32(ctx->r6, 0X7FF);
            goto L_806FA3CC;
    }
    // 0x806FA3C0: addiu       $t8, $a2, 0x7FF
    ctx->r24 = ADD32(ctx->r6, 0X7FF);
    // 0x806FA3C4: b           L_806FA3CC
    // 0x806FA3C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806FA3CC;
    // 0x806FA3C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806FA3CC:
    // 0x806FA3CC: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x806FA3D0: mflo        $t9
    ctx->r25 = lo;
    // 0x806FA3D4: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x806FA3D8: bne         $v0, $zero, L_806FA3E4
    if (ctx->r2 != 0) {
        // 0x806FA3DC: nop
    
            goto L_806FA3E4;
    }
    // 0x806FA3DC: nop

    // 0x806FA3E0: break       7
    do_break(2154800096);
L_806FA3E4:
    // 0x806FA3E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806FA3E8: bne         $v0, $at, L_806FA3FC
    if (ctx->r2 != ctx->r1) {
        // 0x806FA3EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806FA3FC;
    }
    // 0x806FA3EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806FA3F0: bne         $t8, $at, L_806FA3FC
    if (ctx->r24 != ctx->r1) {
        // 0x806FA3F4: nop
    
            goto L_806FA3FC;
    }
    // 0x806FA3F4: nop

    // 0x806FA3F8: break       6
    do_break(2154800120);
L_806FA3FC:
    // 0x806FA3FC: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x806FA400: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x806FA404: or          $t6, $t7, $t5
    ctx->r14 = ctx->r15 | ctx->r13;
    // 0x806FA408: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x806FA40C: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x806FA410: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA414: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x806FA418: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x806FA41C: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x806FA420: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x806FA424: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x806FA428: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x806FA42C: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA430: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x806FA434: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x806FA438: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806FA43C: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x806FA440: sw          $ra, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r31;
    // 0x806FA444: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x806FA448: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA44C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x806FA450: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x806FA454: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x806FA458: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x806FA45C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x806FA460: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x806FA464: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(700, 0X2A48) << 16);
    // 0x806FA468: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x806FA46C: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA470: addiu       $t7, $t7, -0x3988
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(700, 0X2A48));
    // 0x806FA474: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x806FA478: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x806FA47C: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x806FA480: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x806FA484: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA488: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x806FA48C: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x806FA490: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x806FA494: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x806FA498: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x806FA49C: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x806FA4A0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x806FA4A4: addiu       $t8, $t7, 0x1000
    ctx->r24 = ADD32(ctx->r15, 0X1000);
    // 0x806FA4A8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x806FA4AC: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA4B0: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x806FA4B4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x806FA4B8: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x806FA4BC: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x806FA4C0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x806FA4C4: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x806FA4C8: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA4CC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x806FA4D0: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x806FA4D4: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x806FA4D8: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x806FA4DC: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x806FA4E0: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x806FA4E4: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA4E8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x806FA4EC: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x806FA4F0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806FA4F4: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x806FA4F8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806FA4FC: beq         $at, $zero, L_806FA50C
    if (ctx->r1 == 0) {
        // 0x806FA500: or          $t3, $t7, $zero
        ctx->r11 = ctx->r15 | 0;
            goto L_806FA50C;
    }
    // 0x806FA500: or          $t3, $t7, $zero
    ctx->r11 = ctx->r15 | 0;
    // 0x806FA504: b           L_806FA50C
    // 0x806FA508: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_806FA50C;
    // 0x806FA508: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_806FA50C:
    // 0x806FA50C: bgtz        $a3, L_806FA51C
    if (SIGNED(ctx->r7) > 0) {
        // 0x806FA510: nop
    
            goto L_806FA51C;
    }
    // 0x806FA510: nop

    // 0x806FA514: b           L_806FA51C
    // 0x806FA518: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_806FA51C;
    // 0x806FA518: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_806FA51C:
    // 0x806FA51C: bgtz        $a3, L_806FA52C
    if (SIGNED(ctx->r7) > 0) {
        // 0x806FA520: addiu       $t9, $a2, 0x7FF
        ctx->r25 = ADD32(ctx->r6, 0X7FF);
            goto L_806FA52C;
    }
    // 0x806FA520: addiu       $t9, $a2, 0x7FF
    ctx->r25 = ADD32(ctx->r6, 0X7FF);
    // 0x806FA524: b           L_806FA52C
    // 0x806FA528: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806FA52C;
    // 0x806FA528: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806FA52C:
    // 0x806FA52C: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x806FA530: mflo        $t7
    ctx->r15 = lo;
    // 0x806FA534: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x806FA538: bne         $v0, $zero, L_806FA544
    if (ctx->r2 != 0) {
        // 0x806FA53C: nop
    
            goto L_806FA544;
    }
    // 0x806FA53C: nop

    // 0x806FA540: break       7
    do_break(2154800448);
L_806FA544:
    // 0x806FA544: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806FA548: bne         $v0, $at, L_806FA55C
    if (ctx->r2 != ctx->r1) {
        // 0x806FA54C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806FA55C;
    }
    // 0x806FA54C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806FA550: bne         $t9, $at, L_806FA55C
    if (ctx->r25 != ctx->r1) {
        // 0x806FA554: nop
    
            goto L_806FA55C;
    }
    // 0x806FA554: nop

    // 0x806FA558: break       6
    do_break(2154800472);
L_806FA55C:
    // 0x806FA55C: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x806FA560: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x806FA564: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x806FA568: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x806FA56C: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x806FA570: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA574: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x806FA578: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x806FA57C: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x806FA580: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x806FA584: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x806FA588: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA58C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x806FA590: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806FA594: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x806FA598: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x806FA59C: sw          $ra, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r31;
    // 0x806FA5A0: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA5A4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x806FA5A8: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x806FA5AC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x806FA5B0: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x806FA5B4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x806FA5B8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x806FA5BC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x806FA5C0: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(700, 0X2A60) << 16);
    // 0x806FA5C4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x806FA5C8: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA5CC: addiu       $t8, $t8, -0x3970
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(700, 0X2A60));
    // 0x806FA5D0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x806FA5D4: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x806FA5D8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x806FA5DC: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x806FA5E0: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x806FA5E4: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x806FA5E8: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x806FA5EC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x806FA5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FA5F4: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x806FA5F8: jr          $ra
    // 0x806FA5FC: nop

    return;
    // 0x806FA5FC: nop

;}
RECOMP_FUNC void func_8042F9D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F9D8: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8042F9DC: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0X1630) << 16);
    // 0x8042F9E0: addiu       $t6, $t6, -0x8F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0X1630));
    // 0x8042F9E4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8042F9E8: jr          $ra
    // 0x8042F9EC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8042F9EC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80018EBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018EBC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80018EC0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80018EC4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80018EC8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80018ECC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80018ED0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80018ED4: sh          $a0, -0x6D20($at)
    MEM_H(-0X6D20, ctx->r1) = ctx->r4;
    // 0x80018ED8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80018EDC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80018EE0: jr          $ra
    // 0x80018EE4: sh          $a1, -0x6D1C($at)
    MEM_H(-0X6D1C, ctx->r1) = ctx->r5;
    return;
    // 0x80018EE4: sh          $a1, -0x6D1C($at)
    MEM_H(-0X6D1C, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_80517388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517388: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051738C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80517390: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80517394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80517398: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8051739C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805173A0: lui         $t8, 0x8051
    ctx->r24 = S32(RELOC_HI16(285, 0X3C0) << 16);
    // 0x805173A4: sb          $a2, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r6;
    // 0x805173A8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805173AC: lw          $t8, 0x74D0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(285, 0X3C0));
    // 0x805173B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805173B4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x805173B8: jal         0x805172C0
    // 0x805173BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805172C0(rdram, ctx);
        goto after_0;
    // 0x805173BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805173C0: jal         0x8051731C
    // 0x805173C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8051731C(rdram, ctx);
        goto after_1;
    // 0x805173C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805173C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805173CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805173D0: jr          $ra
    // 0x805173D4: nop

    return;
    // 0x805173D4: nop

    // 0x805173D8: nop

    // 0x805173DC: nop

;}
RECOMP_FUNC void func_8049ECEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049ECEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8049ECF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8049ECF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8049ECF8: jal         0x8004700C
    // 0x8049ECFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8049ECFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8049ED00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8049ED04: beq         $v0, $zero, L_8049EDB4
    if (ctx->r2 == 0) {
        // 0x8049ED08: lw          $v1, 0x1F4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X1F4);
            goto L_8049EDB4;
    }
    // 0x8049ED08: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8049ED0C: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8049ED10: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8049ED14: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8049ED18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049ED1C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8049ED20: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8049ED24: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8049ED28: nop

    // 0x8049ED2C: bc1f        L_8049ED4C
    if (!c1cs) {
        // 0x8049ED30: nop
    
            goto L_8049ED4C;
    }
    // 0x8049ED30: nop

    // 0x8049ED34: lbu         $a2, 0x30($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X30);
    // 0x8049ED38: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8049ED3C: jal         0x8049FBAC
    // 0x8049ED40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8049FBAC(rdram, ctx);
        goto after_1;
    // 0x8049ED40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8049ED44: b           L_8049ED78
    // 0x8049ED48: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
        goto L_8049ED78;
    // 0x8049ED48: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_8049ED4C:
    // 0x8049ED4C: jal         0x80049018
    // 0x8049ED50: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80049018(rdram, ctx);
        goto after_2;
    // 0x8049ED50: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_2:
    // 0x8049ED54: beq         $v0, $zero, L_8049ED6C
    if (ctx->r2 == 0) {
        // 0x8049ED58: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_8049ED6C;
    }
    // 0x8049ED58: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8049ED5C: lhu         $t6, 0x8($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X8);
    // 0x8049ED60: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8049ED64: b           L_8049ED78
    // 0x8049ED68: sh          $t7, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r15;
        goto L_8049ED78;
    // 0x8049ED68: sh          $t7, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r15;
L_8049ED6C:
    // 0x8049ED6C: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X12BC) << 16);
    // 0x8049ED70: lwc1        $f10, -0x1C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(167, 0X12BC));
    // 0x8049ED74: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
L_8049ED78:
    // 0x8049ED78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049ED7C: jal         0x8049EBD8
    // 0x8049ED80: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8049EBD8(rdram, ctx);
        goto after_3;
    // 0x8049ED80: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x8049ED84: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x8049ED88: beq         $t8, $zero, L_8049EDA8
    if (ctx->r24 == 0) {
        // 0x8049ED8C: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_8049EDA8;
    }
    // 0x8049ED8C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8049ED90: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
    // 0x8049ED94: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x8049ED98: sh          $t1, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r9;
    // 0x8049ED9C: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x8049EDA0: b           L_8049EDB4
    // 0x8049EDA4: sh          $t2, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r10;
        goto L_8049EDB4;
    // 0x8049EDA4: sh          $t2, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r10;
L_8049EDA8:
    // 0x8049EDA8: lhu         $t3, 0x8($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X8);
    // 0x8049EDAC: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x8049EDB0: sh          $t4, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r12;
L_8049EDB4:
    // 0x8049EDB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8049EDB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8049EDBC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8049EDC0: jr          $ra
    // 0x8049EDC4: nop

    return;
    // 0x8049EDC4: nop

;}
RECOMP_FUNC void func_80036F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036F00: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80036F04: lw          $v0, 0x138($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X138);
    // 0x80036F08: lbu         $v1, -0x7684($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X7684);
    // 0x80036F0C: beql        $v0, $v1, L_80036F30
    if (ctx->r2 == ctx->r3) {
        // 0x80036F10: sw          $zero, 0x120($a1)
        MEM_W(0X120, ctx->r5) = 0;
            goto L_80036F30;
    }
    goto skip_0;
    // 0x80036F10: sw          $zero, 0x120($a1)
    MEM_W(0X120, ctx->r5) = 0;
    skip_0:
    // 0x80036F14: lw          $v0, 0x120($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X120);
    // 0x80036F18: sltiu       $at, $v0, 0x3C
    ctx->r1 = ctx->r2 < 0X3C ? 1 : 0;
    // 0x80036F1C: beq         $at, $zero, L_80036F30
    if (ctx->r1 == 0) {
        // 0x80036F20: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80036F30;
    }
    // 0x80036F20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80036F24: jr          $ra
    // 0x80036F28: sw          $v0, 0x120($a1)
    MEM_W(0X120, ctx->r5) = ctx->r2;
    return;
    // 0x80036F28: sw          $v0, 0x120($a1)
    MEM_W(0X120, ctx->r5) = ctx->r2;
    // 0x80036F2C: sw          $zero, 0x120($a1)
    MEM_W(0X120, ctx->r5) = 0;
L_80036F30:
    // 0x80036F30: jr          $ra
    // 0x80036F34: nop

    return;
    // 0x80036F34: nop

;}
RECOMP_FUNC void func_80071878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071878: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007187C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80071880: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80071884: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80071888: addiu       $v1, $v1, -0x7AF0
    ctx->r3 = ADD32(ctx->r3, -0X7AF0);
    // 0x8007188C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80071890: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80071894: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80071898: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007189C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800718A0: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x800718A4: addiu       $s2, $s2, -0x7B7C
    ctx->r18 = ADD32(ctx->r18, -0X7B7C);
    // 0x800718A8: beq         $v0, $zero, L_800718C4
    if (ctx->r2 == 0) {
        // 0x800718AC: nop
    
            goto L_800718C4;
    }
    // 0x800718AC: nop

    // 0x800718B0: lhu         $t6, 0xA($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XA);
    // 0x800718B4: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x800718B8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800718BC: lhu         $t7, 0xC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC);
    // 0x800718C0: sh          $t7, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r15;
L_800718C4:
    // 0x800718C4: blez        $s1, L_800718E8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800718C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800718E8;
    }
L_800718C8:
    // 0x800718C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800718CC: jal         0x8007180C
    // 0x800718D0: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    func_8007180C(rdram, ctx);
        goto after_0;
    // 0x800718D0: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    after_0:
    // 0x800718D4: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800718D8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800718DC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800718E0: bgtz        $s1, L_800718C8
    if (SIGNED(ctx->r17) > 0) {
        // 0x800718E4: sw          $t0, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r8;
            goto L_800718C8;
    }
    // 0x800718E4: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
L_800718E8:
    // 0x800718E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800718EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800718F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800718F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800718F8: jr          $ra
    // 0x800718FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800718FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_804BD6D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD6D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BD6DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD6E0: jal         0x800653D8
    // 0x804BD6E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x804BD6E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BD6E8: andi        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 & 0X7;
    // 0x804BD6EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804BD6F0: lui         $t9, 0x804C
    ctx->r25 = S32(RELOC_HI16(191, 0X40B0) << 16);
    // 0x804BD6F4: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x804BD6F8: lw          $t9, -0x620($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(191, 0X40B0));
    // 0x804BD6FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BD700: jalr        $t9
    // 0x804BD704: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x804BD704: nop

    after_1:
    // 0x804BD708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BD70C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BD710: jr          $ra
    // 0x804BD714: nop

    return;
    // 0x804BD714: nop

;}
RECOMP_FUNC void func_804C0288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0288: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C028C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C0290: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804C0294: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x804C0298: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804C029C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x804C02A0: jal         0x804C0188
    // 0x804C02A4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_804C0188(rdram, ctx);
        goto after_0;
    // 0x804C02A4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x804C02A8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804C02AC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x804C02B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C02B4: lwc1        $f4, 0x70($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X70);
    // 0x804C02B8: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x804C02BC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x804C02C0: mul.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804C02C4: beq         $v1, $at, L_804C02D8
    if (ctx->r3 == ctx->r1) {
        // 0x804C02C8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_804C02D8;
    }
    // 0x804C02C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804C02CC: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x804C02D0: bnel        $v1, $at, L_804C0310
    if (ctx->r3 != ctx->r1) {
        // 0x804C02D4: lw          $v1, 0x138($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X138);
            goto L_804C0310;
    }
    goto skip_0;
    // 0x804C02D4: lw          $v1, 0x138($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X138);
    skip_0:
L_804C02D8:
    // 0x804C02D8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x804C02DC: lwc1        $f2, 0x40($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804C02E0: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804C02E4: lwc1        $f0, 0x8($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X8);
    // 0x804C02E8: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804C02EC: div.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x804C02F0: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x804C02F4: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x804C02F8: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x804C02FC: nop

    // 0x804C0300: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x804C0304: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    // 0x804C0308: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    // 0x804C030C: lw          $v1, 0x138($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X138);
L_804C0310:
    // 0x804C0310: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804C0314: beq         $v1, $at, L_804C0320
    if (ctx->r3 == ctx->r1) {
        // 0x804C0318: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_804C0320;
    }
    // 0x804C0318: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x804C031C: bne         $v1, $at, L_804C0330
    if (ctx->r3 != ctx->r1) {
        // 0x804C0320: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_804C0330;
    }
L_804C0320:
    // 0x804C0320: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C0324: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C0328: nop

    // 0x804C032C: sub.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f6.fl;
L_804C0330:
    // 0x804C0330: swc1        $f14, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f14.u32l;
    // 0x804C0334: lw          $t8, 0x138($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X138);
    // 0x804C0338: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(194, 0X2F8) << 16);
    // 0x804C033C: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804C0340: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804C0344: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x804C0348: lwc1        $f10, 0x408($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(194, 0X2F8));
    // 0x804C034C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804C0350: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
    // 0x804C0354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C0358: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C035C: jr          $ra
    // 0x804C0360: nop

    return;
    // 0x804C0360: nop

;}
RECOMP_FUNC void func_804CF3A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF3A4: lh          $a1, 0x184($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X184);
    // 0x804CF3A8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CF3AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x804CF3B0: blez        $a1, L_804CF438
    if (SIGNED(ctx->r5) <= 0) {
        // 0x804CF3B4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_804CF438;
    }
    // 0x804CF3B4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804CF3B8: addiu       $t0, $zero, 0x4123
    ctx->r8 = ADD32(0, 0X4123);
L_804CF3BC:
    // 0x804CF3BC: lw          $a2, 0x188($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X188);
    // 0x804CF3C0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x804CF3C4: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x804CF3C8: beq         $a2, $zero, L_804CF430
    if (ctx->r6 == 0) {
        // 0x804CF3CC: nop
    
            goto L_804CF430;
    }
    // 0x804CF3CC: nop

    // 0x804CF3D0: lhu         $t6, 0xC($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0XC);
    // 0x804CF3D4: bne         $t0, $t6, L_804CF430
    if (ctx->r8 != ctx->r14) {
        // 0x804CF3D8: nop
    
            goto L_804CF430;
    }
    // 0x804CF3D8: nop

    // 0x804CF3DC: lw          $v1, 0x1F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1F4);
    // 0x804CF3E0: beq         $v1, $zero, L_804CF41C
    if (ctx->r3 == 0) {
        // 0x804CF3E4: nop
    
            goto L_804CF41C;
    }
    // 0x804CF3E4: nop

    // 0x804CF3E8: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804CF3EC: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x804CF3F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804CF3F4: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x804CF3F8: lh          $t9, 0x56($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X56);
    // 0x804CF3FC: lw          $t8, 0x70($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X70);
    // 0x804CF400: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x804CF404: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x804CF408: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804CF40C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x804CF410: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x804CF414: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x804CF418: lw          $v1, 0x1F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1F4);
L_804CF41C:
    // 0x804CF41C: beq         $v1, $zero, L_804CF438
    if (ctx->r3 == 0) {
        // 0x804CF420: nop
    
            goto L_804CF438;
    }
    // 0x804CF420: nop

    // 0x804CF424: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804CF428: jr          $ra
    // 0x804CF42C: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    return;
    // 0x804CF42C: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
L_804CF430:
    // 0x804CF430: bne         $at, $zero, L_804CF3BC
    if (ctx->r1 != 0) {
        // 0x804CF434: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_804CF3BC;
    }
    // 0x804CF434: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_804CF438:
    // 0x804CF438: jr          $ra
    // 0x804CF43C: nop

    return;
    // 0x804CF43C: nop

;}
RECOMP_FUNC void func_80023DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023DD0: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x80023DD4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80023DD8: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80023DDC: bc1fl       L_80023E10
    if (!c1cs) {
        // 0x80023DE0: add.s       $f0, $f12, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f8.fl;
            goto L_80023E10;
    }
    goto skip_0;
    // 0x80023DE0: add.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f8.fl;
    skip_0:
    // 0x80023DE4: sub.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x80023DE8: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80023DEC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80023DF0: nop

    // 0x80023DF4: bc1f        L_80023E04
    if (!c1cs) {
        // 0x80023DF8: nop
    
            goto L_80023E04;
    }
    // 0x80023DF8: nop

    // 0x80023DFC: jr          $ra
    // 0x80023E00: sub.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f4.fl;
    return;
    // 0x80023E00: sub.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f4.fl;
L_80023E04:
    // 0x80023E04: jr          $ra
    // 0x80023E08: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    return;
    // 0x80023E08: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x80023E0C: add.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f8.fl;
L_80023E10:
    // 0x80023E10: jr          $ra
    // 0x80023E14: nop

    return;
    // 0x80023E14: nop

;}
RECOMP_FUNC void func_807B5198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B5198: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807B519C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807B51A0: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x807B51A4: lbu         $t7, 0xF5C($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XF5C);
    // 0x807B51A8: lbu         $t9, 0xF5D($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF5D);
    // 0x807B51AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B51B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B51B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B51B8: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x807B51BC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x807B51C0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x807B51C4: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x807B51C8: or          $s0, $sp, $zero
    ctx->r16 = ctx->r29 | 0;
    // 0x807B51CC: addiu       $s0, $s0, 0xCF
    ctx->r16 = ADD32(ctx->r16, 0XCF);
    // 0x807B51D0: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x807B51D4: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
    // 0x807B51D8: lui         $t6, 0x361
    ctx->r14 = S32(0X361 << 16);
    // 0x807B51DC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x807B51E0: srl         $s0, $s0, 3
    ctx->r16 = S32(U32(ctx->r16) >> 3);
    // 0x807B51E4: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x807B51E8: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x807B51EC: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x807B51F0: addiu       $t5, $t4, 0x174
    ctx->r13 = ADD32(ctx->r12, 0X174);
    // 0x807B51F4: addiu       $t6, $t6, -0x2570
    ctx->r14 = ADD32(ctx->r14, -0X2570);
    // 0x807B51F8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x807B51FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B5200: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x807B5204: jal         0x800675D0
    // 0x807B5208: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_800675D0(rdram, ctx);
        goto after_0;
    // 0x807B5208: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x807B520C: or          $s1, $sp, $zero
    ctx->r17 = ctx->r29 | 0;
    // 0x807B5210: addiu       $s1, $s1, 0xA3
    ctx->r17 = ADD32(ctx->r17, 0XA3);
    // 0x807B5214: srl         $s1, $s1, 3
    ctx->r17 = S32(U32(ctx->r17) >> 3);
    // 0x807B5218: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x807B521C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x807B5220: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B5224: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x807B5228: jal         0x800675D0
    // 0x807B522C: lhu         $a2, 0x4($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X4);
    func_800675D0(rdram, ctx);
        goto after_1;
    // 0x807B522C: lhu         $a2, 0x4($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X4);
    after_1:
    // 0x807B5230: lw          $a0, 0xEC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XEC);
    // 0x807B5234: jal         0x807B4A10
    // 0x807B5238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_807B4A10(rdram, ctx);
        goto after_2;
    // 0x807B5238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x807B523C: lw          $a0, 0xEC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XEC);
    // 0x807B5240: jal         0x807B4A10
    // 0x807B5244: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_807B4A10(rdram, ctx);
        goto after_3;
    // 0x807B5244: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_3:
    // 0x807B5248: addiu       $t7, $zero, 0x3B
    ctx->r15 = ADD32(0, 0X3B);
    // 0x807B524C: sh          $t7, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r15;
    // 0x807B5250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807B5254: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B5258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x807B525C: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x807B5260: addiu       $t3, $zero, 0x39
    ctx->r11 = ADD32(0, 0X39);
    // 0x807B5264: addiu       $t2, $zero, 0x62
    ctx->r10 = ADD32(0, 0X62);
    // 0x807B5268: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x807B526C: addiu       $t0, $zero, 0x3B
    ctx->r8 = ADD32(0, 0X3B);
    // 0x807B5270: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x807B5274: addu        $t8, $s1, $a0
    ctx->r24 = ADD32(ctx->r17, ctx->r4);
L_807B5278:
    // 0x807B5278: lhu         $a1, 0x0($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X0);
    // 0x807B527C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x807B5280: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x807B5284: bne         $a3, $a1, L_807B52AC
    if (ctx->r7 != ctx->r5) {
        // 0x807B5288: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_807B52AC;
    }
    // 0x807B5288: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x807B528C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x807B5290: addu        $t4, $s0, $t9
    ctx->r12 = ADD32(ctx->r16, ctx->r25);
    // 0x807B5294: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x807B5298: sh          $t0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r8;
    // 0x807B529C: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x807B52A0: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
    // 0x807B52A4: b           L_807B52E4
    // 0x807B52A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_807B52E4;
    // 0x807B52A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_807B52AC:
    // 0x807B52AC: beq         $a2, $zero, L_807B52C4
    if (ctx->r6 == 0) {
        // 0x807B52B0: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_807B52C4;
    }
    // 0x807B52B0: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x807B52B4: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x807B52B8: sh          $a1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r5;
    // 0x807B52BC: b           L_807B52E4
    // 0x807B52C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_807B52E4;
    // 0x807B52C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_807B52C4:
    // 0x807B52C4: beq         $v1, $zero, L_807B52E4
    if (ctx->r3 == 0) {
        // 0x807B52C8: nop
    
            goto L_807B52E4;
    }
    // 0x807B52C8: nop

    // 0x807B52CC: beq         $t3, $v1, L_807B52E4
    if (ctx->r11 == ctx->r3) {
        // 0x807B52D0: sll         $t9, $v0, 1
        ctx->r25 = S32(ctx->r2 << 1);
            goto L_807B52E4;
    }
    // 0x807B52D0: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x807B52D4: addu        $t4, $s0, $t9
    ctx->r12 = ADD32(ctx->r16, ctx->r25);
    // 0x807B52D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807B52DC: sh          $a1, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r5;
    // 0x807B52E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_807B52E4:
    // 0x807B52E4: bnel        $a0, $t2, L_807B5278
    if (ctx->r4 != ctx->r10) {
        // 0x807B52E8: addu        $t8, $s1, $a0
        ctx->r24 = ADD32(ctx->r17, ctx->r4);
            goto L_807B5278;
    }
    goto skip_0;
    // 0x807B52E8: addu        $t8, $s1, $a0
    ctx->r24 = ADD32(ctx->r17, ctx->r4);
    skip_0:
    // 0x807B52EC: lw          $a0, 0xEC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XEC);
    // 0x807B52F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807B52F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807B52F8: jal         0x807B4900
    // 0x807B52FC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_807B4900(rdram, ctx);
        goto after_4;
    // 0x807B52FC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_4:
    // 0x807B5300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B5304: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B5308: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B530C: jr          $ra
    // 0x807B5310: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x807B5310: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_80581A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581A38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80581A3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581A40: jal         0x80580C70
    // 0x80581A44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80580C70(rdram, ctx);
        goto after_0;
    // 0x80581A44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80581A48: jal         0x80581734
    // 0x80581A4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80581734(rdram, ctx);
        goto after_1;
    // 0x80581A4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80581A50: jal         0x805819A0
    // 0x80581A54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805819A0(rdram, ctx);
        goto after_2;
    // 0x80581A54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80581A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80581A5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581A60: jr          $ra
    // 0x80581A64: nop

    return;
    // 0x80581A64: nop

;}
RECOMP_FUNC void func_8043E514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E514: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043E518: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8043E51C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8043E520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E524: addiu       $t6, $zero, 0x69
    ctx->r14 = ADD32(0, 0X69);
    // 0x8043E528: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8043E52C: lui         $t7, 0x8044
    ctx->r15 = S32(RELOC_HI16(92, 0X1B40) << 16);
    // 0x8043E530: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8043E534: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x8043E538: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8043E53C: lw          $t7, -0x1480($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(92, 0X1B40));
    // 0x8043E540: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8043E544: sw          $a2, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r6;
    // 0x8043E548: sw          $a2, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r6;
    // 0x8043E54C: sw          $a2, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r6;
    // 0x8043E550: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8043E554: sb          $a1, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r5;
    // 0x8043E558: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8043E55C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8043E560: jal         0x8043DDB4
    // 0x8043E564: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8043DDB4(rdram, ctx);
        goto after_0;
    // 0x8043E564: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8043E568: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x8043E56C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8043E570: lui         $t9, 0x8044
    ctx->r25 = S32(RELOC_HI16(92, 0X1B48) << 16);
    // 0x8043E574: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x8043E578: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8043E57C: lhu         $t9, -0x1478($t9)
    ctx->r25 = MEM_HU(ctx->r25, (int16_t)RELOC_LO16(92, 0X1B48));
    // 0x8043E580: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8043E584: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8043E588: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8043E58C: lui         $t1, 0x8044
    ctx->r9 = S32(RELOC_HI16(92, 0X1B4C) << 16);
    // 0x8043E590: sh          $t9, 0x4C($t0)
    MEM_H(0X4C, ctx->r8) = ctx->r25;
    // 0x8043E594: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x8043E598: lw          $t1, -0x1474($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(92, 0X1B4C));
    // 0x8043E59C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8043E5A0: sw          $t1, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->r9;
    // 0x8043E5A4: jal         0x8043D154
    // 0x8043E5A8: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    func_8043D154(rdram, ctx);
        goto after_1;
    // 0x8043E5A8: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    after_1:
    // 0x8043E5AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043E5B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043E5B4: jr          $ra
    // 0x8043E5B8: nop

    return;
    // 0x8043E5B8: nop

;}
RECOMP_FUNC void func_80465BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465BE4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80465BE8: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x80465BEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80465BF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80465BF4: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80465BF8: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x80465BFC: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80465C00: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80465C04: jal         0x80465AE8
    // 0x80465C08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80465AE8(rdram, ctx);
        goto after_0;
    // 0x80465C08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80465C0C: jal         0x804654F8
    // 0x80465C10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804654F8(rdram, ctx);
        goto after_1;
    // 0x80465C10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80465C14: jal         0x80465708
    // 0x80465C18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80465708(rdram, ctx);
        goto after_2;
    // 0x80465C18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80465C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80465C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80465C24: jr          $ra
    // 0x80465C28: nop

    return;
    // 0x80465C28: nop

;}
RECOMP_FUNC void func_805AB8A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB8A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AB8A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AB8A8: jal         0x805AB778
    // 0x805AB8AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805AB778(rdram, ctx);
        goto after_0;
    // 0x805AB8AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805AB8B0: beq         $v0, $zero, L_805AB904
    if (ctx->r2 == 0) {
        // 0x805AB8B4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805AB904;
    }
    // 0x805AB8B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AB8B8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x805AB8BC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x805AB8C0: lui         $t7, 0x805B
    ctx->r15 = S32(RELOC_HI16(435, 0XAB0) << 16);
    // 0x805AB8C4: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x805AB8C8: addiu       $t7, $t7, -0x4610
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(435, 0XAB0));
    // 0x805AB8CC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805AB8D0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805AB8D4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805AB8D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805AB8DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AB8E0: jal         0x805AB914
    // 0x805AB8E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_805AB914(rdram, ctx);
        goto after_1;
    // 0x805AB8E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x805AB8E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AB8EC: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805AB8F0: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x805AB8F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805AB8F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805AB8FC: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x805AB900: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
L_805AB904:
    // 0x805AB904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AB908: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AB90C: jr          $ra
    // 0x805AB910: nop

    return;
    // 0x805AB910: nop

;}
RECOMP_FUNC void func_80434718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043471C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80434720: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80434724: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80434728: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8043472C: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(71, 0X29C8) << 16);
    // 0x80434730: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80434734: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80434738: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8043473C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80434740: lw          $t8, 0x6478($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(71, 0X29C8));
    // 0x80434744: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80434748: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8043474C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80434750: jal         0x80048490
    // 0x80434754: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80434754: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80434758: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8043475C: jal         0x80048378
    // 0x80434760: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80434760: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80434764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80434768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043476C: jr          $ra
    // 0x80434770: nop

    return;
    // 0x80434770: nop

;}
RECOMP_FUNC void func_80674874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80674874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80674878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067487C: jal         0x80674804
    // 0x80674880: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80674804(rdram, ctx);
        goto after_0;
    // 0x80674880: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80674884: bne         $v0, $zero, L_8067489C
    if (ctx->r2 != 0) {
        // 0x80674888: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8067489C;
    }
    // 0x80674888: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8067488C: jal         0x800445A4
    // 0x80674890: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80674890: nop

    after_1:
    // 0x80674894: b           L_806748D8
    // 0x80674898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806748D8;
    // 0x80674898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8067489C:
    // 0x8067489C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806748A0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806748A4: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x806748A8: lui         $t7, 0x8067
    ctx->r15 = S32(RELOC_HI16(529, 0X1B60) << 16);
    // 0x806748AC: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x806748B0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806748B4: addiu       $t7, $t7, 0x4B40
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(529, 0X1B60));
    // 0x806748B8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806748BC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806748C0: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x806748C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806748C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806748CC: jal         0x806748E4
    // 0x806748D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806748E4(rdram, ctx);
        goto after_2;
    // 0x806748D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x806748D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806748D8:
    // 0x806748D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806748DC: jr          $ra
    // 0x806748E0: nop

    return;
    // 0x806748E0: nop

;}
RECOMP_FUNC void func_8043DFEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DFEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043DFF0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8043DFF4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8043DFF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043DFFC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8043E000: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8043E004: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8043E008: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_8043E00C:
    // 0x8043E00C: jal         0x8043E960
    // 0x8043E010: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8043E960(rdram, ctx);
        goto after_0;
    // 0x8043E010: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8043E014: beq         $v0, $zero, L_8043E028
    if (ctx->r2 == 0) {
        // 0x8043E018: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8043E028;
    }
    // 0x8043E018: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8043E01C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8043E020: bne         $s0, $s2, L_8043E00C
    if (ctx->r16 != ctx->r18) {
        // 0x8043E024: nop
    
            goto L_8043E00C;
    }
    // 0x8043E024: nop

L_8043E028:
    // 0x8043E028: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8043E02C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043E030: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8043E034: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8043E038: jr          $ra
    // 0x8043E03C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8043E03C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80048114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004811C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80048120: lw          $t6, 0x180($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X180);
    // 0x80048124: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80048128: beq         $t6, $zero, L_80048148
    if (ctx->r14 == 0) {
        // 0x8004812C: nop
    
            goto L_80048148;
    }
    // 0x8004812C: nop

    // 0x80048130: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80048134: addiu       $a0, $a0, 0x7E0
    ctx->r4 = ADD32(ctx->r4, 0X7E0);
    // 0x80048138: jal         0x80071380
    // 0x8004813C: addiu       $a1, $zero, 0x9C2
    ctx->r5 = ADD32(0, 0X9C2);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8004813C: addiu       $a1, $zero, 0x9C2
    ctx->r5 = ADD32(0, 0X9C2);
    after_0:
    // 0x80048140: b           L_80048160
    // 0x80048144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048160;
    // 0x80048144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048148:
    // 0x80048148: jal         0x800444D0
    // 0x8004814C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800444D0(rdram, ctx);
        goto after_1;
    // 0x8004814C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80048150: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80048154: jal         0x80047F9C
    // 0x80048158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80048158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8004815C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048160:
    // 0x80048160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048164: jr          $ra
    // 0x80048168: nop

    return;
    // 0x80048168: nop

;}
RECOMP_FUNC void func_80008C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008C3C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80008C40: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80008C44: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x80008C48: addiu       $s1, $s1, 0x4D10
    ctx->r17 = ADD32(ctx->r17, 0X4D10);
    // 0x80008C4C: lw          $t6, 0xD84($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XD84);
    // 0x80008C50: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x80008C54: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80008C58: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80008C5C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80008C60: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80008C64: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80008C68: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80008C6C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80008C70: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80008C74: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80008C78: beq         $t6, $zero, L_80008C88
    if (ctx->r14 == 0) {
        // 0x80008C7C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80008C88;
    }
    // 0x80008C7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80008C80: b           L_80008C90
    // 0x80008C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80008C90;
    // 0x80008C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80008C88:
    // 0x80008C88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80008C8C: sw          $zero, 0x4CD0($at)
    MEM_W(0X4CD0, ctx->r1) = 0;
L_80008C90:
    // 0x80008C90: sw          $zero, 0xD80($s1)
    MEM_W(0XD80, ctx->r17) = 0;
    // 0x80008C94: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80008C98: jal         0x80007490
    // 0x80008C9C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    func_80007490(rdram, ctx);
        goto after_0;
    // 0x80008C9C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80008CA0: lw          $a0, 0xD80($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XD80);
    // 0x80008CA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008CA8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80008CAC: blez        $a0, L_80008CF4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80008CB0: lui         $t7, 0x800B
        ctx->r15 = S32(0X800B << 16);
            goto L_80008CF4;
    }
    // 0x80008CB0: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80008CB4: addiu       $v0, $t7, 0x4D10
    ctx->r2 = ADD32(ctx->r15, 0X4D10);
    // 0x80008CB8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80008CBC: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
    // 0x80008CC0: addiu       $v1, $zero, -0x10
    ctx->r3 = ADD32(0, -0X10);
L_80008CC4:
    // 0x80008CC4: lw          $t9, 0x180($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X180);
    // 0x80008CC8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80008CCC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80008CD0: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80008CD4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80008CD8: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80008CDC: addiu       $t4, $t3, 0xF
    ctx->r12 = ADD32(ctx->r11, 0XF);
    // 0x80008CE0: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x80008CE4: and         $t5, $t4, $v1
    ctx->r13 = ctx->r12 & ctx->r3;
    // 0x80008CE8: bne         $at, $zero, L_80008CC4
    if (ctx->r1 != 0) {
        // 0x80008CEC: addu        $a1, $a1, $t5
        ctx->r5 = ADD32(ctx->r5, ctx->r13);
            goto L_80008CC4;
    }
    // 0x80008CEC: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x80008CF0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_80008CF4:
    // 0x80008CF4: blez        $a0, L_80008F5C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80008CF8: addiu       $s7, $zero, 0x1
        ctx->r23 = ADD32(0, 0X1);
            goto L_80008F5C;
    }
    // 0x80008CF8: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80008CFC: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
    // 0x80008D00: lw          $s2, 0x5C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X5C);
    // 0x80008D04: lw          $t6, 0xD84($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XD84);
L_80008D08:
    // 0x80008D08: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80008D0C: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x80008D10: beq         $t6, $at, L_80008F5C
    if (ctx->r14 == ctx->r1) {
        // 0x80008D14: addu        $t7, $s1, $t8
        ctx->r15 = ADD32(ctx->r17, ctx->r24);
            goto L_80008F5C;
    }
    // 0x80008D14: addu        $t7, $s1, $t8
    ctx->r15 = ADD32(ctx->r17, ctx->r24);
    // 0x80008D18: beq         $s6, $zero, L_80008D30
    if (ctx->r22 == 0) {
        // 0x80008D1C: lw          $s0, 0x180($t7)
        ctx->r16 = MEM_W(ctx->r15, 0X180);
            goto L_80008D30;
    }
    // 0x80008D1C: lw          $s0, 0x180($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X180);
    // 0x80008D20: beql        $s6, $s7, L_80008DA0
    if (ctx->r22 == ctx->r23) {
        // 0x80008D24: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80008DA0;
    }
    goto skip_0;
    // 0x80008D24: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80008D28: b           L_80008E04
    // 0x80008D2C: nop

        goto L_80008E04;
    // 0x80008D2C: nop

L_80008D30:
    // 0x80008D30: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80008D34: lw          $t9, 0x10($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X10);
    // 0x80008D38: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80008D3C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80008D40: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x80008D44: bne         $t9, $v1, L_80008D6C
    if (ctx->r25 != ctx->r3) {
        // 0x80008D48: ori         $at, $at, 0xFFFF
        ctx->r1 = ctx->r1 | 0XFFFF;
            goto L_80008D6C;
    }
    // 0x80008D48: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80008D4C: sll         $a3, $v1, 24
    ctx->r7 = S32(ctx->r3 << 24);
    // 0x80008D50: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80008D54: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    // 0x80008D58: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x80008D5C: jal         0x8000576C
    // 0x80008D60: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_8000576C(rdram, ctx);
        goto after_1;
    // 0x80008D60: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x80008D64: b           L_80008E04
    // 0x80008D68: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_80008E04;
    // 0x80008D68: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80008D6C:
    // 0x80008D6C: lw          $t2, 0x14($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X14);
    // 0x80008D70: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80008D74: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80008D78: bne         $t2, $v1, L_80008E04
    if (ctx->r10 != ctx->r3) {
        // 0x80008D7C: and         $a0, $v0, $at
        ctx->r4 = ctx->r2 & ctx->r1;
            goto L_80008E04;
    }
    // 0x80008D7C: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    // 0x80008D80: sll         $a3, $v1, 24
    ctx->r7 = S32(ctx->r3 << 24);
    // 0x80008D84: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80008D88: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x80008D8C: jal         0x8000576C
    // 0x80008D90: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_8000576C(rdram, ctx);
        goto after_2;
    // 0x80008D90: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x80008D94: b           L_80008E04
    // 0x80008D98: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_80008E04;
    // 0x80008D98: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80008D9C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80008DA0:
    // 0x80008DA0: lw          $t3, 0x10($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X10);
    // 0x80008DA4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80008DA8: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80008DAC: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x80008DB0: bne         $t3, $v1, L_80008DD8
    if (ctx->r11 != ctx->r3) {
        // 0x80008DB4: ori         $at, $at, 0xFFFF
        ctx->r1 = ctx->r1 | 0XFFFF;
            goto L_80008DD8;
    }
    // 0x80008DB4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80008DB8: sll         $a3, $v1, 24
    ctx->r7 = S32(ctx->r3 << 24);
    // 0x80008DBC: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80008DC0: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    // 0x80008DC4: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x80008DC8: jal         0x8000571C
    // 0x80008DCC: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_8000571C(rdram, ctx);
        goto after_3;
    // 0x80008DCC: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_3:
    // 0x80008DD0: b           L_80008E04
    // 0x80008DD4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_80008E04;
    // 0x80008DD4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80008DD8:
    // 0x80008DD8: lw          $t4, 0x14($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X14);
    // 0x80008DDC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80008DE0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80008DE4: bne         $t4, $v1, L_80008E04
    if (ctx->r12 != ctx->r3) {
        // 0x80008DE8: and         $a0, $v0, $at
        ctx->r4 = ctx->r2 & ctx->r1;
            goto L_80008E04;
    }
    // 0x80008DE8: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    // 0x80008DEC: sll         $a3, $v1, 24
    ctx->r7 = S32(ctx->r3 << 24);
    // 0x80008DF0: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80008DF4: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x80008DF8: jal         0x8000571C
    // 0x80008DFC: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_8000571C(rdram, ctx);
        goto after_4;
    // 0x80008DFC: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_4:
    // 0x80008E00: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80008E04:
    // 0x80008E04: bne         $s2, $zero, L_80008E14
    if (ctx->r18 != 0) {
        // 0x80008E08: nop
    
            goto L_80008E14;
    }
    // 0x80008E08: nop

    // 0x80008E0C: b           L_80008F48
    // 0x80008E10: lw          $a0, 0xD80($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XD80);
        goto L_80008F48;
    // 0x80008E10: lw          $a0, 0xD80($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XD80);
L_80008E14:
    // 0x80008E14: beql        $s6, $zero, L_80008E30
    if (ctx->r22 == 0) {
        // 0x80008E18: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80008E30;
    }
    goto skip_1;
    // 0x80008E18: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80008E1C: beql        $s6, $s7, L_80008EAC
    if (ctx->r22 == ctx->r23) {
        // 0x80008E20: lw          $t2, 0xD84($s1)
        ctx->r10 = MEM_W(ctx->r17, 0XD84);
            goto L_80008EAC;
    }
    goto skip_2;
    // 0x80008E20: lw          $t2, 0xD84($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XD84);
    skip_2:
    // 0x80008E24: b           L_80008F48
    // 0x80008E28: lw          $a0, 0xD80($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XD80);
        goto L_80008F48;
    // 0x80008E28: lw          $a0, 0xD80($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XD80);
    // 0x80008E2C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80008E30:
    // 0x80008E30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008E34: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80008E38: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80008E3C: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x80008E40: bne         $v1, $at, L_80008E7C
    if (ctx->r3 != ctx->r1) {
        // 0x80008E44: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80008E7C;
    }
    // 0x80008E44: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80008E48: lw          $t5, 0x1D6C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X1D6C);
    // 0x80008E4C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80008E50: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80008E54: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    // 0x80008E58: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80008E5C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80008E60: jal         0x80007798
    // 0x80008E64: lh          $a3, 0x2($t5)
    ctx->r7 = MEM_H(ctx->r13, 0X2);
    func_80007798(rdram, ctx);
        goto after_5;
    // 0x80008E64: lh          $a3, 0x2($t5)
    ctx->r7 = MEM_H(ctx->r13, 0X2);
    after_5:
    // 0x80008E68: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80008E6C: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80008E70: andi        $t8, $t6, 0xFFF3
    ctx->r24 = ctx->r14 & 0XFFF3;
    // 0x80008E74: b           L_80008EA0
    // 0x80008E78: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
        goto L_80008EA0;
    // 0x80008E78: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
L_80008E7C:
    // 0x80008E7C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80008E80: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80008E84: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    // 0x80008E88: jal         0x80007674
    // 0x80008E8C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_80007674(rdram, ctx);
        goto after_6;
    // 0x80008E8C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_6:
    // 0x80008E90: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80008E94: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80008E98: andi        $t9, $t7, 0xFFF3
    ctx->r25 = ctx->r15 & 0XFFF3;
    // 0x80008E9C: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
L_80008EA0:
    // 0x80008EA0: b           L_80008F48
    // 0x80008EA4: lw          $a0, 0xD80($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XD80);
        goto L_80008F48;
    // 0x80008EA4: lw          $a0, 0xD80($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XD80);
    // 0x80008EA8: lw          $t2, 0xD84($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XD84);
L_80008EAC:
    // 0x80008EAC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80008EB0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80008EB4: multu       $t2, $s4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80008EB8: mflo        $t3
    ctx->r11 = lo;
    // 0x80008EBC: addu        $t4, $s1, $t3
    ctx->r12 = ADD32(ctx->r17, ctx->r11);
    // 0x80008EC0: sw          $s0, 0x384($t4)
    MEM_W(0X384, ctx->r12) = ctx->r16;
    // 0x80008EC4: lw          $t5, 0xD84($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XD84);
    // 0x80008EC8: multu       $t5, $s4
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80008ECC: mflo        $t6
    ctx->r14 = lo;
    // 0x80008ED0: addu        $t8, $s1, $t6
    ctx->r24 = ADD32(ctx->r17, ctx->r14);
    // 0x80008ED4: sw          $s2, 0x388($t8)
    MEM_W(0X388, ctx->r24) = ctx->r18;
    // 0x80008ED8: lw          $v1, 0xD84($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XD84);
    // 0x80008EDC: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80008EE0: sll         $t7, $v1, 24
    ctx->r15 = S32(ctx->r3 << 24);
    // 0x80008EE4: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80008EE8: mflo        $t2
    ctx->r10 = lo;
    // 0x80008EEC: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x80008EF0: sw          $t9, 0x38C($t3)
    MEM_W(0X38C, ctx->r11) = ctx->r25;
    // 0x80008EF4: lw          $t4, 0xD84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XD84);
    // 0x80008EF8: multu       $t4, $s4
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80008EFC: mflo        $t5
    ctx->r13 = lo;
    // 0x80008F00: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x80008F04: sw          $zero, 0x390($t6)
    MEM_W(0X390, ctx->r14) = 0;
    // 0x80008F08: lw          $t5, 0xD84($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XD84);
    // 0x80008F0C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80008F10: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80008F14: multu       $t5, $s4
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80008F18: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x80008F1C: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80008F20: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x80008F24: srl         $t3, $t9, 30
    ctx->r11 = S32(U32(ctx->r25) >> 30);
    // 0x80008F28: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80008F2C: mflo        $t6
    ctx->r14 = lo;
    // 0x80008F30: addu        $t8, $s1, $t6
    ctx->r24 = ADD32(ctx->r17, ctx->r14);
    // 0x80008F34: sw          $t4, 0x380($t8)
    MEM_W(0X380, ctx->r24) = ctx->r12;
    // 0x80008F38: lw          $t7, 0xD84($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XD84);
    // 0x80008F3C: lw          $a0, 0xD80($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XD80);
    // 0x80008F40: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80008F44: sw          $t9, 0xD84($s1)
    MEM_W(0XD84, ctx->r17) = ctx->r25;
L_80008F48:
    // 0x80008F48: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80008F4C: slt         $at, $s5, $a0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80008F50: bnel        $at, $zero, L_80008D08
    if (ctx->r1 != 0) {
        // 0x80008F54: lw          $t6, 0xD84($s1)
        ctx->r14 = MEM_W(ctx->r17, 0XD84);
            goto L_80008D08;
    }
    goto skip_3;
    // 0x80008F54: lw          $t6, 0xD84($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XD84);
    skip_3:
    // 0x80008F58: sw          $s2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r18;
L_80008F5C:
    // 0x80008F5C: lw          $v1, 0xD84($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XD84);
    // 0x80008F60: sw          $zero, 0xD80($s1)
    MEM_W(0XD80, ctx->r17) = 0;
    // 0x80008F64: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
    // 0x80008F68: beq         $v1, $zero, L_80008FCC
    if (ctx->r3 == 0) {
        // 0x80008F6C: lw          $t2, 0x4C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X4C);
            goto L_80008FCC;
    }
    // 0x80008F6C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80008F70: bnel        $t2, $zero, L_80008FD0
    if (ctx->r10 != 0) {
        // 0x80008F74: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80008FD0;
    }
    goto skip_4;
    // 0x80008F74: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_4:
    // 0x80008F78: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80008F7C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80008F80: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80008F84: lui         $t5, 0x800B
    ctx->r13 = S32(0X800B << 16);
    // 0x80008F88: addiu       $t5, $t5, 0x60DC
    ctx->r13 = ADD32(ctx->r13, 0X60DC);
    // 0x80008F8C: mflo        $t3
    ctx->r11 = lo;
    // 0x80008F90: addu        $t0, $s1, $t3
    ctx->r8 = ADD32(ctx->r17, ctx->r11);
    // 0x80008F94: lw          $s0, 0x370($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X370);
    // 0x80008F98: lw          $t6, 0x378($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X378);
    // 0x80008F9C: lw          $a1, 0x374($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X374);
    // 0x80008FA0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80008FA4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80008FA8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80008FAC: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    // 0x80008FB0: srl         $t1, $a2, 12
    ctx->r9 = S32(U32(ctx->r6) >> 12);
    // 0x80008FB4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80008FB8: sll         $a3, $v0, 4
    ctx->r7 = S32(ctx->r2 << 4);
    // 0x80008FBC: srl         $a3, $a3, 30
    ctx->r7 = S32(U32(ctx->r7) >> 30);
    // 0x80008FC0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80008FC4: jal         0x80008668
    // 0x80008FC8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_80008668(rdram, ctx);
        goto after_7;
    // 0x80008FC8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_7:
L_80008FCC:
    // 0x80008FCC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80008FD0:
    // 0x80008FD0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80008FD4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80008FD8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80008FDC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80008FE0: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80008FE4: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80008FE8: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80008FEC: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80008FF0: jr          $ra
    // 0x80008FF4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80008FF4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800431D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800431D8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800431DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800431E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800431E4: lw          $v0, 0x1300($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1300);
    // 0x800431E8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800431EC: bne         $v0, $zero, L_800431F8
    if (ctx->r2 != 0) {
        // 0x800431F0: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_800431F8;
    }
    // 0x800431F0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800431F4: sw          $zero, 0x12FC($a1)
    MEM_W(0X12FC, ctx->r5) = 0;
L_800431F8:
    // 0x800431F8: beql        $at, $zero, L_80043394
    if (ctx->r1 == 0) {
        // 0x800431FC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80043394;
    }
    goto skip_0;
    // 0x800431FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80043200: lw          $t6, 0x130C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X130C);
    // 0x80043204: beql        $t6, $zero, L_80043394
    if (ctx->r14 == 0) {
        // 0x80043208: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80043394;
    }
    goto skip_1;
    // 0x80043208: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8004320C: lw          $t1, 0x1308($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1308);
    // 0x80043210: lw          $t0, 0x12FC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X12FC);
    // 0x80043214: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80043218: sll         $t7, $t1, 3
    ctx->r15 = S32(ctx->r9 << 3);
    // 0x8004321C: addu        $t2, $s0, $t7
    ctx->r10 = ADD32(ctx->r16, ctx->r15);
    // 0x80043220: lbu         $v0, 0x1310($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X1310);
    // 0x80043224: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x80043228: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8004322C: lwc1        $f12, 0x518($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X518);
    // 0x80043230: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x80043234: beq         $at, $zero, L_800432D0
    if (ctx->r1 == 0) {
        // 0x80043238: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_800432D0;
    }
    // 0x80043238: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8004323C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80043240: addu        $at, $at, $t8
    gpr jr_addend_80043248 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80043244: lw          $t8, 0x31C($at)
    ctx->r24 = ADD32(ctx->r1, 0X31C);
    // 0x80043248: jr          $t8
    // 0x8004324C: nop

    switch (jr_addend_80043248 >> 2) {
        case 0: goto L_80043250; break;
        case 1: goto L_800432D0; break;
        case 2: goto L_80043260; break;
        case 3: goto L_80043274; break;
        case 4: goto L_80043288; break;
        case 5: goto L_8004329C; break;
        case 6: goto L_800432AC; break;
        case 7: goto L_800432C0; break;
        default: switch_error(__func__, 0x80043248, 0x800B031C);
    }
    // 0x8004324C: nop

L_80043250:
    // 0x80043250: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80043254: sb          $zero, 0x42($sp)
    MEM_B(0X42, ctx->r29) = 0;
    // 0x80043258: b           L_800432D0
    // 0x8004325C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
        goto L_800432D0;
    // 0x8004325C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_80043260:
    // 0x80043260: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80043264: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80043268: sb          $t3, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r11;
    // 0x8004326C: b           L_800432D0
    // 0x80043270: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
        goto L_800432D0;
    // 0x80043270: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
L_80043274:
    // 0x80043274: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80043278: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8004327C: sb          $t5, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r13;
    // 0x80043280: b           L_800432D0
    // 0x80043284: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
        goto L_800432D0;
    // 0x80043284: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_80043288:
    // 0x80043288: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8004328C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80043290: sb          $t7, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r15;
    // 0x80043294: b           L_800432D0
    // 0x80043298: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
        goto L_800432D0;
    // 0x80043298: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
L_8004329C:
    // 0x8004329C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x800432A0: sb          $t9, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r25;
    // 0x800432A4: b           L_800432D0
    // 0x800432A8: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
        goto L_800432D0;
    // 0x800432A8: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_800432AC:
    // 0x800432AC: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x800432B0: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800432B4: sb          $t3, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r11;
    // 0x800432B8: b           L_800432D0
    // 0x800432BC: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
        goto L_800432D0;
    // 0x800432BC: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
L_800432C0:
    // 0x800432C0: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x800432C4: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x800432C8: sb          $t5, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r13;
    // 0x800432CC: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_800432D0:
    // 0x800432D0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800432D4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800432D8: lwc1        $f6, 0x524($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X524);
    // 0x800432DC: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800432E0: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800432E4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800432E8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800432EC: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800432F0: lwc1        $f10, 0x530($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X530);
    // 0x800432F4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800432F8: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x800432FC: neg.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = -ctx->f12.fl;
    // 0x80043300: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80043304: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80043308: addiu       $t7, $t7, 0x30AC
    ctx->r15 = ADD32(ctx->r15, 0X30AC);
    // 0x8004330C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80043310: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80043314: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80043318: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8004331C: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x80043320: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80043324: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80043328: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8004332C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80043330: lw          $t9, 0x40($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X40);
    // 0x80043334: lbu         $a1, 0x42($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X42);
    // 0x80043338: jalr        $t9
    // 0x8004333C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8004333C: nop

    after_0:
    // 0x80043340: beq         $v0, $zero, L_80043390
    if (ctx->r2 == 0) {
        // 0x80043344: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80043390;
    }
    // 0x80043344: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80043348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004334C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80043350: jal         0x8004312C
    // 0x80043354: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    func_8004312C(rdram, ctx);
        goto after_1;
    // 0x80043354: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x80043358: jal         0x8001D770
    // 0x8004335C: nop

    func_8001D770(rdram, ctx);
        goto after_2;
    // 0x8004335C: nop

    after_2:
    // 0x80043360: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x80043364: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80043368: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004336C: lw          $t4, 0x38($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X38);
    // 0x80043370: lw          $a3, 0x34($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X34);
    // 0x80043374: lw          $a2, 0x1314($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X1314);
    // 0x80043378: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8004337C: jal         0x80067DD8
    // 0x80043380: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_80067DD8(rdram, ctx);
        goto after_3;
    // 0x80043380: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x80043384: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    // 0x80043388: jal         0x80067818
    // 0x8004338C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8004338C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
L_80043390:
    // 0x80043390: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80043394:
    // 0x80043394: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80043398: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8004339C: jr          $ra
    // 0x800433A0: nop

    return;
    // 0x800433A0: nop

;}
RECOMP_FUNC void func_806D8944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D8944: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D8948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D894C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806D8950: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x806D8954: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806D8958: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x806D895C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806D8960: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x806D8964: jal         0x8004D150
    // 0x806D8968: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8004D150(rdram, ctx);
        goto after_0;
    // 0x806D8968: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x806D896C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x806D8970: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x806D8974: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806D8978: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x806D897C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x806D8980: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x806D8984: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x806D8988: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x806D898C: lbu         $t3, 0x14($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X14);
    // 0x806D8990: beql        $t3, $zero, L_806D89AC
    if (ctx->r11 == 0) {
        // 0x806D8994: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D89AC;
    }
    goto skip_0;
    // 0x806D8994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806D8998: jal         0x806D88D0
    // 0x806D899C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_806D88D0(rdram, ctx);
        goto after_1;
    // 0x806D899C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x806D89A0: jal         0x80044658
    // 0x806D89A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80044658(rdram, ctx);
        goto after_2;
    // 0x806D89A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x806D89A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D89AC:
    // 0x806D89AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D89B0: jr          $ra
    // 0x806D89B4: nop

    return;
    // 0x806D89B4: nop

;}
RECOMP_FUNC void func_800298B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800298B4: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800298B8: lw          $t7, -0x7CE8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CE8);
    // 0x800298BC: lw          $t1, 0xD0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XD0);
    // 0x800298C0: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x800298C4: lw          $t8, 0xFC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XFC);
    // 0x800298C8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800298CC: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x800298D0: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x800298D4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800298D8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800298DC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800298E0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800298E4: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800298E8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800298EC: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x800298F0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800298F4: lw          $t4, -0x218C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X218C);
    // 0x800298F8: lw          $t6, 0x38($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X38);
    // 0x800298FC: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x80029900: lw          $t5, -0x21EC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X21EC);
    // 0x80029904: subu        $v0, $t6, $t4
    ctx->r2 = SUB32(ctx->r14, ctx->r12);
    // 0x80029908: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8002990C: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80029910: bne         $at, $zero, L_80029950
    if (ctx->r1 != 0) {
        // 0x80029914: addu        $t7, $t7, $v1
        ctx->r15 = ADD32(ctx->r15, ctx->r3);
            goto L_80029950;
    }
    // 0x80029914: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80029918: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002991C: lwc1        $f4, -0x1C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C4);
    // 0x80029920: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80029924: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80029928: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x8002992C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80029930: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x80029934: lwc1        $f8, 0xC4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80029938: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8002993C: nop

    // 0x80029940: bc1f        L_800299D8
    if (!c1cs) {
        // 0x80029944: nop
    
            goto L_800299D8;
    }
    // 0x80029944: nop

    // 0x80029948: jr          $ra
    // 0x8002994C: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8002994C: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
L_80029950:
    // 0x80029950: lw          $t7, -0x21BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X21BC);
    // 0x80029954: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80029958: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x8002995C: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80029960: bnel        $at, $zero, L_800299C8
    if (ctx->r1 != 0) {
        // 0x80029964: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800299C8;
    }
    goto skip_0;
    // 0x80029964: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80029968: lw          $t8, -0x21A4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X21A4);
    // 0x8002996C: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80029970: beq         $at, $zero, L_800299AC
    if (ctx->r1 == 0) {
        // 0x80029974: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_800299AC;
    }
    // 0x80029974: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80029978: lwc1        $f10, -0x1C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1C0);
    // 0x8002997C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80029980: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80029984: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x80029988: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002998C: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x80029990: lwc1        $f18, 0xC4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80029994: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80029998: nop

    // 0x8002999C: bc1f        L_800299D8
    if (!c1cs) {
        // 0x800299A0: nop
    
            goto L_800299D8;
    }
    // 0x800299A0: nop

    // 0x800299A4: jr          $ra
    // 0x800299A8: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800299A8: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
L_800299AC:
    // 0x800299AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800299B0: nop

    // 0x800299B4: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x800299B8: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800299BC: jr          $ra
    // 0x800299C0: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800299C0: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x800299C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800299C8:
    // 0x800299C8: nop

    // 0x800299CC: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x800299D0: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800299D4: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
L_800299D8:
    // 0x800299D8: jr          $ra
    // 0x800299DC: nop

    return;
    // 0x800299DC: nop

;}
RECOMP_FUNC void func_80067F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067F40: jal         0x80067D5C
    // 0x80067F44: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x80067F44: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_0:
    // 0x80067F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067F4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067F50: jr          $ra
    // 0x80067F54: nop

    return;
    // 0x80067F54: nop

;}
RECOMP_FUNC void func_8043DBBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DBBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043DBC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043DBC4: lbu         $t6, 0xF5($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XF5);
    // 0x8043DBC8: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // 0x8043DBCC: beql        $t6, $zero, L_8043DBF0
    if (ctx->r14 == 0) {
        // 0x8043DBD0: sh          $zero, 0x144($a0)
        MEM_H(0X144, ctx->r4) = 0;
            goto L_8043DBF0;
    }
    goto skip_0;
    // 0x8043DBD0: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    skip_0:
    // 0x8043DBD4: jal         0x8043DA34
    // 0x8043DBD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8043DA34(rdram, ctx);
        goto after_0;
    // 0x8043DBD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043DBDC: jal         0x8043D618
    // 0x8043DBE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8043D618(rdram, ctx);
        goto after_1;
    // 0x8043DBE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8043DBE4: b           L_8043DBF4
    // 0x8043DBE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8043DBF4;
    // 0x8043DBE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043DBEC: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
L_8043DBF0:
    // 0x8043DBF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043DBF4:
    // 0x8043DBF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043DBF8: jr          $ra
    // 0x8043DBFC: nop

    return;
    // 0x8043DBFC: nop

;}
RECOMP_FUNC void func_806E3DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E3DB8: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806E3DBC: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(649, 0X578) << 16);
    // 0x806E3DC0: addiu       $t6, $t6, 0x3D78
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(649, 0X578));
    // 0x806E3DC4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806E3DC8: jr          $ra
    // 0x806E3DCC: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x806E3DCC: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8043045C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043045C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80430460: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80430464: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80430468: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8043046C: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0X3150) << 16);
    // 0x80430470: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80430474: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80430478: addiu       $t6, $t6, 0x1230
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0X3150));
    // 0x8043047C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80430480: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80430484: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80430488: jal         0x80045A34
    // 0x8043048C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8043048C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_0:
    // 0x80430490: jal         0x8004700C
    // 0x80430494: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x80430494: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    after_1:
    // 0x80430498: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8043049C: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x804304A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804304A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804304A8: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x804304AC: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x804304B0: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804304B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804304B8: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x804304BC: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x804304C0: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x804304C4: bne         $v0, $zero, L_80430570
    if (ctx->r2 != 0) {
        // 0x804304C8: swc1        $f8, 0xC($t0)
        MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
            goto L_80430570;
    }
    // 0x804304C8: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x804304CC: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804304D0: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804304D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x804304D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804304DC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x804304E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804304E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804304E8: bc1f        L_80430534
    if (!c1cs) {
        // 0x804304EC: nop
    
            goto L_80430534;
    }
    // 0x804304EC: nop

    // 0x804304F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804304F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804304F8: jal         0x804303F0
    // 0x804304FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_804303F0(rdram, ctx);
        goto after_2;
    // 0x804304FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80430500: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80430504: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80430508: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8043050C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80430510: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80430514: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80430518: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8043051C: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80430520: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80430524: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x80430528: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    // 0x8043052C: b           L_804305A8
    // 0x80430530: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
        goto L_804305A8;
    // 0x80430530: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
L_80430534:
    // 0x80430534: jal         0x804303F0
    // 0x80430538: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804303F0(rdram, ctx);
        goto after_3;
    // 0x80430538: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8043053C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80430540: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80430544: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80430548: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8043054C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80430550: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80430554: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80430558: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8043055C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80430560: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x80430564: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x80430568: b           L_804305A8
    // 0x8043056C: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
        goto L_804305A8;
    // 0x8043056C: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
L_80430570:
    // 0x80430570: jal         0x804303F0
    // 0x80430574: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804303F0(rdram, ctx);
        goto after_4;
    // 0x80430574: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80430578: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8043057C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80430580: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80430584: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80430588: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8043058C: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80430590: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80430594: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80430598: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8043059C: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x804305A0: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x804305A4: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
L_804305A8:
    // 0x804305A8: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804305AC: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x804305B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804305B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x804305B8: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
    // 0x804305BC: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x804305C0: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804305C4: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    // 0x804305C8: swc1        $f10, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->f10.u32l;
    // 0x804305CC: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x804305D0: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x804305D4: jal         0x8042F824
    // 0x804305D8: swc1        $f16, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f16.u32l;
    func_8042F824(rdram, ctx);
        goto after_5;
    // 0x804305D8: swc1        $f16, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f16.u32l;
    after_5:
    // 0x804305DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804305E0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x804305E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804305E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804305EC: sb          $t4, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r12;
    // 0x804305F0: jr          $ra
    // 0x804305F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x804305F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_807BB638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BB638: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807BB63C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807BB640: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807BB644: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807BB648: jal         0x807BB590
    // 0x807BB64C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_807BB590(rdram, ctx);
        goto after_0;
    // 0x807BB64C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x807BB650: lw          $s0, 0x1F4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X1F4);
    // 0x807BB654: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x807BB658: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x807BB65C: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x807BB660: jal         0x800653D8
    // 0x807BB664: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x807BB664: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x807BB668: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x807BB66C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x807BB670: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1254) << 16);
    // 0x807BB674: lwc1        $f16, -0x459C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1254));
    // 0x807BB678: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807BB67C: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1258) << 16);
    // 0x807BB680: lwc1        $f4, -0x4598($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1258));
    // 0x807BB684: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807BB688: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x807BB68C: jal         0x800653D8
    // 0x807BB690: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x807BB690: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x807BB694: andi        $t7, $v0, 0xF
    ctx->r15 = ctx->r2 & 0XF;
    // 0x807BB698: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x807BB69C: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X125C) << 16);
    // 0x807BB6A0: lwc1        $f16, -0x4594($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X125C));
    // 0x807BB6A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807BB6A8: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1260) << 16);
    // 0x807BB6AC: lwc1        $f4, -0x4590($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1260));
    // 0x807BB6B0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807BB6B4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x807BB6B8: jal         0x800653D8
    // 0x807BB6BC: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x807BB6BC: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x807BB6C0: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x807BB6C4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x807BB6C8: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1264) << 16);
    // 0x807BB6CC: lwc1        $f16, -0x458C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1264));
    // 0x807BB6D0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807BB6D4: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1268) << 16);
    // 0x807BB6D8: lwc1        $f4, -0x4588($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1268));
    // 0x807BB6DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807BB6E0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807BB6E4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x807BB6E8: jal         0x807BB4A8
    // 0x807BB6EC: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    func_807BB4A8(rdram, ctx);
        goto after_4;
    // 0x807BB6EC: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x807BB6F0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x807BB6F4: lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XC);
    // 0x807BB6F8: addiu       $at, $zero, 0x403E
    ctx->r1 = ADD32(0, 0X403E);
    // 0x807BB6FC: beq         $v0, $at, L_807BB714
    if (ctx->r2 == ctx->r1) {
        // 0x807BB700: addiu       $at, $zero, 0x4057
        ctx->r1 = ADD32(0, 0X4057);
            goto L_807BB714;
    }
    // 0x807BB700: addiu       $at, $zero, 0x4057
    ctx->r1 = ADD32(0, 0X4057);
    // 0x807BB704: beq         $v0, $at, L_807BB754
    if (ctx->r2 == ctx->r1) {
        // 0x807BB708: nop
    
            goto L_807BB754;
    }
    // 0x807BB708: nop

    // 0x807BB70C: b           L_807BB794
    // 0x807BB710: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807BB794;
    // 0x807BB710: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807BB714:
    // 0x807BB714: jal         0x807BB4E0
    // 0x807BB718: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_807BB4E0(rdram, ctx);
        goto after_5;
    // 0x807BB718: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x807BB71C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x807BB720: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807BB724: lui         $at, 0xC280
    ctx->r1 = S32(0XC280 << 16);
    // 0x807BB728: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807BB72C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x807BB730: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x807BB734: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807BB738: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x807BB73C: sh          $t9, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r25;
    // 0x807BB740: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x807BB744: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x807BB748: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x807BB74C: b           L_807BB790
    // 0x807BB750: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
        goto L_807BB790;
    // 0x807BB750: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_807BB754:
    // 0x807BB754: jal         0x807BB4E0
    // 0x807BB758: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_807BB4E0(rdram, ctx);
        goto after_6;
    // 0x807BB758: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x807BB75C: lui         $at, 0x4400
    ctx->r1 = S32(0X4400 << 16);
    // 0x807BB760: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807BB764: lui         $at, 0xC300
    ctx->r1 = S32(0XC300 << 16);
    // 0x807BB768: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807BB76C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x807BB770: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807BB774: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807BB778: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x807BB77C: sh          $t0, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r8;
    // 0x807BB780: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x807BB784: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x807BB788: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x807BB78C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_807BB790:
    // 0x807BB790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807BB794:
    // 0x807BB794: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807BB798: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807BB79C: jr          $ra
    // 0x807BB7A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x807BB7A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80574A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80574A64: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80574A68: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80574A6C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80574A70: lui         $t8, 0x8057
    ctx->r24 = S32(RELOC_HI16(381, 0XE5C) << 16);
    // 0x80574A74: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80574A78: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80574A7C: lw          $t8, 0x4CEC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(381, 0XE5C));
    // 0x80574A80: jr          $ra
    // 0x80574A84: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x80574A84: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_805D2E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2E5C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805D2E60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D2E64: jal         0x8004700C
    // 0x805D2E68: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805D2E68: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D2E6C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x805D2E70: jal         0x80062D14
    // 0x805D2E74: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80062D14(rdram, ctx);
        goto after_1;
    // 0x805D2E74: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x805D2E78: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x805D2E7C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x805D2E80: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x805D2E84: lw          $t6, 0x1E0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1E0);
    // 0x805D2E88: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x805D2E8C: bne         $t7, $at, L_805D2F78
    if (ctx->r15 != ctx->r1) {
        // 0x805D2E90: sw          $t7, 0x1E0($a1)
        MEM_W(0X1E0, ctx->r5) = ctx->r15;
            goto L_805D2F78;
    }
    // 0x805D2E90: sw          $t7, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r15;
    // 0x805D2E94: beq         $v1, $zero, L_805D2EBC
    if (ctx->r3 == 0) {
        // 0x805D2E98: sw          $zero, 0x1E0($a1)
        MEM_W(0X1E0, ctx->r5) = 0;
            goto L_805D2EBC;
    }
    // 0x805D2E98: sw          $zero, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = 0;
    // 0x805D2E9C: lw          $t9, 0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X34);
    // 0x805D2EA0: slti        $at, $t9, 0xA0
    ctx->r1 = SIGNED(ctx->r25) < 0XA0 ? 1 : 0;
    // 0x805D2EA4: beq         $at, $zero, L_805D2EB4
    if (ctx->r1 == 0) {
        // 0x805D2EA8: nop
    
            goto L_805D2EB4;
    }
    // 0x805D2EA8: nop

    // 0x805D2EAC: b           L_805D2ECC
    // 0x805D2EB0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D2ECC;
    // 0x805D2EB0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D2EB4:
    // 0x805D2EB4: b           L_805D2ECC
    // 0x805D2EB8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_805D2ECC;
    // 0x805D2EB8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_805D2EBC:
    // 0x805D2EBC: jal         0x800653D8
    // 0x805D2EC0: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x805D2EC0: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_2:
    // 0x805D2EC4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x805D2EC8: andi        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 & 0X1;
L_805D2ECC:
    // 0x805D2ECC: addiu       $a0, $a1, 0x84
    ctx->r4 = ADD32(ctx->r5, 0X84);
    // 0x805D2ED0: jal         0x805D2004
    // 0x805D2ED4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_805D2004(rdram, ctx);
        goto after_3;
    // 0x805D2ED4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_3:
    // 0x805D2ED8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805D2EDC: beq         $v0, $zero, L_805D2F78
    if (ctx->r2 == 0) {
        // 0x805D2EE0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805D2F78;
    }
    // 0x805D2EE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805D2EE4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x805D2EE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805D2EEC: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x805D2EF0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805D2EF4: swc1        $f8, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f8.u32l;
    // 0x805D2EF8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x805D2EFC: jal         0x805D3650
    // 0x805D2F00: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_805D3650(rdram, ctx);
        goto after_4;
    // 0x805D2F00: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_4:
    // 0x805D2F04: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805D2F08: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D2F0C: jal         0x800653D8
    // 0x805D2F10: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x805D2F10: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_5:
    // 0x805D2F14: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805D2F18: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x805D2F1C: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x805D2F20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805D2F24: beq         $v1, $zero, L_805D2F48
    if (ctx->r3 == 0) {
        // 0x805D2F28: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_805D2F48;
    }
    // 0x805D2F28: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x805D2F2C: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805D2F30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805D2F34: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x805D2F38: jal         0x805D1CC0
    // 0x805D2F3C: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    func_805D1CC0(rdram, ctx);
        goto after_6;
    // 0x805D2F3C: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    after_6:
    // 0x805D2F40: b           L_805D2F7C
    // 0x805D2F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805D2F7C;
    // 0x805D2F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D2F48:
    // 0x805D2F48: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805D2F4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D2F50: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x805D2F54: jal         0x805D1CC0
    // 0x805D2F58: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    func_805D1CC0(rdram, ctx);
        goto after_7;
    // 0x805D2F58: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    after_7:
    // 0x805D2F5C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x805D2F60: lw          $v0, 0x8($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X8);
    // 0x805D2F64: beql        $v0, $zero, L_805D2F7C
    if (ctx->r2 == 0) {
        // 0x805D2F68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805D2F7C;
    }
    goto skip_0;
    // 0x805D2F68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805D2F6C: lwc1        $f8, 0x3C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x805D2F70: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x805D2F74: swc1        $f10, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f10.u32l;
L_805D2F78:
    // 0x805D2F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D2F7C:
    // 0x805D2F7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805D2F80: jr          $ra
    // 0x805D2F84: nop

    return;
    // 0x805D2F84: nop

;}
RECOMP_FUNC void func_8003FBE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FBE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003FBE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003FBEC: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003FBF0: addiu       $at, $zero, 0x4005
    ctx->r1 = ADD32(0, 0X4005);
    // 0x8003FBF4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003FBF8: lw          $a3, 0x1F0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X1F0);
    // 0x8003FBFC: lhu         $v0, 0xC($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0XC);
    // 0x8003FC00: beq         $v0, $at, L_8003FC20
    if (ctx->r2 == ctx->r1) {
        // 0x8003FC04: addiu       $at, $zero, 0x406C
        ctx->r1 = ADD32(0, 0X406C);
            goto L_8003FC20;
    }
    // 0x8003FC04: addiu       $at, $zero, 0x406C
    ctx->r1 = ADD32(0, 0X406C);
    // 0x8003FC08: beq         $v0, $at, L_8003FC30
    if (ctx->r2 == ctx->r1) {
        // 0x8003FC0C: addiu       $at, $zero, 0x4144
        ctx->r1 = ADD32(0, 0X4144);
            goto L_8003FC30;
    }
    // 0x8003FC0C: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x8003FC10: beq         $v0, $at, L_8003FC30
    if (ctx->r2 == ctx->r1) {
        // 0x8003FC14: nop
    
            goto L_8003FC30;
    }
    // 0x8003FC14: nop

    // 0x8003FC18: b           L_8003FC3C
    // 0x8003FC1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003FC3C;
    // 0x8003FC1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003FC20:
    // 0x8003FC20: jal         0x8003F970
    // 0x8003FC24: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8003F970(rdram, ctx);
        goto after_0;
    // 0x8003FC24: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x8003FC28: b           L_8003FC3C
    // 0x8003FC2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003FC3C;
    // 0x8003FC2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003FC30:
    // 0x8003FC30: jal         0x8003FAA4
    // 0x8003FC34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8003FAA4(rdram, ctx);
        goto after_1;
    // 0x8003FC34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8003FC38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003FC3C:
    // 0x8003FC3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003FC40: jr          $ra
    // 0x8003FC44: nop

    return;
    // 0x8003FC44: nop

;}
RECOMP_FUNC void func_805AE474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE474: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE478: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE47C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE480: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE484: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE488: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE48C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE490: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE494: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE498: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE49C: jr          $ra
    // 0x805AE4A0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE4A0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80515BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80515BD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80515BD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80515BDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80515BE0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80515BE4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80515BE8: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80515BEC: lw          $t7, 0x478($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X478);
    // 0x80515BF0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80515BF4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80515BF8: lwc1        $f4, 0x30($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X30);
    // 0x80515BFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80515C00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80515C04: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x80515C08: lw          $t8, 0x478($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X478);
    // 0x80515C0C: lwc1        $f6, 0x34($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X34);
    // 0x80515C10: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80515C14: lw          $t9, 0x478($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X478);
    // 0x80515C18: lwc1        $f8, 0x38($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X38);
    // 0x80515C1C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80515C20: swc1        $f16, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f16.u32l;
    // 0x80515C24: jal         0x805158B4
    // 0x80515C28: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    func_805158B4(rdram, ctx);
        goto after_0;
    // 0x80515C28: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    after_0:
    // 0x80515C2C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80515C30: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80515C34: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x80515C38: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x80515C3C: lhu         $v0, 0xC($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0XC);
    // 0x80515C40: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x80515C44: bne         $t1, $at, L_80515C80
    if (ctx->r9 != ctx->r1) {
        // 0x80515C48: andi        $t2, $v0, 0x8000
        ctx->r10 = ctx->r2 & 0X8000;
            goto L_80515C80;
    }
    // 0x80515C48: andi        $t2, $v0, 0x8000
    ctx->r10 = ctx->r2 & 0X8000;
    // 0x80515C4C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80515C50: jal         0x80067BBC
    // 0x80515C54: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x80515C54: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x80515C58: addiu       $a0, $zero, 0x267
    ctx->r4 = ADD32(0, 0X267);
    // 0x80515C5C: jal         0x80067818
    // 0x80515C60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80515C60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80515C64: jal         0x80515868
    // 0x80515C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80515868(rdram, ctx);
        goto after_3;
    // 0x80515C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80515C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80515C70: jal         0x80515DD4
    // 0x80515C74: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80515DD4(rdram, ctx);
        goto after_4;
    // 0x80515C74: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x80515C78: b           L_80515CF4
    // 0x80515C7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80515CF4;
    // 0x80515C7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80515C80:
    // 0x80515C80: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80515C84: bne         $t2, $at, L_80515CF0
    if (ctx->r10 != ctx->r1) {
        // 0x80515C88: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_80515CF0;
    }
    // 0x80515C88: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80515C8C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80515C90: lw          $v0, 0x1E0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X1E0);
    // 0x80515C94: bne         $v0, $zero, L_80515CD0
    if (ctx->r2 != 0) {
        // 0x80515C98: slti        $at, $v0, 0x10
        ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
            goto L_80515CD0;
    }
    // 0x80515C98: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80515C9C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80515CA0: jal         0x80067BBC
    // 0x80515CA4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x80515CA4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x80515CA8: addiu       $a0, $zero, 0x267
    ctx->r4 = ADD32(0, 0X267);
    // 0x80515CAC: jal         0x80067818
    // 0x80515CB0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x80515CB0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80515CB4: jal         0x80515868
    // 0x80515CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80515868(rdram, ctx);
        goto after_7;
    // 0x80515CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80515CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80515CC0: jal         0x80515DD4
    // 0x80515CC4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80515DD4(rdram, ctx);
        goto after_8;
    // 0x80515CC4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_8:
    // 0x80515CC8: b           L_80515CF4
    // 0x80515CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80515CF4;
    // 0x80515CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80515CD0:
    // 0x80515CD0: bnel        $at, $zero, L_80515CF4
    if (ctx->r1 != 0) {
        // 0x80515CD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80515CF4;
    }
    goto skip_0;
    // 0x80515CD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80515CD8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80515CDC: jal         0x80067BBC
    // 0x80515CE0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_9;
    // 0x80515CE0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_9:
    // 0x80515CE4: addiu       $a0, $zero, 0x268
    ctx->r4 = ADD32(0, 0X268);
    // 0x80515CE8: jal         0x80067818
    // 0x80515CEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_10;
    // 0x80515CEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
L_80515CF0:
    // 0x80515CF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80515CF4:
    // 0x80515CF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80515CF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80515CFC: jr          $ra
    // 0x80515D00: nop

    return;
    // 0x80515D00: nop

;}
RECOMP_FUNC void func_80441544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441544: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80441548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044154C: jal         0x8004700C
    // 0x80441550: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80441550: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80441554: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80441558: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8044155C: beq         $v0, $zero, L_804415B4
    if (ctx->r2 == 0) {
        // 0x80441560: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_804415B4;
    }
    // 0x80441560: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80441564: lwc1        $f4, 0x1C78($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C78);
    // 0x80441568: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8044156C: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80441570: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80441574: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80441578: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8044157C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80441580: nop

    // 0x80441584: bc1fl       L_804415A0
    if (!c1cs) {
        // 0x80441588: lw          $t6, 0x138($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X138);
            goto L_804415A0;
    }
    goto skip_0;
    // 0x80441588: lw          $t6, 0x138($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X138);
    skip_0:
    // 0x8044158C: jal         0x8043F46C
    // 0x80441590: nop

    func_8043F46C(rdram, ctx);
        goto after_1;
    // 0x80441590: nop

    after_1:
    // 0x80441594: b           L_804415B8
    // 0x80441598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804415B8;
    // 0x80441598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044159C: lw          $t6, 0x138($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X138);
L_804415A0:
    // 0x804415A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804415A4: bnel        $t6, $at, L_804415B8
    if (ctx->r14 != ctx->r1) {
        // 0x804415A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804415B8;
    }
    goto skip_1;
    // 0x804415A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804415AC: jal         0x8043F6F4
    // 0x804415B0: nop

    func_8043F6F4(rdram, ctx);
        goto after_2;
    // 0x804415B0: nop

    after_2:
L_804415B4:
    // 0x804415B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804415B8:
    // 0x804415B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804415BC: jr          $ra
    // 0x804415C0: nop

    return;
    // 0x804415C0: nop

;}
RECOMP_FUNC void func_804EF9E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF9E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EF9EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF9F0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804EF9F4: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804EF9F8: lui         $t8, 0x804F
    ctx->r24 = S32(RELOC_HI16(267, 0X114C) << 16);
    // 0x804EF9FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804EFA00: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804EFA04: lw          $t8, -0x124($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(267, 0X114C));
    // 0x804EFA08: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804EFA0C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804EFA10: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804EFA14: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804EFA18: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804EFA1C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804EFA20: beql        $v1, $zero, L_804EFA54
    if (ctx->r3 == 0) {
        // 0x804EFA24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804EFA54;
    }
    goto skip_0;
    // 0x804EFA24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804EFA28: jalr        $v1
    // 0x804EFA2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804EFA2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804EFA30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804EFA34: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804EFA38: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804EFA3C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804EFA40: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804EFA44: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804EFA48: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804EFA4C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804EFA50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804EFA54:
    // 0x804EFA54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EFA58: jr          $ra
    // 0x804EFA5C: nop

    return;
    // 0x804EFA5C: nop

;}
RECOMP_FUNC void func_80449D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449D1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80449D20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80449D24: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80449D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80449D2C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80449D30: bne         $a2, $zero, L_80449D70
    if (ctx->r6 != 0) {
        // 0x80449D34: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80449D70;
    }
    // 0x80449D34: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80449D38: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x80449D3C: lw          $v1, 0x88($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X88);
    // 0x80449D40: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x80449D44: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80449D48: bne         $at, $zero, L_80449DB0
    if (ctx->r1 != 0) {
        // 0x80449D4C: sw          $t7, 0x28($v0)
        MEM_W(0X28, ctx->r2) = ctx->r15;
            goto L_80449DB0;
    }
    // 0x80449D4C: sw          $t7, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r15;
    // 0x80449D50: jal         0x80446B28
    // 0x80449D54: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446B28(rdram, ctx);
        goto after_0;
    // 0x80449D54: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80449D58: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80449D5C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449D60: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80449D64: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80449D68: b           L_80449DB0
    // 0x80449D6C: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80449DB0;
    // 0x80449D6C: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_80449D70:
    // 0x80449D70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80449D74: bnel        $a2, $at, L_80449DA0
    if (ctx->r6 != ctx->r1) {
        // 0x80449D78: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80449DA0;
    }
    goto skip_0;
    // 0x80449D78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80449D7C: jal         0x80446B28
    // 0x80449D80: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446B28(rdram, ctx);
        goto after_1;
    // 0x80449D80: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80449D84: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80449D88: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449D8C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80449D90: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80449D94: b           L_80449DB0
    // 0x80449D98: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_80449DB0;
    // 0x80449D98: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80449D9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80449DA0:
    // 0x80449DA0: bnel        $a2, $at, L_80449DB4
    if (ctx->r6 != ctx->r1) {
        // 0x80449DA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449DB4;
    }
    goto skip_1;
    // 0x80449DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80449DA8: jal         0x80446B8C
    // 0x80449DAC: nop

    func_80446B8C(rdram, ctx);
        goto after_2;
    // 0x80449DAC: nop

    after_2:
L_80449DB0:
    // 0x80449DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449DB4:
    // 0x80449DB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80449DB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449DBC: jr          $ra
    // 0x80449DC0: nop

    return;
    // 0x80449DC0: nop

;}
RECOMP_FUNC void func_805A35B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A35B4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A35B8: addiu       $t5, $zero, -0xA0
    ctx->r13 = ADD32(0, -0XA0);
    // 0x805A35BC: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x805A35C0: lw          $t0, 0x68($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X68);
    // 0x805A35C4: lw          $v1, 0x48($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X48);
    // 0x805A35C8: lw          $a1, 0x4C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4C);
    // 0x805A35CC: lw          $a2, 0x50($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X50);
    // 0x805A35D0: lw          $a3, 0x54($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X54);
    // 0x805A35D4: lw          $t1, 0x58($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X58);
    // 0x805A35D8: lw          $t2, 0x5C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X5C);
    // 0x805A35DC: lw          $t3, 0x60($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X60);
    // 0x805A35E0: lw          $t4, 0x64($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X64);
    // 0x805A35E4: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x805A35E8: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x805A35EC: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x805A35F0: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x805A35F4: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // 0x805A35F8: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x805A35FC: sh          $zero, 0x10($v0)
    MEM_H(0X10, ctx->r2) = 0;
    // 0x805A3600: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    // 0x805A3604: sh          $t6, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r14;
    // 0x805A3608: sh          $zero, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = 0;
    // 0x805A360C: sh          $zero, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = 0;
    // 0x805A3610: sh          $zero, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = 0;
    // 0x805A3614: sh          $zero, 0x20($v0)
    MEM_H(0X20, ctx->r2) = 0;
    // 0x805A3618: sh          $zero, 0x22($v0)
    MEM_H(0X22, ctx->r2) = 0;
    // 0x805A361C: sh          $t0, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r8;
    // 0x805A3620: sh          $t5, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r13;
    // 0x805A3624: sh          $zero, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = 0;
    // 0x805A3628: sh          $zero, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = 0;
    // 0x805A362C: sh          $zero, 0x30($v0)
    MEM_H(0X30, ctx->r2) = 0;
    // 0x805A3630: sh          $zero, 0x32($v0)
    MEM_H(0X32, ctx->r2) = 0;
    // 0x805A3634: sh          $t0, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r8;
    // 0x805A3638: sh          $t7, 0x38($v0)
    MEM_H(0X38, ctx->r2) = ctx->r15;
    // 0x805A363C: sh          $zero, 0x3C($v0)
    MEM_H(0X3C, ctx->r2) = 0;
    // 0x805A3640: sh          $zero, 0x3E($v0)
    MEM_H(0X3E, ctx->r2) = 0;
    // 0x805A3644: sh          $zero, 0x40($v0)
    MEM_H(0X40, ctx->r2) = 0;
    // 0x805A3648: sh          $zero, 0x42($v0)
    MEM_H(0X42, ctx->r2) = 0;
    // 0x805A364C: sb          $v1, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r3;
    // 0x805A3650: sb          $v1, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r3;
    // 0x805A3654: sb          $a1, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r5;
    // 0x805A3658: sb          $a1, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r5;
    // 0x805A365C: sb          $a2, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r6;
    // 0x805A3660: sb          $a2, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r6;
    // 0x805A3664: sb          $a3, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r7;
    // 0x805A3668: sb          $a3, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r7;
    // 0x805A366C: sb          $t1, 0x34($v0)
    MEM_B(0X34, ctx->r2) = ctx->r9;
    // 0x805A3670: sb          $t1, 0x44($v0)
    MEM_B(0X44, ctx->r2) = ctx->r9;
    // 0x805A3674: sb          $t2, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r10;
    // 0x805A3678: sb          $t2, 0x45($v0)
    MEM_B(0X45, ctx->r2) = ctx->r10;
    // 0x805A367C: sb          $t3, 0x36($v0)
    MEM_B(0X36, ctx->r2) = ctx->r11;
    // 0x805A3680: sb          $t3, 0x46($v0)
    MEM_B(0X46, ctx->r2) = ctx->r11;
    // 0x805A3684: sb          $t4, 0x37($v0)
    MEM_B(0X37, ctx->r2) = ctx->r12;
    // 0x805A3688: jr          $ra
    // 0x805A368C: sb          $t4, 0x47($v0)
    MEM_B(0X47, ctx->r2) = ctx->r12;
    return;
    // 0x805A368C: sb          $t4, 0x47($v0)
    MEM_B(0X47, ctx->r2) = ctx->r12;
;}
RECOMP_FUNC void func_807C3ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C3AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C3AE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807C3AE8: jal         0x80046E88
    // 0x807C3AEC: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    func_80046E88(rdram, ctx);
        goto after_0;
    // 0x807C3AEC: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    after_0:
    // 0x807C3AF0: beq         $v0, $zero, L_807C3B3C
    if (ctx->r2 == 0) {
        // 0x807C3AF4: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_807C3B3C;
    }
    // 0x807C3AF4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x807C3AF8: lw          $a0, 0x16C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X16C);
    // 0x807C3AFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C3B00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807C3B04: lbu         $v1, 0x10($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X10);
    // 0x807C3B08: addiu       $a0, $a0, 0xD
    ctx->r4 = ADD32(ctx->r4, 0XD);
    // 0x807C3B0C: beq         $v1, $zero, L_807C3B2C
    if (ctx->r3 == 0) {
        // 0x807C3B10: addiu       $v1, $v1, -0x2
        ctx->r3 = ADD32(ctx->r3, -0X2);
            goto L_807C3B2C;
    }
    // 0x807C3B10: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x807C3B14: bgez        $v1, L_807C3B24
    if (SIGNED(ctx->r3) >= 0) {
        // 0x807C3B18: nop
    
            goto L_807C3B24;
    }
    // 0x807C3B18: nop

    // 0x807C3B1C: b           L_807C3B4C
    // 0x807C3B20: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
        goto L_807C3B4C;
    // 0x807C3B20: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
L_807C3B24:
    // 0x807C3B24: b           L_807C3B4C
    // 0x807C3B28: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
        goto L_807C3B4C;
    // 0x807C3B28: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
L_807C3B2C:
    // 0x807C3B2C: jal         0x807C3EC0
    // 0x807C3B30: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_807C3EC0(rdram, ctx);
        goto after_1;
    // 0x807C3B30: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x807C3B34: b           L_807C3B50
    // 0x807C3B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807C3B50;
    // 0x807C3B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C3B3C:
    // 0x807C3B3C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807C3B40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C3B44: jal         0x807C3EC0
    // 0x807C3B48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_807C3EC0(rdram, ctx);
        goto after_2;
    // 0x807C3B48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_807C3B4C:
    // 0x807C3B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C3B50:
    // 0x807C3B50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C3B54: jr          $ra
    // 0x807C3B58: nop

    return;
    // 0x807C3B58: nop

;}
RECOMP_FUNC void func_8073B430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073B430: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(739, 0X22EC) << 16);
    // 0x8073B434: lhu         $t6, -0x42E4($t6)
    ctx->r14 = MEM_HU(ctx->r14, (int16_t)RELOC_LO16(739, 0X22EC));
    // 0x8073B438: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8073B43C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8073B440: bne         $v1, $t6, L_8073B454
    if (ctx->r3 != ctx->r14) {
        // 0x8073B444: lui         $t7, 0x8074
        ctx->r15 = S32(RELOC_HI16(739, 0X22EE) << 16);
            goto L_8073B454;
    }
    // 0x8073B444: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(739, 0X22EE) << 16);
    // 0x8073B448: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(739, 0X2350) << 16);
    // 0x8073B44C: jr          $ra
    // 0x8073B450: lhu         $v0, -0x4280($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2350));
    return;
    // 0x8073B450: lhu         $v0, -0x4280($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2350));
L_8073B454:
    // 0x8073B454: lhu         $t7, -0x42E2($t7)
    ctx->r15 = MEM_HU(ctx->r15, (int16_t)RELOC_LO16(739, 0X22EE));
    // 0x8073B458: lui         $a1, 0x8074
    ctx->r5 = S32(RELOC_HI16(739, 0X22F0) << 16);
    // 0x8073B45C: addiu       $a1, $a1, -0x42E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(739, 0X22F0));
    // 0x8073B460: bne         $v1, $t7, L_8073B474
    if (ctx->r3 != ctx->r15) {
        // 0x8073B464: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_8073B474;
    }
    // 0x8073B464: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8073B468: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(739, 0X2352) << 16);
    // 0x8073B46C: jr          $ra
    // 0x8073B470: lhu         $v0, -0x427E($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2352));
    return;
    // 0x8073B470: lhu         $v0, -0x427E($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2352));
L_8073B474:
    // 0x8073B474: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(739, 0X2350) << 16);
    // 0x8073B478: addiu       $v0, $v0, -0x4280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(739, 0X2350));
L_8073B47C:
    // 0x8073B47C: lhu         $t8, 0x0($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X0);
    // 0x8073B480: bnel        $v1, $t8, L_8073B49C
    if (ctx->r3 != ctx->r24) {
        // 0x8073B484: lhu         $t9, 0x2($a1)
        ctx->r25 = MEM_HU(ctx->r5, 0X2);
            goto L_8073B49C;
    }
    goto skip_0;
    // 0x8073B484: lhu         $t9, 0x2($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X2);
    skip_0:
    // 0x8073B488: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(739, 0X2350) << 16);
    // 0x8073B48C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8073B490: jr          $ra
    // 0x8073B494: lhu         $v0, -0x4280($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2350));
    return;
    // 0x8073B494: lhu         $v0, -0x4280($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2350));
    // 0x8073B498: lhu         $t9, 0x2($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X2);
L_8073B49C:
    // 0x8073B49C: bnel        $v1, $t9, L_8073B4B8
    if (ctx->r3 != ctx->r25) {
        // 0x8073B4A0: lhu         $t0, 0x4($a1)
        ctx->r8 = MEM_HU(ctx->r5, 0X4);
            goto L_8073B4B8;
    }
    goto skip_1;
    // 0x8073B4A0: lhu         $t0, 0x4($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X4);
    skip_1:
    // 0x8073B4A4: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(739, 0X2352) << 16);
    // 0x8073B4A8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8073B4AC: jr          $ra
    // 0x8073B4B0: lhu         $v0, -0x427E($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2352));
    return;
    // 0x8073B4B0: lhu         $v0, -0x427E($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2352));
    // 0x8073B4B4: lhu         $t0, 0x4($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X4);
L_8073B4B8:
    // 0x8073B4B8: bnel        $v1, $t0, L_8073B4D4
    if (ctx->r3 != ctx->r8) {
        // 0x8073B4BC: lhu         $t1, 0x6($a1)
        ctx->r9 = MEM_HU(ctx->r5, 0X6);
            goto L_8073B4D4;
    }
    goto skip_2;
    // 0x8073B4BC: lhu         $t1, 0x6($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X6);
    skip_2:
    // 0x8073B4C0: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(739, 0X2354) << 16);
    // 0x8073B4C4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8073B4C8: jr          $ra
    // 0x8073B4CC: lhu         $v0, -0x427C($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2354));
    return;
    // 0x8073B4CC: lhu         $v0, -0x427C($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2354));
    // 0x8073B4D0: lhu         $t1, 0x6($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X6);
L_8073B4D4:
    // 0x8073B4D4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8073B4D8: bne         $v1, $t1, L_8073B4F0
    if (ctx->r3 != ctx->r9) {
        // 0x8073B4DC: nop
    
            goto L_8073B4F0;
    }
    // 0x8073B4DC: nop

    // 0x8073B4E0: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(739, 0X2356) << 16);
    // 0x8073B4E4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8073B4E8: jr          $ra
    // 0x8073B4EC: lhu         $v0, -0x427A($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2356));
    return;
    // 0x8073B4EC: lhu         $v0, -0x427A($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2356));
L_8073B4F0:
    // 0x8073B4F0: bne         $a1, $v0, L_8073B47C
    if (ctx->r5 != ctx->r2) {
        // 0x8073B4F4: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_8073B47C;
    }
    // 0x8073B4F4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8073B4F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8073B4FC: jr          $ra
    // 0x8073B500: nop

    return;
    // 0x8073B500: nop

;}
RECOMP_FUNC void func_80471050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471050: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80471054: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80471058: sw          $zero, 0xAA0($v0)
    MEM_W(0XAA0, ctx->r2) = 0;
    // 0x8047105C: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x80471060: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // 0x80471064: sw          $zero, 0xCE8($v0)
    MEM_W(0XCE8, ctx->r2) = 0;
    // 0x80471068: sw          $zero, 0xCD0($v0)
    MEM_W(0XCD0, ctx->r2) = 0;
    // 0x8047106C: sw          $zero, 0xCD4($v0)
    MEM_W(0XCD4, ctx->r2) = 0;
    // 0x80471070: sw          $zero, 0xCD8($v0)
    MEM_W(0XCD8, ctx->r2) = 0;
    // 0x80471074: sw          $zero, 0xCDC($v0)
    MEM_W(0XCDC, ctx->r2) = 0;
    // 0x80471078: sw          $zero, 0xCE0($v0)
    MEM_W(0XCE0, ctx->r2) = 0;
    // 0x8047107C: sw          $zero, 0xCE4($v0)
    MEM_W(0XCE4, ctx->r2) = 0;
    // 0x80471080: jr          $ra
    // 0x80471084: sw          $zero, 0xF80($v0)
    MEM_W(0XF80, ctx->r2) = 0;
    return;
    // 0x80471084: sw          $zero, 0xF80($v0)
    MEM_W(0XF80, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80439D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80439D60: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80439D64: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x80439D68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80439D6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80439D70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80439D74: lbu         $t7, 0xF0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XF0);
    // 0x80439D78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80439D7C: jal         0x80439090
    // 0x80439D80: sb          $t7, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r15;
    func_80439090(rdram, ctx);
        goto after_0;
    // 0x80439D80: sb          $t7, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r15;
    after_0:
    // 0x80439D84: jal         0x804393DC
    // 0x80439D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804393DC(rdram, ctx);
        goto after_1;
    // 0x80439D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80439D8C: jal         0x80439BAC
    // 0x80439D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80439BAC(rdram, ctx);
        goto after_2;
    // 0x80439D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80439D94: jal         0x80438BBC
    // 0x80439D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80438BBC(rdram, ctx);
        goto after_3;
    // 0x80439D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80439D9C: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x80439DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80439DA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80439DA8: bne         $t8, $zero, L_80439DB8
    if (ctx->r24 != 0) {
        // 0x80439DAC: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_80439DB8;
    }
    // 0x80439DAC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80439DB0: jal         0x8043A27C
    // 0x80439DB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8043A27C(rdram, ctx);
        goto after_4;
    // 0x80439DB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
L_80439DB8:
    // 0x80439DB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80439DBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80439DC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80439DC4: jr          $ra
    // 0x80439DC8: nop

    return;
    // 0x80439DC8: nop

;}
RECOMP_FUNC void func_80533108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533108: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8053310C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80533110: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80533114: jal         0x80047090
    // 0x80533118: addiu       $a0, $zero, 0x4070
    ctx->r4 = ADD32(0, 0X4070);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80533118: addiu       $a0, $zero, 0x4070
    ctx->r4 = ADD32(0, 0X4070);
    after_0:
    // 0x8053311C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80533120: beq         $v0, $at, L_8053315C
    if (ctx->r2 == ctx->r1) {
        // 0x80533124: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8053315C;
    }
    // 0x80533124: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80533128: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8053312C: lui         $at, 0x4070
    ctx->r1 = S32(0X4070 << 16);
    // 0x80533130: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80533134: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80533138: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8053313C: jal         0x8004613C
    // 0x80533140: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80533140: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_1:
    // 0x80533144: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80533148: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8053314C: jal         0x80047F9C
    // 0x80533150: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80533150: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80533154: jal         0x8005FDC4
    // 0x80533158: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x80533158: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
L_8053315C:
    // 0x8053315C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80533160: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80533164: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80533168: jr          $ra
    // 0x8053316C: nop

    return;
    // 0x8053316C: nop

;}
RECOMP_FUNC void func_80665408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80665408: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8066540C: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x80665410: lui         $t6, 0x8066
    ctx->r14 = S32(RELOC_HI16(504, 0X2B58) << 16);
    // 0x80665414: lw          $t6, 0x7828($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(504, 0X2B58));
    // 0x80665418: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8066541C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80665420: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // 0x80665424: sw          $t7, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r15;
    // 0x80665428: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x8066542C: jr          $ra
    // 0x80665430: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
    return;
    // 0x80665430: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
;}
RECOMP_FUNC void func_806E6880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E6880: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806E6884: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x806E6888: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x806E688C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x806E6890: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x806E6894: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x806E6898: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E689C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x806E68A0: jal         0x800610A0
    // 0x806E68A4: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    func_800610A0(rdram, ctx);
        goto after_0;
    // 0x806E68A4: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x806E68A8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x806E68AC: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x806E68B0: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_806E68B4:
    // 0x806E68B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x806E68B8: jal         0x80047EB0
    // 0x806E68BC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047EB0(rdram, ctx);
        goto after_1;
    // 0x806E68BC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x806E68C0: beql        $v0, $zero, L_806E68E4
    if (ctx->r2 == 0) {
        // 0x806E68C4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_806E68E4;
    }
    goto skip_0;
    // 0x806E68C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x806E68C8: jal         0x8004816C
    // 0x806E68CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8004816C(rdram, ctx);
        goto after_2;
    // 0x806E68CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x806E68D0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x806E68D4: addiu       $t7, $s1, 0x1
    ctx->r15 = ADD32(ctx->r17, 0X1);
    // 0x806E68D8: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x806E68DC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x806E68E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_806E68E4:
    // 0x806E68E4: bne         $s1, $s2, L_806E68B4
    if (ctx->r17 != ctx->r18) {
        // 0x806E68E8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_806E68B4;
    }
    // 0x806E68E8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x806E68EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x806E68F0: jal         0x80047EB0
    // 0x806E68F4: lw          $a1, 0x28($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X28);
    func_80047EB0(rdram, ctx);
        goto after_3;
    // 0x806E68F4: lw          $a1, 0x28($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X28);
    after_3:
    // 0x806E68F8: beql        $v0, $zero, L_806E6928
    if (ctx->r2 == 0) {
        // 0x806E68FC: lw          $a0, 0x34($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X34);
            goto L_806E6928;
    }
    goto skip_1;
    // 0x806E68FC: lw          $a0, 0x34($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X34);
    skip_1:
    // 0x806E6900: jal         0x8004816C
    // 0x806E6904: lw          $a0, 0x28($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X28);
    func_8004816C(rdram, ctx);
        goto after_4;
    // 0x806E6904: lw          $a0, 0x28($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X28);
    after_4:
    // 0x806E6908: lw          $t8, 0x28($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X28);
    // 0x806E690C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x806E6910: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x806E6914: lw          $v0, 0x1F4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X1F4);
    // 0x806E6918: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
    // 0x806E691C: lw          $t9, -0x7294($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7294);
    // 0x806E6920: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
    // 0x806E6924: lw          $a0, 0x34($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X34);
L_806E6928:
    // 0x806E6928: jal         0x80067BBC
    // 0x806E692C: lw          $a1, 0x38($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x806E692C: lw          $a1, 0x38($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X38);
    after_5:
    // 0x806E6930: addiu       $a0, $zero, 0x249
    ctx->r4 = ADD32(0, 0X249);
    // 0x806E6934: jal         0x80067818
    // 0x806E6938: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x806E6938: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x806E693C: jal         0x800447C8
    // 0x806E6940: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800447C8(rdram, ctx);
        goto after_7;
    // 0x806E6940: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x806E6944: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x806E6948: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E694C: jal         0x806E6BC8
    // 0x806E6950: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_806E6BC8(rdram, ctx);
        goto after_8;
    // 0x806E6950: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
    // 0x806E6954: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x806E6958: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E695C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x806E6960: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x806E6964: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x806E6968: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x806E696C: jr          $ra
    // 0x806E6970: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x806E6970: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80437F8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437F8C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80437F90: lwc1        $f2, 0xC4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80437F94: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437F98: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80437F9C: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80437FA0: bc1fl       L_80437FC8
    if (!c1cs) {
        // 0x80437FA4: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_80437FC8;
    }
    goto skip_0;
    // 0x80437FA4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_0:
    // 0x80437FA8: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80437FAC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80437FB0: nop

    // 0x80437FB4: bc1f        L_80437FEC
    if (!c1cs) {
        // 0x80437FB8: nop
    
            goto L_80437FEC;
    }
    // 0x80437FB8: nop

    // 0x80437FBC: b           L_80437FEC
    // 0x80437FC0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_80437FEC;
    // 0x80437FC0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80437FC4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_80437FC8:
    // 0x80437FC8: nop

    // 0x80437FCC: bc1f        L_80437FEC
    if (!c1cs) {
        // 0x80437FD0: nop
    
            goto L_80437FEC;
    }
    // 0x80437FD0: nop

    // 0x80437FD4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80437FD8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80437FDC: nop

    // 0x80437FE0: bc1f        L_80437FEC
    if (!c1cs) {
        // 0x80437FE4: nop
    
            goto L_80437FEC;
    }
    // 0x80437FE4: nop

    // 0x80437FE8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_80437FEC:
    // 0x80437FEC: jr          $ra
    // 0x80437FF0: swc1        $f2, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x80437FF0: swc1        $f2, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_8040CF4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040CF4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8040CF50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040CF54: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040CF58: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8040CF5C: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(20, 0X1F10) << 16);
    // 0x8040CF60: lw          $a1, 0x2C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C);
    // 0x8040CF64: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8040CF68: lh          $t6, 0x13E($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X13E);
    // 0x8040CF6C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8040CF70: lwc1        $f4, -0x1AF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(20, 0X1F10));
    // 0x8040CF74: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8040CF78: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8040CF7C: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8040CF80: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8040CF84: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8040CF88: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    // 0x8040CF8C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8040CF90: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8040CF94: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8040CF98: lwc1        $f18, 0x44($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8040CF9C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8040CFA0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8040CFA4: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8040CFA8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8040CFAC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8040CFB0: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8040CFB4: lw          $t9, 0x48($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X48);
    // 0x8040CFB8: jalr        $t9
    // 0x8040CFBC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8040CFBC: nop

    after_0:
    // 0x8040CFC0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8040CFC4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8040CFC8: jal         0x80047F9C
    // 0x8040CFCC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x8040CFCC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8040CFD0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8040CFD4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8040CFD8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8040CFDC: sb          $t0, 0x17C($t1)
    MEM_B(0X17C, ctx->r9) = ctx->r8;
    // 0x8040CFE0: lw          $t2, 0x2C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2C);
    // 0x8040CFE4: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8040CFE8: sw          $t3, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r11;
    // 0x8040CFEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040CFF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8040CFF4: jr          $ra
    // 0x8040CFF8: nop

    return;
    // 0x8040CFF8: nop

;}
RECOMP_FUNC void func_80475180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475180: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475184: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475188: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047518C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475190: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475194: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475198: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047519C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804751A0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804751A4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804751A8: jr          $ra
    // 0x804751AC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804751AC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80675F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675F84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80675F88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80675F8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80675F90: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80675F94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80675F98: jal         0x80675C30
    // 0x80675F9C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80675C30(rdram, ctx);
        goto after_0;
    // 0x80675F9C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80675FA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80675FA4: bne         $v0, $at, L_80675FD0
    if (ctx->r2 != ctx->r1) {
        // 0x80675FA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80675FD0;
    }
    // 0x80675FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80675FAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80675FB0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80675FB4: jal         0x80677A88
    // 0x80675FB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80677A88(rdram, ctx);
        goto after_1;
    // 0x80675FB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80675FBC: jal         0x80675B9C
    // 0x80675FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675B9C(rdram, ctx);
        goto after_2;
    // 0x80675FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80675FC4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80675FC8: addiu       $t7, $zero, 0x12C
    ctx->r15 = ADD32(0, 0X12C);
    // 0x80675FCC: sh          $t7, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r15;
L_80675FD0:
    // 0x80675FD0: jal         0x80675CD0
    // 0x80675FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675CD0(rdram, ctx);
        goto after_3;
    // 0x80675FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80675FD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80675FDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80675FE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80675FE4: jr          $ra
    // 0x80675FE8: nop

    return;
    // 0x80675FE8: nop

;}
RECOMP_FUNC void PadSetup_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081AF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80081AF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80081AF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80081AFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80081B00: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80081B04: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    // 0x80081B08: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80081B0C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80081B10: jal         0x80085140
    // 0x80081B14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    osContInit_recomp(rdram, ctx);
        goto after_0;
    // 0x80081B14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80081B18: beq         $v0, $zero, L_80081B28
    if (ctx->r2 == 0) {
        // 0x80081B1C: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_80081B28;
    }
    // 0x80081B1C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80081B20: b           L_80081C1C
    // 0x80081B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80081C1C;
    // 0x80081B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80081B28:
    // 0x80081B28: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    // 0x80081B2C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80081B30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80081B34: bnel        $t7, $at, L_80081C18
    if (ctx->r15 != ctx->r1) {
        // 0x80081B38: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80081C18;
    }
    goto skip_0;
    // 0x80081B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80081B3C: jal         0x80089DF0
    // 0x80081B40: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    osContStartQuery_recomp(rdram, ctx);
        goto after_1;
    // 0x80081B40: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_1:
    // 0x80081B44: beq         $v0, $zero, L_80081B54
    if (ctx->r2 == 0) {
        // 0x80081B48: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_80081B54;
    }
    // 0x80081B48: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80081B4C: b           L_80081C18
    // 0x80081B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80081C18;
    // 0x80081B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80081B54:
    // 0x80081B54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80081B58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80081B5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80081B60: jal         0x800824B0
    // 0x80081B64: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80081B64: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x80081B68: jal         0x80089E74
    // 0x80081B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osContGetQuery_recomp(rdram, ctx);
        goto after_3;
    // 0x80081B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80081B70: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80081B74: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80081B78: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80081B7C: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
    // 0x80081B80: lbu         $t8, 0x3($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X3);
    // 0x80081B84: bne         $t8, $zero, L_80081BA8
    if (ctx->r24 != 0) {
        // 0x80081B88: nop
    
            goto L_80081BA8;
    }
    // 0x80081B88: nop

    // 0x80081B8C: lhu         $t9, 0x0($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X0);
    // 0x80081B90: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80081B94: ori         $t1, $zero, 0x1
    ctx->r9 = 0 | 0X1;
    // 0x80081B98: bnel        $v1, $t9, L_80081BAC
    if (ctx->r3 != ctx->r25) {
        // 0x80081B9C: lbu         $t2, 0x7($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X7);
            goto L_80081BAC;
    }
    goto skip_1;
    // 0x80081B9C: lbu         $t2, 0x7($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X7);
    skip_1:
    // 0x80081BA0: b           L_80081BA8
    // 0x80081BA4: sb          $t1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r9;
        goto L_80081BA8;
    // 0x80081BA4: sb          $t1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r9;
L_80081BA8:
    // 0x80081BA8: lbu         $t2, 0x7($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X7);
L_80081BAC:
    // 0x80081BAC: bnel        $t2, $zero, L_80081BD0
    if (ctx->r10 != 0) {
        // 0x80081BB0: lbu         $t6, 0xB($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0XB);
            goto L_80081BD0;
    }
    goto skip_2;
    // 0x80081BB0: lbu         $t6, 0xB($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XB);
    skip_2:
    // 0x80081BB4: lhu         $t3, 0x4($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X4);
    // 0x80081BB8: bnel        $v1, $t3, L_80081BD0
    if (ctx->r3 != ctx->r11) {
        // 0x80081BBC: lbu         $t6, 0xB($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0XB);
            goto L_80081BD0;
    }
    goto skip_3;
    // 0x80081BBC: lbu         $t6, 0xB($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XB);
    skip_3:
    // 0x80081BC0: lbu         $t4, 0x0($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X0);
    // 0x80081BC4: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x80081BC8: sb          $t5, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r13;
    // 0x80081BCC: lbu         $t6, 0xB($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XB);
L_80081BD0:
    // 0x80081BD0: bnel        $t6, $zero, L_80081BF4
    if (ctx->r14 != 0) {
        // 0x80081BD4: lbu         $t0, 0xF($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0XF);
            goto L_80081BF4;
    }
    goto skip_4;
    // 0x80081BD4: lbu         $t0, 0xF($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XF);
    skip_4:
    // 0x80081BD8: lhu         $t7, 0x8($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X8);
    // 0x80081BDC: bnel        $v1, $t7, L_80081BF4
    if (ctx->r3 != ctx->r15) {
        // 0x80081BE0: lbu         $t0, 0xF($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0XF);
            goto L_80081BF4;
    }
    goto skip_5;
    // 0x80081BE0: lbu         $t0, 0xF($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XF);
    skip_5:
    // 0x80081BE4: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x80081BE8: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x80081BEC: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
    // 0x80081BF0: lbu         $t0, 0xF($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XF);
L_80081BF4:
    // 0x80081BF4: bnel        $t0, $zero, L_80081C18
    if (ctx->r8 != 0) {
        // 0x80081BF8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80081C18;
    }
    goto skip_6;
    // 0x80081BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x80081BFC: lhu         $t1, 0xC($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XC);
    // 0x80081C00: bnel        $v1, $t1, L_80081C18
    if (ctx->r3 != ctx->r9) {
        // 0x80081C04: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80081C18;
    }
    goto skip_7;
    // 0x80081C04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_7:
    // 0x80081C08: lbu         $t2, 0x0($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X0);
    // 0x80081C0C: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x80081C10: sb          $t3, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r11;
    // 0x80081C14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80081C18:
    // 0x80081C18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80081C1C:
    // 0x80081C1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80081C20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80081C24: jr          $ra
    // 0x80081C28: nop

    return;
    // 0x80081C28: nop

;}
RECOMP_FUNC void func_80467D9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80467D9C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80467DA0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80467DA4: lh          $t6, 0x1A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1A);
    // 0x80467DA8: lh          $t7, 0x18($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X18);
    // 0x80467DAC: lw          $t8, 0x1FA0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1FA0);
    // 0x80467DB0: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467DB4: mflo        $t0
    ctx->r8 = lo;
    // 0x80467DB8: nop

    // 0x80467DBC: nop

    // 0x80467DC0: multu       $t0, $t8
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467DC4: mflo        $t9
    ctx->r25 = lo;
    // 0x80467DC8: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    // 0x80467DCC: addiu       $v1, $a2, 0x1C
    ctx->r3 = ADD32(ctx->r6, 0X1C);
    // 0x80467DD0: blez        $t0, L_80467E18
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80467DD4: addiu       $a3, $a2, 0xFDC
        ctx->r7 = ADD32(ctx->r6, 0XFDC);
            goto L_80467E18;
    }
    // 0x80467DD4: addiu       $a3, $a2, 0xFDC
    ctx->r7 = ADD32(ctx->r6, 0XFDC);
L_80467DD8:
    // 0x80467DD8: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x80467DDC: lbu         $t4, 0x3($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X3);
    // 0x80467DE0: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x80467DE4: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x80467DE8: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x80467DEC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80467DF0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80467DF4: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80467DF8: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80467DFC: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x80467E00: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80467E04: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x80467E08: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80467E0C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80467E10: bne         $at, $zero, L_80467DD8
    if (ctx->r1 != 0) {
        // 0x80467E14: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80467DD8;
    }
    // 0x80467E14: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80467E18:
    // 0x80467E18: jr          $ra
    // 0x80467E1C: nop

    return;
    // 0x80467E1C: nop

;}
RECOMP_FUNC void func_8046CB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046CB58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046CB5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046CB60: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8046CB64: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8046CB68: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8046CB6C: jal         0x80048F84
    // 0x8046CB70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8046CB70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8046CB74: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8046CB78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046CB7C: lw          $t6, 0x1E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1E0);
    // 0x8046CB80: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8046CB84: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8046CB88: blez        $t7, L_8046CBF0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8046CB8C: sw          $t7, 0x1E0($a3)
        MEM_W(0X1E0, ctx->r7) = ctx->r15;
            goto L_8046CBF0;
    }
    // 0x8046CB8C: sw          $t7, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r15;
    // 0x8046CB90: lw          $t9, 0x1F4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X1F4);
    // 0x8046CB94: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8046CB98: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8046CB9C: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x8046CBA0: beql        $t1, $zero, L_8046CBB4
    if (ctx->r9 == 0) {
        // 0x8046CBA4: lbu         $t3, 0x30($a3)
        ctx->r11 = MEM_BU(ctx->r7, 0X30);
            goto L_8046CBB4;
    }
    goto skip_0;
    // 0x8046CBA4: lbu         $t3, 0x30($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X30);
    skip_0:
    // 0x8046CBA8: b           L_8046CBD0
    // 0x8046CBAC: sb          $t2, 0x30($a3)
    MEM_B(0X30, ctx->r7) = ctx->r10;
        goto L_8046CBD0;
    // 0x8046CBAC: sb          $t2, 0x30($a3)
    MEM_B(0X30, ctx->r7) = ctx->r10;
    // 0x8046CBB0: lbu         $t3, 0x30($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X30);
L_8046CBB4:
    // 0x8046CBB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8046CBB8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8046CBBC: bne         $t3, $at, L_8046CBCC
    if (ctx->r11 != ctx->r1) {
        // 0x8046CBC0: addiu       $t5, $zero, 0x5
        ctx->r13 = ADD32(0, 0X5);
            goto L_8046CBCC;
    }
    // 0x8046CBC0: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8046CBC4: b           L_8046CBD0
    // 0x8046CBC8: sb          $t4, 0x30($a3)
    MEM_B(0X30, ctx->r7) = ctx->r12;
        goto L_8046CBD0;
    // 0x8046CBC8: sb          $t4, 0x30($a3)
    MEM_B(0X30, ctx->r7) = ctx->r12;
L_8046CBCC:
    // 0x8046CBCC: sb          $t5, 0x30($a3)
    MEM_B(0X30, ctx->r7) = ctx->r13;
L_8046CBD0:
    // 0x8046CBD0: lbu         $a2, 0x30($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X30);
    // 0x8046CBD4: jal         0x8046D3E8
    // 0x8046CBD8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8046D3E8(rdram, ctx);
        goto after_1;
    // 0x8046CBD8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x8046CBDC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8046CBE0: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x8046CBE4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8046CBE8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8046CBEC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8046CBF0:
    // 0x8046CBF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046CBF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046CBF8: jr          $ra
    // 0x8046CBFC: nop

    return;
    // 0x8046CBFC: nop

;}
RECOMP_FUNC void func_8042E298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042E298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042E29C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042E2A0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8042E2A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8042E2A8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8042E2AC: jal         0x80048F84
    // 0x8042E2B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8042E2B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8042E2B4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8042E2B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8042E2BC: lwc1        $f4, 0xC4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC4);
    // 0x8042E2C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8042E2C4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8042E2C8: nop

    // 0x8042E2CC: bc1fl       L_8042E370
    if (!c1cs) {
        // 0x8042E2D0: lw          $t2, 0x138($a2)
        ctx->r10 = MEM_W(ctx->r6, 0X138);
            goto L_8042E370;
    }
    goto skip_0;
    // 0x8042E2D0: lw          $t2, 0x138($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X138);
    skip_0:
    // 0x8042E2D4: lw          $t6, 0x138($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X138);
    // 0x8042E2D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042E2DC: bne         $t6, $at, L_8042E31C
    if (ctx->r14 != ctx->r1) {
        // 0x8042E2E0: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8042E31C;
    }
    // 0x8042E2E0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8042E2E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8042E2E8: lwc1        $f8, 0x50($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X50);
    // 0x8042E2EC: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x8042E2F0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8042E2F4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8042E2F8: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8042E2FC: nop

    // 0x8042E300: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8042E304: mfhi        $t8
    ctx->r24 = hi;
    // 0x8042E308: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8042E30C: nop

    // 0x8042E310: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8042E314: b           L_8042E400
    // 0x8042E318: swc1        $f6, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f6.u32l;
        goto L_8042E400;
    // 0x8042E318: swc1        $f6, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f6.u32l;
L_8042E31C:
    // 0x8042E31C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8042E320: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8042E324: lwc1        $f8, 0x50($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X50);
    // 0x8042E328: addiu       $t0, $zero, 0x168
    ctx->r8 = ADD32(0, 0X168);
    // 0x8042E32C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8042E330: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8042E334: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8042E338: nop

    // 0x8042E33C: bgez        $v0, L_8042E358
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8042E340: subu        $t1, $t0, $v0
        ctx->r9 = SUB32(ctx->r8, ctx->r2);
            goto L_8042E358;
    }
    // 0x8042E340: subu        $t1, $t0, $v0
    ctx->r9 = SUB32(ctx->r8, ctx->r2);
    // 0x8042E344: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8042E348: nop

    // 0x8042E34C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8042E350: b           L_8042E400
    // 0x8042E354: swc1        $f6, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f6.u32l;
        goto L_8042E400;
    // 0x8042E354: swc1        $f6, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f6.u32l;
L_8042E358:
    // 0x8042E358: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8042E35C: nop

    // 0x8042E360: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8042E364: b           L_8042E400
    // 0x8042E368: swc1        $f10, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f10.u32l;
        goto L_8042E400;
    // 0x8042E368: swc1        $f10, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f10.u32l;
    // 0x8042E36C: lw          $t2, 0x138($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X138);
L_8042E370:
    // 0x8042E370: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042E374: bne         $t2, $at, L_8042E3C8
    if (ctx->r10 != ctx->r1) {
        // 0x8042E378: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8042E3C8;
    }
    // 0x8042E378: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8042E37C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8042E380: lwc1        $f16, 0x50($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X50);
    // 0x8042E384: addiu       $t4, $zero, 0x168
    ctx->r12 = ADD32(0, 0X168);
    // 0x8042E388: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8042E38C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8042E390: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8042E394: nop

    // 0x8042E398: bgez        $v0, L_8042E3B4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8042E39C: subu        $t5, $t4, $v0
        ctx->r13 = SUB32(ctx->r12, ctx->r2);
            goto L_8042E3B4;
    }
    // 0x8042E39C: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x8042E3A0: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8042E3A4: nop

    // 0x8042E3A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8042E3AC: b           L_8042E400
    // 0x8042E3B0: swc1        $f10, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f10.u32l;
        goto L_8042E400;
    // 0x8042E3B0: swc1        $f10, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f10.u32l;
L_8042E3B4:
    // 0x8042E3B4: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8042E3B8: nop

    // 0x8042E3BC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8042E3C0: b           L_8042E400
    // 0x8042E3C4: swc1        $f18, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f18.u32l;
        goto L_8042E400;
    // 0x8042E3C4: swc1        $f18, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f18.u32l;
L_8042E3C8:
    // 0x8042E3C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8042E3CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8042E3D0: lwc1        $f4, 0x50($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X50);
    // 0x8042E3D4: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x8042E3D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8042E3DC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8042E3E0: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8042E3E4: nop

    // 0x8042E3E8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8042E3EC: mfhi        $t7
    ctx->r15 = hi;
    // 0x8042E3F0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8042E3F4: nop

    // 0x8042E3F8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8042E3FC: swc1        $f18, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f18.u32l;
L_8042E400:
    // 0x8042E400: jal         0x800592AC
    // 0x8042E404: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800592AC(rdram, ctx);
        goto after_1;
    // 0x8042E404: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8042E408: bne         $v0, $zero, L_8042E418
    if (ctx->r2 != 0) {
        // 0x8042E40C: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8042E418;
    }
    // 0x8042E40C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8042E410: jal         0x800447C8
    // 0x8042E414: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x8042E414: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
L_8042E418:
    // 0x8042E418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042E41C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042E420: jr          $ra
    // 0x8042E424: nop

    return;
    // 0x8042E424: nop

;}
RECOMP_FUNC void func_804A4F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4F64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A4F68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A4F6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804A4F70: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x804A4F74: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x804A4F78: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804A4F7C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x804A4F80: lw          $v1, 0x6EEC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6EEC);
    // 0x804A4F84: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x804A4F88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A4F8C: bne         $v1, $zero, L_804A4FBC
    if (ctx->r3 != 0) {
        // 0x804A4F90: nop
    
            goto L_804A4FBC;
    }
    // 0x804A4F90: nop

    // 0x804A4F94: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x804A4F98: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x804A4F9C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x804A4FA0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x804A4FA4: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x804A4FA8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x804A4FAC: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x804A4FB0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x804A4FB4: b           L_804A4FC4
    // 0x804A4FB8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
        goto L_804A4FC4;
    // 0x804A4FB8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_804A4FBC:
    // 0x804A4FBC: jal         0x804A4E94
    // 0x804A4FC0: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    func_804A4E94(rdram, ctx);
        goto after_0;
    // 0x804A4FC0: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    after_0:
L_804A4FC4:
    // 0x804A4FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A4FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A4FCC: jr          $ra
    // 0x804A4FD0: nop

    return;
    // 0x804A4FD0: nop

;}
RECOMP_FUNC void func_8046DD0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046DD0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8046DD10: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8046DD14: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8046DD18: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8046DD1C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8046DD20: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8046DD24: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8046DD28: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8046DD2C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8046DD30: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8046DD34: jr          $ra
    // 0x8046DD38: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8046DD38: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8078A2D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A2D0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8078A2D4: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x8078A2D8: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x8078A2DC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8078A2E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8078A2E4: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8078A2E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8078A2EC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8078A2F0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8078A2F4: lui         $t0, 0xFCFF
    ctx->r8 = S32(0XFCFF << 16);
    // 0x8078A2F8: lui         $t1, 0xFFFC
    ctx->r9 = S32(0XFFFC << 16);
    // 0x8078A2FC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8078A300: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8078A304: ori         $t1, $t1, 0xF279
    ctx->r9 = ctx->r9 | 0XF279;
    // 0x8078A308: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x8078A30C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8078A310: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8078A314: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8078A318: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8078A31C: lui         $t4, 0x8
    ctx->r12 = S32(0X8 << 16);
    // 0x8078A320: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8078A324: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8078A328: ori         $t4, $t4, 0xAC80
    ctx->r12 = ctx->r12 | 0XAC80;
    // 0x8078A32C: ori         $t3, $t3, 0x18
    ctx->r11 = ctx->r11 | 0X18;
    // 0x8078A330: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8078A334: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8078A338: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8078A33C: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x8078A340: lui         $a3, 0x55
    ctx->r7 = S32(0X55 << 16);
    // 0x8078A344: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8078A348: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8078A34C: ori         $a3, $a3, 0x3048
    ctx->r7 = ctx->r7 | 0X3048;
    // 0x8078A350: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x8078A354: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8078A358: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x8078A35C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8078A360: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8078A364: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x8078A368: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8078A36C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8078A370: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x8078A374: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8078A378: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8078A37C: addiu       $t1, $zero, 0x2204
    ctx->r9 = ADD32(0, 0X2204);
    // 0x8078A380: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x8078A384: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8078A388: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8078A38C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8078A390: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8078A394: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8078A398: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8078A39C: lui         $t3, 0xBB00
    ctx->r11 = S32(0XBB00 << 16);
    // 0x8078A3A0: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8078A3A4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8078A3A8: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x8078A3AC: ori         $t4, $t4, 0x8000
    ctx->r12 = ctx->r12 | 0X8000;
    // 0x8078A3B0: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8078A3B4: jr          $ra
    // 0x8078A3B8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    return;
    // 0x8078A3B8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
;}
RECOMP_FUNC void func_80024D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024D30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80024D34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80024D38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80024D3C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80024D40: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x80024D44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80024D48: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x80024D4C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80024D50: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x80024D54: lw          $t1, 0x1F4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1F4);
    // 0x80024D58: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80024D5C: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x80024D60: bne         $at, $zero, L_80024DF0
    if (ctx->r1 != 0) {
        // 0x80024D64: sw          $t7, 0x154($a0)
        MEM_W(0X154, ctx->r4) = ctx->r15;
            goto L_80024DF0;
    }
    // 0x80024D64: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x80024D68: lw          $v0, 0x154($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X154);
    // 0x80024D6C: lw          $a1, 0x14C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X14C);
    // 0x80024D70: addiu       $a0, $a0, 0x154
    ctx->r4 = ADD32(ctx->r4, 0X154);
    // 0x80024D74: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80024D78: bne         $at, $zero, L_80024D98
    if (ctx->r1 != 0) {
        // 0x80024D7C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80024D98;
    }
    // 0x80024D7C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80024D80:
    // 0x80024D80: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x80024D84: sltu        $at, $t9, $v1
    ctx->r1 = ctx->r25 < ctx->r3 ? 1 : 0;
    // 0x80024D88: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80024D8C: beq         $at, $zero, L_80024D80
    if (ctx->r1 == 0) {
        // 0x80024D90: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_80024D80;
    }
    // 0x80024D90: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80024D94: lw          $t0, 0x15C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X15C);
L_80024D98:
    // 0x80024D98: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80024D9C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80024DA0: sltu        $at, $a1, $t2
    ctx->r1 = ctx->r5 < ctx->r10 ? 1 : 0;
    // 0x80024DA4: bne         $at, $zero, L_80024DB4
    if (ctx->r1 != 0) {
        // 0x80024DA8: nop
    
            goto L_80024DB4;
    }
    // 0x80024DA8: nop

    // 0x80024DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80024DB0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_80024DB4:
    // 0x80024DB4: beq         $a1, $a3, L_80024DC8
    if (ctx->r5 == ctx->r7) {
        // 0x80024DB8: sw          $a1, 0x14C($s0)
        MEM_W(0X14C, ctx->r16) = ctx->r5;
            goto L_80024DC8;
    }
    // 0x80024DB8: sw          $a1, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r5;
    // 0x80024DBC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80024DC0: bnel        $a1, $t4, L_80024DF4
    if (ctx->r5 != ctx->r12) {
        // 0x80024DC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80024DF4;
    }
    goto skip_0;
    // 0x80024DC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80024DC8:
    // 0x80024DC8: jal         0x8001D770
    // 0x80024DCC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    func_8001D770(rdram, ctx);
        goto after_0;
    // 0x80024DCC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_0:
    // 0x80024DD0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80024DD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80024DD8: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80024DDC: jal         0x80067ED8
    // 0x80024DE0: lbu         $a1, 0xDE($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0XDE);
    func_80067ED8(rdram, ctx);
        goto after_1;
    // 0x80024DE0: lbu         $a1, 0xDE($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0XDE);
    after_1:
    // 0x80024DE4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80024DE8: jal         0x80067818
    // 0x80024DEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80024DEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_80024DF0:
    // 0x80024DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80024DF4:
    // 0x80024DF4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80024DF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80024DFC: jr          $ra
    // 0x80024E00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80024E00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80568B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568B4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80568B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80568B54: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80568B58: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80568B5C: addiu       $at, $zero, 0x4153
    ctx->r1 = ADD32(0, 0X4153);
    // 0x80568B60: beq         $v0, $at, L_80568B84
    if (ctx->r2 == ctx->r1) {
        // 0x80568B64: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80568B84;
    }
    // 0x80568B64: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80568B68: addiu       $at, $zero, 0x415F
    ctx->r1 = ADD32(0, 0X415F);
    // 0x80568B6C: beq         $v0, $at, L_80568B94
    if (ctx->r2 == ctx->r1) {
        // 0x80568B70: addiu       $at, $zero, 0x416B
        ctx->r1 = ADD32(0, 0X416B);
            goto L_80568B94;
    }
    // 0x80568B70: addiu       $at, $zero, 0x416B
    ctx->r1 = ADD32(0, 0X416B);
    // 0x80568B74: beql        $v0, $at, L_80568BA8
    if (ctx->r2 == ctx->r1) {
        // 0x80568B78: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80568BA8;
    }
    goto skip_0;
    // 0x80568B78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80568B7C: b           L_80568BB4
    // 0x80568B80: nop

        goto L_80568BB4;
    // 0x80568B80: nop

L_80568B84:
    // 0x80568B84: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80568B88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80568B8C: b           L_80568BB4
    // 0x80568B90: swc1        $f4, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f4.u32l;
        goto L_80568BB4;
    // 0x80568B90: swc1        $f4, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f4.u32l;
L_80568B94:
    // 0x80568B94: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21E4) << 16);
    // 0x80568B98: lwc1        $f6, -0x686C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21E4));
    // 0x80568B9C: b           L_80568BB4
    // 0x80568BA0: swc1        $f6, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
        goto L_80568BB4;
    // 0x80568BA0: swc1        $f6, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
    // 0x80568BA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80568BA8:
    // 0x80568BA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80568BAC: nop

    // 0x80568BB0: swc1        $f8, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f8.u32l;
L_80568BB4:
    // 0x80568BB4: jal         0x80568710
    // 0x80568BB8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x80568BB8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80568BBC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80568BC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80568BC4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80568BC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80568BCC: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21E8) << 16);
    // 0x80568BD0: sw          $zero, 0x24($a2)
    MEM_W(0X24, ctx->r6) = 0;
    // 0x80568BD4: swc1        $f10, 0xC8($a2)
    MEM_W(0XC8, ctx->r6) = ctx->f10.u32l;
    // 0x80568BD8: swc1        $f16, 0xE0($a2)
    MEM_W(0XE0, ctx->r6) = ctx->f16.u32l;
    // 0x80568BDC: lwc1        $f18, -0x6868($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21E8));
    // 0x80568BE0: lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F4);
    // 0x80568BE4: lwc1        $f4, 0x40($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X40);
    // 0x80568BE8: swc1        $f18, 0xEC($a2)
    MEM_W(0XEC, ctx->r6) = ctx->f18.u32l;
    // 0x80568BEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80568BF0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80568BF4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    // 0x80568BF8: jal         0x80048F84
    // 0x80568BFC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80568BFC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80568C00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80568C04: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80568C08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80568C0C: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80568C10: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80568C14: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80568C18: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80568C1C: jal         0x80569310
    // 0x80568C20: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    func_80569310(rdram, ctx);
        goto after_2;
    // 0x80568C20: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    after_2:
    // 0x80568C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80568C28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80568C2C: jr          $ra
    // 0x80568C30: nop

    return;
    // 0x80568C30: nop

;}
RECOMP_FUNC void func_8005D078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D078: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005D07C: lui         $at, 0xC460
    ctx->r1 = S32(0XC460 << 16);
    // 0x8005D080: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005D084: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D088: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005D08C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8005D090: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8005D094: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8005D098: lui         $a3, 0x4294
    ctx->r7 = S32(0X4294 << 16);
    // 0x8005D09C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005D0A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005D0A4: jal         0x8005CEBC
    // 0x8005D0A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_0;
    // 0x8005D0A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8005D0AC: beq         $v0, $zero, L_8005D0FC
    if (ctx->r2 == 0) {
        // 0x8005D0B0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8005D0FC;
    }
    // 0x8005D0B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005D0B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8005D0B8: jal         0x8005D134
    // 0x8005D0BC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8005D134(rdram, ctx);
        goto after_1;
    // 0x8005D0BC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8005D0C0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8005D0C4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8005D0C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005D0CC: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8005D0D0: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x8005D0D4: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8005D0D8: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8005D0DC: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
    // 0x8005D0E0: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8005D0E4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8005D0E8: swc1        $f18, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f18.u32l;
    // 0x8005D0EC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8005D0F0: sb          $t6, 0x31($a0)
    MEM_B(0X31, ctx->r4) = ctx->r14;
    // 0x8005D0F4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005D0F8: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
L_8005D0FC:
    // 0x8005D0FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D100: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005D104: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8005D108: jr          $ra
    // 0x8005D10C: nop

    return;
    // 0x8005D10C: nop

;}
RECOMP_FUNC void func_80564744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80564744: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80564748: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8056474C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80564750: lw          $v1, 0x2EC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2EC);
    // 0x80564754: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80564758: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8056475C: sll         $t8, $v1, 5
    ctx->r24 = S32(ctx->r3 << 5);
    // 0x80564760: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x80564764: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80564768: addu        $a3, $v0, $t8
    ctx->r7 = ADD32(ctx->r2, ctx->r24);
    // 0x8056476C: addiu       $a3, $a3, 0x174
    ctx->r7 = ADD32(ctx->r7, 0X174);
    // 0x80564770: sllv        $a1, $t6, $v1
    ctx->r5 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x80564774: sllv        $a2, $t7, $v1
    ctx->r6 = S32(ctx->r15 << (ctx->r3 & 31));
    // 0x80564778: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8056477C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80564780: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x80564784: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80564788: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x8056478C: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_80564790:
    // 0x80564790: lwc1        $f4, 0x3E8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X3E8);
    // 0x80564794: lwc1        $f6, 0x2F0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X2F0);
    // 0x80564798: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x8056479C: slti        $at, $t1, 0x3E
    ctx->r1 = SIGNED(ctx->r9) < 0X3E ? 1 : 0;
    // 0x805647A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805647A4: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x805647A8: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x805647AC: addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // 0x805647B0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x805647B4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x805647B8: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x805647BC: nop

    // 0x805647C0: sh          $t5, -0x4($t2)
    MEM_H(-0X4, ctx->r10) = ctx->r13;
    // 0x805647C4: lwc1        $f4, 0x2EC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X2EC);
    // 0x805647C8: lwc1        $f18, 0x3E4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X3E4);
    // 0x805647CC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x805647D0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x805647D4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x805647D8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x805647DC: bne         $at, $zero, L_80564790
    if (ctx->r1 != 0) {
        // 0x805647E0: sh          $t7, -0x2($t2)
        MEM_H(-0X2, ctx->r10) = ctx->r15;
            goto L_80564790;
    }
    // 0x805647E0: sh          $t7, -0x2($t2)
    MEM_H(-0X2, ctx->r10) = ctx->r15;
    // 0x805647E4: addiu       $v1, $v0, 0x4E0
    ctx->r3 = ADD32(ctx->r2, 0X4E0);
    // 0x805647E8: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x805647EC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x805647F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_805647F4:
    // 0x805647F4: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x805647F8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x805647FC: slti        $at, $t1, 0x1F
    ctx->r1 = SIGNED(ctx->r9) < 0X1F ? 1 : 0;
    // 0x80564800: or          $t9, $t8, $a0
    ctx->r25 = ctx->r24 | ctx->r4;
    // 0x80564804: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80564808: bne         $at, $zero, L_805647F4
    if (ctx->r1 != 0) {
        // 0x8056480C: sb          $t9, -0x1($t2)
        MEM_B(-0X1, ctx->r10) = ctx->r25;
            goto L_805647F4;
    }
    // 0x8056480C: sb          $t9, -0x1($t2)
    MEM_B(-0X1, ctx->r10) = ctx->r25;
    // 0x80564810: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80564814: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80564818: sltiu       $v0, $a2, 0x1
    ctx->r2 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x8056481C: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x80564820: addiu       $t3, $zero, 0x1D
    ctx->r11 = ADD32(0, 0X1D);
L_80564824:
    // 0x80564824: lbu         $t5, 0x0($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X0);
    // 0x80564828: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8056482C: and         $t6, $t5, $v0
    ctx->r14 = ctx->r13 & ctx->r2;
    // 0x80564830: beql        $t6, $zero, L_805648A8
    if (ctx->r14 == 0) {
        // 0x80564834: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_805648A8;
    }
    goto skip_0;
    // 0x80564834: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_0:
    // 0x80564838: lbu         $a2, 0x1($t2)
    ctx->r6 = MEM_BU(ctx->r10, 0X1);
    // 0x8056483C: and         $t7, $a2, $v0
    ctx->r15 = ctx->r6 & ctx->r2;
    // 0x80564840: beql        $t7, $zero, L_805648A8
    if (ctx->r15 == 0) {
        // 0x80564844: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_805648A8;
    }
    goto skip_1;
    // 0x80564844: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_1:
    // 0x80564848: lbu         $t8, 0x2($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X2);
    // 0x8056484C: sll         $t5, $t0, 1
    ctx->r13 = S32(ctx->r8 << 1);
    // 0x80564850: addu        $v1, $a3, $t5
    ctx->r3 = ADD32(ctx->r7, ctx->r13);
    // 0x80564854: and         $t9, $t8, $v0
    ctx->r25 = ctx->r24 & ctx->r2;
    // 0x80564858: beql        $t9, $zero, L_805648A8
    if (ctx->r25 == 0) {
        // 0x8056485C: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_805648A8;
    }
    goto skip_2;
    // 0x8056485C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_2:
    // 0x80564860: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x80564864: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80564868: bnel        $t6, $a1, L_805648A8
    if (ctx->r14 != ctx->r5) {
        // 0x8056486C: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_805648A8;
    }
    goto skip_3;
    // 0x8056486C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_3:
    // 0x80564870: lh          $t7, 0x8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X8);
    // 0x80564874: bnel        $a1, $t7, L_805648A8
    if (ctx->r5 != ctx->r15) {
        // 0x80564878: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_805648A8;
    }
    goto skip_4;
    // 0x80564878: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_4:
    // 0x8056487C: lh          $a1, 0x6($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X6);
    // 0x80564880: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80564884: bnel        $t8, $a1, L_805648A8
    if (ctx->r24 != ctx->r5) {
        // 0x80564888: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_805648A8;
    }
    goto skip_5;
    // 0x80564888: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_5:
    // 0x8056488C: lh          $t9, 0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XA);
    // 0x80564890: xori        $t5, $a0, 0xFF
    ctx->r13 = ctx->r4 ^ 0XFF;
    // 0x80564894: and         $t6, $a2, $t5
    ctx->r14 = ctx->r6 & ctx->r13;
    // 0x80564898: bnel        $a1, $t9, L_805648A8
    if (ctx->r5 != ctx->r25) {
        // 0x8056489C: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_805648A8;
    }
    goto skip_6;
    // 0x8056489C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_6:
    // 0x805648A0: sb          $t6, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r14;
    // 0x805648A4: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_805648A8:
    // 0x805648A8: bne         $t1, $t3, L_80564824
    if (ctx->r9 != ctx->r11) {
        // 0x805648AC: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_80564824;
    }
    // 0x805648AC: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x805648B0: jr          $ra
    // 0x805648B4: nop

    return;
    // 0x805648B4: nop

;}
RECOMP_FUNC void func_80462734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80462738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046273C: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x80462740: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(122, 0X3880) << 16);
    // 0x80462744: addiu       $t8, $t8, 0x3E10
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(122, 0X3880));
    // 0x80462748: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8046274C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80462750: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80462754: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80462758: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8046275C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80462760: beql        $v1, $zero, L_80462798
    if (ctx->r3 == 0) {
        // 0x80462764: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80462798;
    }
    goto skip_0;
    // 0x80462764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80462768: jalr        $v1
    // 0x8046276C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8046276C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80462770: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80462774: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x80462778: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x8046277C: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x80462780: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80462784: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x80462788: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8046278C: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80462790: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x80462794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80462798:
    // 0x80462798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046279C: jr          $ra
    // 0x804627A0: nop

    return;
    // 0x804627A0: nop

;}
RECOMP_FUNC void func_80474D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474D30: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474D34: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474D38: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474D3C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474D40: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474D44: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474D48: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474D4C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474D50: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474D54: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474D58: jr          $ra
    // 0x80474D5C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474D5C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8046B338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046B338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046B33C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046B340: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8046B344: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8046B348: lui         $t8, 0x8047
    ctx->r24 = S32(RELOC_HI16(138, 0X28F0) << 16);
    // 0x8046B34C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8046B350: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8046B354: lw          $t8, -0x3FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(138, 0X28F0));
    // 0x8046B358: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8046B35C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8046B360: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8046B364: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8046B368: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8046B36C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8046B370: beql        $v1, $zero, L_8046B3A4
    if (ctx->r3 == 0) {
        // 0x8046B374: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8046B3A4;
    }
    goto skip_0;
    // 0x8046B374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8046B378: jalr        $v1
    // 0x8046B37C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8046B37C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046B380: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046B384: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8046B388: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8046B38C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8046B390: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8046B394: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8046B398: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8046B39C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8046B3A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046B3A4:
    // 0x8046B3A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046B3A8: jr          $ra
    // 0x8046B3AC: nop

    return;
    // 0x8046B3AC: nop

;}
RECOMP_FUNC void func_80060624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060624: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80060628: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006062C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060630: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80060634: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    // 0x80060638: jal         0x8005FF38
    // 0x8006063C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_8005FF38(rdram, ctx);
        goto after_0;
    // 0x8006063C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80060640: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80060644: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80060648: jal         0x80065954
    // 0x8006064C: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8006064C: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    after_1:
    // 0x80060650: lwc1        $f2, 0x30($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80060654: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80060658: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006065C: bc1f        L_80060780
    if (!c1cs) {
        // 0x80060660: swc1        $f6, 0x64($s0)
        MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
            goto L_80060780;
    }
    // 0x80060660: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
    // 0x80060664: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
    // 0x80060668: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8006066C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80060670: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060674: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x80060678: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x8006067C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80060680: lwc1        $f8, 0x4($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80060684: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80060688: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8006068C: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    // 0x80060690: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060694: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80060698: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8006069C: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x800606A0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800606A4: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800606A8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800606AC: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800606B0: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800606B4: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800606B8: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800606BC: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800606C0: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800606C4: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x800606C8: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800606CC: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800606D0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800606D4: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800606D8: bc1f        L_80060780
    if (!c1cs) {
        // 0x800606DC: swc1        $f16, 0x68($s0)
        MEM_W(0X68, ctx->r16) = ctx->f16.u32l;
            goto L_80060780;
    }
    // 0x800606DC: swc1        $f16, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f16.u32l;
    // 0x800606E0: lwc1        $f18, 0x68($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800606E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800606E8: nop

    // 0x800606EC: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800606F0: nop

    // 0x800606F4: bc1fl       L_80060784
    if (!c1cs) {
        // 0x800606F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80060784;
    }
    goto skip_0;
    // 0x800606F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800606FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060700: lh          $t1, 0xE($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XE);
    // 0x80060704: lw          $t0, 0x70($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X70);
    // 0x80060708: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8006070C: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80060710: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80060714: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80060718: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x8006071C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060720: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80060724: lh          $t3, 0x8($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X8);
    // 0x80060728: lw          $t2, 0x70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X70);
    // 0x8006072C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80060730: lwc1        $f18, 0x8($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80060734: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80060738: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8006073C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80060740: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80060744: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
    // 0x80060748: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8006074C: jal         0x80065954
    // 0x80060750: sub.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f18.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x80060750: sub.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f18.fl;
    after_2:
    // 0x80060754: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80060758: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8006075C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060760: add.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80060764: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80060768: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006076C: bc1f        L_80060784
    if (!c1cs) {
        // 0x80060770: swc1        $f8, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
            goto L_80060784;
    }
    // 0x80060770: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    // 0x80060774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060778: b           L_80060788
    // 0x8006077C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80060788;
    // 0x8006077C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80060780:
    // 0x80060780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060784:
    // 0x80060784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80060788:
    // 0x80060788: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006078C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80060790: jr          $ra
    // 0x80060794: nop

    return;
    // 0x80060794: nop

;}
RECOMP_FUNC void func_8046B134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046B134: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8046B138: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046B13C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046B140: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8046B144: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8046B148: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046B14C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8046B150: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8046B154: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8046B158: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8046B15C: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2998) << 16);
    // 0x8046B160: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8046B164: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8046B168: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8046B16C: jal         0x80082730
    // 0x8046B170: lwc1        $f12, -0x3F28($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2998));
    fsin(rdram, ctx);
        goto after_0;
    // 0x8046B170: lwc1        $f12, -0x3F28($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2998));
    after_0:
    // 0x8046B174: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8046B178: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x8046B17C: sb          $zero, 0x64($s0)
    MEM_B(0X64, ctx->r16) = 0;
    // 0x8046B180: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8046B184: jal         0x80469834
    // 0x8046B188: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80469834(rdram, ctx);
        goto after_1;
    // 0x8046B188: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8046B18C: jal         0x8046A4A4
    // 0x8046B190: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8046A4A4(rdram, ctx);
        goto after_2;
    // 0x8046B190: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8046B194: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8046B198: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8046B19C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8046B1A0: jal         0x80469D08
    // 0x8046B1A4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80469D08(rdram, ctx);
        goto after_3;
    // 0x8046B1A4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x8046B1A8: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8046B1AC: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8046B1B0: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8046B1B4: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8046B1B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8046B1BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046B1C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8046B1C4: jr          $ra
    // 0x8046B1C8: nop

    return;
    // 0x8046B1C8: nop

;}
RECOMP_FUNC void func_8044BA64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BA64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044BA68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044BA6C: jal         0x8044B740
    // 0x8044BA70: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8044B740(rdram, ctx);
        goto after_0;
    // 0x8044BA70: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x8044BA74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044BA78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044BA7C: jr          $ra
    // 0x8044BA80: nop

    return;
    // 0x8044BA80: nop

;}
RECOMP_FUNC void func_8041EFD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041EFD4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8041EFD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041EFDC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8041EFE0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8041EFE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041EFE8: jal         0x8041DB1C
    // 0x8041EFEC: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_8041DB1C(rdram, ctx);
        goto after_0;
    // 0x8041EFEC: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8041EFF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EFF4: jal         0x8041E9A8
    // 0x8041EFF8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E9A8(rdram, ctx);
        goto after_1;
    // 0x8041EFF8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8041EFFC: beql        $v0, $zero, L_8041F120
    if (ctx->r2 == 0) {
        // 0x8041F000: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041F120;
    }
    goto skip_0;
    // 0x8041F000: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8041F004: lh          $v0, 0x2E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2E);
    // 0x8041F008: beq         $v0, $zero, L_8041F0C4
    if (ctx->r2 == 0) {
        // 0x8041F00C: nop
    
            goto L_8041F0C4;
    }
    // 0x8041F00C: nop

    // 0x8041F010: lh          $t7, 0x30($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X30);
    // 0x8041F014: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8041F018: sh          $t6, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r14;
    // 0x8041F01C: beq         $t7, $zero, L_8041F0FC
    if (ctx->r15 == 0) {
        // 0x8041F020: nop
    
            goto L_8041F0FC;
    }
    // 0x8041F020: nop

    // 0x8041F024: lh          $v0, 0x32($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X32);
    // 0x8041F028: beq         $v0, $zero, L_8041F038
    if (ctx->r2 == 0) {
        // 0x8041F02C: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8041F038;
    }
    // 0x8041F02C: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8041F030: b           L_8041F0FC
    // 0x8041F034: sh          $t8, 0x32($s1)
    MEM_H(0X32, ctx->r17) = ctx->r24;
        goto L_8041F0FC;
    // 0x8041F034: sh          $t8, 0x32($s1)
    MEM_H(0X32, ctx->r17) = ctx->r24;
L_8041F038:
    // 0x8041F038: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8041F03C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8041F040: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8041F044: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8041F048: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8041F04C: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8041F050: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3520) << 16);
    // 0x8041F054: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8041F058: lwc1        $f6, 0xB80($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3520));
    // 0x8041F05C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8041F060: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x8041F064: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8041F068: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    // 0x8041F06C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8041F070: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8041F074: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8041F078: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8041F07C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x8041F080: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8041F084: lw          $t9, 0x80($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X80);
    // 0x8041F088: jalr        $t9
    // 0x8041F08C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8041F08C: nop

    after_2:
    // 0x8041F090: lh          $t2, 0x30($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X30);
    // 0x8041F094: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8041F098: sh          $t1, 0x32($s1)
    MEM_H(0X32, ctx->r17) = ctx->r9;
    // 0x8041F09C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8041F0A0: sh          $t3, 0x30($s1)
    MEM_H(0X30, ctx->r17) = ctx->r11;
    // 0x8041F0A4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x8041F0A8: jal         0x80067BBC
    // 0x8041F0AC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8041F0AC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x8041F0B0: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    // 0x8041F0B4: jal         0x80067818
    // 0x8041F0B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8041F0B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8041F0BC: b           L_8041F0FC
    // 0x8041F0C0: nop

        goto L_8041F0FC;
    // 0x8041F0C0: nop

L_8041F0C4:
    // 0x8041F0C4: jal         0x800653D8
    // 0x8041F0C8: nop

    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x8041F0C8: nop

    after_5:
    // 0x8041F0CC: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x8041F0D0: andi        $t5, $t4, 0x7F
    ctx->r13 = ctx->r12 & 0X7F;
    // 0x8041F0D4: addiu       $t6, $t5, 0x3C
    ctx->r14 = ADD32(ctx->r13, 0X3C);
    // 0x8041F0D8: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8041F0DC: sh          $t6, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r14;
    // 0x8041F0E0: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x8041F0E4: sw          $t7, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r15;
    // 0x8041F0E8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8041F0EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F0F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041F0F4: jal         0x8041FE10
    // 0x8041F0F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8041FE10(rdram, ctx);
        goto after_6;
    // 0x8041F0F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
L_8041F0FC:
    // 0x8041F0FC: jal         0x8041E5E8
    // 0x8041F100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041E5E8(rdram, ctx);
        goto after_7;
    // 0x8041F100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8041F104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F108: jal         0x8041E430
    // 0x8041F10C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E430(rdram, ctx);
        goto after_8;
    // 0x8041F10C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x8041F110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F114: jal         0x8041E7D4
    // 0x8041F118: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E7D4(rdram, ctx);
        goto after_9;
    // 0x8041F118: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x8041F11C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041F120:
    // 0x8041F120: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8041F124: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8041F128: jr          $ra
    // 0x8041F12C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8041F12C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_807607EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807607EC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807607F0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x807607F4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x807607F8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x807607FC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80760800: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80760804: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80760808: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8076080C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80760810: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80760814: jr          $ra
    // 0x80760818: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80760818: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8073A024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073A024: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8073A028: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x8073A02C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8073A030: sdc1        $f30, 0x30($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X30, ctx->r29);
    // 0x8073A034: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8073A038: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8073A03C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8073A040: sdc1        $f28, 0x28($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X28, ctx->r29);
    // 0x8073A044: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x8073A048: sdc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X20, ctx->r29);
    // 0x8073A04C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8073A050: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x8073A054: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x8073A058: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8073A05C: lui         $at, 0xC2D8
    ctx->r1 = S32(0XC2D8 << 16);
    // 0x8073A060: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8073A064: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8073A068: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8073A06C: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x8073A070: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8073A074: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8073A078: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8073A07C: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x8073A080: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_8073A084:
    // 0x8073A084: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8073A088: mov.s       $f18, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    ctx->f18.fl = ctx->f26.fl;
    // 0x8073A08C: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8073A090: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
    // 0x8073A094: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8073A098: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8073A09C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8073A0A0: trunc.w.s   $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    ctx->f8.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8073A0A4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8073A0A8: mov.s       $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    ctx->f22.fl = ctx->f26.fl;
    // 0x8073A0AC: mov.s       $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    ctx->f24.fl = ctx->f16.fl;
    // 0x8073A0B0: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8073A0B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8073A0B8: sll         $t0, $t0, 6
    ctx->r8 = S32(ctx->r8 << 6);
    // 0x8073A0BC: sll         $t2, $t2, 6
    ctx->r10 = S32(ctx->r10 << 6);
L_8073A0C0:
    // 0x8073A0C0: trunc.w.s   $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8073A0C4: sh          $a3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r7;
    // 0x8073A0C8: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x8073A0CC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8073A0D0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8073A0D4: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x8073A0D8: sh          $t0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r8;
    // 0x8073A0DC: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8073A0E0: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x8073A0E4: sh          $t8, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r24;
    // 0x8073A0E8: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
    // 0x8073A0EC: sb          $zero, 0xD($v1)
    MEM_B(0XD, ctx->r3) = 0;
    // 0x8073A0F0: sb          $zero, 0xE($v1)
    MEM_B(0XE, ctx->r3) = 0;
    // 0x8073A0F4: sb          $zero, 0xF($v1)
    MEM_B(0XF, ctx->r3) = 0;
    // 0x8073A0F8: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    // 0x8073A0FC: trunc.w.s   $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    ctx->f10.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x8073A100: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8073A104: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8073A108: trunc.w.s   $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    ctx->f8.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x8073A10C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8073A110: sb          $zero, 0xF($a1)
    MEM_B(0XF, ctx->r5) = 0;
    // 0x8073A114: add.s       $f18, $f18, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f28.fl;
    // 0x8073A118: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8073A11C: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x8073A120: add.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
    // 0x8073A124: sh          $t7, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r15;
    // 0x8073A128: sb          $zero, 0xE($a1)
    MEM_B(0XE, ctx->r5) = 0;
    // 0x8073A12C: sb          $zero, 0xD($a1)
    MEM_B(0XD, ctx->r5) = 0;
    // 0x8073A130: sb          $zero, 0xC($a1)
    MEM_B(0XC, ctx->r5) = 0;
    // 0x8073A134: sh          $t2, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r10;
    // 0x8073A138: sh          $zero, 0x6($a1)
    MEM_H(0X6, ctx->r5) = 0;
    // 0x8073A13C: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x8073A140: sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
    // 0x8073A144: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8073A148: add.s       $f22, $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f28.fl;
    // 0x8073A14C: sh          $t4, -0x10($a1)
    MEM_H(-0X10, ctx->r5) = ctx->r12;
    // 0x8073A150: bne         $a0, $t3, L_8073A0C0
    if (ctx->r4 != ctx->r11) {
        // 0x8073A154: add.s       $f24, $f24, $f28
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f28.fl;
            goto L_8073A0C0;
    }
    // 0x8073A154: add.s       $f24, $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f28.fl;
    // 0x8073A158: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8073A15C: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8073A160: add.s       $f0, $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f30.fl;
    // 0x8073A164: add.s       $f2, $f2, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f30.fl;
    // 0x8073A168: add.s       $f12, $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f30.fl;
    // 0x8073A16C: bne         $at, $zero, L_8073A084
    if (ctx->r1 != 0) {
        // 0x8073A170: add.s       $f14, $f14, $f30
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f30.fl;
            goto L_8073A084;
    }
    // 0x8073A170: add.s       $f14, $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f30.fl;
    // 0x8073A174: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x8073A178: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x8073A17C: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x8073A180: ldc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X20);
    // 0x8073A184: ldc1        $f28, 0x28($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X28);
    // 0x8073A188: ldc1        $f30, 0x30($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X30);
    // 0x8073A18C: jr          $ra
    // 0x8073A190: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8073A190: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_806F2364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F2368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F236C: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x806F2370: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(679, 0X1AF0) << 16);
    // 0x806F2374: addiu       $t8, $t8, 0x3070
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(679, 0X1AF0));
    // 0x806F2378: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806F237C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x806F2380: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806F2384: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x806F2388: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x806F238C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x806F2390: beql        $v1, $zero, L_806F23C8
    if (ctx->r3 == 0) {
        // 0x806F2394: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F23C8;
    }
    goto skip_0;
    // 0x806F2394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806F2398: jalr        $v1
    // 0x806F239C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x806F239C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F23A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F23A4: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x806F23A8: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x806F23AC: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x806F23B0: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x806F23B4: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x806F23B8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x806F23BC: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x806F23C0: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x806F23C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F23C8:
    // 0x806F23C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F23CC: jr          $ra
    // 0x806F23D0: nop

    return;
    // 0x806F23D0: nop

;}
RECOMP_FUNC void func_80776CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80776CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80776CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80776CE4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80776CE8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80776CEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80776CF0: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80776CF4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80776CF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80776CFC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80776D00: nop

    // 0x80776D04: bc1fl       L_80776D24
    if (!c1cs) {
        // 0x80776D08: lwc1        $f2, 0x8($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
            goto L_80776D24;
    }
    goto skip_0;
    // 0x80776D08: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x80776D0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80776D10: nop

    // 0x80776D14: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80776D18: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80776D1C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80776D20: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
L_80776D24:
    // 0x80776D24: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80776D28: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80776D2C: nop

    // 0x80776D30: bc1fl       L_80776D4C
    if (!c1cs) {
        // 0x80776D34: lw          $t6, 0x1E0($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X1E0);
            goto L_80776D4C;
    }
    goto skip_1;
    // 0x80776D34: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    skip_1:
    // 0x80776D38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80776D3C: nop

    // 0x80776D40: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80776D44: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x80776D48: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
L_80776D4C:
    // 0x80776D4C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80776D50: slti        $at, $t7, 0x78
    ctx->r1 = SIGNED(ctx->r15) < 0X78 ? 1 : 0;
    // 0x80776D54: bne         $at, $zero, L_80776D88
    if (ctx->r1 != 0) {
        // 0x80776D58: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_80776D88;
    }
    // 0x80776D58: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x80776D5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80776D60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80776D64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80776D68: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80776D6C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80776D70: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80776D74: jal         0x8077725C
    // 0x80776D78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8077725C(rdram, ctx);
        goto after_0;
    // 0x80776D78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80776D7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80776D80: jal         0x80776CA4
    // 0x80776D84: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    func_80776CA4(rdram, ctx);
        goto after_1;
    // 0x80776D84: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    after_1:
L_80776D88:
    // 0x80776D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80776D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80776D90: jr          $ra
    // 0x80776D94: nop

    return;
    // 0x80776D94: nop

;}
RECOMP_FUNC void func_80455BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455BD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80455BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80455BD8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80455BDC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455BE0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80455BE4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455BE8: sw          $t6, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r14;
    // 0x80455BEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80455BF0: jal         0x8044EFA0
    // 0x80455BF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x80455BF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80455BF8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80455BFC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455C00: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x80455C04: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455C08: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    // 0x80455C0C: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13D78) << 16);
    // 0x80455C10: lw          $t9, -0x7EA8($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13D78));
    // 0x80455C14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80455C18: jalr        $t9
    // 0x80455C1C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80455C1C: nop

    after_1:
    // 0x80455C20: jal         0x804559B4
    // 0x80455C24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_804559B4(rdram, ctx);
        goto after_2;
    // 0x80455C24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80455C28: jal         0x80445CBC
    // 0x80455C2C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_80445CBC(rdram, ctx);
        goto after_3;
    // 0x80455C2C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x80455C30: jal         0x80445CC4
    // 0x80455C34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445CC4(rdram, ctx);
        goto after_4;
    // 0x80455C34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80455C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80455C3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80455C40: jr          $ra
    // 0x80455C44: nop

    return;
    // 0x80455C44: nop

;}
RECOMP_FUNC void func_8073E984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073E984: jr          $ra
    // 0x8073E988: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8073E988: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_807B02C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B02C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B02C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B02C8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x807B02CC: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x807B02D0: lui         $t8, 0x807B
    ctx->r24 = S32(RELOC_HI16(871, 0X3674) << 16);
    // 0x807B02D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807B02D8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x807B02DC: lw          $t8, 0x31C4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(871, 0X3674));
    // 0x807B02E0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x807B02E4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x807B02E8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x807B02EC: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x807B02F0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x807B02F4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x807B02F8: beql        $v1, $zero, L_807B032C
    if (ctx->r3 == 0) {
        // 0x807B02FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807B032C;
    }
    goto skip_0;
    // 0x807B02FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807B0300: jalr        $v1
    // 0x807B0304: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x807B0304: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807B0308: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807B030C: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x807B0310: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x807B0314: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x807B0318: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x807B031C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x807B0320: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x807B0324: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x807B0328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B032C:
    // 0x807B032C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B0330: jr          $ra
    // 0x807B0334: nop

    return;
    // 0x807B0334: nop

;}
RECOMP_FUNC void func_80427940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427940: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80427944: addiu       $at, $zero, 0x406E
    ctx->r1 = ADD32(0, 0X406E);
    // 0x80427948: beq         $v0, $at, L_80427968
    if (ctx->r2 == ctx->r1) {
        // 0x8042794C: addiu       $at, $zero, 0x41C4
        ctx->r1 = ADD32(0, 0X41C4);
            goto L_80427968;
    }
    // 0x8042794C: addiu       $at, $zero, 0x41C4
    ctx->r1 = ADD32(0, 0X41C4);
    // 0x80427950: beq         $v0, $at, L_80427974
    if (ctx->r2 == ctx->r1) {
        // 0x80427954: addiu       $at, $zero, 0x41C5
        ctx->r1 = ADD32(0, 0X41C5);
            goto L_80427974;
    }
    // 0x80427954: addiu       $at, $zero, 0x41C5
    ctx->r1 = ADD32(0, 0X41C5);
    // 0x80427958: beq         $v0, $at, L_80427980
    if (ctx->r2 == ctx->r1) {
        // 0x8042795C: nop
    
            goto L_80427980;
    }
    // 0x8042795C: nop

    // 0x80427960: b           L_8042798C
    // 0x80427964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8042798C;
    // 0x80427964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80427968:
    // 0x80427968: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(41, 0XE8C) << 16);
    // 0x8042796C: jr          $ra
    // 0x80427970: addiu       $v0, $v0, -0x7834
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(41, 0XE8C));
    return;
    // 0x80427970: addiu       $v0, $v0, -0x7834
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(41, 0XE8C));
L_80427974:
    // 0x80427974: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(41, 0X1764) << 16);
    // 0x80427978: jr          $ra
    // 0x8042797C: addiu       $v0, $v0, -0x6F5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(41, 0X1764));
    return;
    // 0x8042797C: addiu       $v0, $v0, -0x6F5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(41, 0X1764));
L_80427980:
    // 0x80427980: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(41, 0X1A50) << 16);
    // 0x80427984: jr          $ra
    // 0x80427988: addiu       $v0, $v0, -0x6C70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(41, 0X1A50));
    return;
    // 0x80427988: addiu       $v0, $v0, -0x6C70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(41, 0X1A50));
L_8042798C:
    // 0x8042798C: jr          $ra
    // 0x80427990: nop

    return;
    // 0x80427990: nop

;}
RECOMP_FUNC void func_8044DED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044DED0: jr          $ra
    // 0x8044DED4: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    return;
    // 0x8044DED4: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
;}
RECOMP_FUNC void func_80032BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032BA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032BA8: jal         0x80021958
    // 0x80032BAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80032BAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80032BB0: bne         $v0, $zero, L_80032BC0
    if (ctx->r2 != 0) {
        // 0x80032BB4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80032BC0;
    }
    // 0x80032BB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80032BB8: b           L_80032C04
    // 0x80032BBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80032C04;
    // 0x80032BBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80032BC0:
    // 0x80032BC0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80032BC4: lbu         $t7, 0xF4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XF4);
    // 0x80032BC8: bne         $t7, $zero, L_80032BE8
    if (ctx->r15 != 0) {
        // 0x80032BCC: nop
    
            goto L_80032BE8;
    }
    // 0x80032BCC: nop

    // 0x80032BD0: jal         0x80033FB0
    // 0x80032BD4: nop

    func_80033FB0(rdram, ctx);
        goto after_1;
    // 0x80032BD4: nop

    after_1:
    // 0x80032BD8: beq         $v0, $zero, L_80032BE8
    if (ctx->r2 == 0) {
        // 0x80032BDC: nop
    
            goto L_80032BE8;
    }
    // 0x80032BDC: nop

    // 0x80032BE0: b           L_80032C04
    // 0x80032BE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80032C04;
    // 0x80032BE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80032BE8:
    // 0x80032BE8: jal         0x800328C0
    // 0x80032BEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800328C0(rdram, ctx);
        goto after_2;
    // 0x80032BEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80032BF0: bnel        $v0, $zero, L_80032C04
    if (ctx->r2 != 0) {
        // 0x80032BF4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80032C04;
    }
    goto skip_0;
    // 0x80032BF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80032BF8: b           L_80032C04
    // 0x80032BFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80032C04;
    // 0x80032BFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80032C00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80032C04:
    // 0x80032C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032C08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032C0C: jr          $ra
    // 0x80032C10: nop

    return;
    // 0x80032C10: nop

;}
RECOMP_FUNC void func_804544DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804544DC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804544E0: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
    // 0x804544E4: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x804544E8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x804544EC: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x804544F0: jr          $ra
    // 0x804544F4: sw          $t6, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r14;
    return;
    // 0x804544F4: sw          $t6, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_80047648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047648: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8004764C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80047650: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80047654: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80047658: lw          $a3, 0x180($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X180);
    // 0x8004765C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80047660: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80047664: beq         $a3, $zero, L_8004767C
    if (ctx->r7 == 0) {
        // 0x80047668: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_8004767C;
    }
    // 0x80047668: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8004766C: lbu         $v0, 0x17C($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X17C);
    // 0x80047670: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80047674: bne         $v0, $at, L_80047740
    if (ctx->r2 != ctx->r1) {
        // 0x80047678: nop
    
            goto L_80047740;
    }
    // 0x80047678: nop

L_8004767C:
    // 0x8004767C: jal         0x80049018
    // 0x80047680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x80047680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80047684: beq         $v0, $zero, L_8004769C
    if (ctx->r2 == 0) {
        // 0x80047688: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004769C;
    }
    // 0x80047688: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004768C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80047690: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80047694: b           L_800476A8
    // 0x80047698: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
        goto L_800476A8;
    // 0x80047698: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
L_8004769C:
    // 0x8004769C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800476A0: nop

    // 0x800476A4: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
L_800476A8:
    // 0x800476A8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x800476AC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800476B0: mul.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800476B4: jal         0x80066E88
    // 0x800476B8: nop

    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x800476B8: nop

    after_1:
    // 0x800476BC: lwc1        $f8, 0x98($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X98);
    // 0x800476C0: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800476C4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800476C8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800476CC: mul.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800476D0: jal         0x80066DE4
    // 0x800476D4: nop

    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x800476D4: nop

    after_2:
    // 0x800476D8: lwc1        $f2, 0x54($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800476DC: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800476E0: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800476E4: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x800476E8: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800476EC: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800476F0: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800476F4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800476F8: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800476FC: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80047700: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80047704: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    // 0x80047708: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004770C: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047710: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80047714: neg.s       $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = -ctx->f16.fl;
    // 0x80047718: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004771C: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80047720: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
    // 0x80047724: mul.s       $f16, $f6, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80047728: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004772C: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80047730: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x80047734: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80047738: b           L_80047AA4
    // 0x8004773C: swc1        $f10, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f10.u32l;
        goto L_80047AA4;
    // 0x8004773C: swc1        $f10, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f10.u32l;
L_80047740:
    // 0x80047740: bne         $v0, $zero, L_80047830
    if (ctx->r2 != 0) {
        // 0x80047744: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80047830;
    }
    // 0x80047744: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80047748: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004774C: jal         0x80047648
    // 0x80047750: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80047648(rdram, ctx);
        goto after_3;
    // 0x80047750: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x80047754: jal         0x80049018
    // 0x80047758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80049018(rdram, ctx);
        goto after_4;
    // 0x80047758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8004775C: beq         $v0, $zero, L_80047774
    if (ctx->r2 == 0) {
        // 0x80047760: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80047774;
    }
    // 0x80047760: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80047764: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80047768: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004776C: b           L_80047780
    // 0x80047770: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
        goto L_80047780;
    // 0x80047770: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
L_80047774:
    // 0x80047774: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80047778: nop

    // 0x8004777C: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
L_80047780:
    // 0x80047780: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80047784: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80047788: mul.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004778C: jal         0x80066E88
    // 0x80047790: nop

    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x80047790: nop

    after_5:
    // 0x80047794: lwc1        $f16, 0x98($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80047798: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004779C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800477A0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800477A4: mul.s       $f12, $f18, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800477A8: jal         0x80066DE4
    // 0x800477AC: nop

    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x800477AC: nop

    after_6:
    // 0x800477B0: lwc1        $f2, 0x54($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800477B4: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800477B8: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800477BC: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x800477C0: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800477C4: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800477C8: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800477CC: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x800477D0: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800477D4: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800477D8: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800477DC: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800477E0: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800477E4: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    // 0x800477E8: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800477EC: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800477F0: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800477F4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800477F8: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800477FC: add.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80047800: neg.s       $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = -ctx->f12.fl;
    // 0x80047804: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80047808: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8004780C: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80047810: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80047814: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80047818: add.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8004781C: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80047820: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80047824: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80047828: b           L_80047AA4
    // 0x8004782C: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
        goto L_80047AA4;
    // 0x8004782C: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
L_80047830:
    // 0x80047830: beq         $v0, $at, L_80047840
    if (ctx->r2 == ctx->r1) {
        // 0x80047834: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80047840;
    }
    // 0x80047834: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80047838: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004783C: bne         $v0, $at, L_800479E4
    if (ctx->r2 != ctx->r1) {
        // 0x80047840: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_800479E4;
    }
L_80047840:
    // 0x80047840: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80047844: jal         0x80047648
    // 0x80047848: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_80047648(rdram, ctx);
        goto after_7;
    // 0x80047848: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_7:
    // 0x8004784C: lbu         $t6, 0x17C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X17C);
    // 0x80047850: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80047854: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80047858: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004785C: bne         $t6, $at, L_8004788C
    if (ctx->r14 != ctx->r1) {
        // 0x80047860: lw          $a2, 0x30($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X30);
            goto L_8004788C;
    }
    // 0x80047860: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80047864: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80047868: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8004786C: jal         0x80049018
    // 0x80047870: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_80049018(rdram, ctx);
        goto after_8;
    // 0x80047870: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_8:
    // 0x80047874: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80047878: beq         $v0, $zero, L_8004788C
    if (ctx->r2 == 0) {
        // 0x8004787C: lwc1        $f2, 0x34($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
            goto L_8004788C;
    }
    // 0x8004787C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80047880: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80047884: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80047888: nop

L_8004788C:
    // 0x8004788C: lwc1        $f16, 0x98($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X98);
    // 0x80047890: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80047894: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80047898: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x8004789C: mul.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800478A0: jal         0x80066E88
    // 0x800478A4: nop

    func_80066E88(rdram, ctx);
        goto after_9;
    // 0x800478A4: nop

    after_9:
    // 0x800478A8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800478AC: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800478B0: lwc1        $f10, 0x98($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X98);
    // 0x800478B4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800478B8: neg.s       $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = -ctx->f10.fl;
    // 0x800478BC: mul.s       $f12, $f8, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800478C0: jal         0x80066DE4
    // 0x800478C4: nop

    func_80066DE4(rdram, ctx);
        goto after_10;
    // 0x800478C4: nop

    after_10:
    // 0x800478C8: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800478CC: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800478D0: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800478D4: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800478D8: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800478DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800478E0: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800478E4: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800478E8: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800478EC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x800478F0: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800478F4: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800478F8: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800478FC: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80047900: nop

    // 0x80047904: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80047908: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8004790C: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80047910: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80047914: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80047918: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8004791C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80047920: jal         0x80049018
    // 0x80047924: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_80049018(rdram, ctx);
        goto after_11;
    // 0x80047924: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x80047928: beq         $v0, $zero, L_80047940
    if (ctx->r2 == 0) {
        // 0x8004792C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80047940;
    }
    // 0x8004792C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80047930: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80047934: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80047938: b           L_8004794C
    // 0x8004793C: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
        goto L_8004794C;
    // 0x8004793C: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
L_80047940:
    // 0x80047940: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80047944: nop

    // 0x80047948: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
L_8004794C:
    // 0x8004794C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80047950: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x80047954: mul.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80047958: jal         0x80066E88
    // 0x8004795C: nop

    func_80066E88(rdram, ctx);
        goto after_12;
    // 0x8004795C: nop

    after_12:
    // 0x80047960: lwc1        $f16, 0x98($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80047964: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80047968: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8004796C: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x80047970: mul.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80047974: jal         0x80066DE4
    // 0x80047978: nop

    func_80066DE4(rdram, ctx);
        goto after_13;
    // 0x80047978: nop

    after_13:
    // 0x8004797C: lwc1        $f2, 0x54($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80047980: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80047984: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80047988: neg.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = -ctx->f2.fl;
    // 0x8004798C: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80047990: mul.s       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x80047994: add.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80047998: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x8004799C: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800479A0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800479A4: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800479A8: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x800479AC: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800479B0: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800479B4: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800479B8: neg.s       $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = -ctx->f4.fl;
    // 0x800479BC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800479C0: add.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800479C4: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
    // 0x800479C8: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800479CC: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800479D0: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800479D4: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x800479D8: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800479DC: b           L_80047AA4
    // 0x800479E0: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
        goto L_80047AA4;
    // 0x800479E0: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
L_800479E4:
    // 0x800479E4: jal         0x80049018
    // 0x800479E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80049018(rdram, ctx);
        goto after_14;
    // 0x800479E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800479EC: beq         $v0, $zero, L_80047A04
    if (ctx->r2 == 0) {
        // 0x800479F0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80047A04;
    }
    // 0x800479F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800479F4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800479F8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800479FC: b           L_80047A10
    // 0x80047A00: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
        goto L_80047A10;
    // 0x80047A00: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
L_80047A04:
    // 0x80047A04: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80047A08: nop

    // 0x80047A0C: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
L_80047A10:
    // 0x80047A10: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80047A14: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x80047A18: mul.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80047A1C: jal         0x80066E88
    // 0x80047A20: nop

    func_80066E88(rdram, ctx);
        goto after_15;
    // 0x80047A20: nop

    after_15:
    // 0x80047A24: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80047A28: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80047A2C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80047A30: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x80047A34: mul.s       $f12, $f8, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80047A38: jal         0x80066DE4
    // 0x80047A3C: nop

    func_80066DE4(rdram, ctx);
        goto after_16;
    // 0x80047A3C: nop

    after_16:
    // 0x80047A40: lwc1        $f2, 0x54($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80047A44: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80047A48: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80047A4C: neg.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = -ctx->f2.fl;
    // 0x80047A50: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80047A54: mul.s       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x80047A58: add.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80047A5C: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x80047A60: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80047A64: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80047A68: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80047A6C: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x80047A70: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80047A74: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047A78: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80047A7C: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x80047A80: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80047A84: add.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80047A88: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
    // 0x80047A8C: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80047A90: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80047A94: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80047A98: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x80047A9C: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80047AA0: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
L_80047AA4:
    // 0x80047AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80047AA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80047AAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80047AB0: jr          $ra
    // 0x80047AB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80047AB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8043B44C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B44C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043B450: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8043B454: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8043B458: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8043B45C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043B460: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8043B464: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8043B468: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8043B46C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8043B470: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8043B474: lui         $t2, 0x8044
    ctx->r10 = S32(RELOC_HI16(83, 0X118C) << 16);
    // 0x8043B478: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8043B47C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8043B480: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8043B484: lw          $t2, -0x4814($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(83, 0X118C));
    // 0x8043B488: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8043B48C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8043B490: jal         0x8043A7D4
    // 0x8043B494: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8043A7D4(rdram, ctx);
        goto after_0;
    // 0x8043B494: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043B498: jal         0x8043A830
    // 0x8043B49C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8043A830(rdram, ctx);
        goto after_1;
    // 0x8043B49C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8043B4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043B4A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043B4A8: jr          $ra
    // 0x8043B4AC: nop

    return;
    // 0x8043B4AC: nop

;}
RECOMP_FUNC void func_8066A158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A158: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066A15C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A160: jal         0x80669E80
    // 0x8066A164: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80669E80(rdram, ctx);
        goto after_0;
    // 0x8066A164: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066A168: jal         0x80669FA4
    // 0x8066A16C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80669FA4(rdram, ctx);
        goto after_1;
    // 0x8066A16C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8066A170: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066A174: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(511, 0XD6C) << 16);
    // 0x8066A178: lwc1        $f6, -0x5514($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(511, 0XD6C));
    // 0x8066A17C: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8066A180: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8066A184: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066A188: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8066A18C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8066A190: bc1fl       L_8066A1A8
    if (!c1cs) {
        // 0x8066A194: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066A1A8;
    }
    goto skip_0;
    // 0x8066A194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066A198: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8066A19C: jal         0x8066A790
    // 0x8066A1A0: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_8066A790(rdram, ctx);
        goto after_2;
    // 0x8066A1A0: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_2:
    // 0x8066A1A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A1A8:
    // 0x8066A1A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066A1AC: jr          $ra
    // 0x8066A1B0: nop

    return;
    // 0x8066A1B0: nop

;}
RECOMP_FUNC void func_805D0FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D0FF0: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(465, 0X618) << 16);
    // 0x805D0FF4: addiu       $v0, $v0, 0x1608
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(465, 0X618));
    // 0x805D0FF8: jr          $ra
    // 0x805D0FFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805D0FFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80446310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446310: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446314: addiu       $v1, $zero, 0x1EF0
    ctx->r3 = ADD32(0, 0X1EF0);
    // 0x80446318: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044631C: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80446320: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446324: sw          $zero, 0x6CAC($at)
    MEM_W(0X6CAC, ctx->r1) = 0;
    // 0x80446328: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x8044632C: addiu       $a2, $zero, 0x1B6C
    ctx->r6 = ADD32(0, 0X1B6C);
    // 0x80446330: sw          $a1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r5;
    // 0x80446334: sw          $a2, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r6;
    // 0x80446338: sw          $a1, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r5;
    // 0x8044633C: sw          $a2, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->r6;
    // 0x80446340: jr          $ra
    // 0x80446344: sw          $v1, 0x100($v0)
    MEM_W(0X100, ctx->r2) = ctx->r3;
    return;
    // 0x80446344: sw          $v1, 0x100($v0)
    MEM_W(0X100, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_8007C174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C174: sw          $a1, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r5;
    // 0x8007C178: jr          $ra
    // 0x8007C17C: nop

    return;
    // 0x8007C17C: nop

;}
RECOMP_FUNC void func_805DAE90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DAE90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DAE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DAE98: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805DAE9C: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x805DAEA0: lui         $t8, 0x805E
    ctx->r24 = S32(RELOC_HI16(480, 0X26F8) << 16);
    // 0x805DAEA4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805DAEA8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805DAEAC: lw          $t8, -0x2C08($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(480, 0X26F8));
    // 0x805DAEB0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805DAEB4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x805DAEB8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x805DAEBC: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x805DAEC0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x805DAEC4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x805DAEC8: beql        $v1, $zero, L_805DAEFC
    if (ctx->r3 == 0) {
        // 0x805DAECC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805DAEFC;
    }
    goto skip_0;
    // 0x805DAECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805DAED0: jalr        $v1
    // 0x805DAED4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x805DAED4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805DAED8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805DAEDC: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x805DAEE0: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x805DAEE4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x805DAEE8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x805DAEEC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x805DAEF0: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x805DAEF4: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x805DAEF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805DAEFC:
    // 0x805DAEFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DAF00: jr          $ra
    // 0x805DAF04: nop

    return;
    // 0x805DAF04: nop

;}
RECOMP_FUNC void func_8066A698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A698: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8066A69C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8066A6A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066A6A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A6A8: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    // 0x8066A6AC: swc1        $f0, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f0.u32l;
    // 0x8066A6B0: jal         0x8066A614
    // 0x8066A6B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8066A614(rdram, ctx);
        goto after_0;
    // 0x8066A6B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066A6B8: bne         $v0, $zero, L_8066A6D0
    if (ctx->r2 != 0) {
        // 0x8066A6BC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8066A6D0;
    }
    // 0x8066A6BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066A6C0: jal         0x800445A4
    // 0x8066A6C4: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8066A6C4: nop

    after_1:
    // 0x8066A6C8: b           L_8066A784
    // 0x8066A6CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8066A784;
    // 0x8066A6CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A6D0:
    // 0x8066A6D0: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(511, 0X7E8) << 16);
    // 0x8066A6D4: addiu       $t6, $t6, -0x5A98
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(511, 0X7E8));
    // 0x8066A6D8: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8066A6DC: jal         0x8066A658
    // 0x8066A6E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8066A658(rdram, ctx);
        goto after_2;
    // 0x8066A6E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8066A6E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066A6E8: lui         $t7, 0x8067
    ctx->r15 = S32(RELOC_HI16(511, 0X8F0) << 16);
    // 0x8066A6EC: addiu       $t7, $t7, -0x5990
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(511, 0X8F0));
    // 0x8066A6F0: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x8066A6F4: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8066A6F8: lui         $t9, 0x8067
    ctx->r25 = S32(RELOC_HI16(511, 0XD00) << 16);
    // 0x8066A6FC: addiu       $t9, $t9, -0x5580
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(511, 0XD00));
    // 0x8066A700: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x8066A704: sh          $t8, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r24;
    // 0x8066A708: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8066A70C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8066A710: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8066A714: addiu       $at, $zero, 0x4555
    ctx->r1 = ADD32(0, 0X4555);
    // 0x8066A718: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8066A71C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8066A720: beq         $v0, $at, L_8066A748
    if (ctx->r2 == ctx->r1) {
        // 0x8066A724: sh          $zero, 0x144($a0)
        MEM_H(0X144, ctx->r4) = 0;
            goto L_8066A748;
    }
    // 0x8066A724: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8066A728: addiu       $at, $zero, 0x455B
    ctx->r1 = ADD32(0, 0X455B);
    // 0x8066A72C: beq         $v0, $at, L_8066A760
    if (ctx->r2 == ctx->r1) {
        // 0x8066A730: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8066A760;
    }
    // 0x8066A730: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066A734: addiu       $at, $zero, 0x455C
    ctx->r1 = ADD32(0, 0X455C);
    // 0x8066A738: beq         $v0, $at, L_8066A774
    if (ctx->r2 == ctx->r1) {
        // 0x8066A73C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8066A774;
    }
    // 0x8066A73C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066A740: b           L_8066A784
    // 0x8066A744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8066A784;
    // 0x8066A744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A748:
    // 0x8066A748: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066A74C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8066A750: jal         0x8066A790
    // 0x8066A754: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8066A790(rdram, ctx);
        goto after_3;
    // 0x8066A754: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8066A758: b           L_8066A784
    // 0x8066A75C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8066A784;
    // 0x8066A75C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A760:
    // 0x8066A760: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8066A764: jal         0x8066A790
    // 0x8066A768: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8066A790(rdram, ctx);
        goto after_4;
    // 0x8066A768: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8066A76C: b           L_8066A784
    // 0x8066A770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8066A784;
    // 0x8066A770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A774:
    // 0x8066A774: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8066A778: jal         0x8066A790
    // 0x8066A77C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8066A790(rdram, ctx);
        goto after_5;
    // 0x8066A77C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x8066A780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A784:
    // 0x8066A784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066A788: jr          $ra
    // 0x8066A78C: nop

    return;
    // 0x8066A78C: nop

;}
RECOMP_FUNC void func_80444998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80444998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044499C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804449A0: jal         0x804448D8
    // 0x804449A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804448D8(rdram, ctx);
        goto after_0;
    // 0x804449A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804449A8: jal         0x8044493C
    // 0x804449AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8044493C(rdram, ctx);
        goto after_1;
    // 0x804449AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804449B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804449B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804449B8: jr          $ra
    // 0x804449BC: nop

    return;
    // 0x804449BC: nop

;}
RECOMP_FUNC void func_806DFE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DFE00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DFE04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DFE08: jal         0x806DF6E0
    // 0x806DFE0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806DF6E0(rdram, ctx);
        goto after_0;
    // 0x806DFE0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806DFE10: jal         0x806DFBD4
    // 0x806DFE14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806DFBD4(rdram, ctx);
        goto after_1;
    // 0x806DFE14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806DFE18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806DFE1C: jal         0x80062748
    // 0x806DFE20: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80062748(rdram, ctx);
        goto after_2;
    // 0x806DFE20: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x806DFE24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DFE28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DFE2C: jr          $ra
    // 0x806DFE30: nop

    return;
    // 0x806DFE30: nop

;}
