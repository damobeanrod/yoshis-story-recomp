#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_805A1BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1BFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805A1C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A1C04: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x805A1C08: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x805A1C0C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x805A1C10: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805A1C14: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(411, 0X1D50) << 16);
    // 0x805A1C18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805A1C1C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x805A1C20: lwc1        $f4, 0x30C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(411, 0X1D50));
    // 0x805A1C24: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805A1C28: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x805A1C2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805A1C30: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805A1C34: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(411, 0X1DE0) << 16);
    // 0x805A1C38: lwc1        $f6, 0x3150($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(411, 0X1DE0));
    // 0x805A1C3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A1C40: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x805A1C44: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805A1C48: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x805A1C4C: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x805A1C50: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805A1C54: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x805A1C58: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x805A1C5C: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x805A1C60: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x805A1C64: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805A1C68: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x805A1C6C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x805A1C70: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x805A1C74: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x805A1C78: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x805A1C7C: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x805A1C80: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x805A1C84: lw          $t9, 0x10($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X10);
    // 0x805A1C88: jalr        $t9
    // 0x805A1C8C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805A1C8C: nop

    after_0:
    // 0x805A1C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A1C94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x805A1C98: jr          $ra
    // 0x805A1C9C: nop

    return;
    // 0x805A1C9C: nop

;}
RECOMP_FUNC void func_805D7900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7900: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(474, 0X10) << 16);
    // 0x805D7904: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x805D7908: jr          $ra
    // 0x805D790C: addiu       $v0, $v0, 0x7910
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(474, 0X10));
    return;
    // 0x805D790C: addiu       $v0, $v0, 0x7910
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(474, 0X10));
;}
RECOMP_FUNC void func_80787D9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80787D9C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80787DA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80787DA4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80787DA8: lw          $v1, 0x43E4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X43E4);
    // 0x80787DAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80787DB0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80787DB4: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80787DB8: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x80787DBC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80787DC0: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x80787DC4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80787DC8: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80787DCC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80787DD0: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80787DD4: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80787DD8: sllv        $a1, $t6, $v1
    ctx->r5 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x80787DDC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80787DE0: addu        $t1, $v0, $t7
    ctx->r9 = ADD32(ctx->r2, ctx->r15);
    // 0x80787DE4: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80787DE8: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_80787DEC:
    // 0x80787DEC: lwc1        $f4, 0x4990($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X4990);
    // 0x80787DF0: lwc1        $f6, 0x43E8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X43E8);
    // 0x80787DF4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80787DF8: slti        $at, $t0, 0x16A
    ctx->r1 = SIGNED(ctx->r8) < 0X16A ? 1 : 0;
    // 0x80787DFC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80787E00: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80787E04: addiu       $t1, $t1, 0x20
    ctx->r9 = ADD32(ctx->r9, 0X20);
    // 0x80787E08: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x80787E0C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80787E10: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80787E14: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80787E18: nop

    // 0x80787E1C: sh          $t9, -0x1E($t1)
    MEM_H(-0X1E, ctx->r9) = ctx->r25;
    // 0x80787E20: lwc1        $f4, 0x43E4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X43E4);
    // 0x80787E24: lwc1        $f18, 0x498C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X498C);
    // 0x80787E28: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80787E2C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80787E30: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80787E34: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80787E38: bne         $at, $zero, L_80787DEC
    if (ctx->r1 != 0) {
        // 0x80787E3C: sh          $t5, -0xE($t1)
        MEM_H(-0XE, ctx->r9) = ctx->r13;
            goto L_80787DEC;
    }
    // 0x80787E3C: sh          $t5, -0xE($t1)
    MEM_H(-0XE, ctx->r9) = ctx->r13;
    // 0x80787E40: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80787E44: lbu         $t6, 0x520C($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X520C);
    // 0x80787E48: addiu       $a2, $v1, 0x520D
    ctx->r6 = ADD32(ctx->r3, 0X520D);
    // 0x80787E4C: addiu       $v0, $zero, 0xB5
    ctx->r2 = ADD32(0, 0XB5);
    // 0x80787E50: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80787E54: sb          $t7, 0x520C($v1)
    MEM_B(0X520C, ctx->r3) = ctx->r15;
    // 0x80787E58: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80787E5C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80787E60:
    // 0x80787E60: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x80787E64: lbu         $t4, 0x1($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1);
    // 0x80787E68: lbu         $t6, 0x2($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X2);
    // 0x80787E6C: or          $t9, $t8, $a0
    ctx->r25 = ctx->r24 | ctx->r4;
    // 0x80787E70: lbu         $t8, 0x3($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X3);
    // 0x80787E74: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x80787E78: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80787E7C: or          $t5, $t4, $a0
    ctx->r13 = ctx->r12 | ctx->r4;
    // 0x80787E80: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x80787E84: or          $t9, $t8, $a0
    ctx->r25 = ctx->r24 | ctx->r4;
    // 0x80787E88: sb          $t9, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r25;
    // 0x80787E8C: sb          $t7, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r15;
    // 0x80787E90: sb          $t5, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r13;
    // 0x80787E94: bne         $t0, $v0, L_80787E60
    if (ctx->r8 != ctx->r2) {
        // 0x80787E98: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80787E60;
    }
    // 0x80787E98: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80787E9C: jr          $ra
    // 0x80787EA0: nop

    return;
    // 0x80787EA0: nop

;}
RECOMP_FUNC void func_806F28E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F28E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F28EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F28F0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806F28F4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806F28F8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806F28FC: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(679, 0X1B60) << 16);
    // 0x806F2900: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806F2904: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806F2908: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806F290C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806F2910: lw          $t8, 0x30E0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(679, 0X1B60));
    // 0x806F2914: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806F2918: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806F291C: jal         0x80048490
    // 0x806F2920: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806F2920: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806F2924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F2928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F292C: jr          $ra
    // 0x806F2930: nop

    return;
    // 0x806F2930: nop

;}
RECOMP_FUNC void func_80451400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80451400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80451404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80451408: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140C8) << 16);
    // 0x8045140C: lwc1        $f4, -0x7B58($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140C8));
    // 0x80451410: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80451414: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80451418: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140CC) << 16);
    // 0x8045141C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80451420: nop

    // 0x80451424: bc1f        L_8045144C
    if (!c1cs) {
        // 0x80451428: nop
    
            goto L_8045144C;
    }
    // 0x80451428: nop

    // 0x8045142C: jal         0x80450B18
    // 0x80451430: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80450B18(rdram, ctx);
        goto after_0;
    // 0x80451430: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80451434: jal         0x804510D4
    // 0x80451438: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804510D4(rdram, ctx);
        goto after_1;
    // 0x80451438: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8045143C: jal         0x80445A34
    // 0x80451440: nop

    func_80445A34(rdram, ctx);
        goto after_2;
    // 0x80451440: nop

    after_2:
    // 0x80451444: b           L_804515DC
    // 0x80451448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804515DC;
    // 0x80451448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045144C:
    // 0x8045144C: lwc1        $f6, -0x7B54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140CC));
    // 0x80451450: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140D0) << 16);
    // 0x80451454: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80451458: nop

    // 0x8045145C: bc1f        L_80451488
    if (!c1cs) {
        // 0x80451460: nop
    
            goto L_80451488;
    }
    // 0x80451460: nop

    // 0x80451464: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80451468: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8045146C: beql        $t6, $zero, L_804515DC
    if (ctx->r14 == 0) {
        // 0x80451470: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804515DC;
    }
    goto skip_0;
    // 0x80451470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80451474: jal         0x80450B18
    // 0x80451478: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_3;
    // 0x80451478: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x8045147C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451480: b           L_804515D8
    // 0x80451484: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_804515D8;
    // 0x80451484: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80451488:
    // 0x80451488: lwc1        $f8, -0x7B50($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140D0));
    // 0x8045148C: lui         $at, 0x4452
    ctx->r1 = S32(0X4452 << 16);
    // 0x80451490: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80451494: nop

    // 0x80451498: bc1fl       L_804514D0
    if (!c1cs) {
        // 0x8045149C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_804514D0;
    }
    goto skip_1;
    // 0x8045149C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_1:
    // 0x804514A0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x804514A4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x804514A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x804514AC: beql        $t7, $at, L_804515DC
    if (ctx->r15 == ctx->r1) {
        // 0x804514B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804515DC;
    }
    goto skip_2;
    // 0x804514B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x804514B4: jal         0x80450B18
    // 0x804514B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_4;
    // 0x804514B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x804514BC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804514C0: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x804514C4: b           L_804515D8
    // 0x804514C8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
        goto L_804515D8;
    // 0x804514C8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x804514CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_804514D0:
    // 0x804514D0: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x804514D4: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x804514D8: nop

    // 0x804514DC: bc1fl       L_80451514
    if (!c1cs) {
        // 0x804514E0: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80451514;
    }
    goto skip_3;
    // 0x804514E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_3:
    // 0x804514E4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x804514E8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x804514EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x804514F0: beql        $t9, $at, L_804515DC
    if (ctx->r25 == ctx->r1) {
        // 0x804514F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804515DC;
    }
    goto skip_4;
    // 0x804514F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x804514F8: jal         0x80450B18
    // 0x804514FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_5;
    // 0x804514FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_5:
    // 0x80451500: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451504: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80451508: b           L_804515D8
    // 0x8045150C: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
        goto L_804515D8;
    // 0x8045150C: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80451510: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80451514:
    // 0x80451514: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80451518: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x8045151C: nop

    // 0x80451520: bc1fl       L_80451558
    if (!c1cs) {
        // 0x80451524: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80451558;
    }
    goto skip_5;
    // 0x80451524: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_5:
    // 0x80451528: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8045152C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80451530: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80451534: beql        $t1, $at, L_804515DC
    if (ctx->r9 == ctx->r1) {
        // 0x80451538: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804515DC;
    }
    goto skip_6;
    // 0x80451538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8045153C: jal         0x80450B18
    // 0x80451540: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_6;
    // 0x80451540: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_6:
    // 0x80451544: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451548: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8045154C: b           L_804515D8
    // 0x80451550: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
        goto L_804515D8;
    // 0x80451550: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80451554: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80451558:
    // 0x80451558: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8045155C: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x80451560: nop

    // 0x80451564: bc1fl       L_8045159C
    if (!c1cs) {
        // 0x80451568: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8045159C;
    }
    goto skip_7;
    // 0x80451568: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_7:
    // 0x8045156C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80451570: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80451574: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80451578: beql        $t3, $at, L_804515DC
    if (ctx->r11 == ctx->r1) {
        // 0x8045157C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804515DC;
    }
    goto skip_8;
    // 0x8045157C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x80451580: jal         0x80450B18
    // 0x80451584: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_7;
    // 0x80451584: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_7:
    // 0x80451588: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8045158C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80451590: b           L_804515D8
    // 0x80451594: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
        goto L_804515D8;
    // 0x80451594: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x80451598: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8045159C:
    // 0x8045159C: nop

    // 0x804515A0: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x804515A4: nop

    // 0x804515A8: bc1fl       L_804515DC
    if (!c1cs) {
        // 0x804515AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804515DC;
    }
    goto skip_9;
    // 0x804515AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x804515B0: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x804515B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804515B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804515BC: beql        $t5, $at, L_804515DC
    if (ctx->r13 == ctx->r1) {
        // 0x804515C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804515DC;
    }
    goto skip_10;
    // 0x804515C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x804515C4: jal         0x80450B18
    // 0x804515C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_8;
    // 0x804515C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_8:
    // 0x804515CC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804515D0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x804515D4: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
L_804515D8:
    // 0x804515D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804515DC:
    // 0x804515DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804515E0: jr          $ra
    // 0x804515E4: nop

    return;
    // 0x804515E4: nop

;}
RECOMP_FUNC void func_800401B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800401B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800401B8: sw          $a0, 0x1F0($a1)
    MEM_W(0X1F0, ctx->r5) = ctx->r4;
    // 0x800401BC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800401C0: sb          $t6, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r14;
    // 0x800401C4: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x800401C8: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x800401CC: swc1        $f0, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f0.u32l;
    // 0x800401D0: jr          $ra
    // 0x800401D4: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800401D4: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_800317AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800317AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800317B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800317B4: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x800317B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800317BC: jal         0x800310A0
    // 0x800317C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x800317C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800317C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800317C8: jal         0x80030FE8
    // 0x800317CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80030FE8(rdram, ctx);
        goto after_1;
    // 0x800317CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800317D0: beq         $v0, $zero, L_800317E0
    if (ctx->r2 == 0) {
        // 0x800317D4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800317E0;
    }
    // 0x800317D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800317D8: jal         0x800310D0
    // 0x800317DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800310D0(rdram, ctx);
        goto after_2;
    // 0x800317DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_800317E0:
    // 0x800317E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800317E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800317E8: jr          $ra
    // 0x800317EC: nop

    return;
    // 0x800317EC: nop

;}
RECOMP_FUNC void func_8006820C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006820C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068210: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068214: jal         0x8006806C
    // 0x80068218: nop

    func_8006806C(rdram, ctx);
        goto after_0;
    // 0x80068218: nop

    after_0:
    // 0x8006821C: bnel        $v0, $zero, L_80068230
    if (ctx->r2 != 0) {
        // 0x80068220: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80068230;
    }
    goto skip_0;
    // 0x80068220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80068224: jal         0x80068190
    // 0x80068228: nop

    func_80068190(rdram, ctx);
        goto after_1;
    // 0x80068228: nop

    after_1:
    // 0x8006822C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80068230:
    // 0x80068230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068234: jr          $ra
    // 0x80068238: nop

    return;
    // 0x80068238: nop

;}
RECOMP_FUNC void func_806F7870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7870: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x806F7874: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x806F7878: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x806F787C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x806F7880: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x806F7884: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x806F7888: lwc1        $f20, 0x5F0($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X5F0);
    // 0x806F788C: jal         0x80066DE4
    // 0x806F7890: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x806F7890: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x806F7894: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x806F7898: jal         0x80066E88
    // 0x806F789C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x806F789C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x806F78A0: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x806F78A4: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B20) << 16);
    // 0x806F78A8: lwc1        $f24, -0x6CD0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B20));
    // 0x806F78AC: lw          $v0, 0x26C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X26C);
    // 0x806F78B0: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x806F78B4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x806F78B8: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x806F78BC: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x806F78C0: sll         $t7, $t7, 7
    ctx->r15 = S32(ctx->r15 << 7);
    // 0x806F78C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806F78C8: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x806F78CC: lui         $a2, 0x8070
    ctx->r6 = S32(RELOC_HI16(694, 0X1908) << 16);
    // 0x806F78D0: lui         $t3, 0x8070
    ctx->r11 = S32(RELOC_HI16(694, 0X1A88) << 16);
    // 0x806F78D4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x806F78D8: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x806F78DC: addiu       $t3, $t3, -0x6D68
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(694, 0X1A88));
    // 0x806F78E0: addiu       $a2, $a2, -0x6EE8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(694, 0X1908));
    // 0x806F78E4: addiu       $t1, $v1, 0x2F0
    ctx->r9 = ADD32(ctx->r3, 0X2F0);
    // 0x806F78E8: addiu       $t2, $v1, 0x330
    ctx->r10 = ADD32(ctx->r3, 0X330);
    // 0x806F78EC: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x806F78F0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_806F78F4:
    // 0x806F78F4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x806F78F8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x806F78FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x806F7900: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_806F7904:
    // 0x806F7904: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x806F7908: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x806F790C: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x806F7910: addiu       $t9, $t8, 0x19
    ctx->r25 = ADD32(ctx->r24, 0X19);
    // 0x806F7914: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x806F7918: addiu       $t5, $t4, 0x7
    ctx->r13 = ADD32(ctx->r12, 0X7);
    // 0x806F791C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x806F7920: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806F7924: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806F7928: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x806F792C: nop

    // 0x806F7930: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x806F7934: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806F7938: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x806F793C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x806F7940: nop

    // 0x806F7944: addiu       $t8, $t7, -0x19
    ctx->r24 = ADD32(ctx->r15, -0X19);
    // 0x806F7948: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x806F794C: lh          $t9, 0x40($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X40);
    // 0x806F7950: lh          $t5, 0x44($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X44);
    // 0x806F7954: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x806F7958: addiu       $t4, $t9, -0x19
    ctx->r12 = ADD32(ctx->r25, -0X19);
    // 0x806F795C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x806F7960: addiu       $t6, $t5, 0x7
    ctx->r14 = ADD32(ctx->r13, 0X7);
    // 0x806F7964: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x806F7968: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806F796C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806F7970: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x806F7974: nop

    // 0x806F7978: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x806F797C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806F7980: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x806F7984: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x806F7988: nop

    // 0x806F798C: addiu       $t9, $t8, 0x19
    ctx->r25 = ADD32(ctx->r24, 0X19);
    // 0x806F7990: beq         $v1, $zero, L_806F79A0
    if (ctx->r3 == 0) {
        // 0x806F7994: sh          $t9, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r25;
            goto L_806F79A0;
    }
    // 0x806F7994: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x806F7998: bnel        $v1, $a3, L_806F7A20
    if (ctx->r3 != ctx->r7) {
        // 0x806F799C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_806F7A20;
    }
    goto skip_0;
    // 0x806F799C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_806F79A0:
    // 0x806F79A0: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x806F79A4: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x806F79A8: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x806F79AC: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x806F79B0: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x806F79B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806F79B8: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x806F79BC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x806F79C0: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x806F79C4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806F79C8: add.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x806F79CC: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x806F79D0: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x806F79D4: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x806F79D8: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x806F79DC: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x806F79E0: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x806F79E4: nop

    // 0x806F79E8: sh          $t6, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r14;
    // 0x806F79EC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x806F79F0: lh          $t9, 0x42($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X42);
    // 0x806F79F4: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x806F79F8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x806F79FC: mul.s       $f6, $f10, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x806F7A00: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806F7A04: add.s       $f4, $f20, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x806F7A08: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x806F7A0C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x806F7A10: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x806F7A14: nop

    // 0x806F7A18: sh          $t5, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r13;
    // 0x806F7A1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_806F7A20:
    // 0x806F7A20: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x806F7A24: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x806F7A28: bne         $v1, $t0, L_806F7904
    if (ctx->r3 != ctx->r8) {
        // 0x806F7A2C: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_806F7904;
    }
    // 0x806F7A2C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x806F7A30: addiu       $a2, $a2, 0x80
    ctx->r6 = ADD32(ctx->r6, 0X80);
    // 0x806F7A34: addiu       $t1, $t1, 0x80
    ctx->r9 = ADD32(ctx->r9, 0X80);
    // 0x806F7A38: bne         $a2, $t3, L_806F78F4
    if (ctx->r6 != ctx->r11) {
        // 0x806F7A3C: addiu       $t2, $t2, 0x80
        ctx->r10 = ADD32(ctx->r10, 0X80);
            goto L_806F78F4;
    }
    // 0x806F7A3C: addiu       $t2, $t2, 0x80
    ctx->r10 = ADD32(ctx->r10, 0X80);
    // 0x806F7A40: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x806F7A44: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x806F7A48: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x806F7A4C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x806F7A50: jr          $ra
    // 0x806F7A54: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x806F7A54: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8042FE28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FE28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042FE2C: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0X3818) << 16);
    // 0x8042FE30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042FE34: addiu       $t6, $t6, 0x18F8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0X3818));
    // 0x8042FE38: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8042FE3C: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x8042FE40: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8042FE44: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8042FE48: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8042FE4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8042FE50: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x8042FE54: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042FE58: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8042FE5C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8042FE60: jalr        $t9
    // 0x8042FE64: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8042FE64: nop

    after_0:
    // 0x8042FE68: jal         0x8042F6B4
    // 0x8042FE6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8042F6B4(rdram, ctx);
        goto after_1;
    // 0x8042FE6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8042FE70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8042FE74: bnel        $v0, $at, L_8042FE88
    if (ctx->r2 != ctx->r1) {
        // 0x8042FE78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042FE88;
    }
    goto skip_0;
    // 0x8042FE78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042FE7C: jal         0x8042FDD4
    // 0x8042FE80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8042FDD4(rdram, ctx);
        goto after_2;
    // 0x8042FE80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8042FE84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042FE88:
    // 0x8042FE88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042FE8C: jr          $ra
    // 0x8042FE90: nop

    return;
    // 0x8042FE90: nop

;}
RECOMP_FUNC void func_8079A550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079A550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079A554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079A558: jal         0x80060FE0
    // 0x8079A55C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80060FE0(rdram, ctx);
        goto after_0;
    // 0x8079A55C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8079A560: jal         0x8005FE48
    // 0x8079A564: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x8079A564: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8079A568: jal         0x8079997C
    // 0x8079A56C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8079997C(rdram, ctx);
        goto after_2;
    // 0x8079A56C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8079A570: jal         0x800447C8
    // 0x8079A574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x8079A574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8079A578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079A57C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079A580: jr          $ra
    // 0x8079A584: nop

    return;
    // 0x8079A584: nop

;}
RECOMP_FUNC void func_80776BD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80776BD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80776BDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80776BE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80776BE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80776BE8: lh          $a2, 0x1F0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X1F0);
    // 0x80776BEC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80776BF0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80776BF4: beq         $a2, $at, L_80776C28
    if (ctx->r6 == ctx->r1) {
        // 0x80776BF8: sll         $a1, $a2, 16
        ctx->r5 = S32(ctx->r6 << 16);
            goto L_80776C28;
    }
    // 0x80776BF8: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x80776BFC: jal         0x80067930
    // 0x80776C00: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80776C00: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_0:
    // 0x80776C04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80776C08: bne         $v0, $at, L_80776C1C
    if (ctx->r2 != ctx->r1) {
        // 0x80776C0C: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80776C1C;
    }
    // 0x80776C0C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80776C10: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80776C14: jal         0x80067878
    // 0x80776C18: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x80776C18: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    after_1:
L_80776C1C:
    // 0x80776C1C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80776C20: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80776C24: sh          $t8, 0x1F0($t9)
    MEM_H(0X1F0, ctx->r25) = ctx->r24;
L_80776C28:
    // 0x80776C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80776C2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80776C30: jr          $ra
    // 0x80776C34: nop

    return;
    // 0x80776C34: nop

;}
RECOMP_FUNC void func_80441650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441650: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80441654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80441658: jal         0x8004700C
    // 0x8044165C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8044165C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80441660: beql        $v0, $zero, L_80441684
    if (ctx->r2 == 0) {
        // 0x80441664: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80441684;
    }
    goto skip_0;
    // 0x80441664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80441668: lw          $t6, 0x138($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X138);
    // 0x8044166C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80441670: bnel        $t6, $at, L_80441684
    if (ctx->r14 != ctx->r1) {
        // 0x80441674: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80441684;
    }
    goto skip_1;
    // 0x80441674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80441678: jal         0x8043F6CC
    // 0x8044167C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8043F6CC(rdram, ctx);
        goto after_1;
    // 0x8044167C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80441680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80441684:
    // 0x80441684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80441688: jr          $ra
    // 0x8044168C: nop

    return;
    // 0x8044168C: nop

;}
RECOMP_FUNC void func_8052F980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052F980: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8052F984: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8052F988: lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XC);
    // 0x8052F98C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8052F990: beq         $v1, $at, L_8052F9B8
    if (ctx->r3 == ctx->r1) {
        // 0x8052F994: addiu       $at, $zero, 0x4002
        ctx->r1 = ADD32(0, 0X4002);
            goto L_8052F9B8;
    }
    // 0x8052F994: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8052F998: beq         $v1, $at, L_8052F9C8
    if (ctx->r3 == ctx->r1) {
        // 0x8052F99C: addiu       $at, $zero, 0x400C
        ctx->r1 = ADD32(0, 0X400C);
            goto L_8052F9C8;
    }
    // 0x8052F99C: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x8052F9A0: beq         $v1, $at, L_8052FA08
    if (ctx->r3 == ctx->r1) {
        // 0x8052F9A4: addiu       $at, $zero, 0x41C0
        ctx->r1 = ADD32(0, 0X41C0);
            goto L_8052FA08;
    }
    // 0x8052F9A4: addiu       $at, $zero, 0x41C0
    ctx->r1 = ADD32(0, 0X41C0);
    // 0x8052F9A8: beql        $v1, $at, L_8052F9F0
    if (ctx->r3 == ctx->r1) {
        // 0x8052F9AC: lw          $t7, 0x180($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X180);
            goto L_8052F9F0;
    }
    goto skip_0;
    // 0x8052F9AC: lw          $t7, 0x180($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X180);
    skip_0:
    // 0x8052F9B0: b           L_8052FA1C
    // 0x8052F9B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8052FA1C;
    // 0x8052F9B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052F9B8:
    // 0x8052F9B8: jal         0x8052EBAC
    // 0x8052F9BC: nop

    func_8052EBAC(rdram, ctx);
        goto after_0;
    // 0x8052F9BC: nop

    after_0:
    // 0x8052F9C0: b           L_8052FA1C
    // 0x8052F9C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8052FA1C;
    // 0x8052F9C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052F9C8:
    // 0x8052F9C8: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x8052F9CC: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8052F9D0: bne         $t6, $at, L_8052FA18
    if (ctx->r14 != ctx->r1) {
        // 0x8052F9D4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8052FA18;
    }
    // 0x8052F9D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052F9D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052F9DC: jal         0x8052E698
    // 0x8052F9E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8052E698(rdram, ctx);
        goto after_1;
    // 0x8052F9E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8052F9E4: b           L_8052FA1C
    // 0x8052F9E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8052FA1C;
    // 0x8052F9E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8052F9EC: lw          $t7, 0x180($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X180);
L_8052F9F0:
    // 0x8052F9F0: bnel        $a0, $t7, L_8052FA1C
    if (ctx->r4 != ctx->r15) {
        // 0x8052F9F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8052FA1C;
    }
    goto skip_1;
    // 0x8052F9F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8052F9F8: jal         0x8052F0C4
    // 0x8052F9FC: nop

    func_8052F0C4(rdram, ctx);
        goto after_2;
    // 0x8052F9FC: nop

    after_2:
    // 0x8052FA00: b           L_8052FA1C
    // 0x8052FA04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8052FA1C;
    // 0x8052FA04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052FA08:
    // 0x8052FA08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052FA0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8052FA10: jal         0x8052E9E8
    // 0x8052FA14: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8052E9E8(rdram, ctx);
        goto after_3;
    // 0x8052FA14: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
L_8052FA18:
    // 0x8052FA18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052FA1C:
    // 0x8052FA1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8052FA20: jr          $ra
    // 0x8052FA24: nop

    return;
    // 0x8052FA24: nop

;}
RECOMP_FUNC void func_8069EA20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069EA20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8069EA24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069EA28: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8069EA2C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8069EA30: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0XA04) << 16);
    // 0x8069EA34: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8069EA38: bne         $t7, $zero, L_8069EAD4
    if (ctx->r15 != 0) {
        // 0x8069EA3C: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_8069EAD4;
    }
    // 0x8069EA3C: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8069EA40: lwc1        $f0, -0x122C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0XA04));
    // 0x8069EA44: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069EA48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8069EA4C: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x8069EA50: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x8069EA54: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8069EA58: jal         0x8069EC9C
    // 0x8069EA5C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8069EC9C(rdram, ctx);
        goto after_0;
    // 0x8069EA5C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8069EA60: jal         0x800653D8
    // 0x8069EA64: nop

    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x8069EA64: nop

    after_1:
    // 0x8069EA68: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8069EA6C: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8069EA70: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8069EA74: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x8069EA78: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X98C) << 16);
    // 0x8069EA7C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8069EA80: lwc1        $f4, -0x12A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X98C));
    // 0x8069EA84: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8069EA88: lui         $t3, 0x806A
    ctx->r11 = S32(RELOC_HI16(577, 0X8F8) << 16);
    // 0x8069EA8C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8069EA90: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8069EA94: lw          $t3, -0x1338($t3)
    ctx->r11 = MEM_W(ctx->r11, (int16_t)RELOC_LO16(577, 0X8F8));
    // 0x8069EA98: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8069EA9C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8069EAA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8069EAA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8069EAA8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8069EAAC: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x8069EAB0: swc1        $f8, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f8.u32l;
    // 0x8069EAB4: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x8069EAB8: sb          $zero, 0x165($a2)
    MEM_B(0X165, ctx->r6) = 0;
    // 0x8069EABC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8069EAC0: jal         0x80067BBC
    // 0x8069EAC4: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8069EAC4: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    after_2:
    // 0x8069EAC8: addiu       $a0, $zero, 0x220
    ctx->r4 = ADD32(0, 0X220);
    // 0x8069EACC: jal         0x80067818
    // 0x8069EAD0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8069EAD0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_8069EAD4:
    // 0x8069EAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069EAD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8069EADC: jr          $ra
    // 0x8069EAE0: nop

    return;
    // 0x8069EAE0: nop

;}
RECOMP_FUNC void func_806723B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806723B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806723BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806723C0: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x806723C4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806723C8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x806723CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806723D0: jal         0x80671D4C
    // 0x806723D4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80671D4C(rdram, ctx);
        goto after_0;
    // 0x806723D4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x806723D8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x806723DC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x806723E0: lw          $t6, 0x1E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1E0);
    // 0x806723E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x806723E8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806723EC: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x806723F0: bne         $at, $zero, L_80672410
    if (ctx->r1 != 0) {
        // 0x806723F4: sw          $t7, 0x1E0($a3)
        MEM_W(0X1E0, ctx->r7) = ctx->r15;
            goto L_80672410;
    }
    // 0x806723F4: sw          $t7, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r15;
    // 0x806723F8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x806723FC: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80672400: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80672404: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80672408: jal         0x80672C80
    // 0x8067240C: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    func_80672C80(rdram, ctx);
        goto after_1;
    // 0x8067240C: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    after_1:
L_80672410:
    // 0x80672410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80672414: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80672418: jr          $ra
    // 0x8067241C: nop

    return;
    // 0x8067241C: nop

;}
RECOMP_FUNC void func_80566290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566290: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80566294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566298: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8056629C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805662A0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x805662A4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x805662A8: jal         0x80566088
    // 0x805662AC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_80566088(rdram, ctx);
        goto after_0;
    // 0x805662AC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x805662B0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x805662B4: jal         0x80566184
    // 0x805662B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80566184(rdram, ctx);
        goto after_1;
    // 0x805662B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x805662BC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x805662C0: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x805662C4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x805662C8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x805662CC: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x805662D0: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x805662D4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x805662D8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x805662DC: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x805662E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805662E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805662E8: jr          $ra
    // 0x805662EC: nop

    return;
    // 0x805662EC: nop

;}
RECOMP_FUNC void func_8042FA9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FA9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042FAA0: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0X3808) << 16);
    // 0x8042FAA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042FAA8: addiu       $t6, $t6, 0x18E8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0X3808));
    // 0x8042FAAC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8042FAB0: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x8042FAB4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8042FAB8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8042FABC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8042FAC0: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x8042FAC4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042FAC8: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8042FACC: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8042FAD0: jalr        $t9
    // 0x8042FAD4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8042FAD4: nop

    after_0:
    // 0x8042FAD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042FADC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042FAE0: jr          $ra
    // 0x8042FAE4: nop

    return;
    // 0x8042FAE4: nop

;}
RECOMP_FUNC void func_804288A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804288A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804288A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804288A8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804288AC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804288B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804288B4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804288B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804288BC: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x804288C0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804288C4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804288C8: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(41, 0X1DB8) << 16);
    // 0x804288CC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804288D0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804288D4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804288D8: lw          $t2, -0x6908($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(41, 0X1DB8));
    // 0x804288DC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804288E0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804288E4: jal         0x804279C8
    // 0x804288E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804279C8(rdram, ctx);
        goto after_0;
    // 0x804288E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804288EC: jal         0x80427A24
    // 0x804288F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80427A24(rdram, ctx);
        goto after_1;
    // 0x804288F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804288F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804288F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804288FC: jr          $ra
    // 0x80428900: nop

    return;
    // 0x80428900: nop

;}
RECOMP_FUNC void func_8002BE60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BE60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002BE64: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002BE68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BE6C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8002BE70: jal         0x8005D1C8
    // 0x8002BE74: lw          $a0, -0x7890($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7890);
    func_8005D1C8(rdram, ctx);
        goto after_0;
    // 0x8002BE74: lw          $a0, -0x7890($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7890);
    after_0:
    // 0x8002BE78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BE7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002BE80: jr          $ra
    // 0x8002BE84: nop

    return;
    // 0x8002BE84: nop

;}
RECOMP_FUNC void func_80562BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80562BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80562BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80562BCC: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80562BD0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80562BD4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80562BD8: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    // 0x80562BDC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80562BE0: addiu       $a1, $a2, 0x13C
    ctx->r5 = ADD32(ctx->r6, 0X13C);
    // 0x80562BE4: bc1f        L_80562BFC
    if (!c1cs) {
        // 0x80562BE8: nop
    
            goto L_80562BFC;
    }
    // 0x80562BE8: nop

    // 0x80562BEC: jal         0x8005965C
    // 0x80562BF0: addiu       $a1, $a2, 0x13C
    ctx->r5 = ADD32(ctx->r6, 0X13C);
    func_8005965C(rdram, ctx);
        goto after_0;
    // 0x80562BF0: addiu       $a1, $a2, 0x13C
    ctx->r5 = ADD32(ctx->r6, 0X13C);
    after_0:
    // 0x80562BF4: b           L_80562C08
    // 0x80562BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80562C08;
    // 0x80562BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80562BFC:
    // 0x80562BFC: jal         0x800597A4
    // 0x80562C00: addiu       $a0, $a2, 0x84
    ctx->r4 = ADD32(ctx->r6, 0X84);
    func_800597A4(rdram, ctx);
        goto after_1;
    // 0x80562C00: addiu       $a0, $a2, 0x84
    ctx->r4 = ADD32(ctx->r6, 0X84);
    after_1:
    // 0x80562C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80562C08:
    // 0x80562C08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80562C0C: jr          $ra
    // 0x80562C10: nop

    return;
    // 0x80562C10: nop

;}
RECOMP_FUNC void func_805A7440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A7440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A7444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A7448: jal         0x8005780C
    // 0x805A744C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    func_8005780C(rdram, ctx);
        goto after_0;
    // 0x805A744C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x805A7450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A7454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A7458: jr          $ra
    // 0x805A745C: nop

    return;
    // 0x805A745C: nop

;}
RECOMP_FUNC void func_806A99B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A99B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806A99B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A99BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806A99C0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806A99C4: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x806A99C8: jal         0x80067BBC
    // 0x806A99CC: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806A99CC: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x806A99D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806A99D4: jal         0x80067818
    // 0x806A99D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x806A99D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806A99DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806A99E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806A99E4: jr          $ra
    // 0x806A99E8: nop

    return;
    // 0x806A99E8: nop

;}
RECOMP_FUNC void func_80473520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80473520: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80473524: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80473528: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8047352C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80473530: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80473534: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80473538: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8047353C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80473540: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80473544: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80473548: lwc1        $f16, 0xC4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8047354C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80473550: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x80473554: bc1fl       L_804736B0
    if (!c1cs) {
        // 0x80473558: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804736B0;
    }
    goto skip_0;
    // 0x80473558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8047355C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80473560: jal         0x8004D1F0
    // 0x80473564: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x80473564: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x80473568: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8047356C: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x80473570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80473574: jal         0x8004D698
    // 0x80473578: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x80473578: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8047357C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80473580: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80473584: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80473588: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8047358C: lbu         $t0, 0x5C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X5C);
    // 0x80473590: beql        $t0, $zero, L_804736B0
    if (ctx->r8 == 0) {
        // 0x80473594: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804736B0;
    }
    goto skip_1;
    // 0x80473594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80473598: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    // 0x8047359C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804735A0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x804735A4: lw          $t3, 0x40($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X40);
    // 0x804735A8: lhu         $a0, 0x48($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X48);
    // 0x804735AC: jal         0x8004A97C
    // 0x804735B0: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    func_8004A97C(rdram, ctx);
        goto after_2;
    // 0x804735B0: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x804735B4: lw          $t4, 0x138($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X138);
    // 0x804735B8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804735BC: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x804735C0: beq         $t4, $zero, L_804735D4
    if (ctx->r12 == 0) {
        // 0x804735C4: lui         $at, 0x8047
        ctx->r1 = S32(RELOC_HI16(161, 0X1480) << 16);
            goto L_804735D4;
    }
    // 0x804735C4: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(161, 0X1480) << 16);
    // 0x804735C8: lwc1        $f14, 0x50($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X50);
    // 0x804735CC: b           L_804735DC
    // 0x804735D0: add.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f0.fl;
        goto L_804735DC;
    // 0x804735D0: add.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f0.fl;
L_804735D4:
    // 0x804735D4: lwc1        $f14, 0x50($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X50);
    // 0x804735D8: sub.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f0.fl;
L_804735DC:
    // 0x804735DC: lwc1        $f0, 0x4610($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(161, 0X1480));
    // 0x804735E0: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(161, 0X1484) << 16);
    // 0x804735E4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804735E8: nop

    // 0x804735EC: bc1t        L_80473608
    if (c1cs) {
        // 0x804735F0: nop
    
            goto L_80473608;
    }
    // 0x804735F0: nop

    // 0x804735F4: lwc1        $f6, 0x4614($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(161, 0X1484));
    // 0x804735F8: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x804735FC: nop

    // 0x80473600: bc1fl       L_80473614
    if (!c1cs) {
        // 0x80473604: sub.s       $f8, $f14, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f2.fl;
            goto L_80473614;
    }
    goto skip_2;
    // 0x80473604: sub.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f2.fl;
    skip_2:
L_80473608:
    // 0x80473608: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8047360C: nop

    // 0x80473610: sub.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f2.fl;
L_80473614:
    // 0x80473614: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80473618: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8047361C: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x80473620: mul.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80473624: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80473628: jal         0x80066E88
    // 0x8047362C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x8047362C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80473630: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80473634: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x80473638: lw          $t5, 0x68($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X68);
    // 0x8047363C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80473640: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80473644: beql        $t5, $zero, L_80473678
    if (ctx->r13 == 0) {
        // 0x80473648: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80473678;
    }
    goto skip_3;
    // 0x80473648: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_3:
    // 0x8047364C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80473650: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(161, 0X1488) << 16);
    // 0x80473654: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80473658: nop

    // 0x8047365C: bc1fl       L_8047369C
    if (!c1cs) {
        // 0x80473660: swc1        $f16, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
            goto L_8047369C;
    }
    goto skip_4;
    // 0x80473660: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    skip_4:
    // 0x80473664: lwc1        $f6, 0x4618($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(161, 0X1488));
    // 0x80473668: mul.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8047366C: b           L_8047369C
    // 0x80473670: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
        goto L_8047369C;
    // 0x80473670: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x80473674: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80473678:
    // 0x80473678: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(161, 0X148C) << 16);
    // 0x8047367C: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80473680: nop

    // 0x80473684: bc1fl       L_8047369C
    if (!c1cs) {
        // 0x80473688: swc1        $f16, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
            goto L_8047369C;
    }
    goto skip_5;
    // 0x80473688: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    skip_5:
    // 0x8047368C: lwc1        $f10, 0x461C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(161, 0X148C));
    // 0x80473690: mul.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80473694: nop

    // 0x80473698: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
L_8047369C:
    // 0x8047369C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x804736A0: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x804736A4: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x804736A8: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x804736AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804736B0:
    // 0x804736B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804736B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804736B8: jr          $ra
    // 0x804736BC: nop

    return;
    // 0x804736BC: nop

;}
RECOMP_FUNC void func_805A1DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1DE4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805A1DE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A1DEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A1DF0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A1DF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A1DF8: jal         0x8004700C
    // 0x805A1DFC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805A1DFC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x805A1E00: beq         $v0, $zero, L_805A1F80
    if (ctx->r2 == 0) {
        // 0x805A1E04: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_805A1F80;
    }
    // 0x805A1E04: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x805A1E08: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805A1E0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A1E10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A1E14: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x805A1E18: jal         0x80048F84
    // 0x805A1E1C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x805A1E1C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x805A1E20: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x805A1E24: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(411, 0X1D58) << 16);
    // 0x805A1E28: lwc1        $f8, 0x30C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(411, 0X1D58));
    // 0x805A1E2C: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805A1E30: lwc1        $f6, 0x84($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X84);
    // 0x805A1E34: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x805A1E38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805A1E3C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805A1E40: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x805A1E44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A1E48: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x805A1E4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805A1E50: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805A1E54: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x805A1E58: nop

    // 0x805A1E5C: bc1fl       L_805A1EB0
    if (!c1cs) {
        // 0x805A1E60: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_805A1EB0;
    }
    goto skip_0;
    // 0x805A1E60: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x805A1E64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A1E68: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x805A1E6C: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x805A1E70: nop

    // 0x805A1E74: bc1fl       L_805A1EB0
    if (!c1cs) {
        // 0x805A1E78: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_805A1EB0;
    }
    goto skip_1;
    // 0x805A1E78: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x805A1E7C: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x805A1E80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A1E84: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x805A1E88: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x805A1E8C: nop

    // 0x805A1E90: bc1fl       L_805A1EB0
    if (!c1cs) {
        // 0x805A1E94: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_805A1EB0;
    }
    goto skip_2;
    // 0x805A1E94: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_2:
    // 0x805A1E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A1E9C: jal         0x805A2B28
    // 0x805A1EA0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805A2B28(rdram, ctx);
        goto after_2;
    // 0x805A1EA0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x805A1EA4: b           L_805A1F84
    // 0x805A1EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A1F84;
    // 0x805A1EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A1EAC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_805A1EB0:
    // 0x805A1EB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A1EB4: beq         $v0, $zero, L_805A1EC4
    if (ctx->r2 == 0) {
        // 0x805A1EB8: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_805A1EC4;
    }
    // 0x805A1EB8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x805A1EBC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x805A1EC0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_805A1EC4:
    // 0x805A1EC4: bne         $v0, $at, L_805A1EFC
    if (ctx->r2 != ctx->r1) {
        // 0x805A1EC8: lui         $at, 0xC040
        ctx->r1 = S32(0XC040 << 16);
            goto L_805A1EFC;
    }
    // 0x805A1EC8: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x805A1ECC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A1ED0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x805A1ED4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805A1ED8: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(411, 0X1DE4) << 16);
    // 0x805A1EDC: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x805A1EE0: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x805A1EE4: lwc1        $f10, 0x3154($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(411, 0X1DE4));
    // 0x805A1EE8: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
    // 0x805A1EEC: sw          $zero, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = 0;
    // 0x805A1EF0: sw          $zero, 0x134($s0)
    MEM_W(0X134, ctx->r16) = 0;
    // 0x805A1EF4: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x805A1EF8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_805A1EFC:
    // 0x805A1EFC: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x805A1F00: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x805A1F04: nop

    // 0x805A1F08: bc1f        L_805A1F60
    if (!c1cs) {
        // 0x805A1F0C: nop
    
            goto L_805A1F60;
    }
    // 0x805A1F0C: nop

    // 0x805A1F10: lwc1        $f18, 0x2C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x805A1F14: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805A1F18: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x805A1F1C: nop

    // 0x805A1F20: bc1f        L_805A1F60
    if (!c1cs) {
        // 0x805A1F24: nop
    
            goto L_805A1F60;
    }
    // 0x805A1F24: nop

    // 0x805A1F28: bne         $v0, $zero, L_805A1F60
    if (ctx->r2 != 0) {
        // 0x805A1F2C: lui         $at, 0x805A
        ctx->r1 = S32(RELOC_HI16(411, 0X1DE8) << 16);
            goto L_805A1F60;
    }
    // 0x805A1F2C: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(411, 0X1DE8) << 16);
    // 0x805A1F30: sw          $zero, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = 0;
    // 0x805A1F34: sw          $zero, 0x134($s0)
    MEM_W(0X134, ctx->r16) = 0;
    // 0x805A1F38: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x805A1F3C: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x805A1F40: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x805A1F44: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x805A1F48: lwc1        $f8, 0x3158($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(411, 0X1DE8));
    // 0x805A1F4C: lwc1        $f6, 0x2C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x805A1F50: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // 0x805A1F54: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x805A1F58: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    // 0x805A1F5C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_805A1F60:
    // 0x805A1F60: bnel        $v0, $zero, L_805A1F84
    if (ctx->r2 != 0) {
        // 0x805A1F64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A1F84;
    }
    goto skip_3;
    // 0x805A1F64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x805A1F68: lh          $t8, 0x144($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X144);
    // 0x805A1F6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805A1F70: beql        $t8, $at, L_805A1F84
    if (ctx->r24 == ctx->r1) {
        // 0x805A1F74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A1F84;
    }
    goto skip_4;
    // 0x805A1F74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x805A1F78: jal         0x805A1BA8
    // 0x805A1F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A1BA8(rdram, ctx);
        goto after_3;
    // 0x805A1F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_805A1F80:
    // 0x805A1F80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A1F84:
    // 0x805A1F84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A1F88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805A1F8C: jr          $ra
    // 0x805A1F90: nop

    return;
    // 0x805A1F90: nop

;}
RECOMP_FUNC void func_80048C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048C2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048C34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80048C38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80048C3C: jal         0x80048BD8
    // 0x80048C40: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80048BD8(rdram, ctx);
        goto after_0;
    // 0x80048C40: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80048C44: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80048C48: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80048C4C: jal         0x80048C18
    // 0x80048C50: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80048C18(rdram, ctx);
        goto after_1;
    // 0x80048C50: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80048C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048C5C: jr          $ra
    // 0x80048C60: nop

    return;
    // 0x80048C60: nop

;}
RECOMP_FUNC void func_800619BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800619BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800619C0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800619C4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800619C8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800619CC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800619D0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800619D4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800619D8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800619DC: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x800619E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800619E4: sw          $t6, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r14;
    // 0x800619E8: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
    // 0x800619EC: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x800619F0: sh          $t7, 0x78($a0)
    MEM_H(0X78, ctx->r4) = ctx->r15;
    // 0x800619F4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800619F8: lh          $t9, 0x56($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X56);
    // 0x800619FC: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x80061A00: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80061A04: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80061A08: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80061A0C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80061A10: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x80061A14: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061A18: lh          $t1, 0x58($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X58);
    // 0x80061A1C: lw          $t0, 0x70($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X70);
    // 0x80061A20: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80061A24: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80061A28: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80061A2C: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80061A30: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x80061A34: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061A38: lh          $t3, 0x5A($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X5A);
    // 0x80061A3C: lw          $t2, 0x70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X70);
    // 0x80061A40: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80061A44: lwc1        $f8, 0x8($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80061A48: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80061A4C: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80061A50: swc1        $f16, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f16.u32l;
    // 0x80061A54: jal         0x80060030
    // 0x80061A58: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    func_80060030(rdram, ctx);
        goto after_0;
    // 0x80061A58: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    after_0:
    // 0x80061A5C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80061A60: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80061A64: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80061A68: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061A6C: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x80061A70: lh          $t5, 0x52($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X52);
    // 0x80061A74: lw          $t4, 0x70($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X70);
    // 0x80061A78: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80061A7C: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80061A80: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80061A84: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80061A88: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    // 0x80061A8C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061A90: lwc1        $f10, 0x8C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X8C);
    // 0x80061A94: lh          $t7, 0x54($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X54);
    // 0x80061A98: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x80061A9C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80061AA0: lwc1        $f18, 0x8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80061AA4: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80061AA8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80061AAC: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80061AB0: beq         $a0, $zero, L_80061C24
    if (ctx->r4 == 0) {
        // 0x80061AB4: swc1        $f8, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
            goto L_80061C24;
    }
    // 0x80061AB4: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80061AB8: lh          $t9, 0x78($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X78);
    // 0x80061ABC: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x80061AC0: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x80061AC4: beql        $t9, $zero, L_80061C28
    if (ctx->r25 == 0) {
        // 0x80061AC8: lw          $t5, 0x4($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X4);
            goto L_80061C28;
    }
    goto skip_0;
    // 0x80061AC8: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x80061ACC: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80061AD0: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x80061AD4: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
L_80061AD8:
    // 0x80061AD8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80061ADC: beql        $v1, $zero, L_80061C10
    if (ctx->r3 == 0) {
        // 0x80061AE0: addiu       $t3, $v0, 0x4
        ctx->r11 = ADD32(ctx->r2, 0X4);
            goto L_80061C10;
    }
    goto skip_1;
    // 0x80061AE0: addiu       $t3, $v0, 0x4
    ctx->r11 = ADD32(ctx->r2, 0X4);
    skip_1:
    // 0x80061AE4: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80061AE8: beql        $t0, $v1, L_80061BFC
    if (ctx->r8 == ctx->r3) {
        // 0x80061AEC: lh          $t1, 0x78($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X78);
            goto L_80061BFC;
    }
    goto skip_2;
    // 0x80061AEC: lh          $t1, 0x78($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X78);
    skip_2:
    // 0x80061AF0: sw          $v1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r3;
    // 0x80061AF4: lwc1        $f16, 0xC4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC4);
    // 0x80061AF8: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80061AFC: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80061B00: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80061B04: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80061B08: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
    // 0x80061B0C: lwc1        $f6, 0xC8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC8);
    // 0x80061B10: lwc1        $f16, 0x5C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80061B14: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80061B18: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80061B1C: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80061B20: swc1        $f8, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f8.u32l;
    // 0x80061B24: lwc1        $f6, 0x60($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X60);
    // 0x80061B28: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80061B2C: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80061B30: c.lt.s      $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f24.fl < ctx->f16.fl;
    // 0x80061B34: nop

    // 0x80061B38: bc1fl       L_80061BFC
    if (!c1cs) {
        // 0x80061B3C: lh          $t1, 0x78($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X78);
            goto L_80061BFC;
    }
    goto skip_3;
    // 0x80061B3C: lh          $t1, 0x78($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X78);
    skip_3:
    // 0x80061B40: lw          $t1, 0x174($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X174);
    // 0x80061B44: sw          $t1, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r9;
    // 0x80061B48: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80061B4C: andi        $t4, $t3, 0xF00
    ctx->r12 = ctx->r11 & 0XF00;
    // 0x80061B50: bnel        $t4, $zero, L_80061BFC
    if (ctx->r12 != 0) {
        // 0x80061B54: lh          $t1, 0x78($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X78);
            goto L_80061BFC;
    }
    goto skip_4;
    // 0x80061B54: lh          $t1, 0x78($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X78);
    skip_4:
    // 0x80061B58: lbu         $t5, 0x5($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X5);
    // 0x80061B5C: beq         $t5, $zero, L_80061B70
    if (ctx->r13 == 0) {
        // 0x80061B60: nop
    
            goto L_80061B70;
    }
    // 0x80061B60: nop

    // 0x80061B64: lbu         $t6, 0x10($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X10);
    // 0x80061B68: beql        $t6, $zero, L_80061BFC
    if (ctx->r14 == 0) {
        // 0x80061B6C: lh          $t1, 0x78($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X78);
            goto L_80061BFC;
    }
    goto skip_5;
    // 0x80061B6C: lh          $t1, 0x78($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X78);
    skip_5:
L_80061B70:
    // 0x80061B70: jal         0x800603E8
    // 0x80061B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800603E8(rdram, ctx);
        goto after_1;
    // 0x80061B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80061B78: beql        $v0, $zero, L_80061BFC
    if (ctx->r2 == 0) {
        // 0x80061B7C: lh          $t1, 0x78($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X78);
            goto L_80061BFC;
    }
    goto skip_6;
    // 0x80061B7C: lh          $t1, 0x78($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X78);
    skip_6:
    // 0x80061B80: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80061B84: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80061B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061B8C: lwc1        $f18, 0x84($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80061B90: lwc1        $f10, 0x88($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80061B94: lwc1        $f6, 0x84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X84);
    // 0x80061B98: lwc1        $f4, 0x88($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X88);
    // 0x80061B9C: sub.s       $f20, $f18, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80061BA0: jal         0x80060ED0
    // 0x80061BA4: sub.s       $f22, $f10, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f4.fl;
    func_80060ED0(rdram, ctx);
        goto after_2;
    // 0x80061BA4: sub.s       $f22, $f10, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f4.fl;
    after_2:
    // 0x80061BA8: lw          $t7, 0x3C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X3C);
    // 0x80061BAC: swc1        $f24, 0x120($t7)
    MEM_W(0X120, ctx->r15) = ctx->f24.u32l;
    // 0x80061BB0: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x80061BB4: sb          $s2, 0x17C($t8)
    MEM_B(0X17C, ctx->r24) = ctx->r18;
    // 0x80061BB8: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80061BBC: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80061BC0: lw          $t9, 0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X3C);
    // 0x80061BC4: mul.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80061BC8: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x80061BCC: mul.s       $f10, $f22, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x80061BD0: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80061BD4: swc1        $f4, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f4.u32l;
    // 0x80061BD8: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80061BDC: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80061BE0: lw          $t0, 0x3C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X3C);
    // 0x80061BE4: mul.s       $f18, $f8, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80061BE8: nop

    // 0x80061BEC: mul.s       $f16, $f22, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x80061BF0: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80061BF4: swc1        $f10, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f10.u32l;
    // 0x80061BF8: lh          $t1, 0x78($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X78);
L_80061BFC:
    // 0x80061BFC: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x80061C00: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x80061C04: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80061C08: sh          $t2, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r10;
    // 0x80061C0C: addiu       $t3, $v0, 0x4
    ctx->r11 = ADD32(ctx->r2, 0X4);
L_80061C10:
    // 0x80061C10: beq         $a0, $zero, L_80061C24
    if (ctx->r4 == 0) {
        // 0x80061C14: sw          $t3, 0x74($s0)
        MEM_W(0X74, ctx->r16) = ctx->r11;
            goto L_80061C24;
    }
    // 0x80061C14: sw          $t3, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r11;
    // 0x80061C18: lh          $t4, 0x78($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X78);
    // 0x80061C1C: bnel        $t4, $zero, L_80061AD8
    if (ctx->r12 != 0) {
        // 0x80061C20: lw          $v0, 0x74($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X74);
            goto L_80061AD8;
    }
    goto skip_7;
    // 0x80061C20: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    skip_7:
L_80061C24:
    // 0x80061C24: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
L_80061C28:
    // 0x80061C28: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80061C2C: lh          $t6, 0x184($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X184);
    // 0x80061C30: beql        $t6, $zero, L_80061C58
    if (ctx->r14 == 0) {
        // 0x80061C34: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80061C58;
    }
    goto skip_8;
    // 0x80061C34: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_8:
    // 0x80061C38: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80061C3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80061C40: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x80061C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061C48: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80061C4C: jalr        $t9
    // 0x80061C50: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80061C50: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x80061C54: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80061C58:
    // 0x80061C58: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80061C5C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80061C60: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80061C64: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80061C68: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80061C6C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80061C70: jr          $ra
    // 0x80061C74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80061C74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_804619C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804619C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804619C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804619CC: jal         0x80460F4C
    // 0x804619D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80460F4C(rdram, ctx);
        goto after_0;
    // 0x804619D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804619D4: jal         0x80045BD8
    // 0x804619D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x804619D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804619DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804619E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804619E4: jr          $ra
    // 0x804619E8: nop

    return;
    // 0x804619E8: nop

;}
RECOMP_FUNC void func_806E02D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E02D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E02D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806E02DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E02E0: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x806E02E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806E02E8: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806E02EC: lui         $at, 0x4108
    ctx->r1 = S32(0X4108 << 16);
    // 0x806E02F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806E02F4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806E02F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E02FC: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x806E0300: jal         0x806E0250
    // 0x806E0304: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    func_806E0250(rdram, ctx);
        goto after_0;
    // 0x806E0304: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    after_0:
    // 0x806E0308: bne         $v0, $zero, L_806E0320
    if (ctx->r2 != 0) {
        // 0x806E030C: nop
    
            goto L_806E0320;
    }
    // 0x806E030C: nop

    // 0x806E0310: jal         0x800445A4
    // 0x806E0314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806E0314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806E0318: b           L_806E0388
    // 0x806E031C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806E0388;
    // 0x806E031C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806E0320:
    // 0x806E0320: jal         0x806E0294
    // 0x806E0324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E0294(rdram, ctx);
        goto after_2;
    // 0x806E0324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806E0328: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x806E032C: sh          $t6, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r14;
    // 0x806E0330: jal         0x806E0294
    // 0x806E0334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E0294(rdram, ctx);
        goto after_3;
    // 0x806E0334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806E0338: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x806E033C: lui         $t7, 0x806E
    ctx->r15 = S32(RELOC_HI16(643, 0XE7C) << 16);
    // 0x806E0340: lui         $t8, 0x806E
    ctx->r24 = S32(RELOC_HI16(643, 0X250) << 16);
    // 0x806E0344: addiu       $t7, $t7, 0x2AC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(643, 0XE7C));
    // 0x806E0348: addiu       $t8, $t8, -0x980
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(643, 0X250));
    // 0x806E034C: lui         $t9, 0x806E
    ctx->r25 = S32(RELOC_HI16(643, 0X1144) << 16);
    // 0x806E0350: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    // 0x806E0354: sw          $t8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r24;
    // 0x806E0358: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806E035C: addiu       $t9, $t9, 0x574
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(643, 0X1144));
    // 0x806E0360: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x806E0364: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806E0368: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x806E036C: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x806E0370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E0374: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E0378: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806E037C: jal         0x806E0398
    // 0x806E0380: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806E0398(rdram, ctx);
        goto after_4;
    // 0x806E0380: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x806E0384: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806E0388:
    // 0x806E0388: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E038C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E0390: jr          $ra
    // 0x806E0394: nop

    return;
    // 0x806E0394: nop

;}
RECOMP_FUNC void func_806AED30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AED30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806AED34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AED38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AED3C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AED40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806AED44: jal         0x806AEBDC
    // 0x806AED48: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_806AEBDC(rdram, ctx);
        goto after_0;
    // 0x806AED48: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x806AED4C: bnel        $v0, $zero, L_806AEDF0
    if (ctx->r2 != 0) {
        // 0x806AED50: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806AEDF0;
    }
    goto skip_0;
    // 0x806AED50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806AED54: jal         0x806AE458
    // 0x806AED58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AE458(rdram, ctx);
        goto after_1;
    // 0x806AED58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806AED5C: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x806AED60: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x806AED64: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x806AED68: bnel        $v1, $at, L_806AEDA0
    if (ctx->r3 != ctx->r1) {
        // 0x806AED6C: slti        $at, $v1, 0xD2
        ctx->r1 = SIGNED(ctx->r3) < 0XD2 ? 1 : 0;
            goto L_806AEDA0;
    }
    goto skip_1;
    // 0x806AED6C: slti        $at, $v1, 0xD2
    ctx->r1 = SIGNED(ctx->r3) < 0XD2 ? 1 : 0;
    skip_1:
    // 0x806AED70: lw          $t9, -0x7288($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7288);
    // 0x806AED74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AED78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AED7C: jalr        $t9
    // 0x806AED80: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x806AED80: nop

    after_2:
    // 0x806AED84: jal         0x800677F8
    // 0x806AED88: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800677F8(rdram, ctx);
        goto after_3;
    // 0x806AED88: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_3:
    // 0x806AED8C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806AED90: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x806AED94: sb          $t7, 0x7EA5($at)
    MEM_B(0X7EA5, ctx->r1) = ctx->r15;
    // 0x806AED98: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x806AED9C: slti        $at, $v1, 0xD2
    ctx->r1 = SIGNED(ctx->r3) < 0XD2 ? 1 : 0;
L_806AEDA0:
    // 0x806AEDA0: bne         $at, $zero, L_806AEDE8
    if (ctx->r1 != 0) {
        // 0x806AEDA4: addiu       $t1, $v1, 0x1
        ctx->r9 = ADD32(ctx->r3, 0X1);
            goto L_806AEDE8;
    }
    // 0x806AEDA4: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x806AEDA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AEDAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AEDB0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806AEDB4: jal         0x806AF64C
    // 0x806AEDB8: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806AF64C(rdram, ctx);
        goto after_4;
    // 0x806AEDB8: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806AEDBC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x806AEDC0: lw          $a0, 0x28($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X28);
    // 0x806AEDC4: beql        $a0, $zero, L_806AEDF0
    if (ctx->r4 == 0) {
        // 0x806AEDC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806AEDF0;
    }
    goto skip_2;
    // 0x806AEDC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806AEDCC: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x806AEDD0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x806AEDD4: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x806AEDD8: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // 0x806AEDDC: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x806AEDE0: b           L_806AEDEC
    // 0x806AEDE4: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
        goto L_806AEDEC;
    // 0x806AEDE4: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_806AEDE8:
    // 0x806AEDE8: sw          $t1, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r9;
L_806AEDEC:
    // 0x806AEDEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806AEDF0:
    // 0x806AEDF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AEDF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806AEDF8: jr          $ra
    // 0x806AEDFC: nop

    return;
    // 0x806AEDFC: nop

;}
RECOMP_FUNC void func_80527C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527C60: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80527C64: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80527C68: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x80527C6C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80527C70: jal         0x80067BBC
    // 0x80527C74: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80527C74: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80527C78: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    // 0x80527C7C: jal         0x80067818
    // 0x80527C80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80527C80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80527C84: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80527C88: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X61A4) << 16);
    // 0x80527C8C: lwc1        $f4, -0x3F5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X61A4));
    // 0x80527C90: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80527C94: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(327, 0X5BB0) << 16);
    // 0x80527C98: addiu       $v0, $v0, -0x4550
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(327, 0X5BB0));
    // 0x80527C9C: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(327, 0X1DD8) << 16);
    // 0x80527CA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80527CA4: addiu       $t7, $t7, 0x7CD8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(327, 0X1DD8));
    // 0x80527CA8: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x80527CAC: sw          $t6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r14;
    // 0x80527CB0: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80527CB4: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80527CB8: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    // 0x80527CBC: sw          $t7, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r15;
    // 0x80527CC0: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
    // 0x80527CC4: swc1        $f6, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f6.u32l;
    // 0x80527CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80527CCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527CD0: jr          $ra
    // 0x80527CD4: nop

    return;
    // 0x80527CD4: nop

;}
RECOMP_FUNC void func_80532B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532B10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80532B14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80532B18: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80532B1C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80532B20: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80532B24: beq         $a1, $at, L_80532B40
    if (ctx->r5 == ctx->r1) {
        // 0x80532B28: addiu       $a0, $zero, 0x62
        ctx->r4 = ADD32(0, 0X62);
            goto L_80532B40;
    }
    // 0x80532B28: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    // 0x80532B2C: jal         0x80067878
    // 0x80532B30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x80532B30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80532B34: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80532B38: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80532B3C: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_80532B40:
    // 0x80532B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80532B44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80532B48: jr          $ra
    // 0x80532B4C: nop

    return;
    // 0x80532B4C: nop

;}
RECOMP_FUNC void func_807B8974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8974: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B8978: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B897C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x807B8980: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x807B8984: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807B8988: jal         0x807B8298
    // 0x807B898C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_807B8298(rdram, ctx);
        goto after_0;
    // 0x807B898C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x807B8990: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x807B8994: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x807B8998: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B899C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807B89A0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807B89A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807B89A8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x807B89AC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807B89B0: lui         $a0, 0x807C
    ctx->r4 = S32(RELOC_HI16(886, 0X1C10) << 16);
    // 0x807B89B4: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x807B89B8: lui         $a2, 0x4188
    ctx->r6 = S32(0X4188 << 16);
    // 0x807B89BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807B89C0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x807B89C4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x807B89C8: ori         $a2, $a2, 0x51EB
    ctx->r6 = ctx->r6 | 0X51EB;
    // 0x807B89CC: lhu         $a0, -0x6180($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(886, 0X1C10));
    // 0x807B89D0: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    // 0x807B89D4: jal         0x8005CEBC
    // 0x807B89D8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_1;
    // 0x807B89D8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x807B89DC: lw          $t2, 0x3C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X3C);
    // 0x807B89E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B89E4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x807B89E8: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x807B89EC: jal         0x807B8314
    // 0x807B89F0: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    func_807B8314(rdram, ctx);
        goto after_2;
    // 0x807B89F0: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    after_2:
    // 0x807B89F4: lw          $t5, 0x44($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X44);
    // 0x807B89F8: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x807B89FC: lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10);
    // 0x807B8A00: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x807B8A04: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x807B8A08: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x807B8A0C: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x807B8A10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807B8A14: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x807B8A18: lui         $a0, 0x807C
    ctx->r4 = S32(RELOC_HI16(886, 0X1C10) << 16);
    // 0x807B8A1C: lui         $a1, 0x807C
    ctx->r5 = S32(RELOC_HI16(886, 0X1C84) << 16);
    // 0x807B8A20: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x807B8A24: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x807B8A28: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x807B8A2C: lui         $a2, 0x4188
    ctx->r6 = S32(0X4188 << 16);
    // 0x807B8A30: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x807B8A34: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x807B8A38: ori         $a2, $a2, 0x51EB
    ctx->r6 = ctx->r6 | 0X51EB;
    // 0x807B8A3C: lhu         $a0, -0x6180($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(886, 0X1C10));
    // 0x807B8A40: lw          $a1, -0x610C($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(886, 0X1C84));
    // 0x807B8A44: lui         $a3, 0xC240
    ctx->r7 = S32(0XC240 << 16);
    // 0x807B8A48: jal         0x8005CEBC
    // 0x807B8A4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_3;
    // 0x807B8A4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x807B8A50: lw          $t3, 0x3C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X3C);
    // 0x807B8A54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B8A58: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x807B8A5C: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x807B8A60: jal         0x807B8314
    // 0x807B8A64: sw          $v0, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r2;
    func_807B8314(rdram, ctx);
        goto after_4;
    // 0x807B8A64: sw          $v0, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r2;
    after_4:
    // 0x807B8A68: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    // 0x807B8A6C: lw          $t7, 0x3C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X3C);
    // 0x807B8A70: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x807B8A74: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x807B8A78: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x807B8A7C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x807B8A80: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x807B8A84: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x807B8A88: lui         $a0, 0x807C
    ctx->r4 = S32(RELOC_HI16(886, 0X1C10) << 16);
    // 0x807B8A8C: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x807B8A90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807B8A94: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x807B8A98: lhu         $a0, -0x6180($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(886, 0X1C10));
    // 0x807B8A9C: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x807B8AA0: lui         $a2, 0x4180
    ctx->r6 = S32(0X4180 << 16);
    // 0x807B8AA4: lui         $a3, 0xC1C0
    ctx->r7 = S32(0XC1C0 << 16);
    // 0x807B8AA8: jal         0x8005CEBC
    // 0x807B8AAC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_5;
    // 0x807B8AAC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x807B8AB0: lw          $t2, 0x3C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X3C);
    // 0x807B8AB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B8AB8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x807B8ABC: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x807B8AC0: jal         0x807B8314
    // 0x807B8AC4: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    func_807B8314(rdram, ctx);
        goto after_6;
    // 0x807B8AC4: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    after_6:
    // 0x807B8AC8: jal         0x807B8340
    // 0x807B8ACC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_807B8340(rdram, ctx);
        goto after_7;
    // 0x807B8ACC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x807B8AD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B8AD4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x807B8AD8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x807B8ADC: jr          $ra
    // 0x807B8AE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807B8AE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80566BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566BE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80566BE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80566BEC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80566BF0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80566BF4: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80566BF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80566BFC: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80566C00: beq         $v0, $zero, L_80566C10
    if (ctx->r2 == 0) {
        // 0x80566C04: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80566C10;
    }
    // 0x80566C04: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80566C08: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x80566C0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80566C10:
    // 0x80566C10: bne         $v0, $zero, L_80566CA4
    if (ctx->r2 != 0) {
        // 0x80566C14: nop
    
            goto L_80566CA4;
    }
    // 0x80566C14: nop

    // 0x80566C18: jal         0x805667A8
    // 0x80566C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805667A8(rdram, ctx);
        goto after_0;
    // 0x80566C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80566C20: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80566C24: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80566C28: bne         $t7, $at, L_80566CA4
    if (ctx->r15 != ctx->r1) {
        // 0x80566C2C: nop
    
            goto L_80566CA4;
    }
    // 0x80566C2C: nop

    // 0x80566C30: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    // 0x80566C34: bne         $t8, $zero, L_80566CA4
    if (ctx->r24 != 0) {
        // 0x80566C38: nop
    
            goto L_80566CA4;
    }
    // 0x80566C38: nop

    // 0x80566C3C: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80566C40: addiu       $at, $zero, 0x4177
    ctx->r1 = ADD32(0, 0X4177);
    // 0x80566C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80566C48: bne         $v0, $at, L_80566C5C
    if (ctx->r2 != ctx->r1) {
        // 0x80566C4C: lui         $a1, 0xC100
        ctx->r5 = S32(0XC100 << 16);
            goto L_80566C5C;
    }
    // 0x80566C4C: lui         $a1, 0xC100
    ctx->r5 = S32(0XC100 << 16);
    // 0x80566C50: jal         0x8056698C
    // 0x80566C54: addiu       $a2, $zero, 0x415A
    ctx->r6 = ADD32(0, 0X415A);
    func_8056698C(rdram, ctx);
        goto after_1;
    // 0x80566C54: addiu       $a2, $zero, 0x415A
    ctx->r6 = ADD32(0, 0X415A);
    after_1:
    // 0x80566C58: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
L_80566C5C:
    // 0x80566C5C: addiu       $at, $zero, 0x4178
    ctx->r1 = ADD32(0, 0X4178);
    // 0x80566C60: bne         $v0, $at, L_80566C78
    if (ctx->r2 != ctx->r1) {
        // 0x80566C64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80566C78;
    }
    // 0x80566C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80566C68: lui         $a1, 0xC100
    ctx->r5 = S32(0XC100 << 16);
    // 0x80566C6C: jal         0x8056698C
    // 0x80566C70: addiu       $a2, $zero, 0x4166
    ctx->r6 = ADD32(0, 0X4166);
    func_8056698C(rdram, ctx);
        goto after_2;
    // 0x80566C70: addiu       $a2, $zero, 0x4166
    ctx->r6 = ADD32(0, 0X4166);
    after_2:
    // 0x80566C74: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
L_80566C78:
    // 0x80566C78: addiu       $at, $zero, 0x4179
    ctx->r1 = ADD32(0, 0X4179);
    // 0x80566C7C: bne         $v0, $at, L_80566C90
    if (ctx->r2 != ctx->r1) {
        // 0x80566C80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80566C90;
    }
    // 0x80566C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80566C84: lui         $a1, 0xC100
    ctx->r5 = S32(0XC100 << 16);
    // 0x80566C88: jal         0x8056698C
    // 0x80566C8C: addiu       $a2, $zero, 0x4172
    ctx->r6 = ADD32(0, 0X4172);
    func_8056698C(rdram, ctx);
        goto after_3;
    // 0x80566C8C: addiu       $a2, $zero, 0x4172
    ctx->r6 = ADD32(0, 0X4172);
    after_3:
L_80566C90:
    // 0x80566C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80566C94: jal         0x80566900
    // 0x80566C98: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    func_80566900(rdram, ctx);
        goto after_4;
    // 0x80566C98: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    after_4:
    // 0x80566C9C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80566CA0: sw          $t9, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r25;
L_80566CA4:
    // 0x80566CA4: jal         0x80566674
    // 0x80566CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80566674(rdram, ctx);
        goto after_5;
    // 0x80566CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80566CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80566CB0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80566CB4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80566CB8: jr          $ra
    // 0x80566CBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80566CBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80530C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530C4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80530C50: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80530C54: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80530C58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80530C5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80530C60: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80530C64: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80530C68: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80530C6C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80530C70: lui         $t1, 0x8053
    ctx->r9 = S32(RELOC_HI16(339, 0X408) << 16);
    // 0x80530C74: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80530C78: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80530C7C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80530C80: lw          $t1, 0xD28($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(339, 0X408));
    // 0x80530C84: jal         0x80530C9C
    // 0x80530C88: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_80530C9C(rdram, ctx);
        goto after_0;
    // 0x80530C88: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x80530C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80530C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80530C94: jr          $ra
    // 0x80530C98: nop

    return;
    // 0x80530C98: nop

;}
RECOMP_FUNC void func_80003530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003530: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80003534: lh          $v0, 0x6AA0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6AA0);
    // 0x80003538: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000353C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80003540: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80003544: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80003548: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000354C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80003550: blez        $v0, L_8000359C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80003554: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000359C;
    }
    // 0x80003554: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80003558: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x8000355C: addiu       $s0, $s0, 0x4D10
    ctx->r16 = ADD32(ctx->r16, 0X4D10);
L_80003560:
    // 0x80003560: lw          $t6, 0x2A30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2A30);
    // 0x80003564: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80003568: beql        $t7, $zero, L_80003590
    if (ctx->r15 == 0) {
        // 0x8000356C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80003590;
    }
    goto skip_0;
    // 0x8000356C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80003570: lbu         $t8, 0x2A34($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2A34);
    // 0x80003574: bnel        $s2, $t8, L_80003590
    if (ctx->r18 != ctx->r24) {
        // 0x80003578: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80003590;
    }
    goto skip_1;
    // 0x80003578: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x8000357C: jal         0x8000DAE8
    // 0x80003580: addiu       $a0, $s0, 0x2A30
    ctx->r4 = ADD32(ctx->r16, 0X2A30);
    func_8000DAE8(rdram, ctx);
        goto after_0;
    // 0x80003580: addiu       $a0, $s0, 0x2A30
    ctx->r4 = ADD32(ctx->r16, 0X2A30);
    after_0:
    // 0x80003584: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80003588: lh          $v0, 0x6AA0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6AA0);
    // 0x8000358C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80003590:
    // 0x80003590: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80003594: bne         $at, $zero, L_80003560
    if (ctx->r1 != 0) {
        // 0x80003598: addiu       $s0, $s0, 0x160
        ctx->r16 = ADD32(ctx->r16, 0X160);
            goto L_80003560;
    }
    // 0x80003598: addiu       $s0, $s0, 0x160
    ctx->r16 = ADD32(ctx->r16, 0X160);
L_8000359C:
    // 0x8000359C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800035A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800035A4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800035A8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800035AC: jr          $ra
    // 0x800035B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800035B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806F6B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F6B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F6B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F6B0C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806F6B10: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806F6B14: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(688, 0X628) << 16);
    // 0x806F6B18: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806F6B1C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806F6B20: addiu       $t7, $t7, 0x6CC8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(688, 0X628));
    // 0x806F6B24: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806F6B28: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806F6B2C: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806F6B30: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806F6B34: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806F6B38: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x806F6B3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806F6B40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806F6B44: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x806F6B48: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x806F6B4C: jal         0x80048378
    // 0x806F6B50: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x806F6B50: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x806F6B54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F6B58: jal         0x80045A34
    // 0x806F6B5C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x806F6B5C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x806F6B60: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806F6B64: sw          $v0, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = ctx->r2;
    // 0x806F6B68: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // 0x806F6B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F6B70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F6B74: jr          $ra
    // 0x806F6B78: nop

    return;
    // 0x806F6B78: nop

;}
RECOMP_FUNC void func_80009200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009200: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80009204: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80009208: lw          $t6, 0x6A88($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A88);
    // 0x8000920C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80009210: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80009214: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80009218: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000921C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80009220: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80009224: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80009228: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000922C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80009230: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80009234: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80009238: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8000923C: lbu         $s0, 0x1($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X1);
    // 0x80009240: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80009244: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80009248: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000924C: lbu         $s6, 0x0($v0)
    ctx->r22 = MEM_BU(ctx->r2, 0X0);
    // 0x80009250: blez        $s0, L_8000928C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80009254: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8000928C;
    }
    // 0x80009254: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80009258: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8000925C:
    // 0x8000925C: jal         0x8000B8DC
    // 0x80009260: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8000B8DC(rdram, ctx);
        goto after_0;
    // 0x80009260: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80009264: beq         $v0, $zero, L_8000927C
    if (ctx->r2 == 0) {
        // 0x80009268: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8000927C;
    }
    // 0x80009268: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000926C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80009270: jal         0x800091B8
    // 0x80009274: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800091B8(rdram, ctx);
        goto after_1;
    // 0x80009274: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_1:
    // 0x80009278: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8000927C:
    // 0x8000927C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80009280: bnel        $s2, $s0, L_8000925C
    if (ctx->r18 != ctx->r16) {
        // 0x80009284: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8000925C;
    }
    goto skip_0;
    // 0x80009284: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
    // 0x80009288: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000928C:
    // 0x8000928C: blez        $s6, L_80009308
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80009290: addiu       $s5, $zero, 0x7F
        ctx->r21 = ADD32(0, 0X7F);
            goto L_80009308;
    }
    // 0x80009290: addiu       $s5, $zero, 0x7F
    ctx->r21 = ADD32(0, 0X7F);
    // 0x80009294: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80009298:
    // 0x80009298: jal         0x8000B808
    // 0x8000929C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8000B808(rdram, ctx);
        goto after_2;
    // 0x8000929C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800092A0: beq         $v0, $zero, L_800092FC
    if (ctx->r2 == 0) {
        // 0x800092A4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800092FC;
    }
    // 0x800092A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800092A8: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800092AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800092B0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800092B4: beql        $t8, $zero, L_800092CC
    if (ctx->r24 == 0) {
        // 0x800092B8: lbu         $t9, 0x2($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X2);
            goto L_800092CC;
    }
    goto skip_1;
    // 0x800092B8: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
    skip_1:
    // 0x800092BC: jal         0x800091B8
    // 0x800092C0: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    func_800091B8(rdram, ctx);
        goto after_3;
    // 0x800092C0: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    after_3:
    // 0x800092C4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800092C8: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
L_800092CC:
    // 0x800092CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800092D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800092D4: beql        $s5, $t9, L_800092EC
    if (ctx->r21 == ctx->r25) {
        // 0x800092D8: lw          $a0, 0x10($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X10);
            goto L_800092EC;
    }
    goto skip_2;
    // 0x800092D8: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    skip_2:
    // 0x800092DC: jal         0x800091B8
    // 0x800092E0: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    func_800091B8(rdram, ctx);
        goto after_4;
    // 0x800092E0: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_4:
    // 0x800092E4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800092E8: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
L_800092EC:
    // 0x800092EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800092F0: jal         0x800091B8
    // 0x800092F4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800091B8(rdram, ctx);
        goto after_5;
    // 0x800092F4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_5:
    // 0x800092F8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800092FC:
    // 0x800092FC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80009300: bnel        $s2, $s6, L_80009298
    if (ctx->r18 != ctx->r22) {
        // 0x80009304: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80009298;
    }
    goto skip_3;
    // 0x80009304: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_3:
L_80009308:
    // 0x80009308: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000930C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80009310: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80009314: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80009318: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000931C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80009320: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80009324: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80009328: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000932C: jr          $ra
    // 0x80009330: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80009330: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_804BAFE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BAFE4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x804BAFE8: sb          $v0, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r2;
    // 0x804BAFEC: sb          $v0, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r2;
    // 0x804BAFF0: jr          $ra
    // 0x804BAFF4: sb          $v0, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r2;
    return;
    // 0x804BAFF4: sb          $v0, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80776AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80776AD0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80776AD4: addiu       $at, $zero, 0x4650
    ctx->r1 = ADD32(0, 0X4650);
    // 0x80776AD8: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(772, 0X734) << 16);
    // 0x80776ADC: bne         $t6, $at, L_80776AF0
    if (ctx->r14 != ctx->r1) {
        // 0x80776AE0: addiu       $v0, $v0, 0x7204
        ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(772, 0X734));
            goto L_80776AF0;
    }
    // 0x80776AE0: addiu       $v0, $v0, 0x7204
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(772, 0X734));
    // 0x80776AE4: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(772, 0X734) << 16);
    // 0x80776AE8: jr          $ra
    // 0x80776AEC: addiu       $v0, $v0, 0x7204
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(772, 0X734));
    return;
    // 0x80776AEC: addiu       $v0, $v0, 0x7204
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(772, 0X734));
L_80776AF0:
    // 0x80776AF0: jr          $ra
    // 0x80776AF4: nop

    return;
    // 0x80776AF4: nop

;}
RECOMP_FUNC void func_80462198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462198: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8046219C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804621A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804621A4: jal         0x8004700C
    // 0x804621A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804621A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804621AC: beq         $v0, $zero, L_8046220C
    if (ctx->r2 == 0) {
        // 0x804621B0: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_8046220C;
    }
    // 0x804621B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804621B4: jal         0x80461C60
    // 0x804621B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80461C60(rdram, ctx);
        goto after_1;
    // 0x804621B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804621BC: jal         0x80461EF0
    // 0x804621C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80461EF0(rdram, ctx);
        goto after_2;
    // 0x804621C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804621C4: jal         0x80462014
    // 0x804621C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80462014(rdram, ctx);
        goto after_3;
    // 0x804621C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804621CC: jal         0x8046212C
    // 0x804621D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046212C(rdram, ctx);
        goto after_4;
    // 0x804621D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804621D4: jal         0x80461C04
    // 0x804621D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80461C04(rdram, ctx);
        goto after_5;
    // 0x804621D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804621DC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804621E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804621E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804621E8: lw          $t6, 0x180($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X180);
    // 0x804621EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804621F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804621F4: bnel        $s0, $t6, L_80462210
    if (ctx->r16 != ctx->r14) {
        // 0x804621F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80462210;
    }
    goto skip_0;
    // 0x804621F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804621FC: lw          $t8, 0x1F4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1F4);
    // 0x80462200: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80462204: jal         0x804623F0
    // 0x80462208: sb          $t7, 0xDC($t8)
    MEM_B(0XDC, ctx->r24) = ctx->r15;
    func_804623F0(rdram, ctx);
        goto after_6;
    // 0x80462208: sb          $t7, 0xDC($t8)
    MEM_B(0XDC, ctx->r24) = ctx->r15;
    after_6:
L_8046220C:
    // 0x8046220C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80462210:
    // 0x80462210: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80462214: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80462218: jr          $ra
    // 0x8046221C: nop

    return;
    // 0x8046221C: nop

;}
RECOMP_FUNC void func_8004FD78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FD78: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8004FD7C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8004FD80: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8004FD84: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8004FD88: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004FD8C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8004FD90: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8004FD94: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x8004FD98: lh          $t8, 0x3A($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X3A);
    // 0x8004FD9C: addiu       $s0, $v0, 0x38
    ctx->r16 = ADD32(ctx->r2, 0X38);
    // 0x8004FDA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004FDA4: sh          $t8, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r24;
    // 0x8004FDA8: lh          $t9, 0x3C($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X3C);
    // 0x8004FDAC: sh          $t9, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r25;
    // 0x8004FDB0: lh          $t0, 0x42($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X42);
    // 0x8004FDB4: sh          $t0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r8;
    // 0x8004FDB8: lh          $t1, 0x44($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X44);
    // 0x8004FDBC: jal         0x8004FC60
    // 0x8004FDC0: sh          $t1, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r9;
    func_8004FC60(rdram, ctx);
        goto after_0;
    // 0x8004FDC0: sh          $t1, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r9;
    after_0:
    // 0x8004FDC4: lh          $t2, 0x3E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3E);
    // 0x8004FDC8: lh          $t3, 0x3C($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X3C);
    // 0x8004FDCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004FDD0: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004FDD4: mflo        $a3
    ctx->r7 = lo;
    // 0x8004FDD8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8004FDDC: jal         0x8004FCB0
    // 0x8004FDE0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_8004FCB0(rdram, ctx);
        goto after_1;
    // 0x8004FDE0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_1:
    // 0x8004FDE4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8004FDE8: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8004FDEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004FDF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004FDF4: jal         0x800657CC
    // 0x8004FDF8: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    func_800657CC(rdram, ctx);
        goto after_2;
    // 0x8004FDF8: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    after_2:
    // 0x8004FDFC: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8004FE00: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x8004FE04: lh          $a2, 0x3E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3E);
    // 0x8004FE08: lw          $a0, 0x1B0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1B0);
    // 0x8004FE0C: lw          $a3, 0x1B4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X1B4);
    // 0x8004FE10: lh          $t4, 0x42($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X42);
    // 0x8004FE14: lh          $t5, 0x40($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X40);
    // 0x8004FE18: lh          $t6, 0x3C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3C);
    // 0x8004FE1C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8004FE20: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8004FE24: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8004FE28: jal         0x8006B7D8
    // 0x8004FE2C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8006B7D8(rdram, ctx);
        goto after_3;
    // 0x8004FE2C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_3:
    // 0x8004FE30: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004FE34: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8004FE38: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8004FE3C: jr          $ra
    // 0x8004FE40: nop

    return;
    // 0x8004FE40: nop

;}
RECOMP_FUNC void func_804634AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804634AC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x804634B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804634B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804634B8: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x804634BC: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804634C0: lw          $s0, 0x1F4($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X1F4);
    // 0x804634C4: addiu       $t1, $zero, 0x240
    ctx->r9 = ADD32(0, 0X240);
    // 0x804634C8: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x804634CC: lw          $v0, 0x168($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X168);
    // 0x804634D0: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x804634D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804634D8: lw          $t8, 0x88($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X88);
    // 0x804634DC: sw          $t8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r24;
    // 0x804634E0: lh          $t0, 0x144($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X144);
    // 0x804634E4: lw          $v1, 0x80($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X80);
    // 0x804634E8: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x804634EC: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804634F0: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x804634F4: mflo        $t9
    ctx->r25 = lo;
    // 0x804634F8: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x804634FC: sw          $t6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r14;
    // 0x80463500: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80463504: mflo        $t8
    ctx->r24 = lo;
    // 0x80463508: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8046350C: jal         0x80077338
    // 0x80463510: sw          $t9, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r25;
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x80463510: sw          $t9, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80463514: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x80463518: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8046351C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80463520: jal         0x8007711C
    // 0x80463524: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x80463524: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    after_1:
    // 0x80463528: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x8046352C: lui         $t0, 0xFD50
    ctx->r8 = S32(0XFD50 << 16);
    // 0x80463530: lui         $t1, 0xF550
    ctx->r9 = S32(0XF550 << 16);
    // 0x80463534: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80463538: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x8046353C: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x80463540: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x80463544: lui         $t2, 0x700
    ctx->r10 = S32(0X700 << 16);
    // 0x80463548: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x8046354C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80463550: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x80463554: lui         $ra, 0x711
    ctx->r31 = S32(0X711 << 16);
    // 0x80463558: ori         $ra, $ra, 0xF2AB
    ctx->r31 = ctx->r31 | 0XF2AB;
    // 0x8046355C: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80463560: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x80463564: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x80463568: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8046356C: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x80463570: lui         $t4, 0xF300
    ctx->r12 = S32(0XF300 << 16);
    // 0x80463574: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x80463578: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8046357C: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x80463580: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80463584: sw          $t3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r11;
    // 0x80463588: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x8046358C: ori         $t5, $t5, 0x81FF
    ctx->r13 = ctx->r13 | 0X81FF;
    // 0x80463590: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80463594: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x80463598: sw          $ra, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r31;
    // 0x8046359C: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x804635A0: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x804635A4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804635A8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x804635AC: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x804635B0: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x804635B4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x804635B8: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x804635BC: lui         $t8, 0xF548
    ctx->r24 = S32(0XF548 << 16);
    // 0x804635C0: ori         $t8, $t8, 0x600
    ctx->r24 = ctx->r24 | 0X600;
    // 0x804635C4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x804635C8: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x804635CC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x804635D0: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x804635D4: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x804635D8: lui         $t8, 0x5
    ctx->r24 = S32(0X5 << 16);
    // 0x804635DC: ori         $t8, $t8, 0xC05C
    ctx->r24 = ctx->r24 | 0XC05C;
    // 0x804635E0: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x804635E4: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x804635E8: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x804635EC: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x804635F0: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x804635F4: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x804635F8: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x804635FC: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x80463600: sw          $s0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r16;
    // 0x80463604: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x80463608: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x8046360C: lui         $t9, 0xB100
    ctx->r25 = S32(0XB100 << 16);
    // 0x80463610: lui         $t6, 0x2
    ctx->r14 = S32(0X2 << 16);
    // 0x80463614: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80463618: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8046361C: ori         $t6, $t6, 0x604
    ctx->r14 = ctx->r14 | 0X604;
    // 0x80463620: ori         $t9, $t9, 0x204
    ctx->r25 = ctx->r25 | 0X204;
    // 0x80463624: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80463628: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8046362C: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x80463630: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80463634: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x80463638: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x8046363C: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x80463640: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80463644: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x80463648: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8046364C: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x80463650: sw          $t2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r10;
    // 0x80463654: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x80463658: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x8046365C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80463660: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80463664: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80463668: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8046366C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80463670: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x80463674: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x80463678: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8046367C: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x80463680: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80463684: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x80463688: sw          $ra, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r31;
    // 0x8046368C: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x80463690: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x80463694: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80463698: addiu       $a3, $a2, 0x2
    ctx->r7 = ADD32(ctx->r6, 0X2);
    // 0x8046369C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x804636A0: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x804636A4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x804636A8: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x804636AC: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x804636B0: lui         $t9, 0xF548
    ctx->r25 = S32(0XF548 << 16);
    // 0x804636B4: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x804636B8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x804636BC: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x804636C0: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x804636C4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x804636C8: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x804636CC: lui         $t9, 0x5
    ctx->r25 = S32(0X5 << 16);
    // 0x804636D0: ori         $t9, $t9, 0xC05C
    ctx->r25 = ctx->r25 | 0XC05C;
    // 0x804636D4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x804636D8: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x804636DC: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x804636E0: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x804636E4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x804636E8: lw          $v1, 0x98($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X98);
    // 0x804636EC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804636F0: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x804636F4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x804636F8: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x804636FC: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x80463700: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80463704: addiu       $t0, $a2, 0x4
    ctx->r8 = ADD32(ctx->r6, 0X4);
    // 0x80463708: andi        $a1, $t0, 0xFF
    ctx->r5 = ctx->r8 & 0XFF;
    // 0x8046370C: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80463710: or          $t8, $t7, $a1
    ctx->r24 = ctx->r15 | ctx->r5;
    // 0x80463714: lui         $t4, 0xB100
    ctx->r12 = S32(0XB100 << 16);
    // 0x80463718: or          $t9, $t8, $t4
    ctx->r25 = ctx->r24 | ctx->r12;
    // 0x8046371C: addiu       $v0, $a2, 0x6
    ctx->r2 = ADD32(ctx->r6, 0X6);
    // 0x80463720: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80463724: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80463728: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8046372C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80463730: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80463734: or          $t7, $t9, $a1
    ctx->r15 = ctx->r25 | ctx->r5;
    // 0x80463738: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8046373C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80463740: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80463744: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80463748: addiu       $ra, $zero, 0x8
    ctx->r31 = ADD32(0, 0X8);
    // 0x8046374C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_80463750:
    // 0x80463750: slti        $at, $v0, 0x46
    ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
    // 0x80463754: bne         $at, $zero, L_8046378C
    if (ctx->r1 != 0) {
        // 0x80463758: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_8046378C;
    }
    // 0x80463758: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x8046375C: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x80463760: sll         $t9, $t1, 9
    ctx->r25 = S32(ctx->r9 << 9);
    // 0x80463764: addu        $t7, $t9, $s0
    ctx->r15 = ADD32(ctx->r25, ctx->r16);
    // 0x80463768: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8046376C: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x80463770: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80463774: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80463778: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8046377C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80463780: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80463784: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x80463788: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_8046378C:
    // 0x8046378C: lw          $v1, 0x98($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X98);
    // 0x80463790: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x80463794: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80463798: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8046379C: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x804637A0: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x804637A4: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x804637A8: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x804637AC: andi        $a1, $t0, 0xFF
    ctx->r5 = ctx->r8 & 0XFF;
    // 0x804637B0: or          $t9, $t8, $a1
    ctx->r25 = ctx->r24 | ctx->r5;
    // 0x804637B4: or          $t7, $t9, $t4
    ctx->r15 = ctx->r25 | ctx->r12;
    // 0x804637B8: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x804637BC: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x804637C0: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x804637C4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x804637C8: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x804637CC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x804637D0: slti        $at, $v0, 0x46
    ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
    // 0x804637D4: or          $t8, $t7, $a1
    ctx->r24 = ctx->r15 | ctx->r5;
    // 0x804637D8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x804637DC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x804637E0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x804637E4: bne         $at, $zero, L_8046381C
    if (ctx->r1 != 0) {
        // 0x804637E8: sw          $t8, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r24;
            goto L_8046381C;
    }
    // 0x804637E8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x804637EC: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x804637F0: sll         $t7, $t1, 9
    ctx->r15 = S32(ctx->r9 << 9);
    // 0x804637F4: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x804637F8: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x804637FC: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x80463800: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80463804: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80463808: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8046380C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80463810: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80463814: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80463818: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_8046381C:
    // 0x8046381C: lw          $v1, 0x98($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X98);
    // 0x80463820: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x80463824: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x80463828: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8046382C: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x80463830: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80463834: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x80463838: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8046383C: andi        $a1, $t0, 0xFF
    ctx->r5 = ctx->r8 & 0XFF;
    // 0x80463840: or          $t7, $t9, $a1
    ctx->r15 = ctx->r25 | ctx->r5;
    // 0x80463844: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x80463848: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8046384C: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x80463850: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80463854: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80463858: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8046385C: or          $t9, $t8, $a1
    ctx->r25 = ctx->r24 | ctx->r5;
    // 0x80463860: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80463864: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80463868: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8046386C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80463870: bne         $t2, $ra, L_80463750
    if (ctx->r10 != ctx->r31) {
        // 0x80463874: sw          $t9, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r25;
            goto L_80463750;
    }
    // 0x80463874: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80463878: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x8046387C: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80463880: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x80463884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80463888: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046388C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x80463890: jr          $ra
    // 0x80463894: nop

    return;
    // 0x80463894: nop

;}
RECOMP_FUNC void func_80006B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006B78: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80006B7C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80006B80: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80006B84: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80006B88: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80006B8C: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80006B90: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80006B94: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80006B98: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80006B9C: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x80006BA0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80006BA4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80006BA8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80006BAC: jal         0x800073BC
    // 0x80006BB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800073BC(rdram, ctx);
        goto after_0;
    // 0x80006BB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80006BB4: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x80006BB8: addiu       $s2, $s2, 0x4D10
    ctx->r18 = ADD32(ctx->r18, 0X4D10);
    // 0x80006BBC: lw          $v1, 0x1D70($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1D70);
    // 0x80006BC0: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80006BC4: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80006BC8: lhu         $s0, 0x0($t7)
    ctx->r16 = MEM_HU(ctx->r15, 0X0);
    // 0x80006BCC: addu        $t8, $s0, $v1
    ctx->r24 = ADD32(ctx->r16, ctx->r3);
    // 0x80006BD0: lbu         $s1, 0x0($t8)
    ctx->r17 = MEM_BU(ctx->r24, 0X0);
    // 0x80006BD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80006BD8: blezl       $s1, L_80006C20
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80006BDC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80006C20;
    }
    goto skip_0;
    // 0x80006BDC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80006BE0: lw          $t9, 0x1D70($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X1D70);
L_80006BE4:
    // 0x80006BE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80006BE8: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x80006BEC: lbu         $a1, 0x0($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X0);
    // 0x80006BF0: jal         0x800073BC
    // 0x80006BF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800073BC(rdram, ctx);
        goto after_1;
    // 0x80006BF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_1:
    // 0x80006BF8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80006BFC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80006C00: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80006C04: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80006C08: jal         0x800078B4
    // 0x80006C0C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    func_800078B4(rdram, ctx);
        goto after_2;
    // 0x80006C0C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_2:
    // 0x80006C10: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80006C14: bgtzl       $s1, L_80006BE4
    if (SIGNED(ctx->r17) > 0) {
        // 0x80006C18: lw          $t9, 0x1D70($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X1D70);
            goto L_80006BE4;
    }
    goto skip_1;
    // 0x80006C18: lw          $t9, 0x1D70($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X1D70);
    skip_1:
    // 0x80006C1C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80006C20:
    // 0x80006C20: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80006C24: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80006C28: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80006C2C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80006C30: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80006C34: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80006C38: jr          $ra
    // 0x80006C3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80006C3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8007A700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A700: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007A704: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8007A708: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007A70C: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8007A710: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8007A714: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8007A718: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8007A71C: addiu       $t6, $t0, -0x1
    ctx->r14 = ADD32(ctx->r8, -0X1);
    // 0x8007A720: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8007A724: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8007A728: bc1f        L_8007A73C
    if (!c1cs) {
        // 0x8007A72C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8007A73C;
    }
    // 0x8007A72C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007A730: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x8007A734: b           L_8007A744
    // 0x8007A738: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_8007A744;
    // 0x8007A738: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8007A73C:
    // 0x8007A73C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8007A740: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8007A744:
    // 0x8007A744: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8007A748: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007A74C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007A750: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8007A754: bc1f        L_8007A764
    if (!c1cs) {
        // 0x8007A758: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_8007A764;
    }
    // 0x8007A758: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8007A75C: b           L_8007A76C
    // 0x8007A760: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
        goto L_8007A76C;
    // 0x8007A760: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
L_8007A764:
    // 0x8007A764: neg.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = -ctx->f18.fl;
    // 0x8007A768: ori         $t1, $t1, 0x2
    ctx->r9 = ctx->r9 | 0X2;
L_8007A76C:
    // 0x8007A76C: lw          $v0, -0x7AF0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7AF0);
    // 0x8007A770: mul.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8007A774: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8007A778: lhu         $t7, 0x18($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X18);
    // 0x8007A77C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007A780: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8007A784: add.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8007A788: bgez        $t7, L_8007A79C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8007A78C: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8007A79C;
    }
    // 0x8007A78C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007A790: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007A794: nop

    // 0x8007A798: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8007A79C:
    // 0x8007A79C: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8007A7A0: nop

    // 0x8007A7A4: bc1tl       L_8007A8F4
    if (c1cs) {
        // 0x8007A7A8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8007A8F4;
    }
    goto skip_0;
    // 0x8007A7A8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8007A7AC: lhu         $t8, 0x1C($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1C);
    // 0x8007A7B0: sub.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8007A7B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007A7B8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8007A7BC: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8007A7C0: bgez        $t8, L_8007A7D4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007A7C4: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8007A7D4;
    }
    // 0x8007A7C4: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007A7C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007A7CC: nop

    // 0x8007A7D0: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_8007A7D4:
    // 0x8007A7D4: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8007A7D8: addiu       $t9, $t2, -0x1
    ctx->r25 = ADD32(ctx->r10, -0X1);
    // 0x8007A7DC: bc1tl       L_8007A8F4
    if (c1cs) {
        // 0x8007A7E0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8007A8F4;
    }
    goto skip_1;
    // 0x8007A7E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x8007A7E4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8007A7E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007A7EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007A7F0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007A7F4: lhu         $t3, 0x1A($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X1A);
    // 0x8007A7F8: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8007A7FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007A800: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8007A804: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8007A808: mul.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8007A80C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007A810: bgez        $t3, L_8007A824
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8007A814: add.s       $f16, $f6, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f2.fl;
            goto L_8007A824;
    }
    // 0x8007A814: add.s       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8007A818: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007A81C: nop

    // 0x8007A820: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8007A824:
    // 0x8007A824: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8007A828: nop

    // 0x8007A82C: bc1tl       L_8007A8F4
    if (c1cs) {
        // 0x8007A830: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8007A8F4;
    }
    goto skip_2;
    // 0x8007A830: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x8007A834: lhu         $t4, 0x1E($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X1E);
    // 0x8007A838: sub.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8007A83C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007A840: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8007A844: sllv        $v1, $t0, $a3
    ctx->r3 = S32(ctx->r8 << (ctx->r7 & 31));
    // 0x8007A848: bgez        $t4, L_8007A85C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007A84C: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8007A85C;
    }
    // 0x8007A84C: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007A850: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007A854: nop

    // 0x8007A858: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_8007A85C:
    // 0x8007A85C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8007A860: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007A864: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007A868: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8007A86C: bc1tl       L_8007A8F4
    if (c1cs) {
        // 0x8007A870: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8007A8F4;
    }
    goto skip_3;
    // 0x8007A870: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x8007A874: bne         $a2, $at, L_8007A884
    if (ctx->r6 != ctx->r1) {
        // 0x8007A878: addiu       $v0, $zero, 0x1000
        ctx->r2 = ADD32(0, 0X1000);
            goto L_8007A884;
    }
    // 0x8007A878: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // 0x8007A87C: b           L_8007A884
    // 0x8007A880: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
        goto L_8007A884;
    // 0x8007A880: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
L_8007A884:
    // 0x8007A884: multu       $v1, $t2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007A888: mflo        $t5
    ctx->r13 = lo;
    // 0x8007A88C: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8007A890: bnel        $at, $zero, L_8007A8C4
    if (ctx->r1 != 0) {
        // 0x8007A894: lwc1        $f6, 0x50($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
            goto L_8007A8C4;
    }
    goto skip_4;
    // 0x8007A894: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    skip_4:
    // 0x8007A898: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8007A89C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8007A8A0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8007A8A4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8007A8A8: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8007A8AC: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8007A8B0: jal         0x80079A20
    // 0x8007A8B4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    func_80079A20(rdram, ctx);
        goto after_0;
    // 0x8007A8B4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_0:
    // 0x8007A8B8: b           L_8007A8F4
    // 0x8007A8BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8007A8F4;
    // 0x8007A8BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8007A8C0: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
L_8007A8C4:
    // 0x8007A8C4: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8007A8C8: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8007A8CC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8007A8D0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8007A8D4: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8007A8D8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8007A8DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8007A8E0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8007A8E4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8007A8E8: jal         0x80079D48
    // 0x8007A8EC: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_80079D48(rdram, ctx);
        goto after_1;
    // 0x8007A8EC: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8007A8F0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8007A8F4:
    // 0x8007A8F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8007A8F8: jr          $ra
    // 0x8007A8FC: nop

    return;
    // 0x8007A8FC: nop

;}
RECOMP_FUNC void func_806D9710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D9710: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D9714: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806D9718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D971C: lui         $a0, 0x806E
    ctx->r4 = S32(RELOC_HI16(631, 0X4A0) << 16);
    // 0x806D9720: lui         $a1, 0x806E
    ctx->r5 = S32(RELOC_HI16(631, 0X4B0) << 16);
    // 0x806D9724: addiu       $a1, $a1, -0x6440
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(631, 0X4B0));
    // 0x806D9728: addiu       $a0, $a0, -0x6450
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(631, 0X4A0));
    // 0x806D972C: jal         0x8004667C
    // 0x806D9730: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x806D9730: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x806D9734: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x806D9738: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x806D973C: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x806D9740: lui         $a2, 0x806E
    ctx->r6 = S32(RELOC_HI16(631, 0X2C0) << 16);
    // 0x806D9744: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x806D9748: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x806D974C: bnel        $t7, $zero, L_806D9760
    if (ctx->r15 != 0) {
        // 0x806D9750: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D9760;
    }
    goto skip_0;
    // 0x806D9750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806D9754: jal         0x80057B28
    // 0x806D9758: addiu       $a2, $a2, -0x6630
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(631, 0X2C0));
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x806D9758: addiu       $a2, $a2, -0x6630
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(631, 0X2C0));
    after_1:
    // 0x806D975C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D9760:
    // 0x806D9760: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(631, 0X60) << 16);
    // 0x806D9764: addiu       $v0, $v0, -0x6890
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(631, 0X60));
    // 0x806D9768: jr          $ra
    // 0x806D976C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806D976C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800483B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800483B8: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x800483BC: lwc1        $f6, 0x100($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X100);
    // 0x800483C0: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x800483C4: lwc1        $f10, 0x10C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x800483C8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800483CC: beq         $v0, $zero, L_8004842C
    if (ctx->r2 == 0) {
        // 0x800483D0: add.s       $f0, $f10, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
            goto L_8004842C;
    }
    // 0x800483D0: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800483D4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800483D8: nop

    // 0x800483DC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800483E0: nop

    // 0x800483E4: bc1fl       L_80048400
    if (!c1cs) {
        // 0x800483E8: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80048400;
    }
    goto skip_0;
    // 0x800483E8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x800483EC: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x800483F0: andi        $t7, $t6, 0xF0
    ctx->r15 = ctx->r14 & 0XF0;
    // 0x800483F4: beql        $t7, $zero, L_80048420
    if (ctx->r15 == 0) {
        // 0x800483F8: lwc1        $f16, 0x3C($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_80048420;
    }
    goto skip_1;
    // 0x800483F8: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    skip_1:
    // 0x800483FC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80048400:
    // 0x80048400: nop

    // 0x80048404: bc1fl       L_80048440
    if (!c1cs) {
        // 0x80048408: lwc1        $f18, 0xC8($a0)
        ctx->f18.u32l = MEM_W(ctx->r4, 0XC8);
            goto L_80048440;
    }
    goto skip_2;
    // 0x80048408: lwc1        $f18, 0xC8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC8);
    skip_2:
    // 0x8004840C: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80048410: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x80048414: bnel        $t9, $zero, L_80048440
    if (ctx->r25 != 0) {
        // 0x80048418: lwc1        $f18, 0xC8($a0)
        ctx->f18.u32l = MEM_W(ctx->r4, 0XC8);
            goto L_80048440;
    }
    goto skip_3;
    // 0x80048418: lwc1        $f18, 0xC8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC8);
    skip_3:
    // 0x8004841C: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
L_80048420:
    // 0x80048420: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80048424: b           L_8004843C
    // 0x80048428: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
        goto L_8004843C;
    // 0x80048428: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
L_8004842C:
    // 0x8004842C: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80048430: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80048434: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80048438: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
L_8004843C:
    // 0x8004843C: lwc1        $f18, 0xC8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC8);
L_80048440:
    // 0x80048440: lwc1        $f16, 0x104($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X104);
    // 0x80048444: lwc1        $f14, 0x110($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X110);
    // 0x80048448: lwc1        $f12, 0x40($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8004844C: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80048450: lwc1        $f18, 0x44($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80048454: lwc1        $f10, 0xCC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x80048458: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004845C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80048460: add.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80048464: swc1        $f2, 0x114($a0)
    MEM_W(0X114, ctx->r4) = ctx->f2.u32l;
    // 0x80048468: swc1        $f2, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f2.u32l;
    // 0x8004846C: add.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80048470: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    // 0x80048474: swc1        $f2, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f2.u32l;
    // 0x80048478: swc1        $f8, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->f8.u32l;
    // 0x8004847C: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80048480: swc1        $f8, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->f8.u32l;
    // 0x80048484: swc1        $f8, 0x100($a0)
    MEM_W(0X100, ctx->r4) = ctx->f8.u32l;
    // 0x80048488: jr          $ra
    // 0x8004848C: swc1        $f14, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x8004848C: swc1        $f14, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_806F85F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F85F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F85FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F8600: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B28) << 16);
    // 0x806F8604: lwc1        $f6, -0x6CC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B28));
    // 0x806F8608: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x806F860C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F8610: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806F8614: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x806F8618: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x806F861C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x806F8620: nop

    // 0x806F8624: bc1f        L_806F8634
    if (!c1cs) {
        // 0x806F8628: nop
    
            goto L_806F8634;
    }
    // 0x806F8628: nop

    // 0x806F862C: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x806F8630: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
L_806F8634:
    // 0x806F8634: jal         0x806F84D8
    // 0x806F8638: nop

    func_806F84D8(rdram, ctx);
        goto after_0;
    // 0x806F8638: nop

    after_0:
    // 0x806F863C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F8640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F8644: jr          $ra
    // 0x806F8648: nop

    return;
    // 0x806F8648: nop

;}
RECOMP_FUNC void func_80046C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046C58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80046C5C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80046C60: sll         $s1, $a1, 16
    ctx->r17 = S32(ctx->r5 << 16);
    // 0x80046C64: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80046C68: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80046C6C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80046C70: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80046C74: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80046C78: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x80046C7C: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80046C80: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80046C84: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80046C88: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80046C8C: beq         $s1, $zero, L_80046D04
    if (ctx->r17 == 0) {
        // 0x80046C90: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_80046D04;
    }
    // 0x80046C90: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80046C94: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80046C98:
    // 0x80046C98: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80046C9C: beq         $v0, $zero, L_80046CFC
    if (ctx->r2 == 0) {
        // 0x80046CA0: nop
    
            goto L_80046CFC;
    }
    // 0x80046CA0: nop

    // 0x80046CA4: beq         $s5, $v0, L_80046CF0
    if (ctx->r21 == ctx->r2) {
        // 0x80046CA8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80046CF0;
    }
    // 0x80046CA8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80046CAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80046CB0: jalr        $s4
    // 0x80046CB4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x80046CB4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x80046CB8: beq         $v0, $zero, L_80046CC8
    if (ctx->r2 == 0) {
        // 0x80046CBC: addiu       $a0, $s0, 0x188
        ctx->r4 = ADD32(ctx->r16, 0X188);
            goto L_80046CC8;
    }
    // 0x80046CBC: addiu       $a0, $s0, 0x188
    ctx->r4 = ADD32(ctx->r16, 0X188);
    // 0x80046CC0: b           L_80046D0C
    // 0x80046CC4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80046D0C;
    // 0x80046CC4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80046CC8:
    // 0x80046CC8: lh          $a1, 0x184($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X184);
    // 0x80046CCC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80046CD0: beql        $a1, $zero, L_80046CF4
    if (ctx->r5 == 0) {
        // 0x80046CD4: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80046CF4;
    }
    goto skip_0;
    // 0x80046CD4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x80046CD8: jal         0x80046C58
    // 0x80046CDC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80046C58(rdram, ctx);
        goto after_1;
    // 0x80046CDC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_1:
    // 0x80046CE0: beql        $v0, $zero, L_80046CF4
    if (ctx->r2 == 0) {
        // 0x80046CE4: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80046CF4;
    }
    goto skip_1;
    // 0x80046CE4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_1:
    // 0x80046CE8: b           L_80046D0C
    // 0x80046CEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80046D0C;
    // 0x80046CEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80046CF0:
    // 0x80046CF0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80046CF4:
    // 0x80046CF4: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80046CF8: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
L_80046CFC:
    // 0x80046CFC: bne         $s1, $zero, L_80046C98
    if (ctx->r17 != 0) {
        // 0x80046D00: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80046C98;
    }
    // 0x80046D00: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80046D04:
    // 0x80046D04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80046D08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80046D0C:
    // 0x80046D0C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80046D10: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80046D14: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80046D18: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80046D1C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80046D20: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80046D24: jr          $ra
    // 0x80046D28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80046D28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_806A28D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A28D0: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x806A28D4: lwc1        $f4, 0x10C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x806A28D8: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806A28DC: beq         $v0, $zero, L_806A293C
    if (ctx->r2 == 0) {
        // 0x806A28E0: add.s       $f0, $f4, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
            goto L_806A293C;
    }
    // 0x806A28E0: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806A28E4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806A28E8: nop

    // 0x806A28EC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806A28F0: nop

    // 0x806A28F4: bc1fl       L_806A2910
    if (!c1cs) {
        // 0x806A28F8: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_806A2910;
    }
    goto skip_0;
    // 0x806A28F8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x806A28FC: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x806A2900: andi        $t7, $t6, 0xF0
    ctx->r15 = ctx->r14 & 0XF0;
    // 0x806A2904: beql        $t7, $zero, L_806A2930
    if (ctx->r15 == 0) {
        // 0x806A2908: lwc1        $f8, 0x3C($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_806A2930;
    }
    goto skip_1;
    // 0x806A2908: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    skip_1:
    // 0x806A290C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_806A2910:
    // 0x806A2910: nop

    // 0x806A2914: bc1fl       L_806A2950
    if (!c1cs) {
        // 0x806A2918: lwc1        $f4, 0xC8($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
            goto L_806A2950;
    }
    goto skip_2;
    // 0x806A2918: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    skip_2:
    // 0x806A291C: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x806A2920: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x806A2924: bnel        $t9, $zero, L_806A2950
    if (ctx->r25 != 0) {
        // 0x806A2928: lwc1        $f4, 0xC8($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
            goto L_806A2950;
    }
    goto skip_3;
    // 0x806A2928: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    skip_3:
    // 0x806A292C: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
L_806A2930:
    // 0x806A2930: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x806A2934: b           L_806A294C
    // 0x806A2938: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
        goto L_806A294C;
    // 0x806A2938: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
L_806A293C:
    // 0x806A293C: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806A2940: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806A2944: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x806A2948: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
L_806A294C:
    // 0x806A294C: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
L_806A2950:
    // 0x806A2950: lwc1        $f6, 0x110($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X110);
    // 0x806A2954: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806A2958: lwc1        $f18, 0x44($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X44);
    // 0x806A295C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806A2960: lwc1        $f4, 0xCC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x806A2964: swc1        $f2, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f2.u32l;
    // 0x806A2968: swc1        $f2, 0x114($a0)
    MEM_W(0X114, ctx->r4) = ctx->f2.u32l;
    // 0x806A296C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x806A2970: swc1        $f2, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f2.u32l;
    // 0x806A2974: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x806A2978: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
    // 0x806A297C: jr          $ra
    // 0x806A2980: swc1        $f6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x806A2980: swc1        $f6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80517590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80517594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80517598: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
    // 0x8051759C: beql        $v0, $zero, L_805175D4
    if (ctx->r2 == 0) {
        // 0x805175A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805175D4;
    }
    goto skip_0;
    // 0x805175A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x805175A4: jalr        $v0
    // 0x805175A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x805175A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805175AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805175B0: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x805175B4: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x805175B8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x805175BC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x805175C0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805175C4: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x805175C8: b           L_805175D4
    // 0x805175CC: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
        goto L_805175D4;
    // 0x805175CC: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x805175D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805175D4:
    // 0x805175D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805175D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805175DC: jr          $ra
    // 0x805175E0: nop

    return;
    // 0x805175E0: nop

;}
RECOMP_FUNC void func_80735D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735D18: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80735D1C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80735D20: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80735D24: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80735D28: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80735D2C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80735D30: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80735D34: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80735D38: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(736, 0X3938) << 16);
    // 0x80735D3C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80735D40: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80735D44: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80735D48: lw          $t1, -0x6C68($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(736, 0X3938));
    // 0x80735D4C: jr          $ra
    // 0x80735D50: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80735D50: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80580438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8058043C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580440: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80580444: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80580448: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8058044C: lui         $t8, 0x8058
    ctx->r24 = S32(RELOC_HI16(399, 0X4524) << 16);
    // 0x80580450: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80580454: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80580458: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8058045C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80580460: lw          $t8, 0x3334($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(399, 0X4524));
    // 0x80580464: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80580468: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8058046C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80580470: jal         0x80048490
    // 0x80580474: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80580474: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80580478: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8058047C: jal         0x80048378
    // 0x80580480: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80580480: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80580484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80580488: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8058048C: jr          $ra
    // 0x80580490: nop

    return;
    // 0x80580490: nop

;}
RECOMP_FUNC void func_8046CC00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046CC00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8046CC04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8046CC08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8046CC0C: jal         0x8004700C
    // 0x8046CC10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8046CC10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8046CC14: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8046CC18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046CC1C: jal         0x80048F84
    // 0x8046CC20: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8046CC20: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x8046CC24: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8046CC28: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
    // 0x8046CC2C: lwc1        $f14, 0x3C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8046CC30: lw          $a3, 0x40($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X40);
    // 0x8046CC34: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x8046CC38: lw          $a2, 0x40($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X40);
    // 0x8046CC3C: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x8046CC40: jal         0x8046C92C
    // 0x8046CC44: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8046C92C(rdram, ctx);
        goto after_2;
    // 0x8046CC44: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x8046CC48: beq         $v0, $zero, L_8046CC5C
    if (ctx->r2 == 0) {
        // 0x8046CC4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8046CC5C;
    }
    // 0x8046CC4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046CC50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046CC54: jal         0x8046D3E8
    // 0x8046CC58: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_8046D3E8(rdram, ctx);
        goto after_3;
    // 0x8046CC58: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_3:
L_8046CC5C:
    // 0x8046CC5C: lw          $t8, 0x1E0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E0);
    // 0x8046CC60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046CC64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046CC68: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8046CC6C: slti        $at, $t9, 0x1E
    ctx->r1 = SIGNED(ctx->r25) < 0X1E ? 1 : 0;
    // 0x8046CC70: bne         $at, $zero, L_8046CCB0
    if (ctx->r1 != 0) {
        // 0x8046CC74: sw          $t9, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r25;
            goto L_8046CCB0;
    }
    // 0x8046CC74: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
    // 0x8046CC78: lbu         $t1, 0x30($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X30);
    // 0x8046CC7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8046CC80: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8046CC84: bne         $t1, $at, L_8046CC94
    if (ctx->r9 != ctx->r1) {
        // 0x8046CC88: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_8046CC94;
    }
    // 0x8046CC88: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8046CC8C: b           L_8046CC98
    // 0x8046CC90: sb          $t2, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r10;
        goto L_8046CC98;
    // 0x8046CC90: sb          $t2, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r10;
L_8046CC94:
    // 0x8046CC94: sb          $t3, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r11;
L_8046CC98:
    // 0x8046CC98: jal         0x8046D3E8
    // 0x8046CC9C: lbu         $a2, 0x30($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X30);
    func_8046D3E8(rdram, ctx);
        goto after_4;
    // 0x8046CC9C: lbu         $a2, 0x30($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X30);
    after_4:
    // 0x8046CCA0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046CCA4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8046CCA8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8046CCAC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8046CCB0:
    // 0x8046CCB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8046CCB4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8046CCB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8046CCBC: jr          $ra
    // 0x8046CCC0: nop

    return;
    // 0x8046CCC0: nop

;}
RECOMP_FUNC void func_80580868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580868: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8058086C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580870: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80580874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80580878: beq         $t6, $zero, L_805808B4
    if (ctx->r14 == 0) {
        // 0x8058087C: nop
    
            goto L_805808B4;
    }
    // 0x8058087C: nop

    // 0x80580880: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80580884: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80580888: jalr        $t9
    // 0x8058088C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8058088C: nop

    after_0:
    // 0x80580890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80580894: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80580898: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x8058089C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x805808A0: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x805808A4: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x805808A8: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x805808AC: b           L_805808B4
    // 0x805808B0: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_805808B4;
    // 0x805808B0: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_805808B4:
    // 0x805808B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805808B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805808BC: jr          $ra
    // 0x805808C0: nop

    return;
    // 0x805808C0: nop

;}
RECOMP_FUNC void func_8057F770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057F774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057F778: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8057F77C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8057F780: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8057F784: lui         $t8, 0x8058
    ctx->r24 = S32(RELOC_HI16(399, 0X41F8) << 16);
    // 0x8057F788: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8057F78C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8057F790: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8057F794: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8057F798: lw          $t8, 0x3008($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(399, 0X41F8));
    // 0x8057F79C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8057F7A0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8057F7A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8057F7A8: jal         0x80048490
    // 0x8057F7AC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8057F7AC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8057F7B0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8057F7B4: jal         0x80048378
    // 0x8057F7B8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8057F7B8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8057F7BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057F7C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057F7C4: jr          $ra
    // 0x8057F7C8: nop

    return;
    // 0x8057F7C8: nop

;}
RECOMP_FUNC void func_800784AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800784AC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800784B0: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800784B4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800784B8: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800784BC: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800784C0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800784C4: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800784C8: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800784CC: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800784D0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800784D4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800784D8: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800784DC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800784E0: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800784E4: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x800784E8: lwc1        $f22, 0x84($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800784EC: lwc1        $f20, 0x80($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800784F0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800784F4: addiu       $s6, $sp, 0x64
    ctx->r22 = ADD32(ctx->r29, 0X64);
    // 0x800784F8: lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X7C);
    // 0x800784FC: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x80078500: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x80078504: lw          $s1, 0x4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X4);
    // 0x80078508: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x8007850C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80078510: srl         $s0, $s0, 24
    ctx->r16 = S32(U32(ctx->r16) >> 24);
    // 0x80078514: blez        $s0, L_80078548
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80078518: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80078548;
    }
L_80078518:
    // 0x80078518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8007851C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80078520: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80078524: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80078528: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8007852C: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80078530: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80078534: jal         0x80078184
    // 0x80078538: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    func_80078184(rdram, ctx);
        goto after_0;
    // 0x80078538: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    after_0:
    // 0x8007853C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80078540: bgtz        $s0, L_80078518
    if (SIGNED(ctx->r16) > 0) {
        // 0x80078544: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80078518;
    }
    // 0x80078544: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_80078548:
    // 0x80078548: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8007854C: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80078550: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80078554: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80078558: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8007855C: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80078560: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80078564: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80078568: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8007856C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80078570: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80078574: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80078578: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8007857C: jr          $ra
    // 0x80078580: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80078580: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80536534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536534: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536538: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053653C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536540: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536544: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536548: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053654C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536550: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536554: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536558: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053655C: jr          $ra
    // 0x80536560: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536560: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8001A8A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A8A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001A8A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001A8A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001A8AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A8B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001A8B4: beq         $a0, $zero, L_8001A8EC
    if (ctx->r4 == 0) {
        // 0x8001A8B8: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8001A8EC;
    }
    // 0x8001A8B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001A8BC: jal         0x8001AA08
    // 0x8001A8C0: nop

    func_8001AA08(rdram, ctx);
        goto after_0;
    // 0x8001A8C0: nop

    after_0:
    // 0x8001A8C4: beq         $v0, $zero, L_8001A8DC
    if (ctx->r2 == 0) {
        // 0x8001A8C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001A8DC;
    }
    // 0x8001A8C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001A8CC: jal         0x8001A900
    // 0x8001A8D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8001A900(rdram, ctx);
        goto after_1;
    // 0x8001A8D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8001A8D4: jal         0x8001A4D4
    // 0x8001A8D8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_8001A4D4(rdram, ctx);
        goto after_2;
    // 0x8001A8D8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_2:
L_8001A8DC:
    // 0x8001A8DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001A8E0: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    // 0x8001A8E4: jal         0x8001AA4C
    // 0x8001A8E8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_8001AA4C(rdram, ctx);
        goto after_3;
    // 0x8001A8E8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_3:
L_8001A8EC:
    // 0x8001A8EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A8F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001A8F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001A8F8: jr          $ra
    // 0x8001A8FC: nop

    return;
    // 0x8001A8FC: nop

;}
RECOMP_FUNC void func_80410AF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80410AF4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80410AF8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80410AFC: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80410B00: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80410B04: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80410B08: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80410B0C: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80410B10: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80410B14: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80410B18: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80410B1C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80410B20: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80410B24: addu        $a3, $a1, $at
    ctx->r7 = ADD32(ctx->r5, ctx->r1);
    // 0x80410B28: lw          $t6, 0x39CC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39CC);
    // 0x80410B2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410B30: ori         $at, $zero, 0xB9C0
    ctx->r1 = 0 | 0XB9C0;
    // 0x80410B34: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80410B38: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80410B3C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80410B40: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x80410B44: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80410B48: addu        $t6, $a1, $at
    ctx->r14 = ADD32(ctx->r5, ctx->r1);
    // 0x80410B4C: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x80410B50: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80410B54: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80410B58: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410B5C: sll         $t7, $t7, 9
    ctx->r15 = S32(ctx->r15 << 9);
    // 0x80410B60: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x80410B64: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80410B68: lui         $t0, 0xF510
    ctx->r8 = S32(0XF510 << 16);
    // 0x80410B6C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80410B70: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x80410B74: ori         $t0, $t0, 0x3F4
    ctx->r8 = ctx->r8 | 0X3F4;
    // 0x80410B78: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80410B7C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80410B80: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80410B84: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410B88: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x80410B8C: lui         $t8, 0xF400
    ctx->r24 = S32(0XF400 << 16);
    // 0x80410B90: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80410B94: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80410B98: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80410B9C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80410BA0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410BA4: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80410BA8: ori         $t9, $t9, 0x4004
    ctx->r25 = ctx->r25 | 0X4004;
    // 0x80410BAC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80410BB0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80410BB4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80410BB8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80410BBC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410BC0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80410BC4: lui         $t9, 0x108
    ctx->r25 = S32(0X108 << 16);
    // 0x80410BC8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80410BCC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80410BD0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80410BD4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80410BD8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410BDC: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80410BE0: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x80410BE4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80410BE8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80410BEC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80410BF0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80410BF4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410BF8: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x80410BFC: ori         $t8, $t8, 0x4004
    ctx->r24 = ctx->r24 | 0X4004;
    // 0x80410C00: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80410C04: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80410C08: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80410C0C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80410C10: addiu       $t5, $v1, 0x5C0
    ctx->r13 = ADD32(ctx->r3, 0X5C0);
    // 0x80410C14: addiu       $s1, $v1, 0x5FC0
    ctx->r17 = ADD32(ctx->r3, 0X5FC0);
    // 0x80410C18: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80410C1C: lw          $v1, 0x39E4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X39E4);
    // 0x80410C20: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80410C24: lui         $fp, 0xFD10
    ctx->r30 = S32(0XFD10 << 16);
    // 0x80410C28: beq         $v1, $zero, L_80410EBC
    if (ctx->r3 == 0) {
        // 0x80410C2C: lui         $ra, 0x700
        ctx->r31 = S32(0X700 << 16);
            goto L_80410EBC;
    }
    // 0x80410C2C: lui         $ra, 0x700
    ctx->r31 = S32(0X700 << 16);
    // 0x80410C30: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
    // 0x80410C34: lui         $s3, 0xBB00
    ctx->r19 = S32(0XBB00 << 16);
    // 0x80410C38: ori         $s3, $s3, 0x1
    ctx->r19 = ctx->r19 | 0X1;
    // 0x80410C3C: ori         $s4, $s4, 0x8000
    ctx->r20 = ctx->r20 | 0X8000;
    // 0x80410C40: lw          $v0, 0x39E8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X39E8);
    // 0x80410C44: lui         $s5, 0xBF00
    ctx->r21 = S32(0XBF00 << 16);
    // 0x80410C48: lui         $s2, 0xF510
    ctx->r18 = S32(0XF510 << 16);
L_80410C4C:
    // 0x80410C4C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80410C50: beq         $v0, $zero, L_80410EA0
    if (ctx->r2 == 0) {
        // 0x80410C54: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_80410EA0;
    }
    // 0x80410C54: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80410C58: sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9 << 2);
    // 0x80410C5C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80410C60: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80410C64: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80410C68: or          $s6, $v0, $at
    ctx->r22 = ctx->r2 | ctx->r1;
    // 0x80410C6C: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80410C70: or          $s7, $v0, $at
    ctx->r23 = ctx->r2 | ctx->r1;
L_80410C74:
    // 0x80410C74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410C78: sll         $a2, $t0, 2
    ctx->r6 = S32(ctx->r8 << 2);
    // 0x80410C7C: andi        $a2, $a2, 0xFFF
    ctx->r6 = ctx->r6 & 0XFFF;
    // 0x80410C80: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80410C84: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80410C88: lw          $t6, 0x39D4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39D4);
    // 0x80410C8C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80410C90: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80410C94: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80410C98: or          $t9, $t8, $fp
    ctx->r25 = ctx->r24 | ctx->r30;
    // 0x80410C9C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80410CA0: lw          $t6, 0x39C8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39C8);
    // 0x80410CA4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80410CA8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410CAC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80410CB0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80410CB4: lw          $t8, 0x39DC($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X39DC);
    // 0x80410CB8: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x80410CBC: subu        $t6, $t9, $t1
    ctx->r14 = SUB32(ctx->r25, ctx->r9);
    // 0x80410CC0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80410CC4: addiu       $t8, $t7, 0x7
    ctx->r24 = ADD32(ctx->r15, 0X7);
    // 0x80410CC8: srl         $t9, $t8, 3
    ctx->r25 = S32(U32(ctx->r24) >> 3);
    // 0x80410CCC: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x80410CD0: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x80410CD4: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x80410CD8: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80410CDC: or          $t8, $t7, $s2
    ctx->r24 = ctx->r15 | ctx->r18;
    // 0x80410CE0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80410CE4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80410CE8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410CEC: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80410CF0: or          $t9, $s6, $a2
    ctx->r25 = ctx->r22 | ctx->r6;
    // 0x80410CF4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80410CF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80410CFC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80410D00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80410D04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410D08: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80410D0C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80410D10: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80410D14: lw          $t6, 0x39E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39E0);
    // 0x80410D18: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x80410D1C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80410D20: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80410D24: lw          $t8, 0x39DC($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X39DC);
    // 0x80410D28: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80410D2C: or          $t7, $t6, $ra
    ctx->r15 = ctx->r14 | ctx->r31;
    // 0x80410D30: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x80410D34: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x80410D38: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80410D3C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80410D40: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80410D44: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80410D48: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80410D4C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410D50: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80410D54: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80410D58: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80410D5C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80410D60: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80410D64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410D68: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80410D6C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80410D70: lw          $t8, 0x39DC($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X39DC);
    // 0x80410D74: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x80410D78: subu        $t7, $t9, $t1
    ctx->r15 = SUB32(ctx->r25, ctx->r9);
    // 0x80410D7C: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x80410D80: addiu       $t8, $t6, 0x7
    ctx->r24 = ADD32(ctx->r14, 0X7);
    // 0x80410D84: srl         $t9, $t8, 3
    ctx->r25 = S32(U32(ctx->r24) >> 3);
    // 0x80410D88: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x80410D8C: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x80410D90: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80410D94: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80410D98: or          $t8, $t6, $s2
    ctx->r24 = ctx->r14 | ctx->r18;
    // 0x80410D9C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80410DA0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80410DA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410DA8: or          $t6, $s7, $a2
    ctx->r14 = ctx->r23 | ctx->r6;
    // 0x80410DAC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80410DB0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80410DB4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80410DB8: lw          $t8, 0x39E0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X39E0);
    // 0x80410DBC: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80410DC0: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x80410DC4: lw          $t9, 0x39DC($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X39DC);
    // 0x80410DC8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80410DCC: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80410DD0: addu        $t7, $t1, $t9
    ctx->r15 = ADD32(ctx->r9, ctx->r25);
    // 0x80410DD4: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x80410DD8: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80410DDC: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80410DE0: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x80410DE4: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80410DE8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80410DEC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410DF0: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80410DF4: ori         $t8, $t8, 0x103F
    ctx->r24 = ctx->r24 | 0X103F;
    // 0x80410DF8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80410DFC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80410E00: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80410E04: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80410E08: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410E0C: lui         $t9, 0x408
    ctx->r25 = S32(0X408 << 16);
    // 0x80410E10: ori         $t9, $t9, 0x103F
    ctx->r25 = ctx->r25 | 0X103F;
    // 0x80410E14: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80410E18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80410E1C: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80410E20: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80410E24: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410E28: addiu       $t6, $zero, 0x402
    ctx->r14 = ADD32(0, 0X402);
    // 0x80410E2C: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x80410E30: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80410E34: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80410E38: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x80410E3C: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80410E40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410E44: addiu       $t5, $t5, 0x40
    ctx->r13 = ADD32(ctx->r13, 0X40);
    // 0x80410E48: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80410E4C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80410E50: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80410E54: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80410E58: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410E5C: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80410E60: ori         $t8, $t8, 0x406
    ctx->r24 = ctx->r24 | 0X406;
    // 0x80410E64: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80410E68: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80410E6C: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x80410E70: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80410E74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410E78: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80410E7C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80410E80: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80410E84: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80410E88: lw          $v0, 0x39E8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X39E8);
    // 0x80410E8C: lw          $t6, 0x39E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39E0);
    // 0x80410E90: sltu        $at, $t4, $v0
    ctx->r1 = ctx->r12 < ctx->r2 ? 1 : 0;
    // 0x80410E94: bne         $at, $zero, L_80410C74
    if (ctx->r1 != 0) {
        // 0x80410E98: addu        $t0, $t0, $t6
        ctx->r8 = ADD32(ctx->r8, ctx->r14);
            goto L_80410C74;
    }
    // 0x80410E98: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x80410E9C: lw          $v1, 0x39E4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X39E4);
L_80410EA0:
    // 0x80410EA0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80410EA4: lw          $t9, 0x39DC($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X39DC);
    // 0x80410EA8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80410EAC: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80410EB0: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80410EB4: bne         $at, $zero, L_80410C4C
    if (ctx->r1 != 0) {
        // 0x80410EB8: addu        $t1, $t1, $t9
        ctx->r9 = ADD32(ctx->r9, ctx->r25);
            goto L_80410C4C;
    }
    // 0x80410EB8: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
L_80410EBC:
    // 0x80410EBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80410EC0: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80410EC4: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80410EC8: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80410ECC: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80410ED0: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80410ED4: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80410ED8: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80410EDC: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x80410EE0: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80410EE4: jr          $ra
    // 0x80410EE8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80410EE8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8003DF18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DF18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DF1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DF20: jal         0x8003DE00
    // 0x8003DF24: nop

    func_8003DE00(rdram, ctx);
        goto after_0;
    // 0x8003DF24: nop

    after_0:
    // 0x8003DF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DF2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DF30: jr          $ra
    // 0x8003DF34: nop

    return;
    // 0x8003DF34: nop

;}
RECOMP_FUNC void func_80429360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80429364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80429368: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042936C: jal         0x80045A34
    // 0x80429370: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80429370: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80429374: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80429378: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8042937C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80429380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80429384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80429388: jr          $ra
    // 0x8042938C: nop

    return;
    // 0x8042938C: nop

;}
RECOMP_FUNC void func_80447E2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447E2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447E30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80447E34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80447E38: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80447E3C: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80447E40: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80447E44: lui         $t0, 0x8045
    ctx->r8 = S32(RELOC_HI16(98, 0X13330) << 16);
    // 0x80447E48: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80447E4C: lw          $v1, 0x6CA8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CA8);
    // 0x80447E50: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x80447E54: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80447E58: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80447E5C: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80447E60: lw          $t0, 0x7710($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(98, 0X13330));
    // 0x80447E64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80447E68: beql        $t0, $zero, L_80447E7C
    if (ctx->r8 == 0) {
        // 0x80447E6C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80447E7C;
    }
    goto skip_0;
    // 0x80447E6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80447E70: jalr        $t0
    // 0x80447E74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
        goto after_0;
    // 0x80447E74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80447E78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80447E7C:
    // 0x80447E7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447E80: jr          $ra
    // 0x80447E84: nop

    return;
    // 0x80447E84: nop

;}
RECOMP_FUNC void func_8064CA2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064CA2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064CA30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064CA34: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064CA38: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064CA3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064CA40: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064CA44: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8064CA48: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064CA4C: nop

    // 0x8064CA50: bc1fl       L_8064CA64
    if (!c1cs) {
        // 0x8064CA54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064CA64;
    }
    goto skip_0;
    // 0x8064CA54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064CA58: jal         0x8064CD50
    // 0x8064CA5C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064CD50(rdram, ctx);
        goto after_0;
    // 0x8064CA5C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064CA60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064CA64:
    // 0x8064CA64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064CA68: jr          $ra
    // 0x8064CA6C: nop

    return;
    // 0x8064CA6C: nop

;}
RECOMP_FUNC void guScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800826E4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800826E8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800826EC: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800826F0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800826F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800826F8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800826FC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80082700: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80082704: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80082708: jal         0x80082690
    // 0x8008270C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    guScaleF(rdram, ctx);
        goto after_0;
    // 0x8008270C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80082710: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80082714: jal         0x80086DA0
    // 0x80082718: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x80082718: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x8008271C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80082720: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80082724: jr          $ra
    // 0x80082728: nop

    return;
    // 0x80082728: nop

;}
RECOMP_FUNC void func_8003E0D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E0D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E0D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E0DC: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8003E0E0: lbu         $t6, 0x11($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X11);
    // 0x8003E0E4: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8003E0E8: beql        $at, $zero, L_8003E100
    if (ctx->r1 == 0) {
        // 0x8003E0EC: lw          $t9, 0x1C($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X1C);
            goto L_8003E100;
    }
    goto skip_0;
    // 0x8003E0EC: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    skip_0:
    // 0x8003E0F0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8003E0F4: beql        $t7, $zero, L_8003E114
    if (ctx->r15 == 0) {
        // 0x8003E0F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003E114;
    }
    goto skip_1;
    // 0x8003E0F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8003E0FC: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
L_8003E100:
    // 0x8003E100: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003E104: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x8003E108: jalr        $t9
    // 0x8003E10C: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8003E10C: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x8003E110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003E114:
    // 0x8003E114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E118: jr          $ra
    // 0x8003E11C: nop

    return;
    // 0x8003E11C: nop

;}
RECOMP_FUNC void func_80530DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530DF0: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x80530DF4: addiu       $t6, $v1, -0x440B
    ctx->r14 = ADD32(ctx->r3, -0X440B);
    // 0x80530DF8: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80530DFC: beq         $at, $zero, L_80530E30
    if (ctx->r1 == 0) {
        // 0x80530E00: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80530E30;
    }
    // 0x80530E00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80530E04: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X19E0) << 16);
    // 0x80530E08: addu        $at, $at, $t6
    gpr jr_addend_80530E10 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80530E0C: lw          $t6, 0x27D0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(342, 0X19E0));
    // 0x80530E10: jr          $t6
    // 0x80530E14: nop

    switch (jr_addend_80530E10 >> 2) {
        case 0: goto L_80530E18; break;
        case 1: goto L_80530E24; break;
        case 2: goto L_80530E24; break;
        case 3: goto L_80530E24; break;
        case 4: goto L_80530E24; break;
        default: switch_error(__func__, 0x80530E10, 0x805327D0);
    }
    // 0x80530E14: nop

L_80530E18:
    // 0x80530E18: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(342, 0X17C0) << 16);
    // 0x80530E1C: jr          $ra
    // 0x80530E20: addiu       $v0, $v0, 0x25B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(342, 0X17C0));
    return;
    // 0x80530E20: addiu       $v0, $v0, 0x25B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(342, 0X17C0));
L_80530E24:
    // 0x80530E24: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(342, 0X163C) << 16);
    // 0x80530E28: jr          $ra
    // 0x80530E2C: addiu       $v0, $v0, 0x242C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(342, 0X163C));
    return;
    // 0x80530E2C: addiu       $v0, $v0, 0x242C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(342, 0X163C));
L_80530E30:
    // 0x80530E30: slti        $at, $v1, 0x4302
    ctx->r1 = SIGNED(ctx->r3) < 0X4302 ? 1 : 0;
    // 0x80530E34: bne         $at, $zero, L_80530E4C
    if (ctx->r1 != 0) {
        // 0x80530E38: slti        $at, $v1, 0x4395
        ctx->r1 = SIGNED(ctx->r3) < 0X4395 ? 1 : 0;
            goto L_80530E4C;
    }
    // 0x80530E38: slti        $at, $v1, 0x4395
    ctx->r1 = SIGNED(ctx->r3) < 0X4395 ? 1 : 0;
    // 0x80530E3C: beq         $at, $zero, L_80530E4C
    if (ctx->r1 == 0) {
        // 0x80530E40: lui         $v0, 0x8053
        ctx->r2 = S32(RELOC_HI16(342, 0X1048) << 16);
            goto L_80530E4C;
    }
    // 0x80530E40: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(342, 0X1048) << 16);
    // 0x80530E44: jr          $ra
    // 0x80530E48: addiu       $v0, $v0, 0x1E38
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(342, 0X1048));
    return;
    // 0x80530E48: addiu       $v0, $v0, 0x1E38
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(342, 0X1048));
L_80530E4C:
    // 0x80530E4C: slti        $at, $v1, 0x43C1
    ctx->r1 = SIGNED(ctx->r3) < 0X43C1 ? 1 : 0;
    // 0x80530E50: bne         $at, $zero, L_80530E70
    if (ctx->r1 != 0) {
        // 0x80530E54: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80530E70;
    }
    // 0x80530E54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80530E58: slti        $at, $v1, 0x43EB
    ctx->r1 = SIGNED(ctx->r3) < 0X43EB ? 1 : 0;
    // 0x80530E5C: beq         $at, $zero, L_80530E70
    if (ctx->r1 == 0) {
        // 0x80530E60: nop
    
            goto L_80530E70;
    }
    // 0x80530E60: nop

    // 0x80530E64: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(342, 0X1514) << 16);
    // 0x80530E68: jr          $ra
    // 0x80530E6C: addiu       $v0, $v0, 0x2304
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(342, 0X1514));
    return;
    // 0x80530E6C: addiu       $v0, $v0, 0x2304
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(342, 0X1514));
L_80530E70:
    // 0x80530E70: jr          $ra
    // 0x80530E74: nop

    return;
    // 0x80530E74: nop

;}
RECOMP_FUNC void func_80039DB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039DB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039DB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039DBC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039DC0: jal         0x80046790
    // 0x80039DC4: lw          $a0, 0x426C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X426C);
    func_80046790(rdram, ctx);
        goto after_0;
    // 0x80039DC4: lw          $a0, 0x426C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X426C);
    after_0:
    // 0x80039DC8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039DCC: jal         0x80046790
    // 0x80039DD0: lw          $a0, 0x4274($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4274);
    func_80046790(rdram, ctx);
        goto after_1;
    // 0x80039DD0: lw          $a0, 0x4274($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4274);
    after_1:
    // 0x80039DD4: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039DD8: jal         0x80046790
    // 0x80039DDC: lw          $a0, 0x4278($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4278);
    func_80046790(rdram, ctx);
        goto after_2;
    // 0x80039DDC: lw          $a0, 0x4278($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4278);
    after_2:
    // 0x80039DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039DE8: jr          $ra
    // 0x80039DEC: nop

    return;
    // 0x80039DEC: nop

;}
RECOMP_FUNC void func_80411588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80411588: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8041158C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80411590: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x80411594: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80411598: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x8041159C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x804115A0: addu        $s4, $a0, $at
    ctx->r20 = ADD32(ctx->r4, ctx->r1);
    // 0x804115A4: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x804115A8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x804115AC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x804115B0: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x804115B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804115B8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x804115BC: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x804115C0: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x804115C4: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x804115C8: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x804115CC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804115D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x804115D4: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x804115D8: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x804115DC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x804115E0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x804115E4: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x804115E8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804115EC: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x804115F0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x804115F4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x804115F8: lw          $s7, 0x1E0($a1)
    ctx->r23 = MEM_W(ctx->r5, 0X1E0);
    // 0x804115FC: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x80411600: addiu       $s5, $zero, -0xBB8
    ctx->r21 = ADD32(0, -0XBB8);
    // 0x80411604: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_80411608:
    // 0x80411608: lui         $at, 0xC320
    ctx->r1 = S32(0XC320 << 16);
    // 0x8041160C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80411610: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80411614: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80411618: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8041161C: add.s       $f0, $f24, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f24.fl + ctx->f4.fl;
    // 0x80411620: mul.s       $f30, $f0, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f30.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80411624: nop

L_80411628:
    // 0x80411628: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8041162C: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(26, 0X2488) << 16);
    // 0x80411630: lwc1        $f8, 0x1B08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(26, 0X2488));
    // 0x80411634: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80411638: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8041163C: lw          $t7, 0x39E8($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X39E8);
    // 0x80411640: add.s       $f0, $f6, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f30.fl;
    // 0x80411644: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80411648: multu       $t8, $s2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8041164C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80411650: mflo        $t9
    ctx->r25 = lo;
    // 0x80411654: addu        $s0, $t9, $s6
    ctx->r16 = ADD32(ctx->r25, ctx->r22);
    // 0x80411658: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8041165C: nop

    // 0x80411660: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80411664: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80411668: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8041166C: nop

    // 0x80411670: addu        $v0, $s7, $t1
    ctx->r2 = ADD32(ctx->r23, ctx->r9);
    // 0x80411674: addiu       $v0, $v0, -0x3C
    ctx->r2 = ADD32(ctx->r2, -0X3C);
    // 0x80411678: blez        $v0, L_80411754
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8041167C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80411754;
    }
    // 0x8041167C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80411680: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x80411684: beq         $at, $zero, L_8041173C
    if (ctx->r1 == 0) {
        // 0x80411688: nop
    
            goto L_8041173C;
    }
    // 0x80411688: nop

    // 0x8041168C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80411690: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80411694: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80411698: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8041169C: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804116A0: jal         0x80066E88
    // 0x804116A4: nop

    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x804116A4: nop

    after_0:
    // 0x804116A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x804116AC: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x804116B0: c.le.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl <= ctx->f20.fl;
    // 0x804116B4: nop

    // 0x804116B8: bc1fl       L_804116F0
    if (!c1cs) {
        // 0x804116BC: sub.s       $f2, $f26, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f26.fl - ctx->f0.fl;
            goto L_804116F0;
    }
    goto skip_0;
    // 0x804116BC: sub.s       $f2, $f26, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f26.fl - ctx->f0.fl;
    skip_0:
    // 0x804116C0: sub.s       $f2, $f26, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f26.fl - ctx->f0.fl;
    // 0x804116C4: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804116C8: mul.s       $f18, $f2, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f28.fl);
    // 0x804116CC: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x804116D0: mflo        $t2
    ctx->r10 = lo;
    // 0x804116D4: addu        $v0, $s1, $t2
    ctx->r2 = ADD32(ctx->r17, ctx->r10);
    // 0x804116D8: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x804116DC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804116E0: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x804116E4: b           L_80411718
    // 0x804116E8: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
        goto L_80411718;
    // 0x804116E8: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x804116EC: sub.s       $f2, $f26, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f26.fl - ctx->f0.fl;
L_804116F0:
    // 0x804116F0: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804116F4: mul.s       $f10, $f2, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f28.fl);
    // 0x804116F8: sub.s       $f16, $f20, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f20.fl - ctx->f10.fl;
    // 0x804116FC: mflo        $t5
    ctx->r13 = lo;
    // 0x80411700: addu        $v0, $s1, $t5
    ctx->r2 = ADD32(ctx->r17, ctx->r13);
    // 0x80411704: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x80411708: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8041170C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80411710: nop

    // 0x80411714: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
L_80411718:
    // 0x80411718: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8041171C: nop

    // 0x80411720: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80411724: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x80411728: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8041172C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80411730: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80411734: b           L_80411784
    // 0x80411738: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
        goto L_80411784;
    // 0x80411738: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
L_8041173C:
    // 0x8041173C: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80411740: mflo        $t0
    ctx->r8 = lo;
    // 0x80411744: addu        $v0, $s1, $t0
    ctx->r2 = ADD32(ctx->r17, ctx->r8);
    // 0x80411748: sh          $s5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r21;
    // 0x8041174C: b           L_80411784
    // 0x80411750: sh          $s5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r21;
        goto L_80411784;
    // 0x80411750: sh          $s5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r21;
L_80411754:
    // 0x80411754: mul.s       $f4, $f20, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x80411758: nop

    // 0x8041175C: mul.s       $f8, $f24, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f22.fl);
    // 0x80411760: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80411764: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80411768: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8041176C: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80411770: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80411774: mflo        $t1
    ctx->r9 = lo;
    // 0x80411778: addu        $v0, $s1, $t1
    ctx->r2 = ADD32(ctx->r17, ctx->r9);
    // 0x8041177C: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x80411780: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
L_80411784:
    // 0x80411784: lw          $t6, 0x39DC($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X39DC);
    // 0x80411788: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8041178C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80411790: bgez        $t6, L_804117A4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80411794: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_804117A4;
    }
    // 0x80411794: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80411798: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8041179C: nop

    // 0x804117A0: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_804117A4:
    // 0x804117A4: lw          $v0, 0x39E4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X39E4);
    // 0x804117A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x804117AC: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x804117B0: sltu        $at, $v0, $s2
    ctx->r1 = ctx->r2 < ctx->r18 ? 1 : 0;
    // 0x804117B4: beq         $at, $zero, L_80411628
    if (ctx->r1 == 0) {
        // 0x804117B8: nop
    
            goto L_80411628;
    }
    // 0x804117B8: nop

    // 0x804117BC: lw          $t7, 0x39E0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X39E0);
    // 0x804117C0: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x804117C4: lw          $v1, 0x39E8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X39E8);
    // 0x804117C8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x804117CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x804117D0: bgez        $t7, L_804117E4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x804117D4: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_804117E4;
    }
    // 0x804117D4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804117D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804117DC: nop

    // 0x804117E0: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_804117E4:
    // 0x804117E4: sltu        $at, $v1, $s6
    ctx->r1 = ctx->r3 < ctx->r22 ? 1 : 0;
    // 0x804117E8: beq         $at, $zero, L_80411608
    if (ctx->r1 == 0) {
        // 0x804117EC: add.s       $f24, $f24, $f8
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f8.fl;
            goto L_80411608;
    }
    // 0x804117EC: add.s       $f24, $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f8.fl;
    // 0x804117F0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x804117F4: lw          $v0, 0x1E0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X1E0);
    // 0x804117F8: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x804117FC: sw          $t9, 0x1E0($t8)
    MEM_W(0X1E0, ctx->r24) = ctx->r25;
    // 0x80411800: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80411804: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x80411808: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x8041180C: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x80411810: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x80411814: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80411818: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8041181C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80411820: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80411824: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80411828: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8041182C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80411830: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80411834: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80411838: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8041183C: jr          $ra
    // 0x80411840: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80411840: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_807C2D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C2D50: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x807C2D54: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x807C2D58: lui         $t7, 0x807C
    ctx->r15 = S32(RELOC_HI16(901, 0X180) << 16);
    // 0x807C2D5C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x807C2D60: addiu       $t7, $t7, 0x2E60
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(901, 0X180));
    // 0x807C2D64: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807C2D68: lui         $t9, 0x807C
    ctx->r25 = S32(RELOC_HI16(901, 0X20) << 16);
    // 0x807C2D6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C2D70: addiu       $t9, $t9, 0x2D00
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(901, 0X20));
    // 0x807C2D74: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807C2D78: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807C2D7C: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x807C2D80: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x807C2D84: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(901, 0X1A4) << 16);
    // 0x807C2D88: lwc1        $f4, 0x2E84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(901, 0X1A4));
    // 0x807C2D8C: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(901, 0X1A8) << 16);
    // 0x807C2D90: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x807C2D94: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x807C2D98: lwc1        $f6, 0x2E88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(901, 0X1A8));
    // 0x807C2D9C: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x807C2DA0: addiu       $t1, $zero, 0x48
    ctx->r9 = ADD32(0, 0X48);
    // 0x807C2DA4: sw          $t0, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r8;
    // 0x807C2DA8: sw          $t1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r9;
    // 0x807C2DAC: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x807C2DB0: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
    // 0x807C2DB4: lw          $t2, -0x7BC4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7BC4);
    // 0x807C2DB8: lui         $t3, 0x807C
    ctx->r11 = S32(RELOC_HI16(901, 0X188) << 16);
    // 0x807C2DBC: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x807C2DC0: lw          $v1, 0x10C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X10C);
    // 0x807C2DC4: lui         $t4, 0x807C
    ctx->r12 = S32(RELOC_HI16(901, 0X18C) << 16);
    // 0x807C2DC8: lui         $t5, 0x807C
    ctx->r13 = S32(RELOC_HI16(901, 0X190) << 16);
    // 0x807C2DCC: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x807C2DD0: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x807C2DD4: lbu         $t3, 0x2E68($t3)
    ctx->r11 = MEM_BU(ctx->r11, (int16_t)RELOC_LO16(901, 0X188));
    // 0x807C2DD8: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x807C2DDC: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x807C2DE0: sb          $t3, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r11;
    // 0x807C2DE4: lbu         $t4, 0x2E6C($t4)
    ctx->r12 = MEM_BU(ctx->r12, (int16_t)RELOC_LO16(901, 0X18C));
    // 0x807C2DE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807C2DEC: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x807C2DF0: sb          $t4, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r12;
    // 0x807C2DF4: lbu         $t5, 0x2E70($t5)
    ctx->r13 = MEM_BU(ctx->r13, (int16_t)RELOC_LO16(901, 0X190));
    // 0x807C2DF8: sb          $t5, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r13;
    // 0x807C2DFC: jr          $ra
    // 0x807C2E00: sb          $a1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r5;
    return;
    // 0x807C2E00: sb          $a1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_80035D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035D2C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80035D30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80035D34: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80035D38: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80035D3C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80035D40: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80035D44: jal         0x800356E8
    // 0x80035D48: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800356E8(rdram, ctx);
        goto after_0;
    // 0x80035D48: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80035D4C: addiu       $t6, $zero, 0x27
    ctx->r14 = ADD32(0, 0X27);
    // 0x80035D50: addiu       $t7, $zero, 0x3E
    ctx->r15 = ADD32(0, 0X3E);
    // 0x80035D54: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80035D58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80035D5C: addiu       $a0, $sp, 0x4F
    ctx->r4 = ADD32(ctx->r29, 0X4F);
    // 0x80035D60: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80035D64: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80035D68: jal         0x80035A70
    // 0x80035D6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80035A70(rdram, ctx);
        goto after_1;
    // 0x80035D6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80035D70: bne         $v0, $zero, L_80035D88
    if (ctx->r2 != 0) {
        // 0x80035D74: addiu       $a0, $sp, 0x4F
        ctx->r4 = ADD32(ctx->r29, 0X4F);
            goto L_80035D88;
    }
    // 0x80035D74: addiu       $a0, $sp, 0x4F
    ctx->r4 = ADD32(ctx->r29, 0X4F);
    // 0x80035D78: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80035D7C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80035D80: jal         0x800358B8
    // 0x80035D84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800358B8(rdram, ctx);
        goto after_2;
    // 0x80035D84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
L_80035D88:
    // 0x80035D88: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80035D8C: lbu         $a1, 0x4F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X4F);
    // 0x80035D90: jal         0x8002DBE4
    // 0x80035D94: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_3;
    // 0x80035D94: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_3:
    // 0x80035D98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80035D9C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80035DA0: jr          $ra
    // 0x80035DA4: nop

    return;
    // 0x80035DA4: nop

;}
RECOMP_FUNC void func_80069610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069614: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80069618: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8006961C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069620: addiu       $t8, $t8, 0x7EA0
    ctx->r24 = ADD32(ctx->r24, 0X7EA0);
    // 0x80069624: addiu       $t7, $t6, 0xFC2
    ctx->r15 = ADD32(ctx->r14, 0XFC2);
    // 0x80069628: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x8006962C: jal         0x80069508
    // 0x80069630: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_80069508(rdram, ctx);
        goto after_0;
    // 0x80069630: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x80069634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006963C: jr          $ra
    // 0x80069640: nop

    return;
    // 0x80069640: nop

;}
RECOMP_FUNC void func_8044D680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044D680: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8044D684: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    // 0x8044D688: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8044D68C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8044D690: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8044D694: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8044D698: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8044D69C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8044D6A0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8044D6A4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8044D6A8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8044D6AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8044D6B0: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x8044D6B4: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x8044D6B8: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    // 0x8044D6BC: sw          $a3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r7;
    // 0x8044D6C0: lw          $s2, 0x1F4($t6)
    ctx->r18 = MEM_W(ctx->r14, 0X1F4);
    // 0x8044D6C4: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8044D6C8: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x8044D6CC: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8044D6D0: lw          $v0, 0x6980($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6980);
    // 0x8044D6D4: lw          $fp, 0xA60($s2)
    ctx->r30 = MEM_W(ctx->r18, 0XA60);
    // 0x8044D6D8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8044D6DC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8044D6E0: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x8044D6E4: addiu       $s7, $sp, 0x80
    ctx->r23 = ADD32(ctx->r29, 0X80);
    // 0x8044D6E8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8044D6EC: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
L_8044D6F0:
    // 0x8044D6F0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8044D6F4: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x8044D6F8: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8044D6FC: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
    // 0x8044D700: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x8044D704: lw          $t5, 0xF0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF0);
    // 0x8044D708: beq         $s0, $zero, L_8044D7E0
    if (ctx->r16 == 0) {
        // 0x8044D70C: addiu       $v0, $s2, 0xA64
        ctx->r2 = ADD32(ctx->r18, 0XA64);
            goto L_8044D7E0;
    }
    // 0x8044D70C: addiu       $v0, $s2, 0xA64
    ctx->r2 = ADD32(ctx->r18, 0XA64);
    // 0x8044D710: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8044D714: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8044D718: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x8044D71C: beq         $a2, $zero, L_8044D76C
    if (ctx->r6 == 0) {
        // 0x8044D720: addu        $s4, $t4, $s3
        ctx->r20 = ADD32(ctx->r12, ctx->r19);
            goto L_8044D76C;
    }
    // 0x8044D720: addu        $s4, $t4, $s3
    ctx->r20 = ADD32(ctx->r12, ctx->r19);
    // 0x8044D724: addiu       $s1, $fp, 0x1
    ctx->r17 = ADD32(ctx->r30, 0X1);
    // 0x8044D728: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8044D72C: lw          $a3, 0x2A0($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X2A0);
    // 0x8044D730: sll         $t7, $fp, 2
    ctx->r15 = S32(ctx->r30 << 2);
    // 0x8044D734: addu        $s6, $v0, $t7
    ctx->r22 = ADD32(ctx->r2, ctx->r15);
    // 0x8044D738: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8044D73C: jal         0x8044D140
    // 0x8044D740: addu        $s5, $v0, $t6
    ctx->r21 = ADD32(ctx->r2, ctx->r14);
    func_8044D140(rdram, ctx);
        goto after_0;
    // 0x8044D740: addu        $s5, $v0, $t6
    ctx->r21 = ADD32(ctx->r2, ctx->r14);
    after_0:
    // 0x8044D744: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8044D748: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8044D74C: jal         0x8044CCE4
    // 0x8044D750: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    func_8044CCE4(rdram, ctx);
        goto after_1;
    // 0x8044D750: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_1:
    // 0x8044D754: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8044D758: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8044D75C: jal         0x8044C360
    // 0x8044D760: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_8044C360(rdram, ctx);
        goto after_2;
    // 0x8044D760: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_2:
    // 0x8044D764: sw          $s7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r23;
    // 0x8044D768: sw          $s1, 0xA60($s2)
    MEM_W(0XA60, ctx->r18) = ctx->r17;
L_8044D76C:
    // 0x8044D76C: lw          $t8, 0xE8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE8);
    // 0x8044D770: lw          $t2, 0xE4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE4);
    // 0x8044D774: lw          $t3, 0x1E0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X1E0);
    // 0x8044D778: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8044D77C: lw          $t4, 0xF0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF0);
    // 0x8044D780: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8044D784: sll         $t1, $t9, 6
    ctx->r9 = S32(ctx->r25 << 6);
    // 0x8044D788: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x8044D78C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8044D790: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x8044D794: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8044D798: jal         0x8044D1F4
    // 0x8044D79C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_8044D1F4(rdram, ctx);
        goto after_3;
    // 0x8044D79C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_3:
    // 0x8044D7A0: lw          $t5, 0xE8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE8);
    // 0x8044D7A4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8044D7A8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8044D7AC: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x8044D7B0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8044D7B4: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x8044D7B8: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8044D7BC: beql        $t1, $zero, L_8044D7CC
    if (ctx->r9 == 0) {
        // 0x8044D7C0: lw          $t2, 0x58($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X58);
            goto L_8044D7CC;
    }
    goto skip_0;
    // 0x8044D7C0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    skip_0:
    // 0x8044D7C4: sw          $fp, 0xA60($s2)
    MEM_W(0XA60, ctx->r18) = ctx->r30;
    // 0x8044D7C8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
L_8044D7CC:
    // 0x8044D7CC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8044D7D0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8044D7D4: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8044D7D8: bne         $s3, $at, L_8044D6F0
    if (ctx->r19 != ctx->r1) {
        // 0x8044D7DC: sw          $t3, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r11;
            goto L_8044D6F0;
    }
    // 0x8044D7DC: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
L_8044D7E0:
    // 0x8044D7E0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8044D7E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8044D7E8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8044D7EC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8044D7F0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8044D7F4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8044D7F8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8044D7FC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8044D800: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8044D804: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8044D808: jr          $ra
    // 0x8044D80C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x8044D80C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_800259FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800259FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80025A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025A04: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80025A08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80025A0C: jal         0x800259A4
    // 0x80025A10: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_800259A4(rdram, ctx);
        goto after_0;
    // 0x80025A10: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80025A14: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80025A18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80025A1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80025A20: lbu         $t8, 0xF6($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XF6);
    // 0x80025A24: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80025A28: bnel        $t8, $at, L_80025A44
    if (ctx->r24 != ctx->r1) {
        // 0x80025A2C: lw          $t1, 0x14C($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X14C);
            goto L_80025A44;
    }
    goto skip_0;
    // 0x80025A2C: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    skip_0:
    // 0x80025A30: lw          $t9, 0x14C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14C);
    // 0x80025A34: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x80025A38: b           L_80025A50
    // 0x80025A3C: sw          $t0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r8;
        goto L_80025A50;
    // 0x80025A3C: sw          $t0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r8;
    // 0x80025A40: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
L_80025A44:
    // 0x80025A44: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x80025A48: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x80025A4C: sw          $t3, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r11;
L_80025A50:
    // 0x80025A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025A54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80025A58: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80025A5C: jr          $ra
    // 0x80025A60: nop

    return;
    // 0x80025A60: nop

;}
RECOMP_FUNC void func_8041E5E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041E5E8: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8041E5EC: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8041E5F0: beq         $v0, $zero, L_8041E600
    if (ctx->r2 == 0) {
        // 0x8041E5F4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8041E600;
    }
    // 0x8041E5F4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8041E5F8: jr          $ra
    // 0x8041E5FC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    return;
    // 0x8041E5FC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8041E600:
    // 0x8041E600: lh          $t7, 0x144($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X144);
    // 0x8041E604: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8041E608: sh          $t8, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r24;
    // 0x8041E60C: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x8041E610: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x8041E614: bnel        $at, $zero, L_8041E624
    if (ctx->r1 != 0) {
        // 0x8041E618: sw          $t0, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r8;
            goto L_8041E624;
    }
    goto skip_0;
    // 0x8041E618: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
    skip_0:
    // 0x8041E61C: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8041E620: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
L_8041E624:
    // 0x8041E624: jr          $ra
    // 0x8041E628: nop

    return;
    // 0x8041E628: nop

;}
RECOMP_FUNC void func_8079DA3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079DA3C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8079DA40: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8079DA44: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8079DA48: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8079DA4C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8079DA50: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8079DA54: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8079DA58: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(832, 0X2E0) << 16);
    // 0x8079DA5C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8079DA60: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8079DA64: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8079DA68: lw          $t1, -0x2580($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(832, 0X2E0));
    // 0x8079DA6C: jr          $ra
    // 0x8079DA70: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8079DA70: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8079DA74: nop

    // 0x8079DA78: nop

    // 0x8079DA7C: nop

;}
RECOMP_FUNC void func_80517E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517E78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80517E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80517E80: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80517E84: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80517E88: jal         0x80048378
    // 0x80517E8C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x80517E8C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x80517E90: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(291, 0X25F0) << 16);
    // 0x80517E94: lwc1        $f4, -0x5DA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(291, 0X25F0));
    // 0x80517E98: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80517E9C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80517EA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80517EA4: swc1        $f4, 0xEC($a1)
    MEM_W(0XEC, ctx->r5) = ctx->f4.u32l;
    // 0x80517EA8: swc1        $f6, 0xE0($a1)
    MEM_W(0XE0, ctx->r5) = ctx->f6.u32l;
    // 0x80517EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80517EB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80517EB4: jr          $ra
    // 0x80517EB8: nop

    return;
    // 0x80517EB8: nop

;}
RECOMP_FUNC void func_80021884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021884: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x80021888: lw          $v0, 0x2C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X2C);
    // 0x8002188C: ori         $t8, $zero, 0xF000
    ctx->r24 = 0 | 0XF000;
    // 0x80021890: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x80021894: andi        $t6, $v0, 0x3000
    ctx->r14 = ctx->r2 & 0X3000;
    // 0x80021898: beql        $t6, $zero, L_800218AC
    if (ctx->r14 == 0) {
        // 0x8002189C: andi        $t9, $v0, 0x700
        ctx->r25 = ctx->r2 & 0X700;
            goto L_800218AC;
    }
    goto skip_0;
    // 0x8002189C: andi        $t9, $v0, 0x700
    ctx->r25 = ctx->r2 & 0X700;
    skip_0:
    // 0x800218A0: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800218A4: lw          $v0, 0x2C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X2C);
    // 0x800218A8: andi        $t9, $v0, 0x700
    ctx->r25 = ctx->r2 & 0X700;
L_800218AC:
    // 0x800218AC: beql        $t9, $zero, L_800218CC
    if (ctx->r25 == 0) {
        // 0x800218B0: and         $t2, $v0, $at
        ctx->r10 = ctx->r2 & ctx->r1;
            goto L_800218CC;
    }
    goto skip_1;
    // 0x800218B0: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    skip_1:
    // 0x800218B4: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800218B8: sb          $zero, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = 0;
    // 0x800218BC: ori         $t1, $t0, 0xF00
    ctx->r9 = ctx->r8 | 0XF00;
    // 0x800218C0: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x800218C4: lw          $v0, 0x2C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X2C);
    // 0x800218C8: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
L_800218CC:
    // 0x800218CC: beq         $t2, $zero, L_800218E4
    if (ctx->r10 == 0) {
        // 0x800218D0: lui         $at, 0xF
        ctx->r1 = S32(0XF << 16);
            goto L_800218E4;
    }
    // 0x800218D0: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x800218D4: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x800218D8: ori         $t4, $t3, 0xF0
    ctx->r12 = ctx->r11 | 0XF0;
    // 0x800218DC: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    // 0x800218E0: lw          $v0, 0x2C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X2C);
L_800218E4:
    // 0x800218E4: and         $t5, $v0, $at
    ctx->r13 = ctx->r2 & ctx->r1;
    // 0x800218E8: beql        $t5, $zero, L_80021900
    if (ctx->r13 == 0) {
        // 0x800218EC: lw          $t8, 0x138($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X138);
            goto L_80021900;
    }
    goto skip_2;
    // 0x800218EC: lw          $t8, 0x138($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X138);
    skip_2:
    // 0x800218F0: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800218F4: ori         $t7, $t6, 0xF
    ctx->r15 = ctx->r14 | 0XF;
    // 0x800218F8: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800218FC: lw          $t8, 0x138($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X138);
L_80021900:
    // 0x80021900: beql        $t8, $zero, L_80021930
    if (ctx->r24 == 0) {
        // 0x80021904: lw          $v0, 0x8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X8);
            goto L_80021930;
    }
    goto skip_3;
    // 0x80021904: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    skip_3:
    // 0x80021908: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8002190C: sll         $t0, $t9, 28
    ctx->r8 = S32(ctx->r25 << 28);
    // 0x80021910: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80021914: andi        $t2, $t1, 0xF0
    ctx->r10 = ctx->r9 & 0XF0;
    // 0x80021918: sll         $t3, $t2, 20
    ctx->r11 = S32(ctx->r10 << 20);
    // 0x8002191C: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x80021920: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80021924: jr          $ra
    // 0x80021928: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    return;
    // 0x80021928: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    // 0x8002192C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
L_80021930:
    // 0x80021930: andi        $t5, $v0, 0xF0
    ctx->r13 = ctx->r2 & 0XF0;
    // 0x80021934: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x80021938: or          $t7, $v0, $t6
    ctx->r15 = ctx->r2 | ctx->r14;
    // 0x8002193C: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x80021940: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80021944: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x80021948: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8002194C: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x80021950: jr          $ra
    // 0x80021954: nop

    return;
    // 0x80021954: nop

;}
RECOMP_FUNC void func_80001338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001338: sra         $t0, $a3, 4
    ctx->r8 = S32(SIGNED(ctx->r7) >> 4);
    // 0x8000133C: andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // 0x80001340: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x80001344: lui         $at, 0x1400
    ctx->r1 = S32(0X1400 << 16);
    // 0x80001348: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
    // 0x8000134C: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80001350: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80001354: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80001358: or          $t7, $t0, $t6
    ctx->r15 = ctx->r8 | ctx->r14;
    // 0x8000135C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80001360: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x80001364: lui         $t5, 0x800B
    ctx->r13 = S32(0X800B << 16);
    // 0x80001368: addiu       $t5, $t5, 0x4D10
    ctx->r13 = ADD32(ctx->r13, 0X4D10);
    // 0x8000136C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80001370: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80001374: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80001378: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8000137C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80001380: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80001384: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80001388: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x8000138C: lw          $t6, 0x38($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X38);
    // 0x80001390: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80001394: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x80001398: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8000139C: addiu       $t9, $a1, 0x1A0
    ctx->r25 = ADD32(ctx->r5, 0X1A0);
    // 0x800013A0: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x800013A4: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x800013A8: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x800013AC: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800013B0: addiu       $t3, $a0, 0x8
    ctx->r11 = ADD32(ctx->r4, 0X8);
    // 0x800013B4: or          $t6, $t0, $t5
    ctx->r14 = ctx->r8 | ctx->r13;
    // 0x800013B8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800013BC: lw          $t7, 0x3C($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X3C);
    // 0x800013C0: addiu       $v0, $t3, 0x8
    ctx->r2 = ADD32(ctx->r11, 0X8);
    // 0x800013C4: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x800013C8: addu        $t9, $t8, $t4
    ctx->r25 = ADD32(ctx->r24, ctx->r12);
    // 0x800013CC: jr          $ra
    // 0x800013D0: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    return;
    // 0x800013D0: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
;}
RECOMP_FUNC void func_80519340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519340: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80519344: beq         $v0, $zero, L_80519350
    if (ctx->r2 == 0) {
        // 0x80519348: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80519350;
    }
    // 0x80519348: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8051934C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_80519350:
    // 0x80519350: jr          $ra
    // 0x80519354: nop

    return;
    // 0x80519354: nop

;}
RECOMP_FUNC void func_806E7E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7E70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E7E74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E7E78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E7E7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806E7E80: jal         0x80047090
    // 0x806E7E84: addiu       $a0, $zero, 0x40C5
    ctx->r4 = ADD32(0, 0X40C5);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806E7E84: addiu       $a0, $zero, 0x40C5
    ctx->r4 = ADD32(0, 0X40C5);
    after_0:
    // 0x806E7E88: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x806E7E8C: beq         $v0, $at, L_806E7F00
    if (ctx->r2 == ctx->r1) {
        // 0x806E7E90: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_806E7F00;
    }
    // 0x806E7E90: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x806E7E94: lui         $at, 0x40C5
    ctx->r1 = S32(0X40C5 << 16);
    // 0x806E7E98: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x806E7E9C: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x806E7EA0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x806E7EA4: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x806E7EA8: jal         0x8004613C
    // 0x806E7EAC: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806E7EAC: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x806E7EB0: beq         $v0, $zero, L_806E7F00
    if (ctx->r2 == 0) {
        // 0x806E7EB4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806E7F00;
    }
    // 0x806E7EB4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806E7EB8: jal         0x80044194
    // 0x806E7EBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x806E7EBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x806E7EC0: jal         0x806E7468
    // 0x806E7EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E7468(rdram, ctx);
        goto after_3;
    // 0x806E7EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806E7EC8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(664, 0XF00) << 16);
    // 0x806E7ECC: lwc1        $f0, -0x7EC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(664, 0XF00));
    // 0x806E7ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E7ED4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x806E7ED8: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x806E7EDC: jal         0x806E7E4C
    // 0x806E7EE0: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    func_806E7E4C(rdram, ctx);
        goto after_4;
    // 0x806E7EE0: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    after_4:
    // 0x806E7EE4: jal         0x8005FD1C
    // 0x806E7EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FD1C(rdram, ctx);
        goto after_5;
    // 0x806E7EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806E7EEC: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x806E7EF0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x806E7EF4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806E7EF8: b           L_806E7F04
    // 0x806E7EFC: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
        goto L_806E7F04;
    // 0x806E7EFC: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
L_806E7F00:
    // 0x806E7F00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806E7F04:
    // 0x806E7F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806E7F08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E7F0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E7F10: jr          $ra
    // 0x806E7F14: nop

    return;
    // 0x806E7F14: nop

;}
RECOMP_FUNC void func_8006A8AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A8AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006A8B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A8B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006A8B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006A8BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006A8C0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8006A8C4: jal         0x8006A0F8
    // 0x8006A8C8: lhu         $a0, 0x2E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2E);
    func_8006A0F8(rdram, ctx);
        goto after_0;
    // 0x8006A8C8: lhu         $a0, 0x2E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2E);
    after_0:
    // 0x8006A8CC: bne         $v0, $zero, L_8006A8DC
    if (ctx->r2 != 0) {
        // 0x8006A8D0: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8006A8DC;
    }
    // 0x8006A8D0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8006A8D4: b           L_8006A988
    // 0x8006A8D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A988;
    // 0x8006A8D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A8DC:
    // 0x8006A8DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006A8E0: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x8006A8E4: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x8006A8E8: bnel        $t6, $zero, L_8006A8FC
    if (ctx->r14 != 0) {
        // 0x8006A8EC: sb          $t7, 0x4($s0)
        MEM_B(0X4, ctx->r16) = ctx->r15;
            goto L_8006A8FC;
    }
    goto skip_0;
    // 0x8006A8EC: sb          $t7, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r15;
    skip_0:
    // 0x8006A8F0: b           L_8006A988
    // 0x8006A8F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006A988;
    // 0x8006A8F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006A8F8: sb          $t7, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r15;
L_8006A8FC:
    // 0x8006A8FC: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x8006A900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006A904: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x8006A908: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x8006A90C: lw          $t0, 0x20($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X20);
    // 0x8006A910: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x8006A914: jal         0x8006A1E4
    // 0x8006A918: sh          $t1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r9;
    func_8006A1E4(rdram, ctx);
        goto after_1;
    // 0x8006A918: sh          $t1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r9;
    after_1:
    // 0x8006A91C: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A920: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8006A924: jal         0x8006A3E4
    // 0x8006A928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006A3E4(rdram, ctx);
        goto after_2;
    // 0x8006A928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8006A92C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8006A930: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006A938: or          $v1, $v1, $t2
    ctx->r3 = ctx->r3 | ctx->r10;
    // 0x8006A93C: jal         0x8006A284
    // 0x8006A940: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8006A284(rdram, ctx);
        goto after_3;
    // 0x8006A940: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x8006A944: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8006A948: lhu         $t4, 0x2E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X2E);
    // 0x8006A94C: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A950: or          $v1, $v1, $t3
    ctx->r3 = ctx->r3 | ctx->r11;
    // 0x8006A954: beq         $v1, $zero, L_8006A96C
    if (ctx->r3 == 0) {
        // 0x8006A958: sra         $t5, $t4, 14
        ctx->r13 = S32(SIGNED(ctx->r12) >> 14);
            goto L_8006A96C;
    }
    // 0x8006A958: sra         $t5, $t4, 14
    ctx->r13 = S32(SIGNED(ctx->r12) >> 14);
    // 0x8006A95C: jal         0x8006A64C
    // 0x8006A960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006A64C(rdram, ctx);
        goto after_4;
    // 0x8006A960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8006A964: b           L_8006A988
    // 0x8006A968: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A988;
    // 0x8006A968: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A96C:
    // 0x8006A96C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8006A970: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006A974: bnel        $t6, $at, L_8006A988
    if (ctx->r14 != ctx->r1) {
        // 0x8006A978: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006A988;
    }
    goto skip_1;
    // 0x8006A978: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8006A97C: jal         0x8006A6C4
    // 0x8006A980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006A6C4(rdram, ctx);
        goto after_5;
    // 0x8006A980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8006A984: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A988:
    // 0x8006A988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A98C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A990: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006A994: jr          $ra
    // 0x8006A998: nop

    return;
    // 0x8006A998: nop

;}
RECOMP_FUNC void func_8003A620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A620: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003A624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A628: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x8003A62C: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x8003A630: jal         0x800582D8
    // 0x8003A634: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800582D8(rdram, ctx);
        goto after_0;
    // 0x8003A634: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8003A638: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8003A63C: lw          $t6, -0x6DA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DA8);
    // 0x8003A640: lbu         $t7, 0x5D($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5D);
    // 0x8003A644: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8003A648: jal         0x80058958
    // 0x8003A64C: sb          $t7, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r15;
    func_80058958(rdram, ctx);
        goto after_1;
    // 0x8003A64C: sb          $t7, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r15;
    after_1:
    // 0x8003A650: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8003A654: beq         $v0, $zero, L_8003A6E0
    if (ctx->r2 == 0) {
        // 0x8003A658: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8003A6E0;
    }
    // 0x8003A658: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003A65C: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003A660: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x8003A664: bnel        $v0, $t8, L_8003A6BC
    if (ctx->r2 != ctx->r24) {
        // 0x8003A668: lbu         $t4, 0x4($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X4);
            goto L_8003A6BC;
    }
    goto skip_0;
    // 0x8003A668: lbu         $t4, 0x4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4);
    skip_0:
    // 0x8003A66C: lbu         $t9, 0x5($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5);
    // 0x8003A670: bnel        $v0, $t9, L_8003A6BC
    if (ctx->r2 != ctx->r25) {
        // 0x8003A674: lbu         $t4, 0x4($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X4);
            goto L_8003A6BC;
    }
    goto skip_1;
    // 0x8003A674: lbu         $t4, 0x4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4);
    skip_1:
    // 0x8003A678: lbu         $t0, 0x6($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X6);
    // 0x8003A67C: bnel        $v0, $t0, L_8003A6BC
    if (ctx->r2 != ctx->r8) {
        // 0x8003A680: lbu         $t4, 0x4($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X4);
            goto L_8003A6BC;
    }
    goto skip_2;
    // 0x8003A680: lbu         $t4, 0x4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4);
    skip_2:
    // 0x8003A684: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8003A688: jal         0x8004700C
    // 0x8003A68C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_2;
    // 0x8003A68C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x8003A690: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8003A694: beq         $v0, $zero, L_8003A6B8
    if (ctx->r2 == 0) {
        // 0x8003A698: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8003A6B8;
    }
    // 0x8003A698: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003A69C: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    // 0x8003A6A0: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x8003A6A4: lbu         $t2, 0x1($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X1);
    // 0x8003A6A8: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    // 0x8003A6AC: lbu         $t3, 0x2($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X2);
    // 0x8003A6B0: b           L_8003A6D0
    // 0x8003A6B4: sb          $t3, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r11;
        goto L_8003A6D0;
    // 0x8003A6B4: sb          $t3, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r11;
L_8003A6B8:
    // 0x8003A6B8: lbu         $t4, 0x4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4);
L_8003A6BC:
    // 0x8003A6BC: lbu         $t5, 0x5($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X5);
    // 0x8003A6C0: lbu         $t6, 0x6($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X6);
    // 0x8003A6C4: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x8003A6C8: sb          $t5, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r13;
    // 0x8003A6CC: sb          $t6, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r14;
L_8003A6D0:
    // 0x8003A6D0: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003A6D4: sb          $v0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r2;
    // 0x8003A6D8: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // 0x8003A6DC: sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
L_8003A6E0:
    // 0x8003A6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A6E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003A6E8: jr          $ra
    // 0x8003A6EC: nop

    return;
    // 0x8003A6EC: nop

;}
RECOMP_FUNC void func_805E432C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E432C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805E4330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E4334: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805E4338: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x805E433C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805E4340: lui         $t8, 0x805E
    ctx->r24 = S32(RELOC_HI16(486, 0XEC0) << 16);
    // 0x805E4344: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805E4348: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x805E434C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805E4350: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805E4354: lw          $t8, 0x5000($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(486, 0XEC0));
    // 0x805E4358: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805E435C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805E4360: jal         0x80048490
    // 0x805E4364: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x805E4364: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x805E4368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805E436C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805E4370: jr          $ra
    // 0x805E4374: nop

    return;
    // 0x805E4374: nop

;}
RECOMP_FUNC void func_8003D54C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D54C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003D550: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003D554: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003D558: jal         0x8004700C
    // 0x8003D55C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003D55C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8003D560: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8003D564: lw          $t6, -0x76BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76BC);
    // 0x8003D568: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003D56C: lwc1        $f4, 0x214($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X214);
    // 0x8003D570: lwc1        $f0, 0x6C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x8003D574: sltu        $t7, $zero, $t6
    ctx->r15 = 0 < ctx->r14 ? 1 : 0;
    // 0x8003D578: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003D57C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8003D580: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8003D584: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003D588: lwc1        $f6, -0x10A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X10A0);
    // 0x8003D58C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D590: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8003D594: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003D598: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8003D59C: jal         0x8003D4E4
    // 0x8003D5A0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_8003D4E4(rdram, ctx);
        goto after_1;
    // 0x8003D5A0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8003D5A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003D5A8: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8003D5AC: lwc1        $f10, 0x218($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X218);
    // 0x8003D5B0: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8003D5B4: swc1        $f2, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f2.u32l;
    // 0x8003D5B8: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x8003D5BC: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003D5C0: neg.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = -ctx->f2.fl;
    // 0x8003D5C4: addiu       $t9, $t9, -0x2F50
    ctx->r25 = ADD32(ctx->r25, -0X2F50);
    // 0x8003D5C8: swc1        $f18, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f18.u32l;
    // 0x8003D5CC: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
    // 0x8003D5D0: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x8003D5D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D5D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003D5DC: swc1        $f16, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f16.u32l;
    // 0x8003D5E0: jal         0x8001D770
    // 0x8003D5E4: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    func_8001D770(rdram, ctx);
        goto after_2;
    // 0x8003D5E4: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    after_2:
    // 0x8003D5E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003D5EC: jal         0x80067E98
    // 0x8003D5F0: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    func_80067E98(rdram, ctx);
        goto after_3;
    // 0x8003D5F0: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x8003D5F4: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x8003D5F8: jal         0x80067818
    // 0x8003D5FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8003D5FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8003D600: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x8003D604: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8003D608: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D60C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003D610: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003D614: jr          $ra
    // 0x8003D618: nop

    return;
    // 0x8003D618: nop

;}
RECOMP_FUNC void func_80018C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018C80: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80018C84: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80018C88: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80018C8C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80018C90: jr          $ra
    // 0x80018C94: sh          $a0, -0x6D10($at)
    MEM_H(-0X6D10, ctx->r1) = ctx->r4;
    return;
    // 0x80018C94: sh          $a0, -0x6D10($at)
    MEM_H(-0X6D10, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_804B63C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B63C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B63CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B63D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804B63D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804B63D8: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x804B63DC: jal         0x80067BBC
    // 0x804B63E0: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x804B63E0: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x804B63E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x804B63E8: jal         0x80067818
    // 0x804B63EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x804B63EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x804B63F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B63F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B63F8: jr          $ra
    // 0x804B63FC: nop

    return;
    // 0x804B63FC: nop

;}
RECOMP_FUNC void func_8002E8C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E8C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002E8C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E8CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002E8D0: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002E8D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002E8D8: jal         0x800422CC
    // 0x8002E8DC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_800422CC(rdram, ctx);
        goto after_0;
    // 0x8002E8DC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8002E8E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002E8E4: jal         0x8002D164
    // 0x8002E8E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8002D164(rdram, ctx);
        goto after_1;
    // 0x8002E8E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002E8EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002E8F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E8F4: jal         0x8002E7C8
    // 0x8002E8F8: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    func_8002E7C8(rdram, ctx);
        goto after_2;
    // 0x8002E8F8: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    after_2:
    // 0x8002E8FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002E904: jr          $ra
    // 0x8002E908: nop

    return;
    // 0x8002E908: nop

;}
RECOMP_FUNC void func_8005B814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B814: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005B818: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005B81C: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x8005B820: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8005B824: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8005B828: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005B82C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8005B830: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8005B834: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8005B838: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8005B83C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005B840: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005B844: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8005B848: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8005B84C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8005B850: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8005B854: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8005B858: jal         0x8005B54C
    // 0x8005B85C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    func_8005B54C(rdram, ctx);
        goto after_0;
    // 0x8005B85C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_0:
    // 0x8005B860: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B864: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8005B868: jr          $ra
    // 0x8005B86C: nop

    return;
    // 0x8005B86C: nop

;}
RECOMP_FUNC void func_80673D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673D90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80673D94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80673D98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80673D9C: jal         0x80673D34
    // 0x80673DA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80673D34(rdram, ctx);
        goto after_0;
    // 0x80673DA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80673DA4: bne         $v0, $zero, L_80673DB4
    if (ctx->r2 != 0) {
        // 0x80673DA8: nop
    
            goto L_80673DB4;
    }
    // 0x80673DA8: nop

    // 0x80673DAC: b           L_80673DE0
    // 0x80673DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80673DE0;
    // 0x80673DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80673DB4:
    // 0x80673DB4: jal         0x806731F4
    // 0x80673DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806731F4(rdram, ctx);
        goto after_1;
    // 0x80673DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80673DBC: jal         0x8067379C
    // 0x80673DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067379C(rdram, ctx);
        goto after_2;
    // 0x80673DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80673DC4: jal         0x806734B4
    // 0x80673DC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806734B4(rdram, ctx);
        goto after_3;
    // 0x80673DC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80673DCC: jal         0x80673D78
    // 0x80673DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80673D78(rdram, ctx);
        goto after_4;
    // 0x80673DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80673DD4: jal         0x80673560
    // 0x80673DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80673560(rdram, ctx);
        goto after_5;
    // 0x80673DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80673DDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80673DE0:
    // 0x80673DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80673DE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80673DE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80673DEC: jr          $ra
    // 0x80673DF0: nop

    return;
    // 0x80673DF0: nop

;}
RECOMP_FUNC void func_806F2934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F2938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F293C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F2940: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x806F2944: jal         0x80065728
    // 0x806F2948: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x806F2948: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x806F294C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F2950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F2954: jr          $ra
    // 0x806F2958: nop

    return;
    // 0x806F2958: nop

;}
RECOMP_FUNC void func_8002E5E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E5E4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8002E5E8: lw          $t6, -0x76BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76BC);
    // 0x8002E5EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002E5F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002E5F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002E5F8: beq         $t6, $zero, L_8002E610
    if (ctx->r14 == 0) {
        // 0x8002E5FC: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8002E610;
    }
    // 0x8002E5FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002E600: jal         0x8002E488
    // 0x8002E604: nop

    func_8002E488(rdram, ctx);
        goto after_0;
    // 0x8002E604: nop

    after_0:
    // 0x8002E608: b           L_8002E660
    // 0x8002E60C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8002E660;
    // 0x8002E60C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002E610:
    // 0x8002E610: jal         0x8002B798
    // 0x8002E614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002B798(rdram, ctx);
        goto after_1;
    // 0x8002E614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8002E618: beq         $v0, $zero, L_8002E630
    if (ctx->r2 == 0) {
        // 0x8002E61C: nop
    
            goto L_8002E630;
    }
    // 0x8002E61C: nop

    // 0x8002E620: jal         0x8002E4F0
    // 0x8002E624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002E4F0(rdram, ctx);
        goto after_2;
    // 0x8002E624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8002E628: b           L_8002E638
    // 0x8002E62C: nop

        goto L_8002E638;
    // 0x8002E62C: nop

L_8002E630:
    // 0x8002E630: jal         0x8002D208
    // 0x8002E634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002D208(rdram, ctx);
        goto after_3;
    // 0x8002E634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8002E638:
    // 0x8002E638: jal         0x8001D770
    // 0x8002E63C: nop

    func_8001D770(rdram, ctx);
        goto after_4;
    // 0x8002E63C: nop

    after_4:
    // 0x8002E640: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002E644: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002E648: jal         0x80067BF8
    // 0x8002E64C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_5;
    // 0x8002E64C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x8002E650: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x8002E654: jal         0x80067818
    // 0x8002E658: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8002E658: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8002E65C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002E660:
    // 0x8002E660: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002E664: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002E668: jr          $ra
    // 0x8002E66C: nop

    return;
    // 0x8002E66C: nop

;}
RECOMP_FUNC void func_80475210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475210: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475214: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475218: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047521C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475220: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475224: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475228: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047522C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475230: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475234: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475238: jr          $ra
    // 0x8047523C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047523C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80041BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041BCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041BD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041BD4: lhu         $t6, 0x8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X8);
    // 0x80041BD8: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80041BDC: lhu         $t9, 0xC($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0XC);
    // 0x80041BE0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80041BE4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80041BE8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80041BEC: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80041BF0: lhu         $a1, 0x1200($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X1200);
    // 0x80041BF4: lhu         $a2, 0xA($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0XA);
    // 0x80041BF8: addu        $a3, $a1, $t9
    ctx->r7 = ADD32(ctx->r5, ctx->r25);
    // 0x80041BFC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80041C00: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80041C04: beq         $at, $zero, L_80041C14
    if (ctx->r1 == 0) {
        // 0x80041C08: andi        $a3, $a3, 0xFFFF
        ctx->r7 = ctx->r7 & 0XFFFF;
            goto L_80041C14;
    }
    // 0x80041C08: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x80041C0C: b           L_80041C3C
    // 0x80041C10: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
        goto L_80041C3C;
    // 0x80041C10: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
L_80041C14:
    // 0x80041C14: sll         $t0, $a3, 4
    ctx->r8 = S32(ctx->r7 << 4);
    // 0x80041C18: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x80041C1C: lbu         $t2, 0x209($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X209);
    // 0x80041C20: srl         $t3, $t2, 4
    ctx->r11 = S32(U32(ctx->r10) >> 4);
    // 0x80041C24: bne         $t3, $zero, L_80041C3C
    if (ctx->r11 != 0) {
        // 0x80041C28: nop
    
            goto L_80041C3C;
    }
    // 0x80041C28: nop

    // 0x80041C2C: beq         $a1, $zero, L_80041C3C
    if (ctx->r5 == 0) {
        // 0x80041C30: nop
    
            goto L_80041C3C;
    }
    // 0x80041C30: nop

    // 0x80041C34: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80041C38: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
L_80041C3C:
    // 0x80041C3C: jal         0x80041914
    // 0x80041C40: sh          $a1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r5;
    func_80041914(rdram, ctx);
        goto after_0;
    // 0x80041C40: sh          $a1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r5;
    after_0:
    // 0x80041C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041C48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80041C4C: jr          $ra
    // 0x80041C50: nop

    return;
    // 0x80041C50: nop

;}
RECOMP_FUNC void func_8078BEE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078BEE0: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8078BEE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078BEE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078BEEC: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8078BEF0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8078BEF4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8078BEF8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8078BEFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8078BF00: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x8078BF04: jal         0x8004921C
    // 0x8078BF08: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8078BF08: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8078BF0C: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x8078BF10: sh          $v0, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r2;
    // 0x8078BF14: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8078BF18: lw          $t8, 0x168($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X168);
    // 0x8078BF1C: lw          $v1, -0x260C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X260C);
    // 0x8078BF20: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x8078BF24: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x8078BF28: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8078BF2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8078BF30: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x8078BF34: lw          $t6, 0x16C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X16C);
    // 0x8078BF38: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8078BF3C: sw          $t7, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r15;
    // 0x8078BF40: lw          $s0, 0xC($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XC);
    // 0x8078BF44: addiu       $s0, $s0, -0x240
    ctx->r16 = ADD32(ctx->r16, -0X240);
    // 0x8078BF48: sw          $s0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r16;
    // 0x8078BF4C: sw          $s0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r16;
    // 0x8078BF50: lw          $t8, 0x1F4($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X1F4);
    // 0x8078BF54: jal         0x80077338
    // 0x8078BF58: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
    func_80077338(rdram, ctx);
        goto after_1;
    // 0x8078BF58: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
    after_1:
    // 0x8078BF5C: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x8078BF60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8078BF64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8078BF68: jal         0x8007711C
    // 0x8078BF6C: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    func_8007711C(rdram, ctx);
        goto after_2;
    // 0x8078BF6C: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    after_2:
    // 0x8078BF70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078BF74: jal         0x8078BA60
    // 0x8078BF78: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    func_8078BA60(rdram, ctx);
        goto after_3;
    // 0x8078BF78: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    after_3:
    // 0x8078BF7C: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8078BF80: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x8078BF84: ori         $t7, $t7, 0x491F
    ctx->r15 = ctx->r15 | 0X491F;
    // 0x8078BF88: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8078BF8C: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x8078BF90: sw          $s0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r16;
    // 0x8078BF94: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8078BF98: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8078BF9C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8078BFA0: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8078BFA4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8078BFA8: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8078BFAC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8078BFB0: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x8078BFB4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8078BFB8: lui         $ra, 0x700
    ctx->r31 = S32(0X700 << 16);
    // 0x8078BFBC: addiu       $t8, $t7, 0x600
    ctx->r24 = ADD32(ctx->r15, 0X600);
    // 0x8078BFC0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8078BFC4: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8078BFC8: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x8078BFCC: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x8078BFD0: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8078BFD4: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x8078BFD8: sw          $ra, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r31;
    // 0x8078BFDC: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8078BFE0: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8078BFE4: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8078BFE8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8078BFEC: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8078BFF0: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8078BFF4: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8078BFF8: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
    // 0x8078BFFC: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C000: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8078C004: sll         $t0, $v0, 6
    ctx->r8 = S32(ctx->r2 << 6);
    // 0x8078C008: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8078C00C: sra         $t0, $t0, 1
    ctx->r8 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8078C010: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8078C014: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8078C018: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x8078C01C: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8078C020: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8078C024: beq         $at, $zero, L_8078C034
    if (ctx->r1 == 0) {
        // 0x8078C028: or          $t3, $t7, $zero
        ctx->r11 = ctx->r15 | 0;
            goto L_8078C034;
    }
    // 0x8078C028: or          $t3, $t7, $zero
    ctx->r11 = ctx->r15 | 0;
    // 0x8078C02C: b           L_8078C034
    // 0x8078C030: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
        goto L_8078C034;
    // 0x8078C030: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_8078C034:
    // 0x8078C034: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8078C038: bgez        $t2, L_8078C048
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8078C03C: sra         $a1, $t2, 3
        ctx->r5 = S32(SIGNED(ctx->r10) >> 3);
            goto L_8078C048;
    }
    // 0x8078C03C: sra         $a1, $t2, 3
    ctx->r5 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8078C040: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
    // 0x8078C044: sra         $a1, $at, 3
    ctx->r5 = S32(SIGNED(ctx->r1) >> 3);
L_8078C048:
    // 0x8078C048: bgtz        $a1, L_8078C058
    if (SIGNED(ctx->r5) > 0) {
        // 0x8078C04C: addiu       $t4, $t2, 0x7
        ctx->r12 = ADD32(ctx->r10, 0X7);
            goto L_8078C058;
    }
    // 0x8078C04C: addiu       $t4, $t2, 0x7
    ctx->r12 = ADD32(ctx->r10, 0X7);
    // 0x8078C050: b           L_8078C05C
    // 0x8078C054: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8078C05C;
    // 0x8078C054: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8078C058:
    // 0x8078C058: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_8078C05C:
    // 0x8078C05C: bgtz        $a1, L_8078C06C
    if (SIGNED(ctx->r5) > 0) {
        // 0x8078C060: addiu       $t6, $a2, 0x7FF
        ctx->r14 = ADD32(ctx->r6, 0X7FF);
            goto L_8078C06C;
    }
    // 0x8078C060: addiu       $t6, $a2, 0x7FF
    ctx->r14 = ADD32(ctx->r6, 0X7FF);
    // 0x8078C064: b           L_8078C070
    // 0x8078C068: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8078C070;
    // 0x8078C068: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8078C06C:
    // 0x8078C06C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
L_8078C070:
    // 0x8078C070: div         $zero, $t6, $s0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r16)));
    // 0x8078C074: mflo        $t7
    ctx->r15 = lo;
    // 0x8078C078: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8078C07C: bne         $s0, $zero, L_8078C088
    if (ctx->r16 != 0) {
        // 0x8078C080: nop
    
            goto L_8078C088;
    }
    // 0x8078C080: nop

    // 0x8078C084: break       7
    do_break(2155397252);
L_8078C088:
    // 0x8078C088: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8078C08C: bne         $s0, $at, L_8078C0A0
    if (ctx->r16 != ctx->r1) {
        // 0x8078C090: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8078C0A0;
    }
    // 0x8078C090: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8078C094: bne         $t6, $at, L_8078C0A0
    if (ctx->r14 != ctx->r1) {
        // 0x8078C098: nop
    
            goto L_8078C0A0;
    }
    // 0x8078C098: nop

    // 0x8078C09C: break       6
    do_break(2155397276);
L_8078C0A0:
    // 0x8078C0A0: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x8078C0A4: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8078C0A8: or          $t9, $t8, $ra
    ctx->r25 = ctx->r24 | ctx->r31;
    // 0x8078C0AC: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8078C0B0: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x8078C0B4: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C0B8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8078C0BC: sra         $t4, $t4, 3
    ctx->r12 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8078C0C0: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8078C0C4: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8078C0C8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8078C0CC: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x8078C0D0: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C0D4: andi        $t4, $t4, 0x1FF
    ctx->r12 = ctx->r12 & 0X1FF;
    // 0x8078C0D8: sll         $t4, $t4, 9
    ctx->r12 = S32(ctx->r12 << 9);
    // 0x8078C0DC: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8078C0E0: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x8078C0E4: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8078C0E8: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
    // 0x8078C0EC: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x8078C0F0: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8078C0F4: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C0F8: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8078C0FC: lui         $t2, 0x8079
    ctx->r10 = S32(RELOC_HI16(796, 0X1930) << 16);
    // 0x8078C100: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8078C104: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x8078C108: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8078C10C: lh          $t5, 0x9A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X9A);
    // 0x8078C110: addiu       $t2, $t2, -0x3540
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(796, 0X1930));
    // 0x8078C114: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8078C118: addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
    // 0x8078C11C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8078C120: andi        $t5, $t5, 0xFFF
    ctx->r13 = ctx->r13 & 0XFFF;
    // 0x8078C124: sll         $t5, $t5, 12
    ctx->r13 = S32(ctx->r13 << 12);
    // 0x8078C128: ori         $t5, $t5, 0xFC
    ctx->r13 = ctx->r13 | 0XFC;
    // 0x8078C12C: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x8078C130: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C134: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8078C138: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x8078C13C: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8078C140: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8078C144: sw          $t2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r10;
    // 0x8078C148: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8078C14C: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C150: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x8078C154: ori         $t6, $t6, 0x491F
    ctx->r14 = ctx->r14 | 0X491F;
    // 0x8078C158: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8078C15C: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x8078C160: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8078C164: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8078C168: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8078C16C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8078C170: addiu       $t7, $t9, 0x120
    ctx->r15 = ADD32(ctx->r25, 0X120);
    // 0x8078C174: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8078C178: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C17C: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x8078C180: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8078C184: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x8078C188: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8078C18C: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x8078C190: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8078C194: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8078C198: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8078C19C: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C1A0: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8078C1A4: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x8078C1A8: sw          $ra, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r31;
    // 0x8078C1AC: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8078C1B0: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C1B4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8078C1B8: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8078C1BC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8078C1C0: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x8078C1C4: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8078C1C8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8078C1CC: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C1D0: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8078C1D4: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8078C1D8: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8078C1DC: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x8078C1E0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8078C1E4: beq         $at, $zero, L_8078C1F4
    if (ctx->r1 == 0) {
        // 0x8078C1E8: or          $a3, $t9, $zero
        ctx->r7 = ctx->r25 | 0;
            goto L_8078C1F4;
    }
    // 0x8078C1E8: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8078C1EC: b           L_8078C1F4
    // 0x8078C1F0: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
        goto L_8078C1F4;
    // 0x8078C1F0: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_8078C1F4:
    // 0x8078C1F4: bgtz        $a1, L_8078C204
    if (SIGNED(ctx->r5) > 0) {
        // 0x8078C1F8: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8078C204;
    }
    // 0x8078C1F8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8078C1FC: b           L_8078C204
    // 0x8078C200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8078C204;
    // 0x8078C200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8078C204:
    // 0x8078C204: bgtz        $a1, L_8078C214
    if (SIGNED(ctx->r5) > 0) {
        // 0x8078C208: addiu       $t6, $a2, 0x7FF
        ctx->r14 = ADD32(ctx->r6, 0X7FF);
            goto L_8078C214;
    }
    // 0x8078C208: addiu       $t6, $a2, 0x7FF
    ctx->r14 = ADD32(ctx->r6, 0X7FF);
    // 0x8078C20C: b           L_8078C214
    // 0x8078C210: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8078C214;
    // 0x8078C210: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8078C214:
    // 0x8078C214: div         $zero, $t6, $s0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r16)));
    // 0x8078C218: mflo        $t9
    ctx->r25 = lo;
    // 0x8078C21C: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8078C220: bne         $s0, $zero, L_8078C22C
    if (ctx->r16 != 0) {
        // 0x8078C224: nop
    
            goto L_8078C22C;
    }
    // 0x8078C224: nop

    // 0x8078C228: break       7
    do_break(2155397672);
L_8078C22C:
    // 0x8078C22C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8078C230: bne         $s0, $at, L_8078C244
    if (ctx->r16 != ctx->r1) {
        // 0x8078C234: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8078C244;
    }
    // 0x8078C234: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8078C238: bne         $t6, $at, L_8078C244
    if (ctx->r14 != ctx->r1) {
        // 0x8078C23C: nop
    
            goto L_8078C244;
    }
    // 0x8078C23C: nop

    // 0x8078C240: break       6
    do_break(2155397696);
L_8078C244:
    // 0x8078C244: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x8078C248: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8078C24C: or          $t8, $t7, $ra
    ctx->r24 = ctx->r15 | ctx->r31;
    // 0x8078C250: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8078C254: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x8078C258: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C25C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8078C260: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8078C264: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x8078C268: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8078C26C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8078C270: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C274: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8078C278: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x8078C27C: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x8078C280: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8078C284: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8078C288: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C28C: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8078C290: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8078C294: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8078C298: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8078C29C: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x8078C2A0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8078C2A4: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C2A8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8078C2AC: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8078C2B0: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x8078C2B4: sw          $t2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r10;
    // 0x8078C2B8: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8078C2BC: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x8078C2C0: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8078C2C4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8078C2C8: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x8078C2CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078C2D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078C2D4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x8078C2D8: jr          $ra
    // 0x8078C2DC: nop

    return;
    // 0x8078C2DC: nop

;}
RECOMP_FUNC void func_8045439C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045439C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804543A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804543A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804543A8: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804543AC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804543B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804543B4: addu        $v0, $s0, $at
    ctx->r2 = ADD32(ctx->r16, ctx->r1);
    // 0x804543B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804543BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804543C0: lwc1        $f4, 0x6C84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C84);
    // 0x804543C4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804543C8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x804543CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804543D0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x804543D4: swc1        $f8, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f8.u32l;
    // 0x804543D8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x804543DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804543E0: lwc1        $f10, 0x6C84($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6C84);
    // 0x804543E4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x804543E8: nop

    // 0x804543EC: bc1f        L_804544AC
    if (!c1cs) {
        // 0x804543F0: nop
    
            goto L_804544AC;
    }
    // 0x804543F0: nop

    // 0x804543F4: lw          $v1, 0xA5C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA5C);
    // 0x804543F8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x804543FC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80454400: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80454404: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80454408: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8045440C: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80454410: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80454414: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80454418: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8045441C: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80454420: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80454424: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80454428: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8045442C: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80454430: addiu       $t8, $t7, 0xAE0
    ctx->r24 = ADD32(ctx->r15, 0XAE0);
    // 0x80454434: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80454438: jal         0x80446D70
    // 0x8045443C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_80446D70(rdram, ctx);
        goto after_0;
    // 0x8045443C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_0:
    // 0x80454440: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x80454444: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80454448: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8045444C: jal         0x8044EEF8
    // 0x80454450: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_8044EEF8(rdram, ctx);
        goto after_1;
    // 0x80454450: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80454454: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80454458: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8045445C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80454460: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80454464: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80454468: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8045446C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80454470: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80454474: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80454478: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x8045447C: addu        $a1, $s0, $t0
    ctx->r5 = ADD32(ctx->r16, ctx->r8);
    // 0x80454480: jal         0x8044ED68
    // 0x80454484: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_2;
    // 0x80454484: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_2:
    // 0x80454488: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8045448C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80454490: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80454494: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80454498: sw          $t1, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r9;
    // 0x8045449C: jal         0x80450490
    // 0x804544A0: lwc1        $f12, 0x6C84($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X6C84);
    func_80450490(rdram, ctx);
        goto after_3;
    // 0x804544A0: lwc1        $f12, 0x6C84($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X6C84);
    after_3:
    // 0x804544A4: b           L_804544B8
    // 0x804544A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804544B8;
    // 0x804544A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804544AC:
    // 0x804544AC: jal         0x8006E0FC
    // 0x804544B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8006E0FC(rdram, ctx);
        goto after_4;
    // 0x804544B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x804544B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804544B8:
    // 0x804544B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804544BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804544C0: jr          $ra
    // 0x804544C4: nop

    return;
    // 0x804544C4: nop

;}
RECOMP_FUNC void func_80532304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532304: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80532308: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8053230C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80532310: jal         0x80532244
    // 0x80532314: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80532244(rdram, ctx);
        goto after_0;
    // 0x80532314: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80532318: beql        $v0, $zero, L_805323D8
    if (ctx->r2 == 0) {
        // 0x8053231C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805323D8;
    }
    goto skip_0;
    // 0x8053231C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80532320: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80532324: lui         $t1, 0x8053
    ctx->r9 = S32(RELOC_HI16(342, 0X1840) << 16);
    // 0x80532328: lw          $t3, 0x16C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X16C);
    // 0x8053232C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80532330: lui         $t2, 0x8053
    ctx->r10 = S32(RELOC_HI16(342, 0X1830) << 16);
    // 0x80532334: addiu       $t2, $t2, 0x2620
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(342, 0X1830));
    // 0x80532338: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8053233C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80532340: lui         $t5, 0x8053
    ctx->r13 = S32(RELOC_HI16(342, 0X384) << 16);
    // 0x80532344: addiu       $t5, $t5, 0x1174
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(342, 0X384));
    // 0x80532348: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x8053234C: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x80532350: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80532354: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80532358: lh          $t1, 0x2630($t1)
    ctx->r9 = MEM_H(ctx->r9, (int16_t)RELOC_LO16(342, 0X1840));
    // 0x8053235C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80532360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80532364: sh          $t1, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r9;
    // 0x80532368: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8053236C: lw          $t6, 0x16C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X16C);
    // 0x80532370: sw          $t4, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r12;
    // 0x80532374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80532378: sw          $t5, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r13;
    // 0x8053237C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80532380: jal         0x805323E8
    // 0x80532384: sb          $t7, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r15;
    func_805323E8(rdram, ctx);
        goto after_1;
    // 0x80532384: sb          $t7, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r15;
    after_1:
    // 0x80532388: jal         0x805322EC
    // 0x8053238C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805322EC(rdram, ctx);
        goto after_2;
    // 0x8053238C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80532390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80532394: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    // 0x80532398: jal         0x8053167C
    // 0x8053239C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8053167C(rdram, ctx);
        goto after_3;
    // 0x8053239C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x805323A0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x805323A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805323A8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x805323AC: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805323B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805323B4: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805323B8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x805323BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805323C0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805323C4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x805323C8: swc1        $f16, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f16.u32l;
    // 0x805323CC: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x805323D0: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x805323D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805323D8:
    // 0x805323D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805323DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805323E0: jr          $ra
    // 0x805323E4: nop

    return;
    // 0x805323E4: nop

;}
RECOMP_FUNC void func_8045089C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045089C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804508A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804508A4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804508A8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804508AC: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x804508B0: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x804508B4: lw          $t7, 0x6A28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X6A28);
    // 0x804508B8: addiu       $t8, $zero, -0x64
    ctx->r24 = ADD32(0, -0X64);
    // 0x804508BC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x804508C0: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x804508C4: sw          $t6, 0x6A20($v0)
    MEM_W(0X6A20, ctx->r2) = ctx->r14;
    // 0x804508C8: sw          $t8, 0x6A28($v0)
    MEM_W(0X6A28, ctx->r2) = ctx->r24;
    // 0x804508CC: sw          $t9, 0x6A2C($v0)
    MEM_W(0X6A2C, ctx->r2) = ctx->r25;
    // 0x804508D0: sw          $t0, 0x6A30($v0)
    MEM_W(0X6A30, ctx->r2) = ctx->r8;
    // 0x804508D4: sw          $t7, 0x6A24($v0)
    MEM_W(0X6A24, ctx->r2) = ctx->r15;
    // 0x804508D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804508DC: jal         0x8044EFA0
    // 0x804508E0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x804508E0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x804508E4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804508E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804508EC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804508F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804508F4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x804508F8: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    // 0x804508FC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450900: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80450904: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80450908: sw          $t1, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r9;
    // 0x8045090C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80450910: jal         0x80457164
    // 0x80450914: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80457164(rdram, ctx);
        goto after_1;
    // 0x80450914: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80450918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045091C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80450920: jr          $ra
    // 0x80450924: nop

    return;
    // 0x80450924: nop

;}
RECOMP_FUNC void func_805DB9FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DB9FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805DBA00: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x805DBA04: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x805DBA08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DBA0C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x805DBA10: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805DBA14: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x805DBA18: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x805DBA1C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x805DBA20: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x805DBA24: blez        $a1, L_805DBA7C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x805DBA28: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_805DBA7C;
    }
    // 0x805DBA28: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x805DBA2C: andi        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 & 0X3;
    // 0x805DBA30: beq         $a1, $zero, L_805DBA54
    if (ctx->r5 == 0) {
        // 0x805DBA34: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_805DBA54;
    }
    // 0x805DBA34: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805DBA38: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x805DBA3C: addu        $v0, $s1, $t6
    ctx->r2 = ADD32(ctx->r17, ctx->r14);
L_805DBA40:
    // 0x805DBA40: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x805DBA44: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x805DBA48: bne         $a0, $v1, L_805DBA40
    if (ctx->r4 != ctx->r3) {
        // 0x805DBA4C: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_805DBA40;
    }
    // 0x805DBA4C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x805DBA50: beq         $v1, $s0, L_805DBA7C
    if (ctx->r3 == ctx->r16) {
        // 0x805DBA54: sll         $t7, $v1, 1
        ctx->r15 = S32(ctx->r3 << 1);
            goto L_805DBA7C;
    }
L_805DBA54:
    // 0x805DBA54: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x805DBA58: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x805DBA5C: addu        $a0, $t8, $s1
    ctx->r4 = ADD32(ctx->r24, ctx->r17);
    // 0x805DBA60: addu        $v0, $s1, $t7
    ctx->r2 = ADD32(ctx->r17, ctx->r15);
L_805DBA64:
    // 0x805DBA64: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x805DBA68: sh          $zero, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = 0;
    // 0x805DBA6C: sh          $zero, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = 0;
    // 0x805DBA70: sh          $zero, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = 0;
    // 0x805DBA74: bne         $v0, $a0, L_805DBA64
    if (ctx->r2 != ctx->r4) {
        // 0x805DBA78: sh          $zero, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = 0;
            goto L_805DBA64;
    }
    // 0x805DBA78: sh          $zero, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = 0;
L_805DBA7C:
    // 0x805DBA7C: blez        $s4, L_805DBB24
    if (SIGNED(ctx->r20) <= 0) {
        // 0x805DBA80: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_805DBB24;
    }
    // 0x805DBA80: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x805DBA84: addiu       $s3, $zero, 0x4034
    ctx->r19 = ADD32(0, 0X4034);
L_805DBA88:
    // 0x805DBA88: jal         0x800653D8
    // 0x805DBA8C: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x805DBA8C: nop

    after_0:
    // 0x805DBA90: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DBA94: mfhi        $t9
    ctx->r25 = hi;
    // 0x805DBA98: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x805DBA9C: addu        $v1, $s1, $t0
    ctx->r3 = ADD32(ctx->r17, ctx->r8);
    // 0x805DBAA0: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x805DBAA4: bne         $s0, $zero, L_805DBAB0
    if (ctx->r16 != 0) {
        // 0x805DBAA8: nop
    
            goto L_805DBAB0;
    }
    // 0x805DBAA8: nop

    // 0x805DBAAC: break       7
    do_break(2153626284);
L_805DBAB0:
    // 0x805DBAB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DBAB4: bne         $s0, $at, L_805DBAC8
    if (ctx->r16 != ctx->r1) {
        // 0x805DBAB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DBAC8;
    }
    // 0x805DBAB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DBABC: bne         $v0, $at, L_805DBAC8
    if (ctx->r2 != ctx->r1) {
        // 0x805DBAC0: nop
    
            goto L_805DBAC8;
    }
    // 0x805DBAC0: nop

    // 0x805DBAC4: break       6
    do_break(2153626308);
L_805DBAC8:
    // 0x805DBAC8: beql        $t1, $zero, L_805DBB1C
    if (ctx->r9 == 0) {
        // 0x805DBACC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_805DBB1C;
    }
    goto skip_0;
    // 0x805DBACC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
L_805DBAD0:
    // 0x805DBAD0: jal         0x800653D8
    // 0x805DBAD4: nop

    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x805DBAD4: nop

    after_1:
    // 0x805DBAD8: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DBADC: mfhi        $t2
    ctx->r10 = hi;
    // 0x805DBAE0: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x805DBAE4: addu        $v1, $s1, $t3
    ctx->r3 = ADD32(ctx->r17, ctx->r11);
    // 0x805DBAE8: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x805DBAEC: bne         $s0, $zero, L_805DBAF8
    if (ctx->r16 != 0) {
        // 0x805DBAF0: nop
    
            goto L_805DBAF8;
    }
    // 0x805DBAF0: nop

    // 0x805DBAF4: break       7
    do_break(2153626356);
L_805DBAF8:
    // 0x805DBAF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DBAFC: bne         $s0, $at, L_805DBB10
    if (ctx->r16 != ctx->r1) {
        // 0x805DBB00: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DBB10;
    }
    // 0x805DBB00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DBB04: bne         $v0, $at, L_805DBB10
    if (ctx->r2 != ctx->r1) {
        // 0x805DBB08: nop
    
            goto L_805DBB10;
    }
    // 0x805DBB08: nop

    // 0x805DBB0C: break       6
    do_break(2153626380);
L_805DBB10:
    // 0x805DBB10: bne         $t4, $zero, L_805DBAD0
    if (ctx->r12 != 0) {
        // 0x805DBB14: nop
    
            goto L_805DBAD0;
    }
    // 0x805DBB14: nop

    // 0x805DBB18: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_805DBB1C:
    // 0x805DBB1C: bne         $s2, $s4, L_805DBA88
    if (ctx->r18 != ctx->r20) {
        // 0x805DBB20: sh          $s3, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r19;
            goto L_805DBA88;
    }
    // 0x805DBB20: sh          $s3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r19;
L_805DBB24:
    // 0x805DBB24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x805DBB28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DBB2C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x805DBB30: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x805DBB34: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x805DBB38: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x805DBB3C: jr          $ra
    // 0x805DBB40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x805DBB40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80791690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80791690: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80791694: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80791698: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8079169C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807916A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807916A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807916A8: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807916AC: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x807916B0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807916B4: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x807916B8: bne         $at, $zero, L_807916F4
    if (ctx->r1 != 0) {
        // 0x807916BC: lw          $s3, 0x88($t6)
        ctx->r19 = MEM_W(ctx->r14, 0X88);
            goto L_807916F4;
    }
    // 0x807916BC: lw          $s3, 0x88($t6)
    ctx->r19 = MEM_W(ctx->r14, 0X88);
    // 0x807916C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807916C4: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x807916C8: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
L_807916CC:
    // 0x807916CC: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x807916D0: beql        $a0, $zero, L_807916E4
    if (ctx->r4 == 0) {
        // 0x807916D4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_807916E4;
    }
    goto skip_0;
    // 0x807916D4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x807916D8: jal         0x8004590C
    // 0x807916DC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x807916DC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x807916E0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_807916E4:
    // 0x807916E4: bne         $s0, $s2, L_807916CC
    if (ctx->r16 != ctx->r18) {
        // 0x807916E8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_807916CC;
    }
    // 0x807916E8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807916EC: b           L_80791738
    // 0x807916F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80791738;
    // 0x807916F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_807916F4:
    // 0x807916F4: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x807916F8: beq         $t7, $zero, L_80791734
    if (ctx->r15 == 0) {
        // 0x807916FC: andi        $t8, $v0, 0x4
        ctx->r24 = ctx->r2 & 0X4;
            goto L_80791734;
    }
    // 0x807916FC: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x80791700: bne         $t8, $zero, L_8079170C
    if (ctx->r24 != 0) {
        // 0x80791704: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8079170C;
    }
    // 0x80791704: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80791708: addiu       $s3, $s3, 0x200
    ctx->r19 = ADD32(ctx->r19, 0X200);
L_8079170C:
    // 0x8079170C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80791710: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
L_80791714:
    // 0x80791714: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80791718: beql        $a0, $zero, L_8079172C
    if (ctx->r4 == 0) {
        // 0x8079171C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8079172C;
    }
    goto skip_1;
    // 0x8079171C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x80791720: jal         0x8004590C
    // 0x80791724: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_8004590C(rdram, ctx);
        goto after_1;
    // 0x80791724: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x80791728: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8079172C:
    // 0x8079172C: bne         $s0, $s2, L_80791714
    if (ctx->r16 != ctx->r18) {
        // 0x80791730: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80791714;
    }
    // 0x80791730: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80791734:
    // 0x80791734: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80791738:
    // 0x80791738: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8079173C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80791740: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80791744: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80791748: jr          $ra
    // 0x8079174C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8079174C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
