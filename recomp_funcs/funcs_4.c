#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_805A9388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A9388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A938C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805A9390: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805A9394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A9398: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805A939C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A93A0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805A93A4: jal         0x80048F84
    // 0x805A93A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x805A93A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x805A93AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A93B0: jal         0x805A9314
    // 0x805A93B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_805A9314(rdram, ctx);
        goto after_1;
    // 0x805A93B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x805A93B8: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x805A93BC: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x805A93C0: beql        $at, $zero, L_805A9438
    if (ctx->r1 == 0) {
        // 0x805A93C4: lwc1        $f0, 0x40($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
            goto L_805A9438;
    }
    goto skip_0;
    // 0x805A93C4: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    skip_0:
    // 0x805A93C8: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x805A93CC: lui         $at, 0xBF40
    ctx->r1 = S32(0XBF40 << 16);
    // 0x805A93D0: beq         $t7, $zero, L_805A93F8
    if (ctx->r15 == 0) {
        // 0x805A93D4: nop
    
            goto L_805A93F8;
    }
    // 0x805A93D4: nop

    // 0x805A93D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A93DC: lwc1        $f6, 0xC8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x805A93E0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805A93E4: nop

    // 0x805A93E8: bc1fl       L_805A9458
    if (!c1cs) {
        // 0x805A93EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A9458;
    }
    goto skip_1;
    // 0x805A93EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805A93F0: b           L_805A9454
    // 0x805A93F4: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
        goto L_805A9454;
    // 0x805A93F4: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_805A93F8:
    // 0x805A93F8: jal         0x805A925C
    // 0x805A93FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805A925C(rdram, ctx);
        goto after_2;
    // 0x805A93FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x805A9400: bne         $v0, $zero, L_805A9420
    if (ctx->r2 != 0) {
        // 0x805A9404: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_805A9420;
    }
    // 0x805A9404: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805A9408: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    // 0x805A940C: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x805A9410: sw          $t0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r8;
    // 0x805A9414: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x805A9418: b           L_805A9454
    // 0x805A941C: sw          $t9, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r25;
        goto L_805A9454;
    // 0x805A941C: sw          $t9, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r25;
L_805A9420:
    // 0x805A9420: bne         $v0, $at, L_805A9454
    if (ctx->r2 != ctx->r1) {
        // 0x805A9424: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_805A9454;
    }
    // 0x805A9424: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805A9428: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805A942C: b           L_805A9454
    // 0x805A9430: swc1        $f8, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f8.u32l;
        goto L_805A9454;
    // 0x805A9430: swc1        $f8, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f8.u32l;
    // 0x805A9434: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
L_805A9438:
    // 0x805A9438: lwc1        $f10, 0x40($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X40);
    // 0x805A943C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x805A9440: nop

    // 0x805A9444: bc1fl       L_805A9458
    if (!c1cs) {
        // 0x805A9448: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A9458;
    }
    goto skip_2;
    // 0x805A9448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805A944C: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
    // 0x805A9450: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
L_805A9454:
    // 0x805A9454: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A9458:
    // 0x805A9458: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805A945C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805A9460: jr          $ra
    // 0x805A9464: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805A9464: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8040B314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B314: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8040B318: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040B31C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8040B320: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8040B324: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8040B328: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8040B32C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8040B330: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040B334: lui         $a0, 0x409C
    ctx->r4 = S32(0X409C << 16);
    // 0x8040B338: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8040B33C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8040B340: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8040B344: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8040B348: jal         0x8004613C
    // 0x8040B34C: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x8040B34C: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    after_0:
    // 0x8040B350: bne         $v0, $zero, L_8040B360
    if (ctx->r2 != 0) {
        // 0x8040B354: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8040B360;
    }
    // 0x8040B354: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8040B358: b           L_8040B464
    // 0x8040B35C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8040B464;
    // 0x8040B35C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8040B360:
    // 0x8040B360: jal         0x80047090
    // 0x8040B364: addiu       $a0, $zero, 0x409C
    ctx->r4 = ADD32(0, 0X409C);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x8040B364: addiu       $a0, $zero, 0x409C
    ctx->r4 = ADD32(0, 0X409C);
    after_1:
    // 0x8040B368: lhu         $t8, 0xE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XE);
    // 0x8040B36C: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x8040B370: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8040B374: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x8040B378: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8040B37C: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    // 0x8040B380: sb          $zero, 0x165($s1)
    MEM_B(0X165, ctx->r17) = 0;
    // 0x8040B384: lw          $t2, 0x16C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X16C);
    // 0x8040B388: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8040B38C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8040B390: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8040B394: lw          $t3, 0x138($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X138);
    // 0x8040B398: jal         0x80045A34
    // 0x8040B39C: sw          $t3, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r11;
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x8040B39C: sw          $t3, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r11;
    after_2:
    // 0x8040B3A0: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8040B3A4: lwc1        $f4, 0x6C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8040B3A8: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8040B3AC: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8040B3B0: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8040B3B4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8040B3B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040B3BC: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8040B3C0: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    // 0x8040B3C4: lwc1        $f10, 0x70($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8040B3C8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8040B3CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8040B3D0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8040B3D4: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
    // 0x8040B3D8: lwc1        $f4, 0x6C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8040B3DC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8040B3E0: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x8040B3E4: lwc1        $f10, 0x70($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8040B3E8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8040B3EC: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x8040B3F0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8040B3F4: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x8040B3F8: lw          $t4, 0x138($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X138);
    // 0x8040B3FC: bnel        $t4, $zero, L_8040B41C
    if (ctx->r12 != 0) {
        // 0x8040B400: lwc1        $f16, 0x3C($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_8040B41C;
    }
    goto skip_0;
    // 0x8040B400: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    skip_0:
    // 0x8040B404: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8040B408: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8040B40C: nop

    // 0x8040B410: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8040B414: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x8040B418: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
L_8040B41C:
    // 0x8040B41C: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040B420: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8040B424: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8040B428: swc1        $f16, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f16.u32l;
    // 0x8040B42C: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040B430: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8040B434: swc1        $f18, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f18.u32l;
    // 0x8040B438: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040B43C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8040B440: jal         0x80047F9C
    // 0x8040B444: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x8040B444: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    after_3:
    // 0x8040B448: lw          $t0, 0x180($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X180);
    // 0x8040B44C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8040B450: sb          $t9, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r25;
    // 0x8040B454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040B458: jal         0x8040B2F0
    // 0x8040B45C: lbu         $a1, 0x30($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X30);
    func_8040B2F0(rdram, ctx);
        goto after_4;
    // 0x8040B45C: lbu         $a1, 0x30($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X30);
    after_4:
    // 0x8040B460: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8040B464:
    // 0x8040B464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8040B468: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8040B46C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8040B470: jr          $ra
    // 0x8040B474: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8040B474: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8045457C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045457C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80454580: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
    // 0x80454584: addiu       $a1, $zero, 0x1B6C
    ctx->r5 = ADD32(0, 0X1B6C);
    // 0x80454588: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x8045458C: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80454590: sw          $v1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r3;
    // 0x80454594: sw          $a1, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r5;
    // 0x80454598: sw          $v1, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r3;
    // 0x8045459C: sw          $a1, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->r5;
    // 0x804545A0: jr          $ra
    // 0x804545A4: sw          $t6, 0xFC($v0)
    MEM_W(0XFC, ctx->r2) = ctx->r14;
    return;
    // 0x804545A4: sw          $t6, 0xFC($v0)
    MEM_W(0XFC, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8040CBE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040CBE8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040CBEC: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8040CBF0: addu        $a3, $a0, $v1
    ctx->r7 = ADD32(ctx->r4, ctx->r3);
    // 0x8040CBF4: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // 0x8040CBF8: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8040CBFC: lwc1        $f6, 0x6C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X6C);
    // 0x8040CC00: addiu       $v0, $a2, 0x10
    ctx->r2 = ADD32(ctx->r6, 0X10);
    // 0x8040CC04: addiu       $v1, $a3, 0x6C
    ctx->r3 = ADD32(ctx->r7, 0X6C);
    // 0x8040CC08: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8040CC0C: nop

    // 0x8040CC10: bc1fl       L_8040CC54
    if (!c1cs) {
        // 0x8040CC14: lwc1        $f2, 0x0($v1)
        ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
            goto L_8040CC54;
    }
    goto skip_0;
    // 0x8040CC14: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8040CC18: addiu       $v1, $a3, 0x6C
    ctx->r3 = ADD32(ctx->r7, 0X6C);
    // 0x8040CC1C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8040CC20: lwc1        $f10, 0x1C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x8040CC24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8040CC28: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8040CC2C: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x8040CC30: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8040CC34: lwc1        $f0, 0x10($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8040CC38: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x8040CC3C: nop

    // 0x8040CC40: bc1fl       L_8040CCA4
    if (!c1cs) {
        // 0x8040CC44: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8040CCA4;
    }
    goto skip_1;
    // 0x8040CC44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8040CC48: jr          $ra
    // 0x8040CC4C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x8040CC4C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8040CC50: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
L_8040CC54:
    // 0x8040CC54: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8040CC58: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8040CC5C: nop

    // 0x8040CC60: bc1f        L_8040CC98
    if (!c1cs) {
        // 0x8040CC64: nop
    
            goto L_8040CC98;
    }
    // 0x8040CC64: nop

    // 0x8040CC68: lwc1        $f6, 0x1C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x8040CC6C: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8040CC70: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8040CC74: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8040CC78: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8040CC7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8040CC80: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8040CC84: nop

    // 0x8040CC88: bc1fl       L_8040CCA4
    if (!c1cs) {
        // 0x8040CC8C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8040CCA4;
    }
    goto skip_2;
    // 0x8040CC8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8040CC90: jr          $ra
    // 0x8040CC94: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x8040CC94: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_8040CC98:
    // 0x8040CC98: jr          $ra
    // 0x8040CC9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8040CC9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8040CCA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8040CCA4:
    // 0x8040CCA4: jr          $ra
    // 0x8040CCA8: nop

    return;
    // 0x8040CCA8: nop

;}
RECOMP_FUNC void func_80515AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80515AFC: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE64) << 16);
    // 0x80515B00: lwc1        $f2, 0x6304($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE64));
    // 0x80515B04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80515B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80515B0C: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE68) << 16);
    // 0x80515B10: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80515B14: lwc1        $f4, 0x6308($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE68));
    // 0x80515B18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80515B1C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80515B20: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80515B24: nop

    // 0x80515B28: bc1fl       L_80515B48
    if (!c1cs) {
        // 0x80515B2C: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_80515B48;
    }
    goto skip_0;
    // 0x80515B2C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_0:
    // 0x80515B30: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80515B34: jal         0x80515DD4
    // 0x80515B38: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80515DD4(rdram, ctx);
        goto after_0;
    // 0x80515B38: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80515B3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80515B40: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80515B44: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80515B48:
    // 0x80515B48: jal         0x805158B4
    // 0x80515B4C: nop

    func_805158B4(rdram, ctx);
        goto after_1;
    // 0x80515B4C: nop

    after_1:
    // 0x80515B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80515B54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80515B58: jr          $ra
    // 0x80515B5C: nop

    return;
    // 0x80515B5C: nop

;}
RECOMP_FUNC void func_8057C348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C348: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057C34C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057C350: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057C354: jal         0x8057BB68
    // 0x8057C358: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8057BB68(rdram, ctx);
        goto after_0;
    // 0x8057C358: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8057C35C: jal         0x8057C1AC
    // 0x8057C360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057C1AC(rdram, ctx);
        goto after_1;
    // 0x8057C360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8057C364: beq         $v0, $zero, L_8057C39C
    if (ctx->r2 == 0) {
        // 0x8057C368: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8057C39C;
    }
    // 0x8057C368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057C36C: jal         0x8057C6B0
    // 0x8057C370: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8057C6B0(rdram, ctx);
        goto after_2;
    // 0x8057C370: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x8057C374: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8057C378: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x8057C37C: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8057C380: jal         0x80065490
    // 0x8057C384: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x8057C384: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    after_3:
    // 0x8057C388: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8057C38C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8057C390: lw          $t7, 0xEE0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XEE0);
    // 0x8057C394: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8057C398: sw          $t8, 0xEE0($v0)
    MEM_W(0XEE0, ctx->r2) = ctx->r24;
L_8057C39C:
    // 0x8057C39C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8057C3A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057C3A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057C3A8: jr          $ra
    // 0x8057C3AC: nop

    return;
    // 0x8057C3AC: nop

;}
RECOMP_FUNC void func_805D2924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2924: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805D2928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D292C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D2930: jal         0x8004700C
    // 0x805D2934: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805D2934: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805D2938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D293C: jal         0x80062D14
    // 0x805D2940: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80062D14(rdram, ctx);
        goto after_1;
    // 0x805D2940: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x805D2944: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x805D2948: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x805D294C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x805D2950: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x805D2954: bne         $t7, $at, L_805D2A6C
    if (ctx->r15 != ctx->r1) {
        // 0x805D2958: sw          $t7, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r15;
            goto L_805D2A6C;
    }
    // 0x805D2958: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x805D295C: beq         $v1, $zero, L_805D2984
    if (ctx->r3 == 0) {
        // 0x805D2960: sw          $zero, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = 0;
            goto L_805D2984;
    }
    // 0x805D2960: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x805D2964: lw          $t9, 0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X34);
    // 0x805D2968: slti        $at, $t9, 0xA0
    ctx->r1 = SIGNED(ctx->r25) < 0XA0 ? 1 : 0;
    // 0x805D296C: beq         $at, $zero, L_805D297C
    if (ctx->r1 == 0) {
        // 0x805D2970: nop
    
            goto L_805D297C;
    }
    // 0x805D2970: nop

    // 0x805D2974: b           L_805D2990
    // 0x805D2978: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D2990;
    // 0x805D2978: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D297C:
    // 0x805D297C: b           L_805D2990
    // 0x805D2980: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_805D2990;
    // 0x805D2980: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_805D2984:
    // 0x805D2984: jal         0x800653D8
    // 0x805D2988: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x805D2988: nop

    after_2:
    // 0x805D298C: andi        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 & 0X1;
L_805D2990:
    // 0x805D2990: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x805D2994: jal         0x805D1F64
    // 0x805D2998: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_805D1F64(rdram, ctx);
        goto after_3;
    // 0x805D2998: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_3:
    // 0x805D299C: beq         $v0, $zero, L_805D2A6C
    if (ctx->r2 == 0) {
        // 0x805D29A0: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_805D2A6C;
    }
    // 0x805D29A0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805D29A4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x805D29A8: jal         0x800653D8
    // 0x805D29AC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x805D29AC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_4:
    // 0x805D29B0: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x805D29B4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x805D29B8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x805D29BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805D29C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805D29C4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x805D29C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805D29CC: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805D29D0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805D29D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805D29D8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805D29DC: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x805D29E0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x805D29E4: swc1        $f6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f6.u32l;
    // 0x805D29E8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805D29EC: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x805D29F0: beq         $v1, $zero, L_805D2A1C
    if (ctx->r3 == 0) {
        // 0x805D29F4: swc1        $f0, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
            goto L_805D2A1C;
    }
    // 0x805D29F4: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x805D29F8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x805D29FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805D2A00: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805D2A04: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x805D2A08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805D2A0C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x805D2A10: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x805D2A14: b           L_805D2A38
    // 0x805D2A18: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
        goto L_805D2A38;
    // 0x805D2A18: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
L_805D2A1C:
    // 0x805D2A1C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805D2A20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805D2A24: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x805D2A28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805D2A2C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x805D2A30: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805D2A34: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
L_805D2A38:
    // 0x805D2A38: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x805D2A3C: jal         0x805D33D8
    // 0x805D2A40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_805D33D8(rdram, ctx);
        goto after_5;
    // 0x805D2A40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_5:
    // 0x805D2A44: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805D2A48: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805D2A4C: beq         $v1, $zero, L_805D2A64
    if (ctx->r3 == 0) {
        // 0x805D2A50: nop
    
            goto L_805D2A64;
    }
    // 0x805D2A50: nop

    // 0x805D2A54: jal         0x805D1CC0
    // 0x805D2A58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_805D1CC0(rdram, ctx);
        goto after_6;
    // 0x805D2A58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x805D2A5C: b           L_805D2A70
    // 0x805D2A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805D2A70;
    // 0x805D2A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D2A64:
    // 0x805D2A64: jal         0x805D1CC0
    // 0x805D2A68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_805D1CC0(rdram, ctx);
        goto after_7;
    // 0x805D2A68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
L_805D2A6C:
    // 0x805D2A6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D2A70:
    // 0x805D2A70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D2A74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805D2A78: jr          $ra
    // 0x805D2A7C: nop

    return;
    // 0x805D2A7C: nop

;}
RECOMP_FUNC void func_804B7048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B7048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B704C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B7050: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804B7054: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804B7058: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804B705C: lui         $t8, 0x804B
    ctx->r24 = S32(RELOC_HI16(182, 0X1108) << 16);
    // 0x804B7060: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804B7064: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804B7068: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804B706C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804B7070: lw          $t8, 0x73A8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(182, 0X1108));
    // 0x804B7074: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804B7078: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804B707C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804B7080: jal         0x80048490
    // 0x804B7084: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804B7084: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804B7088: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B708C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x804B7090: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x804B7094: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804B7098: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x804B709C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804B70A0: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x804B70A4: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804B70A8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804B70AC: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
    // 0x804B70B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B70B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B70B8: jr          $ra
    // 0x804B70BC: nop

    return;
    // 0x804B70BC: nop

;}
RECOMP_FUNC void func_804280D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804280D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804280D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804280DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804280E0: jal         0x80427DC8
    // 0x804280E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80427DC8(rdram, ctx);
        goto after_0;
    // 0x804280E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804280E8: bne         $v0, $zero, L_8042813C
    if (ctx->r2 != 0) {
        // 0x804280EC: nop
    
            goto L_8042813C;
    }
    // 0x804280EC: nop

    // 0x804280F0: jal         0x8004700C
    // 0x804280F4: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x804280F4: nop

    after_1:
    // 0x804280F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804280FC: jal         0x80428080
    // 0x80428100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80428080(rdram, ctx);
        goto after_2;
    // 0x80428100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80428104: jal         0x80427F14
    // 0x80428108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427F14(rdram, ctx);
        goto after_3;
    // 0x80428108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8042810C: jal         0x80427AC0
    // 0x80428110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427AC0(rdram, ctx);
        goto after_4;
    // 0x80428110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80428114: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80428118: beql        $v1, $zero, L_80428148
    if (ctx->r3 == 0) {
        // 0x8042811C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80428148;
    }
    goto skip_0;
    // 0x8042811C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80428120: lw          $t6, 0x180($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X180);
    // 0x80428124: bnel        $s0, $t6, L_80428148
    if (ctx->r16 != ctx->r14) {
        // 0x80428128: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80428148;
    }
    goto skip_1;
    // 0x80428128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8042812C: jal         0x80428008
    // 0x80428130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80428008(rdram, ctx);
        goto after_5;
    // 0x80428130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80428134: b           L_80428148
    // 0x80428138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80428148;
    // 0x80428138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042813C:
    // 0x8042813C: jal         0x80427F5C
    // 0x80428140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427F5C(rdram, ctx);
        goto after_6;
    // 0x80428140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80428144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80428148:
    // 0x80428148: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042814C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80428150: jr          $ra
    // 0x80428154: nop

    return;
    // 0x80428154: nop

;}
RECOMP_FUNC void func_804486E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804486E0: jr          $ra
    // 0x804486E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804486E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80052530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052530: addiu       $sp, $sp, -0x450
    ctx->r29 = ADD32(ctx->r29, -0X450);
    // 0x80052534: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80052538: jal         0x8007C61C
    // 0x8005253C: sw          $a0, 0x450($sp)
    MEM_W(0X450, ctx->r29) = ctx->r4;
    func_8007C61C(rdram, ctx);
        goto after_0;
    // 0x8005253C: sw          $a0, 0x450($sp)
    MEM_W(0X450, ctx->r29) = ctx->r4;
    after_0:
    // 0x80052540: sw          $v0, 0x44C($sp)
    MEM_W(0X44C, ctx->r29) = ctx->r2;
    // 0x80052544: jal         0x80089DF0
    // 0x80052548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osContStartQuery_recomp(rdram, ctx);
        goto after_1;
    // 0x80052548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8005254C: lw          $a0, 0x44C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44C);
    // 0x80052550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80052554: jal         0x800824B0
    // 0x80052558: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80052558: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8005255C: lw          $t6, 0x450($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X450);
    // 0x80052560: addiu       $t8, $sp, 0x434
    ctx->r24 = ADD32(ctx->r29, 0X434);
    // 0x80052564: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80052568: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x8005256C: jal         0x80089E74
    // 0x80052570: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    osContGetQuery_recomp(rdram, ctx);
        goto after_3;
    // 0x80052570: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_3:
    // 0x80052574: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80052578: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x8005257C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80052580: beql        $t0, $zero, L_800525F4
    if (ctx->r8 == 0) {
        // 0x80052584: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800525F4;
    }
    goto skip_0;
    // 0x80052584: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80052588: lbu         $t1, 0x2($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X2);
    // 0x8005258C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052590: addiu       $a0, $a0, -0x4D70
    ctx->r4 = ADD32(ctx->r4, -0X4D70);
    // 0x80052594: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80052598: beq         $t2, $zero, L_800525F0
    if (ctx->r10 == 0) {
        // 0x8005259C: lui         $a1, 0x800A
        ctx->r5 = S32(0X800A << 16);
            goto L_800525F0;
    }
    // 0x8005259C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800525A0: lui         $t3, 0x800B
    ctx->r11 = S32(0X800B << 16);
    // 0x800525A4: addiu       $t3, $t3, 0xAD0
    ctx->r11 = ADD32(ctx->r11, 0XAD0);
    // 0x800525A8: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x800525AC: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x800525B0: addiu       $t4, $sp, 0x448
    ctx->r12 = ADD32(ctx->r29, 0X448);
    // 0x800525B4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800525B8: addiu       $a3, $a3, 0xAC0
    ctx->r7 = ADD32(ctx->r7, 0XAC0);
    // 0x800525BC: lw          $a2, 0x5CC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5CC4);
    // 0x800525C0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800525C4: jal         0x800892E0
    // 0x800525C8: lhu         $a1, 0x5CC0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X5CC0);
    osPfsFindFile_recomp(rdram, ctx);
        goto after_4;
    // 0x800525C8: lhu         $a1, 0x5CC0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X5CC0);
    after_4:
    // 0x800525CC: beq         $v0, $zero, L_800525F0
    if (ctx->r2 == 0) {
        // 0x800525D0: lw          $a0, 0x450($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X450);
            goto L_800525F0;
    }
    // 0x800525D0: lw          $a0, 0x450($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X450);
    // 0x800525D4: or          $a1, $sp, $zero
    ctx->r5 = ctx->r29 | 0;
    // 0x800525D8: addiu       $a1, $a1, 0x2F
    ctx->r5 = ADD32(ctx->r5, 0X2F);
    // 0x800525DC: srl         $a1, $a1, 3
    ctx->r5 = S32(U32(ctx->r5) >> 3);
    // 0x800525E0: jal         0x80052464
    // 0x800525E4: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    func_80052464(rdram, ctx);
        goto after_5;
    // 0x800525E4: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    after_5:
    // 0x800525E8: jal         0x8007C640
    // 0x800525EC: lw          $a0, 0x44C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44C);
    func_8007C640(rdram, ctx);
        goto after_6;
    // 0x800525EC: lw          $a0, 0x44C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44C);
    after_6:
L_800525F0:
    // 0x800525F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800525F4:
    // 0x800525F4: addiu       $sp, $sp, 0x450
    ctx->r29 = ADD32(ctx->r29, 0X450);
    // 0x800525F8: jr          $ra
    // 0x800525FC: nop

    return;
    // 0x800525FC: nop

;}
RECOMP_FUNC void func_8073EBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EBC0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8073EBC4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8073EBC8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8073EBCC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8073EBD0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8073EBD4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8073EBD8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8073EBDC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8073EBE0: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(748, 0X2374) << 16);
    // 0x8073EBE4: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8073EBE8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8073EBEC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8073EBF0: lw          $t1, 0xB64($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(748, 0X2374));
    // 0x8073EBF4: jr          $ra
    // 0x8073EBF8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8073EBF8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_807929FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807929FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80792A00: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80792A04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80792A08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80792A0C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80792A10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80792A14: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x80792A18: addiu       $s1, $a0, 0xC4
    ctx->r17 = ADD32(ctx->r4, 0XC4);
    // 0x80792A1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80792A20: jal         0x807903C4
    // 0x80792A24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807903C4(rdram, ctx);
        goto after_0;
    // 0x80792A24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80792A28: jal         0x80790714
    // 0x80792A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x80792A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80792A30: beq         $v0, $zero, L_80792B54
    if (ctx->r2 == 0) {
        // 0x80792A34: lui         $t6, 0x8010
        ctx->r14 = S32(0X8010 << 16);
            goto L_80792B54;
    }
    // 0x80792A34: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80792A38: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x80792A3C: lw          $t6, -0x7290($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7290);
    // 0x80792A40: lw          $t0, 0x30($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X30);
    // 0x80792A44: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80792A48: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80792A4C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80792A50: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80792A54: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80792A58: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80792A5C: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80792A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80792A64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80792A68: slti        $at, $t3, -0xA
    ctx->r1 = SIGNED(ctx->r11) < -0XA ? 1 : 0;
    // 0x80792A6C: beq         $at, $zero, L_80792A90
    if (ctx->r1 == 0) {
        // 0x80792A70: addiu       $a2, $zero, 0x1C
        ctx->r6 = ADD32(0, 0X1C);
            goto L_80792A90;
    }
    // 0x80792A70: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80792A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80792A78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80792A7C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80792A80: jal         0x8079393C
    // 0x80792A84: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x80792A84: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    after_2:
    // 0x80792A88: b           L_80792B58
    // 0x80792A8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80792B58;
    // 0x80792A8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80792A90:
    // 0x80792A90: jal         0x8079393C
    // 0x80792A94: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    func_8079393C(rdram, ctx);
        goto after_3;
    // 0x80792A94: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    after_3:
    // 0x80792A98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80792A9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80792AA0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80792AA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80792AA8: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x80792AAC: lw          $t4, -0x7290($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7290);
    // 0x80792AB0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80792AB4: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80792AB8: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80792ABC: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x80792AC0: lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X30);
    // 0x80792AC4: lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X2C);
    // 0x80792AC8: jalr        $t9
    // 0x80792ACC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80792ACC: nop

    after_4:
    // 0x80792AD0: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x80792AD4: lw          $t5, -0x7290($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7290);
    // 0x80792AD8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80792ADC: lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X30);
    // 0x80792AE0: lw          $t9, 0x8($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X8);
    // 0x80792AE4: lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X2C);
    // 0x80792AE8: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80792AEC: jalr        $t9
    // 0x80792AF0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x80792AF0: nop

    after_5:
    // 0x80792AF4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80792AF8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80792AFC: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80792B00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80792B04: addiu       $t7, $zero, 0x271
    ctx->r15 = ADD32(0, 0X271);
    // 0x80792B08: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80792B0C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80792B10: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80792B14: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80792B18: swc1        $f2, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f2.u32l;
    // 0x80792B1C: lwc1        $f18, 0x88($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80792B20: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    // 0x80792B24: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80792B28: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80792B2C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80792B30: sub.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80792B34: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80792B38: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x80792B3C: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80792B40: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80792B44: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80792B48: mul.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80792B4C: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    // 0x80792B50: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_80792B54:
    // 0x80792B54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80792B58:
    // 0x80792B58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80792B5C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80792B60: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80792B64: jr          $ra
    // 0x80792B68: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80792B68: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80567AAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80567AAC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80567AB0: lui         $t6, 0x8056
    ctx->r14 = S32(RELOC_HI16(378, 0X298) << 16);
    // 0x80567AB4: addiu       $t6, $t6, 0x7848
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(378, 0X298));
    // 0x80567AB8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80567ABC: jr          $ra
    // 0x80567AC0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80567AC0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_804715E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804715E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804715E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804715EC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804715F0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x804715F4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x804715F8: lh          $t6, 0x30($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X30);
    // 0x804715FC: bnel        $t6, $at, L_80471630
    if (ctx->r14 != ctx->r1) {
        // 0x80471600: lw          $a0, 0x34($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X34);
            goto L_80471630;
    }
    goto skip_0;
    // 0x80471600: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    skip_0:
    // 0x80471604: lw          $a0, 0x34($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X34);
    // 0x80471608: lw          $a1, 0x38($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X38);
    // 0x8047160C: jal         0x80067BBC
    // 0x80471610: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80471610: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80471614: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x80471618: jal         0x80067F78
    // 0x8047161C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8047161C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80471620: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80471624: b           L_80471650
    // 0x80471628: sh          $v0, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r2;
        goto L_80471650;
    // 0x80471628: sh          $v0, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r2;
    // 0x8047162C: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
L_80471630:
    // 0x80471630: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x80471634: jal         0x80067BBC
    // 0x80471638: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80471638: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8047163C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80471640: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x80471644: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80471648: jal         0x800678F0
    // 0x8047164C: lh          $a1, 0x30($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X30);
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x8047164C: lh          $a1, 0x30($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X30);
    after_3:
L_80471650:
    // 0x80471650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80471654: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80471658: jr          $ra
    // 0x8047165C: nop

    return;
    // 0x8047165C: nop

;}
RECOMP_FUNC void func_804C1A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C1A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C1A2C: jal         0x804C192C
    // 0x804C1A30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C192C(rdram, ctx);
        goto after_0;
    // 0x804C1A30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C1A34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C1A38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C1A3C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804C1A40: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x804C1A44: bne         $v0, $zero, L_804C1A5C
    if (ctx->r2 != 0) {
        // 0x804C1A48: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_804C1A5C;
    }
    // 0x804C1A48: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x804C1A4C: jal         0x804C1F2C
    // 0x804C1A50: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_804C1F2C(rdram, ctx);
        goto after_1;
    // 0x804C1A50: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x804C1A54: b           L_804C1A64
    // 0x804C1A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804C1A64;
    // 0x804C1A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C1A5C:
    // 0x804C1A5C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x804C1A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C1A64:
    // 0x804C1A64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C1A68: jr          $ra
    // 0x804C1A6C: nop

    return;
    // 0x804C1A6C: nop

;}
RECOMP_FUNC void func_8042910C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042910C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80429110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80429114: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80429118: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8042911C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80429120: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(41, 0X1E60) << 16);
    // 0x80429124: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80429128: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8042912C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80429130: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80429134: lw          $t8, -0x6860($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(41, 0X1E60));
    // 0x80429138: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042913C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80429140: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80429144: jal         0x80048490
    // 0x80429148: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80429148: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8042914C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80429150: jal         0x80048378
    // 0x80429154: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80429154: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80429158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042915C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80429160: jr          $ra
    // 0x80429164: nop

    return;
    // 0x80429164: nop

;}
RECOMP_FUNC void func_8057E1A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057E1A4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8057E1A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057E1AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057E1B0: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8057E1B4: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8057E1B8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8057E1BC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8057E1C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8057E1C4: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8057E1C8: jal         0x8004921C
    // 0x8057E1CC: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8057E1CC: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    after_0:
    // 0x8057E1D0: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8057E1D4: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8057E1D8: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x8057E1DC: jal         0x8004921C
    // 0x8057E1E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x8057E1E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8057E1E4: andi        $t9, $s0, 0xFF
    ctx->r25 = ctx->r16 & 0XFF;
    // 0x8057E1E8: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x8057E1EC: multu       $t9, $t5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8057E1F0: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x8057E1F4: sh          $v0, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r2;
    // 0x8057E1F8: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8057E1FC: lw          $v1, 0x168($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X168);
    // 0x8057E200: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057E204: addiu       $a2, $a3, 0x84
    ctx->r6 = ADD32(ctx->r7, 0X84);
    // 0x8057E208: lw          $t8, 0x88($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X88);
    // 0x8057E20C: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x8057E210: mflo        $t6
    ctx->r14 = lo;
    // 0x8057E214: lbu         $t7, 0x145($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X145);
    // 0x8057E218: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x8057E21C: lw          $t9, 0x80($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X80);
    // 0x8057E220: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8057E224: lw          $t5, 0x2B8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2B8);
    // 0x8057E228: lui         $t7, 0x8058
    ctx->r15 = S32(RELOC_HI16(393, 0X1048) << 16);
    // 0x8057E22C: sw          $a0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r4;
    // 0x8057E230: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8057E234: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8057E238: lw          $t7, -0x1478($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(393, 0X1048));
    // 0x8057E23C: mflo        $t8
    ctx->r24 = lo;
    // 0x8057E240: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x8057E244: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x8057E248: jal         0x8057DF98
    // 0x8057E24C: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    func_8057DF98(rdram, ctx);
        goto after_2;
    // 0x8057E24C: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    after_2:
    // 0x8057E250: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8057E254: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8057E258: jal         0x80077338
    // 0x8057E25C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80077338(rdram, ctx);
        goto after_3;
    // 0x8057E25C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8057E260: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8057E264: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8057E268: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8057E26C: jal         0x8007711C
    // 0x8057E270: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    func_8007711C(rdram, ctx);
        goto after_4;
    // 0x8057E270: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    after_4:
    // 0x8057E274: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8057E278: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x8057E27C: ori         $t6, $t6, 0x289F
    ctx->r14 = ctx->r14 | 0X289F;
    // 0x8057E280: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x8057E284: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x8057E288: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8057E28C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8057E290: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8057E294: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x8057E298: addiu       $t9, $t7, 0x210
    ctx->r25 = ADD32(ctx->r15, 0X210);
    // 0x8057E29C: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8057E2A0: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8057E2A4: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x8057E2A8: addiu       $a3, $zero, 0x7FF
    ctx->r7 = ADD32(0, 0X7FF);
    // 0x8057E2AC: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x8057E2B0: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x8057E2B4: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8057E2B8: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8057E2BC: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8057E2C0: lui         $t5, 0xF550
    ctx->r13 = S32(0XF550 << 16);
    // 0x8057E2C4: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8057E2C8: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x8057E2CC: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8057E2D0: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x8057E2D4: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x8057E2D8: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x8057E2DC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8057E2E0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8057E2E4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8057E2E8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8057E2EC: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x8057E2F0: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8057E2F4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8057E2F8: lh          $t4, 0x70($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X70);
    // 0x8057E2FC: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8057E300: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8057E304: multu       $s0, $t4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8057E308: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x8057E30C: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x8057E310: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8057E314: or          $t2, $t8, $zero
    ctx->r10 = ctx->r24 | 0;
    // 0x8057E318: mflo        $v0
    ctx->r2 = lo;
    // 0x8057E31C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8057E320: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8057E324: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8057E328: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x8057E32C: beq         $at, $zero, L_8057E33C
    if (ctx->r1 == 0) {
        // 0x8057E330: nop
    
            goto L_8057E33C;
    }
    // 0x8057E330: nop

    // 0x8057E334: b           L_8057E33C
    // 0x8057E338: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_8057E33C;
    // 0x8057E338: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8057E33C:
    // 0x8057E33C: bgez        $t0, L_8057E34C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8057E340: sra         $v0, $t0, 3
        ctx->r2 = S32(SIGNED(ctx->r8) >> 3);
            goto L_8057E34C;
    }
    // 0x8057E340: sra         $v0, $t0, 3
    ctx->r2 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8057E344: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x8057E348: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8057E34C:
    // 0x8057E34C: bgtz        $v0, L_8057E35C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8057E350: andi        $t6, $a3, 0xFFF
        ctx->r14 = ctx->r7 & 0XFFF;
            goto L_8057E35C;
    }
    // 0x8057E350: andi        $t6, $a3, 0xFFF
    ctx->r14 = ctx->r7 & 0XFFF;
    // 0x8057E354: b           L_8057E360
    // 0x8057E358: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8057E360;
    // 0x8057E358: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8057E35C:
    // 0x8057E35C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8057E360:
    // 0x8057E360: bgtz        $v0, L_8057E370
    if (SIGNED(ctx->r2) > 0) {
        // 0x8057E364: addiu       $t7, $t1, 0x7FF
        ctx->r15 = ADD32(ctx->r9, 0X7FF);
            goto L_8057E370;
    }
    // 0x8057E364: addiu       $t7, $t1, 0x7FF
    ctx->r15 = ADD32(ctx->r9, 0X7FF);
    // 0x8057E368: b           L_8057E374
    // 0x8057E36C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8057E374;
    // 0x8057E36C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8057E370:
    // 0x8057E370: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8057E374:
    // 0x8057E374: div         $zero, $t7, $a1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r5)));
    // 0x8057E378: mflo        $t9
    ctx->r25 = lo;
    // 0x8057E37C: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8057E380: bne         $a1, $zero, L_8057E38C
    if (ctx->r5 != 0) {
        // 0x8057E384: nop
    
            goto L_8057E38C;
    }
    // 0x8057E384: nop

    // 0x8057E388: break       7
    do_break(2153243528);
L_8057E38C:
    // 0x8057E38C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8057E390: bne         $a1, $at, L_8057E3A4
    if (ctx->r5 != ctx->r1) {
        // 0x8057E394: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8057E3A4;
    }
    // 0x8057E394: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8057E398: bne         $t7, $at, L_8057E3A4
    if (ctx->r15 != ctx->r1) {
        // 0x8057E39C: nop
    
            goto L_8057E3A4;
    }
    // 0x8057E39C: nop

    // 0x8057E3A0: break       6
    do_break(2153243552);
L_8057E3A4:
    // 0x8057E3A4: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8057E3A8: or          $t5, $t8, $t3
    ctx->r13 = ctx->r24 | ctx->r11;
    // 0x8057E3AC: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x8057E3B0: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8057E3B4: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8057E3B8: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8057E3BC: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8057E3C0: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8057E3C4: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x8057E3C8: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8057E3CC: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8057E3D0: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8057E3D4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8057E3D8: addiu       $t8, $t0, 0x7
    ctx->r24 = ADD32(ctx->r8, 0X7);
    // 0x8057E3DC: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8057E3E0: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8057E3E4: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x8057E3E8: andi        $t5, $t6, 0x1FF
    ctx->r13 = ctx->r14 & 0X1FF;
    // 0x8057E3EC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8057E3F0: sll         $t7, $t5, 9
    ctx->r15 = S32(ctx->r13 << 9);
    // 0x8057E3F4: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8057E3F8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8057E3FC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8057E400: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8057E404: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x8057E408: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8057E40C: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8057E410: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x8057E414: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8057E418: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8057E41C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8057E420: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8057E424: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8057E428: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8057E42C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8057E430: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8057E434: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8057E438: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8057E43C: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8057E440: lui         $t9, 0x8058
    ctx->r25 = S32(RELOC_HI16(393, 0X1000) << 16);
    // 0x8057E444: addiu       $t9, $t9, -0x14C0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(393, 0X1000));
    // 0x8057E448: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x8057E44C: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x8057E450: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8057E454: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8057E458: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8057E45C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8057E460: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8057E464: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8057E468: sw          $t8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r24;
    // 0x8057E46C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8057E470: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057E474: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8057E478: jr          $ra
    // 0x8057E47C: nop

    return;
    // 0x8057E47C: nop

;}
RECOMP_FUNC void func_80078B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078B60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078B68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80078B6C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x80078B70: jal         0x80084820
    // 0x80078B74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _blkclr(rdram, ctx);
        goto after_0;
    // 0x80078B74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80078B78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80078B7C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80078B80: jal         0x80084820
    // 0x80078B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _blkclr(rdram, ctx);
        goto after_1;
    // 0x80078B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80078B88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80078B8C: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80078B90: addiu       $t7, $t7, -0x75C0
    ctx->r15 = ADD32(ctx->r15, -0X75C0);
    // 0x80078B94: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80078B98: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80078B9C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80078BA0: lbu         $t8, 0x8($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X8);
    // 0x80078BA4: sb          $zero, 0x9($a0)
    MEM_B(0X9, ctx->r4) = 0;
    // 0x80078BA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80078BAC: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x80078BB0: sb          $t9, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r25;
    // 0x80078BB4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80078BB8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80078BBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80078BC0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80078BC4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80078BC8: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x80078BCC: sb          $zero, 0x24($a0)
    MEM_B(0X24, ctx->r4) = 0;
    // 0x80078BD0: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x80078BD4: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x80078BD8: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    // 0x80078BDC: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
    // 0x80078BE0: sb          $v1, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r3;
    // 0x80078BE4: sb          $v1, 0x2D($a0)
    MEM_B(0X2D, ctx->r4) = ctx->r3;
    // 0x80078BE8: sb          $v1, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = ctx->r3;
    // 0x80078BEC: sb          $v1, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r3;
    // 0x80078BF0: sw          $t0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r8;
    // 0x80078BF4: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x80078BF8: swc1        $f2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f2.u32l;
    // 0x80078BFC: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x80078C00: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80078C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078C08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078C0C: jr          $ra
    // 0x80078C10: nop

    return;
    // 0x80078C10: nop

    // 0x80078C14: nop

    // 0x80078C18: nop

    // 0x80078C1C: nop

;}
RECOMP_FUNC void func_80672974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80672974: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80672978: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067297C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80672980: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80672984: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80672988: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    // 0x8067298C: beq         $t7, $zero, L_806729A4
    if (ctx->r15 == 0) {
        // 0x80672990: nop
    
            goto L_806729A4;
    }
    // 0x80672990: nop

    // 0x80672994: jal         0x80672750
    // 0x80672998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80672750(rdram, ctx);
        goto after_0;
    // 0x80672998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8067299C: jal         0x806728F4
    // 0x806729A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806728F4(rdram, ctx);
        goto after_1;
    // 0x806729A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_806729A4:
    // 0x806729A4: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x806729A8: lw          $t8, 0x7EA8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7EA8);
    // 0x806729AC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x806729B0: lui         $a0, 0x4014
    ctx->r4 = S32(0X4014 << 16);
    // 0x806729B4: lhu         $v0, 0xC($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0XC);
    // 0x806729B8: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x806729BC: beq         $t9, $at, L_806729DC
    if (ctx->r25 == ctx->r1) {
        // 0x806729C0: andi        $t0, $v0, 0x4000
        ctx->r8 = ctx->r2 & 0X4000;
            goto L_806729DC;
    }
    // 0x806729C0: andi        $t0, $v0, 0x4000
    ctx->r8 = ctx->r2 & 0X4000;
    // 0x806729C4: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x806729C8: beq         $t0, $at, L_806729DC
    if (ctx->r8 == ctx->r1) {
        // 0x806729CC: andi        $t1, $v0, 0x1000
        ctx->r9 = ctx->r2 & 0X1000;
            goto L_806729DC;
    }
    // 0x806729CC: andi        $t1, $v0, 0x1000
    ctx->r9 = ctx->r2 & 0X1000;
    // 0x806729D0: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x806729D4: bnel        $t1, $at, L_80672A24
    if (ctx->r9 != ctx->r1) {
        // 0x806729D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80672A24;
    }
    goto skip_0;
    // 0x806729D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_806729DC:
    // 0x806729DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806729E0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x806729E4: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x806729E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x806729EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x806729F0: jal         0x8004613C
    // 0x806729F4: lw          $a3, 0x44($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X44);
    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x806729F4: lw          $a3, 0x44($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X44);
    after_2:
    // 0x806729F8: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x806729FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80672A00: jal         0x80047F9C
    // 0x80672A04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x80672A04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80672A08: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x80672A0C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80672A10: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80672A14: sb          $t3, 0x17C($t4)
    MEM_B(0X17C, ctx->r12) = ctx->r11;
    // 0x80672A18: jal         0x80672C80
    // 0x80672A1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80672C80(rdram, ctx);
        goto after_4;
    // 0x80672A1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80672A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80672A24:
    // 0x80672A24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80672A28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80672A2C: jr          $ra
    // 0x80672A30: nop

    return;
    // 0x80672A30: nop

;}
RECOMP_FUNC void func_8001D840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D840: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8001D844: lh          $t6, -0x7682($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X7682);
    // 0x8001D848: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x8001D84C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D850: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8001D854: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8001D858: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D85C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001D860: div.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8001D864: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001D868: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001D86C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8001D870: nop

    // 0x8001D874: slti        $at, $v0, -0x7F
    ctx->r1 = SIGNED(ctx->r2) < -0X7F ? 1 : 0;
    // 0x8001D878: beq         $at, $zero, L_8001D888
    if (ctx->r1 == 0) {
        // 0x8001D87C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001D888;
    }
    // 0x8001D87C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001D880: jr          $ra
    // 0x8001D884: addiu       $v0, $zero, -0x7F
    ctx->r2 = ADD32(0, -0X7F);
    return;
    // 0x8001D884: addiu       $v0, $zero, -0x7F
    ctx->r2 = ADD32(0, -0X7F);
L_8001D888:
    // 0x8001D888: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x8001D88C: bne         $at, $zero, L_8001D898
    if (ctx->r1 != 0) {
        // 0x8001D890: nop
    
            goto L_8001D898;
    }
    // 0x8001D890: nop

    // 0x8001D894: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_8001D898:
    // 0x8001D898: jr          $ra
    // 0x8001D89C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001D89C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8076C910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076C910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8076C914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076C918: jal         0x8076C8D0
    // 0x8076C91C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8076C8D0(rdram, ctx);
        goto after_0;
    // 0x8076C91C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8076C920: jal         0x80045BD8
    // 0x8076C924: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8076C924: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8076C928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8076C92C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8076C930: jr          $ra
    // 0x8076C934: nop

    return;
    // 0x8076C934: nop

;}
RECOMP_FUNC void func_804BA728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BA728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BA72C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804BA730: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804BA734: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804BA738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BA73C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804BA740: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804BA744: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x804BA748: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804BA74C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804BA750: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(185, 0X2ADC) << 16);
    // 0x804BA754: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804BA758: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804BA75C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804BA760: lw          $t2, -0x5704($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(185, 0X2ADC));
    // 0x804BA764: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804BA768: jal         0x804BA28C
    // 0x804BA76C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_804BA28C(rdram, ctx);
        goto after_0;
    // 0x804BA76C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x804BA770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BA774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BA778: jr          $ra
    // 0x804BA77C: nop

    return;
    // 0x804BA77C: nop

;}
RECOMP_FUNC void func_805AE7B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE7B4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE7B8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE7BC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE7C0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE7C4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE7C8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE7CC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE7D0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE7D4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE7D8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE7DC: jr          $ra
    // 0x805AE7E0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE7E0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x805AE7E4: nop

    // 0x805AE7E8: nop

    // 0x805AE7EC: nop

;}
RECOMP_FUNC void func_806D2E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D2E60: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D2E64: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806D2E68: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x806D2E6C: bne         $t6, $zero, L_806D2E7C
    if (ctx->r14 != 0) {
        // 0x806D2E70: nop
    
            goto L_806D2E7C;
    }
    // 0x806D2E70: nop

    // 0x806D2E74: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806D2E78: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_806D2E7C:
    // 0x806D2E7C: jr          $ra
    // 0x806D2E80: nop

    return;
    // 0x806D2E80: nop

;}
RECOMP_FUNC void func_80531C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531C28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80531C2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80531C30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80531C34: jal         0x8004700C
    // 0x80531C38: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80531C38: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80531C3C: beq         $v0, $zero, L_80531D54
    if (ctx->r2 == 0) {
        // 0x80531C40: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80531D54;
    }
    // 0x80531C40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80531C44: lw          $t7, 0x174($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X174);
    // 0x80531C48: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80531C4C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80531C50: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80531C54: lw          $a2, 0x1F4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X1F4);
    // 0x80531C58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80531C5C: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x80531C60: lwc1        $f4, 0x268($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X268);
    // 0x80531C64: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80531C68: lwc1        $f6, 0x10($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80531C6C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80531C70: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80531C74: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80531C78: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80531C7C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80531C80: lwc1        $f10, 0x88($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80531C84: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80531C88: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80531C8C: nop

    // 0x80531C90: bc1fl       L_80531CB0
    if (!c1cs) {
        // 0x80531C94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80531CB0;
    }
    goto skip_0;
    // 0x80531C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80531C98: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80531C9C: jal         0x80531880
    // 0x80531CA0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_80531880(rdram, ctx);
        goto after_1;
    // 0x80531CA0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80531CA4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80531CA8: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80531CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80531CB0:
    // 0x80531CB0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80531CB4: jal         0x80531774
    // 0x80531CB8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_80531774(rdram, ctx);
        goto after_2;
    // 0x80531CB8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80531CBC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80531CC0: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80531CC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80531CC8: nop

    // 0x80531CCC: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80531CD0: nop

    // 0x80531CD4: bc1fl       L_80531D58
    if (!c1cs) {
        // 0x80531CD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80531D58;
    }
    goto skip_1;
    // 0x80531CD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80531CDC: jal         0x8002F86C
    // 0x80531CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002F86C(rdram, ctx);
        goto after_3;
    // 0x80531CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80531CE4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80531CE8: jal         0x80531FB8
    // 0x80531CEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80531FB8(rdram, ctx);
        goto after_4;
    // 0x80531CEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80531CF0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80531CF4: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1A18) << 16);
    // 0x80531CF8: lwc1        $f8, 0x2808($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1A18));
    // 0x80531CFC: lwc1        $f6, 0x8C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8C);
    // 0x80531D00: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1A20) << 16);
    // 0x80531D04: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80531D08: nop

    // 0x80531D0C: bc1f        L_80531D20
    if (!c1cs) {
        // 0x80531D10: nop
    
            goto L_80531D20;
    }
    // 0x80531D10: nop

    // 0x80531D14: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1A1C) << 16);
    // 0x80531D18: b           L_80531D24
    // 0x80531D1C: lwc1        $f0, 0x280C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1A1C));
        goto L_80531D24;
    // 0x80531D1C: lwc1        $f0, 0x280C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1A1C));
L_80531D20:
    // 0x80531D20: lwc1        $f0, 0x2810($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1A20));
L_80531D24:
    // 0x80531D24: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80531D28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80531D2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80531D30: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80531D34: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x80531D38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80531D3C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80531D40: jal         0x80047AB8
    // 0x80531D44: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    func_80047AB8(rdram, ctx);
        goto after_5;
    // 0x80531D44: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    after_5:
    // 0x80531D48: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80531D4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80531D50: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
L_80531D54:
    // 0x80531D54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80531D58:
    // 0x80531D58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80531D5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80531D60: jr          $ra
    // 0x80531D64: nop

    return;
    // 0x80531D64: nop

;}
RECOMP_FUNC void func_80048C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048C00: lw          $t6, 0x1D8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1D8);
    // 0x80048C04: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x80048C08: sw          $t6, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->r14;
    // 0x80048C0C: sw          $t8, 0x1DC($a0)
    MEM_W(0X1DC, ctx->r4) = ctx->r24;
    // 0x80048C10: jr          $ra
    // 0x80048C14: sw          $zero, 0x1D8($a1)
    MEM_W(0X1D8, ctx->r5) = 0;
    return;
    // 0x80048C14: sw          $zero, 0x1D8($a1)
    MEM_W(0X1D8, ctx->r5) = 0;
;}
RECOMP_FUNC void func_80446C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446C74: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446C78: jr          $ra
    // 0x80446C7C: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    return;
    // 0x80446C7C: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8001D698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D698: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D69C: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x8001D6A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D6A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001D6A8: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8001D6AC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8001D6B0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8001D6B4: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8001D6B8: lw          $t6, -0x6918($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6918);
    // 0x8001D6BC: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8001D6C0: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x8001D6C4: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8001D6C8: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x8001D6CC: lw          $t8, -0x697C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X697C);
    // 0x8001D6D0: lw          $v1, 0x88($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X88);
    // 0x8001D6D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001D6D8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8001D6DC: jal         0x8004590C
    // 0x8001D6E0: addu        $a1, $t9, $v1
    ctx->r5 = ADD32(ctx->r25, ctx->r3);
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x8001D6E0: addu        $a1, $t9, $v1
    ctx->r5 = ADD32(ctx->r25, ctx->r3);
    after_0:
    // 0x8001D6E4: jal         0x8001CD44
    // 0x8001D6E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8001CD44(rdram, ctx);
        goto after_1;
    // 0x8001D6E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8001D6EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D6F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D6F4: jr          $ra
    // 0x8001D6F8: nop

    return;
    // 0x8001D6F8: nop

;}
RECOMP_FUNC void func_80583D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80583D88: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80583D8C: beql        $at, $zero, L_80583DA0
    if (ctx->r1 == 0) {
        // 0x80583D90: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80583DA0;
    }
    goto skip_0;
    // 0x80583D90: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x80583D94: jr          $ra
    // 0x80583D98: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    return;
    // 0x80583D98: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80583D9C: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_80583DA0:
    // 0x80583DA0: beq         $at, $zero, L_80583DDC
    if (ctx->r1 == 0) {
        // 0x80583DA4: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_80583DDC;
    }
    // 0x80583DA4: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x80583DA8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80583DAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80583DB0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80583DB4: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80583DB8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80583DBC: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x80583DC0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80583DC4: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80583DC8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80583DCC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80583DD0: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80583DD4: jr          $ra
    // 0x80583DD8: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    return;
    // 0x80583DD8: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
L_80583DDC:
    // 0x80583DDC: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80583DE0: beq         $at, $zero, L_80583DF8
    if (ctx->r1 == 0) {
        // 0x80583DE4: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_80583DF8;
    }
    // 0x80583DE4: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80583DE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80583DEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80583DF0: jr          $ra
    // 0x80583DF4: nop

    return;
    // 0x80583DF4: nop

L_80583DF8:
    // 0x80583DF8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80583DFC: beq         $at, $zero, L_80583E3C
    if (ctx->r1 == 0) {
        // 0x80583E00: lw          $v1, 0x14($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X14);
            goto L_80583E3C;
    }
    // 0x80583E00: lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X14);
    // 0x80583E04: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x80583E08: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80583E0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80583E10: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80583E14: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80583E18: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80583E1C: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x80583E20: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80583E24: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80583E28: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80583E2C: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80583E30: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80583E34: jr          $ra
    // 0x80583E38: sub.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f8.fl;
    return;
    // 0x80583E38: sub.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f8.fl;
L_80583E3C:
    // 0x80583E3C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80583E40: beq         $at, $zero, L_80583E7C
    if (ctx->r1 == 0) {
        // 0x80583E44: lwc1        $f0, 0x20($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80583E7C;
    }
    // 0x80583E44: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80583E48: subu        $t0, $a0, $v0
    ctx->r8 = SUB32(ctx->r4, ctx->r2);
    // 0x80583E4C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80583E50: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80583E54: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80583E58: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80583E5C: subu        $t1, $v1, $v0
    ctx->r9 = SUB32(ctx->r3, ctx->r2);
    // 0x80583E60: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80583E64: sub.s       $f16, $f2, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80583E68: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80583E6C: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80583E70: div.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80583E74: jr          $ra
    // 0x80583E78: sub.s       $f0, $f2, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f18.fl;
    return;
    // 0x80583E78: sub.s       $f0, $f2, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f18.fl;
L_80583E7C:
    // 0x80583E7C: jr          $ra
    // 0x80583E80: nop

    return;
    // 0x80583E80: nop

;}
RECOMP_FUNC void func_80554EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80554EF0: lui         $t6, 0x8055
    ctx->r14 = S32(RELOC_HI16(357, 0X19A0) << 16);
    // 0x80554EF4: lw          $t6, 0x6890($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(357, 0X19A0));
    // 0x80554EF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80554EFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80554F00: bne         $t6, $zero, L_80554F2C
    if (ctx->r14 != 0) {
        // 0x80554F04: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80554F2C;
    }
    // 0x80554F04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80554F08: lui         $a0, 0x8055
    ctx->r4 = S32(RELOC_HI16(357, 0X1B30) << 16);
    // 0x80554F0C: lui         $a1, 0x8055
    ctx->r5 = S32(RELOC_HI16(357, 0X1B40) << 16);
    // 0x80554F10: addiu       $a1, $a1, 0x6A30
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(357, 0X1B40));
    // 0x80554F14: addiu       $a0, $a0, 0x6A20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(357, 0X1B30));
    // 0x80554F18: jal         0x8004667C
    // 0x80554F1C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x80554F1C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x80554F20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80554F24: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(357, 0X19A0) << 16);
    // 0x80554F28: sw          $t7, 0x6890($at)
    MEM_W((int16_t)RELOC_LO16(357, 0X19A0), ctx->r1) = ctx->r15;
L_80554F2C:
    // 0x80554F2C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80554F30: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x80554F34: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80554F38: lui         $a2, 0x8055
    ctx->r6 = S32(RELOC_HI16(357, 0X1854) << 16);
    // 0x80554F3C: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x80554F40: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x80554F44: bnel        $t9, $zero, L_80554F58
    if (ctx->r25 != 0) {
        // 0x80554F48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80554F58;
    }
    goto skip_0;
    // 0x80554F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80554F4C: jal         0x80057B28
    // 0x80554F50: addiu       $a2, $a2, 0x6744
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(357, 0X1854));
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x80554F50: addiu       $a2, $a2, 0x6744
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(357, 0X1854));
    after_1:
    // 0x80554F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80554F58:
    // 0x80554F58: lui         $v0, 0x8055
    ctx->r2 = S32(RELOC_HI16(357, 0X144) << 16);
    // 0x80554F5C: addiu       $v0, $v0, 0x5034
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(357, 0X144));
    // 0x80554F60: jr          $ra
    // 0x80554F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80554F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805A4298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A4298: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A429C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A42A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A42A4: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x805A42A8: lw          $v0, 0x16C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X16C);
    // 0x805A42AC: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A42B0: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x805A42B4: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x805A42B8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x805A42BC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x805A42C0: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x805A42C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805A42C8: jal         0x805A46CC
    // 0x805A42CC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_805A46CC(rdram, ctx);
        goto after_0;
    // 0x805A42CC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x805A42D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A42D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A42D8: jr          $ra
    // 0x805A42DC: nop

    return;
    // 0x805A42DC: nop

;}
RECOMP_FUNC void func_804CB930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CB930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CB934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CB938: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CB93C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804CB940: lui         $t9, 0x804D
    ctx->r25 = S32(RELOC_HI16(231, 0X1384) << 16);
    // 0x804CB944: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x804CB948: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804CB94C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x804CB950: lw          $t9, -0x413C($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(231, 0X1384));
    // 0x804CB954: jalr        $t9
    // 0x804CB958: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804CB958: nop

    after_0:
    // 0x804CB95C: jal         0x804CB83C
    // 0x804CB960: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804CB83C(rdram, ctx);
        goto after_1;
    // 0x804CB960: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804CB964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CB968: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CB96C: jr          $ra
    // 0x804CB970: nop

    return;
    // 0x804CB970: nop

;}
RECOMP_FUNC void func_8005F25C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F25C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005F260: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005F264: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8005F268: lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X0);
    // 0x8005F26C: lh          $a3, 0x3E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X3E);
    // 0x8005F270: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005F274: andi        $t6, $v1, 0x8000
    ctx->r14 = ctx->r3 & 0X8000;
    // 0x8005F278: beq         $t6, $zero, L_8005F298
    if (ctx->r14 == 0) {
        // 0x8005F27C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8005F298;
    }
    // 0x8005F27C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005F280: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005F284: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8005F288: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8005F28C: addu        $v1, $t8, $v1
    ctx->r3 = ADD32(ctx->r24, ctx->r3);
    // 0x8005F290: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8005F294: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
L_8005F298:
    // 0x8005F298: lh          $t1, 0x42($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X42);
    // 0x8005F29C: sll         $t9, $v0, 8
    ctx->r25 = S32(ctx->r2 << 8);
    // 0x8005F2A0: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8005F2A4: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8005F2A8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8005F2AC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8005F2B0: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x8005F2B4: jal         0x80073D58
    // 0x8005F2B8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_80073D58(rdram, ctx);
        goto after_0;
    // 0x8005F2B8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x8005F2BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005F2C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005F2C4: jr          $ra
    // 0x8005F2C8: nop

    return;
    // 0x8005F2C8: nop

;}
RECOMP_FUNC void func_8064B1BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B1BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B1C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B1C4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8064B1C8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8064B1CC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8064B1D0: lui         $t8, 0x8065
    ctx->r24 = S32(RELOC_HI16(495, 0X2FA0) << 16);
    // 0x8064B1D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8064B1D8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8064B1DC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8064B1E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8064B1E4: lw          $t8, -0x2F90($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(495, 0X2FA0));
    // 0x8064B1E8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8064B1EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8064B1F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064B1F4: jal         0x80048490
    // 0x8064B1F8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8064B1F8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8064B1FC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8064B200: jal         0x80048378
    // 0x8064B204: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8064B204: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8064B208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064B20C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B210: jr          $ra
    // 0x8064B214: nop

    return;
    // 0x8064B214: nop

;}
RECOMP_FUNC void func_8006D554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D554: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D55C: jal         0x8006D420
    // 0x8006D560: nop

    func_8006D420(rdram, ctx);
        goto after_0;
    // 0x8006D560: nop

    after_0:
    // 0x8006D564: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8006D568: bne         $v0, $at, L_8006D578
    if (ctx->r2 != ctx->r1) {
        // 0x8006D56C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8006D578;
    }
    // 0x8006D56C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8006D570: b           L_8006D58C
    // 0x8006D574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D58C;
    // 0x8006D574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D578:
    // 0x8006D578: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006D57C: lw          $t6, -0x7BB0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7BB0);
    // 0x8006D580: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8006D584: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8006D588: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
L_8006D58C:
    // 0x8006D58C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D590: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D594: jr          $ra
    // 0x8006D598: nop

    return;
    // 0x8006D598: nop

;}
RECOMP_FUNC void func_80430050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430050: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80430054: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0X3828) << 16);
    // 0x80430058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043005C: addiu       $t6, $t6, 0x1908
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0X3828));
    // 0x80430060: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80430064: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80430068: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8043006C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80430070: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80430074: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80430078: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x8043007C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80430080: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80430084: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80430088: jalr        $t9
    // 0x8043008C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8043008C: nop

    after_0:
    // 0x80430090: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80430094: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430098: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8043009C: lwc1        $f4, 0x14($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X14);
    // 0x804300A0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x804300A4: nop

    // 0x804300A8: bc1f        L_804300BC
    if (!c1cs) {
        // 0x804300AC: nop
    
            goto L_804300BC;
    }
    // 0x804300AC: nop

    // 0x804300B0: jal         0x800447C8
    // 0x804300B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x804300B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x804300B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_804300BC:
    // 0x804300BC: jal         0x8042F6B4
    // 0x804300C0: nop

    func_8042F6B4(rdram, ctx);
        goto after_2;
    // 0x804300C0: nop

    after_2:
    // 0x804300C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804300C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804300CC: jr          $ra
    // 0x804300D0: nop

    return;
    // 0x804300D0: nop

;}
RECOMP_FUNC void func_804CFAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CFAA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CFAA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CFAA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804CFAAC: jal         0x80045A34
    // 0x804CFAB0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804CFAB0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x804CFAB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CFAB8: bne         $v0, $zero, L_804CFAC8
    if (ctx->r2 != 0) {
        // 0x804CFABC: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_804CFAC8;
    }
    // 0x804CFABC: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804CFAC0: b           L_804CFAD4
    // 0x804CFAC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CFAD4;
    // 0x804CFAC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CFAC8:
    // 0x804CFAC8: jal         0x804CFA8C
    // 0x804CFACC: nop

    func_804CFA8C(rdram, ctx);
        goto after_1;
    // 0x804CFACC: nop

    after_1:
    // 0x804CFAD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804CFAD4:
    // 0x804CFAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CFAD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CFADC: jr          $ra
    // 0x804CFAE0: nop

    return;
    // 0x804CFAE0: nop

;}
RECOMP_FUNC void func_806D40F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D40F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D40F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D40FC: jal         0x806D3F68
    // 0x806D4100: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_806D3F68(rdram, ctx);
        goto after_0;
    // 0x806D4100: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D4104: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D4108: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x806D410C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806D4110: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D4114: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D4118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806D411C: sh          $t6, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r14;
    // 0x806D4120: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x806D4124: jal         0x806D414C
    // 0x806D4128: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806D414C(rdram, ctx);
        goto after_1;
    // 0x806D4128: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x806D412C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D4130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806D4134: jal         0x806D30C4
    // 0x806D4138: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_806D30C4(rdram, ctx);
        goto after_2;
    // 0x806D4138: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_2:
    // 0x806D413C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D4140: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D4144: jr          $ra
    // 0x806D4148: nop

    return;
    // 0x806D4148: nop

;}
RECOMP_FUNC void func_8002D53C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D53C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002D540: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D544: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D548: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002D54C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002D550: jal         0x8002CF94
    // 0x8002D554: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8002CF94(rdram, ctx);
        goto after_0;
    // 0x8002D554: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002D558: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002D55C: jal         0x8002BB90
    // 0x8002D560: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8002BB90(rdram, ctx);
        goto after_1;
    // 0x8002D560: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8002D564: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002D568: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002D56C: addiu       $a1, $a1, -0x2CFC
    ctx->r5 = ADD32(ctx->r5, -0X2CFC);
    // 0x8002D570: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8002D574: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8002D578: addiu       $t8, $t8, 0x85C
    ctx->r24 = ADD32(ctx->r24, 0X85C);
    // 0x8002D57C: sb          $t6, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r14;
    // 0x8002D580: sb          $t7, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r15;
    // 0x8002D584: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x8002D588: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002D58C: jal         0x80028118
    // 0x8002D590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028118(rdram, ctx);
        goto after_2;
    // 0x8002D590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8002D594: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8002D598: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8002D59C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8002D5A0: lw          $t9, 0xF10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XF10);
    // 0x8002D5A4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8002D5A8: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8002D5AC: lw          $t2, 0xF14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XF14);
    // 0x8002D5B0: beq         $t2, $zero, L_8002D5C0
    if (ctx->r10 == 0) {
        // 0x8002D5B4: nop
    
            goto L_8002D5C0;
    }
    // 0x8002D5B4: nop

    // 0x8002D5B8: jal         0x8002B698
    // 0x8002D5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002B698(rdram, ctx);
        goto after_3;
    // 0x8002D5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8002D5C0:
    // 0x8002D5C0: jal         0x8002B3A0
    // 0x8002D5C4: nop

    func_8002B3A0(rdram, ctx);
        goto after_4;
    // 0x8002D5C4: nop

    after_4:
    // 0x8002D5C8: jal         0x8002AEE4
    // 0x8002D5CC: nop

    func_8002AEE4(rdram, ctx);
        goto after_5;
    // 0x8002D5CC: nop

    after_5:
    // 0x8002D5D0: jal         0x8003ECCC
    // 0x8002D5D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003ECCC(rdram, ctx);
        goto after_6;
    // 0x8002D5D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8002D5D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D5DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002D5E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002D5E4: jr          $ra
    // 0x8002D5E8: nop

    return;
    // 0x8002D5E8: nop

;}
RECOMP_FUNC void func_804F3EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F3EF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804F3EF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804F3EF8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804F3EFC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804F3F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F3F04: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804F3F08: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804F3F0C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x804F3F10: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804F3F14: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804F3F18: lui         $t2, 0x804F
    ctx->r10 = S32(RELOC_HI16(270, 0XD88) << 16);
    // 0x804F3F1C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804F3F20: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804F3F24: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804F3F28: lw          $t2, 0x40B8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(270, 0XD88));
    // 0x804F3F2C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804F3F30: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804F3F34: jal         0x804F3F54
    // 0x804F3F38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804F3F54(rdram, ctx);
        goto after_0;
    // 0x804F3F38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804F3F3C: jal         0x804F3FCC
    // 0x804F3F40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804F3FCC(rdram, ctx);
        goto after_1;
    // 0x804F3F40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804F3F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F3F48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804F3F4C: jr          $ra
    // 0x804F3F50: nop

    return;
    // 0x804F3F50: nop

;}
RECOMP_FUNC void func_806DB900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DB900: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DB904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DB908: jal         0x806DB6C0
    // 0x806DB90C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806DB6C0(rdram, ctx);
        goto after_0;
    // 0x806DB90C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806DB910: jal         0x800447C8
    // 0x806DB914: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x806DB914: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806DB918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DB91C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DB920: jr          $ra
    // 0x806DB924: nop

    return;
    // 0x806DB924: nop

;}
RECOMP_FUNC void func_807036CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807036CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807036D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807036D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807036D8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807036DC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x807036E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807036E4: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x807036E8: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x807036EC: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x807036F0: beq         $t6, $zero, L_80703768
    if (ctx->r14 == 0) {
        // 0x807036F4: lui         $a3, 0x4000
        ctx->r7 = S32(0X4000 << 16);
            goto L_80703768;
    }
    // 0x807036F4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x807036F8: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x807036FC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80703700: beql        $v1, $at, L_8070376C
    if (ctx->r3 == ctx->r1) {
        // 0x80703704: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8070376C;
    }
    goto skip_0;
    // 0x80703704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80703708: lw          $t7, 0x14($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14);
    // 0x8070370C: bnel        $t7, $zero, L_80703830
    if (ctx->r15 != 0) {
        // 0x80703710: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80703830;
    }
    goto skip_1;
    // 0x80703710: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80703714: beq         $v1, $zero, L_8070382C
    if (ctx->r3 == 0) {
        // 0x80703718: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8070382C;
    }
    // 0x80703718: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8070371C: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80703720: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80703724: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80703728: sw          $t8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r24;
    // 0x8070372C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80703730: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    // 0x80703734: jal         0x807041F8
    // 0x80703738: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_807041F8(rdram, ctx);
        goto after_0;
    // 0x80703738: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8070373C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80703740: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80703744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80703748: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070374C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80703750: sw          $t9, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r25;
    // 0x80703754: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80703758: jal         0x80705A5C
    // 0x8070375C: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    func_80705A5C(rdram, ctx);
        goto after_1;
    // 0x8070375C: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    after_1:
    // 0x80703760: b           L_80703830
    // 0x80703764: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80703830;
    // 0x80703764: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80703768:
    // 0x80703768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8070376C:
    // 0x8070376C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80703770: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80703774: jal         0x8004D150
    // 0x80703778: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_8004D150(rdram, ctx);
        goto after_2;
    // 0x80703778: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_2:
    // 0x8070377C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80703780: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80703784: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80703788: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8070378C: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80703790: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x80703794: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x80703798: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8070379C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x807037A0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x807037A4: lbu         $t5, 0x14($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X14);
    // 0x807037A8: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x807037AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807037B0: beql        $t5, $zero, L_80703830
    if (ctx->r13 == 0) {
        // 0x807037B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80703830;
    }
    goto skip_2;
    // 0x807037B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x807037B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x807037BC: jal         0x8004D618
    // 0x807037C0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_8004D618(rdram, ctx);
        goto after_3;
    // 0x807037C0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_3:
    // 0x807037C4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x807037C8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x807037CC: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x807037D0: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x807037D4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x807037D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807037DC: ori         $t7, $t6, 0xF00
    ctx->r15 = ctx->r14 | 0XF00;
    // 0x807037E0: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x807037E4: lw          $t8, 0x40($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X40);
    // 0x807037E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807037EC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x807037F0: bne         $t8, $zero, L_80703810
    if (ctx->r24 != 0) {
        // 0x807037F4: sw          $zero, 0x14($v0)
        MEM_W(0X14, ctx->r2) = 0;
            goto L_80703810;
    }
    // 0x807037F4: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x807037F8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x807037FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80703800: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80703804: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x80703808: swc1        $f10, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f10.u32l;
    // 0x8070380C: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
L_80703810:
    // 0x80703810: lbu         $t1, 0x30($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X30);
    // 0x80703814: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80703818: bnel        $t1, $at, L_80703830
    if (ctx->r9 != ctx->r1) {
        // 0x8070381C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80703830;
    }
    goto skip_3;
    // 0x8070381C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80703820: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80703824: jal         0x80705A5C
    // 0x80703828: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    func_80705A5C(rdram, ctx);
        goto after_4;
    // 0x80703828: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    after_4:
L_8070382C:
    // 0x8070382C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80703830:
    // 0x80703830: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80703834: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80703838: jr          $ra
    // 0x8070383C: nop

    return;
    // 0x8070383C: nop

;}
RECOMP_FUNC void func_80031F3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031F3C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80031F40: lbu         $t6, -0x7D78($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X7D78);
    // 0x80031F44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031F48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031F4C: bnel        $t6, $zero, L_80031F60
    if (ctx->r14 != 0) {
        // 0x80031F50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80031F60;
    }
    goto skip_0;
    // 0x80031F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80031F54: jal         0x8002CE5C
    // 0x80031F58: nop

    func_8002CE5C(rdram, ctx);
        goto after_0;
    // 0x80031F58: nop

    after_0:
    // 0x80031F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031F60:
    // 0x80031F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031F64: jr          $ra
    // 0x80031F68: nop

    return;
    // 0x80031F68: nop

;}
RECOMP_FUNC void func_804486E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804486E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804486EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804486F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804486F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804486F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804486FC: bne         $a2, $zero, L_8044873C
    if (ctx->r6 != 0) {
        // 0x80448700: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_8044873C;
    }
    // 0x80448700: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80448704: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80448708: lw          $v1, 0x78($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X78);
    // 0x8044870C: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x80448710: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80448714: bne         $at, $zero, L_8044877C
    if (ctx->r1 != 0) {
        // 0x80448718: sw          $t7, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r15;
            goto L_8044877C;
    }
    // 0x80448718: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x8044871C: jal         0x804465DC
    // 0x80448720: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804465DC(rdram, ctx);
        goto after_0;
    // 0x80448720: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80448724: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80448728: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044872C: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80448730: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448734: b           L_8044877C
    // 0x80448738: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_8044877C;
    // 0x80448738: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_8044873C:
    // 0x8044873C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80448740: bnel        $a2, $at, L_8044876C
    if (ctx->r6 != ctx->r1) {
        // 0x80448744: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8044876C;
    }
    goto skip_0;
    // 0x80448744: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80448748: jal         0x804465DC
    // 0x8044874C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804465DC(rdram, ctx);
        goto after_1;
    // 0x8044874C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80448750: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80448754: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448758: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8044875C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448760: b           L_8044877C
    // 0x80448764: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_8044877C;
    // 0x80448764: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80448768: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8044876C:
    // 0x8044876C: bnel        $a2, $at, L_80448780
    if (ctx->r6 != ctx->r1) {
        // 0x80448770: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448780;
    }
    goto skip_1;
    // 0x80448770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80448774: jal         0x80446640
    // 0x80448778: nop

    func_80446640(rdram, ctx);
        goto after_2;
    // 0x80448778: nop

    after_2:
L_8044877C:
    // 0x8044877C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448780:
    // 0x80448780: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80448784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448788: jr          $ra
    // 0x8044878C: nop

    return;
    // 0x8044878C: nop

;}
RECOMP_FUNC void func_8078941C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078941C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80789420: lui         $t1, 0x8079
    ctx->r9 = S32(RELOC_HI16(787, 0X2E40) << 16);
    // 0x80789424: lui         $t0, 0x8079
    ctx->r8 = S32(RELOC_HI16(787, 0X2E30) << 16);
    // 0x80789428: addiu       $t0, $t0, -0x6790
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(787, 0X2E30));
    // 0x8078942C: addiu       $t1, $t1, -0x6780
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(787, 0X2E40));
    // 0x80789430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80789434: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80789438:
    // 0x80789438: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8078943C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80789440: addiu       $a3, $a2, 0x10
    ctx->r7 = ADD32(ctx->r6, 0X10);
L_80789444:
    // 0x80789444: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80789448: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8078944C: slti        $at, $a0, 0x16A
    ctx->r1 = SIGNED(ctx->r4) < 0X16A ? 1 : 0;
    // 0x80789450: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80789454: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x80789458: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8078945C: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x80789460: sw          $t6, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->r14;
    // 0x80789464: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x80789468: sw          $t7, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r15;
    // 0x8078946C: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x80789470: sw          $t6, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->r14;
    // 0x80789474: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80789478: sw          $t9, -0x20($a3)
    MEM_W(-0X20, ctx->r7) = ctx->r25;
    // 0x8078947C: lw          $t8, 0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X4);
    // 0x80789480: sw          $t8, -0x1C($a3)
    MEM_W(-0X1C, ctx->r7) = ctx->r24;
    // 0x80789484: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x80789488: sw          $t9, -0x18($a3)
    MEM_W(-0X18, ctx->r7) = ctx->r25;
    // 0x8078948C: lw          $t8, 0xC($t1)
    ctx->r24 = MEM_W(ctx->r9, 0XC);
    // 0x80789490: bne         $at, $zero, L_80789444
    if (ctx->r1 != 0) {
        // 0x80789494: sw          $t8, -0x14($a3)
        MEM_W(-0X14, ctx->r7) = ctx->r24;
            goto L_80789444;
    }
    // 0x80789494: sw          $t8, -0x14($a3)
    MEM_W(-0X14, ctx->r7) = ctx->r24;
    // 0x80789498: addiu       $a1, $a1, 0x16A0
    ctx->r5 = ADD32(ctx->r5, 0X16A0);
    // 0x8078949C: slti        $at, $a1, 0x43E0
    ctx->r1 = SIGNED(ctx->r5) < 0X43E0 ? 1 : 0;
    // 0x807894A0: bne         $at, $zero, L_80789438
    if (ctx->r1 != 0) {
        // 0x807894A4: addiu       $a2, $a2, 0x16A0
        ctx->r6 = ADD32(ctx->r6, 0X16A0);
            goto L_80789438;
    }
    // 0x807894A4: addiu       $a2, $a2, 0x16A0
    ctx->r6 = ADD32(ctx->r6, 0X16A0);
    // 0x807894A8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F68) << 16);
    // 0x807894AC: lwc1        $f0, -0x6658($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F68));
    // 0x807894B0: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F6C) << 16);
    // 0x807894B4: lwc1        $f12, -0x6654($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F6C));
    // 0x807894B8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x807894BC: sb          $zero, 0x520C($v0)
    MEM_B(0X520C, ctx->r2) = 0;
    // 0x807894C0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x807894C4: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x807894C8: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x807894CC: addiu       $a3, $v0, 0x8
    ctx->r7 = ADD32(ctx->r2, 0X8);
    // 0x807894D0: addiu       $v1, $zero, 0x16A
    ctx->r3 = ADD32(0, 0X16A);
    // 0x807894D4: swc1        $f0, 0x43E8($v0)
    MEM_W(0X43E8, ctx->r2) = ctx->f0.u32l;
    // 0x807894D8: swc1        $f0, 0x4C64($v0)
    MEM_W(0X4C64, ctx->r2) = ctx->f0.u32l;
    // 0x807894DC: swc1        $f12, 0x43EC($v0)
    MEM_W(0X43EC, ctx->r2) = ctx->f12.u32l;
    // 0x807894E0: swc1        $f2, 0x4990($v0)
    MEM_W(0X4990, ctx->r2) = ctx->f2.u32l;
    // 0x807894E4: swc1        $f2, 0x4F38($v0)
    MEM_W(0X4F38, ctx->r2) = ctx->f2.u32l;
L_807894E8:
    // 0x807894E8: sb          $zero, 0x520C($a1)
    MEM_B(0X520C, ctx->r5) = 0;
    // 0x807894EC: swc1        $f0, 0x4C64($a2)
    MEM_W(0X4C64, ctx->r6) = ctx->f0.u32l;
    // 0x807894F0: swc1        $f2, 0x4F38($a2)
    MEM_W(0X4F38, ctx->r6) = ctx->f2.u32l;
    // 0x807894F4: swc1        $f2, 0x4990($a2)
    MEM_W(0X4990, ctx->r6) = ctx->f2.u32l;
    // 0x807894F8: swc1        $f0, 0x43E8($a3)
    MEM_W(0X43E8, ctx->r7) = ctx->f0.u32l;
    // 0x807894FC: swc1        $f12, 0x43EC($a3)
    MEM_W(0X43EC, ctx->r7) = ctx->f12.u32l;
    // 0x80789500: sb          $zero, 0x520D($a1)
    MEM_B(0X520D, ctx->r5) = 0;
    // 0x80789504: swc1        $f2, 0x4F3C($a2)
    MEM_W(0X4F3C, ctx->r6) = ctx->f2.u32l;
    // 0x80789508: swc1        $f2, 0x4994($a2)
    MEM_W(0X4994, ctx->r6) = ctx->f2.u32l;
    // 0x8078950C: swc1        $f0, 0x4C68($a2)
    MEM_W(0X4C68, ctx->r6) = ctx->f0.u32l;
    // 0x80789510: swc1        $f12, 0x43F4($a3)
    MEM_W(0X43F4, ctx->r7) = ctx->f12.u32l;
    // 0x80789514: swc1        $f0, 0x43F0($a3)
    MEM_W(0X43F0, ctx->r7) = ctx->f0.u32l;
    // 0x80789518: sb          $zero, 0x520E($a1)
    MEM_B(0X520E, ctx->r5) = 0;
    // 0x8078951C: swc1        $f2, 0x4F40($a2)
    MEM_W(0X4F40, ctx->r6) = ctx->f2.u32l;
    // 0x80789520: swc1        $f2, 0x4998($a2)
    MEM_W(0X4998, ctx->r6) = ctx->f2.u32l;
    // 0x80789524: swc1        $f0, 0x4C6C($a2)
    MEM_W(0X4C6C, ctx->r6) = ctx->f0.u32l;
    // 0x80789528: swc1        $f12, 0x43FC($a3)
    MEM_W(0X43FC, ctx->r7) = ctx->f12.u32l;
    // 0x8078952C: swc1        $f0, 0x43F8($a3)
    MEM_W(0X43F8, ctx->r7) = ctx->f0.u32l;
    // 0x80789530: sb          $zero, 0x520F($a1)
    MEM_B(0X520F, ctx->r5) = 0;
    // 0x80789534: swc1        $f2, 0x4F44($a2)
    MEM_W(0X4F44, ctx->r6) = ctx->f2.u32l;
    // 0x80789538: swc1        $f2, 0x499C($a2)
    MEM_W(0X499C, ctx->r6) = ctx->f2.u32l;
    // 0x8078953C: swc1        $f0, 0x4C70($a2)
    MEM_W(0X4C70, ctx->r6) = ctx->f0.u32l;
    // 0x80789540: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80789544: swc1        $f12, 0x4404($a3)
    MEM_W(0X4404, ctx->r7) = ctx->f12.u32l;
    // 0x80789548: swc1        $f0, 0x4400($a3)
    MEM_W(0X4400, ctx->r7) = ctx->f0.u32l;
    // 0x8078954C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80789550: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80789554: bne         $a0, $v1, L_807894E8
    if (ctx->r4 != ctx->r3) {
        // 0x80789558: addiu       $a3, $a3, 0x20
        ctx->r7 = ADD32(ctx->r7, 0X20);
            goto L_807894E8;
    }
    // 0x80789558: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x8078955C: addiu       $t2, $zero, -0x64
    ctx->r10 = ADD32(0, -0X64);
    // 0x80789560: sw          $zero, 0x43E4($v0)
    MEM_W(0X43E4, ctx->r2) = 0;
    // 0x80789564: sw          $zero, 0x43E0($v0)
    MEM_W(0X43E0, ctx->r2) = 0;
    // 0x80789568: sh          $t2, 0x52C2($v0)
    MEM_H(0X52C2, ctx->r2) = ctx->r10;
    // 0x8078956C: sh          $zero, 0x52F0($v0)
    MEM_H(0X52F0, ctx->r2) = 0;
    // 0x80789570: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F70) << 16);
    // 0x80789574: lwc1        $f4, -0x6650($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F70));
    // 0x80789578: jr          $ra
    // 0x8078957C: swc1        $f4, 0x52C8($v0)
    MEM_W(0X52C8, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x8078957C: swc1        $f4, 0x52C8($v0)
    MEM_W(0X52C8, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80035834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035834: lui         $at, 0x4301
    ctx->r1 = S32(0X4301 << 16);
    // 0x80035838: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8003583C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80035840: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80035844: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80035848: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8003584C: nop

    // 0x80035850: bc1fl       L_80035864
    if (!c1cs) {
        // 0x80035854: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80035864;
    }
    goto skip_0;
    // 0x80035854: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x80035858: b           L_80035880
    // 0x8003585C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80035880;
    // 0x8003585C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80035860: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80035864:
    // 0x80035864: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80035868: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8003586C: nop

    // 0x80035870: bc1f        L_80035880
    if (!c1cs) {
        // 0x80035874: nop
    
            goto L_80035880;
    }
    // 0x80035874: nop

    // 0x80035878: b           L_80035880
    // 0x8003587C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80035880;
    // 0x8003587C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80035880:
    // 0x80035880: sw          $v0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r2;
    // 0x80035884: jr          $ra
    // 0x80035888: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    return;
    // 0x80035888: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80026E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026E20: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x80026E24: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80026E28: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80026E2C: addiu       $t8, $t8, 0x6D10
    ctx->r24 = ADD32(ctx->r24, 0X6D10);
    // 0x80026E30: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80026E34: sb          $t6, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r14;
    // 0x80026E38: sw          $t7, 0x150($a0)
    MEM_W(0X150, ctx->r4) = ctx->r15;
    // 0x80026E3C: jr          $ra
    // 0x80026E40: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
    return;
    // 0x80026E40: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8005FC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FC5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005FC60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FC64: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8005FC68: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005FC6C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005FC70: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005FC74: lbu         $t7, 0x78($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X78);
    // 0x8005FC78: beql        $t7, $zero, L_8005FC9C
    if (ctx->r15 == 0) {
        // 0x8005FC7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FC9C;
    }
    goto skip_0;
    // 0x8005FC7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005FC80: jal         0x8005F9F4
    // 0x8005FC84: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8005F9F4(rdram, ctx);
        goto after_0;
    // 0x8005FC84: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005FC88: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8005FC8C: lw          $t8, 0x174($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X174);
    // 0x8005FC90: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8005FC94: sb          $zero, 0x78($t9)
    MEM_B(0X78, ctx->r25) = 0;
    // 0x8005FC98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FC9C:
    // 0x8005FC9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005FCA0: jr          $ra
    // 0x8005FCA4: nop

    return;
    // 0x8005FCA4: nop

;}
RECOMP_FUNC void func_8001A420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A420: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8001A424: addiu       $v0, $v0, 0x5A0
    ctx->r2 = ADD32(ctx->r2, 0X5A0);
    // 0x8001A428: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001A42C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
L_8001A430:
    // 0x8001A430: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8001A434: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001A438: bnel        $t8, $zero, L_8001A44C
    if (ctx->r24 != 0) {
        // 0x8001A43C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001A44C;
    }
    goto skip_0;
    // 0x8001A43C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8001A440: jr          $ra
    // 0x8001A444: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001A444: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001A448: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8001A44C:
    // 0x8001A44C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001A450: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001A454: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8001A458: bnel        $at, $zero, L_8001A430
    if (ctx->r1 != 0) {
        // 0x8001A45C: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_8001A430;
    }
    goto skip_1;
    // 0x8001A45C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    skip_1:
    // 0x8001A460: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8001A464: jr          $ra
    // 0x8001A468: nop

    return;
    // 0x8001A468: nop

;}
RECOMP_FUNC void func_80053CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053CD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053CE0: jal         0x80053C4C
    // 0x80053CE4: addiu       $a1, $zero, 0x4058
    ctx->r5 = ADD32(0, 0X4058);
    func_80053C4C(rdram, ctx);
        goto after_0;
    // 0x80053CE4: addiu       $a1, $zero, 0x4058
    ctx->r5 = ADD32(0, 0X4058);
    after_0:
    // 0x80053CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053CEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053CF0: jr          $ra
    // 0x80053CF4: nop

    return;
    // 0x80053CF4: nop

;}
RECOMP_FUNC void func_805C7BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C7BAC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C7BB0: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(447, 0X3910) << 16);
    // 0x805C7BB4: addiu       $t7, $t7, -0x6200
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(447, 0X3910));
    // 0x805C7BB8: lw          $v0, 0x3C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X3C);
    // 0x805C7BBC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x805C7BC0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x805C7BC4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x805C7BC8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x805C7BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805C7BD0: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x805C7BD4: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x805C7BD8: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x805C7BDC: lw          $t8, 0x3C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X3C);
    // 0x805C7BE0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x805C7BE4: slti        $at, $t9, 0x7
    ctx->r1 = SIGNED(ctx->r25) < 0X7 ? 1 : 0;
    // 0x805C7BE8: bne         $at, $zero, L_805C7BFC
    if (ctx->r1 != 0) {
        // 0x805C7BEC: sw          $t9, 0x3C($v1)
        MEM_W(0X3C, ctx->r3) = ctx->r25;
            goto L_805C7BFC;
    }
    // 0x805C7BEC: sw          $t9, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r25;
    // 0x805C7BF0: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    // 0x805C7BF4: jr          $ra
    // 0x805C7BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x805C7BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805C7BFC:
    // 0x805C7BFC: jr          $ra
    // 0x805C7C00: nop

    return;
    // 0x805C7C00: nop

;}
RECOMP_FUNC void func_80060960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060968: lw          $a1, 0x40($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X40);
    // 0x8006096C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80060970: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80060974: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x80060978: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x8006097C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80060980: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80060984: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80060988: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8006098C: swc1        $f10, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f10.u32l;
    // 0x80060990: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    // 0x80060994: jal         0x8005FEBC
    // 0x80060998: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8005FEBC(rdram, ctx);
        goto after_0;
    // 0x80060998: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8006099C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800609A0: lw          $a1, 0x40($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X40);
    // 0x800609A4: swc1        $f0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f0.u32l;
    // 0x800609A8: lw          $v1, 0x3C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X3C);
    // 0x800609AC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800609B0: lwc1        $f8, 0x88($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X88);
    // 0x800609B4: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x800609B8: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x800609BC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800609C0: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800609C4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800609C8: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800609CC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800609D0: swc1        $f10, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f10.u32l;
    // 0x800609D4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800609D8: lwc1        $f8, 0x8C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x800609DC: lh          $t1, 0x8($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X8);
    // 0x800609E0: lw          $t0, 0x70($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X70);
    // 0x800609E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800609E8: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800609EC: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800609F0: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800609F4: lwc1        $f16, 0x24($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800609F8: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800609FC: lwc1        $f6, 0x54($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X54);
    // 0x80060A00: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80060A04: swc1        $f18, 0x64($a2)
    MEM_W(0X64, ctx->r6) = ctx->f18.u32l;
    // 0x80060A08: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80060A0C: lwc1        $f4, 0x48($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X48);
    // 0x80060A10: lwc1        $f18, 0x2C($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x80060A14: lwc1        $f0, 0x64($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X64);
    // 0x80060A18: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80060A1C: swc1        $f10, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->f10.u32l;
    // 0x80060A20: lwc1        $f10, 0x28($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X28);
    // 0x80060A24: lwc1        $f6, 0x4C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4C);
    // 0x80060A28: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80060A2C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80060A30: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80060A34: swc1        $f16, 0x68($a2)
    MEM_W(0X68, ctx->r6) = ctx->f16.u32l;
    // 0x80060A38: lwc1        $f2, 0x68($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X68);
    // 0x80060A3C: swc1        $f4, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f4.u32l;
    // 0x80060A40: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80060A44: lwc1        $f12, 0x6C($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x80060A48: swc1        $f10, 0x64($a2)
    MEM_W(0X64, ctx->r6) = ctx->f10.u32l;
    // 0x80060A4C: lwc1        $f18, 0x64($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X64);
    // 0x80060A50: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80060A54: swc1        $f8, 0x68($a2)
    MEM_W(0X68, ctx->r6) = ctx->f8.u32l;
    // 0x80060A58: lwc1        $f6, 0x68($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X68);
    // 0x80060A5C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80060A60: swc1        $f16, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
    // 0x80060A64: lwc1        $f10, 0x6C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x80060A68: lwc1        $f16, 0x30($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X30);
    // 0x80060A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060A70: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80060A74: c.le.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl <= ctx->f16.fl;
    // 0x80060A78: nop

    // 0x80060A7C: bc1f        L_80060A88
    if (!c1cs) {
        // 0x80060A80: nop
    
            goto L_80060A88;
    }
    // 0x80060A80: nop

    // 0x80060A84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060A88:
    // 0x80060A88: jr          $ra
    // 0x80060A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80060A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_807A1A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A1A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A1A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A1A2C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x807A1A30: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x807A1A34: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(841, 0XD6C) << 16);
    // 0x807A1A38: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x807A1A3C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807A1A40: addiu       $t7, $t7, 0x1CAC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(841, 0XD6C));
    // 0x807A1A44: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x807A1A48: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807A1A4C: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x807A1A50: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807A1A54: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x807A1A58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807A1A5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807A1A60: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x807A1A64: lw          $t2, 0x174($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X174);
    // 0x807A1A68: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(841, 0X9C0) << 16);
    // 0x807A1A6C: addiu       $t1, $t1, 0x1900
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(841, 0X9C0));
    // 0x807A1A70: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x807A1A74: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x807A1A78: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x807A1A7C: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    // 0x807A1A80: jal         0x80048378
    // 0x807A1A84: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x807A1A84: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x807A1A88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807A1A8C: jal         0x80045A34
    // 0x807A1A90: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x807A1A90: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x807A1A94: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x807A1A98: sw          $v0, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = ctx->r2;
    // 0x807A1A9C: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x807A1AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A1AA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A1AA8: jr          $ra
    // 0x807A1AAC: nop

    return;
    // 0x807A1AAC: nop

;}
RECOMP_FUNC void func_804C0120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C0124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C0128: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804C012C: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(194, 0X2F0) << 16);
    // 0x804C0130: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804C0134: addiu       $t6, $t6, 0x400
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(194, 0X2F0));
    // 0x804C0138: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804C013C: lw          $t8, 0x180($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X180);
    // 0x804C0140: addiu       $at, $zero, 0x41F9
    ctx->r1 = ADD32(0, 0X41F9);
    // 0x804C0144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804C0148: lhu         $t9, 0xC($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XC);
    // 0x804C014C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C0150: beq         $t9, $at, L_804C0168
    if (ctx->r25 == ctx->r1) {
        // 0x804C0154: nop
    
            goto L_804C0168;
    }
    // 0x804C0154: nop

    // 0x804C0158: jal         0x804C03C0
    // 0x804C015C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804C03C0(rdram, ctx);
        goto after_0;
    // 0x804C015C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x804C0160: b           L_804C0174
    // 0x804C0164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804C0174;
    // 0x804C0164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C0168:
    // 0x804C0168: jal         0x804C03C0
    // 0x804C016C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804C03C0(rdram, ctx);
        goto after_1;
    // 0x804C016C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x804C0170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C0174:
    // 0x804C0174: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804C0178: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804C017C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x804C0180: jr          $ra
    // 0x804C0184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804C0184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80678598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80678598: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067859C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806785A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806785A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806785A8: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x806785AC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x806785B0: jal         0x806780B4
    // 0x806785B4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_806780B4(rdram, ctx);
        goto after_0;
    // 0x806785B4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x806785B8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x806785BC: jal         0x806781B0
    // 0x806785C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_806781B0(rdram, ctx);
        goto after_1;
    // 0x806785C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x806785C4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x806785C8: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x806785CC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806785D0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x806785D4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x806785D8: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x806785DC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x806785E0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x806785E4: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x806785E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806785EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806785F0: jr          $ra
    // 0x806785F4: nop

    return;
    // 0x806785F4: nop

;}
RECOMP_FUNC void func_805D264C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D264C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805D2650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D2654: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x805D2658: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x805D265C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805D2660: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x805D2664: lw          $t7, 0x12C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X12C);
    // 0x805D2668: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805D266C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805D2670: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D2674: bne         $t7, $at, L_805D26BC
    if (ctx->r15 != ctx->r1) {
        // 0x805D2678: add.s       $f12, $f6, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_805D26BC;
    }
    // 0x805D2678: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x805D267C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x805D2680: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x805D2684: jal         0x80066DE4
    // 0x805D2688: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x805D2688: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x805D268C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x805D2690: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x805D2694: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805D2698: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x805D269C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805D26A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x805D26A4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x805D26A8: sub.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x805D26AC: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x805D26B0: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x805D26B4: b           L_805D26FC
    // 0x805D26B8: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
        goto L_805D26FC;
    // 0x805D26B8: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
L_805D26BC:
    // 0x805D26BC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x805D26C0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x805D26C4: jal         0x80066DE4
    // 0x805D26C8: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x805D26C8: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x805D26CC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x805D26D0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x805D26D4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x805D26D8: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x805D26DC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805D26E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805D26E4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805D26E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x805D26EC: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x805D26F0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x805D26F4: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x805D26F8: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
L_805D26FC:
    // 0x805D26FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x805D2700: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x805D2704: jal         0x80066E88
    // 0x805D2708: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x805D2708: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_2:
    // 0x805D270C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x805D2710: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x805D2714: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x805D2718: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x805D271C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x805D2720: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x805D2724: lw          $t8, 0x1E0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1E0);
    // 0x805D2728: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x805D272C: jal         0x805D1DF8
    // 0x805D2730: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
    func_805D1DF8(rdram, ctx);
        goto after_3;
    // 0x805D2730: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
    after_3:
    // 0x805D2734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D2738: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805D273C: jr          $ra
    // 0x805D2740: nop

    return;
    // 0x805D2740: nop

;}
RECOMP_FUNC void func_8005FF38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FF38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005FF3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FF40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005FF44: jal         0x80049018
    // 0x8005FF48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x8005FF48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005FF4C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FF50: beq         $v0, $zero, L_8005FF80
    if (ctx->r2 == 0) {
        // 0x8005FF54: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8005FF80;
    }
    // 0x8005FF54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005FF58: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FF5C: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8005FF60: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8005FF64: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x8005FF68: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8005FF6C: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8005FF70: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005FF74: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8005FF78: b           L_8005FFA4
    // 0x8005FF7C: sub.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f10.fl;
        goto L_8005FFA4;
    // 0x8005FF7C: sub.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f10.fl;
L_8005FF80:
    // 0x8005FF80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FF84: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8005FF88: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x8005FF8C: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x8005FF90: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8005FF94: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8005FF98: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005FF9C: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8005FFA0: add.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f16.fl;
L_8005FFA4:
    // 0x8005FFA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005FFA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005FFAC: jr          $ra
    // 0x8005FFB0: nop

    return;
    // 0x8005FFB0: nop

;}
RECOMP_FUNC void func_80536504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536504: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536508: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053650C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536510: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536514: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536518: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053651C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536520: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536524: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536528: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053652C: jr          $ra
    // 0x80536530: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536530: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8002491C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002491C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80024920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024924: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80024928: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x8002492C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80024930: lh          $a0, -0x7680($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7680);
    // 0x80024934: jal         0x8006593C
    // 0x80024938: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80024938: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x8002493C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80024940: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80024944: lh          $a0, -0x7680($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7680);
    // 0x80024948: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x8002494C: jal         0x8006593C
    // 0x80024950: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8006593C(rdram, ctx);
        goto after_1;
    // 0x80024950: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80024954: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80024958: bne         $at, $zero, L_80024968
    if (ctx->r1 != 0) {
        // 0x8002495C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80024968;
    }
    // 0x8002495C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80024960: b           L_8002496C
    // 0x80024964: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
        goto L_8002496C;
    // 0x80024964: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
L_80024968:
    // 0x80024968: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8002496C:
    // 0x8002496C: addiu       $t9, $a0, -0x27
    ctx->r25 = ADD32(ctx->r4, -0X27);
    // 0x80024970: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80024974: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80024978: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002497C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80024980: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x80024984: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80024988: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8002498C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80024990: bgez        $a1, L_800249A4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80024994: div.s       $f10, $f6, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
            goto L_800249A4;
    }
    // 0x80024994: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80024998: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002499C: nop

    // 0x800249A0: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800249A4:
    // 0x800249A4: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800249A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800249AC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800249B0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800249B4: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800249B8: nop

    // 0x800249BC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800249C0: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800249C4: nop

    // 0x800249C8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800249CC: beql        $v0, $zero, L_80024A1C
    if (ctx->r2 == 0) {
        // 0x800249D0: mfc1        $v0, $f8
        ctx->r2 = (int32_t)ctx->f8.u32l;
            goto L_80024A1C;
    }
    goto skip_0;
    // 0x800249D0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x800249D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800249D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800249DC: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800249E0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800249E4: nop

    // 0x800249E8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800249EC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800249F0: nop

    // 0x800249F4: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800249F8: bne         $v0, $zero, L_80024A10
    if (ctx->r2 != 0) {
        // 0x800249FC: nop
    
            goto L_80024A10;
    }
    // 0x800249FC: nop

    // 0x80024A00: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80024A04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024A08: b           L_80024A28
    // 0x80024A0C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80024A28;
    // 0x80024A0C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80024A10:
    // 0x80024A10: b           L_80024A28
    // 0x80024A14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80024A28;
    // 0x80024A14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80024A18: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
L_80024A1C:
    // 0x80024A1C: nop

    // 0x80024A20: bltz        $v0, L_80024A10
    if (SIGNED(ctx->r2) < 0) {
        // 0x80024A24: nop
    
            goto L_80024A10;
    }
    // 0x80024A24: nop

L_80024A28:
    // 0x80024A28: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80024A2C: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80024A30: bne         $at, $zero, L_80024A3C
    if (ctx->r1 != 0) {
        // 0x80024A34: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80024A3C;
    }
    // 0x80024A34: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80024A38: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
L_80024A3C:
    // 0x80024A3C: lw          $a1, 0x14C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X14C);
    // 0x80024A40: beq         $v1, $a1, L_80024A64
    if (ctx->r3 == ctx->r5) {
        // 0x80024A44: addu        $a0, $v1, $a1
        ctx->r4 = ADD32(ctx->r3, ctx->r5);
            goto L_80024A64;
    }
    // 0x80024A44: addu        $a0, $v1, $a1
    ctx->r4 = ADD32(ctx->r3, ctx->r5);
    // 0x80024A48: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x80024A4C: bne         $a1, $a0, L_80024A60
    if (ctx->r5 != ctx->r4) {
        // 0x80024A50: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80024A60;
    }
    // 0x80024A50: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80024A54: beql        $a0, $v1, L_80024A64
    if (ctx->r4 == ctx->r3) {
        // 0x80024A58: sw          $a2, 0x14C($a3)
        MEM_W(0X14C, ctx->r7) = ctx->r6;
            goto L_80024A64;
    }
    goto skip_1;
    // 0x80024A58: sw          $a2, 0x14C($a3)
    MEM_W(0X14C, ctx->r7) = ctx->r6;
    skip_1:
    // 0x80024A5C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_80024A60:
    // 0x80024A60: sw          $a2, 0x14C($a3)
    MEM_W(0X14C, ctx->r7) = ctx->r6;
L_80024A64:
    // 0x80024A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024A68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80024A6C: jr          $ra
    // 0x80024A70: nop

    return;
    // 0x80024A70: nop

;}
RECOMP_FUNC void func_80058B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058B44: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80058B48: lw          $v0, -0x6DA8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6DA8);
    // 0x80058B4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80058B50: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80058B54: addiu       $a2, $v0, 0x120
    ctx->r6 = ADD32(ctx->r2, 0X120);
    // 0x80058B58: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80058B5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80058B60:
    // 0x80058B60: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80058B64: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80058B68: beq         $v1, $zero, L_80058B84
    if (ctx->r3 == 0) {
        // 0x80058B6C: nop
    
            goto L_80058B84;
    }
    // 0x80058B6C: nop

    // 0x80058B70: lhu         $t6, 0xC($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XC);
    // 0x80058B74: bne         $a0, $t6, L_80058B84
    if (ctx->r4 != ctx->r14) {
        // 0x80058B78: nop
    
            goto L_80058B84;
    }
    // 0x80058B78: nop

    // 0x80058B7C: jr          $ra
    // 0x80058B80: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80058B80: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80058B84:
    // 0x80058B84: bne         $a1, $v0, L_80058B60
    if (ctx->r5 != ctx->r2) {
        // 0x80058B88: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80058B60;
    }
    // 0x80058B88: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80058B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80058B90: jr          $ra
    // 0x80058B94: nop

    return;
    // 0x80058B94: nop

;}
RECOMP_FUNC void func_807808AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807808AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807808B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807808B4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x807808B8: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    // 0x807808BC: jal         0x80067878
    // 0x807808C0: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x807808C0: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_0:
    // 0x807808C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807808C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807808CC: jr          $ra
    // 0x807808D0: nop

    return;
    // 0x807808D0: nop

;}
RECOMP_FUNC void func_8000372C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000372C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80003730: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80003734: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80003738: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x8000373C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80003740: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80003744: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x80003748: sh          $v1, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r3;
    // 0x8000374C: sh          $v1, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r3;
    // 0x80003750: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x80003754: jr          $ra
    // 0x80003758: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    return;
    // 0x80003758: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_804C08E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C08E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C08EC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804C08F0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804C08F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C08F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C08FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804C0900: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804C0904: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C0908: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804C090C: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(197, 0X4F8) << 16);
    // 0x804C0910: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804C0914: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804C0918: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804C091C: lw          $t1, 0x9B8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(197, 0X4F8));
    // 0x804C0920: jal         0x804C0938
    // 0x804C0924: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_804C0938(rdram, ctx);
        goto after_0;
    // 0x804C0924: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x804C0928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C092C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C0930: jr          $ra
    // 0x804C0934: nop

    return;
    // 0x804C0934: nop

;}
RECOMP_FUNC void func_80467610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80467610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80467614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80467618: jal         0x8005780C
    // 0x8046761C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    func_8005780C(rdram, ctx);
        goto after_0;
    // 0x8046761C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x80467620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80467624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80467628: jr          $ra
    // 0x8046762C: nop

    return;
    // 0x8046762C: nop

;}
RECOMP_FUNC void func_807AAEE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AAEE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AAEEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AAEF0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807AAEF4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807AAEF8: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AAEFC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807AAF00: jal         0x807A9D84
    // 0x807AAF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A9D84(rdram, ctx);
        goto after_0;
    // 0x807AAF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x807AAF08: lwc1        $f4, 0x50($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X50);
    // 0x807AAF0C: lwc1        $f6, 0xC0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x807AAF10: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x807AAF14: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x807AAF18: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807AAF1C: swc1        $f8, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f8.u32l;
    // 0x807AAF20: jal         0x80067170
    // 0x807AAF24: lw          $a1, 0xD4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XD4);
    func_80067170(rdram, ctx);
        goto after_1;
    // 0x807AAF24: lw          $a1, 0xD4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XD4);
    after_1:
    // 0x807AAF28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AAF2C: jal         0x807AA878
    // 0x807AAF30: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    func_807AA878(rdram, ctx);
        goto after_2;
    // 0x807AAF30: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    after_2:
    // 0x807AAF34: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C28) << 16);
    // 0x807AAF38: lwc1        $f12, -0x4798($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C28));
    // 0x807AAF3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807AAF40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807AAF44: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C2C) << 16);
    // 0x807AAF48: lwc1        $f18, -0x4794($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C2C));
    // 0x807AAF4C: lwc1        $f10, 0xCC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x807AAF50: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x807AAF54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807AAF58: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x807AAF5C: swc1        $f4, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f4.u32l;
    // 0x807AAF60: lwc1        $f2, 0xCC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x807AAF64: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x807AAF68: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x807AAF6C: nop

    // 0x807AAF70: bc1tl       L_807AAFA0
    if (c1cs) {
        // 0x807AAF74: swc1        $f16, 0xCC($s0)
        MEM_W(0XCC, ctx->r16) = ctx->f16.u32l;
            goto L_807AAFA0;
    }
    goto skip_0;
    // 0x807AAF74: swc1        $f16, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f16.u32l;
    skip_0:
    // 0x807AAF78: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x807AAF7C: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x807AAF80: nop

    // 0x807AAF84: bc1tl       L_807AAFA8
    if (c1cs) {
        // 0x807AAF88: lwc1        $f12, 0xEC($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0XEC);
            goto L_807AAFA8;
    }
    goto skip_1;
    // 0x807AAF88: lwc1        $f12, 0xEC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XEC);
    skip_1:
    // 0x807AAF8C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x807AAF90: nop

    // 0x807AAF94: bc1tl       L_807AAFA8
    if (c1cs) {
        // 0x807AAF98: lwc1        $f12, 0xEC($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0XEC);
            goto L_807AAFA8;
    }
    goto skip_2;
    // 0x807AAF98: lwc1        $f12, 0xEC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XEC);
    skip_2:
    // 0x807AAF9C: swc1        $f16, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f16.u32l;
L_807AAFA0:
    // 0x807AAFA0: lwc1        $f2, 0xCC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x807AAFA4: lwc1        $f12, 0xEC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XEC);
L_807AAFA8:
    // 0x807AAFA8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x807AAFAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807AAFB0: sub.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x807AAFB4: lwc1        $f14, 0xE8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x807AAFB8: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x807AAFBC: sub.s       $f0, $f4, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x807AAFC0: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x807AAFC4: add.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x807AAFC8: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
    // 0x807AAFCC: add.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x807AAFD0: swc1        $f8, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f8.u32l;
    // 0x807AAFD4: lwc1        $f18, 0xD0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x807AAFD8: lwc1        $f10, 0xD4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD4);
    // 0x807AAFDC: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x807AAFE0: nop

    // 0x807AAFE4: bc1fl       L_807AB01C
    if (!c1cs) {
        // 0x807AAFE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807AB01C;
    }
    goto skip_3;
    // 0x807AAFE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x807AAFEC: lwc1        $f4, 0xCC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x807AAFF0: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x807AAFF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807AAFF8: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x807AAFFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AB000: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x807AB004: bc1fl       L_807AB01C
    if (!c1cs) {
        // 0x807AB008: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807AB01C;
    }
    goto skip_4;
    // 0x807AB008: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x807AB00C: sw          $t6, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->r14;
    // 0x807AB010: jal         0x807AB278
    // 0x807AB014: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    func_807AB278(rdram, ctx);
        goto after_3;
    // 0x807AB014: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    after_3:
    // 0x807AB018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807AB01C:
    // 0x807AB01C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807AB020: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807AB024: jr          $ra
    // 0x807AB028: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x807AB028: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806B2064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2064: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B2068: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806B206C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806B2070: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806B2074: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806B2078: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806B207C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806B2080: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B2084: addiu       $t6, $zero, 0x1D10
    ctx->r14 = ADD32(0, 0X1D10);
    // 0x806B2088: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806B208C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x806B2090: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x806B2094: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x806B2098: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x806B209C: jal         0x806B195C
    // 0x806B20A0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_806B195C(rdram, ctx);
        goto after_0;
    // 0x806B20A0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x806B20A4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806B20A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B20AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806B20B0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B20B4: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x806B20B8: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x806B20BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806B20C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B20C4: jr          $ra
    // 0x806B20C8: nop

    return;
    // 0x806B20C8: nop

;}
RECOMP_FUNC void func_80681480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80681480: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80681484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80681488: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8068148C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80681490: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80681494: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80681498: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x8068149C: swc1        $f4, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->f4.u32l;
    // 0x806814A0: swc1        $f6, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->f6.u32l;
    // 0x806814A4: jal         0x80086F28
    // 0x806814A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gMtxIdent(rdram, ctx);
        goto after_0;
    // 0x806814A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x806814AC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806814B0: jal         0x80086F28
    // 0x806814B4: addiu       $a0, $v0, 0x48
    ctx->r4 = ADD32(ctx->r2, 0X48);
    gMtxIdent(rdram, ctx);
        goto after_1;
    // 0x806814B4: addiu       $a0, $v0, 0x48
    ctx->r4 = ADD32(ctx->r2, 0X48);
    after_1:
    // 0x806814B8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806814BC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x806814C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806814C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806814C8: jr          $ra
    // 0x806814CC: nop

    return;
    // 0x806814CC: nop

;}
RECOMP_FUNC void func_806F9A9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9A9C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x806F9AA0: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(697, 0X5CC) << 16);
    // 0x806F9AA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F9AA8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x806F9AAC: lwc1        $f0, -0x64B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(697, 0X5CC));
    // 0x806F9AB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F9AB4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806F9AB8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x806F9ABC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806F9AC0: jal         0x806F9A78
    // 0x806F9AC4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_806F9A78(rdram, ctx);
        goto after_0;
    // 0x806F9AC4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x806F9AC8: jal         0x806F98AC
    // 0x806F9ACC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_806F98AC(rdram, ctx);
        goto after_1;
    // 0x806F9ACC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x806F9AD0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x806F9AD4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806F9AD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806F9ADC: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x806F9AE0: swc1        $f2, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f2.u32l;
    // 0x806F9AE4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806F9AE8: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806F9AEC: lwc1        $f6, 0x84($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X84);
    // 0x806F9AF0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806F9AF4: nop

    // 0x806F9AF8: bc1f        L_806F9B0C
    if (!c1cs) {
        // 0x806F9AFC: nop
    
            goto L_806F9B0C;
    }
    // 0x806F9AFC: nop

    // 0x806F9B00: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x806F9B04: b           L_806F9B14
    // 0x806F9B08: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
        goto L_806F9B14;
    // 0x806F9B08: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
L_806F9B0C:
    // 0x806F9B0C: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x806F9B10: swc1        $f10, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f10.u32l;
L_806F9B14:
    // 0x806F9B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F9B18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F9B1C: jr          $ra
    // 0x806F9B20: nop

    return;
    // 0x806F9B20: nop

    // 0x806F9B24: nop

    // 0x806F9B28: nop

    // 0x806F9B2C: nop

;}
RECOMP_FUNC void func_80427DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427DC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80427DCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80427DD0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80427DD4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80427DD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80427DDC: jal         0x8004700C
    // 0x80427DE0: lw          $s1, 0x174($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X174);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80427DE0: lw          $s1, 0x174($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X174);
    after_0:
    // 0x80427DE4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80427DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80427DEC: jal         0x80049D74
    // 0x80427DF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80049D74(rdram, ctx);
        goto after_1;
    // 0x80427DF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80427DF4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80427DF8: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x80427DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80427E00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80427E04: jal         0x8004D150
    // 0x80427E08: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_2;
    // 0x80427E08: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80427E0C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80427E10: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80427E14: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    // 0x80427E18: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x80427E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80427E20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80427E24: lbu         $t8, 0x14($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X14);
    // 0x80427E28: beq         $t8, $zero, L_80427E38
    if (ctx->r24 == 0) {
        // 0x80427E2C: nop
    
            goto L_80427E38;
    }
    // 0x80427E2C: nop

    // 0x80427E30: b           L_80427F00
    // 0x80427E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80427F00;
    // 0x80427E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80427E38:
    // 0x80427E38: jal         0x8004D150
    // 0x80427E3C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x80427E3C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80427E40: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80427E44: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80427E48: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x80427E4C: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x80427E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80427E54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80427E58: lbu         $t1, 0x2C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2C);
    // 0x80427E5C: beq         $t1, $zero, L_80427E6C
    if (ctx->r9 == 0) {
        // 0x80427E60: nop
    
            goto L_80427E6C;
    }
    // 0x80427E60: nop

    // 0x80427E64: b           L_80427F00
    // 0x80427E68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80427F00;
    // 0x80427E68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80427E6C:
    // 0x80427E6C: jal         0x8004D150
    // 0x80427E70: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_4;
    // 0x80427E70: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80427E74: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80427E78: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80427E7C: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x80427E80: lw          $t3, 0x40($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X40);
    // 0x80427E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80427E88: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80427E8C: lbu         $t4, 0x44($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X44);
    // 0x80427E90: beq         $t4, $zero, L_80427EA0
    if (ctx->r12 == 0) {
        // 0x80427E94: nop
    
            goto L_80427EA0;
    }
    // 0x80427E94: nop

    // 0x80427E98: b           L_80427F00
    // 0x80427E9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80427F00;
    // 0x80427E9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80427EA0:
    // 0x80427EA0: jal         0x8004D150
    // 0x80427EA4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_5;
    // 0x80427EA4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_5:
    // 0x80427EA8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80427EAC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80427EB0: lw          $t6, 0x40($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X40);
    // 0x80427EB4: lbu         $t7, 0x5C($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5C);
    // 0x80427EB8: beq         $t7, $zero, L_80427EC8
    if (ctx->r15 == 0) {
        // 0x80427EBC: nop
    
            goto L_80427EC8;
    }
    // 0x80427EBC: nop

    // 0x80427EC0: b           L_80427F00
    // 0x80427EC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80427F00;
    // 0x80427EC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80427EC8:
    // 0x80427EC8: beq         $v1, $zero, L_80427EF4
    if (ctx->r3 == 0) {
        // 0x80427ECC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80427EF4;
    }
    // 0x80427ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80427ED0: lw          $t8, 0x180($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X180);
    // 0x80427ED4: bne         $s0, $t8, L_80427EF4
    if (ctx->r16 != ctx->r24) {
        // 0x80427ED8: nop
    
            goto L_80427EF4;
    }
    // 0x80427ED8: nop

    // 0x80427EDC: lw          $v0, 0x174($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X174);
    // 0x80427EE0: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80427EE4: beq         $t9, $zero, L_80427EF4
    if (ctx->r25 == 0) {
        // 0x80427EE8: nop
    
            goto L_80427EF4;
    }
    // 0x80427EE8: nop

    // 0x80427EEC: b           L_80427F00
    // 0x80427EF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80427F00;
    // 0x80427EF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80427EF4:
    // 0x80427EF4: jal         0x80062748
    // 0x80427EF8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062748(rdram, ctx);
        goto after_6;
    // 0x80427EF8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_6:
    // 0x80427EFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80427F00:
    // 0x80427F00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80427F04: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80427F08: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80427F0C: jr          $ra
    // 0x80427F10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80427F10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805AE294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE294: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE298: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE29C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE2A0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE2A4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE2A8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE2AC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE2B0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE2B4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE2B8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE2BC: jr          $ra
    // 0x805AE2C0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE2C0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804552B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804552B4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x804552B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804552BC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x804552C0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x804552C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804552C8: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804552CC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804552D0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x804552D4: lw          $v0, 0xA5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA5C);
    // 0x804552D8: addu        $s2, $s0, $at
    ctx->r18 = ADD32(ctx->r16, ctx->r1);
    // 0x804552DC: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x804552E0: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x804552E4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x804552E8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x804552EC: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x804552F0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x804552F4: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x804552F8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x804552FC: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80455300: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80455304: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80455308: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8045530C: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80455310: addiu       $t8, $t7, 0xAE0
    ctx->r24 = ADD32(ctx->r15, 0XAE0);
    // 0x80455314: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80455318: lw          $a1, 0x6F04($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X6F04);
    // 0x8045531C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80455320: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80455324: jal         0x8044EEF8
    // 0x80455328: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8044EEF8(rdram, ctx);
        goto after_0;
    // 0x80455328: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
    // 0x8045532C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80455330: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80455334: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80455338: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8045533C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80455340: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80455344: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80455348: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8045534C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80455350: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x80455354: addu        $a1, $s0, $t0
    ctx->r5 = ADD32(ctx->r16, ctx->r8);
    // 0x80455358: jal         0x8044ED68
    // 0x8045535C: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_1;
    // 0x8045535C: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_1:
    // 0x80455360: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80455364: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80455368: jal         0x8044F178
    // 0x8045536C: sw          $t1, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r9;
    func_8044F178(rdram, ctx);
        goto after_2;
    // 0x8045536C: sw          $t1, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r9;
    after_2:
    // 0x80455370: jal         0x8044F384
    // 0x80455374: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8044F384(rdram, ctx);
        goto after_3;
    // 0x80455374: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80455378: lwc1        $f0, 0x6C84($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X6C84);
    // 0x8045537C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80455380: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80455384: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80455388: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8045538C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80455390: bc1fl       L_804553DC
    if (!c1cs) {
        // 0x80455394: lw          $t2, 0xFB4($v0)
        ctx->r10 = MEM_W(ctx->r2, 0XFB4);
            goto L_804553DC;
    }
    goto skip_0;
    // 0x80455394: lw          $t2, 0xFB4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XFB4);
    skip_0:
    // 0x80455398: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8045539C: nop

    // 0x804553A0: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x804553A4: nop

    // 0x804553A8: bc1fl       L_804553C0
    if (!c1cs) {
        // 0x804553AC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_804553C0;
    }
    goto skip_1;
    // 0x804553AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x804553B0: jal         0x80450490
    // 0x804553B4: sub.s       $f12, $f14, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f0.fl;
    func_80450490(rdram, ctx);
        goto after_4;
    // 0x804553B4: sub.s       $f12, $f14, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f0.fl;
    after_4:
    // 0x804553B8: lwc1        $f0, 0x6C84($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X6C84);
    // 0x804553BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_804553C0:
    // 0x804553C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804553C4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804553C8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x804553CC: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x804553D0: b           L_80455438
    // 0x804553D4: swc1        $f8, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f8.u32l;
        goto L_80455438;
    // 0x804553D4: swc1        $f8, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f8.u32l;
    // 0x804553D8: lw          $t2, 0xFB4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XFB4);
L_804553DC:
    // 0x804553DC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804553E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x804553E4: beq         $t2, $zero, L_80455410
    if (ctx->r10 == 0) {
        // 0x804553E8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80455410;
    }
    // 0x804553E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804553EC: lbu         $t3, 0x6CEC($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X6CEC);
    // 0x804553F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x804553F4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x804553F8: jal         0x8006E0FC
    // 0x804553FC: sb          $t3, 0x584($v0)
    MEM_B(0X584, ctx->r2) = ctx->r11;
    func_8006E0FC(rdram, ctx);
        goto after_5;
    // 0x804553FC: sb          $t3, 0x584($v0)
    MEM_B(0X584, ctx->r2) = ctx->r11;
    after_5:
    // 0x80455400: jal         0x8044B67C
    // 0x80455404: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8044B67C(rdram, ctx);
        goto after_6;
    // 0x80455404: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80455408: b           L_80455428
    // 0x8045540C: nop

        goto L_80455428;
    // 0x8045540C: nop

L_80455410:
    // 0x80455410: lbu         $t4, 0x6CEC($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X6CEC);
    // 0x80455414: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80455418: jal         0x8006E0FC
    // 0x8045541C: sb          $t4, 0x584($v0)
    MEM_B(0X584, ctx->r2) = ctx->r12;
    func_8006E0FC(rdram, ctx);
        goto after_7;
    // 0x8045541C: sb          $t4, 0x584($v0)
    MEM_B(0X584, ctx->r2) = ctx->r12;
    after_7:
    // 0x80455420: jal         0x8044B67C
    // 0x80455424: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8044B67C(rdram, ctx);
        goto after_8;
    // 0x80455424: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
L_80455428:
    // 0x80455428: jal         0x804448AC
    // 0x8045542C: nop

    func_804448AC(rdram, ctx);
        goto after_9;
    // 0x8045542C: nop

    after_9:
    // 0x80455430: jal         0x804444B0
    // 0x80455434: nop

    func_804444B0(rdram, ctx);
        goto after_10;
    // 0x80455434: nop

    after_10:
L_80455438:
    // 0x80455438: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8045543C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80455440: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80455444: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80455448: jr          $ra
    // 0x8045544C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8045544C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80049018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004901C: bne         $a0, $zero, L_8004903C
    if (ctx->r4 != 0) {
        // 0x80049020: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8004903C;
    }
    // 0x80049020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049024: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80049028: addiu       $a0, $a0, 0x860
    ctx->r4 = ADD32(ctx->r4, 0X860);
    // 0x8004902C: jal         0x80071380
    // 0x80049030: addiu       $a1, $zero, 0xDE9
    ctx->r5 = ADD32(0, 0XDE9);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80049030: addiu       $a1, $zero, 0xDE9
    ctx->r5 = ADD32(0, 0XDE9);
    after_0:
    // 0x80049034: b           L_80049098
    // 0x80049038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80049098;
    // 0x80049038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004903C:
    // 0x8004903C: lbu         $t6, 0x164($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X164);
    // 0x80049040: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80049044: bnel        $t6, $at, L_80049058
    if (ctx->r14 != ctx->r1) {
        // 0x80049048: lw          $v0, 0x16C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X16C);
            goto L_80049058;
    }
    goto skip_0;
    // 0x80049048: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    skip_0:
    // 0x8004904C: b           L_80049098
    // 0x80049050: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80049098;
    // 0x80049050: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80049054: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
L_80049058:
    // 0x80049058: bnel        $v0, $zero, L_8004906C
    if (ctx->r2 != 0) {
        // 0x8004905C: lw          $v1, 0x0($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X0);
            goto L_8004906C;
    }
    goto skip_1;
    // 0x8004905C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x80049060: b           L_80049098
    // 0x80049064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80049098;
    // 0x80049064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80049068: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_8004906C:
    // 0x8004906C: bnel        $v1, $zero, L_80049080
    if (ctx->r3 != 0) {
        // 0x80049070: lw          $t7, 0x138($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X138);
            goto L_80049080;
    }
    goto skip_2;
    // 0x80049070: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    skip_2:
    // 0x80049074: b           L_80049098
    // 0x80049078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80049098;
    // 0x80049078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004907C: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
L_80049080:
    // 0x80049080: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80049084: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80049088: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8004908C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80049090: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80049094: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80049098:
    // 0x80049098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004909C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800490A0: jr          $ra
    // 0x800490A4: nop

    return;
    // 0x800490A4: nop

;}
RECOMP_FUNC void func_8078AD14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078AD14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078AD18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078AD1C: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8078AD20: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8078AD24: lui         $t7, 0x8079
    ctx->r15 = S32(RELOC_HI16(793, 0XC08) << 16);
    // 0x8078AD28: lw          $v0, 0x88($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X88);
    // 0x8078AD2C: addiu       $t7, $t7, -0x51B8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(793, 0XC08));
    // 0x8078AD30: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8078AD34: lw          $t2, 0x1E0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1E0);
    // 0x8078AD38: lui         $t1, 0x8006
    ctx->r9 = S32(0X8006 << 16);
    // 0x8078AD3C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8078AD40: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8078AD44: addiu       $t1, $t1, 0x5284
    ctx->r9 = ADD32(ctx->r9, 0X5284);
    // 0x8078AD48: sll         $t3, $t2, 9
    ctx->r11 = S32(ctx->r10 << 9);
    // 0x8078AD4C: sw          $t9, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r25;
    // 0x8078AD50: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8078AD54: sb          $t0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r8;
    // 0x8078AD58: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8078AD5C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8078AD60: jal         0x8004590C
    // 0x8078AD64: addu        $a1, $t3, $v0
    ctx->r5 = ADD32(ctx->r11, ctx->r2);
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x8078AD64: addu        $a1, $t3, $v0
    ctx->r5 = ADD32(ctx->r11, ctx->r2);
    after_0:
    // 0x8078AD68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078AD6C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8078AD70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8078AD74: sb          $t4, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r12;
    // 0x8078AD78: jr          $ra
    // 0x8078AD7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8078AD7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805325DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805325DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805325E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805325E4: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805325E8: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(342, 0X1830) << 16);
    // 0x805325EC: addiu       $t6, $t6, 0x2620
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(342, 0X1830));
    // 0x805325F0: jal         0x80532554
    // 0x805325F4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    func_80532554(rdram, ctx);
        goto after_0;
    // 0x805325F4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    after_0:
    // 0x805325F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805325FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80532600: jr          $ra
    // 0x80532604: nop

    return;
    // 0x80532604: nop

    // 0x80532608: nop

    // 0x8053260C: nop

;}
RECOMP_FUNC void func_807A1868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A1868: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807A186C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A1870: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807A1874: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807A1878: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807A187C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A1880: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x807A1884: blez        $v0, L_807A1894
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807A1888: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_807A1894;
    }
    // 0x807A1888: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A188C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807A1890: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_807A1894:
    // 0x807A1894: jal         0x807A0FFC
    // 0x807A1898: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_807A0FFC(rdram, ctx);
        goto after_0;
    // 0x807A1898: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x807A189C: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
    // 0x807A18A0: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(841, 0XDAC) << 16);
    // 0x807A18A4: beql        $t7, $zero, L_807A18C4
    if (ctx->r15 == 0) {
        // 0x807A18A8: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_807A18C4;
    }
    goto skip_0;
    // 0x807A18A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x807A18AC: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x807A18B0: lwc1        $f6, 0x1CEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(841, 0XDAC));
    // 0x807A18B4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807A18B8: b           L_807A18CC
    // 0x807A18BC: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
        goto L_807A18CC;
    // 0x807A18BC: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x807A18C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_807A18C4:
    // 0x807A18C4: nop

    // 0x807A18C8: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_807A18CC:
    // 0x807A18CC: jal         0x807A10CC
    // 0x807A18D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A10CC(rdram, ctx);
        goto after_1;
    // 0x807A18D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807A18D4: beq         $v0, $zero, L_807A18EC
    if (ctx->r2 == 0) {
        // 0x807A18D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807A18EC;
    }
    // 0x807A18D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A18DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A18E0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x807A18E4: jal         0x807A1AE4
    // 0x807A18E8: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    func_807A1AE4(rdram, ctx);
        goto after_2;
    // 0x807A18E8: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    after_2:
L_807A18EC:
    // 0x807A18EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807A18F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807A18F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807A18F8: jr          $ra
    // 0x807A18FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x807A18FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8043D914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D914: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x8043D918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8043D91C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8043D920: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x8043D924: bne         $at, $zero, L_8043D99C
    if (ctx->r1 != 0) {
        // 0x8043D928: sw          $t7, 0x154($a0)
        MEM_W(0X154, ctx->r4) = ctx->r15;
            goto L_8043D99C;
    }
    // 0x8043D928: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x8043D92C: lw          $t9, 0x1E0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1E0);
    // 0x8043D930: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x8043D934: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8043D938: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x8043D93C: bne         $at, $zero, L_8043D97C
    if (ctx->r1 != 0) {
        // 0x8043D940: sw          $t0, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r8;
            goto L_8043D97C;
    }
    // 0x8043D940: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
    // 0x8043D944: lbu         $t2, 0x158($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X158);
    // 0x8043D948: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8043D94C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8043D950: beql        $t2, $zero, L_8043D964
    if (ctx->r10 == 0) {
        // 0x8043D954: lw          $t5, 0x138($a0)
        ctx->r13 = MEM_W(ctx->r4, 0X138);
            goto L_8043D964;
    }
    goto skip_0;
    // 0x8043D954: lw          $t5, 0x138($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X138);
    skip_0:
    // 0x8043D958: jr          $ra
    // 0x8043D95C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x8043D95C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8043D960: lw          $t5, 0x138($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X138);
L_8043D964:
    // 0x8043D964: sw          $t3, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r11;
    // 0x8043D968: sb          $t4, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r12;
    // 0x8043D96C: xori        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 ^ 0X1;
    // 0x8043D970: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    // 0x8043D974: sw          $t6, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r14;
    // 0x8043D978: sw          $t6, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r14;
L_8043D97C:
    // 0x8043D97C: lbu         $t8, 0x158($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X158);
    // 0x8043D980: lui         $t0, 0x8044
    ctx->r8 = S32(RELOC_HI16(92, 0X1A40) << 16);
    // 0x8043D984: lh          $t7, 0x144($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X144);
    // 0x8043D988: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8043D98C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8043D990: lw          $t0, -0x1580($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(92, 0X1A40));
    // 0x8043D994: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x8043D998: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
L_8043D99C:
    // 0x8043D99C: jr          $ra
    // 0x8043D9A0: nop

    return;
    // 0x8043D9A0: nop

;}
RECOMP_FUNC void func_806E3800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E3800: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(649, 0X1718) << 16);
    // 0x806E3804: addiu       $v0, $v0, 0x4F18
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(649, 0X1718));
    // 0x806E3808: jr          $ra
    // 0x806E380C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806E380C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8005965C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005965C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059664: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80059668: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005966C: jal         0x80081C64
    // 0x80059670: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x80059670: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x80059674: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80059678: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x8005967C: lw          $v1, 0x3F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3F4);
    // 0x80059680: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80059684: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80059688: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8005968C: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80059690: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80059694: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80059698: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005969C: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x800596A0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800596A4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800596A8: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800596AC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800596B0: lwc1        $f18, 0x4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800596B4: lw          $t1, 0x478($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X478);
    // 0x800596B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800596BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800596C0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800596C4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800596C8: sub.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800596CC: mul.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800596D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800596D4: lwc1        $f18, 0x34($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X34);
    // 0x800596D8: add.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x800596DC: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800596E0: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800596E4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800596E8: nop

    // 0x800596EC: bc1f        L_800596F8
    if (!c1cs) {
        // 0x800596F0: nop
    
            goto L_800596F8;
    }
    // 0x800596F0: nop

    // 0x800596F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800596F8:
    // 0x800596F8: jr          $ra
    // 0x800596FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800596FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000C130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C130: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8000C134: bne         $t6, $zero, L_8000C168
    if (ctx->r14 != 0) {
        // 0x8000C138: nop
    
            goto L_8000C168;
    }
    // 0x8000C138: nop

    // 0x8000C13C: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x8000C140: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8000C144: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8000C148: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8000C14C: sw          $a1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r5;
    // 0x8000C150: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8000C154: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x8000C158: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x8000C15C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8000C160: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x8000C164: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
L_8000C168:
    // 0x8000C168: jr          $ra
    // 0x8000C16C: nop

    return;
    // 0x8000C16C: nop

;}
RECOMP_FUNC void func_80446670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446670: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446674: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80446678: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044667C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80446680: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x80446684: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446688: jr          $ra
    // 0x8044668C: sw          $t7, 0x6CB4($at)
    MEM_W(0X6CB4, ctx->r1) = ctx->r15;
    return;
    // 0x8044668C: sw          $t7, 0x6CB4($at)
    MEM_W(0X6CB4, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_8067B088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067B088: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8067B08C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8067B090: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2AC8) << 16);
    // 0x8067B094: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8067B098: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8067B09C: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8067B0A0: lwc1        $f4, -0x3888($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2AC8));
    // 0x8067B0A4: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8067B0A8: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(541, 0X2AF8) << 16);
    // 0x8067B0AC: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8067B0B0: sw          $a2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r6;
    // 0x8067B0B4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8067B0B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8067B0BC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8067B0C0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8067B0C4: bc1fl       L_8067B0EC
    if (!c1cs) {
        // 0x8067B0C8: lui         $at, 0xC334
        ctx->r1 = S32(0XC334 << 16);
            goto L_8067B0EC;
    }
    goto skip_0;
    // 0x8067B0C8: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    skip_0:
    // 0x8067B0CC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8067B0D0: nop

    // 0x8067B0D4: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
L_8067B0D8:
    // 0x8067B0D8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8067B0DC: nop

    // 0x8067B0E0: bc1tl       L_8067B0D8
    if (c1cs) {
        // 0x8067B0E4: sub.s       $f2, $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
            goto L_8067B0D8;
    }
    goto skip_1;
    // 0x8067B0E4: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    skip_1:
    // 0x8067B0E8: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
L_8067B0EC:
    // 0x8067B0EC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8067B0F0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8067B0F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8067B0F8: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x8067B0FC: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2AE8) << 16);
    // 0x8067B100: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8067B104: bc1fl       L_8067B124
    if (!c1cs) {
        // 0x8067B108: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_8067B124;
    }
    goto skip_2;
    // 0x8067B108: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_2:
    // 0x8067B10C: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
L_8067B110:
    // 0x8067B110: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x8067B114: nop

    // 0x8067B118: bc1tl       L_8067B110
    if (c1cs) {
        // 0x8067B11C: add.s       $f2, $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
            goto L_8067B110;
    }
    goto skip_3;
    // 0x8067B11C: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
    skip_3:
    // 0x8067B120: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8067B124:
    // 0x8067B124: nop

    // 0x8067B128: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8067B12C: nop

    // 0x8067B130: bc1fl       L_8067B168
    if (!c1cs) {
        // 0x8067B134: sw          $zero, 0x128($a0)
        MEM_W(0X128, ctx->r4) = 0;
            goto L_8067B168;
    }
    goto skip_4;
    // 0x8067B134: sw          $zero, 0x128($a0)
    MEM_W(0X128, ctx->r4) = 0;
    skip_4:
    // 0x8067B138: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2AD8) << 16);
    // 0x8067B13C: sw          $t6, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->r14;
    // 0x8067B140: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8067B144: lwc1        $f12, -0x3878($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2AD8));
    // 0x8067B148: sub.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8067B14C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8067B150: nop

    // 0x8067B154: bc1fl       L_8067B188
    if (!c1cs) {
        // 0x8067B158: swc1        $f0, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
            goto L_8067B188;
    }
    goto skip_5;
    // 0x8067B158: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    skip_5:
    // 0x8067B15C: b           L_8067B184
    // 0x8067B160: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_8067B184;
    // 0x8067B160: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8067B164: sw          $zero, 0x128($a0)
    MEM_W(0X128, ctx->r4) = 0;
L_8067B168:
    // 0x8067B168: lwc1        $f12, -0x3868($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2AE8));
    // 0x8067B16C: sub.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8067B170: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8067B174: nop

    // 0x8067B178: bc1fl       L_8067B188
    if (!c1cs) {
        // 0x8067B17C: swc1        $f0, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
            goto L_8067B188;
    }
    goto skip_6;
    // 0x8067B17C: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    skip_6:
    // 0x8067B180: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8067B184:
    // 0x8067B184: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
L_8067B188:
    // 0x8067B188: lw          $t8, -0x3858($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(541, 0X2AF8));
    // 0x8067B18C: jr          $ra
    // 0x8067B190: sw          $t8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r24;
    return;
    // 0x8067B190: sw          $t8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r24;
;}
RECOMP_FUNC void func_8006E84C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E84C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006E850: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006E854: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006E858: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x8006E85C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006E860: jal         0x80049D74
    // 0x8006E864: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x8006E864: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006E868: lwc1        $f4, 0xA8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8006E86C: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8006E870: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8006E874: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8006E878: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8006E87C: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x8006E880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006E884: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8006E888: bc1f        L_8006E8C0
    if (!c1cs) {
        // 0x8006E88C: nop
    
            goto L_8006E8C0;
    }
    // 0x8006E88C: nop

    // 0x8006E890: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8006E894: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x8006E898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006E89C: jal         0x8004D150
    // 0x8006E8A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8004D150(rdram, ctx);
        goto after_1;
    // 0x8006E8A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8006E8A4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8006E8A8: addiu       $a2, $a2, -0x2A94
    ctx->r6 = ADD32(ctx->r6, -0X2A94);
    // 0x8006E8AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006E8B0: jal         0x8004D618
    // 0x8006E8B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8004D618(rdram, ctx);
        goto after_2;
    // 0x8006E8B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x8006E8B8: b           L_8006E8DC
    // 0x8006E8BC: nop

        goto L_8006E8DC;
    // 0x8006E8BC: nop

L_8006E8C0:
    // 0x8006E8C0: jal         0x8004D150
    // 0x8006E8C4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x8006E8C4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_3:
    // 0x8006E8C8: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8006E8CC: addiu       $a2, $a2, -0x2B40
    ctx->r6 = ADD32(ctx->r6, -0X2B40);
    // 0x8006E8D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006E8D4: jal         0x8004D618
    // 0x8006E8D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x8006E8D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
L_8006E8DC:
    // 0x8006E8DC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8006E8E0: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x8006E8E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006E8E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006E8EC: jal         0x8004D150
    // 0x8006E8F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_5;
    // 0x8006E8F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_5:
    // 0x8006E8F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006E8F8: lwc1        $f8, 0x1180($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1180);
    // 0x8006E8FC: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8006E900: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8006E904: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8006E908: nop

    // 0x8006E90C: bc1fl       L_8006E95C
    if (!c1cs) {
        // 0x8006E910: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006E95C;
    }
    goto skip_0;
    // 0x8006E910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8006E914: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006E918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006E91C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006E920: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8006E924: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8006E928: lbu         $t8, 0x14($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X14);
    // 0x8006E92C: beql        $t8, $zero, L_8006E948
    if (ctx->r24 == 0) {
        // 0x8006E930: lw          $t9, 0x4($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X4);
            goto L_8006E948;
    }
    goto skip_1;
    // 0x8006E930: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x8006E934: jal         0x8004D618
    // 0x8006E938: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    func_8004D618(rdram, ctx);
        goto after_6;
    // 0x8006E938: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    after_6:
    // 0x8006E93C: b           L_8006E95C
    // 0x8006E940: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006E95C;
    // 0x8006E940: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006E944: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
L_8006E948:
    // 0x8006E948: beql        $t9, $zero, L_8006E95C
    if (ctx->r25 == 0) {
        // 0x8006E94C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006E95C;
    }
    goto skip_2;
    // 0x8006E94C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8006E950: b           L_8006E95C
    // 0x8006E954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006E95C;
    // 0x8006E954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006E958: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006E95C:
    // 0x8006E95C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E960: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006E964: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006E968: jr          $ra
    // 0x8006E96C: nop

    return;
    // 0x8006E96C: nop

;}
RECOMP_FUNC void func_806DB860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DB860: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DB864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DB868: jal         0x80059278
    // 0x806DB86C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80059278(rdram, ctx);
        goto after_0;
    // 0x806DB86C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806DB870: bnel        $v0, $zero, L_806DB88C
    if (ctx->r2 != 0) {
        // 0x806DB874: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806DB88C;
    }
    goto skip_0;
    // 0x806DB874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x806DB878: jal         0x800447C8
    // 0x806DB87C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x806DB87C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806DB880: b           L_806DB88C
    // 0x806DB884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806DB88C;
    // 0x806DB884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806DB888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806DB88C:
    // 0x806DB88C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DB890: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DB894: jr          $ra
    // 0x806DB898: nop

    return;
    // 0x806DB898: nop

;}
RECOMP_FUNC void func_804C0188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0188: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804C018C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x804C0190: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804C0194: lw          $t6, 0x16C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X16C);
    // 0x804C0198: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x804C019C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804C01A0: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x804C01A4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x804C01A8: bgez        $t7, L_804C01BC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x804C01AC: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_804C01BC;
    }
    // 0x804C01AC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804C01B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C01B4: nop

    // 0x804C01B8: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_804C01BC:
    // 0x804C01BC: lwc1        $f8, 0x78($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X78);
    // 0x804C01C0: lwc1        $f10, 0x6C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x804C01C4: lwc1        $f18, 0x7C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x804C01C8: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(194, 0X330) << 16);
    // 0x804C01CC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804C01D0: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    // 0x804C01D4: lwc1        $f4, 0x70($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X70);
    // 0x804C01D8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x804C01DC: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x804C01E0: lwc1        $f8, 0x440($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(194, 0X330));
    // 0x804C01E4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x804C01E8: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x804C01EC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804C01F0: nop

    // 0x804C01F4: bc1fl       L_804C0204
    if (!c1cs) {
        // 0x804C01F8: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_804C0204;
    }
    goto skip_0;
    // 0x804C01F8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_0:
    // 0x804C01FC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x804C0200: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_804C0204:
    // 0x804C0204: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x804C0208: nop

    // 0x804C020C: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x804C0210: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x804C0214: nop

    // 0x804C0218: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x804C021C: beql        $t9, $zero, L_804C026C
    if (ctx->r25 == 0) {
        // 0x804C0220: mfc1        $t9, $f10
        ctx->r25 = (int32_t)ctx->f10.u32l;
            goto L_804C026C;
    }
    goto skip_1;
    // 0x804C0220: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x804C0224: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804C0228: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804C022C: sub.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x804C0230: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x804C0234: nop

    // 0x804C0238: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x804C023C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x804C0240: nop

    // 0x804C0244: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x804C0248: bne         $t9, $zero, L_804C0260
    if (ctx->r25 != 0) {
        // 0x804C024C: nop
    
            goto L_804C0260;
    }
    // 0x804C024C: nop

    // 0x804C0250: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x804C0254: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804C0258: b           L_804C0278
    // 0x804C025C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_804C0278;
    // 0x804C025C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_804C0260:
    // 0x804C0260: b           L_804C0278
    // 0x804C0264: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_804C0278;
    // 0x804C0264: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x804C0268: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
L_804C026C:
    // 0x804C026C: nop

    // 0x804C0270: bltz        $t9, L_804C0260
    if (SIGNED(ctx->r25) < 0) {
        // 0x804C0274: nop
    
            goto L_804C0260;
    }
    // 0x804C0274: nop

L_804C0278:
    // 0x804C0278: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x804C027C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x804C0280: jr          $ra
    // 0x804C0284: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    return;
    // 0x804C0284: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
;}
RECOMP_FUNC void func_8064C4FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C4FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064C500: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064C504: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064C508: lh          $t6, 0xC2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XC2);
    // 0x8064C50C: lui         $at, 0x4336
    ctx->r1 = S32(0X4336 << 16);
    // 0x8064C510: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8064C514: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8064C518: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8064C51C: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8064C520: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8064C524: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064C528: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064C52C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8064C530: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8064C534: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x8064C538: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8064C53C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8064C540: swc1        $f10, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f10.u32l;
    // 0x8064C544: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8064C548: jal         0x8064C4A0
    // 0x8064C54C: sh          $t8, 0xC2($a0)
    MEM_H(0XC2, ctx->r4) = ctx->r24;
    func_8064C4A0(rdram, ctx);
        goto after_0;
    // 0x8064C54C: sh          $t8, 0xC2($a0)
    MEM_H(0XC2, ctx->r4) = ctx->r24;
    after_0:
    // 0x8064C550: bne         $v0, $zero, L_8064C568
    if (ctx->r2 != 0) {
        // 0x8064C554: nop
    
            goto L_8064C568;
    }
    // 0x8064C554: nop

    // 0x8064C558: jal         0x800445A4
    // 0x8064C55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8064C55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8064C560: b           L_8064C5C8
    // 0x8064C564: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8064C5C8;
    // 0x8064C564: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064C568:
    // 0x8064C568: jal         0x8064A468
    // 0x8064C56C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A468(rdram, ctx);
        goto after_2;
    // 0x8064C56C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8064C570: lui         $t9, 0x8065
    ctx->r25 = S32(RELOC_HI16(495, 0X232C) << 16);
    // 0x8064C574: addiu       $t9, $t9, -0x3C04
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(495, 0X232C));
    // 0x8064C578: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x8064C57C: jal         0x8064C4E4
    // 0x8064C580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064C4E4(rdram, ctx);
        goto after_3;
    // 0x8064C580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8064C584: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x8064C588: lui         $t0, 0x8065
    ctx->r8 = S32(RELOC_HI16(495, 0X33E4) << 16);
    // 0x8064C58C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8064C590: addiu       $t0, $t0, -0x2B4C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(495, 0X33E4));
    // 0x8064C594: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8064C598: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8064C59C: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8064C5A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064C5A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C5A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8064C5AC: jal         0x8064C5D8
    // 0x8064C5B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8064C5D8(rdram, ctx);
        goto after_4;
    // 0x8064C5B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8064C5B4: jal         0x8064A158
    // 0x8064C5B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A158(rdram, ctx);
        goto after_5;
    // 0x8064C5B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8064C5BC: jal         0x8064A40C
    // 0x8064C5C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A40C(rdram, ctx);
        goto after_6;
    // 0x8064C5C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8064C5C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064C5C8:
    // 0x8064C5C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064C5CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064C5D0: jr          $ra
    // 0x8064C5D4: nop

    return;
    // 0x8064C5D4: nop

;}
RECOMP_FUNC void func_804608AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804608AC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804608B0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x804608B4: jr          $ra
    // 0x804608B8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x804608B8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_800415D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800415D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800415D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800415D8: jal         0x800320C4
    // 0x800415DC: nop

    func_800320C4(rdram, ctx);
        goto after_0;
    // 0x800415DC: nop

    after_0:
    // 0x800415E0: beq         $v0, $zero, L_800415F0
    if (ctx->r2 == 0) {
        // 0x800415E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800415F0;
    }
    // 0x800415E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800415E8: b           L_800415F4
    // 0x800415EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800415F4;
    // 0x800415EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800415F0:
    // 0x800415F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800415F4:
    // 0x800415F4: jr          $ra
    // 0x800415F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800415F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80052C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052C98: jr          $ra
    // 0x80052C9C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80052C9C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void strlen_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ADAC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8008ADB0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8008ADB4: beq         $t6, $zero, L_8008ADCC
    if (ctx->r14 == 0) {
        // 0x8008ADB8: nop
    
            goto L_8008ADCC;
    }
    // 0x8008ADB8: nop

    // 0x8008ADBC: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
L_8008ADC0:
    // 0x8008ADC0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008ADC4: bnel        $t7, $zero, L_8008ADC0
    if (ctx->r15 != 0) {
        // 0x8008ADC8: lbu         $t7, 0x1($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X1);
            goto L_8008ADC0;
    }
    goto skip_0;
    // 0x8008ADC8: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    skip_0:
L_8008ADCC:
    // 0x8008ADCC: jr          $ra
    // 0x8008ADD0: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    return;
    // 0x8008ADD0: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
;}
RECOMP_FUNC void func_8006D420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D428: jal         0x8006D360
    // 0x8006D42C: nop

    func_8006D360(rdram, ctx);
        goto after_0;
    // 0x8006D42C: nop

    after_0:
    // 0x8006D430: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006D434: bne         $v0, $at, L_8006D444
    if (ctx->r2 != ctx->r1) {
        // 0x8006D438: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8006D444;
    }
    // 0x8006D438: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8006D43C: b           L_8006D45C
    // 0x8006D440: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D45C;
    // 0x8006D440: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D444:
    // 0x8006D444: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8006D448: bnel        $v0, $at, L_8006D45C
    if (ctx->r2 != ctx->r1) {
        // 0x8006D44C: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8006D45C;
    }
    goto skip_0;
    // 0x8006D44C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8006D450: b           L_8006D45C
    // 0x8006D454: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_8006D45C;
    // 0x8006D454: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8006D458: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8006D45C:
    // 0x8006D45C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D464: jr          $ra
    // 0x8006D468: nop

    return;
    // 0x8006D468: nop

;}
RECOMP_FUNC void func_80519818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519818: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051981C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80519820: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80519824: jal         0x80517D80
    // 0x80519828: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80517D80(rdram, ctx);
        goto after_0;
    // 0x80519828: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8051982C: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80519830: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80519834: nop

    // 0x80519838: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x8051983C: nop

    // 0x80519840: bc1fl       L_80519878
    if (!c1cs) {
        // 0x80519844: lwc1        $f14, 0xEC($s0)
        ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
            goto L_80519878;
    }
    goto skip_0;
    // 0x80519844: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    skip_0:
    // 0x80519848: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x8051984C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80519850: andi        $t8, $t7, 0xF00
    ctx->r24 = ctx->r15 & 0XF00;
    // 0x80519854: beql        $t8, $zero, L_80519878
    if (ctx->r24 == 0) {
        // 0x80519858: lwc1        $f14, 0xEC($s0)
        ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
            goto L_80519878;
    }
    goto skip_1;
    // 0x80519858: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    skip_1:
    // 0x8051985C: jal         0x8004700C
    // 0x80519860: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x80519860: nop

    after_1:
    // 0x80519864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80519868: jal         0x805193B4
    // 0x8051986C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_805193B4(rdram, ctx);
        goto after_2;
    // 0x8051986C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80519870: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80519874: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
L_80519878:
    // 0x80519878: jal         0x80065ABC
    // 0x8051987C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_3;
    // 0x8051987C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_3:
    // 0x80519880: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80519884: jal         0x80519124
    // 0x80519888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80519124(rdram, ctx);
        goto after_4;
    // 0x80519888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8051988C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80519890: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80519894: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80519898: jr          $ra
    // 0x8051989C: nop

    return;
    // 0x8051989C: nop

;}
RECOMP_FUNC void func_80677244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80677244: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80677248: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067724C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80677250: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80677254: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x80677258: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8067725C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80677260: beq         $v0, $at, L_8067727C
    if (ctx->r2 == ctx->r1) {
        // 0x80677264: lui         $t7, 0x8067
        ctx->r15 = S32(RELOC_HI16(535, 0X15A8) << 16);
            goto L_8067727C;
    }
    // 0x80677264: lui         $t7, 0x8067
    ctx->r15 = S32(RELOC_HI16(535, 0X15A8) << 16);
    // 0x80677268: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8067726C: beql        $v0, $at, L_806772B0
    if (ctx->r2 == ctx->r1) {
        // 0x80677270: lbu         $t9, 0x18($a1)
        ctx->r25 = MEM_BU(ctx->r5, 0X18);
            goto L_806772B0;
    }
    goto skip_0;
    // 0x80677270: lbu         $t9, 0x18($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X18);
    skip_0:
    // 0x80677274: b           L_806772EC
    // 0x80677278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806772EC;
    // 0x80677278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8067727C:
    // 0x8067727C: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80677280: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80677284: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x80677288: addiu       $t7, $t7, 0x6C68
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(535, 0X15A8));
    // 0x8067728C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80677290: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80677294: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80677298: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8067729C: jal         0x80676E20
    // 0x806772A0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_80676E20(rdram, ctx);
        goto after_0;
    // 0x806772A0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x806772A4: b           L_806772EC
    // 0x806772A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806772EC;
    // 0x806772A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806772AC: lbu         $t9, 0x18($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X18);
L_806772B0:
    // 0x806772B0: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x806772B4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x806772B8: bne         $t9, $at, L_806772E8
    if (ctx->r25 != ctx->r1) {
        // 0x806772BC: lui         $t1, 0x8067
        ctx->r9 = S32(RELOC_HI16(535, 0X160C) << 16);
            goto L_806772E8;
    }
    // 0x806772BC: lui         $t1, 0x8067
    ctx->r9 = S32(RELOC_HI16(535, 0X160C) << 16);
    // 0x806772C0: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x806772C4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x806772C8: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x806772CC: addiu       $t1, $t1, 0x6CCC
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(535, 0X160C));
    // 0x806772D0: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x806772D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x806772D8: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x806772DC: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x806772E0: jal         0x80676E20
    // 0x806772E4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_80676E20(rdram, ctx);
        goto after_1;
    // 0x806772E4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_1:
L_806772E8:
    // 0x806772E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806772EC:
    // 0x806772EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806772F0: jr          $ra
    // 0x806772F4: nop

    return;
    // 0x806772F4: nop

;}
RECOMP_FUNC void func_80030068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030068: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003006C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80030070: lbu         $v1, 0x17C($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X17C);
    // 0x80030074: beq         $v1, $at, L_80030084
    if (ctx->r3 == ctx->r1) {
        // 0x80030078: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80030084;
    }
    // 0x80030078: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003007C: bne         $v1, $at, L_80030098
    if (ctx->r3 != ctx->r1) {
        // 0x80030080: nop
    
            goto L_80030098;
    }
    // 0x80030080: nop

L_80030084:
    // 0x80030084: lbu         $t6, 0x158($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X158);
    // 0x80030088: bne         $t6, $zero, L_800300DC
    if (ctx->r14 != 0) {
        // 0x8003008C: nop
    
            goto L_800300DC;
    }
    // 0x8003008C: nop

    // 0x80030090: jr          $ra
    // 0x80030094: sb          $zero, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = 0;
    return;
    // 0x80030094: sb          $zero, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = 0;
L_80030098:
    // 0x80030098: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8003009C: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x800300A0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x800300A4: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x800300A8: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800300AC: andi        $t9, $t8, 0x2000
    ctx->r25 = ctx->r24 & 0X2000;
    // 0x800300B0: beq         $t9, $at, L_800300DC
    if (ctx->r25 == ctx->r1) {
        // 0x800300B4: nop
    
            goto L_800300DC;
    }
    // 0x800300B4: nop

    // 0x800300B8: lh          $v1, 0xAE0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0XAE0);
    // 0x800300BC: beq         $v1, $zero, L_800300DC
    if (ctx->r3 == 0) {
        // 0x800300C0: nop
    
            goto L_800300DC;
    }
    // 0x800300C0: nop

    // 0x800300C4: bgez        $v1, L_800300D8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800300C8: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_800300D8;
    }
    // 0x800300C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800300CC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800300D0: jr          $ra
    // 0x800300D4: sb          $t0, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r8;
    return;
    // 0x800300D4: sb          $t0, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r8;
L_800300D8:
    // 0x800300D8: sb          $t1, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r9;
L_800300DC:
    // 0x800300DC: jr          $ra
    // 0x800300E0: nop

    return;
    // 0x800300E0: nop

;}
RECOMP_FUNC void func_80032A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032A8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032A90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032A94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80032A98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80032A9C: lw          $a2, 0x164($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X164);
    // 0x80032AA0: lw          $v0, 0x174($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X174);
    // 0x80032AA4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80032AA8: lhu         $v1, 0x1C($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X1C);
    // 0x80032AAC: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x80032AB0: beq         $t8, $zero, L_80032AC8
    if (ctx->r24 == 0) {
        // 0x80032AB4: andi        $t9, $v1, 0x2
        ctx->r25 = ctx->r3 & 0X2;
            goto L_80032AC8;
    }
    // 0x80032AB4: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
    // 0x80032AB8: jal         0x800329B8
    // 0x80032ABC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800329B8(rdram, ctx);
        goto after_0;
    // 0x80032ABC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80032AC0: b           L_80032AE8
    // 0x80032AC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80032AE8;
    // 0x80032AC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80032AC8:
    // 0x80032AC8: beql        $t9, $zero, L_80032AE8
    if (ctx->r25 == 0) {
        // 0x80032ACC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80032AE8;
    }
    goto skip_0;
    // 0x80032ACC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80032AD0: lw          $t9, 0x1C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X1C);
    // 0x80032AD4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80032AD8: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    // 0x80032ADC: jalr        $t9
    // 0x80032AE0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80032AE0: nop

    after_1:
    // 0x80032AE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80032AE8:
    // 0x80032AE8: jal         0x8002B470
    // 0x80032AEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8002B470(rdram, ctx);
        goto after_2;
    // 0x80032AEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80032AF0: jal         0x80032984
    // 0x80032AF4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80032984(rdram, ctx);
        goto after_3;
    // 0x80032AF4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80032AF8: jal         0x8001D770
    // 0x80032AFC: nop

    func_8001D770(rdram, ctx);
        goto after_4;
    // 0x80032AFC: nop

    after_4:
    // 0x80032B00: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80032B04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80032B08: lw          $a1, 0x34($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X34);
    // 0x80032B0C: jal         0x80067BF8
    // 0x80032B10: lw          $a2, 0x38($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_5;
    // 0x80032B10: lw          $a2, 0x38($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X38);
    after_5:
    // 0x80032B14: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80032B18: jal         0x80067818
    // 0x80032B1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x80032B1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80032B20: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x80032B24: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80032B28: sb          $t1, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r9;
    // 0x80032B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032B30: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80032B34: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80032B38: sb          $t2, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r10;
    // 0x80032B3C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80032B40: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x80032B44: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
    // 0x80032B48: jr          $ra
    // 0x80032B4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80032B4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80049830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049830: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x80049834: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x80049838: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8004983C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80049840: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80049844: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80049848: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8004984C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80049850: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x80049854: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80049858: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x8004985C: jr          $ra
    // 0x80049860: lbu         $v0, 0x5C0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5C0);
    return;
    // 0x80049860: lbu         $v0, 0x5C0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5C0);
;}
RECOMP_FUNC void func_80791750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80791750: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80791754: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80791758: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079175C: jal         0x8004700C
    // 0x80791760: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80791760: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80791764: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80791768: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x8079176C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791770: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80791774: jal         0x80791690
    // 0x80791778: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    func_80791690(rdram, ctx);
        goto after_1;
    // 0x80791778: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    after_1:
    // 0x8079177C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80791780: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80791784: jal         0x807903C4
    // 0x80791788: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807903C4(rdram, ctx);
        goto after_2;
    // 0x80791788: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8079178C: lw          $t8, 0x1E4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E4);
    // 0x80791790: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80791794: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80791798: bne         $t8, $zero, L_807917B8
    if (ctx->r24 != 0) {
        // 0x8079179C: addiu       $t0, $zero, 0x1E
        ctx->r8 = ADD32(0, 0X1E);
            goto L_807917B8;
    }
    // 0x8079179C: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x807917A0: sb          $t9, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r25;
    // 0x807917A4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807917A8: sb          $t0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r8;
    // 0x807917AC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807917B0: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x807917B4: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
L_807917B8:
    // 0x807917B8: jal         0x80790714
    // 0x807917BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790714(rdram, ctx);
        goto after_3;
    // 0x807917BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807917C0: beq         $v0, $zero, L_80791800
    if (ctx->r2 == 0) {
        // 0x807917C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80791800;
    }
    // 0x807917C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807917C8: lw          $t2, 0x1E4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1E4);
    // 0x807917CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x807917D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807917D4: bne         $t2, $at, L_807917F0
    if (ctx->r10 != ctx->r1) {
        // 0x807917D8: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_807917F0;
    }
    // 0x807917D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807917DC: sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
    // 0x807917E0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x807917E4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x807917E8: sb          $zero, 0x10($t3)
    MEM_B(0X10, ctx->r11) = 0;
    // 0x807917EC: sb          $v0, 0x7EA5($at)
    MEM_B(0X7EA5, ctx->r1) = ctx->r2;
L_807917F0:
    // 0x807917F0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x807917F4: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x807917F8: jal         0x8079393C
    // 0x807917FC: lw          $a3, 0x68($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X68);
    func_8079393C(rdram, ctx);
        goto after_4;
    // 0x807917FC: lw          $a3, 0x68($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X68);
    after_4:
L_80791800:
    // 0x80791800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791804: jal         0x80790878
    // 0x80791808: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    func_80790878(rdram, ctx);
        goto after_5;
    // 0x80791808: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    after_5:
    // 0x8079180C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80791810: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80791814: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80791818: jr          $ra
    // 0x8079181C: nop

    return;
    // 0x8079181C: nop

;}
RECOMP_FUNC void func_80038BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038BD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80038BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038BD8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80038BDC: lwc1        $f4, 0x13C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X13C);
    // 0x80038BE0: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80038BE4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80038BE8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80038BEC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80038BF0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80038BF4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80038BF8: addiu       $a0, $a2, 0x84
    ctx->r4 = ADD32(ctx->r6, 0X84);
    // 0x80038BFC: bc1tl       L_80038C24
    if (c1cs) {
        // 0x80038C00: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80038C24;
    }
    goto skip_0;
    // 0x80038C00: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    skip_0:
    // 0x80038C04: lwc1        $f6, 0x140($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X140);
    // 0x80038C08: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80038C0C: nop

    // 0x80038C10: bc1tl       L_80038C24
    if (c1cs) {
        // 0x80038C14: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80038C24;
    }
    goto skip_1;
    // 0x80038C14: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    skip_1:
    // 0x80038C18: b           L_80038CA8
    // 0x80038C1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80038CA8;
    // 0x80038C1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80038C20: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
L_80038C24:
    // 0x80038C24: jal         0x80047AB8
    // 0x80038C28: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x80038C28: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80038C2C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80038C30: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80038C34: jal         0x8004742C
    // 0x80038C38: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_8004742C(rdram, ctx);
        goto after_1;
    // 0x80038C38: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80038C3C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80038C40: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80038C44: slti        $at, $v0, 0x26
    ctx->r1 = SIGNED(ctx->r2) < 0X26 ? 1 : 0;
    // 0x80038C48: bne         $at, $zero, L_80038C74
    if (ctx->r1 != 0) {
        // 0x80038C4C: slti        $at, $v0, 0x11B
        ctx->r1 = SIGNED(ctx->r2) < 0X11B ? 1 : 0;
            goto L_80038C74;
    }
    // 0x80038C4C: slti        $at, $v0, 0x11B
    ctx->r1 = SIGNED(ctx->r2) < 0X11B ? 1 : 0;
    // 0x80038C50: beq         $at, $zero, L_80038C74
    if (ctx->r1 == 0) {
        // 0x80038C54: lw          $v0, 0x20($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X20);
            goto L_80038C74;
    }
    // 0x80038C54: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80038C58: slti        $at, $v0, 0x1C
    ctx->r1 = SIGNED(ctx->r2) < 0X1C ? 1 : 0;
    // 0x80038C5C: bne         $at, $zero, L_80038C74
    if (ctx->r1 != 0) {
        // 0x80038C60: slti        $at, $v0, 0xD5
        ctx->r1 = SIGNED(ctx->r2) < 0XD5 ? 1 : 0;
            goto L_80038C74;
    }
    // 0x80038C60: slti        $at, $v0, 0xD5
    ctx->r1 = SIGNED(ctx->r2) < 0XD5 ? 1 : 0;
    // 0x80038C64: beql        $at, $zero, L_80038C78
    if (ctx->r1 == 0) {
        // 0x80038C68: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_80038C78;
    }
    goto skip_2;
    // 0x80038C68: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    skip_2:
    // 0x80038C6C: b           L_80038CA8
    // 0x80038C70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80038CA8;
    // 0x80038C70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80038C74:
    // 0x80038C74: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
L_80038C78:
    // 0x80038C78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80038C7C: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80038C80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80038C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80038C88: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80038C8C: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x80038C90: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80038C94: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80038C98: nop

    // 0x80038C9C: bc1f        L_80038CA8
    if (!c1cs) {
        // 0x80038CA0: nop
    
            goto L_80038CA8;
    }
    // 0x80038CA0: nop

    // 0x80038CA4: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_80038CA8:
    // 0x80038CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038CAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80038CB0: jr          $ra
    // 0x80038CB4: nop

    return;
    // 0x80038CB4: nop

;}
RECOMP_FUNC void func_805CF0F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CF0F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805CF0F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CF0F8: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x805CF0FC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805CF100: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805CF104: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x805CF108: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805CF10C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805CF110: jal         0x80048F84
    // 0x805CF114: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x805CF114: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x805CF118: jal         0x805CF068
    // 0x805CF11C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_805CF068(rdram, ctx);
        goto after_1;
    // 0x805CF11C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x805CF120: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x805CF124: lw          $t8, 0x1E0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X1E0);
    // 0x805CF128: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x805CF12C: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x805CF130: bne         $at, $zero, L_805CF170
    if (ctx->r1 != 0) {
        // 0x805CF134: sw          $t9, 0x1E0($a2)
        MEM_W(0X1E0, ctx->r6) = ctx->r25;
            goto L_805CF170;
    }
    // 0x805CF134: sw          $t9, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r25;
    // 0x805CF138: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x805CF13C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x805CF140: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x805CF144: lw          $t1, 0x30($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X30);
    // 0x805CF148: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805CF14C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x805CF150: sw          $t2, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r10;
    // 0x805CF154: lw          $t3, 0xABC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XABC);
    // 0x805CF158: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x805CF15C: jal         0x80044658
    // 0x805CF160: sw          $t4, 0xABC($v0)
    MEM_W(0XABC, ctx->r2) = ctx->r12;
    func_80044658(rdram, ctx);
        goto after_2;
    // 0x805CF160: sw          $t4, 0xABC($v0)
    MEM_W(0XABC, ctx->r2) = ctx->r12;
    after_2:
    // 0x805CF164: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x805CF168: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805CF16C: sb          $t5, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r13;
L_805CF170:
    // 0x805CF170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805CF174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805CF178: jr          $ra
    // 0x805CF17C: nop

    return;
    // 0x805CF17C: nop

;}
RECOMP_FUNC void func_8044B28C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B28C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8044B290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B294: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044B298: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B29C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044B2A0: lw          $a1, 0x6A70($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X6A70);
    // 0x8044B2A4: beq         $a1, $zero, L_8044B2BC
    if (ctx->r5 == 0) {
        // 0x8044B2A8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044B2BC;
    }
    // 0x8044B2A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044B2AC: jal         0x80050A2C
    // 0x8044B2B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80050A2C(rdram, ctx);
        goto after_0;
    // 0x8044B2B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044B2B4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B2B8: sw          $zero, 0x6A70($v1)
    MEM_W(0X6A70, ctx->r3) = 0;
L_8044B2BC:
    // 0x8044B2BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044B2C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8044B2C4: jr          $ra
    // 0x8044B2C8: nop

    return;
    // 0x8044B2C8: nop

;}
