#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80580EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580EA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80580EA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580EAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80580EB0: jal         0x8057EF14
    // 0x80580EB4: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    func_8057EF14(rdram, ctx);
        goto after_0;
    // 0x80580EB4: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    after_0:
    // 0x80580EB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80580EBC: jal         0x80580C70
    // 0x80580EC0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80580C70(rdram, ctx);
        goto after_1;
    // 0x80580EC0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80580EC4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80580EC8: beql        $v1, $zero, L_80580F24
    if (ctx->r3 == 0) {
        // 0x80580ECC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80580F24;
    }
    goto skip_0;
    // 0x80580ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80580ED0: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    // 0x80580ED4: lbu         $t6, 0x18($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X18);
    // 0x80580ED8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80580EDC: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x80580EE0: bne         $t6, $at, L_80580F20
    if (ctx->r14 != ctx->r1) {
        // 0x80580EE4: lw          $a1, 0xC($v0)
        ctx->r5 = MEM_W(ctx->r2, 0XC);
            goto L_80580F20;
    }
    // 0x80580EE4: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x80580EE8: lw          $t7, 0x1E0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1E0);
    // 0x80580EEC: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x80580EF0: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80580EF4: beql        $t7, $zero, L_80580F24
    if (ctx->r15 == 0) {
        // 0x80580EF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80580F24;
    }
    goto skip_1;
    // 0x80580EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80580EFC: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80580F00: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80580F04: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80580F08: beq         $t0, $at, L_80580F20
    if (ctx->r8 == ctx->r1) {
        // 0x80580F0C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80580F20;
    }
    // 0x80580F0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80580F10: sb          $t1, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r9;
    // 0x80580F14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80580F18: jal         0x80580F6C
    // 0x80580F1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80580F6C(rdram, ctx);
        goto after_2;
    // 0x80580F1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80580F20:
    // 0x80580F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80580F24:
    // 0x80580F24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80580F28: jr          $ra
    // 0x80580F2C: nop

    return;
    // 0x80580F2C: nop

;}
RECOMP_FUNC void func_80711A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80711A8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80711A90: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80711A94: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80711A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80711A9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80711AA0: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80711AA4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80711AA8: lui         $t8, 0x8071
    ctx->r24 = S32(RELOC_HI16(727, 0X191C) << 16);
    // 0x80711AAC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80711AB0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80711AB4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80711AB8: lw          $t8, 0x288C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(727, 0X191C));
    // 0x80711ABC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80711AC0: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80711AC4: beq         $a2, $at, L_80711ADC
    if (ctx->r6 == ctx->r1) {
        // 0x80711AC8: sw          $t8, 0x20($a0)
        MEM_W(0X20, ctx->r4) = ctx->r24;
            goto L_80711ADC;
    }
    // 0x80711AC8: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80711ACC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80711AD0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80711AD4: jal         0x807111A4
    // 0x80711AD8: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    func_807111A4(rdram, ctx);
        goto after_0;
    // 0x80711AD8: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    after_0:
L_80711ADC:
    // 0x80711ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80711AE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80711AE4: jr          $ra
    // 0x80711AE8: nop

    return;
    // 0x80711AE8: nop

    // 0x80711AEC: nop

;}
RECOMP_FUNC void func_8002D9F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D9F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002D9F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D9FC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002DA00: addiu       $t6, $zero, 0x68
    ctx->r14 = ADD32(0, 0X68);
    // 0x8002DA04: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8002DA08: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002DA0C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8002DA10: sb          $t7, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r15;
    // 0x8002DA14: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002DA18: lui         $t9, 0x8003
    ctx->r25 = S32(0X8003 << 16);
    // 0x8002DA1C: addiu       $t8, $t8, 0x3C20
    ctx->r24 = ADD32(ctx->r24, 0X3C20);
    // 0x8002DA20: addiu       $t9, $t9, 0x3C9C
    ctx->r25 = ADD32(ctx->r25, 0X3C9C);
    // 0x8002DA24: sw          $t8, 0xAC($a1)
    MEM_W(0XAC, ctx->r5) = ctx->r24;
    // 0x8002DA28: sw          $t9, 0xB8($a1)
    MEM_W(0XB8, ctx->r5) = ctx->r25;
    // 0x8002DA2C: swc1        $f4, 0x54($a1)
    MEM_W(0X54, ctx->r5) = ctx->f4.u32l;
    // 0x8002DA30: jal         0x8002310C
    // 0x8002DA34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8002310C(rdram, ctx);
        goto after_0;
    // 0x8002DA34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002DA38: jal         0x80032E38
    // 0x8002DA3C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80032E38(rdram, ctx);
        goto after_1;
    // 0x8002DA3C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002DA40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DA44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002DA48: jr          $ra
    // 0x8002DA4C: nop

    return;
    // 0x8002DA4C: nop

;}
RECOMP_FUNC void __cosf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D250: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x8008D254: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8008D258: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8008D25C: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8008D260: sra         $t6, $v0, 22
    ctx->r14 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8008D264: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x8008D268: slti        $at, $t7, 0x136
    ctx->r1 = SIGNED(ctx->r15) < 0X136 ? 1 : 0;
    // 0x8008D26C: beql        $at, $zero, L_8008D394
    if (ctx->r1 == 0) {
        // 0x8008D270: c.eq.s      $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
            goto L_8008D394;
    }
    goto skip_0;
    // 0x8008D270: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
    skip_0:
    // 0x8008D274: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008D278: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8008D27C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008D280: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8008D284: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8008D288: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8008D28C: bc1fl       L_8008D2A0
    if (!c1cs) {
        // 0x8008D290: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_8008D2A0;
    }
    goto skip_1;
    // 0x8008D290: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_1:
    // 0x8008D294: b           L_8008D2A0
    // 0x8008D298: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
        goto L_8008D2A0;
    // 0x8008D298: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x8008D29C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8008D2A0:
    // 0x8008D2A0: ldc1        $f8, 0x3418($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X3418);
    // 0x8008D2A4: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x8008D2A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008D2AC: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x8008D2B0: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8008D2B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008D2B8: add.d       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = ctx->f10.d + ctx->f18.d;
    // 0x8008D2BC: c.le.d      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.d <= ctx->f14.d;
    // 0x8008D2C0: nop

    // 0x8008D2C4: bc1fl       L_8008D2E4
    if (!c1cs) {
        // 0x8008D2C8: sub.d       $f10, $f14, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
            goto L_8008D2E4;
    }
    goto skip_2;
    // 0x8008D2C8: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
    skip_2:
    // 0x8008D2CC: add.d       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f14.d + ctx->f18.d;
    // 0x8008D2D0: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x8008D2D4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8008D2D8: b           L_8008D2F4
    // 0x8008D2DC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
        goto L_8008D2F4;
    // 0x8008D2DC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8008D2E0: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
L_8008D2E4:
    // 0x8008D2E4: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8008D2E8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8008D2EC: nop

    // 0x8008D2F0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
L_8008D2F4:
    // 0x8008D2F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8008D2F8: ldc1        $f10, 0x3420($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X3420);
    // 0x8008D2FC: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8008D300: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8008D304: ldc1        $f6, 0x3428($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X3428);
    // 0x8008D308: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8008D30C: addiu       $v1, $v1, 0x33F0
    ctx->r3 = ADD32(ctx->r3, 0X33F0);
    // 0x8008D310: sub.d       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f8.d - ctx->f18.d;
    // 0x8008D314: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x8008D318: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x8008D31C: ldc1        $f10, 0x20($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X20);
    // 0x8008D320: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8008D324: ldc1        $f6, 0x18($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X18);
    // 0x8008D328: sub.d       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f12.d - ctx->f4.d;
    // 0x8008D32C: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x8008D330: mul.d       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f14.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x8008D334: nop

    // 0x8008D338: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x8008D33C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8008D340: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x8008D344: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x8008D348: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8008D34C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x8008D350: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x8008D354: bne         $t0, $zero, L_8008D374
    if (ctx->r8 != 0) {
        // 0x8008D358: add.d       $f16, $f10, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
            goto L_8008D374;
    }
    // 0x8008D358: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x8008D35C: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x8008D360: nop

    // 0x8008D364: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8008D368: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x8008D36C: jr          $ra
    // 0x8008D370: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x8008D370: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8008D374:
    // 0x8008D374: mul.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x8008D378: nop

    // 0x8008D37C: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8008D380: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x8008D384: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x8008D388: jr          $ra
    // 0x8008D38C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x8008D38C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8008D390: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
L_8008D394:
    // 0x8008D394: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8008D398: bc1t        L_8008D3AC
    if (c1cs) {
        // 0x8008D39C: nop
    
            goto L_8008D3AC;
    }
    // 0x8008D39C: nop

    // 0x8008D3A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8008D3A4: jr          $ra
    // 0x8008D3A8: lwc1        $f0, 0x3440($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3440);
    return;
    // 0x8008D3A8: lwc1        $f0, 0x3440($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3440);
L_8008D3AC:
    // 0x8008D3AC: lwc1        $f0, 0x3430($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3430);
    // 0x8008D3B0: jr          $ra
    // 0x8008D3B4: nop

    return;
    // 0x8008D3B4: nop

;}
RECOMP_FUNC void func_8049EBD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049EBD8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8049EBDC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8049EBE0: lhu         $t7, 0x8($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X8);
    // 0x8049EBE4: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8049EBE8: beq         $t8, $zero, L_8049EC34
    if (ctx->r24 == 0) {
        // 0x8049EBEC: nop
    
            goto L_8049EC34;
    }
    // 0x8049EBEC: nop

    // 0x8049EBF0: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8049EBF4: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8049EBF8: lwc1        $f2, 0x84($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8049EBFC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8049EC00: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8049EC04: nop

    // 0x8049EC08: bc1fl       L_8049EC18
    if (!c1cs) {
        // 0x8049EC0C: lwc1        $f8, 0x14($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
            goto L_8049EC18;
    }
    goto skip_0;
    // 0x8049EC0C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    skip_0:
    // 0x8049EC10: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8049EC14: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
L_8049EC18:
    // 0x8049EC18: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8049EC1C: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8049EC20: nop

    // 0x8049EC24: bc1f        L_8049EC34
    if (!c1cs) {
        // 0x8049EC28: nop
    
            goto L_8049EC34;
    }
    // 0x8049EC28: nop

    // 0x8049EC2C: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x8049EC30: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_8049EC34:
    // 0x8049EC34: jr          $ra
    // 0x8049EC38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8049EC38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8073D600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073D600: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8073D604: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073D608: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073D60C: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8073D610: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8073D614: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8073D618: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8073D61C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8073D620: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x8073D624: jal         0x8004921C
    // 0x8073D628: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8073D628: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8073D62C: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x8073D630: sh          $v0, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r2;
    // 0x8073D634: jal         0x8004921C
    // 0x8073D638: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x8073D638: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8073D63C: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x8073D640: sh          $v0, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r2;
    // 0x8073D644: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8073D648: lw          $t9, 0x16C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X16C);
    // 0x8073D64C: lw          $t8, 0x168($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X168);
    // 0x8073D650: lw          $v1, -0x260C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X260C);
    // 0x8073D654: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x8073D658: lw          $t0, 0x80($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X80);
    // 0x8073D65C: lui         $t9, 0x8074
    ctx->r25 = S32(RELOC_HI16(745, 0X1418) << 16);
    // 0x8073D660: sw          $t6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r14;
    // 0x8073D664: lw          $s0, 0xC($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XC);
    // 0x8073D668: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x8073D66C: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8073D670: addiu       $s0, $s0, -0x80
    ctx->r16 = ADD32(ctx->r16, -0X80);
    // 0x8073D674: sw          $s0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r16;
    // 0x8073D678: lw          $t1, 0x1F4($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X1F4);
    // 0x8073D67C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8073D680: lw          $t7, 0x24($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X24);
    // 0x8073D684: sw          $t0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r8;
    // 0x8073D688: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x8073D68C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8073D690: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8073D694: lw          $t9, -0x1A18($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(745, 0X1418));
    // 0x8073D698: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x8073D69C: jal         0x80077338
    // 0x8073D6A0: sw          $t6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r14;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x8073D6A0: sw          $t6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r14;
    after_2:
    // 0x8073D6A4: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x8073D6A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8073D6AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8073D6B0: jal         0x8007711C
    // 0x8073D6B4: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x8073D6B4: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    after_3:
    // 0x8073D6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073D6BC: jal         0x8073D33C
    // 0x8073D6C0: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    func_8073D33C(rdram, ctx);
        goto after_4;
    // 0x8073D6C0: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    after_4:
    // 0x8073D6C4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D6C8: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8073D6CC: ori         $t9, $t9, 0x207F
    ctx->r25 = ctx->r25 | 0X207F;
    // 0x8073D6D0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8073D6D4: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x8073D6D8: sw          $s0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r16;
    // 0x8073D6DC: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8073D6E0: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D6E4: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x8073D6E8: lui         $ra, 0x700
    ctx->r31 = S32(0X700 << 16);
    // 0x8073D6EC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8073D6F0: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x8073D6F4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8073D6F8: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x8073D6FC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8073D700: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x8073D704: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8073D708: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D70C: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x8073D710: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8073D714: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x8073D718: sw          $ra, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r31;
    // 0x8073D71C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8073D720: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D724: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8073D728: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8073D72C: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8073D730: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x8073D734: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8073D738: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8073D73C: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D740: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
    // 0x8073D744: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8073D748: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x8073D74C: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8073D750: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8073D754: lh          $t7, 0x98($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X98);
    // 0x8073D758: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8073D75C: addiu       $t4, $t2, 0x7
    ctx->r12 = ADD32(ctx->r10, 0X7);
    // 0x8073D760: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8073D764: sra         $t4, $t4, 3
    ctx->r12 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8073D768: andi        $t4, $t4, 0x1FF
    ctx->r12 = ctx->r12 & 0X1FF;
    // 0x8073D76C: mflo        $t0
    ctx->r8 = lo;
    // 0x8073D770: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8073D774: sra         $t0, $t0, 1
    ctx->r8 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8073D778: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8073D77C: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8073D780: beq         $at, $zero, L_8073D790
    if (ctx->r1 == 0) {
        // 0x8073D784: nop
    
            goto L_8073D790;
    }
    // 0x8073D784: nop

    // 0x8073D788: b           L_8073D790
    // 0x8073D78C: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
        goto L_8073D790;
    // 0x8073D78C: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_8073D790:
    // 0x8073D790: bgez        $t2, L_8073D7A0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8073D794: sra         $a1, $t2, 3
        ctx->r5 = S32(SIGNED(ctx->r10) >> 3);
            goto L_8073D7A0;
    }
    // 0x8073D794: sra         $a1, $t2, 3
    ctx->r5 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8073D798: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
    // 0x8073D79C: sra         $a1, $at, 3
    ctx->r5 = S32(SIGNED(ctx->r1) >> 3);
L_8073D7A0:
    // 0x8073D7A0: bgtz        $a1, L_8073D7B0
    if (SIGNED(ctx->r5) > 0) {
        // 0x8073D7A4: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8073D7B0;
    }
    // 0x8073D7A4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8073D7A8: b           L_8073D7B0
    // 0x8073D7AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8073D7B0;
    // 0x8073D7AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8073D7B0:
    // 0x8073D7B0: bgtz        $a1, L_8073D7C0
    if (SIGNED(ctx->r5) > 0) {
        // 0x8073D7B4: addiu       $t8, $a2, 0x7FF
        ctx->r24 = ADD32(ctx->r6, 0X7FF);
            goto L_8073D7C0;
    }
    // 0x8073D7B4: addiu       $t8, $a2, 0x7FF
    ctx->r24 = ADD32(ctx->r6, 0X7FF);
    // 0x8073D7B8: b           L_8073D7C4
    // 0x8073D7BC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8073D7C4;
    // 0x8073D7BC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8073D7C0:
    // 0x8073D7C0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
L_8073D7C4:
    // 0x8073D7C4: div         $zero, $t8, $s0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r16)));
    // 0x8073D7C8: mflo        $t9
    ctx->r25 = lo;
    // 0x8073D7CC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8073D7D0: bne         $s0, $zero, L_8073D7DC
    if (ctx->r16 != 0) {
        // 0x8073D7D4: nop
    
            goto L_8073D7DC;
    }
    // 0x8073D7D4: nop

    // 0x8073D7D8: break       7
    do_break(2155075544);
L_8073D7DC:
    // 0x8073D7DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8073D7E0: bne         $s0, $at, L_8073D7F4
    if (ctx->r16 != ctx->r1) {
        // 0x8073D7E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8073D7F4;
    }
    // 0x8073D7E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8073D7E8: bne         $t8, $at, L_8073D7F4
    if (ctx->r24 != ctx->r1) {
        // 0x8073D7EC: nop
    
            goto L_8073D7F4;
    }
    // 0x8073D7EC: nop

    // 0x8073D7F0: break       6
    do_break(2155075568);
L_8073D7F4:
    // 0x8073D7F4: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x8073D7F8: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8073D7FC: or          $t7, $t6, $ra
    ctx->r15 = ctx->r14 | ctx->r31;
    // 0x8073D800: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8073D804: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x8073D808: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D80C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8073D810: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8073D814: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x8073D818: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x8073D81C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8073D820: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8073D824: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D828: sll         $t4, $t4, 9
    ctx->r12 = S32(ctx->r12 << 9);
    // 0x8073D82C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
    // 0x8073D830: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8073D834: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x8073D838: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x8073D83C: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8073D840: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D844: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8073D848: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8073D84C: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8073D850: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8073D854: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8073D858: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
    // 0x8073D85C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8073D860: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8073D864: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x8073D868: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8073D86C: lh          $t7, 0x98($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X98);
    // 0x8073D870: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8073D874: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8073D878: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x8073D87C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8073D880: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8073D884: or          $t5, $t8, $t7
    ctx->r13 = ctx->r24 | ctx->r15;
    // 0x8073D888: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x8073D88C: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D890: lui         $t8, 0x8074
    ctx->r24 = S32(RELOC_HI16(745, 0X13A8) << 16);
    // 0x8073D894: addiu       $t8, $t8, -0x1A88
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(745, 0X13A8));
    // 0x8073D898: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8073D89C: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x8073D8A0: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8073D8A4: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x8073D8A8: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D8AC: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8073D8B0: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8073D8B4: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8073D8B8: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8073D8BC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8073D8C0: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x8073D8C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8073D8C8: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x8073D8CC: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8073D8D0: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D8D4: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x8073D8D8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8073D8DC: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8073D8E0: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8073D8E4: sw          $ra, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r31;
    // 0x8073D8E8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8073D8EC: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D8F0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8073D8F4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8073D8F8: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x8073D8FC: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x8073D900: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8073D904: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8073D908: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D90C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8073D910: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8073D914: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8073D918: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x8073D91C: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x8073D920: beq         $at, $zero, L_8073D930
    if (ctx->r1 == 0) {
        // 0x8073D924: or          $t2, $t6, $zero
        ctx->r10 = ctx->r14 | 0;
            goto L_8073D930;
    }
    // 0x8073D924: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x8073D928: b           L_8073D930
    // 0x8073D92C: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
        goto L_8073D930;
    // 0x8073D92C: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_8073D930:
    // 0x8073D930: bgtz        $a1, L_8073D940
    if (SIGNED(ctx->r5) > 0) {
        // 0x8073D934: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_8073D940;
    }
    // 0x8073D934: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8073D938: b           L_8073D940
    // 0x8073D93C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8073D940;
    // 0x8073D93C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8073D940:
    // 0x8073D940: bgtz        $a1, L_8073D950
    if (SIGNED(ctx->r5) > 0) {
        // 0x8073D944: addiu       $t9, $a2, 0x7FF
        ctx->r25 = ADD32(ctx->r6, 0X7FF);
            goto L_8073D950;
    }
    // 0x8073D944: addiu       $t9, $a2, 0x7FF
    ctx->r25 = ADD32(ctx->r6, 0X7FF);
    // 0x8073D948: b           L_8073D950
    // 0x8073D94C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8073D950;
    // 0x8073D94C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8073D950:
    // 0x8073D950: div         $zero, $t9, $s0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r16)));
    // 0x8073D954: mflo        $t6
    ctx->r14 = lo;
    // 0x8073D958: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8073D95C: bne         $s0, $zero, L_8073D968
    if (ctx->r16 != 0) {
        // 0x8073D960: nop
    
            goto L_8073D968;
    }
    // 0x8073D960: nop

    // 0x8073D964: break       7
    do_break(2155075940);
L_8073D968:
    // 0x8073D968: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8073D96C: bne         $s0, $at, L_8073D980
    if (ctx->r16 != ctx->r1) {
        // 0x8073D970: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8073D980;
    }
    // 0x8073D970: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8073D974: bne         $t9, $at, L_8073D980
    if (ctx->r25 != ctx->r1) {
        // 0x8073D978: nop
    
            goto L_8073D980;
    }
    // 0x8073D978: nop

    // 0x8073D97C: break       6
    do_break(2155075964);
L_8073D980:
    // 0x8073D980: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x8073D984: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8073D988: or          $t7, $t8, $ra
    ctx->r15 = ctx->r24 | ctx->r31;
    // 0x8073D98C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8073D990: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8073D994: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D998: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8073D99C: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8073D9A0: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x8073D9A4: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8073D9A8: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8073D9AC: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D9B0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8073D9B4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8073D9B8: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8073D9BC: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8073D9C0: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x8073D9C4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D9C8: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8073D9CC: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8073D9D0: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x8073D9D4: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x8073D9D8: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8073D9DC: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8073D9E0: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8073D9E4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8073D9E8: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(745, 0X1390) << 16);
    // 0x8073D9EC: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8073D9F0: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x8073D9F4: addiu       $t6, $t6, -0x1AA0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(745, 0X1390));
    // 0x8073D9F8: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x8073D9FC: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x8073DA00: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8073DA04: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x8073DA08: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8073DA0C: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8073DA10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8073DA14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073DA18: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x8073DA1C: jr          $ra
    // 0x8073DA20: nop

    return;
    // 0x8073DA20: nop

;}
RECOMP_FUNC void func_805A74D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A74D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A74D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805A74D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x805A74DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A74E0: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x805A74E4: jal         0x80067878
    // 0x805A74E8: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x805A74E8: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    after_0:
    // 0x805A74EC: jal         0x80045BD8
    // 0x805A74F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x805A74F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805A74F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A74F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A74FC: jr          $ra
    // 0x805A7500: nop

    return;
    // 0x805A7500: nop

;}
RECOMP_FUNC void func_8001ED3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ED3C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001ED40: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x8001ED44: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8001ED48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001ED4C: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001ED50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001ED54: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x8001ED58: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8001ED5C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8001ED60: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x8001ED64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001ED68: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8001ED6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001ED70: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001ED74: jal         0x800534C0
    // 0x8001ED78: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    func_800534C0(rdram, ctx);
        goto after_0;
    // 0x8001ED78: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x8001ED7C: addiu       $v1, $sp, 0x36
    ctx->r3 = ADD32(ctx->r29, 0X36);
    // 0x8001ED80: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x8001ED84: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x8001ED88: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8001ED8C: andi        $t0, $v0, 0x7FF
    ctx->r8 = ctx->r2 & 0X7FF;
    // 0x8001ED90: andi        $t8, $t7, 0xF8
    ctx->r24 = ctx->r15 & 0XF8;
    // 0x8001ED94: bne         $t8, $at, L_8001EDA0
    if (ctx->r24 != ctx->r1) {
        // 0x8001ED98: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001EDA0;
    }
    // 0x8001ED98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001ED9C: sh          $t0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r8;
L_8001EDA0:
    // 0x8001EDA0: lhu         $t1, 0x36($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X36);
    // 0x8001EDA4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001EDA8: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001EDAC: beq         $t1, $zero, L_8001EE08
    if (ctx->r9 == 0) {
        // 0x8001EDB0: lwc1        $f14, 0x3C($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_8001EE08;
    }
    // 0x8001EDB0: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001EDB4: beql        $t1, $at, L_8001EE0C
    if (ctx->r9 == ctx->r1) {
        // 0x8001EDB8: addiu       $t2, $sp, 0x28
        ctx->r10 = ADD32(ctx->r29, 0X28);
            goto L_8001EE0C;
    }
    goto skip_0;
    // 0x8001EDB8: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    skip_0:
    // 0x8001EDBC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8001EDC0: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8001EDC4: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8001EDC8: beq         $v0, $at, L_8001EE08
    if (ctx->r2 == ctx->r1) {
        // 0x8001EDCC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8001EE08;
    }
    // 0x8001EDCC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001EDD0: beq         $v0, $at, L_8001EE08
    if (ctx->r2 == ctx->r1) {
        // 0x8001EDD4: or          $a0, $t1, $zero
        ctx->r4 = ctx->r9 | 0;
            goto L_8001EE08;
    }
    // 0x8001EDD4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8001EDD8: jal         0x8004A97C
    // 0x8001EDDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004A97C(rdram, ctx);
        goto after_1;
    // 0x8001EDDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8001EDE0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001EDE4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8001EDE8: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8001EDEC: nop

    // 0x8001EDF0: bc1f        L_8001EE00
    if (!c1cs) {
        // 0x8001EDF4: nop
    
            goto L_8001EE00;
    }
    // 0x8001EDF4: nop

    // 0x8001EDF8: b           L_8001EF2C
    // 0x8001EDFC: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
        goto L_8001EF2C;
    // 0x8001EDFC: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
L_8001EE00:
    // 0x8001EE00: b           L_8001EF2C
    // 0x8001EE04: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001EF2C;
    // 0x8001EE04: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001EE08:
    // 0x8001EE08: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
L_8001EE0C:
    // 0x8001EE0C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8001EE10: jal         0x800534C0
    // 0x8001EE14: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_800534C0(rdram, ctx);
        goto after_2;
    // 0x8001EE14: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x8001EE18: addiu       $v1, $sp, 0x36
    ctx->r3 = ADD32(ctx->r29, 0X36);
    // 0x8001EE1C: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x8001EE20: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x8001EE24: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8001EE28: andi        $t6, $v0, 0x7FF
    ctx->r14 = ctx->r2 & 0X7FF;
    // 0x8001EE2C: andi        $t4, $t3, 0xF8
    ctx->r12 = ctx->r11 & 0XF8;
    // 0x8001EE30: bne         $t4, $at, L_8001EE3C
    if (ctx->r12 != ctx->r1) {
        // 0x8001EE34: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001EE3C;
    }
    // 0x8001EE34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001EE38: sh          $t6, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r14;
L_8001EE3C:
    // 0x8001EE3C: lhu         $t7, 0x36($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X36);
    // 0x8001EE40: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001EE44: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001EE48: beq         $t7, $zero, L_8001EE84
    if (ctx->r15 == 0) {
        // 0x8001EE4C: lwc1        $f10, 0x3C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_8001EE84;
    }
    // 0x8001EE4C: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001EE50: beql        $t7, $at, L_8001EE88
    if (ctx->r15 == ctx->r1) {
        // 0x8001EE54: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_8001EE88;
    }
    goto skip_1;
    // 0x8001EE54: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    skip_1:
    // 0x8001EE58: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8001EE5C: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8001EE60: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8001EE64: beq         $v0, $at, L_8001EE84
    if (ctx->r2 == ctx->r1) {
        // 0x8001EE68: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8001EE84;
    }
    // 0x8001EE68: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001EE6C: beq         $v0, $at, L_8001EE84
    if (ctx->r2 == ctx->r1) {
        // 0x8001EE70: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8001EE84;
    }
    // 0x8001EE70: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8001EE74: jal         0x8004A97C
    // 0x8001EE78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004A97C(rdram, ctx);
        goto after_3;
    // 0x8001EE78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8001EE7C: b           L_8001EF30
    // 0x8001EE80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001EF30;
    // 0x8001EE80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001EE84:
    // 0x8001EE84: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
L_8001EE88:
    // 0x8001EE88: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001EE8C: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x8001EE90: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8001EE94: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8001EE98: jal         0x800534C0
    // 0x8001EE9C: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    func_800534C0(rdram, ctx);
        goto after_4;
    // 0x8001EE9C: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    after_4:
    // 0x8001EEA0: addiu       $v1, $sp, 0x36
    ctx->r3 = ADD32(ctx->r29, 0X36);
    // 0x8001EEA4: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x8001EEA8: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8001EEAC: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8001EEB0: andi        $t2, $v0, 0x7FF
    ctx->r10 = ctx->r2 & 0X7FF;
    // 0x8001EEB4: andi        $t0, $t9, 0xF8
    ctx->r8 = ctx->r25 & 0XF8;
    // 0x8001EEB8: bnel        $t0, $at, L_8001EEC8
    if (ctx->r8 != ctx->r1) {
        // 0x8001EEBC: lhu         $t3, 0x36($sp)
        ctx->r11 = MEM_HU(ctx->r29, 0X36);
            goto L_8001EEC8;
    }
    goto skip_2;
    // 0x8001EEBC: lhu         $t3, 0x36($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X36);
    skip_2:
    // 0x8001EEC0: sh          $t2, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r10;
    // 0x8001EEC4: lhu         $t3, 0x36($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X36);
L_8001EEC8:
    // 0x8001EEC8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001EECC: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001EED0: beq         $t3, $zero, L_8001EF2C
    if (ctx->r11 == 0) {
        // 0x8001EED4: nop
    
            goto L_8001EF2C;
    }
    // 0x8001EED4: nop

    // 0x8001EED8: beq         $t3, $at, L_8001EF2C
    if (ctx->r11 == ctx->r1) {
        // 0x8001EEDC: nop
    
            goto L_8001EF2C;
    }
    // 0x8001EEDC: nop

    // 0x8001EEE0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8001EEE4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8001EEE8: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8001EEEC: beq         $v0, $at, L_8001EF2C
    if (ctx->r2 == ctx->r1) {
        // 0x8001EEF0: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8001EF2C;
    }
    // 0x8001EEF0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001EEF4: beq         $v0, $at, L_8001EF2C
    if (ctx->r2 == ctx->r1) {
        // 0x8001EEF8: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_8001EF2C;
    }
    // 0x8001EEF8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8001EEFC: jal         0x8004A97C
    // 0x8001EF00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004A97C(rdram, ctx);
        goto after_5;
    // 0x8001EF00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8001EF04: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001EF08: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8001EF0C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8001EF10: nop

    // 0x8001EF14: bc1f        L_8001EF24
    if (!c1cs) {
        // 0x8001EF18: nop
    
            goto L_8001EF24;
    }
    // 0x8001EF18: nop

    // 0x8001EF1C: b           L_8001EF2C
    // 0x8001EF20: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
        goto L_8001EF2C;
    // 0x8001EF20: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
L_8001EF24:
    // 0x8001EF24: b           L_8001EF2C
    // 0x8001EF28: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001EF2C;
    // 0x8001EF28: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001EF2C:
    // 0x8001EF2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001EF30:
    // 0x8001EF30: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001EF34: jr          $ra
    // 0x8001EF38: nop

    return;
    // 0x8001EF38: nop

;}
RECOMP_FUNC void func_80582498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582498: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8058249C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805824A0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x805824A4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805824A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805824AC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805824B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805824B4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805824B8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805824BC: lui         $t1, 0x8058
    ctx->r9 = S32(RELOC_HI16(399, 0X4710) << 16);
    // 0x805824C0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805824C4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805824C8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805824CC: lw          $t1, 0x3520($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(399, 0X4710));
    // 0x805824D0: jr          $ra
    // 0x805824D4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x805824D4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804C5F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5F80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C5F84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C5F88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C5F8C: lui         $a0, 0x804C
    ctx->r4 = S32(RELOC_HI16(218, 0X550) << 16);
    // 0x804C5F90: lui         $a1, 0x804C
    ctx->r5 = S32(RELOC_HI16(218, 0X560) << 16);
    // 0x804C5F94: addiu       $a1, $a1, 0x64E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(218, 0X560));
    // 0x804C5F98: addiu       $a0, $a0, 0x64D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(218, 0X550));
    // 0x804C5F9C: jal         0x8004667C
    // 0x804C5FA0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x804C5FA0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x804C5FA4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x804C5FA8: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x804C5FAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804C5FB0: lui         $a2, 0x804C
    ctx->r6 = S32(RELOC_HI16(218, 0X328) << 16);
    // 0x804C5FB4: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x804C5FB8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x804C5FBC: bnel        $t7, $zero, L_804C5FD0
    if (ctx->r15 != 0) {
        // 0x804C5FC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C5FD0;
    }
    goto skip_0;
    // 0x804C5FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C5FC4: jal         0x80057B28
    // 0x804C5FC8: addiu       $a2, $a2, 0x62A8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(218, 0X328));
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x804C5FC8: addiu       $a2, $a2, 0x62A8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(218, 0X328));
    after_1:
    // 0x804C5FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C5FD0:
    // 0x804C5FD0: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(218, 0X60) << 16);
    // 0x804C5FD4: addiu       $v0, $v0, 0x5FE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(218, 0X60));
    // 0x804C5FD8: jr          $ra
    // 0x804C5FDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804C5FDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806D94CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D94CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D94D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D94D4: jal         0x806D8FD0
    // 0x806D94D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806D8FD0(rdram, ctx);
        goto after_0;
    // 0x806D94D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D94DC: jal         0x80045BD8
    // 0x806D94E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x806D94E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806D94E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D94E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D94EC: jr          $ra
    // 0x806D94F0: nop

    return;
    // 0x806D94F0: nop

;}
RECOMP_FUNC void func_80439EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80439EAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80439EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80439EB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80439EB8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80439EBC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80439EC0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80439EC4: addiu       $t7, $v0, 0x4B8
    ctx->r15 = ADD32(ctx->r2, 0X4B8);
    // 0x80439EC8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80439ECC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80439ED0: jal         0x80439E7C
    // 0x80439ED4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80439E7C(rdram, ctx);
        goto after_0;
    // 0x80439ED4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80439ED8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80439EDC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80439EE0: lui         $t9, 0x8044
    ctx->r25 = S32(RELOC_HI16(80, 0X1364) << 16);
    // 0x80439EE4: sw          $t8, 0x970($v0)
    MEM_W(0X970, ctx->r2) = ctx->r24;
    // 0x80439EE8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80439EEC: addiu       $t9, $t9, -0x61DC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(80, 0X1364));
    // 0x80439EF0: lw          $t1, 0x16C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X16C);
    // 0x80439EF4: sw          $t9, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r25;
    // 0x80439EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80439EFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80439F00: jr          $ra
    // 0x80439F04: nop

    return;
    // 0x80439F04: nop

;}
RECOMP_FUNC void func_80065368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065368: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8006536C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80065370: nop

    // 0x80065374: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80065378: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006537C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80065380: jr          $ra
    // 0x80065384: nop

    return;
    // 0x80065384: nop

;}
RECOMP_FUNC void func_800321DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800321DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800321E0: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x800321E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800321E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800321EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800321F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800321F4: addiu       $t6, $t6, 0x5284
    ctx->r14 = ADD32(ctx->r14, 0X5284);
    // 0x800321F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800321FC: jal         0x80048060
    // 0x80032200: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    func_80048060(rdram, ctx);
        goto after_0;
    // 0x80032200: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    after_0:
    // 0x80032204: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80032208: jal         0x80047F9C
    // 0x8003220C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x8003220C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80032210: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80032214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80032218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003221C: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80032220: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80032224: jal         0x8003D894
    // 0x80032228: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    func_8003D894(rdram, ctx);
        goto after_2;
    // 0x80032228: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x8003222C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80032230: addiu       $t7, $zero, 0x5DC
    ctx->r15 = ADD32(0, 0X5DC);
    // 0x80032234: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80032238: sw          $t7, 0x170($v0)
    MEM_W(0X170, ctx->r2) = ctx->r15;
    // 0x8003223C: sb          $t8, 0x155($v0)
    MEM_B(0X155, ctx->r2) = ctx->r24;
    // 0x80032240: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80032244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80032248: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003224C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80032250: jr          $ra
    // 0x80032254: nop

    return;
    // 0x80032254: nop

;}
RECOMP_FUNC void func_80799A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799A80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80799A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799A88: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80799A8C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80799A90: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80799A94: beq         $a1, $at, L_80799AB8
    if (ctx->r5 == ctx->r1) {
        // 0x80799A98: addiu       $a0, $zero, 0x49
        ctx->r4 = ADD32(0, 0X49);
            goto L_80799AB8;
    }
    // 0x80799A98: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x80799A9C: jal         0x80067930
    // 0x80799AA0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80799AA0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80799AA4: beq         $v0, $zero, L_80799AB8
    if (ctx->r2 == 0) {
        // 0x80799AA8: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80799AB8;
    }
    // 0x80799AA8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80799AAC: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x80799AB0: jal         0x80067878
    // 0x80799AB4: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x80799AB4: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    after_1:
L_80799AB8:
    // 0x80799AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80799ABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80799AC0: jr          $ra
    // 0x80799AC4: nop

    return;
    // 0x80799AC4: nop

;}
RECOMP_FUNC void func_806F7810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7810: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x806F7814: addiu       $at, $zero, 0x4300
    ctx->r1 = ADD32(0, 0X4300);
    // 0x806F7818: bne         $v0, $at, L_806F782C
    if (ctx->r2 != ctx->r1) {
        // 0x806F781C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_806F782C;
    }
    // 0x806F781C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x806F7820: lui         $v0, 0x8070
    ctx->r2 = S32(RELOC_HI16(694, 0X1808) << 16);
    // 0x806F7824: jr          $ra
    // 0x806F7828: addiu       $v0, $v0, -0x6FE8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(694, 0X1808));
    return;
    // 0x806F7828: addiu       $v0, $v0, -0x6FE8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(694, 0X1808));
L_806F782C:
    // 0x806F782C: slti        $at, $v1, 0x4299
    ctx->r1 = SIGNED(ctx->r3) < 0X4299 ? 1 : 0;
    // 0x806F7830: bne         $at, $zero, L_806F784C
    if (ctx->r1 != 0) {
        // 0x806F7834: slti        $at, $v1, 0x4300
        ctx->r1 = SIGNED(ctx->r3) < 0X4300 ? 1 : 0;
            goto L_806F784C;
    }
    // 0x806F7834: slti        $at, $v1, 0x4300
    ctx->r1 = SIGNED(ctx->r3) < 0X4300 ? 1 : 0;
    // 0x806F7838: beql        $at, $zero, L_806F7850
    if (ctx->r1 == 0) {
        // 0x806F783C: slti        $at, $v1, 0x43EB
        ctx->r1 = SIGNED(ctx->r3) < 0X43EB ? 1 : 0;
            goto L_806F7850;
    }
    goto skip_0;
    // 0x806F783C: slti        $at, $v1, 0x43EB
    ctx->r1 = SIGNED(ctx->r3) < 0X43EB ? 1 : 0;
    skip_0:
    // 0x806F7840: lui         $v0, 0x8070
    ctx->r2 = S32(RELOC_HI16(694, 0X172C) << 16);
    // 0x806F7844: jr          $ra
    // 0x806F7848: addiu       $v0, $v0, -0x70C4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(694, 0X172C));
    return;
    // 0x806F7848: addiu       $v0, $v0, -0x70C4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(694, 0X172C));
L_806F784C:
    // 0x806F784C: slti        $at, $v1, 0x43EB
    ctx->r1 = SIGNED(ctx->r3) < 0X43EB ? 1 : 0;
L_806F7850:
    // 0x806F7850: bne         $at, $zero, L_806F7868
    if (ctx->r1 != 0) {
        // 0x806F7854: slti        $at, $v1, 0x440B
        ctx->r1 = SIGNED(ctx->r3) < 0X440B ? 1 : 0;
            goto L_806F7868;
    }
    // 0x806F7854: slti        $at, $v1, 0x440B
    ctx->r1 = SIGNED(ctx->r3) < 0X440B ? 1 : 0;
    // 0x806F7858: beq         $at, $zero, L_806F7868
    if (ctx->r1 == 0) {
        // 0x806F785C: nop
    
            goto L_806F7868;
    }
    // 0x806F785C: nop

    // 0x806F7860: lui         $v0, 0x8070
    ctx->r2 = S32(RELOC_HI16(694, 0X185C) << 16);
    // 0x806F7864: addiu       $v0, $v0, -0x6F94
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(694, 0X185C));
L_806F7868:
    // 0x806F7868: jr          $ra
    // 0x806F786C: nop

    return;
    // 0x806F786C: nop

;}
RECOMP_FUNC void func_8057BC48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057BC48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057BC4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057BC50: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x8057BC54: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8057BC58: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8057BC5C: beq         $a1, $at, L_8057BC78
    if (ctx->r5 == ctx->r1) {
        // 0x8057BC60: addiu       $a0, $zero, 0x57
        ctx->r4 = ADD32(0, 0X57);
            goto L_8057BC78;
    }
    // 0x8057BC60: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    // 0x8057BC64: jal         0x80067878
    // 0x8057BC68: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8057BC68: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8057BC6C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8057BC70: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8057BC74: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_8057BC78:
    // 0x8057BC78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057BC7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057BC80: jr          $ra
    // 0x8057BC84: nop

    return;
    // 0x8057BC84: nop

;}
RECOMP_FUNC void func_805DA09C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA09C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x805DA0A0: lui         $t6, 0x805E
    ctx->r14 = S32(RELOC_HI16(477, 0XCB0) << 16);
    // 0x805DA0A4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x805DA0A8: addiu       $t6, $t6, -0x5310
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(477, 0XCB0));
    // 0x805DA0AC: sw          $t6, 0xF70($v0)
    MEM_W(0XF70, ctx->r2) = ctx->r14;
    // 0x805DA0B0: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x805DA0B4: lw          $t8, 0xF70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XF70);
    // 0x805DA0B8: jr          $ra
    // 0x805DA0BC: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    return;
    // 0x805DA0BC: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
;}
RECOMP_FUNC void func_805332DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805332DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805332E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805332E4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805332E8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x805332EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805332F0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805332F4: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805332F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805332FC: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80533300: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80533304: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80533308: nop

    // 0x8053330C: bc1fl       L_80533320
    if (!c1cs) {
        // 0x80533310: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80533320;
    }
    goto skip_0;
    // 0x80533310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80533314: jal         0x80533878
    // 0x80533318: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80533878(rdram, ctx);
        goto after_0;
    // 0x80533318: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8053331C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80533320:
    // 0x80533320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80533324: jr          $ra
    // 0x80533328: nop

    return;
    // 0x80533328: nop

;}
RECOMP_FUNC void truncf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082050: trunc.w.s   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80082054: jr          $ra
    // 0x80082058: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
    return;
    // 0x80082058: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
;}
RECOMP_FUNC void func_807A129C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A129C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807A12A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807A12A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A12A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A12AC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x807A12B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807A12B4: jal         0x807A0FFC
    // 0x807A12B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807A0FFC(rdram, ctx);
        goto after_0;
    // 0x807A12B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x807A12BC: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x807A12C0: blez        $v0, L_807A12CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807A12C4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807A12CC;
    }
    // 0x807A12C4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807A12C8: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_807A12CC:
    // 0x807A12CC: jal         0x807A10CC
    // 0x807A12D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A10CC(rdram, ctx);
        goto after_1;
    // 0x807A12D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807A12D4: beq         $v0, $zero, L_807A12F0
    if (ctx->r2 == 0) {
        // 0x807A12D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807A12F0;
    }
    // 0x807A12D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A12DC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x807A12E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A12E4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807A12E8: jal         0x807A1AE4
    // 0x807A12EC: lw          $a3, 0x68($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X68);
    func_807A1AE4(rdram, ctx);
        goto after_2;
    // 0x807A12EC: lw          $a3, 0x68($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X68);
    after_2:
L_807A12F0:
    // 0x807A12F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807A12F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807A12F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807A12FC: jr          $ra
    // 0x807A1300: nop

    return;
    // 0x807A1300: nop

;}
RECOMP_FUNC void func_80471D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471D38: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80471D3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80471D40: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80471D44: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80471D48: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80471D4C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80471D50: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80471D54: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80471D58: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80471D5C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80471D60: lui         $t1, 0x8047
    ctx->r9 = S32(RELOC_HI16(158, 0X1AA4) << 16);
    // 0x80471D64: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80471D68: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80471D6C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80471D70: lw          $t1, 0x2F64($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(158, 0X1AA4));
    // 0x80471D74: jr          $ra
    // 0x80471D78: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80471D78: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_805256DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805256DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805256E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805256E4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805256E8: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(324, 0X878) << 16);
    // 0x805256EC: lw          $t7, 0x174($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X174);
    // 0x805256F0: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x805256F4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x805256F8: lui         $t3, 0x8052
    ctx->r11 = S32(RELOC_HI16(324, 0X87C) << 16);
    // 0x805256FC: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80525700: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80525704: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80525708: lbu         $t6, 0x5D88($t6)
    ctx->r14 = MEM_BU(ctx->r14, (int16_t)RELOC_LO16(324, 0X878));
    // 0x8052570C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80525710: sll         $t8, $t0, 3
    ctx->r24 = S32(ctx->r8 << 3);
    // 0x80525714: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x80525718: lwc1        $f14, 0x4($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8052571C: lwc1        $f12, 0x0($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80525720: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x80525724: addiu       $t3, $t3, 0x5D8C
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(324, 0X87C));
    // 0x80525728: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8052572C: addu        $t1, $t2, $t3
    ctx->r9 = ADD32(ctx->r10, ctx->r11);
    // 0x80525730: lhu         $a2, 0x0($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X0);
    // 0x80525734: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80525738: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8052573C: jal         0x800538BC
    // 0x80525740: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_800538BC(rdram, ctx);
        goto after_0;
    // 0x80525740: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80525744: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80525748: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8052574C: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(324, 0X89C) << 16);
    // 0x80525750: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x80525754: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80525758: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8052575C: lwc1        $f4, 0x5DAC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(324, 0X89C));
    // 0x80525760: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80525764: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80525768: lhu         $a2, 0x2($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X2);
    // 0x8052576C: jal         0x800538BC
    // 0x80525770: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800538BC(rdram, ctx);
        goto after_1;
    // 0x80525770: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x80525774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80525778: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8052577C: jr          $ra
    // 0x80525780: nop

    return;
    // 0x80525780: nop

;}
RECOMP_FUNC void func_8007CBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CBC0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8007CBC4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007CBC8: addiu       $a0, $a0, -0x1BB8
    ctx->r4 = ADD32(ctx->r4, -0X1BB8);
    // 0x8007CBCC: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x8007CBD0: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x8007CBD4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8007CBD8: sw          $t8, -0x1B98($at)
    MEM_W(-0X1B98, ctx->r1) = ctx->r24;
    // 0x8007CBDC: sw          $t9, -0x1B94($at)
    MEM_W(-0X1B94, ctx->r1) = ctx->r25;
    // 0x8007CBE0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8007CBE4: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x8007CBE8: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x8007CBEC: sw          $t1, -0x1B9C($at)
    MEM_W(-0X1B9C, ctx->r1) = ctx->r9;
    // 0x8007CBF0: sw          $t0, -0x1BA0($at)
    MEM_W(-0X1BA0, ctx->r1) = ctx->r8;
    // 0x8007CBF4: lw          $t2, 0x20($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X20);
    // 0x8007CBF8: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x8007CBFC: lw          $t4, 0x50($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X50);
    // 0x8007CC00: lw          $t5, 0x54($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X54);
    // 0x8007CC04: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8007CC08: sw          $t4, -0x1B60($at)
    MEM_W(-0X1B60, ctx->r1) = ctx->r12;
    // 0x8007CC0C: sw          $t5, -0x1B5C($at)
    MEM_W(-0X1B5C, ctx->r1) = ctx->r13;
    // 0x8007CC10: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8007CC14: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8007CC18: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8007CC1C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8007CC20: sw          $t6, -0x1B68($at)
    MEM_W(-0X1B68, ctx->r1) = ctx->r14;
    // 0x8007CC24: sw          $t7, -0x1B64($at)
    MEM_W(-0X1B64, ctx->r1) = ctx->r15;
    // 0x8007CC28: lw          $t0, 0x58($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X58);
    // 0x8007CC2C: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8007CC30: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8007CC34: lw          $t1, 0x5C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X5C);
    // 0x8007CC38: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x8007CC3C: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x8007CC40: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007CC44: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x8007CC48: sltu        $at, $t3, $t1
    ctx->r1 = ctx->r11 < ctx->r9 ? 1 : 0;
    // 0x8007CC4C: addu        $t2, $at, $t8
    ctx->r10 = ADD32(ctx->r1, ctx->r24);
    // 0x8007CC50: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8007CC54: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8007CC58: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8007CC5C: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x8007CC60: addiu       $v0, $v0, -0x17C8
    ctx->r2 = ADD32(ctx->r2, -0X17C8);
    // 0x8007CC64: addiu       $v1, $v1, -0x1B48
    ctx->r3 = ADD32(ctx->r3, -0X1B48);
    // 0x8007CC68: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_8007CC6C:
    // 0x8007CC6C: lw          $t4, 0x18($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X18);
    // 0x8007CC70: lw          $t5, 0x1C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X1C);
    // 0x8007CC74: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8007CC78: sw          $t4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r12;
    // 0x8007CC7C: sw          $t5, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r13;
    // 0x8007CC80: sw          $t6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r14;
    // 0x8007CC84: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8007CC88: sw          $t7, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r15;
    // 0x8007CC8C: lw          $t0, 0x20($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X20);
    // 0x8007CC90: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
    // 0x8007CC94: lw          $t4, 0x50($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X50);
    // 0x8007CC98: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8007CC9C: lw          $t5, 0x54($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X54);
    // 0x8007CCA0: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007CCA4: sw          $t4, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r12;
    // 0x8007CCA8: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x8007CCAC: sltu        $at, $t3, $t1
    ctx->r1 = ctx->r11 < ctx->r9 ? 1 : 0;
    // 0x8007CCB0: sw          $t5, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r13;
    // 0x8007CCB4: sw          $t6, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r14;
    // 0x8007CCB8: addu        $t2, $at, $t8
    ctx->r10 = ADD32(ctx->r1, ctx->r24);
    // 0x8007CCBC: sw          $t7, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r15;
    // 0x8007CCC0: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8007CCC4: lw          $t0, 0x58($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X58);
    // 0x8007CCC8: lw          $t1, 0x5C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X5C);
    // 0x8007CCCC: lw          $t4, 0x88($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X88);
    // 0x8007CCD0: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8007CCD4: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8007CCD8: lw          $t5, 0x8C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8C);
    // 0x8007CCDC: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x8007CCE0: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007CCE4: sw          $t4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r12;
    // 0x8007CCE8: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x8007CCEC: sltu        $at, $t3, $t1
    ctx->r1 = ctx->r11 < ctx->r9 ? 1 : 0;
    // 0x8007CCF0: sw          $t5, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->r13;
    // 0x8007CCF4: sw          $t6, 0x88($v1)
    MEM_W(0X88, ctx->r3) = ctx->r14;
    // 0x8007CCF8: addu        $t2, $at, $t8
    ctx->r10 = ADD32(ctx->r1, ctx->r24);
    // 0x8007CCFC: sw          $t7, 0x8C($v1)
    MEM_W(0X8C, ctx->r3) = ctx->r15;
    // 0x8007CD00: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8007CD04: lw          $t0, 0x90($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X90);
    // 0x8007CD08: lw          $t1, 0x94($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X94);
    // 0x8007CD0C: lw          $t4, 0xC0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC0);
    // 0x8007CD10: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8007CD14: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8007CD18: lw          $t5, 0xC4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC4);
    // 0x8007CD1C: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x8007CD20: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007CD24: sw          $t4, 0xC8($v1)
    MEM_W(0XC8, ctx->r3) = ctx->r12;
    // 0x8007CD28: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x8007CD2C: sltu        $at, $t3, $t1
    ctx->r1 = ctx->r11 < ctx->r9 ? 1 : 0;
    // 0x8007CD30: sw          $t5, 0xCC($v1)
    MEM_W(0XCC, ctx->r3) = ctx->r13;
    // 0x8007CD34: sw          $t6, 0xC0($v1)
    MEM_W(0XC0, ctx->r3) = ctx->r14;
    // 0x8007CD38: addu        $t2, $at, $t8
    ctx->r10 = ADD32(ctx->r1, ctx->r24);
    // 0x8007CD3C: sw          $t7, 0xC4($v1)
    MEM_W(0XC4, ctx->r3) = ctx->r15;
    // 0x8007CD40: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8007CD44: lw          $t0, 0xC8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC8);
    // 0x8007CD48: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8007CD4C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8007CD50: lw          $t1, 0xCC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XCC);
    // 0x8007CD54: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x8007CD58: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007CD5C: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x8007CD60: sltu        $at, $t3, $t1
    ctx->r1 = ctx->r11 < ctx->r9 ? 1 : 0;
    // 0x8007CD64: addu        $t2, $at, $t8
    ctx->r10 = ADD32(ctx->r1, ctx->r24);
    // 0x8007CD68: addiu       $v1, $v1, 0xE0
    ctx->r3 = ADD32(ctx->r3, 0XE0);
    // 0x8007CD6C: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8007CD70: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x8007CD74: bne         $v1, $v0, L_8007CC6C
    if (ctx->r3 != ctx->r2) {
        // 0x8007CD78: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_8007CC6C;
    }
    // 0x8007CD78: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8007CD7C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8007CD80: addiu       $t6, $t6, -0x1C60
    ctx->r14 = ADD32(ctx->r14, -0X1C60);
    // 0x8007CD84: sw          $t2, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r10;
    // 0x8007CD88: sw          $t3, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r11;
    // 0x8007CD8C: jr          $ra
    // 0x8007CD90: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8007CD90: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8007CD94: nop

    // 0x8007CD98: nop

    // 0x8007CD9C: nop

;}
RECOMP_FUNC void func_80519D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80519D24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80519D28: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80519D2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80519D30: beq         $a1, $at, L_80519D5C
    if (ctx->r5 == ctx->r1) {
        // 0x80519D34: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80519D5C;
    }
    // 0x80519D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80519D38: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80519D3C: beq         $a1, $at, L_80519DC0
    if (ctx->r5 == ctx->r1) {
        // 0x80519D40: addiu       $at, $zero, 0x69
        ctx->r1 = ADD32(0, 0X69);
            goto L_80519DC0;
    }
    // 0x80519D40: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x80519D44: beq         $a1, $at, L_80519DAC
    if (ctx->r5 == ctx->r1) {
        // 0x80519D48: addiu       $at, $zero, 0x6B
        ctx->r1 = ADD32(0, 0X6B);
            goto L_80519DAC;
    }
    // 0x80519D48: addiu       $at, $zero, 0x6B
    ctx->r1 = ADD32(0, 0X6B);
    // 0x80519D4C: beq         $a1, $at, L_80519DD0
    if (ctx->r5 == ctx->r1) {
        // 0x80519D50: nop
    
            goto L_80519DD0;
    }
    // 0x80519D50: nop

    // 0x80519D54: b           L_80519DDC
    // 0x80519D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80519DDC;
    // 0x80519D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80519D5C:
    // 0x80519D5C: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    // 0x80519D60: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80519D64: beq         $a1, $at, L_80519D7C
    if (ctx->r5 == ctx->r1) {
        // 0x80519D68: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80519D7C;
    }
    // 0x80519D68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80519D6C: beq         $a1, $at, L_80519D8C
    if (ctx->r5 == ctx->r1) {
        // 0x80519D70: nop
    
            goto L_80519D8C;
    }
    // 0x80519D70: nop

    // 0x80519D74: b           L_80519D9C
    // 0x80519D78: nop

        goto L_80519D9C;
    // 0x80519D78: nop

L_80519D7C:
    // 0x80519D7C: jal         0x805196C8
    // 0x80519D80: nop

    func_805196C8(rdram, ctx);
        goto after_0;
    // 0x80519D80: nop

    after_0:
    // 0x80519D84: b           L_80519DDC
    // 0x80519D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80519DDC;
    // 0x80519D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80519D8C:
    // 0x80519D8C: jal         0x80519C5C
    // 0x80519D90: nop

    func_80519C5C(rdram, ctx);
        goto after_1;
    // 0x80519D90: nop

    after_1:
    // 0x80519D94: b           L_80519DDC
    // 0x80519D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80519DDC;
    // 0x80519D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80519D9C:
    // 0x80519D9C: jal         0x80519AFC
    // 0x80519DA0: lw          $a2, 0x12C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X12C);
    func_80519AFC(rdram, ctx);
        goto after_2;
    // 0x80519DA0: lw          $a2, 0x12C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X12C);
    after_2:
    // 0x80519DA4: b           L_80519DDC
    // 0x80519DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80519DDC;
    // 0x80519DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80519DAC:
    // 0x80519DAC: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    // 0x80519DB0: jal         0x80519B54
    // 0x80519DB4: lw          $a2, 0x12C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X12C);
    func_80519B54(rdram, ctx);
        goto after_3;
    // 0x80519DB4: lw          $a2, 0x12C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X12C);
    after_3:
    // 0x80519DB8: b           L_80519DDC
    // 0x80519DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80519DDC;
    // 0x80519DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80519DC0:
    // 0x80519DC0: jal         0x80519BE4
    // 0x80519DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80519BE4(rdram, ctx);
        goto after_4;
    // 0x80519DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80519DC8: b           L_80519DDC
    // 0x80519DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80519DDC;
    // 0x80519DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80519DD0:
    // 0x80519DD0: jal         0x80517D80
    // 0x80519DD4: nop

    func_80517D80(rdram, ctx);
        goto after_5;
    // 0x80519DD4: nop

    after_5:
    // 0x80519DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80519DDC:
    // 0x80519DDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80519DE0: jr          $ra
    // 0x80519DE4: nop

    return;
    // 0x80519DE4: nop

;}
RECOMP_FUNC void func_80581B84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581B84: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80581B88: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80581B8C: lw          $t6, 0x478($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X478);
    // 0x80581B90: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X47F4) << 16);
    // 0x80581B94: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80581B98: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80581B9C: swc1        $f0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f0.u32l;
    // 0x80581BA0: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x80581BA4: lw          $t7, 0x478($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X478);
    // 0x80581BA8: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80581BAC: swc1        $f0, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f0.u32l;
    // 0x80581BB0: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x80581BB4: lw          $t8, 0x478($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X478);
    // 0x80581BB8: lwc1        $f6, 0x3604($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X47F4));
    // 0x80581BBC: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X47F8) << 16);
    // 0x80581BC0: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80581BC4: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80581BC8: swc1        $f0, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f0.u32l;
    // 0x80581BCC: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x80581BD0: lwc1        $f8, 0x3608($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X47F8));
    // 0x80581BD4: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X47FC) << 16);
    // 0x80581BD8: swc1        $f8, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f8.u32l;
    // 0x80581BDC: lwc1        $f10, 0x360C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X47FC));
    // 0x80581BE0: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X4800) << 16);
    // 0x80581BE4: swc1        $f10, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f10.u32l;
    // 0x80581BE8: lwc1        $f16, 0x3610($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X4800));
    // 0x80581BEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80581BF0: swc1        $f16, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->f16.u32l;
    // 0x80581BF4: jr          $ra
    // 0x80581BF8: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    return;
    // 0x80581BF8: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void func_805178E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805178E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805178EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805178F0: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x805178F4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x805178F8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805178FC: lui         $t8, 0x8051
    ctx->r24 = S32(RELOC_HI16(288, 0X5BC) << 16);
    // 0x80517900: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80517904: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80517908: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8051790C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80517910: lw          $t8, 0x7B3C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(288, 0X5BC));
    // 0x80517914: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80517918: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8051791C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80517920: jal         0x80048490
    // 0x80517924: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80517924: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80517928: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8051792C: jal         0x80048378
    // 0x80517930: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80517930: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80517934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80517938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051793C: jr          $ra
    // 0x80517940: nop

    return;
    // 0x80517940: nop

;}
RECOMP_FUNC void func_806D3ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D3ADC: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x806D3AE0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x806D3AE4: lui         $a1, 0x806D
    ctx->r5 = S32(RELOC_HI16(616, 0X994) << 16);
    // 0x806D3AE8: addiu       $a1, $a1, 0x3944
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(616, 0X994));
    // 0x806D3AEC: beq         $a1, $a2, L_806D3B2C
    if (ctx->r5 == ctx->r6) {
        // 0x806D3AF0: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_806D3B2C;
    }
    // 0x806D3AF0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D3AF4: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x806D3AF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806D3AFC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806D3B00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D3B04: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806D3B08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806D3B0C: sw          $a2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r6;
    // 0x806D3B10: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x806D3B14: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x806D3B18: swc1        $f6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f6.u32l;
    // 0x806D3B1C: swc1        $f8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f8.u32l;
    // 0x806D3B20: sw          $a1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r5;
    // 0x806D3B24: sh          $zero, 0x24($v0)
    MEM_H(0X24, ctx->r2) = 0;
    // 0x806D3B28: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_806D3B2C:
    // 0x806D3B2C: jr          $ra
    // 0x806D3B30: nop

    return;
    // 0x806D3B30: nop

;}
RECOMP_FUNC void func_805368BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805368BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805368C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805368C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805368C8: lw          $v1, 0x1F4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X1F4);
    // 0x805368CC: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x805368D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805368D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x805368D8: lw          $v0, 0x6D9C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D9C);
    // 0x805368DC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805368E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805368E4: bne         $v0, $zero, L_80536914
    if (ctx->r2 != 0) {
        // 0x805368E8: nop
    
            goto L_80536914;
    }
    // 0x805368E8: nop

    // 0x805368EC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x805368F0: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x805368F4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805368F8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x805368FC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80536900: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80536904: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80536908: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053690C: b           L_805369C4
    // 0x80536910: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
        goto L_805369C4;
    // 0x80536910: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
L_80536914:
    // 0x80536914: bne         $v0, $at, L_8053692C
    if (ctx->r2 != ctx->r1) {
        // 0x80536918: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8053692C;
    }
    // 0x80536918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8053691C: jal         0x80536174
    // 0x80536920: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    func_80536174(rdram, ctx);
        goto after_0;
    // 0x80536920: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    after_0:
    // 0x80536924: b           L_805369C8
    // 0x80536928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805369C8;
    // 0x80536928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8053692C:
    // 0x8053692C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80536930: bne         $v0, $at, L_80536948
    if (ctx->r2 != ctx->r1) {
        // 0x80536934: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80536948;
    }
    // 0x80536934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80536938: jal         0x805361A4
    // 0x8053693C: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    func_805361A4(rdram, ctx);
        goto after_1;
    // 0x8053693C: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    after_1:
    // 0x80536940: b           L_805369C8
    // 0x80536944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805369C8;
    // 0x80536944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80536948:
    // 0x80536948: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8053694C: bne         $v0, $at, L_80536964
    if (ctx->r2 != ctx->r1) {
        // 0x80536950: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80536964;
    }
    // 0x80536950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80536954: jal         0x805361D4
    // 0x80536958: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    func_805361D4(rdram, ctx);
        goto after_2;
    // 0x80536958: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_2:
    // 0x8053695C: b           L_805369C8
    // 0x80536960: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805369C8;
    // 0x80536960: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80536964:
    // 0x80536964: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80536968: bne         $v0, $at, L_80536980
    if (ctx->r2 != ctx->r1) {
        // 0x8053696C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80536980;
    }
    // 0x8053696C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80536970: jal         0x80536204
    // 0x80536974: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    func_80536204(rdram, ctx);
        goto after_3;
    // 0x80536974: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    after_3:
    // 0x80536978: b           L_805369C8
    // 0x8053697C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805369C8;
    // 0x8053697C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80536980:
    // 0x80536980: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80536984: bne         $v0, $at, L_8053699C
    if (ctx->r2 != ctx->r1) {
        // 0x80536988: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8053699C;
    }
    // 0x80536988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8053698C: jal         0x80536234
    // 0x80536990: addiu       $a2, $zero, 0x25
    ctx->r6 = ADD32(0, 0X25);
    func_80536234(rdram, ctx);
        goto after_4;
    // 0x80536990: addiu       $a2, $zero, 0x25
    ctx->r6 = ADD32(0, 0X25);
    after_4:
    // 0x80536994: b           L_805369C8
    // 0x80536998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805369C8;
    // 0x80536998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8053699C:
    // 0x8053699C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x805369A0: bne         $v0, $at, L_805369BC
    if (ctx->r2 != ctx->r1) {
        // 0x805369A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805369BC;
    }
    // 0x805369A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805369A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805369AC: jal         0x80536264
    // 0x805369B0: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    func_80536264(rdram, ctx);
        goto after_5;
    // 0x805369B0: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    after_5:
    // 0x805369B4: b           L_805369C8
    // 0x805369B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805369C8;
    // 0x805369B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805369BC:
    // 0x805369BC: jal         0x80536294
    // 0x805369C0: addiu       $a2, $zero, 0x27
    ctx->r6 = ADD32(0, 0X27);
    func_80536294(rdram, ctx);
        goto after_6;
    // 0x805369C0: addiu       $a2, $zero, 0x27
    ctx->r6 = ADD32(0, 0X27);
    after_6:
L_805369C4:
    // 0x805369C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805369C8:
    // 0x805369C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805369CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805369D0: jr          $ra
    // 0x805369D4: nop

    return;
    // 0x805369D4: nop

;}
RECOMP_FUNC void func_80519454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519454: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80519458: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8051945C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80519460: jal         0x8004700C
    // 0x80519464: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80519464: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80519468: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8051946C: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(291, 0X25FC) << 16);
    // 0x80519470: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80519474: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x80519478: beq         $v0, $zero, L_80519580
    if (ctx->r2 == 0) {
        // 0x8051947C: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_80519580;
    }
    // 0x8051947C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80519480: lwc1        $f6, 0x8C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x80519484: lwc1        $f8, -0x5D94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(291, 0X25FC));
    // 0x80519488: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8051948C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80519490: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80519494: jal         0x80518C44
    // 0x80519498: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    func_80518C44(rdram, ctx);
        goto after_1;
    // 0x80519498: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8051949C: jal         0x80519124
    // 0x805194A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80519124(rdram, ctx);
        goto after_2;
    // 0x805194A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805194A4: jal         0x80517DB0
    // 0x805194A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80517DB0(rdram, ctx);
        goto after_3;
    // 0x805194A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805194AC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805194B0: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x805194B4: bnel        $t7, $zero, L_80519508
    if (ctx->r15 != 0) {
        // 0x805194B8: lwc1        $f2, 0x28($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80519508;
    }
    goto skip_0;
    // 0x805194B8: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x805194BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805194C0: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x805194C4: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805194C8: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x805194CC: nop

    // 0x805194D0: bc1fl       L_80519508
    if (!c1cs) {
        // 0x805194D4: lwc1        $f2, 0x28($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80519508;
    }
    goto skip_1;
    // 0x805194D4: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x805194D8: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x805194DC: nop

    // 0x805194E0: bc1fl       L_80519508
    if (!c1cs) {
        // 0x805194E4: lwc1        $f2, 0x28($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80519508;
    }
    goto skip_2;
    // 0x805194E4: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x805194E8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805194EC: jal         0x80067BBC
    // 0x805194F0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x805194F0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x805194F4: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x805194F8: jal         0x80067818
    // 0x805194FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x805194FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80519500: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80519504: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
L_80519508:
    // 0x80519508: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8051950C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80519510: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x80519514: nop

    // 0x80519518: bc1fl       L_80519584
    if (!c1cs) {
        // 0x8051951C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80519584;
    }
    goto skip_3;
    // 0x8051951C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80519520: swc1        $f0, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f0.u32l;
    // 0x80519524: swc1        $f0, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f0.u32l;
    // 0x80519528: swc1        $f2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f2.u32l;
    // 0x8051952C: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80519530: andi        $t9, $t8, 0xF00
    ctx->r25 = ctx->r24 & 0XF00;
    // 0x80519534: beql        $t9, $zero, L_80519584
    if (ctx->r25 == 0) {
        // 0x80519538: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80519584;
    }
    goto skip_4;
    // 0x80519538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8051953C: lbu         $t0, 0x11($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X11);
    // 0x80519540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80519544: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x80519548: bnel        $at, $zero, L_80519564
    if (ctx->r1 != 0) {
        // 0x8051954C: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_80519564;
    }
    goto skip_5;
    // 0x8051954C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    skip_5:
    // 0x80519550: jal         0x805193B4
    // 0x80519554: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_805193B4(rdram, ctx);
        goto after_6;
    // 0x80519554: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80519558: b           L_80519584
    // 0x8051955C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80519584;
    // 0x8051955C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80519560: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
L_80519564:
    // 0x80519564: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80519568: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8051956C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80519570: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80519574: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x80519578: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8051957C: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
L_80519580:
    // 0x80519580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80519584:
    // 0x80519584: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80519588: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8051958C: jr          $ra
    // 0x80519590: nop

    return;
    // 0x80519590: nop

;}
RECOMP_FUNC void func_8040EC00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EC00: lwc1        $f4, 0xDC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x8040EC04: lwc1        $f8, 0xC4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8040EC08: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8040EC0C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8040EC10: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8040EC14: nop

    // 0x8040EC18: bc1t        L_8040EC30
    if (c1cs) {
        // 0x8040EC1C: nop
    
            goto L_8040EC30;
    }
    // 0x8040EC1C: nop

    // 0x8040EC20: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8040EC24: lwc1        $f16, 0x24($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8040EC28: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8040EC2C: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_8040EC30:
    // 0x8040EC30: jr          $ra
    // 0x8040EC34: nop

    return;
    // 0x8040EC34: nop

;}
RECOMP_FUNC void func_80536A78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536A78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80536A7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80536A80: jal         0x805367A4
    // 0x80536A84: nop

    func_805367A4(rdram, ctx);
        goto after_0;
    // 0x80536A84: nop

    after_0:
    // 0x80536A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80536A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80536A90: jr          $ra
    // 0x80536A94: nop

    return;
    // 0x80536A94: nop

;}
RECOMP_FUNC void func_80066894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066894: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006689C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800668A0: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800668A4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800668A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800668AC: jal         0x80065954
    // 0x800668B0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x800668B0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x800668B4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800668B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800668BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800668C0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800668C4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800668C8: nop

    // 0x800668CC: bc1fl       L_80066920
    if (!c1cs) {
        // 0x800668D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80066920;
    }
    goto skip_0;
    // 0x800668D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800668D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800668D8: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800668DC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800668E0: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800668E4: nop

    // 0x800668E8: bc1fl       L_8006690C
    if (!c1cs) {
        // 0x800668EC: lwc1        $f8, 0x0($a1)
        ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
            goto L_8006690C;
    }
    goto skip_1;
    // 0x800668EC: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    skip_1:
    // 0x800668F0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800668F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800668F8: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800668FC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80066900: b           L_8006691C
    // 0x80066904: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_8006691C;
    // 0x80066904: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80066908: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
L_8006690C:
    // 0x8006690C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80066910: nop

    // 0x80066914: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80066918: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
L_8006691C:
    // 0x8006691C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80066920:
    // 0x80066920: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066924: jr          $ra
    // 0x80066928: nop

    return;
    // 0x80066928: nop

;}
RECOMP_FUNC void func_8044FD5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044FD5C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8044FD60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044FD64: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044FD68: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8044FD6C: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x8044FD70: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8044FD74: lw          $v1, 0x6A28($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6A28);
    // 0x8044FD78: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044FD7C: lui         $t8, 0x8045
    ctx->r24 = S32(RELOC_HI16(98, 0X1370C) << 16);
    // 0x8044FD80: bne         $v1, $at, L_8044FD98
    if (ctx->r3 != ctx->r1) {
        // 0x8044FD84: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_8044FD98;
    }
    // 0x8044FD84: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8044FD88: jal         0x8044F424
    // 0x8044FD8C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8044F424(rdram, ctx);
        goto after_0;
    // 0x8044FD8C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8044FD90: b           L_8044FDEC
    // 0x8044FD94: nop

        goto L_8044FDEC;
    // 0x8044FD94: nop

L_8044FD98:
    // 0x8044FD98: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8044FD9C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8044FDA0: addiu       $t7, $t6, 0x6
    ctx->r15 = ADD32(ctx->r14, 0X6);
    // 0x8044FDA4: addiu       $t8, $t8, 0x7AEC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(98, 0X1370C));
    // 0x8044FDA8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8044FDAC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8044FDB0: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x8044FDB4: lbu         $t0, 0x1($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X1);
    // 0x8044FDB8: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x8044FDBC: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x8044FDC0: addu        $v0, $a0, $t1
    ctx->r2 = ADD32(ctx->r4, ctx->r9);
    // 0x8044FDC4: sb          $t9, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r25;
    // 0x8044FDC8: sb          $t0, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r8;
    // 0x8044FDCC: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
    // 0x8044FDD0: lbu         $t4, 0x2($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X2);
    // 0x8044FDD4: lbu         $t5, 0x3($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3);
    // 0x8044FDD8: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x8044FDDC: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    // 0x8044FDE0: sb          $t4, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r12;
    // 0x8044FDE4: sb          $t5, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r13;
    // 0x8044FDE8: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
L_8044FDEC:
    // 0x8044FDEC: jal         0x80046E88
    // 0x8044FDF0: addiu       $a0, $zero, 0x450C
    ctx->r4 = ADD32(0, 0X450C);
    func_80046E88(rdram, ctx);
        goto after_1;
    // 0x8044FDF0: addiu       $a0, $zero, 0x450C
    ctx->r4 = ADD32(0, 0X450C);
    after_1:
    // 0x8044FDF4: beq         $v0, $zero, L_8044FE30
    if (ctx->r2 == 0) {
        // 0x8044FDF8: lbu         $t6, 0x2C($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X2C);
            goto L_8044FE30;
    }
    // 0x8044FDF8: lbu         $t6, 0x2C($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2C);
    // 0x8044FDFC: lw          $v1, 0x16C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X16C);
    // 0x8044FE00: sb          $t6, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r14;
    // 0x8044FE04: lbu         $t7, 0x2D($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2D);
    // 0x8044FE08: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x8044FE0C: sb          $t7, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r15;
    // 0x8044FE10: lbu         $t8, 0x2E($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2E);
    // 0x8044FE14: sb          $t8, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r24;
    // 0x8044FE18: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
    // 0x8044FE1C: sb          $t9, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r25;
    // 0x8044FE20: lbu         $t0, 0x30($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X30);
    // 0x8044FE24: sb          $t0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r8;
    // 0x8044FE28: lbu         $t1, 0x31($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X31);
    // 0x8044FE2C: sb          $t1, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r9;
L_8044FE30:
    // 0x8044FE30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044FE34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8044FE38: jr          $ra
    // 0x8044FE3C: nop

    return;
    // 0x8044FE3C: nop

;}
RECOMP_FUNC void func_804B7E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B7E74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804B7E78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B7E7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B7E80: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x804B7E84: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x804B7E88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804B7E8C: bne         $a1, $at, L_804B7EB0
    if (ctx->r5 != ctx->r1) {
        // 0x804B7E90: nop
    
            goto L_804B7EB0;
    }
    // 0x804B7E90: nop

    // 0x804B7E94: jal         0x80067E78
    // 0x804B7E98: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067E78(rdram, ctx);
        goto after_0;
    // 0x804B7E98: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x804B7E9C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x804B7EA0: jal         0x80067F78
    // 0x804B7EA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x804B7EA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x804B7EA8: b           L_804B7F00
    // 0x804B7EAC: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_804B7F00;
    // 0x804B7EAC: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_804B7EB0:
    // 0x804B7EB0: jal         0x80067930
    // 0x804B7EB4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80067930(rdram, ctx);
        goto after_2;
    // 0x804B7EB4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_2:
    // 0x804B7EB8: beq         $v0, $zero, L_804B7EE8
    if (ctx->r2 == 0) {
        // 0x804B7EBC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_804B7EE8;
    }
    // 0x804B7EBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804B7EC0: bnel        $v0, $at, L_804B7F04
    if (ctx->r2 != ctx->r1) {
        // 0x804B7EC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804B7F04;
    }
    goto skip_0;
    // 0x804B7EC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804B7EC8: jal         0x80067E78
    // 0x804B7ECC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067E78(rdram, ctx);
        goto after_3;
    // 0x804B7ECC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x804B7ED0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x804B7ED4: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x804B7ED8: jal         0x800678F0
    // 0x804B7EDC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x804B7EDC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x804B7EE0: b           L_804B7F04
    // 0x804B7EE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804B7F04;
    // 0x804B7EE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B7EE8:
    // 0x804B7EE8: jal         0x80067E78
    // 0x804B7EEC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067E78(rdram, ctx);
        goto after_5;
    // 0x804B7EEC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_5:
    // 0x804B7EF0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x804B7EF4: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x804B7EF8: jal         0x80067838
    // 0x804B7EFC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_6;
    // 0x804B7EFC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
L_804B7F00:
    // 0x804B7F00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B7F04:
    // 0x804B7F04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B7F08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804B7F0C: jr          $ra
    // 0x804B7F10: nop

    return;
    // 0x804B7F10: nop

;}
RECOMP_FUNC void func_804467BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804467BC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804467C0: addiu       $t6, $zero, 0xAC8
    ctx->r14 = ADD32(0, 0XAC8);
    // 0x804467C4: jr          $ra
    // 0x804467C8: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
    return;
    // 0x804467C8: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8003BBF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BBF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003BBF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003BBFC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8003BC00: addiu       $t6, $zero, 0x401C
    ctx->r14 = ADD32(0, 0X401C);
    // 0x8003BC04: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x8003BC08: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8003BC0C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8003BC10: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003BC14: jal         0x8003BB94
    // 0x8003BC18: lw          $a3, 0x4274($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4274);
    func_8003BB94(rdram, ctx);
        goto after_0;
    // 0x8003BC18: lw          $a3, 0x4274($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4274);
    after_0:
    // 0x8003BC1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BC20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003BC24: jr          $ra
    // 0x8003BC28: nop

    return;
    // 0x8003BC28: nop

;}
RECOMP_FUNC void func_805A7460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A7460: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A7464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A7468: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A746C: lh          $t6, 0x1F0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1F0);
    // 0x805A7470: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805A7474: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A7478: bnel        $t6, $at, L_805A74A4
    if (ctx->r14 != ctx->r1) {
        // 0x805A747C: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_805A74A4;
    }
    goto skip_0;
    // 0x805A747C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x805A7480: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805A7484: jal         0x80067BBC
    // 0x805A7488: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805A7488: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x805A748C: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x805A7490: jal         0x80067F78
    // 0x805A7494: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x805A7494: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805A7498: b           L_805A74BC
    // 0x805A749C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_805A74BC;
    // 0x805A749C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x805A74A0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_805A74A4:
    // 0x805A74A4: jal         0x80067BBC
    // 0x805A74A8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x805A74A8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x805A74AC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x805A74B0: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x805A74B4: jal         0x800678F0
    // 0x805A74B8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x805A74B8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_805A74BC:
    // 0x805A74BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A74C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A74C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A74C8: jr          $ra
    // 0x805A74CC: nop

    return;
    // 0x805A74CC: nop

;}
RECOMP_FUNC void func_805198A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805198A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805198A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805198A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805198AC: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x805198B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805198B4: bnel        $t6, $zero, L_805198D4
    if (ctx->r14 != 0) {
        // 0x805198B8: lwc1        $f12, 0xC8($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_805198D4;
    }
    goto skip_0;
    // 0x805198B8: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    skip_0:
    // 0x805198BC: jal         0x8004700C
    // 0x805198C0: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805198C0: nop

    after_0:
    // 0x805198C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805198C8: jal         0x805193B4
    // 0x805198CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_805193B4(rdram, ctx);
        goto after_1;
    // 0x805198CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805198D0: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
L_805198D4:
    // 0x805198D4: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x805198D8: jal         0x80065ABC
    // 0x805198DC: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_2;
    // 0x805198DC: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_2:
    // 0x805198E0: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x805198E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805198E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805198EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805198F0: jr          $ra
    // 0x805198F4: nop

    return;
    // 0x805198F4: nop

;}
RECOMP_FUNC void func_807A70DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A70DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A70E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A70E4: jal         0x807A7098
    // 0x807A70E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807A7098(rdram, ctx);
        goto after_0;
    // 0x807A70E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807A70EC: bne         $v0, $zero, L_807A7104
    if (ctx->r2 != 0) {
        // 0x807A70F0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807A7104;
    }
    // 0x807A70F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807A70F4: jal         0x800447C8
    // 0x807A70F8: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x807A70F8: nop

    after_1:
    // 0x807A70FC: b           L_807A712C
    // 0x807A7100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807A712C;
    // 0x807A7100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A7104:
    // 0x807A7104: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807A7108: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807A710C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x807A7110: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807A7114: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807A7118: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x807A711C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A7120: jal         0x807A7138
    // 0x807A7124: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_807A7138(rdram, ctx);
        goto after_2;
    // 0x807A7124: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x807A7128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A712C:
    // 0x807A712C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A7130: jr          $ra
    // 0x807A7134: nop

    return;
    // 0x807A7134: nop

;}
RECOMP_FUNC void func_80580494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580494: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8058049C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805804A0: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x805804A4: lui         $t8, 0x8058
    ctx->r24 = S32(RELOC_HI16(399, 0X454C) << 16);
    // 0x805804A8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805804AC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805804B0: lw          $t8, 0x335C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(399, 0X454C));
    // 0x805804B4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805804B8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x805804BC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x805804C0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x805804C4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x805804C8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x805804CC: beql        $v1, $zero, L_80580500
    if (ctx->r3 == 0) {
        // 0x805804D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80580500;
    }
    goto skip_0;
    // 0x805804D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805804D4: jalr        $v1
    // 0x805804D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x805804D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805804DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805804E0: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x805804E4: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x805804E8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x805804EC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x805804F0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x805804F4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x805804F8: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x805804FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80580500:
    // 0x80580500: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80580504: jr          $ra
    // 0x80580508: nop

    return;
    // 0x80580508: nop

;}
RECOMP_FUNC void func_804D65A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D65A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D65A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D65A8: jal         0x80059278
    // 0x804D65AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80059278(rdram, ctx);
        goto after_0;
    // 0x804D65AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804D65B0: bnel        $v0, $zero, L_804D65CC
    if (ctx->r2 != 0) {
        // 0x804D65B4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_804D65CC;
    }
    goto skip_0;
    // 0x804D65B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x804D65B8: jal         0x800447C8
    // 0x804D65BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x804D65BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804D65C0: b           L_804D65CC
    // 0x804D65C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804D65CC;
    // 0x804D65C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804D65C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804D65CC:
    // 0x804D65CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D65D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D65D4: jr          $ra
    // 0x804D65D8: nop

    return;
    // 0x804D65D8: nop

;}
RECOMP_FUNC void func_8005AD30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AD30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005AD34: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005AD38: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005AD3C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8005AD40: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005AD44: jal         0x8005AB3C
    // 0x8005AD48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    func_8005AB3C(rdram, ctx);
        goto after_0;
    // 0x8005AD48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x8005AD4C: bne         $v0, $zero, L_8005AD5C
    if (ctx->r2 != 0) {
        // 0x8005AD50: sw          $v0, 0x3C($s2)
        MEM_W(0X3C, ctx->r18) = ctx->r2;
            goto L_8005AD5C;
    }
    // 0x8005AD50: sw          $v0, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r2;
    // 0x8005AD54: b           L_8005AE28
    // 0x8005AD58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005AE28;
    // 0x8005AD58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005AD5C:
    // 0x8005AD5C: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x8005AD60: lbu         $t6, 0x4($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X4);
    // 0x8005AD64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005AD68: bnel        $t6, $at, L_8005AD88
    if (ctx->r14 != ctx->r1) {
        // 0x8005AD6C: lw          $a0, 0xC($s0)
        ctx->r4 = MEM_W(ctx->r16, 0XC);
            goto L_8005AD88;
    }
    goto skip_0;
    // 0x8005AD6C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x8005AD70: lbu         $t7, 0xA($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XA);
    // 0x8005AD74: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005AD78: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x8005AD7C: b           L_8005AE20
    // 0x8005AD80: lw          $s1, 0xC($t9)
    ctx->r17 = MEM_W(ctx->r25, 0XC);
        goto L_8005AE20;
    // 0x8005AD80: lw          $s1, 0xC($t9)
    ctx->r17 = MEM_W(ctx->r25, 0XC);
    // 0x8005AD84: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
L_8005AD88:
    // 0x8005AD88: sll         $t0, $a0, 4
    ctx->r8 = S32(ctx->r4 << 4);
    // 0x8005AD8C: srl         $t1, $t0, 28
    ctx->r9 = S32(U32(ctx->r8) >> 28);
    // 0x8005AD90: bne         $t1, $zero, L_8005AE10
    if (ctx->r9 != 0) {
        // 0x8005AD94: nop
    
            goto L_8005AE10;
    }
    // 0x8005AD94: nop

    // 0x8005AD98: lh          $t2, 0x32($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X32);
    // 0x8005AD9C: lh          $t3, 0x30($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X30);
    // 0x8005ADA0: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005ADA4: mflo        $a0
    ctx->r4 = lo;
    // 0x8005ADA8: jal         0x80064DD0
    // 0x8005ADAC: nop

    func_80064DD0(rdram, ctx);
        goto after_1;
    // 0x8005ADAC: nop

    after_1:
    // 0x8005ADB0: bne         $v0, $zero, L_8005ADD0
    if (ctx->r2 != 0) {
        // 0x8005ADB4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8005ADD0;
    }
    // 0x8005ADB4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8005ADB8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005ADBC: addiu       $a0, $a0, 0xC20
    ctx->r4 = ADD32(ctx->r4, 0XC20);
    // 0x8005ADC0: jal         0x80071380
    // 0x8005ADC4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x8005ADC4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_2:
    // 0x8005ADC8: b           L_8005AE28
    // 0x8005ADCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005AE28;
    // 0x8005ADCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005ADD0:
    // 0x8005ADD0: lw          $t4, 0x1C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C);
    // 0x8005ADD4: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8005ADD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005ADDC: addiu       $a1, $s2, 0x30
    ctx->r5 = ADD32(ctx->r18, 0X30);
    // 0x8005ADE0: addiu       $a2, $s0, 0x6
    ctx->r6 = ADD32(ctx->r16, 0X6);
    // 0x8005ADE4: jal         0x8006BDA4
    // 0x8005ADE8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_8006BDA4(rdram, ctx);
        goto after_3;
    // 0x8005ADE8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x8005ADEC: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8005ADF0: jal         0x800509EC
    // 0x8005ADF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800509EC(rdram, ctx);
        goto after_4;
    // 0x8005ADF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8005ADF8: beql        $v0, $zero, L_8005AE24
    if (ctx->r2 == 0) {
        // 0x8005ADFC: sw          $s1, 0x38($s2)
        MEM_W(0X38, ctx->r18) = ctx->r17;
            goto L_8005AE24;
    }
    goto skip_1;
    // 0x8005ADFC: sw          $s1, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r17;
    skip_1:
    // 0x8005AE00: jal         0x80064E84
    // 0x8005AE04: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_80064E84(rdram, ctx);
        goto after_5;
    // 0x8005AE04: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_5:
    // 0x8005AE08: b           L_8005AE20
    // 0x8005AE0C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
        goto L_8005AE20;
    // 0x8005AE0C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
L_8005AE10:
    // 0x8005AE10: jal         0x80050970
    // 0x8005AE14: nop

    func_80050970(rdram, ctx);
        goto after_6;
    // 0x8005AE14: nop

    after_6:
    // 0x8005AE18: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8005AE1C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
L_8005AE20:
    // 0x8005AE20: sw          $s1, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r17;
L_8005AE24:
    // 0x8005AE24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005AE28:
    // 0x8005AE28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AE2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005AE30: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005AE34: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005AE38: jr          $ra
    // 0x8005AE3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005AE3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80776B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80776B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80776B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80776B0C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80776B10: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80776B14: lui         $t8, 0x8077
    ctx->r24 = S32(RELOC_HI16(772, 0X828) << 16);
    // 0x80776B18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80776B1C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80776B20: lw          $t8, 0x72F8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(772, 0X828));
    // 0x80776B24: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80776B28: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80776B2C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80776B30: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80776B34: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80776B38: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80776B3C: beql        $v1, $zero, L_80776B70
    if (ctx->r3 == 0) {
        // 0x80776B40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80776B70;
    }
    goto skip_0;
    // 0x80776B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80776B44: jalr        $v1
    // 0x80776B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80776B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80776B4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80776B50: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80776B54: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80776B58: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80776B5C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80776B60: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80776B64: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80776B68: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80776B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80776B70:
    // 0x80776B70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80776B74: jr          $ra
    // 0x80776B78: nop

    return;
    // 0x80776B78: nop

;}
RECOMP_FUNC void func_806DFC04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DFC04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806DFC08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806DFC0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806DFC10: jal         0x8004700C
    // 0x806DFC14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806DFC14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806DFC18: beq         $v0, $zero, L_806DFC74
    if (ctx->r2 == 0) {
        // 0x806DFC1C: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_806DFC74;
    }
    // 0x806DFC1C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806DFC20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806DFC24: jal         0x80062748
    // 0x806DFC28: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80062748(rdram, ctx);
        goto after_1;
    // 0x806DFC28: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_1:
    // 0x806DFC2C: jal         0x806DF6E0
    // 0x806DFC30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DF6E0(rdram, ctx);
        goto after_2;
    // 0x806DFC30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806DFC34: jal         0x806DFBD4
    // 0x806DFC38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DFBD4(rdram, ctx);
        goto after_3;
    // 0x806DFC38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806DFC3C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x806DFC40: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X11AC) << 16);
    // 0x806DFC44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806DFC48: lw          $t7, 0x180($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X180);
    // 0x806DFC4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806DFC50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806DFC54: bnel        $s0, $t7, L_806DFC78
    if (ctx->r16 != ctx->r15) {
        // 0x806DFC58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806DFC78;
    }
    goto skip_0;
    // 0x806DFC58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806DFC5C: lwc1        $f4, 0x5DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X11AC));
    // 0x806DFC60: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x806DFC64: jal         0x806E0398
    // 0x806DFC68: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    func_806E0398(rdram, ctx);
        goto after_4;
    // 0x806DFC68: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x806DFC6C: jal         0x806DF458
    // 0x806DFC70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DF458(rdram, ctx);
        goto after_5;
    // 0x806DFC70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_806DFC74:
    // 0x806DFC74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806DFC78:
    // 0x806DFC78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806DFC7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806DFC80: jr          $ra
    // 0x806DFC84: nop

    return;
    // 0x806DFC84: nop

;}
RECOMP_FUNC void func_8002F5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F5F4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8002F5F8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8002F5FC: lw          $t6, 0xF10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF10);
    // 0x8002F600: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8002F604: lw          $t9, 0xF54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XF54);
    // 0x8002F608: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002F60C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002F610: lw          $t8, -0x1808($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1808);
    // 0x8002F614: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F61C: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8002F620: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x8002F624: bne         $t2, $zero, L_8002F644
    if (ctx->r10 != 0) {
        // 0x8002F628: sw          $t0, 0xF54($v0)
        MEM_W(0XF54, ctx->r2) = ctx->r8;
            goto L_8002F644;
    }
    // 0x8002F628: sw          $t0, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r8;
    // 0x8002F62C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002F630: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x8002F634: jal         0x8006E0FC
    // 0x8002F638: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    func_8006E0FC(rdram, ctx);
        goto after_0;
    // 0x8002F638: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    after_0:
    // 0x8002F63C: b           L_8002F654
    // 0x8002F640: nop

        goto L_8002F654;
    // 0x8002F640: nop

L_8002F644:
    // 0x8002F644: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002F648: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x8002F64C: jal         0x8006E0FC
    // 0x8002F650: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_8006E0FC(rdram, ctx);
        goto after_1;
    // 0x8002F650: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
L_8002F654:
    // 0x8002F654: jal         0x8002AEE4
    // 0x8002F658: nop

    func_8002AEE4(rdram, ctx);
        goto after_2;
    // 0x8002F658: nop

    after_2:
    // 0x8002F65C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8002F660: jal         0x80067878
    // 0x8002F664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_3;
    // 0x8002F664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8002F668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F66C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002F670: jr          $ra
    // 0x8002F674: nop

    return;
    // 0x8002F674: nop

;}
RECOMP_FUNC void func_80025384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025384: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80025388: addiu       $t6, $t6, 0x515C
    ctx->r14 = ADD32(ctx->r14, 0X515C);
    // 0x8002538C: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80025390: jr          $ra
    // 0x80025394: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x80025394: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_804A25E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A25E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804A25EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A25F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804A25F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804A25F8: jal         0x804A2910
    // 0x804A25FC: sb          $a2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r6;
    func_804A2910(rdram, ctx);
        goto after_0;
    // 0x804A25FC: sb          $a2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r6;
    after_0:
    // 0x804A2600: beq         $v0, $zero, L_804A2640
    if (ctx->r2 == 0) {
        // 0x804A2604: lbu         $a2, 0x1F($sp)
        ctx->r6 = MEM_BU(ctx->r29, 0X1F);
            goto L_804A2640;
    }
    // 0x804A2604: lbu         $a2, 0x1F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1F);
    // 0x804A2608: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x804A260C: lw          $t6, -0x71E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X71E0);
    // 0x804A2610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804A2614: bnel        $t6, $zero, L_804A2644
    if (ctx->r14 != 0) {
        // 0x804A2618: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804A2644;
    }
    goto skip_0;
    // 0x804A2618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804A261C: lh          $t7, 0x184($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X184);
    // 0x804A2620: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x804A2624: bne         $at, $zero, L_804A2630
    if (ctx->r1 != 0) {
        // 0x804A2628: nop
    
            goto L_804A2630;
    }
    // 0x804A2628: nop

    // 0x804A262C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
L_804A2630:
    // 0x804A2630: jal         0x804A27A0
    // 0x804A2634: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804A27A0(rdram, ctx);
        goto after_1;
    // 0x804A2634: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804A2638: jal         0x804A1398
    // 0x804A263C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_804A1398(rdram, ctx);
        goto after_2;
    // 0x804A263C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
L_804A2640:
    // 0x804A2640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804A2644:
    // 0x804A2644: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804A2648: jr          $ra
    // 0x804A264C: nop

    return;
    // 0x804A264C: nop

;}
RECOMP_FUNC void func_8059F114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059F114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8059F118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8059F11C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8059F120: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8059F124: addiu       $at, $zero, 0x4127
    ctx->r1 = ADD32(0, 0X4127);
    // 0x8059F128: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x8059F12C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8059F130: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8059F134: bne         $t6, $at, L_8059F14C
    if (ctx->r14 != ctx->r1) {
        // 0x8059F138: nop
    
            goto L_8059F14C;
    }
    // 0x8059F138: nop

    // 0x8059F13C: jal         0x80048F84
    // 0x8059F140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8059F140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8059F144: b           L_8059F184
    // 0x8059F148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8059F184;
    // 0x8059F148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8059F14C:
    // 0x8059F14C: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8059F150: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8059F154: addiu       $a0, $zero, 0x4008
    ctx->r4 = ADD32(0, 0X4008);
    // 0x8059F158: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8059F15C: addiu       $a1, $a3, 0x3C
    ctx->r5 = ADD32(ctx->r7, 0X3C);
    // 0x8059F160: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8059F164: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x8059F168: jalr        $t9
    // 0x8059F16C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8059F16C: nop

    after_1:
    // 0x8059F170: jal         0x8059EC8C
    // 0x8059F174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8059EC8C(rdram, ctx);
        goto after_2;
    // 0x8059F174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8059F178: jal         0x800447C8
    // 0x8059F17C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x8059F17C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8059F180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8059F184:
    // 0x8059F184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8059F188: jr          $ra
    // 0x8059F18C: nop

    return;
    // 0x8059F18C: nop

;}
RECOMP_FUNC void func_8006E788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E788: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006E78C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006E790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E798: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8006E79C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006E7A0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006E7A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006E7A8: jal         0x8006E154
    // 0x8006E7AC: addiu       $a1, $a1, -0x18E8
    ctx->r5 = ADD32(ctx->r5, -0X18E8);
    func_8006E154(rdram, ctx);
        goto after_0;
    // 0x8006E7AC: addiu       $a1, $a1, -0x18E8
    ctx->r5 = ADD32(ctx->r5, -0X18E8);
    after_0:
    // 0x8006E7B0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006E7B4: sw          $zero, 0x1E0($t6)
    MEM_W(0X1E0, ctx->r14) = 0;
    // 0x8006E7B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E7BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E7C0: jr          $ra
    // 0x8006E7C4: nop

    return;
    // 0x8006E7C4: nop

;}
RECOMP_FUNC void func_804C33BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C33BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804C33C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C33C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C33C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804C33CC: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x804C33D0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x804C33D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804C33D8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x804C33DC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x804C33E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x804C33E4: jal         0x80062AEC
    // 0x804C33E8: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x804C33E8: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    after_0:
    // 0x804C33EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804C33F0: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x804C33F4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804C33F8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C33FC: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x804C3400: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x804C3404: lwc1        $f4, 0x6D4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X6D4);
    // 0x804C3408: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x804C340C: bne         $t7, $at, L_804C34F8
    if (ctx->r15 != ctx->r1) {
        // 0x804C3410: sub.s       $f0, $f4, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_804C34F8;
    }
    // 0x804C3410: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804C3414: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x804C3418: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x804C341C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804C3420: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804C3424: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x804C3428: nop

    // 0x804C342C: bc1fl       L_804C34FC
    if (!c1cs) {
        // 0x804C3430: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804C34FC;
    }
    goto skip_0;
    // 0x804C3430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804C3434: beq         $v0, $at, L_804C344C
    if (ctx->r2 == ctx->r1) {
        // 0x804C3438: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_804C344C;
    }
    // 0x804C3438: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804C343C: beq         $v0, $at, L_804C34A4
    if (ctx->r2 == ctx->r1) {
        // 0x804C3440: nop
    
            goto L_804C34A4;
    }
    // 0x804C3440: nop

    // 0x804C3444: b           L_804C34FC
    // 0x804C3448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804C34FC;
    // 0x804C3448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C344C:
    // 0x804C344C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(206, 0X1458) << 16);
    // 0x804C3450: lwc1        $f18, 0x3ED8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(206, 0X1458));
    // 0x804C3454: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x804C3458: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x804C345C: nop

    // 0x804C3460: bc1fl       L_804C3490
    if (!c1cs) {
        // 0x804C3464: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_804C3490;
    }
    goto skip_1;
    // 0x804C3464: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_1:
    // 0x804C3468: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x804C346C: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x804C3470: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C3474: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804C3478: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x804C347C: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804C3480: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804C3484: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x804C3488: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x804C348C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_804C3490:
    // 0x804C3490: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x804C3494: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x804C3498: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x804C349C: b           L_804C34F8
    // 0x804C34A0: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
        goto L_804C34F8;
    // 0x804C34A0: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_804C34A4:
    // 0x804C34A4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(206, 0X145C) << 16);
    // 0x804C34A8: lwc1        $f10, 0x3EDC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(206, 0X145C));
    // 0x804C34AC: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x804C34B0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x804C34B4: nop

    // 0x804C34B8: bc1fl       L_804C34E8
    if (!c1cs) {
        // 0x804C34BC: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_804C34E8;
    }
    goto skip_2;
    // 0x804C34BC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_2:
    // 0x804C34C0: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x804C34C4: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x804C34C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C34CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C34D0: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x804C34D4: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804C34D8: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x804C34DC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804C34E0: swc1        $f16, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f16.u32l;
    // 0x804C34E4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_804C34E8:
    // 0x804C34E8: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x804C34EC: lw          $t0, 0x34($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X34);
    // 0x804C34F0: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x804C34F4: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
L_804C34F8:
    // 0x804C34F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C34FC:
    // 0x804C34FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C3500: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804C3504: jr          $ra
    // 0x804C3508: nop

    return;
    // 0x804C3508: nop

;}
RECOMP_FUNC void func_8006958C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006958C: blez        $a2, L_80069608
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80069590: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80069608;
    }
    // 0x80069590: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80069594: andi        $t1, $a2, 0x3
    ctx->r9 = ctx->r6 & 0X3;
    // 0x80069598: beq         $t1, $zero, L_800695C8
    if (ctx->r9 == 0) {
        // 0x8006959C: or          $t0, $t1, $zero
        ctx->r8 = ctx->r9 | 0;
            goto L_800695C8;
    }
    // 0x8006959C: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x800695A0: sll         $t6, $zero, 1
    ctx->r14 = S32(0 << 1);
    // 0x800695A4: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x800695A8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
L_800695AC:
    // 0x800695AC: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    // 0x800695B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800695B4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800695B8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800695BC: bne         $t0, $v0, L_800695AC
    if (ctx->r8 != ctx->r2) {
        // 0x800695C0: sh          $t7, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r15;
            goto L_800695AC;
    }
    // 0x800695C0: sh          $t7, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r15;
    // 0x800695C4: beq         $v0, $a2, L_80069608
    if (ctx->r2 == ctx->r6) {
        // 0x800695C8: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_80069608;
    }
L_800695C8:
    // 0x800695C8: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800695CC: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x800695D0: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x800695D4: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x800695D8: addu        $a3, $a1, $v0
    ctx->r7 = ADD32(ctx->r5, ctx->r2);
L_800695DC:
    // 0x800695DC: lbu         $t2, 0x0($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X0);
    // 0x800695E0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800695E4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800695E8: sh          $t2, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r10;
    // 0x800695EC: lbu         $t3, -0x3($a3)
    ctx->r11 = MEM_BU(ctx->r7, -0X3);
    // 0x800695F0: sh          $t3, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r11;
    // 0x800695F4: lbu         $t4, -0x2($a3)
    ctx->r12 = MEM_BU(ctx->r7, -0X2);
    // 0x800695F8: sh          $t4, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r12;
    // 0x800695FC: lbu         $t5, -0x1($a3)
    ctx->r13 = MEM_BU(ctx->r7, -0X1);
    // 0x80069600: bne         $v1, $t0, L_800695DC
    if (ctx->r3 != ctx->r8) {
        // 0x80069604: sh          $t5, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r13;
            goto L_800695DC;
    }
    // 0x80069604: sh          $t5, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r13;
L_80069608:
    // 0x80069608: jr          $ra
    // 0x8006960C: nop

    return;
    // 0x8006960C: nop

;}
RECOMP_FUNC void func_80420118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80420118: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8042011C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80420120: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80420124: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80420128: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8042012C: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80420130: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80420134: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80420138: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8042013C: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80420140: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X354C) << 16);
    // 0x80420144: lwc1        $f10, 0xBAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X354C));
    // 0x80420148: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8042014C: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80420150: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80420154: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80420158: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8042015C: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x80420160: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80420164: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80420168: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8042016C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80420170: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80420174: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80420178: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8042017C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80420180: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80420184: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80420188: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8042018C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80420190: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80420194: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80420198: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x8042019C: jalr        $t9
    // 0x804201A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804201A0: nop

    after_0:
    // 0x804201A4: jal         0x80060FE0
    // 0x804201A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060FE0(rdram, ctx);
        goto after_1;
    // 0x804201A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804201AC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x804201B0: jal         0x80067BBC
    // 0x804201B4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x804201B4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x804201B8: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    // 0x804201BC: jal         0x80067818
    // 0x804201C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x804201C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x804201C4: jal         0x800447C8
    // 0x804201C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x804201C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804201CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804201D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804201D4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x804201D8: jr          $ra
    // 0x804201DC: nop

    return;
    // 0x804201DC: nop

;}
RECOMP_FUNC void func_805E4A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4A10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805E4A14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805E4A18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805E4A1C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805E4A20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805E4A24: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805E4A28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E4A2C: jal         0x805E4378
    // 0x805E4A30: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_805E4378(rdram, ctx);
        goto after_0;
    // 0x805E4A30: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x805E4A34: jal         0x805E4460
    // 0x805E4A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E4460(rdram, ctx);
        goto after_1;
    // 0x805E4A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805E4A3C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x805E4A40: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x805E4A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E4A48: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x805E4A4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E4A50: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x805E4A54: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805E4A58: nop

    // 0x805E4A5C: bc1f        L_805E4A6C
    if (!c1cs) {
        // 0x805E4A60: nop
    
            goto L_805E4A6C;
    }
    // 0x805E4A60: nop

    // 0x805E4A64: jal         0x805E4D78
    // 0x805E4A68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805E4D78(rdram, ctx);
        goto after_2;
    // 0x805E4A68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
L_805E4A6C:
    // 0x805E4A6C: jal         0x805E4674
    // 0x805E4A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E4674(rdram, ctx);
        goto after_3;
    // 0x805E4A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805E4A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805E4A78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805E4A7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805E4A80: jr          $ra
    // 0x805E4A84: nop

    return;
    // 0x805E4A84: nop

;}
RECOMP_FUNC void func_8052D6E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052D6E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8052D6E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052D6EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8052D6F0: jal         0x80045A34
    // 0x8052D6F4: addiu       $a1, $zero, 0xF2C
    ctx->r5 = ADD32(0, 0XF2C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8052D6F4: addiu       $a1, $zero, 0xF2C
    ctx->r5 = ADD32(0, 0XF2C);
    after_0:
    // 0x8052D6F8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8052D6FC: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8052D700: bne         $v0, $zero, L_8052D710
    if (ctx->r2 != 0) {
        // 0x8052D704: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8052D710;
    }
    // 0x8052D704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8052D708: b           L_8052D714
    // 0x8052D70C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8052D714;
    // 0x8052D70C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8052D710:
    // 0x8052D710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8052D714:
    // 0x8052D714: jr          $ra
    // 0x8052D718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8052D718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8052D658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052D658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8052D65C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052D660: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8052D664: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(330, 0X16CC) << 16);
    // 0x8052D668: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8052D66C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8052D670: addiu       $t6, $t6, -0x2364
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(330, 0X16CC));
    // 0x8052D674: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8052D678: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8052D67C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8052D680: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8052D684: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8052D688: jal         0x8052D6A8
    // 0x8052D68C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8052D6A8(rdram, ctx);
        goto after_0;
    // 0x8052D68C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8052D690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8052D694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8052D698: jr          $ra
    // 0x8052D69C: nop

    return;
    // 0x8052D69C: nop

;}
RECOMP_FUNC void func_807AF8D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF8D4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x807AF8D8: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(868, 0X124) << 16);
    // 0x807AF8DC: addiu       $t6, $t6, -0x8EC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(868, 0X124));
    // 0x807AF8E0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x807AF8E4: jr          $ra
    // 0x807AF8E8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x807AF8E8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_805687A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805687A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805687A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805687AC: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805687B0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805687B4: addiu       $at, $zero, 0x4150
    ctx->r1 = ADD32(0, 0X4150);
    // 0x805687B8: beq         $v0, $at, L_805687DC
    if (ctx->r2 == ctx->r1) {
        // 0x805687BC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_805687DC;
    }
    // 0x805687BC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805687C0: addiu       $at, $zero, 0x415C
    ctx->r1 = ADD32(0, 0X415C);
    // 0x805687C4: beq         $v0, $at, L_805687EC
    if (ctx->r2 == ctx->r1) {
        // 0x805687C8: addiu       $at, $zero, 0x4168
        ctx->r1 = ADD32(0, 0X4168);
            goto L_805687EC;
    }
    // 0x805687C8: addiu       $at, $zero, 0x4168
    ctx->r1 = ADD32(0, 0X4168);
    // 0x805687CC: beql        $v0, $at, L_80568800
    if (ctx->r2 == ctx->r1) {
        // 0x805687D0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80568800;
    }
    goto skip_0;
    // 0x805687D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x805687D4: b           L_8056880C
    // 0x805687D8: nop

        goto L_8056880C;
    // 0x805687D8: nop

L_805687DC:
    // 0x805687DC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x805687E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805687E4: b           L_8056880C
    // 0x805687E8: swc1        $f4, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f4.u32l;
        goto L_8056880C;
    // 0x805687E8: swc1        $f4, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f4.u32l;
L_805687EC:
    // 0x805687EC: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21CC) << 16);
    // 0x805687F0: lwc1        $f6, -0x6884($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21CC));
    // 0x805687F4: b           L_8056880C
    // 0x805687F8: swc1        $f6, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
        goto L_8056880C;
    // 0x805687F8: swc1        $f6, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
    // 0x805687FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80568800:
    // 0x80568800: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80568804: nop

    // 0x80568808: swc1        $f8, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f8.u32l;
L_8056880C:
    // 0x8056880C: jal         0x80568710
    // 0x80568810: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x80568810: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80568814: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80568818: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8056881C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80568820: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80568824: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21D0) << 16);
    // 0x80568828: sw          $zero, 0x24($a2)
    MEM_W(0X24, ctx->r6) = 0;
    // 0x8056882C: swc1        $f10, 0xC4($a2)
    MEM_W(0XC4, ctx->r6) = ctx->f10.u32l;
    // 0x80568830: swc1        $f16, 0xDC($a2)
    MEM_W(0XDC, ctx->r6) = ctx->f16.u32l;
    // 0x80568834: lwc1        $f18, -0x6880($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21D0));
    // 0x80568838: lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F4);
    // 0x8056883C: lwc1        $f4, 0x3C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x80568840: swc1        $f18, 0xE8($a2)
    MEM_W(0XE8, ctx->r6) = ctx->f18.u32l;
    // 0x80568844: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80568848: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8056884C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    // 0x80568850: jal         0x80048F84
    // 0x80568854: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80568854: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80568858: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8056885C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80568860: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80568864: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80568868: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8056886C: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80568870: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80568874: jal         0x80569310
    // 0x80568878: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    func_80569310(rdram, ctx);
        goto after_2;
    // 0x80568878: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    after_2:
    // 0x8056887C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80568880: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80568884: jr          $ra
    // 0x80568888: nop

    return;
    // 0x80568888: nop

;}
RECOMP_FUNC void func_807C6830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C6830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C6834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C6838: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x807C683C: addiu       $at, $zero, 0x4735
    ctx->r1 = ADD32(0, 0X4735);
    // 0x807C6840: lui         $t9, 0x807C
    ctx->r25 = S32(RELOC_HI16(916, 0X1C0) << 16);
    // 0x807C6844: beq         $v0, $at, L_807C6870
    if (ctx->r2 == ctx->r1) {
        // 0x807C6848: addiu       $t9, $t9, 0x69D0
        ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(916, 0X1C0));
            goto L_807C6870;
    }
    // 0x807C6848: addiu       $t9, $t9, 0x69D0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(916, 0X1C0));
    // 0x807C684C: addiu       $at, $zero, 0x4736
    ctx->r1 = ADD32(0, 0X4736);
    // 0x807C6850: beq         $v0, $at, L_807C6890
    if (ctx->r2 == ctx->r1) {
        // 0x807C6854: addiu       $at, $zero, 0x4737
        ctx->r1 = ADD32(0, 0X4737);
            goto L_807C6890;
    }
    // 0x807C6854: addiu       $at, $zero, 0x4737
    ctx->r1 = ADD32(0, 0X4737);
    // 0x807C6858: beq         $v0, $at, L_807C68AC
    if (ctx->r2 == ctx->r1) {
        // 0x807C685C: addiu       $at, $zero, 0x4738
        ctx->r1 = ADD32(0, 0X4738);
            goto L_807C68AC;
    }
    // 0x807C685C: addiu       $at, $zero, 0x4738
    ctx->r1 = ADD32(0, 0X4738);
    // 0x807C6860: beql        $v0, $at, L_807C68D0
    if (ctx->r2 == ctx->r1) {
        // 0x807C6864: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_807C68D0;
    }
    goto skip_0;
    // 0x807C6864: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    skip_0:
    // 0x807C6868: b           L_807C68EC
    // 0x807C686C: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
        goto L_807C68EC;
    // 0x807C686C: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
L_807C6870:
    // 0x807C6870: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x807C6874: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807C6878: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x807C687C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x807C6880: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    // 0x807C6884: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807C6888: b           L_807C68E8
    // 0x807C688C: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
        goto L_807C68E8;
    // 0x807C688C: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
L_807C6890:
    // 0x807C6890: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x807C6894: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807C6898: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x807C689C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807C68A0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x807C68A4: b           L_807C68E8
    // 0x807C68A8: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
        goto L_807C68E8;
    // 0x807C68A8: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
L_807C68AC:
    // 0x807C68AC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x807C68B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807C68B4: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x807C68B8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x807C68BC: sw          $t7, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r15;
    // 0x807C68C0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807C68C4: b           L_807C68E8
    // 0x807C68C8: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
        goto L_807C68E8;
    // 0x807C68C8: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x807C68CC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
L_807C68D0:
    // 0x807C68D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807C68D4: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x807C68D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807C68DC: sw          $t8, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r24;
    // 0x807C68E0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x807C68E4: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
L_807C68E8:
    // 0x807C68E8: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
L_807C68EC:
    // 0x807C68EC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807C68F0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807C68F4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x807C68F8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807C68FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C6900: jal         0x807C6920
    // 0x807C6904: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_807C6920(rdram, ctx);
        goto after_0;
    // 0x807C6904: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x807C6908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C690C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C6910: jr          $ra
    // 0x807C6914: nop

    return;
    // 0x807C6914: nop

;}
RECOMP_FUNC void func_807601C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807601C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807601C4: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(763, 0XC334) << 16);
    // 0x807601C8: lwc1        $f4, -0x3C3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(763, 0XC334));
    // 0x807601CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x807601D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807601D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807601D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x807601DC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x807601E0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x807601E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x807601E8: addiu       $t6, $zero, 0x5A0
    ctx->r14 = ADD32(0, 0X5A0);
    // 0x807601EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x807601F0: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x807601F4: addiu       $a3, $zero, 0x564
    ctx->r7 = ADD32(0, 0X564);
    // 0x807601F8: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x807601FC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80760200: jal         0x8076009C
    // 0x80760204: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_8076009C(rdram, ctx);
        goto after_0;
    // 0x80760204: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80760208: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8076020C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80760210: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80760214: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80760218: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8076021C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80760220: jr          $ra
    // 0x80760224: nop

    return;
    // 0x80760224: nop

;}
RECOMP_FUNC void func_8002F19C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F19C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002F1A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F1A4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F1A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002F1AC: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    // 0x8002F1B0: jal         0x8002F15C
    // 0x8002F1B4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8002F15C(rdram, ctx);
        goto after_0;
    // 0x8002F1B4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002F1B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002F1BC: jal         0x8002ED94
    // 0x8002F1C0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8002ED94(rdram, ctx);
        goto after_1;
    // 0x8002F1C0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002F1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F1C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002F1CC: jr          $ra
    // 0x8002F1D0: nop

    return;
    // 0x8002F1D0: nop

;}
RECOMP_FUNC void func_806D0D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0D4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D0D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D0D54: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x806D0D58: lui         $t8, 0x806D
    ctx->r24 = S32(RELOC_HI16(607, 0X1AA0) << 16);
    // 0x806D0D5C: addiu       $t8, $t8, 0x1240
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(607, 0X1AA0));
    // 0x806D0D60: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806D0D64: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x806D0D68: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806D0D6C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x806D0D70: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x806D0D74: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x806D0D78: beql        $v1, $zero, L_806D0DB0
    if (ctx->r3 == 0) {
        // 0x806D0D7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D0DB0;
    }
    goto skip_0;
    // 0x806D0D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806D0D80: jalr        $v1
    // 0x806D0D84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x806D0D84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D0D88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D0D8C: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x806D0D90: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x806D0D94: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x806D0D98: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x806D0D9C: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x806D0DA0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x806D0DA4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x806D0DA8: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x806D0DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D0DB0:
    // 0x806D0DB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D0DB4: jr          $ra
    // 0x806D0DB8: nop

    return;
    // 0x806D0DB8: nop

;}
RECOMP_FUNC void func_805A5D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A5D58: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x805A5D5C: lw          $v0, -0x7254($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7254);
    // 0x805A5D60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805A5D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A5D68: beq         $v0, $zero, L_805A5DD4
    if (ctx->r2 == 0) {
        // 0x805A5D6C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_805A5DD4;
    }
    // 0x805A5D6C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x805A5D70: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x805A5D74: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x805A5D78: bnel        $t6, $zero, L_805A5DD8
    if (ctx->r14 != 0) {
        // 0x805A5D7C: lw          $t8, 0x1E0($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X1E0);
            goto L_805A5DD8;
    }
    goto skip_0;
    // 0x805A5D7C: lw          $t8, 0x1E0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1E0);
    skip_0:
    // 0x805A5D80: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x805A5D84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A5D88: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x805A5D8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805A5D90: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805A5D94: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(417, 0X1584) << 16);
    // 0x805A5D98: lwc1        $f6, 0x6844($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(417, 0X1584));
    // 0x805A5D9C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x805A5DA0: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x805A5DA4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805A5DA8: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x805A5DAC: lwc1        $f4, 0x8C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x805A5DB0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x805A5DB4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x805A5DB8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805A5DBC: jalr        $v0
    // 0x805A5DC0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x805A5DC0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x805A5DC4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x805A5DC8: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x805A5DCC: b           L_805A5DE0
    // 0x805A5DD0: sw          $t7, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r15;
        goto L_805A5DE0;
    // 0x805A5DD0: sw          $t7, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r15;
L_805A5DD4:
    // 0x805A5DD4: lw          $t8, 0x1E0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1E0);
L_805A5DD8:
    // 0x805A5DD8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x805A5DDC: sw          $t9, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r25;
L_805A5DE0:
    // 0x805A5DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A5DE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805A5DE8: jr          $ra
    // 0x805A5DEC: nop

    return;
    // 0x805A5DEC: nop

;}
RECOMP_FUNC void func_80682058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682058: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8068205C: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(550, 0X1670) << 16);
    // 0x80682060: addiu       $t6, $t6, 0x1A80
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(550, 0X1670));
    // 0x80682064: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80682068: jr          $ra
    // 0x8068206C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8068206C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8044DC48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044DC48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8044DC4C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8044DC50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8044DC54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8044DC58: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8044DC5C: bltz        $a3, L_8044DD34
    if (SIGNED(ctx->r7) < 0) {
        // 0x8044DC60: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_8044DD34;
    }
    // 0x8044DC60: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8044DC64: slti        $at, $a3, 0xC
    ctx->r1 = SIGNED(ctx->r7) < 0XC ? 1 : 0;
    // 0x8044DC68: beq         $at, $zero, L_8044DD34
    if (ctx->r1 == 0) {
        // 0x8044DC6C: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_8044DD34;
    }
    // 0x8044DC6C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8044DC70: lw          $v0, 0x1F4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X1F4);
    // 0x8044DC74: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8044DC78: sll         $a1, $a3, 2
    ctx->r5 = S32(ctx->r7 << 2);
    // 0x8044DC7C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8044DC80: lw          $v1, 0x6980($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6980);
    // 0x8044DC84: lui         $t3, 0x8045
    ctx->r11 = S32(RELOC_HI16(98, 0X12DE8) << 16);
    // 0x8044DC88: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8044DC8C: addu        $t6, $v1, $a1
    ctx->r14 = ADD32(ctx->r3, ctx->r5);
    // 0x8044DC90: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8044DC94: sll         $t7, $a3, 1
    ctx->r15 = S32(ctx->r7 << 1);
    // 0x8044DC98: addiu       $t3, $t3, 0x71C8
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(98, 0X12DE8));
    // 0x8044DC9C: beq         $a0, $zero, L_8044DD34
    if (ctx->r4 == 0) {
        // 0x8044DCA0: lui         $t5, 0x8045
        ctx->r13 = S32(RELOC_HI16(98, 0X13980) << 16);
            goto L_8044DD34;
    }
    // 0x8044DCA0: lui         $t5, 0x8045
    ctx->r13 = S32(RELOC_HI16(98, 0X13980) << 16);
    // 0x8044DCA4: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X136B4) << 16);
    // 0x8044DCA8: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8044DCAC: lh          $a0, 0x7A94($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(98, 0X136B4));
    // 0x8044DCB0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8044DCB4: addiu       $t5, $t5, 0x7D60
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(98, 0X13980));
    // 0x8044DCB8: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8044DCBC: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8044DCC0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8044DCC4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8044DCC8: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x8044DCCC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8044DCD0: addu        $a2, $a1, $t5
    ctx->r6 = ADD32(ctx->r5, ctx->r13);
    // 0x8044DCD4: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8044DCD8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8044DCDC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8044DCE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8044DCE4: beql        $t6, $zero, L_8044DD08
    if (ctx->r14 == 0) {
        // 0x8044DCE8: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_8044DD08;
    }
    goto skip_0;
    // 0x8044DCE8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8044DCEC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8044DCF0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8044DCF4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8044DCF8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8044DCFC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8044DD00: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8044DD04: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
L_8044DD08:
    // 0x8044DD08: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8044DD0C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8044DD10: jal         0x8044D5F4
    // 0x8044DD14: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_8044D5F4(rdram, ctx);
        goto after_0;
    // 0x8044DD14: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x8044DD18: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8044DD1C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8044DD20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8044DD24: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8044DD28: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8044DD2C: jal         0x8044D680
    // 0x8044DD30: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_8044D680(rdram, ctx);
        goto after_1;
    // 0x8044DD30: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
L_8044DD34:
    // 0x8044DD34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8044DD38: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8044DD3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8044DD40: jr          $ra
    // 0x8044DD44: nop

    return;
    // 0x8044DD44: nop

;}
RECOMP_FUNC void func_800411AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800411AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800411B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800411B4: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800411B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800411BC: jal         0x8001D7CC
    // 0x800411C0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8001D7CC(rdram, ctx);
        goto after_0;
    // 0x800411C0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x800411C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800411C8: jal         0x8001D808
    // 0x800411CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8001D808(rdram, ctx);
        goto after_1;
    // 0x800411CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800411D0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800411D4: swc1        $f0, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f0.u32l;
    // 0x800411D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800411DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800411E0: jr          $ra
    // 0x800411E4: nop

    return;
    // 0x800411E4: nop

;}
RECOMP_FUNC void func_8005E598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005E59C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005E5A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005E5A4: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x8005E5A8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8005E5AC: lw          $a1, 0xC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC);
    // 0x8005E5B0: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8005E5B4: lw          $t8, -0x76D4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76D4);
    // 0x8005E5B8: lw          $t7, 0x16C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X16C);
    // 0x8005E5BC: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8005E5C0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005E5C4: lw          $a3, 0x2C($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X2C);
    // 0x8005E5C8: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x8005E5CC: ori         $t1, $t1, 0x40
    ctx->r9 = ctx->r9 | 0X40;
    // 0x8005E5D0: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8005E5D4: subu        $t9, $t9, $a3
    ctx->r25 = SUB32(ctx->r25, ctx->r7);
    // 0x8005E5D8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005E5DC: subu        $t9, $t9, $a3
    ctx->r25 = SUB32(ctx->r25, ctx->r7);
    // 0x8005E5E0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8005E5E4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8005E5E8: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x8005E5EC: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8005E5F0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8005E5F4: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8005E5F8: sw          $v0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r2;
    // 0x8005E5FC: lw          $t3, 0x16C($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X16C);
    // 0x8005E600: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8005E604: lw          $t9, 0x34($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X34);
    // 0x8005E608: jalr        $t9
    // 0x8005E60C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005E60C: nop

    after_0:
    // 0x8005E610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005E614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005E618: jr          $ra
    // 0x8005E61C: nop

    return;
    // 0x8005E61C: nop

;}
RECOMP_FUNC void func_8076DF28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076DF28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8076DF2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076DF30: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076DF34: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8076DF38: bnel        $t6, $zero, L_8076DF60
    if (ctx->r14 != 0) {
        // 0x8076DF3C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8076DF60;
    }
    goto skip_0;
    // 0x8076DF3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8076DF40: jal         0x80045A34
    // 0x8076DF44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8076DF44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8076DF48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8076DF4C: bne         $v0, $zero, L_8076DF5C
    if (ctx->r2 != 0) {
        // 0x8076DF50: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8076DF5C;
    }
    // 0x8076DF50: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8076DF54: b           L_8076DF60
    // 0x8076DF58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8076DF60;
    // 0x8076DF58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8076DF5C:
    // 0x8076DF5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8076DF60:
    // 0x8076DF60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8076DF64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8076DF68: jr          $ra
    // 0x8076DF6C: nop

    return;
    // 0x8076DF6C: nop

;}
RECOMP_FUNC void func_800748D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800748D8: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800748DC: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x800748E0: sb          $t6, 0x2B2($a0)
    MEM_B(0X2B2, ctx->r4) = ctx->r14;
    // 0x800748E4: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x800748E8: sb          $t7, 0x2B3($a0)
    MEM_B(0X2B3, ctx->r4) = ctx->r15;
    // 0x800748EC: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x800748F0: sb          $t8, 0x2B4($a0)
    MEM_B(0X2B4, ctx->r4) = ctx->r24;
    // 0x800748F4: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x800748F8: sb          $t9, 0x2B5($a0)
    MEM_B(0X2B5, ctx->r4) = ctx->r25;
    // 0x800748FC: sb          $t0, 0x45D($a0)
    MEM_B(0X45D, ctx->r4) = ctx->r8;
    // 0x80074900: jr          $ra
    // 0x80074904: nop

    return;
    // 0x80074904: nop

;}
RECOMP_FUNC void func_80531740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80531744: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80531748: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x8053174C: lui         $a2, 0x8053
    ctx->r6 = S32(RELOC_HI16(342, 0X199C) << 16);
    // 0x80531750: lui         $a1, 0xC180
    ctx->r5 = S32(0XC180 << 16);
    // 0x80531754: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80531758: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8053175C: jal         0x8053167C
    // 0x80531760: lw          $a2, 0x278C($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(342, 0X199C));
    func_8053167C(rdram, ctx);
        goto after_0;
    // 0x80531760: lw          $a2, 0x278C($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(342, 0X199C));
    after_0:
    // 0x80531764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80531768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8053176C: jr          $ra
    // 0x80531770: nop

    return;
    // 0x80531770: nop

;}
RECOMP_FUNC void func_8005FCA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FCA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FCAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FCB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005FCB4: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x8005FCB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FCBC: lh          $t7, 0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X10);
    // 0x8005FCC0: beql        $t7, $zero, L_8005FCDC
    if (ctx->r15 == 0) {
        // 0x8005FCC4: lh          $t8, 0x12($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X12);
            goto L_8005FCDC;
    }
    goto skip_0;
    // 0x8005FCC4: lh          $t8, 0x12($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X12);
    skip_0:
    // 0x8005FCC8: jal         0x8005FA48
    // 0x8005FCCC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8005FA48(rdram, ctx);
        goto after_0;
    // 0x8005FCCC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8005FCD0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FCD4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FCD8: lh          $t8, 0x12($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X12);
L_8005FCDC:
    // 0x8005FCDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005FCE0: beql        $t8, $zero, L_8005FCFC
    if (ctx->r24 == 0) {
        // 0x8005FCE4: lh          $t9, 0x14($v0)
        ctx->r25 = MEM_H(ctx->r2, 0X14);
            goto L_8005FCFC;
    }
    goto skip_1;
    // 0x8005FCE4: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    skip_1:
    // 0x8005FCE8: jal         0x8005FAE0
    // 0x8005FCEC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8005FAE0(rdram, ctx);
        goto after_1;
    // 0x8005FCEC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8005FCF0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FCF4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FCF8: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
L_8005FCFC:
    // 0x8005FCFC: beql        $t9, $zero, L_8005FD10
    if (ctx->r25 == 0) {
        // 0x8005FD00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FD10;
    }
    goto skip_2;
    // 0x8005FD00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8005FD04: jal         0x8005FB74
    // 0x8005FD08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8005FB74(rdram, ctx);
        goto after_2;
    // 0x8005FD08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8005FD0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FD10:
    // 0x8005FD10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005FD14: jr          $ra
    // 0x8005FD18: nop

    return;
    // 0x8005FD18: nop

;}
RECOMP_FUNC void func_8052D61C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052D61C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8052D620: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8052D624: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8052D628: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8052D62C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8052D630: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8052D634: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8052D638: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8052D63C: lui         $t1, 0x8053
    ctx->r9 = S32(RELOC_HI16(330, 0X16BC) << 16);
    // 0x8052D640: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8052D644: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8052D648: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8052D64C: lw          $t1, -0x2374($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(330, 0X16BC));
    // 0x8052D650: jr          $ra
    // 0x8052D654: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8052D654: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80430BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80430BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80430BF0: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80430BF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80430BF8: beq         $t6, $zero, L_80430C34
    if (ctx->r14 == 0) {
        // 0x80430BFC: nop
    
            goto L_80430C34;
    }
    // 0x80430BFC: nop

    // 0x80430C00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80430C04: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80430C08: jalr        $t9
    // 0x80430C0C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80430C0C: nop

    after_0:
    // 0x80430C10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80430C14: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80430C18: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80430C1C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80430C20: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80430C24: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80430C28: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80430C2C: b           L_80430C34
    // 0x80430C30: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_80430C34;
    // 0x80430C30: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_80430C34:
    // 0x80430C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80430C38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80430C3C: jr          $ra
    // 0x80430C40: nop

    return;
    // 0x80430C40: nop

;}
RECOMP_FUNC void nearbyint_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082094: round.w.d   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = lround(ctx->f12.d);
    // 0x80082098: jr          $ra
    // 0x8008209C: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
    return;
    // 0x8008209C: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
;}
RECOMP_FUNC void func_8040B23C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B23C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040B240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040B244: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040B248: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8040B24C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8040B250: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8040B254: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8040B258: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8040B25C: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x8040B260: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8040B264: lw          $t7, 0x180($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X180);
    // 0x8040B268: jal         0x8040B2F0
    // 0x8040B26C: lbu         $a1, 0x30($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X30);
    func_8040B2F0(rdram, ctx);
        goto after_0;
    // 0x8040B26C: lbu         $a1, 0x30($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X30);
    after_0:
    // 0x8040B270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040B274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040B278: jr          $ra
    // 0x8040B27C: nop

    return;
    // 0x8040B27C: nop

;}
RECOMP_FUNC void func_8067926C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067926C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80679270: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(538, 0X125C) << 16);
    // 0x80679274: addiu       $t6, $t6, -0x6E34
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(538, 0X125C));
    // 0x80679278: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8067927C: jr          $ra
    // 0x80679280: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80679280: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80436024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436024: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80436028: lui         $a2, 0xB800
    ctx->r6 = S32(0XB800 << 16);
    // 0x8043602C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x80436030: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80436034: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80436038: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x8043603C: jr          $ra
    // 0x80436040: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    return;
    // 0x80436040: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
;}
RECOMP_FUNC void func_80429BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80429BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80429BCC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80429BD0: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80429BD4: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(44, 0X260) << 16);
    // 0x80429BD8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80429BDC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80429BE0: lw          $t8, -0x62D0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(44, 0X260));
    // 0x80429BE4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80429BE8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80429BEC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80429BF0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80429BF4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80429BF8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80429BFC: beql        $v1, $zero, L_80429C30
    if (ctx->r3 == 0) {
        // 0x80429C00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80429C30;
    }
    goto skip_0;
    // 0x80429C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80429C04: jalr        $v1
    // 0x80429C08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80429C08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80429C0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80429C10: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80429C14: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80429C18: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80429C1C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80429C20: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80429C24: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80429C28: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80429C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80429C30:
    // 0x80429C30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80429C34: jr          $ra
    // 0x80429C38: nop

    return;
    // 0x80429C38: nop

;}
RECOMP_FUNC void func_8004F910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F910: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004F914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004F918: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004F91C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8004F920: lw          $v1, 0x1B8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1B8);
    // 0x8004F924: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x8004F928: jal         0x8006A99C
    // 0x8004F92C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8006A99C(rdram, ctx);
        goto after_0;
    // 0x8004F92C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8004F930: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8004F934: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8004F938: sh          $v0, 0x3A($a1)
    MEM_H(0X3A, ctx->r5) = ctx->r2;
    // 0x8004F93C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8004F940: addiu       $a1, $a1, 0x38
    ctx->r5 = ADD32(ctx->r5, 0X38);
    // 0x8004F944: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004F948: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8004F94C: lh          $a0, 0x4($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X4);
    // 0x8004F950: jal         0x8006A99C
    // 0x8004F954: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x8004F954: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8004F958: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F95C: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // 0x8004F960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004F964: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004F968: jr          $ra
    // 0x8004F96C: nop

    return;
    // 0x8004F96C: nop

;}
RECOMP_FUNC void func_8066D5D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066D5D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066D5D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066D5D8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8066D5DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8066D5E0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066D5E4: bne         $t6, $at, L_8066D62C
    if (ctx->r14 != ctx->r1) {
        // 0x8066D5E8: addiu       $t7, $zero, 0xC8
        ctx->r15 = ADD32(0, 0XC8);
            goto L_8066D62C;
    }
    // 0x8066D5E8: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x8066D5EC: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x8066D5F0: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8066D5F4: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x8066D5F8: jal         0x800653D8
    // 0x8066D5FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8066D5FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066D600: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x8066D604: beq         $t8, $zero, L_8066D620
    if (ctx->r24 == 0) {
        // 0x8066D608: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8066D620;
    }
    // 0x8066D608: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066D60C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066D610: jal         0x8066E4C8
    // 0x8066D614: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8066E4C8(rdram, ctx);
        goto after_1;
    // 0x8066D614: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8066D618: b           L_8066D630
    // 0x8066D61C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8066D630;
    // 0x8066D61C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066D620:
    // 0x8066D620: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066D624: jal         0x8066E4C8
    // 0x8066D628: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8066E4C8(rdram, ctx);
        goto after_2;
    // 0x8066D628: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
L_8066D62C:
    // 0x8066D62C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066D630:
    // 0x8066D630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066D634: jr          $ra
    // 0x8066D638: nop

    return;
    // 0x8066D638: nop

;}
RECOMP_FUNC void func_8051827C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051827C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80518280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80518284: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x80518288: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8051828C: bnel        $t6, $at, L_805182A0
    if (ctx->r14 != ctx->r1) {
        // 0x80518290: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805182A0;
    }
    goto skip_0;
    // 0x80518290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80518294: jal         0x805181B8
    // 0x80518298: nop

    func_805181B8(rdram, ctx);
        goto after_0;
    // 0x80518298: nop

    after_0:
    // 0x8051829C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805182A0:
    // 0x805182A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805182A4: jr          $ra
    // 0x805182A8: nop

    return;
    // 0x805182A8: nop

;}
RECOMP_FUNC void func_80040940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040948: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8004094C: jal         0x8003E7E0
    // 0x80040950: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    func_8003E7E0(rdram, ctx);
        goto after_0;
    // 0x80040950: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_0:
    // 0x80040954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004095C: jr          $ra
    // 0x80040960: nop

    return;
    // 0x80040960: nop

;}
RECOMP_FUNC void func_800657CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800657CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800657D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800657D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800657D8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800657DC: sb          $a3, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r7;
    // 0x800657E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800657E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800657E8: jal         0x800656BC
    // 0x800657EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800656BC(rdram, ctx);
        goto after_0;
    // 0x800657EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800657F0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800657F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800657F8: bne         $v0, $zero, L_80065818
    if (ctx->r2 != 0) {
        // 0x800657FC: lbu         $a3, 0x2B($sp)
        ctx->r7 = MEM_BU(ctx->r29, 0X2B);
            goto L_80065818;
    }
    // 0x800657FC: lbu         $a3, 0x2B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2B);
    // 0x80065800: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80065804: addiu       $a0, $a0, 0xDD0
    ctx->r4 = ADD32(ctx->r4, 0XDD0);
    // 0x80065808: jal         0x80071380
    // 0x8006580C: addiu       $a1, $zero, 0x264
    ctx->r5 = ADD32(0, 0X264);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8006580C: addiu       $a1, $zero, 0x264
    ctx->r5 = ADD32(0, 0X264);
    after_1:
    // 0x80065810: b           L_80065860
    // 0x80065814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80065860;
    // 0x80065814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80065818:
    // 0x80065818: beq         $a1, $zero, L_8006585C
    if (ctx->r5 == 0) {
        // 0x8006581C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006585C;
    }
    // 0x8006581C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80065820: andi        $a2, $a1, 0x3
    ctx->r6 = ctx->r5 & 0X3;
    // 0x80065824: beq         $a2, $zero, L_80065840
    if (ctx->r6 == 0) {
        // 0x80065828: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80065840;
    }
    // 0x80065828: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_8006582C:
    // 0x8006582C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80065830: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x80065834: bne         $a0, $v0, L_8006582C
    if (ctx->r4 != ctx->r2) {
        // 0x80065838: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8006582C;
    }
    // 0x80065838: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006583C: beq         $v0, $a1, L_8006585C
    if (ctx->r2 == ctx->r5) {
        // 0x80065840: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8006585C;
    }
L_80065840:
    // 0x80065840: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80065844: sb          $a3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r7;
    // 0x80065848: sb          $a3, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r7;
    // 0x8006584C: sb          $a3, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r7;
    // 0x80065850: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80065854: bne         $v0, $a1, L_80065840
    if (ctx->r2 != ctx->r5) {
        // 0x80065858: sb          $a3, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = ctx->r7;
            goto L_80065840;
    }
    // 0x80065858: sb          $a3, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r7;
L_8006585C:
    // 0x8006585C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80065860:
    // 0x80065860: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065864: jr          $ra
    // 0x80065868: nop

    return;
    // 0x80065868: nop

;}
RECOMP_FUNC void func_8064A88C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A88C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8064A890: lui         $t6, 0x8065
    ctx->r14 = S32(RELOC_HI16(495, 0X63C) << 16);
    // 0x8064A894: addiu       $t6, $t6, -0x58F4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(495, 0X63C));
    // 0x8064A898: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8064A89C: jr          $ra
    // 0x8064A8A0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8064A8A0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void ViMode_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EB2C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007EB30: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8007EB34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007EB38: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8007EB3C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8007EB40: jal         0x8007EA30
    // 0x8007EB44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ViMode_Load(rdram, ctx);
        goto after_0;
    // 0x8007EB44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007EB48: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x8007EB4C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007EB50: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8007EB54: bnel        $v0, $at, L_8007EB7C
    if (ctx->r2 != ctx->r1) {
        // 0x8007EB58: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8007EB7C;
    }
    goto skip_0;
    // 0x8007EB58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x8007EB5C: jal         0x8007E470
    // 0x8007EB60: addiu       $a0, $a0, -0x45D0
    ctx->r4 = ADD32(ctx->r4, -0X45D0);
    ViMode_LogPrint(rdram, ctx);
        goto after_1;
    // 0x8007EB60: addiu       $a0, $a0, -0x45D0
    ctx->r4 = ADD32(ctx->r4, -0X45D0);
    after_1:
    // 0x8007EB64: jal         0x8007E470
    // 0x8007EB68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ViMode_LogPrint(rdram, ctx);
        goto after_2;
    // 0x8007EB68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8007EB6C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8007EB70: b           L_8007EE0C
    // 0x8007EB74: sw          $t6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r14;
        goto L_8007EE0C;
    // 0x8007EB74: sw          $t6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r14;
    // 0x8007EB78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8007EB7C:
    // 0x8007EB7C: beq         $v0, $at, L_8007EB90
    if (ctx->r2 == ctx->r1) {
        // 0x8007EB80: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_8007EB90;
    }
    // 0x8007EB80: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8007EB84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007EB88: bne         $v0, $at, L_8007EE0C
    if (ctx->r2 != ctx->r1) {
        // 0x8007EB8C: nop
    
            goto L_8007EE0C;
    }
    // 0x8007EB8C: nop

L_8007EB90:
    // 0x8007EB90: jal         0x8007FB34
    // 0x8007EB94: addiu       $a1, $zero, 0x1009
    ctx->r5 = ADD32(0, 0X1009);
    pad_push_also(rdram, ctx);
        goto after_3;
    // 0x8007EB94: addiu       $a1, $zero, 0x1009
    ctx->r5 = ADD32(0, 0X1009);
    after_3:
    // 0x8007EB98: beql        $v0, $zero, L_8007EBAC
    if (ctx->r2 == 0) {
        // 0x8007EB9C: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_8007EBAC;
    }
    goto skip_1;
    // 0x8007EB9C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x8007EBA0: jal         0x8007EA54
    // 0x8007EBA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ViMode_Init(rdram, ctx);
        goto after_4;
    // 0x8007EBA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8007EBA8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_8007EBAC:
    // 0x8007EBAC: jal         0x8007FB34
    // 0x8007EBB0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    pad_push_also(rdram, ctx);
        goto after_5;
    // 0x8007EBB0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x8007EBB4: beql        $v0, $zero, L_8007EC34
    if (ctx->r2 == 0) {
        // 0x8007EBB8: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_8007EC34;
    }
    goto skip_2;
    // 0x8007EBB8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    skip_2:
    // 0x8007EBBC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8007EBC0: jal         0x8007FB34
    // 0x8007EBC4: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    pad_push_also(rdram, ctx);
        goto after_6;
    // 0x8007EBC4: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_6:
    // 0x8007EBC8: beq         $v0, $zero, L_8007EBDC
    if (ctx->r2 == 0) {
        // 0x8007EBCC: addiu       $a1, $zero, 0x400
        ctx->r5 = ADD32(0, 0X400);
            goto L_8007EBDC;
    }
    // 0x8007EBCC: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x8007EBD0: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x8007EBD4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8007EBD8: sw          $t8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r24;
L_8007EBDC:
    // 0x8007EBDC: jal         0x8007FB34
    // 0x8007EBE0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    pad_push_also(rdram, ctx);
        goto after_7;
    // 0x8007EBE0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_7:
    // 0x8007EBE4: beq         $v0, $zero, L_8007EBF8
    if (ctx->r2 == 0) {
        // 0x8007EBE8: addiu       $a1, $zero, 0x200
        ctx->r5 = ADD32(0, 0X200);
            goto L_8007EBF8;
    }
    // 0x8007EBE8: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x8007EBEC: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x8007EBF0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8007EBF4: sw          $t0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r8;
L_8007EBF8:
    // 0x8007EBF8: jal         0x8007FB34
    // 0x8007EBFC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    pad_push_also(rdram, ctx);
        goto after_8;
    // 0x8007EBFC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_8:
    // 0x8007EC00: beq         $v0, $zero, L_8007EC14
    if (ctx->r2 == 0) {
        // 0x8007EC04: addiu       $a1, $zero, 0x100
        ctx->r5 = ADD32(0, 0X100);
            goto L_8007EC14;
    }
    // 0x8007EC04: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8007EC08: lw          $t1, 0x5C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X5C);
    // 0x8007EC0C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8007EC10: sw          $t2, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r10;
L_8007EC14:
    // 0x8007EC14: jal         0x8007FB34
    // 0x8007EC18: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    pad_push_also(rdram, ctx);
        goto after_9;
    // 0x8007EC18: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_9:
    // 0x8007EC1C: beql        $v0, $zero, L_8007EC34
    if (ctx->r2 == 0) {
        // 0x8007EC20: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_8007EC34;
    }
    goto skip_3;
    // 0x8007EC20: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    skip_3:
    // 0x8007EC24: lw          $t3, 0x5C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X5C);
    // 0x8007EC28: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007EC2C: sw          $t4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r12;
    // 0x8007EC30: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_8007EC34:
    // 0x8007EC34: jal         0x8007FB34
    // 0x8007EC38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    pad_push_also(rdram, ctx);
        goto after_10;
    // 0x8007EC38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x8007EC3C: beq         $v0, $zero, L_8007ECB4
    if (ctx->r2 == 0) {
        // 0x8007EC40: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_8007ECB4;
    }
    // 0x8007EC40: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8007EC44: jal         0x8007FB34
    // 0x8007EC48: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    pad_push_also(rdram, ctx);
        goto after_11;
    // 0x8007EC48: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_11:
    // 0x8007EC4C: beq         $v0, $zero, L_8007EC60
    if (ctx->r2 == 0) {
        // 0x8007EC50: addiu       $a1, $zero, 0x400
        ctx->r5 = ADD32(0, 0X400);
            goto L_8007EC60;
    }
    // 0x8007EC50: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x8007EC54: lw          $t5, 0x60($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X60);
    // 0x8007EC58: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8007EC5C: sw          $t6, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r14;
L_8007EC60:
    // 0x8007EC60: jal         0x8007FB34
    // 0x8007EC64: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    pad_push_also(rdram, ctx);
        goto after_12;
    // 0x8007EC64: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_12:
    // 0x8007EC68: beq         $v0, $zero, L_8007EC7C
    if (ctx->r2 == 0) {
        // 0x8007EC6C: addiu       $a1, $zero, 0x200
        ctx->r5 = ADD32(0, 0X200);
            goto L_8007EC7C;
    }
    // 0x8007EC6C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x8007EC70: lw          $t7, 0x60($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X60);
    // 0x8007EC74: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8007EC78: sw          $t8, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r24;
L_8007EC7C:
    // 0x8007EC7C: jal         0x8007FB34
    // 0x8007EC80: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    pad_push_also(rdram, ctx);
        goto after_13;
    // 0x8007EC80: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_13:
    // 0x8007EC84: beq         $v0, $zero, L_8007EC98
    if (ctx->r2 == 0) {
        // 0x8007EC88: addiu       $a1, $zero, 0x100
        ctx->r5 = ADD32(0, 0X100);
            goto L_8007EC98;
    }
    // 0x8007EC88: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8007EC8C: lw          $t9, 0x58($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X58);
    // 0x8007EC90: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8007EC94: sw          $t0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r8;
L_8007EC98:
    // 0x8007EC98: jal         0x8007FB34
    // 0x8007EC9C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    pad_push_also(rdram, ctx);
        goto after_14;
    // 0x8007EC9C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_14:
    // 0x8007ECA0: beql        $v0, $zero, L_8007ECB8
    if (ctx->r2 == 0) {
        // 0x8007ECA4: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_8007ECB8;
    }
    goto skip_4;
    // 0x8007ECA4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    skip_4:
    // 0x8007ECA8: lw          $t1, 0x58($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X58);
    // 0x8007ECAC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8007ECB0: sw          $t2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r10;
L_8007ECB4:
    // 0x8007ECB4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_8007ECB8:
    // 0x8007ECB8: jal         0x8007FB34
    // 0x8007ECBC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    pad_push_also(rdram, ctx);
        goto after_15;
    // 0x8007ECBC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_15:
    // 0x8007ECC0: beq         $v0, $zero, L_8007ED38
    if (ctx->r2 == 0) {
        // 0x8007ECC4: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_8007ED38;
    }
    // 0x8007ECC4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8007ECC8: jal         0x8007FB50
    // 0x8007ECCC: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    pad_on_trigger(rdram, ctx);
        goto after_16;
    // 0x8007ECCC: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_16:
    // 0x8007ECD0: beq         $v0, $zero, L_8007ECE4
    if (ctx->r2 == 0) {
        // 0x8007ECD4: addiu       $a1, $zero, 0x400
        ctx->r5 = ADD32(0, 0X400);
            goto L_8007ECE4;
    }
    // 0x8007ECD4: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x8007ECD8: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x8007ECDC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007ECE0: sw          $v0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r2;
L_8007ECE4:
    // 0x8007ECE4: jal         0x8007FB50
    // 0x8007ECE8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    pad_on_trigger(rdram, ctx);
        goto after_17;
    // 0x8007ECE8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_17:
    // 0x8007ECEC: beq         $v0, $zero, L_8007ED00
    if (ctx->r2 == 0) {
        // 0x8007ECF0: addiu       $a1, $zero, 0x200
        ctx->r5 = ADD32(0, 0X200);
            goto L_8007ED00;
    }
    // 0x8007ECF0: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x8007ECF4: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x8007ECF8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007ECFC: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
L_8007ED00:
    // 0x8007ED00: jal         0x8007FB50
    // 0x8007ED04: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    pad_on_trigger(rdram, ctx);
        goto after_18;
    // 0x8007ED04: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_18:
    // 0x8007ED08: beq         $v0, $zero, L_8007ED1C
    if (ctx->r2 == 0) {
        // 0x8007ED0C: addiu       $a1, $zero, 0x100
        ctx->r5 = ADD32(0, 0X100);
            goto L_8007ED1C;
    }
    // 0x8007ED0C: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8007ED10: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x8007ED14: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007ED18: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
L_8007ED1C:
    // 0x8007ED1C: jal         0x8007FB50
    // 0x8007ED20: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    pad_on_trigger(rdram, ctx);
        goto after_19;
    // 0x8007ED20: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_19:
    // 0x8007ED24: beql        $v0, $zero, L_8007ED3C
    if (ctx->r2 == 0) {
        // 0x8007ED28: lw          $t3, 0x5C($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X5C);
            goto L_8007ED3C;
    }
    goto skip_5;
    // 0x8007ED28: lw          $t3, 0x5C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X5C);
    skip_5:
    // 0x8007ED2C: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x8007ED30: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007ED34: sw          $v0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r2;
L_8007ED38:
    // 0x8007ED38: lw          $t3, 0x5C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X5C);
L_8007ED3C:
    // 0x8007ED3C: bgezl       $t3, L_8007ED4C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8007ED40: lw          $t4, 0x64($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X64);
            goto L_8007ED4C;
    }
    goto skip_6;
    // 0x8007ED40: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    skip_6:
    // 0x8007ED44: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x8007ED48: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
L_8007ED4C:
    // 0x8007ED4C: bgezl       $t4, L_8007ED5C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007ED50: lw          $t5, 0x58($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X58);
            goto L_8007ED5C;
    }
    goto skip_7;
    // 0x8007ED50: lw          $t5, 0x58($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X58);
    skip_7:
    // 0x8007ED54: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x8007ED58: lw          $t5, 0x58($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X58);
L_8007ED5C:
    // 0x8007ED5C: blezl       $t5, L_8007ED6C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8007ED60: lw          $v0, 0x60($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X60);
            goto L_8007ED6C;
    }
    goto skip_8;
    // 0x8007ED60: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    skip_8:
    // 0x8007ED64: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    // 0x8007ED68: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
L_8007ED6C:
    // 0x8007ED6C: blezl       $v0, L_8007ED80
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007ED70: lw          $t6, 0x74($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X74);
            goto L_8007ED80;
    }
    goto skip_9;
    // 0x8007ED70: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    skip_9:
    // 0x8007ED74: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x8007ED78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007ED7C: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
L_8007ED80:
    // 0x8007ED80: lw          $a3, 0x70($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X70);
    // 0x8007ED84: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x8007ED88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8007ED8C: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x8007ED90: lw          $a2, 0x300($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X300);
    // 0x8007ED94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007ED98: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8007ED9C: lw          $t8, 0x7C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X7C);
    // 0x8007EDA0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x8007EDA4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8007EDA8: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x8007EDAC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8007EDB0: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
    // 0x8007EDB4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8007EDB8: lw          $t1, 0x5C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X5C);
    // 0x8007EDBC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8007EDC0: lw          $t2, 0x58($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X58);
    // 0x8007EDC4: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8007EDC8: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x8007EDCC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8007EDD0: jal         0x8007E47C
    // 0x8007EDD4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    ViMode_Configure(rdram, ctx);
        goto after_20;
    // 0x8007EDD4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_20:
    // 0x8007EDD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007EDDC: jal         0x8007EAC8
    // 0x8007EDE0: lw          $a1, 0x80($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X80);
    ViMode_ConfigureFeatures(rdram, ctx);
        goto after_21;
    // 0x8007EDE0: lw          $a1, 0x80($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X80);
    after_21:
    // 0x8007EDE4: lw          $t4, 0x68($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X68);
    // 0x8007EDE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007EDEC: bne         $t4, $at, L_8007EE0C
    if (ctx->r12 != ctx->r1) {
        // 0x8007EDF0: nop
    
            goto L_8007EE0C;
    }
    // 0x8007EDF0: nop

    // 0x8007EDF4: jal         0x8007E470
    // 0x8007EDF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ViMode_LogPrint(rdram, ctx);
        goto after_22;
    // 0x8007EDF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8007EDFC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007EE00: sw          $t5, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r13;
    // 0x8007EE04: jal         0x80087010
    // 0x8007EE08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osViSetMode_recomp(rdram, ctx);
        goto after_23;
    // 0x8007EE08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
L_8007EE0C:
    // 0x8007EE0C: jal         0x8007EA24
    // 0x8007EE10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ViMode_Save(rdram, ctx);
        goto after_24;
    // 0x8007EE10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8007EE14: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8007EE18: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8007EE1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8007EE20: jr          $ra
    // 0x8007EE24: nop

    return;
    // 0x8007EE24: nop

;}
RECOMP_FUNC void func_804515E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804515E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804515EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804515F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804515F4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804515F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804515FC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80451600: jal         0x8045111C
    // 0x80451604: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8045111C(rdram, ctx);
        goto after_0;
    // 0x80451604: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80451608: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8045160C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451610: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80451614: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    // 0x80451618: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8045161C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80451620: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80451624: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80451628: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045162C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80451630: ori         $at, $at, 0x6E48
    ctx->r1 = ctx->r1 | 0X6E48;
    // 0x80451634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80451638: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x8045163C: lw          $t6, -0x71A8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X71A8);
    // 0x80451640: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80451644: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80451648: bne         $t8, $zero, L_8045166C
    if (ctx->r24 != 0) {
        // 0x8045164C: nop
    
            goto L_8045166C;
    }
    // 0x8045164C: nop

    // 0x80451650: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451654: ori         $at, $at, 0x6E48
    ctx->r1 = ctx->r1 | 0X6E48;
    // 0x80451658: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    // 0x8045165C: jal         0x80451400
    // 0x80451660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80451400(rdram, ctx);
        goto after_1;
    // 0x80451660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80451664: b           L_80451674
    // 0x80451668: nop

        goto L_80451674;
    // 0x80451668: nop

L_8045166C:
    // 0x8045166C: jal         0x804511DC
    // 0x80451670: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    func_804511DC(rdram, ctx);
        goto after_2;
    // 0x80451670: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    after_2:
L_80451674:
    // 0x80451674: jal         0x804507C4
    // 0x80451678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804507C4(rdram, ctx);
        goto after_3;
    // 0x80451678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8045167C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80451680: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80451684: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80451688: jr          $ra
    // 0x8045168C: nop

    return;
    // 0x8045168C: nop

;}
RECOMP_FUNC void func_8067F6A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067F6A8: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8067F6AC: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(547, 0X4D0) << 16);
    // 0x8067F6B0: addiu       $t6, $t6, -0x940
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(547, 0X4D0));
    // 0x8067F6B4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8067F6B8: jr          $ra
    // 0x8067F6BC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8067F6BC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80064B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064B3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064B40: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80064B44: addiu       $a0, $a0, 0x65AC
    ctx->r4 = ADD32(ctx->r4, 0X65AC);
    // 0x80064B48: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80064B4C: jal         0x80065728
    // 0x80064B50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80064B50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80064B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064B5C: jr          $ra
    // 0x80064B60: nop

    return;
    // 0x80064B60: nop

;}
RECOMP_FUNC void func_804CC830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC830: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804CC834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CC838: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804CC83C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804CC840: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x804CC844: jal         0x80047090
    // 0x804CC848: addiu       $a0, $zero, 0x4139
    ctx->r4 = ADD32(0, 0X4139);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804CC848: addiu       $a0, $zero, 0x4139
    ctx->r4 = ADD32(0, 0X4139);
    after_0:
    // 0x804CC84C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804CC850: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x804CC854: beq         $v0, $at, L_804CC89C
    if (ctx->r2 == ctx->r1) {
        // 0x804CC858: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804CC89C;
    }
    // 0x804CC858: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804CC85C: lui         $at, 0x4139
    ctx->r1 = S32(0X4139 << 16);
    // 0x804CC860: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x804CC864: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x804CC868: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x804CC86C: jal         0x8004613C
    // 0x804CC870: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804CC870: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    after_1:
    // 0x804CC874: beq         $v0, $zero, L_804CC894
    if (ctx->r2 == 0) {
        // 0x804CC878: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804CC894;
    }
    // 0x804CC878: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804CC87C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804CC880: jal         0x80047F9C
    // 0x804CC884: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x804CC884: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x804CC888: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x804CC88C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x804CC890: sh          $t6, 0x144($a1)
    MEM_H(0X144, ctx->r5) = ctx->r14;
L_804CC894:
    // 0x804CC894: b           L_804CC8A0
    // 0x804CC898: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_804CC8A0;
    // 0x804CC898: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_804CC89C:
    // 0x804CC89C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CC8A0:
    // 0x804CC8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CC8A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804CC8A8: jr          $ra
    // 0x804CC8AC: nop

    return;
    // 0x804CC8AC: nop

;}
RECOMP_FUNC void func_80028220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028228: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8002822C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80028230: beq         $t6, $zero, L_80028278
    if (ctx->r14 == 0) {
        // 0x80028234: nop
    
            goto L_80028278;
    }
    // 0x80028234: nop

    // 0x80028238: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002823C: lbu         $t7, 0x1F8($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X1F8);
    // 0x80028240: bnel        $t7, $zero, L_80028258
    if (ctx->r15 != 0) {
        // 0x80028244: lw          $t9, 0xA0($a2)
        ctx->r25 = MEM_W(ctx->r6, 0XA0);
            goto L_80028258;
    }
    goto skip_0;
    // 0x80028244: lw          $t9, 0xA0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA0);
    skip_0:
    // 0x80028248: lw          $t8, 0x12EC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X12EC);
    // 0x8002824C: beql        $t8, $zero, L_80028264
    if (ctx->r24 == 0) {
        // 0x80028250: lw          $t0, 0x9C($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X9C);
            goto L_80028264;
    }
    goto skip_1;
    // 0x80028250: lw          $t0, 0x9C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X9C);
    skip_1:
    // 0x80028254: lw          $t9, 0xA0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA0);
L_80028258:
    // 0x80028258: b           L_80028268
    // 0x8002825C: sw          $t9, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r25;
        goto L_80028268;
    // 0x8002825C: sw          $t9, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r25;
    // 0x80028260: lw          $t0, 0x9C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X9C);
L_80028264:
    // 0x80028264: sw          $t0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r8;
L_80028268:
    // 0x80028268: jal         0x80028170
    // 0x8002826C: addiu       $a1, $a0, 0x14C
    ctx->r5 = ADD32(ctx->r4, 0X14C);
    func_80028170(rdram, ctx);
        goto after_0;
    // 0x8002826C: addiu       $a1, $a0, 0x14C
    ctx->r5 = ADD32(ctx->r4, 0X14C);
    after_0:
    // 0x80028270: b           L_8002827C
    // 0x80028274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002827C;
    // 0x80028274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80028278:
    // 0x80028278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002827C:
    // 0x8002827C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80028280: jr          $ra
    // 0x80028284: nop

    return;
    // 0x80028284: nop

;}
RECOMP_FUNC void func_80428CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80428CC8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80428CCC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80428CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80428CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80428CD8: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1EDC) << 16);
    // 0x80428CDC: lwc1        $f6, -0x67E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1EDC));
    // 0x80428CE0: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80428CE4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80428CE8: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x80428CEC: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80428CF0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80428CF4: nop

    // 0x80428CF8: bc1fl       L_80428D10
    if (!c1cs) {
        // 0x80428CFC: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80428D10;
    }
    goto skip_0;
    // 0x80428CFC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_0:
    // 0x80428D00: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80428D04: b           L_80428D2C
    // 0x80428D08: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
        goto L_80428D2C;
    // 0x80428D08: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x80428D0C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80428D10:
    // 0x80428D10: nop

    // 0x80428D14: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80428D18: nop

    // 0x80428D1C: bc1f        L_80428D2C
    if (!c1cs) {
        // 0x80428D20: nop
    
            goto L_80428D2C;
    }
    // 0x80428D20: nop

    // 0x80428D24: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80428D28: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
L_80428D2C:
    // 0x80428D2C: jal         0x804289D8
    // 0x80428D30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804289D8(rdram, ctx);
        goto after_0;
    // 0x80428D30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80428D34: jal         0x80428C04
    // 0x80428D38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80428C04(rdram, ctx);
        goto after_1;
    // 0x80428D38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80428D3C: jal         0x80428A88
    // 0x80428D40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80428A88(rdram, ctx);
        goto after_2;
    // 0x80428D40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80428D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80428D48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80428D4C: jr          $ra
    // 0x80428D50: nop

    return;
    // 0x80428D50: nop

;}
RECOMP_FUNC void func_8003F460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F460: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003F464: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003F468: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003F46C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003F470: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003F474: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8003F478: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8003F47C: jal         0x8003EBD4
    // 0x8003F480: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8003EBD4(rdram, ctx);
        goto after_0;
    // 0x8003F480: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8003F484: jal         0x8003E520
    // 0x8003F488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003E520(rdram, ctx);
        goto after_1;
    // 0x8003F488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003F48C: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8003F490: sb          $v0, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r2;
    // 0x8003F494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F498: jalr        $t9
    // 0x8003F49C: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8003F49C: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    after_2:
    // 0x8003F4A0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8003F4A4: addiu       $t6, $t6, -0x19E8
    ctx->r14 = ADD32(ctx->r14, -0X19E8);
    // 0x8003F4A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003F4AC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003F4B0: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    // 0x8003F4B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8003F4B8: jal         0x8003E6C4
    // 0x8003F4BC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    func_8003E6C4(rdram, ctx);
        goto after_3;
    // 0x8003F4BC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x8003F4C0: jal         0x800447C8
    // 0x8003F4C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x8003F4C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x8003F4C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003F4CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003F4D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003F4D4: jr          $ra
    // 0x8003F4D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8003F4D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80682FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682FB4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682FB8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682FBC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682FC0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682FC4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682FC8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682FCC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682FD0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682FD4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682FD8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682FDC: jr          $ra
    // 0x80682FE0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682FE0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8052707C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052707C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527084: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80527088: jal         0x800653D8
    // 0x8052708C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8052708C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80527090: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80527094: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80527098: beq         $t6, $zero, L_805270B0
    if (ctx->r14 == 0) {
        // 0x8052709C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_805270B0;
    }
    // 0x8052709C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x805270A0: jal         0x805272E4
    // 0x805270A4: nop

    func_805272E4(rdram, ctx);
        goto after_1;
    // 0x805270A4: nop

    after_1:
    // 0x805270A8: b           L_805270BC
    // 0x805270AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805270BC;
    // 0x805270AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805270B0:
    // 0x805270B0: jal         0x80526F28
    // 0x805270B4: nop

    func_80526F28(rdram, ctx);
        goto after_2;
    // 0x805270B4: nop

    after_2:
    // 0x805270B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805270BC:
    // 0x805270BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805270C0: jr          $ra
    // 0x805270C4: nop

    return;
    // 0x805270C4: nop

;}
RECOMP_FUNC void func_806AE32C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AE32C: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x806AE330: lui         $t9, 0x806B
    ctx->r25 = S32(RELOC_HI16(595, 0X1DEC) << 16);
    // 0x806AE334: addiu       $t9, $t9, -0x4D4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(595, 0X1DEC));
    // 0x806AE338: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806AE33C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x806AE340: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806AE344: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x806AE348: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x806AE34C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x806AE350: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AE354: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x806AE358: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x806AE35C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x806AE360: addiu       $t3, $sp, 0x18
    ctx->r11 = ADD32(ctx->r29, 0X18);
    // 0x806AE364: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806AE368: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x806AE36C: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x806AE370: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x806AE374: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806AE378: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x806AE37C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x806AE380: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x806AE384: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x806AE388: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x806AE38C: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x806AE390: lui         $t0, 0x806B
    ctx->r8 = S32(RELOC_HI16(595, 0X1BAC) << 16);
    // 0x806AE394: addiu       $t0, $t0, -0x714
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(595, 0X1BAC));
    // 0x806AE398: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x806AE39C: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x806AE3A0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x806AE3A4: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x806AE3A8: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x806AE3AC: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x806AE3B0: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x806AE3B4: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x806AE3B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x806AE3BC: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x806AE3C0: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x806AE3C4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x806AE3C8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x806AE3CC: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x806AE3D0: lw          $t5, 0x8($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X8);
    // 0x806AE3D4: sw          $t5, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r13;
    // 0x806AE3D8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x806AE3DC: sw          $t2, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r10;
    // 0x806AE3E0: lw          $t5, 0x10($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X10);
    // 0x806AE3E4: sw          $t5, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r13;
    // 0x806AE3E8: lbu         $t4, 0x26($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X26);
    // 0x806AE3EC: beql        $t4, $zero, L_806AE410
    if (ctx->r12 == 0) {
        // 0x806AE3F0: lw          $t6, 0xC($v0)
        ctx->r14 = MEM_W(ctx->r2, 0XC);
            goto L_806AE410;
    }
    goto skip_0;
    // 0x806AE3F0: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    skip_0:
    // 0x806AE3F4: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x806AE3F8: addiu       $t8, $t7, -0x5
    ctx->r24 = ADD32(ctx->r15, -0X5);
    // 0x806AE3FC: bgez        $t8, L_806AE428
    if (SIGNED(ctx->r24) >= 0) {
        // 0x806AE400: sw          $t8, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r24;
            goto L_806AE428;
    }
    // 0x806AE400: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x806AE404: b           L_806AE428
    // 0x806AE408: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
        goto L_806AE428;
    // 0x806AE408: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x806AE40C: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
L_806AE410:
    // 0x806AE410: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x806AE414: addiu       $t0, $t6, 0x5
    ctx->r8 = ADD32(ctx->r14, 0X5);
    // 0x806AE418: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x806AE41C: bne         $at, $zero, L_806AE428
    if (ctx->r1 != 0) {
        // 0x806AE420: sw          $t0, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r8;
            goto L_806AE428;
    }
    // 0x806AE420: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
    // 0x806AE424: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
L_806AE428:
    // 0x806AE428: lw          $v1, 0x1C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1C);
    // 0x806AE42C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x806AE430: beq         $v1, $zero, L_806AE448
    if (ctx->r3 == 0) {
        // 0x806AE434: nop
    
            goto L_806AE448;
    }
    // 0x806AE434: nop

    // 0x806AE438: lw          $a2, 0x16C($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X16C);
    // 0x806AE43C: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x806AE440: addiu       $a2, $a2, 0xD
    ctx->r6 = ADD32(ctx->r6, 0XD);
    // 0x806AE444: sb          $t2, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r10;
L_806AE448:
    // 0x806AE448: bne         $a0, $a3, L_806AE428
    if (ctx->r4 != ctx->r7) {
        // 0x806AE44C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_806AE428;
    }
    // 0x806AE44C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x806AE450: jr          $ra
    // 0x806AE454: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x806AE454: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80676B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80676B74: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80676B78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80676B7C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80676B80: lw          $v1, 0x404($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X404);
    // 0x80676B84: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x80676B88: bne         $v1, $zero, L_80676B98
    if (ctx->r3 != 0) {
        // 0x80676B8C: nop
    
            goto L_80676B98;
    }
    // 0x80676B8C: nop

    // 0x80676B90: jr          $ra
    // 0x80676B94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80676B94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80676B98:
    // 0x80676B98: lw          $t6, 0x188($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X188);
    // 0x80676B9C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80676BA0: bnel        $v1, $t6, L_80676BB4
    if (ctx->r3 != ctx->r14) {
        // 0x80676BA4: lw          $t7, 0x18C($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X18C);
            goto L_80676BB4;
    }
    goto skip_0;
    // 0x80676BA4: lw          $t7, 0x18C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X18C);
    skip_0:
    // 0x80676BA8: jr          $ra
    // 0x80676BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80676BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80676BB0: lw          $t7, 0x18C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X18C);
L_80676BB4:
    // 0x80676BB4: bnel        $v1, $t7, L_80676BC8
    if (ctx->r3 != ctx->r15) {
        // 0x80676BB8: lw          $t8, 0x190($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X190);
            goto L_80676BC8;
    }
    goto skip_1;
    // 0x80676BB8: lw          $t8, 0x190($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X190);
    skip_1:
    // 0x80676BBC: jr          $ra
    // 0x80676BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80676BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80676BC4: lw          $t8, 0x190($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X190);
L_80676BC8:
    // 0x80676BC8: bnel        $v1, $t8, L_80676BDC
    if (ctx->r3 != ctx->r24) {
        // 0x80676BCC: lw          $t9, 0x194($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X194);
            goto L_80676BDC;
    }
    goto skip_2;
    // 0x80676BCC: lw          $t9, 0x194($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X194);
    skip_2:
    // 0x80676BD0: jr          $ra
    // 0x80676BD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80676BD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80676BD8: lw          $t9, 0x194($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X194);
L_80676BDC:
    // 0x80676BDC: bne         $v1, $t9, L_80676BEC
    if (ctx->r3 != ctx->r25) {
        // 0x80676BE0: nop
    
            goto L_80676BEC;
    }
    // 0x80676BE0: nop

    // 0x80676BE4: jr          $ra
    // 0x80676BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80676BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80676BEC:
    // 0x80676BEC: bne         $a1, $v0, L_80676B98
    if (ctx->r5 != ctx->r2) {
        // 0x80676BF0: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_80676B98;
    }
    // 0x80676BF0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80676BF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80676BF8: jr          $ra
    // 0x80676BFC: nop

    return;
    // 0x80676BFC: nop

;}
RECOMP_FUNC void func_805ABDE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ABDE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805ABDE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805ABDEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805ABDF0: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(438, 0X590) << 16);
    // 0x805ABDF4: lwc1        $f6, -0x3EE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(438, 0X590));
    // 0x805ABDF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805ABDFC: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x805ABE00: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x805ABE04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805ABE08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805ABE0C: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x805ABE10: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x805ABE14: jal         0x805ABD0C
    // 0x805ABE18: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_805ABD0C(rdram, ctx);
        goto after_0;
    // 0x805ABE18: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x805ABE1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805ABE20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805ABE24: jr          $ra
    // 0x805ABE28: nop

    return;
    // 0x805ABE28: nop

;}
RECOMP_FUNC void func_8002D49C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D49C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002D4A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D4A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002D4A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002D4AC: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002D4B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002D4B4: jal         0x8002D198
    // 0x8002D4B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8002D198(rdram, ctx);
        goto after_0;
    // 0x8002D4B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8002D4BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002D4C0: jal         0x8002BB90
    // 0x8002D4C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8002BB90(rdram, ctx);
        goto after_1;
    // 0x8002D4C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8002D4C8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002D4CC: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002D4D0: addiu       $a1, $a1, -0x2878
    ctx->r5 = ADD32(ctx->r5, -0X2878);
    // 0x8002D4D4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8002D4D8: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x8002D4DC: addiu       $t8, $t8, 0x8D0
    ctx->r24 = ADD32(ctx->r24, 0X8D0);
    // 0x8002D4E0: sb          $t6, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r14;
    // 0x8002D4E4: sb          $t7, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r15;
    // 0x8002D4E8: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x8002D4EC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002D4F0: jal         0x80028118
    // 0x8002D4F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028118(rdram, ctx);
        goto after_2;
    // 0x8002D4F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8002D4F8: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8002D4FC: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x8002D500: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002D504: sw          $t9, 0x1A4($s1)
    MEM_W(0X1A4, ctx->r17) = ctx->r25;
    // 0x8002D508: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8002D50C: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x8002D510: swc1        $f6, 0x12D8($s1)
    MEM_W(0X12D8, ctx->r17) = ctx->f6.u32l;
    // 0x8002D514: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8002D518: jal         0x8002AEE4
    // 0x8002D51C: swc1        $f8, 0x12DC($s1)
    MEM_W(0X12DC, ctx->r17) = ctx->f8.u32l;
    func_8002AEE4(rdram, ctx);
        goto after_3;
    // 0x8002D51C: swc1        $f8, 0x12DC($s1)
    MEM_W(0X12DC, ctx->r17) = ctx->f8.u32l;
    after_3:
    // 0x8002D520: jal         0x800677F8
    // 0x8002D524: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_800677F8(rdram, ctx);
        goto after_4;
    // 0x8002D524: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_4:
    // 0x8002D528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D52C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002D530: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002D534: jr          $ra
    // 0x8002D538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002D538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806CD6B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CD6B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CD6B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CD6BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CD6C0: jal         0x806CCF00
    // 0x806CD6C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806CCF00(rdram, ctx);
        goto after_0;
    // 0x806CD6C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806CD6C8: jal         0x806CD470
    // 0x806CD6CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CD470(rdram, ctx);
        goto after_1;
    // 0x806CD6CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CD6D0: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x806CD6D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD6D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CD6DC: blez        $v0, L_806CD6EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806CD6E0: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806CD6EC;
    }
    // 0x806CD6E0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806CD6E4: b           L_806CD704
    // 0x806CD6E8: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
        goto L_806CD704;
    // 0x806CD6E8: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_806CD6EC:
    // 0x806CD6EC: jal         0x806CED40
    // 0x806CD6F0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_806CED40(rdram, ctx);
        goto after_2;
    // 0x806CD6F0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_2:
    // 0x806CD6F4: jal         0x806CCCE4
    // 0x806CD6F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCCE4(rdram, ctx);
        goto after_3;
    // 0x806CD6F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806CD6FC: jal         0x806CC008
    // 0x806CD700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CC008(rdram, ctx);
        goto after_4;
    // 0x806CD700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_806CD704:
    // 0x806CD704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806CD708: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CD70C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CD710: jr          $ra
    // 0x806CD714: nop

    return;
    // 0x806CD714: nop

;}
RECOMP_FUNC void func_804BB940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BB944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BB948: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x804BB94C: addiu       $t7, $t6, -0x4129
    ctx->r15 = ADD32(ctx->r14, -0X4129);
    // 0x804BB950: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x804BB954: beq         $at, $zero, L_804BB9C8
    if (ctx->r1 == 0) {
        // 0x804BB958: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_804BB9C8;
    }
    // 0x804BB958: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804BB95C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4140) << 16);
    // 0x804BB960: addu        $at, $at, $t7
    gpr jr_addend_804BB968 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x804BB964: lw          $t7, -0x590($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(191, 0X4140));
    // 0x804BB968: jr          $t7
    // 0x804BB96C: nop

    switch (jr_addend_804BB968 >> 2) {
        case 0: goto L_804BB970; break;
        case 1: goto L_804BB990; break;
        case 2: goto L_804BB980; break;
        case 3: goto L_804BB9C8; break;
        case 4: goto L_804BB9C8; break;
        case 5: goto L_804BB9A0; break;
        case 6: goto L_804BB9B0; break;
        case 7: goto L_804BB9C0; break;
        default: switch_error(__func__, 0x804BB968, 0x804BFA70);
    }
    // 0x804BB96C: nop

L_804BB970:
    // 0x804BB970: jal         0x804BD44C
    // 0x804BB974: nop

    func_804BD44C(rdram, ctx);
        goto after_0;
    // 0x804BB974: nop

    after_0:
    // 0x804BB978: b           L_804BB9CC
    // 0x804BB97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804BB9CC;
    // 0x804BB97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BB980:
    // 0x804BB980: jal         0x804BBA18
    // 0x804BB984: nop

    func_804BBA18(rdram, ctx);
        goto after_1;
    // 0x804BB984: nop

    after_1:
    // 0x804BB988: b           L_804BB9CC
    // 0x804BB98C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804BB9CC;
    // 0x804BB98C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BB990:
    // 0x804BB990: jal         0x804BD0C8
    // 0x804BB994: nop

    func_804BD0C8(rdram, ctx);
        goto after_2;
    // 0x804BB994: nop

    after_2:
    // 0x804BB998: b           L_804BB9CC
    // 0x804BB99C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804BB9CC;
    // 0x804BB99C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BB9A0:
    // 0x804BB9A0: jal         0x804BD4E0
    // 0x804BB9A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_804BD4E0(rdram, ctx);
        goto after_3;
    // 0x804BB9A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x804BB9A8: b           L_804BB9CC
    // 0x804BB9AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804BB9CC;
    // 0x804BB9AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BB9B0:
    // 0x804BB9B0: jal         0x804BD4E0
    // 0x804BB9B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804BD4E0(rdram, ctx);
        goto after_4;
    // 0x804BB9B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x804BB9B8: b           L_804BB9CC
    // 0x804BB9BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804BB9CC;
    // 0x804BB9BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BB9C0:
    // 0x804BB9C0: jal         0x804BD4E0
    // 0x804BB9C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_804BD4E0(rdram, ctx);
        goto after_5;
    // 0x804BB9C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
L_804BB9C8:
    // 0x804BB9C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BB9CC:
    // 0x804BB9CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BB9D0: jr          $ra
    // 0x804BB9D4: nop

    return;
    // 0x804BB9D4: nop

;}
