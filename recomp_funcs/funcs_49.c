#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_804CE418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE418: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CE41C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x804CE420: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804CE424: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x804CE428: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804CE42C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804CE430: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804CE434: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804CE438: nop

    // 0x804CE43C: bc1f        L_804CE460
    if (!c1cs) {
        // 0x804CE440: nop
    
            goto L_804CE460;
    }
    // 0x804CE440: nop

    // 0x804CE444: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804CE448: nop

    // 0x804CE44C: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
L_804CE450:
    // 0x804CE450: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804CE454: nop

    // 0x804CE458: bc1tl       L_804CE450
    if (c1cs) {
        // 0x804CE45C: add.s       $f0, $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
            goto L_804CE450;
    }
    goto skip_0;
    // 0x804CE45C: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    skip_0:
L_804CE460:
    // 0x804CE460: jr          $ra
    // 0x804CE464: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x804CE464: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void Fault_Sleep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F8F0: lui         $t7, 0xFFFA
    ctx->r15 = S32(0XFFFA << 16);
    // 0x8006F8F4: or          $t8, $sp, $zero
    ctx->r24 = ctx->r29 | 0;
    // 0x8006F8F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F8FC: ori         $t7, $t7, 0x5A5A
    ctx->r15 = ctx->r15 | 0X5A5A;
L_8006F900:
    // 0x8006F900: addiu       $t8, $t8, -0x8
    ctx->r24 = ADD32(ctx->r24, -0X8);
    // 0x8006F904: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8006F908: bne         $t8, $sp, L_8006F900
    if (ctx->r24 != ctx->r29) {
        // 0x8006F90C: sw          $t7, 0x4($t8)
        MEM_W(0X4, ctx->r24) = ctx->r15;
            goto L_8006F900;
    }
    // 0x8006F90C: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8006F910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F914: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006F918: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006F91C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006F920: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x8006F924: lw          $a3, -0x53BC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X53BC);
    // 0x8006F928: lw          $a2, -0x53C0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X53C0);
    // 0x8006F92C: jal         0x80082D88
    // 0x8006F930: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8006F930: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_0:
    // 0x8006F934: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006F938: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8006F93C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8006F940: jal         0x80082C88
    // 0x8006F944: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x8006F944: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    after_1:
    // 0x8006F948: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006F94C: jal         0x800821A0
    // 0x8006F950: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    csleep(rdram, ctx);
        goto after_2;
    // 0x8006F950: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x8006F954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F95C: jr          $ra
    // 0x8006F960: nop

    return;
    // 0x8006F960: nop

;}
RECOMP_FUNC void func_80437CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437CF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80437CF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80437CF8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437CFC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80437D00: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80437D04: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80437D08: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x80437D0C: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x80437D10: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80437D14: lw          $a1, 0xD8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XD8);
    // 0x80437D18: bc1f        L_80437D90
    if (!c1cs) {
        // 0x80437D1C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80437D90;
    }
    // 0x80437D1C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80437D20: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80437D24: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80437D28: lbu         $t9, 0x44($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X44);
    // 0x80437D2C: bne         $t9, $zero, L_80437D88
    if (ctx->r25 != 0) {
        // 0x80437D30: nop
    
            goto L_80437D88;
    }
    // 0x80437D30: nop

    // 0x80437D34: lw          $t0, 0x54($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X54);
    // 0x80437D38: bltz        $t0, L_80437D88
    if (SIGNED(ctx->r8) < 0) {
        // 0x80437D3C: nop
    
            goto L_80437D88;
    }
    // 0x80437D3C: nop

    // 0x80437D40: lh          $t1, 0x13C($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X13C);
    // 0x80437D44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80437D48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80437D4C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80437D50: lwc1        $f16, 0x40($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X40);
    // 0x80437D54: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80437D58: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80437D5C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80437D60: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80437D64: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x80437D68: nop

    // 0x80437D6C: bc1t        L_80437D88
    if (c1cs) {
        // 0x80437D70: nop
    
            goto L_80437D88;
    }
    // 0x80437D70: nop

    // 0x80437D74: jal         0x80436BE0
    // 0x80437D78: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80436BE0(rdram, ctx);
        goto after_0;
    // 0x80437D78: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x80437D7C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80437D80: beq         $v0, $zero, L_80437E0C
    if (ctx->r2 == 0) {
        // 0x80437D84: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80437E0C;
    }
    // 0x80437D84: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
L_80437D88:
    // 0x80437D88: b           L_80437E0C
    // 0x80437D8C: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
        goto L_80437E0C;
    // 0x80437D8C: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_80437D90:
    // 0x80437D90: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80437D94: nop

    // 0x80437D98: bc1fl       L_80437E10
    if (!c1cs) {
        // 0x80437D9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80437E10;
    }
    goto skip_0;
    // 0x80437D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80437DA0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80437DA4: lw          $t3, 0x40($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X40);
    // 0x80437DA8: lbu         $t4, 0x5C($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X5C);
    // 0x80437DAC: bnel        $t4, $zero, L_80437E0C
    if (ctx->r12 != 0) {
        // 0x80437DB0: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_80437E0C;
    }
    goto skip_1;
    // 0x80437DB0: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x80437DB4: lw          $t5, 0x54($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X54);
    // 0x80437DB8: bgtzl       $t5, L_80437E0C
    if (SIGNED(ctx->r13) > 0) {
        // 0x80437DBC: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_80437E0C;
    }
    goto skip_2;
    // 0x80437DBC: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x80437DC0: lh          $t6, 0x13C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X13C);
    // 0x80437DC4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80437DC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80437DCC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80437DD0: lwc1        $f4, 0x44($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X44);
    // 0x80437DD4: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80437DD8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80437DDC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80437DE0: sub.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80437DE4: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80437DE8: nop

    // 0x80437DEC: bc1tl       L_80437E0C
    if (c1cs) {
        // 0x80437DF0: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_80437E0C;
    }
    goto skip_3;
    // 0x80437DF0: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x80437DF4: jal         0x80436C18
    // 0x80437DF8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80436C18(rdram, ctx);
        goto after_1;
    // 0x80437DF8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x80437DFC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80437E00: beq         $v0, $zero, L_80437E0C
    if (ctx->r2 == 0) {
        // 0x80437E04: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80437E0C;
    }
    // 0x80437E04: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80437E08: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_80437E0C:
    // 0x80437E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80437E10:
    // 0x80437E10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80437E14: jr          $ra
    // 0x80437E18: nop

    return;
    // 0x80437E18: nop

;}
RECOMP_FUNC void func_80401780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80401780: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80401784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80401788: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040178C: lw          $v1, 0x12C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X12C);
    // 0x80401790: bne         $v1, $zero, L_804017E8
    if (ctx->r3 != 0) {
        // 0x80401794: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_804017E8;
    }
    // 0x80401794: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80401798: lh          $v1, 0x144($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X144);
    // 0x8040179C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x804017A0: beq         $at, $zero, L_804017D8
    if (ctx->r1 == 0) {
        // 0x804017A4: lui         $at, 0x8040
        ctx->r1 = S32(RELOC_HI16(8, 0X7720) << 16);
            goto L_804017D8;
    }
    // 0x804017A4: lui         $at, 0x8040
    ctx->r1 = S32(RELOC_HI16(8, 0X7720) << 16);
    // 0x804017A8: lwc1        $f0, 0x7760($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(8, 0X7720));
    // 0x804017AC: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804017B0: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804017B4: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x804017B8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x804017BC: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804017C0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x804017C4: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x804017C8: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x804017CC: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x804017D0: b           L_804017EC
    // 0x804017D4: sw          $t7, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->r15;
        goto L_804017EC;
    // 0x804017D4: sw          $t7, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->r15;
L_804017D8:
    // 0x804017D8: jal         0x800447C8
    // 0x804017DC: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x804017DC: nop

    after_0:
    // 0x804017E0: b           L_804017F0
    // 0x804017E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804017F0;
    // 0x804017E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804017E8:
    // 0x804017E8: sw          $t8, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->r24;
L_804017EC:
    // 0x804017EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804017F0:
    // 0x804017F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804017F4: jr          $ra
    // 0x804017F8: nop

    return;
    // 0x804017F8: nop

;}
RECOMP_FUNC void func_804503F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804503F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804503FC: bltz        $a1, L_8045042C
    if (SIGNED(ctx->r5) < 0) {
        // 0x80450400: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8045042C;
    }
    // 0x80450400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80450404: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x80450408: beq         $at, $zero, L_8045042C
    if (ctx->r1 == 0) {
        // 0x8045040C: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_8045042C;
    }
    // 0x8045040C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80450410: lui         $v0, 0x8045
    ctx->r2 = S32(RELOC_HI16(98, 0X13204) << 16);
    // 0x80450414: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80450418: lw          $v0, 0x75E4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(98, 0X13204));
    // 0x8045041C: beql        $v0, $zero, L_80450430
    if (ctx->r2 == 0) {
        // 0x80450420: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80450430;
    }
    goto skip_0;
    // 0x80450420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80450424: jalr        $v0
    // 0x80450428: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80450428: nop

    after_0:
L_8045042C:
    // 0x8045042C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80450430:
    // 0x80450430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80450434: jr          $ra
    // 0x80450438: nop

    return;
    // 0x80450438: nop

;}
RECOMP_FUNC void func_805259E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805259E4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805259E8: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(324, 0X64) << 16);
    // 0x805259EC: addiu       $t6, $t6, 0x5574
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(324, 0X64));
    // 0x805259F0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805259F4: jr          $ra
    // 0x805259F8: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x805259F8: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_807152B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807152B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807152B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807152BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807152C0: jal         0x80714DD4
    // 0x807152C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80714DD4(rdram, ctx);
        goto after_0;
    // 0x807152C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807152C8: jal         0x80714E64
    // 0x807152CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80714E64(rdram, ctx);
        goto after_1;
    // 0x807152CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807152D0: jal         0x80714D40
    // 0x807152D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80714D40(rdram, ctx);
        goto after_2;
    // 0x807152D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807152D8: jal         0x80714B20
    // 0x807152DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80714B20(rdram, ctx);
        goto after_3;
    // 0x807152DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807152E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807152E4: bne         $v0, $at, L_80715308
    if (ctx->r2 != ctx->r1) {
        // 0x807152E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80715308;
    }
    // 0x807152E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807152EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807152F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807152F4: jal         0x80715C24
    // 0x807152F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80715C24(rdram, ctx);
        goto after_4;
    // 0x807152F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x807152FC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80715300: jal         0x80714A38
    // 0x80715304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80714A38(rdram, ctx);
        goto after_5;
    // 0x80715304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_80715308:
    // 0x80715308: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8071530C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80715310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80715314: jr          $ra
    // 0x80715318: nop

    return;
    // 0x80715318: nop

;}
RECOMP_FUNC void func_80024778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024778: lbu         $t6, 0x158($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X158);
    // 0x8002477C: bnel        $t6, $zero, L_80024790
    if (ctx->r14 != 0) {
        // 0x80024780: lw          $t7, 0x154($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X154);
            goto L_80024790;
    }
    goto skip_0;
    // 0x80024780: lw          $t7, 0x154($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X154);
    skip_0:
    // 0x80024784: jr          $ra
    // 0x80024788: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80024788: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002478C: lw          $t7, 0x154($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X154);
L_80024790:
    // 0x80024790: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x80024794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80024798: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8002479C: sw          $t8, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r24;
    // 0x800247A0: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800247A4: sltu        $at, $t8, $t1
    ctx->r1 = ctx->r24 < ctx->r9 ? 1 : 0;
    // 0x800247A8: bne         $at, $zero, L_800247DC
    if (ctx->r1 != 0) {
        // 0x800247AC: nop
    
            goto L_800247DC;
    }
    // 0x800247AC: nop

    // 0x800247B0: lbu         $t2, 0x158($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X158);
    // 0x800247B4: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800247B8: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800247BC: bne         $t4, $zero, L_800247CC
    if (ctx->r12 != 0) {
        // 0x800247C0: sb          $t3, 0x158($a0)
        MEM_B(0X158, ctx->r4) = ctx->r11;
            goto L_800247CC;
    }
    // 0x800247C0: sb          $t3, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r11;
    // 0x800247C4: jr          $ra
    // 0x800247C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x800247C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800247CC:
    // 0x800247CC: lw          $t5, 0x14C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X14C);
    // 0x800247D0: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x800247D4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800247D8: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
L_800247DC:
    // 0x800247DC: jr          $ra
    // 0x800247E0: nop

    return;
    // 0x800247E0: nop

;}
RECOMP_FUNC void func_80035BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035BC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035BD0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80035BD4: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80035BD8: lw          $v0, 0x144($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X144);
    // 0x80035BDC: beq         $v1, $at, L_80035C70
    if (ctx->r3 == ctx->r1) {
        // 0x80035BE0: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_80035C70;
    }
    // 0x80035BE0: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80035BE4: beql        $v1, $at, L_80035C74
    if (ctx->r3 == ctx->r1) {
        // 0x80035BE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035C74;
    }
    goto skip_0;
    // 0x80035BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80035BEC: lbu         $t6, 0x155($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X155);
    // 0x80035BF0: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x80035BF4: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x80035BF8: bnel        $t6, $zero, L_80035C74
    if (ctx->r14 != 0) {
        // 0x80035BFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035C74;
    }
    goto skip_1;
    // 0x80035BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80035C00: lw          $t7, 0xF10($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XF10);
    // 0x80035C04: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80035C08: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80035C0C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80035C10: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x80035C14: lw          $v1, 0xF14($t9)
    ctx->r3 = MEM_W(ctx->r25, 0XF14);
    // 0x80035C18: addiu       $t1, $zero, 0x35
    ctx->r9 = ADD32(0, 0X35);
    // 0x80035C1C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80035C20: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x80035C24: lw          $t0, 0x110($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X110);
    // 0x80035C28: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x80035C2C: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80035C30: bne         $at, $zero, L_80035C40
    if (ctx->r1 != 0) {
        // 0x80035C34: nop
    
            goto L_80035C40;
    }
    // 0x80035C34: nop

    // 0x80035C38: b           L_80035C70
    // 0x80035C3C: sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
        goto L_80035C70;
    // 0x80035C3C: sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
L_80035C40:
    // 0x80035C40: lw          $t2, 0xC0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XC0);
    // 0x80035C44: addiu       $t3, $zero, 0x30
    ctx->r11 = ADD32(0, 0X30);
    // 0x80035C48: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80035C4C: bnel        $at, $zero, L_80035C74
    if (ctx->r1 != 0) {
        // 0x80035C50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035C74;
    }
    goto skip_2;
    // 0x80035C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80035C54: sb          $t3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r11;
    // 0x80035C58: jal         0x800653D8
    // 0x80035C5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80035C5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80035C60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80035C64: andi        $t4, $v0, 0x3
    ctx->r12 = ctx->r2 & 0X3;
    // 0x80035C68: addiu       $t5, $t4, 0x6
    ctx->r13 = ADD32(ctx->r12, 0X6);
    // 0x80035C6C: sw          $t5, 0x140($a0)
    MEM_W(0X140, ctx->r4) = ctx->r13;
L_80035C70:
    // 0x80035C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035C74:
    // 0x80035C74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035C78: jr          $ra
    // 0x80035C7C: nop

    return;
    // 0x80035C7C: nop

;}
RECOMP_FUNC void func_80446D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446D70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80446D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80446D78: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446D7C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446D80: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80446D84: addu        $a1, $v1, $at
    ctx->r5 = ADD32(ctx->r3, ctx->r1);
    // 0x80446D88: lw          $v0, 0x6A28($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X6A28);
    // 0x80446D8C: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x80446D90: beq         $v0, $at, L_80446EA0
    if (ctx->r2 == ctx->r1) {
        // 0x80446D94: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80446EA0;
    }
    // 0x80446D94: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80446D98: bne         $v0, $at, L_80446DA8
    if (ctx->r2 != ctx->r1) {
        // 0x80446D9C: nop
    
            goto L_80446DA8;
    }
    // 0x80446D9C: nop

    // 0x80446DA0: b           L_80446F48
    // 0x80446DA4: sw          $zero, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = 0;
        goto L_80446F48;
    // 0x80446DA4: sw          $zero, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = 0;
L_80446DA8:
    // 0x80446DA8: bne         $v0, $zero, L_80446DBC
    if (ctx->r2 != 0) {
        // 0x80446DAC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80446DBC;
    }
    // 0x80446DAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80446DB0: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80446DB4: b           L_80446F48
    // 0x80446DB8: sw          $t6, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r14;
        goto L_80446F48;
    // 0x80446DB8: sw          $t6, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r14;
L_80446DBC:
    // 0x80446DBC: bne         $v0, $at, L_80446DCC
    if (ctx->r2 != ctx->r1) {
        // 0x80446DC0: addiu       $t7, $zero, 0x780
        ctx->r15 = ADD32(0, 0X780);
            goto L_80446DCC;
    }
    // 0x80446DC0: addiu       $t7, $zero, 0x780
    ctx->r15 = ADD32(0, 0X780);
    // 0x80446DC4: b           L_80446F48
    // 0x80446DC8: sw          $t7, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r15;
        goto L_80446F48;
    // 0x80446DC8: sw          $t7, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r15;
L_80446DCC:
    // 0x80446DCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80446DD0: bne         $v0, $at, L_80446DE0
    if (ctx->r2 != ctx->r1) {
        // 0x80446DD4: addiu       $t8, $zero, 0x780
        ctx->r24 = ADD32(0, 0X780);
            goto L_80446DE0;
    }
    // 0x80446DD4: addiu       $t8, $zero, 0x780
    ctx->r24 = ADD32(0, 0X780);
    // 0x80446DD8: b           L_80446F48
    // 0x80446DDC: sw          $t8, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r24;
        goto L_80446F48;
    // 0x80446DDC: sw          $t8, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r24;
L_80446DE0:
    // 0x80446DE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80446DE4: bne         $v0, $at, L_80446DF4
    if (ctx->r2 != ctx->r1) {
        // 0x80446DE8: addiu       $t9, $zero, 0x780
        ctx->r25 = ADD32(0, 0X780);
            goto L_80446DF4;
    }
    // 0x80446DE8: addiu       $t9, $zero, 0x780
    ctx->r25 = ADD32(0, 0X780);
    // 0x80446DEC: b           L_80446F48
    // 0x80446DF0: sw          $t9, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r25;
        goto L_80446F48;
    // 0x80446DF0: sw          $t9, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r25;
L_80446DF4:
    // 0x80446DF4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80446DF8: bne         $v0, $at, L_80446E08
    if (ctx->r2 != ctx->r1) {
        // 0x80446DFC: addiu       $t0, $zero, 0x780
        ctx->r8 = ADD32(0, 0X780);
            goto L_80446E08;
    }
    // 0x80446DFC: addiu       $t0, $zero, 0x780
    ctx->r8 = ADD32(0, 0X780);
    // 0x80446E00: b           L_80446F48
    // 0x80446E04: sw          $t0, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r8;
        goto L_80446F48;
    // 0x80446E04: sw          $t0, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r8;
L_80446E08:
    // 0x80446E08: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80446E0C: bne         $v0, $at, L_80446E1C
    if (ctx->r2 != ctx->r1) {
        // 0x80446E10: addiu       $t1, $zero, 0x780
        ctx->r9 = ADD32(0, 0X780);
            goto L_80446E1C;
    }
    // 0x80446E10: addiu       $t1, $zero, 0x780
    ctx->r9 = ADD32(0, 0X780);
    // 0x80446E14: b           L_80446F48
    // 0x80446E18: sw          $t1, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r9;
        goto L_80446F48;
    // 0x80446E18: sw          $t1, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r9;
L_80446E1C:
    // 0x80446E1C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80446E20: bne         $v0, $at, L_80446E30
    if (ctx->r2 != ctx->r1) {
        // 0x80446E24: addiu       $t2, $zero, 0x780
        ctx->r10 = ADD32(0, 0X780);
            goto L_80446E30;
    }
    // 0x80446E24: addiu       $t2, $zero, 0x780
    ctx->r10 = ADD32(0, 0X780);
    // 0x80446E28: b           L_80446F48
    // 0x80446E2C: sw          $t2, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r10;
        goto L_80446F48;
    // 0x80446E2C: sw          $t2, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r10;
L_80446E30:
    // 0x80446E30: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80446E34: bne         $v0, $at, L_80446E44
    if (ctx->r2 != ctx->r1) {
        // 0x80446E38: addiu       $t3, $zero, 0x780
        ctx->r11 = ADD32(0, 0X780);
            goto L_80446E44;
    }
    // 0x80446E38: addiu       $t3, $zero, 0x780
    ctx->r11 = ADD32(0, 0X780);
    // 0x80446E3C: b           L_80446F48
    // 0x80446E40: sw          $t3, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r11;
        goto L_80446F48;
    // 0x80446E40: sw          $t3, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r11;
L_80446E44:
    // 0x80446E44: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80446E48: bne         $v0, $at, L_80446E58
    if (ctx->r2 != ctx->r1) {
        // 0x80446E4C: addiu       $t4, $zero, 0x780
        ctx->r12 = ADD32(0, 0X780);
            goto L_80446E58;
    }
    // 0x80446E4C: addiu       $t4, $zero, 0x780
    ctx->r12 = ADD32(0, 0X780);
    // 0x80446E50: b           L_80446F48
    // 0x80446E54: sw          $t4, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r12;
        goto L_80446F48;
    // 0x80446E54: sw          $t4, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r12;
L_80446E58:
    // 0x80446E58: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80446E5C: bne         $v0, $at, L_80446E6C
    if (ctx->r2 != ctx->r1) {
        // 0x80446E60: addiu       $t5, $zero, 0x780
        ctx->r13 = ADD32(0, 0X780);
            goto L_80446E6C;
    }
    // 0x80446E60: addiu       $t5, $zero, 0x780
    ctx->r13 = ADD32(0, 0X780);
    // 0x80446E64: b           L_80446F48
    // 0x80446E68: sw          $t5, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r13;
        goto L_80446F48;
    // 0x80446E68: sw          $t5, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r13;
L_80446E6C:
    // 0x80446E6C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80446E70: bne         $v0, $at, L_80446E80
    if (ctx->r2 != ctx->r1) {
        // 0x80446E74: addiu       $t6, $zero, 0x780
        ctx->r14 = ADD32(0, 0X780);
            goto L_80446E80;
    }
    // 0x80446E74: addiu       $t6, $zero, 0x780
    ctx->r14 = ADD32(0, 0X780);
    // 0x80446E78: b           L_80446F48
    // 0x80446E7C: sw          $t6, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r14;
        goto L_80446F48;
    // 0x80446E7C: sw          $t6, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r14;
L_80446E80:
    // 0x80446E80: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80446E84: bne         $v0, $at, L_80446E98
    if (ctx->r2 != ctx->r1) {
        // 0x80446E88: addiu       $t8, $zero, 0xB40
        ctx->r24 = ADD32(0, 0XB40);
            goto L_80446E98;
    }
    // 0x80446E88: addiu       $t8, $zero, 0xB40
    ctx->r24 = ADD32(0, 0XB40);
    // 0x80446E8C: addiu       $t7, $zero, 0x780
    ctx->r15 = ADD32(0, 0X780);
    // 0x80446E90: b           L_80446F48
    // 0x80446E94: sw          $t7, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r15;
        goto L_80446F48;
    // 0x80446E94: sw          $t7, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r15;
L_80446E98:
    // 0x80446E98: b           L_80446F48
    // 0x80446E9C: sw          $t8, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r24;
        goto L_80446F48;
    // 0x80446E9C: sw          $t8, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r24;
L_80446EA0:
    // 0x80446EA0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446EA4: ori         $at, $at, 0x6A20
    ctx->r1 = ctx->r1 | 0X6A20;
    // 0x80446EA8: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80446EAC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80446EB0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80446EB4: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80446EB8: bne         $a0, $at, L_80446ECC
    if (ctx->r4 != ctx->r1) {
        // 0x80446EBC: nop
    
            goto L_80446ECC;
    }
    // 0x80446EBC: nop

    // 0x80446EC0: lw          $t9, 0x6A38($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X6A38);
    // 0x80446EC4: b           L_80446F48
    // 0x80446EC8: sw          $t9, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r25;
        goto L_80446F48;
    // 0x80446EC8: sw          $t9, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r25;
L_80446ECC:
    // 0x80446ECC: bgez        $a2, L_80446EE4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80446ED0: nop
    
            goto L_80446EE4;
    }
    // 0x80446ED0: nop

    // 0x80446ED4: lw          $t0, 0x6A3C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X6A3C);
    // 0x80446ED8: addiu       $t1, $t0, 0x780
    ctx->r9 = ADD32(ctx->r8, 0X780);
    // 0x80446EDC: b           L_80446F48
    // 0x80446EE0: sw          $t1, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r9;
        goto L_80446F48;
    // 0x80446EE0: sw          $t1, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r9;
L_80446EE4:
    // 0x80446EE4: bne         $a2, $zero, L_80446F00
    if (ctx->r6 != 0) {
        // 0x80446EE8: sll         $t2, $a2, 2
        ctx->r10 = S32(ctx->r6 << 2);
            goto L_80446F00;
    }
    // 0x80446EE8: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80446EEC: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x80446EF0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80446EF4: addiu       $t5, $t4, 0x3C0
    ctx->r13 = ADD32(ctx->r12, 0X3C0);
    // 0x80446EF8: b           L_80446F48
    // 0x80446EFC: sw          $t5, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r13;
        goto L_80446F48;
    // 0x80446EFC: sw          $t5, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r13;
L_80446F00:
    // 0x80446F00: blez        $a2, L_80446F30
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80446F04: slti        $at, $a2, 0xB
        ctx->r1 = SIGNED(ctx->r6) < 0XB ? 1 : 0;
            goto L_80446F30;
    }
    // 0x80446F04: slti        $at, $a2, 0xB
    ctx->r1 = SIGNED(ctx->r6) < 0XB ? 1 : 0;
    // 0x80446F08: beq         $at, $zero, L_80446F30
    if (ctx->r1 == 0) {
        // 0x80446F0C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80446F30;
    }
    // 0x80446F0C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80446F10: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80446F14: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80446F18: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80446F1C: jal         0x80446D40
    // 0x80446F20: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80446D40(rdram, ctx);
        goto after_0;
    // 0x80446F20: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80446F24: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80446F28: b           L_80446F48
    // 0x80446F2C: sw          $v0, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r2;
        goto L_80446F48;
    // 0x80446F2C: sw          $v0, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r2;
L_80446F30:
    // 0x80446F30: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80446F34: bne         $a2, $at, L_80446F48
    if (ctx->r6 != ctx->r1) {
        // 0x80446F38: sll         $t8, $a2, 2
        ctx->r24 = S32(ctx->r6 << 2);
            goto L_80446F48;
    }
    // 0x80446F38: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80446F3C: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80446F40: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80446F44: sw          $t0, 0xA54($v1)
    MEM_W(0XA54, ctx->r3) = ctx->r8;
L_80446F48:
    // 0x80446F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80446F4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80446F50: jr          $ra
    // 0x80446F54: nop

    return;
    // 0x80446F54: nop

;}
RECOMP_FUNC void func_804BC24C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BC24C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x804BC250: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BC254: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BC258: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x804BC25C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804BC260: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x804BC264: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804BC268: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x804BC26C: lw          $s0, 0x1F4($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X1F4);
    // 0x804BC270: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x804BC274: jal         0x8004921C
    // 0x804BC278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804BC278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x804BC27C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x804BC280: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x804BC284: jal         0x8004921C
    // 0x804BC288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804BC288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804BC28C: lbu         $t9, 0x27($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X27);
    // 0x804BC290: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x804BC294: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x804BC298: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804BC29C: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x804BC2A0: lbu         $t3, 0x145($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X145);
    // 0x804BC2A4: lw          $t5, 0x168($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X168);
    // 0x804BC2A8: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x804BC2AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804BC2B0: lw          $t6, 0x80($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X80);
    // 0x804BC2B4: mflo        $t2
    ctx->r10 = lo;
    // 0x804BC2B8: nop

    // 0x804BC2BC: nop

    // 0x804BC2C0: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804BC2C4: mflo        $t4
    ctx->r12 = lo;
    // 0x804BC2C8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x804BC2CC: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x804BC2D0: lw          $t8, 0x16C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X16C);
    // 0x804BC2D4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x804BC2D8: jal         0x80077338
    // 0x804BC2DC: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x804BC2DC: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    after_2:
    // 0x804BC2E0: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x804BC2E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x804BC2E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804BC2EC: jal         0x8007711C
    // 0x804BC2F0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x804BC2F0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_3:
    // 0x804BC2F4: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC2F8: lui         $t5, 0xFD50
    ctx->r13 = S32(0XFD50 << 16);
    // 0x804BC2FC: lui         $t9, 0x701
    ctx->r25 = S32(0X701 << 16);
    // 0x804BC300: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x804BC304: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x804BC308: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x804BC30C: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x804BC310: ori         $t9, $t9, 0x4050
    ctx->r25 = ctx->r25 | 0X4050;
    // 0x804BC314: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x804BC318: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x804BC31C: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC320: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x804BC324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BC328: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x804BC32C: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x804BC330: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x804BC334: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x804BC338: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC33C: lui         $t8, 0x71F
    ctx->r24 = S32(0X71F << 16);
    // 0x804BC340: ori         $t8, $t8, 0xF200
    ctx->r24 = ctx->r24 | 0XF200;
    // 0x804BC344: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x804BC348: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x804BC34C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x804BC350: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x804BC354: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC358: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x804BC35C: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x804BC360: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x804BC364: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x804BC368: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x804BC36C: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x804BC370: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC374: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x804BC378: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x804BC37C: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x804BC380: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
    // 0x804BC384: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x804BC388: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x804BC38C: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC390: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x804BC394: ori         $t7, $t7, 0x4050
    ctx->r15 = ctx->r15 | 0X4050;
    // 0x804BC398: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x804BC39C: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x804BC3A0: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x804BC3A4: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x804BC3A8: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC3AC: lui         $t3, 0x7
    ctx->r11 = S32(0X7 << 16);
    // 0x804BC3B0: ori         $t3, $t3, 0xC07C
    ctx->r11 = ctx->r11 | 0XC07C;
    // 0x804BC3B4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x804BC3B8: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x804BC3BC: lui         $t2, 0xF200
    ctx->r10 = S32(0XF200 << 16);
    // 0x804BC3C0: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x804BC3C4: jal         0x804BBDE0
    // 0x804BC3C8: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    func_804BBDE0(rdram, ctx);
        goto after_4;
    // 0x804BC3C8: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    after_4:
    // 0x804BC3CC: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC3D0: lui         $t0, 0x400
    ctx->r8 = S32(0X400 << 16);
    // 0x804BC3D4: ori         $t0, $t0, 0x40FF
    ctx->r8 = ctx->r8 | 0X40FF;
    // 0x804BC3D8: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x804BC3DC: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x804BC3E0: sw          $s0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r16;
    // 0x804BC3E4: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x804BC3E8: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC3EC: lui         $a0, 0x804C
    ctx->r4 = S32(RELOC_HI16(191, 0X3DF0) << 16);
    // 0x804BC3F0: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x804BC3F4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x804BC3F8: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x804BC3FC: addiu       $a0, $a0, -0x8E0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(191, 0X3DF0));
    // 0x804BC400: sw          $a0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r4;
    // 0x804BC404: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x804BC408: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC40C: addiu       $t2, $s0, 0xE0
    ctx->r10 = ADD32(ctx->r16, 0XE0);
    // 0x804BC410: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x804BC414: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x804BC418: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x804BC41C: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x804BC420: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x804BC424: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC428: addiu       $t8, $s0, 0x1C0
    ctx->r24 = ADD32(ctx->r16, 0X1C0);
    // 0x804BC42C: ori         $t7, $t7, 0x38DF
    ctx->r15 = ctx->r15 | 0X38DF;
    // 0x804BC430: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x804BC434: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
    // 0x804BC438: sw          $a0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r4;
    // 0x804BC43C: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x804BC440: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC444: lui         $t3, 0x804C
    ctx->r11 = S32(RELOC_HI16(191, 0X3E68) << 16);
    // 0x804BC448: addiu       $t3, $t3, -0x868
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(191, 0X3E68));
    // 0x804BC44C: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x804BC450: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x804BC454: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x804BC458: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x804BC45C: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC460: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x804BC464: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
    // 0x804BC468: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x804BC46C: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x804BC470: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x804BC474: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC478: sw          $t5, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r13;
    // 0x804BC47C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804BC480: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BC484: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x804BC488: jr          $ra
    // 0x804BC48C: nop

    return;
    // 0x804BC48C: nop

;}
RECOMP_FUNC void func_8001B140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001B144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B148: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001B14C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001B150: jal         0x80019D30
    // 0x8001B154: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80019D30(rdram, ctx);
        goto after_0;
    // 0x8001B154: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8001B158: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8001B15C: lh          $a2, -0x6CF0($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X6CF0);
    // 0x8001B160: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001B164: jal         0x80019DB8
    // 0x8001B168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80019DB8(rdram, ctx);
        goto after_1;
    // 0x8001B168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8001B16C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001B174: jr          $ra
    // 0x8001B178: nop

    return;
    // 0x8001B178: nop

;}
RECOMP_FUNC void func_806FC910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FC910: lui         $v0, 0x8070
    ctx->r2 = S32(RELOC_HI16(703, 0X28) << 16);
    // 0x806FC914: addiu       $v0, $v0, -0x36C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(703, 0X28));
    // 0x806FC918: jr          $ra
    // 0x806FC91C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806FC91C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_807A6DAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6DAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807A6DB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A6DB4: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    // 0x807A6DB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807A6DBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A6DC0: beql        $a2, $at, L_807A6E10
    if (ctx->r6 == ctx->r1) {
        // 0x807A6DC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807A6E10;
    }
    goto skip_0;
    // 0x807A6DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807A6DC8: jal         0x807A7138
    // 0x807A6DCC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_807A7138(rdram, ctx);
        goto after_0;
    // 0x807A6DCC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x807A6DD0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x807A6DD4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x807A6DD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807A6DDC: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807A6DE0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x807A6DE4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x807A6DE8: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x807A6DEC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x807A6DF0: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x807A6DF4: lwc1        $f16, 0x8C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x807A6DF8: jal         0x807A67CC
    // 0x807A6DFC: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    func_807A67CC(rdram, ctx);
        goto after_1;
    // 0x807A6DFC: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x807A6E00: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x807A6E04: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x807A6E08: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x807A6E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A6E10:
    // 0x807A6E10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807A6E14: jr          $ra
    // 0x807A6E18: nop

    return;
    // 0x807A6E18: nop

;}
RECOMP_FUNC void func_80736E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736E14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80736E18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736E1C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80736E20: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80736E24: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(736, 0X39BC) << 16);
    // 0x80736E28: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80736E2C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x80736E30: addiu       $t7, $t7, -0x6BE4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(736, 0X39BC));
    // 0x80736E34: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80736E38: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80736E3C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80736E40: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x80736E44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80736E48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80736E4C: jal         0x80736E64
    // 0x80736E50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80736E64(rdram, ctx);
        goto after_0;
    // 0x80736E50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80736E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80736E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80736E5C: jr          $ra
    // 0x80736E60: nop

    return;
    // 0x80736E60: nop

;}
RECOMP_FUNC void func_8002CBF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CBF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002CBF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CBF8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002CBFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002CC00: jal         0x8002CB84
    // 0x8002CC04: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8002CB84(rdram, ctx);
        goto after_0;
    // 0x8002CC04: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002CC08: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8002CC0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002CC10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002CC14: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002CC18: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x8002CC1C: lwc1        $f6, -0x60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X60);
    // 0x8002CC20: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    // 0x8002CC24: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CC28: sw          $zero, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = 0;
    // 0x8002CC2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CC30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002CC34: jr          $ra
    // 0x8002CC38: nop

    return;
    // 0x8002CC38: nop

;}
RECOMP_FUNC void func_804F3A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F3A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804F3A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F3A18: jal         0x8005780C
    // 0x804F3A1C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    func_8005780C(rdram, ctx);
        goto after_0;
    // 0x804F3A1C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x804F3A20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F3A24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804F3A28: jr          $ra
    // 0x804F3A2C: nop

    return;
    // 0x804F3A2C: nop

;}
RECOMP_FUNC void func_80075170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075170: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80075174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075178: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007517C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80075180: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80075184: lw          $v1, 0x248($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X248);
    // 0x80075188: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8007518C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80075190: jal         0x800825F0
    // 0x80075194: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80075194: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80075198: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8007519C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800751A0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800751A4: beq         $v1, $zero, L_800751E4
    if (ctx->r3 == 0) {
        // 0x800751A8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800751E4;
    }
    // 0x800751A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800751AC:
    // 0x800751AC: bnel        $v1, $a1, L_800751D8
    if (ctx->r3 != ctx->r5) {
        // 0x800751B0: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_800751D8;
    }
    goto skip_0;
    // 0x800751B0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    skip_0:
    // 0x800751B4: beq         $a2, $zero, L_800751C8
    if (ctx->r6 == 0) {
        // 0x800751B8: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_800751C8;
    }
    // 0x800751B8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800751BC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800751C0: b           L_800751E4
    // 0x800751C4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
        goto L_800751E4;
    // 0x800751C4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_800751C8:
    // 0x800751C8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800751CC: b           L_800751E4
    // 0x800751D0: sw          $t8, 0x248($t9)
    MEM_W(0X248, ctx->r25) = ctx->r24;
        goto L_800751E4;
    // 0x800751D0: sw          $t8, 0x248($t9)
    MEM_W(0X248, ctx->r25) = ctx->r24;
    // 0x800751D4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800751D8:
    // 0x800751D8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800751DC: bne         $v1, $zero, L_800751AC
    if (ctx->r3 != 0) {
        // 0x800751E0: nop
    
            goto L_800751AC;
    }
    // 0x800751E0: nop

L_800751E4:
    // 0x800751E4: jal         0x800825F0
    // 0x800751E8: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800751E8: nop

    after_1:
    // 0x800751EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800751F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800751F4: jr          $ra
    // 0x800751F8: nop

    return;
    // 0x800751F8: nop

;}
RECOMP_FUNC void func_805DA164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA164: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805DA168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DA16C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x805DA170: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805DA174: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(477, 0XBA4) << 16);
    // 0x805DA178: lwc1        $f10, -0x541C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(477, 0XBA4));
    // 0x805DA17C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x805DA180: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805DA184: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x805DA188: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805DA18C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x805DA190: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x805DA194: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x805DA198: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805DA19C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805DA1A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805DA1A4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805DA1A8: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x805DA1AC: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x805DA1B0: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x805DA1B4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x805DA1B8: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x805DA1BC: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x805DA1C0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x805DA1C4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x805DA1C8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805DA1CC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x805DA1D0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x805DA1D4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x805DA1D8: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x805DA1DC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x805DA1E0: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x805DA1E4: jalr        $t9
    // 0x805DA1E8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805DA1E8: nop

    after_0:
    // 0x805DA1EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DA1F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x805DA1F4: jr          $ra
    // 0x805DA1F8: nop

    return;
    // 0x805DA1F8: nop

;}
RECOMP_FUNC void func_80434D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434D00: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80434D04: lui         $at, 0x436F
    ctx->r1 = S32(0X436F << 16);
    // 0x80434D08: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80434D0C: lw          $v1, 0x5C0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C0);
    // 0x80434D10: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(71, 0X2AE0) << 16);
    // 0x80434D14: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80434D18: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80434D1C: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80434D20: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80434D24: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80434D28: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80434D2C: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80434D30: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80434D34: addu        $a2, $v0, $t6
    ctx->r6 = ADD32(ctx->r2, ctx->r14);
    // 0x80434D38: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80434D3C: lwc1        $f14, 0x6590($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(71, 0X2AE0));
    // 0x80434D40: addiu       $a3, $zero, 0x59
    ctx->r7 = ADD32(0, 0X59);
    // 0x80434D44: lui         $t2, 0xF600
    ctx->r10 = S32(0XF600 << 16);
    // 0x80434D48: addiu       $a1, $v0, 0x5CC
    ctx->r5 = ADD32(ctx->r2, 0X5CC);
    // 0x80434D4C: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
L_80434D50:
    // 0x80434D50: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80434D54: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80434D58: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x80434D5C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80434D60: bc1f        L_80434ED8
    if (!c1cs) {
        // 0x80434D64: nop
    
            goto L_80434ED8;
    }
    // 0x80434D64: nop

    // 0x80434D68: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x80434D6C: nop

    // 0x80434D70: bc1f        L_80434ED8
    if (!c1cs) {
        // 0x80434D74: nop
    
            goto L_80434ED8;
    }
    // 0x80434D74: nop

    // 0x80434D78: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80434D7C: nop

    // 0x80434D80: bc1f        L_80434ED8
    if (!c1cs) {
        // 0x80434D84: nop
    
            goto L_80434ED8;
    }
    // 0x80434D84: nop

    // 0x80434D88: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x80434D8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80434D90: bc1f        L_80434ED8
    if (!c1cs) {
        // 0x80434D94: nop
    
            goto L_80434ED8;
    }
    // 0x80434D94: nop

    // 0x80434D98: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80434D9C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80434DA0: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x80434DA4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80434DA8: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80434DAC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80434DB0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80434DB4: nop

    // 0x80434DB8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80434DBC: beql        $a0, $zero, L_80434E0C
    if (ctx->r4 == 0) {
        // 0x80434DC0: mfc1        $a0, $f4
        ctx->r4 = (int32_t)ctx->f4.u32l;
            goto L_80434E0C;
    }
    goto skip_0;
    // 0x80434DC0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x80434DC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80434DC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80434DCC: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80434DD0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80434DD4: nop

    // 0x80434DD8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80434DDC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80434DE0: nop

    // 0x80434DE4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80434DE8: bne         $a0, $zero, L_80434E00
    if (ctx->r4 != 0) {
        // 0x80434DEC: nop
    
            goto L_80434E00;
    }
    // 0x80434DEC: nop

    // 0x80434DF0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80434DF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80434DF8: b           L_80434E18
    // 0x80434DFC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80434E18;
    // 0x80434DFC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80434E00:
    // 0x80434E00: b           L_80434E18
    // 0x80434E04: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80434E18;
    // 0x80434E04: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80434E08: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
L_80434E0C:
    // 0x80434E0C: nop

    // 0x80434E10: bltz        $a0, L_80434E00
    if (SIGNED(ctx->r4) < 0) {
        // 0x80434E14: nop
    
            goto L_80434E00;
    }
    // 0x80434E14: nop

L_80434E18:
    // 0x80434E18: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80434E1C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80434E20: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x80434E24: andi        $t3, $t9, 0x3FF
    ctx->r11 = ctx->r25 & 0X3FF;
    // 0x80434E28: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80434E2C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80434E30: sll         $t4, $t3, 14
    ctx->r12 = S32(ctx->r11 << 14);
    // 0x80434E34: or          $t5, $t4, $t2
    ctx->r13 = ctx->r12 | ctx->r10;
    // 0x80434E38: cvt.w.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80434E3C: andi        $t3, $a0, 0x3FF
    ctx->r11 = ctx->r4 & 0X3FF;
    // 0x80434E40: sll         $t4, $t3, 14
    ctx->r12 = S32(ctx->r11 << 14);
    // 0x80434E44: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80434E48: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80434E4C: nop

    // 0x80434E50: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80434E54: beql        $t0, $zero, L_80434EA4
    if (ctx->r8 == 0) {
        // 0x80434E58: mfc1        $t0, $f6
        ctx->r8 = (int32_t)ctx->f6.u32l;
            goto L_80434EA4;
    }
    goto skip_1;
    // 0x80434E58: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x80434E5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80434E60: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80434E64: sub.s       $f6, $f2, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80434E68: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80434E6C: nop

    // 0x80434E70: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80434E74: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80434E78: nop

    // 0x80434E7C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80434E80: bne         $t0, $zero, L_80434E98
    if (ctx->r8 != 0) {
        // 0x80434E84: nop
    
            goto L_80434E98;
    }
    // 0x80434E84: nop

    // 0x80434E88: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80434E8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80434E90: b           L_80434EB0
    // 0x80434E94: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80434EB0;
    // 0x80434E94: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80434E98:
    // 0x80434E98: b           L_80434EB0
    // 0x80434E9C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80434EB0;
    // 0x80434E9C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80434EA0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
L_80434EA4:
    // 0x80434EA4: nop

    // 0x80434EA8: bltz        $t0, L_80434E98
    if (SIGNED(ctx->r8) < 0) {
        // 0x80434EAC: nop
    
            goto L_80434E98;
    }
    // 0x80434EAC: nop

L_80434EB0:
    // 0x80434EB0: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x80434EB4: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x80434EB8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80434EBC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80434EC0: andi        $t6, $t0, 0x3FF
    ctx->r14 = ctx->r8 & 0X3FF;
    // 0x80434EC4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80434EC8: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x80434ECC: or          $t5, $t4, $t7
    ctx->r13 = ctx->r12 | ctx->r15;
    // 0x80434ED0: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80434ED4: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_80434ED8:
    // 0x80434ED8: bgezl       $a3, L_80434D50
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80434EDC: lwc1        $f0, 0x0($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
            goto L_80434D50;
    }
    goto skip_2;
    // 0x80434EDC: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    skip_2:
    // 0x80434EE0: lui         $t8, 0xB800
    ctx->r24 = S32(0XB800 << 16);
    // 0x80434EE4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80434EE8: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80434EEC: jr          $ra
    // 0x80434EF0: sw          $v1, 0x5C0($v0)
    MEM_W(0X5C0, ctx->r2) = ctx->r3;
    return;
    // 0x80434EF0: sw          $v1, 0x5C0($v0)
    MEM_W(0X5C0, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_800422B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800422B4: lw          $v0, 0x11C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X11C);
    // 0x800422B8: beq         $v0, $zero, L_800422C4
    if (ctx->r2 == 0) {
        // 0x800422BC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800422C4;
    }
    // 0x800422BC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800422C0: sw          $v0, 0x11C($a0)
    MEM_W(0X11C, ctx->r4) = ctx->r2;
L_800422C4:
    // 0x800422C4: jr          $ra
    // 0x800422C8: nop

    return;
    // 0x800422C8: nop

;}
RECOMP_FUNC void func_804CBB50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CBB50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804CBB54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CBB58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804CBB5C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x804CBB60: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x804CBB64: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x804CBB68: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x804CBB6C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x804CBB70: jal         0x80048114
    // 0x804CBB74: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80048114(rdram, ctx);
        goto after_0;
    // 0x804CBB74: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x804CBB78: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x804CBB7C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804CBB80: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
    // 0x804CBB84: jal         0x8005FB2C
    // 0x804CBB88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8005FB2C(rdram, ctx);
        goto after_1;
    // 0x804CBB88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x804CBB8C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x804CBB90: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804CBB94: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x804CBB98: sh          $t9, 0x10($t1)
    MEM_H(0X10, ctx->r9) = ctx->r25;
    // 0x804CBB9C: jal         0x8005FA48
    // 0x804CBBA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8005FA48(rdram, ctx);
        goto after_2;
    // 0x804CBBA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x804CBBA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CBBA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804CBBAC: jr          $ra
    // 0x804CBBB0: nop

    return;
    // 0x804CBBB0: nop

;}
RECOMP_FUNC void func_8004FA64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FA64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004FA68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004FA6C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8004FA70: lw          $a0, 0x1B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1B8);
    // 0x8004FA74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004FA78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004FA7C: lh          $t6, 0x52($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X52);
    // 0x8004FA80: addiu       $t7, $t6, 0xF
    ctx->r15 = ADD32(ctx->r14, 0XF);
    // 0x8004FA84: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8004FA88: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004FA8C: sra         $t0, $t9, 4
    ctx->r8 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8004FA90: sh          $t0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r8;
    // 0x8004FA94: lh          $t1, 0x54($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X54);
    // 0x8004FA98: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8004FA9C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x8004FAA0: addiu       $t2, $t1, 0xF
    ctx->r10 = ADD32(ctx->r9, 0XF);
    // 0x8004FAA4: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8004FAA8: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8004FAAC: sra         $t5, $t4, 4
    ctx->r13 = S32(SIGNED(ctx->r12) >> 4);
    // 0x8004FAB0: jal         0x8004F9B0
    // 0x8004FAB4: sh          $t5, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r13;
    func_8004F9B0(rdram, ctx);
        goto after_0;
    // 0x8004FAB4: sh          $t5, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r13;
    after_0:
    // 0x8004FAB8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8004FABC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8004FAC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004FAC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004FAC8: jal         0x8004F9B0
    // 0x8004FACC: sh          $v0, 0x3E($a3)
    MEM_H(0X3E, ctx->r7) = ctx->r2;
    func_8004F9B0(rdram, ctx);
        goto after_1;
    // 0x8004FACC: sh          $v0, 0x3E($a3)
    MEM_H(0X3E, ctx->r7) = ctx->r2;
    after_1:
    // 0x8004FAD0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8004FAD4: sh          $v0, 0x40($a3)
    MEM_H(0X40, ctx->r7) = ctx->r2;
    // 0x8004FAD8: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x8004FADC: sh          $t6, 0x5A($a3)
    MEM_H(0X5A, ctx->r7) = ctx->r14;
    // 0x8004FAE0: lh          $t7, 0x5A($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X5A);
    // 0x8004FAE4: sh          $t7, 0x42($a3)
    MEM_H(0X42, ctx->r7) = ctx->r15;
    // 0x8004FAE8: lh          $t8, 0x18($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X18);
    // 0x8004FAEC: sh          $t8, 0x5C($a3)
    MEM_H(0X5C, ctx->r7) = ctx->r24;
    // 0x8004FAF0: lh          $t9, 0x5C($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X5C);
    // 0x8004FAF4: sh          $t9, 0x44($a3)
    MEM_H(0X44, ctx->r7) = ctx->r25;
    // 0x8004FAF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004FAFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004FB00: jr          $ra
    // 0x8004FB04: nop

    return;
    // 0x8004FB04: nop

;}
RECOMP_FUNC void func_8007EE28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EE28: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007EE2C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8007EE30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007EE34: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8007EE38: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8007EE3C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8007EE40: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8007EE44: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x8007EE48: lw          $a3, 0x70($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X70);
    // 0x8007EE4C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8007EE50: sw          $v0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r2;
    // 0x8007EE54: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8007EE58: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x8007EE5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007EE60: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x8007EE64: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x8007EE68: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8007EE6C: addiu       $v1, $v1, -0x1E0
    ctx->r3 = ADD32(ctx->r3, -0X1E0);
    // 0x8007EE70: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
    // 0x8007EE74: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8007EE78: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8007EE7C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x8007EE80: subu        $t0, $t6, $t7
    ctx->r8 = SUB32(ctx->r14, ctx->r15);
    // 0x8007EE84: sw          $t0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r8;
    // 0x8007EE88: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8007EE8C: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
    // 0x8007EE90: lw          $a2, 0x300($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X300);
    // 0x8007EE94: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8007EE98: lw          $t1, 0x7C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X7C);
    // 0x8007EE9C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8007EEA0: lw          $t2, 0x54($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X54);
    // 0x8007EEA4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8007EEA8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8007EEAC: lw          $t3, 0x5C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X5C);
    // 0x8007EEB0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8007EEB4: lw          $t4, 0x58($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X58);
    // 0x8007EEB8: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x8007EEBC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8007EEC0: jal         0x8007E47C
    // 0x8007EEC4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    ViMode_Configure(rdram, ctx);
        goto after_0;
    // 0x8007EEC4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    after_0:
    // 0x8007EEC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007EECC: jal         0x8007EAC8
    // 0x8007EED0: lw          $a1, 0x80($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X80);
    ViMode_ConfigureFeatures(rdram, ctx);
        goto after_1;
    // 0x8007EED0: lw          $a1, 0x80($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X80);
    after_1:
    // 0x8007EED4: jal         0x80087010
    // 0x8007EED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osViSetMode_recomp(rdram, ctx);
        goto after_2;
    // 0x8007EED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8007EEDC: jal         0x8008D3F0
    // 0x8007EEE0: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_3;
    // 0x8007EEE0: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    after_3:
    // 0x8007EEE4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8007EEE8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8007EEEC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8007EEF0: jr          $ra
    // 0x8007EEF4: nop

    return;
    // 0x8007EEF4: nop

;}
RECOMP_FUNC void func_80584BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584BAC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584BB0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584BB4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584BB8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584BBC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584BC0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584BC4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584BC8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584BCC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584BD0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584BD4: jr          $ra
    // 0x80584BD8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584BD8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8006F070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F074: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006F078: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8006F07C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8006F080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F084: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8006F088: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8006F08C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8006F090: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006F094: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8006F098: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006F09C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8006F0A0: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8006F0A4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8006F0A8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8006F0AC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8006F0B0: lw          $t2, 0x7FA4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7FA4);
    // 0x8006F0B4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8006F0B8: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8006F0BC: jal         0x8006EABC
    // 0x8006F0C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8006EABC(rdram, ctx);
        goto after_0;
    // 0x8006F0C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006F0C4: jal         0x8006EB18
    // 0x8006F0C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8006EB18(rdram, ctx);
        goto after_1;
    // 0x8006F0C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8006F0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F0D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F0D4: jr          $ra
    // 0x8006F0D8: nop

    return;
    // 0x8006F0D8: nop

;}
RECOMP_FUNC void func_8079103C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079103C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80791040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80791044: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80791048: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079104C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80791050: jal         0x80790CB4
    // 0x80791054: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80790CB4(rdram, ctx);
        goto after_0;
    // 0x80791054: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x80791058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079105C: jal         0x80790CD8
    // 0x80791060: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80790CD8(rdram, ctx);
        goto after_1;
    // 0x80791060: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80791064: bnel        $v0, $zero, L_80791158
    if (ctx->r2 != 0) {
        // 0x80791068: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80791158;
    }
    goto skip_0;
    // 0x80791068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8079106C: jal         0x80790A1C
    // 0x80791070: nop

    func_80790A1C(rdram, ctx);
        goto after_2;
    // 0x80791070: nop

    after_2:
    // 0x80791074: beq         $v0, $zero, L_80791094
    if (ctx->r2 == 0) {
        // 0x80791078: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80791094;
    }
    // 0x80791078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079107C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791080: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80791084: jal         0x8079393C
    // 0x80791088: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8079393C(rdram, ctx);
        goto after_3;
    // 0x80791088: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_3:
    // 0x8079108C: b           L_80791158
    // 0x80791090: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80791158;
    // 0x80791090: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80791094:
    // 0x80791094: jal         0x80790714
    // 0x80791098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790714(rdram, ctx);
        goto after_4;
    // 0x80791098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8079109C: beql        $v0, $zero, L_80791158
    if (ctx->r2 == 0) {
        // 0x807910A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80791158;
    }
    goto skip_1;
    // 0x807910A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x807910A4: jal         0x800653D8
    // 0x807910A8: nop

    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x807910A8: nop

    after_5:
    // 0x807910AC: andi        $t7, $v0, 0x7
    ctx->r15 = ctx->r2 & 0X7;
    // 0x807910B0: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x807910B4: beq         $at, $zero, L_80791154
    if (ctx->r1 == 0) {
        // 0x807910B8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80791154;
    }
    // 0x807910B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807910BC: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AA0) << 16);
    // 0x807910C0: addu        $at, $at, $t7
    gpr jr_addend_807910C8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x807910C4: lw          $t7, 0x7DF0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AA0));
    // 0x807910C8: jr          $t7
    // 0x807910CC: nop

    switch (jr_addend_807910C8 >> 2) {
        case 0: goto L_807910F4; break;
        case 1: goto L_80791110; break;
        case 2: goto L_807910F4; break;
        case 3: goto L_807910D0; break;
        case 4: goto L_807910F4; break;
        case 5: goto L_8079113C; break;
        case 6: goto L_807910D0; break;
        default: switch_error(__func__, 0x807910C8, 0x80797DF0);
    }
    // 0x807910CC: nop

L_807910D0:
    // 0x807910D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807910D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807910D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807910DC: jal         0x8079393C
    // 0x807910E0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8079393C(rdram, ctx);
        goto after_6;
    // 0x807910E0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x807910E4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x807910E8: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x807910EC: b           L_80791154
    // 0x807910F0: sb          $t8, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r24;
        goto L_80791154;
    // 0x807910F0: sb          $t8, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r24;
L_807910F4:
    // 0x807910F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807910F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807910FC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80791100: jal         0x8079393C
    // 0x80791104: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8079393C(rdram, ctx);
        goto after_7;
    // 0x80791104: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x80791108: b           L_80791158
    // 0x8079110C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80791158;
    // 0x8079110C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80791110:
    // 0x80791110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791114: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8079111C: jal         0x8079393C
    // 0x80791120: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8079393C(rdram, ctx);
        goto after_8;
    // 0x80791120: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_8:
    // 0x80791124: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80791128: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
    // 0x8079112C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80791130: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80791134: b           L_80791154
    // 0x80791138: sb          $t1, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r9;
        goto L_80791154;
    // 0x80791138: sb          $t1, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r9;
L_8079113C:
    // 0x8079113C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791144: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80791148: jal         0x8079393C
    // 0x8079114C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8079393C(rdram, ctx);
        goto after_9;
    // 0x8079114C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_9:
    // 0x80791150: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_80791154:
    // 0x80791154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80791158:
    // 0x80791158: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079115C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80791160: jr          $ra
    // 0x80791164: nop

    return;
    // 0x80791164: nop

;}
RECOMP_FUNC void func_8076D188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D188: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8076D18C: beq         $v0, $zero, L_8076D19C
    if (ctx->r2 == 0) {
        // 0x8076D190: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8076D19C;
    }
    // 0x8076D190: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8076D194: b           L_8076D1E0
    // 0x8076D198: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
        goto L_8076D1E0;
    // 0x8076D198: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
L_8076D19C:
    // 0x8076D19C: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x8076D1A0: lui         $t1, 0x8077
    ctx->r9 = S32(RELOC_HI16(766, 0X3508) << 16);
    // 0x8076D1A4: addiu       $t1, $t1, -0x308
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(766, 0X3508));
    // 0x8076D1A8: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x8076D1AC: slti        $at, $v0, 0x37
    ctx->r1 = SIGNED(ctx->r2) < 0X37 ? 1 : 0;
    // 0x8076D1B0: bne         $at, $zero, L_8076D1C8
    if (ctx->r1 != 0) {
        // 0x8076D1B4: sw          $v0, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r2;
            goto L_8076D1C8;
    }
    // 0x8076D1B4: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x8076D1B8: addiu       $t9, $zero, 0x36
    ctx->r25 = ADD32(0, 0X36);
    // 0x8076D1BC: sw          $t9, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r25;
    // 0x8076D1C0: jr          $ra
    // 0x8076D1C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8076D1C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8076D1C8:
    // 0x8076D1C8: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x8076D1CC: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x8076D1D0: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8076D1D4: sw          $t2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r10;
    // 0x8076D1D8: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x8076D1DC: sw          $t3, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r11;
L_8076D1E0:
    // 0x8076D1E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8076D1E4: jr          $ra
    // 0x8076D1E8: nop

    return;
    // 0x8076D1E8: nop

;}
RECOMP_FUNC void func_80437650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437650: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80437654: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80437658: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8043765C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80437660: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80437664: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80437668: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8043766C: jal         0x80065490
    // 0x80437670: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x80437670: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80437674: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x80437678: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8043767C: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80437680: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    // 0x80437684: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x80437688: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x8043768C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80437690: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80437694: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80437698: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8043769C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x804376A0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x804376A4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804376A8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x804376AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x804376B0: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x804376B4: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x804376B8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x804376BC: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x804376C0: bc1f        L_804376D8
    if (!c1cs) {
        // 0x804376C4: nop
    
            goto L_804376D8;
    }
    // 0x804376C4: nop

    // 0x804376C8: jal         0x8043751C
    // 0x804376CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8043751C(rdram, ctx);
        goto after_1;
    // 0x804376CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x804376D0: b           L_8043772C
    // 0x804376D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8043772C;
    // 0x804376D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804376D8:
    // 0x804376D8: jal         0x804373F0
    // 0x804376DC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_804373F0(rdram, ctx);
        goto after_2;
    // 0x804376DC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x804376E0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x804376E4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x804376E8: jal         0x804374A8
    // 0x804376EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_804374A8(rdram, ctx);
        goto after_3;
    // 0x804376EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x804376F0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804376F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804376F8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x804376FC: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80437700: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80437704: bc1f        L_80437720
    if (!c1cs) {
        // 0x80437708: nop
    
            goto L_80437720;
    }
    // 0x80437708: nop

    // 0x8043770C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80437710: jal         0x80437314
    // 0x80437714: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80437314(rdram, ctx);
        goto after_4;
    // 0x80437714: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x80437718: b           L_8043772C
    // 0x8043771C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8043772C;
    // 0x8043771C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80437720:
    // 0x80437720: jal         0x8043751C
    // 0x80437724: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8043751C(rdram, ctx);
        goto after_5;
    // 0x80437724: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80437728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043772C:
    // 0x8043772C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80437730: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80437734: jr          $ra
    // 0x80437738: nop

    return;
    // 0x80437738: nop

;}
RECOMP_FUNC void func_8057C5B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C5B8: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8057C5BC: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8057C5C0: addiu       $t6, $t6, 0x5284
    ctx->r14 = ADD32(ctx->r14, 0X5284);
    // 0x8057C5C4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8057C5C8: jr          $ra
    // 0x8057C5CC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8057C5CC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8006ABF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ABF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006ABF4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006ABF8: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x8006ABFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006AC00: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006AC04: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006AC08: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8006AC0C: sll         $a3, $a0, 16
    ctx->r7 = S32(ctx->r4 << 16);
    // 0x8006AC10: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x8006AC14: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8006AC18: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006AC1C: addiu       $a1, $sp, 0x22
    ctx->r5 = ADD32(ctx->r29, 0X22);
    // 0x8006AC20: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x8006AC24: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8006AC28: lw          $t0, 0x1B0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1B0);
    // 0x8006AC2C: lw          $a0, 0x20($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X20);
    // 0x8006AC30: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x8006AC34: sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
    // 0x8006AC38: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8006AC3C: jal         0x8006AB7C
    // 0x8006AC40: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_8006AB7C(rdram, ctx);
        goto after_0;
    // 0x8006AC40: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006AC44: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006AC48: bne         $v0, $at, L_8006AC58
    if (ctx->r2 != ctx->r1) {
        // 0x8006AC4C: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8006AC58;
    }
    // 0x8006AC4C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8006AC50: b           L_8006AC84
    // 0x8006AC54: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_8006AC84;
    // 0x8006AC54: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8006AC58:
    // 0x8006AC58: lh          $t6, 0x16($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X16);
    // 0x8006AC5C: lh          $t7, 0x20($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X20);
    // 0x8006AC60: lh          $t3, 0x22($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X22);
    // 0x8006AC64: lw          $t2, 0x24($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X24);
    // 0x8006AC68: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006AC6C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8006AC70: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8006AC74: mflo        $t8
    ctx->r24 = lo;
    // 0x8006AC78: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8006AC7C: addu        $t0, $t5, $t9
    ctx->r8 = ADD32(ctx->r13, ctx->r25);
    // 0x8006AC80: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
L_8006AC84:
    // 0x8006AC84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AC88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006AC8C: jr          $ra
    // 0x8006AC90: nop

    return;
    // 0x8006AC90: nop

;}
RECOMP_FUNC void func_8006E718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E71C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E720: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8006E724: jal         0x8006E2B0
    // 0x8006E728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8006E2B0(rdram, ctx);
        goto after_0;
    // 0x8006E728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006E72C: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x8006E730: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x8006E734: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8006E738: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006E73C: lhu         $t7, 0xC($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC);
    // 0x8006E740: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8006E744: bnel        $t8, $at, L_8006E76C
    if (ctx->r24 != ctx->r1) {
        // 0x8006E748: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006E76C;
    }
    goto skip_0;
    // 0x8006E748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8006E74C: lw          $t9, 0x1E0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1E0);
    // 0x8006E750: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x8006E754: addiu       $t0, $t0, -0x19AC
    ctx->r8 = ADD32(ctx->r8, -0X19AC);
    // 0x8006E758: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x8006E75C: beql        $at, $zero, L_8006E76C
    if (ctx->r1 == 0) {
        // 0x8006E760: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006E76C;
    }
    goto skip_1;
    // 0x8006E760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8006E764: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x8006E768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006E76C:
    // 0x8006E76C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E770: jr          $ra
    // 0x8006E774: nop

    return;
    // 0x8006E774: nop

;}
RECOMP_FUNC void func_805193B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805193B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805193B8: beq         $a1, $zero, L_805193E8
    if (ctx->r5 == 0) {
        // 0x805193BC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_805193E8;
    }
    // 0x805193BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805193C0: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x805193C4: lwc1        $f6, 0x84($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X84);
    // 0x805193C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805193CC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805193D0: nop

    // 0x805193D4: bc1fl       L_805193F8
    if (!c1cs) {
        // 0x805193D8: sll         $v1, $v0, 2
        ctx->r3 = S32(ctx->r2 << 2);
            goto L_805193F8;
    }
    goto skip_0;
    // 0x805193D8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    skip_0:
    // 0x805193DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805193E0: b           L_805193F8
    // 0x805193E4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_805193F8;
    // 0x805193E4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_805193E8:
    // 0x805193E8: lw          $v0, 0x138($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X138);
    // 0x805193EC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x805193F0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x805193F4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_805193F8:
    // 0x805193F8: lui         $a2, 0x8052
    ctx->r6 = S32(RELOC_HI16(291, 0X2460) << 16);
    // 0x805193FC: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x80519400: lw          $a2, -0x5F30($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(291, 0X2460));
    // 0x80519404: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80519408: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8051940C: jal         0x80519AFC
    // 0x80519410: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80519AFC(rdram, ctx);
        goto after_0;
    // 0x80519410: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80519414: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80519418: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(291, 0X2458) << 16);
    // 0x8051941C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80519420: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80519424: lwc1        $f8, -0x5F38($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(291, 0X2458));
    // 0x80519428: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8051942C: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(291, 0X25F8) << 16);
    // 0x80519430: swc1        $f8, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f8.u32l;
    // 0x80519434: lwc1        $f10, -0x5D98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(291, 0X25F8));
    // 0x80519438: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x8051943C: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x80519440: swc1        $f10, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f10.u32l;
    // 0x80519444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80519448: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051944C: jr          $ra
    // 0x80519450: nop

    return;
    // 0x80519450: nop

;}
RECOMP_FUNC void eepmgr_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CF50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007CF54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007CF58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007CF5C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007CF60: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8007CF64: addiu       $a1, $zero, 0x228
    ctx->r5 = ADD32(0, 0X228);
    // 0x8007CF68: jal         0x80084820
    // 0x8007CF6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _blkclr(rdram, ctx);
        goto after_0;
    // 0x8007CF6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007CF70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007CF74: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CF78: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x8007CF7C: sw          $t6, 0x218($a0)
    MEM_W(0X218, ctx->r4) = ctx->r14;
    // 0x8007CF80: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8007CF84: sw          $t7, 0x220($a0)
    MEM_W(0X220, ctx->r4) = ctx->r15;
    // 0x8007CF88: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8007CF8C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8007CF90: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8007CF94: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8007CF98: sb          $t8, 0x21C($a0)
    MEM_B(0X21C, ctx->r4) = ctx->r24;
    // 0x8007CF9C: lhu         $t1, -0x65DC($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X65DC);
    // 0x8007CFA0: sh          $t1, 0x21E($a0)
    MEM_H(0X21E, ctx->r4) = ctx->r9;
    // 0x8007CFA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007CFA8: jr          $ra
    // 0x8007CFAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007CFAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80447C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447C64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447C68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80447C6C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80447C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80447C74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80447C78: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80447C7C: bne         $a2, $zero, L_80447CE4
    if (ctx->r6 != 0) {
        // 0x80447C80: lw          $t0, 0x1F4($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X1F4);
            goto L_80447CE4;
    }
    // 0x80447C80: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x80447C84: lui         $v0, 0x8045
    ctx->r2 = S32(RELOC_HI16(98, 0X13240) << 16);
    // 0x80447C88: lw          $v0, 0x7620($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(98, 0X13240));
    // 0x80447C8C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80447C90: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80447C94: beq         $v0, $zero, L_80447CB4
    if (ctx->r2 == 0) {
        // 0x80447C98: nop
    
            goto L_80447CB4;
    }
    // 0x80447C98: nop

    // 0x80447C9C: jalr        $v0
    // 0x80447CA0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80447CA0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80447CA4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80447CA8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80447CAC: b           L_80447CB4
    // 0x80447CB0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80447CB4;
    // 0x80447CB0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80447CB4:
    // 0x80447CB4: bne         $v1, $zero, L_80447CC4
    if (ctx->r3 != 0) {
        // 0x80447CB8: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80447CC4;
    }
    // 0x80447CB8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80447CBC: b           L_80447D28
    // 0x80447CC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80447D28;
    // 0x80447CC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80447CC4:
    // 0x80447CC4: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x80447CC8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80447CCC: bgtz        $t8, L_80447D24
    if (SIGNED(ctx->r24) > 0) {
        // 0x80447CD0: sw          $t8, 0xC($t0)
        MEM_W(0XC, ctx->r8) = ctx->r24;
            goto L_80447D24;
    }
    // 0x80447CD0: sw          $t8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r24;
    // 0x80447CD4: jal         0x804462B4
    // 0x80447CD8: nop

    func_804462B4(rdram, ctx);
        goto after_1;
    // 0x80447CD8: nop

    after_1:
    // 0x80447CDC: b           L_80447D28
    // 0x80447CE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80447D28;
    // 0x80447CE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80447CE4:
    // 0x80447CE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80447CE8: bnel        $a2, $at, L_80447D14
    if (ctx->r6 != ctx->r1) {
        // 0x80447CEC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80447D14;
    }
    goto skip_0;
    // 0x80447CEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80447CF0: jal         0x8044625C
    // 0x80447CF4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_8044625C(rdram, ctx);
        goto after_2;
    // 0x80447CF4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_2:
    // 0x80447CF8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80447CFC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447D00: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80447D04: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80447D08: b           L_80447D24
    // 0x80447D0C: sw          $t1, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r9;
        goto L_80447D24;
    // 0x80447D0C: sw          $t1, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r9;
    // 0x80447D10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80447D14:
    // 0x80447D14: bnel        $a2, $at, L_80447D28
    if (ctx->r6 != ctx->r1) {
        // 0x80447D18: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80447D28;
    }
    goto skip_1;
    // 0x80447D18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80447D1C: jal         0x804462B4
    // 0x80447D20: nop

    func_804462B4(rdram, ctx);
        goto after_3;
    // 0x80447D20: nop

    after_3:
L_80447D24:
    // 0x80447D24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80447D28:
    // 0x80447D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80447D2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447D30: jr          $ra
    // 0x80447D34: nop

    return;
    // 0x80447D34: nop

;}
RECOMP_FUNC void func_805579BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805579BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805579C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805579C4: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x805579C8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x805579CC: lbu         $v0, 0x30($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X30);
    // 0x805579D0: beq         $v0, $at, L_80557A00
    if (ctx->r2 == ctx->r1) {
        // 0x805579D4: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80557A00;
    }
    // 0x805579D4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x805579D8: beql        $v0, $at, L_80557A04
    if (ctx->r2 == ctx->r1) {
        // 0x805579DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80557A04;
    }
    goto skip_0;
    // 0x805579DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805579E0: jal         0x800653D8
    // 0x805579E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x805579E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805579E8: andi        $t7, $v0, 0x1F
    ctx->r15 = ctx->r2 & 0X1F;
    // 0x805579EC: slti        $at, $t7, 0x1F
    ctx->r1 = SIGNED(ctx->r15) < 0X1F ? 1 : 0;
    // 0x805579F0: bne         $at, $zero, L_80557A00
    if (ctx->r1 != 0) {
        // 0x805579F4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80557A00;
    }
    // 0x805579F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805579F8: jal         0x80557AA0
    // 0x805579FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80557AA0(rdram, ctx);
        goto after_1;
    // 0x805579FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
L_80557A00:
    // 0x80557A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80557A04:
    // 0x80557A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80557A08: jr          $ra
    // 0x80557A0C: nop

    return;
    // 0x80557A0C: nop

;}
RECOMP_FUNC void func_8006112C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006112C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80061130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061134: jal         0x80060F6C
    // 0x80061138: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80060F6C(rdram, ctx);
        goto after_0;
    // 0x80061138: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006113C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80061140: lw          $v0, 0x3C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X3C);
    // 0x80061144: addiu       $a0, $v0, 0x48
    ctx->r4 = ADD32(ctx->r2, 0X48);
    // 0x80061148: jal         0x80065490
    // 0x8006114C: addiu       $a1, $v0, 0x90
    ctx->r5 = ADD32(ctx->r2, 0X90);
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x8006114C: addiu       $a1, $v0, 0x90
    ctx->r5 = ADD32(ctx->r2, 0X90);
    after_1:
    // 0x80061150: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80061154: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80061158: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8006115C: sw          $t7, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r15;
    // 0x80061160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80061168: jr          $ra
    // 0x8006116C: nop

    return;
    // 0x8006116C: nop

;}
RECOMP_FUNC void func_804538A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804538A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804538AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804538B0: jal         0x80453784
    // 0x804538B4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80453784(rdram, ctx);
        goto after_0;
    // 0x804538B4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x804538B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804538BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804538C0: jr          $ra
    // 0x804538C4: nop

    return;
    // 0x804538C4: nop

;}
RECOMP_FUNC void func_8070F400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070F400: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8070F404: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x8070F408: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8070F40C: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x8070F410: lw          $t9, 0x1F4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1F4);
    // 0x8070F414: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8070F418: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x8070F41C: lw          $t1, 0x1F4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1F4);
    // 0x8070F420: jr          $ra
    // 0x8070F424: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    return;
    // 0x8070F424: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
;}
RECOMP_FUNC void func_80423B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423B0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80423B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80423B14: jal         0x80423A0C
    // 0x80423B18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80423A0C(rdram, ctx);
        goto after_0;
    // 0x80423B18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80423B1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80423B20: lui         $at, 0xC387
    ctx->r1 = S32(0XC387 << 16);
    // 0x80423B24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80423B28: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80423B2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80423B30: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80423B34: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80423B38: lwc1        $f6, 0xEC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x80423B3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80423B40: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80423B44: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x80423B48: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80423B4C: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80423B50: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80423B54: nop

    // 0x80423B58: bc1fl       L_80423B6C
    if (!c1cs) {
        // 0x80423B5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80423B6C;
    }
    goto skip_0;
    // 0x80423B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80423B60: jal         0x80423DB8
    // 0x80423B64: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    func_80423DB8(rdram, ctx);
        goto after_1;
    // 0x80423B64: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    after_1:
    // 0x80423B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80423B6C:
    // 0x80423B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80423B70: jr          $ra
    // 0x80423B74: nop

    return;
    // 0x80423B74: nop

;}
RECOMP_FUNC void func_80735C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735C84: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80735C88: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80735C8C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80735C90: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80735C94: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80735C98: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80735C9C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80735CA0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80735CA4: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(736, 0X3928) << 16);
    // 0x80735CA8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80735CAC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80735CB0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80735CB4: lw          $t1, -0x6C78($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(736, 0X3928));
    // 0x80735CB8: jr          $ra
    // 0x80735CBC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80735CBC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80427C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427C6C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80427C70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80427C74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80427C78: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80427C7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80427C80: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80427C84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80427C88: jal         0x80065954
    // 0x80427C8C: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80427C8C: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    after_0:
    // 0x80427C90: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80427C94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80427C98: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80427C9C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80427CA0: addiu       $t7, $v1, 0x1C
    ctx->r15 = ADD32(ctx->r3, 0X1C);
    // 0x80427CA4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80427CA8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80427CAC: nop

    // 0x80427CB0: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x80427CB4: bnel        $at, $zero, L_80427CC4
    if (ctx->r1 != 0) {
        // 0x80427CB8: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_80427CC4;
    }
    goto skip_0;
    // 0x80427CB8: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    skip_0:
    // 0x80427CBC: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x80427CC0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_80427CC4:
    // 0x80427CC4: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x80427CC8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80427CCC: bne         $t9, $at, L_80427D08
    if (ctx->r25 != ctx->r1) {
        // 0x80427CD0: nop
    
            goto L_80427D08;
    }
    // 0x80427CD0: nop

    // 0x80427CD4: jal         0x8001D770
    // 0x80427CD8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x80427CD8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_1:
    // 0x80427CDC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80427CE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80427CE4: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80427CE8: jal         0x80067D94
    // 0x80427CEC: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_80067D94(rdram, ctx);
        goto after_2;
    // 0x80427CEC: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80427CF0: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80427CF4: jal         0x80067F78
    // 0x80427CF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_3;
    // 0x80427CF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80427CFC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80427D00: b           L_80427D38
    // 0x80427D04: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
        goto L_80427D38;
    // 0x80427D04: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
L_80427D08:
    // 0x80427D08: jal         0x8001D770
    // 0x80427D0C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_8001D770(rdram, ctx);
        goto after_4;
    // 0x80427D0C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_4:
    // 0x80427D10: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80427D14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80427D18: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80427D1C: jal         0x80067D94
    // 0x80427D20: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_80067D94(rdram, ctx);
        goto after_5;
    // 0x80427D20: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x80427D24: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80427D28: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80427D2C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80427D30: jal         0x800678F0
    // 0x80427D34: lh          $a1, 0x0($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X0);
    func_800678F0(rdram, ctx);
        goto after_6;
    // 0x80427D34: lh          $a1, 0x0($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X0);
    after_6:
L_80427D38:
    // 0x80427D38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80427D3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80427D40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80427D44: jr          $ra
    // 0x80427D48: nop

    return;
    // 0x80427D48: nop

;}
RECOMP_FUNC void func_806E5DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E5DA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E5DAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E5DB0: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x806E5DB4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x806E5DB8: lw          $a2, 0x2C($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X2C);
    // 0x806E5DBC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806E5DC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806E5DC4: jal         0x80049D74
    // 0x806E5DC8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x806E5DC8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x806E5DCC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806E5DD0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806E5DD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806E5DD8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x806E5DDC: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x806E5DE0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x806E5DE4: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x806E5DE8: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x806E5DEC: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x806E5DF0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x806E5DF4: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x806E5DF8: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x806E5DFC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x806E5E00: beql        $v1, $zero, L_806E5E48
    if (ctx->r3 == 0) {
        // 0x806E5E04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E5E48;
    }
    goto skip_0;
    // 0x806E5E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E5E08: beql        $v1, $at, L_806E5E48
    if (ctx->r3 == ctx->r1) {
        // 0x806E5E0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E5E48;
    }
    goto skip_1;
    // 0x806E5E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806E5E10: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x806E5E14: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x806E5E18: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x806E5E1C: beq         $v1, $at, L_806E5E44
    if (ctx->r3 == ctx->r1) {
        // 0x806E5E20: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_806E5E44;
    }
    // 0x806E5E20: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x806E5E24: beq         $v1, $at, L_806E5E44
    if (ctx->r3 == ctx->r1) {
        // 0x806E5E28: sll         $t0, $a2, 2
        ctx->r8 = S32(ctx->r6 << 2);
            goto L_806E5E44;
    }
    // 0x806E5E28: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x806E5E2C: lui         $t9, 0x806E
    ctx->r25 = S32(RELOC_HI16(655, 0XF50) << 16);
    // 0x806E5E30: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x806E5E34: lw          $t9, 0x6C10($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(655, 0XF50));
    // 0x806E5E38: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x806E5E3C: jalr        $t9
    // 0x806E5E40: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x806E5E40: nop

    after_1:
L_806E5E44:
    // 0x806E5E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E5E48:
    // 0x806E5E48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E5E4C: jr          $ra
    // 0x806E5E50: nop

    return;
    // 0x806E5E50: nop

;}
RECOMP_FUNC void func_804327A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804327A0: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(62, 0X2D8) << 16);
    // 0x804327A4: addiu       $v0, $v0, 0x2A78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(62, 0X2D8));
    // 0x804327A8: jr          $ra
    // 0x804327AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804327AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800275A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800275A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800275A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800275A8: jal         0x80024668
    // 0x800275AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024668(rdram, ctx);
        goto after_0;
    // 0x800275AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800275B0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800275B4: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x800275B8: addiu       $t6, $t6, 0x756C
    ctx->r14 = ADD32(ctx->r14, 0X756C);
    // 0x800275BC: sw          $t6, 0x160($t7)
    MEM_W(0X160, ctx->r15) = ctx->r14;
    // 0x800275C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800275C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800275C8: jr          $ra
    // 0x800275CC: nop

    return;
    // 0x800275CC: nop

;}
RECOMP_FUNC void func_804360A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804360A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804360A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804360A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x804360AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x804360B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804360B4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804360B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804360BC: addiu       $s0, $zero, 0x3B
    ctx->r16 = ADD32(0, 0X3B);
    // 0x804360C0: addiu       $v0, $v1, 0x106C
    ctx->r2 = ADD32(ctx->r3, 0X106C);
L_804360C4:
    // 0x804360C4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x804360C8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x804360CC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x804360D0: bgez        $s0, L_804360C4
    if (SIGNED(ctx->r16) >= 0) {
        // 0x804360D4: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_804360C4;
    }
    // 0x804360D4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x804360D8: sw          $zero, 0x134C($v1)
    MEM_W(0X134C, ctx->r3) = 0;
    // 0x804360DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x804360E0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_804360E4:
    // 0x804360E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x804360E8: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x804360EC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x804360F0: bne         $at, $zero, L_804360E4
    if (ctx->r1 != 0) {
        // 0x804360F4: sw          $zero, 0x1248($s1)
        MEM_W(0X1248, ctx->r17) = 0;
            goto L_804360E4;
    }
    // 0x804360F4: sw          $zero, 0x1248($s1)
    MEM_W(0X1248, ctx->r17) = 0;
    // 0x804360F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x804360FC: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80436100: addiu       $s2, $zero, 0x3C
    ctx->r18 = ADD32(0, 0X3C);
L_80436104:
    // 0x80436104: jal         0x800653D8
    // 0x80436108: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80436108: nop

    after_0:
    // 0x8043610C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80436110: bgez        $v0, L_80436124
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80436114: andi        $t6, $v0, 0x3
        ctx->r14 = ctx->r2 & 0X3;
            goto L_80436124;
    }
    // 0x80436114: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x80436118: beq         $t6, $zero, L_80436124
    if (ctx->r14 == 0) {
        // 0x8043611C: nop
    
            goto L_80436124;
    }
    // 0x8043611C: nop

    // 0x80436120: addiu       $t6, $t6, -0x4
    ctx->r14 = ADD32(ctx->r14, -0X4);
L_80436124:
    // 0x80436124: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80436128: bne         $s0, $s2, L_80436104
    if (ctx->r16 != ctx->r18) {
        // 0x8043612C: sw          $t6, 0x1258($s1)
        MEM_W(0X1258, ctx->r17) = ctx->r14;
            goto L_80436104;
    }
    // 0x8043612C: sw          $t6, 0x1258($s1)
    MEM_W(0X1258, ctx->r17) = ctx->r14;
    // 0x80436130: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80436134: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80436138: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8043613C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80436140: jr          $ra
    // 0x80436144: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80436144: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005ACB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005ACB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005ACB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005ACBC: jal         0x800648A4
    // 0x8005ACC0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800648A4(rdram, ctx);
        goto after_0;
    // 0x8005ACC0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8005ACC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005ACC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005ACCC: jr          $ra
    // 0x8005ACD0: nop

    return;
    // 0x8005ACD0: nop

;}
RECOMP_FUNC void func_806B219C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B219C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B21A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806B21A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806B21A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806B21AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806B21B0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806B21B4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806B21B8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B21BC: addiu       $t6, $zero, 0xDD4
    ctx->r14 = ADD32(0, 0XDD4);
    // 0x806B21C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806B21C4: addiu       $a2, $zero, 0xA8C
    ctx->r6 = ADD32(0, 0XA8C);
    // 0x806B21C8: addiu       $a3, $zero, 0xCA8
    ctx->r7 = ADD32(0, 0XCA8);
    // 0x806B21CC: addiu       $a1, $zero, 0x99C
    ctx->r5 = ADD32(0, 0X99C);
    // 0x806B21D0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x806B21D4: jal         0x806B195C
    // 0x806B21D8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_806B195C(rdram, ctx);
        goto after_0;
    // 0x806B21D8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x806B21DC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806B21E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B21E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B21E8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B21EC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x806B21F0: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x806B21F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806B21F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B21FC: jr          $ra
    // 0x806B2200: nop

    return;
    // 0x806B2200: nop

;}
RECOMP_FUNC void func_8057C6B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C6B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057C6B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8057C6B8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8057C6BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057C6C0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8057C6C4: lui         $t7, 0x8058
    ctx->r15 = S32(RELOC_HI16(387, 0XF90) << 16);
    // 0x8057C6C8: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x8057C6CC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8057C6D0: lw          $t7, -0x3560($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(387, 0XF90));
    // 0x8057C6D4: jal         0x8057BD1C
    // 0x8057C6D8: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    func_8057BD1C(rdram, ctx);
        goto after_0;
    // 0x8057C6D8: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    after_0:
    // 0x8057C6DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057C6E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057C6E4: jr          $ra
    // 0x8057C6E8: nop

    return;
    // 0x8057C6E8: nop

;}
RECOMP_FUNC void func_8006B554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B554: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006B558: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x8006B55C: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8006B560: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8006B564: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006B568: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006B56C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8006B570: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x8006B574: lh          $s0, 0x1E($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X1E);
    // 0x8006B578: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8006B57C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006B580: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8006B584: mflo        $t7
    ctx->r15 = lo;
    // 0x8006B588: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8006B58C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8006B590: bne         $at, $zero, L_8006B5DC
    if (ctx->r1 != 0) {
        // 0x8006B594: addu        $a1, $a1, $t9
        ctx->r5 = ADD32(ctx->r5, ctx->r25);
            goto L_8006B5DC;
    }
    // 0x8006B594: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
L_8006B598:
    // 0x8006B598: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x8006B59C: addiu       $s0, $s0, -0x5
    ctx->r16 = ADD32(ctx->r16, -0X5);
    // 0x8006B5A0: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8006B5A4: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x8006B5A8: lhu         $t1, 0x2($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X2);
    // 0x8006B5AC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8006B5B0: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8006B5B4: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
    // 0x8006B5B8: lhu         $t2, 0x4($a1)
    ctx->r10 = MEM_HU(ctx->r5, 0X4);
    // 0x8006B5BC: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x8006B5C0: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x8006B5C4: sh          $t2, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r10;
    // 0x8006B5C8: lhu         $t3, -0x4($a1)
    ctx->r11 = MEM_HU(ctx->r5, -0X4);
    // 0x8006B5CC: sh          $t3, -0x4($a0)
    MEM_H(-0X4, ctx->r4) = ctx->r11;
    // 0x8006B5D0: lhu         $t4, -0x2($a1)
    ctx->r12 = MEM_HU(ctx->r5, -0X2);
    // 0x8006B5D4: beq         $at, $zero, L_8006B598
    if (ctx->r1 == 0) {
        // 0x8006B5D8: sh          $t4, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r12;
            goto L_8006B598;
    }
    // 0x8006B5D8: sh          $t4, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r12;
L_8006B5DC:
    // 0x8006B5DC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8006B5E0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006B5E4: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8006B5E8: beq         $v0, $zero, L_8006B614
    if (ctx->r2 == 0) {
        // 0x8006B5EC: sra         $s0, $s0, 16
        ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
            goto L_8006B614;
    }
    // 0x8006B5EC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_8006B5F0:
    // 0x8006B5F0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8006B5F4: lhu         $t5, 0x0($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X0);
    // 0x8006B5F8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006B5FC: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8006B600: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8006B604: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8006B608: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8006B60C: bne         $v0, $zero, L_8006B5F0
    if (ctx->r2 != 0) {
        // 0x8006B610: sh          $t5, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r13;
            goto L_8006B5F0;
    }
    // 0x8006B610: sh          $t5, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r13;
L_8006B614:
    // 0x8006B614: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8006B618: jr          $ra
    // 0x8006B61C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006B61C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void tmemLoad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083038: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8008303C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80083040: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80083044: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80083048: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8008304C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80083050: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80083054: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80083058: lh          $t0, -0xEF4($t0)
    ctx->r8 = MEM_H(ctx->r8, -0XEF4);
    // 0x8008305C: lh          $t1, 0x0($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X0);
    // 0x80083060: lh          $t9, 0x72($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X72);
    // 0x80083064: sll         $s3, $a3, 16
    ctx->r19 = S32(ctx->r7 << 16);
    // 0x80083068: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8008306C: subu        $s0, $t1, $t0
    ctx->r16 = SUB32(ctx->r9, ctx->r8);
    // 0x80083070: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x80083074: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x80083078: addu        $t5, $t6, $t9
    ctx->r13 = ADD32(ctx->r14, ctx->r25);
    // 0x8008307C: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80083080: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80083084: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80083088: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8008308C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80083090: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80083094: bne         $at, $zero, L_800830DC
    if (ctx->r1 != 0) {
        // 0x80083098: sw          $t7, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r15;
            goto L_800830DC;
    }
    // 0x80083098: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8008309C: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800830A0: lh          $a3, -0xEF8($a3)
    ctx->r7 = MEM_H(ctx->r7, -0XEF8);
    // 0x800830A4: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x800830A8: jal         0x80082F38
    // 0x800830AC: lh          $a2, 0x32($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X32);
    tmemLoad_B(rdram, ctx);
        goto after_0;
    // 0x800830AC: lh          $a2, 0x32($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X32);
    after_0:
    // 0x800830B0: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800830B4: lhu         $t9, -0xEF6($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0XEF6);
    // 0x800830B8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800830BC: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800830C0: mflo        $t5
    ctx->r13 = lo;
    // 0x800830C4: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x800830C8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800830CC: lh          $t7, 0x0($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X0);
    // 0x800830D0: subu        $t9, $t7, $s3
    ctx->r25 = SUB32(ctx->r15, ctx->r19);
    // 0x800830D4: b           L_80083378
    // 0x800830D8: sh          $t9, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r25;
        goto L_80083378;
    // 0x800830D8: sh          $t9, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r25;
L_800830DC:
    // 0x800830DC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800830E0: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x800830E4: sra         $t8, $v0, 16
    ctx->r24 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800830E8: subu        $v1, $t5, $t8
    ctx->r3 = SUB32(ctx->r13, ctx->r24);
    // 0x800830EC: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800830F0: lw          $a3, -0xEF0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0XEF0);
    // 0x800830F4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800830F8: sll         $a2, $v1, 16
    ctx->r6 = S32(ctx->r3 << 16);
    // 0x800830FC: subu        $t7, $s3, $t8
    ctx->r15 = SUB32(ctx->r19, ctx->r24);
    // 0x80083100: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x80083104: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80083108: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8008310C: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80083110: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80083114: sh          $t7, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r15;
    // 0x80083118: blez        $t8, L_800831A0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8008311C: and         $t2, $a3, $at
        ctx->r10 = ctx->r7 & ctx->r1;
            goto L_800831A0;
    }
    // 0x8008311C: and         $t2, $a3, $at
    ctx->r10 = ctx->r7 & ctx->r1;
    // 0x80083120: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x80083124: lhu         $t5, -0xEF2($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0XEF2);
    // 0x80083128: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8008312C: beq         $t6, $zero, L_80083168
    if (ctx->r14 == 0) {
        // 0x80083130: addu        $a1, $t5, $a3
        ctx->r5 = ADD32(ctx->r13, ctx->r7);
            goto L_80083168;
    }
    // 0x80083130: addu        $a1, $t5, $a3
    ctx->r5 = ADD32(ctx->r13, ctx->r7);
    // 0x80083134: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80083138: lhu         $t7, -0xEF6($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0XEF6);
    // 0x8008313C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80083140: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80083144: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80083148: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008314C: subu        $a1, $a1, $t7
    ctx->r5 = SUB32(ctx->r5, ctx->r15);
    // 0x80083150: and         $t9, $a1, $at
    ctx->r25 = ctx->r5 & ctx->r1;
    // 0x80083154: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80083158: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8008315C: or          $a1, $t9, $t2
    ctx->r5 = ctx->r25 | ctx->r10;
    // 0x80083160: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80083164: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
L_80083168:
    // 0x80083168: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8008316C: lhu         $v1, -0xEF8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0XEF8);
    // 0x80083170: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80083174: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x80083178: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008317C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80083180: mflo        $a3
    ctx->r7 = lo;
    // 0x80083184: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x80083188: jal         0x80082FC4
    // 0x8008318C: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    tmemLoad_A(rdram, ctx);
        goto after_1;
    // 0x8008318C: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    after_1:
    // 0x80083190: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80083194: lh          $t0, -0xEF4($t0)
    ctx->r8 = MEM_H(ctx->r8, -0XEF4);
    // 0x80083198: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8008319C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
L_800831A0:
    // 0x800831A0: beq         $t0, $zero, L_800832A4
    if (ctx->r8 == 0) {
        // 0x800831A4: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800832A4;
    }
    // 0x800831A4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800831A8: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800831AC: lhu         $t0, -0xEF6($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0XEF6);
    // 0x800831B0: andi        $v0, $s0, 0x1
    ctx->r2 = ctx->r16 & 0X1;
    // 0x800831B4: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x800831B8: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800831BC: sra         $t8, $t3, 16
    ctx->r24 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800831C0: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800831C4: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x800831C8: or          $t3, $t8, $zero
    ctx->r11 = ctx->r24 | 0;
    // 0x800831CC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800831D0: sra         $t7, $t1, 16
    ctx->r15 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800831D4: addiu       $a2, $t3, 0x1
    ctx->r6 = ADD32(ctx->r11, 0X1);
    // 0x800831D8: lw          $a1, -0xEF0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XEF0);
    // 0x800831DC: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x800831E0: mflo        $t6
    ctx->r14 = lo;
    // 0x800831E4: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x800831E8: beq         $t8, $zero, L_80083214
    if (ctx->r24 == 0) {
        // 0x800831EC: addu        $t4, $t5, $t6
        ctx->r12 = ADD32(ctx->r13, ctx->r14);
            goto L_80083214;
    }
    // 0x800831EC: addu        $t4, $t5, $t6
    ctx->r12 = ADD32(ctx->r13, ctx->r14);
    // 0x800831F0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800831F4: subu        $a1, $a1, $t0
    ctx->r5 = SUB32(ctx->r5, ctx->r8);
    // 0x800831F8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800831FC: addiu       $t1, $s0, -0x1
    ctx->r9 = ADD32(ctx->r16, -0X1);
    // 0x80083200: and         $t5, $a1, $at
    ctx->r13 = ctx->r5 & ctx->r1;
    // 0x80083204: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x80083208: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x8008320C: or          $a1, $t5, $t2
    ctx->r5 = ctx->r13 | ctx->r10;
    // 0x80083210: sra         $t1, $t6, 16
    ctx->r9 = S32(SIGNED(ctx->r14) >> 16);
L_80083214:
    // 0x80083214: lhu         $v1, -0xEF8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0XEF8);
    // 0x80083218: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x8008321C: lhu         $t5, -0xEF2($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0XEF2);
    // 0x80083220: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80083224: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80083228: subu        $v0, $t0, $t5
    ctx->r2 = SUB32(ctx->r8, ctx->r13);
    // 0x8008322C: sra         $t7, $v0, 3
    ctx->r15 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80083230: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80083234: subu        $t2, $v1, $v0
    ctx->r10 = SUB32(ctx->r3, ctx->r2);
    // 0x80083238: sll         $t8, $t2, 16
    ctx->r24 = S32(ctx->r10 << 16);
    // 0x8008323C: sra         $t5, $t8, 16
    ctx->r13 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80083240: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80083244: sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
    // 0x80083248: mflo        $t6
    ctx->r14 = lo;
    // 0x8008324C: addu        $a3, $t6, $v0
    ctx->r7 = ADD32(ctx->r14, ctx->r2);
    // 0x80083250: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80083254: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80083258: sh          $a2, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r6;
    // 0x8008325C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80083260: sh          $t1, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r9;
    // 0x80083264: jal         0x80082FC4
    // 0x80083268: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    tmemLoad_A(rdram, ctx);
        goto after_2;
    // 0x80083268: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    after_2:
    // 0x8008326C: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80083270: lh          $t1, 0x42($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X42);
    // 0x80083274: lhu         $t8, -0xEF8($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0XEF8);
    // 0x80083278: lh          $v0, 0x3E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X3E);
    // 0x8008327C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80083280: multu       $t1, $t8
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80083284: lh          $a2, 0x40($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X40);
    // 0x80083288: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8008328C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80083290: mflo        $a3
    ctx->r7 = lo;
    // 0x80083294: sll         $t5, $a3, 16
    ctx->r13 = S32(ctx->r7 << 16);
    // 0x80083298: jal         0x80082FC4
    // 0x8008329C: sra         $a3, $t5, 16
    ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
    tmemLoad_A(rdram, ctx);
        goto after_3;
    // 0x8008329C: sra         $a3, $t5, 16
    ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
    after_3:
    // 0x800832A0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
L_800832A4:
    // 0x800832A4: blez        $s0, L_800832D8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800832A8: lui         $t8, 0x8011
        ctx->r24 = S32(0X8011 << 16);
            goto L_800832D8;
    }
    // 0x800832A8: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800832AC: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800832B0: lhu         $t9, -0xEF8($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0XEF8);
    // 0x800832B4: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x800832B8: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800832BC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800832C0: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800832C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800832C8: jal         0x80082FC4
    // 0x800832CC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    tmemLoad_A(rdram, ctx);
        goto after_4;
    // 0x800832CC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_4:
    // 0x800832D0: b           L_80083300
    // 0x800832D4: lh          $t5, 0x0($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X0);
        goto L_80083300;
    // 0x800832D4: lh          $t5, 0x0($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X0);
L_800832D8:
    // 0x800832D8: lw          $t8, -0xEFC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XEFC);
    // 0x800832DC: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800832E0: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x800832E4: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x800832E8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800832EC: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800832F0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800832F4: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x800832F8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800832FC: lh          $t5, 0x0($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X0);
L_80083300:
    // 0x80083300: subu        $t6, $t5, $s3
    ctx->r14 = SUB32(ctx->r13, ctx->r19);
    // 0x80083304: sh          $t6, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r14;
    // 0x80083308: lh          $t7, 0x0($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X0);
    // 0x8008330C: lh          $t8, 0x58($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X58);
    // 0x80083310: blez        $t7, L_80083338
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80083314: nop
    
            goto L_80083338;
    }
    // 0x80083314: nop

    // 0x80083318: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8008331C: lhu         $t8, -0xEF6($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0XEF6);
    // 0x80083320: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80083324: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80083328: mflo        $t5
    ctx->r13 = lo;
    // 0x8008332C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80083330: b           L_80083378
    // 0x80083334: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
        goto L_80083378;
    // 0x80083334: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_80083338:
    // 0x80083338: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8008333C: lh          $t7, -0xEEC($t7)
    ctx->r15 = MEM_H(ctx->r15, -0XEEC);
    // 0x80083340: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80083344: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80083348: sh          $t9, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r25;
    // 0x8008334C: lhu         $t6, -0xEF6($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0XEF6);
    // 0x80083350: lh          $t5, 0x58($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X58);
    // 0x80083354: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80083358: lw          $t8, -0xEF0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XEF0);
    // 0x8008335C: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80083360: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x80083364: lhu         $t5, -0xEF2($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0XEF2);
    // 0x80083368: mflo        $t7
    ctx->r15 = lo;
    // 0x8008336C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80083370: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80083374: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_80083378:
    // 0x80083378: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008337C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80083380: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80083384: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80083388: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8008338C: jr          $ra
    // 0x80083390: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80083390: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_805ABD0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ABD0C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805ABD10: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x805ABD14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805ABD18: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x805ABD1C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x805ABD20: lwc1        $f0, 0x6C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x805ABD24: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x805ABD28: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x805ABD2C: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x805ABD30: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x805ABD34: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x805ABD38: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x805ABD3C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x805ABD40: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x805ABD44: lbu         $a2, 0x37($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X37);
    // 0x805ABD48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805ABD4C: addiu       $t0, $t0, 0xD
    ctx->r8 = ADD32(ctx->r8, 0XD);
    // 0x805ABD50: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805ABD54: lbu         $a3, 0x3($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X3);
    // 0x805ABD58: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x805ABD5C: nop

    // 0x805ABD60: bc1fl       L_805ABD94
    if (!c1cs) {
        // 0x805ABD64: swc1        $f0, 0x6C($v0)
        MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
            goto L_805ABD94;
    }
    goto skip_0;
    // 0x805ABD64: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    skip_0:
    // 0x805ABD68: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x805ABD6C: sh          $a3, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r7;
    // 0x805ABD70: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x805ABD74: jal         0x805AC088
    // 0x805ABD78: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    func_805AC088(rdram, ctx);
        goto after_0;
    // 0x805ABD78: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x805ABD7C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x805ABD80: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    // 0x805ABD84: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x805ABD88: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x805ABD8C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x805ABD90: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
L_805ABD94:
    // 0x805ABD94: lh          $t7, 0x4A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4A);
    // 0x805ABD98: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x805ABD9C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x805ABDA0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x805ABDA4: bgez        $a3, L_805ABDB4
    if (SIGNED(ctx->r7) >= 0) {
        // 0x805ABDA8: slti        $at, $a3, 0x100
        ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
            goto L_805ABDB4;
    }
    // 0x805ABDA8: slti        $at, $a3, 0x100
    ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
    // 0x805ABDAC: b           L_805ABDC0
    // 0x805ABDB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_805ABDC0;
    // 0x805ABDB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_805ABDB4:
    // 0x805ABDB4: bnel        $at, $zero, L_805ABDC4
    if (ctx->r1 != 0) {
        // 0x805ABDB8: sb          $a3, 0x3($t0)
        MEM_B(0X3, ctx->r8) = ctx->r7;
            goto L_805ABDC4;
    }
    goto skip_1;
    // 0x805ABDB8: sb          $a3, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r7;
    skip_1:
    // 0x805ABDBC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_805ABDC0:
    // 0x805ABDC0: sb          $a3, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r7;
L_805ABDC4:
    // 0x805ABDC4: sb          $a3, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r7;
    // 0x805ABDC8: sb          $a3, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r7;
    // 0x805ABDCC: sb          $a3, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r7;
    // 0x805ABDD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805ABDD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805ABDD8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x805ABDDC: jr          $ra
    // 0x805ABDE0: nop

    return;
    // 0x805ABDE0: nop

;}
RECOMP_FUNC void func_80789598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80789598: lui         $v1, 0x8079
    ctx->r3 = S32(RELOC_HI16(787, 0X3264) << 16);
    // 0x8078959C: addiu       $v1, $v1, -0x635C
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(787, 0X3264));
    // 0x807895A0: addiu       $t6, $zero, 0x118
    ctx->r14 = ADD32(0, 0X118);
    // 0x807895A4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x807895A8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x807895AC: lbu         $v0, -0x7203($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7203);
    // 0x807895B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807895B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807895B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807895BC: beq         $v0, $zero, L_807895E8
    if (ctx->r2 == 0) {
        // 0x807895C0: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_807895E8;
    }
    // 0x807895C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807895C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807895C8: beq         $v0, $at, L_807895E8
    if (ctx->r2 == ctx->r1) {
        // 0x807895CC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_807895E8;
    }
    // 0x807895CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807895D0: beq         $v0, $at, L_807895E4
    if (ctx->r2 == ctx->r1) {
        // 0x807895D4: addiu       $t7, $zero, 0x8C
        ctx->r15 = ADD32(0, 0X8C);
            goto L_807895E4;
    }
    // 0x807895D4: addiu       $t7, $zero, 0x8C
    ctx->r15 = ADD32(0, 0X8C);
    // 0x807895D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x807895DC: bnel        $v0, $at, L_807895EC
    if (ctx->r2 != ctx->r1) {
        // 0x807895E0: lw          $t9, 0x16C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X16C);
            goto L_807895EC;
    }
    goto skip_0;
    // 0x807895E0: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    skip_0:
L_807895E4:
    // 0x807895E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_807895E8:
    // 0x807895E8: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
L_807895EC:
    // 0x807895EC: lui         $t8, 0x8079
    ctx->r24 = S32(RELOC_HI16(787, 0X2E24) << 16);
    // 0x807895F0: addiu       $t8, $t8, -0x679C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(787, 0X2E24));
    // 0x807895F4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x807895F8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x807895FC: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80789600: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80789604: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80789608: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x8078960C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80789610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80789614: jal         0x8078980C
    // 0x80789618: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8078980C(rdram, ctx);
        goto after_0;
    // 0x80789618: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8078961C: lw          $t3, 0x16C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X16C);
    // 0x80789620: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80789624: lui         $t2, 0x8078
    ctx->r10 = S32(RELOC_HI16(787, 0X5C4) << 16);
    // 0x80789628: sb          $t1, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r9;
    // 0x8078962C: addiu       $t2, $t2, 0x7004
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(787, 0X5C4));
    // 0x80789630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80789634: jal         0x80789580
    // 0x80789638: sw          $t2, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->r10;
    func_80789580(rdram, ctx);
        goto after_1;
    // 0x80789638: sw          $t2, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->r10;
    after_1:
    // 0x8078963C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80789640: jal         0x80045A34
    // 0x80789644: addiu       $a1, $zero, 0x52F8
    ctx->r5 = ADD32(0, 0X52F8);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x80789644: addiu       $a1, $zero, 0x52F8
    ctx->r5 = ADD32(0, 0X52F8);
    after_2:
    // 0x80789648: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8078964C: jal         0x8078941C
    // 0x80789650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8078941C(rdram, ctx);
        goto after_3;
    // 0x80789650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80789654: lw          $t4, 0x16C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X16C);
    // 0x80789658: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x8078965C: addiu       $at, $zero, 0x4671
    ctx->r1 = ADD32(0, 0X4671);
    // 0x80789660: addiu       $t5, $t4, 0xD
    ctx->r13 = ADD32(ctx->r12, 0XD);
    // 0x80789664: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80789668: lhu         $t6, 0xC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XC);
    // 0x8078966C: lui         $t7, 0x8079
    ctx->r15 = S32(RELOC_HI16(787, 0X2E68) << 16);
    // 0x80789670: addiu       $t7, $t7, -0x6758
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(787, 0X2E68));
    // 0x80789674: bne         $t6, $at, L_807897A0
    if (ctx->r14 != ctx->r1) {
        // 0x80789678: lui         $t8, 0x8079
        ctx->r24 = S32(RELOC_HI16(787, 0X2E50) << 16);
            goto L_807897A0;
    }
    // 0x80789678: lui         $t8, 0x8079
    ctx->r24 = S32(RELOC_HI16(787, 0X2E50) << 16);
    // 0x8078967C: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80789680: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80789684: lui         $t9, 0x8079
    ctx->r25 = S32(RELOC_HI16(787, 0X2E7C) << 16);
    // 0x80789688: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8078968C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x80789690: addiu       $t8, $t8, -0x6770
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(787, 0X2E50));
    // 0x80789694: addiu       $t9, $t9, -0x6744
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(787, 0X2E7C));
    // 0x80789698: sw          $t7, 0x52E8($a0)
    MEM_W(0X52E8, ctx->r4) = ctx->r15;
    // 0x8078969C: sw          $t8, 0x52E4($a0)
    MEM_W(0X52E4, ctx->r4) = ctx->r24;
    // 0x807896A0: sw          $t9, 0x52EC($a0)
    MEM_W(0X52EC, ctx->r4) = ctx->r25;
    // 0x807896A4: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x807896A8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x807896AC: lw          $v1, -0x7290($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7290);
    // 0x807896B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807896B4: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
L_807896B8:
    // 0x807896B8: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x807896BC: lw          $t2, 0x38($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X38);
    // 0x807896C0: bnel        $t2, $zero, L_807896D4
    if (ctx->r10 != 0) {
        // 0x807896C4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_807896D4;
    }
    goto skip_1;
    // 0x807896C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x807896C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807896CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x807896D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_807896D4:
    // 0x807896D4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x807896D8: bnel        $at, $zero, L_807896B8
    if (ctx->r1 != 0) {
        // 0x807896DC: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_807896B8;
    }
    goto skip_2;
    // 0x807896DC: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    skip_2:
    // 0x807896E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x807896E4: bnel        $a1, $at, L_80789700
    if (ctx->r5 != ctx->r1) {
        // 0x807896E8: sw          $a0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r4;
            goto L_80789700;
    }
    goto skip_3;
    // 0x807896E8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    skip_3:
    // 0x807896EC: jal         0x800447C8
    // 0x807896F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x807896F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807896F4: b           L_807897AC
    // 0x807896F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807897AC;
    // 0x807896F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807896FC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
L_80789700:
    // 0x80789700: jal         0x800653D8
    // 0x80789704: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x80789704: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_5:
    // 0x80789708: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x8078970C: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x80789710: mfhi        $t3
    ctx->r11 = hi;
    // 0x80789714: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80789718: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8078971C: bne         $v1, $zero, L_80789728
    if (ctx->r3 != 0) {
        // 0x80789720: nop
    
            goto L_80789728;
    }
    // 0x80789720: nop

    // 0x80789724: break       7
    do_break(2155386660);
L_80789728:
    // 0x80789728: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8078972C: bne         $v1, $at, L_80789740
    if (ctx->r3 != ctx->r1) {
        // 0x80789730: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80789740;
    }
    // 0x80789730: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80789734: bne         $v0, $at, L_80789740
    if (ctx->r2 != ctx->r1) {
        // 0x80789738: nop
    
            goto L_80789740;
    }
    // 0x80789738: nop

    // 0x8078973C: break       6
    do_break(2155386684);
L_80789740:
    // 0x80789740: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80789744: addiu       $t6, $zero, -0x8C
    ctx->r14 = ADD32(0, -0X8C);
    // 0x80789748: sh          $a1, 0x52C6($a0)
    MEM_H(0X52C6, ctx->r4) = ctx->r5;
    // 0x8078974C: mflo        $t4
    ctx->r12 = lo;
    // 0x80789750: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80789754: beq         $a1, $zero, L_80789768
    if (ctx->r5 == 0) {
        // 0x80789758: sw          $t5, 0x52E0($a0)
        MEM_W(0X52E0, ctx->r4) = ctx->r13;
            goto L_80789768;
    }
    // 0x80789758: sw          $t5, 0x52E0($a0)
    MEM_W(0X52E0, ctx->r4) = ctx->r13;
    // 0x8078975C: sh          $t6, 0x52C2($a0)
    MEM_H(0X52C2, ctx->r4) = ctx->r14;
    // 0x80789760: b           L_80789774
    // 0x80789764: sh          $zero, 0x52C4($a0)
    MEM_H(0X52C4, ctx->r4) = 0;
        goto L_80789774;
    // 0x80789764: sh          $zero, 0x52C4($a0)
    MEM_H(0X52C4, ctx->r4) = 0;
L_80789768:
    // 0x80789768: sh          $zero, 0x52C4($a0)
    MEM_H(0X52C4, ctx->r4) = 0;
    // 0x8078976C: lh          $t7, 0x52C4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X52C4);
    // 0x80789770: sh          $t7, 0x52C2($a0)
    MEM_H(0X52C2, ctx->r4) = ctx->r15;
L_80789774:
    // 0x80789774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80789778: jal         0x8078749C
    // 0x8078977C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8078749C(rdram, ctx);
        goto after_6;
    // 0x8078977C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_6:
    // 0x80789780: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80789784: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80789788: lw          $t8, -0x7290($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7290);
    // 0x8078978C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80789790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80789794: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80789798: jal         0x807870C0
    // 0x8078979C: sw          $s0, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r16;
    func_807870C0(rdram, ctx);
        goto after_7;
    // 0x8078979C: sw          $s0, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r16;
    after_7:
L_807897A0:
    // 0x807897A0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x807897A4: sb          $zero, 0x3($t1)
    MEM_B(0X3, ctx->r9) = 0;
    // 0x807897A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807897AC:
    // 0x807897AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807897B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807897B4: jr          $ra
    // 0x807897B8: nop

    return;
    // 0x807897B8: nop

;}
RECOMP_FUNC void func_8004CC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CC28: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8004CC2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004CC30: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8004CC34: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8004CC38: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8004CC3C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8004CC40: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x8004CC44: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x8004CC48: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8004CC4C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8004CC50: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8004CC54: addiu       $t1, $sp, 0x46
    ctx->r9 = ADD32(ctx->r29, 0X46);
    // 0x8004CC58: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8004CC5C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004CC60: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8004CC64: addu        $t0, $t9, $t3
    ctx->r8 = ADD32(ctx->r25, ctx->r11);
    // 0x8004CC68: lhu         $t4, 0x0($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X0);
    // 0x8004CC6C: sh          $t4, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r12;
    // 0x8004CC70: lbu         $t8, 0x1($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X1);
    // 0x8004CC74: lbu         $t5, 0x0($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X0);
    // 0x8004CC78: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x8004CC7C: xori        $t3, $t9, 0x3
    ctx->r11 = ctx->r25 ^ 0X3;
    // 0x8004CC80: sltu        $t3, $zero, $t3
    ctx->r11 = 0 < ctx->r11 ? 1 : 0;
    // 0x8004CC84: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8004CC88: and         $t4, $t6, $t3
    ctx->r12 = ctx->r14 & ctx->r11;
    // 0x8004CC8C: beql        $t4, $zero, L_8004CE54
    if (ctx->r12 == 0) {
        // 0x8004CC90: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004CE54;
    }
    goto skip_0;
    // 0x8004CC90: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8004CC94: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    // 0x8004CC98: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x8004CC9C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8004CCA0: jal         0x80049864
    // 0x8004CCA4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    func_80049864(rdram, ctx);
        goto after_0;
    // 0x8004CCA4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004CCA8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8004CCAC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8004CCB0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8004CCB4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8004CCB8: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x8004CCBC: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8004CCC0: lw          $t6, 0x34($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X34);
    // 0x8004CCC4: addiu       $t1, $sp, 0x46
    ctx->r9 = ADD32(ctx->r29, 0X46);
    // 0x8004CCC8: lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1);
    // 0x8004CCCC: addu        $t4, $t6, $t3
    ctx->r12 = ADD32(ctx->r14, ctx->r11);
    // 0x8004CCD0: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8004CCD4: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x8004CCD8: srl         $t8, $v0, 6
    ctx->r24 = S32(U32(ctx->r2) >> 6);
    // 0x8004CCDC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004CCE0: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8004CCE4: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x8004CCE8: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004CCEC: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8004CCF0: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8004CCF4: trunc.w.s   $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8004CCF8: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x8004CCFC: lw          $t7, 0xA24($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XA24);
    // 0x8004CD00: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8004CD04: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x8004CD08: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x8004CD0C: andi        $t9, $t6, 0xF
    ctx->r25 = ctx->r14 & 0XF;
    // 0x8004CD10: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x8004CD14: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8004CD18: addu        $t5, $t7, $t2
    ctx->r13 = ADD32(ctx->r15, ctx->r10);
    // 0x8004CD1C: lhu         $v1, 0x0($t5)
    ctx->r3 = MEM_HU(ctx->r13, 0X0);
    // 0x8004CD20: subu        $t4, $t3, $t9
    ctx->r12 = SUB32(ctx->r11, ctx->r25);
    // 0x8004CD24: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8004CD28: srav        $t7, $v1, $t4
    ctx->r15 = S32(SIGNED(ctx->r3) >> (ctx->r12 & 31));
    // 0x8004CD2C: andi        $t5, $t7, 0x1
    ctx->r13 = ctx->r15 & 0X1;
    // 0x8004CD30: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8004CD34: beq         $t5, $zero, L_8004CE50
    if (ctx->r13 == 0) {
        // 0x8004CD38: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_8004CE50;
    }
    // 0x8004CD38: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8004CD3C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004CD40: sb          $t8, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r24;
    // 0x8004CD44: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004CD48: lwc1        $f16, 0x8D8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X8D8);
    // 0x8004CD4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004CD50: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8004CD54: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8004CD58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004CD5C: addiu       $t6, $t0, 0xC
    ctx->r14 = ADD32(ctx->r8, 0XC);
    // 0x8004CD60: bc1tl       L_8004CD90
    if (c1cs) {
        // 0x8004CD64: sub.s       $f12, $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_8004CD90;
    }
    goto skip_1;
    // 0x8004CD64: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    skip_1:
    // 0x8004CD68: lwc1        $f18, 0x8DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X8DC);
    // 0x8004CD6C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8004CD70: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8004CD74: nop

    // 0x8004CD78: bc1tl       L_8004CD90
    if (c1cs) {
        // 0x8004CD7C: sub.s       $f12, $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_8004CD90;
    }
    goto skip_2;
    // 0x8004CD7C: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    skip_2:
    // 0x8004CD80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004CD84: b           L_8004CE5C
    // 0x8004CD88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004CE5C;
    // 0x8004CD88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004CD8C: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
L_8004CD90:
    // 0x8004CD90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8004CD94: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8004CD98: jal         0x800534C0
    // 0x8004CD9C: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    func_800534C0(rdram, ctx);
        goto after_1;
    // 0x8004CD9C: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8004CDA0: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x8004CDA4: addiu       $t1, $sp, 0x46
    ctx->r9 = ADD32(ctx->r29, 0X46);
    // 0x8004CDA8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8004CDAC: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004CDB0: beq         $t3, $zero, L_8004CE50
    if (ctx->r11 == 0) {
        // 0x8004CDB4: sh          $v0, 0x46($sp)
        MEM_H(0X46, ctx->r29) = ctx->r2;
            goto L_8004CE50;
    }
    // 0x8004CDB4: sh          $v0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r2;
    // 0x8004CDB8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004CDBC: beql        $t3, $at, L_8004CE54
    if (ctx->r11 == ctx->r1) {
        // 0x8004CDC0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004CE54;
    }
    goto skip_3;
    // 0x8004CDC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x8004CDC4: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8004CDC8: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004CDCC: andi        $v0, $v1, 0xF8
    ctx->r2 = ctx->r3 & 0XF8;
    // 0x8004CDD0: beq         $v0, $at, L_8004CE50
    if (ctx->r2 == ctx->r1) {
        // 0x8004CDD4: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004CE50;
    }
    // 0x8004CDD4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004CDD8: beql        $v0, $at, L_8004CE54
    if (ctx->r2 == ctx->r1) {
        // 0x8004CDDC: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004CE54;
    }
    goto skip_4;
    // 0x8004CDDC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_4:
    // 0x8004CDE0: lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1);
    // 0x8004CDE4: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x8004CDE8: andi        $a0, $v0, 0x3F
    ctx->r4 = ctx->r2 & 0X3F;
    // 0x8004CDEC: xori        $t4, $a0, 0x3
    ctx->r12 = ctx->r4 ^ 0X3;
    // 0x8004CDF0: sltu        $t4, $zero, $t4
    ctx->r12 = 0 < ctx->r12 ? 1 : 0;
    // 0x8004CDF4: and         $t7, $t9, $t4
    ctx->r15 = ctx->r25 & ctx->r12;
    // 0x8004CDF8: beq         $t7, $zero, L_8004CE50
    if (ctx->r15 == 0) {
        // 0x8004CDFC: srl         $t5, $v0, 6
        ctx->r13 = S32(U32(ctx->r2) >> 6);
            goto L_8004CE50;
    }
    // 0x8004CDFC: srl         $t5, $v0, 6
    ctx->r13 = S32(U32(ctx->r2) >> 6);
    // 0x8004CE00: sll         $t8, $t5, 8
    ctx->r24 = S32(ctx->r13 << 8);
    // 0x8004CE04: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8004CE08: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8004CE0C: addu        $t3, $t8, $t6
    ctx->r11 = ADD32(ctx->r24, ctx->r14);
    // 0x8004CE10: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8004CE14: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x8004CE18: lw          $t9, 0xA24($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XA24);
    // 0x8004CE1C: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8004CE20: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8004CE24: addu        $t4, $t9, $t2
    ctx->r12 = ADD32(ctx->r25, ctx->r10);
    // 0x8004CE28: lhu         $v1, 0x0($t4)
    ctx->r3 = MEM_HU(ctx->r12, 0X0);
    // 0x8004CE2C: andi        $t8, $t5, 0xF
    ctx->r24 = ctx->r13 & 0XF;
    // 0x8004CE30: subu        $t3, $t6, $t8
    ctx->r11 = SUB32(ctx->r14, ctx->r24);
    // 0x8004CE34: srav        $t9, $v1, $t3
    ctx->r25 = S32(SIGNED(ctx->r3) >> (ctx->r11 & 31));
    // 0x8004CE38: andi        $t4, $t9, 0x1
    ctx->r12 = ctx->r25 & 0X1;
    // 0x8004CE3C: beq         $t4, $zero, L_8004CE50
    if (ctx->r12 == 0) {
        // 0x8004CE40: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8004CE50;
    }
    // 0x8004CE40: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8004CE44: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004CE48: b           L_8004CE5C
    // 0x8004CE4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004CE5C;
    // 0x8004CE4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004CE50:
    // 0x8004CE50: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8004CE54:
    // 0x8004CE54: nop

    // 0x8004CE58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004CE5C:
    // 0x8004CE5C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8004CE60: jr          $ra
    // 0x8004CE64: nop

    return;
    // 0x8004CE64: nop

;}
RECOMP_FUNC void func_80064C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064C14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064C18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064C1C: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80064C20: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80064C24: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x80064C28: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x80064C2C: slti        $at, $t7, 0x21
    ctx->r1 = SIGNED(ctx->r15) < 0X21 ? 1 : 0;
    // 0x80064C30: bne         $at, $zero, L_80064C64
    if (ctx->r1 != 0) {
        // 0x80064C34: addiu       $t8, $zero, 0x913
        ctx->r24 = ADD32(0, 0X913);
            goto L_80064C64;
    }
    // 0x80064C34: addiu       $t8, $zero, 0x913
    ctx->r24 = ADD32(0, 0X913);
    // 0x80064C38: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80064C3C: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x80064C40: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80064C44: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80064C48: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x80064C4C: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x80064C50: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x80064C54: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x80064C58: sw          $v0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r2;
    // 0x80064C5C: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x80064C60: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
L_80064C64:
    // 0x80064C64: bne         $a2, $zero, L_80064C78
    if (ctx->r6 != 0) {
        // 0x80064C68: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80064C78;
    }
    // 0x80064C68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064C6C: jal         0x80064B64
    // 0x80064C70: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80064B64(rdram, ctx);
        goto after_0;
    // 0x80064C70: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80064C74: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80064C78:
    // 0x80064C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064C7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064C80: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80064C84: jr          $ra
    // 0x80064C88: nop

    return;
    // 0x80064C88: nop

;}
RECOMP_FUNC void func_80028FF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028FF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028FFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029000: lbu         $t6, 0xF4($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XF4);
    // 0x80029004: bne         $t6, $zero, L_8002902C
    if (ctx->r14 != 0) {
        // 0x80029008: nop
    
            goto L_8002902C;
    }
    // 0x80029008: nop

    // 0x8002900C: lw          $t7, 0x24($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X24);
    // 0x80029010: andi        $t8, $t7, 0x700
    ctx->r24 = ctx->r15 & 0X700;
    // 0x80029014: beql        $t8, $zero, L_80029038
    if (ctx->r24 == 0) {
        // 0x80029018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80029038;
    }
    goto skip_0;
    // 0x80029018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002901C: lw          $t9, 0x28($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X28);
    // 0x80029020: andi        $t0, $t9, 0x700
    ctx->r8 = ctx->r25 & 0X700;
    // 0x80029024: bnel        $t0, $zero, L_80029038
    if (ctx->r8 != 0) {
        // 0x80029028: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80029038;
    }
    goto skip_1;
    // 0x80029028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_8002902C:
    // 0x8002902C: jal         0x80028DB4
    // 0x80029030: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80028DB4(rdram, ctx);
        goto after_0;
    // 0x80029030: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80029034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80029038:
    // 0x80029038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002903C: jr          $ra
    // 0x80029040: nop

    return;
    // 0x80029040: nop

;}
RECOMP_FUNC void func_8004AD9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004AD9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004ADA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004ADA4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004ADA8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8004ADAC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004ADB0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8004ADB4: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    // 0x8004ADB8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8004ADBC: lh          $t0, 0x10($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X10);
    // 0x8004ADC0: blez        $v0, L_8004AE40
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004ADC4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8004AE40;
    }
    // 0x8004ADC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004ADC8: lbu         $t9, 0x1($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X1);
    // 0x8004ADCC: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8004ADD0: sll         $t5, $t0, 1
    ctx->r13 = S32(ctx->r8 << 1);
    // 0x8004ADD4: srl         $t7, $t9, 6
    ctx->r15 = S32(U32(ctx->r25) >> 6);
    // 0x8004ADD8: andi        $t1, $t9, 0x3F
    ctx->r9 = ctx->r25 & 0X3F;
    // 0x8004ADDC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8004ADE0: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8004ADE4: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x8004ADE8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8004ADEC: lw          $t4, 0xA24($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XA24);
    // 0x8004ADF0: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x8004ADF4: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x8004ADF8: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
L_8004ADFC:
    // 0x8004ADFC: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8004AE00: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x8004AE04: and         $t1, $t9, $a1
    ctx->r9 = ctx->r25 & ctx->r5;
    // 0x8004AE08: beq         $t1, $zero, L_8004AE20
    if (ctx->r9 == 0) {
        // 0x8004AE0C: nop
    
            goto L_8004AE20;
    }
    // 0x8004AE0C: nop

    // 0x8004AE10: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x8004AE14: andi        $t2, $t8, 0x1
    ctx->r10 = ctx->r24 & 0X1;
    // 0x8004AE18: bnel        $t2, $zero, L_8004AE2C
    if (ctx->r10 != 0) {
        // 0x8004AE1C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8004AE2C;
    }
    goto skip_0;
    // 0x8004AE1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_8004AE20:
    // 0x8004AE20: b           L_8004AF78
    // 0x8004AE24: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8004AF78;
    // 0x8004AE24: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004AE28: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8004AE2C:
    // 0x8004AE2C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004AE30: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004AE34: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004AE38: bnel        $at, $zero, L_8004ADFC
    if (ctx->r1 != 0) {
        // 0x8004AE3C: sll         $t6, $v1, 1
        ctx->r14 = S32(ctx->r3 << 1);
            goto L_8004ADFC;
    }
    goto skip_1;
    // 0x8004AE3C: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    skip_1:
L_8004AE40:
    // 0x8004AE40: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8004AE44: slti        $at, $t3, 0x11
    ctx->r1 = SIGNED(ctx->r11) < 0X11 ? 1 : 0;
    // 0x8004AE48: bnel        $at, $zero, L_8004AE5C
    if (ctx->r1 != 0) {
        // 0x8004AE4C: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_8004AE5C;
    }
    goto skip_2;
    // 0x8004AE4C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    skip_2:
    // 0x8004AE50: b           L_8004AF78
    // 0x8004AE54: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8004AF78;
    // 0x8004AE54: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004AE58: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
L_8004AE5C:
    // 0x8004AE5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004AE60: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004AE64: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x8004AE68: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004AE6C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004AE70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004AE74: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8004AE78: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004AE7C: sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    // 0x8004AE80: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8004AE84: jal         0x800534C0
    // 0x8004AE88: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800534C0(rdram, ctx);
        goto after_0;
    // 0x8004AE88: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_0:
    // 0x8004AE8C: lh          $v1, 0x2E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2E);
    // 0x8004AE90: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8004AE94: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8004AE98: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8004AE9C: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x8004AEA0: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8004AEA4: andi        $t9, $v0, 0x7FF
    ctx->r25 = ctx->r2 & 0X7FF;
    // 0x8004AEA8: andi        $t6, $t5, 0xF8
    ctx->r14 = ctx->r13 & 0XF8;
    // 0x8004AEAC: bnel        $t6, $at, L_8004AEBC
    if (ctx->r14 != ctx->r1) {
        // 0x8004AEB0: lhu         $v0, 0x0($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X0);
            goto L_8004AEBC;
    }
    goto skip_3;
    // 0x8004AEB0: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    skip_3:
    // 0x8004AEB4: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x8004AEB8: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
L_8004AEBC:
    // 0x8004AEBC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004AEC0: beql        $v0, $zero, L_8004AF78
    if (ctx->r2 == 0) {
        // 0x8004AEC4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004AF78;
    }
    goto skip_4;
    // 0x8004AEC4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_4:
    // 0x8004AEC8: beql        $v0, $at, L_8004AF78
    if (ctx->r2 == ctx->r1) {
        // 0x8004AECC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004AF78;
    }
    goto skip_5;
    // 0x8004AECC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_5:
    // 0x8004AED0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004AED4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004AED8: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8004AEDC: beq         $v0, $at, L_8004AF74
    if (ctx->r2 == ctx->r1) {
        // 0x8004AEE0: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004AF74;
    }
    // 0x8004AEE0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004AEE4: beq         $v0, $at, L_8004AF74
    if (ctx->r2 == ctx->r1) {
        // 0x8004AEE8: addiu       $t1, $zero, 0x10
        ctx->r9 = ADD32(0, 0X10);
            goto L_8004AF74;
    }
    // 0x8004AEE8: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8004AEEC: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x8004AEF0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8004AEF4: sh          $zero, 0x10($s0)
    MEM_H(0X10, ctx->r16) = 0;
    // 0x8004AEF8: srl         $t8, $v0, 6
    ctx->r24 = S32(U32(ctx->r2) >> 6);
    // 0x8004AEFC: andi        $t3, $v0, 0x3F
    ctx->r11 = ctx->r2 & 0X3F;
    // 0x8004AF00: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8004AF04: sll         $t2, $t8, 8
    ctx->r10 = S32(ctx->r24 << 8);
    // 0x8004AF08: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8004AF0C: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
    // 0x8004AF10: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8004AF14: lw          $t6, 0xA24($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XA24);
    // 0x8004AF18: lhu         $t9, 0x2($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2);
    // 0x8004AF1C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8004AF20: and         $t1, $t7, $t9
    ctx->r9 = ctx->r15 & ctx->r25;
    // 0x8004AF24: beql        $t1, $zero, L_8004AF78
    if (ctx->r9 == 0) {
        // 0x8004AF28: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004AF78;
    }
    goto skip_6;
    // 0x8004AF28: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_6:
    // 0x8004AF2C: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
    // 0x8004AF30: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x8004AF34: lhu         $t8, 0x0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X0);
    // 0x8004AF38: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x8004AF3C: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x8004AF40: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8004AF44: lw          $t4, 0x40($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X40);
    // 0x8004AF48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8004AF4C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8004AF50: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x8004AF54: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8004AF58: sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    // 0x8004AF5C: jal         0x8004AD9C
    // 0x8004AF60: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_8004AD9C(rdram, ctx);
        goto after_1;
    // 0x8004AF60: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_1:
    // 0x8004AF64: lh          $v1, 0x2E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2E);
    // 0x8004AF68: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004AF6C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004AF70: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8004AF74:
    // 0x8004AF74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8004AF78:
    // 0x8004AF78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004AF7C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004AF80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004AF84: jr          $ra
    // 0x8004AF88: nop

    return;
    // 0x8004AF88: nop

;}
RECOMP_FUNC void func_805DC410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DC410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DC414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DC418: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805DC41C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805DC420: slti        $at, $v0, 0x407A
    ctx->r1 = SIGNED(ctx->r2) < 0X407A ? 1 : 0;
    // 0x805DC424: bne         $at, $zero, L_805DC470
    if (ctx->r1 != 0) {
        // 0x805DC428: slti        $at, $v0, 0x4093
        ctx->r1 = SIGNED(ctx->r2) < 0X4093 ? 1 : 0;
            goto L_805DC470;
    }
    // 0x805DC428: slti        $at, $v0, 0x4093
    ctx->r1 = SIGNED(ctx->r2) < 0X4093 ? 1 : 0;
    // 0x805DC42C: bne         $at, $zero, L_805DC454
    if (ctx->r1 != 0) {
        // 0x805DC430: addiu       $t7, $v0, -0x4532
        ctx->r15 = ADD32(ctx->r2, -0X4532);
            goto L_805DC454;
    }
    // 0x805DC430: addiu       $t7, $v0, -0x4532
    ctx->r15 = ADD32(ctx->r2, -0X4532);
    // 0x805DC434: sltiu       $at, $t7, 0x15
    ctx->r1 = ctx->r15 < 0X15 ? 1 : 0;
    // 0x805DC438: beq         $at, $zero, L_805DC4AC
    if (ctx->r1 == 0) {
        // 0x805DC43C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_805DC4AC;
    }
    // 0x805DC43C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805DC440: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X286C) << 16);
    // 0x805DC444: addu        $at, $at, $t7
    gpr jr_addend_805DC44C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x805DC448: lw          $t7, -0x2A94($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(480, 0X286C));
    // 0x805DC44C: jr          $t7
    // 0x805DC450: nop

    switch (jr_addend_805DC44C >> 2) {
        case 0: goto L_805DC4A4; break;
        case 1: goto L_805DC494; break;
        case 2: goto L_805DC4A4; break;
        case 3: goto L_805DC494; break;
        case 4: goto L_805DC4AC; break;
        case 5: goto L_805DC4AC; break;
        case 6: goto L_805DC4AC; break;
        case 7: goto L_805DC4AC; break;
        case 8: goto L_805DC4AC; break;
        case 9: goto L_805DC4AC; break;
        case 10: goto L_805DC4AC; break;
        case 11: goto L_805DC4A4; break;
        case 12: goto L_805DC4AC; break;
        case 13: goto L_805DC4AC; break;
        case 14: goto L_805DC4AC; break;
        case 15: goto L_805DC4AC; break;
        case 16: goto L_805DC4AC; break;
        case 17: goto L_805DC4AC; break;
        case 18: goto L_805DC4AC; break;
        case 19: goto L_805DC4A4; break;
        case 20: goto L_805DC494; break;
        default: switch_error(__func__, 0x805DC44C, 0x805DD56C);
    }
    // 0x805DC450: nop

L_805DC454:
    // 0x805DC454: addiu       $at, $zero, 0x407C
    ctx->r1 = ADD32(0, 0X407C);
    // 0x805DC458: beq         $v0, $at, L_805DC494
    if (ctx->r2 == ctx->r1) {
        // 0x805DC45C: addiu       $at, $zero, 0x4092
        ctx->r1 = ADD32(0, 0X4092);
            goto L_805DC494;
    }
    // 0x805DC45C: addiu       $at, $zero, 0x4092
    ctx->r1 = ADD32(0, 0X4092);
    // 0x805DC460: beq         $v0, $at, L_805DC4A4
    if (ctx->r2 == ctx->r1) {
        // 0x805DC464: nop
    
            goto L_805DC4A4;
    }
    // 0x805DC464: nop

    // 0x805DC468: b           L_805DC4AC
    // 0x805DC46C: nop

        goto L_805DC4AC;
    // 0x805DC46C: nop

L_805DC470:
    // 0x805DC470: addiu       $at, $zero, 0x4047
    ctx->r1 = ADD32(0, 0X4047);
    // 0x805DC474: beq         $v0, $at, L_805DC494
    if (ctx->r2 == ctx->r1) {
        // 0x805DC478: addiu       $at, $zero, 0x4048
        ctx->r1 = ADD32(0, 0X4048);
            goto L_805DC494;
    }
    // 0x805DC478: addiu       $at, $zero, 0x4048
    ctx->r1 = ADD32(0, 0X4048);
    // 0x805DC47C: beq         $v0, $at, L_805DC494
    if (ctx->r2 == ctx->r1) {
        // 0x805DC480: addiu       $at, $zero, 0x4079
        ctx->r1 = ADD32(0, 0X4079);
            goto L_805DC494;
    }
    // 0x805DC480: addiu       $at, $zero, 0x4079
    ctx->r1 = ADD32(0, 0X4079);
    // 0x805DC484: beq         $v0, $at, L_805DC4A4
    if (ctx->r2 == ctx->r1) {
        // 0x805DC488: nop
    
            goto L_805DC4A4;
    }
    // 0x805DC488: nop

    // 0x805DC48C: b           L_805DC4AC
    // 0x805DC490: nop

        goto L_805DC4AC;
    // 0x805DC490: nop

L_805DC494:
    // 0x805DC494: jal         0x805DC0A8
    // 0x805DC498: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805DC0A8(rdram, ctx);
        goto after_0;
    // 0x805DC498: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x805DC49C: b           L_805DC4AC
    // 0x805DC4A0: nop

        goto L_805DC4AC;
    // 0x805DC4A0: nop

L_805DC4A4:
    // 0x805DC4A4: jal         0x805DC010
    // 0x805DC4A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805DC010(rdram, ctx);
        goto after_1;
    // 0x805DC4A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_805DC4AC:
    // 0x805DC4AC: jal         0x805DBB44
    // 0x805DC4B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805DBB44(rdram, ctx);
        goto after_2;
    // 0x805DC4B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x805DC4B4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x805DC4B8: lw          $v0, 0x1F4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X1F4);
    // 0x805DC4BC: lhu         $t9, 0x74($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X74);
    // 0x805DC4C0: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x805DC4C4: sh          $t0, 0x74($v0)
    MEM_H(0X74, ctx->r2) = ctx->r8;
    // 0x805DC4C8: jal         0x805DC318
    // 0x805DC4CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805DC318(rdram, ctx);
        goto after_3;
    // 0x805DC4CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x805DC4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DC4D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DC4D8: jr          $ra
    // 0x805DC4DC: nop

    return;
    // 0x805DC4DC: nop

;}
RECOMP_FUNC void func_8005D7F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D7F4: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8005D7F8: addiu       $v1, $a0, 0x4
    ctx->r3 = ADD32(ctx->r4, 0X4);
    // 0x8005D7FC: beql        $v0, $zero, L_8005D834
    if (ctx->r2 == 0) {
        // 0x8005D800: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005D834;
    }
    goto skip_0;
    // 0x8005D800: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_8005D804:
    // 0x8005D804: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8005D808: beq         $a1, $zero, L_8005D828
    if (ctx->r5 == 0) {
        // 0x8005D80C: nop
    
            goto L_8005D828;
    }
    // 0x8005D80C: nop

    // 0x8005D810: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8005D814: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8005D818: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8005D81C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8005D820: jr          $ra
    // 0x8005D824: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x8005D824: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
L_8005D828:
    // 0x8005D828: bne         $v0, $zero, L_8005D804
    if (ctx->r2 != 0) {
        // 0x8005D82C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8005D804;
    }
    // 0x8005D82C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005D830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005D834:
    // 0x8005D834: jr          $ra
    // 0x8005D838: nop

    return;
    // 0x8005D838: nop

;}
RECOMP_FUNC void func_8053056C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053056C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80530570: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80530574: lw          $t6, 0xE94($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE94);
    // 0x80530578: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8053057C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80530580: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80530584: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80530588: sh          $a3, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r7;
    // 0x8053058C: lw          $t7, 0xE94($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XE94);
    // 0x80530590: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80530594: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80530598: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8053059C: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x805305A0: lw          $t8, 0xE94($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE94);
    // 0x805305A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805305A8: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x805305AC: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x805305B0: lw          $t9, 0xE94($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XE94);
    // 0x805305B4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x805305B8: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x805305BC: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x805305C0: lwc1        $f16, 0x8C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x805305C4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x805305C8: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x805305CC: lw          $t9, 0xC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XC);
    // 0x805305D0: jalr        $t9
    // 0x805305D4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805305D4: nop

    after_0:
    // 0x805305D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805305DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805305E0: jr          $ra
    // 0x805305E4: nop

    return;
    // 0x805305E4: nop

;}
RECOMP_FUNC void func_806DFBD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DFBD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DFBD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DFBDC: jal         0x806DF82C
    // 0x806DFBE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806DF82C(rdram, ctx);
        goto after_0;
    // 0x806DFBE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806DFBE4: jal         0x806DF8AC
    // 0x806DFBE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806DF8AC(rdram, ctx);
        goto after_1;
    // 0x806DFBE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806DFBEC: jal         0x806DF9C8
    // 0x806DFBF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806DF9C8(rdram, ctx);
        goto after_2;
    // 0x806DFBF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806DFBF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DFBF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DFBFC: jr          $ra
    // 0x806DFC00: nop

    return;
    // 0x806DFC00: nop

;}
RECOMP_FUNC void func_8044FF44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044FF44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044FF48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044FF4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8044FF50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8044FF54: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044FF58: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8044FF5C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8044FF60: jal         0x8044DED0
    // 0x8044FF64: lw          $a0, 0x6A28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A28);
    func_8044DED0(rdram, ctx);
        goto after_0;
    // 0x8044FF64: lw          $a0, 0x6A28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A28);
    after_0:
    // 0x8044FF68: bltz        $v0, L_8044FFA8
    if (SIGNED(ctx->r2) < 0) {
        // 0x8044FF6C: slti        $at, $v0, 0x6
        ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
            goto L_8044FFA8;
    }
    // 0x8044FF6C: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8044FF70: beq         $at, $zero, L_8044FFA8
    if (ctx->r1 == 0) {
        // 0x8044FF74: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8044FFA8;
    }
    // 0x8044FF74: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8044FF78: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X13920) << 16);
    // 0x8044FF7C: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x8044FF80: lw          $v1, 0x7D00($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(98, 0X13920));
    // 0x8044FF84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8044FF88: beql        $v1, $zero, L_8044FFB4
    if (ctx->r3 == 0) {
        // 0x8044FF8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044FFB4;
    }
    goto skip_0;
    // 0x8044FF8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044FF90: jalr        $v1
    // 0x8044FF94: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_1;
    // 0x8044FF94: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8044FF98: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8044FF9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8044FFA0: b           L_8044FFB0
    // 0x8044FFA4: sw          $t8, 0x60($t9)
    MEM_W(0X60, ctx->r25) = ctx->r24;
        goto L_8044FFB0;
    // 0x8044FFA4: sw          $t8, 0x60($t9)
    MEM_W(0X60, ctx->r25) = ctx->r24;
L_8044FFA8:
    // 0x8044FFA8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044FFAC: sw          $zero, 0x60($t0)
    MEM_W(0X60, ctx->r8) = 0;
L_8044FFB0:
    // 0x8044FFB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044FFB4:
    // 0x8044FFB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044FFB8: jr          $ra
    // 0x8044FFBC: nop

    return;
    // 0x8044FFBC: nop

;}
RECOMP_FUNC void func_80517DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517DB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80517DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80517DB8: lwc1        $f6, 0xDC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x80517DBC: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80517DC0: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x80517DC4: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x80517DC8: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80517DCC: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80517DD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80517DD4: jal         0x80065ABC
    // 0x80517DD8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x80517DD8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80517DDC: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80517DE0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80517DE4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80517DE8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80517DEC: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x80517DF0: bc1fl       L_80517E30
    if (!c1cs) {
        // 0x80517DF4: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_80517E30;
    }
    goto skip_0;
    // 0x80517DF4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_0:
    // 0x80517DF8: lwc1        $f0, 0xE8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XE8);
    // 0x80517DFC: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80517E00: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80517E04: nop

    // 0x80517E08: bc1fl       L_80517E20
    if (!c1cs) {
        // 0x80517E0C: lwc1        $f16, 0xC4($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0XC4);
            goto L_80517E20;
    }
    goto skip_1;
    // 0x80517E0C: lwc1        $f16, 0xC4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC4);
    skip_1:
    // 0x80517E10: lwc1        $f10, 0xDC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x80517E14: b           L_80517E68
    // 0x80517E18: swc1        $f10, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f10.u32l;
        goto L_80517E68;
    // 0x80517E18: swc1        $f10, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f10.u32l;
    // 0x80517E1C: lwc1        $f16, 0xC4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC4);
L_80517E20:
    // 0x80517E20: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80517E24: b           L_80517E68
    // 0x80517E28: swc1        $f18, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f18.u32l;
        goto L_80517E68;
    // 0x80517E28: swc1        $f18, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f18.u32l;
    // 0x80517E2C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_80517E30:
    // 0x80517E30: nop

    // 0x80517E34: bc1fl       L_80517E6C
    if (!c1cs) {
        // 0x80517E38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80517E6C;
    }
    goto skip_2;
    // 0x80517E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80517E3C: lwc1        $f0, 0xE8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XE8);
    // 0x80517E40: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80517E44: nop

    // 0x80517E48: bc1fl       L_80517E60
    if (!c1cs) {
        // 0x80517E4C: lwc1        $f6, 0xC4($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
            goto L_80517E60;
    }
    goto skip_3;
    // 0x80517E4C: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    skip_3:
    // 0x80517E50: lwc1        $f4, 0xDC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x80517E54: b           L_80517E68
    // 0x80517E58: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
        goto L_80517E68;
    // 0x80517E58: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x80517E5C: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
L_80517E60:
    // 0x80517E60: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80517E64: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
L_80517E68:
    // 0x80517E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80517E6C:
    // 0x80517E6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80517E70: jr          $ra
    // 0x80517E74: nop

    return;
    // 0x80517E74: nop

;}
RECOMP_FUNC void func_800688CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800688CC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x800688D0: lw          $t6, -0x7BC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7BC4);
    // 0x800688D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800688D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800688DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800688E0: lw          $s0, 0x104($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X104);
    // 0x800688E4: jal         0x800493F4
    // 0x800688E8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    func_800493F4(rdram, ctx);
        goto after_0;
    // 0x800688E8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_0:
    // 0x800688EC: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x800688F0: beq         $s0, $at, L_80068938
    if (ctx->r16 == ctx->r1) {
        // 0x800688F4: lui         $t7, 0x800A
        ctx->r15 = S32(0X800A << 16);
            goto L_80068938;
    }
    // 0x800688F4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800688F8: lw          $t7, 0x6EBC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6EBC);
    // 0x800688FC: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x80068900: beq         $t7, $s0, L_80068938
    if (ctx->r15 == ctx->r16) {
        // 0x80068904: nop
    
            goto L_80068938;
    }
    // 0x80068904: nop

    // 0x80068908: bne         $s0, $at, L_80068924
    if (ctx->r16 != ctx->r1) {
        // 0x8006890C: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_80068924;
    }
    // 0x8006890C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80068910: lw          $t9, -0x7208($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7208);
    // 0x80068914: jalr        $t9
    // 0x80068918: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80068918: nop

    after_1:
    // 0x8006891C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80068920: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_80068924:
    // 0x80068924: jal         0x800679B0
    // 0x80068928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800679B0(rdram, ctx);
        goto after_2;
    // 0x80068928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8006892C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80068930: b           L_80068940
    // 0x80068934: sw          $s0, 0x6EBC($at)
    MEM_W(0X6EBC, ctx->r1) = ctx->r16;
        goto L_80068940;
    // 0x80068934: sw          $s0, 0x6EBC($at)
    MEM_W(0X6EBC, ctx->r1) = ctx->r16;
L_80068938:
    // 0x80068938: jal         0x800679B0
    // 0x8006893C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800679B0(rdram, ctx);
        goto after_3;
    // 0x8006893C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
L_80068940:
    // 0x80068940: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80068944: lw          $v0, -0x7BC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7BC4);
    // 0x80068948: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006894C: lw          $a0, 0x118($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X118);
    // 0x80068950: beql        $a0, $zero, L_80068974
    if (ctx->r4 == 0) {
        // 0x80068954: lw          $a0, 0x108($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X108);
            goto L_80068974;
    }
    goto skip_0;
    // 0x80068954: lw          $a0, 0x108($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X108);
    skip_0:
    // 0x80068958: bnel        $t0, $zero, L_80068974
    if (ctx->r8 != 0) {
        // 0x8006895C: lw          $a0, 0x108($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X108);
            goto L_80068974;
    }
    goto skip_1;
    // 0x8006895C: lw          $a0, 0x108($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X108);
    skip_1:
    // 0x80068960: jal         0x800677F8
    // 0x80068964: nop

    func_800677F8(rdram, ctx);
        goto after_4;
    // 0x80068964: nop

    after_4:
    // 0x80068968: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8006896C: lw          $v0, -0x7BC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7BC4);
    // 0x80068970: lw          $a0, 0x108($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X108);
L_80068974:
    // 0x80068974: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80068978: beql        $a0, $zero, L_8006898C
    if (ctx->r4 == 0) {
        // 0x8006897C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006898C;
    }
    goto skip_2;
    // 0x8006897C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80068980: jal         0x80067838
    // 0x80068984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80067838(rdram, ctx);
        goto after_5;
    // 0x80068984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80068988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006898C:
    // 0x8006898C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068990: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80068994: jr          $ra
    // 0x80068998: nop

    return;
    // 0x80068998: nop

;}
RECOMP_FUNC void func_80553838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80553838: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8055383C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80553840: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80553844: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X4164) << 16);
    // 0x80553848: swc1        $f0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f0.u32l;
    // 0x8055384C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x80553850: lwc1        $f4, 0x4C84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X4164));
    // 0x80553854: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80553858: swc1        $f2, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f2.u32l;
    // 0x8055385C: swc1        $f2, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f2.u32l;
    // 0x80553860: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x80553864: jr          $ra
    // 0x80553868: sw          $zero, 0xDB4($v0)
    MEM_W(0XDB4, ctx->r2) = 0;
    return;
    // 0x80553868: sw          $zero, 0xDB4($v0)
    MEM_W(0XDB4, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80432B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432B00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80432B04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80432B08: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80432B0C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80432B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80432B14: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80432B18: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80432B1C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80432B20: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80432B24: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80432B28: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(62, 0X490) << 16);
    // 0x80432B2C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80432B30: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80432B34: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80432B38: lw          $t2, 0x2C30($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(62, 0X490));
    // 0x80432B3C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80432B40: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80432B44: jal         0x80432B64
    // 0x80432B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80432B64(rdram, ctx);
        goto after_0;
    // 0x80432B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80432B4C: jal         0x80432BB0
    // 0x80432B50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80432BB0(rdram, ctx);
        goto after_1;
    // 0x80432B50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80432B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80432B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80432B5C: jr          $ra
    // 0x80432B60: nop

    return;
    // 0x80432B60: nop

;}
RECOMP_FUNC void func_8064B834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B834: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064B838: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064B83C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064B840: lh          $t6, 0xC0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XC0);
    // 0x8064B844: lui         $at, 0x432E
    ctx->r1 = S32(0X432E << 16);
    // 0x8064B848: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8064B84C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8064B850: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8064B854: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8064B858: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8064B85C: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064B860: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8064B864: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064B868: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8064B86C: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8064B870: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x8064B874: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8064B878: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8064B87C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8064B880: swc1        $f10, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f10.u32l;
    // 0x8064B884: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x8064B888: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8064B88C: jal         0x8064B7D8
    // 0x8064B890: sh          $t8, 0xC0($a0)
    MEM_H(0XC0, ctx->r4) = ctx->r24;
    func_8064B7D8(rdram, ctx);
        goto after_0;
    // 0x8064B890: sh          $t8, 0xC0($a0)
    MEM_H(0XC0, ctx->r4) = ctx->r24;
    after_0:
    // 0x8064B894: bne         $v0, $zero, L_8064B8AC
    if (ctx->r2 != 0) {
        // 0x8064B898: lui         $t9, 0x8065
        ctx->r25 = S32(RELOC_HI16(495, 0X1680) << 16);
            goto L_8064B8AC;
    }
    // 0x8064B898: lui         $t9, 0x8065
    ctx->r25 = S32(RELOC_HI16(495, 0X1680) << 16);
    // 0x8064B89C: jal         0x800445A4
    // 0x8064B8A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8064B8A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8064B8A4: b           L_8064B908
    // 0x8064B8A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8064B908;
    // 0x8064B8A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064B8AC:
    // 0x8064B8AC: addiu       $t9, $t9, -0x48B0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(495, 0X1680));
    // 0x8064B8B0: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x8064B8B4: jal         0x8064A468
    // 0x8064B8B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A468(rdram, ctx);
        goto after_2;
    // 0x8064B8B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8064B8BC: jal         0x8064B81C
    // 0x8064B8C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064B81C(rdram, ctx);
        goto after_3;
    // 0x8064B8C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8064B8C4: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x8064B8C8: lui         $t0, 0x8065
    ctx->r8 = S32(RELOC_HI16(495, 0X30B4) << 16);
    // 0x8064B8CC: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8064B8D0: addiu       $t0, $t0, -0x2E7C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(495, 0X30B4));
    // 0x8064B8D4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8064B8D8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8064B8DC: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8064B8E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064B8E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064B8E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8064B8EC: jal         0x8064B918
    // 0x8064B8F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8064B918(rdram, ctx);
        goto after_4;
    // 0x8064B8F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8064B8F4: jal         0x8064A158
    // 0x8064B8F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A158(rdram, ctx);
        goto after_5;
    // 0x8064B8F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8064B8FC: jal         0x8064A40C
    // 0x8064B900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A40C(rdram, ctx);
        goto after_6;
    // 0x8064B900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8064B904: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064B908:
    // 0x8064B908: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064B90C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064B910: jr          $ra
    // 0x8064B914: nop

    return;
    // 0x8064B914: nop

;}
RECOMP_FUNC void func_804532FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804532FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453304: jal         0x804531D0
    // 0x80453308: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804531D0(rdram, ctx);
        goto after_0;
    // 0x80453308: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045330C: beql        $v0, $zero, L_80453320
    if (ctx->r2 == 0) {
        // 0x80453310: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80453320;
    }
    goto skip_0;
    // 0x80453310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80453314: jal         0x804528C4
    // 0x80453318: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804528C4(rdram, ctx);
        goto after_1;
    // 0x80453318: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8045331C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80453320:
    // 0x80453320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453324: jr          $ra
    // 0x80453328: nop

    return;
    // 0x80453328: nop

;}
RECOMP_FUNC void func_80461FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461FB4: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80461FB8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80461FBC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80461FC0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80461FC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80461FC8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80461FCC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80461FD0:
    // 0x80461FD0: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80461FD4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80461FD8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80461FDC: nop

    // 0x80461FE0: bc1fl       L_80461FF4
    if (!c1cs) {
        // 0x80461FE4: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_80461FF4;
    }
    goto skip_0;
    // 0x80461FE4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_0:
    // 0x80461FE8: b           L_80462004
    // 0x80461FEC: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
        goto L_80462004;
    // 0x80461FEC: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
    // 0x80461FF0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_80461FF4:
    // 0x80461FF4: nop

    // 0x80461FF8: bc1f        L_80462004
    if (!c1cs) {
        // 0x80461FFC: nop
    
            goto L_80462004;
    }
    // 0x80461FFC: nop

    // 0x80462000: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
L_80462004:
    // 0x80462004: bne         $v1, $v0, L_80461FD0
    if (ctx->r3 != ctx->r2) {
        // 0x80462008: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80461FD0;
    }
    // 0x80462008: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8046200C: jr          $ra
    // 0x80462010: nop

    return;
    // 0x80462010: nop

;}
RECOMP_FUNC void func_800708D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800708D4: lui         $t9, 0xFFFA
    ctx->r25 = S32(0XFFFA << 16);
    // 0x800708D8: or          $t0, $sp, $zero
    ctx->r8 = ctx->r29 | 0;
    // 0x800708DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800708E0: ori         $t9, $t9, 0x5A5A
    ctx->r25 = ctx->r25 | 0X5A5A;
L_800708E4:
    // 0x800708E4: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
    // 0x800708E8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800708EC: bne         $t0, $sp, L_800708E4
    if (ctx->r8 != ctx->r29) {
        // 0x800708F0: sw          $t9, 0x4($t0)
        MEM_W(0X4, ctx->r8) = ctx->r25;
            goto L_800708E4;
    }
    // 0x800708F0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800708F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800708F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800708FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80070900: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80070904: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80070908: lw          $v0, -0x57C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57C4);
    // 0x8007090C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80070910: addiu       $t7, $t7, -0x57C0
    ctx->r15 = ADD32(ctx->r15, -0X57C0);
    // 0x80070914: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80070918: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007091C: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80070920: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80070924: beq         $at, $zero, L_8007096C
    if (ctx->r1 == 0) {
        // 0x80070928: or          $s2, $a0, $zero
        ctx->r18 = ctx->r4 | 0;
            goto L_8007096C;
    }
    // 0x80070928: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8007092C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_80070930:
    // 0x80070930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80070934: beql        $t8, $zero, L_80070954
    if (ctx->r24 == 0) {
        // 0x80070938: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80070954;
    }
    goto skip_0;
    // 0x80070938: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x8007093C: jal         0x80070848
    // 0x80070940: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80070848(rdram, ctx);
        goto after_0;
    // 0x80070940: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80070944: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80070948: lw          $v0, -0x57C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X57C4);
    // 0x8007094C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80070950: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80070954:
    // 0x80070954: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80070958: beq         $at, $zero, L_8007096C
    if (ctx->r1 == 0) {
        // 0x8007095C: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_8007096C;
    }
    // 0x8007095C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80070960: slti        $at, $s1, 0x1C
    ctx->r1 = SIGNED(ctx->r17) < 0X1C ? 1 : 0;
    // 0x80070964: bnel        $at, $zero, L_80070930
    if (ctx->r1 != 0) {
        // 0x80070968: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_80070930;
    }
    goto skip_1;
    // 0x80070968: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_1:
L_8007096C:
    // 0x8007096C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80070970: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80070974: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80070978: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007097C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80070980: jr          $ra
    // 0x80070984: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80070984: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806D6BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D6BC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806D6BC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D6BC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D6BCC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D6BD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D6BD4: jal         0x800692D4
    // 0x806D6BD8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800692D4(rdram, ctx);
        goto after_0;
    // 0x806D6BD8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x806D6BDC: beq         $v0, $zero, L_806D6C58
    if (ctx->r2 == 0) {
        // 0x806D6BE0: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_806D6C58;
    }
    // 0x806D6BE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806D6BE4: lbu         $t6, 0x30($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X30);
    // 0x806D6BE8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x806D6BEC: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x806D6BF0: beql        $t6, $at, L_806D6C5C
    if (ctx->r14 == ctx->r1) {
        // 0x806D6BF4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D6C5C;
    }
    goto skip_0;
    // 0x806D6BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806D6BF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806D6BFC: sw          $t7, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r15;
    // 0x806D6C00: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806D6C04: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x806D6C08: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x806D6C0C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x806D6C10: beql        $v1, $zero, L_806D6C4C
    if (ctx->r3 == 0) {
        // 0x806D6C14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806D6C4C;
    }
    goto skip_1;
    // 0x806D6C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x806D6C18: lw          $t8, 0x180($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X180);
    // 0x806D6C1C: bnel        $s0, $t8, L_806D6C4C
    if (ctx->r16 != ctx->r24) {
        // 0x806D6C20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806D6C4C;
    }
    goto skip_2;
    // 0x806D6C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x806D6C24: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    // 0x806D6C28: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x806D6C2C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x806D6C30: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x806D6C34: jal         0x80067BBC
    // 0x806D6C38: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x806D6C38: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x806D6C3C: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    // 0x806D6C40: jal         0x80067818
    // 0x806D6C44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x806D6C44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x806D6C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_806D6C4C:
    // 0x806D6C4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D6C50: jal         0x806D7A20
    // 0x806D6C54: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_806D7A20(rdram, ctx);
        goto after_3;
    // 0x806D6C54: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_3:
L_806D6C58:
    // 0x806D6C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D6C5C:
    // 0x806D6C5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D6C60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806D6C64: jr          $ra
    // 0x806D6C68: nop

    return;
    // 0x806D6C68: nop

;}
RECOMP_FUNC void func_8057C684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057C688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057C68C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8057C690: jal         0x8057C6B0
    // 0x8057C694: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8057C6B0(rdram, ctx);
        goto after_0;
    // 0x8057C694: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8057C698: jal         0x8057C5F8
    // 0x8057C69C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8057C5F8(rdram, ctx);
        goto after_1;
    // 0x8057C69C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8057C6A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057C6A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057C6A8: jr          $ra
    // 0x8057C6AC: nop

    return;
    // 0x8057C6AC: nop

;}
RECOMP_FUNC void func_8042FB28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FB28: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8042FB2C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8042FB30: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042FB34: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BAC) << 16);
    // 0x8042FB38: swc1        $f2, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f2.u32l;
    // 0x8042FB3C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8042FB40: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8042FB44: lwc1        $f8, 0x1C8C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BAC));
    // 0x8042FB48: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8042FB4C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8042FB50: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8042FB54: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8042FB58: nop

    // 0x8042FB5C: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8042FB60: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x8042FB64: jr          $ra
    // 0x8042FB68: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x8042FB68: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_8043773C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043773C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80437740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80437744: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80437748: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043774C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80437750: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80437754: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x80437758: bnel        $v1, $at, L_804377AC
    if (ctx->r3 != ctx->r1) {
        // 0x8043775C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_804377AC;
    }
    goto skip_0;
    // 0x8043775C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80437760: lwc1        $f4, 0xC4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x80437764: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80437768: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x8043776C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80437770: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80437774: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80437778: jal         0x80065490
    // 0x8043777C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x8043777C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80437780: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80437784: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80437788: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8043778C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80437790: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80437794: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80437798: jal         0x80437540
    // 0x8043779C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_80437540(rdram, ctx);
        goto after_1;
    // 0x8043779C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x804377A0: b           L_80437808
    // 0x804377A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80437808;
    // 0x804377A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804377A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_804377AC:
    // 0x804377AC: bne         $v1, $at, L_80437804
    if (ctx->r3 != ctx->r1) {
        // 0x804377B0: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_80437804;
    }
    // 0x804377B0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x804377B4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x804377B8: jal         0x80065490
    // 0x804377BC: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x804377BC: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    after_2:
    // 0x804377C0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x804377C4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804377C8: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804377CC: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x804377D0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804377D4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x804377D8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x804377DC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804377E0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804377E4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x804377E8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804377EC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804377F0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x804377F4: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x804377F8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804377FC: jal         0x80437650
    // 0x80437800: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_80437650(rdram, ctx);
        goto after_3;
    // 0x80437800: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_3:
L_80437804:
    // 0x80437804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80437808:
    // 0x80437808: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8043780C: jr          $ra
    // 0x80437810: nop

    return;
    // 0x80437810: nop

;}
RECOMP_FUNC void func_8079FFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079FFE8: jr          $ra
    // 0x8079FFEC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8079FFEC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80437CBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437CBC: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80437CC0: lwc1        $f6, 0xE0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x80437CC4: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80437CC8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80437CCC: nop

    // 0x80437CD0: bc1t        L_80437CE8
    if (c1cs) {
        // 0x80437CD4: nop
    
            goto L_80437CE8;
    }
    // 0x80437CD4: nop

    // 0x80437CD8: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80437CDC: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80437CE0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80437CE4: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
L_80437CE8:
    // 0x80437CE8: jr          $ra
    // 0x80437CEC: nop

    return;
    // 0x80437CEC: nop

;}
RECOMP_FUNC void func_8057440C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057440C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80574410: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80574414: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80574418: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8057441C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80574420: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80574424: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80574428: lwc1        $f12, 0x84($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8057442C: jal         0x80053924
    // 0x80574430: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    func_80053924(rdram, ctx);
        goto after_0;
    // 0x80574430: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80574434: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80574438: beq         $v0, $at, L_80574500
    if (ctx->r2 == ctx->r1) {
        // 0x8057443C: sh          $v0, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r2;
            goto L_80574500;
    }
    // 0x8057443C: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x80574440: lbu         $t6, 0x26($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X26);
    // 0x80574444: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x80574448: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8057444C: andi        $t7, $t6, 0xF8
    ctx->r15 = ctx->r14 & 0XF8;
    // 0x80574450: bnel        $t7, $at, L_80574504
    if (ctx->r15 != ctx->r1) {
        // 0x80574454: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80574504;
    }
    goto skip_0;
    // 0x80574454: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80574458: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8057445C: lwc1        $f8, 0x84($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80574460: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80574464: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80574468: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8057446C: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80574470: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(381, 0XEE0) << 16);
    // 0x80574474: lwc1        $f18, 0x4D70($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(381, 0XEE0));
    // 0x80574478: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8057447C: lwc1        $f16, 0x8C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80574480: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80574484: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80574488: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8057448C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80574490: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(381, 0XEE4) << 16);
    // 0x80574494: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80574498: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8057449C: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x805744A0: lwc1        $f4, 0x4D74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(381, 0XEE4));
    // 0x805744A4: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x805744A8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x805744AC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x805744B0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x805744B4: lwc1        $f10, 0x70($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X70);
    // 0x805744B8: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x805744BC: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x805744C0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x805744C4: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x805744C8: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x805744CC: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x805744D0: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x805744D4: lw          $t9, 0x28($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X28);
    // 0x805744D8: jalr        $t9
    // 0x805744DC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x805744DC: nop

    after_1:
    // 0x805744E0: jal         0x80048D4C
    // 0x805744E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048D4C(rdram, ctx);
        goto after_2;
    // 0x805744E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805744E8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805744EC: jal         0x80067BBC
    // 0x805744F0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x805744F0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x805744F4: addiu       $a0, $zero, 0x278
    ctx->r4 = ADD32(0, 0X278);
    // 0x805744F8: jal         0x80067818
    // 0x805744FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x805744FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
L_80574500:
    // 0x80574500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80574504:
    // 0x80574504: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80574508: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8057450C: jr          $ra
    // 0x80574510: nop

    return;
    // 0x80574510: nop

;}
RECOMP_FUNC void func_8052D9F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052D9F4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8052D9F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8052D9FC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8052DA00: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8052DA04: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8052DA08: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052DA0C: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8052DA10: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8052DA14: lw          $t6, 0xF00($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XF00);
    // 0x8052DA18: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8052DA1C: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x8052DA20: jal         0x8004700C
    // 0x8052DA24: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8052DA24: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    after_0:
    // 0x8052DA28: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8052DA2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8052DA30: jal         0x8052C648
    // 0x8052DA34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8052C648(rdram, ctx);
        goto after_1;
    // 0x8052DA34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8052DA38: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8052DA3C: lwc1        $f0, 0x3C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8052DA40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8052DA44: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8052DA48: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8052DA4C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8052DA50: lwc1        $f0, 0x40($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8052DA54: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8052DA58: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8052DA5C: jal         0x8052D7C8
    // 0x8052DA60: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    func_8052D7C8(rdram, ctx);
        goto after_2;
    // 0x8052DA60: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8052DA64: lwc1        $f4, 0xC4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8052DA68: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8052DA6C: jal         0x80066E88
    // 0x8052DA70: swc1        $f4, 0xF1C($s0)
    MEM_W(0XF1C, ctx->r16) = ctx->f4.u32l;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x8052DA70: swc1        $f4, 0xF1C($s0)
    MEM_W(0XF1C, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x8052DA74: lwc1        $f6, 0xF14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF14);
    // 0x8052DA78: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8052DA7C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8052DA80: jal         0x80066DE4
    // 0x8052DA84: swc1        $f8, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f8.u32l;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x8052DA84: swc1        $f8, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f8.u32l;
    after_4:
    // 0x8052DA88: lwc1        $f16, 0xF14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF14);
    // 0x8052DA8C: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8052DA90: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8052DA94: lwc1        $f4, 0xC4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8052DA98: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8052DA9C: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x8052DAA0: nop

    // 0x8052DAA4: bc1f        L_8052DAC0
    if (!c1cs) {
        // 0x8052DAA8: swc1        $f18, 0xC8($s1)
        MEM_W(0XC8, ctx->r17) = ctx->f18.u32l;
            goto L_8052DAC0;
    }
    // 0x8052DAA8: swc1        $f18, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f18.u32l;
    // 0x8052DAAC: lwc1        $f6, 0xC8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x8052DAB0: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
    // 0x8052DAB4: nop

    // 0x8052DAB8: bc1tl       L_8052DAE0
    if (c1cs) {
        // 0x8052DABC: lw          $a1, 0x30($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X30);
            goto L_8052DAE0;
    }
    goto skip_0;
    // 0x8052DABC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    skip_0:
L_8052DAC0:
    // 0x8052DAC0: lw          $v0, 0xF00($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF00);
    // 0x8052DAC4: addiu       $t0, $zero, 0x1DF
    ctx->r8 = ADD32(0, 0X1DF);
    // 0x8052DAC8: beq         $v0, $zero, L_8052DAD8
    if (ctx->r2 == 0) {
        // 0x8052DACC: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8052DAD8;
    }
    // 0x8052DACC: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8052DAD0: b           L_8052DADC
    // 0x8052DAD4: sw          $t9, 0xF00($s0)
    MEM_W(0XF00, ctx->r16) = ctx->r25;
        goto L_8052DADC;
    // 0x8052DAD4: sw          $t9, 0xF00($s0)
    MEM_W(0XF00, ctx->r16) = ctx->r25;
L_8052DAD8:
    // 0x8052DAD8: sw          $t0, 0xF00($s0)
    MEM_W(0XF00, ctx->r16) = ctx->r8;
L_8052DADC:
    // 0x8052DADC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_8052DAE0:
    // 0x8052DAE0: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8052DAE4: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8052DAE8: beql        $a1, $zero, L_8052DB18
    if (ctx->r5 == 0) {
        // 0x8052DAEC: neg.s       $f12, $f12
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
            goto L_8052DB18;
    }
    goto skip_1;
    // 0x8052DAEC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    skip_1:
    // 0x8052DAF0: jal         0x80047AB8
    // 0x8052DAF4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_80047AB8(rdram, ctx);
        goto after_5;
    // 0x8052DAF4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_5:
    // 0x8052DAF8: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8052DAFC: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8052DB00: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8052DB04: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8052DB08: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8052DB0C: b           L_8052DB1C
    // 0x8052DB10: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
        goto L_8052DB1C;
    // 0x8052DB10: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8052DB14: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_8052DB18:
    // 0x8052DB18: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_8052DB1C:
    // 0x8052DB1C: jal         0x80067114
    // 0x8052DB20: nop

    func_80067114(rdram, ctx);
        goto after_6;
    // 0x8052DB20: nop

    after_6:
    // 0x8052DB24: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8052DB28: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8052DB2C: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8052DB30: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8052DB34: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8052DB38: swc1        $f2, 0xF10($s0)
    MEM_W(0XF10, ctx->r16) = ctx->f2.u32l;
    // 0x8052DB3C: bc1fl       L_8052DB80
    if (!c1cs) {
        // 0x8052DB40: sub.s       $f16, $f2, $f20
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f20.fl;
            goto L_8052DB80;
    }
    goto skip_2;
    // 0x8052DB40: sub.s       $f16, $f2, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f20.fl;
    skip_2:
    // 0x8052DB44: sub.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x8052DB48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052DB4C: lui         $at, 0x3F20
    ctx->r1 = S32(0X3F20 << 16);
    // 0x8052DB50: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8052DB54: nop

    // 0x8052DB58: bc1fl       L_8052DB74
    if (!c1cs) {
        // 0x8052DB5C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8052DB74;
    }
    goto skip_3;
    // 0x8052DB5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_3:
    // 0x8052DB60: lui         $at, 0xBF20
    ctx->r1 = S32(0XBF20 << 16);
    // 0x8052DB64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052DB68: b           L_8052DBB0
    // 0x8052DB6C: swc1        $f8, 0xF0C($s0)
    MEM_W(0XF0C, ctx->r16) = ctx->f8.u32l;
        goto L_8052DBB0;
    // 0x8052DB6C: swc1        $f8, 0xF0C($s0)
    MEM_W(0XF0C, ctx->r16) = ctx->f8.u32l;
    // 0x8052DB70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8052DB74:
    // 0x8052DB74: b           L_8052DBB0
    // 0x8052DB78: swc1        $f10, 0xF0C($s0)
    MEM_W(0XF0C, ctx->r16) = ctx->f10.u32l;
        goto L_8052DBB0;
    // 0x8052DB78: swc1        $f10, 0xF0C($s0)
    MEM_W(0XF0C, ctx->r16) = ctx->f10.u32l;
    // 0x8052DB7C: sub.s       $f16, $f2, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f20.fl;
L_8052DB80:
    // 0x8052DB80: lui         $at, 0xBF20
    ctx->r1 = S32(0XBF20 << 16);
    // 0x8052DB84: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x8052DB88: nop

    // 0x8052DB8C: bc1fl       L_8052DBA8
    if (!c1cs) {
        // 0x8052DB90: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8052DBA8;
    }
    goto skip_4;
    // 0x8052DB90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_4:
    // 0x8052DB94: lui         $at, 0x3F20
    ctx->r1 = S32(0X3F20 << 16);
    // 0x8052DB98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8052DB9C: b           L_8052DBB0
    // 0x8052DBA0: swc1        $f18, 0xF0C($s0)
    MEM_W(0XF0C, ctx->r16) = ctx->f18.u32l;
        goto L_8052DBB0;
    // 0x8052DBA0: swc1        $f18, 0xF0C($s0)
    MEM_W(0XF0C, ctx->r16) = ctx->f18.u32l;
    // 0x8052DBA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8052DBA8:
    // 0x8052DBA8: nop

    // 0x8052DBAC: swc1        $f4, 0xF0C($s0)
    MEM_W(0XF0C, ctx->r16) = ctx->f4.u32l;
L_8052DBB0:
    // 0x8052DBB0: lwc1        $f6, 0xF0C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF0C);
    // 0x8052DBB4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8052DBB8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8052DBBC: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x8052DBC0: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x8052DBC4: nop

    // 0x8052DBC8: bc1fl       L_8052DBE0
    if (!c1cs) {
        // 0x8052DBCC: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8052DBE0;
    }
    goto skip_5;
    // 0x8052DBCC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_5:
    // 0x8052DBD0: sub.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8052DBD4: b           L_8052DC04
    // 0x8052DBD8: swc1        $f8, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f8.u32l;
        goto L_8052DC04;
    // 0x8052DBD8: swc1        $f8, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f8.u32l;
    // 0x8052DBDC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8052DBE0:
    // 0x8052DBE0: nop

    // 0x8052DBE4: c.lt.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
    // 0x8052DBE8: nop

    // 0x8052DBEC: bc1fl       L_8052DC04
    if (!c1cs) {
        // 0x8052DBF0: swc1        $f20, 0x50($s1)
        MEM_W(0X50, ctx->r17) = ctx->f20.u32l;
            goto L_8052DC04;
    }
    goto skip_6;
    // 0x8052DBF0: swc1        $f20, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f20.u32l;
    skip_6:
    // 0x8052DBF4: add.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8052DBF8: b           L_8052DC04
    // 0x8052DBFC: swc1        $f16, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f16.u32l;
        goto L_8052DC04;
    // 0x8052DBFC: swc1        $f16, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f16.u32l;
    // 0x8052DC00: swc1        $f20, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f20.u32l;
L_8052DC04:
    // 0x8052DC04: lw          $t1, 0xF20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XF20);
    // 0x8052DC08: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(330, 0X16F8) << 16);
    // 0x8052DC0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8052DC10: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8052DC14: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x8052DC18: lw          $t9, -0x2338($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(330, 0X16F8));
    // 0x8052DC1C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8052DC20: jalr        $t9
    // 0x8052DC24: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8052DC24: nop

    after_7:
    // 0x8052DC28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8052DC2C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8052DC30: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8052DC34: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8052DC38: jr          $ra
    // 0x8052DC3C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8052DC3C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_804CECC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CECC8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CECCC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804CECD0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804CECD4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804CECD8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804CECDC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804CECE0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x804CECE4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804CECE8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804CECEC: nop

    // 0x804CECF0: bc1fl       L_804CED20
    if (!c1cs) {
        // 0x804CECF4: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_804CED20;
    }
    goto skip_0;
    // 0x804CECF4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x804CECF8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804CECFC: nop

    // 0x804CED00: add.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f12.fl;
L_804CED04:
    // 0x804CED04: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x804CED08: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804CED0C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804CED10: nop

    // 0x804CED14: bc1tl       L_804CED04
    if (c1cs) {
        // 0x804CED18: add.s       $f10, $f0, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f12.fl;
            goto L_804CED04;
    }
    goto skip_1;
    // 0x804CED18: add.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f12.fl;
    skip_1:
    // 0x804CED1C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_804CED20:
    // 0x804CED20: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804CED24: nop

    // 0x804CED28: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804CED2C: nop

    // 0x804CED30: bc1f        L_804CED54
    if (!c1cs) {
        // 0x804CED34: nop
    
            goto L_804CED54;
    }
    // 0x804CED34: nop

    // 0x804CED38: sub.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
L_804CED3C:
    // 0x804CED3C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x804CED40: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804CED44: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804CED48: nop

    // 0x804CED4C: bc1tl       L_804CED3C
    if (c1cs) {
        // 0x804CED50: sub.s       $f16, $f0, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_804CED3C;
    }
    goto skip_2;
    // 0x804CED50: sub.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
    skip_2:
L_804CED54:
    // 0x804CED54: jr          $ra
    // 0x804CED58: nop

    return;
    // 0x804CED58: nop

;}
RECOMP_FUNC void func_800568E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800568E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800568E4: beq         $a0, $zero, L_800568F4
    if (ctx->r4 == 0) {
        // 0x800568E8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800568F4;
    }
    // 0x800568E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800568EC: jal         0x80064E84
    // 0x800568F0: nop

    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x800568F0: nop

    after_0:
L_800568F4:
    // 0x800568F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800568F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800568FC: jr          $ra
    // 0x80056900: nop

    return;
    // 0x80056900: nop

;}
RECOMP_FUNC void func_804C9940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C9940: lui         $t7, 0x804D
    ctx->r15 = S32(RELOC_HI16(228, 0X470) << 16);
    // 0x804C9944: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804C9948: addiu       $t7, $t7, -0x6850
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(228, 0X470));
    // 0x804C994C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804C9950: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x804C9954: jr          $ra
    // 0x804C9958: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x804C9958: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_8002FFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FFDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FFE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FFE4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FFE8: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FFEC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8002FFF0: jal         0x8002F678
    // 0x8002FFF4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FFF4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FFF8: beq         $v0, $zero, L_8003000C
    if (ctx->r2 == 0) {
        // 0x8002FFFC: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8003000C;
    }
    // 0x8002FFFC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80030000: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x80030004: addiu       $t6, $t6, -0x3284
    ctx->r14 = ADD32(ctx->r14, -0X3284);
    // 0x80030008: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8003000C:
    // 0x8003000C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030010: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80030014: jr          $ra
    // 0x80030018: nop

    return;
    // 0x80030018: nop

;}
RECOMP_FUNC void func_8046AB28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046AB28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8046AB2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046AB30: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046AB34: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8046AB38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8046AB3C: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8046AB40: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8046AB44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8046AB48: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8046AB4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8046AB50: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8046AB54: addiu       $v1, $a3, 0x4
    ctx->r3 = ADD32(ctx->r7, 0X4);
    // 0x8046AB58: bc1f        L_8046ABFC
    if (!c1cs) {
        // 0x8046AB5C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8046ABFC;
    }
    // 0x8046AB5C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8046AB60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8046AB64: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2984) << 16);
    // 0x8046AB68: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8046AB6C: nop

    // 0x8046AB70: bc1f        L_8046ABFC
    if (!c1cs) {
        // 0x8046AB74: nop
    
            goto L_8046ABFC;
    }
    // 0x8046AB74: nop

    // 0x8046AB78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8046AB7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8046AB80: addiu       $v1, $a3, 0x4
    ctx->r3 = ADD32(ctx->r7, 0X4);
    // 0x8046AB84: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8046AB88: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
L_8046AB8C:
    // 0x8046AB8C: lwc1        $f8, 0x4C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x8046AB90: lwc1        $f10, 0x4C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x8046AB94: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8046AB98: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8046AB9C: nop

    // 0x8046ABA0: bc1fl       L_8046ABB4
    if (!c1cs) {
        // 0x8046ABA4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8046ABB4;
    }
    goto skip_0;
    // 0x8046ABA4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8046ABA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8046ABAC: addu        $a0, $a3, $t6
    ctx->r4 = ADD32(ctx->r7, ctx->r14);
    // 0x8046ABB0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8046ABB4:
    // 0x8046ABB4: bne         $v0, $a2, L_8046AB8C
    if (ctx->r2 != ctx->r6) {
        // 0x8046ABB8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8046AB8C;
    }
    // 0x8046ABB8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8046ABBC: lwc1        $f16, 0x1C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8046ABC0: lwc1        $f18, -0x3F3C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2984));
    // 0x8046ABC4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8046ABC8: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x8046ABCC: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8046ABD0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8046ABD4: jal         0x804697D8
    // 0x8046ABD8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_804697D8(rdram, ctx);
        goto after_0;
    // 0x8046ABD8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8046ABDC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8046ABE0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8046ABE4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8046ABE8: bgez        $a1, L_8046ABF4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8046ABEC: swc1        $f0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
            goto L_8046ABF4;
    }
    // 0x8046ABEC: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x8046ABF0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_8046ABF4:
    // 0x8046ABF4: b           L_8046AC5C
    // 0x8046ABF8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8046AC5C;
    // 0x8046ABF8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8046ABFC:
    // 0x8046ABFC: lwc1        $f6, 0x4C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x8046AC00: lwc1        $f8, 0x4C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x8046AC04: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8046AC08: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8046AC0C: nop

    // 0x8046AC10: bc1fl       L_8046AC24
    if (!c1cs) {
        // 0x8046AC14: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8046AC24;
    }
    goto skip_1;
    // 0x8046AC14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x8046AC18: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8046AC1C: addu        $a0, $a3, $t7
    ctx->r4 = ADD32(ctx->r7, ctx->r15);
    // 0x8046AC20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8046AC24:
    // 0x8046AC24: bne         $v0, $a2, L_8046ABFC
    if (ctx->r2 != ctx->r6) {
        // 0x8046AC28: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8046ABFC;
    }
    // 0x8046AC28: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8046AC2C: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2988) << 16);
    // 0x8046AC30: lwc1        $f16, -0x3F38($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2988));
    // 0x8046AC34: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8046AC38: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8046AC3C: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x8046AC40: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8046AC44: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8046AC48: jal         0x804697D8
    // 0x8046AC4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_804697D8(rdram, ctx);
        goto after_1;
    // 0x8046AC4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8046AC50: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8046AC54: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8046AC58: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_8046AC5C:
    // 0x8046AC5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046AC60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8046AC64: jr          $ra
    // 0x8046AC68: nop

    return;
    // 0x8046AC68: nop

;}
RECOMP_FUNC void func_807ADA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ADA60: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807ADA64: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807ADA68: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807ADA6C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807ADA70: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807ADA74: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x807ADA78: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807ADA7C: lui         $t1, 0x807B
    ctx->r9 = S32(RELOC_HI16(859, 0X2634) << 16);
    // 0x807ADA80: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807ADA84: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807ADA88: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807ADA8C: lw          $t1, -0x136C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(859, 0X2634));
    // 0x807ADA90: jr          $ra
    // 0x807ADA94: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807ADA94: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804481E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804481E0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804481E4: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x804481E8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x804481EC: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x804481F0: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x804481F4: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x804481F8: lw          $t7, 0x6A2C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A2C);
    // 0x804481FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80448200: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x80448204: bne         $t7, $at, L_80448244
    if (ctx->r15 != ctx->r1) {
        // 0x80448208: addu        $t2, $t2, $v1
        ctx->r10 = ADD32(ctx->r10, ctx->r3);
            goto L_80448244;
    }
    // 0x80448208: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x8044820C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448210: ori         $at, $at, 0x6A38
    ctx->r1 = ctx->r1 | 0X6A38;
    // 0x80448214: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80448218: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8044821C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448220: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80448224: subu        $t9, $t8, $a2
    ctx->r25 = SUB32(ctx->r24, ctx->r6);
    // 0x80448228: bgtz        $t9, L_80448278
    if (SIGNED(ctx->r25) > 0) {
        // 0x8044822C: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_80448278;
    }
    // 0x8044822C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80448230: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448234: sw          $t1, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r9;
    // 0x80448238: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8044823C: jr          $ra
    // 0x80448240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80448240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80448244:
    // 0x80448244: lw          $t2, 0x6A2C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6A2C);
    // 0x80448248: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8044824C: bne         $t2, $at, L_80448278
    if (ctx->r10 != ctx->r1) {
        // 0x80448250: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80448278;
    }
    // 0x80448250: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448254: ori         $at, $at, 0x6A38
    ctx->r1 = ctx->r1 | 0X6A38;
    // 0x80448258: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044825C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80448260: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80448264: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x80448268: slti        $at, $t4, 0x3C0
    ctx->r1 = SIGNED(ctx->r12) < 0X3C0 ? 1 : 0;
    // 0x8044826C: bne         $at, $zero, L_80448278
    if (ctx->r1 != 0) {
        // 0x80448270: sw          $t4, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r12;
            goto L_80448278;
    }
    // 0x80448270: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80448274: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80448278:
    // 0x80448278: jr          $ra
    // 0x8044827C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8044827C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80475B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475B10: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475B14: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475B18: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80475B1C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475B20: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475B24: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475B28: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80475B2C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475B30: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475B34: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475B38: jr          $ra
    // 0x80475B3C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80475B3C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8041E62C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041E62C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8041E630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041E634: jal         0x8004700C
    // 0x8041E638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8041E638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8041E63C: beq         $v0, $zero, L_8041E684
    if (ctx->r2 == 0) {
        // 0x8041E640: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8041E684;
    }
    // 0x8041E640: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8041E644: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8041E648: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8041E64C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8041E650: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8041E654: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8041E658: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8041E65C: nop

    // 0x8041E660: bc1fl       L_8041E674
    if (!c1cs) {
        // 0x8041E664: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8041E674;
    }
    goto skip_0;
    // 0x8041E664: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x8041E668: b           L_8041E684
    // 0x8041E66C: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
        goto L_8041E684;
    // 0x8041E66C: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    // 0x8041E670: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8041E674:
    // 0x8041E674: nop

    // 0x8041E678: bc1fl       L_8041E688
    if (!c1cs) {
        // 0x8041E67C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8041E688;
    }
    goto skip_1;
    // 0x8041E67C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8041E680: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
L_8041E684:
    // 0x8041E684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8041E688:
    // 0x8041E688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8041E68C: jr          $ra
    // 0x8041E690: nop

    return;
    // 0x8041E690: nop

;}
RECOMP_FUNC void func_8005AB10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AB10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005AB14: beq         $a0, $zero, L_8005AB2C
    if (ctx->r4 == 0) {
        // 0x8005AB18: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8005AB2C;
    }
    // 0x8005AB18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005AB1C: jal         0x8005B508
    // 0x8005AB20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005B508(rdram, ctx);
        goto after_0;
    // 0x8005AB20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005AB24: jal         0x80064E84
    // 0x8005AB28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x8005AB28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_8005AB2C:
    // 0x8005AB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005AB30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005AB34: jr          $ra
    // 0x8005AB38: nop

    return;
    // 0x8005AB38: nop

;}
RECOMP_FUNC void func_80741B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80741B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80741B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80741B78: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x80741B7C: beql        $t6, $zero, L_80741BCC
    if (ctx->r14 == 0) {
        // 0x80741B80: lw          $t2, 0x1E0($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X1E0);
            goto L_80741BCC;
    }
    goto skip_0;
    // 0x80741B80: lw          $t2, 0x1E0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1E0);
    skip_0:
    // 0x80741B84: lw          $t7, 0x1E0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E0);
    // 0x80741B88: addiu       $t8, $t7, -0x3
    ctx->r24 = ADD32(ctx->r15, -0X3);
    // 0x80741B8C: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80741B90: beq         $at, $zero, L_80741BC0
    if (ctx->r1 == 0) {
        // 0x80741B94: sw          $t8, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r24;
            goto L_80741BC0;
    }
    // 0x80741B94: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x80741B98: lw          $t1, 0x1E4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1E4);
    // 0x80741B9C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80741BA0: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x80741BA4: bgtz        $t1, L_80741BC0
    if (SIGNED(ctx->r9) > 0) {
        // 0x80741BA8: sw          $t0, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r8;
            goto L_80741BC0;
    }
    // 0x80741BA8: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
    // 0x80741BAC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80741BB0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80741BB4: jal         0x80741E44
    // 0x80741BB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80741E44(rdram, ctx);
        goto after_0;
    // 0x80741BB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80741BBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80741BC0:
    // 0x80741BC0: b           L_80741BF8
    // 0x80741BC4: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
        goto L_80741BF8;
    // 0x80741BC4: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80741BC8: lw          $t2, 0x1E0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1E0);
L_80741BCC:
    // 0x80741BCC: lw          $v1, 0x1E4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E4);
    // 0x80741BD0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80741BD4: addiu       $t3, $t2, 0x3
    ctx->r11 = ADD32(ctx->r10, 0X3);
    // 0x80741BD8: slt         $at, $t3, $v1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80741BDC: sw          $t3, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r11;
    // 0x80741BE0: bne         $at, $zero, L_80741BF8
    if (ctx->r1 != 0) {
        // 0x80741BE4: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_80741BF8;
    }
    // 0x80741BE4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80741BE8: addiu       $t4, $v1, -0x5
    ctx->r12 = ADD32(ctx->r3, -0X5);
    // 0x80741BEC: sw          $t4, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = ctx->r12;
    // 0x80741BF0: sw          $t5, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r13;
    // 0x80741BF4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80741BF8:
    // 0x80741BF8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80741BFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80741C00: jal         0x80066DE4
    // 0x80741C04: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80741C04: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x80741C08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80741C0C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80741C10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80741C14: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80741C18: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80741C1C: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x80741C20: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
    // 0x80741C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80741C28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80741C2C: jr          $ra
    // 0x80741C30: nop

    return;
    // 0x80741C30: nop

;}
RECOMP_FUNC void func_80446C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446C90: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446C94: addiu       $t6, $zero, 0x744
    ctx->r14 = ADD32(0, 0X744);
    // 0x80446C98: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446C9C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80446CA0: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x80446CA4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446CA8: jr          $ra
    // 0x80446CAC: sw          $t7, 0x6CC8($at)
    MEM_W(0X6CC8, ctx->r1) = ctx->r15;
    return;
    // 0x80446CAC: sw          $t7, 0x6CC8($at)
    MEM_W(0X6CC8, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_8044B2CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B2CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044B2D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B2D4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8044B2D8: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8044B2DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044B2E0: jal         0x8044A558
    // 0x8044B2E4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8044A558(rdram, ctx);
        goto after_0;
    // 0x8044B2E4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x8044B2E8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B2EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8044B2F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044B2F4: bne         $v0, $zero, L_8044B30C
    if (ctx->r2 != 0) {
        // 0x8044B2F8: nop
    
            goto L_8044B30C;
    }
    // 0x8044B2F8: nop

    // 0x8044B2FC: jal         0x80446988
    // 0x8044B300: nop

    func_80446988(rdram, ctx);
        goto after_1;
    // 0x8044B300: nop

    after_1:
    // 0x8044B304: b           L_8044B330
    // 0x8044B308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044B330;
    // 0x8044B308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B30C:
    // 0x8044B30C: bne         $v0, $at, L_8044B324
    if (ctx->r2 != ctx->r1) {
        // 0x8044B310: nop
    
            goto L_8044B324;
    }
    // 0x8044B310: nop

    // 0x8044B314: jal         0x804469C0
    // 0x8044B318: nop

    func_804469C0(rdram, ctx);
        goto after_2;
    // 0x8044B318: nop

    after_2:
    // 0x8044B31C: b           L_8044B330
    // 0x8044B320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044B330;
    // 0x8044B320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B324:
    // 0x8044B324: jal         0x804469FC
    // 0x8044B328: nop

    func_804469FC(rdram, ctx);
        goto after_3;
    // 0x8044B328: nop

    after_3:
    // 0x8044B32C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B330:
    // 0x8044B330: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044B334: jr          $ra
    // 0x8044B338: nop

    return;
    // 0x8044B338: nop

;}
RECOMP_FUNC void func_805A8DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A8DC8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x805A8DCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A8DD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A8DD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A8DD8: jal         0x805A8F90
    // 0x805A8DDC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    func_805A8F90(rdram, ctx);
        goto after_0;
    // 0x805A8DDC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x805A8DE0: beq         $v0, $zero, L_805A8F38
    if (ctx->r2 == 0) {
        // 0x805A8DE4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805A8F38;
    }
    // 0x805A8DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A8DE8: jal         0x805A905C
    // 0x805A8DEC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_805A905C(rdram, ctx);
        goto after_1;
    // 0x805A8DEC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_1:
    // 0x805A8DF0: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x805A8DF4: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x805A8DF8: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x805A8DFC: lui         $t7, 0x805B
    ctx->r15 = S32(RELOC_HI16(429, 0X1414) << 16);
    // 0x805A8E00: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x805A8E04: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x805A8E08: addiu       $t7, $t7, -0x5EEC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(429, 0X1414));
    // 0x805A8E0C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805A8E10: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x805A8E14: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x805A8E18: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x805A8E1C: lui         $a2, 0x805B
    ctx->r6 = S32(RELOC_HI16(429, 0X141C) << 16);
    // 0x805A8E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A8E24: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x805A8E28: lbu         $a2, -0x5EE4($a2)
    ctx->r6 = MEM_BU(ctx->r6, (int16_t)RELOC_LO16(429, 0X141C));
    // 0x805A8E2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A8E30: jal         0x805A9768
    // 0x805A8E34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805A9768(rdram, ctx);
        goto after_2;
    // 0x805A8E34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x805A8E38: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x805A8E3C: lui         $t0, 0x805B
    ctx->r8 = S32(RELOC_HI16(429, 0X468) << 16);
    // 0x805A8E40: addiu       $t0, $t0, -0x6E98
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(429, 0X468));
    // 0x805A8E44: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
    // 0x805A8E48: lhu         $t2, 0xC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XC);
    // 0x805A8E4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805A8E50: addiu       $t3, $t2, -0x418E
    ctx->r11 = ADD32(ctx->r10, -0X418E);
    // 0x805A8E54: sltiu       $at, $t3, 0x6
    ctx->r1 = ctx->r11 < 0X6 ? 1 : 0;
    // 0x805A8E58: beq         $at, $zero, L_805A8EA4
    if (ctx->r1 == 0) {
        // 0x805A8E5C: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_805A8EA4;
    }
    // 0x805A8E5C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x805A8E60: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(429, 0X1478) << 16);
    // 0x805A8E64: addu        $at, $at, $t3
    gpr jr_addend_805A8E6C = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x805A8E68: lw          $t3, -0x5E88($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(429, 0X1478));
    // 0x805A8E6C: jr          $t3
    // 0x805A8E70: nop

    switch (jr_addend_805A8E6C >> 2) {
        case 0: goto L_805A8E74; break;
        case 1: goto L_805A8E7C; break;
        case 2: goto L_805A8E84; break;
        case 3: goto L_805A8E8C; break;
        case 4: goto L_805A8E94; break;
        case 5: goto L_805A8E9C; break;
        default: switch_error(__func__, 0x805A8E6C, 0x805AA178);
    }
    // 0x805A8E70: nop

L_805A8E74:
    // 0x805A8E74: b           L_805A8EA4
    // 0x805A8E78: addiu       $v0, $zero, 0x4030
    ctx->r2 = ADD32(0, 0X4030);
        goto L_805A8EA4;
    // 0x805A8E78: addiu       $v0, $zero, 0x4030
    ctx->r2 = ADD32(0, 0X4030);
L_805A8E7C:
    // 0x805A8E7C: b           L_805A8EA4
    // 0x805A8E80: addiu       $v0, $zero, 0x4031
    ctx->r2 = ADD32(0, 0X4031);
        goto L_805A8EA4;
    // 0x805A8E80: addiu       $v0, $zero, 0x4031
    ctx->r2 = ADD32(0, 0X4031);
L_805A8E84:
    // 0x805A8E84: b           L_805A8EA4
    // 0x805A8E88: addiu       $v0, $zero, 0x4032
    ctx->r2 = ADD32(0, 0X4032);
        goto L_805A8EA4;
    // 0x805A8E88: addiu       $v0, $zero, 0x4032
    ctx->r2 = ADD32(0, 0X4032);
L_805A8E8C:
    // 0x805A8E8C: b           L_805A8EA4
    // 0x805A8E90: addiu       $v0, $zero, 0x4033
    ctx->r2 = ADD32(0, 0X4033);
        goto L_805A8EA4;
    // 0x805A8E90: addiu       $v0, $zero, 0x4033
    ctx->r2 = ADD32(0, 0X4033);
L_805A8E94:
    // 0x805A8E94: b           L_805A8EA4
    // 0x805A8E98: addiu       $v0, $zero, 0x4034
    ctx->r2 = ADD32(0, 0X4034);
        goto L_805A8EA4;
    // 0x805A8E98: addiu       $v0, $zero, 0x4034
    ctx->r2 = ADD32(0, 0X4034);
L_805A8E9C:
    // 0x805A8E9C: b           L_805A8EA4
    // 0x805A8EA0: addiu       $v0, $zero, 0x4035
    ctx->r2 = ADD32(0, 0X4035);
        goto L_805A8EA4;
    // 0x805A8EA0: addiu       $v0, $zero, 0x4035
    ctx->r2 = ADD32(0, 0X4035);
L_805A8EA4:
    // 0x805A8EA4: beq         $v0, $zero, L_805A8F40
    if (ctx->r2 == 0) {
        // 0x805A8EA8: sh          $v0, 0x28($sp)
        MEM_H(0X28, ctx->r29) = ctx->r2;
            goto L_805A8F40;
    }
    // 0x805A8EA8: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // 0x805A8EAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A8EB0: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(429, 0X1490) << 16);
    // 0x805A8EB4: lwc1        $f4, -0x5E70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(429, 0X1490));
    // 0x805A8EB8: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x805A8EBC: lw          $t5, -0x76F8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X76F8);
    // 0x805A8EC0: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x805A8EC4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x805A8EC8: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x805A8ECC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x805A8ED0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x805A8ED4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x805A8ED8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x805A8EDC: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x805A8EE0: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x805A8EE4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x805A8EE8: lw          $t9, 0x54($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X54);
    // 0x805A8EEC: jalr        $t9
    // 0x805A8EF0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x805A8EF0: nop

    after_3:
    // 0x805A8EF4: beq         $v0, $zero, L_805A8F28
    if (ctx->r2 == 0) {
        // 0x805A8EF8: nop
    
            goto L_805A8F28;
    }
    // 0x805A8EF8: nop

    // 0x805A8EFC: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x805A8F00: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x805A8F04: sw          $v0, 0x64($t7)
    MEM_W(0X64, ctx->r15) = ctx->r2;
    // 0x805A8F08: sb          $t8, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r24;
    // 0x805A8F0C: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x805A8F10: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x805A8F14: lwc1        $f8, 0x70($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X70);
    // 0x805A8F18: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x805A8F1C: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x805A8F20: b           L_805A8F40
    // 0x805A8F24: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
        goto L_805A8F40;
    // 0x805A8F24: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_805A8F28:
    // 0x805A8F28: jal         0x800445A4
    // 0x805A8F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x805A8F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805A8F30: b           L_805A8F44
    // 0x805A8F34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A8F44;
    // 0x805A8F34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A8F38:
    // 0x805A8F38: jal         0x800445A4
    // 0x805A8F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x805A8F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_805A8F40:
    // 0x805A8F40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A8F44:
    // 0x805A8F44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A8F48: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x805A8F4C: jr          $ra
    // 0x805A8F50: nop

    return;
    // 0x805A8F50: nop

;}
RECOMP_FUNC void func_807C3E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3E60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C3E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C3E68: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807C3E6C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x807C3E70: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x807C3E74: beq         $v0, $zero, L_807C3E88
    if (ctx->r2 == 0) {
        // 0x807C3E78: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_807C3E88;
    }
    // 0x807C3E78: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807C3E7C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807C3E80: b           L_807C3EA8
    // 0x807C3E84: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_807C3EA8;
    // 0x807C3E84: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_807C3E88:
    // 0x807C3E88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x807C3E8C: jal         0x8006E0FC
    // 0x807C3E90: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8006E0FC(rdram, ctx);
        goto after_0;
    // 0x807C3E90: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x807C3E94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807C3E98: jal         0x800461F4
    // 0x807C3E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800461F4(rdram, ctx);
        goto after_1;
    // 0x807C3E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x807C3EA0: jal         0x800447C8
    // 0x807C3EA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x807C3EA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_807C3EA8:
    // 0x807C3EA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C3EAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C3EB0: jr          $ra
    // 0x807C3EB4: nop

    return;
    // 0x807C3EB4: nop

;}
RECOMP_FUNC void func_8003FFD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FFD8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8003FFDC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003FFE0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8003FFE4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8003FFE8: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8003FFEC: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8003FFF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003FFF4: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x8003FFF8: lbu         $t7, 0x12C8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X12C8);
    // 0x8003FFFC: sb          $t7, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r15;
    // 0x80040000: lw          $s1, 0x174($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X174);
    // 0x80040004: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80040008: jal         0x80065490
    // 0x8004000C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x8004000C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_0:
    // 0x80040010: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80040014: jal         0x80065490
    // 0x80040018: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x80040018: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    after_1:
    // 0x8004001C: lbu         $a2, 0x53($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X53);
    // 0x80040020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80040024: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80040028: slti        $at, $a2, 0x6
    ctx->r1 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
    // 0x8004002C: bne         $at, $zero, L_80040060
    if (ctx->r1 != 0) {
        // 0x80040030: addiu       $a3, $sp, 0x44
        ctx->r7 = ADD32(ctx->r29, 0X44);
            goto L_80040060;
    }
    // 0x80040030: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    // 0x80040034: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80040038: addiu       $t8, $sp, 0x38
    ctx->r24 = ADD32(ctx->r29, 0X38);
    // 0x8004003C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80040040: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80040044: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80040048: jal         0x8003F894
    // 0x8004004C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_8003F894(rdram, ctx);
        goto after_2;
    // 0x8004004C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_2:
    // 0x80040050: bnel        $v0, $zero, L_800400A4
    if (ctx->r2 != 0) {
        // 0x80040054: lw          $t1, 0x180($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X180);
            goto L_800400A4;
    }
    goto skip_0;
    // 0x80040054: lw          $t1, 0x180($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X180);
    skip_0:
    // 0x80040058: b           L_8004011C
    // 0x8004005C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8004011C;
    // 0x8004005C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80040060:
    // 0x80040060: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x80040064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80040068: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    // 0x8004006C: jalr        $t9
    // 0x80040070: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80040070: nop

    after_3:
    // 0x80040074: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80040078: addiu       $a3, $a3, -0x1A14
    ctx->r7 = ADD32(ctx->r7, -0X1A14);
    // 0x8004007C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80040080: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80040084: jal         0x8003E658
    // 0x80040088: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8003E658(rdram, ctx);
        goto after_4;
    // 0x80040088: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8004008C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80040090: addiu       $a2, $a2, -0x7C48
    ctx->r6 = ADD32(ctx->r6, -0X7C48);
    // 0x80040094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80040098: jal         0x8003F14C
    // 0x8004009C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_8003F14C(rdram, ctx);
        goto after_5;
    // 0x8004009C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_5:
    // 0x800400A0: lw          $t1, 0x180($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X180);
L_800400A4:
    // 0x800400A4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800400A8: beq         $t1, $zero, L_800400CC
    if (ctx->r9 == 0) {
        // 0x800400AC: nop
    
            goto L_800400CC;
    }
    // 0x800400AC: nop

    // 0x800400B0: jal         0x80048060
    // 0x800400B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048060(rdram, ctx);
        goto after_6;
    // 0x800400B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800400B8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800400BC: jal         0x80047F9C
    // 0x800400C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x800400C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800400C4: b           L_800400D8
    // 0x800400C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_800400D8;
    // 0x800400C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800400CC:
    // 0x800400CC: jal         0x80048114
    // 0x800400D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80048114(rdram, ctx);
        goto after_8;
    // 0x800400D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800400D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800400D8:
    // 0x800400D8: sb          $t2, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r10;
    // 0x800400DC: jal         0x8005FE48
    // 0x800400E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_9;
    // 0x800400E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800400E4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800400E8: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x800400EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800400F0: sh          $zero, 0x10($t3)
    MEM_H(0X10, ctx->r11) = 0;
    // 0x800400F4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800400F8: addiu       $t8, $t8, -0x7630
    ctx->r24 = ADD32(ctx->r24, -0X7630);
    // 0x800400FC: sh          $zero, 0x12($t4)
    MEM_H(0X12, ctx->r12) = 0;
    // 0x80040100: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80040104: sh          $zero, 0x14($t5)
    MEM_H(0X14, ctx->r13) = 0;
    // 0x80040108: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8004010C: sw          $zero, 0x44($t6)
    MEM_W(0X44, ctx->r14) = 0;
    // 0x80040110: sb          $t7, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r15;
    // 0x80040114: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x80040118: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8004011C:
    // 0x8004011C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80040120: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80040124: jr          $ra
    // 0x80040128: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80040128: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8070F668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070F668: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8070F66C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8070F670: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8070F674: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8070F678: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8070F67C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8070F680: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8070F684: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x8070F688: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8070F68C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8070F690: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8070F694: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8070F698: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8070F69C: beq         $t6, $zero, L_8070F71C
    if (ctx->r14 == 0) {
        // 0x8070F6A0: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8070F71C;
    }
    // 0x8070F6A0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8070F6A4: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070F6A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8070F6AC: beq         $a2, $zero, L_8070F6BC
    if (ctx->r6 == 0) {
        // 0x8070F6B0: sw          $t7, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r15;
            goto L_8070F6BC;
    }
    // 0x8070F6B0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8070F6B4: addiu       $s2, $a2, 0x9
    ctx->r18 = ADD32(ctx->r6, 0X9);
    // 0x8070F6B8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8070F6BC:
    // 0x8070F6BC: bltz        $v0, L_8070F714
    if (SIGNED(ctx->r2) < 0) {
        // 0x8070F6C0: sll         $s1, $v0, 2
        ctx->r17 = S32(ctx->r2 << 2);
            goto L_8070F714;
    }
    // 0x8070F6C0: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
    // 0x8070F6C4: addu        $s0, $a1, $s1
    ctx->r16 = ADD32(ctx->r5, ctx->r17);
L_8070F6C8:
    // 0x8070F6C8: bne         $s3, $zero, L_8070F6EC
    if (ctx->r19 != 0) {
        // 0x8070F6CC: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8070F6EC;
    }
    // 0x8070F6CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8070F6D0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8070F6D4: bne         $v1, $zero, L_8070F6E4
    if (ctx->r3 != 0) {
        // 0x8070F6D8: addiu       $v0, $v1, 0x10
        ctx->r2 = ADD32(ctx->r3, 0X10);
            goto L_8070F6E4;
    }
    // 0x8070F6D8: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8070F6DC: b           L_8070F6F4
    // 0x8070F6E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8070F6F4;
    // 0x8070F6E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8070F6E4:
    // 0x8070F6E4: b           L_8070F6F4
    // 0x8070F6E8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_8070F6F4;
    // 0x8070F6E8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8070F6EC:
    // 0x8070F6EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8070F6F0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
L_8070F6F4:
    // 0x8070F6F4: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x8070F6F8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8070F6FC: jal         0x8005C27C
    // 0x8070F700: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x8070F700: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_0:
    // 0x8070F704: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x8070F708: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    // 0x8070F70C: bgez        $s1, L_8070F6C8
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8070F710: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_8070F6C8;
    }
    // 0x8070F710: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_8070F714:
    // 0x8070F714: lw          $t9, 0x1F4($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X1F4);
    // 0x8070F718: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_8070F71C:
    // 0x8070F71C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8070F720: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8070F724: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8070F728: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8070F72C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8070F730: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8070F734: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8070F738: jr          $ra
    // 0x8070F73C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8070F73C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_804407B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804407B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804407BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804407C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804407C4: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x804407C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x804407CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804407D0: lbu         $t6, 0x30($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X30);
    // 0x804407D4: bne         $t6, $at, L_80440828
    if (ctx->r14 != ctx->r1) {
        // 0x804407D8: nop
    
            goto L_80440828;
    }
    // 0x804407D8: nop

    // 0x804407DC: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x804407E0: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x804407E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804407E8: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x804407EC: lwc1        $f6, 0x40($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X40);
    // 0x804407F0: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EC4) << 16);
    // 0x804407F4: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x804407F8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x804407FC: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x80440800: lwc1        $f16, 0x3DC4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EC4));
    // 0x80440804: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EC8) << 16);
    // 0x80440808: swc1        $f16, 0x1C24($t7)
    MEM_W(0X1C24, ctx->r15) = ctx->f16.u32l;
    // 0x8044080C: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x80440810: lwc1        $f18, 0x3DC8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EC8));
    // 0x80440814: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4ECC) << 16);
    // 0x80440818: swc1        $f18, 0x1C28($t8)
    MEM_W(0X1C28, ctx->r24) = ctx->f18.u32l;
    // 0x8044081C: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x80440820: lwc1        $f4, 0x3DCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4ECC));
    // 0x80440824: swc1        $f4, 0x1C2C($t9)
    MEM_W(0X1C2C, ctx->r25) = ctx->f4.u32l;
L_80440828:
    // 0x80440828: jal         0x804406D0
    // 0x8044082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804406D0(rdram, ctx);
        goto after_0;
    // 0x8044082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80440830: beql        $v0, $zero, L_804408A8
    if (ctx->r2 == 0) {
        // 0x80440834: lw          $v1, 0x180($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X180);
            goto L_804408A8;
    }
    goto skip_0;
    // 0x80440834: lw          $v1, 0x180($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X180);
    skip_0:
    // 0x80440838: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x8044083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80440840: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80440844: lw          $t1, 0x2630($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2630);
    // 0x80440848: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8044084C: beql        $t1, $zero, L_804408A8
    if (ctx->r9 == 0) {
        // 0x80440850: lw          $v1, 0x180($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X180);
            goto L_804408A8;
    }
    goto skip_1;
    // 0x80440850: lw          $v1, 0x180($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X180);
    skip_1:
    // 0x80440854: jal         0x80442188
    // 0x80440858: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_80442188(rdram, ctx);
        goto after_1;
    // 0x80440858: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_1:
    // 0x8044085C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80440860: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x80440864: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4ED0) << 16);
    // 0x80440868: lwc1        $f0, 0x3DD0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4ED0));
    // 0x8044086C: swc1        $f6, 0x1C78($t2)
    MEM_W(0X1C78, ctx->r10) = ctx->f6.u32l;
    // 0x80440870: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x80440874: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80440878: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4ED4) << 16);
    // 0x8044087C: swc1        $f8, 0x1C7C($t3)
    MEM_W(0X1C7C, ctx->r11) = ctx->f8.u32l;
    // 0x80440880: lw          $t4, 0x1F4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F4);
    // 0x80440884: swc1        $f0, 0x1C24($t4)
    MEM_W(0X1C24, ctx->r12) = ctx->f0.u32l;
    // 0x80440888: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x8044088C: swc1        $f0, 0x1C28($t5)
    MEM_W(0X1C28, ctx->r13) = ctx->f0.u32l;
    // 0x80440890: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80440894: lwc1        $f10, 0x3DD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4ED4));
    // 0x80440898: swc1        $f10, 0x1C2C($t6)
    MEM_W(0X1C2C, ctx->r14) = ctx->f10.u32l;
    // 0x8044089C: b           L_80440910
    // 0x804408A0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
        goto L_80440910;
    // 0x804408A0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x804408A4: lw          $v1, 0x180($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X180);
L_804408A8:
    // 0x804408A8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x804408AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804408B0: lwc1        $f16, 0x3C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x804408B4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x804408B8: swc1        $f16, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f16.u32l;
    // 0x804408BC: lwc1        $f18, 0x40($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X40);
    // 0x804408C0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x804408C4: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x804408C8: lw          $t7, 0x262C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X262C);
    // 0x804408CC: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x804408D0: bnel        $at, $zero, L_80440914
    if (ctx->r1 != 0) {
        // 0x804408D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80440914;
    }
    goto skip_2;
    // 0x804408D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x804408D8: lw          $t8, 0x2628($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2628);
    // 0x804408DC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x804408E0: sw          $t9, 0x2628($v0)
    MEM_W(0X2628, ctx->r2) = ctx->r25;
    // 0x804408E4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x804408E8: lw          $t0, 0x2628($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2628);
    // 0x804408EC: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x804408F0: bnel        $at, $zero, L_80440914
    if (ctx->r1 != 0) {
        // 0x804408F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80440914;
    }
    goto skip_3;
    // 0x804408F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x804408F8: sw          $zero, 0x2628($v0)
    MEM_W(0X2628, ctx->r2) = 0;
    // 0x804408FC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80440900: lw          $t1, 0x262C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X262C);
    // 0x80440904: addiu       $t2, $t1, -0xF
    ctx->r10 = ADD32(ctx->r9, -0XF);
    // 0x80440908: sw          $t2, 0x262C($v0)
    MEM_W(0X262C, ctx->r2) = ctx->r10;
    // 0x8044090C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80440910:
    // 0x80440910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80440914:
    // 0x80440914: jal         0x8043EFF8
    // 0x80440918: lw          $a1, 0x262C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X262C);
    func_8043EFF8(rdram, ctx);
        goto after_2;
    // 0x80440918: lw          $a1, 0x262C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X262C);
    after_2:
    // 0x8044091C: jal         0x8043F33C
    // 0x80440920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F33C(rdram, ctx);
        goto after_3;
    // 0x80440920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80440924: jal         0x8043FBDC
    // 0x80440928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043FBDC(rdram, ctx);
        goto after_4;
    // 0x80440928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8044092C: jal         0x8043F150
    // 0x80440930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F150(rdram, ctx);
        goto after_5;
    // 0x80440930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80440934: jal         0x804400F0
    // 0x80440938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804400F0(rdram, ctx);
        goto after_6;
    // 0x80440938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8044093C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80440940: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80440944: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80440948: jr          $ra
    // 0x8044094C: nop

    return;
    // 0x8044094C: nop

;}
RECOMP_FUNC void func_80432E08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432E08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80432E0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80432E10: jal         0x80062748
    // 0x80432E14: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062748(rdram, ctx);
        goto after_0;
    // 0x80432E14: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x80432E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80432E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80432E20: jr          $ra
    // 0x80432E24: nop

    return;
    // 0x80432E24: nop

;}
RECOMP_FUNC void func_80536744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536744: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536748: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053674C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536750: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536754: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536758: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053675C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536760: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536764: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536768: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053676C: jr          $ra
    // 0x80536770: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536770: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80532B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532B50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80532B54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80532B58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80532B5C: lh          $t6, 0x1F0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1F0);
    // 0x80532B60: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80532B64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80532B68: bnel        $t6, $at, L_80532B94
    if (ctx->r14 != ctx->r1) {
        // 0x80532B6C: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_80532B94;
    }
    goto skip_0;
    // 0x80532B6C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x80532B70: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80532B74: jal         0x80067BBC
    // 0x80532B78: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80532B78: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x80532B7C: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    // 0x80532B80: jal         0x80067F78
    // 0x80532B84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80532B84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80532B88: b           L_80532BAC
    // 0x80532B8C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_80532BAC;
    // 0x80532B8C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x80532B90: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_80532B94:
    // 0x80532B94: jal         0x80067BBC
    // 0x80532B98: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80532B98: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80532B9C: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    // 0x80532BA0: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80532BA4: jal         0x800678F0
    // 0x80532BA8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x80532BA8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_80532BAC:
    // 0x80532BAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80532BB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80532BB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80532BB8: jr          $ra
    // 0x80532BBC: nop

    return;
    // 0x80532BBC: nop

;}
RECOMP_FUNC void func_80573F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80573F08: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80573F0C: lw          $t6, -0x762C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X762C);
    // 0x80573F10: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80573F14: addiu       $v1, $v1, 0x7EA4
    ctx->r3 = ADD32(ctx->r3, 0X7EA4);
    // 0x80573F18: beq         $a0, $t6, L_80573F28
    if (ctx->r4 == ctx->r14) {
        // 0x80573F1C: lui         $v0, 0x800F
        ctx->r2 = S32(0X800F << 16);
            goto L_80573F28;
    }
    // 0x80573F1C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80573F20: jr          $ra
    // 0x80573F24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80573F24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80573F28:
    // 0x80573F28: addiu       $v0, $v0, 0x7F14
    ctx->r2 = ADD32(ctx->r2, 0X7F14);
    // 0x80573F2C: lw          $t7, 0xB34($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XB34);
L_80573F30:
    // 0x80573F30: beql        $a0, $t7, L_80573F44
    if (ctx->r4 == ctx->r15) {
        // 0x80573F34: lw          $t8, 0xB38($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XB38);
            goto L_80573F44;
    }
    goto skip_0;
    // 0x80573F34: lw          $t8, 0xB38($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XB38);
    skip_0:
    // 0x80573F38: jr          $ra
    // 0x80573F3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80573F3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80573F40: lw          $t8, 0xB38($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XB38);
L_80573F44:
    // 0x80573F44: beql        $a0, $t8, L_80573F58
    if (ctx->r4 == ctx->r24) {
        // 0x80573F48: lw          $t9, 0xB3C($v1)
        ctx->r25 = MEM_W(ctx->r3, 0XB3C);
            goto L_80573F58;
    }
    goto skip_1;
    // 0x80573F48: lw          $t9, 0xB3C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XB3C);
    skip_1:
    // 0x80573F4C: jr          $ra
    // 0x80573F50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80573F50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80573F54: lw          $t9, 0xB3C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XB3C);
L_80573F58:
    // 0x80573F58: beql        $a0, $t9, L_80573F6C
    if (ctx->r4 == ctx->r25) {
        // 0x80573F5C: lw          $t0, 0xB40($v1)
        ctx->r8 = MEM_W(ctx->r3, 0XB40);
            goto L_80573F6C;
    }
    goto skip_2;
    // 0x80573F5C: lw          $t0, 0xB40($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XB40);
    skip_2:
    // 0x80573F60: jr          $ra
    // 0x80573F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80573F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80573F68: lw          $t0, 0xB40($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XB40);
L_80573F6C:
    // 0x80573F6C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80573F70: beq         $a0, $t0, L_80573F80
    if (ctx->r4 == ctx->r8) {
        // 0x80573F74: nop
    
            goto L_80573F80;
    }
    // 0x80573F74: nop

    // 0x80573F78: jr          $ra
    // 0x80573F7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80573F7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80573F80:
    // 0x80573F80: bnel        $v1, $v0, L_80573F30
    if (ctx->r3 != ctx->r2) {
        // 0x80573F84: lw          $t7, 0xB34($v1)
        ctx->r15 = MEM_W(ctx->r3, 0XB34);
            goto L_80573F30;
    }
    goto skip_3;
    // 0x80573F84: lw          $t7, 0xB34($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XB34);
    skip_3:
    // 0x80573F88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80573F8C: jr          $ra
    // 0x80573F90: nop

    return;
    // 0x80573F90: nop

;}
