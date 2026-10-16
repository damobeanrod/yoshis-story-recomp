#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8044284C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044284C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80442850: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80442854: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80442858: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8044285C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80442860: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80442864: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80442868: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8044286C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80442870: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80442874: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80442878: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8044287C: lui         $t2, 0x8044
    ctx->r10 = S32(RELOC_HI16(95, 0X4E4C) << 16);
    // 0x80442880: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80442884: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80442888: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8044288C: lw          $t2, 0x3D4C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(95, 0X4E4C));
    // 0x80442890: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80442894: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80442898: jal         0x804421FC
    // 0x8044289C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804421FC(rdram, ctx);
        goto after_0;
    // 0x8044289C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804428A0: jal         0x80442258
    // 0x804428A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80442258(rdram, ctx);
        goto after_1;
    // 0x804428A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804428A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804428AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804428B0: jr          $ra
    // 0x804428B4: nop

    return;
    // 0x804428B4: nop

    // 0x804428B8: nop

    // 0x804428BC: nop

;}
RECOMP_FUNC void func_8004FD3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FD3C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8004FD40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004FD44: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8004FD48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004FD4C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8004FD50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004FD54: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8004FD58: jal         0x8004FC60
    // 0x8004FD5C: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    func_8004FC60(rdram, ctx);
        goto after_0;
    // 0x8004FD5C: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    after_0:
    // 0x8004FD60: jal         0x8004F290
    // 0x8004FD64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8004F290(rdram, ctx);
        goto after_1;
    // 0x8004FD64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8004FD68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004FD6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004FD70: jr          $ra
    // 0x8004FD74: nop

    return;
    // 0x8004FD74: nop

;}
RECOMP_FUNC void func_806F25B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F25B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806F25B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F25BC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F25C0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x806F25C4: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806F25C8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x806F25CC: jal         0x80066DE4
    // 0x806F25D0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x806F25D0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_0:
    // 0x806F25D4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x806F25D8: lwc1        $f12, 0x50($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X50);
    // 0x806F25DC: jal         0x80066E88
    // 0x806F25E0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x806F25E0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x806F25E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806F25E8: lui         $v1, 0x806F
    ctx->r3 = S32(RELOC_HI16(679, 0X1B64) << 16);
    // 0x806F25EC: lui         $a2, 0x806F
    ctx->r6 = S32(RELOC_HI16(679, 0X1B7C) << 16);
    // 0x806F25F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806F25F4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x806F25F8: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x806F25FC: addiu       $a2, $a2, 0x30FC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(679, 0X1B7C));
    // 0x806F2600: addiu       $v1, $v1, 0x30E4
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(679, 0X1B64));
    // 0x806F2604: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_806F2608:
    // 0x806F2608: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806F260C: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806F2610: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806F2614: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x806F2618: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x806F261C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x806F2620: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x806F2624: nop

    // 0x806F2628: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x806F262C: nop

    // 0x806F2630: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x806F2634: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806F2638: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x806F263C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x806F2640: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x806F2644: swc1        $f8, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f8.u32l;
    // 0x806F2648: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806F264C: swc1        $f6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f6.u32l;
    // 0x806F2650: lwc1        $f10, -0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, -0X4);
    // 0x806F2654: swc1        $f16, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f16.u32l;
    // 0x806F2658: swc1        $f16, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f16.u32l;
    // 0x806F265C: swc1        $f10, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f10.u32l;
    // 0x806F2660: lwc1        $f18, 0x50($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X50);
    // 0x806F2664: sw          $zero, 0x138($v0)
    MEM_W(0X138, ctx->r2) = 0;
    // 0x806F2668: bne         $v1, $a2, L_806F2608
    if (ctx->r3 != ctx->r6) {
        // 0x806F266C: swc1        $f18, 0x50($v0)
        MEM_W(0X50, ctx->r2) = ctx->f18.u32l;
            goto L_806F2608;
    }
    // 0x806F266C: swc1        $f18, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f18.u32l;
    // 0x806F2670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F2674: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806F2678: jr          $ra
    // 0x806F267C: nop

    return;
    // 0x806F267C: nop

;}
RECOMP_FUNC void func_806D0408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D040C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D0410: jal         0x806CFFF4
    // 0x806D0414: nop

    func_806CFFF4(rdram, ctx);
        goto after_0;
    // 0x806D0414: nop

    after_0:
    // 0x806D0418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D041C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D0420: jr          $ra
    // 0x806D0424: nop

    return;
    // 0x806D0424: nop

;}
RECOMP_FUNC void func_80516870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80516870: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(279, 0X10) << 16);
    // 0x80516874: addiu       $v0, $v0, 0x6880
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(279, 0X10));
    // 0x80516878: jr          $ra
    // 0x8051687C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8051687C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805DC534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DC534: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805DC538: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DC53C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805DC540: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DC544: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805DC548: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805DC54C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x805DC550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805DC554: jal         0x805DAE20
    // 0x805DC558: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_805DAE20(rdram, ctx);
        goto after_0;
    // 0x805DC558: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x805DC55C: jal         0x805DBFBC
    // 0x805DC560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DBFBC(rdram, ctx);
        goto after_1;
    // 0x805DC560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805DC564: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x805DC568: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805DC56C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x805DC570: lw          $t8, 0x68($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X68);
    // 0x805DC574: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x805DC578: bne         $t8, $at, L_805DC5C4
    if (ctx->r24 != ctx->r1) {
        // 0x805DC57C: lui         $at, 0x43A0
        ctx->r1 = S32(0X43A0 << 16);
            goto L_805DC5C4;
    }
    // 0x805DC57C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x805DC580: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805DC584: lwc1        $f4, 0x60($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X60);
    // 0x805DC588: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x805DC58C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805DC590: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x805DC594: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x805DC598: nop

    // 0x805DC59C: addiu       $t3, $t2, 0x140
    ctx->r11 = ADD32(ctx->r10, 0X140);
    // 0x805DC5A0: slt         $at, $t3, $t9
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x805DC5A4: beql        $at, $zero, L_805DC608
    if (ctx->r1 == 0) {
        // 0x805DC5A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DC608;
    }
    goto skip_0;
    // 0x805DC5A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805DC5AC: jal         0x805DC140
    // 0x805DC5B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DC140(rdram, ctx);
        goto after_2;
    // 0x805DC5B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805DC5B4: jal         0x805DBB44
    // 0x805DC5B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DBB44(rdram, ctx);
        goto after_3;
    // 0x805DC5B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805DC5BC: b           L_805DC608
    // 0x805DC5C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805DC608;
    // 0x805DC5C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805DC5C4:
    // 0x805DC5C4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x805DC5C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805DC5CC: lwc1        $f16, 0x60($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X60);
    // 0x805DC5D0: lw          $t4, 0x34($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X34);
    // 0x805DC5D4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x805DC5D8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x805DC5DC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x805DC5E0: nop

    // 0x805DC5E4: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x805DC5E8: slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x805DC5EC: beql        $at, $zero, L_805DC608
    if (ctx->r1 == 0) {
        // 0x805DC5F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DC608;
    }
    goto skip_1;
    // 0x805DC5F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805DC5F4: jal         0x805DC1F0
    // 0x805DC5F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DC1F0(rdram, ctx);
        goto after_4;
    // 0x805DC5F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805DC5FC: jal         0x805DBB44
    // 0x805DC600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DBB44(rdram, ctx);
        goto after_5;
    // 0x805DC600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805DC604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805DC608:
    // 0x805DC608: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DC60C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805DC610: jr          $ra
    // 0x805DC614: nop

    return;
    // 0x805DC614: nop

;}
RECOMP_FUNC void func_80052840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80052844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052848: jal         0x80064D1C
    // 0x8005284C: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x8005284C: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    after_0:
    // 0x80052850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80052854: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80052858: jr          $ra
    // 0x8005285C: nop

    return;
    // 0x8005285C: nop

;}
RECOMP_FUNC void func_8044B3F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B3F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044B3F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B3FC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8044B400: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8044B404: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044B408: jal         0x8044A558
    // 0x8044B40C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8044A558(rdram, ctx);
        goto after_0;
    // 0x8044B40C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x8044B410: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B414: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8044B418: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044B41C: bne         $v0, $zero, L_8044B434
    if (ctx->r2 != 0) {
        // 0x8044B420: nop
    
            goto L_8044B434;
    }
    // 0x8044B420: nop

    // 0x8044B424: jal         0x80446AAC
    // 0x8044B428: nop

    func_80446AAC(rdram, ctx);
        goto after_1;
    // 0x8044B428: nop

    after_1:
    // 0x8044B42C: b           L_8044B458
    // 0x8044B430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044B458;
    // 0x8044B430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B434:
    // 0x8044B434: bne         $v0, $at, L_8044B44C
    if (ctx->r2 != ctx->r1) {
        // 0x8044B438: nop
    
            goto L_8044B44C;
    }
    // 0x8044B438: nop

    // 0x8044B43C: jal         0x80446AE8
    // 0x8044B440: nop

    func_80446AE8(rdram, ctx);
        goto after_2;
    // 0x8044B440: nop

    after_2:
    // 0x8044B444: b           L_8044B458
    // 0x8044B448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044B458;
    // 0x8044B448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B44C:
    // 0x8044B44C: jal         0x80446B28
    // 0x8044B450: nop

    func_80446B28(rdram, ctx);
        goto after_3;
    // 0x8044B450: nop

    after_3:
    // 0x8044B454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B458:
    // 0x8044B458: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044B45C: jr          $ra
    // 0x8044B460: nop

    return;
    // 0x8044B460: nop

;}
RECOMP_FUNC void func_80060F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060F6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80060F70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060F74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80060F78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060F7C: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x80060F80: jal         0x80047AB8
    // 0x80060F84: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x80060F84: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80060F88: jal         0x8004816C
    // 0x80060F8C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x80060F8C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x80060F90: jal         0x8005FE48
    // 0x80060F94: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x80060F94: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
    // 0x80060F98: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x80060F9C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80060FA0: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80060FA4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80060FA8: jal         0x80065490
    // 0x80060FAC: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x80060FAC: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_3:
    // 0x80060FB0: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80060FB4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80060FB8: lhu         $t7, 0xC($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XC);
    // 0x80060FBC: bnel        $t7, $at, L_80060FD0
    if (ctx->r15 != ctx->r1) {
        // 0x80060FC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80060FD0;
    }
    goto skip_0;
    // 0x80060FC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80060FC4: lw          $t8, 0x1F4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1F4);
    // 0x80060FC8: sb          $zero, 0xDC($t8)
    MEM_B(0XDC, ctx->r24) = 0;
    // 0x80060FCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80060FD0:
    // 0x80060FD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060FD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80060FD8: jr          $ra
    // 0x80060FDC: nop

    return;
    // 0x80060FDC: nop

;}
RECOMP_FUNC void func_80780CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80780CEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80780CF0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80780CF4: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80780CF8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80780CFC: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80780D00: sh          $zero, -0x6DB8($at)
    MEM_H(-0X6DB8, ctx->r1) = 0;
    // 0x80780D04: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x80780D08: sh          $zero, 0x13AA($v0)
    MEM_H(0X13AA, ctx->r2) = 0;
    // 0x80780D0C: sh          $zero, 0x13AC($v0)
    MEM_H(0X13AC, ctx->r2) = 0;
    // 0x80780D10: sh          $zero, 0x13AE($v0)
    MEM_H(0X13AE, ctx->r2) = 0;
    // 0x80780D14: sh          $zero, 0x13A8($v0)
    MEM_H(0X13A8, ctx->r2) = 0;
    // 0x80780D18: ori         $t1, $zero, 0x4
    ctx->r9 = 0 | 0X4;
    // 0x80780D1C: sb          $zero, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = 0;
    // 0x80780D20: ori         $t4, $t1, 0x10
    ctx->r12 = ctx->r9 | 0X10;
    // 0x80780D24: sb          $t1, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r9;
    // 0x80780D28: ori         $t7, $t4, 0x20
    ctx->r15 = ctx->r12 | 0X20;
    // 0x80780D2C: sb          $t4, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r12;
    // 0x80780D30: ori         $t0, $t7, 0x2
    ctx->r8 = ctx->r15 | 0X2;
    // 0x80780D34: lbu         $t5, 0x13B4($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X13B4);
    // 0x80780D38: sb          $t7, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r15;
    // 0x80780D3C: ori         $t3, $t0, 0x1
    ctx->r11 = ctx->r8 | 0X1;
    // 0x80780D40: sb          $t0, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r8;
    // 0x80780D44: sb          $t3, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r11;
    // 0x80780D48: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x80780D4C: lbu         $t1, 0x13B5($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X13B5);
    // 0x80780D50: andi        $t3, $t5, 0xFF1F
    ctx->r11 = ctx->r13 & 0XFF1F;
    // 0x80780D54: lbu         $t7, 0x13B3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X13B3);
    // 0x80780D58: andi        $t5, $t3, 0xE7
    ctx->r13 = ctx->r11 & 0XE7;
    // 0x80780D5C: sb          $t3, 0x13B4($v1)
    MEM_B(0X13B4, ctx->r3) = ctx->r11;
    // 0x80780D60: sb          $t5, 0x13B4($v1)
    MEM_B(0X13B4, ctx->r3) = ctx->r13;
    // 0x80780D64: andi        $t6, $t5, 0xF9
    ctx->r14 = ctx->r13 & 0XF9;
    // 0x80780D68: andi        $t2, $t1, 0xFFF8
    ctx->r10 = ctx->r9 & 0XFFF8;
    // 0x80780D6C: sb          $t2, 0x13B5($v1)
    MEM_B(0X13B5, ctx->r3) = ctx->r10;
    // 0x80780D70: sb          $t6, 0x13B4($v1)
    MEM_B(0X13B4, ctx->r3) = ctx->r14;
    // 0x80780D74: andi        $t9, $t7, 0xFFCF
    ctx->r25 = ctx->r15 & 0XFFCF;
    // 0x80780D78: lhu         $t7, 0x13B4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X13B4);
    // 0x80780D7C: sb          $t9, 0x13B3($v1)
    MEM_B(0X13B3, ctx->r3) = ctx->r25;
    // 0x80780D80: andi        $t0, $t9, 0x3F
    ctx->r8 = ctx->r25 & 0X3F;
    // 0x80780D84: andi        $t8, $t7, 0xFE7F
    ctx->r24 = ctx->r15 & 0XFE7F;
    // 0x80780D88: sh          $t8, 0x13B4($v1)
    MEM_H(0X13B4, ctx->r3) = ctx->r24;
    // 0x80780D8C: lbu         $t9, 0x13B5($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X13B5);
    // 0x80780D90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80780D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80780D98: andi        $t1, $t9, 0xFF9F
    ctx->r9 = ctx->r25 & 0XFF9F;
    // 0x80780D9C: sb          $t1, 0x13B5($v1)
    MEM_B(0X13B5, ctx->r3) = ctx->r9;
    // 0x80780DA0: andi        $t2, $t1, 0xE7
    ctx->r10 = ctx->r9 & 0XE7;
    // 0x80780DA4: sb          $t4, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r12;
    // 0x80780DA8: sb          $t0, 0x13B3($v1)
    MEM_B(0X13B3, ctx->r3) = ctx->r8;
    // 0x80780DAC: jal         0x8006988C
    // 0x80780DB0: sb          $t2, 0x13B5($v1)
    MEM_B(0X13B5, ctx->r3) = ctx->r10;
    func_8006988C(rdram, ctx);
        goto after_0;
    // 0x80780DB0: sb          $t2, 0x13B5($v1)
    MEM_B(0X13B5, ctx->r3) = ctx->r10;
    after_0:
    // 0x80780DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80780DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80780DBC: jr          $ra
    // 0x80780DC0: nop

    return;
    // 0x80780DC0: nop

;}
RECOMP_FUNC void func_805A647C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A647C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A6480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A6484: lw          $a1, 0x268($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X268);
    // 0x805A6488: beql        $a1, $zero, L_805A649C
    if (ctx->r5 == 0) {
        // 0x805A648C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A649C;
    }
    goto skip_0;
    // 0x805A648C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805A6490: jal         0x800568E0
    // 0x805A6494: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800568E0(rdram, ctx);
        goto after_0;
    // 0x805A6494: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x805A6498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A649C:
    // 0x805A649C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A64A0: jr          $ra
    // 0x805A64A4: nop

    return;
    // 0x805A64A4: nop

;}
RECOMP_FUNC void func_806E5BF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E5BF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E5BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E5C00: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806E5C04: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(652, 0X90) << 16);
    // 0x806E5C08: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806E5C0C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806E5C10: addiu       $t6, $t6, 0x5C70
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(652, 0X90));
    // 0x806E5C14: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806E5C18: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806E5C1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E5C20: jal         0x806E5C38
    // 0x806E5C24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_806E5C38(rdram, ctx);
        goto after_0;
    // 0x806E5C24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x806E5C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E5C2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E5C30: jr          $ra
    // 0x806E5C34: nop

    return;
    // 0x806E5C34: nop

;}
RECOMP_FUNC void func_804BAC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BAC7C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804BAC80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BAC84: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804BAC88: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804BAC8C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(188, 0XC38) << 16);
    // 0x804BAC90: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804BAC94: lwc1        $f16, -0x4868($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(188, 0XC38));
    // 0x804BAC98: lwc1        $f18, 0x78($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X78);
    // 0x804BAC9C: lwc1        $f6, 0x7C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x804BACA0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x804BACA4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804BACA8: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x804BACAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804BACB0: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(188, 0XC3C) << 16);
    // 0x804BACB4: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x804BACB8: sub.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x804BACBC: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x804BACC0: nop

    // 0x804BACC4: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x804BACC8: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x804BACCC: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x804BACD0: lwc1        $f18, -0x4864($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(188, 0XC3C));
    // 0x804BACD4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(188, 0XC40) << 16);
    // 0x804BACD8: lwc1        $f6, -0x4860($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(188, 0XC40));
    // 0x804BACDC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804BACE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804BACE4: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804BACE8: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    // 0x804BACEC: jr          $ra
    // 0x804BACF0: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    return;
    // 0x804BACF0: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8044BB6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BB6C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8044BB70: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8044BB74: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8044BB78: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8044BB7C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8044BB80: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8044BB84: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8044BB88: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8044BB8C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8044BB90: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8044BB94: lwc1        $f18, 0x14($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8044BB98: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8044BB9C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8044BBA0: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8044BBA4: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8044BBA8: jr          $ra
    // 0x8044BBAC: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    return;
    // 0x8044BBAC: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_80670418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80670418: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067041C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80670420: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80670424: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80670428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067042C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80670430: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80670434: beql        $t6, $zero, L_806704AC
    if (ctx->r14 == 0) {
        // 0x80670438: lw          $v0, 0xC($v1)
        ctx->r2 = MEM_W(ctx->r3, 0XC);
            goto L_806704AC;
    }
    goto skip_0;
    // 0x80670438: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    skip_0:
    // 0x8067043C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80670440: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80670444: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x80670448: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8067044C: nop

    // 0x80670450: bc1fl       L_80670468
    if (!c1cs) {
        // 0x80670454: lw          $t7, 0x138($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X138);
            goto L_80670468;
    }
    goto skip_1;
    // 0x80670454: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    skip_1:
    // 0x80670458: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8067045C: nop

    // 0x80670460: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
    // 0x80670464: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
L_80670468:
    // 0x80670468: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8067046C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80670470: bnel        $t7, $zero, L_8067048C
    if (ctx->r15 != 0) {
        // 0x80670474: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_8067048C;
    }
    goto skip_2;
    // 0x80670474: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_2:
    // 0x80670478: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8067047C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80670480: b           L_80670494
    // 0x80670484: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_80670494;
    // 0x80670484: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80670488: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_8067048C:
    // 0x8067048C: nop

    // 0x80670490: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_80670494:
    // 0x80670494: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80670498: jal         0x8067087C
    // 0x8067049C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8067087C(rdram, ctx);
        goto after_0;
    // 0x8067049C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806704A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806704A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806704A8: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
L_806704AC:
    // 0x806704AC: beq         $v0, $zero, L_806704BC
    if (ctx->r2 == 0) {
        // 0x806704B0: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_806704BC;
    }
    // 0x806704B0: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x806704B4: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x806704B8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_806704BC:
    // 0x806704BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x806704C0: bnel        $v1, $v0, L_806704DC
    if (ctx->r3 != ctx->r2) {
        // 0x806704C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806704DC;
    }
    goto skip_3;
    // 0x806704C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x806704C8: lw          $t9, 0x174($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X174);
    // 0x806704CC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806704D0: jal         0x8005FCA8
    // 0x806704D4: sh          $v1, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r3;
    func_8005FCA8(rdram, ctx);
        goto after_1;
    // 0x806704D4: sh          $v1, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r3;
    after_1:
    // 0x806704D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806704DC:
    // 0x806704DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806704E0: jr          $ra
    // 0x806704E4: nop

    return;
    // 0x806704E4: nop

;}
RECOMP_FUNC void func_8001A330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A330: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001A334: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001A338: sw          $zero, 0x590($at)
    MEM_W(0X590, ctx->r1) = 0;
    // 0x8001A33C: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // 0x8001A340: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A344: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8001A348: addiu       $a0, $zero, 0x90
    ctx->r4 = ADD32(0, 0X90);
L_8001A34C:
    // 0x8001A34C: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A350: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A354: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8001A358: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8001A35C: mflo        $t6
    ctx->r14 = lo;
    // 0x8001A360: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8001A364: bne         $at, $zero, L_8001A34C
    if (ctx->r1 != 0) {
        // 0x8001A368: sw          $a1, 0x84($t7)
        MEM_W(0X84, ctx->r15) = ctx->r5;
            goto L_8001A34C;
    }
    // 0x8001A368: sw          $a1, 0x84($t7)
    MEM_W(0X84, ctx->r15) = ctx->r5;
    // 0x8001A36C: jr          $ra
    // 0x8001A370: nop

    return;
    // 0x8001A370: nop

;}
RECOMP_FUNC void func_80031B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031B38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031B3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031B40: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031B44: sw          $zero, 0xC0($a1)
    MEM_W(0XC0, ctx->r5) = 0;
    // 0x80031B48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80031B4C: jal         0x800310A0
    // 0x80031B50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x80031B50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80031B54: jal         0x80021A44
    // 0x80031B58: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80021A44(rdram, ctx);
        goto after_1;
    // 0x80031B58: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80031B5C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80031B60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80031B64: lw          $v0, 0x1C8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1C8);
    // 0x80031B68: bne         $v0, $zero, L_80031BB0
    if (ctx->r2 != 0) {
        // 0x80031B6C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80031BB0;
    }
    // 0x80031B6C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80031B70: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
    // 0x80031B74: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80031B78: beq         $v0, $at, L_80031B90
    if (ctx->r2 == ctx->r1) {
        // 0x80031B7C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80031B90;
    }
    // 0x80031B7C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80031B80: beq         $v0, $at, L_80031BA0
    if (ctx->r2 == ctx->r1) {
        // 0x80031B84: nop
    
            goto L_80031BA0;
    }
    // 0x80031B84: nop

    // 0x80031B88: b           L_80031BBC
    // 0x80031B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80031BBC;
    // 0x80031B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031B90:
    // 0x80031B90: jal         0x8002BCA4
    // 0x80031B94: nop

    func_8002BCA4(rdram, ctx);
        goto after_2;
    // 0x80031B94: nop

    after_2:
    // 0x80031B98: b           L_80031BBC
    // 0x80031B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80031BBC;
    // 0x80031B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031BA0:
    // 0x80031BA0: jal         0x8002BE1C
    // 0x80031BA4: nop

    func_8002BE1C(rdram, ctx);
        goto after_3;
    // 0x80031BA4: nop

    after_3:
    // 0x80031BA8: b           L_80031BBC
    // 0x80031BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80031BBC;
    // 0x80031BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031BB0:
    // 0x80031BB0: jal         0x800310D0
    // 0x80031BB4: sw          $t6, 0x1C8($a1)
    MEM_W(0X1C8, ctx->r5) = ctx->r14;
    func_800310D0(rdram, ctx);
        goto after_4;
    // 0x80031BB4: sw          $t6, 0x1C8($a1)
    MEM_W(0X1C8, ctx->r5) = ctx->r14;
    after_4:
    // 0x80031BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031BBC:
    // 0x80031BBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80031BC0: jr          $ra
    // 0x80031BC4: nop

    return;
    // 0x80031BC4: nop

;}
RECOMP_FUNC void func_8005FD1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FD1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FD20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FD24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005FD28: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x8005FD2C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8005FD30: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8005FD34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FD38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005FD3C: lbu         $t7, 0x76($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X76);
    // 0x8005FD40: beql        $t7, $zero, L_8005FD64
    if (ctx->r15 == 0) {
        // 0x8005FD44: lbu         $t9, 0x77($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X77);
            goto L_8005FD64;
    }
    goto skip_0;
    // 0x8005FD44: lbu         $t9, 0x77($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X77);
    skip_0:
    // 0x8005FD48: jal         0x8005F9F4
    // 0x8005FD4C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8005F9F4(rdram, ctx);
        goto after_0;
    // 0x8005FD4C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8005FD50: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FD54: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8005FD58: sb          $zero, 0x76($t8)
    MEM_B(0X76, ctx->r24) = 0;
    // 0x8005FD5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FD60: lbu         $t9, 0x77($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X77);
L_8005FD64:
    // 0x8005FD64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005FD68: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8005FD6C: beql        $t9, $zero, L_8005FD90
    if (ctx->r25 == 0) {
        // 0x8005FD70: lbu         $t1, 0x79($v0)
        ctx->r9 = MEM_BU(ctx->r2, 0X79);
            goto L_8005FD90;
    }
    goto skip_1;
    // 0x8005FD70: lbu         $t1, 0x79($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X79);
    skip_1:
    // 0x8005FD74: jal         0x8005F9F4
    // 0x8005FD78: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8005F9F4(rdram, ctx);
        goto after_1;
    // 0x8005FD78: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8005FD7C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FD80: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8005FD84: sb          $zero, 0x77($t0)
    MEM_B(0X77, ctx->r8) = 0;
    // 0x8005FD88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FD8C: lbu         $t1, 0x79($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X79);
L_8005FD90:
    // 0x8005FD90: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8005FD94: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8005FD98: beql        $t1, $zero, L_8005FDB8
    if (ctx->r9 == 0) {
        // 0x8005FD9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FDB8;
    }
    goto skip_2;
    // 0x8005FD9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8005FDA0: jal         0x8005F9F4
    // 0x8005FDA4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8005F9F4(rdram, ctx);
        goto after_2;
    // 0x8005FDA4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8005FDA8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FDAC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8005FDB0: sb          $zero, 0x79($t2)
    MEM_B(0X79, ctx->r10) = 0;
    // 0x8005FDB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FDB8:
    // 0x8005FDB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005FDBC: jr          $ra
    // 0x8005FDC0: nop

    return;
    // 0x8005FDC0: nop

;}
RECOMP_FUNC void func_80563860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80563860: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80563864: addiu       $at, $zero, 0x413D
    ctx->r1 = ADD32(0, 0X413D);
    // 0x80563868: beq         $v0, $at, L_80563874
    if (ctx->r2 == ctx->r1) {
        // 0x8056386C: addiu       $at, $zero, 0x4552
        ctx->r1 = ADD32(0, 0X4552);
            goto L_80563874;
    }
    // 0x8056386C: addiu       $at, $zero, 0x4552
    ctx->r1 = ADD32(0, 0X4552);
    // 0x80563870: bne         $v0, $at, L_80563880
    if (ctx->r2 != ctx->r1) {
        // 0x80563874: lui         $v0, 0x8056
        ctx->r2 = S32(RELOC_HI16(369, 0X222C) << 16);
            goto L_80563880;
    }
L_80563874:
    // 0x80563874: lui         $v0, 0x8056
    ctx->r2 = S32(RELOC_HI16(369, 0X222C) << 16);
    // 0x80563878: jr          $ra
    // 0x8056387C: addiu       $v0, $v0, 0x5A8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(369, 0X222C));
    return;
    // 0x8056387C: addiu       $v0, $v0, 0x5A8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(369, 0X222C));
L_80563880:
    // 0x80563880: lui         $v0, 0x8056
    ctx->r2 = S32(RELOC_HI16(369, 0X222C) << 16);
    // 0x80563884: addiu       $v0, $v0, 0x5A8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(369, 0X222C));
    // 0x80563888: jr          $ra
    // 0x8056388C: nop

    return;
    // 0x8056388C: nop

;}
RECOMP_FUNC void func_80049F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049F68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80049F6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049F70: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80049F74: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80049F78: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80049F7C: jal         0x80047AB8
    // 0x80049F80: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x80049F80: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80049F84: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80049F88: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80049F8C: jal         0x80049E7C
    // 0x80049F90: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_80049E7C(rdram, ctx);
        goto after_1;
    // 0x80049F90: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80049F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049F98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80049F9C: jr          $ra
    // 0x80049FA0: nop

    return;
    // 0x80049FA0: nop

;}
RECOMP_FUNC void func_807AB34C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AB34C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807AB350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AB354: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807AB358: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x807AB35C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x807AB360: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x807AB364: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x807AB368: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x807AB36C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x807AB370: bnel        $t6, $at, L_807AB3D8
    if (ctx->r14 != ctx->r1) {
        // 0x807AB374: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807AB3D8;
    }
    goto skip_0;
    // 0x807AB374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807AB378: lw          $t9, 0x180($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X180);
    // 0x807AB37C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807AB380: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C40) << 16);
    // 0x807AB384: lw          $t0, 0x1F4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1F4);
    // 0x807AB388: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x807AB38C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x807AB390: sw          $t7, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->r15;
    // 0x807AB394: lwc1        $f4, 0x3C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x807AB398: lwc1        $f8, -0x4780($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C40));
    // 0x807AB39C: lw          $t1, -0x76F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76F8);
    // 0x807AB3A0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x807AB3A4: lwc1        $f6, 0x40($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X40);
    // 0x807AB3A8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x807AB3AC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x807AB3B0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x807AB3B4: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x807AB3B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807AB3BC: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x807AB3C0: lw          $t9, 0x18($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X18);
    // 0x807AB3C4: jalr        $t9
    // 0x807AB3C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x807AB3C8: nop

    after_0:
    // 0x807AB3CC: jal         0x800447C8
    // 0x807AB3D0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x807AB3D0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x807AB3D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807AB3D8:
    // 0x807AB3D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807AB3DC: jr          $ra
    // 0x807AB3E0: nop

    return;
    // 0x807AB3E0: nop

;}
RECOMP_FUNC void func_80580A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580A74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580A7C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80580A80: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80580A84: lui         $t8, 0x8058
    ctx->r24 = S32(RELOC_HI16(399, 0X4608) << 16);
    // 0x80580A88: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80580A8C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80580A90: lw          $t8, 0x3418($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(399, 0X4608));
    // 0x80580A94: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80580A98: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80580A9C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80580AA0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80580AA4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80580AA8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80580AAC: beql        $v1, $zero, L_80580AE0
    if (ctx->r3 == 0) {
        // 0x80580AB0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80580AE0;
    }
    goto skip_0;
    // 0x80580AB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80580AB4: jalr        $v1
    // 0x80580AB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80580AB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80580ABC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80580AC0: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80580AC4: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80580AC8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80580ACC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80580AD0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80580AD4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80580AD8: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80580ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80580AE0:
    // 0x80580AE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80580AE4: jr          $ra
    // 0x80580AE8: nop

    return;
    // 0x80580AE8: nop

;}
RECOMP_FUNC void func_806D3E1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D3E1C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x806D3E20: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x806D3E24: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(616, 0X3644) << 16);
    // 0x806D3E28: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x806D3E2C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x806D3E30: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x806D3E34: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x806D3E38: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x806D3E3C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x806D3E40: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806D3E44: lwc1        $f24, 0x65F4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(616, 0X3644));
    // 0x806D3E48: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x806D3E4C: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x806D3E50: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x806D3E54: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x806D3E58: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x806D3E5C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x806D3E60: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(616, 0X3648) << 16);
    // 0x806D3E64: lui         $s6, 0x45AD
    ctx->r22 = S32(0X45AD << 16);
    // 0x806D3E68: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x806D3E6C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x806D3E70: lw          $fp, 0x1F4($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D3E74: ori         $s6, $s6, 0x2000
    ctx->r22 = ctx->r22 | 0X2000;
    // 0x806D3E78: lwc1        $f22, 0x65F8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(616, 0X3648));
    // 0x806D3E7C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x806D3E80: addiu       $s5, $zero, 0x3FF
    ctx->r21 = ADD32(0, 0X3FF);
    // 0x806D3E84: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
L_806D3E88:
    // 0x806D3E88: jal         0x80047090
    // 0x806D3E8C: addiu       $a0, $zero, 0x45AD
    ctx->r4 = ADD32(0, 0X45AD);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806D3E8C: addiu       $a0, $zero, 0x45AD
    ctx->r4 = ADD32(0, 0X45AD);
    after_0:
    // 0x806D3E90: bne         $s5, $v0, L_806D3EA0
    if (ctx->r21 != ctx->r2) {
        // 0x806D3E94: andi        $s3, $v0, 0xFFFF
        ctx->r19 = ctx->r2 & 0XFFFF;
            goto L_806D3EA0;
    }
    // 0x806D3E94: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x806D3E98: b           L_806D3F2C
    // 0x806D3E9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806D3F2C;
    // 0x806D3E9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D3EA0:
    // 0x806D3EA0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x806D3EA4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x806D3EA8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x806D3EAC: jal         0x8004613C
    // 0x806D3EB0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806D3EB0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x806D3EB4: beq         $v0, $zero, L_806D3F0C
    if (ctx->r2 == 0) {
        // 0x806D3EB8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806D3F0C;
    }
    // 0x806D3EB8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806D3EBC: lhu         $t8, 0xE($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XE);
    // 0x806D3EC0: andi        $t7, $s3, 0x3FF
    ctx->r15 = ctx->r19 & 0X3FF;
    // 0x806D3EC4: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x806D3EC8: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x806D3ECC: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x806D3ED0: sh          $t0, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r8;
    // 0x806D3ED4: addu        $s1, $fp, $t1
    ctx->r17 = ADD32(ctx->r30, ctx->r9);
    // 0x806D3ED8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x806D3EDC: jal         0x80047F9C
    // 0x806D3EE0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806D3EE0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x806D3EE4: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x806D3EE8: jal         0x806D3DCC
    // 0x806D3EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D3DCC(rdram, ctx);
        goto after_3;
    // 0x806D3EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806D3EF0: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x806D3EF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x806D3EF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806D3EFC: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x806D3F00: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x806D3F04: b           L_806D3F14
    // 0x806D3F08: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
        goto L_806D3F14;
    // 0x806D3F08: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_806D3F0C:
    // 0x806D3F0C: b           L_806D3F2C
    // 0x806D3F10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806D3F2C;
    // 0x806D3F10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D3F14:
    // 0x806D3F14: bne         $s2, $s7, L_806D3E88
    if (ctx->r18 != ctx->r23) {
        // 0x806D3F18: sw          $s0, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->r16;
            goto L_806D3E88;
    }
    // 0x806D3F18: sw          $s0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r16;
    // 0x806D3F1C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x806D3F20: sw          $zero, 0x28($fp)
    MEM_W(0X28, ctx->r30) = 0;
    // 0x806D3F24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806D3F28: sw          $t2, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r10;
L_806D3F2C:
    // 0x806D3F2C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x806D3F30: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806D3F34: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x806D3F38: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x806D3F3C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x806D3F40: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x806D3F44: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x806D3F48: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x806D3F4C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x806D3F50: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x806D3F54: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x806D3F58: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x806D3F5C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x806D3F60: jr          $ra
    // 0x806D3F64: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x806D3F64: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_806E9800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E9800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E9804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E9808: jal         0x806E9760
    // 0x806E980C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806E9760(rdram, ctx);
        goto after_0;
    // 0x806E980C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806E9810: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806E9814: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E9818: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806E981C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E9820: beql        $t6, $zero, L_806E984C
    if (ctx->r14 == 0) {
        // 0x806E9824: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E984C;
    }
    goto skip_0;
    // 0x806E9824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E9828: jal         0x806E98B8
    // 0x806E982C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806E98B8(rdram, ctx);
        goto after_1;
    // 0x806E982C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x806E9830: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806E9834: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(667, 0X508) << 16);
    // 0x806E9838: addiu       $t7, $t7, -0x7848
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(667, 0X508));
    // 0x806E983C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806E9840: jal         0x806E9748
    // 0x806E9844: sw          $t7, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r15;
    func_806E9748(rdram, ctx);
        goto after_2;
    // 0x806E9844: sw          $t7, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r15;
    after_2:
    // 0x806E9848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E984C:
    // 0x806E984C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E9850: jr          $ra
    // 0x806E9854: nop

    return;
    // 0x806E9854: nop

;}
RECOMP_FUNC void func_8073C7E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073C7E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073C7E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073C7EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073C7F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8073C7F4: jal         0x80045A34
    // 0x8073C7F8: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8073C7F8: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    after_0:
    // 0x8073C7FC: bne         $v0, $zero, L_8073C814
    if (ctx->r2 != 0) {
        // 0x8073C800: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_8073C814;
    }
    // 0x8073C800: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8073C804: jal         0x800445A4
    // 0x8073C808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8073C808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8073C80C: b           L_8073C978
    // 0x8073C810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8073C978;
    // 0x8073C810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073C814:
    // 0x8073C814: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x8073C818: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(742, 0XF60) << 16);
    // 0x8073C81C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8073C820: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8073C824: addiu       $t6, $t6, -0x2F40
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(742, 0XF60));
    // 0x8073C828: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8073C82C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8073C830: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8073C834: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x8073C838: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8073C83C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8073C840: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8073C844: sw          $t8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r24;
    // 0x8073C848: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x8073C84C: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    // 0x8073C850: sw          $zero, 0x14($t2)
    MEM_W(0X14, ctx->r10) = 0;
    // 0x8073C854: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x8073C858: sw          $zero, 0xC($t2)
    MEM_W(0XC, ctx->r10) = 0;
    // 0x8073C85C: sw          $zero, 0x10($t2)
    MEM_W(0X10, ctx->r10) = 0;
    // 0x8073C860: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8073C864: addiu       $v1, $t2, 0x20
    ctx->r3 = ADD32(ctx->r10, 0X20);
    // 0x8073C868: addiu       $a1, $t2, 0x30
    ctx->r5 = ADD32(ctx->r10, 0X30);
    // 0x8073C86C: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x8073C870: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8073C874: addiu       $a3, $t2, 0x40
    ctx->r7 = ADD32(ctx->r10, 0X40);
    // 0x8073C878: addiu       $t1, $t2, 0x50
    ctx->r9 = ADD32(ctx->r10, 0X50);
    // 0x8073C87C: swc1        $f8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f8.u32l;
    // 0x8073C880: lui         $t2, 0x8074
    ctx->r10 = S32(RELOC_HI16(742, 0XE38) << 16);
    // 0x8073C884: lui         $a0, 0x8074
    ctx->r4 = S32(RELOC_HI16(742, 0XD48) << 16);
    // 0x8073C888: lui         $a2, 0x8074
    ctx->r6 = S32(RELOC_HI16(742, 0XD58) << 16);
    // 0x8073C88C: lui         $t0, 0x8074
    ctx->r8 = S32(RELOC_HI16(742, 0XD68) << 16);
    // 0x8073C890: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(742, 0XD78) << 16);
    // 0x8073C894: addiu       $v0, $v0, -0x3128
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(742, 0XD78));
    // 0x8073C898: addiu       $t0, $t0, -0x3138
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(742, 0XD68));
    // 0x8073C89C: addiu       $a2, $a2, -0x3148
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(742, 0XD58));
    // 0x8073C8A0: addiu       $a0, $a0, -0x3158
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(742, 0XD48));
    // 0x8073C8A4: addiu       $t2, $t2, -0x3068
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(742, 0XE38));
L_8073C8A8:
    // 0x8073C8A8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8073C8AC: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8073C8B0: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x8073C8B4: sw          $t6, -0x40($v1)
    MEM_W(-0X40, ctx->r3) = ctx->r14;
    // 0x8073C8B8: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8073C8BC: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x8073C8C0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x8073C8C4: sw          $t5, -0x3C($v1)
    MEM_W(-0X3C, ctx->r3) = ctx->r13;
    // 0x8073C8C8: lw          $t6, -0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, -0X38);
    // 0x8073C8CC: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    // 0x8073C8D0: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x8073C8D4: sw          $t6, -0x38($v1)
    MEM_W(-0X38, ctx->r3) = ctx->r14;
    // 0x8073C8D8: lw          $t5, -0x34($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X34);
    // 0x8073C8DC: addiu       $t0, $t0, 0x40
    ctx->r8 = ADD32(ctx->r8, 0X40);
    // 0x8073C8E0: addiu       $t1, $t1, 0x40
    ctx->r9 = ADD32(ctx->r9, 0X40);
    // 0x8073C8E4: sw          $t5, -0x34($v1)
    MEM_W(-0X34, ctx->r3) = ctx->r13;
    // 0x8073C8E8: lw          $t8, -0x40($a2)
    ctx->r24 = MEM_W(ctx->r6, -0X40);
    // 0x8073C8EC: sw          $t8, -0x40($a1)
    MEM_W(-0X40, ctx->r5) = ctx->r24;
    // 0x8073C8F0: lw          $t7, -0x3C($a2)
    ctx->r15 = MEM_W(ctx->r6, -0X3C);
    // 0x8073C8F4: sw          $t7, -0x3C($a1)
    MEM_W(-0X3C, ctx->r5) = ctx->r15;
    // 0x8073C8F8: lw          $t8, -0x38($a2)
    ctx->r24 = MEM_W(ctx->r6, -0X38);
    // 0x8073C8FC: sw          $t8, -0x38($a1)
    MEM_W(-0X38, ctx->r5) = ctx->r24;
    // 0x8073C900: lw          $t7, -0x34($a2)
    ctx->r15 = MEM_W(ctx->r6, -0X34);
    // 0x8073C904: sw          $t7, -0x34($a1)
    MEM_W(-0X34, ctx->r5) = ctx->r15;
    // 0x8073C908: lw          $t5, -0x40($t0)
    ctx->r13 = MEM_W(ctx->r8, -0X40);
    // 0x8073C90C: sw          $t5, -0x40($a3)
    MEM_W(-0X40, ctx->r7) = ctx->r13;
    // 0x8073C910: lw          $t9, -0x3C($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X3C);
    // 0x8073C914: sw          $t9, -0x3C($a3)
    MEM_W(-0X3C, ctx->r7) = ctx->r25;
    // 0x8073C918: lw          $t5, -0x38($t0)
    ctx->r13 = MEM_W(ctx->r8, -0X38);
    // 0x8073C91C: sw          $t5, -0x38($a3)
    MEM_W(-0X38, ctx->r7) = ctx->r13;
    // 0x8073C920: lw          $t9, -0x34($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X34);
    // 0x8073C924: sw          $t9, -0x34($a3)
    MEM_W(-0X34, ctx->r7) = ctx->r25;
    // 0x8073C928: lw          $t7, -0x40($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X40);
    // 0x8073C92C: sw          $t7, -0x40($t1)
    MEM_W(-0X40, ctx->r9) = ctx->r15;
    // 0x8073C930: lw          $t6, -0x3C($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X3C);
    // 0x8073C934: sw          $t6, -0x3C($t1)
    MEM_W(-0X3C, ctx->r9) = ctx->r14;
    // 0x8073C938: lw          $t7, -0x38($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X38);
    // 0x8073C93C: sw          $t7, -0x38($t1)
    MEM_W(-0X38, ctx->r9) = ctx->r15;
    // 0x8073C940: lw          $t6, -0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X34);
    // 0x8073C944: bne         $v0, $t2, L_8073C8A8
    if (ctx->r2 != ctx->r10) {
        // 0x8073C948: sw          $t6, -0x34($t1)
        MEM_W(-0X34, ctx->r9) = ctx->r14;
            goto L_8073C8A8;
    }
    // 0x8073C948: sw          $t6, -0x34($t1)
    MEM_W(-0X34, ctx->r9) = ctx->r14;
    // 0x8073C94C: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x8073C950: lui         $t8, 0x8074
    ctx->r24 = S32(RELOC_HI16(742, 0X10) << 16);
    // 0x8073C954: addiu       $t8, $t8, -0x3E90
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(742, 0X10));
    // 0x8073C958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073C95C: jal         0x8073C6C8
    // 0x8073C960: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    func_8073C6C8(rdram, ctx);
        goto after_2;
    // 0x8073C960: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    after_2:
    // 0x8073C964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073C968: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073C96C: jal         0x8073C988
    // 0x8073C970: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8073C988(rdram, ctx);
        goto after_3;
    // 0x8073C970: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8073C974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073C978:
    // 0x8073C978: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073C97C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073C980: jr          $ra
    // 0x8073C984: nop

    return;
    // 0x8073C984: nop

;}
RECOMP_FUNC void func_80444890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80444890: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80444894: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80444898: sb          $zero, 0xF6D($v0)
    MEM_B(0XF6D, ctx->r2) = 0;
    // 0x8044489C: sb          $zero, 0xF6E($v0)
    MEM_B(0XF6E, ctx->r2) = 0;
    // 0x804448A0: sb          $zero, 0xF6F($v0)
    MEM_B(0XF6F, ctx->r2) = 0;
    // 0x804448A4: jr          $ra
    // 0x804448A8: sw          $zero, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = 0;
    return;
    // 0x804448A8: sw          $zero, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80401B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80401B90: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80401B94: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80401B98: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80401B9C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80401BA0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80401BA4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80401BA8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80401BAC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80401BB0: lui         $t1, 0x8040
    ctx->r9 = S32(RELOC_HI16(8, 0X762C) << 16);
    // 0x80401BB4: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80401BB8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80401BBC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80401BC0: lw          $t1, 0x766C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(8, 0X762C));
    // 0x80401BC4: jr          $ra
    // 0x80401BC8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80401BC8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x80401BCC: nop

;}
RECOMP_FUNC void func_80422BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80422BF4: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x80422BF8: bne         $t6, $zero, L_80422C14
    if (ctx->r14 != 0) {
        // 0x80422BFC: nop
    
            goto L_80422C14;
    }
    // 0x80422BFC: nop

    // 0x80422C00: lh          $t7, 0x144($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X144);
    // 0x80422C04: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80422C08: sw          $t1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r9;
    // 0x80422C0C: addu        $t0, $t7, $a1
    ctx->r8 = ADD32(ctx->r15, ctx->r5);
    // 0x80422C10: sh          $t0, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r8;
L_80422C14:
    // 0x80422C14: jr          $ra
    // 0x80422C18: nop

    return;
    // 0x80422C18: nop

;}
RECOMP_FUNC void func_807A0380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A0380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A0384: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x807A0388: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x807A038C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A0390: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x807A0394: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x807A0398: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x807A039C: lui         $t9, 0x807A
    ctx->r25 = S32(RELOC_HI16(838, 0X16BC) << 16);
    // 0x807A03A0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807A03A4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x807A03A8: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x807A03AC: lw          $t9, 0xD1C($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(838, 0X16BC));
    // 0x807A03B0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x807A03B4: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x807A03B8: jal         0x8079F6A4
    // 0x807A03BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8079F6A4(rdram, ctx);
        goto after_0;
    // 0x807A03BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807A03C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807A03C4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x807A03C8: lbu         $t0, 0x30($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X30);
    // 0x807A03CC: beql        $t0, $at, L_807A03E8
    if (ctx->r8 == ctx->r1) {
        // 0x807A03D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807A03E8;
    }
    goto skip_0;
    // 0x807A03D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807A03D4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A03D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x807A03DC: jal         0x8079F7D8
    // 0x807A03E0: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    func_8079F7D8(rdram, ctx);
        goto after_1;
    // 0x807A03E0: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    after_1:
    // 0x807A03E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A03E8:
    // 0x807A03E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A03EC: jr          $ra
    // 0x807A03F0: nop

    return;
    // 0x807A03F0: nop

    // 0x807A03F4: nop

    // 0x807A03F8: nop

    // 0x807A03FC: nop

;}
RECOMP_FUNC void func_807A6EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6EF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A6EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A6EF8: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x807A6EFC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A6F00: lui         $at, 0x435F
    ctx->r1 = S32(0X435F << 16);
    // 0x807A6F04: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x807A6F08: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x807A6F0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807A6F10: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807A6F14: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807A6F18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807A6F1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807A6F20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x807A6F24: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x807A6F28: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807A6F2C: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x807A6F30: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x807A6F34: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x807A6F38: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x807A6F3C: nop

    // 0x807A6F40: bc1fl       L_807A6F54
    if (!c1cs) {
        // 0x807A6F44: cfc1        $t6, $FpcCsr
        ctx->r14 = get_cop1_cs();
            goto L_807A6F54;
    }
    goto skip_0;
    // 0x807A6F44: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    skip_0:
    // 0x807A6F48: b           L_807A6FD4
    // 0x807A6F4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_807A6FD4;
    // 0x807A6F4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807A6F50: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_807A6F54:
    // 0x807A6F54: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x807A6F58: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x807A6F5C: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x807A6F60: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x807A6F64: nop

    // 0x807A6F68: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x807A6F6C: beql        $a2, $zero, L_807A6FBC
    if (ctx->r6 == 0) {
        // 0x807A6F70: mfc1        $a2, $f4
        ctx->r6 = (int32_t)ctx->f4.u32l;
            goto L_807A6FBC;
    }
    goto skip_1;
    // 0x807A6F70: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x807A6F74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807A6F78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807A6F7C: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x807A6F80: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x807A6F84: nop

    // 0x807A6F88: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x807A6F8C: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x807A6F90: nop

    // 0x807A6F94: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x807A6F98: bne         $a2, $zero, L_807A6FB0
    if (ctx->r6 != 0) {
        // 0x807A6F9C: nop
    
            goto L_807A6FB0;
    }
    // 0x807A6F9C: nop

    // 0x807A6FA0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x807A6FA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x807A6FA8: b           L_807A6FC8
    // 0x807A6FAC: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_807A6FC8;
    // 0x807A6FAC: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_807A6FB0:
    // 0x807A6FB0: b           L_807A6FC8
    // 0x807A6FB4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_807A6FC8;
    // 0x807A6FB4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x807A6FB8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
L_807A6FBC:
    // 0x807A6FBC: nop

    // 0x807A6FC0: bltz        $a2, L_807A6FB0
    if (SIGNED(ctx->r6) < 0) {
        // 0x807A6FC4: nop
    
            goto L_807A6FB0;
    }
    // 0x807A6FC4: nop

L_807A6FC8:
    // 0x807A6FC8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x807A6FCC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x807A6FD0: nop

L_807A6FD4:
    // 0x807A6FD4: slti        $at, $v1, 0x2C
    ctx->r1 = SIGNED(ctx->r3) < 0X2C ? 1 : 0;
    // 0x807A6FD8: beq         $at, $zero, L_807A7068
    if (ctx->r1 == 0) {
        // 0x807A6FDC: nop
    
            goto L_807A7068;
    }
    // 0x807A6FDC: nop

    // 0x807A6FE0: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
L_807A6FE4:
    // 0x807A6FE4: lw          $a0, 0x188($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X188);
    // 0x807A6FE8: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x807A6FEC: beql        $a0, $zero, L_807A7008
    if (ctx->r4 == 0) {
        // 0x807A6FF0: lw          $v1, 0x18C($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X18C);
            goto L_807A7008;
    }
    goto skip_2;
    // 0x807A6FF0: lw          $v1, 0x18C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X18C);
    skip_2:
    // 0x807A6FF4: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x807A6FF8: beql        $v0, $zero, L_807A7008
    if (ctx->r2 == 0) {
        // 0x807A6FFC: lw          $v1, 0x18C($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X18C);
            goto L_807A7008;
    }
    goto skip_3;
    // 0x807A6FFC: lw          $v1, 0x18C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X18C);
    skip_3:
    // 0x807A7000: sb          $a2, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r6;
    // 0x807A7004: lw          $v1, 0x18C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X18C);
L_807A7008:
    // 0x807A7008: beql        $v1, $zero, L_807A7024
    if (ctx->r3 == 0) {
        // 0x807A700C: lw          $v1, 0x190($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X190);
            goto L_807A7024;
    }
    goto skip_4;
    // 0x807A700C: lw          $v1, 0x190($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X190);
    skip_4:
    // 0x807A7010: lw          $v0, 0x16C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X16C);
    // 0x807A7014: beql        $v0, $zero, L_807A7024
    if (ctx->r2 == 0) {
        // 0x807A7018: lw          $v1, 0x190($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X190);
            goto L_807A7024;
    }
    goto skip_5;
    // 0x807A7018: lw          $v1, 0x190($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X190);
    skip_5:
    // 0x807A701C: sb          $a2, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r6;
    // 0x807A7020: lw          $v1, 0x190($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X190);
L_807A7024:
    // 0x807A7024: beql        $v1, $zero, L_807A7040
    if (ctx->r3 == 0) {
        // 0x807A7028: lw          $v1, 0x194($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X194);
            goto L_807A7040;
    }
    goto skip_6;
    // 0x807A7028: lw          $v1, 0x194($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X194);
    skip_6:
    // 0x807A702C: lw          $v0, 0x16C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X16C);
    // 0x807A7030: beql        $v0, $zero, L_807A7040
    if (ctx->r2 == 0) {
        // 0x807A7034: lw          $v1, 0x194($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X194);
            goto L_807A7040;
    }
    goto skip_7;
    // 0x807A7034: lw          $v1, 0x194($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X194);
    skip_7:
    // 0x807A7038: sb          $a2, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r6;
    // 0x807A703C: lw          $v1, 0x194($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X194);
L_807A7040:
    // 0x807A7040: beq         $v1, $zero, L_807A7058
    if (ctx->r3 == 0) {
        // 0x807A7044: nop
    
            goto L_807A7058;
    }
    // 0x807A7044: nop

    // 0x807A7048: lw          $v0, 0x16C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X16C);
    // 0x807A704C: beq         $v0, $zero, L_807A7058
    if (ctx->r2 == 0) {
        // 0x807A7050: nop
    
            goto L_807A7058;
    }
    // 0x807A7050: nop

    // 0x807A7054: sb          $a2, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r6;
L_807A7058:
    // 0x807A7058: bne         $a3, $t0, L_807A6FE4
    if (ctx->r7 != ctx->r8) {
        // 0x807A705C: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_807A6FE4;
    }
    // 0x807A705C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x807A7060: b           L_807A7074
    // 0x807A7064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807A7074;
    // 0x807A7064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A7068:
    // 0x807A7068: jal         0x800447C8
    // 0x807A706C: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x807A706C: nop

    after_0:
    // 0x807A7070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A7074:
    // 0x807A7074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A7078: jr          $ra
    // 0x807A707C: nop

    return;
    // 0x807A707C: nop

;}
RECOMP_FUNC void func_8040CFFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040CFFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040D000: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040D004: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040D008: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8040D00C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8040D010: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x8040D014: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8040D018: sw          $t6, -0x72E4($at)
    MEM_W(-0X72E4, ctx->r1) = ctx->r14;
    // 0x8040D01C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8040D020: jal         0x80067BBC
    // 0x8040D024: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8040D024: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x8040D028: jal         0x80067E68
    // 0x8040D02C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80067E68(rdram, ctx);
        goto after_1;
    // 0x8040D02C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_1:
    // 0x8040D030: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x8040D034: jal         0x80067818
    // 0x8040D038: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8040D038: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8040D03C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040D040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040D044: jr          $ra
    // 0x8040D048: nop

    return;
    // 0x8040D048: nop

;}
RECOMP_FUNC void func_8064C3A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C3A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C3A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C3A8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8064C3AC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8064C3B0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8064C3B4: lui         $t8, 0x8065
    ctx->r24 = S32(RELOC_HI16(495, 0X33C0) << 16);
    // 0x8064C3B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8064C3BC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8064C3C0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8064C3C4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8064C3C8: lw          $t8, -0x2B70($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(495, 0X33C0));
    // 0x8064C3CC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8064C3D0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8064C3D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064C3D8: jal         0x80048490
    // 0x8064C3DC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8064C3DC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8064C3E0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8064C3E4: jal         0x80048378
    // 0x8064C3E8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8064C3E8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8064C3EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064C3F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C3F4: jr          $ra
    // 0x8064C3F8: nop

    return;
    // 0x8064C3F8: nop

;}
RECOMP_FUNC void func_80041914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041914: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80041918: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004191C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80041920: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80041924: lhu         $t7, 0x8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X8);
    // 0x80041928: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8004192C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80041930: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80041934: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80041938: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004193C: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80041940: lw          $v1, 0x11FC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X11FC);
    // 0x80041944: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80041948: lw          $t1, 0x174($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X174);
    // 0x8004194C: sh          $a1, 0x1200($v0)
    MEM_H(0X1200, ctx->r2) = ctx->r5;
    // 0x80041950: lhu         $t9, 0xC($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0XC);
    // 0x80041954: lbu         $t2, 0xF($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XF);
    // 0x80041958: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8004195C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80041960: beq         $t2, $zero, L_80041970
    if (ctx->r10 == 0) {
        // 0x80041964: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_80041970;
    }
    // 0x80041964: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80041968: b           L_80041974
    // 0x8004196C: lwc1        $f0, 0x7C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X7C);
        goto L_80041974;
    // 0x8004196C: lwc1        $f0, 0x7C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X7C);
L_80041970:
    // 0x80041970: lwc1        $f0, 0x70($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X70);
L_80041974:
    // 0x80041974: beql        $t1, $zero, L_800419AC
    if (ctx->r9 == 0) {
        // 0x80041978: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_800419AC;
    }
    goto skip_0;
    // 0x80041978: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x8004197C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80041980: lbu         $t3, 0x74($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X74);
    // 0x80041984: beql        $t3, $zero, L_800419AC
    if (ctx->r11 == 0) {
        // 0x80041988: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_800419AC;
    }
    goto skip_1;
    // 0x80041988: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x8004198C: lh          $t4, 0xC($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XC);
    // 0x80041990: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80041994: nop

    // 0x80041998: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004199C: mul.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800419A0: b           L_800419BC
    // 0x800419A4: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
        goto L_800419BC;
    // 0x800419A4: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800419A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_800419AC:
    // 0x800419AC: nop

    // 0x800419B0: mul.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800419B4: nop

    // 0x800419B8: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
L_800419BC:
    // 0x800419BC: sll         $t0, $a1, 4
    ctx->r8 = S32(ctx->r5 << 4);
    // 0x800419C0: addu        $v0, $t5, $t0
    ctx->r2 = ADD32(ctx->r13, ctx->r8);
    // 0x800419C4: lbu         $t7, 0x209($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X209);
    // 0x800419C8: srl         $t6, $t7, 4
    ctx->r14 = S32(U32(ctx->r15) >> 4);
    // 0x800419CC: beql        $t6, $zero, L_80041A74
    if (ctx->r14 == 0) {
        // 0x800419D0: sw          $zero, 0x8($t1)
        MEM_W(0X8, ctx->r9) = 0;
            goto L_80041A74;
    }
    goto skip_2;
    // 0x800419D0: sw          $zero, 0x8($t1)
    MEM_W(0X8, ctx->r9) = 0;
    skip_2:
    // 0x800419D4: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
    // 0x800419D8: addiu       $at, $zero, 0x401F
    ctx->r1 = ADD32(0, 0X401F);
    // 0x800419DC: beql        $t8, $at, L_800419F0
    if (ctx->r24 == ctx->r1) {
        // 0x800419E0: lw          $t9, 0x8($t1)
        ctx->r25 = MEM_W(ctx->r9, 0X8);
            goto L_800419F0;
    }
    goto skip_3;
    // 0x800419E0: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    skip_3:
    // 0x800419E4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800419E8: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800419EC: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
L_800419F0:
    // 0x800419F0: bnel        $t9, $zero, L_80041A68
    if (ctx->r25 != 0) {
        // 0x800419F4: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80041A68;
    }
    goto skip_4;
    // 0x800419F4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_4:
    // 0x800419F8: lhu         $t2, 0x208($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X208);
    // 0x800419FC: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x80041A00: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x80041A04: sb          $t7, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r15;
    // 0x80041A08: lbu         $t8, 0x209($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X209);
    // 0x80041A0C: andi        $t6, $t7, 0xF
    ctx->r14 = ctx->r15 & 0XF;
    // 0x80041A10: andi        $t9, $t8, 0xFFF0
    ctx->r25 = ctx->r24 & 0XFFF0;
    // 0x80041A14: or          $t2, $t6, $t9
    ctx->r10 = ctx->r14 | ctx->r25;
    // 0x80041A18: sb          $t2, 0x209($v0)
    MEM_B(0X209, ctx->r2) = ctx->r10;
    // 0x80041A1C: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80041A20: lw          $a3, 0x1C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X1C);
    // 0x80041A24: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    // 0x80041A28: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x80041A2C: lbu         $a0, 0x208($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X208);
    // 0x80041A30: lbu         $a1, 0xE($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XE);
    // 0x80041A34: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80041A38: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80041A3C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80041A40: jal         0x80067E24
    // 0x80041A44: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_80067E24(rdram, ctx);
        goto after_0;
    // 0x80041A44: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80041A48: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80041A4C: jal         0x80067818
    // 0x80041A50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80041A50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80041A54: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80041A58: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80041A5C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80041A60: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80041A64: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_80041A68:
    // 0x80041A68: b           L_80041A74
    // 0x80041A6C: sw          $t5, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r13;
        goto L_80041A74;
    // 0x80041A6C: sw          $t5, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r13;
    // 0x80041A70: sw          $zero, 0x8($t1)
    MEM_W(0X8, ctx->r9) = 0;
L_80041A74:
    // 0x80041A74: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80041A78: addiu       $a0, $v1, 0x6C
    ctx->r4 = ADD32(ctx->r3, 0X6C);
    // 0x80041A7C: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x80041A80: lwc1        $f16, 0x1FC($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X1FC);
    // 0x80041A84: swc1        $f16, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f16.u32l;
    // 0x80041A88: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80041A8C: addu        $t9, $t6, $t0
    ctx->r25 = ADD32(ctx->r14, ctx->r8);
    // 0x80041A90: lwc1        $f18, 0x200($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X200);
    // 0x80041A94: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80041A98: swc1        $f4, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f4.u32l;
    // 0x80041A9C: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80041AA0: lw          $t2, 0x10($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X10);
    // 0x80041AA4: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x80041AA8: lwc1        $f8, 0x204($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X204);
    // 0x80041AAC: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80041AB0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80041AB4: swc1        $f10, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f10.u32l;
    // 0x80041AB8: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80041ABC: addu        $t7, $t5, $t0
    ctx->r15 = ADD32(ctx->r13, ctx->r8);
    // 0x80041AC0: lh          $t8, 0x20A($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X20A);
    // 0x80041AC4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80041AC8: nop

    // 0x80041ACC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80041AD0: swc1        $f18, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f18.u32l;
    // 0x80041AD4: lbu         $t6, 0xF($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XF);
    // 0x80041AD8: beq         $t6, $zero, L_80041B40
    if (ctx->r14 == 0) {
        // 0x80041ADC: nop
    
            goto L_80041B40;
    }
    // 0x80041ADC: nop

    // 0x80041AE0: lhu         $t9, 0xC($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XC);
    // 0x80041AE4: addiu       $at, $zero, 0x4004
    ctx->r1 = ADD32(0, 0X4004);
    // 0x80041AE8: bnel        $t9, $at, L_80041B10
    if (ctx->r25 != ctx->r1) {
        // 0x80041AEC: lwc1        $f8, 0x78($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X78);
            goto L_80041B10;
    }
    goto skip_5;
    // 0x80041AEC: lwc1        $f8, 0x78($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X78);
    skip_5:
    // 0x80041AF0: lwc1        $f4, 0x78($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X78);
    // 0x80041AF4: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80041AF8: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80041AFC: swc1        $f0, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f0.u32l;
    // 0x80041B00: swc1        $f0, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f0.u32l;
    // 0x80041B04: b           L_80041B48
    // 0x80041B08: swc1        $f0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f0.u32l;
        goto L_80041B48;
    // 0x80041B08: swc1        $f0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f0.u32l;
    // 0x80041B0C: lwc1        $f8, 0x78($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X78);
L_80041B10:
    // 0x80041B10: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80041B14: lwc1        $f18, 0x7C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X7C);
    // 0x80041B18: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80041B1C: lwc1        $f8, 0x80($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X80);
    // 0x80041B20: swc1        $f16, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f16.u32l;
    // 0x80041B24: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80041B28: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80041B2C: swc1        $f6, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f6.u32l;
    // 0x80041B30: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80041B34: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80041B38: b           L_80041B48
    // 0x80041B3C: swc1        $f16, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f16.u32l;
        goto L_80041B48;
    // 0x80041B3C: swc1        $f16, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f16.u32l;
L_80041B40:
    // 0x80041B40: jal         0x80065490
    // 0x80041B44: addiu       $a1, $v1, 0x78
    ctx->r5 = ADD32(ctx->r3, 0X78);
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x80041B44: addiu       $a1, $v1, 0x78
    ctx->r5 = ADD32(ctx->r3, 0X78);
    after_2:
L_80041B48:
    // 0x80041B48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80041B4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041B50: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80041B54: jr          $ra
    // 0x80041B58: nop

    return;
    // 0x80041B58: nop

;}
RECOMP_FUNC void func_8077FF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077FF80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8077FF84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8077FF88: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8077FF8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8077FF90: jal         0x8077FE4C
    // 0x8077FF94: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
    func_8077FE4C(rdram, ctx);
        goto after_0;
    // 0x8077FF94: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
    after_0:
    // 0x8077FF98: beq         $v0, $zero, L_80780038
    if (ctx->r2 == 0) {
        // 0x8077FF9C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80780038;
    }
    // 0x8077FF9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8077FFA0: lhu         $v0, 0x1E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1E);
    // 0x8077FFA4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8077FFA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8077FFAC: slti        $at, $v0, 0x444E
    ctx->r1 = SIGNED(ctx->r2) < 0X444E ? 1 : 0;
    // 0x8077FFB0: bne         $at, $zero, L_8077FFCC
    if (ctx->r1 != 0) {
        // 0x8077FFB4: lui         $t9, 0x8078
        ctx->r25 = S32(RELOC_HI16(781, 0X36C) << 16);
            goto L_8077FFCC;
    }
    // 0x8077FFB4: lui         $t9, 0x8078
    ctx->r25 = S32(RELOC_HI16(781, 0X36C) << 16);
    // 0x8077FFB8: slti        $at, $v0, 0x448C
    ctx->r1 = SIGNED(ctx->r2) < 0X448C ? 1 : 0;
    // 0x8077FFBC: beql        $at, $zero, L_8077FFD0
    if (ctx->r1 == 0) {
        // 0x8077FFC0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8077FFD0;
    }
    goto skip_0;
    // 0x8077FFC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8077FFC4: b           L_8077FFD0
    // 0x8077FFC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8077FFD0;
    // 0x8077FFC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8077FFCC:
    // 0x8077FFCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8077FFD0:
    // 0x8077FFD0: addiu       $t9, $t9, -0x384
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(781, 0X36C));
    // 0x8077FFD4: sw          $v0, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r2;
    // 0x8077FFD8: sw          $t7, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r15;
    // 0x8077FFDC: sb          $t8, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r24;
    // 0x8077FFE0: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8077FFE4: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x8077FFE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8077FFEC: jal         0x8077FEF4
    // 0x8077FFF0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8077FEF4(rdram, ctx);
        goto after_1;
    // 0x8077FFF0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8077FFF4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8077FFF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8077FFFC: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(781, 0X7D8) << 16);
    // 0x80780000: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80780004: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80780008: lwc1        $f4, 0xE8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(781, 0X7D8));
    // 0x8078000C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80780010: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80780014: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80780018: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8078001C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80780020: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80780024: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80780028: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8078002C: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x80780030: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x80780034: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
L_80780038:
    // 0x80780038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078003C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80780040: jr          $ra
    // 0x80780044: nop

    return;
    // 0x80780044: nop

;}
RECOMP_FUNC void func_8052E16C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052E16C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8052E170: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x8052E174: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x8052E178: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8052E17C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052E180: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8052E184: lw          $v1, -0x7CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
    // 0x8052E188: lw          $a2, 0x1160($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1160);
    // 0x8052E18C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8052E190: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X23D4) << 16);
    // 0x8052E194: blezl       $a2, L_8052E244
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8052E198: sll         $t6, $a2, 3
        ctx->r14 = S32(ctx->r6 << 3);
            goto L_8052E244;
    }
    goto skip_0;
    // 0x8052E198: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    skip_0:
    // 0x8052E19C: lwc1        $f24, 0x194($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X23D4));
    // 0x8052E1A0: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8052E1A4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8052E1A8: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X23D8) << 16);
    // 0x8052E1AC: lwc1        $f20, 0x198($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X23D8));
    // 0x8052E1B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8052E1B4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8052E1B8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8052E1BC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8052E1C0: lwc1        $f16, 0x105C($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X105C);
L_8052E1C4:
    // 0x8052E1C4: lwc1        $f4, 0xF6C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XF6C);
    // 0x8052E1C8: sub.s       $f14, $f4, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8052E1CC: mul.s       $f0, $f14, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x8052E1D0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8052E1D4: nop

    // 0x8052E1D8: bc1fl       L_8052E1E8
    if (!c1cs) {
        // 0x8052E1DC: c.lt.s      $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
            goto L_8052E1E8;
    }
    goto skip_1;
    // 0x8052E1DC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    skip_1:
    // 0x8052E1E0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8052E1E4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
L_8052E1E8:
    // 0x8052E1E8: nop

    // 0x8052E1EC: bc1fl       L_8052E1FC
    if (!c1cs) {
        // 0x8052E1F0: sub.s       $f14, $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f0.fl;
            goto L_8052E1FC;
    }
    goto skip_2;
    // 0x8052E1F0: sub.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f0.fl;
    skip_2:
    // 0x8052E1F4: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x8052E1F8: sub.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f0.fl;
L_8052E1FC:
    // 0x8052E1FC: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x8052E200: nop

    // 0x8052E204: bc1fl       L_8052E224
    if (!c1cs) {
        // 0x8052E208: add.s       $f6, $f16, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f14.fl;
            goto L_8052E224;
    }
    goto skip_3;
    // 0x8052E208: add.s       $f6, $f16, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f14.fl;
    skip_3:
    // 0x8052E20C: c.lt.s      $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f24.fl < ctx->f14.fl;
    // 0x8052E210: nop

    // 0x8052E214: bc1fl       L_8052E224
    if (!c1cs) {
        // 0x8052E218: add.s       $f6, $f16, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f14.fl;
            goto L_8052E224;
    }
    goto skip_4;
    // 0x8052E218: add.s       $f6, $f16, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f14.fl;
    skip_4:
    // 0x8052E21C: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x8052E220: add.s       $f6, $f16, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f14.fl;
L_8052E224:
    // 0x8052E224: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8052E228: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8052E22C: swc1        $f6, 0xF68($a3)
    MEM_W(0XF68, ctx->r7) = ctx->f6.u32l;
    // 0x8052E230: lw          $a2, 0x1160($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1160);
    // 0x8052E234: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8052E238: bnel        $at, $zero, L_8052E1C4
    if (ctx->r1 != 0) {
        // 0x8052E23C: lwc1        $f16, 0x105C($a3)
        ctx->f16.u32l = MEM_W(ctx->r7, 0X105C);
            goto L_8052E1C4;
    }
    goto skip_5;
    // 0x8052E23C: lwc1        $f16, 0x105C($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X105C);
    skip_5:
    // 0x8052E240: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
L_8052E244:
    // 0x8052E244: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8052E248: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8052E24C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8052E250: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8052E254: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8052E258: lwc1        $f16, 0x30($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8052E25C: lwc1        $f18, 0x114C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X114C);
    // 0x8052E260: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052E264: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8052E268: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8052E26C: lh          $t7, 0xC0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XC0);
    // 0x8052E270: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8052E274: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8052E278: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8052E27C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8052E280: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8052E284: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8052E288: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x8052E28C: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x8052E290: nop

    // 0x8052E294: bc1t        L_8052E2B0
    if (c1cs) {
        // 0x8052E298: nop
    
            goto L_8052E2B0;
    }
    // 0x8052E298: nop

    // 0x8052E29C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8052E2A0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8052E2A4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8052E2A8: bc1fl       L_8052E2BC
    if (!c1cs) {
        // 0x8052E2AC: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8052E2BC;
    }
    goto skip_6;
    // 0x8052E2AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_6:
L_8052E2B0:
    // 0x8052E2B0: b           L_8052E41C
    // 0x8052E2B4: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
        goto L_8052E41C;
    // 0x8052E2B4: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x8052E2B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8052E2BC:
    // 0x8052E2BC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8052E2C0: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X23DC) << 16);
    // 0x8052E2C4: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8052E2C8: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8052E2CC: sub.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8052E2D0: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8052E2D4: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8052E2D8: nop

    // 0x8052E2DC: bc1fl       L_8052E2F0
    if (!c1cs) {
        // 0x8052E2E0: lui         $at, 0x3E00
        ctx->r1 = S32(0X3E00 << 16);
            goto L_8052E2F0;
    }
    goto skip_7;
    // 0x8052E2E0: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    skip_7:
    // 0x8052E2E4: lwc1        $f4, 0x19C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X23DC));
    // 0x8052E2E8: sub.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x8052E2EC: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
L_8052E2F0:
    // 0x8052E2F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8052E2F4: lw          $t8, 0x1168($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1168);
    // 0x8052E2F8: mul.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x8052E2FC: sw          $t8, 0x116C($v0)
    MEM_W(0X116C, ctx->r2) = ctx->r24;
    // 0x8052E300: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8052E304: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8052E308: nop

    // 0x8052E30C: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x8052E310: bgez        $t0, L_8052E320
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8052E314: sw          $t0, 0x1168($v0)
        MEM_W(0X1168, ctx->r2) = ctx->r8;
            goto L_8052E320;
    }
    // 0x8052E314: sw          $t0, 0x1168($v0)
    MEM_W(0X1168, ctx->r2) = ctx->r8;
    // 0x8052E318: b           L_8052E34C
    // 0x8052E31C: sw          $zero, 0x1168($v0)
    MEM_W(0X1168, ctx->r2) = 0;
        goto L_8052E34C;
    // 0x8052E31C: sw          $zero, 0x1168($v0)
    MEM_W(0X1168, ctx->r2) = 0;
L_8052E320:
    // 0x8052E320: lw          $a1, 0x1164($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1164);
    // 0x8052E324: lw          $t2, 0x1168($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1168);
    // 0x8052E328: lw          $a2, 0x1160($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1160);
    // 0x8052E32C: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x8052E330: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8052E334: bne         $at, $zero, L_8052E34C
    if (ctx->r1 != 0) {
        // 0x8052E338: subu        $t1, $a2, $a1
        ctx->r9 = SUB32(ctx->r6, ctx->r5);
            goto L_8052E34C;
    }
    // 0x8052E338: subu        $t1, $a2, $a1
    ctx->r9 = SUB32(ctx->r6, ctx->r5);
    // 0x8052E33C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8052E340: bgez        $t1, L_8052E34C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8052E344: sw          $t1, 0x1168($v0)
        MEM_W(0X1168, ctx->r2) = ctx->r9;
            goto L_8052E34C;
    }
    // 0x8052E344: sw          $t1, 0x1168($v0)
    MEM_W(0X1168, ctx->r2) = ctx->r9;
    // 0x8052E348: sw          $zero, 0x1168($v0)
    MEM_W(0X1168, ctx->r2) = 0;
L_8052E34C:
    // 0x8052E34C: slti        $at, $t0, -0x29
    ctx->r1 = SIGNED(ctx->r8) < -0X29 ? 1 : 0;
    // 0x8052E350: beq         $at, $zero, L_8052E360
    if (ctx->r1 == 0) {
        // 0x8052E354: lw          $a1, 0x1168($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X1168);
            goto L_8052E360;
    }
    // 0x8052E354: lw          $a1, 0x1168($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1168);
    // 0x8052E358: b           L_8052E374
    // 0x8052E35C: addiu       $a3, $zero, -0x29
    ctx->r7 = ADD32(0, -0X29);
        goto L_8052E374;
    // 0x8052E35C: addiu       $a3, $zero, -0x29
    ctx->r7 = ADD32(0, -0X29);
L_8052E360:
    // 0x8052E360: lw          $a2, 0x1160($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1160);
    // 0x8052E364: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8052E368: beql        $at, $zero, L_8052E378
    if (ctx->r1 == 0) {
        // 0x8052E36C: cfc1        $t4, $FpcCsr
        ctx->r12 = get_cop1_cs();
            goto L_8052E378;
    }
    goto skip_8;
    // 0x8052E36C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    skip_8:
    // 0x8052E370: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_8052E374:
    // 0x8052E374: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
L_8052E378:
    // 0x8052E378: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8052E37C: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8052E380: subu        $t7, $a1, $a3
    ctx->r15 = SUB32(ctx->r5, ctx->r7);
    // 0x8052E384: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8052E388: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8052E38C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8052E390: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8052E394: nop

    // 0x8052E398: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8052E39C: beql        $t5, $zero, L_8052E3EC
    if (ctx->r13 == 0) {
        // 0x8052E3A0: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_8052E3EC;
    }
    goto skip_9;
    // 0x8052E3A0: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_9:
    // 0x8052E3A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8052E3A8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8052E3AC: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8052E3B0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8052E3B4: nop

    // 0x8052E3B8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8052E3BC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8052E3C0: nop

    // 0x8052E3C4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8052E3C8: bne         $t5, $zero, L_8052E3E0
    if (ctx->r13 != 0) {
        // 0x8052E3CC: nop
    
            goto L_8052E3E0;
    }
    // 0x8052E3CC: nop

    // 0x8052E3D0: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8052E3D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8052E3D8: b           L_8052E3F8
    // 0x8052E3DC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_8052E3F8;
    // 0x8052E3DC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_8052E3E0:
    // 0x8052E3E0: b           L_8052E3F8
    // 0x8052E3E4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_8052E3F8;
    // 0x8052E3E4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8052E3E8: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_8052E3EC:
    // 0x8052E3EC: nop

    // 0x8052E3F0: bltz        $t5, L_8052E3E0
    if (SIGNED(ctx->r13) < 0) {
        // 0x8052E3F4: nop
    
            goto L_8052E3E0;
    }
    // 0x8052E3F4: nop

L_8052E3F8:
    // 0x8052E3F8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8052E3FC: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x8052E400: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8052E404: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8052E408: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8052E40C: lwc1        $f10, 0x1150($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1150);
    // 0x8052E410: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8052E414: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x8052E418: swc1        $f14, 0x1150($v0)
    MEM_W(0X1150, ctx->r2) = ctx->f14.u32l;
L_8052E41C:
    // 0x8052E41C: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x8052E420: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x8052E424: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x8052E428: jr          $ra
    // 0x8052E42C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8052E42C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80040F5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040F5C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80040F60: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80040F64: lw          $a1, 0x1F4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X1F4);
    // 0x80040F68: beq         $a1, $zero, L_80040F90
    if (ctx->r5 == 0) {
        // 0x80040F6C: nop
    
            goto L_80040F90;
    }
    // 0x80040F6C: nop

    // 0x80040F70: lwc1        $f4, 0x88($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X88);
    // 0x80040F74: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80040F78: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80040F7C: nop

    // 0x80040F80: bc1fl       L_80040FCC
    if (!c1cs) {
        // 0x80040F84: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_80040FCC;
    }
    goto skip_0;
    // 0x80040F84: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    skip_0:
    // 0x80040F88: jr          $ra
    // 0x80040F8C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80040F8C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80040F90:
    // 0x80040F90: lh          $v0, -0x7680($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X7680);
    // 0x80040F94: slti        $at, $v0, -0x27
    ctx->r1 = SIGNED(ctx->r2) < -0X27 ? 1 : 0;
    // 0x80040F98: beql        $at, $zero, L_80040FB8
    if (ctx->r1 == 0) {
        // 0x80040F9C: slti        $at, $v0, 0x28
        ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
            goto L_80040FB8;
    }
    goto skip_1;
    // 0x80040F9C: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    skip_1:
    // 0x80040FA0: lbu         $t6, 0x1F8($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1F8);
    // 0x80040FA4: bnel        $t6, $zero, L_80040FB8
    if (ctx->r14 != 0) {
        // 0x80040FA8: slti        $at, $v0, 0x28
        ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
            goto L_80040FB8;
    }
    goto skip_2;
    // 0x80040FA8: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    skip_2:
    // 0x80040FAC: jr          $ra
    // 0x80040FB0: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    return;
    // 0x80040FB0: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x80040FB4: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
L_80040FB8:
    // 0x80040FB8: bnel        $at, $zero, L_80040FCC
    if (ctx->r1 != 0) {
        // 0x80040FBC: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_80040FCC;
    }
    goto skip_3;
    // 0x80040FBC: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    skip_3:
    // 0x80040FC0: jr          $ra
    // 0x80040FC4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80040FC4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x80040FC8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80040FCC:
    // 0x80040FCC: jr          $ra
    // 0x80040FD0: nop

    return;
    // 0x80040FD0: nop

;}
RECOMP_FUNC void func_80051100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051100: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80051104: lw          $v0, -0x7B2C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7B2C);
    // 0x80051108: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005110C: andi        $a3, $a0, 0xFFFF
    ctx->r7 = ctx->r4 & 0XFFFF;
    // 0x80051110: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x80051114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80051118: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8005111C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80051120: blez        $a2, L_80051168
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80051124: addiu       $v1, $v0, 0x4
        ctx->r3 = ADD32(ctx->r2, 0X4);
            goto L_80051168;
    }
    // 0x80051124: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x80051128: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
L_8005112C:
    // 0x8005112C: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80051130: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80051134: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80051138: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8005113C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80051140: lhu         $t9, 0x3C($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X3C);
    // 0x80051144: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80051148: beql        $at, $zero, L_8005115C
    if (ctx->r1 == 0) {
        // 0x8005114C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8005115C;
    }
    goto skip_0;
    // 0x8005114C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    skip_0:
    // 0x80051150: b           L_8005115C
    // 0x80051154: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
        goto L_8005115C;
    // 0x80051154: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    // 0x80051158: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8005115C:
    // 0x8005115C: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80051160: bnel        $at, $zero, L_8005112C
    if (ctx->r1 != 0) {
        // 0x80051164: addu        $a0, $a2, $a1
        ctx->r4 = ADD32(ctx->r6, ctx->r5);
            goto L_8005112C;
    }
    goto skip_1;
    // 0x80051164: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
    skip_1:
L_80051168:
    // 0x80051168: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8005116C: addu        $t1, $v1, $a0
    ctx->r9 = ADD32(ctx->r3, ctx->r4);
    // 0x80051170: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80051174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80051178: lhu         $t3, 0x3C($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X3C);
    // 0x8005117C: bne         $a3, $t3, L_8005118C
    if (ctx->r7 != ctx->r11) {
        // 0x80051180: nop
    
            goto L_8005118C;
    }
    // 0x80051180: nop

    // 0x80051184: jr          $ra
    // 0x80051188: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    return;
    // 0x80051188: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
L_8005118C:
    // 0x8005118C: jr          $ra
    // 0x80051190: nop

    return;
    // 0x80051190: nop

;}
RECOMP_FUNC void func_80581F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581F38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80581F3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80581F40: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80581F44: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80581F48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581F4C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80581F50: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80581F54: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80581F58: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80581F5C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80581F60: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80581F64: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80581F68: lui         $t2, 0x8058
    ctx->r10 = S32(RELOC_HI16(399, 0X46E4) << 16);
    // 0x80581F6C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80581F70: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80581F74: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80581F78: lw          $t2, 0x34F4($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(399, 0X46E4));
    // 0x80581F7C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80581F80: jal         0x80581C44
    // 0x80581F84: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_80581C44(rdram, ctx);
        goto after_0;
    // 0x80581F84: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x80581F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80581F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581F90: jr          $ra
    // 0x80581F94: nop

    return;
    // 0x80581F94: nop

;}
RECOMP_FUNC void func_807885C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807885C8: jr          $ra
    // 0x807885CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807885CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805E1208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E1208: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805E120C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805E1210: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x805E1214: jal         0x800653D8
    // 0x805E1218: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x805E1218: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805E121C: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x805E1220: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x805E1224: lui         $t8, 0x805E
    ctx->r24 = S32(RELOC_HI16(483, 0X698) << 16);
    // 0x805E1228: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805E122C: lhu         $t8, 0x1328($t8)
    ctx->r24 = MEM_HU(ctx->r24, (int16_t)RELOC_LO16(483, 0X698));
    // 0x805E1230: addiu       $at, $zero, 0x453A
    ctx->r1 = ADD32(0, 0X453A);
    // 0x805E1234: lui         $a0, 0x805E
    ctx->r4 = S32(RELOC_HI16(483, 0X7A0) << 16);
    // 0x805E1238: andi        $v1, $t8, 0xFFFF
    ctx->r3 = ctx->r24 & 0XFFFF;
    // 0x805E123C: bne         $v1, $at, L_805E1274
    if (ctx->r3 != ctx->r1) {
        // 0x805E1240: sh          $t8, 0x2A($sp)
        MEM_H(0X2A, ctx->r29) = ctx->r24;
            goto L_805E1274;
    }
    // 0x805E1240: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
    // 0x805E1244: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x805E1248: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x805E124C: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x805E1250: lui         $a0, 0x805E
    ctx->r4 = S32(RELOC_HI16(483, 0X790) << 16);
    // 0x805E1254: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x805E1258: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x805E125C: addiu       $a0, $a0, 0x1420
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(483, 0X790));
    // 0x805E1260: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x805E1264: jal         0x80046804
    // 0x805E1268: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x805E1268: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x805E126C: b           L_805E129C
    // 0x805E1270: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_805E129C;
    // 0x805E1270: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_805E1274:
    // 0x805E1274: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x805E1278: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x805E127C: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x805E1280: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x805E1284: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x805E1288: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x805E128C: addiu       $a0, $a0, 0x1430
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(483, 0X7A0));
    // 0x805E1290: jal         0x80046804
    // 0x805E1294: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80046804(rdram, ctx);
        goto after_2;
    // 0x805E1294: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x805E1298: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_805E129C:
    // 0x805E129C: beq         $v0, $zero, L_805E12E0
    if (ctx->r2 == 0) {
        // 0x805E12A0: nop
    
            goto L_805E12E0;
    }
    // 0x805E12A0: nop

    // 0x805E12A4: jal         0x80047090
    // 0x805E12A8: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    func_80047090(rdram, ctx);
        goto after_3;
    // 0x805E12A8: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    after_3:
    // 0x805E12AC: lhu         $t1, 0xE($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XE);
    // 0x805E12B0: andi        $t0, $v0, 0x3FF
    ctx->r8 = ctx->r2 & 0X3FF;
    // 0x805E12B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E12B8: andi        $t2, $t1, 0xFC00
    ctx->r10 = ctx->r9 & 0XFC00;
    // 0x805E12BC: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x805E12C0: jal         0x80052BA4
    // 0x805E12C4: sh          $t3, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r11;
    func_80052BA4(rdram, ctx);
        goto after_4;
    // 0x805E12C4: sh          $t3, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r11;
    after_4:
    // 0x805E12C8: jal         0x8005FDC4
    // 0x805E12CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_5;
    // 0x805E12CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805E12D0: jal         0x80052BA4
    // 0x805E12D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052BA4(rdram, ctx);
        goto after_6;
    // 0x805E12D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x805E12D8: b           L_805E12E8
    // 0x805E12DC: nop

        goto L_805E12E8;
    // 0x805E12DC: nop

L_805E12E0:
    // 0x805E12E0: b           L_805E12F4
    // 0x805E12E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805E12F4;
    // 0x805E12E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805E12E8:
    // 0x805E12E8: jal         0x80044194
    // 0x805E12EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044194(rdram, ctx);
        goto after_7;
    // 0x805E12EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x805E12F0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_805E12F4:
    // 0x805E12F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805E12F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805E12FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805E1300: jr          $ra
    // 0x805E1304: nop

    return;
    // 0x805E1304: nop

    // 0x805E1308: nop

    // 0x805E130C: nop

;}
RECOMP_FUNC void func_807AF904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AF908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AF90C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807AF910: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x807AF914: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x807AF918: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807AF91C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807AF920: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AF924: jal         0x807AFA3C
    // 0x807AF928: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_807AFA3C(rdram, ctx);
        goto after_0;
    // 0x807AF928: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x807AF92C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AF930: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807AF934: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807AF938: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807AF93C: jal         0x807AF8A4
    // 0x807AF940: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    func_807AF8A4(rdram, ctx);
        goto after_1;
    // 0x807AF940: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    after_1:
    // 0x807AF944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AF948: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AF94C: jr          $ra
    // 0x807AF950: nop

    return;
    // 0x807AF950: nop

;}
RECOMP_FUNC void func_80715C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80715C24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80715C28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80715C2C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80715C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80715C34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80715C38: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x80715C3C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80715C40: lui         $t9, 0x8071
    ctx->r25 = S32(RELOC_HI16(730, 0X1790) << 16);
    // 0x80715C44: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80715C48: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80715C4C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80715C50: lw          $t9, 0x5FB0($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(730, 0X1790));
    // 0x80715C54: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80715C58: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x80715C5C: jal         0x807149D8
    // 0x80715C60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807149D8(rdram, ctx);
        goto after_0;
    // 0x80715C60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80715C64: jal         0x80714AA8
    // 0x80715C68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80714AA8(rdram, ctx);
        goto after_1;
    // 0x80715C68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80715C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80715C70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80715C74: jr          $ra
    // 0x80715C78: nop

    return;
    // 0x80715C78: nop

    // 0x80715C7C: nop

;}
RECOMP_FUNC void func_8045335C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045335C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453364: jal         0x804531D0
    // 0x80453368: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804531D0(rdram, ctx);
        goto after_0;
    // 0x80453368: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045336C: beq         $v0, $zero, L_8045337C
    if (ctx->r2 == 0) {
        // 0x80453370: nop
    
            goto L_8045337C;
    }
    // 0x80453370: nop

    // 0x80453374: jal         0x8045290C
    // 0x80453378: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8045290C(rdram, ctx);
        goto after_1;
    // 0x80453378: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_8045337C:
    // 0x8045337C: jal         0x8044DED8
    // 0x80453380: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8044DED8(rdram, ctx);
        goto after_2;
    // 0x80453380: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80453384: jal         0x8044E684
    // 0x80453388: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8044E684(rdram, ctx);
        goto after_3;
    // 0x80453388: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8045338C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453394: jr          $ra
    // 0x80453398: nop

    return;
    // 0x80453398: nop

;}
RECOMP_FUNC void func_804B8770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B8770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B8774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B8778: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804B877C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804B8780: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804B8784: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(185, 0X298C) << 16);
    // 0x804B8788: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804B878C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804B8790: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804B8794: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804B8798: lw          $t8, -0x5854($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(185, 0X298C));
    // 0x804B879C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804B87A0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804B87A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804B87A8: jal         0x80048490
    // 0x804B87AC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804B87AC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804B87B0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804B87B4: jal         0x80048378
    // 0x804B87B8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804B87B8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804B87BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B87C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B87C4: jr          $ra
    // 0x804B87C8: nop

    return;
    // 0x804B87C8: nop

;}
RECOMP_FUNC void func_804A4FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4FD4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x804A4FD8: lw          $t6, -0x720C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X720C);
    // 0x804A4FDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A4FE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A4FE4: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x804A4FE8: beq         $t7, $zero, L_804A5044
    if (ctx->r15 == 0) {
        // 0x804A4FEC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_804A5044;
    }
    // 0x804A4FEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804A4FF0: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x804A4FF4: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x804A4FF8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x804A4FFC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x804A5000: lw          $v1, 0x6EE0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6EE0);
    // 0x804A5004: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x804A5008: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A500C: bne         $v1, $zero, L_804A503C
    if (ctx->r3 != 0) {
        // 0x804A5010: nop
    
            goto L_804A503C;
    }
    // 0x804A5010: nop

    // 0x804A5014: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x804A5018: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x804A501C: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x804A5020: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x804A5024: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x804A5028: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x804A502C: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x804A5030: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x804A5034: b           L_804A5044
    // 0x804A5038: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
        goto L_804A5044;
    // 0x804A5038: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_804A503C:
    // 0x804A503C: jal         0x804A4E04
    // 0x804A5040: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    func_804A4E04(rdram, ctx);
        goto after_0;
    // 0x804A5040: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_0:
L_804A5044:
    // 0x804A5044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A5048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A504C: jr          $ra
    // 0x804A5050: nop

    return;
    // 0x804A5050: nop

;}
RECOMP_FUNC void func_8001F0DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F0DC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001F0E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001F0E4: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8001F0E8: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x8001F0EC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001F0F0: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8001F0F4: lw          $v0, 0x40($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X40);
    // 0x8001F0F8: lhu         $t7, 0x60($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X60);
    // 0x8001F0FC: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // 0x8001F100: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8001F104: beq         $t8, $zero, L_8001F14C
    if (ctx->r24 == 0) {
        // 0x8001F108: sh          $t7, 0x4E($sp)
        MEM_H(0X4E, ctx->r29) = ctx->r15;
            goto L_8001F14C;
    }
    // 0x8001F108: sh          $t7, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r15;
    // 0x8001F10C: beq         $t8, $at, L_8001F14C
    if (ctx->r24 == ctx->r1) {
        // 0x8001F110: lbu         $v1, 0x4E($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X4E);
            goto L_8001F14C;
    }
    // 0x8001F110: lbu         $v1, 0x4E($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X4E);
    // 0x8001F114: andi        $v0, $v1, 0xF8
    ctx->r2 = ctx->r3 & 0XF8;
    // 0x8001F118: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8001F11C: beq         $v0, $at, L_8001F14C
    if (ctx->r2 == ctx->r1) {
        // 0x8001F120: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8001F14C;
    }
    // 0x8001F120: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001F124: beq         $v0, $at, L_8001F14C
    if (ctx->r2 == ctx->r1) {
        // 0x8001F128: andi        $t9, $v1, 0x1
        ctx->r25 = ctx->r3 & 0X1;
            goto L_8001F14C;
    }
    // 0x8001F128: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x8001F12C: bne         $t9, $zero, L_8001F13C
    if (ctx->r25 != 0) {
        // 0x8001F130: andi        $t1, $v1, 0x2
        ctx->r9 = ctx->r3 & 0X2;
            goto L_8001F13C;
    }
    // 0x8001F130: andi        $t1, $v1, 0x2
    ctx->r9 = ctx->r3 & 0X2;
    // 0x8001F134: beql        $t1, $zero, L_8001F150
    if (ctx->r9 == 0) {
        // 0x8001F138: lwc1        $f4, 0x84($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
            goto L_8001F150;
    }
    goto skip_0;
    // 0x8001F138: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    skip_0:
L_8001F13C:
    // 0x8001F13C: jal         0x8001F050
    // 0x8001F140: nop

    func_8001F050(rdram, ctx);
        goto after_0;
    // 0x8001F140: nop

    after_0:
    // 0x8001F144: b           L_8001F270
    // 0x8001F148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001F270;
    // 0x8001F148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001F14C:
    // 0x8001F14C: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
L_8001F150:
    // 0x8001F150: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8001F154: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001F158: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x8001F15C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8001F160: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8001F164: addiu       $t4, $sp, 0x3C
    ctx->r12 = ADD32(ctx->r29, 0X3C);
    // 0x8001F168: lw          $t3, 0x34($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X34);
    // 0x8001F16C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001F170: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001F174: lwc1        $f16, 0x10($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X10);
    // 0x8001F178: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x8001F17C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8001F180: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8001F184: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8001F188: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001F18C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8001F190: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x8001F194: jal         0x800534C0
    // 0x8001F198: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    func_800534C0(rdram, ctx);
        goto after_1;
    // 0x8001F198: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x8001F19C: addiu       $a0, $sp, 0x4E
    ctx->r4 = ADD32(ctx->r29, 0X4E);
    // 0x8001F1A0: sh          $v0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r2;
    // 0x8001F1A4: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x8001F1A8: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8001F1AC: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8001F1B0: andi        $t6, $t5, 0xF8
    ctx->r14 = ctx->r13 & 0XF8;
    // 0x8001F1B4: bne         $t6, $at, L_8001F1C0
    if (ctx->r14 != ctx->r1) {
        // 0x8001F1B8: andi        $t8, $v0, 0x7FF
        ctx->r24 = ctx->r2 & 0X7FF;
            goto L_8001F1C0;
    }
    // 0x8001F1B8: andi        $t8, $v0, 0x7FF
    ctx->r24 = ctx->r2 & 0X7FF;
    // 0x8001F1BC: sh          $t8, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r24;
L_8001F1C0:
    // 0x8001F1C0: lhu         $t9, 0x4E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X4E);
    // 0x8001F1C4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001F1C8: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8001F1CC: beql        $t9, $zero, L_8001F248
    if (ctx->r25 == 0) {
        // 0x8001F1D0: lw          $t3, 0x0($t0)
        ctx->r11 = MEM_W(ctx->r8, 0X0);
            goto L_8001F248;
    }
    goto skip_1;
    // 0x8001F1D0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    skip_1:
    // 0x8001F1D4: beql        $t9, $at, L_8001F248
    if (ctx->r25 == ctx->r1) {
        // 0x8001F1D8: lw          $t3, 0x0($t0)
        ctx->r11 = MEM_W(ctx->r8, 0X0);
            goto L_8001F248;
    }
    goto skip_2;
    // 0x8001F1D8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    skip_2:
    // 0x8001F1DC: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8001F1E0: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8001F1E4: andi        $v0, $v1, 0xF8
    ctx->r2 = ctx->r3 & 0XF8;
    // 0x8001F1E8: beq         $v0, $at, L_8001F244
    if (ctx->r2 == ctx->r1) {
        // 0x8001F1EC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8001F244;
    }
    // 0x8001F1EC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001F1F0: beq         $v0, $at, L_8001F244
    if (ctx->r2 == ctx->r1) {
        // 0x8001F1F4: andi        $t1, $v1, 0x1
        ctx->r9 = ctx->r3 & 0X1;
            goto L_8001F244;
    }
    // 0x8001F1F4: andi        $t1, $v1, 0x1
    ctx->r9 = ctx->r3 & 0X1;
    // 0x8001F1F8: bne         $t1, $zero, L_8001F208
    if (ctx->r9 != 0) {
        // 0x8001F1FC: andi        $t2, $v1, 0x2
        ctx->r10 = ctx->r3 & 0X2;
            goto L_8001F208;
    }
    // 0x8001F1FC: andi        $t2, $v1, 0x2
    ctx->r10 = ctx->r3 & 0X2;
    // 0x8001F200: beql        $t2, $zero, L_8001F248
    if (ctx->r10 == 0) {
        // 0x8001F204: lw          $t3, 0x0($t0)
        ctx->r11 = MEM_W(ctx->r8, 0X0);
            goto L_8001F248;
    }
    goto skip_3;
    // 0x8001F204: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    skip_3:
L_8001F208:
    // 0x8001F208: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    // 0x8001F20C: jal         0x8004A97C
    // 0x8001F210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004A97C(rdram, ctx);
        goto after_2;
    // 0x8001F210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8001F214: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8001F218: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8001F21C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8001F220: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8001F224: jal         0x8001EFDC
    // 0x8001F228: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    func_8001EFDC(rdram, ctx);
        goto after_3;
    // 0x8001F228: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    after_3:
    // 0x8001F22C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8001F230: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8001F234: jal         0x8001EF3C
    // 0x8001F238: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_8001EF3C(rdram, ctx);
        goto after_4;
    // 0x8001F238: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x8001F23C: b           L_8001F270
    // 0x8001F240: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001F270;
    // 0x8001F240: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001F244:
    // 0x8001F244: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
L_8001F248:
    // 0x8001F248: lbu         $t6, 0x5C($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X5C);
    // 0x8001F24C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F250: lw          $t4, 0x40($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X40);
    // 0x8001F254: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001F258: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8001F25C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8001F260: addu        $v0, $t4, $t7
    ctx->r2 = ADD32(ctx->r12, ctx->r15);
    // 0x8001F264: jal         0x8004A97C
    // 0x8001F268: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    func_8004A97C(rdram, ctx);
        goto after_5;
    // 0x8001F268: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    after_5:
    // 0x8001F26C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001F270:
    // 0x8001F270: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8001F274: jr          $ra
    // 0x8001F278: nop

    return;
    // 0x8001F278: nop

;}
RECOMP_FUNC void func_80027B14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027B14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80027B18: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80027B1C: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x80027B20: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80027B24: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80027B28: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80027B2C: addiu       $t8, $t8, 0x4748
    ctx->r24 = ADD32(ctx->r24, 0X4748);
    // 0x80027B30: bc1f        L_80027B44
    if (!c1cs) {
        // 0x80027B34: nop
    
            goto L_80027B44;
    }
    // 0x80027B34: nop

    // 0x80027B38: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    // 0x80027B3C: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
    // 0x80027B40: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
L_80027B44:
    // 0x80027B44: jr          $ra
    // 0x80027B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80027B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_806E5BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E5BF0: jr          $ra
    // 0x806E5BF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806E5BF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80442258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80442258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044225C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80442260: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80442264: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80442268: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(95, 0X4E34) << 16);
    // 0x8044226C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80442270: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80442274: lw          $t8, 0x3D34($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(95, 0X4E34));
    // 0x80442278: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8044227C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80442280: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80442284: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80442288: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8044228C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80442290: beql        $v1, $zero, L_804422C4
    if (ctx->r3 == 0) {
        // 0x80442294: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804422C4;
    }
    goto skip_0;
    // 0x80442294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80442298: jalr        $v1
    // 0x8044229C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8044229C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804422A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804422A4: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804422A8: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804422AC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804422B0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804422B4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804422B8: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804422BC: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804422C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804422C4:
    // 0x804422C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804422C8: jr          $ra
    // 0x804422CC: nop

    return;
    // 0x804422CC: nop

;}
RECOMP_FUNC void func_8064B6F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B6F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B6F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B6FC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8064B700: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8064B704: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8064B708: lui         $t8, 0x8065
    ctx->r24 = S32(RELOC_HI16(495, 0X309C) << 16);
    // 0x8064B70C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8064B710: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8064B714: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8064B718: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8064B71C: lw          $t8, -0x2E94($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(495, 0X309C));
    // 0x8064B720: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8064B724: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8064B728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064B72C: jal         0x80048490
    // 0x8064B730: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8064B730: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8064B734: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8064B738: jal         0x80048378
    // 0x8064B73C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8064B73C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8064B740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064B744: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B748: jr          $ra
    // 0x8064B74C: nop

    return;
    // 0x8064B74C: nop

;}
RECOMP_FUNC void func_805A2A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A2A98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A2A9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A2AA0: jal         0x805A27E8
    // 0x805A2AA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805A27E8(rdram, ctx);
        goto after_0;
    // 0x805A2AA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A2AA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A2AAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A2AB0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805A2AB4: jal         0x805A2B28
    // 0x805A2AB8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_805A2B28(rdram, ctx);
        goto after_1;
    // 0x805A2AB8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x805A2ABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A2AC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A2AC4: jr          $ra
    // 0x805A2AC8: nop

    return;
    // 0x805A2AC8: nop

;}
RECOMP_FUNC void func_80032878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032878: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003287C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032880: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80032884: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80032888: jal         0x8003D840
    // 0x8003288C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8003D840(rdram, ctx);
        goto after_0;
    // 0x8003288C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80032890: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80032894: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80032898: sb          $zero, 0x156($a1)
    MEM_B(0X156, ctx->r5) = 0;
    // 0x8003289C: jal         0x800322BC
    // 0x800328A0: sb          $zero, 0x154($a1)
    MEM_B(0X154, ctx->r5) = 0;
    func_800322BC(rdram, ctx);
        goto after_1;
    // 0x800328A0: sb          $zero, 0x154($a1)
    MEM_B(0X154, ctx->r5) = 0;
    after_1:
    // 0x800328A4: bne         $v0, $zero, L_800328B4
    if (ctx->r2 != 0) {
        // 0x800328A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800328B4;
    }
    // 0x800328A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800328AC: b           L_800328B8
    // 0x800328B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800328B8;
    // 0x800328B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800328B4:
    // 0x800328B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800328B8:
    // 0x800328B8: jr          $ra
    // 0x800328BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800328BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80526C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526C4C: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6154) << 16);
    // 0x80526C50: lwc1        $f4, -0x3FAC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6154));
    // 0x80526C54: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80526C58: lui         $v1, 0x8053
    ctx->r3 = S32(RELOC_HI16(327, 0X303C) << 16);
    // 0x80526C5C: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(327, 0XDFC) << 16);
    // 0x80526C60: addiu       $v1, $v1, -0x70C4
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(327, 0X303C));
    // 0x80526C64: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80526C68: addiu       $t6, $t6, 0x6CFC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(327, 0XDFC));
    // 0x80526C6C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x80526C70: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x80526C74: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80526C78: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80526C7C: sw          $t6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r14;
    // 0x80526C80: sw          $v0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r2;
    // 0x80526C84: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x80526C88: jr          $ra
    // 0x80526C8C: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80526C8C: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80436D24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436D24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80436D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80436D2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80436D30: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80436D34: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80436D38: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80436D3C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80436D40: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80436D44: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80436D48: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80436D4C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80436D50: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80436D54: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80436D58: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x80436D5C: lw          $t7, 0x174($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X174);
    // 0x80436D60: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80436D64: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80436D68: lw          $v0, 0x28($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X28);
    // 0x80436D6C: beql        $v0, $zero, L_80436D80
    if (ctx->r2 == 0) {
        // 0x80436D70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80436D80;
    }
    goto skip_0;
    // 0x80436D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80436D74: jalr        $v0
    // 0x80436D78: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80436D78: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80436D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80436D80:
    // 0x80436D80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80436D84: jr          $ra
    // 0x80436D88: nop

    return;
    // 0x80436D88: nop

;}
RECOMP_FUNC void func_800422CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800422CC: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800422D0: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x800422D4: lw          $t6, 0xF10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XF10);
    // 0x800422D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800422DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800422E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800422E4: addu        $v0, $v1, $t7
    ctx->r2 = ADD32(ctx->r3, ctx->r15);
    // 0x800422E8: lw          $t8, 0xF14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XF14);
    // 0x800422EC: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x800422F0: bne         $at, $zero, L_800422FC
    if (ctx->r1 != 0) {
        // 0x800422F4: nop
    
            goto L_800422FC;
    }
    // 0x800422F4: nop

    // 0x800422F8: sw          $zero, 0xAA4($v1)
    MEM_W(0XAA4, ctx->r3) = 0;
L_800422FC:
    // 0x800422FC: jal         0x8002B3A0
    // 0x80042300: sw          $a0, 0xF14($v0)
    MEM_W(0XF14, ctx->r2) = ctx->r4;
    func_8002B3A0(rdram, ctx);
        goto after_0;
    // 0x80042300: sw          $a0, 0xF14($v0)
    MEM_W(0XF14, ctx->r2) = ctx->r4;
    after_0:
    // 0x80042304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80042308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004230C: jr          $ra
    // 0x80042310: nop

    return;
    // 0x80042310: nop

;}
RECOMP_FUNC void func_8040FAB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040FAB4: jr          $ra
    // 0x8040FAB8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8040FAB8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8001D1DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D1DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D1E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D1E4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001D1E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001D1EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001D1F0: jal         0x8001D698
    // 0x8001D1F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8001D698(rdram, ctx);
        goto after_0;
    // 0x8001D1F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8001D1F8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D1FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001D200: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001D204: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001D208: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8001D20C: sb          $zero, 0x30($v0)
    MEM_B(0X30, ctx->r2) = 0;
    // 0x8001D210: sb          $t7, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r15;
    // 0x8001D214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D218: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D21C: jr          $ra
    // 0x8001D220: nop

    return;
    // 0x8001D220: nop

;}
RECOMP_FUNC void func_807AD5F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AD5F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AD5FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AD600: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AD604: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26D4) << 16);
    // 0x807AD608: lwc1        $f6, -0x12CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26D4));
    // 0x807AD60C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807AD610: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AD614: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807AD618: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x807AD61C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807AD620: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x807AD624: nop

    // 0x807AD628: bc1fl       L_807AD648
    if (!c1cs) {
        // 0x807AD62C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807AD648;
    }
    goto skip_0;
    // 0x807AD62C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807AD630: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x807AD634: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x807AD638: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x807AD63C: jal         0x80044658
    // 0x807AD640: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    func_80044658(rdram, ctx);
        goto after_0;
    // 0x807AD640: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    after_0:
    // 0x807AD644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807AD648:
    // 0x807AD648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AD64C: jr          $ra
    // 0x807AD650: nop

    return;
    // 0x807AD650: nop

;}
RECOMP_FUNC void func_800256A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800256A8: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x800256AC: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x800256B0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800256B4: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x800256B8: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800256BC: sltu        $at, $t7, $t9
    ctx->r1 = ctx->r15 < ctx->r25 ? 1 : 0;
    // 0x800256C0: bnel        $at, $zero, L_80025704
    if (ctx->r1 != 0) {
        // 0x800256C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80025704;
    }
    goto skip_0;
    // 0x800256C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800256C8: lbu         $t0, 0x158($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X158);
    // 0x800256CC: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x800256D0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800256D4: sb          $t1, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r9;
    // 0x800256D8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800256DC: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800256E0: sltu        $at, $t2, $t3
    ctx->r1 = ctx->r10 < ctx->r11 ? 1 : 0;
    // 0x800256E4: bnel        $at, $zero, L_800256F8
    if (ctx->r1 != 0) {
        // 0x800256E8: lw          $t4, 0x14C($a0)
        ctx->r12 = MEM_W(ctx->r4, 0X14C);
            goto L_800256F8;
    }
    goto skip_1;
    // 0x800256E8: lw          $t4, 0x14C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X14C);
    skip_1:
    // 0x800256EC: jr          $ra
    // 0x800256F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800256F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800256F4: lw          $t4, 0x14C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X14C);
L_800256F8:
    // 0x800256F8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800256FC: sw          $t5, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r13;
    // 0x80025700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80025704:
    // 0x80025704: jr          $ra
    // 0x80025708: nop

    return;
    // 0x80025708: nop

;}
RECOMP_FUNC void func_8078C690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078C690: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078C694: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8078C698: addiu       $v1, $v0, 0x80
    ctx->r3 = ADD32(ctx->r2, 0X80);
    // 0x8078C69C: lw          $a1, 0xC4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC4);
    // 0x8078C6A0: lw          $a2, 0xC8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC8);
    // 0x8078C6A4: lwc1        $f0, 0xC0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC0);
    // 0x8078C6A8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8078C6AC: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8078C6B0: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8078C6B4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8078C6B8: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x8078C6BC: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8078C6C0: beql        $a3, $v0, L_8078C744
    if (ctx->r7 == ctx->r2) {
        // 0x8078C6C4: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_8078C744;
    }
    goto skip_0;
    // 0x8078C6C4: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_0:
    // 0x8078C6C8: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_8078C6CC:
    // 0x8078C6CC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8078C6D0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8078C6D4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8078C6D8: swc1        $f14, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f14.u32l;
    // 0x8078C6DC: lwc1        $f14, -0xC($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0XC);
    // 0x8078C6E0: lwc1        $f12, -0xC($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, -0XC);
    // 0x8078C6E4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8078C6E8: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8078C6EC: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8078C6F0: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8078C6F4: swc1        $f14, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f14.u32l;
    // 0x8078C6F8: lwc1        $f14, -0x8($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X8);
    // 0x8078C6FC: lwc1        $f12, -0x8($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, -0X8);
    // 0x8078C700: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8078C704: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8078C708: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8078C70C: swc1        $f14, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f14.u32l;
    // 0x8078C710: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8078C714: lwc1        $f12, -0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8078C718: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8078C71C: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8078C720: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8078C724: swc1        $f14, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f14.u32l;
    // 0x8078C728: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8078C72C: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8078C730: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x8078C734: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8078C738: bnel        $a3, $v0, L_8078C6CC
    if (ctx->r7 != ctx->r2) {
        // 0x8078C73C: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_8078C6CC;
    }
    goto skip_1;
    // 0x8078C73C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
    // 0x8078C740: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_8078C744:
    // 0x8078C744: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8078C748: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8078C74C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8078C750: swc1        $f14, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f14.u32l;
    // 0x8078C754: lwc1        $f12, -0xC($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, -0XC);
    // 0x8078C758: lwc1        $f14, -0xC($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0XC);
    // 0x8078C75C: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8078C760: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8078C764: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8078C768: swc1        $f14, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f14.u32l;
    // 0x8078C76C: lwc1        $f12, -0x8($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, -0X8);
    // 0x8078C770: lwc1        $f14, -0x8($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X8);
    // 0x8078C774: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8078C778: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8078C77C: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8078C780: swc1        $f14, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f14.u32l;
    // 0x8078C784: lwc1        $f12, -0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8078C788: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8078C78C: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8078C790: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8078C794: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8078C798: swc1        $f14, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f14.u32l;
    // 0x8078C79C: jr          $ra
    // 0x8078C7A0: nop

    return;
    // 0x8078C7A0: nop

;}
RECOMP_FUNC void func_804448BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804448BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x804448C0: jr          $ra
    // 0x804448C4: sb          $zero, 0x7EA4($at)
    MEM_B(0X7EA4, ctx->r1) = 0;
    return;
    // 0x804448C4: sb          $zero, 0x7EA4($at)
    MEM_B(0X7EA4, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80534ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534ED8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80534EDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80534EE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80534EE4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80534EE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80534EEC: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x80534EF0: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x80534EF4: beq         $t6, $zero, L_80534F98
    if (ctx->r14 == 0) {
        // 0x80534EF8: andi        $t7, $v0, 0x4
        ctx->r15 = ctx->r2 & 0X4;
            goto L_80534F98;
    }
    // 0x80534EF8: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x80534EFC: beql        $t7, $zero, L_80534F90
    if (ctx->r15 == 0) {
        // 0x80534F00: ori         $t4, $v0, 0x4
        ctx->r12 = ctx->r2 | 0X4;
            goto L_80534F90;
    }
    goto skip_0;
    // 0x80534F00: ori         $t4, $v0, 0x4
    ctx->r12 = ctx->r2 | 0X4;
    skip_0:
    // 0x80534F04: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80534F08: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80534F0C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80534F10: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80534F14: sb          $t8, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r24;
    // 0x80534F18: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80534F1C: add.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80534F20: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x80534F24: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    // 0x80534F28: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    // 0x80534F2C: swc1        $f6, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = ctx->f6.u32l;
    // 0x80534F30: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x80534F34: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80534F38: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x80534F3C: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x80534F40: lw          $t9, 0x18($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X18);
    // 0x80534F44: jalr        $t9
    // 0x80534F48: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80534F48: nop

    after_0:
    // 0x80534F4C: jal         0x800447C8
    // 0x80534F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x80534F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80534F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80534F58: jal         0x805346E4
    // 0x80534F5C: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_805346E4(rdram, ctx);
        goto after_2;
    // 0x80534F5C: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_2:
    // 0x80534F60: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80534F64: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80534F68: sb          $t1, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r9;
    // 0x80534F6C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80534F70: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80534F74: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80534F78: sb          $t2, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r10;
    // 0x80534F7C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80534F80: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x80534F84: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
    // 0x80534F88: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x80534F8C: ori         $t4, $v0, 0x4
    ctx->r12 = ctx->r2 | 0X4;
L_80534F90:
    // 0x80534F90: b           L_80534FC8
    // 0x80534F94: sh          $t4, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r12;
        goto L_80534FC8;
    // 0x80534F94: sh          $t4, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r12;
L_80534F98:
    // 0x80534F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80534F9C: jal         0x805347F0
    // 0x80534FA0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_805347F0(rdram, ctx);
        goto after_3;
    // 0x80534FA0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x80534FA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80534FA8: bne         $v0, $at, L_80534FC8
    if (ctx->r2 != ctx->r1) {
        // 0x80534FAC: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80534FC8;
    }
    // 0x80534FAC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80534FB0: lhu         $t5, 0xC($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0XC);
    // 0x80534FB4: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x80534FB8: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x80534FBC: sh          $t6, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r14;
    // 0x80534FC0: sh          $t7, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r15;
    // 0x80534FC4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_80534FC8:
    // 0x80534FC8: jal         0x80534620
    // 0x80534FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80534620(rdram, ctx);
        goto after_4;
    // 0x80534FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80534FD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80534FD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80534FD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80534FDC: jr          $ra
    // 0x80534FE0: nop

    return;
    // 0x80534FE0: nop

;}
RECOMP_FUNC void func_80561760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80561760: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80561764: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80561768: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8056176C: jal         0x80561804
    // 0x80561770: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80561804(rdram, ctx);
        goto after_0;
    // 0x80561770: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80561774: beq         $v0, $zero, L_805617E8
    if (ctx->r2 == 0) {
        // 0x80561778: nop
    
            goto L_805617E8;
    }
    // 0x80561778: nop

    // 0x8056177C: jal         0x8056183C
    // 0x80561780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8056183C(rdram, ctx);
        goto after_1;
    // 0x80561780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80561784: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80561788: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8056178C: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80561790: lui         $t7, 0x8056
    ctx->r15 = S32(RELOC_HI16(366, 0X22E8) << 16);
    // 0x80561794: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x80561798: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8056179C: addiu       $t7, $t7, 0x3738
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(366, 0X22E8));
    // 0x805617A0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805617A4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x805617A8: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x805617AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805617B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805617B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805617B8: jal         0x805636D0
    // 0x805617BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805636D0(rdram, ctx);
        goto after_2;
    // 0x805617BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x805617C0: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x805617C4: lui         $t9, 0x8056
    ctx->r25 = S32(RELOC_HI16(366, 0XB7C) << 16);
    // 0x805617C8: addiu       $t9, $t9, 0x1FCC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(366, 0XB7C));
    // 0x805617CC: lui         $t1, 0x8056
    ctx->r9 = S32(RELOC_HI16(366, 0X244) << 16);
    // 0x805617D0: addiu       $t1, $t1, 0x1694
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(366, 0X244));
    // 0x805617D4: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x805617D8: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x805617DC: sw          $t1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r9;
    // 0x805617E0: b           L_805617F0
    // 0x805617E4: sh          $t2, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r10;
        goto L_805617F0;
    // 0x805617E4: sh          $t2, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r10;
L_805617E8:
    // 0x805617E8: jal         0x800445A4
    // 0x805617EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x805617EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_805617F0:
    // 0x805617F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805617F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805617F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805617FC: jr          $ra
    // 0x80561800: nop

    return;
    // 0x80561800: nop

;}
RECOMP_FUNC void func_8066DAE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066DAE0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8066DAE4: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(517, 0X538) << 16);
    // 0x8066DAE8: addiu       $t6, $t6, -0x2508
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(517, 0X538));
    // 0x8066DAEC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8066DAF0: jr          $ra
    // 0x8066DAF4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8066DAF4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_806F8EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8EB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F8EB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F8EB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806F8EBC: jal         0x80047090
    // 0x806F8EC0: addiu       $a0, $zero, 0x4300
    ctx->r4 = ADD32(0, 0X4300);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806F8EC0: addiu       $a0, $zero, 0x4300
    ctx->r4 = ADD32(0, 0X4300);
    after_0:
    // 0x806F8EC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F8EC8: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x806F8ECC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x806F8ED0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x806F8ED4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x806F8ED8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x806F8EDC: jal         0x8004613C
    // 0x806F8EE0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806F8EE0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x806F8EE4: beq         $v0, $zero, L_806F8F28
    if (ctx->r2 == 0) {
        // 0x806F8EE8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_806F8F28;
    }
    // 0x806F8EE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806F8EEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806F8EF0: jal         0x80047F9C
    // 0x806F8EF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806F8EF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x806F8EF8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806F8EFC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806F8F00: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806F8F04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806F8F08: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B58) << 16);
    // 0x806F8F0C: swc1        $f4, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f4.u32l;
    // 0x806F8F10: swc1        $f6, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f6.u32l;
    // 0x806F8F14: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x806F8F18: lwc1        $f8, -0x6C98($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B58));
    // 0x806F8F1C: lwc1        $f10, 0x8C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X8C);
    // 0x806F8F20: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806F8F24: swc1        $f16, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f16.u32l;
L_806F8F28:
    // 0x806F8F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F8F2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F8F30: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x806F8F34: jr          $ra
    // 0x806F8F38: nop

    return;
    // 0x806F8F38: nop

;}
RECOMP_FUNC void func_8070CD98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070CD98: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8070CD9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8070CDA0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8070CDA4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070CDA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8070CDAC: jal         0x8070CC68
    // 0x8070CDB0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_8070CC68(rdram, ctx);
        goto after_0;
    // 0x8070CDB0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8070CDB4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8070CDB8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8070CDBC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8070CDC0: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD60) << 16);
    // 0x8070CDC4: lwc1        $f6, -0x2C10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD60));
    // 0x8070CDC8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8070CDCC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8070CDD0: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8070CDD4: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8070CDD8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8070CDDC: nop

    // 0x8070CDE0: bc1fl       L_8070CDF4
    if (!c1cs) {
        // 0x8070CDE4: lwc1        $f10, 0x50($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
            goto L_8070CDF4;
    }
    goto skip_0;
    // 0x8070CDE4: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    skip_0:
    // 0x8070CDE8: swc1        $f2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f2.u32l;
    // 0x8070CDEC: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8070CDF0: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
L_8070CDF4:
    // 0x8070CDF4: jal         0x800659EC
    // 0x8070CDF8: add.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f0.fl;
    func_800659EC(rdram, ctx);
        goto after_1;
    // 0x8070CDF8: add.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f0.fl;
    after_1:
    // 0x8070CDFC: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8070CE00: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8070CE04: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8070CE08: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    // 0x8070CE0C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8070CE10: lw          $t8, 0x70($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X70);
    // 0x8070CE14: beq         $t8, $zero, L_8070CEC8
    if (ctx->r24 == 0) {
        // 0x8070CE18: nop
    
            goto L_8070CEC8;
    }
    // 0x8070CE18: nop

    // 0x8070CE1C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8070CE20: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8070CE24: jal         0x8070C798
    // 0x8070CE28: nop

    func_8070C798(rdram, ctx);
        goto after_2;
    // 0x8070CE28: nop

    after_2:
    // 0x8070CE2C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8070CE30: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8070CE34: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8070CE38: jal         0x8070C798
    // 0x8070CE3C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_8070C798(rdram, ctx);
        goto after_3;
    // 0x8070CE3C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8070CE40: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8070CE44: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8070CE48: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD64) << 16);
    // 0x8070CE4C: lwc1        $f14, -0x2C0C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD64));
    // 0x8070CE50: jal         0x8070C798
    // 0x8070CE54: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_8070C798(rdram, ctx);
        goto after_4;
    // 0x8070CE54: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8070CE58: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8070CE5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8070CE60: jal         0x8070C714
    // 0x8070CE64: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8070C714(rdram, ctx);
        goto after_5;
    // 0x8070CE64: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_5:
    // 0x8070CE68: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8070CE6C: lui         $t0, 0x8071
    ctx->r8 = S32(RELOC_HI16(721, 0XCC4) << 16);
    // 0x8070CE70: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8070CE74: lw          $t0, -0x2CAC($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(721, 0XCC4));
    // 0x8070CE78: lwc1        $f18, 0x84($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8070CE7C: lwc1        $f8, 0x8C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8070CE80: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8070CE84: lw          $t1, -0x76F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76F8);
    // 0x8070CE88: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8070CE8C: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8070CE90: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD68) << 16);
    // 0x8070CE94: lwc1        $f10, -0x2C08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD68));
    // 0x8070CE98: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8070CE9C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8070CEA0: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x8070CEA4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8070CEA8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8070CEAC: lw          $t9, 0x70($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X70);
    // 0x8070CEB0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8070CEB4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8070CEB8: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8070CEBC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8070CEC0: jalr        $t9
    // 0x8070CEC4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x8070CEC4: nop

    after_6:
L_8070CEC8:
    // 0x8070CEC8: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD6C) << 16);
    // 0x8070CECC: lwc1        $f4, -0x2C04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD6C));
    // 0x8070CED0: lwc1        $f18, 0xC8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8070CED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070CED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070CEDC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8070CEE0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8070CEE4: bc1fl       L_8070CEF8
    if (!c1cs) {
        // 0x8070CEE8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8070CEF8;
    }
    goto skip_1;
    // 0x8070CEE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8070CEEC: jal         0x8070D208
    // 0x8070CEF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8070D208(rdram, ctx);
        goto after_7;
    // 0x8070CEF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8070CEF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8070CEF8:
    // 0x8070CEF8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8070CEFC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8070CF00: jr          $ra
    // 0x8070CF04: nop

    return;
    // 0x8070CF04: nop

;}
RECOMP_FUNC void func_80072668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072668: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007266C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072670: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80072674: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80072678: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007267C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80072680: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80072684: addiu       $s0, $s0, -0x5968
    ctx->r16 = ADD32(ctx->r16, -0X5968);
    // 0x80072688: addiu       $s1, $sp, 0x24
    ctx->r17 = ADD32(ctx->r29, 0X24);
    // 0x8007268C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80072690:
    // 0x80072690: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80072694: jal         0x800824B0
    // 0x80072698: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80072698: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007269C: jal         0x80072534
    // 0x800726A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80072534(rdram, ctx);
        goto after_1;
    // 0x800726A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800726A4: b           L_80072690
    // 0x800726A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80072690;
    // 0x800726A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800726AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800726B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800726B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800726B8: jr          $ra
    // 0x800726BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800726BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_804BC86C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BC86C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x804BC870: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x804BC874: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x804BC878: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x804BC87C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x804BC880: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x804BC884: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x804BC888: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x804BC88C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x804BC890: addiu       $s0, $a0, 0x2D0
    ctx->r16 = ADD32(ctx->r4, 0X2D0);
    // 0x804BC894: lwc1        $f26, 0x364($a0)
    ctx->f26.u32l = MEM_W(ctx->r4, 0X364);
    // 0x804BC898: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x804BC89C: addiu       $s2, $zero, 0x15
    ctx->r18 = ADD32(0, 0X15);
L_804BC8A0:
    // 0x804BC8A0: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x804BC8A4: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x804BC8A8: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x804BC8AC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x804BC8B0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x804BC8B4: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804BC8B8: jal         0x80066E88
    // 0x804BC8BC: cvt.s.w     $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    ctx->f24.fl = CVT_S_W(ctx->f6.u32l);
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x804BC8BC: cvt.s.w     $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    ctx->f24.fl = CVT_S_W(ctx->f6.u32l);
    after_0:
    // 0x804BC8C0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x804BC8C4: jal         0x80066DE4
    // 0x804BC8C8: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x804BC8C8: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_1:
    // 0x804BC8CC: mul.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x804BC8D0: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x804BC8D4: mul.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x804BC8D8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804BC8DC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804BC8E0: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x804BC8E4: jal         0x80066DE4
    // 0x804BC8E8: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x804BC8E8: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    after_2:
    // 0x804BC8EC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x804BC8F0: jal         0x80066E88
    // 0x804BC8F4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x804BC8F4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_3:
    // 0x804BC8F8: mul.s       $f4, $f0, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x804BC8FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x804BC900: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x804BC904: mul.s       $f6, $f20, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x804BC908: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x804BC90C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804BC910: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x804BC914: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x804BC918: bne         $s1, $s2, L_804BC8A0
    if (ctx->r17 != ctx->r18) {
        // 0x804BC91C: sh          $t1, -0x4($s0)
        MEM_H(-0X4, ctx->r16) = ctx->r9;
            goto L_804BC8A0;
    }
    // 0x804BC91C: sh          $t1, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r9;
    // 0x804BC920: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x804BC924: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x804BC928: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x804BC92C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x804BC930: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x804BC934: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x804BC938: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x804BC93C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x804BC940: jr          $ra
    // 0x804BC944: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x804BC944: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800380C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800380C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800380C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800380C8: jal         0x80021958
    // 0x800380CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x800380CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800380D0: bne         $v0, $zero, L_800380E0
    if (ctx->r2 != 0) {
        // 0x800380D4: nop
    
            goto L_800380E0;
    }
    // 0x800380D4: nop

    // 0x800380D8: b           L_80038114
    // 0x800380DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038114;
    // 0x800380DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800380E0:
    // 0x800380E0: jal         0x800415FC
    // 0x800380E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x800380E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800380E8: beq         $v0, $zero, L_800380F8
    if (ctx->r2 == 0) {
        // 0x800380EC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800380F8;
    }
    // 0x800380EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800380F0: b           L_80038114
    // 0x800380F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038114;
    // 0x800380F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800380F8:
    // 0x800380F8: jal         0x800376A4
    // 0x800380FC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800376A4(rdram, ctx);
        goto after_2;
    // 0x800380FC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80038100: bnel        $v0, $zero, L_80038114
    if (ctx->r2 != 0) {
        // 0x80038104: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80038114;
    }
    goto skip_0;
    // 0x80038104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80038108: b           L_80038114
    // 0x8003810C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038114;
    // 0x8003810C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80038110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80038114:
    // 0x80038114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003811C: jr          $ra
    // 0x80038120: nop

    return;
    // 0x80038120: nop

;}
RECOMP_FUNC void func_8076084C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076084C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80760850: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80760854: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80760858: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8076085C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80760860: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80760864: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80760868: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8076086C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80760870: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80760874: jr          $ra
    // 0x80760878: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80760878: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x8076087C: nop

;}
RECOMP_FUNC void func_804C60B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C60B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C60B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C60BC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804C60C0: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804C60C4: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(218, 0X47C) << 16);
    // 0x804C60C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C60CC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804C60D0: lw          $t8, 0x63FC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(218, 0X47C));
    // 0x804C60D4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804C60D8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804C60DC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804C60E0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804C60E4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804C60E8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804C60EC: beql        $v1, $zero, L_804C6120
    if (ctx->r3 == 0) {
        // 0x804C60F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C6120;
    }
    goto skip_0;
    // 0x804C60F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C60F4: jalr        $v1
    // 0x804C60F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804C60F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C60FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C6100: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804C6104: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804C6108: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804C610C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804C6110: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804C6114: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804C6118: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804C611C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C6120:
    // 0x804C6120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C6124: jr          $ra
    // 0x804C6128: nop

    return;
    // 0x804C6128: nop

;}
RECOMP_FUNC void func_807AD97C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AD97C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AD980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AD984: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807AD988: jal         0x80045A34
    // 0x807AD98C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807AD98C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x807AD990: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AD994: bne         $v0, $zero, L_807AD9A4
    if (ctx->r2 != 0) {
        // 0x807AD998: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_807AD9A4;
    }
    // 0x807AD998: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x807AD99C: b           L_807AD9B0
    // 0x807AD9A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807AD9B0;
    // 0x807AD9A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807AD9A4:
    // 0x807AD9A4: jal         0x807AD960
    // 0x807AD9A8: nop

    func_807AD960(rdram, ctx);
        goto after_1;
    // 0x807AD9A8: nop

    after_1:
    // 0x807AD9AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807AD9B0:
    // 0x807AD9B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AD9B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AD9B8: jr          $ra
    // 0x807AD9BC: nop

    return;
    // 0x807AD9BC: nop

;}
RECOMP_FUNC void func_8001CBB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CBB8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001CBBC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001CBC0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8001CBC4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8001CBC8: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x8001CBCC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001CBD0: lw          $t7, -0x6990($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6990);
    // 0x8001CBD4: jr          $ra
    // 0x8001CBD8: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x8001CBD8: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80033AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033AEC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80033AF0: lwc1        $f14, 0xC4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x80033AF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80033AF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033AFC: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x80033B00: nop

    // 0x80033B04: bc1fl       L_80033B34
    if (!c1cs) {
        // 0x80033B08: lwc1        $f8, 0x64($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X64);
            goto L_80033B34;
    }
    goto skip_0;
    // 0x80033B08: lwc1        $f8, 0x64($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X64);
    skip_0:
    // 0x80033B0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80033B10: nop

    // 0x80033B14: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x80033B18: nop

    // 0x80033B1C: bc1fl       L_80033B34
    if (!c1cs) {
        // 0x80033B20: lwc1        $f8, 0x64($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X64);
            goto L_80033B34;
    }
    goto skip_1;
    // 0x80033B20: lwc1        $f8, 0x64($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X64);
    skip_1:
    // 0x80033B24: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80033B28: b           L_80033B6C
    // 0x80033B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80033B6C;
    // 0x80033B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033B30: lwc1        $f8, 0x64($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X64);
L_80033B34:
    // 0x80033B34: lwc1        $f12, 0xC8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0XC8);
    // 0x80033B38: mul.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80033B3C: jal         0x80081E8C
    // 0x80033B40: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    fatan2(rdram, ctx);
        goto after_0;
    // 0x80033B40: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_0:
    // 0x80033B44: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80033B48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80033B4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80033B50: lwc1        $f18, 0x84($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X84);
    // 0x80033B54: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80033B58: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80033B5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80033B60: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80033B64: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80033B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80033B6C:
    // 0x80033B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033B70: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80033B74: jr          $ra
    // 0x80033B78: nop

    return;
    // 0x80033B78: nop

;}
RECOMP_FUNC void guMtxXFMF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B340: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008B344: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8008B348: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8008B34C: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8008B350: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8008B354: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x8008B358: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8008B35C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8008B360: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8008B364: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8008B368: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8008B36C: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8008B370: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8008B374: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8008B378: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x8008B37C: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8008B380: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8008B384: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x8008B388: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8008B38C: lwc1        $f18, 0x24($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8008B390: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8008B394: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8008B398: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8008B39C: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8008B3A0: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8008B3A4: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8008B3A8: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x8008B3AC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8008B3B0: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8008B3B4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008B3B8: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8008B3BC: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8008B3C0: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8008B3C4: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8008B3C8: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8008B3CC: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8008B3D0: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8008B3D4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8008B3D8: jr          $ra
    // 0x8008B3DC: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    return;
    // 0x8008B3DC: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_805689EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805689EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805689F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805689F4: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805689F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805689FC: addiu       $at, $zero, 0x4152
    ctx->r1 = ADD32(0, 0X4152);
    // 0x80568A00: beq         $v0, $at, L_80568A24
    if (ctx->r2 == ctx->r1) {
        // 0x80568A04: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80568A24;
    }
    // 0x80568A04: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80568A08: addiu       $at, $zero, 0x415E
    ctx->r1 = ADD32(0, 0X415E);
    // 0x80568A0C: beq         $v0, $at, L_80568A34
    if (ctx->r2 == ctx->r1) {
        // 0x80568A10: addiu       $at, $zero, 0x416A
        ctx->r1 = ADD32(0, 0X416A);
            goto L_80568A34;
    }
    // 0x80568A10: addiu       $at, $zero, 0x416A
    ctx->r1 = ADD32(0, 0X416A);
    // 0x80568A14: beql        $v0, $at, L_80568A48
    if (ctx->r2 == ctx->r1) {
        // 0x80568A18: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80568A48;
    }
    goto skip_0;
    // 0x80568A18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80568A1C: b           L_80568A54
    // 0x80568A20: nop

        goto L_80568A54;
    // 0x80568A20: nop

L_80568A24:
    // 0x80568A24: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80568A28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80568A2C: b           L_80568A54
    // 0x80568A30: swc1        $f4, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f4.u32l;
        goto L_80568A54;
    // 0x80568A30: swc1        $f4, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f4.u32l;
L_80568A34:
    // 0x80568A34: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21DC) << 16);
    // 0x80568A38: lwc1        $f6, -0x6874($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21DC));
    // 0x80568A3C: b           L_80568A54
    // 0x80568A40: swc1        $f6, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
        goto L_80568A54;
    // 0x80568A40: swc1        $f6, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
    // 0x80568A44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80568A48:
    // 0x80568A48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80568A4C: nop

    // 0x80568A50: swc1        $f8, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f8.u32l;
L_80568A54:
    // 0x80568A54: jal         0x80568710
    // 0x80568A58: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x80568A58: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80568A5C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80568A60: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80568A64: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80568A68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80568A6C: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21E0) << 16);
    // 0x80568A70: sw          $zero, 0x24($a2)
    MEM_W(0X24, ctx->r6) = 0;
    // 0x80568A74: swc1        $f10, 0xC8($a2)
    MEM_W(0XC8, ctx->r6) = ctx->f10.u32l;
    // 0x80568A78: swc1        $f16, 0xE0($a2)
    MEM_W(0XE0, ctx->r6) = ctx->f16.u32l;
    // 0x80568A7C: lwc1        $f18, -0x6870($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21E0));
    // 0x80568A80: lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F4);
    // 0x80568A84: lwc1        $f4, 0x40($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X40);
    // 0x80568A88: swc1        $f18, 0xEC($a2)
    MEM_W(0XEC, ctx->r6) = ctx->f18.u32l;
    // 0x80568A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80568A90: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80568A94: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    // 0x80568A98: jal         0x80048F84
    // 0x80568A9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80568A9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80568AA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80568AA4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80568AA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80568AAC: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80568AB0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80568AB4: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80568AB8: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80568ABC: jal         0x80569310
    // 0x80568AC0: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    func_80569310(rdram, ctx);
        goto after_2;
    // 0x80568AC0: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    after_2:
    // 0x80568AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80568AC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80568ACC: jr          $ra
    // 0x80568AD0: nop

    return;
    // 0x80568AD0: nop

;}
RECOMP_FUNC void func_80474D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474D60: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474D64: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474D68: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474D6C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474D70: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474D74: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474D78: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474D7C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474D80: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474D84: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474D88: jr          $ra
    // 0x80474D8C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474D8C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80582358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582358: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8058235C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80582360: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80582364: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80582368: jal         0x8057EF14
    // 0x8058236C: addiu       $a1, $zero, 0x40F1
    ctx->r5 = ADD32(0, 0X40F1);
    func_8057EF14(rdram, ctx);
        goto after_0;
    // 0x8058236C: addiu       $a1, $zero, 0x40F1
    ctx->r5 = ADD32(0, 0X40F1);
    after_0:
    // 0x80582370: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80582374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582378: jal         0x8057EF14
    // 0x8058237C: addiu       $a1, $zero, 0x40F2
    ctx->r5 = ADD32(0, 0X40F2);
    func_8057EF14(rdram, ctx);
        goto after_1;
    // 0x8058237C: addiu       $a1, $zero, 0x40F2
    ctx->r5 = ADD32(0, 0X40F2);
    after_1:
    // 0x80582380: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80582384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582388: jal         0x8057EF14
    // 0x8058238C: addiu       $a1, $zero, 0x4021
    ctx->r5 = ADD32(0, 0X4021);
    func_8057EF14(rdram, ctx);
        goto after_2;
    // 0x8058238C: addiu       $a1, $zero, 0x4021
    ctx->r5 = ADD32(0, 0X4021);
    after_2:
    // 0x80582390: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80582394: jal         0x80580C70
    // 0x80582398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80580C70(rdram, ctx);
        goto after_3;
    // 0x80582398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8058239C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x805823A0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x805823A4: beql        $t6, $zero, L_8058244C
    if (ctx->r14 == 0) {
        // 0x805823A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8058244C;
    }
    goto skip_0;
    // 0x805823A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805823AC: beq         $t7, $zero, L_80582448
    if (ctx->r15 == 0) {
        // 0x805823B0: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_80582448;
    }
    // 0x805823B0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x805823B4: beql        $t8, $zero, L_8058244C
    if (ctx->r24 == 0) {
        // 0x805823B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8058244C;
    }
    goto skip_1;
    // 0x805823B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805823BC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x805823C0: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x805823C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x805823C8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805823CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805823D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805823D4: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x805823D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805823DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805823E0: bc1f        L_80582430
    if (!c1cs) {
        // 0x805823E4: nop
    
            goto L_80582430;
    }
    // 0x805823E4: nop

    // 0x805823E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805823EC: nop

    // 0x805823F0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x805823F4: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x805823F8: jal         0x80582144
    // 0x805823FC: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    func_80582144(rdram, ctx);
        goto after_4;
    // 0x805823FC: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    after_4:
    // 0x80582400: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80582404: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80582408: subu        $v1, $t9, $v0
    ctx->r3 = SUB32(ctx->r25, ctx->r2);
    // 0x8058240C: lw          $t1, 0x16C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X16C);
    // 0x80582410: sb          $v1, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r3;
    // 0x80582414: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80582418: lw          $t3, 0x16C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X16C);
    // 0x8058241C: sb          $v1, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r3;
    // 0x80582420: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80582424: lw          $t5, 0x16C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X16C);
    // 0x80582428: b           L_80582448
    // 0x8058242C: sb          $v1, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r3;
        goto L_80582448;
    // 0x8058242C: sb          $v1, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r3;
L_80582430:
    // 0x80582430: jal         0x80582498
    // 0x80582434: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80582498(rdram, ctx);
        goto after_5;
    // 0x80582434: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_5:
    // 0x80582438: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8058243C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80582440: nop

    // 0x80582444: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_80582448:
    // 0x80582448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8058244C:
    // 0x8058244C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80582450: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80582454: jr          $ra
    // 0x80582458: nop

    return;
    // 0x80582458: nop

;}
RECOMP_FUNC void func_8001FDE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FDE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001FDEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001FDF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001FDF4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001FDF8: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x8001FDFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001FE00: slti        $at, $t6, 0x9
    ctx->r1 = SIGNED(ctx->r14) < 0X9 ? 1 : 0;
    // 0x8001FE04: beql        $at, $zero, L_8001FF04
    if (ctx->r1 == 0) {
        // 0x8001FE08: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001FF04;
    }
    goto skip_0;
    // 0x8001FE08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8001FE0C: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8001FE10: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8001FE14: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8001FE18: lbu         $t8, 0xF5($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XF5);
    // 0x8001FE1C: beql        $t8, $zero, L_8001FE38
    if (ctx->r24 == 0) {
        // 0x8001FE20: lw          $t9, 0x174($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X174);
            goto L_8001FE38;
    }
    goto skip_1;
    // 0x8001FE20: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    skip_1:
    // 0x8001FE24: jal         0x80034160
    // 0x8001FE28: nop

    func_80034160(rdram, ctx);
        goto after_0;
    // 0x8001FE28: nop

    after_0:
    // 0x8001FE2C: b           L_8001FE50
    // 0x8001FE30: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
        goto L_8001FE50;
    // 0x8001FE30: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x8001FE34: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
L_8001FE38:
    // 0x8001FE38: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8001FE3C: beql        $t0, $zero, L_8001FE50
    if (ctx->r8 == 0) {
        // 0x8001FE40: lbu         $v0, 0x30($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X30);
            goto L_8001FE50;
    }
    goto skip_2;
    // 0x8001FE40: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    skip_2:
    // 0x8001FE44: jal         0x80061170
    // 0x8001FE48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80061170(rdram, ctx);
        goto after_1;
    // 0x8001FE48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8001FE4C: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
L_8001FE50:
    // 0x8001FE50: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8001FE54: beq         $v0, $at, L_8001FE64
    if (ctx->r2 == ctx->r1) {
        // 0x8001FE58: addiu       $at, $zero, 0x23
        ctx->r1 = ADD32(0, 0X23);
            goto L_8001FE64;
    }
    // 0x8001FE58: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x8001FE5C: bne         $v0, $at, L_8001FE6C
    if (ctx->r2 != ctx->r1) {
        // 0x8001FE60: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_8001FE6C;
    }
    // 0x8001FE60: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
L_8001FE64:
    // 0x8001FE64: b           L_8001FF04
    // 0x8001FE68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8001FF04;
    // 0x8001FE68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001FE6C:
    // 0x8001FE6C: lbu         $t2, 0xF4($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XF4);
    // 0x8001FE70: beql        $t2, $zero, L_8001FF04
    if (ctx->r10 == 0) {
        // 0x8001FE74: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001FF04;
    }
    goto skip_3;
    // 0x8001FE74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x8001FE78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001FE7C: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8001FE80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001FE84: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8001FE88: nop

    // 0x8001FE8C: bc1fl       L_8001FF04
    if (!c1cs) {
        // 0x8001FE90: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001FF04;
    }
    goto skip_4;
    // 0x8001FE90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x8001FE94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001FE98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001FE9C: jal         0x8002DBA8
    // 0x8001FEA0: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
    func_8002DBA8(rdram, ctx);
        goto after_2;
    // 0x8001FEA0: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
    after_2:
    // 0x8001FEA4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8001FEA8: jal         0x800413C8
    // 0x8001FEAC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800413C8(rdram, ctx);
        goto after_3;
    // 0x8001FEAC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x8001FEB0: jal         0x8001D770
    // 0x8001FEB4: nop

    func_8001D770(rdram, ctx);
        goto after_4;
    // 0x8001FEB4: nop

    after_4:
    // 0x8001FEB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001FEBC: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8001FEC0: jal         0x80067BF8
    // 0x8001FEC4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_5;
    // 0x8001FEC4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x8001FEC8: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    // 0x8001FECC: jal         0x80067818
    // 0x8001FED0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8001FED0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8001FED4: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x8001FED8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8001FEDC: sb          $t3, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r11;
    // 0x8001FEE0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8001FEE4: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8001FEE8: sb          $t4, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r12;
    // 0x8001FEEC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8001FEF0: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8001FEF4: sb          $t5, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r13;
    // 0x8001FEF8: b           L_8001FF04
    // 0x8001FEFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001FF04;
    // 0x8001FEFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001FF00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001FF04:
    // 0x8001FF04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001FF08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001FF0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001FF10: jr          $ra
    // 0x8001FF14: nop

    return;
    // 0x8001FF14: nop

;}
RECOMP_FUNC void func_804C612C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C612C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804C6130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C6134: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C6138: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804C613C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C6140: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x804C6144: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x804C6148: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804C614C: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x804C6150: jal         0x80059278
    // 0x804C6154: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80059278(rdram, ctx);
        goto after_0;
    // 0x804C6154: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C6158: bne         $v0, $zero, L_804C6170
    if (ctx->r2 != 0) {
        // 0x804C615C: lw          $a2, 0x38($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X38);
            goto L_804C6170;
    }
    // 0x804C615C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x804C6160: jal         0x800447C8
    // 0x804C6164: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x804C6164: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x804C6168: b           L_804C6248
    // 0x804C616C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804C6248;
    // 0x804C616C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C6170:
    // 0x804C6170: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804C6174: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(218, 0X4A0) << 16);
    // 0x804C6178: lwc1        $f10, 0x6420($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(218, 0X4A0));
    // 0x804C617C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804C6180: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(218, 0X4A4) << 16);
    // 0x804C6184: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x804C6188: nop

    // 0x804C618C: bc1tl       L_804C6234
    if (c1cs) {
        // 0x804C6190: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_804C6234;
    }
    goto skip_0;
    // 0x804C6190: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x804C6194: lwc1        $f16, 0x6424($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(218, 0X4A4));
    // 0x804C6198: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x804C619C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x804C61A0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x804C61A4: nop

    // 0x804C61A8: bc1tl       L_804C6234
    if (c1cs) {
        // 0x804C61AC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_804C6234;
    }
    goto skip_1;
    // 0x804C61AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x804C61B0: jal         0x80047AB8
    // 0x804C61B4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x804C61B4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_2:
    // 0x804C61B8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x804C61BC: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(218, 0X4A8) << 16);
    // 0x804C61C0: lwc1        $f0, 0x6428($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(218, 0X4A8));
    // 0x804C61C4: lwc1        $f18, 0x6C($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x804C61C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C61CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804C61D0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x804C61D4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(218, 0X4AC) << 16);
    // 0x804C61D8: lwc1        $f18, 0x642C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(218, 0X4AC));
    // 0x804C61DC: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804C61E0: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x804C61E4: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x804C61E8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x804C61EC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x804C61F0: lwc1        $f6, 0x70($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X70);
    // 0x804C61F4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x804C61F8: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x804C61FC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x804C6200: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x804C6204: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x804C6208: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x804C620C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x804C6210: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x804C6214: jalr        $t9
    // 0x804C6218: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x804C6218: nop

    after_3:
    // 0x804C621C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x804C6220: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C6224: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x804C6228: b           L_804C6244
    // 0x804C622C: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
        goto L_804C6244;
    // 0x804C622C: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x804C6230: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_804C6234:
    // 0x804C6234: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804C6238: nop

    // 0x804C623C: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x804C6240: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_804C6244:
    // 0x804C6244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C6248:
    // 0x804C6248: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804C624C: jr          $ra
    // 0x804C6250: nop

    return;
    // 0x804C6250: nop

;}
RECOMP_FUNC void func_807BC5C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC5C0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807BC5C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807BC5C8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807BC5CC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807BC5D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807BC5D4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807BC5D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807BC5DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807BC5E0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807BC5E4: lui         $t1, 0x807C
    ctx->r9 = S32(RELOC_HI16(898, 0X6E58) << 16);
    // 0x807BC5E8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807BC5EC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807BC5F0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807BC5F4: lw          $t1, 0x2B18($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(898, 0X6E58));
    // 0x807BC5F8: jr          $ra
    // 0x807BC5FC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807BC5FC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8079FFF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079FFF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8079FFF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079FFF8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8079FFFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x807A0000: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x807A0004: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x807A0008: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x807A000C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x807A0010: bnel        $v0, $at, L_807A0080
    if (ctx->r2 != ctx->r1) {
        // 0x807A0014: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807A0080;
    }
    goto skip_0;
    // 0x807A0014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807A0018: jal         0x8079FF78
    // 0x807A001C: nop

    func_8079FF78(rdram, ctx);
        goto after_0;
    // 0x807A001C: nop

    after_0:
    // 0x807A0020: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x807A0024: jal         0x8003E478
    // 0x807A0028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003E478(rdram, ctx);
        goto after_1;
    // 0x807A0028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x807A002C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x807A0030: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x807A0034: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807A0038: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x807A003C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x807A0040: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x807A0044: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x807A0048: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x807A004C: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x807A0050: jal         0x8002F96C
    // 0x807A0054: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_8002F96C(rdram, ctx);
        goto after_2;
    // 0x807A0054: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x807A0058: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x807A005C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807A0060: sb          $t7, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r15;
    // 0x807A0064: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807A0068: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x807A006C: sb          $t8, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r24;
    // 0x807A0070: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807A0074: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x807A0078: sb          $t9, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r25;
    // 0x807A007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A0080:
    // 0x807A0080: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807A0084: jr          $ra
    // 0x807A0088: nop

    return;
    // 0x807A0088: nop

;}
RECOMP_FUNC void func_80071C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071C94: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80071C98: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80071C9C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80071CA0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80071CA4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80071CA8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80071CAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80071CB0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80071CB4: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x80071CB8: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x80071CBC: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x80071CC0: addiu       $s2, $s2, -0x2710
    ctx->r18 = ADD32(ctx->r18, -0X2710);
    // 0x80071CC4: addiu       $s3, $s3, -0x59E0
    ctx->r19 = ADD32(ctx->r19, -0X59E0);
    // 0x80071CC8: addiu       $s4, $s4, -0x2790
    ctx->r20 = ADD32(ctx->r20, -0X2790);
    // 0x80071CCC: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x80071CD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80071CD4:
    // 0x80071CD4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80071CD8: jal         0x800824B0
    // 0x80071CDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80071CDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80071CE0: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80071CE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80071CE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80071CEC: jal         0x800824B0
    // 0x80071CF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80071CF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80071CF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80071CF8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80071CFC: jal         0x80082210
    // 0x80071D00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80071D00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80071D04: b           L_80071CD4
    // 0x80071D08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_80071CD4;
    // 0x80071D08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80071D0C: nop

    // 0x80071D10: nop

    // 0x80071D14: nop

    // 0x80071D18: nop

    // 0x80071D1C: nop

    // 0x80071D20: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80071D24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071D28: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80071D2C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80071D30: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80071D34: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80071D38: jr          $ra
    // 0x80071D3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80071D3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_804090E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804090E4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x804090E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804090EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804090F0: lui         $a3, 0x8041
    ctx->r7 = S32(RELOC_HI16(11, 0X2CD0) << 16);
    // 0x804090F4: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x804090F8: jal         0x80408F40
    // 0x804090FC: addiu       $a3, $a3, -0x5960
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(11, 0X2CD0));
    func_80408F40(rdram, ctx);
        goto after_0;
    // 0x804090FC: addiu       $a3, $a3, -0x5960
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(11, 0X2CD0));
    after_0:
    // 0x80409100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80409104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80409108: jr          $ra
    // 0x8040910C: nop

    return;
    // 0x8040910C: nop

;}
RECOMP_FUNC void func_80798DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798DB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80798DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80798DB8: jal         0x80798D3C
    // 0x80798DBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80798D3C(rdram, ctx);
        goto after_0;
    // 0x80798DBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80798DC0: bne         $v0, $zero, L_80798DD8
    if (ctx->r2 != 0) {
        // 0x80798DC4: nop
    
            goto L_80798DD8;
    }
    // 0x80798DC4: nop

    // 0x80798DC8: jal         0x800445A4
    // 0x80798DCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80798DCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80798DD0: b           L_80798DF4
    // 0x80798DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80798DF4;
    // 0x80798DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80798DD8:
    // 0x80798DD8: jal         0x80798D80
    // 0x80798DDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80798D80(rdram, ctx);
        goto after_2;
    // 0x80798DDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80798DE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80798DE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80798DE8: jal         0x80798E00
    // 0x80798DEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80798E00(rdram, ctx);
        goto after_3;
    // 0x80798DEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80798DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80798DF4:
    // 0x80798DF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80798DF8: jr          $ra
    // 0x80798DFC: nop

    return;
    // 0x80798DFC: nop

;}
RECOMP_FUNC void func_8006D508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D50C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006D514: addiu       $a1, $zero, 0xA94
    ctx->r5 = ADD32(0, 0XA94);
    // 0x8006D518: jal         0x80065728
    // 0x8006D51C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8006D51C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8006D520: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006D524: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8006D528: addiu       $t6, $a0, 0x12C
    ctx->r14 = ADD32(ctx->r4, 0X12C);
    // 0x8006D52C: addiu       $t7, $a0, 0x134
    ctx->r15 = ADD32(ctx->r4, 0X134);
    // 0x8006D530: addiu       $t9, $a0, 0x128
    ctx->r25 = ADD32(ctx->r4, 0X128);
    // 0x8006D534: sw          $t6, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->r14;
    // 0x8006D538: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    // 0x8006D53C: sb          $t8, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r24;
    // 0x8006D540: sw          $t9, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r25;
    // 0x8006D544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D548: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D54C: jr          $ra
    // 0x8006D550: nop

    return;
    // 0x8006D550: nop

;}
RECOMP_FUNC void func_80430838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430838: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043083C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80430840: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80430844: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80430848: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8043084C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80430850: jal         0x80047090
    // 0x80430854: addiu       $a0, $zero, 0x408C
    ctx->r4 = ADD32(0, 0X408C);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80430854: addiu       $a0, $zero, 0x408C
    ctx->r4 = ADD32(0, 0X408C);
    after_0:
    // 0x80430858: lui         $at, 0x408C
    ctx->r1 = S32(0X408C << 16);
    // 0x8043085C: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x80430860: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x80430864: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80430868: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8043086C: jal         0x8004613C
    // 0x80430870: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80430870: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80430874: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80430878: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x8043087C: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x80430880: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80430884: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x80430888: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8043088C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80430890: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    // 0x80430894: lwc1        $f4, 0x6C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x80430898: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8043089C: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    // 0x804308A0: lwc1        $f6, 0x70($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X70);
    // 0x804308A4: swc1        $f6, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f6.u32l;
    // 0x804308A8: lwc1        $f8, 0x74($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X74);
    // 0x804308AC: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
    // 0x804308B0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x804308B4: jal         0x80044194
    // 0x804308B8: sw          $t2, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->r10;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x804308B8: sw          $t2, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->r10;
    after_2:
    // 0x804308BC: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x804308C0: lui         $t3, 0x8043
    ctx->r11 = S32(RELOC_HI16(56, 0X2604) << 16);
    // 0x804308C4: addiu       $t3, $t3, 0x6E4
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(56, 0X2604));
    // 0x804308C8: sw          $t3, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r11;
    // 0x804308CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804308D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804308D4: jr          $ra
    // 0x804308D8: nop

    return;
    // 0x804308D8: nop

;}
RECOMP_FUNC void func_8005F2CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F2CC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8005F2D0: lh          $t6, 0x96($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X96);
    // 0x8005F2D4: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
    // 0x8005F2D8: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8005F2DC: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8005F2E0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8005F2E4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8005F2E8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8005F2EC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8005F2F0: sll         $fp, $t6, 4
    ctx->r30 = S32(ctx->r14 << 4);
    // 0x8005F2F4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8005F2F8: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8005F2FC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8005F300: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8005F304: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8005F308: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8005F30C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8005F310: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8005F314: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005F318: sw          $fp, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r30;
    // 0x8005F31C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x8005F320: lh          $s3, 0x92($sp)
    ctx->r19 = MEM_H(ctx->r29, 0X92);
    // 0x8005F324: blez        $v0, L_8005F3C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005F328: sw          $zero, 0x70($sp)
        MEM_W(0X70, ctx->r29) = 0;
            goto L_8005F3C4;
    }
    // 0x8005F328: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8005F32C: lw          $s7, 0x88($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X88);
L_8005F330:
    // 0x8005F330: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8005F334: lh          $s0, 0x8E($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X8E);
    // 0x8005F338: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005F33C: blezl       $t8, L_8005F3AC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005F340: lw          $t4, 0x70($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X70);
            goto L_8005F3AC;
    }
    goto skip_0;
    // 0x8005F340: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    skip_0:
L_8005F344:
    // 0x8005F344: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x8005F348: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8005F34C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8005F350: andi        $t9, $v1, 0x8000
    ctx->r25 = ctx->r3 & 0X8000;
    // 0x8005F354: beq         $t9, $zero, L_8005F370
    if (ctx->r25 == 0) {
        // 0x8005F358: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8005F370;
    }
    // 0x8005F358: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005F35C: lhu         $t0, 0x0($s7)
    ctx->r8 = MEM_HU(ctx->r23, 0X0);
    // 0x8005F360: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8005F364: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x8005F368: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8005F36C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
L_8005F370:
    // 0x8005F370: sll         $t1, $v0, 8
    ctx->r9 = S32(ctx->r2 << 8);
    // 0x8005F374: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8005F378: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8005F37C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8005F380: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8005F384: addu        $a2, $t1, $s6
    ctx->r6 = ADD32(ctx->r9, ctx->r22);
    // 0x8005F388: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8005F38C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005F390: jal         0x80073D58
    // 0x8005F394: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_80073D58(rdram, ctx);
        goto after_0;
    // 0x8005F394: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_0:
    // 0x8005F398: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8005F39C: slt         $at, $s1, $fp
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x8005F3A0: bne         $at, $zero, L_8005F344
    if (ctx->r1 != 0) {
        // 0x8005F3A4: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_8005F344;
    }
    // 0x8005F3A4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8005F3A8: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
L_8005F3AC:
    // 0x8005F3AC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8005F3B0: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x8005F3B4: addiu       $t5, $t4, 0x10
    ctx->r13 = ADD32(ctx->r12, 0X10);
    // 0x8005F3B8: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8005F3BC: bne         $at, $zero, L_8005F330
    if (ctx->r1 != 0) {
        // 0x8005F3C0: sw          $t5, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r13;
            goto L_8005F330;
    }
    // 0x8005F3C0: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
L_8005F3C4:
    // 0x8005F3C4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F3C8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005F3CC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F3D0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8005F3D4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8005F3D8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8005F3DC: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8005F3E0: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8005F3E4: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8005F3E8: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8005F3EC: jr          $ra
    // 0x8005F3F0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8005F3F0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_8001C0B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C0B4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8001C0B8: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x8001C0BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C0C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C0C4: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8001C0C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001C0CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001C0D0: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8001C0D4: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8001C0D8: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001C0DC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001C0E0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8001C0E4: addiu       $a1, $a1, -0x3F54
    ctx->r5 = ADD32(ctx->r5, -0X3F54);
    // 0x8001C0E8: jal         0x8006E154
    // 0x8001C0EC: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    func_8006E154(rdram, ctx);
        goto after_0;
    // 0x8001C0EC: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    after_0:
    // 0x8001C0F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C0F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C0F8: jr          $ra
    // 0x8001C0FC: nop

    return;
    // 0x8001C0FC: nop

;}
RECOMP_FUNC void func_80441AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441AD8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80441ADC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80441AE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80441AE4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80441AE8: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80441AEC: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80441AF0: lwc1        $f4, 0x1C78($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C78);
    // 0x80441AF4: lwc1        $f8, 0x1C7C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C7C);
    // 0x80441AF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80441AFC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80441B00: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80441B04: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80441B08: jal         0x80440950
    // 0x80441B0C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_80440950(rdram, ctx);
        goto after_0;
    // 0x80441B0C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80441B10: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80441B14: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80441B18: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80441B1C: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80441B20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80441B24: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80441B28: nop

    // 0x80441B2C: bc1f        L_80441B7C
    if (!c1cs) {
        // 0x80441B30: nop
    
            goto L_80441B7C;
    }
    // 0x80441B30: nop

    // 0x80441B34: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80441B38: nop

    // 0x80441B3C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80441B40: nop

    // 0x80441B44: bc1f        L_80441B7C
    if (!c1cs) {
        // 0x80441B48: nop
    
            goto L_80441B7C;
    }
    // 0x80441B48: nop

    // 0x80441B4C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80441B50: nop

    // 0x80441B54: bc1f        L_80441B7C
    if (!c1cs) {
        // 0x80441B58: nop
    
            goto L_80441B7C;
    }
    // 0x80441B58: nop

    // 0x80441B5C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80441B60: nop

    // 0x80441B64: bc1f        L_80441B7C
    if (!c1cs) {
        // 0x80441B68: nop
    
            goto L_80441B7C;
    }
    // 0x80441B68: nop

    // 0x80441B6C: jal         0x8043F8C4
    // 0x80441B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F8C4(rdram, ctx);
        goto after_1;
    // 0x80441B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80441B74: b           L_80441BA8
    // 0x80441B78: nop

        goto L_80441BA8;
    // 0x80441B78: nop

L_80441B7C:
    // 0x80441B7C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EE0) << 16);
    // 0x80441B80: lwc1        $f12, 0x3DE0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EE0));
    // 0x80441B84: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80441B88: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80441B8C: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80441B90: nop

    // 0x80441B94: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80441B98: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80441B9C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80441BA0: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x80441BA4: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
L_80441BA8:
    // 0x80441BA8: jal         0x8043F33C
    // 0x80441BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F33C(rdram, ctx);
        goto after_2;
    // 0x80441BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80441BB0: jal         0x8043FEAC
    // 0x80441BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043FEAC(rdram, ctx);
        goto after_3;
    // 0x80441BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80441BB8: jal         0x8043F150
    // 0x80441BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F150(rdram, ctx);
        goto after_4;
    // 0x80441BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80441BC0: jal         0x8044045C
    // 0x80441BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044045C(rdram, ctx);
        goto after_5;
    // 0x80441BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80441BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80441BCC: jal         0x8043EF80
    // 0x80441BD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8043EF80(rdram, ctx);
        goto after_6;
    // 0x80441BD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80441BD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80441BD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80441BDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80441BE0: jr          $ra
    // 0x80441BE4: nop

    return;
    // 0x80441BE4: nop

;}
RECOMP_FUNC void func_80045414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045414: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80045418: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004541C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80045420: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x80045424: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80045428: beql        $t6, $zero, L_800454DC
    if (ctx->r14 == 0) {
        // 0x8004542C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800454DC;
    }
    goto skip_0;
    // 0x8004542C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80045430: jal         0x8005DAA4
    // 0x80045434: nop

    func_8005DAA4(rdram, ctx);
        goto after_0;
    // 0x80045434: nop

    after_0:
    // 0x80045438: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8004543C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80045440: sw          $t7, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r15;
    // 0x80045444: lbu         $t9, 0x164($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X164);
    // 0x80045448: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x8004544C: beq         $at, $zero, L_800454B8
    if (ctx->r1 == 0) {
        // 0x80045450: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800454B8;
    }
    // 0x80045450: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80045454: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80045458: addu        $at, $at, $t9
    gpr jr_addend_80045460 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8004545C: lw          $t9, 0x880($at)
    ctx->r25 = ADD32(ctx->r1, 0X880);
    // 0x80045460: jr          $t9
    // 0x80045464: nop

    switch (jr_addend_80045460 >> 2) {
        case 0: goto L_80045468; break;
        case 1: goto L_80045468; break;
        case 2: goto L_800454B8; break;
        case 3: goto L_80045478; break;
        case 4: goto L_80045498; break;
        case 5: goto L_80045488; break;
        default: switch_error(__func__, 0x80045460, 0x800B0880);
    }
    // 0x80045464: nop

L_80045468:
    // 0x80045468: jal         0x8004535C
    // 0x8004546C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004535C(rdram, ctx);
        goto after_1;
    // 0x8004546C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80045470: b           L_800454BC
    // 0x80045474: lbu         $t0, 0x5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X5);
        goto L_800454BC;
    // 0x80045474: lbu         $t0, 0x5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X5);
L_80045478:
    // 0x80045478: jal         0x80051E58
    // 0x8004547C: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    func_80051E58(rdram, ctx);
        goto after_2;
    // 0x8004547C: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    after_2:
    // 0x80045480: b           L_800454BC
    // 0x80045484: lbu         $t0, 0x5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X5);
        goto L_800454BC;
    // 0x80045484: lbu         $t0, 0x5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X5);
L_80045488:
    // 0x80045488: jal         0x8004F38C
    // 0x8004548C: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    func_8004F38C(rdram, ctx);
        goto after_3;
    // 0x8004548C: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    after_3:
    // 0x80045490: b           L_800454BC
    // 0x80045494: lbu         $t0, 0x5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X5);
        goto L_800454BC;
    // 0x80045494: lbu         $t0, 0x5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X5);
L_80045498:
    // 0x80045498: lw          $v1, 0x16C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X16C);
    // 0x8004549C: lw          $a0, 0x34($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X34);
    // 0x800454A0: jal         0x80064F94
    // 0x800454A4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80064F94(rdram, ctx);
        goto after_4;
    // 0x800454A4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x800454A8: beq         $v0, $zero, L_800454B8
    if (ctx->r2 == 0) {
        // 0x800454AC: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_800454B8;
    }
    // 0x800454AC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800454B0: jal         0x80064E84
    // 0x800454B4: lw          $a0, 0x34($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X34);
    func_80064E84(rdram, ctx);
        goto after_5;
    // 0x800454B4: lw          $a0, 0x34($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X34);
    after_5:
L_800454B8:
    // 0x800454B8: lbu         $t0, 0x5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X5);
L_800454BC:
    // 0x800454BC: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x800454C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800454C4: beql        $t0, $zero, L_800454D8
    if (ctx->r8 == 0) {
        // 0x800454C8: sw          $zero, 0x16C($s0)
        MEM_W(0X16C, ctx->r16) = 0;
            goto L_800454D8;
    }
    goto skip_1;
    // 0x800454C8: sw          $zero, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = 0;
    skip_1:
    // 0x800454CC: jal         0x80065728
    // 0x800454D0: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    func_80065728(rdram, ctx);
        goto after_6;
    // 0x800454D0: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    after_6:
    // 0x800454D4: sw          $zero, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = 0;
L_800454D8:
    // 0x800454D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800454DC:
    // 0x800454DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800454E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800454E4: jr          $ra
    // 0x800454E8: nop

    return;
    // 0x800454E8: nop

;}
RECOMP_FUNC void _bzero(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084820: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x80084824: bne         $at, $zero, L_8008489C
    if (ctx->r1 != 0) {
        // 0x80084828: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_8008489C;
    }
    // 0x80084828: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x8008482C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x80084830: beq         $v1, $zero, L_80084840
    if (ctx->r3 == 0) {
        // 0x80084834: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_80084840;
    }
    // 0x80084834: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x80084838: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x8008483C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_80084840:
    // 0x80084840: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x80084844: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80084848: beq         $a3, $zero, L_8008487C
    if (ctx->r7 == 0) {
        // 0x8008484C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8008487C;
    }
    // 0x8008484C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x80084850: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80084854:
    // 0x80084854: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80084858: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x8008485C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x80084860: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x80084864: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x80084868: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x8008486C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x80084870: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x80084874: bne         $a0, $a3, L_80084854
    if (ctx->r4 != ctx->r7) {
        // 0x80084878: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80084854;
    }
    // 0x80084878: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8008487C:
    // 0x8008487C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80084880: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80084884: beq         $a3, $zero, L_8008489C
    if (ctx->r7 == 0) {
        // 0x80084888: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8008489C;
    }
    // 0x80084888: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8008488C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80084890:
    // 0x80084890: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80084894: bne         $a0, $a3, L_80084890
    if (ctx->r4 != ctx->r7) {
        // 0x80084898: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80084890;
    }
    // 0x80084898: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8008489C:
    // 0x8008489C: blez        $a1, L_800848B4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800848A0: nop
    
            goto L_800848B4;
    }
    // 0x800848A0: nop

    // 0x800848A4: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_800848A8:
    // 0x800848A8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800848AC: bne         $a0, $a1, L_800848A8
    if (ctx->r4 != ctx->r5) {
        // 0x800848B0: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_800848A8;
    }
    // 0x800848B0: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_800848B4:
    // 0x800848B4: jr          $ra
    // 0x800848B8: nop

    return;
    // 0x800848B8: nop

;}
RECOMP_FUNC void func_806E9350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E9350: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16EC) << 16);
    // 0x806E9354: lwc1        $f2, -0x6664($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16EC));
    // 0x806E9358: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16F0) << 16);
    // 0x806E935C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x806E9360: lwc1        $f4, -0x6660($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16F0));
    // 0x806E9364: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x806E9368: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x806E936C: mul.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x806E9370: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806E9374: swc1        $f0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f0.u32l;
    // 0x806E9378: bc1fl       L_806E9388
    if (!c1cs) {
        // 0x806E937C: lwc1        $f8, 0x0($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
            goto L_806E9388;
    }
    goto skip_0;
    // 0x806E937C: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    skip_0:
    // 0x806E9380: swc1        $f2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f2.u32l;
    // 0x806E9384: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
L_806E9388:
    // 0x806E9388: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806E938C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806E9390: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x806E9394: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x806E9398: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806E939C: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x806E93A0: lwc1        $f18, 0x0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X0);
    // 0x806E93A4: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x806E93A8: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x806E93AC: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x806E93B0: nop

    // 0x806E93B4: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x806E93B8: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x806E93BC: lwc1        $f16, 0x0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X0);
    // 0x806E93C0: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x806E93C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x806E93C8: sub.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x806E93CC: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x806E93D0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x806E93D4: nop

    // 0x806E93D8: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x806E93DC: jr          $ra
    // 0x806E93E0: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x806E93E0: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_807926B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807926B4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x807926B8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x807926BC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x807926C0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x807926C4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x807926C8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x807926CC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x807926D0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x807926D4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x807926D8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x807926DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x807926E0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x807926E4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807926E8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x807926EC: lui         $s4, 0x800F
    ctx->r20 = S32(0X800F << 16);
    // 0x807926F0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x807926F4: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x807926F8: addiu       $s4, $s4, 0x7EA0
    ctx->r20 = ADD32(ctx->r20, 0X7EA0);
    // 0x807926FC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80792700: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x80792704: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x80792708: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x8079270C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80792710: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
L_80792714:
    // 0x80792714: lw          $t7, 0xED0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0XED0);
    // 0x80792718: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8079271C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80792720: addu        $t8, $t7, $fp
    ctx->r24 = ADD32(ctx->r15, ctx->r30);
    // 0x80792724: lw          $t9, 0x38($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X38);
    // 0x80792728: beql        $t9, $zero, L_807927A8
    if (ctx->r25 == 0) {
        // 0x8079272C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_807927A8;
    }
    goto skip_0;
    // 0x8079272C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
L_80792730:
    // 0x80792730: lw          $v1, 0xED0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XED0);
    // 0x80792734: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    // 0x80792738: subu        $t0, $t0, $s2
    ctx->r8 = SUB32(ctx->r8, ctx->r18);
    // 0x8079273C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80792740: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x80792744: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x80792748: lw          $v0, 0xC($t2)
    ctx->r2 = MEM_W(ctx->r10, 0XC);
    // 0x8079274C: slti        $at, $v0, 0x5A
    ctx->r1 = SIGNED(ctx->r2) < 0X5A ? 1 : 0;
    // 0x80792750: beql        $at, $zero, L_8079279C
    if (ctx->r1 == 0) {
        // 0x80792754: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8079279C;
    }
    goto skip_1;
    // 0x80792754: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80792758: blezl       $v0, L_8079279C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8079275C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8079279C;
    }
    goto skip_2;
    // 0x8079275C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x80792760: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x80792764: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80792768: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8079276C: jalr        $t9
    // 0x80792770: addiu       $a2, $zero, -0xC
    ctx->r6 = ADD32(0, -0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80792770: addiu       $a2, $zero, -0xC
    ctx->r6 = ADD32(0, -0XC);
    after_0:
    // 0x80792774: lwc1        $f4, 0x84($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X84);
    // 0x80792778: jal         0x80065954
    // 0x8079277C: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8079277C: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    after_1:
    // 0x80792780: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80792784: nop

    // 0x80792788: bc1fl       L_8079279C
    if (!c1cs) {
        // 0x8079278C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8079279C;
    }
    goto skip_3;
    // 0x8079278C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x80792790: or          $s6, $s2, $zero
    ctx->r22 = ctx->r18 | 0;
    // 0x80792794: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
    // 0x80792798: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8079279C:
    // 0x8079279C: bne         $s0, $s3, L_80792730
    if (ctx->r16 != ctx->r19) {
        // 0x807927A0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80792730;
    }
    // 0x807927A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807927A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_807927A8:
    // 0x807927A8: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x807927AC: bne         $at, $zero, L_80792714
    if (ctx->r1 != 0) {
        // 0x807927B0: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_80792714;
    }
    // 0x807927B0: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x807927B4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x807927B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807927BC: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x807927C0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x807927C4: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x807927C8: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x807927CC: bc1f        L_8079282C
    if (!c1cs) {
        // 0x807927D0: nop
    
            goto L_8079282C;
    }
    // 0x807927D0: nop

    // 0x807927D4: sw          $s6, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->r22;
    // 0x807927D8: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x807927DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x807927E0: sw          $s7, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r23;
    // 0x807927E4: lw          $t5, 0xED0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0XED0);
    // 0x807927E8: addu        $t6, $t5, $s6
    ctx->r14 = ADD32(ctx->r13, ctx->r22);
    // 0x807927EC: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x807927F0: beql        $t7, $zero, L_80792814
    if (ctx->r15 == 0) {
        // 0x807927F4: lw          $t0, 0x12C($s5)
        ctx->r8 = MEM_W(ctx->r21, 0X12C);
            goto L_80792814;
    }
    goto skip_4;
    // 0x807927F4: lw          $t0, 0x12C($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X12C);
    skip_4:
    // 0x807927F8: lw          $t8, 0x12C($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X12C);
    // 0x807927FC: bne         $t8, $zero, L_80792824
    if (ctx->r24 != 0) {
        // 0x80792800: nop
    
            goto L_80792824;
    }
    // 0x80792800: nop

    // 0x80792804: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80792808: b           L_80792900
    // 0x8079280C: ori         $v0, $v1, 0x1
    ctx->r2 = ctx->r3 | 0X1;
        goto L_80792900;
    // 0x8079280C: ori         $v0, $v1, 0x1
    ctx->r2 = ctx->r3 | 0X1;
    // 0x80792810: lw          $t0, 0x12C($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X12C);
L_80792814:
    // 0x80792814: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80792818: bne         $t0, $at, L_80792824
    if (ctx->r8 != ctx->r1) {
        // 0x8079281C: nop
    
            goto L_80792824;
    }
    // 0x8079281C: nop

    // 0x80792820: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80792824:
    // 0x80792824: b           L_80792900
    // 0x80792828: ori         $v0, $v1, 0x1
    ctx->r2 = ctx->r3 | 0X1;
        goto L_80792900;
    // 0x80792828: ori         $v0, $v1, 0x1
    ctx->r2 = ctx->r3 | 0X1;
L_8079282C:
    // 0x8079282C: lw          $t1, 0xED0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0XED0);
    // 0x80792830: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80792834: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80792838: addu        $t2, $t1, $fp
    ctx->r10 = ADD32(ctx->r9, ctx->r30);
    // 0x8079283C: lw          $t9, 0x38($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X38);
    // 0x80792840: beql        $t9, $zero, L_807928C0
    if (ctx->r25 == 0) {
        // 0x80792844: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_807928C0;
    }
    goto skip_5;
    // 0x80792844: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_5:
L_80792848:
    // 0x80792848: lw          $v1, 0xED0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XED0);
    // 0x8079284C: sll         $t3, $s2, 2
    ctx->r11 = S32(ctx->r18 << 2);
    // 0x80792850: subu        $t3, $t3, $s2
    ctx->r11 = SUB32(ctx->r11, ctx->r18);
    // 0x80792854: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80792858: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8079285C: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80792860: lw          $v0, 0xC($t5)
    ctx->r2 = MEM_W(ctx->r13, 0XC);
    // 0x80792864: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x80792868: beql        $at, $zero, L_807928B4
    if (ctx->r1 == 0) {
        // 0x8079286C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_807928B4;
    }
    goto skip_6;
    // 0x8079286C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_6:
    // 0x80792870: blezl       $v0, L_807928B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80792874: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_807928B4;
    }
    goto skip_7;
    // 0x80792874: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_7:
    // 0x80792878: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x8079287C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80792880: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80792884: jalr        $t9
    // 0x80792888: addiu       $a2, $zero, -0xC
    ctx->r6 = ADD32(0, -0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80792888: addiu       $a2, $zero, -0xC
    ctx->r6 = ADD32(0, -0XC);
    after_2:
    // 0x8079288C: lwc1        $f8, 0x84($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X84);
    // 0x80792890: jal         0x80065954
    // 0x80792894: sub.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f8.fl;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x80792894: sub.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f8.fl;
    after_3:
    // 0x80792898: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8079289C: nop

    // 0x807928A0: bc1fl       L_807928B4
    if (!c1cs) {
        // 0x807928A4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_807928B4;
    }
    goto skip_8;
    // 0x807928A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_8:
    // 0x807928A8: or          $s6, $s2, $zero
    ctx->r22 = ctx->r18 | 0;
    // 0x807928AC: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
    // 0x807928B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_807928B4:
    // 0x807928B4: bne         $s0, $s3, L_80792848
    if (ctx->r16 != ctx->r19) {
        // 0x807928B8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80792848;
    }
    // 0x807928B8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807928BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_807928C0:
    // 0x807928C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807928C4: bne         $s2, $at, L_8079282C
    if (ctx->r18 != ctx->r1) {
        // 0x807928C8: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_8079282C;
    }
    // 0x807928C8: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x807928CC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x807928D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807928D4: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x807928D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807928DC: c.lt.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
    // 0x807928E0: nop

    // 0x807928E4: bc1f        L_80792900
    if (!c1cs) {
        // 0x807928E8: nop
    
            goto L_80792900;
    }
    // 0x807928E8: nop

    // 0x807928EC: sw          $s6, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r22;
    // 0x807928F0: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x807928F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807928F8: b           L_80792900
    // 0x807928FC: sw          $s7, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r23;
        goto L_80792900;
    // 0x807928FC: sw          $s7, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r23;
L_80792900:
    // 0x80792900: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80792904: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80792908: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8079290C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80792910: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80792914: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80792918: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8079291C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80792920: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80792924: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80792928: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8079292C: jr          $ra
    // 0x80792930: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80792930: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8007301C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007301C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80073020: lw          $v0, -0x27A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X27A8);
    // 0x80073024: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80073028: jr          $ra
    // 0x8007302C: nop

    return;
    // 0x8007302C: nop

;}
RECOMP_FUNC void func_80022594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022594: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80022598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002259C: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x800225A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800225A4: lwc1        $f4, 0xD4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XD4);
    // 0x800225A8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800225AC: nop

    // 0x800225B0: bc1fl       L_80022690
    if (!c1cs) {
        // 0x800225B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80022690;
    }
    goto skip_0;
    // 0x800225B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800225B8: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x800225BC: lbu         $t7, 0x12($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X12);
    // 0x800225C0: bnel        $t7, $zero, L_80022690
    if (ctx->r15 != 0) {
        // 0x800225C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80022690;
    }
    goto skip_1;
    // 0x800225C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800225C8: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
    // 0x800225CC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800225D0: bne         $t8, $at, L_80022660
    if (ctx->r24 != ctx->r1) {
        // 0x800225D4: nop
    
            goto L_80022660;
    }
    // 0x800225D4: nop

    // 0x800225D8: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x800225DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800225E0: jal         0x80021F54
    // 0x800225E4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80021F54(rdram, ctx);
        goto after_0;
    // 0x800225E4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x800225E8: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800225EC: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x800225F0: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x800225F4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800225F8: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800225FC: lbu         $t0, 0xF0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XF0);
    // 0x80022600: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x80022604: addiu       $t2, $t1, 0x20
    ctx->r10 = ADD32(ctx->r9, 0X20);
    // 0x80022608: sb          $t2, 0xF0($v0)
    MEM_B(0XF0, ctx->r2) = ctx->r10;
    // 0x8002260C: lw          $t4, 0x478($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X478);
    // 0x80022610: sb          $t3, 0xF9($t4)
    MEM_B(0XF9, ctx->r12) = ctx->r11;
    // 0x80022614: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80022618: sh          $t5, 0x100($t6)
    MEM_H(0X100, ctx->r14) = ctx->r13;
    // 0x8002261C: lw          $t7, 0x478($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X478);
    // 0x80022620: sb          $zero, 0xF2($t7)
    MEM_B(0XF2, ctx->r15) = 0;
    // 0x80022624: lw          $t8, 0xAA4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XAA4);
    // 0x80022628: beql        $t8, $zero, L_8002263C
    if (ctx->r24 == 0) {
        // 0x8002262C: addiu       $t9, $zero, 0x64
        ctx->r25 = ADD32(0, 0X64);
            goto L_8002263C;
    }
    goto skip_2;
    // 0x8002262C: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    skip_2:
    // 0x80022630: jal         0x80022558
    // 0x80022634: nop

    func_80022558(rdram, ctx);
        goto after_1;
    // 0x80022634: nop

    after_1:
    // 0x80022638: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
L_8002263C:
    // 0x8002263C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80022640: sb          $t9, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r25;
    // 0x80022644: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80022648: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x8002264C: sb          $t0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r8;
    // 0x80022650: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80022654: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80022658: b           L_8002268C
    // 0x8002265C: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
        goto L_8002268C;
    // 0x8002265C: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
L_80022660:
    // 0x80022660: jal         0x80021F54
    // 0x80022664: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80021F54(rdram, ctx);
        goto after_2;
    // 0x80022664: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80022668: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x8002266C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80022670: sb          $t2, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r10;
    // 0x80022674: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80022678: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8002267C: sb          $t3, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r11;
    // 0x80022680: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80022684: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x80022688: sb          $t4, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r12;
L_8002268C:
    // 0x8002268C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80022690:
    // 0x80022690: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80022694: jr          $ra
    // 0x80022698: nop

    return;
    // 0x80022698: nop

;}
RECOMP_FUNC void func_80475870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475870: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475874: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475878: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047587C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475880: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475884: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475888: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047588C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475890: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475894: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475898: jr          $ra
    // 0x8047589C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047589C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8004977C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004977C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80049780: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80049784: lbu         $t6, 0xF6E($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF6E);
    // 0x80049788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004978C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049790: bnel        $t6, $zero, L_800497C8
    if (ctx->r14 != 0) {
        // 0x80049794: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800497C8;
    }
    goto skip_0;
    // 0x80049794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80049798: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x8004979C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800497A0: bnel        $t7, $at, L_800497C8
    if (ctx->r15 != ctx->r1) {
        // 0x800497A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800497C8;
    }
    goto skip_1;
    // 0x800497A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800497A8: jal         0x800492C0
    // 0x800497AC: addiu       $a0, $zero, -0x78
    ctx->r4 = ADD32(0, -0X78);
    func_800492C0(rdram, ctx);
        goto after_0;
    // 0x800497AC: addiu       $a0, $zero, -0x78
    ctx->r4 = ADD32(0, -0X78);
    after_0:
    // 0x800497B0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800497B4: beq         $v0, $zero, L_800497C4
    if (ctx->r2 == 0) {
        // 0x800497B8: addiu       $v1, $v1, 0x7EA0
        ctx->r3 = ADD32(ctx->r3, 0X7EA0);
            goto L_800497C4;
    }
    // 0x800497B8: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x800497BC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800497C0: sb          $t8, 0xF6E($v1)
    MEM_B(0XF6E, ctx->r3) = ctx->r24;
L_800497C4:
    // 0x800497C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800497C8:
    // 0x800497C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800497CC: jr          $ra
    // 0x800497D0: nop

    return;
    // 0x800497D0: nop

;}
RECOMP_FUNC void func_80039B68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039B68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039B6C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039B70: addiu       $a0, $a0, 0x5690
    ctx->r4 = ADD32(ctx->r4, 0X5690);
    // 0x80039B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039B78: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80039B7C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80039B80: sw          $a0, 0x426C($at)
    MEM_W(0X426C, ctx->r1) = ctx->r4;
    // 0x80039B84: addiu       $a1, $a1, 0x56A0
    ctx->r5 = ADD32(ctx->r5, 0X56A0);
    // 0x80039B88: jal         0x8004667C
    // 0x80039B8C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x80039B8C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x80039B90: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039B94: addiu       $a0, $a0, 0x56A0
    ctx->r4 = ADD32(ctx->r4, 0X56A0);
    // 0x80039B98: jal         0x80039ABC
    // 0x80039B9C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80039ABC(rdram, ctx);
        goto after_1;
    // 0x80039B9C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80039BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039BA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039BA8: jr          $ra
    // 0x80039BAC: nop

    return;
    // 0x80039BAC: nop

;}
RECOMP_FUNC void func_80536174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536174: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536178: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053617C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536180: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536184: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536188: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053618C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536190: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536194: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536198: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053619C: jr          $ra
    // 0x805361A0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805361A0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
