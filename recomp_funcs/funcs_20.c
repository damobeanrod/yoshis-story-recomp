#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8078EEA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078EEA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078EEA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078EEAC: jal         0x8004700C
    // 0x8078EEB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8078EEB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8078EEB4: beq         $v0, $zero, L_8078EF50
    if (ctx->r2 == 0) {
        // 0x8078EEB8: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8078EF50;
    }
    // 0x8078EEB8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8078EEBC: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x8078EEC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8078EEC4: bnel        $t6, $at, L_8078EF54
    if (ctx->r14 != ctx->r1) {
        // 0x8078EEC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078EF54;
    }
    goto skip_0;
    // 0x8078EEC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8078EECC: lbu         $t7, 0x30($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X30);
    // 0x8078EED0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8078EED4: bnel        $t7, $at, L_8078EF54
    if (ctx->r15 != ctx->r1) {
        // 0x8078EED8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078EF54;
    }
    goto skip_1;
    // 0x8078EED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8078EEDC: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8078EEE0: lwc1        $f6, 0x84($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X84);
    // 0x8078EEE4: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(811, 0X604) << 16);
    // 0x8078EEE8: lwc1        $f8, -0xEFC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(811, 0X604));
    // 0x8078EEEC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8078EEF0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8078EEF4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8078EEF8: nop

    // 0x8078EEFC: bc1fl       L_8078EF54
    if (!c1cs) {
        // 0x8078EF00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078EF54;
    }
    goto skip_2;
    // 0x8078EF00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8078EF04: lw          $t8, 0x174($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X174);
    // 0x8078EF08: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8078EF0C: andi        $t0, $t9, 0xF00
    ctx->r8 = ctx->r25 & 0XF00;
    // 0x8078EF10: beq         $t0, $zero, L_8078EF50
    if (ctx->r8 == 0) {
        // 0x8078EF14: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_8078EF50;
    }
    // 0x8078EF14: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8078EF18: lw          $t9, -0x7298($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7298);
    // 0x8078EF1C: lw          $t1, 0x1F4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X1F4);
    // 0x8078EF20: addiu       $a1, $a2, 0x84
    ctx->r5 = ADD32(ctx->r6, 0X84);
    // 0x8078EF24: jalr        $t9
    // 0x8078EF28: lhu         $a0, 0x8($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X8);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8078EF28: lhu         $a0, 0x8($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X8);
    after_1:
    // 0x8078EF2C: beq         $v0, $zero, L_8078EF50
    if (ctx->r2 == 0) {
        // 0x8078EF30: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8078EF50;
    }
    // 0x8078EF30: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8078EF34: jal         0x800447C8
    // 0x8078EF38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x8078EF38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x8078EF3C: jal         0x80067E68
    // 0x8078EF40: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x8078EF40: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_3:
    // 0x8078EF44: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x8078EF48: jal         0x80067818
    // 0x8078EF4C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8078EF4C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
L_8078EF50:
    // 0x8078EF50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078EF54:
    // 0x8078EF54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078EF58: jr          $ra
    // 0x8078EF5C: nop

    return;
    // 0x8078EF5C: nop

;}
RECOMP_FUNC void func_8069CAD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069CAD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8069CAD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8069CADC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8069CAE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8069CAE4: jal         0x80045A34
    // 0x8069CAE8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8069CAE8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x8069CAEC: bne         $v0, $zero, L_8069CB04
    if (ctx->r2 != 0) {
        // 0x8069CAF0: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_8069CB04;
    }
    // 0x8069CAF0: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8069CAF4: jal         0x800445A4
    // 0x8069CAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8069CAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8069CAFC: b           L_8069CBD4
    // 0x8069CB00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8069CBD4;
    // 0x8069CB00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069CB04:
    // 0x8069CB04: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x8069CB08: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(568, 0X490) << 16);
    // 0x8069CB0C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8069CB10: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8069CB14: addiu       $t6, $t6, -0x33D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(568, 0X490));
    // 0x8069CB18: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8069CB1C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8069CB20: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8069CB24: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8069CB28: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8069CB2C: sw          $t8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r24;
    // 0x8069CB30: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x8069CB34: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x8069CB38: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8069CB3C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8069CB40: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8069CB44: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8069CB48: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8069CB4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8069CB50: lui         $t2, 0x806A
    ctx->r10 = S32(RELOC_HI16(568, 0X134) << 16);
    // 0x8069CB54: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8069CB58: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8069CB5C: addiu       $t2, $t2, -0x372C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(568, 0X134));
    // 0x8069CB60: bc1fl       L_8069CB88
    if (!c1cs) {
        // 0x8069CB64: sw          $t2, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->r10;
            goto L_8069CB88;
    }
    goto skip_0;
    // 0x8069CB64: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    skip_0:
    // 0x8069CB68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8069CB6C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8069CB70: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8069CB74: nop

    // 0x8069CB78: bc1fl       L_8069CB88
    if (!c1cs) {
        // 0x8069CB7C: sw          $t2, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->r10;
            goto L_8069CB88;
    }
    goto skip_1;
    // 0x8069CB7C: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    skip_1:
    // 0x8069CB80: sw          $t1, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r9;
    // 0x8069CB84: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
L_8069CB88:
    // 0x8069CB88: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8069CB8C: jal         0x80067BBC
    // 0x8069CB90: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8069CB90: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x8069CB94: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x8069CB98: jal         0x80067F78
    // 0x8069CB9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_3;
    // 0x8069CB9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8069CBA0: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8069CBA4: jal         0x8069C97C
    // 0x8069CBA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8069C97C(rdram, ctx);
        goto after_4;
    // 0x8069CBA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8069CBAC: jal         0x8005FD1C
    // 0x8069CBB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FD1C(rdram, ctx);
        goto after_5;
    // 0x8069CBB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8069CBB4: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x8069CBB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069CBBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069CBC0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8069CBC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8069CBC8: jal         0x8069CBE4
    // 0x8069CBCC: sh          $zero, 0x12($t4)
    MEM_H(0X12, ctx->r12) = 0;
    func_8069CBE4(rdram, ctx);
        goto after_6;
    // 0x8069CBCC: sh          $zero, 0x12($t4)
    MEM_H(0X12, ctx->r12) = 0;
    after_6:
    // 0x8069CBD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069CBD4:
    // 0x8069CBD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8069CBD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8069CBDC: jr          $ra
    // 0x8069CBE0: nop

    return;
    // 0x8069CBE0: nop

;}
RECOMP_FUNC void func_80468830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80468830: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80468834: lw          $v1, 0x16C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X16C);
    // 0x80468838: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x8046883C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80468840: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80468844: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x80468848: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8046884C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80468850: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80468854: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80468858: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x8046885C: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x80468860: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80468864: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80468868: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8046886C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80468870: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80468874: ori         $t3, $t3, 0x18
    ctx->r11 = ctx->r11 | 0X18;
    // 0x80468878: ori         $t4, $zero, 0xACF0
    ctx->r12 = 0 | 0XACF0;
    // 0x8046887C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80468880: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80468884: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80468888: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8046888C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80468890: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x80468894: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x80468898: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8046889C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x804688A0: ori         $t0, $t0, 0x41C9
    ctx->r8 = ctx->r8 | 0X41C9;
    // 0x804688A4: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x804688A8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x804688AC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x804688B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804688B4: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x804688B8: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x804688BC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x804688C0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x804688C4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x804688C8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x804688CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804688D0: lui         $t2, 0xFF2F
    ctx->r10 = S32(0XFF2F << 16);
    // 0x804688D4: lui         $t1, 0xFC11
    ctx->r9 = S32(0XFC11 << 16);
    // 0x804688D8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x804688DC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804688E0: ori         $t1, $t1, 0x9623
    ctx->r9 = ctx->r9 | 0X9623;
    // 0x804688E4: ori         $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 | 0XFFFF;
    // 0x804688E8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x804688EC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x804688F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804688F4: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x804688F8: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x804688FC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80468900: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80468904: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80468908: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8046890C: lbu         $t6, 0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3);
    // 0x80468910: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
    // 0x80468914: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80468918: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x8046891C: or          $t1, $t6, $t9
    ctx->r9 = ctx->r14 | ctx->r25;
    // 0x80468920: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80468924: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x80468928: sll         $t6, $t8, 8
    ctx->r14 = S32(ctx->r24 << 8);
    // 0x8046892C: or          $t9, $t5, $t6
    ctx->r25 = ctx->r13 | ctx->r14;
    // 0x80468930: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80468934: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80468938: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8046893C: lui         $t3, 0xBB00
    ctx->r11 = S32(0XBB00 << 16);
    // 0x80468940: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80468944: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80468948: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x8046894C: ori         $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 | 0X8000;
    // 0x80468950: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80468954: jr          $ra
    // 0x80468958: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    return;
    // 0x80468958: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void func_8004F5FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F5FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004F600: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004F604: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004F608: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004F60C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8004F610: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8004F614: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004F618: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004F61C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004F620: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004F624: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x8004F628: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8004F62C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8004F630: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8004F634: jal         0x8004F5A4
    // 0x8004F638: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    func_8004F5A4(rdram, ctx);
        goto after_0;
    // 0x8004F638: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8004F63C: jal         0x8004F5A4
    // 0x8004F640: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_8004F5A4(rdram, ctx);
        goto after_1;
    // 0x8004F640: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_1:
    // 0x8004F644: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004F648: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004F64C: lwc1        $f2, 0x984($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X984);
    // 0x8004F650: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x8004F654: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x8004F658: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004F65C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004F660: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004F664: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8004F668: nop

    // 0x8004F66C: bc1t        L_8004F684
    if (c1cs) {
        // 0x8004F670: nop
    
            goto L_8004F684;
    }
    // 0x8004F670: nop

    // 0x8004F674: lwc1        $f18, 0x988($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X988);
    // 0x8004F678: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x8004F67C: nop

    // 0x8004F680: bc1f        L_8004F690
    if (!c1cs) {
        // 0x8004F684: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_8004F690;
    }
L_8004F684:
    // 0x8004F684: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004F688: lwc1        $f18, 0x98C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X98C);
    // 0x8004F68C: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
L_8004F690:
    // 0x8004F690: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004F694: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004F698: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004F69C: nop

    // 0x8004F6A0: bc1tl       L_8004F6BC
    if (c1cs) {
        // 0x8004F6A4: swc1        $f4, 0x30($s0)
        MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
            goto L_8004F6BC;
    }
    goto skip_0;
    // 0x8004F6A4: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    skip_0:
    // 0x8004F6A8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8004F6AC: nop

    // 0x8004F6B0: bc1fl       L_8004F6C0
    if (!c1cs) {
        // 0x8004F6B4: lwc1        $f12, 0x18($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
            goto L_8004F6C0;
    }
    goto skip_1;
    // 0x8004F6B4: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    skip_1:
    // 0x8004F6B8: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
L_8004F6BC:
    // 0x8004F6BC: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
L_8004F6C0:
    // 0x8004F6C0: jal         0x80065388
    // 0x8004F6C4: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    func_80065388(rdram, ctx);
        goto after_2;
    // 0x8004F6C4: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    after_2:
    // 0x8004F6C8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8004F6CC: lwc1        $f14, 0x30($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8004F6D0: jal         0x80065388
    // 0x8004F6D4: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    func_80065388(rdram, ctx);
        goto after_3;
    // 0x8004F6D4: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    after_3:
    // 0x8004F6D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004F6DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004F6E0: jal         0x8004F44C
    // 0x8004F6E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004F44C(rdram, ctx);
        goto after_4;
    // 0x8004F6E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x8004F6E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004F6EC: lwc1        $f2, 0x9A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X9A0);
    // 0x8004F6F0: lbu         $t6, 0x3C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X3C);
    // 0x8004F6F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004F6F8: lwc1        $f18, 0x9A4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X9A4);
    // 0x8004F6FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004F700: sb          $zero, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = 0;
    // 0x8004F704: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004F708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004F70C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8004F710: sb          $t6, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r14;
L_8004F714:
    // 0x8004F714: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8004F718: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004F71C: nop

    // 0x8004F720: bc1tl       L_8004F744
    if (c1cs) {
        // 0x8004F724: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8004F744;
    }
    goto skip_2;
    // 0x8004F724: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_2:
    // 0x8004F728: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8004F72C: nop

    // 0x8004F730: bc1tl       L_8004F744
    if (c1cs) {
        // 0x8004F734: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8004F744;
    }
    goto skip_3;
    // 0x8004F734: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_3:
    // 0x8004F738: b           L_8004F77C
    // 0x8004F73C: swc1        $f16, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f16.u32l;
        goto L_8004F77C;
    // 0x8004F73C: swc1        $f16, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f16.u32l;
    // 0x8004F740: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8004F744:
    // 0x8004F744: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8004F748: addiu       $t8, $t8, 0x1020
    ctx->r24 = ADD32(ctx->r24, 0X1020);
    // 0x8004F74C: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8004F750: bc1f        L_8004F76C
    if (!c1cs) {
        // 0x8004F754: addu        $v0, $t7, $t8
        ctx->r2 = ADD32(ctx->r15, ctx->r24);
            goto L_8004F76C;
    }
    // 0x8004F754: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8004F758: lbu         $t9, 0x3C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X3C);
    // 0x8004F75C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8004F760: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x8004F764: b           L_8004F77C
    // 0x8004F768: sb          $t1, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r9;
        goto L_8004F77C;
    // 0x8004F768: sb          $t1, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r9;
L_8004F76C:
    // 0x8004F76C: lbu         $t2, 0x3C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X3C);
    // 0x8004F770: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x8004F774: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x8004F778: sb          $t4, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r12;
L_8004F77C:
    // 0x8004F77C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004F780: bne         $v1, $a1, L_8004F714
    if (ctx->r3 != ctx->r5) {
        // 0x8004F784: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8004F714;
    }
    // 0x8004F784: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8004F788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F78C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004F790: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004F794: jr          $ra
    // 0x8004F798: nop

    return;
    // 0x8004F798: nop

;}
RECOMP_FUNC void func_80674804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80674804: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80674808: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067480C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80674810: jal         0x806747A8
    // 0x80674814: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806747A8(rdram, ctx);
        goto after_0;
    // 0x80674814: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80674818: bne         $v0, $zero, L_80674830
    if (ctx->r2 != 0) {
        // 0x8067481C: nop
    
            goto L_80674830;
    }
    // 0x8067481C: nop

    // 0x80674820: jal         0x800445A4
    // 0x80674824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80674824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80674828: b           L_80674860
    // 0x8067482C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80674860;
    // 0x8067482C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80674830:
    // 0x80674830: jal         0x806731F4
    // 0x80674834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806731F4(rdram, ctx);
        goto after_2;
    // 0x80674834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80674838: jal         0x8067414C
    // 0x8067483C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067414C(rdram, ctx);
        goto after_3;
    // 0x8067483C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80674840: jal         0x806734B4
    // 0x80674844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806734B4(rdram, ctx);
        goto after_4;
    // 0x80674844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80674848: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8067484C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80674850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80674854: jal         0x806747EC
    // 0x80674858: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    func_806747EC(rdram, ctx);
        goto after_5;
    // 0x80674858: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x8067485C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80674860:
    // 0x80674860: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80674864: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80674868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067486C: jr          $ra
    // 0x80674870: nop

    return;
    // 0x80674870: nop

;}
RECOMP_FUNC void func_8069DBF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069DBF8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8069DBFC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8069DC00: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8069DC04: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8069DC08: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8069DC0C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8069DC10: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8069DC14: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8069DC18: lui         $t1, 0x806A
    ctx->r9 = S32(RELOC_HI16(574, 0XD54) << 16);
    // 0x8069DC1C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8069DC20: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8069DC24: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8069DC28: lw          $t1, -0x1D2C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(574, 0XD54));
    // 0x8069DC2C: jr          $ra
    // 0x8069DC30: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8069DC30: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_800270C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800270C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800270CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800270D0: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x800270D4: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x800270D8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800270DC: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x800270E0: addiu       $t8, $t8, 0x6FD4
    ctx->r24 = ADD32(ctx->r24, 0X6FD4);
    // 0x800270E4: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    // 0x800270E8: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
    // 0x800270EC: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
    // 0x800270F0: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x800270F4: lw          $t0, 0x48($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X48);
    // 0x800270F8: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800270FC: jal         0x8001D770
    // 0x80027100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001D770(rdram, ctx);
        goto after_0;
    // 0x80027100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80027104: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80027108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002710C: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80027110: jal         0x80067BF8
    // 0x80027114: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_1;
    // 0x80027114: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_1:
    // 0x80027118: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8002711C: jal         0x80067818
    // 0x80027120: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80027120: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80027124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002712C: jr          $ra
    // 0x80027130: nop

    return;
    // 0x80027130: nop

;}
RECOMP_FUNC void func_80449D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449D14: jr          $ra
    // 0x80449D18: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80449D18: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8001759C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001759C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800175A0: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800175A4: lbu         $t7, -0x6DA0($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X6DA0);
    // 0x800175A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800175AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800175B0: addiu       $t6, $zero, 0x3F
    ctx->r14 = ADD32(0, 0X3F);
    // 0x800175B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800175B8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800175BC: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800175C0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800175C4: sh          $t6, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r14;
    // 0x800175C8: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
    // 0x800175CC: sh          $zero, 0x50($sp)
    MEM_H(0X50, ctx->r29) = 0;
    // 0x800175D0: bne         $t7, $zero, L_800186CC
    if (ctx->r15 != 0) {
        // 0x800175D4: swc1        $f14, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
            goto L_800186CC;
    }
    // 0x800175D4: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    // 0x800175D8: lh          $a1, 0x6E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X6E);
    // 0x800175DC: sh          $v1, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r3;
    // 0x800175E0: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800175E4: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
    // 0x800175E8: jal         0x80011928
    // 0x800175EC: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    func_80011928(rdram, ctx);
        goto after_0;
    // 0x800175EC: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800175F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800175F4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800175F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800175FC: lh          $v1, 0x66($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X66);
    // 0x80017600: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80017604: lh          $t0, 0x4E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4E);
    // 0x80017608: bne         $v0, $at, L_800186CC
    if (ctx->r2 != ctx->r1) {
        // 0x8001760C: lwc1        $f14, 0x58($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
            goto L_800186CC;
    }
    // 0x8001760C: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80017610: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80017614: sltiu       $at, $t8, 0x78
    ctx->r1 = ctx->r24 < 0X78 ? 1 : 0;
    // 0x80017618: beq         $at, $zero, L_80018488
    if (ctx->r1 == 0) {
        // 0x8001761C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80018488;
    }
    // 0x8001761C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80017620: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80017624: addu        $at, $at, $t8
    gpr jr_addend_8001762C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80017628: lw          $t8, -0x1230($at)
    ctx->r24 = ADD32(ctx->r1, -0X1230);
    // 0x8001762C: jr          $t8
    // 0x80017630: nop

    switch (jr_addend_8001762C >> 2) {
        case 0: goto L_800186CC; break;
        case 1: goto L_80017634; break;
        case 2: goto L_8001763C; break;
        case 3: goto L_8001764C; break;
        case 4: goto L_8001765C; break;
        case 5: goto L_80017664; break;
        case 6: goto L_80017674; break;
        case 7: goto L_80017684; break;
        case 8: goto L_800176C8; break;
        case 9: goto L_800176D4; break;
        case 10: goto L_800176E0; break;
        case 11: goto L_800176EC; break;
        case 12: goto L_800176F8; break;
        case 13: goto L_80017700; break;
        case 14: goto L_80017708; break;
        case 15: goto L_8001774C; break;
        case 16: goto L_80017790; break;
        case 17: goto L_80017798; break;
        case 18: goto L_800177A0; break;
        case 19: goto L_800177FC; break;
        case 20: goto L_80017804; break;
        case 21: goto L_8001780C; break;
        case 22: goto L_800186CC; break;
        case 23: goto L_80017818; break;
        case 24: goto L_80017820; break;
        case 25: goto L_80017828; break;
        case 26: goto L_80017830; break;
        case 27: goto L_80017838; break;
        case 28: goto L_80017848; break;
        case 29: goto L_80017878; break;
        case 30: goto L_800186CC; break;
        case 31: goto L_80017880; break;
        case 32: goto L_80017888; break;
        case 33: goto L_80017890; break;
        case 34: goto L_800186CC; break;
        case 35: goto L_80017898; break;
        case 36: goto L_800178A0; break;
        case 37: goto L_800178A8; break;
        case 38: goto L_800178B0; break;
        case 39: goto L_800178D0; break;
        case 40: goto L_8001790C; break;
        case 41: goto L_80017914; break;
        case 42: goto L_8001791C; break;
        case 43: goto L_80017960; break;
        case 44: goto L_800179AC; break;
        case 45: goto L_800179B4; break;
        case 46: goto L_800179C0; break;
        case 47: goto L_800179C8; break;
        case 48: goto L_80017A24; break;
        case 49: goto L_800186CC; break;
        case 50: goto L_80017A2C; break;
        case 51: goto L_80017AF8; break;
        case 52: goto L_80017B00; break;
        case 53: goto L_80017B08; break;
        case 54: goto L_80017B10; break;
        case 55: goto L_80017B20; break;
        case 56: goto L_80017C14; break;
        case 57: goto L_80017C68; break;
        case 58: goto L_80017C94; break;
        case 59: goto L_80017CD8; break;
        case 60: goto L_80017CE0; break;
        case 61: goto L_80017CEC; break;
        case 62: goto L_80017CF8; break;
        case 63: goto L_80017D04; break;
        case 64: goto L_80017D0C; break;
        case 65: goto L_80017E08; break;
        case 66: goto L_80017E10; break;
        case 67: goto L_80017E18; break;
        case 68: goto L_80017E20; break;
        case 69: goto L_80017E28; break;
        case 70: goto L_80017EAC; break;
        case 71: goto L_800186CC; break;
        case 72: goto L_800186CC; break;
        case 73: goto L_80017ED0; break;
        case 74: goto L_80017ED8; break;
        case 75: goto L_80017F1C; break;
        case 76: goto L_80017F68; break;
        case 77: goto L_80017F78; break;
        case 78: goto L_80017F84; break;
        case 79: goto L_80017F8C; break;
        case 80: goto L_80017F98; break;
        case 81: goto L_80017FE8; break;
        case 82: goto L_80017FF0; break;
        case 83: goto L_80018034; break;
        case 84: goto L_8001803C; break;
        case 85: goto L_80018060; break;
        case 86: goto L_800180A4; break;
        case 87: goto L_80018108; break;
        case 88: goto L_80018110; break;
        case 89: goto L_80018154; break;
        case 90: goto L_80018164; break;
        case 91: goto L_800186CC; break;
        case 92: goto L_8001816C; break;
        case 93: goto L_80018174; break;
        case 94: goto L_800181E0; break;
        case 95: goto L_800181E8; break;
        case 96: goto L_800181F4; break;
        case 97: goto L_80018200; break;
        case 98: goto L_80018208; break;
        case 99: goto L_80018218; break;
        case 100: goto L_80018220; break;
        case 101: goto L_8001822C; break;
        case 102: goto L_80018238; break;
        case 103: goto L_80018244; break;
        case 104: goto L_80018250; break;
        case 105: goto L_8001825C; break;
        case 106: goto L_80018268; break;
        case 107: goto L_800182AC; break;
        case 108: goto L_800182C0; break;
        case 109: goto L_800182D4; break;
        case 110: goto L_800182E0; break;
        case 111: goto L_800182EC; break;
        case 112: goto L_800182F8; break;
        case 113: goto L_80018304; break;
        case 114: goto L_80018310; break;
        case 115: goto L_8001831C; break;
        case 116: goto L_8001835C; break;
        case 117: goto L_80018364; break;
        case 118: goto L_800183C8; break;
        case 119: goto L_800186CC; break;
        default: switch_error(__func__, 0x8001762C, 0x800AEDD0);
    }
    // 0x80017630: nop

L_80017634:
    // 0x80017634: b           L_80018488
    // 0x80017638: addiu       $v1, $zero, 0x3A
    ctx->r3 = ADD32(0, 0X3A);
        goto L_80018488;
    // 0x80017638: addiu       $v1, $zero, 0x3A
    ctx->r3 = ADD32(0, 0X3A);
L_8001763C:
    // 0x8001763C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80017640: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80017644: b           L_80018488
    // 0x80017648: addiu       $v1, $zero, 0x22
    ctx->r3 = ADD32(0, 0X22);
        goto L_80018488;
    // 0x80017648: addiu       $v1, $zero, 0x22
    ctx->r3 = ADD32(0, 0X22);
L_8001764C:
    // 0x8001764C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80017650: sh          $t1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r9;
    // 0x80017654: b           L_80018488
    // 0x80017658: addiu       $v1, $zero, 0x35
    ctx->r3 = ADD32(0, 0X35);
        goto L_80018488;
    // 0x80017658: addiu       $v1, $zero, 0x35
    ctx->r3 = ADD32(0, 0X35);
L_8001765C:
    // 0x8001765C: b           L_80018488
    // 0x80017660: addiu       $v1, $zero, 0x1AF
    ctx->r3 = ADD32(0, 0X1AF);
        goto L_80018488;
    // 0x80017660: addiu       $v1, $zero, 0x1AF
    ctx->r3 = ADD32(0, 0X1AF);
L_80017664:
    // 0x80017664: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80017668: sh          $t2, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r10;
    // 0x8001766C: b           L_80018488
    // 0x80017670: addiu       $v1, $zero, 0x33
    ctx->r3 = ADD32(0, 0X33);
        goto L_80018488;
    // 0x80017670: addiu       $v1, $zero, 0x33
    ctx->r3 = ADD32(0, 0X33);
L_80017674:
    // 0x80017674: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80017678: sh          $t3, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r11;
    // 0x8001767C: b           L_80018488
    // 0x80017680: addiu       $v1, $zero, 0x48
    ctx->r3 = ADD32(0, 0X48);
        goto L_80018488;
    // 0x80017680: addiu       $v1, $zero, 0x48
    ctx->r3 = ADD32(0, 0X48);
L_80017684:
    // 0x80017684: beq         $a3, $zero, L_800176C0
    if (ctx->r7 == 0) {
        // 0x80017688: addiu       $v1, $zero, 0x38
        ctx->r3 = ADD32(0, 0X38);
            goto L_800176C0;
    }
    // 0x80017688: addiu       $v1, $zero, 0x38
    ctx->r3 = ADD32(0, 0X38);
    // 0x8001768C: lw          $t4, 0x14($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X14);
    // 0x80017690: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x80017694: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80017698: addiu       $t5, $t4, -0x40
    ctx->r13 = ADD32(ctx->r12, -0X40);
    // 0x8001769C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800176A0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800176A4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800176A8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800176AC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800176B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800176B4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800176B8: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x800176BC: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
L_800176C0:
    // 0x800176C0: b           L_80018488
    // 0x800176C4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x800176C4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800176C8:
    // 0x800176C8: addiu       $v1, $zero, 0x5F
    ctx->r3 = ADD32(0, 0X5F);
    // 0x800176CC: b           L_80018488
    // 0x800176D0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x800176D0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800176D4:
    // 0x800176D4: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x800176D8: b           L_80018488
    // 0x800176DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x800176DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800176E0:
    // 0x800176E0: addiu       $v1, $zero, 0x65
    ctx->r3 = ADD32(0, 0X65);
    // 0x800176E4: b           L_80018488
    // 0x800176E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x800176E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800176EC:
    // 0x800176EC: addiu       $v1, $zero, 0x1E5
    ctx->r3 = ADD32(0, 0X1E5);
    // 0x800176F0: b           L_80018488
    // 0x800176F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x800176F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800176F8:
    // 0x800176F8: b           L_80018488
    // 0x800176FC: addiu       $v1, $zero, 0x4B
    ctx->r3 = ADD32(0, 0X4B);
        goto L_80018488;
    // 0x800176FC: addiu       $v1, $zero, 0x4B
    ctx->r3 = ADD32(0, 0X4B);
L_80017700:
    // 0x80017700: b           L_80018488
    // 0x80017704: addiu       $v1, $zero, 0x39
    ctx->r3 = ADD32(0, 0X39);
        goto L_80018488;
    // 0x80017704: addiu       $v1, $zero, 0x39
    ctx->r3 = ADD32(0, 0X39);
L_80017708:
    // 0x80017708: beq         $a3, $zero, L_80017744
    if (ctx->r7 == 0) {
        // 0x8001770C: nop
    
            goto L_80017744;
    }
    // 0x8001770C: nop

    // 0x80017710: lw          $t6, 0x14($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X14);
    // 0x80017714: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80017718: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001771C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80017720: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80017724: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80017728: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8001772C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80017730: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80017734: nop

    // 0x80017738: mul.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x8001773C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80017740: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
L_80017744:
    // 0x80017744: b           L_80018488
    // 0x80017748: addiu       $v1, $zero, 0x49
    ctx->r3 = ADD32(0, 0X49);
        goto L_80018488;
    // 0x80017748: addiu       $v1, $zero, 0x49
    ctx->r3 = ADD32(0, 0X49);
L_8001774C:
    // 0x8001774C: beq         $a3, $zero, L_80017788
    if (ctx->r7 == 0) {
        // 0x80017750: nop
    
            goto L_80017788;
    }
    // 0x80017750: nop

    // 0x80017754: lw          $t7, 0x14($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X14);
    // 0x80017758: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001775C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80017760: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80017764: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80017768: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001776C: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x80017770: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80017774: mul.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80017778: nop

    // 0x8001777C: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80017780: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80017784: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
L_80017788:
    // 0x80017788: b           L_80018488
    // 0x8001778C: addiu       $v1, $zero, 0x3B
    ctx->r3 = ADD32(0, 0X3B);
        goto L_80018488;
    // 0x8001778C: addiu       $v1, $zero, 0x3B
    ctx->r3 = ADD32(0, 0X3B);
L_80017790:
    // 0x80017790: b           L_80018488
    // 0x80017794: addiu       $v1, $zero, 0x6E
    ctx->r3 = ADD32(0, 0X6E);
        goto L_80018488;
    // 0x80017794: addiu       $v1, $zero, 0x6E
    ctx->r3 = ADD32(0, 0X6E);
L_80017798:
    // 0x80017798: b           L_80018488
    // 0x8001779C: addiu       $v1, $zero, 0x49
    ctx->r3 = ADD32(0, 0X49);
        goto L_80018488;
    // 0x8001779C: addiu       $v1, $zero, 0x49
    ctx->r3 = ADD32(0, 0X49);
L_800177A0:
    // 0x800177A0: beq         $a3, $zero, L_800177F4
    if (ctx->r7 == 0) {
        // 0x800177A4: nop
    
            goto L_800177F4;
    }
    // 0x800177A4: nop

    // 0x800177A8: lw          $t8, 0x14($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X14);
    // 0x800177AC: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x800177B0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800177B4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800177B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800177BC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800177C0: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800177C4: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800177C8: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x800177CC: mul.d       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800177D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800177D4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800177D8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800177DC: add.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f0.d + ctx->f4.d;
    // 0x800177E0: add.d       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f10.d + ctx->f0.d;
    // 0x800177E4: mul.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x800177E8: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x800177EC: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x800177F0: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
L_800177F4:
    // 0x800177F4: b           L_80018488
    // 0x800177F8: addiu       $v1, $zero, 0x4A
    ctx->r3 = ADD32(0, 0X4A);
        goto L_80018488;
    // 0x800177F8: addiu       $v1, $zero, 0x4A
    ctx->r3 = ADD32(0, 0X4A);
L_800177FC:
    // 0x800177FC: b           L_80018488
    // 0x80017800: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
        goto L_80018488;
    // 0x80017800: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
L_80017804:
    // 0x80017804: b           L_80018488
    // 0x80017808: addiu       $v1, $zero, 0x71
    ctx->r3 = ADD32(0, 0X71);
        goto L_80018488;
    // 0x80017808: addiu       $v1, $zero, 0x71
    ctx->r3 = ADD32(0, 0X71);
L_8001780C:
    // 0x8001780C: addiu       $v1, $zero, 0x136
    ctx->r3 = ADD32(0, 0X136);
    // 0x80017810: b           L_80018488
    // 0x80017814: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80017814: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80017818:
    // 0x80017818: b           L_80018488
    // 0x8001781C: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
        goto L_80018488;
    // 0x8001781C: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
L_80017820:
    // 0x80017820: b           L_80018488
    // 0x80017824: addiu       $v1, $zero, 0x85
    ctx->r3 = ADD32(0, 0X85);
        goto L_80018488;
    // 0x80017824: addiu       $v1, $zero, 0x85
    ctx->r3 = ADD32(0, 0X85);
L_80017828:
    // 0x80017828: b           L_80018488
    // 0x8001782C: addiu       $v1, $zero, 0x8A
    ctx->r3 = ADD32(0, 0X8A);
        goto L_80018488;
    // 0x8001782C: addiu       $v1, $zero, 0x8A
    ctx->r3 = ADD32(0, 0X8A);
L_80017830:
    // 0x80017830: b           L_80018488
    // 0x80017834: addiu       $v1, $zero, 0x8B
    ctx->r3 = ADD32(0, 0X8B);
        goto L_80018488;
    // 0x80017834: addiu       $v1, $zero, 0x8B
    ctx->r3 = ADD32(0, 0X8B);
L_80017838:
    // 0x80017838: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001783C: sh          $t9, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r25;
    // 0x80017840: b           L_80018488
    // 0x80017844: addiu       $v1, $zero, 0x42
    ctx->r3 = ADD32(0, 0X42);
        goto L_80018488;
    // 0x80017844: addiu       $v1, $zero, 0x42
    ctx->r3 = ADD32(0, 0X42);
L_80017848:
    // 0x80017848: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001784C: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x80017850: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80017854: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80017858: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8001785C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80017860: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80017864: sh          $t1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r9;
    // 0x80017868: addiu       $v1, $zero, 0x153
    ctx->r3 = ADD32(0, 0X153);
    // 0x8001786C: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80017870: b           L_80018488
    // 0x80017874: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
        goto L_80018488;
    // 0x80017874: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
L_80017878:
    // 0x80017878: b           L_80018488
    // 0x8001787C: addiu       $v1, $zero, 0x93
    ctx->r3 = ADD32(0, 0X93);
        goto L_80018488;
    // 0x8001787C: addiu       $v1, $zero, 0x93
    ctx->r3 = ADD32(0, 0X93);
L_80017880:
    // 0x80017880: b           L_80018488
    // 0x80017884: addiu       $v1, $zero, 0x97
    ctx->r3 = ADD32(0, 0X97);
        goto L_80018488;
    // 0x80017884: addiu       $v1, $zero, 0x97
    ctx->r3 = ADD32(0, 0X97);
L_80017888:
    // 0x80017888: b           L_80018488
    // 0x8001788C: addiu       $v1, $zero, 0x9B
    ctx->r3 = ADD32(0, 0X9B);
        goto L_80018488;
    // 0x8001788C: addiu       $v1, $zero, 0x9B
    ctx->r3 = ADD32(0, 0X9B);
L_80017890:
    // 0x80017890: b           L_80018488
    // 0x80017894: addiu       $v1, $zero, 0x4C
    ctx->r3 = ADD32(0, 0X4C);
        goto L_80018488;
    // 0x80017894: addiu       $v1, $zero, 0x4C
    ctx->r3 = ADD32(0, 0X4C);
L_80017898:
    // 0x80017898: b           L_80018488
    // 0x8001789C: addiu       $v1, $zero, 0x240
    ctx->r3 = ADD32(0, 0X240);
        goto L_80018488;
    // 0x8001789C: addiu       $v1, $zero, 0x240
    ctx->r3 = ADD32(0, 0X240);
L_800178A0:
    // 0x800178A0: b           L_80018488
    // 0x800178A4: addiu       $v1, $zero, 0xAF
    ctx->r3 = ADD32(0, 0XAF);
        goto L_80018488;
    // 0x800178A4: addiu       $v1, $zero, 0xAF
    ctx->r3 = ADD32(0, 0XAF);
L_800178A8:
    // 0x800178A8: b           L_80018488
    // 0x800178AC: addiu       $v1, $zero, 0xA5
    ctx->r3 = ADD32(0, 0XA5);
        goto L_80018488;
    // 0x800178AC: addiu       $v1, $zero, 0xA5
    ctx->r3 = ADD32(0, 0XA5);
L_800178B0:
    // 0x800178B0: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x800178B4: lbu         $t2, -0x6D78($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X6D78);
    // 0x800178B8: beq         $t2, $zero, L_800178C8
    if (ctx->r10 == 0) {
        // 0x800178BC: nop
    
            goto L_800178C8;
    }
    // 0x800178BC: nop

    // 0x800178C0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800178C4: nop

L_800178C8:
    // 0x800178C8: b           L_80018488
    // 0x800178CC: addiu       $v1, $zero, 0xBF
    ctx->r3 = ADD32(0, 0XBF);
        goto L_80018488;
    // 0x800178CC: addiu       $v1, $zero, 0xBF
    ctx->r3 = ADD32(0, 0XBF);
L_800178D0:
    // 0x800178D0: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x800178D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800178D8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x800178DC: sh          $t0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r8;
    // 0x800178E0: jal         0x80011928
    // 0x800178E4: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    func_80011928(rdram, ctx);
        goto after_1;
    // 0x800178E4: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x800178E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800178EC: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800178F0: lh          $t0, 0x4E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4E);
    // 0x800178F4: beq         $v0, $at, L_80017904
    if (ctx->r2 == ctx->r1) {
        // 0x800178F8: lwc1        $f14, 0x58($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80017904;
    }
    // 0x800178F8: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800178FC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80017900: nop

L_80017904:
    // 0x80017904: b           L_80018488
    // 0x80017908: addiu       $v1, $zero, 0x56
    ctx->r3 = ADD32(0, 0X56);
        goto L_80018488;
    // 0x80017908: addiu       $v1, $zero, 0x56
    ctx->r3 = ADD32(0, 0X56);
L_8001790C:
    // 0x8001790C: b           L_80018488
    // 0x80017910: addiu       $v1, $zero, 0x59
    ctx->r3 = ADD32(0, 0X59);
        goto L_80018488;
    // 0x80017910: addiu       $v1, $zero, 0x59
    ctx->r3 = ADD32(0, 0X59);
L_80017914:
    // 0x80017914: b           L_80018488
    // 0x80017918: addiu       $v1, $zero, 0xC5
    ctx->r3 = ADD32(0, 0XC5);
        goto L_80018488;
    // 0x80017918: addiu       $v1, $zero, 0xC5
    ctx->r3 = ADD32(0, 0XC5);
L_8001791C:
    // 0x8001791C: beq         $a3, $zero, L_80017958
    if (ctx->r7 == 0) {
        // 0x80017920: nop
    
            goto L_80017958;
    }
    // 0x80017920: nop

    // 0x80017924: lw          $t3, 0x14($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X14);
    // 0x80017928: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001792C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80017930: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80017934: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80017938: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001793C: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x80017940: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80017944: mul.d       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80017948: nop

    // 0x8001794C: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80017950: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80017954: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
L_80017958:
    // 0x80017958: b           L_80018488
    // 0x8001795C: addiu       $v1, $zero, 0xD7
    ctx->r3 = ADD32(0, 0XD7);
        goto L_80018488;
    // 0x8001795C: addiu       $v1, $zero, 0xD7
    ctx->r3 = ADD32(0, 0XD7);
L_80017960:
    // 0x80017960: beq         $a3, $zero, L_800179A4
    if (ctx->r7 == 0) {
        // 0x80017964: nop
    
            goto L_800179A4;
    }
    // 0x80017964: nop

    // 0x80017968: lw          $t4, 0x14($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X14);
    // 0x8001796C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80017970: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80017974: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80017978: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001797C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80017980: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80017984: ldc1        $f8, -0x1050($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1050);
    // 0x80017988: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001798C: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80017990: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80017994: add.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f18.d + ctx->f8.d;
    // 0x80017998: mul.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x8001799C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800179A0: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
L_800179A4:
    // 0x800179A4: b           L_80018488
    // 0x800179A8: addiu       $v1, $zero, 0x1A2
    ctx->r3 = ADD32(0, 0X1A2);
        goto L_80018488;
    // 0x800179A8: addiu       $v1, $zero, 0x1A2
    ctx->r3 = ADD32(0, 0X1A2);
L_800179AC:
    // 0x800179AC: b           L_80018488
    // 0x800179B0: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
        goto L_80018488;
    // 0x800179B0: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
L_800179B4:
    // 0x800179B4: addiu       $v1, $zero, 0x10A
    ctx->r3 = ADD32(0, 0X10A);
    // 0x800179B8: b           L_80018488
    // 0x800179BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x800179BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800179C0:
    // 0x800179C0: b           L_80018488
    // 0x800179C4: addiu       $v1, $zero, 0x126
    ctx->r3 = ADD32(0, 0X126);
        goto L_80018488;
    // 0x800179C4: addiu       $v1, $zero, 0x126
    ctx->r3 = ADD32(0, 0X126);
L_800179C8:
    // 0x800179C8: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x800179CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800179D0: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x800179D4: sh          $t0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r8;
    // 0x800179D8: jal         0x80011928
    // 0x800179DC: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    func_80011928(rdram, ctx);
        goto after_2;
    // 0x800179DC: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x800179E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800179E4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800179E8: lh          $t0, 0x4E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4E);
    // 0x800179EC: bne         $v0, $at, L_80017A14
    if (ctx->r2 != ctx->r1) {
        // 0x800179F0: lwc1        $f14, 0x58($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80017A14;
    }
    // 0x800179F0: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800179F4: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800179F8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800179FC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80017A00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80017A04: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80017A08: mul.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80017A0C: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80017A10: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
L_80017A14:
    // 0x80017A14: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80017A18: sh          $t5, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r13;
    // 0x80017A1C: b           L_80018488
    // 0x80017A20: addiu       $v1, $zero, 0x136
    ctx->r3 = ADD32(0, 0X136);
        goto L_80018488;
    // 0x80017A20: addiu       $v1, $zero, 0x136
    ctx->r3 = ADD32(0, 0X136);
L_80017A24:
    // 0x80017A24: b           L_80018488
    // 0x80017A28: addiu       $v1, $zero, 0x146
    ctx->r3 = ADD32(0, 0X146);
        goto L_80018488;
    // 0x80017A28: addiu       $v1, $zero, 0x146
    ctx->r3 = ADD32(0, 0X146);
L_80017A2C:
    // 0x80017A2C: beql        $a3, $zero, L_80017AF0
    if (ctx->r7 == 0) {
        // 0x80017A30: addiu       $v1, $zero, 0x250
        ctx->r3 = ADD32(0, 0X250);
            goto L_80017AF0;
    }
    goto skip_0;
    // 0x80017A30: addiu       $v1, $zero, 0x250
    ctx->r3 = ADD32(0, 0X250);
    skip_0:
    // 0x80017A34: lw          $t6, 0x14($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X14);
    // 0x80017A38: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    // 0x80017A3C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80017A40: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80017A44: jal         0x80011CF0
    // 0x80017A48: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    func_80011CF0(rdram, ctx);
        goto after_3;
    // 0x80017A48: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    after_3:
    // 0x80017A4C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80017A50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017A54: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80017A58: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80017A5C: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80017A60: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80017A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80017A68: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80017A6C: bc1fl       L_80017AD0
    if (!c1cs) {
        // 0x80017A70: sw          $a3, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r7;
            goto L_80017AD0;
    }
    goto skip_1;
    // 0x80017A70: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    skip_1:
    // 0x80017A74: lh          $t7, -0x6D44($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6D44);
    // 0x80017A78: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80017A7C: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    // 0x80017A80: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80017A84: jal         0x80011CF0
    // 0x80017A88: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_80011CF0(rdram, ctx);
        goto after_4;
    // 0x80017A88: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_4:
    // 0x80017A8C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80017A90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017A94: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80017A98: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80017A9C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80017AA0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80017AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80017AA8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80017AAC: bc1fl       L_80017AE4
    if (!c1cs) {
        // 0x80017AB0: lw          $t8, 0x14($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X14);
            goto L_80017AE4;
    }
    goto skip_2;
    // 0x80017AB0: lw          $t8, 0x14($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X14);
    skip_2:
    // 0x80017AB4: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80017AB8: jal         0x80015E74
    // 0x80017ABC: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    func_80015E74(rdram, ctx);
        goto after_5;
    // 0x80017ABC: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x80017AC0: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80017AC4: b           L_80017AE0
    // 0x80017AC8: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
        goto L_80017AE0;
    // 0x80017AC8: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80017ACC: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
L_80017AD0:
    // 0x80017AD0: jal         0x80011990
    // 0x80017AD4: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    func_80011990(rdram, ctx);
        goto after_6;
    // 0x80017AD4: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    after_6:
    // 0x80017AD8: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80017ADC: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
L_80017AE0:
    // 0x80017AE0: lw          $t8, 0x14($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X14);
L_80017AE4:
    // 0x80017AE4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80017AE8: sh          $t8, -0x6D44($at)
    MEM_H(-0X6D44, ctx->r1) = ctx->r24;
    // 0x80017AEC: addiu       $v1, $zero, 0x250
    ctx->r3 = ADD32(0, 0X250);
L_80017AF0:
    // 0x80017AF0: b           L_80018488
    // 0x80017AF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80017AF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80017AF8:
    // 0x80017AF8: b           L_80018488
    // 0x80017AFC: addiu       $v1, $zero, 0x262
    ctx->r3 = ADD32(0, 0X262);
        goto L_80018488;
    // 0x80017AFC: addiu       $v1, $zero, 0x262
    ctx->r3 = ADD32(0, 0X262);
L_80017B00:
    // 0x80017B00: b           L_80018488
    // 0x80017B04: addiu       $v1, $zero, 0x263
    ctx->r3 = ADD32(0, 0X263);
        goto L_80018488;
    // 0x80017B04: addiu       $v1, $zero, 0x263
    ctx->r3 = ADD32(0, 0X263);
L_80017B08:
    // 0x80017B08: b           L_80018488
    // 0x80017B0C: addiu       $v1, $zero, 0x12F
    ctx->r3 = ADD32(0, 0X12F);
        goto L_80018488;
    // 0x80017B0C: addiu       $v1, $zero, 0x12F
    ctx->r3 = ADD32(0, 0X12F);
L_80017B10:
    // 0x80017B10: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80017B14: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80017B18: b           L_80018488
    // 0x80017B1C: addiu       $v1, $zero, 0x168
    ctx->r3 = ADD32(0, 0X168);
        goto L_80018488;
    // 0x80017B1C: addiu       $v1, $zero, 0x168
    ctx->r3 = ADD32(0, 0X168);
L_80017B20:
    // 0x80017B20: beql        $a3, $zero, L_80017C0C
    if (ctx->r7 == 0) {
        // 0x80017B24: addiu       $v1, $zero, 0x250
        ctx->r3 = ADD32(0, 0X250);
            goto L_80017C0C;
    }
    goto skip_3;
    // 0x80017B24: addiu       $v1, $zero, 0x250
    ctx->r3 = ADD32(0, 0X250);
    skip_3:
    // 0x80017B28: lw          $t1, 0x14($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X14);
    // 0x80017B2C: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    // 0x80017B30: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80017B34: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80017B38: jal         0x80011CF0
    // 0x80017B3C: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    func_80011CF0(rdram, ctx);
        goto after_7;
    // 0x80017B3C: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_7:
    // 0x80017B40: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80017B44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017B48: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80017B4C: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80017B50: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80017B54: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80017B58: bc1fl       L_80017BB4
    if (!c1cs) {
        // 0x80017B5C: lw          $t3, 0x14($a3)
        ctx->r11 = MEM_W(ctx->r7, 0X14);
            goto L_80017BB4;
    }
    goto skip_4;
    // 0x80017B5C: lw          $t3, 0x14($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X14);
    skip_4:
    // 0x80017B60: lh          $t2, -0x6D40($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X6D40);
    // 0x80017B64: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80017B68: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    // 0x80017B6C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80017B70: jal         0x80011CF0
    // 0x80017B74: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    func_80011CF0(rdram, ctx);
        goto after_8;
    // 0x80017B74: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    after_8:
    // 0x80017B78: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80017B7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017B80: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80017B84: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80017B88: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80017B8C: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    // 0x80017B90: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80017B94: bc1fl       L_80017BB4
    if (!c1cs) {
        // 0x80017B98: lw          $t3, 0x14($a3)
        ctx->r11 = MEM_W(ctx->r7, 0X14);
            goto L_80017BB4;
    }
    goto skip_5;
    // 0x80017B98: lw          $t3, 0x14($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X14);
    skip_5:
    // 0x80017B9C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80017BA0: jal         0x80011D1C
    // 0x80017BA4: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    func_80011D1C(rdram, ctx);
        goto after_9;
    // 0x80017BA4: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    after_9:
    // 0x80017BA8: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80017BAC: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80017BB0: lw          $t3, 0x14($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X14);
L_80017BB4:
    // 0x80017BB4: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    // 0x80017BB8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80017BBC: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80017BC0: jal         0x80011CF0
    // 0x80017BC4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_80011CF0(rdram, ctx);
        goto after_10;
    // 0x80017BC4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_10:
    // 0x80017BC8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80017BCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017BD0: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80017BD4: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80017BD8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80017BDC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80017BE0: bc1fl       L_80017C00
    if (!c1cs) {
        // 0x80017BE4: lw          $t4, 0x14($a3)
        ctx->r12 = MEM_W(ctx->r7, 0X14);
            goto L_80017C00;
    }
    goto skip_6;
    // 0x80017BE4: lw          $t4, 0x14($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X14);
    skip_6:
    // 0x80017BE8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80017BEC: jal         0x80010A74
    // 0x80017BF0: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    func_80010A74(rdram, ctx);
        goto after_11;
    // 0x80017BF0: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    after_11:
    // 0x80017BF4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80017BF8: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80017BFC: lw          $t4, 0x14($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X14);
L_80017C00:
    // 0x80017C00: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80017C04: sh          $t4, -0x6D40($at)
    MEM_H(-0X6D40, ctx->r1) = ctx->r12;
    // 0x80017C08: addiu       $v1, $zero, 0x250
    ctx->r3 = ADD32(0, 0X250);
L_80017C0C:
    // 0x80017C0C: b           L_80018488
    // 0x80017C10: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80017C10: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80017C14:
    // 0x80017C14: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80017C18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80017C1C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80017C20: sh          $t0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r8;
    // 0x80017C24: jal         0x80011928
    // 0x80017C28: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    func_80011928(rdram, ctx);
        goto after_12;
    // 0x80017C28: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    after_12:
    // 0x80017C2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80017C30: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80017C34: lh          $t0, 0x4E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4E);
    // 0x80017C38: bne         $v0, $at, L_80017C60
    if (ctx->r2 != ctx->r1) {
        // 0x80017C3C: lwc1        $f14, 0x58($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80017C60;
    }
    // 0x80017C3C: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80017C40: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80017C44: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80017C48: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80017C4C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80017C50: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80017C54: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80017C58: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80017C5C: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
L_80017C60:
    // 0x80017C60: b           L_80018488
    // 0x80017C64: addiu       $v1, $zero, 0x19E
    ctx->r3 = ADD32(0, 0X19E);
        goto L_80018488;
    // 0x80017C64: addiu       $v1, $zero, 0x19E
    ctx->r3 = ADD32(0, 0X19E);
L_80017C68:
    // 0x80017C68: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80017C6C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80017C70: ldc1        $f10, -0x1048($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1048);
    // 0x80017C74: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80017C78: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80017C7C: mul.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80017C80: sh          $t5, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r13;
    // 0x80017C84: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
    // 0x80017C88: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x80017C8C: b           L_80018488
    // 0x80017C90: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
        goto L_80018488;
    // 0x80017C90: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
L_80017C94:
    // 0x80017C94: beq         $a3, $zero, L_80017CD0
    if (ctx->r7 == 0) {
        // 0x80017C98: nop
    
            goto L_80017CD0;
    }
    // 0x80017C98: nop

    // 0x80017C9C: lw          $t6, 0x14($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X14);
    // 0x80017CA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80017CA4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80017CA8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80017CAC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80017CB0: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80017CB4: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80017CB8: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80017CBC: mul.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80017CC0: nop

    // 0x80017CC4: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80017CC8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80017CCC: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
L_80017CD0:
    // 0x80017CD0: b           L_80018488
    // 0x80017CD4: addiu       $v1, $zero, 0x49
    ctx->r3 = ADD32(0, 0X49);
        goto L_80018488;
    // 0x80017CD4: addiu       $v1, $zero, 0x49
    ctx->r3 = ADD32(0, 0X49);
L_80017CD8:
    // 0x80017CD8: b           L_80018488
    // 0x80017CDC: addiu       $v1, $zero, 0x1E6
    ctx->r3 = ADD32(0, 0X1E6);
        goto L_80018488;
    // 0x80017CDC: addiu       $v1, $zero, 0x1E6
    ctx->r3 = ADD32(0, 0X1E6);
L_80017CE0:
    // 0x80017CE0: addiu       $v1, $zero, 0x128
    ctx->r3 = ADD32(0, 0X128);
    // 0x80017CE4: b           L_80018488
    // 0x80017CE8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80017CE8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80017CEC:
    // 0x80017CEC: addiu       $v1, $zero, 0x1A6
    ctx->r3 = ADD32(0, 0X1A6);
    // 0x80017CF0: b           L_80018488
    // 0x80017CF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80017CF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80017CF8:
    // 0x80017CF8: addiu       $v1, $zero, 0x154
    ctx->r3 = ADD32(0, 0X154);
    // 0x80017CFC: b           L_80018488
    // 0x80017D00: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80017D00: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80017D04:
    // 0x80017D04: b           L_80018488
    // 0x80017D08: addiu       $v1, $zero, 0x1B1
    ctx->r3 = ADD32(0, 0X1B1);
        goto L_80018488;
    // 0x80017D08: addiu       $v1, $zero, 0x1B1
    ctx->r3 = ADD32(0, 0X1B1);
L_80017D0C:
    // 0x80017D0C: beql        $a3, $zero, L_80017E00
    if (ctx->r7 == 0) {
        // 0x80017D10: addiu       $v1, $zero, 0x241
        ctx->r3 = ADD32(0, 0X241);
            goto L_80017E00;
    }
    goto skip_7;
    // 0x80017D10: addiu       $v1, $zero, 0x241
    ctx->r3 = ADD32(0, 0X241);
    skip_7:
    // 0x80017D14: lw          $t7, 0x14($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X14);
    // 0x80017D18: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x80017D1C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80017D20: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80017D24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80017D28: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80017D2C: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80017D30: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80017D34: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80017D38: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80017D3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80017D40: mul.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80017D44: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80017D48: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80017D4C: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80017D50: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80017D54: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    // 0x80017D58: lw          $t8, 0x14($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X14);
    // 0x80017D5C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80017D60: nop

    // 0x80017D64: cvt.d.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.d = CVT_D_W(ctx->f8.u32l);
    // 0x80017D68: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x80017D6C: nop

    // 0x80017D70: bc1fl       L_80017E00
    if (!c1cs) {
        // 0x80017D74: addiu       $v1, $zero, 0x241
        ctx->r3 = ADD32(0, 0X241);
            goto L_80017E00;
    }
    goto skip_8;
    // 0x80017D74: addiu       $v1, $zero, 0x241
    ctx->r3 = ADD32(0, 0X241);
    skip_8:
    // 0x80017D78: lw          $v0, 0x6BA4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6BA4);
    // 0x80017D7C: ldc1        $f10, -0x1040($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1040);
    // 0x80017D80: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80017D84: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x80017D88: sub.d       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f2.d - ctx->f0.d;
    // 0x80017D8C: mfhi        $t1
    ctx->r9 = hi;
    // 0x80017D90: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x80017D94: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x80017D98: div.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f2.d);
    // 0x80017D9C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80017DA0: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80017DA4: trunc.w.d   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_D(ctx->f16.d);
    // 0x80017DA8: bne         $t1, $at, L_80017DCC
    if (ctx->r9 != ctx->r1) {
        // 0x80017DAC: swc1        $f18, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
            goto L_80017DCC;
    }
    // 0x80017DAC: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x80017DB0: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80017DB4: jal         0x80011D1C
    // 0x80017DB8: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    func_80011D1C(rdram, ctx);
        goto after_13;
    // 0x80017DB8: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    after_13:
    // 0x80017DBC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80017DC0: lw          $v0, 0x6BA4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6BA4);
    // 0x80017DC4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80017DC8: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
L_80017DCC:
    // 0x80017DCC: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80017DD0: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x80017DD4: mfhi        $t2
    ctx->r10 = hi;
    // 0x80017DD8: addiu       $at, $zero, 0xC7
    ctx->r1 = ADD32(0, 0XC7);
    // 0x80017DDC: bne         $t2, $at, L_80017DFC
    if (ctx->r10 != ctx->r1) {
        // 0x80017DE0: addiu       $a0, $zero, 0xD3
        ctx->r4 = ADD32(0, 0XD3);
            goto L_80017DFC;
    }
    // 0x80017DE0: addiu       $a0, $zero, 0xD3
    ctx->r4 = ADD32(0, 0XD3);
    // 0x80017DE4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80017DE8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80017DEC: jal         0x80011D1C
    // 0x80017DF0: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    func_80011D1C(rdram, ctx);
        goto after_14;
    // 0x80017DF0: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    after_14:
    // 0x80017DF4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80017DF8: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
L_80017DFC:
    // 0x80017DFC: addiu       $v1, $zero, 0x241
    ctx->r3 = ADD32(0, 0X241);
L_80017E00:
    // 0x80017E00: b           L_80018488
    // 0x80017E04: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80017E04: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80017E08:
    // 0x80017E08: b           L_80018488
    // 0x80017E0C: addiu       $v1, $zero, 0x1D8
    ctx->r3 = ADD32(0, 0X1D8);
        goto L_80018488;
    // 0x80017E0C: addiu       $v1, $zero, 0x1D8
    ctx->r3 = ADD32(0, 0X1D8);
L_80017E10:
    // 0x80017E10: b           L_80018488
    // 0x80017E14: addiu       $v1, $zero, 0x1D9
    ctx->r3 = ADD32(0, 0X1D9);
        goto L_80018488;
    // 0x80017E14: addiu       $v1, $zero, 0x1D9
    ctx->r3 = ADD32(0, 0X1D9);
L_80017E18:
    // 0x80017E18: b           L_80018488
    // 0x80017E1C: addiu       $v1, $zero, 0x1DB
    ctx->r3 = ADD32(0, 0X1DB);
        goto L_80018488;
    // 0x80017E1C: addiu       $v1, $zero, 0x1DB
    ctx->r3 = ADD32(0, 0X1DB);
L_80017E20:
    // 0x80017E20: b           L_80018488
    // 0x80017E24: addiu       $v1, $zero, 0x1DA
    ctx->r3 = ADD32(0, 0X1DA);
        goto L_80018488;
    // 0x80017E24: addiu       $v1, $zero, 0x1DA
    ctx->r3 = ADD32(0, 0X1DA);
L_80017E28:
    // 0x80017E28: beq         $a3, $zero, L_80017EA4
    if (ctx->r7 == 0) {
        // 0x80017E2C: nop
    
            goto L_80017EA4;
    }
    // 0x80017E2C: nop

    // 0x80017E30: lw          $t3, 0x14($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X14);
    // 0x80017E34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80017E38: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80017E3C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80017E40: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80017E44: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80017E48: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x80017E4C: lui         $at, 0x3F60
    ctx->r1 = S32(0X3F60 << 16);
    // 0x80017E50: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80017E54: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80017E58: nop

    // 0x80017E5C: mul.d       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x80017E60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80017E64: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80017E68: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x80017E6C: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80017E70: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80017E74: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x80017E78: lw          $t4, 0x18($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X18);
    // 0x80017E7C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80017E80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80017E84: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80017E88: nop

    // 0x80017E8C: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80017E90: mul.d       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x80017E94: add.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d + ctx->f4.d;
    // 0x80017E98: mul.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80017E9C: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x80017EA0: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
L_80017EA4:
    // 0x80017EA4: b           L_80018488
    // 0x80017EA8: addiu       $v1, $zero, 0x1BD
    ctx->r3 = ADD32(0, 0X1BD);
        goto L_80018488;
    // 0x80017EA8: addiu       $v1, $zero, 0x1BD
    ctx->r3 = ADD32(0, 0X1BD);
L_80017EAC:
    // 0x80017EAC: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80017EB0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80017EB4: ldc1        $f6, -0x1038($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1038);
    // 0x80017EB8: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80017EBC: addiu       $v1, $zero, 0x8B
    ctx->r3 = ADD32(0, 0X8B);
    // 0x80017EC0: mul.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80017EC4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80017EC8: b           L_80018488
    // 0x80017ECC: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
        goto L_80018488;
    // 0x80017ECC: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
L_80017ED0:
    // 0x80017ED0: b           L_80018488
    // 0x80017ED4: addiu       $v1, $zero, 0x1DC
    ctx->r3 = ADD32(0, 0X1DC);
        goto L_80018488;
    // 0x80017ED4: addiu       $v1, $zero, 0x1DC
    ctx->r3 = ADD32(0, 0X1DC);
L_80017ED8:
    // 0x80017ED8: beq         $a3, $zero, L_80017F14
    if (ctx->r7 == 0) {
        // 0x80017EDC: nop
    
            goto L_80017F14;
    }
    // 0x80017EDC: nop

    // 0x80017EE0: lw          $t5, 0x14($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X14);
    // 0x80017EE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80017EE8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80017EEC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80017EF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80017EF4: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80017EF8: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x80017EFC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80017F00: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80017F04: nop

    // 0x80017F08: mul.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x80017F0C: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80017F10: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
L_80017F14:
    // 0x80017F14: b           L_80018488
    // 0x80017F18: addiu       $v1, $zero, 0x1DD
    ctx->r3 = ADD32(0, 0X1DD);
        goto L_80018488;
    // 0x80017F18: addiu       $v1, $zero, 0x1DD
    ctx->r3 = ADD32(0, 0X1DD);
L_80017F1C:
    // 0x80017F1C: beq         $a3, $zero, L_80017F60
    if (ctx->r7 == 0) {
        // 0x80017F20: nop
    
            goto L_80017F60;
    }
    // 0x80017F20: nop

    // 0x80017F24: lw          $t6, 0x14($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X14);
    // 0x80017F28: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x80017F2C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80017F30: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80017F34: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80017F38: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80017F3C: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x80017F40: ldc1        $f10, -0x1030($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1030);
    // 0x80017F44: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80017F48: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80017F4C: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80017F50: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80017F54: mul.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x80017F58: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80017F5C: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
L_80017F60:
    // 0x80017F60: b           L_80018488
    // 0x80017F64: addiu       $v1, $zero, 0x1DE
    ctx->r3 = ADD32(0, 0X1DE);
        goto L_80018488;
    // 0x80017F64: addiu       $v1, $zero, 0x1DE
    ctx->r3 = ADD32(0, 0X1DE);
L_80017F68:
    // 0x80017F68: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80017F6C: sh          $t7, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r15;
    // 0x80017F70: b           L_80018488
    // 0x80017F74: addiu       $v1, $zero, 0x42
    ctx->r3 = ADD32(0, 0X42);
        goto L_80018488;
    // 0x80017F74: addiu       $v1, $zero, 0x42
    ctx->r3 = ADD32(0, 0X42);
L_80017F78:
    // 0x80017F78: addiu       $v1, $zero, 0x241
    ctx->r3 = ADD32(0, 0X241);
    // 0x80017F7C: b           L_80018488
    // 0x80017F80: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80017F80: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80017F84:
    // 0x80017F84: b           L_80018488
    // 0x80017F88: addiu       $v1, $zero, 0x219
    ctx->r3 = ADD32(0, 0X219);
        goto L_80018488;
    // 0x80017F88: addiu       $v1, $zero, 0x219
    ctx->r3 = ADD32(0, 0X219);
L_80017F8C:
    // 0x80017F8C: addiu       $v1, $zero, 0x1E7
    ctx->r3 = ADD32(0, 0X1E7);
    // 0x80017F90: b           L_80018488
    // 0x80017F94: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80017F94: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80017F98:
    // 0x80017F98: beq         $a3, $zero, L_80017FE0
    if (ctx->r7 == 0) {
        // 0x80017F9C: nop
    
            goto L_80017FE0;
    }
    // 0x80017F9C: nop

    // 0x80017FA0: lw          $t8, 0x14($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X14);
    // 0x80017FA4: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x80017FA8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80017FAC: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80017FB0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80017FB4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80017FB8: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x80017FBC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80017FC0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80017FC4: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80017FC8: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80017FCC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80017FD0: add.d       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f8.d + ctx->f18.d;
    // 0x80017FD4: mul.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80017FD8: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x80017FDC: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
L_80017FE0:
    // 0x80017FE0: b           L_80018488
    // 0x80017FE4: addiu       $v1, $zero, 0x1E4
    ctx->r3 = ADD32(0, 0X1E4);
        goto L_80018488;
    // 0x80017FE4: addiu       $v1, $zero, 0x1E4
    ctx->r3 = ADD32(0, 0X1E4);
L_80017FE8:
    // 0x80017FE8: b           L_80018488
    // 0x80017FEC: addiu       $v1, $zero, 0x1EB
    ctx->r3 = ADD32(0, 0X1EB);
        goto L_80018488;
    // 0x80017FEC: addiu       $v1, $zero, 0x1EB
    ctx->r3 = ADD32(0, 0X1EB);
L_80017FF0:
    // 0x80017FF0: beq         $a3, $zero, L_8001802C
    if (ctx->r7 == 0) {
        // 0x80017FF4: nop
    
            goto L_8001802C;
    }
    // 0x80017FF4: nop

    // 0x80017FF8: lw          $t9, 0x14($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X14);
    // 0x80017FFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018000: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80018004: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80018008: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001800C: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80018010: cvt.d.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.d = CVT_D_W(ctx->f18.u32l);
    // 0x80018014: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80018018: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8001801C: nop

    // 0x80018020: mul.d       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x80018024: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x80018028: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
L_8001802C:
    // 0x8001802C: b           L_80018488
    // 0x80018030: addiu       $v1, $zero, 0x1EE
    ctx->r3 = ADD32(0, 0X1EE);
        goto L_80018488;
    // 0x80018030: addiu       $v1, $zero, 0x1EE
    ctx->r3 = ADD32(0, 0X1EE);
L_80018034:
    // 0x80018034: b           L_80018488
    // 0x80018038: addiu       $v1, $zero, 0x1F9
    ctx->r3 = ADD32(0, 0X1F9);
        goto L_80018488;
    // 0x80018038: addiu       $v1, $zero, 0x1F9
    ctx->r3 = ADD32(0, 0X1F9);
L_8001803C:
    // 0x8001803C: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80018040: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80018044: ldc1        $f8, -0x1028($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1028);
    // 0x80018048: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8001804C: addiu       $v1, $zero, 0x1F9
    ctx->r3 = ADD32(0, 0X1F9);
    // 0x80018050: mul.d       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x80018054: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x80018058: b           L_80018488
    // 0x8001805C: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
        goto L_80018488;
    // 0x8001805C: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
L_80018060:
    // 0x80018060: beq         $a3, $zero, L_8001809C
    if (ctx->r7 == 0) {
        // 0x80018064: nop
    
            goto L_8001809C;
    }
    // 0x80018064: nop

    // 0x80018068: lw          $t1, 0x14($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X14);
    // 0x8001806C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018070: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80018074: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80018078: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001807C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80018080: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x80018084: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x80018088: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8001808C: nop

    // 0x80018090: mul.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80018094: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80018098: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
L_8001809C:
    // 0x8001809C: b           L_80018488
    // 0x800180A0: addiu       $v1, $zero, 0x1FA
    ctx->r3 = ADD32(0, 0X1FA);
        goto L_80018488;
    // 0x800180A0: addiu       $v1, $zero, 0x1FA
    ctx->r3 = ADD32(0, 0X1FA);
L_800180A4:
    // 0x800180A4: beq         $a3, $zero, L_80018100
    if (ctx->r7 == 0) {
        // 0x800180A8: nop
    
            goto L_80018100;
    }
    // 0x800180A8: nop

    // 0x800180AC: lw          $t2, 0x14($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X14);
    // 0x800180B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800180B4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800180B8: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800180BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800180C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800180C4: cvt.d.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.d = CVT_D_W(ctx->f16.u32l);
    // 0x800180C8: ldc1        $f10, -0x1020($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1020);
    // 0x800180CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800180D0: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800180D4: mul.d       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x800180D8: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800180DC: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x800180E0: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x800180E4: ldc1        $f10, -0x1018($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1018);
    // 0x800180E8: add.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d + ctx->f4.d;
    // 0x800180EC: mul.d       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x800180F0: cvt.s.d     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f14.fl = CVT_S_D(ctx->f16.d);
    // 0x800180F4: add.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f18.d + ctx->f8.d;
    // 0x800180F8: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x800180FC: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
L_80018100:
    // 0x80018100: b           L_80018488
    // 0x80018104: addiu       $v1, $zero, 0x48
    ctx->r3 = ADD32(0, 0X48);
        goto L_80018488;
    // 0x80018104: addiu       $v1, $zero, 0x48
    ctx->r3 = ADD32(0, 0X48);
L_80018108:
    // 0x80018108: b           L_80018488
    // 0x8001810C: addiu       $v1, $zero, 0x209
    ctx->r3 = ADD32(0, 0X209);
        goto L_80018488;
    // 0x8001810C: addiu       $v1, $zero, 0x209
    ctx->r3 = ADD32(0, 0X209);
L_80018110:
    // 0x80018110: beq         $a3, $zero, L_8001814C
    if (ctx->r7 == 0) {
        // 0x80018114: nop
    
            goto L_8001814C;
    }
    // 0x80018114: nop

    // 0x80018118: lw          $t3, 0x14($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X14);
    // 0x8001811C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018120: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80018124: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80018128: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001812C: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80018130: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80018134: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80018138: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8001813C: nop

    // 0x80018140: mul.d       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x80018144: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80018148: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
L_8001814C:
    // 0x8001814C: b           L_80018488
    // 0x80018150: addiu       $v1, $zero, 0x20A
    ctx->r3 = ADD32(0, 0X20A);
        goto L_80018488;
    // 0x80018150: addiu       $v1, $zero, 0x20A
    ctx->r3 = ADD32(0, 0X20A);
L_80018154:
    // 0x80018154: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80018158: sh          $t4, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r12;
    // 0x8001815C: b           L_80018488
    // 0x80018160: addiu       $v1, $zero, 0x216
    ctx->r3 = ADD32(0, 0X216);
        goto L_80018488;
    // 0x80018160: addiu       $v1, $zero, 0x216
    ctx->r3 = ADD32(0, 0X216);
L_80018164:
    // 0x80018164: b           L_80018488
    // 0x80018168: addiu       $v1, $zero, 0x1EB
    ctx->r3 = ADD32(0, 0X1EB);
        goto L_80018488;
    // 0x80018168: addiu       $v1, $zero, 0x1EB
    ctx->r3 = ADD32(0, 0X1EB);
L_8001816C:
    // 0x8001816C: b           L_80018488
    // 0x80018170: addiu       $v1, $zero, 0x23A
    ctx->r3 = ADD32(0, 0X23A);
        goto L_80018488;
    // 0x80018170: addiu       $v1, $zero, 0x23A
    ctx->r3 = ADD32(0, 0X23A);
L_80018174:
    // 0x80018174: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80018178: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x8001817C: beq         $v0, $zero, L_80018194
    if (ctx->r2 == 0) {
        // 0x80018180: nop
    
            goto L_80018194;
    }
    // 0x80018180: nop

    // 0x80018184: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x80018188: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x8001818C: beql        $t5, $at, L_800186D0
    if (ctx->r13 == ctx->r1) {
        // 0x80018190: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800186D0;
    }
    goto skip_9;
    // 0x80018190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
L_80018194:
    // 0x80018194: beq         $a3, $zero, L_800181D8
    if (ctx->r7 == 0) {
        // 0x80018198: nop
    
            goto L_800181D8;
    }
    // 0x80018198: nop

    // 0x8001819C: lw          $t6, 0x14($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X14);
    // 0x800181A0: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x800181A4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800181A8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800181AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800181B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800181B4: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800181B8: ldc1        $f6, -0x1010($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1010);
    // 0x800181BC: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800181C0: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800181C4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800181C8: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x800181CC: mul.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800181D0: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x800181D4: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
L_800181D8:
    // 0x800181D8: b           L_80018488
    // 0x800181DC: addiu       $v1, $zero, 0x136
    ctx->r3 = ADD32(0, 0X136);
        goto L_80018488;
    // 0x800181DC: addiu       $v1, $zero, 0x136
    ctx->r3 = ADD32(0, 0X136);
L_800181E0:
    // 0x800181E0: b           L_80018488
    // 0x800181E4: addiu       $v1, $zero, 0x246
    ctx->r3 = ADD32(0, 0X246);
        goto L_80018488;
    // 0x800181E4: addiu       $v1, $zero, 0x246
    ctx->r3 = ADD32(0, 0X246);
L_800181E8:
    // 0x800181E8: addiu       $v1, $zero, 0x244
    ctx->r3 = ADD32(0, 0X244);
    // 0x800181EC: b           L_80018488
    // 0x800181F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x800181F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800181F4:
    // 0x800181F4: addiu       $v1, $zero, 0x245
    ctx->r3 = ADD32(0, 0X245);
    // 0x800181F8: b           L_80018488
    // 0x800181FC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x800181FC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80018200:
    // 0x80018200: b           L_80018488
    // 0x80018204: addiu       $v1, $zero, 0x249
    ctx->r3 = ADD32(0, 0X249);
        goto L_80018488;
    // 0x80018204: addiu       $v1, $zero, 0x249
    ctx->r3 = ADD32(0, 0X249);
L_80018208:
    // 0x80018208: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001820C: sh          $t7, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r15;
    // 0x80018210: b           L_80018488
    // 0x80018214: addiu       $v1, $zero, 0x136
    ctx->r3 = ADD32(0, 0X136);
        goto L_80018488;
    // 0x80018214: addiu       $v1, $zero, 0x136
    ctx->r3 = ADD32(0, 0X136);
L_80018218:
    // 0x80018218: b           L_80018488
    // 0x8001821C: addiu       $v1, $zero, 0x25C
    ctx->r3 = ADD32(0, 0X25C);
        goto L_80018488;
    // 0x8001821C: addiu       $v1, $zero, 0x25C
    ctx->r3 = ADD32(0, 0X25C);
L_80018220:
    // 0x80018220: addiu       $v1, $zero, 0x256
    ctx->r3 = ADD32(0, 0X256);
    // 0x80018224: b           L_80018488
    // 0x80018228: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80018228: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001822C:
    // 0x8001822C: addiu       $v1, $zero, 0x256
    ctx->r3 = ADD32(0, 0X256);
    // 0x80018230: b           L_80018488
    // 0x80018234: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80018234: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80018238:
    // 0x80018238: addiu       $v1, $zero, 0x1EF
    ctx->r3 = ADD32(0, 0X1EF);
    // 0x8001823C: b           L_80018488
    // 0x80018240: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80018240: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80018244:
    // 0x80018244: addiu       $v1, $zero, 0x1F0
    ctx->r3 = ADD32(0, 0X1F0);
    // 0x80018248: b           L_80018488
    // 0x8001824C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x8001824C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80018250:
    // 0x80018250: addiu       $v1, $zero, 0x1F1
    ctx->r3 = ADD32(0, 0X1F1);
    // 0x80018254: b           L_80018488
    // 0x80018258: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80018258: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001825C:
    // 0x8001825C: addiu       $v1, $zero, 0x1F2
    ctx->r3 = ADD32(0, 0X1F2);
    // 0x80018260: b           L_80018488
    // 0x80018264: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80018264: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80018268:
    // 0x80018268: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001826C: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80018270: beq         $v0, $zero, L_800182A4
    if (ctx->r2 == 0) {
        // 0x80018274: nop
    
            goto L_800182A4;
    }
    // 0x80018274: nop

    // 0x80018278: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8001827C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80018280: ldc1        $f6, -0x1008($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1008);
    // 0x80018284: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80018288: addiu       $v1, $zero, 0x28F
    ctx->r3 = ADD32(0, 0X28F);
    // 0x8001828C: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x80018290: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80018294: bc1f        L_800182A4
    if (!c1cs) {
        // 0x80018298: nop
    
            goto L_800182A4;
    }
    // 0x80018298: nop

    // 0x8001829C: b           L_80018488
    // 0x800182A0: addiu       $v1, $zero, 0x20E
    ctx->r3 = ADD32(0, 0X20E);
        goto L_80018488;
    // 0x800182A0: addiu       $v1, $zero, 0x20E
    ctx->r3 = ADD32(0, 0X20E);
L_800182A4:
    // 0x800182A4: b           L_80018488
    // 0x800182A8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x800182A8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800182AC:
    // 0x800182AC: addiu       $a0, $zero, 0x292
    ctx->r4 = ADD32(0, 0X292);
    // 0x800182B0: jal         0x80011D1C
    // 0x800182B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_15;
    // 0x800182B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x800182B8: b           L_800186D0
    // 0x800182BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800186D0;
    // 0x800182BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800182C0:
    // 0x800182C0: addiu       $a0, $zero, 0x293
    ctx->r4 = ADD32(0, 0X293);
    // 0x800182C4: jal         0x80011D1C
    // 0x800182C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_16;
    // 0x800182C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x800182CC: b           L_800186D0
    // 0x800182D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800186D0;
    // 0x800182D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800182D4:
    // 0x800182D4: addiu       $v1, $zero, 0x25D
    ctx->r3 = ADD32(0, 0X25D);
    // 0x800182D8: b           L_80018488
    // 0x800182DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x800182DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800182E0:
    // 0x800182E0: addiu       $v1, $zero, 0x261
    ctx->r3 = ADD32(0, 0X261);
    // 0x800182E4: b           L_80018488
    // 0x800182E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x800182E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800182EC:
    // 0x800182EC: addiu       $v1, $zero, 0x159
    ctx->r3 = ADD32(0, 0X159);
    // 0x800182F0: b           L_80018488
    // 0x800182F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x800182F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800182F8:
    // 0x800182F8: addiu       $v1, $zero, 0x15A
    ctx->r3 = ADD32(0, 0X15A);
    // 0x800182FC: b           L_80018488
    // 0x80018300: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80018300: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80018304:
    // 0x80018304: addiu       $v1, $zero, 0x23D
    ctx->r3 = ADD32(0, 0X23D);
    // 0x80018308: b           L_80018488
    // 0x8001830C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x8001830C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80018310:
    // 0x80018310: addiu       $v1, $zero, 0x23E
    ctx->r3 = ADD32(0, 0X23E);
    // 0x80018314: b           L_80018488
    // 0x80018318: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80018488;
    // 0x80018318: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001831C:
    // 0x8001831C: beq         $a3, $zero, L_80018354
    if (ctx->r7 == 0) {
        // 0x80018320: nop
    
            goto L_80018354;
    }
    // 0x80018320: nop

    // 0x80018324: lw          $t8, 0x14($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X14);
    // 0x80018328: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8001832C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80018330: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80018334: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80018338: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001833C: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80018340: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80018344: div.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f8.d);
    // 0x80018348: mul.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x8001834C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80018350: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
L_80018354:
    // 0x80018354: b           L_80018488
    // 0x80018358: addiu       $v1, $zero, 0x296
    ctx->r3 = ADD32(0, 0X296);
        goto L_80018488;
    // 0x80018358: addiu       $v1, $zero, 0x296
    ctx->r3 = ADD32(0, 0X296);
L_8001835C:
    // 0x8001835C: b           L_80018488
    // 0x80018360: addiu       $v1, $zero, 0x297
    ctx->r3 = ADD32(0, 0X297);
        goto L_80018488;
    // 0x80018360: addiu       $v1, $zero, 0x297
    ctx->r3 = ADD32(0, 0X297);
L_80018364:
    // 0x80018364: beql        $a3, $zero, L_800186D0
    if (ctx->r7 == 0) {
        // 0x80018368: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800186D0;
    }
    goto skip_10;
    // 0x80018368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x8001836C: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80018370: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80018374: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80018378: subu        $t2, $t1, $t9
    ctx->r10 = SUB32(ctx->r9, ctx->r25);
    // 0x8001837C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80018380: jal         0x80011CF0
    // 0x80018384: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_80011CF0(rdram, ctx);
        goto after_17;
    // 0x80018384: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_17:
    // 0x80018388: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001838C: addiu       $v0, $v0, -0x6D94
    ctx->r2 = ADD32(ctx->r2, -0X6D94);
    // 0x80018390: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80018394: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x80018398: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8001839C: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x800183A0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800183A4: nop

    // 0x800183A8: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800183AC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800183B0: nop

    // 0x800183B4: bc1fl       L_800186D0
    if (!c1cs) {
        // 0x800183B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800186D0;
    }
    goto skip_11;
    // 0x800183B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x800183BC: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x800183C0: b           L_800186CC
    // 0x800183C4: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
        goto L_800186CC;
    // 0x800183C4: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
L_800183C8:
    // 0x800183C8: beq         $a3, $zero, L_80018484
    if (ctx->r7 == 0) {
        // 0x800183CC: addiu       $v1, $zero, 0x299
        ctx->r3 = ADD32(0, 0X299);
            goto L_80018484;
    }
    // 0x800183CC: addiu       $v1, $zero, 0x299
    ctx->r3 = ADD32(0, 0X299);
    // 0x800183D0: lh          $v0, 0x0($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X0);
    // 0x800183D4: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x800183D8: bgez        $v0, L_80018430
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800183DC: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_80018430;
    }
    // 0x800183DC: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800183E0: sh          $t7, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r15;
    // 0x800183E4: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800183E8: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x800183EC: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x800183F0: negu        $t1, $t8
    ctx->r9 = SUB32(0, ctx->r24);
    // 0x800183F4: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800183F8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800183FC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80018400: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80018404: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80018408: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001840C: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80018410: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80018414: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80018418: div.d       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = DIV_D(ctx->f16.d, ctx->f2.d);
    // 0x8001841C: add.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f8.d + ctx->f6.d;
    // 0x80018420: div.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x80018424: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x80018428: b           L_80018484
    // 0x8001842C: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
        goto L_80018484;
    // 0x8001842C: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
L_80018430:
    // 0x80018430: bne         $at, $zero, L_80018484
    if (ctx->r1 != 0) {
        // 0x80018434: addiu       $t9, $zero, 0x64
        ctx->r25 = ADD32(0, 0X64);
            goto L_80018484;
    }
    // 0x80018434: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80018438: sh          $t9, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r25;
    // 0x8001843C: lh          $t2, 0x0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X0);
    // 0x80018440: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x80018444: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80018448: addiu       $t4, $t2, -0x7F
    ctx->r12 = ADD32(ctx->r10, -0X7F);
    // 0x8001844C: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80018450: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80018454: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80018458: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001845C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80018460: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80018464: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80018468: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8001846C: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x80018470: div.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f2.d);
    // 0x80018474: add.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f4.d + ctx->f16.d;
    // 0x80018478: div.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f18.d, ctx->f8.d);
    // 0x8001847C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80018480: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
L_80018484:
    // 0x80018484: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80018488:
    // 0x80018488: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001848C: beql        $v1, $at, L_800186D0
    if (ctx->r3 == ctx->r1) {
        // 0x80018490: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800186D0;
    }
    goto skip_12;
    // 0x80018490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_12:
    // 0x80018494: bne         $t0, $zero, L_800184C0
    if (ctx->r8 != 0) {
        // 0x80018498: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800184C0;
    }
    // 0x80018498: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001849C: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x800184A0: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x800184A4: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x800184A8: sh          $t0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r8;
    // 0x800184AC: jal         0x80011AE4
    // 0x800184B0: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    func_80011AE4(rdram, ctx);
        goto after_18;
    // 0x800184B0: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    after_18:
    // 0x800184B4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800184B8: lh          $t0, 0x4E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4E);
    // 0x800184BC: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
L_800184C0:
    // 0x800184C0: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800184C4: lh          $t6, 0x6E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6E);
    // 0x800184C8: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x800184CC: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x800184D0: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x800184D4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800184D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800184DC: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800184E0: addiu       $t1, $t1, -0x5AD0
    ctx->r9 = ADD32(ctx->r9, -0X5AD0);
    // 0x800184E4: addu        $v0, $t8, $t1
    ctx->r2 = ADD32(ctx->r24, ctx->r9);
    // 0x800184E8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800184EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800184F0: lbu         $a1, 0x61($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X61);
    // 0x800184F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800184F8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x800184FC: sh          $t0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r8;
    // 0x80018500: jal         0x8001BC8C
    // 0x80018504: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    func_8001BC8C(rdram, ctx);
        goto after_19;
    // 0x80018504: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    after_19:
    // 0x80018508: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8001850C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80018510: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80018514: jal         0x8001BC68
    // 0x80018518: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_8001BC68(rdram, ctx);
        goto after_20;
    // 0x80018518: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_20:
    // 0x8001851C: lh          $t2, 0x50($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X50);
    // 0x80018520: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80018524: lh          $t0, 0x4E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4E);
    // 0x80018528: beq         $t2, $zero, L_80018570
    if (ctx->r10 == 0) {
        // 0x8001852C: lwc1        $f14, 0x58($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80018570;
    }
    // 0x8001852C: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80018530: beql        $a3, $zero, L_80018574
    if (ctx->r7 == 0) {
        // 0x80018534: lh          $t3, 0x52($sp)
        ctx->r11 = MEM_H(ctx->r29, 0X52);
            goto L_80018574;
    }
    goto skip_13;
    // 0x80018534: lh          $t3, 0x52($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X52);
    skip_13:
    // 0x80018538: lh          $t4, 0x2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X2);
    // 0x8001853C: lui         $at, 0x4050
    ctx->r1 = S32(0X4050 << 16);
    // 0x80018540: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80018544: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80018548: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001854C: lui         $at, 0x4089
    ctx->r1 = S32(0X4089 << 16);
    // 0x80018550: cvt.d.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.d = CVT_D_W(ctx->f16.u32l);
    // 0x80018554: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80018558: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001855C: cvt.d.s     $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.d = CVT_D_S(ctx->f14.fl);
    // 0x80018560: sub.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f6.d - ctx->f18.d;
    // 0x80018564: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x80018568: sub.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d - ctx->f4.d;
    // 0x8001856C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
L_80018570:
    // 0x80018570: lh          $t3, 0x52($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X52);
L_80018574:
    // 0x80018574: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80018578: beql        $t3, $zero, L_80018668
    if (ctx->r11 == 0) {
        // 0x8001857C: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80018668;
    }
    goto skip_14;
    // 0x8001857C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_14:
    // 0x80018580: lbu         $t6, -0x6D14($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6D14);
    // 0x80018584: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80018588: beq         $t6, $zero, L_800185A0
    if (ctx->r14 == 0) {
        // 0x8001858C: nop
    
            goto L_800185A0;
    }
    // 0x8001858C: nop

    // 0x80018590: ldc1        $f8, -0x1000($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1000);
    // 0x80018594: cvt.d.s     $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.d = CVT_D_S(ctx->f14.fl);
    // 0x80018598: mul.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x8001859C: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
L_800185A0:
    // 0x800185A0: beql        $a3, $zero, L_80018668
    if (ctx->r7 == 0) {
        // 0x800185A4: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80018668;
    }
    goto skip_15;
    // 0x800185A4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_15:
    // 0x800185A8: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
    // 0x800185AC: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x800185B0: bne         $at, $zero, L_800185C8
    if (ctx->r1 != 0) {
        // 0x800185B4: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_800185C8;
    }
    // 0x800185B4: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800185B8: beq         $v0, $at, L_80018608
    if (ctx->r2 == ctx->r1) {
        // 0x800185BC: nop
    
            goto L_80018608;
    }
    // 0x800185BC: nop

    // 0x800185C0: b           L_80018668
    // 0x800185C4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
        goto L_80018668;
    // 0x800185C4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_800185C8:
    // 0x800185C8: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x800185CC: bne         $at, $zero, L_800185E8
    if (ctx->r1 != 0) {
        // 0x800185D0: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_800185E8;
    }
    // 0x800185D0: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800185D4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800185D8: beq         $v0, $at, L_80018638
    if (ctx->r2 == ctx->r1) {
        // 0x800185DC: nop
    
            goto L_80018638;
    }
    // 0x800185DC: nop

    // 0x800185E0: b           L_80018668
    // 0x800185E4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
        goto L_80018668;
    // 0x800185E4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_800185E8:
    // 0x800185E8: sltiu       $at, $t5, 0x20
    ctx->r1 = ctx->r13 < 0X20 ? 1 : 0;
    // 0x800185EC: beq         $at, $zero, L_80018664
    if (ctx->r1 == 0) {
        // 0x800185F0: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80018664;
    }
    // 0x800185F0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800185F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800185F8: addu        $at, $at, $t5
    gpr jr_addend_80018600 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800185FC: lw          $t5, -0xFF8($at)
    ctx->r13 = ADD32(ctx->r1, -0XFF8);
    // 0x80018600: jr          $t5
    // 0x80018604: nop

    switch (jr_addend_80018600 >> 2) {
        case 0: goto L_80018664; break;
        case 1: goto L_80018608; break;
        case 2: goto L_80018664; break;
        case 3: goto L_80018620; break;
        case 4: goto L_80018664; break;
        case 5: goto L_80018664; break;
        case 6: goto L_80018664; break;
        case 7: goto L_80018664; break;
        case 8: goto L_80018664; break;
        case 9: goto L_80018664; break;
        case 10: goto L_80018664; break;
        case 11: goto L_80018664; break;
        case 12: goto L_80018664; break;
        case 13: goto L_80018664; break;
        case 14: goto L_80018664; break;
        case 15: goto L_80018620; break;
        case 16: goto L_80018664; break;
        case 17: goto L_80018664; break;
        case 18: goto L_80018664; break;
        case 19: goto L_80018664; break;
        case 20: goto L_80018664; break;
        case 21: goto L_80018664; break;
        case 22: goto L_80018664; break;
        case 23: goto L_80018664; break;
        case 24: goto L_80018664; break;
        case 25: goto L_80018664; break;
        case 26: goto L_80018664; break;
        case 27: goto L_80018664; break;
        case 28: goto L_80018664; break;
        case 29: goto L_80018664; break;
        case 30: goto L_80018664; break;
        case 31: goto L_80018650; break;
        default: switch_error(__func__, 0x80018600, 0x800AF008);
    }
    // 0x80018604: nop

L_80018608:
    // 0x80018608: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001860C: ldc1        $f4, -0xF78($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0XF78);
    // 0x80018610: cvt.d.s     $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.d = CVT_D_S(ctx->f14.fl);
    // 0x80018614: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80018618: b           L_80018664
    // 0x8001861C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
        goto L_80018664;
    // 0x8001861C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
L_80018620:
    // 0x80018620: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80018624: ldc1        $f8, -0xF70($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0XF70);
    // 0x80018628: cvt.d.s     $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.d = CVT_D_S(ctx->f14.fl);
    // 0x8001862C: mul.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80018630: b           L_80018664
    // 0x80018634: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
        goto L_80018664;
    // 0x80018634: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
L_80018638:
    // 0x80018638: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001863C: ldc1        $f4, -0xF68($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0XF68);
    // 0x80018640: cvt.d.s     $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.d = CVT_D_S(ctx->f14.fl);
    // 0x80018644: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80018648: b           L_80018664
    // 0x8001864C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
        goto L_80018664;
    // 0x8001864C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
L_80018650:
    // 0x80018650: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80018654: ldc1        $f8, -0xF60($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0XF60);
    // 0x80018658: cvt.d.s     $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.d = CVT_D_S(ctx->f14.fl);
    // 0x8001865C: mul.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80018660: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
L_80018664:
    // 0x80018664: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_80018668:
    // 0x80018668: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8001866C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80018670: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80018674: jal         0x8001BCD0
    // 0x80018678: sh          $t0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r8;
    func_8001BCD0(rdram, ctx);
        goto after_21;
    // 0x80018678: sh          $t0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r8;
    after_21:
    // 0x8001867C: lh          $t0, 0x4E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4E);
    // 0x80018680: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80018684: addiu       $v0, $v0, -0x6D80
    ctx->r2 = ADD32(ctx->r2, -0X6D80);
    // 0x80018688: bnel        $t0, $zero, L_800186D0
    if (ctx->r8 != 0) {
        // 0x8001868C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800186D0;
    }
    goto skip_16;
    // 0x8001868C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_16:
    // 0x80018690: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80018694: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80018698: beql        $t8, $zero, L_800186D0
    if (ctx->r24 == 0) {
        // 0x8001869C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800186D0;
    }
    goto skip_17;
    // 0x8001869C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_17:
    // 0x800186A0: lh          $t1, -0x6D90($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X6D90);
    // 0x800186A4: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x800186A8: bnel        $t1, $at, L_800186BC
    if (ctx->r9 != ctx->r1) {
        // 0x800186AC: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_800186BC;
    }
    goto skip_18;
    // 0x800186AC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    skip_18:
    // 0x800186B0: b           L_800186CC
    // 0x800186B4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
        goto L_800186CC;
    // 0x800186B4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800186B8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
L_800186BC:
    // 0x800186BC: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x800186C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800186C4: jal         0x8001BCF4
    // 0x800186C8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_8001BCF4(rdram, ctx);
        goto after_22;
    // 0x800186C8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_22:
L_800186CC:
    // 0x800186CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800186D0:
    // 0x800186D0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800186D4: jr          $ra
    // 0x800186D8: nop

    return;
    // 0x800186D8: nop

    // 0x800186DC: nop

;}
RECOMP_FUNC void func_807B3800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B3800: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(874, 0X18) << 16);
    // 0x807B3804: addiu       $v0, $v0, 0x3818
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(874, 0X18));
    // 0x807B3808: jr          $ra
    // 0x807B380C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807B380C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8005CC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CC90: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8005CC94: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8005CC98: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8005CC9C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8005CCA0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005CCA4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8005CCA8: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8005CCAC: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8005CCB0: lw          $s3, 0x1F4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1F4);
    // 0x8005CCB4: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8005CCB8: addiu       $t7, $t6, 0x48
    ctx->r15 = ADD32(ctx->r14, 0X48);
    // 0x8005CCBC: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8005CCC0: addiu       $t8, $t8, 0x61C0
    ctx->r24 = ADD32(ctx->r24, 0X61C0);
    // 0x8005CCC4: sw          $t8, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r24;
    // 0x8005CCC8: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x8005CCCC: or          $s0, $sp, $zero
    ctx->r16 = ctx->r29 | 0;
    // 0x8005CCD0: addiu       $s0, $s0, 0x6F
    ctx->r16 = ADD32(ctx->r16, 0X6F);
    // 0x8005CCD4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8005CCD8: srl         $s0, $s0, 3
    ctx->r16 = S32(U32(ctx->r16) >> 3);
    // 0x8005CCDC: lui         $s2, 0x8006
    ctx->r18 = S32(0X8006 << 16);
    // 0x8005CCE0: lui         $t1, 0x361
    ctx->r9 = S32(0X361 << 16);
    // 0x8005CCE4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8005CCE8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8005CCEC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8005CCF0: addiu       $t1, $t1, -0x2570
    ctx->r9 = ADD32(ctx->r9, -0X2570);
    // 0x8005CCF4: addiu       $s2, $s2, 0x758C
    ctx->r18 = ADD32(ctx->r18, 0X758C);
    // 0x8005CCF8: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x8005CCFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CD00: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8005CD04: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x8005CD08: jal         0x800675D0
    // 0x8005CD0C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_800675D0(rdram, ctx);
        goto after_0;
    // 0x8005CD0C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x8005CD10: jal         0x80064DD0
    // 0x8005CD14: lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X4);
    func_80064DD0(rdram, ctx);
        goto after_1;
    // 0x8005CD14: lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X4);
    after_1:
    // 0x8005CD18: lw          $t2, 0x1F4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1F4);
    // 0x8005CD1C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8005CD20: sw          $v0, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r2;
    // 0x8005CD24: lw          $t3, 0x1F4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1F4);
    // 0x8005CD28: lw          $a0, 0x14($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X14);
    // 0x8005CD2C: bnel        $a0, $zero, L_8005CD40
    if (ctx->r4 != 0) {
        // 0x8005CD30: lw          $a1, 0x0($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X0);
            goto L_8005CD40;
    }
    goto skip_0;
    // 0x8005CD30: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8005CD34: b           L_8005CEA0
    // 0x8005CD38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005CEA0;
    // 0x8005CD38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005CD3C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
L_8005CD40:
    // 0x8005CD40: jal         0x800675D0
    // 0x8005CD44: lhu         $a2, 0x4($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X4);
    func_800675D0(rdram, ctx);
        goto after_2;
    // 0x8005CD44: lhu         $a2, 0x4($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X4);
    after_2:
    // 0x8005CD48: lh          $t4, 0x6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X6);
    // 0x8005CD4C: sh          $t4, 0x13C($s1)
    MEM_H(0X13C, ctx->r17) = ctx->r12;
    // 0x8005CD50: lh          $t5, 0x8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8);
    // 0x8005CD54: lh          $t8, 0x13C($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X13C);
    // 0x8005CD58: sh          $t5, 0x13E($s1)
    MEM_H(0X13E, ctx->r17) = ctx->r13;
    // 0x8005CD5C: lh          $t6, 0x13E($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X13E);
    // 0x8005CD60: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x8005CD64: bgez        $t8, L_8005CD74
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8005CD68: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_8005CD74;
    }
    // 0x8005CD68: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8005CD6C: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x8005CD70: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8005CD74:
    // 0x8005CD74: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005CD78: mflo        $s2
    ctx->r18 = lo;
    // 0x8005CD7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005CD80: jal         0x80064DD0
    // 0x8005CD84: nop

    func_80064DD0(rdram, ctx);
        goto after_3;
    // 0x8005CD84: nop

    after_3:
    // 0x8005CD88: bne         $v0, $zero, L_8005CD98
    if (ctx->r2 != 0) {
        // 0x8005CD8C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8005CD98;
    }
    // 0x8005CD8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005CD90: b           L_8005CEA0
    // 0x8005CD94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005CEA0;
    // 0x8005CD94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005CD98:
    // 0x8005CD98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8005CD9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CDA0: jal         0x800657CC
    // 0x8005CDA4: sw          $a0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r4;
    func_800657CC(rdram, ctx);
        goto after_4;
    // 0x8005CDA4: sw          $a0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r4;
    after_4:
    // 0x8005CDA8: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8005CDAC: beql        $t0, $zero, L_8005CE0C
    if (ctx->r8 == 0) {
        // 0x8005CDB0: lw          $v1, 0x4C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X4C);
            goto L_8005CE0C;
    }
    goto skip_1;
    // 0x8005CDB0: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x8005CDB4: jal         0x80064DD0
    // 0x8005CDB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80064DD0(rdram, ctx);
        goto after_5;
    // 0x8005CDB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x8005CDBC: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8005CDC0: jal         0x80064DD0
    // 0x8005CDC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80064DD0(rdram, ctx);
        goto after_6;
    // 0x8005CDC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x8005CDC8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8005CDCC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8005CDD0: bne         $a0, $zero, L_8005CDE0
    if (ctx->r4 != 0) {
        // 0x8005CDD4: nop
    
            goto L_8005CDE0;
    }
    // 0x8005CDD4: nop

    // 0x8005CDD8: b           L_8005CEA0
    // 0x8005CDDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005CEA0;
    // 0x8005CDDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005CDE0:
    // 0x8005CDE0: bne         $v0, $zero, L_8005CDF0
    if (ctx->r2 != 0) {
        // 0x8005CDE4: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_8005CDF0;
    }
    // 0x8005CDE4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8005CDE8: b           L_8005CEA0
    // 0x8005CDEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005CEA0;
    // 0x8005CDEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005CDF0:
    // 0x8005CDF0: jal         0x800657CC
    // 0x8005CDF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_7;
    // 0x8005CDF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8005CDF8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8005CDFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8005CE00: jal         0x800657CC
    // 0x8005CE04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_8;
    // 0x8005CE04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8005CE08: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
L_8005CE0C:
    // 0x8005CE0C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x8005CE10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005CE14: addiu       $s0, $v1, 0x4
    ctx->r16 = ADD32(ctx->r3, 0X4);
    // 0x8005CE18: sw          $v0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r2;
    // 0x8005CE1C: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x8005CE20: sw          $v0, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->r2;
    // 0x8005CE24: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8005CE28: sw          $t1, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r9;
    // 0x8005CE2C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8005CE30: jal         0x8005C9F4
    // 0x8005CE34: sw          $t2, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->r10;
    func_8005C9F4(rdram, ctx);
        goto after_9;
    // 0x8005CE34: sw          $t2, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->r10;
    after_9:
    // 0x8005CE38: jal         0x8005AB3C
    // 0x8005CE3C: nop

    func_8005AB3C(rdram, ctx);
        goto after_10;
    // 0x8005CE3C: nop

    after_10:
    // 0x8005CE40: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x8005CE44: lw          $t3, 0x1F4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1F4);
    // 0x8005CE48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8005CE4C: sll         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18 << 16);
    // 0x8005CE50: sw          $v0, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r2;
    // 0x8005CE54: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x8005CE58: bnel        $t4, $zero, L_8005CE6C
    if (ctx->r12 != 0) {
        // 0x8005CE5C: sw          $zero, 0x30($s3)
        MEM_W(0X30, ctx->r19) = 0;
            goto L_8005CE6C;
    }
    goto skip_2;
    // 0x8005CE5C: sw          $zero, 0x30($s3)
    MEM_W(0X30, ctx->r19) = 0;
    skip_2:
    // 0x8005CE60: b           L_8005CEA0
    // 0x8005CE64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005CEA0;
    // 0x8005CE64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005CE68: sw          $zero, 0x30($s3)
    MEM_W(0X30, ctx->r19) = 0;
L_8005CE6C:
    // 0x8005CE6C: sw          $zero, 0x34($s3)
    MEM_W(0X34, ctx->r19) = 0;
    // 0x8005CE70: sw          $zero, 0x38($s3)
    MEM_W(0X38, ctx->r19) = 0;
    // 0x8005CE74: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8005CE78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005CE7C: lh          $t5, 0x13C($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X13C);
    // 0x8005CE80: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8005CE84: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8005CE88: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005CE8C: lh          $t6, 0x13E($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X13E);
    // 0x8005CE90: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8005CE94: jal         0x8005B8D4
    // 0x8005CE98: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_8005B8D4(rdram, ctx);
        goto after_11;
    // 0x8005CE98: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_11:
    // 0x8005CE9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005CEA0:
    // 0x8005CEA0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8005CEA4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8005CEA8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005CEAC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8005CEB0: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8005CEB4: jr          $ra
    // 0x8005CEB8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8005CEB8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80573E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80573E90: lui         $t6, 0x8057
    ctx->r14 = S32(RELOC_HI16(381, 0XE50) << 16);
    // 0x80573E94: lw          $t6, 0x4CE0($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(381, 0XE50));
    // 0x80573E98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80573E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80573EA0: bne         $t6, $zero, L_80573EF4
    if (ctx->r14 != 0) {
        // 0x80573EA4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80573EF4;
    }
    // 0x80573EA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80573EA8: lui         $a0, 0x8057
    ctx->r4 = S32(RELOC_HI16(381, 0X10A0) << 16);
    // 0x80573EAC: lui         $a1, 0x8057
    ctx->r5 = S32(RELOC_HI16(381, 0X10B0) << 16);
    // 0x80573EB0: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(381, 0X10B0));
    // 0x80573EB4: addiu       $a0, $a0, 0x4F30
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(381, 0X10A0));
    // 0x80573EB8: jal         0x8004667C
    // 0x80573EBC: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x80573EBC: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_0:
    // 0x80573EC0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80573EC4: lui         $a2, 0x8057
    ctx->r6 = S32(RELOC_HI16(381, 0XCB4) << 16);
    // 0x80573EC8: addiu       $a2, $a2, 0x4B44
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(381, 0XCB4));
    // 0x80573ECC: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x80573ED0: jal         0x80057B28
    // 0x80573ED4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x80573ED4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_1:
    // 0x80573ED8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80573EDC: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(381, 0XE50) << 16);
    // 0x80573EE0: sw          $t7, 0x4CE0($at)
    MEM_W((int16_t)RELOC_LO16(381, 0XE50), ctx->r1) = ctx->r15;
    // 0x80573EE4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80573EE8: sw          $zero, -0x7534($at)
    MEM_W(-0X7534, ctx->r1) = 0;
    // 0x80573EEC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80573EF0: sw          $zero, -0x7530($at)
    MEM_W(-0X7530, ctx->r1) = 0;
L_80573EF4:
    // 0x80573EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80573EF8: lui         $v0, 0x8057
    ctx->r2 = S32(RELOC_HI16(381, 0X414) << 16);
    // 0x80573EFC: addiu       $v0, $v0, 0x42A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(381, 0X414));
    // 0x80573F00: jr          $ra
    // 0x80573F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80573F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8064B4C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B4C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B4C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B4C8: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8064B4CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8064B4D0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064B4D4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064B4D8: nop

    // 0x8064B4DC: bc1fl       L_8064B524
    if (!c1cs) {
        // 0x8064B4E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064B524;
    }
    goto skip_0;
    // 0x8064B4E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064B4E4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064B4E8: lwc1        $f10, 0x84($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064B4EC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8064B4F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8064B4F4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8064B4F8: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8064B4FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064B500: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8064B504: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8064B508: nop

    // 0x8064B50C: bc1fl       L_8064B524
    if (!c1cs) {
        // 0x8064B510: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064B524;
    }
    goto skip_1;
    // 0x8064B510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8064B514: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064B518: jal         0x8064B918
    // 0x8064B51C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064B918(rdram, ctx);
        goto after_0;
    // 0x8064B51C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064B520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064B524:
    // 0x8064B524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B528: jr          $ra
    // 0x8064B52C: nop

    return;
    // 0x8064B52C: nop

;}
RECOMP_FUNC void func_8003085C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003085C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80030860: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80030864: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80030868: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003086C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80030870: jal         0x80042148
    // 0x80030874: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80042148(rdram, ctx);
        goto after_0;
    // 0x80030874: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80030878: beq         $v0, $zero, L_800308BC
    if (ctx->r2 == 0) {
        // 0x8003087C: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_800308BC;
    }
    // 0x8003087C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80030880: jal         0x80042880
    // 0x80030884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80042880(rdram, ctx);
        goto after_1;
    // 0x80030884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80030888: jal         0x800307D4
    // 0x8003088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800307D4(rdram, ctx);
        goto after_2;
    // 0x8003088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80030890: jal         0x80028220
    // 0x80030894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028220(rdram, ctx);
        goto after_3;
    // 0x80030894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80030898: jal         0x80065954
    // 0x8003089C: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    func_80065954(rdram, ctx);
        goto after_4;
    // 0x8003089C: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    after_4:
    // 0x800308A0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800308A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800308A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800308AC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800308B0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800308B4: jal         0x80041214
    // 0x800308B8: nop

    func_80041214(rdram, ctx);
        goto after_5;
    // 0x800308B8: nop

    after_5:
L_800308BC:
    // 0x800308BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800308C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800308C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800308C8: jr          $ra
    // 0x800308CC: nop

    return;
    // 0x800308CC: nop

;}
RECOMP_FUNC void func_804A41E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A41E4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x804A41E8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x804A41EC: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x804A41F0: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x804A41F4: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x804A41F8: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x804A41FC: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x804A4200: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x804A4204: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x804A4208: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804A420C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804A4210: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804A4214: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x804A4218: lwc1        $f26, 0x3C($a0)
    ctx->f26.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804A421C: addiu       $s0, $v0, 0x188
    ctx->r16 = ADD32(ctx->r2, 0X188);
    // 0x804A4220: lwc1        $f28, 0x40($a0)
    ctx->f28.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804A4224: bne         $s0, $zero, L_804A4234
    if (ctx->r16 != 0) {
        // 0x804A4228: lh          $s1, 0x184($v0)
        ctx->r17 = MEM_H(ctx->r2, 0X184);
            goto L_804A4234;
    }
    // 0x804A4228: lh          $s1, 0x184($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X184);
    // 0x804A422C: b           L_804A42D4
    // 0x804A4230: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_804A42D4;
    // 0x804A4230: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_804A4234:
    // 0x804A4234: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A4238: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x804A423C: beq         $s1, $zero, L_804A42B0
    if (ctx->r17 == 0) {
        // 0x804A4240: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_804A42B0;
    }
    // 0x804A4240: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_804A4244:
    // 0x804A4244: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804A4248: beq         $v0, $zero, L_804A42A8
    if (ctx->r2 == 0) {
        // 0x804A424C: nop
    
            goto L_804A42A8;
    }
    // 0x804A424C: nop

    // 0x804A4250: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A4254: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x804A4258: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x804A425C: c.lt.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl < ctx->f0.fl;
    // 0x804A4260: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804A4264: bc1f        L_804A42A8
    if (!c1cs) {
        // 0x804A4268: nop
    
            goto L_804A42A8;
    }
    // 0x804A4268: nop

    // 0x804A426C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x804A4270: lwc1        $f20, 0x40($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A4274: jal         0x804A3C08
    // 0x804A4278: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_804A3C08(rdram, ctx);
        goto after_0;
    // 0x804A4278: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_0:
    // 0x804A427C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x804A4280: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x804A4284: jal         0x804A3C08
    // 0x804A4288: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_804A3C08(rdram, ctx);
        goto after_1;
    // 0x804A4288: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_1:
    // 0x804A428C: add.s       $f2, $f0, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x804A4290: c.le.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl <= ctx->f24.fl;
    // 0x804A4294: nop

    // 0x804A4298: bc1f        L_804A42A8
    if (!c1cs) {
        // 0x804A429C: nop
    
            goto L_804A42A8;
    }
    // 0x804A429C: nop

    // 0x804A42A0: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x804A42A4: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_804A42A8:
    // 0x804A42A8: bne         $s1, $zero, L_804A4244
    if (ctx->r17 != 0) {
        // 0x804A42AC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_804A4244;
    }
    // 0x804A42AC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_804A42B0:
    // 0x804A42B0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A42B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A42B8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x804A42BC: c.le.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl <= ctx->f24.fl;
    // 0x804A42C0: nop

    // 0x804A42C4: bc1f        L_804A42D4
    if (!c1cs) {
        // 0x804A42C8: nop
    
            goto L_804A42D4;
    }
    // 0x804A42C8: nop

    // 0x804A42CC: b           L_804A42D4
    // 0x804A42D0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_804A42D4;
    // 0x804A42D0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_804A42D4:
    // 0x804A42D4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x804A42D8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804A42DC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804A42E0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x804A42E4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x804A42E8: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x804A42EC: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x804A42F0: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x804A42F4: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x804A42F8: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x804A42FC: jr          $ra
    // 0x804A4300: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x804A4300: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80050994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050998: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005099C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800509A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800509A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800509A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800509AC: jal         0x80050848
    // 0x800509B0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_80050848(rdram, ctx);
        goto after_0;
    // 0x800509B0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x800509B4: bne         $v0, $zero, L_800509D8
    if (ctx->r2 != 0) {
        // 0x800509B8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800509D8;
    }
    // 0x800509B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800509BC: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x800509C0: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x800509C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800509C8: jal         0x800675D0
    // 0x800509CC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800675D0(rdram, ctx);
        goto after_1;
    // 0x800509CC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800509D0: b           L_800509DC
    // 0x800509D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800509DC;
    // 0x800509D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800509D8:
    // 0x800509D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800509DC:
    // 0x800509DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800509E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800509E4: jr          $ra
    // 0x800509E8: nop

    return;
    // 0x800509E8: nop

;}
RECOMP_FUNC void func_800463B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800463B4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800463B8: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x800463BC: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800463C0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800463C4: slt         $at, $t7, $a2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800463C8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800463CC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800463D0: beq         $at, $zero, L_8004640C
    if (ctx->r1 == 0) {
        // 0x800463D4: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_8004640C;
    }
    // 0x800463D4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800463D8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800463DC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800463E0: sll         $t8, $t8, 7
    ctx->r24 = S32(ctx->r24 << 7);
    // 0x800463E4: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
L_800463E8:
    // 0x800463E8: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800463EC: bnel        $t9, $zero, L_80046400
    if (ctx->r25 != 0) {
        // 0x800463F0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80046400;
    }
    goto skip_0;
    // 0x800463F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x800463F4: jr          $ra
    // 0x800463F8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800463F8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800463FC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80046400:
    // 0x80046400: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80046404: bne         $at, $zero, L_800463E8
    if (ctx->r1 != 0) {
        // 0x80046408: addiu       $a0, $a0, 0x280
        ctx->r4 = ADD32(ctx->r4, 0X280);
            goto L_800463E8;
    }
    // 0x80046408: addiu       $a0, $a0, 0x280
    ctx->r4 = ADD32(ctx->r4, 0X280);
L_8004640C:
    // 0x8004640C: blez        $v1, L_8004643C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80046410: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8004643C;
    }
    // 0x80046410: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80046414: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80046418:
    // 0x80046418: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x8004641C: bnel        $t0, $zero, L_80046430
    if (ctx->r8 != 0) {
        // 0x80046420: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80046430;
    }
    goto skip_1;
    // 0x80046420: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x80046424: jr          $ra
    // 0x80046428: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x80046428: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8004642C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80046430:
    // 0x80046430: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80046434: bne         $at, $zero, L_80046418
    if (ctx->r1 != 0) {
        // 0x80046438: addiu       $a0, $a0, 0x280
        ctx->r4 = ADD32(ctx->r4, 0X280);
            goto L_80046418;
    }
    // 0x80046438: addiu       $a0, $a0, 0x280
    ctx->r4 = ADD32(ctx->r4, 0X280);
L_8004643C:
    // 0x8004643C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80046440: jr          $ra
    // 0x80046444: nop

    return;
    // 0x80046444: nop

;}
RECOMP_FUNC void func_80069D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069D40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80069D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069D48: jal         0x80064DD0
    // 0x80069D4C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x80069D4C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_0:
    // 0x80069D50: bne         $v0, $zero, L_80069D60
    if (ctx->r2 != 0) {
        // 0x80069D54: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80069D60;
    }
    // 0x80069D54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80069D58: b           L_80069D74
    // 0x80069D5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80069D74;
    // 0x80069D5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80069D60:
    // 0x80069D60: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80069D64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80069D68: jal         0x80065728
    // 0x80069D6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x80069D6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80069D70: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_80069D74:
    // 0x80069D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069D78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80069D7C: jr          $ra
    // 0x80069D80: nop

    return;
    // 0x80069D80: nop

;}
RECOMP_FUNC void func_8005D96C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D96C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D970: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005D974: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8005D978: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8005D97C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8005D980: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8005D984: addiu       $t7, $t7, 0x6344
    ctx->r15 = ADD32(ctx->r15, 0X6344);
    // 0x8005D988: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8005D98C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8005D990: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8005D994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D998: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8005D99C: blez        $a2, L_8005DA54
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8005D9A0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8005DA54;
    }
    // 0x8005D9A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D9A4: andi        $a0, $a2, 0x3
    ctx->r4 = ctx->r6 & 0X3;
    // 0x8005D9A8: beq         $a0, $zero, L_8005D9DC
    if (ctx->r4 == 0) {
        // 0x8005D9AC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8005D9DC;
    }
    // 0x8005D9AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8005D9B0:
    // 0x8005D9B0: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8005D9B4: bne         $t8, $zero, L_8005D9C8
    if (ctx->r24 != 0) {
        // 0x8005D9B8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8005D9C8;
    }
    // 0x8005D9B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005D9BC: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x8005D9C0: b           L_8005DA68
    // 0x8005D9C4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8005DA68;
    // 0x8005D9C4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8005D9C8:
    // 0x8005D9C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8005D9CC: bne         $v0, $a1, L_8005D9B0
    if (ctx->r2 != ctx->r5) {
        // 0x8005D9D0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8005D9B0;
    }
    // 0x8005D9D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005D9D4: beq         $a1, $a2, L_8005DA54
    if (ctx->r5 == ctx->r6) {
        // 0x8005D9D8: nop
    
            goto L_8005DA54;
    }
    // 0x8005D9D8: nop

L_8005D9DC:
    // 0x8005D9DC: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x8005D9E0: bne         $t0, $zero, L_8005D9F4
    if (ctx->r8 != 0) {
        // 0x8005D9E4: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8005D9F4;
    }
    // 0x8005D9E4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005D9E8: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x8005D9EC: b           L_8005DA68
    // 0x8005D9F0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8005DA68;
    // 0x8005D9F0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8005D9F4:
    // 0x8005D9F4: lbu         $t2, 0x1($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X1);
    // 0x8005D9F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005D9FC: bne         $t2, $zero, L_8005DA10
    if (ctx->r10 != 0) {
        // 0x8005DA00: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8005DA10;
    }
    // 0x8005DA00: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005DA04: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x8005DA08: b           L_8005DA68
    // 0x8005DA0C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
        goto L_8005DA68;
    // 0x8005DA0C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
L_8005DA10:
    // 0x8005DA10: lbu         $t4, 0x1($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1);
    // 0x8005DA14: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005DA18: bne         $t4, $zero, L_8005DA2C
    if (ctx->r12 != 0) {
        // 0x8005DA1C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8005DA2C;
    }
    // 0x8005DA1C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005DA20: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8005DA24: b           L_8005DA68
    // 0x8005DA28: addiu       $v0, $a1, 0x2
    ctx->r2 = ADD32(ctx->r5, 0X2);
        goto L_8005DA68;
    // 0x8005DA28: addiu       $v0, $a1, 0x2
    ctx->r2 = ADD32(ctx->r5, 0X2);
L_8005DA2C:
    // 0x8005DA2C: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x8005DA30: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005DA34: bne         $t6, $zero, L_8005DA48
    if (ctx->r14 != 0) {
        // 0x8005DA38: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8005DA48;
    }
    // 0x8005DA38: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005DA3C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x8005DA40: b           L_8005DA68
    // 0x8005DA44: addiu       $v0, $a1, 0x3
    ctx->r2 = ADD32(ctx->r5, 0X3);
        goto L_8005DA68;
    // 0x8005DA44: addiu       $v0, $a1, 0x3
    ctx->r2 = ADD32(ctx->r5, 0X3);
L_8005DA48:
    // 0x8005DA48: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8005DA4C: bne         $a1, $a2, L_8005D9DC
    if (ctx->r5 != ctx->r6) {
        // 0x8005DA50: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8005D9DC;
    }
    // 0x8005DA50: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8005DA54:
    // 0x8005DA54: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005DA58: addiu       $a0, $a0, 0xD10
    ctx->r4 = ADD32(ctx->r4, 0XD10);
    // 0x8005DA5C: jal         0x80071380
    // 0x8005DA60: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8005DA60: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    after_0:
    // 0x8005DA64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005DA68:
    // 0x8005DA68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005DA6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005DA70: jr          $ra
    // 0x8005DA74: nop

    return;
    // 0x8005DA74: nop

;}
RECOMP_FUNC void func_804463E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804463E8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804463EC: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x804463F0: jr          $ra
    // 0x804463F4: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    return;
    // 0x804463F4: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8045278C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045278C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452794: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80452798: jal         0x804525A8
    // 0x8045279C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_804525A8(rdram, ctx);
        goto after_0;
    // 0x8045279C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x804527A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804527A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804527A8: jr          $ra
    // 0x804527AC: nop

    return;
    // 0x804527AC: nop

;}
RECOMP_FUNC void func_800343C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800343C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800343C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800343C8: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x800343CC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x800343D0: lbu         $t7, 0x12($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X12);
    // 0x800343D4: beql        $t7, $zero, L_8003440C
    if (ctx->r15 == 0) {
        // 0x800343D8: lw          $t8, 0x24($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X24);
            goto L_8003440C;
    }
    goto skip_0;
    // 0x800343D8: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    skip_0:
    // 0x800343DC: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x800343E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800343E4: nop

    // 0x800343E8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800343EC: nop

    // 0x800343F0: bc1fl       L_8003440C
    if (!c1cs) {
        // 0x800343F4: lw          $t8, 0x24($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X24);
            goto L_8003440C;
    }
    goto skip_1;
    // 0x800343F4: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    skip_1:
    // 0x800343F8: jal         0x8002F1D4
    // 0x800343FC: nop

    func_8002F1D4(rdram, ctx);
        goto after_0;
    // 0x800343FC: nop

    after_0:
    // 0x80034400: b           L_8003443C
    // 0x80034404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003443C;
    // 0x80034404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80034408: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
L_8003440C:
    // 0x8003440C: andi        $t9, $t8, 0x700
    ctx->r25 = ctx->r24 & 0X700;
    // 0x80034410: beql        $t9, $zero, L_8003443C
    if (ctx->r25 == 0) {
        // 0x80034414: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003443C;
    }
    goto skip_2;
    // 0x80034414: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80034418: lhu         $v1, 0x100($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X100);
    // 0x8003441C: bne         $v1, $zero, L_80034434
    if (ctx->r3 != 0) {
        // 0x80034420: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_80034434;
    }
    // 0x80034420: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x80034424: jal         0x8002E110
    // 0x80034428: nop

    func_8002E110(rdram, ctx);
        goto after_1;
    // 0x80034428: nop

    after_1:
    // 0x8003442C: b           L_8003443C
    // 0x80034430: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003443C;
    // 0x80034430: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80034434:
    // 0x80034434: sh          $t0, 0x100($v0)
    MEM_H(0X100, ctx->r2) = ctx->r8;
    // 0x80034438: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003443C:
    // 0x8003443C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034444: jr          $ra
    // 0x80034448: nop

    return;
    // 0x80034448: nop

;}
RECOMP_FUNC void func_8004EE30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EE30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004EE34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004EE38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004EE3C: jal         0x80065728
    // 0x8004EE40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8004EE40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8004EE44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8004EE48: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x8004EE4C: sb          $t7, 0x4C($a0)
    MEM_B(0X4C, ctx->r4) = ctx->r15;
    // 0x8004EE50: sb          $t7, 0x3C($a0)
    MEM_B(0X3C, ctx->r4) = ctx->r15;
    // 0x8004EE54: sb          $zero, 0x4D($a0)
    MEM_B(0X4D, ctx->r4) = 0;
    // 0x8004EE58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004EE5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004EE60: jr          $ra
    // 0x8004EE64: nop

    return;
    // 0x8004EE64: nop

;}
RECOMP_FUNC void func_806FD60C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD60C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x806FD610: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x806FD614: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(706, 0X12B0) << 16);
    // 0x806FD618: lwc1        $f6, -0x18F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(706, 0X12B0));
    // 0x806FD61C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806FD620: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x806FD624: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806FD628: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806FD62C: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x806FD630: nop

    // 0x806FD634: bc1f        L_806FD660
    if (!c1cs) {
        // 0x806FD638: swc1        $f8, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
            goto L_806FD660;
    }
    // 0x806FD638: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x806FD63C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806FD640: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806FD644: nop

    // 0x806FD648: bc1f        L_806FD680
    if (!c1cs) {
        // 0x806FD64C: nop
    
            goto L_806FD680;
    }
    // 0x806FD64C: nop

    // 0x806FD650: lwc1        $f16, 0x24($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X24);
    // 0x806FD654: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x806FD658: jr          $ra
    // 0x806FD65C: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x806FD65C: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_806FD660:
    // 0x806FD660: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806FD664: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806FD668: nop

    // 0x806FD66C: bc1f        L_806FD680
    if (!c1cs) {
        // 0x806FD670: nop
    
            goto L_806FD680;
    }
    // 0x806FD670: nop

    // 0x806FD674: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x806FD678: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x806FD67C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_806FD680:
    // 0x806FD680: jr          $ra
    // 0x806FD684: nop

    return;
    // 0x806FD684: nop

;}
RECOMP_FUNC void func_80011CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011CF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80011CF4: nop

    // 0x80011CF8: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80011CFC: nop

    // 0x80011D00: bc1fl       L_80011D14
    if (!c1cs) {
        // 0x80011D04: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_80011D14;
    }
    goto skip_0;
    // 0x80011D04: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x80011D08: jr          $ra
    // 0x80011D0C: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    return;
    // 0x80011D0C: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x80011D10: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80011D14:
    // 0x80011D14: jr          $ra
    // 0x80011D18: nop

    return;
    // 0x80011D18: nop

;}
RECOMP_FUNC void func_804500B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804500B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804500BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804500C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804500C4: jal         0x8044448C
    // 0x804500C8: addiu       $a1, $zero, 0x40F4
    ctx->r5 = ADD32(0, 0X40F4);
    func_8044448C(rdram, ctx);
        goto after_0;
    // 0x804500C8: addiu       $a1, $zero, 0x40F4
    ctx->r5 = ADD32(0, 0X40F4);
    after_0:
    // 0x804500CC: bne         $v0, $zero, L_804500E8
    if (ctx->r2 != 0) {
        // 0x804500D0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804500E8;
    }
    // 0x804500D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804500D4: lui         $a3, 0xBFB9
    ctx->r7 = S32(0XBFB9 << 16);
    // 0x804500D8: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x804500DC: lui         $a1, 0xC2D6
    ctx->r5 = S32(0XC2D6 << 16);
    // 0x804500E0: jal         0x80444F4C
    // 0x804500E4: lui         $a2, 0xC296
    ctx->r6 = S32(0XC296 << 16);
    func_80444F4C(rdram, ctx);
        goto after_1;
    // 0x804500E4: lui         $a2, 0xC296
    ctx->r6 = S32(0XC296 << 16);
    after_1:
L_804500E8:
    // 0x804500E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804500EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804500F0: jr          $ra
    // 0x804500F4: nop

    return;
    // 0x804500F4: nop

;}
RECOMP_FUNC void func_8002F6E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F6E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002F6E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002F6EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002F6F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002F6F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002F6F8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8002F6FC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F700: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8002F704: lw          $t7, 0x1A4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1A4);
    // 0x8002F708: bne         $t7, $zero, L_8002F744
    if (ctx->r15 != 0) {
        // 0x8002F70C: nop
    
            goto L_8002F744;
    }
    // 0x8002F70C: nop

    // 0x8002F710: lbu         $t8, 0x18($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X18);
    // 0x8002F714: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x8002F718: beq         $at, $zero, L_8002F744
    if (ctx->r1 == 0) {
        // 0x8002F71C: nop
    
            goto L_8002F744;
    }
    // 0x8002F71C: nop

    // 0x8002F720: lw          $t9, 0x168($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X168);
    // 0x8002F724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002F728: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8002F72C: beq         $a1, $t9, L_8002F744
    if (ctx->r5 == ctx->r25) {
        // 0x8002F730: nop
    
            goto L_8002F744;
    }
    // 0x8002F730: nop

    // 0x8002F734: jal         0x8002F678
    // 0x8002F738: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002F738: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8002F73C: bne         $v0, $zero, L_8002F74C
    if (ctx->r2 != 0) {
        // 0x8002F740: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_8002F74C;
    }
    // 0x8002F740: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_8002F744:
    // 0x8002F744: b           L_8002F798
    // 0x8002F748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002F798;
    // 0x8002F748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002F74C:
    // 0x8002F74C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8002F750: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8002F754: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8002F758: lw          $t2, -0x17E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X17E8);
    // 0x8002F75C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002F760: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8002F764: sw          $t2, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->r10;
    // 0x8002F768: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002F76C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8002F770: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002F774: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8002F778: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8002F77C: nop

    // 0x8002F780: bc1fl       L_8002F794
    if (!c1cs) {
        // 0x8002F784: sb          $t4, 0x1A8($s0)
        MEM_B(0X1A8, ctx->r16) = ctx->r12;
            goto L_8002F794;
    }
    goto skip_0;
    // 0x8002F784: sb          $t4, 0x1A8($s0)
    MEM_B(0X1A8, ctx->r16) = ctx->r12;
    skip_0:
    // 0x8002F788: b           L_8002F794
    // 0x8002F78C: sb          $zero, 0x1A8($s0)
    MEM_B(0X1A8, ctx->r16) = 0;
        goto L_8002F794;
    // 0x8002F78C: sb          $zero, 0x1A8($s0)
    MEM_B(0X1A8, ctx->r16) = 0;
    // 0x8002F790: sb          $t4, 0x1A8($s0)
    MEM_B(0X1A8, ctx->r16) = ctx->r12;
L_8002F794:
    // 0x8002F794: sw          $t5, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->r13;
L_8002F798:
    // 0x8002F798: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F79C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002F7A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002F7A4: jr          $ra
    // 0x8002F7A8: nop

    return;
    // 0x8002F7A8: nop

;}
RECOMP_FUNC void func_8076C8D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076C8D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8076C8D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076C8D8: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x8076C8DC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8076C8E0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8076C8E4: beq         $a1, $at, L_8076C900
    if (ctx->r5 == ctx->r1) {
        // 0x8076C8E8: addiu       $a0, $zero, 0x39
        ctx->r4 = ADD32(0, 0X39);
            goto L_8076C900;
    }
    // 0x8076C8E8: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x8076C8EC: jal         0x80067878
    // 0x8076C8F0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8076C8F0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8076C8F4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8076C8F8: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8076C8FC: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_8076C900:
    // 0x8076C900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8076C904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8076C908: jr          $ra
    // 0x8076C90C: nop

    return;
    // 0x8076C90C: nop

;}
RECOMP_FUNC void func_8007C670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C670: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8007C674: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8007C678: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8007C67C: addiu       $t7, $t7, -0x1C60
    ctx->r15 = ADD32(ctx->r15, -0X1C60);
    // 0x8007C680: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8007C684: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8007C688: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8007C68C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007C690: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x8007C694: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x8007C698: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
    // 0x8007C69C: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x8007C6A0: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x8007C6A4: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8007C6A8: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x8007C6AC: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8007C6B0: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x8007C6B4: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8007C6B8: sw          $t4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r12;
    // 0x8007C6BC: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8007C6C0: sw          $t5, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r13;
    // 0x8007C6C4: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8007C6C8: sw          $t6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r14;
    // 0x8007C6CC: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8007C6D0: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x8007C6D4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8007C6D8: sw          $t8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r24;
    // 0x8007C6DC: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8007C6E0: sw          $t9, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r25;
    // 0x8007C6E4: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x8007C6E8: jr          $ra
    // 0x8007C6EC: nop

    return;
    // 0x8007C6EC: nop

;}
RECOMP_FUNC void func_80475A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475A80: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475A84: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475A88: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80475A8C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475A90: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475A94: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475A98: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80475A9C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475AA0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475AA4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475AA8: jr          $ra
    // 0x80475AAC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80475AAC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8057B438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057B438: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8057B43C: jr          $ra
    // 0x8057B440: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    return;
    // 0x8057B440: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_804BCB28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BCB28: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x804BCB2C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x804BCB30: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x804BCB34: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x804BCB38: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x804BCB3C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x804BCB40: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x804BCB44: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x804BCB48: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804BCB4C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804BCB50: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x804BCB54: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    // 0x804BCB58: sw          $a3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r7;
    // 0x804BCB5C: lw          $t6, 0x174($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X174);
    // 0x804BCB60: lwc1        $f20, 0x6C($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804BCB64: lwc1        $f22, 0x70($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804BCB68: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x804BCB6C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804BCB70: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x804BCB74: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x804BCB78: lw          $v1, 0x70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X70);
    // 0x804BCB7C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x804BCB80: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x804BCB84: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804BCB88: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x804BCB8C: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x804BCB90: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    // 0x804BCB94: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804BCB98: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x804BCB9C: nop

    // 0x804BCBA0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804BCBA4: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x804BCBA8: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x804BCBAC: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BCBB0: sw          $a3, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r7;
    // 0x804BCBB4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804BCBB8: jal         0x80049018
    // 0x804BCBBC: addiu       $s0, $a2, 0x2D0
    ctx->r16 = ADD32(ctx->r6, 0X2D0);
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x804BCBBC: addiu       $s0, $a2, 0x2D0
    ctx->r16 = ADD32(ctx->r6, 0X2D0);
    after_0:
    // 0x804BCBC0: beql        $v0, $zero, L_804BCBFC
    if (ctx->r2 == 0) {
        // 0x804BCBC4: lw          $t2, 0x174($s2)
        ctx->r10 = MEM_W(ctx->r18, 0X174);
            goto L_804BCBFC;
    }
    goto skip_0;
    // 0x804BCBC4: lw          $t2, 0x174($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X174);
    skip_0:
    // 0x804BCBC8: lw          $t9, 0x174($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X174);
    // 0x804BCBCC: lwc1        $f6, 0x84($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X84);
    // 0x804BCBD0: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x804BCBD4: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x804BCBD8: lw          $t0, 0x70($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X70);
    // 0x804BCBDC: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x804BCBE0: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x804BCBE4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x804BCBE8: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x804BCBEC: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x804BCBF0: b           L_804BCC24
    // 0x804BCBF4: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
        goto L_804BCC24;
    // 0x804BCBF4: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x804BCBF8: lw          $t2, 0x174($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X174);
L_804BCBFC:
    // 0x804BCBFC: lwc1        $f16, 0x84($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X84);
    // 0x804BCC00: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x804BCC04: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x804BCC08: lw          $t3, 0x70($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X70);
    // 0x804BCC0C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x804BCC10: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x804BCC14: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x804BCC18: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x804BCC1C: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x804BCC20: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
L_804BCC24:
    // 0x804BCC24: lw          $t5, 0x174($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X174);
    // 0x804BCC28: lwc1        $f16, 0x88($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X88);
    // 0x804BCC2C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x804BCC30: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x804BCC34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804BCC38: lw          $v1, 0xC0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC0);
    // 0x804BCC3C: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x804BCC40: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x804BCC44: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x804BCC48: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x804BCC4C: lwc1        $f8, 0x4($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X4);
    // 0x804BCC50: addiu       $s5, $zero, 0x12
    ctx->r21 = ADD32(0, 0X12);
    // 0x804BCC54: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x804BCC58: addiu       $s4, $zero, 0x68
    ctx->r20 = ADD32(0, 0X68);
    // 0x804BCC5C: addiu       $s3, $zero, 0x4001
    ctx->r19 = ADD32(0, 0X4001);
    // 0x804BCC60: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x804BCC64: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x804BCC68: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x804BCC6C: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x804BCC70: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    // 0x804BCC74: lwc1        $f10, 0x84($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X84);
    // 0x804BCC78: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x804BCC7C: swc1        $f10, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f10.u32l;
    // 0x804BCC80: lwc1        $f8, 0x88($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X88);
    // 0x804BCC84: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x804BCC88: add.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x804BCC8C: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
    // 0x804BCC90: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x804BCC94: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x804BCC98: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
L_804BCC9C:
    // 0x804BCC9C: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x804BCCA0: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x804BCCA4: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x804BCCA8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x804BCCAC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x804BCCB0: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x804BCCB4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804BCCB8: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x804BCCBC: mul.s       $f16, $f6, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x804BCCC0: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x804BCCC4: mul.s       $f6, $f18, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x804BCCC8: add.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x804BCCCC: lwc1        $f16, 0xB0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x804BCCD0: sub.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x804BCCD4: sub.s       $f2, $f10, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x804BCCD8: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x804BCCDC: lwc1        $f12, 0x98($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X98);
    // 0x804BCCE0: sub.s       $f18, $f2, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x804BCCE4: jal         0x80065954
    // 0x804BCCE8: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x804BCCE8: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x804BCCEC: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x804BCCF0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x804BCCF4: nop

    // 0x804BCCF8: bc1fl       L_804BCE30
    if (!c1cs) {
        // 0x804BCCFC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_804BCE30;
    }
    goto skip_1;
    // 0x804BCCFC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x804BCD00: jal         0x80065954
    // 0x804BCD04: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x804BCD04: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    after_2:
    // 0x804BCD08: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x804BCD0C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804BCD10: nop

    // 0x804BCD14: bc1fl       L_804BCE30
    if (!c1cs) {
        // 0x804BCD18: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_804BCE30;
    }
    goto skip_2;
    // 0x804BCD18: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x804BCD1C: lbu         $t0, 0x18($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X18);
    // 0x804BCD20: bnel        $s4, $t0, L_804BCDC0
    if (ctx->r20 != ctx->r8) {
        // 0x804BCD24: lhu         $t7, 0xC($s2)
        ctx->r15 = MEM_HU(ctx->r18, 0XC);
            goto L_804BCDC0;
    }
    goto skip_3;
    // 0x804BCD24: lhu         $t7, 0xC($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0XC);
    skip_3:
    // 0x804BCD28: lhu         $t1, 0xC($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0XC);
    // 0x804BCD2C: beql        $s3, $t1, L_804BCE30
    if (ctx->r19 == ctx->r9) {
        // 0x804BCD30: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_804BCE30;
    }
    goto skip_4;
    // 0x804BCD30: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x804BCD34: lwc1        $f16, 0x3C($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x804BCD38: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4190) << 16);
    // 0x804BCD3C: lwc1        $f8, -0x540($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4190));
    // 0x804BCD40: swc1        $f16, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f16.u32l;
    // 0x804BCD44: lwc1        $f4, 0x40($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X40);
    // 0x804BCD48: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x804BCD4C: lw          $t2, -0x76F8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X76F8);
    // 0x804BCD50: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    // 0x804BCD54: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x804BCD58: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x804BCD5C: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x804BCD60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804BCD64: lw          $t9, 0x18($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X18);
    // 0x804BCD68: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x804BCD6C: jalr        $t9
    // 0x804BCD70: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x804BCD70: nop

    after_3:
    // 0x804BCD74: jal         0x800447C8
    // 0x804BCD78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x804BCD78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x804BCD7C: lw          $a0, 0x34($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X34);
    // 0x804BCD80: jal         0x80067BBC
    // 0x804BCD84: lw          $a1, 0x38($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x804BCD84: lw          $a1, 0x38($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X38);
    after_5:
    // 0x804BCD88: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x804BCD8C: jal         0x80067818
    // 0x804BCD90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x804BCD90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x804BCD94: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x804BCD98: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804BCD9C: sb          $t4, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r12;
    // 0x804BCDA0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804BCDA4: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x804BCDA8: sb          $t5, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r13;
    // 0x804BCDAC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804BCDB0: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x804BCDB4: b           L_804BCE38
    // 0x804BCDB8: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
        goto L_804BCE38;
    // 0x804BCDB8: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
    // 0x804BCDBC: lhu         $t7, 0xC($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0XC);
L_804BCDC0:
    // 0x804BCDC0: bnel        $s3, $t7, L_804BCE30
    if (ctx->r19 != ctx->r15) {
        // 0x804BCDC4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_804BCE30;
    }
    goto skip_5;
    // 0x804BCDC4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x804BCDC8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804BCDCC: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x804BCDD0: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x804BCDD4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x804BCDD8: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x804BCDDC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x804BCDE0: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x804BCDE4: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    // 0x804BCDE8: bc1f        L_804BCE1C
    if (!c1cs) {
        // 0x804BCDEC: nop
    
            goto L_804BCE1C;
    }
    // 0x804BCDEC: nop

    // 0x804BCDF0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804BCDF4: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x804BCDF8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x804BCDFC: mul.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x804BCE00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x804BCE04: lui         $a2, 0xC100
    ctx->r6 = S32(0XC100 << 16);
    // 0x804BCE08: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x804BCE0C: jal         0x8002F96C
    // 0x804BCE10: nop

    func_8002F96C(rdram, ctx);
        goto after_7;
    // 0x804BCE10: nop

    after_7:
    // 0x804BCE14: b           L_804BCE3C
    // 0x804BCE18: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_804BCE3C;
    // 0x804BCE18: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_804BCE1C:
    // 0x804BCE1C: jal         0x8002F6E4
    // 0x804BCE20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_8;
    // 0x804BCE20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x804BCE24: b           L_804BCE3C
    // 0x804BCE28: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_804BCE3C;
    // 0x804BCE28: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x804BCE2C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_804BCE30:
    // 0x804BCE30: bne         $s1, $s5, L_804BCC9C
    if (ctx->r17 != ctx->r21) {
        // 0x804BCE34: addiu       $s0, $s0, 0x6
        ctx->r16 = ADD32(ctx->r16, 0X6);
            goto L_804BCC9C;
    }
    // 0x804BCE34: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
L_804BCE38:
    // 0x804BCE38: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_804BCE3C:
    // 0x804BCE3C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804BCE40: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804BCE44: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x804BCE48: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x804BCE4C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x804BCE50: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x804BCE54: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x804BCE58: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x804BCE5C: jr          $ra
    // 0x804BCE60: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x804BCE60: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_8046B08C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046B08C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046B090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046B094: jal         0x80469F00
    // 0x8046B098: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80469F00(rdram, ctx);
        goto after_0;
    // 0x8046B098: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046B09C: beq         $v0, $zero, L_8046B0B4
    if (ctx->r2 == 0) {
        // 0x8046B0A0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8046B0B4;
    }
    // 0x8046B0A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046B0A4: jal         0x8046AF80
    // 0x8046B0A8: nop

    func_8046AF80(rdram, ctx);
        goto after_1;
    // 0x8046B0A8: nop

    after_1:
    // 0x8046B0AC: b           L_8046B128
    // 0x8046B0B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8046B128;
    // 0x8046B0B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046B0B4:
    // 0x8046B0B4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046B0B8: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x8046B0BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8046B0C0: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8046B0C4: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x8046B0C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8046B0CC: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8046B0D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8046B0D4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8046B0D8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8046B0DC: nop

    // 0x8046B0E0: bc1fl       L_8046B0F4
    if (!c1cs) {
        // 0x8046B0E4: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8046B0F4;
    }
    goto skip_0;
    // 0x8046B0E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x8046B0E8: b           L_8046B11C
    // 0x8046B0EC: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
        goto L_8046B11C;
    // 0x8046B0EC: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x8046B0F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8046B0F4:
    // 0x8046B0F4: nop

    // 0x8046B0F8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8046B0FC: nop

    // 0x8046B100: bc1fl       L_8046B114
    if (!c1cs) {
        // 0x8046B104: trunc.w.s   $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_8046B114;
    }
    goto skip_1;
    // 0x8046B104: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_1:
    // 0x8046B108: b           L_8046B11C
    // 0x8046B10C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8046B11C;
    // 0x8046B10C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8046B110: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
L_8046B114:
    // 0x8046B114: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8046B118: nop

L_8046B11C:
    // 0x8046B11C: jal         0x8046AFC8
    // 0x8046B120: nop

    func_8046AFC8(rdram, ctx);
        goto after_2;
    // 0x8046B120: nop

    after_2:
    // 0x8046B124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046B128:
    // 0x8046B128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046B12C: jr          $ra
    // 0x8046B130: nop

    return;
    // 0x8046B130: nop

;}
RECOMP_FUNC void func_80566EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566EEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80566EF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566EF4: jal         0x80566E48
    // 0x80566EF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80566E48(rdram, ctx);
        goto after_0;
    // 0x80566EF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80566EFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80566F00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80566F04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80566F08: jal         0x805670F4
    // 0x80566F0C: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    func_805670F4(rdram, ctx);
        goto after_1;
    // 0x80566F0C: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    after_1:
    // 0x80566F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80566F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80566F18: jr          $ra
    // 0x80566F1C: nop

    return;
    // 0x80566F1C: nop

;}
RECOMP_FUNC void func_8000DB94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DB94: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8000DB98: bne         $t6, $zero, L_8000DBCC
    if (ctx->r14 != 0) {
        // 0x8000DB9C: nop
    
            goto L_8000DBCC;
    }
    // 0x8000DB9C: nop

    // 0x8000DBA0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8000DBA4: sw          $a1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r5;
    // 0x8000DBA8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8000DBAC: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x8000DBB0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8000DBB4: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8000DBB8: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x8000DBBC: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x8000DBC0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8000DBC4: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x8000DBC8: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
L_8000DBCC:
    // 0x8000DBCC: jr          $ra
    // 0x8000DBD0: nop

    return;
    // 0x8000DBD0: nop

;}
RECOMP_FUNC void func_80682DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682DA4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682DA8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682DAC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682DB0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682DB4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682DB8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682DBC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682DC0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682DC4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682DC8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682DCC: jr          $ra
    // 0x80682DD0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682DD0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806E3DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E3DD0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x806E3DD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E3DD8: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E3DDC: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x806E3DE0: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806E3DE4: lw          $t6, 0x3C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X3C);
    // 0x806E3DE8: lui         $t8, 0x806E
    ctx->r24 = S32(RELOC_HI16(649, 0X1960) << 16);
    // 0x806E3DEC: addiu       $t8, $t8, 0x5160
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(649, 0X1960));
    // 0x806E3DF0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806E3DF4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806E3DF8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x806E3DFC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x806E3E00: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x806E3E04: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x806E3E08: beq         $t9, $zero, L_806E3E48
    if (ctx->r25 == 0) {
        // 0x806E3E0C: neg.s       $f12, $f12
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
            goto L_806E3E48;
    }
    // 0x806E3E0C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x806E3E10: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x806E3E14: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x806E3E18: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x806E3E1C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x806E3E20: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806E3E24: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x806E3E28: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806E3E2C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806E3E30: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806E3E34: nop

    // 0x806E3E38: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x806E3E3C: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x806E3E40: b           L_806E3E78
    // 0x806E3E44: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
        goto L_806E3E78;
    // 0x806E3E44: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
L_806E3E48:
    // 0x806E3E48: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x806E3E4C: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x806E3E50: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x806E3E54: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x806E3E58: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806E3E5C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x806E3E60: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806E3E64: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806E3E68: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806E3E6C: nop

    // 0x806E3E70: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x806E3E74: nop

L_806E3E78:
    // 0x806E3E78: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x806E3E7C: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x806E3E80: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x806E3E84: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x806E3E88: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x806E3E8C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x806E3E90: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x806E3E94: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x806E3E98: jal         0x80066DE4
    // 0x806E3E9C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x806E3E9C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x806E3EA0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806E3EA4: jal         0x80066E88
    // 0x806E3EA8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x806E3EA8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x806E3EAC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x806E3EB0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x806E3EB4: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x806E3EB8: lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4);
    // 0x806E3EBC: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x806E3EC0: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x806E3EC4: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x806E3EC8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x806E3ECC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806E3ED0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806E3ED4: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x806E3ED8: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x806E3EDC: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x806E3EE0: mul.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x806E3EE4: nop

    // 0x806E3EE8: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806E3EEC: nop

    // 0x806E3EF0: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x806E3EF4: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x806E3EF8: mul.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x806E3EFC: nop

    // 0x806E3F00: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x806E3F04: swc1        $f4, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f4.u32l;
    // 0x806E3F08: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806E3F0C: swc1        $f6, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f6.u32l;
    // 0x806E3F10: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x806E3F14: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x806E3F18: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x806E3F1C: nop

    // 0x806E3F20: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806E3F24: mul.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x806E3F28: nop

    // 0x806E3F2C: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x806E3F30: nop

    // 0x806E3F34: mul.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x806E3F38: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806E3F3C: mul.s       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x806E3F40: nop

    // 0x806E3F44: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x806E3F48: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x806E3F4C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x806E3F50: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x806E3F54: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    // 0x806E3F58: sw          $a1, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r5;
    // 0x806E3F5C: sw          $a1, 0x138($a2)
    MEM_W(0X138, ctx->r6) = ctx->r5;
    // 0x806E3F60: lwc1        $f4, 0x6C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x806E3F64: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x806E3F68: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x806E3F6C: swc1        $f6, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f6.u32l;
    // 0x806E3F70: lwc1        $f8, 0x70($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X70);
    // 0x806E3F74: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x806E3F78: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x806E3F7C: swc1        $f10, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f10.u32l;
    // 0x806E3F80: lwc1        $f6, 0x50($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806E3F84: swc1        $f6, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f6.u32l;
    // 0x806E3F88: lw          $t6, 0x138($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X138);
    // 0x806E3F8C: bne         $t6, $zero, L_806E3FA8
    if (ctx->r14 != 0) {
        // 0x806E3F90: nop
    
            goto L_806E3FA8;
    }
    // 0x806E3F90: nop

    // 0x806E3F94: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806E3F98: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x806E3F9C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x806E3FA0: b           L_806E3FB8
    // 0x806E3FA4: swc1        $f10, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f10.u32l;
        goto L_806E3FB8;
    // 0x806E3FA4: swc1        $f10, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f10.u32l;
L_806E3FA8:
    // 0x806E3FA8: lwc1        $f6, 0x50($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806E3FAC: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x806E3FB0: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806E3FB4: swc1        $f4, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f4.u32l;
L_806E3FB8:
    // 0x806E3FB8: lw          $t7, 0x3C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X3C);
    // 0x806E3FBC: lui         $t9, 0x806E
    ctx->r25 = S32(RELOC_HI16(649, 0X1FB0) << 16);
    // 0x806E3FC0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806E3FC4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x806E3FC8: lw          $t9, 0x57B0($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(649, 0X1FB0));
    // 0x806E3FCC: jal         0x806E3BD4
    // 0x806E3FD0: sh          $t9, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r25;
    func_806E3BD4(rdram, ctx);
        goto after_2;
    // 0x806E3FD0: sh          $t9, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r25;
    after_2:
    // 0x806E3FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E3FD8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x806E3FDC: jr          $ra
    // 0x806E3FE0: nop

    return;
    // 0x806E3FE0: nop

;}
RECOMP_FUNC void func_805AE384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE384: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE388: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE38C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE390: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE394: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE398: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE39C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE3A0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE3A4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE3A8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE3AC: jr          $ra
    // 0x805AE3B0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE3B0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805D3760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D3760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D3764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D3768: jal         0x805D3358
    // 0x805D376C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805D3358(rdram, ctx);
        goto after_0;
    // 0x805D376C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D3770: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D3774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D3778: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805D377C: jal         0x805D3B18
    // 0x805D3780: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_805D3B18(rdram, ctx);
        goto after_1;
    // 0x805D3780: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x805D3784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D3788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D378C: jr          $ra
    // 0x805D3790: nop

    return;
    // 0x805D3790: nop

;}
RECOMP_FUNC void func_800755E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800755E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800755E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800755E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800755EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800755F0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800755F4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800755F8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800755FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80075600: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80075604: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80075608: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x8007560C: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x80075610: sw          $zero, 0x248($s0)
    MEM_W(0X248, ctx->r16) = 0;
    // 0x80075614: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x80075618: sh          $t7, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r15;
    // 0x8007561C: sh          $t8, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r24;
    // 0x80075620: sb          $zero, 0x24C($s0)
    MEM_B(0X24C, ctx->r16) = 0;
    // 0x80075624: sw          $t1, 0x254($s0)
    MEM_W(0X254, ctx->r16) = ctx->r9;
    // 0x80075628: sw          $t0, 0x250($s0)
    MEM_W(0X250, ctx->r16) = ctx->r8;
    // 0x8007562C: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    // 0x80075630: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80075634: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    // 0x80075638: jal         0x8008AE20
    // 0x8007563C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8007563C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x80075640: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80075644: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80075648: jal         0x80089D70
    // 0x8007564C: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8007564C: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    after_1:
    // 0x80075650: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80075654: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    // 0x80075658: jal         0x8008D5B0
    // 0x8007565C: lbu         $a2, 0x3F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3F);
    osViSetEvent_recomp(rdram, ctx);
        goto after_2;
    // 0x8007565C: lbu         $a2, 0x3F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3F);
    after_2:
    // 0x80075660: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80075664: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80075668: addiu       $a0, $s0, 0x98
    ctx->r4 = ADD32(ctx->r16, 0X98);
    // 0x8007566C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80075670: addiu       $a2, $a2, 0x5468
    ctx->r6 = ADD32(ctx->r6, 0X5468);
    // 0x80075674: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80075678: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x8007567C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80075680: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80075684: jal         0x80085B10
    // 0x80075688: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    osCreateThread_recomp(rdram, ctx);
        goto after_3;
    // 0x80075688: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_3:
    // 0x8007568C: jal         0x80090CC0
    // 0x80075690: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osStartThread_recomp(rdram, ctx);
        goto after_4;
    // 0x80075690: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80075694: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80075698: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007569C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800756A0: jr          $ra
    // 0x800756A4: nop

    return;
    // 0x800756A4: nop

;}
RECOMP_FUNC void func_80665068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80665068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066506C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80665070: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80665074: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x80665078: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8066507C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80665080: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80665084: jal         0x80065728
    // 0x80665088: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80665088: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8066508C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80665090: jal         0x80665264
    // 0x80665094: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80665264(rdram, ctx);
        goto after_1;
    // 0x80665094: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80665098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066509C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806650A0: jr          $ra
    // 0x806650A4: nop

    return;
    // 0x806650A4: nop

;}
RECOMP_FUNC void func_806EBDC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EBDC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EBDC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EBDC8: jal         0x806EBD68
    // 0x806EBDCC: nop

    func_806EBD68(rdram, ctx);
        goto after_0;
    // 0x806EBDCC: nop

    after_0:
    // 0x806EBDD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EBDD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EBDD8: jr          $ra
    // 0x806EBDDC: nop

    return;
    // 0x806EBDDC: nop

;}
RECOMP_FUNC void func_8069EFC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069EFC0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8069EFC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8069EFC8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8069EFCC: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x8069EFD0: lbu         $v0, 0x10($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X10);
    // 0x8069EFD4: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x8069EFD8: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8069EFDC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8069EFE0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8069EFE4: bgezl       $v0, L_8069F000
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8069EFE8: lw          $t6, 0x1F4($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X1F4);
            goto L_8069F000;
    }
    goto skip_0;
    // 0x8069EFE8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    skip_0:
    // 0x8069EFEC: jal         0x800447C8
    // 0x8069EFF0: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x8069EFF0: nop

    after_0:
    // 0x8069EFF4: b           L_8069F178
    // 0x8069EFF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8069F178;
    // 0x8069EFF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8069EFFC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
L_8069F000:
    // 0x8069F000: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8069F004: lwc1        $f14, 0xC4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8069F008: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8069F00C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8069F010: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8069F014: sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // 0x8069F018: jal         0x80081E8C
    // 0x8069F01C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    fatan2(rdram, ctx);
        goto after_1;
    // 0x8069F01C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_1:
    // 0x8069F020: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8069F024: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8069F028: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5C0) << 16);
    // 0x8069F02C: lwc1        $f6, -0xAD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5C0));
    // 0x8069F030: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8069F034: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8069F038: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8069F03C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8069F040: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8069F044: lh          $v0, 0x3A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X3A);
    // 0x8069F048: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8069F04C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8069F050: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8069F054: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8069F058: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x8069F05C: lwc1        $f16, 0x50($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8069F060: lwc1        $f14, 0x8($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8069F064: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x8069F068: sub.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8069F06C: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x8069F070: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8069F074: bc1fl       L_8069F090
    if (!c1cs) {
        // 0x8069F078: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8069F090;
    }
    goto skip_1;
    // 0x8069F078: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x8069F07C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8069F080: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8069F084: b           L_8069F0B0
    // 0x8069F088: sub.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
        goto L_8069F0B0;
    // 0x8069F088: sub.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8069F08C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8069F090:
    // 0x8069F090: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8069F094: c.le.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
    // 0x8069F098: nop

    // 0x8069F09C: bc1fl       L_8069F0B4
    if (!c1cs) {
        // 0x8069F0A0: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_8069F0B4;
    }
    goto skip_2;
    // 0x8069F0A0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_2:
    // 0x8069F0A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8069F0A8: nop

    // 0x8069F0AC: add.s       $f20, $f12, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f12.fl + ctx->f8.fl;
L_8069F0B0:
    // 0x8069F0B0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_8069F0B4:
    // 0x8069F0B4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8069F0B8: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8069F0BC: jal         0x80065954
    // 0x8069F0C0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8069F0C0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8069F0C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8069F0C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8069F0CC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8069F0D0: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8069F0D4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8069F0D8: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8069F0DC: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5C4) << 16);
    // 0x8069F0E0: bc1fl       L_8069F0F4
    if (!c1cs) {
        // 0x8069F0E4: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8069F0F4;
    }
    goto skip_3;
    // 0x8069F0E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_3:
    // 0x8069F0E8: b           L_8069F114
    // 0x8069F0EC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
        goto L_8069F114;
    // 0x8069F0EC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8069F0F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8069F0F4:
    // 0x8069F0F4: nop

    // 0x8069F0F8: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x8069F0FC: nop

    // 0x8069F100: bc1fl       L_8069F114
    if (!c1cs) {
        // 0x8069F104: sub.s       $f16, $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f2.fl;
            goto L_8069F114;
    }
    goto skip_4;
    // 0x8069F104: sub.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f2.fl;
    skip_4:
    // 0x8069F108: b           L_8069F114
    // 0x8069F10C: add.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f2.fl;
        goto L_8069F114;
    // 0x8069F10C: add.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8069F110: sub.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f2.fl;
L_8069F114:
    // 0x8069F114: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    // 0x8069F118: lwc1        $f4, -0xACC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5C4));
    // 0x8069F11C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8069F120: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5C8) << 16);
    // 0x8069F124: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x8069F128: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8069F12C: nop

    // 0x8069F130: bc1fl       L_8069F140
    if (!c1cs) {
        // 0x8069F134: swc1        $f14, 0x8($t8)
        MEM_W(0X8, ctx->r24) = ctx->f14.u32l;
            goto L_8069F140;
    }
    goto skip_5;
    // 0x8069F134: swc1        $f14, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f14.u32l;
    skip_5:
    // 0x8069F138: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x8069F13C: swc1        $f14, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f14.u32l;
L_8069F140:
    // 0x8069F140: lwc1        $f6, -0xAC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5C8));
    // 0x8069F144: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5CC) << 16);
    // 0x8069F148: lwc1        $f10, -0xAC4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5CC));
    // 0x8069F14C: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8069F150: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5D0) << 16);
    // 0x8069F154: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8069F158: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8069F15C: lwc1        $f6, -0xAC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5D0));
    // 0x8069F160: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(580, 0X5D4) << 16);
    // 0x8069F164: lwc1        $f10, -0xABC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(580, 0X5D4));
    // 0x8069F168: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8069F16C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8069F170: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    // 0x8069F174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069F178:
    // 0x8069F178: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8069F17C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8069F180: jr          $ra
    // 0x8069F184: nop

    return;
    // 0x8069F184: nop

;}
RECOMP_FUNC void func_807602F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807602F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807602FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80760300: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80760304: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80760308: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8076030C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80760310: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80760314: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80760318: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8076031C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80760320: addiu       $t6, $zero, 0x708
    ctx->r14 = ADD32(0, 0X708);
    // 0x80760324: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80760328: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8076032C: addiu       $a3, $zero, 0x6CC
    ctx->r7 = ADD32(0, 0X6CC);
    // 0x80760330: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80760334: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80760338: jal         0x8076009C
    // 0x8076033C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_8076009C(rdram, ctx);
        goto after_0;
    // 0x8076033C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80760340: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80760344: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80760348: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8076034C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80760350: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80760354: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80760358: jr          $ra
    // 0x8076035C: nop

    return;
    // 0x8076035C: nop

;}
RECOMP_FUNC void func_80445858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445858: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8044585C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80445860: addu        $t6, $v1, $a1
    ctx->r14 = ADD32(ctx->r3, ctx->r5);
    // 0x80445864: lbu         $v0, 0xF64($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XF64);
    // 0x80445868: lw          $t9, 0xFB8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XFB8);
    // 0x8044586C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80445870: lui         $a2, 0x8045
    ctx->r6 = S32(RELOC_HI16(98, 0X13118) << 16);
    // 0x80445874: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80445878: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8044587C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80445880: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x80445884: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x80445888: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8044588C: bne         $t1, $zero, L_804458CC
    if (ctx->r9 != 0) {
        // 0x80445890: lbu         $a2, 0x74F8($a2)
        ctx->r6 = MEM_BU(ctx->r6, (int16_t)RELOC_LO16(98, 0X13118));
            goto L_804458CC;
    }
    // 0x80445890: lbu         $a2, 0x74F8($a2)
    ctx->r6 = MEM_BU(ctx->r6, (int16_t)RELOC_LO16(98, 0X13118));
    // 0x80445894: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14038) << 16);
    // 0x80445898: lwc1        $f0, -0x7BE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14038));
    // 0x8044589C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804458A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804458A4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1403C) << 16);
    // 0x804458A8: lwc1        $f6, -0x7BE4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1403C));
    // 0x804458AC: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x804458B0: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x804458B4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x804458B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x804458BC: jal         0x80444B28
    // 0x804458C0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80444B28(rdram, ctx);
        goto after_0;
    // 0x804458C0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x804458C4: b           L_804458F8
    // 0x804458C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_804458F8;
    // 0x804458C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804458CC:
    // 0x804458CC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14040) << 16);
    // 0x804458D0: lwc1        $f0, -0x7BE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14040));
    // 0x804458D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804458D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804458DC: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x804458E0: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x804458E4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x804458E8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x804458EC: jal         0x80444B28
    // 0x804458F0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_80444B28(rdram, ctx);
        goto after_1;
    // 0x804458F0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x804458F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804458F8:
    // 0x804458F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804458FC: jr          $ra
    // 0x80445900: nop

    return;
    // 0x80445900: nop

;}
RECOMP_FUNC void func_8064B3E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B3E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B3E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8064B3E8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8064B3EC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8064B3F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B3F4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8064B3F8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8064B3FC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8064B400: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8064B404: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8064B408: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8064B40C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8064B410: lui         $t2, 0x8065
    ctx->r10 = S32(RELOC_HI16(495, 0X2FBC) << 16);
    // 0x8064B414: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8064B418: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8064B41C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8064B420: lw          $t2, -0x2F74($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(495, 0X2FBC));
    // 0x8064B424: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8064B428: jal         0x8064B1BC
    // 0x8064B42C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_8064B1BC(rdram, ctx);
        goto after_0;
    // 0x8064B42C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x8064B430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064B434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B438: jr          $ra
    // 0x8064B43C: nop

    return;
    // 0x8064B43C: nop

;}
RECOMP_FUNC void func_8064ED54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064ED54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8064ED58: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8064ED5C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8064ED60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8064ED64: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8064ED68: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8064ED6C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8064ED70: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064ED74: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x8064ED78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8064ED7C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8064ED80: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x8064ED84: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8064ED88: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8064ED8C: jal         0x8064EA0C
    // 0x8064ED90: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_8064EA0C(rdram, ctx);
        goto after_0;
    // 0x8064ED90: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8064ED94: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8064ED98: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8064ED9C: addiu       $t8, $zero, 0x1D88
    ctx->r24 = ADD32(0, 0X1D88);
    // 0x8064EDA0: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x8064EDA4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8064EDA8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8064EDAC: addiu       $a1, $zero, 0x1A4
    ctx->r5 = ADD32(0, 0X1A4);
    // 0x8064EDB0: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8064EDB4: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x8064EDB8: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8064EDBC: jal         0x8064EA0C
    // 0x8064EDC0: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_8064EA0C(rdram, ctx);
        goto after_1;
    // 0x8064EDC0: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x8064EDC4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8064EDC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064EDCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064EDD0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8064EDD4: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8064EDD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8064EDDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8064EDE0: jr          $ra
    // 0x8064EDE4: nop

    return;
    // 0x8064EDE4: nop

;}
RECOMP_FUNC void func_80424618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042461C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80424620: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80424624: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80424628: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(35, 0X34A8) << 16);
    // 0x8042462C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80424630: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80424634: lw          $t8, 0x5EA8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(35, 0X34A8));
    // 0x80424638: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042463C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80424640: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80424644: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80424648: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8042464C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80424650: beql        $v1, $zero, L_80424684
    if (ctx->r3 == 0) {
        // 0x80424654: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80424684;
    }
    goto skip_0;
    // 0x80424654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80424658: jalr        $v1
    // 0x8042465C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8042465C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80424660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80424664: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80424668: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8042466C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80424670: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80424674: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80424678: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8042467C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80424680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80424684:
    // 0x80424684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80424688: jr          $ra
    // 0x8042468C: nop

    return;
    // 0x8042468C: nop

;}
RECOMP_FUNC void func_8005EBD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EBD8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005EBDC: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8005EBE0: jr          $ra
    // 0x8005EBE4: sb          $t6, 0x38($t7)
    MEM_B(0X38, ctx->r15) = ctx->r14;
    return;
    // 0x8005EBE4: sb          $t6, 0x38($t7)
    MEM_B(0X38, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_806F28B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F28B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F28BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F28C0: jal         0x806F27E4
    // 0x806F28C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F27E4(rdram, ctx);
        goto after_0;
    // 0x806F28C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F28C8: jal         0x806F2818
    // 0x806F28CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806F2818(rdram, ctx);
        goto after_1;
    // 0x806F28CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806F28D0: jal         0x806F25B4
    // 0x806F28D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806F25B4(rdram, ctx);
        goto after_2;
    // 0x806F28D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806F28D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F28DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F28E0: jr          $ra
    // 0x806F28E4: nop

    return;
    // 0x806F28E4: nop

;}
RECOMP_FUNC void func_80074AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074AE8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80074AEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074AF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80074AF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074AF8: jal         0x800744B0
    // 0x80074AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800744B0(rdram, ctx);
        goto after_0;
    // 0x80074AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80074B00: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80074B04: jal         0x80085C60
    // 0x80074B08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osContStartReadData_recomp(rdram, ctx);
        goto after_1;
    // 0x80074B08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074B0C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80074B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80074B14: jal         0x800824B0
    // 0x80074B18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80074B18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80074B1C: addiu       $a0, $s0, 0x290
    ctx->r4 = ADD32(ctx->r16, 0X290);
    // 0x80074B20: jal         0x80085CEC
    // 0x80074B24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    osContGetReadData_recomp(rdram, ctx);
        goto after_3;
    // 0x80074B24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_3:
    // 0x80074B28: addiu       $a0, $s0, 0x296
    ctx->r4 = ADD32(ctx->r16, 0X296);
    // 0x80074B2C: jal         0x80084820
    // 0x80074B30: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    _blkclr(rdram, ctx);
        goto after_4;
    // 0x80074B30: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_4:
    // 0x80074B34: lbu         $t6, 0x45E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X45E);
    // 0x80074B38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80074B3C: beq         $t6, $zero, L_80074B4C
    if (ctx->r14 == 0) {
        // 0x80074B40: nop
    
            goto L_80074B4C;
    }
    // 0x80074B40: nop

    // 0x80074B44: jal         0x80084820
    // 0x80074B48: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    _blkclr(rdram, ctx);
        goto after_5;
    // 0x80074B48: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_5:
L_80074B4C:
    // 0x80074B4C: jal         0x80074908
    // 0x80074B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80074908(rdram, ctx);
        goto after_6;
    // 0x80074B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80074B54: jal         0x80089DF0
    // 0x80074B58: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osContStartQuery_recomp(rdram, ctx);
        goto after_7;
    // 0x80074B58: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80074B5C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80074B60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80074B64: jal         0x800824B0
    // 0x80074B68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x80074B68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80074B6C: jal         0x80089E74
    // 0x80074B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osContGetQuery_recomp(rdram, ctx);
        goto after_9;
    // 0x80074B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80074B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074B78: jal         0x8007451C
    // 0x80074B7C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8007451C(rdram, ctx);
        goto after_10;
    // 0x80074B7C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x80074B80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80074B84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80074B88: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80074B8C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80074B90: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_80074B94:
    // 0x80074B94: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
    // 0x80074B98: bnel        $t7, $zero, L_80074BBC
    if (ctx->r15 != 0) {
        // 0x80074B9C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80074BBC;
    }
    goto skip_0;
    // 0x80074B9C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80074BA0: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x80074BA4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80074BA8: sllv        $t0, $t9, $v0
    ctx->r8 = S32(ctx->r25 << (ctx->r2 & 31));
    // 0x80074BAC: bnel        $a1, $t8, L_80074BBC
    if (ctx->r5 != ctx->r24) {
        // 0x80074BB0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80074BBC;
    }
    goto skip_1;
    // 0x80074BB0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x80074BB4: or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    // 0x80074BB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80074BBC:
    // 0x80074BBC: bne         $v0, $a2, L_80074B94
    if (ctx->r2 != ctx->r6) {
        // 0x80074BC0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80074B94;
    }
    // 0x80074BC0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80074BC4: sb          $a0, 0x2A8($s0)
    MEM_B(0X2A8, ctx->r16) = ctx->r4;
    // 0x80074BC8: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x80074BCC: addiu       $t1, $t1, -0x7FFC
    ctx->r9 = ADD32(ctx->r9, -0X7FFC);
    // 0x80074BD0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80074BD4: beql        $t2, $zero, L_80074BF0
    if (ctx->r10 == 0) {
        // 0x80074BD8: lbu         $t3, 0x45C($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X45C);
            goto L_80074BF0;
    }
    goto skip_2;
    // 0x80074BD8: lbu         $t3, 0x45C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X45C);
    skip_2:
    // 0x80074BDC: jal         0x8007480C
    // 0x80074BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007480C(rdram, ctx);
        goto after_11;
    // 0x80074BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80074BE4: b           L_80074C54
    // 0x80074BE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80074C54;
    // 0x80074BE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074BEC: lbu         $t3, 0x45C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X45C);
L_80074BF0:
    // 0x80074BF0: blezl       $t3, L_80074C18
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80074BF4: lbu         $t6, 0x45D($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X45D);
            goto L_80074C18;
    }
    goto skip_3;
    // 0x80074BF4: lbu         $t6, 0x45D($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X45D);
    skip_3:
    // 0x80074BF8: lbu         $t4, 0x45C($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X45C);
    // 0x80074BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074C00: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80074C04: jal         0x8007480C
    // 0x80074C08: sb          $t5, 0x45C($s0)
    MEM_B(0X45C, ctx->r16) = ctx->r13;
    func_8007480C(rdram, ctx);
        goto after_12;
    // 0x80074C08: sb          $t5, 0x45C($s0)
    MEM_B(0X45C, ctx->r16) = ctx->r13;
    after_12:
    // 0x80074C0C: b           L_80074C54
    // 0x80074C10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80074C54;
    // 0x80074C10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074C14: lbu         $t6, 0x45D($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X45D);
L_80074C18:
    // 0x80074C18: bnel        $t6, $zero, L_80074C34
    if (ctx->r14 != 0) {
        // 0x80074C1C: lbu         $t7, 0x45E($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X45E);
            goto L_80074C34;
    }
    goto skip_4;
    // 0x80074C1C: lbu         $t7, 0x45E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X45E);
    skip_4:
    // 0x80074C20: jal         0x8007480C
    // 0x80074C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007480C(rdram, ctx);
        goto after_13;
    // 0x80074C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80074C28: b           L_80074C54
    // 0x80074C2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80074C54;
    // 0x80074C2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074C30: lbu         $t7, 0x45E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X45E);
L_80074C34:
    // 0x80074C34: bnel        $t7, $zero, L_80074C54
    if (ctx->r15 != 0) {
        // 0x80074C38: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80074C54;
    }
    goto skip_5;
    // 0x80074C38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80074C3C: jal         0x800745E0
    // 0x80074C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800745E0(rdram, ctx);
        goto after_14;
    // 0x80074C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80074C44: lbu         $t8, 0x45D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X45D);
    // 0x80074C48: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80074C4C: sb          $t9, 0x45D($s0)
    MEM_B(0X45D, ctx->r16) = ctx->r25;
    // 0x80074C50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80074C54:
    // 0x80074C54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074C58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80074C5C: jr          $ra
    // 0x80074C60: nop

    return;
    // 0x80074C60: nop

;}
RECOMP_FUNC void func_8001A5A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A5A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001A5A8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001A5AC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001A5B0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8001A5B4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8001A5B8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8001A5BC: jr          $ra
    // 0x8001A5C0: lw          $v0, 0x5A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5A0);
    return;
    // 0x8001A5C0: lw          $v0, 0x5A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5A0);
;}
RECOMP_FUNC void guScaleF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80082694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082698: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008269C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800826A0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800826A4: jal         0x80086EA0
    // 0x800826A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800826A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800826AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800826B0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800826B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800826B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800826BC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800826C0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800826C4: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x800826C8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800826CC: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x800826D0: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x800826D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800826D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800826DC: jr          $ra
    // 0x800826E0: nop

    return;
    // 0x800826E0: nop

;}
RECOMP_FUNC void func_8076CC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076CC30: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8076CC34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8076CC38: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8076CC3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8076CC40: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8076CC44: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8076CC48: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076CC4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8076CC50: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8076CC54: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8076CC58: lw          $t6, 0x1F4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1F4);
    // 0x8076CC5C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8076CC60: jal         0x8004700C
    // 0x8076CC64: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8076CC64: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x8076CC68: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8076CC6C: lbu         $t7, 0x18($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X18);
    // 0x8076CC70: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8076CC74: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8076CC78: beql        $t7, $at, L_8076CC9C
    if (ctx->r15 == ctx->r1) {
        // 0x8076CC7C: lwc1        $f4, 0x3C($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
            goto L_8076CC9C;
    }
    goto skip_0;
    // 0x8076CC7C: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    skip_0:
    // 0x8076CC80: lhu         $t8, 0xC($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0XC);
    // 0x8076CC84: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8076CC88: bnel        $t8, $at, L_8076CD78
    if (ctx->r24 != ctx->r1) {
        // 0x8076CC8C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8076CD78;
    }
    goto skip_1;
    // 0x8076CC8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8076CC90: b           L_8076CD78
    // 0x8076CC94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8076CD78;
    // 0x8076CC94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8076CC98: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
L_8076CC9C:
    // 0x8076CC9C: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(766, 0X3AC0) << 16);
    // 0x8076CCA0: lwc1        $f8, 0x2B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(766, 0X3AC0));
    // 0x8076CCA4: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8076CCA8: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8076CCAC: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x8076CCB0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x8076CCB4: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8076CCB8: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8076CCBC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8076CCC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8076CCC4: lw          $t9, 0x18($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X18);
    // 0x8076CCC8: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8076CCCC: jalr        $t9
    // 0x8076CCD0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8076CCD0: nop

    after_1:
    // 0x8076CCD4: jal         0x800447C8
    // 0x8076CCD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x8076CCD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8076CCDC: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x8076CCE0: jal         0x80067BBC
    // 0x8076CCE4: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8076CCE4: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_3:
    // 0x8076CCE8: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    // 0x8076CCEC: jal         0x80067818
    // 0x8076CCF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8076CCF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8076CCF4: jal         0x8005FD1C
    // 0x8076CCF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FD1C(rdram, ctx);
        goto after_5;
    // 0x8076CCF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8076CCFC: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    // 0x8076CD00: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8076CD04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8076CD08: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8076CD0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076CD10: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8076CD14: sh          $zero, 0x12($t2)
    MEM_H(0X12, ctx->r10) = 0;
    // 0x8076CD18: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8076CD1C: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8076CD20: jal         0x8076DD8C
    // 0x8076CD24: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    func_8076DD8C(rdram, ctx);
        goto after_6;
    // 0x8076CD24: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    after_6:
    // 0x8076CD28: jal         0x8005FD1C
    // 0x8076CD2C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8005FD1C(rdram, ctx);
        goto after_7;
    // 0x8076CD2C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x8076CD30: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8076CD34: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8076CD38: lw          $t4, 0x174($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X174);
    // 0x8076CD3C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8076CD40: beq         $a0, $zero, L_8076CD74
    if (ctx->r4 == 0) {
        // 0x8076CD44: sh          $zero, 0x12($t5)
        MEM_H(0X12, ctx->r13) = 0;
            goto L_8076CD74;
    }
    // 0x8076CD44: sh          $zero, 0x12($t5)
    MEM_H(0X12, ctx->r13) = 0;
    // 0x8076CD48: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8076CD4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8076CD50: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8076CD54: bnel        $t6, $at, L_8076CD78
    if (ctx->r14 != ctx->r1) {
        // 0x8076CD58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8076CD78;
    }
    goto skip_2;
    // 0x8076CD58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8076CD5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8076CD60: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8076CD64: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8076CD68: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8076CD6C: jal         0x8076CBC0
    // 0x8076CD70: nop

    func_8076CBC0(rdram, ctx);
        goto after_8;
    // 0x8076CD70: nop

    after_8:
L_8076CD74:
    // 0x8076CD74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076CD78:
    // 0x8076CD78: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8076CD7C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8076CD80: jr          $ra
    // 0x8076CD84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8076CD84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void __sinf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082730: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x80082734: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80082738: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8008273C: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x80082740: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x80082744: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x80082748: beq         $at, $zero, L_800827B0
    if (ctx->r1 == 0) {
        // 0x8008274C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800827B0;
    }
    // 0x8008274C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80082750: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x80082754: bne         $at, $zero, L_800827A8
    if (ctx->r1 != 0) {
        // 0x80082758: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_800827A8;
    }
    // 0x80082758: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x8008275C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80082760: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80082764: addiu       $v1, $v1, 0x3220
    ctx->r3 = ADD32(ctx->r3, 0X3220);
    // 0x80082768: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x8008276C: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x80082770: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x80082774: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x80082778: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8008277C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x80082780: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x80082784: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80082788: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x8008278C: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x80082790: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x80082794: nop

    // 0x80082798: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x8008279C: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x800827A0: jr          $ra
    // 0x800827A4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x800827A4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_800827A8:
    // 0x800827A8: jr          $ra
    // 0x800827AC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    return;
    // 0x800827AC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
L_800827B0:
    // 0x800827B0: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x800827B4: beq         $at, $zero, L_800828C8
    if (ctx->r1 == 0) {
        // 0x800827B8: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
            goto L_800828C8;
    }
    // 0x800827B8: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800827BC: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800827C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800827C4: ldc1        $f10, 0x3248($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X3248);
    // 0x800827C8: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x800827CC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800827D0: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x800827D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800827D8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800827DC: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x800827E0: nop

    // 0x800827E4: bc1fl       L_80082814
    if (!c1cs) {
        // 0x800827E8: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_80082814;
    }
    goto skip_0;
    // 0x800827E8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800827EC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800827F0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800827F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800827F8: nop

    // 0x800827FC: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x80082800: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x80082804: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80082808: b           L_80082830
    // 0x8008280C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_80082830;
    // 0x8008280C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80082810: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_80082814:
    // 0x80082814: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80082818: nop

    // 0x8008281C: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x80082820: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80082824: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80082828: nop

    // 0x8008282C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_80082830:
    // 0x80082830: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80082834: ldc1        $f18, 0x3250($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X3250);
    // 0x80082838: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x8008283C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80082840: ldc1        $f6, 0x3258($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X3258);
    // 0x80082844: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80082848: addiu       $v1, $v1, 0x3220
    ctx->r3 = ADD32(ctx->r3, 0X3220);
    // 0x8008284C: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x80082850: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x80082854: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x80082858: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8008285C: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x80082860: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x80082864: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x80082868: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x8008286C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80082870: nop

    // 0x80082874: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x80082878: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8008287C: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x80082880: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x80082884: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80082888: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x8008288C: bne         $t9, $zero, L_800828AC
    if (ctx->r25 != 0) {
        // 0x80082890: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_800828AC;
    }
    // 0x80082890: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x80082894: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x80082898: nop

    // 0x8008289C: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x800828A0: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800828A4: jr          $ra
    // 0x800828A8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800828A8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800828AC:
    // 0x800828AC: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800828B0: nop

    // 0x800828B4: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800828B8: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x800828BC: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x800828C0: jr          $ra
    // 0x800828C4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x800828C4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800828C8:
    // 0x800828C8: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x800828CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800828D0: bc1t        L_800828E4
    if (c1cs) {
        // 0x800828D4: nop
    
            goto L_800828E4;
    }
    // 0x800828D4: nop

    // 0x800828D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800828DC: jr          $ra
    // 0x800828E0: lwc1        $f0, 0x3440($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3440);
    return;
    // 0x800828E0: lwc1        $f0, 0x3440($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3440);
L_800828E4:
    // 0x800828E4: lwc1        $f0, 0x3260($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3260);
    // 0x800828E8: jr          $ra
    // 0x800828EC: nop

    return;
    // 0x800828EC: nop

;}
RECOMP_FUNC void func_805640B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805640B8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805640BC: lw          $v1, 0x2EC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2EC);
    // 0x805640C0: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x805640C4: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x805640C8: sw          $t6, 0x2EC($v0)
    MEM_W(0X2EC, ctx->r2) = ctx->r14;
    // 0x805640CC: bne         $at, $zero, L_805640D8
    if (ctx->r1 != 0) {
        // 0x805640D0: sw          $v1, 0x2E8($v0)
        MEM_W(0X2E8, ctx->r2) = ctx->r3;
            goto L_805640D8;
    }
    // 0x805640D0: sw          $v1, 0x2E8($v0)
    MEM_W(0X2E8, ctx->r2) = ctx->r3;
    // 0x805640D4: sw          $zero, 0x2EC($v0)
    MEM_W(0X2EC, ctx->r2) = 0;
L_805640D8:
    // 0x805640D8: jr          $ra
    // 0x805640DC: nop

    return;
    // 0x805640DC: nop

;}
RECOMP_FUNC void func_80760158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80760158: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8076015C: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(763, 0XC330) << 16);
    // 0x80760160: lwc1        $f4, -0x3C40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(763, 0XC330));
    // 0x80760164: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80760168: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8076016C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80760170: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80760174: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80760178: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8076017C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80760180: addiu       $t6, $zero, 0x654
    ctx->r14 = ADD32(0, 0X654);
    // 0x80760184: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80760188: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8076018C: addiu       $a3, $zero, 0x618
    ctx->r7 = ADD32(0, 0X618);
    // 0x80760190: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80760194: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80760198: jal         0x8076009C
    // 0x8076019C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_8076009C(rdram, ctx);
        goto after_0;
    // 0x8076019C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x807601A0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x807601A4: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x807601A8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x807601AC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x807601B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807601B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807601B8: jr          $ra
    // 0x807601BC: nop

    return;
    // 0x807601BC: nop

;}
RECOMP_FUNC void func_8006E9D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E9D4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8006E9D8: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8006E9DC: addiu       $t6, $t6, -0x120C
    ctx->r14 = ADD32(ctx->r14, -0X120C);
    // 0x8006E9E0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8006E9E4: jr          $ra
    // 0x8006E9E8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8006E9E8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80025D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025D7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025D84: jal         0x80067A10
    // 0x80025D88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80067A10(rdram, ctx);
        goto after_0;
    // 0x80025D88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80025D8C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80025D90: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80025D94: lw          $t6, 0x14C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X14C);
    // 0x80025D98: beql        $v1, $t6, L_80025E0C
    if (ctx->r3 == ctx->r14) {
        // 0x80025D9C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80025E0C;
    }
    goto skip_0;
    // 0x80025D9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80025DA0: beq         $v1, $zero, L_80025DB4
    if (ctx->r3 == 0) {
        // 0x80025DA4: sw          $v1, 0x14C($a3)
        MEM_W(0X14C, ctx->r7) = ctx->r3;
            goto L_80025DB4;
    }
    // 0x80025DA4: sw          $v1, 0x14C($a3)
    MEM_W(0X14C, ctx->r7) = ctx->r3;
    // 0x80025DA8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80025DAC: bnel        $v1, $at, L_80025DE8
    if (ctx->r3 != ctx->r1) {
        // 0x80025DB0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80025DE8;
    }
    goto skip_1;
    // 0x80025DB0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_1:
L_80025DB4:
    // 0x80025DB4: jal         0x8001D770
    // 0x80025DB8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x80025DB8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80025DBC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80025DC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80025DC4: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80025DC8: jal         0x80067BF8
    // 0x80025DCC: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_2;
    // 0x80025DCC: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x80025DD0: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    // 0x80025DD4: jal         0x80067818
    // 0x80025DD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80025DD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80025DDC: b           L_80025E0C
    // 0x80025DE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80025E0C;
    // 0x80025DE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80025DE4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80025DE8:
    // 0x80025DE8: bnel        $v1, $at, L_80025E0C
    if (ctx->r3 != ctx->r1) {
        // 0x80025DEC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80025E0C;
    }
    goto skip_2;
    // 0x80025DEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80025DF0: lbu         $v0, 0x158($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X158);
    // 0x80025DF4: beq         $v0, $zero, L_80025E04
    if (ctx->r2 == 0) {
        // 0x80025DF8: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_80025E04;
    }
    // 0x80025DF8: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80025DFC: b           L_80025E0C
    // 0x80025E00: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80025E0C;
    // 0x80025E00: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80025E04:
    // 0x80025E04: sb          $t7, 0x158($a3)
    MEM_B(0X158, ctx->r7) = ctx->r15;
    // 0x80025E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80025E0C:
    // 0x80025E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025E10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025E14: jr          $ra
    // 0x80025E18: nop

    return;
    // 0x80025E18: nop

;}
RECOMP_FUNC void func_8078D820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078D820: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078D824: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078D828: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8078D82C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8078D830: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8078D834: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8078D838: jal         0x80045A34
    // 0x8078D83C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8078D83C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_0:
    // 0x8078D840: bne         $v0, $zero, L_8078D858
    if (ctx->r2 != 0) {
        // 0x8078D844: sw          $v0, 0x1F4($s1)
        MEM_W(0X1F4, ctx->r17) = ctx->r2;
            goto L_8078D858;
    }
    // 0x8078D844: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x8078D848: jal         0x800445A4
    // 0x8078D84C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8078D84C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8078D850: b           L_8078DA24
    // 0x8078D854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8078DA24;
    // 0x8078D854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078D858:
    // 0x8078D858: lw          $t8, 0x16C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X16C);
    // 0x8078D85C: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(802, 0XD4) << 16);
    // 0x8078D860: addiu       $t6, $t6, -0x2E1C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(802, 0XD4));
    // 0x8078D864: lui         $t7, 0x8079
    ctx->r15 = S32(RELOC_HI16(802, 0XBB0) << 16);
    // 0x8078D868: sw          $t6, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r14;
    // 0x8078D86C: addiu       $t7, $t7, -0x2340
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(802, 0XBB0));
    // 0x8078D870: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8078D874: lw          $s0, 0x1F4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X1F4);
    // 0x8078D878: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8078D87C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8078D880: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x8078D884: sw          $t9, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->r25;
    // 0x8078D888: sw          $t0, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->r8;
    // 0x8078D88C: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x8078D890: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8078D894: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x8078D898: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x8078D89C: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x8078D8A0: lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XC);
    // 0x8078D8A4: addiu       $at, $zero, 0x467F
    ctx->r1 = ADD32(0, 0X467F);
    // 0x8078D8A8: addiu       $a0, $zero, 0x4680
    ctx->r4 = ADD32(0, 0X4680);
    // 0x8078D8AC: beq         $v0, $at, L_8078D99C
    if (ctx->r2 == ctx->r1) {
        // 0x8078D8B0: addiu       $at, $zero, 0x4685
        ctx->r1 = ADD32(0, 0X4685);
            goto L_8078D99C;
    }
    // 0x8078D8B0: addiu       $at, $zero, 0x4685
    ctx->r1 = ADD32(0, 0X4685);
    // 0x8078D8B4: bne         $v0, $at, L_8078DA20
    if (ctx->r2 != ctx->r1) {
        // 0x8078D8B8: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8078DA20;
    }
    // 0x8078D8B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8078D8BC: sb          $t1, 0x165($s1)
    MEM_B(0X165, ctx->r17) = ctx->r9;
    // 0x8078D8C0: jal         0x80047090
    // 0x8078D8C4: addiu       $a0, $zero, 0x467F
    ctx->r4 = ADD32(0, 0X467F);
    func_80047090(rdram, ctx);
        goto after_2;
    // 0x8078D8C4: addiu       $a0, $zero, 0x467F
    ctx->r4 = ADD32(0, 0X467F);
    after_2:
    // 0x8078D8C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8078D8CC: lui         $at, 0x467F
    ctx->r1 = S32(0X467F << 16);
    // 0x8078D8D0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x8078D8D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8078D8D8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8078D8DC: jal         0x8004613C
    // 0x8078D8E0: lui         $a1, 0xC248
    ctx->r5 = S32(0XC248 << 16);
    func_8004613C(rdram, ctx);
        goto after_3;
    // 0x8078D8E0: lui         $a1, 0xC248
    ctx->r5 = S32(0XC248 << 16);
    after_3:
    // 0x8078D8E4: bne         $v0, $zero, L_8078D8FC
    if (ctx->r2 != 0) {
        // 0x8078D8E8: sw          $v0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r2;
            goto L_8078D8FC;
    }
    // 0x8078D8E8: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x8078D8EC: jal         0x800445A4
    // 0x8078D8F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8078D8F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8078D8F4: b           L_8078DA24
    // 0x8078D8F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8078DA24;
    // 0x8078D8F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078D8FC:
    // 0x8078D8FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078D900: jal         0x80047F9C
    // 0x8078D904: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x8078D904: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_5:
    // 0x8078D908: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x8078D90C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8078D910: addiu       $a0, $zero, 0x467F
    ctx->r4 = ADD32(0, 0X467F);
    // 0x8078D914: sb          $t2, 0x17C($t3)
    MEM_B(0X17C, ctx->r11) = ctx->r10;
    // 0x8078D918: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x8078D91C: jal         0x80047090
    // 0x8078D920: sw          $zero, 0x138($t4)
    MEM_W(0X138, ctx->r12) = 0;
    func_80047090(rdram, ctx);
        goto after_6;
    // 0x8078D920: sw          $zero, 0x138($t4)
    MEM_W(0X138, ctx->r12) = 0;
    after_6:
    // 0x8078D924: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8078D928: lui         $at, 0x467F
    ctx->r1 = S32(0X467F << 16);
    // 0x8078D92C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x8078D930: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8078D934: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8078D938: jal         0x8004613C
    // 0x8078D93C: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    func_8004613C(rdram, ctx);
        goto after_7;
    // 0x8078D93C: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    after_7:
    // 0x8078D940: bne         $v0, $zero, L_8078D958
    if (ctx->r2 != 0) {
        // 0x8078D944: sw          $v0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r2;
            goto L_8078D958;
    }
    // 0x8078D944: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8078D948: jal         0x800445A4
    // 0x8078D94C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x8078D94C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8078D950: b           L_8078DA24
    // 0x8078D954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8078DA24;
    // 0x8078D954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078D958:
    // 0x8078D958: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078D95C: jal         0x80047F9C
    // 0x8078D960: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    func_80047F9C(rdram, ctx);
        goto after_9;
    // 0x8078D960: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_9:
    // 0x8078D964: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8078D968: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8078D96C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8078D970: sb          $t5, 0x17C($t6)
    MEM_B(0X17C, ctx->r14) = ctx->r13;
    // 0x8078D974: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8078D978: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078D97C: jal         0x8078D2BC
    // 0x8078D980: sw          $t7, 0x138($t8)
    MEM_W(0X138, ctx->r24) = ctx->r15;
    func_8078D2BC(rdram, ctx);
        goto after_10;
    // 0x8078D980: sw          $t7, 0x138($t8)
    MEM_W(0X138, ctx->r24) = ctx->r15;
    after_10:
    // 0x8078D984: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078D988: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078D98C: jal         0x8078DA34
    // 0x8078D990: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8078DA34(rdram, ctx);
        goto after_11;
    // 0x8078D990: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8078D994: b           L_8078DA24
    // 0x8078D998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8078DA24;
    // 0x8078D998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078D99C:
    // 0x8078D99C: jal         0x80047090
    // 0x8078D9A0: sb          $zero, 0x165($s1)
    MEM_B(0X165, ctx->r17) = 0;
    func_80047090(rdram, ctx);
        goto after_12;
    // 0x8078D9A0: sb          $zero, 0x165($s1)
    MEM_B(0X165, ctx->r17) = 0;
    after_12:
    // 0x8078D9A4: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x8078D9A8: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x8078D9AC: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8078D9B0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x8078D9B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8078D9B8: jal         0x8004613C
    // 0x8078D9BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8004613C(rdram, ctx);
        goto after_13;
    // 0x8078D9BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_13:
    // 0x8078D9C0: bne         $v0, $zero, L_8078D9D8
    if (ctx->r2 != 0) {
        // 0x8078D9C4: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8078D9D8;
    }
    // 0x8078D9C4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8078D9C8: jal         0x800445A4
    // 0x8078D9CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_14;
    // 0x8078D9CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x8078D9D0: b           L_8078DA24
    // 0x8078D9D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8078DA24;
    // 0x8078D9D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078D9D8:
    // 0x8078D9D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078D9DC: jal         0x80047F9C
    // 0x8078D9E0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_15;
    // 0x8078D9E0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_15:
    // 0x8078D9E4: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(802, 0XBE0) << 16);
    // 0x8078D9E8: lwc1        $f0, -0x2310($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(802, 0XBE0));
    // 0x8078D9EC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8078D9F0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8078D9F4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8078D9F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8078D9FC: addiu       $v0, $s1, 0xC4
    ctx->r2 = ADD32(ctx->r17, 0XC4);
    // 0x8078DA00: sb          $t9, 0x17C($t0)
    MEM_B(0X17C, ctx->r8) = ctx->r25;
    // 0x8078DA04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078DA08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078DA0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8078DA10: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x8078DA14: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x8078DA18: jal         0x8078DA34
    // 0x8078DA1C: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    func_8078DA34(rdram, ctx);
        goto after_16;
    // 0x8078DA1C: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    after_16:
L_8078DA20:
    // 0x8078DA20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078DA24:
    // 0x8078DA24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8078DA28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8078DA2C: jr          $ra
    // 0x8078DA30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8078DA30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806F2AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2AA0: jr          $ra
    // 0x806F2AA4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806F2AA4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8001E2D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E2D4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001E2D8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001E2DC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001E2E0: beq         $a1, $zero, L_8001E31C
    if (ctx->r5 == 0) {
        // 0x8001E2E4: andi        $a2, $a2, 0xFFFF
        ctx->r6 = ctx->r6 & 0XFFFF;
            goto L_8001E31C;
    }
    // 0x8001E2E4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8001E2E8: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
L_8001E2EC:
    // 0x8001E2EC: multu       $a2, $v1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001E2F0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001E2F4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001E2F8: andi        $a2, $a2, 0x7
    ctx->r6 = ctx->r6 & 0X7;
    // 0x8001E2FC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001E300: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8001E304: mflo        $t6
    ctx->r14 = lo;
    // 0x8001E308: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8001E30C: lhu         $t7, 0x1200($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1200);
    // 0x8001E310: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001E314: bne         $a1, $zero, L_8001E2EC
    if (ctx->r5 != 0) {
        // 0x8001E318: sh          $t8, 0x1200($v0)
        MEM_H(0X1200, ctx->r2) = ctx->r24;
            goto L_8001E2EC;
    }
    // 0x8001E318: sh          $t8, 0x1200($v0)
    MEM_H(0X1200, ctx->r2) = ctx->r24;
L_8001E31C:
    // 0x8001E31C: jr          $ra
    // 0x8001E320: nop

    return;
    // 0x8001E320: nop

;}
RECOMP_FUNC void func_8004DAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DAA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004DAA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004DAA8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004DAAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004DAB0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8004DAB4: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8004DAB8: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8004DABC: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8004DAC0: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004DAC4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004DAC8: addu        $v1, $t8, $t0
    ctx->r3 = ADD32(ctx->r24, ctx->r8);
    // 0x8004DACC: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8004DAD0: beql        $v0, $zero, L_8004DB64
    if (ctx->r2 == 0) {
        // 0x8004DAD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004DB64;
    }
    goto skip_0;
    // 0x8004DAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004DAD8: beql        $v0, $at, L_8004DB64
    if (ctx->r2 == ctx->r1) {
        // 0x8004DADC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004DB64;
    }
    goto skip_1;
    // 0x8004DADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004DAE0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8004DAE4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004DAE8: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8004DAEC: beq         $v0, $at, L_8004DB60
    if (ctx->r2 == ctx->r1) {
        // 0x8004DAF0: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004DB60;
    }
    // 0x8004DAF0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004DAF4: beq         $v0, $at, L_8004DB60
    if (ctx->r2 == ctx->r1) {
        // 0x8004DAF8: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8004DB60;
    }
    // 0x8004DAF8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004DAFC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8004DB00: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8004DB04: jal         0x8004CE68
    // 0x8004DB08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004CE68(rdram, ctx);
        goto after_0;
    // 0x8004DB08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004DB0C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8004DB10: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8004DB14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8004DB18: lbu         $t1, 0x14($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X14);
    // 0x8004DB1C: beql        $t1, $zero, L_8004DB64
    if (ctx->r9 == 0) {
        // 0x8004DB20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004DB64;
    }
    goto skip_2;
    // 0x8004DB20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8004DB24: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8004DB28: lhu         $t3, 0x4C($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4C);
    // 0x8004DB2C: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x8004DB30: beql        $t4, $zero, L_8004DB4C
    if (ctx->r12 == 0) {
        // 0x8004DB34: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_8004DB4C;
    }
    goto skip_3;
    // 0x8004DB34: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_3:
    // 0x8004DB38: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8004DB3C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8004DB40: b           L_8004DB54
    // 0x8004DB44: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
        goto L_8004DB54;
    // 0x8004DB44: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
    // 0x8004DB48: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_8004DB4C:
    // 0x8004DB4C: nop

    // 0x8004DB50: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
L_8004DB54:
    // 0x8004DB54: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x8004DB58: ori         $t6, $t5, 0xF000
    ctx->r14 = ctx->r13 | 0XF000;
    // 0x8004DB5C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
L_8004DB60:
    // 0x8004DB60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004DB64:
    // 0x8004DB64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004DB68: jr          $ra
    // 0x8004DB6C: nop

    return;
    // 0x8004DB6C: nop

;}
RECOMP_FUNC void func_8007E030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E030: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8007E034: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8007E038: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8007E03C: lw          $t6, -0x260C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X260C);
    // 0x8007E040: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007E044: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x8007E048: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8007E04C: lw          $s0, 0xC($t6)
    ctx->r16 = MEM_W(ctx->r14, 0XC);
    // 0x8007E050: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8007E054: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x8007E058: addiu       $s0, $s0, -0x40
    ctx->r16 = ADD32(ctx->r16, -0X40);
    // 0x8007E05C: sw          $s0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r16;
    // 0x8007E060: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x8007E064: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x8007E068: sh          $t5, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r13;
    // 0x8007E06C: sh          $t3, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r11;
    // 0x8007E070: sh          $a1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r5;
    // 0x8007E074: sh          $a2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r6;
    // 0x8007E078: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8007E07C: addu        $v1, $a1, $a3
    ctx->r3 = ADD32(ctx->r5, ctx->r7);
    // 0x8007E080: addu        $t7, $t2, $a3
    ctx->r15 = ADD32(ctx->r10, ctx->r7);
    // 0x8007E084: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x8007E088: sh          $v1, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r3;
    // 0x8007E08C: sh          $a2, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r6;
    // 0x8007E090: sh          $zero, 0x14($s0)
    MEM_H(0X14, ctx->r16) = 0;
    // 0x8007E094: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x8007E098: sh          $t5, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r13;
    // 0x8007E09C: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
    // 0x8007E0A0: addu        $t1, $a2, $t0
    ctx->r9 = ADD32(ctx->r6, ctx->r8);
    // 0x8007E0A4: sh          $t1, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r9;
    // 0x8007E0A8: sh          $v1, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r3;
    // 0x8007E0AC: sh          $zero, 0x24($s0)
    MEM_H(0X24, ctx->r16) = 0;
    // 0x8007E0B0: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8007E0B4: addu        $t6, $t4, $t0
    ctx->r14 = ADD32(ctx->r12, ctx->r8);
    // 0x8007E0B8: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x8007E0BC: sh          $t9, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r25;
    // 0x8007E0C0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8007E0C4: sh          $t7, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r15;
    // 0x8007E0C8: sh          $a1, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r5;
    // 0x8007E0CC: sh          $t1, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r9;
    // 0x8007E0D0: sh          $zero, 0x34($s0)
    MEM_H(0X34, ctx->r16) = 0;
    // 0x8007E0D4: sh          $t3, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r11;
    // 0x8007E0D8: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x8007E0DC: sh          $t8, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r24;
    // 0x8007E0E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8007E0E4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8007E0E8: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8007E0EC: ori         $t9, $t9, 0x103F
    ctx->r25 = ctx->r25 | 0X103F;
    // 0x8007E0F0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8007E0F4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8007E0F8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007E0FC: sw          $s0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r16;
    // 0x8007E100: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007E104: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8007E108: lui         $t8, 0xB100
    ctx->r24 = S32(0XB100 << 16);
    // 0x8007E10C: ori         $t8, $t8, 0x204
    ctx->r24 = ctx->r24 | 0X204;
    // 0x8007E110: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007E114: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8007E118: addiu       $t6, $zero, 0x406
    ctx->r14 = ADD32(0, 0X406);
    // 0x8007E11C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007E120: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8007E124: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8007E128: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8007E12C: jr          $ra
    // 0x8007E130: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8007E130: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80716A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716A88: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716A8C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716A90: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716A94: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716A98: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716A9C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716AA0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716AA4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716AA8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716AAC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716AB0: jr          $ra
    // 0x80716AB4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716AB4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80071900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071900: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80071904: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80071908: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x8007190C: addiu       $s0, $s0, -0x7B7C
    ctx->r16 = ADD32(ctx->r16, -0X7B7C);
    // 0x80071910: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80071914: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80071918: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007191C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80071920: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x80071924: addiu       $s2, $s2, -0x5E08
    ctx->r18 = ADD32(ctx->r18, -0X5E08);
    // 0x80071928: blez        $v0, L_8007195C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007192C: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_8007195C;
    }
    // 0x8007192C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80071930:
    // 0x80071930: bne         $s1, $v0, L_80071944
    if (ctx->r17 != ctx->r2) {
        // 0x80071934: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80071944;
    }
    // 0x80071934: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80071938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007193C: jal         0x80082210
    // 0x80071940: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80071940: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
L_80071944:
    // 0x80071944: jal         0x80071760
    // 0x80071948: nop

    func_80071760(rdram, ctx);
        goto after_1;
    // 0x80071948: nop

    after_1:
    // 0x8007194C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80071950: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x80071954: bgtz        $v0, L_80071930
    if (SIGNED(ctx->r2) > 0) {
        // 0x80071958: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80071930;
    }
    // 0x80071958: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_8007195C:
    // 0x8007195C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80071960: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071964: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80071968: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007196C: jr          $ra
    // 0x80071970: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80071970: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_804B8CB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B8CB4: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x804B8CB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804B8CBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B8CC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804B8CC4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x804B8CC8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x804B8CCC: jal         0x8004921C
    // 0x804B8CD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804B8CD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x804B8CD4: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x804B8CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B8CDC: jal         0x8004921C
    // 0x804B8CE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804B8CE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804B8CE4: lh          $s1, 0x2A($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X2A);
    // 0x804B8CE8: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x804B8CEC: lh          $t9, 0x144($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X144);
    // 0x804B8CF0: andi        $t7, $s1, 0xFF
    ctx->r15 = ctx->r17 & 0XFF;
    // 0x804B8CF4: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B8CF8: addiu       $t6, $t9, 0x10
    ctx->r14 = ADD32(ctx->r25, 0X10);
    // 0x804B8CFC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804B8D00: lw          $t6, 0x168($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X168);
    // 0x804B8D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B8D08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804B8D0C: mflo        $t8
    ctx->r24 = lo;
    // 0x804B8D10: nop

    // 0x804B8D14: nop

    // 0x804B8D18: multu       $t8, $t7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B8D1C: lw          $t8, 0x80($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X80);
    // 0x804B8D20: mflo        $t9
    ctx->r25 = lo;
    // 0x804B8D24: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x804B8D28: jal         0x8004921C
    // 0x804B8D2C: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_2;
    // 0x804B8D2C: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    after_2:
    // 0x804B8D30: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x804B8D34: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804B8D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B8D3C: jal         0x8004921C
    // 0x804B8D40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_3;
    // 0x804B8D40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x804B8D44: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x804B8D48: andi        $t9, $s1, 0xFF
    ctx->r25 = ctx->r17 & 0XFF;
    // 0x804B8D4C: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B8D50: lbu         $t7, 0x145($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X145);
    // 0x804B8D54: lw          $t9, 0x168($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X168);
    // 0x804B8D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B8D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804B8D60: mflo        $t8
    ctx->r24 = lo;
    // 0x804B8D64: nop

    // 0x804B8D68: nop

    // 0x804B8D6C: multu       $t8, $t7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B8D70: lw          $t8, 0x80($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X80);
    // 0x804B8D74: mflo        $t6
    ctx->r14 = lo;
    // 0x804B8D78: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x804B8D7C: jal         0x8004921C
    // 0x804B8D80: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_4;
    // 0x804B8D80: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    after_4:
    // 0x804B8D84: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x804B8D88: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804B8D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B8D90: jal         0x8004921C
    // 0x804B8D94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_5;
    // 0x804B8D94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x804B8D98: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x804B8D9C: andi        $t6, $s1, 0xFF
    ctx->r14 = ctx->r17 & 0XFF;
    // 0x804B8DA0: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B8DA4: lh          $t7, 0x144($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X144);
    // 0x804B8DA8: lui         $s2, 0x400
    ctx->r18 = S32(0X400 << 16);
    // 0x804B8DAC: ori         $s2, $s2, 0x81FF
    ctx->r18 = ctx->r18 | 0X81FF;
    // 0x804B8DB0: addiu       $t9, $t7, 0x20
    ctx->r25 = ADD32(ctx->r15, 0X20);
    // 0x804B8DB4: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x804B8DB8: lw          $t9, 0x168($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X168);
    // 0x804B8DBC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x804B8DC0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x804B8DC4: addiu       $ra, $zero, 0x3
    ctx->r31 = ADD32(0, 0X3);
    // 0x804B8DC8: mflo        $t8
    ctx->r24 = lo;
    // 0x804B8DCC: lui         $t3, 0xB100
    ctx->r11 = S32(0XB100 << 16);
    // 0x804B8DD0: nop

    // 0x804B8DD4: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B8DD8: lw          $t8, 0x80($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X80);
    // 0x804B8DDC: mflo        $t7
    ctx->r15 = lo;
    // 0x804B8DE0: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x804B8DE4: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x804B8DE8: lw          $a3, 0x1F4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X1F4);
    // 0x804B8DEC: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x804B8DF0: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x804B8DF4: lw          $t0, 0x320($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X320);
    // 0x804B8DF8: addiu       $t5, $a3, 0x328
    ctx->r13 = ADD32(ctx->r7, 0X328);
    // 0x804B8DFC: lui         $s0, 0x400
    ctx->r16 = S32(0X400 << 16);
    // 0x804B8E00: xori        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 ^ 0X1;
    // 0x804B8E04: andi        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 & 0X1;
    // 0x804B8E08: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x804B8E0C: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x804B8E10: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x804B8E14: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x804B8E18: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x804B8E1C: addu        $v0, $a3, $t9
    ctx->r2 = ADD32(ctx->r7, ctx->r25);
    // 0x804B8E20: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x804B8E24: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x804B8E28: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x804B8E2C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B8E30: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804B8E34: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x804B8E38: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8E3C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x804B8E40: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x804B8E44: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8E48: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x804B8E4C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x804B8E50: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x804B8E54: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x804B8E58: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8E5C: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x804B8E60: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x804B8E64: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x804B8E68: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x804B8E6C: lui         $t6, 0x711
    ctx->r14 = S32(0X711 << 16);
    // 0x804B8E70: ori         $t6, $t6, 0xF2AB
    ctx->r14 = ctx->r14 | 0XF2AB;
    // 0x804B8E74: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x804B8E78: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x804B8E7C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x804B8E80: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8E84: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x804B8E88: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804B8E8C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x804B8E90: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    // 0x804B8E94: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8E98: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B8E9C: sw          $a3, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r7;
    // 0x804B8EA0: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x804B8EA4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8EA8: lui         $t0, 0xF548
    ctx->r8 = S32(0XF548 << 16);
    // 0x804B8EAC: ori         $t0, $t0, 0x600
    ctx->r8 = ctx->r8 | 0X600;
    // 0x804B8EB0: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x804B8EB4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8EB8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x804B8EBC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804B8EC0: lui         $t8, 0x5
    ctx->r24 = S32(0X5 << 16);
    // 0x804B8EC4: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x804B8EC8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x804B8ECC: ori         $t8, $t8, 0xC05C
    ctx->r24 = ctx->r24 | 0XC05C;
    // 0x804B8ED0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x804B8ED4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x804B8ED8: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x804B8EDC: lui         $t6, 0xB100
    ctx->r14 = S32(0XB100 << 16);
    // 0x804B8EE0: ori         $t6, $t6, 0x204
    ctx->r14 = ctx->r14 | 0X204;
    // 0x804B8EE4: ori         $t9, $t9, 0x604
    ctx->r25 = ctx->r25 | 0X604;
    // 0x804B8EE8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8EEC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x804B8EF0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804B8EF4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x804B8EF8: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x804B8EFC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x804B8F00: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x804B8F04: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8F08: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x804B8F0C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x804B8F10: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8F14: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x804B8F18: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x804B8F1C: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x804B8F20: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x804B8F24: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B8F28: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8F2C: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x804B8F30: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804B8F34: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x804B8F38: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8F3C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804B8F40: lui         $t6, 0x711
    ctx->r14 = S32(0X711 << 16);
    // 0x804B8F44: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x804B8F48: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x804B8F4C: ori         $t6, $t6, 0xF2AB
    ctx->r14 = ctx->r14 | 0XF2AB;
    // 0x804B8F50: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x804B8F54: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8F58: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x804B8F5C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x804B8F60: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804B8F64: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804B8F68: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x804B8F6C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8F70: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x804B8F74: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x804B8F78: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x804B8F7C: lui         $t8, 0x5
    ctx->r24 = S32(0X5 << 16);
    // 0x804B8F80: ori         $t8, $t8, 0xC05C
    ctx->r24 = ctx->r24 | 0XC05C;
    // 0x804B8F84: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x804B8F88: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x804B8F8C: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x804B8F90: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8F94: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x804B8F98: ori         $s0, $s0, 0x185F
    ctx->r16 = ctx->r16 | 0X185F;
L_804B8F9C:
    // 0x804B8F9C: bne         $t4, $zero, L_804B8FAC
    if (ctx->r12 != 0) {
        // 0x804B8FA0: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_804B8FAC;
    }
    // 0x804B8FA0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x804B8FA4: b           L_804B8FAC
    // 0x804B8FA8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_804B8FAC;
    // 0x804B8FA8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_804B8FAC:
    // 0x804B8FAC: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x804B8FB0: beq         $at, $zero, L_804B9034
    if (ctx->r1 == 0) {
        // 0x804B8FB4: sll         $a0, $t0, 2
        ctx->r4 = S32(ctx->r8 << 2);
            goto L_804B9034;
    }
    // 0x804B8FB4: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
    // 0x804B8FB8: sll         $t6, $t4, 5
    ctx->r14 = S32(ctx->r12 << 5);
    // 0x804B8FBC: addu        $a1, $t6, $a0
    ctx->r5 = ADD32(ctx->r14, ctx->r4);
L_804B8FC0:
    // 0x804B8FC0: slti        $at, $a1, 0x34
    ctx->r1 = SIGNED(ctx->r5) < 0X34 ? 1 : 0;
    // 0x804B8FC4: beq         $at, $zero, L_804B9034
    if (ctx->r1 == 0) {
        // 0x804B8FC8: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_804B9034;
    }
    // 0x804B8FC8: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x804B8FCC: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x804B8FD0: addiu       $a2, $v1, 0x2
    ctx->r6 = ADD32(ctx->r3, 0X2);
    // 0x804B8FD4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x804B8FD8: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x804B8FDC: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x804B8FE0: sll         $t8, $a2, 8
    ctx->r24 = S32(ctx->r6 << 8);
    // 0x804B8FE4: addiu       $a3, $v1, 0x4
    ctx->r7 = ADD32(ctx->r3, 0X4);
    // 0x804B8FE8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x804B8FEC: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x804B8FF0: or          $t9, $t6, $a3
    ctx->r25 = ctx->r14 | ctx->r7;
    // 0x804B8FF4: or          $t7, $t9, $t3
    ctx->r15 = ctx->r25 | ctx->r11;
    // 0x804B8FF8: addiu       $t6, $v1, 0x6
    ctx->r14 = ADD32(ctx->r3, 0X6);
    // 0x804B8FFC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B9000: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804B9004: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x804B9008: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x804B900C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x804B9010: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x804B9014: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x804B9018: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x804B901C: or          $t9, $t6, $a3
    ctx->r25 = ctx->r14 | ctx->r7;
    // 0x804B9020: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804B9024: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x804B9028: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x804B902C: bne         $at, $zero, L_804B8FC0
    if (ctx->r1 != 0) {
        // 0x804B9030: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_804B8FC0;
    }
    // 0x804B9030: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_804B9034:
    // 0x804B9034: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x804B9038: beq         $at, $zero, L_804B908C
    if (ctx->r1 == 0) {
        // 0x804B903C: sll         $t6, $t4, 9
        ctx->r14 = S32(ctx->r12 << 9);
            goto L_804B908C;
    }
    // 0x804B903C: sll         $t6, $t4, 9
    ctx->r14 = S32(ctx->r12 << 9);
    // 0x804B9040: sll         $v1, $t2, 1
    ctx->r3 = S32(ctx->r10 << 1);
    // 0x804B9044: addiu       $a2, $v1, 0x2
    ctx->r6 = ADD32(ctx->r3, 0X2);
    // 0x804B9048: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x804B904C: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x804B9050: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x804B9054: sll         $t6, $a2, 8
    ctx->r14 = S32(ctx->r6 << 8);
    // 0x804B9058: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x804B905C: addiu       $a3, $v1, 0x4
    ctx->r7 = ADD32(ctx->r3, 0X4);
    // 0x804B9060: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x804B9064: addiu       $t7, $v1, 0x6
    ctx->r15 = ADD32(ctx->r3, 0X6);
    // 0x804B9068: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x804B906C: or          $t0, $t9, $a3
    ctx->r8 = ctx->r25 | ctx->r7;
    // 0x804B9070: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x804B9074: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x804B9078: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x804B907C: lui         $at, 0xB100
    ctx->r1 = S32(0XB100 << 16);
    // 0x804B9080: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
    // 0x804B9084: b           L_804B9110
    // 0x804B9088: or          $t3, $t7, $a3
    ctx->r11 = ctx->r15 | ctx->r7;
        goto L_804B9110;
    // 0x804B9088: or          $t3, $t7, $a3
    ctx->r11 = ctx->r15 | ctx->r7;
L_804B908C:
    // 0x804B908C: addu        $v1, $t6, $t5
    ctx->r3 = ADD32(ctx->r14, ctx->r13);
    // 0x804B9090: bne         $t4, $ra, L_804B90AC
    if (ctx->r12 != ctx->r31) {
        // 0x804B9094: addiu       $v1, $v1, 0x200
        ctx->r3 = ADD32(ctx->r3, 0X200);
            goto L_804B90AC;
    }
    // 0x804B9094: addiu       $v1, $v1, 0x200
    ctx->r3 = ADD32(ctx->r3, 0X200);
    // 0x804B9098: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B909C: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x804B90A0: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x804B90A4: b           L_804B90BC
    // 0x804B90A8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_804B90BC;
    // 0x804B90A8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_804B90AC:
    // 0x804B90AC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B90B0: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x804B90B4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x804B90B8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_804B90BC:
    // 0x804B90BC: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x804B90C0: bne         $t4, $s1, L_804B8F9C
    if (ctx->r12 != ctx->r17) {
        // 0x804B90C4: nop
    
            goto L_804B8F9C;
    }
    // 0x804B90C4: nop

    // 0x804B90C8: sll         $v1, $t2, 1
    ctx->r3 = S32(ctx->r10 << 1);
    // 0x804B90CC: addiu       $a2, $v1, 0x2
    ctx->r6 = ADD32(ctx->r3, 0X2);
    // 0x804B90D0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x804B90D4: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x804B90D8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x804B90DC: sll         $t7, $a2, 8
    ctx->r15 = S32(ctx->r6 << 8);
    // 0x804B90E0: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x804B90E4: addiu       $a3, $v1, 0x4
    ctx->r7 = ADD32(ctx->r3, 0X4);
    // 0x804B90E8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x804B90EC: addiu       $t9, $v1, 0x6
    ctx->r25 = ADD32(ctx->r3, 0X6);
    // 0x804B90F0: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x804B90F4: or          $t0, $t6, $a3
    ctx->r8 = ctx->r14 | ctx->r7;
    // 0x804B90F8: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x804B90FC: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x804B9100: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x804B9104: lui         $at, 0xB100
    ctx->r1 = S32(0XB100 << 16);
    // 0x804B9108: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
    // 0x804B910C: or          $t3, $t9, $a3
    ctx->r11 = ctx->r25 | ctx->r7;
L_804B9110:
    // 0x804B9110: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B9114: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x804B9118: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804B911C: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x804B9120: addiu       $v1, $t1, 0x8
    ctx->r3 = ADD32(ctx->r9, 0X8);
    // 0x804B9124: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x804B9128: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x804B912C: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x804B9130: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x804B9134: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x804B9138: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x804B913C: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x804B9140: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x804B9144: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x804B9148: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x804B914C: lui         $t6, 0x711
    ctx->r14 = S32(0X711 << 16);
    // 0x804B9150: ori         $t6, $t6, 0xF2AB
    ctx->r14 = ctx->r14 | 0XF2AB;
    // 0x804B9154: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x804B9158: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x804B915C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x804B9160: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x804B9164: addiu       $t1, $a2, 0x8
    ctx->r9 = ADD32(ctx->r6, 0X8);
    // 0x804B9168: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804B916C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x804B9170: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x804B9174: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x804B9178: ori         $t7, $t7, 0x600
    ctx->r15 = ctx->r15 | 0X600;
    // 0x804B917C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x804B9180: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x804B9184: addiu       $v1, $t1, 0x8
    ctx->r3 = ADD32(ctx->r9, 0X8);
    // 0x804B9188: lui         $t6, 0x5
    ctx->r14 = S32(0X5 << 16);
    // 0x804B918C: ori         $t6, $t6, 0xC05C
    ctx->r14 = ctx->r14 | 0XC05C;
    // 0x804B9190: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x804B9194: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x804B9198: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x804B919C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x804B91A0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x804B91A4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x804B91A8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x804B91AC: lui         $t9, 0xB800
    ctx->r25 = S32(0XB800 << 16);
    // 0x804B91B0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x804B91B4: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x804B91B8: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x804B91BC: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x804B91C0: sw          $t7, 0x320($t8)
    MEM_W(0X320, ctx->r24) = ctx->r15;
    // 0x804B91C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804B91C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x804B91CC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x804B91D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B91D4: jr          $ra
    // 0x804B91D8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x804B91D8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_806D7228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D7228: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806D722C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D7230: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D7234: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D7238: lui         $t8, 0x806E
    ctx->r24 = S32(RELOC_HI16(622, 0X18F8) << 16);
    // 0x806D723C: lui         $t0, 0x806D
    ctx->r8 = S32(RELOC_HI16(622, 0XEB0) << 16);
    // 0x806D7240: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x806D7244: addiu       $t0, $t0, 0x7A60
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(622, 0XEB0));
    // 0x806D7248: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D724C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806D7250: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806D7254: lw          $t8, -0x7B58($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(622, 0X18F8));
    // 0x806D7258: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x806D725C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806D7260: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x806D7264: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x806D7268: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x806D726C: jal         0x806D6BC0
    // 0x806D7270: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    func_806D6BC0(rdram, ctx);
        goto after_0;
    // 0x806D7270: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_0:
    // 0x806D7274: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806D7278: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x806D727C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x806D7280: beq         $v1, $zero, L_806D7290
    if (ctx->r3 == 0) {
        // 0x806D7284: addiu       $t2, $v1, -0x1
        ctx->r10 = ADD32(ctx->r3, -0X1);
            goto L_806D7290;
    }
    // 0x806D7284: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x806D7288: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x806D728C: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_806D7290:
    // 0x806D7290: bnel        $v1, $zero, L_806D7358
    if (ctx->r3 != 0) {
        // 0x806D7294: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_806D7358;
    }
    goto skip_0;
    // 0x806D7294: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x806D7298: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x806D729C: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(622, 0X1910) << 16);
    // 0x806D72A0: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    // 0x806D72A4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x806D72A8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x806D72AC: lw          $t6, -0x7B40($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(622, 0X1910));
    // 0x806D72B0: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    // 0x806D72B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D72B8: sh          $t6, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r14;
    // 0x806D72BC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806D72C0: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x806D72C4: xor         $t0, $t8, $t9
    ctx->r8 = ctx->r24 ^ ctx->r25;
    // 0x806D72C8: sw          $t0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r8;
    // 0x806D72CC: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x806D72D0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x806D72D4: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x806D72D8: bne         $at, $zero, L_806D7354
    if (ctx->r1 != 0) {
        // 0x806D72DC: sw          $t2, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r10;
            goto L_806D7354;
    }
    // 0x806D72DC: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x806D72E0: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x806D72E4: jal         0x806D6D60
    // 0x806D72E8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_806D6D60(rdram, ctx);
        goto after_1;
    // 0x806D72E8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x806D72EC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806D72F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D72F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D72F8: lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X14);
    // 0x806D72FC: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(622, 0X1B6C) << 16);
    // 0x806D7300: beq         $t4, $zero, L_806D7318
    if (ctx->r12 == 0) {
        // 0x806D7304: nop
    
            goto L_806D7318;
    }
    // 0x806D7304: nop

    // 0x806D7308: jal         0x806D7A20
    // 0x806D730C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_806D7A20(rdram, ctx);
        goto after_2;
    // 0x806D730C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x806D7310: b           L_806D7358
    // 0x806D7314: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
        goto L_806D7358;
    // 0x806D7314: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_806D7318:
    // 0x806D7318: lwc1        $f4, -0x78E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(622, 0X1B6C));
    // 0x806D731C: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x806D7320: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(622, 0X1AFC) << 16);
    // 0x806D7324: swc1        $f4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f4.u32l;
    // 0x806D7328: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
    // 0x806D732C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806D7330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D7334: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x806D7338: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x806D733C: lwc1        $f6, -0x7954($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(622, 0X1AFC));
    // 0x806D7340: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D7344: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806D7348: swc1        $f6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f6.u32l;
    // 0x806D734C: jal         0x806D7A20
    // 0x806D7350: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    func_806D7A20(rdram, ctx);
        goto after_3;
    // 0x806D7350: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    after_3:
L_806D7354:
    // 0x806D7354: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_806D7358:
    // 0x806D7358: jal         0x80048F84
    // 0x806D735C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x806D735C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x806D7360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D7364: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D7368: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806D736C: jr          $ra
    // 0x806D7370: nop

    return;
    // 0x806D7370: nop

;}
RECOMP_FUNC void func_804CC8EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC8EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804CC8F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CC8F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804CC8F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804CC8FC: jal         0x80045A34
    // 0x804CC900: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804CC900: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_0:
    // 0x804CC904: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x804CC908: bne         $v0, $zero, L_804CC918
    if (ctx->r2 != 0) {
        // 0x804CC90C: sw          $v0, 0x1F4($v1)
        MEM_W(0X1F4, ctx->r3) = ctx->r2;
            goto L_804CC918;
    }
    // 0x804CC90C: sw          $v0, 0x1F4($v1)
    MEM_W(0X1F4, ctx->r3) = ctx->r2;
    // 0x804CC910: b           L_804CC9A0
    // 0x804CC914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CC9A0;
    // 0x804CC914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CC918:
    // 0x804CC918: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x804CC91C: lw          $t6, 0x1F4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1F4);
    // 0x804CC920: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x804CC924: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x804CC928: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x804CC92C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x804CC930: jal         0x80064D1C
    // 0x804CC934: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x804CC934: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_1:
    // 0x804CC938: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x804CC93C: bne         $v0, $zero, L_804CC94C
    if (ctx->r2 != 0) {
        // 0x804CC940: sw          $v0, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->r2;
            goto L_804CC94C;
    }
    // 0x804CC940: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x804CC944: b           L_804CC9A0
    // 0x804CC948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CC9A0;
    // 0x804CC948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CC94C:
    // 0x804CC94C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x804CC950: jal         0x80064D1C
    // 0x804CC954: sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4 << 6);
    func_80064D1C(rdram, ctx);
        goto after_2;
    // 0x804CC954: sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4 << 6);
    after_2:
    // 0x804CC958: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x804CC95C: bne         $v0, $zero, L_804CC96C
    if (ctx->r2 != 0) {
        // 0x804CC960: sw          $v0, 0x4($t8)
        MEM_W(0X4, ctx->r24) = ctx->r2;
            goto L_804CC96C;
    }
    // 0x804CC960: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x804CC964: b           L_804CC9A0
    // 0x804CC968: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CC9A0;
    // 0x804CC968: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CC96C:
    // 0x804CC96C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x804CC970: jal         0x80064D1C
    // 0x804CC974: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    func_80064D1C(rdram, ctx);
        goto after_3;
    // 0x804CC974: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_3:
    // 0x804CC978: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x804CC97C: lui         $t0, 0x804D
    ctx->r8 = S32(RELOC_HI16(237, 0X440) << 16);
    // 0x804CC980: bne         $v0, $zero, L_804CC990
    if (ctx->r2 != 0) {
        // 0x804CC984: sw          $v0, 0x8($t9)
        MEM_W(0X8, ctx->r25) = ctx->r2;
            goto L_804CC990;
    }
    // 0x804CC984: sw          $v0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r2;
    // 0x804CC988: b           L_804CC9A0
    // 0x804CC98C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CC9A0;
    // 0x804CC98C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CC990:
    // 0x804CC990: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x804CC994: addiu       $t0, $t0, -0x3750
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(237, 0X440));
    // 0x804CC998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804CC99C: sw          $t0, 0x1F8($t1)
    MEM_W(0X1F8, ctx->r9) = ctx->r8;
L_804CC9A0:
    // 0x804CC9A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CC9A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804CC9A8: jr          $ra
    // 0x804CC9AC: nop

    return;
    // 0x804CC9AC: nop

;}
RECOMP_FUNC void func_806EE3BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE3BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EE3C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EE3C4: jal         0x80056904
    // 0x806EE3C8: nop

    func_80056904(rdram, ctx);
        goto after_0;
    // 0x806EE3C8: nop

    after_0:
    // 0x806EE3CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EE3D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EE3D4: jr          $ra
    // 0x806EE3D8: nop

    return;
    // 0x806EE3D8: nop

;}
RECOMP_FUNC void func_80671738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80671738: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8067173C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80671740: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80671744: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80671748: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8067174C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80671750: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80671754: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x80671758: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8067175C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80671760: lw          $t8, 0x1F4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1F4);
    // 0x80671764: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80671768: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8067176C: addiu       $s0, $a0, 0xC
    ctx->r16 = ADD32(ctx->r4, 0XC);
    // 0x80671770: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x80671774: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_80671778:
    // 0x80671778: bne         $s3, $zero, L_8067179C
    if (ctx->r19 != 0) {
        // 0x8067177C: or          $a2, $s1, $zero
        ctx->r6 = ctx->r17 | 0;
            goto L_8067179C;
    }
    // 0x8067177C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80671780: lw          $v1, 0xA0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA0);
    // 0x80671784: bne         $v1, $zero, L_80671794
    if (ctx->r3 != 0) {
        // 0x80671788: addiu       $v0, $v1, 0x10
        ctx->r2 = ADD32(ctx->r3, 0X10);
            goto L_80671794;
    }
    // 0x80671788: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8067178C: b           L_806717A4
    // 0x80671790: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806717A4;
    // 0x80671790: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80671794:
    // 0x80671794: b           L_806717A4
    // 0x80671798: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_806717A4;
    // 0x80671798: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8067179C:
    // 0x8067179C: lw          $v0, 0xA0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA0);
    // 0x806717A0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
L_806717A4:
    // 0x806717A4: lw          $a0, 0x24($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X24);
    // 0x806717A8: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x806717AC: jal         0x8005C27C
    // 0x806717B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x806717B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x806717B4: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
    // 0x806717B8: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    // 0x806717BC: bgez        $s2, L_80671778
    if (SIGNED(ctx->r18) >= 0) {
        // 0x806717C0: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80671778;
    }
    // 0x806717C0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x806717C4: lw          $t9, 0x24($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X24);
    // 0x806717C8: lw          $t0, 0x1F4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1F4);
    // 0x806717CC: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x806717D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x806717D4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x806717D8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x806717DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x806717E0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x806717E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806717E8: jr          $ra
    // 0x806717EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x806717EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80076D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076D0C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80076D10: andi        $t6, $a1, 0x7
    ctx->r14 = ctx->r5 & 0X7;
    // 0x80076D14: sllv        $t3, $a3, $a2
    ctx->r11 = S32(ctx->r7 << (ctx->r6 & 31));
    // 0x80076D18: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80076D1C: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x80076D20: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80076D24: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x80076D28: andi        $t9, $a2, 0x3
    ctx->r25 = ctx->r6 & 0X3;
    // 0x80076D2C: sll         $t1, $t9, 19
    ctx->r9 = S32(ctx->r25 << 19);
    // 0x80076D30: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80076D34: addiu       $t6, $t5, 0x7
    ctx->r14 = ADD32(ctx->r13, 0X7);
    // 0x80076D38: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80076D3C: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x80076D40: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x80076D44: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x80076D48: or          $t1, $t2, $t8
    ctx->r9 = ctx->r10 | ctx->r24;
    // 0x80076D4C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80076D50: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80076D54: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x80076D58: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x80076D5C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076D60: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x80076D64: sll         $t5, $t4, 20
    ctx->r13 = S32(ctx->r12 << 20);
    // 0x80076D68: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80076D6C: ori         $t7, $t6, 0x200
    ctx->r15 = ctx->r14 | 0X200;
    // 0x80076D70: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80076D74: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80076D78: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80076D7C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80076D80: lw          $t4, 0x10($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10);
    // 0x80076D84: addiu       $t2, $a3, -0x1
    ctx->r10 = ADD32(ctx->r7, -0X1);
    // 0x80076D88: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x80076D8C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80076D90: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80076D94: andi        $t1, $t8, 0xFFF
    ctx->r9 = ctx->r24 & 0XFFF;
    // 0x80076D98: sll         $t3, $t1, 12
    ctx->r11 = S32(ctx->r9 << 12);
    // 0x80076D9C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80076DA0: or          $t9, $t3, $t7
    ctx->r25 = ctx->r11 | ctx->r15;
    // 0x80076DA4: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80076DA8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076DAC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80076DB0: jr          $ra
    // 0x80076DB4: nop

    return;
    // 0x80076DB4: nop

;}
RECOMP_FUNC void func_80453FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453FF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80453FF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80453FF8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80453FFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80454000: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80454004: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80454008: lw          $v0, 0xA5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA5C);
    // 0x8045400C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80454010: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80454014: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80454018: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8045401C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80454020: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80454024: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80454028: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8045402C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80454030: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80454034: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80454038: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x8045403C: addiu       $t8, $t7, 0xAE0
    ctx->r24 = ADD32(ctx->r15, 0XAE0);
    // 0x80454040: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80454044: jal         0x80446D70
    // 0x80454048: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80446D70(rdram, ctx);
        goto after_0;
    // 0x80454048: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x8045404C: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x80454050: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80454054: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80454058: jal         0x8044EEF8
    // 0x8045405C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8044EEF8(rdram, ctx);
        goto after_1;
    // 0x8045405C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x80454060: jal         0x80453DC4
    // 0x80454064: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80453DC4(rdram, ctx);
        goto after_2;
    // 0x80454064: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80454068: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8045406C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80454070: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80454074: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80454078: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8045407C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80454080: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80454084: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80454088: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8045408C: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x80454090: addu        $a1, $s0, $t0
    ctx->r5 = ADD32(ctx->r16, ctx->r8);
    // 0x80454094: jal         0x8044ED68
    // 0x80454098: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_3;
    // 0x80454098: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_3:
    // 0x8045409C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x804540A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804540A4: jal         0x80450A74
    // 0x804540A8: sw          $t1, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r9;
    func_80450A74(rdram, ctx);
        goto after_4;
    // 0x804540A8: sw          $t1, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r9;
    after_4:
    // 0x804540AC: jal         0x80453F10
    // 0x804540B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80453F10(rdram, ctx);
        goto after_5;
    // 0x804540B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x804540B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804540B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804540BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804540C0: jr          $ra
    // 0x804540C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x804540C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80533170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533170: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80533174: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80533178: lw          $v1, 0x1C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C);
    // 0x8053317C: beq         $v1, $zero, L_80533194
    if (ctx->r3 == 0) {
        // 0x80533180: nop
    
            goto L_80533194;
    }
    // 0x80533180: nop

    // 0x80533184: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80533188: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8053318C: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x80533190: swc1        $f6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f6.u32l;
L_80533194:
    // 0x80533194: jr          $ra
    // 0x80533198: nop

    return;
    // 0x80533198: nop

;}
RECOMP_FUNC void func_8004D150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D150: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004D154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D158: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8004D15C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004D160: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8004D164: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8004D168: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8004D16C: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x8004D170: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x8004D174: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8004D178: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004D17C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8004D180: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8004D184: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004D188: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8004D18C: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8004D190: beql        $v1, $zero, L_8004D1E4
    if (ctx->r3 == 0) {
        // 0x8004D194: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004D1E4;
    }
    goto skip_0;
    // 0x8004D194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004D198: beql        $v1, $at, L_8004D1E4
    if (ctx->r3 == ctx->r1) {
        // 0x8004D19C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004D1E4;
    }
    goto skip_1;
    // 0x8004D19C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004D1A0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8004D1A4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004D1A8: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x8004D1AC: beq         $v1, $at, L_8004D1E0
    if (ctx->r3 == ctx->r1) {
        // 0x8004D1B0: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004D1E0;
    }
    // 0x8004D1B0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004D1B4: beq         $v1, $at, L_8004D1E0
    if (ctx->r3 == ctx->r1) {
        // 0x8004D1B8: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_8004D1E0;
    }
    // 0x8004D1B8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8004D1BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8004D1C0: jal         0x80047AB8
    // 0x8004D1C4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8004D1C4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x8004D1C8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8004D1CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8004D1D0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8004D1D4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8004D1D8: jalr        $t9
    // 0x8004D1DC: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8004D1DC: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_1:
L_8004D1E0:
    // 0x8004D1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004D1E4:
    // 0x8004D1E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004D1E8: jr          $ra
    // 0x8004D1EC: nop

    return;
    // 0x8004D1EC: nop

;}
RECOMP_FUNC void func_805E4A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4A88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805E4A8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805E4A90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805E4A94: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805E4A98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805E4A9C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805E4AA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805E4AA4: jal         0x805E4378
    // 0x805E4AA8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_805E4378(rdram, ctx);
        goto after_0;
    // 0x805E4AA8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x805E4AAC: jal         0x805E4460
    // 0x805E4AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E4460(rdram, ctx);
        goto after_1;
    // 0x805E4AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805E4AB4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x805E4AB8: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805E4ABC: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x805E4AC0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805E4AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E4AC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E4ACC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805E4AD0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805E4AD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x805E4AD8: bc1f        L_805E4AE8
    if (!c1cs) {
        // 0x805E4ADC: nop
    
            goto L_805E4AE8;
    }
    // 0x805E4ADC: nop

    // 0x805E4AE0: jal         0x805E4D78
    // 0x805E4AE4: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    func_805E4D78(rdram, ctx);
        goto after_2;
    // 0x805E4AE4: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    after_2:
L_805E4AE8:
    // 0x805E4AE8: jal         0x805E478C
    // 0x805E4AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E478C(rdram, ctx);
        goto after_3;
    // 0x805E4AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805E4AF0: jal         0x805E4674
    // 0x805E4AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E4674(rdram, ctx);
        goto after_4;
    // 0x805E4AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805E4AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805E4AFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805E4B00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805E4B04: jr          $ra
    // 0x805E4B08: nop

    return;
    // 0x805E4B08: nop

;}
RECOMP_FUNC void func_8003EAE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EAE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003EAE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003EAE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003EAEC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8003EAF0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003EAF4: sb          $t6, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r14;
    // 0x8003EAF8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8003EAFC: lw          $t9, 0x1C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X1C);
    // 0x8003EB00: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8003EB04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003EB08: jalr        $t9
    // 0x8003EB0C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8003EB0C: nop

    after_0:
    // 0x8003EB10: jal         0x8003EA1C
    // 0x8003EB14: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8003EA1C(rdram, ctx);
        goto after_1;
    // 0x8003EB14: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8003EB18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003EB1C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8003EB20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003EB24: jr          $ra
    // 0x8003EB28: nop

    return;
    // 0x8003EB28: nop

;}
RECOMP_FUNC void func_80471DB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471DB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80471DB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80471DBC: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x80471DC0: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x80471DC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80471DC8: jal         0x80065728
    // 0x80471DCC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80471DCC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80471DD0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80471DD4: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80471DD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80471DDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80471DE0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80471DE4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80471DE8: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80471DEC: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80471DF0: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80471DF4: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80471DF8: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80471DFC: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x80471E00: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x80471E04: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x80471E08: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x80471E0C: swc1        $f12, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f12.u32l;
    // 0x80471E10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80471E14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80471E18: jr          $ra
    // 0x80471E1C: nop

    return;
    // 0x80471E1C: nop

;}
RECOMP_FUNC void func_8067087C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067087C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80670880: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80670884: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x80670888: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8067088C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80670890: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80670894: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80670898: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8067089C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x806708A0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806708A4: lui         $t1, 0x8067
    ctx->r9 = S32(RELOC_HI16(520, 0X720) << 16);
    // 0x806708A8: sb          $a3, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r7;
    // 0x806708AC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806708B0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806708B4: lw          $t1, 0x9A0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(520, 0X720));
    // 0x806708B8: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    // 0x806708BC: jal         0x80670748
    // 0x806708C0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_80670748(rdram, ctx);
        goto after_0;
    // 0x806708C0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x806708C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806708C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806708CC: jr          $ra
    // 0x806708D0: nop

    return;
    // 0x806708D0: nop

    // 0x806708D4: nop

    // 0x806708D8: nop

    // 0x806708DC: nop

;}
RECOMP_FUNC void func_80052AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052AA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80052AA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052AAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80052AB0: lw          $a3, 0x174($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X174);
    // 0x80052AB4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80052AB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80052ABC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80052AC0: jal         0x80065728
    // 0x80052AC4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80052AC4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80052AC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80052ACC: jal         0x80052A28
    // 0x80052AD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80052A28(rdram, ctx);
        goto after_1;
    // 0x80052AD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80052AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80052AD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80052ADC: jr          $ra
    // 0x80052AE0: nop

    return;
    // 0x80052AE0: nop

;}
RECOMP_FUNC void func_807AC7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AC7E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AC7E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AC7E8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AC7EC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26A4) << 16);
    // 0x807AC7F0: lwc1        $f0, -0x12FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26A4));
    // 0x807AC7F4: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26A8) << 16);
    // 0x807AC7F8: lwc1        $f6, -0x12F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26A8));
    // 0x807AC7FC: lwc1        $f4, 0x474($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X474);
    // 0x807AC800: sll         $t6, $a1, 6
    ctx->r14 = S32(ctx->r5 << 6);
    // 0x807AC804: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x807AC808: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807AC80C: addiu       $a0, $a0, 0x3E8
    ctx->r4 = ADD32(ctx->r4, 0X3E8);
    // 0x807AC810: swc1        $f8, 0x474($v0)
    MEM_W(0X474, ctx->r2) = ctx->f8.u32l;
    // 0x807AC814: lwc1        $f10, 0x474($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X474);
    // 0x807AC818: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x807AC81C: nop

    // 0x807AC820: bc1fl       L_807AC830
    if (!c1cs) {
        // 0x807AC824: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_807AC830;
    }
    goto skip_0;
    // 0x807AC824: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    skip_0:
    // 0x807AC828: swc1        $f0, 0x474($v0)
    MEM_W(0X474, ctx->r2) = ctx->f0.u32l;
    // 0x807AC82C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_807AC830:
    // 0x807AC830: jal         0x80086F28
    // 0x807AC834: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gMtxIdent(rdram, ctx);
        goto after_0;
    // 0x807AC834: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807AC838: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807AC83C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AC840: lwc1        $f0, 0x474($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X474);
    // 0x807AC844: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x807AC848: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x807AC84C: jal         0x8007FE74
    // 0x807AC850: nop

    func_8007FE74(rdram, ctx);
        goto after_1;
    // 0x807AC850: nop

    after_1:
    // 0x807AC854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AC858: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AC85C: jr          $ra
    // 0x807AC860: nop

    return;
    // 0x807AC860: nop

;}
RECOMP_FUNC void func_80451690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80451690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80451694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80451698: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8045169C: jal         0x80450F94
    // 0x804516A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80450F94(rdram, ctx);
        goto after_0;
    // 0x804516A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x804516A4: jal         0x804507C4
    // 0x804516A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804507C4(rdram, ctx);
        goto after_1;
    // 0x804516A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804516AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804516B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804516B4: jr          $ra
    // 0x804516B8: nop

    return;
    // 0x804516B8: nop

;}
RECOMP_FUNC void func_805AC028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AC02C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AC030: jal         0x805ABFC0
    // 0x805AC034: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805ABFC0(rdram, ctx);
        goto after_0;
    // 0x805AC034: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805AC038: beq         $v0, $zero, L_805AC078
    if (ctx->r2 == 0) {
        // 0x805AC03C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805AC078;
    }
    // 0x805AC03C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AC040: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805AC044: lui         $t6, 0x805B
    ctx->r14 = S32(RELOC_HI16(438, 0X540) << 16);
    // 0x805AC048: addiu       $t6, $t6, -0x3F30
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(438, 0X540));
    // 0x805AC04C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AC050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805AC054: jal         0x805AC088
    // 0x805AC058: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    func_805AC088(rdram, ctx);
        goto after_1;
    // 0x805AC058: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    after_1:
    // 0x805AC05C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x805AC060: lui         $t8, 0x805B
    ctx->r24 = S32(RELOC_HI16(438, 0X11C) << 16);
    // 0x805AC064: addiu       $t8, $t8, -0x4354
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(438, 0X11C));
    // 0x805AC068: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805AC06C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805AC070: sw          $t8, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->r24;
    // 0x805AC074: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
L_805AC078:
    // 0x805AC078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AC07C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AC080: jr          $ra
    // 0x805AC084: nop

    return;
    // 0x805AC084: nop

;}
RECOMP_FUNC void func_8046562C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046562C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80465630: sll         $a3, $a2, 4
    ctx->r7 = S32(ctx->r6 << 4);
    // 0x80465634: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    // 0x80465638: sll         $t7, $a2, 10
    ctx->r15 = S32(ctx->r6 << 10);
    // 0x8046563C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80465640: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80465644: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80465648: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8046564C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80465650: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80465654: subu        $t8, $a1, $a3
    ctx->r24 = SUB32(ctx->r5, ctx->r7);
    // 0x80465658: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8046565C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80465660: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80465664: bgez        $a2, L_80465674
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80465668: sra         $t1, $a2, 2
        ctx->r9 = S32(SIGNED(ctx->r6) >> 2);
            goto L_80465674;
    }
    // 0x80465668: sra         $t1, $a2, 2
    ctx->r9 = S32(SIGNED(ctx->r6) >> 2);
    // 0x8046566C: addiu       $at, $a2, 0x3
    ctx->r1 = ADD32(ctx->r6, 0X3);
    // 0x80465670: sra         $t1, $at, 2
    ctx->r9 = S32(SIGNED(ctx->r1) >> 2);
L_80465674:
    // 0x80465674: addiu       $t0, $t1, -0x1
    ctx->r8 = ADD32(ctx->r9, -0X1);
    // 0x80465678: bltz        $t0, L_80465700
    if (SIGNED(ctx->r8) < 0) {
        // 0x8046567C: sll         $t4, $a2, 1
        ctx->r12 = S32(ctx->r6 << 1);
            goto L_80465700;
    }
    // 0x8046567C: sll         $t4, $a2, 1
    ctx->r12 = S32(ctx->r6 << 1);
    // 0x80465680: lui         $t5, 0xB100
    ctx->r13 = S32(0XB100 << 16);
L_80465684:
    // 0x80465684: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80465688: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8046568C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80465690: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80465694: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80465698: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8046569C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x804656A0: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x804656A4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x804656A8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x804656AC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804656B0: andi        $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 & 0XFF;
    // 0x804656B4: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x804656B8: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x804656BC: sll         $t6, $t2, 16
    ctx->r14 = S32(ctx->r10 << 16);
    // 0x804656C0: sll         $t3, $a3, 1
    ctx->r11 = S32(ctx->r7 << 1);
    // 0x804656C4: andi        $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 & 0XFF;
    // 0x804656C8: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x804656CC: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x804656D0: addiu       $t4, $t4, -0x8
    ctx->r12 = ADD32(ctx->r12, -0X8);
    // 0x804656D4: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x804656D8: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x804656DC: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x804656E0: sll         $t9, $t3, 16
    ctx->r25 = S32(ctx->r11 << 16);
    // 0x804656E4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x804656E8: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x804656EC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x804656F0: or          $t7, $t6, $t2
    ctx->r15 = ctx->r14 | ctx->r10;
    // 0x804656F4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x804656F8: bgez        $t0, L_80465684
    if (SIGNED(ctx->r8) >= 0) {
        // 0x804656FC: sw          $t7, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r15;
            goto L_80465684;
    }
    // 0x804656FC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_80465700:
    // 0x80465700: jr          $ra
    // 0x80465704: nop

    return;
    // 0x80465704: nop

;}
RECOMP_FUNC void func_800792D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800792D4: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800792D8: lw          $v1, -0x7AF0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7AF0);
    // 0x800792DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800792E0: lhu         $t0, 0x1C($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X1C);
    // 0x800792E4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800792E8: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800792EC: beql        $at, $zero, L_80079440
    if (ctx->r1 == 0) {
        // 0x800792F0: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80079440;
    }
    goto skip_0;
    // 0x800792F0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    skip_0:
    // 0x800792F4: lhu         $t1, 0x1E($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X1E);
    // 0x800792F8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800792FC: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80079300: beql        $at, $zero, L_80079440
    if (ctx->r1 == 0) {
        // 0x80079304: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80079440;
    }
    goto skip_1;
    // 0x80079304: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    skip_1:
    // 0x80079308: lhu         $t2, 0x18($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X18);
    // 0x8007930C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80079310: slt         $at, $a3, $t2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80079314: bnel        $at, $zero, L_80079440
    if (ctx->r1 != 0) {
        // 0x80079318: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80079440;
    }
    goto skip_2;
    // 0x80079318: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    skip_2:
    // 0x8007931C: lhu         $t4, 0x1A($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X1A);
    // 0x80079320: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x80079324: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80079328: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007932C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80079330: bne         $at, $zero, L_8007943C
    if (ctx->r1 != 0) {
        // 0x80079334: slt         $at, $a1, $t2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8007943C;
    }
    // 0x80079334: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80079338: beq         $at, $zero, L_80079364
    if (ctx->r1 == 0) {
        // 0x8007933C: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80079364;
    }
    // 0x8007933C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80079340: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80079344: subu        $t6, $a1, $t2
    ctx->r14 = SUB32(ctx->r5, ctx->r10);
    // 0x80079348: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8007934C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80079350: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80079354: mflo        $t8
    ctx->r24 = lo;
    // 0x80079358: sra         $t9, $t8, 7
    ctx->r25 = S32(SIGNED(ctx->r24) >> 7);
    // 0x8007935C: subu        $t6, $t5, $t9
    ctx->r14 = SUB32(ctx->r13, ctx->r25);
    // 0x80079360: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
L_80079364:
    // 0x80079364: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80079368: beq         $at, $zero, L_80079390
    if (ctx->r1 == 0) {
        // 0x8007936C: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_80079390;
    }
    // 0x8007936C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80079370: subu        $t7, $a2, $t4
    ctx->r15 = SUB32(ctx->r6, ctx->r12);
    // 0x80079374: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80079378: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007937C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80079380: mflo        $t5
    ctx->r13 = lo;
    // 0x80079384: sra         $t9, $t5, 7
    ctx->r25 = S32(SIGNED(ctx->r13) >> 7);
    // 0x80079388: subu        $t7, $t6, $t9
    ctx->r15 = SUB32(ctx->r14, ctx->r25);
    // 0x8007938C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_80079390:
    // 0x80079390: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80079394: beql        $at, $zero, L_800793A4
    if (ctx->r1 == 0) {
        // 0x80079398: slt         $at, $t1, $t3
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800793A4;
    }
    goto skip_3;
    // 0x80079398: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    skip_3:
    // 0x8007939C: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x800793A0: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
L_800793A4:
    // 0x800793A4: beq         $at, $zero, L_800793B0
    if (ctx->r1 == 0) {
        // 0x800793A8: andi        $t8, $a3, 0xFFF
        ctx->r24 = ctx->r7 & 0XFFF;
            goto L_800793B0;
    }
    // 0x800793A8: andi        $t8, $a3, 0xFFF
    ctx->r24 = ctx->r7 & 0XFFF;
    // 0x800793AC: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_800793B0:
    // 0x800793B0: sll         $t5, $t8, 12
    ctx->r13 = S32(ctx->r24 << 12);
    // 0x800793B4: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800793B8: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800793BC: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x800793C0: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800793C4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800793C8: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x800793CC: andi        $t9, $a1, 0xFFF
    ctx->r25 = ctx->r5 & 0XFFF;
    // 0x800793D0: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x800793D4: andi        $t5, $t8, 0x7
    ctx->r13 = ctx->r24 & 0X7;
    // 0x800793D8: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x800793DC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800793E0: andi        $t5, $a2, 0xFFF
    ctx->r13 = ctx->r6 & 0XFFF;
    // 0x800793E4: or          $t9, $t8, $t5
    ctx->r25 = ctx->r24 | ctx->r13;
    // 0x800793E8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800793EC: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800793F0: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x800793F4: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800793F8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800793FC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80079400: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80079404: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80079408: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x8007940C: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80079410: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x80079414: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80079418: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x8007941C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80079420: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80079424: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80079428: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007942C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80079430: sll         $t7, $t6, 18
    ctx->r15 = S32(ctx->r14 << 18);
    // 0x80079434: or          $t5, $t7, $t9
    ctx->r13 = ctx->r15 | ctx->r25;
    // 0x80079438: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
L_8007943C:
    // 0x8007943C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_80079440:
    // 0x80079440: jr          $ra
    // 0x80079444: nop

    return;
    // 0x80079444: nop

;}
RECOMP_FUNC void func_804C192C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C192C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C1930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C1934: jal         0x804C18D0
    // 0x804C1938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C18D0(rdram, ctx);
        goto after_0;
    // 0x804C1938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C193C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x804C1940: bne         $v0, $at, L_804C196C
    if (ctx->r2 != ctx->r1) {
        // 0x804C1944: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804C196C;
    }
    // 0x804C1944: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C1948: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x804C194C: bne         $t6, $zero, L_804C1964
    if (ctx->r14 != 0) {
        // 0x804C1950: nop
    
            goto L_804C1964;
    }
    // 0x804C1950: nop

    // 0x804C1954: jal         0x804C1CB0
    // 0x804C1958: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804C1CB0(rdram, ctx);
        goto after_1;
    // 0x804C1958: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804C195C: b           L_804C1970
    // 0x804C1960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804C1970;
    // 0x804C1960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C1964:
    // 0x804C1964: jal         0x804C1CB0
    // 0x804C1968: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_804C1CB0(rdram, ctx);
        goto after_2;
    // 0x804C1968: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_804C196C:
    // 0x804C196C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C1970:
    // 0x804C1970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C1974: jr          $ra
    // 0x804C1978: nop

    return;
    // 0x804C1978: nop

;}
RECOMP_FUNC void func_8052DE04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052DE04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8052DE08: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x8052DE0C: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x8052DE10: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8052DE14: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8052DE18: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8052DE1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8052DE20: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8052DE24: lw          $t9, 0x1F4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X1F4);
    // 0x8052DE28: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8052DE2C: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x8052DE30: lhu         $t0, 0x119E($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X119E);
    // 0x8052DE34: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x8052DE38: lui         $a3, 0x50
    ctx->r7 = S32(0X50 << 16);
    // 0x8052DE3C: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x8052DE40: beql        $t1, $zero, L_8052DEC0
    if (ctx->r9 == 0) {
        // 0x8052DE44: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_8052DEC0;
    }
    goto skip_0;
    // 0x8052DE44: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8052DE48: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8052DE4C: ori         $t5, $t5, 0x18
    ctx->r13 = ctx->r13 | 0X18;
    // 0x8052DE50: addiu       $t6, $zero, 0x2C80
    ctx->r14 = ADD32(0, 0X2C80);
    // 0x8052DE54: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8052DE58: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8052DE5C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8052DE60: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8052DE64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8052DE68: lui         $a3, 0xF0A
    ctx->r7 = S32(0XF0A << 16);
    // 0x8052DE6C: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8052DE70: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8052DE74: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8052DE78: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8052DE7C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8052DE80: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8052DE84: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x8052DE88: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x8052DE8C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8052DE90: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8052DE94: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8052DE98: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8052DE9C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8052DEA0: lui         $t0, 0xB900
    ctx->r8 = S32(0XB900 << 16);
    // 0x8052DEA4: ori         $t0, $t0, 0x31D
    ctx->r8 = ctx->r8 | 0X31D;
    // 0x8052DEA8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8052DEAC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8052DEB0: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8052DEB4: b           L_8052DF2C
    // 0x8052DEB8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
        goto L_8052DF2C;
    // 0x8052DEB8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8052DEBC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_8052DEC0:
    // 0x8052DEC0: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x8052DEC4: ori         $t4, $t4, 0x18
    ctx->r12 = ctx->r12 | 0X18;
    // 0x8052DEC8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8052DECC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8052DED0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8052DED4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8052DED8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8052DEDC: addiu       $t5, $zero, 0x2C80
    ctx->r13 = ADD32(0, 0X2C80);
    // 0x8052DEE0: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8052DEE4: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8052DEE8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8052DEEC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8052DEF0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8052DEF4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8052DEF8: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x8052DEFC: ori         $a3, $a3, 0x41C8
    ctx->r7 = ctx->r7 | 0X41C8;
    // 0x8052DF00: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8052DF04: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8052DF08: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8052DF0C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8052DF10: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8052DF14: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x8052DF18: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x8052DF1C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8052DF20: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8052DF24: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8052DF28: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8052DF2C:
    // 0x8052DF2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8052DF30: lui         $t1, 0xFCFF
    ctx->r9 = S32(0XFCFF << 16);
    // 0x8052DF34: lui         $t2, 0xFFFE
    ctx->r10 = S32(0XFFFE << 16);
    // 0x8052DF38: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8052DF3C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8052DF40: ori         $t2, $t2, 0x793C
    ctx->r10 = ctx->r10 | 0X793C;
    // 0x8052DF44: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x8052DF48: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8052DF4C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8052DF50: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8052DF54: lui         $t4, 0xB700
    ctx->r12 = S32(0XB700 << 16);
    // 0x8052DF58: addiu       $t5, $zero, 0x204
    ctx->r13 = ADD32(0, 0X204);
    // 0x8052DF5C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8052DF60: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8052DF64: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8052DF68: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8052DF6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8052DF70: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8052DF74: ori         $t8, $t8, 0x8000
    ctx->r24 = ctx->r24 | 0X8000;
    // 0x8052DF78: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8052DF7C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8052DF80: lui         $t7, 0xBB00
    ctx->r15 = S32(0XBB00 << 16);
    // 0x8052DF84: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8052DF88: jr          $ra
    // 0x8052DF8C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    return;
    // 0x8052DF8C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_80044800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044800: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80044804: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044808: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8004480C: beq         $t7, $zero, L_8004482C
    if (ctx->r15 == 0) {
        // 0x80044810: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8004482C;
    }
    // 0x80044810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044814: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80044818: addiu       $a0, $a0, 0x540
    ctx->r4 = ADD32(ctx->r4, 0X540);
    // 0x8004481C: jal         0x80071380
    // 0x80044820: addiu       $a1, $zero, 0x58D
    ctx->r5 = ADD32(0, 0X58D);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80044820: addiu       $a1, $zero, 0x58D
    ctx->r5 = ADD32(0, 0X58D);
    after_0:
    // 0x80044824: b           L_80044880
    // 0x80044828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80044880;
    // 0x80044828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004482C:
    // 0x8004482C: lbu         $t8, 0x28($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X28);
    // 0x80044830: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80044834: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80044838: bgtz        $t0, L_8004487C
    if (SIGNED(ctx->r8) > 0) {
        // 0x8004483C: sb          $t9, 0x28($a0)
        MEM_B(0X28, ctx->r4) = ctx->r25;
            goto L_8004487C;
    }
    // 0x8004483C: sb          $t9, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r25;
    // 0x80044840: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80044844: jal         0x80043DD4
    // 0x80044848: addiu       $a0, $a0, -0x77AC
    ctx->r4 = ADD32(ctx->r4, -0X77AC);
    func_80043DD4(rdram, ctx);
        goto after_1;
    // 0x80044848: addiu       $a0, $a0, -0x77AC
    ctx->r4 = ADD32(ctx->r4, -0X77AC);
    after_1:
    // 0x8004484C: bne         $v0, $zero, L_8004486C
    if (ctx->r2 != 0) {
        // 0x80044850: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8004486C;
    }
    // 0x80044850: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80044854: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80044858: addiu       $a0, $a0, 0x550
    ctx->r4 = ADD32(ctx->r4, 0X550);
    // 0x8004485C: jal         0x80071380
    // 0x80044860: addiu       $a1, $zero, 0x599
    ctx->r5 = ADD32(0, 0X599);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x80044860: addiu       $a1, $zero, 0x599
    ctx->r5 = ADD32(0, 0X599);
    after_2:
    // 0x80044864: b           L_80044880
    // 0x80044868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80044880;
    // 0x80044868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004486C:
    // 0x8004486C: beq         $v0, $zero, L_8004487C
    if (ctx->r2 == 0) {
        // 0x80044870: sb          $zero, 0x17D($v0)
        MEM_B(0X17D, ctx->r2) = 0;
            goto L_8004487C;
    }
    // 0x80044870: sb          $zero, 0x17D($v0)
    MEM_B(0X17D, ctx->r2) = 0;
    // 0x80044874: jal         0x80048BA0
    // 0x80044878: nop

    func_80048BA0(rdram, ctx);
        goto after_3;
    // 0x80044878: nop

    after_3:
L_8004487C:
    // 0x8004487C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044880:
    // 0x80044880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044884: jr          $ra
    // 0x80044888: nop

    return;
    // 0x80044888: nop

;}
RECOMP_FUNC void func_804BDAFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BDAFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BDB00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BDB04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804BDB08: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x804BDB0C: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x804BDB10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BDB14: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x804BDB18: addiu       $t7, $zero, -0x5
    ctx->r15 = ADD32(0, -0X5);
    // 0x804BDB1C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804BDB20: lw          $a2, 0x370($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X370);
    // 0x804BDB24: addiu       $v0, $v1, 0x350
    ctx->r2 = ADD32(ctx->r3, 0X350);
    // 0x804BDB28: lui         $t9, 0x804C
    ctx->r25 = S32(RELOC_HI16(191, 0X2240) << 16);
    // 0x804BDB2C: sh          $zero, 0x144($a2)
    MEM_H(0X144, ctx->r6) = 0;
    // 0x804BDB30: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804BDB34: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x804BDB38: addiu       $t9, $t9, -0x2490
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(191, 0X2240));
    // 0x804BDB3C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x804BDB40: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
    // 0x804BDB44: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x804BDB48: lw          $a0, 0x34($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X34);
    // 0x804BDB4C: jal         0x80067BBC
    // 0x804BDB50: lw          $a1, 0x38($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x804BDB50: lw          $a1, 0x38($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X38);
    after_0:
    // 0x804BDB54: addiu       $a0, $zero, 0x20E
    ctx->r4 = ADD32(0, 0X20E);
    // 0x804BDB58: jal         0x80067818
    // 0x804BDB5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x804BDB5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x804BDB60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BDB64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BDB68: jr          $ra
    // 0x804BDB6C: nop

    return;
    // 0x804BDB6C: nop

;}
RECOMP_FUNC void func_8064F2E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F2E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064F2EC: slti        $at, $a0, 0xB4
    ctx->r1 = SIGNED(ctx->r4) < 0XB4 ? 1 : 0;
    // 0x8064F2F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064F2F4: beq         $at, $zero, L_8064F30C
    if (ctx->r1 == 0) {
        // 0x8064F2F8: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8064F30C;
    }
    // 0x8064F2F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8064F2FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064F300: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8064F304: b           L_8064F348
    // 0x8064F308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8064F348;
    // 0x8064F308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064F30C:
    // 0x8064F30C: jal         0x80066DE4
    // 0x8064F310: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8064F310: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x8064F314: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8064F318: jal         0x80066E88
    // 0x8064F31C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8064F31C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8064F320: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(501, 0X15D4C) << 16);
    // 0x8064F324: lwc1        $f4, 0x474C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(501, 0X15D4C));
    // 0x8064F328: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8064F32C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064F330: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8064F334: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8064F338: nop

    // 0x8064F33C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8064F340: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8064F344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064F348:
    // 0x8064F348: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064F34C: jr          $ra
    // 0x8064F350: nop

    return;
    // 0x8064F350: nop

;}
RECOMP_FUNC void func_806AF5F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AF5F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806AF5FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AF600: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AF604: jal         0x806AF580
    // 0x806AF608: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806AF580(rdram, ctx);
        goto after_0;
    // 0x806AF608: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806AF60C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AF610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AF614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806AF618: jal         0x806AF64C
    // 0x806AF61C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806AF64C(rdram, ctx);
        goto after_1;
    // 0x806AF61C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x806AF620: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x806AF624: jal         0x806AF278
    // 0x806AF628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AF278(rdram, ctx);
        goto after_2;
    // 0x806AF628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806AF62C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x806AF630: sh          $t6, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r14;
    // 0x806AF634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806AF638: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x806AF63C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AF640: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x806AF644: jr          $ra
    // 0x806AF648: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806AF648: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80445DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445DF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445DF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80445DFC: jal         0x8044448C
    // 0x80445E00: addiu       $a1, $zero, 0x46E5
    ctx->r5 = ADD32(0, 0X46E5);
    func_8044448C(rdram, ctx);
        goto after_0;
    // 0x80445E00: addiu       $a1, $zero, 0x46E5
    ctx->r5 = ADD32(0, 0X46E5);
    after_0:
    // 0x80445E04: bne         $v0, $zero, L_80445E1C
    if (ctx->r2 != 0) {
        // 0x80445E08: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80445E1C;
    }
    // 0x80445E08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80445E0C: lui         $a1, 0x4320
    ctx->r5 = S32(0X4320 << 16);
    // 0x80445E10: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    // 0x80445E14: jal         0x804450A4
    // 0x80445E18: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    func_804450A4(rdram, ctx);
        goto after_1;
    // 0x80445E18: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    after_1:
L_80445E1C:
    // 0x80445E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445E20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445E24: jr          $ra
    // 0x80445E28: nop

    return;
    // 0x80445E28: nop

;}
RECOMP_FUNC void func_805AA55C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA55C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AA560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AA564: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805AA568: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x805AA56C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805AA570: lui         $t8, 0x805B
    ctx->r24 = S32(RELOC_HI16(432, 0XAC0) << 16);
    // 0x805AA574: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805AA578: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x805AA57C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805AA580: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805AA584: lw          $t8, -0x5250($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(432, 0XAC0));
    // 0x805AA588: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805AA58C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805AA590: jal         0x80048490
    // 0x805AA594: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x805AA594: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x805AA598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AA59C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AA5A0: jr          $ra
    // 0x805AA5A4: nop

    return;
    // 0x805AA5A4: nop

;}
RECOMP_FUNC void func_8003F14C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F14C: sw          $a2, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r6;
    // 0x8003F150: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003F154: lwc1        $f6, 0x248($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X248);
    // 0x8003F158: lwc1        $f4, 0x64($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X64);
    // 0x8003F15C: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8003F160: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003F164: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003F168: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8003F16C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003F170: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003F174: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x8003F178: swc1        $f16, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f16.u32l;
    // 0x8003F17C: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x8003F180: lwc1        $f18, 0x24C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X24C);
    // 0x8003F184: jr          $ra
    // 0x8003F188: swc1        $f18, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x8003F188: swc1        $f18, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void lnearbyintf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800820A0: round.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = lroundf(ctx->f12.fl);
    // 0x800820A4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800820A8: jr          $ra
    // 0x800820AC: nop

    return;
    // 0x800820AC: nop

;}
RECOMP_FUNC void func_8002B200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B200: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002B204: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8002B208: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8002B20C: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8002B210: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8002B214: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002B218: lw          $a3, 0xAAC($v1)
    ctx->r7 = MEM_W(ctx->r3, 0XAAC);
    // 0x8002B21C: lw          $t8, -0x20DC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X20DC);
    // 0x8002B220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002B224: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8002B228: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002B22C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002B230: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8002B234: jal         0x8002B088
    // 0x8002B238: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    func_8002B088(rdram, ctx);
        goto after_0;
    // 0x8002B238: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_0:
    // 0x8002B23C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8002B240: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8002B244: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8002B248: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8002B24C: beq         $v0, $at, L_8002B364
    if (ctx->r2 == ctx->r1) {
        // 0x8002B250: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8002B364;
    }
    // 0x8002B250: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002B254: lw          $t9, 0xAA8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAA8);
    // 0x8002B258: lw          $a0, 0xAB0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XAB0);
    // 0x8002B25C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002B260: bne         $v0, $t9, L_8002B2C0
    if (ctx->r2 != ctx->r25) {
        // 0x8002B264: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_8002B2C0;
    }
    // 0x8002B264: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002B268: slti        $at, $a3, 0x64
    ctx->r1 = SIGNED(ctx->r7) < 0X64 ? 1 : 0;
    // 0x8002B26C: bnel        $at, $zero, L_8002B27C
    if (ctx->r1 != 0) {
        // 0x8002B270: lw          $t0, 0xC28($v1)
        ctx->r8 = MEM_W(ctx->r3, 0XC28);
            goto L_8002B27C;
    }
    goto skip_0;
    // 0x8002B270: lw          $t0, 0xC28($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC28);
    skip_0:
    // 0x8002B274: addiu       $a3, $zero, 0x63
    ctx->r7 = ADD32(0, 0X63);
    // 0x8002B278: lw          $t0, 0xC28($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC28);
L_8002B27C:
    // 0x8002B27C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8002B280: bnel        $t0, $zero, L_8002B2CC
    if (ctx->r8 != 0) {
        // 0x8002B284: lw          $t2, 0xB30($v1)
        ctx->r10 = MEM_W(ctx->r3, 0XB30);
            goto L_8002B2CC;
    }
    goto skip_1;
    // 0x8002B284: lw          $t2, 0xB30($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XB30);
    skip_1:
    // 0x8002B288: div         $zero, $a3, $at
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r1)));
    // 0x8002B28C: mfhi        $t1
    ctx->r9 = hi;
    // 0x8002B290: bnel        $t1, $zero, L_8002B2CC
    if (ctx->r9 != 0) {
        // 0x8002B294: lw          $t2, 0xB30($v1)
        ctx->r10 = MEM_W(ctx->r3, 0XB30);
            goto L_8002B2CC;
    }
    goto skip_2;
    // 0x8002B294: lw          $t2, 0xB30($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XB30);
    skip_2:
    // 0x8002B298: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x8002B29C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002B2A0: jal         0x8002B124
    // 0x8002B2A4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8002B124(rdram, ctx);
        goto after_1;
    // 0x8002B2A4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x8002B2A8: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8002B2AC: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8002B2B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002B2B4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B2B8: b           L_8002B2C8
    // 0x8002B2BC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
        goto L_8002B2C8;
    // 0x8002B2BC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
L_8002B2C0:
    // 0x8002B2C0: sw          $v0, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->r2;
    // 0x8002B2C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8002B2C8:
    // 0x8002B2C8: lw          $t2, 0xB30($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XB30);
L_8002B2CC:
    // 0x8002B2CC: sw          $a3, 0xAAC($v1)
    MEM_W(0XAAC, ctx->r3) = ctx->r7;
    // 0x8002B2D0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8002B2D4: slti        $at, $t2, 0x1F
    ctx->r1 = SIGNED(ctx->r10) < 0X1F ? 1 : 0;
    // 0x8002B2D8: beq         $at, $zero, L_8002B2FC
    if (ctx->r1 == 0) {
        // 0x8002B2DC: nop
    
            goto L_8002B2FC;
    }
    // 0x8002B2DC: nop

    // 0x8002B2E0: lw          $t3, 0x3EC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X3EC);
    // 0x8002B2E4: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x8002B2E8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8002B2EC: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8002B2F0: lbu         $t5, 0x598($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X598);
    // 0x8002B2F4: bne         $t5, $at, L_8002B304
    if (ctx->r13 != ctx->r1) {
        // 0x8002B2F8: nop
    
            goto L_8002B304;
    }
    // 0x8002B2F8: nop

L_8002B2FC:
    // 0x8002B2FC: b           L_8002B304
    // 0x8002B300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8002B304;
    // 0x8002B300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8002B304:
    // 0x8002B304: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B308: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002B30C: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B310: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8002B314: bgezl       $a0, L_8002B324
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8002B318: lw          $t8, 0xAA0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XAA0);
            goto L_8002B324;
    }
    goto skip_3;
    // 0x8002B318: lw          $t8, 0xAA0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XAA0);
    skip_3:
    // 0x8002B31C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002B320: lw          $t8, 0xAA0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XAA0);
L_8002B324:
    // 0x8002B324: sw          $a0, 0xAB0($v1)
    MEM_W(0XAB0, ctx->r3) = ctx->r4;
    // 0x8002B328: bne         $a1, $t8, L_8002B340
    if (ctx->r5 != ctx->r24) {
        // 0x8002B32C: nop
    
            goto L_8002B340;
    }
    // 0x8002B32C: nop

    // 0x8002B330: jal         0x80049674
    // 0x8002B334: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80049674(rdram, ctx);
        goto after_2;
    // 0x8002B334: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x8002B338: b           L_8002B354
    // 0x8002B33C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
        goto L_8002B354;
    // 0x8002B33C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_8002B340:
    // 0x8002B340: bne         $a1, $at, L_8002B354
    if (ctx->r5 != ctx->r1) {
        // 0x8002B344: nop
    
            goto L_8002B354;
    }
    // 0x8002B344: nop

    // 0x8002B348: lw          $t9, 0xAC0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAC0);
    // 0x8002B34C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8002B350: sw          $t0, 0xAC0($v1)
    MEM_W(0XAC0, ctx->r3) = ctx->r8;
L_8002B354:
    // 0x8002B354: jal         0x80049724
    // 0x8002B358: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80049724(rdram, ctx);
        goto after_3;
    // 0x8002B358: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x8002B35C: b           L_8002B384
    // 0x8002B360: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
        goto L_8002B384;
    // 0x8002B360: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_8002B364:
    // 0x8002B364: lw          $v0, 0xAB4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XAB4);
    // 0x8002B368: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8002B36C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8002B370: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8002B374: bgezl       $v0, L_8002B384
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B378: sw          $v0, 0xAB4($v1)
        MEM_W(0XAB4, ctx->r3) = ctx->r2;
            goto L_8002B384;
    }
    goto skip_4;
    // 0x8002B378: sw          $v0, 0xAB4($v1)
    MEM_W(0XAB4, ctx->r3) = ctx->r2;
    skip_4:
    // 0x8002B37C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002B380: sw          $v0, 0xAB4($v1)
    MEM_W(0XAB4, ctx->r3) = ctx->r2;
L_8002B384:
    // 0x8002B384: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8002B388: jal         0x8002B03C
    // 0x8002B38C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_8002B03C(rdram, ctx);
        goto after_4;
    // 0x8002B38C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x8002B390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002B394: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002B398: jr          $ra
    // 0x8002B39C: nop

    return;
    // 0x8002B39C: nop

;}
RECOMP_FUNC void func_80470718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80470718: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8047071C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80470720: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80470724: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80470728: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8047072C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80470730: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80470734: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80470738: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8047073C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80470740: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80470744: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80470748: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8047074C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80470750: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80470754: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80470758: lui         $at, 0x3F34
    ctx->r1 = S32(0X3F34 << 16);
    // 0x8047075C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80470760: lw          $t6, 0xF3C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XF3C);
    // 0x80470764: lw          $s4, 0x1150($s1)
    ctx->r20 = MEM_W(ctx->r17, 0X1150);
    // 0x80470768: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(149, 0X1238) << 16);
    // 0x8047076C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80470770: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80470774: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80470778: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8047077C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80470780: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x80470784: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80470788: addiu       $s2, $v0, 0x8
    ctx->r18 = ADD32(ctx->r2, 0X8);
    // 0x8047078C: lwc1        $f28, 0xE48($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(149, 0X1238));
    // 0x80470790: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80470794: addiu       $s5, $zero, 0x19
    ctx->r21 = ADD32(0, 0X19);
    // 0x80470798: addiu       $s6, $zero, 0x510
    ctx->r22 = ADD32(0, 0X510);
    // 0x8047079C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x804707A0: addiu       $s4, $s4, -0x3C
    ctx->r20 = ADD32(ctx->r20, -0X3C);
L_804707A4:
    // 0x804707A4: lh          $t9, 0x10A4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X10A4);
    // 0x804707A8: lh          $t1, 0x114A($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X114A);
    // 0x804707AC: subu        $t0, $s4, $t9
    ctx->r8 = SUB32(ctx->r20, ctx->r25);
    // 0x804707B0: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x804707B4: bgezl       $v0, L_804707C4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x804707B8: subu        $t2, $s5, $v0
        ctx->r10 = SUB32(ctx->r21, ctx->r2);
            goto L_804707C4;
    }
    goto skip_0;
    // 0x804707B8: subu        $t2, $s5, $v0
    ctx->r10 = SUB32(ctx->r21, ctx->r2);
    skip_0:
    // 0x804707BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804707C0: subu        $t2, $s5, $v0
    ctx->r10 = SUB32(ctx->r21, ctx->r2);
L_804707C4:
    // 0x804707C4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x804707C8: andi        $t3, $v0, 0x1FF
    ctx->r11 = ctx->r2 & 0X1FF;
    // 0x804707CC: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x804707D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804707D4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x804707D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804707DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x804707E0: mul.s       $f20, $f6, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x804707E4: nop

    // 0x804707E8: mul.s       $f16, $f10, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x804707EC: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x804707F0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804707F4: bc1f        L_80470800
    if (!c1cs) {
        // 0x804707F8: trunc.w.s   $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
            goto L_80470800;
    }
    // 0x804707F8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804707FC: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
L_80470800:
    // 0x80470800: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80470804: nop

    // 0x80470808: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8047080C: nop

    // 0x80470810: cvt.s.w     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    ctx->f22.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80470814: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
    // 0x80470818: jal         0x80066DE4
    // 0x8047081C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8047081C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x80470820: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80470824: jal         0x80066E88
    // 0x80470828: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80470828: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_1:
    // 0x8047082C: lh          $t5, 0xFE2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XFE2);
    // 0x80470830: lh          $t6, 0x1148($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1148);
    // 0x80470834: lh          $v0, 0x1146($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X1146);
    // 0x80470838: lh          $t8, 0xF40($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XF40);
    // 0x8047083C: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80470840: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80470844: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x80470848: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8047084C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80470850: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x80470854: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80470858: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x8047085C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80470860: mul.s       $f18, $f24, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f24.fl, ctx->f16.fl);
    // 0x80470864: nop

    // 0x80470868: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8047086C: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80470870: mul.s       $f16, $f20, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80470874: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80470878: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8047087C: nop

    // 0x80470880: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80470884: sh          $t4, -0x10($s2)
    MEM_H(-0X10, ctx->r18) = ctx->r12;
    // 0x80470888: lh          $t6, 0x1146($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1146);
    // 0x8047088C: lh          $t5, 0xF3E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XF3E);
    // 0x80470890: lh          $t8, 0xFE0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XFE0);
    // 0x80470894: lh          $v1, 0x1148($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X1148);
    // 0x80470898: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8047089C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x804708A0: subu        $t9, $t8, $v1
    ctx->r25 = SUB32(ctx->r24, ctx->r3);
    // 0x804708A4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x804708A8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804708AC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x804708B0: mul.s       $f18, $f24, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x804708B4: nop

    // 0x804708B8: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x804708BC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x804708C0: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x804708C4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x804708C8: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x804708CC: nop

    // 0x804708D0: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x804708D4: bne         $s3, $s6, L_804707A4
    if (ctx->r19 != ctx->r22) {
        // 0x804708D8: sh          $t4, -0xE($s2)
        MEM_H(-0XE, ctx->r18) = ctx->r12;
            goto L_804707A4;
    }
    // 0x804708D8: sh          $t4, -0xE($s2)
    MEM_H(-0XE, ctx->r18) = ctx->r12;
    // 0x804708DC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x804708E0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x804708E4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x804708E8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x804708EC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x804708F0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x804708F4: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x804708F8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x804708FC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80470900: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80470904: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80470908: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8047090C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80470910: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80470914: jr          $ra
    // 0x80470918: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80470918: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8003A060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A060: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003A064: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8003A068: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8003A06C: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8003A070: beq         $v0, $zero, L_8003A3F4
    if (ctx->r2 == 0) {
        // 0x8003A074: sll         $t7, $t6, 2
        ctx->r15 = S32(ctx->r14 << 2);
            goto L_8003A3F4;
    }
    // 0x8003A074: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8003A078: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8003A07C: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8003A080: lw          $t0, -0x1380($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1380);
    // 0x8003A084: lw          $t1, 0x70($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X70);
    // 0x8003A088: lw          $v1, 0x2C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X2C);
    // 0x8003A08C: lw          $a1, 0x30($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X30);
    // 0x8003A090: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8003A094: lwc1        $f2, 0x4($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8003A098: lwc1        $f12, 0x8($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8003A09C: lw          $a2, 0x34($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X34);
    // 0x8003A0A0: lw          $a3, 0x38($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X38);
    // 0x8003A0A4: beq         $v1, $zero, L_8003A3F4
    if (ctx->r3 == 0) {
        // 0x8003A0A8: sw          $t0, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->r8;
            goto L_8003A3F4;
    }
    // 0x8003A0A8: sw          $t0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r8;
    // 0x8003A0AC: andi        $a0, $v1, 0x3
    ctx->r4 = ctx->r3 & 0X3;
    // 0x8003A0B0: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8003A0B4: beq         $a0, $zero, L_8003A184
    if (ctx->r4 == 0) {
        // 0x8003A0B8: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_8003A184;
    }
    // 0x8003A0B8: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x8003A0BC: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x8003A0C0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8003A0C4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8003A0C8: nop

    // 0x8003A0CC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A0D0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003A0D4: beql        $v0, $v1, L_8003A140
    if (ctx->r2 == ctx->r3) {
        // 0x8003A0D8: swc1        $f18, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
            goto L_8003A140;
    }
    goto skip_0;
    // 0x8003A0D8: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    skip_0:
    // 0x8003A0DC: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_8003A0E0:
    // 0x8003A0E0: lh          $t9, 0x2($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X2);
    // 0x8003A0E4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8003A0E8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8003A0EC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8003A0F0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8003A0F4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8003A0F8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A0FC: addiu       $t0, $t0, 0x6
    ctx->r8 = ADD32(ctx->r8, 0X6);
    // 0x8003A100: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003A104: swc1        $f16, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f16.u32l;
    // 0x8003A108: lh          $t2, -0x2($t0)
    ctx->r10 = MEM_H(ctx->r8, -0X2);
    // 0x8003A10C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8003A110: nop

    // 0x8003A114: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A118: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8003A11C: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8003A120: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x8003A124: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8003A128: nop

    // 0x8003A12C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A130: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003A134: bnel        $v0, $v1, L_8003A0E0
    if (ctx->r2 != ctx->r3) {
        // 0x8003A138: swc1        $f18, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
            goto L_8003A0E0;
    }
    goto skip_1;
    // 0x8003A138: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    skip_1:
    // 0x8003A13C: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_8003A140:
    // 0x8003A140: lh          $t9, 0x2($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X2);
    // 0x8003A144: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8003A148: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8003A14C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8003A150: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8003A154: addiu       $t0, $t0, 0x6
    ctx->r8 = ADD32(ctx->r8, 0X6);
    // 0x8003A158: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A15C: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003A160: swc1        $f16, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f16.u32l;
    // 0x8003A164: lh          $t2, -0x2($t0)
    ctx->r10 = MEM_H(ctx->r8, -0X2);
    // 0x8003A168: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8003A16C: nop

    // 0x8003A170: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A174: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8003A178: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8003A17C: beq         $v1, $zero, L_8003A3F4
    if (ctx->r3 == 0) {
        // 0x8003A180: nop
    
            goto L_8003A3F4;
    }
    // 0x8003A180: nop

L_8003A184:
    // 0x8003A184: lh          $t3, 0x0($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X0);
    // 0x8003A188: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8003A18C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8003A190: nop

    // 0x8003A194: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A198: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003A19C: beql        $v1, $zero, L_8003A2E0
    if (ctx->r3 == 0) {
        // 0x8003A1A0: swc1        $f18, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
            goto L_8003A2E0;
    }
    goto skip_2;
    // 0x8003A1A0: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    skip_2:
    // 0x8003A1A4: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_8003A1A8:
    // 0x8003A1A8: lh          $t4, 0x2($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X2);
    // 0x8003A1AC: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8003A1B0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8003A1B4: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8003A1B8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8003A1BC: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8003A1C0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A1C4: addiu       $t0, $t0, 0x18
    ctx->r8 = ADD32(ctx->r8, 0X18);
    // 0x8003A1C8: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003A1CC: swc1        $f16, -0x10($a2)
    MEM_W(-0X10, ctx->r6) = ctx->f16.u32l;
    // 0x8003A1D0: lh          $t5, -0x14($t0)
    ctx->r13 = MEM_H(ctx->r8, -0X14);
    // 0x8003A1D4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8003A1D8: nop

    // 0x8003A1DC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A1E0: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8003A1E4: swc1        $f16, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->f16.u32l;
    // 0x8003A1E8: lh          $t6, -0x12($t0)
    ctx->r14 = MEM_H(ctx->r8, -0X12);
    // 0x8003A1EC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8003A1F0: nop

    // 0x8003A1F4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A1F8: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003A1FC: swc1        $f16, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->f16.u32l;
    // 0x8003A200: lh          $t7, -0x10($t0)
    ctx->r15 = MEM_H(ctx->r8, -0X10);
    // 0x8003A204: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8003A208: nop

    // 0x8003A20C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A210: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003A214: swc1        $f16, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->f16.u32l;
    // 0x8003A218: lh          $t8, -0xE($t0)
    ctx->r24 = MEM_H(ctx->r8, -0XE);
    // 0x8003A21C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8003A220: nop

    // 0x8003A224: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A228: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8003A22C: swc1        $f16, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f16.u32l;
    // 0x8003A230: lh          $t9, -0xC($t0)
    ctx->r25 = MEM_H(ctx->r8, -0XC);
    // 0x8003A234: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8003A238: nop

    // 0x8003A23C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A240: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003A244: swc1        $f16, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->f16.u32l;
    // 0x8003A248: lh          $t2, -0xA($t0)
    ctx->r10 = MEM_H(ctx->r8, -0XA);
    // 0x8003A24C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8003A250: nop

    // 0x8003A254: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A258: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003A25C: swc1        $f16, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->f16.u32l;
    // 0x8003A260: lh          $t3, -0x8($t0)
    ctx->r11 = MEM_H(ctx->r8, -0X8);
    // 0x8003A264: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8003A268: nop

    // 0x8003A26C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A270: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8003A274: swc1        $f16, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f16.u32l;
    // 0x8003A278: lh          $t4, -0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, -0X6);
    // 0x8003A27C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8003A280: nop

    // 0x8003A284: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A288: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003A28C: swc1        $f16, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f16.u32l;
    // 0x8003A290: lh          $t5, -0x4($t0)
    ctx->r13 = MEM_H(ctx->r8, -0X4);
    // 0x8003A294: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8003A298: nop

    // 0x8003A29C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A2A0: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003A2A4: swc1        $f16, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f16.u32l;
    // 0x8003A2A8: lh          $t6, -0x2($t0)
    ctx->r14 = MEM_H(ctx->r8, -0X2);
    // 0x8003A2AC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8003A2B0: nop

    // 0x8003A2B4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A2B8: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8003A2BC: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8003A2C0: lh          $t3, 0x0($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X0);
    // 0x8003A2C4: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8003A2C8: nop

    // 0x8003A2CC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A2D0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003A2D4: bnel        $v1, $zero, L_8003A1A8
    if (ctx->r3 != 0) {
        // 0x8003A2D8: swc1        $f18, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
            goto L_8003A1A8;
    }
    goto skip_3;
    // 0x8003A2D8: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    skip_3:
    // 0x8003A2DC: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_8003A2E0:
    // 0x8003A2E0: lh          $t4, 0x2($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X2);
    // 0x8003A2E4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8003A2E8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8003A2EC: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8003A2F0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8003A2F4: addiu       $t0, $t0, 0x18
    ctx->r8 = ADD32(ctx->r8, 0X18);
    // 0x8003A2F8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A2FC: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003A300: swc1        $f16, -0x10($a2)
    MEM_W(-0X10, ctx->r6) = ctx->f16.u32l;
    // 0x8003A304: lh          $t5, -0x14($t0)
    ctx->r13 = MEM_H(ctx->r8, -0X14);
    // 0x8003A308: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8003A30C: nop

    // 0x8003A310: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A314: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8003A318: swc1        $f16, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->f16.u32l;
    // 0x8003A31C: lh          $t6, -0x12($t0)
    ctx->r14 = MEM_H(ctx->r8, -0X12);
    // 0x8003A320: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8003A324: nop

    // 0x8003A328: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A32C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003A330: swc1        $f16, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->f16.u32l;
    // 0x8003A334: lh          $t7, -0x10($t0)
    ctx->r15 = MEM_H(ctx->r8, -0X10);
    // 0x8003A338: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8003A33C: nop

    // 0x8003A340: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A344: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003A348: swc1        $f16, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->f16.u32l;
    // 0x8003A34C: lh          $t8, -0xE($t0)
    ctx->r24 = MEM_H(ctx->r8, -0XE);
    // 0x8003A350: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8003A354: nop

    // 0x8003A358: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A35C: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8003A360: swc1        $f16, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f16.u32l;
    // 0x8003A364: lh          $t9, -0xC($t0)
    ctx->r25 = MEM_H(ctx->r8, -0XC);
    // 0x8003A368: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8003A36C: nop

    // 0x8003A370: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A374: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003A378: swc1        $f16, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->f16.u32l;
    // 0x8003A37C: lh          $t2, -0xA($t0)
    ctx->r10 = MEM_H(ctx->r8, -0XA);
    // 0x8003A380: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8003A384: nop

    // 0x8003A388: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A38C: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003A390: swc1        $f16, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->f16.u32l;
    // 0x8003A394: lh          $t3, -0x8($t0)
    ctx->r11 = MEM_H(ctx->r8, -0X8);
    // 0x8003A398: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8003A39C: nop

    // 0x8003A3A0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A3A4: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8003A3A8: swc1        $f16, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f16.u32l;
    // 0x8003A3AC: lh          $t4, -0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, -0X6);
    // 0x8003A3B0: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8003A3B4: nop

    // 0x8003A3B8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A3BC: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003A3C0: swc1        $f16, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f16.u32l;
    // 0x8003A3C4: lh          $t5, -0x4($t0)
    ctx->r13 = MEM_H(ctx->r8, -0X4);
    // 0x8003A3C8: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8003A3CC: nop

    // 0x8003A3D0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A3D4: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003A3D8: swc1        $f16, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f16.u32l;
    // 0x8003A3DC: lh          $t6, -0x2($t0)
    ctx->r14 = MEM_H(ctx->r8, -0X2);
    // 0x8003A3E0: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8003A3E4: nop

    // 0x8003A3E8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003A3EC: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8003A3F0: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
L_8003A3F4:
    // 0x8003A3F4: jr          $ra
    // 0x8003A3F8: nop

    return;
    // 0x8003A3F8: nop

;}
RECOMP_FUNC void func_8044B164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B164: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8044B168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B16C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044B170: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B174: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044B178: lw          $a1, 0x6A6C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X6A6C);
    // 0x8044B17C: beq         $a1, $zero, L_8044B194
    if (ctx->r5 == 0) {
        // 0x8044B180: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044B194;
    }
    // 0x8044B180: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044B184: jal         0x80050A2C
    // 0x8044B188: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80050A2C(rdram, ctx);
        goto after_0;
    // 0x8044B188: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044B18C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B190: sw          $zero, 0x6A6C($v1)
    MEM_W(0X6A6C, ctx->r3) = 0;
L_8044B194:
    // 0x8044B194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044B198: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8044B19C: jr          $ra
    // 0x8044B1A0: nop

    return;
    // 0x8044B1A0: nop

;}
RECOMP_FUNC void func_806EFED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EFED8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EFEDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EFEE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EFEE4: jal         0x806EC16C
    // 0x806EFEE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806EC16C(rdram, ctx);
        goto after_0;
    // 0x806EFEE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EFEEC: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EFEF0: jal         0x800577D8
    // 0x806EFEF4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_1;
    // 0x806EFEF4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x806EFEF8: jal         0x806EF504
    // 0x806EFEFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF504(rdram, ctx);
        goto after_2;
    // 0x806EFEFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EFF00: jal         0x806EF584
    // 0x806EFF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF584(rdram, ctx);
        goto after_3;
    // 0x806EFF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EFF08: jal         0x806EF638
    // 0x806EFF0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF638(rdram, ctx);
        goto after_4;
    // 0x806EFF0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EFF10: jal         0x806EFCC4
    // 0x806EFF14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EFCC4(rdram, ctx);
        goto after_5;
    // 0x806EFF14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EFF18: beq         $v0, $zero, L_806EFF5C
    if (ctx->r2 == 0) {
        // 0x806EFF1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EFF5C;
    }
    // 0x806EFF1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EFF20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EFF24: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806EFF28: jal         0x806F0348
    // 0x806EFF2C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F0348(rdram, ctx);
        goto after_6;
    // 0x806EFF2C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x806EFF30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806EFF34: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x806EFF38: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4DA4) << 16);
    // 0x806EFF3C: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x806EFF40: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x806EFF44: lwc1        $f4, 0xCF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4DA4));
    // 0x806EFF48: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x806EFF4C: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x806EFF50: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x806EFF54: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806EFF58: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
L_806EFF5C:
    // 0x806EFF5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806EFF60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EFF64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EFF68: jr          $ra
    // 0x806EFF6C: nop

    return;
    // 0x806EFF6C: nop

;}
