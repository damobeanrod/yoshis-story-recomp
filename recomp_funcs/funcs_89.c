#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_805D8A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D8A30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D8A34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D8A38: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805D8A3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805D8A40: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805D8A44: jal         0x805D87D0
    // 0x805D8A48: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_805D87D0(rdram, ctx);
        goto after_0;
    // 0x805D8A48: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x805D8A4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805D8A50: jal         0x805D84A4
    // 0x805D8A54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_805D84A4(rdram, ctx);
        goto after_1;
    // 0x805D8A54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x805D8A58: jal         0x805D8778
    // 0x805D8A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805D8778(rdram, ctx);
        goto after_2;
    // 0x805D8A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805D8A60: beql        $v0, $zero, L_805D8AA4
    if (ctx->r2 == 0) {
        // 0x805D8A64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D8AA4;
    }
    goto skip_0;
    // 0x805D8A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805D8A68: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x805D8A6C: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x805D8A70: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x805D8A74: beq         $v0, $zero, L_805D8A88
    if (ctx->r2 == 0) {
        // 0x805D8A78: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_805D8A88;
    }
    // 0x805D8A78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805D8A7C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x805D8A80: b           L_805D8AA0
    // 0x805D8A84: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
        goto L_805D8AA0;
    // 0x805D8A84: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
L_805D8A88:
    // 0x805D8A88: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x805D8A8C: sw          $t7, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->r15;
    // 0x805D8A90: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    // 0x805D8A94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D8A98: jal         0x805D8AB4
    // 0x805D8A9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805D8AB4(rdram, ctx);
        goto after_3;
    // 0x805D8A9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_805D8AA0:
    // 0x805D8AA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D8AA4:
    // 0x805D8AA4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805D8AA8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805D8AAC: jr          $ra
    // 0x805D8AB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805D8AB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001E324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E324: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001E328: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001E32C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001E330: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001E334: lhu         $t6, 0x12BE($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X12BE);
    // 0x8001E338: lhu         $a3, 0x12BC($a1)
    ctx->r7 = MEM_HU(ctx->r5, 0X12BC);
    // 0x8001E33C: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x8001E340: sh          $t6, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r14;
    // 0x8001E344: lbu         $t7, 0x12C8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X12C8);
    // 0x8001E348: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001E34C: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8001E350: sb          $t7, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r15;
    // 0x8001E354: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001E358: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001E35C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8001E360: swc1        $f4, 0x12C0($a1)
    MEM_W(0X12C0, ctx->r5) = ctx->f4.u32l;
    // 0x8001E364: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001E368: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001E36C: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8001E370: swc1        $f6, 0x12C4($a1)
    MEM_W(0X12C4, ctx->r5) = ctx->f6.u32l;
    // 0x8001E374: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001E378: sll         $t8, $a3, 4
    ctx->r24 = S32(ctx->r7 << 4);
    // 0x8001E37C: addu        $v0, $a1, $t8
    ctx->r2 = ADD32(ctx->r5, ctx->r24);
    // 0x8001E380: swc1        $f16, 0x1FC($v0)
    MEM_W(0X1FC, ctx->r2) = ctx->f16.u32l;
    // 0x8001E384: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001E388: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001E38C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001E390: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8001E394: swc1        $f4, 0x200($v0)
    MEM_W(0X200, ctx->r2) = ctx->f4.u32l;
    // 0x8001E398: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8001E39C: swc1        $f6, 0x204($v0)
    MEM_W(0X204, ctx->r2) = ctx->f6.u32l;
    // 0x8001E3A0: lbu         $t9, 0xDE($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XDE);
    // 0x8001E3A4: sb          $t9, 0x208($v0)
    MEM_B(0X208, ctx->r2) = ctx->r25;
    // 0x8001E3A8: lw          $t2, 0x38($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X38);
    // 0x8001E3AC: lw          $t0, 0x2C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X2C);
    // 0x8001E3B0: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8001E3B4: andi        $t3, $t2, 0x700
    ctx->r11 = ctx->r10 & 0X700;
    // 0x8001E3B8: andi        $t1, $t0, 0x700
    ctx->r9 = ctx->r8 & 0X700;
    // 0x8001E3BC: lbu         $t7, 0x12($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X12);
    // 0x8001E3C0: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x8001E3C4: lbu         $t1, 0x209($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X209);
    // 0x8001E3C8: srl         $t5, $t4, 8
    ctx->r13 = S32(U32(ctx->r12) >> 8);
    // 0x8001E3CC: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x8001E3D0: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x8001E3D4: andi        $t3, $t1, 0xFF0F
    ctx->r11 = ctx->r9 & 0XFF0F;
    // 0x8001E3D8: or          $t6, $t2, $t3
    ctx->r14 = ctx->r10 | ctx->r11;
    // 0x8001E3DC: sb          $t6, 0x209($v0)
    MEM_B(0X209, ctx->r2) = ctx->r14;
    // 0x8001E3E0: andi        $t5, $t6, 0xF0
    ctx->r13 = ctx->r14 & 0XF0;
    // 0x8001E3E4: sb          $t5, 0x209($v0)
    MEM_B(0X209, ctx->r2) = ctx->r13;
    // 0x8001E3E8: lwc1        $f10, 0x64($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X64);
    // 0x8001E3EC: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8001E3F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001E3F4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001E3F8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8001E3FC: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8001E400: nop

    // 0x8001E404: sh          $t8, 0x20A($v0)
    MEM_H(0X20A, ctx->r2) = ctx->r24;
    // 0x8001E408: sh          $a3, 0x12BC($a1)
    MEM_H(0X12BC, ctx->r5) = ctx->r7;
    // 0x8001E40C: lw          $t5, 0x174($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X174);
    // 0x8001E410: lbu         $t9, 0x18($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X18);
    // 0x8001E414: lbu         $t2, 0x30($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X30);
    // 0x8001E418: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8001E41C: xori        $t0, $t9, 0xA
    ctx->r8 = ctx->r25 ^ 0XA;
    // 0x8001E420: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8001E424: sltiu       $t3, $t2, 0x1
    ctx->r11 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8001E428: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8001E42C: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8001E430: sltu        $t8, $zero, $t7
    ctx->r24 = 0 < ctx->r15 ? 1 : 0;
    // 0x8001E434: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001E438: addu        $t6, $t1, $t4
    ctx->r14 = ADD32(ctx->r9, ctx->r12);
    // 0x8001E43C: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x8001E440: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8001E444: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8001E448: lw          $t9, -0x66D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X66D0);
    // 0x8001E44C: lhu         $a2, 0x24($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X24);
    // 0x8001E450: lbu         $a1, 0x23($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X23);
    // 0x8001E454: jalr        $t9
    // 0x8001E458: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8001E458: nop

    after_0:
    // 0x8001E45C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001E460: sb          $t2, 0x1F9($s0)
    MEM_B(0X1F9, ctx->r16) = ctx->r10;
    // 0x8001E464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E468: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001E46C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001E470: jr          $ra
    // 0x8001E474: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001E474: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800348A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800348A4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x800348A8: lbu         $t6, 0xF7($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF7);
    // 0x800348AC: bne         $t6, $zero, L_80034928
    if (ctx->r14 != 0) {
        // 0x800348B0: nop
    
            goto L_80034928;
    }
    // 0x800348B0: nop

    // 0x800348B4: lbu         $v1, 0xF6($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XF6);
    // 0x800348B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800348BC: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800348C0: beq         $v1, $at, L_800348D8
    if (ctx->r3 == ctx->r1) {
        // 0x800348C4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800348D8;
    }
    // 0x800348C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800348C8: beql        $v1, $at, L_800348F4
    if (ctx->r3 == ctx->r1) {
        // 0x800348CC: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_800348F4;
    }
    goto skip_0;
    // 0x800348CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x800348D0: jr          $ra
    // 0x800348D4: nop

    return;
    // 0x800348D4: nop

L_800348D8:
    // 0x800348D8: lbu         $t7, -0x766B($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X766B);
    // 0x800348DC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800348E0: bne         $t7, $zero, L_80034928
    if (ctx->r15 != 0) {
        // 0x800348E4: nop
    
            goto L_80034928;
    }
    // 0x800348E4: nop

    // 0x800348E8: jr          $ra
    // 0x800348EC: sb          $t8, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = ctx->r24;
    return;
    // 0x800348EC: sb          $t8, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = ctx->r24;
    // 0x800348F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_800348F4:
    // 0x800348F4: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x800348F8: addiu       $v1, $v0, 0xF8
    ctx->r3 = ADD32(ctx->r2, 0XF8);
    // 0x800348FC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80034900: nop

    // 0x80034904: bc1f        L_80034928
    if (!c1cs) {
        // 0x80034908: nop
    
            goto L_80034928;
    }
    // 0x80034908: nop

    // 0x8003490C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80034910: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80034914: beq         $a0, $zero, L_80034924
    if (ctx->r4 == 0) {
        // 0x80034918: addiu       $t9, $a0, -0x1
        ctx->r25 = ADD32(ctx->r4, -0X1);
            goto L_80034924;
    }
    // 0x80034918: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x8003491C: jr          $ra
    // 0x80034920: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    return;
    // 0x80034920: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_80034924:
    // 0x80034924: sb          $t0, 0xF7($v0)
    MEM_B(0XF7, ctx->r2) = ctx->r8;
L_80034928:
    // 0x80034928: jr          $ra
    // 0x8003492C: nop

    return;
    // 0x8003492C: nop

;}
RECOMP_FUNC void func_806AA0FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA0FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806AA100: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AA104: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AA108: jal         0x800653D8
    // 0x806AA10C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x806AA10C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806AA110: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x806AA114: bne         $t6, $zero, L_806AA15C
    if (ctx->r14 != 0) {
        // 0x806AA118: nop
    
            goto L_806AA15C;
    }
    // 0x806AA118: nop

    // 0x806AA11C: jal         0x800653D8
    // 0x806AA120: nop

    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x806AA120: nop

    after_1:
    // 0x806AA124: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x806AA128: beq         $t7, $zero, L_806AA14C
    if (ctx->r15 == 0) {
        // 0x806AA12C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806AA14C;
    }
    // 0x806AA12C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AA130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AA134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AA138: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x806AA13C: jal         0x806AA784
    // 0x806AA140: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806AA784(rdram, ctx);
        goto after_2;
    // 0x806AA140: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_2:
    // 0x806AA144: b           L_806AA15C
    // 0x806AA148: nop

        goto L_806AA15C;
    // 0x806AA148: nop

L_806AA14C:
    // 0x806AA14C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AA150: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x806AA154: jal         0x806AA784
    // 0x806AA158: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806AA784(rdram, ctx);
        goto after_3;
    // 0x806AA158: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_3:
L_806AA15C:
    // 0x806AA15C: jal         0x806AA06C
    // 0x806AA160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AA06C(rdram, ctx);
        goto after_4;
    // 0x806AA160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806AA164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806AA168: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AA16C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806AA170: jr          $ra
    // 0x806AA174: nop

    return;
    // 0x806AA174: nop

;}
RECOMP_FUNC void func_80077038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077038: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8007703C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80077040: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80077044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80077048: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8007704C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80077050: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80077054: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80077058: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8007705C: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80077060: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x80077064: jal         0x80077010
    // 0x80077068: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80077010(rdram, ctx);
        goto after_0;
    // 0x80077068: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x8007706C: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80077070: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80077074: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80077078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007707C: jr          $ra
    // 0x80077080: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80077080: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_805DCE24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DCE24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805DCE28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805DCE2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DCE30: jal         0x805DCAF4
    // 0x805DCE34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_805DCAF4(rdram, ctx);
        goto after_0;
    // 0x805DCE34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805DCE38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DCE3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DCE40: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x805DCE44: jal         0x805DD234
    // 0x805DCE48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_805DD234(rdram, ctx);
        goto after_1;
    // 0x805DCE48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x805DCE4C: jal         0x805DCCFC
    // 0x805DCE50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DCCFC(rdram, ctx);
        goto after_2;
    // 0x805DCE50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805DCE54: jal         0x805DCDB8
    // 0x805DCE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DCDB8(rdram, ctx);
        goto after_3;
    // 0x805DCE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805DCE5C: lui         $t6, 0x805E
    ctx->r14 = S32(RELOC_HI16(480, 0X20C8) << 16);
    // 0x805DCE60: addiu       $t6, $t6, -0x3238
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(480, 0X20C8));
    // 0x805DCE64: sw          $t6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r14;
    // 0x805DCE68: jal         0x80048378
    // 0x805DCE6C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    func_80048378(rdram, ctx);
        goto after_4;
    // 0x805DCE6C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    after_4:
    // 0x805DCE70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805DCE74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DCE78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805DCE7C: jr          $ra
    // 0x805DCE80: nop

    return;
    // 0x805DCE80: nop

;}
RECOMP_FUNC void func_804BB310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB310: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804BB314: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BB318: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BB31C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BB320: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804BB324: jal         0x804BB0C8
    // 0x804BB328: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_804BB0C8(rdram, ctx);
        goto after_0;
    // 0x804BB328: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x804BB32C: bnel        $v0, $zero, L_804BB390
    if (ctx->r2 != 0) {
        // 0x804BB330: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804BB390;
    }
    goto skip_0;
    // 0x804BB330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804BB334: lh          $t7, 0x184($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X184);
    // 0x804BB338: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x804BB33C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BB340: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x804BB344: beq         $at, $zero, L_804BB358
    if (ctx->r1 == 0) {
        // 0x804BB348: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_804BB358;
    }
    // 0x804BB348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BB34C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x804BB350: jal         0x804BB4C4
    // 0x804BB354: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804BB4C4(rdram, ctx);
        goto after_1;
    // 0x804BB354: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_804BB358:
    // 0x804BB358: lw          $t9, 0x1E0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1E0);
    // 0x804BB35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BB360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BB364: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x804BB368: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x804BB36C: bne         $at, $zero, L_804BB37C
    if (ctx->r1 != 0) {
        // 0x804BB370: sw          $t0, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r8;
            goto L_804BB37C;
    }
    // 0x804BB370: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
    // 0x804BB374: jal         0x804BB4C4
    // 0x804BB378: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_804BB4C4(rdram, ctx);
        goto after_2;
    // 0x804BB378: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
L_804BB37C:
    // 0x804BB37C: jal         0x804BAF2C
    // 0x804BB380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BAF2C(rdram, ctx);
        goto after_3;
    // 0x804BB380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804BB384: jal         0x804BAFE4
    // 0x804BB388: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    func_804BAFE4(rdram, ctx);
        goto after_4;
    // 0x804BB388: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    after_4:
    // 0x804BB38C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804BB390:
    // 0x804BB390: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BB394: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804BB398: jr          $ra
    // 0x804BB39C: nop

    return;
    // 0x804BB39C: nop

;}
RECOMP_FUNC void func_8073B700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073B700: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8073B704: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073B708: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8073B70C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8073B710: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8073B714: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073B718: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x8073B71C: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x8073B720: lhu         $s1, 0x18($s0)
    ctx->r17 = MEM_HU(ctx->r16, 0X18);
    // 0x8073B724: lw          $t7, 0x3C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X3C);
    // 0x8073B728: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x8073B72C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8073B730: beq         $s1, $at, L_8073B744
    if (ctx->r17 == ctx->r1) {
        // 0x8073B734: lw          $t0, 0x1F4($t7)
        ctx->r8 = MEM_W(ctx->r15, 0X1F4);
            goto L_8073B744;
    }
    // 0x8073B734: lw          $t0, 0x1F4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X1F4);
    // 0x8073B738: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x8073B73C: bne         $s1, $at, L_8073B754
    if (ctx->r17 != ctx->r1) {
        // 0x8073B740: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_8073B754;
    }
    // 0x8073B740: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
L_8073B744:
    // 0x8073B744: jal         0x8073B5A8
    // 0x8073B748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073B5A8(rdram, ctx);
        goto after_0;
    // 0x8073B748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8073B74C: b           L_8073B7E8
    // 0x8073B750: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
        goto L_8073B7E8;
    // 0x8073B750: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_8073B754:
    // 0x8073B754: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x8073B758: sh          $s1, 0x1A($t9)
    MEM_H(0X1A, ctx->r25) = ctx->r17;
    // 0x8073B75C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8073B760: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8073B764: sb          $a2, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r6;
    // 0x8073B768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8073B76C: jal         0x8005C27C
    // 0x8073B770: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x8073B770: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8073B774: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8073B778: lhu         $s1, 0x18($s0)
    ctx->r17 = MEM_HU(ctx->r16, 0X18);
    // 0x8073B77C: lbu         $a2, 0x27($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X27);
    // 0x8073B780: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x8073B784: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8073B788: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8073B78C: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x8073B790: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x8073B794: subu        $a2, $a2, $t3
    ctx->r6 = SUB32(ctx->r6, ctx->r11);
    // 0x8073B798: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8073B79C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8073B7A0: andi        $t4, $a2, 0x7
    ctx->r12 = ctx->r6 & 0X7;
    // 0x8073B7A4: beq         $t4, $zero, L_8073B7B4
    if (ctx->r12 == 0) {
        // 0x8073B7A8: nop
    
            goto L_8073B7B4;
    }
    // 0x8073B7A8: nop

    // 0x8073B7AC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8073B7B0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_8073B7B4:
    // 0x8073B7B4: jal         0x8005C27C
    // 0x8073B7B8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x8073B7B8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
    // 0x8073B7BC: lw          $t5, 0x10($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X10);
    // 0x8073B7C0: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8073B7C4: addiu       $a0, $zero, 0x289
    ctx->r4 = ADD32(0, 0X289);
    // 0x8073B7C8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8073B7CC: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x8073B7D0: bne         $at, $zero, L_8073B7DC
    if (ctx->r1 != 0) {
        // 0x8073B7D4: sw          $t6, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r14;
            goto L_8073B7DC;
    }
    // 0x8073B7D4: sw          $t6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r14;
    // 0x8073B7D8: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
L_8073B7DC:
    // 0x8073B7DC: jal         0x80067818
    // 0x8073B7E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8073B7E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8073B7E4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_8073B7E8:
    // 0x8073B7E8: jal         0x8073B8CC
    // 0x8073B7EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8073B8CC(rdram, ctx);
        goto after_4;
    // 0x8073B7EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x8073B7F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8073B7F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8073B7F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8073B7FC: jr          $ra
    // 0x8073B800: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8073B800: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80567F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80567F2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80567F30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80567F34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80567F38: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80567F3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80567F40: jal         0x8004700C
    // 0x80567F44: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80567F44: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x80567F48: beq         $v0, $zero, L_80567FC4
    if (ctx->r2 == 0) {
        // 0x80567F4C: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_80567FC4;
    }
    // 0x80567F4C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80567F50: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x80567F54: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80567F58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80567F5C: bne         $s0, $t6, L_80567FBC
    if (ctx->r16 != ctx->r14) {
        // 0x80567F60: nop
    
            goto L_80567FBC;
    }
    // 0x80567F60: nop

    // 0x80567F64: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80567F68: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80567F6C: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21A0) << 16);
    // 0x80567F70: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80567F74: lwc1        $f6, -0x68B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21A0));
    // 0x80567F78: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80567F7C: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x80567F80: lw          $t7, 0x1C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1C);
    // 0x80567F84: beql        $t7, $zero, L_80567FA0
    if (ctx->r15 == 0) {
        // 0x80567F88: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80567FA0;
    }
    goto skip_0;
    // 0x80567F88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x80567F8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80567F90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80567F94: b           L_80567FA8
    // 0x80567F98: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
        goto L_80567FA8;
    // 0x80567F98: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x80567F9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80567FA0:
    // 0x80567FA0: nop

    // 0x80567FA4: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
L_80567FA8:
    // 0x80567FA8: jal         0x80048F84
    // 0x80567FAC: sw          $t8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r24;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80567FAC: sw          $t8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r24;
    after_1:
    // 0x80567FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80567FB4: jal         0x80569310
    // 0x80567FB8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80569310(rdram, ctx);
        goto after_2;
    // 0x80567FB8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
L_80567FBC:
    // 0x80567FBC: jal         0x80567E60
    // 0x80567FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80567E60(rdram, ctx);
        goto after_3;
    // 0x80567FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80567FC4:
    // 0x80567FC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80567FC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80567FCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80567FD0: jr          $ra
    // 0x80567FD4: nop

    return;
    // 0x80567FD4: nop

;}
RECOMP_FUNC void func_80069900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069900: addiu       $sp, $sp, -0x818
    ctx->r29 = ADD32(ctx->r29, -0X818);
    // 0x80069904: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80069908: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8006990C: addiu       $t6, $t6, 0x6F58
    ctx->r14 = ADD32(ctx->r14, 0X6F58);
    // 0x80069910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069914: addiu       $t0, $t6, 0x7F8
    ctx->r8 = ADD32(ctx->r14, 0X7F8);
    // 0x80069918: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
L_8006991C:
    // 0x8006991C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80069920: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80069924: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80069928: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8006992C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80069930: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80069934: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80069938: bne         $t6, $t0, L_8006991C
    if (ctx->r14 != ctx->r8) {
        // 0x8006993C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8006991C;
    }
    // 0x8006993C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80069940: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80069944: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80069948: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8006994C: jal         0x80069A80
    // 0x80069950: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    func_80069A80(rdram, ctx);
        goto after_0;
    // 0x80069950: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    after_0:
    // 0x80069954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069958: addiu       $sp, $sp, 0x818
    ctx->r29 = ADD32(ctx->r29, 0X818);
    // 0x8006995C: jr          $ra
    // 0x80069960: nop

    return;
    // 0x80069960: nop

;}
RECOMP_FUNC void func_8073A604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073A604: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(739, 0X22DC) << 16);
    // 0x8073A608: lw          $t6, -0x42F4($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(739, 0X22DC));
    // 0x8073A60C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073A610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073A614: bne         $t6, $zero, L_8073A7A4
    if (ctx->r14 != 0) {
        // 0x8073A618: lui         $t7, 0x800F
        ctx->r15 = S32(0X800F << 16);
            goto L_8073A7A4;
    }
    // 0x8073A618: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x8073A61C: lw          $t7, 0x7EA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7EA8);
    // 0x8073A620: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8073A624: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8073A628: lb          $t8, 0x2($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X2);
    // 0x8073A62C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8073A630: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8073A634: nop

    // 0x8073A638: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8073A63C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8073A640: nop

    // 0x8073A644: bc1fl       L_8073A68C
    if (!c1cs) {
        // 0x8073A648: c.le.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
            goto L_8073A68C;
    }
    goto skip_0;
    // 0x8073A648: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    skip_0:
    // 0x8073A64C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8073A650: nop

    // 0x8073A654: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8073A658: nop

    // 0x8073A65C: bc1fl       L_8073A68C
    if (!c1cs) {
        // 0x8073A660: c.le.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
            goto L_8073A68C;
    }
    goto skip_1;
    // 0x8073A660: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    skip_1:
    // 0x8073A664: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8073A668: jal         0x80082050
    // 0x8073A66C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    truncf_recomp(rdram, ctx);
        goto after_0;
    // 0x8073A66C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8073A670: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8073A674: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8073A678: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X22D4) << 16);
    // 0x8073A67C: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x8073A680: b           L_8073A7A4
    // 0x8073A684: swc1        $f12, -0x42FC($at)
    MEM_W((int16_t)RELOC_LO16(739, 0X22D4), ctx->r1) = ctx->f12.u32l;
        goto L_8073A7A4;
    // 0x8073A684: swc1        $f12, -0x42FC($at)
    MEM_W((int16_t)RELOC_LO16(739, 0X22D4), ctx->r1) = ctx->f12.u32l;
    // 0x8073A688: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
L_8073A68C:
    // 0x8073A68C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8073A690: bc1fl       L_8073A6A4
    if (!c1cs) {
        // 0x8073A694: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8073A6A4;
    }
    goto skip_2;
    // 0x8073A694: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_2:
    // 0x8073A698: b           L_8073A6AC
    // 0x8073A69C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_8073A6AC;
    // 0x8073A69C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8073A6A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8073A6A4:
    // 0x8073A6A4: nop

    // 0x8073A6A8: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
L_8073A6AC:
    // 0x8073A6AC: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X22D4) << 16);
    // 0x8073A6B0: lwc1        $f12, -0x42FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X22D4));
    // 0x8073A6B4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8073A6B8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X2490) << 16);
    // 0x8073A6BC: lwc1        $f10, -0x4140($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X2490));
    // 0x8073A6C0: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x8073A6C4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8073A6C8: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8073A6CC: bc1fl       L_8073A748
    if (!c1cs) {
        // 0x8073A6D0: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8073A748;
    }
    goto skip_3;
    // 0x8073A6D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_3:
    // 0x8073A6D4: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8073A6D8: nop

    // 0x8073A6DC: bc1tl       L_8073A92C
    if (c1cs) {
        // 0x8073A6E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073A92C;
    }
    goto skip_4;
    // 0x8073A6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8073A6E4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8073A6E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8073A6EC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8073A6F0: nop

    // 0x8073A6F4: bc1fl       L_8073A724
    if (!c1cs) {
        // 0x8073A6F8: lwc1        $f8, 0x0($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
            goto L_8073A724;
    }
    goto skip_5;
    // 0x8073A6F8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    skip_5:
    // 0x8073A6FC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8073A700: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8073A704: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8073A708: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8073A70C: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8073A710: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8073A714: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8073A718: b           L_8073A734
    // 0x8073A71C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
        goto L_8073A734;
    // 0x8073A71C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8073A720: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
L_8073A724:
    // 0x8073A724: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8073A728: nop

    // 0x8073A72C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8073A730: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
L_8073A734:
    // 0x8073A734: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8073A738: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X22D4) << 16);
    // 0x8073A73C: b           L_8073A928
    // 0x8073A740: swc1        $f12, -0x42FC($at)
    MEM_W((int16_t)RELOC_LO16(739, 0X22D4), ctx->r1) = ctx->f12.u32l;
        goto L_8073A928;
    // 0x8073A740: swc1        $f12, -0x42FC($at)
    MEM_W((int16_t)RELOC_LO16(739, 0X22D4), ctx->r1) = ctx->f12.u32l;
    // 0x8073A744: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8073A748:
    // 0x8073A748: nop

    // 0x8073A74C: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x8073A750: nop

    // 0x8073A754: bc1fl       L_8073A770
    if (!c1cs) {
        // 0x8073A758: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_8073A770;
    }
    goto skip_6;
    // 0x8073A758: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_6:
    // 0x8073A75C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8073A760: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8073A764: b           L_8073A928
    // 0x8073A768: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
        goto L_8073A928;
    // 0x8073A768: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8073A76C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8073A770:
    // 0x8073A770: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8073A774: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8073A778: nop

    // 0x8073A77C: bc1fl       L_8073A798
    if (!c1cs) {
        // 0x8073A780: add.s       $f12, $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_8073A798;
    }
    goto skip_7;
    // 0x8073A780: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    skip_7:
    // 0x8073A784: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8073A788: nop

    // 0x8073A78C: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8073A790: nop

    // 0x8073A794: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_8073A798:
    // 0x8073A798: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X22D4) << 16);
    // 0x8073A79C: b           L_8073A928
    // 0x8073A7A0: swc1        $f12, -0x42FC($at)
    MEM_W((int16_t)RELOC_LO16(739, 0X22D4), ctx->r1) = ctx->f12.u32l;
        goto L_8073A928;
    // 0x8073A7A0: swc1        $f12, -0x42FC($at)
    MEM_W((int16_t)RELOC_LO16(739, 0X22D4), ctx->r1) = ctx->f12.u32l;
L_8073A7A4:
    // 0x8073A7A4: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x8073A7A8: lw          $t9, 0x7EA8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7EA8);
    // 0x8073A7AC: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8073A7B0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8073A7B4: lb          $t0, 0x3($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X3);
    // 0x8073A7B8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8073A7BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8073A7C0: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8073A7C4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8073A7C8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8073A7CC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8073A7D0: mul.s       $f0, $f18, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8073A7D4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8073A7D8: nop

    // 0x8073A7DC: bc1fl       L_8073A82C
    if (!c1cs) {
        // 0x8073A7E0: c.le.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
            goto L_8073A82C;
    }
    goto skip_8;
    // 0x8073A7E0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    skip_8:
    // 0x8073A7E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8073A7E8: nop

    // 0x8073A7EC: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8073A7F0: nop

    // 0x8073A7F4: bc1fl       L_8073A82C
    if (!c1cs) {
        // 0x8073A7F8: c.le.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
            goto L_8073A82C;
    }
    goto skip_9;
    // 0x8073A7F8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    skip_9:
    // 0x8073A7FC: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8073A800: jal         0x80082050
    // 0x8073A804: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    truncf_recomp(rdram, ctx);
        goto after_1;
    // 0x8073A804: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8073A808: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8073A80C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X22DC) << 16);
    // 0x8073A810: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8073A814: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8073A818: sw          $zero, -0x42F4($at)
    MEM_W((int16_t)RELOC_LO16(739, 0X22DC), ctx->r1) = 0;
    // 0x8073A81C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X22D8) << 16);
    // 0x8073A820: b           L_8073A928
    // 0x8073A824: swc1        $f12, -0x42F8($at)
    MEM_W((int16_t)RELOC_LO16(739, 0X22D8), ctx->r1) = ctx->f12.u32l;
        goto L_8073A928;
    // 0x8073A824: swc1        $f12, -0x42F8($at)
    MEM_W((int16_t)RELOC_LO16(739, 0X22D8), ctx->r1) = ctx->f12.u32l;
    // 0x8073A828: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
L_8073A82C:
    // 0x8073A82C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8073A830: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X22DC) << 16);
    // 0x8073A834: sw          $t1, -0x42F4($at)
    MEM_W((int16_t)RELOC_LO16(739, 0X22DC), ctx->r1) = ctx->r9;
    // 0x8073A838: bc1f        L_8073A848
    if (!c1cs) {
        // 0x8073A83C: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8073A848;
    }
    // 0x8073A83C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8073A840: b           L_8073A854
    // 0x8073A844: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_8073A854;
    // 0x8073A844: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_8073A848:
    // 0x8073A848: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8073A84C: nop

    // 0x8073A850: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
L_8073A854:
    // 0x8073A854: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X22D8) << 16);
    // 0x8073A858: lwc1        $f12, -0x42F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X22D8));
    // 0x8073A85C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8073A860: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X2494) << 16);
    // 0x8073A864: lwc1        $f8, -0x413C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X2494));
    // 0x8073A868: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x8073A86C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8073A870: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8073A874: bc1fl       L_8073A8E0
    if (!c1cs) {
        // 0x8073A878: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_8073A8E0;
    }
    goto skip_10;
    // 0x8073A878: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_10:
    // 0x8073A87C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8073A880: nop

    // 0x8073A884: bc1tl       L_8073A92C
    if (c1cs) {
        // 0x8073A888: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073A92C;
    }
    goto skip_11;
    // 0x8073A888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x8073A88C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8073A890: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8073A894: bc1fl       L_8073A8BC
    if (!c1cs) {
        // 0x8073A898: lwc1        $f6, 0x4($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
            goto L_8073A8BC;
    }
    goto skip_12;
    // 0x8073A898: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    skip_12:
    // 0x8073A89C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8073A8A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8073A8A4: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8073A8A8: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8073A8AC: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8073A8B0: b           L_8073A8CC
    // 0x8073A8B4: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
        goto L_8073A8CC;
    // 0x8073A8B4: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x8073A8B8: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
L_8073A8BC:
    // 0x8073A8BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8073A8C0: nop

    // 0x8073A8C4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8073A8C8: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
L_8073A8CC:
    // 0x8073A8CC: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8073A8D0: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X22D8) << 16);
    // 0x8073A8D4: b           L_8073A928
    // 0x8073A8D8: swc1        $f12, -0x42F8($at)
    MEM_W((int16_t)RELOC_LO16(739, 0X22D8), ctx->r1) = ctx->f12.u32l;
        goto L_8073A928;
    // 0x8073A8D8: swc1        $f12, -0x42F8($at)
    MEM_W((int16_t)RELOC_LO16(739, 0X22D8), ctx->r1) = ctx->f12.u32l;
    // 0x8073A8DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_8073A8E0:
    // 0x8073A8E0: nop

    // 0x8073A8E4: c.le.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
    // 0x8073A8E8: nop

    // 0x8073A8EC: bc1fl       L_8073A908
    if (!c1cs) {
        // 0x8073A8F0: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_8073A908;
    }
    goto skip_13;
    // 0x8073A8F0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_13:
    // 0x8073A8F4: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8073A8F8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8073A8FC: b           L_8073A928
    // 0x8073A900: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
        goto L_8073A928;
    // 0x8073A900: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x8073A904: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_8073A908:
    // 0x8073A908: nop

    // 0x8073A90C: bc1fl       L_8073A920
    if (!c1cs) {
        // 0x8073A910: add.s       $f12, $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_8073A920;
    }
    goto skip_14;
    // 0x8073A910: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    skip_14:
    // 0x8073A914: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8073A918: nop

    // 0x8073A91C: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_8073A920:
    // 0x8073A920: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X22D8) << 16);
    // 0x8073A924: swc1        $f12, -0x42F8($at)
    MEM_W((int16_t)RELOC_LO16(739, 0X22D8), ctx->r1) = ctx->f12.u32l;
L_8073A928:
    // 0x8073A928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8073A92C:
    // 0x8073A92C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073A930: jr          $ra
    // 0x8073A934: nop

    return;
    // 0x8073A934: nop

;}
RECOMP_FUNC void func_8007336C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007336C: lbu         $t6, 0x15($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15);
    // 0x80073370: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x80073374: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80073378: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007337C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80073380: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80073384: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80073388: jr          $ra
    // 0x8007338C: nop

    return;
    // 0x8007338C: nop

;}
RECOMP_FUNC void func_806A9908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A9908: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x806A990C: bgez        $a0, L_806A9964
    if (SIGNED(ctx->r4) >= 0) {
        // 0x806A9910: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_806A9964;
    }
    // 0x806A9910: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x806A9914: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x806A9918: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806A991C: addiu       $t6, $a0, 0x14
    ctx->r14 = ADD32(ctx->r4, 0X14);
    // 0x806A9920: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x806A9924: div.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f12.fl, ctx->f8.fl);
    // 0x806A9928: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x806A992C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806A9930: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x806A9934: mul.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x806A9938: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x806A993C: nop

    // 0x806A9940: bc1fl       L_806A9950
    if (!c1cs) {
        // 0x806A9944: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_806A9950;
    }
    goto skip_0;
    // 0x806A9944: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x806A9948: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x806A994C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_806A9950:
    // 0x806A9950: nop

    // 0x806A9954: bc1f        L_806A99AC
    if (!c1cs) {
        // 0x806A9958: nop
    
            goto L_806A99AC;
    }
    // 0x806A9958: nop

    // 0x806A995C: jr          $ra
    // 0x806A9960: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    return;
    // 0x806A9960: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_806A9964:
    // 0x806A9964: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806A9968: addiu       $t7, $a0, -0x14
    ctx->r15 = ADD32(ctx->r4, -0X14);
    // 0x806A996C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x806A9970: div.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x806A9974: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806A9978: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806A997C: mul.s       $f2, $f18, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x806A9980: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x806A9984: nop

    // 0x806A9988: bc1fl       L_806A999C
    if (!c1cs) {
        // 0x806A998C: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_806A999C;
    }
    goto skip_1;
    // 0x806A998C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_1:
    // 0x806A9990: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806A9994: nop

    // 0x806A9998: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_806A999C:
    // 0x806A999C: nop

    // 0x806A99A0: bc1f        L_806A99AC
    if (!c1cs) {
        // 0x806A99A4: nop
    
            goto L_806A99AC;
    }
    // 0x806A99A4: nop

    // 0x806A99A8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_806A99AC:
    // 0x806A99AC: jr          $ra
    // 0x806A99B0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x806A99B0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_80027304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80027308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002730C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80027310: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80027314: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80027318: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8002731C: nop

    // 0x80027320: bc1fl       L_8002733C
    if (!c1cs) {
        // 0x80027324: lw          $t6, 0x154($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X154);
            goto L_8002733C;
    }
    goto skip_0;
    // 0x80027324: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    skip_0:
    // 0x80027328: jal         0x800272EC
    // 0x8002732C: nop

    func_800272EC(rdram, ctx);
        goto after_0;
    // 0x8002732C: nop

    after_0:
    // 0x80027330: b           L_80027374
    // 0x80027334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80027374;
    // 0x80027334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027338: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
L_8002733C:
    // 0x8002733C: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x80027340: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80027344: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x80027348: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8002734C: sltu        $at, $t7, $t0
    ctx->r1 = ctx->r15 < ctx->r8 ? 1 : 0;
    // 0x80027350: bnel        $at, $zero, L_80027374
    if (ctx->r1 != 0) {
        // 0x80027354: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80027374;
    }
    goto skip_1;
    // 0x80027354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80027358: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x8002735C: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80027360: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80027364: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x80027368: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8002736C: sw          $t4, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r12;
    // 0x80027370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80027374:
    // 0x80027374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80027378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002737C: jr          $ra
    // 0x80027380: nop

    return;
    // 0x80027380: nop

;}
RECOMP_FUNC void func_8005B36C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B36C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005B370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B374: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x8005B378: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8005B37C: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8005B380: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8005B384: lui         $t8, 0xFC
    ctx->r24 = S32(0XFC << 16);
    // 0x8005B388: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8005B38C: ori         $t8, $t8, 0x1034
    ctx->r24 = ctx->r24 | 0X1034;
    // 0x8005B390: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005B394: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x8005B398: lbu         $t9, 0x5($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X5);
    // 0x8005B39C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8005B3A0: subu        $t0, $v0, $t9
    ctx->r8 = SUB32(ctx->r2, ctx->r25);
    // 0x8005B3A4: srav        $t1, $zero, $t0
    ctx->r9 = S32(SIGNED(0) >> (ctx->r8 & 31));
    // 0x8005B3A8: sh          $t1, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r9;
    // 0x8005B3AC: lbu         $t3, 0x5($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X5);
    // 0x8005B3B0: lhu         $t2, 0x8($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X8);
    // 0x8005B3B4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005B3B8: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x8005B3BC: srav        $t5, $t2, $t4
    ctx->r13 = S32(SIGNED(ctx->r10) >> (ctx->r12 & 31));
    // 0x8005B3C0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8005B3C4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8005B3C8: sh          $t7, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r15;
    // 0x8005B3CC: lhu         $t8, 0xA($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XA);
    // 0x8005B3D0: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x8005B3D4: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x8005B3D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005B3DC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8005B3E0: sh          $t0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r8;
    // 0x8005B3E4: sw          $a2, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r6;
    // 0x8005B3E8: sw          $t1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r9;
    // 0x8005B3EC: sh          $t3, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r11;
    // 0x8005B3F0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8005B3F4: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x8005B3F8: sh          $t4, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r12;
    // 0x8005B3FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005B400: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8005B404: jal         0x8005B270
    // 0x8005B408: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    func_8005B270(rdram, ctx);
        goto after_0;
    // 0x8005B408: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x8005B40C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005B410: sh          $v0, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r2;
    // 0x8005B414: jal         0x8005B270
    // 0x8005B418: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    func_8005B270(rdram, ctx);
        goto after_1;
    // 0x8005B418: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x8005B41C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005B420: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005B424: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8005B428: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x8005B42C: lhu         $t5, 0x8($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X8);
    // 0x8005B430: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x8005B434: sh          $t6, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r14;
    // 0x8005B438: lhu         $t7, 0xA($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XA);
    // 0x8005B43C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8005B440: sh          $t8, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r24;
    // 0x8005B444: lbu         $t0, 0x5($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X5);
    // 0x8005B448: lhu         $t9, 0x8($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X8);
    // 0x8005B44C: sh          $zero, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = 0;
    // 0x8005B450: subu        $t3, $t1, $t0
    ctx->r11 = SUB32(ctx->r9, ctx->r8);
    // 0x8005B454: srav        $t2, $t9, $t3
    ctx->r10 = S32(SIGNED(ctx->r25) >> (ctx->r11 & 31));
    // 0x8005B458: sh          $t2, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r10;
    // 0x8005B45C: lbu         $t4, 0x4($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X4);
    // 0x8005B460: sb          $t4, 0x2C($v1)
    MEM_B(0X2C, ctx->r3) = ctx->r12;
    // 0x8005B464: lbu         $t5, 0x5($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X5);
    // 0x8005B468: sb          $zero, 0x2E($v1)
    MEM_B(0X2E, ctx->r3) = 0;
    // 0x8005B46C: sb          $zero, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = 0;
    // 0x8005B470: sb          $t5, 0x2D($v1)
    MEM_B(0X2D, ctx->r3) = ctx->r13;
    // 0x8005B474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B478: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005B47C: jr          $ra
    // 0x8005B480: nop

    return;
    // 0x8005B480: nop

;}
RECOMP_FUNC void func_807427EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807427EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807427F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807427F4: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x807427F8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x807427FC: addu        $t0, $v0, $at
    ctx->r8 = ADD32(ctx->r2, ctx->r1);
    // 0x80742800: lw          $v1, 0x6E6C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X6E6C);
    // 0x80742804: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80742808: lw          $t1, 0x6E64($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X6E64);
    // 0x8074280C: bne         $v1, $at, L_8074281C
    if (ctx->r3 != ctx->r1) {
        // 0x80742810: nop
    
            goto L_8074281C;
    }
    // 0x80742810: nop

    // 0x80742814: beq         $t1, $zero, L_8074282C
    if (ctx->r9 == 0) {
        // 0x80742818: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8074282C;
    }
    // 0x80742818: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8074281C:
    // 0x8074281C: jal         0x807424D8
    // 0x80742820: nop

    func_807424D8(rdram, ctx);
        goto after_0;
    // 0x80742820: nop

    after_0:
    // 0x80742824: b           L_8074288C
    // 0x80742828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8074288C;
    // 0x80742828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8074282C:
    // 0x8074282C: lwc1        $f12, 0x6BE4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X6BE4);
    // 0x80742830: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80742834: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80742838: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8074283C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80742840: jal         0x80742354
    // 0x80742844: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80742354(rdram, ctx);
        goto after_1;
    // 0x80742844: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80742848: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8074284C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80742850: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80742854: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80742858: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8074285C: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80742860: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80742864: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80742868: jal         0x807423AC
    // 0x8074286C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    func_807423AC(rdram, ctx);
        goto after_2;
    // 0x8074286C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    after_2:
    // 0x80742870: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80742874: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80742878: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8074287C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80742880: swc1        $f0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80742884: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80742888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8074288C:
    // 0x8074288C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80742890: jr          $ra
    // 0x80742894: nop

    return;
    // 0x80742894: nop

;}
RECOMP_FUNC void func_8042F824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F824: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8042F828: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8042F82C: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8042F830: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8042F834: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042F838: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8042F83C: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8042F840: swc1        $f6, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f6.u32l;
    // 0x8042F844: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8042F848: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042F84C: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8042F850: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x8042F854: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8042F858: swc1        $f10, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f10.u32l;
    // 0x8042F85C: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042F860: jr          $ra
    // 0x8042F864: swc1        $f0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f0.u32l;
    return;
    // 0x8042F864: swc1        $f0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_805AC26C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC26C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805AC270: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805AC274: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805AC278: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805AC27C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AC280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805AC284: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x805AC288: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x805AC28C: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x805AC290: bnel        $t8, $zero, L_805AC334
    if (ctx->r24 != 0) {
        // 0x805AC294: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805AC334;
    }
    goto skip_0;
    // 0x805AC294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805AC298: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x805AC29C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805AC2A0: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x805AC2A4: beq         $t9, $zero, L_805AC2E8
    if (ctx->r25 == 0) {
        // 0x805AC2A8: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_805AC2E8;
    }
    // 0x805AC2A8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x805AC2AC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805AC2B0: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x805AC2B4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x805AC2B8: jal         0x8004D1F0
    // 0x805AC2BC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x805AC2BC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x805AC2C0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805AC2C4: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x805AC2C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AC2CC: jal         0x8004D698
    // 0x805AC2D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x805AC2D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x805AC2D4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805AC2D8: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x805AC2DC: ori         $t1, $t0, 0xF
    ctx->r9 = ctx->r8 | 0XF;
    // 0x805AC2E0: b           L_805AC31C
    // 0x805AC2E4: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
        goto L_805AC31C;
    // 0x805AC2E4: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
L_805AC2E8:
    // 0x805AC2E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AC2EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x805AC2F0: jal         0x8004D1F0
    // 0x805AC2F4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x805AC2F4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x805AC2F8: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805AC2FC: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x805AC300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AC304: jal         0x8004D698
    // 0x805AC308: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8004D698(rdram, ctx);
        goto after_3;
    // 0x805AC308: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x805AC30C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805AC310: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x805AC314: ori         $t3, $t2, 0xF0
    ctx->r11 = ctx->r10 | 0XF0;
    // 0x805AC318: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
L_805AC31C:
    // 0x805AC31C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x805AC320: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x805AC324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AC328: jal         0x805AC200
    // 0x805AC32C: sw          $t4, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r12;
    func_805AC200(rdram, ctx);
        goto after_4;
    // 0x805AC32C: sw          $t4, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r12;
    after_4:
    // 0x805AC330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805AC334:
    // 0x805AC334: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805AC338: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805AC33C: jr          $ra
    // 0x805AC340: nop

    return;
    // 0x805AC340: nop

;}
RECOMP_FUNC void func_805D32D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D32D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D32D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D32DC: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x805D32E0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x805D32E4: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(471, 0X2460) << 16);
    // 0x805D32E8: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x805D32EC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805D32F0: addiu       $t7, $t7, 0x3E90
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(471, 0X2460));
    // 0x805D32F4: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805D32F8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805D32FC: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x805D3300: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805D3304: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x805D3308: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805D330C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805D3310: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x805D3314: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D3318: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x805D331C: bnel        $v1, $zero, L_805D333C
    if (ctx->r3 != 0) {
        // 0x805D3320: lwc1        $f4, 0x3C($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_805D333C;
    }
    goto skip_0;
    // 0x805D3320: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    skip_0:
    // 0x805D3324: jal         0x80045A34
    // 0x805D3328: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805D3328: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D332C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D3330: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x805D3334: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x805D3338: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
L_805D333C:
    // 0x805D333C: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x805D3340: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805D3344: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x805D3348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D334C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D3350: jr          $ra
    // 0x805D3354: nop

    return;
    // 0x805D3354: nop

;}
RECOMP_FUNC void func_8004D6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D6C8: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8004D6CC: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // 0x8004D6D0: multu       $a1, $v0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004D6D4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8004D6D8: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8004D6DC: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8004D6E0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8004D6E4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8004D6E8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8004D6EC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8004D6F0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8004D6F4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8004D6F8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8004D6FC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8004D700: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8004D704: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8004D708: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8004D70C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8004D710: mflo        $t9
    ctx->r25 = lo;
    // 0x8004D714: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8004D718: sw          $t6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r14;
    // 0x8004D71C: lw          $s0, 0x174($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X174);
    // 0x8004D720: multu       $a3, $v0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004D724: sw          $a1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r5;
    // 0x8004D728: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    // 0x8004D72C: sw          $a2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r6;
    // 0x8004D730: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8004D734: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8004D738: addiu       $fp, $sp, 0x74
    ctx->r30 = ADD32(ctx->r29, 0X74);
    // 0x8004D73C: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8004D740: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x8004D744: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8004D748: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8004D74C: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8004D750: mflo        $t3
    ctx->r11 = lo;
    // 0x8004D754: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8004D758: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8004D75C: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004D760: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8004D764: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x8004D768: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8004D76C: sw          $t4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r12;
    // 0x8004D770: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8004D774: lw          $t6, 0x40($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X40);
    // 0x8004D778: mflo        $t7
    ctx->r15 = lo;
    // 0x8004D77C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8004D780: jal         0x80047AB8
    // 0x8004D784: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8004D784: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
    after_0:
    // 0x8004D788: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8004D78C: lwc1        $f6, 0x88($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X88);
    // 0x8004D790: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8004D794: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004D798: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8004D79C: addiu       $s6, $sp, 0x94
    ctx->r22 = ADD32(ctx->r29, 0X94);
    // 0x8004D7A0: addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
    // 0x8004D7A4: addiu       $s4, $zero, 0x38
    ctx->r20 = ADD32(0, 0X38);
    // 0x8004D7A8: bc1f        L_8004D8DC
    if (!c1cs) {
        // 0x8004D7AC: ori         $s3, $zero, 0xFFFF
        ctx->r19 = 0 | 0XFFFF;
            goto L_8004D8DC;
    }
    // 0x8004D7AC: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x8004D7B0: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8004D7B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8004D7B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004D7BC: bne         $t9, $zero, L_8004D9D0
    if (ctx->r25 != 0) {
        // 0x8004D7C0: addiu       $s6, $sp, 0x94
        ctx->r22 = ADD32(ctx->r29, 0X94);
            goto L_8004D9D0;
    }
    // 0x8004D7C0: addiu       $s6, $sp, 0x94
    ctx->r22 = ADD32(ctx->r29, 0X94);
    // 0x8004D7C4: lwc1        $f26, 0x8E0($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X8E0);
    // 0x8004D7C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004D7CC: lwc1        $f24, 0x8E4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X8E4);
    // 0x8004D7D0: addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
    // 0x8004D7D4: addiu       $s4, $zero, 0x38
    ctx->r20 = ADD32(0, 0X38);
    // 0x8004D7D8: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x8004D7DC: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
L_8004D7E0:
    // 0x8004D7E0: addiu       $t0, $sp, 0x88
    ctx->r8 = ADD32(ctx->r29, 0X88);
    // 0x8004D7E4: addu        $s0, $v1, $t0
    ctx->r16 = ADD32(ctx->r3, ctx->r8);
    // 0x8004D7E8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8004D7EC: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8004D7F0: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8004D7F4: beq         $t3, $zero, L_8004D8C0
    if (ctx->r11 == 0) {
        // 0x8004D7F8: sh          $t2, 0x80($sp)
        MEM_H(0X80, ctx->r29) = ctx->r10;
            goto L_8004D8C0;
    }
    // 0x8004D7F8: sh          $t2, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r10;
    // 0x8004D7FC: beq         $s3, $t3, L_8004D8C0
    if (ctx->r19 == ctx->r11) {
        // 0x8004D800: lbu         $v0, 0x80($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X80);
            goto L_8004D8C0;
    }
    // 0x8004D800: lbu         $v0, 0x80($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X80);
    // 0x8004D804: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8004D808: beql        $s4, $v0, L_8004D8C4
    if (ctx->r20 == ctx->r2) {
        // 0x8004D80C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8004D8C4;
    }
    goto skip_0;
    // 0x8004D80C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8004D810: beq         $s5, $v0, L_8004D8C0
    if (ctx->r21 == ctx->r2) {
        // 0x8004D814: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8004D8C0;
    }
    // 0x8004D814: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004D818: addu        $t4, $s6, $v1
    ctx->r12 = ADD32(ctx->r22, ctx->r3);
    // 0x8004D81C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004D820: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x8004D824: jal         0x8004CEF8
    // 0x8004D828: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    func_8004CEF8(rdram, ctx);
        goto after_1;
    // 0x8004D828: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_1:
    // 0x8004D82C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D830: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004D834: c.le.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl <= ctx->f8.fl;
    // 0x8004D838: nop

    // 0x8004D83C: bc1fl       L_8004D858
    if (!c1cs) {
        // 0x8004D840: lw          $t6, 0xA4($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA4);
            goto L_8004D858;
    }
    goto skip_1;
    // 0x8004D840: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    skip_1:
    // 0x8004D844: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // 0x8004D848: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8004D84C: swc1        $f20, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f20.u32l;
    // 0x8004D850: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D854: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
L_8004D858:
    // 0x8004D858: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8004D85C: andi        $t8, $t7, 0x3000
    ctx->r24 = ctx->r15 & 0X3000;
    // 0x8004D860: beql        $t8, $zero, L_8004D87C
    if (ctx->r24 == 0) {
        // 0x8004D864: lwc1        $f0, 0x8($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
            goto L_8004D87C;
    }
    goto skip_2;
    // 0x8004D864: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    skip_2:
    // 0x8004D868: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // 0x8004D86C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8004D870: b           L_8004D8C0
    // 0x8004D874: swc1        $f20, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f20.u32l;
        goto L_8004D8C0;
    // 0x8004D874: swc1        $f20, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f20.u32l;
    // 0x8004D878: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
L_8004D87C:
    // 0x8004D87C: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x8004D880: nop

    // 0x8004D884: bc1tl       L_8004D8A0
    if (c1cs) {
        // 0x8004D888: sb          $zero, 0x14($v0)
        MEM_B(0X14, ctx->r2) = 0;
            goto L_8004D8A0;
    }
    goto skip_3;
    // 0x8004D888: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    skip_3:
    // 0x8004D88C: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x8004D890: nop

    // 0x8004D894: bc1fl       L_8004D8C4
    if (!c1cs) {
        // 0x8004D898: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8004D8C4;
    }
    goto skip_4;
    // 0x8004D898: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x8004D89C: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
L_8004D8A0:
    // 0x8004D8A0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8004D8A4: lwc1        $f0, 0x8($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8004D8A8: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8004D8AC: nop

    // 0x8004D8B0: bc1fl       L_8004D8C4
    if (!c1cs) {
        // 0x8004D8B4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8004D8C4;
    }
    goto skip_5;
    // 0x8004D8B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x8004D8B8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8004D8BC: andi        $s7, $s1, 0xFF
    ctx->r23 = ctx->r17 & 0XFF;
L_8004D8C0:
    // 0x8004D8C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8004D8C4:
    // 0x8004D8C4: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8004D8C8: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x8004D8CC: bnel        $at, $zero, L_8004D7E0
    if (ctx->r1 != 0) {
        // 0x8004D8D0: sll         $v1, $s1, 2
        ctx->r3 = S32(ctx->r17 << 2);
            goto L_8004D7E0;
    }
    goto skip_6;
    // 0x8004D8D0: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    skip_6:
    // 0x8004D8D4: b           L_8004D9D4
    // 0x8004D8D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
        goto L_8004D9D4;
    // 0x8004D8D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8004D8DC:
    // 0x8004D8DC: lwc1        $f26, 0x8E8($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X8E8);
    // 0x8004D8E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004D8E4: lwc1        $f24, 0x8EC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X8EC);
    // 0x8004D8E8: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
L_8004D8EC:
    // 0x8004D8EC: addiu       $t1, $sp, 0x88
    ctx->r9 = ADD32(ctx->r29, 0X88);
    // 0x8004D8F0: addu        $s0, $v1, $t1
    ctx->r16 = ADD32(ctx->r3, ctx->r9);
    // 0x8004D8F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D8F8: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8004D8FC: beql        $a0, $zero, L_8004D9C0
    if (ctx->r4 == 0) {
        // 0x8004D900: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8004D9C0;
    }
    goto skip_7;
    // 0x8004D900: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x8004D904: beql        $s3, $a0, L_8004D9C0
    if (ctx->r19 == ctx->r4) {
        // 0x8004D908: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8004D9C0;
    }
    goto skip_8;
    // 0x8004D908: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_8:
    // 0x8004D90C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x8004D910: andi        $a0, $a0, 0xF8
    ctx->r4 = ctx->r4 & 0XF8;
    // 0x8004D914: beql        $s4, $a0, L_8004D9C0
    if (ctx->r20 == ctx->r4) {
        // 0x8004D918: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8004D9C0;
    }
    goto skip_9;
    // 0x8004D918: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_9:
    // 0x8004D91C: beq         $s5, $a0, L_8004D9BC
    if (ctx->r21 == ctx->r4) {
        // 0x8004D920: addu        $t2, $s6, $v1
        ctx->r10 = ADD32(ctx->r22, ctx->r3);
            goto L_8004D9BC;
    }
    // 0x8004D920: addu        $t2, $s6, $v1
    ctx->r10 = ADD32(ctx->r22, ctx->r3);
    // 0x8004D924: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004D928: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004D92C: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x8004D930: jal         0x8004CEF8
    // 0x8004D934: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    func_8004CEF8(rdram, ctx);
        goto after_2;
    // 0x8004D934: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_2:
    // 0x8004D938: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D93C: lwc1        $f16, 0xB8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8004D940: lbu         $t3, 0x14($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X14);
    // 0x8004D944: beql        $t3, $zero, L_8004D960
    if (ctx->r11 == 0) {
        // 0x8004D948: lwc1        $f0, 0x8($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
            goto L_8004D960;
    }
    goto skip_10;
    // 0x8004D948: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    skip_10:
    // 0x8004D94C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004D950: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004D954: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x8004D958: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D95C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
L_8004D960:
    // 0x8004D960: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x8004D964: nop

    // 0x8004D968: bc1fl       L_8004D988
    if (!c1cs) {
        // 0x8004D96C: c.lt.s      $f24, $f0
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
            goto L_8004D988;
    }
    goto skip_11;
    // 0x8004D96C: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    skip_11:
    // 0x8004D970: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // 0x8004D974: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8004D978: swc1        $f20, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f20.u32l;
    // 0x8004D97C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8004D980: lwc1        $f0, 0x8($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8004D984: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
L_8004D988:
    // 0x8004D988: nop

    // 0x8004D98C: bc1tl       L_8004D9A8
    if (c1cs) {
        // 0x8004D990: c.lt.s      $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
            goto L_8004D9A8;
    }
    goto skip_12;
    // 0x8004D990: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    skip_12:
    // 0x8004D994: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x8004D998: nop

    // 0x8004D99C: bc1fl       L_8004D9C0
    if (!c1cs) {
        // 0x8004D9A0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8004D9C0;
    }
    goto skip_13;
    // 0x8004D9A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_13:
    // 0x8004D9A4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
L_8004D9A8:
    // 0x8004D9A8: nop

    // 0x8004D9AC: bc1fl       L_8004D9C0
    if (!c1cs) {
        // 0x8004D9B0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8004D9C0;
    }
    goto skip_14;
    // 0x8004D9B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_14:
    // 0x8004D9B4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8004D9B8: andi        $s7, $s1, 0xFF
    ctx->r23 = ctx->r17 & 0XFF;
L_8004D9BC:
    // 0x8004D9BC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8004D9C0:
    // 0x8004D9C0: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8004D9C4: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x8004D9C8: bnel        $at, $zero, L_8004D8EC
    if (ctx->r1 != 0) {
        // 0x8004D9CC: sll         $v1, $s1, 2
        ctx->r3 = S32(ctx->r17 << 2);
            goto L_8004D8EC;
    }
    goto skip_15;
    // 0x8004D9CC: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    skip_15:
L_8004D9D0:
    // 0x8004D9D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8004D9D4:
    // 0x8004D9D4: beq         $s7, $at, L_8004DA10
    if (ctx->r23 == ctx->r1) {
        // 0x8004D9D8: lui         $t0, 0x800A
        ctx->r8 = S32(0X800A << 16);
            goto L_8004DA10;
    }
    // 0x8004D9D8: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8004D9DC: sll         $t6, $s7, 2
    ctx->r14 = S32(ctx->r23 << 2);
    // 0x8004D9E0: addiu       $t7, $sp, 0x88
    ctx->r15 = ADD32(ctx->r29, 0X88);
    // 0x8004D9E4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8004D9E8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8004D9EC: lwc1        $f4, 0x3C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x8004D9F0: lwc1        $f10, 0x40($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X40);
    // 0x8004D9F4: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8004D9F8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004D9FC: swc1        $f8, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f8.u32l;
    // 0x8004DA00: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8004DA04: lwc1        $f16, 0x8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8004DA08: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004DA0C: swc1        $f18, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f18.u32l;
L_8004DA10:
    // 0x8004DA10: addu        $t0, $t0, $s7
    ctx->r8 = ADD32(ctx->r8, ctx->r23);
    // 0x8004DA14: lbu         $t0, 0x100C($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X100C);
    // 0x8004DA18: lw          $t1, 0x1F4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X1F4);
    // 0x8004DA1C: sb          $t0, 0x5C($t1)
    MEM_B(0X5C, ctx->r9) = ctx->r8;
    // 0x8004DA20: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8004DA24: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8004DA28: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8004DA2C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8004DA30: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8004DA34: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8004DA38: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8004DA3C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8004DA40: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8004DA44: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8004DA48: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8004DA4C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8004DA50: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8004DA54: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8004DA58: jr          $ra
    // 0x8004DA5C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8004DA5C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_800406E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800406E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800406E4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800406E8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800406EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800406F0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800406F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800406F8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800406FC: lw          $s1, 0x174($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X174);
    // 0x80040700: jal         0x8004816C
    // 0x80040704: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8004816C(rdram, ctx);
        goto after_0;
    // 0x80040704: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80040708: lwc1        $f4, 0x84($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X84);
    // 0x8004070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80040710: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80040714: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x80040718: lwc1        $f6, 0x88($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X88);
    // 0x8004071C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x80040720: lwc1        $f8, 0x8C($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8C);
    // 0x80040724: jal         0x800404C8
    // 0x80040728: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    func_800404C8(rdram, ctx);
        goto after_1;
    // 0x80040728: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8004072C: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x80040730: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80040734: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80040738: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x8004073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80040740: jalr        $t9
    // 0x80040744: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80040744: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    after_2:
    // 0x80040748: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8004074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80040750: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x80040754: lh          $t8, 0xC($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XC);
    // 0x80040758: sh          $t8, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r24;
    // 0x8004075C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80040760: lw          $t0, 0x20($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X20);
    // 0x80040764: lh          $t1, 0xE($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XE);
    // 0x80040768: sh          $t1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r9;
    // 0x8004076C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80040770: lw          $t2, 0x20($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X20);
    // 0x80040774: lh          $t3, 0x10($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X10);
    // 0x80040778: jal         0x8005FDC4
    // 0x8004077C: sh          $t3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r11;
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x8004077C: sh          $t3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r11;
    after_3:
    // 0x80040780: lhu         $t4, 0xC($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XC);
    // 0x80040784: addiu       $at, $zero, 0x406C
    ctx->r1 = ADD32(0, 0X406C);
    // 0x80040788: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x8004078C: bne         $t4, $at, L_800407A8
    if (ctx->r12 != ctx->r1) {
        // 0x80040790: addiu       $t1, $t1, -0x7644
        ctx->r9 = ADD32(ctx->r9, -0X7644);
            goto L_800407A8;
    }
    // 0x80040790: addiu       $t1, $t1, -0x7644
    ctx->r9 = ADD32(ctx->r9, -0X7644);
    // 0x80040794: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80040798: sh          $zero, 0x4C($t5)
    MEM_H(0X4C, ctx->r13) = 0;
    // 0x8004079C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800407A0: b           L_800407C4
    // 0x800407A4: sw          $zero, 0x44($t6)
    MEM_W(0X44, ctx->r14) = 0;
        goto L_800407C4;
    // 0x800407A4: sw          $zero, 0x44($t6)
    MEM_W(0X44, ctx->r14) = 0;
L_800407A8:
    // 0x800407A8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800407AC: addiu       $t9, $zero, 0x153
    ctx->r25 = ADD32(0, 0X153);
    // 0x800407B0: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x800407B4: sh          $t9, 0x4C($t7)
    MEM_H(0X4C, ctx->r15) = ctx->r25;
    // 0x800407B8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800407BC: addiu       $t8, $t8, -0x6004
    ctx->r24 = ADD32(ctx->r24, -0X6004);
    // 0x800407C0: sw          $t8, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r24;
L_800407C4:
    // 0x800407C4: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x800407C8: jal         0x8001D770
    // 0x800407CC: sw          $t1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r9;
    func_8001D770(rdram, ctx);
        goto after_4;
    // 0x800407CC: sw          $t1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r9;
    after_4:
    // 0x800407D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800407D4: lw          $a1, 0x34($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X34);
    // 0x800407D8: jal         0x80067BF8
    // 0x800407DC: lw          $a2, 0x38($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_5;
    // 0x800407DC: lw          $a2, 0x38($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X38);
    after_5:
    // 0x800407E0: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    // 0x800407E4: jal         0x80067818
    // 0x800407E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x800407E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x800407EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800407F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800407F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800407F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800407FC: jr          $ra
    // 0x80040800: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80040800: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8041DFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041DFA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8041DFA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041DFA8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041DFAC: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X34E8) << 16);
    // 0x8041DFB0: lwc1        $f4, 0xB48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X34E8));
    // 0x8041DFB4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8041DFB8: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x8041DFBC: jal         0x80062D14
    // 0x8041DFC0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80062D14(rdram, ctx);
        goto after_0;
    // 0x8041DFC0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8041DFC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8041DFC8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8041DFCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8041DFD0: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8041DFD4: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8041DFD8: addiu       $at, $zero, 0x45F0
    ctx->r1 = ADD32(0, 0X45F0);
    // 0x8041DFDC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8041DFE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041DFE4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8041DFE8: beq         $v0, $at, L_8041E004
    if (ctx->r2 == ctx->r1) {
        // 0x8041DFEC: swc1        $f10, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
            goto L_8041E004;
    }
    // 0x8041DFEC: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x8041DFF0: addiu       $at, $zero, 0x4638
    ctx->r1 = ADD32(0, 0X4638);
    // 0x8041DFF4: beql        $v0, $at, L_8041E030
    if (ctx->r2 == ctx->r1) {
        // 0x8041DFF8: lui         $at, 0x4352
        ctx->r1 = S32(0X4352 << 16);
            goto L_8041E030;
    }
    goto skip_0;
    // 0x8041DFF8: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    skip_0:
    // 0x8041DFFC: b           L_8041E058
    // 0x8041E000: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_8041E058;
    // 0x8041E000: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8041E004:
    // 0x8041E004: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x8041E008: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8041E00C: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8041E010: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8041E014: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8041E018: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8041E01C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8041E020: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x8041E024: b           L_8041E054
    // 0x8041E028: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
        goto L_8041E054;
    // 0x8041E028: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8041E02C: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
L_8041E030:
    // 0x8041E030: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8041E034: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8041E038: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8041E03C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8041E040: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8041E044: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8041E048: sw          $t7, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r15;
    // 0x8041E04C: swc1        $f18, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f18.u32l;
    // 0x8041E050: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
L_8041E054:
    // 0x8041E054: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8041E058:
    // 0x8041E058: jal         0x8041FE10
    // 0x8041E05C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8041FE10(rdram, ctx);
        goto after_1;
    // 0x8041E05C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8041E060: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8041E064: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8041E068: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8041E06C: sh          $t8, 0x2E($t9)
    MEM_H(0X2E, ctx->r25) = ctx->r24;
    // 0x8041E070: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8041E074: lwc1        $f6, 0x7C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8041E078: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8041E07C: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x8041E080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041E084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8041E088: jr          $ra
    // 0x8041E08C: nop

    return;
    // 0x8041E08C: nop

;}
RECOMP_FUNC void func_8079A258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079A258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079A25C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079A260: jal         0x8004700C
    // 0x8079A264: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8079A264: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8079A268: beq         $v0, $zero, L_8079A2A8
    if (ctx->r2 == 0) {
        // 0x8079A26C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079A2A8;
    }
    // 0x8079A26C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079A270: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8079A274: lw          $t7, 0x180($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X180);
    // 0x8079A278: bnel        $t6, $t7, L_8079A2AC
    if (ctx->r14 != ctx->r15) {
        // 0x8079A27C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8079A2AC;
    }
    goto skip_0;
    // 0x8079A27C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8079A280: lbu         $t8, 0x18($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X18);
    // 0x8079A284: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8079A288: bnel        $t8, $at, L_8079A2AC
    if (ctx->r24 != ctx->r1) {
        // 0x8079A28C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8079A2AC;
    }
    goto skip_1;
    // 0x8079A28C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8079A290: lbu         $t9, 0x30($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X30);
    // 0x8079A294: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8079A298: bnel        $t9, $at, L_8079A2AC
    if (ctx->r25 != ctx->r1) {
        // 0x8079A29C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8079A2AC;
    }
    goto skip_2;
    // 0x8079A29C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8079A2A0: b           L_8079A2AC
    // 0x8079A2A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8079A2AC;
    // 0x8079A2A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8079A2A8:
    // 0x8079A2A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8079A2AC:
    // 0x8079A2AC: jr          $ra
    // 0x8079A2B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8079A2B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804B9248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B9248: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804B924C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B9250: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B9254: jal         0x8004700C
    // 0x804B9258: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804B9258: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804B925C: beq         $v0, $zero, L_804B92E8
    if (ctx->r2 == 0) {
        // 0x804B9260: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_804B92E8;
    }
    // 0x804B9260: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804B9264: jal         0x804B7E74
    // 0x804B9268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B7E74(rdram, ctx);
        goto after_1;
    // 0x804B9268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804B926C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B9270: jal         0x80062684
    // 0x804B9274: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062684(rdram, ctx);
        goto after_2;
    // 0x804B9274: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_2:
    // 0x804B9278: jal         0x804B8C58
    // 0x804B927C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B8C58(rdram, ctx);
        goto after_3;
    // 0x804B927C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804B9280: jal         0x804B8CB4
    // 0x804B9284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B8CB4(rdram, ctx);
        goto after_4;
    // 0x804B9284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804B9288: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804B928C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B9290: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B9294: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x804B9298: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804B929C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x804B92A0: beq         $s0, $t6, L_804B92B8
    if (ctx->r16 == ctx->r14) {
        // 0x804B92A4: lui         $t7, 0x8010
        ctx->r15 = S32(0X8010 << 16);
            goto L_804B92B8;
    }
    // 0x804B92A4: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x804B92A8: jal         0x804B9890
    // 0x804B92AC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804B9890(rdram, ctx);
        goto after_5;
    // 0x804B92AC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_5:
    // 0x804B92B0: b           L_804B92EC
    // 0x804B92B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804B92EC;
    // 0x804B92B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B92B8:
    // 0x804B92B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804B92BC: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x804B92C0: lw          $t7, -0x7BC4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7BC4);
    // 0x804B92C4: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x804B92C8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804B92CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804B92D0: lwc1        $f16, 0x3C($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x804B92D4: lw          $t8, 0x1F4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1F4);
    // 0x804B92D8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804B92DC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x804B92E0: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x804B92E4: swc1        $f6, 0xE4($t8)
    MEM_W(0XE4, ctx->r24) = ctx->f6.u32l;
L_804B92E8:
    // 0x804B92E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B92EC:
    // 0x804B92EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B92F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804B92F4: jr          $ra
    // 0x804B92F8: nop

    return;
    // 0x804B92F8: nop

;}
RECOMP_FUNC void func_80441330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80441334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80441338: jal         0x8004700C
    // 0x8044133C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8044133C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80441340: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80441344: beq         $v0, $zero, L_804413D0
    if (ctx->r2 == 0) {
        // 0x80441348: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_804413D0;
    }
    // 0x80441348: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044134C: lw          $v0, 0x2628($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2628);
    // 0x80441350: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80441354: beq         $at, $zero, L_804413C0
    if (ctx->r1 == 0) {
        // 0x80441358: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_804413C0;
    }
    // 0x80441358: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8044135C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80441360: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80441364: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80441368: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8044136C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80441370: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80441374: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80441378: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8044137C: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80441380: lwc1        $f10, 0x84($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X84);
    // 0x80441384: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80441388: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8044138C: nop

    // 0x80441390: bc1fl       L_804413B4
    if (!c1cs) {
        // 0x80441394: lwc1        $f6, 0x0($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
            goto L_804413B4;
    }
    goto skip_0;
    // 0x80441394: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80441398: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8044139C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x804413A0: lw          $t7, 0x2628($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2628);
    // 0x804413A4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x804413A8: sw          $t8, 0x2628($v1)
    MEM_W(0X2628, ctx->r3) = ctx->r24;
    // 0x804413AC: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804413B0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
L_804413B4:
    // 0x804413B4: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x804413B8: b           L_804413D0
    // 0x804413BC: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
        goto L_804413D0;
    // 0x804413BC: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
L_804413C0:
    // 0x804413C0: slti        $at, $t9, 0x3D
    ctx->r1 = SIGNED(ctx->r25) < 0X3D ? 1 : 0;
    // 0x804413C4: bne         $at, $zero, L_804413D0
    if (ctx->r1 != 0) {
        // 0x804413C8: sw          $t9, 0x2628($v1)
        MEM_W(0X2628, ctx->r3) = ctx->r25;
            goto L_804413D0;
    }
    // 0x804413C8: sw          $t9, 0x2628($v1)
    MEM_W(0X2628, ctx->r3) = ctx->r25;
    // 0x804413CC: sw          $zero, 0x2628($v1)
    MEM_W(0X2628, ctx->r3) = 0;
L_804413D0:
    // 0x804413D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804413D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804413D8: jr          $ra
    // 0x804413DC: nop

    return;
    // 0x804413DC: nop

;}
RECOMP_FUNC void func_800813E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800813E0: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800813E4: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800813E8: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800813EC: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800813F0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800813F4: lwc1        $f18, 0x30($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800813F8: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800813FC: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80081400: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80081404: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80081408: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8008140C: lwc1        $f10, 0x14($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80081410: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80081414: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80081418: nop

    // 0x8008141C: mul.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80081420: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80081424: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80081428: jr          $ra
    // 0x8008142C: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8008142C: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80034DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034DAC: jal         0x80023B78
    // 0x80034DB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80023B78(rdram, ctx);
        goto after_0;
    // 0x80034DB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80034DB4: jal         0x80023EA0
    // 0x80034DB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80023EA0(rdram, ctx);
        goto after_1;
    // 0x80034DB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80034DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034DC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034DC4: jr          $ra
    // 0x80034DC8: nop

    return;
    // 0x80034DC8: nop

;}
RECOMP_FUNC void func_80568FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568FC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80568FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80568FC8: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80568FCC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80568FD0: addiu       $at, $zero, 0x4159
    ctx->r1 = ADD32(0, 0X4159);
    // 0x80568FD4: beq         $v0, $at, L_80568FF4
    if (ctx->r2 == ctx->r1) {
        // 0x80568FD8: addiu       $at, $zero, 0x4165
        ctx->r1 = ADD32(0, 0X4165);
            goto L_80568FF4;
    }
    // 0x80568FD8: addiu       $at, $zero, 0x4165
    ctx->r1 = ADD32(0, 0X4165);
    // 0x80568FDC: beq         $v0, $at, L_80569004
    if (ctx->r2 == ctx->r1) {
        // 0x80568FE0: addiu       $at, $zero, 0x4171
        ctx->r1 = ADD32(0, 0X4171);
            goto L_80569004;
    }
    // 0x80568FE0: addiu       $at, $zero, 0x4171
    ctx->r1 = ADD32(0, 0X4171);
    // 0x80568FE4: beql        $v0, $at, L_80569014
    if (ctx->r2 == ctx->r1) {
        // 0x80568FE8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80569014;
    }
    goto skip_0;
    // 0x80568FE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80568FEC: b           L_80569020
    // 0x80568FF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
        goto L_80569020;
    // 0x80568FF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
L_80568FF4:
    // 0x80568FF4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80568FF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80568FFC: b           L_80569020
    // 0x80569000: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
        goto L_80569020;
    // 0x80569000: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
L_80569004:
    // 0x80569004: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2200) << 16);
    // 0x80569008: b           L_8056901C
    // 0x8056900C: lwc1        $f0, -0x6850($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2200));
        goto L_8056901C;
    // 0x8056900C: lwc1        $f0, -0x6850($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2200));
    // 0x80569010: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80569014:
    // 0x80569014: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80569018: nop

L_8056901C:
    // 0x8056901C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
L_80569020:
    // 0x80569020: jal         0x80568710
    // 0x80569024: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x80569024: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80569028: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8056902C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80569030: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80569034: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80569038: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8056903C: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80569040: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2204) << 16);
    // 0x80569044: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x80569048: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    // 0x8056904C: lwc1        $f8, -0x684C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2204));
    // 0x80569050: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80569054: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2208) << 16);
    // 0x80569058: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    // 0x8056905C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80569060: lwc1        $f10, -0x6848($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2208));
    // 0x80569064: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80569068: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x8056906C: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x80569070: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80569074: jal         0x80569310
    // 0x80569078: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    func_80569310(rdram, ctx);
        goto after_1;
    // 0x80569078: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    after_1:
    // 0x8056907C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80569080: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80569084: jr          $ra
    // 0x80569088: nop

    return;
    // 0x80569088: nop

;}
RECOMP_FUNC void func_807B5848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B5848: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x807B584C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B5850: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807B5854: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x807B5858: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x807B585C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x807B5860: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807B5864: lw          $s3, 0x14($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X14);
    // 0x807B5868: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B586C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_807B5870:
    // 0x807B5870: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B5874: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5878: jal         0x8005C27C
    // 0x807B587C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x807B587C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x807B5880: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5884: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x807B5888: bnel        $at, $zero, L_807B5870
    if (ctx->r1 != 0) {
        // 0x807B588C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_807B5870;
    }
    goto skip_0;
    // 0x807B588C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x807B5890: lui         $s0, 0x807B
    ctx->r16 = S32(RELOC_HI16(880, 0X2E18) << 16);
    // 0x807B5894: addiu       $s0, $s0, 0x7618
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(880, 0X2E18));
    // 0x807B5898: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807B589C: addiu       $s4, $zero, 0x1000
    ctx->r20 = ADD32(0, 0X1000);
    // 0x807B58A0: sll         $t6, $s1, 1
    ctx->r14 = S32(ctx->r17 << 1);
L_807B58A4:
    // 0x807B58A4: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x807B58A8: lhu         $a1, 0x0($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X0);
    // 0x807B58AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B58B0: sll         $a2, $s1, 3
    ctx->r6 = S32(ctx->r17 << 3);
    // 0x807B58B4: bne         $s4, $a1, L_807B58C4
    if (ctx->r20 != ctx->r5) {
        // 0x807B58B8: nop
    
            goto L_807B58C4;
    }
    // 0x807B58B8: nop

    // 0x807B58BC: b           L_807B58CC
    // 0x807B58C0: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
        goto L_807B58CC;
    // 0x807B58C0: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
L_807B58C4:
    // 0x807B58C4: jal         0x8005C27C
    // 0x807B58C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x807B58C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_807B58CC:
    // 0x807B58CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x807B58D0: slti        $at, $s1, 0x10
    ctx->r1 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x807B58D4: bnel        $at, $zero, L_807B58A4
    if (ctx->r1 != 0) {
        // 0x807B58D8: sll         $t6, $s1, 1
        ctx->r14 = S32(ctx->r17 << 1);
            goto L_807B58A4;
    }
    goto skip_1;
    // 0x807B58D8: sll         $t6, $s1, 1
    ctx->r14 = S32(ctx->r17 << 1);
    skip_1:
    // 0x807B58DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B58E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_807B58E4:
    // 0x807B58E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B58E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B58EC: jal         0x8005C27C
    // 0x807B58F0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x807B58F0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
    // 0x807B58F4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B58F8: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x807B58FC: bnel        $at, $zero, L_807B58E4
    if (ctx->r1 != 0) {
        // 0x807B5900: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_807B58E4;
    }
    goto skip_2;
    // 0x807B5900: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_2:
    // 0x807B5904: jal         0x807B4A74
    // 0x807B5908: nop

    func_807B4A74(rdram, ctx);
        goto after_3;
    // 0x807B5908: nop

    after_3:
    // 0x807B590C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x807B5910: lw          $t8, -0x7474($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7474);
    // 0x807B5914: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x807B5918: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x807B591C: jal         0x807B4B3C
    // 0x807B5920: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    func_807B4B3C(rdram, ctx);
        goto after_4;
    // 0x807B5920: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    after_4:
    // 0x807B5924: addiu       $s2, $sp, 0x44
    ctx->r18 = ADD32(ctx->r29, 0X44);
    // 0x807B5928: addiu       $s0, $zero, 0x50
    ctx->r16 = ADD32(0, 0X50);
L_807B592C:
    // 0x807B592C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B5930: lhu         $a1, 0x2($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X2);
    // 0x807B5934: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5938: jal         0x8005C27C
    // 0x807B593C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_5;
    // 0x807B593C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_5:
    // 0x807B5940: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5944: slti        $at, $s0, 0x78
    ctx->r1 = SIGNED(ctx->r16) < 0X78 ? 1 : 0;
    // 0x807B5948: bne         $at, $zero, L_807B592C
    if (ctx->r1 != 0) {
        // 0x807B594C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_807B592C;
    }
    // 0x807B594C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x807B5950: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B5954: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807B5958: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x807B595C: jal         0x8005C27C
    // 0x807B5960: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_6;
    // 0x807B5960: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_6:
    // 0x807B5964: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B5968: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_807B596C:
    // 0x807B596C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B5970: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5974: jal         0x8005C27C
    // 0x807B5978: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005C27C(rdram, ctx);
        goto after_7;
    // 0x807B5978: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_7:
    // 0x807B597C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5980: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x807B5984: bnel        $at, $zero, L_807B596C
    if (ctx->r1 != 0) {
        // 0x807B5988: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_807B596C;
    }
    goto skip_3;
    // 0x807B5988: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_3:
    // 0x807B598C: lui         $s0, 0x807B
    ctx->r16 = S32(RELOC_HI16(880, 0X2E38) << 16);
    // 0x807B5990: addiu       $s0, $s0, 0x7638
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(880, 0X2E38));
    // 0x807B5994: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807B5998: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
L_807B599C:
    // 0x807B599C: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x807B59A0: lhu         $a1, 0x0($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X0);
    // 0x807B59A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B59A8: sll         $a2, $s1, 3
    ctx->r6 = S32(ctx->r17 << 3);
    // 0x807B59AC: bne         $s4, $a1, L_807B59BC
    if (ctx->r20 != ctx->r5) {
        // 0x807B59B0: nop
    
            goto L_807B59BC;
    }
    // 0x807B59B0: nop

    // 0x807B59B4: b           L_807B59C4
    // 0x807B59B8: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
        goto L_807B59C4;
    // 0x807B59B8: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
L_807B59BC:
    // 0x807B59BC: jal         0x8005C27C
    // 0x807B59C0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005C27C(rdram, ctx);
        goto after_8;
    // 0x807B59C0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_8:
L_807B59C4:
    // 0x807B59C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x807B59C8: slti        $at, $s1, 0x10
    ctx->r1 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x807B59CC: bnel        $at, $zero, L_807B599C
    if (ctx->r1 != 0) {
        // 0x807B59D0: sll         $t9, $s1, 1
        ctx->r25 = S32(ctx->r17 << 1);
            goto L_807B599C;
    }
    goto skip_4;
    // 0x807B59D0: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    skip_4:
    // 0x807B59D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B59D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_807B59DC:
    // 0x807B59DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B59E0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B59E4: jal         0x8005C27C
    // 0x807B59E8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_9;
    // 0x807B59E8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_9:
    // 0x807B59EC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B59F0: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x807B59F4: bnel        $at, $zero, L_807B59DC
    if (ctx->r1 != 0) {
        // 0x807B59F8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_807B59DC;
    }
    goto skip_5;
    // 0x807B59F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_5:
    // 0x807B59FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x807B5A00: jal         0x80069644
    // 0x807B5A04: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80069644(rdram, ctx);
        goto after_10;
    // 0x807B5A04: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_10:
    // 0x807B5A08: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // 0x807B5A0C: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
L_807B5A10:
    // 0x807B5A10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B5A14: lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X0);
    // 0x807B5A18: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5A1C: jal         0x8005C27C
    // 0x807B5A20: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_11;
    // 0x807B5A20: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_11:
    // 0x807B5A24: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5A28: slti        $at, $s0, 0x48
    ctx->r1 = SIGNED(ctx->r16) < 0X48 ? 1 : 0;
    // 0x807B5A2C: bne         $at, $zero, L_807B5A10
    if (ctx->r1 != 0) {
        // 0x807B5A30: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_807B5A10;
    }
    // 0x807B5A30: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x807B5A34: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x807B5A38: lhu         $a1, -0x71A0($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X71A0);
    // 0x807B5A3C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x807B5A40: jal         0x807B4B3C
    // 0x807B5A44: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_807B4B3C(rdram, ctx);
        goto after_12;
    // 0x807B5A44: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_12:
    // 0x807B5A48: addiu       $s2, $sp, 0x44
    ctx->r18 = ADD32(ctx->r29, 0X44);
    // 0x807B5A4C: addiu       $s0, $zero, 0x50
    ctx->r16 = ADD32(0, 0X50);
    // 0x807B5A50: addiu       $s1, $zero, 0x78
    ctx->r17 = ADD32(0, 0X78);
L_807B5A54:
    // 0x807B5A54: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B5A58: lhu         $a1, 0x2($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X2);
    // 0x807B5A5C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5A60: jal         0x8005C27C
    // 0x807B5A64: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_13;
    // 0x807B5A64: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_13:
    // 0x807B5A68: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5A6C: bne         $s0, $s1, L_807B5A54
    if (ctx->r16 != ctx->r17) {
        // 0x807B5A70: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_807B5A54;
    }
    // 0x807B5A70: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x807B5A74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B5A78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807B5A7C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x807B5A80: jal         0x8005C27C
    // 0x807B5A84: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_14;
    // 0x807B5A84: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_14:
    // 0x807B5A88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x807B5A8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B5A90: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x807B5A94: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x807B5A98: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x807B5A9C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x807B5AA0: jr          $ra
    // 0x807B5AA4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x807B5AA4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_804F4C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F4C88: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x804F4C8C: jr          $ra
    // 0x804F4C90: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    return;
    // 0x804F4C90: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_805AE204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE204: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE208: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE20C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE210: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE214: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE218: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE21C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE220: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE224: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE228: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE22C: jr          $ra
    // 0x805AE230: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE230: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805E469C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E469C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805E46A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805E46A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805E46A8: jal         0x805E4460
    // 0x805E46AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_805E4460(rdram, ctx);
        goto after_0;
    // 0x805E46AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x805E46B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805E46B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805E46B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E46BC: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x805E46C0: addiu       $s0, $s0, 0xC4
    ctx->r16 = ADD32(ctx->r16, 0XC4);
    // 0x805E46C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805E46C8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x805E46CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E46D0: bc1f        L_805E46F0
    if (!c1cs) {
        // 0x805E46D4: nop
    
            goto L_805E46F0;
    }
    // 0x805E46D4: nop

    // 0x805E46D8: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x805E46DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805E46E0: jal         0x805E4D78
    // 0x805E46E4: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    func_805E4D78(rdram, ctx);
        goto after_1;
    // 0x805E46E4: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    after_1:
    // 0x805E46E8: b           L_805E46F8
    // 0x805E46EC: nop

        goto L_805E46F8;
    // 0x805E46EC: nop

L_805E46F0:
    // 0x805E46F0: jal         0x805E4378
    // 0x805E46F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_805E4378(rdram, ctx);
        goto after_2;
    // 0x805E46F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_805E46F8:
    // 0x805E46F8: jal         0x805E4674
    // 0x805E46FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_805E4674(rdram, ctx);
        goto after_3;
    // 0x805E46FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x805E4700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805E4704: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805E4708: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805E470C: jr          $ra
    // 0x805E4710: nop

    return;
    // 0x805E4710: nop

;}
RECOMP_FUNC void func_805E4460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4460: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805E4464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E4468: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x805E446C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805E4470: beq         $t6, $zero, L_805E4538
    if (ctx->r14 == 0) {
        // 0x805E4474: nop
    
            goto L_805E4538;
    }
    // 0x805E4474: nop

    // 0x805E4478: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805E447C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x805E4480: jalr        $t9
    // 0x805E4484: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805E4484: nop

    after_0:
    // 0x805E4488: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805E448C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x805E4490: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805E4494: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x805E4498: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x805E449C: lw          $t4, 0x1F4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1F4);
    // 0x805E44A0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x805E44A4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x805E44A8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x805E44AC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x805E44B0: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x805E44B4: lhu         $t6, 0xC($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0XC);
    // 0x805E44B8: andi        $t9, $t6, 0x1
    ctx->r25 = ctx->r14 & 0X1;
    // 0x805E44BC: beql        $t9, $zero, L_805E44F4
    if (ctx->r25 == 0) {
        // 0x805E44C0: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_805E44F4;
    }
    goto skip_0;
    // 0x805E44C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x805E44C4: lh          $v1, 0x144($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X144);
    // 0x805E44C8: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(486, 0XF60) << 16);
    // 0x805E44CC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x805E44D0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x805E44D4: lwc1        $f4, 0x50A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(486, 0XF60));
    // 0x805E44D8: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(486, 0XF84) << 16);
    // 0x805E44DC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x805E44E0: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x805E44E4: lwc1        $f6, 0x50C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(486, 0XF84));
    // 0x805E44E8: b           L_805E4500
    // 0x805E44EC: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
        goto L_805E4500;
    // 0x805E44EC: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x805E44F0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_805E44F4:
    // 0x805E44F4: nop

    // 0x805E44F8: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x805E44FC: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
L_805E4500:
    // 0x805E4500: beq         $v0, $zero, L_805E4530
    if (ctx->r2 == 0) {
        // 0x805E4504: nop
    
            goto L_805E4530;
    }
    // 0x805E4504: nop

    // 0x805E4508: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805E450C: lhu         $v1, 0xC($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XC);
    // 0x805E4510: andi        $t0, $v1, 0x1
    ctx->r8 = ctx->r3 & 0X1;
    // 0x805E4514: beq         $t0, $zero, L_805E452C
    if (ctx->r8 == 0) {
        // 0x805E4518: ori         $t1, $v1, 0x1
        ctx->r9 = ctx->r3 | 0X1;
            goto L_805E452C;
    }
    // 0x805E4518: ori         $t1, $v1, 0x1
    ctx->r9 = ctx->r3 | 0X1;
    // 0x805E451C: andi        $t8, $v1, 0xFFFE
    ctx->r24 = ctx->r3 & 0XFFFE;
    // 0x805E4520: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
    // 0x805E4524: b           L_805E4538
    // 0x805E4528: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_805E4538;
    // 0x805E4528: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_805E452C:
    // 0x805E452C: sh          $t1, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r9;
L_805E4530:
    // 0x805E4530: b           L_805E4538
    // 0x805E4534: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_805E4538;
    // 0x805E4534: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_805E4538:
    // 0x805E4538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805E453C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805E4540: jr          $ra
    // 0x805E4544: nop

    return;
    // 0x805E4544: nop

;}
RECOMP_FUNC void func_80429B68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429B68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80429B6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80429B70: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80429B74: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80429B78: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80429B7C: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(44, 0X258) << 16);
    // 0x80429B80: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80429B84: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80429B88: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80429B8C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80429B90: lw          $t8, -0x62D8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(44, 0X258));
    // 0x80429B94: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80429B98: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80429B9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80429BA0: jal         0x80048490
    // 0x80429BA4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80429BA4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80429BA8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80429BAC: jal         0x80048378
    // 0x80429BB0: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80429BB0: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80429BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80429BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80429BBC: jr          $ra
    // 0x80429BC0: nop

    return;
    // 0x80429BC0: nop

;}
RECOMP_FUNC void func_800575B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800575B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800575B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800575BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800575C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800575C4: jal         0x80047090
    // 0x800575C8: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x800575C8: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x800575CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800575D0: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x800575D4: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x800575D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800575DC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800575E0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800575E4: jal         0x8004613C
    // 0x800575E8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x800575E8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    after_1:
    // 0x800575EC: bne         $v0, $zero, L_800575FC
    if (ctx->r2 != 0) {
        // 0x800575F0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800575FC;
    }
    // 0x800575F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800575F4: b           L_80057630
    // 0x800575F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80057630;
    // 0x800575F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800575FC:
    // 0x800575FC: lhu         $t7, 0x1E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1E);
    // 0x80057600: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x80057604: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80057608: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x8005760C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80057610: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x80057614: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80057618: jal         0x80047F9C
    // 0x8005761C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8005761C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80057620: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80057624: jal         0x8005FDC4
    // 0x80057628: sb          $zero, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = 0;
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x80057628: sb          $zero, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = 0;
    after_3:
    // 0x8005762C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_80057630:
    // 0x80057630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80057638: jr          $ra
    // 0x8005763C: nop

    return;
    // 0x8005763C: nop

;}
RECOMP_FUNC void func_805A5508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A5508: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805A550C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A5510: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A5514: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x805A5518: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A551C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x805A5520: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    // 0x805A5524: andi        $t7, $t6, 0xF00
    ctx->r15 = ctx->r14 & 0XF00;
    // 0x805A5528: beql        $t7, $zero, L_805A5608
    if (ctx->r15 == 0) {
        // 0x805A552C: sh          $zero, 0x144($s0)
        MEM_H(0X144, ctx->r16) = 0;
            goto L_805A5608;
    }
    goto skip_0;
    // 0x805A552C: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    skip_0:
    // 0x805A5530: lw          $v1, 0x14C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14C);
    // 0x805A5534: sltiu       $at, $v1, 0x2
    ctx->r1 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x805A5538: bne         $at, $zero, L_805A5574
    if (ctx->r1 != 0) {
        // 0x805A553C: sll         $t0, $v1, 2
        ctx->r8 = S32(ctx->r3 << 2);
            goto L_805A5574;
    }
    // 0x805A553C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x805A5540: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x805A5544: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A5548: nop

    // 0x805A554C: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x805A5550: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x805A5554: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805A5558: jal         0x80067BBC
    // 0x805A555C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805A555C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x805A5560: addiu       $a0, $zero, 0x271
    ctx->r4 = ADD32(0, 0X271);
    // 0x805A5564: jal         0x80067818
    // 0x805A5568: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805A5568: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805A556C: b           L_805A55EC
    // 0x805A5570: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
        goto L_805A55EC;
    // 0x805A5570: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_805A5574:
    // 0x805A5574: lw          $t8, 0x154($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X154);
    // 0x805A5578: lui         $t1, 0x805A
    ctx->r9 = S32(RELOC_HI16(417, 0X14E0) << 16);
    // 0x805A557C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805A5580: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x805A5584: sw          $t9, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->r25;
    // 0x805A5588: lw          $t1, 0x67A0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(417, 0X14E0));
    // 0x805A558C: sltu        $at, $t1, $t9
    ctx->r1 = ctx->r9 < ctx->r25 ? 1 : 0;
    // 0x805A5590: beql        $at, $zero, L_805A55EC
    if (ctx->r1 == 0) {
        // 0x805A5594: sw          $v1, 0x14C($s0)
        MEM_W(0X14C, ctx->r16) = ctx->r3;
            goto L_805A55EC;
    }
    goto skip_1;
    // 0x805A5594: sw          $v1, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r3;
    skip_1:
    // 0x805A5598: lbu         $t3, 0x158($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X158);
    // 0x805A559C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x805A55A0: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x805A55A4: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x805A55A8: bne         $at, $zero, L_805A55E0
    if (ctx->r1 != 0) {
        // 0x805A55AC: sb          $t4, 0x158($s0)
        MEM_B(0X158, ctx->r16) = ctx->r12;
            goto L_805A55E0;
    }
    // 0x805A55AC: sb          $t4, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r12;
    // 0x805A55B0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x805A55B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A55B8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805A55BC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x805A55C0: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x805A55C4: jal         0x80067BBC
    // 0x805A55C8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x805A55C8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_2:
    // 0x805A55CC: addiu       $a0, $zero, 0x271
    ctx->r4 = ADD32(0, 0X271);
    // 0x805A55D0: jal         0x80067818
    // 0x805A55D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x805A55D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x805A55D8: b           L_805A55E4
    // 0x805A55DC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
        goto L_805A55E4;
    // 0x805A55DC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_805A55E0:
    // 0x805A55E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_805A55E4:
    // 0x805A55E4: sw          $zero, 0x154($s0)
    MEM_W(0X154, ctx->r16) = 0;
    // 0x805A55E8: sw          $v1, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r3;
L_805A55EC:
    // 0x805A55EC: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x805A55F0: lui         $t7, 0x805A
    ctx->r15 = S32(RELOC_HI16(417, 0X14EC) << 16);
    // 0x805A55F4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x805A55F8: lh          $t7, 0x67AC($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(417, 0X14EC));
    // 0x805A55FC: b           L_805A5614
    // 0x805A5600: sh          $t7, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r15;
        goto L_805A5614;
    // 0x805A5600: sh          $t7, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r15;
    // 0x805A5604: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
L_805A5608:
    // 0x805A5608: sb          $zero, 0x158($s0)
    MEM_B(0X158, ctx->r16) = 0;
    // 0x805A560C: sw          $v0, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r2;
    // 0x805A5610: sw          $v0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->r2;
L_805A5614:
    // 0x805A5614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A5618: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A561C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805A5620: jr          $ra
    // 0x805A5624: nop

    return;
    // 0x805A5624: nop

;}
RECOMP_FUNC void func_80051DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051DA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80051DA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051DA8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80051DAC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80051DB0: jal         0x80051CB8
    // 0x80051DB4: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    func_80051CB8(rdram, ctx);
        goto after_0;
    // 0x80051DB4: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    after_0:
    // 0x80051DB8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80051DBC: lw          $t6, -0x79DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X79DC);
    // 0x80051DC0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80051DC4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80051DC8: xori        $t7, $t6, 0x17D8
    ctx->r15 = ctx->r14 ^ 0X17D8;
    // 0x80051DCC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80051DD0: or          $a0, $sp, $zero
    ctx->r4 = ctx->r29 | 0;
    // 0x80051DD4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80051DD8: sw          $t7, 0x5AD0($at)
    MEM_W(0X5AD0, ctx->r1) = ctx->r15;
    // 0x80051DDC: addiu       $a0, $a0, 0x2F
    ctx->r4 = ADD32(ctx->r4, 0X2F);
    // 0x80051DE0: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x80051DE4: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80051DE8: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x80051DEC: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    // 0x80051DF0: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x80051DF4: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80051DF8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80051DFC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80051E00: jal         0x800675D0
    // 0x80051E04: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800675D0(rdram, ctx);
        goto after_1;
    // 0x80051E04: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80051E08: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80051E0C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80051E10: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80051E14: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
    // 0x80051E18: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    // 0x80051E1C: sll         $a0, $a2, 7
    ctx->r4 = S32(ctx->r6 << 7);
    // 0x80051E20: jal         0x80064DD0
    // 0x80051E24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80064DD0(rdram, ctx);
        goto after_2;
    // 0x80051E24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x80051E28: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80051E2C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80051E30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80051E34: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    // 0x80051E38: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80051E3C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80051E40: jal         0x800675D0
    // 0x80051E44: lw          $a1, 0x24($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X24);
    func_800675D0(rdram, ctx);
        goto after_3;
    // 0x80051E44: lw          $a1, 0x24($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X24);
    after_3:
    // 0x80051E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051E4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80051E50: jr          $ra
    // 0x80051E54: nop

    return;
    // 0x80051E54: nop

;}
RECOMP_FUNC void func_80445B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445B54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445B58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445B5C: jal         0x800679B0
    // 0x80445B60: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_800679B0(rdram, ctx);
        goto after_0;
    // 0x80445B60: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_0:
    // 0x80445B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445B68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445B6C: jr          $ra
    // 0x80445B70: nop

    return;
    // 0x80445B70: nop

;}
RECOMP_FUNC void func_804CFA8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CFA8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804CFA90: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CFA94: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x804CFA98: jr          $ra
    // 0x804CFA9C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x804CFA9C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_800217E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800217E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800217E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800217E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800217EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800217F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800217F4: jal         0x800213EC
    // 0x800217F8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_800213EC(rdram, ctx);
        goto after_0;
    // 0x800217F8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x800217FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80021800: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80021804: jal         0x800216C4
    // 0x80021808: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800216C4(rdram, ctx);
        goto after_1;
    // 0x80021808: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8002180C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021814: jr          $ra
    // 0x80021818: nop

    return;
    // 0x80021818: nop

;}
RECOMP_FUNC void func_807AABF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AABF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AABF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AABFC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807AAC00: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807AAC04: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AAC08: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807AAC0C: jal         0x807A9D84
    // 0x807AAC10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A9D84(rdram, ctx);
        goto after_0;
    // 0x807AAC10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x807AAC14: lwc1        $f4, 0x50($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X50);
    // 0x807AAC18: lwc1        $f6, 0xC0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x807AAC1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AAC20: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807AAC24: swc1        $f8, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f8.u32l;
    // 0x807AAC28: jal         0x807AA878
    // 0x807AAC2C: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    func_807AA878(rdram, ctx);
        goto after_1;
    // 0x807AAC2C: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    after_1:
    // 0x807AAC30: lw          $v0, 0xD8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD8);
    // 0x807AAC34: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C10) << 16);
    // 0x807AAC38: beq         $v0, $zero, L_807AAC4C
    if (ctx->r2 == 0) {
        // 0x807AAC3C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807AAC4C;
    }
    // 0x807AAC3C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807AAC40: sw          $t6, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->r14;
    // 0x807AAC44: b           L_807AACC8
    // 0x807AAC48: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
        goto L_807AACC8;
    // 0x807AAC48: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
L_807AAC4C:
    // 0x807AAC4C: lwc1        $f14, -0x47B0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C10));
    // 0x807AAC50: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C14) << 16);
    // 0x807AAC54: lwc1        $f16, -0x47AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C14));
    // 0x807AAC58: lwc1        $f10, 0xCC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x807AAC5C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x807AAC60: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x807AAC64: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x807AAC68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807AAC6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AAC70: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x807AAC74: swc1        $f18, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f18.u32l;
    // 0x807AAC78: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x807AAC7C: add.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x807AAC80: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x807AAC84: nop

    // 0x807AAC88: bc1tl       L_807AACB4
    if (c1cs) {
        // 0x807AAC8C: swc1        $f12, 0xCC($s0)
        MEM_W(0XCC, ctx->r16) = ctx->f12.u32l;
            goto L_807AACB4;
    }
    goto skip_0;
    // 0x807AAC8C: swc1        $f12, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f12.u32l;
    skip_0:
    // 0x807AAC90: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x807AAC94: nop

    // 0x807AAC98: bc1tl       L_807AACCC
    if (c1cs) {
        // 0x807AAC9C: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_807AACCC;
    }
    goto skip_1;
    // 0x807AAC9C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    skip_1:
    // 0x807AACA0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x807AACA4: nop

    // 0x807AACA8: bc1tl       L_807AACCC
    if (c1cs) {
        // 0x807AACAC: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_807AACCC;
    }
    goto skip_2;
    // 0x807AACAC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    skip_2:
    // 0x807AACB0: swc1        $f12, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f12.u32l;
L_807AACB4:
    // 0x807AACB4: sh          $zero, 0xDC($s0)
    MEM_H(0XDC, ctx->r16) = 0;
    // 0x807AACB8: sw          $t7, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->r15;
    // 0x807AACBC: jal         0x807AB278
    // 0x807AACC0: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    func_807AB278(rdram, ctx);
        goto after_2;
    // 0x807AACC0: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    after_2:
    // 0x807AACC4: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
L_807AACC8:
    // 0x807AACC8: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
L_807AACCC:
    // 0x807AACCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807AACD0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x807AACD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807AACD8: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x807AACDC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x807AACE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807AACE4: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x807AACE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807AACEC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x807AACF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807AACF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807AACF8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807AACFC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x807AAD00: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    // 0x807AAD04: jal         0x807AA96C
    // 0x807AAD08: swc1        $f6, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f6.u32l;
    func_807AA96C(rdram, ctx);
        goto after_3;
    // 0x807AAD08: swc1        $f6, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f6.u32l;
    after_3:
    // 0x807AAD0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807AAD10: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807AAD14: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807AAD18: jr          $ra
    // 0x807AAD1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x807AAD1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8051EC54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051EC54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8051EC58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051EC5C: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(300, 0X5B4) << 16);
    // 0x8051EC60: lwc1        $f0, -0x104C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(300, 0X5B4));
    // 0x8051EC64: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x8051EC68: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8051EC6C: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(300, 0X5B8) << 16);
    // 0x8051EC70: swc1        $f0, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f0.u32l;
    // 0x8051EC74: lw          $t7, 0x188($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X188);
    // 0x8051EC78: swc1        $f0, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->f0.u32l;
    // 0x8051EC7C: lw          $t8, 0x18C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18C);
    // 0x8051EC80: swc1        $f0, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->f0.u32l;
    // 0x8051EC84: lw          $t9, 0x18C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X18C);
    // 0x8051EC88: swc1        $f0, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f0.u32l;
    // 0x8051EC8C: lw          $t0, 0x190($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X190);
    // 0x8051EC90: swc1        $f0, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->f0.u32l;
    // 0x8051EC94: lw          $t1, 0x190($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X190);
    // 0x8051EC98: swc1        $f0, 0x70($t1)
    MEM_W(0X70, ctx->r9) = ctx->f0.u32l;
    // 0x8051EC9C: lw          $t2, 0x194($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X194);
    // 0x8051ECA0: swc1        $f0, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->f0.u32l;
    // 0x8051ECA4: lw          $t3, 0x194($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X194);
    // 0x8051ECA8: swc1        $f0, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f0.u32l;
    // 0x8051ECAC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8051ECB0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8051ECB4: lwc1        $f2, -0x1048($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(300, 0X5B8));
    // 0x8051ECB8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8051ECBC: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8051ECC0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8051ECC4: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8051ECC8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8051ECCC: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8051ECD0: andi        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 & 0X3;
    // 0x8051ECD4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8051ECD8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8051ECDC: nop

    // 0x8051ECE0: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8051ECE4: andi        $a2, $a2, 0x3
    ctx->r6 = ctx->r6 & 0X3;
    // 0x8051ECE8: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8051ECEC: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x8051ECF0: lw          $t7, 0x188($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X188);
    // 0x8051ECF4: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x8051ECF8: swc1        $f2, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f2.u32l;
    // 0x8051ECFC: lw          $t8, 0x188($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X188);
    // 0x8051ED00: beq         $a2, $a1, L_8051ED18
    if (ctx->r6 == ctx->r5) {
        // 0x8051ED04: swc1        $f2, 0x70($t8)
        MEM_W(0X70, ctx->r24) = ctx->f2.u32l;
            goto L_8051ED18;
    }
    // 0x8051ED04: swc1        $f2, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f2.u32l;
    // 0x8051ED08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8051ED0C: jal         0x80067818
    // 0x8051ED10: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x8051ED10: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8051ED14: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_8051ED18:
    // 0x8051ED18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051ED1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8051ED20: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8051ED24: jr          $ra
    // 0x8051ED28: nop

    return;
    // 0x8051ED28: nop

;}
RECOMP_FUNC void func_804448D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804448D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804448DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804448E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804448E4: jal         0x80047090
    // 0x804448E8: addiu       $a0, $zero, 0x450C
    ctx->r4 = ADD32(0, 0X450C);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804448E8: addiu       $a0, $zero, 0x450C
    ctx->r4 = ADD32(0, 0X450C);
    after_0:
    // 0x804448EC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804448F0: beq         $v0, $at, L_8044492C
    if (ctx->r2 == ctx->r1) {
        // 0x804448F4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8044492C;
    }
    // 0x804448F4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804448F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804448FC: lui         $at, 0x450C
    ctx->r1 = S32(0X450C << 16);
    // 0x80444900: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80444904: lui         $a3, 0x460C
    ctx->r7 = S32(0X460C << 16);
    // 0x80444908: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8044490C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80444910: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x80444914: jal         0x8004613C
    // 0x80444918: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80444918: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x8044491C: beq         $v0, $zero, L_8044492C
    if (ctx->r2 == 0) {
        // 0x80444920: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8044492C;
    }
    // 0x80444920: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80444924: jal         0x80047F9C
    // 0x80444928: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80444928: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8044492C:
    // 0x8044492C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80444930: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80444934: jr          $ra
    // 0x80444938: nop

    return;
    // 0x80444938: nop

;}
RECOMP_FUNC void func_8003D444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D444: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003D448: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003D44C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003D450: jal         0x8004700C
    // 0x8003D454: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003D454: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8003D458: lw          $a2, 0x1F4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1F4);
    // 0x8003D45C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003D460: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8003D464: lbu         $a0, 0x159($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X159);
    // 0x8003D468: bnel        $a0, $at, L_8003D49C
    if (ctx->r4 != ctx->r1) {
        // 0x8003D46C: lh          $t6, 0x184($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X184);
            goto L_8003D49C;
    }
    goto skip_0;
    // 0x8003D46C: lh          $t6, 0x184($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X184);
    skip_0:
    // 0x8003D470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D474: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8003D478: jal         0x8003C7C4
    // 0x8003D47C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8003C7C4(rdram, ctx);
        goto after_1;
    // 0x8003D47C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x8003D480: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8003D484: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003D488: jal         0x8003D254
    // 0x8003D48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003D254(rdram, ctx);
        goto after_2;
    // 0x8003D48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003D490: b           L_8003D4C8
    // 0x8003D494: nop

        goto L_8003D4C8;
    // 0x8003D494: nop

    // 0x8003D498: lh          $t6, 0x184($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X184);
L_8003D49C:
    // 0x8003D49C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003D4A0: bne         $t6, $zero, L_8003D4B0
    if (ctx->r14 != 0) {
        // 0x8003D4A4: nop
    
            goto L_8003D4B0;
    }
    // 0x8003D4A4: nop

    // 0x8003D4A8: bne         $a0, $at, L_8003D4C0
    if (ctx->r4 != ctx->r1) {
        // 0x8003D4AC: nop
    
            goto L_8003D4C0;
    }
    // 0x8003D4AC: nop

L_8003D4B0:
    // 0x8003D4B0: jal         0x8003D33C
    // 0x8003D4B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003D33C(rdram, ctx);
        goto after_3;
    // 0x8003D4B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8003D4B8: b           L_8003D4C8
    // 0x8003D4BC: nop

        goto L_8003D4C8;
    // 0x8003D4BC: nop

L_8003D4C0:
    // 0x8003D4C0: jal         0x8003D254
    // 0x8003D4C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003D254(rdram, ctx);
        goto after_4;
    // 0x8003D4C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8003D4C8:
    // 0x8003D4C8: jal         0x8003D090
    // 0x8003D4CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003D090(rdram, ctx);
        goto after_5;
    // 0x8003D4CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8003D4D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D4D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003D4D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003D4DC: jr          $ra
    // 0x8003D4E0: nop

    return;
    // 0x8003D4E0: nop

;}
RECOMP_FUNC void func_804C57AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C57AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C57B0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x804C57B4: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x804C57B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C57BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C57C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C57C4: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(212, 0X97C) << 16);
    // 0x804C57C8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804C57CC: sb          $a2, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r6;
    // 0x804C57D0: lw          $t8, 0x58BC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(212, 0X97C));
    // 0x804C57D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804C57D8: jal         0x804C5320
    // 0x804C57DC: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    func_804C5320(rdram, ctx);
        goto after_0;
    // 0x804C57DC: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    after_0:
    // 0x804C57E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C57E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C57E8: jr          $ra
    // 0x804C57EC: nop

    return;
    // 0x804C57EC: nop

;}
RECOMP_FUNC void func_800365A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800365A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800365A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800365AC: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800365B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800365B4: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800365B8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800365BC: lw          $t7, 0x180($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X180);
    // 0x800365C0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800365C4: lwc1        $f4, 0x50($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X50);
    // 0x800365C8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800365CC: nop

    // 0x800365D0: bc1fl       L_800365E0
    if (!c1cs) {
        // 0x800365D4: sll         $t9, $t8, 2
        ctx->r25 = S32(ctx->r24 << 2);
            goto L_800365E0;
    }
    goto skip_0;
    // 0x800365D4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    skip_0:
    // 0x800365D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800365DC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
L_800365E0:
    // 0x800365E0: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x800365E4: lw          $a1, -0x151C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X151C);
    // 0x800365E8: jal         0x8001D7CC
    // 0x800365EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8001D7CC(rdram, ctx);
        goto after_0;
    // 0x800365EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800365F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800365F4: jal         0x8001D808
    // 0x800365F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8001D808(rdram, ctx);
        goto after_1;
    // 0x800365F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800365FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80036600: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x80036604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036608: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003660C: jr          $ra
    // 0x80036610: nop

    return;
    // 0x80036610: nop

;}
RECOMP_FUNC void func_80437268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043726C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80437270: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80437274: lwc1        $f2, 0xC4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x80437278: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8043727C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80437280: nop

    // 0x80437284: bc1fl       L_804372E0
    if (!c1cs) {
        // 0x80437288: c.le.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
            goto L_804372E0;
    }
    goto skip_0;
    // 0x80437288: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    skip_0:
    // 0x8043728C: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x80437290: nop

    // 0x80437294: bc1fl       L_804372B8
    if (!c1cs) {
        // 0x80437298: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_804372B8;
    }
    goto skip_1;
    // 0x80437298: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_1:
    // 0x8043729C: jal         0x80437160
    // 0x804372A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80437160(rdram, ctx);
        goto after_0;
    // 0x804372A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x804372A4: jal         0x80437178
    // 0x804372A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80437178(rdram, ctx);
        goto after_1;
    // 0x804372A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x804372AC: b           L_80437308
    // 0x804372B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80437308;
    // 0x804372B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804372B4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_804372B8:
    // 0x804372B8: nop

    // 0x804372BC: bc1fl       L_80437308
    if (!c1cs) {
        // 0x804372C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80437308;
    }
    goto skip_2;
    // 0x804372C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x804372C4: jal         0x80437160
    // 0x804372C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80437160(rdram, ctx);
        goto after_2;
    // 0x804372C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x804372CC: jal         0x80437178
    // 0x804372D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80437178(rdram, ctx);
        goto after_3;
    // 0x804372D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x804372D4: b           L_80437308
    // 0x804372D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80437308;
    // 0x804372D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804372DC: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
L_804372E0:
    // 0x804372E0: nop

    // 0x804372E4: bc1fl       L_80437308
    if (!c1cs) {
        // 0x804372E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80437308;
    }
    goto skip_3;
    // 0x804372E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x804372EC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804372F0: nop

    // 0x804372F4: bc1fl       L_80437308
    if (!c1cs) {
        // 0x804372F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80437308;
    }
    goto skip_4;
    // 0x804372F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x804372FC: jal         0x80437130
    // 0x80437300: nop

    func_80437130(rdram, ctx);
        goto after_4;
    // 0x80437300: nop

    after_4:
    // 0x80437304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80437308:
    // 0x80437308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043730C: jr          $ra
    // 0x80437310: nop

    return;
    // 0x80437310: nop

;}
RECOMP_FUNC void func_804D6378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D6378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D637C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D6380: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x804D6384: addiu       $at, $zero, 0x4008
    ctx->r1 = ADD32(0, 0X4008);
    // 0x804D6388: beq         $v0, $at, L_804D63A0
    if (ctx->r2 == ctx->r1) {
        // 0x804D638C: addiu       $at, $zero, 0x400F
        ctx->r1 = ADD32(0, 0X400F);
            goto L_804D63A0;
    }
    // 0x804D638C: addiu       $at, $zero, 0x400F
    ctx->r1 = ADD32(0, 0X400F);
    // 0x804D6390: beq         $v0, $at, L_804D63B0
    if (ctx->r2 == ctx->r1) {
        // 0x804D6394: nop
    
            goto L_804D63B0;
    }
    // 0x804D6394: nop

    // 0x804D6398: b           L_804D63BC
    // 0x804D639C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804D63BC;
    // 0x804D639C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804D63A0:
    // 0x804D63A0: jal         0x804D63C8
    // 0x804D63A4: nop

    func_804D63C8(rdram, ctx);
        goto after_0;
    // 0x804D63A4: nop

    after_0:
    // 0x804D63A8: b           L_804D63BC
    // 0x804D63AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804D63BC;
    // 0x804D63AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804D63B0:
    // 0x804D63B0: jal         0x804D641C
    // 0x804D63B4: nop

    func_804D641C(rdram, ctx);
        goto after_1;
    // 0x804D63B4: nop

    after_1:
    // 0x804D63B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804D63BC:
    // 0x804D63BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D63C0: jr          $ra
    // 0x804D63C4: nop

    return;
    // 0x804D63C4: nop

;}
RECOMP_FUNC void func_805A1F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1F94: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x805A1F98: lw          $v0, 0x7F78($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7F78);
    // 0x805A1F9C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x805A1FA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805A1FA4: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x805A1FA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A1FAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A1FB0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A1FB4: mfhi        $t7
    ctx->r15 = hi;
    // 0x805A1FB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A1FBC: bne         $t7, $zero, L_805A1FCC
    if (ctx->r15 != 0) {
        // 0x805A1FC0: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_805A1FCC;
    }
    // 0x805A1FC0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x805A1FC4: jal         0x805A1BFC
    // 0x805A1FC8: nop

    func_805A1BFC(rdram, ctx);
        goto after_0;
    // 0x805A1FC8: nop

    after_0:
L_805A1FCC:
    // 0x805A1FCC: jal         0x805A1848
    // 0x805A1FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A1848(rdram, ctx);
        goto after_1;
    // 0x805A1FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A1FD4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x805A1FD8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805A1FDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805A1FE0: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x805A1FE4: bnel        $t9, $zero, L_805A200C
    if (ctx->r25 != 0) {
        // 0x805A1FE8: lw          $t1, 0x174($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X174);
            goto L_805A200C;
    }
    goto skip_0;
    // 0x805A1FE8: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    skip_0:
    // 0x805A1FEC: jal         0x80048F84
    // 0x805A1FF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x805A1FF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x805A1FF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A1FF8: jal         0x80048F84
    // 0x805A1FFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x805A1FFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x805A2000: b           L_805A203C
    // 0x805A2004: nop

        goto L_805A203C;
    // 0x805A2004: nop

    // 0x805A2008: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
L_805A200C:
    // 0x805A200C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805A2010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A2014: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x805A2018: jal         0x8005FCA8
    // 0x805A201C: sh          $t0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r8;
    func_8005FCA8(rdram, ctx);
        goto after_4;
    // 0x805A201C: sh          $t0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r8;
    after_4:
    // 0x805A2020: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x805A2024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A2028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A202C: lw          $a3, 0x28($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X28);
    // 0x805A2030: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805A2034: jal         0x805A2B28
    // 0x805A2038: sw          $a3, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r7;
    func_805A2B28(rdram, ctx);
        goto after_5;
    // 0x805A2038: sw          $a3, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r7;
    after_5:
L_805A203C:
    // 0x805A203C: jal         0x805A1BA8
    // 0x805A2040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A1BA8(rdram, ctx);
        goto after_6;
    // 0x805A2040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x805A2044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A2048: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A204C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805A2050: jr          $ra
    // 0x805A2054: nop

    return;
    // 0x805A2054: nop

;}
RECOMP_FUNC void func_8046C624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046C624: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8046C628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046C62C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8046C630: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046C634: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8046C638: lwc1        $f0, 0x174($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X174);
    // 0x8046C63C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8046C640: jal         0x80049018
    // 0x8046C644: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x8046C644: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8046C648: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8046C64C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8046C650: bne         $v0, $zero, L_8046C660
    if (ctx->r2 != 0) {
        // 0x8046C654: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_8046C660;
    }
    // 0x8046C654: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8046C658: b           L_8046C664
    // 0x8046C65C: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
        goto L_8046C664;
    // 0x8046C65C: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
L_8046C660:
    // 0x8046C660: sub.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f12.fl;
L_8046C664:
    // 0x8046C664: jal         0x80066DE4
    // 0x8046C668: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8046C668: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8046C66C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8046C670: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8046C674: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(143, 0X159C) << 16);
    // 0x8046C678: lwc1        $f8, -0x2614($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(143, 0X159C));
    // 0x8046C67C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8046C680: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8046C684: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8046C688: addiu       $v0, $v0, 0xC4
    ctx->r2 = ADD32(ctx->r2, 0XC4);
    // 0x8046C68C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8046C690: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8046C694: jal         0x80066E88
    // 0x8046C698: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8046C698: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x8046C69C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8046C6A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8046C6A4: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(143, 0X15A0) << 16);
    // 0x8046C6A8: lwc1        $f4, -0x2610($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(143, 0X15A0));
    // 0x8046C6AC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8046C6B0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8046C6B4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8046C6B8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8046C6BC: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8046C6C0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8046C6C4: bnel        $t7, $zero, L_8046C6E4
    if (ctx->r15 != 0) {
        // 0x8046C6C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8046C6E4;
    }
    goto skip_0;
    // 0x8046C6C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8046C6CC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8046C6D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8046C6D4: nop

    // 0x8046C6D8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8046C6DC: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8046C6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046C6E4:
    // 0x8046C6E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8046C6E8: jr          $ra
    // 0x8046C6EC: nop

    return;
    // 0x8046C6EC: nop

;}
RECOMP_FUNC void func_806D386C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D386C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806D3870: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806D3874: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806D3878: jal         0x806D373C
    // 0x806D387C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806D373C(rdram, ctx);
        goto after_0;
    // 0x806D387C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806D3880: bnel        $v0, $zero, L_806D3934
    if (ctx->r2 != 0) {
        // 0x806D3884: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_806D3934;
    }
    goto skip_0;
    // 0x806D3884: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x806D3888: jal         0x806D351C
    // 0x806D388C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D351C(rdram, ctx);
        goto after_1;
    // 0x806D388C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806D3890: beq         $v0, $zero, L_806D38F4
    if (ctx->r2 == 0) {
        // 0x806D3894: addiu       $t6, $s0, 0xC4
        ctx->r14 = ADD32(ctx->r16, 0XC4);
            goto L_806D38F4;
    }
    // 0x806D3894: addiu       $t6, $s0, 0xC4
    ctx->r14 = ADD32(ctx->r16, 0XC4);
    // 0x806D3898: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x806D389C: lw          $t8, 0x68($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X68);
    // 0x806D38A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806D38A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D38A8: bne         $t8, $at, L_806D38D4
    if (ctx->r24 != ctx->r1) {
        // 0x806D38AC: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_806D38D4;
    }
    // 0x806D38AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D38B0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806D38B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x806D38B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D38BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D38C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806D38C4: jal         0x806D414C
    // 0x806D38C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806D414C(rdram, ctx);
        goto after_2;
    // 0x806D38C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x806D38CC: b           L_806D38EC
    // 0x806D38D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_806D38EC;
    // 0x806D38D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_806D38D4:
    // 0x806D38D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806D38D8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x806D38DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806D38E0: jal         0x806D414C
    // 0x806D38E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806D414C(rdram, ctx);
        goto after_3;
    // 0x806D38E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x806D38E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_806D38EC:
    // 0x806D38EC: jal         0x806D30C4
    // 0x806D38F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806D30C4(rdram, ctx);
        goto after_4;
    // 0x806D38F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_806D38F4:
    // 0x806D38F4: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806D38F8: jal         0x806D30C4
    // 0x806D38FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806D30C4(rdram, ctx);
        goto after_5;
    // 0x806D38FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x806D3900: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x806D3904: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x806D3908: bnel        $t1, $zero, L_806D3934
    if (ctx->r9 != 0) {
        // 0x806D390C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_806D3934;
    }
    goto skip_1;
    // 0x806D390C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x806D3910: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x806D3914: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806D3918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D391C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x806D3920: bnel        $t3, $at, L_806D3934
    if (ctx->r11 != ctx->r1) {
        // 0x806D3924: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_806D3934;
    }
    goto skip_2;
    // 0x806D3924: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x806D3928: jal         0x806D357C
    // 0x806D392C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    func_806D357C(rdram, ctx);
        goto after_6;
    // 0x806D392C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_6:
    // 0x806D3930: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806D3934:
    // 0x806D3934: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806D3938: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806D393C: jr          $ra
    // 0x806D3940: nop

    return;
    // 0x806D3940: nop

;}
RECOMP_FUNC void func_80710F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80710F70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80710F74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80710F78: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80710F7C: addiu       $at, $zero, 0x4620
    ctx->r1 = ADD32(0, 0X4620);
    // 0x80710F80: lui         $t6, 0x8071
    ctx->r14 = S32(RELOC_HI16(727, 0XB80) << 16);
    // 0x80710F84: beq         $v0, $at, L_80710F9C
    if (ctx->r2 == ctx->r1) {
        // 0x80710F88: addiu       $at, $zero, 0x4627
        ctx->r1 = ADD32(0, 0X4627);
            goto L_80710F9C;
    }
    // 0x80710F88: addiu       $at, $zero, 0x4627
    ctx->r1 = ADD32(0, 0X4627);
    // 0x80710F8C: beq         $v0, $at, L_80710FEC
    if (ctx->r2 == ctx->r1) {
        // 0x80710F90: lui         $t8, 0x8071
        ctx->r24 = S32(RELOC_HI16(727, 0XB84) << 16);
            goto L_80710FEC;
    }
    // 0x80710F90: lui         $t8, 0x8071
    ctx->r24 = S32(RELOC_HI16(727, 0XB84) << 16);
    // 0x80710F94: b           L_80711024
    // 0x80710F98: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(727, 0XAEC) << 16);
        goto L_80711024;
    // 0x80710F98: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(727, 0XAEC) << 16);
L_80710F9C:
    // 0x80710F9C: lw          $t6, 0x1AF0($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(727, 0XB80));
    // 0x80710FA0: lui         $a0, 0x8071
    ctx->r4 = S32(RELOC_HI16(727, 0X1A90) << 16);
    // 0x80710FA4: addiu       $a0, $a0, 0x2A00
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(727, 0X1A90));
    // 0x80710FA8: bne         $t6, $zero, L_80710FE0
    if (ctx->r14 != 0) {
        // 0x80710FAC: lui         $a1, 0x8071
        ctx->r5 = S32(RELOC_HI16(727, 0X1AB0) << 16);
            goto L_80710FE0;
    }
    // 0x80710FAC: lui         $a1, 0x8071
    ctx->r5 = S32(RELOC_HI16(727, 0X1AB0) << 16);
    // 0x80710FB0: addiu       $a1, $a1, 0x2A20
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(727, 0X1AB0));
    // 0x80710FB4: jal         0x8004667C
    // 0x80710FB8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x80710FB8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80710FBC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80710FC0: lui         $a2, 0x8071
    ctx->r6 = S32(RELOC_HI16(727, 0XC8) << 16);
    // 0x80710FC4: addiu       $a2, $a2, 0x1038
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(727, 0XC8));
    // 0x80710FC8: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x80710FCC: jal         0x80057B28
    // 0x80710FD0: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x80710FD0: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_1:
    // 0x80710FD4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80710FD8: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(727, 0XB80) << 16);
    // 0x80710FDC: sw          $t7, 0x1AF0($at)
    MEM_W((int16_t)RELOC_LO16(727, 0XB80), ctx->r1) = ctx->r15;
L_80710FE0:
    // 0x80710FE0: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(727, 0XAEC) << 16);
    // 0x80710FE4: b           L_80711028
    // 0x80710FE8: addiu       $v0, $v0, 0x1A5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(727, 0XAEC));
        goto L_80711028;
    // 0x80710FE8: addiu       $v0, $v0, 0x1A5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(727, 0XAEC));
L_80710FEC:
    // 0x80710FEC: lw          $t8, 0x1AF4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(727, 0XB84));
    // 0x80710FF0: lui         $a0, 0x8071
    ctx->r4 = S32(RELOC_HI16(727, 0X1AA0) << 16);
    // 0x80710FF4: addiu       $a0, $a0, 0x2A10
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(727, 0X1AA0));
    // 0x80710FF8: bne         $t8, $zero, L_80711018
    if (ctx->r24 != 0) {
        // 0x80710FFC: lui         $a1, 0x8071
        ctx->r5 = S32(RELOC_HI16(727, 0X1FB0) << 16);
            goto L_80711018;
    }
    // 0x80710FFC: lui         $a1, 0x8071
    ctx->r5 = S32(RELOC_HI16(727, 0X1FB0) << 16);
    // 0x80711000: addiu       $a1, $a1, 0x2F20
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(727, 0X1FB0));
    // 0x80711004: jal         0x8004667C
    // 0x80711008: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_8004667C(rdram, ctx);
        goto after_2;
    // 0x80711008: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_2:
    // 0x8071100C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80711010: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(727, 0XB84) << 16);
    // 0x80711014: sw          $t9, 0x1AF4($at)
    MEM_W((int16_t)RELOC_LO16(727, 0XB84), ctx->r1) = ctx->r25;
L_80711018:
    // 0x80711018: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(727, 0X720) << 16);
    // 0x8071101C: b           L_80711028
    // 0x80711020: addiu       $v0, $v0, 0x1690
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(727, 0X720));
        goto L_80711028;
    // 0x80711020: addiu       $v0, $v0, 0x1690
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(727, 0X720));
L_80711024:
    // 0x80711024: addiu       $v0, $v0, 0x1A5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(727, 0XAEC));
L_80711028:
    // 0x80711028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8071102C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80711030: jr          $ra
    // 0x80711034: nop

    return;
    // 0x80711034: nop

;}
RECOMP_FUNC void func_807103B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807103B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807103B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807103B8: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x807103BC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807103C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x807103C4: lbu         $t6, 0x34($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X34);
    // 0x807103C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807103CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807103D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807103D4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x807103D8: lw          $t9, 0x38($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X38);
    // 0x807103DC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x807103E0: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x807103E4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x807103E8: jal         0x8070FCFC
    // 0x807103EC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8070FCFC(rdram, ctx);
        goto after_0;
    // 0x807103EC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x807103F0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x807103F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807103F8: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x807103FC: jal         0x8070FDDC
    // 0x80710400: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, 0X120);
    func_8070FDDC(rdram, ctx);
        goto after_1;
    // 0x80710400: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, 0X120);
    after_1:
    // 0x80710404: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80710408: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8071040C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80710410: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80710414: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80710418: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8071041C: lw          $t2, 0x1E0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X1E0);
    // 0x80710420: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80710424: slti        $at, $t3, 0x1E
    ctx->r1 = SIGNED(ctx->r11) < 0X1E ? 1 : 0;
    // 0x80710428: bne         $at, $zero, L_80710438
    if (ctx->r1 != 0) {
        // 0x8071042C: sw          $t3, 0x1E0($a3)
        MEM_W(0X1E0, ctx->r7) = ctx->r11;
            goto L_80710438;
    }
    // 0x8071042C: sw          $t3, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r11;
    // 0x80710430: jal         0x80710C50
    // 0x80710434: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80710C50(rdram, ctx);
        goto after_2;
    // 0x80710434: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
L_80710438:
    // 0x80710438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8071043C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80710440: jr          $ra
    // 0x80710444: nop

    return;
    // 0x80710444: nop

;}
RECOMP_FUNC void func_80780C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80780C18: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80780C1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80780C20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80780C24: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80780C28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80780C2C: jal         0x80780260
    // 0x80780C30: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80780260(rdram, ctx);
        goto after_0;
    // 0x80780C30: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80780C34: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(784, 0X6664) << 16);
    // 0x80780C38: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80780C3C: lwc1        $f4, 0x6854($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(784, 0X6664));
    // 0x80780C40: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80780C44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80780C48: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80780C4C: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x80780C50: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x80780C54: jal         0x80048F84
    // 0x80780C58: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80780C58: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x80780C5C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80780C60: jal         0x80048F84
    // 0x80780C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x80780C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80780C68: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x80780C6C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80780C70: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80780C74: bne         $at, $zero, L_80780C88
    if (ctx->r1 != 0) {
        // 0x80780C78: sw          $t7, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r15;
            goto L_80780C88;
    }
    // 0x80780C78: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x80780C7C: jal         0x80780A24
    // 0x80780C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80780A24(rdram, ctx);
        goto after_3;
    // 0x80780C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80780C84: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_80780C88:
    // 0x80780C88: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80780C8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80780C90: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80780C94: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(784, 0X6668) << 16);
    // 0x80780C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80780C9C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80780CA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80780CA4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80780CA8: bc1fl       L_80780CDC
    if (!c1cs) {
        // 0x80780CAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80780CDC;
    }
    goto skip_0;
    // 0x80780CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80780CB0: lwc1        $f0, 0x6858($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(784, 0X6668));
    // 0x80780CB4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80780CB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80780CBC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80780CC0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80780CC4: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x80780CC8: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x80780CCC: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x80780CD0: jal         0x807813F0
    // 0x80780CD4: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    func_807813F0(rdram, ctx);
        goto after_4;
    // 0x80780CD4: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    after_4:
    // 0x80780CD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80780CDC:
    // 0x80780CDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80780CE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80780CE4: jr          $ra
    // 0x80780CE8: nop

    return;
    // 0x80780CE8: nop

;}
RECOMP_FUNC void func_807AF8EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF8EC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x807AF8F0: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(868, 0X1E8) << 16);
    // 0x807AF8F4: addiu       $t6, $t6, -0x828
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(868, 0X1E8));
    // 0x807AF8F8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x807AF8FC: jr          $ra
    // 0x807AF900: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x807AF900: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_807AB3EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AB3EC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807AB3F0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807AB3F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807AB3F8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807AB3FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807AB400: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807AB404: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x807AB408: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807AB40C: lui         $t1, 0x807B
    ctx->r9 = S32(RELOC_HI16(853, 0X1BF0) << 16);
    // 0x807AB410: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807AB414: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807AB418: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807AB41C: lw          $t1, -0x47D0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(853, 0X1BF0));
    // 0x807AB420: jr          $ra
    // 0x807AB424: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807AB424: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8079DB4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079DB4C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8079DB50: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8079DB54: lui         $s0, 0x807A
    ctx->r16 = S32(RELOC_HI16(835, 0X18A8) << 16);
    // 0x8079DB58: addiu       $s0, $s0, -0xC68
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(835, 0X18A8));
    // 0x8079DB5C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8079DB60: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1950) << 16);
    // 0x8079DB64: lwc1        $f22, -0xBC0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1950));
    // 0x8079DB68: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8079DB6C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8079DB70: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1954) << 16);
    // 0x8079DB74: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8079DB78: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8079DB7C: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x8079DB80: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x8079DB84: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8079DB88: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8079DB8C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8079DB90: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8079DB94: lwc1        $f24, -0xBBC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1954));
    // 0x8079DB98: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079DB9C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8079DBA0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8079DBA4: lui         $a2, 0x42E1
    ctx->r6 = S32(0X42E1 << 16);
    // 0x8079DBA8: ori         $a2, $a2, 0x9810
    ctx->r6 = ctx->r6 | 0X9810;
    // 0x8079DBAC: addiu       $a0, $zero, 0x40F1
    ctx->r4 = ADD32(0, 0X40F1);
    // 0x8079DBB0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8079DBB4: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    // 0x8079DBB8: jal         0x8005CEBC
    // 0x8079DBBC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_0;
    // 0x8079DBBC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_0:
    // 0x8079DBC0: sw          $v0, 0xEC($s5)
    MEM_W(0XEC, ctx->r21) = ctx->r2;
    // 0x8079DBC4: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8079DBC8: lui         $a2, 0x42E1
    ctx->r6 = S32(0X42E1 << 16);
    // 0x8079DBCC: ori         $a2, $a2, 0x9810
    ctx->r6 = ctx->r6 | 0X9810;
    // 0x8079DBD0: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8079DBD4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8079DBD8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8079DBDC: addiu       $a0, $zero, 0x40F2
    ctx->r4 = ADD32(0, 0X40F2);
    // 0x8079DBE0: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8079DBE4: jal         0x8005CEBC
    // 0x8079DBE8: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    func_8005CEBC(rdram, ctx);
        goto after_1;
    // 0x8079DBE8: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    after_1:
    // 0x8079DBEC: sw          $v0, 0xF0($s5)
    MEM_W(0XF0, ctx->r21) = ctx->r2;
    // 0x8079DBF0: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8079DBF4: lui         $a2, 0x42E1
    ctx->r6 = S32(0X42E1 << 16);
    // 0x8079DBF8: ori         $a2, $a2, 0x9810
    ctx->r6 = ctx->r6 | 0X9810;
    // 0x8079DBFC: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x8079DC00: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8079DC04: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8079DC08: addiu       $a0, $zero, 0x4021
    ctx->r4 = ADD32(0, 0X4021);
    // 0x8079DC0C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8079DC10: jal         0x8005CEBC
    // 0x8079DC14: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    func_8005CEBC(rdram, ctx);
        goto after_2;
    // 0x8079DC14: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    after_2:
    // 0x8079DC18: sw          $v0, 0xF4($s5)
    MEM_W(0XF4, ctx->r21) = ctx->r2;
    // 0x8079DC1C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8079DC20: lui         $a2, 0x42E1
    ctx->r6 = S32(0X42E1 << 16);
    // 0x8079DC24: ori         $a2, $a2, 0x9810
    ctx->r6 = ctx->r6 | 0X9810;
    // 0x8079DC28: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8079DC2C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8079DC30: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8079DC34: addiu       $a0, $zero, 0x4022
    ctx->r4 = ADD32(0, 0X4022);
    // 0x8079DC38: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8079DC3C: jal         0x8005CEBC
    // 0x8079DC40: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    func_8005CEBC(rdram, ctx);
        goto after_3;
    // 0x8079DC40: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    after_3:
    // 0x8079DC44: sw          $v0, 0xF8($s5)
    MEM_W(0XF8, ctx->r21) = ctx->r2;
    // 0x8079DC48: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8079DC4C: lui         $a2, 0x42E1
    ctx->r6 = S32(0X42E1 << 16);
    // 0x8079DC50: ori         $a2, $a2, 0x9810
    ctx->r6 = ctx->r6 | 0X9810;
    // 0x8079DC54: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8079DC58: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8079DC5C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8079DC60: addiu       $a0, $zero, 0x4023
    ctx->r4 = ADD32(0, 0X4023);
    // 0x8079DC64: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8079DC68: jal         0x8005CEBC
    // 0x8079DC6C: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    func_8005CEBC(rdram, ctx);
        goto after_4;
    // 0x8079DC6C: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    after_4:
    // 0x8079DC70: sw          $v0, 0xFC($s5)
    MEM_W(0XFC, ctx->r21) = ctx->r2;
    // 0x8079DC74: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1958) << 16);
    // 0x8079DC78: lwc1        $f16, -0xBB8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1958));
    // 0x8079DC7C: lui         $s0, 0x807A
    ctx->r16 = S32(RELOC_HI16(835, 0X18BC) << 16);
    // 0x8079DC80: addiu       $s0, $s0, -0xC54
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(835, 0X18BC));
    // 0x8079DC84: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8079DC88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8079DC8C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8079DC90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8079DC94: sub.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8079DC98: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8079DC9C: addiu       $a0, $zero, 0x472B
    ctx->r4 = ADD32(0, 0X472B);
    // 0x8079DCA0: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8079DCA4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8079DCA8: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    // 0x8079DCAC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8079DCB0: jal         0x8005CEBC
    // 0x8079DCB4: nop

    func_8005CEBC(rdram, ctx);
        goto after_5;
    // 0x8079DCB4: nop

    after_5:
    // 0x8079DCB8: sw          $v0, 0x100($s5)
    MEM_W(0X100, ctx->r21) = ctx->r2;
    // 0x8079DCBC: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8079DCC0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8079DCC4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8079DCC8: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8079DCCC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8079DCD0: addiu       $a0, $zero, 0x472C
    ctx->r4 = ADD32(0, 0X472C);
    // 0x8079DCD4: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    // 0x8079DCD8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8079DCDC: jal         0x8005CEBC
    // 0x8079DCE0: nop

    func_8005CEBC(rdram, ctx);
        goto after_6;
    // 0x8079DCE0: nop

    after_6:
    // 0x8079DCE4: sw          $v0, 0x104($s5)
    MEM_W(0X104, ctx->r21) = ctx->r2;
    // 0x8079DCE8: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8079DCEC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8079DCF0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8079DCF4: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x8079DCF8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8079DCFC: addiu       $a0, $zero, 0x472D
    ctx->r4 = ADD32(0, 0X472D);
    // 0x8079DD00: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    // 0x8079DD04: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8079DD08: jal         0x8005CEBC
    // 0x8079DD0C: nop

    func_8005CEBC(rdram, ctx);
        goto after_7;
    // 0x8079DD0C: nop

    after_7:
    // 0x8079DD10: sw          $v0, 0x108($s5)
    MEM_W(0X108, ctx->r21) = ctx->r2;
    // 0x8079DD14: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8079DD18: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8079DD1C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8079DD20: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8079DD24: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8079DD28: addiu       $a0, $zero, 0x472E
    ctx->r4 = ADD32(0, 0X472E);
    // 0x8079DD2C: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    // 0x8079DD30: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8079DD34: jal         0x8005CEBC
    // 0x8079DD38: nop

    func_8005CEBC(rdram, ctx);
        goto after_8;
    // 0x8079DD38: nop

    after_8:
    // 0x8079DD3C: sw          $v0, 0x10C($s5)
    MEM_W(0X10C, ctx->r21) = ctx->r2;
    // 0x8079DD40: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8079DD44: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8079DD48: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8079DD4C: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8079DD50: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8079DD54: addiu       $a0, $zero, 0x472F
    ctx->r4 = ADD32(0, 0X472F);
    // 0x8079DD58: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    // 0x8079DD5C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8079DD60: jal         0x8005CEBC
    // 0x8079DD64: nop

    func_8005CEBC(rdram, ctx);
        goto after_9;
    // 0x8079DD64: nop

    after_9:
    // 0x8079DD68: sw          $v0, 0x110($s5)
    MEM_W(0X110, ctx->r21) = ctx->r2;
    // 0x8079DD6C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X195C) << 16);
    // 0x8079DD70: lwc1        $f22, -0xBB4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X195C));
    // 0x8079DD74: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1960) << 16);
    // 0x8079DD78: lwc1        $f20, -0xBB0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1960));
    // 0x8079DD7C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8079DD80: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x8079DD84: addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
L_8079DD88:
    // 0x8079DD88: lw          $a1, 0xEC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XEC);
    // 0x8079DD8C: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x8079DD90: subu        $t6, $t6, $s2
    ctx->r14 = SUB32(ctx->r14, ctx->r18);
    // 0x8079DD94: beq         $a1, $zero, L_8079DDF4
    if (ctx->r5 == 0) {
        // 0x8079DD98: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8079DDF4;
    }
    // 0x8079DD98: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8079DD9C: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(835, 0X18D0) << 16);
    // 0x8079DDA0: addiu       $t7, $t7, -0xC40
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(835, 0X18D0));
    // 0x8079DDA4: jal         0x80047F9C
    // 0x8079DDA8: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    func_80047F9C(rdram, ctx);
        goto after_10;
    // 0x8079DDA8: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    after_10:
    // 0x8079DDAC: lw          $t9, 0xEC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XEC);
    // 0x8079DDB0: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x8079DDB4: lw          $t0, 0x16C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X16C);
    // 0x8079DDB8: sb          $t8, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r24;
    // 0x8079DDBC: lw          $t2, 0xEC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XEC);
    // 0x8079DDC0: lbu         $t1, 0x1($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X1);
    // 0x8079DDC4: lw          $t3, 0x16C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X16C);
    // 0x8079DDC8: sb          $t1, 0xE($t3)
    MEM_B(0XE, ctx->r11) = ctx->r9;
    // 0x8079DDCC: lw          $t5, 0xEC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XEC);
    // 0x8079DDD0: lbu         $t4, 0x2($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X2);
    // 0x8079DDD4: lw          $t6, 0x16C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X16C);
    // 0x8079DDD8: sb          $t4, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r12;
    // 0x8079DDDC: lw          $t7, 0xEC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XEC);
    // 0x8079DDE0: sb          $zero, 0x165($t7)
    MEM_B(0X165, ctx->r15) = 0;
    // 0x8079DDE4: lw          $t9, 0xEC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XEC);
    // 0x8079DDE8: swc1        $f20, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->f20.u32l;
    // 0x8079DDEC: lw          $t8, 0xEC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XEC);
    // 0x8079DDF0: swc1        $f22, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f22.u32l;
L_8079DDF4:
    // 0x8079DDF4: lw          $a1, 0x100($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X100);
    // 0x8079DDF8: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    // 0x8079DDFC: subu        $t0, $t0, $s2
    ctx->r8 = SUB32(ctx->r8, ctx->r18);
    // 0x8079DE00: beq         $a1, $zero, L_8079DE60
    if (ctx->r5 == 0) {
        // 0x8079DE04: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8079DE60;
    }
    // 0x8079DE04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8079DE08: lui         $t2, 0x807A
    ctx->r10 = S32(RELOC_HI16(835, 0X18D0) << 16);
    // 0x8079DE0C: addiu       $t2, $t2, -0xC40
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(835, 0X18D0));
    // 0x8079DE10: jal         0x80047F9C
    // 0x8079DE14: addu        $s1, $t0, $t2
    ctx->r17 = ADD32(ctx->r8, ctx->r10);
    func_80047F9C(rdram, ctx);
        goto after_11;
    // 0x8079DE14: addu        $s1, $t0, $t2
    ctx->r17 = ADD32(ctx->r8, ctx->r10);
    after_11:
    // 0x8079DE18: lw          $t3, 0x100($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X100);
    // 0x8079DE1C: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x8079DE20: lw          $t5, 0x16C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X16C);
    // 0x8079DE24: sb          $t1, 0xD($t5)
    MEM_B(0XD, ctx->r13) = ctx->r9;
    // 0x8079DE28: lw          $t6, 0x100($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X100);
    // 0x8079DE2C: lbu         $t4, 0x1($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X1);
    // 0x8079DE30: lw          $t7, 0x16C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X16C);
    // 0x8079DE34: sb          $t4, 0xE($t7)
    MEM_B(0XE, ctx->r15) = ctx->r12;
    // 0x8079DE38: lw          $t8, 0x100($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X100);
    // 0x8079DE3C: lbu         $t9, 0x2($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X2);
    // 0x8079DE40: lw          $t0, 0x16C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X16C);
    // 0x8079DE44: sb          $t9, 0xF($t0)
    MEM_B(0XF, ctx->r8) = ctx->r25;
    // 0x8079DE48: lw          $t2, 0x100($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X100);
    // 0x8079DE4C: sb          $zero, 0x165($t2)
    MEM_B(0X165, ctx->r10) = 0;
    // 0x8079DE50: lw          $t3, 0x100($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X100);
    // 0x8079DE54: swc1        $f20, 0x6C($t3)
    MEM_W(0X6C, ctx->r11) = ctx->f20.u32l;
    // 0x8079DE58: lw          $t1, 0x100($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X100);
    // 0x8079DE5C: swc1        $f22, 0x70($t1)
    MEM_W(0X70, ctx->r9) = ctx->f22.u32l;
L_8079DE60:
    // 0x8079DE60: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8079DE64: bne         $s2, $s4, L_8079DD88
    if (ctx->r18 != ctx->r20) {
        // 0x8079DE68: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8079DD88;
    }
    // 0x8079DE68: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8079DE6C: sw          $zero, 0x114($s5)
    MEM_W(0X114, ctx->r21) = 0;
    // 0x8079DE70: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8079DE74: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x8079DE78: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8079DE7C: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8079DE80: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8079DE84: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8079DE88: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8079DE8C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8079DE90: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8079DE94: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8079DE98: jr          $ra
    // 0x8079DE9C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8079DE9C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_804D6620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D6620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D6624: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804D6628: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804D662C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804D6630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D6634: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804D6638: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804D663C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x804D6640: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804D6644: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x804D6648: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804D664C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804D6650: lui         $t2, 0x804D
    ctx->r10 = S32(RELOC_HI16(252, 0X5F4) << 16);
    // 0x804D6654: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804D6658: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804D665C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804D6660: lw          $t2, 0x68F4($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(252, 0X5F4));
    // 0x804D6664: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804D6668: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804D666C: jal         0x804D6470
    // 0x804D6670: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804D6470(rdram, ctx);
        goto after_0;
    // 0x804D6670: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804D6674: jal         0x804D64CC
    // 0x804D6678: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804D64CC(rdram, ctx);
        goto after_1;
    // 0x804D6678: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804D667C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D6680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D6684: jr          $ra
    // 0x804D6688: nop

    return;
    // 0x804D6688: nop

;}
RECOMP_FUNC void func_80680194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680194: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80680198: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8068019C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806801A0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806801A4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806801A8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806801AC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806801B0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x806801B4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806801B8: lui         $t1, 0x8068
    ctx->r9 = S32(RELOC_HI16(547, 0X10BC) << 16);
    // 0x806801BC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806801C0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806801C4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806801C8: lw          $t1, 0x2AC($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(547, 0X10BC));
    // 0x806801CC: jr          $ra
    // 0x806801D0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806801D0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x806801D4: nop

    // 0x806801D8: nop

    // 0x806801DC: nop

;}
RECOMP_FUNC void func_80024260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024260: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80024264: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80024268: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002426C: lwc1        $f0, -0x7678($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7678);
    // 0x80024270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80024274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024278: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002427C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80024280: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80024284: bc1fl       L_80024298
    if (!c1cs) {
        // 0x80024288: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80024298;
    }
    goto skip_0;
    // 0x80024288: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x8002428C: b           L_800242B0
    // 0x80024290: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800242B0;
    // 0x80024290: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80024294: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80024298:
    // 0x80024298: nop

    // 0x8002429C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800242A0: nop

    // 0x800242A4: bc1fl       L_800242B4
    if (!c1cs) {
        // 0x800242A8: lwc1        $f2, 0x114($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X114);
            goto L_800242B4;
    }
    goto skip_1;
    // 0x800242A8: lwc1        $f2, 0x114($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X114);
    skip_1:
    // 0x800242AC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800242B0:
    // 0x800242B0: lwc1        $f2, 0x114($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X114);
L_800242B4:
    // 0x800242B4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800242B8: nop

    // 0x800242BC: bc1fl       L_800242D0
    if (!c1cs) {
        // 0x800242C0: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800242D0;
    }
    goto skip_2;
    // 0x800242C0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_2:
    // 0x800242C4: b           L_800242D0
    // 0x800242C8: swc1        $f0, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f0.u32l;
        goto L_800242D0;
    // 0x800242C8: swc1        $f0, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f0.u32l;
    // 0x800242CC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800242D0:
    // 0x800242D0: lbu         $t6, 0x113($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X113);
    // 0x800242D4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800242D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800242DC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800242E0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800242E4: lwc1        $f4, -0x6278($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6278);
    // 0x800242E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800242EC: lwc1        $f6, -0x288($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X288);
    // 0x800242F0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800242F4: nop

    // 0x800242F8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800242FC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80024300: jal         0x80024188
    // 0x80024304: nop

    func_80024188(rdram, ctx);
        goto after_0;
    // 0x80024304: nop

    after_0:
    // 0x80024308: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8002430C: jal         0x80065954
    // 0x80024310: lwc1        $f12, 0x118($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X118);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80024310: lwc1        $f12, 0x118($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X118);
    after_1:
    // 0x80024314: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80024318: lw          $v1, 0x12C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X12C);
    // 0x8002431C: beq         $v1, $zero, L_8002432C
    if (ctx->r3 == 0) {
        // 0x80024320: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_8002432C;
    }
    // 0x80024320: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80024324: b           L_80024330
    // 0x80024328: sw          $t8, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->r24;
        goto L_80024330;
    // 0x80024328: sw          $t8, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->r24;
L_8002432C:
    // 0x8002432C: sw          $zero, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = 0;
L_80024330:
    // 0x80024330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024334: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80024338: jr          $ra
    // 0x8002433C: nop

    return;
    // 0x8002433C: nop

;}
RECOMP_FUNC void func_804C0DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0DD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804C0DD8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804C0DDC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x804C0DE0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804C0DE4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804C0DE8: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x804C0DEC: lui         $a0, 0x804C
    ctx->r4 = S32(RELOC_HI16(200, 0X580) << 16);
    // 0x804C0DF0: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x804C0DF4: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x804C0DF8: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x804C0DFC: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x804C0E00: addiu       $a0, $a0, 0xFE0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(200, 0X580));
    // 0x804C0E04: jal         0x80046804
    // 0x804C0E08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x804C0E08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x804C0E0C: beq         $v0, $zero, L_804C0E40
    if (ctx->r2 == 0) {
        // 0x804C0E10: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_804C0E40;
    }
    // 0x804C0E10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x804C0E14: jal         0x80047090
    // 0x804C0E18: addiu       $a0, $zero, 0x40A0
    ctx->r4 = ADD32(0, 0X40A0);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x804C0E18: addiu       $a0, $zero, 0x40A0
    ctx->r4 = ADD32(0, 0X40A0);
    after_1:
    // 0x804C0E1C: lhu         $t9, 0xE($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XE);
    // 0x804C0E20: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x804C0E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C0E28: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x804C0E2C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x804C0E30: jal         0x80044194
    // 0x804C0E34: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x804C0E34: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    after_2:
    // 0x804C0E38: jal         0x80052BA4
    // 0x804C0E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052BA4(rdram, ctx);
        goto after_3;
    // 0x804C0E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_804C0E40:
    // 0x804C0E40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804C0E44: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x804C0E48: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804C0E4C: jr          $ra
    // 0x804C0E50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x804C0E50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804C0E54: nop

    // 0x804C0E58: nop

    // 0x804C0E5C: nop

;}
RECOMP_FUNC void func_806D373C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D373C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D3740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D3744: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D3748: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    // 0x806D374C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806D3750: jal         0x80047EB0
    // 0x806D3754: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80047EB0(rdram, ctx);
        goto after_0;
    // 0x806D3754: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x806D3758: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D375C: bne         $v0, $zero, L_806D3780
    if (ctx->r2 != 0) {
        // 0x806D3760: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_806D3780;
    }
    // 0x806D3760: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x806D3764: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806D3768: addiu       $t6, $t6, -0x7218
    ctx->r14 = ADD32(ctx->r14, -0X7218);
    // 0x806D376C: sw          $t6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r14;
    // 0x806D3770: jal         0x8003E478
    // 0x806D3774: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003E478(rdram, ctx);
        goto after_1;
    // 0x806D3774: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x806D3778: b           L_806D37A0
    // 0x806D377C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806D37A0;
    // 0x806D377C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806D3780:
    // 0x806D3780: lw          $t7, 0x1E0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1E0);
    // 0x806D3784: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806D3788: beq         $t7, $zero, L_806D37A0
    if (ctx->r15 == 0) {
        // 0x806D378C: nop
    
            goto L_806D37A0;
    }
    // 0x806D378C: nop

    // 0x806D3790: jal         0x806D36C4
    // 0x806D3794: nop

    func_806D36C4(rdram, ctx);
        goto after_2;
    // 0x806D3794: nop

    after_2:
    // 0x806D3798: b           L_806D37A0
    // 0x806D379C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806D37A0;
    // 0x806D379C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806D37A0:
    // 0x806D37A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D37A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D37A8: jr          $ra
    // 0x806D37AC: nop

    return;
    // 0x806D37AC: nop

;}
RECOMP_FUNC void func_80438EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438EE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80438EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80438EEC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80438EF0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80438EF4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80438EF8: jal         0x800653D8
    // 0x80438EFC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80438EFC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x80438F00: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x80438F04: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80438F08: mfhi        $t6
    ctx->r14 = hi;
    // 0x80438F0C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80438F10: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80438F14: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80438F18: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x80438F1C: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80438F20: lwc1        $f14, 0x4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80438F24: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x80438F28: jal         0x80066E88
    // 0x80438F2C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80438F2C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x80438F30: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80438F34: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80438F38: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80438F3C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80438F40: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80438F44: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80438F48: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80438F4C: nop

    // 0x80438F50: bc1fl       L_80438F64
    if (!c1cs) {
        // 0x80438F54: neg.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
            goto L_80438F64;
    }
    goto skip_0;
    // 0x80438F54: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    skip_0:
    // 0x80438F58: b           L_80438F78
    // 0x80438F5C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_80438F78;
    // 0x80438F5C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80438F60: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
L_80438F64:
    // 0x80438F64: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80438F68: nop

    // 0x80438F6C: bc1fl       L_80438F7C
    if (!c1cs) {
        // 0x80438F70: lwc1        $f12, 0x24($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80438F7C;
    }
    goto skip_1;
    // 0x80438F70: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80438F74: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80438F78:
    // 0x80438F78: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
L_80438F7C:
    // 0x80438F7C: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x80438F80: jal         0x80066DE4
    // 0x80438F84: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x80438F84: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x80438F88: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80438F8C: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80438F90: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80438F94: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80438F98: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80438F9C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80438FA0: add.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80438FA4: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80438FA8: nop

    // 0x80438FAC: bc1fl       L_80438FC0
    if (!c1cs) {
        // 0x80438FB0: neg.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
            goto L_80438FC0;
    }
    goto skip_2;
    // 0x80438FB0: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    skip_2:
    // 0x80438FB4: b           L_80438FD4
    // 0x80438FB8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
        goto L_80438FD4;
    // 0x80438FB8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x80438FBC: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
L_80438FC0:
    // 0x80438FC0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80438FC4: nop

    // 0x80438FC8: bc1fl       L_80438FD8
    if (!c1cs) {
        // 0x80438FCC: swc1        $f2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
            goto L_80438FD8;
    }
    goto skip_3;
    // 0x80438FCC: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    skip_3:
    // 0x80438FD0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80438FD4:
    // 0x80438FD4: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_80438FD8:
    // 0x80438FD8: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x80438FDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80438FE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80438FE4: jr          $ra
    // 0x80438FE8: nop

    return;
    // 0x80438FE8: nop

;}
RECOMP_FUNC void func_80736A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736A0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80736A10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736A14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80736A18: jal         0x80047090
    // 0x80736A1C: addiu       $a0, $zero, 0x462E
    ctx->r4 = ADD32(0, 0X462E);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80736A1C: addiu       $a0, $zero, 0x462E
    ctx->r4 = ADD32(0, 0X462E);
    after_0:
    // 0x80736A20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80736A24: lui         $at, 0x462E
    ctx->r1 = S32(0X462E << 16);
    // 0x80736A28: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80736A2C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80736A30: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80736A34: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80736A38: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x80736A3C: jal         0x8004613C
    // 0x80736A40: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80736A40: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x80736A44: bne         $v0, $zero, L_80736A54
    if (ctx->r2 != 0) {
        // 0x80736A48: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80736A54;
    }
    // 0x80736A48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80736A4C: b           L_80736A84
    // 0x80736A50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80736A84;
    // 0x80736A50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80736A54:
    // 0x80736A54: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x80736A58: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x80736A5C: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80736A60: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x80736A64: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80736A68: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x80736A6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80736A70: jal         0x80047F9C
    // 0x80736A74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80736A74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80736A78: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80736A7C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80736A80: sb          $t2, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r10;
L_80736A84:
    // 0x80736A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80736A88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80736A8C: jr          $ra
    // 0x80736A90: nop

    return;
    // 0x80736A90: nop

;}
RECOMP_FUNC void func_8052C6BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052C6BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8052C6C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052C6C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8052C6C8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052C6CC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8052C6D0: jal         0x80067878
    // 0x8052C6D4: lh          $a1, 0xF28($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XF28);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8052C6D4: lh          $a1, 0xF28($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XF28);
    after_0:
    // 0x8052C6D8: jal         0x80045BD8
    // 0x8052C6DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8052C6DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8052C6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8052C6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8052C6E8: jr          $ra
    // 0x8052C6EC: nop

    return;
    // 0x8052C6EC: nop

;}
RECOMP_FUNC void func_80453C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453C6C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80453C70: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80453C74: lhu         $t6, 0x13B4($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X13B4);
    // 0x80453C78: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80453C7C: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80453C80: beq         $t7, $zero, L_80453CF4
    if (ctx->r15 == 0) {
        // 0x80453C84: nop
    
            goto L_80453CF4;
    }
    // 0x80453C84: nop

    // 0x80453C88: lw          $t8, 0x13B4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X13B4);
    // 0x80453C8C: lw          $t1, 0x13B4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X13B4);
    // 0x80453C90: lw          $t4, 0x13B4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X13B4);
    // 0x80453C94: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80453C98: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x80453C9C: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x80453CA0: sll         $t5, $t4, 7
    ctx->r13 = S32(ctx->r12 << 7);
    // 0x80453CA4: lw          $t7, 0x13B4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X13B4);
    // 0x80453CA8: sb          $t0, 0xF64($v0)
    MEM_B(0XF64, ctx->r2) = ctx->r8;
    // 0x80453CAC: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x80453CB0: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x80453CB4: lw          $t0, 0x13B4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X13B4);
    // 0x80453CB8: lw          $t5, 0x13B0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X13B0);
    // 0x80453CBC: sb          $t3, 0xF65($v0)
    MEM_B(0XF65, ctx->r2) = ctx->r11;
    // 0x80453CC0: lhu         $t3, 0x13B4($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X13B4);
    // 0x80453CC4: sb          $t6, 0xF66($v0)
    MEM_B(0XF66, ctx->r2) = ctx->r14;
    // 0x80453CC8: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x80453CCC: sll         $t1, $t0, 11
    ctx->r9 = S32(ctx->r8 << 11);
    // 0x80453CD0: sll         $t6, $t5, 26
    ctx->r14 = S32(ctx->r13 << 26);
    // 0x80453CD4: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x80453CD8: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x80453CDC: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x80453CE0: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x80453CE4: sb          $t9, 0xF67($v0)
    MEM_B(0XF67, ctx->r2) = ctx->r25;
    // 0x80453CE8: sb          $t2, 0xF68($v0)
    MEM_B(0XF68, ctx->r2) = ctx->r10;
    // 0x80453CEC: sb          $t4, 0xF5C($v0)
    MEM_B(0XF5C, ctx->r2) = ctx->r12;
    // 0x80453CF0: sb          $t7, 0xF6C($v0)
    MEM_B(0XF6C, ctx->r2) = ctx->r15;
L_80453CF4:
    // 0x80453CF4: jr          $ra
    // 0x80453CF8: nop

    return;
    // 0x80453CF8: nop

;}
RECOMP_FUNC void Fault_PrintFReg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F964: lui         $t8, 0xFFFA
    ctx->r24 = S32(0XFFFA << 16);
    // 0x8006F968: or          $t9, $sp, $zero
    ctx->r25 = ctx->r29 | 0;
    // 0x8006F96C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006F970: ori         $t8, $t8, 0x5A5A
    ctx->r24 = ctx->r24 | 0X5A5A;
L_8006F974:
    // 0x8006F974: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
    // 0x8006F978: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8006F97C: bne         $t9, $sp, L_8006F974
    if (ctx->r25 != ctx->r29) {
        // 0x8006F980: sw          $t8, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r24;
            goto L_8006F974;
    }
    // 0x8006F980: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8006F984: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006F988: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006F98C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006F990: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8006F994: lui         $at, 0x7F80
    ctx->r1 = S32(0X7F80 << 16);
    // 0x8006F998: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8006F99C: and         $v1, $v0, $at
    ctx->r3 = ctx->r2 & ctx->r1;
    // 0x8006F9A0: srl         $v1, $v1, 23
    ctx->r3 = S32(U32(ctx->r3) >> 23);
    // 0x8006F9A4: addiu       $v1, $v1, -0x7F
    ctx->r3 = ADD32(ctx->r3, -0X7F);
    // 0x8006F9A8: slti        $at, $v1, -0x7E
    ctx->r1 = SIGNED(ctx->r3) < -0X7E ? 1 : 0;
    // 0x8006F9AC: bne         $at, $zero, L_8006F9BC
    if (ctx->r1 != 0) {
        // 0x8006F9B0: slti        $at, $v1, 0x80
        ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
            goto L_8006F9BC;
    }
    // 0x8006F9B0: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x8006F9B4: bnel        $at, $zero, L_8006F9C8
    if (ctx->r1 != 0) {
        // 0x8006F9B8: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_8006F9C8;
    }
    goto skip_0;
    // 0x8006F9B8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_8006F9BC:
    // 0x8006F9BC: bne         $v0, $zero, L_8006F9EC
    if (ctx->r2 != 0) {
        // 0x8006F9C0: lui         $a2, 0x800B
        ctx->r6 = S32(0X800B << 16);
            goto L_8006F9EC;
    }
    // 0x8006F9C0: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006F9C4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_8006F9C8:
    // 0x8006F9C8: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006F9CC: addiu       $a2, $a2, 0x1394
    ctx->r6 = ADD32(ctx->r6, 0X1394);
    // 0x8006F9D0: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8006F9D4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8006F9D8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8006F9DC: jal         0x8006F884
    // 0x8006F9E0: sdc1        $f6, 0x10($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X10, ctx->r29);
    Fault_Printf(rdram, ctx);
        goto after_0;
    // 0x8006F9E0: sdc1        $f6, 0x10($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X10, ctx->r29);
    after_0:
    // 0x8006F9E4: b           L_8006F9FC
    // 0x8006F9E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8006F9FC;
    // 0x8006F9E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006F9EC:
    // 0x8006F9EC: addiu       $a2, $a2, 0x13A0
    ctx->r6 = ADD32(ctx->r6, 0X13A0);
    // 0x8006F9F0: jal         0x8006F884
    // 0x8006F9F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    Fault_Printf(rdram, ctx);
        goto after_1;
    // 0x8006F9F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8006F9F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006F9FC:
    // 0x8006F9FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006FA00: jr          $ra
    // 0x8006FA04: nop

    return;
    // 0x8006FA04: nop

;}
RECOMP_FUNC void func_805A7E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A7E54: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x805A7E58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805A7E5C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x805A7E60: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805A7E64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A7E68: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x805A7E6C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x805A7E70: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x805A7E74: nop

    // 0x805A7E78: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x805A7E7C: lw          $t8, 0x168($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X168);
    // 0x805A7E80: lw          $t9, 0x88($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X88);
    // 0x805A7E84: jal         0x80045A34
    // 0x805A7E88: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805A7E88: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    after_0:
    // 0x805A7E8C: bne         $v0, $zero, L_805A7EA4
    if (ctx->r2 != 0) {
        // 0x805A7E90: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_805A7EA4;
    }
    // 0x805A7E90: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x805A7E94: jal         0x800445A4
    // 0x805A7E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x805A7E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A7E9C: b           L_805A82C8
    // 0x805A7EA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_805A82C8;
    // 0x805A7EA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805A7EA4:
    // 0x805A7EA4: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x805A7EA8: lui         $t0, 0x805B
    ctx->r8 = S32(RELOC_HI16(426, 0X16E8) << 16);
    // 0x805A7EAC: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x805A7EB0: addiu       $t0, $t0, -0x75C8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(426, 0X16E8));
    // 0x805A7EB4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x805A7EB8: lui         $t3, 0x8005
    ctx->r11 = S32(0X8005 << 16);
    // 0x805A7EBC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x805A7EC0: addiu       $t3, $t3, -0x7C48
    ctx->r11 = ADD32(ctx->r11, -0X7C48);
    // 0x805A7EC4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x805A7EC8: sw          $t2, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r10;
    // 0x805A7ECC: sw          $t3, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r11;
    // 0x805A7ED0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x805A7ED4: jal         0x80067BBC
    // 0x805A7ED8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x805A7ED8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x805A7EDC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x805A7EE0: jal         0x80067F78
    // 0x805A7EE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_3;
    // 0x805A7EE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x805A7EE8: lui         $v1, 0x805A
    ctx->r3 = S32(RELOC_HI16(426, 0X290) << 16);
    // 0x805A7EEC: lui         $t4, 0x805A
    ctx->r12 = S32(RELOC_HI16(426, 0X180) << 16);
    // 0x805A7EF0: addiu       $v1, $v1, 0x75E0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(426, 0X290));
    // 0x805A7EF4: addiu       $t4, $t4, 0x74D0
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(426, 0X180));
    // 0x805A7EF8: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x805A7EFC: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    // 0x805A7F00: sw          $t4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r12;
    // 0x805A7F04: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x805A7F08: jal         0x805A757C
    // 0x805A7F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A757C(rdram, ctx);
        goto after_4;
    // 0x805A7F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805A7F10: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x805A7F14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805A7F18: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805A7F1C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x805A7F20: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    // 0x805A7F24: addiu       $t5, $zero, 0x96
    ctx->r13 = ADD32(0, 0X96);
    // 0x805A7F28: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(426, 0XC4) << 16);
    // 0x805A7F2C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x805A7F30: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x805A7F34: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x805A7F38: addiu       $t6, $t6, 0x7414
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(426, 0XC4));
    // 0x805A7F3C: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
    // 0x805A7F40: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    // 0x805A7F44: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x805A7F48: jal         0x80058958
    // 0x805A7F4C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    func_80058958(rdram, ctx);
        goto after_5;
    // 0x805A7F4C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_5:
    // 0x805A7F50: beq         $v0, $zero, L_805A7FC8
    if (ctx->r2 == 0) {
        // 0x805A7F54: lui         $t7, 0x8010
        ctx->r15 = S32(0X8010 << 16);
            goto L_805A7FC8;
    }
    // 0x805A7F54: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x805A7F58: lw          $t7, -0x7BC4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7BC4);
    // 0x805A7F5C: lw          $t8, 0x10C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10C);
    // 0x805A7F60: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x805A7F64: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x805A7F68: beql        $t0, $zero, L_805A7FCC
    if (ctx->r8 == 0) {
        // 0x805A7F6C: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_805A7FCC;
    }
    goto skip_0;
    // 0x805A7F6C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x805A7F70: jal         0x80056564
    // 0x805A7F74: nop

    func_80056564(rdram, ctx);
        goto after_6;
    // 0x805A7F74: nop

    after_6:
    // 0x805A7F78: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x805A7F7C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805A7F80: beq         $v0, $zero, L_805A7FC8
    if (ctx->r2 == 0) {
        // 0x805A7F84: sw          $v0, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r2;
            goto L_805A7FC8;
    }
    // 0x805A7F84: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x805A7F88: jal         0x800457A0
    // 0x805A7F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800457A0(rdram, ctx);
        goto after_7;
    // 0x805A7F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x805A7F90: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x805A7F94: addiu       $t3, $zero, 0x29
    ctx->r11 = ADD32(0, 0X29);
    // 0x805A7F98: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x805A7F9C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x805A7FA0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x805A7FA4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x805A7FA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805A7FAC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805A7FB0: jal         0x80056584
    // 0x805A7FB4: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80056584(rdram, ctx);
        goto after_8;
    // 0x805A7FB4: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_8:
    // 0x805A7FB8: lw          $t6, 0x16C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X16C);
    // 0x805A7FBC: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x805A7FC0: addiu       $t5, $t5, 0x784C
    ctx->r13 = ADD32(ctx->r13, 0X784C);
    // 0x805A7FC4: sw          $t5, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r13;
L_805A7FC8:
    // 0x805A7FC8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_805A7FCC:
    // 0x805A7FCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805A7FD0: sra         $v0, $v0, 4
    ctx->r2 = S32(SIGNED(ctx->r2) >> 4);
    // 0x805A7FD4: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x805A7FD8: beql        $v0, $zero, L_805A80B0
    if (ctx->r2 == 0) {
        // 0x805A7FDC: lw          $t8, 0x174($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X174);
            goto L_805A80B0;
    }
    goto skip_1;
    // 0x805A7FDC: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    skip_1:
    // 0x805A7FE0: beq         $v0, $at, L_805A8008
    if (ctx->r2 == ctx->r1) {
        // 0x805A7FE4: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_805A8008;
    }
    // 0x805A7FE4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x805A7FE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805A7FEC: beq         $v0, $at, L_805A8040
    if (ctx->r2 == ctx->r1) {
        // 0x805A7FF0: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_805A8040;
    }
    // 0x805A7FF0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x805A7FF4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805A7FF8: beq         $v0, $at, L_805A8074
    if (ctx->r2 == ctx->r1) {
        // 0x805A7FFC: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_805A8074;
    }
    // 0x805A7FFC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x805A8000: b           L_805A80D8
    // 0x805A8004: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
        goto L_805A80D8;
    // 0x805A8004: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
L_805A8008:
    // 0x805A8008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A800C: jal         0x8004590C
    // 0x805A8010: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    func_8004590C(rdram, ctx);
        goto after_9;
    // 0x805A8010: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    after_9:
    // 0x805A8014: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x805A8018: addiu       $t7, $zero, 0x2242
    ctx->r15 = ADD32(0, 0X2242);
    // 0x805A801C: addiu       $t0, $zero, 0x2244
    ctx->r8 = ADD32(0, 0X2244);
    // 0x805A8020: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x805A8024: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x805A8028: sh          $t7, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r15;
    // 0x805A802C: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    // 0x805A8030: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x805A8034: sh          $t0, 0x1A($t2)
    MEM_H(0X1A, ctx->r10) = ctx->r8;
    // 0x805A8038: b           L_805A80D4
    // 0x805A803C: sw          $t3, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r11;
        goto L_805A80D4;
    // 0x805A803C: sw          $t3, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r11;
L_805A8040:
    // 0x805A8040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A8044: jal         0x8004590C
    // 0x805A8048: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    func_8004590C(rdram, ctx);
        goto after_10;
    // 0x805A8048: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    after_10:
    // 0x805A804C: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    // 0x805A8050: addiu       $t4, $zero, 0x4222
    ctx->r12 = ADD32(0, 0X4222);
    // 0x805A8054: addiu       $t8, $zero, 0x2244
    ctx->r24 = ADD32(0, 0X2244);
    // 0x805A8058: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x805A805C: sh          $t4, 0x18($t6)
    MEM_H(0X18, ctx->r14) = ctx->r12;
    // 0x805A8060: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x805A8064: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x805A8068: sh          $t8, 0x1A($t9)
    MEM_H(0X1A, ctx->r25) = ctx->r24;
    // 0x805A806C: b           L_805A80D4
    // 0x805A8070: sw          $zero, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = 0;
        goto L_805A80D4;
    // 0x805A8070: sw          $zero, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = 0;
L_805A8074:
    // 0x805A8074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A8078: jal         0x8004590C
    // 0x805A807C: addiu       $a1, $a1, 0x600
    ctx->r5 = ADD32(ctx->r5, 0X600);
    func_8004590C(rdram, ctx);
        goto after_11;
    // 0x805A807C: addiu       $a1, $a1, 0x600
    ctx->r5 = ADD32(ctx->r5, 0X600);
    after_11:
    // 0x805A8080: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x805A8084: addiu       $t1, $zero, 0x2224
    ctx->r9 = ADD32(0, 0X2224);
    // 0x805A8088: addiu       $t3, $zero, 0x4244
    ctx->r11 = ADD32(0, 0X4244);
    // 0x805A808C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x805A8090: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x805A8094: sh          $t1, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r9;
    // 0x805A8098: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    // 0x805A809C: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x805A80A0: sh          $t3, 0x1A($t4)
    MEM_H(0X1A, ctx->r12) = ctx->r11;
    // 0x805A80A4: b           L_805A80D4
    // 0x805A80A8: sw          $t6, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r14;
        goto L_805A80D4;
    // 0x805A80A8: sw          $t6, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r14;
    // 0x805A80AC: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
L_805A80B0:
    // 0x805A80B0: addiu       $t7, $zero, 0x2422
    ctx->r15 = ADD32(0, 0X2422);
    // 0x805A80B4: addiu       $t0, $zero, 0x2444
    ctx->r8 = ADD32(0, 0X2444);
    // 0x805A80B8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x805A80BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x805A80C0: sh          $t7, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r15;
    // 0x805A80C4: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    // 0x805A80C8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x805A80CC: sh          $t0, 0x1A($t2)
    MEM_H(0X1A, ctx->r10) = ctx->r8;
    // 0x805A80D0: sw          $t5, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r13;
L_805A80D4:
    // 0x805A80D4: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
L_805A80D8:
    // 0x805A80D8: slti        $at, $v0, 0x45B4
    ctx->r1 = SIGNED(ctx->r2) < 0X45B4 ? 1 : 0;
    // 0x805A80DC: bne         $at, $zero, L_805A80F8
    if (ctx->r1 != 0) {
        // 0x805A80E0: addiu       $t3, $v0, -0x4182
        ctx->r11 = ADD32(ctx->r2, -0X4182);
            goto L_805A80F8;
    }
    // 0x805A80E0: addiu       $t3, $v0, -0x4182
    ctx->r11 = ADD32(ctx->r2, -0X4182);
    // 0x805A80E4: addiu       $at, $zero, 0x4696
    ctx->r1 = ADD32(0, 0X4696);
    // 0x805A80E8: beq         $v0, $at, L_805A8184
    if (ctx->r2 == ctx->r1) {
        // 0x805A80EC: lui         $t5, 0x805B
        ctx->r13 = S32(RELOC_HI16(426, 0X16F8) << 16);
            goto L_805A8184;
    }
    // 0x805A80EC: lui         $t5, 0x805B
    ctx->r13 = S32(RELOC_HI16(426, 0X16F8) << 16);
    // 0x805A80F0: b           L_805A81B4
    // 0x805A80F4: lhu         $t3, 0x48($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X48);
        goto L_805A81B4;
    // 0x805A80F4: lhu         $t3, 0x48($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X48);
L_805A80F8:
    // 0x805A80F8: slti        $at, $v0, 0x4188
    ctx->r1 = SIGNED(ctx->r2) < 0X4188 ? 1 : 0;
    // 0x805A80FC: bne         $at, $zero, L_805A8114
    if (ctx->r1 != 0) {
        // 0x805A8100: addiu       $at, $zero, 0x45B3
        ctx->r1 = ADD32(0, 0X45B3);
            goto L_805A8114;
    }
    // 0x805A8100: addiu       $at, $zero, 0x45B3
    ctx->r1 = ADD32(0, 0X45B3);
    // 0x805A8104: beq         $v0, $at, L_805A817C
    if (ctx->r2 == ctx->r1) {
        // 0x805A8108: addiu       $t0, $zero, 0x45B6
        ctx->r8 = ADD32(0, 0X45B6);
            goto L_805A817C;
    }
    // 0x805A8108: addiu       $t0, $zero, 0x45B6
    ctx->r8 = ADD32(0, 0X45B6);
    // 0x805A810C: b           L_805A81B4
    // 0x805A8110: lhu         $t3, 0x48($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X48);
        goto L_805A81B4;
    // 0x805A8110: lhu         $t3, 0x48($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X48);
L_805A8114:
    // 0x805A8114: sltiu       $at, $t3, 0x6
    ctx->r1 = ctx->r11 < 0X6 ? 1 : 0;
    // 0x805A8118: beq         $at, $zero, L_805A81B0
    if (ctx->r1 == 0) {
        // 0x805A811C: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_805A81B0;
    }
    // 0x805A811C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x805A8120: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(426, 0X1770) << 16);
    // 0x805A8124: addu        $at, $at, $t3
    gpr jr_addend_805A812C = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x805A8128: lw          $t3, -0x7540($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(426, 0X1770));
    // 0x805A812C: jr          $t3
    // 0x805A8130: nop

    switch (jr_addend_805A812C >> 2) {
        case 0: goto L_805A8134; break;
        case 1: goto L_805A8140; break;
        case 2: goto L_805A814C; break;
        case 3: goto L_805A8158; break;
        case 4: goto L_805A8164; break;
        case 5: goto L_805A8170; break;
        default: switch_error(__func__, 0x805A812C, 0x805A8AC0);
    }
    // 0x805A8130: nop

L_805A8134:
    // 0x805A8134: addiu       $t4, $zero, 0x4030
    ctx->r12 = ADD32(0, 0X4030);
    // 0x805A8138: b           L_805A81B0
    // 0x805A813C: sh          $t4, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r12;
        goto L_805A81B0;
    // 0x805A813C: sh          $t4, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r12;
L_805A8140:
    // 0x805A8140: addiu       $t6, $zero, 0x4031
    ctx->r14 = ADD32(0, 0X4031);
    // 0x805A8144: b           L_805A81B0
    // 0x805A8148: sh          $t6, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r14;
        goto L_805A81B0;
    // 0x805A8148: sh          $t6, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r14;
L_805A814C:
    // 0x805A814C: addiu       $t8, $zero, 0x4032
    ctx->r24 = ADD32(0, 0X4032);
    // 0x805A8150: b           L_805A81B0
    // 0x805A8154: sh          $t8, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r24;
        goto L_805A81B0;
    // 0x805A8154: sh          $t8, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r24;
L_805A8158:
    // 0x805A8158: addiu       $t7, $zero, 0x4033
    ctx->r15 = ADD32(0, 0X4033);
    // 0x805A815C: b           L_805A81B0
    // 0x805A8160: sh          $t7, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r15;
        goto L_805A81B0;
    // 0x805A8160: sh          $t7, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r15;
L_805A8164:
    // 0x805A8164: addiu       $t9, $zero, 0x4034
    ctx->r25 = ADD32(0, 0X4034);
    // 0x805A8168: b           L_805A81B0
    // 0x805A816C: sh          $t9, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r25;
        goto L_805A81B0;
    // 0x805A816C: sh          $t9, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r25;
L_805A8170:
    // 0x805A8170: addiu       $t1, $zero, 0x4035
    ctx->r9 = ADD32(0, 0X4035);
    // 0x805A8174: b           L_805A81B0
    // 0x805A8178: sh          $t1, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r9;
        goto L_805A81B0;
    // 0x805A8178: sh          $t1, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r9;
L_805A817C:
    // 0x805A817C: b           L_805A81B0
    // 0x805A8180: sh          $t0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r8;
        goto L_805A81B0;
    // 0x805A8180: sh          $t0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r8;
L_805A8184:
    // 0x805A8184: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x805A8188: lw          $v0, -0x76C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X76C0);
    // 0x805A818C: bltz        $v0, L_805A819C
    if (SIGNED(ctx->r2) < 0) {
        // 0x805A8190: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_805A819C;
    }
    // 0x805A8190: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x805A8194: bnel        $at, $zero, L_805A81A4
    if (ctx->r1 != 0) {
        // 0x805A8198: sll         $t2, $v0, 1
        ctx->r10 = S32(ctx->r2 << 1);
            goto L_805A81A4;
    }
    goto skip_2;
    // 0x805A8198: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    skip_2:
L_805A819C:
    // 0x805A819C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x805A81A0: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
L_805A81A4:
    // 0x805A81A4: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x805A81A8: lhu         $t5, -0x75B8($t5)
    ctx->r13 = MEM_HU(ctx->r13, (int16_t)RELOC_LO16(426, 0X16F8));
    // 0x805A81AC: sh          $t5, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r13;
L_805A81B0:
    // 0x805A81B0: lhu         $t3, 0x48($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X48);
L_805A81B4:
    // 0x805A81B4: addiu       $at, $zero, 0x45B6
    ctx->r1 = ADD32(0, 0X45B6);
    // 0x805A81B8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x805A81BC: beq         $t3, $at, L_805A8230
    if (ctx->r11 == ctx->r1) {
        // 0x805A81C0: lui         $t6, 0x8010
        ctx->r14 = S32(0X8010 << 16);
            goto L_805A8230;
    }
    // 0x805A81C0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805A81C4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x805A81C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805A81CC: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x805A81D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805A81D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A81D8: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(426, 0X1788) << 16);
    // 0x805A81DC: lwc1        $f18, -0x7528($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(426, 0X1788));
    // 0x805A81E0: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x805A81E4: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x805A81E8: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x805A81EC: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x805A81F0: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x805A81F4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x805A81F8: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x805A81FC: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x805A8200: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x805A8204: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x805A8208: lw          $t9, 0x54($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X54);
    // 0x805A820C: jalr        $t9
    // 0x805A8210: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_12;
    // 0x805A8210: nop

    after_12:
    // 0x805A8214: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x805A8218: bne         $v0, $zero, L_805A8290
    if (ctx->r2 != 0) {
        // 0x805A821C: sw          $v0, 0x4($t7)
        MEM_W(0X4, ctx->r15) = ctx->r2;
            goto L_805A8290;
    }
    // 0x805A821C: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
    // 0x805A8220: jal         0x800445A4
    // 0x805A8224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_13;
    // 0x805A8224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x805A8228: b           L_805A82C8
    // 0x805A822C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_805A82C8;
    // 0x805A822C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805A8230:
    // 0x805A8230: jal         0x80047090
    // 0x805A8234: addiu       $a0, $zero, 0x45B6
    ctx->r4 = ADD32(0, 0X45B6);
    func_80047090(rdram, ctx);
        goto after_14;
    // 0x805A8234: addiu       $a0, $zero, 0x45B6
    ctx->r4 = ADD32(0, 0X45B6);
    after_14:
    // 0x805A8238: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A823C: lui         $at, 0x45B6
    ctx->r1 = S32(0X45B6 << 16);
    // 0x805A8240: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x805A8244: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805A8248: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805A824C: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x805A8250: jal         0x8004613C
    // 0x805A8254: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_15;
    // 0x805A8254: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_15:
    // 0x805A8258: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x805A825C: bne         $v0, $zero, L_805A8274
    if (ctx->r2 != 0) {
        // 0x805A8260: sw          $v0, 0x4($t1)
        MEM_W(0X4, ctx->r9) = ctx->r2;
            goto L_805A8274;
    }
    // 0x805A8260: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x805A8264: jal         0x800445A4
    // 0x805A8268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_16;
    // 0x805A8268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x805A826C: b           L_805A82C8
    // 0x805A8270: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_805A82C8;
    // 0x805A8270: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805A8274:
    // 0x805A8274: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x805A8278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A827C: jal         0x80047F9C
    // 0x805A8280: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    func_80047F9C(rdram, ctx);
        goto after_17;
    // 0x805A8280: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    after_17:
    // 0x805A8284: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x805A8288: jal         0x8005FDC4
    // 0x805A828C: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    func_8005FDC4(rdram, ctx);
        goto after_18;
    // 0x805A828C: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    after_18:
L_805A8290:
    // 0x805A8290: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x805A8294: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(426, 0X178C) << 16);
    // 0x805A8298: lwc1        $f0, -0x7524($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(426, 0X178C));
    // 0x805A829C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x805A82A0: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x805A82A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A82A8: sb          $t5, 0x17C($t4)
    MEM_B(0X17C, ctx->r12) = ctx->r13;
    // 0x805A82AC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x805A82B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A82B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805A82B8: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x805A82BC: jal         0x805A8794
    // 0x805A82C0: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    func_805A8794(rdram, ctx);
        goto after_19;
    // 0x805A82C0: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    after_19:
    // 0x805A82C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805A82C8:
    // 0x805A82C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805A82CC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x805A82D0: jr          $ra
    // 0x805A82D4: nop

    return;
    // 0x805A82D4: nop

;}
RECOMP_FUNC void func_80064CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064CC0: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80064CC4: addiu       $t7, $a1, 0x1F
    ctx->r15 = ADD32(ctx->r5, 0X1F);
    // 0x80064CC8: srl         $t8, $t7, 4
    ctx->r24 = S32(U32(ctx->r15) >> 4);
    // 0x80064CCC: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80064CD0: subu        $a2, $t6, $t9
    ctx->r6 = SUB32(ctx->r14, ctx->r25);
    // 0x80064CD4: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x80064CD8: bne         $at, $zero, L_80064D00
    if (ctx->r1 != 0) {
        // 0x80064CDC: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80064D00;
    }
    // 0x80064CDC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80064CE0: jal         0x80064C14
    // 0x80064CE4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80064C14(rdram, ctx);
        goto after_0;
    // 0x80064CE4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80064CE8: bne         $v0, $zero, L_80064CF8
    if (ctx->r2 != 0) {
        // 0x80064CEC: nop
    
            goto L_80064CF8;
    }
    // 0x80064CEC: nop

    // 0x80064CF0: b           L_80064D0C
    // 0x80064CF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80064D0C;
    // 0x80064CF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80064CF8:
    // 0x80064CF8: b           L_80064D00
    // 0x80064CFC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
        goto L_80064D00;
    // 0x80064CFC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_80064D00:
    // 0x80064D00: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80064D04: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
    // 0x80064D08: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
L_80064D0C:
    // 0x80064D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064D10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064D14: jr          $ra
    // 0x80064D18: nop

    return;
    // 0x80064D18: nop

;}
RECOMP_FUNC void func_80716CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716CC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80716CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80716CD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80716CD4: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80716CD8: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80716CDC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80716CE0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80716CE4: lw          $v1, 0x6E44($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E44);
    // 0x80716CE8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80716CEC: beql        $v1, $zero, L_80716D08
    if (ctx->r3 == 0) {
        // 0x80716CF0: lw          $v1, 0x0($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X0);
            goto L_80716D08;
    }
    goto skip_0;
    // 0x80716CF0: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    skip_0:
    // 0x80716CF4: jal         0x80716998
    // 0x80716CF8: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    func_80716998(rdram, ctx);
        goto after_0;
    // 0x80716CF8: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_0:
    // 0x80716CFC: b           L_80716D2C
    // 0x80716D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80716D2C;
    // 0x80716D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80716D04: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
L_80716D08:
    // 0x80716D08: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80716D0C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80716D10: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80716D14: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80716D18: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80716D1C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80716D20: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80716D24: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80716D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80716D2C:
    // 0x80716D2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80716D30: jr          $ra
    // 0x80716D34: nop

    return;
    // 0x80716D34: nop

;}
RECOMP_FUNC void func_800729DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800729DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800729E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800729E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800729E8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800729EC: addiu       $t6, $t6, -0x4D98
    ctx->r14 = ADD32(ctx->r14, -0X4D98);
    // 0x800729F0: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800729F4: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x800729F8: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x800729FC: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80072A00: addiu       $t7, $t7, -0x4D94
    ctx->r15 = ADD32(ctx->r15, -0X4D94);
    // 0x80072A04: addiu       $t9, $t9, 0x1570
    ctx->r25 = ADD32(ctx->r25, 0X1570);
    // 0x80072A08: addiu       $t8, $t8, 0x1640
    ctx->r24 = ADD32(ctx->r24, 0X1640);
    // 0x80072A0C: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80072A10: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80072A14: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80072A18: jal         0x80071D98
    // 0x80072A1C: sw          $t0, -0x7B64($at)
    MEM_W(-0X7B64, ctx->r1) = ctx->r8;
    func_80071D98(rdram, ctx);
        goto after_0;
    // 0x80072A1C: sw          $t0, -0x7B64($at)
    MEM_W(-0X7B64, ctx->r1) = ctx->r8;
    after_0:
    // 0x80072A20: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072A24: addiu       $a1, $a1, 0x1CB4
    ctx->r5 = ADD32(ctx->r5, 0X1CB4);
    // 0x80072A28: jal         0x8007E3D0
    // 0x80072A2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8007E3D0(rdram, ctx);
        goto after_1;
    // 0x80072A2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80072A30: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072A34: addiu       $a1, $a1, 0x1CBC
    ctx->r5 = ADD32(ctx->r5, 0X1CBC);
    // 0x80072A38: jal         0x8007E3D0
    // 0x80072A3C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8007E3D0(rdram, ctx);
        goto after_2;
    // 0x80072A3C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x80072A40: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072A44: addiu       $a1, $a1, 0x1CC4
    ctx->r5 = ADD32(ctx->r5, 0X1CC4);
    // 0x80072A48: jal         0x8007E3D0
    // 0x80072A4C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_8007E3D0(rdram, ctx);
        goto after_3;
    // 0x80072A4C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_3:
    // 0x80072A50: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072A54: addiu       $a1, $a1, 0x1CCC
    ctx->r5 = ADD32(ctx->r5, 0X1CCC);
    // 0x80072A58: jal         0x8007E3D0
    // 0x80072A5C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_8007E3D0(rdram, ctx);
        goto after_4;
    // 0x80072A5C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_4:
    // 0x80072A60: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072A64: addiu       $a1, $a1, 0x1CD4
    ctx->r5 = ADD32(ctx->r5, 0X1CD4);
    // 0x80072A68: jal         0x8007E3D0
    // 0x80072A6C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8007E3D0(rdram, ctx);
        goto after_5;
    // 0x80072A6C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_5:
    // 0x80072A70: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072A74: addiu       $a1, $a1, 0x1CDC
    ctx->r5 = ADD32(ctx->r5, 0X1CDC);
    // 0x80072A78: jal         0x8007E3D0
    // 0x80072A7C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_8007E3D0(rdram, ctx);
        goto after_6;
    // 0x80072A7C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_6:
    // 0x80072A80: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072A84: addiu       $a1, $a1, 0x1CE4
    ctx->r5 = ADD32(ctx->r5, 0X1CE4);
    // 0x80072A88: jal         0x8007E3D0
    // 0x80072A8C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_8007E3D0(rdram, ctx);
        goto after_7;
    // 0x80072A8C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_7:
    // 0x80072A90: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072A94: addiu       $a1, $a1, 0x1CEC
    ctx->r5 = ADD32(ctx->r5, 0X1CEC);
    // 0x80072A98: jal         0x8007E3D0
    // 0x80072A9C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8007E3D0(rdram, ctx);
        goto after_8;
    // 0x80072A9C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_8:
    // 0x80072AA0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072AA4: addiu       $a1, $a1, 0x1CF4
    ctx->r5 = ADD32(ctx->r5, 0X1CF4);
    // 0x80072AA8: jal         0x8007E3D0
    // 0x80072AAC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_8007E3D0(rdram, ctx);
        goto after_9;
    // 0x80072AAC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_9:
    // 0x80072AB0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072AB4: addiu       $a1, $a1, 0x1CFC
    ctx->r5 = ADD32(ctx->r5, 0X1CFC);
    // 0x80072AB8: jal         0x8007E3D0
    // 0x80072ABC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_8007E3D0(rdram, ctx);
        goto after_10;
    // 0x80072ABC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_10:
    // 0x80072AC0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072AC4: addiu       $a1, $a1, 0x1D04
    ctx->r5 = ADD32(ctx->r5, 0X1D04);
    // 0x80072AC8: jal         0x8007E3D0
    // 0x80072ACC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_8007E3D0(rdram, ctx);
        goto after_11;
    // 0x80072ACC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_11:
    // 0x80072AD0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072AD4: addiu       $a1, $a1, 0x1D0C
    ctx->r5 = ADD32(ctx->r5, 0X1D0C);
    // 0x80072AD8: jal         0x8007E3D0
    // 0x80072ADC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_8007E3D0(rdram, ctx);
        goto after_12;
    // 0x80072ADC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_12:
    // 0x80072AE0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072AE4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072AE8: addiu       $a1, $a1, 0x1D18
    ctx->r5 = ADD32(ctx->r5, 0X1D18);
    // 0x80072AEC: jal         0x8007E3D0
    // 0x80072AF0: addiu       $a0, $a0, -0x5948
    ctx->r4 = ADD32(ctx->r4, -0X5948);
    func_8007E3D0(rdram, ctx);
        goto after_13;
    // 0x80072AF0: addiu       $a0, $a0, -0x5948
    ctx->r4 = ADD32(ctx->r4, -0X5948);
    after_13:
    // 0x80072AF4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072AF8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072AFC: addiu       $a1, $a1, 0x1D28
    ctx->r5 = ADD32(ctx->r5, 0X1D28);
    // 0x80072B00: jal         0x8007E3D0
    // 0x80072B04: addiu       $a0, $a0, -0x5968
    ctx->r4 = ADD32(ctx->r4, -0X5968);
    func_8007E3D0(rdram, ctx);
        goto after_14;
    // 0x80072B04: addiu       $a0, $a0, -0x5968
    ctx->r4 = ADD32(ctx->r4, -0X5968);
    after_14:
    // 0x80072B08: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072B0C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072B10: addiu       $a1, $a1, 0x1D38
    ctx->r5 = ADD32(ctx->r5, 0X1D38);
    // 0x80072B14: jal         0x8007E3D0
    // 0x80072B18: addiu       $a0, $a0, -0x2750
    ctx->r4 = ADD32(ctx->r4, -0X2750);
    func_8007E3D0(rdram, ctx);
        goto after_15;
    // 0x80072B18: addiu       $a0, $a0, -0x2750
    ctx->r4 = ADD32(ctx->r4, -0X2750);
    after_15:
    // 0x80072B1C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072B20: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072B24: addiu       $a1, $a1, 0x1D4C
    ctx->r5 = ADD32(ctx->r5, 0X1D4C);
    // 0x80072B28: jal         0x8007E3D0
    // 0x80072B2C: addiu       $a0, $a0, -0x2730
    ctx->r4 = ADD32(ctx->r4, -0X2730);
    func_8007E3D0(rdram, ctx);
        goto after_16;
    // 0x80072B2C: addiu       $a0, $a0, -0x2730
    ctx->r4 = ADD32(ctx->r4, -0X2730);
    after_16:
    // 0x80072B30: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072B34: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072B38: addiu       $a1, $a1, 0x1D60
    ctx->r5 = ADD32(ctx->r5, 0X1D60);
    // 0x80072B3C: jal         0x8007E3D0
    // 0x80072B40: addiu       $a0, $a0, -0x2770
    ctx->r4 = ADD32(ctx->r4, -0X2770);
    func_8007E3D0(rdram, ctx);
        goto after_17;
    // 0x80072B40: addiu       $a0, $a0, -0x2770
    ctx->r4 = ADD32(ctx->r4, -0X2770);
    after_17:
    // 0x80072B44: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072B48: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072B4C: addiu       $a1, $a1, 0x1D74
    ctx->r5 = ADD32(ctx->r5, 0X1D74);
    // 0x80072B50: jal         0x8007E3D0
    // 0x80072B54: addiu       $a0, $a0, -0x2710
    ctx->r4 = ADD32(ctx->r4, -0X2710);
    func_8007E3D0(rdram, ctx);
        goto after_18;
    // 0x80072B54: addiu       $a0, $a0, -0x2710
    ctx->r4 = ADD32(ctx->r4, -0X2710);
    after_18:
    // 0x80072B58: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072B5C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072B60: addiu       $a1, $a1, 0x1D84
    ctx->r5 = ADD32(ctx->r5, 0X1D84);
    // 0x80072B64: jal         0x8007E3D0
    // 0x80072B68: addiu       $a0, $a0, -0x5908
    ctx->r4 = ADD32(ctx->r4, -0X5908);
    func_8007E3D0(rdram, ctx);
        goto after_19;
    // 0x80072B68: addiu       $a0, $a0, -0x5908
    ctx->r4 = ADD32(ctx->r4, -0X5908);
    after_19:
    // 0x80072B6C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072B70: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072B74: addiu       $a1, $a1, 0x1D94
    ctx->r5 = ADD32(ctx->r5, 0X1D94);
    // 0x80072B78: jal         0x8007E3D0
    // 0x80072B7C: addiu       $a0, $a0, -0x26D0
    ctx->r4 = ADD32(ctx->r4, -0X26D0);
    func_8007E3D0(rdram, ctx);
        goto after_20;
    // 0x80072B7C: addiu       $a0, $a0, -0x26D0
    ctx->r4 = ADD32(ctx->r4, -0X26D0);
    after_20:
    // 0x80072B80: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072B84: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072B88: addiu       $a1, $a1, 0x1DA4
    ctx->r5 = ADD32(ctx->r5, 0X1DA4);
    // 0x80072B8C: jal         0x8007E3D0
    // 0x80072B90: addiu       $a0, $a0, -0x59E0
    ctx->r4 = ADD32(ctx->r4, -0X59E0);
    func_8007E3D0(rdram, ctx);
        goto after_21;
    // 0x80072B90: addiu       $a0, $a0, -0x59E0
    ctx->r4 = ADD32(ctx->r4, -0X59E0);
    after_21:
    // 0x80072B94: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072B98: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072B9C: addiu       $a1, $a1, 0x1DB4
    ctx->r5 = ADD32(ctx->r5, 0X1DB4);
    // 0x80072BA0: jal         0x8007E3D0
    // 0x80072BA4: addiu       $a0, $a0, -0x59C0
    ctx->r4 = ADD32(ctx->r4, -0X59C0);
    func_8007E3D0(rdram, ctx);
        goto after_22;
    // 0x80072BA4: addiu       $a0, $a0, -0x59C0
    ctx->r4 = ADD32(ctx->r4, -0X59C0);
    after_22:
    // 0x80072BA8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072BAC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072BB0: addiu       $a1, $a1, 0x1DC4
    ctx->r5 = ADD32(ctx->r5, 0X1DC4);
    // 0x80072BB4: jal         0x8007E3D0
    // 0x80072BB8: addiu       $a0, $a0, -0x5928
    ctx->r4 = ADD32(ctx->r4, -0X5928);
    func_8007E3D0(rdram, ctx);
        goto after_23;
    // 0x80072BB8: addiu       $a0, $a0, -0x5928
    ctx->r4 = ADD32(ctx->r4, -0X5928);
    after_23:
    // 0x80072BBC: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80072BC0: addiu       $s0, $s0, -0x27B0
    ctx->r16 = ADD32(ctx->r16, -0X27B0);
    // 0x80072BC4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80072BC8: addiu       $a1, $a1, 0x1DD8
    ctx->r5 = ADD32(ctx->r5, 0X1DD8);
    // 0x80072BCC: jal         0x8007E3D0
    // 0x80072BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007E3D0(rdram, ctx);
        goto after_24;
    // 0x80072BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80072BD4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072BD8: addiu       $a1, $a1, -0x2798
    ctx->r5 = ADD32(ctx->r5, -0X2798);
    // 0x80072BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80072BE0: jal         0x8008AE20
    // 0x80072BE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_25;
    // 0x80072BE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_25:
    // 0x80072BE8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072BEC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072BF0: addiu       $a1, $a1, -0x2778
    ctx->r5 = ADD32(ctx->r5, -0X2778);
    // 0x80072BF4: addiu       $a0, $a0, -0x2790
    ctx->r4 = ADD32(ctx->r4, -0X2790);
    // 0x80072BF8: jal         0x8008AE20
    // 0x80072BFC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_26;
    // 0x80072BFC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_26:
    // 0x80072C00: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072C04: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072C08: addiu       $a1, $a1, -0x2758
    ctx->r5 = ADD32(ctx->r5, -0X2758);
    // 0x80072C0C: addiu       $a0, $a0, -0x2770
    ctx->r4 = ADD32(ctx->r4, -0X2770);
    // 0x80072C10: jal         0x8008AE20
    // 0x80072C14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_27;
    // 0x80072C14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_27:
    // 0x80072C18: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072C1C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072C20: addiu       $a1, $a1, -0x2738
    ctx->r5 = ADD32(ctx->r5, -0X2738);
    // 0x80072C24: addiu       $a0, $a0, -0x2750
    ctx->r4 = ADD32(ctx->r4, -0X2750);
    // 0x80072C28: jal         0x8008AE20
    // 0x80072C2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_28;
    // 0x80072C2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_28:
    // 0x80072C30: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072C34: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072C38: addiu       $a1, $a1, -0x2718
    ctx->r5 = ADD32(ctx->r5, -0X2718);
    // 0x80072C3C: addiu       $a0, $a0, -0x2730
    ctx->r4 = ADD32(ctx->r4, -0X2730);
    // 0x80072C40: jal         0x8008AE20
    // 0x80072C44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_29;
    // 0x80072C44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_29:
    // 0x80072C48: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072C4C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072C50: addiu       $a1, $a1, -0x26F8
    ctx->r5 = ADD32(ctx->r5, -0X26F8);
    // 0x80072C54: addiu       $a0, $a0, -0x2710
    ctx->r4 = ADD32(ctx->r4, -0X2710);
    // 0x80072C58: jal         0x8008AE20
    // 0x80072C5C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_30;
    // 0x80072C5C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_30:
    // 0x80072C60: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072C64: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072C68: addiu       $a1, $a1, -0x26B8
    ctx->r5 = ADD32(ctx->r5, -0X26B8);
    // 0x80072C6C: addiu       $a0, $a0, -0x26D0
    ctx->r4 = ADD32(ctx->r4, -0X26D0);
    // 0x80072C70: jal         0x8008AE20
    // 0x80072C74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_31;
    // 0x80072C74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_31:
    // 0x80072C78: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072C7C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072C80: addiu       $a1, $a1, -0x59C8
    ctx->r5 = ADD32(ctx->r5, -0X59C8);
    // 0x80072C84: addiu       $a0, $a0, -0x59E0
    ctx->r4 = ADD32(ctx->r4, -0X59E0);
    // 0x80072C88: jal         0x8008AE20
    // 0x80072C8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_32;
    // 0x80072C8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_32:
    // 0x80072C90: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072C94: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072C98: addiu       $a1, $a1, -0x58F0
    ctx->r5 = ADD32(ctx->r5, -0X58F0);
    // 0x80072C9C: addiu       $a0, $a0, -0x5908
    ctx->r4 = ADD32(ctx->r4, -0X5908);
    // 0x80072CA0: jal         0x8008AE20
    // 0x80072CA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_33;
    // 0x80072CA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_33:
    // 0x80072CA8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072CAC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072CB0: addiu       $a1, $a1, -0x59A8
    ctx->r5 = ADD32(ctx->r5, -0X59A8);
    // 0x80072CB4: addiu       $a0, $a0, -0x59C0
    ctx->r4 = ADD32(ctx->r4, -0X59C0);
    // 0x80072CB8: jal         0x8008AE20
    // 0x80072CBC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_34;
    // 0x80072CBC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_34:
    // 0x80072CC0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072CC4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072CC8: addiu       $a1, $a1, -0x5910
    ctx->r5 = ADD32(ctx->r5, -0X5910);
    // 0x80072CCC: addiu       $a0, $a0, -0x5928
    ctx->r4 = ADD32(ctx->r4, -0X5928);
    // 0x80072CD0: jal         0x8008AE20
    // 0x80072CD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_35;
    // 0x80072CD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_35:
    // 0x80072CD8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072CDC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072CE0: addiu       $a1, $a1, -0x5950
    ctx->r5 = ADD32(ctx->r5, -0X5950);
    // 0x80072CE4: addiu       $a0, $a0, -0x5968
    ctx->r4 = ADD32(ctx->r4, -0X5968);
    // 0x80072CE8: jal         0x8008AE20
    // 0x80072CEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_36;
    // 0x80072CEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_36:
    // 0x80072CF0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072CF4: addiu       $a1, $a1, -0x5968
    ctx->r5 = ADD32(ctx->r5, -0X5968);
    // 0x80072CF8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80072CFC: jal         0x80089D70
    // 0x80072D00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_37;
    // 0x80072D00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_37:
    // 0x80072D04: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072D08: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072D0C: addiu       $a1, $a1, -0x5930
    ctx->r5 = ADD32(ctx->r5, -0X5930);
    // 0x80072D10: addiu       $a0, $a0, -0x5948
    ctx->r4 = ADD32(ctx->r4, -0X5948);
    // 0x80072D14: jal         0x8008AE20
    // 0x80072D18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_38;
    // 0x80072D18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_38:
    // 0x80072D1C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072D20: addiu       $a1, $a1, -0x5948
    ctx->r5 = ADD32(ctx->r5, -0X5948);
    // 0x80072D24: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80072D28: jal         0x80089D70
    // 0x80072D2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_39;
    // 0x80072D2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_39:
    // 0x80072D30: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80072D34: lui         $t2, 0x800B
    ctx->r10 = S32(0X800B << 16);
    // 0x80072D38: addiu       $s0, $s0, -0x4290
    ctx->r16 = ADD32(ctx->r16, -0X4290);
    // 0x80072D3C: addiu       $t2, $t2, 0x1DEC
    ctx->r10 = ADD32(ctx->r10, 0X1DEC);
    // 0x80072D40: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072D44: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072D48: addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
    // 0x80072D4C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80072D50: addiu       $a1, $a1, -0x4590
    ctx->r5 = ADD32(ctx->r5, -0X4590);
    // 0x80072D54: addiu       $a0, $a0, -0x3270
    ctx->r4 = ADD32(ctx->r4, -0X3270);
    // 0x80072D58: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80072D5C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80072D60: jal         0x80081910
    // 0x80072D64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_40;
    // 0x80072D64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_40:
    // 0x80072D68: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072D6C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80072D70: addiu       $t3, $zero, 0x16
    ctx->r11 = ADD32(0, 0X16);
    // 0x80072D74: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80072D78: addiu       $a2, $a2, 0x2668
    ctx->r6 = ADD32(ctx->r6, 0X2668);
    // 0x80072D7C: addiu       $a0, $a0, -0x3020
    ctx->r4 = ADD32(ctx->r4, -0X3020);
    // 0x80072D80: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80072D84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80072D88: jal         0x80085B10
    // 0x80072D8C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    osCreateThread_recomp(rdram, ctx);
        goto after_41;
    // 0x80072D8C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_41:
    // 0x80072D90: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80072D94: lui         $t5, 0x800B
    ctx->r13 = S32(0X800B << 16);
    // 0x80072D98: addiu       $s0, $s0, -0x3F90
    ctx->r16 = ADD32(ctx->r16, -0X3F90);
    // 0x80072D9C: addiu       $t5, $t5, 0x1DF4
    ctx->r13 = ADD32(ctx->r13, 0X1DF4);
    // 0x80072DA0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072DA4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072DA8: addiu       $t4, $zero, 0x100
    ctx->r12 = ADD32(0, 0X100);
    // 0x80072DAC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80072DB0: addiu       $a1, $a1, -0x4290
    ctx->r5 = ADD32(ctx->r5, -0X4290);
    // 0x80072DB4: addiu       $a0, $a0, -0x3250
    ctx->r4 = ADD32(ctx->r4, -0X3250);
    // 0x80072DB8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80072DBC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80072DC0: jal         0x80081910
    // 0x80072DC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_42;
    // 0x80072DC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_42:
    // 0x80072DC8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072DCC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80072DD0: addiu       $t6, $zero, 0x15
    ctx->r14 = ADD32(0, 0X15);
    // 0x80072DD4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80072DD8: addiu       $a2, $a2, 0x27EC
    ctx->r6 = ADD32(ctx->r6, 0X27EC);
    // 0x80072DDC: addiu       $a0, $a0, -0x2E70
    ctx->r4 = ADD32(ctx->r4, -0X2E70);
    // 0x80072DE0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80072DE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80072DE8: jal         0x80085B10
    // 0x80072DEC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    osCreateThread_recomp(rdram, ctx);
        goto after_43;
    // 0x80072DEC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_43:
    // 0x80072DF0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80072DF4: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x80072DF8: addiu       $s0, $s0, -0x3990
    ctx->r16 = ADD32(ctx->r16, -0X3990);
    // 0x80072DFC: addiu       $t8, $t8, 0x1DFC
    ctx->r24 = ADD32(ctx->r24, 0X1DFC);
    // 0x80072E00: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072E04: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072E08: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x80072E0C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80072E10: addiu       $a1, $a1, -0x3F90
    ctx->r5 = ADD32(ctx->r5, -0X3F90);
    // 0x80072E14: addiu       $a0, $a0, -0x3230
    ctx->r4 = ADD32(ctx->r4, -0X3230);
    // 0x80072E18: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80072E1C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80072E20: jal         0x80081910
    // 0x80072E24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_44;
    // 0x80072E24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_44:
    // 0x80072E28: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072E2C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80072E30: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x80072E34: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80072E38: addiu       $a2, $a2, 0x1FF0
    ctx->r6 = ADD32(ctx->r6, 0X1FF0);
    // 0x80072E3C: addiu       $a0, $a0, -0x2CC0
    ctx->r4 = ADD32(ctx->r4, -0X2CC0);
    // 0x80072E40: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80072E44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80072E48: jal         0x80085B10
    // 0x80072E4C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    osCreateThread_recomp(rdram, ctx);
        goto after_45;
    // 0x80072E4C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_45:
    // 0x80072E50: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80072E54: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x80072E58: addiu       $s0, $s0, -0x4590
    ctx->r16 = ADD32(ctx->r16, -0X4590);
    // 0x80072E5C: addiu       $t1, $t1, 0x1E04
    ctx->r9 = ADD32(ctx->r9, 0X1E04);
    // 0x80072E60: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072E64: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072E68: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
    // 0x80072E6C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80072E70: addiu       $a1, $a1, -0x4D90
    ctx->r5 = ADD32(ctx->r5, -0X4D90);
    // 0x80072E74: addiu       $a0, $a0, -0x3290
    ctx->r4 = ADD32(ctx->r4, -0X3290);
    // 0x80072E78: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80072E7C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80072E80: jal         0x80081910
    // 0x80072E84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_46;
    // 0x80072E84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_46:
    // 0x80072E88: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072E8C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80072E90: addiu       $t2, $zero, 0xD
    ctx->r10 = ADD32(0, 0XD);
    // 0x80072E94: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80072E98: addiu       $a2, $a2, 0x1E2C
    ctx->r6 = ADD32(ctx->r6, 0X1E2C);
    // 0x80072E9C: addiu       $a0, $a0, -0x31D0
    ctx->r4 = ADD32(ctx->r4, -0X31D0);
    // 0x80072EA0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80072EA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80072EA8: jal         0x80085B10
    // 0x80072EAC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    osCreateThread_recomp(rdram, ctx);
        goto after_47;
    // 0x80072EAC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_47:
    // 0x80072EB0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80072EB4: lui         $t4, 0x800B
    ctx->r12 = S32(0X800B << 16);
    // 0x80072EB8: addiu       $s0, $s0, -0x3590
    ctx->r16 = ADD32(ctx->r16, -0X3590);
    // 0x80072EBC: addiu       $t4, $t4, 0x1E0C
    ctx->r12 = ADD32(ctx->r12, 0X1E0C);
    // 0x80072EC0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072EC4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072EC8: addiu       $t3, $zero, 0x100
    ctx->r11 = ADD32(0, 0X100);
    // 0x80072ECC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80072ED0: addiu       $a1, $a1, -0x3990
    ctx->r5 = ADD32(ctx->r5, -0X3990);
    // 0x80072ED4: addiu       $a0, $a0, -0x3210
    ctx->r4 = ADD32(ctx->r4, -0X3210);
    // 0x80072ED8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80072EDC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80072EE0: jal         0x80081910
    // 0x80072EE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_48;
    // 0x80072EE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_48:
    // 0x80072EE8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072EEC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80072EF0: addiu       $t5, $zero, 0x13
    ctx->r13 = ADD32(0, 0X13);
    // 0x80072EF4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80072EF8: addiu       $a2, $a2, 0x2320
    ctx->r6 = ADD32(ctx->r6, 0X2320);
    // 0x80072EFC: addiu       $a0, $a0, -0x2B10
    ctx->r4 = ADD32(ctx->r4, -0X2B10);
    // 0x80072F00: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80072F04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80072F08: jal         0x80085B10
    // 0x80072F0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    osCreateThread_recomp(rdram, ctx);
        goto after_49;
    // 0x80072F0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_49:
    // 0x80072F10: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80072F14: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80072F18: addiu       $s0, $s0, -0x3290
    ctx->r16 = ADD32(ctx->r16, -0X3290);
    // 0x80072F1C: addiu       $t7, $t7, 0x1E14
    ctx->r15 = ADD32(ctx->r15, 0X1E14);
    // 0x80072F20: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072F24: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80072F28: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x80072F2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80072F30: addiu       $a1, $a1, -0x3590
    ctx->r5 = ADD32(ctx->r5, -0X3590);
    // 0x80072F34: addiu       $a0, $a0, -0x31F0
    ctx->r4 = ADD32(ctx->r4, -0X31F0);
    // 0x80072F38: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80072F3C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80072F40: jal         0x80081910
    // 0x80072F44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_50;
    // 0x80072F44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_50:
    // 0x80072F48: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072F4C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80072F50: addiu       $t8, $zero, 0x11
    ctx->r24 = ADD32(0, 0X11);
    // 0x80072F54: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80072F58: addiu       $a2, $a2, 0x1C94
    ctx->r6 = ADD32(ctx->r6, 0X1C94);
    // 0x80072F5C: addiu       $a0, $a0, -0x2960
    ctx->r4 = ADD32(ctx->r4, -0X2960);
    // 0x80072F60: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80072F64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80072F68: jal         0x80085B10
    // 0x80072F6C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    osCreateThread_recomp(rdram, ctx);
        goto after_51;
    // 0x80072F6C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_51:
    // 0x80072F70: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80072F74: addiu       $s0, $s0, -0x5818
    ctx->r16 = ADD32(ctx->r16, -0X5818);
L_80072F78:
    // 0x80072F78: jal         0x80071C60
    // 0x80072F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80071C60(rdram, ctx);
        goto after_52;
    // 0x80072F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x80072F80: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80072F84: addiu       $t9, $t9, -0x4D98
    ctx->r25 = ADD32(ctx->r25, -0X4D98);
    // 0x80072F88: addiu       $s0, $s0, 0xA8
    ctx->r16 = ADD32(ctx->r16, 0XA8);
    // 0x80072F8C: bne         $s0, $t9, L_80072F78
    if (ctx->r16 != ctx->r25) {
        // 0x80072F90: nop
    
            goto L_80072F78;
    }
    // 0x80072F90: nop

    // 0x80072F94: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072F98: jal         0x80090CC0
    // 0x80072F9C: addiu       $a0, $a0, -0x3020
    ctx->r4 = ADD32(ctx->r4, -0X3020);
    osStartThread_recomp(rdram, ctx);
        goto after_53;
    // 0x80072F9C: addiu       $a0, $a0, -0x3020
    ctx->r4 = ADD32(ctx->r4, -0X3020);
    after_53:
    // 0x80072FA0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072FA4: jal         0x80090CC0
    // 0x80072FA8: addiu       $a0, $a0, -0x2E70
    ctx->r4 = ADD32(ctx->r4, -0X2E70);
    osStartThread_recomp(rdram, ctx);
        goto after_54;
    // 0x80072FA8: addiu       $a0, $a0, -0x2E70
    ctx->r4 = ADD32(ctx->r4, -0X2E70);
    after_54:
    // 0x80072FAC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072FB0: jal         0x80090CC0
    // 0x80072FB4: addiu       $a0, $a0, -0x31D0
    ctx->r4 = ADD32(ctx->r4, -0X31D0);
    osStartThread_recomp(rdram, ctx);
        goto after_55;
    // 0x80072FB4: addiu       $a0, $a0, -0x31D0
    ctx->r4 = ADD32(ctx->r4, -0X31D0);
    after_55:
    // 0x80072FB8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072FBC: jal         0x80090CC0
    // 0x80072FC0: addiu       $a0, $a0, -0x2CC0
    ctx->r4 = ADD32(ctx->r4, -0X2CC0);
    osStartThread_recomp(rdram, ctx);
        goto after_56;
    // 0x80072FC0: addiu       $a0, $a0, -0x2CC0
    ctx->r4 = ADD32(ctx->r4, -0X2CC0);
    after_56:
    // 0x80072FC4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072FC8: jal         0x80090CC0
    // 0x80072FCC: addiu       $a0, $a0, -0x2B10
    ctx->r4 = ADD32(ctx->r4, -0X2B10);
    osStartThread_recomp(rdram, ctx);
        goto after_57;
    // 0x80072FCC: addiu       $a0, $a0, -0x2B10
    ctx->r4 = ADD32(ctx->r4, -0X2B10);
    after_57:
    // 0x80072FD0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072FD4: jal         0x80090CC0
    // 0x80072FD8: addiu       $a0, $a0, -0x2960
    ctx->r4 = ADD32(ctx->r4, -0X2960);
    osStartThread_recomp(rdram, ctx);
        goto after_58;
    // 0x80072FD8: addiu       $a0, $a0, -0x2960
    ctx->r4 = ADD32(ctx->r4, -0X2960);
    after_58:
    // 0x80072FDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80072FE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80072FE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80072FE8: jr          $ra
    // 0x80072FEC: nop

    return;
    // 0x80072FEC: nop

;}
RECOMP_FUNC void func_8043DCF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DCF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043DCF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043DCFC: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
    // 0x8043DD00: beql        $v0, $zero, L_8043DD1C
    if (ctx->r2 == 0) {
        // 0x8043DD04: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8043DD1C;
    }
    goto skip_0;
    // 0x8043DD04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8043DD08: jalr        $v0
    // 0x8043DD0C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8043DD0C: nop

    after_0:
    // 0x8043DD10: b           L_8043DD20
    // 0x8043DD14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8043DD20;
    // 0x8043DD14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043DD18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043DD1C:
    // 0x8043DD1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043DD20:
    // 0x8043DD20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043DD24: jr          $ra
    // 0x8043DD28: nop

    return;
    // 0x8043DD28: nop

;}
RECOMP_FUNC void func_80031DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031DE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031DEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031DF0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80031DF4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80031DF8: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031DFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80031E00: jal         0x800310A0
    // 0x80031E04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x80031E04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80031E08: jal         0x80021A44
    // 0x80031E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80021A44(rdram, ctx);
        goto after_1;
    // 0x80031E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80031E10: lw          $t6, 0x78($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X78);
    // 0x80031E14: beql        $t6, $zero, L_80031E50
    if (ctx->r14 == 0) {
        // 0x80031E18: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_80031E50;
    }
    goto skip_0;
    // 0x80031E18: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_0:
    // 0x80031E1C: lw          $v0, 0xC0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC0);
    // 0x80031E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80031E24: bne         $v0, $zero, L_80031E3C
    if (ctx->r2 != 0) {
        // 0x80031E28: nop
    
            goto L_80031E3C;
    }
    // 0x80031E28: nop

    // 0x80031E2C: jal         0x800310D0
    // 0x80031E30: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800310D0(rdram, ctx);
        goto after_2;
    // 0x80031E30: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80031E34: b           L_80031E9C
    // 0x80031E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80031E9C;
    // 0x80031E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80031E3C:
    // 0x80031E3C: jalr        $v0
    // 0x80031E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x80031E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80031E44: b           L_80031E98
    // 0x80031E48: sw          $zero, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = 0;
        goto L_80031E98;
    // 0x80031E48: sw          $zero, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = 0;
    // 0x80031E4C: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_80031E50:
    // 0x80031E50: bne         $v0, $zero, L_80031E68
    if (ctx->r2 != 0) {
        // 0x80031E54: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80031E68;
    }
    // 0x80031E54: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80031E58: jal         0x80028220
    // 0x80031E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028220(rdram, ctx);
        goto after_4;
    // 0x80031E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80031E60: b           L_80031E6C
    // 0x80031E64: sw          $v0, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->r2;
        goto L_80031E6C;
    // 0x80031E64: sw          $v0, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->r2;
L_80031E68:
    // 0x80031E68: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
L_80031E6C:
    // 0x80031E6C: jal         0x80065954
    // 0x80031E70: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    func_80065954(rdram, ctx);
        goto after_5;
    // 0x80031E70: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    after_5:
    // 0x80031E74: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80031E78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80031E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80031E80: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80031E84: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80031E88: jal         0x80041214
    // 0x80031E8C: nop

    func_80041214(rdram, ctx);
        goto after_6;
    // 0x80031E8C: nop

    after_6:
    // 0x80031E90: jal         0x80023EA0
    // 0x80031E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80023EA0(rdram, ctx);
        goto after_7;
    // 0x80031E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80031E98:
    // 0x80031E98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80031E9C:
    // 0x80031E9C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80031EA0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80031EA4: jr          $ra
    // 0x80031EA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80031EA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80067E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067E78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067E80: jal         0x80067BBC
    // 0x80067E84: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80067E84: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_0:
    // 0x80067E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067E8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067E90: jr          $ra
    // 0x80067E94: nop

    return;
    // 0x80067E94: nop

;}
RECOMP_FUNC void func_80463A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80463A64: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80463A68: lui         $t6, 0x8046
    ctx->r14 = S32(RELOC_HI16(122, 0X2DFC) << 16);
    // 0x80463A6C: addiu       $t6, $t6, 0x338C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(122, 0X2DFC));
    // 0x80463A70: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80463A74: jr          $ra
    // 0x80463A78: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80463A78: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80058D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058D2C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80058D30: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80058D34: lw          $t6, 0x478($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X478);
    // 0x80058D38: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80058D3C: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80058D40: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80058D44: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80058D48: lw          $t7, 0x478($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X478);
    // 0x80058D4C: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80058D50: lwc1        $f16, 0x4($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80058D54: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80058D58: jr          $ra
    // 0x80058D5C: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x80058D5C: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_80554F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80554F80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80554F84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80554F88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80554F8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80554F90: lh          $t6, 0x1F0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1F0);
    // 0x80554F94: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80554F98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80554F9C: bnel        $t6, $at, L_80554FCC
    if (ctx->r14 != ctx->r1) {
        // 0x80554FA0: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_80554FCC;
    }
    goto skip_0;
    // 0x80554FA0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x80554FA4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80554FA8: jal         0x80067BBC
    // 0x80554FAC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80554FAC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x80554FB0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80554FB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80554FB8: jal         0x80067F78
    // 0x80554FBC: lw          $a0, 0x554($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X554);
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80554FBC: lw          $a0, 0x554($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X554);
    after_1:
    // 0x80554FC0: b           L_80554FE8
    // 0x80554FC4: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_80554FE8;
    // 0x80554FC4: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x80554FC8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_80554FCC:
    // 0x80554FCC: jal         0x80067BBC
    // 0x80554FD0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80554FD0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80554FD4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80554FD8: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80554FDC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80554FE0: jal         0x800678F0
    // 0x80554FE4: lw          $a0, 0x554($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X554);
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x80554FE4: lw          $a0, 0x554($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X554);
    after_3:
L_80554FE8:
    // 0x80554FE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80554FEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80554FF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80554FF4: jr          $ra
    // 0x80554FF8: nop

    return;
    // 0x80554FF8: nop

;}
RECOMP_FUNC void func_8057DA4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057DA4C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8057DA50: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8057DA54: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8057DA58: lui         $t8, 0x8058
    ctx->r24 = S32(RELOC_HI16(390, 0X388) << 16);
    // 0x8057DA5C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8057DA60: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8057DA64: lw          $t8, -0x2538($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(390, 0X388));
    // 0x8057DA68: jr          $ra
    // 0x8057DA6C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x8057DA6C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8079997C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079997C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80799980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799984: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80799988: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8079998C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80799990: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80799994: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80799998: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8079999C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807999A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x807999A4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x807999A8: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x807999AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807999B0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807999B4: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x807999B8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x807999BC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x807999C0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x807999C4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x807999C8: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x807999CC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x807999D0: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x807999D4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x807999D8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x807999DC: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x807999E0: jalr        $t9
    // 0x807999E4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x807999E4: nop

    after_0:
    // 0x807999E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807999EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x807999F0: jr          $ra
    // 0x807999F4: nop

    return;
    // 0x807999F4: nop

;}
RECOMP_FUNC void func_806747A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806747A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806747AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806747B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806747B4: jal         0x80045A34
    // 0x806747B8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806747B8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x806747BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806747C0: bne         $v0, $zero, L_806747D0
    if (ctx->r2 != 0) {
        // 0x806747C4: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_806747D0;
    }
    // 0x806747C4: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806747C8: b           L_806747DC
    // 0x806747CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806747DC;
    // 0x806747CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806747D0:
    // 0x806747D0: jal         0x8067478C
    // 0x806747D4: nop

    func_8067478C(rdram, ctx);
        goto after_1;
    // 0x806747D4: nop

    after_1:
    // 0x806747D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806747DC:
    // 0x806747DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806747E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806747E4: jr          $ra
    // 0x806747E8: nop

    return;
    // 0x806747E8: nop

;}
RECOMP_FUNC void func_805C954C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C954C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x805C9550: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C9554: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C9558: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C955C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C9560: jal         0x8004700C
    // 0x805C9564: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805C9564: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_0:
    // 0x805C9568: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x805C956C: beq         $v0, $zero, L_805C9764
    if (ctx->r2 == 0) {
        // 0x805C9570: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_805C9764;
    }
    // 0x805C9570: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x805C9574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9578: jal         0x805C6A70
    // 0x805C957C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_805C6A70(rdram, ctx);
        goto after_1;
    // 0x805C957C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_1:
    // 0x805C9580: beq         $v0, $zero, L_805C9618
    if (ctx->r2 == 0) {
        // 0x805C9584: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_805C9618;
    }
    // 0x805C9584: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x805C9588: lw          $t6, 0x44($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X44);
    // 0x805C958C: bnel        $t6, $zero, L_805C961C
    if (ctx->r14 != 0) {
        // 0x805C9590: addiu       $a3, $s0, 0xC4
        ctx->r7 = ADD32(ctx->r16, 0XC4);
            goto L_805C961C;
    }
    goto skip_0;
    // 0x805C9590: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x805C9594: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805C9598: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x805C959C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805C95A0: nop

    // 0x805C95A4: bc1fl       L_805C961C
    if (!c1cs) {
        // 0x805C95A8: addiu       $a3, $s0, 0xC4
        ctx->r7 = ADD32(ctx->r16, 0XC4);
            goto L_805C961C;
    }
    goto skip_1;
    // 0x805C95A8: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    skip_1:
    // 0x805C95AC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805C95B0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x805C95B4: jal         0x80067BBC
    // 0x805C95B8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x805C95B8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_2:
    // 0x805C95BC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x805C95C0: jal         0x80067818
    // 0x805C95C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x805C95C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x805C95C8: lui         $at, 0x439C
    ctx->r1 = S32(0X439C << 16);
    // 0x805C95CC: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C95D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805C95D4: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x805C95D8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x805C95DC: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x805C95E0: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x805C95E4: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x805C95E8: lui         $a1, 0x805D
    ctx->r5 = S32(RELOC_HI16(447, 0X3B34) << 16);
    // 0x805C95EC: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x805C95F0: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x805C95F4: addiu       $a1, $a1, -0x5FDC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(447, 0X3B34));
    // 0x805C95F8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x805C95FC: lw          $t9, 0x4C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4C);
    // 0x805C9600: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805C9604: jalr        $t9
    // 0x805C9608: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x805C9608: nop

    after_4:
    // 0x805C960C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x805C9610: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805C9614: sw          $t0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r8;
L_805C9618:
    // 0x805C9618: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
L_805C961C:
    // 0x805C961C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x805C9620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9624: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x805C9628: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x805C962C: jal         0x805C70B0
    // 0x805C9630: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_805C70B0(rdram, ctx);
        goto after_5;
    // 0x805C9630: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_5:
    // 0x805C9634: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805C9638: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x805C963C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x805C9640: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x805C9644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9648: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x805C964C: nop

    // 0x805C9650: bc1fl       L_805C9744
    if (!c1cs) {
        // 0x805C9654: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_805C9744;
    }
    goto skip_2;
    // 0x805C9654: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_2:
    // 0x805C9658: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x805C965C: jal         0x805C6A70
    // 0x805C9660: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_805C6A70(rdram, ctx);
        goto after_6;
    // 0x805C9660: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_6:
    // 0x805C9664: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x805C9668: beq         $v0, $zero, L_805C9740
    if (ctx->r2 == 0) {
        // 0x805C966C: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_805C9740;
    }
    // 0x805C966C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805C9670: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
    // 0x805C9674: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x805C9678: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x805C967C: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x805C9680: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x805C9684: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(447, 0X3C00) << 16);
    // 0x805C9688: lwc1        $f6, -0x5F10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(447, 0X3C00));
    // 0x805C968C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x805C9690: lui         $at, 0x43B5
    ctx->r1 = S32(0X43B5 << 16);
    // 0x805C9694: swc1        $f6, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f6.u32l;
    // 0x805C9698: lw          $t1, 0x40($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X40);
    // 0x805C969C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x805C96A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C96A4: bne         $t1, $zero, L_805C9720
    if (ctx->r9 != 0) {
        // 0x805C96A8: nop
    
            goto L_805C9720;
    }
    // 0x805C96A8: nop

    // 0x805C96AC: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x805C96B0: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x805C96B4: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x805C96B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805C96BC: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805C96C0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x805C96C4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805C96C8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x805C96CC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x805C96D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x805C96D4: bc1fl       L_805C96E8
    if (!c1cs) {
        // 0x805C96D8: sw          $t3, 0x38($v1)
        MEM_W(0X38, ctx->r3) = ctx->r11;
            goto L_805C96E8;
    }
    goto skip_3;
    // 0x805C96D8: sw          $t3, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r11;
    skip_3:
    // 0x805C96DC: b           L_805C96E8
    // 0x805C96E0: sw          $t2, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r10;
        goto L_805C96E8;
    // 0x805C96E0: sw          $t2, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r10;
    // 0x805C96E4: sw          $t3, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r11;
L_805C96E8:
    // 0x805C96E8: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805C96EC: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x805C96F0: nop

    // 0x805C96F4: bc1f        L_805C9700
    if (!c1cs) {
        // 0x805C96F8: nop
    
            goto L_805C9700;
    }
    // 0x805C96F8: nop

    // 0x805C96FC: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
L_805C9700:
    // 0x805C9700: jal         0x805C74C8
    // 0x805C9704: swc1        $f16, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f16.u32l;
    func_805C74C8(rdram, ctx);
        goto after_7;
    // 0x805C9704: swc1        $f16, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f16.u32l;
    after_7:
    // 0x805C9708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C970C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C9710: jal         0x805C9D10
    // 0x805C9714: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_805C9D10(rdram, ctx);
        goto after_8;
    // 0x805C9714: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_8:
    // 0x805C9718: b           L_805C9768
    // 0x805C971C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C9768;
    // 0x805C971C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C9720:
    // 0x805C9720: jal         0x8002FCBC
    // 0x805C9724: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_8002FCBC(rdram, ctx);
        goto after_9;
    // 0x805C9724: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_9:
    // 0x805C9728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C972C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C9730: jal         0x805C9D10
    // 0x805C9734: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_805C9D10(rdram, ctx);
        goto after_10;
    // 0x805C9734: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x805C9738: b           L_805C9768
    // 0x805C973C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C9768;
    // 0x805C973C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C9740:
    // 0x805C9740: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_805C9744:
    // 0x805C9744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805C9748: jal         0x80048F84
    // 0x805C974C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_11;
    // 0x805C974C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_11:
    // 0x805C9750: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805C9754: jal         0x80048F84
    // 0x805C9758: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_12;
    // 0x805C9758: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x805C975C: jal         0x805C7ABC
    // 0x805C9760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7ABC(rdram, ctx);
        goto after_13;
    // 0x805C9760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
L_805C9764:
    // 0x805C9764: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C9768:
    // 0x805C9768: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C976C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x805C9770: jr          $ra
    // 0x805C9774: nop

    return;
    // 0x805C9774: nop

;}
RECOMP_FUNC void func_806D9590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D9590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D9594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D9598: jal         0x80047090
    // 0x806D959C: addiu       $a0, $zero, 0x45B9
    ctx->r4 = ADD32(0, 0X45B9);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806D959C: addiu       $a0, $zero, 0x45B9
    ctx->r4 = ADD32(0, 0X45B9);
    after_0:
    // 0x806D95A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806D95A4: lui         $at, 0x45B9
    ctx->r1 = S32(0X45B9 << 16);
    // 0x806D95A8: ori         $at, $at, 0x2400
    ctx->r1 = ctx->r1 | 0X2400;
    // 0x806D95AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x806D95B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x806D95B4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x806D95B8: jal         0x8004613C
    // 0x806D95BC: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806D95BC: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x806D95C0: bne         $v0, $zero, L_806D95D0
    if (ctx->r2 != 0) {
        // 0x806D95C4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_806D95D0;
    }
    // 0x806D95C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x806D95C8: b           L_806D95D4
    // 0x806D95CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806D95D4;
    // 0x806D95CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D95D0:
    // 0x806D95D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_806D95D4:
    // 0x806D95D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D95D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D95DC: jr          $ra
    // 0x806D95E0: nop

    return;
    // 0x806D95E0: nop

    // 0x806D95E4: nop

    // 0x806D95E8: nop

    // 0x806D95EC: nop

;}
RECOMP_FUNC void func_8040FCEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040FCEC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8040FCF0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8040FCF4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8040FCF8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8040FCFC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8040FD00: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8040FD04: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8040FD08: lui         $t1, 0x8041
    ctx->r9 = S32(RELOC_HI16(26, 0X2428) << 16);
    // 0x8040FD0C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8040FD10: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8040FD14: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8040FD18: lw          $t1, 0x1AA8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(26, 0X2428));
    // 0x8040FD1C: jr          $ra
    // 0x8040FD20: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8040FD20: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80048BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048BE8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80048BEC: sw          $a1, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->r5;
    // 0x80048BF0: addiu       $t6, $sp, 0x8
    ctx->r14 = ADD32(ctx->r29, 0X8);
    // 0x80048BF4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80048BF8: jr          $ra
    // 0x80048BFC: sw          $t8, 0x1DC($a0)
    MEM_W(0X1DC, ctx->r4) = ctx->r24;
    return;
    // 0x80048BFC: sw          $t8, 0x1DC($a0)
    MEM_W(0X1DC, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_804C62A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C62A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804C62AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C62B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804C62B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x804C62B8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x804C62BC: jal         0x80047090
    // 0x804C62C0: addiu       $a0, $zero, 0x412C
    ctx->r4 = ADD32(0, 0X412C);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804C62C0: addiu       $a0, $zero, 0x412C
    ctx->r4 = ADD32(0, 0X412C);
    after_0:
    // 0x804C62C4: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804C62C8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x804C62CC: beq         $v0, $at, L_804C636C
    if (ctx->r2 == ctx->r1) {
        // 0x804C62D0: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804C636C;
    }
    // 0x804C62D0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804C62D4: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x804C62D8: lui         $a0, 0x804C
    ctx->r4 = S32(RELOC_HI16(218, 0X550) << 16);
    // 0x804C62DC: lui         $at, 0x412C
    ctx->r1 = S32(0X412C << 16);
    // 0x804C62E0: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x804C62E4: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x804C62E8: or          $a1, $v1, $at
    ctx->r5 = ctx->r3 | ctx->r1;
    // 0x804C62EC: addiu       $a0, $a0, 0x64D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(218, 0X550));
    // 0x804C62F0: jal         0x80046804
    // 0x804C62F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x804C62F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x804C62F8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x804C62FC: beq         $v0, $zero, L_804C636C
    if (ctx->r2 == 0) {
        // 0x804C6300: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_804C636C;
    }
    // 0x804C6300: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804C6304: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x804C6308: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x804C630C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804C6310: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x804C6314: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x804C6318: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
    // 0x804C631C: lwc1        $f10, 0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X8);
    // 0x804C6320: swc1        $f0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->f0.u32l;
    // 0x804C6324: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x804C6328: swc1        $f10, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f10.u32l;
    // 0x804C632C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804C6330: swc1        $f0, 0xF8($a0)
    MEM_W(0XF8, ctx->r4) = ctx->f0.u32l;
    // 0x804C6334: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x804C6338: swc1        $f2, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f2.u32l;
    // 0x804C633C: swc1        $f2, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f2.u32l;
    // 0x804C6340: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804C6344: swc1        $f0, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->f0.u32l;
    // 0x804C6348: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x804C634C: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x804C6350: swc1        $f0, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f0.u32l;
    // 0x804C6354: swc1        $f2, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f2.u32l;
    // 0x804C6358: swc1        $f2, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f2.u32l;
    // 0x804C635C: jal         0x80044194
    // 0x804C6360: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x804C6360: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x804C6364: b           L_804C6370
    // 0x804C6368: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_804C6370;
    // 0x804C6368: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_804C636C:
    // 0x804C636C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C6370:
    // 0x804C6370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C6374: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804C6378: jr          $ra
    // 0x804C637C: nop

    return;
    // 0x804C637C: nop

;}
RECOMP_FUNC void func_8004924C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004924C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049254: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80049258: jal         0x8004921C
    // 0x8004925C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8004925C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80049260: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80049264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80049268: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004926C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80049270: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80049274: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80049278: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8004927C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80049280: jal         0x8004921C
    // 0x80049284: sh          $t7, 0x13C($a0)
    MEM_H(0X13C, ctx->r4) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80049284: sh          $t7, 0x13C($a0)
    MEM_H(0X13C, ctx->r4) = ctx->r15;
    after_1:
    // 0x80049288: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8004928C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80049290: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80049294: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80049298: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004929C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800492A0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800492A4: nop

    // 0x800492A8: sh          $t9, 0x13E($a0)
    MEM_H(0X13E, ctx->r4) = ctx->r25;
    // 0x800492AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800492B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800492B4: jr          $ra
    // 0x800492B8: nop

    return;
    // 0x800492B8: nop

    // 0x800492BC: nop

;}
RECOMP_FUNC void func_80445EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445EC8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80445ECC: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x80445ED0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80445ED4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80445ED8: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80445EDC: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80445EE0: sw          $t6, 0x6C9C($v1)
    MEM_W(0X6C9C, ctx->r3) = ctx->r14;
    // 0x80445EE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80445EE8: addiu       $t7, $zero, 0x1B6C
    ctx->r15 = ADD32(0, 0X1B6C);
    // 0x80445EEC: addiu       $t8, $zero, 0x1EF0
    ctx->r24 = ADD32(0, 0X1EF0);
    // 0x80445EF0: sw          $a1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r5;
    // 0x80445EF4: sw          $t7, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r15;
    // 0x80445EF8: sw          $t8, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r24;
    // 0x80445EFC: jr          $ra
    // 0x80445F00: swc1        $f4, 0x6AA0($v1)
    MEM_W(0X6AA0, ctx->r3) = ctx->f4.u32l;
    return;
    // 0x80445F00: swc1        $f4, 0x6AA0($v1)
    MEM_W(0X6AA0, ctx->r3) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_800613B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800613B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800613B8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800613BC: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800613C0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800613C4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800613C8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800613CC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800613D0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800613D4: lw          $s3, 0x4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X4);
    // 0x800613D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800613DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800613E0: lh          $s1, 0x184($s3)
    ctx->r17 = MEM_H(ctx->r19, 0X184);
    // 0x800613E4: addiu       $s2, $s3, 0x188
    ctx->r18 = ADD32(ctx->r19, 0X188);
    // 0x800613E8: beql        $s1, $zero, L_800614AC
    if (ctx->r17 == 0) {
        // 0x800613EC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800614AC;
    }
    goto skip_0;
    // 0x800613EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x800613F0: lwc1        $f22, 0xD60($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0XD60);
    // 0x800613F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800613F8: lwc1        $f20, 0xD64($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0XD64);
L_800613FC:
    // 0x800613FC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80061400: beq         $v1, $zero, L_800614A0
    if (ctx->r3 == 0) {
        // 0x80061404: nop
    
            goto L_800614A0;
    }
    // 0x80061404: nop

    // 0x80061408: sw          $v1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r3;
    // 0x8006140C: lw          $t6, 0x174($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X174);
    // 0x80061410: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80061414: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80061418: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8006141C: beq         $t6, $zero, L_800614A0
    if (ctx->r14 == 0) {
        // 0x80061420: sw          $t6, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->r14;
            goto L_800614A0;
    }
    // 0x80061420: sw          $t6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r14;
    // 0x80061424: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80061428: bne         $s3, $t7, L_800614A0
    if (ctx->r19 != ctx->r15) {
        // 0x8006142C: nop
    
            goto L_800614A0;
    }
    // 0x8006142C: nop

    // 0x80061430: lwc1        $f0, 0xC4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC4);
    // 0x80061434: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80061438: nop

    // 0x8006143C: bc1t        L_80061498
    if (c1cs) {
        // 0x80061440: nop
    
            goto L_80061498;
    }
    // 0x80061440: nop

    // 0x80061444: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80061448: nop

    // 0x8006144C: bc1t        L_80061498
    if (c1cs) {
        // 0x80061450: nop
    
            goto L_80061498;
    }
    // 0x80061450: nop

    // 0x80061454: lwc1        $f0, 0xC8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC8);
    // 0x80061458: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8006145C: nop

    // 0x80061460: bc1t        L_80061498
    if (c1cs) {
        // 0x80061464: nop
    
            goto L_80061498;
    }
    // 0x80061464: nop

    // 0x80061468: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8006146C: nop

    // 0x80061470: bc1t        L_80061498
    if (c1cs) {
        // 0x80061474: nop
    
            goto L_80061498;
    }
    // 0x80061474: nop

    // 0x80061478: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8006147C: andi        $t9, $t8, 0xF00
    ctx->r25 = ctx->r24 & 0XF00;
    // 0x80061480: bne         $t9, $zero, L_80061498
    if (ctx->r25 != 0) {
        // 0x80061484: nop
    
            goto L_80061498;
    }
    // 0x80061484: nop

    // 0x80061488: jal         0x800608D4
    // 0x8006148C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800608D4(rdram, ctx);
        goto after_0;
    // 0x8006148C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80061490: bne         $v0, $zero, L_800614A0
    if (ctx->r2 != 0) {
        // 0x80061494: nop
    
            goto L_800614A0;
    }
    // 0x80061494: nop

L_80061498:
    // 0x80061498: jal         0x8006112C
    // 0x8006149C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006112C(rdram, ctx);
        goto after_1;
    // 0x8006149C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_800614A0:
    // 0x800614A0: bne         $s1, $zero, L_800613FC
    if (ctx->r17 != 0) {
        // 0x800614A4: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800613FC;
    }
    // 0x800614A4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800614A8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800614AC:
    // 0x800614AC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800614B0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800614B4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800614B8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800614BC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800614C0: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800614C4: jr          $ra
    // 0x800614C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800614C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_806F6024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F6024: jr          $ra
    // 0x806F6028: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806F6028: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8043C310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043C310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043C314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043C318: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8043C31C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8043C320: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8043C324: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8043C328: jal         0x8043BC50
    // 0x8043C32C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_8043BC50(rdram, ctx);
        goto after_0;
    // 0x8043C32C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8043C330: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8043C334: jal         0x8043BD38
    // 0x8043C338: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8043BD38(rdram, ctx);
        goto after_1;
    // 0x8043C338: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8043C33C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8043C340: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8043C344: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8043C348: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8043C34C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8043C350: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8043C354: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8043C358: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8043C35C: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x8043C360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043C364: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043C368: jr          $ra
    // 0x8043C36C: nop

    return;
    // 0x8043C36C: nop

;}
RECOMP_FUNC void func_80048780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048780: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80048784: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80048788: addiu       $t9, $t9, -0x78E0
    ctx->r25 = ADD32(ctx->r25, -0X78E0);
    // 0x8004878C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80048790: sw          $t9, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r25;
    // 0x80048794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80048798: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8004879C: jr          $ra
    // 0x800487A0: sw          $t8, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r24;
    return;
    // 0x800487A0: sw          $t8, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8006106C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006106C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80061070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061074: jal         0x80060F6C
    // 0x80061078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80060F6C(rdram, ctx);
        goto after_0;
    // 0x80061078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006107C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80061080: lw          $v0, 0x3C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X3C);
    // 0x80061084: addiu       $a0, $v0, 0x48
    ctx->r4 = ADD32(ctx->r2, 0X48);
    // 0x80061088: jal         0x80065490
    // 0x8006108C: addiu       $a1, $v0, 0x90
    ctx->r5 = ADD32(ctx->r2, 0X90);
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x8006108C: addiu       $a1, $v0, 0x90
    ctx->r5 = ADD32(ctx->r2, 0X90);
    after_1:
    // 0x80061090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80061098: jr          $ra
    // 0x8006109C: nop

    return;
    // 0x8006109C: nop

;}
RECOMP_FUNC void func_80059040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059040: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80059044: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80059048: lw          $v0, 0x3F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X3F4);
    // 0x8005904C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059050: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059054: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80059058: lw          $t6, 0x478($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X478);
    // 0x8005905C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80059060: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80059064: lwc1        $f6, 0x38($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80059068: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8005906C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80059070: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80059074: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80059078: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8005907C: jal         0x80058F68
    // 0x80059080: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_80058F68(rdram, ctx);
        goto after_0;
    // 0x80059080: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80059084: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80059088: lw          $t7, -0x7D6C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D6C);
    // 0x8005908C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80059090: swc1        $f10, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f10.u32l;
    // 0x80059094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059098: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005909C: jr          $ra
    // 0x800590A0: nop

    return;
    // 0x800590A0: nop

;}
RECOMP_FUNC void pad_correct_stick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FC14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007FC18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FC1C: jal         0x8007FB98
    // 0x8007FC20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    pad_physical_stick_x(rdram, ctx);
        goto after_0;
    // 0x8007FC20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007FC24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007FC28: jal         0x8007FBA0
    // 0x8007FC2C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    pad_physical_stick_y(rdram, ctx);
        goto after_1;
    // 0x8007FC2C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8007FC30: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8007FC34: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8007FC38: bne         $at, $zero, L_8007FC58
    if (ctx->r1 != 0) {
        // 0x8007FC3C: slti        $at, $v1, 0x43
        ctx->r1 = SIGNED(ctx->r3) < 0X43 ? 1 : 0;
            goto L_8007FC58;
    }
    // 0x8007FC3C: slti        $at, $v1, 0x43
    ctx->r1 = SIGNED(ctx->r3) < 0X43 ? 1 : 0;
    // 0x8007FC40: beq         $at, $zero, L_8007FC50
    if (ctx->r1 == 0) {
        // 0x8007FC44: nop
    
            goto L_8007FC50;
    }
    // 0x8007FC44: nop

    // 0x8007FC48: b           L_8007FC80
    // 0x8007FC4C: addiu       $a1, $v1, -0x7
    ctx->r5 = ADD32(ctx->r3, -0X7);
        goto L_8007FC80;
    // 0x8007FC4C: addiu       $a1, $v1, -0x7
    ctx->r5 = ADD32(ctx->r3, -0X7);
L_8007FC50:
    // 0x8007FC50: b           L_8007FC80
    // 0x8007FC54: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
        goto L_8007FC80;
    // 0x8007FC54: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
L_8007FC58:
    // 0x8007FC58: slti        $at, $v1, -0x7
    ctx->r1 = SIGNED(ctx->r3) < -0X7 ? 1 : 0;
    // 0x8007FC5C: beq         $at, $zero, L_8007FC80
    if (ctx->r1 == 0) {
        // 0x8007FC60: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8007FC80;
    }
    // 0x8007FC60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007FC64: slti        $at, $v1, -0x42
    ctx->r1 = SIGNED(ctx->r3) < -0X42 ? 1 : 0;
    // 0x8007FC68: bne         $at, $zero, L_8007FC78
    if (ctx->r1 != 0) {
        // 0x8007FC6C: nop
    
            goto L_8007FC78;
    }
    // 0x8007FC6C: nop

    // 0x8007FC70: b           L_8007FC80
    // 0x8007FC74: addiu       $a1, $v1, 0x7
    ctx->r5 = ADD32(ctx->r3, 0X7);
        goto L_8007FC80;
    // 0x8007FC74: addiu       $a1, $v1, 0x7
    ctx->r5 = ADD32(ctx->r3, 0X7);
L_8007FC78:
    // 0x8007FC78: b           L_8007FC80
    // 0x8007FC7C: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
        goto L_8007FC80;
    // 0x8007FC7C: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
L_8007FC80:
    // 0x8007FC80: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8007FC84: bne         $at, $zero, L_8007FCA4
    if (ctx->r1 != 0) {
        // 0x8007FC88: slti        $at, $v0, 0x43
        ctx->r1 = SIGNED(ctx->r2) < 0X43 ? 1 : 0;
            goto L_8007FCA4;
    }
    // 0x8007FC88: slti        $at, $v0, 0x43
    ctx->r1 = SIGNED(ctx->r2) < 0X43 ? 1 : 0;
    // 0x8007FC8C: beq         $at, $zero, L_8007FC9C
    if (ctx->r1 == 0) {
        // 0x8007FC90: nop
    
            goto L_8007FC9C;
    }
    // 0x8007FC90: nop

    // 0x8007FC94: b           L_8007FCCC
    // 0x8007FC98: addiu       $a2, $v0, -0x7
    ctx->r6 = ADD32(ctx->r2, -0X7);
        goto L_8007FCCC;
    // 0x8007FC98: addiu       $a2, $v0, -0x7
    ctx->r6 = ADD32(ctx->r2, -0X7);
L_8007FC9C:
    // 0x8007FC9C: b           L_8007FCCC
    // 0x8007FCA0: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
        goto L_8007FCCC;
    // 0x8007FCA0: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
L_8007FCA4:
    // 0x8007FCA4: slti        $at, $v0, -0x7
    ctx->r1 = SIGNED(ctx->r2) < -0X7 ? 1 : 0;
    // 0x8007FCA8: beq         $at, $zero, L_8007FCCC
    if (ctx->r1 == 0) {
        // 0x8007FCAC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8007FCCC;
    }
    // 0x8007FCAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007FCB0: slti        $at, $v0, -0x42
    ctx->r1 = SIGNED(ctx->r2) < -0X42 ? 1 : 0;
    // 0x8007FCB4: bne         $at, $zero, L_8007FCC4
    if (ctx->r1 != 0) {
        // 0x8007FCB8: nop
    
            goto L_8007FCC4;
    }
    // 0x8007FCB8: nop

    // 0x8007FCBC: b           L_8007FCCC
    // 0x8007FCC0: addiu       $a2, $v0, 0x7
    ctx->r6 = ADD32(ctx->r2, 0X7);
        goto L_8007FCCC;
    // 0x8007FCC0: addiu       $a2, $v0, 0x7
    ctx->r6 = ADD32(ctx->r2, 0X7);
L_8007FCC4:
    // 0x8007FCC4: b           L_8007FCCC
    // 0x8007FCC8: addiu       $a2, $zero, -0x3C
    ctx->r6 = ADD32(0, -0X3C);
        goto L_8007FCCC;
    // 0x8007FCC8: addiu       $a2, $zero, -0x3C
    ctx->r6 = ADD32(0, -0X3C);
L_8007FCCC:
    // 0x8007FCCC: jal         0x8007FBA8
    // 0x8007FCD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    pad_set_logical_stick(rdram, ctx);
        goto after_2;
    // 0x8007FCD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8007FCD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FCD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007FCDC: jr          $ra
    // 0x8007FCE0: nop

    return;
    // 0x8007FCE0: nop

;}
RECOMP_FUNC void func_80044194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004419C: jal         0x80043830
    // 0x800441A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80043830(rdram, ctx);
        goto after_0;
    // 0x800441A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800441A4: bne         $v0, $zero, L_800441C4
    if (ctx->r2 != 0) {
        // 0x800441A8: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_800441C4;
    }
    // 0x800441A8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800441AC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800441B0: addiu       $a0, $a0, 0x410
    ctx->r4 = ADD32(ctx->r4, 0X410);
    // 0x800441B4: jal         0x80071380
    // 0x800441B8: addiu       $a1, $zero, 0x3BD
    ctx->r5 = ADD32(0, 0X3BD);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x800441B8: addiu       $a1, $zero, 0x3BD
    ctx->r5 = ADD32(0, 0X3BD);
    after_1:
    // 0x800441BC: b           L_80044204
    // 0x800441C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80044204;
    // 0x800441C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800441C4:
    // 0x800441C4: addiu       $a0, $a0, -0x77D4
    ctx->r4 = ADD32(ctx->r4, -0X77D4);
    // 0x800441C8: jal         0x80043D34
    // 0x800441CC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_80043D34(rdram, ctx);
        goto after_2;
    // 0x800441CC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800441D0: bne         $v0, $zero, L_800441F0
    if (ctx->r2 != 0) {
        // 0x800441D4: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_800441F0;
    }
    // 0x800441D4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800441D8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800441DC: addiu       $a0, $a0, 0x420
    ctx->r4 = ADD32(ctx->r4, 0X420);
    // 0x800441E0: jal         0x80071380
    // 0x800441E4: addiu       $a1, $zero, 0x3C9
    ctx->r5 = ADD32(0, 0X3C9);
    Fault_HungUp(rdram, ctx);
        goto after_3;
    // 0x800441E4: addiu       $a1, $zero, 0x3C9
    ctx->r5 = ADD32(0, 0X3C9);
    after_3:
    // 0x800441E8: b           L_80044204
    // 0x800441EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80044204;
    // 0x800441EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800441F0:
    // 0x800441F0: sb          $zero, 0x18($t6)
    MEM_B(0X18, ctx->r14) = 0;
    // 0x800441F4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800441F8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800441FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044200: sb          $t7, 0x17D($t8)
    MEM_B(0X17D, ctx->r24) = ctx->r15;
L_80044204:
    // 0x80044204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004420C: jr          $ra
    // 0x80044210: nop

    return;
    // 0x80044210: nop

;}
RECOMP_FUNC void func_8073C160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073C160: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(742, 0X684) << 16);
    // 0x8073C164: addiu       $v0, $v0, -0x381C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(742, 0X684));
    // 0x8073C168: jr          $ra
    // 0x8073C16C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8073C16C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8005B69C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B69C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005B6A0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005B6A4: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x8005B6A8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8005B6AC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8005B6B0: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8005B6B4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005B6B8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8005B6BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005B6C0: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // 0x8005B6C4: addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
    // 0x8005B6C8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8005B6CC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8005B6D0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8005B6D4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8005B6D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005B6DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005B6E0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8005B6E4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8005B6E8: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8005B6EC: jal         0x8005B54C
    // 0x8005B6F0: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    func_8005B54C(rdram, ctx);
        goto after_0;
    // 0x8005B6F0: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    after_0:
    // 0x8005B6F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B6F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8005B6FC: jr          $ra
    // 0x8005B700: nop

    return;
    // 0x8005B700: nop

;}
RECOMP_FUNC void func_807A6D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A6D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A6D10: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    // 0x807A6D14: beql        $a2, $zero, L_807A6D28
    if (ctx->r6 == 0) {
        // 0x807A6D18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807A6D28;
    }
    goto skip_0;
    // 0x807A6D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807A6D1C: jal         0x807A7138
    // 0x807A6D20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807A7138(rdram, ctx);
        goto after_0;
    // 0x807A6D20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x807A6D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A6D28:
    // 0x807A6D28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A6D2C: jr          $ra
    // 0x807A6D30: nop

    return;
    // 0x807A6D30: nop

;}
RECOMP_FUNC void func_806F1B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1B6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F1B70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F1B74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F1B78: jal         0x806F1644
    // 0x806F1B7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806F1644(rdram, ctx);
        goto after_0;
    // 0x806F1B7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806F1B80: jal         0x8004700C
    // 0x806F1B84: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x806F1B84: nop

    after_1:
    // 0x806F1B88: beq         $v0, $zero, L_806F1BA4
    if (ctx->r2 == 0) {
        // 0x806F1B8C: nop
    
            goto L_806F1BA4;
    }
    // 0x806F1B8C: nop

    // 0x806F1B90: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x806F1B94: bne         $s0, $t6, L_806F1BA4
    if (ctx->r16 != ctx->r14) {
        // 0x806F1B98: nop
    
            goto L_806F1BA4;
    }
    // 0x806F1B98: nop

    // 0x806F1B9C: jal         0x80060FE0
    // 0x806F1BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060FE0(rdram, ctx);
        goto after_2;
    // 0x806F1BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_806F1BA4:
    // 0x806F1BA4: jal         0x8005FE48
    // 0x806F1BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_3;
    // 0x806F1BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806F1BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F1BB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F1BB4: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x806F1BB8: jal         0x806F1F14
    // 0x806F1BBC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F1F14(rdram, ctx);
        goto after_4;
    // 0x806F1BBC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806F1BC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F1BC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F1BC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F1BCC: jr          $ra
    // 0x806F1BD0: nop

    return;
    // 0x806F1BD0: nop

;}
RECOMP_FUNC void func_8064CC1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064CC1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064CC20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064CC24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064CC28: jal         0x80045A34
    // 0x8064CC2C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8064CC2C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8064CC30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064CC34: bne         $v0, $zero, L_8064CC44
    if (ctx->r2 != 0) {
        // 0x8064CC38: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8064CC44;
    }
    // 0x8064CC38: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8064CC3C: b           L_8064CC50
    // 0x8064CC40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8064CC50;
    // 0x8064CC40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8064CC44:
    // 0x8064CC44: jal         0x8064CC04
    // 0x8064CC48: nop

    func_8064CC04(rdram, ctx);
        goto after_1;
    // 0x8064CC48: nop

    after_1:
    // 0x8064CC4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8064CC50:
    // 0x8064CC50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064CC54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064CC58: jr          $ra
    // 0x8064CC5C: nop

    return;
    // 0x8064CC5C: nop

;}
