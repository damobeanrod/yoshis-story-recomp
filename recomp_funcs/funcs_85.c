#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_807B0338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B0338: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B033C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B0340: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807B0344: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B0348: jal         0x807AFE94
    // 0x807B034C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_807AFE94(rdram, ctx);
        goto after_0;
    // 0x807B034C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x807B0350: jal         0x80064E84
    // 0x807B0354: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x807B0354: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x807B0358: lw          $v1, 0x13C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X13C);
    // 0x807B035C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x807B0360: beq         $v0, $zero, L_807B0374
    if (ctx->r2 == 0) {
        // 0x807B0364: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807B0374;
    }
    // 0x807B0364: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807B0368: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x807B036C: lw          $t7, 0x13C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X13C);
    // 0x807B0370: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
L_807B0374:
    // 0x807B0374: bnel        $v0, $zero, L_807B0394
    if (ctx->r2 != 0) {
        // 0x807B0378: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807B0394;
    }
    goto skip_0;
    // 0x807B0378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807B037C: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x807B0380: jal         0x80064E84
    // 0x807B0384: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x807B0384: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x807B0388: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    // 0x807B038C: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x807B0390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807B0394:
    // 0x807B0394: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B0398: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B039C: jr          $ra
    // 0x807B03A0: nop

    return;
    // 0x807B03A0: nop

;}
RECOMP_FUNC void func_807169C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807169C8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807169CC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x807169D0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x807169D4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x807169D8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x807169DC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x807169E0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x807169E4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x807169E8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x807169EC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x807169F0: jr          $ra
    // 0x807169F4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x807169F4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8073D33C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073D33C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8073D340: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073D344: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8073D348: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8073D34C: lwc1        $f20, 0x0($a1)
    ctx->f20.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8073D350: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8073D354: jal         0x80066DE4
    // 0x8073D358: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8073D358: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8073D35C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8073D360: jal         0x80066E88
    // 0x8073D364: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8073D364: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8073D368: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8073D36C: lui         $a0, 0x8074
    ctx->r4 = S32(RELOC_HI16(745, 0X1310) << 16);
    // 0x8073D370: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8073D374: addiu       $a0, $a0, -0x1B20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(745, 0X1310));
    // 0x8073D378: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8073D37C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8073D380:
    // 0x8073D380: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8073D384: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8073D388: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8073D38C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8073D390: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8073D394: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8073D398: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8073D39C: sw          $t7, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r15;
    // 0x8073D3A0: lw          $t8, -0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, -0X8);
    // 0x8073D3A4: sw          $t8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r24;
    // 0x8073D3A8: lw          $t7, -0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, -0X4);
    // 0x8073D3AC: bne         $at, $zero, L_8073D380
    if (ctx->r1 != 0) {
        // 0x8073D3B0: sw          $t7, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r15;
            goto L_8073D380;
    }
    // 0x8073D3B0: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x8073D3B4: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x8073D3B8: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(745, 0X13C8) << 16);
    // 0x8073D3BC: addiu       $v0, $v0, -0x1A68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(745, 0X13C8));
    // 0x8073D3C0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8073D3C4: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8073D3C8: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x8073D3CC: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8073D3D0: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8073D3D4: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8073D3D8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8073D3DC: lh          $t0, 0x2($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X2);
    // 0x8073D3E0: mul.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8073D3E4: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8073D3E8: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8073D3EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8073D3F0: lh          $t5, 0x10($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X10);
    // 0x8073D3F4: lh          $t6, 0x12($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X12);
    // 0x8073D3F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8073D3FC: lh          $t1, 0x20($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X20);
    // 0x8073D400: lh          $t7, 0x30($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X30);
    // 0x8073D404: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8073D408: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(745, 0X13C0) << 16);
    // 0x8073D40C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8073D410: mul.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8073D414: addiu       $v0, $v0, -0x1A70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(745, 0X13C0));
    // 0x8073D418: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8073D41C: sll         $t3, $v1, 4
    ctx->r11 = S32(ctx->r3 << 4);
    // 0x8073D420: mul.s       $f12, $f10, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8073D424: nop

    // 0x8073D428: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8073D42C: nop

    // 0x8073D430: mul.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8073D434: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8073D438: mul.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8073D43C: nop

    // 0x8073D440: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8073D444: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8073D448: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8073D44C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8073D450: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8073D454: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x8073D458: sh          $t2, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r10;
    // 0x8073D45C: lh          $t2, 0x22($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X22);
    // 0x8073D460: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8073D464: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8073D468: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8073D46C: mul.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8073D470: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8073D474: nop

    // 0x8073D478: sh          $t4, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r12;
    // 0x8073D47C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8073D480: mul.s       $f12, $f4, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8073D484: nop

    // 0x8073D488: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8073D48C: nop

    // 0x8073D490: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8073D494: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8073D498: mul.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8073D49C: nop

    // 0x8073D4A0: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8073D4A4: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8073D4A8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8073D4AC: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8073D4B0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8073D4B4: add.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x8073D4B8: sh          $t8, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r24;
    // 0x8073D4BC: lh          $t8, 0x32($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X32);
    // 0x8073D4C0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8073D4C4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8073D4C8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8073D4CC: mul.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8073D4D0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8073D4D4: nop

    // 0x8073D4D8: sh          $t0, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r8;
    // 0x8073D4DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8073D4E0: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8073D4E4: nop

    // 0x8073D4E8: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8073D4EC: nop

    // 0x8073D4F0: mul.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8073D4F4: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8073D4F8: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8073D4FC: nop

    // 0x8073D500: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8073D504: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8073D508: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8073D50C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x8073D510: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8073D514: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x8073D518: sh          $t4, 0x20($a2)
    MEM_H(0X20, ctx->r6) = ctx->r12;
    // 0x8073D51C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8073D520: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8073D524: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8073D528: mul.s       $f2, $f4, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8073D52C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8073D530: nop

    // 0x8073D534: sh          $t6, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r14;
    // 0x8073D538: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8073D53C: mul.s       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8073D540: nop

    // 0x8073D544: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8073D548: nop

    // 0x8073D54C: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8073D550: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8073D554: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8073D558: nop

    // 0x8073D55C: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8073D560: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8073D564: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8073D568: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8073D56C: add.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x8073D570: sh          $t0, 0x30($a2)
    MEM_H(0X30, ctx->r6) = ctx->r8;
    // 0x8073D574: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8073D578: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8073D57C: nop

    // 0x8073D580: sh          $t2, 0x32($a2)
    MEM_H(0X32, ctx->r6) = ctx->r10;
    // 0x8073D584: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8073D588: beq         $at, $zero, L_8073D5EC
    if (ctx->r1 == 0) {
        // 0x8073D58C: lwc1        $f20, 0x4($v0)
        ctx->f20.u32l = MEM_W(ctx->r2, 0X4);
            goto L_8073D5EC;
    }
    // 0x8073D58C: lwc1        $f20, 0x4($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8073D590: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8073D594: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8073D598: addu        $v0, $a2, $t3
    ctx->r2 = ADD32(ctx->r6, ctx->r11);
L_8073D59C:
    // 0x8073D59C: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x8073D5A0: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x8073D5A4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8073D5A8: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8073D5AC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8073D5B0: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8073D5B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8073D5B8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8073D5BC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8073D5C0: mul.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8073D5C4: nop

    // 0x8073D5C8: mul.s       $f12, $f10, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8073D5CC: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8073D5D0: add.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8073D5D4: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8073D5D8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8073D5DC: sh          $t7, -0x10($v0)
    MEM_H(-0X10, ctx->r2) = ctx->r15;
    // 0x8073D5E0: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8073D5E4: bne         $at, $zero, L_8073D59C
    if (ctx->r1 != 0) {
        // 0x8073D5E8: sh          $t9, -0xE($v0)
        MEM_H(-0XE, ctx->r2) = ctx->r25;
            goto L_8073D59C;
    }
    // 0x8073D5E8: sh          $t9, -0xE($v0)
    MEM_H(-0XE, ctx->r2) = ctx->r25;
L_8073D5EC:
    // 0x8073D5EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8073D5F0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8073D5F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8073D5F8: jr          $ra
    // 0x8073D5FC: nop

    return;
    // 0x8073D5FC: nop

;}
RECOMP_FUNC void func_804C5158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5158: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C515C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C5160: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x804C5164: addiu       $s0, $s0, 0x7EA0
    ctx->r16 = ADD32(ctx->r16, 0X7EA0);
    // 0x804C5168: lw          $t6, 0xF74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XF74);
    // 0x804C516C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C5170: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804C5174: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x804C5178: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C517C: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x804C5180: beql        $at, $zero, L_804C5254
    if (ctx->r1 == 0) {
        // 0x804C5184: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804C5254;
    }
    goto skip_0;
    // 0x804C5184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804C5188: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x804C518C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804C5190: bnel        $t8, $zero, L_804C5254
    if (ctx->r24 != 0) {
        // 0x804C5194: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804C5254;
    }
    goto skip_1;
    // 0x804C5194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x804C5198: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x804C519C: lw          $v0, 0xF74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF74);
    // 0x804C51A0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x804C51A4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x804C51A8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x804C51AC: lw          $t2, 0xABC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XABC);
    // 0x804C51B0: lw          $t4, 0xF74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XF74);
    // 0x804C51B4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x804C51B8: sw          $t3, 0xABC($s0)
    MEM_W(0XABC, ctx->r16) = ctx->r11;
    // 0x804C51BC: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x804C51C0: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x804C51C4: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x804C51C8: jal         0x80067D5C
    // 0x804C51CC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x804C51CC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x804C51D0: addiu       $a0, $zero, 0x212
    ctx->r4 = ADD32(0, 0X212);
    // 0x804C51D4: jal         0x80067818
    // 0x804C51D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x804C51D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x804C51DC: lw          $t5, 0xF74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XF74);
    // 0x804C51E0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x804C51E4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x804C51E8: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x804C51EC: bnel        $at, $zero, L_804C5254
    if (ctx->r1 != 0) {
        // 0x804C51F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804C5254;
    }
    goto skip_2;
    // 0x804C51F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x804C51F4: lw          $t8, 0xE94($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE94);
    // 0x804C51F8: addiu       $t7, $zero, 0x4034
    ctx->r15 = ADD32(0, 0X4034);
    // 0x804C51FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804C5200: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x804C5204: lw          $t9, 0xE94($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE94);
    // 0x804C5208: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x804C520C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C5210: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x804C5214: lw          $t0, 0xE94($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE94);
    // 0x804C5218: addiu       $a0, $a3, 0x84
    ctx->r4 = ADD32(ctx->r7, 0X84);
    // 0x804C521C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804C5220: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x804C5224: lw          $t1, 0xE94($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE94);
    // 0x804C5228: lw          $t9, 0xC($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XC);
    // 0x804C522C: jalr        $t9
    // 0x804C5230: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x804C5230: nop

    after_2:
    // 0x804C5234: jal         0x80067E68
    // 0x804C5238: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x804C5238: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x804C523C: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x804C5240: jal         0x80067818
    // 0x804C5244: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x804C5244: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x804C5248: lw          $t2, 0xF74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XF74);
    // 0x804C524C: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x804C5250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C5254:
    // 0x804C5254: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C5258: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C525C: jr          $ra
    // 0x804C5260: nop

    return;
    // 0x804C5260: nop

;}
RECOMP_FUNC void func_8004742C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004742C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80047430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80047434: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80047438: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8004743C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80047440: jal         0x8004733C
    // 0x80047444: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8004733C(rdram, ctx);
        goto after_0;
    // 0x80047444: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80047448: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004744C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80047450: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80047454: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80047458: nop

    // 0x8004745C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80047460: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80047464: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80047468: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8004746C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80047470: nop

    // 0x80047474: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80047478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004747C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80047480: jr          $ra
    // 0x80047484: nop

    return;
    // 0x80047484: nop

;}
RECOMP_FUNC void func_80793284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80793284: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80793288: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079328C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80793290: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x80793294: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80793298: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079329C: slti        $at, $v0, 0x12
    ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x807932A0: bne         $at, $zero, L_807932AC
    if (ctx->r1 != 0) {
        // 0x807932A4: slti        $at, $v0, 0x1A
        ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
            goto L_807932AC;
    }
    // 0x807932A4: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x807932A8: bne         $at, $zero, L_807933E8
    if (ctx->r1 != 0) {
        // 0x807932AC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_807933E8;
    }
L_807932AC:
    // 0x807932AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807932B0: beql        $v0, $at, L_807933EC
    if (ctx->r2 == ctx->r1) {
        // 0x807932B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807933EC;
    }
    goto skip_0;
    // 0x807932B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807932B8: lw          $t6, 0x3C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X3C);
    // 0x807932BC: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x807932C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807932C4: bne         $t6, $zero, L_807933E8
    if (ctx->r14 != 0) {
        // 0x807932C8: addiu       $a2, $zero, 0x12
        ctx->r6 = ADD32(0, 0X12);
            goto L_807933E8;
    }
    // 0x807932C8: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x807932CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807932D0: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807932D4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x807932D8: nop

    // 0x807932DC: bc1fl       L_807932F4
    if (!c1cs) {
        // 0x807932E0: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_807932F4;
    }
    goto skip_1;
    // 0x807932E0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_1:
    // 0x807932E4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x807932E8: b           L_8079333C
    // 0x807932EC: sw          $zero, 0x68($v0)
    MEM_W(0X68, ctx->r2) = 0;
        goto L_8079333C;
    // 0x807932EC: sw          $zero, 0x68($v0)
    MEM_W(0X68, ctx->r2) = 0;
    // 0x807932F0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_807932F4:
    // 0x807932F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807932F8: bc1fl       L_80793310
    if (!c1cs) {
        // 0x807932FC: lwc1        $f4, 0x84($a1)
        ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
            goto L_80793310;
    }
    goto skip_2;
    // 0x807932FC: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
    skip_2:
    // 0x80793300: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80793304: b           L_8079333C
    // 0x80793308: sw          $t7, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r15;
        goto L_8079333C;
    // 0x80793308: sw          $t7, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r15;
    // 0x8079330C: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
L_80793310:
    // 0x80793310: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80793314: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80793318: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8079331C: nop

    // 0x80793320: bc1fl       L_80793338
    if (!c1cs) {
        // 0x80793324: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_80793338;
    }
    goto skip_3;
    // 0x80793324: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    skip_3:
    // 0x80793328: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8079332C: b           L_8079333C
    // 0x80793330: sw          $zero, 0x68($v0)
    MEM_W(0X68, ctx->r2) = 0;
        goto L_8079333C;
    // 0x80793330: sw          $zero, 0x68($v0)
    MEM_W(0X68, ctx->r2) = 0;
    // 0x80793334: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_80793338:
    // 0x80793338: sw          $t8, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r24;
L_8079333C:
    // 0x8079333C: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x80793340: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80793344: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80793348: jal         0x8079393C
    // 0x8079334C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8079393C(rdram, ctx);
        goto after_0;
    // 0x8079334C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80793350: lw          $v1, 0x1E4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E4);
    // 0x80793354: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80793358: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8079335C: blez        $v1, L_8079336C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80793360: lw          $v0, 0x20($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X20);
            goto L_8079336C;
    }
    // 0x80793360: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80793364: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80793368: sw          $t9, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r25;
L_8079336C:
    // 0x8079336C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80793370: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80793374: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80793378: lw          $t0, -0x7290($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7290);
    // 0x8079337C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80793380: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80793384: jal         0x8006CB1C
    // 0x80793388: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
    func_8006CB1C(rdram, ctx);
        goto after_1;
    // 0x80793388: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
    after_1:
    // 0x8079338C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80793390: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80793394: jal         0x8006CB2C
    // 0x80793398: nop

    func_8006CB2C(rdram, ctx);
        goto after_2;
    // 0x80793398: nop

    after_2:
    // 0x8079339C: lw          $t1, 0x1E4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1E4);
    // 0x807933A0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x807933A4: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x807933A8: bne         $t1, $at, L_807933BC
    if (ctx->r9 != ctx->r1) {
        // 0x807933AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807933BC;
    }
    // 0x807933AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807933B0: lw          $t3, -0x7290($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7290);
    // 0x807933B4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x807933B8: sb          $t2, 0x41($t3)
    MEM_B(0X41, ctx->r11) = ctx->r10;
L_807933BC:
    // 0x807933BC: jal         0x807907AC
    // 0x807933C0: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    func_807907AC(rdram, ctx);
        goto after_3;
    // 0x807933C0: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    after_3:
    // 0x807933C4: lw          $t4, 0x1E4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1E4);
    // 0x807933C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x807933CC: bnel        $t4, $at, L_807933E0
    if (ctx->r12 != ctx->r1) {
        // 0x807933D0: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_807933E0;
    }
    goto skip_4;
    // 0x807933D0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x807933D4: jal         0x800677F8
    // 0x807933D8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800677F8(rdram, ctx);
        goto after_4;
    // 0x807933D8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_4:
    // 0x807933DC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_807933E0:
    // 0x807933E0: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x807933E4: sw          $t5, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r13;
L_807933E8:
    // 0x807933E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807933EC:
    // 0x807933EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807933F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807933F4: jr          $ra
    // 0x807933F8: nop

    return;
    // 0x807933F8: nop

;}
RECOMP_FUNC void func_8002DA50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DA50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002DA54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DA58: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002DA5C: addiu       $t6, $zero, 0x68
    ctx->r14 = ADD32(0, 0X68);
    // 0x8002DA60: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8002DA64: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8002DA68: sb          $t7, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r15;
    // 0x8002DA6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002DA70: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002DA74: lui         $t9, 0x8003
    ctx->r25 = S32(0X8003 << 16);
    // 0x8002DA78: addiu       $t8, $t8, 0x3DD8
    ctx->r24 = ADD32(ctx->r24, 0X3DD8);
    // 0x8002DA7C: addiu       $t9, $t9, 0x3E54
    ctx->r25 = ADD32(ctx->r25, 0X3E54);
    // 0x8002DA80: sw          $t8, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->r24;
    // 0x8002DA84: sw          $t9, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->r25;
    // 0x8002DA88: sw          $zero, 0x190($v0)
    MEM_W(0X190, ctx->r2) = 0;
    // 0x8002DA8C: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x8002DA90: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x8002DA94: jal         0x8001D770
    // 0x8002DA98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001D770(rdram, ctx);
        goto after_0;
    // 0x8002DA98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002DA9C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8002DAA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002DAA4: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x8002DAA8: jal         0x80067BF8
    // 0x8002DAAC: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_1;
    // 0x8002DAAC: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_1:
    // 0x8002DAB0: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    // 0x8002DAB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002DAB8: jal         0x80067838
    // 0x8002DABC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_2;
    // 0x8002DABC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x8002DAC0: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x8002DAC4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002DAC8: sb          $t0, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r8;
    // 0x8002DACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DAD0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002DAD4: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8002DAD8: sb          $t1, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r9;
    // 0x8002DADC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002DAE0: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8002DAE4: sb          $t2, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r10;
    // 0x8002DAE8: jr          $ra
    // 0x8002DAEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002DAEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800474D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800474D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800474DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800474E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800474E4: lh          $t6, 0x13C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X13C);
    // 0x800474E8: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800474EC: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x800474F0: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800474F4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800474F8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800474FC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80047500: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80047504: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80047508: jal         0x800471D8
    // 0x8004750C: sub.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f16.fl;
    func_800471D8(rdram, ctx);
        goto after_0;
    // 0x8004750C: sub.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f16.fl;
    after_0:
    // 0x80047510: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80047514: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80047518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004751C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80047520: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80047524: nop

    // 0x80047528: slt         $v0, $t8, $t0
    ctx->r2 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004752C: jr          $ra
    // 0x80047530: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    return;
    // 0x80047530: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
;}
RECOMP_FUNC void pad_stick_x(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FBC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007FBC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FBCC: jal         0x8007FBB4
    // 0x8007FBD0: nop

    pad_logical_stick_x(rdram, ctx);
        goto after_0;
    // 0x8007FBD0: nop

    after_0:
    // 0x8007FBD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FBD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007FBDC: jr          $ra
    // 0x8007FBE0: nop

    return;
    // 0x8007FBE0: nop

;}
RECOMP_FUNC void func_800230DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800230DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800230E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800230E4: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x800230E8: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x800230EC: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x800230F0: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x800230F4: lwc1        $f4, -0x318($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X318);
    // 0x800230F8: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x800230FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80023100: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x80023104: jr          $ra
    // 0x80023108: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80023108: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_807ADA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ADA98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807ADA9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807ADAA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807ADAA4: jal         0x80047090
    // 0x807ADAA8: addiu       $a0, $zero, 0x46F2
    ctx->r4 = ADD32(0, 0X46F2);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807ADAA8: addiu       $a0, $zero, 0x46F2
    ctx->r4 = ADD32(0, 0X46F2);
    after_0:
    // 0x807ADAAC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x807ADAB0: bne         $v0, $at, L_807ADAC0
    if (ctx->r2 != ctx->r1) {
        // 0x807ADAB4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_807ADAC0;
    }
    // 0x807ADAB4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x807ADAB8: b           L_807ADB30
    // 0x807ADABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807ADB30;
    // 0x807ADABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807ADAC0:
    // 0x807ADAC0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x807ADAC4: lui         $at, 0x46F2
    ctx->r1 = S32(0X46F2 << 16);
    // 0x807ADAC8: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807ADACC: lui         $a3, 0x43F9
    ctx->r7 = S32(0X43F9 << 16);
    // 0x807ADAD0: lw          $a1, 0x84($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X84);
    // 0x807ADAD4: lw          $a2, 0x88($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X88);
    // 0x807ADAD8: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    // 0x807ADADC: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x807ADAE0: jal         0x8004613C
    // 0x807ADAE4: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807ADAE4: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x807ADAE8: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x807ADAEC: bne         $v0, $zero, L_807ADAFC
    if (ctx->r2 != 0) {
        // 0x807ADAF0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_807ADAFC;
    }
    // 0x807ADAF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807ADAF4: b           L_807ADB30
    // 0x807ADAF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807ADB30;
    // 0x807ADAF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807ADAFC:
    // 0x807ADAFC: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x807ADB00: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x807ADB04: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x807ADB08: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x807ADB0C: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x807ADB10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x807ADB14: jal         0x80047F9C
    // 0x807ADB18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807ADB18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x807ADB1C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x807ADB20: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807ADB24: jal         0x807AD9C0
    // 0x807ADB28: sb          $t1, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r9;
    func_807AD9C0(rdram, ctx);
        goto after_3;
    // 0x807ADB28: sb          $t1, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r9;
    after_3:
    // 0x807ADB2C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_807ADB30:
    // 0x807ADB30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807ADB34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807ADB38: jr          $ra
    // 0x807ADB3C: nop

    return;
    // 0x807ADB3C: nop

;}
RECOMP_FUNC void func_8045D654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045D654: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045D658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045D65C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045D660: jal         0x8045D424
    // 0x8045D664: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8045D424(rdram, ctx);
        goto after_0;
    // 0x8045D664: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8045D668: jal         0x8045D590
    // 0x8045D66C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8045D590(rdram, ctx);
        goto after_1;
    // 0x8045D66C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8045D670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045D674: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8045D678: jr          $ra
    // 0x8045D67C: nop

    return;
    // 0x8045D67C: nop

;}
RECOMP_FUNC void func_8044045C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044045C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80440460: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80440464: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80440468: lw          $t5, 0x1F4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044046C: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x80440470: addiu       $s0, $s0, 0x7EA0
    ctx->r16 = ADD32(ctx->r16, 0X7EA0);
    // 0x80440474: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80440478: lw          $t9, 0x478($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X478);
    // 0x8044047C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80440480: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80440484: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80440488: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8044048C: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80440490: lwc1        $f6, 0x38($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X38);
    // 0x80440494: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80440498: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    // 0x8044049C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804404A0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x804404A4: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x804404A8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804404AC: jal         0x80081C64
    // 0x804404B0: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x804404B0: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x804404B4: lw          $v0, 0x3F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3F4);
    // 0x804404B8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x804404BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804404C0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804404C4: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x804404C8: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804404CC: div.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804404D0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x804404D4: add.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x804404D8: div.s       $f2, $f14, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f4.fl);
    // 0x804404DC: jal         0x80081C64
    // 0x804404E0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x804404E0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x804404E4: lw          $v0, 0x3F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3F4);
    // 0x804404E8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x804404EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804404F0: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804404F4: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x804404F8: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EC0) << 16);
    // 0x804404FC: div.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80440500: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80440504: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80440508: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8044050C: lwc1        $f8, 0x3DC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EC0));
    // 0x80440510: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80440514: nop

    // 0x80440518: mul.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8044051C: add.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80440520: jal         0x80081C64
    // 0x80440524: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_2;
    // 0x80440524: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80440528: lw          $v0, 0x3F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3F4);
    // 0x8044052C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80440530: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80440534: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80440538: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8044053C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80440540: div.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80440544: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80440548: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8044054C: lui         $t3, 0x8044
    ctx->r11 = S32(RELOC_HI16(95, 0X4C64) << 16);
    // 0x80440550: sub.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80440554: sll         $t6, $ra, 2
    ctx->r14 = S32(ctx->r31 << 2);
    // 0x80440558: addu        $t6, $t6, $ra
    ctx->r14 = ADD32(ctx->r14, ctx->r31);
    // 0x8044055C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80440560: subu        $t6, $t6, $ra
    ctx->r14 = SUB32(ctx->r14, ctx->r31);
    // 0x80440564: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80440568: addu        $t6, $t6, $ra
    ctx->r14 = ADD32(ctx->r14, ctx->r31);
    // 0x8044056C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80440570: lui         $t2, 0x8044
    ctx->r10 = S32(RELOC_HI16(95, 0X4C24) << 16);
    // 0x80440574: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x80440578: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8044057C: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80440580: addiu       $t0, $t0, 0x1CA8
    ctx->r8 = ADD32(ctx->r8, 0X1CA8);
    // 0x80440584: addiu       $t2, $t2, 0x3B24
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(95, 0X4C24));
    // 0x80440588: addiu       $t3, $t3, 0x3B64
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(95, 0X4C64));
    // 0x8044058C: addiu       $t1, $zero, 0x95
    ctx->r9 = ADD32(0, 0X95);
    // 0x80440590: lui         $t4, 0xF600
    ctx->r12 = S32(0XF600 << 16);
    // 0x80440594: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80440598: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8044059C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804405A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804405A4: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x804405A8: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x804405AC: add.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f18.fl;
    // 0x804405B0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x804405B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804405B8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x804405BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804405C0: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804405C4: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804405C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804405CC: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x804405D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804405D4: nop

    // 0x804405D8: mul.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804405DC: nop

L_804405E0:
    // 0x804405E0: lw          $v0, 0x478($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X478);
    // 0x804405E4: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x804405E8: lw          $t7, 0x1C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1C);
    // 0x804405EC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804405F0: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x804405F4: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    // 0x804405F8: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x804405FC: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x80440600: addu        $t6, $t2, $v1
    ctx->r14 = ADD32(ctx->r10, ctx->r3);
    // 0x80440604: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80440608: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8044060C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80440610: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80440614: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80440618: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8044061C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80440620: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80440624: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80440628: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x8044062C: addu        $t7, $t3, $v1
    ctx->r15 = ADD32(ctx->r11, ctx->r3);
    // 0x80440630: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80440634: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80440638: slti        $at, $a0, 0x141
    ctx->r1 = SIGNED(ctx->r4) < 0X141 ? 1 : 0;
    // 0x8044063C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80440640: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80440644: bltz        $a0, L_804406A4
    if (SIGNED(ctx->r4) < 0) {
        // 0x80440648: addu        $a1, $t9, $t6
        ctx->r5 = ADD32(ctx->r25, ctx->r14);
            goto L_804406A4;
    }
    // 0x80440648: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
    // 0x8044064C: beq         $at, $zero, L_804406A4
    if (ctx->r1 == 0) {
        // 0x80440650: nop
    
            goto L_804406A4;
    }
    // 0x80440650: nop

    // 0x80440654: bltz        $a1, L_804406A4
    if (SIGNED(ctx->r5) < 0) {
        // 0x80440658: slti        $at, $a1, 0xF1
        ctx->r1 = SIGNED(ctx->r5) < 0XF1 ? 1 : 0;
            goto L_804406A4;
    }
    // 0x80440658: slti        $at, $a1, 0xF1
    ctx->r1 = SIGNED(ctx->r5) < 0XF1 ? 1 : 0;
    // 0x8044065C: beq         $at, $zero, L_804406A4
    if (ctx->r1 == 0) {
        // 0x80440660: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_804406A4;
    }
    // 0x80440660: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80440664: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x80440668: andi        $t7, $t8, 0x3FF
    ctx->r15 = ctx->r24 & 0X3FF;
    // 0x8044066C: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x80440670: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x80440674: andi        $t7, $t8, 0x3FF
    ctx->r15 = ctx->r24 & 0X3FF;
    // 0x80440678: or          $t6, $t9, $t4
    ctx->r14 = ctx->r25 | ctx->r12;
    // 0x8044067C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80440680: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80440684: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80440688: andi        $t9, $a1, 0x3FF
    ctx->r25 = ctx->r5 & 0X3FF;
    // 0x8044068C: andi        $t7, $a0, 0x3FF
    ctx->r15 = ctx->r4 & 0X3FF;
    // 0x80440690: sll         $t6, $t7, 14
    ctx->r14 = S32(ctx->r15 << 14);
    // 0x80440694: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80440698: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8044069C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x804406A0: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_804406A4:
    // 0x804406A4: bgez        $t1, L_804405E0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x804406A8: addiu       $a3, $a3, 0x30
        ctx->r7 = ADD32(ctx->r7, 0X30);
            goto L_804405E0;
    }
    // 0x804406A8: addiu       $a3, $a3, 0x30
    ctx->r7 = ADD32(ctx->r7, 0X30);
    // 0x804406AC: lui         $t9, 0xB800
    ctx->r25 = S32(0XB800 << 16);
    // 0x804406B0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x804406B4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x804406B8: sw          $ra, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r31;
    // 0x804406BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804406C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804406C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x804406C8: jr          $ra
    // 0x804406CC: nop

    return;
    // 0x804406CC: nop

;}
RECOMP_FUNC void func_8042C8F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042C8F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042C8F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042C8F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8042C8FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8042C900: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X3054) << 16);
    // 0x8042C904: lwc1        $f0, -0x270C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X3054));
    // 0x8042C908: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8042C90C: lwc1        $f8, 0xC8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8042C910: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042C914: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8042C918: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042C91C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8042C920: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x8042C924: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x8042C928: jal         0x8042A9DC
    // 0x8042C92C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_8042A9DC(rdram, ctx);
        goto after_0;
    // 0x8042C92C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x8042C930: jal         0x8042BB3C
    // 0x8042C934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BB3C(rdram, ctx);
        goto after_1;
    // 0x8042C934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8042C938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C93C: jal         0x8042B938
    // 0x8042C940: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    func_8042B938(rdram, ctx);
        goto after_2;
    // 0x8042C940: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    after_2:
    // 0x8042C944: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042C948: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x8042C94C: beq         $at, $zero, L_8042C96C
    if (ctx->r1 == 0) {
        // 0x8042C950: lui         $at, 0x8043
        ctx->r1 = S32(RELOC_HI16(50, 0X3058) << 16);
            goto L_8042C96C;
    }
    // 0x8042C950: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X3058) << 16);
    // 0x8042C954: lwc1        $f18, -0x2708($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X3058));
    // 0x8042C958: lwc1        $f16, 0x20($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8042C95C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8042C960: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x8042C964: b           L_8042C994
    // 0x8042C968: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
        goto L_8042C994;
    // 0x8042C968: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_8042C96C:
    // 0x8042C96C: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x8042C970: bne         $at, $zero, L_8042C994
    if (ctx->r1 != 0) {
        // 0x8042C974: slti        $at, $v0, 0x46
        ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
            goto L_8042C994;
    }
    // 0x8042C974: slti        $at, $v0, 0x46
    ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
    // 0x8042C978: beq         $at, $zero, L_8042C994
    if (ctx->r1 == 0) {
        // 0x8042C97C: lui         $at, 0x8043
        ctx->r1 = S32(RELOC_HI16(50, 0X305C) << 16);
            goto L_8042C994;
    }
    // 0x8042C97C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X305C) << 16);
    // 0x8042C980: lwc1        $f8, -0x2704($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X305C));
    // 0x8042C984: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8042C988: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8042C98C: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x8042C990: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_8042C994:
    // 0x8042C994: slti        $at, $v0, 0x46
    ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
    // 0x8042C998: bne         $at, $zero, L_8042C9E4
    if (ctx->r1 != 0) {
        // 0x8042C99C: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_8042C9E4;
    }
    // 0x8042C99C: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8042C9A0: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x8042C9A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042C9A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C9AC: bne         $t6, $at, L_8042C9D0
    if (ctx->r14 != ctx->r1) {
        // 0x8042C9B0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8042C9D0;
    }
    // 0x8042C9B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042C9B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C9B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042C9BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8042C9C0: jal         0x8042D50C
    // 0x8042C9C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8042D50C(rdram, ctx);
        goto after_3;
    // 0x8042C9C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8042C9C8: b           L_8042C9DC
    // 0x8042C9CC: nop

        goto L_8042C9DC;
    // 0x8042C9CC: nop

L_8042C9D0:
    // 0x8042C9D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8042C9D4: jal         0x8042D50C
    // 0x8042C9D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8042D50C(rdram, ctx);
        goto after_4;
    // 0x8042C9D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
L_8042C9DC:
    // 0x8042C9DC: b           L_8042C9E8
    // 0x8042C9E0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
        goto L_8042C9E8;
    // 0x8042C9E0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_8042C9E4:
    // 0x8042C9E4: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
L_8042C9E8:
    // 0x8042C9E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8042C9EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8042C9F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8042C9F4: jr          $ra
    // 0x8042C9F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8042C9F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000AA48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AA48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000AA4C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8000AA50: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000AA54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000AA58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AA5C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000AA60: jal         0x800036F0
    // 0x8000AA64: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    func_800036F0(rdram, ctx);
        goto after_0;
    // 0x8000AA64: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_0:
    // 0x8000AA68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000AA6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000AA70: jr          $ra
    // 0x8000AA74: nop

    return;
    // 0x8000AA74: nop

;}
RECOMP_FUNC void func_8001C770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C770: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001C774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C778: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001C77C: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8001C780: lw          $t7, 0x1F4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1F4);
    // 0x8001C784: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001C788: jal         0x8001C748
    // 0x8001C78C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_8001C748(rdram, ctx);
        goto after_0;
    // 0x8001C78C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x8001C790: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001C794: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8001C798: lw          $t9, 0x1E0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1E0);
    // 0x8001C79C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8001C7A0: jal         0x8001CBB8
    // 0x8001C7A4: lbu         $a1, 0x28($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X28);
    func_8001CBB8(rdram, ctx);
        goto after_1;
    // 0x8001C7A4: lbu         $a1, 0x28($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X28);
    after_1:
    // 0x8001C7A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C7AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001C7B0: jr          $ra
    // 0x8001C7B4: nop

    return;
    // 0x8001C7B4: nop

;}
RECOMP_FUNC void func_807076FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807076FC: jr          $ra
    // 0x80707700: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80707700: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806EE4C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE4C0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806EE4C4: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(676, 0X235C) << 16);
    // 0x806EE4C8: addiu       $t6, $t6, -0x1D54
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(676, 0X235C));
    // 0x806EE4CC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806EE4D0: jr          $ra
    // 0x806EE4D4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806EE4D4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_806FE318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FE318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FE31C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FE320: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x806FE324: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806FE328: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x806FE32C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806FE330: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806FE334: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806FE338: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806FE33C: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    // 0x806FE340: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806FE344: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806FE348: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x806FE34C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x806FE350: jal         0x80048378
    // 0x806FE354: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x806FE354: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x806FE358: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806FE35C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x806FE360: lw          $v1, 0x1F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1F4);
    // 0x806FE364: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806FE368: bne         $v1, $zero, L_806FE384
    if (ctx->r3 != 0) {
        // 0x806FE36C: nop
    
            goto L_806FE384;
    }
    // 0x806FE36C: nop

    // 0x806FE370: jal         0x80045A34
    // 0x806FE374: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x806FE374: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x806FE378: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806FE37C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x806FE380: sw          $v0, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = ctx->r2;
L_806FE384:
    // 0x806FE384: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(706, 0XE98) << 16);
    // 0x806FE388: addiu       $t9, $t9, -0x1D08
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(706, 0XE98));
    // 0x806FE38C: sw          $t9, 0x1F8($a2)
    MEM_W(0X1F8, ctx->r6) = ctx->r25;
    // 0x806FE390: sh          $zero, 0x10($v1)
    MEM_H(0X10, ctx->r3) = 0;
    // 0x806FE394: lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F4);
    // 0x806FE398: lwc1        $f4, 0x3C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x806FE39C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x806FE3A0: lwc1        $f6, 0x40($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X40);
    // 0x806FE3A4: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x806FE3A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FE3AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FE3B0: jr          $ra
    // 0x806FE3B4: nop

    return;
    // 0x806FE3B4: nop

;}
RECOMP_FUNC void func_8067E004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E004: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8067E008: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8067E00C: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8067E010: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8067E014: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8067E018: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8067E01C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8067E020: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8067E024: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8067E028: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8067E02C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8067E030: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8067E034: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8067E038: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8067E03C: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8067E040: lui         $t9, 0x8068
    ctx->r25 = S32(RELOC_HI16(544, 0X10B8) << 16);
    // 0x8067E044: addiu       $t9, $t9, -0x1088
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(544, 0X10B8));
    // 0x8067E048: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8067E04C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8067E050: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8067E054: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8067E058: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8067E05C: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067E060: addiu       $t6, $sp, 0x94
    ctx->r14 = ADD32(ctx->r29, 0X94);
    // 0x8067E064: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8067E068: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8067E06C: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8067E070: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8067E074: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x8067E078: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8067E07C: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x8067E080: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8067E084: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x8067E088: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8067E08C: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x8067E090: lwc1        $f22, 0x6C($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8067E094: jal         0x80049018
    // 0x8067E098: lwc1        $f24, 0x70($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X70);
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x8067E098: lwc1        $f24, 0x70($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X70);
    after_0:
    // 0x8067E09C: beq         $v0, $zero, L_8067E0BC
    if (ctx->r2 == 0) {
        // 0x8067E0A0: or          $s1, $s5, $zero
        ctx->r17 = ctx->r21 | 0;
            goto L_8067E0BC;
    }
    // 0x8067E0A0: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x8067E0A4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8067E0A8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8067E0AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8067E0B0: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
    // 0x8067E0B4: b           L_8067E0D0
    // 0x8067E0B8: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
        goto L_8067E0D0;
    // 0x8067E0B8: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
L_8067E0BC:
    // 0x8067E0BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8067E0C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8067E0C4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8067E0C8: sw          $t4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r12;
    // 0x8067E0CC: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
L_8067E0D0:
    // 0x8067E0D0: lui         $s3, 0x8068
    ctx->r19 = S32(RELOC_HI16(544, 0XE70) << 16);
    // 0x8067E0D4: addiu       $s3, $s3, -0x12D0
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(544, 0XE70));
    // 0x8067E0D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8067E0DC: addiu       $s4, $sp, 0x80
    ctx->r20 = ADD32(ctx->r29, 0X80);
    // 0x8067E0E0: addiu       $s2, $sp, 0x64
    ctx->r18 = ADD32(ctx->r29, 0X64);
L_8067E0E4:
    // 0x8067E0E4: lw          $t7, 0xC($s5)
    ctx->r15 = MEM_W(ctx->r21, 0XC);
    // 0x8067E0E8: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x8067E0EC: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8067E0F0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8067E0F4: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x8067E0F8: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x8067E0FC: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8067E100: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8067E104: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8067E108: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x8067E10C: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8067E110: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8067E114: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x8067E118: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8067E11C: sw          $t3, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r11;
    // 0x8067E120: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x8067E124: sw          $t4, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r12;
    // 0x8067E128: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8067E12C: sw          $t3, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r11;
    // 0x8067E130: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x8067E134: beq         $a0, $zero, L_8067E1C0
    if (ctx->r4 == 0) {
        // 0x8067E138: sw          $t4, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->r12;
            goto L_8067E1C0;
    }
    // 0x8067E138: sw          $t4, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r12;
    // 0x8067E13C: lh          $t7, 0x64($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X64);
    // 0x8067E140: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8067E144: nop

    // 0x8067E148: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8067E14C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8067E150: nop

    // 0x8067E154: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8067E158: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x8067E15C: lh          $t5, 0x66($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X66);
    // 0x8067E160: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8067E164: nop

    // 0x8067E168: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8067E16C: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x8067E170: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x8067E174: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8067E178: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8067E17C: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    // 0x8067E180: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8067E184: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8067E188: swc1        $f16, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
    // 0x8067E18C: lh          $t8, 0x70($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X70);
    // 0x8067E190: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8067E194: nop

    // 0x8067E198: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8067E19C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8067E1A0: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
    // 0x8067E1A4: lh          $t9, 0x74($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X74);
    // 0x8067E1A8: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    // 0x8067E1AC: lbu         $t6, 0x72($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X72);
    // 0x8067E1B0: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8067E1B4: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x8067E1B8: jal         0x8067DF04
    // 0x8067E1BC: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    func_8067DF04(rdram, ctx);
        goto after_1;
    // 0x8067E1BC: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    after_1:
L_8067E1C0:
    // 0x8067E1C0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8067E1C4: slti        $at, $s0, 0x14
    ctx->r1 = SIGNED(ctx->r16) < 0X14 ? 1 : 0;
    // 0x8067E1C8: bne         $at, $zero, L_8067E0E4
    if (ctx->r1 != 0) {
        // 0x8067E1CC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8067E0E4;
    }
    // 0x8067E1CC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8067E1D0: lui         $s3, 0x8068
    ctx->r19 = S32(RELOC_HI16(544, 0XF74) << 16);
    // 0x8067E1D4: addiu       $s3, $s3, -0x11CC
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(544, 0XF74));
    // 0x8067E1D8: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x8067E1DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8067E1E0: addiu       $fp, $zero, 0x14
    ctx->r30 = ADD32(0, 0X14);
    // 0x8067E1E4: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8067E1E8: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
L_8067E1EC:
    // 0x8067E1EC: lw          $t3, 0xC($s5)
    ctx->r11 = MEM_W(ctx->r21, 0XC);
    // 0x8067E1F0: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x8067E1F4: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x8067E1F8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8067E1FC: addu        $t7, $t2, $t4
    ctx->r15 = ADD32(ctx->r10, ctx->r12);
    // 0x8067E200: lh          $t5, 0x0($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X0);
    // 0x8067E204: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8067E208: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8067E20C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8067E210: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x8067E214: addu        $t6, $t9, $s0
    ctx->r14 = ADD32(ctx->r25, ctx->r16);
    // 0x8067E218: lw          $t1, 0x0($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X0);
    // 0x8067E21C: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x8067E220: lw          $t0, 0x4($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X4);
    // 0x8067E224: sw          $t0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r8;
    // 0x8067E228: lw          $t1, 0x8($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X8);
    // 0x8067E22C: sw          $t1, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r9;
    // 0x8067E230: lw          $t0, 0xC($t6)
    ctx->r8 = MEM_W(ctx->r14, 0XC);
    // 0x8067E234: sw          $t0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r8;
    // 0x8067E238: lw          $t1, 0x10($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X10);
    // 0x8067E23C: beq         $a0, $zero, L_8067E2E4
    if (ctx->r4 == 0) {
        // 0x8067E240: sw          $t1, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->r9;
            goto L_8067E2E4;
    }
    // 0x8067E240: sw          $t1, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r9;
    // 0x8067E244: lh          $t3, 0x64($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X64);
    // 0x8067E248: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8067E24C: nop

    // 0x8067E250: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8067E254: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8067E258: nop

    // 0x8067E25C: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8067E260: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x8067E264: lh          $t2, 0x66($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X66);
    // 0x8067E268: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8067E26C: nop

    // 0x8067E270: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8067E274: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8067E278: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x8067E27C: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x8067E280: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8067E284: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8067E288: swc1        $f18, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f18.u32l;
    // 0x8067E28C: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8067E290: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8067E294: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x8067E298: lh          $t4, 0x70($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X70);
    // 0x8067E29C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8067E2A0: nop

    // 0x8067E2A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8067E2A8: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8067E2AC: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    // 0x8067E2B0: lh          $t7, 0x74($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X74);
    // 0x8067E2B4: sh          $t7, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r15;
    // 0x8067E2B8: lh          $t5, 0x144($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X144);
    // 0x8067E2BC: bne         $s6, $t5, L_8067E2CC
    if (ctx->r22 != ctx->r13) {
        // 0x8067E2C0: nop
    
            goto L_8067E2CC;
    }
    // 0x8067E2C0: nop

    // 0x8067E2C4: b           L_8067E2D0
    // 0x8067E2C8: sb          $s7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r23;
        goto L_8067E2D0;
    // 0x8067E2C8: sb          $s7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r23;
L_8067E2CC:
    // 0x8067E2CC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
L_8067E2D0:
    // 0x8067E2D0: lbu         $t8, 0x72($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X72);
    // 0x8067E2D4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8067E2D8: addu        $t6, $s4, $t9
    ctx->r14 = ADD32(ctx->r20, ctx->r25);
    // 0x8067E2DC: jal         0x8067DF04
    // 0x8067E2E0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_8067DF04(rdram, ctx);
        goto after_2;
    // 0x8067E2E0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_2:
L_8067E2E4:
    // 0x8067E2E4: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8067E2E8: bne         $s0, $fp, L_8067E1EC
    if (ctx->r16 != ctx->r30) {
        // 0x8067E2EC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8067E1EC;
    }
    // 0x8067E2EC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8067E2F0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8067E2F4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8067E2F8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8067E2FC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8067E300: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8067E304: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8067E308: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8067E30C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8067E310: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8067E314: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8067E318: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8067E31C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8067E320: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8067E324: jr          $ra
    // 0x8067E328: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8067E328: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_806EEE1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EEE1C: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x806EEE20: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806EEE24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EEE28: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x806EEE2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806EEE30: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EEE34: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806EEE38: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D38) << 16);
    // 0x806EEE3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806EEE40: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x806EEE44: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806EEE48: lwc1        $f10, 0x40($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X40);
    // 0x806EEE4C: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x806EEE50: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806EEE54: swc1        $f18, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f18.u32l;
    // 0x806EEE58: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x806EEE5C: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x806EEE60: nop

    // 0x806EEE64: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x806EEE68: add.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x806EEE6C: lwc1        $f6, 0xC88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D38));
    // 0x806EEE70: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D3C) << 16);
    // 0x806EEE74: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x806EEE78: div.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x806EEE7C: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x806EEE80: nop

    // 0x806EEE84: mul.s       $f18, $f4, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x806EEE88: nop

    // 0x806EEE8C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806EEE90: swc1        $f16, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f16.u32l;
    // 0x806EEE94: swc1        $f18, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f18.u32l;
    // 0x806EEE98: add.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x806EEE9C: mul.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x806EEEA0: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x806EEEA4: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x806EEEA8: mul.s       $f18, $f4, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x806EEEAC: swc1        $f18, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f18.u32l;
    // 0x806EEEB0: lwc1        $f6, 0xC8C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D3C));
    // 0x806EEEB4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x806EEEB8: nop

    // 0x806EEEBC: bc1f        L_806EEEC8
    if (!c1cs) {
        // 0x806EEEC0: nop
    
            goto L_806EEEC8;
    }
    // 0x806EEEC0: nop

    // 0x806EEEC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806EEEC8:
    // 0x806EEEC8: jr          $ra
    // 0x806EEECC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806EEECC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804444B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804444B0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x804444B4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x804444B8: sw          $zero, 0xAB8($v0)
    MEM_W(0XAB8, ctx->r2) = 0;
    // 0x804444BC: jr          $ra
    // 0x804444C0: sw          $zero, 0xACC($v0)
    MEM_W(0XACC, ctx->r2) = 0;
    return;
    // 0x804444C0: sw          $zero, 0xACC($v0)
    MEM_W(0XACC, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8005A150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A150: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005A154: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005A158: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005A15C: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x8005A160: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005A164: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x8005A168: lbu         $v0, 0x38($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X38);
    // 0x8005A16C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005A170: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x8005A174: bne         $v0, $zero, L_8005A180
    if (ctx->r2 != 0) {
        // 0x8005A178: addiu       $a0, $a0, -0x4BC0
        ctx->r4 = ADD32(ctx->r4, -0X4BC0);
            goto L_8005A180;
    }
    // 0x8005A178: addiu       $a0, $a0, -0x4BC0
    ctx->r4 = ADD32(ctx->r4, -0X4BC0);
    // 0x8005A17C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8005A180:
    // 0x8005A180: lw          $t7, 0x968($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X968);
    // 0x8005A184: lh          $t6, 0x962($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X962);
    // 0x8005A188: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005A18C: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8005A190: addiu       $a1, $a1, -0x4BBC
    ctx->r5 = ADD32(ctx->r5, -0X4BBC);
    // 0x8005A194: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x8005A198: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005A19C: beql        $at, $zero, L_8005A1B0
    if (ctx->r1 == 0) {
        // 0x8005A1A0: lwc1        $f4, 0x4($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
            goto L_8005A1B0;
    }
    goto skip_0;
    // 0x8005A1A0: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x8005A1A4: b           L_8005A2AC
    // 0x8005A1A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A2AC;
    // 0x8005A1A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005A1AC: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
L_8005A1B0:
    // 0x8005A1B0: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8005A1B4: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8005A1B8: jal         0x80059040
    // 0x8005A1BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80059040(rdram, ctx);
        goto after_0;
    // 0x8005A1BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8005A1C0: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8005A1C4: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x8005A1C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005A1CC: lh          $t1, 0x2A($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X2A);
    // 0x8005A1D0: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x8005A1D4: addiu       $a0, $a0, -0x4BC0
    ctx->r4 = ADD32(ctx->r4, -0X4BC0);
    // 0x8005A1D8: bne         $t1, $zero, L_8005A1F8
    if (ctx->r9 != 0) {
        // 0x8005A1DC: addiu       $a1, $a1, 0x2A
        ctx->r5 = ADD32(ctx->r5, 0X2A);
            goto L_8005A1F8;
    }
    // 0x8005A1DC: addiu       $a1, $a1, 0x2A
    ctx->r5 = ADD32(ctx->r5, 0X2A);
    // 0x8005A1E0: lh          $t2, 0x2($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X2);
    // 0x8005A1E4: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x8005A1E8: bnel        $t2, $zero, L_8005A1FC
    if (ctx->r10 != 0) {
        // 0x8005A1EC: lbu         $t3, 0x3($t0)
        ctx->r11 = MEM_BU(ctx->r8, 0X3);
            goto L_8005A1FC;
    }
    goto skip_1;
    // 0x8005A1EC: lbu         $t3, 0x3($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X3);
    skip_1:
    // 0x8005A1F0: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8005A1F4: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
L_8005A1F8:
    // 0x8005A1F8: lbu         $t3, 0x3($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X3);
L_8005A1FC:
    // 0x8005A1FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A200: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A204: bne         $v0, $t3, L_8005A260
    if (ctx->r2 != ctx->r11) {
        // 0x8005A208: nop
    
            goto L_8005A260;
    }
    // 0x8005A208: nop

    // 0x8005A20C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8005A210: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005A218: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x8005A21C: bne         $v0, $t5, L_8005A250
    if (ctx->r2 != ctx->r13) {
        // 0x8005A220: nop
    
            goto L_8005A250;
    }
    // 0x8005A220: nop

    // 0x8005A224: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005A228: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A22C: sw          $a1, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = ctx->r5;
    // 0x8005A230: jal         0x80059EBC
    // 0x8005A234: addiu       $a0, $a0, -0x4BC0
    ctx->r4 = ADD32(ctx->r4, -0X4BC0);
    func_80059EBC(rdram, ctx);
        goto after_1;
    // 0x8005A234: addiu       $a0, $a0, -0x4BC0
    ctx->r4 = ADD32(ctx->r4, -0X4BC0);
    after_1:
    // 0x8005A238: beql        $v0, $zero, L_8005A2B0
    if (ctx->r2 == 0) {
        // 0x8005A23C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005A2B0;
    }
    goto skip_2;
    // 0x8005A23C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8005A240: jal         0x80059FD4
    // 0x8005A244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80059FD4(rdram, ctx);
        goto after_2;
    // 0x8005A244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8005A248: b           L_8005A2B0
    // 0x8005A24C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005A2B0;
    // 0x8005A24C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A250:
    // 0x8005A250: jal         0x80059FD4
    // 0x8005A254: sw          $a1, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = ctx->r5;
    func_80059FD4(rdram, ctx);
        goto after_3;
    // 0x8005A254: sw          $a1, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = ctx->r5;
    after_3:
    // 0x8005A258: b           L_8005A2B0
    // 0x8005A25C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005A2B0;
    // 0x8005A25C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A260:
    // 0x8005A260: jal         0x80059F64
    // 0x8005A264: sw          $a1, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = ctx->r5;
    func_80059F64(rdram, ctx);
        goto after_4;
    // 0x8005A264: sw          $a1, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = ctx->r5;
    after_4:
    // 0x8005A268: bne         $v0, $zero, L_8005A2AC
    if (ctx->r2 != 0) {
        // 0x8005A26C: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_8005A2AC;
    }
    // 0x8005A26C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005A270: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005A274: addiu       $a0, $a0, -0x4BC0
    ctx->r4 = ADD32(ctx->r4, -0X4BC0);
    // 0x8005A278: jal         0x80059EBC
    // 0x8005A27C: lw          $a1, -0x4BB8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4BB8);
    func_80059EBC(rdram, ctx);
        goto after_5;
    // 0x8005A27C: lw          $a1, -0x4BB8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4BB8);
    after_5:
    // 0x8005A280: beql        $v0, $zero, L_8005A2B0
    if (ctx->r2 == 0) {
        // 0x8005A284: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005A2B0;
    }
    goto skip_3;
    // 0x8005A284: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8005A288: jal         0x8005A0B0
    // 0x8005A28C: nop

    func_8005A0B0(rdram, ctx);
        goto after_6;
    // 0x8005A28C: nop

    after_6:
    // 0x8005A290: bne         $v0, $zero, L_8005A2A4
    if (ctx->r2 != 0) {
        // 0x8005A294: lui         $t7, 0x8006
        ctx->r15 = S32(0X8006 << 16);
            goto L_8005A2A4;
    }
    // 0x8005A294: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8005A298: addiu       $t7, $t7, -0x5B54
    ctx->r15 = ADD32(ctx->r15, -0X5B54);
    // 0x8005A29C: beql        $t7, $zero, L_8005A2B0
    if (ctx->r15 == 0) {
        // 0x8005A2A0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005A2B0;
    }
    goto skip_4;
    // 0x8005A2A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
L_8005A2A4:
    // 0x8005A2A4: jal         0x80059FD4
    // 0x8005A2A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80059FD4(rdram, ctx);
        goto after_7;
    // 0x8005A2A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_8005A2AC:
    // 0x8005A2AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A2B0:
    // 0x8005A2B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005A2B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005A2B8: jr          $ra
    // 0x8005A2BC: nop

    return;
    // 0x8005A2BC: nop

;}
RECOMP_FUNC void func_800340F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800340F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800340FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034100: lhu         $t6, 0x102($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X102);
    // 0x80034104: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80034108: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8003410C: beq         $t6, $zero, L_80034134
    if (ctx->r14 == 0) {
        // 0x80034110: nop
    
            goto L_80034134;
    }
    // 0x80034110: nop

    // 0x80034114: lh          $t7, -0x7680($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X7680);
    // 0x80034118: slti        $at, $t7, -0x30
    ctx->r1 = SIGNED(ctx->r15) < -0X30 ? 1 : 0;
    // 0x8003411C: beql        $at, $zero, L_80034150
    if (ctx->r1 == 0) {
        // 0x80034120: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80034150;
    }
    goto skip_0;
    // 0x80034120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80034124: jal         0x8002E0B0
    // 0x80034128: nop

    func_8002E0B0(rdram, ctx);
        goto after_0;
    // 0x80034128: nop

    after_0:
    // 0x8003412C: b           L_80034150
    // 0x80034130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80034150;
    // 0x80034130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80034134:
    // 0x80034134: lh          $t8, -0x7680($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X7680);
    // 0x80034138: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003413C: slti        $at, $t8, -0x30
    ctx->r1 = SIGNED(ctx->r24) < -0X30 ? 1 : 0;
    // 0x80034140: bnel        $at, $zero, L_80034150
    if (ctx->r1 != 0) {
        // 0x80034144: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80034150;
    }
    goto skip_1;
    // 0x80034144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80034148: sh          $t9, 0x102($a1)
    MEM_H(0X102, ctx->r5) = ctx->r25;
    // 0x8003414C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80034150:
    // 0x80034150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034158: jr          $ra
    // 0x8003415C: nop

    return;
    // 0x8003415C: nop

;}
RECOMP_FUNC void func_80515DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80515DF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80515DFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80515E00: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80515E04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80515E08: lui         $a0, 0x8051
    ctx->r4 = S32(RELOC_HI16(276, 0X1130) << 16);
    // 0x80515E0C: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80515E10: lui         $a1, 0x4088
    ctx->r5 = S32(0X4088 << 16);
    // 0x80515E14: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x80515E18: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x80515E1C: ori         $a1, $a1, 0x2200
    ctx->r5 = ctx->r5 | 0X2200;
    // 0x80515E20: addiu       $a0, $a0, 0x65D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(276, 0X1130));
    // 0x80515E24: jal         0x80046804
    // 0x80515E28: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x80515E28: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80515E2C: bne         $v0, $zero, L_80515E3C
    if (ctx->r2 != 0) {
        // 0x80515E30: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80515E3C;
    }
    // 0x80515E30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80515E34: b           L_80515ED4
    // 0x80515E38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80515ED4;
    // 0x80515E38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80515E3C:
    // 0x80515E3C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80515E40: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0X113C) << 16);
    // 0x80515E44: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80515E48: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80515E4C: jal         0x80044194
    // 0x80515E50: sw          $t8, 0x65DC($at)
    MEM_W((int16_t)RELOC_LO16(276, 0X113C), ctx->r1) = ctx->r24;
    func_80044194(rdram, ctx);
        goto after_1;
    // 0x80515E50: sw          $t8, 0x65DC($at)
    MEM_W((int16_t)RELOC_LO16(276, 0X113C), ctx->r1) = ctx->r24;
    after_1:
    // 0x80515E54: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80515E58: lw          $t9, -0x71A8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X71A8);
    // 0x80515E5C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80515E60: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE80) << 16);
    // 0x80515E64: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80515E68: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x80515E6C: bne         $t1, $zero, L_80515EA8
    if (ctx->r9 != 0) {
        // 0x80515E70: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80515EA8;
    }
    // 0x80515E70: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80515E74: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE78) << 16);
    // 0x80515E78: lwc1        $f6, 0x6318($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE78));
    // 0x80515E7C: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0X1140) << 16);
    // 0x80515E80: swc1        $f6, 0x65E0($at)
    MEM_W((int16_t)RELOC_LO16(276, 0X1140), ctx->r1) = ctx->f6.u32l;
    // 0x80515E84: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE7C) << 16);
    // 0x80515E88: lwc1        $f8, 0x631C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE7C));
    // 0x80515E8C: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0X1144) << 16);
    // 0x80515E90: swc1        $f8, 0x65E4($at)
    MEM_W((int16_t)RELOC_LO16(276, 0X1144), ctx->r1) = ctx->f8.u32l;
    // 0x80515E94: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80515E98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80515E9C: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0X1148) << 16);
    // 0x80515EA0: b           L_80515ED4
    // 0x80515EA4: swc1        $f10, 0x65E8($at)
    MEM_W((int16_t)RELOC_LO16(276, 0X1148), ctx->r1) = ctx->f10.u32l;
        goto L_80515ED4;
    // 0x80515EA4: swc1        $f10, 0x65E8($at)
    MEM_W((int16_t)RELOC_LO16(276, 0X1148), ctx->r1) = ctx->f10.u32l;
L_80515EA8:
    // 0x80515EA8: lwc1        $f16, 0x6320($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE80));
    // 0x80515EAC: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0X1140) << 16);
    // 0x80515EB0: swc1        $f16, 0x65E0($at)
    MEM_W((int16_t)RELOC_LO16(276, 0X1140), ctx->r1) = ctx->f16.u32l;
    // 0x80515EB4: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE84) << 16);
    // 0x80515EB8: lwc1        $f18, 0x6324($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE84));
    // 0x80515EBC: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0X1144) << 16);
    // 0x80515EC0: swc1        $f18, 0x65E4($at)
    MEM_W((int16_t)RELOC_LO16(276, 0X1144), ctx->r1) = ctx->f18.u32l;
    // 0x80515EC4: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80515EC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80515ECC: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0X1148) << 16);
    // 0x80515ED0: swc1        $f4, 0x65E8($at)
    MEM_W((int16_t)RELOC_LO16(276, 0X1148), ctx->r1) = ctx->f4.u32l;
L_80515ED4:
    // 0x80515ED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80515ED8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80515EDC: jr          $ra
    // 0x80515EE0: nop

    return;
    // 0x80515EE0: nop

    // 0x80515EE4: nop

    // 0x80515EE8: nop

    // 0x80515EEC: nop

;}
RECOMP_FUNC void func_80057B14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057B14: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x80057B18: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x80057B1C: sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
    // 0x80057B20: jr          $ra
    // 0x80057B24: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    return;
    // 0x80057B24: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_800315F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800315F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800315FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031600: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031604: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80031608: jal         0x800310A0
    // 0x8003160C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x8003160C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80031610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80031614: jal         0x80030EE8
    // 0x80031618: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80030EE8(rdram, ctx);
        goto after_1;
    // 0x80031618: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8003161C: beq         $v0, $zero, L_8003162C
    if (ctx->r2 == 0) {
        // 0x80031620: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8003162C;
    }
    // 0x80031620: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80031624: jal         0x8003159C
    // 0x80031628: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8003159C(rdram, ctx);
        goto after_2;
    // 0x80031628: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_8003162C:
    // 0x8003162C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031630: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80031634: jr          $ra
    // 0x80031638: nop

    return;
    // 0x80031638: nop

;}
RECOMP_FUNC void func_8004B154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B154: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8004B158: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004B15C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004B160: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8004B164: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8004B168: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    // 0x8004B16C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8004B170: lh          $t1, 0x10($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X10);
    // 0x8004B174: lw          $t2, 0x174($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X174);
    // 0x8004B178: blez        $v0, L_8004B1EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004B17C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8004B1EC;
    }
    // 0x8004B17C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004B180: lbu         $t3, 0x1($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X1);
    // 0x8004B184: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8004B188: lhu         $a0, 0x2($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X2);
    // 0x8004B18C: srl         $t8, $t3, 6
    ctx->r24 = S32(U32(ctx->r11) >> 6);
    // 0x8004B190: andi        $t4, $t3, 0x3F
    ctx->r12 = ctx->r11 & 0X3F;
    // 0x8004B194: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8004B198: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8004B19C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8004B1A0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8004B1A4: lw          $t7, 0xA24($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XA24);
    // 0x8004B1A8: sll         $t8, $t1, 1
    ctx->r24 = S32(ctx->r9 << 1);
    // 0x8004B1AC: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8004B1B0: sll         $t3, $t0, 1
    ctx->r11 = S32(ctx->r8 << 1);
L_8004B1B4:
    // 0x8004B1B4: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8004B1B8: addu        $t9, $v1, $t4
    ctx->r25 = ADD32(ctx->r3, ctx->r12);
    // 0x8004B1BC: lhu         $t5, 0x0($t9)
    ctx->r13 = MEM_HU(ctx->r25, 0X0);
    // 0x8004B1C0: and         $t6, $t5, $a0
    ctx->r14 = ctx->r13 & ctx->r4;
    // 0x8004B1C4: bnel        $t6, $zero, L_8004B1D8
    if (ctx->r14 != 0) {
        // 0x8004B1C8: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8004B1D8;
    }
    goto skip_0;
    // 0x8004B1C8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x8004B1CC: b           L_8004B3E4
    // 0x8004B1D0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8004B3E4;
    // 0x8004B1D0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8004B1D4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8004B1D8:
    // 0x8004B1D8: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8004B1DC: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8004B1E0: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004B1E4: bnel        $at, $zero, L_8004B1B4
    if (ctx->r1 != 0) {
        // 0x8004B1E8: sll         $t3, $t0, 1
        ctx->r11 = S32(ctx->r8 << 1);
            goto L_8004B1B4;
    }
    goto skip_1;
    // 0x8004B1E8: sll         $t3, $t0, 1
    ctx->r11 = S32(ctx->r8 << 1);
    skip_1:
L_8004B1EC:
    // 0x8004B1EC: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8004B1F0: slti        $at, $t7, 0x11
    ctx->r1 = SIGNED(ctx->r15) < 0X11 ? 1 : 0;
    // 0x8004B1F4: bnel        $at, $zero, L_8004B208
    if (ctx->r1 != 0) {
        // 0x8004B1F8: sh          $t0, 0x38($sp)
        MEM_H(0X38, ctx->r29) = ctx->r8;
            goto L_8004B208;
    }
    goto skip_2;
    // 0x8004B1F8: sh          $t0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r8;
    skip_2:
    // 0x8004B1FC: b           L_8004B3E4
    // 0x8004B200: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8004B3E4;
    // 0x8004B200: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8004B204: sh          $t0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r8;
L_8004B208:
    // 0x8004B208: lhu         $t8, 0x0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X0);
    // 0x8004B20C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8004B210: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004B214: sh          $t8, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r24;
    // 0x8004B218: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004B21C: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x8004B220: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004B224: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004B228: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004B22C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8004B230: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004B234: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8004B238: sh          $t0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r8;
    // 0x8004B23C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8004B240: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8004B244: jal         0x800534C0
    // 0x8004B248: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_800534C0(rdram, ctx);
        goto after_0;
    // 0x8004B248: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_0:
    // 0x8004B24C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8004B250: lh          $t0, 0x3E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3E);
    // 0x8004B254: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8004B258: sh          $v0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r2;
    // 0x8004B25C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8004B260: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x8004B264: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8004B268: andi        $t6, $v0, 0x7FF
    ctx->r14 = ctx->r2 & 0X7FF;
    // 0x8004B26C: andi        $t9, $t4, 0xF8
    ctx->r25 = ctx->r12 & 0XF8;
    // 0x8004B270: bnel        $t9, $at, L_8004B280
    if (ctx->r25 != ctx->r1) {
        // 0x8004B274: lhu         $v0, 0x0($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X0);
            goto L_8004B280;
    }
    goto skip_3;
    // 0x8004B274: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    skip_3:
    // 0x8004B278: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x8004B27C: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
L_8004B280:
    // 0x8004B280: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004B284: beql        $v0, $zero, L_8004B3E4
    if (ctx->r2 == 0) {
        // 0x8004B288: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8004B3E4;
    }
    goto skip_4;
    // 0x8004B288: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    skip_4:
    // 0x8004B28C: beql        $v0, $at, L_8004B3E4
    if (ctx->r2 == ctx->r1) {
        // 0x8004B290: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8004B3E4;
    }
    goto skip_5;
    // 0x8004B290: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    skip_5:
    // 0x8004B294: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004B298: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004B29C: andi        $v1, $v0, 0xF8
    ctx->r3 = ctx->r2 & 0XF8;
    // 0x8004B2A0: beq         $v1, $at, L_8004B3E0
    if (ctx->r3 == ctx->r1) {
        // 0x8004B2A4: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004B3E0;
    }
    // 0x8004B2A4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004B2A8: beq         $v1, $at, L_8004B3E0
    if (ctx->r3 == ctx->r1) {
        // 0x8004B2AC: andi        $t7, $v0, 0x2
        ctx->r15 = ctx->r2 & 0X2;
            goto L_8004B3E0;
    }
    // 0x8004B2AC: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x8004B2B0: beq         $t7, $zero, L_8004B3E0
    if (ctx->r15 == 0) {
        // 0x8004B2B4: sll         $t4, $a1, 2
        ctx->r12 = S32(ctx->r5 << 2);
            goto L_8004B3E0;
    }
    // 0x8004B2B4: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8004B2B8: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8004B2BC: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x8004B2C0: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x8004B2C4: lw          $t3, 0x40($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X40);
    // 0x8004B2C8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8004B2CC: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8004B2D0: andi        $t8, $v0, 0x3F
    ctx->r24 = ctx->r2 & 0X3F;
    // 0x8004B2D4: srl         $t6, $v0, 6
    ctx->r14 = S32(U32(ctx->r2) >> 6);
    // 0x8004B2D8: addu        $t1, $t3, $t4
    ctx->r9 = ADD32(ctx->r11, ctx->r12);
    // 0x8004B2DC: sh          $t9, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r25;
    // 0x8004B2E0: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x8004B2E4: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8004B2E8: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8004B2EC: sh          $t5, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r13;
    // 0x8004B2F0: addu        $t4, $t7, $t3
    ctx->r12 = ADD32(ctx->r15, ctx->r11);
    // 0x8004B2F4: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8004B2F8: lh          $t5, 0x10($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X10);
    // 0x8004B2FC: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x8004B300: lw          $t9, 0xA24($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XA24);
    // 0x8004B304: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8004B308: lhu         $t3, 0x2($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X2);
    // 0x8004B30C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8004B310: lhu         $t7, 0x0($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X0);
    // 0x8004B314: and         $t4, $t7, $t3
    ctx->r12 = ctx->r15 & ctx->r11;
    // 0x8004B318: beql        $t4, $zero, L_8004B3E4
    if (ctx->r12 == 0) {
        // 0x8004B31C: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8004B3E4;
    }
    goto skip_6;
    // 0x8004B31C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    skip_6:
    // 0x8004B320: lhu         $t5, 0x0($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X0);
    // 0x8004B324: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8004B328: sh          $t5, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r13;
    // 0x8004B32C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8004B330: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8004B334: sh          $t0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r8;
    // 0x8004B338: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8004B33C: jal         0x8004B154
    // 0x8004B340: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_8004B154(rdram, ctx);
        goto after_1;
    // 0x8004B340: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_1:
    // 0x8004B344: lh          $t0, 0x3E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3E);
    // 0x8004B348: lbu         $v1, 0x36($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X36);
    // 0x8004B34C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8004B350: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x8004B354: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8004B358: andi        $a0, $v1, 0x2
    ctx->r4 = ctx->r3 & 0X2;
    // 0x8004B35C: beq         $a0, $zero, L_8004B3A4
    if (ctx->r4 == 0) {
        // 0x8004B360: sra         $t0, $t0, 16
        ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
            goto L_8004B3A4;
    }
    // 0x8004B360: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8004B364: lbu         $v0, 0x34($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X34);
    // 0x8004B368: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8004B36C: bne         $t9, $zero, L_8004B378
    if (ctx->r25 != 0) {
        // 0x8004B370: andi        $t6, $v0, 0x2
        ctx->r14 = ctx->r2 & 0X2;
            goto L_8004B378;
    }
    // 0x8004B370: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x8004B374: bne         $t6, $zero, L_8004B3E0
    if (ctx->r14 != 0) {
        // 0x8004B378: andi        $t8, $v0, 0x2
        ctx->r24 = ctx->r2 & 0X2;
            goto L_8004B3E0;
    }
L_8004B378:
    // 0x8004B378: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x8004B37C: beq         $t8, $zero, L_8004B38C
    if (ctx->r24 == 0) {
        // 0x8004B380: slti        $at, $t0, 0x13
        ctx->r1 = SIGNED(ctx->r8) < 0X13 ? 1 : 0;
            goto L_8004B38C;
    }
    // 0x8004B380: slti        $at, $t0, 0x13
    ctx->r1 = SIGNED(ctx->r8) < 0X13 ? 1 : 0;
    // 0x8004B384: bnel        $at, $zero, L_8004B3E4
    if (ctx->r1 != 0) {
        // 0x8004B388: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8004B3E4;
    }
    goto skip_7;
    // 0x8004B388: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    skip_7:
L_8004B38C:
    // 0x8004B38C: lhu         $t7, 0x36($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X36);
    // 0x8004B390: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x8004B394: lhu         $t3, 0x36($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X36);
    // 0x8004B398: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x8004B39C: b           L_8004B3E4
    // 0x8004B3A0: lh          $v0, 0x38($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X38);
        goto L_8004B3E4;
    // 0x8004B3A0: lh          $v0, 0x38($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X38);
L_8004B3A4:
    // 0x8004B3A4: andi        $t4, $v1, 0x1
    ctx->r12 = ctx->r3 & 0X1;
    // 0x8004B3A8: bnel        $t4, $zero, L_8004B3E4
    if (ctx->r12 != 0) {
        // 0x8004B3AC: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8004B3E4;
    }
    goto skip_8;
    // 0x8004B3AC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    skip_8:
    // 0x8004B3B0: bne         $a0, $zero, L_8004B3E0
    if (ctx->r4 != 0) {
        // 0x8004B3B4: andi        $t5, $v1, 0x4
        ctx->r13 = ctx->r3 & 0X4;
            goto L_8004B3E0;
    }
    // 0x8004B3B4: andi        $t5, $v1, 0x4
    ctx->r13 = ctx->r3 & 0X4;
    // 0x8004B3B8: beq         $t5, $zero, L_8004B3E0
    if (ctx->r13 == 0) {
        // 0x8004B3BC: lbu         $t9, 0x34($sp)
        ctx->r25 = MEM_BU(ctx->r29, 0X34);
            goto L_8004B3E0;
    }
    // 0x8004B3BC: lbu         $t9, 0x34($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X34);
    // 0x8004B3C0: andi        $t6, $t9, 0x2
    ctx->r14 = ctx->r25 & 0X2;
    // 0x8004B3C4: beq         $t6, $zero, L_8004B3D4
    if (ctx->r14 == 0) {
        // 0x8004B3C8: slti        $at, $t0, 0x13
        ctx->r1 = SIGNED(ctx->r8) < 0X13 ? 1 : 0;
            goto L_8004B3D4;
    }
    // 0x8004B3C8: slti        $at, $t0, 0x13
    ctx->r1 = SIGNED(ctx->r8) < 0X13 ? 1 : 0;
    // 0x8004B3CC: bnel        $at, $zero, L_8004B3E4
    if (ctx->r1 != 0) {
        // 0x8004B3D0: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8004B3E4;
    }
    goto skip_9;
    // 0x8004B3D0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    skip_9:
L_8004B3D4:
    // 0x8004B3D4: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x8004B3D8: b           L_8004B3E4
    // 0x8004B3DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004B3E4;
    // 0x8004B3DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004B3E0:
    // 0x8004B3E0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8004B3E4:
    // 0x8004B3E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004B3E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004B3EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8004B3F0: jr          $ra
    // 0x8004B3F4: nop

    return;
    // 0x8004B3F4: nop

;}
RECOMP_FUNC void func_806993B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806993B0: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(559, 0X18) << 16);
    // 0x806993B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x806993B8: jr          $ra
    // 0x806993BC: addiu       $v0, $v0, -0x6C38
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(559, 0X18));
    return;
    // 0x806993BC: addiu       $v0, $v0, -0x6C38
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(559, 0X18));
;}
RECOMP_FUNC void func_80032E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032E38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032E3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032E40: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80032E44: beql        $t6, $zero, L_80032E58
    if (ctx->r14 == 0) {
        // 0x80032E48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80032E58;
    }
    goto skip_0;
    // 0x80032E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80032E4C: jal         0x80038F98
    // 0x80032E50: nop

    func_80038F98(rdram, ctx);
        goto after_0;
    // 0x80032E50: nop

    after_0:
    // 0x80032E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80032E58:
    // 0x80032E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032E5C: jr          $ra
    // 0x80032E60: nop

    return;
    // 0x80032E60: nop

;}
RECOMP_FUNC void func_8006515C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006515C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80065160: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80065164: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80065168: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006516C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80065170: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80065174: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x80065178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006517C: slt         $at, $t8, $a1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80065180: bne         $at, $zero, L_800651A8
    if (ctx->r1 != 0) {
        // 0x80065184: nop
    
            goto L_800651A8;
    }
    // 0x80065184: nop

    // 0x80065188: bne         $a2, $zero, L_8006519C
    if (ctx->r6 != 0) {
        // 0x8006518C: addiu       $t9, $a1, -0x1
        ctx->r25 = ADD32(ctx->r5, -0X1);
            goto L_8006519C;
    }
    // 0x8006518C: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x80065190: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80065194: jr          $ra
    // 0x80065198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80065198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006519C:
    // 0x8006519C: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x800651A0: jr          $ra
    // 0x800651A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800651A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800651A8:
    // 0x800651A8: jr          $ra
    // 0x800651AC: nop

    return;
    // 0x800651AC: nop

;}
RECOMP_FUNC void func_806B2434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2434: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806B2438: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806B243C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B2440: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806B2444: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806B2448: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806B244C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x806B2450: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x806B2454: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B2458: addiu       $t6, $zero, 0x9D8
    ctx->r14 = ADD32(0, 0X9D8);
    // 0x806B245C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806B2460: addiu       $a2, $zero, 0x7BC
    ctx->r6 = ADD32(0, 0X7BC);
    // 0x806B2464: addiu       $a3, $zero, 0x8E8
    ctx->r7 = ADD32(0, 0X8E8);
    // 0x806B2468: addiu       $a1, $zero, 0x6CC
    ctx->r5 = ADD32(0, 0X6CC);
    // 0x806B246C: jal         0x806B1BC4
    // 0x806B2470: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_806B1BC4(rdram, ctx);
        goto after_0;
    // 0x806B2470: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x806B2474: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806B2478: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B247C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806B2480: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B2484: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x806B2488: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x806B248C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806B2490: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806B2494: jr          $ra
    // 0x806B2498: nop

    return;
    // 0x806B2498: nop

;}
RECOMP_FUNC void func_805AE784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE784: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE788: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE78C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE790: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE794: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE798: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE79C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE7A0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE7A4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE7A8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE7AC: jr          $ra
    // 0x805AE7B0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE7B0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806CE938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CE938: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806CE93C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CE940: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806CE944: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806CE948: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806CE94C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806CE950: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806CE954: lw          $s1, 0x180($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X180);
    // 0x806CE958: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806CE95C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x806CE960: lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1F4);
    // 0x806CE964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806CE968: jal         0x806CB78C
    // 0x806CE96C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_806CB78C(rdram, ctx);
        goto after_0;
    // 0x806CE96C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x806CE970: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806CE974: lw          $t6, 0x874($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X874);
    // 0x806CE978: bnel        $s0, $t6, L_806CEA48
    if (ctx->r16 != ctx->r14) {
        // 0x806CE97C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806CEA48;
    }
    goto skip_0;
    // 0x806CE97C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806CE980: lh          $t7, 0x872($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X872);
    // 0x806CE984: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806CE988: addiu       $a1, $zero, 0x279
    ctx->r5 = ADD32(0, 0X279);
    // 0x806CE98C: bnel        $t7, $zero, L_806CEA48
    if (ctx->r15 != 0) {
        // 0x806CE990: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806CEA48;
    }
    goto skip_1;
    // 0x806CE990: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806CE994: jal         0x806CB8BC
    // 0x806CE998: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_806CB8BC(rdram, ctx);
        goto after_1;
    // 0x806CE998: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x806CE99C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806CE9A0: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x806CE9A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CE9A8: sh          $t8, 0x872($v0)
    MEM_H(0X872, ctx->r2) = ctx->r24;
    // 0x806CE9AC: lw          $t9, 0x1E4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1E4);
    // 0x806CE9B0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x806CE9B4: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x806CE9B8: bne         $at, $zero, L_806CEA44
    if (ctx->r1 != 0) {
        // 0x806CE9BC: sw          $t0, 0x1E4($s0)
        MEM_W(0X1E4, ctx->r16) = ctx->r8;
            goto L_806CEA44;
    }
    // 0x806CE9BC: sw          $t0, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r8;
    // 0x806CE9C0: jal         0x80048060
    // 0x806CE9C4: sw          $zero, 0x874($v0)
    MEM_W(0X874, ctx->r2) = 0;
    func_80048060(rdram, ctx);
        goto after_2;
    // 0x806CE9C4: sw          $zero, 0x874($v0)
    MEM_W(0X874, ctx->r2) = 0;
    after_2:
    // 0x806CE9C8: jal         0x800440E4
    // 0x806CE9CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800440E4(rdram, ctx);
        goto after_3;
    // 0x806CE9CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806CE9D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CE9D4: jal         0x8003E478
    // 0x806CE9D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8003E478(rdram, ctx);
        goto after_4;
    // 0x806CE9D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x806CE9DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806CE9E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CE9E4: jal         0x806CED40
    // 0x806CE9E8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_806CED40(rdram, ctx);
        goto after_5;
    // 0x806CE9E8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x806CE9EC: jal         0x806CCCE4
    // 0x806CE9F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806CCCE4(rdram, ctx);
        goto after_6;
    // 0x806CE9F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x806CE9F4: jal         0x80049018
    // 0x806CE9F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80049018(rdram, ctx);
        goto after_7;
    // 0x806CE9F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x806CE9FC: beq         $v0, $zero, L_806CEA18
    if (ctx->r2 == 0) {
        // 0x806CEA00: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_806CEA18;
    }
    // 0x806CEA00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806CEA04: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806CEA08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806CEA0C: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806CEA10: b           L_806CEA24
    // 0x806CEA14: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
        goto L_806CEA24;
    // 0x806CEA14: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_806CEA18:
    // 0x806CEA18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806CEA1C: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806CEA20: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_806CEA24:
    // 0x806CEA24: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x806CEA28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806CEA2C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C6C) << 16);
    // 0x806CEA30: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x806CEA34: lwc1        $f16, -0xC74($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C6C));
    // 0x806CEA38: lwc1        $f10, 0x8C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8C);
    // 0x806CEA3C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806CEA40: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
L_806CEA44:
    // 0x806CEA44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806CEA48:
    // 0x806CEA48: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806CEA4C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806CEA50: jr          $ra
    // 0x806CEA54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x806CEA54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80467CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80467CA4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80467CA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80467CAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80467CB0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80467CB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80467CB8: lh          $t6, 0x1A($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1A);
    // 0x80467CBC: lh          $t7, 0x18($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X18);
    // 0x80467CC0: lw          $t9, 0x1FA0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1FA0);
    // 0x80467CC4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80467CC8: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467CCC: mflo        $t8
    ctx->r24 = lo;
    // 0x80467CD0: nop

    // 0x80467CD4: nop

    // 0x80467CD8: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467CDC: mflo        $t0
    ctx->r8 = lo;
    // 0x80467CE0: addu        $a1, $t0, $v1
    ctx->r5 = ADD32(ctx->r8, ctx->r3);
    // 0x80467CE4: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x80467CE8: jal         0x80467610
    // 0x80467CEC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_80467610(rdram, ctx);
        goto after_0;
    // 0x80467CEC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x80467CF0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80467CF4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80467CF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80467CFC: lh          $t1, 0x1A($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X1A);
    // 0x80467D00: lh          $t2, 0x18($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X18);
    // 0x80467D04: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467D08: mflo        $a2
    ctx->r6 = lo;
    // 0x80467D0C: sra         $a2, $a2, 2
    ctx->r6 = S32(SIGNED(ctx->r6) >> 2);
    // 0x80467D10: blez        $a2, L_80467D60
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80467D14: andi        $v1, $a2, 0x3
        ctx->r3 = ctx->r6 & 0X3;
            goto L_80467D60;
    }
    // 0x80467D14: andi        $v1, $a2, 0x3
    ctx->r3 = ctx->r6 & 0X3;
    // 0x80467D18: beq         $v1, $zero, L_80467D3C
    if (ctx->r3 == 0) {
        // 0x80467D1C: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80467D3C;
    }
    // 0x80467D1C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80467D20: lui         $v1, 0x4040
    ctx->r3 = S32(0X4040 << 16);
    // 0x80467D24: ori         $v1, $v1, 0x4040
    ctx->r3 = ctx->r3 | 0X4040;
L_80467D28:
    // 0x80467D28: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80467D2C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80467D30: bne         $a1, $a0, L_80467D28
    if (ctx->r5 != ctx->r4) {
        // 0x80467D34: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80467D28;
    }
    // 0x80467D34: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80467D38: beq         $a0, $a2, L_80467D60
    if (ctx->r4 == ctx->r6) {
        // 0x80467D3C: lui         $v1, 0x4040
        ctx->r3 = S32(0X4040 << 16);
            goto L_80467D60;
    }
L_80467D3C:
    // 0x80467D3C: lui         $v1, 0x4040
    ctx->r3 = S32(0X4040 << 16);
    // 0x80467D40: ori         $v1, $v1, 0x4040
    ctx->r3 = ctx->r3 | 0X4040;
L_80467D44:
    // 0x80467D44: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80467D48: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80467D4C: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x80467D50: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80467D54: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80467D58: bne         $a0, $a2, L_80467D44
    if (ctx->r4 != ctx->r6) {
        // 0x80467D5C: sw          $v1, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->r3;
            goto L_80467D44;
    }
    // 0x80467D5C: sw          $v1, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r3;
L_80467D60:
    // 0x80467D60: jal         0x8046790C
    // 0x80467D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046790C(rdram, ctx);
        goto after_1;
    // 0x80467D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80467D68: jal         0x80467B0C
    // 0x80467D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80467B0C(rdram, ctx);
        goto after_2;
    // 0x80467D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80467D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80467D74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80467D78: jal         0x804686B4
    // 0x80467D7C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_804686B4(rdram, ctx);
        goto after_3;
    // 0x80467D7C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x80467D80: jal         0x80466950
    // 0x80467D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80466950(rdram, ctx);
        goto after_4;
    // 0x80467D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80467D88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80467D8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80467D90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80467D94: jr          $ra
    // 0x80467D98: nop

    return;
    // 0x80467D98: nop

;}
RECOMP_FUNC void func_80675C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675C30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80675C34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80675C38: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80675C3C: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80675C40: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80675C44: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80675C48: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80675C4C: bne         $at, $zero, L_80675CBC
    if (ctx->r1 != 0) {
        // 0x80675C50: sb          $t7, 0x1($v0)
        MEM_B(0X1, ctx->r2) = ctx->r15;
            goto L_80675CBC;
    }
    // 0x80675C50: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    // 0x80675C54: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80675C58: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80675C5C: lui         $t2, 0x8067
    ctx->r10 = S32(RELOC_HI16(535, 0X2528) << 16);
    // 0x80675C60: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80675C64: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x80675C68: lbu         $t1, 0x30($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X30);
    // 0x80675C6C: andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
    // 0x80675C70: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80675C74: lbu         $t2, 0x7BE8($t2)
    ctx->r10 = MEM_BU(ctx->r10, (int16_t)RELOC_LO16(535, 0X2528));
    // 0x80675C78: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80675C7C: bnel        $at, $zero, L_80675C98
    if (ctx->r1 != 0) {
        // 0x80675C80: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80675C98;
    }
    goto skip_0;
    // 0x80675C80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x80675C84: jal         0x80675B9C
    // 0x80675C88: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80675B9C(rdram, ctx);
        goto after_0;
    // 0x80675C88: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_0:
    // 0x80675C8C: b           L_80675CC0
    // 0x80675C90: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80675CC0;
    // 0x80675C90: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80675C94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80675C98:
    // 0x80675C98: bne         $v1, $at, L_80675CAC
    if (ctx->r3 != ctx->r1) {
        // 0x80675C9C: addiu       $a1, $zero, 0x235
        ctx->r5 = ADD32(0, 0X235);
            goto L_80675CAC;
    }
    // 0x80675C9C: addiu       $a1, $zero, 0x235
    ctx->r5 = ADD32(0, 0X235);
    // 0x80675CA0: jal         0x80675738
    // 0x80675CA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80675738(rdram, ctx);
        goto after_1;
    // 0x80675CA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80675CA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80675CAC:
    // 0x80675CAC: jal         0x80675B9C
    // 0x80675CB0: nop

    func_80675B9C(rdram, ctx);
        goto after_2;
    // 0x80675CB0: nop

    after_2:
    // 0x80675CB4: b           L_80675CC0
    // 0x80675CB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80675CC0;
    // 0x80675CB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80675CBC:
    // 0x80675CBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80675CC0:
    // 0x80675CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80675CC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80675CC8: jr          $ra
    // 0x80675CCC: nop

    return;
    // 0x80675CCC: nop

;}
RECOMP_FUNC void func_80447E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447E88: jr          $ra
    // 0x80447E8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80447E8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8041E734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041E734: lwc1        $f2, 0x88($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8041E738: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8041E73C: lwc1        $f0, 0x84($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8041E740: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8041E744: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8041E748: nop

    // 0x8041E74C: bc1fl       L_8041E764
    if (!c1cs) {
        // 0x8041E750: lwc1        $f8, 0x28($a1)
        ctx->f8.u32l = MEM_W(ctx->r5, 0X28);
            goto L_8041E764;
    }
    goto skip_0;
    // 0x8041E750: lwc1        $f8, 0x28($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X28);
    skip_0:
    // 0x8041E754: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8041E758: b           L_8041E784
    // 0x8041E75C: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
        goto L_8041E784;
    // 0x8041E75C: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    // 0x8041E760: lwc1        $f8, 0x28($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X28);
L_8041E764:
    // 0x8041E764: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8041E768: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8041E76C: nop

    // 0x8041E770: bc1fl       L_8041E788
    if (!c1cs) {
        // 0x8041E774: lwc1        $f16, 0x1C($a1)
        ctx->f16.u32l = MEM_W(ctx->r5, 0X1C);
            goto L_8041E788;
    }
    goto skip_1;
    // 0x8041E774: lwc1        $f16, 0x1C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X1C);
    skip_1:
    // 0x8041E778: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8041E77C: nop

    // 0x8041E780: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
L_8041E784:
    // 0x8041E784: lwc1        $f16, 0x1C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X1C);
L_8041E788:
    // 0x8041E788: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8041E78C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8041E790: nop

    // 0x8041E794: bc1fl       L_8041E7AC
    if (!c1cs) {
        // 0x8041E798: lwc1        $f4, 0x20($a1)
        ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
            goto L_8041E7AC;
    }
    goto skip_2;
    // 0x8041E798: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    skip_2:
    // 0x8041E79C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8041E7A0: jr          $ra
    // 0x8041E7A4: swc1        $f18, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x8041E7A4: swc1        $f18, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f18.u32l;
    // 0x8041E7A8: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
L_8041E7AC:
    // 0x8041E7AC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8041E7B0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8041E7B4: nop

    // 0x8041E7B8: bc1f        L_8041E7CC
    if (!c1cs) {
        // 0x8041E7BC: nop
    
            goto L_8041E7CC;
    }
    // 0x8041E7BC: nop

    // 0x8041E7C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8041E7C4: nop

    // 0x8041E7C8: swc1        $f6, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f6.u32l;
L_8041E7CC:
    // 0x8041E7CC: jr          $ra
    // 0x8041E7D0: nop

    return;
    // 0x8041E7D0: nop

;}
RECOMP_FUNC void sinf_recomp(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void func_8064B9F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B9F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B9FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064BA00: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8064BA04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8064BA08: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064BA0C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064BA10: nop

    // 0x8064BA14: bc1fl       L_8064BA5C
    if (!c1cs) {
        // 0x8064BA18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064BA5C;
    }
    goto skip_0;
    // 0x8064BA18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064BA1C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064BA20: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064BA24: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8064BA28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8064BA2C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8064BA30: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8064BA34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064BA38: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8064BA3C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8064BA40: nop

    // 0x8064BA44: bc1fl       L_8064BA5C
    if (!c1cs) {
        // 0x8064BA48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064BA5C;
    }
    goto skip_1;
    // 0x8064BA48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8064BA4C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064BA50: jal         0x8064BF74
    // 0x8064BA54: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064BF74(rdram, ctx);
        goto after_0;
    // 0x8064BA54: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064BA58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064BA5C:
    // 0x8064BA5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064BA60: jr          $ra
    // 0x8064BA64: nop

    return;
    // 0x8064BA64: nop

;}
RECOMP_FUNC void func_807809CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807809CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807809D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807809D4: jal         0x80780260
    // 0x807809D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80780260(rdram, ctx);
        goto after_0;
    // 0x807809D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807809DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807809E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807809E4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x807809E8: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x807809EC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x807809F0: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x807809F4: bne         $at, $zero, L_80780A14
    if (ctx->r1 != 0) {
        // 0x807809F8: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_80780A14;
    }
    // 0x807809F8: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x807809FC: jal         0x807813F0
    // 0x80780A00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807813F0(rdram, ctx);
        goto after_1;
    // 0x80780A00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80780A04: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(784, 0X6660) << 16);
    // 0x80780A08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80780A0C: lwc1        $f4, 0x6850($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(784, 0X6660));
    // 0x80780A10: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
L_80780A14:
    // 0x80780A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80780A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80780A1C: jr          $ra
    // 0x80780A20: nop

    return;
    // 0x80780A20: nop

;}
RECOMP_FUNC void func_806E7680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7680: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806E7684: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806E7688: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806E768C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806E7690: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E7694: jal         0x806E7B70
    // 0x806E7698: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    func_806E7B70(rdram, ctx);
        goto after_0;
    // 0x806E7698: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    after_0:
    // 0x806E769C: bne         $v0, $zero, L_806E770C
    if (ctx->r2 != 0) {
        // 0x806E76A0: nop
    
            goto L_806E770C;
    }
    // 0x806E76A0: nop

    // 0x806E76A4: jal         0x806E72B8
    // 0x806E76A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E72B8(rdram, ctx);
        goto after_1;
    // 0x806E76A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806E76AC: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x806E76B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806E76B4: nop

    // 0x806E76B8: mul.s       $f12, $f20, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x806E76BC: jal         0x80066E88
    // 0x806E76C0: nop

    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x806E76C0: nop

    after_2:
    // 0x806E76C4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x806E76C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806E76CC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806E76D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806E76D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E76D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E76DC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806E76E0: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x806E76E4: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x806E76E8: nop

    // 0x806E76EC: bc1f        L_806E76FC
    if (!c1cs) {
        // 0x806E76F0: nop
    
            goto L_806E76FC;
    }
    // 0x806E76F0: nop

    // 0x806E76F4: b           L_806E7714
    // 0x806E76F8: swc1        $f20, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
        goto L_806E7714;
    // 0x806E76F8: swc1        $f20, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
L_806E76FC:
    // 0x806E76FC: jal         0x806E7E4C
    // 0x806E7700: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
    func_806E7E4C(rdram, ctx);
        goto after_3;
    // 0x806E7700: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
    after_3:
    // 0x806E7704: b           L_806E7718
    // 0x806E7708: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_806E7718;
    // 0x806E7708: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806E770C:
    // 0x806E770C: jal         0x806E7328
    // 0x806E7710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E7328(rdram, ctx);
        goto after_4;
    // 0x806E7710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_806E7714:
    // 0x806E7714: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806E7718:
    // 0x806E7718: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806E771C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806E7720: jr          $ra
    // 0x806E7724: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x806E7724: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_804F3F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F3F54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804F3F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F3F5C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804F3F60: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804F3F64: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804F3F68: lui         $t8, 0x804F
    ctx->r24 = S32(RELOC_HI16(270, 0XE00) << 16);
    // 0x804F3F6C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804F3F70: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804F3F74: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804F3F78: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804F3F7C: lw          $t8, 0x4130($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(270, 0XE00));
    // 0x804F3F80: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804F3F84: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804F3F88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804F3F8C: jal         0x80048490
    // 0x804F3F90: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804F3F90: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804F3F94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804F3F98: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x804F3F9C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x804F3FA0: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804F3FA4: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x804F3FA8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804F3FAC: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x804F3FB0: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804F3FB4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804F3FB8: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
    // 0x804F3FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F3FC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804F3FC4: jr          $ra
    // 0x804F3FC8: nop

    return;
    // 0x804F3FC8: nop

;}
RECOMP_FUNC void func_80665110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80665110: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80665114: lui         $t8, 0x8066
    ctx->r24 = S32(RELOC_HI16(504, 0X2768) << 16);
    // 0x80665118: addiu       $t8, $t8, 0x7438
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(504, 0X2768));
    // 0x8066511C: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80665120: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80665124: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80665128: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8066512C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80665130: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80665134: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80665138: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8066513C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80665140: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80665144:
    // 0x80665144: lbu         $t9, 0x165($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X165);
    // 0x80665148: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x8066514C: sb          $t9, 0x165($t0)
    MEM_B(0X165, ctx->r8) = ctx->r25;
    // 0x80665150: lw          $t2, 0x138($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X138);
    // 0x80665154: lw          $t1, 0x14($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X14);
    // 0x80665158: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8066515C: xor         $t3, $t1, $t2
    ctx->r11 = ctx->r9 ^ ctx->r10;
    // 0x80665160: sw          $t3, 0x138($t4)
    MEM_W(0X138, ctx->r12) = ctx->r11;
    // 0x80665164: lw          $t5, 0x138($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X138);
    // 0x80665168: beql        $t5, $zero, L_80665198
    if (ctx->r13 == 0) {
        // 0x8066516C: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_80665198;
    }
    goto skip_0;
    // 0x8066516C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x80665170: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80665174: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80665178: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8066517C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80665180: nop

    // 0x80665184: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80665188: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8066518C: b           L_806651B0
    // 0x80665190: swc1        $f10, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f10.u32l;
        goto L_806651B0;
    // 0x80665190: swc1        $f10, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f10.u32l;
    // 0x80665194: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
L_80665198:
    // 0x80665198: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8066519C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x806651A0: nop

    // 0x806651A4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806651A8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x806651AC: swc1        $f4, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f4.u32l;
L_806651B0:
    // 0x806651B0: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x806651B4: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x806651B8: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x806651BC: nop

    // 0x806651C0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806651C4: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x806651C8: beq         $a2, $zero, L_806651F4
    if (ctx->r6 == 0) {
        // 0x806651CC: swc1        $f10, 0x40($t1)
        MEM_W(0X40, ctx->r9) = ctx->f10.u32l;
            goto L_806651F4;
    }
    // 0x806651CC: swc1        $f10, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f10.u32l;
    // 0x806651D0: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x806651D4: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x806651D8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806651DC: swc1        $f18, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->f18.u32l;
    // 0x806651E0: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x806651E4: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x806651E8: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x806651EC: b           L_80665220
    // 0x806651F0: swc1        $f6, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f6.u32l;
        goto L_80665220;
    // 0x806651F0: swc1        $f6, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f6.u32l;
L_806651F4:
    // 0x806651F4: lw          $t4, 0x20($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X20);
    // 0x806651F8: beql        $t4, $zero, L_80665224
    if (ctx->r12 == 0) {
        // 0x806651FC: lw          $t7, 0x138($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X138);
            goto L_80665224;
    }
    goto skip_1;
    // 0x806651FC: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    skip_1:
    // 0x80665200: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80665204: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80665208: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8066520C: swc1        $f10, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f10.u32l;
    // 0x80665210: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80665214: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80665218: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8066521C: swc1        $f18, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f18.u32l;
L_80665220:
    // 0x80665220: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
L_80665224:
    // 0x80665224: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80665228: beql        $t7, $zero, L_80665248
    if (ctx->r15 == 0) {
        // 0x8066522C: lwc1        $f8, 0x10($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
            goto L_80665248;
    }
    goto skip_2;
    // 0x8066522C: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    skip_2:
    // 0x80665230: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80665234: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80665238: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8066523C: b           L_80665250
    // 0x80665240: swc1        $f6, 0x50($t8)
    MEM_W(0X50, ctx->r24) = ctx->f6.u32l;
        goto L_80665250;
    // 0x80665240: swc1        $f6, 0x50($t8)
    MEM_W(0X50, ctx->r24) = ctx->f6.u32l;
    // 0x80665244: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
L_80665248:
    // 0x80665248: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8066524C: swc1        $f8, 0x50($t9)
    MEM_W(0X50, ctx->r25) = ctx->f8.u32l;
L_80665250:
    // 0x80665250: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80665254: bne         $a2, $a3, L_80665144
    if (ctx->r6 != ctx->r7) {
        // 0x80665258: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80665144;
    }
    // 0x80665258: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8066525C: jr          $ra
    // 0x80665260: nop

    return;
    // 0x80665260: nop

;}
RECOMP_FUNC void func_8042BD04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042BD04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8042BD08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042BD0C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8042BD10: jal         0x8004700C
    // 0x8042BD14: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8042BD14: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042BD18: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8042BD1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8042BD20: beq         $v0, $zero, L_8042BF04
    if (ctx->r2 == 0) {
        // 0x8042BD24: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_8042BF04;
    }
    // 0x8042BD24: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042BD28: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8042BD2C: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8042BD30: lwc1        $f10, 0x84($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8042BD34: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8042BD38: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8042BD3C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042BD40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8042BD44: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8042BD48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8042BD4C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X3024) << 16);
    // 0x8042BD50: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8042BD54: lwc1        $f4, -0x273C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X3024));
    // 0x8042BD58: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8042BD5C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8042BD60: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x8042BD64: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X3028) << 16);
    // 0x8042BD68: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8042BD6C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8042BD70: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8042BD74: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8042BD78: lwc1        $f18, -0x2738($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X3028));
    // 0x8042BD7C: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8042BD80: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8042BD84: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8042BD88: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8042BD8C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8042BD90: nop

    // 0x8042BD94: bc1fl       L_8042BDA8
    if (!c1cs) {
        // 0x8042BD98: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8042BDA8;
    }
    goto skip_0;
    // 0x8042BD98: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x8042BD9C: b           L_8042BDC0
    // 0x8042BDA0: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
        goto L_8042BDC0;
    // 0x8042BDA0: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x8042BDA4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8042BDA8:
    // 0x8042BDA8: nop

    // 0x8042BDAC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8042BDB0: nop

    // 0x8042BDB4: bc1fl       L_8042BDC4
    if (!c1cs) {
        // 0x8042BDB8: lw          $t7, 0xC($v1)
        ctx->r15 = MEM_W(ctx->r3, 0XC);
            goto L_8042BDC4;
    }
    goto skip_1;
    // 0x8042BDB8: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    skip_1:
    // 0x8042BDBC: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_8042BDC0:
    // 0x8042BDC0: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
L_8042BDC4:
    // 0x8042BDC4: sw          $t7, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r15;
    // 0x8042BDC8: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8042BDCC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8042BDD0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8042BDD4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8042BDD8: jal         0x80065954
    // 0x8042BDDC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8042BDDC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8042BDE0: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X302C) << 16);
    // 0x8042BDE4: lwc1        $f8, -0x2734($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X302C));
    // 0x8042BDE8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8042BDEC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8042BDF0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8042BDF4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8042BDF8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8042BDFC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8042BE00: bc1fl       L_8042BE38
    if (!c1cs) {
        // 0x8042BE04: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8042BE38;
    }
    goto skip_2;
    // 0x8042BE04: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_2:
    // 0x8042BE08: lwc1        $f6, 0x84($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X84);
    // 0x8042BE0C: lwc1        $f10, 0x84($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8042BE10: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8042BE14: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8042BE18: nop

    // 0x8042BE1C: bc1f        L_8042BE2C
    if (!c1cs) {
        // 0x8042BE20: nop
    
            goto L_8042BE2C;
    }
    // 0x8042BE20: nop

    // 0x8042BE24: b           L_8042BE9C
    // 0x8042BE28: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
        goto L_8042BE9C;
    // 0x8042BE28: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
L_8042BE2C:
    // 0x8042BE2C: b           L_8042BE9C
    // 0x8042BE30: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
        goto L_8042BE9C;
    // 0x8042BE30: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8042BE34: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8042BE38:
    // 0x8042BE38: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8042BE3C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8042BE40: nop

    // 0x8042BE44: bc1fl       L_8042BE74
    if (!c1cs) {
        // 0x8042BE48: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8042BE74;
    }
    goto skip_3;
    // 0x8042BE48: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_3:
    // 0x8042BE4C: lwc1        $f16, 0x84($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X84);
    // 0x8042BE50: lwc1        $f18, 0x84($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8042BE54: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8042BE58: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8042BE5C: nop

    // 0x8042BE60: bc1fl       L_8042BE74
    if (!c1cs) {
        // 0x8042BE64: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8042BE74;
    }
    goto skip_4;
    // 0x8042BE64: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_4:
    // 0x8042BE68: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x8042BE6C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8042BE70: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8042BE74:
    // 0x8042BE74: nop

    // 0x8042BE78: bc1fl       L_8042BEA0
    if (!c1cs) {
        // 0x8042BE7C: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_8042BEA0;
    }
    goto skip_5;
    // 0x8042BE7C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    skip_5:
    // 0x8042BE80: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8042BE84: lwc1        $f8, 0x84($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X84);
    // 0x8042BE88: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8042BE8C: nop

    // 0x8042BE90: bc1fl       L_8042BEA0
    if (!c1cs) {
        // 0x8042BE94: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_8042BEA0;
    }
    goto skip_6;
    // 0x8042BE94: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    skip_6:
    // 0x8042BE98: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
L_8042BE9C:
    // 0x8042BE9C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
L_8042BEA0:
    // 0x8042BEA0: lwc1        $f6, 0x88($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X88);
    // 0x8042BEA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8042BEA8: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8042BEAC: lwc1        $f18, 0x4($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8042BEB0: sub.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8042BEB4: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X3030) << 16);
    // 0x8042BEB8: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8042BEBC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8042BEC0: nop

    // 0x8042BEC4: bc1fl       L_8042BED4
    if (!c1cs) {
        // 0x8042BEC8: lwc1        $f4, 0x88($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
            goto L_8042BED4;
    }
    goto skip_7;
    // 0x8042BEC8: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    skip_7:
    // 0x8042BECC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8042BED0: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
L_8042BED4:
    // 0x8042BED4: lwc1        $f2, -0x2730($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X3030));
    // 0x8042BED8: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X3034) << 16);
    // 0x8042BEDC: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8042BEE0: lwc1        $f6, -0x272C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X3034));
    // 0x8042BEE4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8042BEE8: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8042BEEC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8042BEF0: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x8042BEF4: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8042BEF8: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8042BEFC: b           L_8042BF2C
    // 0x8042BF00: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
        goto L_8042BF2C;
    // 0x8042BF00: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_8042BF04:
    // 0x8042BF04: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X3038) << 16);
    // 0x8042BF08: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8042BF0C: lwc1        $f2, -0x2728($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X3038));
    // 0x8042BF10: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8042BF14: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8042BF18: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8042BF1C: nop

    // 0x8042BF20: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8042BF24: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8042BF28: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
L_8042BF2C:
    // 0x8042BF2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042BF30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8042BF34: jr          $ra
    // 0x8042BF38: nop

    return;
    // 0x8042BF38: nop

;}
RECOMP_FUNC void func_8001DEC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DEC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001DEC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DEC8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001DECC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001DED0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001DED4: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001DED8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8001DEDC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8001DEE0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8001DEE4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8001DEE8: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001DEEC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001DEF0: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8001DEF4: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8001DEF8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8001DEFC: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8001DF00: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8001DF04: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x8001DF08: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8001DF0C: lw          $t9, 0x28($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X28);
    // 0x8001DF10: jalr        $t9
    // 0x8001DF14: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8001DF14: nop

    after_0:
    // 0x8001DF18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001DF1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001DF20: jr          $ra
    // 0x8001DF24: nop

    return;
    // 0x8001DF24: nop

;}
RECOMP_FUNC void func_804739FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804739FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80473A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80473A04: jal         0x804736C0
    // 0x80473A08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804736C0(rdram, ctx);
        goto after_0;
    // 0x80473A08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80473A0C: jal         0x80473904
    // 0x80473A10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80473904(rdram, ctx);
        goto after_1;
    // 0x80473A10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80473A14: beq         $v0, $zero, L_80473A68
    if (ctx->r2 == 0) {
        // 0x80473A18: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80473A68;
    }
    // 0x80473A18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80473A1C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80473A20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80473A24: beql        $t6, $at, L_80473A50
    if (ctx->r14 == ctx->r1) {
        // 0x80473A28: lw          $t9, 0x1F4($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X1F4);
            goto L_80473A50;
    }
    goto skip_0;
    // 0x80473A28: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    skip_0:
    // 0x80473A2C: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x80473A30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80473A34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80473A38: xori        $a3, $t7, 0x1
    ctx->r7 = ctx->r15 ^ 0X1;
    // 0x80473A3C: jal         0x80473DF8
    // 0x80473A40: sw          $a3, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r7;
    func_80473DF8(rdram, ctx);
        goto after_2;
    // 0x80473A40: sw          $a3, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r7;
    after_2:
    // 0x80473A44: b           L_80473A6C
    // 0x80473A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80473A6C;
    // 0x80473A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80473A4C: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
L_80473A50:
    // 0x80473A50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80473A54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80473A58: sh          $zero, 0x2($t9)
    MEM_H(0X2, ctx->r25) = 0;
    // 0x80473A5C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80473A60: jal         0x80473DF8
    // 0x80473A64: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_80473DF8(rdram, ctx);
        goto after_3;
    // 0x80473A64: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_3:
L_80473A68:
    // 0x80473A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80473A6C:
    // 0x80473A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80473A70: jr          $ra
    // 0x80473A74: nop

    return;
    // 0x80473A74: nop

;}
RECOMP_FUNC void func_806F2D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2D6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F2D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2D74: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x806F2D78: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(679, 0X1BA4) << 16);
    // 0x806F2D7C: addiu       $t8, $t8, 0x3124
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(679, 0X1BA4));
    // 0x806F2D80: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806F2D84: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x806F2D88: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806F2D8C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x806F2D90: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x806F2D94: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x806F2D98: beql        $v1, $zero, L_806F2DD0
    if (ctx->r3 == 0) {
        // 0x806F2D9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F2DD0;
    }
    goto skip_0;
    // 0x806F2D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806F2DA0: jalr        $v1
    // 0x806F2DA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x806F2DA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F2DA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F2DAC: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x806F2DB0: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x806F2DB4: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x806F2DB8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x806F2DBC: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x806F2DC0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x806F2DC4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x806F2DC8: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x806F2DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F2DD0:
    // 0x806F2DD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F2DD4: jr          $ra
    // 0x806F2DD8: nop

    return;
    // 0x806F2DD8: nop

;}
RECOMP_FUNC void func_800239FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800239FC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80023A00: lh          $t6, -0x7682($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X7682);
    // 0x80023A04: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80023A08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80023A0C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80023A10: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80023A14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023A18: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80023A1C: div.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80023A20: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80023A24: jr          $ra
    // 0x80023A28: swc1        $f16, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x80023A28: swc1        $f16, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_807424D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807424D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807424DC: lui         $at, 0x8076
    ctx->r1 = S32(RELOC_HI16(754, 0X1C378) << 16);
    // 0x807424E0: lwc1        $f0, -0x1A48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(754, 0X1C378));
    // 0x807424E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807424E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807424EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x807424F0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x807424F4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x807424F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x807424FC: addiu       $t6, $zero, 0xAC8
    ctx->r14 = ADD32(0, 0XAC8);
    // 0x80742500: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80742504: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80742508: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x8074250C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80742510: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80742514: jal         0x8074224C
    // 0x80742518: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8074224C(rdram, ctx);
        goto after_0;
    // 0x80742518: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8074251C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80742520: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80742524: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80742528: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8074252C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80742530: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80742534: jr          $ra
    // 0x80742538: nop

    return;
    // 0x80742538: nop

;}
RECOMP_FUNC void func_8069F188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069F188: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8069F18C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8069F190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069F194: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8069F198: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x8069F19C: jal         0x80048F84
    // 0x8069F1A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8069F1A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8069F1A4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8069F1A8: jal         0x80048F84
    // 0x8069F1AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8069F1AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8069F1B0: jal         0x8069EFC0
    // 0x8069F1B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8069EFC0(rdram, ctx);
        goto after_2;
    // 0x8069F1B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8069F1B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069F1BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8069F1C0: jr          $ra
    // 0x8069F1C4: nop

    return;
    // 0x8069F1C4: nop

;}
RECOMP_FUNC void func_806DFD80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DFD80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806DFD84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806DFD88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806DFD8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806DFD90: jal         0x80062748
    // 0x806DFD94: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80062748(rdram, ctx);
        goto after_0;
    // 0x806DFD94: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_0:
    // 0x806DFD98: jal         0x806DF6E0
    // 0x806DFD9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DF6E0(rdram, ctx);
        goto after_1;
    // 0x806DFD9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806DFDA0: jal         0x806DFBD4
    // 0x806DFDA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DFBD4(rdram, ctx);
        goto after_2;
    // 0x806DFDA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806DFDA8: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X11B4) << 16);
    // 0x806DFDAC: lwc1        $f6, 0x5E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X11B4));
    // 0x806DFDB0: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x806DFDB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806DFDB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806DFDBC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806DFDC0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806DFDC4: bc1f        L_806DFDE4
    if (!c1cs) {
        // 0x806DFDC8: nop
    
            goto L_806DFDE4;
    }
    // 0x806DFDC8: nop

    // 0x806DFDCC: jal         0x806E0398
    // 0x806DFDD0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806E0398(rdram, ctx);
        goto after_3;
    // 0x806DFDD0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_3:
    // 0x806DFDD4: jal         0x806DF4BC
    // 0x806DFDD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DF4BC(rdram, ctx);
        goto after_4;
    // 0x806DFDD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806DFDDC: b           L_806DFDF0
    // 0x806DFDE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806DFDF0;
    // 0x806DFDE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806DFDE4:
    // 0x806DFDE4: jal         0x806DF504
    // 0x806DFDE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DF504(rdram, ctx);
        goto after_5;
    // 0x806DFDE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806DFDEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806DFDF0:
    // 0x806DFDF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806DFDF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806DFDF8: jr          $ra
    // 0x806DFDFC: nop

    return;
    // 0x806DFDFC: nop

;}
RECOMP_FUNC void func_8078EB10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078EB10: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8078EB14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078EB18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078EB1C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078EB20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8078EB24: lhu         $a0, 0x8($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X8);
    // 0x8078EB28: jal         0x80047090
    // 0x8078EB2C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8078EB2C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8078EB30: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8078EB34: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8078EB38: bne         $v0, $at, L_8078EB48
    if (ctx->r2 != ctx->r1) {
        // 0x8078EB3C: andi        $t0, $v0, 0xFFFF
        ctx->r8 = ctx->r2 & 0XFFFF;
            goto L_8078EB48;
    }
    // 0x8078EB3C: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x8078EB40: b           L_8078EBD4
    // 0x8078EB44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8078EBD4;
    // 0x8078EB44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8078EB48:
    // 0x8078EB48: lhu         $t6, 0x8($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X8);
    // 0x8078EB4C: lw          $a1, 0x84($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X84);
    // 0x8078EB50: lw          $a2, 0x88($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X88);
    // 0x8078EB54: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8078EB58: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x8078EB5C: lw          $a3, 0x8C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8C);
    // 0x8078EB60: sh          $t0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r8;
    // 0x8078EB64: jal         0x8004613C
    // 0x8078EB68: or          $a0, $t8, $t0
    ctx->r4 = ctx->r24 | ctx->r8;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8078EB68: or          $a0, $t8, $t0
    ctx->r4 = ctx->r24 | ctx->r8;
    after_1:
    // 0x8078EB6C: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    // 0x8078EB70: bne         $v0, $zero, L_8078EB80
    if (ctx->r2 != 0) {
        // 0x8078EB74: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8078EB80;
    }
    // 0x8078EB74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8078EB78: b           L_8078EBD4
    // 0x8078EB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8078EBD4;
    // 0x8078EB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8078EB80:
    // 0x8078EB80: lhu         $t2, 0xE($a1)
    ctx->r10 = MEM_HU(ctx->r5, 0XE);
    // 0x8078EB84: andi        $t1, $t0, 0x3FF
    ctx->r9 = ctx->r8 & 0X3FF;
    // 0x8078EB88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078EB8C: andi        $t3, $t2, 0xFC00
    ctx->r11 = ctx->r10 & 0XFC00;
    // 0x8078EB90: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x8078EB94: sh          $t4, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r12;
    // 0x8078EB98: jal         0x80047F9C
    // 0x8078EB9C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8078EB9C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_2:
    // 0x8078EBA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8078EBA4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8078EBA8: jal         0x8005FE48
    // 0x8078EBAC: sb          $s0, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r16;
    func_8005FE48(rdram, ctx);
        goto after_3;
    // 0x8078EBAC: sb          $s0, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r16;
    after_3:
    // 0x8078EBB0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8078EBB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8078EBB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8078EBBC: lw          $t5, 0x174($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X174);
    // 0x8078EBC0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8078EBC4: sh          $zero, 0x12($t6)
    MEM_H(0X12, ctx->r14) = 0;
    // 0x8078EBC8: sb          $s0, 0x165($a1)
    MEM_B(0X165, ctx->r5) = ctx->r16;
    // 0x8078EBCC: swc1        $f0, 0xC4($a1)
    MEM_W(0XC4, ctx->r5) = ctx->f0.u32l;
    // 0x8078EBD0: swc1        $f0, 0xC8($a1)
    MEM_W(0XC8, ctx->r5) = ctx->f0.u32l;
L_8078EBD4:
    // 0x8078EBD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078EBD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078EBDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8078EBE0: jr          $ra
    // 0x8078EBE4: nop

    return;
    // 0x8078EBE4: nop

;}
RECOMP_FUNC void func_805A3690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A3690: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A3694: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x805A3698: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805A369C: lwc1        $f4, 0x8C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x805A36A0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x805A36A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805A36A8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x805A36AC: lwc1        $f10, 0x6C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x805A36B0: lw          $a2, 0x40($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X40);
    // 0x805A36B4: lw          $a3, 0x44($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X44);
    // 0x805A36B8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x805A36BC: lw          $t0, 0x48($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X48);
    // 0x805A36C0: lw          $t1, 0x4C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4C);
    // 0x805A36C4: addiu       $t3, $zero, -0xA
    ctx->r11 = ADD32(0, -0XA);
    // 0x805A36C8: sh          $t3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r11;
    // 0x805A36CC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x805A36D0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x805A36D4: lwc1        $f6, 0x90($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X90);
    // 0x805A36D8: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x805A36DC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x805A36E0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x805A36E4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x805A36E8: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x805A36EC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x805A36F0: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x805A36F4: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
    // 0x805A36F8: subu        $t8, $v1, $a1
    ctx->r24 = SUB32(ctx->r3, ctx->r5);
    // 0x805A36FC: addu        $t9, $a1, $v1
    ctx->r25 = ADD32(ctx->r5, ctx->r3);
    // 0x805A3700: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x805A3704: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x805A3708: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    // 0x805A370C: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
    // 0x805A3710: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x805A3714: sh          $zero, 0x16($v0)
    MEM_H(0X16, ctx->r2) = 0;
    // 0x805A3718: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
    // 0x805A371C: subu        $t5, $t2, $a1
    ctx->r13 = SUB32(ctx->r10, ctx->r5);
    // 0x805A3720: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x805A3724: sh          $zero, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = 0;
    // 0x805A3728: sh          $t6, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r14;
    // 0x805A372C: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x805A3730: sb          $a2, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r6;
    // 0x805A3734: sb          $a2, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r6;
    // 0x805A3738: sb          $a3, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r7;
    // 0x805A373C: sb          $a3, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r7;
    // 0x805A3740: sb          $t0, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r8;
    // 0x805A3744: sb          $t0, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r8;
    // 0x805A3748: sb          $t1, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r9;
    // 0x805A374C: sb          $t1, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = ctx->r9;
    // 0x805A3750: addiu       $t7, $zero, -0x7D0
    ctx->r15 = ADD32(0, -0X7D0);
    // 0x805A3754: sh          $t7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r15;
    // 0x805A3758: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // 0x805A375C: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    // 0x805A3760: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x805A3764: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x805A3768: lw          $t8, 0x50($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X50);
    // 0x805A376C: addu        $t6, $t2, $a1
    ctx->r14 = ADD32(ctx->r10, ctx->r5);
    // 0x805A3770: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x805A3774: sb          $t8, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r24;
    // 0x805A3778: lw          $t9, 0x54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X54);
    // 0x805A377C: addiu       $t8, $zero, -0x898
    ctx->r24 = ADD32(0, -0X898);
    // 0x805A3780: sb          $t9, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r25;
    // 0x805A3784: lw          $t4, 0x58($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X58);
    // 0x805A3788: sb          $t4, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r12;
    // 0x805A378C: lw          $t5, 0x5C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X5C);
    // 0x805A3790: sb          $t5, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r13;
    // 0x805A3794: lw          $t6, 0x5C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X5C);
    // 0x805A3798: lw          $t5, 0x58($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X58);
    // 0x805A379C: lw          $t4, 0x54($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X54);
    // 0x805A37A0: lw          $t9, 0x50($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X50);
    // 0x805A37A4: sh          $zero, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = 0;
    // 0x805A37A8: sh          $zero, 0x38($v0)
    MEM_H(0X38, ctx->r2) = 0;
    // 0x805A37AC: sh          $zero, 0x36($v0)
    MEM_H(0X36, ctx->r2) = 0;
    // 0x805A37B0: sh          $zero, 0x34($v0)
    MEM_H(0X34, ctx->r2) = 0;
    // 0x805A37B4: sh          $t8, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r24;
    // 0x805A37B8: sh          $t7, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r15;
    // 0x805A37BC: sb          $t6, 0x3F($v0)
    MEM_B(0X3F, ctx->r2) = ctx->r14;
    // 0x805A37C0: sb          $t5, 0x3E($v0)
    MEM_B(0X3E, ctx->r2) = ctx->r13;
    // 0x805A37C4: sb          $t4, 0x3D($v0)
    MEM_B(0X3D, ctx->r2) = ctx->r12;
    // 0x805A37C8: jr          $ra
    // 0x805A37CC: sb          $t9, 0x3C($v0)
    MEM_B(0X3C, ctx->r2) = ctx->r25;
    return;
    // 0x805A37CC: sb          $t9, 0x3C($v0)
    MEM_B(0X3C, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_800554AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800554AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800554B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800554B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800554B8: addiu       $a1, $zero, 0x44E4
    ctx->r5 = ADD32(0, 0X44E4);
    // 0x800554BC: jal         0x80055370
    // 0x800554C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80055370(rdram, ctx);
        goto after_0;
    // 0x800554C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800554C4: lh          $v1, 0x1E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X1E);
    // 0x800554C8: beq         $v0, $zero, L_800554DC
    if (ctx->r2 == 0) {
        // 0x800554CC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800554DC;
    }
    // 0x800554CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800554D0: sw          $a0, 0x1F4($v0)
    MEM_W(0X1F4, ctx->r2) = ctx->r4;
    // 0x800554D4: b           L_800554E4
    // 0x800554D8: sw          $v1, 0x1E0($v0)
    MEM_W(0X1E0, ctx->r2) = ctx->r3;
        goto L_800554E4;
    // 0x800554D8: sw          $v1, 0x1E0($v0)
    MEM_W(0X1E0, ctx->r2) = ctx->r3;
L_800554DC:
    // 0x800554DC: sh          $v1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r3;
    // 0x800554E0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
L_800554E4:
    // 0x800554E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800554E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800554EC: jr          $ra
    // 0x800554F0: nop

    return;
    // 0x800554F0: nop

;}
RECOMP_FUNC void func_80006E0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006E0C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80006E10: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x80006E14: lw          $t6, 0x1E9C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1E9C);
    // 0x80006E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006E20: beq         $t6, $zero, L_80006E30
    if (ctx->r14 == 0) {
        // 0x80006E24: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_80006E30;
    }
    // 0x80006E24: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80006E28: b           L_80006E4C
    // 0x80006E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80006E4C;
    // 0x80006E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80006E30:
    // 0x80006E30: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80006E34: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80006E38: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80006E3C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80006E40: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80006E44: jal         0x80006EB4
    // 0x80006E48: sw          $zero, 0x2B08($t8)
    MEM_W(0X2B08, ctx->r24) = 0;
    func_80006EB4(rdram, ctx);
        goto after_0;
    // 0x80006E48: sw          $zero, 0x2B08($t8)
    MEM_W(0X2B08, ctx->r24) = 0;
    after_0:
L_80006E4C:
    // 0x80006E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006E50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006E54: jr          $ra
    // 0x80006E58: nop

    return;
    // 0x80006E58: nop

;}
RECOMP_FUNC void func_804BEF4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BEF4C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x804BEF50: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x804BEF54: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x804BEF58: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x804BEF5C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x804BEF60: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x804BEF64: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804BEF68: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4218) << 16);
    // 0x804BEF6C: lwc1        $f0, -0x4B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4218));
    // 0x804BEF70: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804BEF74: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BEF78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804BEF7C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x804BEF80: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x804BEF84: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x804BEF88: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
    // 0x804BEF8C: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x804BEF90: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x804BEF94: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804BEF98: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x804BEF9C: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
L_804BEFA0:
    // 0x804BEFA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x804BEFA4: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x804BEFA8: beql        $a0, $zero, L_804BEFDC
    if (ctx->r4 == 0) {
        // 0x804BEFAC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_804BEFDC;
    }
    goto skip_0;
    // 0x804BEFAC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x804BEFB0: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x804BEFB4: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x804BEFB8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x804BEFBC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804BEFC0: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x804BEFC4: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x804BEFC8: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x804BEFCC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804BEFD0: jal         0x804BEF30
    // 0x804BEFD4: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    func_804BEF30(rdram, ctx);
        goto after_0;
    // 0x804BEFD4: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x804BEFD8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_804BEFDC:
    // 0x804BEFDC: bne         $s1, $s3, L_804BEFA0
    if (ctx->r17 != ctx->r19) {
        // 0x804BEFE0: addiu       $s0, $s0, 0x4C
        ctx->r16 = ADD32(ctx->r16, 0X4C);
            goto L_804BEFA0;
    }
    // 0x804BEFE0: addiu       $s0, $s0, 0x4C
    ctx->r16 = ADD32(ctx->r16, 0X4C);
    // 0x804BEFE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x804BEFE8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804BEFEC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x804BEFF0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x804BEFF4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x804BEFF8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x804BEFFC: jr          $ra
    // 0x804BF000: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x804BF000: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8043B304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B304: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8043B308: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(83, 0X248) << 16);
    // 0x8043B30C: addiu       $t6, $t6, -0x5758
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(83, 0X248));
    // 0x8043B310: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8043B314: jr          $ra
    // 0x8043B318: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8043B318: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80452720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452728: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8045272C: jal         0x804525A8
    // 0x80452730: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_804525A8(rdram, ctx);
        goto after_0;
    // 0x80452730: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_0:
    // 0x80452734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80452738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045273C: jr          $ra
    // 0x80452740: nop

    return;
    // 0x80452740: nop

;}
RECOMP_FUNC void func_80736708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736708: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073670C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736710: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80736714: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80736718: lui         $at, 0xC190
    ctx->r1 = S32(0XC190 << 16);
    // 0x8073671C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80736720: lwc1        $f4, 0x50($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X50);
    // 0x80736724: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80736728: jal         0x80066DE4
    // 0x8073672C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8073672C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_0:
    // 0x80736730: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80736734: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80736738: lui         $at, 0xC190
    ctx->r1 = S32(0XC190 << 16);
    // 0x8073673C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80736740: lwc1        $f8, 0x50($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X50);
    // 0x80736744: jal         0x80066E88
    // 0x80736748: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80736748: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x8073674C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B3C) << 16);
    // 0x80736750: lwc1        $f2, -0x6A64($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B3C));
    // 0x80736754: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80736758: mul.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8073675C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80736760: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80736764: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80736768: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8073676C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80736770: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80736774: jr          $ra
    // 0x80736778: nop

    return;
    // 0x80736778: nop

;}
RECOMP_FUNC void func_80664DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80664DB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80664DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80664DB8: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80664DBC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80664DC0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80664DC4: beq         $a1, $at, L_80664DE0
    if (ctx->r5 == ctx->r1) {
        // 0x80664DC8: addiu       $a0, $zero, 0x66
        ctx->r4 = ADD32(0, 0X66);
            goto L_80664DE0;
    }
    // 0x80664DC8: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    // 0x80664DCC: jal         0x80067878
    // 0x80664DD0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x80664DD0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80664DD4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80664DD8: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80664DDC: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_80664DE0:
    // 0x80664DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80664DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80664DE8: jr          $ra
    // 0x80664DEC: nop

    return;
    // 0x80664DEC: nop

;}
RECOMP_FUNC void func_8003DAB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DAB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003DABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DAC0: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x8003DAC4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8003DAC8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8003DACC: beql        $v0, $zero, L_8003DAE4
    if (ctx->r2 == 0) {
        // 0x8003DAD0: lwc1        $f2, 0x78($a3)
        ctx->f2.u32l = MEM_W(ctx->r7, 0X78);
            goto L_8003DAE4;
    }
    goto skip_0;
    // 0x8003DAD0: lwc1        $f2, 0x78($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X78);
    skip_0:
    // 0x8003DAD4: jalr        $v0
    // 0x8003DAD8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8003DAD8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x8003DADC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8003DAE0: lwc1        $f2, 0x78($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X78);
L_8003DAE4:
    // 0x8003DAE4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8003DAE8: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8003DAEC: add.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8003DAF0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8003DAF4: addiu       $a0, $a3, 0x84
    ctx->r4 = ADD32(ctx->r7, 0X84);
    // 0x8003DAF8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8003DAFC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8003DB00: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8003DB04: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8003DB08: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8003DB0C: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8003DB10: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x8003DB14: jalr        $t9
    // 0x8003DB18: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8003DB18: nop

    after_1:
    // 0x8003DB1C: jal         0x800447C8
    // 0x8003DB20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x8003DB20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8003DB24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DB28: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003DB2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003DB30: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x8003DB34: jr          $ra
    // 0x8003DB38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8003DB38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_804601FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804601FC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80460200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460204: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80460208: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8046020C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80460210: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80460214: jal         0x80460100
    // 0x80460218: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    func_80460100(rdram, ctx);
        goto after_0;
    // 0x80460218: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    after_0:
    // 0x8046021C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80460220: lui         $t0, 0x400
    ctx->r8 = S32(0X400 << 16);
    // 0x80460224: lui         $t1, 0x8046
    ctx->r9 = S32(RELOC_HI16(119, 0X3C0) << 16);
    // 0x80460228: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8046022C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80460230: addiu       $t1, $t1, 0x4B0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(119, 0X3C0));
    // 0x80460234: ori         $t0, $t0, 0x185F
    ctx->r8 = ctx->r8 | 0X185F;
    // 0x80460238: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8046023C: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x80460240: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80460244: lui         $v0, 0xBF00
    ctx->r2 = S32(0XBF00 << 16);
    // 0x80460248: addiu       $t4, $zero, 0x204
    ctx->r12 = ADD32(0, 0X204);
    // 0x8046024C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80460250: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80460254: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80460258: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x8046025C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80460260: addiu       $t7, $zero, 0x406
    ctx->r15 = ADD32(0, 0X406);
    // 0x80460264: addiu       $t0, $zero, 0x608
    ctx->r8 = ADD32(0, 0X608);
    // 0x80460268: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8046026C: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80460270: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80460274: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x80460278: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8046027C: addiu       $t3, $zero, 0x802
    ctx->r11 = ADD32(0, 0X802);
    // 0x80460280: lui         $t6, 0xA
    ctx->r14 = S32(0XA << 16);
    // 0x80460284: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80460288: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8046028C: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x80460290: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x80460294: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80460298: ori         $t6, $t6, 0x204
    ctx->r14 = ctx->r14 | 0X204;
    // 0x8046029C: lui         $t9, 0xA
    ctx->r25 = S32(0XA << 16);
    // 0x804602A0: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x804602A4: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x804602A8: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x804602AC: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x804602B0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x804602B4: ori         $t9, $t9, 0x406
    ctx->r25 = ctx->r25 | 0X406;
    // 0x804602B8: lui         $t2, 0xA
    ctx->r10 = S32(0XA << 16);
    // 0x804602BC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x804602C0: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x804602C4: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x804602C8: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x804602CC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x804602D0: ori         $t2, $t2, 0x608
    ctx->r10 = ctx->r10 | 0X608;
    // 0x804602D4: lui         $t5, 0xA
    ctx->r13 = S32(0XA << 16);
    // 0x804602D8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x804602DC: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x804602E0: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x804602E4: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x804602E8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x804602EC: ori         $t5, $t5, 0x802
    ctx->r13 = ctx->r13 | 0X802;
    // 0x804602F0: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x804602F4: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x804602F8: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x804602FC: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80460300: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80460304: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80460308: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8046030C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x80460310: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80460314: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x80460318: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8046031C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80460320: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80460324: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80460328: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8046032C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80460330: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80460334: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80460338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046033C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80460340: jr          $ra
    // 0x80460344: nop

    return;
    // 0x80460344: nop

;}
RECOMP_FUNC void func_807BC7C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC7C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807BC7C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BC7CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807BC7D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x807BC7D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x807BC7D8: jal         0x80047090
    // 0x807BC7DC: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807BC7DC: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x807BC7E0: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x807BC7E4: beq         $v0, $at, L_807BC838
    if (ctx->r2 == ctx->r1) {
        // 0x807BC7E8: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_807BC838;
    }
    // 0x807BC7E8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x807BC7EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807BC7F0: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x807BC7F4: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x807BC7F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x807BC7FC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x807BC800: ori         $t8, $t7, 0x2400
    ctx->r24 = ctx->r15 | 0X2400;
    // 0x807BC804: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x807BC808: or          $a0, $t8, $v1
    ctx->r4 = ctx->r24 | ctx->r3;
    // 0x807BC80C: jal         0x8004613C
    // 0x807BC810: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807BC810: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    after_1:
    // 0x807BC814: beq         $v0, $zero, L_807BC838
    if (ctx->r2 == 0) {
        // 0x807BC818: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_807BC838;
    }
    // 0x807BC818: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807BC81C: lh          $t9, 0x2A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A);
    // 0x807BC820: sh          $t9, 0x144($v0)
    MEM_H(0X144, ctx->r2) = ctx->r25;
    // 0x807BC824: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x807BC828: jal         0x80047F9C
    // 0x807BC82C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807BC82C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x807BC830: b           L_807BC83C
    // 0x807BC834: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_807BC83C;
    // 0x807BC834: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_807BC838:
    // 0x807BC838: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807BC83C:
    // 0x807BC83C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BC840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807BC844: jr          $ra
    // 0x807BC848: nop

    return;
    // 0x807BC848: nop

    // 0x807BC84C: nop

;}
RECOMP_FUNC void func_8076078C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076078C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80760790: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80760794: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80760798: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8076079C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x807607A0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x807607A4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x807607A8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x807607AC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x807607B0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x807607B4: jr          $ra
    // 0x807607B8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x807607B8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80071B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071B0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80071B10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80071B14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80071B18: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071B1C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80071B20: addiu       $a1, $a1, 0x1B78
    ctx->r5 = ADD32(ctx->r5, 0X1B78);
    // 0x80071B24: jal         0x8007E3D0
    // 0x80071B28: addiu       $a0, $a0, -0x5E30
    ctx->r4 = ADD32(ctx->r4, -0X5E30);
    func_8007E3D0(rdram, ctx);
        goto after_0;
    // 0x80071B28: addiu       $a0, $a0, -0x5E30
    ctx->r4 = ADD32(ctx->r4, -0X5E30);
    after_0:
    // 0x80071B2C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071B30: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80071B34: addiu       $a1, $a1, 0x1B88
    ctx->r5 = ADD32(ctx->r5, 0X1B88);
    // 0x80071B38: jal         0x8007E3D0
    // 0x80071B3C: addiu       $a0, $a0, -0x5E08
    ctx->r4 = ADD32(ctx->r4, -0X5E08);
    func_8007E3D0(rdram, ctx);
        goto after_1;
    // 0x80071B3C: addiu       $a0, $a0, -0x5E08
    ctx->r4 = ADD32(ctx->r4, -0X5E08);
    after_1:
    // 0x80071B40: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071B44: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80071B48: addiu       $a1, $a1, 0x1B98
    ctx->r5 = ADD32(ctx->r5, 0X1B98);
    // 0x80071B4C: jal         0x8007E3D0
    // 0x80071B50: addiu       $a0, $a0, -0x5E50
    ctx->r4 = ADD32(ctx->r4, -0X5E50);
    func_8007E3D0(rdram, ctx);
        goto after_2;
    // 0x80071B50: addiu       $a0, $a0, -0x5E50
    ctx->r4 = ADD32(ctx->r4, -0X5E50);
    after_2:
    // 0x80071B54: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071B58: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80071B5C: addiu       $a1, $a1, 0x1BB0
    ctx->r5 = ADD32(ctx->r5, 0X1BB0);
    // 0x80071B60: jal         0x8007E3D0
    // 0x80071B64: addiu       $a0, $a0, -0x6320
    ctx->r4 = ADD32(ctx->r4, -0X6320);
    func_8007E3D0(rdram, ctx);
        goto after_3;
    // 0x80071B64: addiu       $a0, $a0, -0x6320
    ctx->r4 = ADD32(ctx->r4, -0X6320);
    after_3:
    // 0x80071B68: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071B6C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80071B70: addiu       $a1, $a1, -0x5E18
    ctx->r5 = ADD32(ctx->r5, -0X5E18);
    // 0x80071B74: addiu       $a0, $a0, -0x5E30
    ctx->r4 = ADD32(ctx->r4, -0X5E30);
    // 0x80071B78: jal         0x8008AE20
    // 0x80071B7C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x80071B7C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x80071B80: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071B84: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80071B88: addiu       $a1, $a1, -0x5DF0
    ctx->r5 = ADD32(ctx->r5, -0X5DF0);
    // 0x80071B8C: addiu       $a0, $a0, -0x5E08
    ctx->r4 = ADD32(ctx->r4, -0X5E08);
    // 0x80071B90: jal         0x8008AE20
    // 0x80071B94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_5;
    // 0x80071B94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80071B98: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071B9C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80071BA0: addiu       $a1, $a1, -0x5E38
    ctx->r5 = ADD32(ctx->r5, -0X5E38);
    // 0x80071BA4: addiu       $a0, $a0, -0x5E50
    ctx->r4 = ADD32(ctx->r4, -0X5E50);
    // 0x80071BA8: jal         0x8008AE20
    // 0x80071BAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_6;
    // 0x80071BAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80071BB0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80071BB4: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80071BB8: addiu       $a2, $a2, -0x5E50
    ctx->r6 = ADD32(ctx->r6, -0X5E50);
    // 0x80071BBC: addiu       $a1, $a1, -0x5DE8
    ctx->r5 = ADD32(ctx->r5, -0X5DE8);
    // 0x80071BC0: jal         0x80075120
    // 0x80071BC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80075120(rdram, ctx);
        goto after_7;
    // 0x80071BC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x80071BC8: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80071BCC: addiu       $t7, $t7, 0x1BC0
    ctx->r15 = ADD32(ctx->r15, 0X1BC0);
    // 0x80071BD0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071BD4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80071BD8: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80071BDC: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x80071BE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80071BE4: addiu       $a2, $a2, -0x5E70
    ctx->r6 = ADD32(ctx->r6, -0X5E70);
    // 0x80071BE8: addiu       $a1, $a1, -0x6170
    ctx->r5 = ADD32(ctx->r5, -0X6170);
    // 0x80071BEC: addiu       $a0, $a0, -0x5E70
    ctx->r4 = ADD32(ctx->r4, -0X5E70);
    // 0x80071BF0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80071BF4: jal         0x80081910
    // 0x80071BF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_8;
    // 0x80071BF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x80071BFC: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80071C00: addiu       $t8, $t8, -0x5E70
    ctx->r24 = ADD32(ctx->r24, -0X5E70);
    // 0x80071C04: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071C08: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80071C0C: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80071C10: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80071C14: addiu       $a2, $a2, 0x1974
    ctx->r6 = ADD32(ctx->r6, 0X1974);
    // 0x80071C18: addiu       $a0, $a0, -0x6320
    ctx->r4 = ADD32(ctx->r4, -0X6320);
    // 0x80071C1C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80071C20: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80071C24: jal         0x80085B10
    // 0x80071C28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_9;
    // 0x80071C28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80071C2C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071C30: jal         0x80090CC0
    // 0x80071C34: addiu       $a0, $a0, -0x6320
    ctx->r4 = ADD32(ctx->r4, -0X6320);
    osStartThread_recomp(rdram, ctx);
        goto after_10;
    // 0x80071C34: addiu       $a0, $a0, -0x6320
    ctx->r4 = ADD32(ctx->r4, -0X6320);
    after_10:
    // 0x80071C38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80071C3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80071C40: jr          $ra
    // 0x80071C44: nop

    return;
    // 0x80071C44: nop

    // 0x80071C48: nop

    // 0x80071C4C: nop

    // 0x80071C50: nop

    // 0x80071C54: nop

    // 0x80071C58: nop

    // 0x80071C5C: nop

;}
RECOMP_FUNC void func_8003AE4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AE4C: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x8003AE50: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x8003AE54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003AE58: lw          $t6, 0xF10($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XF10);
    // 0x8003AE5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AE60: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8003AE64: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8003AE68: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8003AE6C: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x8003AE70: lw          $a3, 0xF14($t8)
    ctx->r7 = MEM_W(ctx->r24, 0XF14);
    // 0x8003AE74: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x8003AE78: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8003AE7C: jal         0x8003AE00
    // 0x8003AE80: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8003AE00(rdram, ctx);
        goto after_0;
    // 0x8003AE80: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8003AE84: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8003AE88: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8003AE8C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8003AE90: lw          $a0, 0x1F4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X1F4);
    // 0x8003AE94: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8003AE98: beq         $v1, $zero, L_8003AEB4
    if (ctx->r3 == 0) {
        // 0x8003AE9C: sb          $t0, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r8;
            goto L_8003AEB4;
    }
    // 0x8003AE9C: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    // 0x8003AEA0: lwc1        $f4, 0x84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8003AEA4: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x8003AEA8: lwc1        $f6, 0x88($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X88);
    // 0x8003AEAC: b           L_8003AEC4
    // 0x8003AEB0: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
        goto L_8003AEC4;
    // 0x8003AEB0: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
L_8003AEB4:
    // 0x8003AEB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003AEB8: nop

    // 0x8003AEBC: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x8003AEC0: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
L_8003AEC4:
    // 0x8003AEC4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8003AEC8: lw          $v0, -0x7250($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7250);
    // 0x8003AECC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8003AED0: beq         $v0, $at, L_8003AEDC
    if (ctx->r2 == ctx->r1) {
        // 0x8003AED4: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8003AEDC;
    }
    // 0x8003AED4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8003AED8: bne         $v0, $at, L_8003AEF8
    if (ctx->r2 != ctx->r1) {
        // 0x8003AEDC: slti        $at, $a3, 0x8
        ctx->r1 = SIGNED(ctx->r7) < 0X8 ? 1 : 0;
            goto L_8003AEF8;
    }
L_8003AEDC:
    // 0x8003AEDC: slti        $at, $a3, 0x8
    ctx->r1 = SIGNED(ctx->r7) < 0X8 ? 1 : 0;
    // 0x8003AEE0: bne         $at, $zero, L_8003AEF0
    if (ctx->r1 != 0) {
        // 0x8003AEE4: nop
    
            goto L_8003AEF0;
    }
    // 0x8003AEE4: nop

    // 0x8003AEE8: b           L_8003AF0C
    // 0x8003AEEC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8003AF0C;
    // 0x8003AEEC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8003AEF0:
    // 0x8003AEF0: b           L_8003AF0C
    // 0x8003AEF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003AF0C;
    // 0x8003AEF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003AEF8:
    // 0x8003AEF8: slti        $at, $a3, 0x8
    ctx->r1 = SIGNED(ctx->r7) < 0X8 ? 1 : 0;
    // 0x8003AEFC: bne         $at, $zero, L_8003AF0C
    if (ctx->r1 != 0) {
        // 0x8003AF00: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003AF0C;
    }
    // 0x8003AF00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003AF04: b           L_8003AF0C
    // 0x8003AF08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003AF0C;
    // 0x8003AF08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003AF0C:
    // 0x8003AF0C: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x8003AF10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AF14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003AF18: jr          $ra
    // 0x8003AF1C: nop

    return;
    // 0x8003AF1C: nop

;}
RECOMP_FUNC void func_8046687C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046687C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80466880: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80466884: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80466888: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8046688C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80466890: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80466894: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80466898: lui         $t1, 0x8046
    ctx->r9 = S32(RELOC_HI16(129, 0X2C0) << 16);
    // 0x8046689C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804668A0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804668A4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804668A8: lw          $t1, 0x68C0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(129, 0X2C0));
    // 0x804668AC: jr          $ra
    // 0x804668B0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x804668B0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x804668B4: nop

    // 0x804668B8: nop

    // 0x804668BC: nop

;}
RECOMP_FUNC void func_804C0864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C0868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C086C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804C0870: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804C0874: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(197, 0X4F0) << 16);
    // 0x804C0878: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804C087C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804C0880: addiu       $t7, $t7, 0x9B0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(197, 0X4F0));
    // 0x804C0884: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804C0888: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804C088C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C0890: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C0894: jal         0x804C08E8
    // 0x804C0898: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_804C08E8(rdram, ctx);
        goto after_0;
    // 0x804C0898: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x804C089C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C08A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804C08A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804C08A8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x804C08AC: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x804C08B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804C08B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804C08B8: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x804C08BC: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x804C08C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x804C08C4: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x804C08C8: jal         0x80045A34
    // 0x804C08CC: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x804C08CC: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    after_1:
    // 0x804C08D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C08D4: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804C08D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C08DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C08E0: jr          $ra
    // 0x804C08E4: nop

    return;
    // 0x804C08E4: nop

;}
RECOMP_FUNC void func_805AE144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE144: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE148: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE14C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE150: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE154: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE158: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE15C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE160: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE164: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE168: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE16C: jr          $ra
    // 0x805AE170: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE170: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805AE3E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE3E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE3E8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE3EC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE3F0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE3F4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE3F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE3FC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE400: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE404: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE408: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE40C: jr          $ra
    // 0x805AE410: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE410: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8005F510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F510: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8005F514: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8005F518: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8005F51C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8005F520: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8005F524: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8005F528: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8005F52C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8005F530: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8005F534: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8005F538: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8005F53C: lw          $s3, 0x0($a1)
    ctx->r19 = MEM_W(ctx->r5, 0X0);
    // 0x8005F540: addiu       $s0, $a1, 0x34
    ctx->r16 = ADD32(ctx->r5, 0X34);
    // 0x8005F544: lw          $s4, 0x198($a1)
    ctx->r20 = MEM_W(ctx->r5, 0X198);
    // 0x8005F548: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005F54C: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
L_8005F550:
    // 0x8005F550: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8005F554: addiu       $t7, $s2, 0x30
    ctx->r15 = ADD32(ctx->r18, 0X30);
    // 0x8005F558: beql        $t6, $zero, L_8005F5A0
    if (ctx->r14 == 0) {
        // 0x8005F55C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8005F5A0;
    }
    goto skip_0;
    // 0x8005F55C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8005F560: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8005F564: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005F568: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x8005F56C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005F570: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8005F574: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8005F578: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
    // 0x8005F57C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8005F580: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8005F584: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x8005F588: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8005F58C: lh          $t1, 0x8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X8);
    // 0x8005F590: jal         0x8005F2CC
    // 0x8005F594: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    func_8005F2CC(rdram, ctx);
        goto after_0;
    // 0x8005F594: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_0:
    // 0x8005F598: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8005F59C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8005F5A0:
    // 0x8005F5A0: bne         $s1, $s6, L_8005F550
    if (ctx->r17 != ctx->r22) {
        // 0x8005F5A4: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_8005F550;
    }
    // 0x8005F5A4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8005F5A8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F5AC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8005F5B0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8005F5B4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8005F5B8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8005F5BC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8005F5C0: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8005F5C4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8005F5C8: jr          $ra
    // 0x8005F5CC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8005F5CC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80080798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080798: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008079C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800807A0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800807A4: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800807A8: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800807AC: lwc1        $f18, 0x30($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800807B0: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800807B4: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800807B8: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800807BC: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800807C0: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800807C4: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800807C8: mul.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800807CC: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800807D0: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x800807D4: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800807D8: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800807DC: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800807E0: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800807E4: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800807E8: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800807EC: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800807F0: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
    // 0x800807F4: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800807F8: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800807FC: mul.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80080800: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80080804: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80080808: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8008080C: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x80080810: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80080814: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80080818: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8008081C: jr          $ra
    // 0x80080820: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x80080820: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_804BE3D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BE3D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BE3D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BE3D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804BE3DC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x804BE3E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804BE3E4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41EC) << 16);
    // 0x804BE3E8: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x804BE3EC: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x804BE3F0: lw          $v1, 0x370($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X370);
    // 0x804BE3F4: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x804BE3F8: lwc1        $f6, -0x4E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41EC));
    // 0x804BE3FC: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41F0) << 16);
    // 0x804BE400: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x804BE404: nop

    // 0x804BE408: bc1tl       L_804BE49C
    if (c1cs) {
        // 0x804BE40C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BE49C;
    }
    goto skip_0;
    // 0x804BE40C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BE410: lwc1        $f8, -0x4E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41F0));
    // 0x804BE414: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x804BE418: nop

    // 0x804BE41C: bc1tl       L_804BE49C
    if (c1cs) {
        // 0x804BE420: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BE49C;
    }
    goto skip_1;
    // 0x804BE420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804BE424: lh          $v0, 0x2E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2E);
    // 0x804BE428: lui         $t9, 0x804C
    ctx->r25 = S32(RELOC_HI16(191, 0X3DC0) << 16);
    // 0x804BE42C: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(191, 0X2850) << 16);
    // 0x804BE430: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x804BE434: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x804BE438: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x804BE43C: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x804BE440: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x804BE444: sh          $v0, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r2;
    // 0x804BE448: lh          $t9, -0x910($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(191, 0X3DC0));
    // 0x804BE44C: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(191, 0X1FBC) << 16);
    // 0x804BE450: addiu       $t1, $t1, -0x1E80
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(191, 0X2850));
    // 0x804BE454: sh          $t9, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r25;
    // 0x804BE458: lh          $t0, 0x2E($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2E);
    // 0x804BE45C: addiu       $t2, $t2, -0x2714
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(191, 0X1FBC));
    // 0x804BE460: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x804BE464: bnel        $at, $zero, L_804BE48C
    if (ctx->r1 != 0) {
        // 0x804BE468: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_804BE48C;
    }
    goto skip_2;
    // 0x804BE468: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_2:
    // 0x804BE46C: sh          $zero, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = 0;
    // 0x804BE470: sh          $zero, 0x144($v1)
    MEM_H(0X144, ctx->r3) = 0;
    // 0x804BE474: sw          $t1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r9;
    // 0x804BE478: jal         0x804BD678
    // 0x804BE47C: sw          $t2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r10;
    func_804BD678(rdram, ctx);
        goto after_0;
    // 0x804BE47C: sw          $t2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r10;
    after_0:
    // 0x804BE480: b           L_804BE49C
    // 0x804BE484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804BE49C;
    // 0x804BE484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BE488: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_804BE48C:
    // 0x804BE48C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804BE490: nop

    // 0x804BE494: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x804BE498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BE49C:
    // 0x804BE49C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BE4A0: jr          $ra
    // 0x804BE4A4: nop

    return;
    // 0x804BE4A4: nop

;}
RECOMP_FUNC void func_80032C5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032C5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032C60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032C64: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80032C68: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80032C6C: addiu       $t7, $t7, 0x3450
    ctx->r15 = ADD32(ctx->r15, 0X3450);
    // 0x80032C70: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x80032C74: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80032C78: lbu         $t8, 0x155($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X155);
    // 0x80032C7C: sb          $zero, 0x154($a1)
    MEM_B(0X154, ctx->r5) = 0;
    // 0x80032C80: beql        $t8, $zero, L_80032C94
    if (ctx->r24 == 0) {
        // 0x80032C84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80032C94;
    }
    goto skip_0;
    // 0x80032C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80032C88: jal         0x80032A8C
    // 0x80032C8C: nop

    func_80032A8C(rdram, ctx);
        goto after_0;
    // 0x80032C8C: nop

    after_0:
    // 0x80032C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80032C94:
    // 0x80032C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032C98: jr          $ra
    // 0x80032C9C: nop

    return;
    // 0x80032C9C: nop

;}
RECOMP_FUNC void func_80777864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80777864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80777868: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8077786C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80777870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80777874: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80777878: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x8077787C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80777880: lui         $t9, 0x8077
    ctx->r25 = S32(RELOC_HI16(775, 0X4BC) << 16);
    // 0x80777884: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80777888: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8077788C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80777890: lw          $t9, 0x78CC($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(775, 0X4BC));
    // 0x80777894: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80777898: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x8077789C: jal         0x80777508
    // 0x807778A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80777508(rdram, ctx);
        goto after_0;
    // 0x807778A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807778A4: jal         0x80777514
    // 0x807778A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80777514(rdram, ctx);
        goto after_1;
    // 0x807778A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x807778AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807778B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807778B4: jr          $ra
    // 0x807778B8: nop

    return;
    // 0x807778B8: nop

    // 0x807778BC: nop

;}
RECOMP_FUNC void func_8041E7D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041E7D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8041E7D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041E7DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8041E7E0: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8041E7E4: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8041E7E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041E7EC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8041E7F0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8041E7F4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8041E7F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8041E7FC: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8041E800: bc1fl       L_8041E814
    if (!c1cs) {
        // 0x8041E804: lwc1        $f6, 0x18($a2)
        ctx->f6.u32l = MEM_W(ctx->r6, 0X18);
            goto L_8041E814;
    }
    goto skip_0;
    // 0x8041E804: lwc1        $f6, 0x18($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X18);
    skip_0:
    // 0x8041E808: b           L_8041E82C
    // 0x8041E80C: sh          $t6, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = ctx->r14;
        goto L_8041E82C;
    // 0x8041E80C: sh          $t6, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = ctx->r14;
    // 0x8041E810: lwc1        $f6, 0x18($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X18);
L_8041E814:
    // 0x8041E814: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8041E818: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8041E81C: nop

    // 0x8041E820: bc1fl       L_8041E830
    if (!c1cs) {
        // 0x8041E824: lh          $v0, 0x2C($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X2C);
            goto L_8041E830;
    }
    goto skip_1;
    // 0x8041E824: lh          $v0, 0x2C($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X2C);
    skip_1:
    // 0x8041E828: sh          $t7, 0x2C($a2)
    MEM_H(0X2C, ctx->r6) = ctx->r15;
L_8041E82C:
    // 0x8041E82C: lh          $v0, 0x2C($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X2C);
L_8041E830:
    // 0x8041E830: addiu       $a1, $s0, 0x13C
    ctx->r5 = ADD32(ctx->r16, 0X13C);
    // 0x8041E834: beq         $v0, $zero, L_8041E860
    if (ctx->r2 == 0) {
        // 0x8041E838: nop
    
            goto L_8041E860;
    }
    // 0x8041E838: nop

    // 0x8041E83C: beq         $v0, $at, L_8041E87C
    if (ctx->r2 == ctx->r1) {
        // 0x8041E840: addiu       $a0, $s0, 0x3C
        ctx->r4 = ADD32(ctx->r16, 0X3C);
            goto L_8041E87C;
    }
    // 0x8041E840: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8041E844: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8041E848: beq         $v0, $at, L_8041E994
    if (ctx->r2 == ctx->r1) {
        // 0x8041E84C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8041E994;
    }
    // 0x8041E84C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8041E850: beql        $v0, $at, L_8041E998
    if (ctx->r2 == ctx->r1) {
        // 0x8041E854: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041E998;
    }
    goto skip_2;
    // 0x8041E854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8041E858: b           L_8041E998
    // 0x8041E85C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8041E998;
    // 0x8041E85C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041E860:
    // 0x8041E860: jal         0x800598F0
    // 0x8041E864: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    func_800598F0(rdram, ctx);
        goto after_0;
    // 0x8041E864: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8041E868: beq         $v0, $zero, L_8041E994
    if (ctx->r2 == 0) {
        // 0x8041E86C: lw          $a2, 0x3C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X3C);
            goto L_8041E994;
    }
    // 0x8041E86C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8041E870: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8041E874: b           L_8041E994
    // 0x8041E878: sh          $t8, 0x2C($a2)
    MEM_H(0X2C, ctx->r6) = ctx->r24;
        goto L_8041E994;
    // 0x8041E878: sh          $t8, 0x2C($a2)
    MEM_H(0X2C, ctx->r6) = ctx->r24;
L_8041E87C:
    // 0x8041E87C: addiu       $a1, $s0, 0x13C
    ctx->r5 = ADD32(ctx->r16, 0X13C);
    // 0x8041E880: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8041E884: jal         0x80059398
    // 0x8041E888: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80059398(rdram, ctx);
        goto after_1;
    // 0x8041E888: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x8041E88C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8041E890: beq         $v0, $zero, L_8041E910
    if (ctx->r2 == 0) {
        // 0x8041E894: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_8041E910;
    }
    // 0x8041E894: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8041E898: jal         0x80081C64
    // 0x8041E89C: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    Math_FFloorF(rdram, ctx);
        goto after_2;
    // 0x8041E89C: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    after_2:
    // 0x8041E8A0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8041E8A4: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8041E8A8: lw          $v0, 0x3F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X3F4);
    // 0x8041E8AC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8041E8B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8041E8B4: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8041E8B8: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8041E8BC: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X34FC) << 16);
    // 0x8041E8C0: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8041E8C4: lh          $t0, 0x13C($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X13C);
    // 0x8041E8C8: lw          $t9, 0x478($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X478);
    // 0x8041E8CC: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8041E8D0: lwc1        $f8, 0xB5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X34FC));
    // 0x8041E8D4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8041E8D8: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8041E8DC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8041E8E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8041E8E4: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8041E8E8: lwc1        $f4, 0x30($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X30);
    // 0x8041E8EC: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8041E8F0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8041E8F4: add.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x8041E8F8: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8041E8FC: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8041E900: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8041E904: add.s       $f14, $f16, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8041E908: b           L_8041E994
    // 0x8041E90C: swc1        $f14, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f14.u32l;
        goto L_8041E994;
    // 0x8041E90C: swc1        $f14, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f14.u32l;
L_8041E910:
    // 0x8041E910: jal         0x800594F8
    // 0x8041E914: nop

    func_800594F8(rdram, ctx);
        goto after_3;
    // 0x8041E914: nop

    after_3:
    // 0x8041E918: beql        $v0, $zero, L_8041E998
    if (ctx->r2 == 0) {
        // 0x8041E91C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041E998;
    }
    goto skip_3;
    // 0x8041E91C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8041E920: jal         0x80081C64
    // 0x8041E924: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    Math_FFloorF(rdram, ctx);
        goto after_4;
    // 0x8041E924: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    after_4:
    // 0x8041E928: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8041E92C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8041E930: lw          $v0, 0x3F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X3F4);
    // 0x8041E934: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8041E938: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8041E93C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8041E940: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8041E944: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3500) << 16);
    // 0x8041E948: div.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8041E94C: lh          $t3, 0x13C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X13C);
    // 0x8041E950: lw          $t2, 0x478($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X478);
    // 0x8041E954: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8041E958: lwc1        $f10, 0xB60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3500));
    // 0x8041E95C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8041E960: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8041E964: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8041E968: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8041E96C: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8041E970: lwc1        $f16, 0x30($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X30);
    // 0x8041E974: mul.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8041E978: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8041E97C: add.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x8041E980: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8041E984: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8041E988: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8041E98C: sub.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8041E990: swc1        $f14, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f14.u32l;
L_8041E994:
    // 0x8041E994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041E998:
    // 0x8041E998: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041E99C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8041E9A0: jr          $ra
    // 0x8041E9A4: nop

    return;
    // 0x8041E9A4: nop

;}
RECOMP_FUNC void func_806F980C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F980C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F9810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F9814: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x806F9818: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x806F981C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806F9820: jal         0x80065ABC
    // 0x806F9824: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x806F9824: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F9828: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F982C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x806F9830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F9834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F9838: jr          $ra
    // 0x806F983C: nop

    return;
    // 0x806F983C: nop

;}
RECOMP_FUNC void func_8044A348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A348: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044A34C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8044A350: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8044A354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A358: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044A35C: bne         $a2, $zero, L_8044A3A0
    if (ctx->r6 != 0) {
        // 0x8044A360: lw          $v0, 0x1F4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X1F4);
            goto L_8044A3A0;
    }
    // 0x8044A360: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044A364: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x8044A368: lw          $v1, 0x11C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X11C);
    // 0x8044A36C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044A370: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x8044A374: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8044A378: bne         $at, $zero, L_8044A390
    if (ctx->r1 != 0) {
        // 0x8044A37C: sw          $t7, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->r15;
            goto L_8044A390;
    }
    // 0x8044A37C: sw          $t7, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r15;
    // 0x8044A380: jal         0x80446C80
    // 0x8044A384: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446C80(rdram, ctx);
        goto after_0;
    // 0x8044A384: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8044A388: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A38C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_8044A390:
    // 0x8044A390: jal         0x8044A060
    // 0x8044A394: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    func_8044A060(rdram, ctx);
        goto after_1;
    // 0x8044A394: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    after_1:
    // 0x8044A398: b           L_8044A3E4
    // 0x8044A39C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044A3E4;
    // 0x8044A39C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A3A0:
    // 0x8044A3A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044A3A4: bne         $a2, $at, L_8044A3CC
    if (ctx->r6 != ctx->r1) {
        // 0x8044A3A8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044A3CC;
    }
    // 0x8044A3A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044A3AC: jal         0x80446C40
    // 0x8044A3B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446C40(rdram, ctx);
        goto after_2;
    // 0x8044A3B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8044A3B4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A3B8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A3BC: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x8044A3C0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044A3C4: b           L_8044A3E0
    // 0x8044A3C8: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_8044A3E0;
    // 0x8044A3C8: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_8044A3CC:
    // 0x8044A3CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8044A3D0: bnel        $a2, $at, L_8044A3E4
    if (ctx->r6 != ctx->r1) {
        // 0x8044A3D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044A3E4;
    }
    goto skip_0;
    // 0x8044A3D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044A3D8: jal         0x80446C80
    // 0x8044A3DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80446C80(rdram, ctx);
        goto after_3;
    // 0x8044A3DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
L_8044A3E0:
    // 0x8044A3E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A3E4:
    // 0x8044A3E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044A3E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8044A3EC: jr          $ra
    // 0x8044A3F0: nop

    return;
    // 0x8044A3F0: nop

;}
RECOMP_FUNC void func_8046CFE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046CFE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046CFE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046CFE8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8046CFEC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8046CFF0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8046CFF4: jal         0x80048F84
    // 0x8046CFF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8046CFF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8046CFFC: jal         0x8046C850
    // 0x8046D000: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8046C850(rdram, ctx);
        goto after_1;
    // 0x8046D000: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8046D004: beq         $v0, $zero, L_8046D048
    if (ctx->r2 == 0) {
        // 0x8046D008: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_8046D048;
    }
    // 0x8046D008: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8046D00C: lw          $t6, 0x1F4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1F4);
    // 0x8046D010: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8046D014: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8046D018: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8046D01C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046D020: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8046D024: bne         $at, $zero, L_8046D040
    if (ctx->r1 != 0) {
        // 0x8046D028: nop
    
            goto L_8046D040;
    }
    // 0x8046D028: nop

    // 0x8046D02C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8046D030: jal         0x8046D3E8
    // 0x8046D034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8046D3E8(rdram, ctx);
        goto after_2;
    // 0x8046D034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8046D038: b           L_8046D04C
    // 0x8046D03C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8046D04C;
    // 0x8046D03C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046D040:
    // 0x8046D040: jal         0x8046D3E8
    // 0x8046D044: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_8046D3E8(rdram, ctx);
        goto after_3;
    // 0x8046D044: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_3:
L_8046D048:
    // 0x8046D048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046D04C:
    // 0x8046D04C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046D050: jr          $ra
    // 0x8046D054: nop

    return;
    // 0x8046D054: nop

;}
RECOMP_FUNC void func_8044AC84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044AC84: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044AC88: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X134B4) << 16);
    // 0x8044AC8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044AC90: addiu       $t6, $t6, 0x7894
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X134B4));
    // 0x8044AC94: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044AC98: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044AC9C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044ACA0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044ACA4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044ACA8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044ACAC: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044ACB0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044ACB4: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044ACB8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044ACBC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044ACC0: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044ACC4: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044ACC8: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044ACCC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044ACD0: jal         0x80050A50
    // 0x8044ACD4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044ACD4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044ACD8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044ACDC: jalr        $v0
    // 0x8044ACE0: sw          $v0, 0x6A84($v1)
    MEM_W(0X6A84, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044ACE0: sw          $v0, 0x6A84($v1)
    MEM_W(0X6A84, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044ACE4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044ACE8: sw          $v0, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r2;
    // 0x8044ACEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044ACF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044ACF4: jr          $ra
    // 0x8044ACF8: nop

    return;
    // 0x8044ACF8: nop

;}
RECOMP_FUNC void func_80034930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034930: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80034934: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80034938: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003493C: jal         0x80030104
    // 0x80034940: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80030104(rdram, ctx);
        goto after_0;
    // 0x80034940: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80034944: jal         0x80041D3C
    // 0x80034948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80041D3C(rdram, ctx);
        goto after_1;
    // 0x80034948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003494C: jal         0x80041F58
    // 0x80034950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80041F58(rdram, ctx);
        goto after_2;
    // 0x80034950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80034954: jal         0x80041FE8
    // 0x80034958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80041FE8(rdram, ctx);
        goto after_3;
    // 0x80034958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8003495C: jal         0x80041450
    // 0x80034960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80041450(rdram, ctx);
        goto after_4;
    // 0x80034960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80034964: jal         0x80036924
    // 0x80034968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036924(rdram, ctx);
        goto after_5;
    // 0x80034968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8003496C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80034970: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80034974: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80034978: jr          $ra
    // 0x8003497C: nop

    return;
    // 0x8003497C: nop

;}
RECOMP_FUNC void func_804C365C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C365C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C3660: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x804C3664: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x804C3668: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x804C366C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x804C3670: lui         $s1, 0x400
    ctx->r17 = S32(0X400 << 16);
    // 0x804C3674: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804C3678: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x804C367C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804C3680: ori         $s1, $s1, 0x81FF
    ctx->r17 = ctx->r17 | 0X81FF;
    // 0x804C3684: lui         $s2, 0xB100
    ctx->r18 = S32(0XB100 << 16);
    // 0x804C3688: addiu       $s3, $zero, 0x18
    ctx->r19 = ADD32(0, 0X18);
    // 0x804C368C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_804C3690:
    // 0x804C3690: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x804C3694: bne         $at, $zero, L_804C36C0
    if (ctx->r1 != 0) {
        // 0x804C3698: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_804C36C0;
    }
    // 0x804C3698: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x804C369C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x804C36A0: sll         $t6, $a2, 9
    ctx->r14 = S32(ctx->r6 << 9);
    // 0x804C36A4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x804C36A8: addiu       $t8, $t7, 0x308
    ctx->r24 = ADD32(ctx->r15, 0X308);
    // 0x804C36AC: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x804C36B0: sw          $s1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r17;
    // 0x804C36B4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x804C36B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x804C36BC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_804C36C0:
    // 0x804C36C0: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x804C36C4: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x804C36C8: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x804C36CC: andi        $t9, $t1, 0xFF
    ctx->r25 = ctx->r9 & 0XFF;
    // 0x804C36D0: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x804C36D4: sll         $t7, $t3, 8
    ctx->r15 = S32(ctx->r11 << 8);
    // 0x804C36D8: addiu       $t4, $t1, 0x4
    ctx->r12 = ADD32(ctx->r9, 0X4);
    // 0x804C36DC: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x804C36E0: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x804C36E4: or          $t9, $t8, $t5
    ctx->r25 = ctx->r24 | ctx->r13;
    // 0x804C36E8: or          $t6, $t9, $s2
    ctx->r14 = ctx->r25 | ctx->r18;
    // 0x804C36EC: addiu       $s0, $t1, 0x6
    ctx->r16 = ADD32(ctx->r9, 0X6);
    // 0x804C36F0: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x804C36F4: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x804C36F8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x804C36FC: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x804C3700: sll         $t7, $t3, 16
    ctx->r15 = S32(ctx->r11 << 16);
    // 0x804C3704: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x804C3708: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804C370C: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x804C3710: or          $t8, $t6, $t5
    ctx->r24 = ctx->r14 | ctx->r13;
    // 0x804C3714: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x804C3718: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x804C371C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x804C3720: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804C3724: addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // 0x804C3728: bne         $at, $zero, L_804C3764
    if (ctx->r1 != 0) {
        // 0x804C372C: addiu       $t2, $t2, 0x8
        ctx->r10 = ADD32(ctx->r10, 0X8);
            goto L_804C3764;
    }
    // 0x804C372C: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x804C3730: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x804C3734: sll         $t7, $a2, 9
    ctx->r15 = S32(ctx->r6 << 9);
    // 0x804C3738: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x804C373C: addiu       $t6, $t9, 0x308
    ctx->r14 = ADD32(ctx->r25, 0X308);
    // 0x804C3740: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x804C3744: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x804C3748: sw          $s1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r17;
    // 0x804C374C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x804C3750: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x804C3754: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x804C3758: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x804C375C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x804C3760: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
L_804C3764:
    // 0x804C3764: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x804C3768: andi        $t8, $t1, 0xFF
    ctx->r24 = ctx->r9 & 0XFF;
    // 0x804C376C: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x804C3770: sll         $t9, $t3, 8
    ctx->r25 = S32(ctx->r11 << 8);
    // 0x804C3774: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x804C3778: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x804C377C: or          $t8, $t6, $t5
    ctx->r24 = ctx->r14 | ctx->r13;
    // 0x804C3780: or          $t7, $t8, $s2
    ctx->r15 = ctx->r24 | ctx->r18;
    // 0x804C3784: andi        $t6, $s0, 0xFF
    ctx->r14 = ctx->r16 & 0XFF;
    // 0x804C3788: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x804C378C: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x804C3790: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x804C3794: sll         $t9, $t3, 16
    ctx->r25 = S32(ctx->r11 << 16);
    // 0x804C3798: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x804C379C: or          $t6, $t7, $t5
    ctx->r14 = ctx->r15 | ctx->r13;
    // 0x804C37A0: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x804C37A4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x804C37A8: bne         $a3, $s3, L_804C3690
    if (ctx->r7 != ctx->r19) {
        // 0x804C37AC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_804C3690;
    }
    // 0x804C37AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804C37B0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x804C37B4: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x804C37B8: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x804C37BC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x804C37C0: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x804C37C4: jr          $ra
    // 0x804C37C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804C37C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006E630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E638: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8006E63C: jal         0x8006E248
    // 0x8006E640: addiu       $a1, $a1, -0x1A84
    ctx->r5 = ADD32(ctx->r5, -0X1A84);
    func_8006E248(rdram, ctx);
        goto after_0;
    // 0x8006E640: addiu       $a1, $a1, -0x1A84
    ctx->r5 = ADD32(ctx->r5, -0X1A84);
    after_0:
    // 0x8006E644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E64C: jr          $ra
    // 0x8006E650: nop

    return;
    // 0x8006E650: nop

;}
RECOMP_FUNC void func_805A6C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6C40: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805A6C44: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x805A6C48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A6C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A6C50: beq         $t6, $zero, L_805A6C7C
    if (ctx->r14 == 0) {
        // 0x805A6C54: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_805A6C7C;
    }
    // 0x805A6C54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805A6C58: lui         $t8, 0x805A
    ctx->r24 = S32(RELOC_HI16(420, 0X1D4) << 16);
    // 0x805A6C5C: addiu       $t8, $t8, 0x6BB4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(420, 0X1D4));
    // 0x805A6C60: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805A6C64: sb          $t7, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r15;
    // 0x805A6C68: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x805A6C6C: jal         0x8005FDC4
    // 0x805A6C70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FDC4(rdram, ctx);
        goto after_0;
    // 0x805A6C70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A6C74: jal         0x805A6A30
    // 0x805A6C78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805A6A30(rdram, ctx);
        goto after_1;
    // 0x805A6C78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_805A6C7C:
    // 0x805A6C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A6C80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A6C84: jr          $ra
    // 0x805A6C88: nop

    return;
    // 0x805A6C88: nop

;}
RECOMP_FUNC void func_80714D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80714D40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80714D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80714D48: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80714D4C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80714D50: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80714D54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80714D58: jal         0x80714A38
    // 0x80714D5C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80714A38(rdram, ctx);
        goto after_0;
    // 0x80714D5C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x80714D60: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80714D64: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80714D68: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(730, 0X1880) << 16);
    // 0x80714D6C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80714D70: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x80714D74: lbu         $t0, 0x2C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2C);
    // 0x80714D78: beql        $t0, $zero, L_80714DB4
    if (ctx->r8 == 0) {
        // 0x80714D7C: lwc1        $f8, 0x0($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
            goto L_80714DB4;
    }
    goto skip_0;
    // 0x80714D7C: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80714D80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80714D84: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80714D88: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80714D8C: nop

    // 0x80714D90: bc1f        L_80714DA0
    if (!c1cs) {
        // 0x80714D94: nop
    
            goto L_80714DA0;
    }
    // 0x80714D94: nop

    // 0x80714D98: b           L_80714DC4
    // 0x80714D9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80714DC4;
    // 0x80714D9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80714DA0:
    // 0x80714DA0: jal         0x80714A38
    // 0x80714DA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80714A38(rdram, ctx);
        goto after_1;
    // 0x80714DA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80714DA8: b           L_80714DC4
    // 0x80714DAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80714DC4;
    // 0x80714DAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80714DB0: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
L_80714DB4:
    // 0x80714DB4: lwc1        $f10, 0x60A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(730, 0X1880));
    // 0x80714DB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80714DBC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80714DC0: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
L_80714DC4:
    // 0x80714DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80714DC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80714DCC: jr          $ra
    // 0x80714DD0: nop

    return;
    // 0x80714DD0: nop

;}
RECOMP_FUNC void func_8059F7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059F7C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8059F7C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8059F7C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8059F7CC: jal         0x8059F6C4
    // 0x8059F7D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8059F6C4(rdram, ctx);
        goto after_0;
    // 0x8059F7D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8059F7D4: beq         $v0, $zero, L_8059F7EC
    if (ctx->r2 == 0) {
        // 0x8059F7D8: nop
    
            goto L_8059F7EC;
    }
    // 0x8059F7D8: nop

    // 0x8059F7DC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8059F7E0: lhu         $t6, 0x8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8);
    // 0x8059F7E4: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8059F7E8: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
L_8059F7EC:
    // 0x8059F7EC: jal         0x8059F608
    // 0x8059F7F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8059F608(rdram, ctx);
        goto after_1;
    // 0x8059F7F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8059F7F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8059F7F8: beq         $v0, $at, L_8059F810
    if (ctx->r2 == ctx->r1) {
        // 0x8059F7FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8059F810;
    }
    // 0x8059F7FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8059F800: beql        $v0, $at, L_8059F824
    if (ctx->r2 == ctx->r1) {
        // 0x8059F804: lbu         $t8, 0x30($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X30);
            goto L_8059F824;
    }
    goto skip_0;
    // 0x8059F804: lbu         $t8, 0x30($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X30);
    skip_0:
    // 0x8059F808: b           L_8059F8DC
    // 0x8059F80C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
        goto L_8059F8DC;
    // 0x8059F80C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8059F810:
    // 0x8059F810: jal         0x8059F3CC
    // 0x8059F814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8059F3CC(rdram, ctx);
        goto after_2;
    // 0x8059F814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8059F818: b           L_8059F8DC
    // 0x8059F81C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
        goto L_8059F8DC;
    // 0x8059F81C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8059F820: lbu         $t8, 0x30($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X30);
L_8059F824:
    // 0x8059F824: bnel        $t8, $zero, L_8059F838
    if (ctx->r24 != 0) {
        // 0x8059F828: lw          $t9, 0x1F4($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X1F4);
            goto L_8059F838;
    }
    goto skip_1;
    // 0x8059F828: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    skip_1:
    // 0x8059F82C: jal         0x8005FDC4
    // 0x8059F830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x8059F830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8059F834: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
L_8059F838:
    // 0x8059F838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059F83C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059F840: lhu         $t1, 0x8($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X8);
    // 0x8059F844: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8059F848: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8059F84C: beq         $t2, $zero, L_8059F870
    if (ctx->r10 == 0) {
        // 0x8059F850: nop
    
            goto L_8059F870;
    }
    // 0x8059F850: nop

    // 0x8059F854: jal         0x805A0790
    // 0x8059F858: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805A0790(rdram, ctx);
        goto after_4;
    // 0x8059F858: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8059F85C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8059F860: lhu         $t3, 0x8($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X8);
    // 0x8059F864: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x8059F868: b           L_8059F8D8
    // 0x8059F86C: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
        goto L_8059F8D8;
    // 0x8059F86C: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
L_8059F870:
    // 0x8059F870: jal         0x800653D8
    // 0x8059F874: nop

    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x8059F874: nop

    after_5:
    // 0x8059F878: andi        $v1, $v0, 0x7
    ctx->r3 = ctx->r2 & 0X7;
    // 0x8059F87C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8059F880: beq         $at, $zero, L_8059F8A0
    if (ctx->r1 == 0) {
        // 0x8059F884: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8059F8A0;
    }
    // 0x8059F884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059F888: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059F88C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8059F890: jal         0x805A0790
    // 0x8059F894: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805A0790(rdram, ctx);
        goto after_6;
    // 0x8059F894: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x8059F898: b           L_8059F8D8
    // 0x8059F89C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
        goto L_8059F8D8;
    // 0x8059F89C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_8059F8A0:
    // 0x8059F8A0: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8059F8A4: beq         $at, $zero, L_8059F8C8
    if (ctx->r1 == 0) {
        // 0x8059F8A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8059F8C8;
    }
    // 0x8059F8A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059F8AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059F8B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059F8B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8059F8B8: jal         0x805A0790
    // 0x8059F8BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805A0790(rdram, ctx);
        goto after_7;
    // 0x8059F8BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8059F8C0: b           L_8059F8DC
    // 0x8059F8C4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
        goto L_8059F8DC;
    // 0x8059F8C4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8059F8C8:
    // 0x8059F8C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059F8CC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8059F8D0: jal         0x805A0790
    // 0x8059F8D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805A0790(rdram, ctx);
        goto after_8;
    // 0x8059F8D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
L_8059F8D8:
    // 0x8059F8D8: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8059F8DC:
    // 0x8059F8DC: lhu         $t5, 0x8($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X8);
    // 0x8059F8E0: andi        $t6, $t5, 0xFFF7
    ctx->r14 = ctx->r13 & 0XFFF7;
    // 0x8059F8E4: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x8059F8E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8059F8EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8059F8F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8059F8F4: jr          $ra
    // 0x8059F8F8: nop

    return;
    // 0x8059F8F8: nop

;}
RECOMP_FUNC void func_800675F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800675F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800675F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800675F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800675FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80067600: lbu         $t6, 0x15C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15C);
    // 0x80067604: addiu       $v0, $a0, 0x15C
    ctx->r2 = ADD32(ctx->r4, 0X15C);
    // 0x80067608: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8006760C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80067610: slti        $at, $t8, 0xA
    ctx->r1 = SIGNED(ctx->r24) < 0XA ? 1 : 0;
    // 0x80067614: bne         $at, $zero, L_80067620
    if (ctx->r1 != 0) {
        // 0x80067618: sb          $t7, 0x15C($a0)
        MEM_B(0X15C, ctx->r4) = ctx->r15;
            goto L_80067620;
    }
    // 0x80067618: sb          $t7, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = ctx->r15;
    // 0x8006761C: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
L_80067620:
    // 0x80067620: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80067624: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x80067628: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x8006762C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80067630: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80067634: beq         $t9, $zero, L_80067668
    if (ctx->r25 == 0) {
        // 0x80067638: sll         $t0, $t0, 3
        ctx->r8 = S32(ctx->r8 << 3);
            goto L_80067668;
    }
    // 0x80067638: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8006763C: addu        $s1, $v0, $t0
    ctx->r17 = ADD32(ctx->r2, ctx->r8);
    // 0x80067640: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80067644:
    // 0x80067644: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80067648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006764C: jal         0x800824B0
    // 0x80067650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80067650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80067654: lbu         $t1, 0x1($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1);
    // 0x80067658: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8006765C: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x80067660: bne         $t3, $zero, L_80067644
    if (ctx->r11 != 0) {
        // 0x80067664: sb          $t2, 0x1($s0)
        MEM_B(0X1, ctx->r16) = ctx->r10;
            goto L_80067644;
    }
    // 0x80067664: sb          $t2, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r10;
L_80067668:
    // 0x80067668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006766C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80067670: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80067674: jr          $ra
    // 0x80067678: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80067678: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80467B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80467B0C: addiu       $sp, $sp, -0x1F0
    ctx->r29 = ADD32(ctx->r29, -0X1F0);
    // 0x80467B10: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80467B14: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80467B18: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80467B1C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80467B20: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80467B24: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80467B28: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80467B2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80467B30: lw          $s3, 0x1F4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1F4);
    // 0x80467B34: addiu       $s6, $sp, 0x5C
    ctx->r22 = ADD32(ctx->r29, 0X5C);
    // 0x80467B38: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80467B3C: lh          $a1, 0x1A($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X1A);
    // 0x80467B40: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80467B44: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80467B48: blez        $a1, L_80467B70
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80467B4C: addiu       $s0, $s3, 0x2885
        ctx->r16 = ADD32(ctx->r19, 0X2885);
            goto L_80467B70;
    }
    // 0x80467B4C: addiu       $s0, $s3, 0x2885
    ctx->r16 = ADD32(ctx->r19, 0X2885);
L_80467B50:
    // 0x80467B50: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80467B54: lh          $a1, 0x1A($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X1A);
    // 0x80467B58: lh          $t6, 0x18($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X18);
    // 0x80467B5C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80467B60: slt         $at, $s2, $a1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80467B64: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80467B68: bne         $at, $zero, L_80467B50
    if (ctx->r1 != 0) {
        // 0x80467B6C: addu        $v1, $v1, $t6
        ctx->r3 = ADD32(ctx->r3, ctx->r14);
            goto L_80467B50;
    }
    // 0x80467B6C: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
L_80467B70:
    // 0x80467B70: lh          $t7, 0x18($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X18);
    // 0x80467B74: lw          $t9, 0x1FA0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X1FA0);
    // 0x80467B78: lbu         $t3, 0x2A78($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X2A78);
    // 0x80467B7C: multu       $a1, $t7
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467B80: lbu         $t1, 0x2884($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X2884);
    // 0x80467B84: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80467B88: addu        $t5, $s6, $t4
    ctx->r13 = ADD32(ctx->r22, ctx->r12);
    // 0x80467B8C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80467B90: addiu       $s5, $zero, 0x30
    ctx->r21 = ADD32(0, 0X30);
    // 0x80467B94: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80467B98: addiu       $s1, $s3, 0x2A79
    ctx->r17 = ADD32(ctx->r19, 0X2A79);
    // 0x80467B9C: mflo        $t8
    ctx->r24 = lo;
    // 0x80467BA0: nop

    // 0x80467BA4: nop

    // 0x80467BA8: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467BAC: mflo        $t0
    ctx->r8 = lo;
    // 0x80467BB0: addu        $s4, $t0, $s3
    ctx->r20 = ADD32(ctx->r8, ctx->r19);
    // 0x80467BB4: addiu       $s4, $s4, 0x1C
    ctx->r20 = ADD32(ctx->r20, 0X1C);
    // 0x80467BB8: addu        $t2, $s4, $t1
    ctx->r10 = ADD32(ctx->r20, ctx->r9);
    // 0x80467BBC: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x80467BC0: sb          $s5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r21;
    // 0x80467BC4: lw          $t8, 0x2C6C($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X2C6C);
    // 0x80467BC8: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80467BCC: bnel        $at, $zero, L_80467C80
    if (ctx->r1 != 0) {
        // 0x80467BD0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80467C80;
    }
    goto skip_0;
    // 0x80467BD0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
L_80467BD4:
    // 0x80467BD4: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x80467BD8: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x80467BDC: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80467BE0: addu        $t4, $s6, $t3
    ctx->r12 = ADD32(ctx->r22, ctx->r11);
    // 0x80467BE4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80467BE8: addu        $t0, $s4, $t9
    ctx->r8 = ADD32(ctx->r20, ctx->r25);
    // 0x80467BEC: addu        $t2, $t0, $t5
    ctx->r10 = ADD32(ctx->r8, ctx->r13);
    // 0x80467BF0: sb          $s5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r21;
    // 0x80467BF4: lbu         $t7, -0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, -0X1);
    // 0x80467BF8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80467BFC: jal         0x8006593C
    // 0x80467C00: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80467C00: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    after_0:
    // 0x80467C04: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80467C08: beql        $at, $zero, L_80467C30
    if (ctx->r1 == 0) {
        // 0x80467C0C: lbu         $t2, 0x0($s1)
        ctx->r10 = MEM_BU(ctx->r17, 0X0);
            goto L_80467C30;
    }
    goto skip_1;
    // 0x80467C0C: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    skip_1:
    // 0x80467C10: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x80467C14: lbu         $t9, -0x1($s1)
    ctx->r25 = MEM_BU(ctx->r17, -0X1);
    // 0x80467C18: jal         0x8006593C
    // 0x80467C1C: subu        $a0, $t8, $t9
    ctx->r4 = SUB32(ctx->r24, ctx->r25);
    func_8006593C(rdram, ctx);
        goto after_1;
    // 0x80467C1C: subu        $a0, $t8, $t9
    ctx->r4 = SUB32(ctx->r24, ctx->r25);
    after_1:
    // 0x80467C20: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80467C24: bnel        $at, $zero, L_80467C68
    if (ctx->r1 != 0) {
        // 0x80467C28: lw          $t0, 0x2C6C($s3)
        ctx->r8 = MEM_W(ctx->r19, 0X2C6C);
            goto L_80467C68;
    }
    goto skip_2;
    // 0x80467C28: lw          $t0, 0x2C6C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X2C6C);
    skip_2:
    // 0x80467C2C: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
L_80467C30:
    // 0x80467C30: lbu         $t6, -0x1($s1)
    ctx->r14 = MEM_BU(ctx->r17, -0X1);
    // 0x80467C34: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x80467C38: lbu         $t3, -0x1($s0)
    ctx->r11 = MEM_BU(ctx->r16, -0X1);
    // 0x80467C3C: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x80467C40: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80467C44: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80467C48: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80467C4C: addu        $t1, $s6, $t9
    ctx->r9 = ADD32(ctx->r22, ctx->r25);
    // 0x80467C50: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80467C54: sra         $t0, $t4, 1
    ctx->r8 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80467C58: addu        $t5, $s4, $t0
    ctx->r13 = ADD32(ctx->r20, ctx->r8);
    // 0x80467C5C: addu        $t4, $t5, $t3
    ctx->r12 = ADD32(ctx->r13, ctx->r11);
    // 0x80467C60: sb          $s5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r21;
    // 0x80467C64: lw          $t0, 0x2C6C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X2C6C);
L_80467C68:
    // 0x80467C68: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80467C6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80467C70: slt         $at, $s2, $t0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80467C74: bne         $at, $zero, L_80467BD4
    if (ctx->r1 != 0) {
        // 0x80467C78: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80467BD4;
    }
    // 0x80467C78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80467C7C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80467C80:
    // 0x80467C80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80467C84: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80467C88: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80467C8C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80467C90: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80467C94: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80467C98: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80467C9C: jr          $ra
    // 0x80467CA0: addiu       $sp, $sp, 0x1F0
    ctx->r29 = ADD32(ctx->r29, 0X1F0);
    return;
    // 0x80467CA0: addiu       $sp, $sp, 0x1F0
    ctx->r29 = ADD32(ctx->r29, 0X1F0);
;}
RECOMP_FUNC void func_8003C1A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C1A0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8003C1A4: addiu       $v0, $v0, -0x29E4
    ctx->r2 = ADD32(ctx->r2, -0X29E4);
    // 0x8003C1A8: jr          $ra
    // 0x8003C1AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8003C1AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8001CF70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CF70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001CF74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CF78: lui         $a1, 0xC2C8
    ctx->r5 = S32(0XC2C8 << 16);
    // 0x8001CF7C: jal         0x800485B8
    // 0x8001CF80: lui         $a2, 0xC28C
    ctx->r6 = S32(0XC28C << 16);
    func_800485B8(rdram, ctx);
        goto after_0;
    // 0x8001CF80: lui         $a2, 0xC28C
    ctx->r6 = S32(0XC28C << 16);
    after_0:
    // 0x8001CF84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CF88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001CF8C: jr          $ra
    // 0x8001CF90: nop

    return;
    // 0x8001CF90: nop

;}
RECOMP_FUNC void func_806EF314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF314: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806EF318: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806EF31C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806EF320: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EF324: jal         0x80045A34
    // 0x806EF328: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806EF328: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x806EF32C: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(676, 0X33A4) << 16);
    // 0x806EF330: addiu       $t6, $t6, -0xD0C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(676, 0X33A4));
    // 0x806EF334: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806EF338: bne         $v0, $zero, L_806EF348
    if (ctx->r2 != 0) {
        // 0x806EF33C: sw          $t6, 0x1F8($s0)
        MEM_W(0X1F8, ctx->r16) = ctx->r14;
            goto L_806EF348;
    }
    // 0x806EF33C: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
    // 0x806EF340: b           L_806EF3E4
    // 0x806EF344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806EF3E4;
    // 0x806EF344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806EF348:
    // 0x806EF348: jal         0x806EF2D0
    // 0x806EF34C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF2D0(rdram, ctx);
        goto after_1;
    // 0x806EF34C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EF350: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EF354: jal         0x80058958
    // 0x806EF358: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_80058958(rdram, ctx);
        goto after_2;
    // 0x806EF358: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_2:
    // 0x806EF35C: beq         $v0, $zero, L_806EF3E0
    if (ctx->r2 == 0) {
        // 0x806EF360: lui         $t8, 0x8010
        ctx->r24 = S32(0X8010 << 16);
            goto L_806EF3E0;
    }
    // 0x806EF360: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x806EF364: lw          $t8, -0x7BC4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7BC4);
    // 0x806EF368: lw          $t9, 0x10C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10C);
    // 0x806EF36C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x806EF370: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x806EF374: beql        $t1, $zero, L_806EF3E4
    if (ctx->r9 == 0) {
        // 0x806EF378: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_806EF3E4;
    }
    goto skip_0;
    // 0x806EF378: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x806EF37C: jal         0x80056564
    // 0x806EF380: nop

    func_80056564(rdram, ctx);
        goto after_3;
    // 0x806EF380: nop

    after_3:
    // 0x806EF384: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x806EF388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EF38C: beq         $v0, $zero, L_806EF3D8
    if (ctx->r2 == 0) {
        // 0x806EF390: sw          $v0, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r2;
            goto L_806EF3D8;
    }
    // 0x806EF390: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x806EF394: jal         0x800457A0
    // 0x806EF398: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_4;
    // 0x806EF398: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x806EF39C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x806EF3A0: addiu       $t4, $zero, 0x29
    ctx->r12 = ADD32(0, 0X29);
    // 0x806EF3A4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x806EF3A8: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x806EF3AC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x806EF3B0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x806EF3B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806EF3B8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806EF3BC: jal         0x80056584
    // 0x806EF3C0: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80056584(rdram, ctx);
        goto after_5;
    // 0x806EF3C0: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_5:
    // 0x806EF3C4: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x806EF3C8: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806EF3CC: addiu       $t6, $t6, 0x784C
    ctx->r14 = ADD32(ctx->r14, 0X784C);
    // 0x806EF3D0: b           L_806EF3E0
    // 0x806EF3D4: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
        goto L_806EF3E0;
    // 0x806EF3D4: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
L_806EF3D8:
    // 0x806EF3D8: b           L_806EF3E4
    // 0x806EF3DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806EF3E4;
    // 0x806EF3DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806EF3E0:
    // 0x806EF3E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806EF3E4:
    // 0x806EF3E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806EF3E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806EF3EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806EF3F0: jr          $ra
    // 0x806EF3F4: nop

    return;
    // 0x806EF3F4: nop

;}
RECOMP_FUNC void func_80436C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80436C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80436C20: jal         0x80436BBC
    // 0x80436C24: nop

    func_80436BBC(rdram, ctx);
        goto after_0;
    // 0x80436C24: nop

    after_0:
    // 0x80436C28: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80436C2C: beql        $v0, $zero, L_80436C44
    if (ctx->r2 == 0) {
        // 0x80436C30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80436C44;
    }
    goto skip_0;
    // 0x80436C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80436C34: jal         0x80436B7C
    // 0x80436C38: nop

    func_80436B7C(rdram, ctx);
        goto after_1;
    // 0x80436C38: nop

    after_1:
    // 0x80436C3C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80436C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80436C44:
    // 0x80436C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80436C48: jr          $ra
    // 0x80436C4C: nop

    return;
    // 0x80436C4C: nop

;}
RECOMP_FUNC void func_807A7080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A7080: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A7084: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807A7088: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x807A708C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x807A7090: jr          $ra
    // 0x807A7094: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x807A7094: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_807705CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807705CC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807705D0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x807705D4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x807705D8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x807705DC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x807705E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x807705E4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x807705E8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x807705EC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x807705F0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x807705F4: jr          $ra
    // 0x807705F8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x807705F8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80073030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073030: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x80073034: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x80073038: lui         $t7, 0xB00
    ctx->r15 = S32(0XB00 << 16);
    // 0x8007303C: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x80073040: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80073044: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80073048: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
    // 0x8007304C: lbu         $t9, 0x14($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X14);
    // 0x80073050: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80073054: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // 0x80073058: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x8007305C: sw          $t0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r8;
    // 0x80073060: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80073064: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x80073068: jr          $ra
    // 0x8007306C: nop

    return;
    // 0x8007306C: nop

;}
RECOMP_FUNC void func_805662F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805662F8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x805662FC: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x80566300: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80566304: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80566308: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8056630C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80566310: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80566314: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80566318: jr          $ra
    // 0x8056631C: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x8056631C: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_807A6E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6E60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807A6E64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A6E68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807A6E6C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807A6E70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A6E74: blez        $v0, L_807A6E84
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807A6E78: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807A6E84;
    }
    // 0x807A6E78: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807A6E7C: b           L_807A6EB4
    // 0x807A6E80: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_807A6EB4;
    // 0x807A6E80: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_807A6E84:
    // 0x807A6E84: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x807A6E88: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x807A6E8C: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x807A6E90: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x807A6E94: addiu       $a1, $t8, 0x1
    ctx->r5 = ADD32(ctx->r24, 0X1);
    // 0x807A6E98: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x807A6E9C: bne         $at, $zero, L_807A6EAC
    if (ctx->r1 != 0) {
        // 0x807A6EA0: sw          $a1, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r5;
            goto L_807A6EAC;
    }
    // 0x807A6EA0: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x807A6EA4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x807A6EA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_807A6EAC:
    // 0x807A6EAC: jal         0x807A6C40
    // 0x807A6EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A6C40(rdram, ctx);
        goto after_0;
    // 0x807A6EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
L_807A6EB4:
    // 0x807A6EB4: lbu         $a2, 0x30($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X30);
    // 0x807A6EB8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x807A6EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A6EC0: beql        $a2, $at, L_807A6EE0
    if (ctx->r6 == ctx->r1) {
        // 0x807A6EC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807A6EE0;
    }
    goto skip_0;
    // 0x807A6EC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807A6EC8: jal         0x807A7138
    // 0x807A6ECC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807A7138(rdram, ctx);
        goto after_1;
    // 0x807A6ECC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x807A6ED0: jal         0x807A6CF4
    // 0x807A6ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A6CF4(rdram, ctx);
        goto after_2;
    // 0x807A6ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807A6ED8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x807A6EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807A6EE0:
    // 0x807A6EE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807A6EE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807A6EE8: jr          $ra
    // 0x807A6EEC: nop

    return;
    // 0x807A6EEC: nop

;}
RECOMP_FUNC void func_805A7270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A7270: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805A7274: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(423, 0X4E0) << 16);
    // 0x805A7278: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805A727C: addiu       $t6, $t6, 0x72E0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(423, 0X4E0));
    // 0x805A7280: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805A7284: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x805A7288: addiu       $at, $zero, 0x4014
    ctx->r1 = ADD32(0, 0X4014);
    // 0x805A728C: lui         $t3, 0x805A
    ctx->r11 = S32(RELOC_HI16(423, 0X58) << 16);
    // 0x805A7290: bne         $t8, $at, L_805A72C0
    if (ctx->r24 != ctx->r1) {
        // 0x805A7294: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_805A72C0;
    }
    // 0x805A7294: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x805A7298: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x805A729C: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(423, 0X6C) << 16);
    // 0x805A72A0: addiu       $t9, $t9, 0x6E6C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(423, 0X6C));
    // 0x805A72A4: lui         $t1, 0x805A
    ctx->r9 = S32(RELOC_HI16(423, 0X10) << 16);
    // 0x805A72A8: addiu       $t1, $t1, 0x6E10
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(423, 0X10));
    // 0x805A72AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805A72B0: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x805A72B4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x805A72B8: b           L_805A72C8
    // 0x805A72BC: sb          $t2, 0x31($a0)
    MEM_B(0X31, ctx->r4) = ctx->r10;
        goto L_805A72C8;
    // 0x805A72BC: sb          $t2, 0x31($a0)
    MEM_B(0X31, ctx->r4) = ctx->r10;
L_805A72C0:
    // 0x805A72C0: addiu       $t3, $t3, 0x6E58
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(423, 0X58));
    // 0x805A72C4: sw          $t3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r11;
L_805A72C8:
    // 0x805A72C8: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x805A72CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A72D0: jr          $ra
    // 0x805A72D4: sb          $t4, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r12;
    return;
    // 0x805A72D4: sb          $t4, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r12;
    // 0x805A72D8: nop

    // 0x805A72DC: nop

;}
RECOMP_FUNC void func_80532BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532BC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80532BC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80532BC8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80532BCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80532BD0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80532BD4: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80532BD8: jal         0x80067D5C
    // 0x80532BDC: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x80532BDC: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_0:
    // 0x80532BE0: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80532BE4: jal         0x80067818
    // 0x80532BE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80532BE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80532BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80532BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80532BF4: jr          $ra
    // 0x80532BF8: nop

    return;
    // 0x80532BF8: nop

;}
