#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8078BA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078BA60: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8078BA64: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(796, 0X16F0) << 16);
    // 0x8078BA68: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8078BA6C: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x8078BA70: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x8078BA74: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x8078BA78: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x8078BA7C: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8078BA80: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8078BA84: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8078BA88: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8078BA8C: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8078BA90: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8078BA94: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8078BA98: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8078BA9C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8078BAA0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8078BAA4: addiu       $t6, $t6, -0x3780
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(796, 0X16F0));
    // 0x8078BAA8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8078BAAC: lui         $t9, 0x8079
    ctx->r25 = S32(RELOC_HI16(796, 0X1700) << 16);
    // 0x8078BAB0: addiu       $t9, $t9, -0x3770
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(796, 0X1700));
    // 0x8078BAB4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8078BAB8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8078BABC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8078BAC0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8078BAC4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8078BAC8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8078BACC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8078BAD0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8078BAD4: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8078BAD8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8078BADC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8078BAE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8078BAE4: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8078BAE8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8078BAEC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8078BAF0: lui         $s5, 0x8079
    ctx->r21 = S32(RELOC_HI16(796, 0X1710) << 16);
    // 0x8078BAF4: sw          $t1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r9;
    // 0x8078BAF8: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8078BAFC: lui         $s6, 0x8079
    ctx->r22 = S32(RELOC_HI16(796, 0X1720) << 16);
    // 0x8078BB00: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8078BB04: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    // 0x8078BB08: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8078BB0C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8078BB10: addiu       $s2, $a1, 0x80
    ctx->r18 = ADD32(ctx->r5, 0X80);
    // 0x8078BB14: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // 0x8078BB18: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8078BB1C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8078BB20: addiu       $s5, $s5, -0x3760
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(796, 0X1710));
    // 0x8078BB24: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    // 0x8078BB28: addiu       $s6, $s6, -0x3750
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(796, 0X1720));
    // 0x8078BB2C: addiu       $s0, $a0, 0x20
    ctx->r16 = ADD32(ctx->r4, 0X20);
    // 0x8078BB30: addiu       $s1, $a0, 0x30
    ctx->r17 = ADD32(ctx->r4, 0X30);
    // 0x8078BB34: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x8078BB38: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x8078BB3C: mov.s       $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    ctx->f24.fl = ctx->f28.fl;
L_8078BB40:
    // 0x8078BB40: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8078BB44: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8078BB48: lw          $t2, 0x4($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X4);
    // 0x8078BB4C: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x8078BB50: lw          $t3, 0x8($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X8);
    // 0x8078BB54: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x8078BB58: lw          $t2, 0xC($s5)
    ctx->r10 = MEM_W(ctx->r21, 0XC);
    // 0x8078BB5C: sw          $t2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r10;
    // 0x8078BB60: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x8078BB64: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8078BB68: lw          $t4, 0x4($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X4);
    // 0x8078BB6C: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    // 0x8078BB70: lw          $t5, 0x8($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X8);
    // 0x8078BB74: sw          $t5, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r13;
    // 0x8078BB78: lw          $t4, 0xC($s6)
    ctx->r12 = MEM_W(ctx->r22, 0XC);
    // 0x8078BB7C: sw          $t4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r12;
    // 0x8078BB80: jal         0x80066DE4
    // 0x8078BB84: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8078BB84: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    after_0:
    // 0x8078BB88: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8078BB8C: jal         0x80066E88
    // 0x8078BB90: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8078BB90: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    after_1:
    // 0x8078BB94: mul.s       $f2, $f26, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x8078BB98: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1B5C) << 16);
    // 0x8078BB9C: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x8078BBA0: mul.s       $f14, $f28, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f28.fl, ctx->f20.fl);
    // 0x8078BBA4: addiu       $s5, $s5, 0x20
    ctx->r21 = ADD32(ctx->r21, 0X20);
    // 0x8078BBA8: addiu       $s6, $s6, 0x20
    ctx->r22 = ADD32(ctx->r22, 0X20);
    // 0x8078BBAC: mul.s       $f16, $f28, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x8078BBB0: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8078BBB4: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x8078BBB8: mul.s       $f12, $f26, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x8078BBBC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x8078BBC0: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8078BBC4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8078BBC8: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8078BBCC: add.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8078BBD0: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8078BBD4: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x8078BBD8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8078BBDC: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x8078BBE0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8078BBE4: sh          $t7, -0x20($s0)
    MEM_H(-0X20, ctx->r16) = ctx->r15;
    // 0x8078BBE8: sub.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8078BBEC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8078BBF0: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x8078BBF4: sh          $t9, -0x1E($s0)
    MEM_H(-0X1E, ctx->r16) = ctx->r25;
    // 0x8078BBF8: add.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x8078BBFC: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x8078BC00: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8078BC04: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8078BC08: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8078BC0C: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8078BC10: sh          $t1, -0x20($s1)
    MEM_H(-0X20, ctx->r17) = ctx->r9;
    // 0x8078BC14: sh          $t3, -0x1E($s1)
    MEM_H(-0X1E, ctx->r17) = ctx->r11;
    // 0x8078BC18: swc1        $f22, -0x8($s3)
    MEM_W(-0X8, ctx->r19) = ctx->f22.u32l;
    // 0x8078BC1C: swc1        $f24, -0x4($s3)
    MEM_W(-0X4, ctx->r19) = ctx->f24.u32l;
    // 0x8078BC20: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8078BC24: lwc1        $f10, -0x3314($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1B5C));
    // 0x8078BC28: slti        $at, $s4, 0x10
    ctx->r1 = SIGNED(ctx->r20) < 0X10 ? 1 : 0;
    // 0x8078BC2C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8078BC30: sub.s       $f26, $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = ctx->f26.fl - ctx->f10.fl;
    // 0x8078BC34: mul.s       $f8, $f30, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x8078BC38: add.s       $f22, $f6, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x8078BC3C: bne         $at, $zero, L_8078BB40
    if (ctx->r1 != 0) {
        // 0x8078BC40: add.s       $f24, $f8, $f24
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = ctx->f8.fl + ctx->f24.fl;
            goto L_8078BB40;
    }
    // 0x8078BC40: add.s       $f24, $f8, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x8078BC44: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8078BC48: addiu       $s4, $s0, 0x20
    ctx->r20 = ADD32(ctx->r16, 0X20);
    // 0x8078BC4C: addiu       $s7, $s1, 0x20
    ctx->r23 = ADD32(ctx->r17, 0X20);
    // 0x8078BC50: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8078BC54: lw          $t4, 0x4($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X4);
    // 0x8078BC58: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x8078BC5C: lw          $t5, 0x8($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X8);
    // 0x8078BC60: sw          $t5, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r13;
    // 0x8078BC64: lw          $t4, 0xC($s5)
    ctx->r12 = MEM_W(ctx->r21, 0XC);
    // 0x8078BC68: sw          $t4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r12;
    // 0x8078BC6C: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x8078BC70: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8078BC74: lw          $t6, 0x4($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X4);
    // 0x8078BC78: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x8078BC7C: lw          $t7, 0x8($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X8);
    // 0x8078BC80: sw          $t7, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r15;
    // 0x8078BC84: lw          $t6, 0xC($s6)
    ctx->r14 = MEM_W(ctx->r22, 0XC);
    // 0x8078BC88: sw          $t6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r14;
    // 0x8078BC8C: lw          $t9, 0x20($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X20);
    // 0x8078BC90: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x8078BC94: lw          $t8, 0x24($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X24);
    // 0x8078BC98: sw          $t8, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r24;
    // 0x8078BC9C: lw          $t9, 0x28($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X28);
    // 0x8078BCA0: sw          $t9, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r25;
    // 0x8078BCA4: lw          $t8, 0x2C($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X2C);
    // 0x8078BCA8: sw          $t8, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r24;
    // 0x8078BCAC: lw          $t1, 0x20($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X20);
    // 0x8078BCB0: sw          $t1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r9;
    // 0x8078BCB4: lw          $t0, 0x24($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X24);
    // 0x8078BCB8: sw          $t0, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r8;
    // 0x8078BCBC: lw          $t1, 0x28($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X28);
    // 0x8078BCC0: sw          $t1, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r9;
    // 0x8078BCC4: lw          $t0, 0x2C($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X2C);
    // 0x8078BCC8: sw          $t0, 0xC($s7)
    MEM_W(0XC, ctx->r23) = ctx->r8;
    // 0x8078BCCC: jal         0x80066DE4
    // 0x8078BCD0: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8078BCD0: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    after_2:
    // 0x8078BCD4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8078BCD8: jal         0x80066E88
    // 0x8078BCDC: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x8078BCDC: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    after_3:
    // 0x8078BCE0: mul.s       $f2, $f26, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x8078BCE4: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1B60) << 16);
    // 0x8078BCE8: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x8078BCEC: mul.s       $f14, $f28, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f28.fl, ctx->f20.fl);
    // 0x8078BCF0: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x8078BCF4: addiu       $s5, $s5, 0x40
    ctx->r21 = ADD32(ctx->r21, 0X40);
    // 0x8078BCF8: mul.s       $f16, $f28, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x8078BCFC: addiu       $s6, $s6, 0x40
    ctx->r22 = ADD32(ctx->r22, 0X40);
    // 0x8078BD00: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x8078BD04: mul.s       $f12, $f26, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x8078BD08: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8078BD0C: sub.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8078BD10: add.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x8078BD14: add.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8078BD18: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8078BD1C: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x8078BD20: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8078BD24: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x8078BD28: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8078BD2C: sh          $v0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r2;
    // 0x8078BD30: sh          $v0, -0x40($s0)
    MEM_H(-0X40, ctx->r16) = ctx->r2;
    // 0x8078BD34: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8078BD38: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x8078BD3C: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x8078BD40: sh          $v1, 0x2($s4)
    MEM_H(0X2, ctx->r20) = ctx->r3;
    // 0x8078BD44: sh          $v1, -0x3E($s0)
    MEM_H(-0X3E, ctx->r16) = ctx->r3;
    // 0x8078BD48: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x8078BD4C: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x8078BD50: add.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x8078BD54: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8078BD58: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8078BD5C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8078BD60: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8078BD64: sh          $a0, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r4;
    // 0x8078BD68: sh          $a0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r4;
    // 0x8078BD6C: sh          $a1, 0x2($s7)
    MEM_H(0X2, ctx->r23) = ctx->r5;
    // 0x8078BD70: sh          $a1, -0x3E($s1)
    MEM_H(-0X3E, ctx->r17) = ctx->r5;
    // 0x8078BD74: swc1        $f22, -0x8($s3)
    MEM_W(-0X8, ctx->r19) = ctx->f22.u32l;
    // 0x8078BD78: swc1        $f24, -0x4($s3)
    MEM_W(-0X4, ctx->r19) = ctx->f24.u32l;
    // 0x8078BD7C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8078BD80: lwc1        $f4, -0x3310($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1B60));
    // 0x8078BD84: addiu       $s7, $zero, 0x12
    ctx->r23 = ADD32(0, 0X12);
    // 0x8078BD88: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8078BD8C: sub.s       $f26, $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f26.fl - ctx->f4.fl;
    // 0x8078BD90: mul.s       $f18, $f30, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x8078BD94: add.s       $f22, $f10, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x8078BD98: add.s       $f24, $f18, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = ctx->f18.fl + ctx->f24.fl;
L_8078BD9C:
    // 0x8078BD9C: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x8078BDA0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8078BDA4: lw          $t6, 0x4($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X4);
    // 0x8078BDA8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x8078BDAC: lw          $t7, 0x8($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X8);
    // 0x8078BDB0: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x8078BDB4: lw          $t6, 0xC($s5)
    ctx->r14 = MEM_W(ctx->r21, 0XC);
    // 0x8078BDB8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
    // 0x8078BDBC: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x8078BDC0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8078BDC4: lw          $t8, 0x4($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X4);
    // 0x8078BDC8: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x8078BDCC: lw          $t9, 0x8($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X8);
    // 0x8078BDD0: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
    // 0x8078BDD4: lw          $t8, 0xC($s6)
    ctx->r24 = MEM_W(ctx->r22, 0XC);
    // 0x8078BDD8: sw          $t8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r24;
    // 0x8078BDDC: jal         0x80066DE4
    // 0x8078BDE0: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x8078BDE0: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    after_4:
    // 0x8078BDE4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8078BDE8: jal         0x80066E88
    // 0x8078BDEC: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x8078BDEC: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    after_5:
    // 0x8078BDF0: mul.s       $f2, $f26, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x8078BDF4: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1B64) << 16);
    // 0x8078BDF8: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x8078BDFC: mul.s       $f14, $f28, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f28.fl, ctx->f20.fl);
    // 0x8078BE00: addiu       $s5, $s5, 0x20
    ctx->r21 = ADD32(ctx->r21, 0X20);
    // 0x8078BE04: addiu       $s6, $s6, 0x20
    ctx->r22 = ADD32(ctx->r22, 0X20);
    // 0x8078BE08: mul.s       $f16, $f28, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x8078BE0C: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8078BE10: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x8078BE14: mul.s       $f12, $f26, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x8078BE18: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x8078BE1C: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8078BE20: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8078BE24: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x8078BE28: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8078BE2C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8078BE30: add.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x8078BE34: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8078BE38: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x8078BE3C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8078BE40: sh          $t1, -0x20($s0)
    MEM_H(-0X20, ctx->r16) = ctx->r9;
    // 0x8078BE44: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x8078BE48: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8078BE4C: sub.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x8078BE50: sh          $t3, -0x1E($s0)
    MEM_H(-0X1E, ctx->r16) = ctx->r11;
    // 0x8078BE54: add.s       $f18, $f10, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x8078BE58: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8078BE5C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8078BE60: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8078BE64: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8078BE68: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8078BE6C: sh          $t5, -0x20($s1)
    MEM_H(-0X20, ctx->r17) = ctx->r13;
    // 0x8078BE70: sh          $t7, -0x1E($s1)
    MEM_H(-0X1E, ctx->r17) = ctx->r15;
    // 0x8078BE74: swc1        $f22, -0x8($s3)
    MEM_W(-0X8, ctx->r19) = ctx->f22.u32l;
    // 0x8078BE78: swc1        $f24, -0x4($s3)
    MEM_W(-0X4, ctx->r19) = ctx->f24.u32l;
    // 0x8078BE7C: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8078BE80: lwc1        $f8, -0x330C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1B64));
    // 0x8078BE84: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8078BE88: sub.s       $f26, $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = ctx->f26.fl - ctx->f8.fl;
    // 0x8078BE8C: mul.s       $f6, $f30, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x8078BE90: add.s       $f22, $f4, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8078BE94: bne         $s4, $s7, L_8078BD9C
    if (ctx->r20 != ctx->r23) {
        // 0x8078BE98: add.s       $f24, $f6, $f24
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = ctx->f6.fl + ctx->f24.fl;
            goto L_8078BD9C;
    }
    // 0x8078BE98: add.s       $f24, $f6, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8078BE9C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8078BEA0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8078BEA4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8078BEA8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8078BEAC: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8078BEB0: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8078BEB4: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8078BEB8: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8078BEBC: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8078BEC0: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8078BEC4: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8078BEC8: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x8078BECC: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x8078BED0: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x8078BED4: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x8078BED8: jr          $ra
    // 0x8078BEDC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x8078BEDC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_806F2284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2284: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806F2288: jr          $ra
    // 0x806F228C: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x806F228C: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_804459EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804459EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804459F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804459F4: addiu       $a0, $zero, 0x202
    ctx->r4 = ADD32(0, 0X202);
    // 0x804459F8: jal         0x80067818
    // 0x804459FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x804459FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80445A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445A08: jr          $ra
    // 0x80445A0C: nop

    return;
    // 0x80445A0C: nop

;}
RECOMP_FUNC void func_800451F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800451F0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800451F4: lbu         $t7, -0x7EB0($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X7EB0);
    // 0x800451F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800451FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80045200: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80045204: beq         $t7, $zero, L_80045240
    if (ctx->r15 == 0) {
        // 0x80045208: lw          $v0, 0x18($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X18);
            goto L_80045240;
    }
    // 0x80045208: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8004520C: addiu       $a3, $a0, 0x70
    ctx->r7 = ADD32(ctx->r4, 0X70);
    // 0x80045210: sh          $zero, 0x6($a3)
    MEM_H(0X6, ctx->r7) = 0;
    // 0x80045214: lh          $a2, 0x6($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X6);
    // 0x80045218: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x8004521C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80045220: jal         0x80045144
    // 0x80045224: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80045144(rdram, ctx);
        goto after_0;
    // 0x80045224: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80045228: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8004522C: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    // 0x80045230: jal         0x80044FE4
    // 0x80045234: lh          $a1, 0x6($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X6);
    func_80044FE4(rdram, ctx);
        goto after_1;
    // 0x80045234: lh          $a1, 0x6($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X6);
    after_1:
    // 0x80045238: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004523C: sb          $zero, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = 0;
L_80045240:
    // 0x80045240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80045244: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80045248: jr          $ra
    // 0x8004524C: nop

    return;
    // 0x8004524C: nop

;}
RECOMP_FUNC void func_8003C094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003C098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003C09C: jal         0x800433D0
    // 0x8003C0A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800433D0(rdram, ctx);
        goto after_0;
    // 0x8003C0A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003C0A4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003C0A8: jal         0x80065954
    // 0x8003C0AC: lwc1        $f12, 0xC4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XC4);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8003C0AC: lwc1        $f12, 0xC4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XC4);
    after_1:
    // 0x8003C0B0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003C0B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003C0B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003C0BC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003C0C0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003C0C4: jal         0x80041214
    // 0x8003C0C8: nop

    func_80041214(rdram, ctx);
        goto after_2;
    // 0x8003C0C8: nop

    after_2:
    // 0x8003C0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003C0D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003C0D4: jr          $ra
    // 0x8003C0D8: nop

    return;
    // 0x8003C0D8: nop

;}
RECOMP_FUNC void func_807996E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807996E8: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x807996EC: lh          $v0, 0x144($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X144);
    // 0x807996F0: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(826, 0X24B0) << 16);
    // 0x807996F4: beq         $v1, $zero, L_80799750
    if (ctx->r3 == 0) {
        // 0x807996F8: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80799750;
    }
    // 0x807996F8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x807996FC: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80799700: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80799704: addiu       $t7, $t7, -0x5030
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(826, 0X24B0));
    // 0x80799708: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x8079970C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80799710: lwc1        $f6, 0x84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X84);
    // 0x80799714: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80799718: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8079971C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80799720: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x80799724: lwc1        $f16, 0x88($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X88);
    // 0x80799728: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8079972C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80799730: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80799734: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80799738: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8079973C: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    // 0x80799740: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80799744: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x80799748: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8079974C: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
L_80799750:
    // 0x80799750: jr          $ra
    // 0x80799754: nop

    return;
    // 0x80799754: nop

;}
RECOMP_FUNC void func_8004884C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004884C: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80048850: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80048854: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80048858: addiu       $t8, $t8, -0x785C
    ctx->r24 = ADD32(ctx->r24, -0X785C);
    // 0x8004885C: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80048860: sb          $t6, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r14;
    // 0x80048864: sw          $t7, 0x150($a0)
    MEM_W(0X150, ctx->r4) = ctx->r15;
    // 0x80048868: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
    // 0x8004886C: jr          $ra
    // 0x80048870: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80048870: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8004E344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E344: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004E348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004E34C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004E350: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8004E354: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8004E358: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x8004E35C: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004E360: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8004E364: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004E368: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8004E36C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8004E370: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x8004E374: beql        $v0, $zero, L_8004E3AC
    if (ctx->r2 == 0) {
        // 0x8004E378: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E3AC;
    }
    goto skip_0;
    // 0x8004E378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004E37C: beql        $v0, $at, L_8004E3AC
    if (ctx->r2 == ctx->r1) {
        // 0x8004E380: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E3AC;
    }
    goto skip_1;
    // 0x8004E380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004E384: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8004E388: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004E38C: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8004E390: beq         $v0, $at, L_8004E3A8
    if (ctx->r2 == ctx->r1) {
        // 0x8004E394: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004E3A8;
    }
    // 0x8004E394: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004E398: beq         $v0, $at, L_8004E3A8
    if (ctx->r2 == ctx->r1) {
        // 0x8004E39C: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8004E3A8;
    }
    // 0x8004E39C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004E3A0: jal         0x8004D038
    // 0x8004E3A4: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    func_8004D038(rdram, ctx);
        goto after_0;
    // 0x8004E3A4: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_0:
L_8004E3A8:
    // 0x8004E3A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004E3AC:
    // 0x8004E3AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004E3B0: jr          $ra
    // 0x8004E3B4: nop

    return;
    // 0x8004E3B4: nop

;}
RECOMP_FUNC void func_805675B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805675B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805675B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805675B8: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x805675BC: addiu       $t7, $t6, -0x4159
    ctx->r15 = ADD32(ctx->r14, -0X4159);
    // 0x805675C0: sltiu       $at, $t7, 0x25
    ctx->r1 = ctx->r15 < 0X25 ? 1 : 0;
    // 0x805675C4: beq         $at, $zero, L_80567658
    if (ctx->r1 == 0) {
        // 0x805675C8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80567658;
    }
    // 0x805675C8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805675CC: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2020) << 16);
    // 0x805675D0: addu        $at, $at, $t7
    gpr jr_addend_805675D8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x805675D4: lw          $t7, -0x6A30($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(378, 0X2020));
    // 0x805675D8: jr          $t7
    // 0x805675DC: nop

    switch (jr_addend_805675D8 >> 2) {
        case 0: goto L_805675E0; break;
        case 1: goto L_80567610; break;
        case 2: goto L_80567658; break;
        case 3: goto L_80567658; break;
        case 4: goto L_80567658; break;
        case 5: goto L_80567658; break;
        case 6: goto L_80567658; break;
        case 7: goto L_80567658; break;
        case 8: goto L_80567658; break;
        case 9: goto L_80567658; break;
        case 10: goto L_80567658; break;
        case 11: goto L_80567658; break;
        case 12: goto L_805675F0; break;
        case 13: goto L_80567620; break;
        case 14: goto L_80567658; break;
        case 15: goto L_80567658; break;
        case 16: goto L_80567658; break;
        case 17: goto L_80567658; break;
        case 18: goto L_80567658; break;
        case 19: goto L_80567658; break;
        case 20: goto L_80567658; break;
        case 21: goto L_80567658; break;
        case 22: goto L_80567658; break;
        case 23: goto L_80567658; break;
        case 24: goto L_80567600; break;
        case 25: goto L_80567630; break;
        case 26: goto L_80567658; break;
        case 27: goto L_80567658; break;
        case 28: goto L_80567658; break;
        case 29: goto L_80567658; break;
        case 30: goto L_80567658; break;
        case 31: goto L_80567658; break;
        case 32: goto L_80567658; break;
        case 33: goto L_80567658; break;
        case 34: goto L_80567658; break;
        case 35: goto L_80567640; break;
        case 36: goto L_80567650; break;
        default: switch_error(__func__, 0x805675D8, 0x805695D0);
    }
    // 0x805675DC: nop

L_805675E0:
    // 0x805675E0: jal         0x805694F0
    // 0x805675E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_805694F0(rdram, ctx);
        goto after_0;
    // 0x805675E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x805675E8: b           L_8056765C
    // 0x805675EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8056765C;
    // 0x805675EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805675F0:
    // 0x805675F0: jal         0x805694F0
    // 0x805675F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_805694F0(rdram, ctx);
        goto after_1;
    // 0x805675F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x805675F8: b           L_8056765C
    // 0x805675FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8056765C;
    // 0x805675FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80567600:
    // 0x80567600: jal         0x805694F0
    // 0x80567604: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_805694F0(rdram, ctx);
        goto after_2;
    // 0x80567604: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80567608: b           L_8056765C
    // 0x8056760C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8056765C;
    // 0x8056760C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80567610:
    // 0x80567610: jal         0x805694F0
    // 0x80567614: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_805694F0(rdram, ctx);
        goto after_3;
    // 0x80567614: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x80567618: b           L_8056765C
    // 0x8056761C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8056765C;
    // 0x8056761C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80567620:
    // 0x80567620: jal         0x805694F0
    // 0x80567624: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_805694F0(rdram, ctx);
        goto after_4;
    // 0x80567624: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_4:
    // 0x80567628: b           L_8056765C
    // 0x8056762C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8056765C;
    // 0x8056762C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80567630:
    // 0x80567630: jal         0x805694F0
    // 0x80567634: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_805694F0(rdram, ctx);
        goto after_5;
    // 0x80567634: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_5:
    // 0x80567638: b           L_8056765C
    // 0x8056763C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8056765C;
    // 0x8056763C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80567640:
    // 0x80567640: jal         0x805694F0
    // 0x80567644: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_805694F0(rdram, ctx);
        goto after_6;
    // 0x80567644: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_6:
    // 0x80567648: b           L_8056765C
    // 0x8056764C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8056765C;
    // 0x8056764C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80567650:
    // 0x80567650: jal         0x805694F0
    // 0x80567654: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_805694F0(rdram, ctx);
        goto after_7;
    // 0x80567654: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_7:
L_80567658:
    // 0x80567658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056765C:
    // 0x8056765C: lui         $v0, 0x8056
    ctx->r2 = S32(RELOC_HI16(378, 0XBC) << 16);
    // 0x80567660: addiu       $v0, $v0, 0x766C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(378, 0XBC));
    // 0x80567664: jr          $ra
    // 0x80567668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80567668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80580614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580614: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8058061C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80580620: jal         0x80045A34
    // 0x80580624: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80580624: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80580628: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8058062C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80580630: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80580634: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80580638: jal         0x800657CC
    // 0x8058063C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x8058063C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    after_1:
    // 0x80580640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80580644: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80580648: jr          $ra
    // 0x8058064C: nop

    return;
    // 0x8058064C: nop

;}
RECOMP_FUNC void func_8040AB60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040AB60: lui         $v0, 0x8041
    ctx->r2 = S32(RELOC_HI16(14, 0X28) << 16);
    // 0x8040AB64: addiu       $v0, $v0, -0x5478
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(14, 0X28));
    // 0x8040AB68: jr          $ra
    // 0x8040AB6C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8040AB6C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8002B7EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B7EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002B7F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002B7F4: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8002B7F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002B7FC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002B800: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002B804: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002B808: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8002B80C: lw          $a1, -0x1C0C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X1C0C);
    // 0x8002B810: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8002B814: jal         0x80065528
    // 0x8002B818: addiu       $a0, $v0, 0xA8
    ctx->r4 = ADD32(ctx->r2, 0XA8);
    func_80065528(rdram, ctx);
        goto after_0;
    // 0x8002B818: addiu       $a0, $v0, 0xA8
    ctx->r4 = ADD32(ctx->r2, 0XA8);
    after_0:
    // 0x8002B81C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002B820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002B824: jr          $ra
    // 0x8002B828: nop

    return;
    // 0x8002B828: nop

;}
RECOMP_FUNC void func_80716998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716998: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8071699C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x807169A0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x807169A4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x807169A8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x807169AC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x807169B0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x807169B4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x807169B8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x807169BC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x807169C0: jr          $ra
    // 0x807169C4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x807169C4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80425548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80425548: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042554C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80425550: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80425554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80425558: beq         $t6, $zero, L_80425594
    if (ctx->r14 == 0) {
        // 0x8042555C: nop
    
            goto L_80425594;
    }
    // 0x8042555C: nop

    // 0x80425560: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80425564: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80425568: jalr        $t9
    // 0x8042556C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8042556C: nop

    after_0:
    // 0x80425570: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80425574: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80425578: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x8042557C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80425580: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80425584: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80425588: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8042558C: b           L_80425594
    // 0x80425590: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_80425594;
    // 0x80425590: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_80425594:
    // 0x80425594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80425598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042559C: jr          $ra
    // 0x804255A0: nop

    return;
    // 0x804255A0: nop

;}
RECOMP_FUNC void func_8002B798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B798: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8002B79C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8002B7A0: lw          $t6, 0xF10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF10);
    // 0x8002B7A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002B7A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002B7AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002B7B0: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8002B7B4: lw          $t9, 0xF14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XF14);
    // 0x8002B7B8: bne         $t9, $zero, L_8002B7C8
    if (ctx->r25 != 0) {
        // 0x8002B7BC: nop
    
            goto L_8002B7C8;
    }
    // 0x8002B7BC: nop

    // 0x8002B7C0: b           L_8002B7DC
    // 0x8002B7C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002B7DC;
    // 0x8002B7C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002B7C8:
    // 0x8002B7C8: jal         0x8002B698
    // 0x8002B7CC: nop

    func_8002B698(rdram, ctx);
        goto after_0;
    // 0x8002B7CC: nop

    after_0:
    // 0x8002B7D0: jal         0x8002B3A0
    // 0x8002B7D4: nop

    func_8002B3A0(rdram, ctx);
        goto after_1;
    // 0x8002B7D4: nop

    after_1:
    // 0x8002B7D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002B7DC:
    // 0x8002B7DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002B7E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002B7E4: jr          $ra
    // 0x8002B7E8: nop

    return;
    // 0x8002B7E8: nop

;}
RECOMP_FUNC void func_807095C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807095C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807095C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807095CC: jal         0x800447C8
    // 0x807095D0: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x807095D0: nop

    after_0:
    // 0x807095D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807095D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807095DC: jr          $ra
    // 0x807095E0: nop

    return;
    // 0x807095E0: nop

;}
RECOMP_FUNC void func_80061EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061EFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80061F00: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80061F04: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80061F08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80061F0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80061F10: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80061F14: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80061F18: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80061F1C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80061F20: jal         0x8004700C
    // 0x80061F24: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80061F24: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x80061F28: beq         $v0, $zero, L_80062154
    if (ctx->r2 == 0) {
        // 0x80061F2C: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_80062154;
    }
    // 0x80061F2C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80061F30: lw          $t6, 0x10($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X10);
    // 0x80061F34: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80061F38: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80061F3C: sw          $t6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r14;
    // 0x80061F40: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x80061F44: sh          $t7, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r15;
    // 0x80061F48: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061F4C: lh          $t9, 0x56($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X56);
    // 0x80061F50: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x80061F54: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80061F58: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80061F5C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80061F60: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80061F64: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x80061F68: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061F6C: lh          $t1, 0x58($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X58);
    // 0x80061F70: lw          $t0, 0x70($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X70);
    // 0x80061F74: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80061F78: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80061F7C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80061F80: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80061F84: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80061F88: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061F8C: lh          $t3, 0x5A($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X5A);
    // 0x80061F90: lw          $t2, 0x70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X70);
    // 0x80061F94: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80061F98: lwc1        $f8, 0x8($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80061F9C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80061FA0: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80061FA4: jal         0x8005FFB4
    // 0x80061FA8: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
    func_8005FFB4(rdram, ctx);
        goto after_1;
    // 0x80061FA8: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
    after_1:
    // 0x80061FAC: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80061FB0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80061FB4: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80061FB8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061FBC: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x80061FC0: lwc1        $f18, 0x88($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X88);
    // 0x80061FC4: lh          $t5, 0x52($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X52);
    // 0x80061FC8: lw          $t4, 0x70($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X70);
    // 0x80061FCC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80061FD0: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80061FD4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80061FD8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80061FDC: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80061FE0: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
    // 0x80061FE4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061FE8: lwc1        $f18, 0x8C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x80061FEC: lh          $t7, 0x54($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X54);
    // 0x80061FF0: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x80061FF4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80061FF8: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80061FFC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80062000: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80062004: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80062008: beq         $a0, $zero, L_80062154
    if (ctx->r4 == 0) {
        // 0x8006200C: swc1        $f16, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
            goto L_80062154;
    }
    // 0x8006200C: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x80062010: lh          $t8, 0x78($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X78);
    // 0x80062014: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x80062018: addiu       $s3, $s3, 0x6500
    ctx->r19 = ADD32(ctx->r19, 0X6500);
    // 0x8006201C: beq         $t8, $zero, L_80062154
    if (ctx->r24 == 0) {
        // 0x80062020: addiu       $s2, $zero, 0x2
        ctx->r18 = ADD32(0, 0X2);
            goto L_80062154;
    }
    // 0x80062020: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x80062024: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80062028: addiu       $s1, $zero, 0xF
    ctx->r17 = ADD32(0, 0XF);
    // 0x8006202C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
L_80062030:
    // 0x80062030: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80062034: beql        $v1, $zero, L_80062140
    if (ctx->r3 == 0) {
        // 0x80062038: addiu       $t9, $v0, 0x4
        ctx->r25 = ADD32(ctx->r2, 0X4);
            goto L_80062140;
    }
    goto skip_0;
    // 0x80062038: addiu       $t9, $v0, 0x4
    ctx->r25 = ADD32(ctx->r2, 0X4);
    skip_0:
    // 0x8006203C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80062040: sw          $v1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r3;
    // 0x80062044: lw          $t9, 0x174($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X174);
    // 0x80062048: beq         $t0, $v1, L_80062128
    if (ctx->r8 == ctx->r3) {
        // 0x8006204C: sw          $t9, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->r25;
            goto L_80062128;
    }
    // 0x8006204C: sw          $t9, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r25;
    // 0x80062050: bnel        $s4, $v1, L_80062078
    if (ctx->r20 != ctx->r3) {
        // 0x80062054: lw          $v1, 0x40($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X40);
            goto L_80062078;
    }
    goto skip_1;
    // 0x80062054: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
    skip_1:
    // 0x80062058: lw          $t1, 0x1F4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X1F4);
    // 0x8006205C: lbu         $t2, 0xF4($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XF4);
    // 0x80062060: beql        $t2, $zero, L_8006212C
    if (ctx->r10 == 0) {
        // 0x80062064: lh          $t7, 0x78($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X78);
            goto L_8006212C;
    }
    goto skip_2;
    // 0x80062064: lh          $t7, 0x78($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X78);
    skip_2:
    // 0x80062068: lbu         $t3, 0x30($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X30);
    // 0x8006206C: beql        $s1, $t3, L_8006212C
    if (ctx->r17 == ctx->r11) {
        // 0x80062070: lh          $t7, 0x78($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X78);
            goto L_8006212C;
    }
    goto skip_3;
    // 0x80062070: lh          $t7, 0x78($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X78);
    skip_3:
    // 0x80062074: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
L_80062078:
    // 0x80062078: lw          $t4, 0x18($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X18);
    // 0x8006207C: bnel        $t4, $zero, L_8006212C
    if (ctx->r12 != 0) {
        // 0x80062080: lh          $t7, 0x78($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X78);
            goto L_8006212C;
    }
    goto skip_4;
    // 0x80062080: lh          $t7, 0x78($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X78);
    skip_4:
    // 0x80062084: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x80062088: andi        $t6, $t5, 0xF00
    ctx->r14 = ctx->r13 & 0XF00;
    // 0x8006208C: bnel        $t6, $zero, L_8006212C
    if (ctx->r14 != 0) {
        // 0x80062090: lh          $t7, 0x78($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X78);
            goto L_8006212C;
    }
    goto skip_5;
    // 0x80062090: lh          $t7, 0x78($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X78);
    skip_5:
    // 0x80062094: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80062098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006209C: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x800620A0: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x800620A4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800620A8: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800620AC: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800620B0: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800620B4: jal         0x80060798
    // 0x800620B8: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    func_80060798(rdram, ctx);
        goto after_2;
    // 0x800620B8: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x800620BC: beql        $v0, $zero, L_8006212C
    if (ctx->r2 == 0) {
        // 0x800620C0: lh          $t7, 0x78($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X78);
            goto L_8006212C;
    }
    goto skip_6;
    // 0x800620C0: lh          $t7, 0x78($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X78);
    skip_6:
    // 0x800620C4: jal         0x80060ED0
    // 0x800620C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060ED0(rdram, ctx);
        goto after_3;
    // 0x800620C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800620CC: lw          $t9, 0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X3C);
    // 0x800620D0: swc1        $f20, 0x120($t9)
    MEM_W(0X120, ctx->r25) = ctx->f20.u32l;
    // 0x800620D4: lw          $t0, 0x3C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X3C);
    // 0x800620D8: swc1        $f20, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f20.u32l;
    // 0x800620DC: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x800620E0: lwc1        $f0, 0xCC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XCC);
    // 0x800620E4: swc1        $f0, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f0.u32l;
    // 0x800620E8: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    // 0x800620EC: swc1        $f0, 0xC4($t1)
    MEM_W(0XC4, ctx->r9) = ctx->f0.u32l;
    // 0x800620F0: lw          $t2, 0x3C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X3C);
    // 0x800620F4: sb          $s2, 0x17C($t2)
    MEM_B(0X17C, ctx->r10) = ctx->r18;
    // 0x800620F8: jal         0x80049018
    // 0x800620FC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80049018(rdram, ctx);
        goto after_4;
    // 0x800620FC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_4:
    // 0x80062100: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80062104: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x80062108: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8006210C: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80062110: lw          $t5, 0x3C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X3C);
    // 0x80062114: mul.s       $f0, $f18, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80062118: swc1        $f0, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f0.u32l;
    // 0x8006211C: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
    // 0x80062120: lwc1        $f4, 0x80($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80062124: swc1        $f4, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f4.u32l;
L_80062128:
    // 0x80062128: lh          $t7, 0x78($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X78);
L_8006212C:
    // 0x8006212C: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x80062130: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x80062134: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80062138: sh          $t8, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r24;
    // 0x8006213C: addiu       $t9, $v0, 0x4
    ctx->r25 = ADD32(ctx->r2, 0X4);
L_80062140:
    // 0x80062140: beq         $a0, $zero, L_80062154
    if (ctx->r4 == 0) {
        // 0x80062144: sw          $t9, 0x74($s0)
        MEM_W(0X74, ctx->r16) = ctx->r25;
            goto L_80062154;
    }
    // 0x80062144: sw          $t9, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r25;
    // 0x80062148: lh          $t0, 0x78($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X78);
    // 0x8006214C: bnel        $t0, $zero, L_80062030
    if (ctx->r8 != 0) {
        // 0x80062150: lw          $v0, 0x74($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X74);
            goto L_80062030;
    }
    goto skip_7;
    // 0x80062150: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    skip_7:
L_80062154:
    // 0x80062154: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80062158: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8006215C: lh          $t2, 0x184($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X184);
    // 0x80062160: beql        $t2, $zero, L_80062188
    if (ctx->r10 == 0) {
        // 0x80062164: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80062188;
    }
    goto skip_8;
    // 0x80062164: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_8:
    // 0x80062168: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8006216C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80062170: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x80062174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80062178: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8006217C: jalr        $t9
    // 0x80062180: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x80062180: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    after_5:
    // 0x80062184: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80062188:
    // 0x80062188: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8006218C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80062190: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80062194: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80062198: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8006219C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800621A0: jr          $ra
    // 0x800621A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800621A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_805D2BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2BE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805D2BE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D2BEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D2BF0: jal         0x8004700C
    // 0x805D2BF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805D2BF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805D2BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D2BFC: jal         0x80062D14
    // 0x805D2C00: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80062D14(rdram, ctx);
        goto after_1;
    // 0x805D2C00: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x805D2C04: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x805D2C08: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x805D2C0C: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x805D2C10: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x805D2C14: bne         $t7, $at, L_805D2D0C
    if (ctx->r15 != ctx->r1) {
        // 0x805D2C18: sw          $t7, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r15;
            goto L_805D2D0C;
    }
    // 0x805D2C18: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x805D2C1C: beq         $v1, $zero, L_805D2C44
    if (ctx->r3 == 0) {
        // 0x805D2C20: sw          $zero, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = 0;
            goto L_805D2C44;
    }
    // 0x805D2C20: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x805D2C24: lw          $t9, 0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X34);
    // 0x805D2C28: slti        $at, $t9, 0xA0
    ctx->r1 = SIGNED(ctx->r25) < 0XA0 ? 1 : 0;
    // 0x805D2C2C: beq         $at, $zero, L_805D2C3C
    if (ctx->r1 == 0) {
        // 0x805D2C30: nop
    
            goto L_805D2C3C;
    }
    // 0x805D2C30: nop

    // 0x805D2C34: b           L_805D2C50
    // 0x805D2C38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_805D2C50;
    // 0x805D2C38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_805D2C3C:
    // 0x805D2C3C: b           L_805D2C50
    // 0x805D2C40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_805D2C50;
    // 0x805D2C40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_805D2C44:
    // 0x805D2C44: jal         0x800653D8
    // 0x805D2C48: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x805D2C48: nop

    after_2:
    // 0x805D2C4C: andi        $a1, $v0, 0x1
    ctx->r5 = ctx->r2 & 0X1;
L_805D2C50:
    // 0x805D2C50: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x805D2C54: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x805D2C58: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805D2C5C: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x805D2C60: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x805D2C64: lw          $t9, 0x90($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X90);
    // 0x805D2C68: jalr        $t9
    // 0x805D2C6C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x805D2C6C: nop

    after_3:
    // 0x805D2C70: beq         $v0, $zero, L_805D2D0C
    if (ctx->r2 == 0) {
        // 0x805D2C74: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_805D2D0C;
    }
    // 0x805D2C74: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x805D2C78: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x805D2C7C: jal         0x800653D8
    // 0x805D2C80: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x805D2C80: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_4:
    // 0x805D2C84: andi        $t2, $v0, 0xF
    ctx->r10 = ctx->r2 & 0XF;
    // 0x805D2C88: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x805D2C8C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x805D2C90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805D2C94: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805D2C98: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x805D2C9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805D2CA0: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805D2CA4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x805D2CA8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x805D2CAC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805D2CB0: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x805D2CB4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x805D2CB8: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x805D2CBC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805D2CC0: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x805D2CC4: beq         $a1, $zero, L_805D2CF0
    if (ctx->r5 == 0) {
        // 0x805D2CC8: swc1        $f0, 0x40($v1)
        MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
            goto L_805D2CF0;
    }
    // 0x805D2CC8: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x805D2CCC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x805D2CD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805D2CD4: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805D2CD8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x805D2CDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805D2CE0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805D2CE4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x805D2CE8: b           L_805D2D0C
    // 0x805D2CEC: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
        goto L_805D2D0C;
    // 0x805D2CEC: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
L_805D2CF0:
    // 0x805D2CF0: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805D2CF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805D2CF8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x805D2CFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805D2D00: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x805D2D04: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805D2D08: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
L_805D2D0C:
    // 0x805D2D0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805D2D10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D2D14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805D2D18: jr          $ra
    // 0x805D2D1C: nop

    return;
    // 0x805D2D1C: nop

;}
RECOMP_FUNC void func_80568EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568EB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80568EB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80568EBC: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80568EC0: addiu       $at, $zero, 0x4158
    ctx->r1 = ADD32(0, 0X4158);
    // 0x80568EC4: beq         $v0, $at, L_80568EE4
    if (ctx->r2 == ctx->r1) {
        // 0x80568EC8: addiu       $at, $zero, 0x4164
        ctx->r1 = ADD32(0, 0X4164);
            goto L_80568EE4;
    }
    // 0x80568EC8: addiu       $at, $zero, 0x4164
    ctx->r1 = ADD32(0, 0X4164);
    // 0x80568ECC: beq         $v0, $at, L_80568EF4
    if (ctx->r2 == ctx->r1) {
        // 0x80568ED0: addiu       $at, $zero, 0x4170
        ctx->r1 = ADD32(0, 0X4170);
            goto L_80568EF4;
    }
    // 0x80568ED0: addiu       $at, $zero, 0x4170
    ctx->r1 = ADD32(0, 0X4170);
    // 0x80568ED4: beql        $v0, $at, L_80568F08
    if (ctx->r2 == ctx->r1) {
        // 0x80568ED8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80568F08;
    }
    goto skip_0;
    // 0x80568ED8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80568EDC: b           L_80568F14
    // 0x80568EE0: nop

        goto L_80568F14;
    // 0x80568EE0: nop

L_80568EE4:
    // 0x80568EE4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80568EE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80568EEC: b           L_80568F14
    // 0x80568EF0: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
        goto L_80568F14;
    // 0x80568EF0: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
L_80568EF4:
    // 0x80568EF4: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21FC) << 16);
    // 0x80568EF8: lwc1        $f6, -0x6854($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21FC));
    // 0x80568EFC: b           L_80568F14
    // 0x80568F00: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
        goto L_80568F14;
    // 0x80568F00: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x80568F04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80568F08:
    // 0x80568F08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80568F0C: nop

    // 0x80568F10: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
L_80568F14:
    // 0x80568F14: jal         0x80568710
    // 0x80568F18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x80568F18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80568F1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80568F20: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80568F24: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80568F28: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80568F2C: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80568F30: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80568F34: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80568F38: jal         0x80569310
    // 0x80568F3C: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    func_80569310(rdram, ctx);
        goto after_1;
    // 0x80568F3C: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    after_1:
    // 0x80568F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80568F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80568F48: jr          $ra
    // 0x80568F4C: nop

    return;
    // 0x80568F4C: nop

;}
RECOMP_FUNC void func_80710B24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80710B24: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80710B28: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80710B2C: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x80710B30: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x80710B34: lbu         $t6, 0xF5C($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XF5C);
    // 0x80710B38: lbu         $t7, 0xF5D($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XF5D);
    // 0x80710B3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80710B40: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80710B44: sb          $t6, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r14;
    // 0x80710B48: sb          $t7, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r15;
    // 0x80710B4C: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x80710B50: lw          $t1, 0xCF0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XCF0);
    // 0x80710B54: lw          $t8, 0x14($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X14);
    // 0x80710B58: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x80710B5C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80710B60: beq         $t1, $zero, L_80710BAC
    if (ctx->r9 == 0) {
        // 0x80710B64: lbu         $s0, 0x10($t9)
        ctx->r16 = MEM_BU(ctx->r25, 0X10);
            goto L_80710BAC;
    }
    // 0x80710B64: lbu         $s0, 0x10($t9)
    ctx->r16 = MEM_BU(ctx->r25, 0X10);
    // 0x80710B68: lw          $t2, 0x4($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X4);
    // 0x80710B6C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80710B70: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80710B74: andi        $a1, $t3, 0x10
    ctx->r5 = ctx->r11 & 0X10;
    // 0x80710B78: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x80710B7C: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    // 0x80710B80: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80710B84: jal         0x807106C8
    // 0x80710B88: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    func_807106C8(rdram, ctx);
        goto after_0;
    // 0x80710B88: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_0:
    // 0x80710B8C: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x80710B90: lw          $t4, -0x7470($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7470);
    // 0x80710B94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80710B98: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80710B9C: bne         $t4, $at, L_80710BAC
    if (ctx->r12 != ctx->r1) {
        // 0x80710BA0: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_80710BAC;
    }
    // 0x80710BA0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80710BA4: jal         0x807106E4
    // 0x80710BA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_807106E4(rdram, ctx);
        goto after_1;
    // 0x80710BA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_80710BAC:
    // 0x80710BAC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80710BB0: sltiu       $at, $s0, 0xFF
    ctx->r1 = ctx->r16 < 0XFF ? 1 : 0;
    // 0x80710BB4: bne         $at, $zero, L_80710C34
    if (ctx->r1 != 0) {
        // 0x80710BB8: lbu         $t5, 0x3B($sp)
        ctx->r13 = MEM_BU(ctx->r29, 0X3B);
            goto L_80710C34;
    }
    // 0x80710BB8: lbu         $t5, 0x3B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X3B);
    // 0x80710BBC: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x80710BC0: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    // 0x80710BC4: beq         $at, $zero, L_80710BF4
    if (ctx->r1 == 0) {
        // 0x80710BC8: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_80710BF4;
    }
    // 0x80710BC8: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80710BCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80710BD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80710BD4: jal         0x8006E0FC
    // 0x80710BD8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8006E0FC(rdram, ctx);
        goto after_2;
    // 0x80710BD8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80710BDC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80710BE0: sw          $t6, 0xF60($s1)
    MEM_W(0XF60, ctx->r17) = ctx->r14;
    // 0x80710BE4: jal         0x80710860
    // 0x80710BE8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80710860(rdram, ctx);
        goto after_3;
    // 0x80710BE8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80710BEC: b           L_80710C10
    // 0x80710BF0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_80710C10;
    // 0x80710BF0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80710BF4:
    // 0x80710BF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80710BF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80710BFC: jal         0x8006E0FC
    // 0x80710C00: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_8006E0FC(rdram, ctx);
        goto after_4;
    // 0x80710C00: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_4:
    // 0x80710C04: jal         0x80710A64
    // 0x80710C08: nop

    func_80710A64(rdram, ctx);
        goto after_5;
    // 0x80710C08: nop

    after_5:
    // 0x80710C0C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80710C10:
    // 0x80710C10: lbu         $t9, 0x3A($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3A);
    // 0x80710C14: lw          $t3, 0xFBC($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XFBC);
    // 0x80710C18: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80710C1C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80710C20: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80710C24: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x80710C28: or          $t4, $t3, $t2
    ctx->r12 = ctx->r11 | ctx->r10;
    // 0x80710C2C: jal         0x8006988C
    // 0x80710C30: sw          $t4, 0xFBC($s1)
    MEM_W(0XFBC, ctx->r17) = ctx->r12;
    func_8006988C(rdram, ctx);
        goto after_6;
    // 0x80710C30: sw          $t4, 0xFBC($s1)
    MEM_W(0XFBC, ctx->r17) = ctx->r12;
    after_6:
L_80710C34:
    // 0x80710C34: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80710C38: sb          $s0, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r16;
    // 0x80710C3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80710C40: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80710C44: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80710C48: jr          $ra
    // 0x80710C4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80710C4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80471530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80471534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80471538: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8047153C: lh          $t7, 0x1F0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X1F0);
    // 0x80471540: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80471544: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80471548: bnel        $t7, $at, L_80471578
    if (ctx->r15 != ctx->r1) {
        // 0x8047154C: lw          $a0, 0x34($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X34);
            goto L_80471578;
    }
    goto skip_0;
    // 0x8047154C: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    skip_0:
    // 0x80471550: lw          $a0, 0x34($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X34);
    // 0x80471554: jal         0x80067BBC
    // 0x80471558: lw          $a1, 0x38($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80471558: lw          $a1, 0x38($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X38);
    after_0:
    // 0x8047155C: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x80471560: jal         0x80067F78
    // 0x80471564: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80471564: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80471568: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8047156C: b           L_80471594
    // 0x80471570: sh          $v0, 0x1F0($t8)
    MEM_H(0X1F0, ctx->r24) = ctx->r2;
        goto L_80471594;
    // 0x80471570: sh          $v0, 0x1F0($t8)
    MEM_H(0X1F0, ctx->r24) = ctx->r2;
    // 0x80471574: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
L_80471578:
    // 0x80471578: jal         0x80067BBC
    // 0x8047157C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8047157C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_2:
    // 0x80471580: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80471584: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x80471588: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8047158C: jal         0x800678F0
    // 0x80471590: lh          $a1, 0x1F0($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X1F0);
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x80471590: lh          $a1, 0x1F0($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X1F0);
    after_3:
L_80471594:
    // 0x80471594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80471598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8047159C: jr          $ra
    // 0x804715A0: nop

    return;
    // 0x804715A0: nop

;}
RECOMP_FUNC void func_80475660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475660: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475664: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475668: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047566C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475670: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475674: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475678: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047567C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475680: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475684: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475688: jr          $ra
    // 0x8047568C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047568C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8051F3A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051F3A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051F3A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051F3AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8051F3B0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8051F3B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8051F3B8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8051F3BC: jal         0x8051F0D0
    // 0x8051F3C0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_8051F0D0(rdram, ctx);
        goto after_0;
    // 0x8051F3C0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8051F3C4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8051F3C8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8051F3CC: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8051F3D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051F3D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051F3D8: jr          $ra
    // 0x8051F3DC: nop

    return;
    // 0x8051F3DC: nop

;}
RECOMP_FUNC void func_805A2B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A2B28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A2B2C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805A2B30: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805A2B34: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x805A2B38: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x805A2B3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A2B40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805A2B44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805A2B48: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x805A2B4C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x805A2B50: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x805A2B54: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x805A2B58: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(411, 0X1D84) << 16);
    // 0x805A2B5C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805A2B60: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805A2B64: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x805A2B68: lw          $t9, 0x30F4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(411, 0X1D84));
    // 0x805A2B6C: lui         $t0, 0x805A
    ctx->r8 = S32(RELOC_HI16(411, 0X1D5C) << 16);
    // 0x805A2B70: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x805A2B74: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x805A2B78: lw          $t0, 0x30CC($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(411, 0X1D5C));
    // 0x805A2B7C: sw          $t0, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r8;
    // 0x805A2B80: jal         0x805A1400
    // 0x805A2B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805A1400(rdram, ctx);
        goto after_0;
    // 0x805A2B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A2B88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A2B8C: jal         0x805A2ACC
    // 0x805A2B90: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_805A2ACC(rdram, ctx);
        goto after_1;
    // 0x805A2B90: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x805A2B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A2B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A2B9C: jr          $ra
    // 0x805A2BA0: nop

    return;
    // 0x805A2BA0: nop

    // 0x805A2BA4: nop

    // 0x805A2BA8: nop

    // 0x805A2BAC: nop

;}
RECOMP_FUNC void func_806AA06C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA06C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806AA070: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AA074: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AA078: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AA07C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806AA080: jal         0x806A9BBC
    // 0x806AA084: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_806A9BBC(rdram, ctx);
        goto after_0;
    // 0x806AA084: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x806AA088: beq         $v0, $zero, L_806AA0A0
    if (ctx->r2 == 0) {
        // 0x806AA08C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806AA0A0;
    }
    // 0x806AA08C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AA090: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AA094: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x806AA098: jal         0x806AA784
    // 0x806AA09C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806AA784(rdram, ctx);
        goto after_1;
    // 0x806AA09C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_1:
L_806AA0A0:
    // 0x806AA0A0: jal         0x806A99EC
    // 0x806AA0A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806A99EC(rdram, ctx);
        goto after_2;
    // 0x806AA0A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806AA0A8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806AA0AC: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    // 0x806AA0B0: beql        $a1, $zero, L_806AA0EC
    if (ctx->r5 == 0) {
        // 0x806AA0B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806AA0EC;
    }
    goto skip_0;
    // 0x806AA0B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806AA0B8: jal         0x80047EB0
    // 0x806AA0BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80047EB0(rdram, ctx);
        goto after_3;
    // 0x806AA0BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806AA0C0: bnel        $v0, $zero, L_806AA0EC
    if (ctx->r2 != 0) {
        // 0x806AA0C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806AA0EC;
    }
    goto skip_1;
    // 0x806AA0C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806AA0C8: lw          $v0, 0x180($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X180);
    // 0x806AA0CC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x806AA0D0: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806AA0D4: beq         $v0, $zero, L_806AA0E8
    if (ctx->r2 == 0) {
        // 0x806AA0D8: sw          $zero, 0xC($t8)
        MEM_W(0XC, ctx->r24) = 0;
            goto L_806AA0E8;
    }
    // 0x806AA0D8: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
    // 0x806AA0DC: addiu       $t9, $t9, -0x7218
    ctx->r25 = ADD32(ctx->r25, -0X7218);
    // 0x806AA0E0: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x806AA0E4: sw          $zero, 0x1D8($v0)
    MEM_W(0X1D8, ctx->r2) = 0;
L_806AA0E8:
    // 0x806AA0E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806AA0EC:
    // 0x806AA0EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AA0F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806AA0F4: jr          $ra
    // 0x806AA0F8: nop

    return;
    // 0x806AA0F8: nop

;}
RECOMP_FUNC void func_806ECE3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ECE3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806ECE40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806ECE44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806ECE48: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806ECE4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806ECE50: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806ECE54: jal         0x800577D8
    // 0x806ECE58: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806ECE58: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x806ECE5C: jal         0x806EC444
    // 0x806ECE60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC444(rdram, ctx);
        goto after_1;
    // 0x806ECE60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806ECE64: jal         0x806EC4B0
    // 0x806ECE68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC4B0(rdram, ctx);
        goto after_2;
    // 0x806ECE68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806ECE6C: jal         0x806EC584
    // 0x806ECE70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC584(rdram, ctx);
        goto after_3;
    // 0x806ECE70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806ECE74: bne         $v0, $zero, L_806ECE98
    if (ctx->r2 != 0) {
        // 0x806ECE78: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_806ECE98;
    }
    // 0x806ECE78: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x806ECE7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECE80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ECE84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806ECE88: jal         0x806ED360
    // 0x806ECE8C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_4;
    // 0x806ECE8C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806ECE90: b           L_806ECEF0
    // 0x806ECE94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806ECEF0;
    // 0x806ECE94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ECE98:
    // 0x806ECE98: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806ECE9C: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x806ECEA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECEA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ECEA8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806ECEAC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806ECEB0: bc1fl       L_806ECEF0
    if (!c1cs) {
        // 0x806ECEB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806ECEF0;
    }
    goto skip_0;
    // 0x806ECEB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806ECEB8: jal         0x806ED360
    // 0x806ECEBC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_5;
    // 0x806ECEBC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
    // 0x806ECEC0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806ECEC4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806ECEC8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806ECECC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806ECED0: jal         0x806EC03C
    // 0x806ECED4: nop

    func_806EC03C(rdram, ctx);
        goto after_6;
    // 0x806ECED4: nop

    after_6:
    // 0x806ECED8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806ECEDC: swc1        $f0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f0.u32l;
    // 0x806ECEE0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x806ECEE4: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806ECEE8: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    // 0x806ECEEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ECEF0:
    // 0x806ECEF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806ECEF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806ECEF8: jr          $ra
    // 0x806ECEFC: nop

    return;
    // 0x806ECEFC: nop

;}
RECOMP_FUNC void func_800305D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800305D0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x800305D4: lw          $t6, -0x7280($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7280);
    // 0x800305D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800305DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800305E0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800305E4: bne         $t6, $at, L_80030600
    if (ctx->r14 != ctx->r1) {
        // 0x800305E8: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_80030600;
    }
    // 0x800305E8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x800305EC: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x800305F0: addiu       $t7, $t7, 0x63C
    ctx->r15 = ADD32(ctx->r15, 0X63C);
    // 0x800305F4: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x800305F8: b           L_8003062C
    // 0x800305FC: sb          $zero, 0x1AC($v1)
    MEM_B(0X1AC, ctx->r3) = 0;
        goto L_8003062C;
    // 0x800305FC: sb          $zero, 0x1AC($v1)
    MEM_B(0X1AC, ctx->r3) = 0;
L_80030600:
    // 0x80030600: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80030604: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x80030608: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8003060C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80030610: jal         0x80065ABC
    // 0x80030614: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x80030614: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80030618: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003061C: jal         0x80028220
    // 0x80030620: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    func_80028220(rdram, ctx);
        goto after_1;
    // 0x80030620: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    after_1:
    // 0x80030624: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80030628: sw          $v0, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->r2;
L_8003062C:
    // 0x8003062C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030630: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80030634: jr          $ra
    // 0x80030638: nop

    return;
    // 0x80030638: nop

;}
RECOMP_FUNC void func_8064AF08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064AF08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064AF0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064AF10: jal         0x8004700C
    // 0x8064AF14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8064AF14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064AF18: beq         $v0, $zero, L_8064AF78
    if (ctx->r2 == 0) {
        // 0x8064AF1C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8064AF78;
    }
    // 0x8064AF1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064AF20: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064AF24: blez        $v1, L_8064AF34
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8064AF28: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8064AF34;
    }
    // 0x8064AF28: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8064AF2C: b           L_8064AF78
    // 0x8064AF30: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064AF78;
    // 0x8064AF30: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064AF34:
    // 0x8064AF34: lwc1        $f4, 0x88($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8064AF38: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064AF3C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8064AF40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8064AF44: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8064AF48: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8064AF4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064AF50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8064AF54: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8064AF58: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8064AF5C: nop

    // 0x8064AF60: bc1fl       L_8064AF7C
    if (!c1cs) {
        // 0x8064AF64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064AF7C;
    }
    goto skip_0;
    // 0x8064AF64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064AF68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8064AF6C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064AF70: jal         0x8064B3E0
    // 0x8064AF74: swc1        $f10, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f10.u32l;
    func_8064B3E0(rdram, ctx);
        goto after_1;
    // 0x8064AF74: swc1        $f10, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f10.u32l;
    after_1:
L_8064AF78:
    // 0x8064AF78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064AF7C:
    // 0x8064AF7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064AF80: jr          $ra
    // 0x8064AF84: nop

    return;
    // 0x8064AF84: nop

;}
RECOMP_FUNC void func_8069B81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069B81C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069B820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069B824: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069B828: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(565, 0X1840) << 16);
    // 0x8069B82C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8069B830: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8069B834: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8069B838: lw          $t8, -0x3AF0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(565, 0X1840));
    // 0x8069B83C: sh          $t8, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r24;
    // 0x8069B840: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8069B844: bne         $t9, $zero, L_8069B8B0
    if (ctx->r25 != 0) {
        // 0x8069B848: nop
    
            goto L_8069B8B0;
    }
    // 0x8069B848: nop

    // 0x8069B84C: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    // 0x8069B850: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(565, 0X1938) << 16);
    // 0x8069B854: bne         $t0, $zero, L_8069B8B0
    if (ctx->r8 != 0) {
        // 0x8069B858: nop
    
            goto L_8069B8B0;
    }
    // 0x8069B858: nop

    // 0x8069B85C: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8069B860: lwc1        $f4, -0x39F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(565, 0X1938));
    // 0x8069B864: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8069B868: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8069B86C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8069B870: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8069B874: nop

    // 0x8069B878: bc1fl       L_8069B890
    if (!c1cs) {
        // 0x8069B87C: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8069B890;
    }
    goto skip_0;
    // 0x8069B87C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x8069B880: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8069B884: nop

    // 0x8069B888: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8069B88C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_8069B890:
    // 0x8069B890: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8069B894: nop

    // 0x8069B898: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8069B89C: nop

    // 0x8069B8A0: bc1fl       L_8069B8B0
    if (!c1cs) {
        // 0x8069B8A4: swc1        $f0, 0x50($a0)
        MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
            goto L_8069B8B0;
    }
    goto skip_1;
    // 0x8069B8A4: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    skip_1:
    // 0x8069B8A8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8069B8AC: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
L_8069B8B0:
    // 0x8069B8B0: jal         0x8069B588
    // 0x8069B8B4: nop

    func_8069B588(rdram, ctx);
        goto after_0;
    // 0x8069B8B4: nop

    after_0:
    // 0x8069B8B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069B8BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069B8C0: jr          $ra
    // 0x8069B8C4: nop

    return;
    // 0x8069B8C4: nop

;}
RECOMP_FUNC void func_80073390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073390: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073398: sw          $a1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r5;
    // 0x8007339C: jal         0x80073274
    // 0x800733A0: sw          $a2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r6;
    func_80073274(rdram, ctx);
        goto after_0;
    // 0x800733A0: sw          $a2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r6;
    after_0:
    // 0x800733A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800733A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800733AC: jr          $ra
    // 0x800733B0: nop

    return;
    // 0x800733B0: nop

;}
RECOMP_FUNC void func_807A6A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6A0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A6A10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A6A14: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A6A18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x807A6A1C: bne         $v1, $zero, L_807A6A38
    if (ctx->r3 != 0) {
        // 0x807A6A20: nop
    
            goto L_807A6A38;
    }
    // 0x807A6A20: nop

    // 0x807A6A24: jal         0x80045A34
    // 0x807A6A28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807A6A28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807A6A2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807A6A30: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x807A6A34: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
L_807A6A38:
    // 0x807A6A38: bne         $v1, $zero, L_807A6A48
    if (ctx->r3 != 0) {
        // 0x807A6A3C: nop
    
            goto L_807A6A48;
    }
    // 0x807A6A3C: nop

    // 0x807A6A40: b           L_807A6A54
    // 0x807A6A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807A6A54;
    // 0x807A6A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807A6A48:
    // 0x807A6A48: jal         0x807A69FC
    // 0x807A6A4C: nop

    func_807A69FC(rdram, ctx);
        goto after_1;
    // 0x807A6A4C: nop

    after_1:
    // 0x807A6A50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807A6A54:
    // 0x807A6A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A6A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A6A5C: jr          $ra
    // 0x807A6A60: nop

    return;
    // 0x807A6A60: nop

;}
RECOMP_FUNC void func_8042BFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042BFF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8042BFF8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8042BFFC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8042C000: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8042C004: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8042C008: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042C00C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042C010: jal         0x8042A9DC
    // 0x8042C014: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_8042A9DC(rdram, ctx);
        goto after_0;
    // 0x8042C014: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x8042C018: jal         0x8042BB3C
    // 0x8042C01C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BB3C(rdram, ctx);
        goto after_1;
    // 0x8042C01C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8042C020: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042C024: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8042C028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C02C: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8042C030: beq         $at, $zero, L_8042C07C
    if (ctx->r1 == 0) {
        // 0x8042C034: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8042C07C;
    }
    // 0x8042C034: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8042C038: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8042C03C: mfhi        $t7
    ctx->r15 = hi;
    // 0x8042C040: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8042C044: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8042C048: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8042C04C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8042C050: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8042C054: jal         0x80066DE4
    // 0x8042C058: nop

    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8042C058: nop

    after_2:
    // 0x8042C05C: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8042C060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C064: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8042C068: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8042C06C: jal         0x8042B938
    // 0x8042C070: nop

    func_8042B938(rdram, ctx);
        goto after_3;
    // 0x8042C070: nop

    after_3:
    // 0x8042C074: b           L_8042C084
    // 0x8042C078: nop

        goto L_8042C084;
    // 0x8042C078: nop

L_8042C07C:
    // 0x8042C07C: jal         0x8042B938
    // 0x8042C080: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8042B938(rdram, ctx);
        goto after_4;
    // 0x8042C080: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
L_8042C084:
    // 0x8042C084: jal         0x8042B810
    // 0x8042C088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042B810(rdram, ctx);
        goto after_5;
    // 0x8042C088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8042C08C: lw          $t8, 0x1E0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042C090: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x8042C094: beql        $at, $zero, L_8042C0D4
    if (ctx->r1 == 0) {
        // 0x8042C098: lw          $t2, 0x24($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X24);
            goto L_8042C0D4;
    }
    goto skip_0;
    // 0x8042C098: lw          $t2, 0x24($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X24);
    skip_0:
    // 0x8042C09C: jal         0x8042B410
    // 0x8042C0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042B410(rdram, ctx);
        goto after_6;
    // 0x8042C0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8042C0A4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8042C0A8: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x8042C0AC: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x8042C0B0: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x8042C0B4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8042C0B8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8042C0BC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8042C0C0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8042C0C4: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x8042C0C8: jal         0x8042B8A0
    // 0x8042C0CC: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    func_8042B8A0(rdram, ctx);
        goto after_7;
    // 0x8042C0CC: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    after_7:
    // 0x8042C0D0: lw          $t2, 0x24($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X24);
L_8042C0D4:
    // 0x8042C0D4: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8042C0D8: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x8042C0DC: sb          $zero, 0x30($t2)
    MEM_B(0X30, ctx->r10) = 0;
    // 0x8042C0E0: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042C0E4: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    // 0x8042C0E8: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x8042C0EC: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x8042C0F0: bne         $at, $zero, L_8042C11C
    if (ctx->r1 != 0) {
        // 0x8042C0F4: andi        $t6, $v0, 0x4
        ctx->r14 = ctx->r2 & 0X4;
            goto L_8042C11C;
    }
    // 0x8042C0F4: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x8042C0F8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8042C0FC: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x8042C100: addiu       $t5, $zero, 0xA0
    ctx->r13 = ADD32(0, 0XA0);
    // 0x8042C104: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8042C108: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8042C10C: jal         0x8042B8A0
    // 0x8042C110: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_8042B8A0(rdram, ctx);
        goto after_8;
    // 0x8042C110: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_8:
    // 0x8042C114: b           L_8042C184
    // 0x8042C118: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8042C184;
    // 0x8042C118: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8042C11C:
    // 0x8042C11C: beq         $t6, $zero, L_8042C158
    if (ctx->r14 == 0) {
        // 0x8042C120: addiu       $a1, $zero, 0xA0
        ctx->r5 = ADD32(0, 0XA0);
            goto L_8042C158;
    }
    // 0x8042C120: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8042C124: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8042C128: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8042C12C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8042C130: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8042C134: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8042C138: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8042C13C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8042C140: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8042C144: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8042C148: jal         0x8042B8A0
    // 0x8042C14C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    func_8042B8A0(rdram, ctx);
        goto after_9;
    // 0x8042C14C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_9:
    // 0x8042C150: b           L_8042C184
    // 0x8042C154: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8042C184;
    // 0x8042C154: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8042C158:
    // 0x8042C158: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8042C15C: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x8042C160: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x8042C164: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x8042C168: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8042C16C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8042C170: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8042C174: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x8042C178: jal         0x8042B8A0
    // 0x8042C17C: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    func_8042B8A0(rdram, ctx);
        goto after_10;
    // 0x8042C17C: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    after_10:
    // 0x8042C180: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8042C184:
    // 0x8042C184: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8042C188: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8042C18C: jr          $ra
    // 0x8042C190: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8042C190: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80675FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675FEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80675FF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80675FF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80675FF8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80675FFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80676000: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80676004: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80676008: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8067600C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80676010: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80676014: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80676018: nop

    // 0x8067601C: bc1f        L_8067603C
    if (!c1cs) {
        // 0x80676020: nop
    
            goto L_8067603C;
    }
    // 0x80676020: nop

    // 0x80676024: jal         0x80677A88
    // 0x80676028: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80677A88(rdram, ctx);
        goto after_0;
    // 0x80676028: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8067602C: jal         0x80675B9C
    // 0x80676030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675B9C(rdram, ctx);
        goto after_1;
    // 0x80676030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80676034: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80676038: sh          $zero, 0x2($t7)
    MEM_H(0X2, ctx->r15) = 0;
L_8067603C:
    // 0x8067603C: jal         0x80675CD0
    // 0x80676040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675CD0(rdram, ctx);
        goto after_2;
    // 0x80676040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80676044: bnel        $v0, $zero, L_80676058
    if (ctx->r2 != 0) {
        // 0x80676048: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80676058;
    }
    goto skip_0;
    // 0x80676048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8067604C: jal         0x80675D48
    // 0x80676050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675D48(rdram, ctx);
        goto after_3;
    // 0x80676050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80676054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80676058:
    // 0x80676058: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067605C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80676060: jr          $ra
    // 0x80676064: nop

    return;
    // 0x80676064: nop

;}
RECOMP_FUNC void func_804470A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804470A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804470A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804470A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804470AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804470B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804470B4: bne         $a2, $zero, L_804470E4
    if (ctx->r6 != 0) {
        // 0x804470B8: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_804470E4;
    }
    // 0x804470B8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804470BC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x804470C0: lw          $v1, 0xF0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XF0);
    // 0x804470C4: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x804470C8: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x804470CC: bne         $at, $zero, L_80447120
    if (ctx->r1 != 0) {
        // 0x804470D0: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_80447120;
    }
    // 0x804470D0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804470D4: jal         0x80445F10
    // 0x804470D8: nop

    func_80445F10(rdram, ctx);
        goto after_0;
    // 0x804470D8: nop

    after_0:
    // 0x804470DC: b           L_80447124
    // 0x804470E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80447124;
    // 0x804470E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804470E4:
    // 0x804470E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804470E8: bnel        $a2, $at, L_80447110
    if (ctx->r6 != ctx->r1) {
        // 0x804470EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80447110;
    }
    goto skip_0;
    // 0x804470EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x804470F0: jal         0x80445EC8
    // 0x804470F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80445EC8(rdram, ctx);
        goto after_1;
    // 0x804470F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x804470F8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804470FC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447100: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447104: b           L_80447120
    // 0x80447108: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
        goto L_80447120;
    // 0x80447108: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
    // 0x8044710C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80447110:
    // 0x80447110: bnel        $a2, $at, L_80447124
    if (ctx->r6 != ctx->r1) {
        // 0x80447114: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80447124;
    }
    goto skip_1;
    // 0x80447114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80447118: jal         0x80445F10
    // 0x8044711C: nop

    func_80445F10(rdram, ctx);
        goto after_2;
    // 0x8044711C: nop

    after_2:
L_80447120:
    // 0x80447120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80447124:
    // 0x80447124: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8044712C: jr          $ra
    // 0x80447130: nop

    return;
    // 0x80447130: nop

;}
RECOMP_FUNC void func_8045696C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045696C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80456970: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80456974: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80456978: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045697C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80456980: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80456984: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80456988: sw          $t6, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r14;
    // 0x8045698C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80456990: jal         0x8044EFA0
    // 0x80456994: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x80456994: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x80456998: jal         0x804449C0
    // 0x8045699C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804449C0(rdram, ctx);
        goto after_1;
    // 0x8045699C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804569A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804569A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804569A8: jal         0x80450490
    // 0x804569AC: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_80450490(rdram, ctx);
        goto after_2;
    // 0x804569AC: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_2:
    // 0x804569B0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x804569B4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804569B8: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x804569BC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x804569C0: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    // 0x804569C4: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13D7C) << 16);
    // 0x804569C8: lw          $t9, -0x7EA4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13D7C));
    // 0x804569CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804569D0: jalr        $t9
    // 0x804569D4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x804569D4: nop

    after_3:
    // 0x804569D8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x804569DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804569E0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804569E4: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x804569E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804569EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x804569F0: jal         0x80455D88
    // 0x804569F4: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    func_80455D88(rdram, ctx);
        goto after_4;
    // 0x804569F4: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    after_4:
    // 0x804569F8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x804569FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80456A00: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80456A04: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80456A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456A0C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80456A10: jal         0x80455D88
    // 0x80456A14: swc1        $f6, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f6.u32l;
    func_80455D88(rdram, ctx);
        goto after_5;
    // 0x80456A14: swc1        $f6, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f6.u32l;
    after_5:
    // 0x80456A18: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80456A1C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80456A20: lw          $t2, 0xFB8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XFB8);
    // 0x80456A24: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80456A28: srl         $t4, $t3, 30
    ctx->r12 = S32(U32(ctx->r11) >> 30);
    // 0x80456A2C: bnel        $t4, $zero, L_80456B58
    if (ctx->r12 != 0) {
        // 0x80456A30: lbu         $v0, 0xF5D($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
            goto L_80456B58;
    }
    goto skip_0;
    // 0x80456A30: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
    skip_0:
    // 0x80456A34: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
    // 0x80456A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456A3C: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456A40: bne         $v0, $zero, L_80456A80
    if (ctx->r2 != 0) {
        // 0x80456A44: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80456A80;
    }
    // 0x80456A44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80456A48: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141E8) << 16);
    // 0x80456A4C: lwc1        $f0, -0x7A38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141E8));
    // 0x80456A50: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80456A54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80456A58: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141EC) << 16);
    // 0x80456A5C: lwc1        $f10, -0x7A34($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141EC));
    // 0x80456A60: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80456A64: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80456A68: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456A6C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80456A70: jal         0x80444B28
    // 0x80456A74: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80444B28(rdram, ctx);
        goto after_6;
    // 0x80456A74: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80456A78: b           L_80456C50
    // 0x80456A7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456C50;
    // 0x80456A7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456A80:
    // 0x80456A80: bne         $v0, $at, L_80456AC4
    if (ctx->r2 != ctx->r1) {
        // 0x80456A84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456AC4;
    }
    // 0x80456A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456A88: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141F0) << 16);
    // 0x80456A8C: lwc1        $f0, -0x7A30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141F0));
    // 0x80456A90: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80456A94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80456A98: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141F4) << 16);
    // 0x80456A9C: lwc1        $f18, -0x7A2C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141F4));
    // 0x80456AA0: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456AA4: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80456AA8: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80456AAC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456AB0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80456AB4: jal         0x80444B28
    // 0x80456AB8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_80444B28(rdram, ctx);
        goto after_7;
    // 0x80456AB8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x80456ABC: b           L_80456C50
    // 0x80456AC0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456C50;
    // 0x80456AC0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456AC4:
    // 0x80456AC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80456AC8: bne         $v0, $at, L_80456B0C
    if (ctx->r2 != ctx->r1) {
        // 0x80456ACC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456B0C;
    }
    // 0x80456ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456AD0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141F8) << 16);
    // 0x80456AD4: lwc1        $f0, -0x7A28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141F8));
    // 0x80456AD8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80456ADC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80456AE0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141FC) << 16);
    // 0x80456AE4: lwc1        $f6, -0x7A24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141FC));
    // 0x80456AE8: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456AEC: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x80456AF0: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80456AF4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456AF8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80456AFC: jal         0x80444B28
    // 0x80456B00: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80444B28(rdram, ctx);
        goto after_8;
    // 0x80456B00: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x80456B04: b           L_80456C50
    // 0x80456B08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456C50;
    // 0x80456B08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456B0C:
    // 0x80456B0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80456B10: bne         $v0, $at, L_80456C4C
    if (ctx->r2 != ctx->r1) {
        // 0x80456B14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456C4C;
    }
    // 0x80456B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456B18: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14200) << 16);
    // 0x80456B1C: lwc1        $f0, -0x7A20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14200));
    // 0x80456B20: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80456B24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80456B28: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14204) << 16);
    // 0x80456B2C: lwc1        $f10, -0x7A1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14204));
    // 0x80456B30: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456B34: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80456B38: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80456B3C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456B40: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80456B44: jal         0x80444B28
    // 0x80456B48: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80444B28(rdram, ctx);
        goto after_9;
    // 0x80456B48: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80456B4C: b           L_80456C50
    // 0x80456B50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456C50;
    // 0x80456B50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80456B54: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
L_80456B58:
    // 0x80456B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456B5C: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456B60: bne         $v0, $zero, L_80456B98
    if (ctx->r2 != 0) {
        // 0x80456B64: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80456B98;
    }
    // 0x80456B64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80456B68: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14208) << 16);
    // 0x80456B6C: lwc1        $f0, -0x7A18($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14208));
    // 0x80456B70: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80456B74: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80456B78: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80456B7C: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80456B80: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80456B84: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456B88: jal         0x80444B28
    // 0x80456B8C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80444B28(rdram, ctx);
        goto after_10;
    // 0x80456B8C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x80456B90: b           L_80456C50
    // 0x80456B94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456C50;
    // 0x80456B94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456B98:
    // 0x80456B98: bne         $v0, $at, L_80456BD4
    if (ctx->r2 != ctx->r1) {
        // 0x80456B9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456BD4;
    }
    // 0x80456B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456BA0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1420C) << 16);
    // 0x80456BA4: lwc1        $f0, -0x7A14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1420C));
    // 0x80456BA8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80456BAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80456BB0: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456BB4: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80456BB8: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80456BBC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80456BC0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456BC4: jal         0x80444B28
    // 0x80456BC8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80444B28(rdram, ctx);
        goto after_11;
    // 0x80456BC8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x80456BCC: b           L_80456C50
    // 0x80456BD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456C50;
    // 0x80456BD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456BD4:
    // 0x80456BD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80456BD8: bne         $v0, $at, L_80456C14
    if (ctx->r2 != ctx->r1) {
        // 0x80456BDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456C14;
    }
    // 0x80456BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456BE0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14210) << 16);
    // 0x80456BE4: lwc1        $f0, -0x7A10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14210));
    // 0x80456BE8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80456BEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80456BF0: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456BF4: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x80456BF8: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80456BFC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80456C00: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456C04: jal         0x80444B28
    // 0x80456C08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80444B28(rdram, ctx);
        goto after_12;
    // 0x80456C08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x80456C0C: b           L_80456C50
    // 0x80456C10: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456C50;
    // 0x80456C10: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456C14:
    // 0x80456C14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80456C18: bne         $v0, $at, L_80456C4C
    if (ctx->r2 != ctx->r1) {
        // 0x80456C1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456C4C;
    }
    // 0x80456C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456C20: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14214) << 16);
    // 0x80456C24: lwc1        $f0, -0x7A0C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14214));
    // 0x80456C28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80456C2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80456C30: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456C34: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80456C38: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80456C3C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80456C40: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456C44: jal         0x80444B28
    // 0x80456C48: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80444B28(rdram, ctx);
        goto after_13;
    // 0x80456C48: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
L_80456C4C:
    // 0x80456C4C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456C50:
    // 0x80456C50: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80456C54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80456C58: jr          $ra
    // 0x80456C5C: nop

    return;
    // 0x80456C5C: nop

;}
RECOMP_FUNC void func_8000335C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000335C: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80003360: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80003364: addiu       $v0, $v0, 0x4D56
    ctx->r2 = ADD32(ctx->r2, 0X4D56);
    // 0x80003368: addiu       $v1, $v1, 0x4D10
    ctx->r3 = ADD32(ctx->r3, 0X4D10);
    // 0x8000336C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80003370: lbu         $t6, 0x2996($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2996);
L_80003374:
    // 0x80003374: beql        $a0, $t6, L_80003384
    if (ctx->r4 == ctx->r14) {
        // 0x80003378: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80003384;
    }
    goto skip_0;
    // 0x80003378: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8000337C: sb          $zero, 0x2996($v1)
    MEM_B(0X2996, ctx->r3) = 0;
    // 0x80003380: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80003384:
    // 0x80003384: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80003388: bnel        $at, $zero, L_80003374
    if (ctx->r1 != 0) {
        // 0x8000338C: lbu         $t6, 0x2996($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X2996);
            goto L_80003374;
    }
    goto skip_1;
    // 0x8000338C: lbu         $t6, 0x2996($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2996);
    skip_1:
    // 0x80003390: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80003394: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80003398: addiu       $v0, $v0, 0x4D56
    ctx->r2 = ADD32(ctx->r2, 0X4D56);
    // 0x8000339C: addiu       $v1, $v1, 0x4D10
    ctx->r3 = ADD32(ctx->r3, 0X4D10);
    // 0x800033A0: lbu         $t7, 0x2950($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2950);
L_800033A4:
    // 0x800033A4: beql        $a0, $t7, L_800033B4
    if (ctx->r4 == ctx->r15) {
        // 0x800033A8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800033B4;
    }
    goto skip_2;
    // 0x800033A8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x800033AC: sb          $zero, 0x2950($v1)
    MEM_B(0X2950, ctx->r3) = 0;
    // 0x800033B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800033B4:
    // 0x800033B4: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800033B8: bnel        $at, $zero, L_800033A4
    if (ctx->r1 != 0) {
        // 0x800033BC: lbu         $t7, 0x2950($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X2950);
            goto L_800033A4;
    }
    goto skip_3;
    // 0x800033BC: lbu         $t7, 0x2950($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2950);
    skip_3:
    // 0x800033C0: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x800033C4: lbu         $t8, 0x76EC($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X76EC);
    // 0x800033C8: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800033CC: addiu       $v1, $v1, 0x4D12
    ctx->r3 = ADD32(ctx->r3, 0X4D12);
    // 0x800033D0: beq         $a0, $t8, L_800033E0
    if (ctx->r4 == ctx->r24) {
        // 0x800033D4: lui         $t9, 0x800B
        ctx->r25 = S32(0X800B << 16);
            goto L_800033E0;
    }
    // 0x800033D4: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x800033D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800033DC: sb          $zero, 0x76EC($at)
    MEM_B(0X76EC, ctx->r1) = 0;
L_800033E0:
    // 0x800033E0: lbu         $t9, 0x76ED($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X76ED);
    // 0x800033E4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800033E8: addiu       $v0, $v0, 0x4D56
    ctx->r2 = ADD32(ctx->r2, 0X4D56);
    // 0x800033EC: beq         $a0, $t9, L_800033F8
    if (ctx->r4 == ctx->r25) {
        // 0x800033F0: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_800033F8;
    }
    // 0x800033F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800033F4: sb          $zero, 0x76ED($at)
    MEM_B(0X76ED, ctx->r1) = 0;
L_800033F8:
    // 0x800033F8: lbu         $t0, 0x29DC($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X29DC);
L_800033FC:
    // 0x800033FC: beql        $a0, $t0, L_8000340C
    if (ctx->r4 == ctx->r8) {
        // 0x80003400: lbu         $t1, 0x29DD($v1)
        ctx->r9 = MEM_BU(ctx->r3, 0X29DD);
            goto L_8000340C;
    }
    goto skip_4;
    // 0x80003400: lbu         $t1, 0x29DD($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X29DD);
    skip_4:
    // 0x80003404: sb          $zero, 0x29DC($v1)
    MEM_B(0X29DC, ctx->r3) = 0;
    // 0x80003408: lbu         $t1, 0x29DD($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X29DD);
L_8000340C:
    // 0x8000340C: beql        $a0, $t1, L_8000341C
    if (ctx->r4 == ctx->r9) {
        // 0x80003410: lbu         $t2, 0x29DE($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0X29DE);
            goto L_8000341C;
    }
    goto skip_5;
    // 0x80003410: lbu         $t2, 0x29DE($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X29DE);
    skip_5:
    // 0x80003414: sb          $zero, 0x29DD($v1)
    MEM_B(0X29DD, ctx->r3) = 0;
    // 0x80003418: lbu         $t2, 0x29DE($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X29DE);
L_8000341C:
    // 0x8000341C: beql        $a0, $t2, L_8000342C
    if (ctx->r4 == ctx->r10) {
        // 0x80003420: lbu         $t3, 0x29DF($v1)
        ctx->r11 = MEM_BU(ctx->r3, 0X29DF);
            goto L_8000342C;
    }
    goto skip_6;
    // 0x80003420: lbu         $t3, 0x29DF($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X29DF);
    skip_6:
    // 0x80003424: sb          $zero, 0x29DE($v1)
    MEM_B(0X29DE, ctx->r3) = 0;
    // 0x80003428: lbu         $t3, 0x29DF($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X29DF);
L_8000342C:
    // 0x8000342C: beql        $a0, $t3, L_8000343C
    if (ctx->r4 == ctx->r11) {
        // 0x80003430: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000343C;
    }
    goto skip_7;
    // 0x80003430: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_7:
    // 0x80003434: sb          $zero, 0x29DF($v1)
    MEM_B(0X29DF, ctx->r3) = 0;
    // 0x80003438: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8000343C:
    // 0x8000343C: bnel        $v1, $v0, L_800033FC
    if (ctx->r3 != ctx->r2) {
        // 0x80003440: lbu         $t0, 0x29DC($v1)
        ctx->r8 = MEM_BU(ctx->r3, 0X29DC);
            goto L_800033FC;
    }
    goto skip_8;
    // 0x80003440: lbu         $t0, 0x29DC($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X29DC);
    skip_8:
    // 0x80003444: jr          $ra
    // 0x80003448: nop

    return;
    // 0x80003448: nop

;}
RECOMP_FUNC void func_804373F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804373F0: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x804373F4: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x804373F8: mul.s       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x804373FC: nop

    // 0x80437400: mul.s       $f14, $f16, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80437404: add.s       $f0, $f2, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80437408: jr          $ra
    // 0x8043740C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    return;
    // 0x8043740C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
;}
RECOMP_FUNC void func_8042B938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042B938: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8042B93C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8042B940: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8042B944: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8042B948: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8042B94C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8042B950: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8042B954: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8042B958: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8042B95C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8042B960: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042B964: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x8042B968: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8042B96C: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8042B970: addiu       $s1, $zero, 0xA0
    ctx->r17 = ADD32(0, 0XA0);
    // 0x8042B974: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x8042B978: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x8042B97C: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x8042B980: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8042B984: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x8042B988: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8042B98C: lw          $t5, 0x38($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X38);
    // 0x8042B990: lw          $t1, 0x30($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X30);
    // 0x8042B994: lw          $t2, 0x28($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X28);
    // 0x8042B998: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8042B99C: lw          $t0, 0x38($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X38);
    // 0x8042B9A0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8042B9A4: cvt.s.w     $f28, $f8
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    ctx->f28.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8042B9A8: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8042B9AC: lw          $a2, 0x20($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X20);
    // 0x8042B9B0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8042B9B4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8042B9B8: addiu       $s0, $a2, 0xA0
    ctx->r16 = ADD32(ctx->r6, 0XA0);
    // 0x8042B9BC: c.lt.s      $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f28.fl < ctx->f24.fl;
    // 0x8042B9C0: cvt.s.w     $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8042B9C4: bc1f        L_8042B9D0
    if (!c1cs) {
        // 0x8042B9C8: cvt.s.w     $f26, $f4
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    ctx->f26.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8042B9D0;
    }
    // 0x8042B9C8: cvt.s.w     $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    ctx->f26.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8042B9CC: neg.s       $f28, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f28.fl = -ctx->f28.fl;
L_8042B9D0:
    // 0x8042B9D0: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
L_8042B9D4:
    // 0x8042B9D4: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8042B9D8: add.s       $f22, $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f14.fl;
    // 0x8042B9DC: jal         0x80066DE4
    // 0x8042B9E0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8042B9E0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x8042B9E4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8042B9E8: jal         0x80066E88
    // 0x8042B9EC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8042B9EC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_1:
    // 0x8042B9F0: mul.s       $f10, $f20, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x8042B9F4: addiu       $s1, $s1, -0x20
    ctx->r17 = ADD32(ctx->r17, -0X20);
    // 0x8042B9F8: addiu       $s0, $s0, -0x20
    ctx->r16 = ADD32(ctx->r16, -0X20);
    // 0x8042B9FC: mul.s       $f16, $f0, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8042BA00: nop

    // 0x8042BA04: mul.s       $f2, $f0, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8042BA08: add.s       $f24, $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f10.fl;
    // 0x8042BA0C: mul.s       $f12, $f20, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x8042BA10: sub.s       $f26, $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f26.fl = ctx->f26.fl - ctx->f16.fl;
    // 0x8042BA14: sub.s       $f18, $f24, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f24.fl - ctx->f2.fl;
    // 0x8042BA18: sub.s       $f6, $f26, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f26.fl - ctx->f12.fl;
    // 0x8042BA1C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8042BA20: add.s       $f10, $f24, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f24.fl + ctx->f2.fl;
    // 0x8042BA24: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8042BA28: add.s       $f18, $f26, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f26.fl + ctx->f12.fl;
    // 0x8042BA2C: sh          $t7, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r15;
    // 0x8042BA30: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8042BA34: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8042BA38: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8042BA3C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8042BA40: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x8042BA44: sh          $t9, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r25;
    // 0x8042BA48: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8042BA4C: sh          $t1, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r9;
    // 0x8042BA50: bgez        $s1, L_8042B9D4
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8042BA54: sh          $t3, 0x32($s0)
        MEM_H(0X32, ctx->r16) = ctx->r11;
            goto L_8042B9D4;
    }
    // 0x8042BA54: sh          $t3, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r11;
    // 0x8042BA58: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8042BA5C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8042BA60: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8042BA64: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8042BA68: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8042BA6C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8042BA70: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8042BA74: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8042BA78: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8042BA7C: jr          $ra
    // 0x8042BA80: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8042BA80: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_804381F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804381F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804381F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804381FC: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80438200: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80438204: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80438208: beq         $a1, $at, L_80438224
    if (ctx->r5 == ctx->r1) {
        // 0x8043820C: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_80438224;
    }
    // 0x8043820C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80438210: jal         0x80067878
    // 0x80438214: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x80438214: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80438218: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8043821C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80438220: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_80438224:
    // 0x80438224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80438228: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043822C: jr          $ra
    // 0x80438230: nop

    return;
    // 0x80438230: nop

;}
RECOMP_FUNC void func_804A1AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1AA0: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    // 0x804A1AA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804A1AA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804A1AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A1AB0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x804A1AB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A1AB8: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804A1ABC: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X3184) << 16);
    // 0x804A1AC0: lwc1        $f10, 0x35C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X3184));
    // 0x804A1AC4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804A1AC8: lwc1        $f2, 0x40($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804A1ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804A1AD0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804A1AD4: add.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x804A1AD8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x804A1ADC: nop

    // 0x804A1AE0: bc1fl       L_804A1AF4
    if (!c1cs) {
        // 0x804A1AE4: lw          $a1, 0x3C($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X3C);
            goto L_804A1AF4;
    }
    goto skip_0;
    // 0x804A1AE4: lw          $a1, 0x3C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X3C);
    skip_0:
    // 0x804A1AE8: b           L_804A1B34
    // 0x804A1AEC: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
        goto L_804A1B34;
    // 0x804A1AEC: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x804A1AF0: lw          $a1, 0x3C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X3C);
L_804A1AF4:
    // 0x804A1AF4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x804A1AF8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x804A1AFC: jal         0x804A1320
    // 0x804A1B00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_804A1320(rdram, ctx);
        goto after_0;
    // 0x804A1B00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A1B04: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x804A1B08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804A1B0C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804A1B10: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x804A1B14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804A1B18: bc1tl       L_804A1B34
    if (c1cs) {
        // 0x804A1B1C: swc1        $f2, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
            goto L_804A1B34;
    }
    goto skip_1;
    // 0x804A1B1C: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
    skip_1:
    // 0x804A1B20: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x804A1B24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804A1B28: b           L_804A1B34
    // 0x804A1B2C: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
        goto L_804A1B34;
    // 0x804A1B2C: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x804A1B30: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
L_804A1B34:
    // 0x804A1B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A1B38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804A1B3C: jr          $ra
    // 0x804A1B40: nop

    return;
    // 0x804A1B40: nop

;}
RECOMP_FUNC void func_80080D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080D54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80080D58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80080D5C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80080D60: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80080D64: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x80080D68: nop

    // 0x80080D6C: bc1tl       L_80080DAC
    if (c1cs) {
        // 0x80080D70: c.eq.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
            goto L_80080DAC;
    }
    goto skip_0;
    // 0x80080D70: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    skip_0:
    // 0x80080D74: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80080D78: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80080D7C: lwc1        $f16, 0x20($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80080D80: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80080D84: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80080D88: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80080D8C: nop

    // 0x80080D90: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80080D94: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80080D98: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80080D9C: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x80080DA0: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x80080DA4: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    // 0x80080DA8: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
L_80080DAC:
    // 0x80080DAC: nop

    // 0x80080DB0: bc1t        L_80080DEC
    if (c1cs) {
        // 0x80080DB4: nop
    
            goto L_80080DEC;
    }
    // 0x80080DB4: nop

    // 0x80080DB8: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80080DBC: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80080DC0: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80080DC4: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80080DC8: lwc1        $f8, 0x34($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80080DCC: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80080DD0: nop

    // 0x80080DD4: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80080DD8: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x80080DDC: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80080DE0: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80080DE4: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x80080DE8: swc1        $f10, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f10.u32l;
L_80080DEC:
    // 0x80080DEC: jr          $ra
    // 0x80080DF0: nop

    return;
    // 0x80080DF0: nop

;}
RECOMP_FUNC void func_8066B570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B570: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8066B574: jr          $ra
    // 0x8066B578: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    return;
    // 0x8066B578: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_805E1000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E1000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805E1004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805E1008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805E100C: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x805E1010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805E1014: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805E1018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E101C: jal         0x80048F84
    // 0x805E1020: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x805E1020: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805E1024: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805E1028: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805E102C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805E1030: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x805E1034: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805E1038: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x805E103C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805E1040: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x805E1044: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x805E1048: nop

    // 0x805E104C: bc1fl       L_805E105C
    if (!c1cs) {
        // 0x805E1050: lwc1        $f6, 0x40($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
            goto L_805E105C;
    }
    goto skip_0;
    // 0x805E1050: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    skip_0:
    // 0x805E1054: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x805E1058: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
L_805E105C:
    // 0x805E105C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x805E1060: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x805E1064: nop

    // 0x805E1068: bc1tl       L_805E10A4
    if (c1cs) {
        // 0x805E106C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805E10A4;
    }
    goto skip_1;
    // 0x805E106C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805E1070: jal         0x805E0E20
    // 0x805E1074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E0E20(rdram, ctx);
        goto after_1;
    // 0x805E1074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805E1078: beql        $v0, $zero, L_805E10A4
    if (ctx->r2 == 0) {
        // 0x805E107C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805E10A4;
    }
    goto skip_2;
    // 0x805E107C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805E1080: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x805E1084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E1088: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x805E108C: jal         0x8005FD1C
    // 0x805E1090: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    func_8005FD1C(rdram, ctx);
        goto after_2;
    // 0x805E1090: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    after_2:
    // 0x805E1094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E1098: jal         0x805E11E0
    // 0x805E109C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_805E11E0(rdram, ctx);
        goto after_3;
    // 0x805E109C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x805E10A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805E10A4:
    // 0x805E10A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805E10A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805E10AC: jr          $ra
    // 0x805E10B0: nop

    return;
    // 0x805E10B0: nop

;}
RECOMP_FUNC void func_8052E430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052E430: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052E434: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x8052E438: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8052E43C: lw          $a1, 0xF64($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XF64);
    // 0x8052E440: addiu       $t9, $t8, -0x419F
    ctx->r25 = ADD32(ctx->r24, -0X419F);
    // 0x8052E444: sltiu       $at, $t9, 0xD
    ctx->r1 = ctx->r25 < 0XD ? 1 : 0;
    // 0x8052E448: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8052E44C: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8052E450: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8052E454: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8052E458: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8052E45C: sllv        $a2, $t7, $a1
    ctx->r6 = S32(ctx->r15 << (ctx->r5 & 31));
    // 0x8052E460: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8052E464: beq         $at, $zero, L_8052E578
    if (ctx->r1 == 0) {
        // 0x8052E468: addu        $v1, $v0, $t6
        ctx->r3 = ADD32(ctx->r2, ctx->r14);
            goto L_8052E578;
    }
    // 0x8052E468: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x8052E46C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8052E470: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X23E0) << 16);
    // 0x8052E474: addu        $at, $at, $t9
    gpr jr_addend_8052E47C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8052E478: lw          $t9, 0x1A0($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(333, 0X23E0));
    // 0x8052E47C: jr          $t9
    // 0x8052E480: nop

    switch (jr_addend_8052E47C >> 2) {
        case 0: goto L_8052E504; break;
        case 1: goto L_8052E578; break;
        case 2: goto L_8052E504; break;
        case 3: goto L_8052E578; break;
        case 4: goto L_8052E578; break;
        case 5: goto L_8052E578; break;
        case 6: goto L_8052E578; break;
        case 7: goto L_8052E578; break;
        case 8: goto L_8052E578; break;
        case 9: goto L_8052E484; break;
        case 10: goto L_8052E484; break;
        case 11: goto L_8052E484; break;
        case 12: goto L_8052E484; break;
        default: switch_error(__func__, 0x8052E47C, 0x805301A0);
    }
    // 0x8052E480: nop

L_8052E484:
    // 0x8052E484: lw          $t2, 0x1164($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1164);
    // 0x8052E488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8052E48C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8052E490: blez        $t2, L_8052E578
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8052E494: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8052E578;
    }
    // 0x8052E494: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8052E498: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8052E49C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8052E4A0: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x8052E4A4: addiu       $t1, $v0, 0x1174
    ctx->r9 = ADD32(ctx->r2, 0X1174);
    // 0x8052E4A8: lw          $t3, 0x1168($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1168);
L_8052E4AC:
    // 0x8052E4AC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8052E4B0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8052E4B4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8052E4B8: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x8052E4BC: lwc1        $f4, 0xF6C($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XF6C);
    // 0x8052E4C0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8052E4C4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8052E4C8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8052E4CC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8052E4D0: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8052E4D4: nop

    // 0x8052E4D8: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8052E4DC: sh          $t8, -0x1E($a0)
    MEM_H(-0X1E, ctx->r4) = ctx->r24;
    // 0x8052E4E0: lbu         $t9, -0x1($t1)
    ctx->r25 = MEM_BU(ctx->r9, -0X1);
    // 0x8052E4E4: or          $t2, $t9, $t0
    ctx->r10 = ctx->r25 | ctx->r8;
    // 0x8052E4E8: sb          $t2, -0x1($t1)
    MEM_B(-0X1, ctx->r9) = ctx->r10;
    // 0x8052E4EC: lw          $t3, 0x1164($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1164);
    // 0x8052E4F0: slt         $at, $a1, $t3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8052E4F4: bnel        $at, $zero, L_8052E4AC
    if (ctx->r1 != 0) {
        // 0x8052E4F8: lw          $t3, 0x1168($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X1168);
            goto L_8052E4AC;
    }
    goto skip_0;
    // 0x8052E4F8: lw          $t3, 0x1168($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1168);
    skip_0:
    // 0x8052E4FC: b           L_8052E57C
    // 0x8052E500: lw          $a3, 0x1164($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X1164);
        goto L_8052E57C;
    // 0x8052E500: lw          $a3, 0x1164($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X1164);
L_8052E504:
    // 0x8052E504: lw          $t4, 0x1164($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1164);
    // 0x8052E508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8052E50C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8052E510: blez        $t4, L_8052E578
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8052E514: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8052E578;
    }
    // 0x8052E514: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8052E518: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8052E51C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8052E520: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x8052E524: addiu       $t1, $v0, 0x1174
    ctx->r9 = ADD32(ctx->r2, 0X1174);
    // 0x8052E528: lw          $t5, 0x1168($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1168);
L_8052E52C:
    // 0x8052E52C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8052E530: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8052E534: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8052E538: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x8052E53C: lwc1        $f10, 0xF6C($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XF6C);
    // 0x8052E540: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8052E544: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8052E548: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8052E54C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8052E550: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8052E554: nop

    // 0x8052E558: sh          $t9, -0x1E($a0)
    MEM_H(-0X1E, ctx->r4) = ctx->r25;
    // 0x8052E55C: lbu         $t2, -0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, -0X1);
    // 0x8052E560: or          $t3, $t2, $t0
    ctx->r11 = ctx->r10 | ctx->r8;
    // 0x8052E564: sb          $t3, -0x1($t1)
    MEM_B(-0X1, ctx->r9) = ctx->r11;
    // 0x8052E568: lw          $t4, 0x1164($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1164);
    // 0x8052E56C: slt         $at, $a1, $t4
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8052E570: bnel        $at, $zero, L_8052E52C
    if (ctx->r1 != 0) {
        // 0x8052E574: lw          $t5, 0x1168($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X1168);
            goto L_8052E52C;
    }
    goto skip_1;
    // 0x8052E574: lw          $t5, 0x1168($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1168);
    skip_1:
L_8052E578:
    // 0x8052E578: lw          $a3, 0x1164($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X1164);
L_8052E57C:
    // 0x8052E57C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8052E580: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8052E584: addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    // 0x8052E588: blez        $a3, L_8052E5EC
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8052E58C: nop
    
            goto L_8052E5EC;
    }
    // 0x8052E58C: nop

L_8052E590:
    // 0x8052E590: lh          $v1, 0x2($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X2);
    // 0x8052E594: lh          $t0, 0x22($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X22);
    // 0x8052E598: bnel        $v1, $t0, L_8052E5B0
    if (ctx->r3 != ctx->r8) {
        // 0x8052E59C: lh          $t7, 0x42($a0)
        ctx->r15 = MEM_H(ctx->r4, 0X42);
            goto L_8052E5B0;
    }
    goto skip_2;
    // 0x8052E59C: lh          $t7, 0x42($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X42);
    skip_2:
    // 0x8052E5A0: lh          $t5, 0x42($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X42);
    // 0x8052E5A4: beql        $t0, $t5, L_8052E5C0
    if (ctx->r8 == ctx->r13) {
        // 0x8052E5A8: addu        $t1, $a1, $v0
        ctx->r9 = ADD32(ctx->r5, ctx->r2);
            goto L_8052E5C0;
    }
    goto skip_3;
    // 0x8052E5A8: addu        $t1, $a1, $v0
    ctx->r9 = ADD32(ctx->r5, ctx->r2);
    skip_3:
    // 0x8052E5AC: lh          $t7, 0x42($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X42);
L_8052E5B0:
    // 0x8052E5B0: subu        $t6, $v1, $t0
    ctx->r14 = SUB32(ctx->r3, ctx->r8);
    // 0x8052E5B4: subu        $t8, $t0, $t7
    ctx->r24 = SUB32(ctx->r8, ctx->r15);
    // 0x8052E5B8: bne         $t6, $t8, L_8052E5DC
    if (ctx->r14 != ctx->r24) {
        // 0x8052E5BC: addu        $t1, $a1, $v0
        ctx->r9 = ADD32(ctx->r5, ctx->r2);
            goto L_8052E5DC;
    }
    // 0x8052E5BC: addu        $t1, $a1, $v0
    ctx->r9 = ADD32(ctx->r5, ctx->r2);
L_8052E5C0:
    // 0x8052E5C0: lbu         $t9, 0x1175($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X1175);
    // 0x8052E5C4: xori        $t2, $a2, 0xFF
    ctx->r10 = ctx->r6 ^ 0XFF;
    // 0x8052E5C8: addiu       $t1, $t1, 0x1174
    ctx->r9 = ADD32(ctx->r9, 0X1174);
    // 0x8052E5CC: and         $t3, $t9, $t2
    ctx->r11 = ctx->r25 & ctx->r10;
    // 0x8052E5D0: sb          $t3, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r11;
    // 0x8052E5D4: lw          $a3, 0x1164($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X1164);
    // 0x8052E5D8: addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
L_8052E5DC:
    // 0x8052E5DC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8052E5E0: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8052E5E4: bne         $at, $zero, L_8052E590
    if (ctx->r1 != 0) {
        // 0x8052E5E8: addiu       $a0, $a0, 0x20
        ctx->r4 = ADD32(ctx->r4, 0X20);
            goto L_8052E590;
    }
    // 0x8052E5E8: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
L_8052E5EC:
    // 0x8052E5EC: jr          $ra
    // 0x8052E5F0: nop

    return;
    // 0x8052E5F0: nop

;}
RECOMP_FUNC void func_80030BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030BDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030BE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030BE4: lw          $t6, 0x78($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X78);
    // 0x80030BE8: beql        $t6, $zero, L_80030CC0
    if (ctx->r14 == 0) {
        // 0x80030BEC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80030CC0;
    }
    goto skip_0;
    // 0x80030BEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80030BF0: lwc1        $f4, 0x1B8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1B8);
    // 0x80030BF4: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80030BF8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80030BFC: nop

    // 0x80030C00: bc1fl       L_80030C60
    if (!c1cs) {
        // 0x80030C04: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80030C60;
    }
    goto skip_1;
    // 0x80030C04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x80030C08: lbu         $t7, 0x1B4($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1B4);
    // 0x80030C0C: beql        $t7, $zero, L_80030C28
    if (ctx->r15 == 0) {
        // 0x80030C10: lbu         $t8, 0x165($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X165);
            goto L_80030C28;
    }
    goto skip_2;
    // 0x80030C10: lbu         $t8, 0x165($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X165);
    skip_2:
    // 0x80030C14: jal         0x80030BA8
    // 0x80030C18: nop

    func_80030BA8(rdram, ctx);
        goto after_0;
    // 0x80030C18: nop

    after_0:
    // 0x80030C1C: b           L_80030CC0
    // 0x80030C20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80030CC0;
    // 0x80030C20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030C24: lbu         $t8, 0x165($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X165);
L_80030C28:
    // 0x80030C28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80030C2C: bnel        $t8, $zero, L_80030C44
    if (ctx->r24 != 0) {
        // 0x80030C30: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80030C44;
    }
    goto skip_3;
    // 0x80030C30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x80030C34: jal         0x80030A98
    // 0x80030C38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80030A98(rdram, ctx);
        goto after_1;
    // 0x80030C38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80030C3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80030C40: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80030C44:
    // 0x80030C44: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80030C48: sb          $t9, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r25;
    // 0x80030C4C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x80030C50: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x80030C54: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x80030C58: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x80030C5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80030C60:
    // 0x80030C60: lwc1        $f8, 0xC8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80030C64: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80030C68: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80030C6C: nop

    // 0x80030C70: bc1fl       L_80030CC0
    if (!c1cs) {
        // 0x80030C74: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80030CC0;
    }
    goto skip_4;
    // 0x80030C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x80030C78: lwc1        $f0, -0x14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X14);
    // 0x80030C7C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80030C80: lwc1        $f16, -0x10($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X10);
    // 0x80030C84: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80030C88: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80030C8C: swc1        $f18, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f18.u32l;
    // 0x80030C90: lwc1        $f2, 0x6C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80030C94: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80030C98: nop

    // 0x80030C9C: bc1fl       L_80030CB8
    if (!c1cs) {
        // 0x80030CA0: swc1        $f2, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
            goto L_80030CB8;
    }
    goto skip_5;
    // 0x80030CA0: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    skip_5:
    // 0x80030CA4: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x80030CA8: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x80030CAC: b           L_80030CBC
    // 0x80030CB0: swc1        $f0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f0.u32l;
        goto L_80030CBC;
    // 0x80030CB0: swc1        $f0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f0.u32l;
    // 0x80030CB4: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
L_80030CB8:
    // 0x80030CB8: swc1        $f2, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f2.u32l;
L_80030CBC:
    // 0x80030CBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80030CC0:
    // 0x80030CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030CC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80030CC8: jr          $ra
    // 0x80030CCC: nop

    return;
    // 0x80030CCC: nop

;}
RECOMP_FUNC void func_8005D6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D6F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D6F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D6F8: jal         0x8005D608
    // 0x8005D6FC: nop

    func_8005D608(rdram, ctx);
        goto after_0;
    // 0x8005D6FC: nop

    after_0:
    // 0x8005D700: bne         $v0, $zero, L_8005D710
    if (ctx->r2 != 0) {
        // 0x8005D704: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005D710;
    }
    // 0x8005D704: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005D708: b           L_8005D720
    // 0x8005D70C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005D720;
    // 0x8005D70C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005D710:
    // 0x8005D710: addiu       $a0, $v1, 0x10
    ctx->r4 = ADD32(ctx->r3, 0X10);
    // 0x8005D714: jal         0x8005D320
    // 0x8005D718: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8005D320(rdram, ctx);
        goto after_1;
    // 0x8005D718: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8005D71C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8005D720:
    // 0x8005D720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D724: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005D728: jr          $ra
    // 0x8005D72C: nop

    return;
    // 0x8005D72C: nop

;}
RECOMP_FUNC void func_80736D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736D78: jr          $ra
    // 0x80736D7C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80736D7C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80716728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716728: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8071672C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80716730: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80716734: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80716738: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8071673C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80716740: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80716744: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80716748: addiu       $t6, $zero, 0x99C
    ctx->r14 = ADD32(0, 0X99C);
    // 0x8071674C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80716750: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80716754: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x80716758: addiu       $a1, $zero, 0x168
    ctx->r5 = ADD32(0, 0X168);
    // 0x8071675C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80716760: jal         0x8071637C
    // 0x80716764: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8071637C(rdram, ctx);
        goto after_0;
    // 0x80716764: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80716768: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8071676C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80716770: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80716774: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80716778: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x8071677C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x80716780: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80716784: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80716788: jr          $ra
    // 0x8071678C: nop

    return;
    // 0x8071678C: nop

;}
RECOMP_FUNC void func_806AEF88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AEF88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AEF8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AEF90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806AEF94: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AEF98: lw          $t9, 0x10($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X10);
    // 0x806AEF9C: jalr        $t9
    // 0x806AEFA0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806AEFA0: nop

    after_0:
    // 0x806AEFA4: jal         0x806AE458
    // 0x806AEFA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806AE458(rdram, ctx);
        goto after_1;
    // 0x806AEFA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806AEFAC: beq         $v0, $zero, L_806AEFC4
    if (ctx->r2 == 0) {
        // 0x806AEFB0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806AEFC4;
    }
    // 0x806AEFB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806AEFB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AEFB8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806AEFBC: jal         0x806AF64C
    // 0x806AEFC0: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_806AF64C(rdram, ctx);
        goto after_2;
    // 0x806AEFC0: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_2:
L_806AEFC4:
    // 0x806AEFC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AEFC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AEFCC: jr          $ra
    // 0x806AEFD0: nop

    return;
    // 0x806AEFD0: nop

;}
RECOMP_FUNC void func_8079862C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079862C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80798630: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x80798634: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80798638: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8079863C: addiu       $t3, $zero, 0x4001
    ctx->r11 = ADD32(0, 0X4001);
    // 0x80798640: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x80798644: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x80798648: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8079864C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80798650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80798654:
    // 0x80798654: beql        $a1, $zero, L_807986F4
    if (ctx->r5 == 0) {
        // 0x80798658: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_807986F4;
    }
    goto skip_0;
    // 0x80798658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
L_8079865C:
    // 0x8079865C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80798660: beq         $v0, $zero, L_807986E8
    if (ctx->r2 == 0) {
        // 0x80798664: nop
    
            goto L_807986E8;
    }
    // 0x80798664: nop

    // 0x80798668: beq         $a2, $v0, L_807986E0
    if (ctx->r6 == ctx->r2) {
        // 0x8079866C: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_807986E0;
    }
    // 0x8079866C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80798670: lh          $t6, 0x184($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X184);
    // 0x80798674: beq         $t6, $zero, L_80798690
    if (ctx->r14 == 0) {
        // 0x80798678: addiu       $t7, $v0, 0x188
        ctx->r15 = ADD32(ctx->r2, 0X188);
            goto L_80798690;
    }
    // 0x80798678: addiu       $t7, $v0, 0x188
    ctx->r15 = ADD32(ctx->r2, 0X188);
    // 0x8079867C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80798680: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80798684: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80798688: b           L_80798654
    // 0x8079868C: lh          $a1, 0x184($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X184);
        goto L_80798654;
    // 0x8079868C: lh          $a1, 0x184($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X184);
L_80798690:
    // 0x80798690: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80798694: srl         $t4, $t9, 30
    ctx->r12 = S32(U32(ctx->r25) >> 30);
    // 0x80798698: bnel        $a3, $t4, L_807986E4
    if (ctx->r7 != ctx->r12) {
        // 0x8079869C: sll         $a1, $a1, 16
        ctx->r5 = S32(ctx->r5 << 16);
            goto L_807986E4;
    }
    goto skip_1;
    // 0x8079869C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    skip_1:
    // 0x807986A0: lhu         $v1, 0xE($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XE);
    // 0x807986A4: srl         $v1, $v1, 10
    ctx->r3 = S32(U32(ctx->r3) >> 10);
    // 0x807986A8: andi        $v1, $v1, 0xF
    ctx->r3 = ctx->r3 & 0XF;
    // 0x807986AC: beql        $t0, $v1, L_807986D0
    if (ctx->r8 == ctx->r3) {
        // 0x807986B0: lhu         $t5, 0xC($v0)
        ctx->r13 = MEM_HU(ctx->r2, 0XC);
            goto L_807986D0;
    }
    goto skip_2;
    // 0x807986B0: lhu         $t5, 0xC($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XC);
    skip_2:
    // 0x807986B4: beql        $t1, $v1, L_807986D0
    if (ctx->r9 == ctx->r3) {
        // 0x807986B8: lhu         $t5, 0xC($v0)
        ctx->r13 = MEM_HU(ctx->r2, 0XC);
            goto L_807986D0;
    }
    goto skip_3;
    // 0x807986B8: lhu         $t5, 0xC($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XC);
    skip_3:
    // 0x807986BC: beql        $v1, $zero, L_807986D0
    if (ctx->r3 == 0) {
        // 0x807986C0: lhu         $t5, 0xC($v0)
        ctx->r13 = MEM_HU(ctx->r2, 0XC);
            goto L_807986D0;
    }
    goto skip_4;
    // 0x807986C0: lhu         $t5, 0xC($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XC);
    skip_4:
    // 0x807986C4: bnel        $t2, $v1, L_807986E4
    if (ctx->r10 != ctx->r3) {
        // 0x807986C8: sll         $a1, $a1, 16
        ctx->r5 = S32(ctx->r5 << 16);
            goto L_807986E4;
    }
    goto skip_5;
    // 0x807986C8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    skip_5:
    // 0x807986CC: lhu         $t5, 0xC($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XC);
L_807986D0:
    // 0x807986D0: beql        $t3, $t5, L_807986E4
    if (ctx->r11 == ctx->r13) {
        // 0x807986D4: sll         $a1, $a1, 16
        ctx->r5 = S32(ctx->r5 << 16);
            goto L_807986E4;
    }
    goto skip_6;
    // 0x807986D4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    skip_6:
    // 0x807986D8: b           L_807986F4
    // 0x807986DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807986F4;
    // 0x807986DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807986E0:
    // 0x807986E0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
L_807986E4:
    // 0x807986E4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_807986E8:
    // 0x807986E8: bne         $a1, $zero, L_8079865C
    if (ctx->r5 != 0) {
        // 0x807986EC: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8079865C;
    }
    // 0x807986EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x807986F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807986F4:
    // 0x807986F4: jr          $ra
    // 0x807986F8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x807986F8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80742AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742AC4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742AC8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742ACC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742AD0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742AD4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742AD8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742ADC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742AE0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742AE4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742AE8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742AEC: jr          $ra
    // 0x80742AF0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742AF0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80422B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80422B08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80422B0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80422B10: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80422B14: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80422B18: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80422B1C: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(35, 0X2E00) << 16);
    // 0x80422B20: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80422B24: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80422B28: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80422B2C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80422B30: lw          $t8, 0x5800($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(35, 0X2E00));
    // 0x80422B34: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80422B38: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80422B3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80422B40: jal         0x80048490
    // 0x80422B44: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80422B44: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80422B48: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80422B4C: jal         0x80048378
    // 0x80422B50: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80422B50: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80422B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80422B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80422B5C: jr          $ra
    // 0x80422B60: nop

    return;
    // 0x80422B60: nop

;}
RECOMP_FUNC void func_80678868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80678868: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8067886C: bne         $a1, $at, L_80678878
    if (ctx->r5 != ctx->r1) {
        // 0x80678870: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80678878;
    }
    // 0x80678870: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80678874: lw          $a1, 0x304($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X304);
L_80678878:
    // 0x80678878: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8067887C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80678880: lwc1        $f4, 0x418($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X418);
    // 0x80678884: lwc1        $f6, 0x414($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X414);
    // 0x80678888: lh          $a0, 0x408($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X408);
    // 0x8067888C: mul.s       $f0, $f4, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80678890: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80678894: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80678898: lui         $at, 0x3C80
    ctx->r1 = S32(0X3C80 << 16);
    // 0x8067889C: sll         $t6, $a1, 7
    ctx->r14 = S32(ctx->r5 << 7);
    // 0x806788A0: addu        $t0, $v0, $t6
    ctx->r8 = ADD32(ctx->r2, ctx->r14);
    // 0x806788A4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x806788A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806788AC: mul.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x806788B0: addu        $a3, $v0, $t7
    ctx->r7 = ADD32(ctx->r2, ctx->r15);
    // 0x806788B4: addiu       $t1, $t0, 0x180
    ctx->r9 = ADD32(ctx->r8, 0X180);
    // 0x806788B8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x806788BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_806788C0:
    // 0x806788C0: slti        $at, $a0, 0x40
    ctx->r1 = SIGNED(ctx->r4) < 0X40 ? 1 : 0;
    // 0x806788C4: bne         $at, $zero, L_806788D4
    if (ctx->r1 != 0) {
        // 0x806788C8: trunc.w.s   $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_806788D4;
    }
    // 0x806788C8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x806788CC: addiu       $a0, $a0, -0x40
    ctx->r4 = ADD32(ctx->r4, -0X40);
    // 0x806788D0: addiu       $a3, $a3, -0x100
    ctx->r7 = ADD32(ctx->r7, -0X100);
L_806788D4:
    // 0x806788D4: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x806788D8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x806788DC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x806788E0: sh          $v1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r3;
    // 0x806788E4: lwc1        $f18, 0x410($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X410);
    // 0x806788E8: lwc1        $f10, 0x308($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X308);
    // 0x806788EC: slti        $at, $a0, 0x40
    ctx->r1 = SIGNED(ctx->r4) < 0X40 ? 1 : 0;
    // 0x806788F0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x806788F4: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x806788F8: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x806788FC: nop

    // 0x80678900: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80678904: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80678908: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8067890C: nop

    // 0x80678910: sh          $t2, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r10;
    // 0x80678914: sh          $v1, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r3;
    // 0x80678918: lwc1        $f4, 0x410($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X410);
    // 0x8067891C: lwc1        $f18, 0x300($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X300);
    // 0x80678920: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80678924: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80678928: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8067892C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80678930: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80678934: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80678938: sub.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x8067893C: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80678940: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80678944: bne         $at, $zero, L_80678954
    if (ctx->r1 != 0) {
        // 0x80678948: sh          $t4, 0x2($t1)
        MEM_H(0X2, ctx->r9) = ctx->r12;
            goto L_80678954;
    }
    // 0x80678948: sh          $t4, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r12;
    // 0x8067894C: addiu       $a0, $a0, -0x40
    ctx->r4 = ADD32(ctx->r4, -0X40);
    // 0x80678950: addiu       $a3, $a3, -0x100
    ctx->r7 = ADD32(ctx->r7, -0X100);
L_80678954:
    // 0x80678954: sh          $v1, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r3;
    // 0x80678958: lwc1        $f8, 0x410($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X410);
    // 0x8067895C: lwc1        $f6, 0x308($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X308);
    // 0x80678960: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80678964: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80678968: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8067896C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80678970: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80678974: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80678978: mul.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8067897C: nop

    // 0x80678980: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80678984: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80678988: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8067898C: nop

    // 0x80678990: sh          $t7, -0x4($t1)
    MEM_H(-0X4, ctx->r9) = ctx->r15;
    // 0x80678994: sh          $v1, -0x2($t0)
    MEM_H(-0X2, ctx->r8) = ctx->r3;
    // 0x80678998: lwc1        $f10, 0x410($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X410);
    // 0x8067899C: lwc1        $f8, 0x300($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X300);
    // 0x806789A0: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806789A4: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x806789A8: nop

    // 0x806789AC: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x806789B0: sub.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x806789B4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x806789B8: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x806789BC: bne         $a2, $a1, L_806788C0
    if (ctx->r6 != ctx->r5) {
        // 0x806789C0: sh          $t9, -0x2($t1)
        MEM_H(-0X2, ctx->r9) = ctx->r25;
            goto L_806788C0;
    }
    // 0x806789C0: sh          $t9, -0x2($t1)
    MEM_H(-0X2, ctx->r9) = ctx->r25;
    // 0x806789C4: jr          $ra
    // 0x806789C8: nop

    return;
    // 0x806789C8: nop

;}
RECOMP_FUNC void func_805271D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805271D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805271D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805271DC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805271E0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x805271E4: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x805271E8: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805271EC: jal         0x80067BBC
    // 0x805271F0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805271F0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x805271F4: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    // 0x805271F8: jal         0x80067818
    // 0x805271FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805271FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80527200: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80527204: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X616C) << 16);
    // 0x80527208: lwc1        $f4, -0x3F94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X616C));
    // 0x8052720C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80527210: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(327, 0X4BFC) << 16);
    // 0x80527214: addiu       $v0, $v0, -0x5504
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(327, 0X4BFC));
    // 0x80527218: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(327, 0X1350) << 16);
    // 0x8052721C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80527220: addiu       $t7, $t7, 0x7250
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(327, 0X1350));
    // 0x80527224: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x80527228: sw          $t6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r14;
    // 0x8052722C: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80527230: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80527234: sw          $t7, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r15;
    // 0x80527238: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
    // 0x8052723C: swc1        $f6, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f6.u32l;
    // 0x80527240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80527244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527248: jr          $ra
    // 0x8052724C: nop

    return;
    // 0x8052724C: nop

;}
RECOMP_FUNC void func_80446848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446848: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044684C: addiu       $v1, $zero, 0xAC8
    ctx->r3 = ADD32(0, 0XAC8);
    // 0x80446850: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446854: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x80446858: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044685C: sw          $zero, 0x6CBC($at)
    MEM_W(0X6CBC, ctx->r1) = 0;
    // 0x80446860: addiu       $a1, $zero, 0x744
    ctx->r5 = ADD32(0, 0X744);
    // 0x80446864: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80446868: sw          $t6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r14;
    // 0x8044686C: sw          $a1, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r5;
    // 0x80446870: sw          $a1, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = ctx->r5;
    // 0x80446874: sw          $a1, 0xE0($v0)
    MEM_W(0XE0, ctx->r2) = ctx->r5;
    // 0x80446878: jr          $ra
    // 0x8044687C: sw          $v1, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->r3;
    return;
    // 0x8044687C: sw          $v1, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_80452858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452858: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045285C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452860: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80452864: jal         0x804527B0
    // 0x80452868: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804527B0(rdram, ctx);
        goto after_0;
    // 0x80452868: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8045286C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80452870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452874: jr          $ra
    // 0x80452878: nop

    return;
    // 0x80452878: nop

;}
RECOMP_FUNC void func_8002D5EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D5EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002D5F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D5F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002D5F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002D5FC: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002D600: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8002D604: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002D608: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002D60C: jal         0x8002B00C
    // 0x8002D610: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_8002B00C(rdram, ctx);
        goto after_0;
    // 0x8002D610: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002D614: lbu         $t7, 0x155($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X155);
    // 0x8002D618: beq         $t7, $zero, L_8002D628
    if (ctx->r15 == 0) {
        // 0x8002D61C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8002D628;
    }
    // 0x8002D61C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002D620: jal         0x80032564
    // 0x8002D624: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80032564(rdram, ctx);
        goto after_1;
    // 0x8002D624: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
L_8002D628:
    // 0x8002D628: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8002D62C: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x8002D630: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002D634: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8002D638: lw          $v0, 0x78($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X78);
    // 0x8002D63C: beql        $v0, $zero, L_8002D650
    if (ctx->r2 == 0) {
        // 0x8002D640: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8002D650;
    }
    goto skip_0;
    // 0x8002D640: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8002D644: jalr        $v0
    // 0x8002D648: lw          $a0, 0x108($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X108);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x8002D648: lw          $a0, 0x108($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X108);
    after_2:
    // 0x8002D64C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8002D650:
    // 0x8002D650: jal         0x8002BBF4
    // 0x8002D654: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8002BBF4(rdram, ctx);
        goto after_3;
    // 0x8002D654: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8002D658: lbu         $t0, 0x18($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X18);
    // 0x8002D65C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002D660: lui         $t3, 0x8003
    ctx->r11 = S32(0X8003 << 16);
    // 0x8002D664: sb          $t0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r8;
    // 0x8002D668: addiu       $a1, $a1, -0x2ED8
    ctx->r5 = ADD32(ctx->r5, -0X2ED8);
    // 0x8002D66C: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8002D670: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8002D674: addiu       $t3, $t3, 0x12F0
    ctx->r11 = ADD32(ctx->r11, 0X12F0);
    // 0x8002D678: sb          $t1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r9;
    // 0x8002D67C: sb          $t2, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r10;
    // 0x8002D680: sw          $t3, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r11;
    // 0x8002D684: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002D688: jal         0x80028118
    // 0x8002D68C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028118(rdram, ctx);
        goto after_4;
    // 0x8002D68C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8002D690: jal         0x80022EB4
    // 0x8002D694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80022EB4(rdram, ctx);
        goto after_5;
    // 0x8002D694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8002D698: jal         0x8002AE90
    // 0x8002D69C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002AE90(rdram, ctx);
        goto after_6;
    // 0x8002D69C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8002D6A0: jal         0x8005FE48
    // 0x8002D6A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_7;
    // 0x8002D6A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8002D6A8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8002D6AC: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8002D6B0: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8002D6B4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8002D6B8: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8002D6BC: addiu       $a0, $zero, 0x400F
    ctx->r4 = ADD32(0, 0X400F);
    // 0x8002D6C0: sh          $zero, 0x10($t4)
    MEM_H(0X10, ctx->r12) = 0;
    // 0x8002D6C4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8002D6C8: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x8002D6CC: sh          $zero, 0x12($t5)
    MEM_H(0X12, ctx->r13) = 0;
    // 0x8002D6D0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8002D6D4: sh          $zero, 0x14($t6)
    MEM_H(0X14, ctx->r14) = 0;
    // 0x8002D6D8: lw          $t7, -0x7BC4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7BC4);
    // 0x8002D6DC: lw          $t1, -0x76F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76F8);
    // 0x8002D6E0: lw          $t8, 0x10C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10C);
    // 0x8002D6E4: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x8002D6E8: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x8002D6EC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8002D6F0: lw          $t9, 0x14($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X14);
    // 0x8002D6F4: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x8002D6F8: lw          $a2, -0x20E8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X20E8);
    // 0x8002D6FC: jalr        $t9
    // 0x8002D700: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x8002D700: nop

    after_8:
    // 0x8002D704: jal         0x8001D770
    // 0x8002D708: nop

    func_8001D770(rdram, ctx);
        goto after_9;
    // 0x8002D708: nop

    after_9:
    // 0x8002D70C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002D710: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002D714: jal         0x80067BF8
    // 0x8002D718: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_10;
    // 0x8002D718: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_10:
    // 0x8002D71C: addiu       $a0, $zero, 0x1FA
    ctx->r4 = ADD32(0, 0X1FA);
    // 0x8002D720: jal         0x80067818
    // 0x8002D724: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_11;
    // 0x8002D724: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x8002D728: addiu       $t3, $zero, 0x46
    ctx->r11 = ADD32(0, 0X46);
    // 0x8002D72C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002D730: sb          $t3, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r11;
    // 0x8002D734: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002D738: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8002D73C: sb          $t4, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r12;
    // 0x8002D740: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002D744: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8002D748: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x8002D74C: sb          $t5, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r13;
    // 0x8002D750: addiu       $t6, $t6, 0x387C
    ctx->r14 = ADD32(ctx->r14, 0X387C);
    // 0x8002D754: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x8002D758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D75C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002D760: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002D764: jr          $ra
    // 0x8002D768: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8002D768: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80052CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052CA0: jr          $ra
    // 0x80052CA4: nop

    return;
    // 0x80052CA4: nop

;}
RECOMP_FUNC void func_80452DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452DD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80452DDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80452DE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80452DE4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80452DE8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452DEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80452DF0: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80452DF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80452DF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80452DFC: lwc1        $f4, 0x6CE0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6CE0);
    // 0x80452E00: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14104) << 16);
    // 0x80452E04: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80452E08: swc1        $f8, 0x6CE0($v0)
    MEM_W(0X6CE0, ctx->r2) = ctx->f8.u32l;
    // 0x80452E0C: lwc1        $f16, 0x6CE0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6CE0);
    // 0x80452E10: lwc1        $f10, -0x7B1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14104));
    // 0x80452E14: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452E18: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80452E1C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80452E20: nop

    // 0x80452E24: bc1fl       L_80452E40
    if (!c1cs) {
        // 0x80452E28: lwc1        $f0, 0x6CE0($at)
        ctx->f0.u32l = MEM_W(ctx->r1, 0X6CE0);
            goto L_80452E40;
    }
    goto skip_0;
    // 0x80452E28: lwc1        $f0, 0x6CE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6CE0);
    skip_0:
    // 0x80452E2C: jal         0x80452768
    // 0x80452E30: nop

    func_80452768(rdram, ctx);
        goto after_0;
    // 0x80452E30: nop

    after_0:
    // 0x80452E34: b           L_80452F70
    // 0x80452E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80452F70;
    // 0x80452E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80452E3C: lwc1        $f0, 0x6CE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6CE0);
L_80452E40:
    // 0x80452E40: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14108) << 16);
    // 0x80452E44: lwc1        $f18, -0x7B18($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14108));
    // 0x80452E48: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1410C) << 16);
    // 0x80452E4C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80452E50: nop

    // 0x80452E54: bc1f        L_80452E98
    if (!c1cs) {
        // 0x80452E58: nop
    
            goto L_80452E98;
    }
    // 0x80452E58: nop

    // 0x80452E5C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452E60: ori         $at, $at, 0x6E04
    ctx->r1 = ctx->r1 | 0X6E04;
    // 0x80452E64: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80452E68: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80452E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80452E70: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80452E74: beql        $t6, $zero, L_80452F64
    if (ctx->r14 == 0) {
        // 0x80452E78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80452F64;
    }
    goto skip_1;
    // 0x80452E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80452E7C: jal         0x80450B18
    // 0x80452E80: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    func_80450B18(rdram, ctx);
        goto after_1;
    // 0x80452E80: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_1:
    // 0x80452E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80452E88: jal         0x80445E2C
    // 0x80452E8C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80445E2C(rdram, ctx);
        goto after_2;
    // 0x80452E8C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80452E90: b           L_80452F64
    // 0x80452E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80452F64;
    // 0x80452E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80452E98:
    // 0x80452E98: lwc1        $f4, -0x7B14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1410C));
    // 0x80452E9C: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80452EA0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80452EA4: nop

    // 0x80452EA8: bc1fl       L_80452EE4
    if (!c1cs) {
        // 0x80452EAC: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80452EE4;
    }
    goto skip_2;
    // 0x80452EAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_2:
    // 0x80452EB0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452EB4: ori         $at, $at, 0x6E04
    ctx->r1 = ctx->r1 | 0X6E04;
    // 0x80452EB8: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80452EBC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80452EC0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80452EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80452EC8: beq         $a2, $t7, L_80452F60
    if (ctx->r6 == ctx->r15) {
        // 0x80452ECC: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80452F60;
    }
    // 0x80452ECC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80452ED0: jal         0x80450B18
    // 0x80452ED4: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_3;
    // 0x80452ED4: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    after_3:
    // 0x80452ED8: b           L_80452F64
    // 0x80452EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80452F64;
    // 0x80452EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80452EE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80452EE4:
    // 0x80452EE4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80452EE8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80452EEC: nop

    // 0x80452EF0: bc1fl       L_80452F2C
    if (!c1cs) {
        // 0x80452EF4: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80452F2C;
    }
    goto skip_3;
    // 0x80452EF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_3:
    // 0x80452EF8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452EFC: ori         $at, $at, 0x6E04
    ctx->r1 = ctx->r1 | 0X6E04;
    // 0x80452F00: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80452F04: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80452F08: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80452F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80452F10: beq         $a2, $t8, L_80452F60
    if (ctx->r6 == ctx->r24) {
        // 0x80452F14: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80452F60;
    }
    // 0x80452F14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80452F18: jal         0x80450B18
    // 0x80452F1C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_4;
    // 0x80452F1C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    after_4:
    // 0x80452F20: b           L_80452F64
    // 0x80452F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80452F64;
    // 0x80452F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80452F28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80452F2C:
    // 0x80452F2C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452F30: ori         $at, $at, 0x6E04
    ctx->r1 = ctx->r1 | 0X6E04;
    // 0x80452F34: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80452F38: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80452F3C: bc1fl       L_80452F64
    if (!c1cs) {
        // 0x80452F40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80452F64;
    }
    goto skip_4;
    // 0x80452F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80452F44: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80452F48: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80452F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80452F50: beq         $a2, $t9, L_80452F60
    if (ctx->r6 == ctx->r25) {
        // 0x80452F54: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80452F60;
    }
    // 0x80452F54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80452F58: jal         0x80450B18
    // 0x80452F5C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_5;
    // 0x80452F5C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    after_5:
L_80452F60:
    // 0x80452F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80452F64:
    // 0x80452F64: jal         0x80452A14
    // 0x80452F68: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80452A14(rdram, ctx);
        goto after_6;
    // 0x80452F68: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x80452F6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80452F70:
    // 0x80452F70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80452F74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80452F78: jr          $ra
    // 0x80452F7C: nop

    return;
    // 0x80452F7C: nop

;}
RECOMP_FUNC void func_804524DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804524DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804524E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804524E4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804524E8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804524EC: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x804524F0: lwc1        $f0, 0x6C84($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X6C84);
    // 0x804524F4: lwc1        $f4, 0x6C88($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C88);
    // 0x804524F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804524FC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80452500: nop

    // 0x80452504: bc1f        L_80452534
    if (!c1cs) {
        // 0x80452508: nop
    
            goto L_80452534;
    }
    // 0x80452508: nop

    // 0x8045250C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80452510: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452514: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80452518: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8045251C: swc1        $f8, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f8.u32l;
    // 0x80452520: lwc1        $f14, 0x6C88($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X6C88);
    // 0x80452524: jal         0x80450490
    // 0x80452528: lwc1        $f12, 0x6C84($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X6C84);
    func_80450490(rdram, ctx);
        goto after_0;
    // 0x80452528: lwc1        $f12, 0x6C84($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X6C84);
    after_0:
    // 0x8045252C: b           L_80452540
    // 0x80452530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80452540;
    // 0x80452530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452534:
    // 0x80452534: jal         0x804506D0
    // 0x80452538: nop

    func_804506D0(rdram, ctx);
        goto after_1;
    // 0x80452538: nop

    after_1:
    // 0x8045253C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452540:
    // 0x80452540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452544: jr          $ra
    // 0x80452548: nop

    return;
    // 0x80452548: nop

;}
RECOMP_FUNC void func_80584CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584CFC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584D00: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584D04: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584D08: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584D0C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584D10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584D14: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584D18: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584D1C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584D20: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584D24: jr          $ra
    // 0x80584D28: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584D28: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80557930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80557930: lui         $v0, 0x8055
    ctx->r2 = S32(RELOC_HI16(360, 0X10) << 16);
    // 0x80557934: addiu       $v0, $v0, 0x7940
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(360, 0X10));
    // 0x80557938: jr          $ra
    // 0x8055793C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8055793C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8045A748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045A748: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045A74C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045A750: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8045A754: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8045A758: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8045A75C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8045A760: jal         0x8045A4B0
    // 0x8045A764: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_8045A4B0(rdram, ctx);
        goto after_0;
    // 0x8045A764: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8045A768: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8045A76C: jal         0x8045A5AC
    // 0x8045A770: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8045A5AC(rdram, ctx);
        goto after_1;
    // 0x8045A770: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8045A774: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8045A778: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8045A77C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8045A780: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8045A784: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8045A788: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8045A78C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8045A790: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8045A794: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x8045A798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045A79C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8045A7A0: jr          $ra
    // 0x8045A7A4: nop

    return;
    // 0x8045A7A4: nop

;}
RECOMP_FUNC void func_8046A4A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046A4A4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046A4A8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8046A4AC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8046A4B0: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8046A4B4: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8046A4B8: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8046A4BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8046A4C0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8046A4C4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8046A4C8: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x8046A4CC: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8046A4D0: bc1fl       L_8046A4E0
    if (!c1cs) {
        // 0x8046A4D4: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_8046A4E0;
    }
    goto skip_0;
    // 0x8046A4D4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    skip_0:
    // 0x8046A4D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046A4DC: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
L_8046A4E0:
    // 0x8046A4E0: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8046A4E4: lwc1        $f0, 0x1C($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8046A4E8: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8046A4EC: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8046A4F0: nop

    // 0x8046A4F4: bc1fl       L_8046A508
    if (!c1cs) {
        // 0x8046A4F8: lwc1        $f10, 0x20($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
            goto L_8046A508;
    }
    goto skip_1;
    // 0x8046A4F8: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    skip_1:
    // 0x8046A4FC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8046A500: lwc1        $f0, 0x1C($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x8046A504: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
L_8046A508:
    // 0x8046A508: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8046A50C: nop

    // 0x8046A510: bc1fl       L_8046A52C
    if (!c1cs) {
        // 0x8046A514: lwc1        $f16, 0x24($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X24);
            goto L_8046A52C;
    }
    goto skip_2;
    // 0x8046A514: lwc1        $f16, 0x24($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X24);
    skip_2:
    // 0x8046A518: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x8046A51C: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x8046A520: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8046A524: lwc1        $f0, 0x1C($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x8046A528: lwc1        $f16, 0x24($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X24);
L_8046A52C:
    // 0x8046A52C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8046A530: nop

    // 0x8046A534: bc1fl       L_8046A550
    if (!c1cs) {
        // 0x8046A538: lwc1        $f18, 0x28($a0)
        ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
            goto L_8046A550;
    }
    goto skip_3;
    // 0x8046A538: lwc1        $f18, 0x28($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
    skip_3:
    // 0x8046A53C: addiu       $a1, $v1, 0x2
    ctx->r5 = ADD32(ctx->r3, 0X2);
    // 0x8046A540: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x8046A544: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x8046A548: lwc1        $f0, 0x1C($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x8046A54C: lwc1        $f18, 0x28($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
L_8046A550:
    // 0x8046A550: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8046A554: nop

    // 0x8046A558: bc1fl       L_8046A568
    if (!c1cs) {
        // 0x8046A55C: slti        $at, $a1, 0x6
        ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
            goto L_8046A568;
    }
    goto skip_4;
    // 0x8046A55C: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    skip_4:
    // 0x8046A560: addiu       $a1, $v1, 0x3
    ctx->r5 = ADD32(ctx->r3, 0X3);
    // 0x8046A564: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
L_8046A568:
    // 0x8046A568: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8046A56C: bne         $at, $zero, L_8046A578
    if (ctx->r1 != 0) {
        // 0x8046A570: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8046A578;
    }
    // 0x8046A570: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8046A574: addiu       $v1, $a0, -0x6
    ctx->r3 = ADD32(ctx->r4, -0X6);
L_8046A578:
    // 0x8046A578: bne         $v1, $a3, L_8046A584
    if (ctx->r3 != ctx->r7) {
        // 0x8046A57C: addiu       $a0, $v1, 0x1
        ctx->r4 = ADD32(ctx->r3, 0X1);
            goto L_8046A584;
    }
    // 0x8046A57C: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8046A580: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8046A584:
    // 0x8046A584: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8046A588: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8046A58C: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8046A590: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8046A594: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8046A598: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8046A59C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8046A5A0: addu        $a2, $a1, $a0
    ctx->r6 = ADD32(ctx->r5, ctx->r4);
    // 0x8046A5A4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8046A5A8: slti        $at, $a2, 0x6
    ctx->r1 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
    // 0x8046A5AC: bc1f        L_8046A5D0
    if (!c1cs) {
        // 0x8046A5B0: nop
    
            goto L_8046A5D0;
    }
    // 0x8046A5B0: nop

    // 0x8046A5B4: lwc1        $f6, 0x1C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8046A5B8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8046A5BC: nop

    // 0x8046A5C0: bc1f        L_8046A5D0
    if (!c1cs) {
        // 0x8046A5C4: nop
    
            goto L_8046A5D0;
    }
    // 0x8046A5C4: nop

    // 0x8046A5C8: jr          $ra
    // 0x8046A5CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8046A5CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8046A5D0:
    // 0x8046A5D0: bne         $at, $zero, L_8046A5DC
    if (ctx->r1 != 0) {
        // 0x8046A5D4: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_8046A5DC;
    }
    // 0x8046A5D4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8046A5D8: addiu       $v1, $a2, -0x6
    ctx->r3 = ADD32(ctx->r6, -0X6);
L_8046A5DC:
    // 0x8046A5DC: bne         $v1, $a3, L_8046A5E8
    if (ctx->r3 != ctx->r7) {
        // 0x8046A5E0: addiu       $a0, $v1, 0x1
        ctx->r4 = ADD32(ctx->r3, 0X1);
            goto L_8046A5E8;
    }
    // 0x8046A5E0: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8046A5E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8046A5E8:
    // 0x8046A5E8: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8046A5EC: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8046A5F0: lwc1        $f8, 0x1C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x8046A5F4: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8046A5F8: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    // 0x8046A5FC: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8046A600: slti        $at, $a2, 0x5
    ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x8046A604: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8046A608: bc1f        L_8046A62C
    if (!c1cs) {
        // 0x8046A60C: nop
    
            goto L_8046A62C;
    }
    // 0x8046A60C: nop

    // 0x8046A610: lwc1        $f10, 0x1C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x8046A614: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8046A618: nop

    // 0x8046A61C: bc1f        L_8046A62C
    if (!c1cs) {
        // 0x8046A620: nop
    
            goto L_8046A62C;
    }
    // 0x8046A620: nop

    // 0x8046A624: jr          $ra
    // 0x8046A628: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8046A628: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8046A62C:
    // 0x8046A62C: bne         $at, $zero, L_8046A638
    if (ctx->r1 != 0) {
        // 0x8046A630: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8046A638;
    }
    // 0x8046A630: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8046A634: addiu       $v1, $a0, -0x6
    ctx->r3 = ADD32(ctx->r4, -0X6);
L_8046A638:
    // 0x8046A638: bne         $v1, $a3, L_8046A644
    if (ctx->r3 != ctx->r7) {
        // 0x8046A63C: addiu       $a0, $v1, 0x1
        ctx->r4 = ADD32(ctx->r3, 0X1);
            goto L_8046A644;
    }
    // 0x8046A63C: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8046A640: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8046A644:
    // 0x8046A644: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8046A648: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x8046A64C: lwc1        $f16, 0x1C($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x8046A650: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8046A654: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8046A658: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x8046A65C: addiu       $a0, $a2, 0x2
    ctx->r4 = ADD32(ctx->r6, 0X2);
    // 0x8046A660: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x8046A664: bc1f        L_8046A688
    if (!c1cs) {
        // 0x8046A668: nop
    
            goto L_8046A688;
    }
    // 0x8046A668: nop

    // 0x8046A66C: lwc1        $f18, 0x1C($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8046A670: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8046A674: nop

    // 0x8046A678: bc1f        L_8046A688
    if (!c1cs) {
        // 0x8046A67C: nop
    
            goto L_8046A688;
    }
    // 0x8046A67C: nop

    // 0x8046A680: jr          $ra
    // 0x8046A684: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8046A684: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8046A688:
    // 0x8046A688: bne         $at, $zero, L_8046A694
    if (ctx->r1 != 0) {
        // 0x8046A68C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8046A694;
    }
    // 0x8046A68C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8046A690: addiu       $v1, $a0, -0x6
    ctx->r3 = ADD32(ctx->r4, -0X6);
L_8046A694:
    // 0x8046A694: bne         $v1, $a3, L_8046A6A0
    if (ctx->r3 != ctx->r7) {
        // 0x8046A698: addiu       $a0, $v1, 0x1
        ctx->r4 = ADD32(ctx->r3, 0X1);
            goto L_8046A6A0;
    }
    // 0x8046A698: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8046A69C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8046A6A0:
    // 0x8046A6A0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8046A6A4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8046A6A8: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8046A6AC: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8046A6B0: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8046A6B4: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8046A6B8: addiu       $a0, $a2, 0x3
    ctx->r4 = ADD32(ctx->r6, 0X3);
    // 0x8046A6BC: slti        $at, $a2, 0x3
    ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // 0x8046A6C0: bc1f        L_8046A6E4
    if (!c1cs) {
        // 0x8046A6C4: nop
    
            goto L_8046A6E4;
    }
    // 0x8046A6C4: nop

    // 0x8046A6C8: lwc1        $f6, 0x1C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x8046A6CC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8046A6D0: nop

    // 0x8046A6D4: bc1f        L_8046A6E4
    if (!c1cs) {
        // 0x8046A6D8: nop
    
            goto L_8046A6E4;
    }
    // 0x8046A6D8: nop

    // 0x8046A6DC: jr          $ra
    // 0x8046A6E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8046A6E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8046A6E4:
    // 0x8046A6E4: bne         $at, $zero, L_8046A6F0
    if (ctx->r1 != 0) {
        // 0x8046A6E8: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8046A6F0;
    }
    // 0x8046A6E8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8046A6EC: addiu       $v1, $a0, -0x6
    ctx->r3 = ADD32(ctx->r4, -0X6);
L_8046A6F0:
    // 0x8046A6F0: bne         $v1, $a3, L_8046A6FC
    if (ctx->r3 != ctx->r7) {
        // 0x8046A6F4: addiu       $a0, $v1, 0x1
        ctx->r4 = ADD32(ctx->r3, 0X1);
            goto L_8046A6FC;
    }
    // 0x8046A6F4: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8046A6F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8046A6FC:
    // 0x8046A6FC: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8046A700: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8046A704: lwc1        $f8, 0x1C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x8046A708: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8046A70C: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x8046A710: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8046A714: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8046A718: bc1f        L_8046A73C
    if (!c1cs) {
        // 0x8046A71C: nop
    
            goto L_8046A73C;
    }
    // 0x8046A71C: nop

    // 0x8046A720: lwc1        $f10, 0x1C($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x8046A724: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8046A728: nop

    // 0x8046A72C: bc1f        L_8046A73C
    if (!c1cs) {
        // 0x8046A730: nop
    
            goto L_8046A73C;
    }
    // 0x8046A730: nop

    // 0x8046A734: jr          $ra
    // 0x8046A738: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8046A738: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8046A73C:
    // 0x8046A73C: jr          $ra
    // 0x8046A740: nop

    return;
    // 0x8046A740: nop

;}
RECOMP_FUNC void func_807AF3FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF3FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AF400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AF404: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AF408: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(865, 0X460) << 16);
    // 0x807AF40C: lwc1        $f6, -0xAA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(865, 0X460));
    // 0x807AF410: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x807AF414: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(865, 0X464) << 16);
    // 0x807AF418: lwc1        $f8, -0xA9C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(865, 0X464));
    // 0x807AF41C: lwc1        $f4, 0x78($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X78);
    // 0x807AF420: lwc1        $f0, 0x6C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x807AF424: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x807AF428: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807AF42C: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x807AF430: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x807AF434: nop

    // 0x807AF438: bc1fl       L_807AF468
    if (!c1cs) {
        // 0x807AF43C: swc1        $f0, 0x6C($v0)
        MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
            goto L_807AF468;
    }
    goto skip_0;
    // 0x807AF43C: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    skip_0:
    // 0x807AF440: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x807AF444: jal         0x807AF508
    // 0x807AF448: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_807AF508(rdram, ctx);
        goto after_0;
    // 0x807AF448: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x807AF44C: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x807AF450: jal         0x80067818
    // 0x807AF454: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x807AF454: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x807AF458: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x807AF45C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x807AF460: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x807AF464: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
L_807AF468:
    // 0x807AF468: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x807AF46C: swc1        $f0, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f0.u32l;
    // 0x807AF470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AF474: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AF478: jr          $ra
    // 0x807AF47C: nop

    return;
    // 0x807AF47C: nop

;}
RECOMP_FUNC void func_80522574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80522574: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80522578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052257C: jal         0x8004700C
    // 0x80522580: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80522580: nop

    after_0:
    // 0x80522584: beql        $v0, $zero, L_805225D8
    if (ctx->r2 == 0) {
        // 0x80522588: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805225D8;
    }
    goto skip_0;
    // 0x80522588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8052258C: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80522590: lw          $t6, 0x12EC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X12EC);
    // 0x80522594: beql        $t6, $zero, L_805225D8
    if (ctx->r14 == 0) {
        // 0x80522598: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805225D8;
    }
    goto skip_1;
    // 0x80522598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8052259C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x805225A0: jal         0x800653D8
    // 0x805225A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x805225A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x805225A8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x805225AC: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x805225B0: andi        $a3, $v0, 0x7
    ctx->r7 = ctx->r2 & 0X7;
    // 0x805225B4: addiu       $a0, $t0, 0x188
    ctx->r4 = ADD32(ctx->r8, 0X188);
    // 0x805225B8: jal         0x8052249C
    // 0x805225BC: lh          $a1, 0x184($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X184);
    func_8052249C(rdram, ctx);
        goto after_2;
    // 0x805225BC: lh          $a1, 0x184($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X184);
    after_2:
    // 0x805225C0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x805225C4: lbu         $t7, 0x12C9($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X12C9);
    // 0x805225C8: sw          $zero, 0x12EC($v1)
    MEM_W(0X12EC, ctx->r3) = 0;
    // 0x805225CC: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x805225D0: sb          $t8, 0x12C9($v1)
    MEM_B(0X12C9, ctx->r3) = ctx->r24;
    // 0x805225D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805225D8:
    // 0x805225D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805225DC: jr          $ra
    // 0x805225E0: nop

    return;
    // 0x805225E0: nop

;}
RECOMP_FUNC void func_8042F4A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F4A4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8042F4A8: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0X1108) << 16);
    // 0x8042F4AC: addiu       $t6, $t6, -0xE18
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0X1108));
    // 0x8042F4B0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8042F4B4: jr          $ra
    // 0x8042F4B8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8042F4B8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8004031C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004031C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80040320: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80040324: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80040328: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004032C: jal         0x8003B764
    // 0x80040330: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8003B764(rdram, ctx);
        goto after_0;
    // 0x80040330: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80040334: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80040338: bne         $at, $zero, L_80040348
    if (ctx->r1 != 0) {
        // 0x8004033C: nop
    
            goto L_80040348;
    }
    // 0x8004033C: nop

    // 0x80040340: b           L_800403D0
    // 0x80040344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800403D0;
    // 0x80040344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80040348:
    // 0x80040348: jal         0x8003BB58
    // 0x8004034C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8003BB58(rdram, ctx);
        goto after_1;
    // 0x8004034C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80040350: bne         $v0, $zero, L_80040360
    if (ctx->r2 != 0) {
        // 0x80040354: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80040360;
    }
    // 0x80040354: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80040358: b           L_800403D0
    // 0x8004035C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800403D0;
    // 0x8004035C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80040360:
    // 0x80040360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80040364: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80040368: jal         0x80047F9C
    // 0x8004036C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8004036C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x80040370: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80040374: lwc1        $f0, 0x2D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2D0);
    // 0x80040378: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8004037C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80040380: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80040384: addiu       $a0, $a2, 0x78
    ctx->r4 = ADD32(ctx->r6, 0X78);
    // 0x80040388: addiu       $a1, $a2, 0x6C
    ctx->r5 = ADD32(ctx->r6, 0X6C);
    // 0x8004038C: swc1        $f6, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
    // 0x80040390: lwc1        $f8, 0x70($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80040394: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80040398: swc1        $f10, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f10.u32l;
    // 0x8004039C: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800403A0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800403A4: jal         0x80065490
    // 0x800403A8: swc1        $f18, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->f18.u32l;
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x800403A8: swc1        $f18, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->f18.u32l;
    after_3:
    // 0x800403AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800403B0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800403B4: addiu       $t6, $t6, -0x4D04
    ctx->r14 = ADD32(ctx->r14, -0X4D04);
    // 0x800403B8: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x800403BC: jal         0x800401B4
    // 0x800403C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800401B4(rdram, ctx);
        goto after_4;
    // 0x800403C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x800403C4: jal         0x80038E18
    // 0x800403C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80038E18(rdram, ctx);
        goto after_5;
    // 0x800403C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800403CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800403D0:
    // 0x800403D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800403D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800403D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800403DC: jr          $ra
    // 0x800403E0: nop

    return;
    // 0x800403E0: nop

;}
RECOMP_FUNC void func_80054640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054640: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80054644: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80054648: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8005464C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80054650: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80054654: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80054658: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8005465C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80054660: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80054664: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80054668: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005466C: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x80054670: sw          $a0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r4;
    // 0x80054674: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x80054678: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x8005467C: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x80054680: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80054684: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80054688: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x8005468C: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x80054690: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x80054694: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    // 0x80054698: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x8005469C: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800546A0: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x800546A4: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800546A8: mflo        $a0
    ctx->r4 = lo;
    // 0x800546AC: jal         0x80064D1C
    // 0x800546B0: nop

    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x800546B0: nop

    after_0:
    // 0x800546B4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800546B8: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800546BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800546C0: sw          $t7, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->r15;
    // 0x800546C4: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800546C8: sw          $zero, 0x14($s3)
    MEM_W(0X14, ctx->r19) = 0;
    // 0x800546CC: sw          $t8, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r24;
    // 0x800546D0: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800546D4: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x800546D8: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800546DC: mflo        $s4
    ctx->r20 = lo;
    // 0x800546E0: andi        $v0, $s4, 0x3
    ctx->r2 = ctx->r20 & 0X3;
    // 0x800546E4: beql        $s4, $zero, L_800547B4
    if (ctx->r20 == 0) {
        // 0x800546E8: lw          $a0, 0x14($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X14);
            goto L_800547B4;
    }
    goto skip_0;
    // 0x800546E8: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    skip_0:
    // 0x800546EC: beq         $v0, $zero, L_8005472C
    if (ctx->r2 == 0) {
        // 0x800546F0: lw          $s5, 0xC4($sp)
        ctx->r21 = MEM_W(ctx->r29, 0XC4);
            goto L_8005472C;
    }
    // 0x800546F0: lw          $s5, 0xC4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XC4);
    // 0x800546F4: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x800546F8: addu        $s0, $s5, $t7
    ctx->r16 = ADD32(ctx->r21, ctx->r15);
    // 0x800546FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80054700:
    // 0x80054700: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054704: lw          $t8, 0x14($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X14);
    // 0x80054708: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005470C: sltu        $at, $t8, $v0
    ctx->r1 = ctx->r24 < ctx->r2 ? 1 : 0;
    // 0x80054710: beq         $at, $zero, L_8005471C
    if (ctx->r1 == 0) {
        // 0x80054714: nop
    
            goto L_8005471C;
    }
    // 0x80054714: nop

    // 0x80054718: sw          $v0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r2;
L_8005471C:
    // 0x8005471C: bne         $v1, $s1, L_80054700
    if (ctx->r3 != ctx->r17) {
        // 0x80054720: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80054700;
    }
    // 0x80054720: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80054724: beql        $s1, $s4, L_800547B0
    if (ctx->r17 == ctx->r20) {
        // 0x80054728: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800547B0;
    }
    goto skip_1;
    // 0x80054728: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    skip_1:
L_8005472C:
    // 0x8005472C: lw          $s5, 0xC4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XC4);
    // 0x80054730: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x80054734: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x80054738: addu        $v1, $t6, $s5
    ctx->r3 = ADD32(ctx->r14, ctx->r21);
    // 0x8005473C: addu        $s0, $s5, $t9
    ctx->r16 = ADD32(ctx->r21, ctx->r25);
    // 0x80054740: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
L_80054744:
    // 0x80054744: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054748: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8005474C: beql        $at, $zero, L_80054760
    if (ctx->r1 == 0) {
        // 0x80054750: lw          $v0, 0x4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X4);
            goto L_80054760;
    }
    goto skip_2;
    // 0x80054750: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x80054754: sw          $v0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r2;
    // 0x80054758: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005475C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
L_80054760:
    // 0x80054760: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80054764: beql        $at, $zero, L_80054778
    if (ctx->r1 == 0) {
        // 0x80054768: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_80054778;
    }
    goto skip_3;
    // 0x80054768: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_3:
    // 0x8005476C: sw          $v0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r2;
    // 0x80054770: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80054774: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_80054778:
    // 0x80054778: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8005477C: beql        $at, $zero, L_80054790
    if (ctx->r1 == 0) {
        // 0x80054780: lw          $v0, 0xC($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XC);
            goto L_80054790;
    }
    goto skip_4;
    // 0x80054780: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    skip_4:
    // 0x80054784: sw          $v0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r2;
    // 0x80054788: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005478C: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
L_80054790:
    // 0x80054790: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80054794: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80054798: beq         $at, $zero, L_800547A4
    if (ctx->r1 == 0) {
        // 0x8005479C: nop
    
            goto L_800547A4;
    }
    // 0x8005479C: nop

    // 0x800547A0: sw          $v0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r2;
L_800547A4:
    // 0x800547A4: bnel        $s0, $v1, L_80054744
    if (ctx->r16 != ctx->r3) {
        // 0x800547A8: lw          $a0, 0x14($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X14);
            goto L_80054744;
    }
    goto skip_5;
    // 0x800547A8: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    skip_5:
    // 0x800547AC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800547B0:
    // 0x800547B0: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
L_800547B4:
    // 0x800547B4: lw          $s5, 0xC4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XC4);
    // 0x800547B8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800547BC: jal         0x80064D1C
    // 0x800547C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x800547C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x800547C4: sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
    // 0x800547C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800547CC: lw          $t7, 0x18($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X18);
L_800547D0:
    // 0x800547D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800547D4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800547D8: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800547DC: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    // 0x800547E0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800547E4: sltu        $at, $a0, $s1
    ctx->r1 = ctx->r4 < ctx->r17 ? 1 : 0;
    // 0x800547E8: beql        $at, $zero, L_800547D0
    if (ctx->r1 == 0) {
        // 0x800547EC: lw          $t7, 0x18($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X18);
            goto L_800547D0;
    }
    goto skip_6;
    // 0x800547EC: lw          $t7, 0x18($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X18);
    skip_6:
    // 0x800547F0: beq         $s4, $zero, L_800548C0
    if (ctx->r20 == 0) {
        // 0x800547F4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800548C0;
    }
    // 0x800547F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800547F8: andi        $v0, $s4, 0x3
    ctx->r2 = ctx->r20 & 0X3;
    // 0x800547FC: beq         $v0, $zero, L_80054838
    if (ctx->r2 == 0) {
        // 0x80054800: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80054838;
    }
    // 0x80054800: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80054804: sll         $t9, $zero, 2
    ctx->r25 = S32(0 << 2);
    // 0x80054808: addu        $s0, $s5, $t9
    ctx->r16 = ADD32(ctx->r21, ctx->r25);
L_8005480C:
    // 0x8005480C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80054810: lw          $t6, 0x18($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X18);
    // 0x80054814: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80054818: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005481C: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80054820: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80054824: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80054828: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005482C: bne         $v1, $s1, L_8005480C
    if (ctx->r3 != ctx->r17) {
        // 0x80054830: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_8005480C;
    }
    // 0x80054830: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80054834: beq         $s1, $s4, L_800548C0
    if (ctx->r17 == ctx->r20) {
        // 0x80054838: sll         $t6, $s1, 2
        ctx->r14 = S32(ctx->r17 << 2);
            goto L_800548C0;
    }
L_80054838:
    // 0x80054838: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8005483C: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x80054840: addu        $a2, $t8, $s5
    ctx->r6 = ADD32(ctx->r24, ctx->r21);
    // 0x80054844: addu        $s0, $s5, $t6
    ctx->r16 = ADD32(ctx->r21, ctx->r14);
L_80054848:
    // 0x80054848: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8005484C: lw          $t9, 0x18($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X18);
    // 0x80054850: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80054854: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80054858: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x8005485C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80054860: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80054864: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80054868: lw          $t6, -0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, -0XC);
    // 0x8005486C: lw          $t9, 0x18($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X18);
    // 0x80054870: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80054874: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x80054878: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8005487C: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x80054880: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80054884: lw          $t8, -0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, -0X8);
    // 0x80054888: lw          $t9, 0x18($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X18);
    // 0x8005488C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80054890: addu        $a0, $t9, $t7
    ctx->r4 = ADD32(ctx->r25, ctx->r15);
    // 0x80054894: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80054898: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8005489C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800548A0: lw          $t7, -0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, -0X4);
    // 0x800548A4: lw          $t9, 0x18($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X18);
    // 0x800548A8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800548AC: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
    // 0x800548B0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800548B4: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800548B8: bne         $s0, $a2, L_80054848
    if (ctx->r16 != ctx->r6) {
        // 0x800548BC: sw          $t7, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r15;
            goto L_80054848;
    }
    // 0x800548BC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_800548C0:
    // 0x800548C0: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x800548C4: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800548C8: lw          $s3, 0xC8($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC8);
    // 0x800548CC: multu       $fp, $t9
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800548D0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800548D4: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x800548D8: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800548DC: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800548E0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800548E4: mflo        $t6
    ctx->r14 = lo;
    // 0x800548E8: srl         $t8, $t6, 1
    ctx->r24 = S32(U32(ctx->r14) >> 1);
    // 0x800548EC: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x800548F0: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x800548F4: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
L_800548F8:
    // 0x800548F8: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x800548FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80054900: beq         $t9, $zero, L_80054AA8
    if (ctx->r25 == 0) {
        // 0x80054904: sw          $zero, 0x88($sp)
        MEM_W(0X88, ctx->r29) = 0;
            goto L_80054AA8;
    }
    // 0x80054904: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x80054908: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x8005490C: multu       $s2, $t6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054910: mflo        $t8
    ctx->r24 = lo;
    // 0x80054914: srl         $t7, $t8, 1
    ctx->r15 = S32(U32(ctx->r24) >> 1);
    // 0x80054918: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x8005491C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_80054920:
    // 0x80054920: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x80054924: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80054928: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8005492C: beq         $t6, $zero, L_80054A90
    if (ctx->r14 == 0) {
        // 0x80054930: lw          $t8, 0xC4($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC4);
            goto L_80054A90;
    }
    // 0x80054930: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x80054934: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80054938: addu        $s0, $t8, $t7
    ctx->r16 = ADD32(ctx->r24, ctx->r15);
L_8005493C:
    // 0x8005493C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80054940: addu        $t6, $s3, $s1
    ctx->r14 = ADD32(ctx->r19, ctx->r17);
    // 0x80054944: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80054948: bnel        $s7, $t9, L_80054A80
    if (ctx->r23 != ctx->r25) {
        // 0x8005494C: lw          $t8, 0xBC($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XBC);
            goto L_80054A80;
    }
    goto skip_7;
    // 0x8005494C: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    skip_7:
    // 0x80054950: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x80054954: sll         $a0, $s2, 7
    ctx->r4 = S32(ctx->r18 << 7);
    // 0x80054958: sll         $t2, $fp, 7
    ctx->r10 = S32(ctx->r30 << 7);
    // 0x8005495C: beq         $v0, $zero, L_80054990
    if (ctx->r2 == 0) {
        // 0x80054960: addu        $t4, $fp, $ra
        ctx->r12 = ADD32(ctx->r30, ctx->r31);
            goto L_80054990;
    }
    // 0x80054960: addu        $t4, $fp, $ra
    ctx->r12 = ADD32(ctx->r30, ctx->r31);
    // 0x80054964: beq         $v0, $s4, L_800549A4
    if (ctx->r2 == ctx->r20) {
        // 0x80054968: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800549A4;
    }
    // 0x80054968: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005496C: beq         $v0, $s5, L_800549B4
    if (ctx->r2 == ctx->r21) {
        // 0x80054970: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_800549B4;
    }
    // 0x80054970: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80054974: beq         $v0, $s6, L_800549C4
    if (ctx->r2 == ctx->r22) {
        // 0x80054978: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_800549C4;
    }
    // 0x80054978: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8005497C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80054980: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80054984: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80054988: b           L_800549D0
    // 0x8005498C: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_800549D0;
    // 0x8005498C: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_80054990:
    // 0x80054990: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80054994: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80054998: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8005499C: b           L_800549D0
    // 0x800549A0: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_800549D0;
    // 0x800549A0: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_800549A4:
    // 0x800549A4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800549A8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800549AC: b           L_800549D0
    // 0x800549B0: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_800549D0;
    // 0x800549B0: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_800549B4:
    // 0x800549B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800549B8: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800549BC: b           L_800549D0
    // 0x800549C0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
        goto L_800549D0;
    // 0x800549C0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
L_800549C4:
    // 0x800549C4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800549C8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800549CC: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
L_800549D0:
    // 0x800549D0: addu        $a0, $s2, $t3
    ctx->r4 = ADD32(ctx->r18, ctx->r11);
    // 0x800549D4: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x800549D8: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x800549DC: sh          $ra, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r31;
    // 0x800549E0: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x800549E4: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x800549E8: sh          $a3, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r7;
    // 0x800549EC: sh          $t1, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r9;
    // 0x800549F0: sb          $a1, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r5;
    // 0x800549F4: sb          $a1, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r5;
    // 0x800549F8: sb          $a1, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r5;
    // 0x800549FC: sb          $a1, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r5;
    // 0x80054A00: sh          $a0, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r4;
    // 0x80054A04: sh          $ra, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r31;
    // 0x80054A08: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x80054A0C: sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // 0x80054A10: sh          $t0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r8;
    // 0x80054A14: sh          $t1, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r9;
    // 0x80054A18: sb          $a1, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r5;
    // 0x80054A1C: sb          $a1, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r5;
    // 0x80054A20: sb          $a1, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r5;
    // 0x80054A24: sb          $a1, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = ctx->r5;
    // 0x80054A28: sh          $a0, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r4;
    // 0x80054A2C: sh          $t4, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r12;
    // 0x80054A30: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x80054A34: sh          $zero, 0x26($v1)
    MEM_H(0X26, ctx->r3) = 0;
    // 0x80054A38: sh          $t0, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r8;
    // 0x80054A3C: sh          $a2, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r6;
    // 0x80054A40: sb          $a1, 0x2C($v1)
    MEM_B(0X2C, ctx->r3) = ctx->r5;
    // 0x80054A44: sb          $a1, 0x2D($v1)
    MEM_B(0X2D, ctx->r3) = ctx->r5;
    // 0x80054A48: sb          $a1, 0x2E($v1)
    MEM_B(0X2E, ctx->r3) = ctx->r5;
    // 0x80054A4C: sb          $a1, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = ctx->r5;
    // 0x80054A50: sh          $t3, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r11;
    // 0x80054A54: sb          $a1, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r5;
    // 0x80054A58: sb          $a1, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r5;
    // 0x80054A5C: sb          $a1, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r5;
    // 0x80054A60: sb          $a1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r5;
    // 0x80054A64: sh          $a2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r6;
    // 0x80054A68: sh          $a3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r7;
    // 0x80054A6C: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x80054A70: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80054A74: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    // 0x80054A78: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x80054A7C: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
L_80054A80:
    // 0x80054A80: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x80054A84: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80054A88: bne         $t5, $t8, L_8005493C
    if (ctx->r13 != ctx->r24) {
        // 0x80054A8C: addu        $t3, $t3, $s2
        ctx->r11 = ADD32(ctx->r11, ctx->r18);
            goto L_8005493C;
    }
    // 0x80054A8C: addu        $t3, $t3, $s2
    ctx->r11 = ADD32(ctx->r11, ctx->r18);
L_80054A90:
    // 0x80054A90: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x80054A94: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x80054A98: addu        $ra, $ra, $fp
    ctx->r31 = ADD32(ctx->r31, ctx->r30);
    // 0x80054A9C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80054AA0: bne         $v0, $t7, L_80054920
    if (ctx->r2 != ctx->r15) {
        // 0x80054AA4: sw          $v0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r2;
            goto L_80054920;
    }
    // 0x80054AA4: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
L_80054AA8:
    // 0x80054AA8: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x80054AAC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80054AB0: lw          $t6, 0x14($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X14);
    // 0x80054AB4: sltu        $at, $t6, $s7
    ctx->r1 = ctx->r14 < ctx->r23 ? 1 : 0;
    // 0x80054AB8: beql        $at, $zero, L_800548F8
    if (ctx->r1 == 0) {
        // 0x80054ABC: lw          $t9, 0xC0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC0);
            goto L_800548F8;
    }
    goto skip_8;
    // 0x80054ABC: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    skip_8:
    // 0x80054AC0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80054AC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80054AC8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80054ACC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80054AD0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80054AD4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80054AD8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80054ADC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80054AE0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80054AE4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80054AE8: jr          $ra
    // 0x80054AEC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80054AEC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_804468D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804468D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804468D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804468DC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804468E0: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x804468E4: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X131F4) << 16);
    // 0x804468E8: sw          $a1, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r5;
    // 0x804468EC: sw          $a1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r5;
    // 0x804468F0: lw          $v1, 0x75D4($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(98, 0X131F4));
    // 0x804468F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x804468F8: beql        $v1, $zero, L_80446910
    if (ctx->r3 == 0) {
        // 0x804468FC: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80446910;
    }
    goto skip_0;
    // 0x804468FC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    skip_0:
    // 0x80446900: jalr        $v1
    // 0x80446904: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80446904: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80446908: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044690C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
L_80446910:
    // 0x80446910: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446914: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80446918: sw          $t6, 0x6CBC($at)
    MEM_W(0X6CBC, ctx->r1) = ctx->r14;
    // 0x8044691C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80446920: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80446924: jr          $ra
    // 0x80446928: nop

    return;
    // 0x80446928: nop

;}
RECOMP_FUNC void func_8044BB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BB24: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8044BB28: jr          $ra
    // 0x8044BB2C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8044BB2C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_80445148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445148: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044514C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80445150: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80445154: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80445158: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8044515C: jal         0x80047090
    // 0x80445160: addiu       $a0, $zero, 0x40F6
    ctx->r4 = ADD32(0, 0X40F6);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80445160: addiu       $a0, $zero, 0x40F6
    ctx->r4 = ADD32(0, 0X40F6);
    after_0:
    // 0x80445164: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80445168: beq         $v0, $at, L_80445298
    if (ctx->r2 == ctx->r1) {
        // 0x8044516C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80445298;
    }
    // 0x8044516C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80445170: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80445174: lui         $at, 0x40F6
    ctx->r1 = S32(0X40F6 << 16);
    // 0x80445178: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8044517C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80445180: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80445184: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80445188: jal         0x8004613C
    // 0x8044518C: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8044518C: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x80445190: beq         $v0, $zero, L_80445298
    if (ctx->r2 == 0) {
        // 0x80445194: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80445298;
    }
    // 0x80445194: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80445198: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8044519C: jal         0x80047F9C
    // 0x804451A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x804451A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x804451A4: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x804451A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804451AC: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x804451B0: jalr        $t9
    // 0x804451B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x804451B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804451B8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x804451BC: lw          $t7, -0x71A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X71A8);
    // 0x804451C0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14000) << 16);
    // 0x804451C4: addiu       $a0, $zero, 0x4024
    ctx->r4 = ADD32(0, 0X4024);
    // 0x804451C8: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x804451CC: srl         $t0, $t8, 30
    ctx->r8 = S32(U32(ctx->r24) >> 30);
    // 0x804451D0: bne         $t0, $zero, L_8044520C
    if (ctx->r8 != 0) {
        // 0x804451D4: addiu       $a1, $zero, 0x37
        ctx->r5 = ADD32(0, 0X37);
            goto L_8044520C;
    }
    // 0x804451D4: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x804451D8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X13FF8) << 16);
    // 0x804451DC: lwc1        $f0, -0x7C28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13FF8));
    // 0x804451E0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X13FFC) << 16);
    // 0x804451E4: lwc1        $f4, -0x7C24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13FFC));
    // 0x804451E8: addiu       $a0, $zero, 0x4024
    ctx->r4 = ADD32(0, 0X4024);
    // 0x804451EC: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x804451F0: lui         $a2, 0xC264
    ctx->r6 = S32(0XC264 << 16);
    // 0x804451F4: lui         $a3, 0xC2C6
    ctx->r7 = S32(0XC2C6 << 16);
    // 0x804451F8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x804451FC: jal         0x8005D078
    // 0x80445200: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8005D078(rdram, ctx);
        goto after_4;
    // 0x80445200: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80445204: b           L_80445228
    // 0x80445208: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80445228;
    // 0x80445208: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8044520C:
    // 0x8044520C: lwc1        $f0, -0x7C20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14000));
    // 0x80445210: lui         $a2, 0xC1F8
    ctx->r6 = S32(0XC1F8 << 16);
    // 0x80445214: lui         $a3, 0xC2C6
    ctx->r7 = S32(0XC2C6 << 16);
    // 0x80445218: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8044521C: jal         0x8005D078
    // 0x80445220: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8005D078(rdram, ctx);
        goto after_5;
    // 0x80445220: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80445224: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80445228:
    // 0x80445228: beq         $v0, $zero, L_80445290
    if (ctx->r2 == 0) {
        // 0x8044522C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80445290;
    }
    // 0x8044522C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80445230: jal         0x80047F9C
    // 0x80445234: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x80445234: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_6:
    // 0x80445238: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8044523C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80445240: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80445244: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80445248: sb          $t1, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r9;
    // 0x8044524C: lw          $t2, 0x478($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X478);
    // 0x80445250: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14004) << 16);
    // 0x80445254: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80445258: swc1        $f0, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->f0.u32l;
    // 0x8044525C: swc1        $f0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f0.u32l;
    // 0x80445260: lw          $t3, 0x478($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X478);
    // 0x80445264: lwc1        $f0, 0x4($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X4);
    // 0x80445268: swc1        $f0, 0x88($a1)
    MEM_W(0X88, ctx->r5) = ctx->f0.u32l;
    // 0x8044526C: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
    // 0x80445270: lw          $t4, 0x478($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X478);
    // 0x80445274: lwc1        $f8, -0x7C1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14004));
    // 0x80445278: lwc1        $f6, 0x8($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8044527C: sb          $zero, 0x165($a1)
    MEM_B(0X165, ctx->r5) = 0;
    // 0x80445280: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80445284: swc1        $f0, 0x8C($a1)
    MEM_W(0X8C, ctx->r5) = ctx->f0.u32l;
    // 0x80445288: b           L_80445298
    // 0x8044528C: swc1        $f0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f0.u32l;
        goto L_80445298;
    // 0x8044528C: swc1        $f0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f0.u32l;
L_80445290:
    // 0x80445290: jal         0x800445A4
    // 0x80445294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_7;
    // 0x80445294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80445298:
    // 0x80445298: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8044529C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x804452A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804452A4: jr          $ra
    // 0x804452A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x804452A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8078FB78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078FB78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078FB7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078FB80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8078FB84: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x8078FB88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8078FB8C: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8078FB90: beq         $a2, $at, L_8078FBBC
    if (ctx->r6 == ctx->r1) {
        // 0x8078FB94: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_8078FBBC;
    }
    // 0x8078FB94: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8078FB98: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x8078FB9C: bne         $v1, $at, L_8078FC1C
    if (ctx->r3 != ctx->r1) {
        // 0x8078FBA0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8078FC1C;
    }
    // 0x8078FBA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078FBA4: jal         0x8078FD04
    // 0x8078FBA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8078FD04(rdram, ctx);
        goto after_0;
    // 0x8078FBA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8078FBAC: jal         0x8078F7C0
    // 0x8078FBB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8078F7C0(rdram, ctx);
        goto after_1;
    // 0x8078FBB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8078FBB4: b           L_8078FC20
    // 0x8078FBB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078FC20;
    // 0x8078FBB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078FBBC:
    // 0x8078FBBC: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    // 0x8078FBC0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8078FBC4: bnel        $a1, $at, L_8078FBE0
    if (ctx->r5 != ctx->r1) {
        // 0x8078FBC8: sb          $a2, 0x18($a0)
        MEM_B(0X18, ctx->r4) = ctx->r6;
            goto L_8078FBE0;
    }
    goto skip_0;
    // 0x8078FBC8: sb          $a2, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r6;
    skip_0:
    // 0x8078FBCC: jal         0x8078FD04
    // 0x8078FBD0: nop

    func_8078FD04(rdram, ctx);
        goto after_2;
    // 0x8078FBD0: nop

    after_2:
    // 0x8078FBD4: b           L_8078FC20
    // 0x8078FBD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078FC20;
    // 0x8078FBD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078FBDC: sb          $a2, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r6;
L_8078FBE0:
    // 0x8078FBE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8078FBE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8078FBE8: jal         0x8078FD04
    // 0x8078FBEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8078FD04(rdram, ctx);
        goto after_3;
    // 0x8078FBEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x8078FBF0: jal         0x8078FB4C
    // 0x8078FBF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8078FB4C(rdram, ctx);
        goto after_4;
    // 0x8078FBF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8078FBF8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8078FBFC: addiu       $t6, $zero, 0x102
    ctx->r14 = ADD32(0, 0X102);
    // 0x8078FC00: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x8078FC04: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8078FC08: addiu       $t8, $t8, -0x6030
    ctx->r24 = ADD32(ctx->r24, -0X6030);
    // 0x8078FC0C: sh          $t6, 0x4C($t7)
    MEM_H(0X4C, ctx->r15) = ctx->r14;
    // 0x8078FC10: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8078FC14: sw          $t8, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->r24;
    // 0x8078FC18: sb          $zero, 0x11($v0)
    MEM_B(0X11, ctx->r2) = 0;
L_8078FC1C:
    // 0x8078FC1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078FC20:
    // 0x8078FC20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078FC24: jr          $ra
    // 0x8078FC28: nop

    return;
    // 0x8078FC28: nop

;}
RECOMP_FUNC void func_80018FF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018FF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018FFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019000: jal         0x8001A028
    // 0x80019004: nop

    func_8001A028(rdram, ctx);
        goto after_0;
    // 0x80019004: nop

    after_0:
    // 0x80019008: jal         0x8001B004
    // 0x8001900C: nop

    func_8001B004(rdram, ctx);
        goto after_1;
    // 0x8001900C: nop

    after_1:
    // 0x80019010: jal         0x80019184
    // 0x80019014: nop

    func_80019184(rdram, ctx);
        goto after_2;
    // 0x80019014: nop

    after_2:
    // 0x80019018: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8001901C: lbu         $t6, -0x6D00($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6D00);
    // 0x80019020: bnel        $t6, $zero, L_80019034
    if (ctx->r14 != 0) {
        // 0x80019024: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80019034;
    }
    goto skip_0;
    // 0x80019024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80019028: jal         0x8000A3E8
    // 0x8001902C: nop

    func_8000A3E8(rdram, ctx);
        goto after_3;
    // 0x8001902C: nop

    after_3:
    // 0x80019030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80019034:
    // 0x80019034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019038: jr          $ra
    // 0x8001903C: nop

    return;
    // 0x8001903C: nop

;}
RECOMP_FUNC void func_80471B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471B6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80471B70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80471B74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80471B78: jal         0x80045A34
    // 0x80471B7C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80471B7C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80471B80: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80471B84: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x80471B88: bne         $v0, $zero, L_80471B98
    if (ctx->r2 != 0) {
        // 0x80471B8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80471B98;
    }
    // 0x80471B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80471B90: b           L_80471B9C
    // 0x80471B94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80471B9C;
    // 0x80471B94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80471B98:
    // 0x80471B98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80471B9C:
    // 0x80471B9C: jr          $ra
    // 0x80471BA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80471BA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805A8F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A8F54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A8F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A8F5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805A8F60: jal         0x80064E84
    // 0x805A8F64: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x805A8F64: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x805A8F68: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x805A8F6C: jal         0x80064E84
    // 0x805A8F70: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x805A8F70: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    after_1:
    // 0x805A8F74: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x805A8F78: jal         0x80064E84
    // 0x805A8F7C: lw          $a0, 0x24($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X24);
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x805A8F7C: lw          $a0, 0x24($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X24);
    after_2:
    // 0x805A8F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A8F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A8F88: jr          $ra
    // 0x805A8F8C: nop

    return;
    // 0x805A8F8C: nop

;}
RECOMP_FUNC void func_80776E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80776E6C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80776E70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80776E74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80776E78: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80776E7C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80776E80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80776E84: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80776E88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80776E8C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80776E90: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80776E94: nop

    // 0x80776E98: bc1fl       L_80776EB4
    if (!c1cs) {
        // 0x80776E9C: lw          $t6, 0x1E0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X1E0);
            goto L_80776EB4;
    }
    goto skip_0;
    // 0x80776E9C: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    skip_0:
    // 0x80776EA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80776EA4: nop

    // 0x80776EA8: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80776EAC: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80776EB0: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
L_80776EB4:
    // 0x80776EB4: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80776EB8: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x80776EBC: bne         $t8, $zero, L_80776F08
    if (ctx->r24 != 0) {
        // 0x80776EC0: sw          $v0, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r2;
            goto L_80776F08;
    }
    // 0x80776EC0: sw          $v0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r2;
    // 0x80776EC4: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80776EC8: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(772, 0X854) << 16);
    // 0x80776ECC: lwc1        $f4, 0x7324($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X854));
    // 0x80776ED0: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80776ED4: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80776ED8: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80776EDC: lw          $t9, -0x72C0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72C0);
    // 0x80776EE0: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80776EE4: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80776EE8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80776EEC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80776EF0: jalr        $t9
    // 0x80776EF4: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80776EF4: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80776EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80776EFC: jal         0x80776C38
    // 0x80776F00: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80776C38(rdram, ctx);
        goto after_1;
    // 0x80776F00: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_1:
    // 0x80776F04: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_80776F08:
    // 0x80776F08: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x80776F0C: bne         $at, $zero, L_80776F30
    if (ctx->r1 != 0) {
        // 0x80776F10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80776F30;
    }
    // 0x80776F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80776F14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80776F18: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80776F1C: jal         0x8077725C
    // 0x80776F20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8077725C(rdram, ctx);
        goto after_2;
    // 0x80776F20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80776F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80776F28: jal         0x80776BD8
    // 0x80776F2C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80776BD8(rdram, ctx);
        goto after_3;
    // 0x80776F2C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_3:
L_80776F30:
    // 0x80776F30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80776F34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80776F38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80776F3C: jr          $ra
    // 0x80776F40: nop

    return;
    // 0x80776F40: nop

;}
RECOMP_FUNC void func_8007FE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FE74: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007FE78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FE7C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8007FE80: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8007FE84: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8007FE88: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8007FE8C: jal         0x800818E8
    // 0x8007FE90: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    MtxConv_L2F(rdram, ctx);
        goto after_0;
    // 0x8007FE90: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8007FE94: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007FE98: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8007FE9C: jal         0x80080440
    // 0x8007FEA0: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    func_80080440(rdram, ctx);
        goto after_1;
    // 0x8007FEA0: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x8007FEA4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8007FEA8: jal         0x800817A0
    // 0x8007FEAC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    MtxConv_F2L(rdram, ctx);
        goto after_2;
    // 0x8007FEAC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8007FEB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FEB4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8007FEB8: jr          $ra
    // 0x8007FEBC: nop

    return;
    // 0x8007FEBC: nop

;}
RECOMP_FUNC void func_806EBF50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EBF50: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x806EBF54: addiu       $at, $zero, 0x45E3
    ctx->r1 = ADD32(0, 0X45E3);
    // 0x806EBF58: beq         $v0, $at, L_806EBF80
    if (ctx->r2 == ctx->r1) {
        // 0x806EBF5C: addiu       $at, $zero, 0x45E4
        ctx->r1 = ADD32(0, 0X45E4);
            goto L_806EBF80;
    }
    // 0x806EBF5C: addiu       $at, $zero, 0x45E4
    ctx->r1 = ADD32(0, 0X45E4);
    // 0x806EBF60: beq         $v0, $at, L_806EBF98
    if (ctx->r2 == ctx->r1) {
        // 0x806EBF64: addiu       $at, $zero, 0x45E5
        ctx->r1 = ADD32(0, 0X45E5);
            goto L_806EBF98;
    }
    // 0x806EBF64: addiu       $at, $zero, 0x45E5
    ctx->r1 = ADD32(0, 0X45E5);
    // 0x806EBF68: beq         $v0, $at, L_806EBF8C
    if (ctx->r2 == ctx->r1) {
        // 0x806EBF6C: addiu       $at, $zero, 0x45E8
        ctx->r1 = ADD32(0, 0X45E8);
            goto L_806EBF8C;
    }
    // 0x806EBF6C: addiu       $at, $zero, 0x45E8
    ctx->r1 = ADD32(0, 0X45E8);
    // 0x806EBF70: beq         $v0, $at, L_806EBFA4
    if (ctx->r2 == ctx->r1) {
        // 0x806EBF74: nop
    
            goto L_806EBFA4;
    }
    // 0x806EBF74: nop

    // 0x806EBF78: b           L_806EBFB0
    // 0x806EBF7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806EBFB0;
    // 0x806EBF7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806EBF80:
    // 0x806EBF80: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(676, 0X4350) << 16);
    // 0x806EBF84: jr          $ra
    // 0x806EBF88: addiu       $v0, $v0, 0x2A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(676, 0X4350));
    return;
    // 0x806EBF88: addiu       $v0, $v0, 0x2A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(676, 0X4350));
L_806EBF8C:
    // 0x806EBF8C: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(676, 0X1364) << 16);
    // 0x806EBF90: jr          $ra
    // 0x806EBF94: addiu       $v0, $v0, -0x2D4C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(676, 0X1364));
    return;
    // 0x806EBF94: addiu       $v0, $v0, -0x2D4C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(676, 0X1364));
L_806EBF98:
    // 0x806EBF98: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(676, 0X34A8) << 16);
    // 0x806EBF9C: jr          $ra
    // 0x806EBFA0: addiu       $v0, $v0, -0xC08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(676, 0X34A8));
    return;
    // 0x806EBFA0: addiu       $v0, $v0, -0xC08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(676, 0X34A8));
L_806EBFA4:
    // 0x806EBFA4: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(676, 0X2588) << 16);
    // 0x806EBFA8: jr          $ra
    // 0x806EBFAC: addiu       $v0, $v0, -0x1B28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(676, 0X2588));
    return;
    // 0x806EBFAC: addiu       $v0, $v0, -0x1B28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(676, 0X2588));
L_806EBFB0:
    // 0x806EBFB0: jr          $ra
    // 0x806EBFB4: nop

    return;
    // 0x806EBFB4: nop

;}
RECOMP_FUNC void func_80699C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699C04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80699C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80699C0C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80699C10: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80699C14: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80699C18: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(562, 0XCD8) << 16);
    // 0x80699C1C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80699C20: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80699C24: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80699C28: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80699C2C: lw          $t8, -0x5E58($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(562, 0XCD8));
    // 0x80699C30: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80699C34: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80699C38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80699C3C: jal         0x80048490
    // 0x80699C40: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80699C40: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80699C44: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80699C48: jal         0x80048378
    // 0x80699C4C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80699C4C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80699C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80699C54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80699C58: jr          $ra
    // 0x80699C5C: nop

    return;
    // 0x80699C5C: nop

;}
RECOMP_FUNC void func_807938B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807938B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807938B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807938B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807938BC: jal         0x80793830
    // 0x807938C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80793830(rdram, ctx);
        goto after_0;
    // 0x807938C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807938C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807938C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807938CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807938D0: jal         0x8079393C
    // 0x807938D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8079393C(rdram, ctx);
        goto after_1;
    // 0x807938D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x807938D8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x807938DC: jal         0x8006CB0C
    // 0x807938E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006CB0C(rdram, ctx);
        goto after_2;
    // 0x807938E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807938E4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x807938E8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807938EC: jal         0x8006CB1C
    // 0x807938F0: nop

    func_8006CB1C(rdram, ctx);
        goto after_3;
    // 0x807938F0: nop

    after_3:
    // 0x807938F4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x807938F8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807938FC: jal         0x8006CB2C
    // 0x80793900: nop

    func_8006CB2C(rdram, ctx);
        goto after_4;
    // 0x80793900: nop

    after_4:
    // 0x80793904: jal         0x8006CAE0
    // 0x80793908: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8006CAE0(rdram, ctx);
        goto after_5;
    // 0x80793908: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8079390C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80793910: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80793914: sw          $t6, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r14;
    // 0x80793918: sh          $t7, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r15;
    // 0x8079391C: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x80793920: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80793924: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80793928: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8079392C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80793930: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x80793934: jr          $ra
    // 0x80793938: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80793938: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_804B6BF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6BF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B6BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B6C00: jal         0x804B6AC0
    // 0x804B6C04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804B6AC0(rdram, ctx);
        goto after_0;
    // 0x804B6C04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804B6C08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6C0C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804B6C10: lui         $t7, 0x804B
    ctx->r15 = S32(RELOC_HI16(182, 0XF2C) << 16);
    // 0x804B6C14: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804B6C18: addiu       $t7, $t7, 0x71CC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(182, 0XF2C));
    // 0x804B6C1C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804B6C20: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804B6C24: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804B6C28: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x804B6C2C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x804B6C30: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x804B6C34: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x804B6C38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804B6C3C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804B6C40: sh          $t9, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r25;
    // 0x804B6C44: sw          $t0, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r8;
    // 0x804B6C48: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x804B6C4C: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x804B6C50: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x804B6C54: bnel        $t2, $zero, L_804B6C70
    if (ctx->r10 != 0) {
        // 0x804B6C58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804B6C70;
    }
    goto skip_0;
    // 0x804B6C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804B6C5C: jal         0x80045A34
    // 0x804B6C60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x804B6C60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x804B6C64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6C68: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804B6C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804B6C70:
    // 0x804B6C70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B6C74: jr          $ra
    // 0x804B6C78: nop

    return;
    // 0x804B6C78: nop

;}
RECOMP_FUNC void func_806AFF90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AFF90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AFF94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806AFF98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AFF9C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x806AFFA0: lui         $a2, 0x806B
    ctx->r6 = S32(RELOC_HI16(598, 0X1498) << 16);
    // 0x806AFFA4: addiu       $a2, $a2, 0x1428
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(598, 0X1498));
    // 0x806AFFA8: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x806AFFAC: jal         0x80057B28
    // 0x806AFFB0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_80057B28(rdram, ctx);
        goto after_0;
    // 0x806AFFB0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_0:
    // 0x806AFFB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AFFB8: lui         $v0, 0x806B
    ctx->r2 = S32(RELOC_HI16(598, 0X1644) << 16);
    // 0x806AFFBC: addiu       $v0, $v0, 0x15D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(598, 0X1644));
    // 0x806AFFC0: jr          $ra
    // 0x806AFFC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806AFFC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80059848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005984C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059850: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80059854: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80059858: jal         0x80081C64
    // 0x8005985C: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x8005985C: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x80059860: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80059864: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80059868: lw          $v1, 0x3F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3F4);
    // 0x8005986C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80059870: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80059874: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80059878: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8005987C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80059880: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80059884: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80059888: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x8005988C: lw          $t7, 0x478($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X478);
    // 0x80059890: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80059894: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80059898: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8005989C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800598A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800598A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800598A8: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800598AC: lwc1        $f6, 0x34($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X34);
    // 0x800598B0: mul.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800598B4: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800598B8: add.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x800598BC: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800598C0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800598C4: nop

    // 0x800598C8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800598CC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800598D0: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800598D4: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x800598D8: nop

    // 0x800598DC: bc1f        L_800598E8
    if (!c1cs) {
        // 0x800598E0: nop
    
            goto L_800598E8;
    }
    // 0x800598E0: nop

    // 0x800598E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800598E8:
    // 0x800598E8: jr          $ra
    // 0x800598EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800598EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80051B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051B48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80051B4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80051B50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80051B54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80051B58: jal         0x80050D74
    // 0x80051B5C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80050D74(rdram, ctx);
        goto after_0;
    // 0x80051B5C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80051B60: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80051B64: jal         0x8005ACD4
    // 0x80051B68: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_8005ACD4(rdram, ctx);
        goto after_1;
    // 0x80051B68: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_1:
    // 0x80051B6C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80051B70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80051B74: lbu         $t6, 0x3E($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3E);
    // 0x80051B78: bne         $t6, $at, L_80051B8C
    if (ctx->r14 != ctx->r1) {
        // 0x80051B7C: nop
    
            goto L_80051B8C;
    }
    // 0x80051B7C: nop

    // 0x80051B80: jal         0x80050A2C
    // 0x80051B84: lw          $a0, 0x40($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X40);
    func_80050A2C(rdram, ctx);
        goto after_2;
    // 0x80051B84: lw          $a0, 0x40($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X40);
    after_2:
    // 0x80051B88: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
L_80051B8C:
    // 0x80051B8C: jal         0x80064E84
    // 0x80051B90: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80064E84(rdram, ctx);
        goto after_3;
    // 0x80051B90: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x80051B94: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80051B98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80051B9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80051BA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80051BA4: jr          $ra
    // 0x80051BA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80051BA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80022EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022EE4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022EE8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80022EEC: lwc1        $f4, -0x35C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X35C);
    // 0x80022EF0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022EF4: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x80022EF8: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
    // 0x80022EFC: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x80022F00: lwc1        $f6, -0x358($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X358);
    // 0x80022F04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022F08: swc1        $f6, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f6.u32l;
    // 0x80022F0C: lwc1        $f8, -0x354($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X354);
    // 0x80022F10: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80022F14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80022F18: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    // 0x80022F1C: jr          $ra
    // 0x80022F20: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80022F20: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void lround_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008211C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80082120: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80082124: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80082128: nop

    // 0x8008212C: add.d       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f12.d + ctx->f4.d;
    // 0x80082130: floor.w.d   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = S32(floor(ctx->f0.d));
    // 0x80082134: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x80082138: jr          $ra
    // 0x8008213C: nop

    return;
    // 0x8008213C: nop

;}
RECOMP_FUNC void func_80742E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742E94: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742E98: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742E9C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742EA0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742EA4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742EA8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742EAC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742EB0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742EB4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742EB8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742EBC: jr          $ra
    // 0x80742EC0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742EC0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8004F85C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F85C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004F860: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004F864: lw          $v1, 0x1B8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1B8);
    // 0x8004F868: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8004F86C: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x8004F870: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8004F874: jal         0x8006A99C
    // 0x8004F878: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8006A99C(rdram, ctx);
        goto after_0;
    // 0x8004F878: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8004F87C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8004F880: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F884: sh          $v0, 0x52($a1)
    MEM_H(0X52, ctx->r5) = ctx->r2;
    // 0x8004F888: lh          $t6, 0x52($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X52);
    // 0x8004F88C: sh          $t6, 0x3A($a1)
    MEM_H(0X3A, ctx->r5) = ctx->r14;
    // 0x8004F890: jal         0x8006A99C
    // 0x8004F894: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x8004F894: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    after_1:
    // 0x8004F898: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8004F89C: sh          $v0, 0x54($a1)
    MEM_H(0X54, ctx->r5) = ctx->r2;
    // 0x8004F8A0: lh          $t7, 0x54($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X54);
    // 0x8004F8A4: sh          $t7, 0x3C($a1)
    MEM_H(0X3C, ctx->r5) = ctx->r15;
    // 0x8004F8A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004F8AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004F8B0: jr          $ra
    // 0x8004F8B4: nop

    return;
    // 0x8004F8B4: nop

;}
RECOMP_FUNC void func_804BD1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD1F0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x804BD1F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BD1F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BD1FC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x804BD200: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x804BD204: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x804BD208: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x804BD20C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x804BD210: bne         $t6, $at, L_804BD2FC
    if (ctx->r14 != ctx->r1) {
        // 0x804BD214: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_804BD2FC;
    }
    // 0x804BD214: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804BD218: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x804BD21C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804BD220: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x804BD224: beql        $t7, $at, L_804BD354
    if (ctx->r15 == ctx->r1) {
        // 0x804BD228: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804BD354;
    }
    goto skip_0;
    // 0x804BD228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804BD22C: lw          $a1, 0x180($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X180);
    // 0x804BD230: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x804BD234: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x804BD238: beq         $a1, $zero, L_804BD244
    if (ctx->r5 == 0) {
        // 0x804BD23C: nop
    
            goto L_804BD244;
    }
    // 0x804BD23C: nop

    // 0x804BD240: lw          $a3, 0x180($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X180);
L_804BD244:
    // 0x804BD244: beql        $a3, $zero, L_804BD27C
    if (ctx->r7 == 0) {
        // 0x804BD248: lwc1        $f4, 0x3C($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_804BD27C;
    }
    goto skip_1;
    // 0x804BD248: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    skip_1:
    // 0x804BD24C: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
L_804BD250:
    // 0x804BD250: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x804BD254: beql        $a1, $t9, L_804BD26C
    if (ctx->r5 == ctx->r25) {
        // 0x804BD258: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_804BD26C;
    }
    goto skip_2;
    // 0x804BD258: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    skip_2:
    // 0x804BD25C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x804BD260: bne         $v1, $a0, L_804BD250
    if (ctx->r3 != ctx->r4) {
        // 0x804BD264: addiu       $v0, $v0, 0x4C
        ctx->r2 = ADD32(ctx->r2, 0X4C);
            goto L_804BD250;
    }
    // 0x804BD264: addiu       $v0, $v0, 0x4C
    ctx->r2 = ADD32(ctx->r2, 0X4C);
    // 0x804BD268: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_804BD26C:
    // 0x804BD26C: beq         $at, $zero, L_804BD278
    if (ctx->r1 == 0) {
        // 0x804BD270: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_804BD278;
    }
    // 0x804BD270: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804BD274: sh          $t0, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r8;
L_804BD278:
    // 0x804BD278: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
L_804BD27C:
    // 0x804BD27C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4198) << 16);
    // 0x804BD280: lwc1        $f8, -0x538($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4198));
    // 0x804BD284: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x804BD288: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804BD28C: lw          $t1, -0x76F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76F8);
    // 0x804BD290: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x804BD294: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x804BD298: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x804BD29C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x804BD2A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804BD2A4: lw          $t9, 0x18($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X18);
    // 0x804BD2A8: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x804BD2AC: jalr        $t9
    // 0x804BD2B0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804BD2B0: nop

    after_0:
    // 0x804BD2B4: jal         0x800447C8
    // 0x804BD2B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x804BD2B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804BD2BC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x804BD2C0: jal         0x80067BBC
    // 0x804BD2C4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x804BD2C4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x804BD2C8: addiu       $a0, $zero, 0x1FD
    ctx->r4 = ADD32(0, 0X1FD);
    // 0x804BD2CC: jal         0x80067818
    // 0x804BD2D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x804BD2D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x804BD2D4: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x804BD2D8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804BD2DC: sb          $t3, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r11;
    // 0x804BD2E0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804BD2E4: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x804BD2E8: sb          $t4, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r12;
    // 0x804BD2EC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804BD2F0: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x804BD2F4: b           L_804BD350
    // 0x804BD2F8: sb          $t5, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r13;
        goto L_804BD350;
    // 0x804BD2F8: sb          $t5, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r13;
L_804BD2FC:
    // 0x804BD2FC: lhu         $t6, 0xC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XC);
    // 0x804BD300: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804BD304: bnel        $t6, $at, L_804BD354
    if (ctx->r14 != ctx->r1) {
        // 0x804BD308: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804BD354;
    }
    goto skip_3;
    // 0x804BD308: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x804BD30C: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x804BD310: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x804BD314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BD318: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x804BD31C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x804BD320: lh          $t0, 0xC($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XC);
    // 0x804BD324: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x804BD328: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x804BD32C: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x804BD330: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x804BD334: mul.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x804BD338: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804BD33C: nop

    // 0x804BD340: bc1fl       L_804BD354
    if (!c1cs) {
        // 0x804BD344: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804BD354;
    }
    goto skip_4;
    // 0x804BD344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x804BD348: jal         0x8002F6E4
    // 0x804BD34C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_4;
    // 0x804BD34C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
L_804BD350:
    // 0x804BD350: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804BD354:
    // 0x804BD354: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BD358: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x804BD35C: jr          $ra
    // 0x804BD360: nop

    return;
    // 0x804BD360: nop

;}
RECOMP_FUNC void func_804C44EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C44EC: lw          $v0, 0x16C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X16C);
    // 0x804C44F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804C44F4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C44F8: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x804C44FC: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x804C4500: addiu       $t1, $sp, 0x34
    ctx->r9 = ADD32(ctx->r29, 0X34);
    // 0x804C4504: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x804C4508: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x804C450C: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x804C4510: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x804C4514: beq         $t1, $a1, L_804C4540
    if (ctx->r9 == ctx->r5) {
        // 0x804C4518: lw          $t6, 0x0($t2)
        ctx->r14 = MEM_W(ctx->r10, 0X0);
            goto L_804C4540;
    }
    // 0x804C4518: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
L_804C451C:
    // 0x804C451C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x804C4520: lwc1        $f16, 0x18($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X18);
    // 0x804C4524: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x804C4528: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804C452C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x804C4530: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x804C4534: swc1        $f16, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f16.u32l;
    // 0x804C4538: bne         $t1, $a1, L_804C451C
    if (ctx->r9 != ctx->r5) {
        // 0x804C453C: lw          $t6, 0x0($t2)
        ctx->r14 = MEM_W(ctx->r10, 0X0);
            goto L_804C451C;
    }
    // 0x804C453C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
L_804C4540:
    // 0x804C4540: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x804C4544: lwc1        $f16, 0x18($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X18);
    // 0x804C4548: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x804C454C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804C4550: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x804C4554: swc1        $f16, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
    // 0x804C4558: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x804C455C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804C4560: lwc1        $f16, 0x18($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X18);
    // 0x804C4564: lhu         $t7, 0xC($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XC);
    // 0x804C4568: addiu       $at, $zero, 0x405E
    ctx->r1 = ADD32(0, 0X405E);
    // 0x804C456C: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804C4570: bne         $t7, $at, L_804C4590
    if (ctx->r15 != ctx->r1) {
        // 0x804C4574: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_804C4590;
    }
    // 0x804C4574: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x804C4578: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x804C457C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(209, 0XE74) << 16);
    // 0x804C4580: lwc1        $f6, 0x4E64($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(209, 0XE74));
    // 0x804C4584: mul.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804C4588: b           L_804C45B0
    // 0x804C458C: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
        goto L_804C45B0;
    // 0x804C458C: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
L_804C4590:
    // 0x804C4590: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x804C4594: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(209, 0XE78) << 16);
    // 0x804C4598: lwc1        $f18, 0x4E68($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(209, 0XE78));
    // 0x804C459C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x804C45A0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804C45A4: mul.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804C45A8: nop

    // 0x804C45AC: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
L_804C45B0:
    // 0x804C45B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C45B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804C45B8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x804C45BC: bc1f        L_804C4624
    if (!c1cs) {
        // 0x804C45C0: nop
    
            goto L_804C4624;
    }
    // 0x804C45C0: nop

    // 0x804C45C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804C45C8: nop

    // 0x804C45CC: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x804C45D0: nop

    // 0x804C45D4: bc1fl       L_804C45E8
    if (!c1cs) {
        // 0x804C45D8: div.s       $f14, $f0, $f14
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = DIV_S(ctx->f0.fl, ctx->f14.fl);
            goto L_804C45E8;
    }
    goto skip_0;
    // 0x804C45D8: div.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = DIV_S(ctx->f0.fl, ctx->f14.fl);
    skip_0:
    // 0x804C45DC: b           L_804C45E8
    // 0x804C45E0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_804C45E8;
    // 0x804C45E0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x804C45E4: div.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = DIV_S(ctx->f0.fl, ctx->f14.fl);
L_804C45E8:
    // 0x804C45E8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x804C45EC: lbu         $t9, 0x4($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X4);
    // 0x804C45F0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804C45F4: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x804C45F8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804C45FC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x804C4600: nop

    // 0x804C4604: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x804C4608: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x804C460C: bnel        $at, $zero, L_804C461C
    if (ctx->r1 != 0) {
        // 0x804C4610: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_804C461C;
    }
    goto skip_1;
    // 0x804C4610: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x804C4614: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x804C4618: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_804C461C:
    // 0x804C461C: bne         $a0, $a2, L_804C45E8
    if (ctx->r4 != ctx->r6) {
        // 0x804C4620: sb          $v1, 0x3($a1)
        MEM_B(0X3, ctx->r5) = ctx->r3;
            goto L_804C45E8;
    }
    // 0x804C4620: sb          $v1, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r3;
L_804C4624:
    // 0x804C4624: jr          $ra
    // 0x804C4628: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x804C4628: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80030EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030EE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030EEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030EF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80030EF4: lbu         $t6, 0x1B4($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1B4);
    // 0x80030EF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80030EFC: beq         $t6, $zero, L_80030F20
    if (ctx->r14 == 0) {
        // 0x80030F00: nop
    
            goto L_80030F20;
    }
    // 0x80030F00: nop

    // 0x80030F04: jal         0x80030BA8
    // 0x80030F08: nop

    func_80030BA8(rdram, ctx);
        goto after_0;
    // 0x80030F08: nop

    after_0:
    // 0x80030F0C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80030F10: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80030F14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030F18: b           L_80030F20
    // 0x80030F1C: sb          $t7, 0x165($t8)
    MEM_B(0X165, ctx->r24) = ctx->r15;
        goto L_80030F20;
    // 0x80030F1C: sb          $t7, 0x165($t8)
    MEM_B(0X165, ctx->r24) = ctx->r15;
L_80030F20:
    // 0x80030F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80030F28: jr          $ra
    // 0x80030F2C: nop

    return;
    // 0x80030F2C: nop

;}
RECOMP_FUNC void func_804F42A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F42A0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804F42A4: lui         $t6, 0x804F
    ctx->r14 = S32(RELOC_HI16(273, 0X454) << 16);
    // 0x804F42A8: addiu       $t6, $t6, 0x46E4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(273, 0X454));
    // 0x804F42AC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804F42B0: jr          $ra
    // 0x804F42B4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x804F42B4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_807AC1A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AC1A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x807AC1AC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x807AC1B0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x807AC1B4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x807AC1B8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x807AC1BC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x807AC1C0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x807AC1C4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AC1C8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x807AC1CC: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x807AC1D0: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x807AC1D4: addiu       $t9, $zero, 0x1D
    ctx->r25 = ADD32(0, 0X1D);
    // 0x807AC1D8: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x807AC1DC: sw          $t6, 0x780($s0)
    MEM_W(0X780, ctx->r16) = ctx->r14;
    // 0x807AC1E0: sw          $t7, 0x784($s0)
    MEM_W(0X784, ctx->r16) = ctx->r15;
    // 0x807AC1E4: sw          $t8, 0x788($s0)
    MEM_W(0X788, ctx->r16) = ctx->r24;
    // 0x807AC1E8: sw          $t9, 0x78C($s0)
    MEM_W(0X78C, ctx->r16) = ctx->r25;
    // 0x807AC1EC: sw          $t0, 0x790($s0)
    MEM_W(0X790, ctx->r16) = ctx->r8;
    // 0x807AC1F0: addiu       $t1, $zero, -0x20
    ctx->r9 = ADD32(0, -0X20);
    // 0x807AC1F4: addiu       $t2, $zero, 0x27F
    ctx->r10 = ADD32(0, 0X27F);
    // 0x807AC1F8: addiu       $t3, $zero, 0x1F
    ctx->r11 = ADD32(0, 0X1F);
    // 0x807AC1FC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x807AC200: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x807AC204: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x807AC208: addiu       $a1, $zero, -0x140
    ctx->r5 = ADD32(0, -0X140);
    // 0x807AC20C: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    // 0x807AC210: addiu       $a3, $zero, 0x280
    ctx->r7 = ADD32(0, 0X280);
    // 0x807AC214: jal         0x807AC0B8
    // 0x807AC218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807AC0B8(rdram, ctx);
        goto after_0;
    // 0x807AC218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x807AC21C: addiu       $s1, $s0, 0x40
    ctx->r17 = ADD32(ctx->r16, 0X40);
    // 0x807AC220: addiu       $t4, $zero, -0x20
    ctx->r12 = ADD32(0, -0X20);
    // 0x807AC224: addiu       $t5, $zero, 0x27F
    ctx->r13 = ADD32(0, 0X27F);
    // 0x807AC228: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x807AC22C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x807AC230: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x807AC234: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x807AC238: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807AC23C: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x807AC240: addiu       $a2, $zero, 0x120
    ctx->r6 = ADD32(0, 0X120);
    // 0x807AC244: jal         0x807AC0B8
    // 0x807AC248: addiu       $a3, $zero, -0x280
    ctx->r7 = ADD32(0, -0X280);
    func_807AC0B8(rdram, ctx);
        goto after_1;
    // 0x807AC248: addiu       $a3, $zero, -0x280
    ctx->r7 = ADD32(0, -0X280);
    after_1:
    // 0x807AC24C: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x807AC250: addiu       $t7, $zero, -0x20
    ctx->r15 = ADD32(0, -0X20);
    // 0x807AC254: addiu       $t8, $zero, 0x27F
    ctx->r24 = ADD32(0, 0X27F);
    // 0x807AC258: addiu       $t9, $zero, 0x1F
    ctx->r25 = ADD32(0, 0X1F);
    // 0x807AC25C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x807AC260: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x807AC264: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x807AC268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807AC26C: addiu       $a1, $zero, -0x140
    ctx->r5 = ADD32(0, -0X140);
    // 0x807AC270: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x807AC274: jal         0x807AC0B8
    // 0x807AC278: addiu       $a3, $zero, 0x280
    ctx->r7 = ADD32(0, 0X280);
    func_807AC0B8(rdram, ctx);
        goto after_2;
    // 0x807AC278: addiu       $a3, $zero, 0x280
    ctx->r7 = ADD32(0, 0X280);
    after_2:
    // 0x807AC27C: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x807AC280: addiu       $t0, $zero, -0x20
    ctx->r8 = ADD32(0, -0X20);
    // 0x807AC284: addiu       $t1, $zero, 0x27F
    ctx->r9 = ADD32(0, 0X27F);
    // 0x807AC288: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x807AC28C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x807AC290: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x807AC294: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x807AC298: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807AC29C: addiu       $a1, $zero, -0x140
    ctx->r5 = ADD32(0, -0X140);
    // 0x807AC2A0: addiu       $a2, $zero, -0xE0
    ctx->r6 = ADD32(0, -0XE0);
    // 0x807AC2A4: jal         0x807AC0B8
    // 0x807AC2A8: addiu       $a3, $zero, 0x280
    ctx->r7 = ADD32(0, 0X280);
    func_807AC0B8(rdram, ctx);
        goto after_3;
    // 0x807AC2A8: addiu       $a3, $zero, 0x280
    ctx->r7 = ADD32(0, 0X280);
    after_3:
    // 0x807AC2AC: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x807AC2B0: addiu       $t3, $zero, -0x20
    ctx->r11 = ADD32(0, -0X20);
    // 0x807AC2B4: addiu       $t4, $zero, 0x27F
    ctx->r12 = ADD32(0, 0X27F);
    // 0x807AC2B8: addiu       $t5, $zero, 0x1F
    ctx->r13 = ADD32(0, 0X1F);
    // 0x807AC2BC: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x807AC2C0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x807AC2C4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x807AC2C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807AC2CC: addiu       $a1, $zero, -0x140
    ctx->r5 = ADD32(0, -0X140);
    // 0x807AC2D0: addiu       $a2, $zero, 0xE0
    ctx->r6 = ADD32(0, 0XE0);
    // 0x807AC2D4: jal         0x807AC0B8
    // 0x807AC2D8: addiu       $a3, $zero, 0x280
    ctx->r7 = ADD32(0, 0X280);
    func_807AC0B8(rdram, ctx);
        goto after_4;
    // 0x807AC2D8: addiu       $a3, $zero, 0x280
    ctx->r7 = ADD32(0, 0X280);
    after_4:
    // 0x807AC2DC: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x807AC2E0: addiu       $s0, $zero, -0x140
    ctx->r16 = ADD32(0, -0X140);
    // 0x807AC2E4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_807AC2E8:
    // 0x807AC2E8: addiu       $t6, $zero, -0x20
    ctx->r14 = ADD32(0, -0X20);
    // 0x807AC2EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x807AC2F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807AC2F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807AC2F8: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x807AC2FC: jal         0x807ABFE8
    // 0x807AC300: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    func_807ABFE8(rdram, ctx);
        goto after_5;
    // 0x807AC300: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_5:
    // 0x807AC304: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x807AC308: slti        $at, $s3, 0x2
    ctx->r1 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // 0x807AC30C: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x807AC310: bne         $at, $zero, L_807AC2E8
    if (ctx->r1 != 0) {
        // 0x807AC314: addiu       $s0, $s0, 0x240
        ctx->r16 = ADD32(ctx->r16, 0X240);
            goto L_807AC2E8;
    }
    // 0x807AC314: addiu       $s0, $s0, 0x240
    ctx->r16 = ADD32(ctx->r16, 0X240);
    // 0x807AC318: addiu       $s2, $zero, 0xA0
    ctx->r18 = ADD32(0, 0XA0);
    // 0x807AC31C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_807AC320:
    // 0x807AC320: addiu       $t7, $zero, -0x20
    ctx->r15 = ADD32(0, -0X20);
    // 0x807AC324: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x807AC328: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807AC32C: addiu       $a1, $zero, -0x140
    ctx->r5 = ADD32(0, -0X140);
    // 0x807AC330: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x807AC334: jal         0x807ABFE8
    // 0x807AC338: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    func_807ABFE8(rdram, ctx);
        goto after_6;
    // 0x807AC338: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_6:
    // 0x807AC33C: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x807AC340: addiu       $t8, $zero, -0x20
    ctx->r24 = ADD32(0, -0X20);
    // 0x807AC344: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x807AC348: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x807AC34C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807AC350: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x807AC354: jal         0x807ABFE8
    // 0x807AC358: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    func_807ABFE8(rdram, ctx);
        goto after_7;
    // 0x807AC358: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_7:
    // 0x807AC35C: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x807AC360: slti        $at, $s3, 0xB
    ctx->r1 = SIGNED(ctx->r19) < 0XB ? 1 : 0;
    // 0x807AC364: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x807AC368: bne         $at, $zero, L_807AC320
    if (ctx->r1 != 0) {
        // 0x807AC36C: addiu       $s2, $s2, -0x40
        ctx->r18 = ADD32(ctx->r18, -0X40);
            goto L_807AC320;
    }
    // 0x807AC36C: addiu       $s2, $s2, -0x40
    ctx->r18 = ADD32(ctx->r18, -0X40);
    // 0x807AC370: addiu       $s2, $zero, 0x80
    ctx->r18 = ADD32(0, 0X80);
    // 0x807AC374: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x807AC378: addiu       $s4, $zero, 0xB
    ctx->r20 = ADD32(0, 0XB);
L_807AC37C:
    // 0x807AC37C: addiu       $t9, $zero, -0x20
    ctx->r25 = ADD32(0, -0X20);
    // 0x807AC380: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x807AC384: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807AC388: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    // 0x807AC38C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x807AC390: jal         0x807ABFE8
    // 0x807AC394: addiu       $a3, $zero, -0x40
    ctx->r7 = ADD32(0, -0X40);
    func_807ABFE8(rdram, ctx);
        goto after_8;
    // 0x807AC394: addiu       $a3, $zero, -0x40
    ctx->r7 = ADD32(0, -0X40);
    after_8:
    // 0x807AC398: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x807AC39C: addiu       $t0, $zero, -0x20
    ctx->r8 = ADD32(0, -0X20);
    // 0x807AC3A0: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x807AC3A4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x807AC3A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807AC3AC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x807AC3B0: jal         0x807ABFE8
    // 0x807AC3B4: addiu       $a3, $zero, -0x40
    ctx->r7 = ADD32(0, -0X40);
    func_807ABFE8(rdram, ctx);
        goto after_9;
    // 0x807AC3B4: addiu       $a3, $zero, -0x40
    ctx->r7 = ADD32(0, -0X40);
    after_9:
    // 0x807AC3B8: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x807AC3BC: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x807AC3C0: bne         $s3, $s4, L_807AC37C
    if (ctx->r19 != ctx->r20) {
        // 0x807AC3C4: addiu       $s2, $s2, -0x40
        ctx->r18 = ADD32(ctx->r18, -0X40);
            goto L_807AC37C;
    }
    // 0x807AC3C4: addiu       $s2, $s2, -0x40
    ctx->r18 = ADD32(ctx->r18, -0X40);
    // 0x807AC3C8: addiu       $t1, $zero, -0x20
    ctx->r9 = ADD32(0, -0X20);
    // 0x807AC3CC: addiu       $t2, $zero, 0x27F
    ctx->r10 = ADD32(0, 0X27F);
    // 0x807AC3D0: addiu       $t3, $zero, 0x1F
    ctx->r11 = ADD32(0, 0X1F);
    // 0x807AC3D4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x807AC3D8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x807AC3DC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x807AC3E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807AC3E4: addiu       $a1, $zero, -0x140
    ctx->r5 = ADD32(0, -0X140);
    // 0x807AC3E8: addiu       $a2, $zero, -0xC0
    ctx->r6 = ADD32(0, -0XC0);
    // 0x807AC3EC: jal         0x807AC0B8
    // 0x807AC3F0: addiu       $a3, $zero, 0x280
    ctx->r7 = ADD32(0, 0X280);
    func_807AC0B8(rdram, ctx);
        goto after_10;
    // 0x807AC3F0: addiu       $a3, $zero, 0x280
    ctx->r7 = ADD32(0, 0X280);
    after_10:
    // 0x807AC3F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x807AC3F8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x807AC3FC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x807AC400: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x807AC404: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x807AC408: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x807AC40C: jr          $ra
    // 0x807AC410: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x807AC410: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80059B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059B78: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80059B7C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059B80: lwc1        $f8, 0xBB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XBB0);
    // 0x80059B84: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80059B88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059B8C: sub.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x80059B90: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x80059B94: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80059B98: nop

    // 0x80059B9C: bc1f        L_80059BA8
    if (!c1cs) {
        // 0x80059BA0: nop
    
            goto L_80059BA8;
    }
    // 0x80059BA0: nop

    // 0x80059BA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059BA8:
    // 0x80059BA8: jr          $ra
    // 0x80059BAC: nop

    return;
    // 0x80059BAC: nop

;}
RECOMP_FUNC void func_80432A78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432A78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80432A7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80432A80: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x80432A84: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80432A88: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80432A8C: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(62, 0X480) << 16);
    // 0x80432A90: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80432A94: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x80432A98: addiu       $t8, $t8, 0x2C20
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(62, 0X480));
    // 0x80432A9C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80432AA0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80432AA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80432AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80432AAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80432AB0: jal         0x80432B00
    // 0x80432AB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80432B00(rdram, ctx);
        goto after_0;
    // 0x80432AB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80432AB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80432ABC: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x80432AC0: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x80432AC4: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x80432AC8: sw          $zero, 0x1F8($a0)
    MEM_W(0X1F8, ctx->r4) = 0;
    // 0x80432ACC: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x80432AD0: sw          $t0, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->r8;
    // 0x80432AD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80432AD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80432ADC: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x80432AE0: jal         0x80432A60
    // 0x80432AE4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80432A60(rdram, ctx);
        goto after_1;
    // 0x80432AE4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80432AE8: jal         0x80048378
    // 0x80432AEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80048378(rdram, ctx);
        goto after_2;
    // 0x80432AEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80432AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80432AF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80432AF8: jr          $ra
    // 0x80432AFC: nop

    return;
    // 0x80432AFC: nop

;}
RECOMP_FUNC void func_80001130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001130: jr          $ra
    // 0x80001134: nop

    return;
    // 0x80001134: nop

    // 0x80001138: jr          $ra
    // 0x8000113C: nop

    return;
    // 0x8000113C: nop

    // 0x80001140: jr          $ra
    // 0x80001144: nop

    return;
    // 0x80001144: nop

;}
RECOMP_FUNC void func_80680C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680C44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80680C48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80680C4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80680C50: jal         0x80680BE8
    // 0x80680C54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80680BE8(rdram, ctx);
        goto after_0;
    // 0x80680C54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80680C58: bne         $v0, $zero, L_80680C70
    if (ctx->r2 != 0) {
        // 0x80680C5C: lui         $t6, 0x8068
        ctx->r14 = S32(RELOC_HI16(550, 0X5D4) << 16);
            goto L_80680C70;
    }
    // 0x80680C5C: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(550, 0X5D4) << 16);
    // 0x80680C60: jal         0x800445A4
    // 0x80680C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80680C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80680C68: b           L_80680CF4
    // 0x80680C6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80680CF4;
    // 0x80680C6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80680C70:
    // 0x80680C70: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80680C74: addiu       $t6, $t6, 0x9E4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(550, 0X5D4));
    // 0x80680C78: lui         $t7, 0x8068
    ctx->r15 = S32(RELOC_HI16(550, 0X21B0) << 16);
    // 0x80680C7C: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x80680C80: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80680C84: addiu       $t7, $t7, 0x25C0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(550, 0X21B0));
    // 0x80680C88: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80680C8C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80680C90: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x80680C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80680C98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80680C9C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80680CA0: jal         0x80680D04
    // 0x80680CA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80680D04(rdram, ctx);
        goto after_2;
    // 0x80680CA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80680CA8: jal         0x8068098C
    // 0x80680CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8068098C(rdram, ctx);
        goto after_3;
    // 0x80680CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80680CB0: jal         0x80680C2C
    // 0x80680CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80680C2C(rdram, ctx);
        goto after_4;
    // 0x80680CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80680CB8: jal         0x80680AA8
    // 0x80680CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80680AA8(rdram, ctx);
        goto after_5;
    // 0x80680CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80680CC0: bne         $v0, $zero, L_80680CD8
    if (ctx->r2 != 0) {
        // 0x80680CC4: nop
    
            goto L_80680CD8;
    }
    // 0x80680CC4: nop

    // 0x80680CC8: jal         0x800445A4
    // 0x80680CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x80680CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80680CD0: b           L_80680CF4
    // 0x80680CD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80680CF4;
    // 0x80680CD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80680CD8:
    // 0x80680CD8: jal         0x806809F8
    // 0x80680CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806809F8(rdram, ctx);
        goto after_7;
    // 0x80680CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80680CE0: bnel        $v0, $zero, L_80680CF4
    if (ctx->r2 != 0) {
        // 0x80680CE4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80680CF4;
    }
    goto skip_0;
    // 0x80680CE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80680CE8: jal         0x800445A4
    // 0x80680CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x80680CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80680CF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80680CF4:
    // 0x80680CF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80680CF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80680CFC: jr          $ra
    // 0x80680D00: nop

    return;
    // 0x80680D00: nop

;}
RECOMP_FUNC void func_807AE800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AE804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AE808: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807AE80C: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x807AE810: blez        $v0, L_807AE850
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807AE814: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807AE850;
    }
    // 0x807AE814: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807AE818: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x807AE81C: mfhi        $t8
    ctx->r24 = hi;
    // 0x807AE820: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x807AE824: bne         $t8, $zero, L_807AE87C
    if (ctx->r24 != 0) {
        // 0x807AE828: addiu       $t9, $zero, 0x50
        ctx->r25 = ADD32(0, 0X50);
            goto L_807AE87C;
    }
    // 0x807AE828: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x807AE82C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE830: sb          $t9, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r25;
    // 0x807AE834: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE838: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x807AE83C: sb          $t0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r8;
    // 0x807AE840: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE844: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x807AE848: b           L_807AE87C
    // 0x807AE84C: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
        goto L_807AE87C;
    // 0x807AE84C: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
L_807AE850:
    // 0x807AE850: jal         0x807AE118
    // 0x807AE854: nop

    func_807AE118(rdram, ctx);
        goto after_0;
    // 0x807AE854: nop

    after_0:
    // 0x807AE858: jal         0x8004700C
    // 0x807AE85C: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x807AE85C: nop

    after_1:
    // 0x807AE860: beql        $v0, $zero, L_807AE880
    if (ctx->r2 == 0) {
        // 0x807AE864: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807AE880;
    }
    goto skip_0;
    // 0x807AE864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807AE868: jal         0x8004700C
    // 0x807AE86C: nop

    func_8004700C(rdram, ctx);
        goto after_2;
    // 0x807AE86C: nop

    after_2:
    // 0x807AE870: lw          $t3, 0x1F4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1F4);
    // 0x807AE874: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x807AE878: sb          $t2, 0x1B4($t3)
    MEM_B(0X1B4, ctx->r11) = ctx->r10;
L_807AE87C:
    // 0x807AE87C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807AE880:
    // 0x807AE880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AE884: jr          $ra
    // 0x807AE888: nop

    return;
    // 0x807AE888: nop

;}
RECOMP_FUNC void func_8070C870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070C870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070C874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070C878: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8070C87C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8070C880: blez        $v0, L_8070C890
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8070C884: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8070C890;
    }
    // 0x8070C884: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8070C888: b           L_8070C8B0
    // 0x8070C88C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8070C8B0;
    // 0x8070C88C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8070C890:
    // 0x8070C890: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8070C894: jal         0x8070C7F4
    // 0x8070C898: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8070C7F4(rdram, ctx);
        goto after_0;
    // 0x8070C898: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8070C89C: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    // 0x8070C8A0: jal         0x8070C714
    // 0x8070C8A4: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    func_8070C714(rdram, ctx);
        goto after_1;
    // 0x8070C8A4: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_1:
    // 0x8070C8A8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8070C8AC: sw          $v0, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r2;
L_8070C8B0:
    // 0x8070C8B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070C8B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8070C8B8: jr          $ra
    // 0x8070C8BC: nop

    return;
    // 0x8070C8BC: nop

;}
