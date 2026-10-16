#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8045B19C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B19C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8045B1A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045B1A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045B1A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8045B1AC: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8045B1B0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8045B1B4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8045B1B8: sh          $t6, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r14;
    // 0x8045B1BC: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045B1C0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8045B1C4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8045B1C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8045B1CC: jal         0x80062AEC
    // 0x8045B1D0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x8045B1D0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_0:
    // 0x8045B1D4: lhu         $t8, 0x2E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2E);
    // 0x8045B1D8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8045B1DC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8045B1E0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8045B1E4: bne         $t8, $at, L_8045B368
    if (ctx->r24 != ctx->r1) {
        // 0x8045B1E8: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_8045B368;
    }
    // 0x8045B1E8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8045B1EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8045B1F0: bnel        $v0, $at, L_8045B26C
    if (ctx->r2 != ctx->r1) {
        // 0x8045B1F4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8045B26C;
    }
    goto skip_0;
    // 0x8045B1F4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_0:
    // 0x8045B1F8: lwc1        $f0, 0x4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8045B1FC: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8045B200: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8045B204: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8045B208: lwc1        $f8, 0xC8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8045B20C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8045B210: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8045B214: nop

    // 0x8045B218: bc1f        L_8045B2D0
    if (!c1cs) {
        // 0x8045B21C: sub.s       $f14, $f4, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_8045B2D0;
    }
    // 0x8045B21C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8045B220: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8045B224: nop

    // 0x8045B228: bc1fl       L_8045B2D4
    if (!c1cs) {
        // 0x8045B22C: lhu         $v0, 0x40($t0)
        ctx->r2 = MEM_HU(ctx->r8, 0X40);
            goto L_8045B2D4;
    }
    goto skip_1;
    // 0x8045B22C: lhu         $v0, 0x40($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X40);
    skip_1:
    // 0x8045B230: sqrt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = sqrtf(ctx->f14.fl);
    // 0x8045B234: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045B238: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8045B23C: nop

    // 0x8045B240: bc1fl       L_8045B2D4
    if (!c1cs) {
        // 0x8045B244: lhu         $v0, 0x40($t0)
        ctx->r2 = MEM_HU(ctx->r8, 0X40);
            goto L_8045B2D4;
    }
    goto skip_2;
    // 0x8045B244: lhu         $v0, 0x40($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X40);
    skip_2:
    // 0x8045B248: sub.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8045B24C: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8045B250: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8045B254: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x8045B258: lhu         $t9, 0x40($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X40);
    // 0x8045B25C: ori         $t1, $t9, 0x4
    ctx->r9 = ctx->r25 | 0X4;
    // 0x8045B260: b           L_8045B2D0
    // 0x8045B264: sh          $t1, 0x40($t0)
    MEM_H(0X40, ctx->r8) = ctx->r9;
        goto L_8045B2D0;
    // 0x8045B264: sh          $t1, 0x40($t0)
    MEM_H(0X40, ctx->r8) = ctx->r9;
    // 0x8045B268: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_8045B26C:
    // 0x8045B26C: bne         $v0, $at, L_8045B28C
    if (ctx->r2 != ctx->r1) {
        // 0x8045B270: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8045B28C;
    }
    // 0x8045B270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045B274: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8045B278: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8045B27C: jal         0x8002F6E4
    // 0x8045B280: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x8045B280: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_1:
    // 0x8045B284: b           L_8045B2D0
    // 0x8045B288: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
        goto L_8045B2D0;
    // 0x8045B288: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_8045B28C:
    // 0x8045B28C: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8045B290: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8045B294: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045B298: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8045B29C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8045B2A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045B2A4: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8045B2A8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8045B2AC: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8045B2B0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8045B2B4: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8045B2B8: nop

    // 0x8045B2BC: bc1fl       L_8045B2D4
    if (!c1cs) {
        // 0x8045B2C0: lhu         $v0, 0x40($t0)
        ctx->r2 = MEM_HU(ctx->r8, 0X40);
            goto L_8045B2D4;
    }
    goto skip_3;
    // 0x8045B2C0: lhu         $v0, 0x40($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X40);
    skip_3:
    // 0x8045B2C4: jal         0x8002F6E4
    // 0x8045B2C8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_8002F6E4(rdram, ctx);
        goto after_2;
    // 0x8045B2C8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_2:
    // 0x8045B2CC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_8045B2D0:
    // 0x8045B2D0: lhu         $v0, 0x40($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X40);
L_8045B2D4:
    // 0x8045B2D4: andi        $t2, $v0, 0x2
    ctx->r10 = ctx->r2 & 0X2;
    // 0x8045B2D8: beq         $t2, $zero, L_8045B33C
    if (ctx->r10 == 0) {
        // 0x8045B2DC: andi        $t3, $v0, 0x4
        ctx->r11 = ctx->r2 & 0X4;
            goto L_8045B33C;
    }
    // 0x8045B2DC: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x8045B2E0: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x8045B2E4: bnel        $t3, $zero, L_8045B318
    if (ctx->r11 != 0) {
        // 0x8045B2E8: lw          $t7, 0x174($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X174);
            goto L_8045B318;
    }
    goto skip_4;
    // 0x8045B2E8: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    skip_4:
    // 0x8045B2EC: lw          $v1, 0x174($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X174);
    // 0x8045B2F0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8045B2F4: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x8045B2F8: bnel        $t4, $t5, L_8045B30C
    if (ctx->r12 != ctx->r13) {
        // 0x8045B2FC: andi        $t6, $v0, 0xFFFD
        ctx->r14 = ctx->r2 & 0XFFFD;
            goto L_8045B30C;
    }
    goto skip_5;
    // 0x8045B2FC: andi        $t6, $v0, 0xFFFD
    ctx->r14 = ctx->r2 & 0XFFFD;
    skip_5:
    // 0x8045B300: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8045B304: lhu         $v0, 0x40($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X40);
    // 0x8045B308: andi        $t6, $v0, 0xFFFD
    ctx->r14 = ctx->r2 & 0XFFFD;
L_8045B30C:
    // 0x8045B30C: b           L_8045B368
    // 0x8045B310: sh          $t6, 0x40($t0)
    MEM_H(0X40, ctx->r8) = ctx->r14;
        goto L_8045B368;
    // 0x8045B310: sh          $t6, 0x40($t0)
    MEM_H(0X40, ctx->r8) = ctx->r14;
    // 0x8045B314: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
L_8045B318:
    // 0x8045B318: ori         $t9, $v0, 0x2
    ctx->r25 = ctx->r2 | 0X2;
    // 0x8045B31C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8045B320: bnel        $t8, $zero, L_8045B36C
    if (ctx->r24 != 0) {
        // 0x8045B324: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8045B36C;
    }
    goto skip_6;
    // 0x8045B324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8045B328: sh          $t9, 0x40($t0)
    MEM_H(0X40, ctx->r8) = ctx->r25;
    // 0x8045B32C: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x8045B330: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8045B334: b           L_8045B368
    // 0x8045B338: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
        goto L_8045B368;
    // 0x8045B338: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_8045B33C:
    // 0x8045B33C: beql        $t3, $zero, L_8045B36C
    if (ctx->r11 == 0) {
        // 0x8045B340: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8045B36C;
    }
    goto skip_7;
    // 0x8045B340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8045B344: lw          $t4, 0x174($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X174);
    // 0x8045B348: ori         $t6, $v0, 0x2
    ctx->r14 = ctx->r2 | 0X2;
    // 0x8045B34C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8045B350: bnel        $t5, $zero, L_8045B36C
    if (ctx->r13 != 0) {
        // 0x8045B354: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8045B36C;
    }
    goto skip_8;
    // 0x8045B354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x8045B358: sh          $t6, 0x40($t0)
    MEM_H(0X40, ctx->r8) = ctx->r14;
    // 0x8045B35C: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x8045B360: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8045B364: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_8045B368:
    // 0x8045B368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8045B36C:
    // 0x8045B36C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045B370: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8045B374: jr          $ra
    // 0x8045B378: nop

    return;
    // 0x8045B378: nop

;}
RECOMP_FUNC void func_8064E70C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E70C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8064E710: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064E714: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064E718: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064E71C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064E720: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8064E724: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8064E728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8064E72C: jal         0x80048F84
    // 0x8064E730: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8064E730: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x8064E734: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8064E738: jal         0x80048F84
    // 0x8064E73C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8064E73C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8064E740: jal         0x8064E014
    // 0x8064E744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064E014(rdram, ctx);
        goto after_2;
    // 0x8064E744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8064E748: bne         $v0, $zero, L_8064E7AC
    if (ctx->r2 != 0) {
        // 0x8064E74C: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_8064E7AC;
    }
    // 0x8064E74C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8064E750: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x8064E754: beq         $v0, $zero, L_8064E764
    if (ctx->r2 == 0) {
        // 0x8064E758: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8064E764;
    }
    // 0x8064E758: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8064E75C: b           L_8064E7AC
    // 0x8064E760: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
        goto L_8064E7AC;
    // 0x8064E760: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
L_8064E764:
    // 0x8064E764: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8064E768: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8064E76C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8064E770: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8064E774: jal         0x8006593C
    // 0x8064E778: nop

    func_8006593C(rdram, ctx);
        goto after_3;
    // 0x8064E778: nop

    after_3:
    // 0x8064E77C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8064E780: lui         $a1, 0x8065
    ctx->r5 = S32(RELOC_HI16(498, 0XB78) << 16);
    // 0x8064E784: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8064E788: lw          $a1, -0x17B8($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(498, 0XB78));
    // 0x8064E78C: jal         0x8064E194
    // 0x8064E790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064E194(rdram, ctx);
        goto after_4;
    // 0x8064E790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8064E794: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8064E798: jal         0x80067BBC
    // 0x8064E79C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x8064E79C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x8064E7A0: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    // 0x8064E7A4: jal         0x80067818
    // 0x8064E7A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8064E7A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
L_8064E7AC:
    // 0x8064E7AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8064E7B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064E7B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8064E7B8: jr          $ra
    // 0x8064E7BC: nop

    return;
    // 0x8064E7BC: nop

;}
RECOMP_FUNC void func_8064F1F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F1F8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F1FC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F200: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F204: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F208: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F20C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F210: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F214: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F218: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F21C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F220: jr          $ra
    // 0x8064F224: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F224: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80073A78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073A78: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80073A7C: lui         $a3, 0x600
    ctx->r7 = S32(0X600 << 16);
    // 0x80073A80: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80073A84: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073A88: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80073A8C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80073A90: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80073A94: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073A98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80073A9C: lui         $t7, 0xD00
    ctx->r15 = S32(0XD00 << 16);
    // 0x80073AA0: addiu       $t7, $t7, 0x150
    ctx->r15 = ADD32(ctx->r15, 0X150);
    // 0x80073AA4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80073AA8: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x80073AAC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073AB0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80073AB4: lui         $t8, 0xD00
    ctx->r24 = S32(0XD00 << 16);
    // 0x80073AB8: addiu       $t8, $t8, 0x198
    ctx->r24 = ADD32(ctx->r24, 0X198);
    // 0x80073ABC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x80073AC0: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x80073AC4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073AC8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80073ACC: jr          $ra
    // 0x80073AD0: nop

    return;
    // 0x80073AD0: nop

;}
RECOMP_FUNC void func_80552408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80552408: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x8055240C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80552410: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80552414: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80552418: sw          $a0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r4;
    // 0x8055241C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80552420: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80552424: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80552428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8055242C: jal         0x8004921C
    // 0x80552430: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80552430: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
    after_0:
    // 0x80552434: sh          $v0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r2;
    // 0x80552438: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8055243C: jal         0x8004921C
    // 0x80552440: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80552440: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80552444: lbu         $t9, 0x47($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X47);
    // 0x80552448: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8055244C: lbu         $t3, 0x145($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X145);
    // 0x80552450: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80552454: lw          $t7, 0x16C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X16C);
    // 0x80552458: lw          $t5, 0x168($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X168);
    // 0x8055245C: addiu       $a0, $sp, 0x100
    ctx->r4 = ADD32(ctx->r29, 0X100);
    // 0x80552460: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80552464: lw          $t6, 0x80($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X80);
    // 0x80552468: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8055246C: sw          $t8, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r24;
    // 0x80552470: lw          $s0, 0x1F4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X1F4);
    // 0x80552474: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80552478: mflo        $t2
    ctx->r10 = lo;
    // 0x8055247C: lw          $t9, 0xD64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XD64);
    // 0x80552480: nop

    // 0x80552484: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80552488: mflo        $t4
    ctx->r12 = lo;
    // 0x8055248C: addu        $v1, $t4, $t6
    ctx->r3 = ADD32(ctx->r12, ctx->r14);
    // 0x80552490: addu        $t2, $t9, $v1
    ctx->r10 = ADD32(ctx->r25, ctx->r3);
    // 0x80552494: sw          $t2, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r10;
    // 0x80552498: lw          $t3, 0xD78($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XD78);
    // 0x8055249C: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x805524A0: sw          $t5, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r13;
    // 0x805524A4: lw          $t4, 0xD8C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XD8C);
    // 0x805524A8: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x805524AC: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x805524B0: lw          $t7, 0xDA0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XDA0);
    // 0x805524B4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x805524B8: jal         0x80077338
    // 0x805524BC: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x805524BC: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    after_2:
    // 0x805524C0: addiu       $a0, $sp, 0x100
    ctx->r4 = ADD32(ctx->r29, 0X100);
    // 0x805524C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805524C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805524CC: jal         0x8007711C
    // 0x805524D0: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x805524D0: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    after_3:
    // 0x805524D4: jal         0x80551A04
    // 0x805524D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80551A04(rdram, ctx);
        goto after_4;
    // 0x805524D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x805524DC: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x805524E0: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x805524E4: ori         $t3, $t3, 0x81FF
    ctx->r11 = ctx->r11 | 0X81FF;
    // 0x805524E8: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x805524EC: sw          $t2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r10;
    // 0x805524F0: addiu       $a3, $s0, 0x950
    ctx->r7 = ADD32(ctx->r16, 0X950);
    // 0x805524F4: sw          $a3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r7;
    // 0x805524F8: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x805524FC: lw          $t5, 0x100($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X100);
    // 0x80552500: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x80552504: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x80552508: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x8055250C: sw          $t4, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r12;
    // 0x80552510: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80552514: lw          $t7, 0xE8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE8);
    // 0x80552518: lui         $t2, 0xF550
    ctx->r10 = S32(0XF550 << 16);
    // 0x8055251C: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x80552520: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80552524: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x80552528: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8055252C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552530: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80552534: sw          $t9, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r25;
    // 0x80552538: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8055253C: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80552540: lw          $t5, 0x100($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X100);
    // 0x80552544: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80552548: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x8055254C: sw          $t4, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r12;
    // 0x80552550: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80552554: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80552558: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x8055255C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80552560: sw          $t8, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r24;
    // 0x80552564: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80552568: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8055256C: jal         0x8004921C
    // 0x80552570: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_5;
    // 0x80552570: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    after_5:
    // 0x80552574: sh          $v0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r2;
    // 0x80552578: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8055257C: jal         0x8004921C
    // 0x80552580: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_6;
    // 0x80552580: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80552584: lh          $t2, 0x46($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X46);
    // 0x80552588: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8055258C: mflo        $t3
    ctx->r11 = lo;
    // 0x80552590: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x80552594: sra         $t4, $t5, 1
    ctx->r12 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80552598: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x8055259C: slti        $at, $t6, 0x7FF
    ctx->r1 = SIGNED(ctx->r14) < 0X7FF ? 1 : 0;
    // 0x805525A0: beq         $at, $zero, L_805525E0
    if (ctx->r1 == 0) {
        // 0x805525A4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_805525E0;
    }
    // 0x805525A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805525A8: jal         0x8004921C
    // 0x805525AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_7;
    // 0x805525AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x805525B0: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x805525B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805525B8: jal         0x8004921C
    // 0x805525BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_8;
    // 0x805525BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x805525C0: lh          $t7, 0x36($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X36);
    // 0x805525C4: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805525C8: mflo        $t8
    ctx->r24 = lo;
    // 0x805525CC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x805525D0: sra         $t2, $t9, 1
    ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
    // 0x805525D4: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x805525D8: b           L_805525E8
    // 0x805525DC: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
        goto L_805525E8;
    // 0x805525DC: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
L_805525E0:
    // 0x805525E0: addiu       $t5, $zero, 0x7FF
    ctx->r13 = ADD32(0, 0X7FF);
    // 0x805525E4: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
L_805525E8:
    // 0x805525E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805525EC: jal         0x8004921C
    // 0x805525F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_9;
    // 0x805525F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x805525F4: bgez        $v0, L_80552604
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805525F8: sra         $t4, $v0, 3
        ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80552604;
    }
    // 0x805525F8: sra         $t4, $v0, 3
    ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805525FC: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80552600: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_80552604:
    // 0x80552604: bgtzl       $t4, L_80552618
    if (SIGNED(ctx->r12) > 0) {
        // 0x80552608: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80552618;
    }
    goto skip_0;
    // 0x80552608: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8055260C: b           L_80552630
    // 0x80552610: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80552630;
    // 0x80552610: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80552614: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80552618:
    // 0x80552618: jal         0x8004921C
    // 0x8055261C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_10;
    // 0x8055261C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80552620: bgez        $v0, L_80552630
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80552624: sra         $t0, $v0, 3
        ctx->r8 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80552630;
    }
    // 0x80552624: sra         $t0, $v0, 3
    ctx->r8 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80552628: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x8055262C: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_80552630:
    // 0x80552630: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552638: jal         0x8004921C
    // 0x8055263C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_8004921C(rdram, ctx);
        goto after_11;
    // 0x8055263C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_11:
    // 0x80552640: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80552644: bgez        $v0, L_80552654
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80552648: sra         $t6, $v0, 3
        ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80552654;
    }
    // 0x80552648: sra         $t6, $v0, 3
    ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8055264C: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80552650: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_80552654:
    // 0x80552654: bgtzl       $t6, L_80552668
    if (SIGNED(ctx->r14) > 0) {
        // 0x80552658: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80552668;
    }
    goto skip_1;
    // 0x80552658: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x8055265C: b           L_80552688
    // 0x80552660: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80552688;
    // 0x80552660: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80552664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80552668:
    // 0x80552668: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8055266C: jal         0x8004921C
    // 0x80552670: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_8004921C(rdram, ctx);
        goto after_12;
    // 0x80552670: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_12:
    // 0x80552674: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80552678: bgez        $v0, L_80552688
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8055267C: sra         $v1, $v0, 3
        ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80552688;
    }
    // 0x8055267C: sra         $v1, $v0, 3
    ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80552680: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80552684: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_80552688:
    // 0x80552688: addiu       $t7, $t0, 0x7FF
    ctx->r15 = ADD32(ctx->r8, 0X7FF);
    // 0x8055268C: div         $zero, $t7, $v1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r3)));
    // 0x80552690: bne         $v1, $zero, L_8055269C
    if (ctx->r3 != 0) {
        // 0x80552694: nop
    
            goto L_8055269C;
    }
    // 0x80552694: nop

    // 0x80552698: break       7
    do_break(2153064088);
L_8055269C:
    // 0x8055269C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805526A0: bne         $v1, $at, L_805526B4
    if (ctx->r3 != ctx->r1) {
        // 0x805526A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805526B4;
    }
    // 0x805526A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805526A8: bne         $t7, $at, L_805526B4
    if (ctx->r15 != ctx->r1) {
        // 0x805526AC: nop
    
            goto L_805526B4;
    }
    // 0x805526AC: nop

    // 0x805526B0: break       6
    do_break(2153064112);
L_805526B4:
    // 0x805526B4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x805526B8: mflo        $t8
    ctx->r24 = lo;
    // 0x805526BC: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x805526C0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x805526C4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x805526C8: andi        $t5, $t3, 0xFFF
    ctx->r13 = ctx->r11 & 0XFFF;
    // 0x805526CC: sll         $t4, $t5, 12
    ctx->r12 = S32(ctx->r13 << 12);
    // 0x805526D0: or          $t2, $t9, $at
    ctx->r10 = ctx->r25 | ctx->r1;
    // 0x805526D4: or          $t6, $t2, $t4
    ctx->r14 = ctx->r10 | ctx->r12;
    // 0x805526D8: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x805526DC: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x805526E0: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x805526E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805526E8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x805526EC: sw          $t9, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r25;
    // 0x805526F0: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x805526F4: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x805526F8: lw          $t5, 0x100($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X100);
    // 0x805526FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552700: addiu       $t2, $t5, 0x8
    ctx->r10 = ADD32(ctx->r13, 0X8);
    // 0x80552704: sw          $t2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r10;
    // 0x80552708: jal         0x8004921C
    // 0x8055270C: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    func_8004921C(rdram, ctx);
        goto after_13;
    // 0x8055270C: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    after_13:
    // 0x80552710: addiu       $t4, $v0, 0x7
    ctx->r12 = ADD32(ctx->r2, 0X7);
    // 0x80552714: sra         $t6, $t4, 3
    ctx->r14 = S32(SIGNED(ctx->r12) >> 3);
    // 0x80552718: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x8055271C: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x80552720: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80552724: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80552728: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8055272C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80552730: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x80552734: lui         $t2, 0xF200
    ctx->r10 = S32(0XF200 << 16);
    // 0x80552738: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8055273C: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x80552740: sw          $t5, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r13;
    // 0x80552744: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80552748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8055274C: jal         0x8004921C
    // 0x80552750: sw          $t3, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r11;
    func_8004921C(rdram, ctx);
        goto after_14;
    // 0x80552750: sw          $t3, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r11;
    after_14:
    // 0x80552754: sh          $v0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r2;
    // 0x80552758: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8055275C: jal         0x8004921C
    // 0x80552760: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_15;
    // 0x80552760: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80552764: lh          $t8, 0x46($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X46);
    // 0x80552768: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8055276C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80552770: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80552774: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80552778: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8055277C: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x80552780: andi        $t5, $t3, 0xFFF
    ctx->r13 = ctx->r11 & 0XFFF;
    // 0x80552784: sll         $t2, $t5, 12
    ctx->r10 = S32(ctx->r13 << 12);
    // 0x80552788: or          $t4, $t7, $t2
    ctx->r12 = ctx->r15 | ctx->r10;
    // 0x8055278C: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x80552790: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x80552794: lui         $s0, 0xBF00
    ctx->r16 = S32(0XBF00 << 16);
    // 0x80552798: addiu       $t3, $zero, 0x204
    ctx->r11 = ADD32(0, 0X204);
    // 0x8055279C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x805527A0: sw          $t9, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r25;
    // 0x805527A4: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x805527A8: sw          $s0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r16;
    // 0x805527AC: lw          $t5, 0x100($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X100);
    // 0x805527B0: lui         $t2, 0x2
    ctx->r10 = S32(0X2 << 16);
    // 0x805527B4: ori         $t2, $t2, 0x604
    ctx->r10 = ctx->r10 | 0X604;
    // 0x805527B8: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x805527BC: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
    // 0x805527C0: sw          $s0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r16;
    // 0x805527C4: sw          $t2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r10;
    // 0x805527C8: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
    // 0x805527CC: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x805527D0: ori         $t8, $t8, 0xA0C
    ctx->r24 = ctx->r24 | 0XA0C;
    // 0x805527D4: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x805527D8: sw          $t6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r14;
    // 0x805527DC: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x805527E0: sw          $s0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r16;
    // 0x805527E4: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x805527E8: lui         $t5, 0xA
    ctx->r13 = S32(0XA << 16);
    // 0x805527EC: ori         $t5, $t5, 0xE0C
    ctx->r13 = ctx->r13 | 0XE0C;
    // 0x805527F0: addiu       $t3, $t9, 0x8
    ctx->r11 = ADD32(ctx->r25, 0X8);
    // 0x805527F4: sw          $t3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r11;
    // 0x805527F8: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x805527FC: sw          $s0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r16;
    // 0x80552800: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x80552804: lui         $t4, 0x10
    ctx->r12 = S32(0X10 << 16);
    // 0x80552808: ori         $t4, $t4, 0x1214
    ctx->r12 = ctx->r12 | 0X1214;
    // 0x8055280C: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x80552810: sw          $t2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r10;
    // 0x80552814: sw          $t4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r12;
    // 0x80552818: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x8055281C: lw          $t6, 0x100($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X100);
    // 0x80552820: lui         $t9, 0x12
    ctx->r25 = S32(0X12 << 16);
    // 0x80552824: ori         $t9, $t9, 0x1614
    ctx->r25 = ctx->r25 | 0X1614;
    // 0x80552828: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8055282C: sw          $t8, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r24;
    // 0x80552830: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80552834: sw          $s0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r16;
    // 0x80552838: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x8055283C: lui         $t7, 0x18
    ctx->r15 = S32(0X18 << 16);
    // 0x80552840: ori         $t7, $t7, 0x1A1C
    ctx->r15 = ctx->r15 | 0X1A1C;
    // 0x80552844: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x80552848: sw          $t5, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r13;
    // 0x8055284C: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x80552850: sw          $s0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r16;
    // 0x80552854: lw          $t2, 0x100($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X100);
    // 0x80552858: lui         $t6, 0x1A
    ctx->r14 = S32(0X1A << 16);
    // 0x8055285C: ori         $t6, $t6, 0x1E1C
    ctx->r14 = ctx->r14 | 0X1E1C;
    // 0x80552860: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x80552864: sw          $t4, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r12;
    // 0x80552868: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8055286C: sw          $s0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r16;
    // 0x80552870: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x80552874: lui         $t3, 0xFD50
    ctx->r11 = S32(0XFD50 << 16);
    // 0x80552878: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8055287C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80552880: sw          $t9, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r25;
    // 0x80552884: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x80552888: lw          $t5, 0xE0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE0);
    // 0x8055288C: lui         $t4, 0xF550
    ctx->r12 = S32(0XF550 << 16);
    // 0x80552890: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x80552894: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x80552898: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x8055289C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x805528A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805528A4: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x805528A8: sw          $t2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r10;
    // 0x805528AC: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x805528B0: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x805528B4: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x805528B8: lui         $t2, 0xF300
    ctx->r10 = S32(0XF300 << 16);
    // 0x805528BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805528C0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x805528C4: sw          $t9, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r25;
    // 0x805528C8: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x805528CC: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x805528D0: lw          $t5, 0x100($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X100);
    // 0x805528D4: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x805528D8: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
    // 0x805528DC: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x805528E0: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    // 0x805528E4: jal         0x8004921C
    // 0x805528E8: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
    func_8004921C(rdram, ctx);
        goto after_16;
    // 0x805528E8: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
    after_16:
    // 0x805528EC: sh          $v0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r2;
    // 0x805528F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805528F4: jal         0x8004921C
    // 0x805528F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_17;
    // 0x805528F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x805528FC: lh          $t4, 0x46($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X46);
    // 0x80552900: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x80552904: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80552908: mflo        $t6
    ctx->r14 = lo;
    // 0x8055290C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80552910: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80552914: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x80552918: slti        $at, $t3, 0x7FF
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF ? 1 : 0;
    // 0x8055291C: beq         $at, $zero, L_80552964
    if (ctx->r1 == 0) {
        // 0x80552920: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80552964;
    }
    // 0x80552920: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552924: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552928: jal         0x8004921C
    // 0x8055292C: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_18;
    // 0x8055292C: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    after_18:
    // 0x80552930: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x80552934: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552938: jal         0x8004921C
    // 0x8055293C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_19;
    // 0x8055293C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80552940: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x80552944: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x80552948: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8055294C: mflo        $t7
    ctx->r15 = lo;
    // 0x80552950: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x80552954: sra         $t4, $t2, 1
    ctx->r12 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80552958: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x8055295C: b           L_8055296C
    // 0x80552960: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
        goto L_8055296C;
    // 0x80552960: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
L_80552964:
    // 0x80552964: addiu       $t8, $zero, 0x7FF
    ctx->r24 = ADD32(0, 0X7FF);
    // 0x80552968: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
L_8055296C:
    // 0x8055296C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552970: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552974: jal         0x8004921C
    // 0x80552978: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_20;
    // 0x80552978: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    after_20:
    // 0x8055297C: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x80552980: bgez        $v0, L_80552990
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80552984: sra         $t9, $v0, 3
        ctx->r25 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80552990;
    }
    // 0x80552984: sra         $t9, $v0, 3
    ctx->r25 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80552988: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x8055298C: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_80552990:
    // 0x80552990: bgtzl       $t9, L_805529A4
    if (SIGNED(ctx->r25) > 0) {
        // 0x80552994: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_805529A4;
    }
    goto skip_2;
    // 0x80552994: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
    // 0x80552998: b           L_805529C4
    // 0x8055299C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_805529C4;
    // 0x8055299C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805529A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_805529A4:
    // 0x805529A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805529A8: jal         0x8004921C
    // 0x805529AC: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_21;
    // 0x805529AC: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    after_21:
    // 0x805529B0: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x805529B4: bgez        $v0, L_805529C4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805529B8: sra         $t0, $v0, 3
        ctx->r8 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805529C4;
    }
    // 0x805529B8: sra         $t0, $v0, 3
    ctx->r8 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805529BC: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805529C0: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_805529C4:
    // 0x805529C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805529C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805529CC: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    // 0x805529D0: jal         0x8004921C
    // 0x805529D4: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_8004921C(rdram, ctx);
        goto after_22;
    // 0x805529D4: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_22:
    // 0x805529D8: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x805529DC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x805529E0: bgez        $v0, L_805529F0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805529E4: sra         $t3, $v0, 3
        ctx->r11 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805529F0;
    }
    // 0x805529E4: sra         $t3, $v0, 3
    ctx->r11 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805529E8: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805529EC: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_805529F0:
    // 0x805529F0: bgtzl       $t3, L_80552A04
    if (SIGNED(ctx->r11) > 0) {
        // 0x805529F4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80552A04;
    }
    goto skip_3;
    // 0x805529F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_3:
    // 0x805529F8: b           L_80552A2C
    // 0x805529FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80552A2C;
    // 0x805529FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80552A00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80552A04:
    // 0x80552A04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552A08: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    // 0x80552A0C: jal         0x8004921C
    // 0x80552A10: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_8004921C(rdram, ctx);
        goto after_23;
    // 0x80552A10: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_23:
    // 0x80552A14: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x80552A18: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80552A1C: bgez        $v0, L_80552A2C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80552A20: sra         $v1, $v0, 3
        ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80552A2C;
    }
    // 0x80552A20: sra         $v1, $v0, 3
    ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80552A24: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80552A28: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_80552A2C:
    // 0x80552A2C: addiu       $t5, $t0, 0x7FF
    ctx->r13 = ADD32(ctx->r8, 0X7FF);
    // 0x80552A30: div         $zero, $t5, $v1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r3)));
    // 0x80552A34: bne         $v1, $zero, L_80552A40
    if (ctx->r3 != 0) {
        // 0x80552A38: nop
    
            goto L_80552A40;
    }
    // 0x80552A38: nop

    // 0x80552A3C: break       7
    do_break(2153065020);
L_80552A40:
    // 0x80552A40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80552A44: bne         $v1, $at, L_80552A58
    if (ctx->r3 != ctx->r1) {
        // 0x80552A48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80552A58;
    }
    // 0x80552A48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80552A4C: bne         $t5, $at, L_80552A58
    if (ctx->r13 != ctx->r1) {
        // 0x80552A50: nop
    
            goto L_80552A58;
    }
    // 0x80552A50: nop

    // 0x80552A54: break       6
    do_break(2153065044);
L_80552A58:
    // 0x80552A58: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80552A5C: mflo        $t7
    ctx->r15 = lo;
    // 0x80552A60: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x80552A64: andi        $t2, $t7, 0xFFF
    ctx->r10 = ctx->r15 & 0XFFF;
    // 0x80552A68: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80552A6C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80552A70: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80552A74: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x80552A78: or          $t3, $t4, $t9
    ctx->r11 = ctx->r12 | ctx->r25;
    // 0x80552A7C: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x80552A80: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x80552A84: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80552A88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552A8C: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x80552A90: sw          $t2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r10;
    // 0x80552A94: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80552A98: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80552A9C: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x80552AA0: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    // 0x80552AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552AA8: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x80552AAC: sw          $t4, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r12;
    // 0x80552AB0: jal         0x8004921C
    // 0x80552AB4: sw          $t8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r24;
    func_8004921C(rdram, ctx);
        goto after_24;
    // 0x80552AB4: sw          $t8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r24;
    after_24:
    // 0x80552AB8: addiu       $t9, $v0, 0x7
    ctx->r25 = ADD32(ctx->r2, 0X7);
    // 0x80552ABC: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x80552AC0: sra         $t3, $t9, 3
    ctx->r11 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80552AC4: andi        $t5, $t3, 0x1FF
    ctx->r13 = ctx->r11 & 0X1FF;
    // 0x80552AC8: sll         $t7, $t5, 9
    ctx->r15 = S32(ctx->r13 << 9);
    // 0x80552ACC: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80552AD0: or          $t2, $t7, $at
    ctx->r10 = ctx->r15 | ctx->r1;
    // 0x80552AD4: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80552AD8: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80552ADC: lw          $t6, 0x100($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X100);
    // 0x80552AE0: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x80552AE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552AE8: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x80552AEC: sw          $t8, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r24;
    // 0x80552AF0: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x80552AF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552AF8: jal         0x8004921C
    // 0x80552AFC: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    func_8004921C(rdram, ctx);
        goto after_25;
    // 0x80552AFC: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    after_25:
    // 0x80552B00: sh          $v0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r2;
    // 0x80552B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552B08: jal         0x8004921C
    // 0x80552B0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_26;
    // 0x80552B0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80552B10: lh          $t7, 0x46($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X46);
    // 0x80552B14: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80552B18: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x80552B1C: addiu       $t2, $t7, -0x1
    ctx->r10 = ADD32(ctx->r15, -0X1);
    // 0x80552B20: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x80552B24: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80552B28: andi        $t5, $t3, 0xFFF
    ctx->r13 = ctx->r11 & 0XFFF;
    // 0x80552B2C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80552B30: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x80552B34: sll         $t4, $t8, 12
    ctx->r12 = S32(ctx->r24 << 12);
    // 0x80552B38: or          $t9, $t5, $t4
    ctx->r25 = ctx->r13 | ctx->r12;
    // 0x80552B3C: slti        $at, $a3, 0x20
    ctx->r1 = SIGNED(ctx->r7) < 0X20 ? 1 : 0;
    // 0x80552B40: beq         $at, $zero, L_80552BC8
    if (ctx->r1 == 0) {
        // 0x80552B44: sw          $t9, 0x4($t3)
        MEM_W(0X4, ctx->r11) = ctx->r25;
            goto L_80552BC8;
    }
    // 0x80552B44: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x80552B48: sll         $v1, $a3, 1
    ctx->r3 = S32(ctx->r7 << 1);
    // 0x80552B4C: addiu       $a0, $v1, 0x2
    ctx->r4 = ADD32(ctx->r3, 0X2);
    // 0x80552B50: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x80552B54: addiu       $v0, $v1, 0x6
    ctx->r2 = ADD32(ctx->r3, 0X6);
L_80552B58:
    // 0x80552B58: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x80552B5C: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x80552B60: andi        $t6, $v1, 0xFF
    ctx->r14 = ctx->r3 & 0XFF;
    // 0x80552B64: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80552B68: sll         $t5, $a2, 8
    ctx->r13 = S32(ctx->r6 << 8);
    // 0x80552B6C: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x80552B70: sw          $t2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r10;
    // 0x80552B74: or          $t4, $t8, $t5
    ctx->r12 = ctx->r24 | ctx->r13;
    // 0x80552B78: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    // 0x80552B7C: or          $t9, $t4, $a3
    ctx->r25 = ctx->r12 | ctx->r7;
    // 0x80552B80: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80552B84: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x80552B88: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x80552B8C: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x80552B90: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x80552B94: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x80552B98: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80552B9C: or          $t5, $t2, $t8
    ctx->r13 = ctx->r10 | ctx->r24;
    // 0x80552BA0: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x80552BA4: slti        $at, $v0, 0x46
    ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
    // 0x80552BA8: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
    // 0x80552BAC: or          $t4, $t5, $a3
    ctx->r12 = ctx->r13 | ctx->r7;
    // 0x80552BB0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80552BB4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80552BB8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80552BBC: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x80552BC0: bne         $at, $zero, L_80552B58
    if (ctx->r1 != 0) {
        // 0x80552BC4: sw          $s0, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r16;
            goto L_80552B58;
    }
    // 0x80552BC4: sw          $s0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r16;
L_80552BC8:
    // 0x80552BC8: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x80552BCC: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80552BD0: ori         $t7, $t7, 0x81FF
    ctx->r15 = ctx->r15 | 0X81FF;
    // 0x80552BD4: addiu       $t3, $t9, 0x8
    ctx->r11 = ADD32(ctx->r25, 0X8);
    // 0x80552BD8: sw          $t3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r11;
    // 0x80552BDC: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x80552BE0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80552BE4: lui         $t4, 0xFD50
    ctx->r12 = S32(0XFD50 << 16);
    // 0x80552BE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552BEC: addiu       $t2, $t6, 0x200
    ctx->r10 = ADD32(ctx->r14, 0X200);
    // 0x80552BF0: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x80552BF4: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x80552BF8: lui         $t2, 0x700
    ctx->r10 = S32(0X700 << 16);
    // 0x80552BFC: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x80552C00: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x80552C04: sw          $t5, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r13;
    // 0x80552C08: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80552C0C: lw          $t9, 0xEC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XEC);
    // 0x80552C10: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x80552C14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552C18: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x80552C1C: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x80552C20: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x80552C24: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
    // 0x80552C28: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x80552C2C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80552C30: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x80552C34: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x80552C38: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x80552C3C: sw          $t5, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r13;
    // 0x80552C40: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80552C44: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80552C48: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x80552C4C: addiu       $t3, $t9, 0x8
    ctx->r11 = ADD32(ctx->r25, 0X8);
    // 0x80552C50: sw          $t3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r11;
    // 0x80552C54: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x80552C58: jal         0x8004921C
    // 0x80552C5C: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    func_8004921C(rdram, ctx);
        goto after_27;
    // 0x80552C5C: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    after_27:
    // 0x80552C60: sh          $v0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r2;
    // 0x80552C64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552C68: jal         0x8004921C
    // 0x80552C6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_28;
    // 0x80552C6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x80552C70: lh          $t6, 0x46($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X46);
    // 0x80552C74: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80552C78: mflo        $t2
    ctx->r10 = lo;
    // 0x80552C7C: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x80552C80: sra         $t5, $t8, 1
    ctx->r13 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80552C84: addiu       $t4, $t5, -0x1
    ctx->r12 = ADD32(ctx->r13, -0X1);
    // 0x80552C88: slti        $at, $t4, 0x7FF
    ctx->r1 = SIGNED(ctx->r12) < 0X7FF ? 1 : 0;
    // 0x80552C8C: beq         $at, $zero, L_80552CCC
    if (ctx->r1 == 0) {
        // 0x80552C90: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80552CCC;
    }
    // 0x80552C90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552C94: jal         0x8004921C
    // 0x80552C98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_29;
    // 0x80552C98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x80552C9C: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x80552CA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552CA4: jal         0x8004921C
    // 0x80552CA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_30;
    // 0x80552CA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80552CAC: lh          $t9, 0x36($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X36);
    // 0x80552CB0: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80552CB4: mflo        $t3
    ctx->r11 = lo;
    // 0x80552CB8: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x80552CBC: sra         $t6, $t7, 1
    ctx->r14 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80552CC0: addiu       $t2, $t6, -0x1
    ctx->r10 = ADD32(ctx->r14, -0X1);
    // 0x80552CC4: b           L_80552CD4
    // 0x80552CC8: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
        goto L_80552CD4;
    // 0x80552CC8: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
L_80552CCC:
    // 0x80552CCC: addiu       $t8, $zero, 0x7FF
    ctx->r24 = ADD32(0, 0X7FF);
    // 0x80552CD0: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
L_80552CD4:
    // 0x80552CD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552CD8: jal         0x8004921C
    // 0x80552CDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_31;
    // 0x80552CDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x80552CE0: bgez        $v0, L_80552CF0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80552CE4: sra         $t5, $v0, 3
        ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80552CF0;
    }
    // 0x80552CE4: sra         $t5, $v0, 3
    ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80552CE8: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80552CEC: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_80552CF0:
    // 0x80552CF0: bgtzl       $t5, L_80552D04
    if (SIGNED(ctx->r13) > 0) {
        // 0x80552CF4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80552D04;
    }
    goto skip_4;
    // 0x80552CF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_4:
    // 0x80552CF8: b           L_80552D1C
    // 0x80552CFC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80552D1C;
    // 0x80552CFC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80552D00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80552D04:
    // 0x80552D04: jal         0x8004921C
    // 0x80552D08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_32;
    // 0x80552D08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x80552D0C: bgez        $v0, L_80552D1C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80552D10: sra         $t0, $v0, 3
        ctx->r8 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80552D1C;
    }
    // 0x80552D10: sra         $t0, $v0, 3
    ctx->r8 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80552D14: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80552D18: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_80552D1C:
    // 0x80552D1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552D20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552D24: jal         0x8004921C
    // 0x80552D28: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_8004921C(rdram, ctx);
        goto after_33;
    // 0x80552D28: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_33:
    // 0x80552D2C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80552D30: bgez        $v0, L_80552D40
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80552D34: sra         $t4, $v0, 3
        ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80552D40;
    }
    // 0x80552D34: sra         $t4, $v0, 3
    ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80552D38: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80552D3C: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_80552D40:
    // 0x80552D40: bgtzl       $t4, L_80552D54
    if (SIGNED(ctx->r12) > 0) {
        // 0x80552D44: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80552D54;
    }
    goto skip_5;
    // 0x80552D44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_5:
    // 0x80552D48: b           L_80552D74
    // 0x80552D4C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80552D74;
    // 0x80552D4C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80552D50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80552D54:
    // 0x80552D54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552D58: jal         0x8004921C
    // 0x80552D5C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_8004921C(rdram, ctx);
        goto after_34;
    // 0x80552D5C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_34:
    // 0x80552D60: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80552D64: bgez        $v0, L_80552D74
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80552D68: sra         $v1, $v0, 3
        ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80552D74;
    }
    // 0x80552D68: sra         $v1, $v0, 3
    ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80552D6C: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80552D70: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_80552D74:
    // 0x80552D74: addiu       $t9, $t0, 0x7FF
    ctx->r25 = ADD32(ctx->r8, 0X7FF);
    // 0x80552D78: div         $zero, $t9, $v1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r3)));
    // 0x80552D7C: bne         $v1, $zero, L_80552D88
    if (ctx->r3 != 0) {
        // 0x80552D80: nop
    
            goto L_80552D88;
    }
    // 0x80552D80: nop

    // 0x80552D84: break       7
    do_break(2153065860);
L_80552D88:
    // 0x80552D88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80552D8C: bne         $v1, $at, L_80552DA0
    if (ctx->r3 != ctx->r1) {
        // 0x80552D90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80552DA0;
    }
    // 0x80552D90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80552D94: bne         $t9, $at, L_80552DA0
    if (ctx->r25 != ctx->r1) {
        // 0x80552D98: nop
    
            goto L_80552DA0;
    }
    // 0x80552D98: nop

    // 0x80552D9C: break       6
    do_break(2153065884);
L_80552DA0:
    // 0x80552DA0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80552DA4: mflo        $t3
    ctx->r11 = lo;
    // 0x80552DA8: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80552DAC: andi        $t7, $t3, 0xFFF
    ctx->r15 = ctx->r11 & 0XFFF;
    // 0x80552DB0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80552DB4: andi        $t8, $t2, 0xFFF
    ctx->r24 = ctx->r10 & 0XFFF;
    // 0x80552DB8: sll         $t5, $t8, 12
    ctx->r13 = S32(ctx->r24 << 12);
    // 0x80552DBC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x80552DC0: or          $t4, $t6, $t5
    ctx->r12 = ctx->r14 | ctx->r13;
    // 0x80552DC4: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x80552DC8: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x80552DCC: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x80552DD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552DD4: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x80552DD8: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
    // 0x80552DDC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80552DE0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80552DE4: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x80552DE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552DEC: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80552DF0: sw          $t6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r14;
    // 0x80552DF4: jal         0x8004921C
    // 0x80552DF8: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    func_8004921C(rdram, ctx);
        goto after_35;
    // 0x80552DF8: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    after_35:
    // 0x80552DFC: addiu       $t5, $v0, 0x7
    ctx->r13 = ADD32(ctx->r2, 0X7);
    // 0x80552E00: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80552E04: sra         $t4, $t5, 3
    ctx->r12 = S32(SIGNED(ctx->r13) >> 3);
    // 0x80552E08: andi        $t9, $t4, 0x1FF
    ctx->r25 = ctx->r12 & 0X1FF;
    // 0x80552E0C: sll         $t3, $t9, 9
    ctx->r11 = S32(ctx->r25 << 9);
    // 0x80552E10: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80552E14: or          $t7, $t3, $at
    ctx->r15 = ctx->r11 | ctx->r1;
    // 0x80552E18: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80552E1C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80552E20: lw          $t2, 0x100($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X100);
    // 0x80552E24: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80552E28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552E2C: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x80552E30: sw          $t8, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r24;
    // 0x80552E34: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80552E38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552E3C: jal         0x8004921C
    // 0x80552E40: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
    func_8004921C(rdram, ctx);
        goto after_36;
    // 0x80552E40: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
    after_36:
    // 0x80552E44: sh          $v0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r2;
    // 0x80552E48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552E4C: jal         0x8004921C
    // 0x80552E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_37;
    // 0x80552E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_37:
    // 0x80552E54: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x80552E58: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80552E5C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80552E60: addiu       $t7, $t3, -0x1
    ctx->r15 = ADD32(ctx->r11, -0X1);
    // 0x80552E64: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x80552E68: andi        $t9, $t4, 0xFFF
    ctx->r25 = ctx->r12 & 0XFFF;
    // 0x80552E6C: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80552E70: andi        $t8, $t2, 0xFFF
    ctx->r24 = ctx->r10 & 0XFFF;
    // 0x80552E74: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80552E78: or          $t5, $t9, $t6
    ctx->r13 = ctx->r25 | ctx->r14;
    // 0x80552E7C: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x80552E80: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x80552E84: addiu       $t2, $zero, 0x204
    ctx->r10 = ADD32(0, 0X204);
    // 0x80552E88: lui         $t6, 0x2
    ctx->r14 = S32(0X2 << 16);
    // 0x80552E8C: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x80552E90: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
    // 0x80552E94: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x80552E98: sw          $s0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r16;
    // 0x80552E9C: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x80552EA0: ori         $t6, $t6, 0x604
    ctx->r14 = ctx->r14 | 0X604;
    // 0x80552EA4: lui         $t3, 0x8
    ctx->r11 = S32(0X8 << 16);
    // 0x80552EA8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80552EAC: sw          $t9, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r25;
    // 0x80552EB0: sw          $s0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r16;
    // 0x80552EB4: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x80552EB8: lw          $t5, 0x100($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X100);
    // 0x80552EBC: ori         $t3, $t3, 0xA0C
    ctx->r11 = ctx->r11 | 0XA0C;
    // 0x80552EC0: lui         $t8, 0xA
    ctx->r24 = S32(0XA << 16);
    // 0x80552EC4: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x80552EC8: sw          $t4, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r12;
    // 0x80552ECC: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x80552ED0: sw          $s0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r16;
    // 0x80552ED4: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x80552ED8: ori         $t8, $t8, 0xE0C
    ctx->r24 = ctx->r24 | 0XE0C;
    // 0x80552EDC: lui         $t5, 0x10
    ctx->r13 = S32(0X10 << 16);
    // 0x80552EE0: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x80552EE4: sw          $t2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r10;
    // 0x80552EE8: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x80552EEC: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x80552EF0: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x80552EF4: ori         $t5, $t5, 0x1214
    ctx->r13 = ctx->r13 | 0X1214;
    // 0x80552EF8: lui         $t7, 0x12
    ctx->r15 = S32(0X12 << 16);
    // 0x80552EFC: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80552F00: sw          $t6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r14;
    // 0x80552F04: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x80552F08: sw          $s0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r16;
    // 0x80552F0C: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
    // 0x80552F10: ori         $t7, $t7, 0x1614
    ctx->r15 = ctx->r15 | 0X1614;
    // 0x80552F14: lui         $t9, 0x18
    ctx->r25 = S32(0X18 << 16);
    // 0x80552F18: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x80552F1C: sw          $t3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r11;
    // 0x80552F20: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80552F24: sw          $s0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r16;
    // 0x80552F28: lw          $t2, 0x100($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X100);
    // 0x80552F2C: ori         $t9, $t9, 0x1A1C
    ctx->r25 = ctx->r25 | 0X1A1C;
    // 0x80552F30: lui         $t4, 0x1A
    ctx->r12 = S32(0X1A << 16);
    // 0x80552F34: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x80552F38: sw          $t8, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r24;
    // 0x80552F3C: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80552F40: sw          $s0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r16;
    // 0x80552F44: lw          $t6, 0x100($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X100);
    // 0x80552F48: ori         $t4, $t4, 0x1E1C
    ctx->r12 = ctx->r12 | 0X1E1C;
    // 0x80552F4C: lui         $t2, 0xFD50
    ctx->r10 = S32(0XFD50 << 16);
    // 0x80552F50: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x80552F54: sw          $t5, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r13;
    // 0x80552F58: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x80552F5C: sw          $s0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r16;
    // 0x80552F60: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x80552F64: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x80552F68: lui         $t5, 0xF550
    ctx->r13 = S32(0XF550 << 16);
    // 0x80552F6C: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x80552F70: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
    // 0x80552F74: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80552F78: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80552F7C: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x80552F80: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80552F84: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x80552F88: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x80552F8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552F90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552F94: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80552F98: sw          $t6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r14;
    // 0x80552F9C: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x80552FA0: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x80552FA4: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x80552FA8: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80552FAC: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x80552FB0: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
    // 0x80552FB4: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80552FB8: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80552FBC: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x80552FC0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80552FC4: sw          $t9, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r25;
    // 0x80552FC8: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80552FCC: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    // 0x80552FD0: jal         0x8004921C
    // 0x80552FD4: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    func_8004921C(rdram, ctx);
        goto after_38;
    // 0x80552FD4: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    after_38:
    // 0x80552FD8: sh          $v0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r2;
    // 0x80552FDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552FE0: jal         0x8004921C
    // 0x80552FE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_39;
    // 0x80552FE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_39:
    // 0x80552FE8: lh          $t5, 0x46($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X46);
    // 0x80552FEC: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x80552FF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80552FF4: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80552FF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80552FFC: mflo        $t4
    ctx->r12 = lo;
    // 0x80553000: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80553004: sra         $t7, $t3, 1
    ctx->r15 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80553008: addiu       $t2, $t7, -0x1
    ctx->r10 = ADD32(ctx->r15, -0X1);
    // 0x8055300C: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x80553010: beq         $at, $zero, L_80553054
    if (ctx->r1 == 0) {
        // 0x80553014: addiu       $t3, $zero, 0x7FF
        ctx->r11 = ADD32(0, 0X7FF);
            goto L_80553054;
    }
    // 0x80553014: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
    // 0x80553018: jal         0x8004921C
    // 0x8055301C: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_40;
    // 0x8055301C: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    after_40:
    // 0x80553020: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x80553024: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80553028: jal         0x8004921C
    // 0x8055302C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_41;
    // 0x8055302C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_41:
    // 0x80553030: lh          $t8, 0x36($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X36);
    // 0x80553034: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x80553038: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8055303C: mflo        $t9
    ctx->r25 = lo;
    // 0x80553040: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80553044: sra         $t5, $t6, 1
    ctx->r13 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80553048: addiu       $t4, $t5, -0x1
    ctx->r12 = ADD32(ctx->r13, -0X1);
    // 0x8055304C: b           L_80553058
    // 0x80553050: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
        goto L_80553058;
    // 0x80553050: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
L_80553054:
    // 0x80553054: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
L_80553058:
    // 0x80553058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8055305C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80553060: jal         0x8004921C
    // 0x80553064: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_42;
    // 0x80553064: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    after_42:
    // 0x80553068: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x8055306C: bgez        $v0, L_8055307C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80553070: sra         $t7, $v0, 3
        ctx->r15 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8055307C;
    }
    // 0x80553070: sra         $t7, $v0, 3
    ctx->r15 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80553074: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80553078: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_8055307C:
    // 0x8055307C: bgtz        $t7, L_8055308C
    if (SIGNED(ctx->r15) > 0) {
        // 0x80553080: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8055308C;
    }
    // 0x80553080: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80553084: b           L_805530AC
    // 0x80553088: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_805530AC;
    // 0x80553088: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8055308C:
    // 0x8055308C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80553090: jal         0x8004921C
    // 0x80553094: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_43;
    // 0x80553094: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    after_43:
    // 0x80553098: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x8055309C: bgez        $v0, L_805530AC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805530A0: sra         $t0, $v0, 3
        ctx->r8 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805530AC;
    }
    // 0x805530A0: sra         $t0, $v0, 3
    ctx->r8 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805530A4: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805530A8: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_805530AC:
    // 0x805530AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805530B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805530B4: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    // 0x805530B8: jal         0x8004921C
    // 0x805530BC: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_8004921C(rdram, ctx);
        goto after_44;
    // 0x805530BC: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_44:
    // 0x805530C0: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x805530C4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x805530C8: bgez        $v0, L_805530D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805530CC: sra         $t2, $v0, 3
        ctx->r10 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805530D8;
    }
    // 0x805530CC: sra         $t2, $v0, 3
    ctx->r10 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805530D0: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805530D4: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_805530D8:
    // 0x805530D8: bgtzl       $t2, L_805530EC
    if (SIGNED(ctx->r10) > 0) {
        // 0x805530DC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_805530EC;
    }
    goto skip_6;
    // 0x805530DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_6:
    // 0x805530E0: b           L_80553114
    // 0x805530E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80553114;
    // 0x805530E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805530E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_805530EC:
    // 0x805530EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805530F0: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    // 0x805530F4: jal         0x8004921C
    // 0x805530F8: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_8004921C(rdram, ctx);
        goto after_45;
    // 0x805530F8: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_45:
    // 0x805530FC: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x80553100: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80553104: bgez        $v0, L_80553114
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80553108: sra         $v1, $v0, 3
        ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80553114;
    }
    // 0x80553108: sra         $v1, $v0, 3
    ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8055310C: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80553110: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_80553114:
    // 0x80553114: addiu       $t8, $t0, 0x7FF
    ctx->r24 = ADD32(ctx->r8, 0X7FF);
    // 0x80553118: div         $zero, $t8, $v1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r3)));
    // 0x8055311C: bne         $v1, $zero, L_80553128
    if (ctx->r3 != 0) {
        // 0x80553120: nop
    
            goto L_80553128;
    }
    // 0x80553120: nop

    // 0x80553124: break       7
    do_break(2153066788);
L_80553128:
    // 0x80553128: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8055312C: bne         $v1, $at, L_80553140
    if (ctx->r3 != ctx->r1) {
        // 0x80553130: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80553140;
    }
    // 0x80553130: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80553134: bne         $t8, $at, L_80553140
    if (ctx->r24 != ctx->r1) {
        // 0x80553138: nop
    
            goto L_80553140;
    }
    // 0x80553138: nop

    // 0x8055313C: break       6
    do_break(2153066812);
L_80553140:
    // 0x80553140: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80553144: mflo        $t9
    ctx->r25 = lo;
    // 0x80553148: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8055314C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80553150: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80553154: andi        $t3, $t4, 0xFFF
    ctx->r11 = ctx->r12 & 0XFFF;
    // 0x80553158: sll         $t7, $t3, 12
    ctx->r15 = S32(ctx->r11 << 12);
    // 0x8055315C: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x80553160: or          $t2, $t5, $t7
    ctx->r10 = ctx->r13 | ctx->r15;
    // 0x80553164: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x80553168: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x8055316C: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80553170: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80553174: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80553178: sw          $t6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r14;
    // 0x8055317C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80553180: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x80553184: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x80553188: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    // 0x8055318C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80553190: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x80553194: sw          $t5, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r13;
    // 0x80553198: jal         0x8004921C
    // 0x8055319C: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    func_8004921C(rdram, ctx);
        goto after_46;
    // 0x8055319C: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    after_46:
    // 0x805531A0: addiu       $t7, $v0, 0x7
    ctx->r15 = ADD32(ctx->r2, 0X7);
    // 0x805531A4: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x805531A8: sra         $t2, $t7, 3
    ctx->r10 = S32(SIGNED(ctx->r15) >> 3);
    // 0x805531AC: andi        $t8, $t2, 0x1FF
    ctx->r24 = ctx->r10 & 0X1FF;
    // 0x805531B0: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x805531B4: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x805531B8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x805531BC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x805531C0: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x805531C4: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
    // 0x805531C8: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x805531CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805531D0: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x805531D4: sw          $t3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r11;
    // 0x805531D8: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x805531DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805531E0: jal         0x8004921C
    // 0x805531E4: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    func_8004921C(rdram, ctx);
        goto after_47;
    // 0x805531E4: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    after_47:
    // 0x805531E8: sh          $v0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r2;
    // 0x805531EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805531F0: jal         0x8004921C
    // 0x805531F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_48;
    // 0x805531F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_48:
    // 0x805531F8: lh          $t9, 0x46($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X46);
    // 0x805531FC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80553200: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x80553204: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x80553208: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x8055320C: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x80553210: andi        $t8, $t2, 0xFFF
    ctx->r24 = ctx->r10 & 0XFFF;
    // 0x80553214: andi        $t3, $t4, 0xFFF
    ctx->r11 = ctx->r12 & 0XFFF;
    // 0x80553218: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8055321C: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x80553220: or          $t7, $t8, $t5
    ctx->r15 = ctx->r24 | ctx->r13;
    // 0x80553224: slti        $at, $a3, 0x20
    ctx->r1 = SIGNED(ctx->r7) < 0X20 ? 1 : 0;
    // 0x80553228: beq         $at, $zero, L_805532B0
    if (ctx->r1 == 0) {
        // 0x8055322C: sw          $t7, 0x4($t2)
        MEM_W(0X4, ctx->r10) = ctx->r15;
            goto L_805532B0;
    }
    // 0x8055322C: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80553230: sll         $v1, $a3, 1
    ctx->r3 = S32(ctx->r7 << 1);
    // 0x80553234: addiu       $a0, $v1, 0x2
    ctx->r4 = ADD32(ctx->r3, 0X2);
    // 0x80553238: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x8055323C: addiu       $v0, $v1, 0x6
    ctx->r2 = ADD32(ctx->r3, 0X6);
L_80553240:
    // 0x80553240: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x80553244: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x80553248: andi        $t4, $v1, 0xFF
    ctx->r12 = ctx->r3 & 0XFF;
    // 0x8055324C: sll         $t3, $t4, 16
    ctx->r11 = S32(ctx->r12 << 16);
    // 0x80553250: sll         $t8, $a2, 8
    ctx->r24 = S32(ctx->r6 << 8);
    // 0x80553254: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80553258: sw          $t6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r14;
    // 0x8055325C: or          $t5, $t3, $t8
    ctx->r13 = ctx->r11 | ctx->r24;
    // 0x80553260: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    // 0x80553264: or          $t7, $t5, $a3
    ctx->r15 = ctx->r13 | ctx->r7;
    // 0x80553268: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8055326C: sw          $s0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r16;
    // 0x80553270: lw          $t2, 0x100($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X100);
    // 0x80553274: andi        $t4, $v0, 0xFF
    ctx->r12 = ctx->r2 & 0XFF;
    // 0x80553278: sll         $t3, $t4, 8
    ctx->r11 = S32(ctx->r12 << 8);
    // 0x8055327C: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80553280: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80553284: or          $t8, $t6, $t3
    ctx->r24 = ctx->r14 | ctx->r11;
    // 0x80553288: addiu       $t9, $t2, 0x8
    ctx->r25 = ADD32(ctx->r10, 0X8);
    // 0x8055328C: slti        $at, $v0, 0x46
    ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
    // 0x80553290: sw          $t9, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r25;
    // 0x80553294: or          $t5, $t8, $a3
    ctx->r13 = ctx->r24 | ctx->r7;
    // 0x80553298: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8055329C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x805532A0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x805532A4: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x805532A8: bne         $at, $zero, L_80553240
    if (ctx->r1 != 0) {
        // 0x805532AC: sw          $s0, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r16;
            goto L_80553240;
    }
    // 0x805532AC: sw          $s0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r16;
L_805532B0:
    // 0x805532B0: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x805532B4: lw          $t2, 0x108($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X108);
    // 0x805532B8: sw          $t7, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r15;
    // 0x805532BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805532C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805532C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805532C8: jr          $ra
    // 0x805532CC: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x805532CC: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_805D17E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D17E4: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D17E8: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x805D17EC: jr          $ra
    // 0x805D17F0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    return;
    // 0x805D17F0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_8066D5C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066D5C0: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(517, 0XC48) << 16);
    // 0x8066D5C4: addiu       $v0, $v0, -0x1DF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(517, 0XC48));
    // 0x8066D5C8: jr          $ra
    // 0x8066D5CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8066D5CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80742A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742A34: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742A38: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742A3C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742A40: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742A44: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742A48: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742A4C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742A50: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742A54: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742A58: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742A5C: jr          $ra
    // 0x80742A60: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742A60: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804690B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804690B8: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(135, 0XE60) << 16);
    // 0x804690BC: lwc1        $f6, -0x6980($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(135, 0XE60));
    // 0x804690C0: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x804690C4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804690C8: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(135, 0XE64) << 16);
    // 0x804690CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804690D0: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804690D4: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x804690D8: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x804690DC: lwc1        $f4, -0x697C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(135, 0XE64));
    // 0x804690E0: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804690E4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x804690E8: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x804690EC: lwc1        $f10, 0x50($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X50);
    // 0x804690F0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804690F4: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x804690F8: jr          $ra
    // 0x804690FC: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x804690FC: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_8078FB4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078FB4C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8078FB50: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(814, 0X644) << 16);
    // 0x8078FB54: addiu       $t6, $t6, -0x82C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(814, 0X644));
    // 0x8078FB58: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8078FB5C: lui         $t9, 0x8079
    ctx->r25 = S32(RELOC_HI16(814, 0X6AC) << 16);
    // 0x8078FB60: addiu       $t9, $t9, -0x7C4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(814, 0X6AC));
    // 0x8078FB64: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    // 0x8078FB68: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x8078FB6C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8078FB70: jr          $ra
    // 0x8078FB74: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
    return;
    // 0x8078FB74: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
;}
RECOMP_FUNC void func_80564C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80564C9C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80564CA0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80564CA4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80564CA8: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80564CAC: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x80564CB0: nop

    // 0x80564CB4: bc1t        L_80564E0C
    if (c1cs) {
        // 0x80564CB8: nop
    
            goto L_80564E0C;
    }
    // 0x80564CB8: nop

    // 0x80564CBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80564CC0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80564CC4: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x80564CC8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80564CCC: nop

    // 0x80564CD0: bc1fl       L_80564CE0
    if (!c1cs) {
        // 0x80564CD4: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80564CE0;
    }
    goto skip_0;
    // 0x80564CD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80564CD8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80564CDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80564CE0:
    // 0x80564CE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80564CE4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80564CE8: nop

    // 0x80564CEC: bc1fl       L_80564CFC
    if (!c1cs) {
        // 0x80564CF0: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_80564CFC;
    }
    goto skip_1;
    // 0x80564CF0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_1:
    // 0x80564CF4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80564CF8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_80564CFC:
    // 0x80564CFC: nop

    // 0x80564D00: bc1fl       L_80564D20
    if (!c1cs) {
        // 0x80564D04: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_80564D20;
    }
    goto skip_2;
    // 0x80564D04: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_2:
    // 0x80564D08: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x80564D0C: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x80564D10: beql        $t7, $zero, L_80564D20
    if (ctx->r15 == 0) {
        // 0x80564D14: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_80564D20;
    }
    goto skip_3;
    // 0x80564D14: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_3:
    // 0x80564D18: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80564D1C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_80564D20:
    // 0x80564D20: nop

    // 0x80564D24: bc1fl       L_80564D44
    if (!c1cs) {
        // 0x80564D28: lwc1        $f4, 0x40($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
            goto L_80564D44;
    }
    goto skip_4;
    // 0x80564D28: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    skip_4:
    // 0x80564D2C: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x80564D30: andi        $t9, $t8, 0x3000
    ctx->r25 = ctx->r24 & 0X3000;
    // 0x80564D34: beql        $t9, $zero, L_80564D44
    if (ctx->r25 == 0) {
        // 0x80564D38: lwc1        $f4, 0x40($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
            goto L_80564D44;
    }
    goto skip_5;
    // 0x80564D38: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    skip_5:
    // 0x80564D3C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80564D40: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
L_80564D44:
    // 0x80564D44: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80564D48: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80564D4C: bc1f        L_80564D84
    if (!c1cs) {
        // 0x80564D50: swc1        $f6, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
            goto L_80564D84;
    }
    // 0x80564D50: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80564D54: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x80564D58: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80564D5C: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2584) << 16);
    // 0x80564D60: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80564D64: nop

    // 0x80564D68: bc1fl       L_80564DCC
    if (!c1cs) {
        // 0x80564D6C: c.le.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
            goto L_80564DCC;
    }
    goto skip_6;
    // 0x80564D6C: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    skip_6:
    // 0x80564D70: lwc1        $f8, 0x5DE4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2584));
    // 0x80564D74: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80564D78: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80564D7C: b           L_80564DC8
    // 0x80564D80: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
        goto L_80564DC8;
    // 0x80564D80: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
L_80564D84:
    // 0x80564D84: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80564D88: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80564D8C: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2588) << 16);
    // 0x80564D90: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80564D94: nop

    // 0x80564D98: bc1fl       L_80564DCC
    if (!c1cs) {
        // 0x80564D9C: c.le.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
            goto L_80564DCC;
    }
    goto skip_7;
    // 0x80564D9C: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    skip_7:
    // 0x80564DA0: lwc1        $f18, 0x5DE8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2588));
    // 0x80564DA4: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80564DA8: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80564DAC: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x80564DB0: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80564DB4: c.lt.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl < ctx->f14.fl;
    // 0x80564DB8: nop

    // 0x80564DBC: bc1fl       L_80564DCC
    if (!c1cs) {
        // 0x80564DC0: c.le.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
            goto L_80564DCC;
    }
    goto skip_8;
    // 0x80564DC0: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    skip_8:
    // 0x80564DC4: swc1        $f14, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f14.u32l;
L_80564DC8:
    // 0x80564DC8: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
L_80564DCC:
    // 0x80564DCC: nop

    // 0x80564DD0: bc1f        L_80564E0C
    if (!c1cs) {
        // 0x80564DD4: nop
    
            goto L_80564E0C;
    }
    // 0x80564DD4: nop

    // 0x80564DD8: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80564DDC: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80564DE0: nop

    // 0x80564DE4: bc1f        L_80564E0C
    if (!c1cs) {
        // 0x80564DE8: nop
    
            goto L_80564E0C;
    }
    // 0x80564DE8: nop

    // 0x80564DEC: lw          $t0, 0x34($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X34);
    // 0x80564DF0: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X258C) << 16);
    // 0x80564DF4: ori         $t1, $t0, 0x700
    ctx->r9 = ctx->r8 | 0X700;
    // 0x80564DF8: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
    // 0x80564DFC: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80564E00: lwc1        $f18, 0x5DEC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X258C));
    // 0x80564E04: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80564E08: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_80564E0C:
    // 0x80564E0C: jr          $ra
    // 0x80564E10: nop

    return;
    // 0x80564E10: nop

;}
RECOMP_FUNC void func_8005A874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A87C: jal         0x8005A824
    // 0x8005A880: nop

    func_8005A824(rdram, ctx);
        goto after_0;
    // 0x8005A880: nop

    after_0:
    // 0x8005A884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A88C: jr          $ra
    // 0x8005A890: nop

    return;
    // 0x8005A890: nop

;}
RECOMP_FUNC void func_8003F37C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F37C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003F380: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003F384: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8003F388: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003F38C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003F390: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8003F394: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003F398: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8003F39C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8003F3A0: lw          $a3, 0x1EC($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1EC);
    // 0x8003F3A4: jal         0x8003BB20
    // 0x8003F3A8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_8003BB20(rdram, ctx);
        goto after_0;
    // 0x8003F3A8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_0:
    // 0x8003F3AC: bne         $v0, $zero, L_8003F3BC
    if (ctx->r2 != 0) {
        // 0x8003F3B0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8003F3BC;
    }
    // 0x8003F3B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003F3B4: b           L_8003F44C
    // 0x8003F3B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003F44C;
    // 0x8003F3B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003F3BC:
    // 0x8003F3BC: jal         0x800447C8
    // 0x8003F3C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8003F3C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8003F3C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003F3C8: jal         0x8003EBD4
    // 0x8003F3CC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8003EBD4(rdram, ctx);
        goto after_2;
    // 0x8003F3CC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8003F3D0: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8003F3D4: addiu       $t7, $t7, -0x4D50
    ctx->r15 = ADD32(ctx->r15, -0X4D50);
    // 0x8003F3D8: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    // 0x8003F3DC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8003F3E0: jal         0x80065490
    // 0x8003F3E4: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x8003F3E4: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    after_3:
    // 0x8003F3E8: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x8003F3EC: jal         0x80065490
    // 0x8003F3F0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80065490(rdram, ctx);
        goto after_4;
    // 0x8003F3F0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x8003F3F4: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8003F3F8: jal         0x80065490
    // 0x8003F3FC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80065490(rdram, ctx);
        goto after_5;
    // 0x8003F3FC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_5:
    // 0x8003F400: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8003F404: jal         0x80047F9C
    // 0x8003F408: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x8003F408: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8003F40C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003F410: sb          $t8, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r24;
    // 0x8003F414: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8003F418: addiu       $t9, $t9, -0x1A14
    ctx->r25 = ADD32(ctx->r25, -0X1A14);
    // 0x8003F41C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003F420: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    // 0x8003F424: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003F428: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8003F42C: jal         0x8003E6C4
    // 0x8003F430: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8003E6C4(rdram, ctx);
        goto after_7;
    // 0x8003F430: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8003F434: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8003F438: addiu       $a2, $a2, -0x5A14
    ctx->r6 = ADD32(ctx->r6, -0X5A14);
    // 0x8003F43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F440: jal         0x8003F14C
    // 0x8003F444: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8003F14C(rdram, ctx);
        goto after_8;
    // 0x8003F444: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x8003F448: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003F44C:
    // 0x8003F44C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003F450: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003F454: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003F458: jr          $ra
    // 0x8003F45C: nop

    return;
    // 0x8003F45C: nop

;}
RECOMP_FUNC void func_80047E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047E70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80047E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80047E78: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x80047E7C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80047E80: sh          $t6, 0x17E($a0)
    MEM_H(0X17E, ctx->r4) = ctx->r14;
    // 0x80047E84: sb          $t7, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r15;
    // 0x80047E88: sw          $zero, 0x180($a0)
    MEM_W(0X180, ctx->r4) = 0;
    // 0x80047E8C: sh          $zero, 0x184($a0)
    MEM_H(0X184, ctx->r4) = 0;
    // 0x80047E90: addiu       $a0, $a0, 0x188
    ctx->r4 = ADD32(ctx->r4, 0X188);
    // 0x80047E94: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80047E98: jal         0x80065728
    // 0x80047E9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80047E9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80047EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80047EA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80047EA8: jr          $ra
    // 0x80047EAC: nop

    return;
    // 0x80047EAC: nop

;}
RECOMP_FUNC void func_80664CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80664CD0: lui         $v0, 0x8066
    ctx->r2 = S32(RELOC_HI16(504, 0X10) << 16);
    // 0x80664CD4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80664CD8: jr          $ra
    // 0x80664CDC: addiu       $v0, $v0, 0x4CE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(504, 0X10));
    return;
    // 0x80664CDC: addiu       $v0, $v0, 0x4CE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(504, 0X10));
;}
RECOMP_FUNC void func_8069C908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069C908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069C90C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069C910: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8069C914: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8069C918: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8069C91C: lhu         $t8, 0xC($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XC);
    // 0x8069C920: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8069C924: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069C928: bne         $t8, $at, L_8069C96C
    if (ctx->r24 != ctx->r1) {
        // 0x8069C92C: or          $t6, $a0, $zero
        ctx->r14 = ctx->r4 | 0;
            goto L_8069C96C;
    }
    // 0x8069C92C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8069C930: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8069C934: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x8069C938: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8069C93C: bne         $t9, $zero, L_8069C96C
    if (ctx->r25 != 0) {
        // 0x8069C940: addiu       $t1, $zero, 0xA
        ctx->r9 = ADD32(0, 0XA);
            goto L_8069C96C;
    }
    // 0x8069C940: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8069C944: sb          $t0, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r8;
    // 0x8069C948: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8069C94C: sb          $t1, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r9;
    // 0x8069C950: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8069C954: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x8069C958: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8069C95C: sb          $t2, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r10;
    // 0x8069C960: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8069C964: jal         0x8002F6E4
    // 0x8069C968: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x8069C968: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
L_8069C96C:
    // 0x8069C96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069C970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069C974: jr          $ra
    // 0x8069C978: nop

    return;
    // 0x8069C978: nop

;}
RECOMP_FUNC void func_80077E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077E88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077E8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077E90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80077E94: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x80077E98: jal         0x80084820
    // 0x80077E9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _blkclr(rdram, ctx);
        goto after_0;
    // 0x80077E9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80077EA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80077EA4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80077EA8: jal         0x80084820
    // 0x80077EAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _blkclr(rdram, ctx);
        goto after_1;
    // 0x80077EAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80077EB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80077EB4: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80077EB8: addiu       $t7, $t7, 0x7930
    ctx->r15 = ADD32(ctx->r15, 0X7930);
    // 0x80077EBC: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80077EC0: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80077EC4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80077EC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80077ECC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80077ED0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80077ED4: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80077ED8: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x80077EDC: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80077EE0: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80077EE4: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x80077EE8: swc1        $f2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f2.u32l;
    // 0x80077EEC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80077EF0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80077EF4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80077EF8: sb          $zero, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = 0;
    // 0x80077EFC: sb          $v0, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r2;
    // 0x80077F00: sb          $v0, 0x31($a0)
    MEM_B(0X31, ctx->r4) = ctx->r2;
    // 0x80077F04: sb          $v0, 0x32($a0)
    MEM_B(0X32, ctx->r4) = ctx->r2;
    // 0x80077F08: sb          $v0, 0x33($a0)
    MEM_B(0X33, ctx->r4) = ctx->r2;
    // 0x80077F0C: sb          $v1, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r3;
    // 0x80077F10: sb          $v1, 0x35($a0)
    MEM_B(0X35, ctx->r4) = ctx->r3;
    // 0x80077F14: sb          $v1, 0x36($a0)
    MEM_B(0X36, ctx->r4) = ctx->r3;
    // 0x80077F18: sb          $v1, 0x37($a0)
    MEM_B(0X37, ctx->r4) = ctx->r3;
    // 0x80077F1C: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x80077F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077F28: jr          $ra
    // 0x80077F2C: nop

    return;
    // 0x80077F2C: nop

;}
RECOMP_FUNC void func_806CD3FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CD3FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CD400: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CD404: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CD408: jal         0x806CCF00
    // 0x806CD40C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806CCF00(rdram, ctx);
        goto after_0;
    // 0x806CD40C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806CD410: jal         0x806CD384
    // 0x806CD414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CD384(rdram, ctx);
        goto after_1;
    // 0x806CD414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CD418: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x806CD41C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806CD420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD424: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806CD428: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x806CD42C: bne         $t7, $at, L_806CD43C
    if (ctx->r15 != ctx->r1) {
        // 0x806CD430: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_806CD43C;
    }
    // 0x806CD430: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x806CD434: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806CD438: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_806CD43C:
    // 0x806CD43C: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x806CD440: bne         $at, $zero, L_806CD45C
    if (ctx->r1 != 0) {
        // 0x806CD444: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_806CD45C;
    }
    // 0x806CD444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CD448: jal         0x806CED40
    // 0x806CD44C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_806CED40(rdram, ctx);
        goto after_2;
    // 0x806CD44C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x806CD450: jal         0x806CCCE4
    // 0x806CD454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCCE4(rdram, ctx);
        goto after_3;
    // 0x806CD454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806CD458: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_806CD45C:
    // 0x806CD45C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806CD460: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CD464: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CD468: jr          $ra
    // 0x806CD46C: nop

    return;
    // 0x806CD46C: nop

;}
RECOMP_FUNC void func_8052675C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052675C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80526760: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x80526764: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80526768: lh          $t6, 0x80($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X80);
    // 0x8052676C: lh          $t7, 0x82($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X82);
    // 0x80526770: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80526774: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80526778: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x8052677C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80526780: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80526784: lw          $t0, 0x84($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X84);
    // 0x80526788: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8052678C: mul.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80526790: swc1        $f0, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f0.u32l;
    // 0x80526794: mul.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80526798: lw          $t1, 0x84($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X84);
    // 0x8052679C: jr          $ra
    // 0x805267A0: swc1        $f2, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f2.u32l;
    return;
    // 0x805267A0: swc1        $f2, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_8045AA10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045AA10: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8045AA14: addiu       $at, $zero, 0x4112
    ctx->r1 = ADD32(0, 0X4112);
    // 0x8045AA18: beq         $v0, $at, L_8045AA30
    if (ctx->r2 == ctx->r1) {
        // 0x8045AA1C: addiu       $at, $zero, 0x4113
        ctx->r1 = ADD32(0, 0X4113);
            goto L_8045AA30;
    }
    // 0x8045AA1C: addiu       $at, $zero, 0x4113
    ctx->r1 = ADD32(0, 0X4113);
    // 0x8045AA20: beq         $v0, $at, L_8045AA3C
    if (ctx->r2 == ctx->r1) {
        // 0x8045AA24: nop
    
            goto L_8045AA3C;
    }
    // 0x8045AA24: nop

    // 0x8045AA28: jr          $ra
    // 0x8045AA2C: nop

    return;
    // 0x8045AA2C: nop

L_8045AA30:
    // 0x8045AA30: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(104, 0XA34) << 16);
    // 0x8045AA34: jr          $ra
    // 0x8045AA38: addiu       $v0, $v0, -0x4BBC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(104, 0XA34));
    return;
    // 0x8045AA38: addiu       $v0, $v0, -0x4BBC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(104, 0XA34));
L_8045AA3C:
    // 0x8045AA3C: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(104, 0XB08) << 16);
    // 0x8045AA40: addiu       $v0, $v0, -0x4AE8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(104, 0XB08));
    // 0x8045AA44: jr          $ra
    // 0x8045AA48: nop

    return;
    // 0x8045AA48: nop

;}
RECOMP_FUNC void func_80735F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735F6C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80735F70: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(736, 0X3988) << 16);
    // 0x80735F74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80735F78: addiu       $t7, $t7, -0x6C18
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(736, 0X3988));
    // 0x80735F7C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80735F80: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x80735F84: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80735F88: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80735F8C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80735F90: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80735F94: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80735F98: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80735F9C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80735FA0: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80735FA4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80735FA8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80735FAC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80735FB0: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80735FB4: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B0C) << 16);
    // 0x80735FB8: lwc1        $f10, -0x6A94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B0C));
    // 0x80735FBC: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80735FC0: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80735FC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80735FC8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B10) << 16);
    // 0x80735FCC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80735FD0: lwc1        $f10, -0x6A90($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B10));
    // 0x80735FD4: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x80735FD8: lw          $t1, -0x76F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76F8);
    // 0x80735FDC: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80735FE0: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80735FE4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80735FE8: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80735FEC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80735FF0: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80735FF4: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x80735FF8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80735FFC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80736000: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80736004: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80736008: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x8073600C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80736010: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80736014: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x80736018: lw          $t9, 0x10($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X10);
    // 0x8073601C: jalr        $t9
    // 0x80736020: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80736020: nop

    after_0:
    // 0x80736024: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x80736028: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x8073602C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80736030: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80736034: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x80736038: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8073603C: addiu       $a0, $a3, 0x84
    ctx->r4 = ADD32(ctx->r7, 0X84);
    // 0x80736040: lw          $t9, 0x18($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X18);
    // 0x80736044: jalr        $t9
    // 0x80736048: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80736048: nop

    after_1:
    // 0x8073604C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80736050: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80736054: jr          $ra
    // 0x80736058: nop

    return;
    // 0x80736058: nop

;}
RECOMP_FUNC void func_80426AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80426AE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80426AE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80426AE8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80426AEC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80426AF0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80426AF4: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(38, 0X11B8) << 16);
    // 0x80426AF8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80426AFC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80426B00: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80426B04: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80426B08: lw          $t8, 0x77B8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(38, 0X11B8));
    // 0x80426B0C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80426B10: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80426B14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80426B18: jal         0x80048490
    // 0x80426B1C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80426B1C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80426B20: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80426B24: jal         0x80048378
    // 0x80426B28: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80426B28: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80426B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80426B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80426B34: jr          $ra
    // 0x80426B38: nop

    return;
    // 0x80426B38: nop

;}
RECOMP_FUNC void func_8040E7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040E7C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040E7CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040E7D0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8040E7D4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8040E7D8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8040E7DC: lui         $t8, 0x8041
    ctx->r24 = S32(RELOC_HI16(23, 0XC50) << 16);
    // 0x8040E7E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8040E7E4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8040E7E8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8040E7EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8040E7F0: lw          $t8, -0xC10($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(23, 0XC50));
    // 0x8040E7F4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8040E7F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8040E7FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8040E800: jal         0x80048490
    // 0x8040E804: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8040E804: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8040E808: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8040E80C: jal         0x80048378
    // 0x8040E810: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8040E810: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8040E814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040E818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040E81C: jr          $ra
    // 0x8040E820: nop

    return;
    // 0x8040E820: nop

;}
RECOMP_FUNC void func_8042CB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042CB90: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8042CB94: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8042CB98: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8042CB9C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042CBA0: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X3064) << 16);
    // 0x8042CBA4: lwc1        $f0, -0x26FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X3064));
    // 0x8042CBA8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8042CBAC: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8042CBB0: lwc1        $f8, 0xC8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8042CBB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042CBB8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8042CBBC: nop

    // 0x8042CBC0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8042CBC4: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x8042CBC8: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x8042CBCC: jal         0x8042A9DC
    // 0x8042CBD0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_8042A9DC(rdram, ctx);
        goto after_0;
    // 0x8042CBD0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x8042CBD4: jal         0x8042BB3C
    // 0x8042CBD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BB3C(rdram, ctx);
        goto after_1;
    // 0x8042CBD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8042CBDC: jal         0x8042BA84
    // 0x8042CBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BA84(rdram, ctx);
        goto after_2;
    // 0x8042CBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8042CBE4: jal         0x8042B810
    // 0x8042CBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042B810(rdram, ctx);
        goto after_3;
    // 0x8042CBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8042CBEC: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042CBF0: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x8042CBF4: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x8042CBF8: bne         $at, $zero, L_8042CC58
    if (ctx->r1 != 0) {
        // 0x8042CBFC: sw          $v0, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r2;
            goto L_8042CC58;
    }
    // 0x8042CBFC: sw          $v0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r2;
    // 0x8042CC00: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8042CC04: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8042CC08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042CC0C: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x8042CC10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8042CC14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042CC18: sb          $zero, 0x30($t8)
    MEM_B(0X30, ctx->r24) = 0;
    // 0x8042CC1C: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8042CC20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042CC24: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8042CC28: bne         $t9, $at, L_8042CC48
    if (ctx->r25 != ctx->r1) {
        // 0x8042CC2C: nop
    
            goto L_8042CC48;
    }
    // 0x8042CC2C: nop

    // 0x8042CC30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042CC34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042CC38: jal         0x8042D50C
    // 0x8042CC3C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8042D50C(rdram, ctx);
        goto after_4;
    // 0x8042CC3C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x8042CC40: b           L_8042CD58
    // 0x8042CC44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8042CD58;
    // 0x8042CC44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8042CC48:
    // 0x8042CC48: jal         0x8042D50C
    // 0x8042CC4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8042D50C(rdram, ctx);
        goto after_5;
    // 0x8042CC4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8042CC50: b           L_8042CD58
    // 0x8042CC54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8042CD58;
    // 0x8042CC54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8042CC58:
    // 0x8042CC58: slti        $at, $v0, 0x2D
    ctx->r1 = SIGNED(ctx->r2) < 0X2D ? 1 : 0;
    // 0x8042CC5C: bne         $at, $zero, L_8042CCE0
    if (ctx->r1 != 0) {
        // 0x8042CC60: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_8042CCE0;
    }
    // 0x8042CC60: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8042CC64: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x8042CC68: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8042CC6C: addiu       $t4, $zero, 0x208
    ctx->r12 = ADD32(0, 0X208);
    // 0x8042CC70: subu        $t0, $t4, $t3
    ctx->r8 = SUB32(ctx->r12, ctx->r11);
    // 0x8042CC74: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x8042CC78: bne         $at, $zero, L_8042CC84
    if (ctx->r1 != 0) {
        // 0x8042CC7C: addiu       $t5, $zero, 0x3C
        ctx->r13 = ADD32(0, 0X3C);
            goto L_8042CC84;
    }
    // 0x8042CC7C: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x8042CC80: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_8042CC84:
    // 0x8042CC84: subu        $v1, $t5, $v0
    ctx->r3 = SUB32(ctx->r13, ctx->r2);
    // 0x8042CC88: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8042CC8C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8042CC90: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8042CC94: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8042CC98: subu        $t1, $t1, $v1
    ctx->r9 = SUB32(ctx->r9, ctx->r3);
    // 0x8042CC9C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8042CCA0: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x8042CCA4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8042CCA8: addiu       $t1, $t1, 0xA0
    ctx->r9 = ADD32(ctx->r9, 0XA0);
    // 0x8042CCAC: subu        $t2, $t7, $t6
    ctx->r10 = SUB32(ctx->r15, ctx->r14);
    // 0x8042CCB0: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x8042CCB4: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x8042CCB8: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x8042CCBC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8042CCC0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8042CCC4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8042CCC8: andi        $a3, $t2, 0xFF
    ctx->r7 = ctx->r10 & 0XFF;
    // 0x8042CCCC: andi        $a2, $t1, 0xFF
    ctx->r6 = ctx->r9 & 0XFF;
    // 0x8042CCD0: jal         0x8042B8A0
    // 0x8042CCD4: andi        $a1, $t0, 0xFF
    ctx->r5 = ctx->r8 & 0XFF;
    func_8042B8A0(rdram, ctx);
        goto after_6;
    // 0x8042CCD4: andi        $a1, $t0, 0xFF
    ctx->r5 = ctx->r8 & 0XFF;
    after_6:
    // 0x8042CCD8: b           L_8042CD58
    // 0x8042CCDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8042CD58;
    // 0x8042CCDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8042CCE0:
    // 0x8042CCE0: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8042CCE4: beq         $at, $zero, L_8042CD54
    if (ctx->r1 == 0) {
        // 0x8042CCE8: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_8042CD54;
    }
    // 0x8042CCE8: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8042CCEC: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x8042CCF0: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8042CCF4: addiu       $t0, $t0, 0xA0
    ctx->r8 = ADD32(ctx->r8, 0XA0);
    // 0x8042CCF8: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x8042CCFC: bne         $at, $zero, L_8042CD08
    if (ctx->r1 != 0) {
        // 0x8042CD00: sll         $t1, $v0, 2
        ctx->r9 = S32(ctx->r2 << 2);
            goto L_8042CD08;
    }
    // 0x8042CD00: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8042CD04: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_8042CD08:
    // 0x8042CD08: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8042CD0C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8042CD10: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x8042CD14: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x8042CD18: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8042CD1C: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x8042CD20: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8042CD24: addiu       $t1, $t1, 0xA0
    ctx->r9 = ADD32(ctx->r9, 0XA0);
    // 0x8042CD28: subu        $t2, $t7, $t5
    ctx->r10 = SUB32(ctx->r15, ctx->r13);
    // 0x8042CD2C: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x8042CD30: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x8042CD34: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x8042CD38: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8042CD3C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8042CD40: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8042CD44: andi        $a3, $t2, 0xFF
    ctx->r7 = ctx->r10 & 0XFF;
    // 0x8042CD48: andi        $a2, $t1, 0xFF
    ctx->r6 = ctx->r9 & 0XFF;
    // 0x8042CD4C: jal         0x8042B8A0
    // 0x8042CD50: andi        $a1, $t0, 0xFF
    ctx->r5 = ctx->r8 & 0XFF;
    func_8042B8A0(rdram, ctx);
        goto after_7;
    // 0x8042CD50: andi        $a1, $t0, 0xFF
    ctx->r5 = ctx->r8 & 0XFF;
    after_7:
L_8042CD54:
    // 0x8042CD54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8042CD58:
    // 0x8042CD58: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8042CD5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8042CD60: jr          $ra
    // 0x8042CD64: nop

    return;
    // 0x8042CD64: nop

;}
RECOMP_FUNC void func_80423344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423344: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80423348: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8042334C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80423350: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80423354: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80423358: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8042335C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80423360: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80423364: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x80423368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8042336C: jal         0x8004921C
    // 0x80423370: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80423370: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    after_0:
    // 0x80423374: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // 0x80423378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042337C: jal         0x8004921C
    // 0x80423380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80423380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80423384: lbu         $t0, 0x2D($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2D);
    // 0x80423388: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8042338C: lbu         $t2, 0x145($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X145);
    // 0x80423390: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80423394: lw          $v1, 0x168($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X168);
    // 0x80423398: lw          $t5, 0x16C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X16C);
    // 0x8042339C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x804233A0: lw          $t4, 0x80($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X80);
    // 0x804233A4: lw          $a3, 0x88($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X88);
    // 0x804233A8: addiu       $t6, $t5, 0xD
    ctx->r14 = ADD32(ctx->r13, 0XD);
    // 0x804233AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x804233B0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x804233B4: mflo        $t1
    ctx->r9 = lo;
    // 0x804233B8: nop

    // 0x804233BC: nop

    // 0x804233C0: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804233C4: mflo        $t3
    ctx->r11 = lo;
    // 0x804233C8: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x804233CC: jal         0x80423120
    // 0x804233D0: nop

    func_80423120(rdram, ctx);
        goto after_2;
    // 0x804233D0: nop

    after_2:
    // 0x804233D4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x804233D8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x804233DC: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x804233E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804233E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804233E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804233EC: jr          $ra
    // 0x804233F0: nop

    return;
    // 0x804233F0: nop

;}
RECOMP_FUNC void func_8077DE88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077DE88: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8077DE8C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8077DE90: lui         $t6, 0x8078
    ctx->r14 = S32(RELOC_HI16(778, 0X190) << 16);
    // 0x8077DE94: sw          $a1, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r5;
    // 0x8077DE98: addiu       $t6, $t6, -0x2090
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(778, 0X190));
    // 0x8077DE9C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8077DEA0: lui         $t8, 0x8078
    ctx->r24 = S32(RELOC_HI16(778, 0X6C) << 16);
    // 0x8077DEA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8077DEA8: addiu       $t8, $t8, -0x21B4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(778, 0X6C));
    // 0x8077DEAC: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x8077DEB0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8077DEB4: sb          $a2, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r6;
    // 0x8077DEB8: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8077DEBC: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8077DEC0: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
    // 0x8077DEC4: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8077DEC8: lw          $t0, -0x7BC4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7BC4);
    // 0x8077DECC: lui         $t1, 0x8078
    ctx->r9 = S32(RELOC_HI16(778, 0X198) << 16);
    // 0x8077DED0: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x8077DED4: lw          $v1, 0x10C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X10C);
    // 0x8077DED8: lui         $t2, 0x8078
    ctx->r10 = S32(RELOC_HI16(778, 0X19C) << 16);
    // 0x8077DEDC: lui         $t3, 0x8078
    ctx->r11 = S32(RELOC_HI16(778, 0X1A0) << 16);
    // 0x8077DEE0: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x8077DEE4: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x8077DEE8: lbu         $t1, -0x2088($t1)
    ctx->r9 = MEM_BU(ctx->r9, (int16_t)RELOC_LO16(778, 0X198));
    // 0x8077DEEC: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x8077DEF0: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x8077DEF4: sb          $t1, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r9;
    // 0x8077DEF8: lbu         $t2, -0x2084($t2)
    ctx->r10 = MEM_BU(ctx->r10, (int16_t)RELOC_LO16(778, 0X19C));
    // 0x8077DEFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8077DF00: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x8077DF04: sb          $t2, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r10;
    // 0x8077DF08: lbu         $t3, -0x2080($t3)
    ctx->r11 = MEM_BU(ctx->r11, (int16_t)RELOC_LO16(778, 0X1A0));
    // 0x8077DF0C: sb          $a1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r5;
    // 0x8077DF10: sb          $t3, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r11;
    // 0x8077DF14: jr          $ra
    // 0x8077DF18: sb          $a2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r6;
    return;
    // 0x8077DF18: sb          $a2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r6;
;}
RECOMP_FUNC void func_80790C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790C34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80790C38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80790C3C: jal         0x8004700C
    // 0x80790C40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80790C40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80790C44: beq         $v0, $zero, L_80790CA4
    if (ctx->r2 == 0) {
        // 0x80790C48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80790CA4;
    }
    // 0x80790C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80790C4C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80790C50: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80790C54: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x80790C58: lwc1        $f6, 0x84($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X84);
    // 0x80790C5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80790C60: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80790C64: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80790C68: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80790C6C: nop

    // 0x80790C70: bc1fl       L_80790C84
    if (!c1cs) {
        // 0x80790C74: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80790C84;
    }
    goto skip_0;
    // 0x80790C74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80790C78: b           L_80790CAC
    // 0x80790C7C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80790CAC;
    // 0x80790C7C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80790C80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80790C84:
    // 0x80790C84: nop

    // 0x80790C88: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80790C8C: nop

    // 0x80790C90: bc1f        L_80790C9C
    if (!c1cs) {
        // 0x80790C94: nop
    
            goto L_80790C9C;
    }
    // 0x80790C94: nop

    // 0x80790C98: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80790C9C:
    // 0x80790C9C: b           L_80790CAC
    // 0x80790CA0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80790CAC;
    // 0x80790CA0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80790CA4:
    // 0x80790CA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80790CA8: nop

L_80790CAC:
    // 0x80790CAC: jr          $ra
    // 0x80790CB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80790CB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_807BB590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BB590: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807BB594: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807BB598: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807BB59C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807BB5A0: lui         $t6, 0x807C
    ctx->r14 = S32(RELOC_HI16(895, 0X11F4) << 16);
    // 0x807BB5A4: addiu       $t6, $t6, -0x45FC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(895, 0X11F4));
    // 0x807BB5A8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807BB5AC: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x807BB5B0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x807BB5B4: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x807BB5B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807BB5BC: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x807BB5C0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807BB5C4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807BB5C8: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x807BB5CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807BB5D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807BB5D4: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x807BB5D8: jal         0x80048378
    // 0x807BB5DC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x807BB5DC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x807BB5E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807BB5E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BB5E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807BB5EC: jal         0x807BB7A4
    // 0x807BB5F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807BB7A4(rdram, ctx);
        goto after_1;
    // 0x807BB5F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x807BB5F4: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x807BB5F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807BB5FC: bne         $v1, $zero, L_807BB614
    if (ctx->r3 != 0) {
        // 0x807BB600: nop
    
            goto L_807BB614;
    }
    // 0x807BB600: nop

    // 0x807BB604: jal         0x80045A34
    // 0x807BB608: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x807BB608: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_2:
    // 0x807BB60C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x807BB610: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_807BB614:
    // 0x807BB614: lui         $t1, 0x807C
    ctx->r9 = S32(RELOC_HI16(895, 0XCB0) << 16);
    // 0x807BB618: addiu       $t1, $t1, -0x4B40
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(895, 0XCB0));
    // 0x807BB61C: sw          $t1, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r9;
    // 0x807BB620: sh          $zero, 0x28($v1)
    MEM_H(0X28, ctx->r3) = 0;
    // 0x807BB624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807BB628: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807BB62C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807BB630: jr          $ra
    // 0x807BB634: nop

    return;
    // 0x807BB634: nop

;}
RECOMP_FUNC void func_80023F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023F90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80023F94: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80023F98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023F9C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80023FA0: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x80023FA4: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80023FA8: lbu         $t7, 0x12($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X12);
    // 0x80023FAC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80023FB0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023FB4: beq         $t7, $zero, L_80023FE4
    if (ctx->r15 == 0) {
        // 0x80023FB8: addiu       $v0, $a0, 0xC8
        ctx->r2 = ADD32(ctx->r4, 0XC8);
            goto L_80023FE4;
    }
    // 0x80023FB8: addiu       $v0, $a0, 0xC8
    ctx->r2 = ADD32(ctx->r4, 0XC8);
    // 0x80023FBC: addiu       $v0, $a0, 0xC8
    ctx->r2 = ADD32(ctx->r4, 0XC8);
    // 0x80023FC0: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80023FC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80023FC8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80023FCC: jal         0x80023E18
    // 0x80023FD0: lwc1        $f14, -0x294($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X294);
    func_80023E18(rdram, ctx);
        goto after_0;
    // 0x80023FD0: lwc1        $f14, -0x294($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X294);
    after_0:
    // 0x80023FD4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80023FD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80023FDC: b           L_80024008
    // 0x80023FE0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_80024008;
    // 0x80023FE0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_80023FE4:
    // 0x80023FE4: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80023FE8: lwc1        $f14, 0xE0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x80023FEC: lw          $a2, 0xEC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XEC);
    // 0x80023FF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80023FF4: jal         0x80023DD0
    // 0x80023FF8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80023DD0(rdram, ctx);
        goto after_1;
    // 0x80023FF8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80023FFC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80024000: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80024004: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_80024008:
    // 0x80024008: jal         0x80023E64
    // 0x8002400C: nop

    func_80023E64(rdram, ctx);
        goto after_2;
    // 0x8002400C: nop

    after_2:
    // 0x80024010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024014: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80024018: jr          $ra
    // 0x8002401C: nop

    return;
    // 0x8002401C: nop

;}
RECOMP_FUNC void func_80065284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065284: jr          $ra
    // 0x80065288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80065288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_800685AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800685AC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800685B0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800685B4: lw          $t6, 0x158($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X158);
    // 0x800685B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800685BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800685C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800685C4: jal         0x800716C0
    // 0x800685C8: sw          $t6, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r14;
    func_800716C0(rdram, ctx);
        goto after_0;
    // 0x800685C8: sw          $t6, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r14;
    after_0:
    // 0x800685CC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800685D0: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x800685D4: addiu       $t7, $t7, -0x7AA0
    ctx->r15 = ADD32(ctx->r15, -0X7AA0);
    // 0x800685D8: jal         0x800716F8
    // 0x800685DC: sw          $t7, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r15;
    func_800716F8(rdram, ctx);
        goto after_1;
    // 0x800685DC: sw          $t7, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r15;
    after_1:
    // 0x800685E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800685E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800685E8: jr          $ra
    // 0x800685EC: nop

    return;
    // 0x800685EC: nop

;}
RECOMP_FUNC void func_8002CCC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CCC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002CCC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CCCC: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002CCD0: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002CCD4: addiu       $t6, $t6, 0x19E4
    ctx->r14 = ADD32(ctx->r14, 0X19E4);
    // 0x8002CCD8: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x8002CCDC: jal         0x8002AE54
    // 0x8002CCE0: sw          $zero, 0x14($t7)
    MEM_W(0X14, ctx->r15) = 0;
    func_8002AE54(rdram, ctx);
        goto after_0;
    // 0x8002CCE0: sw          $zero, 0x14($t7)
    MEM_W(0X14, ctx->r15) = 0;
    after_0:
    // 0x8002CCE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CCE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002CCEC: jr          $ra
    // 0x8002CCF0: nop

    return;
    // 0x8002CCF0: nop

;}
RECOMP_FUNC void func_806D0EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0EC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D0ECC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806D0ED0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806D0ED4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806D0ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D0EDC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806D0EE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806D0EE4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x806D0EE8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806D0EEC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806D0EF0: lui         $t2, 0x806D
    ctx->r10 = S32(RELOC_HI16(607, 0X1AB4) << 16);
    // 0x806D0EF4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806D0EF8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806D0EFC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806D0F00: lw          $t2, 0x1254($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(607, 0X1AB4));
    // 0x806D0F04: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806D0F08: jal         0x806D0D00
    // 0x806D0F0C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_806D0D00(rdram, ctx);
        goto after_0;
    // 0x806D0F0C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x806D0F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D0F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D0F18: jr          $ra
    // 0x806D0F1C: nop

    return;
    // 0x806D0F1C: nop

;}
RECOMP_FUNC void func_8000EC18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EC18: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8000EC1C: andi        $v1, $v0, 0xF
    ctx->r3 = ctx->r2 & 0XF;
    // 0x8000EC20: beq         $v1, $zero, L_8000EC2C
    if (ctx->r3 == 0) {
        // 0x8000EC24: sw          $a1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r5;
            goto L_8000EC2C;
    }
    // 0x8000EC24: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000EC28: sb          $v1, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r3;
L_8000EC2C:
    // 0x8000EC2C: sra         $a1, $v0, 4
    ctx->r5 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8000EC30: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8000EC34: beq         $a1, $zero, L_8000EC40
    if (ctx->r5 == 0) {
        // 0x8000EC38: nop
    
            goto L_8000EC40;
    }
    // 0x8000EC38: nop

    // 0x8000EC3C: sb          $a1, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r5;
L_8000EC40:
    // 0x8000EC40: jr          $ra
    // 0x8000EC44: nop

    return;
    // 0x8000EC44: nop

;}
RECOMP_FUNC void func_8003C9B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C9B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003C9B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003C9B8: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8003C9BC: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x8003C9C0: jr          $ra
    // 0x8003C9C4: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8003C9C4: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_800311D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800311D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800311D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800311D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800311DC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x800311E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800311E4: jal         0x800310A0
    // 0x800311E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x800311E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800311EC: jal         0x80030CD0
    // 0x800311F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80030CD0(rdram, ctx);
        goto after_1;
    // 0x800311F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800311F4: beq         $v0, $zero, L_8003121C
    if (ctx->r2 == 0) {
        // 0x800311F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003121C;
    }
    // 0x800311F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800311FC: jal         0x800310D0
    // 0x80031200: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800310D0(rdram, ctx);
        goto after_2;
    // 0x80031200: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80031204: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80031208: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8003120C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80031210: lw          $a2, 0x78($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X78);
    // 0x80031214: jal         0x80031170
    // 0x80031218: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80031170(rdram, ctx);
        goto after_3;
    // 0x80031218: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
L_8003121C:
    // 0x8003121C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80031220: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80031224: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80031228: jr          $ra
    // 0x8003122C: nop

    return;
    // 0x8003122C: nop

;}
RECOMP_FUNC void func_806F966C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F966C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F9670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F9674: jal         0x806F95A0
    // 0x806F9678: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F95A0(rdram, ctx);
        goto after_0;
    // 0x806F9678: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F967C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F9680: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806F9684: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x806F9688: jal         0x80065ABC
    // 0x806F968C: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x806F968C: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    after_1:
    // 0x806F9690: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F9694: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x806F9698: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x806F969C: bnel        $t6, $zero, L_806F96B0
    if (ctx->r14 != 0) {
        // 0x806F96A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F96B0;
    }
    goto skip_0;
    // 0x806F96A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806F96A4: jal         0x806F9A78
    // 0x806F96A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806F9A78(rdram, ctx);
        goto after_2;
    // 0x806F96A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x806F96AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F96B0:
    // 0x806F96B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F96B4: jr          $ra
    // 0x806F96B8: nop

    return;
    // 0x806F96B8: nop

;}
RECOMP_FUNC void func_8079AE10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079AE10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079AE14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079AE18: jal         0x80799A80
    // 0x8079AE1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80799A80(rdram, ctx);
        goto after_0;
    // 0x8079AE1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8079AE20: jal         0x80045BD8
    // 0x8079AE24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8079AE24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8079AE28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079AE2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079AE30: jr          $ra
    // 0x8079AE34: nop

    return;
    // 0x8079AE34: nop

;}
RECOMP_FUNC void func_8002691C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002691C: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80026920: addiu       $t6, $t6, 0x68BC
    ctx->r14 = ADD32(ctx->r14, 0X68BC);
    // 0x80026924: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80026928: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    // 0x8002692C: jr          $ra
    // 0x80026930: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    return;
    // 0x80026930: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80032D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032D78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80032D7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032D80: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80032D84: jal         0x80028320
    // 0x80032D88: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80028320(rdram, ctx);
        goto after_0;
    // 0x80032D88: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80032D8C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80032D90: sw          $v0, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = ctx->r2;
    // 0x80032D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032D98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80032D9C: jr          $ra
    // 0x80032DA0: nop

    return;
    // 0x80032DA0: nop

;}
RECOMP_FUNC void func_805A1D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1D10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A1D14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805A1D18: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x805A1D1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A1D20: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x805A1D24: jal         0x80067878
    // 0x805A1D28: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x805A1D28: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    after_0:
    // 0x805A1D2C: jal         0x80045BD8
    // 0x805A1D30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x805A1D30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805A1D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A1D38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A1D3C: jr          $ra
    // 0x805A1D40: nop

    return;
    // 0x805A1D40: nop

;}
RECOMP_FUNC void func_80449670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449670: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80449674: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80449678: lw          $t7, -0x71A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X71A8);
    // 0x8044967C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80449680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80449684: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80449688: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8044968C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80449690: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80449694: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80449698: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x8044969C: bne         $t9, $zero, L_804496D4
    if (ctx->r25 != 0) {
        // 0x804496A0: lw          $v1, 0x1F4($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X1F4);
            goto L_804496D4;
    }
    // 0x804496A0: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x804496A4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804496A8: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x804496AC: addu        $a0, $v1, $at
    ctx->r4 = ADD32(ctx->r3, ctx->r1);
    // 0x804496B0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804496B4: ori         $at, $at, 0x6E54
    ctx->r1 = ctx->r1 | 0X6E54;
    // 0x804496B8: addu        $a1, $v1, $at
    ctx->r5 = ADD32(ctx->r3, ctx->r1);
    // 0x804496BC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x804496C0: jal         0x80449318
    // 0x804496C4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80449318(rdram, ctx);
        goto after_0;
    // 0x804496C4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x804496C8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x804496CC: b           L_80449700
    // 0x804496D0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
        goto L_80449700;
    // 0x804496D0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_804496D4:
    // 0x804496D4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804496D8: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x804496DC: addu        $a0, $v1, $at
    ctx->r4 = ADD32(ctx->r3, ctx->r1);
    // 0x804496E0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804496E4: ori         $at, $at, 0x6E54
    ctx->r1 = ctx->r1 | 0X6E54;
    // 0x804496E8: addu        $a1, $v1, $at
    ctx->r5 = ADD32(ctx->r3, ctx->r1);
    // 0x804496EC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x804496F0: jal         0x804494C4
    // 0x804496F4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_804494C4(rdram, ctx);
        goto after_1;
    // 0x804496F4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x804496F8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x804496FC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_80449700:
    // 0x80449700: lw          $t0, 0x18($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X18);
    // 0x80449704: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80449708: beql        $t0, $zero, L_80449794
    if (ctx->r8 == 0) {
        // 0x8044970C: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80449794;
    }
    goto skip_0;
    // 0x8044970C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x80449710: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80449714: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449718: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x8044971C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80449720: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80449724: lwc1        $f4, 0x6BE0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6BE0);
    // 0x80449728: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8044972C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80449730: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80449734: lwc1        $f10, 0x6BE4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6BE4);
    // 0x80449738: swc1        $f8, 0x6BE0($v0)
    MEM_W(0X6BE0, ctx->r2) = ctx->f8.u32l;
    // 0x8044973C: lwc1        $f4, 0x6BE0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6BE0);
    // 0x80449740: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80449744: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80449748: swc1        $f18, 0x6BE4($v0)
    MEM_W(0X6BE4, ctx->r2) = ctx->f18.u32l;
    // 0x8044974C: bc1fl       L_80449768
    if (!c1cs) {
        // 0x80449750: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80449768;
    }
    goto skip_1;
    // 0x80449750: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    skip_1:
    // 0x80449754: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80449758: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044975C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80449760: swc1        $f2, 0x6BE0($at)
    MEM_W(0X6BE0, ctx->r1) = ctx->f2.u32l;
    // 0x80449764: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
L_80449768:
    // 0x80449768: ori         $at, $at, 0x6BE0
    ctx->r1 = ctx->r1 | 0X6BE0;
    // 0x8044976C: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80449770: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80449774: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80449778: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8044977C: nop

    // 0x80449780: bc1fl       L_804497A8
    if (!c1cs) {
        // 0x80449784: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804497A8;
    }
    goto skip_2;
    // 0x80449784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80449788: b           L_804497A4
    // 0x8044978C: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
        goto L_804497A4;
    // 0x8044978C: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80449790: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80449794:
    // 0x80449794: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449798: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x8044979C: swc1        $f2, 0x6BE0($v0)
    MEM_W(0X6BE0, ctx->r2) = ctx->f2.u32l;
    // 0x804497A0: swc1        $f2, 0x6BE4($v0)
    MEM_W(0X6BE4, ctx->r2) = ctx->f2.u32l;
L_804497A4:
    // 0x804497A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804497A8:
    // 0x804497A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804497AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804497B0: jr          $ra
    // 0x804497B4: nop

    return;
    // 0x804497B4: nop

;}
RECOMP_FUNC void func_804410DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804410DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804410E0: mul.s       $f2, $f14, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x804410E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804410E8: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x804410EC: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x804410F0: lwc1        $f12, 0xC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC);
    // 0x804410F4: bc1f        L_80441148
    if (!c1cs) {
        // 0x804410F8: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80441148;
    }
    // 0x804410F8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x804410FC: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80441100: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80441104: bc1fl       L_80441114
    if (!c1cs) {
        // 0x80441108: lwc1        $f2, 0x0($a2)
        ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
            goto L_80441114;
    }
    goto skip_0;
    // 0x80441108: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x8044110C: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x80441110: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
L_80441114:
    // 0x80441114: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80441118: nop

    // 0x8044111C: bc1fl       L_80441134
    if (!c1cs) {
        // 0x80441120: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80441134;
    }
    goto skip_1;
    // 0x80441120: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_1:
    // 0x80441124: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80441128: jr          $ra
    // 0x8044112C: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    return;
    // 0x8044112C: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x80441130: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80441134:
    // 0x80441134: nop

    // 0x80441138: bc1f        L_80441198
    if (!c1cs) {
        // 0x8044113C: nop
    
            goto L_80441198;
    }
    // 0x8044113C: nop

    // 0x80441140: jr          $ra
    // 0x80441144: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    return;
    // 0x80441144: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
L_80441148:
    // 0x80441148: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8044114C: lwc1        $f16, 0x10($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80441150: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80441154: nop

    // 0x80441158: bc1fl       L_80441168
    if (!c1cs) {
        // 0x8044115C: lwc1        $f2, 0x0($a2)
        ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
            goto L_80441168;
    }
    goto skip_2;
    // 0x8044115C: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    skip_2:
    // 0x80441160: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80441164: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
L_80441168:
    // 0x80441168: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8044116C: nop

    // 0x80441170: bc1fl       L_80441188
    if (!c1cs) {
        // 0x80441174: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80441188;
    }
    goto skip_3;
    // 0x80441174: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_3:
    // 0x80441178: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8044117C: jr          $ra
    // 0x80441180: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    return;
    // 0x80441180: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x80441184: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80441188:
    // 0x80441188: nop

    // 0x8044118C: bc1f        L_80441198
    if (!c1cs) {
        // 0x80441190: nop
    
            goto L_80441198;
    }
    // 0x80441190: nop

    // 0x80441194: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
L_80441198:
    // 0x80441198: jr          $ra
    // 0x8044119C: nop

    return;
    // 0x8044119C: nop

;}
RECOMP_FUNC void func_80025D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025D68: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80025D6C: addiu       $t6, $t6, 0x5B4C
    ctx->r14 = ADD32(ctx->r14, 0X5B4C);
    // 0x80025D70: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80025D74: jr          $ra
    // 0x80025D78: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x80025D78: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80446A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446A50: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446A54: jr          $ra
    // 0x80446A58: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    return;
    // 0x80446A58: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80019F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019F90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80019F94: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80019F98: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80019F9C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80019FA0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80019FA4: lui         $s2, 0x800C
    ctx->r18 = S32(0X800C << 16);
    // 0x80019FA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80019FAC: addiu       $s2, $s2, -0x10
    ctx->r18 = ADD32(ctx->r18, -0X10);
    // 0x80019FB0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80019FB4: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    // 0x80019FB8: addiu       $s3, $zero, 0x90
    ctx->r19 = ADD32(0, 0X90);
L_80019FBC:
    // 0x80019FBC: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019FC0: mflo        $t6
    ctx->r14 = lo;
    // 0x80019FC4: addu        $a0, $s2, $t6
    ctx->r4 = ADD32(ctx->r18, ctx->r14);
    // 0x80019FC8: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x80019FCC: beql        $s1, $t7, L_80019FE0
    if (ctx->r17 == ctx->r15) {
        // 0x80019FD0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80019FE0;
    }
    goto skip_0;
    // 0x80019FD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80019FD4: jal         0x80019BE0
    // 0x80019FD8: nop

    func_80019BE0(rdram, ctx);
        goto after_0;
    // 0x80019FD8: nop

    after_0:
    // 0x80019FDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80019FE0:
    // 0x80019FE0: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80019FE4: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80019FE8: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80019FEC: bne         $at, $zero, L_80019FBC
    if (ctx->r1 != 0) {
        // 0x80019FF0: nop
    
            goto L_80019FBC;
    }
    // 0x80019FF0: nop

    // 0x80019FF4: jal         0x8001A330
    // 0x80019FF8: nop

    func_8001A330(rdram, ctx);
        goto after_1;
    // 0x80019FF8: nop

    after_1:
    // 0x80019FFC: jal         0x8001A534
    // 0x8001A000: nop

    func_8001A534(rdram, ctx);
        goto after_2;
    // 0x8001A000: nop

    after_2:
    // 0x8001A004: jal         0x8001A760
    // 0x8001A008: nop

    func_8001A760(rdram, ctx);
        goto after_3;
    // 0x8001A008: nop

    after_3:
    // 0x8001A00C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001A010: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001A014: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001A018: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A01C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001A020: jr          $ra
    // 0x8001A024: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001A024: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80079948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079948: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007994C: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80079950: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80079954: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80079958: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x8007995C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80079960: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80079964: lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XA);
    // 0x80079968: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x8007996C: lbu         $a3, 0x5($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X5);
    // 0x80079970: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80079974: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80079978: lhu         $t5, 0xA($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XA);
    // 0x8007997C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80079980: lbu         $t0, 0x5($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X5);
    // 0x80079984: lbu         $a2, 0x4($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4);
    // 0x80079988: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8007998C: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80079990: mflo        $t7
    ctx->r15 = lo;
    // 0x80079994: sllv        $t8, $t7, $a3
    ctx->r24 = S32(ctx->r15 << (ctx->r7 & 31));
    // 0x80079998: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8007999C: sra         $t2, $t9, 1
    ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800799A0: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800799A4: lhu         $t7, 0x8($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X8);
    // 0x800799A8: mflo        $t3
    ctx->r11 = lo;
    // 0x800799AC: addu        $a1, $t4, $t3
    ctx->r5 = ADD32(ctx->r12, ctx->r11);
    // 0x800799B0: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800799B4: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800799B8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800799BC: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800799C0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800799C4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x800799C8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800799CC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800799D0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800799D4: mflo        $t8
    ctx->r24 = lo;
    // 0x800799D8: sllv        $t9, $t8, $t0
    ctx->r25 = S32(ctx->r24 << (ctx->r8 & 31));
    // 0x800799DC: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800799E0: sra         $t2, $t6, 1
    ctx->r10 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800799E4: multu       $t4, $t2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800799E8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800799EC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800799F0: mflo        $t3
    ctx->r11 = lo;
    // 0x800799F4: addu        $t1, $t5, $t3
    ctx->r9 = ADD32(ctx->r13, ctx->r11);
    // 0x800799F8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800799FC: lbu         $t9, 0x4($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X4);
    // 0x80079A00: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80079A04: jal         0x80079448
    // 0x80079A08: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    func_80079448(rdram, ctx);
        goto after_0;
    // 0x80079A08: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80079A0C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80079A10: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x80079A14: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80079A18: jr          $ra
    // 0x80079A1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80079A1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_807A9D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A9D4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A9D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A9D54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807A9D58: jal         0x80045A34
    // 0x807A9D5C: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807A9D5C: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    after_0:
    // 0x807A9D60: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x807A9D64: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x807A9D68: bne         $v0, $zero, L_807A9D78
    if (ctx->r2 != 0) {
        // 0x807A9D6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807A9D78;
    }
    // 0x807A9D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A9D70: b           L_807A9D7C
    // 0x807A9D74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807A9D7C;
    // 0x807A9D74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807A9D78:
    // 0x807A9D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807A9D7C:
    // 0x807A9D7C: jr          $ra
    // 0x807A9D80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x807A9D80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000684C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000684C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80006850: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80006854: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80006858: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000685C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80006860: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80006864: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80006868: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000686C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80006870: jal         0x800073BC
    // 0x80006874: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800073BC(rdram, ctx);
        goto after_0;
    // 0x80006874: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80006878: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x8000687C: addiu       $s3, $s3, 0x4D10
    ctx->r19 = ADD32(ctx->r19, 0X4D10);
    // 0x80006880: lw          $v1, 0x1D70($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1D70);
    // 0x80006884: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80006888: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x8000688C: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80006890: lhu         $s0, 0x0($t7)
    ctx->r16 = MEM_HU(ctx->r15, 0X0);
    // 0x80006894: addu        $t8, $s0, $v1
    ctx->r24 = ADD32(ctx->r16, ctx->r3);
    // 0x80006898: lbu         $s1, 0x0($t8)
    ctx->r17 = MEM_BU(ctx->r24, 0X0);
    // 0x8000689C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800068A0: blezl       $s1, L_800068D4
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800068A4: lw          $t1, 0x3C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X3C);
            goto L_800068D4;
    }
    goto skip_0;
    // 0x800068A4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x800068A8: lw          $t9, 0x1D70($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X1D70);
L_800068AC:
    // 0x800068AC: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x800068B0: lbu         $s2, 0x0($t0)
    ctx->r18 = MEM_BU(ctx->r8, 0X0);
    // 0x800068B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800068B8: jal         0x800070EC
    // 0x800068BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800070EC(rdram, ctx);
        goto after_1;
    // 0x800068BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800068C0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800068C4: bgtzl       $s1, L_800068AC
    if (SIGNED(ctx->r17) > 0) {
        // 0x800068C8: lw          $t9, 0x1D70($s3)
        ctx->r25 = MEM_W(ctx->r19, 0X1D70);
            goto L_800068AC;
    }
    goto skip_1;
    // 0x800068C8: lw          $t9, 0x1D70($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X1D70);
    skip_1:
    // 0x800068CC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800068D0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_800068D4:
    // 0x800068D4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800068D8: sw          $s2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r18;
    // 0x800068DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800068E0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800068E4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800068E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800068EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800068F0: jr          $ra
    // 0x800068F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800068F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_807B73D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B73D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B73D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807B73DC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x807B73E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B73E4: lui         $a0, 0x807B
    ctx->r4 = S32(RELOC_HI16(880, 0X31B0) << 16);
    // 0x807B73E8: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x807B73EC: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    // 0x807B73F0: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x807B73F4: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x807B73F8: ori         $a1, $a1, 0x2200
    ctx->r5 = ctx->r5 | 0X2200;
    // 0x807B73FC: addiu       $a0, $a0, 0x79B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(880, 0X31B0));
    // 0x807B7400: jal         0x80046804
    // 0x807B7404: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x807B7404: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x807B7408: bne         $v0, $zero, L_807B7418
    if (ctx->r2 != 0) {
        // 0x807B740C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_807B7418;
    }
    // 0x807B740C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x807B7410: b           L_807B745C
    // 0x807B7414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807B745C;
    // 0x807B7414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807B7418:
    // 0x807B7418: jal         0x80044194
    // 0x807B741C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_1;
    // 0x807B741C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x807B7420: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807B7424: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807B7428: lw          $t7, 0x478($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X478);
    // 0x807B742C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x807B7430: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x807B7434: lwc1        $f6, 0x30($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X30);
    // 0x807B7438: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807B743C: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x807B7440: lw          $t8, 0x478($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X478);
    // 0x807B7444: lwc1        $f8, 0x34($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X34);
    // 0x807B7448: swc1        $f8, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f8.u32l;
    // 0x807B744C: lw          $t9, 0x478($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X478);
    // 0x807B7450: lwc1        $f10, 0x38($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X38);
    // 0x807B7454: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x807B7458: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
L_807B745C:
    // 0x807B745C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B7460: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807B7464: jr          $ra
    // 0x807B7468: nop

    return;
    // 0x807B7468: nop

    // 0x807B746C: nop

;}
RECOMP_FUNC void func_800689F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800689F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800689F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800689F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800689FC: jal         0x800689E8
    // 0x80068A00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800689E8(rdram, ctx);
        goto after_0;
    // 0x80068A00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80068A04: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x80068A08: addiu       $s0, $s0, 0x7EA0
    ctx->r16 = ADD32(ctx->r16, 0X7EA0);
    // 0x80068A0C: lbu         $t6, 0x20($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X20);
    // 0x80068A10: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80068A14: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80068A18: bnel        $t6, $zero, L_80068A28
    if (ctx->r14 != 0) {
        // 0x80068A1C: sb          $zero, 0x20($s0)
        MEM_B(0X20, ctx->r16) = 0;
            goto L_80068A28;
    }
    goto skip_0;
    // 0x80068A1C: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
    skip_0:
    // 0x80068A20: sw          $t7, -0x7B78($at)
    MEM_W(-0X7B78, ctx->r1) = ctx->r15;
    // 0x80068A24: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
L_80068A28:
    // 0x80068A28: jal         0x80068438
    // 0x80068A2C: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    func_80068438(rdram, ctx);
        goto after_1;
    // 0x80068A2C: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    after_1:
    // 0x80068A30: jal         0x8006915C
    // 0x80068A34: nop

    func_8006915C(rdram, ctx);
        goto after_2;
    // 0x80068A34: nop

    after_2:
    // 0x80068A38: lw          $t8, 0x59C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X59C);
    // 0x80068A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80068A40: jal         0x80067930
    // 0x80068A44: lw          $a0, 0x108($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X108);
    func_80067930(rdram, ctx);
        goto after_3;
    // 0x80068A44: lw          $a0, 0x108($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X108);
    after_3:
    // 0x80068A48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80068A4C: bnel        $v0, $at, L_80068A68
    if (ctx->r2 != ctx->r1) {
        // 0x80068A50: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80068A68;
    }
    goto skip_1;
    // 0x80068A50: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    skip_1:
    // 0x80068A54: lw          $t9, 0x59C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X59C);
    // 0x80068A58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80068A5C: jal         0x80067878
    // 0x80068A60: lw          $a0, 0x108($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X108);
    func_80067878(rdram, ctx);
        goto after_4;
    // 0x80068A60: lw          $a0, 0x108($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X108);
    after_4:
    // 0x80068A64: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80068A68:
    // 0x80068A68: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80068A6C: sb          $t0, -0x7AE0($at)
    MEM_B(-0X7AE0, ctx->r1) = ctx->r8;
    // 0x80068A70: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x80068A74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80068A78: bnel        $t1, $at, L_80068A90
    if (ctx->r9 != ctx->r1) {
        // 0x80068A7C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80068A90;
    }
    goto skip_2;
    // 0x80068A7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_2:
    // 0x80068A80: jal         0x80069964
    // 0x80068A84: nop

    func_80069964(rdram, ctx);
        goto after_5;
    // 0x80068A84: nop

    after_5:
    // 0x80068A88: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80068A8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80068A90:
    // 0x80068A90: lw          $t9, 0xCC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XCC);
    // 0x80068A94: jalr        $t9
    // 0x80068A98: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x80068A98: nop

    after_6:
    // 0x80068A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80068AA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068AA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80068AA8: jr          $ra
    // 0x80068AAC: nop

    return;
    // 0x80068AAC: nop

;}
RECOMP_FUNC void func_8079D7A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079D7A0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8079D7A4: addiu       $at, $zero, 0x46B9
    ctx->r1 = ADD32(0, 0X46B9);
    // 0x8079D7A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8079D7AC: bne         $t6, $at, L_8079D7C0
    if (ctx->r14 != ctx->r1) {
        // 0x8079D7B0: nop
    
            goto L_8079D7C0;
    }
    // 0x8079D7B0: nop

    // 0x8079D7B4: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(832, 0X260) << 16);
    // 0x8079D7B8: jr          $ra
    // 0x8079D7BC: addiu       $v0, $v0, -0x2600
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(832, 0X260));
    return;
    // 0x8079D7BC: addiu       $v0, $v0, -0x2600
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(832, 0X260));
L_8079D7C0:
    // 0x8079D7C0: jr          $ra
    // 0x8079D7C4: nop

    return;
    // 0x8079D7C4: nop

;}
RECOMP_FUNC void func_805E4D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805E4D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E4D28: jal         0x805E4BB8
    // 0x805E4D2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805E4BB8(rdram, ctx);
        goto after_0;
    // 0x805E4D2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805E4D30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805E4D34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E4D38: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x805E4D3C: jal         0x805E4D78
    // 0x805E4D40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805E4D78(rdram, ctx);
        goto after_1;
    // 0x805E4D40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x805E4D44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805E4D48: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805E4D4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805E4D50: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805E4D54: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805E4D58: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x805E4D5C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x805E4D60: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805E4D64: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x805E4D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805E4D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805E4D70: jr          $ra
    // 0x805E4D74: nop

    return;
    // 0x805E4D74: nop

;}
RECOMP_FUNC void func_800071C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800071C8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800071CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800071D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800071D4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800071D8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800071DC: jal         0x800073F8
    // 0x800071E0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    func_800073F8(rdram, ctx);
        goto after_0;
    // 0x800071E0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_0:
    // 0x800071E4: beq         $v0, $zero, L_800071FC
    if (ctx->r2 == 0) {
        // 0x800071E8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800071FC;
    }
    // 0x800071E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800071EC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800071F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800071F4: b           L_80007354
    // 0x800071F8: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
        goto L_80007354;
    // 0x800071F8: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_800071FC:
    // 0x800071FC: jal         0x8000744C
    // 0x80007200: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_8000744C(rdram, ctx);
        goto after_1;
    // 0x80007200: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x80007204: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80007208: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8000720C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80007210: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80007214: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x80007218: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x8000721C: addiu       $t1, $t9, 0xF
    ctx->r9 = ADD32(ctx->r25, 0XF);
    // 0x80007220: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80007224: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80007228: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x8000722C: lb          $t3, 0x18($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X18);
    // 0x80007230: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80007234: lb          $a0, 0x19($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X19);
    // 0x80007238: lw          $t4, 0x10($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X10);
    // 0x8000723C: sltiu       $at, $a0, 0x5
    ctx->r1 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x80007240: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80007244: beq         $at, $zero, L_800072F0
    if (ctx->r1 == 0) {
        // 0x80007248: sw          $t4, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r12;
            goto L_800072F0;
    }
    // 0x80007248: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8000724C: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80007250: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80007254: addu        $at, $at, $t5
    gpr jr_addend_8000725C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80007258: lw          $t5, -0x43F0($at)
    ctx->r13 = ADD32(ctx->r1, -0X43F0);
    // 0x8000725C: jr          $t5
    // 0x80007260: nop

    switch (jr_addend_8000725C >> 2) {
        case 0: goto L_80007264; break;
        case 1: goto L_80007284; break;
        case 2: goto L_800072A8; break;
        case 3: goto L_800072CC; break;
        case 4: goto L_800072CC; break;
        default: switch_error(__func__, 0x8000725C, 0x800ABC10);
    }
    // 0x80007260: nop

L_80007264:
    // 0x80007264: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80007268: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8000726C: jal         0x80005698
    // 0x80007270: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_80005698(rdram, ctx);
        goto after_2;
    // 0x80007270: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x80007274: bne         $v0, $zero, L_800072F0
    if (ctx->r2 != 0) {
        // 0x80007278: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800072F0;
    }
    // 0x80007278: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000727C: b           L_800073AC
    // 0x80007280: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800073AC;
    // 0x80007280: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80007284:
    // 0x80007284: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80007288: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8000728C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80007290: jal         0x80003A5C
    // 0x80007294: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    func_80003A5C(rdram, ctx);
        goto after_3;
    // 0x80007294: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    after_3:
    // 0x80007298: bne         $v0, $zero, L_800072F0
    if (ctx->r2 != 0) {
        // 0x8000729C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800072F0;
    }
    // 0x8000729C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800072A0: b           L_800073AC
    // 0x800072A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800073AC;
    // 0x800072A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800072A8:
    // 0x800072A8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800072AC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800072B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800072B4: jal         0x80003A5C
    // 0x800072B8: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    func_80003A5C(rdram, ctx);
        goto after_4;
    // 0x800072B8: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x800072BC: bne         $v0, $zero, L_800072F0
    if (ctx->r2 != 0) {
        // 0x800072C0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800072F0;
    }
    // 0x800072C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800072C4: b           L_800073AC
    // 0x800072C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800073AC;
    // 0x800072C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800072CC:
    // 0x800072CC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800072D0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800072D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800072D8: jal         0x80003A5C
    // 0x800072DC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    func_80003A5C(rdram, ctx);
        goto after_5;
    // 0x800072DC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    after_5:
    // 0x800072E0: bne         $v0, $zero, L_800072F0
    if (ctx->r2 != 0) {
        // 0x800072E4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800072F0;
    }
    // 0x800072E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800072E8: b           L_800073AC
    // 0x800072EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800073AC;
    // 0x800072EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800072F0:
    // 0x800072F0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800072F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800072F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800072FC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80007300: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80007304: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80007308: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8000730C: bne         $t8, $at, L_80007334
    if (ctx->r24 != ctx->r1) {
        // 0x80007310: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80007334;
    }
    // 0x80007310: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80007314: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80007318: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8000731C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80007320: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80007324: jal         0x80007798
    // 0x80007328: lh          $a3, 0x2($t9)
    ctx->r7 = MEM_H(ctx->r25, 0X2);
    func_80007798(rdram, ctx);
        goto after_6;
    // 0x80007328: lh          $a3, 0x2($t9)
    ctx->r7 = MEM_H(ctx->r25, 0X2);
    after_6:
    // 0x8000732C: b           L_80007340
    // 0x80007330: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
        goto L_80007340;
    // 0x80007330: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_80007334:
    // 0x80007334: jal         0x80007674
    // 0x80007338: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    func_80007674(rdram, ctx);
        goto after_7;
    // 0x80007338: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x8000733C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_80007340:
    // 0x80007340: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80007344: bne         $t0, $zero, L_80007354
    if (ctx->r8 != 0) {
        // 0x80007348: nop
    
            goto L_80007354;
    }
    // 0x80007348: nop

    // 0x8000734C: b           L_80007354
    // 0x80007350: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_80007354;
    // 0x80007350: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_80007354:
    // 0x80007354: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80007358: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000735C: beq         $v0, $zero, L_8000737C
    if (ctx->r2 == 0) {
        // 0x80007360: nop
    
            goto L_8000737C;
    }
    // 0x80007360: nop

    // 0x80007364: beq         $v0, $at, L_8000738C
    if (ctx->r2 == ctx->r1) {
        // 0x80007368: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000738C;
    }
    // 0x80007368: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000736C: beq         $v0, $at, L_8000739C
    if (ctx->r2 == ctx->r1) {
        // 0x80007370: nop
    
            goto L_8000739C;
    }
    // 0x80007370: nop

    // 0x80007374: b           L_800073A8
    // 0x80007378: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800073A8;
    // 0x80007378: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8000737C:
    // 0x8000737C: jal         0x8000678C
    // 0x80007380: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_8000678C(rdram, ctx);
        goto after_8;
    // 0x80007380: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_8:
    // 0x80007384: b           L_800073A8
    // 0x80007388: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800073A8;
    // 0x80007388: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8000738C:
    // 0x8000738C: jal         0x8000675C
    // 0x80007390: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_8000675C(rdram, ctx);
        goto after_9;
    // 0x80007390: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_9:
    // 0x80007394: b           L_800073A8
    // 0x80007398: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800073A8;
    // 0x80007398: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8000739C:
    // 0x8000739C: jal         0x800067BC
    // 0x800073A0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800067BC(rdram, ctx);
        goto after_10;
    // 0x800073A0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_10:
    // 0x800073A4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800073A8:
    // 0x800073A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800073AC:
    // 0x800073AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800073B0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800073B4: jr          $ra
    // 0x800073B8: nop

    return;
    // 0x800073B8: nop

;}
RECOMP_FUNC void func_8044C4C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044C4C8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8044C4CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8044C4D0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8044C4D4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8044C4D8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8044C4DC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8044C4E0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8044C4E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8044C4E8: jal         0x80066E88
    // 0x8044C4EC: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8044C4EC: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    after_0:
    // 0x8044C4F0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8044C4F4: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8044C4F8: jal         0x80066DE4
    // 0x8044C4FC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8044C4FC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x8044C500: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8044C504: jal         0x80066E88
    // 0x8044C508: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8044C508: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x8044C50C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8044C510: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8044C514: jal         0x80066DE4
    // 0x8044C518: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8044C518: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x8044C51C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8044C520: jal         0x80066E88
    // 0x8044C524: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x8044C524: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8044C528: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8044C52C: jal         0x80066DE4
    // 0x8044C530: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x8044C530: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8044C534: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8044C538: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8044C53C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8044C540: neg.s       $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = -ctx->f20.fl;
    // 0x8044C544: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8044C548: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8044C54C: neg.s       $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = -ctx->f16.fl;
    // 0x8044C550: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8044C554: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8044C558: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8044C55C: mul.s       $f18, $f22, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x8044C560: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8044C564: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C568: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8044C56C: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8044C570: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8044C574: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8044C578: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8044C57C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C580: mul.s       $f10, $f20, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8044C584: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8044C588: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8044C58C: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8044C590: mul.s       $f8, $f22, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8044C594: nop

    // 0x8044C598: mul.s       $f12, $f20, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8044C59C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8044C5A0: mul.s       $f10, $f22, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8044C5A4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8044C5A8: neg.s       $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = -ctx->f22.fl;
    // 0x8044C5AC: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8044C5B0: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8044C5B4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8044C5B8: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8044C5BC: nop

    // 0x8044C5C0: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8044C5C4: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x8044C5C8: mul.s       $f8, $f20, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x8044C5CC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8044C5D0: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    // 0x8044C5D4: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x8044C5D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8044C5DC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8044C5E0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8044C5E4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8044C5E8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8044C5EC: jr          $ra
    // 0x8044C5F0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8044C5F0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_806F2188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2188: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806F218C: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x806F2190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F2194: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F2198: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F219C: bne         $t6, $zero, L_806F21D4
    if (ctx->r14 != 0) {
        // 0x806F21A0: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_806F21D4;
    }
    // 0x806F21A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F21A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F21A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F21AC: jal         0x806F2554
    // 0x806F21B0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F2554(rdram, ctx);
        goto after_0;
    // 0x806F21B0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_0:
    // 0x806F21B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806F21B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F21BC: jal         0x806F1FC8
    // 0x806F21C0: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    func_806F1FC8(rdram, ctx);
        goto after_1;
    // 0x806F21C0: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x806F21C4: jal         0x8005FE48
    // 0x806F21C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x806F21C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806F21CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806F21D0: sb          $t7, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r15;
L_806F21D4:
    // 0x806F21D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F21D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F21DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F21E0: jr          $ra
    // 0x806F21E4: nop

    return;
    // 0x806F21E4: nop

;}
RECOMP_FUNC void func_805D86B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D86B0: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x805D86B4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x805D86B8: lui         $t1, 0x805E
    ctx->r9 = S32(RELOC_HI16(474, 0X2270) << 16);
    // 0x805D86BC: bne         $v0, $zero, L_805D8700
    if (ctx->r2 != 0) {
        // 0x805D86C0: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_805D8700;
    }
    // 0x805D86C0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x805D86C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805D86C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805D86CC: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x805D86D0: nop

    // 0x805D86D4: bc1fl       L_805D86E4
    if (!c1cs) {
        // 0x805D86D8: lw          $t7, 0x18($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X18);
            goto L_805D86E4;
    }
    goto skip_0;
    // 0x805D86D8: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    skip_0:
    // 0x805D86DC: sw          $t6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r14;
    // 0x805D86E0: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
L_805D86E4:
    // 0x805D86E4: addiu       $v1, $t7, 0x1
    ctx->r3 = ADD32(ctx->r15, 0X1);
    // 0x805D86E8: slti        $at, $v1, 0x1C
    ctx->r1 = SIGNED(ctx->r3) < 0X1C ? 1 : 0;
    // 0x805D86EC: bne         $at, $zero, L_805D8708
    if (ctx->r1 != 0) {
        // 0x805D86F0: sw          $v1, 0x18($a0)
        MEM_W(0X18, ctx->r4) = ctx->r3;
            goto L_805D8708;
    }
    // 0x805D86F0: sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
    // 0x805D86F4: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x805D86F8: b           L_805D8708
    // 0x805D86FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_805D8708;
    // 0x805D86FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_805D8700:
    // 0x805D8700: sw          $t9, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r25;
    // 0x805D8704: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
L_805D8708:
    // 0x805D8708: sll         $t0, $v1, 3
    ctx->r8 = S32(ctx->r3 << 3);
    // 0x805D870C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805D8710: lw          $t1, -0x6490($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(474, 0X2270));
    // 0x805D8714: jr          $ra
    // 0x805D8718: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
    return;
    // 0x805D8718: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8044B6D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B6D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044B6DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B6E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8044B6E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8044B6E8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8044B6EC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044B6F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8044B6F4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B6F8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044B6FC: swc1        $f4, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f4.u32l;
    // 0x8044B700: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B704: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044B708: sb          $a1, 0x6CEC($at)
    MEM_B(0X6CEC, ctx->r1) = ctx->r5;
    // 0x8044B70C: jal         0x804449C0
    // 0x8044B710: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804449C0(rdram, ctx);
        goto after_0;
    // 0x8044B710: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8044B714: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8044B718: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8044B71C: jal         0x80457164
    // 0x8044B720: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80457164(rdram, ctx);
        goto after_1;
    // 0x8044B720: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x8044B724: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8044B728: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8044B72C: sw          $t6, 0x68($t7)
    MEM_W(0X68, ctx->r15) = ctx->r14;
    // 0x8044B730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044B734: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044B738: jr          $ra
    // 0x8044B73C: nop

    return;
    // 0x8044B73C: nop

;}
RECOMP_FUNC void func_80450384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450384: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80450388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045038C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80450390: jal         0x80444408
    // 0x80450394: addiu       $a1, $zero, 0x40F8
    ctx->r5 = ADD32(0, 0X40F8);
    func_80444408(rdram, ctx);
        goto after_0;
    // 0x80450394: addiu       $a1, $zero, 0x40F8
    ctx->r5 = ADD32(0, 0X40F8);
    after_0:
    // 0x80450398: beq         $v0, $zero, L_804503A4
    if (ctx->r2 == 0) {
        // 0x8045039C: lbu         $t6, 0x1F($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X1F);
            goto L_804503A4;
    }
    // 0x8045039C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804503A0: sb          $t6, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r14;
L_804503A4:
    // 0x804503A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804503A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804503AC: jr          $ra
    // 0x804503B0: nop

    return;
    // 0x804503B0: nop

;}
RECOMP_FUNC void func_804759F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804759F0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804759F4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804759F8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804759FC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475A00: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475A04: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475A08: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80475A0C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475A10: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475A14: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475A18: jr          $ra
    // 0x80475A1C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80475A1C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804CF254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CF258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CF25C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804CF260: jal         0x80045A34
    // 0x804CF264: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804CF264: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x804CF268: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CF26C: bne         $v0, $zero, L_804CF27C
    if (ctx->r2 != 0) {
        // 0x804CF270: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_804CF27C;
    }
    // 0x804CF270: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804CF274: b           L_804CF288
    // 0x804CF278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CF288;
    // 0x804CF278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CF27C:
    // 0x804CF27C: jal         0x804CF240
    // 0x804CF280: nop

    func_804CF240(rdram, ctx);
        goto after_1;
    // 0x804CF280: nop

    after_1:
    // 0x804CF284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804CF288:
    // 0x804CF288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CF28C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CF290: jr          $ra
    // 0x804CF294: nop

    return;
    // 0x804CF294: nop

;}
RECOMP_FUNC void func_8005E620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E620: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8005E624: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005E628: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005E62C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005E630: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005E634: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x8005E638: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005E63C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005E640: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x8005E644: bnel        $v0, $at, L_8005E658
    if (ctx->r2 != ctx->r1) {
        // 0x8005E648: lbu         $t6, 0x165($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X165);
            goto L_8005E658;
    }
    goto skip_0;
    // 0x8005E648: lbu         $t6, 0x165($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X165);
    skip_0:
    // 0x8005E64C: b           L_8005E808
    // 0x8005E650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005E808;
    // 0x8005E650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005E654: lbu         $t6, 0x165($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X165);
L_8005E658:
    // 0x8005E658: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E65C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8005E660: beq         $t6, $at, L_8005E804
    if (ctx->r14 == ctx->r1) {
        // 0x8005E664: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_8005E804;
    }
    // 0x8005E664: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8005E668: lwc1        $f4, 0x9C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x8005E66C: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8005E670: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8005E674: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x8005E678: lwc1        $f6, 0xA0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x8005E67C: lw          $t7, -0x76D4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76D4);
    // 0x8005E680: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8005E684: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x8005E688: lwc1        $f8, 0xA4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8005E68C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8005E690: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x8005E694: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x8005E698: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x8005E69C: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x8005E6A0: jal         0x80058CC0
    // 0x8005E6A4: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    func_80058CC0(rdram, ctx);
        goto after_0;
    // 0x8005E6A4: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8005E6A8: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8005E6AC: sb          $t9, 0x40($s1)
    MEM_B(0X40, ctx->r17) = ctx->r25;
    // 0x8005E6B0: sw          $zero, 0x48($s1)
    MEM_W(0X48, ctx->r17) = 0;
    // 0x8005E6B4: sw          $zero, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = 0;
    // 0x8005E6B8: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8005E6BC: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x8005E6C0: addiu       $t2, $t2, -0x1A68
    ctx->r10 = ADD32(ctx->r10, -0X1A68);
    // 0x8005E6C4: lbu         $t1, 0x30($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X30);
    // 0x8005E6C8: sw          $s0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r16;
    // 0x8005E6CC: sw          $t2, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r10;
    // 0x8005E6D0: sh          $t1, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r9;
    // 0x8005E6D4: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005E6D8: addiu       $s2, $sp, 0x34
    ctx->r18 = ADD32(ctx->r29, 0X34);
    // 0x8005E6DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005E6E0: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8005E6E4: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x8005E6E8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8005E6EC: jal         0x80066468
    // 0x8005E6F0: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    func_80066468(rdram, ctx);
        goto after_1;
    // 0x8005E6F0: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    after_1:
    // 0x8005E6F4: lw          $t3, 0x16C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X16C);
    // 0x8005E6F8: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
    // 0x8005E6FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005E700: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8005E704: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8005E708: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8005E70C: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8005E710: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x8005E714: beq         $t8, $zero, L_8005E72C
    if (ctx->r24 == 0) {
        // 0x8005E718: andi        $t9, $v0, 0x2
        ctx->r25 = ctx->r2 & 0X2;
            goto L_8005E72C;
    }
    // 0x8005E718: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x8005E71C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8005E720: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005E724: b           L_8005E738
    // 0x8005E728: srl         $t0, $t9, 1
    ctx->r8 = S32(U32(ctx->r25) >> 1);
        goto L_8005E738;
    // 0x8005E728: srl         $t0, $t9, 1
    ctx->r8 = S32(U32(ctx->r25) >> 1);
L_8005E72C:
    // 0x8005E72C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005E730: nop

    // 0x8005E734: srl         $t0, $t9, 1
    ctx->r8 = S32(U32(ctx->r25) >> 1);
L_8005E738:
    // 0x8005E738: beq         $t0, $zero, L_8005E750
    if (ctx->r8 == 0) {
        // 0x8005E73C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8005E750;
    }
    // 0x8005E73C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005E740: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8005E744: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005E748: b           L_8005E75C
    // 0x8005E74C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
        goto L_8005E75C;
    // 0x8005E74C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_8005E750:
    // 0x8005E750: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005E754: nop

    // 0x8005E758: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_8005E75C:
    // 0x8005E75C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005E760: jal         0x80080440
    // 0x8005E764: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80080440(rdram, ctx);
        goto after_2;
    // 0x8005E764: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x8005E768: addiu       $v0, $s0, 0x90
    ctx->r2 = ADD32(ctx->r16, 0X90);
    // 0x8005E76C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8005E770: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8005E774: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005E778: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005E77C: jal         0x800662B8
    // 0x8005E780: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800662B8(rdram, ctx);
        goto after_3;
    // 0x8005E780: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_3:
    // 0x8005E784: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005E788: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005E78C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005E790: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005E794: jal         0x800662B8
    // 0x8005E798: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    func_800662B8(rdram, ctx);
        goto after_4;
    // 0x8005E798: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    after_4:
    // 0x8005E79C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8005E7A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005E7A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005E7A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005E7AC: jal         0x800662B8
    // 0x8005E7B0: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    func_800662B8(rdram, ctx);
        goto after_5;
    // 0x8005E7B0: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    after_5:
    // 0x8005E7B4: addiu       $v0, $s0, 0x54
    ctx->r2 = ADD32(ctx->r16, 0X54);
    // 0x8005E7B8: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8005E7BC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8005E7C0: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8005E7C4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8005E7C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005E7CC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8005E7D0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8005E7D4: jal         0x80080C84
    // 0x8005E7D8: nop

    func_80080C84(rdram, ctx);
        goto after_6;
    // 0x8005E7D8: nop

    after_6:
    // 0x8005E7DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005E7E0: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    // 0x8005E7E4: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x8005E7E8: jal         0x80080824
    // 0x8005E7EC: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
    func_80080824(rdram, ctx);
        goto after_7;
    // 0x8005E7EC: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
    after_7:
    // 0x8005E7F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005E7F4: jal         0x800817A0
    // 0x8005E7F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    MtxConv_F2L(rdram, ctx);
        goto after_8;
    // 0x8005E7F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x8005E7FC: b           L_8005E808
    // 0x8005E800: addiu       $v0, $s1, 0x40
    ctx->r2 = ADD32(ctx->r17, 0X40);
        goto L_8005E808;
    // 0x8005E800: addiu       $v0, $s1, 0x40
    ctx->r2 = ADD32(ctx->r17, 0X40);
L_8005E804:
    // 0x8005E804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005E808:
    // 0x8005E808: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005E80C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005E810: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E814: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005E818: jr          $ra
    // 0x8005E81C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8005E81C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80462014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462014: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80462018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046201C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80462020: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80462024: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A48) << 16);
    // 0x80462028: lwc1        $f6, 0x3FD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A48));
    // 0x8046202C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80462030: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A4C) << 16);
    // 0x80462034: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80462038: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8046203C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80462040: lwc1        $f10, 0x3FDC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A4C));
    // 0x80462044: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80462048: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A54) << 16);
    // 0x8046204C: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x80462050: nop

    // 0x80462054: bc1f        L_80462074
    if (!c1cs) {
        // 0x80462058: nop
    
            goto L_80462074;
    }
    // 0x80462058: nop

    // 0x8046205C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A50) << 16);
    // 0x80462060: lwc1        $f16, 0x3FE0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A50));
    // 0x80462064: sub.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80462068: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x8046206C: b           L_8046209C
    // 0x80462070: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
        goto L_8046209C;
    // 0x80462070: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
L_80462074:
    // 0x80462074: lwc1        $f4, 0x3FE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A54));
    // 0x80462078: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A58) << 16);
    // 0x8046207C: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80462080: nop

    // 0x80462084: bc1f        L_8046209C
    if (!c1cs) {
        // 0x80462088: nop
    
            goto L_8046209C;
    }
    // 0x80462088: nop

    // 0x8046208C: lwc1        $f6, 0x3FE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A58));
    // 0x80462090: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80462094: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80462098: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
L_8046209C:
    // 0x8046209C: jal         0x80082730
    // 0x804620A0: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    fsin(rdram, ctx);
        goto after_0;
    // 0x804620A0: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_0:
    // 0x804620A4: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x804620A8: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x804620AC: jal         0x80082730
    // 0x804620B0: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    fsin(rdram, ctx);
        goto after_1;
    // 0x804620B0: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x804620B4: lui         $at, 0x439B
    ctx->r1 = S32(0X439B << 16);
    // 0x804620B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804620BC: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x804620C0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804620C4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x804620C8: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x804620CC: jal         0x8008D250
    // 0x804620D0: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    fcos(rdram, ctx);
        goto after_2;
    // 0x804620D0: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x804620D4: lui         $at, 0x439B
    ctx->r1 = S32(0X439B << 16);
    // 0x804620D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804620DC: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x804620E0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x804620E4: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x804620E8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804620EC: addiu       $a0, $a1, 0xC4
    ctx->r4 = ADD32(ctx->r5, 0XC4);
    // 0x804620F0: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x804620F4: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x804620F8: lwc1        $f6, 0x3C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x804620FC: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80462100: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80462104: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80462108: lwc1        $f18, 0x40($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X40);
    // 0x8046210C: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80462110: jal         0x80461FB4
    // 0x80462114: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    func_80461FB4(rdram, ctx);
        goto after_3;
    // 0x80462114: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    after_3:
    // 0x80462118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8046211C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80462120: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80462124: jr          $ra
    // 0x80462128: nop

    return;
    // 0x80462128: nop

;}
RECOMP_FUNC void func_8005DC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DC34: lw          $t6, 0x38($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X38);
    // 0x8005DC38: beql        $t6, $zero, L_8005DC68
    if (ctx->r14 == 0) {
        // 0x8005DC3C: lw          $t4, 0x30($a1)
        ctx->r12 = MEM_W(ctx->r5, 0X30);
            goto L_8005DC68;
    }
    goto skip_0;
    // 0x8005DC3C: lw          $t4, 0x30($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X30);
    skip_0:
    // 0x8005DC40: lbu         $t7, 0x34($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X34);
    // 0x8005DC44: lw          $t1, 0x30($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X30);
    // 0x8005DC48: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005DC4C: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x8005DC50: lw          $t0, 0x38($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X38);
    // 0x8005DC54: sw          $t0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r8;
    // 0x8005DC58: lbu         $t2, 0x34($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X34);
    // 0x8005DC5C: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x8005DC60: sb          $t3, 0x34($a1)
    MEM_B(0X34, ctx->r5) = ctx->r11;
    // 0x8005DC64: lw          $t4, 0x30($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X30);
L_8005DC68:
    // 0x8005DC68: jr          $ra
    // 0x8005DC6C: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    return;
    // 0x8005DC6C: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
;}
RECOMP_FUNC void func_8041DB1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041DB1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8041DB20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041DB24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8041DB28: lh          $t6, 0x1F0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1F0);
    // 0x8041DB2C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8041DB30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041DB34: bnel        $t6, $at, L_8041DB60
    if (ctx->r14 != ctx->r1) {
        // 0x8041DB38: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_8041DB60;
    }
    goto skip_0;
    // 0x8041DB38: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x8041DB3C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x8041DB40: jal         0x80067BBC
    // 0x8041DB44: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8041DB44: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x8041DB48: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x8041DB4C: jal         0x80067F78
    // 0x8041DB50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8041DB50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8041DB54: b           L_8041DB78
    // 0x8041DB58: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_8041DB78;
    // 0x8041DB58: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8041DB5C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_8041DB60:
    // 0x8041DB60: jal         0x80067BBC
    // 0x8041DB64: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8041DB64: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x8041DB68: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x8041DB6C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8041DB70: jal         0x800678F0
    // 0x8041DB74: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x8041DB74: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_8041DB78:
    // 0x8041DB78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8041DB7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041DB80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8041DB84: jr          $ra
    // 0x8041DB88: nop

    return;
    // 0x8041DB88: nop

;}
RECOMP_FUNC void func_80711A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80711A5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80711A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80711A64: jal         0x807119DC
    // 0x80711A68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807119DC(rdram, ctx);
        goto after_0;
    // 0x80711A68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80711A6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80711A70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80711A74: jal         0x80711A8C
    // 0x80711A78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80711A8C(rdram, ctx);
        goto after_1;
    // 0x80711A78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80711A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80711A80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80711A84: jr          $ra
    // 0x80711A88: nop

    return;
    // 0x80711A88: nop

;}
RECOMP_FUNC void func_805AB4D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB4D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805AB4DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AB4E0: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AB4E4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805AB4E8: lbu         $t6, 0x26D($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X26D);
    // 0x805AB4EC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x805AB4F0: bnel        $t6, $zero, L_805AB62C
    if (ctx->r14 != 0) {
        // 0x805AB4F4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_805AB62C;
    }
    goto skip_0;
    // 0x805AB4F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
    // 0x805AB4F8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x805AB4FC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x805AB500: jal         0x805AB0C0
    // 0x805AB504: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_805AB0C0(rdram, ctx);
        goto after_0;
    // 0x805AB504: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x805AB508: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x805AB50C: beq         $v0, $zero, L_805AB644
    if (ctx->r2 == 0) {
        // 0x805AB510: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_805AB644;
    }
    // 0x805AB510: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805AB514: lbu         $v0, 0x26C($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X26C);
    // 0x805AB518: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(435, 0XAB8) << 16);
    // 0x805AB51C: lui         $t7, 0x805B
    ctx->r15 = S32(RELOC_HI16(435, 0XAD0) << 16);
    // 0x805AB520: beq         $v0, $zero, L_805AB5A0
    if (ctx->r2 == 0) {
        // 0x805AB524: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_805AB5A0;
    }
    // 0x805AB524: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x805AB528: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x805AB52C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x805AB530: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x805AB534: lwc1        $f4, -0x4608($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0XAB8));
    // 0x805AB538: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(435, 0XAC4) << 16);
    // 0x805AB53C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x805AB540: swc1        $f4, 0x274($a2)
    MEM_W(0X274, ctx->r6) = ctx->f4.u32l;
    // 0x805AB544: lwc1        $f6, -0x45FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0XAC4));
    // 0x805AB548: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x805AB54C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805AB550: swc1        $f6, 0x270($a2)
    MEM_W(0X270, ctx->r6) = ctx->f6.u32l;
    // 0x805AB554: lbu         $t7, -0x45F0($t7)
    ctx->r15 = MEM_BU(ctx->r15, (int16_t)RELOC_LO16(435, 0XAD0));
    // 0x805AB558: sb          $v0, 0x26C($a2)
    MEM_B(0X26C, ctx->r6) = ctx->r2;
    // 0x805AB55C: bne         $v0, $at, L_805AB644
    if (ctx->r2 != ctx->r1) {
        // 0x805AB560: sb          $t7, 0x26D($a2)
        MEM_B(0X26D, ctx->r6) = ctx->r15;
            goto L_805AB644;
    }
    // 0x805AB560: sb          $t7, 0x26D($a2)
    MEM_B(0X26D, ctx->r6) = ctx->r15;
    // 0x805AB564: lbu         $v0, 0x30($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X30);
    // 0x805AB568: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805AB56C: bnel        $v0, $at, L_805AB588
    if (ctx->r2 != ctx->r1) {
        // 0x805AB570: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_805AB588;
    }
    goto skip_1;
    // 0x805AB570: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_1:
    // 0x805AB574: jal         0x805AB1B0
    // 0x805AB578: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_805AB1B0(rdram, ctx);
        goto after_1;
    // 0x805AB578: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x805AB57C: b           L_805AB648
    // 0x805AB580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805AB648;
    // 0x805AB580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AB584: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_805AB588:
    // 0x805AB588: bne         $v0, $at, L_805AB644
    if (ctx->r2 != ctx->r1) {
        // 0x805AB58C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_805AB644;
    }
    // 0x805AB58C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805AB590: jal         0x805AB3F4
    // 0x805AB594: lw          $a1, 0x264($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X264);
    func_805AB3F4(rdram, ctx);
        goto after_2;
    // 0x805AB594: lw          $a1, 0x264($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X264);
    after_2:
    // 0x805AB598: b           L_805AB648
    // 0x805AB59C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805AB648;
    // 0x805AB59C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AB5A0:
    // 0x805AB5A0: lbu         $v0, 0x30($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X30);
    // 0x805AB5A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805AB5A8: bnel        $v0, $at, L_805AB60C
    if (ctx->r2 != ctx->r1) {
        // 0x805AB5AC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_805AB60C;
    }
    goto skip_2;
    // 0x805AB5AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_2:
    // 0x805AB5B0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x805AB5B4: jal         0x8004700C
    // 0x805AB5B8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8004700C(rdram, ctx);
        goto after_3;
    // 0x805AB5B8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x805AB5BC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x805AB5C0: beq         $v0, $zero, L_805AB644
    if (ctx->r2 == 0) {
        // 0x805AB5C4: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_805AB644;
    }
    // 0x805AB5C4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805AB5C8: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x805AB5CC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805AB5D0: lbu         $t8, 0x1B4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1B4);
    // 0x805AB5D4: bnel        $t8, $zero, L_805AB648
    if (ctx->r24 != 0) {
        // 0x805AB5D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805AB648;
    }
    goto skip_3;
    // 0x805AB5D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x805AB5DC: sb          $t9, 0x1B4($v1)
    MEM_B(0X1B4, ctx->r3) = ctx->r25;
    // 0x805AB5E0: lw          $t0, 0x260($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X260);
    // 0x805AB5E4: lbu         $a0, 0x15($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X15);
    // 0x805AB5E8: jal         0x80062DD4
    // 0x805AB5EC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80062DD4(rdram, ctx);
        goto after_4;
    // 0x805AB5EC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_4:
    // 0x805AB5F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805AB5F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AB5F8: jal         0x805AB914
    // 0x805AB5FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_805AB914(rdram, ctx);
        goto after_5;
    // 0x805AB5FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x805AB600: b           L_805AB648
    // 0x805AB604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805AB648;
    // 0x805AB604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AB608: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_805AB60C:
    // 0x805AB60C: bne         $v0, $at, L_805AB644
    if (ctx->r2 != ctx->r1) {
        // 0x805AB610: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_805AB644;
    }
    // 0x805AB610: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805AB614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AB618: jal         0x805AB914
    // 0x805AB61C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_805AB914(rdram, ctx);
        goto after_6;
    // 0x805AB61C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x805AB620: b           L_805AB648
    // 0x805AB624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805AB648;
    // 0x805AB624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AB628: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_805AB62C:
    // 0x805AB62C: jal         0x805AB178
    // 0x805AB630: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_805AB178(rdram, ctx);
        goto after_7;
    // 0x805AB630: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_7:
    // 0x805AB634: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x805AB638: lbu         $t1, 0x26D($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X26D);
    // 0x805AB63C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x805AB640: sb          $t2, 0x26D($a2)
    MEM_B(0X26D, ctx->r6) = ctx->r10;
L_805AB644:
    // 0x805AB644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AB648:
    // 0x805AB648: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805AB64C: jr          $ra
    // 0x805AB650: nop

    return;
    // 0x805AB650: nop

;}
RECOMP_FUNC void func_8002F8AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F8AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002F8B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F8B4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002F8B8: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F8BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002F8C0: jal         0x8002F678
    // 0x8002F8C4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002F8C4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002F8C8: beq         $v0, $zero, L_8002F8DC
    if (ctx->r2 == 0) {
        // 0x8002F8CC: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002F8DC;
    }
    // 0x8002F8CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F8D0: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002F8D4: addiu       $t6, $t6, -0x34B0
    ctx->r14 = ADD32(ctx->r14, -0X34B0);
    // 0x8002F8D8: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002F8DC:
    // 0x8002F8DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F8E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002F8E4: jr          $ra
    // 0x8002F8E8: nop

    return;
    // 0x8002F8E8: nop

;}
RECOMP_FUNC void func_80072534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007253C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80072540: addiu       $t6, $t6, -0x4D98
    ctx->r14 = ADD32(ctx->r14, -0X4D98);
    // 0x80072544: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80072548: lw          $t8, 0x58($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X58);
    // 0x8007254C: lw          $t9, 0x5C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X5C);
    // 0x80072550: bne         $t8, $zero, L_80072560
    if (ctx->r24 != 0) {
        // 0x80072554: nop
    
            goto L_80072560;
    }
    // 0x80072554: nop

    // 0x80072558: beql        $t9, $zero, L_800725A0
    if (ctx->r25 == 0) {
        // 0x8007255C: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_800725A0;
    }
    goto skip_0;
    // 0x8007255C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
L_80072560:
    // 0x80072560: jal         0x8008B920
    // 0x80072564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x80072564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80072568: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007256C: sw          $v0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r2;
    // 0x80072570: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
    // 0x80072574: lw          $t0, 0x60($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X60);
    // 0x80072578: lw          $t1, 0x64($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X64);
    // 0x8007257C: lw          $t2, 0x58($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X58);
    // 0x80072580: lw          $t3, 0x5C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X5C);
    // 0x80072584: subu        $t4, $t0, $t2
    ctx->r12 = SUB32(ctx->r8, ctx->r10);
    // 0x80072588: sltu        $at, $t1, $t3
    ctx->r1 = ctx->r9 < ctx->r11 ? 1 : 0;
    // 0x8007258C: subu        $t4, $t4, $at
    ctx->r12 = SUB32(ctx->r12, ctx->r1);
    // 0x80072590: sw          $t4, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r12;
    // 0x80072594: subu        $t5, $t1, $t3
    ctx->r13 = SUB32(ctx->r9, ctx->r11);
    // 0x80072598: sw          $t5, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r13;
    // 0x8007259C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800725A0:
    // 0x800725A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800725A4: beq         $v0, $at, L_800725EC
    if (ctx->r2 == ctx->r1) {
        // 0x800725A8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800725EC;
    }
    // 0x800725A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800725AC: bne         $v0, $at, L_80072644
    if (ctx->r2 != ctx->r1) {
        // 0x800725B0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80072644;
    }
    // 0x800725B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800725B4: addiu       $v0, $v0, -0x25F0
    ctx->r2 = ADD32(ctx->r2, -0X25F0);
    // 0x800725B8: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x800725BC: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x800725C0: lw          $t8, 0x68($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X68);
    // 0x800725C4: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
    // 0x800725C8: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x800725CC: sltu        $at, $t1, $t9
    ctx->r1 = ctx->r9 < ctx->r25 ? 1 : 0;
    // 0x800725D0: addu        $t0, $at, $t6
    ctx->r8 = ADD32(ctx->r1, ctx->r14);
    // 0x800725D4: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800725D8: sw          $t0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r8;
    // 0x800725DC: jal         0x80072470
    // 0x800725E0: sw          $t1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r9;
    func_80072470(rdram, ctx);
        goto after_1;
    // 0x800725E0: sw          $t1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r9;
    after_1:
    // 0x800725E4: b           L_80072644
    // 0x800725E8: nop

        goto L_80072644;
    // 0x800725E8: nop

L_800725EC:
    // 0x800725EC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800725F0: addiu       $v0, $v0, -0x25F0
    ctx->r2 = ADD32(ctx->r2, -0X25F0);
    // 0x800725F4: lw          $t2, 0x38($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X38);
    // 0x800725F8: lw          $t3, 0x3C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X3C);
    // 0x800725FC: lw          $t4, 0x68($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X68);
    // 0x80072600: lw          $t5, 0x6C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X6C);
    // 0x80072604: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80072608: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x8007260C: sltu        $at, $t7, $t5
    ctx->r1 = ctx->r15 < ctx->r13 ? 1 : 0;
    // 0x80072610: addu        $t6, $at, $t2
    ctx->r14 = ADD32(ctx->r1, ctx->r10);
    // 0x80072614: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x80072618: sw          $t6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r14;
    // 0x8007261C: jal         0x8008B780
    // 0x80072620: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    osSpTaskYielded_recomp(rdram, ctx);
        goto after_2;
    // 0x80072620: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    after_2:
    // 0x80072624: bne         $v0, $zero, L_8007263C
    if (ctx->r2 != 0) {
        // 0x80072628: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8007263C;
    }
    // 0x80072628: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007262C: jal         0x800724CC
    // 0x80072630: nop

    func_800724CC(rdram, ctx);
        goto after_3;
    // 0x80072630: nop

    after_3:
    // 0x80072634: b           L_80072644
    // 0x80072638: nop

        goto L_80072644;
    // 0x80072638: nop

L_8007263C:
    // 0x8007263C: jal         0x80072500
    // 0x80072640: nop

    func_80072500(rdram, ctx);
        goto after_4;
    // 0x80072640: nop

    after_4:
L_80072644:
    // 0x80072644: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072648: addiu       $a0, $a0, -0x2770
    ctx->r4 = ADD32(ctx->r4, -0X2770);
    // 0x8007264C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80072650: jal         0x80082210
    // 0x80072654: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80072654: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80072658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007265C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072660: jr          $ra
    // 0x80072664: nop

    return;
    // 0x80072664: nop

;}
RECOMP_FUNC void func_80557BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80557BA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80557BA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80557BA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80557BAC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80557BB0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80557BB4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80557BB8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80557BBC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80557BC0: jal         0x80062AEC
    // 0x80557BC4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x80557BC4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80557BC8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80557BCC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80557BD0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80557BD4: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x80557BD8: bnel        $t7, $zero, L_80557D34
    if (ctx->r15 != 0) {
        // 0x80557BDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80557D34;
    }
    goto skip_0;
    // 0x80557BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80557BE0: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    // 0x80557BE4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80557BE8: bne         $a0, $at, L_80557C74
    if (ctx->r4 != ctx->r1) {
        // 0x80557BEC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80557C74;
    }
    // 0x80557BEC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80557BF0: beql        $v0, $at, L_80557D34
    if (ctx->r2 == ctx->r1) {
        // 0x80557BF4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80557D34;
    }
    goto skip_1;
    // 0x80557BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80557BF8: lbu         $t8, 0x30($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X30);
    // 0x80557BFC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80557C00: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80557C04: bne         $t8, $at, L_80557C1C
    if (ctx->r24 != ctx->r1) {
        // 0x80557C08: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80557C1C;
    }
    // 0x80557C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80557C0C: lbu         $t9, 0x18($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X18);
    // 0x80557C10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80557C14: beql        $t9, $at, L_80557C34
    if (ctx->r25 == ctx->r1) {
        // 0x80557C18: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80557C34;
    }
    goto skip_2;
    // 0x80557C18: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    skip_2:
L_80557C1C:
    // 0x80557C1C: jal         0x80559928
    // 0x80557C20: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80559928(rdram, ctx);
        goto after_1;
    // 0x80557C20: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80557C24: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80557C28: jal         0x80557B60
    // 0x80557C2C: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    func_80557B60(rdram, ctx);
        goto after_2;
    // 0x80557C2C: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    after_2:
    // 0x80557C30: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_80557C34:
    // 0x80557C34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80557C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80557C3C: beq         $t0, $at, L_80557C54
    if (ctx->r8 == ctx->r1) {
        // 0x80557C40: lui         $a2, 0xC020
        ctx->r6 = S32(0XC020 << 16);
            goto L_80557C54;
    }
    // 0x80557C40: lui         $a2, 0xC020
    ctx->r6 = S32(0XC020 << 16);
    // 0x80557C44: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80557C48: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80557C4C: b           L_80557C64
    // 0x80557C50: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
        goto L_80557C64;
    // 0x80557C50: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80557C54:
    // 0x80557C54: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80557C58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80557C5C: nop

    // 0x80557C60: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80557C64:
    // 0x80557C64: jal         0x8002F96C
    // 0x80557C68: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8002F96C(rdram, ctx);
        goto after_3;
    // 0x80557C68: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_3:
    // 0x80557C6C: b           L_80557D34
    // 0x80557C70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80557D34;
    // 0x80557C70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80557C74:
    // 0x80557C74: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80557C78: bne         $a0, $at, L_80557D30
    if (ctx->r4 != ctx->r1) {
        // 0x80557C7C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80557D30;
    }
    // 0x80557C7C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80557C80: sw          $t1, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r9;
    // 0x80557C84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80557C88: beq         $v0, $at, L_80557CC8
    if (ctx->r2 == ctx->r1) {
        // 0x80557C8C: lwc1        $f0, 0xC4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
            goto L_80557CC8;
    }
    // 0x80557C8C: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80557C90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80557C94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80557C98: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80557C9C: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80557CA0: nop

    // 0x80557CA4: bc1fl       L_80557CC0
    if (!c1cs) {
        // 0x80557CA8: sw          $v0, 0x12C($s0)
        MEM_W(0X12C, ctx->r16) = ctx->r2;
            goto L_80557CC0;
    }
    goto skip_3;
    // 0x80557CA8: sw          $v0, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r2;
    skip_3:
    // 0x80557CAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80557CB0: nop

    // 0x80557CB4: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80557CB8: nop

    // 0x80557CBC: sw          $v0, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r2;
L_80557CC0:
    // 0x80557CC0: b           L_80557CFC
    // 0x80557CC4: sw          $v0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r2;
        goto L_80557CFC;
    // 0x80557CC4: sw          $v0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r2;
L_80557CC8:
    // 0x80557CC8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80557CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80557CD0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80557CD4: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80557CD8: nop

    // 0x80557CDC: bc1fl       L_80557CF8
    if (!c1cs) {
        // 0x80557CE0: sw          $v0, 0x12C($s0)
        MEM_W(0X12C, ctx->r16) = ctx->r2;
            goto L_80557CF8;
    }
    goto skip_4;
    // 0x80557CE0: sw          $v0, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r2;
    skip_4:
    // 0x80557CE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80557CE8: nop

    // 0x80557CEC: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80557CF0: nop

    // 0x80557CF4: sw          $v0, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r2;
L_80557CF8:
    // 0x80557CF8: sw          $v0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r2;
L_80557CFC:
    // 0x80557CFC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80557D00: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x80557D04: jal         0x80557B60
    // 0x80557D08: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80557B60(rdram, ctx);
        goto after_4;
    // 0x80557D08: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80557D0C: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x80557D10: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80557D14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80557D18: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80557D1C: sb          $v0, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r2;
    // 0x80557D20: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x80557D24: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80557D28: jal         0x80559928
    // 0x80557D2C: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    func_80559928(rdram, ctx);
        goto after_5;
    // 0x80557D2C: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    after_5:
L_80557D30:
    // 0x80557D30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80557D34:
    // 0x80557D34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80557D38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80557D3C: jr          $ra
    // 0x80557D40: nop

    return;
    // 0x80557D40: nop

;}
RECOMP_FUNC void func_805CAE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CAE74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805CAE78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805CAE7C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x805CAE80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805CAE84: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x805CAE88: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805CAE8C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805CAE90: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x805CAE94: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(453, 0X93C) << 16);
    // 0x805CAE98: lwc1        $f6, -0x4E74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(453, 0X93C));
    // 0x805CAE9C: lwc1        $f4, 0x8C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8C);
    // 0x805CAEA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805CAEA4: lui         $a1, 0x4016
    ctx->r5 = S32(0X4016 << 16);
    // 0x805CAEA8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805CAEAC: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(453, 0XB00) << 16);
    // 0x805CAEB0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805CAEB4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x805CAEB8: addiu       $a0, $a0, -0x4CB0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(453, 0XB00));
    // 0x805CAEBC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x805CAEC0: jal         0x80046804
    // 0x805CAEC4: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x805CAEC4: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    after_0:
    // 0x805CAEC8: bne         $v0, $zero, L_805CAED8
    if (ctx->r2 != 0) {
        // 0x805CAECC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_805CAED8;
    }
    // 0x805CAECC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805CAED0: b           L_805CAF2C
    // 0x805CAED4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805CAF2C;
    // 0x805CAED4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805CAED8:
    // 0x805CAED8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x805CAEDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805CAEE0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x805CAEE4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x805CAEE8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x805CAEEC: jal         0x805CADA4
    // 0x805CAEF0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_805CADA4(rdram, ctx);
        goto after_1;
    // 0x805CAEF0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_1:
    // 0x805CAEF4: bne         $v0, $zero, L_805CAF04
    if (ctx->r2 != 0) {
        // 0x805CAEF8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_805CAF04;
    }
    // 0x805CAEF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805CAEFC: b           L_805CAF2C
    // 0x805CAF00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805CAF2C;
    // 0x805CAF00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805CAF04:
    // 0x805CAF04: jal         0x80047F9C
    // 0x805CAF08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x805CAF08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x805CAF0C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805CAF10: sb          $t8, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r24;
    // 0x805CAF14: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x805CAF18: jal         0x805CACCC
    // 0x805CAF1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805CACCC(rdram, ctx);
        goto after_3;
    // 0x805CAF1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805CAF20: jal         0x805CA904
    // 0x805CAF24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805CA904(rdram, ctx);
        goto after_4;
    // 0x805CAF24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805CAF28: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_805CAF2C:
    // 0x805CAF2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805CAF30: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805CAF34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805CAF38: jr          $ra
    // 0x805CAF3C: nop

    return;
    // 0x805CAF3C: nop

;}
RECOMP_FUNC void func_8044E90C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044E90C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8044E910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044E914: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044E918: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x8044E91C: slti        $at, $a1, 0x8E
    ctx->r1 = SIGNED(ctx->r5) < 0X8E ? 1 : 0;
    // 0x8044E920: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8044E924: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8044E928: bne         $at, $zero, L_8044E934
    if (ctx->r1 != 0) {
        // 0x8044E92C: lw          $a3, 0x6A94($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X6A94);
            goto L_8044E934;
    }
    // 0x8044E92C: lw          $a3, 0x6A94($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6A94);
    // 0x8044E930: addiu       $a2, $zero, 0x8D
    ctx->r6 = ADD32(0, 0X8D);
L_8044E934:
    // 0x8044E934: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8044E938: jal         0x8044BFA8
    // 0x8044E93C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_8044BFA8(rdram, ctx);
        goto after_0;
    // 0x8044E93C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x8044E940: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8044E944: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8044E948: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8044E94C: jal         0x8006C56C
    // 0x8044E950: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_8006C56C(rdram, ctx);
        goto after_1;
    // 0x8044E950: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8044E954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044E958: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8044E95C: jr          $ra
    // 0x8044E960: nop

    return;
    // 0x8044E960: nop

;}
RECOMP_FUNC void func_80034B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034B28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034B30: jal         0x80021958
    // 0x80034B34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80034B34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80034B38: bne         $v0, $zero, L_80034B48
    if (ctx->r2 != 0) {
        // 0x80034B3C: nop
    
            goto L_80034B48;
    }
    // 0x80034B3C: nop

    // 0x80034B40: b           L_80034B64
    // 0x80034B44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034B64;
    // 0x80034B44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80034B48:
    // 0x80034B48: jal         0x800343C0
    // 0x80034B4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800343C0(rdram, ctx);
        goto after_1;
    // 0x80034B4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80034B50: bnel        $v0, $zero, L_80034B64
    if (ctx->r2 != 0) {
        // 0x80034B54: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80034B64;
    }
    goto skip_0;
    // 0x80034B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80034B58: b           L_80034B64
    // 0x80034B5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034B64;
    // 0x80034B5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80034B60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80034B64:
    // 0x80034B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034B68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034B6C: jr          $ra
    // 0x80034B70: nop

    return;
    // 0x80034B70: nop

;}
RECOMP_FUNC void func_8077DE4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077DE4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8077DE50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8077DE54: jal         0x8077DE28
    // 0x8077DE58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8077DE28(rdram, ctx);
        goto after_0;
    // 0x8077DE58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8077DE5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8077DE60: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8077DE64: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8077DE68: bne         $t7, $zero, L_8077DE78
    if (ctx->r15 != 0) {
        // 0x8077DE6C: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_8077DE78;
    }
    // 0x8077DE6C: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8077DE70: jal         0x800447C8
    // 0x8077DE74: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8077DE74: nop

    after_1:
L_8077DE78:
    // 0x8077DE78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8077DE7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8077DE80: jr          $ra
    // 0x8077DE84: nop

    return;
    // 0x8077DE84: nop

;}
RECOMP_FUNC void func_8070CB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070CB48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8070CB4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8070CB50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8070CB54: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070CB58: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8070CB5C: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8070CB60: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8070CB64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8070CB68: jal         0x80065ABC
    // 0x8070CB6C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x8070CB6C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8070CB70: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8070CB74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8070CB78: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8070CB7C: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8070CB80: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD50) << 16);
    // 0x8070CB84: lwc1        $f6, -0x2C20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD50));
    // 0x8070CB88: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8070CB8C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8070CB90: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8070CB94: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8070CB98: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8070CB9C: nop

    // 0x8070CBA0: bc1fl       L_8070CBB4
    if (!c1cs) {
        // 0x8070CBA4: lwc1        $f10, 0x50($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
            goto L_8070CBB4;
    }
    goto skip_0;
    // 0x8070CBA4: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    skip_0:
    // 0x8070CBA8: swc1        $f12, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f12.u32l;
    // 0x8070CBAC: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8070CBB0: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
L_8070CBB4:
    // 0x8070CBB4: jal         0x800659EC
    // 0x8070CBB8: add.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f2.fl;
    func_800659EC(rdram, ctx);
        goto after_1;
    // 0x8070CBB8: add.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f2.fl;
    after_1:
    // 0x8070CBBC: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8070CBC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070CBC4: jal         0x80049D74
    // 0x8070CBC8: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_2;
    // 0x8070CBC8: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_2:
    // 0x8070CBCC: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x8070CBD0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8070CBD4: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8070CBD8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8070CBDC: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8070CBE0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8070CBE4: andi        $t0, $t9, 0xF8
    ctx->r8 = ctx->r25 & 0XF8;
    // 0x8070CBE8: bnel        $t0, $at, L_8070CC58
    if (ctx->r8 != ctx->r1) {
        // 0x8070CBEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8070CC58;
    }
    goto skip_1;
    // 0x8070CBEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8070CBF0: lw          $t1, -0x76F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76F8);
    // 0x8070CBF4: lui         $a1, 0x8071
    ctx->r5 = S32(RELOC_HI16(721, 0XCB8) << 16);
    // 0x8070CBF8: addiu       $a1, $a1, -0x2CB8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(721, 0XCB8));
    // 0x8070CBFC: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x8070CC00: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8070CC04: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8070CC08: lw          $t9, 0x4C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4C);
    // 0x8070CC0C: jalr        $t9
    // 0x8070CC10: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8070CC10: nop

    after_3:
    // 0x8070CC14: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD54) << 16);
    // 0x8070CC18: lwc1        $f18, -0x2C1C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD54));
    // 0x8070CC1C: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8070CC20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070CC24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070CC28: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8070CC2C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8070CC30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8070CC34: jal         0x8070D208
    // 0x8070CC38: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    func_8070D208(rdram, ctx);
        goto after_4;
    // 0x8070CC38: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x8070CC3C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8070CC40: jal         0x80067BBC
    // 0x8070CC44: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x8070CC44: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x8070CC48: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x8070CC4C: jal         0x80067818
    // 0x8070CC50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8070CC50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8070CC54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8070CC58:
    // 0x8070CC58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8070CC5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8070CC60: jr          $ra
    // 0x8070CC64: nop

    return;
    // 0x8070CC64: nop

;}
RECOMP_FUNC void func_80787598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80787598: addiu       $sp, $sp, -0x690
    ctx->r29 = ADD32(ctx->r29, -0X690);
    // 0x8078759C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x807875A0: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x807875A4: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x807875A8: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x807875AC: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x807875B0: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x807875B4: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x807875B8: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x807875BC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x807875C0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x807875C4: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x807875C8: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x807875CC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x807875D0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x807875D4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x807875D8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x807875DC: lw          $s7, 0x1F4($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X1F4);
    // 0x807875E0: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x807875E4: lui         $a1, 0x8079
    ctx->r5 = S32(RELOC_HI16(787, 0X3264) << 16);
    // 0x807875E8: lw          $v0, 0x43E4($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X43E4);
    // 0x807875EC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x807875F0: addiu       $fp, $zero, 0x8
    ctx->r30 = ADD32(0, 0X8);
    // 0x807875F4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x807875F8: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x807875FC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80787600: sllv        $t8, $t7, $v0
    ctx->r24 = S32(ctx->r15 << (ctx->r2 & 31));
    // 0x80787604: sb          $t8, 0x67B($sp)
    MEM_B(0X67B, ctx->r29) = ctx->r24;
    // 0x80787608: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8078760C: lh          $v1, 0x52C2($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X52C2);
    // 0x80787610: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80787614: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80787618: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8078761C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80787620: addiu       $t9, $v1, -0x50
    ctx->r25 = ADD32(ctx->r3, -0X50);
    // 0x80787624: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80787628: slti        $at, $t9, 0xBF
    ctx->r1 = SIGNED(ctx->r25) < 0XBF ? 1 : 0;
    // 0x8078762C: bne         $at, $zero, L_80787664
    if (ctx->r1 != 0) {
        // 0x80787630: addu        $s6, $s7, $t6
        ctx->r22 = ADD32(ctx->r23, ctx->r14);
            goto L_80787664;
    }
    // 0x80787630: addu        $s6, $s7, $t6
    ctx->r22 = ADD32(ctx->r23, ctx->r14);
    // 0x80787634: lh          $t2, 0x52C4($s7)
    ctx->r10 = MEM_H(ctx->r23, 0X52C4);
    // 0x80787638: lui         $t0, 0x8079
    ctx->r8 = S32(RELOC_HI16(787, 0X3264) << 16);
    // 0x8078763C: lw          $t0, -0x635C($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(787, 0X3264));
    // 0x80787640: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80787644: sh          $t3, 0x52C4($s7)
    MEM_H(0X52C4, ctx->r23) = ctx->r11;
    // 0x80787648: lh          $t4, 0x52C4($s7)
    ctx->r12 = MEM_H(ctx->r23, 0X52C4);
    // 0x8078764C: subu        $t1, $v1, $t0
    ctx->r9 = SUB32(ctx->r3, ctx->r8);
    // 0x80787650: sh          $t1, 0x52C2($s7)
    MEM_H(0X52C2, ctx->r23) = ctx->r9;
    // 0x80787654: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x80787658: bnel        $at, $zero, L_80787668
    if (ctx->r1 != 0) {
        // 0x8078765C: lh          $t5, 0x52C2($s7)
        ctx->r13 = MEM_H(ctx->r23, 0X52C2);
            goto L_80787668;
    }
    goto skip_0;
    // 0x8078765C: lh          $t5, 0x52C2($s7)
    ctx->r13 = MEM_H(ctx->r23, 0X52C2);
    skip_0:
    // 0x80787660: sh          $zero, 0x52C4($s7)
    MEM_H(0X52C4, ctx->r23) = 0;
L_80787664:
    // 0x80787664: lh          $t5, 0x52C2($s7)
    ctx->r13 = MEM_H(ctx->r23, 0X52C2);
L_80787668:
    // 0x80787668: addiu       $s3, $sp, 0x660
    ctx->r19 = ADD32(ctx->r29, 0X660);
    // 0x8078766C: lw          $a1, -0x635C($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(787, 0X3264));
    // 0x80787670: sw          $t5, 0x65C($sp)
    MEM_W(0X65C, ctx->r29) = ctx->r13;
    // 0x80787674: lh          $t6, 0x52C2($s7)
    ctx->r14 = MEM_H(ctx->r23, 0X52C2);
    // 0x80787678: addiu       $s4, $sp, 0x66C
    ctx->r20 = ADD32(ctx->r29, 0X66C);
    // 0x8078767C: addiu       $a0, $sp, 0x674
    ctx->r4 = ADD32(ctx->r29, 0X674);
    // 0x80787680: addiu       $t7, $t6, -0x50
    ctx->r15 = ADD32(ctx->r14, -0X50);
    // 0x80787684: sw          $t7, 0x668($sp)
    MEM_W(0X668, ctx->r29) = ctx->r15;
    // 0x80787688: lw          $v1, -0x4($s3)
    ctx->r3 = MEM_W(ctx->r19, -0X4);
L_8078768C:
    // 0x8078768C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80787690: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // 0x80787694: sltu        $at, $s4, $a0
    ctx->r1 = ctx->r20 < ctx->r4 ? 1 : 0;
    // 0x80787698: addiu       $t9, $v0, -0x50
    ctx->r25 = ADD32(ctx->r2, -0X50);
    // 0x8078769C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x807876A0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x807876A4: sw          $v0, -0x4($s3)
    MEM_W(-0X4, ctx->r19) = ctx->r2;
    // 0x807876A8: bne         $at, $zero, L_8078768C
    if (ctx->r1 != 0) {
        // 0x807876AC: sw          $t9, -0x4($s4)
        MEM_W(-0X4, ctx->r20) = ctx->r25;
            goto L_8078768C;
    }
    // 0x807876AC: sw          $t9, -0x4($s4)
    MEM_W(-0X4, ctx->r20) = ctx->r25;
    // 0x807876B0: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x807876B4: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x807876B8: lui         $at, 0x423C
    ctx->r1 = S32(0X423C << 16);
    // 0x807876BC: addiu       $t0, $s7, 0x520C
    ctx->r8 = ADD32(ctx->r23, 0X520C);
    // 0x807876C0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x807876C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807876C8: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    // 0x807876CC: addiu       $s3, $sp, 0x664
    ctx->r19 = ADD32(ctx->r29, 0X664);
    // 0x807876D0: lwc1        $f28, 0xA8($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x807876D4: lwc1        $f26, 0xA0($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x807876D8: lwc1        $f22, 0xAC($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x807876DC: lwc1        $f20, 0xA4($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x807876E0: addiu       $s5, $zero, 0x1780
    ctx->r21 = ADD32(0, 0X1780);
    // 0x807876E4: addiu       $a1, $sp, 0x668
    ctx->r5 = ADD32(ctx->r29, 0X668);
L_807876E8:
    // 0x807876E8: slti        $at, $s2, 0xB5
    ctx->r1 = SIGNED(ctx->r18) < 0XB5 ? 1 : 0;
    // 0x807876EC: beq         $at, $zero, L_8078775C
    if (ctx->r1 == 0) {
        // 0x807876F0: addu        $s4, $a1, $fp
        ctx->r20 = ADD32(ctx->r5, ctx->r30);
            goto L_8078775C;
    }
    // 0x807876F0: addu        $s4, $a1, $fp
    ctx->r20 = ADD32(ctx->r5, ctx->r30);
    // 0x807876F4: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x807876F8: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x807876FC: addu        $s1, $s7, $t2
    ctx->r17 = ADD32(ctx->r23, ctx->r10);
    // 0x80787700: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80787704: beq         $at, $zero, L_8078775C
    if (ctx->r1 == 0) {
        // 0x80787708: lw          $t5, 0x90($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X90);
            goto L_8078775C;
    }
    // 0x80787708: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x8078770C: sll         $t4, $s2, 5
    ctx->r12 = S32(ctx->r18 << 5);
    // 0x80787710: addu        $v0, $s6, $t4
    ctx->r2 = ADD32(ctx->r22, ctx->r12);
    // 0x80787714: addu        $s0, $t5, $s2
    ctx->r16 = ADD32(ctx->r13, ctx->r18);
    // 0x80787718: swc1        $f0, 0x4C64($s1)
    MEM_W(0X4C64, ctx->r17) = ctx->f0.u32l;
L_8078771C:
    // 0x8078771C: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80787720: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80787724: slti        $at, $s2, 0xB5
    ctx->r1 = SIGNED(ctx->r18) < 0XB5 ? 1 : 0;
    // 0x80787728: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x8078772C: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x80787730: sh          $s5, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r21;
    // 0x80787734: lh          $t8, 0x18($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X18);
    // 0x80787738: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8078773C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80787740: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80787744: beq         $at, $zero, L_8078775C
    if (ctx->r1 == 0) {
        // 0x80787748: sh          $t8, -0x18($v0)
        MEM_H(-0X18, ctx->r2) = ctx->r24;
            goto L_8078775C;
    }
    // 0x80787748: sh          $t8, -0x18($v0)
    MEM_H(-0X18, ctx->r2) = ctx->r24;
    // 0x8078774C: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80787750: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80787754: bnel        $at, $zero, L_8078771C
    if (ctx->r1 != 0) {
        // 0x80787758: swc1        $f0, 0x4C64($s1)
        MEM_W(0X4C64, ctx->r17) = ctx->f0.u32l;
            goto L_8078771C;
    }
    goto skip_1;
    // 0x80787758: swc1        $f0, 0x4C64($s1)
    MEM_W(0X4C64, ctx->r17) = ctx->f0.u32l;
    skip_1:
L_8078775C:
    // 0x8078775C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80787760: addu        $t0, $a1, $fp
    ctx->r8 = ADD32(ctx->r5, ctx->r30);
    // 0x80787764: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80787768: bnel        $at, $zero, L_807877E0
    if (ctx->r1 != 0) {
        // 0x8078776C: slt         $at, $v0, $s2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_807877E0;
    }
    goto skip_2;
    // 0x8078776C: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    skip_2:
    // 0x80787770: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80787774: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80787778: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8078777C: subu        $t1, $v0, $v1
    ctx->r9 = SUB32(ctx->r2, ctx->r3);
    // 0x80787780: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80787784: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80787788: subu        $t3, $s2, $v1
    ctx->r11 = SUB32(ctx->r18, ctx->r3);
    // 0x8078778C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80787790: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80787794: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80787798: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8078779C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x807877A0: div.s       $f28, $f4, $f8
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f28.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x807877A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807877A8: lwc1        $f4, 0x52C8($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X52C8);
    // 0x807877AC: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F24) << 16);
    // 0x807877B0: mul.s       $f22, $f6, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x807877B4: lwc1        $f6, -0x669C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F24));
    // 0x807877B8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x807877BC: nop

    // 0x807877C0: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x807877C4: div.s       $f26, $f24, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = DIV_S(ctx->f24.fl, ctx->f4.fl);
    // 0x807877C8: c.lt.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl < ctx->f0.fl;
    // 0x807877CC: nop

    // 0x807877D0: bc1f        L_807877DC
    if (!c1cs) {
        // 0x807877D4: nop
    
            goto L_807877DC;
    }
    // 0x807877D4: nop

    // 0x807877D8: neg.s       $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f26.fl = -ctx->f26.fl;
L_807877DC:
    // 0x807877DC: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
L_807877E0:
    // 0x807877E0: bne         $at, $zero, L_80787840
    if (ctx->r1 != 0) {
        // 0x807877E4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80787840;
    }
    // 0x807877E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_807877E8:
    // 0x807877E8: bltz        $a0, L_80787818
    if (SIGNED(ctx->r4) < 0) {
        // 0x807877EC: slti        $at, $a0, 0xB5
        ctx->r1 = SIGNED(ctx->r4) < 0XB5 ? 1 : 0;
            goto L_80787818;
    }
    // 0x807877EC: slti        $at, $a0, 0xB5
    ctx->r1 = SIGNED(ctx->r4) < 0XB5 ? 1 : 0;
    // 0x807877F0: beql        $at, $zero, L_8078781C
    if (ctx->r1 == 0) {
        // 0x807877F4: add.s       $f20, $f20, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
            goto L_8078781C;
    }
    goto skip_3;
    // 0x807877F4: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    skip_3:
    // 0x807877F8: mul.s       $f8, $f20, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x807877FC: sll         $t5, $a0, 5
    ctx->r13 = S32(ctx->r4 << 5);
    // 0x80787800: addu        $v1, $s6, $t5
    ctx->r3 = ADD32(ctx->r22, ctx->r13);
    // 0x80787804: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80787808: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8078780C: nop

    // 0x80787810: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    // 0x80787814: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
L_80787818:
    // 0x80787818: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
L_8078781C:
    // 0x8078781C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80787820: slt         $at, $a0, $s2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80787824: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x80787828: nop

    // 0x8078782C: bc1f        L_80787838
    if (!c1cs) {
        // 0x80787830: nop
    
            goto L_80787838;
    }
    // 0x80787830: nop

    // 0x80787834: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
L_80787838:
    // 0x80787838: beq         $at, $zero, L_807877E8
    if (ctx->r1 == 0) {
        // 0x8078783C: nop
    
            goto L_807877E8;
    }
    // 0x8078783C: nop

L_80787840:
    // 0x80787840: slti        $at, $s2, 0xB5
    ctx->r1 = SIGNED(ctx->r18) < 0XB5 ? 1 : 0;
    // 0x80787844: beql        $at, $zero, L_807878C4
    if (ctx->r1 == 0) {
        // 0x80787848: addiu       $s3, $s3, -0x4
        ctx->r19 = ADD32(ctx->r19, -0X4);
            goto L_807878C4;
    }
    goto skip_4;
    // 0x80787848: addiu       $s3, $s3, -0x4
    ctx->r19 = ADD32(ctx->r19, -0X4);
    skip_4:
    // 0x8078784C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80787850: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x80787854: slt         $at, $t7, $s2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80787858: bne         $at, $zero, L_807878C0
    if (ctx->r1 != 0) {
        // 0x8078785C: addu        $s0, $t9, $s2
        ctx->r16 = ADD32(ctx->r25, ctx->r18);
            goto L_807878C0;
    }
    // 0x8078785C: addu        $s0, $t9, $s2
    ctx->r16 = ADD32(ctx->r25, ctx->r18);
    // 0x80787860: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x80787864: addu        $s1, $s7, $t8
    ctx->r17 = ADD32(ctx->r23, ctx->r24);
L_80787868:
    // 0x80787868: jal         0x80066E88
    // 0x8078786C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8078786C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x80787870: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80787874: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80787878: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F28) << 16);
    // 0x8078787C: lwc1        $f8, -0x6698($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F28));
    // 0x80787880: sub.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80787884: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80787888: slti        $at, $s2, 0xB5
    ctx->r1 = SIGNED(ctx->r18) < 0XB5 ? 1 : 0;
    // 0x8078788C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80787890: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80787894: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80787898: add.s       $f22, $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f28.fl;
    // 0x8078789C: swc1        $f10, 0x4C60($s1)
    MEM_W(0X4C60, ctx->r17) = ctx->f10.u32l;
    // 0x807878A0: lbu         $t0, -0x1($s0)
    ctx->r8 = MEM_BU(ctx->r16, -0X1);
    // 0x807878A4: andi        $t1, $t0, 0x7F
    ctx->r9 = ctx->r8 & 0X7F;
    // 0x807878A8: beq         $at, $zero, L_807878C0
    if (ctx->r1 == 0) {
        // 0x807878AC: sb          $t1, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r9;
            goto L_807878C0;
    }
    // 0x807878AC: sb          $t1, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r9;
    // 0x807878B0: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x807878B4: slt         $at, $t2, $s2
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x807878B8: beq         $at, $zero, L_80787868
    if (ctx->r1 == 0) {
        // 0x807878BC: nop
    
            goto L_80787868;
    }
    // 0x807878BC: nop

L_807878C0:
    // 0x807878C0: addiu       $s3, $s3, -0x4
    ctx->r19 = ADD32(ctx->r19, -0X4);
L_807878C4:
    // 0x807878C4: addiu       $t3, $sp, 0x65C
    ctx->r11 = ADD32(ctx->r29, 0X65C);
    // 0x807878C8: sltu        $at, $s3, $t3
    ctx->r1 = ctx->r19 < ctx->r11 ? 1 : 0;
    // 0x807878CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807878D0: addiu       $fp, $fp, -0x4
    ctx->r30 = ADD32(ctx->r30, -0X4);
    // 0x807878D4: beq         $at, $zero, L_807876E8
    if (ctx->r1 == 0) {
        // 0x807878D8: addiu       $a1, $sp, 0x668
        ctx->r5 = ADD32(ctx->r29, 0X668);
            goto L_807876E8;
    }
    // 0x807878D8: addiu       $a1, $sp, 0x668
    ctx->r5 = ADD32(ctx->r29, 0X668);
    // 0x807878DC: slti        $at, $s2, 0xB5
    ctx->r1 = SIGNED(ctx->r18) < 0XB5 ? 1 : 0;
    // 0x807878E0: swc1        $f28, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f28.u32l;
    // 0x807878E4: swc1        $f26, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f26.u32l;
    // 0x807878E8: swc1        $f22, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f22.u32l;
    // 0x807878EC: beq         $at, $zero, L_80787940
    if (ctx->r1 == 0) {
        // 0x807878F0: swc1        $f20, 0xA4($sp)
        MEM_W(0XA4, ctx->r29) = ctx->f20.u32l;
            goto L_80787940;
    }
    // 0x807878F0: swc1        $f20, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f20.u32l;
    // 0x807878F4: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x807878F8: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x807878FC: sll         $t6, $s2, 5
    ctx->r14 = S32(ctx->r18 << 5);
    // 0x80787900: addu        $v0, $s6, $t6
    ctx->r2 = ADD32(ctx->r22, ctx->r14);
    // 0x80787904: addu        $s1, $s7, $t4
    ctx->r17 = ADD32(ctx->r23, ctx->r12);
    // 0x80787908: addu        $s0, $t7, $s2
    ctx->r16 = ADD32(ctx->r15, ctx->r18);
L_8078790C:
    // 0x8078790C: swc1        $f0, 0x4C64($s1)
    MEM_W(0X4C64, ctx->r17) = ctx->f0.u32l;
    // 0x80787910: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x80787914: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80787918: slti        $at, $s2, 0xB5
    ctx->r1 = SIGNED(ctx->r18) < 0XB5 ? 1 : 0;
    // 0x8078791C: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x80787920: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x80787924: sh          $s5, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r21;
    // 0x80787928: lh          $t0, 0x18($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X18);
    // 0x8078792C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80787930: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80787934: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80787938: bne         $at, $zero, L_8078790C
    if (ctx->r1 != 0) {
        // 0x8078793C: sh          $t0, -0x18($v0)
        MEM_H(-0X18, ctx->r2) = ctx->r8;
            goto L_8078790C;
    }
    // 0x8078793C: sh          $t0, -0x18($v0)
    MEM_H(-0X18, ctx->r2) = ctx->r8;
L_80787940:
    // 0x80787940: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80787944: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80787948: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8078794C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80787950: addiu       $s3, $sp, 0x664
    ctx->r19 = ADD32(ctx->r29, 0X664);
    // 0x80787954: addiu       $s4, $sp, 0x670
    ctx->r20 = ADD32(ctx->r29, 0X670);
    // 0x80787958: addiu       $s5, $sp, 0x668
    ctx->r21 = ADD32(ctx->r29, 0X668);
L_8078795C:
    // 0x8078795C: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    // 0x80787960: bgezl       $s2, L_80787970
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80787964: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_80787970;
    }
    goto skip_5;
    // 0x80787964: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_5:
    // 0x80787968: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8078796C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_80787970:
    // 0x80787970: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80787974: beq         $at, $zero, L_807879D0
    if (ctx->r1 == 0) {
        // 0x80787978: slti        $at, $s2, 0xB4
        ctx->r1 = SIGNED(ctx->r18) < 0XB4 ? 1 : 0;
            goto L_807879D0;
    }
    // 0x80787978: slti        $at, $s2, 0xB4
    ctx->r1 = SIGNED(ctx->r18) < 0XB4 ? 1 : 0;
    // 0x8078797C: beq         $at, $zero, L_807879D0
    if (ctx->r1 == 0) {
        // 0x80787980: sll         $a0, $s2, 2
        ctx->r4 = S32(ctx->r18 << 2);
            goto L_807879D0;
    }
    // 0x80787980: sll         $a0, $s2, 2
    ctx->r4 = S32(ctx->r18 << 2);
    // 0x80787984: addiu       $t1, $sp, 0xB0
    ctx->r9 = ADD32(ctx->r29, 0XB0);
    // 0x80787988: addu        $s0, $a0, $t1
    ctx->r16 = ADD32(ctx->r4, ctx->r9);
    // 0x8078798C: addu        $s1, $s7, $a0
    ctx->r17 = ADD32(ctx->r23, ctx->r4);
    // 0x80787990: lwc1        $f6, 0x4990($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4990);
L_80787994:
    // 0x80787994: lwc1        $f4, 0x4994($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4994);
    // 0x80787998: lwc1        $f0, 0x52C8($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X52C8);
    // 0x8078799C: sub.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x807879A0: jal         0x80067114
    // 0x807879A4: add.s       $f14, $f0, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f0.fl;
    func_80067114(rdram, ctx);
        goto after_1;
    // 0x807879A4: add.s       $f14, $f0, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f0.fl;
    after_1:
    // 0x807879A8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x807879AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x807879B0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807879B4: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x807879B8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x807879BC: beq         $at, $zero, L_807879D0
    if (ctx->r1 == 0) {
        // 0x807879C0: swc1        $f0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f0.u32l;
            goto L_807879D0;
    }
    // 0x807879C0: swc1        $f0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f0.u32l;
    // 0x807879C4: slti        $at, $s2, 0xB4
    ctx->r1 = SIGNED(ctx->r18) < 0XB4 ? 1 : 0;
    // 0x807879C8: bnel        $at, $zero, L_80787994
    if (ctx->r1 != 0) {
        // 0x807879CC: lwc1        $f6, 0x4990($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0X4990);
            goto L_80787994;
    }
    goto skip_6;
    // 0x807879CC: lwc1        $f6, 0x4990($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4990);
    skip_6:
L_807879D0:
    // 0x807879D0: lw          $s2, 0x0($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X0);
    // 0x807879D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x807879D8: bgtzl       $s2, L_807879E8
    if (SIGNED(ctx->r18) > 0) {
        // 0x807879DC: slt         $at, $s2, $v0
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_807879E8;
    }
    goto skip_7;
    // 0x807879DC: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    skip_7:
    // 0x807879E0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x807879E4: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
L_807879E8:
    // 0x807879E8: beq         $at, $zero, L_80787A54
    if (ctx->r1 == 0) {
        // 0x807879EC: slti        $at, $s2, 0xB4
        ctx->r1 = SIGNED(ctx->r18) < 0XB4 ? 1 : 0;
            goto L_80787A54;
    }
    // 0x807879EC: slti        $at, $s2, 0xB4
    ctx->r1 = SIGNED(ctx->r18) < 0XB4 ? 1 : 0;
    // 0x807879F0: beq         $at, $zero, L_80787A54
    if (ctx->r1 == 0) {
        // 0x807879F4: sll         $a0, $s2, 2
        ctx->r4 = S32(ctx->r18 << 2);
            goto L_80787A54;
    }
    // 0x807879F4: sll         $a0, $s2, 2
    ctx->r4 = S32(ctx->r18 << 2);
    // 0x807879F8: addiu       $t2, $sp, 0xB0
    ctx->r10 = ADD32(ctx->r29, 0XB0);
    // 0x807879FC: addu        $s0, $a0, $t2
    ctx->r16 = ADD32(ctx->r4, ctx->r10);
    // 0x80787A00: addu        $s1, $s7, $a0
    ctx->r17 = ADD32(ctx->r23, ctx->r4);
    // 0x80787A04: lwc1        $f8, -0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, -0X4);
L_80787A08:
    // 0x80787A08: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80787A0C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80787A10: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80787A14: jal         0x80066DE4
    // 0x80787A18: nop

    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x80787A18: nop

    after_2:
    // 0x80787A1C: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80787A20: lwc1        $f4, 0x4C64($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4C64);
    // 0x80787A24: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80787A28: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80787A2C: add.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x80787A30: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80787A34: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80787A38: swc1        $f6, 0x4C60($s1)
    MEM_W(0X4C60, ctx->r17) = ctx->f6.u32l;
    // 0x80787A3C: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80787A40: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80787A44: beq         $at, $zero, L_80787A54
    if (ctx->r1 == 0) {
        // 0x80787A48: slti        $at, $s2, 0xB4
        ctx->r1 = SIGNED(ctx->r18) < 0XB4 ? 1 : 0;
            goto L_80787A54;
    }
    // 0x80787A48: slti        $at, $s2, 0xB4
    ctx->r1 = SIGNED(ctx->r18) < 0XB4 ? 1 : 0;
    // 0x80787A4C: bnel        $at, $zero, L_80787A08
    if (ctx->r1 != 0) {
        // 0x80787A50: lwc1        $f8, -0x4($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, -0X4);
            goto L_80787A08;
    }
    goto skip_8;
    // 0x80787A50: lwc1        $f8, -0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, -0X4);
    skip_8:
L_80787A54:
    // 0x80787A54: addiu       $s4, $s4, -0x4
    ctx->r20 = ADD32(ctx->r20, -0X4);
    // 0x80787A58: sltu        $at, $s4, $s5
    ctx->r1 = ctx->r20 < ctx->r21 ? 1 : 0;
    // 0x80787A5C: beq         $at, $zero, L_8078795C
    if (ctx->r1 == 0) {
        // 0x80787A60: addiu       $s3, $s3, -0x4
        ctx->r19 = ADD32(ctx->r19, -0X4);
            goto L_8078795C;
    }
    // 0x80787A60: addiu       $s3, $s3, -0x4
    ctx->r19 = ADD32(ctx->r19, -0X4);
    // 0x80787A64: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80787A68: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80787A6C: addiu       $fp, $zero, 0x8
    ctx->r30 = ADD32(0, 0X8);
    // 0x80787A70: addiu       $s4, $sp, 0x670
    ctx->r20 = ADD32(ctx->r29, 0X670);
    // 0x80787A74: addiu       $a3, $sp, 0x668
    ctx->r7 = ADD32(ctx->r29, 0X668);
    // 0x80787A78: addiu       $a2, $sp, 0x65C
    ctx->r6 = ADD32(ctx->r29, 0X65C);
    // 0x80787A7C: addiu       $a1, $sp, 0x384
    ctx->r5 = ADD32(ctx->r29, 0X384);
L_80787A80:
    // 0x80787A80: blez        $s2, L_80787A9C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80787A84: addu        $t8, $a2, $fp
        ctx->r24 = ADD32(ctx->r6, ctx->r30);
            goto L_80787A9C;
    }
    // 0x80787A84: addu        $t8, $a2, $fp
    ctx->r24 = ADD32(ctx->r6, ctx->r30);
    // 0x80787A88: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80787A8C: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80787A90: beq         $at, $zero, L_80787AC8
    if (ctx->r1 == 0) {
        // 0x80787A94: slti        $at, $s2, 0xB5
        ctx->r1 = SIGNED(ctx->r18) < 0XB5 ? 1 : 0;
            goto L_80787AC8;
    }
    // 0x80787A94: slti        $at, $s2, 0xB5
    ctx->r1 = SIGNED(ctx->r18) < 0XB5 ? 1 : 0;
    // 0x80787A98: beq         $at, $zero, L_80787AC8
    if (ctx->r1 == 0) {
        // 0x80787A9C: sll         $t5, $s2, 2
        ctx->r13 = S32(ctx->r18 << 2);
            goto L_80787AC8;
    }
L_80787A9C:
    // 0x80787A9C: sll         $t5, $s2, 2
    ctx->r13 = S32(ctx->r18 << 2);
L_80787AA0:
    // 0x80787AA0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80787AA4: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x80787AA8: blez        $s2, L_80787A9C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80787AAC: swc1        $f22, 0x0($t6)
        MEM_W(0X0, ctx->r14) = ctx->f22.u32l;
            goto L_80787A9C;
    }
    // 0x80787AAC: swc1        $f22, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f22.u32l;
    // 0x80787AB0: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80787AB4: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80787AB8: beq         $at, $zero, L_80787AC8
    if (ctx->r1 == 0) {
        // 0x80787ABC: slti        $at, $s2, 0xB5
        ctx->r1 = SIGNED(ctx->r18) < 0XB5 ? 1 : 0;
            goto L_80787AC8;
    }
    // 0x80787ABC: slti        $at, $s2, 0xB5
    ctx->r1 = SIGNED(ctx->r18) < 0XB5 ? 1 : 0;
    // 0x80787AC0: bnel        $at, $zero, L_80787AA0
    if (ctx->r1 != 0) {
        // 0x80787AC4: sll         $t5, $s2, 2
        ctx->r13 = S32(ctx->r18 << 2);
            goto L_80787AA0;
    }
    goto skip_9;
    // 0x80787AC4: sll         $t5, $s2, 2
    ctx->r13 = S32(ctx->r18 << 2);
    skip_9:
L_80787AC8:
    // 0x80787AC8: slti        $at, $s2, 0xB4
    ctx->r1 = SIGNED(ctx->r18) < 0XB4 ? 1 : 0;
    // 0x80787ACC: beq         $at, $zero, L_80787B28
    if (ctx->r1 == 0) {
        // 0x80787AD0: addiu       $s4, $s4, -0x4
        ctx->r20 = ADD32(ctx->r20, -0X4);
            goto L_80787B28;
    }
    // 0x80787AD0: addiu       $s4, $s4, -0x4
    ctx->r20 = ADD32(ctx->r20, -0X4);
    // 0x80787AD4: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80787AD8: sll         $a0, $s2, 2
    ctx->r4 = S32(ctx->r18 << 2);
    // 0x80787ADC: addu        $s1, $s7, $a0
    ctx->r17 = ADD32(ctx->r23, ctx->r4);
    // 0x80787AE0: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80787AE4: bne         $at, $zero, L_80787B28
    if (ctx->r1 != 0) {
        // 0x80787AE8: addu        $v1, $a1, $a0
        ctx->r3 = ADD32(ctx->r5, ctx->r4);
            goto L_80787B28;
    }
    // 0x80787AE8: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x80787AEC: lwc1        $f8, 0x498C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X498C);
L_80787AF0:
    // 0x80787AF0: lwc1        $f4, 0x4994($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4994);
    // 0x80787AF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80787AF8: slti        $at, $s2, 0xB4
    ctx->r1 = SIGNED(ctx->r18) < 0XB4 ? 1 : 0;
    // 0x80787AFC: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80787B00: lwc1        $f8, 0x4990($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4990);
    // 0x80787B04: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80787B08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80787B0C: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80787B10: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80787B14: beq         $at, $zero, L_80787B28
    if (ctx->r1 == 0) {
        // 0x80787B18: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_80787B28;
    }
    // 0x80787B18: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x80787B1C: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80787B20: beql        $at, $zero, L_80787AF0
    if (ctx->r1 == 0) {
        // 0x80787B24: lwc1        $f8, 0x498C($s1)
        ctx->f8.u32l = MEM_W(ctx->r17, 0X498C);
            goto L_80787AF0;
    }
    goto skip_10;
    // 0x80787B24: lwc1        $f8, 0x498C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X498C);
    skip_10:
L_80787B28:
    // 0x80787B28: sltu        $at, $s4, $a3
    ctx->r1 = ctx->r20 < ctx->r7 ? 1 : 0;
    // 0x80787B2C: beq         $at, $zero, L_80787A80
    if (ctx->r1 == 0) {
        // 0x80787B30: addiu       $fp, $fp, -0x4
        ctx->r30 = ADD32(ctx->r30, -0X4);
            goto L_80787A80;
    }
    // 0x80787B30: addiu       $fp, $fp, -0x4
    ctx->r30 = ADD32(ctx->r30, -0X4);
    // 0x80787B34: slti        $at, $s2, 0xB5
    ctx->r1 = SIGNED(ctx->r18) < 0XB5 ? 1 : 0;
    // 0x80787B38: beq         $at, $zero, L_80787B60
    if (ctx->r1 == 0) {
        // 0x80787B3C: or          $s1, $s7, $zero
        ctx->r17 = ctx->r23 | 0;
            goto L_80787B60;
    }
    // 0x80787B3C: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x80787B40: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x80787B44: addiu       $t0, $sp, 0x384
    ctx->r8 = ADD32(ctx->r29, 0X384);
    // 0x80787B48: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x80787B4C: addiu       $v0, $sp, 0x658
    ctx->r2 = ADD32(ctx->r29, 0X658);
L_80787B50:
    // 0x80787B50: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80787B54: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80787B58: bne         $at, $zero, L_80787B50
    if (ctx->r1 != 0) {
        // 0x80787B5C: swc1        $f22, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f22.u32l;
            goto L_80787B50;
    }
    // 0x80787B5C: swc1        $f22, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f22.u32l;
L_80787B60:
    // 0x80787B60: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F2C) << 16);
    // 0x80787B64: lwc1        $f24, -0x6694($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F2C));
    // 0x80787B68: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F30) << 16);
    // 0x80787B6C: lwc1        $f20, -0x6690($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F30));
    // 0x80787B70: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F34) << 16);
    // 0x80787B74: lwc1        $f18, -0x668C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F34));
    // 0x80787B78: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F38) << 16);
    // 0x80787B7C: lwc1        $f16, -0x6688($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F38));
    // 0x80787B80: addiu       $v1, $sp, 0x384
    ctx->r3 = ADD32(ctx->r29, 0X384);
    // 0x80787B84: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x80787B88: lbu         $a1, 0x67B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X67B);
    // 0x80787B8C: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x80787B90: addiu       $a0, $sp, 0x658
    ctx->r4 = ADD32(ctx->r29, 0X658);
L_80787B94:
    // 0x80787B94: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x80787B98: lwc1        $f12, 0x4C64($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4C64);
    // 0x80787B9C: lwc1        $f10, 0x43E8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X43E8);
    // 0x80787BA0: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x80787BA4: beq         $t2, $zero, L_80787BC4
    if (ctx->r10 == 0) {
        // 0x80787BA8: sub.s       $f0, $f10, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f12.fl;
            goto L_80787BC4;
    }
    // 0x80787BA8: sub.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x80787BAC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80787BB0: nop

    // 0x80787BB4: bc1f        L_80787BC4
    if (!c1cs) {
        // 0x80787BB8: nop
    
            goto L_80787BC4;
    }
    // 0x80787BB8: nop

    // 0x80787BBC: b           L_80787BCC
    // 0x80787BC0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80787BCC;
    // 0x80787BC0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80787BC4:
    // 0x80787BC4: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80787BC8: nop

L_80787BCC:
    // 0x80787BCC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80787BD0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80787BD4: nop

    // 0x80787BD8: bc1fl       L_80787BF8
    if (!c1cs) {
        // 0x80787BDC: add.s       $f6, $f12, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_80787BF8;
    }
    goto skip_11;
    // 0x80787BDC: add.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f0.fl;
    skip_11:
    // 0x80787BE0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80787BE4: nop

    // 0x80787BE8: bc1fl       L_80787BF8
    if (!c1cs) {
        // 0x80787BEC: add.s       $f6, $f12, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_80787BF8;
    }
    goto skip_12;
    // 0x80787BEC: add.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f0.fl;
    skip_12:
    // 0x80787BF0: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x80787BF4: add.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f0.fl;
L_80787BF8:
    // 0x80787BF8: lwc1        $f8, 0x43EC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X43EC);
    // 0x80787BFC: swc1        $f6, 0x43E8($v0)
    MEM_W(0X43E8, ctx->r2) = ctx->f6.u32l;
    // 0x80787C00: lwc1        $f14, 0x4C64($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X4C64);
    // 0x80787C04: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x80787C08: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80787C0C: andi        $t4, $t3, 0x80
    ctx->r12 = ctx->r11 & 0X80;
    // 0x80787C10: beq         $t4, $zero, L_80787C30
    if (ctx->r12 == 0) {
        // 0x80787C14: sub.s       $f0, $f8, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f14.fl;
            goto L_80787C30;
    }
    // 0x80787C14: sub.s       $f0, $f8, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80787C18: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80787C1C: nop

    // 0x80787C20: bc1f        L_80787C30
    if (!c1cs) {
        // 0x80787C24: nop
    
            goto L_80787C30;
    }
    // 0x80787C24: nop

    // 0x80787C28: b           L_80787C38
    // 0x80787C2C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80787C38;
    // 0x80787C2C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80787C30:
    // 0x80787C30: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80787C34: nop

L_80787C38:
    // 0x80787C38: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80787C3C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80787C40: nop

    // 0x80787C44: bc1fl       L_80787C64
    if (!c1cs) {
        // 0x80787C48: add.s       $f4, $f14, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f0.fl;
            goto L_80787C64;
    }
    goto skip_13;
    // 0x80787C48: add.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f0.fl;
    skip_13:
    // 0x80787C4C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80787C50: nop

    // 0x80787C54: bc1fl       L_80787C64
    if (!c1cs) {
        // 0x80787C58: add.s       $f4, $f14, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f0.fl;
            goto L_80787C64;
    }
    goto skip_14;
    // 0x80787C58: add.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f0.fl;
    skip_14:
    // 0x80787C5C: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x80787C60: add.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f0.fl;
L_80787C64:
    // 0x80787C64: lwc1        $f10, 0x43E8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X43E8);
    // 0x80787C68: swc1        $f4, 0x43EC($v0)
    MEM_W(0X43EC, ctx->r2) = ctx->f4.u32l;
    // 0x80787C6C: lwc1        $f8, 0x43EC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X43EC);
    // 0x80787C70: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80787C74: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80787C78: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80787C7C: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80787C80: nop

    // 0x80787C84: bnel        $t6, $t8, L_80787CA0
    if (ctx->r14 != ctx->r24) {
        // 0x80787C88: lbu         $t1, 0x0($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X0);
            goto L_80787CA0;
    }
    goto skip_15;
    // 0x80787C88: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    skip_15:
    // 0x80787C8C: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x80787C90: or          $t0, $t9, $a1
    ctx->r8 = ctx->r25 | ctx->r5;
    // 0x80787C94: b           L_80787CAC
    // 0x80787C98: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
        goto L_80787CAC;
    // 0x80787C98: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
    // 0x80787C9C: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
L_80787CA0:
    // 0x80787CA0: xori        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 ^ 0XFF;
    // 0x80787CA4: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x80787CA8: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
L_80787CAC:
    // 0x80787CAC: lwc1        $f10, 0x4990($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4990);
    // 0x80787CB0: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80787CB4: lwc1        $f4, 0x4F38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4F38);
    // 0x80787CB8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80787CBC: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80787CC0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80787CC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80787CC8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80787CCC: swc1        $f8, 0x498C($s1)
    MEM_W(0X498C, ctx->r17) = ctx->f8.u32l;
    // 0x80787CD0: lwc1        $f0, 0x498C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X498C);
    // 0x80787CD4: sub.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80787CD8: mul.s       $f6, $f10, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80787CDC: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80787CE0: bne         $v1, $a0, L_80787B94
    if (ctx->r3 != ctx->r4) {
        // 0x80787CE4: swc1        $f8, 0x498C($s1)
        MEM_W(0X498C, ctx->r17) = ctx->f8.u32l;
            goto L_80787B94;
    }
    // 0x80787CE4: swc1        $f8, 0x498C($s1)
    MEM_W(0X498C, ctx->r17) = ctx->f8.u32l;
    // 0x80787CE8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F3C) << 16);
    // 0x80787CEC: lwc1        $f2, -0x6684($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F3C));
    // 0x80787CF0: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F40) << 16);
    // 0x80787CF4: lwc1        $f0, -0x6680($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F40));
    // 0x80787CF8: addiu       $s3, $sp, 0x65C
    ctx->r19 = ADD32(ctx->r29, 0X65C);
    // 0x80787CFC: addiu       $a0, $sp, 0x668
    ctx->r4 = ADD32(ctx->r29, 0X668);
    // 0x80787D00: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_80787D04:
    // 0x80787D04: bltz        $v0, L_80787D48
    if (SIGNED(ctx->r2) < 0) {
        // 0x80787D08: slti        $at, $v0, 0xB5
        ctx->r1 = SIGNED(ctx->r2) < 0XB5 ? 1 : 0;
            goto L_80787D48;
    }
    // 0x80787D08: slti        $at, $v0, 0xB5
    ctx->r1 = SIGNED(ctx->r2) < 0XB5 ? 1 : 0;
    // 0x80787D0C: beq         $at, $zero, L_80787D48
    if (ctx->r1 == 0) {
        // 0x80787D10: lw          $t4, 0x90($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X90);
            goto L_80787D48;
    }
    // 0x80787D10: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x80787D14: addu        $v1, $v0, $t4
    ctx->r3 = ADD32(ctx->r2, ctx->r12);
    // 0x80787D18: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x80787D1C: xori        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 ^ 0XFF;
    // 0x80787D20: and         $t6, $t5, $t7
    ctx->r14 = ctx->r13 & ctx->r15;
    // 0x80787D24: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x80787D28: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80787D2C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80787D30: addu        $t1, $s7, $t0
    ctx->r9 = ADD32(ctx->r23, ctx->r8);
    // 0x80787D34: swc1        $f0, 0x43E8($t1)
    MEM_W(0X43E8, ctx->r9) = ctx->f0.u32l;
    // 0x80787D38: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80787D3C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80787D40: addu        $t5, $s7, $t4
    ctx->r13 = ADD32(ctx->r23, ctx->r12);
    // 0x80787D44: swc1        $f2, 0x43EC($t5)
    MEM_W(0X43EC, ctx->r13) = ctx->f2.u32l;
L_80787D48:
    // 0x80787D48: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80787D4C: bnel        $s3, $a0, L_80787D04
    if (ctx->r19 != ctx->r4) {
        // 0x80787D50: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_80787D04;
    }
    goto skip_16;
    // 0x80787D50: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_16:
    // 0x80787D54: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80787D58: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80787D5C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80787D60: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80787D64: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80787D68: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80787D6C: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80787D70: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80787D74: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80787D78: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80787D7C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80787D80: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80787D84: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80787D88: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80787D8C: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80787D90: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80787D94: jr          $ra
    // 0x80787D98: addiu       $sp, $sp, 0x690
    ctx->r29 = ADD32(ctx->r29, 0X690);
    return;
    // 0x80787D98: addiu       $sp, $sp, 0x690
    ctx->r29 = ADD32(ctx->r29, 0X690);
;}
RECOMP_FUNC void func_807094FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807094FC: jr          $ra
    // 0x80709500: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80709500: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8040FDC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040FDC8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8040FDCC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8040FDD0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8040FDD4: addu        $v0, $a0, $at
    ctx->r2 = ADD32(ctx->r4, ctx->r1);
    // 0x8040FDD8: lw          $t6, 0x39D4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X39D4);
    // 0x8040FDDC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8040FDE0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8040FDE4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8040FDE8: bgez        $t6, L_8040FDFC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8040FDEC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8040FDFC;
    }
    // 0x8040FDEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8040FDF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8040FDF4: nop

    // 0x8040FDF8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8040FDFC:
    // 0x8040FDFC: mul.s       $f0, $f6, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8040FE00: lw          $t7, 0x39D8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X39D8);
    // 0x8040FE04: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8040FE08: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8040FE0C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8040FE10: bgez        $t7, L_8040FE24
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8040FE14: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8040FE24;
    }
    // 0x8040FE14: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8040FE18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8040FE1C: nop

    // 0x8040FE20: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8040FE24:
    // 0x8040FE24: mul.s       $f2, $f4, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8040FE28: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8040FE2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8040FE30: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x8040FE34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8040FE38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8040FE3C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8040FE40:
    // 0x8040FE40: add.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8040FE44: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8040FE48: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8040FE4C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8040FE50: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8040FE54: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8040FE58: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x8040FE5C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8040FE60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8040FE64: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8040FE68: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8040FE6C: nop

L_8040FE70:
    // 0x8040FE70: add.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8040FE74: sh          $a2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r6;
    // 0x8040FE78: sh          $zero, 0x4($t0)
    MEM_H(0X4, ctx->r8) = 0;
    // 0x8040FE7C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8040FE80: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8040FE84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8040FE88: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8040FE8C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8040FE90: nop

    // 0x8040FE94: sh          $t3, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r11;
    // 0x8040FE98: lw          $t4, 0x39E0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X39E0);
    // 0x8040FE9C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8040FEA0: bgez        $t4, L_8040FEB4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8040FEA4: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8040FEB4;
    }
    // 0x8040FEA4: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8040FEA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040FEAC: nop

    // 0x8040FEB0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8040FEB4:
    // 0x8040FEB4: lw          $t1, 0x39E8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X39E8);
    // 0x8040FEB8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8040FEBC: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x8040FEC0: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x8040FEC4: beq         $at, $zero, L_8040FE70
    if (ctx->r1 == 0) {
        // 0x8040FEC8: addiu       $t0, $t0, 0xA
        ctx->r8 = ADD32(ctx->r8, 0XA);
            goto L_8040FE70;
    }
    // 0x8040FEC8: addiu       $t0, $t0, 0xA
    ctx->r8 = ADD32(ctx->r8, 0XA);
    // 0x8040FECC: lw          $t5, 0x39DC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X39DC);
    // 0x8040FED0: lw          $a2, 0x39E4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X39E4);
    // 0x8040FED4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8040FED8: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8040FEDC: bgez        $t5, L_8040FEF0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8040FEE0: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8040FEF0;
    }
    // 0x8040FEE0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8040FEE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040FEE8: nop

    // 0x8040FEEC: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_8040FEF0:
    // 0x8040FEF0: sltu        $at, $a2, $a1
    ctx->r1 = ctx->r6 < ctx->r5 ? 1 : 0;
    // 0x8040FEF4: beq         $at, $zero, L_8040FE40
    if (ctx->r1 == 0) {
        // 0x8040FEF8: add.s       $f12, $f12, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
            goto L_8040FE40;
    }
    // 0x8040FEF8: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x8040FEFC: jr          $ra
    // 0x8040FF00: nop

    return;
    // 0x8040FF00: nop

;}
RECOMP_FUNC void func_8003033C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003033C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80030340: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80030344: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80030348: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003034C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80030350: jal         0x80021A44
    // 0x80030354: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_80021A44(rdram, ctx);
        goto after_0;
    // 0x80030354: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x80030358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003035C: jal         0x80042880
    // 0x80030360: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80042880(rdram, ctx);
        goto after_1;
    // 0x80030360: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80030364: lw          $t6, 0x78($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X78);
    // 0x80030368: beq         $t6, $zero, L_80030390
    if (ctx->r14 == 0) {
        // 0x8003036C: nop
    
            goto L_80030390;
    }
    // 0x8003036C: nop

    // 0x80030370: lw          $t7, 0x24($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X24);
    // 0x80030374: andi        $t8, $t7, 0x700
    ctx->r24 = ctx->r15 & 0X700;
    // 0x80030378: beq         $t8, $zero, L_80030390
    if (ctx->r24 == 0) {
        // 0x8003037C: nop
    
            goto L_80030390;
    }
    // 0x8003037C: nop

    // 0x80030380: jal         0x8002D2F0
    // 0x80030384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002D2F0(rdram, ctx);
        goto after_2;
    // 0x80030384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80030388: b           L_800303EC
    // 0x8003038C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800303EC;
    // 0x8003038C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80030390:
    // 0x80030390: jal         0x800592AC
    // 0x80030394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800592AC(rdram, ctx);
        goto after_3;
    // 0x80030394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80030398: bne         $v0, $zero, L_800303B0
    if (ctx->r2 != 0) {
        // 0x8003039C: nop
    
            goto L_800303B0;
    }
    // 0x8003039C: nop

    // 0x800303A0: jal         0x8002E7C8
    // 0x800303A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002E7C8(rdram, ctx);
        goto after_4;
    // 0x800303A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800303A8: b           L_800303EC
    // 0x800303AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800303EC;
    // 0x800303AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800303B0:
    // 0x800303B0: jal         0x80023EA0
    // 0x800303B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80023EA0(rdram, ctx);
        goto after_5;
    // 0x800303B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800303B8: jal         0x80028220
    // 0x800303BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028220(rdram, ctx);
        goto after_6;
    // 0x800303BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800303C0: sw          $v0, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->r2;
    // 0x800303C4: jal         0x80065954
    // 0x800303C8: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    func_80065954(rdram, ctx);
        goto after_7;
    // 0x800303C8: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    after_7:
    // 0x800303CC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800303D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800303D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800303D8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800303DC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800303E0: jal         0x80041214
    // 0x800303E4: nop

    func_80041214(rdram, ctx);
        goto after_8;
    // 0x800303E4: nop

    after_8:
    // 0x800303E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800303EC:
    // 0x800303EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800303F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800303F4: jr          $ra
    // 0x800303F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800303F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_807169F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807169F8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807169FC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716A00: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716A04: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716A08: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716A0C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716A10: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716A14: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716A18: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716A1C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716A20: jr          $ra
    // 0x80716A24: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716A24: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80556700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80556700: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80556704: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80556708: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8055670C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80556710: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80556714: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80556718: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8055671C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80556720: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80556724: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80556728: lui         $t1, 0x8055
    ctx->r9 = S32(RELOC_HI16(357, 0X19B8) << 16);
    // 0x8055672C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80556730: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80556734: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80556738: lw          $t1, 0x68A8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(357, 0X19B8));
    // 0x8055673C: jr          $ra
    // 0x80556740: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80556740: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_806FBB60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FBB60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FBB64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FBB68: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806FBB6C: lw          $a1, 0x14AC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X14AC);
    // 0x806FBB70: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x806FBB74: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x806FBB78: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x806FBB7C: jal         0x806FBAE8
    // 0x806FBB80: addiu       $a0, $a0, 0x14A8
    ctx->r4 = ADD32(ctx->r4, 0X14A8);
    func_806FBAE8(rdram, ctx);
        goto after_0;
    // 0x806FBB80: addiu       $a0, $a0, 0x14A8
    ctx->r4 = ADD32(ctx->r4, 0X14A8);
    after_0:
    // 0x806FBB84: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806FBB88: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x806FBB8C: lwc1        $f4, 0x14A4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14A4);
    // 0x806FBB90: lwc1        $f6, 0x14A8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14A8);
    // 0x806FBB94: lw          $t6, 0x14BC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X14BC);
    // 0x806FBB98: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806FBB9C: bne         $t6, $zero, L_806FBBD8
    if (ctx->r14 != 0) {
        // 0x806FBBA0: swc1        $f8, 0x14A4($a3)
        MEM_W(0X14A4, ctx->r7) = ctx->f8.u32l;
            goto L_806FBBD8;
    }
    // 0x806FBBA0: swc1        $f8, 0x14A4($a3)
    MEM_W(0X14A4, ctx->r7) = ctx->f8.u32l;
    // 0x806FBBA4: lui         $at, 0x4346
    ctx->r1 = S32(0X4346 << 16);
    // 0x806FBBA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806FBBAC: lwc1        $f16, 0x14A4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14A4);
    // 0x806FBBB0: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x806FBBB4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806FBBB8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806FBBBC: nop

    // 0x806FBBC0: bc1fl       L_806FBC04
    if (!c1cs) {
        // 0x806FBBC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806FBC04;
    }
    goto skip_0;
    // 0x806FBBC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806FBBC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806FBBCC: sw          $t7, 0x14BC($a3)
    MEM_W(0X14BC, ctx->r7) = ctx->r15;
    // 0x806FBBD0: b           L_806FBC00
    // 0x806FBBD4: swc1        $f18, 0x14AC($a3)
    MEM_W(0X14AC, ctx->r7) = ctx->f18.u32l;
        goto L_806FBC00;
    // 0x806FBBD4: swc1        $f18, 0x14AC($a3)
    MEM_W(0X14AC, ctx->r7) = ctx->f18.u32l;
L_806FBBD8:
    // 0x806FBBD8: lwc1        $f4, 0x14A4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14A4);
    // 0x806FBBDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806FBBE0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806FBBE4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806FBBE8: nop

    // 0x806FBBEC: bc1fl       L_806FBC04
    if (!c1cs) {
        // 0x806FBBF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806FBC04;
    }
    goto skip_1;
    // 0x806FBBF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806FBBF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806FBBF8: sw          $zero, 0x14BC($a3)
    MEM_W(0X14BC, ctx->r7) = 0;
    // 0x806FBBFC: swc1        $f8, 0x14AC($a3)
    MEM_W(0X14AC, ctx->r7) = ctx->f8.u32l;
L_806FBC00:
    // 0x806FBC00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806FBC04:
    // 0x806FBC04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FBC08: jr          $ra
    // 0x806FBC0C: nop

    return;
    // 0x806FBC0C: nop

;}
RECOMP_FUNC void func_806DB648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DB648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DB64C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DB650: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806DB654: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x806DB658: lui         $t8, 0x806E
    ctx->r24 = S32(RELOC_HI16(634, 0X658) << 16);
    // 0x806DB65C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806DB660: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806DB664: lw          $t8, -0x44E8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(634, 0X658));
    // 0x806DB668: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806DB66C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x806DB670: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x806DB674: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x806DB678: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x806DB67C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x806DB680: beql        $v1, $zero, L_806DB6B4
    if (ctx->r3 == 0) {
        // 0x806DB684: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806DB6B4;
    }
    goto skip_0;
    // 0x806DB684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806DB688: jalr        $v1
    // 0x806DB68C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x806DB68C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806DB690: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806DB694: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x806DB698: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x806DB69C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x806DB6A0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x806DB6A4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x806DB6A8: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x806DB6AC: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x806DB6B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806DB6B4:
    // 0x806DB6B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DB6B8: jr          $ra
    // 0x806DB6BC: nop

    return;
    // 0x806DB6BC: nop

;}
RECOMP_FUNC void func_80525B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80525B4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80525B50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80525B54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80525B58: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80525B5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80525B60: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80525B64: jal         0x80062684
    // 0x80525B68: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x80525B68: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80525B6C: lh          $t7, 0x184($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X184);
    // 0x80525B70: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80525B74: beq         $t7, $zero, L_80525BC8
    if (ctx->r15 == 0) {
        // 0x80525B78: swc1        $f2, 0xC8($s0)
        MEM_W(0XC8, ctx->r16) = ctx->f2.u32l;
            goto L_80525BC8;
    }
    // 0x80525B78: swc1        $f2, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f2.u32l;
    // 0x80525B7C: jal         0x8004700C
    // 0x80525B80: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x80525B80: nop

    after_1:
    // 0x80525B84: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80525B88: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80525B8C: beq         $v0, $zero, L_80525C84
    if (ctx->r2 == 0) {
        // 0x80525B90: sh          $v1, 0x144($s0)
        MEM_H(0X144, ctx->r16) = ctx->r3;
            goto L_80525C84;
    }
    // 0x80525B90: sh          $v1, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r3;
    // 0x80525B94: lbu         $t8, 0x30($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X30);
    // 0x80525B98: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(324, 0X8F4) << 16);
    // 0x80525B9C: lwc1        $f6, 0xC4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x80525BA0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80525BA4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80525BA8: lwc1        $f4, 0x5E04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(324, 0X8F4));
    // 0x80525BAC: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80525BB0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80525BB4: nop

    // 0x80525BB8: bc1fl       L_80525C88
    if (!c1cs) {
        // 0x80525BBC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80525C88;
    }
    goto skip_0;
    // 0x80525BBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80525BC0: b           L_80525C84
    // 0x80525BC4: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
        goto L_80525C84;
    // 0x80525BC4: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
L_80525BC8:
    // 0x80525BC8: lh          $t0, 0x144($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X144);
    // 0x80525BCC: beq         $t0, $zero, L_80525C38
    if (ctx->r8 == 0) {
        // 0x80525BD0: nop
    
            goto L_80525C38;
    }
    // 0x80525BD0: nop

    // 0x80525BD4: lw          $t1, 0x180($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X180);
    // 0x80525BD8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80525BDC: lw          $v0, 0x1F4($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X1F4);
    // 0x80525BE0: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80525BE4: beql        $t2, $zero, L_80525C14
    if (ctx->r10 == 0) {
        // 0x80525BE8: lw          $t7, 0x0($t6)
        ctx->r15 = MEM_W(ctx->r14, 0X0);
            goto L_80525C14;
    }
    goto skip_1;
    // 0x80525BE8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    skip_1:
    // 0x80525BEC: swc1        $f2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f2.u32l;
    // 0x80525BF0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80525BF4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80525BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80525BFC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80525C00: jal         0x8005FDC4
    // 0x80525C04: sb          $t3, 0x75($t5)
    MEM_B(0X75, ctx->r13) = ctx->r11;
    func_8005FDC4(rdram, ctx);
        goto after_2;
    // 0x80525C04: sb          $t3, 0x75($t5)
    MEM_B(0X75, ctx->r13) = ctx->r11;
    after_2:
    // 0x80525C08: b           L_80525C84
    // 0x80525C0C: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
        goto L_80525C84;
    // 0x80525C0C: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x80525C10: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
L_80525C14:
    // 0x80525C14: lbu         $t8, 0x75($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X75);
    // 0x80525C18: beql        $t8, $zero, L_80525C88
    if (ctx->r24 == 0) {
        // 0x80525C1C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80525C88;
    }
    goto skip_2;
    // 0x80525C1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80525C20: jal         0x8005FE48
    // 0x80525C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_3;
    // 0x80525C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80525C28: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80525C2C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80525C30: b           L_80525C84
    // 0x80525C34: sb          $zero, 0x75($t0)
    MEM_B(0X75, ctx->r8) = 0;
        goto L_80525C84;
    // 0x80525C34: sb          $zero, 0x75($t0)
    MEM_B(0X75, ctx->r8) = 0;
L_80525C38:
    // 0x80525C38: jal         0x8004700C
    // 0x80525C3C: nop

    func_8004700C(rdram, ctx);
        goto after_4;
    // 0x80525C3C: nop

    after_4:
    // 0x80525C40: beql        $v0, $zero, L_80525C88
    if (ctx->r2 == 0) {
        // 0x80525C44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80525C88;
    }
    goto skip_3;
    // 0x80525C44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80525C48: lw          $t1, 0x174($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X174);
    // 0x80525C4C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80525C50: lbu         $t2, 0x10($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X10);
    // 0x80525C54: bnel        $v1, $t2, L_80525C88
    if (ctx->r3 != ctx->r10) {
        // 0x80525C58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80525C88;
    }
    goto skip_4;
    // 0x80525C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80525C5C: lw          $t4, 0x1F4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1F4);
    // 0x80525C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80525C64: lbu         $t3, 0xF4($t4)
    ctx->r11 = MEM_BU(ctx->r12, 0XF4);
    // 0x80525C68: beql        $t3, $zero, L_80525C88
    if (ctx->r11 == 0) {
        // 0x80525C6C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80525C88;
    }
    goto skip_5;
    // 0x80525C6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80525C70: jal         0x8005FE48
    // 0x80525C74: sh          $v1, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r3;
    func_8005FE48(rdram, ctx);
        goto after_5;
    // 0x80525C74: sh          $v1, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r3;
    after_5:
    // 0x80525C78: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80525C7C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80525C80: sb          $zero, 0x75($t6)
    MEM_B(0X75, ctx->r14) = 0;
L_80525C84:
    // 0x80525C84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80525C88:
    // 0x80525C88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80525C8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80525C90: jr          $ra
    // 0x80525C94: nop

    return;
    // 0x80525C94: nop

;}
RECOMP_FUNC void func_80006E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006E5C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80006E60: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x80006E64: lw          $t6, 0x1E9C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1E9C);
    // 0x80006E68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006E6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006E70: beq         $t6, $zero, L_80006E80
    if (ctx->r14 == 0) {
        // 0x80006E74: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_80006E80;
    }
    // 0x80006E74: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80006E78: b           L_80006EA4
    // 0x80006E7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80006EA4;
    // 0x80006E7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80006E80:
    // 0x80006E80: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80006E84: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80006E88: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80006E8C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80006E90: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80006E94: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80006E98: sw          $a3, 0x2B08($t8)
    MEM_W(0X2B08, ctx->r24) = ctx->r7;
    // 0x80006E9C: jal         0x80006EB4
    // 0x80006EA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80006EB4(rdram, ctx);
        goto after_0;
    // 0x80006EA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_80006EA4:
    // 0x80006EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006EAC: jr          $ra
    // 0x80006EB0: nop

    return;
    // 0x80006EB0: nop

;}
RECOMP_FUNC void func_8051B404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051B404: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(297, 0X8C) << 16);
    // 0x8051B408: addiu       $t6, $t6, -0x4C44
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(297, 0X8C));
    // 0x8051B40C: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8051B410: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x8051B414: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    // 0x8051B418: jr          $ra
    // 0x8051B41C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8051B41C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80472CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80472CD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80472CDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80472CE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80472CE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80472CE8: jal         0x80047090
    // 0x80472CEC: addiu       $a0, $zero, 0x4128
    ctx->r4 = ADD32(0, 0X4128);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80472CEC: addiu       $a0, $zero, 0x4128
    ctx->r4 = ADD32(0, 0X4128);
    after_0:
    // 0x80472CF0: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80472CF4: beq         $v0, $at, L_80472D88
    if (ctx->r2 == ctx->r1) {
        // 0x80472CF8: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80472D88;
    }
    // 0x80472CF8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80472CFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80472D00: lui         $at, 0x4128
    ctx->r1 = S32(0X4128 << 16);
    // 0x80472D04: ori         $at, $at, 0x4800
    ctx->r1 = ctx->r1 | 0X4800;
    // 0x80472D08: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x80472D0C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80472D10: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80472D14: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80472D18: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80472D1C: jal         0x8004613C
    // 0x80472D20: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80472D20: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    after_1:
    // 0x80472D24: lhu         $v1, 0x22($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X22);
    // 0x80472D28: beq         $v0, $zero, L_80472D88
    if (ctx->r2 == 0) {
        // 0x80472D2C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80472D88;
    }
    // 0x80472D2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80472D30: lhu         $t8, 0xE($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XE);
    // 0x80472D34: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x80472D38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80472D3C: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x80472D40: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80472D44: sh          $t0, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r8;
    // 0x80472D48: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80472D4C: lw          $t2, 0x138($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X138);
    // 0x80472D50: jal         0x80471818
    // 0x80472D54: sw          $t2, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r10;
    func_80471818(rdram, ctx);
        goto after_2;
    // 0x80472D54: sw          $t2, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r10;
    after_2:
    // 0x80472D58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80472D5C: jal         0x80047F9C
    // 0x80472D60: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x80472D60: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80472D64: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80472D68: lw          $t4, 0x1F4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1F4);
    // 0x80472D6C: sw          $s0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r16;
    // 0x80472D70: jal         0x804726F4
    // 0x80472D74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_804726F4(rdram, ctx);
        goto after_4;
    // 0x80472D74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80472D78: jal         0x8005FDC4
    // 0x80472D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_5;
    // 0x80472D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80472D80: b           L_80472D8C
    // 0x80472D84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80472D8C;
    // 0x80472D84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80472D88:
    // 0x80472D88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80472D8C:
    // 0x80472D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80472D90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80472D94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80472D98: jr          $ra
    // 0x80472D9C: nop

    return;
    // 0x80472D9C: nop

;}
RECOMP_FUNC void func_80041F58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041F58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80041F5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041F60: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
    // 0x80041F64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80041F68: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80041F6C: bnel        $v0, $at, L_80041F9C
    if (ctx->r2 != ctx->r1) {
        // 0x80041F70: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80041F9C;
    }
    goto skip_0;
    // 0x80041F70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x80041F74: lw          $t6, 0x90($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X90);
    // 0x80041F78: lw          $t8, 0x80($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X80);
    // 0x80041F7C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80041F80: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80041F84: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80041F88: jal         0x80041EC0
    // 0x80041F8C: lh          $a2, 0x0($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X0);
    func_80041EC0(rdram, ctx);
        goto after_0;
    // 0x80041F8C: lh          $a2, 0x0($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X0);
    after_0:
    // 0x80041F90: b           L_80041FDC
    // 0x80041F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80041FDC;
    // 0x80041F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041F98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80041F9C:
    // 0x80041F9C: bnel        $v0, $at, L_80041FDC
    if (ctx->r2 != ctx->r1) {
        // 0x80041FA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80041FDC;
    }
    goto skip_1;
    // 0x80041FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80041FA4: lw          $t1, 0x1F4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X1F4);
    // 0x80041FA8: beql        $t1, $zero, L_80041FDC
    if (ctx->r9 == 0) {
        // 0x80041FAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80041FDC;
    }
    goto skip_2;
    // 0x80041FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80041FB0: lw          $t2, 0x15C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X15C);
    // 0x80041FB4: lw          $t4, 0x14C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X14C);
    // 0x80041FB8: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80041FBC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80041FC0: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80041FC4: lh          $a2, 0x0($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X0);
    // 0x80041FC8: jal         0x80041EC0
    // 0x80041FCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80041EC0(rdram, ctx);
        goto after_1;
    // 0x80041FCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80041FD0: jal         0x80039338
    // 0x80041FD4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80039338(rdram, ctx);
        goto after_2;
    // 0x80041FD4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80041FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80041FDC:
    // 0x80041FDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80041FE0: jr          $ra
    // 0x80041FE4: nop

    return;
    // 0x80041FE4: nop

;}
RECOMP_FUNC void func_806AEFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AEFDC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806AEFE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AEFE4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806AEFE8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806AEFEC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x806AEFF0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x806AEFF4: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x806AEFF8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x806AEFFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806AF000: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x806AF004: bne         $t6, $at, L_806AF1F8
    if (ctx->r14 != ctx->r1) {
        // 0x806AF008: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_806AF1F8;
    }
    // 0x806AF008: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AF00C: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x806AF010: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806AF014: beq         $v0, $at, L_806AF164
    if (ctx->r2 == ctx->r1) {
        // 0x806AF018: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_806AF164;
    }
    // 0x806AF018: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x806AF01C: beq         $v0, $at, L_806AF164
    if (ctx->r2 == ctx->r1) {
        // 0x806AF020: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_806AF164;
    }
    // 0x806AF020: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x806AF024: beq         $v0, $at, L_806AF164
    if (ctx->r2 == ctx->r1) {
        // 0x806AF028: addiu       $a1, $zero, 0x5E
        ctx->r5 = ADD32(0, 0X5E);
            goto L_806AF164;
    }
    // 0x806AF028: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    // 0x806AF02C: jal         0x806ADD68
    // 0x806AF030: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_806ADD68(rdram, ctx);
        goto after_0;
    // 0x806AF030: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x806AF034: lw          $t7, 0x1E4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E4);
    // 0x806AF038: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x806AF03C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AF040: blez        $t7, L_806AF0FC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x806AF044: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_806AF0FC;
    }
    // 0x806AF044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AF048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AF04C: addiu       $a1, $zero, 0x284
    ctx->r5 = ADD32(0, 0X284);
    // 0x806AF050: jal         0x806ADE38
    // 0x806AF054: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_806ADE38(rdram, ctx);
        goto after_1;
    // 0x806AF054: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x806AF058: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806AF05C: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x806AF060: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806AF064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AF068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AF06C: jal         0x806AF64C
    // 0x806AF070: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_806AF64C(rdram, ctx);
        goto after_2;
    // 0x806AF070: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x806AF074: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x806AF078: lui         $t8, 0x806B
    ctx->r24 = S32(RELOC_HI16(595, 0XADC) << 16);
    // 0x806AF07C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x806AF080: addiu       $t8, $t8, -0x17E4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(595, 0XADC));
    // 0x806AF084: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
    // 0x806AF088: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806AF08C: lwc1        $f4, 0x84($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X84);
    // 0x806AF090: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806AF094: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x806AF098: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806AF09C: nop

    // 0x806AF0A0: bc1fl       L_806AF0C8
    if (!c1cs) {
        // 0x806AF0A4: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_806AF0C8;
    }
    goto skip_0;
    // 0x806AF0A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_0:
    // 0x806AF0A8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806AF0AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806AF0B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806AF0B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806AF0B8: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x806AF0BC: b           L_806AF0D8
    // 0x806AF0C0: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
        goto L_806AF0D8;
    // 0x806AF0C0: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    // 0x806AF0C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_806AF0C8:
    // 0x806AF0C8: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x806AF0CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806AF0D0: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x806AF0D4: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
L_806AF0D8:
    // 0x806AF0D8: lw          $t9, 0x1E4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1E4);
    // 0x806AF0DC: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1FA8) << 16);
    // 0x806AF0E0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x806AF0E4: sw          $t0, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r8;
    // 0x806AF0E8: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x806AF0EC: lwc1        $f6, -0x318($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1FA8));
    // 0x806AF0F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806AF0F4: b           L_806AF164
    // 0x806AF0F8: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
        goto L_806AF164;
    // 0x806AF0F8: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
L_806AF0FC:
    // 0x806AF0FC: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806AF100: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x806AF104: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x806AF108: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806AF10C: jal         0x806AF64C
    // 0x806AF110: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_806AF64C(rdram, ctx);
        goto after_3;
    // 0x806AF110: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_3:
    // 0x806AF114: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x806AF118: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x806AF11C: lui         $t1, 0x806B
    ctx->r9 = S32(RELOC_HI16(595, 0XA80) << 16);
    // 0x806AF120: addiu       $t1, $t1, -0x1840
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(595, 0XA80));
    // 0x806AF124: sw          $t1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r9;
    // 0x806AF128: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x806AF12C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806AF130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AF134: jal         0x806ADE38
    // 0x806AF138: addiu       $a1, $zero, 0x28D
    ctx->r5 = ADD32(0, 0X28D);
    func_806ADE38(rdram, ctx);
        goto after_4;
    // 0x806AF138: addiu       $a1, $zero, 0x28D
    ctx->r5 = ADD32(0, 0X28D);
    after_4:
    // 0x806AF13C: jal         0x80058B44
    // 0x806AF140: addiu       $a0, $zero, 0x4528
    ctx->r4 = ADD32(0, 0X4528);
    func_80058B44(rdram, ctx);
        goto after_5;
    // 0x806AF140: addiu       $a0, $zero, 0x4528
    ctx->r4 = ADD32(0, 0X4528);
    after_5:
    // 0x806AF144: beq         $v0, $zero, L_806AF164
    if (ctx->r2 == 0) {
        // 0x806AF148: addiu       $a0, $zero, 0x4528
        ctx->r4 = ADD32(0, 0X4528);
            goto L_806AF164;
    }
    // 0x806AF148: addiu       $a0, $zero, 0x4528
    ctx->r4 = ADD32(0, 0X4528);
    // 0x806AF14C: jal         0x80058C10
    // 0x806AF150: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80058C10(rdram, ctx);
        goto after_6;
    // 0x806AF150: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_6:
    // 0x806AF154: beq         $v0, $zero, L_806AF164
    if (ctx->r2 == 0) {
        // 0x806AF158: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_806AF164;
    }
    // 0x806AF158: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x806AF15C: jal         0x800447C8
    // 0x806AF160: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800447C8(rdram, ctx);
        goto after_7;
    // 0x806AF160: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_7:
L_806AF164:
    // 0x806AF164: lhu         $t2, 0xC($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XC);
    // 0x806AF168: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806AF16C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x806AF170: bnel        $t2, $at, L_806AF268
    if (ctx->r10 != ctx->r1) {
        // 0x806AF174: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806AF268;
    }
    goto skip_1;
    // 0x806AF174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806AF178: lw          $t9, 0x1C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C);
    // 0x806AF17C: sb          $t3, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r11;
    // 0x806AF180: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806AF184: jalr        $t9
    // 0x806AF188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x806AF188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x806AF18C: lwc1        $f10, 0x84($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X84);
    // 0x806AF190: lwc1        $f16, 0x84($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806AF194: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806AF198: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x806AF19C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806AF1A0: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x806AF1A4: bc1fl       L_806AF1C4
    if (!c1cs) {
        // 0x806AF1A8: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_806AF1C4;
    }
    goto skip_2;
    // 0x806AF1A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_2:
    // 0x806AF1AC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806AF1B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806AF1B4: addiu       $v0, $s1, 0xC4
    ctx->r2 = ADD32(ctx->r17, 0XC4);
    // 0x806AF1B8: b           L_806AF1CC
    // 0x806AF1BC: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
        goto L_806AF1CC;
    // 0x806AF1BC: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x806AF1C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_806AF1C4:
    // 0x806AF1C4: addiu       $v0, $s1, 0xC4
    ctx->r2 = ADD32(ctx->r17, 0XC4);
    // 0x806AF1C8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_806AF1CC:
    // 0x806AF1CC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806AF1D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806AF1D4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806AF1D8: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x806AF1DC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x806AF1E0: sb          $t4, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r12;
    // 0x806AF1E4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806AF1E8: sb          $t5, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r13;
    // 0x806AF1EC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806AF1F0: b           L_806AF264
    // 0x806AF1F4: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
        goto L_806AF264;
    // 0x806AF1F4: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
L_806AF1F8:
    // 0x806AF1F8: lhu         $t7, 0xC($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0XC);
    // 0x806AF1FC: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806AF200: bnel        $t7, $at, L_806AF268
    if (ctx->r15 != ctx->r1) {
        // 0x806AF204: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806AF268;
    }
    goto skip_3;
    // 0x806AF204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x806AF208: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x806AF20C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806AF210: beq         $v0, $at, L_806AF264
    if (ctx->r2 == ctx->r1) {
        // 0x806AF214: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_806AF264;
    }
    // 0x806AF214: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x806AF218: beq         $v0, $at, L_806AF264
    if (ctx->r2 == ctx->r1) {
        // 0x806AF21C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_806AF264;
    }
    // 0x806AF21C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x806AF220: beq         $v0, $at, L_806AF264
    if (ctx->r2 == ctx->r1) {
        // 0x806AF224: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806AF264;
    }
    // 0x806AF224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AF228: jal         0x806ADE38
    // 0x806AF22C: addiu       $a1, $zero, 0x28C
    ctx->r5 = ADD32(0, 0X28C);
    func_806ADE38(rdram, ctx);
        goto after_9;
    // 0x806AF22C: addiu       $a1, $zero, 0x28C
    ctx->r5 = ADD32(0, 0X28C);
    after_9:
    // 0x806AF230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AF234: jal         0x806ADD68
    // 0x806AF238: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    func_806ADD68(rdram, ctx);
        goto after_10;
    // 0x806AF238: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    after_10:
    // 0x806AF23C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806AF240: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x806AF244: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x806AF248: jal         0x8002F6E4
    // 0x806AF24C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_11;
    // 0x806AF24C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x806AF250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AF254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AF258: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806AF25C: jal         0x806AF64C
    // 0x806AF260: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806AF64C(rdram, ctx);
        goto after_12;
    // 0x806AF260: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_12:
L_806AF264:
    // 0x806AF264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806AF268:
    // 0x806AF268: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806AF26C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806AF270: jr          $ra
    // 0x806AF274: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x806AF274: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8002F364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F36C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002F370: lbu         $t7, 0x111($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X111);
    // 0x8002F374: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x8002F378: beq         $t7, $zero, L_8002F390
    if (ctx->r15 == 0) {
        // 0x8002F37C: nop
    
            goto L_8002F390;
    }
    // 0x8002F37C: nop

    // 0x8002F380: jal         0x8002F15C
    // 0x8002F384: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    func_8002F15C(rdram, ctx);
        goto after_0;
    // 0x8002F384: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_0:
    // 0x8002F388: b           L_8002F39C
    // 0x8002F38C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
        goto L_8002F39C;
    // 0x8002F38C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
L_8002F390:
    // 0x8002F390: jal         0x8002DBE4
    // 0x8002F394: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_1;
    // 0x8002F394: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x8002F398: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
L_8002F39C:
    // 0x8002F39C: sw          $zero, 0x1400($t8)
    MEM_W(0X1400, ctx->r24) = 0;
    // 0x8002F3A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F3A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002F3A8: jr          $ra
    // 0x8002F3AC: nop

    return;
    // 0x8002F3AC: nop

;}
RECOMP_FUNC void func_8045EDC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045EDC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045EDC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045EDCC: jal         0x8004700C
    // 0x8045EDD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8045EDD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045EDD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8045EDD8: beq         $v0, $zero, L_8045EE1C
    if (ctx->r2 == 0) {
        // 0x8045EDDC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8045EE1C;
    }
    // 0x8045EDDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8045EDE0: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045EDE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8045EDE8: jal         0x8045E3B8
    // 0x8045EDEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8045E3B8(rdram, ctx);
        goto after_1;
    // 0x8045EDEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8045EDF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8045EDF4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8045EDF8: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8045EDFC: bne         $t6, $zero, L_8045EE14
    if (ctx->r14 != 0) {
        // 0x8045EE00: nop
    
            goto L_8045EE14;
    }
    // 0x8045EE00: nop

    // 0x8045EE04: jal         0x8045E950
    // 0x8045EE08: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    func_8045E950(rdram, ctx);
        goto after_2;
    // 0x8045EE08: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    after_2:
    // 0x8045EE0C: b           L_8045EE20
    // 0x8045EE10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8045EE20;
    // 0x8045EE10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045EE14:
    // 0x8045EE14: jal         0x8045E490
    // 0x8045EE18: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    func_8045E490(rdram, ctx);
        goto after_3;
    // 0x8045EE18: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    after_3:
L_8045EE1C:
    // 0x8045EE1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045EE20:
    // 0x8045EE20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8045EE24: jr          $ra
    // 0x8045EE28: nop

    return;
    // 0x8045EE28: nop

;}
RECOMP_FUNC void func_805AA620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA620: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805AA624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AA628: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805AA62C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805AA630: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x805AA634: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x805AA638: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805AA63C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805AA640: jal         0x80062AEC
    // 0x805AA644: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x805AA644: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
    after_0:
    // 0x805AA648: lhu         $t8, 0x1E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1E);
    // 0x805AA64C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x805AA650: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805AA654: bne         $t8, $at, L_805AA668
    if (ctx->r24 != ctx->r1) {
        // 0x805AA658: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_805AA668;
    }
    // 0x805AA658: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x805AA65C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x805AA660: jal         0x8002F6E4
    // 0x805AA664: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x805AA664: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_805AA668:
    // 0x805AA668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AA66C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805AA670: jr          $ra
    // 0x805AA674: nop

    return;
    // 0x805AA674: nop

;}
RECOMP_FUNC void func_80068BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068BC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068BC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068BC8: jal         0x80072FF0
    // 0x80068BCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80072FF0(rdram, ctx);
        goto after_0;
    // 0x80068BCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80068BD0: jal         0x800689F0
    // 0x80068BD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800689F0(rdram, ctx);
        goto after_1;
    // 0x80068BD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80068BD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80068BDC: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80068BE0: addiu       $t6, $t6, -0x7A54
    ctx->r14 = ADD32(ctx->r14, -0X7A54);
    // 0x80068BE4: jal         0x80068B2C
    // 0x80068BE8: sw          $t6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r14;
    func_80068B2C(rdram, ctx);
        goto after_2;
    // 0x80068BE8: sw          $t6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r14;
    after_2:
    // 0x80068BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068BF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80068BF8: jr          $ra
    // 0x80068BFC: nop

    return;
    // 0x80068BFC: nop

;}
RECOMP_FUNC void func_8043F240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F240: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8043F244: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8043F248: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8043F24C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8043F250: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8043F254: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8043F258: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8043F25C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8043F260: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043F264: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8043F268: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8043F26C: addiu       $s1, $zero, 0x95
    ctx->r17 = ADD32(0, 0X95);
    // 0x8043F270: addiu       $s2, $zero, 0x168
    ctx->r18 = ADD32(0, 0X168);
    // 0x8043F274: addiu       $s0, $v0, 0x4
    ctx->r16 = ADD32(ctx->r2, 0X4);
L_8043F278:
    // 0x8043F278: jal         0x800653D8
    // 0x8043F27C: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8043F27C: nop

    after_0:
    // 0x8043F280: div         $zero, $v0, $s2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r18)));
    // 0x8043F284: mfhi        $t6
    ctx->r14 = hi;
    // 0x8043F288: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8043F28C: bne         $s2, $zero, L_8043F298
    if (ctx->r18 != 0) {
        // 0x8043F290: nop
    
            goto L_8043F298;
    }
    // 0x8043F290: nop

    // 0x8043F294: break       7
    do_break(2151936660);
L_8043F298:
    // 0x8043F298: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8043F29C: bne         $s2, $at, L_8043F2B0
    if (ctx->r18 != ctx->r1) {
        // 0x8043F2A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8043F2B0;
    }
    // 0x8043F2A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8043F2A4: bne         $v0, $at, L_8043F2B0
    if (ctx->r2 != ctx->r1) {
        // 0x8043F2A8: nop
    
            goto L_8043F2B0;
    }
    // 0x8043F2A8: nop

    // 0x8043F2AC: break       6
    do_break(2151936684);
L_8043F2B0:
    // 0x8043F2B0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8043F2B4: jal         0x80066E88
    // 0x8043F2B8: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8043F2B8: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    after_1:
    // 0x8043F2BC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8043F2C0: jal         0x80066DE4
    // 0x8043F2C4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8043F2C4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_2:
    // 0x8043F2C8: mul.s       $f6, $f24, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8043F2CC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8043F2D0: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
    // 0x8043F2D4: mul.s       $f8, $f24, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8043F2D8: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8043F2DC: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x8043F2E0: swc1        $f6, -0x20($s0)
    MEM_W(-0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8043F2E4: bgez        $s1, L_8043F278
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8043F2E8: swc1        $f8, -0x1C($s0)
        MEM_W(-0X1C, ctx->r16) = ctx->f8.u32l;
            goto L_8043F278;
    }
    // 0x8043F2E8: swc1        $f8, -0x1C($s0)
    MEM_W(-0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x8043F2EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8043F2F0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8043F2F4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8043F2F8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8043F2FC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8043F300: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8043F304: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8043F308: jr          $ra
    // 0x8043F30C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8043F30C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8044E964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044E964: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8044E968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044E96C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044E970: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x8044E974: slti        $at, $a1, 0x159
    ctx->r1 = SIGNED(ctx->r5) < 0X159 ? 1 : 0;
    // 0x8044E978: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8044E97C: lw          $a3, 0x6A94($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6A94);
    // 0x8044E980: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8044E984: bne         $at, $zero, L_8044E990
    if (ctx->r1 != 0) {
        // 0x8044E988: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8044E990;
    }
    // 0x8044E988: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8044E98C: addiu       $a2, $zero, 0x158
    ctx->r6 = ADD32(0, 0X158);
L_8044E990:
    // 0x8044E990: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8044E994: jal         0x8044BFA8
    // 0x8044E998: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_8044BFA8(rdram, ctx);
        goto after_0;
    // 0x8044E998: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x8044E99C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8044E9A0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8044E9A4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8044E9A8: jal         0x8006C56C
    // 0x8044E9AC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_8006C56C(rdram, ctx);
        goto after_1;
    // 0x8044E9AC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8044E9B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044E9B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8044E9B8: jr          $ra
    // 0x8044E9BC: nop

    return;
    // 0x8044E9BC: nop

;}
RECOMP_FUNC void func_80676DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80676DB0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80676DB4: bne         $a0, $zero, L_80676DC8
    if (ctx->r4 != 0) {
        // 0x80676DB8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80676DC8;
    }
    // 0x80676DB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80676DBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80676DC0: jr          $ra
    // 0x80676DC4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    return;
    // 0x80676DC4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80676DC8:
    // 0x80676DC8: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80676DCC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80676DD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80676DD4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80676DD8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80676DDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80676DE0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80676DE4: div.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80676DE8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80676DEC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80676DF0: bc1fl       L_80676E00
    if (!c1cs) {
        // 0x80676DF4: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80676E00;
    }
    goto skip_0;
    // 0x80676DF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80676DF8: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80676DFC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80676E00:
    // 0x80676E00: nop

    // 0x80676E04: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80676E08: nop

    // 0x80676E0C: bc1f        L_80676E18
    if (!c1cs) {
        // 0x80676E10: nop
    
            goto L_80676E18;
    }
    // 0x80676E10: nop

    // 0x80676E14: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80676E18:
    // 0x80676E18: jr          $ra
    // 0x80676E1C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80676E1C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_80714AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80714AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80714AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80714AB0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80714AB4: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80714AB8: lui         $t8, 0x8071
    ctx->r24 = S32(RELOC_HI16(730, 0X1520) << 16);
    // 0x80714ABC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80714AC0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80714AC4: lw          $t8, 0x5D40($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(730, 0X1520));
    // 0x80714AC8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80714ACC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80714AD0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80714AD4: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80714AD8: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80714ADC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80714AE0: beql        $v1, $zero, L_80714B14
    if (ctx->r3 == 0) {
        // 0x80714AE4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80714B14;
    }
    goto skip_0;
    // 0x80714AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80714AE8: jalr        $v1
    // 0x80714AEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80714AEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80714AF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80714AF4: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80714AF8: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80714AFC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80714B00: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80714B04: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80714B08: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80714B0C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80714B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80714B14:
    // 0x80714B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80714B18: jr          $ra
    // 0x80714B1C: nop

    return;
    // 0x80714B1C: nop

;}
RECOMP_FUNC void func_80015E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015E74: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80015E78: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80015E7C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80015E80: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80015E84: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80015E88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80015E8C: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x80015E90: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80015E94: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80015E98: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80015E9C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80015EA0: addiu       $t1, $t1, -0x5AD0
    ctx->r9 = ADD32(ctx->r9, -0X5AD0);
    // 0x80015EA4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80015EA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80015EAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80015EB0: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80015EB4: addiu       $t6, $zero, 0x3F
    ctx->r14 = ADD32(0, 0X3F);
    // 0x80015EB8: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80015EBC: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80015EC0: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80015EC4: sh          $t6, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r14;
    // 0x80015EC8: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x80015ECC: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
    // 0x80015ED0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80015ED4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80015ED8: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    // 0x80015EDC: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x80015EE0: jal         0x8001B8FC
    // 0x80015EE4: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    func_8001B8FC(rdram, ctx);
        goto after_0;
    // 0x80015EE4: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80015EE8: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80015EEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80015EF0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80015EF4: sltiu       $at, $t2, 0x78
    ctx->r1 = ctx->r10 < 0X78 ? 1 : 0;
    // 0x80015EF8: lh          $v1, 0x5E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X5E);
    // 0x80015EFC: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80015F00: beq         $at, $zero, L_80017380
    if (ctx->r1 == 0) {
        // 0x80015F04: lwc1        $f14, 0x68($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
            goto L_80017380;
    }
    // 0x80015F04: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80015F08: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80015F0C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80015F10: addu        $at, $at, $t2
    gpr jr_addend_80015F18 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80015F14: lw          $t2, -0x1508($at)
    ctx->r10 = ADD32(ctx->r1, -0X1508);
    // 0x80015F18: jr          $t2
    // 0x80015F1C: nop

    switch (jr_addend_80015F18 >> 2) {
        case 0: goto L_80017588; break;
        case 1: goto L_80015F20; break;
        case 2: goto L_80015F38; break;
        case 3: goto L_80015F58; break;
        case 4: goto L_80015F78; break;
        case 5: goto L_80015F90; break;
        case 6: goto L_80015FB0; break;
        case 7: goto L_80015FD0; break;
        case 8: goto L_80016024; break;
        case 9: goto L_80016040; break;
        case 10: goto L_8001605C; break;
        case 11: goto L_80016078; break;
        case 12: goto L_80016094; break;
        case 13: goto L_800160AC; break;
        case 14: goto L_800160C4; break;
        case 15: goto L_80016114; break;
        case 16: goto L_80016164; break;
        case 17: goto L_8001617C; break;
        case 18: goto L_80016194; break;
        case 19: goto L_800161FC; break;
        case 20: goto L_80016214; break;
        case 21: goto L_8001622C; break;
        case 22: goto L_80017588; break;
        case 23: goto L_80016244; break;
        case 24: goto L_8001625C; break;
        case 25: goto L_80016274; break;
        case 26: goto L_8001628C; break;
        case 27: goto L_800162A4; break;
        case 28: goto L_800162C4; break;
        case 29: goto L_80016304; break;
        case 30: goto L_80017588; break;
        case 31: goto L_8001631C; break;
        case 32: goto L_80016334; break;
        case 33: goto L_8001634C; break;
        case 34: goto L_80017588; break;
        case 35: goto L_80016364; break;
        case 36: goto L_80016378; break;
        case 37: goto L_80016390; break;
        case 38: goto L_800163A8; break;
        case 39: goto L_800163D4; break;
        case 40: goto L_80016418; break;
        case 41: goto L_80016430; break;
        case 42: goto L_80016448; break;
        case 43: goto L_80016498; break;
        case 44: goto L_800164F0; break;
        case 45: goto L_80016508; break;
        case 46: goto L_80016524; break;
        case 47: goto L_8001653C; break;
        case 48: goto L_800165A0; break;
        case 49: goto L_80017588; break;
        case 50: goto L_800165B8; break;
        case 51: goto L_8001667C; break;
        case 52: goto L_80016694; break;
        case 53: goto L_800166AC; break;
        case 54: goto L_800166C4; break;
        case 55: goto L_800166E4; break;
        case 56: goto L_800167D4; break;
        case 57: goto L_80016830; break;
        case 58: goto L_8001686C; break;
        case 59: goto L_800168BC; break;
        case 60: goto L_800168D4; break;
        case 61: goto L_800168EC; break;
        case 62: goto L_80016904; break;
        case 63: goto L_80016920; break;
        case 64: goto L_80016938; break;
        case 65: goto L_80016A34; break;
        case 66: goto L_80016A4C; break;
        case 67: goto L_80016A64; break;
        case 68: goto L_80016A7C; break;
        case 69: goto L_80016A94; break;
        case 70: goto L_80016B24; break;
        case 71: goto L_80017588; break;
        case 72: goto L_80017588; break;
        case 73: goto L_80016B58; break;
        case 74: goto L_80016B70; break;
        case 75: goto L_80016BC0; break;
        case 76: goto L_80016C18; break;
        case 77: goto L_80016C38; break;
        case 78: goto L_80016C54; break;
        case 79: goto L_80016C6C; break;
        case 80: goto L_80016C88; break;
        case 81: goto L_80016CE4; break;
        case 82: goto L_80016CFC; break;
        case 83: goto L_80016D4C; break;
        case 84: goto L_80016D64; break;
        case 85: goto L_80016D98; break;
        case 86: goto L_80016DE8; break;
        case 87: goto L_80016E58; break;
        case 88: goto L_80016E6C; break;
        case 89: goto L_80016EBC; break;
        case 90: goto L_80016EDC; break;
        case 91: goto L_80017588; break;
        case 92: goto L_80016EF4; break;
        case 93: goto L_80016F0C; break;
        case 94: goto L_80016F84; break;
        case 95: goto L_80016F9C; break;
        case 96: goto L_80016FB8; break;
        case 97: goto L_80016FD4; break;
        case 98: goto L_80016FEC; break;
        case 99: goto L_8001700C; break;
        case 100: goto L_80017024; break;
        case 101: goto L_8001703C; break;
        case 102: goto L_80017054; break;
        case 103: goto L_80017070; break;
        case 104: goto L_8001708C; break;
        case 105: goto L_800170A8; break;
        case 106: goto L_800170C4; break;
        case 107: goto L_80017114; break;
        case 108: goto L_80017128; break;
        case 109: goto L_8001713C; break;
        case 110: goto L_80017158; break;
        case 111: goto L_80017174; break;
        case 112: goto L_80017190; break;
        case 113: goto L_800171AC; break;
        case 114: goto L_800171C8; break;
        case 115: goto L_800171E4; break;
        case 116: goto L_80017230; break;
        case 117: goto L_80017248; break;
        case 118: goto L_800172A4; break;
        case 119: goto L_80017588; break;
        default: switch_error(__func__, 0x80015F18, 0x800AEAF8);
    }
    // 0x80015F1C: nop

L_80015F20:
    // 0x80015F20: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80015F24: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80015F28: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x80015F2C: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x80015F30: b           L_80017380
    // 0x80015F34: addiu       $s0, $zero, 0x3A
    ctx->r16 = ADD32(0, 0X3A);
        goto L_80017380;
    // 0x80015F34: addiu       $s0, $zero, 0x3A
    ctx->r16 = ADD32(0, 0X3A);
L_80015F38:
    // 0x80015F38: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80015F3C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80015F40: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80015F44: sh          $t7, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r15;
    // 0x80015F48: sh          $t6, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r14;
    // 0x80015F4C: sh          $t5, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r13;
    // 0x80015F50: b           L_80017380
    // 0x80015F54: addiu       $s0, $zero, 0x22
    ctx->r16 = ADD32(0, 0X22);
        goto L_80017380;
    // 0x80015F54: addiu       $s0, $zero, 0x22
    ctx->r16 = ADD32(0, 0X22);
L_80015F58:
    // 0x80015F58: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80015F5C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80015F60: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80015F64: sh          $t0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r8;
    // 0x80015F68: sh          $t9, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r25;
    // 0x80015F6C: sh          $t8, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r24;
    // 0x80015F70: b           L_80017380
    // 0x80015F74: addiu       $s0, $zero, 0x35
    ctx->r16 = ADD32(0, 0X35);
        goto L_80017380;
    // 0x80015F74: addiu       $s0, $zero, 0x35
    ctx->r16 = ADD32(0, 0X35);
L_80015F78:
    // 0x80015F78: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80015F7C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80015F80: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80015F84: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x80015F88: b           L_80017380
    // 0x80015F8C: addiu       $s0, $zero, 0x1AF
    ctx->r16 = ADD32(0, 0X1AF);
        goto L_80017380;
    // 0x80015F8C: addiu       $s0, $zero, 0x1AF
    ctx->r16 = ADD32(0, 0X1AF);
L_80015F90:
    // 0x80015F90: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80015F94: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80015F98: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80015F9C: sh          $t5, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r13;
    // 0x80015FA0: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x80015FA4: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x80015FA8: b           L_80017380
    // 0x80015FAC: addiu       $s0, $zero, 0x33
    ctx->r16 = ADD32(0, 0X33);
        goto L_80017380;
    // 0x80015FAC: addiu       $s0, $zero, 0x33
    ctx->r16 = ADD32(0, 0X33);
L_80015FB0:
    // 0x80015FB0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80015FB4: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80015FB8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80015FBC: sh          $t8, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r24;
    // 0x80015FC0: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
    // 0x80015FC4: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
    // 0x80015FC8: b           L_80017380
    // 0x80015FCC: addiu       $s0, $zero, 0x48
    ctx->r16 = ADD32(0, 0X48);
        goto L_80017380;
    // 0x80015FCC: addiu       $s0, $zero, 0x48
    ctx->r16 = ADD32(0, 0X48);
L_80015FD0:
    // 0x80015FD0: beq         $a2, $zero, L_8001600C
    if (ctx->r6 == 0) {
        // 0x80015FD4: addiu       $s0, $zero, 0x38
        ctx->r16 = ADD32(0, 0X38);
            goto L_8001600C;
    }
    // 0x80015FD4: addiu       $s0, $zero, 0x38
    ctx->r16 = ADD32(0, 0X38);
    // 0x80015FD8: lw          $t9, 0x14($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X14);
    // 0x80015FDC: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x80015FE0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80015FE4: addiu       $t0, $t9, -0x40
    ctx->r8 = ADD32(ctx->r25, -0X40);
    // 0x80015FE8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80015FEC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80015FF0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80015FF4: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80015FF8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80015FFC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80016000: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80016004: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80016008: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
L_8001600C:
    // 0x8001600C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80016010: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80016014: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80016018: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x8001601C: b           L_80017380
    // 0x80016020: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80016020: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80016024:
    // 0x80016024: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80016028: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8001602C: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x80016030: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x80016034: addiu       $s0, $zero, 0x5F
    ctx->r16 = ADD32(0, 0X5F);
    // 0x80016038: b           L_80017380
    // 0x8001603C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x8001603C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80016040:
    // 0x80016040: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80016044: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80016048: sh          $t6, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r14;
    // 0x8001604C: sh          $t5, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r13;
    // 0x80016050: addiu       $s0, $zero, 0x64
    ctx->r16 = ADD32(0, 0X64);
    // 0x80016054: b           L_80017380
    // 0x80016058: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80016058: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001605C:
    // 0x8001605C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80016060: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80016064: sh          $t8, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r24;
    // 0x80016068: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    // 0x8001606C: addiu       $s0, $zero, 0x65
    ctx->r16 = ADD32(0, 0X65);
    // 0x80016070: b           L_80017380
    // 0x80016074: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80016074: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80016078:
    // 0x80016078: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8001607C: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80016080: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
    // 0x80016084: sh          $t9, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r25;
    // 0x80016088: addiu       $s0, $zero, 0x1E5
    ctx->r16 = ADD32(0, 0X1E5);
    // 0x8001608C: b           L_80017380
    // 0x80016090: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80016090: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80016094:
    // 0x80016094: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80016098: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8001609C: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x800160A0: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x800160A4: b           L_80017380
    // 0x800160A8: addiu       $s0, $zero, 0x4B
    ctx->r16 = ADD32(0, 0X4B);
        goto L_80017380;
    // 0x800160A8: addiu       $s0, $zero, 0x4B
    ctx->r16 = ADD32(0, 0X4B);
L_800160AC:
    // 0x800160AC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800160B0: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x800160B4: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x800160B8: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x800160BC: b           L_80017380
    // 0x800160C0: addiu       $s0, $zero, 0x39
    ctx->r16 = ADD32(0, 0X39);
        goto L_80017380;
    // 0x800160C0: addiu       $s0, $zero, 0x39
    ctx->r16 = ADD32(0, 0X39);
L_800160C4:
    // 0x800160C4: beq         $a2, $zero, L_80016100
    if (ctx->r6 == 0) {
        // 0x800160C8: addiu       $s0, $zero, 0x49
        ctx->r16 = ADD32(0, 0X49);
            goto L_80016100;
    }
    // 0x800160C8: addiu       $s0, $zero, 0x49
    ctx->r16 = ADD32(0, 0X49);
    // 0x800160CC: lw          $t5, 0x14($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X14);
    // 0x800160D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800160D4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800160D8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800160DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800160E0: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800160E4: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800160E8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800160EC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800160F0: nop

    // 0x800160F4: mul.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x800160F8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800160FC: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
L_80016100:
    // 0x80016100: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80016104: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80016108: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
    // 0x8001610C: b           L_80017380
    // 0x80016110: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
        goto L_80017380;
    // 0x80016110: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
L_80016114:
    // 0x80016114: beq         $a2, $zero, L_80016150
    if (ctx->r6 == 0) {
        // 0x80016118: addiu       $s0, $zero, 0x3B
        ctx->r16 = ADD32(0, 0X3B);
            goto L_80016150;
    }
    // 0x80016118: addiu       $s0, $zero, 0x3B
    ctx->r16 = ADD32(0, 0X3B);
    // 0x8001611C: lw          $t8, 0x14($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X14);
    // 0x80016120: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016124: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80016128: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8001612C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80016130: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016134: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x80016138: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001613C: mul.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80016140: nop

    // 0x80016144: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80016148: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8001614C: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
L_80016150:
    // 0x80016150: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80016154: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80016158: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
    // 0x8001615C: b           L_80017380
    // 0x80016160: sh          $t9, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r25;
        goto L_80017380;
    // 0x80016160: sh          $t9, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r25;
L_80016164:
    // 0x80016164: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80016168: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8001616C: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80016170: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x80016174: b           L_80017380
    // 0x80016178: addiu       $s0, $zero, 0x6E
    ctx->r16 = ADD32(0, 0X6E);
        goto L_80017380;
    // 0x80016178: addiu       $s0, $zero, 0x6E
    ctx->r16 = ADD32(0, 0X6E);
L_8001617C:
    // 0x8001617C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80016180: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80016184: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x80016188: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x8001618C: b           L_80017380
    // 0x80016190: addiu       $s0, $zero, 0x49
    ctx->r16 = ADD32(0, 0X49);
        goto L_80017380;
    // 0x80016190: addiu       $s0, $zero, 0x49
    ctx->r16 = ADD32(0, 0X49);
L_80016194:
    // 0x80016194: beq         $a2, $zero, L_800161E8
    if (ctx->r6 == 0) {
        // 0x80016198: addiu       $s0, $zero, 0x4A
        ctx->r16 = ADD32(0, 0X4A);
            goto L_800161E8;
    }
    // 0x80016198: addiu       $s0, $zero, 0x4A
    ctx->r16 = ADD32(0, 0X4A);
    // 0x8001619C: lw          $t5, 0x14($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X14);
    // 0x800161A0: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x800161A4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800161A8: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800161AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800161B0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800161B4: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800161B8: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800161BC: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x800161C0: mul.d       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800161C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800161C8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800161CC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800161D0: add.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f0.d + ctx->f4.d;
    // 0x800161D4: add.d       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f10.d + ctx->f0.d;
    // 0x800161D8: mul.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x800161DC: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x800161E0: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x800161E4: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
L_800161E8:
    // 0x800161E8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800161EC: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800161F0: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
    // 0x800161F4: b           L_80017380
    // 0x800161F8: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
        goto L_80017380;
    // 0x800161F8: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
L_800161FC:
    // 0x800161FC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80016200: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80016204: sh          $t9, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r25;
    // 0x80016208: sh          $t8, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r24;
    // 0x8001620C: b           L_80017380
    // 0x80016210: addiu       $s0, $zero, 0x82
    ctx->r16 = ADD32(0, 0X82);
        goto L_80017380;
    // 0x80016210: addiu       $s0, $zero, 0x82
    ctx->r16 = ADD32(0, 0X82);
L_80016214:
    // 0x80016214: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80016218: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8001621C: sh          $t1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r9;
    // 0x80016220: sh          $t0, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r8;
    // 0x80016224: b           L_80017380
    // 0x80016228: addiu       $s0, $zero, 0x71
    ctx->r16 = ADD32(0, 0X71);
        goto L_80017380;
    // 0x80016228: addiu       $s0, $zero, 0x71
    ctx->r16 = ADD32(0, 0X71);
L_8001622C:
    // 0x8001622C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80016230: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80016234: addiu       $s0, $zero, 0x136
    ctx->r16 = ADD32(0, 0X136);
    // 0x80016238: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
    // 0x8001623C: b           L_80017380
    // 0x80016240: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80016240: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80016244:
    // 0x80016244: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80016248: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x8001624C: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x80016250: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x80016254: b           L_80017380
    // 0x80016258: addiu       $s0, $zero, 0x83
    ctx->r16 = ADD32(0, 0X83);
        goto L_80017380;
    // 0x80016258: addiu       $s0, $zero, 0x83
    ctx->r16 = ADD32(0, 0X83);
L_8001625C:
    // 0x8001625C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80016260: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80016264: sh          $t6, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r14;
    // 0x80016268: sh          $t5, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r13;
    // 0x8001626C: b           L_80017380
    // 0x80016270: addiu       $s0, $zero, 0x85
    ctx->r16 = ADD32(0, 0X85);
        goto L_80017380;
    // 0x80016270: addiu       $s0, $zero, 0x85
    ctx->r16 = ADD32(0, 0X85);
L_80016274:
    // 0x80016274: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80016278: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8001627C: sh          $t8, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r24;
    // 0x80016280: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    // 0x80016284: b           L_80017380
    // 0x80016288: addiu       $s0, $zero, 0x8A
    ctx->r16 = ADD32(0, 0X8A);
        goto L_80017380;
    // 0x80016288: addiu       $s0, $zero, 0x8A
    ctx->r16 = ADD32(0, 0X8A);
L_8001628C:
    // 0x8001628C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80016290: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80016294: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
    // 0x80016298: sh          $t9, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r25;
    // 0x8001629C: b           L_80017380
    // 0x800162A0: addiu       $s0, $zero, 0x8B
    ctx->r16 = ADD32(0, 0X8B);
        goto L_80017380;
    // 0x800162A0: addiu       $s0, $zero, 0x8B
    ctx->r16 = ADD32(0, 0X8B);
L_800162A4:
    // 0x800162A4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800162A8: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x800162AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800162B0: sh          $t3, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r11;
    // 0x800162B4: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x800162B8: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x800162BC: b           L_80017380
    // 0x800162C0: addiu       $s0, $zero, 0x42
    ctx->r16 = ADD32(0, 0X42);
        goto L_80017380;
    // 0x800162C0: addiu       $s0, $zero, 0x42
    ctx->r16 = ADD32(0, 0X42);
L_800162C4:
    // 0x800162C4: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800162C8: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x800162CC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800162D0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800162D4: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800162D8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800162DC: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x800162E0: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800162E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800162E8: sh          $t6, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r14;
    // 0x800162EC: sh          $t5, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r13;
    // 0x800162F0: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x800162F4: addiu       $s0, $zero, 0x153
    ctx->r16 = ADD32(0, 0X153);
    // 0x800162F8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800162FC: b           L_80017380
    // 0x80016300: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
        goto L_80017380;
    // 0x80016300: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
L_80016304:
    // 0x80016304: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80016308: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8001630C: sh          $t8, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r24;
    // 0x80016310: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    // 0x80016314: b           L_80017380
    // 0x80016318: addiu       $s0, $zero, 0x93
    ctx->r16 = ADD32(0, 0X93);
        goto L_80017380;
    // 0x80016318: addiu       $s0, $zero, 0x93
    ctx->r16 = ADD32(0, 0X93);
L_8001631C:
    // 0x8001631C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80016320: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80016324: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
    // 0x80016328: sh          $t9, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r25;
    // 0x8001632C: b           L_80017380
    // 0x80016330: addiu       $s0, $zero, 0x97
    ctx->r16 = ADD32(0, 0X97);
        goto L_80017380;
    // 0x80016330: addiu       $s0, $zero, 0x97
    ctx->r16 = ADD32(0, 0X97);
L_80016334:
    // 0x80016334: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80016338: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8001633C: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80016340: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x80016344: b           L_80017380
    // 0x80016348: addiu       $s0, $zero, 0x9B
    ctx->r16 = ADD32(0, 0X9B);
        goto L_80017380;
    // 0x80016348: addiu       $s0, $zero, 0x9B
    ctx->r16 = ADD32(0, 0X9B);
L_8001634C:
    // 0x8001634C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80016350: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80016354: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x80016358: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x8001635C: b           L_80017380
    // 0x80016360: addiu       $s0, $zero, 0x4C
    ctx->r16 = ADD32(0, 0X4C);
        goto L_80017380;
    // 0x80016360: addiu       $s0, $zero, 0x4C
    ctx->r16 = ADD32(0, 0X4C);
L_80016364:
    // 0x80016364: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80016368: sh          $t5, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r13;
    // 0x8001636C: addiu       $s0, $zero, 0x240
    ctx->r16 = ADD32(0, 0X240);
    // 0x80016370: b           L_80017380
    // 0x80016374: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
        goto L_80017380;
    // 0x80016374: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
L_80016378:
    // 0x80016378: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8001637C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80016380: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
    // 0x80016384: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
    // 0x80016388: b           L_80017380
    // 0x8001638C: addiu       $s0, $zero, 0xAF
    ctx->r16 = ADD32(0, 0XAF);
        goto L_80017380;
    // 0x8001638C: addiu       $s0, $zero, 0xAF
    ctx->r16 = ADD32(0, 0XAF);
L_80016390:
    // 0x80016390: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80016394: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80016398: sh          $t9, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r25;
    // 0x8001639C: sh          $t8, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r24;
    // 0x800163A0: b           L_80017380
    // 0x800163A4: addiu       $s0, $zero, 0xA5
    ctx->r16 = ADD32(0, 0XA5);
        goto L_80017380;
    // 0x800163A4: addiu       $s0, $zero, 0xA5
    ctx->r16 = ADD32(0, 0XA5);
L_800163A8:
    // 0x800163A8: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x800163AC: lbu         $t0, -0x6D78($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X6D78);
    // 0x800163B0: addiu       $s0, $zero, 0xBF
    ctx->r16 = ADD32(0, 0XBF);
    // 0x800163B4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800163B8: beq         $t0, $zero, L_800163C8
    if (ctx->r8 == 0) {
        // 0x800163BC: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_800163C8;
    }
    // 0x800163BC: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x800163C0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800163C4: nop

L_800163C8:
    // 0x800163C8: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x800163CC: b           L_80017380
    // 0x800163D0: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
        goto L_80017380;
    // 0x800163D0: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
L_800163D4:
    // 0x800163D4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x800163D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800163DC: sh          $v1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r3;
    // 0x800163E0: jal         0x80011928
    // 0x800163E4: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    func_80011928(rdram, ctx);
        goto after_1;
    // 0x800163E4: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x800163E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800163EC: lh          $v1, 0x5E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X5E);
    // 0x800163F0: beq         $v0, $at, L_80016400
    if (ctx->r2 == ctx->r1) {
        // 0x800163F4: lwc1        $f14, 0x68($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
            goto L_80016400;
    }
    // 0x800163F4: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800163F8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800163FC: nop

L_80016400:
    // 0x80016400: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80016404: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80016408: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x8001640C: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x80016410: b           L_80017380
    // 0x80016414: addiu       $s0, $zero, 0x56
    ctx->r16 = ADD32(0, 0X56);
        goto L_80017380;
    // 0x80016414: addiu       $s0, $zero, 0x56
    ctx->r16 = ADD32(0, 0X56);
L_80016418:
    // 0x80016418: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x8001641C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80016420: sh          $t6, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r14;
    // 0x80016424: sh          $t5, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r13;
    // 0x80016428: b           L_80017380
    // 0x8001642C: addiu       $s0, $zero, 0x59
    ctx->r16 = ADD32(0, 0X59);
        goto L_80017380;
    // 0x8001642C: addiu       $s0, $zero, 0x59
    ctx->r16 = ADD32(0, 0X59);
L_80016430:
    // 0x80016430: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80016434: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80016438: sh          $t8, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r24;
    // 0x8001643C: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    // 0x80016440: b           L_80017380
    // 0x80016444: addiu       $s0, $zero, 0xC5
    ctx->r16 = ADD32(0, 0XC5);
        goto L_80017380;
    // 0x80016444: addiu       $s0, $zero, 0xC5
    ctx->r16 = ADD32(0, 0XC5);
L_80016448:
    // 0x80016448: beq         $a2, $zero, L_80016484
    if (ctx->r6 == 0) {
        // 0x8001644C: addiu       $s0, $zero, 0xD7
        ctx->r16 = ADD32(0, 0XD7);
            goto L_80016484;
    }
    // 0x8001644C: addiu       $s0, $zero, 0xD7
    ctx->r16 = ADD32(0, 0XD7);
    // 0x80016450: lw          $t9, 0x14($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X14);
    // 0x80016454: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016458: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8001645C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80016460: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80016464: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016468: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x8001646C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80016470: mul.d       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80016474: nop

    // 0x80016478: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8001647C: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80016480: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
L_80016484:
    // 0x80016484: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80016488: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8001648C: sh          $t1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r9;
    // 0x80016490: b           L_80017380
    // 0x80016494: sh          $t0, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r8;
        goto L_80017380;
    // 0x80016494: sh          $t0, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r8;
L_80016498:
    // 0x80016498: beq         $a2, $zero, L_800164DC
    if (ctx->r6 == 0) {
        // 0x8001649C: addiu       $s0, $zero, 0x1A2
        ctx->r16 = ADD32(0, 0X1A2);
            goto L_800164DC;
    }
    // 0x8001649C: addiu       $s0, $zero, 0x1A2
    ctx->r16 = ADD32(0, 0X1A2);
    // 0x800164A0: lw          $t2, 0x14($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X14);
    // 0x800164A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800164A8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800164AC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800164B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800164B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800164B8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800164BC: ldc1        $f8, -0x1328($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1328);
    // 0x800164C0: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800164C4: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800164C8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800164CC: add.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f18.d + ctx->f8.d;
    // 0x800164D0: mul.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x800164D4: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800164D8: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
L_800164DC:
    // 0x800164DC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800164E0: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x800164E4: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x800164E8: b           L_80017380
    // 0x800164EC: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
        goto L_80017380;
    // 0x800164EC: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
L_800164F0:
    // 0x800164F0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800164F4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800164F8: sh          $t6, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r14;
    // 0x800164FC: sh          $t5, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r13;
    // 0x80016500: b           L_80017380
    // 0x80016504: addiu       $s0, $zero, 0x100
    ctx->r16 = ADD32(0, 0X100);
        goto L_80017380;
    // 0x80016504: addiu       $s0, $zero, 0x100
    ctx->r16 = ADD32(0, 0X100);
L_80016508:
    // 0x80016508: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8001650C: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80016510: sh          $t8, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r24;
    // 0x80016514: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    // 0x80016518: addiu       $s0, $zero, 0x10A
    ctx->r16 = ADD32(0, 0X10A);
    // 0x8001651C: b           L_80017380
    // 0x80016520: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80016520: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80016524:
    // 0x80016524: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x80016528: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8001652C: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
    // 0x80016530: sh          $t9, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r25;
    // 0x80016534: b           L_80017380
    // 0x80016538: addiu       $s0, $zero, 0x126
    ctx->r16 = ADD32(0, 0X126);
        goto L_80017380;
    // 0x80016538: addiu       $s0, $zero, 0x126
    ctx->r16 = ADD32(0, 0X126);
L_8001653C:
    // 0x8001653C: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80016540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80016544: sh          $v1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r3;
    // 0x80016548: jal         0x80011928
    // 0x8001654C: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    func_80011928(rdram, ctx);
        goto after_2;
    // 0x8001654C: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x80016550: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80016554: lh          $v1, 0x5E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X5E);
    // 0x80016558: bne         $v0, $at, L_80016580
    if (ctx->r2 != ctx->r1) {
        // 0x8001655C: lwc1        $f14, 0x68($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
            goto L_80016580;
    }
    // 0x8001655C: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80016560: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016564: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80016568: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8001656C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80016570: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80016574: mul.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80016578: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8001657C: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
L_80016580:
    // 0x80016580: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80016584: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80016588: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001658C: sh          $t3, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r11;
    // 0x80016590: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80016594: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x80016598: b           L_80017380
    // 0x8001659C: addiu       $s0, $zero, 0x136
    ctx->r16 = ADD32(0, 0X136);
        goto L_80017380;
    // 0x8001659C: addiu       $s0, $zero, 0x136
    ctx->r16 = ADD32(0, 0X136);
L_800165A0:
    // 0x800165A0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800165A4: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800165A8: sh          $t5, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r13;
    // 0x800165AC: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x800165B0: b           L_80017380
    // 0x800165B4: addiu       $s0, $zero, 0x146
    ctx->r16 = ADD32(0, 0X146);
        goto L_80017380;
    // 0x800165B4: addiu       $s0, $zero, 0x146
    ctx->r16 = ADD32(0, 0X146);
L_800165B8:
    // 0x800165B8: beql        $a2, $zero, L_80016664
    if (ctx->r6 == 0) {
        // 0x800165BC: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_80016664;
    }
    goto skip_0;
    // 0x800165BC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    skip_0:
    // 0x800165C0: lw          $t6, 0x14($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X14);
    // 0x800165C4: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x800165C8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800165CC: jal         0x80011CF0
    // 0x800165D0: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    func_80011CF0(rdram, ctx);
        goto after_3;
    // 0x800165D0: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    after_3:
    // 0x800165D4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800165D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800165DC: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800165E0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x800165E4: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x800165E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800165EC: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800165F0: bc1f        L_80016644
    if (!c1cs) {
        // 0x800165F4: nop
    
            goto L_80016644;
    }
    // 0x800165F4: nop

    // 0x800165F8: lh          $t7, -0x6D4C($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6D4C);
    // 0x800165FC: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x80016600: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80016604: jal         0x80011CF0
    // 0x80016608: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_80011CF0(rdram, ctx);
        goto after_4;
    // 0x80016608: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_4:
    // 0x8001660C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80016610: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016614: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80016618: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001661C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80016620: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80016624: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80016628: bc1fl       L_80016658
    if (!c1cs) {
        // 0x8001662C: lw          $t8, 0x14($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X14);
            goto L_80016658;
    }
    goto skip_1;
    // 0x8001662C: lw          $t8, 0x14($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X14);
    skip_1:
    // 0x80016630: jal         0x80015E74
    // 0x80016634: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    func_80015E74(rdram, ctx);
        goto after_5;
    // 0x80016634: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x80016638: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8001663C: b           L_80016654
    // 0x80016640: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
        goto L_80016654;
    // 0x80016640: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
L_80016644:
    // 0x80016644: jal         0x80011990
    // 0x80016648: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    func_80011990(rdram, ctx);
        goto after_6;
    // 0x80016648: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_6:
    // 0x8001664C: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80016650: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
L_80016654:
    // 0x80016654: lw          $t8, 0x14($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X14);
L_80016658:
    // 0x80016658: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001665C: sh          $t8, -0x6D4C($at)
    MEM_H(-0X6D4C, ctx->r1) = ctx->r24;
    // 0x80016660: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80016664:
    // 0x80016664: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80016668: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
    // 0x8001666C: sh          $t9, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r25;
    // 0x80016670: addiu       $s0, $zero, 0x250
    ctx->r16 = ADD32(0, 0X250);
    // 0x80016674: b           L_80017380
    // 0x80016678: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80016678: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001667C:
    // 0x8001667C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80016680: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80016684: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80016688: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x8001668C: b           L_80017380
    // 0x80016690: addiu       $s0, $zero, 0x262
    ctx->r16 = ADD32(0, 0X262);
        goto L_80017380;
    // 0x80016690: addiu       $s0, $zero, 0x262
    ctx->r16 = ADD32(0, 0X262);
L_80016694:
    // 0x80016694: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80016698: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x8001669C: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x800166A0: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x800166A4: b           L_80017380
    // 0x800166A8: addiu       $s0, $zero, 0x263
    ctx->r16 = ADD32(0, 0X263);
        goto L_80017380;
    // 0x800166A8: addiu       $s0, $zero, 0x263
    ctx->r16 = ADD32(0, 0X263);
L_800166AC:
    // 0x800166AC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800166B0: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800166B4: sh          $t6, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r14;
    // 0x800166B8: sh          $t5, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r13;
    // 0x800166BC: b           L_80017380
    // 0x800166C0: addiu       $s0, $zero, 0x12F
    ctx->r16 = ADD32(0, 0X12F);
        goto L_80017380;
    // 0x800166C0: addiu       $s0, $zero, 0x12F
    ctx->r16 = ADD32(0, 0X12F);
L_800166C4:
    // 0x800166C4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800166C8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800166CC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800166D0: sh          $t9, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r25;
    // 0x800166D4: sh          $t8, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r24;
    // 0x800166D8: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    // 0x800166DC: b           L_80017380
    // 0x800166E0: addiu       $s0, $zero, 0x168
    ctx->r16 = ADD32(0, 0X168);
        goto L_80017380;
    // 0x800166E0: addiu       $s0, $zero, 0x168
    ctx->r16 = ADD32(0, 0X168);
L_800166E4:
    // 0x800166E4: beql        $a2, $zero, L_800167BC
    if (ctx->r6 == 0) {
        // 0x800166E8: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_800167BC;
    }
    goto skip_2;
    // 0x800166E8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    skip_2:
    // 0x800166EC: lw          $t0, 0x14($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X14);
    // 0x800166F0: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x800166F4: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800166F8: jal         0x80011CF0
    // 0x800166FC: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    func_80011CF0(rdram, ctx);
        goto after_7;
    // 0x800166FC: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_7:
    // 0x80016700: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80016704: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80016708: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8001670C: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80016710: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80016714: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80016718: bc1fl       L_8001676C
    if (!c1cs) {
        // 0x8001671C: lw          $t2, 0x14($a2)
        ctx->r10 = MEM_W(ctx->r6, 0X14);
            goto L_8001676C;
    }
    goto skip_3;
    // 0x8001671C: lw          $t2, 0x14($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X14);
    skip_3:
    // 0x80016720: lh          $t1, -0x6D48($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X6D48);
    // 0x80016724: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x80016728: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8001672C: jal         0x80011CF0
    // 0x80016730: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    func_80011CF0(rdram, ctx);
        goto after_8;
    // 0x80016730: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    after_8:
    // 0x80016734: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80016738: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001673C: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80016740: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80016744: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80016748: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    // 0x8001674C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80016750: bc1fl       L_8001676C
    if (!c1cs) {
        // 0x80016754: lw          $t2, 0x14($a2)
        ctx->r10 = MEM_W(ctx->r6, 0X14);
            goto L_8001676C;
    }
    goto skip_4;
    // 0x80016754: lw          $t2, 0x14($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X14);
    skip_4:
    // 0x80016758: jal         0x80011D1C
    // 0x8001675C: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    func_80011D1C(rdram, ctx);
        goto after_9;
    // 0x8001675C: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_9:
    // 0x80016760: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80016764: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80016768: lw          $t2, 0x14($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X14);
L_8001676C:
    // 0x8001676C: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x80016770: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80016774: jal         0x80011CF0
    // 0x80016778: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_80011CF0(rdram, ctx);
        goto after_10;
    // 0x80016778: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_10:
    // 0x8001677C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80016780: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016784: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80016788: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001678C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80016790: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80016794: bc1fl       L_800167B0
    if (!c1cs) {
        // 0x80016798: lw          $t3, 0x14($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X14);
            goto L_800167B0;
    }
    goto skip_5;
    // 0x80016798: lw          $t3, 0x14($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X14);
    skip_5:
    // 0x8001679C: jal         0x80010A74
    // 0x800167A0: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    func_80010A74(rdram, ctx);
        goto after_11;
    // 0x800167A0: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_11:
    // 0x800167A4: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x800167A8: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800167AC: lw          $t3, 0x14($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X14);
L_800167B0:
    // 0x800167B0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800167B4: sh          $t3, -0x6D48($at)
    MEM_H(-0X6D48, ctx->r1) = ctx->r11;
    // 0x800167B8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_800167BC:
    // 0x800167BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800167C0: sh          $t5, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r13;
    // 0x800167C4: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x800167C8: addiu       $s0, $zero, 0x250
    ctx->r16 = ADD32(0, 0X250);
    // 0x800167CC: b           L_80017380
    // 0x800167D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x800167D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800167D4:
    // 0x800167D4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x800167D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800167DC: sh          $v1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r3;
    // 0x800167E0: jal         0x80011928
    // 0x800167E4: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    func_80011928(rdram, ctx);
        goto after_12;
    // 0x800167E4: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_12:
    // 0x800167E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800167EC: lh          $v1, 0x5E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X5E);
    // 0x800167F0: bne         $v0, $at, L_80016818
    if (ctx->r2 != ctx->r1) {
        // 0x800167F4: lwc1        $f14, 0x68($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
            goto L_80016818;
    }
    // 0x800167F4: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800167F8: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800167FC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80016800: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80016804: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80016808: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8001680C: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80016810: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80016814: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
L_80016818:
    // 0x80016818: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x8001681C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80016820: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
    // 0x80016824: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
    // 0x80016828: b           L_80017380
    // 0x8001682C: addiu       $s0, $zero, 0x19E
    ctx->r16 = ADD32(0, 0X19E);
        goto L_80017380;
    // 0x8001682C: addiu       $s0, $zero, 0x19E
    ctx->r16 = ADD32(0, 0X19E);
L_80016830:
    // 0x80016830: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016834: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80016838: ldc1        $f10, -0x1320($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1320);
    // 0x8001683C: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80016840: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80016844: mul.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80016848: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8001684C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80016850: sh          $t0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r8;
    // 0x80016854: sh          $t9, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r25;
    // 0x80016858: sh          $t8, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r24;
    // 0x8001685C: addiu       $s0, $zero, 0x82
    ctx->r16 = ADD32(0, 0X82);
    // 0x80016860: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x80016864: b           L_80017380
    // 0x80016868: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
        goto L_80017380;
    // 0x80016868: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
L_8001686C:
    // 0x8001686C: beq         $a2, $zero, L_800168A8
    if (ctx->r6 == 0) {
        // 0x80016870: addiu       $s0, $zero, 0x49
        ctx->r16 = ADD32(0, 0X49);
            goto L_800168A8;
    }
    // 0x80016870: addiu       $s0, $zero, 0x49
    ctx->r16 = ADD32(0, 0X49);
    // 0x80016874: lw          $t1, 0x14($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X14);
    // 0x80016878: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001687C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80016880: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80016884: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80016888: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8001688C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80016890: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80016894: mul.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80016898: nop

    // 0x8001689C: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800168A0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800168A4: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
L_800168A8:
    // 0x800168A8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800168AC: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800168B0: sh          $t3, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r11;
    // 0x800168B4: b           L_80017380
    // 0x800168B8: sh          $t2, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r10;
        goto L_80017380;
    // 0x800168B8: sh          $t2, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r10;
L_800168BC:
    // 0x800168BC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800168C0: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x800168C4: sh          $t5, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r13;
    // 0x800168C8: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x800168CC: b           L_80017380
    // 0x800168D0: addiu       $s0, $zero, 0x1E6
    ctx->r16 = ADD32(0, 0X1E6);
        goto L_80017380;
    // 0x800168D0: addiu       $s0, $zero, 0x1E6
    ctx->r16 = ADD32(0, 0X1E6);
L_800168D4:
    // 0x800168D4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800168D8: sh          $t6, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r14;
    // 0x800168DC: addiu       $s0, $zero, 0x128
    ctx->r16 = ADD32(0, 0X128);
    // 0x800168E0: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
    // 0x800168E4: b           L_80017380
    // 0x800168E8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x800168E8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800168EC:
    // 0x800168EC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800168F0: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
    // 0x800168F4: addiu       $s0, $zero, 0x1A6
    ctx->r16 = ADD32(0, 0X1A6);
    // 0x800168F8: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
    // 0x800168FC: b           L_80017380
    // 0x80016900: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80016900: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80016904:
    // 0x80016904: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80016908: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x8001690C: sh          $t9, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r25;
    // 0x80016910: sh          $t8, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r24;
    // 0x80016914: addiu       $s0, $zero, 0x154
    ctx->r16 = ADD32(0, 0X154);
    // 0x80016918: b           L_80017380
    // 0x8001691C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x8001691C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80016920:
    // 0x80016920: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80016924: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80016928: sh          $t1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r9;
    // 0x8001692C: sh          $t0, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r8;
    // 0x80016930: b           L_80017380
    // 0x80016934: addiu       $s0, $zero, 0x1B1
    ctx->r16 = ADD32(0, 0X1B1);
        goto L_80017380;
    // 0x80016934: addiu       $s0, $zero, 0x1B1
    ctx->r16 = ADD32(0, 0X1B1);
L_80016938:
    // 0x80016938: beql        $a2, $zero, L_80016A1C
    if (ctx->r6 == 0) {
        // 0x8001693C: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_80016A1C;
    }
    goto skip_6;
    // 0x8001693C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    skip_6:
    // 0x80016940: lw          $t2, 0x14($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X14);
    // 0x80016944: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x80016948: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8001694C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80016950: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016954: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80016958: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8001695C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80016960: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016964: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80016968: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001696C: mul.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80016970: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80016974: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80016978: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8001697C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80016980: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x80016984: lw          $t3, 0x14($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X14);
    // 0x80016988: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8001698C: nop

    // 0x80016990: cvt.d.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.d = CVT_D_W(ctx->f8.u32l);
    // 0x80016994: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x80016998: nop

    // 0x8001699C: bc1fl       L_80016A1C
    if (!c1cs) {
        // 0x800169A0: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_80016A1C;
    }
    goto skip_7;
    // 0x800169A0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    skip_7:
    // 0x800169A4: lw          $v0, 0x6BA4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6BA4);
    // 0x800169A8: ldc1        $f10, -0x1318($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1318);
    // 0x800169AC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800169B0: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x800169B4: sub.d       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f2.d - ctx->f0.d;
    // 0x800169B8: mfhi        $t5
    ctx->r13 = hi;
    // 0x800169BC: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x800169C0: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x800169C4: div.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f2.d);
    // 0x800169C8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800169CC: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800169D0: trunc.w.d   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_D(ctx->f16.d);
    // 0x800169D4: bne         $t5, $at, L_800169F0
    if (ctx->r13 != ctx->r1) {
        // 0x800169D8: swc1        $f18, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
            goto L_800169F0;
    }
    // 0x800169D8: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x800169DC: jal         0x80011D1C
    // 0x800169E0: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    func_80011D1C(rdram, ctx);
        goto after_13;
    // 0x800169E0: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_13:
    // 0x800169E4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800169E8: lw          $v0, 0x6BA4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6BA4);
    // 0x800169EC: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
L_800169F0:
    // 0x800169F0: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x800169F4: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x800169F8: mfhi        $t6
    ctx->r14 = hi;
    // 0x800169FC: addiu       $at, $zero, 0xC7
    ctx->r1 = ADD32(0, 0XC7);
    // 0x80016A00: bne         $t6, $at, L_80016A18
    if (ctx->r14 != ctx->r1) {
        // 0x80016A04: addiu       $a0, $zero, 0xD3
        ctx->r4 = ADD32(0, 0XD3);
            goto L_80016A18;
    }
    // 0x80016A04: addiu       $a0, $zero, 0xD3
    ctx->r4 = ADD32(0, 0XD3);
    // 0x80016A08: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80016A0C: jal         0x80011D1C
    // 0x80016A10: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    func_80011D1C(rdram, ctx);
        goto after_14;
    // 0x80016A10: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_14:
    // 0x80016A14: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
L_80016A18:
    // 0x80016A18: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
L_80016A1C:
    // 0x80016A1C: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80016A20: sh          $t8, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r24;
    // 0x80016A24: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    // 0x80016A28: addiu       $s0, $zero, 0x241
    ctx->r16 = ADD32(0, 0X241);
    // 0x80016A2C: b           L_80017380
    // 0x80016A30: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80016A30: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80016A34:
    // 0x80016A34: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80016A38: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80016A3C: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
    // 0x80016A40: sh          $t9, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r25;
    // 0x80016A44: b           L_80017380
    // 0x80016A48: addiu       $s0, $zero, 0x1D8
    ctx->r16 = ADD32(0, 0X1D8);
        goto L_80017380;
    // 0x80016A48: addiu       $s0, $zero, 0x1D8
    ctx->r16 = ADD32(0, 0X1D8);
L_80016A4C:
    // 0x80016A4C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80016A50: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80016A54: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80016A58: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x80016A5C: b           L_80017380
    // 0x80016A60: addiu       $s0, $zero, 0x1D9
    ctx->r16 = ADD32(0, 0X1D9);
        goto L_80017380;
    // 0x80016A60: addiu       $s0, $zero, 0x1D9
    ctx->r16 = ADD32(0, 0X1D9);
L_80016A64:
    // 0x80016A64: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80016A68: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80016A6C: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x80016A70: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x80016A74: b           L_80017380
    // 0x80016A78: addiu       $s0, $zero, 0x1DB
    ctx->r16 = ADD32(0, 0X1DB);
        goto L_80017380;
    // 0x80016A78: addiu       $s0, $zero, 0x1DB
    ctx->r16 = ADD32(0, 0X1DB);
L_80016A7C:
    // 0x80016A7C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80016A80: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80016A84: sh          $t6, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r14;
    // 0x80016A88: sh          $t5, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r13;
    // 0x80016A8C: b           L_80017380
    // 0x80016A90: addiu       $s0, $zero, 0x1DA
    ctx->r16 = ADD32(0, 0X1DA);
        goto L_80017380;
    // 0x80016A90: addiu       $s0, $zero, 0x1DA
    ctx->r16 = ADD32(0, 0X1DA);
L_80016A94:
    // 0x80016A94: beq         $a2, $zero, L_80016B10
    if (ctx->r6 == 0) {
        // 0x80016A98: addiu       $s0, $zero, 0x1BD
        ctx->r16 = ADD32(0, 0X1BD);
            goto L_80016B10;
    }
    // 0x80016A98: addiu       $s0, $zero, 0x1BD
    ctx->r16 = ADD32(0, 0X1BD);
    // 0x80016A9C: lw          $t7, 0x14($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X14);
    // 0x80016AA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016AA4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80016AA8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80016AAC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80016AB0: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016AB4: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x80016AB8: lui         $at, 0x3F60
    ctx->r1 = S32(0X3F60 << 16);
    // 0x80016ABC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80016AC0: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80016AC4: nop

    // 0x80016AC8: mul.d       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x80016ACC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80016AD0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80016AD4: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x80016AD8: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80016ADC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80016AE0: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x80016AE4: lw          $t8, 0x18($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X18);
    // 0x80016AE8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80016AEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80016AF0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80016AF4: nop

    // 0x80016AF8: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80016AFC: mul.d       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x80016B00: add.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d + ctx->f4.d;
    // 0x80016B04: mul.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80016B08: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x80016B0C: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
L_80016B10:
    // 0x80016B10: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80016B14: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80016B18: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
    // 0x80016B1C: b           L_80017380
    // 0x80016B20: sh          $t9, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r25;
        goto L_80017380;
    // 0x80016B20: sh          $t9, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r25;
L_80016B24:
    // 0x80016B24: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016B28: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80016B2C: ldc1        $f6, -0x1310($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1310);
    // 0x80016B30: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80016B34: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80016B38: mul.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80016B3C: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80016B40: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80016B44: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x80016B48: addiu       $s0, $zero, 0x8B
    ctx->r16 = ADD32(0, 0X8B);
    // 0x80016B4C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80016B50: b           L_80017380
    // 0x80016B54: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
        goto L_80017380;
    // 0x80016B54: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
L_80016B58:
    // 0x80016B58: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80016B5C: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80016B60: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x80016B64: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x80016B68: b           L_80017380
    // 0x80016B6C: addiu       $s0, $zero, 0x1DC
    ctx->r16 = ADD32(0, 0X1DC);
        goto L_80017380;
    // 0x80016B6C: addiu       $s0, $zero, 0x1DC
    ctx->r16 = ADD32(0, 0X1DC);
L_80016B70:
    // 0x80016B70: beq         $a2, $zero, L_80016BAC
    if (ctx->r6 == 0) {
        // 0x80016B74: addiu       $s0, $zero, 0x1DD
        ctx->r16 = ADD32(0, 0X1DD);
            goto L_80016BAC;
    }
    // 0x80016B74: addiu       $s0, $zero, 0x1DD
    ctx->r16 = ADD32(0, 0X1DD);
    // 0x80016B78: lw          $t5, 0x14($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X14);
    // 0x80016B7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016B80: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80016B84: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80016B88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80016B8C: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016B90: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x80016B94: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80016B98: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80016B9C: nop

    // 0x80016BA0: mul.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x80016BA4: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80016BA8: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
L_80016BAC:
    // 0x80016BAC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80016BB0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80016BB4: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
    // 0x80016BB8: b           L_80017380
    // 0x80016BBC: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
        goto L_80017380;
    // 0x80016BBC: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
L_80016BC0:
    // 0x80016BC0: beq         $a2, $zero, L_80016C04
    if (ctx->r6 == 0) {
        // 0x80016BC4: addiu       $s0, $zero, 0x1DE
        ctx->r16 = ADD32(0, 0X1DE);
            goto L_80016C04;
    }
    // 0x80016BC4: addiu       $s0, $zero, 0x1DE
    ctx->r16 = ADD32(0, 0X1DE);
    // 0x80016BC8: lw          $t8, 0x14($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X14);
    // 0x80016BCC: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x80016BD0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80016BD4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80016BD8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80016BDC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80016BE0: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x80016BE4: ldc1        $f10, -0x1308($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1308);
    // 0x80016BE8: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016BEC: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80016BF0: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80016BF4: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80016BF8: mul.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x80016BFC: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80016C00: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
L_80016C04:
    // 0x80016C04: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80016C08: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80016C0C: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
    // 0x80016C10: b           L_80017380
    // 0x80016C14: sh          $t9, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r25;
        goto L_80017380;
    // 0x80016C14: sh          $t9, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r25;
L_80016C18:
    // 0x80016C18: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80016C1C: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80016C20: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80016C24: sh          $t3, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r11;
    // 0x80016C28: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80016C2C: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x80016C30: b           L_80017380
    // 0x80016C34: addiu       $s0, $zero, 0x42
    ctx->r16 = ADD32(0, 0X42);
        goto L_80017380;
    // 0x80016C34: addiu       $s0, $zero, 0x42
    ctx->r16 = ADD32(0, 0X42);
L_80016C38:
    // 0x80016C38: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80016C3C: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80016C40: sh          $t5, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r13;
    // 0x80016C44: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x80016C48: addiu       $s0, $zero, 0x241
    ctx->r16 = ADD32(0, 0X241);
    // 0x80016C4C: b           L_80017380
    // 0x80016C50: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80016C50: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80016C54:
    // 0x80016C54: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80016C58: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80016C5C: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
    // 0x80016C60: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
    // 0x80016C64: b           L_80017380
    // 0x80016C68: addiu       $s0, $zero, 0x219
    ctx->r16 = ADD32(0, 0X219);
        goto L_80017380;
    // 0x80016C68: addiu       $s0, $zero, 0x219
    ctx->r16 = ADD32(0, 0X219);
L_80016C6C:
    // 0x80016C6C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80016C70: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80016C74: sh          $t9, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r25;
    // 0x80016C78: sh          $t8, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r24;
    // 0x80016C7C: addiu       $s0, $zero, 0x1E7
    ctx->r16 = ADD32(0, 0X1E7);
    // 0x80016C80: b           L_80017380
    // 0x80016C84: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80016C84: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80016C88:
    // 0x80016C88: beq         $a2, $zero, L_80016CD0
    if (ctx->r6 == 0) {
        // 0x80016C8C: addiu       $s0, $zero, 0x1E4
        ctx->r16 = ADD32(0, 0X1E4);
            goto L_80016CD0;
    }
    // 0x80016C8C: addiu       $s0, $zero, 0x1E4
    ctx->r16 = ADD32(0, 0X1E4);
    // 0x80016C90: lw          $t0, 0x14($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X14);
    // 0x80016C94: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x80016C98: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80016C9C: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80016CA0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80016CA4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80016CA8: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x80016CAC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80016CB0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80016CB4: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016CB8: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80016CBC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80016CC0: add.d       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f8.d + ctx->f18.d;
    // 0x80016CC4: mul.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80016CC8: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x80016CCC: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
L_80016CD0:
    // 0x80016CD0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80016CD4: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80016CD8: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80016CDC: b           L_80017380
    // 0x80016CE0: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
        goto L_80017380;
    // 0x80016CE0: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
L_80016CE4:
    // 0x80016CE4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80016CE8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80016CEC: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x80016CF0: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x80016CF4: b           L_80017380
    // 0x80016CF8: addiu       $s0, $zero, 0x1EB
    ctx->r16 = ADD32(0, 0X1EB);
        goto L_80017380;
    // 0x80016CF8: addiu       $s0, $zero, 0x1EB
    ctx->r16 = ADD32(0, 0X1EB);
L_80016CFC:
    // 0x80016CFC: beq         $a2, $zero, L_80016D38
    if (ctx->r6 == 0) {
        // 0x80016D00: addiu       $s0, $zero, 0x1EE
        ctx->r16 = ADD32(0, 0X1EE);
            goto L_80016D38;
    }
    // 0x80016D00: addiu       $s0, $zero, 0x1EE
    ctx->r16 = ADD32(0, 0X1EE);
    // 0x80016D04: lw          $t5, 0x14($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X14);
    // 0x80016D08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016D0C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80016D10: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80016D14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80016D18: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016D1C: cvt.d.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.d = CVT_D_W(ctx->f18.u32l);
    // 0x80016D20: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80016D24: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80016D28: nop

    // 0x80016D2C: mul.d       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x80016D30: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x80016D34: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
L_80016D38:
    // 0x80016D38: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80016D3C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80016D40: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
    // 0x80016D44: b           L_80017380
    // 0x80016D48: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
        goto L_80017380;
    // 0x80016D48: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
L_80016D4C:
    // 0x80016D4C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80016D50: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80016D54: sh          $t9, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r25;
    // 0x80016D58: sh          $t8, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r24;
    // 0x80016D5C: b           L_80017380
    // 0x80016D60: addiu       $s0, $zero, 0x1F9
    ctx->r16 = ADD32(0, 0X1F9);
        goto L_80017380;
    // 0x80016D60: addiu       $s0, $zero, 0x1F9
    ctx->r16 = ADD32(0, 0X1F9);
L_80016D64:
    // 0x80016D64: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016D68: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80016D6C: ldc1        $f8, -0x1300($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1300);
    // 0x80016D70: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80016D74: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80016D78: mul.d       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x80016D7C: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80016D80: sh          $t1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r9;
    // 0x80016D84: sh          $t0, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r8;
    // 0x80016D88: addiu       $s0, $zero, 0x1F9
    ctx->r16 = ADD32(0, 0X1F9);
    // 0x80016D8C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x80016D90: b           L_80017380
    // 0x80016D94: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
        goto L_80017380;
    // 0x80016D94: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
L_80016D98:
    // 0x80016D98: beq         $a2, $zero, L_80016DD4
    if (ctx->r6 == 0) {
        // 0x80016D9C: addiu       $s0, $zero, 0x1FA
        ctx->r16 = ADD32(0, 0X1FA);
            goto L_80016DD4;
    }
    // 0x80016D9C: addiu       $s0, $zero, 0x1FA
    ctx->r16 = ADD32(0, 0X1FA);
    // 0x80016DA0: lw          $t2, 0x14($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X14);
    // 0x80016DA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016DA8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80016DAC: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80016DB0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80016DB4: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016DB8: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x80016DBC: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x80016DC0: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80016DC4: nop

    // 0x80016DC8: mul.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80016DCC: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80016DD0: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
L_80016DD4:
    // 0x80016DD4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80016DD8: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80016DDC: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x80016DE0: b           L_80017380
    // 0x80016DE4: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
        goto L_80017380;
    // 0x80016DE4: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
L_80016DE8:
    // 0x80016DE8: beq         $a2, $zero, L_80016E44
    if (ctx->r6 == 0) {
        // 0x80016DEC: addiu       $s0, $zero, 0x48
        ctx->r16 = ADD32(0, 0X48);
            goto L_80016E44;
    }
    // 0x80016DEC: addiu       $s0, $zero, 0x48
    ctx->r16 = ADD32(0, 0X48);
    // 0x80016DF0: lw          $t5, 0x14($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X14);
    // 0x80016DF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016DF8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80016DFC: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80016E00: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80016E04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80016E08: cvt.d.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.d = CVT_D_W(ctx->f16.u32l);
    // 0x80016E0C: ldc1        $f10, -0x12F8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X12F8);
    // 0x80016E10: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80016E14: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x80016E18: mul.d       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x80016E1C: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016E20: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x80016E24: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80016E28: ldc1        $f10, -0x12F0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X12F0);
    // 0x80016E2C: add.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d + ctx->f4.d;
    // 0x80016E30: mul.d       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80016E34: cvt.s.d     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f14.fl = CVT_S_D(ctx->f16.d);
    // 0x80016E38: add.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f18.d + ctx->f8.d;
    // 0x80016E3C: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x80016E40: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
L_80016E44:
    // 0x80016E44: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80016E48: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80016E4C: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
    // 0x80016E50: b           L_80017380
    // 0x80016E54: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
        goto L_80017380;
    // 0x80016E54: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
L_80016E58:
    // 0x80016E58: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80016E5C: sh          $t8, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r24;
    // 0x80016E60: addiu       $s0, $zero, 0x209
    ctx->r16 = ADD32(0, 0X209);
    // 0x80016E64: b           L_80017380
    // 0x80016E68: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
        goto L_80017380;
    // 0x80016E68: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
L_80016E6C:
    // 0x80016E6C: beq         $a2, $zero, L_80016EA8
    if (ctx->r6 == 0) {
        // 0x80016E70: addiu       $s0, $zero, 0x20A
        ctx->r16 = ADD32(0, 0X20A);
            goto L_80016EA8;
    }
    // 0x80016E70: addiu       $s0, $zero, 0x20A
    ctx->r16 = ADD32(0, 0X20A);
    // 0x80016E74: lw          $t9, 0x14($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X14);
    // 0x80016E78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016E7C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80016E80: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80016E84: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80016E88: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016E8C: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80016E90: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80016E94: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80016E98: nop

    // 0x80016E9C: mul.d       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x80016EA0: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80016EA4: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
L_80016EA8:
    // 0x80016EA8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80016EAC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80016EB0: sh          $t1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r9;
    // 0x80016EB4: b           L_80017380
    // 0x80016EB8: sh          $t0, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r8;
        goto L_80017380;
    // 0x80016EB8: sh          $t0, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r8;
L_80016EBC:
    // 0x80016EBC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80016EC0: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80016EC4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80016EC8: sh          $t4, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r12;
    // 0x80016ECC: sh          $t3, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r11;
    // 0x80016ED0: sh          $t2, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r10;
    // 0x80016ED4: b           L_80017380
    // 0x80016ED8: addiu       $s0, $zero, 0x216
    ctx->r16 = ADD32(0, 0X216);
        goto L_80017380;
    // 0x80016ED8: addiu       $s0, $zero, 0x216
    ctx->r16 = ADD32(0, 0X216);
L_80016EDC:
    // 0x80016EDC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80016EE0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80016EE4: sh          $t6, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r14;
    // 0x80016EE8: sh          $t5, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r13;
    // 0x80016EEC: b           L_80017380
    // 0x80016EF0: addiu       $s0, $zero, 0x1EB
    ctx->r16 = ADD32(0, 0X1EB);
        goto L_80017380;
    // 0x80016EF0: addiu       $s0, $zero, 0x1EB
    ctx->r16 = ADD32(0, 0X1EB);
L_80016EF4:
    // 0x80016EF4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80016EF8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80016EFC: sh          $t8, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r24;
    // 0x80016F00: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    // 0x80016F04: b           L_80017380
    // 0x80016F08: addiu       $s0, $zero, 0x23A
    ctx->r16 = ADD32(0, 0X23A);
        goto L_80017380;
    // 0x80016F08: addiu       $s0, $zero, 0x23A
    ctx->r16 = ADD32(0, 0X23A);
L_80016F0C:
    // 0x80016F0C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80016F10: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80016F14: addiu       $s0, $zero, 0x136
    ctx->r16 = ADD32(0, 0X136);
    // 0x80016F18: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80016F1C: beq         $v0, $zero, L_80016F34
    if (ctx->r2 == 0) {
        // 0x80016F20: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_80016F34;
    }
    // 0x80016F20: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80016F24: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x80016F28: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x80016F2C: beql        $t9, $at, L_8001758C
    if (ctx->r25 == ctx->r1) {
        // 0x80016F30: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001758C;
    }
    goto skip_8;
    // 0x80016F30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
L_80016F34:
    // 0x80016F34: beql        $a2, $zero, L_80016F7C
    if (ctx->r6 == 0) {
        // 0x80016F38: sh          $t1, 0x74($sp)
        MEM_H(0X74, ctx->r29) = ctx->r9;
            goto L_80016F7C;
    }
    goto skip_9;
    // 0x80016F38: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    skip_9:
    // 0x80016F3C: lw          $t0, 0x14($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X14);
    // 0x80016F40: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x80016F44: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80016F48: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80016F4C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80016F50: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80016F54: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80016F58: ldc1        $f6, -0x12E8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X12E8);
    // 0x80016F5C: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80016F60: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80016F64: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80016F68: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x80016F6C: mul.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80016F70: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x80016F74: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x80016F78: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
L_80016F7C:
    // 0x80016F7C: b           L_80017380
    // 0x80016F80: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
        goto L_80017380;
    // 0x80016F80: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
L_80016F84:
    // 0x80016F84: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x80016F88: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80016F8C: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x80016F90: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x80016F94: b           L_80017380
    // 0x80016F98: addiu       $s0, $zero, 0x246
    ctx->r16 = ADD32(0, 0X246);
        goto L_80017380;
    // 0x80016F98: addiu       $s0, $zero, 0x246
    ctx->r16 = ADD32(0, 0X246);
L_80016F9C:
    // 0x80016F9C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80016FA0: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80016FA4: sh          $t6, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r14;
    // 0x80016FA8: sh          $t5, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r13;
    // 0x80016FAC: addiu       $s0, $zero, 0x244
    ctx->r16 = ADD32(0, 0X244);
    // 0x80016FB0: b           L_80017380
    // 0x80016FB4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80016FB4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80016FB8:
    // 0x80016FB8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80016FBC: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80016FC0: sh          $t8, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r24;
    // 0x80016FC4: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    // 0x80016FC8: addiu       $s0, $zero, 0x245
    ctx->r16 = ADD32(0, 0X245);
    // 0x80016FCC: b           L_80017380
    // 0x80016FD0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80016FD0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80016FD4:
    // 0x80016FD4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80016FD8: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80016FDC: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
    // 0x80016FE0: sh          $t9, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r25;
    // 0x80016FE4: b           L_80017380
    // 0x80016FE8: addiu       $s0, $zero, 0x249
    ctx->r16 = ADD32(0, 0X249);
        goto L_80017380;
    // 0x80016FE8: addiu       $s0, $zero, 0x249
    ctx->r16 = ADD32(0, 0X249);
L_80016FEC:
    // 0x80016FEC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80016FF0: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80016FF4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80016FF8: sh          $t3, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r11;
    // 0x80016FFC: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80017000: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x80017004: b           L_80017380
    // 0x80017008: addiu       $s0, $zero, 0x136
    ctx->r16 = ADD32(0, 0X136);
        goto L_80017380;
    // 0x80017008: addiu       $s0, $zero, 0x136
    ctx->r16 = ADD32(0, 0X136);
L_8001700C:
    // 0x8001700C: addiu       $t4, $zero, 0x16
    ctx->r12 = ADD32(0, 0X16);
    // 0x80017010: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80017014: sh          $t5, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r13;
    // 0x80017018: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x8001701C: b           L_80017380
    // 0x80017020: addiu       $s0, $zero, 0x25C
    ctx->r16 = ADD32(0, 0X25C);
        goto L_80017380;
    // 0x80017020: addiu       $s0, $zero, 0x25C
    ctx->r16 = ADD32(0, 0X25C);
L_80017024:
    // 0x80017024: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80017028: sh          $t6, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r14;
    // 0x8001702C: addiu       $s0, $zero, 0x256
    ctx->r16 = ADD32(0, 0X256);
    // 0x80017030: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
    // 0x80017034: b           L_80017380
    // 0x80017038: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80017038: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001703C:
    // 0x8001703C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80017040: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
    // 0x80017044: addiu       $s0, $zero, 0x256
    ctx->r16 = ADD32(0, 0X256);
    // 0x80017048: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
    // 0x8001704C: b           L_80017380
    // 0x80017050: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80017050: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80017054:
    // 0x80017054: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80017058: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8001705C: sh          $t9, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r25;
    // 0x80017060: sh          $t8, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r24;
    // 0x80017064: addiu       $s0, $zero, 0x1EF
    ctx->r16 = ADD32(0, 0X1EF);
    // 0x80017068: b           L_80017380
    // 0x8001706C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x8001706C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80017070:
    // 0x80017070: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x80017074: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80017078: sh          $t1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r9;
    // 0x8001707C: sh          $t0, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r8;
    // 0x80017080: addiu       $s0, $zero, 0x1F0
    ctx->r16 = ADD32(0, 0X1F0);
    // 0x80017084: b           L_80017380
    // 0x80017088: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80017088: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001708C:
    // 0x8001708C: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80017090: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80017094: sh          $t3, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r11;
    // 0x80017098: sh          $t2, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r10;
    // 0x8001709C: addiu       $s0, $zero, 0x1F1
    ctx->r16 = ADD32(0, 0X1F1);
    // 0x800170A0: b           L_80017380
    // 0x800170A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x800170A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800170A8:
    // 0x800170A8: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x800170AC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800170B0: sh          $t5, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r13;
    // 0x800170B4: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x800170B8: addiu       $s0, $zero, 0x1F2
    ctx->r16 = ADD32(0, 0X1F2);
    // 0x800170BC: b           L_80017380
    // 0x800170C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x800170C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800170C4:
    // 0x800170C4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800170C8: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x800170CC: addiu       $t6, $zero, 0x16
    ctx->r14 = ADD32(0, 0X16);
    // 0x800170D0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800170D4: beq         $v0, $zero, L_80017108
    if (ctx->r2 == 0) {
        // 0x800170D8: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80017108;
    }
    // 0x800170D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800170DC: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800170E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800170E4: ldc1        $f6, -0x12E0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X12E0);
    // 0x800170E8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800170EC: addiu       $s0, $zero, 0x28F
    ctx->r16 = ADD32(0, 0X28F);
    // 0x800170F0: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x800170F4: nop

    // 0x800170F8: bc1f        L_80017108
    if (!c1cs) {
        // 0x800170FC: nop
    
            goto L_80017108;
    }
    // 0x800170FC: nop

    // 0x80017100: b           L_80017108
    // 0x80017104: addiu       $s0, $zero, 0x20E
    ctx->r16 = ADD32(0, 0X20E);
        goto L_80017108;
    // 0x80017104: addiu       $s0, $zero, 0x20E
    ctx->r16 = ADD32(0, 0X20E);
L_80017108:
    // 0x80017108: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
    // 0x8001710C: b           L_80017380
    // 0x80017110: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
        goto L_80017380;
    // 0x80017110: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
L_80017114:
    // 0x80017114: addiu       $a0, $zero, 0x292
    ctx->r4 = ADD32(0, 0X292);
    // 0x80017118: jal         0x80011D1C
    // 0x8001711C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_15;
    // 0x8001711C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80017120: b           L_8001758C
    // 0x80017124: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8001758C;
    // 0x80017124: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80017128:
    // 0x80017128: addiu       $a0, $zero, 0x293
    ctx->r4 = ADD32(0, 0X293);
    // 0x8001712C: jal         0x80011D1C
    // 0x80017130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_16;
    // 0x80017130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80017134: b           L_8001758C
    // 0x80017138: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8001758C;
    // 0x80017138: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001713C:
    // 0x8001713C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80017140: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80017144: sh          $t9, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r25;
    // 0x80017148: sh          $t8, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r24;
    // 0x8001714C: addiu       $s0, $zero, 0x25D
    ctx->r16 = ADD32(0, 0X25D);
    // 0x80017150: b           L_80017380
    // 0x80017154: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80017154: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80017158:
    // 0x80017158: addiu       $t0, $zero, 0x16
    ctx->r8 = ADD32(0, 0X16);
    // 0x8001715C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80017160: sh          $t1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r9;
    // 0x80017164: sh          $t0, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r8;
    // 0x80017168: addiu       $s0, $zero, 0x261
    ctx->r16 = ADD32(0, 0X261);
    // 0x8001716C: b           L_80017380
    // 0x80017170: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x80017170: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80017174:
    // 0x80017174: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
    // 0x80017178: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8001717C: sh          $t3, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r11;
    // 0x80017180: sh          $t2, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r10;
    // 0x80017184: addiu       $s0, $zero, 0x159
    ctx->r16 = ADD32(0, 0X159);
    // 0x80017188: b           L_80017380
    // 0x8001718C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x8001718C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80017190:
    // 0x80017190: addiu       $t4, $zero, 0x19
    ctx->r12 = ADD32(0, 0X19);
    // 0x80017194: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80017198: sh          $t5, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r13;
    // 0x8001719C: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x800171A0: addiu       $s0, $zero, 0x15A
    ctx->r16 = ADD32(0, 0X15A);
    // 0x800171A4: b           L_80017380
    // 0x800171A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x800171A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800171AC:
    // 0x800171AC: addiu       $t6, $zero, 0x1A
    ctx->r14 = ADD32(0, 0X1A);
    // 0x800171B0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800171B4: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
    // 0x800171B8: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
    // 0x800171BC: addiu       $s0, $zero, 0x23D
    ctx->r16 = ADD32(0, 0X23D);
    // 0x800171C0: b           L_80017380
    // 0x800171C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x800171C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800171C8:
    // 0x800171C8: addiu       $t8, $zero, 0x1A
    ctx->r24 = ADD32(0, 0X1A);
    // 0x800171CC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800171D0: sh          $t9, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r25;
    // 0x800171D4: sh          $t8, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r24;
    // 0x800171D8: addiu       $s0, $zero, 0x23E
    ctx->r16 = ADD32(0, 0X23E);
    // 0x800171DC: b           L_80017380
    // 0x800171E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80017380;
    // 0x800171E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800171E4:
    // 0x800171E4: beq         $a2, $zero, L_8001721C
    if (ctx->r6 == 0) {
        // 0x800171E8: addiu       $s0, $zero, 0x296
        ctx->r16 = ADD32(0, 0X296);
            goto L_8001721C;
    }
    // 0x800171E8: addiu       $s0, $zero, 0x296
    ctx->r16 = ADD32(0, 0X296);
    // 0x800171EC: lw          $t0, 0x14($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X14);
    // 0x800171F0: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x800171F4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800171F8: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x800171FC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80017200: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80017204: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80017208: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8001720C: div.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f8.d);
    // 0x80017210: mul.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80017214: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80017218: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
L_8001721C:
    // 0x8001721C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80017220: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80017224: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80017228: b           L_80017380
    // 0x8001722C: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
        goto L_80017380;
    // 0x8001722C: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
L_80017230:
    // 0x80017230: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80017234: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80017238: sh          $t4, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r12;
    // 0x8001723C: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x80017240: b           L_80017380
    // 0x80017244: addiu       $s0, $zero, 0x297
    ctx->r16 = ADD32(0, 0X297);
        goto L_80017380;
    // 0x80017244: addiu       $s0, $zero, 0x297
    ctx->r16 = ADD32(0, 0X297);
L_80017248:
    // 0x80017248: beql        $a2, $zero, L_8001758C
    if (ctx->r6 == 0) {
        // 0x8001724C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001758C;
    }
    goto skip_10;
    // 0x8001724C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x80017250: lh          $t5, 0x0($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X0);
    // 0x80017254: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x80017258: subu        $t6, $s0, $t5
    ctx->r14 = SUB32(ctx->r16, ctx->r13);
    // 0x8001725C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80017260: jal         0x80011CF0
    // 0x80017264: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_80011CF0(rdram, ctx);
        goto after_17;
    // 0x80017264: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_17:
    // 0x80017268: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001726C: addiu       $v0, $v0, -0x6D94
    ctx->r2 = ADD32(ctx->r2, -0X6D94);
    // 0x80017270: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80017274: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80017278: subu        $t8, $s0, $t7
    ctx->r24 = SUB32(ctx->r16, ctx->r15);
    // 0x8001727C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80017280: nop

    // 0x80017284: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80017288: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8001728C: nop

    // 0x80017290: bc1fl       L_8001758C
    if (!c1cs) {
        // 0x80017294: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001758C;
    }
    goto skip_11;
    // 0x80017294: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_11:
    // 0x80017298: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x8001729C: b           L_80017588
    // 0x800172A0: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
        goto L_80017588;
    // 0x800172A0: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
L_800172A4:
    // 0x800172A4: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x800172A8: addiu       $s0, $zero, 0x299
    ctx->r16 = ADD32(0, 0X299);
    // 0x800172AC: addiu       $t8, $zero, 0x1B
    ctx->r24 = ADD32(0, 0X1B);
    // 0x800172B0: beq         $t0, $zero, L_80017374
    if (ctx->r8 == 0) {
        // 0x800172B4: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80017374;
    }
    // 0x800172B4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800172B8: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x800172BC: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x800172C0: bgez        $v0, L_80017318
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800172C4: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_80017318;
    }
    // 0x800172C4: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800172C8: sh          $t1, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r9;
    // 0x800172CC: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x800172D0: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x800172D4: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x800172D8: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x800172DC: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800172E0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800172E4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800172E8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800172EC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800172F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800172F4: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800172F8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800172FC: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80017300: div.d       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = DIV_D(ctx->f16.d, ctx->f2.d);
    // 0x80017304: add.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f8.d + ctx->f6.d;
    // 0x80017308: div.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x8001730C: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x80017310: b           L_80017374
    // 0x80017314: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
        goto L_80017374;
    // 0x80017314: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
L_80017318:
    // 0x80017318: bnel        $at, $zero, L_80017378
    if (ctx->r1 != 0) {
        // 0x8001731C: sh          $t8, 0x74($sp)
        MEM_H(0X74, ctx->r29) = ctx->r24;
            goto L_80017378;
    }
    goto skip_12;
    // 0x8001731C: sh          $t8, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r24;
    skip_12:
    // 0x80017320: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80017324: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80017328: sh          $t4, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r12;
    // 0x8001732C: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80017330: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x80017334: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80017338: addiu       $t7, $t6, -0x7F
    ctx->r15 = ADD32(ctx->r14, -0X7F);
    // 0x8001733C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80017340: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80017344: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80017348: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001734C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80017350: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80017354: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80017358: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8001735C: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x80017360: div.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f2.d);
    // 0x80017364: add.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f4.d + ctx->f16.d;
    // 0x80017368: div.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f18.d, ctx->f8.d);
    // 0x8001736C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80017370: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
L_80017374:
    // 0x80017374: sh          $t8, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r24;
L_80017378:
    // 0x80017378: sh          $t9, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r25;
    // 0x8001737C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80017380:
    // 0x80017380: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80017384: beql        $s0, $at, L_8001758C
    if (ctx->r16 == ctx->r1) {
        // 0x80017388: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001758C;
    }
    goto skip_13;
    // 0x80017388: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_13:
    // 0x8001738C: bne         $v1, $zero, L_800173B0
    if (ctx->r3 != 0) {
        // 0x80017390: lw          $a0, 0x80($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X80);
            goto L_800173B0;
    }
    // 0x80017390: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80017394: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80017398: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x8001739C: sh          $v1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r3;
    // 0x800173A0: jal         0x80011AE4
    // 0x800173A4: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    func_80011AE4(rdram, ctx);
        goto after_18;
    // 0x800173A4: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_18:
    // 0x800173A8: lh          $v1, 0x5E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X5E);
    // 0x800173AC: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
L_800173B0:
    // 0x800173B0: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800173B4: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800173B8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800173BC: lh          $a1, 0x74($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X74);
    // 0x800173C0: lh          $a2, 0x72($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X72);
    // 0x800173C4: lh          $a3, 0x70($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X70);
    // 0x800173C8: sh          $v1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r3;
    // 0x800173CC: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x800173D0: jal         0x8001B84C
    // 0x800173D4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_8001B84C(rdram, ctx);
        goto after_19;
    // 0x800173D4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_19:
    // 0x800173D8: lh          $t1, 0x60($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X60);
    // 0x800173DC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800173E0: lh          $v1, 0x5E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X5E);
    // 0x800173E4: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x800173E8: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800173EC: beq         $t1, $zero, L_80017434
    if (ctx->r9 == 0) {
        // 0x800173F0: sw          $v0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r2;
            goto L_80017434;
    }
    // 0x800173F0: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800173F4: beql        $a2, $zero, L_80017438
    if (ctx->r6 == 0) {
        // 0x800173F8: lh          $t2, 0x62($sp)
        ctx->r10 = MEM_H(ctx->r29, 0X62);
            goto L_80017438;
    }
    goto skip_14;
    // 0x800173F8: lh          $t2, 0x62($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X62);
    skip_14:
    // 0x800173FC: lh          $t0, 0x2($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X2);
    // 0x80017400: lui         $at, 0x4050
    ctx->r1 = S32(0X4050 << 16);
    // 0x80017404: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80017408: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8001740C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80017410: lui         $at, 0x4089
    ctx->r1 = S32(0X4089 << 16);
    // 0x80017414: cvt.d.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.d = CVT_D_W(ctx->f6.u32l);
    // 0x80017418: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8001741C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80017420: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x80017424: sub.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d - ctx->f8.d;
    // 0x80017428: div.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x8001742C: sub.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d - ctx->f16.d;
    // 0x80017430: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
L_80017434:
    // 0x80017434: lh          $t2, 0x62($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X62);
L_80017438:
    // 0x80017438: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x8001743C: beql        $t2, $zero, L_80017528
    if (ctx->r10 == 0) {
        // 0x80017440: mfc1        $a1, $f14
        ctx->r5 = (int32_t)ctx->f14.u32l;
            goto L_80017528;
    }
    goto skip_15;
    // 0x80017440: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    skip_15:
    // 0x80017444: lbu         $t3, -0x6D14($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X6D14);
    // 0x80017448: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001744C: beq         $t3, $zero, L_80017464
    if (ctx->r11 == 0) {
        // 0x80017450: nop
    
            goto L_80017464;
    }
    // 0x80017450: nop

    // 0x80017454: ldc1        $f10, -0x12D8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X12D8);
    // 0x80017458: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x8001745C: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80017460: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
L_80017464:
    // 0x80017464: beql        $a2, $zero, L_80017528
    if (ctx->r6 == 0) {
        // 0x80017468: mfc1        $a1, $f14
        ctx->r5 = (int32_t)ctx->f14.u32l;
            goto L_80017528;
    }
    goto skip_16;
    // 0x80017468: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    skip_16:
    // 0x8001746C: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x80017470: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x80017474: bne         $at, $zero, L_8001748C
    if (ctx->r1 != 0) {
        // 0x80017478: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_8001748C;
    }
    // 0x80017478: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8001747C: beq         $v0, $at, L_800174CC
    if (ctx->r2 == ctx->r1) {
        // 0x80017480: nop
    
            goto L_800174CC;
    }
    // 0x80017480: nop

    // 0x80017484: b           L_80017528
    // 0x80017488: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
        goto L_80017528;
    // 0x80017488: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
L_8001748C:
    // 0x8001748C: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x80017490: bne         $at, $zero, L_800174AC
    if (ctx->r1 != 0) {
        // 0x80017494: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_800174AC;
    }
    // 0x80017494: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80017498: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x8001749C: beq         $v0, $s0, L_800174FC
    if (ctx->r2 == ctx->r16) {
        // 0x800174A0: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_800174FC;
    }
    // 0x800174A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800174A4: b           L_80017528
    // 0x800174A8: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
        goto L_80017528;
    // 0x800174A8: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
L_800174AC:
    // 0x800174AC: sltiu       $at, $t4, 0x20
    ctx->r1 = ctx->r12 < 0X20 ? 1 : 0;
    // 0x800174B0: beq         $at, $zero, L_80017524
    if (ctx->r1 == 0) {
        // 0x800174B4: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80017524;
    }
    // 0x800174B4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800174B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800174BC: addu        $at, $at, $t4
    gpr jr_addend_800174C4 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800174C0: lw          $t4, -0x12D0($at)
    ctx->r12 = ADD32(ctx->r1, -0X12D0);
    // 0x800174C4: jr          $t4
    // 0x800174C8: nop

    switch (jr_addend_800174C4 >> 2) {
        case 0: goto L_80017524; break;
        case 1: goto L_800174CC; break;
        case 2: goto L_80017524; break;
        case 3: goto L_800174E4; break;
        case 4: goto L_80017524; break;
        case 5: goto L_80017524; break;
        case 6: goto L_80017524; break;
        case 7: goto L_80017524; break;
        case 8: goto L_80017524; break;
        case 9: goto L_80017524; break;
        case 10: goto L_80017524; break;
        case 11: goto L_80017524; break;
        case 12: goto L_80017524; break;
        case 13: goto L_80017524; break;
        case 14: goto L_80017524; break;
        case 15: goto L_800174E4; break;
        case 16: goto L_80017524; break;
        case 17: goto L_80017524; break;
        case 18: goto L_80017524; break;
        case 19: goto L_80017524; break;
        case 20: goto L_80017524; break;
        case 21: goto L_80017524; break;
        case 22: goto L_80017524; break;
        case 23: goto L_80017524; break;
        case 24: goto L_80017524; break;
        case 25: goto L_80017524; break;
        case 26: goto L_80017524; break;
        case 27: goto L_80017524; break;
        case 28: goto L_80017524; break;
        case 29: goto L_80017524; break;
        case 30: goto L_80017524; break;
        case 31: goto L_80017510; break;
        default: switch_error(__func__, 0x800174C4, 0x800AED30);
    }
    // 0x800174C8: nop

L_800174CC:
    // 0x800174CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800174D0: ldc1        $f16, -0x1250($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X1250);
    // 0x800174D4: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x800174D8: mul.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x800174DC: b           L_80017524
    // 0x800174E0: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
        goto L_80017524;
    // 0x800174E0: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
L_800174E4:
    // 0x800174E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800174E8: ldc1        $f10, -0x1248($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1248);
    // 0x800174EC: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x800174F0: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800174F4: b           L_80017524
    // 0x800174F8: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
        goto L_80017524;
    // 0x800174F8: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
L_800174FC:
    // 0x800174FC: ldc1        $f16, -0x1240($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X1240);
    // 0x80017500: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x80017504: mul.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80017508: b           L_80017524
    // 0x8001750C: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
        goto L_80017524;
    // 0x8001750C: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
L_80017510:
    // 0x80017510: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80017514: ldc1        $f10, -0x1238($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1238);
    // 0x80017518: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x8001751C: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80017520: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
L_80017524:
    // 0x80017524: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
L_80017528:
    // 0x80017528: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8001752C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80017530: jal         0x8001BCD0
    // 0x80017534: sh          $v1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r3;
    func_8001BCD0(rdram, ctx);
        goto after_20;
    // 0x80017534: sh          $v1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r3;
    after_20:
    // 0x80017538: lh          $v1, 0x5E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X5E);
    // 0x8001753C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80017540: addiu       $v0, $v0, -0x6D80
    ctx->r2 = ADD32(ctx->r2, -0X6D80);
    // 0x80017544: bnel        $v1, $zero, L_8001758C
    if (ctx->r3 != 0) {
        // 0x80017548: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001758C;
    }
    goto skip_17;
    // 0x80017548: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_17:
    // 0x8001754C: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80017550: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80017554: beql        $t5, $zero, L_8001758C
    if (ctx->r13 == 0) {
        // 0x80017558: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001758C;
    }
    goto skip_18;
    // 0x80017558: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_18:
    // 0x8001755C: lh          $t6, -0x6D90($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6D90);
    // 0x80017560: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x80017564: bnel        $t6, $at, L_80017578
    if (ctx->r14 != ctx->r1) {
        // 0x80017568: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80017578;
    }
    goto skip_19;
    // 0x80017568: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    skip_19:
    // 0x8001756C: b           L_80017588
    // 0x80017570: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
        goto L_80017588;
    // 0x80017570: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80017574: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
L_80017578:
    // 0x80017578: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x8001757C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80017580: jal         0x8001BCF4
    // 0x80017584: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_8001BCF4(rdram, ctx);
        goto after_21;
    // 0x80017584: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_21:
L_80017588:
    // 0x80017588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001758C:
    // 0x8001758C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80017590: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80017594: jr          $ra
    // 0x80017598: nop

    return;
    // 0x80017598: nop

;}
RECOMP_FUNC void func_80703614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80703614: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80703618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070361C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80703620: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80703624: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x80703628: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x8070362C: bnel        $t6, $zero, L_807036C0
    if (ctx->r14 != 0) {
        // 0x80703630: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807036C0;
    }
    goto skip_0;
    // 0x80703630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80703634: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x80703638: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8070363C: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x80703640: beq         $t7, $zero, L_80703688
    if (ctx->r15 == 0) {
        // 0x80703644: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_80703688;
    }
    // 0x80703644: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80703648: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8070364C: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x80703650: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80703654: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80703658: jal         0x8004D1F0
    // 0x8070365C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x8070365C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80703660: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80703664: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80703668: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x8070366C: jal         0x8004D698
    // 0x80703670: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x80703670: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80703674: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80703678: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8070367C: ori         $t9, $t8, 0xF
    ctx->r25 = ctx->r24 | 0XF;
    // 0x80703680: b           L_807036BC
    // 0x80703684: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
        goto L_807036BC;
    // 0x80703684: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
L_80703688:
    // 0x80703688: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8070368C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80703690: jal         0x8004D1F0
    // 0x80703694: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x80703694: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x80703698: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8070369C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807036A0: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x807036A4: jal         0x8004D698
    // 0x807036A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_3;
    // 0x807036A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x807036AC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x807036B0: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x807036B4: ori         $t1, $t0, 0xF0
    ctx->r9 = ctx->r8 | 0XF0;
    // 0x807036B8: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
L_807036BC:
    // 0x807036BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807036C0:
    // 0x807036C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807036C4: jr          $ra
    // 0x807036C8: nop

    return;
    // 0x807036C8: nop

;}
RECOMP_FUNC void func_804017FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804017FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80401800: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80401804: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80401808: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8040180C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80401810: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80401814: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x80401818: jal         0x8004700C
    // 0x8040181C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8040181C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    after_0:
    // 0x80401820: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80401824: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80401828: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8040182C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80401830: lwc1        $f0, 0x120($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X120);
    // 0x80401834: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80401838: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8040183C: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80401840: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80401844: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80401848: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8040184C: lwc1        $f2, 0x11C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X11C);
    // 0x80401850: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80401854: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80401858: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8040185C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80401860: jal         0x80400B50
    // 0x80401864: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    func_80400B50(rdram, ctx);
        goto after_1;
    // 0x80401864: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    after_1:
    // 0x80401868: jal         0x80400F7C
    // 0x8040186C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80400F7C(rdram, ctx);
        goto after_2;
    // 0x8040186C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80401870: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80401874: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80401878: jal         0x80048F84
    // 0x8040187C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x8040187C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80401880: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80401884: jal         0x80048F84
    // 0x80401888: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x80401888: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8040188C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80401890: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80401894: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80401898: beql        $t8, $zero, L_804018E0
    if (ctx->r24 == 0) {
        // 0x8040189C: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_804018E0;
    }
    goto skip_0;
    // 0x8040189C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x804018A0: lw          $t9, 0xAA4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XAA4);
    // 0x804018A4: beql        $t9, $zero, L_804018E0
    if (ctx->r25 == 0) {
        // 0x804018A8: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_804018E0;
    }
    goto skip_1;
    // 0x804018A8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x804018AC: lw          $t0, 0x478($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X478);
    // 0x804018B0: lbu         $t1, 0xF0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XF0);
    // 0x804018B4: beql        $t1, $zero, L_804018E0
    if (ctx->r9 == 0) {
        // 0x804018B8: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_804018E0;
    }
    goto skip_2;
    // 0x804018B8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    skip_2:
    // 0x804018BC: jal         0x80059278
    // 0x804018C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80059278(rdram, ctx);
        goto after_5;
    // 0x804018C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804018C4: beql        $v0, $zero, L_804018E0
    if (ctx->r2 == 0) {
        // 0x804018C8: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_804018E0;
    }
    goto skip_3;
    // 0x804018C8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    skip_3:
    // 0x804018CC: jal         0x804011D8
    // 0x804018D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804011D8(rdram, ctx);
        goto after_6;
    // 0x804018D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804018D4: b           L_80401B80
    // 0x804018D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80401B80;
    // 0x804018D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804018DC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
L_804018E0:
    // 0x804018E0: jal         0x80066DE4
    // 0x804018E4: lwc1        $f12, 0x128($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X128);
    func_80066DE4(rdram, ctx);
        goto after_7;
    // 0x804018E4: lwc1        $f12, 0x128($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X128);
    after_7:
    // 0x804018E8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804018EC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804018F0: lui         $at, 0x8040
    ctx->r1 = S32(RELOC_HI16(8, 0X7724) << 16);
    // 0x804018F4: lwc1        $f16, 0x7764($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(8, 0X7724));
    // 0x804018F8: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804018FC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80401900: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80401904: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80401908: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8040190C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80401910: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x80401914: lwc1        $f8, 0x128($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X128);
    // 0x80401918: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8040191C: swc1        $f16, 0x128($v0)
    MEM_W(0X128, ctx->r2) = ctx->f16.u32l;
    // 0x80401920: lwc1        $f2, 0x128($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X128);
    // 0x80401924: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80401928: nop

    // 0x8040192C: bc1fl       L_80401940
    if (!c1cs) {
        // 0x80401930: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80401940;
    }
    goto skip_4;
    // 0x80401930: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_4:
    // 0x80401934: sub.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80401938: swc1        $f18, 0x128($v0)
    MEM_W(0X128, ctx->r2) = ctx->f18.u32l;
    // 0x8040193C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80401940:
    // 0x80401940: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80401944: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80401948: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8040194C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80401950: nop

    // 0x80401954: bc1tl       L_80401970
    if (c1cs) {
        // 0x80401958: lwc1        $f6, 0x3C($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_80401970;
    }
    goto skip_5;
    // 0x80401958: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    skip_5:
    // 0x8040195C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80401960: andi        $t5, $t4, 0xF0
    ctx->r13 = ctx->r12 & 0XF0;
    // 0x80401964: beql        $t5, $zero, L_804019D4
    if (ctx->r13 == 0) {
        // 0x80401968: lwc1        $f8, 0xC4($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
            goto L_804019D4;
    }
    goto skip_6;
    // 0x80401968: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    skip_6:
    // 0x8040196C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
L_80401970:
    // 0x80401970: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80401974: nop

    // 0x80401978: bc1fl       L_804019D4
    if (!c1cs) {
        // 0x8040197C: lwc1        $f8, 0xC4($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
            goto L_804019D4;
    }
    goto skip_7;
    // 0x8040197C: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    skip_7:
    // 0x80401980: lwc1        $f0, 0xDC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x80401984: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80401988: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8040198C: nop

    // 0x80401990: bc1fl       L_804019D4
    if (!c1cs) {
        // 0x80401994: lwc1        $f8, 0xC4($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
            goto L_804019D4;
    }
    goto skip_8;
    // 0x80401994: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    skip_8:
    // 0x80401998: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8040199C: nop

    // 0x804019A0: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x804019A4: jal         0x800653D8
    // 0x804019A8: swc1        $f16, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f16.u32l;
    func_800653D8(rdram, ctx);
        goto after_8;
    // 0x804019A8: swc1        $f16, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f16.u32l;
    after_8:
    // 0x804019AC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804019B0: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x804019B4: bne         $t6, $zero, L_804019D0
    if (ctx->r14 != 0) {
        // 0x804019B8: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_804019D0;
    }
    // 0x804019B8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804019BC: lwc1        $f18, 0xE0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x804019C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804019C4: nop

    // 0x804019C8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x804019CC: swc1        $f6, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f6.u32l;
L_804019D0:
    // 0x804019D0: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
L_804019D4:
    // 0x804019D4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x804019D8: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804019DC: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x804019E0: nop

    // 0x804019E4: bc1tl       L_80401A00
    if (c1cs) {
        // 0x804019E8: lwc1        $f16, 0x3C($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_80401A00;
    }
    goto skip_9;
    // 0x804019E8: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    skip_9:
    // 0x804019EC: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x804019F0: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x804019F4: beql        $t9, $zero, L_80401A64
    if (ctx->r25 == 0) {
        // 0x804019F8: lwc1        $f16, 0xC8($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_80401A64;
    }
    goto skip_10;
    // 0x804019F8: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    skip_10:
    // 0x804019FC: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
L_80401A00:
    // 0x80401A00: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80401A04: nop

    // 0x80401A08: bc1fl       L_80401A64
    if (!c1cs) {
        // 0x80401A0C: lwc1        $f16, 0xC8($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_80401A64;
    }
    goto skip_11;
    // 0x80401A0C: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    skip_11:
    // 0x80401A10: lwc1        $f0, 0xDC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x80401A14: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80401A18: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80401A1C: nop

    // 0x80401A20: bc1fl       L_80401A64
    if (!c1cs) {
        // 0x80401A24: lwc1        $f16, 0xC8($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_80401A64;
    }
    goto skip_12;
    // 0x80401A24: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    skip_12:
    // 0x80401A28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80401A2C: nop

    // 0x80401A30: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80401A34: jal         0x800653D8
    // 0x80401A38: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
    func_800653D8(rdram, ctx);
        goto after_9;
    // 0x80401A38: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
    after_9:
    // 0x80401A3C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80401A40: andi        $t0, $v0, 0x3
    ctx->r8 = ctx->r2 & 0X3;
    // 0x80401A44: bne         $t0, $zero, L_80401A60
    if (ctx->r8 != 0) {
        // 0x80401A48: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80401A60;
    }
    // 0x80401A48: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80401A4C: lwc1        $f6, 0xE0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x80401A50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80401A54: nop

    // 0x80401A58: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80401A5C: swc1        $f10, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f10.u32l;
L_80401A60:
    // 0x80401A60: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
L_80401A64:
    // 0x80401A64: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80401A68: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80401A6C: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80401A70: nop

    // 0x80401A74: bc1tl       L_80401A90
    if (c1cs) {
        // 0x80401A78: lwc1        $f18, 0x40($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
            goto L_80401A90;
    }
    goto skip_13;
    // 0x80401A78: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    skip_13:
    // 0x80401A7C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80401A80: andi        $t3, $t2, 0xF000
    ctx->r11 = ctx->r10 & 0XF000;
    // 0x80401A84: beql        $t3, $zero, L_80401AF4
    if (ctx->r11 == 0) {
        // 0x80401A88: lwc1        $f4, 0xC8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_80401AF4;
    }
    goto skip_14;
    // 0x80401A88: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    skip_14:
    // 0x80401A8C: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
L_80401A90:
    // 0x80401A90: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80401A94: nop

    // 0x80401A98: bc1fl       L_80401AF4
    if (!c1cs) {
        // 0x80401A9C: lwc1        $f4, 0xC8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_80401AF4;
    }
    goto skip_15;
    // 0x80401A9C: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    skip_15:
    // 0x80401AA0: lwc1        $f0, 0xE0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x80401AA4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80401AA8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80401AAC: nop

    // 0x80401AB0: bc1fl       L_80401AF4
    if (!c1cs) {
        // 0x80401AB4: lwc1        $f4, 0xC8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_80401AF4;
    }
    goto skip_16;
    // 0x80401AB4: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    skip_16:
    // 0x80401AB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80401ABC: nop

    // 0x80401AC0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80401AC4: jal         0x800653D8
    // 0x80401AC8: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
    func_800653D8(rdram, ctx);
        goto after_10;
    // 0x80401AC8: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
    after_10:
    // 0x80401ACC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80401AD0: andi        $t4, $v0, 0x3
    ctx->r12 = ctx->r2 & 0X3;
    // 0x80401AD4: bne         $t4, $zero, L_80401AF0
    if (ctx->r12 != 0) {
        // 0x80401AD8: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80401AF0;
    }
    // 0x80401AD8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80401ADC: lwc1        $f10, 0xDC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x80401AE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80401AE4: nop

    // 0x80401AE8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80401AEC: swc1        $f18, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f18.u32l;
L_80401AF0:
    // 0x80401AF0: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
L_80401AF4:
    // 0x80401AF4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80401AF8: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80401AFC: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80401B00: nop

    // 0x80401B04: bc1tl       L_80401B20
    if (c1cs) {
        // 0x80401B08: lwc1        $f8, 0x40($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
            goto L_80401B20;
    }
    goto skip_17;
    // 0x80401B08: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    skip_17:
    // 0x80401B0C: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80401B10: andi        $t7, $t6, 0xF00
    ctx->r15 = ctx->r14 & 0XF00;
    // 0x80401B14: beql        $t7, $zero, L_80401B80
    if (ctx->r15 == 0) {
        // 0x80401B18: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80401B80;
    }
    goto skip_18;
    // 0x80401B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_18:
    // 0x80401B1C: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
L_80401B20:
    // 0x80401B20: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80401B24: nop

    // 0x80401B28: bc1fl       L_80401B80
    if (!c1cs) {
        // 0x80401B2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80401B80;
    }
    goto skip_19;
    // 0x80401B2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_19:
    // 0x80401B30: lwc1        $f0, 0xE0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x80401B34: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80401B38: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80401B3C: nop

    // 0x80401B40: bc1fl       L_80401B80
    if (!c1cs) {
        // 0x80401B44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80401B80;
    }
    goto skip_20;
    // 0x80401B44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_20:
    // 0x80401B48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80401B4C: nop

    // 0x80401B50: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80401B54: jal         0x800653D8
    // 0x80401B58: swc1        $f16, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f16.u32l;
    func_800653D8(rdram, ctx);
        goto after_11;
    // 0x80401B58: swc1        $f16, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f16.u32l;
    after_11:
    // 0x80401B5C: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x80401B60: bne         $t8, $zero, L_80401B7C
    if (ctx->r24 != 0) {
        // 0x80401B64: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80401B7C;
    }
    // 0x80401B64: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80401B68: lwc1        $f18, 0xDC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x80401B6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80401B70: nop

    // 0x80401B74: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80401B78: swc1        $f6, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f6.u32l;
L_80401B7C:
    // 0x80401B7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80401B80:
    // 0x80401B80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80401B84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80401B88: jr          $ra
    // 0x80401B8C: nop

    return;
    // 0x80401B8C: nop

;}
